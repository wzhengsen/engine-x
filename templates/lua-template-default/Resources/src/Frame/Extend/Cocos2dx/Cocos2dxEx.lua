--[[
    Func:   cocos2dx Lua导出类的gtor stor及其一些Cocos2dx扩展功能函数等。
    Auth:   wzhengsen
    Data:   2020.02.16
]]
local cc = cc;
local ccui = ccui;
local type = type;

--[[
    Desc:   将table转换为一个在c++调用中可用的IntKeyMap值。
            将table["1"]映射为table[1]，且令table[1] = nil
    Param:  table
    Return: table
]]
function cc.MakeIntKeyMap(t)
    t["1"] = t[1];
    t[1] = nil;
    return t;
end

local Ref = cc.Ref;
Ref.gtor({
    ReferenceCount = Ref.getReferenceCount
});
Ref.stor({
});

local Node = cc.Node;
Node.gtor({
    LocalZ = Node.getLocalZOrder,
    GlobalZ = Node.getGlobalZOrder,
    ScaleX = Node.getScaleX,
    ScaleY = Node.getScaleY,
    Scale = Node.getScale,
    X = Node.getPositionX,
    Y = Node.getPositionY,
    XY = Node.getPositionXY,
    Width = Node.getContentWidth,
    Height = Node.getContentHeight,
    PositionNormalized = Node.getPositionNormalized,
    SkewX = Node.getSkewX,
    SkewY = Node.getSkewY,
    AnchorPoint = Node.getAnchorPoint,
    AnchorPointInPoints = Node.getAnchorPointInPoints,
    Size = Node.getContentSize,
    Visible = Node.isVisible,
    Rotation = Node.getRotation,
    RotationX = Node.getRotationSkewX,
    RotationY = Node.getRotationSkewY,
    Children = Node.getChildren,
    ChildrenCount = Node.getChildrenCount,
    Parent = Node.getParent,
    Tag = Node.getTag,
    Name = Node.getName,
    Running = Node.isRunning,
    Scene = Node.getScene,
    BoundingBox = Node.getBoundingBox,
    EventDispatcher = Node.getEventDispatcher,
    ActionManager = Node.getActionManager,
    NumberOfRunningActions = Node.getNumberOfRunningActions,
    Scheduler = Node.getScheduler,
    Opacity = Node.getOpacity,
    DisplayedOpacity = Node.getDisplayedOpacity,
    CascadeOpacityEnabled = Node.isCascadeOpacityEnabled,
    Color = Node.getColor,
    DisplayedColor = Node.getDisplayedColor,
    CascadeColorEnabled = Node.isCascadeColorEnabled,
    CameraMask = Node.getCameraMask,
    PhysicsBody = Node.getPhysicsBody,
    OpacityModifyRGB = Node.isOpacityModifyRGB,
    ProgramState = Node.getProgramState
});

Node.stor({
    LocalZ = Node.setLocalZOrder,
    GlobalZ = Node.setGlobalZOrder,
    ScaleX = Node.setScaleX,
    ScaleY = Node.setScaleY,
    Scale = Node.setScale,
    X = Node.setPositionX,
    Y = Node.setPositionY,
    XY = Node.setPosition,
    Width = Node.setContentWidth,
    Height = Node.setContentHeight,
    PositionNormalized = Node.setPositionNormalized,
    SkewX = Node.setSkewX,
    SkewY = Node.setSkewY,
    AnchorPoint = Node.setAnchorPoint,
    Size = Node.setContentSize,
    Visible = Node.setVisible,
    Rotation = Node.setRotation,
    RotationX = Node.setRotationSkewX,
    RotationY = Node.setRotationSkewY,
    Parent = function(self,p)
        if class.IsNull(p) then
            Node.removeFromParent(self);
        else
            local op = Node.getParent(self);
            if op then
                if op ~= p then
                    self:retain();
                    self:removeFromParent(false);
                    p:addChild(self);
                    self:release();
                end
            else
                p:addChild(self);
            end
        end
    end,
    Tag = Node.setTag,
    Name = Node.setName,
    EventDispatcher = Node.setEventDispatcher,
    ActionManager = Node.setActionManager,
    Scheduler = Node.setScheduler,
    Opacity = Node.setOpacity,
    CascadeOpacityEnabled = Node.setCascadeOpacityEnabled,
    Color = Node.setColor,
    CascadeColorEnabled = Node.setCascadeColorEnabled,
    CameraMask = Node.setCameraMask,
    PhysicsBody = Node.setPhysicsBody,
    OpacityModifyRGB = Node.setOpacityModifyRGB,
    ProgramState = Node.setProgramState
});

local Action = cc.Action;
Action.gtor({
    Done = Action.isDone,
    Target = Action.getTarget,
    OriginalTarget = Action.getOriginalTarget,
    Tag = Action.getTag,
    Flags = Action.getFlags
});
Action.stor({
    Target = Action.getTarget,
    OriginalTarget = Action.setOriginalTarget,
    Tag = Action.setTag,
    Flags = Action.setFlags
});

local FiniteTimeAction = cc.FiniteTimeAction;
FiniteTimeAction.gtor({
    Duration = FiniteTimeAction.getDuration
});
FiniteTimeAction.stor({
    Duration = FiniteTimeAction.setDuration
});

local Speed = cc.Speed;
Speed.gtor({
    Speed = Speed.getSpeed,
    InnerAction = Speed.getInnerAction
});
Speed.stor({
    Speed = Speed.setSpeed,
    InnerAction = Speed.setInnerAction
});

local Follow = cc.Follow;
Follow.gtor({
    BoundarySet = Follow.isBoundarySet
});
Follow.stor({
    BoundarySet = Follow.setBoundarySet
});

local ActionInterval = cc.ActionInterval;
ActionInterval.gtor({
    Elapsed = ActionInterval.getElapsed,
    AmplitudeRate = ActionInterval.getAmplitudeRate
});
ActionInterval.stor({
    AmplitudeRate = ActionInterval.setAmplitudeRate
});

local Animate = cc.Animate;
Animate.gtor({
    Animation = Animate.getAnimation,
    CurrentFrameIndex = Animate.getCurrentFrameIndex
});
Animate.stor({
    Animation = Animate.setAnimation
});

local TargetedAction = cc.TargetedAction;
TargetedAction.gtor({
    ForcedTarget = TargetedAction.getForcedTarget
});
TargetedAction.stor({
    ForcedTarget = TargetedAction.setForcedTarget
});

local EaseRateAction = cc.EaseRateAction;
EaseRateAction.gtor({
    Rate = EaseRateAction.getRate
});
EaseRateAction.stor({
    Rate = EaseRateAction.setRate
});

local EaseElastic = cc.EaseElastic;
EaseElastic.gtor({
    Period = EaseElastic.getPeriod
});
EaseElastic.stor({
    Period = EaseElastic.setPeriod
});

local GridAction = cc.GridAction;
GridAction.gtor({
    Grid = GridAction.getGrid
});

local Waves3D = cc.Waves3D;
Waves3D.gtor({
    Amplitude = Waves3D.getAmplitude,
    AmplitudeRate = Waves3D.getAmplitudeRate
});
Waves3D.stor({
    Amplitude = Waves3D.setAmplitude,
    AmplitudeRate = Waves3D.setAmplitudeRate
});

local Lens3D = cc.Lens3D;
Lens3D.gtor({
    LensEffect = Lens3D.getLensEffect,
    Position = Lens3D.getPosition
});
Lens3D.stor({
    LensEffect = Lens3D.setLensEffect,
    Concave = Lens3D.setConcave,
    Position = Lens3D.setPosition
});

local Ripple3D = cc.Ripple3D;
Ripple3D.gtor({
    Amplitude = Ripple3D.getAmplitude,
    AmplitudeRate = Ripple3D.getAmplitudeRate,
    Position = Ripple3D.getPosition
});
Ripple3D.stor({
    Amplitude = Ripple3D.setAmplitude,
    AmplitudeRate = Ripple3D.setAmplitudeRate,
    Position = Ripple3D.setPosition
});

local Liquid = cc.Liquid;
Liquid.gtor({
    Amplitude = Liquid.getAmplitude,
    AmplitudeRate = Liquid.getAmplitudeRate
});
Liquid.stor({
    Amplitude = Liquid.setAmplitude,
    AmplitudeRate = Liquid.setAmplitudeRate
});

local Waves = cc.Waves;
Waves.gtor({
    Amplitude = Waves.getAmplitude,
    AmplitudeRate = Waves.getAmplitudeRate
});
Waves.stor({
    Amplitude = Waves.setAmplitude,
    AmplitudeRate = Waves.setAmplitudeRate
});

local Twirl = cc.Ripple3D;
Twirl.gtor({
    Amplitude = Twirl.getAmplitude,
    AmplitudeRate = Twirl.getAmplitudeRate,
    Position = Twirl.getPosition
});
Twirl.stor({
    Amplitude = Twirl.setAmplitude,
    AmplitudeRate = Twirl.setAmplitudeRate,
    Position = Twirl.setPosition
});

local WavesTiles3D = cc.WavesTiles3D;
WavesTiles3D.gtor({
    Amplitude = WavesTiles3D.getAmplitude,
    AmplitudeRate = WavesTiles3D.getAmplitudeRate
});
WavesTiles3D.stor({
    Amplitude = WavesTiles3D.setAmplitude,
    AmplitudeRate = WavesTiles3D.setAmplitudeRate
});

local JumpTiles3D = cc.WavesTiles3D;
JumpTiles3D.gtor({
    Amplitude = JumpTiles3D.getAmplitude,
    AmplitudeRate = JumpTiles3D.getAmplitudeRate
});
JumpTiles3D.stor({
    Amplitude = JumpTiles3D.setAmplitude,
    AmplitudeRate = JumpTiles3D.setAmplitudeRate
});

local SpriteFrame = cc.SpriteFrame;
SpriteFrame.gtor({
    RectInPixels = SpriteFrame.getRectInPixels,
    Rotated = SpriteFrame.isRotated,
    Rect = SpriteFrame.getRect,
    CenterRect = SpriteFrame.getCenterRect,
    HasCenterRect = SpriteFrame.hasCenterRect,
    OffsetInPixels = SpriteFrame.getOffsetInPixels,
    OriginalSizeInPixels = SpriteFrame.getOriginalSizeInPixels,
    OriginalSize = SpriteFrame.getOriginalSize,
    Texture = SpriteFrame.getTexture,
    Offset = SpriteFrame.getOffset,
    AnchorPoint = SpriteFrame.getAnchorPoint,
    HasAnchorPoint = SpriteFrame.hasAnchorPoint,
});
SpriteFrame.stor({
    RectInPixels = SpriteFrame.setRectInPixels,
    setRotated = SpriteFrame.setRotated,
    Rect = SpriteFrame.setRect,
    CenterRectInPixels = SpriteFrame.setCenterRectInPixels,
    OffsetInPixels = SpriteFrame.setOffsetInPixels,
    OriginalSizeInPixels = SpriteFrame.setOriginalSizeInPixels,
    OriginalSize = SpriteFrame.setOriginalSize,
    Texture = SpriteFrame.setTexture,
    Offset = SpriteFrame.setOffset,
    AnchorPoint = SpriteFrame.setAnchorPoint,
});

local AnimationFrame = cc.AnimationFrame;
AnimationFrame.gtor({
    SpriteFrame = AnimationFrame.getSpriteFrame,
    DelayUnits = AnimationFrame.getDelayUnits,
    UserInfo = AnimationFrame.getUserInfo
});
AnimationFrame.stor({
    SpriteFrame = AnimationFrame.setSpriteFrame,
    DelayUnits = AnimationFrame.setDelayUnits,
    UserInfo = AnimationFrame.setUserInfo
});

local Animation = cc.Animation;
Animation.gtor({
    TotalDelayUnits = Animation.getTotalDelayUnits,
    DelayPerUnit = Animation.getDelayPerUnit,
    Duration = Animation.getDuration,
    Frames = Animation.getFrames,
    RestoreOriginalFrame = Animation.getRestoreOriginalFrame,
    Loops = Animation.getLoops
});
Animation.stor({
    DelayPerUnit = Animation.setDelayPerUnit,
    Frames = Animation.setFrames,
    RestoreOriginalFrame = Animation.setRestoreOriginalFrame,
    Loops = Animation.setLoops
});

local AtlasNode = cc.AtlasNode;
AtlasNode.gtor({
    TextureAtlas = AtlasNode.getTextureAtlas,
    QuadsToDraw = AtlasNode.getQuadsToDraw,
    Texture = AtlasNode.getTexture,
    BlendFunc = AtlasNode.getBlendFunc
});
AtlasNode.stor({
    TextureAtlas = AtlasNode.setTextureAtlas,
    QuadsToDraw = AtlasNode.setQuadsToDraw,
    Texture = AtlasNode.setTexture,
    BlendFunc = AtlasNode.setBlendFunc
});

local Camera = cc.Camera;
Camera.gtor({
    Type = Camera.getType,
    CameraFlag = Camera.getCameraFlag,
    ProjectionMatrix = Camera.getProjectionMatrix,
    ViewMatrix = Camera.getViewMatrix,
    ViewProjectionMatrix = Camera.getViewProjectionMatrix,
    Depth = Camera.getDepth,
    RenderOrder = Camera.getRenderOrder,
    FarPlane = Camera.getFarPlane,
    NearPlane = Camera.getNearPlane,
    ViewProjectionUpdated = Camera.isViewProjectionUpdated,
    BackgroundBrush = Camera.getBackgroundBrush,
    BrushValid = Camera.isBrushValid
});
Camera.stor({
    CameraFlag = Camera.setCameraFlag,
    Depth = Camera.setDepth,
    FrameBufferObject = Camera.setFrameBufferObject,
    Viewport = Camera.setViewport,
    BackgroundBrush = Camera.setBackgroundBrush,
    Scene = Camera.setScene,
    AdditionalProjection = Camera.setAdditionalProjection
});

local CameraBackgroundBrush = cc.CameraBackgroundBrush;
CameraBackgroundBrush.gtor({
    BrushType = CameraBackgroundBrush.getBrushType,
    Valid = CameraBackgroundBrush.isValid
});
CameraBackgroundBrush.stor({
});

local CameraBackgroundDepthBrush = cc.CameraBackgroundDepthBrush;
CameraBackgroundDepthBrush.gtor({
});
CameraBackgroundDepthBrush.stor({
    Depth = CameraBackgroundDepthBrush.setDepth
});

local CameraBackgroundColorBrush = cc.CameraBackgroundColorBrush;
CameraBackgroundColorBrush.gtor({
});
CameraBackgroundColorBrush.stor({
    Color = CameraBackgroundColorBrush.setColor
});

local CameraBackgroundSkyBoxBrush = cc.CameraBackgroundSkyBoxBrush;
CameraBackgroundSkyBoxBrush.gtor({
});
CameraBackgroundSkyBoxBrush.stor({
    Texture = CameraBackgroundSkyBoxBrush.setTexture
});

local ClippingNode = cc.ClippingNode;
ClippingNode.gtor({
    Stencil = ClippingNode.getStencil,
    Content = ClippingNode.hasContent,
    AlphaThreshold = ClippingNode.getAlphaThreshold,
    Inverted = ClippingNode.isInverted
});
ClippingNode.stor({
    Stencil = ClippingNode.setStencil,
    AlphaThreshold = ClippingNode.setAlphaThreshold,
    Inverted = ClippingNode.setInverted
});

local ClippingRectangleNode = cc.ClippingRectangleNode;
ClippingRectangleNode.gtor({
    ClippingRegion = ClippingRectangleNode.getClippingRegion,
    ClippingEnabled = ClippingRectangleNode.isClippingEnabled
});
ClippingRectangleNode.stor({
    ClippingRegion = ClippingRectangleNode.setClippingRegion,
    ClippingEnabled = ClippingRectangleNode.setClippingEnabled
});

local Component = cc.Component;
Component.gtor({
    Enabled = Component.isEnabled,
    Name = Component.getName,
    Owner = Component.getOwner
});
Component.stor({
    Enabled = Component.setEnabled,
    Name = Component.setName,
    Owner = Component.setOwner
});

local DrawNode = cc.DrawNode;
DrawNode.gtor({
    BlendFunc = DrawNode.getBlendFunc,
    LineWidth = DrawNode.getLineWidth,
    Isolated = DrawNode.isIsolated
});
DrawNode.stor({
    BlendFunc = DrawNode.setBlendFunc,
    LineWidth = DrawNode.setLineWidth,
    Isolated = DrawNode.setIsolated
});

-- cc.FastTMXLayer
local FastTMXLayer = cc.FastTMXLayer;
FastTMXLayer.gtor({
    LayerName = FastTMXLayer.getLayerName,
    LayerSize = FastTMXLayer.getLayerSize,
    MapTileSize = FastTMXLayer.getMapTileSize,
    TileSet = FastTMXLayer.getTileSet,
    LayerOrientation = FastTMXLayer.getLayerOrientation,
    Properties = FastTMXLayer.getProperties
});
FastTMXLayer.stor({
    LayerName = FastTMXLayer.setLayerName,
    LayerSize = FastTMXLayer.setLayerSize,
    MapTileSize = FastTMXLayer.setMapTileSize,
    TileSet = FastTMXLayer.setTileSet,
    LayerOrientation = FastTMXLayer.setLayerOrientation,
    Properties = FastTMXLayer.setProperties
});

-- cc.FastTMXLayer
FastTMXLayer = cc.FastTMXLayer;
FastTMXLayer.gtor({
    LayerName = FastTMXLayer.getLayerName,
    LayerSize = FastTMXLayer.getLayerSize,
    MapTileSize = FastTMXLayer.getMapTileSize,
    TileSet = FastTMXLayer.getTileSet,
    LayerOrientation = FastTMXLayer.getLayerOrientation,
    Properties = FastTMXLayer.getProperties
});
FastTMXLayer.stor({
    LayerName = FastTMXLayer.setLayerName,
    LayerSize = FastTMXLayer.setLayerSize,
    MapTileSize = FastTMXLayer.setMapTileSize,
    TileSet = FastTMXLayer.setTileSet,
    LayerOrientation = FastTMXLayer.setLayerOrientation,
    Properties = FastTMXLayer.setProperties
});


-- cc.FastTMXTiledMap
local FastTMXTiledMap = cc.FastTMXTiledMap;
FastTMXTiledMap.gtor({
    MapSize = FastTMXTiledMap.getMapSize,
    TileSize = FastTMXTiledMap.getTileSize,
    MapOrientation = FastTMXTiledMap.getMapOrientation,
    ObjectGroups = FastTMXTiledMap.getObjectGroups,
    Properties = FastTMXTiledMap.getProperties
});
FastTMXTiledMap.stor({
    MapSize = FastTMXTiledMap.setMapSize,
    TileSize = FastTMXTiledMap.setTileSize,
    MapOrientation = FastTMXTiledMap.setMapOrientation,
    ObjectGroups = FastTMXTiledMap.setObjectGroups,
    Properties = FastTMXTiledMap.setProperties
});

-- cc.FastTMXTiledMap
FastTMXTiledMap = cc.FastTMXTiledMap;
FastTMXTiledMap.gtor({
    MapSize = FastTMXTiledMap.getMapSize,
    TileSize = FastTMXTiledMap.getTileSize,
    MapOrientation = FastTMXTiledMap.getMapOrientation,
    ObjectGroups = FastTMXTiledMap.getObjectGroups,
    Properties = FastTMXTiledMap.getProperties
});
FastTMXTiledMap.stor({
    MapSize = FastTMXTiledMap.setMapSize,
    TileSize = FastTMXTiledMap.setTileSize,
    MapOrientation = FastTMXTiledMap.setMapOrientation,
    ObjectGroups = FastTMXTiledMap.setObjectGroups,
    Properties = FastTMXTiledMap.setProperties
});

local TMXObjectGroup = cc.TMXObjectGroup;
TMXObjectGroup.gtor({
    GroupName = TMXObjectGroup.getGroupName,
    PositionOffset = TMXObjectGroup.getPositionOffset,
    Properties = TMXObjectGroup.getProperties,
    Objects = TMXObjectGroup.getObjects,
});
TMXObjectGroup.stor({
    GroupName = TMXObjectGroup.setGroupName,
    PositionOffset = TMXObjectGroup.setPositionOffset,
    Properties = TMXObjectGroup.setProperties,
    Objects = TMXObjectGroup.setObjects,
});

local TMXLayerInfo = cc.TMXLayerInfo;
TMXLayerInfo.gtor({
    Properties = TMXLayerInfo.getProperties
});
TMXLayerInfo.stor({
    Properties = TMXLayerInfo.setProperties
});

local TMXMapInfo = cc.TMXMapInfo;
TMXMapInfo.gtor({
    TileProperties = TMXMapInfo.getTileProperties,
    Orientation = TMXMapInfo.getOrientation,
    StaggerAxis = TMXMapInfo.getStaggerAxis,
    StaggerIndex = TMXMapInfo.getStaggerIndex,
    HexSideLength = TMXMapInfo.getHexSideLength,
    MapSize = TMXMapInfo.getMapSize,
    TileSize = TMXMapInfo.getTileSize,
    Layers = TMXMapInfo.getLayers,
    Tilesets = TMXMapInfo.getTilesets,
    ObjectGroups = TMXMapInfo.getObjectGroups,
    ParentElement = TMXMapInfo.getParentElement,
    ParentGID = TMXMapInfo.getParentGID,
    LayerAttribs = TMXMapInfo.getLayerAttribs,
    StoringCharacters = TMXMapInfo.isStoringCharacters,
    Properties = TMXMapInfo.getProperties
});
TMXMapInfo.stor({
    TileProperties = TMXMapInfo.setTileProperties,
    Orientation = TMXMapInfo.setOrientation,
    StaggerAxis = TMXMapInfo.setStaggerAxis,
    StaggerIndex = TMXMapInfo.setStaggerIndex,
    HexSideLength = TMXMapInfo.setHexSideLength,
    MapSize = TMXMapInfo.setMapSize,
    TileSize = TMXMapInfo.setTileSize,
    Layers = TMXMapInfo.setLayers,
    Tilesets = TMXMapInfo.setTilesets,
    ObjectGroups = TMXMapInfo.setObjectGroups,
    ParentElement = TMXMapInfo.setParentElement,
    ParentGID = TMXMapInfo.setParentGID,
    LayerAttribs = TMXMapInfo.setLayerAttribs,
    StoringCharacters = TMXMapInfo.setStoringCharacters,
    Properties = TMXMapInfo.setProperties
});

local GridBase = cc.GridBase;
GridBase.gtor({
    Active = GridBase.isActive,
    ReuseGrid = GridBase.getReuseGrid,
    GridSize = GridBase.getGridSize,
    Step = GridBase.getStep,
    TextureFlipped = GridBase.isTextureFlipped,
    GridRect = GridBase.getGridRect
});
GridBase.stor({
    Active = GridBase.setActive,
    ReuseGrid = GridBase.setReuseGrid,
    GridSize = GridBase.setGridSize,
    Step = GridBase.setStep,
    TextureFlipped = GridBase.setTextureFlipped,
    GridRect = GridBase.setGridRect
});

local Grid3D = cc.Grid3D;
Grid3D.gtor({
    NeedDepthTestForBlit = Grid3D.getNeedDepthTestForBlit
});
Grid3D.stor({
    NeedDepthTestForBlit = Grid3D.setNeedDepthTestForBlit
});

local Label = cc.Label;
Label.gtor({
    TTFConfig = Label.getTTFConfig,
    BMFontFilePath = Label.getBMFontFilePath,
    SystemFontName = Label.getSystemFontName,
    SystemFontSize = Label.getSystemFontSize,
    String = Label.getString,
    Text = Label.getString,
    StringNumLines = Label.getStringNumLines,
    TextNumLines = Label.getStringNumLines,
    StringLength = Label.getStringLength,
    TextLength = Label.getStringLength,
    TextColor = Label.getTextColor,
    ShadowEnabled = Label.isShadowEnabled,
    ShadowOffset = Label.getShadowOffset,
    ShadowBlurRadius = Label.getShadowBlurRadius,
    ShadowColor = Label.getShadowColor,
    OutlineSize = Label.getOutlineSize,
    LabelEffectType = Label.getLabelEffectType,
    EffectColor = Label.getEffectColor,
    TextAlignment = Label.getTextAlignment,
    HorizontalAlignment = Label.getHorizontalAlignment,
    VerticalAlignment = Label.getVerticalAlignment,
    MaxLineWidth = Label.getMaxLineWidth,
    BMFontSize = Label.getBMFontSize,
    Wrap = Label.isWrapEnabled,
    Overflow = Label.getOverflow,
    LabelWidth = Label.getWidth,
    LabelHeight = Label.getHeight,
    Dimensions = Label.getDimensions,
    ClipMarginEnabled = Label.isClipMarginEnabled,
    LineHeight = Label.getLineHeight,
    LineSpacing = Label.getLineSpacing,
    LabelType = Label.getLabelType,
    RenderingFontSize = Label.getRenderingFontSize,
    AdditionalKerning = Label.getAdditionalKerning,
    BlendFunc = Label.getBlendFunc
});
Label.stor({
    TTFConfig = Label.setTTFConfig,
    SystemFontName = Label.setSystemFontName,
    SystemFontSize = Label.setSystemFontSize,
    String = Label.setString,
    Text = Label.setString,
    TextColor = Label.setTextColor,
    Italics = function(self,b)
        if b then
            Label.enableItalics(self);
        else
            Label.disableEffect(self,cc.LabelEffect.ITALICS);
        end
    end,
    Bold = function(self,b)
        if b then
            Label.enableBold(self);
        else
            Label.disableEffect(self,cc.LabelEffect.BLOD);
        end
    end,
    Underline = function(self,b)
        if b then
            Label.enableUnderline(self);
        else
            Label.disableEffect(self,cc.LabelEffect.UNDERLINE);
        end
    end,
    Strikethrough = function(self,b)
        if b then
            Label.enableStrikethrough(self);
        else
            Label.disableEffect(self,cc.LabelEffect.STRIKETHROUGH);
        end
    end,
    Shadow = function(self,bc)
        if bc then
            if "table" == type(bc) then
                Label.enableShadow(self,bc);
            else
                Label.enableShadow(self);
            end
        else
            Label.disableEffect(self,cc.LabelEffect.SHADOW);
        end
    end,
    Outline = function(self,bc)
        if bc then
            if "table" == type(bc) then
                Label.enableOutline(self,bc);
            else
                Label.enableOutline(self);
            end
        else
            Label.disableEffect(self,cc.LabelEffect.OUTLINE);
        end
    end,
    Glow = function(self,bc)
        if bc then
            if "table" == type(bc) then
                Label.enableGlow(self,bc);
            else
                Label.enableGlow(self);
            end
        else
            Label.disableEffect(self,cc.LabelEffect.GLOW);
        end
    end,
    Alignment = Label.setAlignment,
    HorizontalAlignment = Label.setHorizontalAlignment,
    VerticalAlignment = Label.setVerticalAlignment,
    LineBreakWithoutSpace = Label.setLineBreakWithoutSpace,
    MaxLineWidth = Label.setMaxLineWidth,
    BMFontSize = Label.setBMFontSize,
    Wrap = Label.enableWrap,
    Overflow = Label.setOverflow,
    LabelWidth = Label.setWidth,
    LabelHeight = Label.setHeight,
    Dimensions = Label.setDimensions,
    ClipMarginEnabled = Label.setClipMarginEnabled,
    LineHeight = Label.setLineHeight,
    LineSpacing = Label.setLineSpacing,
    AdditionalKerning = Label.setAdditionalKerning,
    BlendFunc = Label.setBlendFunc
});

local LabelAtlas = cc.LabelAtlas;
LabelAtlas.gtor({
    String = LabelAtlas.getString,
    Text = LabelAtlas.getString
});
LabelAtlas.stor({
    String = LabelAtlas.setString,
    Text = LabelAtlas.setString
});

local LayerColor = cc.LayerColor;
LayerColor.gtor({
    BlendFunc = LayerColor.getBlendFunc
});
LayerColor.stor({
    BlendFunc = LayerColor.setBlendFunc
});

local LayerGradient = cc.LayerGradient;
LayerGradient.gtor({
    CompressedInterpolation = LayerGradient.isCompressedInterpolation,
    StartColor = LayerGradient.getStartColor,
    EndColor = LayerGradient.getEndColor,
    StartOpacity = LayerGradient.getStartOpacity,
    EndOpacity = LayerGradient.getEndOpacity,
    Vector = LayerGradient.getVector
});
LayerGradient.stor({
    CompressedInterpolation = LayerGradient.setCompressedInterpolation,
    StartColor = LayerGradient.setStartColor,
    EndColor = LayerGradient.setEndColor,
    StartOpacity = LayerGradient.setStartOpacity,
    EndOpacity = LayerGradient.setEndOpacity,
    Vector = LayerGradient.setVector
});

local LayerRadialGradient = cc.LayerRadialGradient;
LayerRadialGradient.gtor({
    BlendFunc = LayerRadialGradient.getBlendFunc,
    StartColor = LayerRadialGradient.getStartColor,
    EndColor = LayerRadialGradient.getEndColor,
    StartOpacity = LayerRadialGradient.getStartOpacity,
    EndOpacity = LayerRadialGradient.getEndOpacity,
    Radius = LayerRadialGradient.getRadius,
    Center = LayerRadialGradient.getCenter,
    Expand = LayerRadialGradient.getExpand
});
LayerRadialGradient.stor({
    BlendFunc = LayerRadialGradient.setBlendFunc,
    StartColor = LayerRadialGradient.setStartColor,
    EndColor = LayerRadialGradient.setEndColor,
    StartOpacity = LayerRadialGradient.setStartOpacity,
    EndOpacity = LayerRadialGradient.setEndOpacity,
    Radius = LayerRadialGradient.setRadius,
    Center = LayerRadialGradient.setCenter,
    Expand = LayerRadialGradient.setExpand
});

local Menu = cc.Menu;
Menu.gtor({
    Enabled = Menu.isEnabled
});
Menu.stor({
    Enabled = Menu.setEnabled
});

local MenuItem = cc.MenuItem;
MenuItem.gtor({
    Enabled = MenuItem.isEnabled,
    Selected = MenuItem.isSelected
});
MenuItem.stor({
    Enabled = MenuItem.setEnabled,
    Selected = function(self,b)
        if b then
            MenuItem.selected(self);
        else
            MenuItem.unselected(self);
        end
    end
});

local MenuItemLabel = cc.MenuItemLabel;
MenuItemLabel.gtor({
    String = MenuItemLabel.getString,
    Text = MenuItemLabel.getString,
    DisabledColor = MenuItemLabel.getDisabledColor,
    Label = MenuItemLabel.getLabel
});
MenuItemLabel.stor({
    String = MenuItemLabel.setString,
    Text = MenuItemLabel.setString,
    DisabledColor = MenuItemLabel.setDisabledColor,
    Label = MenuItemLabel.setLabel
});

local MenuItemFont = cc.MenuItemFont;
MenuItemFont.gtor({
    FontSize = MenuItemFont.getFontSizeObj,
    FontName = MenuItemFont.getFontNameObj
});
MenuItemLabel.stor({
    FontSize = MenuItemFont.setFontSizeObj,
    FontName = MenuItemFont.setFontNameObj
});

local MenuItemSprite = cc.MenuItemSprite;
MenuItemSprite.gtor({
    NormalImage = MenuItemSprite.getNormalImage,
    SelectedImage = MenuItemSprite.getSelectedImage,
    DisabledImage = MenuItemSprite.getDisabledImage
});
MenuItemSprite.stor({
    NormalImage = MenuItemSprite.setNormalImage,
    SelectedImage = MenuItemSprite.setSelectedImage,
    DisabledImage = MenuItemSprite.setDisabledImage
});

local MenuItemImage = cc.MenuItemImage;
MenuItemImage.gtor({
});
MenuItemImage.stor({
    NormalSpriteFrame = MenuItemImage.setNormalSpriteFrame,
    SelectedSpriteFrame = MenuItemImage.setSelectedSpriteFrame,
    DisabledSpriteFrame = MenuItemImage.setDisabledSpriteFrame
});

local MenuItemToggle = cc.MenuItemToggle;
MenuItemToggle.gtor({
    SelectedItem = MenuItemSprite.getSelectedItem,
    SelectedIndex = MenuItemSprite.getSelectedIndex,
    SubItems = MenuItemSprite.getSubItems
});
MenuItemToggle.stor({
    SelectedIndex = MenuItemSprite.setSelectedIndex,
    SubItems = MenuItemSprite.setSubItems
});

local MotionStreak = cc.MotionStreak;
MotionStreak.gtor({
    FastMode = MotionStreak.isFastMode,
    Stroke = MotionStreak.getStroke,
    StartingPositionInitialized = MotionStreak.isStartingPositionInitialized,
    Texture = MotionStreak.getTexture,
    BlendFunc = MotionStreak.getBlendFunc
});
MotionStreak.stor({
    FastMode = MotionStreak.setFastMode,
    Stroke = MotionStreak.setStroke,
    StartingPositionInitialized = MotionStreak.setStartingPositionInitialized,
    Texture = MotionStreak.setTexture,
    BlendFunc = MotionStreak.setBlendFunc
});

local NodeGrid = cc.NodeGrid;
NodeGrid.gtor({
    Grid = NodeGrid.getGrid,
    GridRect = NodeGrid.getGridRect
});
NodeGrid.stor({
    Grid = NodeGrid.setGrid,
    Target = NodeGrid.setTarget,
    GridRect = NodeGrid.setGridRect
});

local ParticleBatchNode = cc.ParticleBatchNode;
ParticleBatchNode.gtor({
    TextureAtlas = ParticleBatchNode.getTextureAtlas,
    BlendFunc = ParticleBatchNode.getBlendFunc,
    Texture = ParticleBatchNode.getTexture
});
ParticleBatchNode.stor({
    TextureAtlas = ParticleBatchNode.setTextureAtlas,
    BlendFunc = ParticleBatchNode.setBlendFunc,
    Texture = ParticleBatchNode.setTexture
});

local ParticleSystem = cc.ParticleSystem;
ParticleSystem.gtor({
    Full = ParticleSystem.isFull,
    AutoRemoveOnFinish = ParticleSystem.isAutoRemoveOnFinish,
    Gravity = ParticleSystem.getGravity,
    Speed = ParticleSystem.getSpeed,
    SpeedVar = ParticleSystem.getSpeedVar,
    TangentialAccel = ParticleSystem.getTangentialAccel,
    TangentialAccelVar = ParticleSystem.getTangentialAccelVar,
    RadialAccel = ParticleSystem.getRadialAccel,
    RadialAccelVar = ParticleSystem.getRadialAccelVar,
    RotationIsDir = ParticleSystem.getRotationIsDir,
    StartRadius = ParticleSystem.getStartRadius,
    StartRadiusVar = ParticleSystem.getStartRadiusVar,
    EndRadius = ParticleSystem.getEndRadius,
    EndRadiusVar = ParticleSystem.getEndRadiusVar,
    RotatePerSecond = ParticleSystem.getRotatePerSecond,
    RotatePerSecondVar = ParticleSystem.getRotatePerSecondVar,
    Active = ParticleSystem.isActive,
    BlendAdditive = ParticleSystem.isBlendAdditive,
    BatchNode = ParticleSystem.getBatchNode,
    AtlasIndex = ParticleSystem.getAtlasIndex,
    ParticleCount = ParticleSystem.getParticleCount,
    Duration = ParticleSystem.getDuration,
    SourcePosition = ParticleSystem.getSourcePosition,
    PosVar = ParticleSystem.getPosVar,
    Life = ParticleSystem.getLife,
    LifeVar = ParticleSystem.getLifeVar,
    Angle = ParticleSystem.getAngle,
    AngleVar = ParticleSystem.getAngleVar,
    EmitterMode = ParticleSystem.getEmitterMode,
    StartSize = ParticleSystem.getStartSize,
    StartSizeVar = ParticleSystem.getStartSizeVar,
    EndSize = ParticleSystem.getEndSize,
    EndSizeVar = ParticleSystem.getEndSizeVar,
    StartColor = ParticleSystem.getStartColor,
    StartColorVar = ParticleSystem.getStartColorVar,
    EndColor = ParticleSystem.getEndColor,
    EndColorVar = ParticleSystem.getEndColorVar,
    StartSpin = ParticleSystem.getStartSpin,
    StartSpinVar = ParticleSystem.getStartSpinVar,
    EndSpin = ParticleSystem.getEndSpin,
    EndSpinVar = ParticleSystem.getEndSpinVar,
    EmissionRate = ParticleSystem.getEmissionRate,
    TotalParticles = ParticleSystem.getTotalParticles,
    PositionType = ParticleSystem.getPositionType,
    Texture = ParticleSystem.getTexture,
    BlendFunc = ParticleSystem.getBlendFunc,
    ResourceFile = ParticleSystem.getResourceFile
});
ParticleSystem.stor({
    AutoRemoveOnFinish = ParticleSystem.setAutoRemoveOnFinish,
    Gravity = ParticleSystem.setGravity,
    Speed = ParticleSystem.setSpeed,
    SpeedVar = ParticleSystem.setSpeedVar,
    TangentialAccel = ParticleSystem.setTangentialAccel,
    TangentialAccelVar = ParticleSystem.setTangentialAccelVar,
    RadialAccel = ParticleSystem.setRadialAccel,
    RadialAccelVar = ParticleSystem.setRadialAccelVar,
    RotationIsDir = ParticleSystem.setRotationIsDir,
    StartRadius = ParticleSystem.setStartRadius,
    StartRadiusVar = ParticleSystem.setStartRadiusVar,
    EndRadius = ParticleSystem.setEndRadius,
    EndRadiusVar = ParticleSystem.setEndRadiusVar,
    RotatePerSecond = ParticleSystem.setRotatePerSecond,
    RotatePerSecondVar = ParticleSystem.setRotatePerSecondVar,
    BlendAdditive = ParticleSystem.setBlendAdditive,
    BatchNode = ParticleSystem.setBatchNode,
    AtlasIndex = ParticleSystem.setAtlasIndex,
    Duration = ParticleSystem.setDuration,
    SourcePosition = ParticleSystem.setSourcePosition,
    PosVar = ParticleSystem.setPosVar,
    Life = ParticleSystem.setLife,
    LifeVar = ParticleSystem.setLifeVar,
    Angle = ParticleSystem.setAngle,
    AngleVar = ParticleSystem.setAngleVar,
    EmitterMode = ParticleSystem.setEmitterMode,
    StartSize = ParticleSystem.setStartSize,
    StartSizeVar = ParticleSystem.setStartSizeVar,
    EndSize = ParticleSystem.setEndSize,
    EndSizeVar = ParticleSystem.setEndSizeVar,
    StartColor = ParticleSystem.setStartColor,
    StartColorVar = ParticleSystem.setStartColorVar,
    EndColor = ParticleSystem.setEndColor,
    EndColorVar = ParticleSystem.setEndColorVar,
    StartSpin = ParticleSystem.setStartSpin,
    StartSpinVar = ParticleSystem.setStartSpinVar,
    EndSpin = ParticleSystem.setEndSpin,
    EndSpinVar = ParticleSystem.setEndSpinVar,
    EmissionRate = ParticleSystem.setEmissionRate,
    TotalParticles = ParticleSystem.setTotalParticles,
    PositionType = ParticleSystem.setPositionType,
    Texture = ParticleSystem.setTexture,
    BlendFunc = ParticleSystem.setBlendFunc
});

local ProgressTimer = cc.ProgressTimer;
ProgressTimer.gtor({
    Type = ProgressTimer.getType,
    Percentage = ProgressTimer.getPercentage,
    Percent = function(self)
        return ProgressTimer.getPercentage(self) / 100;
    end,
    Sprite = ProgressTimer.getSprite,
    ReverseDirection = ProgressTimer.isReverseDirection,
    Midpoint = ProgressTimer.getMidpoint,
    BarChangeRate = ProgressTimer.getBarChangeRate
});
ProgressTimer.stor({
    Type = ProgressTimer.setType,
    Percentage = ProgressTimer.setPercentage,
    Percent = function(self,val)
        ProgressTimer.setPercentage(self,val * 100);
    end,
    Sprite = ProgressTimer.setSprite,
    ReverseDirection = ProgressTimer.setReverseDirection,
    Midpoint = ProgressTimer.setMidpoint,
    BarChangeRate = ProgressTimer.setBarChangeRate
});

local RenderTexture = cc.RenderTexture;
RenderTexture.gtor({
    ClearFlags = RenderTexture.getClearFlags,
    ClearColor = RenderTexture.getClearColor,
    ClearDepth = RenderTexture.getClearDepth,
    ClearStencil = RenderTexture.getClearStencil,
    AutoDraw = RenderTexture.isAutoDraw,
    Sprite = RenderTexture.getSprite
});
RenderTexture.stor({
    ClearFlags = RenderTexture.setClearFlags,
    ClearColor = RenderTexture.setClearColor,
    ClearDepth = RenderTexture.setClearDepth,
    ClearStencil = RenderTexture.setClearStencil,
    AutoDraw = RenderTexture.setAutoDraw,
    Sprite = RenderTexture.setSprite,
    KeepMatrix = RenderTexture.setKeepMatrix
});

local Scene = cc.Scene;
Scene.gtor({
    Cameras = Scene.getCameras,
    DefaultCamera = Scene.getDefaultCamera,
    Lights = Scene.getLights,
    PhysicsWorld = Scene.getPhysicsWorld,
    Physics3DWorld = Scene.getPhysics3DWorld,
    NavMesh = Scene.getNavMesh,
});
Scene.stor({
    NavMesh = Scene.setNavMesh
});

local NavMeshAgent = cc.NavMeshAgent;
NavMeshAgent.gtor({
    Radius = NavMeshAgent.getRadius,
    Height = NavMeshAgent.getHeight,
    MaxAcceleration = NavMeshAgent.getMaxAcceleration,
    MaxSpeed = NavMeshAgent.getMaxSpeed,
    SeparationWeight = NavMeshAgent.getSeparationWeight,
    ObstacleAvoidanceType = NavMeshAgent.getObstacleAvoidanceType,
    CurrentVelocity = NavMeshAgent.getCurrentVelocity,
    OnOffMeshLink = NavMeshAgent.isOnOffMeshLink,
    SyncFlag = NavMeshAgent.getSyncFlag,
    Velocity = NavMeshAgent.getVelocity
});
NavMeshAgent.stor({
    Radius = NavMeshAgent.setRadius,
    Height = NavMeshAgent.setHeight,
    MaxAcceleration = NavMeshAgent.setMaxAcceleration,
    MaxSpeed = NavMeshAgent.setMaxSpeed,
    SeparationWeight = NavMeshAgent.setSeparationWeight,
    ObstacleAvoidanceType = NavMeshAgent.setObstacleAvoidanceType,
    OrientationRefAxes = NavMeshAgent.setOrientationRefAxes,
    AutoOrientation = NavMeshAgent.setAutoOrientation,
    AutoTraverseOffMeshLink = NavMeshAgent.setAutoTraverseOffMeshLink,
    SyncFlag = NavMeshAgent.setSyncFlag
});

local NavMeshObstacle = cc.NavMeshObstacle;
NavMeshObstacle.gtor({
    Radius = NavMeshObstacle.getRadius,
    Height = NavMeshObstacle.getHeight,
    SyncFlag = NavMeshObstacle.getSyncFlag
});
NavMeshObstacle.stor({
    Radius = NavMeshObstacle.setRadius,
    Height = NavMeshObstacle.setHeight,
    SyncFlag = NavMeshObstacle.setSyncFlag
});

local Sprite = cc.Sprite;
Sprite.gtor({
    BatchNode = Sprite.getBatchNode,
    Texture = Sprite.getTexture,
    CenterRectNormalized = Sprite.getCenterRectNormalized,
    CenterRect = Sprite.getCenterRect,
    FrameDisplayed = Sprite.isFrameDisplayed,
    SpriteFrame = Sprite.getSpriteFrame,
    Dirty = Sprite.isDirty,
    TextureRectRotated = Sprite.isTextureRectRotated,
    AtlasIndex = Sprite.getAtlasIndex,
    TextureRect = Sprite.getTextureRect,
    TextureAtlas = Sprite.getTextureAtlas,
    OffsetPosition = Sprite.getOffsetPosition,
    FlippedX = Sprite.isFlippedX,
    FlippedY = Sprite.isFlippedY,
    StretchEnabled = Sprite.isStretchEnabled,
    BlendFunc = Sprite.getBlendFunc,
    Grayed = function(self)
        return self.__spriteGrayed or false;
    end
});
Sprite.stor({
    BatchNode = Sprite.setBatchNode,
    Texture = Sprite.setTexture,
    TextureRect = Sprite.setTextureRect,
    VertexRect = Sprite.setVertexRect,
    CenterRectNormalized = Sprite.setCenterRectNormalized,
    CenterRect = Sprite.setCenterRect,
    SpriteFrame = Sprite.setSpriteFrame,
    Dirty = Sprite.setDirty,
    AtlasIndex = Sprite.setAtlasIndex,
    TextureAtlas = Sprite.setTextureAtlas,
    FlippedX = Sprite.setFlippedX,
    FlippedY = Sprite.setFlippedY,
    StretchEnabled = Sprite.setStretchEnabled,
    BlendFunc = Sprite.setBlendFunc,
    ProgramState = Sprite.setProgramState,
    Grayed = function(self,val)
        val = not not val;
        if self.__spriteGrayed == val then
            return;
        end

        self.ProgramState = val and ccb.ProgramType.GRAY_SCALE or ccb.ProgramType.POSITION_TEXTURE_COLOR;
        self.__spriteGrayed = val;
    end
});

local SpriteBatchNode = cc.SpriteBatchNode;
SpriteBatchNode.gtor({
    TextureAtlas = SpriteBatchNode.getTextureAtlas,
    Descendants = SpriteBatchNode.getDescendants,
    Texture = SpriteBatchNode.getTexture,
    BlendFunc = SpriteBatchNode.getBlendFunc,
});
SpriteBatchNode.stor({
    TextureAtlas = SpriteBatchNode.setTextureAtlas,
    Texture = SpriteBatchNode.setTexture,
    BlendFunc = SpriteBatchNode.setBlendFunc,
});

local TransitionScene = cc.TransitionScene;
TransitionScene.gtor({
    InScene = TransitionScene.getInScene,
    Duration = TransitionScene.getDuration
});
TransitionScene.stor({
});

local Director = cc.Director;
Director.gtor({
    RunningScene = Director.getRunningScene,
    AnimationInterval = Director.getAnimationInterval,
    DisplayStats = Director.isDisplayStats,
    SecondsPerFrame = Director.getSecondsPerFrame,
    OpenGLView = Director.getOpenGLView,
    TextureCache = Director.getTextureCache,
    NextDeltaTimeZero = Director.isNextDeltaTimeZero,
    Paused = Director.isPaused,
    TotalFrames = Director.getTotalFrames,
    SendCleanupToScene = Director.isSendCleanupToScene,
    NotificationNode = Director.getNotificationNode,
    WinSize = Director.getWinSize,
    WinSizeInPixels = Director.getWinSizeInPixels,
    VisibleSize = Director.getVisibleSize,
    VisibleOrigin = Director.getVisibleOrigin,
    SafeAreaRect = Director.getSafeAreaRect,
    ZEye = Director.getZEye,
    ClearColor = Director.getClearColor,
    ContentScaleFactor = Director.getContentScaleFactor,
    Scheduler = Director.getScheduler,
    ActionManager = Director.getActionManager,
    EventDispatcher = Director.getEventDispatcher,
    DeltaTime = Director.getDeltaTime,
    FrameRate = Director.getFrameRate,
    Cocos2dThreadId = Director.getCocos2dThreadId,
    Valid = Director.isValid
});
Director.stor({
    AnimationInterval = Director.setAnimationInterval,
    DisplayStats = Director.setDisplayStats,
    OpenGLView = Director.setOpenGLView,
    NextDeltaTimeZero = Director.setNextDeltaTimeZero,
    NotificationNode = Director.setNotificationNode,
    AlphaBlending = Director.setAlphaBlending,
    ClearColor = Director.setClearColor,
    ContentScaleFactor = Director.setContentScaleFactor,
    Scheduler = Director.setScheduler,
    ActionManager = Director.setActionManager,
    EventDispatcher = Director.setEventDispatcher
});

local Event = cc.Event;
Event.gtor({
    Type = Event.getType,
    Stopped = Event.isStopped,
    CurrentTarget = Event.getCurrentTarget
});
Event.stor({
});

local EventCustom = cc.EventCustom;
EventCustom.gtor({
    EventName = EventCustom.getEventName
});
EventCustom.stor({
});

local EventDispatcher = cc.EventDispatcher;
EventDispatcher.gtor({
    Enabled = EventDispatcher.isEnabled
});
EventDispatcher.stor({
    Enabled = EventDispatcher.setEnabled
});

local EventListener = cc.EventListener;
EventListener.gtor({
    Enabled = EventListener.isEnabled
});
EventListener.stor({
    Enabled = EventListener.setEnabled
});

local EventListenerTouchOneByOne = cc.EventListenerTouchOneByOne;
EventListenerTouchOneByOne.gtor({
    SwallowTouches = EventListenerTouchOneByOne.isSwallowTouches
});
EventListenerTouchOneByOne.stor({
    SwallowTouches = EventListenerTouchOneByOne.setSwallowTouches
});

local EventMouse = cc.EventMouse;
EventMouse.gtor({
    ScrollX = EventMouse.getScrollX,
    ScrollY = EventMouse.getScrollY,
    MouseButton = EventMouse.getMouseButton,
    CursorX = EventMouse.getCursorX,
    CursorY = EventMouse.getCursorY,
    Location = EventMouse.getLocation,
    PreviousLocation = EventMouse.getPreviousLocation,
    StartLocation = EventMouse.getStartLocation,
    Delta = EventMouse.getDelta,
    LocationInView = EventMouse.getLocationInView,
    PreviousLocationInView = EventMouse.getPreviousLocationInView,
    StartLocationInView = EventMouse.getStartLocationInView
});
EventMouse.stor({
    CursorPosition = EventMouse.setCursorPosition,
    MouseButton = EventMouse.setMouseButton
});

local EventTouch = cc.EventTouch;
EventTouch.gtor({
    EventCode = EventTouch.getEventCode,
    Touches = EventTouch.getTouches
});
EventTouch.stor({
});

local Scheduler = cc.Scheduler;
Scheduler.gtor({
    TimeScale = Scheduler.getTimeScale
});
Scheduler.stor({
    TimeScale = Scheduler.setTimeScale
});

local Touch = cc.Touch;
Touch.gtor({
    Location = Touch.getLocation,
    PreviousLocation = Touch.getPreviousLocation,
    StartLocation = Touch.getStartLocation,
    Delta = Touch.getDelta,
    LocationInView = Touch.getLocationInView,
    PreviousLocationInView = Touch.getPreviousLocationInView,
    StartLocationInView = Touch.getStartLocationInView,
    ID = Touch.getID,
    CurrentForce = Touch.getCurrentForce,
    MaxForce = Touch.getMaxForce
});
Touch.stor({
});

local CSLoader = cc.CSLoader;
CSLoader.gtor({
    RecordJsonPath = CSLoader.isRecordJsonPath,
    JsonPath = CSLoader.getJsonPath,
});
CSLoader.stor({
    RecordJsonPath = CSLoader.setRecordJsonPath,
    JsonPath = CSLoader.setJsonPath,
});

local AssetsManagerEx = cc.AssetsManagerEx;
AssetsManagerEx.gtor({
    State = AssetsManagerEx.getState,
    StoragePath = AssetsManagerEx.getStoragePath,
    LocalManifest = AssetsManagerEx.getLocalManifest,
    RemoteManifest = AssetsManagerEx.getRemoteManifest,
    MaxConcurrentTask = AssetsManagerEx.getMaxConcurrentTask
});
AssetsManagerEx.stor({
    MaxConcurrentTask = AssetsManagerEx.setMaxConcurrentTask
});

local EventAssetsManagerEx = cc.EventAssetsManagerEx;
EventAssetsManagerEx.gtor({
    EventCode = EventAssetsManagerEx.getEventCode,
    CURLECode = EventAssetsManagerEx.getCURLECode,
    CURLMCode = EventAssetsManagerEx.getCURLMCode,
    Message = EventAssetsManagerEx.getMessage,
    AssetId = EventAssetsManagerEx.getAssetId,
    AssetsManagerEx = EventAssetsManagerEx.getAssetsManagerEx,
    Percent = function(self)
        return EventAssetsManagerEx.getPercent(self) / 100;
    end,
    PercentByFile = function(self)
        return EventAssetsManagerEx.getPercentByFile(self) / 100;
    end
});
EventAssetsManagerEx.stor({
});

local Manifest = cc.Manifest;
Manifest.gtor({
    VersionLoaded = Manifest.isVersionLoaded,
    Loaded = Manifest.isLoaded,
    PackageUrl = Manifest.getPackageUrl,
    ManifestFileUrl = Manifest.getManifestFileUrl,
    VersionFileUrl = Manifest.getVersionFileUrl,
    Version = Manifest.getVersion,
    SearchPaths = Manifest.getSearchPaths
});
Manifest.stor({
});

local PhysicsBody = cc.PhysicsBody;
PhysicsBody.gtor({
    Shapes = PhysicsBody.getShapes,
    FirstShape = PhysicsBody.getFirstShape,
    Velocity = PhysicsBody.getVelocity,
    AngularVelocity = PhysicsBody.getAngularVelocity,
    VelocityLimit = PhysicsBody.getVelocityLimit,
    AngularVelocityLimit = PhysicsBody.getAngularVelocityLimit,
    World = PhysicsBody.getWorld,
    Joints = PhysicsBody.getJoints,
    Node = PhysicsBody.getNode,
    CategoryBitmask = PhysicsBody.getCategoryBitmask,
    ContactTestBitmask = PhysicsBody.getContactTestBitmask,
    CollisionBitmask = PhysicsBody.getCollisionBitmask,
    Group = PhysicsBody.getGroup,
    Position = PhysicsBody.getPosition,
    Rotation = PhysicsBody.getRotation,
    PositionOffset = PhysicsBody.getPositionOffset,
    RotationOffset = PhysicsBody.getRotationOffset,
    Dynamic = PhysicsBody.isDynamic,
    Mass = PhysicsBody.getMass,
    Moment = PhysicsBody.getMoment,
    LinearDamping = PhysicsBody.getLinearDamping,
    AngularDamping = PhysicsBody.getAngularDamping,
    Resting = PhysicsBody.isResting,
    RotationEnabled = PhysicsBody.isRotationEnabled,
    GravityEnabled = PhysicsBody.isGravityEnabled,
    Tag = PhysicsBody.getTag,
});
PhysicsBody.stor({
    Velocity = PhysicsBody.setVelocity,
    AngularVelocity = PhysicsBody.setAngularVelocity,
    VelocityLimit = PhysicsBody.setVelocityLimit,
    AngularVelocityLimit = PhysicsBody.setAngularVelocityLimit,
    CategoryBitmask = PhysicsBody.setCategoryBitmask,
    ContactTestBitmask = PhysicsBody.setContactTestBitmask,
    CollisionBitmask = PhysicsBody.setCollisionBitmask,
    Group = PhysicsBody.setGroup,
    PositionOffset = PhysicsBody.setPositionOffset,
    RotationOffset = PhysicsBody.setRotationOffset,
    Dynamic = PhysicsBody.setDynamic,
    Mass = PhysicsBody.setMass,
    Moment = PhysicsBody.setMoment,
    LinearDamping = PhysicsBody.setLinearDamping,
    AngularDamping = PhysicsBody.setAngularDamping,
    Resting = PhysicsBody.setResting,
    RotationEnabled = PhysicsBody.setRotationEnable,
    GravityEnabled = PhysicsBody.setGravityEnabled,
    Tag = PhysicsBody.setTag,
});

local PhysicsShape = cc.PhysicsShape;
PhysicsShape.gtor({
    Body = PhysicsShape.getBody,
    Type = PhysicsShape.getType,
    Area = PhysicsShape.getArea,
    Moment = PhysicsShape.getMoment,
    Tag = PhysicsShape.getTag,
    Mass = PhysicsShape.getMass,
    Density = PhysicsShape.getDensity,
    Restitution = PhysicsShape.getRestitution,
    Friction = PhysicsShape.getFriction,
    Material = PhysicsShape.getMaterial,
    Sensor = PhysicsShape.isSensor,
    Offset = PhysicsShape.getOffset,
    Center = PhysicsShape.getCenter,
    CategoryBitmask = PhysicsShape.getCategoryBitmask,
    ContactTestBitmask = PhysicsShape.getContactTestBitmask,
    CollisionBitmask = PhysicsShape.getCollisionBitmask,
    Group = PhysicsShape.getGroup
});
PhysicsShape.stor({
    Moment = PhysicsShape.setMoment,
    Tag = PhysicsShape.setTag,
    Mass = PhysicsShape.setMass,
    Density = PhysicsShape.setDensity,
    Restitution = PhysicsShape.setRestitution,
    Friction = PhysicsShape.setFriction,
    Material = PhysicsShape.setMaterial,
    Sensor = PhysicsShape.setSensor,
    CategoryBitmask = PhysicsShape.setCategoryBitmask,
    ContactTestBitmask = PhysicsShape.setContactTestBitmask,
    CollisionBitmask = PhysicsShape.setCollisionBitmask,
    Group = PhysicsShape.setGroup
});

local PhysicsContact = cc.PhysicsContact;
PhysicsContact.gtor({
    ShapeA = PhysicsContact.getShapeA,
    ShapeB = PhysicsContact.getShapeB,
    EventCode = PhysicsContact.getEventCode,
    ContactData = PhysicsContact.getContactData,
    PreContactData = PhysicsContact.getPreContactData
});
PhysicsContact.stor({
});

local PhysicsShapeCircle = cc.PhysicsShapeCircle;
PhysicsShapeCircle.gtor({
    Radius = PhysicsShapeCircle.getRadius
});
PhysicsShapeCircle.stor({
});

local PhysicsShapePolygon = cc.PhysicsShapePolygon;
PhysicsShapePolygon.gtor({
    PointsCount = PhysicsShapePolygon.getPointsCount
});
PhysicsShapePolygon.stor({
});

local PhysicsShapeBox = cc.PhysicsShapeBox;
PhysicsShapeBox.gtor({
    Size = PhysicsShapeBox.getSize
});
PhysicsShapeBox.stor({
});

local PhysicsShapeEdgeSegment = cc.PhysicsShapeEdgeSegment;
PhysicsShapeEdgeSegment.gtor({
    PointA = PhysicsShapeEdgeSegment.getPointA,
    PointB = PhysicsShapeEdgeSegment.getPointB
});
PhysicsShapeEdgeSegment.stor({
});

local PhysicsShapeEdgePolygon = cc.PhysicsShapeEdgePolygon;
PhysicsShapeEdgePolygon.gtor({
    PointsCount = PhysicsShapeEdgePolygon.getPointsCount
});
PhysicsShapeEdgePolygon.stor({
});

local PhysicsShapeEdgeChain = cc.PhysicsShapeEdgeChain;
PhysicsShapeEdgeChain.gtor({
    PointsCount = PhysicsShapeEdgeChain.getPointsCount
});
PhysicsShapeEdgeChain.stor({
});

local PhysicsJoint = cc.PhysicsJoint;
PhysicsJoint.gtor({
    BodyA = PhysicsJoint.getBodyA,
    BodyB = PhysicsJoint.getBodyB,
    World = PhysicsJoint.getWorld,
    Tag = PhysicsJoint.getTag,
    Enabled = PhysicsJoint.isEnabled,
    CollisionEnabled = PhysicsJoint.isCollisionEnabled,
    MaxForce = PhysicsJoint.getMaxForce
});
PhysicsJoint.stor({
    Tag = PhysicsJoint.setTag,
    Enabled = PhysicsJoint.setEnabled,
    CollisionEnabled = PhysicsJoint.setCollisionEnabled,
    MaxForce = PhysicsJoint.setMaxForce
});

local PhysicsJointLimit = cc.PhysicsJointLimit;
PhysicsJointLimit.gtor({
    Anchr1 = PhysicsJointLimit.getAnchr1,
    Anchr2 = PhysicsJointLimit.getAnchr2,
    Min = PhysicsJointLimit.getMin,
    Max = PhysicsJointLimit.getMax
});
PhysicsJointLimit.stor({
    Anchr1 = PhysicsJointLimit.setAnchr1,
    Anchr2 = PhysicsJointLimit.setAnchr2,
    Min = PhysicsJointLimit.setMin,
    Max = PhysicsJointLimit.setMax
});

local PhysicsJointDistance = cc.PhysicsJointDistance;
PhysicsJointDistance.gtor({
    Distance = PhysicsJointDistance.getDistance
});
PhysicsJointDistance.stor({
    Distance = PhysicsJointDistance.setDistance
});

local PhysicsJointSpring = cc.PhysicsJointSpring;
PhysicsJointSpring.gtor({
    Anchr1 = PhysicsJointSpring.getAnchr1,
    Anchr2 = PhysicsJointSpring.getAnchr2,
    RestLength = PhysicsJointSpring.getRestLength,
    Stiffness = PhysicsJointSpring.getStiffness,
    Damping = PhysicsJointSpring.getDamping
});
PhysicsJointSpring.stor({
    Anchr1 = PhysicsJointSpring.setAnchr1,
    Anchr2 = PhysicsJointSpring.setAnchr2,
    RestLength = PhysicsJointSpring.setRestLength,
    Stiffness = PhysicsJointSpring.setStiffness,
    Damping = PhysicsJointSpring.setDamping
});

local PhysicsJointGroove = cc.PhysicsJointGroove;
PhysicsJointGroove.gtor({
    GrooveA = PhysicsJointGroove.getGrooveA,
    GrooveB = PhysicsJointGroove.getGrooveB,
    Anchr2 = PhysicsJointGroove.getAnchr2
});
PhysicsJointGroove.stor({
    GrooveA = PhysicsJointGroove.setGrooveA,
    GrooveB = PhysicsJointGroove.setGrooveB,
    Anchr2 = PhysicsJointGroove.setAnchr2
});

local PhysicsJointRotarySpring = cc.PhysicsJointRotarySpring;
PhysicsJointRotarySpring.gtor({
    RestAngle = PhysicsJointRotarySpring.getRestAngle,
    Stiffness = PhysicsJointRotarySpring.getStiffness,
    Damping = PhysicsJointRotarySpring.getDamping
});
PhysicsJointRotarySpring.stor({
    RestAngle = PhysicsJointRotarySpring.setRestAngle,
    Stiffness = PhysicsJointRotarySpring.setStiffness,
    Damping = PhysicsJointRotarySpring.setDamping
});

local PhysicsJointRotaryLimit = cc.PhysicsJointRotaryLimit;
PhysicsJointRotaryLimit.gtor({
    Min = PhysicsJointRotaryLimit.getMin,
    Max = PhysicsJointRotaryLimit.getMax
});
PhysicsJointRotaryLimit.stor({
    Min = PhysicsJointRotaryLimit.setMin,
    Max = PhysicsJointRotaryLimit.setMax
});

local PhysicsJointRatchet = cc.PhysicsJointRatchet;
PhysicsJointRatchet.gtor({
    Angle = PhysicsJointRatchet.getAngle,
    Phase = PhysicsJointRatchet.getPhase,
    Ratchet = PhysicsJointRatchet.getRatchet
});
PhysicsJointRatchet.stor({
    Angle = PhysicsJointRatchet.setAngle,
    Phase = PhysicsJointRatchet.setPhase,
    Ratchet = PhysicsJointRatchet.setRatchet
});

local PhysicsJointGear = cc.PhysicsJointGear;
PhysicsJointGear.gtor({
    Phase = PhysicsJointGear.getPhase,
    Ratio = PhysicsJointGear.getRatio
});
PhysicsJointGear.stor({
    Phase = PhysicsJointGear.setPhase,
    Ratio = PhysicsJointGear.setRatio
});

local PhysicsJointMotor = cc.PhysicsJointMotor;
PhysicsJointMotor.gtor({
    Rate = PhysicsJointGear.getRate
});
PhysicsJointMotor.stor({
    Rate = PhysicsJointGear.setRate
});

local PhysicsWorld = cc.PhysicsWorld;
PhysicsWorld.gtor({
    Bodies = PhysicsWorld.getAllBodies,
    Scene = PhysicsWorld.getScene,
    Gravity = PhysicsWorld.getGravity,
    Speed = PhysicsWorld.getSpeed,
    UpdateRate = PhysicsWorld.getUpdateRate,
    Substeps = PhysicsWorld.getSubsteps,
    FixedUpdateRate = PhysicsWorld.getFixedUpdateRate,
    AutoStep = PhysicsWorld.isAutoStep
});
PhysicsWorld.stor({
    Gravity = PhysicsWorld.setGravity,
    Speed = PhysicsWorld.setSpeed,
    UpdateRate = PhysicsWorld.setUpdateRate,
    Substeps = PhysicsWorld.setSubsteps,
    FixedUpdateRate = PhysicsWorld.setFixedUpdateRate,
    AutoStep = PhysicsWorld.setAutoStep,
    DebugDrawMask = PhysicsWorld.setDebugDrawMask
});

local Application = cc.Application;
Application.gtor({
    TargetPlatform = Application.getTargetPlatform,
    CurrentLanguage = Application.getCurrentLanguage,
    CurrentLanguageCode = Application.getCurrentLanguageCode,
    Version = Application.getVersion,
    CompileVersion = Application.GetCompileVersion
});
Application.stor({
    AnimationInterval = Application.setAnimationInterval
});

local FileUtils = cc.FileUtils;
FileUtils.gtor({
    SearchResolutionsOrder = FileUtils.getSearchResolutionsOrder,
    DefaultResourceRootPath = FileUtils.getDefaultResourceRootPath,
    SearchPaths = FileUtils.getSearchPaths,
    OriginalSearchPaths = FileUtils.getOriginalSearchPaths,
    WritablePath = FileUtils.getWritablePath,
    PopupNotify = FileUtils.isPopupNotify
});
FileUtils.stor({
    FilenameLookupDictionary = FileUtils.setFilenameLookupDictionary,
    SearchResolutionsOrder = FileUtils.setSearchResolutionsOrder,
    SearchPaths = FileUtils.setSearchPaths,
    DefaultResourceRootPath = FileUtils.setDefaultResourceRootPath,
    WritablePath = FileUtils.setWritablePath,
    PopupNotify = FileUtils.setPopupNotify
});

local GLView = cc.GLView;
GLView.gtor({
    OpenGLReady = GLView.isOpenGLReady,
    FrameSize = GLView.getFrameSize,
    FrameZoomFactor = GLView.getFrameZoomFactor,
    RetinaFactor = GLView.getRetinaFactor,
    ContentScaleFactor = GLView.getContentScaleFactor,
    RetinaDisplay = GLView.isRetinaDisplay,
    VisibleSize = GLView.getVisibleSize,
    VisibleOrigin = GLView.getVisibleOrigin,
    VisibleRect = GLView.getVisibleRect,
    SafeAreaRect = GLView.getSafeAreaRect,
    DesignResolutionSize = GLView.getDesignResolutionSize,
    ScissorEnabled = GLView.isScissorEnabled,
    ScissorRect = GLView.getScissorRect,
    ViewName = GLView.getViewName,
    ViewPortRect = GLView.getViewPortRect,
    Touches = GLView.getAllTouches,
    ScaleX = GLView.getScaleX,
    ScaleY = GLView.getScaleY,
    ResolutionPolicy = GLView.getResolutionPolicy
});
GLView.stor({
    IMEKeyboardState = GLView.setIMEKeyboardState,
    FrameSize = GLView.setFrameSize,
    FrameZoomFactor = GLView.setFrameZoomFactor,
    CursorVisible = GLView.setCursorVisible,
    RetinaFactor = GLView.setRetinaFactor,
    ViewName = GLView.setViewName,
    Icon = GLView.setIcon
});

local Image = cc.Image;
Image.gtor({
    FileType = Image.getFileType,
    RenderFormat = Image.getRenderFormat,
    Width = Image.getWidth,
    Height = Image.getHeight,
    NumberOfMipmaps = Image.getNumberOfMipmaps,
    PremultipliedAlpha = Image.hasPremultipliedAlpha,
    FilePath = Image.getFilePath,
    BitPerPixel = Image.getBitPerPixel,
    Alpha = Image.hasAlpha,
    Compressed = Image.isCompressed
});
Image.stor({
});

local RenderState = cc.RenderState;
RenderState.gtor({
    Name = RenderState.getName,
    Texture = RenderState.getTexture
});
RenderState.stor({
    Texture = RenderState.setTexture,
    Parent = RenderState.setParent
});

local Material = cc.Material;
Material.gtor({
    Name = Material.getName,
    Technique = Material.getTechnique,
    Techniques = Material.getTechniques,
    TechniqueCount = Material.getTechniqueCount
});
Material.stor({
    Name = Material.setName
});

local Pass = cc.Pass;
Pass.gtor({
    ProgramState = Pass.getProgramState,
    VertexAttributeBinding = Pass.getVertexAttributeBinding,
    Hash = Pass.getHash
});
Pass.stor({
    VertexAttributeBinding = Pass.setVertexAttributeBinding
});

local Technique = cc.Technique;
Technique.gtor({
    Name = Technique.getName,
    PassCount = Technique.getPassCount,
    Passes = Technique.getPasses
});
Technique.stor({
});

local Texture2D = cc.Texture2D;
Texture2D.gtor({
    StringForFormat = Texture2D.getStringForFormat,
    BitsPerPixelForFormat = Texture2D.getBitsPerPixelForFormat,
    ContentSizeInPixels = Texture2D.getContentSizeInPixels,
    PremultipliedAlpha = Texture2D.hasPremultipliedAlpha,
    Mipmaps = Texture2D.hasMipmaps,
    PixelFormat = Texture2D.getPixelFormat,
    PixelsWide = Texture2D.getPixelsWide,
    PixelsHigh = Texture2D.getPixelsHigh,
    Name = Texture2D.getName,
    MaxS = Texture2D.getMaxS,
    MaxT = Texture2D.getMaxT,
    Size = Texture2D.getContentSize,
    Path = Texture2D.getPath,
    AlphaTextureName = Texture2D.getAlphaTextureName,
    AlphaTexture = Texture2D.getAlphaTexture
});
Texture2D.stor({
    TexParameters = Texture2D.setTexParameters,
    MaxS = Texture2D.setMaxS,
    MaxT = Texture2D.setMaxT,
    AlphaTexture = Texture2D.setAlphaTexture
});

local Scale9Sprite = ccui.Scale9Sprite;
Scale9Sprite.gtor({
    OriginalSize = Scale9Sprite.getOriginalSize,
    PreferredSize = Scale9Sprite.getPreferredSize,
    InsetLeft = Scale9Sprite.getInsetLeft,
    InsetTop = Scale9Sprite.getInsetTop,
    InsetRight = Scale9Sprite.getInsetRight,
    InsetBottom = Scale9Sprite.getInsetBottom,
    Scale9Enabled = Scale9Sprite.isScale9Enabled,
    Sprite = Scale9Sprite.getSprite,
    RenderingType = Scale9Sprite.getRenderingType,
    CapInsets = Scale9Sprite.getCapInsets,
    -- 由于State枚举和State的gtor冲突，可以使用Grayed代替State的gtor
    Grayed = function(self)
        return self:getState() == Scale9Sprite.State.GRAY;
    end
});
Scale9Sprite.stor({
    PreferredSize = Scale9Sprite.setPreferredSize,
    InsetLeft = Scale9Sprite.setInsetLeft,
    InsetTop = Scale9Sprite.setInsetTop,
    InsetRight = Scale9Sprite.setInsetRight,
    InsetBottom = Scale9Sprite.setInsetBottom,
    Scale9Enabled = Scale9Sprite.setScale9Enabled,
    RenderingType = Scale9Sprite.setRenderingType,
    CapInsets = Scale9Sprite.setCapInsets,
    -- 由于State枚举和State的stor冲突，可以使用Grayed代替State的stor
    Grayed = function(self,val)
        if val then
            self:setState(Scale9Sprite.State.GRAY);
        else
            self:setState(Scale9Sprite.State.NORMAL);
        end
    end
});

local Widget = ccui.Widget;
Widget.gtor({
    Enabled = Widget.isEnabled,
    Bright = Widget.isBright,
    TouchEnabled = Widget.isTouchEnabled,
    Highlighted = Widget.isHighlighted,
    LeftBoundary = Widget.getLeftBoundary,
    BottomBoundary = Widget.getBottomBoundary,
    RightBoundary = Widget.getRightBoundary,
    TopBoundary = Widget.getTopBoundary,
    PositionPercent = Widget.getPositionPercent,
    PositionType = Widget.getPositionType,
    FlippedX = Widget.isFlippedX,
    FlippedY = Widget.isFlippedY,
    ClippingParentContainsPoint = Widget.isClippingParentContainsPoint,
    TouchBeganPosition = Widget.getTouchBeganPosition,
    TouchMovePosition = Widget.getTouchMovePosition,
    TouchEndPosition = Widget.getTouchEndPosition,
    SizeType = Widget.getSizeType,
    CustomSize = Widget.getCustomSize,
    LayoutSize = Widget.getLayoutSize,
    SizePercent = Widget.getSizePercent,
    LayoutParameter = Widget.getLayoutParameter,
    IgnoreContentAdaptWithSize = Widget.isIgnoreContentAdaptWithSize,
    WorldPosition = Widget.getWorldPosition,
    VirtualRenderer = Widget.getVirtualRenderer,
    VirtualRendererSize = Widget.getVirtualRendererSize,
    ActionTag = Widget.getActionTag,
    PropagateTouchEvents = Widget.isPropagateTouchEvents,
    SwallowTouches = Widget.isSwallowTouches,
    Focused = Widget.isFocused,
    FocusEnabled = Widget.isFocusEnabled,
    UnifySizeEnabled = Widget.isUnifySizeEnabled,
    CallbackName = Widget.getCallbackName,
    CallbackType = Widget.getCallbackType,
    LayoutComponentEnabled = Widget.isLayoutComponentEnabled
});
Widget.stor({
    Enabled = Widget.setEnabled,
    Bright = Widget.setBright,
    TouchEnabled = Widget.setTouchEnabled,
    BrightStyle = Widget.setBrightStyle,
    Highlighted = Widget.setHighlighted,
    PositionPercent = Widget.setPositionPercent,
    PositionType = Widget.setPositionType,
    FlippedX = Widget.setFlippedX,
    FlippedY = Widget.setFlippedY,
    SizePercent = Widget.setSizePercent,
    SizeType = Widget.setSizeType,
    LayoutParameter = Widget.setLayoutParameter,
    IgnoreContentAdaptWithSize = Widget.ignoreContentAdaptWithSize,
    ActionTag = Widget.setActionTag,
    PropagateTouchEvents = Widget.setPropagateTouchEvents,
    SwallowTouches = Widget.setSwallowTouches,
    Focused = Widget.setFocused,
    FocusEnabled = Widget.setFocusEnabled,
    UnifySizeEnabled = Widget.setUnifySizeEnabled,
    CallbackName = Widget.setCallbackName,
    LayoutComponentEnabled = Widget.setLayoutComponentEnabled,
    TouchHandler = Widget.addTouchEventListener
});

local Layout = ccui.Layout;
Layout.gtor({
    BackGroundImageCapInsets = Layout.getBackGroundImageCapInsets,
    BackGroundColorType = Layout.getBackGroundColorType,
    BackGroundImageScale9Enabled = Layout.isBackGroundImageScale9Enabled,
    BackGroundColor = Layout.getBackGroundColor,
    BackGroundStartColor = Layout.getBackGroundStartColor,
    BackGroundEndColor = Layout.getBackGroundEndColor,
    BackGroundColorOpacity = Layout.getBackGroundColorOpacity,
    BackGroundColorVector = Layout.getBackGroundColorVector,
    BackGroundImageColor = Layout.getBackGroundImageColor,
    BackGroundImageOpacity = Layout.getBackGroundImageOpacity,
    BackGroundImageTextureSize = Layout.getBackGroundImageTextureSize,
    ClippingType = Layout.getClippingType,
    ClippingEnabled = Layout.isClippingEnabled,
    LayoutType = Layout.getLayoutType,
    LoopFocus = Layout.isLoopFocus,
    PassFocusToChild = Layout.isPassFocusToChild
});
Layout.stor({
    BackGroundImage = Layout.setBackGroundImage,
    BackGroundImageCapInsets = Layout.setBackGroundImageCapInsets,
    BackGroundColorType = Layout.setBackGroundColorType,
    BackGroundImageScale9Enabled = Layout.setBackGroundImageScale9Enabled,
    BackGroundColor = Layout.setBackGroundColor,
    BackGroundColorOpacity = Layout.setBackGroundColorOpacity,
    BackGroundColorVector = Layout.setBackGroundColorVector,
    BackGroundImageColor = Layout.setBackGroundImageColor,
    BackGroundImageOpacity = Layout.setBackGroundImageOpacity,
    ClippingEnabled = Layout.setClippingEnabled,
    ClippingType = Layout.setClippingType,
    LayoutType = Layout.setLayoutType,
    LoopFocus = Layout.setLoopFocus,
    PassFocusToChild = Layout.setPassFocusToChild
});

local LayoutComponent = ccui.LayoutComponent;
LayoutComponent.gtor({
    UsingPercentContentSize = LayoutComponent.getUsingPercentContentSize,
    PercentContentSize = LayoutComponent.getPercentContentSize,
    AnchorPosition = LayoutComponent.getAnchorPosition,
    Position = LayoutComponent.getPosition,
    XY = LayoutComponent.getPosition,
    PositionPercentXEnabled = LayoutComponent.isPositionPercentXEnabled,
    PositionPercentX = LayoutComponent.getPositionPercentX,
    PositionPercentYEnabled = LayoutComponent.isPositionPercentYEnabled,
    PositionPercentY = LayoutComponent.getPositionPercentY,
    HorizontalEdge = LayoutComponent.getHorizontalEdge,
    VerticalEdge = LayoutComponent.getVerticalEdge,
    LeftMargin = LayoutComponent.getLeftMargin,
    RightMargin = LayoutComponent.getRightMargin,
    TopMargin = LayoutComponent.getTopMargin,
    BottomMargin = LayoutComponent.getBottomMargin,
    Size = LayoutComponent.getSize,
    PercentWidthEnabled = LayoutComponent.isPercentWidthEnabled,
    SizeWidth = LayoutComponent.getSizeWidth,
    PercentWidth = LayoutComponent.getPercentWidth,
    PercentHeightEnabled = LayoutComponent.isPercentHeightEnabled,
    SizeHeight = LayoutComponent.getSizeHeight,
    PercentHeight = LayoutComponent.getPercentHeight,
    StretchWidthEnabled = LayoutComponent.isStretchWidthEnabled,
    StretchHeightEnabled = LayoutComponent.isStretchHeightEnabled,
});
LayoutComponent.stor({
    UsingPercentContentSize = LayoutComponent.setUsingPercentContentSize,
    PercentContentSize = LayoutComponent.setPercentContentSize,
    AnchorPosition = LayoutComponent.setAnchorPosition,
    Position = LayoutComponent.setPosition,
    XY = LayoutComponent.setPosition,
    PositionPercentXEnabled = LayoutComponent.setPositionPercentXEnabled,
    PositionPercentX = LayoutComponent.setPositionPercentX,
    PositionPercentYEnabled = LayoutComponent.setPositionPercentYEnabled,
    PositionPercentY = LayoutComponent.setPositionPercentY,
    HorizontalEdge = LayoutComponent.setHorizontalEdge,
    VerticalEdge = LayoutComponent.setVerticalEdge,
    LeftMargin = LayoutComponent.setLeftMargin,
    RightMargin = LayoutComponent.setRightMargin,
    TopMargin = LayoutComponent.setTopMargin,
    BottomMargin = LayoutComponent.setBottomMargin,
    Size = LayoutComponent.setSize,
    PercentWidthEnabled = LayoutComponent.setPercentWidthEnabled,
    SizeWidth = LayoutComponent.setSizeWidth,
    PercentWidth = LayoutComponent.setPercentWidth,
    PercentHeightEnabled = LayoutComponent.setPercentHeightEnabled,
    SizeHeight = LayoutComponent.setSizeHeight,
    PercentHeight = LayoutComponent.setPercentHeight,
    StretchWidthEnabled = LayoutComponent.setStretchWidthEnabled,
    StretchHeightEnabled = LayoutComponent.setStretchHeightEnabled,
    PercentOnlyEnabled = LayoutComponent.setPercentOnlyEnabled,
    ActiveEnabled = LayoutComponent.setActiveEnabled,
});

local LayoutParameter = ccui.LayoutParameter;
LayoutParameter.gtor({
    Margin = LayoutParameter.getMargin,
    LayoutType = LayoutParameter.getLayoutType
});
LayoutParameter.stor({
    Margin = LayoutParameter.setMargin
});

local LinearLayoutParameter = ccui.LinearLayoutParameter;
LinearLayoutParameter.gtor({
    Gravity = LinearLayoutParameter.getGravity
});
LinearLayoutParameter.stor({
    Gravity = LinearLayoutParameter.setGravity
});

local RelativeLayoutParameter = ccui.RelativeLayoutParameter;
RelativeLayoutParameter.gtor({
    Align = RelativeLayoutParameter.getAlign,
    RelativeToWidgetName = RelativeLayoutParameter.getRelativeToWidgetName,
    RelativeName = RelativeLayoutParameter.getRelativeName
});
RelativeLayoutParameter.stor({
    Align = RelativeLayoutParameter.setAlign,
    RelativeToWidgetName = RelativeLayoutParameter.setRelativeToWidgetName,
    RelativeName = RelativeLayoutParameter.setRelativeName
});

local EditBox = ccui.EditBox;
EditBox.gtor({
    CapInsetsNormalRenderer = EditBox.getCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = EditBox.getCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = EditBox.getCapInsetsDisabledRenderer,
    Text = EditBox.getText,
    FontName = EditBox.getFontName,
    FontSize = EditBox.getFontSize,
    FontColor = EditBox.getFontColor,
    PlaceholderFontName = EditBox.getPlaceholderFontName,
    PlaceholderFontSize = EditBox.getPlaceholderFontSize,
    PlaceholderFontColor = EditBox.getPlaceholderFontColor,
    PlaceHolder = EditBox.getPlaceHolder,
    InputMode = EditBox.getInputMode,
    MaxLength = EditBox.getMaxLength,
    InputFlag = EditBox.getInputFlag,
    ReturnType = EditBox.getReturnType,
    TextHorizontalAlignment = EditBox.getTextHorizontalAlignment
});
EditBox.stor({
    CapInsets = EditBox.setCapInsets,
    CapInsetsNormalRenderer = EditBox.setCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = EditBox.setCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = EditBox.setCapInsetsDisabledRenderer,
    Text = EditBox.setText,
    FontName = EditBox.setFontName,
    FontSize = EditBox.setFontSize,
    FontColor = EditBox.setFontColor,
    PlaceholderFontName = EditBox.setPlaceholderFontName,
    PlaceholderFontSize = EditBox.setPlaceholderFontSize,
    PlaceholderFontColor = EditBox.setPlaceholderFontColor,
    PlaceHolder = EditBox.setPlaceHolder,
    InputMode = EditBox.setInputMode,
    MaxLength = EditBox.setMaxLength,
    InputFlag = EditBox.setInputFlag,
    ReturnType = EditBox.setReturnType,
    TextHorizontalAlignment = EditBox.setTextHorizontalAlignment,
    Handler = function(self,val)
        if val == nil then
            self:unregisterScriptEditBoxHandler();
        else
            self:registerScriptEditBoxHandler(val);
        end
    end
});

local ScrollView = ccui.ScrollView;
ScrollView.gtor({
    Direction = ScrollView.getDirection,
    InnerContainer = ScrollView.getInnerContainer,
    ScrolledPercentVertical = ScrollView.getScrolledPercentVertical,
    ScrolledPercentHorizontal = ScrollView.getScrolledPercentHorizontal,
    ScrolledPercentBothDirection = ScrollView.getScrolledPercentBothDirection,
    InnerContainerSize = ScrollView.getInnerContainerSize,
    InnerContainerPosition = ScrollView.getInnerContainerPosition,
    BounceEnabled = ScrollView.isBounceEnabled,
    InertiaScrollEnabled = ScrollView.isInertiaScrollEnabled,
    ScrollBarEnabled = ScrollView.isScrollBarEnabled,
    ScrollBarPositionFromCornerForVertical = ScrollView.getScrollBarPositionFromCornerForVertical,
    ScrollBarPositionFromCornerForHorizontal = ScrollView.getScrollBarPositionFromCornerForHorizontal,
    ScrollBarWidth = ScrollView.getScrollBarWidth,
    ScrollBarColor = ScrollView.getScrollBarColor,
    ScrollBarOpacity = ScrollView.getScrollBarOpacity,
    ScrollBarAutoHideEnabled = ScrollView.isScrollBarAutoHideEnabled,
    ScrollBarAutoHideTime = ScrollView.getScrollBarAutoHideTime,
    TouchTotalTimeThreshold = ScrollView.getTouchTotalTimeThreshold,
    LayoutType = ScrollView.getLayoutType,
    Scrolling = ScrollView.isScrolling,
    AutoScrolling = ScrollView.isAutoScrolling
});
ScrollView.stor({
    Direction = ScrollView.setDirection,
    InnerContainerSize = ScrollView.setInnerContainerSize,
    InnerContainerPosition = ScrollView.setInnerContainerPosition,
    BounceEnabled = ScrollView.setBounceEnabled,
    InertiaScrollEnabled = ScrollView.setInertiaScrollEnabled,
    ScrollBarEnabled = ScrollView.setScrollBarEnabled,
    ScrollBarPositionFromCorner = ScrollView.setScrollBarPositionFromCorner,
    ScrollBarPositionFromCornerForVertical = ScrollView.setScrollBarPositionFromCornerForVertical,
    ScrollBarPositionFromCornerForHorizontal = ScrollView.setScrollBarPositionFromCornerForHorizontal,
    ScrollBarWidth = ScrollView.setScrollBarWidth,
    ScrollBarColor = ScrollView.setScrollBarColor,
    ScrollBarOpacity = ScrollView.setScrollBarOpacity,
    ScrollBarAutoHideEnabled = ScrollView.setScrollBarAutoHideEnabled,
    ScrollBarAutoHideTime = ScrollView.setScrollBarAutoHideTime,
    TouchTotalTimeThreshold = ScrollView.setTouchTotalTimeThreshold,
    LayoutType = ScrollView.setLayoutType
});

local ListView = ccui.ListView;
ListView.gtor({
    Items = ListView.getItems,
    MagneticType = ListView.getMagneticType,
    MagneticAllowedOutOfBoundary = ListView.getMagneticAllowedOutOfBoundary,
    ItemsMargin = ListView.getItemsMargin,
    LeftPadding = ListView.getLeftPadding,
    TopPadding = ListView.getTopPadding,
    RightPadding = ListView.getRightPadding,
    BottomPadding = ListView.getBottomPadding,
    ScrollDuration = ListView.getScrollDuration,
    CenterItemInCurrentView = ListView.getCenterItemInCurrentView,
    LeftmostItemInCurrentView = ListView.getLeftmostItemInCurrentView,
    RightmostItemInCurrentView = ListView.getRightmostItemInCurrentView,
    TopmostItemInCurrentView = ListView.getTopmostItemInCurrentView,
    BottommostItemInCurrentView = ListView.getBottommostItemInCurrentView,
    CurSelectedIndex = ListView.getCurSelectedIndex
});
ListView.stor({
    ItemModel = ListView.setItemModel,
    Gravity = ListView.setGravity,
    MagneticType = ListView.setMagneticType,
    MagneticAllowedOutOfBoundary = ListView.setMagneticAllowedOutOfBoundary,
    ItemsMargin = ListView.setItemsMargin,
    LeftPadding = ListView.setLeftPadding,
    TopPadding = ListView.setTopPadding,
    RightPadding = ListView.setRightPadding,
    BottomPadding = ListView.setBottomPadding,
    ScrollDuration = ListView.setScrollDuration,
    CurSelectedIndex = ListView.setCurSelectedIndex
});

local PageView = ccui.PageView;
PageView.gtor({
    CurrentPageIndex = PageView.getCurrentPageIndex,
    IndicatorEnabled = PageView.getIndicatorEnabled,
    IndicatorPositionAsAnchorPoint = PageView.getIndicatorPositionAsAnchorPoint,
    IndicatorPosition = PageView.getIndicatorPosition,
    IndicatorSpaceBetweenIndexNodes = PageView.getIndicatorSpaceBetweenIndexNodes,
    IndicatorSelectedIndexColor = PageView.getIndicatorSelectedIndexColor,
    IndicatorIndexNodesColor = PageView.getIndicatorIndexNodesColor,
    getIndicatorSelectedIndexOpacity = PageView.getIndicatorSelectedIndexOpacity,
    IndicatorIndexNodesOpacity = PageView.getIndicatorIndexNodesOpacity,
    IndicatorIndexNodesScale = PageView.getIndicatorIndexNodesScale
});
PageView.stor({
    CurrentPageIndex = PageView.setCurrentPageIndex,
    IndicatorEnabled = PageView.setIndicatorEnabled,
    IndicatorPositionAsAnchorPoint = PageView.setIndicatorPositionAsAnchorPoint,
    IndicatorPosition = PageView.setIndicatorPosition,
    IndicatorSpaceBetweenIndexNodes = PageView.setIndicatorSpaceBetweenIndexNodes,
    IndicatorSelectedIndexColor = PageView.setIndicatorSelectedIndexColor,
    IndicatorIndexNodesColor = PageView.setIndicatorIndexNodesColor,
    getIndicatorSelectedIndexOpacity = PageView.setIndicatorSelectedIndexOpacity,
    IndicatorIndexNodesOpacity = PageView.setIndicatorIndexNodesOpacity,
    IndicatorIndexNodesScale = PageView.setIndicatorIndexNodesScale,
    IndicatorIndexNodesTexture = PageView.setIndicatorIndexNodesTexture,
    AutoScrollStopEpsilon = PageView.setAutoScrollStopEpsilon
});

local Button = ccui.Button;
Button.gtor({
    CapInsetsNormalRenderer = Button.getCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = Button.getCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = Button.getCapInsetsDisabledRenderer,
    Scale9Enabled = Button.isScale9Enabled,
    TitleRenderer = Button.getTitleRenderer,
    TitleText = Button.getTitleText,
    Text = Button.getTitleText,
    TitleColor = Button.getTitleColor,
    TitleFontSize = Button.getTitleFontSize,
    TitleFontName = Button.getTitleFontName,
    TitleLabel = Button.getTitleLabel,
    ZoomScale = Button.getZoomScale,
    RendererNormal = Button.getRendererNormal,
    RendererClicked = Button.getRendererClicked,
    RendererDisabled = Button.getRendererDisabled,
    NormalFile = Button.getNormalFile,
    PressedFile = Button.getPressedFile,
    DisabledFile = Button.getDisabledFile
});
Button.stor({
    CapInsets = Button.setCapInsets,
    CapInsetsNormalRenderer = Button.setCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = Button.setCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = Button.setCapInsetsDisabledRenderer,
    Scale9Enabled = Button.setScale9Enabled,
    PressedActionEnabled = Button.setPressedActionEnabled,
    TitleText = Button.setTitleText,
    TitleColor = Button.setTitleColor,
    TitleFontSize = Button.setTitleFontSize,
    TitleFontName = Button.setTitleFontName,
    TitleAlignment = Button.setTitleAlignment,
    TitleLabel = Button.setTitleLabel,
    ZoomScale = Button.setZoomScale
});

local AbstractCheckButton = ccui.AbstractCheckButton;
AbstractCheckButton.gtor({
    Selected = AbstractCheckButton.isSelected,
    ZoomScale = AbstractCheckButton.getZoomScale,
    RendererBackground = AbstractCheckButton.getRendererBackground,
    RendererBackgroundSelected = AbstractCheckButton.getRendererBackgroundSelected,
    RendererFrontCross = AbstractCheckButton.getRendererFrontCross,
    RendererBackgroundDisabled = AbstractCheckButton.getRendererBackgroundDisabled,
    RendererFrontCrossDisabled = AbstractCheckButton.getRendererFrontCrossDisabled,
    BackNormalFile = AbstractCheckButton.getBackNormalFile,
    BackPressedFile = AbstractCheckButton.getBackPressedFile,
    BackDisabledFile = AbstractCheckButton.getBackDisabledFile,
    CrossNormalFile = AbstractCheckButton.getCrossNormalFile,
    CrossDisabledFile = AbstractCheckButton.getCrossDisabledFile
});
AbstractCheckButton.stor({
    Selected = AbstractCheckButton.setSelected,
    ZoomScale = AbstractCheckButton.setZoomScale
});

local ImageView = ccui.ImageView;
ImageView.gtor({
    Scale9Enabled = ImageView.isScale9Enabled,
    CapInsets = ImageView.getCapInsets,
    RenderFile = ImageView.getRenderFile,
    Renderer = ImageView.getRenderer,
    Grayed = function(self)
        return self.Renderer:getState() == Scale9Sprite.State.GRAY;
    end
});
ImageView.stor({
    TextureRect = ImageView.setTextureRect,
    Scale9Enabled = ImageView.setScale9Enabled,
    CapInsets = ImageView.setCapInsets,
    Grayed = function(self,val)
        if val then
            self.Renderer:setState(Scale9Sprite.State.GRAY);
        else
            self.Renderer:setState(Scale9Sprite.State.NORMAL);
        end
    end
});

local LoadingBar = ccui.LoadingBar;
LoadingBar.gtor({
    Direction = LoadingBar.getDirection,
    Percent = function(self)
        return LoadingBar.getPercent(self) / 100;
    end,
    Scale9Enabled = LoadingBar.isScale9Enabled,
    CapInsets = LoadingBar.getCapInsets,
    RenderFile = LoadingBar.getRenderFile
});
LoadingBar.stor({
    Direction = LoadingBar.setDirection,
    Percent = function(self,val)
        LoadingBar.setPercent(self,val * 100);
    end,
    Scale9Enabled = LoadingBar.setScale9Enabled,
    CapInsets = LoadingBar.setCapInsets
});

local RadioButtonGroup = ccui.RadioButtonGroup;
RadioButtonGroup.gtor({
    SelectedButtonIndex = RadioButtonGroup.getSelectedButtonIndex,
    NumberOfRadioButtons = RadioButtonGroup.getNumberOfRadioButtons,
    AllowedNoSelection = RadioButtonGroup.isAllowedNoSelection
});
RadioButtonGroup.stor({
    SelectedButton = RadioButtonGroup.setSelectedButton,
    SelectedButtonWithoutEvent = RadioButtonGroup.setSelectedButtonWithoutEvent,
    AllowedNoSelection = RadioButtonGroup.setAllowedNoSelection
});

local RichElement = ccui.RichElement;
RichElement.gtor({
});
RichElement.stor({
    Color = RichElement.setColor
});

local RichElementImage = ccui.RichElementImage;
RichElementImage.gtor({
});
RichElementImage.stor({
    Width = RichElementImage.setWidth,
    Height = RichElementImage.setHeight,
    Url = RichElementImage.setUrl
});

local RichText = ccui.RichText;
RichText.gtor({
    FontColor3B = RichText.getFontColor3B,
    AnchorFontColor3B = RichText.getAnchorFontColor3B,
    WrapMode = RichText.getWrapMode,
    HorizontalAlignment = RichText.getHorizontalAlignment,
    FontColor = RichText.getFontColor,
    FontSize = RichText.getFontSize,
    FontFace = RichText.getFontFace,
    AnchorFontColor = RichText.getAnchorFontColor,
    AnchorTextBoldEnabled = RichText.isAnchorTextBoldEnabled,
    AnchorTextItalicEnabled = RichText.isAnchorTextItalicEnabled,
    AnchorTextDelEnabled = RichText.isAnchorTextDelEnabled,
    AnchorTextUnderlineEnabled = RichText.isAnchorTextUnderlineEnabled,
    AnchorTextOutlineEnabled = RichText.isAnchorTextOutlineEnabled,
    AnchorTextOutlineColor3B = RichText.getAnchorTextOutlineColor3B,
    AnchorTextOutlineSize = RichText.getAnchorTextOutlineSize,
    AnchorTextShadowEnabled = RichText.isAnchorTextShadowEnabled,
    AnchorTextShadowColor3B = RichText.getAnchorTextShadowColor3B,
    AnchorTextShadowOffset = RichText.getAnchorTextShadowOffset,
    AnchorTextShadowBlurRadius = RichText.getAnchorTextShadowBlurRadius,
    AnchorTextGlowEnabled = RichText.isAnchorTextGlowEnabled,
    AnchorTextGlowColor3B = RichText.getAnchorTextGlowColor3B,
    Defaults = RichText.getDefaults
});
RichText.stor({
    VerticalSpace = RichText.setVerticalSpace,
    WrapMode = RichText.setWrapMode,
    HorizontalAlignment = RichText.setHorizontalAlignment,
    FontColor = RichText.setFontColor,
    FontSize = RichText.setFontSize,
    FontFace = RichText.setFontFace,
    AnchorFontColor = RichText.setAnchorFontColor,
    AnchorTextBoldEnabled = RichText.setAnchorTextBold,
    AnchorTextItalicEnabled = RichText.setAnchorTextItalic,
    AnchorTextDelEnabled = RichText.setAnchorTextDel,
    AnchorTextUnderlineEnabled = RichText.setAnchorTextUnderline,
    AnchorTextOutline = RichText.setAnchorTextOutline,
    AnchorTextShadow = RichText.setAnchorTextShadow,
    AnchorTextGlow = RichText.setAnchorTextGlow,
    Defaults = RichText.setDefaults
});

local Slider = ccui.Slider;
Slider.gtor({
    Scale9Enabled = Slider.isScale9Enabled,
    CapInsetsBarRenderer = Slider.getCapInsetsBarRenderer,
    CapInsetProgressBarRenderer = Slider.getCapInsetProgressBarRenderer,
    Percent = function(self)
        return Slider.getPercent(self) / 100;
    end,
    MaxPercent = function(self)
        return Slider.getMaxPercent(self) / 100;
    end,
    ZoomScale = Slider.getZoomScale,
    SlidBallNormalRenderer = Slider.getSlidBallNormalRenderer,
    SlidBallPressedRenderer = Slider.getSlidBallPressedRenderer,
    SlidBallDisabledRenderer = Slider.getSlidBallDisabledRenderer,
    SlidBallRenderer = Slider.getSlidBallRenderer,
    BackFile = Slider.getBackFile,
    ProgressBarFile = Slider.getProgressBarFile,
    BallNormalFile = Slider.getBallNormalFile,
    BallPressedFile = Slider.getBallPressedFile,
    BallDisabledFile = Slider.getBallDisabledFile
});
Slider.stor({
    Scale9Enabled = Slider.setScale9Enabled,
    CapInsets = Slider.setCapInsets,
    CapInsetsBarRenderer = Slider.setCapInsetsBarRenderer,
    CapInsetProgressBarRenderer = Slider.setCapInsetProgressBarRenderer,
    Percent = function(self,val)
        Slider.setPercent(self,val * 100);
    end,
    MaxPercent = function(self,val)
        Slider.setMaxPercent(self,val * 100);
    end,
    ZoomScale = Slider.setZoomScale
});

local TabHeader = ccui.TabHeader;
TabHeader.gtor({
    TitleRenderer = TabHeader.getTitleRenderer,
    TitleText = TabHeader.getTitleText,
    Text = TabHeader.getTitleText,
    TitleColor = TabHeader.getTitleColor,
    TitleFontSize = TabHeader.getTitleFontSize,
    TitleFontName = TabHeader.getTitleFontName,
    IndexInTabControl = TabHeader.getIndexInTabControl
});
TabHeader.stor({
    TitleText = TabHeader.setTitleText,
    Text = TabHeader.setTitleText,
    TitleColor = TabHeader.setTitleColor,
    TitleFontSize = TabHeader.setTitleFontSize,
    TitleFontName = TabHeader.setTitleFontName
});

local TabControl = ccui.TabControl;
TabControl.gtor({
    TabCount = TabControl.getTabCount,
    SelectedTabIndex = TabControl.getSelectedTabIndex,
    HeaderWidth = TabControl.getHeaderWidth,
    HeaderHeight = TabControl.getHeaderHeight,
    IgnoreHeadersTextureSize = TabControl.isIgnoreHeadersTextureSize,
    HeaderSelectedZoom = TabControl.getHeaderSelectedZoom,
    HeaderDockPlace = TabControl.getHeaderDockPlace
});
TabControl.stor({
    SelectTab = TabControl.setSelectTab,
    HeaderWidth = TabControl.setHeaderWidth,
    HeaderHeight = TabControl.setHeaderHeight,
    IgnoreHeadersTextureSize = TabControl.ignoreHeadersTextureSize,
    HeaderSelectedZoom = TabControl.setHeaderSelectedZoom,
    HeaderDockPlace = TabControl.setHeaderDockPlace
});

local Text = ccui.Text;
Text.gtor({
    String = Text.getString,
    Text = Text.getString,
    StringLength = Text.getStringLength,
    TextLength = Text.getStringLength,
    FontSize = Text.getFontSize,
    FontName = Text.getFontName,
    Type = Text.getType,
    TouchScaleChangeEnabled = Text.isTouchScaleChangeEnabled,
    AutoRenderSize = Text.getAutoRenderSize,
    TextAreaSize = Text.getTextAreaSize,
    TextHorizontalAlignment = Text.getTextHorizontalAlignment,
    TextVerticalAlignment = Text.getTextVerticalAlignment,
    TextColor = Text.getTextColor,
    ShadowEnabled = Text.isShadowEnabled,
    ShadowOffset = Text.getShadowOffset,
    ShadowBlurRadius = Text.getShadowBlurRadius,
    ShadowColor = Text.getShadowColor,
    OutlineSize = Text.getOutlineSize,
    LabelEffectType = Text.getLabelEffectType,
    EffectColor = Text.getEffectColor,
    BlendFunc = Text.getBlendFunc
});
Text.stor({
    String = Text.setString,
    Text = Text.setString,
    FontSize = Text.setFontSize,
    FontName = Text.setFontName,
    TouchScaleChangeEnabled = Text.setTouchScaleChangeEnabled,
    TextAreaSize = Text.setTextAreaSize,
    TextHorizontalAlignment = Text.setTextHorizontalAlignment,
    TextVerticalAlignment = Text.setTextVerticalAlignment,
    TextColor = Text.setTextColor,
    Shadow = function(self,bc)
        if bc then
            if "table" == type(bc) then
                Text.enableShadow(self,bc);
            else
                Text.enableShadow(self);
            end
        else
            Text.disableEffect(self,cc.LabelEffect.SHADOW);
        end
    end,
    Outline = function(self,bc)
        if bc then
            if "table" == type(bc) then
                Text.enableOutline(self,bc);
            else
                Text.enableOutline(self);
            end
        else
            Text.disableEffect(self,cc.LabelEffect.OUTLINE);
        end
    end,
    Glow = function(self,bc)
        if bc then
            if "table" == type(bc) then
                Text.enableGlow(self,bc);
            else
                Text.enableGlow(self);
            end
        else
            Text.disableEffect(self,cc.LabelEffect.GLOW);
        end
    end,
    BlendFunc = Text.setBlendFunc
});

local TextAtlas = ccui.TextAtlas;
TextAtlas.gtor({
    String = TextAtlas.getString,
    Text = TextAtlas.getString,
    StringLength = TextAtlas.getStringLength,
    RenderFile = TextAtlas.getRenderFile
});
TextAtlas.stor({
    String = TextAtlas.setString,
    Text = TextAtlas.setString
});

local TextBMFont = ccui.TextBMFont;
TextBMFont.gtor({
    String = TextBMFont.getString,
    Text = TextBMFont.getString,
    StringLength = TextBMFont.getStringLength,
    RenderFile = TextBMFont.getRenderFile
});
TextBMFont.stor({
    String = TextBMFont.setString,
    Text = TextBMFont.setString
});

local TextField = ccui.TextField;
TextField.gtor({
    TouchSize = TextField.getTouchSize,
    PlaceHolder = TextField.getPlaceHolder,
    PlaceholderColor = TextField.getPlaceholderColor,
    TextColor = TextField.getTextColor,
    FontSize = TextField.getFontSize,
    FontName = TextField.getFontName,
    String = TextField.getString,
    Text = TextField.getString,
    MaxLengthEnabled = TextField.isMaxLengthEnabled,
    MaxLength = TextField.getMaxLength,
    StringLength = TextField.getStringLength,
    PasswordEnabled = TextField.isPasswordEnabled,
    PasswordStyleText = TextField.getPasswordStyleText,
    AttachWithIME = TextField.getAttachWithIME,
    DetachWithIME = TextField.getDetachWithIME,
    InsertText = TextField.getInsertText,
    DeleteBackward = TextField.getDeleteBackward,
    AutoRenderSize = TextField.getAutoRenderSize,
    TextHorizontalAlignment = TextField.getTextHorizontalAlignment,
    TextVerticalAlignment = TextField.getTextVerticalAlignment
});
TextField.stor({
    TouchSize = TextField.setTouchSize,
    TouchAreaEnabled = TextField.setTouchAreaEnabled,
    PlaceHolder = TextField.setPlaceHolder,
    PlaceholderColor = TextField.setPlaceholderColor,
    TextColor = TextField.setTextColor,
    FontSize = TextField.setFontSize,
    FontName = TextField.setFontName,
    String = TextField.setString,
    Text = TextField.setString,
    MaxLengthEnabled = TextField.setMaxLengthEnabled,
    MaxLength = TextField.setMaxLength,
    StringLength = TextField.setStringLength,
    PasswordEnabled = TextField.setPasswordEnabled,
    PasswordStyleText = TextField.setPasswordStyleText,
    AttachWithIME = TextField.setAttachWithIME,
    DetachWithIME = TextField.setDetachWithIME,
    InsertText = TextField.setInsertText,
    DeleteBackward = TextField.setDeleteBackward,
    TextAreaSize = TextField.setTextAreaSize,
    TextHorizontalAlignment = TextField.setTextHorizontalAlignment,
    TextVerticalAlignment = TextField.setTextVerticalAlignment,
    CursorEnabled = TextField.setCursorEnabled,
    CursorChar = TextField.setCursorChar,
    CursorPosition = TextField.setCursorPosition
});

local VideoPlayer = ccui.VideoPlayer;
VideoPlayer.gtor({
    FileName = VideoPlayer.GetFileName,
    File = VideoPlayer.GetFileName,
    Url = VideoPlayer.GetURL,
    Playing = VideoPlayer.IsPlaying,
    Looping = VideoPlayer.IsLooping,
    UserInputEnabled = VideoPlayer.IsUserInputEnabled,
    KeepAspectRatioEnabled = VideoPlayer.IsKeepAspectRatioEnabled,
    FullScreenEnabled = VideoPlayer.IsFullScreenEnabled
});
VideoPlayer.stor({
    FileName = VideoPlayer.SetFileName,
    File = VideoPlayer.SetFileName,
    Url = VideoPlayer.SetURL,
    Looping = VideoPlayer.SetLooping,
    UserInputEnabled = VideoPlayer.SetUserInputEnabled,
    Style = VideoPlayer.SetStyle,
    KeepAspectRatioEnabled = VideoPlayer.SetKeepAspectRatioEnabled,
    FullScreenEnabled = VideoPlayer.SetFullScreenEnabled,
    EventHandler = VideoPlayer.AddEventListener
});

local WebView = ccui.WebView;
WebView.gtor({
    OpacityWebView = WebView.getOpacityWebView
});
WebView.stor({
    JavascriptInterfaceScheme = WebView.setJavascriptInterfaceScheme,
    ScalesPageToFit = WebView.setScalesPageToFit,
    OpacityWebView = WebView.setOpacityWebView,
    BackgroundTransparent = WebView.setBackgroundTransparent,
    FinishHandler = WebView.setOnDidFinishLoading,
    FailHandler = WebView.setOnDidFailLoading,
    StartHandler = WebView.setOnShouldStartLoading,
    JsHandler = WebView.setOnJSCallback,
    Url = WebView.loadURL,
    File = WebView.loadFile
});

local QrCode = ccui.QrCode;
QrCode.gtor({
});
QrCode.stor({
    String = QrCode.LoadCodeByString
});

local EventController = cc.EventController;
EventController.gtor({
    ControllerEventType = EventController.getControllerEventType,
    Controller = EventController.getController,
    KeyCode = EventController.getKeyCode,
    Connected = EventController.isConnected
});
EventController.stor({
    KeyCode = EventController.setKeyCode,
    ConnectStatus = EventController.setConnectStatus,
    Connected = EventController.setConnectStatus
});

local XMLHttpRequest = cc.XMLHttpRequest;
XMLHttpRequest.gtor({
});
XMLHttpRequest.stor({
    Aborted = XMLHttpRequest.setAborted
});