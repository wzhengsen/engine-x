--[[
    Module:	os
    Auth:	wzhengsen
    Date:	2019年08月04日
    Desc:	为os库新增了一些方法
]]
local app = cc.Application.Instance;
local targetPlatform = app.TargetPlatform;
local currentLanguage = app.CurrentLanguage;
os.Platform = cc.ApplicationProtocol.Platform;
os.Language = cc.LanguageType;

function os.GetPlatform()
    return targetPlatform;
end

function os.GetLanguage()
    return currentLanguage;
end

function os.IsWindows()
    return targetPlatform == os.Platform.OS_WINDOWS;
end

function os.IsAndroid()
    return targetPlatform == os.Platform.OS_ANDROID;
end

function os.IsMac()
    return targetPlatform == os.Platform.OS_MAC;
end

function os.IsIphone()
    return targetPlatform == os.Platform.OS_IPHONE;
end

function os.IsIpad()
    return targetPlatform == os.Platform.OS_IPAD;
end

function os.IsIos()
    return targetPlatform == os.Platform.OS_IPAD or targetPlatform == os.Platform.OS_IPHONE;
end

function os.IsApple()
    return targetPlatform == os.Platform.OS_IPAD
    or targetPlatform == os.Platform.OS_IPHONE
    or targetPlatform == os.Platform.OS_MAC;
end

function os.IsLinux()
    return targetPlatform == os.Platform.OS_LINUX;
end

function os.IsMobile()
    return targetPlatform == os.Platform.OS_IPHONE
    or targetPlatform == os.Platform.OS_IPAD
    or targetPlatform == os.Platform.OS_ANDROID;
end

if os.IsWindows() then
    local _execute = os.execute;
    function os.execute(command)
        if command then
            command = command:Convert("gb2312//TRANSLIT","utf-8");
        end
        return _execute(command);
    end

    local _remove = os.remove;
    function os.remove(filename)
        filename = filename:Convert("gb2312//TRANSLIT","utf-8");
        return _remove(filename);
    end

    local _rename = os.rename;
    function os.rename(oldname,newname)
        oldname = oldname:Convert("gb2312//TRANSLIT","utf-8");
        newname = newname:Convert("gb2312//TRANSLIT","utf-8");
        return _rename(oldname,newname);
    end
end