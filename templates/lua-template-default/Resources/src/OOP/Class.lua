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

local setmetatable = setmetatable;
local type = type;
local pcall = pcall;
local error = error;
local remove = table.remove;

local Config = require("OOP.Config");
local Debug = Config.Debug;
local ctor = Config.ctor;
local __cls__ = Config.__cls__;

local Functions = Debug and require("OOP.Variant.DebugFunctions") or require("OOP.Variant.BaseFunctions");
local ClassesBases = Functions.ClassesBases;
local CreateClassObject = Functions.CreateClassObject;
local class = Functions.class;
local CreateClassTables = Functions.CreateClassTables;
local CheckClass = Functions.CheckClass;
local ClassInherite = Functions.ClassInherite;
local CreateClassIs = Functions.CreateClassIs;
local CreateClassDelete = Functions.CreateClassDelete;
local RetrofiteUserDataObjectMeta = Functions.RetrofiteUserDataObjectMeta;
local RegisterHandlersAndMembers = Functions.RegisterHandlersAndMembers;
local AttachClassFunctions = Functions.AttachClassFunctions;
local ClassesBanNew = Functions.ClassesBanNew;
local ClassesMetas = Functions.ClassesMetas;
local NamedClasses = Functions.NamedClasses;

local ClassMeta = {
    __index = Functions.ClassGet,
    __newindex = Functions.ClassSet
};
local ClassCreateLayer = 0;
local function ObjectInit(obj,cls,all,...)
    -- When there is no constructor of its own, if there are less than 2 base classes,
    -- the constructor is automatically found.
    local init = all[ctor] or (#ClassesBases[cls] == 1 and cls[ctor] or nil);
    -- Do not get ctor from ClassesAll and make it search automatically.
    if init then
        -- Avoid recursively polluting the classCreateLayer variable when create a new object in the ctor.
        -- Cache it, after the call, set it to classCreateLayer+tempCreateLayer
        -- The final call ends with the value -1.
        local tempCreateLayer = ClassCreateLayer;
        ClassCreateLayer = 0;
        local ok,msg = pcall(init,obj,...);
        ClassCreateLayer = ClassCreateLayer + tempCreateLayer - 1;
        if not ok then
            error(msg);
        end
    else
        ClassCreateLayer = ClassCreateLayer - 1;
    end
end

local function CreateClassNew(cls,clsAll,handlers,members)
    return function(...)
        if Debug then
            assert(not ClassesBanNew[cls],"The base classes constructor is not accessible.");
        end
        ClassCreateLayer = ClassCreateLayer + 1;
        local ok,obj,all = pcall(CreateClassObject,cls,...);
        if not ok or nil == obj then
            ClassCreateLayer = ClassCreateLayer - 1;
            return nil;
        end

        if ClassCreateLayer == 1 then
            RegisterHandlersAndMembers(obj,all,handlers,members);
            local oType = type(obj);
            if "userdata" == oType then
                RetrofiteUserDataObjectMeta(obj,cls);
            else
                setmetatable(obj,ClassesMetas[cls]);
            end
        end
        ObjectInit(obj,cls,clsAll,...);
        return obj;
    end;
end

---Create a class, passing in parameters to inherit from other classes.
---
---@vararg string|table
---@return table class
function class.New(...)
    local args = {...};
    local cls,metas,name = CheckClass(args);
    local all,bases,handlers,members = CreateClassTables(cls);

    ClassInherite(cls,args,bases,handlers,members,metas,name);

    AttachClassFunctions(
        cls,
        CreateClassIs(cls,bases),
        CreateClassNew(cls,all,handlers,members),
        CreateClassDelete(cls)
    );

    return setmetatable(cls,ClassMeta);
end