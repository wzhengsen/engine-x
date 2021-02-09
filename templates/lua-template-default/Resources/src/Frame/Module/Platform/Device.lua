--[[
    Auth:       wzhengsen
    Date:       2020.01.23
    Content:    一些硬件设备提供的功能和硬件信息。
]]

-- require Device from package.preload
local Device = require("StarryX::Device");
local Platform = nil;
if os.IsWindows() then
    Platform = require("Platform.Windows");
elseif os.IsMobile() then
    Platform = require("Platform.Mobile");
elseif os.IsLinux() then
    Platform = require("Platform.Linux");
elseif os.IsMac() then
    Platform = require("Platform.Mac");
else
    error("unkown Platform.");
end

--[[
    Desc:       定位功能，基于不同系统，实现不同。
                定位完成向外发出RequestLocation事件，携带1个参数：
                Location{nil}       定位数据，若不成功，没有该数据。

    #Location#
    table{
        x = <number>,               经度
        y = <number>,               纬度
        province = <string>,        省份
        city = <string>,            城市
        district = <string>,        区县
        street = <string>,          街道
        number = <string>           门牌号
    }
]]
function Device.RequestLocation()
    return Platform.RequestLocation(function(locationInfo)
        local suc = "table" == type(locationInfo) and
        (not locationInfo.code or locationInfo.code == "61" or locationInfo.code == "161");
        if suc then
            locationInfo.code = nil;
            locationInfo.x = syx.Number(locationInfo.x);
            locationInfo.y = syx.Number(locationInfo.y);
        end
        Event.RequestLocation(suc and locationInfo or nil);
    end);
end

Device.GetDPI = cc.Device.getDPI;

Device.SetAccelerometerEnabled = cc.Device.setAccelerometerEnabled;

Device.SetAccelerometerInterval = cc.Device.setAccelerometerInterval;

Device.SetKeepScreenOn = cc.Device.setKeepScreenOn;

--[[
    Desc:       震动设备。
    Param:      number      震动时间，毫秒。
]]
function Device.Vibrate(time)
    cc.Device.vibrate(time / 1000);
end

--[[
    其余Lua导出函数见Device.h
]]
return Device;