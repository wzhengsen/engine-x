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
local limit = math.limit;
local pi = math.pi;
local acos = math.acos;
local tan = math.tan;
local distance = math.distance;

local IShape = require("Math.Geometry.IShape");
---扇形类。
local Sector = class(IShape);
Sector.protected.sectorR = nil;
Sector.protected.sectorRAD = nil;
Sector.protected.sectorD = nil;

---以圆心点、半径、弧度、中分线方向构造一个扇形。
---方向取值0-2pi。
---@param x number
---@param y number
---@param r number 半径
---@param rad number 弧度
---@param direct number 中分线方向
function Sector:ctor(x,y,r,rad,direct)
    rad = limit(rad,0,2 * pi);

    local locX,locY = self.shapeLocsX,self.shapeLocsY;
    locX[1],locY[1] = x,y;

    self.sectorR = r;
    self.sectorRAD = rad;
    self.sectorD = direct;
end

---绕xy点增量旋转。
---@param x number
---@param y number
---@param rad number
function Sector:Rotate(x,y,rad)
    IShape.Rotate(self,x,y,rad);
    self.sectorD = (self.sectorD + rad) % (2 * pi);
end

---判断是否包含一个点。
---@param x number
---@param y number
---@return boolean
function Sector:IsPointIn(x,y)
    local cX,cY = self.shapeLocsX[1],self.shapeLocsY[1];
    local dis = distance(x,y,cX,cY);
    if dis > self.sectorR then
        return false;
    end

    -- cosθ = v1 * v2 / |v1| * |v2|
    local dX,dY = x - cX,y - cY;
    local uX,uY = 1,tan(self.sectorD);
    local uM = (1 + uY ^ 2) ^ 0.5;
    return acos((dX * uX + dY * uY) / (uM * dis)) < (self.sectorRAD / 2);
end

cc.Geometry = cc.Geometry or {};
cc.Geometry.Sector = Sector;
return Sector;