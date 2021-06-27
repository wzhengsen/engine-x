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
local i18n = require("OOP.i18n");
local modf = math.modf;
local assert = assert;
local floor = math.floor;
local bits = Config.Version == 5.2 and bit32 or {
    band = function (a,b)
        local _,floatA = modf(a);
        local _,floatB = modf(b);
        assert(floatA == 0 and floatB == 0 and a >= 0 and b >= 0 and a ~= math.huge and b ~= math.huge,i18n"Illegal operand.");
        local ret = 0;
        for i = 1,32 do
            if a == 0 or b == 0 then
                break;
            end
            if a % 2 == 1 and b % 2 == 1 then
                ret = ret + 2 ^ (i - 1);
            end
            a = floor(a / 2);
            b = floor(b / 2);
        end
        return ret;
    end,
    bor = function (a,b)
        local _,floatA = modf(a);
        local _,floatB = modf(b);
        assert(floatA == 0 and floatB == 0 and a >= 0 and b >= 0 and a ~= math.huge and b ~= math.huge,i18n"Illegal operand.");
        local ret = 0;
        for i = 1,32 do
            if a == 0 and b == 0 then
                break;
            end
            if a % 2 == 1 or b % 2 == 1 then
                ret = ret + 2 ^ (i - 1);
            end
            a = floor(a / 2);
            b = floor(b / 2);
        end
        return ret;
    end
};

return {
    bits = bits
};