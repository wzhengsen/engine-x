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
local LuaVersion = Config.LuaVersion;
local Compat1 = LuaVersion < 5.3 and require("OOP.Version.LowerThan53") or require("OOP.Version.HigherThan52");
local Compat2 = LuaVersion < 5.4 and require("OOP.Version.LowerThan54") or require("OOP.Version.HigherThan53");
local Internal = require("OOP.Variant.Internal");
local ClassesChildren = Internal.ClassesChildren;

---Maps some value changes to subclasses.
---@param cls table
---@param keyTable table
---@param value any
local function Update2Children(cls,keyTable,value)
    local children = ClassesChildren[cls];
    for _,child in ipairs(children) do
        if nil == keyTable[child] then
            keyTable[child] = value;
        end
        Update2Children(child,keyTable,value)
    end
end
local function Update2ChildrenWithKey(cls,keyTable,key,value)
    local children = ClassesChildren[cls];
    for _,child in ipairs(children) do
        local t = keyTable[child];
        if t and nil == t[key]  then
            t[key] = value;
        end
        Update2ChildrenWithKey(child,keyTable,key,value)
    end
end

---Copy any value.
---
---@param any any
---@return any
---
local function Copy(any,existTab)
    if type(any) ~= "table" then
        return any;
    end
    if existTab then
        local ret = existTab[any];
        if nil ~= ret then
            return ret;
        end
    end

    existTab = existTab or {};
    local tempTab = {};
    existTab[any] = tempTab;
    for k,v in pairs(any) do
        tempTab[Copy(k,existTab)] = Copy(v,existTab);
    end
    return tempTab;
end

return {
    bits = Compat1.bits,
    FunctionWrapper = Compat2.FunctionWrapper,
    BreakFunctionWrapper = Compat2.BreakFunctionWrapper,
    Update2Children = Update2Children,
    Update2ChildrenWithKey = Update2ChildrenWithKey,
    Copy = Copy
};