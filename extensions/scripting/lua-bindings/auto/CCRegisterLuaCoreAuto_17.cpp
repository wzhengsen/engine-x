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
namespace cocos2d{
void RegisterLuaCoreLabelAtlasAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LabelAtlas).name()] = sol::usertype_traits<cocos2d::LabelAtlas*>::metatable();
auto dep=lua.new_usertype<cocos2d::LabelAtlas>("deprecated.cocos2d::LabelAtlas");
dep[sol::base_classes]=sol::bases<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::LabelProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LabelAtlas*>::metatable(),sol::usertype_traits<cocos2d::AtlasNode*>::metatable(),sol::usertype_traits<cocos2d::LabelProtocol*>::metatable());
lua["cc"]["LabelAtlas"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::LabelAtlas*(*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::create));
mt["InitWithString"]=sol::overload(static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::initWithString));
}
void RegisterLuaCoreTouchDispatchModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["ALL_AT_ONCE"]=cocos2d::Touch::DispatchMode::ALL_AT_ONCE;
enumTable["ONE_BY_ONE"]=cocos2d::Touch::DispatchMode::ONE_BY_ONE;
lua["cc"]["Touch"]["static"]["DispatchMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreTouchAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Touch).name()] = sol::usertype_traits<cocos2d::Touch*>::metatable();
auto dep=lua.new_usertype<cocos2d::Touch>("deprecated.cocos2d::Touch");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Touch*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Touch"]=mt;
mt["__new__"]=[](){return new cocos2d::Touch();};
mt["GetLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocation);
mt["get"]["Location"]=mt["GetLocation"];
mt["GetPreviousLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocation);
mt["get"]["PreviousLocation"]=mt["GetPreviousLocation"];
mt["GetStartLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocation);
mt["get"]["StartLocation"]=mt["GetStartLocation"];
mt["GetDelta"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getDelta);
mt["get"]["Delta"]=mt["GetDelta"];
mt["GetLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocationInView);
mt["get"]["LocationInView"]=mt["GetLocationInView"];
mt["GetPreviousLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocationInView);
mt["get"]["PreviousLocationInView"]=mt["GetPreviousLocationInView"];
mt["GetStartLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocationInView);
mt["get"]["StartLocationInView"]=mt["GetStartLocationInView"];
mt["SetTouchInfo"]=sol::overload(static_cast<void(cocos2d::Touch::*)(int,float,float,float,float)>(&cocos2d::Touch::setTouchInfo),static_cast<void(cocos2d::Touch::*)(int,float,float)>(&cocos2d::Touch::setTouchInfo));
mt["GetId"]=static_cast<int(cocos2d::Touch::*)()const>(&cocos2d::Touch::getID);
mt["get"]["ID"]=mt["GetId"];
mt["GetCurrentForce"]=static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getCurrentForce);
mt["get"]["CurrentForce"]=mt["GetCurrentForce"];
mt["GetMaxForce"]=static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getMaxForce);
mt["get"]["MaxForce"]=mt["GetMaxForce"];
RegisterLuaCoreTouchDispatchModeAuto(lua);
}
void RegisterLuaCoreLayerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Layer).name()] = sol::usertype_traits<cocos2d::Layer*>::metatable();
auto dep=lua.new_usertype<cocos2d::Layer>("deprecated.cocos2d::Layer");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Layer*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["Layer"]=mt;
mt["__new__"]=static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create);
mt["OnTouchBegan"]=static_cast<bool(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchBegan);
mt["OnTouchMoved"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchMoved);
mt["OnTouchEnded"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchEnded);
mt["OnTouchCancelled"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchCancelled);
mt["OnTouchesBegan"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesBegan);
mt["OnTouchesMoved"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesMoved);
mt["OnTouchesEnded"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesEnded);
mt["OnTouchesCancelled"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesCancelled);
mt["OnAcceleration"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Acceleration*,cocos2d::Event*)>(&cocos2d::Layer::onAcceleration);
mt["OnKeyPressed"]=static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyPressed);
mt["OnKeyReleased"]=static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyReleased);
}
void RegisterLuaCoreLayerColorAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LayerColor).name()] = sol::usertype_traits<cocos2d::LayerColor*>::metatable();
auto dep=lua.new_usertype<cocos2d::LayerColor>("deprecated.cocos2d::LayerColor");
dep[sol::base_classes]=sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LayerColor*>::metatable(),sol::usertype_traits<cocos2d::Layer*>::metatable(),sol::usertype_traits<cocos2d::BlendProtocol*>::metatable());
lua["cc"]["LayerColor"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)()>(&cocos2d::LayerColor::create));
mt["ChangeWidth"]=static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeWidth);
mt["ChangeHeight"]=static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeHeight);
mt["ChangeWidthAndHeight"]=static_cast<void(cocos2d::LayerColor::*)(float,float)>(&cocos2d::LayerColor::changeWidthAndHeight);
}
void RegisterLuaCoreLayerGradientAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LayerGradient).name()] = sol::usertype_traits<cocos2d::LayerGradient*>::metatable();
auto dep=lua.new_usertype<cocos2d::LayerGradient>("deprecated.cocos2d::LayerGradient");
dep[sol::base_classes]=sol::bases<cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LayerGradient*>::metatable(),sol::usertype_traits<cocos2d::LayerColor*>::metatable());
lua["cc"]["LayerGradient"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)()>(&cocos2d::LayerGradient::create));
mt["SetCompressedInterpolation"]=static_cast<void(cocos2d::LayerGradient::*)(bool)>(&cocos2d::LayerGradient::setCompressedInterpolation);
mt["set"]["CompressedInterpolation"]=mt["SetCompressedInterpolation"];
mt["IsCompressedInterpolation"]=static_cast<bool(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::isCompressedInterpolation);
mt["get"]["CompressedInterpolation"]=mt["IsCompressedInterpolation"];
mt["SetStartColor"]=static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setStartColor);
mt["set"]["StartColor"]=mt["SetStartColor"];
mt["GetStartColor"]=static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartColor);
mt["get"]["StartColor"]=mt["GetStartColor"];
mt["SetEndColor"]=static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setEndColor);
mt["set"]["EndColor"]=mt["SetEndColor"];
mt["GetEndColor"]=static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndColor);
mt["get"]["EndColor"]=mt["GetEndColor"];
mt["SetStartOpacity"]=static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setStartOpacity);
mt["set"]["StartOpacity"]=mt["SetStartOpacity"];
mt["GetStartOpacity"]=static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartOpacity);
mt["get"]["StartOpacity"]=mt["GetStartOpacity"];
mt["SetEndOpacity"]=static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setEndOpacity);
mt["set"]["EndOpacity"]=mt["SetEndOpacity"];
mt["GetEndOpacity"]=static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndOpacity);
mt["get"]["EndOpacity"]=mt["GetEndOpacity"];
mt["SetVector"]=static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerGradient::setVector);
mt["set"]["Vector"]=mt["SetVector"];
mt["GetVector"]=static_cast<const cocos2d::Vec2&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getVector);
mt["get"]["Vector"]=mt["GetVector"];
}
void RegisterLuaCoreLayerRadialGradientAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LayerRadialGradient).name()] = sol::usertype_traits<cocos2d::LayerRadialGradient*>::metatable();
auto dep=lua.new_usertype<cocos2d::LayerRadialGradient>("deprecated.cocos2d::LayerRadialGradient");
dep[sol::base_classes]=sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LayerRadialGradient*>::metatable(),sol::usertype_traits<cocos2d::Layer*>::metatable());
lua["cc"]["LayerRadialGradient"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create));
mt["SetStartOpacity"]=static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setStartOpacity);
mt["set"]["StartOpacity"]=mt["SetStartOpacity"];
mt["GetStartOpacity"]=static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartOpacity);
mt["get"]["StartOpacity"]=mt["GetStartOpacity"];
mt["SetEndOpacity"]=static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setEndOpacity);
mt["set"]["EndOpacity"]=mt["SetEndOpacity"];
mt["GetEndOpacity"]=static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndOpacity);
mt["get"]["EndOpacity"]=mt["GetEndOpacity"];
mt["SetRadius"]=static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setRadius);
mt["set"]["Radius"]=mt["SetRadius"];
mt["GetRadius"]=static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getRadius);
mt["get"]["Radius"]=mt["GetRadius"];
mt["SetCenter"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerRadialGradient::setCenter);
mt["set"]["Center"]=mt["SetCenter"];
mt["GetCenter"]=static_cast<cocos2d::Vec2(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getCenter);
mt["get"]["Center"]=mt["GetCenter"];
mt["SetExpand"]=static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setExpand);
mt["set"]["Expand"]=mt["SetExpand"];
mt["GetExpand"]=static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getExpand);
mt["get"]["Expand"]=mt["GetExpand"];
mt["SetStartColor"]=sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setStartColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setStartColor));
mt["set"]["StartColor"]=mt["SetStartColor"];
mt["GetStartColor"]=static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor);
mt["get"]["StartColor"]=mt["GetStartColor"];
mt["GetStartColor3B"]=static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor3B);
mt["get"]["StartColor3B"]=mt["GetStartColor3B"];
mt["SetEndColor"]=sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setEndColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setEndColor));
mt["set"]["EndColor"]=mt["SetEndColor"];
mt["GetEndColor"]=static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor);
mt["get"]["EndColor"]=mt["GetEndColor"];
mt["GetEndColor3B"]=static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor3B);
mt["get"]["EndColor3B"]=mt["GetEndColor3B"];
mt["SetBlendFunc"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerRadialGradient::setBlendFunc);
mt["set"]["BlendFunc"]=mt["SetBlendFunc"];
mt["GetBlendFunc"]=static_cast<cocos2d::BlendFunc(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getBlendFunc);
mt["get"]["BlendFunc"]=mt["GetBlendFunc"];
}
void RegisterLuaCoreLayerMultiplexAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LayerMultiplex).name()] = sol::usertype_traits<cocos2d::LayerMultiplex*>::metatable();
auto dep=lua.new_usertype<cocos2d::LayerMultiplex>("deprecated.cocos2d::LayerMultiplex");
dep[sol::base_classes]=sol::bases<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LayerMultiplex*>::metatable(),sol::usertype_traits<cocos2d::Layer*>::metatable());
lua["cc"]["LayerMultiplex"]=mt;
mt["__new__"]=static_cast<cocos2d::LayerMultiplex*(*)()>(&cocos2d::LayerMultiplex::create);
mt["static"]["CreateWithArray"]=static_cast<cocos2d::LayerMultiplex*(*)(const cocos2d::Vector<cocos2d::Layer *>&)>(&cocos2d::LayerMultiplex::createWithArray);
mt["static"]["CreateWithLayer"]=static_cast<cocos2d::LayerMultiplex*(*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::createWithLayer);
mt["AddLayer"]=static_cast<void(cocos2d::LayerMultiplex::*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::addLayer);
mt["SwitchTo"]=sol::overload(static_cast<void(cocos2d::LayerMultiplex::*)(int,bool)>(&cocos2d::LayerMultiplex::switchTo),static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchTo));
mt["SwitchToAndReleaseMe"]=static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchToAndReleaseMe);
}
void RegisterLuaCoreMenuItemAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::MenuItem).name()] = sol::usertype_traits<cocos2d::MenuItem*>::metatable();
auto dep=lua.new_usertype<cocos2d::MenuItem>("deprecated.cocos2d::MenuItem");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::MenuItem*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["MenuItem"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::MenuItem*(*)(const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItem::create),static_cast<cocos2d::MenuItem*(*)()>(&cocos2d::MenuItem::create));
mt["Rect"]=static_cast<cocos2d::Rect(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::rect);
mt["Activate"]=static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::activate);
mt["Selected"]=static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::selected);
mt["Unselected"]=static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::unselected);
mt["IsEnabled"]=static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isEnabled);
mt["get"]["Enabled"]=mt["IsEnabled"];
mt["SetEnabled"]=static_cast<void(cocos2d::MenuItem::*)(bool)>(&cocos2d::MenuItem::setEnabled);
mt["set"]["Enabled"]=mt["SetEnabled"];
mt["IsSelected"]=static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isSelected);
mt["get"]["Selected"]=mt["IsSelected"];
mt["SetItemHandler"]=static_cast<void(cocos2d::MenuItem::*)(const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItem::SetItemHandler);
mt["set"]["ItemHandler"]=mt["SetItemHandler"];
}
void RegisterLuaCoreMenuItemLabelAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::MenuItemLabel).name()] = sol::usertype_traits<cocos2d::MenuItemLabel*>::metatable();
auto dep=lua.new_usertype<cocos2d::MenuItemLabel>("deprecated.cocos2d::MenuItemLabel");
dep[sol::base_classes]=sol::bases<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::MenuItemLabel*>::metatable(),sol::usertype_traits<cocos2d::MenuItem*>::metatable());
lua["cc"]["MenuItemLabel"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemLabel::create),static_cast<cocos2d::MenuItemLabel*(*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::create));
mt["SetString"]=static_cast<void(cocos2d::MenuItemLabel::*)(const std::string&)>(&cocos2d::MenuItemLabel::setString);
mt["set"]["String"]=mt["SetString"];
mt["GetString"]=static_cast<std::string(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getString);
mt["get"]["String"]=mt["GetString"];
mt["GetDisabledColor"]=static_cast<const cocos2d::Color3B&(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getDisabledColor);
mt["get"]["DisabledColor"]=mt["GetDisabledColor"];
mt["SetDisabledColor"]=static_cast<void(cocos2d::MenuItemLabel::*)(const cocos2d::Color3B&)>(&cocos2d::MenuItemLabel::setDisabledColor);
mt["set"]["DisabledColor"]=mt["SetDisabledColor"];
mt["GetLabel"]=static_cast<cocos2d::Node*(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getLabel);
mt["get"]["Label"]=mt["GetLabel"];
mt["SetLabel"]=static_cast<void(cocos2d::MenuItemLabel::*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::setLabel);
mt["set"]["Label"]=mt["SetLabel"];
}
void RegisterLuaCoreMenuItemAtlasFontAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::MenuItemAtlasFont).name()] = sol::usertype_traits<cocos2d::MenuItemAtlasFont*>::metatable();
auto dep=lua.new_usertype<cocos2d::MenuItemAtlasFont>("deprecated.cocos2d::MenuItemAtlasFont");
dep[sol::base_classes]=sol::bases<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::MenuItemAtlasFont*>::metatable(),sol::usertype_traits<cocos2d::MenuItemLabel*>::metatable());
lua["cc"]["MenuItemAtlasFont"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char,const cocos2d::MenuItem::MenuItemHandlerType&)>(&cocos2d::MenuItemAtlasFont::create),static_cast<cocos2d::MenuItemAtlasFont*(*)(const std::string&,const std::string&,int,int,char)>(&cocos2d::MenuItemAtlasFont::create));
}
}
