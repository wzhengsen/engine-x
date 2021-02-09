--[[
    File:   Application
    Auth:   wzhengsen
    Date:   2019.07.06

    Chg By:     wzhengsen
    Date:       2020.02.08
    Content:    Application现在继承至cc.Application
]]
local Application = class(function()
    return cc.Application.getInstance();
end,class.Singleton);
local config = require("config");
local Entrance = require("Game.Entrance");

function Application:ctor()
    -- 监听进入前台后台事件。
    local eventDispatcher = cc.Director.getInstance():getEventDispatcher()
    self.lsrAWEF = eventDispatcher:addCustomEventListener(
        "applicationWillEnterForeground",
        class.Handler(self,self.OnEnterForeground)
    );
    self.lsrADEB = eventDispatcher:addCustomEventListener(
        "applicationDidEnterBackground",
        class.Handler(self,self.OnEnterBackground)
    );

    -- 不同设备，不同的监听转屏方法。
    if os.IsAndroid() then
        LuaBridge.SetOnLuaOrientationChanged(function(ori)
            if ori == 1 then
                self:OnDeviceToPortrait();
            elseif ori == 0 then
                self:OnDeviceToLandscape();
            end
        end);
    else
        -- 监听屏幕旋转事件。
        self.lsrDTL = eventDispatcher:addCustomEventListener(
            "DeviceToLandscape",
            class.Handler(self,self.OnDeviceToLandscape)
        );
        self.lsrDTP = eventDispatcher:addCustomEventListener(
            "DeviceToPortrait",
            class.Handler(self,self.OnDeviceToPortrait)
        );
    end
end

--[[
    Desc:       以给定的宽/高设置设计分辨率，会自动选用FIXED_WIDTH或FIXED_HEIGHT模式。
                并且在改变分辨率后会触发AppDesignResolutionChanged事件。
    Param:      <number>
                <number>
]]
function Application:SetDesignResolutionSize(width,height)
    local director = cc.Director.getInstance();
    local view = director:getOpenGLView();
    local frameSize = view:getFrameSize();
    view:setDesignResolutionSize(
        width,
        height,
        frameSize.width < frameSize.height and cc.ResolutionPolicy.FIXED_WIDTH or cc.ResolutionPolicy.FIXED_HEIGHT
    );

    local runningScene = director:getRunningScene();
    if not class.IsNull(runningScene) then
        -- 此处重复一次隐藏/显示，以立即刷新一些不会自动重绘的节点。如：VideoPlayer/WebView/EditBox
        local vb = runningScene:isVisible();
        runningScene:setVisible(not vb);
        runningScene:setVisible(vb);
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
    local glView = cc.Director.getInstance().OpenGLView;
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
    local glView = cc.Director.getInstance().OpenGLView;
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
    local director = cc.Director.getInstance();
    local view = director.OpenGLView;

    local fuInst = cc.FileUtils.getInstance();
    local fullPath = fuInst:fullPathForFilename("config.json");
    local jStr = fuInst:getDataFromFile(fullPath);
    local jConfig = jStr and cjson.decode(jStr) or {
        isLandscape = true,
        name = "StaryX",
        width = 640,
        height = 360
    };

    if class.IsNull(view) then
        director.OpenGLView = cc.GLViewImpl.createWithRect(
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
    syx.Device.SetOrientation(jConfig.isLandscape
    and syx.Device.OrientationType.Landscape
    or syx.Device.OrientationType.Portrait);
end

function Application:OnFinishLaunch()

end

--[[
    Func:   重启
]]
function Application:Restart()
    syx.Connection.CloseMGR();
    syx.Downloader.CloseMGR();
    syx.Sound.UncacheAll();
    cc.Director.getInstance():restart();
end

function Application:Start()
    local fuInst = cc.FileUtils.getInstance();
    fuInst:addSearchPath(fuInst.WritablePath .. "res/");
    fuInst:addSearchPath("res/");

    self:InitGLView();

    self.ListenKeyboardEnabled = true;

    self:OnFinishLaunch();
    Entrance():Enter();
end

if os.IsApple() or os.IsAndroid() then
    function Application:Notify(...)
        LuaBridge.Notify(...);
    end
    if os.IsAndroid() then
        function Application:Dialog(...)
            LuaBridge.Dialog(...);
        end
    end
end

--[[
    Desc:       开启/关闭一个全局的按键监听。
]]
Application.stor({
    ListenKeyboardEnabled = function(self,b)
        assert("boolean" == type(b), "Error boolean value.");
        local hasListener = not class.IsNull(self.__keyboardListener);
        if b ~= hasListener then
            if b then
                self.__keyboardListener = cc.EventListenerKeyboard.new();
                self.__keyboardListener:registerScriptHandler(function(keyCode,_)
                    Event.KeyDown(keyCode);
                end,ScriptHandlerMgr.HandlerType.EVENT_KEYBOARD_PRESSED);
                self.__keyboardListener:registerScriptHandler(function(keyCode,_)
                    Event.KeyUp(keyCode);
                end,ScriptHandlerMgr.HandlerType.EVENT_KEYBOARD_RELEASED);

                local dispatcher = cc.Director.getInstance().EventDispatcher;
                dispatcher:addEventListenerWithFixedPriority(self.__keyboardListener, -1);
            else
                local dispatcher = cc.Director.getInstance().EventDispatcher;
                dispatcher:removeEventListener(self.__keyboardListener);
                self.__keyboardListener = nil;
            end
        end
    end
});

return Application
