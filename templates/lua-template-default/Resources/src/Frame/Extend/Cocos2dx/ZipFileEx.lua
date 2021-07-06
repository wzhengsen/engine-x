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

local ZipFile = cc.ZipFile;

function ZipFile:OnProcess(_,_,_)end
function ZipFile:OnError(_,_)end

function ZipFile:ctor()
    self.ProcessHandler = ZipFile.OnProcessHandler;
    self.ErrorHandler = ZipFile.OnErrorHandler;
end

function ZipFile.private:OnProcessHandler(path,idx,count)
    if not self:OnProcess(path,idx,count) then
        event.ZipFileProcess(self,path,idx,count);
    end
end

function ZipFile.private:OnErrorHandler(code,reason)
    if not self:OnError(code,reason) then
        event.ZipFileError(self,code,reason);
    end
end