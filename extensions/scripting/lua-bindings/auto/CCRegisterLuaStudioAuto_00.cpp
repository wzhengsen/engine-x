#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioActionFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionFrame>("ccs","ActionFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetFrameIndex",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameIndex));
mt.set_function("GetFrameIndex",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameIndex));
mt.set_function("SetFrameTime",static_cast<void(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::setFrameTime));
mt.set_function("GetFrameTime",static_cast<float(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameTime));
mt.set_function("SetFrameType",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameType));
mt.set_function("GetFrameType",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameType));
mt.set_function("SetEasingType",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setEasingType));
mt.set_function("GetEasingType",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getEasingType));
mt.set_function("GetAction",sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::getAction)));
mt.set_function("SetEasingParameter",static_cast<void(cocostudio::ActionFrame::*)(std::vector<float, std::allocator<float> >&)>(&cocostudio::ActionFrame::setEasingParameter));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionFrame()>();
}
void RegisterLuaStudioActionMoveFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionMoveFrame>("ccs","ActionMoveFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetPosition",static_cast<void(cocostudio::ActionMoveFrame::*)(cocos2d::Vec2)>(&cocostudio::ActionMoveFrame::setPosition));
mt.set_function("GetPosition",static_cast<cocos2d::Vec2(cocostudio::ActionMoveFrame::*)()>(&cocostudio::ActionMoveFrame::getPosition));
mt.set_function("GetAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionMoveFrame::*)(float)>(&cocostudio::ActionMoveFrame::getAction));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionMoveFrame()>();
}
void RegisterLuaStudioActionScaleFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionScaleFrame>("ccs","ActionScaleFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetScaleX",static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleX));
mt.set_function("GetScaleX",static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleX));
mt.set_function("SetScaleY",static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleY));
mt.set_function("GetScaleY",static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleY));
mt.set_function("GetAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::getAction));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionScaleFrame()>();
}
void RegisterLuaStudioActionRotationFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionRotationFrame>("ccs","ActionRotationFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetRotation",static_cast<void(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::setRotation));
mt.set_function("GetRotation",static_cast<float(cocostudio::ActionRotationFrame::*)()>(&cocostudio::ActionRotationFrame::getRotation));
mt.set_function("GetAction",sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionRotationFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::getAction)));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionRotationFrame()>();
mt["Rotation"]=&cocostudio::ActionRotationFrame::_rotation;
}
void RegisterLuaStudioActionFadeFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionFadeFrame>("ccs","ActionFadeFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetOpacity",static_cast<void(cocostudio::ActionFadeFrame::*)(int)>(&cocostudio::ActionFadeFrame::setOpacity));
mt.set_function("GetOpacity",static_cast<int(cocostudio::ActionFadeFrame::*)()>(&cocostudio::ActionFadeFrame::getOpacity));
mt.set_function("GetAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionFadeFrame::*)(float)>(&cocostudio::ActionFadeFrame::getAction));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionFadeFrame()>();
}
void RegisterLuaStudioActionTintFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionTintFrame>("ccs","ActionTintFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetColor",static_cast<void(cocostudio::ActionTintFrame::*)(cocos2d::Color3B)>(&cocostudio::ActionTintFrame::setColor));
mt.set_function("GetColor",static_cast<cocos2d::Color3B(cocostudio::ActionTintFrame::*)()>(&cocostudio::ActionTintFrame::getColor));
mt.set_function("GetAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionTintFrame::*)(float)>(&cocostudio::ActionTintFrame::getAction));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionTintFrame()>();
}
void RegisterLuaStudioActionObjectAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionObject>("ccs","ActionObject",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetName",static_cast<void(cocostudio::ActionObject::*)(const char*)>(&cocostudio::ActionObject::setName));
mt.set_function("GetName",static_cast<const char*(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getName));
mt.set_function("SetLoop",static_cast<void(cocostudio::ActionObject::*)(bool)>(&cocostudio::ActionObject::setLoop));
mt.set_function("GetLoop",static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getLoop));
mt.set_function("SetUnitTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setUnitTime));
mt.set_function("GetUnitTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getUnitTime));
mt.set_function("SetCurrentTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setCurrentTime));
mt.set_function("GetCurrentTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getCurrentTime));
mt.set_function("GetTotalTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getTotalTime));
mt.set_function("IsPlaying",static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::isPlaying));
mt.set_function("Play",sol::overload(static_cast<void(cocostudio::ActionObject::*)(cocos2d::CallFunc*)>(&cocostudio::ActionObject::play),static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::play)));
mt.set_function("Pause",static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::pause));
mt.set_function("Stop",static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::stop));
mt.set_function("AddActionNode",static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::addActionNode));
mt.set_function("RemoveActionNode",static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::removeActionNode));
mt.set_function("UpdateToFrameByTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::updateToFrameByTime));
mt.set_function("InitWithDictionary",static_cast<void(cocostudio::ActionObject::*)(const rapidjson::Value&,cocos2d::Ref*)>(&cocostudio::ActionObject::initWithDictionary));
mt.set_function("InitWithBinary",static_cast<void(cocostudio::ActionObject::*)(cocostudio::CocoLoader*,cocostudio::stExpCocoNode*,cocos2d::Ref*)>(&cocostudio::ActionObject::initWithBinary));
mt.set_function("SimulationActionUpdate",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::simulationActionUpdate));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionObject()>();
}
void RegisterLuaStudioActionManagerExAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionManagerEx>("ccs","ActionManagerEx",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocostudio::ActionManagerEx*(*)()>(&cocostudio::ActionManagerEx::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocostudio::ActionManagerEx::destroyInstance));
mt.set_function("GetActionByName",static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::getActionByName));
mt.set_function("PlayActionByName",sol::overload(static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*,cocos2d::CallFunc*)>(&cocostudio::ActionManagerEx::playActionByName),static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::playActionByName)));
mt.set_function("StopActionByName",static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::stopActionByName));
mt.set_function("InitWithDictionary",sol::overload([](cocostudio::ActionManagerEx* obj,const char* arg0,const rapidjson::Value& arg1,cocos2d::Ref* arg2){return obj->initWithDictionary(arg0,arg1,arg2);},[](cocostudio::ActionManagerEx* obj,const char* arg0,const rapidjson::Value& arg1,cocos2d::Ref* arg2,int arg3){return obj->initWithDictionary(arg0,arg1,arg2,arg3);}));
mt.set_function("InitWithBinary",static_cast<void(cocostudio::ActionManagerEx::*)(const char*,cocos2d::Ref*,cocostudio::CocoLoader*,cocostudio::stExpCocoNode*)>(&cocostudio::ActionManagerEx::initWithBinary));
mt.set_function("ReleaseActions",static_cast<void(cocostudio::ActionManagerEx::*)()>(&cocostudio::ActionManagerEx::releaseActions));
mt.set_function("GetStudioVersionNumber",static_cast<int(cocostudio::ActionManagerEx::*)()const>(&cocostudio::ActionManagerEx::getStudioVersionNumber));
mt[sol::call_constructor]=sol::constructors<cocostudio::ActionManagerEx()>();
mt["Instance"]=sol::property(&cocostudio::ActionManagerEx::getInstance,[](std::nullptr_t){cocostudio::ActionManagerEx::destroyInstance();});
}
void RegisterLuaStudioBaseDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BaseData>("ccs","BaseData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::BaseData*(*)()>(&cocostudio::BaseData::create));
mt.set_function("Copy",static_cast<void(cocostudio::BaseData::*)(const cocostudio::BaseData*)>(&cocostudio::BaseData::copy));
mt.set_function("Subtract",static_cast<void(cocostudio::BaseData::*)(cocostudio::BaseData*,cocostudio::BaseData*,bool)>(&cocostudio::BaseData::subtract));
mt.set_function("SetColor",static_cast<void(cocostudio::BaseData::*)(const cocos2d::Color4B&)>(&cocostudio::BaseData::setColor));
mt.set_function("GetColor",static_cast<cocos2d::Color4B(cocostudio::BaseData::*)()>(&cocostudio::BaseData::getColor));
mt[sol::call_constructor]=sol::constructors<cocostudio::BaseData()>();
mt["X"]=&cocostudio::BaseData::x;
mt["Y"]=&cocostudio::BaseData::y;
mt["ZOrder"]=&cocostudio::BaseData::zOrder;
mt["SkewX"]=&cocostudio::BaseData::skewX;
mt["SkewY"]=&cocostudio::BaseData::skewY;
mt["ScaleX"]=&cocostudio::BaseData::scaleX;
mt["ScaleY"]=&cocostudio::BaseData::scaleY;
mt["TweenRotate"]=&cocostudio::BaseData::tweenRotate;
mt["IsUseColorInfo"]=&cocostudio::BaseData::isUseColorInfo;
mt["A"]=&cocostudio::BaseData::a;
mt["R"]=&cocostudio::BaseData::r;
mt["G"]=&cocostudio::BaseData::g;
mt["B"]=&cocostudio::BaseData::b;
}
void RegisterLuaStudioDisplayDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::DisplayData>("ccs","DisplayData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::DisplayData*(*)()>(&cocostudio::DisplayData::create));
mt.set_function("ChangeDisplayToTexture",static_cast<std::string(*)(const std::string&)>(&cocostudio::DisplayData::changeDisplayToTexture));
mt.set_function("Copy",static_cast<void(cocostudio::DisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::DisplayData::copy));
mt[sol::call_constructor]=sol::constructors<cocostudio::DisplayData()>();
mt["DisplayType"]=&cocostudio::DisplayData::displayType;
mt["DisplayName"]=&cocostudio::DisplayData::displayName;
}
