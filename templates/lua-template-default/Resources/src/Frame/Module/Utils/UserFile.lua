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
    ["function"]    = "_@_TF"
};

local type = type;
local rawset = rawset;
local tostring = tostring;
local UserDefault = cc.UserDefault;
--直接使用UserFile来操作UserDefault的文件。
--该类不可实例化，其所有方法和属性都是静态的。
local UserFile = {
    Key = nil;
};

---清空映射文件。
---
function UserFile.Clear()
    UserDefault.Instance:Clear();
end

setmetatable(UserFile,
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
                local _key = t.Key;
                if prefix == TypePrefix.table then
                    -- 将表中可能嵌套存在的函数全部序列化。
                    for tab,key,val in apairs(v) do
                        if "function" == type(val) then
                            tab[key] = TypePrefix["function"]..(string.dump(val));
                        end
                    end
                    v = cjson.encode(v) or "";
                elseif prefix == TypePrefix["function"] then
                    -- 可以保存函数，但不能保存函数的上值，已有的上值被初始化为nil。
                    v = string.dump(v);
                else
                    v = tostring(v);
                end
                UserDefault.Instance:SetStringForKey(k,prefix .. (_key and v:Encrypt(_key) or v));
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
        local v = UserDefault.Instance:GetStringForKey(k,"");
        if "" == v then
            return nil;
        end
        local vType = v:sub(1,5);
        if vType then
            local ret = v:sub(6);
            local _key = t.Key;
            ret = _key and ret:Decrypt(_key) or ret;
            if TypePrefix.number == vType then
                return cc.ToNumber(ret);
            elseif TypePrefix.string == vType then
                return ret;
            elseif TypePrefix.boolean == vType then
                if "true" == ret then
                    return true
                elseif "false" == ret then
                    return false;
                end
                return ret;
            elseif TypePrefix.table == vType then
                local retTab = cjson.decode(ret);
                -- 将表中可能嵌套存在的已被序列化的函数全部反序列化。
                if retTab then
                    for tab,key,val in apairs(retTab) do
                        if "string" == type(val) and TypePrefix["function"] == val:sub(1,5) then
                            tab[key] = (load(val:sub(6)));
                        end
                    end
                end
                return retTab;
            elseif TypePrefix["function"] == vType then
                return load(ret);
            end
        end
    end
});

cc.UserFile = UserFile;

return UserFile;