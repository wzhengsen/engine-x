--[[
    File:   ExtRef
    Func:   Ref一些补充的封装方法，依赖于cocos源码的更改
    Auth:   wzhengsen
    Data:   2019.07.07
]]
local Ref = cc.Ref;

function Ref:EnableRefEvents()
    local scriptHandlerMgr = ScriptHandlerMgr.getInstance();
    scriptHandlerMgr:registerScriptHandler(self,function(state)
        if state == "dtor" then
            self:dtor();
        end
    end,ScriptHandlerMgr.HandlerType.REF);
end

function Ref:DisableNodeEvents()
    local scriptHandlerMgr = ScriptHandlerMgr.getInstance();
    scriptHandlerMgr:unregisterScriptHandler(self,ScriptHandlerMgr.HandlerType.REF);
end

function Ref:dtor()
end