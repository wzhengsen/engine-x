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

from clang import cindex
from Util.CursorHelper import CursorHelper
from .NativeObject import NativeWrapper
from Config.BaseConfig import BaseConfig


class NativeEnum(NativeWrapper):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        # 若生成为lua代码时使用。
        self._luaStr = ""

    def _GetKeyValue(self, useValue: bool = False) -> dict:
        """获取枚举的键值对字典。
        参数：
            useValue        是否直接使用字面值。
        """
        kv = {}
        for node in self._cursor.get_children():
            if not useValue:
                kv[node.displayname] = CursorHelper.GetWholeName(node)
            else:
                kv[node.displayname] = node.enum_value
        return kv

    def __str__(self) -> str:
        """具名枚举的生成。
        c++依照 命名空间::类型名::类型名...::枚举名{...};的方式生成。
        lua依照 命名空间.类型名.类型名....枚举名 = {...};的方式生成。
        """
        if not self._generator.EnumForLua:
            if not self._cxxStr:
                upper = self._generator.UpperCamelCase
                kvMap = self._GetKeyValue()
                strList = ["void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua) {{\n".format(
                    self._generator.Tag, "".join(self._nameList[1:]))]

                strList.append('sol::table enumTable = lua.create_table(lua.lua_state(),0,{});\n'.format(len(kvMap)))
                for key, value in kvMap.items():
                    strList.append(
                        'enumTable["{}"]={};\n'.format(
                            key if not upper else CursorHelper.UpperCamelCase(key),
                            str(value)
                        )
                    )

                strList.append('lua["{}"]'.format(self._simpleNS))
                for pField in self._nNameList[1:-1]:
                    strList.append('["{}"]'.format(
                        pField if not upper else CursorHelper.UpperCamelCase(pField)
                    ))

                pNS = self._cursor.semantic_parent.kind == cindex.CursorKind.NAMESPACE

                if not pNS:
                    strList.append(
                        '["{}"]["{}"]='.format(
                            self._generator.LuaConfig["Qualifiers"]["static"], self._newName if not upper else CursorHelper.UpperCamelCase(self._newName))
                    )
                else:
                    strList.append(
                        '["{}"]='.format(
                            self._newName if not upper else CursorHelper.UpperCamelCase(self._newName))
                    )

                strList.append('lua.NewEnum(enumTable);\n')
                strList.append("}")
                self._cxxStr = ''.join(strList)
            return self._cxxStr
        if not self._luaStr:
            upper = self._generator.UpperCamelCase
            kvMap = self._GetKeyValue(True)
            strList = []
            strList.append(self._simpleNS)
            for pField in self._nNameList[1:]:
                strList.append('.{}'.format(
                    pField if not upper else CursorHelper.UpperCamelCase(pField)
                ))
            strList.append(" = {\n")
            enumList = []
            for key, value in kvMap.items():
                enumList.append('    {} = {}'.format(
                    key if not upper else CursorHelper.UpperCamelCase(key), value
                ))
            strList.append(",\n".join(enumList))
            strList.append("\n};")
            self._luaStr = ''.join(strList)
        return self._luaStr


class NativeAnonymousEnum(NativeEnum):
    def __init__(self, cursor, generator: BaseConfig) -> None:
        super().__init__(cursor, generator)
        # 匿名枚举追加一个生成的名字。
        aeName = CursorHelper.AssumeEnumName(cursor)
        self._name = aeName
        self._newName = aeName
        self._nameList[-1] = aeName
        self._nNameList[-1] = aeName

        parentName = CursorHelper.GetClassesName(cursor)
        self._generatable = False
        if generator.AllowAnonymous == BaseConfig.AnonymousType.Ban:
            self._generatable = False
        elif generator.AllowAnonymous == BaseConfig.AnonymousType.All:
            self._generatable = True
        elif generator.AllowAnonymous == BaseConfig.AnonymousType.Class:
            if parentName:
                self._generatable = not generator.ShouldSkip(parentName)
        elif generator.AllowAnonymous == BaseConfig.AnonymousType.Global:
            if not parentName:
                self._generatable = True

    def __str__(self) -> str:
        """匿名枚举的生成。
        c++依照 命名空间::类型名::类型名...最后的类型名["键名"] = 值;的方式生成。
        lua依照 命名空间.类型名.类型名...最后的类型名.键名 = 值;的方式生成。
        """
        if not self._generator.EnumForLua:
            if not self._cxxStr:
                upper = self._generator.UpperCamelCase
                kvMap = self._GetKeyValue()
                strList = ["void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua) {{\n".format(
                    self._generator.Tag, "".join(self._nameList[1:]))]
                strList.append('sol::table pTable = lua["{}"];\n'.format(self._simpleNS))
                for pField in self._nNameList[1:-1]:
                    strList.append('pTable = pTable["{}"];\n'.format(
                        pField if not upper else CursorHelper.UpperCamelCase(pField)
                    ))

                for key, value in kvMap.items():
                    strList.append('pTable["{}"]["{}"]["{}"] = {};\n'.format(
                        self._generator.LuaConfig["Qualifiers"]["static"],
                        self._generator.LuaConfig["Qualifiers"]["const"],
                        key if not upper else CursorHelper.UpperCamelCase(
                            key), value
                    ))
                strList.append("}")
                self._cxxStr = ''.join(strList)
            return self._cxxStr
        if not self._luaStr:
            upper = self._generator.UpperCamelCase
            kvMap = self._GetKeyValue(True)
            strList = ["do\n"]
            strList.append('local ')
            name = self._nNameList[-2]
            if len(self._nNameList) > 2:
                name = name if not upper else CursorHelper.UpperCamelCase(name)
            strList.append(name)
            strList.append(' = ')
            strList.append(self._simpleNS)
            for name in self._nNameList[1:-1]:
                strList.append(".")
                strList.append(name if not upper else CursorHelper.UpperCamelCase(name))
            strList.append(";\n")
            for key, value in kvMap.items():
                strList.append('{}.{} = {};\n'.format(
                    name, key if not upper else CursorHelper.UpperCamelCase(key), value
                ))
            strList.append("end")
            self._luaStr = ''.join(strList)
        return self._luaStr
