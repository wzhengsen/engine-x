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

--[[
    级联获取某个类及其基类的对应键的值（忽略元方法）。
]]
local function CascadeGet(cls,key)
    local ret = rawget(cls,key);
    if nil ~= ret then
        return ret;
    end
    for _,base in pairs(cls.__bases__) do
        ret = CascadeGet(base,key);
        if nil ~= ret then
            return ret;
        end
    end
end

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

--[[为纯lua类产生的table类型的对象指定一个元表。
]]
local function MakeLuaObjMetaTable(cls)
    local meta = {
        __index = function (sender,key)
            -- 先检查当前类型的对应键。
            local ret = rawget(cls,key);
            if nil ~= ret then
                return ret;
            end
            -- 检查属性。
            local property = cls.__r__[key];
            if property then
                return property(sender);
            else
                if cls.__w__[key] then
                    -- 不能读取只写属性。
                    error("You can't read a write-only property.")
                end
            end
            -- 检查基类。
            for _, base in ipairs(cls.__bases__) do
                ret = CascadeGet(base,key);
                if nil ~= ret then
                    -- 此处缓存，加快下次访问。
                    rawset(sender,key,ret);
                    return ret;
                end
            end
        end,
        __newindex = function (sender,key,value)
            local property = cls.__w__[key];
            if property then
                property(sender,key,value);
                return
            else
                if cls.__r__[key] then
                    -- 不能写入只读属性。
                    error("You can't write a read-only property.")
                end
            end
            rawset(sender,key,value);
        end
    };
    for k,v in pairs(ObjMeta) do
        meta[k] = v;
    end
    return meta;
end

--[[
    改造sol::usertype的元表，以适应lua-class的混合继承模式。
]]
local function RetrofitMeta(ud)
    local meta = getmetatable(ud);
    local retrofited = rawget(meta,"__lua_retrofit");
    -- 已改造过，跳过。
    if retrofited then
        return
    end
    local index = rawget(meta,"__index");
    local newIndex = rawget(meta,"__newindex");
    rawset(meta,"__index",function (sender,key)
        local uv,_ = debug.getuservalue(sender);
        -- 获取预先保存的lua类信息。
        local cls = uv.__cls__;
        if cls then
            -- 如果存在lua类的继承。
            --检查直接类的普通方法和成员等。
            local ret = rawget(cls,key);
            if nil ~= ret then
                return ret;
            end
            -- 检查属性。
            local property = cls.__r__[key];
            if property then
                return property(sender);
            else
                if cls.__w__[key] then
                    -- 不能读取只写属性。
                    error("You can't read a write-only property.")
                end
            end
            -- 检查基类。
            for _, base in ipairs(cls.__bases__) do
                ret = CascadeGet(base,key);
                if nil ~= ret then
                    -- 此处缓存，加快下次访问。
                    rawset(uv,key,ret);
                    return ret;
                end
            end
        end
        -- 最后检查sol::usertype定义的元方法。
        return index(sender,key);
    end);
    rawset(meta,"__newindex",function (sender,key,val)
        local uv,_ = debug.getuservalue(sender);
        -- 获取预先保存的lua类信息。
        local cls = uv.__cls__;
        if cls then
            local property = cls.__w__[key];
            if property then
                property(sender,key,val);
                return
            else
                if cls.__r__[key] then
                    -- 不能写入只读属性。
                    error("You can't write a read-only property.")
                end
            end
        end
        -- 最后检查sol::usertype定义的元方法。
        newIndex(sender,key,val);
    end);

    rawset(meta,"__lua_retrofit",true);
end

setmetatable(class,{
    __metatable = "Can't visit the metatable.",
    __call = function(c,...)
        return c.New(...)
    end
})

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
    setmetatable(self,nil);
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
        __cpp_base__ = nil,

        -- function构造器在继承列表的索引，一旦该类型被构造过一次，
        -- 这个字段将失效。
        __fCtorIdx__ = nil
    };
    -- 检查只读只写属性。
    for _,rw in pairs({"__r__","__w__"}) do
        cls[rw] = setmetatable({},{
            __index = function (_,key)
                for __,base in pairs(cls.__bases__) do
                    local ret = base[rw][key];
                    if nil ~= ret then
                        return ret
                    end
                end
            end
        });
    end

    for idx, base in ipairs(args) do
        local baseType = type(base);
        -- 基类只能是table或function。
        assert(baseType == "table" or baseType == "function","Base classes must be a table or function!");
        if baseType == "function" then
            -- 只能拥有一个__create函数。
            assert(cls.__create == nil,"Class with more than one creating function!");
            cls.__create = base;
            cls.__fCtorIdx__ = idx;
        else
            local __name = rawget(base,"__name");
            -- sol::usertype名字中带有"sol."
            if __name and __name:find("sol.") then
                -- 基类并非当前函数生成（可能是sol::usertype类型），只将其new函数设置为类的__create函数，
                -- 并保证只能拥有一个__create函数。
                assert(cls.__create == nil,"Class with more than one creating function or native class!");
                local new = base.new;
                if new then
                    cls.__create = new;
                end
                cls.__cpp_base__ = base;
            else
                local __create = rawget(base,"__create");
                if __create then
                    assert(cls.__create == nil,"Class with more than one creating function!");
                    -- 当具有__fCtorIdx__值时，表示基类使用了function构造器，
                    -- 将cls.__create赋值为base.new，以递归调用，以便将function构造器的所属类返回到base。
                    if rawget(base,"__fCtorIdx__") then
                        cls.__create = base.new;
                    else
                        cls.__create = __create;
                    end
                end

                -- 继承基类的Handler处理函数。
                for hdr,func in pairs(base.Handler) do
                    cls.Handler[hdr] = func;
                end

                -- 加入多继承表。
                table.insert(cls.__bases__,base)
            end
        end
    end

    if not cls.__cpp_base__ then
        -- 只为纯lua类提供delete的实现。
        cls.delete = deleteFunction;
    end

    local meta = MakeLuaObjMetaTable(cls);
    -- is方法，可以用于判断对象是否继承于某类。
    -- 如果不传入参数，返回当前所属类。
    cls.is = function(owner)
        local tOwner = type(owner);
        if "nil" == tOwner then
            return cls;
        else
            if owner == cls then
                return true;
            end
            for _,bCls in pairs(cls.__bases__) do
                if bCls.is(owner) then
                    return true;
                end
            end
            if cls.__cpp_base__ then
                return cls.__cpp_base__.is(owner);
            end
        end
        return false;
    end;
    if not cls.__cpp_base__ or cls.__create then
        -- 一个没有new方法的sol::usertype类型，不能接受实例化。
        cls.new = function(...)
            classCreateLayer = classCreateLayer + 1;
            --[[
                此处，需要考虑多重function构造的情况，如：
                local C1 = class();
                local C2 = class(function()return C1.new();end);
                local C3 = class(C2);
                local C4 = class(function()return C3.new();end);
                在此继承关系下，由于没有明确指明C4和C2的基类，
                所以不能直接按__bases__字段查询，需要获取返回的基类类型，将其加入到__bases__。

                由于一个function构造器被设计为返回同一种类型，所以，不要使用如下继承方式：
                local E1 = class();
                local E2 = class();
                local E3 = class(function(case)
                    if case == 1 then
                        reutrn E1.new();
                    else
                        return E2.new();
                    end
                );--在这种情况下，可能引起奇怪的问题。
            ]]
            local instance = nil;
            local __create = cls.__create;
            if __create then
                instance = cls.__create(...);
                local __fCtorIdx__ = rawget(cls,"__fCtorIdx__");
                if __fCtorIdx__ then
                    local preCls = instance.__cls__;
                    if preCls then
                        -- 将function构造器所属类插入多继承表后，__fCtorIdx__便可以不再使用。
                        rawset(cls,"__fCtorIdx__",nil);
                        table.insert(cls.__bases__,__fCtorIdx__,preCls);
                    end
                end
            else
                instance = {};
            end
            assert(instance,"Invalid Creator.");

            local instType = type(instance);
            if classCreateLayer == 1 then
                if "table" == instType then
                    -- able返回类型的实例不需要最后的cls信息（metatable中和upvalue中已包含）。
                    instance.__cls__ = nil;
                    setmetatable(instance,meta);
                else
                    -- userdata返回类型的实例需要最后的cls信息。
                    local uv,_ = debug.getuservalue(instance);
                    uv.__cls__ = cls;
                    uv.is = cls.is;
                    RetrofitMeta(instance);
                end
                for key,func in pairs(cls.Handler) do
                    -- 自动监听事件。
                    Handler.On(key:sub(3),instance,func);
                end
            else
                if "table" == instType then
                    -- 将cls一并返回，可以指示function构造器所属类。
                    instance.__cls__ = cls;
                end
            end

            local ctor = cls.ctor;
            if ctor then
                -- 避免在ctor中再次new一个新的对象时递归污染classCreateLayer变量，
                -- 在此缓存，调用后，将其设置为classCreateLayer+tempCreateLayer
                -- 最终调用结束，将值-1。
                local tempCreateLayer = classCreateLayer;
                classCreateLayer = 0;
                cls.ctor(instance,...);
                classCreateLayer = classCreateLayer + tempCreateLayer - 1;
            else
                classCreateLayer = classCreateLayer - 1;
            end
            return instance;
        end;
    end

    setmetatable(cls,{
        __index = function(sender, key)
            -- 检查属性。
            local property = cls.__r__[key];
            if property then
                return property(sender);
            else
                if cls.__w__[key] then
                    -- 不能读取只写属性。
                    error("You can't read a write-only property.")
                end
            end
            -- 检查基类。
            for _, base in ipairs(cls.__bases__) do
                local ret = CascadeGet(base,key);
                if nil ~= ret then
                    -- 此处缓存，加快下次访问。
                    rawset(sender,key,ret);
                    return ret;
                end
            end
            -- 此时可以尝试查找__cpp_base__
            local __cpp_base__ = rawget(cls,"__cpp_base__");
            if __cpp_base__ then
                return __cpp_base__[key];
            end
        end,
        __newindex = function (sender,key,value)
            if key == "__properties__" then
                if "function" == type(value) then
                    value = value(cls);
                end
                for __rw__,rw in pairs({__r__ = "r",__w__ = "w"}) do
                    local subT = value[rw];
                    if subT then
                        for k,v in pairs(subT) do
                            cls[__rw__][k] = v;
                        end
                    end
                end
            else
                local property = cls.__w__[key];
                if property then
                    property(sender,key,value);
                    return
                else
                    if cls.__r__[key] then
                        -- 不能写入只读属性。
                        error("You can't write a read-only property.")
                    end
                end
                rawset(sender,key,value);
            end
        end
    });

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
