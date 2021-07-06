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

require("OOP.Enum");
local Config = require("OOP.Config");
local Internal = require("OOP.Variant.Internal");
local Null = Config.ExternalClass.Null;
local DeathMarker = Config.DeathMarker;
local IsNull = Config.IsNull;
local final = Config.Qualifiers.final;
local FinalClasses = Internal.FinalClasses;
local ClassDefault = Config["class.default"];
local ClassDelete = Config["class.delete"];
local i18n = require("OOP.i18n");

local class = setmetatable({},{
    __call = function(c,...)
        return c.New(...)
    end
});
rawset(_G,Config.class,class);

local _IsNull = Null and function(t)
    local tt = type(t);
    if tt == "table" then
        return rawget(t,DeathMarker);
    elseif tt == "userdata" then
        return Null(t);
    end
    return not t;
end or
function(t)
    if type(t) == "table" then
        return rawget(t,DeathMarker);
    end
    return not t;
end;
class[IsNull] = _IsNull;

class[final] = function (...)
    local cls = class(...);
    FinalClasses[cls] = true;
    return cls;
end

class[ClassDefault] = function ()end;
class[ClassDelete] = function () error(i18n"This is the function that has been deleted.");end;

return class;