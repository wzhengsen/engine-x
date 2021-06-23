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

local Config = require("OOP.Config");
local Debug = Config.Debug;
local WeakTable = {__mode = "k"};
return {
    NamedClasses = {},
    RequireInheriteClasses = {},
    AllClasses = setmetatable({},WeakTable),
    FinalClasses = setmetatable({},WeakTable),
    AllEnumerations = setmetatable({},WeakTable),
    ClassesReadable = setmetatable({},WeakTable),
    ClassesWritable = setmetatable({},WeakTable),
    ClassesHandlers = setmetatable({},WeakTable),
    ClassesBases = setmetatable({},WeakTable),
    ClassesMembers = setmetatable({},WeakTable),
    FinalClassesMembers = setmetatable({},WeakTable),
    ClassesMetas = setmetatable({},WeakTable),
    ClassesNew = setmetatable({},WeakTable),
    ClassesDelete = setmetatable({},WeakTable),
    ClassesSingleton = setmetatable({},WeakTable),
    ObjectsAll = setmetatable({},WeakTable),
    ObjectsCls = setmetatable({},WeakTable),
    ClassesAll = setmetatable({},WeakTable);
    ClassesPermisssions = Debug and setmetatable({},WeakTable) or nil,
    ClassesFriends = Debug and setmetatable({},WeakTable) or nil,
    ClassesBanNew = Debug and setmetatable({},WeakTable) or nil,
    ClassesBanDelete = Debug and setmetatable({},WeakTable) or nil,
    AccessStack = Debug and {} or nil,
    ReservedWord = {
        [Config.Qualifiers.public] = true,
        [Config.Qualifiers.protected] = true,
        [Config.Qualifiers.private] = true,
        [Config.Qualifiers.const] = true,
        [Config.Qualifiers.static] = true,
        [Config.Qualifiers.final] = true,
        [Config.new] = true,
        [Config.delete] = true,
        [Config.is] = true,
        [Config.handlers] = true,
        [Config.set] = true,
        [Config.get] = true
    },
    RouterReservedWord = {
        [Config.new] = true,
        [Config.delete] = true,
        [Config.is] = true,
        [Config.handlers] = true,
        [Config.__new__] = true,
        [Config.__delete__] = true,
        [Config.set] = true,
        [Config.get] = true
    };
};