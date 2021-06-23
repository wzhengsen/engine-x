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

local require = require;
local rawset = rawset;
local type = type;
local select = select;

local Config = require("OOP.Config");
local Version = Config.Version;
local EnumBehavior = Config.EnumBehavior;
local Auto = Config.Auto;
local AllEnumerations = require("OOP.Variant.Internal");
local enum = setmetatable({},{
    __call = function (e,...)
        return e.New(...);
    end
});

local AutoIdx = 0;
if Config.Debug then
    enum[Auto] = function(...)
        local len = select("#",...)
        if len > 1 then
            error(("%s function can't receive more than one parameters."):format(Auto));
        end
        AutoIdx = len == 0 and AutoIdx + 1 or ...;
        return AutoIdx;
    end;

    function enum.New(first,...)
        local fT = type(first);
        local isString = fT == "string"
        assert(isString or fT == "table","Only strings or tables can be used to generate a enumeration.")
        if not isString then
            assert(select("#",...) == 0,"Excess parameters.");
        end
        local e = isString and {} or first;
        if isString then
            for k,v in ipairs({first,...}) do
                e[v] = k;
            end
        end

        if EnumBehavior == 2 then
            AllEnumerations[e] = true;
            return e;
        end
        local _enum = {};
        AllEnumerations[_enum] = true;
        return setmetatable(_enum,{
            __index = e,
            __newindex = function ()
                if EnumBehavior == 0 then
                    if Version > 5.4 then
                        warn("You can't edit a enumeration.");
                    end
                elseif EnumBehavior == 1 then
                    error("You can't edit a enumeration.");
                end
            end
        });
    end
else
    enum[Auto] = function(...)
        local len = select("#",...)
        AutoIdx = len == 0 and AutoIdx + 1 or ...;
        return AutoIdx;
    end;
    function enum.New(first,...)
        local isString = type(first) == "string"
        local e = isString and {} or first;
        if isString then
            for k,v in ipairs({first,...}) do
                e[v] = k;
            end
        end
        AllEnumerations[e] = true;
        return e;
    end
end
rawset(_G,Config.enum,enum);