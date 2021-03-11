--[[
    Auth:       wzhengsen
    Date:       2020.03.19
    Desc:       事件机制的Event部分，和class类内部实现关联，使用相对更简洁。
]]
local Event = {
    __eventPool = {},
    __eventOrder = {},
    __eventLayer = {}
};
local isnull = sol.Null;
local ipairs = ipairs;
local setmetatable = setmetatable;
local rawget = rawget;
local rawset = rawset;


--[[
    Event设置了一个有__index元方法的元表，可以在未主动定义事件名的情况下发送事件：

    -- 发送一个名为SocketRecv的事件，携带3个参数。
    Event.SocketRecv(msg,data,otherInfo);

    -- 发送一个名为WindowClose的事件，携带1个参数。
    Event.WindowClose(true);

    另：事件响应见Handler.lua。
]]
setmetatable(Event,{
    __index = function(t,k)
        local pool = {
            enabled = true,
            objHandlers = {}
        };
        local order = {};

        t.__eventPool[k] = pool;
        t.__eventOrder[k] = order;
        t.__eventLayer[k] = 0;

        rawset(t,k,function(...)
            if not pool.enabled then
                return;
            end

            local hole = false;
            local layer = t.__eventLayer;
            local objHandlers = pool.objHandlers;

            layer[k] = layer[k] + 1;

            -- 如果当前调用层为1时，重新排列obj列表。
            if layer[k] == 1 and #order > 0 then
                local handlerLen = #objHandlers;
                for _,o in ipairs(order) do
                    for i,info in ipairs(objHandlers) do
                        if info.obj == o.obj then
                            local swapIndex = o.index < 1 and 1 or (o.index > handlerLen and handlerLen or o.index);
                            table.insert(objHandlers,swapIndex,table.remove(objHandlers,i));
                            break;
                        end
                    end
                end
                t.__eventOrder[k] = {};
            end

            for _,info in ipairs(objHandlers) do
                local obj = info.obj;
                if obj == false or isnull(obj) then
                    -- obj被销毁后，移除obj的响应；
                    -- 并指明有空洞。
                    hole = true;
                    info.obj = false;
                elseif info.enabled and not obj.__handlerDisabled and info.handler(obj,...) then
                    -- 对正在工作的obj尝试触发handler；若handler返回true，将终止向下传递。
                    break;
                end
            end

            -- 如果有空洞且当前调用层为1时，重新生成obj列表。
            if layer[k] == 1 and hole then
                local newObjHandlers = {};
                local size = 1;
                for _,info in ipairs(objHandlers) do
                    if info.obj then
                        newObjHandlers[size] = info;
                        size = size + 1;
                    end
                end
                pool.objHandlers = newObjHandlers;
            end

            layer[k] = layer[k] - 1;
        end);
        return rawget(t,k);
    end
})

_G.Event = Event;
return Event;