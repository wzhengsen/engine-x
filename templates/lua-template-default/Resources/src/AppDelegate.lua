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

local config = require("config");
local Entrance = require("Game.Entrance");
local AppDelegate = class(cc.Application);

AppDelegate.private.keyboardListener = nil;

function AppDelegate.__new__()
    return cc.Application.Instance;
end

function AppDelegate.__singleton__()
    return AppDelegate.new();
end

function AppDelegate.static.set.Instance(val)
    assert(val == nil,"The nil value must be used.");
    os.exit();
end

function AppDelegate:ctor()
    local eventDispatcher = D.EventDispatcher;
    -- 监听进入前台后台事件。
    eventDispatcher:AddCustomEventListener("applicationWillEnterForeground",event.AppEnterForeground);
    eventDispatcher:AddCustomEventListener("applicationDidEnterBackground",event.AppEnterBackground);

    -- 监听屏幕旋转事件。
    eventDispatcher:AddCustomEventListener("ApplicationDidEnterLandscape",class.Break(function ()
        self:OnAppEnterLandscape();
    end));
    eventDispatcher:AddCustomEventListener("ApplicationDidEnterPortrait",class.Break(function ()
        self:OnAppEnterPortrait();
    end));
end

function AppDelegate.set:ListenKeyboardEnabled(val)
    val = cc.ToBoolean(val);
    local hasListener = not class.IsNull(self.keyboardListener);
    if val ~= hasListener then
        local dispatcher = D.EventDispatcher;
        if val then
            self.keyboardListener = cc.EventListenerKeyboard.new();
            self.keyboardListener.OnKeyPressed = event.KeyDown;
            self.keyboardListener.OnKeyReleased = event.KeyUp;
            dispatcher:AddEventListenerWithFixedPriority(self.keyboardListener, -1);
        else
            dispatcher:RemoveEventListener(self.keyboardListener);
            self.keyboardListener = nil;
        end
    end
end

---以给定的宽/高设置设计分辨率，会自动选用FIXED_WIDTH或FIXED_HEIGHT模式。
---并且在改变分辨率后会触发AppDesignResolutionChanged事件。
---
---@param width number
---@param height number
---
function AppDelegate:SetDesignResolutionSize(width,height)
    local view = D.OpenGLView;
    local frameSize = view.FrameSize;
    view:SetDesignResolutionSize(
        width,
        height,
        frameSize.width < frameSize.height and cc.ResolutionPolicy.FIXED_WIDTH or cc.ResolutionPolicy.FIXED_HEIGHT
    );

    local runningScene = D.RunningScene;
    if not class.IsNull(runningScene) then
        -- 此处重复一次隐藏/显示，以立即刷新一些不会自动重绘的节点。如：VideoPlayer/WebView/EditBox
        local vb = runningScene.Visible;
        runningScene.Visible = not vb;
        runningScene.Visible = vb;
    end

    event.AppDesignResolutionChanged(width,height);
end

function AppDelegate.protected:OnAppEnterLandscape()
    local glView = D.OpenGLView;
    local size = glView.FrameSize;
    glView.FrameSize = {
        width = size.height,
        height = size.width
    };
    self:SetDesignResolutionSize(
        config.DesignResolution.Landscape.width,
        config.DesignResolution.Landscape.height
    );
    event.AppEnterLandscape();
end

function AppDelegate.protected:OnAppEnterPortrait()
    local glView = D.OpenGLView;
    local size = glView.FrameSize;
    glView.FrameSize = {
        width = size.height,
        height = size.width
    };
    self:SetDesignResolutionSize(
        config.DesignResolution.Portrait.width,
        config.DesignResolution.Portrait.height
    );
    event.AppEnterPortrait();
end

function AppDelegate.private:InitGLView()
    local view = D.OpenGLView;

    local fullPath = F:FullPathForFilename("config.json");
    local jStr = F:GetDataFromFile(fullPath);
    local jConfig = jStr and cjson.decode(jStr) or {
        isLandscape = true,
        name = "StaryX",
        width = 640,
        height = 360
    };

    if class.IsNull(view) then
        D.OpenGLView = cc.GLViewImpl.CreateWithRect(
            jConfig.name,
            {
                x = 0,y = 0,
                width = jConfig.width,height = jConfig.height
            }
        );
    end

    if os.linux and jConfig.linuxIcon then
        D.OpenGLView.Icon = F.WritablePath .. jConfig.linuxIcon;
    end

    if jConfig.isLandscape then
        -- 横屏设计分辨率。
        self:SetDesignResolutionSize(
            config.DesignResolution.Landscape.width,
            config.DesignResolution.Landscape.height
        );
    else
        -- 竖屏设计分辨率。
        self:SetDesignResolutionSize(
            config.DesignResolution.Portrait.width,
            config.DesignResolution.Portrait.height
        );
    end

    -- 按配置项，向横屏或竖屏转动。
    cc.Device.Orientation = jConfig.isLandscape
    and cc.Device.OrientationType.Landscape
    or cc.Device.OrientationType.Portrait;
end

function AppDelegate.protected:OnFinishLaunch()

end

--[[
    Func:   重启
]]
function AppDelegate:Restart()
    cc.Downloader.CloseMGR();
    cc.Sound.UncacheAll();
    D:Restart();
end

function AppDelegate:Start()
    F:AddSearchPath(F.WritablePath .. "res/");
    F:AddSearchPath("res/");

    self:InitGLView();

    self.ListenKeyboardEnabled = true;

    self:OnFinishLaunch();
    Entrance.Instance:Enter();
end

if os.apple or os.android then
    function AppDelegate:Notify(...)
        LuaBridge.Notify(...);
    end
    if os.android then
        function AppDelegate:Dialog(...)
            LuaBridge.Dialog(...);
        end
    end
end

cc.AppDelegate = AppDelegate;
