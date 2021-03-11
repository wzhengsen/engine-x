local cc = cc;
local ccb = ccb;
local ccs = ccs;

cc.CC_EDIT_BOX_PADDING = 5;
cc.Sprite.INDEX_NOT_INITIALIZED = -1;

cc.FastTMXLayer.FAST_TMX_ORIENTATION_ORTHO = 0;
cc.FastTMXLayer.FAST_TMX_ORIENTATION_HEX  = 2;
cc.FastTMXLayer.FAST_TMX_ORIENTATION_ISO  = 1;

cc.BLEND_DST = 0x303;
cc.BLEND_SRC = 0x1;

cc.Action.INVALID_TAG   = -1;

cc.Node.INVALID_TAG = -1;

cc.Scheduler.PRIORITY_NON_SYSTEM_MIN  = -2147483647;
cc.Scheduler.PRIORITY_SYSTEM  = -2147483648;
cc.REPEAT_FOREVER   = 0xfffffffe;

cc.TMXTileFlags = {
    kTMXTileHorizontalFlag  = 0x80000000,
    kTMXTileVerticalFlag    = 0x40000000,
    kTMXTileDiagonalFlag    = 0x20000000,
    kTMXFlipedAll           = 0x80000000|0x40000000|0x20000000,
    kTMXFlippedMask         = ~(0x80000000|0x40000000|0x20000000)
};

cc.ANIMATION_FRAME_DISPLAYED_NOTIFICATION = "CCAnimationFrameDisplayedNotification";

cc.ApplicationProtocol = cc.ApplicationProtocol or {};
cc.ApplicationProtocol.Platform = {
    OS_WINDOWS = 0,
    OS_LINUX   = 1,
    OS_MAC     = 2,
    OS_ANDROID = 3,
    OS_IPHONE  = 4,
    OS_IPAD    = 5,
    OS_BLACKBERRY = 6,
    OS_NACL    = 7,
    OS_EMSCRIPTEN = 8,
    OS_TIZEN   = 9,
    OS_WINRT   = 10,
    OS_WP8     = 11
};

cc.LanguageType = {
    ENGLISH    = 0,
    CHINESE    = 1,
    FRENCH     = 2,
    ITALIAN    = 3,
    GERMAN     = 4,
    SPANISH    = 5,
    DUTCH      = 6,
    RUSSIAN    = 7,
    KOREAN     = 8,
    JAPANESE   = 9,
    HUNGARIAN  = 10,
    PORTUGUESE = 11,
    ARABIC     = 12,
    NORWEGIAN  = 13,
    POLISH     = 14,
    TURKISH    = 15,
    UKRAINIAN  = 16,
    ROMANIAN   = 17,
    BULGARIAN  = 18,
    BELARUSIAN = 19
};

cc.EventListener.Type = {
    UNKNOWN = 0,
    TOUCH_ONE_BY_ONE = 1,
    TOUCH_ALL_AT_ONCE = 2,
    KEYBOARD = 3,
    MOUSE= 4,
    ACCELERATION = 5,
    FOCUS = 6,
    GAME_CONTROLLER = 7,
    CUSTOM = 8
};

cc.PHYSICSSHAPE_MATERIAL_DEFAULT = {
    density = 0.0,
    restitution = 0.0,
    friction = 0.0
};

cc.PHYSICSBODY_MATERIAL_DEFAULT = {
    density = 0.1,
    restitution = 0.5,
    friction = 0.5
};

cc.GlyphCollection = {
    DYNAMIC = 0,
    NEHE = 1,
    ASCII = 2,
    CUSTOM = 3
};

cc.LabelEffect = {
    NORMAL          = 0,
    OUTLINE         = 1,
    SHADOW          = 2,
    GLOW            = 3,
    ITALICS         = 4,
    BOLD            = 5,
    UNDERLINE       = 6,
    STRIKETHROUGH   = 7,
    ALL             = 8
}

cc.Label.Overflow = {
    NONE = 0,
    CLAMP = 1,
    SHRINK = 2,
    RESIZE_HEIGHT = 3
};

cc.Label.LabelType = {
    TTF = 0,
    BMFONT = 1,
    CHARMAP = 2,
    STRING_TEXTURE = 3
};

local KeyCodeKey = {
    "KEY_NONE",
    "KEY_PAUSE",
    "KEY_SCROLL_LOCK",
    "KEY_PRINT",
    "KEY_SYSREQ",
    "KEY_BREAK",
    "KEY_ESCAPE",
    "KEY_BACKSPACE",
    "KEY_TAB",
    "KEY_BACK_TAB",
    "KEY_RETURN",
    "KEY_CAPS_LOCK",
    "KEY_SHIFT",
    "KEY_RIGHT_SHIFT",
    "KEY_CTRL",
    "KEY_RIGHT_CTRL",
    "KEY_ALT",
    "KEY_RIGHT_ALT",
    "KEY_MENU",
    "KEY_HYPER",
    "KEY_INSERT",
    "KEY_HOME",
    "KEY_PG_UP",
    "KEY_DELETE",
    "KEY_END",
    "KEY_PG_DOWN",
    "KEY_LEFT_ARROW",
    "KEY_RIGHT_ARROW",
    "KEY_UP_ARROW",
    "KEY_DOWN_ARROW",
    "KEY_NUM_LOCK",
    "KEY_KP_PLUS",
    "KEY_KP_MINUS",
    "KEY_KP_MULTIPLY",
    "KEY_KP_DIVIDE",
    "KEY_KP_ENTER",
    "KEY_KP_HOME",
    "KEY_KP_UP",
    "KEY_KP_PG_UP",
    "KEY_KP_LEFT",
    "KEY_KP_FIVE",
    "KEY_KP_RIGHT",
    "KEY_KP_END",
    "KEY_KP_DOWN",
    "KEY_KP_PG_DOWN",
    "KEY_KP_INSERT",
    "KEY_KP_DELETE",
    "KEY_F1",
    "KEY_F2",
    "KEY_F3",
    "KEY_F4",
    "KEY_F5",
    "KEY_F6",
    "KEY_F7",
    "KEY_F8",
    "KEY_F9",
    "KEY_F10",
    "KEY_F11",
    "KEY_F12",
    "KEY_SPACE",
    "KEY_EXCLAM",
    "KEY_QUOTE",
    "KEY_NUMBER",
    "KEY_DOLLAR",
    "KEY_PERCENT",
    "KEY_CIRCUMFLEX",
    "KEY_AMPERSAND",
    "KEY_APOSTROPHE",
    "KEY_LEFT_PARENTHESIS",
    "KEY_RIGHT_PARENTHESIS",
    "KEY_ASTERISK",
    "KEY_PLUS",
    "KEY_COMMA",
    "KEY_MINUS",
    "KEY_PERIOD",
    "KEY_SLASH",
    "KEY_0",
    "KEY_1",
    "KEY_2",
    "KEY_3",
    "KEY_4",
    "KEY_5",
    "KEY_6",
    "KEY_7",
    "KEY_8",
    "KEY_9",
    "KEY_COLON",
    "KEY_SEMICOLON",
    "KEY_LESS_THAN",
    "KEY_EQUAL",
    "KEY_GREATER_THAN",
    "KEY_QUESTION",
    "KEY_AT",
    "KEY_CAPITAL_A",
    "KEY_CAPITAL_B",
    "KEY_CAPITAL_C",
    "KEY_CAPITAL_D",
    "KEY_CAPITAL_E",
    "KEY_CAPITAL_F",
    "KEY_CAPITAL_G",
    "KEY_CAPITAL_H",
    "KEY_CAPITAL_I",
    "KEY_CAPITAL_J",
    "KEY_CAPITAL_K",
    "KEY_CAPITAL_L",
    "KEY_CAPITAL_M",
    "KEY_CAPITAL_N",
    "KEY_CAPITAL_O",
    "KEY_CAPITAL_P",
    "KEY_CAPITAL_Q",
    "KEY_CAPITAL_R",
    "KEY_CAPITAL_S",
    "KEY_CAPITAL_T",
    "KEY_CAPITAL_U",
    "KEY_CAPITAL_V",
    "KEY_CAPITAL_W",
    "KEY_CAPITAL_X",
    "KEY_CAPITAL_Y",
    "KEY_CAPITAL_Z",
    "KEY_LEFT_BRACKET",
    "KEY_BACK_SLASH",
    "KEY_RIGHT_BRACKET",
    "KEY_UNDERSCORE",
    "KEY_GRAVE",
    "KEY_A",
    "KEY_B",
    "KEY_C",
    "KEY_D",
    "KEY_E",
    "KEY_F",
    "KEY_G",
    "KEY_H",
    "KEY_I",
    "KEY_J",
    "KEY_K",
    "KEY_L",
    "KEY_M",
    "KEY_N",
    "KEY_O",
    "KEY_P",
    "KEY_Q",
    "KEY_R",
    "KEY_S",
    "KEY_T",
    "KEY_U",
    "KEY_V",
    "KEY_W",
    "KEY_X",
    "KEY_Y",
    "KEY_Z",
    "KEY_LEFT_BRACE",
    "KEY_BAR",
    "KEY_RIGHT_BRACE",
    "KEY_TILDE",
    "KEY_EURO",
    "KEY_POUND",
    "KEY_YEN",
    "KEY_MIDDLE_DOT",
    "KEY_SEARCH",
    "KEY_DPAD_LEFT",
    "KEY_DPAD_RIGHT",
    "KEY_DPAD_UP",
    "KEY_DPAD_DOWN",
    "KEY_DPAD_CENTER",
    "KEY_ENTER",
    "KEY_PLAY"
}
cc.EventKeyboard.KeyCode = {
};

local KeyCode = cc.EventKeyboard.KeyCode;
for k,v in ipairs(KeyCodeKey) do
    KeyCode[v] = k - 1;
end
KeyCode.KEY_BACK        = KeyCode.KEY_ESCAPE;
KeyCode.KEY_LEFT_SHIFT  = KeyCode.KEY_SHIFT;
KeyCode.KEY_LEFT_CTRL   = KeyCode.KEY_CTRL;
KeyCode.KEY_LEFT_ALT    = KeyCode.KEY_ALT;

cc.EventAssetsManagerEx.EventCode = {
    ERROR_NO_LOCAL_MANIFEST = 0,
    ERROR_DOWNLOAD_MANIFEST = 1,
    ERROR_PARSE_MANIFEST = 2,
    NEW_VERSION_FOUND = 3,
    ALREADY_UP_TO_DATE = 4,
    UPDATE_PROGRESSION = 5,
    ASSET_UPDATED = 6,
    ERROR_UPDATING = 7,
    UPDATE_FINISHED = 8,
    UPDATE_FAILED = 9,
    ERROR_DECOMPRESS = 10
};

cc.AssetsManagerEx.VERSION_ID ="@version";
cc.AssetsManagerEx.MANIFEST_ID ="@manifest";

cc.AudioEngine.INVALID_AUDIO_ID = -1;
cc.AudioEngine.TIME_UNKNOWN = -1.0;

cc.CameraFlag = {
    DEFAULT = 1,
    USER1 = 1 << 1,
    USER2 = 1 << 2,
    USER3 = 1 << 3,
    USER4 = 1 << 4,
    USER5 = 1 << 5,
    USER6 = 1 << 6,
    USER7 = 1 << 7,
    USER8 = 1 << 8
};

cc.CameraBackgroundBrush.BrushType =
{
    NONE = 0,
    DEPTH = 1,
    COLOR = 2,
    SKYBOX = 3
};

cc.MATRIX_STACK_TYPE =
{
    MATRIX_STACK_MODELVIEW = 0,
    MATRIX_STACK_PROJECTION = 1,
    MATRIX_STACK_TEXTURE = 2
};

cc.LightType =
{
    DIRECTIONAL = 0,
    POINT = 1,
    SPOT = 2,
    AMBIENT = 3
};

local lightFlag = {};
cc.LightFlag = lightFlag;
for i = 0,15 do
    lightFlag["LIGHT"..i] = 1 << i;
end

cc.AsyncTaskPool.TaskType =
{
    TASK_IO = 0,
    TASK_NETWORK = 1,
    TASK_OTHER = 2,
    TASK_MAX_TYPE = 3
};

cc.ParticleSystem.Mode =
{
    GRAVITY = 0,
    RADIUS = 1
};

cc.ParticleSystem.PositionType =
{
    FREE = 0,
    RELATIVE = 1,
    GROUPED = 2
};

cc.ParticleSystem.DURATION_INFINITY = -1;
cc.ParticleSystem.START_SIZE_EQUAL_TO_END_SIZE = -1;
cc.ParticleSystem.START_RADIUS_EQUAL_TO_END_RADIUS = -1;

cc.ProgressTimer.Type =
{
    RADIAL = 0,
    BAR = 1
};

cc.NavMeshAgent.NavMeshAgentSyncFlag =
{
    NONE = 0,
    NODE_TO_AGENT = 1,
    AGENT_TO_NODE = 2,
    NODE_AND_NODE = 1 | 2
};

cc.NavMeshObstacle.NavMeshObstacleSyncFlag =
{
    NONE = 0,
    NODE_TO_OBSTACLE = 1,
    OBSTACLE_TO_NODE = 2,
    NODE_AND_NODE = 1 | 2,
};

cc.Event.Type =
{
    TOUCH = 0,
    KEYBOARD = 1,
    ACCELERATION = 2,
    MOUSE = 3,
    FOCUS = 4,
    GAME_CONTROLLER = 5,
    CUSTOM = 6
};

cc.EventMouse.MouseEventType =
{
    MOUSE_NONE = 0,
    MOUSE_DOWN = 1,
    MOUSE_UP = 2,
    MOUSE_MOVE = 3,
    MOUSE_SCROLL = 4
};

cc.EventMouse.MouseButton =
{
    BUTTON_UNSET   = -1,
    BUTTON_LEFT    =  0,
    BUTTON_RIGHT   =  1,
    BUTTON_MIDDLE  =  2,
    BUTTON_4       =  3,
    BUTTON_5       =  4,
    BUTTON_6       =  5,
    BUTTON_7       =  6,
    BUTTON_8       =  7
};

cc.EventTouch.EventCode =
{
    BEGAN = 0,
    MOVED = 1,
    ENDED = 2,
    CANCELLED = 3
};

cc.PhysicsShape.Type =
{
    UNKNOWN = 0,
    CIRCLE = 1,
    BOX = 2,
    POLYGON = 3,
    EDGESEGMENT = 4,
    EDGEBOX = 5,
    EDGEPOLYGON = 6,
    EDGECHAIN = 7
};

cc.PhysicsContact.EventCode =
{
    NONE = 0,
    BEGIN = 1,
    PRESOLVE = 2,
    POSTSOLVE = 3,
    SEPARATE = 4
};

cc.Image.Format =
{
    JPG = 0,
    PNG = 1,
    TIFF = 2,
    WEBP = 3,
    PVR = 4,
    ETC = 5,
    S3TC = 6,
    ATITC = 7,
    TGA = 8,
    RAW_DATA = 9,
    UNKNOWN = 10
};

cc.Texture2D.PixelFormat =
{
    AUTO = 0,
    BGRA8888 = 1,
    RGBA8888 = 2,
    RGB888 = 3,
    RGB565 = 4,
    A8 = 5,
    I8 = 6,
    AI88 = 7,
    RGBA4444 = 8,
    RGB5A1 = 9,
    PVRTC4 = 10,
    PVRTC4A = 11,
    PVRTC2 = 12,
    PVRTC2A = 13,
    ETC = 14,
    S3TC_DXT1 = 15,
    S3TC_DXT3 = 16,
    S3TC_DXT5 = 17,
    ATC_RGB = 18,
    ATC_EXPLICIT_ALPHA = 19,
    ATC_INTERPOLATED_ALPHA = 20,
    DEFAULT = 0,

    NONE = -1
};

cc.TextVAlignment = {
    TOP = 0,
    CENTER = 1,
    BOTTOM = 2
};

cc.TextHAlignment = {
    LEFT = 0,
    CENTER = 1,
    RIGHT = 2
};

cc.ResolutionPolicy =
{
    EXACT_FIT = 0,
    NO_BORDER = 1,
    SHOW_ALL  = 2,
    FIXED_HEIGHT  = 3,
    FIXED_WIDTH  = 4,
    UNKNOWN  = 5
};

cc.TransitionScene.Orientation = {
    LEFT_OVER = 0,
    RIGHT_OVER = 1,
    UP_OVER = 0,
    DOWN_OVER = 1
};

cc.Touch.DispatchMode = {
    ALL_AT_ONCE = 0,
    ONE_BY_ONE = 1
};
cc.PhysicsWorld.DEBUGDRAW_NONE = 0x00;
cc.PhysicsWorld.DEBUGDRAW_SHAPE = 0x01;
cc.PhysicsWorld.DEBUGDRAW_JOINT = 0x02;
cc.PhysicsWorld.DEBUGDRAW_CONTACT = 0x04;
cc.PhysicsWorld.DEBUGDRAW_ALL = cc.PhysicsWorld.DEBUGDRAW_SHAPE | cc.PhysicsWorld.DEBUGDRAW_JOINT | cc.PhysicsWorld.DEBUGDRAW_CONTACT;

cc.PhysicsBody.MATERIAL_DEFAULT = {
    density = 0.1,
    restitution = 0.5,
    friction = 0.5
};

cc.WebSocket.ErrorCode = {
    TIME_OUT = 0,
    CONNECTION_FAILURE = 1,
    UNKNOWN = 2
};

cc.WebSocket.State = {
    CONNECTING = 0,
    OPEN = 1,
    CLOSING = 2,
    CLOSED = 3
};

cc.XMLHttpRequest.ResponseType = {
    STRING = 0,
    ARRAY_BUFFER = 1,
    BLOB = 2,
    DOCUMENT = 3,
    JSON = 4
};

local Color = nil;
Color = setmetatable(
    {__name = "Color"},
    {
        __call = function (_,r,g,b)
            return setmetatable(
            {
                r = math.Limit(math.tointeger(r),0,255),
                g = math.Limit(math.tointeger(g),0,255),
                b = math.Limit(math.tointeger(b),0,255)
            },
            Color
        );
        end
    }
);
Color.__index = Color;

function Color:__add(c2)
    return Color(
        (self.r + c2.r) / 2,
        (self.g + c2.g) / 2,
        (self.b + c2.b) / 2
    );
end

function Color:__eq(c2)
    return (self.r == c2.r) and (self.g == c2.g) and (self.b == c2.b);
end

--- 白色
Color.White = Color(255,255,255);
--- 黑色
Color.Black = Color(0,0,0);
--- 灰色
Color.Gray = Color.White + Color.Black;
--- 银色
Color.Silver = Color.Gray + Color.White;
--- 暗色
Color.Dark = Color.Gray + Color.Black;
--- 米色
Color.Beige = Color(0xf5,0xf5,0xdc);
--- 象牙白
Color.Ivory = Color(0xff,0xff,0xf0);
--- 石灰色
Color.Slate = Color(0x70,0x80,0x90);
--- 雪色
Color.Snow = Color(0xff,0xfa,0xfa);

--- 红色
Color.Red = Color(255,0,0);
--- 棕色
Color.Brown = Color(0xa5,0x2a,0x2a);
--- 三文鱼色
Color.Salmon = Color(255,128,114);
--- 番茄红
Color.Tomato = Color(0xff,0x63,0x47);
--- 珊瑚红
Color.Coral = Color(0xff,0x7f,0x50);
--- 粉红色
Color.Pink = Color.Red + Color.White;
--- 栗色
Color.Maroon = Color.Red + Color.Black;

--- 黄色
Color.Yellow = Color(255,255,0);
--- 淡黄色
Color.LightYellow = Color.Yellow + Color.White;
--- 橄榄色
Color.Olive = Color.Yellow + Color.Black;
--- 黄土色
Color.Sienna = Color(0xa0,0x52,0x2d);
--- 巧克力色
Color.Chocolate = Color(0xd2,0x69,0x1e);
--- 小麦色
Color.Wheat = Color(0xf5,0xde,0xb3);
--- 金色
Color.Gold = Color(0xff,0xd7,0x00);
--- 卡其色
Color.Khaki = Color(0xf0,0xe6,0x8c);

--- 绿色
Color.Green = Color(0,255,0);
--- 浅绿色
Color.LightGreen = Color.Green + Color.White;
--- 森林绿
Color.Forest = Color.Green + Color.Black;
--- 黄绿色
Color.Chartreuse = Color(0x7f,0xff,0x00);
--- 苍绿色
Color.PaleGreen = Color(0x98,0xfb,0x98);
--- 青柠绿
Color.LimeGreen = Color(0x32,0xcd,0x32);
--- 春绿色
Color.SpringGreen = Color(0x00,0xff,0x7f);

--- 水色
Color.Aqua = Color(0,255,255);
--- 青色
Color.Cyan = Color.Aqua + Color.White;
--- 蓝绿色
Color.Teal = Color.Aqua + Color.Black;
--- 绿松石
Color.Turquoise = Color(0x40,0xe0,0xd0);
--- 淡青色
Color.LightCyan = Color(0xe0,0xff,0xff);

--- 蓝色
Color.Blue = Color(0,0,255);
--- 淡蓝色
Color.LightBlue = Color.Blue + Color.White;
--- 深蓝色
Color.Navy = Color.Blue + Color.Black;
--- 粉蓝色
Color.PowderBlue = Color(0xb0,0xe0,0xe6);
--- 天蓝色
Color.Sky = Color(0x87,0xce,0xeb);
--- 钢蓝色
Color.Steel = Color(0x46,0x82,0xb4);
--- 薰衣草蓝
Color.Lavender = Color(0xe6,0xe6,0xfa);
--- 午夜蓝
Color.Midnight = Color(0x19,0x19,0x70);

--- 紫红色
Color.Fuchsia = Color(255,0,255);
--- 紫色
Color.Purple = Color.Fuchsia + Color.Black;
--- 蓝紫色
Color.BlueViolet = Color(0x8a,0x2b,0xe2);
--- 靛蓝色
Color.Indigo = Color(0x4b,0x00,0x82);
--- 梅花紫
Color.Plum = Color(0xdd,0xa0,0xdd);
--- 淡紫色
Color.Violet = Color(0xee,0x82,0xee);
--- 兰紫色
Color.Orchid = Color(0xda,0x70,0xd6);

--- 橘色
Color.Orange = Color.Yellow + Color.Red;

cc.Color = Color;

cc.AnchorPoint = {
    Center = {x = 0.5,y = 0.5},
    LeftTop = {x = 0,y = 1},
    RightTop = {x = 1,y = 1},
    LeftBottom = {x = 0,y = 0},
    RightBottom = {x = 1,y = 0},
    Top = {x = 0.5,y = 1},
    Bottom = {x = 0.5,y = 0},
    Left = {x = 0,y = 0.5},
    Right = {x = 1,y = 0.5}
};

ccui.Widget.TextureResType = {
    LOCAL = 0,
    PLIST = 1,
};

ccui.Widget.TouchEventType = {
    BEGAN = 0,
    MOVED = 1,
    ENDED = 2,
    CANCELED = 3
};

ccui.CheckBox.EventType = {
    SELECTED = 0,
    UNSELECTED = 1,
};

ccui.RadioButton.EventType = {
    SELECTED = 0,
    UNSELECTED = 1
};

ccui.RadioButtonGroup.EventType = {
    SELECT_CHANGED = 0
};

ccui.Slider.EventType = {
    ON_PERCENTAGE_CHANGED = 0,
    ON_SLIDEBALL_DOWN = 1,
    ON_SLIDEBALL_UP = 2,
    ON_SLIDEBALL_CANCEL = 3
};

ccui.TextField.EventType = {
    ATTACH_WITH_IME = 0,
    DETACH_WITH_IME = 1,
    INSERT_TEXT = 2,
    DELETE_BACKWARD = 3,
};

ccui.LoadingBar.Direction = {
    LEFT = 0,
    RIGHT = 1
};

ccui.ScrollView.Direction = {
    NONE = 0,
    VERTICAL = 1,
    HORIZONTAL = 2,
    BOTH = 3
};

ccui.ScrollView.EventType = {
    SCROLL_TO_TOP = 0,
    SCROLL_TO_BOTTOM = 1,
    SCROLL_TO_LEFT = 2,
    SCROLL_TO_RIGHT = 3,
    SCROLLING = 4,
    BOUNCE_TOP = 5,
    BOUNCE_BOTTOM = 6,
    BOUNCE_LEFT = 7,
    BOUNCE_RIGHT = 8,
    CONTAINER_MOVED = 9,
    SCROLLING_BEGAN = 10,
    SCROLLING_ENDED = 11,
    AUTOSCROLL_ENDED = 12
};

ccui.ListView.MagneticType = {
    NONE = 0,
    CENTER = 1,
    BOTH_END = 2,
    LEFT = 3,
    RIGHT = 4,
    TOP = 5,
    BOTTOM = 6
};

ccui.ListView.EventType = {
    ON_SELECTED_ITEM_START = 0,
    ON_SELECTED_ITEM_END   = 1
};

ccui.PageView.EventType = {
    TURNING = 0
};

ccui.PageView.TouchDirection = {
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3
};

ccui.ListView.Gravity = {
    LEFT = 0,
    RIGHT = 1,
    CENTER_HORIZONTAL = 2,
    TOP = 3,
    BOTTOM = 4 ,
    CENTER_VERTICAL = 5
};

ccui.Text.Type = {
    SYSTEM = 0,
    TTF    = 1
};

ccui.LayoutComponent.HorizontalEdge = {
    None = 0,
    Left = 1,
    Right = 2,
    Center = 3
};

ccui.LayoutComponent.VerticalEdge = {
    None = 0,
    Bottom = 1,
    Top = 2,
    Center = 3
};

ccui.Scale9Sprite.State = {
    NORMAL = 0,
    GRAY = 1
};

ccui.Scale9Sprite.RenderingType = {
    SIMPLE = 0,
    SLICE = 1
};

ccui.Widget.BrightStyle = {
    NONE = -1,
    NORMAL = 0,
    HIGHLIGHT = 1
};

ccui.Widget.PositionType = {
    ABSOLUTE = 0,
    PERCENT = 1
};

ccui.Widget.SizeType = {
    ABSOLUTE = 0,
    PERCENT = 1
};

ccui.Layout.BackGroundColorType = {
    NONE = 0,
    SOLID = 1,
    GRADIENT = 2
};

ccui.Layout.ClippingType = {
    STENCIL = 0,
    SCISSOR = 1
};

ccui.Layout.Type = {
    ABSOLUTE = 0,
    VERTICAL = 1,
    HORIZONTAL = 2,
    RELATIVE = 3
};

ccui.LayoutComponent.HorizontalEdge = {
    None = 0,
    Left = 1,
    Right = 2,
    Center = 3
};

ccui.LayoutComponent.VerticalEdge = {
    None = 0,
    Bottom = 1,
    Top = 2,
    Center = 3
};

ccui.LayoutParameter.Type = {
    NONE = 0,
    LINEAR = 1,
    RELATIVE = 2
};

ccui.LinearLayoutParameter.LinearGravity = {
    NONE = 0,
    LEFT = 1,
    TOP = 2,
    RIGHT = 3,
    BOTTOM = 4,
    CENTER_VERTICAL = 5,
    CENTER_HORIZONTAL = 6
};

ccui.RelativeLayoutParameter.RelativeAlign = {
    NONE = 0,
    PARENT_TOP_LEFT = 1,
    PARENT_TOP_CENTER_HORIZONTAL = 2,
    PARENT_TOP_RIGHT = 3,
    PARENT_LEFT_CENTER_VERTICAL = 4,

    CENTER_IN_PARENT = 5,

    PARENT_RIGHT_CENTER_VERTICAL = 6,
    PARENT_LEFT_BOTTOM = 7,
    PARENT_BOTTOM_CENTER_HORIZONTAL = 8,
    PARENT_RIGHT_BOTTOM = 9,

    LOCATION_ABOVE_LEFTALIGN = 10,
    LOCATION_ABOVE_CENTER = 11,
    LOCATION_ABOVE_RIGHTALIGN = 12,
    LOCATION_LEFT_OF_TOPALIGN = 13,
    LOCATION_LEFT_OF_CENTER = 14,
    LOCATION_LEFT_OF_BOTTOMALIGN = 15,
    LOCATION_RIGHT_OF_TOPALIGN = 16,
    LOCATION_RIGHT_OF_CENTER = 17,
    LOCATION_RIGHT_OF_BOTTOMALIGN = 18,
    LOCATION_BELOW_LEFTALIGN = 19,
    LOCATION_BELOW_CENTER = 20,
    LOCATION_BELOW_RIGHTALIGN = 21
};

ccui.EditBox.InputMode = {
    ANY = 0,
    EMAIL_ADDRESS = 1,
    NUMERIC = 2,
    PHONE_NUMBER = 3,
    URL = 4,
    DECIMAL = 5,
    SINGLE_LINE = 6
};

ccui.EditBox.InputFlag = {
    PASSWORD = 0,
    SENSITIVE = 1,
    INITIAL_CAPS_WORD = 2,
    INITIAL_CAPS_SENTENCE = 3,
    INITIAL_CAPS_ALL_CHARACTERS = 4,
    LOWERCASE_ALL_CHARACTERS = 5
};

ccui.EditBox.KeyboardReturnType = {
    DEFAULT = 0,
    DONE = 1,
    SEND = 2,
    SEARCH = 3,
    GO = 4,
    NEXT = 5
};

ccui.RichText.WrapMode = {
    WRAP_PER_WORD = 0,
    WRAP_PER_CHAR = 1
};

ccui.RichText.HorizontalAlignment = {
    LEFT = 0,
    CENTER = 1,
    RIGHT = 2
};

ccui.TabControl.Dock = {
    TOP = 0,
    LEFT = 1,
    BOTTOM = 2,
    RIGHT = 3
};

ccui.VideoPlayer.EventType = {
    PLAYING = 0,
    PAUSED = 1,
    STOPPED = 2,
    COMPLETED = 3,
    ERROR = 4
};

ccui.VideoPlayer.StyleType = {
    DEFAULT = 0,
    NONE = 1
};

ccs.MovementEventType = {
    START = 0,
    COMPLETE = 1,
    LOOP_COMPLETE = 2
};

ccs.InnerActionType = {
    LoopAction = 0,
    NoLoopAction = 1,
    SingleFrame = 2
};

ccb.ProgramType = {
    POSITION_COLOR_LENGTH_TEXTURE = 0,
    POSITION_COLOR_TEXTURE_AS_POINTSIZE = 1,
    POSITION_COLOR = 2,
    POSITION_UCOLOR = 3,
    POSITION_TEXTURE = 4,
    POSITION_TEXTURE_COLOR = 5,
    POSITION_TEXTURE_COLOR_ALPHA_TEST = 6,
    LABEL_NORMAL = 7,
    LABLE_OUTLINE = 8,
    LABLE_DISTANCEFIELD_GLOW = 9,
    LABEL_DISTANCE_NORMAL = 10,

    LAYER_RADIA_GRADIENT = 11,

    ETC1 = 12,
    ETC1_GRAY = 13,
    GRAY_SCALE = 14,
    CAMERA_CLEAR = 15,

    TERRAIN_3D = 16,
    LINE_COLOR_3D = 17,
    SKYBOX_3D = 18,
    SKINPOSITION_TEXTURE_3D = 19,
    SKINPOSITION_NORMAL_TEXTURE_3D = 20,
    POSITION_NORMAL_TEXTURE_3D = 21,
    POSITION_NORMAL_3D = 22,
    POSITION_TEXTURE_3D = 23,
    POSITION_3D = 24,
    POSITION_BUMPEDNORMAL_TEXTURE_3D = 25,
    SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D = 26,
    PARTICLE_TEXTURE_3D = 27,
    PARTICLE_COLOR_3D = 28,

    CUSTOM_PROGRAM = 29
};