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

local rawset = rawset;
local error = error;
local type = type;
local Config = require("OOP.Config");
local Version = Config.Version;
local i18n = require("OOP.i18n");
local Internal = require("OOP.Variant.Internal");
local ClassesMembers = Internal.ClassesMembers;

local Compat = require("OOP.Version.Compat");
local bits = Compat.bits;
local band = bits.band;
local bor = bits.bor;
local Debug = Config.Debug;

local MetaMapName = Config.MetaMapName;
local AllEnumerations = Internal.AllEnumerations;
local AllClasses = Internal.AllClasses;
local ClassesReadable = Internal.ClassesReadable;
local ClassesWritable = Internal.ClassesWritable;

local new = Config.new;
local delete = Config.delete;

local public = Config.Qualifiers.public;
local private = Config.Qualifiers.private;
local protected = Config.Qualifiers.protected;
local static = Config.Qualifiers.static;
local const = Config.Qualifiers.const;
local final = Config.Qualifiers.final;
local virtual = Config.Qualifiers.virtual;
local get = Config.get;
local set = Config.set;

local BitsMap = {
    [public] = 2 ^ 0,
    [private] = 2 ^ 1,
    [protected] = 2 ^ 2,
    [static] = 2 ^ 3,
    [const] = 2 ^ 4,
    [final] = 2 ^ 5,
    [get] = 2 ^ 6,
    [set] = 2 ^ 7,
    [virtual] = 2 ^ 8
};
if Version > 5.2 then
    BitsMap[public] = math.tointeger(BitsMap[public]);
    BitsMap[private] = math.tointeger(BitsMap[private]);
    BitsMap[protected] = math.tointeger(BitsMap[protected]);
    BitsMap[static] = math.tointeger(BitsMap[static]);
    BitsMap[const] = math.tointeger(BitsMap[const]);
    BitsMap[final] = math.tointeger(BitsMap[final]);
    BitsMap[get] = math.tointeger(BitsMap[get]);
    BitsMap[set] = math.tointeger(BitsMap[set]);
    BitsMap[virtual] = math.tointeger(BitsMap[virtual]);
end
local Permission = {
    public = BitsMap[public],
    private = BitsMap[private],
    protected = BitsMap[protected],
    static = BitsMap[static],
    const = BitsMap[const],
    final = BitsMap[final],
    get = BitsMap[get],
    set = BitsMap[set],
    virtual = BitsMap[virtual]
}
local Router = {};

local Pass = nil;
local Done = nil;
local decor = 0;
local cls = 0;
local function Begin(self,outCls,key)
    decor = 0;
    cls = outCls;
    return Pass(self,key);
end

if Debug then
    local ctor = Config.ctor;
    local dtor = Config.dtor;

    local FunctionWrapper = Compat.FunctionWrapper;
    local ClassesAll = Internal.ClassesAll;
    local FinalClassesMembers = Internal.FinalClassesMembers;
    local ClassesPermisssions = Internal.ClassesPermisssions;
    local VirtualClassesMembers = Internal.VirtualClassesMembers;

    local RouterReservedWord = Internal.RouterReservedWord;
    -- It is only under debug that the values need to be routed to the corresponding fields of the types.
    -- To save performance, all qualifiers will be ignored under non-debug.

    -- Rules:
    -- 1 - There can be no duplicate qualifiers;
    -- 2 - public/private/protected cannot be used together;
    -- 3 - static cannot qualify constructors and destructors;
    -- 4 - Can't use qualifiers that don't exist;
    -- 5 - Reserved words cannot be modified (__singleton__/friends/handlers).
    Pass = function(self,key)
        local bit = BitsMap[key];
        if bit then
            if band(decor,bit) ~= 0 then
                error((i18n"The %s qualifier is not reusable."):format(key));
            elseif band(decor,0x7) ~= 0 and band(bit,0x7) ~= 0 then
                -- Check public,private,protected,they are 0x7
                error((i18n"The %s qualifier cannot be used in conjunction with other access qualifiers."):format(key));
            elseif band(decor,0xd0) ~= 0 and band(bit,0xd0) ~= 0 then
                -- Check set,get,const,they are 0xd0
                error((i18n"%s,%s,%s cannot be used at the same time."):format(get,set,const));
            else
                local temp = bor(bit,decor);
                if band(temp,Permission.virtual) ~= 0 and band(temp,Permission.virtual - 1) ~= 0 then
                    error(i18n"It is not necessary to use pure virtual functions with other qualifiers.");
                end
            end
            decor = bor(decor,bit);
        else
            local get_set = band(decor,0xc0);
            if get_set ~= 0 then
                if bor(decor,0xc0) == 0xc0 then
                    Internal.CheckPermission(cls,key,false);
                    local property = (get_set == Permission.get and ClassesReadable or ClassesWritable)[cls][key];
                    if property then
                        return property[1];
                    else
                        error((i18n"There is no such property. - %s"):format(key));
                    end
                end
            end
            error((i18n"There is no such qualifier. - %s"):format(key));
        end
        return self;
    end
    Done = function(_,key,value)
        if FinalClassesMembers[cls][key] then
            error((i18n"You cannot define final members again. - %s"):format(key));
        end
        local bit = BitsMap[key] or RouterReservedWord[key];
        if bit then
            error((i18n"The name is unavailable. - %s"):format(key));
        end
        local meta = MetaMapName[key];
        if meta then
            error((i18n"You cannot qualify meta-methods. - %s"):format(key));
        end
        local vcm = VirtualClassesMembers[cls];
        if decor == Permission.virtual then
            if value ~= 0 then
                error((i18n"The pure virtual function %s must be assigned a value of 0."):format(key));
            end
            vcm[key] = true;
            decor = 0;
            cls = nil;
            return;
        end
        local isStatic = band(decor,Permission.static) ~= 0;
        if isStatic and
        (key == ctor or key == dtor) then
            error((i18n"%s qualifier cannot qualify %s method."):format(static,key));
        end
        if band(decor,0x7) == 0 then
            -- Without the public qualifier, public is added by default.
            decor = bor(decor,0x1);
        end
        local vt = type(value);
        local isFunction = "function" == vt;
        if vcm[key] then
            -- Check pure virtual functions.
            if not isFunction then
                error((i18n"%s must be overridden as a function."):format(key));
            end
            if isStatic then
                error((i18n"The pure virtual function %s cannot be overridden as a static function."):format(key));
            end
            vcm[key] = nil;
        end
        local get_set = band(decor,0xc0);
        if isFunction then
            value = FunctionWrapper(cls,value);
        elseif get_set == 0 then
            local isTable = "table" == vt;
            -- For non-functional, non-static members,non-class objects,non-enumeration objects,
            -- add to the member table and generate it for each instance.
            if not isStatic and (not isTable or (not AllEnumerations[value] and not AllClasses[value])) then
                ClassesMembers[cls][key] = value;
            end
        end

        local pms = ClassesPermisssions[cls];
        pms[key] = decor;
        if get_set ~= 0 then
            if not isFunction then
                error((i18n"A function must be assigned to the property %s."):format(key));
            end
            if key == ctor or key == dtor then
                error((i18n"%s and %s can't be used as property."):format(ctor,dtor));
            end
            -- The property is set to a special table
            -- with index 1 representing the function assigned to the property
            -- and index 2 representing whether the property is a static property.
            (get_set == Permission.get and ClassesReadable or ClassesWritable)[cls][key] = {value,isStatic};
        else
            ClassesAll[cls][key] = value;
            if key == ctor then
                -- Reassign permissions to "new", which are the same as ctor with the static qualifier.
                pms[new] = bor(decor,0x8);
            elseif key == dtor then
                pms[delete] = decor;
            end
        end

        if band(decor,Permission.final) ~= 0 then
            FinalClassesMembers[cls][key] = true;
        end
        decor = 0;
        cls = nil;
    end
else
    local ClassesMetas = Internal.ClassesMetas;
    local sc = Permission.static;
    local gt = Permission.get;
    local vir = Permission.virtual;
    -- In non-debug mode, no attention is paid to any qualifiers other than static.
    Pass = function(self,key)
        local bit = BitsMap[key];
        if bit then
            decor = bor(decor,bit);
        else
            local get_set = band(decor,0xc0);
            if get_set ~= 0 then
                local property = (get_set == gt and ClassesReadable or ClassesWritable)[cls][key];
                return property and property[1] or nil;
            end
        end
        return self;
    end
    Done = function(_,key,value)
        if band(decor,vir) ~= 0 then
            -- Skip pure virtual functions.
            decor = 0;
            cls = nil;
            return;
        end
        local vt = type(value);
        local isFunction = "function" == vt;
        local isTable = "table" == vt;
        local isStatic = band(decor,sc) ~= 0;
        local get_set = band(decor,0xc0);
        if not isFunction and not isStatic and get_set == 0 and (not isTable or (not AllEnumerations[value] and not AllClasses[value])) then
            ClassesMembers[cls][key] = value;
        end

        if get_set ~= 0 then
            (get_set == gt and ClassesReadable or ClassesWritable)[cls][key] = {value,isStatic};
        else
            rawset(cls,key,value);
        end
        decor = 0;
        cls = nil;

        local meta = MetaMapName[key];
        if meta then
            local metas = ClassesMetas[cls];
            metas[key] = value;
        end
    end
end

setmetatable(Router,{
    __index = function (self,key)
        return Pass(self,key);
    end,
    __newindex = function (self,key,val)
        Done(self,key,val);
    end
});

return {
    Router = Router,
    BitsMap = BitsMap,
    Permission = Permission,
    Begin = Begin
};