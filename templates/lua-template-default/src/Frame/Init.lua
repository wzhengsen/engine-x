local path = package.path;
path = path .. ";src/Frame/Module/?.lua";
path = path .. ";src/Frame/Extend/?.lua";
path = path .. ";src/Frame/Core/?.lua";
path = path .. ";src/Frame/Constant/?.lua";
path = path .. ";src/Frame/?.lua";
package.path = path;

local cpath = package.cpath;
package.cpath = cpath;

-- Initialize global.
cjson = require("cjson");

require("Lua.MathEx");
require("Lua.StringEx");
require("Lua.TableEx");

require("Event");
require("Handler");
require("Class");

require("Cocos2dxConstants");
require("OpenGLConstants");

require("OpenGL");

require("Cocos2dx.Cocos2dxEx");
require("Lua.OsEx");
require("Lua.IoEx");
require("Lua.Lua");

require("LuaBridge");

require("Cocos2dx.CSLoaderEx");
require("Cocos2dx.NodeEx");
require("Cocos2dx.RefEx");
require("Cocos2dx.WidgetEx");
require("Cocos2dx.ButtonEx");
require("Cocos2dx.VideoPlayerEx");

require("Module.Init");

local config = require("config");

-- export global variable
local __g = _G;
cc.exports = {};
setmetatable(cc.exports, {
    __newindex = function(_, name, value)
        rawset(__g, name, value);
    end,

    __index = function(_, name)
        return rawget(__g, name);
    end
});

-- disable create unexpected global variable
if config.DisableGlobal then
    setmetatable(__g, {
        __newindex = function(_, name, value)
            error(string.format("USE \" cc.exports.%s = value \" INSTEAD OF SET GLOBAL VARIABLE", name), 0);
        end
    });
end

if config.ShowFps then
    cc.Director.getInstance():setDisplayStats(true);
end