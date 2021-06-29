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

local type = type;
local pb = require("pb");
local cjson = require("cjson");
local config = require("config");

---带有协议解析和消息分发的服务器连接。
-- SocketConnect   接受连接事件，带有4个参数：
--                 sender      cc.Server
--                 transport   传输会话。
--                 ip          对方ip。
--                 port        对方端口。

-- SocketLose      连接丢失事件，带有2个参数：
--                 sender      cc.Server
--                 transport   传输会话。

-- SocketMessage   接受事件，带有4个参数：
--                 sender      cc.Server
--                 transport   传输会话。
--                 msgName     消息名。
--                 body        消息体。
local Server = cc.Server;
Server.ProtocolType = config.ProtocolType:lower()

function Server:OnConnect(_,_,_) return true;end
function Server:OnMessage(_,_,_) return true;end
function Server:OnLose(_) return true;end

function Server:ctor()
    self.HeartBeat = config.SocketHeartBeat;
    self.ConnectHandler = function (sender,transport,_,ip,port)
        -- sokect连接事件。
        if not sender:OnConnect(transport,ip,port) then
            event.SocketConnect(sender,transport,ip,port);
        end
    end;
    self.MessageHandler = function(sender,transport,msg)
        -- sokect收到消息事件。
        local msgName,body = nil,nil;
        if self.ProtocolType == "json" then
            body = cjson.decode(msg)
            if type(body) ~= "table" then return warn("无法解析的消息。");end
            msgName = body.msgName;
            body.msgName = nil;
        elseif self.ProtocolType == "lua-protobuf" then
            local offset = msg:find("\0");
            if nil == offset then return warn("无法解析的消息。");end
            msgName = msg:sub(1,offset - 1);
            local ret = msg:sub(offset + 1);
            ret,body = pcall(pb.decode,msgName,ret);
            if not ret then return warn("无法解析的消息。-" .. (msgName or ""));end
        else
            return;
        end
        if not self:OnMessage(transport,msgName,body) then
            Event.SocketMessage(sender,transport,msgName,body);
        end
    end;
    self.LoseHandler = function (sender,transport)
        -- sokect连接丢失事件。
        if not sender:OnLose(transport) then
            event.SocketLose(sender,transport);
        end
    end;
end

---向指定的传输会话或所有传输会话发送消息。
---@overload fun(msgName:string,data:table)
---@param transport userdata
---@param msgName string
---@param data table
function Server:Send(transport,msgName,data)
    local toAll = "string" == type(transport);
    if toAll then
        data = msgName or {};
        msgName = transport;
        transport = nil;
    else
        data = data or {};
    end
    if Server.ProtocolType == "json" then
        data.msgName = msgName
        local sendStr = cjson.encode(data);
        if sendStr then
            return toAll and self:Write(sendStr) or self:Write(transport,sendStr);
        end
    elseif Server.ProtocolType == "lua-protobuf" then
        local ok,sendStr = pcall(pb.encode,msgName,data)
        if ok then
            return toAll and self:Write(msgName.."\0"..sendStr) or self:Write(transport,msgName.."\0"..sendStr);
        end
    end
    warn("无法序列化的消息。-" .. (msgName or ""));
end