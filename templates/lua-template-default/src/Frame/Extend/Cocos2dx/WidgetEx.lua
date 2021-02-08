--[[
    Auth:   wzhengsen
    Data:   2020.04.18
    Desc:   Widget一些补充的封装方法。
]]
local config = require("config");
local Widget = ccui.Widget;
local Effect = require("Audio.Effect");

Widget.stor({
    ClickHandler = function(self,handler)
        self:addClickEventListener(function(sender)
            if config.DefaultClick then
                -- 为了适应快速点击仍然能够播放，每次创建新的Effect，而不是反复播放同一个。
                Effect.new(config.DefaultClick):Play();
            end
            if handler then
                handler(sender);
            end
        end);
    end
});