--[[

Copyright (c) 2014-2017 Chukong Technologies Inc.

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
local getmetatable = getmetatable;
local setmetatable = setmetatable;
local rawset = rawset;
local tolua = tolua;
local pairs = pairs;
local ipairs = ipairs;
local assert = assert;
local error = error;
local type = type;
local Handler = require("Handler");

class = {};

-- 在cls中查找gtor的对应值。
local function seekIn_get_set(cls,key,stackSuper,method)
    local gs = cls[method];
    local ret = gs[key];
    if ret then
        return ret;
    end
    if stackSuper then
        for _,sp in ipairs(stackSuper) do
            ret = sp[method];
            if ret then
                ret = ret[key];
                if ret then
                    return ret;
                end
            end
        end
    end
end

local function setmetatable_T(t,cls,ori_t)
    local mt = getmetatable(t) or {};
    if not mt.__index then
        mt.__index = function(_,key)
            local sS = rawget(ori_t,"__stackSupers");
            local ret = seekIn_get_set(cls,key,sS,".get");
            if ret then
                return ret(t);
            end
            ret = cls[key];
            if ret then
                return ret;
            end
            if sS then
                for _,sp in ipairs(sS) do
                    ret = sp[key];
                    if ret then
                        return ret;
                    end
                end
            end
        end
        mt.__newindex = function(_,key,value)
            local sS = rawget(ori_t,"__stackSupers");
            local ret = seekIn_get_set(cls,key,sS,".set");
            if ret then
                ret(t,value);
            else
                rawset(t,key,value);
            end
        end
        setmetatable(t,mt);
    elseif mt.__index ~= cls then
        setmetatable_T(mt,cls,t);
    end
end

local function setmetatable_U(u,cls,peer,ori_peer)
    local mt = getmetatable(peer) or {};
    if not mt.__index then
        mt.__index = function(_,key)
            local sS = rawget(ori_peer,"__stackSupers");
            local ret = seekIn_get_set(cls,key,sS,".get");
            if ret then
                return ret(u);
            end
            ret = cls[key];
            if ret then
                return ret;
            end
            if sS then
                for _,sp in ipairs(sS) do
                    ret = sp[key];
                    if ret then
                        return ret;
                    end
                end
            end
        end
        setmetatable(peer, mt)
    elseif mt.__index ~= cls then
        setmetatable_U(u,cls,mt,ori_peer);
    end
end

local function _setmetatable(t, cls)
    if type(t) == "userdata" then
        local peer = tolua.getpeer(t);
        if not peer then
            peer = {};
            tolua.setpeer(t, peer);
        end
        setmetatable_U(t,cls,peer,peer);
    else
        setmetatable_T(t,cls,t);
    end
    return t;
end

setmetatable(class,{
    __metatable = "Can't visit the metatable.",
    __call = function(c,...)
		return c.New(...)
	end
})

local defaultEmptyCtor = function()end

local handlerMetaTable = {
    __newindex = function(t,key,value)
        assert("string" == type(key) and key:sub(1,2) == "On","Invalid key.");
        assert("function" == type(value),"Event handler must be a function.");
        rawset(t,key,value);
    end
};

local deleteFunction = function(self)
    local dtor = self.dtor;
    local ret = nil;
    if dtor then
        ret = dtor(self);
    end
    if type(self) == "userdata" then
        if not ret then
            -- dtor返回true时，跳过原delete的调用。
            local mt = getmetatable(self);
            if mt then
                local d = mt.delete;
                if d then
                    d(self);
                end
            end
        end
    else
        self["._isnull"] = true;
    end
end

local classCreateLayer = 0;
local Singleton = {};
class.Singleton = Singleton;
function class.New(...)
    local className = "";
    local args = {...};
    if "string" == type(args[1]) then
        className = table.remove(args,1);
    end

    local cls = {
        __cname = className,
        __supers = {},
        [".get"] = {},
        [".set"] = {},

        __allSupers = {},

        -- 事件处理表。
        Handler = {},
        isSingleton = false
    };
    local cStor = cls[".set"];
    local cGtor = cls[".get"];
    for _, super in ipairs(args) do
        local superType = type(super);
        -- 基类只能是table或function。
        assert(
            superType == "table" or superType == "function",
            ([[class() - create class "%s" with invalid super class type "%s"]]):
            format(className,superType)
        );
        if super == Singleton then
            cls[".call"] = function(_,...)
                local obj = Singleton[cls];
                if class.IsNull(obj) then
                    obj = cls.__new__(...);
                    Singleton[cls] = obj;
                end
                return obj;
            end;
            cls.isSingleton = true;
        else
            if superType == "function" then
                -- 只能拥有一个__create函数。
                assert(
                    cls.__create == nil,
                    ([[class() - create class "%s" with more than one creating function]]):
                    format(className)
                );
                -- if super is function, set it to __create
                cls.__create = super;
            elseif superType == "table" then
                if super[".isclass"] then
                    -- 基类并非当前函数生成，只将其create函数设置为类的__create函数，
                    -- 并保证只能拥有一个__create函数。
                    -- super is native class
                    assert(
                        cls.__create == nil,
                        ([[class() - create class "%s" with more than one creating function or native class]]):
                        format(className)
                    );
                    cls.__create = super.new;
                end
                -- super is pure lua class
                cls.__supers[#cls.__supers + 1] = super;

                -- 加入__allSupres，以快速查找所有基类。
                if super.__allSupers then
                    for k,v in pairs(super.__allSupers) do
                        cls.__allSupers[k] = v;
                    end
                end
                local sStor = super[".set"];
                if sStor then
                    for k,v in pairs(sStor) do
                        cStor[k] = v;
                    end
                end
                local gGtor = super[".get"];
                if gGtor then
                    for k,v in pairs(gGtor) do
                        cGtor[k] = v;
                    end
                end
                cls.__allSupers[super] = true;

                local h = rawget(super,"Handler");
                if h then
                    for hdr,func in pairs(h) do
                        cls.Handler[hdr] = func;
                    end
                end
            else
                error(([[class() - create class "%s" with invalid super type]]):format(className),0);
            end
        end
    end

    cls.__index = cls;
    setmetatable(
        cls,
        {
            __index = function(_, key)
                for _, super in ipairs(cls.__supers) do
                    local ret = super[key];
                    if ret ~= nil then
                        rawset(cls,key,ret);
                        return ret;
                    end
                end
            end,
            __call = cls.isSingleton and function(self,...)
                return rawget(self,".call")(self,...);
            end or nil
        }
    );

    if not cls.ctor then
        -- add default constructor
        cls.ctor = defaultEmptyCtor;
    end
    cls.new = function(...)
        classCreateLayer = classCreateLayer + 1;
        local instance = cls.__create and cls.__create(...) or {};
        assert(instance,"Invalid Creator.");

        if classCreateLayer == 1 then
            _setmetatable(instance,cls);
            local regHandler = {};
            for key,func in pairs(cls.Handler) do
                if not regHandler[key] then
                    Handler.On(key:sub(3),instance,func);
                    regHandler[key] = true;
                end
            end
            for super,_ in pairs(cls.__allSupers) do
                local handler = rawget(super,"Handler");
                if handler then
                    for key,func in pairs(handler) do
                        if not regHandler[key] then
                            Handler.On(key:sub(3),instance,func);
                            regHandler[key] = true;
                        end
                    end
                end
            end
        else
            instance.__stackSupers = instance.__stackSupers or {};
            table.insert(instance.__stackSupers,1,cls);
        end
        local tempCreateLayer = classCreateLayer;
        classCreateLayer = 0;
        if type(instance) == "userdata" then
            local peer = tolua.getpeer(instance);
            if not peer then
                peer = {};
                tolua.setpeer(instance, peer);
            end
            local sS = instance.__stackSupers;
            if sS then
                -- 若以function为构造继承一个pure lua class，".cls.set"不能使用引用，而是使用复制，且将不能
                -- 直接继承的类的".set"赋值到peer的".cls.set"。
                local cT = {};
                for m,st in pairs(cls[".set"]) do
                    cT[m] = st;
                end
                for _,sp in ipairs(sS) do
                    for m,st in pairs(sp[".set"]) do
                        cT[m] = st;
                    end
                end
                rawset(peer,".cls.set",cT);
            else
                rawset(peer,".cls.set",cls[".set"]);
            end
        end
        cls.ctor(instance,...);
        classCreateLayer = classCreateLayer + tempCreateLayer - 1;
        return instance;
    end;
    if cls.isSingleton then
        cls.__new__ = cls.new;
    end
    cls.delete = deleteFunction;
    cls.gtor = function(tFunc)
        for k,v in pairs(tFunc) do
            rawset(cls[".get"],k,v);
        end
    end;
    cls.stor = function(tFunc)
        for k,v in pairs(tFunc) do
            rawset(cls[".set"],k,v);
        end
    end;
    cls.is = function(obj_cls,_cls)
        if nil == _cls then
            _cls = obj_cls;
        end
        return _cls == cls or cls.__allSupers[_cls];
    end;
    cls.class = function(_)
        return cls;
    end;

    setmetatable(cls.Handler,handlerMetaTable);

    return cls;
end

function class.Handler(obj, method)
    return function(...)
        return method(obj, ...);
    end
end

local isnull = tolua.isnull;
class.IsNull = function(t)
    if type(t) == "table" then
        return rawget(t,"._isnull");
    else
        return isnull(t);
    end
end