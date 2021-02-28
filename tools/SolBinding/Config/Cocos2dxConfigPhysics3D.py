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

from .Cocos2dxConfig import Cocos2dxConfig


class Cocos2dxConfigPhysics3D(Cocos2dxConfig):
    def __init__(self):
        super().__init__()
        self.TargetNamespace = "cc"
        # 尽量确保嵌套层数较深的命名空间位于列表前端。
        self.CppNamespace |= ["cocos2d"]
        self.MacroJudgement = "#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION"
        self.Headers |= [
            "{}/cocos/physics3d/CCPhysics3D.h".format(self.CocosRoot)
        ]
        self.Classes |= [
            "Physics3DWorld", "Physics3DShape", "PhysicsSprite3D", "Physics3DObject", "Physics3DRigidBody", "Physics3DShapesk", "Physics3DComponent", "Physics3DConstraint", "Physics3DPointToPointConstraint", "Physics3DHingeConstraint",
            "Physics3DSliderConstraint", "Physics3DConeTwistConstraint", "Physics3D6DofConstraint"
        ]
