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

---@class stringex
---@field Convert fun(to:string,from:string):string
local string = string;
local crypto = require("crypto");

---按分隔符截取字符串。
---@param sep string (截取符集合)
---@param cFunc? function
---@return table
function string:Split(sep, cFunc)
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
function string:Trim()
    return self:match("^%s*(.-)%s*$") or "";
end

local function EncodeUrl(input)
    -- convert line endings
    return input:gsub("\n", "\r\n"):gsub(
        -- escape all characters but alphanumeric, -_.!~*'()
        "([^%w%-%_%.%!%~%*%'%(%) ])",
        function(char)
            return "%" .. ("%02X"):format(char:byte());
        end
    ):gsub(" ", "+");
    -- convert spaces to "+" symbols
end

local function DecodeUrl(input)
    return input:gsub("+", " "):gsub(
        "%%(%x%x)",
        function(h)
            return string.char(tonumber(h, 16));
        end
    ):gsub("\r\n", "\n");
end

---对字符串按指定方式编码。
---@param eType | "\"Url\"" | "\"Base64\"" | "\"Hex\""
---@return string?
function string:Encode(eType)
    eType = eType:upper();
    local encode = eType == "URL" and EncodeUrl or crypto["Encode" .. eType];
    if encode then
        -- 强制返回一个值。
        return (encode(self));
    end
    return nil;
end

---对字符串按指定方式解码。
---@param eType | "\"Url\"" | "\"Base64\"" | "\"Hex\""
---@return string?
function string:Decode(eType)
    eType = eType:upper();
    local decode = eType == "URL" and DecodeUrl or crypto["Decode" .. eType];
    if decode then
        -- 强制返回一个值。
        return (decode(self));
    end
    return nil;
end

---计算字符串的哈希值。
---@param eType | "\"Md5\"" | "\"Sha1\"" | "\"Sha224\"" | "\"Sha256\"" | "\"Sha384\"" | "\"Sha512\""
---@param enc? boolean {true}取哈希后是否进行16进制编码。
---@return string?
function string:Hash(eType, enc)
    local hash = crypto[eType:upper()];
    if hash then
        if enc == nil or enc then
            return hash(self):Encode("hex");
        end
        return hash(self);
    end
end


---加密字符串。
---@type fun(pwd:string):string
---@param pwd string 密码默认长度16字节,不足部分补\0,超出部分截断
---@return string
string.Encrypt = crypto.Encrypt;

---解密字符串。
---@type fun(pwd:string):string
---@param pwd string 密码默认长度16字节,不足部分补\0,超出部分截断
---@return string
string.Decrypt = crypto.Decrypt;

---获取一个尽量不重复的字符串。
---@return string
function string.Unique()
    return (tostring({}) .. os.time() .. os.clock() .. math.random(1, 1000000)):Hash("Sha1");
end

---字符串连接，类似python str.join。
---@param t table
---@return string
function string:Join(t)
    return table.concat(t, self);
end
