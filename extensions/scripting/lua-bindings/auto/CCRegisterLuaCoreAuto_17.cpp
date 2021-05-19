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
void RegisterLuaCoreLayerMultiplexAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LayerMultiplex>("cc","LayerMultiplex",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::LayerMultiplex*(*)()>(&cocos2d::LayerMultiplex::create));
mt.set_function("CreateWithArray",static_cast<cocos2d::LayerMultiplex*(*)(const cocos2d::Vector<cocos2d::Layer *>&)>(&cocos2d::LayerMultiplex::createWithArray));
mt.set_function("CreateWithLayer",static_cast<cocos2d::LayerMultiplex*(*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::createWithLayer));
mt.set_function("AddLayer",static_cast<void(cocos2d::LayerMultiplex::*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::addLayer));
mt.set_function("SwitchTo",sol::overload(static_cast<void(cocos2d::LayerMultiplex::*)(int,bool)>(&cocos2d::LayerMultiplex::switchTo),static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchTo)));
mt.set_function("SwitchToAndReleaseMe",static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchToAndReleaseMe));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::LayerMultiplex::*)()const>(&cocos2d::LayerMultiplex::getDescription));
}
void RegisterLuaCoreMenuItemAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItem>("cc","MenuItem",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItem*(*)(const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItem::create),static_cast<cocos2d::MenuItem*(*)()>(&cocos2d::MenuItem::create)));
mt.set_function("Rect",static_cast<cocos2d::Rect(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::rect));
mt.set_function("Activate",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::activate));
mt.set_function("Selected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::selected));
mt.set_function("Unselected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::unselected));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isEnabled));
mt.set_function("SetEnabled",static_cast<void(cocos2d::MenuItem::*)(bool)>(&cocos2d::MenuItem::setEnabled));
mt.set_function("IsSelected",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isSelected));
mt.set_function("SetHandler",static_cast<void(cocos2d::MenuItem::*)(const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItem::SetHandler));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::getDescription));
}
void RegisterLuaCoreMenuItemLabelAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemLabel>("cc","MenuItemLabel",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::create),static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemLabel::create)));
mt.set_function("SetString",static_cast<void(cocos2d::MenuItemLabel::*)(const std::string&)>(&cocos2d::MenuItemLabel::setString));
mt.set_function("GetString",static_cast<std::string(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getString));
mt.set_function("GetDisabledColor",static_cast<const cocos2d::Color3B&(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getDisabledColor));
mt.set_function("SetDisabledColor",static_cast<void(cocos2d::MenuItemLabel::*)(const cocos2d::Color3B&)>(&cocos2d::MenuItemLabel::setDisabledColor));
mt.set_function("GetLabel",static_cast<cocos2d::Node*(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getLabel));
mt.set_function("SetLabel",static_cast<void(cocos2d::MenuItemLabel::*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::setLabel));
mt.set_function("Activate",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::activate));
mt.set_function("Selected",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::selected));
mt.set_function("Unselected",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::unselected));
mt.set_function("SetEnabled",static_cast<void(cocos2d::MenuItemLabel::*)(bool)>(&cocos2d::MenuItemLabel::setEnabled));
}
void RegisterLuaCoreMenuItemAtlasFontAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemAtlasFont>("cc","MenuItemAtlasFont",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemAtlasFont::create),static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char)>(&cocos2d::MenuItemAtlasFont::create)));
}
void RegisterLuaCoreMenuItemFontAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemFont>("cc","MenuItemFont",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemFont*(*)(const std::string&,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemFont::create),[](cocos2d::MenuItemFont* obj){return obj->create();},[](cocos2d::MenuItemFont* obj,const std::string& arg0){return obj->create(arg0);}));
mt.set_function("SetFontSize",static_cast<void(*)(int)>(&cocos2d::MenuItemFont::setFontSize));
mt.set_function("GetFontSize",static_cast<int(*)()>(&cocos2d::MenuItemFont::getFontSize));
mt.set_function("SetFontName",static_cast<void(*)(const std::string&)>(&cocos2d::MenuItemFont::setFontName));
mt.set_function("GetFontName",static_cast<const std::string&(*)()>(&cocos2d::MenuItemFont::getFontName));
mt.set_function("SetFontSizeObj",static_cast<void(cocos2d::MenuItemFont::*)(int)>(&cocos2d::MenuItemFont::setFontSizeObj));
mt.set_function("GetFontSizeObj",static_cast<int(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontSizeObj));
mt.set_function("SetFontNameObj",static_cast<void(cocos2d::MenuItemFont::*)(const std::string&)>(&cocos2d::MenuItemFont::setFontNameObj));
mt.set_function("GetFontNameObj",static_cast<const std::string&(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontNameObj));
}
void RegisterLuaCoreMenuItemSpriteAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemSprite>("cc","MenuItemSprite",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemSprite*(*)(cocos2d::Node*,cocos2d::Node*,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemSprite::create),[](cocos2d::MenuItemSprite* obj,cocos2d::Node* arg0,cocos2d::Node* arg1){return obj->create(arg0,arg1);},[](cocos2d::MenuItemSprite* obj,cocos2d::Node* arg0,cocos2d::Node* arg1,cocos2d::Node* arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::MenuItemSprite*(*)(cocos2d::Node*,cocos2d::Node*,cocos2d::Node*,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemSprite::create)));
mt.set_function("GetNormalImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getNormalImage));
mt.set_function("SetNormalImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setNormalImage));
mt.set_function("GetSelectedImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getSelectedImage));
mt.set_function("SetSelectedImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setSelectedImage));
mt.set_function("GetDisabledImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getDisabledImage));
mt.set_function("SetDisabledImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setDisabledImage));
mt.set_function("Selected",static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::selected));
mt.set_function("Unselected",static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::unselected));
mt.set_function("SetEnabled",static_cast<void(cocos2d::MenuItemSprite::*)(bool)>(&cocos2d::MenuItemSprite::setEnabled));
}
void RegisterLuaCoreMenuItemImageAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemImage>("cc","MenuItemImage",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&)>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)()>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&,const std::string&)>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemImage::create),static_cast<cocos2d::MenuItemImage*(*)(const std::string&,const std::string&,const std::string&,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemImage::create)));
mt.set_function("SetNormalSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setNormalSpriteFrame));
mt.set_function("SetSelectedSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setSelectedSpriteFrame));
mt.set_function("SetDisabledSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setDisabledSpriteFrame));
}
