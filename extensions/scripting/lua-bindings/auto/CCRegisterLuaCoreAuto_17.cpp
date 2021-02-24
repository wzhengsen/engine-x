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
mt.set_function("new",sol::overload(static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create)));
}
void RegisterLuaCoreLayerMultiplexAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerMultiplex,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","LayerMultiplex");
mt.set_function("addLayer",static_cast<void(cocos2d::LayerMultiplex::*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::addLayer));
mt.set_function("switchTo",sol::overload(static_cast<void(cocos2d::LayerMultiplex::*)(int,bool)>(&cocos2d::LayerMultiplex::switchTo),static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchTo)));
mt.set_function("switchToAndReleaseMe",static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchToAndReleaseMe));
mt.set_function("getDescription",static_cast<std::string(cocos2d::LayerMultiplex::*)()const>(&cocos2d::LayerMultiplex::getDescription));
mt.set_function("new",static_cast<cocos2d::LayerMultiplex*(*)()>(&cocos2d::LayerMultiplex::create));
mt.set_function("createWithArray",static_cast<cocos2d::LayerMultiplex*(*)(const cocos2d::Vector<cocos2d::Layer *>&)>(&cocos2d::LayerMultiplex::createWithArray));
mt.set_function("createWithLayer",static_cast<cocos2d::LayerMultiplex*(*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::createWithLayer));
}
void RegisterLuaCoreMenuItemAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItem");
mt.set_function("rect",static_cast<cocos2d::Rect(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::rect));
mt.set_function("activate",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::activate));
mt.set_function("selected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::selected));
mt.set_function("unselected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::unselected));
mt.set_function("isEnabled",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isEnabled));
mt.set_function("setEnabled",static_cast<void(cocos2d::MenuItem::*)(bool)>(&cocos2d::MenuItem::setEnabled));
mt.set_function("isSelected",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isSelected));
mt.set_function("SetHandler",static_cast<void(cocos2d::MenuItem::*)(const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItem::SetHandler));
mt.set_function("getDescription",static_cast<std::string(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::getDescription));
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItem*(*)(const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItem::create),static_cast<cocos2d::MenuItem*(*)()>(&cocos2d::MenuItem::create)));
}
void RegisterLuaCoreMenuItemLabelAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemLabel");
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
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::create),static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemLabel::create)));
}
void RegisterLuaCoreMenuItemAtlasFontAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemAtlasFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemAtlasFont");
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemAtlasFont::create),static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char)>(&cocos2d::MenuItemAtlasFont::create)));
}
void RegisterLuaCoreMenuItemFontAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemFont");
mt.set_function("setFontSizeObj",static_cast<void(cocos2d::MenuItemFont::*)(int)>(&cocos2d::MenuItemFont::setFontSizeObj));
mt.set_function("getFontSizeObj",static_cast<int(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontSizeObj));
mt.set_function("setFontNameObj",static_cast<void(cocos2d::MenuItemFont::*)(const std::string&)>(&cocos2d::MenuItemFont::setFontNameObj));
mt.set_function("getFontNameObj",static_cast<const std::string&(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontNameObj));
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItemFont*(*)(const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemFont::create),[](cocos2d::MenuItemFont* obj){return obj->create();},[](cocos2d::MenuItemFont* obj,const std::string& arg0){return obj->create(arg0);}));
mt.set_function("setFontSize",static_cast<void(*)(int)>(&cocos2d::MenuItemFont::setFontSize));
mt.set_function("getFontSize",static_cast<int(*)()>(&cocos2d::MenuItemFont::getFontSize));
mt.set_function("setFontName",static_cast<void(*)(const std::string&)>(&cocos2d::MenuItemFont::setFontName));
mt.set_function("getFontName",static_cast<const std::string&(*)()>(&cocos2d::MenuItemFont::getFontName));
}
void RegisterLuaCoreMenuItemSpriteAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemSprite");
mt.set_function("getNormalImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getNormalImage));
mt.set_function("setNormalImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setNormalImage));
mt.set_function("getSelectedImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getSelectedImage));
mt.set_function("setSelectedImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setSelectedImage));
mt.set_function("getDisabledImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getDisabledImage));
mt.set_function("setDisabledImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setDisabledImage));
mt.set_function("selected",static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::selected));
mt.set_function("unselected",static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::unselected));
mt.set_function("setEnabled",static_cast<void(cocos2d::MenuItemSprite::*)(bool)>(&cocos2d::MenuItemSprite::setEnabled));
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItemSprite*(*)(cocos2d::Node*,cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemSprite::create),[](cocos2d::MenuItemSprite* obj,cocos2d::Node* arg0,cocos2d::Node* arg1){return obj->create(arg0,arg1);},[](cocos2d::MenuItemSprite* obj,cocos2d::Node* arg0,cocos2d::Node* arg1,cocos2d::Node* arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::MenuItemSprite*(*)(cocos2d::Node*,cocos2d::Node*,cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemSprite::create)));
}
void RegisterLuaCoreMenuItemImageAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemImage,cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemImage");
mt.set_function("setNormalSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setNormalSpriteFrame));
mt.set_function("setSelectedSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setSelectedSpriteFrame));
mt.set_function("setDisabledSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setDisabledSpriteFrame));
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&)>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)()>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&,const std::string&)>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&,const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemImage::create)));
}
void RegisterLuaCoreMenuItemToggleAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemToggle,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemToggle");
mt.set_function("addSubItem",static_cast<void(cocos2d::MenuItemToggle::*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::addSubItem));
mt.set_function("getSelectedItem",static_cast<cocos2d::MenuItem*(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::getSelectedItem));
mt.set_function("getSelectedIndex",static_cast<unsigned int(cocos2d::MenuItemToggle::*)()const>(&cocos2d::MenuItemToggle::getSelectedIndex));
mt.set_function("setSelectedIndex",static_cast<void(cocos2d::MenuItemToggle::*)(unsigned int)>(&cocos2d::MenuItemToggle::setSelectedIndex));
mt.set_function("getSubItems",sol::overload(static_cast<cocos2d::Vector<cocos2d::MenuItem *>&(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::getSubItems),static_cast<const cocos2d::Vector<cocos2d::MenuItem *>&(cocos2d::MenuItemToggle::*)()const>(&cocos2d::MenuItemToggle::getSubItems)));
mt.set_function("setSubItems",static_cast<void(cocos2d::MenuItemToggle::*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::MenuItemToggle::setSubItems));
mt.set_function("activate",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::activate));
mt.set_function("selected",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::selected));
mt.set_function("unselected",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::unselected));
mt.set_function("setEnabled",static_cast<void(cocos2d::MenuItemToggle::*)(bool)>(&cocos2d::MenuItemToggle::setEnabled));
mt.set_function("cleanup",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::cleanup));
mt.set_function("createWithCallback",static_cast<cocos2d::MenuItemToggle*(*)(const std::function<void (cocos2d::MenuItem *)>&,const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::MenuItemToggle::createWithCallback));
mt.set_function("new",sol::overload(static_cast<cocos2d::MenuItemToggle*(*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::create),static_cast<cocos2d::MenuItemToggle*(*)()>(&cocos2d::MenuItemToggle::create)));
}
void RegisterLuaCoreMenuAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Menu,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Menu");
mt.set_function("alignItemsVertically",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsVertically));
mt.set_function("alignItemsVerticallyWithPadding",static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsVerticallyWithPadding));
mt.set_function("alignItemsHorizontally",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsHorizontally));
mt.set_function("alignItemsHorizontallyWithPadding",static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsHorizontallyWithPadding));
mt.set_function("alignItemsInColumns",static_cast<void(cocos2d::Menu::*)(int,va_list)>(&cocos2d::Menu::alignItemsInColumns));
mt.set_function("alignItemsInColumnsWithArray",static_cast<void(cocos2d::Menu::*)(const cocos2d::ValueVector&)>(&cocos2d::Menu::alignItemsInColumnsWithArray));
mt.set_function("alignItemsInRows",static_cast<void(cocos2d::Menu::*)(int,va_list)>(&cocos2d::Menu::alignItemsInRows));
mt.set_function("alignItemsInRowsWithArray",static_cast<void(cocos2d::Menu::*)(const cocos2d::ValueVector&)>(&cocos2d::Menu::alignItemsInRowsWithArray));
mt.set_function("isEnabled",static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isEnabled));
mt.set_function("setEnabled",static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setEnabled));
mt.set_function("onTouchBegan",static_cast<bool(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchBegan));
mt.set_function("onTouchEnded",static_cast<void(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchEnded));
mt.set_function("onTouchCancelled",static_cast<void(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchCancelled));
mt.set_function("onTouchMoved",static_cast<void(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchMoved));
mt.set_function("removeChild",static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,bool)>(&cocos2d::Menu::removeChild));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Menu::addChild)));
mt.set_function("onEnter",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::onExit));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isOpacityModifyRGB));
mt.set_function("getDescription",static_cast<std::string(cocos2d::Menu::*)()const>(&cocos2d::Menu::getDescription));
mt.set_function("new",static_cast<cocos2d::Menu*(*)()>(&cocos2d::Menu::create));
mt.set_function("createWithArray",static_cast<cocos2d::Menu*(*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::Menu::createWithArray));
mt.set_function("createWithItem",static_cast<cocos2d::Menu*(*)(cocos2d::MenuItem*)>(&cocos2d::Menu::createWithItem));
mt.set_function("createWithItems",static_cast<cocos2d::Menu*(*)(cocos2d::MenuItem*,va_list)>(&cocos2d::Menu::createWithItems));
}
