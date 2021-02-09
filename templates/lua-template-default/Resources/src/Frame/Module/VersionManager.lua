--[[
    Auth:       wzhengsen
    Date:       2020.02.06
    Content:    对AssetsManagerEx的热更功能封装。
]]
local VersionManager = class();
local config = require("config");

function VersionManager.EventHandler(event)
    local aEx = event.AssetsManagerEx;
    if class.IsNull(aEx) then
        return;
    end
    local function aExRelease()
        -- 释放aEx。
        if not class.IsNull(aEx.eventListener) then
            cc.Director.getInstance().EventDispatcher:removeEventListener(aEx.eventListener);
        end
        aEx:release();
    end
    local eventCode = event:getEventCode();
    local codes = cc.EventAssetsManagerEx.EventCode;



    if eventCode == codes.ALREADY_UP_TO_DATE then
        -- 当前已经是最新，传递一个最新版本号作为参数。
        Event.AlreadyUpToDate(aEx.module,aEx.RemoteManifest.Version);
        aExRelease();


    elseif eventCode == codes.NEW_VERSION_FOUND then
        if not aEx.inCheckUpdating then
            -- 只在checkUpdate的逻辑中检查，update只负责更新。
            return;
        end
        aEx.inCheckUpdating = false;

        if config.Update then
            -- 发现新热更版本，传递一个当前版本号和最新版本号作为参数。
            Event.NewVersionFound(aEx.module,aEx.LocalManifest.Version,aEx.RemoteManifest.Version);
            aEx:update();
        else
            -- 不热更时，总是认为版本最新。
            Event.AlreadyUpToDate(aEx.module,aEx.RemoteManifest.Version);
            aExRelease();
        end


    elseif eventCode == codes.UPDATE_PROGRESSION then
        if aEx.simpleMode then
            return;
        end
        local assetId = event.AssetId;
        if assetId == cc.AssetsManagerEx.VERSION_ID
        or assetId == cc.AssetsManagerEx.MANIFEST_ID then
            -- [[@version为版本文件，@manifest为清单文件，这两个文件跳过。]]
            return;
        end
        -- 热更过程，传递当前百分比。
        Event.UpdateProgression(aEx.module,event.Percent);


    elseif eventCode == codes.ASSET_UPDATED then
        -- 某资源下载完成，传递当前资源Id（该Id有可能是资源名）与整体文件百分比。
        Event.AssetUpdated(aEx.module,event.AssetId,event.PercentByFile);


    elseif eventCode == codes.UPDATE_FINISHED then
        -- 热更完成，传递最新版本号。
        Event.UpdateFinished(aEx.module,aEx.LocalManifest.Version);
        aExRelease();


    elseif eventCode == codes.ERROR_NO_LOCAL_MANIFEST then
        if aEx.simpleMode then
            Event.ErrorUpdateFailed(aEx.module);
        else
            -- 本地清单文件错误。
            Event.ErrorNoLocalManifest(aEx.module);
        end
        aExRelease();


    elseif eventCode == codes.ERROR_DOWNLOAD_MANIFEST then
        if aEx.simpleMode then
            Event.ErrorUpdateFailed(aEx.module);
        else
            -- 清单文件下载失败，传递当前资源Id（该Id有可能不是资源名）、错误码及错误原因。
            Event.ErrorDownloadManifest(aEx.module,event.AssetId,event.CURLECode,event.Message);
        end
        aExRelease();


    elseif eventCode == codes.ERROR_PARSE_MANIFEST then
        if aEx.simpleMode then
            Event.ErrorUpdateFailed(aEx.module);
        else
            -- 清单文件解析失败。
            Event.ErrorParseManifest(aEx.module);
        end
        aExRelease();


    elseif eventCode == codes.ERROR_UPDATING then
        if aEx.simpleMode then
            return;
        end
        -- 热更文件更新失败，传递当前资源Id（该Id有可能是资源名）、错误码及错误原因。
        Event.ErrorUpdating(aEx.module,event.AssetId,event.CURLECode,event.Message);


    elseif eventCode == codes.ERROR_DECOMPRESS then
        if aEx.simpleMode then
            return;
        end
        -- 热更文件解压失败，传递错误原因。
        -- 解压失败后仍然会触发ERROR_UPDATING
        Event.ErrorDecompress(aEx.module,event.Message);


    elseif eventCode == codes.UPDATE_FAILED then
        -- 热更失败。
        Event.ErrorUpdateFailed(aEx.module);
        aExRelease();
    end
end

--[[
    Desc:       令更新管理器立即检查某个模块的更新，如果更新可用，将进入更新逻辑。
    Param:      string          模块名。
                                确保"Version/模块名/project.manifest.json"文件存在。

                boolean{true}   是否使用简易通知模式，否则使用完整模式。
                                简易模式只有如下几种通知选项：
                                AlreadyUpToDate,NewVersionFound,
                                AssetUpdated,UpdateFinished,ErrorUpdateFailed
                                完整模式有全部的通知：
                                AlreadyUpToDate,NewVersionFound,UpdateProgression,
                                AssetUpdated,UpdateFinished,ErrorNoLocalManifest,ErrorDownloadManifest,
                                ErrorParseManifest,ErrorUpdating,ErrorDecompress,ErrorUpdateFailed
]]
function VersionManager.Update(module,simpleMode)
    simpleMode = nil == simpleMode or simpleMode;
    local director = cc.Director.getInstance();
    local fuInst = cc.FileUtils.getInstance();
    local aEx = cc.AssetsManagerEx.new(
        "Version/" .. module .. "/project.manifest.json",
        fuInst.WritablePath,
        3000
    );
    aEx:retain();
    aEx.module = module;
    aEx.simpleMode = simpleMode;
    aEx.inCheckUpdating = true;

    aEx.eventListener = cc.EventListenerAssetsManagerEx.new(
        aEx,
        VersionManager.EventHandler
    );
    director.EventDispatcher:addEventListenerWithFixedPriority(aEx.eventListener,1);

    -- 一个0秒计时器之后再checkUpdate，避免极端情况下，无法收到事件通知。
    syx.Timer.new(0,function(_)
        if not class.IsNull(aEx) then
            aEx:checkUpdate();
        end
    end);
end

local UpgradeHttpInvoker = class(syx.HttpInvoker);
function UpgradeHttpInvoker:OnResponse(suc,ret)
    if suc then
        local localCVersion = syx.Application().CompileVersion;
        local remoteCVersion = ret.version;
        if localCVersion < remoteCVersion and config.Upgrade then
            Event.NewCompileVersionFound(remoteCVersion,ret.upgradeUrl,not not ret.force);
        else
            Event.CompileVersionAlreadyUpToDate();
        end
    else
        Event.ErrorUpgradeFailed();
    end
    -- 不再向下传递消息。
    return true;
end

--[[
    Desc:       令更新管理器立即检查是否可以更新编译版本。
                给定的url需要返回一个包含以下域的json：
                {
                    "version" : xxx,//整数
                    "upgradeUrl" : "https://xxx",
                    "force" : boolean,//是否建议强制更新，可选项。
                }
                会通知以下消息：
                NewCompileVersionFound ->发现新的编译版本可以升级；
                CompileVersionAlreadyUpToDate ->当前已是最新编译版本；
                ErrorUpgradeFailed ->升级操作失败。
    Param:      string          url
]]
function VersionManager.Upgrade(url)
    UpgradeHttpInvoker.new():Get(url);
end

return VersionManager;