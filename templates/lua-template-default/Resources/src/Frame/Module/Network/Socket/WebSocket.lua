--[[
    Auth:       wzhengsen
    Date:       2020.07.01
    Content:    cc.WebSocket的包装：
                1、使用.new创建而不是使用.create；
                2、避免显式回调，而使用通知的形式。
]]

local WebSocket = class(cc.WebSocket);

function WebSocket:ctor()
    self:registerScriptHandler(function()
        if not self:OnOpen() then
            Event.WebSocketOpen(self);
        end
    end,ScriptHandlerMgr.HandlerType.WEBSOCKET_OPEN);

    self:registerScriptHandler(function(data)
        if not self:OnMessage(data) then
            Event.WebSocketMessage(self,data);
        end
    end,ScriptHandlerMgr.HandlerType.WEBSOCKET_MESSAGE);

    self:registerScriptHandler(function()
        if not self:OnClose() then
            Event.WebSocketClose(self);
        end
    end,ScriptHandlerMgr.HandlerType.WEBSOCKET_CLOSE);

    self:registerScriptHandler(function(errorCode)
        if not self:OnError(errorCode) then
            Event.WebSocketError(self,errorCode);
        end
    end,ScriptHandlerMgr.HandlerType.WEBSOCKET_ERROR);
end

WebSocket.Send = WebSocket.sendString;
WebSocket.Close = WebSocket.close;

function WebSocket:OnOpen()
end

function WebSocket:OnMessage(data)
end

function WebSocket:OnClose()
end

function WebSocket:OnError(errorCode)
end

WebSocket.gtor({
    Url = function(self)
        return self.url;
    end,
    Protocol = function(self)
        return self.protocol;
    end,
    ReadyState = WebSocket.getReadyState,
    State = WebSocket.getReadyState
});

return WebSocket;