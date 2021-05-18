--[[
    File:   HttpInvoker
    Func:   网络请求类，主要进行http请求
    Auth:   wzhengsen
    Date:   2021.05.18
]]

---@class HttpInvoker
---@field new fun(contentType?:table):HttpInvoker
local HttpInvoker = class();

HttpInvoker.ContentType = {
    UrlEncoded = {
        name = "application/x-www-form-urlencoded;charset=utf-8",
    },
    Json = {
        name = "application/json;charset=utf-8"
    }
};

function HttpInvoker:ctor(contentType)
    -- 超时时间，为nil时使用cc.HttpRequest默认超时时间，也可以指定时间，以毫秒计。
    self._timeout = nil;
    -- 重试次数，默认0，不重试。
    self._retry = 0;
    -- 是否异步，为nil时使用cc.HttpRequest默认值，也可以指定是否异步。
    self._async = nil;
    self._contentType = contentType or HttpInvoker.ContentType.UrlEncoded;
    self._headers = {};
    self._params = {};
end

---添加请求头。
---
---@overload fun(hKey:table)
---@param hKey any
---@param hValue any
function HttpInvoker:AddHeader(hKey,hValue)
    if type(hKey) == "table" and hValue == nil then
        table.Merge(self._headers,hKey);
    else
        self._headers[hKey] = hValue;
    end
end

---添加请求参数。
---
---@overload fun(pKey:table)
---@param pKey any
---@param pValue any
function HttpInvoker:AddParams(pKey,pValue)
    if type(pKey) == "table" and pValue == nil then
        table.Merge(self._params,pKey);
    else
        self._params[pKey] = pValue;
    end
end

function HttpInvoker:_OnResponse(_,url,code,headerStr,response,sendTime)
    local suc = code == 200;
    local headers = {};
    local ret = {
        code = code,
        headers = headers,
        url = url,
        delay = math.floor(os.clock() * 1000 - sendTime)
    };

    -- 以\n和:分割出响应头信息。
    for _,v in ipairs(headerStr:Split("\n")) do
        local snap = v:find(":");
        if snap then
            headers[v:sub(1,snap - 1)] = v:sub(snap + 1):Trim();
        end
    end

    local ct = headers["Content-Type"];
    if ct and ct:lower():find("application/json") then
        -- json响应类型，要求返回json能解析为一个表。
        local tab = cjson.decode(response);
        if type(tab) == "table" then
            ret.response = tab;
        else
            -- 返回值不能转换为json被认为是不成功的。
            suc = false;
        end
    else
        ret.response = response;
    end

    if not self:OnResponse(suc,ret) then
        Event.Http(self,suc,ret);
    end
end

---准备发送请求。
---
---@param url string
---@param method table
function HttpInvoker:_Prepare(url,method)
    local hr = cc.HttpRequest.new()
    if self._timeout then
        hr.Timeout = self._timeout;
    end
    if nil ~= self._async then
        hr.Async = self._async;
    end
    if next(self._headers) then
        hr.Headers = self._headers;
        hr:AddHeaders({["Content-Type"] = self._contentType.name});
    end

    local ps = {};
    if self._contentType == HttpInvoker.ContentType.Json then
        table.insert(ps,cjson.encode(self._params));
    else
        for k, v in pairs(self._params) do
            table.insert(ps,tostring(k):Encode("url") .. "=" .. tostring(v):Encode("url"));
        end
    end

    return hr,table.concat(ps,"&");
end

function HttpInvoker:OnResponse(suc,ret)
end

---发送Get请求。
---
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
function HttpInvoker:Get(url,retry)
    retry = retry or self._retry;
    local hr,data = self:_Prepare(url);
    local sendTime = os.clock() * 1000;
    hr.Handler = function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Get(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end;
    if "" == data then
        hr:Get(url);
    else
        hr:Get(url.."?"..data);
    end
end

---发送Post请求。
---
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
function HttpInvoker:Post(url,retry)
    retry = retry or self._retry;
    local hr,data = self:_Prepare(url);
    local sendTime = os.clock() * 1000;
    hr.Handler = function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Post(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end;
    hr.Data = data;
    hr:Post(url);
end

---发送Put请求。
---
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
function HttpInvoker:Put(url,retry)
    retry = retry or self._retry;
    local hr,data = self:_Prepare(url);
    local sendTime = os.clock() * 1000;
    hr.Handler = function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Put(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end;
    hr.Data = data;
    hr:Put(url);
end

---发送Delete请求。
---
---@param url string
---@param retry? integer 不要在外部传递该参数，该参数自动由HttpInvoker.Retry指定。
function HttpInvoker:Delete(url,retry)
    retry = retry or self._retry;
    local hr,data = self:_Prepare(url);
    local sendTime = os.clock() * 1000;
    hr.Handler = function (sender,code,headers,response)
        if code ~= 200 and retry > 0 then
            -- 还剩余重试次数。
            self:Delete(url,retry - 1);
            return;
        end
        self:_OnResponse(sender,url,code,headers,response,sendTime);
    end;
    if "" == data then
        hr:Delete(url);
    else
        hr:Delete(url.."?"..data);
    end
end

function HttpInvoker.__properties__()
    return {
        w = {
            Timeout = function (self,timeout)
                self._timeout = timeout;
            end,
            Retry = function (self,retry)
                self._retry = retry or 0;
            end,
            Async = function (self,async)
                self._async = async;
            end,
            Headers = function (self,headers)
                self._headers = headers or {};
            end,
            Params = function (self,params)
                self._params = params or {};
            end
        }
    };
end

return HttpInvoker;