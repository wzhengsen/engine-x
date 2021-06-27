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

local min = math.min;
local max = math.max;
local insert = table.insert;
local IShape = require("Math.Geometry.IShape");
---多边形类，可以通过增加点来构造一些常见的多边形。
local Polygon = class(IShape);

---判断是否包含一个点。
---@param x number
---@param y number
---@return boolean
function Polygon:IsPointIn(x,y)
    local nCount = #self.shapeLocsX;
    if nCount == 0 then
        return false;
    end
    local nCross = 0;
    local locX = self.shapeLocsX;
    local locY = self.shapeLocsY;
    for i = 0, nCount - 1 do
        local cX = locX[i + 1];
        local cY = locY[i + 1];
        local nX = locX[((i + 1) % nCount) + 1];
        local nY = locY[((i + 1) % nCount) + 1];

        if min(cY,nY) < y and max(cY,nY) >= y then
            local d = (cX - x) * (nY - y) - (cY - y) * (nX - x);
            if 0 == d then
                return true;
            end
            if 0 < (cY - nY < 0 and d or -d) then
                nCross = nCross + 1;
            end
        end
    end
    return 1 == nCross % 2;
end

---按添加点的顺序连线组成多边形，也可以组成凹多边形，起始点和结束点可以不重合。
---@param x number
---@param y number
function Polygon:AddPoint(x,y)
    insert(self.shapeLocsX,x);
    insert(self.shapeLocsY,y);
end

cc.Geometry = cc.Geometry or {};
cc.Geometry.Polygon = Polygon;
return Polygon;