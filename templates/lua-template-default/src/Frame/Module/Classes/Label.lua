--[[
    Auth:       wzhengsen
    Date:       2020.03.26
    Desc:       简单地封装了Label，使其可以自动换行。
]]

--[[
    Param:  string{DefaultFont}                 字体。
            number                              字体大小。
            number{0}                           最大长度，超过长度，自动换行。
            number{cc.TextHAlignment.CENTER}    对齐方式。
]]
local Label = nil;
Label = class(function(font,fontSize,maxWidth,align)
    if "number" == type(font) then
        align = maxWidth;
        maxWidth = fontSize;
        fontSize = font;
        font = Label.DefaultFont or "";
    end

    maxWidth = maxWidth or 0;
    align = align or cc.TextHAlignment.CENTER;

    if not font or font == "" then
        local self = cc.Label.new();
        self:setSystemFontSize(fontSize);
        self:setMaxLineWidth(maxWidth);
        self:setHorizontalAlignment(align);
        return self;
    end

    return cc.Label.createWithTTFConfig(
        {
            fontFilePath = font,
            fontSize = fontSize
        },
        "",
        align,
        maxWidth
    );
end);

function Label:ctor()
    self.LineBreakWithoutSpace = true;
    self.Overflow = cc.Label.Overflow.RESIZE_HEIGHT;
end

function Label.SetDefaultFont(fn)
    Label.DefaultFont = fn or "";
end

return Label;