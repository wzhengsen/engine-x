---------------------------------------------
--	Module:	数学
--	Auth:	wzhengsen
--	Date:	2019年04月03日
--	Desc:	定义了一些数学运算，和一些数学算法
---------------------------------------------

--	Func:	将一个数限制在一个范围内
--	Param:	number,number,number
--	Return:	number
---------------------------------------------
function math.Limit(num,limit1,limit2)
    if limit1 > limit2 then
        limit1,limit2 = limit2,limit1;
    end
    if num < limit1 then
        return limit1;
    end
    if num > limit2 then
        return limit2;
    end
    return num;
end

--	Func:	取两坐标距离
--	Param:	x1,y1,x2,y2
--	Return:	距离
---------------------------------------------
function math.Distance(x1,y1,x2,y2)
    local dx = x1 - x2;
    local dy = y1 - y2;
    return (dx * dx + dy * dy) ^ 0.5;
end

--	Func:	取两坐标弧度,从(x1,y1)到(x2,y2)
--	Param:	x1,y1,x2,y2
--	Return:	弧度
---------------------------------------------
function math.Radian(X1,Y1,X2,Y2)
    local dy = Y2 - Y1;
    local dx = X2 - X1;

    return math.atan(dy,dx);
end

--	Func:	取极坐标XY
--	Param:	原坐标X,原坐标Y,弧度,距离
--	Return:	坐标X,坐标Y
---------------------------------------------
function math.Polar(x,y,rad,dis)
    return x + math.cos(rad) * dis,y + math.sin(rad) * dis;
end

--	Func:	由点1向点2逼近一段距离
--	Param:	x1,y1,x2,y2,距离
--	Return:	x,y
--	Desc:	逼近距离超过总距离,则返回目标距离
---------------------------------------------
function math.Approach(X1,Y1,X2,Y2,dis)
    local allDist = math.Distance(X1,Y1,X2,Y2);
    if allDist == 0.0 then
        return X2,Y2;
    end
    --	求移动占比
    local perc = dis / allDist;
    if perc > 1 then perc = 1; end
    return X1 + (X2 - X1) * perc,Y1 + (Y2 - Y1) * perc;
end