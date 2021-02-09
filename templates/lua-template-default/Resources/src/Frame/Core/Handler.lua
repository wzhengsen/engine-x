--[[
    Auth:       wzhengsen
    Date:       2020.03.19
    Desc:       事件机制的Handler部分，和class类内部实现关联，使用相对更简洁。
]]
local Event = require("Event");
local Handler = {};

--[[
    Desc:       令一个实例对象响应某事件名。
                其中，handler的第一个参数，一定会被置为该obj。

                另一个通常的监听响应的方式为：
                -- 即监听SocketRecv事件名。
                function someclass.Handler:OnSocketRecv(msg,data)
                    print(msg .. "&" .. data); -- abc&123
                end

                -- 事件通知调用：
                Event.SocketRecv("abc",123)

    Param:      string      事件名。
                obj         对象。
                handler     响应函数。
]]
function Handler.On(eventName,obj,handler)
    -- 检查并定义事件名。
    local _ = Event[eventName];
    table.insert(Event.__eventPool[eventName].objHandlers,{
        obj = obj,
        enabled = true,
        handler = handler
    });
end

function Handler.Order(eventName,obj,index)
    -- 检查并定义事件名。
    local _ = Event[eventName];
    table.insert(Event.__eventOrder[eventName],{
        obj = obj,
        index = index
    });
end

--[[
    Desc:       停用某实例响应某事件。
    Param:      string      事件名。
                obj         实例。
]]
function Handler.Disable(eventName,obj)
    if "string" == type(eventName) then
        -- 检查并定义事件名。
        local _ = Event[eventName];
        if obj then
            local objHandlers = Event.__eventPool[eventName].objHandlers;
            for _,info in ipairs(objHandlers) do
                if info.obj == obj then
                    info.enabled = false;
                    break;
                end
            end
        else
            Event.__eventPool[eventName].enabled = false;
        end
    else
        eventName.__handlerDisabled = true;
    end
end

--[[
    Desc:       使某实例响应某事件可用。
    Param:      string      事件名。
                obj         实例。
]]
function Handler.Enable(eventName,obj)
    if "string" == type(eventName) then
        -- 检查并定义事件名。
        local _ = Event[eventName];
        if obj then
            local objHandlers = Event.__eventPool[eventName].objHandlers;
            for _,info in ipairs(objHandlers) do
                if info.obj == obj then
                    info.enabled = true;
                    break;
                end
            end
        else
            Event.__eventPool[eventName].enabled = true;
        end
    else
        eventName.__handlerDisabled = nil;
    end
end

--[[
    Desc:       移除某实例响应某事件。
    Param:      string      事件名。
                obj         实例。
]]
function Handler.Remove(eventName,obj)
    -- 检查并定义事件名。
    local _ = Event[eventName];
    local objHandlers = Event.__eventPool[eventName].objHandlers;
    for _,info in ipairs(objHandlers) do
        if info.obj == obj then
            -- 并非在此移除，将在Event事件循环中检查移除。
            info.obj = false;
            break;
        end
    end
end

_G.Handler = Handler;
return Handler;