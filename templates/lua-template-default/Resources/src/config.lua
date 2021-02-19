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
    Upgrade = true,

    -- 用于控制是否可直接从zip文件中获取lua/luac文件。
    RequireZipEnabled = true,
    -- 用于控制是否可直接从Http和Https中获取lua/luac文件。
    -- 不建议使用，在网络上获取的一些lua文件如果是被精心炮制的，可能对程序运行产生影响。
    RequireHttpEnabled = false
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