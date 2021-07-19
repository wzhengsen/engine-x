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

local type = type;
local pairs = pairs;
local ipairs = ipairs;
local setmetatable = setmetatable;
local getmetatable = getmetatable;
local random = math.random;

-- 为table新增了一些方法,如union,copy,filter

---筛选符合要求的键值对。
---@param t table
---@param fv any | "function(key,value)\n    return true;\nend"
---@return table
function table.filter(t,fv)
    local isFunction = type(fv) == "function";
    local ret = {};
    if isFunction then
        for k,v in pairs(t) do
            if fv(k,v) then
                ret[k] = v;
            end
        end
    else
        for k,v in pairs(t) do
            if fv == v then
                ret[k] = v;
            end
        end
    end
    return ret;
end

local function copy(cTab,existTab)
    if type(cTab) ~= "table" then
        return cTab;
    elseif nil ~= existTab[cTab] then
        return existTab[cTab];
    end

    local tempTab = {};
    --将当前表加入已存在表，并为已存在表赋值
    existTab[cTab] = tempTab;
    for k,v in pairs(cTab) do
        --若任意键值在已存在表中，则将键值赋值为存在表的值
        --避免如下情况引起的死循环：
        --local a = {}
        --a[a] = a
        tempTab[copy(k,existTab)] = copy(v,existTab);
    end
    return tempTab;
end

---拷贝一个表，使用深拷贝。
---userdata/thread等无法拷贝
---@param tab table
---@param copyMeta? boolean {false}是否拷贝元表。
---@return table
function table.copy(tab,copyMeta)
    local retTab = copy(tab,{});
    if copyMeta then
        setmetatable(retTab,getmetatable(tab));
    end
    return retTab;
end

---合并t2表到t1表。
---@param t1 table
---@param t2 table
function table.merge(t1,t2)
    for k,v in pairs(t2) do
        t1[k] = v;
    end
end

---当t1表和t2表作为数组时，将t2追加到t1。
---@param t1 table
---@param t2 table
function table.append(t1,t2)
    local len = #t1;
    for _,v in ipairs(t2) do
        len = len + 1;
        t1[len] = v;
    end
end

---将多个表合并为一个新的表，并返回新表。
---@vararg table
---@return table
function table.union(...)
    local union = {};
    for _,tab in pairs({...}) do
        for k,v in pairs(tab) do
            union[k] = v;
        end
    end
    return union;
end

---求表中元素总数或某种元素总数。
---@param tab table
---@param fv? any | "function(key,value)\n    return true;\nend"
---@return integer
function table.count(tab,fv)
    local isFunction = type(fv) == "function";
    local size = 0;
    if fv == nil then
        for _,_ in pairs(tab) do
            size = size + 1;
        end
    else
        if isFunction then
            for k,v in pairs(tab) do
                if fv(k,v) then
                    size = size + 1;
                end
            end
        else
            for _,v in pairs(tab) do
                if fv == v then
                    size = size + 1;
                end
            end
        end
    end
    return size;
end


---在表中查找指定元素，并返回对应的键。
---只返回第一个匹配的元素。
---@param tab table
---@param fv any | "function(v,value)\n    return true;\nend"
---@return any
function table.find(tab,fv)
    local isFunction = type(fv) == "function";
    if not isFunction then
        for k,v in pairs(tab) do
            if v == fv then
                return k;
            end
        end
    else
        for k,v in pairs(tab) do
            if fv(v) then
                return k;
            end
        end
    end
    return nil;
end

---给定一个顺序表，将其元素顺序打乱。
---@param tab table
function table.mess(tab)
    local len = #tab;
    for i = 1,len do
        local index = random(1,len);
        tab[i],tab[index] = tab[index],tab[i];
    end
end

---给定一个表，返回第一个空洞的位置。
---一个正常的顺序表，第一个空洞在其尾部。
---@param tab table
---@return integer
function table.hole(tab)
    local k = 1;
    while nil ~= tab[k] do
        k = k + 1;
    end
    return k;
end

---筛选给定表中的值，只保留唯一的值，并返回一个包含该值的新表。
---@param t table
---@param bArray? boolean {true}是否以数组返回
---@return table
function table.unique(t,bArray)
    bArray = nil == bArray or bArray;
    local check = {};
    local n = {};
    local idx = 1;
    for k, v in pairs(t) do
        if not check[v] then
            if bArray then
                n[idx] = v;
                idx = idx + 1;
            else
                n[k] = v;
            end
            check[v] = true;
        end
    end
    return n;
end

local empty = function()end
---创建一个表的只读代理。
---@param tab table
---@return table
function table.readonly(tab)
    return setmetatable({},{
        __index = tab,
        __newindex = empty
    });
end

---创建表的子表。
---@param tab table
---@param idx1 integer      为负数时，从尾部计算索引。
---@param idx2? integer     为负数时，从尾部计算索引。
---@return table
function table.sub(tab,idx1,idx2)
    local len = #tab;
    idx1 = idx1 < 0 and (len + idx1 + 1) or idx1;
    idx2 = nil == idx2 and len or (idx2 < 0 and (len + idx2 + 1) or idx2);
    local ret = {};
    local idx = 1;
    for i = idx1,idx2 do
        local v = tab[i];
        if nil == v then
            break;
        end
        ret[idx] = v;
        idx = idx + 1;
    end

    return ret;
end

---给定一个顺序表，将其逆序。
---@param tab table
function table.reverse(tab)
    local len = #tab;
    for i = 1,len // 2 do
        local tail = len - i + 1;
        tab[i],tab[tail] = tab[tail],tab[i];
    end
end