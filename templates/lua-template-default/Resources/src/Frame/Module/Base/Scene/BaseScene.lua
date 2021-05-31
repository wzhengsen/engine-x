--[[
    File:   场景基类
    Auth:   wzhengsen
    Date:   2019.07.07
]]
local Sound = require("Audio.Sound");
local BaseScene = class(function()
    return cc.Scene.new();
end)

BaseScene.PreloadRes = {
    Sound = {},
    Animation = {},
    SpriteFrame = {},
    Texture = {},
}

function BaseScene:__init__()
    self.EnableEvents = true;
    self.EnableDelEvent = true;
end

function BaseScene:Run()
    if class.IsNull(D.RunningScene) then
        D.RunWithScene(self)
    else
        D.ReplaceScene(self)
    end
end

function BaseScene:__del__()
    for _,v in pairs(self.PreloadRes.Sound or {}) do
        Sound.Uncache(v)
    end
end

function BaseScene.Handler:OnDeviceToPortrait()
    self.Size = D.OpenGLView.FrameSize;
    self:Layout();
end

function BaseScene.Handler:OnDeviceToLandscape()
    self.Size = D.OpenGLView.FrameSize;
    self:Layout();
end

return BaseScene;