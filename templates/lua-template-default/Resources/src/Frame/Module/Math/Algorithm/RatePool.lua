--[[
    Auth:       wzhengsen
    Date:       2020.01.06
    Content:    概率池类型，将不同值以指定的比重推入概率池，以便以对应的概率取出。
]]
local RatePool = class();

function RatePool:ctor()
    self:Clear();
end

--[[
    Desc:       将指定的元素按照给定的比重推入概率池。
                可以连续推入同种元素，以增加该元素的占比；推入一个负比重来减少占比。
                但无法将某种元素占比降低至小于0.
    Param:      <value>         任何非nil的可用元素。
                <number>        该元素的占比。
]]
function RatePool:Push(e,rate)
    assert(e ~= nil,"Invalid element.")

    rate = math.floor(rate);
    if 0 == rate then
        return;
    end

    local idx = table.Find(self.__ratePool,e,function(value,v)
        return value.e == v;
    end);
    if not idx then
        assert(rate > 0,"Element rate must more than zero.");
        if rate <= 0 then
            return;
        end
        local element = {
            e = e,
            r = rate,
            rateIdx = self.__rate + rate
        };
        -- 插入顺序索引表。
        table.insert(self.__ratePool,element);
        -- 插入反向索引表。
        self.__elementIdx[e] = element;
    else
        local element = self.__ratePool[idx];
        if rate < 0 and element.r + rate <= 0 then
            -- 清除因无比重被移除的元素。
            rate = -element.r;
            table.remove(self.__ratePool,idx);
            self.__elementIdx[e] = nil;
        else
            -- 改变比重。
            element.r = element.r + rate;
        end

        for i = idx,#self.__ratePool do
            local value = self.__ratePool[i];
            value.rateIdx = value.rateIdx + rate;
        end
    end

    self.__rate = self.__rate + rate;
end

--[[
    Desc:       随机得到一个存放的元素，没有元素会返回nil。
                不会引起概率变化。
    Return:     <value>
]]
function RatePool:Peek()
    local r = math.random(1,self.__rate);
	for _,v in ipairs(self.__ratePool) do
		if r <= v.rateIdx then
			return v.e;
		end
	end
	return nil;
end

--[[
    Desc:       随机得到一个存放的元素，并移除获取到的元素，没有元素会返回nil。
                会引起概率变化。
    Return:     <value>
]]
function RatePool:Pick()
    local e = self:Peek();
    if e then
        self:Remove(e);
    end
    return e;
end

--[[
    Desc:      得到指定的元素的获取概率，若没有该种元素，返回0。
    Param:     <number>
]]
function RatePool:Rate(e)
    local element = self.__elementIdx[e];
    if not element then
        return 0;
    else
        return element.r / self.__rate;
    end
end

--[[
    Desc:       清除并重置概率池。
]]
function RatePool:Clear()
    self.__ratePool = {};
    -- 反向索引表。
    self.__elementIdx = {};
    self.__rate = 0;
end

--[[
    Desc:       移除指定的元素，若元素存在，将引起概率变化。
    Param:      <value>
]]
function RatePool:Remove(e)
    local idx = table.Find(self.__ratePool,e,function(value,v)
        return value.e == v;
    end);
    if nil == idx then
        return;
    end

    table.remove(self.__reatePool,idx);
    self.__elementIdx[e] = nil;

    local deltaRate = self.__reatePool[idx].r;
    for i = idx,#self.__reatePool do
        local value = self.__reatePool[i];
        value.rateIdx = value.rateIdx - deltaRate;
    end

    self.__rate = self.__rate - deltaRate;
end

return RatePool;