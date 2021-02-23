#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreJumpTiles3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpTiles3D");
mt.set_function("getAmplitude",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone));
mt.set_function("update",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::JumpTiles3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create));
}
void RegisterLuaCoreSplitRowsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitRows,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SplitRows");
mt.set_function("clone",static_cast<cocos2d::SplitRows*(cocos2d::SplitRows::*)()const>(&cocos2d::SplitRows::clone));
mt.set_function("update",static_cast<void(cocos2d::SplitRows::*)(float)>(&cocos2d::SplitRows::update));
mt.set_function("startWithTarget",static_cast<void(cocos2d::SplitRows::*)(cocos2d::Node*)>(&cocos2d::SplitRows::startWithTarget));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::SplitRows::*)(float,unsigned int)>(&cocos2d::SplitRows::initWithDuration));
mt.set_function("new",static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create));
}
void RegisterLuaCoreSplitColsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitCols,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SplitCols");
mt.set_function("clone",static_cast<cocos2d::SplitCols*(cocos2d::SplitCols::*)()const>(&cocos2d::SplitCols::clone));
mt.set_function("update",static_cast<void(cocos2d::SplitCols::*)(float)>(&cocos2d::SplitCols::update));
mt.set_function("startWithTarget",static_cast<void(cocos2d::SplitCols::*)(cocos2d::Node*)>(&cocos2d::SplitCols::startWithTarget));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::SplitCols::*)(float,unsigned int)>(&cocos2d::SplitCols::initWithDuration));
mt.set_function("new",static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create));
}
void RegisterLuaCoreActionTweenAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionTween,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionTween");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionTween::*)(cocos2d::Node*)>(&cocos2d::ActionTween::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ActionTween::*)(float)>(&cocos2d::ActionTween::update));
mt.set_function("reverse",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::clone));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ActionTween::*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ActionTween*(*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::create));
}
void RegisterLuaCoreAtlasNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","AtlasNode");
mt.set_function("updateAtlasValues",static_cast<void(cocos2d::AtlasNode::*)()>(&cocos2d::AtlasNode::updateAtlasValues));
mt.set_function("draw",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AtlasNode::draw));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Texture2D*)>(&cocos2d::AtlasNode::setTexture));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::isOpacityModifyRGB));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::AtlasNode::*)(bool)>(&cocos2d::AtlasNode::setOpacityModifyRGB));
mt.set_function("getColor",static_cast<const cocos2d::Color3B&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getColor));
mt.set_function("setColor",static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::Color3B&)>(&cocos2d::AtlasNode::setColor));
mt.set_function("setOpacity",static_cast<void(cocos2d::AtlasNode::*)(uint8_t)>(&cocos2d::AtlasNode::setOpacity));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::AtlasNode::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getBlendFunc));
mt.set_function("setTextureAtlas",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::AtlasNode::setTextureAtlas));
mt.set_function("getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTextureAtlas));
mt.set_function("setQuadsToDraw",static_cast<void(cocos2d::AtlasNode::*)(ssize_t)>(&cocos2d::AtlasNode::setQuadsToDraw));
mt.set_function("getQuadsToDraw",static_cast<size_t(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getQuadsToDraw));
mt.set_function("setProgramState",sol::overload([](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("initWithTileFile",static_cast<bool(cocos2d::AtlasNode::*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::initWithTileFile));
mt.set_function("initWithTexture",static_cast<bool(cocos2d::AtlasNode::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::AtlasNode::initWithTexture));
mt.set_function("new",static_cast<cocos2d::AtlasNode*(*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::create));
}
void RegisterLuaCoreClippingNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ClippingNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ClippingNode");
mt.set_function("getStencil",static_cast<cocos2d::Node*(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getStencil));
mt.set_function("setStencil",static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::setStencil));
mt.set_function("hasContent",static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::hasContent));
mt.set_function("getAlphaThreshold",static_cast<float(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getAlphaThreshold));
mt.set_function("setAlphaThreshold",static_cast<void(cocos2d::ClippingNode::*)(float)>(&cocos2d::ClippingNode::setAlphaThreshold));
mt.set_function("isInverted",static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::isInverted));
mt.set_function("setInverted",static_cast<void(cocos2d::ClippingNode::*)(bool)>(&cocos2d::ClippingNode::setInverted));
mt.set_function("visit",static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingNode::visit));
mt.set_function("setCameraMask",sol::overload([](cocos2d::ClippingNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ClippingNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("init",sol::overload(static_cast<bool(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::init),static_cast<bool(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::init)));
mt.set_function("new",sol::overload(static_cast<cocos2d::ClippingNode*(*)(cocos2d::Node*)>(&cocos2d::ClippingNode::create),static_cast<cocos2d::ClippingNode*(*)()>(&cocos2d::ClippingNode::create)));
}
void RegisterLuaCoreClippingRectangleNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ClippingRectangleNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ClippingRectangleNode");
mt.set_function("getClippingRegion",static_cast<const cocos2d::Rect&(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::getClippingRegion));
mt.set_function("setClippingRegion",static_cast<void(cocos2d::ClippingRectangleNode::*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::setClippingRegion));
mt.set_function("isClippingEnabled",static_cast<bool(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::isClippingEnabled));
mt.set_function("setClippingEnabled",static_cast<void(cocos2d::ClippingRectangleNode::*)(bool)>(&cocos2d::ClippingRectangleNode::setClippingEnabled));
mt.set_function("visit",static_cast<void(cocos2d::ClippingRectangleNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingRectangleNode::visit));
mt.set_function("new",sol::overload(static_cast<cocos2d::ClippingRectangleNode*(*)()>(&cocos2d::ClippingRectangleNode::create),static_cast<cocos2d::ClippingRectangleNode*(*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::create)));
}
void RegisterLuaCoreDrawNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DrawNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","DrawNode");
mt.set_function("drawPoint",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoint));
mt.set_function("drawLine",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawLine));
mt.set_function("drawRect",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect)));
mt.set_function("drawCircle",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle)));
mt.set_function("drawQuadBezier",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawQuadBezier));
mt.set_function("drawCubicBezier",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCubicBezier));
mt.set_function("drawDot",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawDot));
mt.set_function("drawSolidRect",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidRect));
mt.set_function("drawSolidCircle",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle)));
mt.set_function("drawSegment",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSegment));
mt.set_function("drawTriangle",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawTriangle));
mt.set_function("clear",static_cast<void(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::clear));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::getBlendFunc));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::DrawNode::setBlendFunc));
mt.set_function("draw",static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::draw));
mt.set_function("visit",static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::visit));
mt.set_function("setLineWidth",static_cast<void(cocos2d::DrawNode::*)(float)>(&cocos2d::DrawNode::setLineWidth));
mt.set_function("getLineWidth",static_cast<float(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::getLineWidth));
mt.set_function("setIsolated",static_cast<void(cocos2d::DrawNode::*)(bool)>(&cocos2d::DrawNode::setIsolated));
mt.set_function("isIsolated",static_cast<bool(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::isIsolated));
mt.set_function("init",static_cast<bool(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::init));
mt.set_function("new",sol::overload([](cocos2d::DrawNode* obj){return obj->create();},[](cocos2d::DrawNode* obj,float arg0){return obj->create(arg0);}));
}
void RegisterLuaCoreLabelAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Label,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::LabelProtocol,cocos2d::BlendProtocol>("cc","Label");
mt.set_function("setTTFConfig",static_cast<bool(cocos2d::Label::*)(const cocos2d::TTFConfig&)>(&cocos2d::Label::setTTFConfig));
mt.set_function("getTTFConfig",static_cast<const cocos2d::TTFConfig&(cocos2d::Label::*)()const>(&cocos2d::Label::getTTFConfig));
mt.set_function("setBMFontFilePath",sol::overload([](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2,float arg3){return obj->setBMFontFilePath(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0){return obj->setBMFontFilePath(arg0);},[](cocos2d::Label* obj,const std::string& arg0,float arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);}));
mt.set_function("getBMFontFilePath",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontFilePath));
mt.set_function("setCharMap",sol::overload(static_cast<bool(cocos2d::Label::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setCharMap)));
mt.set_function("setSystemFontName",static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setSystemFontName));
mt.set_function("getSystemFontName",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontName));
mt.set_function("setSystemFontSize",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setSystemFontSize));
mt.set_function("getSystemFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontSize));
mt.set_function("requestSystemFontRefresh",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::requestSystemFontRefresh));
mt.set_function("setString",static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setString));
mt.set_function("getString",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getString));
mt.set_function("getStringNumLines",static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringNumLines));
mt.set_function("getStringLength",static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringLength));
mt.set_function("setTextColor",static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::setTextColor));
mt.set_function("getTextColor",static_cast<const cocos2d::Color4B&(cocos2d::Label::*)()const>(&cocos2d::Label::getTextColor));
mt.set_function("enableShadow",sol::overload([](cocos2d::Label* obj){return obj->enableShadow();},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableShadow(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){return obj->enableShadow(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1,int arg2){return obj->enableShadow(arg0,arg1,arg2);}));
mt.set_function("enableOutline",sol::overload([](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableOutline(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,int arg1){return obj->enableOutline(arg0,arg1);}));
mt.set_function("enableGlow",static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::enableGlow));
mt.set_function("enableItalics",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableItalics));
mt.set_function("enableBold",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableBold));
mt.set_function("enableUnderline",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableUnderline));
mt.set_function("enableStrikethrough",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableStrikethrough));
mt.set_function("disableEffect",sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::LabelEffect)>(&cocos2d::Label::disableEffect),static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::disableEffect)));
mt.set_function("isShadowEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isShadowEnabled));
mt.set_function("getShadowOffset",static_cast<cocos2d::Size(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowOffset));
mt.set_function("getShadowBlurRadius",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowBlurRadius));
mt.set_function("getShadowColor",static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowColor));
mt.set_function("getOutlineSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getOutlineSize));
mt.set_function("getLabelEffectType",static_cast<cocos2d::LabelEffect(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelEffectType));
mt.set_function("getEffectColor",static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getEffectColor));
mt.set_function("setAlignment",sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::Label::setAlignment),static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setAlignment)));
mt.set_function("getTextAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getTextAlignment));
mt.set_function("setHorizontalAlignment",static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setHorizontalAlignment));
mt.set_function("getHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getHorizontalAlignment));
mt.set_function("setVerticalAlignment",static_cast<void(cocos2d::Label::*)(cocos2d::TextVAlignment)>(&cocos2d::Label::setVerticalAlignment));
mt.set_function("getVerticalAlignment",static_cast<cocos2d::TextVAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getVerticalAlignment));
mt.set_function("setLineBreakWithoutSpace",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setLineBreakWithoutSpace));
mt.set_function("setMaxLineWidth",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setMaxLineWidth));
mt.set_function("getMaxLineWidth",static_cast<float(cocos2d::Label::*)()>(&cocos2d::Label::getMaxLineWidth));
mt.set_function("setBMFontSize",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setBMFontSize));
mt.set_function("getBMFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontSize));
mt.set_function("enableWrap",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::enableWrap));
mt.set_function("isWrapEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isWrapEnabled));
mt.set_function("setOverflow",static_cast<void(cocos2d::Label::*)(cocos2d::Label::Overflow)>(&cocos2d::Label::setOverflow));
mt.set_function("getOverflow",static_cast<cocos2d::Label::Overflow(cocos2d::Label::*)()const>(&cocos2d::Label::getOverflow));
mt.set_function("setWidth",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setWidth));
mt.set_function("getWidth",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getWidth));
mt.set_function("setHeight",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setHeight));
mt.set_function("getHeight",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getHeight));
mt.set_function("setDimensions",static_cast<void(cocos2d::Label::*)(float,float)>(&cocos2d::Label::setDimensions));
mt.set_function("getDimensions",static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getDimensions));
mt.set_function("updateContent",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::updateContent));
mt.set_function("getLetter",static_cast<cocos2d::Sprite*(cocos2d::Label::*)(int)>(&cocos2d::Label::getLetter));
mt.set_function("setClipMarginEnabled",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setClipMarginEnabled));
mt.set_function("isClipMarginEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isClipMarginEnabled));
mt.set_function("setLineHeight",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineHeight));
mt.set_function("getLineHeight",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineHeight));
mt.set_function("setLineSpacing",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineSpacing));
mt.set_function("getLineSpacing",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineSpacing));
mt.set_function("getLabelType",static_cast<cocos2d::Label::LabelType(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelType));
mt.set_function("getRenderingFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getRenderingFontSize));
mt.set_function("setAdditionalKerning",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setAdditionalKerning));
mt.set_function("getAdditionalKerning",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getAdditionalKerning));
mt.set_function("setProgramState",sol::overload([](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("getFontAtlas",static_cast<cocos2d::FontAtlas*(cocos2d::Label::*)()>(&cocos2d::Label::getFontAtlas));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Label::*)()const>(&cocos2d::Label::getBlendFunc));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::Label::*)(const cocos2d::BlendFunc&)>(&cocos2d::Label::setBlendFunc));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isOpacityModifyRGB));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setOpacityModifyRGB));
mt.set_function("updateDisplayedColor",static_cast<void(cocos2d::Label::*)(const cocos2d::Color3B&)>(&cocos2d::Label::updateDisplayedColor));
mt.set_function("updateDisplayedOpacity",static_cast<void(cocos2d::Label::*)(uint8_t)>(&cocos2d::Label::updateDisplayedOpacity));
mt.set_function("getDescription",static_cast<std::string(cocos2d::Label::*)()const>(&cocos2d::Label::getDescription));
mt.set_function("getContentSize",static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getContentSize));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Label::*)()const>(&cocos2d::Label::getBoundingBox));
mt.set_function("visit",static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::visit));
mt.set_function("draw",static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::draw));
mt.set_function("setCameraMask",sol::overload([](cocos2d::Label* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Label* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::removeAllChildrenWithCleanup));
mt.set_function("removeChild",sol::overload([](cocos2d::Label* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Label* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("setGlobalZOrder",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setGlobalZOrder));
mt.set_function("initWithTTF",sol::overload([](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1){return obj->initWithTTF(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2){return obj->initWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2,int arg3){return obj->initWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithTTF(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithTTF(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("new",static_cast<cocos2d::Label*(*)()>(&cocos2d::Label::create));
mt.set_function("createWithSystemFont",sol::overload([](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithSystemFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->createWithSystemFont(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("createWithBMFont",sol::overload(static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const cocos2d::Rect&,bool)>(&cocos2d::Label::createWithBMFont),[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->createWithBMFont(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2){return obj->createWithBMFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2,int arg3){return obj->createWithBMFont(arg0,arg1,arg2,arg3);},static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const std::string&)>(&cocos2d::Label::createWithBMFont)));
mt.set_function("createWithCharMap",sol::overload(static_cast<cocos2d::Label*(*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&)>(&cocos2d::Label::createWithCharMap)));
}
void RegisterLuaCoreLabelAtlasAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LabelAtlas,cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::LabelProtocol>("cc","LabelAtlas");
mt.set_function("initWithString",sol::overload(static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::initWithString)));
mt.set_function("setString",static_cast<void(cocos2d::LabelAtlas::*)(const std::string&)>(&cocos2d::LabelAtlas::setString));
mt.set_function("getString",static_cast<const std::string&(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getString));
mt.set_function("updateAtlasValues",static_cast<void(cocos2d::LabelAtlas::*)()>(&cocos2d::LabelAtlas::updateAtlasValues));
mt.set_function("getDescription",static_cast<std::string(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getDescription));
mt.set_function("new",sol::overload(static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::create)));
}
void RegisterLuaCoreTouchAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Touch,cocos2d::Ref,cocos2d::LuaObject>("cc","Touch");
mt.set_function("getLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocation));
mt.set_function("getPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocation));
mt.set_function("getStartLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocation));
mt.set_function("getDelta",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getDelta));
mt.set_function("getLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocationInView));
mt.set_function("getPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocationInView));
mt.set_function("getStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocationInView));
mt.set_function("setTouchInfo",sol::overload(static_cast<void(cocos2d::Touch::*)(int,float,float,float,float)>(&cocos2d::Touch::setTouchInfo),static_cast<void(cocos2d::Touch::*)(int,float,float)>(&cocos2d::Touch::setTouchInfo)));
mt.set_function("getId",static_cast<int(cocos2d::Touch::*)()const>(&cocos2d::Touch::getID));
mt.set_function("getCurrentForce",static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getCurrentForce));
mt.set_function("getMaxForce",static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getMaxForce));
}
void RegisterLuaCoreLayerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Layer");
mt.set_function("getDescription",static_cast<std::string(cocos2d::Layer::*)()const>(&cocos2d::Layer::getDescription));
mt.set_function("init",static_cast<bool(cocos2d::Layer::*)()>(&cocos2d::Layer::init));
mt.set_function("SetTouchHandler",static_cast<void(cocos2d::Layer::*)(const std::function<bool (cocos2d::Layer *, cocos2d::EventTouch::EventCode, cocos2d::Touch *)>&)>(&cocos2d::Layer::SetTouchHandler));
mt.set_function("SetTouchesHandler",static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::EventTouch::EventCode, const std::vector<cocos2d::Touch *>&)>&)>(&cocos2d::Layer::SetTouchesHandler));
mt.set_function("SetKeyHandler",static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::EventKeyboard::KeyCode, bool)>&)>(&cocos2d::Layer::SetKeyHandler));
mt.set_function("SetAccelerationHandler",static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::Acceleration *)>&)>(&cocos2d::Layer::SetAccelerationHandler));
mt.set_function("new",static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create));
}
void RegisterLuaCoreLayerColorAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","LayerColor");
mt.set_function("changeWidth",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeWidth));
mt.set_function("changeHeight",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeHeight));
mt.set_function("changeWidthAndHeight",static_cast<void(cocos2d::LayerColor::*)(float,float)>(&cocos2d::LayerColor::changeWidthAndHeight));
mt.set_function("draw",static_cast<void(cocos2d::LayerColor::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerColor::draw));
mt.set_function("setContentSize",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::Size&)>(&cocos2d::LayerColor::setContentSize));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::LayerColor::*)()const>(&cocos2d::LayerColor::getBlendFunc));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerColor::setBlendFunc));
mt.set_function("init",static_cast<bool(cocos2d::LayerColor::*)()>(&cocos2d::LayerColor::init));
mt.set_function("initWithColor",sol::overload(static_cast<bool(cocos2d::LayerColor::*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::initWithColor),static_cast<bool(cocos2d::LayerColor::*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::initWithColor)));
mt.set_function("new",sol::overload(static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)()>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::create)));
}
void RegisterLuaCoreLayerGradientAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerGradient,cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","LayerGradient");
mt.set_function("setCompressedInterpolation",static_cast<void(cocos2d::LayerGradient::*)(bool)>(&cocos2d::LayerGradient::setCompressedInterpolation));
mt.set_function("isCompressedInterpolation",static_cast<bool(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::isCompressedInterpolation));
mt.set_function("setStartColor",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setStartColor));
mt.set_function("getStartColor",static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartColor));
mt.set_function("setEndColor",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setEndColor));
mt.set_function("getEndColor",static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndColor));
mt.set_function("setStartOpacity",static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setStartOpacity));
mt.set_function("getStartOpacity",static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartOpacity));
mt.set_function("setEndOpacity",static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setEndOpacity));
mt.set_function("getEndOpacity",static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndOpacity));
mt.set_function("setVector",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerGradient::setVector));
mt.set_function("getVector",static_cast<const cocos2d::Vec2&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getVector));
mt.set_function("getDescription",static_cast<std::string(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getDescription));
mt.set_function("init",static_cast<bool(cocos2d::LayerGradient::*)()>(&cocos2d::LayerGradient::init));
mt.set_function("initWithColor",sol::overload(static_cast<bool(cocos2d::LayerGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::initWithColor),static_cast<bool(cocos2d::LayerGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::initWithColor)));
mt.set_function("new",sol::overload(static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)()>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::create)));
}
void RegisterLuaCoreLayerRadialGradientAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerRadialGradient,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","LayerRadialGradient");
mt.set_function("draw",static_cast<void(cocos2d::LayerRadialGradient::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerRadialGradient::draw));
mt.set_function("setContentSize",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Size&)>(&cocos2d::LayerRadialGradient::setContentSize));
mt.set_function("setStartOpacity",static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setStartOpacity));
mt.set_function("getStartOpacity",static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartOpacity));
mt.set_function("setEndOpacity",static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setEndOpacity));
mt.set_function("getEndOpacity",static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndOpacity));
mt.set_function("setRadius",static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setRadius));
mt.set_function("getRadius",static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getRadius));
mt.set_function("setCenter",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerRadialGradient::setCenter));
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getCenter));
mt.set_function("setExpand",static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setExpand));
mt.set_function("getExpand",static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getExpand));
mt.set_function("setStartColor",sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setStartColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setStartColor)));
mt.set_function("getStartColor",static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor));
mt.set_function("getStartColor3B",static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor3B));
mt.set_function("setEndColor",sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setEndColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setEndColor)));
mt.set_function("getEndColor",static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor));
mt.set_function("getEndColor3B",static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor3B));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerRadialGradient::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<cocos2d::BlendFunc(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getBlendFunc));
mt.set_function("initWithColor",static_cast<bool(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::initWithColor));
mt.set_function("new",sol::overload(static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create)));
}
