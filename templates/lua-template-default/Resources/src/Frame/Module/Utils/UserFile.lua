-- Copyright (c) 2021 wzhengsen

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

---类型前缀，每种类型均以字符串保存，并添加对应前缀。
local TypePrefix = {
    string          = "_@_TS",
    boolean         = "_@_TB",
    number          = "_@_TN",
    table           = "_@_TT",
    ["function"]    = "_@_TF",

    -- 反向查询映射
    ["_@_TS"] = "S",
    ["_@_TB"] = "B",
    ["_@_TN"] = "N",
    ["_@_TT"] = "T",
    ["_@_TF"] = "F"
};

local type = type;
local rawset = rawset;
local tostring = tostring;
local UserDefault = cc.UserDefault;
--直接使用UserFile来操作UserDefault的文件。
--该类不可实例化，其所有方法和属性都是静态的。
local UserFile = setmetatable({
    -- 使用该值作为加密和解密密码。
    Key = nil
},
{
    __newindex = function (t,k,v)
        if k == "Key" then
            rawset(t,k,v);
        end
        -- 仅布尔/数值/字符串能作为键。
        local kType = type(k);
        if "table" == kType or "function" == kType or not TypePrefix[kType] then
            return;
        end
        k = tostring(k);
        if nil == v then
            UserDefault.Instance:DeleteValueForKey(k);
        else
            local prefix = TypePrefix[type(v)];
            if prefix then
                local key = t.Key;
                if prefix == TypePrefix.table then
                    v = cjson.encode(v) or "";
                elseif prefix == TypePrefix["function"] then
                    -- 可以保存函数，但不能保存函数的上值，已有的上值被初始化为nil。
                    v = string.dump(v);
                else
                    v = tostring(v);
                end
                UserDefault.Instance:SetStringForKey(k,prefix .. (key and v:Encrypt(key) or v));
            end
        end
    end,
    __index = function (t,k)
        if k == "Key" then
            return nil;
        end
        -- 仅布尔/数值/字符串能作为键。
        local kType = type(k);
        if "table" == kType or "function" == kType or not TypePrefix[kType] then
            return nil;
        end
        k = tostring(k);
        local val = UserDefault.Instance:GetStringForKey(k,"");
        if "" == val then
            return nil;
        end
        local vType = TypePrefix[val:sub(1,5)];
        if vType then
            local ret = val:sub(6);
            local key = t.Key;
            ret = key and ret:Decrypt(key) or ret;
            if "N" == vType then
                return cc.ToNumber(ret);
            elseif "S" == vType then
                return ret;
            elseif "B" == vType then
                return cc.ToBoolean(ret);
            elseif "T" == vType then
                return cjson.decode(ret);
            elseif "F" == vType then
                return load(ret);
            end
        end
    end
});

---清空映射文件。
---
function UserFile.Clear()
    UserDefault.Instance:Clear();
end

cc.UserFile = UserFile;