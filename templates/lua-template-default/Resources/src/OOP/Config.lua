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

local Version = tonumber(_VERSION:sub(5)) or 5.1;
if Version >= 5.4 then
    warn("@on");
end
local Config = {
    Version = Version,

    --****************Rename fields start****************
    -- If you need to rename some of the LuaOOP names to suit specific needs,
    -- please qualify the following mapping.

    class = "class",

    enum = "enum",

    event = "event",

    handlers = "handlers",

    IsNull = "IsNull",
    Break = "Break",

    Auto = "Auto",

    set = "set",
    get = "get",

    friends = "friends",

    -- If __singleton__ is defined,
    -- then the class can only access the singleton using the Instance property
    -- and "new" will be automatically modified to the protected.
    __singleton__ = "__singleton__",

    -- Constructor and destructor names.
    __new__ = "__new__",
    __delete__ = "__delete__",

    ctor = "ctor",
    dtor = "dtor",

    -- Constructor and destructor method names.
    new = "new",
    delete = "delete",

    -- "is" method name.
    is = "is",

    -- Meta function names.
    -- You must implement the meta-function to make it work which is named Meta's value.
    Meta = {
        __add = "__add__",
        __sub = "__sub__",
        __mul = "__mul__",
        __mod = "__mod__",
        __pow = "__pow__",
        __div = "__div__",
        __unm = "__unm__",

        __lt = "__lt__",
        __le = "__le__",
        __concat = "__concat__",
        __call = "__call__",
        __gc = "__gc__",
        __eq = "__eq__",
        __pairs = "__pairs__",
        __len = "__len__",
        __tostring = "__tostring__",

        __idiv = Version > 5.2 and "__idiv__" or nil,
        __band = Version > 5.2 and "__band__" or nil,
        __bor = Version > 5.2 and "__bor__" or nil,
        __bxor = Version > 5.2 and "__bxor__" or nil,
        __shl = Version > 5.2 and "__shl__" or nil,
        __shr = Version > 5.2 and "__shr__" or nil,
        __bnot = Version > 5.2 and "__bnot__" or nil,

        __close = Version > 5.3 and "__close__" or nil
    },

    -- Qualifiers names.
    Qualifiers = {
        public = "public",
        private = "private",
        protected = "protected",

        static = "static",
        const = "const",

        final = "final",

        virtual = "virtual"
    },

    -- If __singleton__ is defined,
    -- this property will be generated automatically.
    Instance = "Instance",

    -- If a table has this key,means that the table is dead.
    DeathMarker = {},

    --****************Rename fields end****************


    --****************Functional fields start****************
    -- The following are functional configurations.

    -- Indicates whether the current mode is debug or not.
    -- When false, a more optimized speed will be used.
    Debug = true,

    -- What is the behavior when you use properties incorrectly?
    -- For example, writing a read-only property,
    -- or reading a write-only property.
    -- It works with Debug mode only.
    -- All incorrect operations will be allowed in non-debug mode.
    -------------------------------------
    -- 0 -> warning(for lua5.4 and after)
    -- 1 -> error
    -- 2 -> allow
    -- other -> ignore
    -------------------------------------
    PropertyBehavior = 1,

    -- Same as PropertyBehavior.
    ConstBehavior = 1,

    -- Same as PropertyBehavior.
    EnumBehavior = 1,

    -- Used to extend inherited external classes.
    ExternalClass = {
        ---Function to determine if userdata is empty.
        ---@type fun(p:userdata):boolean
        Null = nil,

        ---Function to determine if a external class inherits from another external class.
        ---A class can be judged as inheriting itself.
        ---@type fun(cls:table,base:table):boolean
        IsInherite = nil,
    },

    -- When the number of holes in the event response objects reaches a certain number,
    -- the list of objects is rearranged to optimise speed.
    HoleLimit = 15,

    -- The language configuration, with a nil value, means that English is used by default.
    -- Currently only English and Chinese are available, use "zh" for Chinese.
    Language = nil,

    --****************Functional fields end****************

    __cls__ = "🧬"
};

-- Reverse mapping to meta method names.
local MetaMapName = {};
Config.MetaMapName = MetaMapName;
for meta,name in pairs(Config.Meta) do
    MetaMapName[name] = meta;
end

return Config;