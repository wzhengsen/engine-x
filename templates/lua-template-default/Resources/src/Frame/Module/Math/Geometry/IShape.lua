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

local polar = math.polar;
local distance = math.distance;
---几何形状类接口。
local IShape = class();

IShape.protected.shapeLocsX = {};
IShape.protected.shapeLocsY = {};

---判断是否包含一个点，纯虚函数。
IShape.virtual.IsPointIn = 0;

---相对移动。
---@param x number
---@param y number
function IShape:MoveBy(x,y)
    local locX = self.shapeLocsX;
    local locY = self.shapeLocsY;

    for i = 1,#locX do
        locX[i] = locX[i] + x;
    end
    for i = 1,#locY do
        locY[i] = locY[i] + y;
    end
end

---绕xy点增量旋转。
---@param x number
---@param y number
---@param rad number
function IShape:Rotate(x,y,rad)
    local locX = self.shapeLocsX;
    local locY = self.shapeLocsY;

    for i = 1,#locX do
        locX[i],locY[i] = polar(x,y,rad,distance(x,y,locX[i],locY[i]));
    end
end

cc.Geometry = cc.Geometry or {};
cc.Geometry.IShape = IShape;
return IShape;