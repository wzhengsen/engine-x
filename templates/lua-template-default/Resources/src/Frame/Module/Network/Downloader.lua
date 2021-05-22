--[[
    Auth:       wzhengsen
    Date:       2019.12.26
    Content:    仅作为cc.Downloader的注释。
                这个cc.Downloader没有继承cc.Ref，需要手动释放。

    Chg By:     wzhengsen
    Date:       2020.06.30
    Content:    现在Downloader主要向外发送消息通知，而不再由回调函数处理。

    Chg By:     wzhengsen
    Date:       2020.09.26
    Content:    可以指定一个once参数，以确保使用一次后，自动析构。

    Chg By:     wzhengsen
    Date:       2020.10.02
    Content:    新增CloseMGR方法，用于在特定时间删除全部下载器。
]]
local StarryDownloader = require("Starry::Downloader");
local Downloader = class(StarryDownloader);

function Downloader:__init__(once)
    Downloader.__dlMGR = Downloader.__dlMGR or {};
    table.insert(Downloader.__dlMGR,self);
    self._once = once == nil or once;
    self:SetOnSuccess(function(sender,task)
        if not self:OnSuccess(task) then
            Event.DownloadSuccess(sender,task);
        end
        if sender._once then
            sender:delete();
        end
    end);
    self:SetOnProgress(function(sender,task)
        if not self:OnProgress(task) then
            Event.DownloadProgress(sender,task);
        end
    end);
    self:SetOnError(function(sender,task)
        if not self:OnError(task) then
            Event.DownloadError(sender,task);
        end
        if sender._once then
            sender:delete();
        end
    end);
end

function Downloader:OnSuccess(task)
end

function Downloader:OnProgress(task)
end

function Downloader:OnError(task)
end

function Downloader:__del__()
    table.remove(Downloader.__dlMGR,table.Find(Downloader.__dlMGR,self));
end

function Downloader.CloseMGR()
    if not Downloader.__dlMGR then
        return;
    end
    for _,v in ipairs(Downloader.__dlMGR) do
        v:delete();
    end
    Downloader.__dlMGR = {};
end

return Downloader;

--[====[
    #Downloader#
    static method:
        new(
        [countOfMaxProcessingTasks              <number>{6}             最高任务数。
        [,timeoutInMS                           <number>{45000}         超时时间，单位毫秒。
        [,tempFileNameSuffix]]]                 <string>{".temp"}       临时文件后缀。
        )                                       -><userdata>#Downlaoder#

    method:
        delete()
        不使用时手动回收，会中断当前的下载任务。

        Download(
            url                                 <string>                下载地址。
            [,path                              <string>                文件保存地址，使用绝对路径（没有该参数时，使用数据下载模式）。
            [,md5]]                             <string>                md5校验和，帮助校验文件完整性，可为空。
        )->userdata#DownloadTask#
        为下载器创建一个下载任务到指定的文件/或下载指定的数据。

        SetOnSuccess(
            callback                            <function>#DownloadCallBack#
        )
        注册一个函数作为成功回调，使用nil以清除当前回调。

        SetOnProgress(
            callback                            <function>#DownloadCallBack#
        )
        注册一个函数作为进度回调，使用nil以清除当前回调。

        SetOnError(
            callback                            <function>#DownloadCallBack#
        )
        注册一个函数作为失败回调，使用nil以清除当前回调。


    #DownloadCallBack#
    prototype:
        function(
            sender,                             Downloader                  下载器。
            task                                <table>#DownloadTask#       下载任务。
        )


    #DownloadTask#
    method:
        Cancel()
        取消当前下载。

    member:

        Url<string>                             当前任务的下载地址。

        [Path<string>]                          当前任务的下载存放文件路径（以字节数据下载时，没有该成员）。

        [Error<number>]                         错误输出，只有下载出错才有该成员。

        [Received<number>]                      当次进度完成的字节数，响应下载过程事件时，才有该成员。
        [Got<number>]                           当前完成的总字节数，响应下载过程事件时，才有该成员。
        [Size<number>]                          总字节数，响应下载过程事件时，才有该成员。
        [Speed<number>]                         下载速度（字节），响应下载过程事件时，才有该成员。

        [Data<string>]                          以字节数据下载成功时，返回的数据；当以文件下载成功时，没有该成员。
]====]