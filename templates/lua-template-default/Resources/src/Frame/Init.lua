-- Copyright (c) 2021 wzhengsen

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:

-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.

local path = package.path;
path = path .. ";src/Frame/Module/?.lua";
package.path = path;

local cpath = package.cpath;
package.cpath = cpath;

require("Frame.Extend.Lua.OsEx");
require("Frame.Extend.Lua.MathEx");
require("Frame.Extend.Lua.StringEx");
require("Frame.Extend.Lua.TableEx");
require("Frame.Extend.Lua.IoEx");
require("Frame.Extend.Lua.LuaEx");

require("AppDelegate");

_G.cjson = require("cjson");
_G.D = cc.Director.Instance;
_G.A = cc.AppDelegate.Instance;
_G.F = cc.FileUtils.Instance;

require("Frame.Core.LuaBridge");

require("Frame.Constant.OpenGLConstants");
require("Frame.Core.OpenGL");

require("Frame.Extend.Cocos2dx.Constants");
require("Frame.Extend.Cocos2dx.Cocos2dxEx");
require("Frame.Extend.Cocos2dx.LuaObjectEx");
require("Frame.Extend.Cocos2dx.ComponentEx");
require("Frame.Extend.Cocos2dx.NodeEx");
require("Frame.Extend.Cocos2dx.VideoPlayerEx");
require("Frame.Extend.Cocos2dx.ClientEx");
require("Frame.Extend.Cocos2dx.ServerEx");
require("Frame.Extend.Cocos2dx.ZipEx");
require("Frame.Extend.Cocos2dx.DownloaderEx");
require("Frame.Extend.Cocos2dx.WebSocketEx");

require("Utils.Convert");
require("Utils.UserFile");
require("Utils.LocalFile");

require("Audio.Sound");
require("Audio.Effect");
require("Audio.Music");

require("Network.HttpInvoker");

require("Others.Alarm");
require("Others.Label");

require("FSM");
require("VersionManager");

require("Math.Algorithm.RatePool");
require("Math.Algorithm.Stack");

require("Math.Geometry.IShape");
require("Math.Geometry.Circle");
require("Math.Geometry.Polygon");
require("Math.Geometry.Sector");
require("Math.Geometry.Vector");

require("Base.Scene.BaseScene");
require("Base.Scene.ILoadingScene");

local config = require("config");

if config.DisableGlobal then
    local __g = _G;
    __g.globals = setmetatable({}, {
        __newindex = function(_, name, value)
            rawset(__g, name, value);
        end,

        __index = function(_, name)
            return rawget(__g, name);
        end
    });
    setmetatable(__g, {
        __newindex = function(_, name, value)
            error(string.format("USE \" globals.%s = value \" INSTEAD OF SET GLOBAL VARIABLE.", name), 0);
        end
    });
end

if config.ShowFps then
    cc.Director.Instance.DisplayStats = true;
end

if config.RequireZipEnabled then
    local function ReadZipFile(zipFile,fileName,interFileName,pwd)
        local file = zipFile:Locate(interFileName);
        local ret = "No file found in zip file.The file name is "..interFileName;
        if file then
            local content = pwd and file:Read(pwd) or file:Read();
            local err = nil;
            if content then
                ret,err = load(content,fileName);
                if err then
                    error(err);
                end
            else
                ret = "Can't read zip internal file,maybe the password was wrong.The file name is "..interFileName;
            end
        end
        return ret;
    end
    --[[
        require Zip 文件时，查找路径不依赖package.path路径。
        支持中文路径和中文文件名。
        可省略文件的.lua/.luac/.zip后缀。
        参数：
            zFileName       遵循"Zip://fileName@subName"格式，如下：
                            require("Zip://myZipFile.zip@myData/userInfo.lua@password");
                            或
                            require("Zip://myZipFile@myData/userInfo@password");
    ]]
    local searcher = function (zFile)
        local zipPrefix<const> = "Zip://";
        if zFile:sub(1,#zipPrefix) ~= zipPrefix then
            return nil;
        end
        local where = zFile:find("@");
        if not where then
            return nil;
        end
        local zipFileName = zFile:sub(#zipPrefix + 1,where - 1);
        local zipFile = nil;
        if zipFileName:sub(-4) == ".zip" then
            zipFile = cc.RZip.new(zipFileName);
        else
            for _,fileExt in ipairs({".zip",""}) do
                zipFile = cc.RZip.new(zipFileName..fileExt);
                if zipFile then
                    break;
                end
            end
        end
        local ret = "No file found.File name is "..zipFileName;
        if not zipFile then
            return ret;
        end
        local pwdPos = zFile:find("@",where + 1);
        local pwd = pwdPos and zFile:sub(pwdPos + 1);
        local interFileName = zFile:sub(where + 1,pwdPos and pwdPos - 1 or -1);
        ret = "No file found in zip file.File name is "..interFileName;
        if interFileName:sub(-5) == ".luac" or interFileName:sub(-4) == ".lua" then
            ret = ReadZipFile(zipFile,zFile:sub(1,pwdPos and pwdPos - 1 or -1),interFileName,pwd);
        else
            for _,fileExt in pairs({".luac",".lua",""}) do
                ret = ReadZipFile(zipFile,zFile:sub(1,pwdPos and pwdPos - 1 or -1),interFileName..fileExt,pwd);
                if "function" == type(ret) then
                    break;
                end
            end
        end
        zipFile:delete();
        return ret;
    end
    table.insert(package.searchers,3,searcher);
end

if config.RequireHttpEnabled then
    local RequireHttpInvoker = class(cc.HttpInvoker);
    function RequireHttpInvoker:ctor()
        cc.HttpInvoker.ctor(self);
        self.timeout = 3000;
        self.async = false;
    end
    local rhInvoker = RequireHttpInvoker.new();
    --[[
        require HTTP 文件时，查找路径不依赖package.path路径，且不能省略.lua/.luac后缀。
        整个require过程是同步过程，会阻塞代码执行直到http返回。
        参数：
            url     支持https.
    ]]
    local searcher = function (url)
        if url:sub(1,7) ~= "http://" and url:sub(1,8) ~= "https://" then
            return nil;
        end
        local ret = rhInvoker:Get(url);
        local err = nil;
        if ret then
            ret,err = load(ret);
            if err then
                error(err);
            end
        else
            ret = "Can't read http/https file.The url name is "..url;
        end
        return ret;
    end
    table.insert(package.searchers,searcher);
end