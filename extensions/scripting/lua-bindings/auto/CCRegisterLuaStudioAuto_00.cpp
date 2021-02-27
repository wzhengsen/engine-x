#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioActionFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ActionFrame",true);
ns["ActionFrame"] = mt;
lua["ActionFrame"] = sol::nil;
mt.set_function("setFrameIndex",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameIndex));
mt.set_function("getFrameIndex",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameIndex));
mt.set_function("setFrameTime",static_cast<void(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::setFrameTime));
mt.set_function("getFrameTime",static_cast<float(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameTime));
mt.set_function("setFrameType",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameType));
mt.set_function("getFrameType",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameType));
mt.set_function("setEasingType",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setEasingType));
mt.set_function("getEasingType",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getEasingType));
mt.set_function("getAction",sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::getAction)));
mt.set_function("setEasingParameter",static_cast<void(cocostudio::ActionFrame::*)(std::vector<float>&)>(&cocostudio::ActionFrame::setEasingParameter));
}
void RegisterLuaStudioActionMoveFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionMoveFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ActionMoveFrame",true);
ns["ActionMoveFrame"] = mt;
lua["ActionMoveFrame"] = sol::nil;
mt.set_function("setPosition",static_cast<void(cocostudio::ActionMoveFrame::*)(cocos2d::Vec2)>(&cocostudio::ActionMoveFrame::setPosition));
mt.set_function("getPosition",static_cast<cocos2d::Vec2(cocostudio::ActionMoveFrame::*)()>(&cocostudio::ActionMoveFrame::getPosition));
mt.set_function("getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionMoveFrame::*)(float)>(&cocostudio::ActionMoveFrame::getAction));
}
void RegisterLuaStudioActionScaleFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionScaleFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ActionScaleFrame",true);
ns["ActionScaleFrame"] = mt;
lua["ActionScaleFrame"] = sol::nil;
mt.set_function("setScaleX",static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleX));
mt.set_function("getScaleX",static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleX));
mt.set_function("setScaleY",static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleY));
mt.set_function("getScaleY",static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleY));
mt.set_function("getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::getAction));
}
void RegisterLuaStudioActionRotationFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionRotationFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ActionRotationFrame",true);
ns["ActionRotationFrame"] = mt;
lua["ActionRotationFrame"] = sol::nil;
mt.set_function("setRotation",static_cast<void(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::setRotation));
mt.set_function("getRotation",static_cast<float(cocostudio::ActionRotationFrame::*)()>(&cocostudio::ActionRotationFrame::getRotation));
mt.set_function("getAction",sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionRotationFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::getAction)));
mt["_rotation"] = &cocostudio::ActionRotationFrame::_rotation;
}
void RegisterLuaStudioActionFadeFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionFadeFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ActionFadeFrame",true);
ns["ActionFadeFrame"] = mt;
lua["ActionFadeFrame"] = sol::nil;
mt.set_function("setOpacity",static_cast<void(cocostudio::ActionFadeFrame::*)(int)>(&cocostudio::ActionFadeFrame::setOpacity));
mt.set_function("getOpacity",static_cast<int(cocostudio::ActionFadeFrame::*)()>(&cocostudio::ActionFadeFrame::getOpacity));
mt.set_function("getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionFadeFrame::*)(float)>(&cocostudio::ActionFadeFrame::getAction));
}
void RegisterLuaStudioActionTintFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionTintFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ActionTintFrame",true);
ns["ActionTintFrame"] = mt;
lua["ActionTintFrame"] = sol::nil;
mt.set_function("setColor",static_cast<void(cocostudio::ActionTintFrame::*)(cocos2d::Color3B)>(&cocostudio::ActionTintFrame::setColor));
mt.set_function("getColor",static_cast<cocos2d::Color3B(cocostudio::ActionTintFrame::*)()>(&cocostudio::ActionTintFrame::getColor));
mt.set_function("getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionTintFrame::*)(float)>(&cocostudio::ActionTintFrame::getAction));
}
void RegisterLuaStudioActionObjectAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionObject,cocos2d::Ref,cocos2d::LuaObject>("ActionObject",true);
ns["ActionObject"] = mt;
lua["ActionObject"] = sol::nil;
mt.set_function("setName",static_cast<void(cocostudio::ActionObject::*)(const char*)>(&cocostudio::ActionObject::setName));
mt.set_function("getName",static_cast<const char*(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getName));
mt.set_function("setLoop",static_cast<void(cocostudio::ActionObject::*)(bool)>(&cocostudio::ActionObject::setLoop));
mt.set_function("getLoop",static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getLoop));
mt.set_function("setUnitTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setUnitTime));
mt.set_function("getUnitTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getUnitTime));
mt.set_function("setCurrentTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setCurrentTime));
mt.set_function("getCurrentTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getCurrentTime));
mt.set_function("getTotalTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getTotalTime));
mt.set_function("isPlaying",static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::isPlaying));
mt.set_function("play",sol::overload(static_cast<void(cocostudio::ActionObject::*)(cocos2d::CallFunc*)>(&cocostudio::ActionObject::play),static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::play)));
mt.set_function("pause",static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::pause));
mt.set_function("stop",static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::stop));
mt.set_function("addActionNode",static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::addActionNode));
mt.set_function("removeActionNode",static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::removeActionNode));
mt.set_function("updateToFrameByTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::updateToFrameByTime));
mt.set_function("initWithDictionary",static_cast<void(cocostudio::ActionObject::*)(const rapidjson::Value&,cocos2d::Ref*)>(&cocostudio::ActionObject::initWithDictionary));
mt.set_function("initWithBinary",static_cast<void(cocostudio::ActionObject::*)(cocostudio::CocoLoader*,cocostudio::stExpCocoNode*,cocos2d::Ref*)>(&cocostudio::ActionObject::initWithBinary));
mt.set_function("simulationActionUpdate",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::simulationActionUpdate));
}
void RegisterLuaStudioActionManagerExAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ActionManagerEx,cocos2d::Ref,cocos2d::LuaObject>("ActionManagerEx",true);
ns["ActionManagerEx"] = mt;
lua["ActionManagerEx"] = sol::nil;
mt.set_function("getActionByName",static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::getActionByName));
mt.set_function("playActionByName",sol::overload(static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*,cocos2d::CallFunc*)>(&cocostudio::ActionManagerEx::playActionByName),static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::playActionByName)));
mt.set_function("stopActionByName",static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::stopActionByName));
mt.set_function("initWithDictionary",sol::overload([](cocostudio::ActionManagerEx* obj,const char* arg0,const rapidjson::Value& arg1,cocos2d::Ref* arg2){return obj->initWithDictionary(arg0,arg1,arg2);},[](cocostudio::ActionManagerEx* obj,const char* arg0,const rapidjson::Value& arg1,cocos2d::Ref* arg2,int arg3){return obj->initWithDictionary(arg0,arg1,arg2,arg3);}));
mt.set_function("initWithBinary",static_cast<void(cocostudio::ActionManagerEx::*)(const char*,cocos2d::Ref*,cocostudio::CocoLoader*,cocostudio::stExpCocoNode*)>(&cocostudio::ActionManagerEx::initWithBinary));
mt.set_function("releaseActions",static_cast<void(cocostudio::ActionManagerEx::*)()>(&cocostudio::ActionManagerEx::releaseActions));
mt.set_function("getStudioVersionNumber",static_cast<int(cocostudio::ActionManagerEx::*)()const>(&cocostudio::ActionManagerEx::getStudioVersionNumber));
mt.set_function("getInstance",static_cast<cocostudio::ActionManagerEx*(*)()>(&cocostudio::ActionManagerEx::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocostudio::ActionManagerEx::destroyInstance));
}
void RegisterLuaStudioBaseDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("BaseData",false);
ns["BaseData"] = mt;
lua["BaseData"] = sol::nil;
mt.set_function("copy",static_cast<void(cocostudio::BaseData::*)(const cocostudio::BaseData*)>(&cocostudio::BaseData::copy));
mt.set_function("subtract",static_cast<void(cocostudio::BaseData::*)(cocostudio::BaseData*,cocostudio::BaseData*,bool)>(&cocostudio::BaseData::subtract));
mt.set_function("setColor",static_cast<void(cocostudio::BaseData::*)(const cocos2d::Color4B&)>(&cocostudio::BaseData::setColor));
mt.set_function("getColor",static_cast<cocos2d::Color4B(cocostudio::BaseData::*)()>(&cocostudio::BaseData::getColor));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::BaseData*(*)()>(&cocostudio::BaseData::create));
mt["x"] = &cocostudio::BaseData::x;
mt["y"] = &cocostudio::BaseData::y;
mt["zOrder"] = &cocostudio::BaseData::zOrder;
mt["skewX"] = &cocostudio::BaseData::skewX;
mt["skewY"] = &cocostudio::BaseData::skewY;
mt["scaleX"] = &cocostudio::BaseData::scaleX;
mt["scaleY"] = &cocostudio::BaseData::scaleY;
mt["tweenRotate"] = &cocostudio::BaseData::tweenRotate;
mt["isUseColorInfo"] = &cocostudio::BaseData::isUseColorInfo;
mt["a"] = &cocostudio::BaseData::a;
mt["r"] = &cocostudio::BaseData::r;
mt["g"] = &cocostudio::BaseData::g;
mt["b"] = &cocostudio::BaseData::b;
}
void RegisterLuaStudioDisplayDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("DisplayData",false);
ns["DisplayData"] = mt;
lua["DisplayData"] = sol::nil;
mt.set_function("copy",static_cast<void(cocostudio::DisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::DisplayData::copy));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::DisplayData*(*)()>(&cocostudio::DisplayData::create));
mt.set_function("changeDisplayToTexture",static_cast<std::string(*)(const std::string&)>(&cocostudio::DisplayData::changeDisplayToTexture));
mt["displayType"] = &cocostudio::DisplayData::displayType;
mt["displayName"] = &cocostudio::DisplayData::displayName;
}
