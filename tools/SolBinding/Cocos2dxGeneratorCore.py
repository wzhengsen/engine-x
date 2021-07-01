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


class Cocos2dxGeneratorCore(Cocos2dxGenerator):
    def __init__(self, **args):
        super().__init__(**args)
        self.TargetNamespace = "cc"
        # 尽量确保嵌套层数较深的命名空间位于列表前端。
        self.CppNameSpace += ["cocos2d", "cocos2d::network"]
        self.Headers += [
            "{}/cocos/cocos2d.h".format(self.CocosRoot),
            "{}/cocos/2d/CCProtectedNode.h".format(self.CocosRoot),
            "{}/cocos/base/CCAsyncTaskPool.h".format(self.CocosRoot),
            "{}/cocos/renderer/CCRenderer.h".format(self.CocosRoot),
            "{}/cocos/renderer/CCPipelineDescriptor.h".format(self.CocosRoot),
            "{}/cocos/renderer/backend/RenderTarget.h".format(self.CocosRoot),
            "{}/cocos/navmesh/CCNavMesh.h".format(self.CocosRoot),
            "{}/cocos/ui/UIWidget.h".format(self.CocosRoot),
            "{}/cocos/base/TGAlib.h".format(self.CocosRoot)
        ]
        self.ExtraArgs += [
            "-I{}/cocos/platform/android".format(self.CocosRoot),
            "-I{}/thirdparty".format(self.CocosRoot),
            "-I{}/thirdparty/openssl/include/android".format(self.CocosRoot)
        ]
        self.Classes += [
            "New.*", "Sprite((?!3D).)*", "Scene", "Node.*", "Director", "Layer.*", "Menu.*", "Touch", ".*Action.*", "Move.*",
            "Rotate.*", "Blink.*", "Tint.*", "Sequence", "Repeat.*", "Fade.*", "Ease.*", "Scale.*", "Transition.*", "Spawn",
            "Animat((?!3D).)*", "Flip.*", "Delay.*", "Skew.*", "Jump.*", "Place.*", "Show.*", "Progress.*", "PointArray", "ToggleVisibility.*",
            "RemoveSelf", "Hide", "Particle.*", "Label.*", "Atlas.*", "TextureCache.*", "Texture2D", "Cardinal.*", "CatmullRom.*", "ParallaxNode",
            "TileMap.*", ".*TMX.*", "CallFunc", "RenderTexture", "GridAction", "Grid3DAction", "GridBase$", ".+Grid", "Shaky3D", "Waves3D",
            "FlipX3D", "FlipY3D", "Speed", "ActionManager", "Set", "Scheduler", "Timer", "Orbit.*", "Follow.*", "Bezier.*",
            "CardinalSpline.*", "Camera.*", "DrawNode", "Liquid$", "Waves$", "ShuffleTiles$", "TurnOffTiles$", "Split.*", "Twirl$", "FileUtils$",
            "GLProgram", "Application.*", "ClippingNode", "MotionStreak", "^Ref$", "UserDefault", "GLViewImpl", "GLView", "Image", "Event(?!.*(Physics).*).*",
            "Component", "ProtectedNode", "GLProgramCache", "GLProgramState", "Device", "ClippingRectangleNode", ".*Light$", "AsyncTaskPool.*", "RenderState",
            "Material", "Properties", "Technique", "Pass", "PolygonInfo", "AutoPolygon", "BoneNode", "SkeletonNode", "ComponentLua", "PipelineDescriptor",
            "Renderer", "FastTMXLayer", "FastTMXTiledMap", "LanguageType", "PHYSICS.*_MATERIAL_DEFAULT", "GlyphCollection", "MATRIX_STACK_TYPE", "LightType", "LightFlag", "Image::Format",
            "Text(H|V)Alignment", "ResolutionPolicy", "Lens3D", "Ripple3D", "WavesTiles3D", "JumpTiles3D", "Grid3D", ".*ZipFile", "RZipFile::ZipItem", "Touch::DispatchMode",
            "RZipFile::Encoding", "Clonable", "Connection", "Server", "Client", "Connection::Kind", "Crypto", "Crypto::.*"
        ]
        self.Skip |= {
            "TMXMapInfo": ["startElement", "endElement"],
            "Application": ["^application.*", "Notify", "Dialog"],
            "Device": ["getTextureDataForText"],
            "RenderTexture": ["newImage"],
            "ParallaxNode": ["(s|g)etParallaxArray"],
            "TMXTilesetInfo": ["_animationInfo"],
            "AsyncTaskPool": ["enqueue"],
            "RZipFile::ZipItem": ["Read"],
            "RZipFile": ["begin", "end"],
            "Node": ["onEnter.*", "onExit.*", "_setLocalZOrder"],
            "Component": ["onEnter", "onExit", "onAdd", "onRemove"]
        }
        self.RenameMembers |= {
            "SpriteFrameCache": {"addSpriteFramesWithFile": "addSpriteFrames", "getSpriteFrameByName": "getSpriteFrame"},
            "ProgressTimer": {"setReverseProgress": "setReverseDirection"},
            "AnimationCache": {"addAnimationsWithFile": "addAnimations"},
            "GLProgram": {"setUniformLocationWith1i": "setUniformLocationI32"},
            "Touch": {"getID": "getId"},
            "FileUtils": {"loadFilenameLookupDictionaryFromFile": "loadFilenameLookup"}
        }
        if not self.UpperCamelCase:
            self.RenameMembers |= {
                "Director": {"end": "endToLua"},
                "GLView": {"end": "endToLua"},
                "RenderTexture": {"end": "endToLua"}
            }
            self.RenameClasses |= {
                "TMXTileFlags_": "TMXTileFlags"
            }
