--[[
    Auth:       wzhengsen
    Date:       2020.01.08
    Content:    扇形类。
]]
local IShape = require("Math.Geometry.IShape");
local Sector = class(IShape);

--[[
    Desc:       以圆心角、半径、弧度、中分线方向构造一个圆。
                方向取值0-2pi。
    Param:      <number>            点的X
                <number>            点的Y
                <number>            半径
                <number>            弧度
                <number>            中分线方向
]]
function Sector:__init__(x,y,r,cR,direc)
    IShape.__init__(self);

    cR = math.Limit(cR,0,2 * math.pi);

    local locX,locY = self._locX,self._locY;
    locX[1],locY[1] = x,y;

    self.__sectorR = r;
    self.__sectorCR = cR;
    self.__sectorD = direc;
end

--[[
    Func:	旋转
    Param:	旋转轴点x,旋转轴点y,弧度
    Desc:	增量旋转
]]
function Sector:Rotate(x,y,rad)
    IShape.Rotate(self,x,y,rad);
	self.__sectorD = (self.__sectorD + rad) % (2 * math.pi);
end

--[[
    Desc:       判断是否包含一个点。
    Param:      <number>            点的X
                <number>            点的Y
    Return:     <boolean>           是否包含点。
]]
function Sector:IsPointIn(x,y)
    local cX,cY = self._locX[1],self._locY[1];
    local dis = math.Distance(x,y,cX,cY);
    if dis > self.__sectorR then
        return false;
    end

    -- cosθ = v1 * v2 / |v1| * |v2|
    local dX,dY = x - cX,y - cY;
    local uX,uY = 1,math.tan(self.__sectorD);
    local uM = (1 + uY ^ 2) ^ 0.5;
    return math.acos((dX * uX + dY * uY) / (uM * dis)) < (self.__sectorCR / 2);
end

return Sector;