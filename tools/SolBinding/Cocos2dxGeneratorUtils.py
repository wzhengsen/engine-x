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

from Generator.Cocos2dxGenerator import Cocos2dxGenerator


class Cocos2dxGeneratorUtils(Cocos2dxGenerator):
    def __init__(self, **args):
        super().__init__(**args)
        self.TargetNamespace = "ccu"
        # 尽量确保嵌套层数较深的命名空间位于列表前端。
        self.CppNameSpace += ["cocos2d::utils"]
        self.Headers += [
            "{}/cocos/base/ccUtils.h".format(self.CocosRoot)
        ]
        self.ExtraArgs += [
            "-I{}/cocos/platform/android".format(self.CocosRoot)
        ]
        self.Classes += [
            "gettime", "getTimeInMilliseconds", "getCascadeBoundingBox", "createSpriteFromBase64.*", "getLanguageTypeByISO2", "toBackendBlendFactor",
            "toGLBlendFactor", "toBackendSamplerFilter", "toBackendAddressMode", "parseIntegerList", "bin2hex", "killCurrentProcess",
            "Convert", "GetClipboard", "SetClipboard", "getFileMD5Hash", "getDataMD5Hash"
        ]
        self.RenameClasses |= {
            "gettime": "GetTime",
            "bin2hex": "Bin2Hex"
        }
