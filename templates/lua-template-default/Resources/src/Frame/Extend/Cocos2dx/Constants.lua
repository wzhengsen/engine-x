local cc = cc;

cc.AnimationFrameDisplayedNotification = "CCAnimationFrameDisplayedNotification";

cc.ParticleSystem.DURATION_INFINITY = -1;
cc.ParticleSystem.START_SIZE_EQUAL_TO_END_SIZE = -1;
cc.ParticleSystem.START_RADIUS_EQUAL_TO_END_RADIUS = -1;

local Color = nil;
Color = setmetatable(
    {__name = "Color"},
    {
        __call = function(_, r, g, b)
            return setmetatable(
                {
                    r = math.Limit(math.tointeger(r), 0, 255),
                    g = math.Limit(math.tointeger(g), 0, 255),
                    b = math.Limit(math.tointeger(b), 0, 255)
                },
                Color
            )
        end
    }
);
Color.__index = Color;

function Color:__add(c2)
    return Color((self.r + c2.r) / 2, (self.g + c2.g) / 2, (self.b + c2.b) / 2);
end

function Color:__eq(c2)
    return (self.r == c2.r) and (self.g == c2.g) and (self.b == c2.b);
end

--- 白色
Color.White = Color(255, 255, 255);
--- 黑色
Color.Black = Color(0, 0, 0);
--- 灰色
Color.Gray = Color.White + Color.Black;
--- 银色
Color.Silver = Color.Gray + Color.White;
--- 暗色
Color.Dark = Color.Gray + Color.Black;
--- 米色
Color.Beige = Color(0xf5, 0xf5, 0xdc);
--- 象牙白
Color.Ivory = Color(0xff, 0xff, 0xf0);
--- 石灰色
Color.Slate = Color(0x70, 0x80, 0x90);
--- 雪色
Color.Snow = Color(0xff, 0xfa, 0xfa);

--- 红色
Color.Red = Color(255, 0, 0);
--- 棕色
Color.Brown = Color(0xa5, 0x2a, 0x2a);
--- 三文鱼色
Color.Salmon = Color(255, 128, 114);
--- 番茄红
Color.Tomato = Color(0xff, 0x63, 0x47);
--- 珊瑚红
Color.Coral = Color(0xff, 0x7f, 0x50);
--- 粉红色
Color.Pink = Color.Red + Color.White;
--- 栗色
Color.Maroon = Color.Red + Color.Black;

--- 黄色
Color.Yellow = Color(255, 255, 0);
--- 淡黄色
Color.LightYellow = Color.Yellow + Color.White;
--- 橄榄色
Color.Olive = Color.Yellow + Color.Black;
--- 黄土色
Color.Sienna = Color(0xa0, 0x52, 0x2d);
--- 巧克力色
Color.Chocolate = Color(0xd2, 0x69, 0x1e);
--- 小麦色
Color.Wheat = Color(0xf5, 0xde, 0xb3);
--- 金色
Color.Gold = Color(0xff, 0xd7, 0x00);
--- 卡其色
Color.Khaki = Color(0xf0, 0xe6, 0x8c);

--- 绿色
Color.Green = Color(0, 255, 0);
--- 浅绿色
Color.LightGreen = Color.Green + Color.White;
--- 森林绿
Color.Forest = Color.Green + Color.Black;
--- 黄绿色
Color.Chartreuse = Color(0x7f, 0xff, 0x00);
--- 苍绿色
Color.PaleGreen = Color(0x98, 0xfb, 0x98);
--- 青柠绿
Color.LimeGreen = Color(0x32, 0xcd, 0x32);
--- 春绿色
Color.SpringGreen = Color(0x00, 0xff, 0x7f);

--- 水色
Color.Aqua = Color(0, 255, 255);
--- 青色
Color.Cyan = Color.Aqua + Color.White;
--- 蓝绿色
Color.Teal = Color.Aqua + Color.Black;
--- 绿松石
Color.Turquoise = Color(0x40, 0xe0, 0xd0);
--- 淡青色
Color.LightCyan = Color(0xe0, 0xff, 0xff);

--- 蓝色
Color.Blue = Color(0, 0, 255);
--- 淡蓝色
Color.LightBlue = Color.Blue + Color.White;
--- 深蓝色
Color.Navy = Color.Blue + Color.Black;
--- 粉蓝色
Color.PowderBlue = Color(0xb0, 0xe0, 0xe6);
--- 天蓝色
Color.Sky = Color(0x87, 0xce, 0xeb);
--- 钢蓝色
Color.Steel = Color(0x46, 0x82, 0xb4);
--- 薰衣草蓝
Color.Lavender = Color(0xe6, 0xe6, 0xfa);
--- 午夜蓝
Color.Midnight = Color(0x19, 0x19, 0x70);

--- 紫红色
Color.Fuchsia = Color(255, 0, 255);
--- 紫色
Color.Purple = Color.Fuchsia + Color.Black;
--- 蓝紫色
Color.BlueViolet = Color(0x8a, 0x2b, 0xe2);
--- 靛蓝色
Color.Indigo = Color(0x4b, 0x00, 0x82);
--- 梅花紫
Color.Plum = Color(0xdd, 0xa0, 0xdd);
--- 淡紫色
Color.Violet = Color(0xee, 0x82, 0xee);
--- 兰紫色
Color.Orchid = Color(0xda, 0x70, 0xd6);

--- 橘色
Color.Orange = Color.Yellow + Color.Red;

cc.Color = Color;

cc.AnchorPoint = {
    Center = {x = 0.5, y = 0.5},
    LeftTop = {x = 0, y = 1},
    RightTop = {x = 1, y = 1},
    LeftBottom = {x = 0, y = 0},
    RightBottom = {x = 1, y = 0},
    Top = {x = 0.5, y = 1},
    Bottom = {x = 0.5, y = 0},
    Left = {x = 0, y = 0.5},
    Right = {x = 1, y = 0.5}
};