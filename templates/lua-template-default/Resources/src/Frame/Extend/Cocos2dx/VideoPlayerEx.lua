-- Copyright (c) 2021 wzhengsen

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:

-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.

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
        self:Recover();
    end
end

function VideoPlayer.Handler:OnAppEnterBackground()
    if self.Playing then
        self:Suspend();
        self._pauseOnBackground = true;
    end
end

if os.Linux then
    function VideoPlayer.Handler:OnKeyDown(key)
        if key == cc.EventKeyboard.KeyCode.KEY_ENTER and self.UserInputEnabled then
            if self.Playing then
                self:Suspend();
            else
                self:Recover();
            end
        end
    end
end

return VideoPlayer;