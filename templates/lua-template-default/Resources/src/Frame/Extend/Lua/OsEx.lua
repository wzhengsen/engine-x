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

--[[
    Module:	os
    Auth:	wzhengsen
    Date:	2019年08月04日
    Desc:	为os库新增了一些方法
]]
-- 令os继承自己，并使其不能实例化，主要是为了使用__properties__方法。
os.__r__ = {};
os.__w__ = {};
os.__bases__ = {};
os.Handler = {};

---@class osex
---@field Platform integer
---@field Language integer
---@field Windows boolean
---@field Android boolean
---@field Mac boolean
---@field Iphone boolean
---@field Ipad boolean
---@field Ios boolean
---@field Apple boolean
---@field Linux boolean
---@field Mobile boolean
os = class(os);
os.new = nil;

os.PlatformType = cc.ApplicationProtocol.Platform;
os.LanguageType = cc.LanguageType;

local app = cc.Application.Instance;
local targetPlatform<const> = app:GetTargetPlatform();
local currentLanguage<const> = app:GetCurrentLanguage();

local isWindows<const>  = targetPlatform == os.PlatformType.OS_WINDOWS;
local isAndroid<const>  = targetPlatform == os.PlatformType.OS_ANDROID;
local isMac<const>      = targetPlatform == os.PlatformType.OS_MAC;
local isIphone<const>   = targetPlatform == os.PlatformType.OS_IPHONE;
local isIpad<const>     = targetPlatform == os.PlatformType.OS_IPAD;
local isIos<const>      = isIphone or isIpad;
local isApple<const>    = isIos or isMac;
local isLinux<const>    = targetPlatform == os.PlatformType.OS_LINUX;
local isMobile<const>   = isAndroid or isIos;

function os.__properties__()
    return {
        r = {
            Platform = function ()
                return targetPlatform;
            end,
            Language = function ()
                return currentLanguage;
            end,
            Windows = function ()
                return isWindows;
            end,
            Android = function ()
                return isAndroid;
            end,
            Mac = function ()
                return isMac;
            end,
            Iphone = function ()
                return isIphone;
            end,
            Ipad = function ()
                return isIpad;
            end,
            Ios = function ()
                return isIos;
            end,
            Apple = function ()
                return isApple;
            end,
            Linux = function ()
                return isLinux;
            end,
            Mobile = function ()
                return isMobile;
            end
        }
    };
end

if os.Windows then
    local _execute = os.execute;
    function os.execute(command)
        if command then
            command = command:Convert("gbk//TRANSLIT","utf-8");
        end
        return _execute(command);
    end

    local _remove = os.remove;
    function os.remove(filename)
        filename = filename:Convert("gbk//TRANSLIT","utf-8");
        return _remove(filename);
    end

    local _rename = os.rename;
    function os.rename(oldname,newname)
        oldname = oldname:Convert("gbk//TRANSLIT","utf-8");
        newname = newname:Convert("gbk//TRANSLIT","utf-8");
        return _rename(oldname,newname);
    end
end