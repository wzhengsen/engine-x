#!/usr/bin/env python3
# Copyright (c) 2021 - wzhengsen

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

import re
from clang import cindex
from Config.BaseConfig import BaseConfig
from Util.CursorHelper import CursorHelper
from .NativeBase import NativeWrapper, NativeMember, NativeFunction, NativeType
from .NativeEnum import NativeEnum, NativeAnonymousEnum


class NativeField(NativeMember):
    def __str__(self) -> str:
        """成员变量的生成。
        依照 mt["self._newName"] = &self._wholeName;的方式生成。
        """
        if not self._cxxStr:
            strList = ['mt["{}"]=&{};'.format(self._newName, self._wholeName)]
            self._cxxStr = ''.join(strList)
        return self._cxxStr


class NativeMethod(NativeMember, NativeFunction):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._const = cursor.is_const_method()
        self._pureVirtual = cursor.is_pure_virtual_method()
        self._isOverride = False
        self._instanceProperty = False

        for node in cursor.get_children():
            if node.kind == cindex.CursorKind.CXX_OVERRIDE_ATTR:
                self._isOverride = True
                break

        # 判定是否有单例属性。
        if self._static:
            parentName = CursorHelper.GetParentName(cursor)
            for matchParent, instanceMethod in generator.InstanceMethods.items():
                if re.match("^" + matchParent + "$", parentName) and\
                        re.match("^" + instanceMethod + "$", self._funcName):
                    self._instanceProperty = True
                    break

    @property
    def Override(self):
        return self._isOverride

    def GetImplStr(self) -> str:
        """获取实现主体字符串。"""
        cxx = []
        if self._minArgs == len(self._args):
            # 无默认参数。
            cxx.append("static_cast<")
            cxx.append(self._returnType)
            cxx.append("(")
            if not self._static:
                cxx.append(self._prefixName + "::")
            cxx.append("*)(")

            idx = len(self._args)
            for i in range(idx):
                cxx.append(self._args[i])
                cxx.append("," if i < idx - 1 else "")
            cxx.append(")")
            cxx.append("const>(&" if self._const else ">(&")
            cxx.append(self._wholeFuncName)
            cxx.append(")")
        else:
            # 有默认参数。
            argsOffset = len(self._args) - self._minArgs + 1
            for i in range(argsOffset):
                cxx.append("[](")
                cxx.append(self._prefixName)
                cxx.append("* obj")
                for argIdx in range(self._minArgs + i):
                    cxx.append(",")
                    cxx.append(self._args[argIdx])
                    cxx.append(" arg")
                    cxx.append(str(argIdx))
                cxx.append("){return obj->")
                cxx.append(self._funcName)
                cxx.append("(")
                for argIdx in range(self._minArgs + i):
                    cxx.append("arg")
                    cxx.append(str(argIdx))
                    cxx.append("" if argIdx == self._minArgs + i - 1 else ",")
                cxx.append(");}")
                cxx.append("" if i == argsOffset - 1 else ",")
        return "".join(cxx)

    def __str__(self) -> str:
        if not self._cxxStr:
            if self._newName == "new":
                # new被作为构造函数。
                cxx = ["mt.set_function(sol::meta_function::construct,"]
            else:
                cxx = ['mt.set_function("{}",'.format(self._newName)]

            if self._minArgs < len(self._args):
                # 具有默认参数的方法添加sol::overload重载。
                cxx.append("sol::overload(")

            cxx.append("".join(self.GetImplStr()))

            if self._minArgs < len(self._args):
                cxx.append(")")
            cxx.append(");")

            if self._instanceProperty:
                # 添加单例属性实现。
                cxx.append('\nmt["Instance"]=sol::readonly_property(&{});'.format(self._wholeFuncName))

            self._cxxStr = "".join(cxx)
        return self._cxxStr


class NativeOverloadMethod(NativeMember):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._impl = []

    def AddMethod(self, method: NativeMethod):
        self._impl.append(method)

    def __str__(self) -> str:
        if not self._cxxStr:
            cxx = ['mt.set_function("{}",'.format(self._newName)]
            cxx.append("sol::overload(")

            implList = []
            for impl in self._impl:
                implList.append(impl.GetImplStr())
            cxx.append(",".join(implList))

            cxx.append("));")

            self._cxxStr = "".join(cxx)
        return self._cxxStr


class NativeConstructor(NativeType):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._argsList = []

    def ImplList(self) -> str:
        """获取构造函数的实现主体列表。"""
        implList = []
        for args in self._argsList:
            implStr = "{}({})".format(self.WholeName, ",".join(args))
            implList.append(implStr)
        return implList

    def __str__(self) -> str:
        if not self._argsList:
            return ""
        if not self._cxxStr:
            self._cxxStr = "".join(["mt[sol::call_constructor]=sol::constructors<", ",".join(self.ImplList()), ">();"])
        return self._cxxStr

    @property
    def ArgsList(self):
        return self._argsList

    @ArgsList.setter
    def ArgsList(self, val):
        self._argsList = val


class NativeObject(NativeWrapper):
    """类，结构体的基类。"""

    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._parents = []
        # 直接父级，当只有一个直接父级时，此值才有意义。
        self._parent: NativeObject = None
        self.__onlyParent = True
        self.__usingParent = False
        self._methods = {}
        self._fileds = []
        self._ctor = NativeConstructor(cursor, generator)
        # 所含的内部类，包括枚举/结构体。
        self._classes = []
        # 标识是否有public的构造函数，
        # 如果有，默认具有sol::call_constructor的构造。
        self._callCtor = False
        # 标识是否有默认构造。
        self._defaultCtor = True
        # 如果还有名为"new"的函数（包括重命名的函数），那么，该类或结构体有new构造。
        self._newCtor = False
        self.__DeepIterate(self._cursor)

        for p in self._parents:
            # 任意父级没有默认构造，即不使用默认构造。
            if not p._defaultCtor:
                self._defaultCtor = False
                break

    def __DeepIterate(self, cursor) -> dict:
        """深度优先遍历所有子节点。"""
        for node in cursor.get_children():
            self.__ProcessCursor(node)

    def __ProcessCursor(self, cursor):
        """处理游标信息。"""
        if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
            if cursor.kind == cindex.CursorKind.CXX_BASE_SPECIFIER:
                # 基类。
                parentDef = cursor.get_definition()
                if self._name not in self._generator.ClassesNoParents and\
                        parentDef.displayname not in self._generator.ParentsClassesSkip and\
                        not self._generator.ShouldSkip(parentDef.displayname):
                    pWholeName = CursorHelper.GetWholeName(parentDef)
                    if pWholeName not in self._generator.NativeObjects.keys():
                        self._generator.NativeObjects[pWholeName] = NativeClass(parentDef, self._generator)

                    parent: NativeClass = self._generator.NativeObjects[pWholeName]
                    if parent not in self._parents:
                        # 添加父级。
                        self._parents.append(parent)
                    for pParent in parent._parents:
                        # 添加父级的父级...。
                        # Sol要求c++绑定时明确指示所有父级。
                        if pParent not in self._parents:
                            self._parents.append(pParent)
                    if self.__onlyParent:
                        self._parent = parent
                        self.__onlyParent = False
                    else:
                        self._parent = None
            elif cursor.kind == cindex.CursorKind.USING_DECLARATION:
                if not self._parent or self.__usingParent:
                    return
                nodes = []
                for node in cursor.get_children():
                    nodes.append(node)
                if len(nodes) == 3 and\
                        nodes[0].kind == cindex.CursorKind.TYPE_REF and\
                        nodes[1].kind == cindex.CursorKind.OVERLOADED_DECL_REF and\
                        nodes[2].kind == cindex.CursorKind.TYPE_REF and\
                        self._parent.WholeName == CursorHelper.GetWholeName(nodes[0].get_definition()):

                    self._defaultCtor = False
                    self._callCtor = True
                    # 尝试匹配 using Parent::Parent;语句
                    self._ctor.ArgsList = self._UnionSelfAndParentCtor()

            elif cursor.kind == cindex.CursorKind.ENUM_DECL:
                # 内部枚举类型。
                # 匿名判断不使用cursor.is_anonymous()获取，此处直接简单判断名字作为匿名标准。
                self._classes.append(NativeEnum(cursor, self._generator)
                                     if CursorHelper.GetName(cursor) else NativeAnonymousEnum(cursor, self._generator))
            elif cursor.kind == cindex.CursorKind.CLASS_DECL\
                    or (self._generator.AllowStruct and cursor.kind == cindex.CursorKind.STRUCT_DECL):
                # 内部类和内部结构体。
                if cursor.kind == cindex.CursorKind.CLASS_DECL:
                    self._classes.append(NativeClass(cursor, self._generator))
                else:
                    self._classes.append(NativeStruct(cursor, self._generator))
            elif cursor.kind == cindex.CursorKind.FIELD_DECL:
                # 成员变量。
                self._fileds.append(NativeField(cursor, self._generator))
            elif cursor.kind == cindex.CursorKind.CXX_METHOD and\
                    not cursor.type.is_function_variadic() and\
                    CursorHelper.GetAvailability(cursor) != CursorHelper.Availability.DEPRECATED:
                # 成员函数，且跳过函数变量和弃用函数。
                method = NativeMethod(cursor, self._generator)
                if method.Override or not method.Supported:
                    return

                if method.NewName == "new":
                    self._newCtor = True
                if method.WholeFuncName not in self._methods.keys():
                    self._methods[method.WholeFuncName] = method
                else:
                    # 已有同名方法。
                    preMethod: NativeMethod = self._methods[method.WholeFuncName]
                    if isinstance(preMethod, NativeOverloadMethod):
                        # 重载方法追加该方法作为实现。
                        preMethod: NativeOverloadMethod.AddMethod(method)
                    else:
                        # 替换普通方法为重载方法，并追加当前方法和原方法。
                        nom = NativeOverloadMethod(cursor, self._generator)
                        nom.AddMethod(method)
                        nom.AddMethod(preMethod)
                        self._methods[method.WholeFuncName] = nom
        if cursor.kind == cindex.CursorKind.CONSTRUCTOR:
            self._defaultCtor = False
            if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                # 构造函数。
                ctor = NativeFunction(cursor, self._generator)
                if not ctor.Supported:
                    return
                self._callCtor = True
                if (ctor.Args not in self._ctor.ArgsList):
                    self._ctor.ArgsList.append(ctor.Args)

    def _UnionSelfAndParentCtor(self) -> list:
        """合并自己和直接父级的构造函数的实现，并返回一个嵌套列表。
        该返回的列表指示了各个实现使用的不同参数。
        """
        argsList = self._ctor.ArgsList
        for pArgs in self._parent._ctor.ArgsList:
            if pArgs not in argsList:
                argsList.append(pArgs)
        return argsList

    def __str__(self) -> str:
        if self._cxxStr:
            return self._cxxStr
        cxx = []
        # 优先生成内部枚举和内部类。
        for c in self._classes:
            cxx.append(str(c))
            cxx.append("\n")

        noCtor = "true" if not self._newCtor and not self._callCtor else "false"

        cxx.append("void RegisterLua{}{}Auto(cocos2d::Lua& lua)".format(self._generator.Tag, "".join(self._sNameList[1:])))
        cxx.append("{\n")
        cxx.append('auto mt=lua.NewUserType<{wholeName}>("{nsName}","{class_name}",{noCtor});\n'.format(
            nsName=".".join(self._sNameList[:-1]), class_name=self._newName, wholeName=self._wholeName, noCtor=noCtor))

        # 方法生成。
        for method in self._methods.values():
            cxx.append(str(method))
            cxx.append("\n")

        # 默认构造。
        if self._defaultCtor:
            cxx.append("mt[sol::call_constructor]=sol::constructors<{}()>();\n".format(self._wholeName))
        else:
            # 手动指定的构造函数。
            ctorStr = str(self._ctor)
            if ctorStr:
                cxx.append(ctorStr)
                cxx.append("\n")

        # public域生成。
        for field in self._fileds:
            cxx.append(str(field))
            cxx.append("\n")

        # 调用注册内部枚举和内部类。
        for c in self._classes:
            cxx.append('RegisterLua{}{}Auto(lua);\n'.format(self._generator.Tag, "".join(c._sNameList[1:])))

        # 类与基类名组合
        basesName = ""
        for p in self._parents:
            basesName += (p._wholeName + ",")
        if basesName:
            # 继承关系暂时放到最后，见https://github.com/ThePhD/sol2/issues/1146。
            cxx.append("mt[sol::base_classes]=sol::bases<{}>();\n".format(basesName[:-1]))
        cxx.append("}")
        self._cxxStr = "".join(cxx)
        return self._cxxStr


class NativeClass(NativeObject):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)


class NativeStruct(NativeObject):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
