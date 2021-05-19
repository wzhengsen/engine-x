#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
void RegisterLuaCoreClippingNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ClippingNode>("cc","ClippingNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ClippingNode*(*)(cocos2d::Node*)>(&cocos2d::ClippingNode::create),static_cast<cocos2d::ClippingNode*(*)()>(&cocos2d::ClippingNode::create)));
mt.set_function("GetStencil",static_cast<cocos2d::Node*(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getStencil));
mt.set_function("SetStencil",static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::setStencil));
mt.set_function("HasContent",static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::hasContent));
mt.set_function("GetAlphaThreshold",static_cast<float(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getAlphaThreshold));
mt.set_function("SetAlphaThreshold",static_cast<void(cocos2d::ClippingNode::*)(float)>(&cocos2d::ClippingNode::setAlphaThreshold));
mt.set_function("IsInverted",static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::isInverted));
mt.set_function("SetInverted",static_cast<void(cocos2d::ClippingNode::*)(bool)>(&cocos2d::ClippingNode::setInverted));
mt.set_function("OnEnter",static_cast<void(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::onEnter));
mt.set_function("OnEnterTransitionDidFinish",static_cast<void(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::onEnterTransitionDidFinish));
mt.set_function("OnExitTransitionDidStart",static_cast<void(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::onExitTransitionDidStart));
mt.set_function("OnExit",static_cast<void(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::onExit));
mt.set_function("Visit",static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingNode::visit));
mt.set_function("SetCameraMask",sol::overload([](cocos2d::ClippingNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ClippingNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
}
void RegisterLuaCoreClippingRectangleNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ClippingRectangleNode>("cc","ClippingRectangleNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ClippingRectangleNode*(*)()>(&cocos2d::ClippingRectangleNode::create),static_cast<cocos2d::ClippingRectangleNode*(*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::create)));
mt.set_function("GetClippingRegion",static_cast<const cocos2d::Rect&(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::getClippingRegion));
mt.set_function("SetClippingRegion",static_cast<void(cocos2d::ClippingRectangleNode::*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::setClippingRegion));
mt.set_function("IsClippingEnabled",static_cast<bool(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::isClippingEnabled));
mt.set_function("SetClippingEnabled",static_cast<void(cocos2d::ClippingRectangleNode::*)(bool)>(&cocos2d::ClippingRectangleNode::setClippingEnabled));
mt.set_function("Visit",static_cast<void(cocos2d::ClippingRectangleNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingRectangleNode::visit));
}
void RegisterLuaCoreDrawNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DrawNode>("cc","DrawNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::DrawNode* obj){return obj->create();},[](cocos2d::DrawNode* obj,float arg0){return obj->create(arg0);}));
mt.set_function("DrawPoint",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoint));
mt.set_function("DrawPoints",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoints),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoints)));
mt.set_function("DrawLine",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawLine));
mt.set_function("DrawRect",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect)));
mt.set_function("DrawPoly",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoly));
mt.set_function("DrawCircle",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle)));
mt.set_function("DrawQuadBezier",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawQuadBezier));
mt.set_function("DrawCubicBezier",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCubicBezier));
mt.set_function("DrawCardinalSpline",static_cast<void(cocos2d::DrawNode::*)(cocos2d::PointArray*,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCardinalSpline));
mt.set_function("DrawCatmullRom",static_cast<void(cocos2d::DrawNode::*)(cocos2d::PointArray*,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCatmullRom));
mt.set_function("DrawDot",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawDot));
mt.set_function("DrawSolidRect",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidRect));
mt.set_function("DrawSolidPoly",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidPoly));
mt.set_function("DrawSolidCircle",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle)));
mt.set_function("DrawSegment",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSegment));
mt.set_function("DrawPolygon",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,int,const cocos2d::Color4F&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPolygon));
mt.set_function("DrawTriangle",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawTriangle));
mt.set_function("Clear",static_cast<void(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::clear));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::getBlendFunc));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::DrawNode::setBlendFunc));
mt.set_function("Draw",static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::draw));
mt.set_function("Visit",static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::visit));
mt.set_function("SetLineWidth",static_cast<void(cocos2d::DrawNode::*)(float)>(&cocos2d::DrawNode::setLineWidth));
mt.set_function("GetLineWidth",static_cast<float(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::getLineWidth));
mt.set_function("SetIsolated",static_cast<void(cocos2d::DrawNode::*)(bool)>(&cocos2d::DrawNode::setIsolated));
mt.set_function("IsIsolated",static_cast<bool(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::isIsolated));
}
void RegisterLuaCoreLabelOverflowAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Label"];
pTable.new_enum<cocos2d::Label::Overflow>("Overflow",{
{"NONE",cocos2d::Label::Overflow::NONE}
,{"CLAMP",cocos2d::Label::Overflow::CLAMP}
,{"SHRINK",cocos2d::Label::Overflow::SHRINK}
,{"RESIZE_HEIGHT",cocos2d::Label::Overflow::RESIZE_HEIGHT}
});}
void RegisterLuaCoreLabelLabelTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Label"];
pTable.new_enum<cocos2d::Label::LabelType>("LabelType",{
{"TTF",cocos2d::Label::LabelType::TTF}
,{"BMFONT",cocos2d::Label::LabelType::BMFONT}
,{"CHARMAP",cocos2d::Label::LabelType::CHARMAP}
,{"STRING_TEXTURE",cocos2d::Label::LabelType::STRING_TEXTURE}
});}
void RegisterLuaCoreLabelAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Label>("cc","Label",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::LabelProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Label*(*)()>(&cocos2d::Label::create));
mt.set_function("CreateWithSystemFont",sol::overload([](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithSystemFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->createWithSystemFont(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("CreateWithTTF",sol::overload([](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1){return obj->createWithTTF(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2){return obj->createWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2,int arg3){return obj->createWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->createWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->createWithTTF(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->createWithTTF(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("CreateWithBMFont",sol::overload(static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const cocos2d::Rect&,bool)>(&cocos2d::Label::createWithBMFont),[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->createWithBMFont(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2){return obj->createWithBMFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2,int arg3){return obj->createWithBMFont(arg0,arg1,arg2,arg3);},static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const std::string&)>(&cocos2d::Label::createWithBMFont)));
mt.set_function("CreateWithCharMap",sol::overload(static_cast<cocos2d::Label*(*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&)>(&cocos2d::Label::createWithCharMap)));
mt.set_function("SetTTFConfig",static_cast<bool(cocos2d::Label::*)(const cocos2d::TTFConfig&)>(&cocos2d::Label::setTTFConfig));
mt.set_function("GetTTFConfig",static_cast<const cocos2d::TTFConfig&(cocos2d::Label::*)()const>(&cocos2d::Label::getTTFConfig));
mt.set_function("SetBMFontFilePath",sol::overload([](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2,float arg3){return obj->setBMFontFilePath(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0){return obj->setBMFontFilePath(arg0);},[](cocos2d::Label* obj,const std::string& arg0,float arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);}));
mt.set_function("GetBMFontFilePath",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontFilePath));
mt.set_function("SetCharMap",sol::overload(static_cast<bool(cocos2d::Label::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setCharMap)));
mt.set_function("SetSystemFontName",static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setSystemFontName));
mt.set_function("GetSystemFontName",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontName));
mt.set_function("SetSystemFontSize",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setSystemFontSize));
mt.set_function("GetSystemFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontSize));
mt.set_function("RequestSystemFontRefresh",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::requestSystemFontRefresh));
mt.set_function("SetString",static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getString));
mt.set_function("GetStringNumLines",static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringNumLines));
mt.set_function("GetStringLength",static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringLength));
mt.set_function("SetTextColor",static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::setTextColor));
mt.set_function("GetTextColor",static_cast<const cocos2d::Color4B&(cocos2d::Label::*)()const>(&cocos2d::Label::getTextColor));
mt.set_function("EnableShadow",sol::overload([](cocos2d::Label* obj){return obj->enableShadow();},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableShadow(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){return obj->enableShadow(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1,int arg2){return obj->enableShadow(arg0,arg1,arg2);}));
mt.set_function("EnableOutline",sol::overload([](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableOutline(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,int arg1){return obj->enableOutline(arg0,arg1);}));
mt.set_function("EnableGlow",static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::enableGlow));
mt.set_function("EnableItalics",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableItalics));
mt.set_function("EnableBold",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableBold));
mt.set_function("EnableUnderline",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableUnderline));
mt.set_function("EnableStrikethrough",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableStrikethrough));
mt.set_function("DisableEffect",sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::LabelEffect)>(&cocos2d::Label::disableEffect),static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::disableEffect)));
mt.set_function("IsShadowEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isShadowEnabled));
mt.set_function("GetShadowOffset",static_cast<cocos2d::Size(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowOffset));
mt.set_function("GetShadowBlurRadius",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowBlurRadius));
mt.set_function("GetShadowColor",static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowColor));
mt.set_function("GetOutlineSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getOutlineSize));
mt.set_function("GetLabelEffectType",static_cast<cocos2d::LabelEffect(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelEffectType));
mt.set_function("GetEffectColor",static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getEffectColor));
mt.set_function("SetAlignment",sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::Label::setAlignment),static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setAlignment)));
mt.set_function("GetTextAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getTextAlignment));
mt.set_function("SetHorizontalAlignment",static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setHorizontalAlignment));
mt.set_function("GetHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getHorizontalAlignment));
mt.set_function("SetVerticalAlignment",static_cast<void(cocos2d::Label::*)(cocos2d::TextVAlignment)>(&cocos2d::Label::setVerticalAlignment));
mt.set_function("GetVerticalAlignment",static_cast<cocos2d::TextVAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getVerticalAlignment));
mt.set_function("SetLineBreakWithoutSpace",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setLineBreakWithoutSpace));
mt.set_function("SetMaxLineWidth",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setMaxLineWidth));
mt.set_function("GetMaxLineWidth",static_cast<float(cocos2d::Label::*)()>(&cocos2d::Label::getMaxLineWidth));
mt.set_function("SetBMFontSize",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setBMFontSize));
mt.set_function("GetBMFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontSize));
mt.set_function("EnableWrap",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::enableWrap));
mt.set_function("IsWrapEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isWrapEnabled));
mt.set_function("SetOverflow",static_cast<void(cocos2d::Label::*)(cocos2d::Label::Overflow)>(&cocos2d::Label::setOverflow));
mt.set_function("GetOverflow",static_cast<cocos2d::Label::Overflow(cocos2d::Label::*)()const>(&cocos2d::Label::getOverflow));
mt.set_function("SetWidth",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setWidth));
mt.set_function("GetWidth",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getWidth));
mt.set_function("SetHeight",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setHeight));
mt.set_function("GetHeight",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getHeight));
mt.set_function("SetDimensions",static_cast<void(cocos2d::Label::*)(float,float)>(&cocos2d::Label::setDimensions));
mt.set_function("GetDimensions",static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getDimensions));
mt.set_function("UpdateContent",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::updateContent));
mt.set_function("GetLetter",static_cast<cocos2d::Sprite*(cocos2d::Label::*)(int)>(&cocos2d::Label::getLetter));
mt.set_function("SetClipMarginEnabled",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setClipMarginEnabled));
mt.set_function("IsClipMarginEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isClipMarginEnabled));
mt.set_function("SetLineHeight",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineHeight));
mt.set_function("GetLineHeight",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineHeight));
mt.set_function("SetLineSpacing",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineSpacing));
mt.set_function("GetLineSpacing",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineSpacing));
mt.set_function("GetLabelType",static_cast<cocos2d::Label::LabelType(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelType));
mt.set_function("GetRenderingFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getRenderingFontSize));
mt.set_function("SetAdditionalKerning",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setAdditionalKerning));
mt.set_function("GetAdditionalKerning",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getAdditionalKerning));
mt.set_function("SetProgramState",sol::overload([](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("GetFontAtlas",static_cast<cocos2d::FontAtlas*(cocos2d::Label::*)()>(&cocos2d::Label::getFontAtlas));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Label::*)()const>(&cocos2d::Label::getBlendFunc));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::Label::*)(const cocos2d::BlendFunc&)>(&cocos2d::Label::setBlendFunc));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isOpacityModifyRGB));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setOpacityModifyRGB));
mt.set_function("UpdateDisplayedColor",static_cast<void(cocos2d::Label::*)(const cocos2d::Color3B&)>(&cocos2d::Label::updateDisplayedColor));
mt.set_function("UpdateDisplayedOpacity",static_cast<void(cocos2d::Label::*)(uint8_t)>(&cocos2d::Label::updateDisplayedOpacity));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::Label::*)()const>(&cocos2d::Label::getDescription));
mt.set_function("GetContentSize",static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getContentSize));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocos2d::Label::*)()const>(&cocos2d::Label::getBoundingBox));
mt.set_function("Visit",static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::visit));
mt.set_function("Draw",static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::draw));
mt.set_function("SetCameraMask",sol::overload([](cocos2d::Label* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Label* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::removeAllChildrenWithCleanup));
mt.set_function("RemoveChild",sol::overload([](cocos2d::Label* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Label* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("SetGlobalZOrder",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setGlobalZOrder));
RegisterLuaCoreLabelOverflowAuto(lua);
RegisterLuaCoreLabelLabelTypeAuto(lua);
}
void RegisterLuaCoreLabelAtlasAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LabelAtlas>("cc","LabelAtlas",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::LabelProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::create)));
mt.set_function("InitWithString",sol::overload(static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::initWithString)));
mt.set_function("SetString",static_cast<void(cocos2d::LabelAtlas::*)(const std::string&)>(&cocos2d::LabelAtlas::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getString));
mt.set_function("UpdateAtlasValues",static_cast<void(cocos2d::LabelAtlas::*)()>(&cocos2d::LabelAtlas::updateAtlasValues));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getDescription));
}
void RegisterLuaCoreTouchDispatchModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Touch"];
pTable.new_enum<cocos2d::Touch::DispatchMode>("DispatchMode",{
{"ALL_AT_ONCE",cocos2d::Touch::DispatchMode::ALL_AT_ONCE}
,{"ONE_BY_ONE",cocos2d::Touch::DispatchMode::ONE_BY_ONE}
});}
void RegisterLuaCoreTouchAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Touch>("cc","Touch",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocation));
mt.set_function("GetPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocation));
mt.set_function("GetStartLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocation));
mt.set_function("GetDelta",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getDelta));
mt.set_function("GetLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocationInView));
mt.set_function("GetPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocationInView));
mt.set_function("GetStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocationInView));
mt.set_function("SetTouchInfo",sol::overload(static_cast<void(cocos2d::Touch::*)(int,float,float,float,float)>(&cocos2d::Touch::setTouchInfo),static_cast<void(cocos2d::Touch::*)(int,float,float)>(&cocos2d::Touch::setTouchInfo)));
mt.set_function("GetId",static_cast<int(cocos2d::Touch::*)()const>(&cocos2d::Touch::getID));
mt.set_function("GetCurrentForce",static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getCurrentForce));
mt.set_function("GetMaxForce",static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getMaxForce));
mt[sol::call_constructor]=sol::constructors<cocos2d::Touch()>();
RegisterLuaCoreTouchDispatchModeAuto(lua);
}
void RegisterLuaCoreLayerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Layer>("cc","Layer",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create));
mt.set_function("OnTouchBegan",static_cast<bool(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchBegan));
mt.set_function("OnTouchMoved",static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchMoved));
mt.set_function("OnTouchEnded",static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchEnded));
mt.set_function("OnTouchCancelled",static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchCancelled));
mt.set_function("OnTouchesBegan",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesBegan));
mt.set_function("OnTouchesMoved",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesMoved));
mt.set_function("OnTouchesEnded",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesEnded));
mt.set_function("OnTouchesCancelled",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesCancelled));
mt.set_function("OnAcceleration",static_cast<void(cocos2d::Layer::*)(cocos2d::Acceleration*,cocos2d::Event*)>(&cocos2d::Layer::onAcceleration));
mt.set_function("OnKeyPressed",static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyPressed));
mt.set_function("OnKeyReleased",static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyReleased));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::Layer::*)()const>(&cocos2d::Layer::getDescription));
}
void RegisterLuaCoreLayerColorAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerColor>("cc","LayerColor",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)()>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::create)));
mt.set_function("ChangeWidth",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeWidth));
mt.set_function("ChangeHeight",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeHeight));
mt.set_function("ChangeWidthAndHeight",static_cast<void(cocos2d::LayerColor::*)(float,float)>(&cocos2d::LayerColor::changeWidthAndHeight));
mt.set_function("Draw",static_cast<void(cocos2d::LayerColor::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerColor::draw));
mt.set_function("SetContentSize",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::Size&)>(&cocos2d::LayerColor::setContentSize));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::LayerColor::*)()const>(&cocos2d::LayerColor::getBlendFunc));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerColor::setBlendFunc));
}
void RegisterLuaCoreLayerGradientAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerGradient>("cc","LayerGradient",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)()>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::create)));
mt.set_function("SetCompressedInterpolation",static_cast<void(cocos2d::LayerGradient::*)(bool)>(&cocos2d::LayerGradient::setCompressedInterpolation));
mt.set_function("IsCompressedInterpolation",static_cast<bool(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::isCompressedInterpolation));
mt.set_function("SetStartColor",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setStartColor));
mt.set_function("GetStartColor",static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartColor));
mt.set_function("SetEndColor",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setEndColor));
mt.set_function("GetEndColor",static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndColor));
mt.set_function("SetStartOpacity",static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setStartOpacity));
mt.set_function("GetStartOpacity",static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartOpacity));
mt.set_function("SetEndOpacity",static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setEndOpacity));
mt.set_function("GetEndOpacity",static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndOpacity));
mt.set_function("SetVector",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerGradient::setVector));
mt.set_function("GetVector",static_cast<const cocos2d::Vec2&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getVector));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getDescription));
}
void RegisterLuaCoreLayerRadialGradientAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerRadialGradient>("cc","LayerRadialGradient",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create)));
mt.set_function("Draw",static_cast<void(cocos2d::LayerRadialGradient::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerRadialGradient::draw));
mt.set_function("SetContentSize",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Size&)>(&cocos2d::LayerRadialGradient::setContentSize));
mt.set_function("SetStartOpacity",static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setStartOpacity));
mt.set_function("GetStartOpacity",static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartOpacity));
mt.set_function("SetEndOpacity",static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setEndOpacity));
mt.set_function("GetEndOpacity",static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndOpacity));
mt.set_function("SetRadius",static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setRadius));
mt.set_function("GetRadius",static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getRadius));
mt.set_function("SetCenter",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerRadialGradient::setCenter));
mt.set_function("GetCenter",static_cast<cocos2d::Vec2(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getCenter));
mt.set_function("SetExpand",static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setExpand));
mt.set_function("GetExpand",static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getExpand));
mt.set_function("SetStartColor",sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setStartColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setStartColor)));
mt.set_function("GetStartColor",static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor));
mt.set_function("GetStartColor3B",static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor3B));
mt.set_function("SetEndColor",sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setEndColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setEndColor)));
mt.set_function("GetEndColor",static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor));
mt.set_function("GetEndColor3B",static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor3B));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerRadialGradient::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<cocos2d::BlendFunc(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getBlendFunc));
}
