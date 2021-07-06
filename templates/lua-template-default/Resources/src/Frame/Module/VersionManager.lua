--[[
Copyright (c) 2021 wzhengsen.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
]]

local VersionManager = class();
local config = require("config");

VersionManager.ctor = class.delete;

function VersionManager.private.EventHandler(e)
    local aEx = e.AssetsManagerEx;
    if class.IsNull(aEx) then
        return;
    end
    local function aExRelease()
        -- 释放aEx。
        if not class.IsNull(aEx.eventListener) then
            D.EventDispatcher:RemoveEventListener(aEx.eventListener);
        end
        aEx:Release();
    end
    local eventCode = e.EventCode;
    local codes = cc.EventAssetsManagerEx.EventCode;



    if eventCode == codes.ALREADY_UP_TO_DATE then
        -- 当前已经是最新，传递一个最新版本号作为参数。
        event.AlreadyUpToDate(aEx.module,aEx.RemoteManifest.Version);
        aExRelease();


    elseif eventCode == codes.NEW_VERSION_FOUND then
        if not aEx.inCheckUpdating then
            -- 只在checkUpdate的逻辑中检查，update只负责更新。
            return;
        end
        aEx.inCheckUpdating = false;

        if config.Update then
            -- 发现新热更版本，传递一个当前版本号和最新版本号作为参数。
            event.NewVersionFound(aEx.module,aEx.LocalManifest.Version,aEx.RemoteManifest.Version);
            aEx:update();
        else
            -- 不热更时，总是认为版本最新。
            event.AlreadyUpToDate(aEx.module,aEx.RemoteManifest.Version);
            aExRelease();
        end


    elseif eventCode == codes.UPDATE_PROGRESSION then
        if aEx.simpleMode then
            return;
        end
        local assetId = e.AssetId;
        if assetId == cc.AssetsManagerEx.VERSION_ID
        or assetId == cc.AssetsManagerEx.MANIFEST_ID then
            -- [[@version为版本文件，@manifest为清单文件，这两个文件跳过。]]
            return;
        end
        -- 热更过程，传递当前百分比。
        event.UpdateProgression(aEx.module,e.Percent);


    elseif eventCode == codes.ASSET_UPDATED then
        -- 某资源下载完成，传递当前资源Id（该Id有可能是资源名）与整体文件百分比。
        event.AssetUpdated(aEx.module,e.AssetId,e.PercentByFile);


    elseif eventCode == codes.UPDATE_FINISHED then
        -- 热更完成，传递最新版本号。
        event.UpdateFinished(aEx.module,aEx.LocalManifest.Version);
        aExRelease();


    elseif eventCode == codes.ERROR_NO_LOCAL_MANIFEST then
        if aEx.simpleMode then
            event.ErrorUpdateFailed(aEx.module);
        else
            -- 本地清单文件错误。
            event.ErrorNoLocalManifest(aEx.module);
        end
        aExRelease();


    elseif eventCode == codes.ERROR_DOWNLOAD_MANIFEST then
        if aEx.simpleMode then
            event.ErrorUpdateFailed(aEx.module);
        else
            -- 清单文件下载失败，传递当前资源Id（该Id有可能不是资源名）、错误码及错误原因。
            event.ErrorDownloadManifest(aEx.module,e.AssetId,e.CURLECode,e.Message);
        end
        aExRelease();


    elseif eventCode == codes.ERROR_PARSE_MANIFEST then
        if aEx.simpleMode then
            event.ErrorUpdateFailed(aEx.module);
        else
            -- 清单文件解析失败。
            event.ErrorParseManifest(aEx.module);
        end
        aExRelease();


    elseif eventCode == codes.ERROR_UPDATING then
        if aEx.simpleMode then
            return;
        end
        -- 热更文件更新失败，传递当前资源Id（该Id有可能是资源名）、错误码及错误原因。
        event.ErrorUpdating(aEx.module,e.AssetId,e.CURLECode,e.Message);


    elseif eventCode == codes.ERROR_DECOMPRESS then
        if aEx.simpleMode then
            return;
        end
        -- 热更文件解压失败，传递错误原因。
        -- 解压失败后仍然会触发ERROR_UPDATING
        event.ErrorDecompress(aEx.module,e.Message);


    elseif eventCode == codes.UPDATE_FAILED then
        -- 热更失败。
        event.ErrorUpdateFailed(aEx.module);
        aExRelease();
    end
end

---令版本管理器立即检查某个模块的更新，如果更新可用，将进入更新逻辑。
---@param module string         模块名。
---                             确保"Version/模块名/project.manifest.json"文件存在。
---@param simpleMode? boolean   {true}
---                             是否使用简易通知模式，否则使用完整模式。
---                             简易模式只有如下几种通知选项：
---                             AlreadyUpToDate,NewVersionFound,
---                             AssetUpdated,UpdateFinished,ErrorUpdateFailed
---                             完整模式有全部的通知：
---                             AlreadyUpToDate,NewVersionFound,UpdateProgression,
---                             AssetUpdated,UpdateFinished,ErrorNoLocalManifest,ErrorDownloadManifest,
---                             ErrorParseManifest,ErrorUpdating,ErrorDecompress,ErrorUpdateFailed
function VersionManager.Update(module,simpleMode)
    simpleMode = nil == simpleMode or simpleMode;
    local aEx = cc.AssetsManagerEx.new(
        "Version/" .. module .. "/project.manifest.json",
        F.WritablePath,
        3000
    );
    aEx:Retain();
    aEx.module = module;
    aEx.simpleMode = simpleMode;
    aEx.inCheckUpdating = true;

    aEx.eventListener = cc.EventListenerAssetsManagerEx.new(
        aEx,
        VersionManager.EventHandler
    );
    D.EventDispatcher:AddEventListenerWithFixedPriority(aEx.eventListener,1);

    -- 一个0秒计时器之后再checkUpdate，避免极端情况下，无法收到事件通知。
    cc.Alarm.new(0,function(_)
        if not class.IsNull(aEx) then
            aEx:CheckUpdate();
        end
    end);
end

local UpgradeHttpInvoker = class(cc.HttpInvoker);
function UpgradeHttpInvoker:OnResponse(suc,ret)
    if suc then
        local localCVersion = A.CompileVersion;
        local remoteCVersion = ret.version;
        if localCVersion < remoteCVersion and config.Upgrade then
            event.NewCompileVersionFound(remoteCVersion,ret.upgradeUrl,not not ret.force);
        else
            event.CompileVersionAlreadyUpToDate();
        end
    else
        event.ErrorUpgradeFailed();
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

cc.VersionManager = VersionManager;