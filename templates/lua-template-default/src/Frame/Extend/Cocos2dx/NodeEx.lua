--[[

Copyright (c) 2014-2017 Chukong Technologies Inc.

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

local Node = cc.Node

function Node:onUpdate(callback)
    self:scheduleUpdateWithPriorityLua(callback, 0)
    return self
end

Node.scheduleUpdate = Node.onUpdate

function Node:onNodeEvent(eventName, callback)
    if "enter" == eventName then
        self.onEnterCallback_ = callback
    elseif "exit" == eventName then
        self.onExitCallback_ = callback
    elseif "enterTransitionFinish" == eventName then
        self.onEnterTransitionFinishCallback_ = callback
    elseif "exitTransitionStart" == eventName then
        self.onExitTransitionStartCallback_ = callback
    elseif "cleanup" == eventName then
        self.onCleanupCallback_ = callback
    end
    self:enableNodeEvents()
end

function Node:enableNodeEvents()
    if self.isNodeEventEnabled_ then
        return self
    end

    self:registerScriptHandler(function(state)
        if state == "enter" then
            self:onEnter_()
        elseif state == "exit" then
            self:onExit_()
        elseif state == "enterTransitionFinish" then
            self:onEnterTransitionFinish_()
        elseif state == "exitTransitionStart" then
            self:onExitTransitionStart_()
        elseif state == "cleanup" then
            self:onCleanup_()
        end
    end)
    self.isNodeEventEnabled_ = true

    return self
end

function Node:disableNodeEvents()
    self:unregisterScriptHandler()
    self.isNodeEventEnabled_ = false
    return self
end


function Node:onEnter()
end

function Node:onExit()
end

function Node:onEnterTransitionFinish()
end

function Node:onExitTransitionStart()
end

function Node:onCleanup()
end

function Node:onEnter_()
    self:onEnter()
    if not self.onEnterCallback_ then
        return
    end
    self:onEnterCallback_()
end

function Node:onExit_()
    self:onExit()
    if not self.onExitCallback_ then
        return
    end
    self:onExitCallback_()
end

function Node:onEnterTransitionFinish_()
    self:onEnterTransitionFinish()
    if not self.onEnterTransitionFinishCallback_ then
        return
    end
    self:onEnterTransitionFinishCallback_()
end

function Node:onExitTransitionStart_()
    self:onExitTransitionStart()
    if not self.onExitTransitionStartCallback_ then
        return
    end
    self:onExitTransitionStartCallback_()
end

function Node:onCleanup_()
    self:onCleanup()
    if not self.onCleanupCallback_ then
        return
    end
    self:onCleanupCallback_()
end


--[[
    Func:   Node一些补充的封装方法
    Auth:   WangZhengSen
    Data:   2019.04.04
]]

--[[
    Func:   递归查找子节点
    Param:  number
    Return: Node
]]
function Node:SeekNodeByTag(nTag)
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

--[[
    Func:   递归查找子节点
    Param:  string|number
    Return: Node
]]
function Node:SeekNode(sn)
    if type(sn) == "string" then
        local node = nil
        self:enumerateChildren("//"..sn,function(sNode)
            node = sNode;
            return true;
        end);
        return node;
    elseif type(sn) == "number" then
        return self:SeekNodeByTag(sn);
    end
end

function Node:SeekNodeInSelf(sn)
    if type(sn) == "string" then
        return self:getChildByName(sn);
    elseif type(sn) == "number" then
        return self:getChildByTag(sn);
    end
end

-- 整除运算指向SeekNode
Node[".idiv"] = Node.SeekNode;
-- 除法运算指向SeekNodeInSelf
Node[".div"] = Node.SeekNodeInSelf;


--[[
    Func:   置于父级顶部
]]
function Node:SetTop()
    local p = self:getParent();
    if class.IsNull(p) then return; end

    local cC = p:getChildren();
    local maxZOrder = nil;
    for _,v in ipairs(cC) do
        local zOrder = v:getLocalZOrder();
        if not maxZOrder or zOrder > maxZOrder then
            maxZOrder = zOrder;
        end
    end
    self:setLocalZOrder(maxZOrder + 1);
end

--[[
    Func:   绑定一个布局组件，并指定绑定参数。
    Param:  table|boolean
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
function Node:Layout(layoutParam)
    layoutParam = nil == layoutParam or layoutParam;
    local pType = type(layoutParam);
    if "table" == pType then
        local layout = LayoutComponent.bindLayoutComponent(self);
        layout:setActiveEnabled(true);
        for k,v in pairs(layoutParam) do
            local isBoolean = "boolean" == type(v);
            if "pw" == k then
                if isBoolean then
                    layout:setPercentWidthEnabled(v);
                else
                    layout:setPercentWidthEnabled(true);
                    layout:setPercentWidth(v);
                end
            elseif "ph" == k then
                if isBoolean then
                    layout:setPercentHeightEnabled(v);
                else
                    layout:setPercentHeightEnabled(true);
                    layout:setPercentHeight(v);
                end
            elseif "sw" == k then
                if isBoolean then
                    layout:setStretchWidthEnabled(v);
                end
            elseif "sh" == k then
                if isBoolean then
                    layout:setStretchHeightEnabled(v);
                end
            elseif "px" == k then
                if isBoolean then
                    layout:setPositionPercentXEnabled(v);
                else
                    layout:setPositionPercentXEnabled(true);
                    layout:setPositionPercentX(v);
                end
            elseif "py" == k then
                if isBoolean then
                    layout:setPositionPercentYEnabled(v);
                else
                    layout:setPositionPercentYEnabled(true);
                    layout:setPositionPercentY(v);
                end
            elseif "lm" == k or "rm" == k then
                local he = layout:getHorizontalEdge();
                if "lm" == k then
                    if isBoolean then
                        he = v
                        and (he | HorizontalEdge.Left)
                        or (he & HorizontalEdge.Right);
                    else
                        he = he | HorizontalEdge.Left;
                        layout:setLeftMargin(v);
                    end
                else
                    if isBoolean then
                        he = v
                        and (he | HorizontalEdge.Right)
                        or (he & HorizontalEdge.Left);
                    else
                        he = he | HorizontalEdge.Right;
                        layout:setRightMargin(v);
                    end
                end
                layout:setHorizontalEdge(he);
            elseif "tm" == k or "bm" == k then
                local ve = layout:getVerticalEdge();
                if "tm" == k then
                    if isBoolean then
                        ve = v
                        and (ve | VerticalEdge.Top)
                        or (ve & VerticalEdge.Bottom);
                    else
                        ve = (ve | VerticalEdge.Top);
                        layout:setTopMargin(v);
                    end
                else
                    if isBoolean then
                        ve = v
                        and (ve | VerticalEdge.Bottom)
                        or (ve & VerticalEdge.Top);
                    else
                        ve = (ve | VerticalEdge.Bottom);
                        layout:setBottomMargin(v);
                    end
                end
                layout:setVerticalEdge(ve);
            end
        end

        layout:refreshLayout();
    else
        local layout = self:getComponent("__ui_layout");
        if not layout then
            if layoutParam then
                ccui.Helper.doLayout(self);
            end
        else
            layout:setActiveEnabled(layoutParam);
            if layoutParam then
                layout:refreshLayout();
            end
        end
    end
end