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

from typing import List
from clang import cindex
from Config.BaseConfig import BaseConfig
from Util.CursorHelper import CursorHelper


class NativeType(object):
    """类，结构体，枚举，方法，成员变量等的基类。"""

    def __init__(self, cursor, generator: BaseConfig) -> None:
        object.__init__(self)
        self._cursor: cindex.Cursor = cursor
        self._generator = generator
        # 生成的c++字符串。
        self._cxxStr = None
        # 原始名。
        self._name = CursorHelper.GetName(cursor)
        # 原始全名。
        self._wholeName = CursorHelper.GetWholeName(cursor)
        self._newName = self._name
        # 可生成。
        self._generatable = True

    @property
    def WholeName(self):
        return self._wholeName

    @property
    def Generatable(self):
        return self._generatable

    @property
    def Generator(self):
        return self._generator

    @property
    def Name(self):
        return self._name

    @property
    def Cursor(self):
        return self._cursor


class NativeMember(NativeType):
    """成员方法，成员变量等的基类。"""

    def __init__(self, cursor, generator: BaseConfig) -> None:
        NativeType.__init__(self, cursor, generator)
        # 获取可能的重命名。
        pName = CursorHelper.GetClassesName(cursor)
        self._newName = generator.RenameMember(pName, cursor.spelling)
        self._generatable = not generator.ShouldSkip(pName, cursor.spelling)

    @property
    def NewName(self):
        return self._newName


class NativeImplement(object):
    """函数实现类。
    多个互为重载的函数，可以作为一个具有多种实现的同一函数。
    一个具有默认值参数的函数，也是一种具有多种实现的函数。
    """
    __LiteralList = [
        cindex.CursorKind.INTEGER_LITERAL, cindex.CursorKind.FLOATING_LITERAL,
        cindex.CursorKind.IMAGINARY_LITERAL, cindex.CursorKind.STRING_LITERAL,
        cindex.CursorKind.CHARACTER_LITERAL, cindex.CursorKind.CXX_BOOL_LITERAL_EXPR,
        cindex.CursorKind.CXX_NULL_PTR_LITERAL_EXPR, cindex.CursorKind.GNU_NULL_EXPR,
        # An expression that refers to some value declaration, such as a function,
        # varible, or enumerator.
        cindex.CursorKind.DECL_REF_EXPR]

    @staticmethod
    def CreateImplements(cursor, nativeObj):
        """由一个游标，自动创建一组实现。
        一般的，有默认值的函数游标，将生成多个实现。
        """
        retImpl: List[NativeImplement] = []
        result = CursorHelper.GetArgName(cursor.result_type)
        args: List[str] = []

        for arg in cursor.type.argument_types():
            if arg.kind == cindex.TypeKind.RVALUEREFERENCE:
                # 右值引用不可用。
                return []
            args.append(CursorHelper.GetArgName(arg))

        # 最小参数数量。
        minArgs = len(args)
        idx = 0
        for node in cursor.get_children():
            if node.kind == cindex.CursorKind.PARM_DECL:
                if NativeImplement.__CheckDefaultArg(node):
                    # 当最小参数数量小于参数列表数时，表示该函数有默认参数。
                    minArgs = idx
                    break
                idx = idx + 1

        # 具有（最大参数数量-最小参数数量+1）种实现。
        # 且参数数量越长的实现在越靠前（sol重载以先查找先匹配的原则决定重载）。
        for index in range(len(args) - minArgs + 1):
            impl = NativeImplement(cursor, args[:len(args) - index], result)
            impl._hasDefault = minArgs < len(args)
            retImpl.append(impl)

        return retImpl

    def __init__(self, cursor: cindex.Cursor, args: List[str], res: str) -> None:
        super().__init__()
        self._cursor = cursor
        self._name = cursor.spelling
        self._args = args
        self._result = res
        # 普通函数始终是静态函数。
        self._static: bool = True
        # 该实现是否基于默认参数。
        self._hasDefault: bool = False

    @staticmethod
    def __CheckDefaultArg(paramNode) -> bool:
        """检查是否有默认参数。"""
        for node in paramNode.get_children():
            if node.kind in NativeImplement.__LiteralList:
                return True
            if NativeImplement.__CheckDefaultArg(node):
                return True
        return False

    def __eq__(self, o: object) -> bool:
        if isinstance(o, NativeImplement):
            return self._args == o._args and self._static == o._static
        return False

    @property
    def Args(self):
        return self._args

    @property
    def Result(self):
        return self._result

    @property
    def Static(self):
        return self._static

    @property
    def Default(self):
        return self._hasDefault


class NativeFunction(NativeType):
    """成员方法，普通函数等的基类。"""

    def __init__(self, cursor, generator: BaseConfig, T: NativeImplement = None, nativeObj=None) -> None:
        super().__init__(cursor, generator)
        self._prefixName = CursorHelper.GetPrefixName(cursor)
        self._funcName = cursor.spelling
        self._wholeFuncName = self._prefixName + "::" + self._funcName
        self._nativeObj = nativeObj
        if not T:
            T = NativeImplement
        self._implements = T.CreateImplements(cursor, nativeObj)

    def AddImplements(self, p: "cindex.Cursor | NativeImplement"):
        if isinstance(p, cindex.Cursor):
            implements = NativeImplement.CreateImplements(p, self._nativeObj)
            for impl in implements:
                self.AddImplements(impl)
        elif isinstance(p, NativeImplement):
            for impl in self._implements:
                if p == impl:
                    return

            # 如果不是静态方法，参数长度+1，因为this指针将作为第一个参数。
            pLen = len(p.Args) if p.Static else len(p.Args) + 1
            for idx, impl in enumerate(self._implements):
                iLen = len(impl.Args) if impl.Static else len(impl.Args) + 1
                if pLen >= iLen:
                    self._implements.insert(idx, p)
                    return
            self._implements.append(p)

    def Merge(self, func: "NativeFunction"):
        for impl in func._implements:
            self.AddImplements(impl)

    @property
    def Supported(self):
        return len(self._implements) > 0

    @property
    def FuncName(self):
        return self._funcName

    @property
    def WholeFuncName(self):
        return self._wholeFuncName

    @property
    def PrefixName(self):
        return self._prefixName

    @property
    def Overload(self):
        return len(self._implements) > 1


class NativeWrapper(NativeType):
    """类，结构体，枚举，全局变量等的基类。"""

    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        # 获取可能的重命名。
        self._newName = generator.RenameClass(self._name)

        # 简化命名空间名。
        self._simpleNS = generator.TargetNamespace

        pList = CursorHelper.GetClassesNameList(cursor)
        self._generatable = not generator.ShouldSkip("::".join([*pList, self._name]))

        if self._generatable:
            for pClass in pList:
                if generator.ShouldSkip(pClass):
                    self._generatable = False
                    break

        listName = self._wholeName
        for rNS in self._generator.CppNameSpace:
            if listName.startswith(rNS):
                listName = listName.replace(rNS, self._simpleNS, 1)
                break

        # 含有全名称的列表。
        self._nameList = listName.split("::")
        # 含有新名称的列表。
        self._nNameList = self._nameList.copy()
        # 重命名列表中的类名为新名称。
        for idx, name in enumerate(self._nNameList[1:]):
            self._nNameList[idx+1] = generator.RenameClass(name)

    @property
    def NameList(self):
        # 从命名空间开始的一系列名称列表。
        return self._nameList


class NativeGlobal(NativeWrapper):
    """全局变量。"""

    def __str__(self) -> str:
        if not self._cxxStr:
            upper = self._generator.UpperCamelCase
            strList = ["void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua) {{\n".format(
                self._generator.Tag, "".join(self._nameList[1:]))]
            strList.append('sol::table pTable = lua["{}"];\n'.format(self._simpleNS))
            for pField in self._nNameList[1:-1]:
                strList.append('pTable = pTable["{}"];\n'.format(
                    pField if not upper else CursorHelper.UpperCamelCase(pField)
                ))

            strList.append('pTable["{}"] = {};\n}}\n'.format(
                self._newName if not upper else CursorHelper.UpperCamelCase(self._newName), self._wholeName
            ))
            self._cxxStr = ''.join(strList)
        return self._cxxStr
