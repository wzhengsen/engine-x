--[[
    File:   HttpInvoker
    Func:   网络请求类，主要进行http请求
    Auth:   wzhengsen
    Date:   2019.04.04

    Chg By:     wzhengsen
    Content:    method新增了"put"和"delete"
                对超时时间做了验证，超时后不会再回调。

    Chg By:     wzhengsen
    Date:       2019.10.05
    Content:    合并了两个回调为一个，现在回调函数新增一个指示成功与否的布尔值参数。

    Chg By:     wzhengsen
    Date:       2019.10.13
    Content:    现在回调函数以SetHandler方法来设置了，Send方法保留一个重试参数

    Chg By:     wzhengsen
    Date:       2019.12.03
    Content:    现在没有回调函数了，通过Event事件向外通知；
                现在有了真正的毫秒级超时时间控制了。

    Chg By:     wzhengsen
    Date:       2019.12.16
    Content:    Send新增了一个function作为回调函数。

    Chg By:     wzhengsen
    Date:       2020.01.24
    Content:    新增了SetParamEncode以编码参数。

    Chg By:     wzhengsen
    Date:       2020.06.10
    Content:    调整了method的枚举值；
                新增了Header/Params/Aborted属性；
                调整了回调的响应原型；
                现在调用delete将立刻Aborted当前请求。

    Chg By:     wzhengsen
    Date:       2020.06.30
    Content:    现在回调只会以通知向外发送了，类似于Socket.Client与Socket.Server的处理方式。

    Chg By:     wzhengsen
    Date:       2020.07.01
    Content:    修复了一些逻辑问题。

    Chg By:     wzhengsen
    Date:       2020.07.27
    Content:    构造时，不再需要传递参数了；
                Send不再推荐直接调用，重命名为_Send，使用Get,Post,Put,Delete代替；
                Retry和Async使用单独的方法设置了；
                类的内部响应使用OnResponse而非OnHttp了，OnHttp用作外部通知。

    Chg By:     wzhengsen
    Date:       2020.12.07
    Content:    构造时可以提供Content-Type了，默认使用application/x-www-form-urlencoded。

    Chg By:     wzhengsen
    Date:       2021.02.19
    Content:    如果使用同步模式，将在Get/Post...等方法结束时返回值。
]]
local HttpInvoker = class();

-- 默认超时时间
HttpInvoker.DefaultTimeoutMillisecond = 30000;
HttpInvoker.Method = {
    Get = {
        name = "get"
    },
    Post = {
        name = "post"
    },
    Put = {
        name = "put"
    },
    Delete = {
        name = "delete"
    }
};
HttpInvoker.ContentType = {
    UrlEncoded = {
        name = "application/x-www-form-urlencoded;charset=utf-8",
    },
    TextPlain = {
        name = "text/plain",
    },
    Json = {
        name = "application/json;charset=utf-8"
    }
};

function HttpInvoker:ctor(contentType)
    self._timeout = HttpInvoker.DefaultTimeoutMillisecond;
    self._responseType = cc.XMLHttpRequest.ResponseType.JSON;
    self._contentType = contentType or HttpInvoker.ContentType.UrlEncoded;
    self._header = {};
    self._params = {};
    -- 重试次数，默认0。
    self._retry = 0;
    -- 是否异步。
    self._async = true;
    -- 默认参数不进行url编码。
    self._encodeParams = false;
    self._XHRArr = {};
end

--[[
    Func:   添加请求头
    Param:  key|table,value
]]
function HttpInvoker:AddHeader(hKey,hValue)
    if type(hKey) == "table" and hValue == nil then
        table.Merge(self._header,hKey);
    else
        self._header[hKey] = hValue;
    end
end

--[[
    Func:   添加请求参数
    Param:  key|table,value
]]
function HttpInvoker:AddParams(pKey,pValue)
    if type(pKey) == "table" and pValue == nil then
        table.Merge(self._params,pKey);
    else
        self._params[pKey] = pValue;
    end
end

function HttpInvoker:_OnResponse(xhr,url,method,sendTime)
    self._XHRArr[xhr] = nil;
    local suc = xhr.status >= 200 and xhr.status < 207;
    if not suc and self._retry > 0 then
        -- 还剩余重试次数。
        self:_Send(url,method);
        return;
    end

    local data = xhr.response;
    local header = {};
    local ret = {
        code = xhr.status,
        header = header,
        url = url,
        delay = math.floor(os.clock() * 1000 - sendTime)
    };

    -- 以\n和:分割出响应头信息。
    local headerTab = xhr:getAllResponseHeaders():Split("\n");
    for _,v in ipairs(headerTab) do
        local snap = v:find(":");
        if snap then
            header[v:sub(1,snap - 1)] = v:sub(snap + 1):Trim();
        end
    end

    if self._responseType == cc.XMLHttpRequest.ResponseType.JSON then
        -- json响应类型，要求返回json能解析为一个表。
        local tab = cjson.decode(data);
        if type(tab) == "table" then
            ret.data = tab;
        else
            -- 返回值不能转换为json被认为是不成功的。
            suc = false;
        end
    else
        ret.data = data;
    end

    if self._async then
        -- 异步下，不记录最近返回的数据，没有意义。
        self._lastData = nil;
    else
        -- 记录最近返回的data.
        self._lastData = ret.data;
    end
    if not self:OnResponse(suc,ret) then
        Event.Http(self,suc,ret);
    end
end

--[[
    Func:   发送请求
    Param:  string          url
            table{HttpInvoker.Method}   请求方法
    Desc:   响应回调函数原型：
            function(suc,data)
            end
]]
function HttpInvoker:_Send(url,method)
    local xhr = cc.XMLHttpRequest.new()
    self._XHRArr[xhr] = true;

    xhr.timeout = self._timeout
    xhr.responseType = self._responseType

    local sendTime = os.clock() * 1000;
    --注册请求响应回调
    xhr:registerScriptHandler(function(_,sender)
        self:_OnResponse(sender,url,method,sendTime)
    end)

    for k,v in pairs(self._header) do
        -- 请求头。
        xhr:setRequestHeader(k,v)
    end

    local ps = {};
    if self._contentType == HttpInvoker.ContentType.Json then
        local j = cjson.encode(self._params);
        if self._encodeParams then
            j = j:Encode("url");
        end
        table.insert(ps,j);
        xhr:setRequestHeader("Content-Type",HttpInvoker.ContentType.Json.name);
    elseif self._contentType == HttpInvoker.ContentType.TextPlain then
        if self._encodeParams then
            for k, v in pairs(self._params) do
                table.insert(ps,tostring(k):Encode("url") .. "=" .. tostring(v):Encode("url"));
            end
        else
            for k, v in pairs(self._params) do
                table.insert(ps,tostring(k):gsub(" ","+") .. "=" .. tostring(v):gsub(" ","+"));
            end
        end
        xhr:setRequestHeader("Content-Type",HttpInvoker.ContentType.TextPlain.name);
    else
        for k, v in pairs(self._params) do
            table.insert(ps,tostring(k):Encode("url") .. "=" .. tostring(v):Encode("url"));
        end
        xhr:setRequestHeader("Content-Type",HttpInvoker.ContentType.UrlEncoded.name);
    end

    local pData = table.concat(ps,"&")
    if method == HttpInvoker.Method.Get then
        xhr:open(method.name, url.."?"..pData,self._async)
        xhr:send()
    else
        xhr:open(method.name, url,self._async)
        xhr:send(pData)
    end

    if not self._async then
        return self._lastData;
    end
end

--[[
    Desc:       决定当前处于活动状态的http响应是否终止（即无论是否成功，都不会有回调）。
]]
function HttpInvoker:Aborted()
    for x,_ in pairs(self._XHRArr) do
        if class.IsNull(x) then
            x:setAborted(true);
        end
    end
    self._XHRArr = {};
end

function HttpInvoker:OnResponse(suc,ret)
end

function HttpInvoker:Get(url)
    return self:_Send(url,HttpInvoker.Method.Get);
end

function HttpInvoker:Post(url)
    return self:_Send(url,HttpInvoker.Method.Post);
end

function HttpInvoker:Put(url)
    return self:_Send(url,HttpInvoker.Method.Put);
end

function HttpInvoker:Delete(url)
    return self:_Send(url,HttpInvoker.Method.Delete);
end

--[[
    Desc:       该类型可以使用后不主动delete，回调完成后，会自动垃圾收集；
                也可以调用delete，但当前未响应的请求将会终止。
]]
function HttpInvoker:dtor()
    self:Aborted();
end

HttpInvoker.gtor({
    --[[
        Desc:   获取参数是否进行URL编码（默认即为false）。
        Return: bool        指示在请求时是否编码参数。
    ]]
    EncodeParams = function(self)
        return self._encodeParams;
    end,
    --[[
        Return:  number          超时时间，毫秒
    ]]
    Timeout = function(self)
        return self._timeout or HttpInvoker.DefaultTimeoutMillisecond;
    end
});
HttpInvoker.stor({
    --[[
        Desc:   参数是否进行URL编码（默认即为false）。
        Param:  bool        指示在请求时是否编码参数。
    ]]
    EncodeParams = function(self,val)
        self._encodeParams = syx.Boolean(val);
    end,
    --[[
        Param:  number          超时时间，毫秒
    ]]
    Timeout = function(self,val)
        self._timeout = syx.Integer(val);
    end,
    Params = function(self,val)
        val = val or {};
        self._params = {};
        self:AddParams(val);
    end,
    Header = function(self,val)
        self._header = val or {};
    end,
    ResponseType = function(self,val)
        self._responseType = val or cc.XMLHttpRequest.ResponseType.STRING;
    end,
    Retry = function(self,val)
        self._retry = syx.Integer(val);
    end,
    Async = function(self,val)
        self._async = syx.Boolean(val);
    end,
});

return HttpInvoker