--[[
    File:       Convert.lua
    Func:       一些和转换相关的封装。
    Content:    如阿拉伯数字转中文数，数字的千分位截断，
                一些类型强制转换等。
]]
local Convert = {}


--[[
    Func:   将数字以千分位截断
    Param:  number
    Return: string
    Desc:   转换失败返回nil
]]
function Convert.Kilodigit(num)
    num = tonumber(num)
    if not num then
        return nil
    end
    local formatted = tostring(num)
    local k = nil
    while true do
        formatted, k = formatted:gsub("^(-?%d+)(%d%d%d)", "%1,%2")
        if k == 0 then break end
    end
    return formatted
end

Convert.ChineseNumberUpper = {
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
}
Convert.ChineseNumberLower = {
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
}

--[[
    Func:   小数部分转换
]]
local function transfromFloat2Chinese(numStr,b)
    if numStr == 0 then
        return ""
    end
    -- 去掉首位0
    numStr = tostring(numStr):sub(2)
    local cTab = b and Convert.ChineseNumberUpper or Convert.ChineseNumberLower

    local ret = {}
    for i = 1,#numStr do
        local char = numStr:sub(i,i)
        ret[i] = cTab[tonumber(char) or char] or ""
    end

    return table.concat(ret)
end

--[[
    Func:   整数部分转换
]]
local function transfromInt2Chinese(num,np,b)
    local cTab = b and Convert.ChineseNumberUpper or Convert.ChineseNumberLower
    if 0 == num then
        return cTab[0]
    end

    local retStr = ""
    -- 指示上一个值是否为0，连续的0不需要多次转换为“零”或“〇”
    local lastZero = true
    while np > 0 do
        local dV = num // np
        -- 获取单位
        local unit = np >= 10 and cTab[np]
        if dV ~= 0 and (unit or np < 10) then
            local numStr = ""
            if np == 100000000 then
                -- 最高转换单位为“亿”，超过100000000的部分再次尝试转换
                numStr = transfromInt2Chinese(dV,np,b)
            else
                -- 获取转换值，如千万、百万等没有对应单位的，再次尝试转换
                numStr = cTab[dV] or transfromInt2Chinese(dV,10000,b)
            end
            if np >= 10 then
                -- 因为没有单位“个”，所以大于10的数才拼接单位
                retStr = retStr .. numStr .. unit
            else
                retStr = retStr .. numStr
            end
            lastZero = false
        elseif dV == 0 and not lastZero and num ~= 0 then
            lastZero = true
            retStr = retStr .. cTab[0]
        end
        if unit then
            num = num % np
        end
        np = np // 10
    end

    return retStr
end

--[[
    Func:   将数字转换为中文
    Param:  number              待转换数字
            boolean{true}       是否使用大写转换
    Return: string
    Desc:   转换失败返回nil
]]
function Convert.ChineseNumber(num,b)
    num = tonumber(num)
    if not num then
        return nil
    end
    local isNegative = num < 0
    num = math.abs(num)
    b = nil == b and true

    -- 分割为整数和小数
    local iNum,fNum = math.modf(num)
    -- 小数
    local fNumStr = transfromFloat2Chinese(fNum,b)
    -- 整数
    local iNumStr = transfromInt2Chinese(iNum,100000000,b)
    if isNegative then
        return "负" .. iNumStr .. fNumStr
    end
    return iNumStr .. fNumStr
end



--[[
    一些基本类型转换。
]]
function Convert.ToBoolean(obj)
    if obj then
        return true
    end
    return false
end

function Convert.ToNumber(num)
    return tonumber(num) or 0
end

function Convert.ToDouble(num)
    return (tonumber(num) or 0) + 0.0
end

function Convert.ToInteger(num)
    return math.floor(tonumber(num) or 0)
end

function Convert.ToString(str)
    if str == nil then return "" end
    return tostring(str)
end

return Convert