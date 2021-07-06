--[[
Copyright (c) 2021 wzhengsen.

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


---@class cc.Label

---简单地封装了Label，使其可以自动换行。
local Label = class(cc.Label);
Label.static.protected._DefaultFont = ""

---@param font? string 字体。
---@param fontSize number 字体大小。
---@param maxWidth? number 最大长度，超过长度，自动换行。
---@param align? number 对齐方式。
---@return cc.Label
function Label.__new__(font,fontSize,maxWidth,align)
    if "number" == type(font) then
        align = maxWidth;
        maxWidth = fontSize;
        fontSize = font;
        font = Label._DefaultFont or "";
    end

    maxWidth = maxWidth or 0;
    align = align or cc.TextHAlignment.CENTER;

    if not font or font == "" then
        local self = cc.Label.new();
        self.SystemFontSize = fontSize;
        self.MaxLineWidth = maxWidth;
        self.HorizontalAlignment = align;
        return self;
    end

    return cc.Label.CreateWithTTF(
        {
            fontFilePath = font,
            fontSize = fontSize
        },
        "",
        align,
        maxWidth
    );
end

function Label:ctor()
    self.LineBreakWithoutSpace = true;
    self.Overflow = cc.Label.Overflow.RESIZE_HEIGHT;
end

function Label.static.set.DefaultFont(fn)
    Label._DefaultFont = fn or "";
end

return Label;