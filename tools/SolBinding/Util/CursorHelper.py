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

import hashlib
from enum import Enum
from clang import cindex


class CursorHelper:
    """一个获取cindex.TranslationUnit.cusor信息的类。"""

    class Availability(Enum):
        """指示游标的可用性。"""
        AVAILABLE = 0
        DEPRECATED = 1
        NOT_AVAILABLE = 2
        NOT_ACCESSIBLE = 3

    @staticmethod
    def _BuildNameSpace(cursor, includeClassName: bool = True, nameSpace: list = None) -> list:
        """构建命名空间到所属类名的列表。"""
        if None is nameSpace:
            nameSpace = []
        parent = cursor.semantic_parent
        if parent:
            if parent.kind == cindex.CursorKind.NAMESPACE or\
                    (parent.kind == cindex.CursorKind.CLASS_DECL or
                     parent.kind == cindex.CursorKind.STRUCT_DECL or
                     parent.kind == cindex.CursorKind.ENUM_DECL):
                CursorHelper._BuildNameSpace(parent, includeClassName, nameSpace)
                if parent.displayname and (parent.kind == cindex.CursorKind.NAMESPACE or includeClassName) and parent.displayname != "__ndk1":
                    nameSpace.append(parent.displayname)
        return nameSpace

    @staticmethod
    def GetAvailability(cursor) -> Availability:
        """获取可用性。"""
        if not hasattr(cursor, "_availability"):
            cursor._availability = cindex.conf.lib.clang_getCursorAvailability(cursor)

        return CursorHelper.Availability(cursor._availability)

    @staticmethod
    def GetName(cursor) -> str:
        """获取名字。
        当displayname不存在时，尝试使用类型的名字。
        """
        if cursor.displayname:
            return cursor.displayname
        cName = cursor.type.spelling
        # spelling名字中包含(的可能是匿名的。
        if cName and not cName.find("("):
            cList = cName.split("::")
            if cList:
                return cList[len(cList)-1]
        return ""

    @staticmethod
    def GetParentName(cursor) -> str:
        """获取直接父级的名字。"""
        parent = cursor.semantic_parent
        if parent:
            return parent.displayname
        return ""

    @staticmethod
    def GetWholeName(cursor) -> str:
        """获得全名，包含命名空间名和所属类名。"""
        ns = CursorHelper._BuildNameSpace(cursor)
        ns.append(CursorHelper.GetName(cursor))
        return "::".join(ns)

    @staticmethod
    def GetClassesNameList(cursor, l=None) -> list:
        """获得所属类的全名列表，不包括命名空间名。"""
        if l is None:
            l = []
        parent = cursor.semantic_parent
        if parent and\
                parent.kind == cindex.CursorKind.CLASS_DECL or parent.kind == cindex.CursorKind.STRUCT_DECL:
            name = parent.displayname
            if name != "__ndk1":
                l.append(name)
            CursorHelper.GetClassesNameList(parent, l)
        return l

    @staticmethod
    def GetClassesName(cursor) -> str:
        """获得所属类的全名，不包括命名空间名。"""
        return "::".join(CursorHelper.GetClassesNameList(cursor))

    @staticmethod
    def GetPrefixName(cursor) -> str:
        """获得前缀名，包含命名空间名和所属类名。"""
        return "::".join(CursorHelper._BuildNameSpace(cursor))

    @staticmethod
    def GetNameSpace(cursor) -> str:
        """获得命名空间名。"""
        return "::".join(CursorHelper._BuildNameSpace(cursor, False))

    @staticmethod
    def AssumeEnumName(cursor) -> str:
        """为匿名枚举假设一个名字。"""
        name = CursorHelper.GetName(cursor)
        if cursor.kind != cindex.CursorKind.ENUM_DECL or name:
            return name
        nsName = CursorHelper.GetPrefixName(cursor)
        signList = [nsName]
        for node in cursor.get_children():
            if node.kind == cindex.CursorKind.ENUM_CONSTANT_DECL:
                signList.append(node.displayname)
                signList.append(";")
        retStr = ''.join(signList)
        md5 = hashlib.md5()
        md5.update(retStr.encode())
        return ("_AE_" + md5.hexdigest() + "_")

    @staticmethod
    def GetArgName(ntype) -> str:
        """获得参数名，也可用于获得返回值名（获取的是类型名，而不是变量名）。"""

        if ntype.kind == cindex.TypeKind.POINTER:
            return CursorHelper.GetArgName(ntype.get_pointee()) + "*"
        elif ntype.kind == cindex.TypeKind.LVALUEREFERENCE:
            return CursorHelper.GetArgName(ntype.get_pointee()) + "&"
        else:
            decl = ntype.get_declaration()
            if decl.kind == cindex.CursorKind.NO_DECL_FOUND:
                return ntype.spelling.replace("__ndk1::", "")
            name = CursorHelper.GetWholeName(decl)
            return (("const " if ntype.is_const_qualified() else "") + name).replace("__ndk1::", "")
