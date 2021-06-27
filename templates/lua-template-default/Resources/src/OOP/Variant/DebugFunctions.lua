-- Copyright (c) 2021 榆柳松
-- https://github.com/wzhengsen/LuaOOP

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

local getmetatable = getmetatable;
local rawset = rawset;
local rawget = rawget;
local type = type;
local pairs = pairs;
local ipairs = ipairs;

local Config = require("OOP.Config");
local Version = Config.Version;
local i18n = require("OOP.i18n");

local Compat = require("OOP.Version.Compat");
local bits = Compat.bits;
local band = bits.band;
local FunctionWrapper = Compat.FunctionWrapper;

local E_Handlers = require("OOP.Event").handlers;

local R = require("OOP.Router");
local Router = R.Router;
local BitsMap = R.BitsMap;
local Permission = R.Permission;
local Begin = R.Begin;

local __cls__ = Config.__cls__;
local new = Config.new;
local delete = Config.delete;
local is = Config.is;
local ctor = Config.ctor;
local dtor = Config.dtor;
local __new__ = Config.__new__;
local __delete__ = Config.__delete__;

local static = Config.Qualifiers.static;
local get = Config.get;
local set = Config.set;

local friends = Config.friends;
local __singleton__ = Config.__singleton__;
local Instance = Config.Instance;
local handlers = Config.handlers;
local Meta = Config.Meta;

local DeathMarker = Config.DeathMarker;

local MetaMapName = Config.MetaMapName;

local PropertyBehavior = Config.PropertyBehavior;
local ConstBehavior = Config.ConstBehavior;

local Functions = require("OOP.Variant.BaseFunctions");
local GetSingleton = Functions.GetSingleton;
local DestroySingleton = Functions.DestroySingleton;
local RetrofiteMetaMethod = Functions.RetrofiteMetaMethod;
local ClassInherite = Functions.ClassInherite;
local PushBase = Functions.PushBase;
local CreateClassObject = Functions.CreateClassObject;
local FinalClassesMembers = Functions.FinalClassesMembers;
local VirtualClassesMembers = Functions.VirtualClassesMembers;
local NamedClasses = Functions.NamedClasses;
local AllClasses = Functions.AllClasses;
local AllEnumerations = Functions.AllEnumerations;
local FinalClasses = Functions.FinalClasses;
local ClassesReadable = Functions.ClassesReadable;
local ClassesWritable = Functions.ClassesWritable;
local ClassesHandlers = Functions.ClassesHandlers;
local ClassesBases = Functions.ClassesBases;
local ClassesMembers = Functions.ClassesMembers;
local ClassesMetas = Functions.ClassesMetas;
local ClassesBanNew = Functions.ClassesBanNew;
local ClassesBanDelete = Functions.ClassesBanDelete;
local ClassesNew = Functions.ClassesNew;
local ClassesDelete = Functions.ClassesDelete;
local ObjectsAll = Functions.ObjectsAll;
local ObjectsCls = Functions.ObjectsCls;
local CreateClassTables = Functions.CreateClassTables;

local ClassesAll = Functions.ClassesAll;
local ClassesPermisssions = Functions.ClassesPermisssions;
local ClassesFriends = Functions.ClassesFriends;
local AccessStack = Functions.AccessStack;

local ReservedWord = Functions.ReservedWord;

---Cascade to get permission values up to the top of the base class.
---
---@param self table
---@param key any
---@return table,integer
---
local function CascadeGetPermission(self,key)
    local pms = ClassesPermisssions[self];
    local pm = pms and pms[key] or nil;
    local cls = self;
    if nil == pm then
        local bases = ClassesBases[self];
        if bases then
            for _,base in ipairs(bases) do
                cls,pm = CascadeGetPermission(base,key);
                if nil ~= pm then
                    return cls,pm;
                end
            end
        end
    end
    return cls,pm;
end

---When a member is accessed directly as a class,
---the members will be checked cascading.
---
---@param self table
---@param key any
---@param byObj boolean
---@param set? boolean
---@return boolean
---
local function CheckPermission(self,key,byObj,set)
    local cls,pm = CascadeGetPermission(self,key);
    if not pm then
        return true;
    end

    if byObj and band(pm,Permission.static) ~= 0 then
        error((i18n"Objects cannot access static members of a class. - %s"):format(key));
    end
    if set then
        if band(pm,Permission.const) ~= 0 then
            -- Check const.
            if ConstBehavior ~= 2 then
                if ConstBehavior == 0 then
                    if Version > 5.4 then
                        warn(("You cannot change the const value. - %s"):format(key));
                    end
                elseif ConstBehavior == 1 then
                    error((i18n"You cannot change the const value. - %s"):format(key));
                end
                return false;
            end
        end
        -- When a class performs a set operation,
        -- even if the operation is on a private member,
        -- it is considered to be a redefinition and the operation is not disabled.
        if not byObj then
            return true;
        end
    end

    local stackCls = AccessStack[#AccessStack];
    local _friends = ClassesFriends[cls];
    --Check if it is a friendly class.
    if not _friends or (not _friends[stackCls] and not _friends[NamedClasses[stackCls]]) then
        if band(pm,Permission.public) == 0 then
            -- Check public,private,protected.
            if stackCls ~= cls then
                if band(pm,Permission.private) ~= 0 then
                    error((i18n"Attempt to access private members outside the permission. - %s"):format(key));
                elseif band(pm,Permission.protected) ~= 0 and (not stackCls or not stackCls.is(cls)) then
                    error((i18n"Attempt to access protected members outside the permission. - %s"):format(key));
                end
            end
        end
    end
    return true;
end

Functions.CheckPermission = CheckPermission;

---Cascade to get the value of the corresponding key of a class and its base class
---(ignoring metamethods).
---
---@param cls table
---@param key any
---@param called table
---@return any
---
local function CascadeGet(cls,key,called)
    if called[cls] then
        return nil;
    end
    called[cls] = true;
    local all = ClassesAll[cls];
    if nil ~= all then
        local ret = all[key];
        if nil ~= ret then
            return ret;
        end
        local bases = ClassesBases[cls];
        if bases then
            for _,base in ipairs(bases) do
                ret = CascadeGet(base,key,called);
                if nil ~= ret then
                    return ret;
                end
            end
        end
    else
        return cls[key];
    end
end

local HandlersControl = setmetatable({
    obj = nil
},{
    __newindex = function (hc,key,value)
        if nil == hc.obj then
            return;
        end
        if "string" ~= type(key) then
            error((i18n"The key of the object's %s must be a string"):format(handlers));
        end
        local vt = type(value);
        if value ~= nil and "number" ~= vt then
            error((i18n"The object's %s can only accpet number or nil."):format(handlers));
        end
        if nil == value then
            -- If value is nil,we remove the response of this event name.
            E_Handlers.Remove(key,hc.obj);
        else
            -- If value is a number,we sort it.
            E_Handlers.Order(key,hc.obj,math.floor(value));
        end
    end
});

local function GetAndCheck(cls,key,sender,metas)
    if key == handlers then
        rawset(HandlersControl,"obj",sender);
        return HandlersControl;
    end
    local cCls = nil;
    if metas and "userdata" == type(sender) then
        cCls = ObjectsCls[sender];
        if not cCls then
            cCls = metas[__cls__];
            ObjectsCls[sender] = cCls;
        end
    else
        cCls = cls;
    end
    if not CheckPermission(cCls,key,true) then
        return nil;
    end
    -- Check self __all__ first.
    local all = ObjectsAll[sender];
    if nil == all then
        all = {};
        ObjectsAll[sender] = all;
    end
    local ret = all[key];
    if nil ~= ret then
        return ret;
    end
    -- Check the key of current class.
    ret = rawget(cCls,key);
    if nil ~= ret then
        return ret;
    end
    -- Check the properties of current class.
    local property = ClassesReadable[cCls][key];
    if property then
        return property[1](sender);
    else
        if ClassesWritable[cCls][key] then
            if PropertyBehavior ~= 2 then
                if PropertyBehavior == 0 then
                    if Version > 5.4 then
                        warn(("You can't read a write-only property. - %s"):format(key));
                    end
                elseif PropertyBehavior == 1 then
                    error((i18n"You can't read a write-only property. - %s"):format(key));
                end
                return nil;
            end
        end
    end
    -- Check current class.
    ret = ClassesAll[cCls][key];
    if nil ~= ret then
        return ret;
    end
    -- Check bases.
    for _, base in ipairs(ClassesBases[cCls]) do
        ret = CascadeGet(base,key,{});
        if nil ~= ret then
            return ret;
        end
    end
end

---
---Generate a meta-table for an object (typically a table) generated by a pure lua class.
---
---@param cls table
---@param metas? table
---@return table
---
function Functions.MakeInternalObjectMeta(cls,metas)
    ClassesMetas[cls] = metas;
    metas.__index = function (sender,key)
        return GetAndCheck(cls,key,sender,metas);
    end;
    metas.__newindex = function (sender,key,value)
        local isUserData = "userdata" == type(sender);
        local cCls = nil;
        if isUserData then
            cCls = ObjectsCls[sender];
            if not cCls then
                cCls = metas[__cls__];
                ObjectsCls[sender] = cCls;
            end
        else
            cCls = cls;
        end
        if not CheckPermission(cCls,key,true,true) then
            return;
        end
        local property = ClassesWritable[cCls][key];
        if property then
            property[1](sender,value);
            return;
        else
            if ClassesReadable[cCls][key] then
                if PropertyBehavior ~= 2 then
                    if PropertyBehavior == 0 then
                        if Version > 5.4 then
                            warn(("You can't write a read-only property. - %s"):format(key));
                        end
                    elseif PropertyBehavior == 1 then
                        error((i18n"You can't write a read-only property. - %s"):format(key));
                    end
                    return;
                end
            end
        end
        local all = ObjectsAll[sender];
        if nil == all then
            all = {};
            ObjectsAll[sender] = {};
        end
        rawset(all,key,value);
    end
    return metas;
end

---
--- Retrofit userdata's meta-table to fit lua-class's hybrid inheritance pattern.
---
---@param obj userdata
---
local function RetrofiteUserDataObjectMetaExternal(obj,meta,cls)
        -- Unlike the normal table type, which saves meta-tables directly in ClassesMetas[cls].
    -- The userdata type, on the other hand, gets its own meta-table and then retrofites this meta-table.
    -- The retrofited meta-table is saved in ClassesMetas[meta] and __index and __newindex are unique logic,
    -- other meta-methods are overridden.

    local found = ClassesMetas[meta];
    if found then
        -- It has been Retrofited,skip it.
        return;
    end

    local clsMeta = setmetatable(ClassesMetas[cls],{
        __newindex = function (sender,key,value)
            -- Copy the operation on clsMeta to meta.
            rawset(sender,key,value);
            RetrofiteMetaMethod(meta,key,value)
        end
    });
    for k,v in pairs(clsMeta) do
        if Meta[k] then
            RetrofiteMetaMethod(meta,k,v)
        end
    end

    local index = rawget(meta,"__index");
    local newIndex = rawget(meta,"__newindex");
    local indexFunc = "function" == type(index);
    local newIndexFunc =  "function" == type(newIndex);
    rawset(meta,"__index",function(sender,key)
        local cls = ObjectsCls[sender];
        if cls then
            local ret = GetAndCheck(cls,key,sender);
            if nil ~= ret then
                return ret;
            end
        end
        -- Finally, check the original method or table.
        if index then
            return indexFunc and index(sender,key) or index[key];
        end
    end);
    rawset(meta,"__newindex",function (sender,key,value)
        local cls = ObjectsCls[sender];
        if cls then
            if not CheckPermission(cls,key,true,true) then
                return;
            end
            local property = ClassesWritable[cls][key];
            if property then
                property[1](sender,value);
                return;
            else
                if ClassesReadable[cls][key] then
                    if PropertyBehavior ~= 2 then
                        if PropertyBehavior == 0 then
                            if Version > 5.4 then
                                warn(("You can't write a read-only property. - %s"):format(key));
                            end
                        elseif PropertyBehavior == 1 then
                            error((i18n"You can't write a read-only property. - %s"):format(key));
                        end
                        return;
                    end
                end
            end
            local all = ObjectsAll[sender];
            all[key] = value;
        end
        -- Finally, write by the original method.
        if not cls or newIndex then
            if newIndexFunc then
                newIndex(sender,key,value);
            elseif newIndex then
                newIndex[key] = value;
            else
                error((i18n"attempt to index a %s value."):format(meta.__name or ""));
            end
        end
    end);

    ClassesMetas[meta] = meta;
end

local function RetrofiteUserDataObjectMeta(obj,cls)
    local meta = getmetatable(obj);
    assert("table" == type(meta),i18n"The userdata to be retrofited must have a meta table.");
    -- Instances of the userdata type require the last cls information.
    -- Because multiple different lua classes can inherit from the same c++ class.
    ObjectsCls[obj] = cls;
    if nil == rawget(meta,__cls__) then
        RetrofiteUserDataObjectMetaExternal(obj,meta,cls);
    end
end

local function ClassGet(cls,key)
    if BitsMap[key] then
        return Begin(Router,cls,key);
    end
    if key == handlers then
        return ClassesHandlers[cls];
    end
    if not CheckPermission(cls,key,false) then
        return;
    end
    -- Check the properties first.
    local property = ClassesReadable[cls][key];
    if property then
        if property[2] then
            return property[1]();
        end
    else
        if ClassesWritable[cls][key] then
            if PropertyBehavior ~= 2 then
                if PropertyBehavior == 0 then
                    if Version > 5.4 then
                        warn(("You can't read a write-only property. - %s"):format(key));
                    end
                elseif PropertyBehavior == 1 then
                    error((i18n"You can't read a write-only property. - %s"):format(key));
                end
                return nil;
            end
        end
    end
    local ret = ClassesAll[cls][key];
    if nil ~= ret then
        return ret;
    end
    for _, base in ipairs(ClassesBases[cls]) do
        ret = CascadeGet(base,key,{});
        if nil ~= ret then
            return ret;
        end
    end
end

local function ClassSet(cls,key,value)
    -- The reserved words cannot be used.
    if ReservedWord[key] then
        error((i18n"%s is a reserved word and you can't set it."):format(key));
    end
    if FinalClassesMembers[cls][key] then
        error((i18n"You cannot define final members again. - %s"):format(key));
    end

    if key == friends then
        if "table" ~= type(value) then
            error((i18n"%s reserved word must be assigned to a table."):format(key));
        end
        local fri = {};
        ClassesFriends[cls] = fri;
        for _,v in ipairs(value) do
            fri[v] = true;
        end
        return;
    end

    local vt = type(value);
    local isFunction = "function" == vt;
    if key == __singleton__ then
        if not isFunction then
            error((i18n"%s reserved word must be assigned to a function."):format(key));
        end
        -- Register "Instance" automatically.
        cls[static][get][Instance] = function()
            return GetSingleton(cls,value);
        end;
        cls[static][set][Instance] = function(val)
            DestroySingleton(cls,val)
        end;
        -- Once register "__singleton__" for a class,set permission of "new","delete" method to protected.
        local pms = ClassesPermisssions[cls];
        local pm = pms[new];
        if band(pm,Permission.private) == 0 then
            pms[new] = Permission.static + Permission.protected;
        end
        pms[delete] = Permission.protected;
        return;
    elseif key == __new__ then
        if not isFunction then
            error((i18n"%s reserved word must be assigned to a function."):format(key));
        end
        ClassesNew[cls] = FunctionWrapper(cls,value);
        return;
    elseif key == __delete__ then
        if not isFunction then
            error((i18n"%s reserved word must be assigned to a function."):format(key));
        end
        ClassesDelete[cls] = FunctionWrapper(cls,value);
        return;
    else
        local vcm = VirtualClassesMembers[cls];
        if vcm[key] then
            -- Check pure virtual functions.
            if not isFunction then
                error((i18n"%s must be overridden as a function."):format(key));
            end
            vcm[key] = nil;
        else
            if not CheckPermission(cls,key,false,true) then
                return;
            end
            local property = ClassesWritable[cls][key];
            if property then
                if property[2] then
                    property[1](value);
                    return;
                end
            else
                if ClassesWritable[cls][key] then
                    if PropertyBehavior ~= 2 then
                        if PropertyBehavior == 0 then
                            if Version > 5.4 then
                                warn(("You can't write a read-only property. - %s"):format(key));
                            end
                        elseif PropertyBehavior == 1 then
                            error((i18n"You can't write a read-only property. - %s"):format(key));
                        end
                        return;
                    end
                end
            end
        end
        local all = ClassesAll[cls];
        local exist = all[key];
        if not exist then
            local isTable = "table" == vt;
            if not isFunction and (not isTable or (not AllEnumerations[value] and not AllClasses[value])) then
                ClassesMembers[cls][key] = value;
            end
            ClassesPermisssions[cls][key] = Permission.public;
        end
        if isFunction then
            -- Wrap this function to include control of access permission.
            value = FunctionWrapper(cls,value);
        end
        all[key] = value;
    end
    local meta = MetaMapName[key];
    if meta then
        local metas = ClassesMetas[cls];
        metas[meta] = value;
    end
end

Functions.RetrofiteUserDataObjectMeta = RetrofiteUserDataObjectMeta;
Functions.ClassSet = ClassSet;
Functions.ClassGet = ClassGet;

local function MakeClassHandlersTable(cls,handlers)
    return setmetatable(handlers,{
        __newindex = function(t,key,value)
            if not ("string" == type(key)) then
                error(i18n"The name of handler function must be a string.")
            end
            assert("function" == type(value),i18n"event handler must be a function.");
            -- Ensure that event response functions have access to member variables.
            rawset(t,key,FunctionWrapper(cls,value));
        end
    });
end

function Functions.CreateClassTables(cls)
    local all,bases,handlers,members,r,w = CreateClassTables(cls);

    MakeClassHandlersTable(cls,handlers);
    all = {}
    ClassesAll[cls] = all;
    ClassesPermisssions[cls] = {};
    FinalClassesMembers[cls] = {};
    VirtualClassesMembers[cls] = {};

    return all,bases,handlers,members,r,w;
end

function Functions.PushBase(cls,bases,base,handlers,members,metas)
    PushBase(cls,bases,base,handlers,members,metas);
    local fm = FinalClassesMembers[cls];
    local vm = VirtualClassesMembers[cls];
    local pms = ClassesPermisssions[base];
    if ClassesBanNew[base] then
        ClassesBanNew[cls] = true;
    elseif pms then
        local pm = pms[ctor];
        if pm and band(pm,Permission.private) ~= 0 then
            ClassesBanNew[cls] = true;
        end
    end

    if ClassesBanDelete[base] then
        ClassesBanDelete[cls] = true;
    elseif pms then
        local pm = pms[dtor];
        if pm and band(pm,Permission.private) ~= 0 then
            ClassesBanDelete[cls] = true;
        end
    end
    local fcm = FinalClassesMembers[base];
    if fcm then
        for k,_ in pairs(fcm) do
            fm[k] = true;
        end
    end

    local vcm = VirtualClassesMembers[base];
    if vcm then
        for k,_ in pairs(vcm) do
            vm[k] = true;
        end
    end
end

function Functions.ClassInherite(cls,args,bases,handlers,members,metas,name)
    for idx, base in ipairs(args) do
        local baseType = type(base);
        assert(
            baseType == "table"
            or baseType == "string",
            i18n"Unavailable base class type."
        );
        assert(not FinalClasses[base],i18n"You cannot inherit a final class.");
        for i,b in ipairs(args) do
            if b == base and idx ~= i then
                error(i18n"It is not possible to inherit from the same class repeatedly.");
            end
        end
    end
    ClassInherite(cls,args,bases,handlers,members,metas,name);
end

function Functions.DestroySingleton(cls,val)
    assert(nil == val,i18n"The nil value needs to be passed in to destory the object.");
    DestroySingleton(cls,val);
end

function Functions.CreateClassObject(...)
    local obj,all = CreateClassObject(...);
    if (nil ~= obj) and (obj == all) then
        all = {};
        ObjectsAll[obj] = all;
    end
    return obj,all;
end

--[[
    Cascade calls to dtor.
    @param self     The object that will be destructured.
    @param cls      The class to be looked up.
    @param called   Records which base classes have been called,See below:
                 X
                 |
                 A
                / \
               B   C
                \ /
                 D
    When you destruct the D object,
    to avoid repeated calls to the destructors of X and A that have been inherited multiple times,
    record the classes that have been called in "called".
]]
local function CascadeDelete(obj,cls,called)
    if called[cls] then
        return;
    end

    local pm = ClassesPermisssions[cls][dtor];
    if pm then
        local aCls = AccessStack[#AccessStack];
        local _friends = ClassesFriends[cls];
        if (not _friends or (not _friends[aCls] and not _friends[NamedClasses[cls]])) and
        (band(pm,Permission.public) == 0) and
        (aCls ~= cls) and
        (band(pm,Permission.private) ~= 0)then
            error((i18n"Attempt to access private members outside the permission. - %s"):format(dtor));
        end
    end

    -- Since the meta method is not triggered here,
    -- it is necessary to determine the permission in advance.
    local del = ClassesAll[cls][dtor];
    if del then
        del(obj);
    end
    called[cls] = true;

    local bases = ClassesBases[cls];
    if bases then
        for _,base in ipairs(bases) do
            CascadeDelete(obj,base,called);
        end
    end
end

function Functions.CallDel(self)
    CascadeDelete(self,self[is](),{});
    ObjectsAll[self] = nil;
end

function Functions.CreateClassDelete(cls)
    return function (self)
        local d = ClassesDelete[cls];
        if d then
            d(self);
        else
            CascadeDelete(self,cls,{});
            setmetatable(self,nil);
            self[DeathMarker] = true;
        end
        ObjectsAll[self] = nil;
    end
end

function Functions.AttachClassFunctions(cls,_is,_new,_delete)
    local all = ClassesAll[cls];
    local pms = ClassesPermisssions[cls];
    all[is] = _is;
    pms[is] = Permission.public;
    -- In debug mode,the "new" method is public and static.
    all[new] = FunctionWrapper(cls,_new);
    -- Use + instead of | to try to keep lua 5.3 or lower compatible.
    pms[new] = Permission.public + Permission.static;

    all[delete] = FunctionWrapper(cls,_delete);
    pms[delete] = Permission.public;
end

return Functions;