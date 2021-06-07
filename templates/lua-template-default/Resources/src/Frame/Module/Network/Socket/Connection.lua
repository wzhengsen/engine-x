--[[
    File:   Connection
    Desc:   Cocos2dx的lua封装，自动开始和结束Poll
]]
local config = require("config");
local Connection = require("StarryX::Connection");
local Timer = require("Others.Alarm");

Connection.ObjectTable = {};

local _CloseMGR = Connection.CloseMGR;
function Connection.CloseMGR()
    -- 关闭MGR时删除全部连接
    for obj,_ in pairs(Connection.ObjectTable) do
        obj:delete();
    end
    if not class.IsNull(Connection.PollTimer) then
        Connection.PollTimer:delete();
    end
    _CloseMGR();
end

local _delete = Connection.delete
function Connection:delete()
    Connection.ObjectTable[self] = nil;
    if self._delayTimer then
        for _,timer in pairs(self._delayTimer) do
            if not class.IsNull(timer) then
                timer:delete();
            end
        end
    end
    if not next(Connection.ObjectTable) and not class.IsNull(Connection.PollTimer) then
        Connection.PollTimer:delete();
    end
    _delete(self);
end

function Connection.Init()
    if next(Connection.ObjectTable) then
        return;
    end
    Connection.PollTimer = Timer.new(
        config.PollTime,
        function()
            Connection.Poll();
        end,
        Timer.Forever
    );
end

function Connection:OnClose()
end

function Connection:OnRecv()
end

function Connection:OnConnect()
end

function Connection:OnAccept()
end

function Connection:Delay(time,func,rep)
    self._delayTimer = self._delayTimer or {};
    rep = rep or 1;
    local timer = Timer.new(time,function(sender)
        if rep > 0 and sender.Rep >= rep then
            self._delayTimer[sender] = nil;
        end
        if func then
            func(sender);
        end
    end,rep);
    self._delayTimer[timer] = timer;
    return timer;
end

return Connection