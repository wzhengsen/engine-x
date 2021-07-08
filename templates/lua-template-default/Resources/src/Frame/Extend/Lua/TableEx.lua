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

-- 为table新增了一些方法,如Union,Copy,Filter

---筛选符合要求的键值对。
---@param t table
---@param f function | "function(key,value)\n    return true;\nend"
---@return table
function table.filter(t,f)
    local ret = {};
    for k,v in pairs(t) do
        if f(k,v) then
            ret[k] = v;
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
---@param b? boolean {false}是否拷贝元表。
---@return table
function table.copy(tab,b)
    local retTab = copy(tab,{});
    if b then
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
    for _,v in pairs({...}) do
        for k,v_v in pairs(v) do
            union[k] = v_v;
        end
    end
    return union;
end

---求表中元素总数。
---@param tab table
---@param f? function | "function(key,value)\n    return true;\nend"
---@return integer
function table.count(tab,f)
    local size = 0;
    if not f then
        for _,_ in pairs(tab) do
            size = size + 1;
        end
    else
        for k,v in pairs(tab) do
            if f(k,v) == true then
                size = size + 1;
            end
        end
    end
    return size;
end


---在表中查找指定元素，并返回对应的键。
---只返回第一个匹配的元素。
---@param tab table
---@param value any
---@param f? function | "function(v,value)\n    return true;\nend"
---@return any
function table.find(tab,value,f)
    if not f then
        for k,v in pairs(tab) do
            if v == value then
                return k;
            end
        end
    else
        for k,v in pairs(tab) do
            if f(v,value) == true then
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
        local index = math.random(1,len);
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

---令表只读/或取消只读属性。
---该操作会改变表的元表。
---@param tab table
---@param b? boolean {true}可以省略，默认只读。
function table.readonly(tab,b)
    b = nil == b or b;

    local mt = getmetatable(tab);
    if b then
        if mt and mt["__@readonly__"] then
            return;
        end
        mt = {
            ["__@readonly__"] = true,
            __index = {},
            __newindex = function()end
        }
        local saveTab = mt.__index;
        for k,v in pairs(tab) do
            saveTab[k] = v;
            tab[k] = nil;
        end
        setmetatable(tab,mt);
    else
        if not mt or not mt["__@readonly__"] then
            return;
        end
        setmetatable(tab,nil);
        local saveTab = mt.__index
        for k,v in pairs(saveTab) do
            tab[k] = v;
        end
    end
end