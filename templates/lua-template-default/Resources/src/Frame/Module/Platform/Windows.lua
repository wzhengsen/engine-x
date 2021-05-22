--[[
    Auth:       wzhengsen
    Date:       2020.01.23
    Content:    一些在Windows下实现的功能。

    Chg By:     wzhengsen
    Date:       2020.07.05
    Content:    不以回调通知定位，而是使用事件。
]]
local HttpInvoker = require("Network.HttpInvoker");
local LocationInvoker = class(HttpInvoker);

function LocationInvoker:__init__(callback)
    HttpInvoker.__init__(self);
    self.Timeout = 3000;
    self.Params = {
        ak = "xujZ0htdZtDXZz3eGTvGw0m3RUznBN7x",
        -- 坐标类型：gcj02或bd09ll或“空”
        coor = "gcj02"
    };
    self.__callback = callback;
end

function LocationInvoker:OnResponse(suc,ret)
    local data = ret.data;
    suc = suc and (data and data.status == 0 and data.content);

    local content = data and data.content;
    if self.__callback then
        self.__callback(suc and {
            x = content.point.x,
            y = content.point.y,
            province = content.address_detail.province,
            city = content.address_detail.city,
            district = content.address_detail.district,
            street = content.address_detail.street,
            number = content.address_detail.street_number
        } or nil);
    end
    return true;
end

local Windows = {};
function Windows.RequestLocation(callback)
    local invoker = LocationInvoker.new(callback);
    invoker:Get("https://api.map.baidu.com/location/ip");
    return true;
end

return Windows;