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
from typing import Dict
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
            upper = self._generator.UpperCamelCase
            strList = ['mt["{}"]=&{};'.format(
                self._newName if not upper else CursorHelper.UpperCamelCase(self._newName), self._wholeName
            )]
            self._cxxStr = ''.join(strList)
        return self._cxxStr


class NativeStaticField(NativeMember):
    def __str__(self) -> str:
        """静态成员变量的生成。
        依照 mt["self._newName"] = sol::var(std::ref(self._wholeName));的方式生成。
        """
        if not self._cxxStr:
            upper = self._generator.UpperCamelCase
            strList = ['mt["{}"]=sol::var(std::ref({}));'.format(
                self._newName if not upper else CursorHelper.UpperCamelCase(self._newName), self._wholeName
            )]
            self._cxxStr = ''.join(strList)
        return self._cxxStr


class NativeMethod(NativeMember, NativeFunction):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._const = cursor.is_const_method()
        self._pureVirtual = cursor.is_pure_virtual_method()
        self._virtual = cursor.is_virtual_method()
        self._isOverride = False
        self._isOverload = False
        # -1-表示没有单例属性。
        # 0-表示该方法是获取单例方法。
        # 1-表示该方法是销毁单例方法。
        self._instanceProperty = -1

        if not self._pureVirtual:
            for node in cursor.get_children():
                if node.kind == cindex.CursorKind.CXX_OVERRIDE_ATTR:
                    self._isOverride = True
                    break

        # 判定是否有单例属性。
        if self._static:
            parentName = CursorHelper.GetClassesName(cursor)
            for matchParent, instanceMethods in generator.InstanceMethods.items():
                breakMe = False
                if re.match("^" + matchParent + "$", parentName):
                    for idx in range(2):
                        if instanceMethods[idx] and re.match("^" + instanceMethods[idx] + "$", self._funcName):
                            self._instanceProperty = idx
                            breakMe = True
                            break
                if breakMe:
                    break

    def IsOverrided(self, method: "NativeMethod"):
        """判断自己是否重写了某方法，或某重载方法。
        """
        if self._funcName != method._funcName:
            return False
        if method.__class__.__name__ == "NativeOverloadMethod":
            for m in method.Impl:
                ret = self.IsOverrided(m)
                if ret:
                    return True
            return False
        else:
            if not self._virtual or not method._virtual:
                return False
            len1 = len(self._args)
            len2 = len(method._args)
            if len1 != len2:
                return False
            return self._args == method._args

    @property
    def Override(self):
        return self._isOverride

    @property
    def PureVirtual(self):
        return self._pureVirtual

    @property
    def Virtual(self):
        return self._virtual

    @property
    def InstanceProperty(self):
        return self._instanceProperty

    @property
    def Overload(self):
        return self._isOverload

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
                if not self._static:
                    cxx.append(self._prefixName)
                    cxx.append("* obj")
                for argIdx in range(self._minArgs + i):
                    if not self._static or argIdx != 0:
                        cxx.append(",")
                    cxx.append(self._args[argIdx])
                    cxx.append(" arg")
                    cxx.append(str(argIdx))
                if not self._static:
                    cxx.append("){return obj->")
                else:
                    cxx.append("){return ")
                    cxx.append(self._prefixName)
                    cxx.append("::")
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
            upper = self._generator.UpperCamelCase
            if self._newName == "new":
                # new被作为构造函数。
                cxx = ["mt[sol::meta_function::construct]="]
            else:
                cxx = ['mt["{}"]='.format(
                    self._newName if not upper else CursorHelper.UpperCamelCase(self._newName)
                )]

            overload = self._minArgs < len(self._args)
            if overload:
                # 具有默认参数的方法添加sol::overload重载。
                cxx.append("sol::overload(")

            cxx.append("".join(self.GetImplStr()))

            if overload:
                cxx.append(")")
            cxx.append(";")

            self._cxxStr = "".join(cxx)
        return self._cxxStr


class NativeOverloadMethod(NativeMember):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._impl = []
        self._prefixName = CursorHelper.GetPrefixName(cursor)
        self._funcName = cursor.spelling
        self._wholeFuncName = self._prefixName + "::" + self._funcName
        self._isOverload = True

    def AddMethod(self, method: NativeMethod):
        if isinstance(method, NativeOverloadMethod):
            appendList = []
            for mm in method._impl:
                ap = True
                for sm in self._impl:
                    if mm._args == sm._args:
                        ap = False
                        break
                if ap:
                    appendList.append(mm)
            self._impl += appendList
        else:
            self._impl.append(method)
            method._isOverload = True

    def __str__(self) -> str:
        if not self._cxxStr:
            upper = self._generator.UpperCamelCase
            if self._newName == "new":
                # new被作为构造函数。
                cxx = ["mt[sol::meta_function::construct]="]
            else:
                cxx = ['mt["{}"]='.format(
                    self._newName if not upper else CursorHelper.UpperCamelCase(self._newName)
                )]
            cxx.append("sol::overload(")

            implList = []
            for impl in self._impl:
                implList.append(impl.GetImplStr())
            cxx.append(",".join(implList))

            cxx.append(");")

            self._cxxStr = "".join(cxx)
        return self._cxxStr

    @property
    def Impl(self):
        return self._impl


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
        # 生成字典，在该字典中的方法才会生成。
        self._methods = {}
        # 全方法字典，用于存储和查询。
        self._allMethods = {}
        # 纯虚函数字典。
        self._pvMethods = {}
        # 虚函数字典。
        # 对于虚函数：
        # 1、基类有声明的，由基类绑定一次；
        # 2、只要自己有另一个同名方法，那么自己再绑定一次重载方法，否则自己不再绑定。
        self._vMethods = {}
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
        # 存放具有获取和销毁单例方法的列表。
        self._instanceMethodList = [None, None]
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
                if parentDef.displayname not in self._generator.ParentsClassesSkip:
                    pWholeName = CursorHelper.GetWholeName(parentDef)

                    if pWholeName not in self._generator.AllNativeObjects.keys():
                        self._generator.AllNativeObjects[pWholeName] = self.__class__(parentDef, self._generator)

                    parent: NativeObject = self._generator.AllNativeObjects[pWholeName]
                    if parent.Generatable:
                        if pWholeName not in self._generator.NativeObjects.keys():
                            self._generator.NativeObjects[pWholeName] = parent

                    if parent not in self._parents:
                        # 添加父级。
                        self._parents.append(parent)
                        # 统计所有父级的纯虚函数。
                        self._pvMethods |= parent._pvMethods
                    for pParent in parent._parents:
                        # 添加父级的父级...。
                        # Sol要求c++绑定时明确指示所有父级。
                        if pParent not in self._parents:
                            self._parents.append(pParent)
                            # 统计所有父级的纯虚函数。
                            self._pvMethods |= pParent._pvMethods
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
                name = CursorHelper.GetName(cursor)
                gEnum = NativeEnum(cursor, self._generator) if name else NativeAnonymousEnum(cursor, self._generator)
                if gEnum.Generatable:
                    # 若需要生成到lua，则不加入自己的内部类，而是加入生成器的生成结构字典。
                    if self._generator.EnumForLua:
                        wholeName = CursorHelper.GetWholeName(cursor)
                        if wholeName not in self._generator.NativeObjects.keys():
                            self._generator.NativeObjects[wholeName] = gEnum
                    else:
                        self._classes.append(gEnum)
            elif cursor.kind == cindex.CursorKind.CLASS_DECL\
                    or (self._generator.AllowStruct and cursor.kind == cindex.CursorKind.STRUCT_DECL):

                pWholeName = CursorHelper.GetWholeName(cursor)

                if pWholeName not in self._generator.AllNativeObjects.keys():
                    self._generator.AllNativeObjects[pWholeName] = NativeClass(cursor, self._generator)\
                        if cursor.kind == cindex.CursorKind.CLASS_DECL else NativeStruct(cursor, self._generator)
                # 内部类和内部结构体。
                gObj = self._generator.AllNativeObjects[pWholeName]
                if gObj.Generatable:
                    self._classes.append(gObj)
            elif cursor.kind == cindex.CursorKind.FIELD_DECL or cursor.kind == cindex.CursorKind.VAR_DECL:
                if cursor.kind == cindex.CursorKind.FIELD_DECL:
                    # 成员变量。
                    gField = NativeField(cursor, self._generator)
                else:
                    # 静态成员变量。
                    gField = NativeStaticField(cursor, self._generator)
                if gField.Generatable:
                    self._fileds.append(gField)
        if cursor.kind == cindex.CursorKind.CXX_METHOD and\
                not cursor.type.is_function_variadic():
            # 成员函数，且跳过函数变量。
            method = NativeMethod(cursor, self._generator)
            if method.PureVirtual:
                # 统计纯虚函数。
                if method._wholeName not in self._pvMethods:
                    self._pvMethods[method._wholeName] = method
            else:
                # 消减已实现的纯虚函数。
                if method._wholeName in self._pvMethods:
                    self._pvMethods.pop(method._wholeName)
            if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                # Override函数到底要不要跳过？需要研究。
                # 如果跳过，类似于cc.Sprite.setTexture的函数实现将会遇到麻烦，
                # 不会重载基类的setTexture。
                # 如果不跳过，将重复绑定一次基类的虚函数。
                # if method.Override:
                #     return

                if not method.Supported or\
                        CursorHelper.GetAvailability(cursor) == CursorHelper.Availability.DEPRECATED:
                    return

                # 检查基类是否绑定，基类未绑定，那么自己需要绑定。
                parentBinding = False
                if method.Virtual:
                    for parent in self._parents:
                        pMethods = parent._allMethods
                        if method.FuncName in pMethods.keys() and\
                                method.IsOverrided(pMethods[method.FuncName]):
                            # 基类已绑定。
                            parentBinding = True
                            break

                    if parentBinding:
                        # 如果基类已绑定，判断自己是否有同名方法。
                        if method.FuncName in self._methods:
                            self._PushToMethodDict(method, self._methods)
                        else:
                            # 否则加入虚函数缓存字典。
                            self._PushToMethodDict(method, self._vMethods)
                if not parentBinding:
                    # 检查自己是否有在虚函数缓存字典中的方法。
                    if method.FuncName in self._vMethods:
                        method = self._PushToMethodDict(method, self._vMethods)
                        del self._vMethods[method.FuncName]
                else:
                    return

                if method.Generatable:
                    if method.Static:
                        if method.InstanceProperty >= 0 and self._instanceMethodList[method.InstanceProperty] is None:
                            self._instanceMethodList[method.InstanceProperty] = method

                    if method.NewName == "new":
                        self._newCtor = True

                    self._PushToMethodDict(method, self._methods)
                self._PushToMethodDict(method, self._allMethods)
        elif cursor.kind == cindex.CursorKind.CONSTRUCTOR:
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

    def _PushToMethodDict(self, method: NativeMethod, d: Dict[str, NativeMethod]) -> NativeMethod:
        """将一个方法推入方法字典，若有同名方法，将转换为重载方法。
        """
        name = method.FuncName
        if name not in d.keys():
            d[name] = method
            return method
        preMethod: NativeMethod = d[name]
        if isinstance(preMethod, NativeOverloadMethod):
            preMethod.AddMethod(method)
            return preMethod
        # 转换为重载函数。
        # 替换普通方法为重载方法，并追加当前方法和原方法。
        ov = NativeOverloadMethod(method._cursor, self._generator)
        ov.AddMethod(method)
        ov.AddMethod(preMethod)
        d[name] = ov
        return ov

    def __str__(self) -> str:
        if self._cxxStr:
            return self._cxxStr
        cxx = []
        upper = self._generator.UpperCamelCase
        # 优先生成内部枚举和内部类。
        for c in self._classes:
            cxx.append(str(c))
            cxx.append("\n")

        noCtor = "true" if not self._newCtor and not self._callCtor else "false"

        cxx.append("void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua)".format(
            self._generator.Tag, "".join(self._nameList[1:])))
        cxx.append("{\n")
        cxx.append('auto mt=lua.NewUserType<{wholeName}>("{nsName}","{class_name}",{noCtor});\n'.format(
            nsName=".".join(self._nNameList[:-1]), class_name=self._newName if not upper else CursorHelper.UpperCamelCase(self._newName), wholeName=self._wholeName, noCtor=noCtor))

        # 类与基类名组合
        basesName = ""
        for p in self._parents:
            basesName += (p._wholeName + ",")
        if basesName:
            cxx.append("cocos2d::extension::Lua::SetBases(mt,sol::bases<{}>());\n".format(basesName[:-1]))

        # 方法生成。
        for method in self._methods.values():
            cxx.append(str(method))
            cxx.append("\n")

        if len(self._pvMethods) == 0:
            # 没有可用的纯虚函数，才允许使用构造。
            if self._defaultCtor:
                # 默认构造。
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
            cxx.append('RegisterLua{}{}Auto(lua);\n'.format(self._generator.Tag, "".join(c._nameList[1:])))

        # 单例属性。
        if self._instanceMethodList[0] and self._instanceMethodList[1]:
            cxx.append('mt["Instance"]=sol::property(&{},[](std::nullptr_t){{{}();}});\n'.format(
                self._instanceMethodList[0].WholeFuncName,
                self._instanceMethodList[1].WholeFuncName))
        elif self._instanceMethodList[0]:
            cxx.append('mt["Instance"]=sol::readonly_property(&{});\n'.format(
                self._instanceMethodList[0].WholeFuncName))
        elif self._instanceMethodList[1]:
            cxx.append('mt["Instance"]=sol::writeonly_property([](std::nullptr_t){{{}();}});\n'.format(
                self._instanceMethodList[1].WholeFuncName))

        cxx.append("}")
        self._cxxStr = "".join(cxx)
        return self._cxxStr


class NativeClass(NativeObject):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)


class NativeStruct(NativeObject):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
