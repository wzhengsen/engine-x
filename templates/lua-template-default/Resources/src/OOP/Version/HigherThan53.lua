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
local insert = table.insert;
local remove = table.remove;
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
local RAII = setmetatable({},{
    __close = function ()
        remove(AccessStack);
    end
});
local function FunctionWrapper(cls,f)
    if AllFunctions[f] then
        return f;
    end
    local newF = function(...)
        insert(AccessStack,cls);
        local _<close> = RAII;
        return f(...);
    end
    AllFunctions[newF] = true;
    AllFunctions[f] = true;
    return newF;
end

return {
    FunctionWrapper = FunctionWrapper
};