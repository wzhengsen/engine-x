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
from .BaseGenerator import BaseGenerator


class Cocos2dxGenerator(BaseGenerator):
    def __init__(self, clearOldFile: bool = True):
        self.CocosRoot = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
        # 由当前类名获取生成的文件名。
        suffix = self.__class__.__name__.removeprefix(__class__.__name__)
        fileName = "CCRegisterLua" + suffix + "Auto"
        outputPath = "{}/extensions/scripting/lua-bindings/auto".format(self.CocosRoot)
        super().__init__(outputPath, fileName, clearOldFile)

        self.Tag = suffix
        self.SearchPaths += [
            os.path.join(self.CocosRoot, "cocos"),
            os.path.join(self.CocosRoot, "cocos", "extensions")
        ]

        self.InstanceMethods |= {
            ".*": "(g|G)etInstance"
        }

        # 解析时的依赖头文件路径等。
        self.ExtraArgs += [
            "-I{}/cocos".format(self.CocosRoot),
            "-I{}/extensions".format(self.CocosRoot),
            "-DANDROID"
        ]

        self.RenameMembers |= {
            ".*": {"create": "new"}
        }
        self.ParentsClassesSkip += ["Clonable"]
