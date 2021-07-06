local FirstScene = class(cc.BaseScene);
local Label = require("Others.Label");

function FirstScene:ctor()
    cc.BaseScene.ctor(self)
    local img = ccui.ImageView.new("HelloWorld.png");
    img.Parent = self;
    img:Layout({
        px = 0.5,
        py = 0.5
    });
    img.TouchEnabled = true;
    img.ClickHandler = function(sender)
        cc.AppDelegate.Instance = nil;
    end;

    local lbl = Label.new("simkai.ttf",65);
    lbl.String = "Hello World!";
    lbl.Parent = self;
    lbl:Layout({
        px = 0.5,
        py = 0.3
    });
end

return FirstScene;