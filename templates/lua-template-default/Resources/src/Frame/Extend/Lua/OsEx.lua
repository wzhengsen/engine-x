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
---@field platform integer
---@field language integer
---@field windows boolean
---@field android boolean
---@field mac boolean
---@field iphone boolean
---@field ipad boolean
---@field ios boolean
---@field apple boolean
---@field linux boolean
---@field mobile boolean
---@field clipboard string
---@field public private any
---@field public get any
---@field public static any
---@field public const any
os = class(os);
os.ctor = class.delete;

os.platformtype = cc.ApplicationProtocol.Platform;
os.languagetype = cc.LanguageType;

local app = cc.Application.Instance;
local targetPlatform<const> = app:GetTargetPlatform();

os.static.const.platform = targetPlatform;
os.static.const.language = app:GetCurrentLanguage();
os.static.const.windows = targetPlatform == os.platformtype.OS_WINDOWS;
os.static.const.android = targetPlatform == os.platformtype.OS_ANDROID;
os.static.const.mac = targetPlatform == os.platformtype.OS_MAC;
os.static.const.iphone = targetPlatform == os.platformtype.OS_IPHONE;
os.static.const.ipad = targetPlatform == os.platformtype.OS_IPAD;
os.static.const.ios = targetPlatform == os.platformtype.OS_IPHONE or targetPlatform == os.platformtype.OS_IPAD;
os.static.const.apple = targetPlatform == os.platformtype.OS_IPHONE or targetPlatform == os.platformtype.OS_IPAD or targetPlatform == os.platformtype.OS_MAC;
os.static.const.linux = targetPlatform == os.platformtype.OS_LINUX;
os.static.const.mobile = targetPlatform == os.platformtype.OS_ANDROID or targetPlatform == os.platformtype.OS_IPHONE or targetPlatform == os.platformtype.OS_IPAD;
os.static.const.pc = not os.mobile;

os.static.get.clipboard = ccu.GetClipboard;
os.static.set.clipboard = ccu.SetClipboard;

if os.windows then
    local _execute = os.execute;
    function os.execute(command)
        if command then
            command = command:convert("utf-8","gbk//TRANSLIT");
        end
        return _execute(command);
    end

    local _remove = os.remove;
    function os.remove(filename)
        filename = filename:convert("utf-8","gbk//TRANSLIT");
        return _remove(filename);
    end

    local _rename = os.rename;
    function os.rename(oldname,newname)
        oldname = oldname:convert("utf-8","gbk//TRANSLIT");
        newname = newname:convert("utf-8","gbk//TRANSLIT");
        return _rename(oldname,newname);
    end
end