--[[
    Auth:       wzhengsen
    Date:       2020.01.08
    Content:    圆形类。
]]
local IShape = require("Math.Geometry.IShape");
local Circle = class(IShape);

--[[
    Desc:       以圆心和半径构造一个圆。
    Param:      <number>            点的X
                <number>            点的Y
                <number>            半径
]]
function Circle:ctor(x,y,r)
    IShape.ctor(self);
    table.insert(self._locX,x);
    table.insert(self._locY,y);
    self.__circleR = r;
end

--[[
    Desc:       判断是否包含一个点。
    Param:      <number>            点的X
                <number>            点的Y
    Return:     <boolean>           是否包含点。
]]
function Circle:IsPointIn(x,y)
    return math.Distance(x,y,self._locX[1],self._locY[1]) <= self.__circleR;
end

return Circle;