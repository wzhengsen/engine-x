--[[
    Auth:       wzhengsen
    Date:       2020.03.18
    Content:    一个并不是那么精确的计时器的封装。
]]
local Timer = class();
local scheduler = cc.Director.getInstance().Scheduler;

Timer.Forever = 0;

--[[
    Param:      number              间隔时间，以毫秒为单位。
                function(sender)    函数原型：
                                    Timer       计时到期的计时器。
                                    return -> nil

                number{1}           重复次数，小于等于0表示永远。
]]
function Timer:ctor(time,func,rep)
    rep = rep or 1;

    self.__curRound = 0;
    self.__time = time;
    self.__timerHandler = scheduler:scheduleScriptFunc(function(_)
        local roundOver = false;
        self.__curRound = self.__curRound + 1;
        if rep > 0 then
            if self.__curRound >= rep then
                roundOver = true;
            end
        end

        local ok = xpcall(func,function(msg)
            print(msg);
            print(debug.traceback());
        end,self);

        if not ok or roundOver then
            self:delete();
        end
    end,time / 1000,false);
end

function Timer:dtor()
    if self.__timerHandler then
        scheduler:unscheduleScriptEntry(self.__timerHandler);
        self.__timerHandler = nil;
    end
end

Timer.gtor({
    Time = function(self)
        return self.__time;
    end,
    Rep = function(self)
        return self.__curRound;
    end
});

return Timer;