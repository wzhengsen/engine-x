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

--[[
    File:       一些和转换相关的封装。
    Content:    如阿拉伯数字转中文数，数字的千分位截断，
                一些类型强制转换等。
]]

---将数字或任意可以转换为数字的内容以千分位截断，不能转换的内容返回nil。
---
---@param num any
---@return string?
---
function cc.ToKilodigit(num)
    num = tonumber(num);
    if not num then
        return nil;
    end
    local formatted = tostring(num);
    local k = nil;
    while true do
        formatted, k = formatted:gsub("^(-?%d+)(%d%d%d)", "%1,%2");
        if k == 0 then
            break;
        end
    end
    return formatted;
end

local ChineseNumberUpper = {
    ["."] = "点",
    [0] = "零",
    [1] = "壹",
    [2] = "贰",
    [3] = "叁",
    [4] = "肆",
    [5] = "伍",
    [6] = "陆",
    [7] = "柒",
    [8] = "捌",
    [9] = "玖",
    [10] = "拾",
    [100] = "百",
    [1000] = "千",
    [10000] = "万",
    [100000000] = "亿"
};
local ChineseNumberLower = {
    ["."] = "点",
    [0] = "〇",
    [1] = "一",
    [2] = "二",
    [3] = "三",
    [4] = "四",
    [5] = "五",
    [6] = "六",
    [7] = "七",
    [8] = "八",
    [9] = "九",
    [10] = "十",
    [100] = "百",
    [1000] = "千",
    [10000] = "万",
    [100000000] = "亿"
};

--[[
    Func:   小数部分转换
]]
local function TransfromFloat2Chinese(numStr,b)
    local cTab = b and ChineseNumberUpper or ChineseNumberLower;

    local ret = {};
    for i = 1,#numStr do
        local char = numStr:sub(i,i);
        ret[i] = cTab[tonumber(char) or char] or "";
    end

    return table.concat(ret);
end

--[[
    Func:   整数部分转换
]]
local function TransfromInt2Chinese(num,np,b)
    local cTab = b and ChineseNumberUpper or ChineseNumberLower;
    if 0 == num then
        return cTab[0];
    end

    local retStr = "";
    -- 指示上一个值是否为0，连续的0不需要多次转换为“零”或“〇”
    local lastZero = true;
    while np > 0 do
        local dV = num // np;
        -- 获取单位
        local unit = np >= 10 and cTab[np];
        if dV ~= 0 and (unit or np < 10) then
            local numStr = "";
            if np == 100000000 then
                -- 最高转换单位为“亿”，超过100000000的部分再次尝试转换
                numStr = TransfromInt2Chinese(dV,np,b);
            else
                -- 获取转换值，如千万、百万等没有对应单位的，再次尝试转换
                numStr = cTab[dV] or TransfromInt2Chinese(dV,10000,b);
            end
            if np >= 10 then
                -- 因为没有单位“个”，所以大于10的数才拼接单位
                retStr = retStr .. numStr .. unit;
            else
                retStr = retStr .. numStr;
            end
            lastZero = false;
        elseif dV == 0 and not lastZero and num ~= 0 then
            lastZero = true;
            retStr = retStr .. cTab[0];
        end
        if unit then
            num = num % np;
        end
        np = np // 10;
    end

    return retStr;
end

---将数字或任意可以转换为数字的内容转换为中文，不能转换的内容将返回nil。
---
---@param num any
---@param b? boolean {true}是否使用大写转换
---@return string?
---
function cc.ToChinese(num,b)
    num = tonumber(num);
    if not num then
        return nil;
    end
    if math.huge == num then
        return "无穷";
    elseif -math.huge == num then
        return "负无穷";
    end
    local isNegative = num < 0;
    num = math.abs(num);
    b = nil == b or b;

    -- 分割为整数和小数
    local iNum,fNum = math.modf(num);
    local fNumStr = "";
    if fNum ~= 0.0 then
        fNumStr = tostring(fNum);
        local eIdx = fNumStr:find("e");
        if eIdx then
            local e = cc.ToInteger(fNumStr:sub(eIdx + 2));
            local pre = fNumStr:sub(1,eIdx - 1):gsub("%.","");
            fNumStr = "." .. ("0"):rep(e - 1) .. pre;
        else
            -- 为确保精度，将小数部分截取到和实际传入的等长。
            local numStr = tostring(num);
            local dotIdx = numStr:find(".",1,true);
            if dotIdx then
                fNumStr = numStr:sub(dotIdx);
            end
        end

        -- 小数
        fNumStr = TransfromFloat2Chinese(fNumStr,b);
    end
    -- 整数
    local iNumStr = TransfromInt2Chinese(iNum,100000000,b);
    if isNegative then
        return "负" .. iNumStr .. fNumStr;
    end
    return iNumStr .. fNumStr;
end

--[[
    一些基本类型转换。
]]

---转换任意值为布尔值，无论该值能不能被转换，一定会返回布尔值，且不会抛出错误。
---
---@param obj any
---@return boolean
---
function cc.ToBoolean(obj)
    if obj then
        return true;
    end
    return false;
end

---转换任意值为数字，无论该值能不能被转换，一定会返回数字类型，且不会抛出错误。
---
---@param num any
---@return number
---
function cc.ToNumber(num)
    return tonumber(num) or 0;
end

---转换任意值为双精度浮点型，无论该值能不能被转换，一定会返回双精度浮点型，且不会抛出错误。
---
---@param num any
---@return number
---
function cc.ToDouble(num)
    return (tonumber(num) or 0) + 0.0;
end

---转换任意值为整型，无论该值能不能被转换，一定会返回整型，且不会抛出错误。
---
---@param num any
---@return number
---
function cc.ToInteger(num)
    return math.floor(tonumber(num) or 0);
end

---转换任意值为字符串，无论该值能不能被转换，一定会返回字符串，且不会抛出错误。
---特别的，nil将被转换为""，而不是"nil"，这和lua的默认行为不同。
---
---@param str any
---@return string
---
function cc.ToString(str)
    if str == nil then return ""; end
    return tostring(str);
end