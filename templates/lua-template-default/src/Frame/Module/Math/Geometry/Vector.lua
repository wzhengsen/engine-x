--[[
    Auth:       wzhengsen
    Date:       2020.01.09
    Content:    平面向量。
]]
local Vector = nil;
Vector = setmetatable(
    {__name = "Vector"},
    {
        --[[
            Desc:   向量构造。
            Param:  <number>
                    <number>
        ]]
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

--[[
    向量和
]]
function Vector:__add(vec)
    return Vector(self.x + vec.x,self.y + vec.y);
end

--[[
    点乘
]]
function Vector:__mul(vec)
    return self.x * vec.x + self.y * vec.y;
end

--[[
    叉乘
]]
function Vector:__pow(vec)
    return self.x * vec.x - self.y * vec.y;
end

--[[
    向量差
]]
function Vector:__sub(vec)
    return Vector(self.x - vec.x,self.y - vec.y);
end

--[[
    两向量取夹角
]]
function Vector:__bxor(vec)
    local x1,y1 = self.x,self.y;
    local x2,y2 = vec.x,vec.y;

    -- 模长
    local m1 = (x1 ^ 2 + y1 ^ 2) ^ 0.5;
    local m2 = (x2 ^ 2 + y2 ^ 2) ^ 0.5;
    -- 内积
    local nj = x1 * x2 + y1 * y2;
    return math.acos(nj / (m1 * m2));
end

--[[
    单位化
]]
function Vector:Normalize()
    local m = (self.x ^ 2 + self.y ^ 2) ^ 0.5;
    self.x = self.x / m;
    self.y = self.y / m;
end

return Vector;