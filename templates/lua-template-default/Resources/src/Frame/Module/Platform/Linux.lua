--[[
    Auth:       wzhengsen
    Date:       2020.09.07
    Content:    一些在Linux下实现的功能。
]]
local Windows = require("Platform.Windows");
local Linux = {
    RequestLocation = Windows.RequestLocation
};

return Linux;