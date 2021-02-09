--[[
    Auth:       wzhengsen
    Date:       2020.01.06
    Content:    由Application调用进入具体游戏逻辑。
]]
local Entrance = class(class.Singleton);
local config = require("config");

function Entrance:ctor()
    -- 游戏初始化代码 --
    local path = package.path;
    path = path .. ";src/Game/?.lua";
    package.path = path;

    local cpath = package.cpath;
    package.cpath = cpath;
    -- 游戏初始化代码 --
end

function Entrance:Enter()
    require(config.StartScene).new():Run();
end

return Entrance;