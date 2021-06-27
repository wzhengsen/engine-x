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

-- 令os继承自己，并使其不能实例化，主要是为了使用__properties__方法。
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
---@field public private any
---@field public get any
---@field public static any
---@field public const any
os = class(os);
function os.private:ctor()end
function os.private:dtor()end
function os.__new__()end

os.PlatformType = cc.ApplicationProtocol.Platform;
os.LanguageType = cc.LanguageType;

local app = cc.Application.Instance;
local targetPlatform<const> = app:GetTargetPlatform();

os.static.const.Platform = targetPlatform;
os.static.const.Language = app:GetCurrentLanguage();
os.static.const.Windows = targetPlatform == os.PlatformType.OS_WINDOWS;
os.static.const.Android = targetPlatform == os.PlatformType.OS_ANDROID;
os.static.const.Mac = targetPlatform == os.PlatformType.OS_MAC;
os.static.const.Iphone = targetPlatform == os.PlatformType.OS_IPHONE;
os.static.const.Ipad = targetPlatform == os.PlatformType.OS_IPAD;
os.static.const.Ios = targetPlatform == os.PlatformType.OS_IPHONE or targetPlatform == os.PlatformType.OS_IPAD;
os.static.const.Apple = targetPlatform == os.PlatformType.OS_IPHONE or targetPlatform == os.PlatformType.OS_IPAD or targetPlatform == os.PlatformType.OS_MAC;
os.static.const.Linux = targetPlatform == os.PlatformType.OS_LINUX;
os.static.const.Mobile = targetPlatform == os.PlatformType.OS_ANDROID or targetPlatform == os.PlatformType.OS_IPHONE or targetPlatform == os.PlatformType.OS_IPAD;

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