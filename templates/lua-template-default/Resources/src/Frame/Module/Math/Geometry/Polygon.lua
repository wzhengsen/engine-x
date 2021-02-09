--[[
    Auth:       wzhengsen
    Date:       2020.01.08
    Content:    多边形类，可以通过增加点来构造一些常见的多边形。
]]
local IShape = require("Math.Geometry.IShape");
local Polygon = class(IShape);

--[[
    Desc:       判断是否包含一个点。
    Param:      <number>            点的X
                <number>            点的Y
    Return:     <boolean>           是否包含点。
]]
function Polygon:IsPointIn(x,y)
    local nCount = #self._locX;
    if nCount == 0 then
        return false
    end
    local nCross = 0;
    local locX = self._locX;
    local locY = self._locY;
    for i = 0, nCount - 1 do
        local cX = locX[i + 1];
        local cY = locY[i + 1];
        local nX = locX[((i + 1) % nCount) + 1];
        local nY = locY[((i + 1) % nCount) + 1];

        if math.min(cY,nY) < y and math.max(cY,nY) >= y then
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

--[[
    Desc:   按添加点的顺序连线组成多边形，也可以组成凹多边形，起始点可以不重合。
    Param:      <number>            点的X
                <number>            点的Y
]]
function Polygon:AddPoint(x,y)
    table.insert(self._locX,x);
    table.insert(self._locY,y);
end

return Polygon;