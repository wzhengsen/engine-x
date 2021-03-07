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

import os
import sys
import re
from clang import cindex
from Util.Functions import *
from Util.CursorHelper import CursorHelper
from Config.BaseConfig import BaseConfig
from Native.NativeObject import *
from Native.NativeEnum import *


class BaseGenerator(BaseConfig):
    def __init__(self, outputPath: str, outputFile: str, clearOldFile: bool = True):
        """
        参数：

            outputPath          生成代码的目录。

            outputFile          生成代码的文件名，不需要带有后缀。
                                比如文件名为"gFile"，则将生成：
                                outputPath/gFile.hpp
                                outputPath/gFile.cpp
                                outputPath/gFile_01.cpp
                                outputPath/gFile_02.cpp
                                ...

            clearOldFile        是否清除原来的旧文件再生成，还是采取覆盖的方式。
                                该参数在文件总数有变化时很有用。
        """
        super().__init__()
        self._outputPath = outputPath
        self._outputFile = outputFile
        self._clearOldFile = clearOldFile
        self._nativeObjects = {}
        # 缓存的所有父级节点，这些节点不一定会被生成代码。
        self.TempParentObjects = {}

        self.__inited = False

        if not cindex.Config.loaded:
            cindex.Config.set_library_path(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "libclang")))
        self._cindex = cindex.Index.create()

    def __LazyInit(self):
        if not self.__inited:
            self.__inited = True
            if sys.platform == "win32":
                self.ClangArgs += self.ExtraArgs
                self.ClangArgs += self.Win32ClangFlags
            self.CppNameSpace.sort()
            self.CppNameSpace.reverse()

    @property
    def NativeObjects(self) -> dict:
        return self._nativeObjects

    def _CheckOldFile(self):
        """检查是否需要删除旧文件。"""
        if not self._clearOldFile:
            return
        matchFiles = FindAllFilesMatch(self._outputPath, lambda x: -1 != x.find(self._outputFile))
        for file in matchFiles:
            os.remove(file)

    def _GenerateHeadCode(self):
        """生成c++头文件。
        """
        with open(os.path.join(self._outputPath, self._outputFile + ".hpp"), "w") as hFile:
            hFile.write((
                '#pragma once\n'
                '#include "base/ccConfig.h"\n'
                '#include "scripting/lua-bindings/manual/CCLuaConvertSol.hpp"\n'
                'void RegisterLua{}Auto(cocos2d::extension::Lua&);'
            ).format(self.Tag))

    def _GenerateImplCode(self):
        """生成c++实现文件。
        """
        with open(os.path.join(self._outputPath, self._outputFile + ".cpp"), "w") as iFile:
            strList = []
            strList.append('#include "scripting/lua-bindings/auto/{}.hpp"\n'.format(self._outputFile))
            for header in self.Headers:
                relative = ".."
                for searchPath in self.SearchPaths:
                    relative = os.path.relpath(header, searchPath)
                    if not ".." in relative:
                        break
                if ".." not in relative:
                    strList.append('#include "{}"\n'.format(relative.replace(os.path.sep, '/')))
                else:
                    strList.append('#include "{}"\n'.format(os.path.basename(header)))

            for c in self._nativeObjects.values():
                strList.append("extern void RegisterLua{}{}Auto(cocos2d::extension::Lua&);\n".format(
                    self.Tag, "".join(c.NameList[1:])))

            strList.append("void RegisterLua{}Auto(cocos2d::extension::Lua& lua){{\n".format(self.Tag))
            if self.MacroJudgement:
                strList.append(self.MacroJudgement + "\n")
            strList.append('lua["{0}"]=lua.get_or("{0}",lua.create_table());\n'.format(self.TargetNamespace))
            for c in self._nativeObjects.values():
                strList.append("RegisterLua{}{}Auto(lua);\n".format(self.Tag, "".join(c.NameList[1:])))
            if self.MacroJudgement:
                strList.append("#endif\n")
            strList.append("}")
            iFile.write(''.join(strList))

    def _GenerateObjectCode(self):
        """为避免产生编译器C1060错误，将每10个类/枚举/结构体放置于一个实现文件。
        """

        groupIndex = 10
        idx = 0
        strList = []

        def DoEnd(self: BaseGenerator):
            if not strList:
                return
            if self.MacroJudgement:
                strList.append("#endif\n")
            with open(os.path.join(self._outputPath, self._outputFile + ("_%02d.cpp" % (idx // groupIndex))), "w") as implFile:
                implFile.write(''.join(strList))
                strList.clear()

        for obj in self._nativeObjects.values():
            if idx % groupIndex == 0:
                strList.append('#include "scripting/lua-bindings/auto/{}.hpp"\n'.format(self._outputFile))
                for header in self.Headers:
                    relative = ".."
                    for searchPath in self.SearchPaths:
                        relative = os.path.relpath(header, searchPath)
                        if not ".." in relative:
                            break
                    if ".." not in relative:
                        strList.append('#include "{}"\n'.format(relative.replace(os.path.sep, '/')))
                    else:
                        strList.append('#include "{}"\n'.format(os.path.basename(header)))
                if self.MacroJudgement:
                    strList.append(self.MacroJudgement + "\n")

            strList.append(str(obj))
            strList.append("\n")

            if idx % groupIndex == groupIndex - 1:
                DoEnd(self)

            idx += 1
        else:
            DoEnd(self)

    def _GenerateCode(self):
        self._GenerateHeadCode()
        self._GenerateImplCode()
        self._GenerateObjectCode()

    def Generate(self):
        self.__LazyInit()
        self._nativeObjects.clear()
        print("\n生成 {} 代码……".format(self._outputFile))
        self._ParseHeaders()
        self._CheckOldFile()
        self._GenerateCode()
        print("\n完成 {} 生成。".format(self._outputFile))

    def RenameMember(self, className: str, funcName: str) -> str:
        """重命名给定的函数。

        参数：

            className           类名，可也以是结构体名。

            funcName            函数名，也可以是成员名。

        返回：
            若没有对应的重命名规则，返回原函数名。
        """
        for k, v in self.RenameMembers.items():
            if re.match("^" + k + "$", className):
                if funcName in v:
                    return v[funcName]
        return funcName

    def RenameClass(self, className: str) -> str:
        """重命名给定的类（结构体，枚举）。

        参数：

            className           类名，可也以是结构体/枚举名。

        返回：
            若没有对应的重命名规则，返回原类型名。
        """
        for k, v in self.RenameClasses.items():
            if re.match("^" + k + "$", className):
                return v
        return className

    def ShouldSkip(self, className: str, funcName: str = None) -> bool:
        """判断是否应当跳过该类或成员函数。

        参数：

            className           类名，可也以是结构体名或枚举名。
            funcName            成员函数名/成员变量名，可以为空，此时只检查类名。
        """
        if not className:
            return True
        for name in self.Classes:
            if re.match("^" + name + "$", className):
                break
        else:
            return True

        if funcName:
            for skipCls, skipFuncs in self.Skip.items():
                if re.match("^" + skipCls + "$", className):
                    for skipFunc in skipFuncs:
                        if re.match("^" + skipFunc + "$", funcName):
                            return True

        return False

    def _CheckDiagnostics(self, diagnostics):
        """检查并打印诊断信息。"""
        errors = []
        for idx, d in enumerate(diagnostics):
            if d.severity > cindex.Diagnostic.Warning:
                errors.append(d)
        if not errors:
            return
        print("====\n解析头文件发生错误：")
        severities = ["忽略", "注意", "警告", "错误", "致命"]
        for idx, d in enumerate(errors):
            print("{}.  严重性 = {},\n    位于 ： [{}] {!r},\n    详细 ： {!r}".format(
                idx+1, severities[d.severity], self.Tag, d.location, d.spelling))
        print("====\n")
        print("*** 发现错误，无法继续。")
        raise Exception("Fatal error in parsing headers")

    def _ParseHeaders(self):
        for header in self.Headers:
            print("{} -> {}".format(self.Tag, header))
            tu = self._cindex.parse(header, self.ClangArgs)
            self._CheckDiagnostics(tu.diagnostics)
            self._DeepIterate(tu.cursor)

    def _DeepIterate(self, cursor):
        if next(cursor.get_children(), None) is None:
            return

        if ((cursor.kind == cindex.CursorKind.CLASS_DECL or (self.AllowStruct and cursor.kind == cindex.CursorKind.STRUCT_DECL))
                or cursor.kind == cindex.CursorKind.ENUM_DECL):
            if cursor == cursor.type.get_declaration() and CursorHelper.GetNameSpace(cursor) in self.CppNameSpace:
                name = CursorHelper.GetName(cursor)
                # 匿名判断不使用cursor.is_anonymous()获取，此处直接简单判断名字作为匿名标准。
                if name:
                    # 具名枚举和类。
                    if not self.ShouldSkip(name):
                        wholeName = CursorHelper.GetWholeName(cursor)
                        if wholeName not in self._nativeObjects.keys():
                            if cursor.kind == cindex.CursorKind.ENUM_DECL:
                                self._nativeObjects[wholeName] = NativeEnum(cursor, self)
                            elif cursor.kind == cindex.CursorKind.CLASS_DECL:
                                self._nativeObjects[wholeName] = NativeClass(cursor, self)
                            else:
                                self._nativeObjects[wholeName] = NativeStruct(cursor, self)
                elif self.AllowAnonymous:
                    # 匿名枚举。
                    # 要求该匿名枚举的父级必须是被包含在生成列表中的。
                    ae = NativeAnonymousEnum(cursor, self)
                    for clsName in ae.NameList[1:-1]:
                        if self.ShouldSkip(clsName):
                            return

                    if ae._name not in self._nativeObjects.keys():
                        self._nativeObjects[ae._name] = ae
            return

        for node in cursor.get_children():
            self._DeepIterate(node)
