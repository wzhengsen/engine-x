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
    File:   Application
    Auth:   wzhengsen
    Date:   2019.07.06

    Chg By:     wzhengsen
    Date:       2020.02.08
    Content:    Application现在继承至cc.Application
]]

local config = require("config");
local Entrance = require("Game.Entrance");
local App = cc.Application;
local Application = class(function()
    return App.Instance;
end);
Application.__new__ = Application.new;
Application.new = nil;

function Application.__properties__()
    return {
        r = {
            Instance = function (_)
                if class.IsNull(Application.__instance) then
                    Application.__instance = Application.__new__();
                end
                return Application.__instance;
            end
        },
        w = {
            --开启/关闭一个全局的按键监听。
            ListenKeyboardEnabled = function(self,b)
                assert("boolean" == type(b), "Error boolean value.");
                local hasListener = not class.IsNull(self.__keyboardListener);
                if b ~= hasListener then
                    local dispatcher = cc.Director.Instance.EventDispatcher;
                    if b then
                        self.__keyboardListener = cc.EventListenerKeyboard.new();
                        self.__keyboardListener.OnKeyPressed = Event.KeyDown;
                        self.__keyboardListener.OnKeyReleased = Event.KeyUp;
                        dispatcher:AddEventListenerWithFixedPriority(self.__keyboardListener, -1);
                    else
                        dispatcher:RemoveEventListener(self.__keyboardListener);
                        self.__keyboardListener = nil;
                    end
                end
            end
        }
    };
end

function Application:__init__()
    -- 监听进入前台后台事件。
    local eventDispatcher = cc.Director.Instance.EventDispatcher;
    self._lsrAWEF = eventDispatcher:AddCustomEventListener(
        "applicationWillEnterForeground",
        class.Handler(self,self.OnEnterForeground)
    );
    self._lsrADEB = eventDispatcher:AddCustomEventListener(
        "applicationDidEnterBackground",
        class.Handler(self,self.OnEnterBackground)
    );

    -- 不同设备，不同的监听转屏方法。
    if os.Android then
        LuaBridge.SetOnLuaOrientationChanged(function(ori)
            if ori == 1 then
                self:OnDeviceToPortrait();
            elseif ori == 0 then
                self:OnDeviceToLandscape();
            end
        end);
    else
        -- 监听屏幕旋转事件。
        self._lsrDTL = eventDispatcher:AddCustomEventListener(
            "DeviceToLandscape",
            class.Handler(self,self.OnDeviceToLandscape)
        );
        self._lsrDTP = eventDispatcher:AddCustomEventListener(
            "DeviceToPortrait",
            class.Handler(self,self.OnDeviceToPortrait)
        );
    end
end

---以给定的宽/高设置设计分辨率，会自动选用FIXED_WIDTH或FIXED_HEIGHT模式。
---并且在改变分辨率后会触发AppDesignResolutionChanged事件。
---
---@param width number
---@param height number
---
function Application:SetDesignResolutionSize(width,height)
    local director = cc.Director.Instance;
    local view = director.OpenGLView;
    local frameSize = view.FrameSize;
    view:SetDesignResolutionSize(
        width,
        height,
        frameSize.width < frameSize.height and cc.ResolutionPolicy.FIXED_WIDTH or cc.ResolutionPolicy.FIXED_HEIGHT
    );

    local runningScene = director.RunningScene;
    if not class.IsNull(runningScene) then
        -- 此处重复一次隐藏/显示，以立即刷新一些不会自动重绘的节点。如：VideoPlayer/WebView/EditBox
        local vb = runningScene.Visible;
        runningScene.Visible = not vb;
        runningScene.Visible = vb;
    end

    Event.AppDesignResolutionChanged(width,height);
end

function Application:OnEnterForeground()
    Event.AppEnterForeground();
end

function Application:OnEnterBackground()
    Event.AppEnterBackground();
end

function Application:OnDeviceToLandscape()
    local glView = cc.Director.Instance.OpenGLView;
    local size = glView.FrameSize;
    glView.FrameSize = {
        width = size.height,
        height = size.width
    };
    self:SetDesignResolutionSize(
        config.DesignResolution.Landscape.width,
        config.DesignResolution.Landscape.height
    );
    Event.DeviceToLandscape();
end

function Application:OnDeviceToPortrait()
    local glView = cc.Director.Instance.OpenGLView;
    local size = glView.FrameSize;
    glView.FrameSize = {
        width = size.height,
        height = size.width
    };
    self:SetDesignResolutionSize(
        config.DesignResolution.Portrait.width,
        config.DesignResolution.Portrait.height
    );
    Event.DeviceToPortrait();
end

function Application:InitGLView()
    local director = cc.Director.Instance;
    local view = director.OpenGLView;

    local fuInst = cc.FileUtils.Instance;
    local fullPath = fuInst:FullPathForFilename("config.json");
    local jStr = fuInst:GetDataFromFile(fullPath);
    local jConfig = jStr and cjson.decode(jStr) or {
        isLandscape = true,
        name = "StaryX",
        width = 640,
        height = 360
    };

    if class.IsNull(view) then
        director.OpenGLView = cc.GLViewImpl.CreateWithRect(
            jConfig.name,
            {
                x = 0,y = 0,
                width = jConfig.width,height = jConfig.height
            }
        );
    end

    if jConfig.linuxIcon then
        director.OpenGLView.Icon = {fuInst.WritablePath .. jConfig.linuxIcon};
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
    cc.Device.SetOrientation(jConfig.isLandscape
    and cc.Device.OrientationType.Landscape
    or cc.Device.OrientationType.Portrait);
end

function Application:OnFinishLaunch()

end

--[[
    Func:   重启
]]
function Application:Restart()
    cc.Connection.CloseMGR();
    cc.Downloader.CloseMGR();
    cc.Sound.UncacheAll();
    cc.Director.Instance:Restart();
end

function Application:Start()
    local fuInst = cc.FileUtils.Instance;
    fuInst:AddSearchPath(fuInst.WritablePath .. "res/");
    fuInst:AddSearchPath("res/");

    self:InitGLView();

    self.ListenKeyboardEnabled = true;

    self:OnFinishLaunch();
    Entrance.Instance:Enter();
end

if os.Apple or os.Android then
    function Application:Notify(...)
        LuaBridge.Notify(...);
    end
    if os.Android then
        function Application:Dialog(...)
            LuaBridge.Dialog(...);
        end
    end
end

cc.Application = Application;
