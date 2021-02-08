--[[
    Auth:   wzhengsen
    Data:   2020.07.05
    Desc:   Button一些补充的封装方法。
]]
local Button = ccui.Button;
local new = Button.new;

--[[
    Desc:       改进原create，原create不能自动适应TextureResType参数。
]]
function Button.new(...)
    local p = {...};
    local len = #p;
    if len == 2 and "number" == type(p[2]) then
        return new(p[1],"","",p[2]);
    elseif len == 3 and "number" == type(p[3]) then
        return new(p[1],p[2],"",p[3]);
    end
    return new(...);
end