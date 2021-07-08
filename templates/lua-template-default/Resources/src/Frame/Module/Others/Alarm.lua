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

---一个并不是那么精确的计时器的封装。
local Alarm = class();

Alarm.static.Forever = 0;
Alarm.protected.curRound = 0;
Alarm.protected.time = nil;
Alarm.private.uniStr = nil;

---@param time number 间隔时间，以毫秒为单位。
---@param func function
---@param rep integer {1}重复次数，小于等于0表示永远。
function Alarm:ctor(time,func,rep)
    rep = rep or 1;

    self.time = time;
    self.uniStr = string.unique();
    D.Scheduler:Schedule(function(_)
        local roundOver = false;
        self.curRound = self.curRound + 1;
        if rep > 0 then
            if self.curRound >= rep then
                roundOver = true;
            end
        end

        pcall(func,self);

        if roundOver and not class.IsNull(self) then
            self:delete();
        end
    end,D,time / 1000,false,self.uniStr);
end

function Alarm:dtor()
    if self.uniStr then
        D.Scheduler:Unschedule(self.uniStr,D);
        self.uniStr = nil;
    end
end
function Alarm.get:Round()
    return self.curRound;
end

cc.Alarm = Alarm;
return Alarm;