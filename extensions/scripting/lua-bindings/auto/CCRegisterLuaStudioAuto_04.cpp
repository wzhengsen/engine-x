#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioSkewFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("SkewFrame",false);
ns["SkewFrame"] = mt;
lua["SkewFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::SkewFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::SkewFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::SkewFrame::*)()>(&cocostudio::timeline::SkewFrame::clone));
mt.set_function("setSkewX",static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewX));
mt.set_function("getSkewX",static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewX));
mt.set_function("setSkewY",static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewY));
mt.set_function("getSkewY",static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewY));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::SkewFrame*(*)()>(&cocostudio::timeline::SkewFrame::create));
}
void RegisterLuaStudioRotationSkewFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::RotationSkewFrame,cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("RotationSkewFrame",false);
ns["RotationSkewFrame"] = mt;
lua["RotationSkewFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::RotationSkewFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::RotationSkewFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationSkewFrame::*)()>(&cocostudio::timeline::RotationSkewFrame::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::RotationSkewFrame*(*)()>(&cocostudio::timeline::RotationSkewFrame::create));
}
void RegisterLuaStudioPositionFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::PositionFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("PositionFrame",false);
ns["PositionFrame"] = mt;
lua["PositionFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::PositionFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::PositionFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PositionFrame::*)()>(&cocostudio::timeline::PositionFrame::clone));
mt.set_function("setPosition",static_cast<void(cocostudio::timeline::PositionFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::PositionFrame::setPosition));
mt.set_function("getPosition",static_cast<cocos2d::Point(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getPosition));
mt.set_function("setX",static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setX));
mt.set_function("setY",static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setY));
mt.set_function("getX",static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getX));
mt.set_function("getY",static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getY));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::PositionFrame*(*)()>(&cocostudio::timeline::PositionFrame::create));
}
void RegisterLuaStudioScaleFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::ScaleFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ScaleFrame",false);
ns["ScaleFrame"] = mt;
lua["ScaleFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::ScaleFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::ScaleFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ScaleFrame::*)()>(&cocostudio::timeline::ScaleFrame::clone));
mt.set_function("setScale",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScale));
mt.set_function("setScaleX",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleX));
mt.set_function("getScaleX",static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleX));
mt.set_function("setScaleY",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleY));
mt.set_function("getScaleY",static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleY));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ScaleFrame*(*)()>(&cocostudio::timeline::ScaleFrame::create));
}
void RegisterLuaStudioAnchorPointFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::AnchorPointFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("AnchorPointFrame",false);
ns["AnchorPointFrame"] = mt;
lua["AnchorPointFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::AnchorPointFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AnchorPointFrame::*)()>(&cocostudio::timeline::AnchorPointFrame::clone));
mt.set_function("setAnchorPoint",static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::AnchorPointFrame::setAnchorPoint));
mt.set_function("getAnchorPoint",static_cast<cocos2d::Point(cocostudio::timeline::AnchorPointFrame::*)()const>(&cocostudio::timeline::AnchorPointFrame::getAnchorPoint));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::AnchorPointFrame*(*)()>(&cocostudio::timeline::AnchorPointFrame::create));
}
void RegisterLuaStudioInnerActionFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::InnerActionFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("InnerActionFrame",false);
ns["InnerActionFrame"] = mt;
lua["InnerActionFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::InnerActionFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::InnerActionFrame::*)()>(&cocostudio::timeline::InnerActionFrame::clone));
mt.set_function("setInnerActionType",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::InnerActionType)>(&cocostudio::timeline::InnerActionFrame::setInnerActionType));
mt.set_function("getInnerActionType",static_cast<cocostudio::timeline::InnerActionType(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getInnerActionType));
mt.set_function("setEnterWithName",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(bool)>(&cocostudio::timeline::InnerActionFrame::setEnterWithName));
mt.set_function("setStartFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setStartFrameIndex));
mt.set_function("getStartFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getStartFrameIndex));
mt.set_function("setEndFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setEndFrameIndex));
mt.set_function("getEndFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getEndFrameIndex));
mt.set_function("setAnimationName",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(const std::string&)>(&cocostudio::timeline::InnerActionFrame::setAnimationName));
mt.set_function("setSingleFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setSingleFrameIndex));
mt.set_function("getSingleFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getSingleFrameIndex));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::InnerActionFrame*(*)()>(&cocostudio::timeline::InnerActionFrame::create));
}
void RegisterLuaStudioColorFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::ColorFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ColorFrame",false);
ns["ColorFrame"] = mt;
lua["ColorFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::ColorFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::ColorFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ColorFrame::*)()>(&cocostudio::timeline::ColorFrame::clone));
mt.set_function("setColor",static_cast<void(cocostudio::timeline::ColorFrame::*)(const cocos2d::Color3B&)>(&cocostudio::timeline::ColorFrame::setColor));
mt.set_function("getColor",static_cast<cocos2d::Color3B(cocostudio::timeline::ColorFrame::*)()const>(&cocostudio::timeline::ColorFrame::getColor));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ColorFrame*(*)()>(&cocostudio::timeline::ColorFrame::create));
}
void RegisterLuaStudioAlphaFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::AlphaFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("AlphaFrame",false);
ns["AlphaFrame"] = mt;
lua["AlphaFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::AlphaFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::AlphaFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AlphaFrame::*)()>(&cocostudio::timeline::AlphaFrame::clone));
mt.set_function("setAlpha",static_cast<void(cocostudio::timeline::AlphaFrame::*)(uint8_t)>(&cocostudio::timeline::AlphaFrame::setAlpha));
mt.set_function("getAlpha",static_cast<uint8_t(cocostudio::timeline::AlphaFrame::*)()const>(&cocostudio::timeline::AlphaFrame::getAlpha));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::AlphaFrame*(*)()>(&cocostudio::timeline::AlphaFrame::create));
}
void RegisterLuaStudioEventFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::EventFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("EventFrame",false);
ns["EventFrame"] = mt;
lua["EventFrame"] = sol::nil;
mt.set_function("init",static_cast<void(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::init));
mt.set_function("setNode",static_cast<void(cocostudio::timeline::EventFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::EventFrame::setNode));
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::EventFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::EventFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::clone));
mt.set_function("setEvent",static_cast<void(cocostudio::timeline::EventFrame::*)(std::string)>(&cocostudio::timeline::EventFrame::setEvent));
mt.set_function("getEvent",static_cast<std::string(cocostudio::timeline::EventFrame::*)()const>(&cocostudio::timeline::EventFrame::getEvent));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::EventFrame*(*)()>(&cocostudio::timeline::EventFrame::create));
}
void RegisterLuaStudioZOrderFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::ZOrderFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ZOrderFrame",false);
ns["ZOrderFrame"] = mt;
lua["ZOrderFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::ZOrderFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::ZOrderFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ZOrderFrame::*)()>(&cocostudio::timeline::ZOrderFrame::clone));
mt.set_function("setZOrder",static_cast<void(cocostudio::timeline::ZOrderFrame::*)(int)>(&cocostudio::timeline::ZOrderFrame::setZOrder));
mt.set_function("getZOrder",static_cast<int(cocostudio::timeline::ZOrderFrame::*)()const>(&cocostudio::timeline::ZOrderFrame::getZOrder));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ZOrderFrame*(*)()>(&cocostudio::timeline::ZOrderFrame::create));
}
