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

import multiprocessing
from Generator.BaseGenerator import BaseGenerator
from Cocos2dxGeneratorCore import Cocos2dxGeneratorCore
from Cocos2dxGenerator3D import Cocos2dxGenerator3D
from Cocos2dxGeneratorAudioEngine import Cocos2dxGeneratorAudioEngine
from Cocos2dxGeneratorBackend import Cocos2dxGeneratorBackend
from Cocos2dxGeneratorController import Cocos2dxGeneratorController
from Cocos2dxGeneratorCSLoader import Cocos2dxGeneratorCSLoader
from Cocos2dxGeneratorExtension import Cocos2dxGeneratorExtension
from Cocos2dxGeneratorNavMesh import Cocos2dxGeneratorNavMesh
from Cocos2dxGeneratorPhysics import Cocos2dxGeneratorPhysics
from Cocos2dxGeneratorPhysics3D import Cocos2dxGeneratorPhysics3D
from Cocos2dxGeneratorSpine import Cocos2dxGeneratorSpine
from Cocos2dxGeneratorStudio import Cocos2dxGeneratorStudio
from Cocos2dxGeneratorUI import Cocos2dxGeneratorUI

_genList = [
    Cocos2dxGeneratorCore,
    Cocos2dxGenerator3D,
    Cocos2dxGeneratorAudioEngine,
    Cocos2dxGeneratorBackend,
    Cocos2dxGeneratorController,
    Cocos2dxGeneratorCSLoader,
    Cocos2dxGeneratorExtension,
    Cocos2dxGeneratorNavMesh,
    Cocos2dxGeneratorPhysics,
    Cocos2dxGeneratorPhysics3D,
    Cocos2dxGeneratorSpine,
    Cocos2dxGeneratorStudio,
    Cocos2dxGeneratorUI
]


def _ProcessWork(idx):
    if idx < 0 or idx >= len(_genList):
        return
    gen: BaseGenerator = _genList[idx]()
    gen.Generate()


# 是否使用多进程。
_UseMultiProcessing = True

if __name__ == "__main__":
    if _UseMultiProcessing and len(_genList) > 1:
        pPool = multiprocessing.Pool()
        pPool.map(_ProcessWork, range(len(_genList)))
    else:
        for idx in range(len(_genList)):
            _ProcessWork(idx)
