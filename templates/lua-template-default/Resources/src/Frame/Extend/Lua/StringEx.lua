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
local crypto = require("crypto")

--	Func:	截取
--	Param:	string,string(截取符集合)
--	Return:	table
---------------------------------------------
function string.Split(s,sep,cFunc)
    local fields = {}
    s:gsub("([^"..sep.."]*)",
    function(c)
        if cFunc then
            c = cFunc(c)
        end
        fields[#fields + 1] = c
    end)
    return fields
end

--	Func:	除前后空白符
--	Param:	string
--	Return:	string
---------------------------------------------
function string.Trim(s)
    return s:match("%S.*%S") or ""
end

function string.EncodeUrl(input)
    -- convert line endings
    return input:gsub("\n","\r\n"):
    -- escape all characters but alphanumeric, -_.!~*'()
    gsub("([^%w%-%_%.%!%~%*%'%(%) ])",function(char) return "%" .. ("%02X"):format(char:byte()) end):
    -- convert spaces to "+" symbols
    gsub(" ","+")
end
string.EncodeURL = string.EncodeUrl;

function string.DecodeUrl(input)
    return input:gsub("+"," "):
    gsub("%%(%x%x)",function(h) return string.char(tonumber(h,16)) end):
    gsub("\r\n", "\n")
end
string.DecodeURL = string.DecodeUrl;

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
function string.Encode(str,eType)
    eType = eType:upper()
    local lib = eType == "URL" and string or crypto
    local encode = lib["Encode"..eType]
    if encode then
        -- 强制返回一个值。
        return (encode(str));
    end
end

function string.Decode(str,eType)
    eType = eType:upper()
    local lib = eType == "URL" and string or crypto
    local decode = lib["Decode"..eType]
    if decode then
        -- 强制返回一个值。
        return (decode(str));
    end
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
function string.Hash(str,eType,enc)
    local hash = crypto[eType:upper()];
    if hash then
        if enc == nil or enc then
            return hash(str):Encode("hex");
        end
        return hash(str);
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
    return (tostring({}) .. os.time() .. os.clock() .. math.random(1,1000000)):Hash("sha1");
end