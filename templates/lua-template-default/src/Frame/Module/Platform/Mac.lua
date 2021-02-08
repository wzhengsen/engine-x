--[[
    Auth:       wzhengsen
    Date:       2020.10.14
    Content:    一些在Mac下实现的功能。
]]
local Windows = require("Platform.Windows");
local Mac = {
    RequestLocation = Windows.RequestLocation
};

return Mac;