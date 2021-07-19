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

---为string新增了一些方法,如Split,Trim,Encrypt,Decrypt,Encode,Decode,Hash等。
local crypto = cc.Crypto;
local clock = os.clock;
local time = os.time;
local random = math.random;
local concat = table.concat;
local tostring = tostring;
local type = type;
local mtype = math.type;
local sub = string.sub;

---按分隔符截取字符串。
---@param sep string (截取符集合)
---@param cFunc? function
---@return table
function string:split(sep, cFunc)
    local fields = {};
    self:gsub(
        "([^" .. sep .. "]*)",
        function(c)
            if cFunc then
                c = cFunc(c);
            end
            fields[#fields + 1] = c;
        end
    )
    return fields;
end

---除前后空白符。
---@return string
function string:trim()
    return self:match("^%s*(.-)%s*$") or "";
end

---对字符串按指定方式编码。
---@param codec | "\"url\"" | "\"base64\"" | "\"hex\""
---@return string
function string:encode(codec)
    return crypto.Encode(self,crypto.EncodeMode[codec:upper()]);
end

---对字符串按指定方式解码。
---@param codec | "\"url\"" | "\"base64\"" | "\"hex\""
---@return string
function string:decode(codec)
    return crypto.Decode(self,crypto.EncodeMode[codec:upper()]);
end

---计算字符串的哈希值。
---@param hash | "\"md5\"" | "\"sha1\"" | "\"sha224\"" | "\"sha256\"" | "\"sha384\"" | "\"sha512\""
---@return string
function string:hash(hash)
    return crypto[hash:upper()](self);
end

---加密字符串。
---@type fun(str:string,pwd:string,iv?:string):string
---@param str string 待加密字符串。
---@param pwd string 密码默认长度16字节,不足部分补\0,超出部分截断。
---@param iv? string 初始向量默认长度16字节,不足部分补\0,超出部分截断。
---@return string
string.encrypt = crypto.Encrypt;

---解密字符串。
---@type fun(str:string,pwd:string,iv?:string):string
---@param str string 待解密字符串。
---@param pwd string 密码默认长度16字节,不足部分补\0,超出部分截断。
---@param iv? string 初始向量默认长度16字节,不足部分补\0,超出部分截断。
---@return string
string.decrypt = crypto.Decrypt;

---将字符串从一种编码转换到另一种编码。
---如：("你好世界！"):convert("utf-8","gbk//TRANSLIT");
---@type fun(str:string,from:string,to:string):string,boolean
---@param str   string  待转换的字符串。
---@param from  string  原字符串的编码。
---@param to    string  欲转换到的编码。
---@return string       转换后的结果。
---@return boolean      是否所有字符都全部转换。
string.convert = ccu.Convert;

---获取一个尽量不重复的字符串。
---@param short? boolean    是否返回一个较短的串（碰撞的概率也更大）。
---@return string
function string.unique(short)
    return (tostring({}) .. time() .. clock() .. random(1, 1000000)):hash(short and "md5" or "sha512");
end

---字符串连接，类似python str.join。
---@param t table
---@return string
function string:join(t)
    return concat(t, self);
end

---字符串迭代。
---@return function
function string:ipairs()
    local idx,len = 0,#self;
    return function ()
        idx = idx + 1
        if idx > len then
            return nil,nil;
        end
        return idx,sub(self,idx,idx);
    end
end

-- 字符串下标取值。
-- 与string.sub不同的是，使用下标取值时，当下标越界时，返回nil而不是返回空串。
-- 相应的，负值下标表示从后往前。
local smt = getmetatable("");
local __index = smt.__index;
smt.__index = function (self,key)
    if type(key) == "number" and mtype(key) == "integer" then
        local len = #self;
        key = key < 0 and len + key + 1 or key;
        if key <= 0 or key > len then
            return nil;
        end
        return sub(self,key,key);
    else
        return __index[key];
    end
end
