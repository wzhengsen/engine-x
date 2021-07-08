--[[
Copyright (c) 2021 wzhengsen.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
]]

local floor = math.floor;
local random = math.random;
local find = table.find;
local insert = table.insert;
local remove = table.remove;
---概率池类型，将不同值以指定的比重推入概率池，以便以对应的概率取出。
local RatePool = class();
RatePool.private.ratePool = {};
RatePool.private.elementIdx = {};
RatePool.private.rateCount = 0;

---将指定的元素按照给定的比重推入概率池。
---可以连续推入同种元素，以增加该元素的占比；推入一个负比重来减少占比。
---但无法将某种元素占比降低至小于0。
---@param e any
---@param rate integer
function RatePool:Push(e,rate)
    if e == nil then return; end
    rate = floor(rate);
    if 0 == rate then return;end

    local idx = find(self.ratePool,e,function(value,v)
        return value.e == v;
    end);
    if not idx then
        -- 推入新数据。
        if rate <= 0 then return;end
        local element = {
            e = e,
            r = rate,
            rateIdx = self.rateCount + rate
        };
        -- 插入顺序索引表。
        insert(self.ratePool,element);
        -- 插入反向索引表。
        self.elementIdx[e] = element;
    else
        local element = self.ratePool[idx];
        local offset = 1;
        if rate < 0 and element.r + rate <= 0 then
            -- 清除因无比重被移除的元素。
            rate = -element.r;
            remove(self.ratePool,idx);
            self.elementIdx[e] = nil;
            -- 因该项被移除，调整rateIdx时省略偏移量。
            offset = 0
        else
            -- 改变比重。
            element.r = element.r + rate;
        end

        for i = idx + offset,#self.ratePool do
            local value = self.ratePool[i];
            value.rateIdx = value.rateIdx + rate;
        end
    end

    self.rateCount = self.rateCount + rate;
end

---随机得到一个存放的元素，没有元素会返回nil。
---不会引起概率变化。
---@return any
function RatePool:Peek()
    if self.rateCount <= 0 then
        return nil;
    end
    local r = random(1,self.rateCount);
    local rp = self.ratePool;
    for i = 1,#rp do
        local v = rp[i];
        if r <= v.rateIdx then
            return v.e;
        end
    end
    return nil;
end

---随机得到一个存放的元素，并相应减少其比重。
---若不传入比重，将移除整个元素，没有元素会返回nil。
---会引起概率变化。
---@param rate? integer
---@return any
function RatePool:Pick(rate)
    if rate and rate < 0 then
        rate = 0;
    end
    local e = RatePool.Peek(self);
    if e then
        RatePool.Push(self,e,rate and -rate or -math.huge);
    end
    return e;
end

---得到指定的元素的获取概率，若没有该种元素，返回0。
---@param e any
---@return integer
function RatePool:Rate(e)
    local element = self.elementIdx[e];
    if not element then
        return 0;
    else
        return element.r / self.rateCount;
    end
end

---清除并重置概率池。
function RatePool:Clear()
    self.ratePool = {};
    -- 反向索引表。
    self.elementIdx = {};
    self.rateCount = 0;
end

---移除指定的元素，若元素存在，将引起概率变化。
---@param e any
function RatePool:Remove(e)
    local rp = self.ratePool;
    local idx = find(rp,e,function(value,v)
        return value.e == v;
    end);
    if nil == idx then
        return;
    end

    local deltaRate = rp[idx].r;
    remove(rp,idx);
    self.elementIdx[e] = nil;

    for i = idx,#rp do
        local value = rp[i];
        value.rateIdx = value.rateIdx - deltaRate;
    end

    self.rateCount = self.rateCount - deltaRate;
end

cc.Algorithm = cc.Algorithm or {};
cc.Algorithm.RatePool = RatePool;
return RatePool;