--[[
    File:   ILoadingScene
    Auth:   wzhengsen
    Date:   2019.07.07
    Desc:   场景的中间加载转换场景类
]]
local Sound = require("Audio.Sound")
local BaseScene = require("Base.Scene.BaseScene")
local ILoadingScene = class(BaseScene)
local Timer = require("Classes.Timer");

function ILoadingScene:__init__()
    BaseScene.__init__(self)
end

function ILoadingScene:onEnterTransitionFinish()
    self:Loading();
end

function ILoadingScene:Loading()
    if not self.toScene then
        return
    end
    local director = cc.Director.getInstance()
    local textureCache = director:getTextureCache()
    local spriteFrameCache = cc.SpriteFrameCache.getInstance()
    cc.AnimationCache:destroyInstance()
    spriteFrameCache:removeUnusedSpriteFrames()
    textureCache:removeUnusedTextures()

    local preLoadRes = self.toScene.PreloadRes;
    local preLoadTextureLen = preLoadRes.Texture and #preLoadRes.Texture or 0
    local preLoadSoundLen = preLoadRes.Sound and #preLoadRes.Sound or 0
    local preLoadResLen = preLoadTextureLen + preLoadSoundLen
    local loadedCount = 0

    for _,v in pairs(preLoadRes.Texture) do
        textureCache:addImageAsync(v,function ()
            if class.IsNull(self) then
                return
            end
            loadedCount = loadedCount + 1
            self:OnLoading(loadedCount,preLoadResLen)
            if loadedCount >= preLoadResLen then
                self:Loaded()
            end
        end)
    end

    Sound.Preload(preLoadRes.Sound,function(filePath,suc)
        if not suc then
            print((filePath or "Unkown") .. " preload failed.")
        end

        if class.IsNull(self) then
            return
        end
        loadedCount = loadedCount + 1
        self:OnLoading(loadedCount,preLoadResLen)
        if loadedCount >= preLoadResLen then
            self:Loaded()
        end
    end)

    for _,v in pairs(preLoadRes.SpriteFrame or {}) do
        spriteFrameCache:addSpriteFrames(v);
    end

    if preLoadResLen == 0 then
        self:OnLoading(1,1)
        self:Loaded()
    end
end

-- 纯虚函数，接受2个参数，分别为：当前加载索引数，总索引数。
-- 这两个参数可能都为0
ILoadingScene.OnLoading = 0

function ILoadingScene:Loaded()
    local delay = self:OnLoaded();
    if delay and delay > 0 then
        Timer.new(delay,function()
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

--[[
    Return:     number      返回要延迟的毫秒数。
    Desc:       该返回值决定了加载完成后，要延迟的毫秒数，才会进入下一个场景。
                小于等于0或返回nil表示不延迟。
]]
function ILoadingScene:OnLoaded()
    return 0;
end

--[[

]]
function ILoadingScene:Run(toScene,...)
    assert(toScene, "toScene must be non-null.");

    self.toScene = toScene;
    self.toSceneParams = {...};
    BaseScene.Run(self);
end

return ILoadingScene
