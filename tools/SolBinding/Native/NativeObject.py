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
from typing import Dict, List
from clang import cindex
from Config.BaseConfig import BaseConfig
from Util.CursorHelper import CursorHelper
from .NativeBase import NativeWrapper, NativeMember, NativeFunction, NativeType, NativeImplement
from .NativeEnum import NativeEnum, NativeAnonymousEnum


class NativeField(NativeMember):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._const = cursor.type.is_const_qualified()

    def __str__(self) -> str:
        """成员变量的生成。
        依照 mt["get"|"set"]["self._newName"] = [](...){...};的方式生成。
        """
        if not self._cxxStr:
            upper = self._generator.UpperCamelCase
            if not self._const:
                implStr = "[]({}* obj,const {}& value){{obj->{} = value;}};".format(
                    CursorHelper.GetPrefixName(self._cursor),
                    CursorHelper.GetArgName(self._cursor.type, False),
                    self._name
                )
                strList = ['mt["{}"]["{}"]={};\n'.format(
                    self._generator.LuaConfig["set"], self._newName if not upper else CursorHelper.UpperCamelCase(
                        self._newName), implStr
                )]
            implStr = "[]({}* obj){{return obj->{};}};".format(CursorHelper.GetPrefixName(self._cursor), self._name)
            strList = ['mt["{}"]["{}"]={};'.format(
                self._generator.LuaConfig["get"], self._newName if not upper else CursorHelper.UpperCamelCase(
                    self._newName), implStr
            )]
            self._cxxStr = ''.join(strList)
        return self._cxxStr


class NativeStaticField(NativeMember):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._const = cursor.type.is_const_qualified()

    def __str__(self) -> str:
        """静态成员变量的生成。
        依照 mt["get"|"set"]["self._newName"] = [](...){...};的方式生成。
        """
        if not self._cxxStr:
            upper = self._generator.UpperCamelCase
            if not self._const:
                implStr = "[](const sol::object&,const {}& value){{{}::{} = value;}};".format(
                    CursorHelper.GetArgName(self._cursor.type, False),
                    CursorHelper.GetPrefixName(self._cursor),
                    self._name
                )
                strList = ['mt["{}"]["{}"]={};\n'.format(
                    self._generator.LuaConfig["set"],
                    self._newName if not upper else CursorHelper.UpperCamelCase(self._newName),
                    implStr
                )]

            implStr = "[](){{return {}::{};}};".format(CursorHelper.GetPrefixName(self._cursor), self._name)
            strList = ['mt["{}"]["{}"]={};'.format(
                self._generator.LuaConfig["get"],
                self._newName if not upper else CursorHelper.UpperCamelCase(self._newName),
                implStr
            )]
            self._cxxStr = ''.join(strList)
        return self._cxxStr


class NativeMethodImplement(NativeImplement):

    @staticmethod
    def CreateImplements(cursor):
        impls = NativeImplement.CreateImplements(cursor)
        return [NativeMethodImplement(impl) for impl in impls]

    def __init__(self, impl: NativeImplement) -> None:
        cursor = impl._cursor
        self.__dict__ |= impl.__dict__
        self._static: bool = cursor.is_static_method()
        self._const = cursor.is_const_method()
        self._pureVirtual = cursor.is_pure_virtual_method()
        self._virtual = cursor.is_virtual_method()
        self._isOverride = False
        self._impl = impl
        if not self._pureVirtual:
            for node in cursor.get_children():
                if node.kind == cindex.CursorKind.CXX_OVERRIDE_ATTR:
                    self._isOverride = True
                    break

    def Copy(self) -> "NativeMethodImplement":
        return NativeMethodImplement(self._impl)

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
    def Const(self):
        return self._const


class NativeMethod(NativeMember, NativeFunction):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        NativeFunction.__init__(self, cursor, generator, NativeMethodImplement)
        NativeMember.__init__(self, cursor, generator)

        # -1-表示没有单例属性。
        # 0-表示该方法是获取单例方法。
        # 1-表示该方法是销毁单例方法。
        self._instanceProperty = -1

        # 判定是否有单例属性（要求构造单例的方法必须具有一个非void返回值，要求析构单例的方法必须接受0个参数）。
        for impl in self._implements:
            breakMe = False
            if not impl._static:
                continue
            parentName = CursorHelper.GetClassesName(cursor)
            for matchParent, instanceMethods in generator.InstanceMethods.items():
                if re.match("^" + matchParent + "$", parentName):
                    for idx in range(2):
                        if instanceMethods[idx] and re.match("^" + instanceMethods[idx] + "$", self._funcName):
                            if (idx == 0 and impl.Result != "void") or (idx == 1 and len(impl.Args) == 0):
                                self._instanceProperty = idx
                                breakMe = True
                                break
                    if breakMe:
                        break
                if breakMe:
                    break
            if breakMe:
                break

    def OverloadBy(self, child: "NativeObject") -> "NativeMethod":
        """用于对子类使用using Parent::Method;方式重载方法时，返回一个
        复制的对象，但其中的所属名将更改。
        """
        copy = NativeMethod(self._cursor, self._generator)
        copy._cxxStr = None
        copy._wholeName = CursorHelper.GetWholeName(child.Cursor) + "::" + copy._name

        pName = CursorHelper.GetName(child.Cursor)
        copy._newName = copy._generator.RenameMember(pName, copy._funcName)
        copy._generatable = not copy._generator.ShouldSkip(pName, copy._funcName)

        copy._prefixName = CursorHelper.GetWholeName(child.Cursor)
        copy._wholeFuncName = copy._prefixName + "::" + copy._funcName
        copy._implements = []
        for impl in self._implements:
            copy._implements.append(impl.Copy())
        return copy

    def IsOverrided(self, other: "NativeMethod"):
        """判断自己是否重写了某方法，或某重载方法。
        """
        if self._funcName != other._funcName:
            return False

        for sImpl in self._implements:
            if sImpl.Virtual:
                for oImpl in other._implements:
                    if oImpl.Virtual and sImpl == oImpl:
                        return True
        return False

    @property
    def InstanceProperty(self):
        return self._instanceProperty

    @staticmethod
    def GetImplStr(self: NativeFunction, new=False) -> str:
        """获取实现主体字符串。
        该逻辑还在外部供构造函数等使用。
        """
        cxx = []
        for impl in self._implements:
            line = []
            if not impl.Default and not new:
                line.append("static_cast<" + impl.Result + "(")
                if not impl.Static:
                    line.append(self._prefixName + "::")
                line.append("*)(")
                line.append(",".join(impl.Args))
                line.append(")")
                if impl.Const:
                    line.append("const")
                line.append(">(&")
                line.append(self._wholeFuncName + ")")
            else:
                line.append("[](")
                args = []
                if not impl.Static:
                    args.append(self._prefixName + "* obj")
                for idx, arg in enumerate(impl.Args):
                    args.append(arg + " arg{}".format(idx))
                line.append(",".join(args))
                if not impl.Static:
                    line.append("){return obj->")
                else:
                    if new:
                        line.append("){return new ")
                    else:
                        line.append("){return ")
                    line.append(self._prefixName + "::")
                line.append(self._funcName + "(")
                args.clear()
                for idx in range(len(impl.Args)):
                    args.append("arg{}".format(idx))
                line.append(",".join(args))
                line.append(");}")
            cxx.append("".join(line))

        return ",".join(cxx)

    def __str__(self) -> str:
        if not self._cxxStr:
            upper = self._generator.UpperCamelCase
            allStatic = True
            for impl in self._implements:
                if not impl._static:
                    allStatic = False
                    break
            cxx = ['mt{}["{}"]='.format(
                ('["' + self._generator.LuaConfig["Qualifiers"]["static"] + '"]')
                if allStatic and self._newName != "new" else "",
                self._generator.LuaConfig["__new__"]
                if self._newName == "new" else (self._newName if not upper else CursorHelper.UpperCamelCase(self._newName)
                                                ))]

            if self.Overload:
                cxx.append("sol::overload(")

            cxx.append(NativeMethod.GetImplStr(self))

            if self.Overload:
                cxx.append(")")
            cxx.append(";")

            self._cxxStr = "".join(cxx)
        return self._cxxStr


class NativeConstructor(NativeFunction):
    def __init__(self, this: "NativeObject") -> None:
        """不使用NativeFunction的构造，而是由所属类直接构造一个默认的。
        """
        NativeType.__init__(self, this._cursor, this._generator)
        self._prefixName = CursorHelper.GetPrefixName(self._cursor)
        self._funcName = CursorHelper.GetName(self._cursor)
        self._wholeFuncName = CursorHelper.GetWholeName(self._cursor)

        self._implements: List[NativeImplement] = []

        # 是否使用默认实现。
        self._useDefalut = True
        self._this = this

    @property
    def Default(self):
        return self._useDefalut

    @Default.setter
    def Default(self, val: bool):
        self._useDefalut = val

    @property
    def Supported(self):
        return super().Supported or self._useDefalut

    def GetImplStr(self, new=False):
        if new:
            return NativeMethod.GetImplStr(self, new)
        else:
            cxx = []
            for impl in self._implements:
                line, args = [], []
                line.append(self._wholeFuncName + "(")
                for arg in impl.Args:
                    args.append(arg)
                line.append(",".join(args))
                line.append(")")
                cxx.append("".join(line))
            return ",".join(cxx)

    def __str__(self) -> str:
        # 不再生成构造。
        return ""


class NativeObject(NativeWrapper):
    """类，结构体的基类。"""

    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        self._parents: List[NativeObject] = []
        self._directlyParents: List[NativeObject] = []
        # 直接父级，当只有一个直接父级时，此值才有意义。
        self._parent: NativeObject = None
        self.__onlyParent = True
        # 生成字典，在该字典中的方法才会生成。
        self._methods: Dict[str, NativeMethod] = {}
        # 全方法字典，用于存储和查询。
        # self._allMethods = {}
        # 纯虚函数字典。
        self._pvMethods = {}
        # 虚函数字典。
        # 对于虚函数：
        # 1、基类有声明的，由基类绑定一次；
        # 2、只要自己有另一个同名方法，那么自己再绑定一次重载方法，否则自己不再绑定。
        self._tMethods = {}
        self._fileds = []
        self._ctor = NativeConstructor(self)
        # 如果还有名为"new"的函数（包括重命名的函数），那么，该类或结构体有new构造。
        self._newCtor: NativeMethod = None
        # 所含的内部类，包括枚举/结构体。
        self._classes = []
        # 存放具有获取和销毁单例方法的列表。
        self._instanceMethodList = [None, None]
        # 强制记录虚函数的表，用于子类查找实现，以判断是否跳过生成重写的方法。
        self._fvMethods = {}

        self.__DeepIterate(self._cursor)

        for p in self._parents:
            # 任意父级没有默认构造，即不使用默认构造。
            if not p._ctor.Default:
                self._ctor.Default = False
                break

    @property
    def NewConstructor(self):
        return self._newCtor

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

                    if parent not in self._directlyParents:
                        self._directlyParents.append(parent)
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
        if (cursor.kind == cindex.CursorKind.CXX_METHOD and
            not cursor.type.is_function_variadic()) or \
                cursor.kind == cindex.CursorKind.USING_DECLARATION:
            static = False
            if cursor.kind == cindex.CursorKind.USING_DECLARATION:
                nodes = []
                for node in cursor.get_children():
                    nodes.append(node)
                if len(nodes) == 3 and\
                        nodes[0].kind == cindex.CursorKind.TYPE_REF and\
                        nodes[1].kind == cindex.CursorKind.OVERLOADED_DECL_REF and\
                        nodes[2].kind == cindex.CursorKind.TYPE_REF and\
                        self._parent.WholeName == CursorHelper.GetWholeName(nodes[0].get_definition()):
                    # 尝试匹配 using Parent::Parent;语句
                    # 匹配成功后，默认构造不可用。
                    self._ctor.Default = False
                    if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                        self._ctor.Merge(self._parent._ctor)
                    return
                if len(nodes) == 2 and\
                        nodes[0].kind == cindex.CursorKind.TYPE_REF and\
                        nodes[1].kind == cindex.CursorKind.OVERLOADED_DECL_REF and\
                        cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                    # 尝试匹配 using Parent::Method;语句
                    prefix = nodes[0].get_definition().displayname
                    spelling = nodes[1].displayname
                    method = None
                    breakFlag = False
                    for parent in self._parents:
                        if parent.Name == prefix:
                            for mName, m in parent._methods.items():
                                if mName == spelling:
                                    method = m.OverloadBy(self)
                                    breakFlag = True
                                    break
                        if breakFlag:
                            break
                    if not method:
                        return
                else:
                    return
            else:
                # 成员函数，且跳过函数变量。
                method = NativeMethod(cursor, self._generator)
                pureVirtual = cursor.is_pure_virtual_method()
                static = cursor.is_static_method()
                if pureVirtual:
                    # 统计纯虚函数。
                    if method._wholeName not in self._pvMethods:
                        self._pvMethods[method._wholeName] = method
                else:
                    # 消减已实现的纯虚函数。
                    if method._wholeName in self._pvMethods:
                        self._pvMethods.pop(method._wholeName)
            if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                if not method.Supported or\
                        CursorHelper.GetAvailability(cursor) == CursorHelper.Availability.DEPRECATED:
                    return

                # 检查基类是否绑定，基类未绑定，那么自己需要绑定。
                parentBinding = False
                for parent in self._parents:
                    for pMethods in [parent._methods, parent._fvMethods]:
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
                        # 否则加入函数缓存字典。
                        self._PushToMethodDict(method, self._tMethods)
                    return
                else:
                    # 检查自己是否有在函数缓存字典中的方法。
                    if method.FuncName in self._tMethods:
                        method = self._PushToMethodDict(method, self._tMethods)
                        del self._tMethods[method.FuncName]

                if cursor.is_virtual_method():
                    self._PushToMethodDict(method, self._fvMethods)

                if method.Generatable:
                    if static:
                        if method.InstanceProperty >= 0 and self._instanceMethodList[method.InstanceProperty] is None:
                            self._instanceMethodList[method.InstanceProperty] = method

                    retMethod = self._PushToMethodDict(method, self._methods)
                    if retMethod.NewName == "new":
                        self._newCtor = retMethod
                # self._PushToMethodDict(method, self._allMethods)
        elif cursor.kind == cindex.CursorKind.CONSTRUCTOR:
            self._ctor.Default = False
            if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                # 使用一个普通函数包装构造函数以便在接下来合并实现。
                ctor = NativeFunction(cursor, self._generator)
                if ctor.Supported:
                    self._ctor.Merge(ctor)
        elif cursor.kind == cindex.CursorKind.USING_DECLARATION:
            nodes = []
            for node in cursor.get_children():
                nodes.append(node)
            if len(nodes) == 3 and\
                    nodes[0].kind == cindex.CursorKind.TYPE_REF and\
                    nodes[1].kind == cindex.CursorKind.OVERLOADED_DECL_REF and\
                    nodes[2].kind == cindex.CursorKind.TYPE_REF and\
                    self._parent.WholeName == CursorHelper.GetWholeName(nodes[0].get_definition()):
                # 尝试匹配 using Parent::Parent;语句
                # 匹配成功后，默认构造不可用。
                self._ctor.Default = False
                if cursor.access_specifier == cindex.AccessSpecifier.PUBLIC:
                    self._ctor.Merge(self._parent._ctor)

    def _PushToMethodDict(self, method: NativeMethod, d: Dict[str, NativeMethod]) -> NativeMethod:
        """将一个方法推入方法字典，若有同名方法，将实现加入原方法。
        """
        name = method.FuncName
        if name not in d.keys():
            d[name] = method
            return method
        preMethod: NativeMethod = d[name]
        preMethod.Merge(method)
        return preMethod

    def __str__(self) -> str:
        if self._cxxStr:
            return self._cxxStr
        cxx = []
        upper = self._generator.UpperCamelCase
        # 优先生成内部枚举和内部类。
        for c in self._classes:
            cxx.append(str(c))
            cxx.append("\n")

        cxx.append("void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua)".format(
            self._generator.Tag, "".join(self._nameList[1:])))
        cxx.append("{\n")

        cxx.append(
            'cocos2d::extension::Lua::Id2Meta[typeid({wn}).name()] = sol::usertype_traits<{wn}*>::metatable();\n'.format(
                wn=self._wholeName)
        )
        cxx.append('auto dep=lua.new_usertype<{wholeName}>("deprecated.{wholeName}");\n'.format(wholeName=self._wholeName))
        # 类与基类名组合
        basesName = ""
        for p in self._parents:
            basesName += (p._wholeName + ",")
        if basesName:
            cxx.append("dep[sol::base_classes]=sol::bases<{}>();\n".format(basesName[:-1]))

        cxx.append('sol::table mt=lua.NewClass(sol::usertype_traits<{}*>::metatable()'.format(self._wholeName))
        for parent in self._directlyParents:
            cxx.append(',sol::usertype_traits<{}*>::metatable()'.format(parent._wholeName))
        cxx.append(');\n')

        cxx.append('lua["{}"]'.format(self._simpleNS))
        for pField in self._nNameList[1:-1]:
            cxx.append('["{}"]'.format(
                pField if not upper else CursorHelper.UpperCamelCase(pField)
            ))
        cxx.append('["{}"]=mt;\n'.format(self._newName if not upper else CursorHelper.UpperCamelCase(self._newName)))

        if not self._newCtor:
            cxx.append('mt["{}"] = [](){{return nullptr;}};\n'.format(self._generator.LuaConfig["__new__"]))

        # 方法生成。
        for method in self._methods.values():
            cxx.append(str(method))
            cxx.append("\n")

        # public域生成。
        for field in self._fileds:
            cxx.append(str(field))
            cxx.append("\n")

        # 调用注册内部枚举和内部类。
        for c in self._classes:
            cxx.append('RegisterLua{}{}Auto(lua);\n'.format(self._generator.Tag, "".join(c._nameList[1:])))

        # 单例属性。
        if self._instanceMethodList[0]:
            cxx.append('mt["{}"]["Instance"]=&{};\n'.format(
                self._generator.LuaConfig["get"],
                self._instanceMethodList[0].WholeFuncName))
        if self._instanceMethodList[1]:
            cxx.append('mt["{}"]["Instance"]=[](std::nullptr_t){{{}();}};\n'.format(
                self._generator.LuaConfig["set"],
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
