--[[
    File:   ILoadingScene
    Auth:   wzhengsen
    Date:   2019.07.07
    Desc:   场景的中间加载转换场景类
]]
local Sound = require("Audio.Sound");
local BaseScene = require("Base.Scene.BaseScene");
local ILoadingScene = class(BaseScene);

function ILoadingScene:OnEnterTransitionDidFinish()
    self:Loading();
end

function ILoadingScene:Loading()
    local textureCache = D.TextureCache;
    local spriteFrameCache = cc.SpriteFrameCache.Instance;
    cc.AnimationCache.Instance = nil;
    spriteFrameCache:RemoveUnusedSpriteFrames();
    textureCache:RemoveUnusedTextures();

    local preLoadRes = self._toScene.PreloadRes;
    local preLoadTextureLen = preLoadRes.Texture and #preLoadRes.Texture or 0
    local preLoadSoundLen = preLoadRes.Sound and #preLoadRes.Sound or 0
    local preLoadResLen = preLoadTextureLen + preLoadSoundLen
    local loadedCount = 0

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
ILoadingScene.OnLoading = 0;

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
            local scene = self._toScene.new(table.unpack(self._toSceneParams));
            scene:Run();
        end);
    else
        local scene = self._toScene.new(table.unpack(self._toSceneParams));
        scene:Run();
    end
end

function ILoadingScene:Run(toScene,...)
    assert(toScene, "toScene must be non-null.");

    self._toScene = toScene;
    self._toSceneParams = {...};
    BaseScene.Run(self);
end

return ILoadingScene;
