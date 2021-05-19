-- Copyright (c) 2021 wzhengsen

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:

-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.

---------------------------------------------
--  Module: 数学
--  Auth:   wzhengsen
--  Date:   2019年04月03日
--  Desc:   定义了一些数学运算，和一些数学算法
---------------------------------------------

---将一个数限制在指定范围内。
---
---@param num number
---@param limit1 number
---@param limit2 number
---@return number
---
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

---取两坐标距离。
---
---@param x1 number
---@param y1 number
---@param x2 number
---@param y2 number
---@return number
---
function math.Distance(x1,y1,x2,y2)
    local dx = x1 - x2;
    local dy = y1 - y2;
    return (dx * dx + dy * dy) ^ 0.5;
end

---取两坐标弧度,从(x1,y1)到(x2,y2)
---
---@param X1 number
---@param Y1 number
---@param X2 number
---@param Y2 number
---@return number
---
function math.Radian(X1,Y1,X2,Y2)
    local dy = Y2 - Y1;
    local dx = X2 - X1;

    return math.atan(dy,dx);
end

---取极坐标XY。
---
---@param x number 原点x
---@param y number 原点y
---@param rad number 方向（弧度）
---@param dis number 距离
---@return number 极坐标x
---@return number 极坐标y
---
function math.Polar(x,y,rad,dis)
    return x + math.cos(rad) * dis,y + math.sin(rad) * dis;
end

---由点1向点2逼近一段距离，并返回新的位置。
---若逼近距离超过总距离,则返回目标位置。
---
---@param X1 number
---@param Y1 number
---@param X2 number
---@param Y2 number
---@param dis number
---@return number
---@return number
---
function math.Approach(X1,Y1,X2,Y2,dis)
    local allDist = math.Distance(X1,Y1,X2,Y2);
    if allDist == 0.0 then
        return X2,Y2;
    end
    --  求移动占比
    local perc = dis / allDist;
    if perc > 1 then perc = 1; end
    return X1 + (X2 - X1) * perc,Y1 + (Y2 - Y1) * perc;
end