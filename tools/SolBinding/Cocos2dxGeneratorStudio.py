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


class Cocos2dxGeneratorStudio(Cocos2dxGenerator):
    def __init__(self):
        super().__init__()
        self.TargetNamespace = "ccs"
        # 尽量确保嵌套层数较深的命名空间位于列表前端。
        self.CppNameSpace += ["cocostudio::timeline", "cocostudio"]
        self.Headers += [
            "{}/extensions/cocostudio/CocoStudio.h".format(self.CocosRoot),
            "{}/extensions/cocostudio/CCComExtensionData.h".format(self.CocosRoot)
        ]
        self.ExtraArgs += [
            "-I{}/cocos/platform/android".format(self.CocosRoot),
            "-I{}/external".format(self.CocosRoot),
            "-I{}/extensions/cocostudio".format(self.CocosRoot)
        ]
        self.Classes += [
            "Armature", "ArmatureAnimation", "Skin", "Bone", "ArmatureDataManager", "\w+Data$", "ActionManagerEx", "ComAudio", "ComController", "ComAttribute",
            "ComRender", "BatchNode", "SceneReader", "GUIReader", "ActionObject", "Tween", "DisplayManager", "NodeReader", "ActionTimeline.*", ".*Frame$",
            "Timeline", "ActionTimelineNode", "ComExtensionData", "BoneNode", "SkeletonNode"
        ]
        self.Skip.update({
            "GUIReader": ["getParseCallBackMap", "getParseObjectMap"],
            "BoneData": ["displayDataList"],
            "ArmatureData": ["boneDataDic"],
            "MovementBoneData": ["frameList"],
            "SkeletonNode": ["getAllSubBonesMap"],
            "AnimationData": ["movementDataDic"],
            "TextureData": ["contourDataList"],
            "MovementData": ["movBoneDataDic"]
        })
        self.RenameMembers.update({
            "ActionManagerEx": {
                "shareManager": "getInstance",
                "purgeActionManager": "destroyInstance"
            },
            "SceneReader": {
                "purgeSceneReader": "destroyInstance"
            },
            "ComAudio": {
                "end": "endToLua"
            }
        })
