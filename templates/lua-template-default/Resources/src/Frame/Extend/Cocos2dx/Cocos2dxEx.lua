-- Copyright (c) 2021 wzhengsen

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.

local cc = cc;
local ccui = ccui;
local type = type;

-- 一些自定义的属性等。

local Node = cc.Node;
function Node.set:Parent(p)
    if class.IsNull(p) then
        self:RemoveFromParent();
    else
        local op = self:GetParent();
        if op then
            if op ~= p then
                self:Retain();
                self:RemoveFromParent(false);
                p:AddChild(self);
                self:Release();
            end
        else
            p:AddChild(self);
        end
    end
end
Node.set.X = Node.SetPositionX;
Node.set.Y = Node.SetPositionY;
Node.set.Z = Node.SetPositionZ;
Node.set.XY = Node.SetPosition;
Node.set.Size = Node.SetContentSize;

Node.get.X = Node.GetPositionX;
Node.get.Y = Node.GetPositionY;
Node.get.Z = Node.GetPositionZ;
Node.get.XY = Node.GetPositionXY;
Node.get.Size = Node.GetContentSize;

local Label = cc.Label;
function Label.set:Italics(b)
    if b then
        self:EnableItalics();
    else
        self:DisableEffect(cc.LabelEffect.ITALICS);
    end
end
function Label.set:Bold(b)
    if b then
        self:EnableBold();
    else
        self:DisableEffect(cc.LabelEffect.BLOD);
    end
end
function Label.set:Underline(b)
    if b then
        self:EnableUnderline();
    else
        self:DisableEffect(cc.LabelEffect.UNDERLINE);
    end
end
function Label.set:Strikethrough(b)
    if b then
        self:EnableStrikethrough();
    else
        self:DisableEffect(cc.LabelEffect.STRIKETHROUGH);
    end
end
function Label.set:Shadow(bc)
    if bc then
        if "table" == type(bc) then
            self:EnableShadow(bc);
        else
            self:EnableShadow();
        end
    else
        self:DisableEffect(cc.LabelEffect.SHADOW);
    end
end
function Label.set:Outline(bc)
    if bc then
        if "table" == type(bc) then
            self:EnableOutline(bc);
        else
            self:EnableOutline();
        end
    else
        self:DisableEffect(cc.LabelEffect.OUTLINE);
    end
end
function Label.set:Glow(bc)
    if bc then
        if "table" == type(bc) then
            self:EnableGlow(bc);
        else
            self:EnableGlow();
        end
    else
        self:DisableEffect(cc.LabelEffect.GLOW);
    end
end
Label.set.Wrap = Label.EnableWrap;

local MenuItem = cc.MenuItem;
function MenuItem.set:Selected(b)
    if b then
        self:Selected();
    else
        self:Unselected();
    end
end

local ProgressTimer = cc.ProgressTimer;
function ProgressTimer.get:Percent()
    return self:GetPercentage() / 100;
end
function ProgressTimer.set:Percent(val)
    self:SetPercentage(val * 100);
end

local Sprite = cc.Sprite;
Sprite.private.__spriteGrayed = nil;
function Sprite.get:Grayed()
    return self.__spriteGrayed or false;
end
function Sprite.set:Grayed(val)
    val = not not val;
    if self.__spriteGrayed == val then
        return;
    end
    self.ProgramState = val and ccb.ProgramType.GRAY_SCALE or ccb.ProgramType.POSITION_TEXTURE_COLOR;
    self.__spriteGrayed = val;
end

local EventAssetsManagerEx = cc.EventAssetsManagerEx;
function EventAssetsManagerEx.get:Percent()
    return EventAssetsManagerEx:GetPercent(self) / 100;
end
function EventAssetsManagerEx.get:PercentByFile()
    return EventAssetsManagerEx.getPercentByFile(self) / 100;
end

local Widget = ccui.Widget;
Widget.set.TouchHandler = Widget.AddTouchEventListener;
Widget.set.ClickHandler = Widget.AddClickEventListener;

local EditBox = ccui.EditBox;
function EditBox.set:EditHandler(val)
    if val == nil then
        self:UnregisterScriptEditBoxHandler();
    else
        self:RegisterScriptEditBoxHandler(val);
    end
end

local LoadingBar = ccui.LoadingBar;
function LoadingBar.get:Percent()
    return self:GetPercent() / 100;
end
function LoadingBar.get:Percent(val)
    self:SetPercent(val * 100);
end

local Slider = ccui.Slider;
function Slider.get:Percent()
    return self:GetPercent() / 100;
end
function Slider.get:MaxPercent()
    return self:getMaxPercent() / 100;
end
function Slider.set:Percent(val)
    self:SetPercent(val * 100);
end
function Slider.set:MaxPercent(val)
    self:SetMaxPercent(val * 100);
end

local Text = ccui.Text;
function Text.set:Shadow(bc)
    if bc then
        if "table" == type(bc) then
            self:EnableShadow(bc);
        else
            self:EnableShadow();
        end
    else
        self:DisableEffect(cc.LabelEffect.SHADOW);
    end
end
function Text.set:Outline(bc)
    if bc then
        if "table" == type(bc) then
            self:EnableOutline(bc);
        else
            self:EnableOutline();
        end
    else
        self:DisableEffect(cc.LabelEffect.OUTLINE);
    end
end
function Text.set:Glow(bc)
    if bc then
        if "table" == type(bc) then
            self:EnableGlow(bc);
        else
            self:EnableGlow();
        end
    else
        self:DisableEffect(cc.LabelEffect.GLOW);
    end
end

local VideoPlayer = ccui.VideoPlayer;
VideoPlayer.set.EventHandler = VideoPlayer.AddEventListener;

local WebView = ccui.WebView;
WebView.set.Url = WebView.LoadURL;
WebView.set.File = WebView.LoadFile;

local QrCode = ccui.QrCode;
QrCode.set.String = QrCode.LoadCodeByString;