--[[
    File:   DeadState
    Func:   有限状态机的默认终结状态
    Auth:   wzhengsen
    Data:   2019.05.01
]]
local IState = require("FSM.IState")
local DeadState = class(IState)

--[[
    Func:   检查状态转换
    Param:  下一个状态（该状态指示为类，而非实例）
            ...
    Return: boolean
]]
function DeadState:OnStateCheck(to,...)
    --终结状态无法转换到其它状态
    return false
end

return DeadState