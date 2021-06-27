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

local insert = table.insert;
local Distance = math.Distance;
local IShape = require("Math.Geometry.IShape");
local Circle = class(IShape);

Circle.private.circleR = 0;

---以圆心和半径构造一个圆。
---@param x number
---@param y number
---@param r number
function Circle:ctor(x,y,r)
    insert(self.shapeLocsX,x);
    insert(self.shapeLocsY,y);
    self.circleR = r;
end

---判断是否包含一个点。
---@param x number
---@param y number
---@return boolean
function Circle:IsPointIn(x,y)
    return Distance(x,y,self.shapeLocsX[1],self.shapeLocsY[1]) <= self.circleR;
end

cc.Geometry = cc.Geometry or {};
cc.Geometry.Circle = Circle;
return Circle;