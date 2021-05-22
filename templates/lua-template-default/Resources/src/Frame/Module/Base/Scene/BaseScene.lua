--[[
    File:   场景基类
    Auth:   wzhengsen
    Date:   2019.07.07
]]
local Sound = require("Audio.Sound")
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
    self:enableNodeEvents()
    self:EnableRefEvents()
end

function BaseScene:Run()
    local director = cc.Director.getInstance();
    if class.IsNull(director:getRunningScene()) then
        director:runWithScene(self)
    else
        director:replaceScene(self)
    end
end

function BaseScene:__del__()
    for _,v in pairs(self.PreloadRes.Sound or {}) do
        Sound.Uncache(v)
    end
end

function BaseScene.Handler:OnDeviceToPortrait()
    local glView = cc.Director.getInstance().OpenGLView;
    self.Size = glView.FrameSize;
    self:Layout();
end

function BaseScene.Handler:OnDeviceToLandscape()
    local glView = cc.Director.getInstance().OpenGLView;
    self.Size = glView.FrameSize;
    self:Layout();
end

return BaseScene