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

local Merge = table.Merge;
local Union = table.Union;
local clock = os.clock;
local floor = math.floor;
local decode = cjson.decode;
local encode = cjson.encode;
local insert = table.insert;
local type = type;
local ipairs = ipairs;
local next = next;
local concat = table.concat;
local tostring = tostring;

---@class HttpInvoker
---@field new fun(contentType?:table):HttpInvoker

---网络请求类，主要进行http请求。
local HttpInvoker = class();

HttpInvoker.static.ContentType = enum {
    UrlEncoded = {
        name = "application/x-www-form-urlencoded;charset=utf-8",
    },
    Json = {
        name = "application/json;charset=utf-8"
    }
};

-- 超时时间，为nil时使用cc.HttpRequest默认超时时间，也可以指定时间，以毫秒计。
HttpInvoker.protected.timeout = nil;
-- 重试次数，默认0，不重试。
HttpInvoker.protected.retry = 0;
-- 是否异步，为nil时使用cc.HttpRequest默认值，也可以指定是否异步。
HttpInvoker.protected.async = nil;
HttpInvoker.protected.contentType = nil;
HttpInvoker.protected.headers = {};
HttpInvoker.protected.params = {};
-- 暂存上次的响应，用于在使用同步请求时保存结果。
HttpInvoker.protected.responseCache = nil;

function HttpInvoker:ctor(contentType)
    self.contentType = contentType or HttpInvoker.ContentType.UrlEncoded;
end

---添加请求头。
---@overload fun(hKey:table)
---@param hKey any
---@param hValue any
function HttpInvoker:AddHeaders(hKey,hValue)
    if type(hKey) == "table" and hValue == nil then
        Merge(self.headers,hKey);
    else
        self.headers[hKey] = hValue;
    end
end

---添加请求参数。
---@overload fun(pKey:table)
---@param pKey any
---@param pValue any
function HttpInvoker:AddParams(pKey,pValue)
    if type(pKey) == "table" and pValue == nil then
        Merge(self.params,pKey);
    else
        self.params[pKey] = pValue;
    end
end

function HttpInvoker.protected:_OnResponse(_,url,code,rHeaders,response,sendTime)
    local suc = code == 200;
    local headers = {};
    local ret = {
        code = code,
        headers = headers,
        url = url,
        delay = floor(clock() * 1000 - sendTime)
    };

    for k,v in pairs(rHeaders) do
        headers[k] = v;
    end

    local ct = headers["Content-Type"] or headers["CONTENT-TYPE"] or headers["content-type"];
    if ct and ct:lower():find("application/json") then
        -- json响应类型，要求返回json能解析为一个表。
        local tab = decode(response);
        if type(tab) == "table" then
            ret.response = tab;
        else
            -- 返回值不能转换为json被认为是不成功的。
            suc = false;
        end
    else
        ret.response = response;
    end

    self.responseCache = suc and ret.response or nil;

    if not self:OnResponse(suc,ret) then
        event.Http(self,suc,ret);
    end
end

---准备发送请求。
---@param url string
---@param method table
function HttpInvoker.protected:Prepare(url,method)
    local hr = cc.HttpRequest.new();
    if self.timeout then
        hr.Timeout = self.timeout;
    end
    if nil ~= self.async then
        hr.Async = self.async;
    end
    if next(self.headers) then
        hr.Headers = Union(self.headers,{["Content-Type"] = self.contentType.name});
    end

    local ps = {};
    if self.contentType == HttpInvoker.ContentType.Json then
        insert(ps,encode(self.params));
    else
        for k, v in pairs(self.params) do
            insert(ps,tostring(k):Encode("url") .. "=" .. tostring(v):Encode("url"));
        end
    end

    return hr,concat(ps,"&");
end

function HttpInvoker:OnResponse(suc,ret)
end

---发送Get请求。
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
---@return string|table|nil 只有在同步请求时，才会有返回值。
function HttpInvoker:Get(url,retry)
    retry = retry or self.retry;
    local hr,data = self:Prepare(url);
    local sendTime = clock() * 1000;
    hr.Handler = class.Break(function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Get(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end);
    if "" == data then
        hr:Get(url);
    else
        hr:Get(url.."?"..data);
    end
    if false == self.async then
        return self.responseCache;
    end
end

---发送Post请求。
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
---@return string,table,nil 只有在同步请求时，才会有返回值。
function HttpInvoker:Post(url,retry)
    retry = retry or self.retry;
    local hr,data = self:Prepare(url);
    local sendTime = clock() * 1000;
    hr.Handler = class.Break(function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Post(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end);
    hr.Data = data;
    hr:Post(url);
    if false == self.async then
        return self.responseCache;
    end
end

---发送Put请求。
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
---@return string,table,nil 只有在同步请求时，才会有返回值。
function HttpInvoker:Put(url,retry)
    retry = retry or self.retry;
    local hr,data = self:Prepare(url);
    local sendTime = clock() * 1000;
    hr.Handler = class.Break(function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Put(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end);
    hr.Data = data;
    hr:Put(url);
    if false == self.async then
        return self.responseCache;
    end
end

---发送Delete请求。
---
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
---@return string,table,nil 只有在同步请求时，才会有返回值。
function HttpInvoker:Delete(url,retry)
    retry = retry or self.retry;
    local hr,data = self:Prepare(url);
    local sendTime = clock() * 1000;
    hr.Handler = class.Break(function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Delete(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end);
    if "" == data then
        hr:Delete(url);
    else
        hr:Delete(url.."?"..data);
    end
    if false == self.async then
        return self.responseCache;
    end
end

function HttpInvoker.set:Timeout(timeout)
    self.timeout = cc.ToInteger(timeout);
end

function HttpInvoker.set:Retry(retry)
    self.retry = cc.ToInteger(retry);
end

function HttpInvoker.set:Async(async)
    self.async = cc.ToBoolean(async);
end

function HttpInvoker.set:Headers(headers)
    self.headers = headers;
end

function HttpInvoker.set:Params(params)
    self.params = params;
end

cc.HttpInvoker = HttpInvoker;
return HttpInvoker;