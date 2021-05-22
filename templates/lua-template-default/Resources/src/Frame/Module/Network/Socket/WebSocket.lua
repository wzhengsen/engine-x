--[[
    Auth:       wzhengsen
    Date:       2020.07.01
    Content:    cc.WebSocket的包装：
                1、使用.new创建而不是使用.create；
                2、避免显式回调，而使用通知的形式。

    Chg By:     wzhengsen
    Date:       2021.03.17
    Content:    重构cc.WebSocket，使用sol绑定。
]]

local WebSocket = class(cc.WebSocket);

function WebSocket:__init__()
    self.OpenHandler = function (sender)
        if not sender:OnOpen() then
            Event.WebSocketOpen(sender);
        end
    end;
    self.MessageHandler = function (sender,data,isBin)
        if not sender:OnMessage(data,isBin) then
            Event.WebSocketMessage(sender,data,isBin);
        end
    end;
    self.CloseHandler = function (sender)
        if not sender:OnClose() then
            Event.WebSocketClose(sender);
        end
    end;
    self.ErrorHandler = function (sender,err)
        if not sender:OnError(err) then
            Event.WebSocketError(sender,err);
        end
    end;
end

function WebSocket:OnOpen()
end

function WebSocket:OnMessage(data,isBin)
end

function WebSocket:OnClose()
end

function WebSocket:OnError(errorCode)
end

return WebSocket;