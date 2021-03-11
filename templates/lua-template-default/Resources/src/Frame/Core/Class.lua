--[[

Copyright (c) 2014-2017 Chukong Technologies Inc.
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
local getmetatable = getmetatable;
local setmetatable = setmetatable;
local rawset = rawset;
local pairs = pairs;
local ipairs = ipairs;
local assert = assert;
local type = type;
local Handler = require("Handler");

_G.class = {};

-- 该表中的元方法，必须实现对应的处理函数，才能使用。
local MetaNeedImpl = {
    __add__ = "__add",
    __sub__ = "__sub",
    __mul__ = "__mul",
    __mod__ = "__mod",
    __pow__ = "__pow",
    __div__ = "__div",
    __idiv__ = "__idiv",
    __band__ = "__band",
    __bor__ = "__bor",
    __bxor__ = "__bxor",
    __shl__ = "__shl",
    __shr__ = "__shr",
    __unm__ = "__unm",
    __bnot__ = "__bnot",
    __lt__ = "__lt",
    __le__ = "__le",
    __concat__ = "__concat",
    __call__ = "__call"
};

local ObjMeta = {};
-- __eq元方法，可以不实现。
ObjMeta.__eq = function (...)
    for _,sender in {...} do
        local __eq = sender.__eq__;
        if __eq then
            return __eq(...);
        end
    end
    return false;
end
-- __gc元方法，可以不实现。
ObjMeta.__gc = function (sender)
    local __gc = sender.__gc__;
    if __gc then
        __gc(sender);
    end
end
-- __pairs元方法，可以不实现，采用默认实现。
ObjMeta.__pairs = function (sender)
    local __pairs = sender.__pairs__;
    if __pairs then
        return __pairs(sender);
    end
    return function(t,key)
        local value = nil;
        key,value = next(t,key);
        return key,value;
    end,sender,nil
end
-- __len元方法，可以不实现，采用默认实现。
ObjMeta.__len = function (sender)
    local __len = sender.__len__;
    if __len then
        return __len(sender);
    end
    return rawlen(sender);
end
for key, value in pairs(MetaNeedImpl)do
    ObjMeta[value] = function (sender,...)
        local meta = sender[key];
        if "function" == type(meta) then
            return meta(sender,...);
        end
        error("You must implement the " .. key .. " meta-method.");
    end
end
local function MakeObjMetaTable_T(cls)
    local meta = {};
    for k,v in ObjMeta do
        meta[k] = v
    end
    meta.__index = function (sender,key)
        local ret = rawget(cls,key);
        if ret then
            return ret;
        end
        local cMeta = getmetatable(cls);
        return cMeta.__index(sender,key);
    end;
    meta.__newindex = function (sender,key,value)
        local cMeta = getmetatable(cls);
        cMeta.__newindex(sender,key,value);
    end;
    return meta;
end

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
        setmetatable(t,MakeObjMetaTable_T(cls));
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
    if dtor then
        dtor(self);
    end
    self["._isnull"] = true;
end

local classCreateLayer = 0;
function class.New(...)
    local args = {...};
    local cls = {
        -- 表示事件处理表。
        Handler = sol.Debug and setmetatable({},handlerMetaTable) or {},
        -- 表示该类的所有直接基类（已排序）。
        __bases__ = {},
        -- 表示该类的sol::usertype基类（也是唯一的sol::usertype基类）。
        __cpp_base__ = nil
    };
    -- 检查只读只写属性。
    for _,rw in pairs({"__r__","__w__"}) do
        cls[rw] = setmetatable({},{
            __index = function (_,key)
                local cppBase = rawget(cls,"__cpp_base__");
                for __,bCls in cls.__bases__ do
                    if bCls ~= cppBase then
                        local ret = bCls[rw][key];
                        if ret then
                            return ret
                        end
                    end
                end
                -- todo 检查__cpp_base__？
                return nil;
            end
        });
    end

    for _, base in ipairs(args) do
        local baseType = type(base);
        -- 基类只能是table或function。
        assert(baseType == "table" or baseType == "function","Base classes must be a table or function!");
        if baseType == "function" then
            -- 只能拥有一个__create函数。
            assert(cls.__create == nil,"Class with more than one creating function!");
            cls.__create = base;
        else
            local __name = rawget(base,"__name")
            -- sol::usertype名字中带有"sol."
            if __name and name:find("sol.") then
                -- 基类并非当前函数生成（可能是sol::usertype类型），只将其new函数设置为类的__create函数，
                -- 并保证只能拥有一个__create函数。
                assert(cls.__create == nil,"Class with more than one creating function or native class!");
                local new = base.new;
                if new then
                    cls.__create = new;
                end
                cls.__cpp_base__ = base
            else
                local __create = rawget(base,"__create")
                if __create then
                    assert(cls.__create == nil,"Class with more than one creating function!");
                    cls.__create = __create;
                end

                -- 继承基类的Handler处理函数。
                for hdr,func in pairs(base.Handler) do
                    cls.Handler[hdr] = func;
                end
            end

            -- 只要基类有任意的sol::usertype类型，都将传递下去。
            local __cpp_base__ = rawget(base,"__cpp_base__")
            if __cpp_base__ then
                cls.__cpp_base__ = __cpp_base__;
            end
            -- 加入多继承表。
            table.insert(cls.__bases__,base)
        end
    end

    if not cls.ctor then
        -- 添加默认构造（空构造）。
        cls.ctor = defaultEmptyCtor;
    end
    if not cls.__cpp_base__ then
        -- 只为纯lua类提供delete的实现。
        cls.delete = deleteFunction;
    end

    setmetatable(cls,{
        __index = function(sender, key)
            local property = cls.__r__[key];
            if property then
                return property(sender);
            end
            for _, base in ipairs(cls.__bases__) do
                local ret = base[key];
                if ret ~= nil then
                    -- 此处缓存，加快下次访问。
                    rawset(sender,key,ret);
                    return ret;
                end
            end
        end,
        __newindex = function (sender,key,value)
            if key == "__properties__" then
                if "function" == type(value) then
                    value = value(cls);
                end
                for __rw__,rw in pairs({__r__ = "r",__w__ = "w"}) do
                    for k,v in pairs(value[rw]) do
                        cls[__rw__][k] = v;
                    end
                end
            else
                local property = cls.__w__[key];
                if property then
                    property(sender,value);
                    return
                end
                rawset(sender,key,value);
            end
        end
    });

    cls.new = function(...)
        classCreateLayer = classCreateLayer + 1;
        local instance = cls.__create and cls.__create(...) or {};
        assert(instance,"Invalid Creator.");

        if classCreateLayer == 1 then
            _setmetatable(instance,cls);
            for key,func in pairs(cls.Handler) do
                -- 自动监听事件。
                Handler.On(key:sub(3),instance,func);
            end
        end
        local tempCreateLayer = classCreateLayer;
        classCreateLayer = 0;
        cls.ctor(instance,...);
        classCreateLayer = classCreateLayer + tempCreateLayer - 1;
        return instance;
    end;

    return cls;
end

function class.Handler(obj, method)
    return function(...)
        return method(obj, ...);
    end
end

local isnull = sol.Null;
class.IsNull = function(t)
    if type(t) == "table" then
        return rawget(t,"._isnull");
    else
        return isnull(t);
    end
end