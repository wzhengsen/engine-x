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
local setmetatable = setmetatable;
local rawset = rawset;
local rawget = rawget;
local pairs = pairs;
local ipairs = ipairs;
local type = type;
local select = select;
local remove = table.remove;
local insert = table.insert;
local d_setmetatable = debug.setmetatable;

local Config = require("OOP.Config");
local i18n = require("OOP.i18n");
local Internal = require("OOP.Variant.Internal");
local class = require("OOP.BaseClass");
local BaseFunctions = require("OOP.BaseFunctions");

local Copy = BaseFunctions.Copy;
local Update2Children = BaseFunctions.Update2Children;
local Update2ChildrenWithKey = BaseFunctions.Update2ChildrenWithKey;


local E_Handlers = require("OOP.Event").handlers;
local R = require("OOP.Router");
local Router = R.Router;
local BitsMap = R.BitsMap;
local Begin = R.Begin;

local delete = Config.delete;
local DeathMarker = Config.DeathMarker;
local dtor = Config.dtor;
local ctor = Config.ctor;
local IsInherite = Config.ExternalClass.IsInherite;

local new = Config.new;
local is = Config.is;
local __cls__ = Config.__cls__;

local __singleton__ = Config.__singleton__;
local Instance = Config.Instance;
local handlers = Config.handlers;
local friends = Config.friends;
local __new__ = Config.__new__;
local __delete__ = Config.__delete__;
local Meta = Config.Meta;
local static = Config.Qualifiers.static;
local get = Config.get;
local set = Config.set;

local MetaMapName = Config.MetaMapName;

local _IsNull = class.IsNull;

local Functions = Internal;
local ClassesChildrenByName = Functions.ClassesChildrenByName;
local NamedClasses = Functions.NamedClasses;
local AllClasses = Functions.AllClasses;
local AllEnumerations = Functions.AllEnumerations;
local ClassesReadable = Functions.ClassesReadable;
local ClassesWritable = Functions.ClassesWritable;
local ClassesHandlers = Functions.ClassesHandlers;
local ClassesBases = Functions.ClassesBases;
local ClassesChildren = Functions.ClassesChildren;
local ClassesMembers = Functions.ClassesMembers;
local ClassesMetas = Functions.ClassesMetas;
local ClassesNew = Functions.ClassesNew;
local ClassesDelete = Functions.ClassesDelete;
local ClassesSingleton = Functions.ClassesSingleton;
local ClassesStatic = Functions.ClassesStatic;
local ObjectsAll = Functions.ObjectsAll;
local ObjectsCls = Functions.ObjectsCls;

---Get the single instance, where it is automatically judged empty
---and does not require the user to care.
---
---@param self any
---@param call function
---
local function GetSingleton(self,call)
    local s = ClassesSingleton[self];
    if _IsNull(s) then
        s = call(self);
        ClassesSingleton[self] = s;
    end
    return s;
end

---Destroy the single instance.
---It is mapped to Instance property.
---
---@param self table
---@param val nil   This parameter must be a nil value.
---
local function DestroySingleton(self,val)
    if nil == val then
        local s = ClassesSingleton[self];
        if not _IsNull(s) then
            s:delete();
            ClassesSingleton[self] = nil;
        end
    end
end

---register meta-table of properties for class.
---
---@param cls table
---@param bases table
---@param rw table Readable or writable.
---@return table,table
---
local function CreateClassPropertiesTable(cls,bases,rw)
    if rw then
        return setmetatable({},{
            __index = function (_,key)
                for _,base in ipairs(bases) do
                    local ret = rw[base];
                    if nil ~= ret then
                        ret = ret[key];
                        if nil ~= ret then
                            return ret;
                        end
                    end
                end
            end
        });
    end
    return CreateClassPropertiesTable(cls,bases,ClassesReadable),CreateClassPropertiesTable(cls,bases,ClassesWritable);
end


local registry = debug.getregistry();
---
---Check the class and return the meta-table for the class object.
---
---@param args table
---@return table cls
---@return table metas
---@return string? name
---
local function CheckClass(args)
    local metas = nil;
    local name = nil;
    local cls = {};
    if type(args[1]) == "string" then
        name = remove(args,1);
        if NamedClasses[name] then
            error((i18n"You cannot use this name \"%s\", which is already used by other class.").format(name));
        else
            NamedClasses[name] = cls;
            NamedClasses[cls] = name;
            metas = registry[name];
            if nil == metas then
                -- If a meta table by that name does not exist in the registry, it is created.
                metas = {__name = name,[__cls__] = cls};
                registry[name] = metas;
            else
                metas[__cls__] = cls;
            end
        end
    else
        metas = {};
    end
    Functions.MakeInternalObjectMeta(cls,metas);
    return cls,metas,name;
end

local function PushBase(cls,bases,base,handlers,members,metas)
    -- Inherite handlers/members/metas from base.

    -- To save runtime performance,
    -- some values that may be looked up at runtime are recorded in the table at inheritance time.
    local found = ClassesHandlers[base];
    if found then
        for handler,func in pairs(found) do
            handlers[handler] = func;
        end
    end
    found = ClassesMembers[base];
    if found then
        for key,member in pairs(found) do
            members[key] = member;
        end
    end
    found = ClassesMetas[base];
    if found then
        for key,_ in pairs(Meta) do
            local meta = found[key];
            if nil ~= meta and nil == metas[key] then
                metas[key] = meta;
            end
        end
    end
    local _new = ClassesNew[base];
    if _new then
        ClassesNew[cls] = _new;
    end
    local _delete = ClassesDelete[base];
    if _delete then
        ClassesDelete[cls] = _delete;
    end
    -- Record the current class into the subclasses table of the base class,
    -- and if there are any member (except for functions, but containing metamethods and events) changes in the base class afterwards,
    -- they will be mapped to all subclasses.

    local children = ClassesChildren[base];
    if children then
        children[#children + 1] = cls;
    end
    bases[#bases + 1] = base;
end

---If there is no parameter,it means the return value is the current type.
---@return table
local function ClassIs(cls,bases,...)
    local len = select("#",...);
    if 0 == len then
        return cls;
    end
    local baseCls = select(1,...);
    if baseCls == nil then
        return false;
    end
    if baseCls == cls then
        return true;
    end
    for _,base in ipairs(bases) do
        if base == baseCls then
            return true;
        else
            local _is = base[is];
            if _is then
                if _is(baseCls) then
                    return true;
                end
            elseif IsInherite and IsInherite(base,baseCls) then
                return true;
            end
        end
    end
    return false;
end

local function CreateClassIs(cls,base)
    return function (...)
        return ClassIs(cls,base,...);
    end;
end

---Creates an object of a class that will be created using the create function if it exists,
---otherwise a table is created.
---Returns the object created and the table holding the members of that object.
---
---@param cls table
---@return "table?|userdata?"
---@return "table?"
local function CreateClassObject(cls,...)
    local _new = ClassesNew[cls];
    local obj = nil;
    local oType = "table";
    if _new then
        -- The object returned by the _new function must be userdata or nil.
        obj = _new(...);
        oType = type(obj);
        obj = "userdata" == oType and obj or nil;
    else
        obj = {};
    end
    local all = nil;
    if "table" == oType then
        all = obj;
    elseif nil ~= obj and nil == ObjectsAll[obj] then
        all = {};
        ObjectsAll[obj] = all;
    end
    return obj,all;
end

---Cascade to get the value of the corresponding key of a class and its base class
---(ignoring metamethods).
---
---@param cls table
---@param key any
---@param called table
---@param byObject? boolean
---@return any
---
local function CascadeGet(cls,key,called,byObject)
    if called[cls] then
        return nil;
    end
    called[cls] = true;
    local ret = rawget(cls,key);
    if nil ~= ret then
        return ret;
    end
    if not byObject then
        local static = ClassesStatic[cls];
        if static then
            ret = rawget(static,key);
            if nil ~= ret then
                return ret;
            end
        end
    end
    local bases = ClassesBases[cls];
    if bases then
        for _,base in ipairs(bases) do
            ret = CascadeGet(base,key,called,byObject);
            if nil ~= ret then
                return ret;
            end
        end
    end
end

local function RegisterHandlersAndMembers(obj,all,handlers,members)
    for key,func in pairs(handlers) do
        -- Automatically listens to events.
        E_Handlers.On(key,obj,func);
    end
    for key,mem in pairs(members) do
        -- Automatically set member of object.
        -- Before the instance can change the meta-table, its members must be set.
        all[key] = Copy(mem);
    end
end

local HandlersControlObj = nil;
local HandlersControl = setmetatable({},{
    __newindex = function (_,key,value)
        if nil == value then
            -- If value is nil,we remove the response of this event name.
            E_Handlers.Remove(key,HandlersControlObj);
        else
            -- If value is a number,we sort it.
            E_Handlers.Order(key,HandlersControlObj,math.floor(value));
        end
    end
});

---Generate a meta-table for an internal object.
---
---@param cls table
---@return table
---
local function MakeInternalObjectMeta(cls,metas)
    ClassesMetas[cls] = metas;
    metas.__index = function (sender,key)
        if key == handlers then
            HandlersControlObj = sender;
            return HandlersControl;
        end
        local ret = nil;
        local cCls = nil;
        if "userdata" == type(sender) then
            local all = ObjectsAll[sender];
            if not all then
                all = {};
                ObjectsAll[sender] = all;
            end
            cCls = ObjectsCls[sender];
            if not cCls then
                cCls = metas[__cls__];
                ObjectsCls[sender] = cCls;
            end
            ret = all[key];
            if nil ~= ret then
                return ret;
            end
        else
            cCls = cls;
        end

        -- Check the properties of current class.
        local property = ClassesReadable[cCls][key];
        if property and not property[2] then
            return property[1](sender);
        end

        -- Check the key of current class.
        ret = rawget(cCls,key);
        if nil ~= ret then
            return ret;
        end

        -- Check base class.
        for _, base in ipairs(ClassesBases[cCls]) do
            ret = CascadeGet(base,key,{},true);
            if nil ~= ret then
                return ret;
            end
        end
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
        local property = ClassesWritable[cCls][key];
        if property and not property[2] then
            property[1](sender,value);
            return;
        end
        if isUserData then
            local all = ObjectsAll[sender];
            if not all then
                all = {};
                ObjectsAll[sender] = all;
            end
            all[key] = value;
            return;
        end
        rawset(sender,key,value);
    end;
    return metas;
end

local function RetrofiteMetaMethod(meta,methodName,method)
    local oldMethod = rawget(meta,methodName);
    rawset(meta,methodName,function (sender,...)
        local all = ObjectsAll[sender];
        if not all then
            if methodName ~= "__close" and methodName ~= "__gc" then
                if nil ~= oldMethod then
                    return oldMethod(sender,...);
                elseif methodName == "__eq" then
                    return false;
                else
                    error((i18n"This meta method is not implemented. - %s"):format(methodName));
                end
            end
        elseif method then
            return method(sender,...);
        end
    end);
end

--- Generate a meta-table for an object (typically a userdata).
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
    local indexFunc = "function" == type(index);
    rawset(meta,"__index",function (sender,key)
        -- Check self all.
        local all = ObjectsAll[sender];
        local ret = nil;
        if all then
            if key == handlers then
                HandlersControlObj = sender;
                return HandlersControl;
            end
            ret = all[key];
            if nil ~= ret then
                return ret;
            end
        end

        local cls = ObjectsCls[sender];
        if cls then
            -- Check cls methods and members.
            ret = rawget(cls,key);
            if nil ~= ret then
                return ret;
            end

            -- Check cls properties.
            local property = ClassesReadable[cls][key];
            if property and not property[2] then
                return property[1](sender);
            end
            -- Check cls bases.
            for _, base in ipairs(ClassesBases[cls]) do
                ret = CascadeGet(base,key,{},true);
                if nil ~= ret then
                    return ret;
                end
            end
        end
        -- Finally, check the original method or table.
        if index then
            return indexFunc and index(sender,key) or index[key];
        end
    end);
    local newIndex = rawget(meta,"__newindex");
    local newIndexFunc =  "function" == type(newIndex);
    rawset(meta,"__newindex",function (sender,key,value)
        local cls = ObjectsCls[sender];
        if cls then
            local property = ClassesWritable[cls][key];
            if property and not property[2] then
                property[1](sender,value);
                return;
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
    -- Instances of the userdata type require the last cls information.
    -- Because multiple different lua classes can inherit from the same c++ class.
    ObjectsCls[obj] = cls;

    local meta = getmetatable(obj);
    -- If the __cls__ field exists in the meta table,
    -- then this userdata can be considered as internal userdata and does not need to retrofite the meta table.
    if nil == rawget(meta,__cls__) then
        RetrofiteUserDataObjectMetaExternal(obj,meta,cls);
    end
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
local function CascadeDelete(self,cls,called)
    if called[cls] then
        return;
    end
    local del = rawget(cls,dtor);
    if del then
        del(self);
    end
    called[cls] = true;
    local bases = ClassesBases[cls];
    if bases then
        for _,base in ipairs(bases) do
            CascadeDelete(self,base,called);
        end
    end
end

local function CallDel(self)
    CascadeDelete(self,self[is](),{});
    ObjectsAll[self] = nil;
end

local function CreateClassDelete(cls)
    return function (self)
        Functions.CascadeDelete(self,cls,{});
        local d = ClassesDelete[cls];
        if d then
            d(self);
        else
            if "userdata" == type(self) then
                d_setmetatable(self,nil);
            else
                setmetatable(self,nil);
                self[DeathMarker] = true;
            end
        end
        ObjectsAll[self] = nil;
    end
end

---Create a class table with base info.
---
---@param cls table
---@return table all
---@return table bases
---@return table handlers
---@return table members
---@return table r
---@return table w
---
local function CreateClassTables(cls)
    local bases = {};
    local handlers = setmetatable({},{
        __newindex = function (h,k,v)
            rawset(h,k,v);
            Update2ChildrenWithKey(cls,ClassesHandlers,k,v);
        end
    });
    local members = {};

    AllClasses[cls] = true;
    ClassesBases[cls] = bases;
    ClassesChildren[cls] = {};
    ClassesHandlers[cls] = handlers;
    ClassesStatic[cls] = {};

    local r,w = CreateClassPropertiesTable(cls,bases);
    ClassesReadable[cls] = r;
    ClassesWritable[cls] = w;
    ClassesMembers[cls] = members;

    return cls,bases,handlers,members,r,w;
end

local function AttachClassFunctions(cls,_is,_new,_delete)
    local static = ClassesStatic[cls];
    cls[is] = _is;
    static[new] = _new;
    cls[delete] = _delete;
end

local function ClassInherite(cls,args,bases,handlers,members,metas,name)
    local children = ClassesChildrenByName[name];
    if children then
        -- If some class inherits by name before that class is defined,
        -- update the bases table and children table here.
        ClassesChildren[cls] = children;
        ClassesChildrenByName[name] = nil;
        for _,child in ipairs(children) do
            insert(ClassesBases[child],cls);
        end
    end
    for _, base in ipairs(args) do
        if "string" == type(base) then
            local baseName = base;
            base = NamedClasses[base];
            if nil == base then
                -- If there is no class named 'base',record it in ClassesChildrenByName.
                -- When the class which named 'base' is created,push 'base' into cls bases table.
                ClassesChildrenByName[baseName] = ClassesChildrenByName[baseName] or {};
                insert(ClassesChildrenByName[baseName],cls);
            end
        end
        if nil ~= base then
            Functions.PushBase(cls,bases,base,handlers,members,metas);
        end
    end
end

---In non-debug mode, no access qualifiers are considered.
---
---@param cls table
---@param key any
---@return any
---
local function ClassGet(cls,key)
    if BitsMap[key] then
        return Begin(Router,cls,key);
    end
    if key == handlers then
        return ClassesHandlers[cls];
    end
    -- Check the properties first.
    local property = ClassesReadable[cls][key];
    if property and property[2] then
        -- Is static property?
        -- Class can't access object's property directly.
        return property[1]()
    end
    local static = ClassesStatic[cls];
    local ret = static[key];
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
    if key == __singleton__ then
        -- Register "Instance" automatically.
        cls[static][get][Instance] = function ()
            return GetSingleton(cls,value);
        end;
        cls[static][set][Instance] = function (val)
            DestroySingleton(cls,val)
        end;
        return;
    elseif key == __new__ then
        ClassesNew[cls] = value;
        Update2Children(cls,ClassesNew,value);
        return;
    elseif key == __delete__ then
        ClassesDelete[cls] = value;
        Update2Children(cls,ClassesDelete,value);
        return;
    elseif key == friends then
        return;
    else
        local property = ClassesWritable[cls][key];
        if property and property[2] then
            -- Is static property?
            -- Class can't access object's property directly.
            property[1](value);
            return;
        end
        local exist = rawget(cls,key);
        local vt = type(value);
        local isFunction = "function" == vt;
        local isTable = "table" == vt;
        if not exist and not isFunction and (not isTable or (not AllEnumerations[value] and not AllClasses[value])) then
            ClassesMembers[cls][key] = value;
            Update2ChildrenWithKey(cls,ClassesMembers,key,value);
        end
        rawset(cls,key,value);
        ClassesStatic[cls][key] = nil;
    end
    local meta = MetaMapName[key];
    if meta then
        ClassesMetas[cls][meta] = value;
        Update2ChildrenWithKey(cls,ClassesMetas,meta,value);
    end
end

Functions.class = class;
Functions.GetSingleton = GetSingleton;
Functions.DestroySingleton = DestroySingleton;
Functions.IsNull = _IsNull;
Functions.CheckClass = CheckClass;
Functions.PushBase = PushBase;
Functions.CreateClassIs = CreateClassIs;
Functions.CreateClassDelete = CreateClassDelete;
Functions.CreateClassObject = CreateClassObject;
Functions.CallDel = CallDel;
Functions.MakeInternalObjectMeta = MakeInternalObjectMeta;
Functions.RegisterHandlersAndMembers = RegisterHandlersAndMembers;
Functions.RetrofiteUserDataObjectMeta = RetrofiteUserDataObjectMeta;
Functions.RetrofiteMetaMethod = RetrofiteMetaMethod;
Functions.CreateClassTables = CreateClassTables;
Functions.AttachClassFunctions = AttachClassFunctions;
Functions.ClassInherite = ClassInherite;
Functions.ClassGet = ClassGet;
Functions.ClassSet = ClassSet;

return Functions;