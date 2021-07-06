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

local Downloader = cc.Downloader;

function Downloader:OnFileSuccess(task)end
function Downloader:OnDataSuccess(task,data)end
function Downloader:OnProgress(task)end
function Downloader:OnError(task,code,err,reason)end

Downloader.static.protected.DLMGR = {};

function Downloader:ctor()
    Downloader.DLMGR[self] = true;

    self.OnFileTaskSuccess(function(task)
        if not self:OnSuccess(task) then
            event.DownloadFileSuccess(self,task);
        end
    end);
    self.OnDataTaskSuccess(function(task,data)
        if not self:OnSuccess(task) then
            event.DownloadDataSuccess(self,task,data);
        end
    end);
    self.OnTaskProgress(function(task)
        if not self:OnProgress(task) then
            event.DownloadProgress(self,task);
        end
    end);
    self:SetOnError(function(task,code,err,reason)
        if not self:OnError(task,code,err,reason) then
            event.DownloadError(self,task,code,err,reason);
        end
    end);
end

function Downloader:dtor()
    Downloader.DLMGR[self] = nil;
end

function Downloader.CloseMGR()
    for downloader,_ in pairs(Downloader.DLMGR) do
        downloader:delete();
    end
    Downloader.DLMGR = {};
end