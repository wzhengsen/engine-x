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

from Util.CursorHelper import CursorHelper
from .NativeObject import NativeWrapper


class NativeEnum(NativeWrapper):
    def _GetKeyValue(self) -> dict:
        """获取枚举的键值对字典。"""
        kv = {}
        for node in self._cursor.get_children():
            kv[node.displayname] = CursorHelper.GetWholeName(node)
        return kv

    def __str__(self) -> str:
        """具名枚举的生成。
        依照 命名空间::类型名::类型名...::枚举名{...}的方式生成。
        """
        if not self._cxxStr:
            kvMap = self._GetKeyValue()
            strList = ["void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua) {{\n".format(
                self._generator.Tag, "".join(self._nameList[1:]))]
            strList.append('sol::table pTable = lua["{}"];\n'.format(self._simpleNS))
            for pField in self._nNameList[1:-1]:
                strList.append('pTable = pTable["{}"];\n'.format(pField))

            strList.append('pTable.new_enum<{}>("{}",{{\n'.format(self._wholeName, self._newName))
            enumList = []
            for key, value in kvMap.items():
                enumList.append('{{"{}",{}}}\n'.format(key, value))
            strList.append(",".join(enumList))
            strList.append("});}")
            self._cxxStr = ''.join(strList)
        return self._cxxStr


class NativeAnonymousEnum(NativeEnum):
    def __init__(self, cursor, generator) -> None:
        super().__init__(cursor, generator)
        # 匿名枚举追加一个生成的名字。
        aeName = CursorHelper.AssumeEnumName(cursor)
        self._name = aeName
        self._newName = aeName
        self._nameList[len(self._nameList)-1] = aeName
        self._nNameList[len(self._nNameList)-1] = aeName
        self._generatable = True

    def __str__(self) -> str:
        """匿名枚举的生成。
        依照 命名空间::类型名::类型名...最后的类型名{...}的方式生成。
        """
        if not self._cxxStr:
            kvMap = self._GetKeyValue()
            strList = ["void RegisterLua{}{}Auto(cocos2d::extension::Lua& lua) {{\n".format(
                self._generator.Tag, "".join(self._nameList[1:]))]
            strList.append('sol::table pTable = lua["{}"];\n'.format(self._simpleNS))
            for pField in self._nNameList[1:-1]:
                strList.append('pTable = pTable["{}"];\n'.format(pField))

            for key, value in kvMap.items():
                strList.append('pTable["{}"] = {};\n'.format(key, value))
            strList.append("}")
            self._cxxStr = ''.join(strList)
        return self._cxxStr
