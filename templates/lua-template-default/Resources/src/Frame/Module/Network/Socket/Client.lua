--[[
    File:   Client
    Func:   带有协议解析和消息分发的客户端连接，继承自Socket.Connection.Client
    Auth:   wzhengsen
    Date:   2019.10.05

    Chg:    wzhengsen
            2020.04.04
            现在会先调用自己的响应函数了，返回true便不再向下传递。
]]
local Connection = require("Network.Socket.Connection");
local cClient = Connection.Client;
local Client = class(cClient);

local pbc = require("Network.LuaPB.protobuf");
local pb = require("pb");

local config = require("config");
--[[
    该类会向外通知如下3种事件：
    SocketConnect   连接事件，带有一个suc参数，表示是否成功；
    SocketClose     关闭事件
    SocketRecv      接受事件，带有两个参数：
                    msgName     消息名
                    data        消息体

]]
Client.ProtocolType = config.ProtocolType:lower()

function Client:ctor()
    Connection.Init();
    Connection.ObjectTable[self] = true;
    self.HeartbeatEnabled = true;
    self:SetHandler(function(sender,info)
        if info.event == Client.MG_Connect then
            self.hbDelay = 0;
            --连接事件，info.suc表示成功与否
            if not self:OnConnect(info.suc) then
                Event.SocketConnect(sender,info.suc);
            end
        elseif info.event == Client.MG_Close then
            --关闭事件
            if not self:OnClose() then
                Event.SocketClose(sender);
            end
        elseif info.event == Client.MG_Recv then
            if Client.ProtocolType == "pbc" then
                --接受事件
                local msg = info.msg
                local offset = msg:find("\0")
                if offset then
                    local msgName = msg:sub(1,offset - 1)
                    local ret = msg:sub(offset + 1)
                    local ok,dataTab = pcall(pbc.decode,msgName,ret)
                    if msgName == "ServerToClientHeartbeat" then
                        self.hbDelay = 0;
                    elseif ok and not self:OnRecv(msgName,dataTab) then
                        Event.SocketRecv(sender,msgName,dataTab);
                    end
                end
            elseif Client.ProtocolType == "json" then
                local ret = cjson.decode(info.msg)
                if type(ret) == "table" then
                    local msgName = ret.msgName
                    ret.msgName = nil
                    if msgName == "ServerToClientHeartbeat" then
                        self.hbDelay = 0;
                    elseif not self:OnRecv(msgName,ret) then
                        Event.SocketRecv(sender,msgName,ret);
                    end
                end
            elseif Client.ProtocolType == "lua-protobuf" then
                local msg = info.msg
                local offset = msg:find("\0")
                if offset then
                    local msgName = msg:sub(1,offset - 1)
                    local ret = msg:sub(offset + 1)
                    local ok,dataTab = pcall(pb.decode,msgName,ret)
                    if msgName == "ServerToClientHeartbeat" then
                        self.hbDelay = 0;
                    elseif ok and not self:OnRecv(msgName,dataTab) then
                        Event.SocketRecv(sender,msgName,dataTab);
                    end
                end
            end
        end
    end)
end

function Client:Send(msgName,data)
    data = data or {};
    if Client.ProtocolType == "pbc" then
        local ok,sendStr = pcall(pbc.encode,msgName,data)
        if ok then
            cClient.Send(self,msgName.."\0"..sendStr)
        end
    elseif Client.ProtocolType == "json" then
        data.msgName = msgName
        local sendStr = cjson.encode(data);
        if sendStr then
            cClient.Send(self,sendStr);
        end
    elseif Client.ProtocolType == "lua-protobuf" then
        local ok,sendStr = pcall(pb.encode,msgName,data)
        if ok then
            cClient.Send(self,msgName.."\0"..sendStr)
        end
    end
end

function Client:OnConnect(suc)
end

function Client:OnRecv(msgName,dataTab)
end

function Client:OnClose()
    if self.__toDelete then
        if not class.IsNull(self.hbTimer) then
            self.hbTimer:delete();
        end
        cClient.delete(self);
    end
end

function Client:dtor()
    if self.State == cClient.Closed then
        if not class.IsNull(self.hbTimer) then
            self.hbTimer:delete();
        end
        cClient.delete(self);
        return true;
    end
    self.__toDelete = true;
    self:Close();
    return true;
end

Client.gtor({
    State = Client.GetState,
    Type = Client.GetType,
    HeartbeatEnabled = function(self)
        return not not self.heartbeat;
    end
});

Client.stor({
    -- 开启心跳。
    HeartbeatEnabled = function(self,val)
        if not config.SocketHeartBeat then
            return;
        end
        val = not not val;
        if self.heartbeat == val then
            return;
        end
        if val then
            if self.Type == Client.UDP then
                return;
            end
            self.hbDelay = 0;
            self.hbTimer = self:Delay(3000,function()
                if self.State ~= Client.Connected then
                    return;
                end
                -- 每3秒发送一次心跳，若连续3次没有响应，则断开。
                self.hbDelay = self.hbDelay + 1;
                if self.hbDelay >= 3 then
                    self:Close();
                else
                    self:Send("ClientToServerHeartbeat");
                end
            end,0);
        else
            if class.IsNull(self.hbTimer) then
                return;
            end
            self.hbTimer:delete();
        end
    end
});

return Client;