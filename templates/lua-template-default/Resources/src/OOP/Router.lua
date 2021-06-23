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
local Internal = require("OOP.Variant.Internal");
local ClassesMembers = Internal.ClassesMembers;

local Compat = require("OOP.Version.Compat");
local bits = Compat.bits;
local Debug = Config.Debug;

local MetaMapName = Config.MetaMapName;
local AllEnumerations = Internal.AllEnumerations;
local AllClasses = Internal.AllClasses;

local new = Config.new;
local delete = Config.delete;

local public = Config.Qualifiers.public;
local private = Config.Qualifiers.private;
local protected = Config.Qualifiers.protected;
local static = Config.Qualifiers.static;
local const = Config.Qualifiers.const;
local final = Config.Qualifiers.final;

local BitsMap = {
    [public] = 2 ^ 0,
    [private] = 2 ^ 1,
    [protected] = 2 ^ 2,
    [static] = 2 ^ 3,
    [const] = 2 ^ 4,
    [final] = 2 ^ 5
};
if Version > 5.2 then
    BitsMap.public = math.tointeger(BitsMap.public);
    BitsMap.private = math.tointeger(BitsMap.private);
    BitsMap.protected = math.tointeger(BitsMap.protected);
    BitsMap.static = math.tointeger(BitsMap.static);
    BitsMap.const = math.tointeger(BitsMap.const);
    BitsMap.final = math.tointeger(BitsMap.final);
end
local Permission = {
    public = BitsMap[public],
    private = BitsMap[private],
    protected = BitsMap[protected],
    static = BitsMap[static],
    const = BitsMap[const],
    final = BitsMap[final]
}
local Router = {};

function Router:Begin(cls,key)
    rawset(self,"decor",0);
    rawset(self,"cls",cls);
    return self:Pass(key);
end

if Debug then
    local ctor = Config.ctor;
    local dtor = Config.dtor;

    local FunctionWrapper = Compat.FunctionWrapper;
    local ClassesAll = Internal.ClassesAll;
    local FinalClassesMembers = Internal.FinalClassesMembers;
    local ClassesPermisssions = Internal.ClassesPermisssions;

    local RouterReservedWord = Internal.RouterReservedWord;
    -- It is only under debug that the values need to be routed to the corresponding fields of the types.
    -- To save performance, all qualifiers will be ignored under non-debug.

    -- Rules:
    -- 1 - There can be no duplicate qualifiers;
    -- 2 - public/private/protected cannot be used together;
    -- 3 - static cannot qualify constructors and destructors;
    -- 4 - Can't use qualifiers that don't exist;
    -- 5 - Reserved words cannot be modified (__singleton__/friends/handlers/set/get and so on).
    function Router:Pass(key)
        local bit = BitsMap[key];
        local decor = self.decor;
        if bit then
            if bits.band(decor,bit) ~= 0 then
                error(("The %s qualifier is not reusable."):format(key));
            elseif bits.band(decor,0x7) ~= 0 and bits.band(bit,0x7) ~= 0 then
                -- Check public,private,protected,they are 0x7
                error(("The %s qualifier cannot be used in conjunction with other access qualifiers."):format(key));
            end
            self.decor = bits.bor(decor,bit);
        else
            error(("There is no such qualifier. - %s"):format(key));
        end
        return self;
    end
    function Router:End(key,value)
        local cls = self.cls;
        if FinalClassesMembers[cls][key] then
            error(("You cannot define final members again.-%s"):format(key));
        end
        local bit = BitsMap[key] or RouterReservedWord[key];
        if bit then
            error(("The name is unavailable. - %s"):format(key));
        end
        local meta = MetaMapName[key];
        if meta then
            error(("You cannot qualify meta-methods. - %s"):format(key));
        end
        local decor = self.decor;
        if bits.band(decor,Permission.static) ~= 0 then
            if (key == ctor or key == dtor) then
                error(("%s qualifier cannot qualify %s functions."):format(static,key));
            end
        end
        if bits.band(decor,0x7) == 0 then
            -- Without the public qualifier, public is added by default.
            decor = bits.bor(decor,0x1);
        end
        local vt = type(value);
        local isFunction = "function" == vt;
        if isFunction then
            value = FunctionWrapper(cls,value);
        else
            local isTable = "table" == vt;
            -- For non-functional, non-static members,non-class objects,non-enumeration objects,
            -- add to the member table and generate it for each instance.
            if bits.band(decor,Permission.static) == 0 and (not isTable or (not AllEnumerations[value] and not AllClasses[value])) then
                ClassesMembers[cls][key] = value;
            end
        end
        ClassesAll[cls][key] = value;
        local pms = ClassesPermisssions[cls];
        pms[key] = decor;
        if key == ctor then
            -- Reassign permissions to "new", which are the same as ctor with the static qualifier.
            pms[new] = bits.bor(decor,0x8);
        elseif key == dtor then
            pms[delete] = decor;
        end
        if bits.band(decor,Permission.final) ~= 0 then
            FinalClassesMembers[cls][key] = true;
        end
        self.decor = 0;
        self.cls = nil;
    end
else
    local ClassesMetas = Internal.ClassesMetas;
    local sc = Permission.static;
    -- In non-debug mode, no attention is paid to any qualifiers other than static.
    function Router:Pass(key)
        if BitsMap[key] == sc then
            self.decor = sc;
        end
        return self;
    end
    function Router:End(key,value)
        local cls = self.cls;
        local vt = type(value);
        local isFunction = "function" == vt;
        local isTable = "table" == vt;
        if not isFunction and self.decor ~= sc and (not isTable or (not AllEnumerations[value] and not AllClasses[value])) then
            ClassesMembers[cls][key] = value;
        end
        rawset(cls,key,value);
        self.decor = 0;
        self.cls = nil;

        local meta = MetaMapName[key];
        if meta then
            local metas = ClassesMetas[cls];
            metas[key] = value;
        end
    end
end

setmetatable(Router,{
    __index = function (self,key)
        return self:Pass(key);
    end,
    __newindex = function (self,key,val)
        self:End(key,val);
    end
});

return {
    Router = Router,
    BitsMap = BitsMap,
    Permission = Permission
};