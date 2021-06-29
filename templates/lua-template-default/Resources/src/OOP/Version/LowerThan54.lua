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
local Version = Config.Version;
local unpack = Version < 5.2 and unpack or table.unpack;
local setmetatable = setmetatable;
local insert = table.insert;
local remove = table.remove;
local pcall = pcall;
local error = error;

---
---Wrapping the given function so that it handles the push and pop of the access stack correctly anyway,
--to avoid the access stack being corrupted by an error being thrown in one of the callbacks.
---@param aStack table
---@param cls table
---@param f function
---@vararg any
---@return ...
---
local AllFunctions = setmetatable({},{__mode = "k"});
local AccessStack = require("OOP.Variant.Internal").AccessStack;
local function FunctionWrapper(cls,f)
    local newF = AllFunctions[f]
    if nil == newF then
        newF = function(...)
            insert(AccessStack,cls);
            local ret = {pcall(f,...)};
            remove(AccessStack);
            if not ret[1] then
                error(ret[2]);
            end
            return unpack(ret,2);
        end;
        AllFunctions[newF] = newF;
        AllFunctions[f] = newF;
    end
    return newF;
end

local function BreakFunctionWrapper(f)
    local newF = AllFunctions[f]
    if nil == newF then
        newF = function(...)
            -- 0 means that any access rights can be broken.
            insert(AccessStack,0);
            local ret = {pcall(f,...)};
            remove(AccessStack);
            if not ret[1] then
                error(ret[2]);
            end
            return unpack(ret,2);
        end;
        AllFunctions[newF] = newF;
        AllFunctions[f] = newF;
    end
    return newF;
end

return {
    FunctionWrapper = FunctionWrapper,
    BreakFunctionWrapper = BreakFunctionWrapper
};