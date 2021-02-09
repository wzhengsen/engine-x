local config = {
    -- show FPS on screen
    ShowFps = true,

    -- disable create unexpected global variable
    DisableGlobal = true,

    -- for module display
    DesignResolution = {
        Landscape = {
            width = 1920,
            height = 1080
        },
        Portrait = {
            width = 1080,
            height = 1920
        }
    },

    StartScene = "Game.FirstScene",

    --[[
        可选协议类型：
        pbc             见：https://github.com/cloudwu/pbc，支持protobuf2
        lua-protobuf    见：https://github.com/starwing/lua-protobuf，支持protobuf3
        json            require("cjson")
    ]]
    ProtocolType = "json",
    -- 是否开启心跳检查，使用false可以用于调试。
    SocketHeartBeat = false,
    -- Poll间隔，毫秒。
    PollTime = 20,

    -- 用于控制热更和应用升级是否可用。
    Update = true,
    Upgrade = true
}

local mt = {
    __index = {},
    __newindex = function()
        error("Can't modify the table.")
    end,
    __metatable = "Can't visit the metatable."
}
local saveTab = mt.__index
for k,v in pairs(config) do
    saveTab[k] = v
    config[k] = nil
end
setmetatable(config,mt)

return config