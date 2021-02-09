---------------------------------------------
--	Module:	table
--	Auth:	wzhengsen
--	Date:	2019年04月03日
--	Desc:	为table新增了一些方法,如union,copy
---------------------------------------------

--[[-------------------------------------------
    Func:	筛选符合要求的键值对
    Param:	table,function
    Return:	table
    Desc:   会返回新表
---------------------------------------------]]
function table.Filter(t,f)
    local ret = {}
    for k,v in pairs(t) do
        if f(k,v) then
            ret[k] = v
        end
    end
    return ret
end

local function copy(cTab,existTab)
    if type(cTab) ~= "table" then
        return cTab
    elseif nil ~= existTab[cTab] then
        return existTab[cTab]
    end

    local tempTab = {}
    --将当前表加入已存在表，并为已存在表赋值
    existTab[cTab] = tempTab
    for k,v in pairs(cTab) do
        --若任意键值在已存在表中，则将键值赋值为存在表的值
        --避免如下情况引起的死循环：
        --local a = {}
        --a[a] = a
        tempTab[copy(k,existTab)] = copy(v,existTab)
    end
    return tempTab
end

--	Func:	拷贝
--	Param:	table[,boolean(是否拷贝元表)]
--	Return:	table
--  Desc:   userdata/thread等无法拷贝
---------------------------------------------
function table.Copy(tab,b)
    local retTab = copy(tab,{})
    if b then
        setmetatable(retTab,getmetatable(tab))
    end
    return retTab
end

--	Func:	合并
--	Param:	table,table
--  Desc:   将表2合并到表1，重复字段将覆盖
---------------------------------------------
function table.Merge(t1,t2)
    for k,v in pairs(t2) do
        t1[k] = v
    end
end

--[[
    Func:   数组追加
    Param:  table,table
]]
function table.Append(t1,t2)
    local len = #t1
    for _,v in ipairs(t2) do
        len = len + 1
        t1[len] = v
    end
end

--	Func:	求并集
--	Param:	table(...)
--	Return:	table
--  Desc:   返回的是一个新的表，效率较低，重复字段将覆盖
---------------------------------------------
function table.Union(...)
    local union = {}
    for _,v in pairs({...}) do
        for k,v_v in pairs(v) do
            union[k] = v_v
        end
    end
    return union
end

--	Func:	求长度
--	Param:	table
--          function(filter)
--	Return:	number
---------------------------------------------
function table.Count(tab,f)
    local size = 0
    if not f then
        for _,_ in pairs(tab) do
            size = size + 1
        end
    else
        for k,v in pairs(tab) do
            if f(k,v) == true then
                size = size + 1
            end
        end
    end
    return size
end

--	Func:	查找
--	Param:	table
--          value
--          function(filter)
--	Return:	索引
---------------------------------------------
function table.Find(tab,value,f)
    if not f then
        for k,v in pairs(tab) do
            if v == value then
                return k
            end
        end
    else
        for k,v in pairs(tab) do
            if f(v,value) == true then
                return k
            end
        end
    end
    return nil
end

--	Func:	打乱一个顺序表
--	Param:	table
---------------------------------------------
function table.Mess(tab)
    local len = #tab
    for i = 1,len do
        local index = math.random(1,len)
        tab[i],tab[index] = tab[index],tab[i]
    end
end

--[[
    Func:   取得第一个空洞的位置
    Param:  table
    Desc:   适用于（有空洞的）顺序表
]]
function table.Hole(tab)
    local k = 1;
    while nil ~= tab[k] do
        k = k + 1;
    end
    return k;
end

--[[
    Func:   筛选唯一值
    Param:  table
            boolean{nil}    是否以数组返回
    Return: table
    Desc:   不改变原表，返回新表
]]
function table.Unique(t,bArray)
    local check = {}
    local n = {}
    local idx = 1
    for k, v in pairs(t) do
        if not check[v] then
            if bArray then
                n[idx] = v
                idx = idx + 1
            else
                n[k] = v
            end
            check[v] = true
        end
    end
    return n
end

--[[
    Func:	令表只读/或取消只读属性
    Param:	table
            boolean{true}
    Desc:   会改变表的元表
]]
function table.ReadOnly(tab,b)
    if nil == b then b = true end

    local mt = getmetatable(tab)
    if b then
        if mt and rawget(mt,"__@readonly__") then
            return
        end
        mt = {
            ["__@readonly__"] = true,
            __index = {},
            __newindex = function()end
        }
        setmetatable(tab,nil)
        local saveTab = mt.__index
        for k,v in pairs(tab) do
            saveTab[k] = v
            tab[k] = nil
        end
        setmetatable(tab,mt)
    else
        if not mt or not rawget(mt,"__@readonly__") then
            return
        end
        setmetatable(tab,nil)
        local saveTab = mt.__index
        for k,v in pairs(saveTab) do
            tab[k] = v
        end
    end
end