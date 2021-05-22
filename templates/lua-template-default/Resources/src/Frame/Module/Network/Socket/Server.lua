--[[
    Func:   带有协议解析和消息分发的服务器连接，继承自Socket.Connection.Server
    Auth:   wzhengsen
    Date:   2020.03.21

    Chg:    wzhengsen
            2020.04.04
            现在会先调用自己的响应函数了，返回true便不再向下传递。

    Chg:    wzhengsen
            2020.04.05
            OnClose时会携带一个标识是否全部关闭对等连接的布尔值了。

    Chg:    wzhengsen
            2020.04.28
            尝试移除04.05的变更。
]]
local Connection = require("Network.Socket.Connection");
local cServer = Connection.Server;
local Server = class(cServer);

local pb = require("pb");

local config = require("config");

--[[
    该类会向外通知如下3种事件：
    SocketAccept    接受连接事件，带有三个参数：
                        conn        对方连接
                        addr        对方地址
                        port        对方端口
    SocketClose     关闭事件，带有两个参数：
                        conn        关闭的连接（有可能是自己）。
                        suc         是否已完全关闭所有对等连接。
    SocketRecv      接受事件，带有三个参数：
                        conn        对方连接
                        msgName     消息名
                        data        消息体

]]
Server.ProtocolType = config.ProtocolType:lower()

function Server:__init__()
    Connection.Init();
    Connection.ObjectTable[self] = true;
    self.hbDelays = {};
    self.HeartbeatEnabled = true;
    self:SetHandler(function(sender,info)
        if info.event == Server.MG_Accept then
            -- 接受连接事件
            if not self:OnAccept(info.conn,info.addr,info.port) then
                Event.SocketAccept(sender,info.conn,info.addr,info.port);
            end
        elseif info.event == Server.MG_Close then
            --关闭事件
            if not self:OnClose(info.conn) then
                Event.SocketClose(sender,info.conn);
            end
        elseif info.event == Server.MG_Recv then
            if Server.ProtocolType == "json" then
                local ret = cjson.decode(info.msg)
                if type(ret) == "table" then
                    local msgName = ret.msgName
                    ret.msgName = nil
                    if msgName == "ClientToServerHeartbeat" then
                        self.hbDelays[info.conn] = 0;
                        self:Send(info.conn,"ServerToClientHeartbeat");
                    elseif not self:OnRecv(info.conn,msgName,ret) then
                        Event.SocketRecv(sender,msgName,ret);
                    end
                end
            elseif Server.ProtocolType == "lua-protobuf" then
                local msg = info.msg
                local offset = msg:find("\0")
                if offset then
                    local msgName = msg:sub(1,offset - 1)
                    local ret = msg:sub(offset + 1)
                    local ok,dataTab = pcall(pb.decode,msgName,ret)
                    if msgName == "ClientToServerHeartbeat" then
                        self.hbDelays[info.conn] = 0;
                        self:Send(info.conn,"ServerToClientHeartbeat");
                    elseif ok and not self:OnRecv(info.conn,msgName,dataTab) then
                        Event.SocketRecv(sender,msgName,dataTab);
                    end
                end
            end
        end
    end)
end

function Server:Send(conn,msgName,data)
    local toAll = "userdata" ~= type(conn);
    if toAll then
        data = msgName or {};
        msgName = conn;
        conn = nil;
    else
        data = data or {};
    end
    if Server.ProtocolType == "json" then
        data.msgName = msgName
        local sendStr = cjson.encode(data);
        if sendStr then
            if toAll then
                cServer.Send(self,sendStr);
            else
                cServer.Send(self,conn,sendStr)
            end
        end
    elseif Server.ProtocolType == "lua-protobuf" then
        local ok,sendStr = pcall(pb.encode,msgName,data)
        if ok then
            if toAll then
                cServer.Send(self,msgName.."\0"..sendStr);
            else
                cServer.Send(self,conn,msgName.."\0"..sendStr)
            end
        end
    end
end

function Server:OnClose(conn)
    if self.__toDelete and self == conn then
        if not class.IsNull(self.hbTimer) then
            self.hbTimer:delete();
        end
        cServer.delete(self);
    end
    return true;
end

function Server:OnRecv()
    return true;
end

function Server:OnAccept()
    return true;
end

function Server:__del__()
    if self.State == Server.Closed then
        if not class.IsNull(self.hbTimer) then
            self.hbTimer:delete();
        end
        cServer.delete(self);
        return true;
    end
    self.__toDelete = true;
    self:Close();
    return true;
end

Server.gtor({
    State = Server.GetState,
    Type = Server.GetType,
    Sockets = Server.GetSockets,
    HeartbeatEnabled = function(self)
        return not not self.heartbeat;
    end
});

Server.stor({
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
            if self.Type == Server.UDP then
                return;
            end
            self.hbDelays = {};
            self.hbTimer = self:Delay(3000,function()
                if self.State ~= Server.Listening then
                    return;
                end
                for _,sock in ipairs(self.Sockets) do
                    -- 若连续3次没有收到，则断开。
                    self.hbDelays[sock] = (self.hbDelays[sock] or 0) + 1;
                    if self.hbDelays[sock] >= 3 then
                        self:Close(sock);
                        self.hbDelays[sock] = nil;
                    end
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

return Server