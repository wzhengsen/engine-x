--[[
    File:   FSM
    Func:   有限状态机
    Auth:   wzhengsen
    Data:   2019.05.01
    Desc:   该状态机不是自动机，不依靠内部循环驱动，使用外部事件驱动
]]
local FSM = class()
local InitState = require("FSM.InitState")

function FSM:ctor(initState)
    --nil状态标识初始状态,默认使用InitState
    initState = initState or InitState

    --持有当前状态类的实例
    self.__curInst = nil;
    self.__curState = nil;
    self:SetState(initState);
end

--[[
    Desc:   设置Enter参数。
]]
function FSM:SetEnterParam(p)
    self.__fsmEnterParam = p;
end

--[[
    Desc:   设置Exit参数。
]]
function FSM:SetExitParam(p)
    self.__fsmExitParam = p;
end

--[[
    Func:   设置当前状态
    Param:  IState  类，而非实例
            ...
    Return: IState  实例，返回nil表示无法转换状态
]]
function FSM:SetState(state,...)
    if self.__curState == state then
        return nil;
    end
    --记录上一个状态类
    local prevInst = self:GetStateInstance()
    self.__prevInst = prevInst;

    local bPrevInst = not class.IsNull(prevInst);
    if bPrevInst then
        local ret = prevInst:OnStateCheck(state,...)
        if not ret then
            self.__fsmEnterParam = nil;
            self.__fsmExitParam = nil;
            return nil
        end
    end

    local nextInst = state.new(...);
    self.__nextInst = nextInst;
    self.__curInst = nextInst;
    self.__curState = state;

    nextInst.FSM = self;
    nextInst:OnStateEnter(self.__fsmEnterParam);

    self:OnStateTransform(nextInst,prevInst);

    self.__fsmEnterParam = nil;
    self.__prevInst = nil;

    if bPrevInst then
        prevInst:OnStateExit(self.__fsmExitParam);
        prevInst.FSM = nil;
    end
    self.__fsmExitParam = nil;
    self.__nextInst = nil;

    return nextInst;
end

function FSM:OnStateTransform(cur)
end


function FSM:GetState()
    return self.__curState;
end

function FSM:GetStateInstance()
    return self.__curInst
end

FSM.gtor({
    State = FSM.GetState,
    StateInstance = FSM.GetStateInstance,
    PrevInstance = function(self)
        return self.__prevInst;
    end,
    NextInstance = function(self)
        return self.__nextInst;
    end,
});

FSM.stor({
    EnterParam = FSM.SetEnterParam,
    ExitParam = FSM.SetExitParam
});

return FSM