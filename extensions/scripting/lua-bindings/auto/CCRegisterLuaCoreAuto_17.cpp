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
void RegisterLuaCoreMenuItemToggleAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MenuItemToggle>("cc","MenuItemToggle",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateWithCallback",static_cast<cocos2d::MenuItemToggle*(*)(const cocos2d::MenuItem::MenuItemHandlerType&,const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::MenuItemToggle::createWithCallback));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MenuItemToggle*(*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::create),static_cast<cocos2d::MenuItemToggle*(*)()>(&cocos2d::MenuItemToggle::create)));
mt.set_function("AddSubItem",static_cast<void(cocos2d::MenuItemToggle::*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::addSubItem));
mt.set_function("GetSelectedItem",static_cast<cocos2d::MenuItem*(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::getSelectedItem));
mt.set_function("GetSelectedIndex",static_cast<unsigned int(cocos2d::MenuItemToggle::*)()const>(&cocos2d::MenuItemToggle::getSelectedIndex));
mt.set_function("SetSelectedIndex",static_cast<void(cocos2d::MenuItemToggle::*)(unsigned int)>(&cocos2d::MenuItemToggle::setSelectedIndex));
mt.set_function("GetSubItems",sol::overload(static_cast<cocos2d::Vector<cocos2d::MenuItem *>&(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::getSubItems),static_cast<const cocos2d::Vector<cocos2d::MenuItem *>&(cocos2d::MenuItemToggle::*)()const>(&cocos2d::MenuItemToggle::getSubItems)));
mt.set_function("SetSubItems",static_cast<void(cocos2d::MenuItemToggle::*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::MenuItemToggle::setSubItems));
mt.set_function("Activate",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::activate));
mt.set_function("Selected",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::selected));
mt.set_function("Unselected",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::unselected));
mt.set_function("SetEnabled",static_cast<void(cocos2d::MenuItemToggle::*)(bool)>(&cocos2d::MenuItemToggle::setEnabled));
mt.set_function("Cleanup",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::cleanup));
}
void RegisterLuaCoreMenuStateAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Menu"];
pTable.new_enum<cocos2d::Menu::State>("State",{
{"WAITING",cocos2d::Menu::State::WAITING}
,{"TRACKING_TOUCH",cocos2d::Menu::State::TRACKING_TOUCH}
});}
void RegisterLuaCoreMenuAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Menu>("cc","Menu",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Menu*(*)()>(&cocos2d::Menu::create));
mt.set_function("CreateWithArray",static_cast<cocos2d::Menu*(*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::Menu::createWithArray));
mt.set_function("CreateWithItem",static_cast<cocos2d::Menu*(*)(cocos2d::MenuItem*)>(&cocos2d::Menu::createWithItem));
mt.set_function("CreateWithItems",static_cast<cocos2d::Menu*(*)(cocos2d::MenuItem*,va_list)>(&cocos2d::Menu::createWithItems));
mt.set_function("AlignItemsVertically",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsVertically));
mt.set_function("AlignItemsVerticallyWithPadding",static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsVerticallyWithPadding));
mt.set_function("AlignItemsHorizontally",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsHorizontally));
mt.set_function("AlignItemsHorizontallyWithPadding",static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsHorizontallyWithPadding));
mt.set_function("AlignItemsInColumns",static_cast<void(cocos2d::Menu::*)(int,va_list)>(&cocos2d::Menu::alignItemsInColumns));
mt.set_function("AlignItemsInColumnsWithArray",static_cast<void(cocos2d::Menu::*)(const cocos2d::ValueVector&)>(&cocos2d::Menu::alignItemsInColumnsWithArray));
mt.set_function("AlignItemsInRows",static_cast<void(cocos2d::Menu::*)(int,va_list)>(&cocos2d::Menu::alignItemsInRows));
mt.set_function("AlignItemsInRowsWithArray",static_cast<void(cocos2d::Menu::*)(const cocos2d::ValueVector&)>(&cocos2d::Menu::alignItemsInRowsWithArray));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isEnabled));
mt.set_function("SetEnabled",static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setEnabled));
mt.set_function("OnTouchBegan",static_cast<bool(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchBegan));
mt.set_function("OnTouchEnded",static_cast<void(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchEnded));
mt.set_function("OnTouchCancelled",static_cast<void(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchCancelled));
mt.set_function("OnTouchMoved",static_cast<void(cocos2d::Menu::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Menu::onTouchMoved));
mt.set_function("RemoveChild",static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,bool)>(&cocos2d::Menu::removeChild));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Menu::addChild)));
mt.set_function("OnEnter",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::onExit));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setOpacityModifyRGB));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isOpacityModifyRGB));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::Menu::*)()const>(&cocos2d::Menu::getDescription));
RegisterLuaCoreMenuStateAuto(lua);
}
void RegisterLuaCoreMotionStreakAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MotionStreak>("cc","MotionStreak",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak::create),static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak::create)));
mt.set_function("SetPosition",sol::overload(static_cast<void(cocos2d::MotionStreak::*)(float,float)>(&cocos2d::MotionStreak::setPosition),static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak::setPosition)));
mt.set_function("GetPosition",sol::overload(static_cast<void(cocos2d::MotionStreak::*)(float*,float*)const>(&cocos2d::MotionStreak::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition)));
mt.set_function("SetPositionX",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionX));
mt.set_function("SetPositionY",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionY));
mt.set_function("GetPositionX",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionX));
mt.set_function("GetPositionY",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionY));
mt.set_function("GetPosition3D",static_cast<cocos2d::Vec3(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition3D));
mt.set_function("Draw",static_cast<void(cocos2d::MotionStreak::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::MotionStreak::draw));
mt.set_function("Update",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::update));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getTexture));
mt.set_function("SetTexture",static_cast<void(cocos2d::MotionStreak::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak::setTexture));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getBlendFunc));
mt.set_function("GetOpacity",static_cast<uint8_t(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getOpacity));
mt.set_function("SetOpacity",static_cast<void(cocos2d::MotionStreak::*)(uint8_t)>(&cocos2d::MotionStreak::setOpacity));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setOpacityModifyRGB));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isOpacityModifyRGB));
mt.set_function("TintWithColor",static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak::tintWithColor));
mt.set_function("Reset",static_cast<void(cocos2d::MotionStreak::*)()>(&cocos2d::MotionStreak::reset));
mt.set_function("IsFastMode",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isFastMode));
mt.set_function("SetFastMode",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setFastMode));
mt.set_function("GetStroke",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getStroke));
mt.set_function("SetStroke",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setStroke));
mt.set_function("IsStartingPositionInitialized",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isStartingPositionInitialized));
mt.set_function("SetStartingPositionInitialized",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setStartingPositionInitialized));
mt.set_function("SetProgramState",static_cast<bool(cocos2d::MotionStreak::*)(cocos2d::backend::ProgramState*,bool)>(&cocos2d::MotionStreak::setProgramState));
}
