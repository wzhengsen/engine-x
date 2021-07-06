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

local WebSocket = cc.WebSocket;
function WebSocket:OnOpen()end
function WebSocket:OnMessage(_,_)end
function WebSocket:OnClose()end
function WebSocket:OnError(_)end

function WebSocket:ctor()
    self.OpenHandler = WebSocket.OnOpenHandler;
    self.MessageHandler = WebSocket.OnMessageHandler;
    self.CloseHandler = WebSocket.OnCloseHandler;
    self.ErrorHandler = WebSocket.OnErrorHandler;
end

function WebSocket.private:OnOpenHandler()
    if not self:OnOpen() then
        event.WebSocketOpen(self);
    end
end

function WebSocket.private:OnMessageHandler(data,isBin)
    if not self:OnMessage(data,isBin) then
        event.WebSocketMessage(self,data,isBin);
    end
end

function WebSocket.private:OnCloseHandler()
    if not self:OnClose() then
        event.WebSocketClose(self);
    end
end

function WebSocket.private:OnErrorHandler(err)
    if not self:OnError() then
        event.WebSocketError(self,err);
    end
end