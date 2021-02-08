--[[
    Auth:   wzhengsen
    Date:   2020.04.06
    Desc:   CSLoader一些新的封装方法。
]]
local CSLoader = cc.CSLoader;

function CSLoader:CreateNodeWithSize(path,size)
    local node = self.createNode(path);
    if node then
        node.Size = size;
        ccui.Helper:doLayout(node);
    end
    return node;
end