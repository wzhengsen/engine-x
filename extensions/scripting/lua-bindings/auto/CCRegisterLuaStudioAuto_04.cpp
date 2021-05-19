#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioRotationFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::RotationFrame>("ccs","RotationFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::RotationFrame*(*)()>(&cocostudio::timeline::RotationFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::RotationFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::RotationFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationFrame::*)()>(&cocostudio::timeline::RotationFrame::clone));
mt.set_function("SetRotation",static_cast<void(cocostudio::timeline::RotationFrame::*)(float)>(&cocostudio::timeline::RotationFrame::setRotation));
mt.set_function("GetRotation",static_cast<float(cocostudio::timeline::RotationFrame::*)()const>(&cocostudio::timeline::RotationFrame::getRotation));
}
void RegisterLuaStudioSkewFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::SkewFrame>("ccs","SkewFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::SkewFrame*(*)()>(&cocostudio::timeline::SkewFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::SkewFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::SkewFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::SkewFrame::*)()>(&cocostudio::timeline::SkewFrame::clone));
mt.set_function("SetSkewX",static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewX));
mt.set_function("GetSkewX",static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewX));
mt.set_function("SetSkewY",static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewY));
mt.set_function("GetSkewY",static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewY));
}
void RegisterLuaStudioRotationSkewFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::RotationSkewFrame>("ccs","RotationSkewFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::RotationSkewFrame*(*)()>(&cocostudio::timeline::RotationSkewFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::RotationSkewFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::RotationSkewFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationSkewFrame::*)()>(&cocostudio::timeline::RotationSkewFrame::clone));
}
void RegisterLuaStudioPositionFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::PositionFrame>("ccs","PositionFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::PositionFrame*(*)()>(&cocostudio::timeline::PositionFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::PositionFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::PositionFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PositionFrame::*)()>(&cocostudio::timeline::PositionFrame::clone));
mt.set_function("SetPosition",static_cast<void(cocostudio::timeline::PositionFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::PositionFrame::setPosition));
mt.set_function("GetPosition",static_cast<cocos2d::Point(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getPosition));
mt.set_function("SetX",static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setX));
mt.set_function("SetY",static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setY));
mt.set_function("GetX",static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getX));
mt.set_function("GetY",static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getY));
}
void RegisterLuaStudioScaleFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ScaleFrame>("ccs","ScaleFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ScaleFrame*(*)()>(&cocostudio::timeline::ScaleFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::ScaleFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::ScaleFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ScaleFrame::*)()>(&cocostudio::timeline::ScaleFrame::clone));
mt.set_function("SetScale",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScale));
mt.set_function("SetScaleX",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleX));
mt.set_function("GetScaleX",static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleX));
mt.set_function("SetScaleY",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleY));
mt.set_function("GetScaleY",static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleY));
}
void RegisterLuaStudioAnchorPointFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::AnchorPointFrame>("ccs","AnchorPointFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::AnchorPointFrame*(*)()>(&cocostudio::timeline::AnchorPointFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::AnchorPointFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AnchorPointFrame::*)()>(&cocostudio::timeline::AnchorPointFrame::clone));
mt.set_function("SetAnchorPoint",static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::AnchorPointFrame::setAnchorPoint));
mt.set_function("GetAnchorPoint",static_cast<cocos2d::Point(cocostudio::timeline::AnchorPointFrame::*)()const>(&cocostudio::timeline::AnchorPointFrame::getAnchorPoint));
}
void RegisterLuaStudioInnerActionTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccs"];
pTable.new_enum<cocostudio::timeline::InnerActionType>("InnerActionType",{
{"LoopAction",cocostudio::timeline::InnerActionType::LoopAction}
,{"NoLoopAction",cocostudio::timeline::InnerActionType::NoLoopAction}
,{"SingleFrame",cocostudio::timeline::InnerActionType::SingleFrame}
});}
void RegisterLuaStudioInnerActionFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::InnerActionFrame>("ccs","InnerActionFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::InnerActionFrame*(*)()>(&cocostudio::timeline::InnerActionFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::InnerActionFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::InnerActionFrame::*)()>(&cocostudio::timeline::InnerActionFrame::clone));
mt.set_function("SetInnerActionType",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::InnerActionType)>(&cocostudio::timeline::InnerActionFrame::setInnerActionType));
mt.set_function("GetInnerActionType",static_cast<cocostudio::timeline::InnerActionType(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getInnerActionType));
mt.set_function("SetEnterWithName",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(bool)>(&cocostudio::timeline::InnerActionFrame::setEnterWithName));
mt.set_function("SetStartFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setStartFrameIndex));
mt.set_function("GetStartFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getStartFrameIndex));
mt.set_function("SetEndFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setEndFrameIndex));
mt.set_function("GetEndFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getEndFrameIndex));
mt.set_function("SetAnimationName",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(const std::string&)>(&cocostudio::timeline::InnerActionFrame::setAnimationName));
mt.set_function("SetSingleFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setSingleFrameIndex));
mt.set_function("GetSingleFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getSingleFrameIndex));
mt["AnimationAllName"]=sol::var(std::ref(cocostudio::timeline::InnerActionFrame::AnimationAllName));
}
void RegisterLuaStudioColorFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ColorFrame>("ccs","ColorFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ColorFrame*(*)()>(&cocostudio::timeline::ColorFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::ColorFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::ColorFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ColorFrame::*)()>(&cocostudio::timeline::ColorFrame::clone));
mt.set_function("SetColor",static_cast<void(cocostudio::timeline::ColorFrame::*)(const cocos2d::Color3B&)>(&cocostudio::timeline::ColorFrame::setColor));
mt.set_function("GetColor",static_cast<cocos2d::Color3B(cocostudio::timeline::ColorFrame::*)()const>(&cocostudio::timeline::ColorFrame::getColor));
}
void RegisterLuaStudioAlphaFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::AlphaFrame>("ccs","AlphaFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::AlphaFrame*(*)()>(&cocostudio::timeline::AlphaFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::AlphaFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::AlphaFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AlphaFrame::*)()>(&cocostudio::timeline::AlphaFrame::clone));
mt.set_function("SetAlpha",static_cast<void(cocostudio::timeline::AlphaFrame::*)(uint8_t)>(&cocostudio::timeline::AlphaFrame::setAlpha));
mt.set_function("GetAlpha",static_cast<uint8_t(cocostudio::timeline::AlphaFrame::*)()const>(&cocostudio::timeline::AlphaFrame::getAlpha));
}
