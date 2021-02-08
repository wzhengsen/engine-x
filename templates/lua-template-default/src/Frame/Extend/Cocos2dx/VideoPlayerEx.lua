--[[
    Auth:   wzhengsen
    Data:   2020.09.14
    Desc:   VideoPlayer监听回到前台后台事件，以暂停或继续。
]]
local VideoPlayer = class(ccui.VideoPlayer);
ccui.VideoPlayer = VideoPlayer;

function VideoPlayer.Handler:OnAppEnterForeground()
    if self._pauseOnBackground then
        self._pauseOnBackground = nil;
        self:Resume();
    end
end

function VideoPlayer.Handler:OnAppEnterBackground()
    if self.Playing then
        self:Pause();
        self._pauseOnBackground = true;
    end
end

if os.IsLinux() then
    function VideoPlayer.Handler:OnKeyDown(key)
        if key == cc.EventKeyboard.KeyCode.KEY_ENTER and self.UserInputEnabled then
            if self.Playing then
                self:Pause();
            else
                self:Resume();
            end
        end
    end
end

return VideoPlayer;