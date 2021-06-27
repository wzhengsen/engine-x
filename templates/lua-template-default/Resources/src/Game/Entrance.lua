--[[
    Auth:       wzhengsen
    Date:       2020.01.06
    Content:    由Application调用进入具体游戏逻辑。
]]
local Entrance = class();
local config = require("config");
Entrance.__new__ = Entrance.new;
Entrance.new = nil;

function Entrance.__properties__()
    return {
        r = {
            Instance = function ()
                if class.IsNull(Entrance.__instance) then
                    Entrance.__instance = Entrance.__new__();
                end
                return Entrance.__instance;
            end
        }
    };
end

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