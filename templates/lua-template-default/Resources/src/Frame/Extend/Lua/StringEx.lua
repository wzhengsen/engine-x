--[[-------------------------------------------
Module:	string
Auth:	wzhengsen
Date:	2019年04月03日
Desc:	为string新增了一些方法,如split,trim

Update: 新增了加解密（Encrypt,Decrypt）、
        编解码（Encode,Decode）、
        哈希值（Hash）
        的算法
---------------------------------------------]]
local crypto = require("crypto");

--	Func:	截取
--	Param:	string,string(截取符集合)
--	Return:	table
---------------------------------------------
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

--	Func:	除前后空白符
--	Param:	string
--	Return:	string
---------------------------------------------
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

--[[
    Func:   编码解码
    Param:  string
            string{
                URL
                Base64
                Hex
            }编解码类型
    Return: string
]]
function string:Encode(eType)
    eType = eType:upper();
    local encode = eType == "URL" and EncodeUrl or crypto["Encode" .. eType];
    if encode then
        -- 强制返回一个值。
        return (encode(self));
    end
    return nil;
end

function string:Decode(eType)
    eType = eType:upper();
    local decode = eType == "URL" and DecodeUrl or crypto["Decode" .. eType];
    if decode then
        -- 强制返回一个值。
        return (decode(self));
    end
    return nil;
end


--[[
    Func:   哈希计算
    Param:  string
            string{
                MD5
                SHA1
                SHA224
                SHA256
                SHA384
                SHA512
            }哈希类型
            boolean{true}   取哈希后是否进行16进制编码
    Return: string
]]
function string:Hash(eType, enc)
    local hash = crypto[eType:upper()];
    if hash then
        if enc == nil or enc then
            return hash(self):Encode("hex");
        end
        return hash(self);
    end
end


--[[
    Func:   加解密
    Param:  string
            string 密码
            密码默认长度16字节,不足部分补\0,超出部分截断
    Return: string
]]
string.Encrypt = crypto.Encrypt;
string.Decrypt = crypto.Decrypt;

--[[
    Return:     string
    Desc:       获取一个尽量不重复的字符串。
]]
function string.Unique()
    return (tostring({}) .. os.time() .. os.clock() .. math.random(1, 1000000)):Hash("sha1");
end

--[[
    Param:  table
]]
function string:Join(t)
    return table.concat(t, self);
end
