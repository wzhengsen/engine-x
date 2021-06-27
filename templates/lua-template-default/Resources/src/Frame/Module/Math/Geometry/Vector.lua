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

local acos = math.acos;
---@class Vector 平面向量。
local Vector = nil;
Vector = setmetatable(
    {__name = "Vector"},
    {
        ---向量构造。
        ---@param _ Vector
        ---@param x number
        ---@param y number
        ---@return Vector
        __call = function (_,x,y)
            return setmetatable({
            x = x,
            y = y
        },Vector);
        end
    }
);
Vector.__index = Vector;

Vector.Zero = Vector(0,0);

function Vector:__eq(vec)
    return (self.x == vec.x) and (self.y == vec.y);
end

---向量和。
---@param vec Vector
---@return Vector
function Vector:__add(vec)
    return Vector(self.x + vec.x,self.y + vec.y);
end

---点乘。
---@param vec Vector
---@return Vector
function Vector:__mul(vec)
    return self.x * vec.x + self.y * vec.y;
end

---叉乘。
---@param vec Vector
---@return Vector
function Vector:__pow(vec)
    return self.x * vec.x - self.y * vec.y;
end

---向量差。
---@param vec Vector
---@return Vector
function Vector:__sub(vec)
    return Vector(self.x - vec.x,self.y - vec.y);
end

---两向量取夹角。
---@param vec Vector
---@return number 弧度。
function Vector:__bxor(vec)
    local x1,y1 = self.x,self.y;
    local x2,y2 = vec.x,vec.y;

    -- 模长
    local m1 = (x1 ^ 2 + y1 ^ 2) ^ 0.5;
    local m2 = (x2 ^ 2 + y2 ^ 2) ^ 0.5;
    -- 内积
    local nj = x1 * x2 + y1 * y2;
    return acos(nj / (m1 * m2));
end

---向量单位化。
function Vector:Normalize()
    local m = (self.x ^ 2 + self.y ^ 2) ^ 0.5;
    self.x = self.x / m;
    self.y = self.y / m;
end

cc.Geometry = cc.Geometry or {};
cc.Geometry.Vector = Vector;
return Vector;