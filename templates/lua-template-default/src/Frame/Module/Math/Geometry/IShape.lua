--[[
    Auth:       wzhengsen
    Date:       2020.01.08
    Content:    几何形状类接口。
]]
local IShape = class();

-- 接口类，不能实例化。
IShape.new = nil;

-- 判断是否包含一个点，纯虚函数。
IShape.IsPointIn = 0;

function IShape:ctor()
    self._locX = {};
    self._locY = {};
end

--	Func:	相对移动
--	Param:	x偏移，y轴偏移
---------------------------------------------
function IShape:MoveBy(x,y)
    local locX = self._locX;
    local locY = self._locY;

    for i = 1,#locX do
        locX[i] = locX[i] + x;
    end
    for i = 1,#locY do
        locY[i] = locY[i] + y;
    end
end

--	Func:	旋转
--	Param:	旋转轴点x,旋转轴点y,弧度
--	Desc:	增量旋转
---------------------------------------------
function IShape:Rotate(x,y,rad)
    local locX = self._locX;
    local locY = self._locY;

    for i = 1,#locX do
        locX[i],locY[i] = math.Polar(x,y,rad,math.Distance(x,y,locX[i],locY[i]));
    end
end

return IShape;