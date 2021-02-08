--[[
    Auth:       wzhengsen
    Date:       2020.01.23
    Content:    一些在移动设备下实现的功能。
]]
local Mobile = {};

function Mobile.RequestLocation(callback)
    if os.IsAndroid() then
        if LuaBridge.CheckPermission("android.permission.ACCESS_FINE_LOCATION") then
            return LuaBridge.RequestLocation(callback);
        else
            LuaBridge.RequestPermission("android.permission.ACCESS_FINE_LOCATION",function(granted)
                if granted then
                    LuaBridge.RequestLocation(callback);
                end
            end);
        end
    else
        return LuaBridge.RequestLocation(callback);
    end
    return false;
end

return Mobile;