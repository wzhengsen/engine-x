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

local Node = cc.Node;

function Node:OnEnter(_)end
function Node:OnExit(_)end
function Node:OnEnterTransitionDidFinish(_)end
function Node:OnExitTransitionDidStart(_)end
function Node:OnCleanUp(_)end
function Node:OnUpdate(_)end

local function SeekNodeByTag(self,nTag)
    local node = self:getChildByTag(nTag);
    if node then
        return node;
    end
    for _,v in ipairs(self:getChildren()) do
        node = v:SeekNodeByTag(nTag);
        if node then
            return node;
        end
    end
end

local function SeekNode(self,sn)
    if type(sn) == "string" then
        local node = nil;
        self:EnumerateChildren("//"..sn,function(sNode)
            node = sNode;
            return true;
        end);
        return node;
    elseif type(sn) == "number" then
        return SeekNodeByTag(self,sn);
    end
end

local function SeekNodeInSelf(self,sn)
    if type(sn) == "string" then
        return self:GetChildByName(sn);
    elseif type(sn) == "number" then
        return self:GetChildByTag(sn);
    end
end

-- 整除运算指向SeekNode
Node.__idiv__ = SeekNode;
-- 除法运算指向SeekNodeInSelf
Node.__div__ = SeekNodeInSelf;


---置于父级顶部
---
function Node:SetTop()
    local p = self.Parent;
    if class.IsNull(p) then return; end

    local cC = p.Children;
    local maxZOrder = nil;
    for _,v in ipairs(cC) do
        local zOrder = v.LocalZ;
        if not maxZOrder or zOrder > maxZOrder then
            maxZOrder = zOrder;
        end
    end
    self.LocalZ = maxZOrder + 1;
end

--[[
    Func:   绑定一个布局组件，并指定绑定参数。
    Param:  table|boolean|nil
    Desc:   参数为表时字段详情如下：
            {
                pw 指示百分比适应宽；
                ph 指示百分比适应高；
                sw 指示拉伸适应宽，只适用boolean值；
                sh 指示拉伸适应高，只适用boolean值；

                px 指示百分比适应x；
                py 指示百分比适应y；

                lm 指示左边界，与rm能同时生效；
                rm 指示右边界，与lm能同时生效；
                tm 指示上边界，与bm能同时生效；
                bm 指示下边界，与tm能同时生效；

                po 强制百分比，只适用boolean值。
            }

            参数优先级：
            1.po
                po值被赋值为true会强制使用百分比类型的适应，如lm/sw等将无效；
                po值被赋值为false并不意味着pw/px等失效。
            2.sw/sh
                sw为true时需要一个pw数值或同时保证lm/rm赋有效值；
                sh同理。
            3.pw/ph
            4.lm/rm/tm/bm
                sw为false,lm和rm同时赋有效值时，需要保证px被赋值；
                sh/tm/bm同理。
            5.px/py

            以上值为number时作为值并打开可用开关，为boolean时仅作为开关，
            且参数为表时，会激活布局并尝试立刻布局一次。

            参数为boolean时代表Node的布局状态的激活与否，当为true时会尝试立刻布局一次。
]]
local LayoutComponent = ccui.LayoutComponent;
local HorizontalEdge = LayoutComponent.HorizontalEdge;
local VerticalEdge = LayoutComponent.VerticalEdge;
local function Layout(self,layoutParam)
    local pType = type(layoutParam);
    if "table" == pType then
        local layout = LayoutComponent.BindLayoutComponent(self);
        layout.ActiveEnabled = true;
        for k,v in pairs(layoutParam) do
            local isBoolean = "boolean" == type(v);
            if "pw" == k then
                if isBoolean then
                    layout.PercentWidthEnabled = v;
                else
                    layout.PercentWidthEnabled = true;
                    layout.PercentWidth = v;
                end
            elseif "ph" == k then
                if isBoolean then
                    layout.PercentHeightEnabled = v;
                else
                    layout.PercentHeightEnabled = true;
                    layout.PercentHeight = v;
                end
            elseif "sw" == k then
                if isBoolean then
                    layout.StretchWidthEnabled = v;
                end
            elseif "sh" == k then
                if isBoolean then
                    layout.StretchHeightEnabled = v;
                end
            elseif "px" == k then
                if isBoolean then
                    layout.PositionPercentXEnabled = v;
                else
                    layout.PositionPercentXEnabled = true;
                    layout.PositionPercentX = v;
                end
            elseif "py" == k then
                if isBoolean then
                    layout.PositionPercentYEnabled = v;
                else
                    layout.PositionPercentYEnabled = true;
                    layout.PositionPercentY = v;
                end
            elseif "lm" == k or "rm" == k then
                local he = layout.Horizontal;
                if "lm" == k then
                    if isBoolean then
                        he = v and (he | HorizontalEdge.Left) or (he & HorizontalEdge.Right);
                    else
                        he = he | HorizontalEdge.Left;
                        layout.LeftMargin = v;
                    end
                else
                    if isBoolean then
                        he = v and (he | HorizontalEdge.Right) or (he & HorizontalEdge.Left);
                    else
                        he = he | HorizontalEdge.Right;
                        layout.RightMargin = v;
                    end
                end
                layout.Horizontal = he;
            elseif "tm" == k or "bm" == k then
                local ve = layout.Vertical;
                if "tm" == k then
                    if isBoolean then
                        ve = v and (ve | VerticalEdge.Top) or (ve & VerticalEdge.Bottom);
                    else
                        ve = (ve | VerticalEdge.Top);
                        layout.TopMargin = v;
                    end
                else
                    if isBoolean then
                        ve = v and (ve | VerticalEdge.Bottom) or (ve & VerticalEdge.Top);
                    else
                        ve = (ve | VerticalEdge.Bottom);
                        layout.BottomMargin = v;
                    end
                end
                layout.Vertical = ve;
            end
        end

        layout:RefreshLayout();
    elseif "boolean" == pType then
        local layout = self:GetComponent("__ui_layout");
        if not layout then
            if layoutParam then
                ccui.Helper.DoLayout(self);
            end
        else
            layout.ActiveEnabled = layoutParam;
            if layoutParam then
                layout:RefreshLayout();
            end
        end
    elseif "nil" == pType then
        self:RemoveComponent("__ui_layout");
    end
end

function Node.__properties__()
    return {
        w = {
            -- 考虑到效率问题，OnUpdate应当独立开启，且不建议大量使用。
            EnableUpdateEvent = function (self,val)
                if val then
                    self.OnUpdateHandler = class.Handler(self,self.OnUpdate);
                else
                    self.OnUpdateHandler = nil;
                end
            end,
            EnableEvents = function (self,val)
                if val then
                    self.OnEnterHandler = class.Handler(self,self.OnEnter);
                    self.OnExitHandler = class.Handler(self,self.OnExit);
                    self.OnEnterTransitionDidFinishHandler = class.Handler(self,self.OnEnterTransitionDidFinish);
                    self.OnExitTransitionDidStartHandler = class.Handler(self,self.OnExitTransitionDidStart);
                    self.OnCleanUpHandler = class.Handler(self,self.OnCleanUp);
                else
                    self.OnEnterHandler = nil;
                    self.OnExitHandler = nil;
                    self.OnEnterTransitionDidFinishHandler = nil;
                    self.OnExitTransitionDidStartHandler = nil;
                    self.OnCleanUpHandler = nil;
                end
            end,
            Layout = Layout
        }
    };
end