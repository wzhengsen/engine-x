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

local IState = class();
IState.protected.fsm = nil;
--锁定状态，令其无论如何也不能转换。
IState.StateLock = false;
function IState.protected.ctor()end
function IState:OnStateEnter(preInst)end
function IState:OnStateExit(nextInst)end
function IState.get:FSM()return self.fsm;end
function IState.set:FSM(val)self.fsm = val;end

---检查状态转换。
---@param to table 希望转换到的状态类型。
---@vararg any 任意参数。
---@return boolean
function IState:OnCheckStateTransfer(to,...)
    return not self.StateLock and to.is(IState);
end

--初始状态。
--只要初始状态不被锁定，那么即可转换到任意状态。
--与IState唯一不同的是InitState可以实例化。
local InitState = class(IState);

--消亡状态。
--消亡状态不能向任意状态转换。
local DoomState = class(IState);
function DoomState:OnCheckStateTransfer()return false;end


local FSM = class("cc.FSM");
-- 持有当前状态类的实例
FSM.protected.fsmCurStateInst = nil;
function FSM:ctor(initState)
    --nil状态标识初始状态,默认使用InitState
    initState = initState or InitState;
    self:Transfer(initState);
end

function FSM:OnStateTransfer(next,prev)end

---命令当前状态机转移到另一个状态。
---@param state table 状态类，而非状态实例。
---@vararg any 任意参数。
---@return any  转移后的状态实例，返回nil表示无法转换。
function FSM:StateTransfer(state,...)
    local prevInst = self.fsmCurStateInst;

    local bPrevInst = not class.IsNull(prevInst);
    if bPrevInst then
        if not prevInst:OnCheckStateTransfer(state,...) then
            -- 上一个状态拒绝转换。
            return nil;
        end
    else
        -- 状态已销毁。
        self.fsmCurStateInst = nil;
        prevInst = nil;
    end

    local nextInst = state.new(...);
    self.fsmCurStateInst = nextInst;
    nextInst.FSM = self;
    nextInst:OnStateEnter();

    self:OnStateTransfer(nextInst,prevInst);

    if bPrevInst then
        prevInst:OnStateExit();
        prevInst.FSM = nil;
    end

    return nextInst;
end

function FSM.get:FSM_StateInstance()
    return self.fsmCurStateInst
end

cc.FSM = FSM;
FSM.static.IState = IState;
FSM.static.InitState = InitState;
FSM.static.DoomState = DoomState;
return FSM;