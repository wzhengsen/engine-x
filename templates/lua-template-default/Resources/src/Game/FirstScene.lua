local FirstScene = class(syx.BaseScene);

function FirstScene:ctor()
    syx.BaseScene.ctor(self)
    local img = ccui.ImageView.new("HelloWorld.png");
    img.Parent = self;
    img:Layout({
        px = 0.5,
        py = 0.5
    });
    img.TouchEnabled = true;
    img.ClickHandler = function(sender)
        sender.Grayed = not sender.Grayed;
    end;

    local lbl = syx.Label.new(65);
    lbl.Text = "Hello World!";
    lbl.Parent = self;
    lbl:Layout({
        px = 0.5,
        py = 0.3
    });
end

return FirstScene;