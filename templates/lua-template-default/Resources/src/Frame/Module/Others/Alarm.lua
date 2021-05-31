--[[

Copyright (c) 2014-2017 Chukong Technologies Inc.
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
--[[
    Auth:       wzhengsen
    Date:       2020.03.18
    Content:    一个并不是那么精确的计时器的封装。
]]
local Alarm = class();

Alarm.Forever = 0;

--[[
    Param:      number              间隔时间，以毫秒为单位。
                function(sender)

                number{1}           重复次数，小于等于0表示永远。
]]
function Alarm:__init__(time,func,rep)
    rep = rep or 1;

    self.__curRound = 0;
    self.__time = time;
    self.__timerHandler = D.Scheduler:ScheduleScriptFunc(function(_)
        local roundOver = false;
        self.__curRound = self.__curRound + 1;
        if rep > 0 then
            if self.__curRound >= rep then
                roundOver = true;
            end
        end

        pcall(func,self);

        if roundOver and not class.IsNull(self) then
            self:delete();
        end
    end,time / 1000,false);
end

function Alarm:__del__()
    if self.__timerHandler then
        D.Scheduler:UnscheduleScriptEntry(self.__timerHandler);
        self.__timerHandler = nil;
    end
end

function Alarm.__properties__()
    return {
        r = {
            Round = function(self)
                return self.__curRound;
            end
        }
    };
end

cc.Alarm = Alarm;

return Alarm;