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
local pcall = pcall;
local warn = warn;
local config = require("config");
local pb = require("pb");
local cjson = require("cjson");

---带有协议解析和消息分发的客户端连接。
-- 该类会向外通知如下3种事件：
-- SocketConnect   连接事件，带有2个参数：
--                 sender      cc.Client
--                 suc         表示是否成功。

-- SocketLose      连接丢失事件，带有1个参数：
--                 sender      cc.Client

-- SocketMessage   接受事件，带有3个参数：
--                 sender      cc.Client
--                 msgName     消息名。
--                 body        消息体。
local Client = cc.Client;
Client.ProtocolType = config.ProtocolType:lower();

function Client:OnConnect(_) return false;end
function Client:OnMessage(_,_) return false;end
function Client:OnLose() return false;end
function Client:ctor()
    self.HeartBeat = config.SocketHeartBeat;
    self.ConnectHandler = Client.OnConnectHandler;
    self.MessageHandler = Client.OnMessageHandler;
    self.LoseHandler = Client.OnLoseHandler;
end

function Client.private:OnConnectHandler(suc)
    if not self:OnConnect(suc) then
        event.SocketConnect(self,suc);
    end
end

function Client.private:OnMessageHandler(msg)
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
    if not self:OnMessage(msgName,body) then
        event.SocketMessage(self,msgName,body);
    end
end

function Client.private:OnLoseHandler()
    if not self:OnLose() then
        event.SocketLose(self);
    end
end

---向对等连接发送消息。
---@param msgName string 消息名。
---@param data? table 消息体。
function Client:Send(msgName,data)
    data = data or {};
    if self.ProtocolType == "json" then
        data.msgName = msgName
        local sendStr = cjson.encode(data);
        if sendStr then
            return self:Write(sendStr);
        end
    elseif self.ProtocolType == "lua-protobuf" then
        local ok,sendStr = pcall(pb.encode,msgName,data)
        if ok then
            return self:Write(msgName.."\0"..sendStr)
        end
    end
    warn("无法序列化的消息。-" .. (msgName or ""));
end