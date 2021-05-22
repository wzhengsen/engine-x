--[[
    File:   IState
    Func:   有限状态机的状态接口
    Auth:   wzhengsen
    Data:   2019.05.01
]]
local IState = class()
IState.__init__ = nil

--[[
    Func:   进入状态
    Param:  value     上一个状态。
]]
function IState:OnStateEnter(preInst)
end

--[[
    Func:   离开状态
    Param:  value     下一个状态。
]]
function IState:OnStateExit(nextInst)
end

--[[
    Func:   检查状态转换
    Param:  下一个状态（该状态指示为类，而非实例）
            参数
    Return: boolean
    Desc:   不能通过检查的，则状态无法转换。
]]
function IState:OnStateCheck(to,...)
    return not self.__stateLock and to:is(IState);
end

IState.gtor({
    --[[
        Func:   获取该状态实例的状态机
        Return: FSM
    ]]
    FSM = function(self)
        return self.__fsm;
    end,
    StateLock = function(self)
        return self.__stateLock;
    end
});

IState.stor({
    --[[
        Func:   设置该状态实例的状态机
        Param:  FSM
    ]]
    FSM = function(self,val)
        self.__fsm = val;
    end,
    --[[
        Desc:   是否锁定该状态，使其无论如何也不能被切换。
    ]]
    StateLock = function(self,val)
        self.__stateLock = val;
    end
});

return IState