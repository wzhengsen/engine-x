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
void RegisterLuaCoreTouchDispatchModeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Touch"];
pTable.new_enum("DispatchMode"
,"ALL_AT_ONCE",0
,"ONE_BY_ONE",1
);}
void RegisterLuaCoreTouchAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Touch,cocos2d::Ref,cocos2d::LuaObject>("Touch",true);
ns["Touch"] = mt;
lua["Touch"] = sol::nil;
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
RegisterLuaCoreTouchDispatchModeAuto(lua);
}
void RegisterLuaCoreLayerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("Layer",false);
ns["Layer"] = mt;
lua["Layer"] = sol::nil;
mt.set_function("onTouchBegan",static_cast<bool(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchBegan));
mt.set_function("onTouchMoved",static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchMoved));
mt.set_function("onTouchEnded",static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchEnded));
mt.set_function("onTouchCancelled",static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchCancelled));
mt.set_function("onTouchesBegan",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *>&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesBegan));
mt.set_function("onTouchesMoved",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *>&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesMoved));
mt.set_function("onTouchesEnded",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *>&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesEnded));
mt.set_function("onTouchesCancelled",static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *>&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesCancelled));
mt.set_function("onAcceleration",static_cast<void(cocos2d::Layer::*)(cocos2d::Acceleration*,cocos2d::Event*)>(&cocos2d::Layer::onAcceleration));
mt.set_function("onKeyPressed",static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyPressed));
mt.set_function("onKeyReleased",static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyReleased));
mt.set_function("getDescription",static_cast<std::string(cocos2d::Layer::*)()const>(&cocos2d::Layer::getDescription));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create));
}
void RegisterLuaCoreLayerColorAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("LayerColor",false);
ns["LayerColor"] = mt;
lua["LayerColor"] = sol::nil;
mt.set_function("changeWidth",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeWidth));
mt.set_function("changeHeight",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeHeight));
mt.set_function("changeWidthAndHeight",static_cast<void(cocos2d::LayerColor::*)(float,float)>(&cocos2d::LayerColor::changeWidthAndHeight));
mt.set_function("draw",static_cast<void(cocos2d::LayerColor::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerColor::draw));
mt.set_function("setContentSize",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::Size&)>(&cocos2d::LayerColor::setContentSize));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::LayerColor::*)()const>(&cocos2d::LayerColor::getBlendFunc));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerColor::setBlendFunc));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)()>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::create)));
}
void RegisterLuaCoreLayerGradientAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::LayerGradient,cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("LayerGradient",false);
ns["LayerGradient"] = mt;
lua["LayerGradient"] = sol::nil;
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
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)()>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::create)));
}
void RegisterLuaCoreLayerRadialGradientAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::LayerRadialGradient,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("LayerRadialGradient",false);
ns["LayerRadialGradient"] = mt;
lua["LayerRadialGradient"] = sol::nil;
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
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create)));
}
void RegisterLuaCoreLayerMultiplexAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::LayerMultiplex,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("LayerMultiplex",false);
ns["LayerMultiplex"] = mt;
lua["LayerMultiplex"] = sol::nil;
mt.set_function("addLayer",static_cast<void(cocos2d::LayerMultiplex::*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::addLayer));
mt.set_function("switchTo",sol::overload(static_cast<void(cocos2d::LayerMultiplex::*)(int,bool)>(&cocos2d::LayerMultiplex::switchTo),static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchTo)));
mt.set_function("switchToAndReleaseMe",static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchToAndReleaseMe));
mt.set_function("getDescription",static_cast<std::string(cocos2d::LayerMultiplex::*)()const>(&cocos2d::LayerMultiplex::getDescription));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::LayerMultiplex*(*)()>(&cocos2d::LayerMultiplex::create));
mt.set_function("createWithArray",static_cast<cocos2d::LayerMultiplex*(*)(const cocos2d::Vector<cocos2d::Layer *>&)>(&cocos2d::LayerMultiplex::createWithArray));
mt.set_function("createWithLayer",static_cast<cocos2d::LayerMultiplex*(*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::createWithLayer));
}
void RegisterLuaCoreMenuItemAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("MenuItem",false);
ns["MenuItem"] = mt;
lua["MenuItem"] = sol::nil;
mt.set_function("rect",static_cast<cocos2d::Rect(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::rect));
mt.set_function("activate",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::activate));
mt.set_function("selected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::selected));
mt.set_function("unselected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::unselected));
mt.set_function("isEnabled",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isEnabled));
mt.set_function("setEnabled",static_cast<void(cocos2d::MenuItem::*)(bool)>(&cocos2d::MenuItem::setEnabled));
mt.set_function("isSelected",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isSelected));
mt.set_function("SetHandler",static_cast<void(cocos2d::MenuItem::*)(const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItem::SetHandler));
mt.set_function("getDescription",static_cast<std::string(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::getDescription));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItem*(*)(const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItem::create),static_cast<cocos2d::MenuItem*(*)()>(&cocos2d::MenuItem::create)));
}
void RegisterLuaCoreMenuItemLabelAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("MenuItemLabel",false);
ns["MenuItemLabel"] = mt;
lua["MenuItemLabel"] = sol::nil;
mt.set_function("setString",static_cast<void(cocos2d::MenuItemLabel::*)(const std::string&)>(&cocos2d::MenuItemLabel::setString));
mt.set_function("getString",static_cast<std::string(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getString));
mt.set_function("getDisabledColor",static_cast<const cocos2d::Color3B&(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getDisabledColor));
mt.set_function("setDisabledColor",static_cast<void(cocos2d::MenuItemLabel::*)(const cocos2d::Color3B&)>(&cocos2d::MenuItemLabel::setDisabledColor));
mt.set_function("getLabel",static_cast<cocos2d::Node*(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getLabel));
mt.set_function("setLabel",static_cast<void(cocos2d::MenuItemLabel::*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::setLabel));
mt.set_function("activate",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::activate));
mt.set_function("selected",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::selected));
mt.set_function("unselected",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::unselected));
mt.set_function("setEnabled",static_cast<void(cocos2d::MenuItemLabel::*)(bool)>(&cocos2d::MenuItemLabel::setEnabled));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::create),static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemLabel::create)));
}
void RegisterLuaCoreMenuItemAtlasFontAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::MenuItemAtlasFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("MenuItemAtlasFont",false);
ns["MenuItemAtlasFont"] = mt;
lua["MenuItemAtlasFont"] = sol::nil;
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemAtlasFont::create),static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char)>(&cocos2d::MenuItemAtlasFont::create)));
}
void RegisterLuaCoreMenuItemFontAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::MenuItemFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("MenuItemFont",false);
ns["MenuItemFont"] = mt;
lua["MenuItemFont"] = sol::nil;
mt.set_function("setFontSizeObj",static_cast<void(cocos2d::MenuItemFont::*)(int)>(&cocos2d::MenuItemFont::setFontSizeObj));
mt.set_function("getFontSizeObj",static_cast<int(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontSizeObj));
mt.set_function("setFontNameObj",static_cast<void(cocos2d::MenuItemFont::*)(const std::string&)>(&cocos2d::MenuItemFont::setFontNameObj));
mt.set_function("getFontNameObj",static_cast<const std::string&(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontNameObj));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemFont*(*)(const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemFont::create),[](cocos2d::MenuItemFont* obj){return obj->create();},[](cocos2d::MenuItemFont* obj,const std::string& arg0){return obj->create(arg0);}));
mt.set_function("setFontSize",static_cast<void(*)(int)>(&cocos2d::MenuItemFont::setFontSize));
mt.set_function("getFontSize",static_cast<int(*)()>(&cocos2d::MenuItemFont::getFontSize));
mt.set_function("setFontName",static_cast<void(*)(const std::string&)>(&cocos2d::MenuItemFont::setFontName));
mt.set_function("getFontName",static_cast<const std::string&(*)()>(&cocos2d::MenuItemFont::getFontName));
}
