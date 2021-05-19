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

--[[
    Func:   cocos2dx Lua导出类的gtor stor及其一些Cocos2dx扩展功能函数等。
    Auth:   wzhengsen
    Data:   2020.02.16
]]
local cc = cc;
local ccui = ccui;
local type = type;

local LuaObject = cc.LuaObject;
function LuaObject.__properties__()
    return {
        r = {
        },
        w = {
            DtorHandler = LuaObject.SetDtorHandler
        }
    };
end

local Ref = cc.Ref;
function Ref.__properties__()
    return {
    r = {
    ReferenceCount = Ref.GetReferenceCount
    },
    w = {
    }};
end

local Node = cc.Node;
function Node.__properties__()
    return {
    r = {
    LocalZ = Node.GetLocalZOrder,
    GlobalZ = Node.GetGlobalZOrder,
    ScaleX = Node.GetScaleX,
    ScaleY = Node.GetScaleY,
    Scale = Node.GetScale,
    X = Node.GetPositionX,
    Y = Node.GetPositionY,
    XY = Node.GetPositionXY,
    Width = Node.GetContentWidth,
    Height = Node.GetContentHeight,
    PositionNormalized = Node.GetPositionNormalized,
    SkewX = Node.GetSkewX,
    SkewY = Node.GetSkewY,
    AnchorPoint = Node.GetAnchorPoint,
    AnchorPointInPoints = Node.GetAnchorPointInPoints,
    Size = Node.GetContentSize,
    Visible = Node.IsVisible,
    Rotation = Node.GetRotation,
    RotationX = Node.GetRotationSkewX,
    RotationY = Node.GetRotationSkewY,
    Children = Node.GetChildren,
    ChildrenCount = Node.GetChildrenCount,
    Parent = Node.GetParent,
    Tag = Node.GetTag,
    Name = Node.GetName,
    Running = Node.IsRunning,
    Scene = Node.GetScene,
    BoundingBox = Node.GetBoundingBox,
    EventDispatcher = Node.GetEventDispatcher,
    ActionManager = Node.GetActionManager,
    NumberOfRunningActions = Node.GetNumberOfRunningActions,
    Scheduler = Node.GetScheduler,
    Opacity = Node.GetOpacity,
    DisplayedOpacity = Node.GetDisplayedOpacity,
    CascadeOpacityEnabled = Node.IsCascadeOpacityEnabled,
    Color = Node.GetColor,
    DisplayedColor = Node.GetDisplayedColor,
    CascadeColorEnabled = Node.IsCascadeColorEnabled,
    CameraMask = Node.GetCameraMask,
    PhysicsBody = Node.GetPhysicsBody,
    OpacityModifyRGB = Node.IsOpacityModifyRGB,
    ProgramState = Node.GetProgramState,
    OnEnterHandler = Node.GetOnEnterHandler,
    OnExitHandler = Node.GetOnExitHandler,
    OnEnterTransitionDidFinishHandler = Node.GetOnEnterTransitionDidFinishHandler,
    OnExitTransitionDidStartHandler = Node.GetOnExitTransitionDidStartHandler,
    OnCleanUpHandler = Node.GetOnCleanUpHandler,
    OnUpdateHandler = Node.GetOnUpdateHandler
    },
    w = {
    LocalZ = Node.SetLocalZOrder,
    GlobalZ = Node.SetGlobalZOrder,
    ScaleX = Node.SetScaleX,
    ScaleY = Node.SetScaleY,
    Scale = Node.SetScale,
    X = Node.SetPositionX,
    Y = Node.SetPositionY,
    XY = Node.SetPosition,
    Width = Node.SetContentWidth,
    Height = Node.SetContentHeight,
    PositionNormalized = Node.SetPositionNormalized,
    SkewX = Node.SetSkewX,
    SkewY = Node.SetSkewY,
    AnchorPoint = Node.SetAnchorPoint,
    Size = Node.SetContentSize,
    Visible = Node.SetVisible,
    Rotation = Node.SetRotation,
    RotationX = Node.SetRotationSkewX,
    RotationY = Node.SetRotationSkewY,
    Parent = function(self,p)
        if class.IsNull(p) then
            Node.removeFromParent(self);
        else
            local op = Node.GetParent(self);
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
    Tag = Node.SetTag,
    Name = Node.SetName,
    EventDispatcher = Node.SetEventDispatcher,
    ActionManager = Node.SetActionManager,
    Scheduler = Node.SetScheduler,
    Opacity = Node.SetOpacity,
    CascadeOpacityEnabled = Node.SetCascadeOpacityEnabled,
    Color = Node.SetColor,
    CascadeColorEnabled = Node.SetCascadeColorEnabled,
    CameraMask = Node.SetCameraMask,
    PhysicsBody = Node.SetPhysicsBody,
    OpacityModifyRGB = Node.SetOpacityModifyRGB,
    ProgramState = Node.SetProgramState,
    OnEnterHandler = Node.SetOnEnterHandler,
    OnExitHandler = Node.SetOnExitHandler,
    OnEnterTransitionDidFinishHandler = Node.SetOnEnterTransitionDidFinishHandler,
    OnExitTransitionDidStartHandler = Node.SetOnExitTransitionDidStartHandler,
    OnCleanUpHandler = Node.SetOnCleanUpHandler,
    OnUpdateHandler = Node.SetOnUpdateHandler
    }};
end

local Action = cc.Action;
function Action.__properties__()
    return {
    r = {
    Done = Action.IsDone,
    Target = Action.GetTarget,
    OriginalTarget = Action.GetOriginalTarget,
    Tag = Action.GetTag,
    Flags = Action.GetFlags
    },
    w = {
    Target = Action.GetTarget,
    OriginalTarget = Action.SetOriginalTarget,
    Tag = Action.SetTag,
    Flags = Action.SetFlags
    }};
end

local FiniteTimeAction = cc.FiniteTimeAction;
function FiniteTimeAction.__properties__()
    return {
    r = {
    Duration = FiniteTimeAction.GetDuration
    },
    w = {
    Duration = FiniteTimeAction.SetDuration
    }};
end

local Speed = cc.Speed;
function Speed.__properties__()
    return {
    r = {
    Speed = Speed.GetSpeed,
    InnerAction = Speed.GetInnerAction
    },
    w = {
    Speed = Speed.SetSpeed,
    InnerAction = Speed.SetInnerAction
    }};
end

local Follow = cc.Follow;
function Follow.__properties__()
    return {
    r = {
    BoundarySet = Follow.IsBoundarySet
    },
    w = {
    BoundarySet = Follow.SetBoundarySet
    }};
end

local ActionInterval = cc.ActionInterval;
function ActionInterval.__properties__()
    return {
    r = {
    Elapsed = ActionInterval.GetElapsed,
    AmplitudeRate = ActionInterval.GetAmplitudeRate
    },
    w = {
    AmplitudeRate = ActionInterval.SetAmplitudeRate
    }};
end

local Animate = cc.Animate;
function Animate.__properties__()
    return {
    r = {
    Animation = Animate.GetAnimation,
    CurrentFrameIndex = Animate.GetCurrentFrameIndex
    },
    w = {
    Animation = Animate.SetAnimation
    }};
end

local TargetedAction = cc.TargetedAction;
function TargetedAction.__properties__()
    return {
    r = {
    ForcedTarget = TargetedAction.GetForcedTarget
    },
    w = {
    ForcedTarget = TargetedAction.SetForcedTarget
    }};
end

local EaseRateAction = cc.EaseRateAction;
function EaseRateAction.__properties__()
    return {
    r = {
    Rate = EaseRateAction.GetRate
    },
    w = {
    Rate = EaseRateAction.SetRate
    }};
end

local EaseElastic = cc.EaseElastic;
function EaseElastic.__properties__()
    return {
    r = {
    Period = EaseElastic.GetPeriod
    },
    w = {
    Period = EaseElastic.SetPeriod
    }};
end

local GridAction = cc.GridAction;
function GridAction.__properties__()
    return {
    r = {
    Grid = GridAction.GetGrid
    },
    w = {
    }};
end

local Waves3D = cc.Waves3D;
function Waves3D.__properties__()
    return {
    r = {
    Amplitude = Waves3D.GetAmplitude,
    AmplitudeRate = Waves3D.GetAmplitudeRate
    },
    w = {
    Amplitude = Waves3D.SetAmplitude,
    AmplitudeRate = Waves3D.SetAmplitudeRate
    }};
end

local Lens3D = cc.Lens3D;
function Lens3D.__properties__()
    return {
    r = {
    LensEffect = Lens3D.GetLensEffect,
    Position = Lens3D.GetPosition
    },
    w = {
    LensEffect = Lens3D.SetLensEffect,
    Concave = Lens3D.SetConcave,
    Position = Lens3D.SetPosition
    }};
end

local Ripple3D = cc.Ripple3D;
function Ripple3D.__properties__()
    return {
    r = {
    Amplitude = Ripple3D.GetAmplitude,
    AmplitudeRate = Ripple3D.GetAmplitudeRate,
    Position = Ripple3D.GetPosition
    },
    w = {
    Amplitude = Ripple3D.SetAmplitude,
    AmplitudeRate = Ripple3D.SetAmplitudeRate,
    Position = Ripple3D.SetPosition
    }};
end

local Liquid = cc.Liquid;
function Liquid.__properties__()
    return {
    r = {
    Amplitude = Liquid.GetAmplitude,
    AmplitudeRate = Liquid.GetAmplitudeRate
    },
    w = {
    Amplitude = Liquid.SetAmplitude,
    AmplitudeRate = Liquid.SetAmplitudeRate
    }};
end

local Waves = cc.Waves;
function Waves.__properties__()
    return {
    r = {
    Amplitude = Waves.GetAmplitude,
    AmplitudeRate = Waves.GetAmplitudeRate
    },
    w = {
    Amplitude = Waves.SetAmplitude,
    AmplitudeRate = Waves.SetAmplitudeRate
    }};
end

local Twirl = cc.Ripple3D;
function Twirl.__properties__()
    return {
    r = {
    Amplitude = Twirl.GetAmplitude,
    AmplitudeRate = Twirl.GetAmplitudeRate,
    Position = Twirl.GetPosition
    },
    w = {
    Amplitude = Twirl.SetAmplitude,
    AmplitudeRate = Twirl.SetAmplitudeRate,
    Position = Twirl.SetPosition
    }};
end

local WavesTiles3D = cc.WavesTiles3D;
function WavesTiles3D.__properties__()
    return {
    r = {
    Amplitude = WavesTiles3D.GetAmplitude,
    AmplitudeRate = WavesTiles3D.GetAmplitudeRate
    },
    w = {
    Amplitude = WavesTiles3D.SetAmplitude,
    AmplitudeRate = WavesTiles3D.SetAmplitudeRate
    }};
end

local JumpTiles3D = cc.WavesTiles3D;
function JumpTiles3D.__properties__()
    return {
    r = {
    Amplitude = JumpTiles3D.GetAmplitude,
    AmplitudeRate = JumpTiles3D.GetAmplitudeRate
    },
    w = {
    Amplitude = JumpTiles3D.SetAmplitude,
    AmplitudeRate = JumpTiles3D.SetAmplitudeRate
    }};
end

local SpriteFrame = cc.SpriteFrame;
function SpriteFrame.__properties__()
    return {
    r = {
    RectInPixels = SpriteFrame.GetRectInPixels,
    Rotated = SpriteFrame.IsRotated,
    Rect = SpriteFrame.GetRect,
    CenterRect = SpriteFrame.GetCenterRect,
    HasCenterRect = SpriteFrame.HasCenterRect,
    OffsetInPixels = SpriteFrame.GetOffsetInPixels,
    OriginalSizeInPixels = SpriteFrame.GetOriginalSizeInPixels,
    OriginalSize = SpriteFrame.GetOriginalSize,
    Texture = SpriteFrame.GetTexture,
    Offset = SpriteFrame.GetOffset,
    AnchorPoint = SpriteFrame.GetAnchorPoint,
    HasAnchorPoint = SpriteFrame.HasAnchorPoint,
    },
    w = {
    RectInPixels = SpriteFrame.SetRectInPixels,
    setRotated = SpriteFrame.SetRotated,
    Rect = SpriteFrame.SetRect,
    CenterRectInPixels = SpriteFrame.SetCenterRectInPixels,
    OffsetInPixels = SpriteFrame.SetOffsetInPixels,
    OriginalSizeInPixels = SpriteFrame.SetOriginalSizeInPixels,
    OriginalSize = SpriteFrame.SetOriginalSize,
    Texture = SpriteFrame.SetTexture,
    Offset = SpriteFrame.SetOffset,
    AnchorPoint = SpriteFrame.SetAnchorPoint,
    }};
end

local AnimationFrame = cc.AnimationFrame;
function AnimationFrame.__properties__()
    return {
    r = {
    SpriteFrame = AnimationFrame.GetSpriteFrame,
    DelayUnits = AnimationFrame.GetDelayUnits,
    UserInfo = AnimationFrame.GetUserInfo
    },
    w = {
    SpriteFrame = AnimationFrame.SetSpriteFrame,
    DelayUnits = AnimationFrame.SetDelayUnits,
    UserInfo = AnimationFrame.SetUserInfo
    }};
end

local Animation = cc.Animation;
function Animation.__properties__()
    return {
    r = {
    TotalDelayUnits = Animation.GetTotalDelayUnits,
    DelayPerUnit = Animation.GetDelayPerUnit,
    Duration = Animation.GetDuration,
    Frames = Animation.GetFrames,
    RestoreOriginalFrame = Animation.GetRestoreOriginalFrame,
    Loops = Animation.GetLoops
    },
    w = {
    DelayPerUnit = Animation.SetDelayPerUnit,
    Frames = Animation.SetFrames,
    RestoreOriginalFrame = Animation.SetRestoreOriginalFrame,
    Loops = Animation.SetLoops
    }};
end

local AtlasNode = cc.AtlasNode;
function AtlasNode.__properties__()
    return {
    r = {
    TextureAtlas = AtlasNode.GetTextureAtlas,
    QuadsToDraw = AtlasNode.GetQuadsToDraw,
    Texture = AtlasNode.GetTexture,
    BlendFunc = AtlasNode.GetBlendFunc
    },
    w = {
    TextureAtlas = AtlasNode.SetTextureAtlas,
    QuadsToDraw = AtlasNode.SetQuadsToDraw,
    Texture = AtlasNode.SetTexture,
    BlendFunc = AtlasNode.SetBlendFunc
    }};
end

local Camera = cc.Camera;
function Camera.__properties__()
    return {
    r = {
    Type = Camera.GetType,
    CameraFlag = Camera.GetCameraFlag,
    ProjectionMatrix = Camera.GetProjectionMatrix,
    ViewMatrix = Camera.GetViewMatrix,
    ViewProjectionMatrix = Camera.GetViewProjectionMatrix,
    Depth = Camera.GetDepth,
    RenderOrder = Camera.GetRenderOrder,
    FarPlane = Camera.GetFarPlane,
    NearPlane = Camera.GetNearPlane,
    ViewProjectionUpdated = Camera.IsViewProjectionUpdated,
    BackgroundBrush = Camera.GetBackgroundBrush,
    BrushValid = Camera.IsBrushValid
    },
    w = {
    CameraFlag = Camera.SetCameraFlag,
    Depth = Camera.SetDepth,
    FrameBufferObject = Camera.SetFrameBufferObject,
    Viewport = Camera.SetViewport,
    BackgroundBrush = Camera.SetBackgroundBrush,
    Scene = Camera.SetScene,
    AdditionalProjection = Camera.SetAdditionalProjection
    }};
end

local CameraBackgroundBrush = cc.CameraBackgroundBrush;
function CameraBackgroundBrush.__properties__()
    return {
    r = {
    BrushType = CameraBackgroundBrush.GetBrushType,
    Valid = CameraBackgroundBrush.IsValid
    },
    w = {
    }};
end

local CameraBackgroundDepthBrush = cc.CameraBackgroundDepthBrush;
function CameraBackgroundDepthBrush.__properties__()
    return {
    r = {
    },
    w = {
    Depth = CameraBackgroundDepthBrush.SetDepth
    }};
end

local CameraBackgroundColorBrush = cc.CameraBackgroundColorBrush;
function CameraBackgroundColorBrush.__properties__()
    return {
    r = {
    },
    w = {
    Color = CameraBackgroundColorBrush.SetColor
    }};
end

local CameraBackgroundSkyBoxBrush = cc.CameraBackgroundSkyBoxBrush;
function CameraBackgroundSkyBoxBrush.__properties__()
    return {
    r = {
    },
    w = {
    Texture = CameraBackgroundSkyBoxBrush.SetTexture
    }};
end

local ClippingNode = cc.ClippingNode;
function ClippingNode.__properties__()
    return {
    r = {
    Stencil = ClippingNode.GetStencil,
    Content = ClippingNode.HasContent,
    AlphaThreshold = ClippingNode.GetAlphaThreshold,
    Inverted = ClippingNode.IsInverted
    },
    w = {
    Stencil = ClippingNode.SetStencil,
    AlphaThreshold = ClippingNode.SetAlphaThreshold,
    Inverted = ClippingNode.SetInverted
    }};
end

local ClippingRectangleNode = cc.ClippingRectangleNode;
function ClippingRectangleNode.__properties__()
    return {
    r = {
    ClippingRegion = ClippingRectangleNode.GetClippingRegion,
    ClippingEnabled = ClippingRectangleNode.IsClippingEnabled
    },
    w = {
    ClippingRegion = ClippingRectangleNode.SetClippingRegion,
    ClippingEnabled = ClippingRectangleNode.SetClippingEnabled
    }};
end

local Component = cc.Component;
function Component.__properties__()
    return {
    r = {
    Enabled = Component.IsEnabled,
    Name = Component.GetName,
    Owner = Component.GetOwner
    },
    w = {
    Enabled = Component.SetEnabled,
    Name = Component.SetName,
    Owner = Component.SetOwner
    }};
end

local DrawNode = cc.DrawNode;
function DrawNode.__properties__()
    return {
    r = {
    BlendFunc = DrawNode.GetBlendFunc,
    LineWidth = DrawNode.GetLineWidth,
    Isolated = DrawNode.IsIsolated
    },
    w = {
    BlendFunc = DrawNode.SetBlendFunc,
    LineWidth = DrawNode.SetLineWidth,
    Isolated = DrawNode.SetIsolated
    }};
end

-- cc.FastTMXLayer
local FastTMXLayer = cc.FastTMXLayer;
function FastTMXLayer.__properties__()
    return {
    r = {
    LayerName = FastTMXLayer.GetLayerName,
    LayerSize = FastTMXLayer.GetLayerSize,
    MapTileSize = FastTMXLayer.GetMapTileSize,
    TileSet = FastTMXLayer.GetTileSet,
    LayerOrientation = FastTMXLayer.GetLayerOrientation,
    Properties = FastTMXLayer.GetProperties
    },
    w = {
    LayerName = FastTMXLayer.SetLayerName,
    LayerSize = FastTMXLayer.SetLayerSize,
    MapTileSize = FastTMXLayer.SetMapTileSize,
    TileSet = FastTMXLayer.SetTileSet,
    LayerOrientation = FastTMXLayer.SetLayerOrientation,
    Properties = FastTMXLayer.SetProperties
    }};
end


-- cc.FastTMXTiledMap
local FastTMXTiledMap = cc.FastTMXTiledMap;
function FastTMXTiledMap.__properties__()
    return {
    r = {
    MapSize = FastTMXTiledMap.GetMapSize,
    TileSize = FastTMXTiledMap.GetTileSize,
    MapOrientation = FastTMXTiledMap.GetMapOrientation,
    ObjectGroups = FastTMXTiledMap.GetObjectGroups,
    Properties = FastTMXTiledMap.GetProperties
    },
    w = {
    MapSize = FastTMXTiledMap.SetMapSize,
    TileSize = FastTMXTiledMap.SetTileSize,
    MapOrientation = FastTMXTiledMap.SetMapOrientation,
    ObjectGroups = FastTMXTiledMap.SetObjectGroups,
    Properties = FastTMXTiledMap.SetProperties
    }};
end

local TMXObjectGroup = cc.TMXObjectGroup;
function TMXObjectGroup.__properties__()
    return {
    r = {
    GroupName = TMXObjectGroup.GetGroupName,
    PositionOffset = TMXObjectGroup.GetPositionOffset,
    Properties = TMXObjectGroup.GetProperties,
    Objects = TMXObjectGroup.GetObjects,
    },
    w = {
    GroupName = TMXObjectGroup.SetGroupName,
    PositionOffset = TMXObjectGroup.SetPositionOffset,
    Properties = TMXObjectGroup.SetProperties,
    Objects = TMXObjectGroup.SetObjects,
    }};
end

local TMXLayerInfo = cc.TMXLayerInfo;
function TMXLayerInfo.__properties__()
    return {
    r = {
    Properties = TMXLayerInfo.GetProperties
    },
    w = {
    Properties = TMXLayerInfo.SetProperties
    }};
end

local TMXMapInfo = cc.TMXMapInfo;
function TMXMapInfo.__properties__()
    return {
    r = {
    TileProperties = TMXMapInfo.GetTileProperties,
    Orientation = TMXMapInfo.GetOrientation,
    StaggerAxis = TMXMapInfo.GetStaggerAxis,
    StaggerIndex = TMXMapInfo.GetStaggerIndex,
    HexSideLength = TMXMapInfo.GetHexSideLength,
    MapSize = TMXMapInfo.GetMapSize,
    TileSize = TMXMapInfo.GetTileSize,
    Layers = TMXMapInfo.GetLayers,
    Tilesets = TMXMapInfo.GetTilesets,
    ObjectGroups = TMXMapInfo.GetObjectGroups,
    ParentElement = TMXMapInfo.GetParentElement,
    ParentGID = TMXMapInfo.GetParentGID,
    LayerAttribs = TMXMapInfo.GetLayerAttribs,
    StoringCharacters = TMXMapInfo.IsStoringCharacters,
    Properties = TMXMapInfo.GetProperties
    },
    w = {
    TileProperties = TMXMapInfo.SetTileProperties,
    Orientation = TMXMapInfo.SetOrientation,
    StaggerAxis = TMXMapInfo.SetStaggerAxis,
    StaggerIndex = TMXMapInfo.SetStaggerIndex,
    HexSideLength = TMXMapInfo.SetHexSideLength,
    MapSize = TMXMapInfo.SetMapSize,
    TileSize = TMXMapInfo.SetTileSize,
    Layers = TMXMapInfo.SetLayers,
    Tilesets = TMXMapInfo.SetTilesets,
    ObjectGroups = TMXMapInfo.SetObjectGroups,
    ParentElement = TMXMapInfo.SetParentElement,
    ParentGID = TMXMapInfo.SetParentGID,
    LayerAttribs = TMXMapInfo.SetLayerAttribs,
    StoringCharacters = TMXMapInfo.SetStoringCharacters,
    Properties = TMXMapInfo.SetProperties
    }};
end

local GridBase = cc.GridBase;
function GridBase.__properties__()
    return {
    r = {
    Active = GridBase.IsActive,
    ReuseGrid = GridBase.GetReuseGrid,
    GridSize = GridBase.GetGridSize,
    Step = GridBase.GetStep,
    TextureFlipped = GridBase.IsTextureFlipped,
    GridRect = GridBase.GetGridRect
    },
    w = {
    Active = GridBase.SetActive,
    ReuseGrid = GridBase.SetReuseGrid,
    GridSize = GridBase.SetGridSize,
    Step = GridBase.SetStep,
    TextureFlipped = GridBase.SetTextureFlipped,
    GridRect = GridBase.SetGridRect
    }};
end

local Grid3D = cc.Grid3D;
function Grid3D.__properties__()
    return {
    r = {
    NeedDepthTestForBlit = Grid3D.GetNeedDepthTestForBlit
    },
    w = {
    NeedDepthTestForBlit = Grid3D.SetNeedDepthTestForBlit
    }};
end

local Label = cc.Label;
function Label.__properties__()
    return {
    r = {
    TTFConfig = Label.GetTTFConfig,
    BMFontFilePath = Label.GetBMFontFilePath,
    SystemFontName = Label.GetSystemFontName,
    SystemFontSize = Label.GetSystemFontSize,
    String = Label.GetString,
    Text = Label.GetString,
    StringNumLines = Label.GetStringNumLines,
    TextNumLines = Label.GetStringNumLines,
    StringLength = Label.GetStringLength,
    TextLength = Label.GetStringLength,
    TextColor = Label.GetTextColor,
    ShadowEnabled = Label.IsShadowEnabled,
    ShadowOffset = Label.GetShadowOffset,
    ShadowBlurRadius = Label.GetShadowBlurRadius,
    ShadowColor = Label.GetShadowColor,
    OutlineSize = Label.GetOutlineSize,
    LabelEffectType = Label.GetLabelEffectType,
    EffectColor = Label.GetEffectColor,
    TextAlignment = Label.GetTextAlignment,
    HorizontalAlignment = Label.GetHorizontalAlignment,
    VerticalAlignment = Label.GetVerticalAlignment,
    MaxLineWidth = Label.GetMaxLineWidth,
    BMFontSize = Label.GetBMFontSize,
    Wrap = Label.IsWrapEnabled,
    Overflow = Label.GetOverflow,
    LabelWidth = Label.GetWidth,
    LabelHeight = Label.GetHeight,
    Dimensions = Label.GetDimensions,
    ClipMarginEnabled = Label.IsClipMarginEnabled,
    LineHeight = Label.GetLineHeight,
    LineSpacing = Label.GetLineSpacing,
    LabelType = Label.GetLabelType,
    RenderingFontSize = Label.GetRenderingFontSize,
    AdditionalKerning = Label.GetAdditionalKerning,
    BlendFunc = Label.GetBlendFunc
    },
    w = {
    TTFConfig = Label.SetTTFConfig,
    SystemFontName = Label.SetSystemFontName,
    SystemFontSize = Label.SetSystemFontSize,
    String = Label.SetString,
    Text = Label.SetString,
    TextColor = Label.SetTextColor,
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
    Alignment = Label.SetAlignment,
    HorizontalAlignment = Label.SetHorizontalAlignment,
    VerticalAlignment = Label.SetVerticalAlignment,
    LineBreakWithoutSpace = Label.SetLineBreakWithoutSpace,
    MaxLineWidth = Label.SetMaxLineWidth,
    BMFontSize = Label.SetBMFontSize,
    Wrap = Label.EnableWrap,
    Overflow = Label.SetOverflow,
    LabelWidth = Label.SetWidth,
    LabelHeight = Label.SetHeight,
    Dimensions = Label.SetDimensions,
    ClipMarginEnabled = Label.SetClipMarginEnabled,
    LineHeight = Label.SetLineHeight,
    LineSpacing = Label.SetLineSpacing,
    AdditionalKerning = Label.SetAdditionalKerning,
    BlendFunc = Label.SetBlendFunc
    }};
end

local LabelAtlas = cc.LabelAtlas;
function LabelAtlas.__properties__()
    return {
    r = {
    String = LabelAtlas.GetString,
    Text = LabelAtlas.GetString
    },
    w = {
    String = LabelAtlas.SetString,
    Text = LabelAtlas.SetString
    }};
end

local LayerColor = cc.LayerColor;
function LayerColor.__properties__()
    return {
    r = {
    BlendFunc = LayerColor.GetBlendFunc
    },
    w = {
    BlendFunc = LayerColor.SetBlendFunc
    }};
end

local LayerGradient = cc.LayerGradient;
function LayerGradient.__properties__()
    return {
    r = {
    CompressedInterpolation = LayerGradient.IsCompressedInterpolation,
    StartColor = LayerGradient.GetStartColor,
    EndColor = LayerGradient.GetEndColor,
    StartOpacity = LayerGradient.GetStartOpacity,
    EndOpacity = LayerGradient.GetEndOpacity,
    Vector = LayerGradient.GetVector
    },
    w = {
    CompressedInterpolation = LayerGradient.SetCompressedInterpolation,
    StartColor = LayerGradient.SetStartColor,
    EndColor = LayerGradient.SetEndColor,
    StartOpacity = LayerGradient.SetStartOpacity,
    EndOpacity = LayerGradient.SetEndOpacity,
    Vector = LayerGradient.SetVector
    }};
end

local LayerRadialGradient = cc.LayerRadialGradient;
function LayerRadialGradient.__properties__()
    return {
    r = {
    BlendFunc = LayerRadialGradient.GetBlendFunc,
    StartColor = LayerRadialGradient.GetStartColor,
    EndColor = LayerRadialGradient.GetEndColor,
    StartOpacity = LayerRadialGradient.GetStartOpacity,
    EndOpacity = LayerRadialGradient.GetEndOpacity,
    Radius = LayerRadialGradient.GetRadius,
    Center = LayerRadialGradient.GetCenter,
    Expand = LayerRadialGradient.GetExpand
    },
    w = {
    BlendFunc = LayerRadialGradient.SetBlendFunc,
    StartColor = LayerRadialGradient.SetStartColor,
    EndColor = LayerRadialGradient.SetEndColor,
    StartOpacity = LayerRadialGradient.SetStartOpacity,
    EndOpacity = LayerRadialGradient.SetEndOpacity,
    Radius = LayerRadialGradient.SetRadius,
    Center = LayerRadialGradient.SetCenter,
    Expand = LayerRadialGradient.SetExpand
    }};
end

local Menu = cc.Menu;
function Menu.__properties__()
    return {
    r = {
    Enabled = Menu.IsEnabled
    },
    w = {
    Enabled = Menu.SetEnabled
    }};
end

local MenuItem = cc.MenuItem;
function MenuItem.__properties__()
    return {
    r = {
    Enabled = MenuItem.IsEnabled,
    Selected = MenuItem.IsSelected
    },
    w = {
    Enabled = MenuItem.SetEnabled,
    Selected = function(self,b)
        if b then
            MenuItem.selected(self);
        else
            MenuItem.unselected(self);
        end
    end
    }};
end

local MenuItemLabel = cc.MenuItemLabel;
function MenuItemLabel.__properties__()
    return {
    r = {
    String = MenuItemLabel.GetString,
    Text = MenuItemLabel.GetString,
    DisabledColor = MenuItemLabel.GetDisabledColor,
    Label = MenuItemLabel.GetLabel
    },
    w = {
    String = MenuItemLabel.SetString,
    Text = MenuItemLabel.SetString,
    DisabledColor = MenuItemLabel.SetDisabledColor,
    Label = MenuItemLabel.SetLabel
    }};
end

local MenuItemFont = cc.MenuItemFont;
function MenuItemFont.__properties__()
    return {
    r = {
    FontSize = MenuItemFont.GetFontSizeObj,
    FontName = MenuItemFont.GetFontNameObj
    },
    w = {
    FontSize = MenuItemFont.SetFontSizeObj,
    FontName = MenuItemFont.SetFontNameObj
    }};
end

local MenuItemSprite = cc.MenuItemSprite;
function MenuItemSprite.__properties__()
    return {
    r = {
    NormalImage = MenuItemSprite.GetNormalImage,
    SelectedImage = MenuItemSprite.GetSelectedImage,
    DisabledImage = MenuItemSprite.GetDisabledImage
    },
    w = {
    NormalImage = MenuItemSprite.SetNormalImage,
    SelectedImage = MenuItemSprite.SetSelectedImage,
    DisabledImage = MenuItemSprite.SetDisabledImage
    }};
end

local MenuItemImage = cc.MenuItemImage;
function MenuItemImage.__properties__()
    return {
    r = {
    },
    w = {
    NormalSpriteFrame = MenuItemImage.SetNormalSpriteFrame,
    SelectedSpriteFrame = MenuItemImage.SetSelectedSpriteFrame,
    DisabledSpriteFrame = MenuItemImage.SetDisabledSpriteFrame
    }};
end

local MenuItemToggle = cc.MenuItemToggle;
function MenuItemToggle.__properties__()
    return {
    r = {
    SelectedItem = MenuItemSprite.GetSelectedItem,
    SelectedIndex = MenuItemSprite.GetSelectedIndex,
    SubItems = MenuItemSprite.GetSubItems
    },
    w = {
    SelectedIndex = MenuItemSprite.SetSelectedIndex,
    SubItems = MenuItemSprite.SetSubItems
    }};
end

local MotionStreak = cc.MotionStreak;
function MotionStreak.__properties__()
    return {
    r = {
    FastMode = MotionStreak.IsFastMode,
    Stroke = MotionStreak.GetStroke,
    StartingPositionInitialized = MotionStreak.IsStartingPositionInitialized,
    Texture = MotionStreak.GetTexture,
    BlendFunc = MotionStreak.GetBlendFunc
    },
    w = {
    FastMode = MotionStreak.SetFastMode,
    Stroke = MotionStreak.SetStroke,
    StartingPositionInitialized = MotionStreak.SetStartingPositionInitialized,
    Texture = MotionStreak.SetTexture,
    BlendFunc = MotionStreak.SetBlendFunc
    }};
end

local NodeGrid = cc.NodeGrid;
function NodeGrid.__properties__()
    return {
    r = {
    Grid = NodeGrid.GetGrid,
    GridRect = NodeGrid.GetGridRect
    },
    w = {
    Grid = NodeGrid.SetGrid,
    Target = NodeGrid.SetTarget,
    GridRect = NodeGrid.SetGridRect
    }};
end

local ParticleBatchNode = cc.ParticleBatchNode;
function ParticleBatchNode.__properties__()
    return {
    r = {
    TextureAtlas = ParticleBatchNode.GetTextureAtlas,
    BlendFunc = ParticleBatchNode.GetBlendFunc,
    Texture = ParticleBatchNode.GetTexture
    },
    w = {
    TextureAtlas = ParticleBatchNode.SetTextureAtlas,
    BlendFunc = ParticleBatchNode.SetBlendFunc,
    Texture = ParticleBatchNode.SetTexture
    }};
end

local ParticleSystem = cc.ParticleSystem;
function ParticleSystem.__properties__()
    return {
    r = {
    Full = ParticleSystem.IsFull,
    AutoRemoveOnFinish = ParticleSystem.IsAutoRemoveOnFinish,
    Gravity = ParticleSystem.GetGravity,
    Speed = ParticleSystem.GetSpeed,
    SpeedVar = ParticleSystem.GetSpeedVar,
    TangentialAccel = ParticleSystem.GetTangentialAccel,
    TangentialAccelVar = ParticleSystem.GetTangentialAccelVar,
    RadialAccel = ParticleSystem.GetRadialAccel,
    RadialAccelVar = ParticleSystem.GetRadialAccelVar,
    RotationIsDir = ParticleSystem.GetRotationIsDir,
    StartRadius = ParticleSystem.GetStartRadius,
    StartRadiusVar = ParticleSystem.GetStartRadiusVar,
    EndRadius = ParticleSystem.GetEndRadius,
    EndRadiusVar = ParticleSystem.GetEndRadiusVar,
    RotatePerSecond = ParticleSystem.GetRotatePerSecond,
    RotatePerSecondVar = ParticleSystem.GetRotatePerSecondVar,
    Active = ParticleSystem.IsActive,
    BlendAdditive = ParticleSystem.IsBlendAdditive,
    BatchNode = ParticleSystem.GetBatchNode,
    AtlasIndex = ParticleSystem.GetAtlasIndex,
    ParticleCount = ParticleSystem.GetParticleCount,
    Duration = ParticleSystem.GetDuration,
    SourcePosition = ParticleSystem.GetSourcePosition,
    PosVar = ParticleSystem.GetPosVar,
    Life = ParticleSystem.GetLife,
    LifeVar = ParticleSystem.GetLifeVar,
    Angle = ParticleSystem.GetAngle,
    AngleVar = ParticleSystem.GetAngleVar,
    EmitterMode = ParticleSystem.GetEmitterMode,
    StartSize = ParticleSystem.GetStartSize,
    StartSizeVar = ParticleSystem.GetStartSizeVar,
    EndSize = ParticleSystem.GetEndSize,
    EndSizeVar = ParticleSystem.GetEndSizeVar,
    StartColor = ParticleSystem.GetStartColor,
    StartColorVar = ParticleSystem.GetStartColorVar,
    EndColor = ParticleSystem.GetEndColor,
    EndColorVar = ParticleSystem.GetEndColorVar,
    StartSpin = ParticleSystem.GetStartSpin,
    StartSpinVar = ParticleSystem.GetStartSpinVar,
    EndSpin = ParticleSystem.GetEndSpin,
    EndSpinVar = ParticleSystem.GetEndSpinVar,
    EmissionRate = ParticleSystem.GetEmissionRate,
    TotalParticles = ParticleSystem.GetTotalParticles,
    PositionType = ParticleSystem.GetPositionType,
    Texture = ParticleSystem.GetTexture,
    BlendFunc = ParticleSystem.GetBlendFunc,
    ResourceFile = ParticleSystem.GetResourceFile
    },
    w = {
    AutoRemoveOnFinish = ParticleSystem.SetAutoRemoveOnFinish,
    Gravity = ParticleSystem.SetGravity,
    Speed = ParticleSystem.SetSpeed,
    SpeedVar = ParticleSystem.SetSpeedVar,
    TangentialAccel = ParticleSystem.SetTangentialAccel,
    TangentialAccelVar = ParticleSystem.SetTangentialAccelVar,
    RadialAccel = ParticleSystem.SetRadialAccel,
    RadialAccelVar = ParticleSystem.SetRadialAccelVar,
    RotationIsDir = ParticleSystem.SetRotationIsDir,
    StartRadius = ParticleSystem.SetStartRadius,
    StartRadiusVar = ParticleSystem.SetStartRadiusVar,
    EndRadius = ParticleSystem.SetEndRadius,
    EndRadiusVar = ParticleSystem.SetEndRadiusVar,
    RotatePerSecond = ParticleSystem.SetRotatePerSecond,
    RotatePerSecondVar = ParticleSystem.SetRotatePerSecondVar,
    BlendAdditive = ParticleSystem.SetBlendAdditive,
    BatchNode = ParticleSystem.SetBatchNode,
    AtlasIndex = ParticleSystem.SetAtlasIndex,
    Duration = ParticleSystem.SetDuration,
    SourcePosition = ParticleSystem.SetSourcePosition,
    PosVar = ParticleSystem.SetPosVar,
    Life = ParticleSystem.SetLife,
    LifeVar = ParticleSystem.SetLifeVar,
    Angle = ParticleSystem.SetAngle,
    AngleVar = ParticleSystem.SetAngleVar,
    EmitterMode = ParticleSystem.SetEmitterMode,
    StartSize = ParticleSystem.SetStartSize,
    StartSizeVar = ParticleSystem.SetStartSizeVar,
    EndSize = ParticleSystem.SetEndSize,
    EndSizeVar = ParticleSystem.SetEndSizeVar,
    StartColor = ParticleSystem.SetStartColor,
    StartColorVar = ParticleSystem.SetStartColorVar,
    EndColor = ParticleSystem.SetEndColor,
    EndColorVar = ParticleSystem.SetEndColorVar,
    StartSpin = ParticleSystem.SetStartSpin,
    StartSpinVar = ParticleSystem.SetStartSpinVar,
    EndSpin = ParticleSystem.SetEndSpin,
    EndSpinVar = ParticleSystem.SetEndSpinVar,
    EmissionRate = ParticleSystem.SetEmissionRate,
    TotalParticles = ParticleSystem.SetTotalParticles,
    PositionType = ParticleSystem.SetPositionType,
    Texture = ParticleSystem.SetTexture,
    BlendFunc = ParticleSystem.SetBlendFunc
    }};
end

local ProgressTimer = cc.ProgressTimer;
function ProgressTimer.__properties__()
    return {
    r = {
    Type = ProgressTimer.GetType,
    Percentage = ProgressTimer.GetPercentage,
    Percent = function(self)
        return ProgressTimer.getPercentage(self) / 100;
    end,
    Sprite = ProgressTimer.GetSprite,
    ReverseDirection = ProgressTimer.IsReverseDirection,
    Midpoint = ProgressTimer.GetMidpoint,
    BarChangeRate = ProgressTimer.GetBarChangeRate
    },
    w = {
    Type = ProgressTimer.SetType,
    Percentage = ProgressTimer.SetPercentage,
    Percent = function(self,val)
        ProgressTimer.setPercentage(self,val * 100);
    end,
    Sprite = ProgressTimer.SetSprite,
    ReverseDirection = ProgressTimer.SetReverseDirection,
    Midpoint = ProgressTimer.SetMidpoint,
    BarChangeRate = ProgressTimer.SetBarChangeRate
    }};
end

local RenderTexture = cc.RenderTexture;
function RenderTexture.__properties__()
    return {
    r = {
    ClearFlags = RenderTexture.GetClearFlags,
    ClearColor = RenderTexture.GetClearColor,
    ClearDepth = RenderTexture.GetClearDepth,
    ClearStencil = RenderTexture.GetClearStencil,
    AutoDraw = RenderTexture.IsAutoDraw,
    Sprite = RenderTexture.GetSprite
    },
    w = {
    ClearFlags = RenderTexture.SetClearFlags,
    ClearColor = RenderTexture.SetClearColor,
    ClearDepth = RenderTexture.SetClearDepth,
    ClearStencil = RenderTexture.SetClearStencil,
    AutoDraw = RenderTexture.SetAutoDraw,
    Sprite = RenderTexture.SetSprite,
    KeepMatrix = RenderTexture.SetKeepMatrix
    }};
end

local Scene = cc.Scene;
function Scene.__properties__()
    return {
    r = {
    Cameras = Scene.GetCameras,
    DefaultCamera = Scene.GetDefaultCamera,
    Lights = Scene.GetLights,
    PhysicsWorld = Scene.GetPhysicsWorld,
    Physics3DWorld = Scene.GetPhysics3DWorld,
    NavMesh = Scene.GetNavMesh,
    },
    w = {
    NavMesh = Scene.SetNavMesh
    }};
end

local NavMeshAgent = cc.NavMeshAgent;
function NavMeshAgent.__properties__()
    return {
    r = {
    Radius = NavMeshAgent.GetRadius,
    Height = NavMeshAgent.GetHeight,
    MaxAcceleration = NavMeshAgent.GetMaxAcceleration,
    MaxSpeed = NavMeshAgent.GetMaxSpeed,
    SeparationWeight = NavMeshAgent.GetSeparationWeight,
    ObstacleAvoidanceType = NavMeshAgent.GetObstacleAvoidanceType,
    CurrentVelocity = NavMeshAgent.GetCurrentVelocity,
    OnOffMeshLink = NavMeshAgent.IsOnOffMeshLink,
    SyncFlag = NavMeshAgent.GetSyncFlag,
    Velocity = NavMeshAgent.GetVelocity
    },
    w = {
    Radius = NavMeshAgent.SetRadius,
    Height = NavMeshAgent.SetHeight,
    MaxAcceleration = NavMeshAgent.SetMaxAcceleration,
    MaxSpeed = NavMeshAgent.SetMaxSpeed,
    SeparationWeight = NavMeshAgent.SetSeparationWeight,
    ObstacleAvoidanceType = NavMeshAgent.SetObstacleAvoidanceType,
    OrientationRefAxes = NavMeshAgent.SetOrientationRefAxes,
    AutoOrientation = NavMeshAgent.SetAutoOrientation,
    AutoTraverseOffMeshLink = NavMeshAgent.SetAutoTraverseOffMeshLink,
    SyncFlag = NavMeshAgent.SetSyncFlag
    }};
end

local NavMeshObstacle = cc.NavMeshObstacle;
function NavMeshObstacle.__properties__()
    return {
    r = {
    Radius = NavMeshObstacle.GetRadius,
    Height = NavMeshObstacle.GetHeight,
    SyncFlag = NavMeshObstacle.GetSyncFlag
    },
    w = {
    Radius = NavMeshObstacle.SetRadius,
    Height = NavMeshObstacle.SetHeight,
    SyncFlag = NavMeshObstacle.SetSyncFlag
    }};
end

local Sprite = cc.Sprite;
function Sprite.__properties__()
    return {
    r = {
    BatchNode = Sprite.GetBatchNode,
    Texture = Sprite.GetTexture,
    CenterRectNormalized = Sprite.GetCenterRectNormalized,
    CenterRect = Sprite.GetCenterRect,
    FrameDisplayed = Sprite.IsFrameDisplayed,
    SpriteFrame = Sprite.GetSpriteFrame,
    Dirty = Sprite.IsDirty,
    TextureRectRotated = Sprite.IsTextureRectRotated,
    AtlasIndex = Sprite.GetAtlasIndex,
    TextureRect = Sprite.GetTextureRect,
    TextureAtlas = Sprite.GetTextureAtlas,
    OffsetPosition = Sprite.GetOffsetPosition,
    FlippedX = Sprite.IsFlippedX,
    FlippedY = Sprite.IsFlippedY,
    StretchEnabled = Sprite.IsStretchEnabled,
    BlendFunc = Sprite.GetBlendFunc,
    Grayed = function(self)
        return self.__spriteGrayed or false;
    end
    },
    w = {
    BatchNode = Sprite.SetBatchNode,
    Texture = Sprite.SetTexture,
    TextureRect = Sprite.SetTextureRect,
    VertexRect = Sprite.SetVertexRect,
    CenterRectNormalized = Sprite.SetCenterRectNormalized,
    CenterRect = Sprite.SetCenterRect,
    SpriteFrame = Sprite.SetSpriteFrame,
    Dirty = Sprite.SetDirty,
    AtlasIndex = Sprite.SetAtlasIndex,
    TextureAtlas = Sprite.SetTextureAtlas,
    FlippedX = Sprite.SetFlippedX,
    FlippedY = Sprite.SetFlippedY,
    StretchEnabled = Sprite.SetStretchEnabled,
    BlendFunc = Sprite.SetBlendFunc,
    ProgramState = Sprite.SetProgramState,
    Grayed = function(self,val)
        val = not not val;
        if self.__spriteGrayed == val then
            return;
        end

        self.ProgramState = val and ccb.ProgramType.GRAY_SCALE or ccb.ProgramType.POSITION_TEXTURE_COLOR;
        self.__spriteGrayed = val;
    end
    }};
end

local SpriteBatchNode = cc.SpriteBatchNode;
function SpriteBatchNode.__properties__()
    return {
    r = {
    TextureAtlas = SpriteBatchNode.GetTextureAtlas,
    Descendants = SpriteBatchNode.GetDescendants,
    Texture = SpriteBatchNode.GetTexture,
    BlendFunc = SpriteBatchNode.GetBlendFunc,
    },
    w = {
    TextureAtlas = SpriteBatchNode.SetTextureAtlas,
    Texture = SpriteBatchNode.SetTexture,
    BlendFunc = SpriteBatchNode.SetBlendFunc,
    }};
end

local TransitionScene = cc.TransitionScene;
function TransitionScene.__properties__()
    return {
    r = {
    InScene = TransitionScene.GetInScene,
    Duration = TransitionScene.GetDuration
    },
    w = {
    }};
end

local Director = cc.Director;
function Director.__properties__()
    return {
    r = {
    RunningScene = Director.GetRunningScene,
    AnimationInterval = Director.GetAnimationInterval,
    DisplayStats = Director.IsDisplayStats,
    SecondsPerFrame = Director.GetSecondsPerFrame,
    OpenGLView = Director.GetOpenGLView,
    TextureCache = Director.GetTextureCache,
    NextDeltaTimeZero = Director.IsNextDeltaTimeZero,
    Paused = Director.IsPaused,
    TotalFrames = Director.GetTotalFrames,
    SendCleanupToScene = Director.IsSendCleanupToScene,
    NotificationNode = Director.GetNotificationNode,
    WinSize = Director.GetWinSize,
    WinSizeInPixels = Director.GetWinSizeInPixels,
    VisibleSize = Director.GetVisibleSize,
    VisibleOrigin = Director.GetVisibleOrigin,
    SafeAreaRect = Director.GetSafeAreaRect,
    ZEye = Director.GetZEye,
    ClearColor = Director.GetClearColor,
    ContentScaleFactor = Director.GetContentScaleFactor,
    Scheduler = Director.GetScheduler,
    ActionManager = Director.GetActionManager,
    EventDispatcher = Director.GetEventDispatcher,
    DeltaTime = Director.GetDeltaTime,
    FrameRate = Director.GetFrameRate,
    Cocos2dThreadId = Director.GetCocos2dThreadId,
    Valid = Director.IsValid
    },
    w = {
    AnimationInterval = Director.SetAnimationInterval,
    DisplayStats = Director.SetDisplayStats,
    OpenGLView = Director.SetOpenGLView,
    NextDeltaTimeZero = Director.SetNextDeltaTimeZero,
    NotificationNode = Director.SetNotificationNode,
    AlphaBlending = Director.SetAlphaBlending,
    ClearColor = Director.SetClearColor,
    ContentScaleFactor = Director.SetContentScaleFactor,
    Scheduler = Director.SetScheduler,
    ActionManager = Director.SetActionManager,
    EventDispatcher = Director.SetEventDispatcher
    }};
end

local Event = cc.Event;
function Event.__properties__()
    return {
    r = {
    Type = Event.GetType,
    Stopped = Event.IsStopped,
    CurrentTarget = Event.GetCurrentTarget
    },
    w = {
    }};
end

local EventCustom = cc.EventCustom;
function EventCustom.__properties__()
    return {
    r = {
    EventName = EventCustom.GetEventName
    },
    w = {
    }};
end

local EventDispatcher = cc.EventDispatcher;
function EventDispatcher.__properties__()
    return {
    r = {
    Enabled = EventDispatcher.IsEnabled
    },
    w = {
    Enabled = EventDispatcher.SetEnabled
    }};
end

local EventListener = cc.EventListener;
function EventListener.__properties__()
    return {
    r = {
    Enabled = EventListener.IsEnabled
    },
    w = {
    Enabled = EventListener.SetEnabled
    }};
end

local EventListenerTouchOneByOne = cc.EventListenerTouchOneByOne;
function EventListenerTouchOneByOne.__properties__()
    return {
    r = {
    SwallowTouches = EventListenerTouchOneByOne.IsSwallowTouches
    },
    w = {
    SwallowTouches = EventListenerTouchOneByOne.SetSwallowTouches
    }};
end

local EventMouse = cc.EventMouse;
function EventMouse.__properties__()
    return {
    r = {
    ScrollX = EventMouse.GetScrollX,
    ScrollY = EventMouse.GetScrollY,
    MouseButton = EventMouse.GetMouseButton,
    CursorX = EventMouse.GetCursorX,
    CursorY = EventMouse.GetCursorY,
    Location = EventMouse.GetLocation,
    PreviousLocation = EventMouse.GetPreviousLocation,
    StartLocation = EventMouse.GetStartLocation,
    Delta = EventMouse.GetDelta,
    LocationInView = EventMouse.GetLocationInView,
    PreviousLocationInView = EventMouse.GetPreviousLocationInView,
    StartLocationInView = EventMouse.GetStartLocationInView
    },
    w = {
    CursorPosition = EventMouse.SetCursorPosition,
    MouseButton = EventMouse.SetMouseButton
    }};
end

local EventTouch = cc.EventTouch;
function EventTouch.__properties__()
    return {
    r = {
    EventCode = EventTouch.GetEventCode,
    Touches = EventTouch.GetTouches
    },
    w = {
    }};
end

local Scheduler = cc.Scheduler;
function Scheduler.__properties__()
    return {
    r = {
    TimeScale = Scheduler.GetTimeScale
    },
    w = {
    TimeScale = Scheduler.SetTimeScale
    }};
end

local Touch = cc.Touch;
function Touch.__properties__()
    return {
    r = {
    Location = Touch.GetLocation,
    PreviousLocation = Touch.GetPreviousLocation,
    StartLocation = Touch.GetStartLocation,
    Delta = Touch.GetDelta,
    LocationInView = Touch.GetLocationInView,
    PreviousLocationInView = Touch.GetPreviousLocationInView,
    StartLocationInView = Touch.GetStartLocationInView,
    ID = Touch.GetID,
    CurrentForce = Touch.GetCurrentForce,
    MaxForce = Touch.GetMaxForce
    },
    w = {
    }};
end

local CSLoader = cc.CSLoader;
function CSLoader.__properties__()
    return {
    r = {
    RecordJsonPath = CSLoader.IsRecordJsonPath,
    JsonPath = CSLoader.GetJsonPath,
    },
    w = {
    RecordJsonPath = CSLoader.SetRecordJsonPath,
    JsonPath = CSLoader.SetJsonPath,
    }};
end

local AssetsManagerEx = cc.AssetsManagerEx;
function AssetsManagerEx.__properties__()
    return {
    r = {
    State = AssetsManagerEx.GetState,
    StoragePath = AssetsManagerEx.GetStoragePath,
    LocalManifest = AssetsManagerEx.GetLocalManifest,
    RemoteManifest = AssetsManagerEx.GetRemoteManifest,
    MaxConcurrentTask = AssetsManagerEx.GetMaxConcurrentTask
    },
    w = {
    MaxConcurrentTask = AssetsManagerEx.SetMaxConcurrentTask
    }};
end

local EventAssetsManagerEx = cc.EventAssetsManagerEx;
function EventAssetsManagerEx.__properties__()
    return {
    r = {
    EventCode = EventAssetsManagerEx.GetEventCode,
    CURLECode = EventAssetsManagerEx.GetCURLECode,
    CURLMCode = EventAssetsManagerEx.GetCURLMCode,
    Message = EventAssetsManagerEx.GetMessage,
    AssetId = EventAssetsManagerEx.GetAssetId,
    AssetsManagerEx = EventAssetsManagerEx.GetAssetsManagerEx,
    Percent = function(self)
        return EventAssetsManagerEx.getPercent(self) / 100;
    end,
    PercentByFile = function(self)
        return EventAssetsManagerEx.getPercentByFile(self) / 100;
    end
    },
    w = {
    }};
end

local Manifest = cc.Manifest;
function Manifest.__properties__()
    return {
    r = {
    VersionLoaded = Manifest.IsVersionLoaded,
    Loaded = Manifest.IsLoaded,
    PackageUrl = Manifest.GetPackageUrl,
    ManifestFileUrl = Manifest.GetManifestFileUrl,
    VersionFileUrl = Manifest.GetVersionFileUrl,
    Version = Manifest.GetVersion,
    SearchPaths = Manifest.GetSearchPaths
    },
    w = {
    }};
end

local PhysicsBody = cc.PhysicsBody;
function PhysicsBody.__properties__()
    return {
    r = {
    Shapes = PhysicsBody.GetShapes,
    FirstShape = PhysicsBody.GetFirstShape,
    Velocity = PhysicsBody.GetVelocity,
    AngularVelocity = PhysicsBody.GetAngularVelocity,
    VelocityLimit = PhysicsBody.GetVelocityLimit,
    AngularVelocityLimit = PhysicsBody.GetAngularVelocityLimit,
    World = PhysicsBody.GetWorld,
    Joints = PhysicsBody.GetJoints,
    Node = PhysicsBody.GetNode,
    CategoryBitmask = PhysicsBody.GetCategoryBitmask,
    ContactTestBitmask = PhysicsBody.GetContactTestBitmask,
    CollisionBitmask = PhysicsBody.GetCollisionBitmask,
    Group = PhysicsBody.GetGroup,
    Position = PhysicsBody.GetPosition,
    Rotation = PhysicsBody.GetRotation,
    PositionOffset = PhysicsBody.GetPositionOffset,
    RotationOffset = PhysicsBody.GetRotationOffset,
    Dynamic = PhysicsBody.IsDynamic,
    Mass = PhysicsBody.GetMass,
    Moment = PhysicsBody.GetMoment,
    LinearDamping = PhysicsBody.GetLinearDamping,
    AngularDamping = PhysicsBody.GetAngularDamping,
    Resting = PhysicsBody.IsResting,
    RotationEnabled = PhysicsBody.IsRotationEnabled,
    GravityEnabled = PhysicsBody.IsGravityEnabled,
    Tag = PhysicsBody.GetTag,
    },
    w = {
    Velocity = PhysicsBody.SetVelocity,
    AngularVelocity = PhysicsBody.SetAngularVelocity,
    VelocityLimit = PhysicsBody.SetVelocityLimit,
    AngularVelocityLimit = PhysicsBody.SetAngularVelocityLimit,
    CategoryBitmask = PhysicsBody.SetCategoryBitmask,
    ContactTestBitmask = PhysicsBody.SetContactTestBitmask,
    CollisionBitmask = PhysicsBody.SetCollisionBitmask,
    Group = PhysicsBody.SetGroup,
    PositionOffset = PhysicsBody.SetPositionOffset,
    RotationOffset = PhysicsBody.SetRotationOffset,
    Dynamic = PhysicsBody.SetDynamic,
    Mass = PhysicsBody.SetMass,
    Moment = PhysicsBody.SetMoment,
    LinearDamping = PhysicsBody.SetLinearDamping,
    AngularDamping = PhysicsBody.SetAngularDamping,
    Resting = PhysicsBody.SetResting,
    RotationEnabled = PhysicsBody.SetRotationEnable,
    GravityEnabled = PhysicsBody.SetGravityEnabled,
    Tag = PhysicsBody.SetTag,
    }};
end

local PhysicsShape = cc.PhysicsShape;
function PhysicsShape.__properties__()
    return {
    r = {
    Body = PhysicsShape.GetBody,
    Type = PhysicsShape.GetType,
    Area = PhysicsShape.GetArea,
    Moment = PhysicsShape.GetMoment,
    Tag = PhysicsShape.GetTag,
    Mass = PhysicsShape.GetMass,
    Density = PhysicsShape.GetDensity,
    Restitution = PhysicsShape.GetRestitution,
    Friction = PhysicsShape.GetFriction,
    Material = PhysicsShape.GetMaterial,
    Sensor = PhysicsShape.IsSensor,
    Offset = PhysicsShape.GetOffset,
    Center = PhysicsShape.GetCenter,
    CategoryBitmask = PhysicsShape.GetCategoryBitmask,
    ContactTestBitmask = PhysicsShape.GetContactTestBitmask,
    CollisionBitmask = PhysicsShape.GetCollisionBitmask,
    Group = PhysicsShape.GetGroup
    },
    w = {
    Moment = PhysicsShape.SetMoment,
    Tag = PhysicsShape.SetTag,
    Mass = PhysicsShape.SetMass,
    Density = PhysicsShape.SetDensity,
    Restitution = PhysicsShape.SetRestitution,
    Friction = PhysicsShape.SetFriction,
    Material = PhysicsShape.SetMaterial,
    Sensor = PhysicsShape.SetSensor,
    CategoryBitmask = PhysicsShape.SetCategoryBitmask,
    ContactTestBitmask = PhysicsShape.SetContactTestBitmask,
    CollisionBitmask = PhysicsShape.SetCollisionBitmask,
    Group = PhysicsShape.SetGroup
    }};
end

local PhysicsContact = cc.PhysicsContact;
function PhysicsContact.__properties__()
    return {
    r = {
    ShapeA = PhysicsContact.GetShapeA,
    ShapeB = PhysicsContact.GetShapeB,
    EventCode = PhysicsContact.GetEventCode,
    ContactData = PhysicsContact.GetContactData,
    PreContactData = PhysicsContact.GetPreContactData
    },
    w = {
    }};
end

local PhysicsShapeCircle = cc.PhysicsShapeCircle;
function PhysicsShapeCircle.__properties__()
    return {
    r = {
    Radius = PhysicsShapeCircle.GetRadius
    },
    w = {
    }};
end

local PhysicsShapePolygon = cc.PhysicsShapePolygon;
function PhysicsShapePolygon.__properties__()
    return {
    r = {
    PointsCount = PhysicsShapePolygon.GetPointsCount
    },
    w = {
    }};
end

local PhysicsShapeBox = cc.PhysicsShapeBox;
function PhysicsShapeBox.__properties__()
    return {
    r = {
    Size = PhysicsShapeBox.GetSize
    },
    w = {
    }};
end

local PhysicsShapeEdgeSegment = cc.PhysicsShapeEdgeSegment;
function PhysicsShapeEdgeSegment.__properties__()
    return {
    r = {
    PointA = PhysicsShapeEdgeSegment.GetPointA,
    PointB = PhysicsShapeEdgeSegment.GetPointB
    },
    w = {
    }};
end

local PhysicsShapeEdgePolygon = cc.PhysicsShapeEdgePolygon;
function PhysicsShapeEdgePolygon.__properties__()
    return {
    r = {
    PointsCount = PhysicsShapeEdgePolygon.GetPointsCount
    },
    w = {
    }};
end

local PhysicsShapeEdgeChain = cc.PhysicsShapeEdgeChain;
function PhysicsShapeEdgeChain.__properties__()
    return {
    r = {
    PointsCount = PhysicsShapeEdgeChain.GetPointsCount
    },
    w = {
    }};
end

local PhysicsJoint = cc.PhysicsJoint;
function PhysicsJoint.__properties__()
    return {
    r = {
    BodyA = PhysicsJoint.GetBodyA,
    BodyB = PhysicsJoint.GetBodyB,
    World = PhysicsJoint.GetWorld,
    Tag = PhysicsJoint.GetTag,
    Enabled = PhysicsJoint.IsEnabled,
    CollisionEnabled = PhysicsJoint.IsCollisionEnabled,
    MaxForce = PhysicsJoint.GetMaxForce
    },
    w = {
    Tag = PhysicsJoint.SetTag,
    Enabled = PhysicsJoint.SetEnabled,
    CollisionEnabled = PhysicsJoint.SetCollisionEnabled,
    MaxForce = PhysicsJoint.SetMaxForce
    }};
end

local PhysicsJointLimit = cc.PhysicsJointLimit;
function PhysicsJointLimit.__properties__()
    return {
    r = {
    Anchr1 = PhysicsJointLimit.GetAnchr1,
    Anchr2 = PhysicsJointLimit.GetAnchr2,
    Min = PhysicsJointLimit.GetMin,
    Max = PhysicsJointLimit.GetMax
    },
    w = {
    Anchr1 = PhysicsJointLimit.SetAnchr1,
    Anchr2 = PhysicsJointLimit.SetAnchr2,
    Min = PhysicsJointLimit.SetMin,
    Max = PhysicsJointLimit.SetMax
    }};
end

local PhysicsJointDistance = cc.PhysicsJointDistance;
function PhysicsJointDistance.__properties__()
    return {
    r = {
    Distance = PhysicsJointDistance.GetDistance
    },
    w = {
    Distance = PhysicsJointDistance.SetDistance
    }};
end

local PhysicsJointSpring = cc.PhysicsJointSpring;
function PhysicsJointSpring.__properties__()
    return {
    r = {
    Anchr1 = PhysicsJointSpring.GetAnchr1,
    Anchr2 = PhysicsJointSpring.GetAnchr2,
    RestLength = PhysicsJointSpring.GetRestLength,
    Stiffness = PhysicsJointSpring.GetStiffness,
    Damping = PhysicsJointSpring.GetDamping
    },
    w = {
    Anchr1 = PhysicsJointSpring.SetAnchr1,
    Anchr2 = PhysicsJointSpring.SetAnchr2,
    RestLength = PhysicsJointSpring.SetRestLength,
    Stiffness = PhysicsJointSpring.SetStiffness,
    Damping = PhysicsJointSpring.SetDamping
    }};
end

local PhysicsJointGroove = cc.PhysicsJointGroove;
function PhysicsJointGroove.__properties__()
    return {
    r = {
    GrooveA = PhysicsJointGroove.GetGrooveA,
    GrooveB = PhysicsJointGroove.GetGrooveB,
    Anchr2 = PhysicsJointGroove.GetAnchr2
    },
    w = {
    GrooveA = PhysicsJointGroove.SetGrooveA,
    GrooveB = PhysicsJointGroove.SetGrooveB,
    Anchr2 = PhysicsJointGroove.SetAnchr2
    }};
end

local PhysicsJointRotarySpring = cc.PhysicsJointRotarySpring;
function PhysicsJointRotarySpring.__properties__()
    return {
    r = {
    RestAngle = PhysicsJointRotarySpring.GetRestAngle,
    Stiffness = PhysicsJointRotarySpring.GetStiffness,
    Damping = PhysicsJointRotarySpring.GetDamping
    },
    w = {
    RestAngle = PhysicsJointRotarySpring.SetRestAngle,
    Stiffness = PhysicsJointRotarySpring.SetStiffness,
    Damping = PhysicsJointRotarySpring.SetDamping
    }};
end

local PhysicsJointRotaryLimit = cc.PhysicsJointRotaryLimit;
function PhysicsJointRotaryLimit.__properties__()
    return {
    r = {
    Min = PhysicsJointRotaryLimit.GetMin,
    Max = PhysicsJointRotaryLimit.GetMax
    },
    w = {
    Min = PhysicsJointRotaryLimit.SetMin,
    Max = PhysicsJointRotaryLimit.SetMax
    }};
end

local PhysicsJointRatchet = cc.PhysicsJointRatchet;
function PhysicsJointRatchet.__properties__()
    return {
    r = {
    Angle = PhysicsJointRatchet.GetAngle,
    Phase = PhysicsJointRatchet.GetPhase,
    Ratchet = PhysicsJointRatchet.GetRatchet
    },
    w = {
    Angle = PhysicsJointRatchet.SetAngle,
    Phase = PhysicsJointRatchet.SetPhase,
    Ratchet = PhysicsJointRatchet.SetRatchet
    }};
end

local PhysicsJointGear = cc.PhysicsJointGear;
function PhysicsJointGear.__properties__()
    return {
    r = {
    Phase = PhysicsJointGear.GetPhase,
    Ratio = PhysicsJointGear.GetRatio
    },
    w = {
    Phase = PhysicsJointGear.SetPhase,
    Ratio = PhysicsJointGear.SetRatio
    }};
end

local PhysicsJointMotor = cc.PhysicsJointMotor;
function PhysicsJointMotor.__properties__()
    return {
    r = {
    Rate = PhysicsJointGear.GetRate
    },
    w = {
    Rate = PhysicsJointGear.SetRate
    }};
end

local PhysicsWorld = cc.PhysicsWorld;
function PhysicsWorld.__properties__()
    return {
    r = {
    Bodies = PhysicsWorld.GetAllBodies,
    Scene = PhysicsWorld.GetScene,
    Gravity = PhysicsWorld.GetGravity,
    Speed = PhysicsWorld.GetSpeed,
    UpdateRate = PhysicsWorld.GetUpdateRate,
    Substeps = PhysicsWorld.GetSubsteps,
    FixedUpdateRate = PhysicsWorld.GetFixedUpdateRate,
    AutoStep = PhysicsWorld.IsAutoStep
    },
    w = {
    Gravity = PhysicsWorld.SetGravity,
    Speed = PhysicsWorld.SetSpeed,
    UpdateRate = PhysicsWorld.SetUpdateRate,
    Substeps = PhysicsWorld.SetSubsteps,
    FixedUpdateRate = PhysicsWorld.SetFixedUpdateRate,
    AutoStep = PhysicsWorld.SetAutoStep,
    DebugDrawMask = PhysicsWorld.SetDebugDrawMask
    }};
end

local Application = cc.Application;
function Application.__properties__()
    return {
    r = {
    TargetPlatform = Application.GetTargetPlatform,
    CurrentLanguage = Application.GetCurrentLanguage,
    CurrentLanguageCode = Application.GetCurrentLanguageCode,
    Version = Application.GetVersion,
    CompileVersion = Application.GetCompileVersion
    },
    w = {
    AnimationInterval = Application.SetAnimationInterval
    }};
end

local FileUtils = cc.FileUtils;
function FileUtils.__properties__()
    return {
    r = {
    SearchResolutionsOrder = FileUtils.GetSearchResolutionsOrder,
    DefaultResourceRootPath = FileUtils.GetDefaultResourceRootPath,
    SearchPaths = FileUtils.GetSearchPaths,
    OriginalSearchPaths = FileUtils.GetOriginalSearchPaths,
    WritablePath = FileUtils.GetWritablePath,
    PopupNotify = FileUtils.IsPopupNotify
    },
    w = {
    FilenameLookupDictionary = FileUtils.SetFilenameLookupDictionary,
    SearchResolutionsOrder = FileUtils.SetSearchResolutionsOrder,
    SearchPaths = FileUtils.SetSearchPaths,
    DefaultResourceRootPath = FileUtils.SetDefaultResourceRootPath,
    WritablePath = FileUtils.SetWritablePath,
    PopupNotify = FileUtils.SetPopupNotify
    }};
end

local GLView = cc.GLView;
function GLView.__properties__()
    return {
    r = {
    OpenGLReady = GLView.IsOpenGLReady,
    FrameSize = GLView.GetFrameSize,
    FrameZoomFactor = GLView.GetFrameZoomFactor,
    RetinaFactor = GLView.GetRetinaFactor,
    ContentScaleFactor = GLView.GetContentScaleFactor,
    RetinaDisplay = GLView.IsRetinaDisplay,
    VisibleSize = GLView.GetVisibleSize,
    VisibleOrigin = GLView.GetVisibleOrigin,
    VisibleRect = GLView.GetVisibleRect,
    SafeAreaRect = GLView.GetSafeAreaRect,
    DesignResolutionSize = GLView.GetDesignResolutionSize,
    ScissorEnabled = GLView.IsScissorEnabled,
    ScissorRect = GLView.GetScissorRect,
    ViewName = GLView.GetViewName,
    ViewPortRect = GLView.GetViewPortRect,
    Touches = GLView.GetAllTouches,
    ScaleX = GLView.GetScaleX,
    ScaleY = GLView.GetScaleY,
    ResolutionPolicy = GLView.GetResolutionPolicy
    },
    w = {
    IMEKeyboardState = GLView.SetIMEKeyboardState,
    FrameSize = GLView.SetFrameSize,
    FrameZoomFactor = GLView.SetFrameZoomFactor,
    CursorVisible = GLView.SetCursorVisible,
    RetinaFactor = GLView.SetRetinaFactor,
    ViewName = GLView.SetViewName,
    Icon = GLView.SetIcon
    }};
end

local Image = cc.Image;
function Image.__properties__()
    return {
    r = {
    FileType = Image.GetFileType,
    RenderFormat = Image.GetRenderFormat,
    Width = Image.GetWidth,
    Height = Image.GetHeight,
    NumberOfMipmaps = Image.GetNumberOfMipmaps,
    PremultipliedAlpha = Image.HasPremultipliedAlpha,
    FilePath = Image.GetFilePath,
    BitPerPixel = Image.GetBitPerPixel,
    Alpha = Image.HasAlpha,
    Compressed = Image.IsCompressed
    },
    w = {
    }};
end

local RenderState = cc.RenderState;
function RenderState.__properties__()
    return {
    r = {
    Name = RenderState.GetName,
    Texture = RenderState.GetTexture
    },
    w = {
    Texture = RenderState.SetTexture,
    Parent = RenderState.SetParent
    }};
end

local Material = cc.Material;
function Material.__properties__()
    return {
    r = {
    Name = Material.GetName,
    Technique = Material.GetTechnique,
    Techniques = Material.GetTechniques,
    TechniqueCount = Material.GetTechniqueCount
    },
    w = {
    Name = Material.SetName
    }};
end

local Pass = cc.Pass;
function Pass.__properties__()
    return {
    r = {
    ProgramState = Pass.GetProgramState,
    VertexAttributeBinding = Pass.GetVertexAttributeBinding,
    Hash = Pass.GetHash
    },
    w = {
    VertexAttributeBinding = Pass.SetVertexAttributeBinding
    }};
end

local Technique = cc.Technique;
function Technique.__properties__()
    return {
    r = {
    Name = Technique.GetName,
    PassCount = Technique.GetPassCount,
    Passes = Technique.GetPasses
    },
    w = {
    }};
end

local Texture2D = cc.Texture2D;
function Texture2D.__properties__()
    return {
    r = {
    StringForFormat = Texture2D.GetStringForFormat,
    BitsPerPixelForFormat = Texture2D.GetBitsPerPixelForFormat,
    ContentSizeInPixels = Texture2D.GetContentSizeInPixels,
    PremultipliedAlpha = Texture2D.HasPremultipliedAlpha,
    Mipmaps = Texture2D.HasMipmaps,
    PixelFormat = Texture2D.GetPixelFormat,
    PixelsWide = Texture2D.GetPixelsWide,
    PixelsHigh = Texture2D.GetPixelsHigh,
    Name = Texture2D.GetName,
    MaxS = Texture2D.GetMaxS,
    MaxT = Texture2D.GetMaxT,
    Size = Texture2D.GetContentSize,
    Path = Texture2D.GetPath,
    AlphaTextureName = Texture2D.GetAlphaTextureName,
    AlphaTexture = Texture2D.GetAlphaTexture
    },
    w = {
    TexParameters = Texture2D.SetTexParameters,
    MaxS = Texture2D.SetMaxS,
    MaxT = Texture2D.SetMaxT,
    AlphaTexture = Texture2D.SetAlphaTexture
    }};
end

local Scale9Sprite = ccui.Scale9Sprite;
function Scale9Sprite.__properties__()
    return {
    r = {
    OriginalSize = Scale9Sprite.GetOriginalSize,
    PreferredSize = Scale9Sprite.GetPreferredSize,
    InsetLeft = Scale9Sprite.GetInsetLeft,
    InsetTop = Scale9Sprite.GetInsetTop,
    InsetRight = Scale9Sprite.GetInsetRight,
    InsetBottom = Scale9Sprite.GetInsetBottom,
    Scale9Enabled = Scale9Sprite.IsScale9Enabled,
    Sprite = Scale9Sprite.GetSprite,
    RenderingType = Scale9Sprite.GetRenderingType,
    CapInsets = Scale9Sprite.GetCapInsets,
    -- 由于State枚举和State的gtor冲突，可以使用Grayed代替State的gtor
    Grayed = function(self)
        return self:getState() == Scale9Sprite.State.GRAY;
    end
    },
    w = {
    PreferredSize = Scale9Sprite.SetPreferredSize,
    InsetLeft = Scale9Sprite.SetInsetLeft,
    InsetTop = Scale9Sprite.SetInsetTop,
    InsetRight = Scale9Sprite.SetInsetRight,
    InsetBottom = Scale9Sprite.SetInsetBottom,
    Scale9Enabled = Scale9Sprite.SetScale9Enabled,
    RenderingType = Scale9Sprite.SetRenderingType,
    CapInsets = Scale9Sprite.SetCapInsets,
    -- 由于State枚举和State的stor冲突，可以使用Grayed代替State的stor
    Grayed = function(self,val)
        if val then
            self:setState(Scale9Sprite.State.GRAY);
        else
            self:setState(Scale9Sprite.State.NORMAL);
        end
    end
    }};
end

local Widget = ccui.Widget;
function Widget.__properties__()
    return {
    r = {
    Enabled = Widget.IsEnabled,
    Bright = Widget.IsBright,
    TouchEnabled = Widget.IsTouchEnabled,
    Highlighted = Widget.IsHighlighted,
    LeftBoundary = Widget.GetLeftBoundary,
    BottomBoundary = Widget.GetBottomBoundary,
    RightBoundary = Widget.GetRightBoundary,
    TopBoundary = Widget.GetTopBoundary,
    PositionPercent = Widget.GetPositionPercent,
    PositionType = Widget.GetPositionType,
    FlippedX = Widget.IsFlippedX,
    FlippedY = Widget.IsFlippedY,
    ClippingParentContainsPoint = Widget.IsClippingParentContainsPoint,
    TouchBeganPosition = Widget.GetTouchBeganPosition,
    TouchMovePosition = Widget.GetTouchMovePosition,
    TouchEndPosition = Widget.GetTouchEndPosition,
    SizeType = Widget.GetSizeType,
    CustomSize = Widget.GetCustomSize,
    LayoutSize = Widget.GetLayoutSize,
    SizePercent = Widget.GetSizePercent,
    LayoutParameter = Widget.GetLayoutParameter,
    IgnoreContentAdaptWithSize = Widget.IsIgnoreContentAdaptWithSize,
    WorldPosition = Widget.GetWorldPosition,
    VirtualRenderer = Widget.GetVirtualRenderer,
    VirtualRendererSize = Widget.GetVirtualRendererSize,
    ActionTag = Widget.GetActionTag,
    PropagateTouchEvents = Widget.IsPropagateTouchEvents,
    SwallowTouches = Widget.IsSwallowTouches,
    Focused = Widget.IsFocused,
    FocusEnabled = Widget.IsFocusEnabled,
    UnifySizeEnabled = Widget.IsUnifySizeEnabled,
    CallbackName = Widget.GetCallbackName,
    CallbackType = Widget.GetCallbackType,
    LayoutComponentEnabled = Widget.IsLayoutComponentEnabled
    },
    w = {
    Enabled = Widget.SetEnabled,
    Bright = function (self,val)
        if "boolean" == type(val) then
            self:SetBright(val);
        else
            self:SetBrightStyle(val);
        end
    end,
    TouchEnabled = Widget.SetTouchEnabled,
    Highlighted = Widget.SetHighlighted,
    PositionPercent = Widget.SetPositionPercent,
    PositionType = Widget.SetPositionType,
    FlippedX = Widget.SetFlippedX,
    FlippedY = Widget.SetFlippedY,
    SizePercent = Widget.SetSizePercent,
    SizeType = Widget.SetSizeType,
    LayoutParameter = Widget.SetLayoutParameter,
    IgnoreContentAdaptWithSize = Widget.IgnoreContentAdaptWithSize,
    ActionTag = Widget.SetActionTag,
    PropagateTouchEvents = Widget.SetPropagateTouchEvents,
    SwallowTouches = Widget.SetSwallowTouches,
    Focused = Widget.SetFocused,
    FocusEnabled = Widget.SetFocusEnabled,
    UnifySizeEnabled = Widget.SetUnifySizeEnabled,
    CallbackName = Widget.SetCallbackName,
    LayoutComponentEnabled = Widget.SetLayoutComponentEnabled,
    TouchHandler = Widget.AddTouchEventListener,
    ClickHandler = Widget.AddClickEventListener
    }};
end

local Layout = ccui.Layout;
function Layout.__properties__()
    return {
    r = {
    BackGroundImageCapInsets = Layout.GetBackGroundImageCapInsets,
    BackGroundColorType = Layout.GetBackGroundColorType,
    BackGroundImageScale9Enabled = Layout.IsBackGroundImageScale9Enabled,
    BackGroundColor = Layout.GetBackGroundColor,
    BackGroundStartColor = Layout.GetBackGroundStartColor,
    BackGroundEndColor = Layout.GetBackGroundEndColor,
    BackGroundColorOpacity = Layout.GetBackGroundColorOpacity,
    BackGroundColorVector = Layout.GetBackGroundColorVector,
    BackGroundImageColor = Layout.GetBackGroundImageColor,
    BackGroundImageOpacity = Layout.GetBackGroundImageOpacity,
    BackGroundImageTextureSize = Layout.GetBackGroundImageTextureSize,
    ClippingType = Layout.GetClippingType,
    ClippingEnabled = Layout.IsClippingEnabled,
    LayoutType = Layout.GetLayoutType,
    LoopFocus = Layout.IsLoopFocus,
    PassFocusToChild = Layout.IsPassFocusToChild
    },
    w = {
    BackGroundImage = Layout.SetBackGroundImage,
    BackGroundImageCapInsets = Layout.SetBackGroundImageCapInsets,
    BackGroundColorType = Layout.SetBackGroundColorType,
    BackGroundImageScale9Enabled = Layout.SetBackGroundImageScale9Enabled,
    BackGroundColor = Layout.SetBackGroundColor,
    BackGroundColorOpacity = Layout.SetBackGroundColorOpacity,
    BackGroundColorVector = Layout.SetBackGroundColorVector,
    BackGroundImageColor = Layout.SetBackGroundImageColor,
    BackGroundImageOpacity = Layout.SetBackGroundImageOpacity,
    ClippingEnabled = Layout.SetClippingEnabled,
    ClippingType = Layout.SetClippingType,
    LayoutType = Layout.SetLayoutType,
    LoopFocus = Layout.SetLoopFocus,
    PassFocusToChild = Layout.SetPassFocusToChild
    }};
end

local LayoutComponent = ccui.LayoutComponent;
function LayoutComponent.__properties__()
    return {
    r = {
    UsingPercentContentSize = LayoutComponent.GetUsingPercentContentSize,
    PercentContentSize = LayoutComponent.GetPercentContentSize,
    AnchorPosition = LayoutComponent.GetAnchorPosition,
    Position = LayoutComponent.GetPosition,
    XY = LayoutComponent.GetPosition,
    PositionPercentXEnabled = LayoutComponent.IsPositionPercentXEnabled,
    PositionPercentX = LayoutComponent.GetPositionPercentX,
    PositionPercentYEnabled = LayoutComponent.IsPositionPercentYEnabled,
    PositionPercentY = LayoutComponent.GetPositionPercentY,
    Horizontal = LayoutComponent.GetHorizontalEdge,
    Vertical = LayoutComponent.GetVerticalEdge,
    LeftMargin = LayoutComponent.GetLeftMargin,
    RightMargin = LayoutComponent.GetRightMargin,
    TopMargin = LayoutComponent.GetTopMargin,
    BottomMargin = LayoutComponent.GetBottomMargin,
    Size = LayoutComponent.GetSize,
    PercentWidthEnabled = LayoutComponent.IsPercentWidthEnabled,
    SizeWidth = LayoutComponent.GetSizeWidth,
    PercentWidth = LayoutComponent.GetPercentWidth,
    PercentHeightEnabled = LayoutComponent.IsPercentHeightEnabled,
    SizeHeight = LayoutComponent.GetSizeHeight,
    PercentHeight = LayoutComponent.GetPercentHeight,
    StretchWidthEnabled = LayoutComponent.IsStretchWidthEnabled,
    StretchHeightEnabled = LayoutComponent.IsStretchHeightEnabled,
    },
    w = {
    UsingPercentContentSize = LayoutComponent.SetUsingPercentContentSize,
    PercentContentSize = LayoutComponent.SetPercentContentSize,
    AnchorPosition = LayoutComponent.SetAnchorPosition,
    Position = LayoutComponent.SetPosition,
    XY = LayoutComponent.SetPosition,
    PositionPercentXEnabled = LayoutComponent.SetPositionPercentXEnabled,
    PositionPercentX = LayoutComponent.SetPositionPercentX,
    PositionPercentYEnabled = LayoutComponent.SetPositionPercentYEnabled,
    PositionPercentY = LayoutComponent.SetPositionPercentY,
    Horizontal = LayoutComponent.SetHorizontalEdge,
    Vertical = LayoutComponent.SetVerticalEdge,
    LeftMargin = LayoutComponent.SetLeftMargin,
    RightMargin = LayoutComponent.SetRightMargin,
    TopMargin = LayoutComponent.SetTopMargin,
    BottomMargin = LayoutComponent.SetBottomMargin,
    Size = LayoutComponent.SetSize,
    PercentWidthEnabled = LayoutComponent.SetPercentWidthEnabled,
    SizeWidth = LayoutComponent.SetSizeWidth,
    PercentWidth = LayoutComponent.SetPercentWidth,
    PercentHeightEnabled = LayoutComponent.SetPercentHeightEnabled,
    SizeHeight = LayoutComponent.SetSizeHeight,
    PercentHeight = LayoutComponent.SetPercentHeight,
    StretchWidthEnabled = LayoutComponent.SetStretchWidthEnabled,
    StretchHeightEnabled = LayoutComponent.SetStretchHeightEnabled,
    PercentOnlyEnabled = LayoutComponent.SetPercentOnlyEnabled,
    ActiveEnabled = LayoutComponent.SetActiveEnabled,
    }};
end

local LayoutParameter = ccui.LayoutParameter;
function LayoutParameter.__properties__()
    return {
    r = {
    Margin = LayoutParameter.GetMargin,
    LayoutType = LayoutParameter.GetLayoutType
    },
    w = {
    Margin = LayoutParameter.SetMargin
    }};
end

local LinearLayoutParameter = ccui.LinearLayoutParameter;
function LinearLayoutParameter.__properties__()
    return {
    r = {
    Gravity = LinearLayoutParameter.GetGravity
    },
    w = {
    Gravity = LinearLayoutParameter.SetGravity
    }};
end

local RelativeLayoutParameter = ccui.RelativeLayoutParameter;
function RelativeLayoutParameter.__properties__()
    return {
    r = {
    Align = RelativeLayoutParameter.GetAlign,
    RelativeToWidgetName = RelativeLayoutParameter.GetRelativeToWidgetName,
    RelativeName = RelativeLayoutParameter.GetRelativeName
    },
    w = {
    Align = RelativeLayoutParameter.SetAlign,
    RelativeToWidgetName = RelativeLayoutParameter.SetRelativeToWidgetName,
    RelativeName = RelativeLayoutParameter.SetRelativeName
    }};
end

local EditBox = ccui.EditBox;
function EditBox.__properties__()
    return {
    r = {
    CapInsetsNormalRenderer = EditBox.GetCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = EditBox.GetCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = EditBox.GetCapInsetsDisabledRenderer,
    Text = EditBox.GetText,
    FontName = EditBox.GetFontName,
    FontSize = EditBox.GetFontSize,
    FontColor = EditBox.GetFontColor,
    PlaceholderFontName = EditBox.GetPlaceholderFontName,
    PlaceholderFontSize = EditBox.GetPlaceholderFontSize,
    PlaceholderFontColor = EditBox.GetPlaceholderFontColor,
    PlaceHolder = EditBox.GetPlaceHolder,
    InputMode = EditBox.GetInputMode,
    MaxLength = EditBox.GetMaxLength,
    InputFlag = EditBox.GetInputFlag,
    ReturnType = EditBox.GetReturnType,
    TextHorizontalAlignment = EditBox.GetTextHorizontalAlignment
    },
    w = {
    CapInsets = EditBox.SetCapInsets,
    CapInsetsNormalRenderer = EditBox.SetCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = EditBox.SetCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = EditBox.SetCapInsetsDisabledRenderer,
    Text = EditBox.SetText,
    FontName = EditBox.SetFontName,
    FontSize = EditBox.SetFontSize,
    FontColor = EditBox.SetFontColor,
    PlaceholderFontName = EditBox.SetPlaceholderFontName,
    PlaceholderFontSize = EditBox.SetPlaceholderFontSize,
    PlaceholderFontColor = EditBox.SetPlaceholderFontColor,
    PlaceHolder = EditBox.SetPlaceHolder,
    InputMode = EditBox.SetInputMode,
    MaxLength = EditBox.SetMaxLength,
    InputFlag = EditBox.SetInputFlag,
    ReturnType = EditBox.SetReturnType,
    TextHorizontalAlignment = EditBox.SetTextHorizontalAlignment,
    Handler = function(self,val)
        if val == nil then
            self:unregisterScriptEditBoxHandler();
        else
            self:registerScriptEditBoxHandler(val);
        end
    end
    }};
end

local ScrollView = ccui.ScrollView;
function ScrollView.__properties__()
    return {
    r = {
    Direction = ScrollView.GetDirection,
    InnerContainer = ScrollView.GetInnerContainer,
    ScrolledPercentVertical = ScrollView.GetScrolledPercentVertical,
    ScrolledPercentHorizontal = ScrollView.GetScrolledPercentHorizontal,
    ScrolledPercentBothDirection = ScrollView.GetScrolledPercentBothDirection,
    InnerContainerSize = ScrollView.GetInnerContainerSize,
    InnerContainerPosition = ScrollView.GetInnerContainerPosition,
    BounceEnabled = ScrollView.IsBounceEnabled,
    InertiaScrollEnabled = ScrollView.IsInertiaScrollEnabled,
    ScrollBarEnabled = ScrollView.IsScrollBarEnabled,
    ScrollBarPositionFromCornerForVertical = ScrollView.GetScrollBarPositionFromCornerForVertical,
    ScrollBarPositionFromCornerForHorizontal = ScrollView.GetScrollBarPositionFromCornerForHorizontal,
    ScrollBarWidth = ScrollView.GetScrollBarWidth,
    ScrollBarColor = ScrollView.GetScrollBarColor,
    ScrollBarOpacity = ScrollView.GetScrollBarOpacity,
    ScrollBarAutoHideEnabled = ScrollView.IsScrollBarAutoHideEnabled,
    ScrollBarAutoHideTime = ScrollView.GetScrollBarAutoHideTime,
    TouchTotalTimeThreshold = ScrollView.GetTouchTotalTimeThreshold,
    LayoutType = ScrollView.GetLayoutType,
    Scrolling = ScrollView.IsScrolling,
    AutoScrolling = ScrollView.IsAutoScrolling
    },
    w = {
    Direction = ScrollView.SetDirection,
    InnerContainerSize = ScrollView.SetInnerContainerSize,
    InnerContainerPosition = ScrollView.SetInnerContainerPosition,
    BounceEnabled = ScrollView.SetBounceEnabled,
    InertiaScrollEnabled = ScrollView.SetInertiaScrollEnabled,
    ScrollBarEnabled = ScrollView.SetScrollBarEnabled,
    ScrollBarPositionFromCorner = ScrollView.SetScrollBarPositionFromCorner,
    ScrollBarPositionFromCornerForVertical = ScrollView.SetScrollBarPositionFromCornerForVertical,
    ScrollBarPositionFromCornerForHorizontal = ScrollView.SetScrollBarPositionFromCornerForHorizontal,
    ScrollBarWidth = ScrollView.SetScrollBarWidth,
    ScrollBarColor = ScrollView.SetScrollBarColor,
    ScrollBarOpacity = ScrollView.SetScrollBarOpacity,
    ScrollBarAutoHideEnabled = ScrollView.SetScrollBarAutoHideEnabled,
    ScrollBarAutoHideTime = ScrollView.SetScrollBarAutoHideTime,
    TouchTotalTimeThreshold = ScrollView.SetTouchTotalTimeThreshold,
    LayoutType = ScrollView.SetLayoutType
    }};
end

local ListView = ccui.ListView;
function ListView.__properties__()
    return {
    r = {
    Items = ListView.GetItems,
    MagneticType = ListView.GetMagneticType,
    MagneticAllowedOutOfBoundary = ListView.GetMagneticAllowedOutOfBoundary,
    ItemsMargin = ListView.GetItemsMargin,
    LeftPadding = ListView.GetLeftPadding,
    TopPadding = ListView.GetTopPadding,
    RightPadding = ListView.GetRightPadding,
    BottomPadding = ListView.GetBottomPadding,
    ScrollDuration = ListView.GetScrollDuration,
    CenterItemInCurrentView = ListView.GetCenterItemInCurrentView,
    LeftmostItemInCurrentView = ListView.GetLeftmostItemInCurrentView,
    RightmostItemInCurrentView = ListView.GetRightmostItemInCurrentView,
    TopmostItemInCurrentView = ListView.GetTopmostItemInCurrentView,
    BottommostItemInCurrentView = ListView.GetBottommostItemInCurrentView,
    CurSelectedIndex = ListView.GetCurSelectedIndex
    },
    w = {
    ItemModel = ListView.SetItemModel,
    Gravity = ListView.SetGravity,
    MagneticType = ListView.SetMagneticType,
    MagneticAllowedOutOfBoundary = ListView.SetMagneticAllowedOutOfBoundary,
    ItemsMargin = ListView.SetItemsMargin,
    LeftPadding = ListView.SetLeftPadding,
    TopPadding = ListView.SetTopPadding,
    RightPadding = ListView.SetRightPadding,
    BottomPadding = ListView.SetBottomPadding,
    ScrollDuration = ListView.SetScrollDuration,
    CurSelectedIndex = ListView.SetCurSelectedIndex
    }};
end

local PageView = ccui.PageView;
function PageView.__properties__()
    return {
    r = {
    CurrentPageIndex = PageView.GetCurrentPageIndex,
    IndicatorEnabled = PageView.GetIndicatorEnabled,
    IndicatorPositionAsAnchorPoint = PageView.GetIndicatorPositionAsAnchorPoint,
    IndicatorPosition = PageView.GetIndicatorPosition,
    IndicatorSpaceBetweenIndexNodes = PageView.GetIndicatorSpaceBetweenIndexNodes,
    IndicatorSelectedIndexColor = PageView.GetIndicatorSelectedIndexColor,
    IndicatorIndexNodesColor = PageView.GetIndicatorIndexNodesColor,
    getIndicatorSelectedIndexOpacity = PageView.GetIndicatorSelectedIndexOpacity,
    IndicatorIndexNodesOpacity = PageView.GetIndicatorIndexNodesOpacity,
    IndicatorIndexNodesScale = PageView.GetIndicatorIndexNodesScale
    },
    w = {
    CurrentPageIndex = PageView.SetCurrentPageIndex,
    IndicatorEnabled = PageView.SetIndicatorEnabled,
    IndicatorPositionAsAnchorPoint = PageView.SetIndicatorPositionAsAnchorPoint,
    IndicatorPosition = PageView.SetIndicatorPosition,
    IndicatorSpaceBetweenIndexNodes = PageView.SetIndicatorSpaceBetweenIndexNodes,
    IndicatorSelectedIndexColor = PageView.SetIndicatorSelectedIndexColor,
    IndicatorIndexNodesColor = PageView.SetIndicatorIndexNodesColor,
    getIndicatorSelectedIndexOpacity = PageView.SetIndicatorSelectedIndexOpacity,
    IndicatorIndexNodesOpacity = PageView.SetIndicatorIndexNodesOpacity,
    IndicatorIndexNodesScale = PageView.SetIndicatorIndexNodesScale,
    IndicatorIndexNodesTexture = PageView.SetIndicatorIndexNodesTexture,
    AutoScrollStopEpsilon = PageView.SetAutoScrollStopEpsilon
    }};
end

local Button = ccui.Button;
function Button.__properties__()
    return {
    r = {
    CapInsetsNormalRenderer = Button.GetCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = Button.GetCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = Button.GetCapInsetsDisabledRenderer,
    Scale9Enabled = Button.IsScale9Enabled,
    TitleRenderer = Button.GetTitleRenderer,
    TitleText = Button.GetTitleText,
    Text = Button.GetTitleText,
    TitleColor = Button.GetTitleColor,
    TitleFontSize = Button.GetTitleFontSize,
    TitleFontName = Button.GetTitleFontName,
    TitleLabel = Button.GetTitleLabel,
    ZoomScale = Button.GetZoomScale,
    RendererNormal = Button.GetRendererNormal,
    RendererClicked = Button.GetRendererClicked,
    RendererDisabled = Button.GetRendererDisabled,
    NormalFile = Button.GetNormalFile,
    PressedFile = Button.GetPressedFile,
    DisabledFile = Button.GetDisabledFile
    },
    w = {
    CapInsets = Button.SetCapInsets,
    CapInsetsNormalRenderer = Button.SetCapInsetsNormalRenderer,
    CapInsetsPressedRenderer = Button.SetCapInsetsPressedRenderer,
    CapInsetsDisabledRenderer = Button.SetCapInsetsDisabledRenderer,
    Scale9Enabled = Button.SetScale9Enabled,
    PressedActionEnabled = Button.SetPressedActionEnabled,
    TitleText = Button.SetTitleText,
    TitleColor = Button.SetTitleColor,
    TitleFontSize = Button.SetTitleFontSize,
    TitleFontName = Button.SetTitleFontName,
    TitleAlignment = Button.SetTitleAlignment,
    TitleLabel = Button.SetTitleLabel,
    ZoomScale = Button.SetZoomScale
    }};
end

local AbstractCheckButton = ccui.AbstractCheckButton;
function AbstractCheckButton.__properties__()
    return {
    r = {
    Selected = AbstractCheckButton.IsSelected,
    ZoomScale = AbstractCheckButton.GetZoomScale,
    RendererBackground = AbstractCheckButton.GetRendererBackground,
    RendererBackgroundSelected = AbstractCheckButton.GetRendererBackgroundSelected,
    RendererFrontCross = AbstractCheckButton.GetRendererFrontCross,
    RendererBackgroundDisabled = AbstractCheckButton.GetRendererBackgroundDisabled,
    RendererFrontCrossDisabled = AbstractCheckButton.GetRendererFrontCrossDisabled,
    BackNormalFile = AbstractCheckButton.GetBackNormalFile,
    BackPressedFile = AbstractCheckButton.GetBackPressedFile,
    BackDisabledFile = AbstractCheckButton.GetBackDisabledFile,
    CrossNormalFile = AbstractCheckButton.GetCrossNormalFile,
    CrossDisabledFile = AbstractCheckButton.GetCrossDisabledFile
    },
    w = {
    Selected = AbstractCheckButton.SetSelected,
    ZoomScale = AbstractCheckButton.SetZoomScale
    }};
end

local ImageView = ccui.ImageView;
function ImageView.__properties__()
    return {
    r = {
    Scale9Enabled = ImageView.IsScale9Enabled,
    CapInsets = ImageView.GetCapInsets,
    RenderFile = ImageView.GetRenderFile,
    Renderer = ImageView.GetRenderer,
    Grayed = function(self)
        return self.Renderer:getState() == Scale9Sprite.State.GRAY;
    end
    },
    w = {
    TextureRect = ImageView.SetTextureRect,
    Scale9Enabled = ImageView.SetScale9Enabled,
    CapInsets = ImageView.SetCapInsets,
    Grayed = function(self,val)
        if val then
            self.Renderer:setState(Scale9Sprite.State.GRAY);
        else
            self.Renderer:setState(Scale9Sprite.State.NORMAL);
        end
    end
    }};
end

local LoadingBar = ccui.LoadingBar;
function LoadingBar.__properties__()
    return {
    r = {
    Direction = LoadingBar.GetDirection,
    Percent = function(self)
        return LoadingBar.getPercent(self) / 100;
    end,
    Scale9Enabled = LoadingBar.IsScale9Enabled,
    CapInsets = LoadingBar.GetCapInsets,
    RenderFile = LoadingBar.GetRenderFile
    },
    w = {
    Direction = LoadingBar.SetDirection,
    Percent = function(self,val)
        LoadingBar.setPercent(self,val * 100);
    end,
    Scale9Enabled = LoadingBar.SetScale9Enabled,
    CapInsets = LoadingBar.SetCapInsets
    }};
end

local RadioButtonGroup = ccui.RadioButtonGroup;
function RadioButtonGroup.__properties__()
    return {
    r = {
    SelectedButtonIndex = RadioButtonGroup.GetSelectedButtonIndex,
    NumberOfRadioButtons = RadioButtonGroup.GetNumberOfRadioButtons,
    AllowedNoSelection = RadioButtonGroup.IsAllowedNoSelection
    },
    w = {
    SelectedButton = RadioButtonGroup.SetSelectedButton,
    SelectedButtonWithoutEvent = RadioButtonGroup.SetSelectedButtonWithoutEvent,
    AllowedNoSelection = RadioButtonGroup.SetAllowedNoSelection
    }};
end

local RichElement = ccui.RichElement;
function RichElement.__properties__()
    return {
    r = {
    },
    w = {
    Color = RichElement.SetColor
    }};
end

local RichElementImage = ccui.RichElementImage;
function RichElementImage.__properties__()
    return {
    r = {
    },
    w = {
    Width = RichElementImage.SetWidth,
    Height = RichElementImage.SetHeight,
    Url = RichElementImage.SetUrl
    }};
end

local RichText = ccui.RichText;
function RichText.__properties__()
    return {
    r = {
    FontColor3B = RichText.GetFontColor3B,
    AnchorFontColor3B = RichText.GetAnchorFontColor3B,
    WrapMode = RichText.GetWrapMode,
    HorizontalAlignment = RichText.GetHorizontalAlignment,
    FontColor = RichText.GetFontColor,
    FontSize = RichText.GetFontSize,
    FontFace = RichText.GetFontFace,
    AnchorFontColor = RichText.GetAnchorFontColor,
    AnchorTextBoldEnabled = RichText.IsAnchorTextBoldEnabled,
    AnchorTextItalicEnabled = RichText.IsAnchorTextItalicEnabled,
    AnchorTextDelEnabled = RichText.IsAnchorTextDelEnabled,
    AnchorTextUnderlineEnabled = RichText.IsAnchorTextUnderlineEnabled,
    AnchorTextOutlineEnabled = RichText.IsAnchorTextOutlineEnabled,
    AnchorTextOutlineColor3B = RichText.GetAnchorTextOutlineColor3B,
    AnchorTextOutlineSize = RichText.GetAnchorTextOutlineSize,
    AnchorTextShadowEnabled = RichText.IsAnchorTextShadowEnabled,
    AnchorTextShadowColor3B = RichText.GetAnchorTextShadowColor3B,
    AnchorTextShadowOffset = RichText.GetAnchorTextShadowOffset,
    AnchorTextShadowBlurRadius = RichText.GetAnchorTextShadowBlurRadius,
    AnchorTextGlowEnabled = RichText.IsAnchorTextGlowEnabled,
    AnchorTextGlowColor3B = RichText.GetAnchorTextGlowColor3B,
    Defaults = RichText.GetDefaults
    },
    w = {
    VerticalSpace = RichText.SetVerticalSpace,
    WrapMode = RichText.SetWrapMode,
    HorizontalAlignment = RichText.SetHorizontalAlignment,
    FontColor = RichText.SetFontColor,
    FontSize = RichText.SetFontSize,
    FontFace = RichText.SetFontFace,
    AnchorFontColor = RichText.SetAnchorFontColor,
    AnchorTextBoldEnabled = RichText.SetAnchorTextBold,
    AnchorTextItalicEnabled = RichText.SetAnchorTextItalic,
    AnchorTextDelEnabled = RichText.SetAnchorTextDel,
    AnchorTextUnderlineEnabled = RichText.SetAnchorTextUnderline,
    AnchorTextOutline = RichText.SetAnchorTextOutline,
    AnchorTextShadow = RichText.SetAnchorTextShadow,
    AnchorTextGlow = RichText.SetAnchorTextGlow,
    Defaults = RichText.SetDefaults
    }};
end

local Slider = ccui.Slider;
function Slider.__properties__()
    return {
    r = {
    Scale9Enabled = Slider.IsScale9Enabled,
    CapInsetsBarRenderer = Slider.GetCapInsetsBarRenderer,
    CapInsetProgressBarRenderer = Slider.GetCapInsetProgressBarRenderer,
    Percent = function(self)
        return Slider.getPercent(self) / 100;
    end,
    MaxPercent = function(self)
        return Slider.getMaxPercent(self) / 100;
    end,
    ZoomScale = Slider.GetZoomScale,
    SlidBallNormalRenderer = Slider.GetSlidBallNormalRenderer,
    SlidBallPressedRenderer = Slider.GetSlidBallPressedRenderer,
    SlidBallDisabledRenderer = Slider.GetSlidBallDisabledRenderer,
    SlidBallRenderer = Slider.GetSlidBallRenderer,
    BackFile = Slider.GetBackFile,
    ProgressBarFile = Slider.GetProgressBarFile,
    BallNormalFile = Slider.GetBallNormalFile,
    BallPressedFile = Slider.GetBallPressedFile,
    BallDisabledFile = Slider.GetBallDisabledFile
    },
    w = {
    Scale9Enabled = Slider.SetScale9Enabled,
    CapInsets = Slider.SetCapInsets,
    CapInsetsBarRenderer = Slider.SetCapInsetsBarRenderer,
    CapInsetProgressBarRenderer = Slider.SetCapInsetProgressBarRenderer,
    Percent = function(self,val)
        Slider.setPercent(self,val * 100);
    end,
    MaxPercent = function(self,val)
        Slider.setMaxPercent(self,val * 100);
    end,
    ZoomScale = Slider.SetZoomScale
    }};
end

local TabHeader = ccui.TabHeader;
function TabHeader.__properties__()
    return {
    r = {
    TitleRenderer = TabHeader.GetTitleRenderer,
    TitleText = TabHeader.GetTitleText,
    Text = TabHeader.GetTitleText,
    TitleColor = TabHeader.GetTitleColor,
    TitleFontSize = TabHeader.GetTitleFontSize,
    TitleFontName = TabHeader.GetTitleFontName,
    IndexInTabControl = TabHeader.GetIndexInTabControl
    },
    w = {
    TitleText = TabHeader.SetTitleText,
    Text = TabHeader.SetTitleText,
    TitleColor = TabHeader.SetTitleColor,
    TitleFontSize = TabHeader.SetTitleFontSize,
    TitleFontName = TabHeader.SetTitleFontName
    }};
end

local TabControl = ccui.TabControl;
function TabControl.__properties__()
    return {
    r = {
    TabCount = TabControl.GetTabCount,
    SelectedTabIndex = TabControl.GetSelectedTabIndex,
    HeaderWidth = TabControl.GetHeaderWidth,
    HeaderHeight = TabControl.GetHeaderHeight,
    IgnoreHeadersTextureSize = TabControl.IsIgnoreHeadersTextureSize,
    HeaderSelectedZoom = TabControl.GetHeaderSelectedZoom,
    HeaderDockPlace = TabControl.GetHeaderDockPlace
    },
    w = {
    SelectTab = TabControl.SetSelectTab,
    HeaderWidth = TabControl.SetHeaderWidth,
    HeaderHeight = TabControl.SetHeaderHeight,
    IgnoreHeadersTextureSize = TabControl.IgnoreHeadersTextureSize,
    HeaderSelectedZoom = TabControl.SetHeaderSelectedZoom,
    HeaderDockPlace = TabControl.SetHeaderDockPlace
    }};
end

local Text = ccui.Text;
function Text.__properties__()
    return {
    r = {
    String = Text.GetString,
    Text = Text.GetString,
    StringLength = Text.GetStringLength,
    TextLength = Text.GetStringLength,
    FontSize = Text.GetFontSize,
    FontName = Text.GetFontName,
    Type = Text.GetType,
    TouchScaleChangeEnabled = Text.IsTouchScaleChangeEnabled,
    AutoRenderSize = Text.GetAutoRenderSize,
    TextAreaSize = Text.GetTextAreaSize,
    TextHorizontalAlignment = Text.GetTextHorizontalAlignment,
    TextVerticalAlignment = Text.GetTextVerticalAlignment,
    TextColor = Text.GetTextColor,
    ShadowEnabled = Text.IsShadowEnabled,
    ShadowOffset = Text.GetShadowOffset,
    ShadowBlurRadius = Text.GetShadowBlurRadius,
    ShadowColor = Text.GetShadowColor,
    OutlineSize = Text.GetOutlineSize,
    LabelEffectType = Text.GetLabelEffectType,
    EffectColor = Text.GetEffectColor,
    BlendFunc = Text.GetBlendFunc
    },
    w = {
    String = Text.SetString,
    Text = Text.SetString,
    FontSize = Text.SetFontSize,
    FontName = Text.SetFontName,
    TouchScaleChangeEnabled = Text.SetTouchScaleChangeEnabled,
    TextAreaSize = Text.SetTextAreaSize,
    TextHorizontalAlignment = Text.SetTextHorizontalAlignment,
    TextVerticalAlignment = Text.SetTextVerticalAlignment,
    TextColor = Text.SetTextColor,
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
    BlendFunc = Text.SetBlendFunc
    }};
end

local TextAtlas = ccui.TextAtlas;
function TextAtlas.__properties__()
    return {
    r = {
    String = TextAtlas.GetString,
    Text = TextAtlas.GetString,
    StringLength = TextAtlas.GetStringLength,
    RenderFile = TextAtlas.GetRenderFile
    },
    w = {
    String = TextAtlas.SetString,
    Text = TextAtlas.SetString
    }};
end

local TextBMFont = ccui.TextBMFont;
function TextBMFont.__properties__()
    return {
    r = {
    String = TextBMFont.GetString,
    Text = TextBMFont.GetString,
    StringLength = TextBMFont.GetStringLength,
    RenderFile = TextBMFont.GetRenderFile
    },
    w = {
    String = TextBMFont.SetString,
    Text = TextBMFont.SetString
    }};
end

local TextField = ccui.TextField;
function TextField.__properties__()
    return {
    r = {
    TouchSize = TextField.GetTouchSize,
    PlaceHolder = TextField.GetPlaceHolder,
    PlaceholderColor = TextField.GetPlaceholderColor,
    TextColor = TextField.GetTextColor,
    FontSize = TextField.GetFontSize,
    FontName = TextField.GetFontName,
    String = TextField.GetString,
    Text = TextField.GetString,
    MaxLengthEnabled = TextField.IsMaxLengthEnabled,
    MaxLength = TextField.GetMaxLength,
    StringLength = TextField.GetStringLength,
    PasswordEnabled = TextField.IsPasswordEnabled,
    PasswordStyleText = TextField.GetPasswordStyleText,
    AttachWithIME = TextField.GetAttachWithIME,
    DetachWithIME = TextField.GetDetachWithIME,
    InsertText = TextField.GetInsertText,
    DeleteBackward = TextField.GetDeleteBackward,
    AutoRenderSize = TextField.GetAutoRenderSize,
    TextHorizontalAlignment = TextField.GetTextHorizontalAlignment,
    TextVerticalAlignment = TextField.GetTextVerticalAlignment
    },
    w = {
    TouchSize = TextField.SetTouchSize,
    TouchAreaEnabled = TextField.SetTouchAreaEnabled,
    PlaceHolder = TextField.SetPlaceHolder,
    PlaceholderColor = TextField.SetPlaceholderColor,
    TextColor = TextField.SetTextColor,
    FontSize = TextField.SetFontSize,
    FontName = TextField.SetFontName,
    String = TextField.SetString,
    Text = TextField.SetString,
    MaxLengthEnabled = TextField.SetMaxLengthEnabled,
    MaxLength = TextField.SetMaxLength,
    StringLength = TextField.SetStringLength,
    PasswordEnabled = TextField.SetPasswordEnabled,
    PasswordStyleText = TextField.SetPasswordStyleText,
    AttachWithIME = TextField.SetAttachWithIME,
    DetachWithIME = TextField.SetDetachWithIME,
    InsertText = TextField.SetInsertText,
    DeleteBackward = TextField.SetDeleteBackward,
    TextAreaSize = TextField.SetTextAreaSize,
    TextHorizontalAlignment = TextField.SetTextHorizontalAlignment,
    TextVerticalAlignment = TextField.SetTextVerticalAlignment,
    CursorEnabled = TextField.SetCursorEnabled,
    CursorChar = TextField.SetCursorChar,
    CursorPosition = TextField.SetCursorPosition
    }};
end

local VideoPlayer = ccui.VideoPlayer;
function VideoPlayer.__properties__()
    return {
    r = {
    FileName = VideoPlayer.GetFileName,
    File = VideoPlayer.GetFileName,
    Url = VideoPlayer.GetURL,
    Playing = VideoPlayer.IsPlaying,
    Looping = VideoPlayer.IsLooping,
    UserInputEnabled = VideoPlayer.IsUserInputEnabled,
    KeepAspectRatioEnabled = VideoPlayer.IsKeepAspectRatioEnabled,
    FullScreenEnabled = VideoPlayer.IsFullScreenEnabled
    },
    w = {
    FileName = VideoPlayer.SetFileName,
    File = VideoPlayer.SetFileName,
    Url = VideoPlayer.SetURL,
    Looping = VideoPlayer.SetLooping,
    UserInputEnabled = VideoPlayer.SetUserInputEnabled,
    Style = VideoPlayer.SetStyle,
    KeepAspectRatioEnabled = VideoPlayer.SetKeepAspectRatioEnabled,
    FullScreenEnabled = VideoPlayer.SetFullScreenEnabled,
    EventHandler = VideoPlayer.AddEventListener
    }};
end

local WebView = ccui.WebView;
function WebView.__properties__()
    return {
    r = {
    OpacityWebView = WebView.GetOpacityWebView
    },
    w = {
    JavascriptInterfaceScheme = WebView.SetJavascriptInterfaceScheme,
    ScalesPageToFit = WebView.SetScalesPageToFit,
    OpacityWebView = WebView.SetOpacityWebView,
    BackgroundTransparent = WebView.SetBackgroundTransparent,
    FinishHandler = WebView.SetOnDidFinishLoading,
    FailHandler = WebView.SetOnDidFailLoading,
    StartHandler = WebView.SetOnShouldStartLoading,
    JsHandler = WebView.SetOnJSCallback,
    Url = WebView.LoadURL,
    File = WebView.LoadFile
    }};
end

local QrCode = ccui.QrCode;
function QrCode.__properties__()
    return {
    r = {
    },
    w = {
    String = QrCode.LoadCodeByString
    }};
end

local EventController = cc.EventController;
function EventController.__properties__()
    return {
    r = {
    ControllerEventType = EventController.GetControllerEventType,
    Controller = EventController.GetController,
    KeyCode = EventController.GetKeyCode,
    Connected = EventController.IsConnected
    },
    w = {
    KeyCode = EventController.SetKeyCode,
    ConnectStatus = EventController.SetConnectStatus,
    Connected = EventController.SetConnectStatus
    }};
end