--[[
Copyright (c) 2021 wzhengsen.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
]]

local Sound = require("Audio.Sound");
local BaseScene = require("Base.Scene.BaseScene");
---场景的中间加载转换场景类。
local ILoadingScene = class(BaseScene);

ILoadingScene.protected.toScene = nil;
ILoadingScene.protected.toSceneParams = nil;
function ILoadingScene:OnEnterTransitionDidFinish()
    self:Loading();
end

function ILoadingScene:Loading()
    local textureCache = D.TextureCache;
    local spriteFrameCache = cc.SpriteFrameCache.Instance;
    cc.AnimationCache.Instance = nil;
    spriteFrameCache:RemoveUnusedSpriteFrames();
    textureCache:RemoveUnusedTextures();

    local preLoadRes = self.toScene.PreloadRes;
    local preLoadTextureLen = preLoadRes.Texture and #preLoadRes.Texture or 0;
    local preLoadSoundLen = preLoadRes.Sound and #preLoadRes.Sound or 0;
    local preLoadResLen = preLoadTextureLen + preLoadSoundLen;
    local loadedCount = 0;

    for _,v in pairs(preLoadRes.Texture) do
        textureCache:AddImageAsync(v,function ()
            if class.IsNull(self) then
                return;
            end
            loadedCount = loadedCount + 1;
            self:OnLoading(loadedCount,preLoadResLen);
            if loadedCount == preLoadResLen then
                self:Loaded();
            end
        end)
    end

    Sound.Preload(preLoadRes.Sound,function(filePath,suc)
        if not suc then
            print((filePath or "Unkown") .. " preload failed.");
        end

        if class.IsNull(self) then
            return;
        end
        loadedCount = loadedCount + 1;
        self:OnLoading(loadedCount,preLoadResLen);
        if loadedCount == preLoadResLen then
            self:Loaded();
        end
    end)

    for _,v in pairs(preLoadRes.SpriteFrame or {}) do
        spriteFrameCache:AddSpriteFrames(v);
    end

    if preLoadResLen == 0 then
        self:OnLoading(1,1)
        self:Loaded()
    end
end

-- 纯虚函数，接受2个参数，分别为：当前加载索引数，总索引数。
ILoadingScene.virtual.OnLoading = 0;

--[[
    Return:     number      返回要延迟的毫秒数。
    Desc:       该返回值决定了加载完成后，要延迟的毫秒数，才会进入下一个场景。
                小于等于0或返回nil表示不延迟。
]]
function ILoadingScene:OnLoaded()
    return 0;
end

function ILoadingScene:Loaded()
    local delay = self:OnLoaded() or 0;
    if delay > 0 then
        cc.Alarm.new(delay,function()
            if class.IsNull(self) then
                return;
            end
            local scene = self.toScene.new(table.unpack(self.toSceneParams));
            scene:Run();
        end);
    else
        local scene = self.toScene.new(table.unpack(self.toSceneParams));
        scene:Run();
    end
end

function ILoadingScene:Run(toScene,...)
    assert(toScene, "toScene must be non-null.");

    self.toScene = toScene;
    self.toSceneParams = {...};
    BaseScene.Run(self);
end
cc.ILoadingScene = ILoadingScene;
return ILoadingScene;
