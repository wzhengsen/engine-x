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
void RegisterLuaCoreTintToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TintTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TintTo");
mt.set_function("clone",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::clone));
mt.set_function("reverse",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TintTo::*)(cocos2d::Node*)>(&cocos2d::TintTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TintTo::*)(float)>(&cocos2d::TintTo::update));
mt.set_function("new",sol::overload(static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create)));
}
void RegisterLuaCoreTintByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TintBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TintBy");
mt.set_function("clone",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::clone));
mt.set_function("reverse",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TintBy::*)(cocos2d::Node*)>(&cocos2d::TintBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TintBy::*)(float)>(&cocos2d::TintBy::update));
mt.set_function("new",static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create));
}
void RegisterLuaCoreDelayTimeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DelayTime,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","DelayTime");
mt.set_function("update",static_cast<void(cocos2d::DelayTime::*)(float)>(&cocos2d::DelayTime::update));
mt.set_function("reverse",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::reverse));
mt.set_function("clone",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::clone));
mt.set_function("new",static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create));
}
void RegisterLuaCoreAnimateAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate");
mt.set_function("setAnimation",static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation));
mt.set_function("getAnimation",sol::overload(static_cast<const cocos2d::Animation*(cocos2d::Animate::*)()const>(&cocos2d::Animate::getAnimation),static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation)));
mt.set_function("getCurrentFrameIndex",static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex));
mt.set_function("clone",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::clone));
mt.set_function("reverse",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Animate::*)(cocos2d::Node*)>(&cocos2d::Animate::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Animate::*)()>(&cocos2d::Animate::stop));
mt.set_function("update",static_cast<void(cocos2d::Animate::*)(float)>(&cocos2d::Animate::update));
mt.set_function("new",static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create));
}
void RegisterLuaCoreTargetedActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TargetedAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TargetedAction");
mt.set_function("setForcedTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget));
mt.set_function("getForcedTarget",sol::overload(static_cast<const cocos2d::Node*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::getForcedTarget),static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget)));
mt.set_function("clone",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::clone));
mt.set_function("reverse",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::stop));
mt.set_function("update",static_cast<void(cocos2d::TargetedAction::*)(float)>(&cocos2d::TargetedAction::update));
mt.set_function("new",static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create));
}
void RegisterLuaCoreActionFloatAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionFloat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionFloat");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionFloat::*)(cocos2d::Node*)>(&cocos2d::ActionFloat::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ActionFloat::*)(float)>(&cocos2d::ActionFloat::update));
mt.set_function("reverse",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::clone));
mt.set_function("new",static_cast<cocos2d::ActionFloat*(*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::create));
}
void RegisterLuaCoreAnimate3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate3D,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate3D");
mt.set_function("stop",static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::stop));
mt.set_function("step",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::step));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Node*)>(&cocos2d::Animate3D::startWithTarget));
mt.set_function("reverse",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::reverse));
mt.set_function("clone",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::update));
mt.set_function("getSpeed",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed));
mt.set_function("setSpeed",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed));
mt.set_function("getWeight",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight));
mt.set_function("setWeight",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight));
mt.set_function("setOriginInterval",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval));
mt.set_function("getOriginInterval",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval));
mt.set_function("setQuality",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality));
mt.set_function("getQuality",static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality));
mt.set_function("setKeyFrameUserInfo",static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo));
mt.set_function("getKeyFrameUserInfo",sol::overload(static_cast<cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)>(&cocos2d::Animate3D::getKeyFrameUserInfo),static_cast<const cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)const>(&cocos2d::Animate3D::getKeyFrameUserInfo)));
mt.set_function("new",sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create)));
mt.set_function("createWithFrames",sol::overload([](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2){return obj->createWithFrames(arg0,arg1,arg2);},[](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return obj->createWithFrames(arg0,arg1,arg2,arg3);}));
mt.set_function("getTransitionTime",static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime));
mt.set_function("setTransitionTime",static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime));
}
void RegisterLuaCoreEventKeyboardAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventKeyboard,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventKeyboard");
}
void RegisterLuaCorePropertiesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Properties>("cc","Properties");
mt.set_function("getNextProperty",static_cast<const char*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextProperty));
mt.set_function("getNextNamespace",static_cast<cocos2d::Properties*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextNamespace));
mt.set_function("rewind",static_cast<void(cocos2d::Properties::*)()>(&cocos2d::Properties::rewind));
mt.set_function("getNamespace",sol::overload(static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getNamespace),[](cocos2d::Properties* obj,const char* arg0){return obj->getNamespace(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getNamespace(arg0,arg1);},[](cocos2d::Properties* obj,const char* arg0,bool arg1,bool arg2){return obj->getNamespace(arg0,arg1,arg2);}));
mt.set_function("getId",static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getId));
mt.set_function("exists",static_cast<bool(cocos2d::Properties::*)(const char*)const>(&cocos2d::Properties::exists));
mt.set_function("getType",sol::overload([](cocos2d::Properties* obj){return obj->getType();},[](cocos2d::Properties* obj,const char* arg0){return obj->getType(arg0);}));
mt.set_function("getString",sol::overload([](cocos2d::Properties* obj){return obj->getString();},[](cocos2d::Properties* obj,const char* arg0){return obj->getString(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getString(arg0,arg1);}));
mt.set_function("setString",static_cast<bool(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setString));
mt.set_function("getBool",sol::overload([](cocos2d::Properties* obj){return obj->getBool();},[](cocos2d::Properties* obj,const char* arg0){return obj->getBool(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getBool(arg0,arg1);}));
mt.set_function("getInt",sol::overload([](cocos2d::Properties* obj){return obj->getInt();},[](cocos2d::Properties* obj,const char* arg0){return obj->getInt(arg0);}));
mt.set_function("getFloat",sol::overload([](cocos2d::Properties* obj){return obj->getFloat();},[](cocos2d::Properties* obj,const char* arg0){return obj->getFloat(arg0);}));
mt.set_function("getLong",sol::overload([](cocos2d::Properties* obj){return obj->getLong();},[](cocos2d::Properties* obj,const char* arg0){return obj->getLong(arg0);}));
mt.set_function("getMat4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Mat4*)const>(&cocos2d::Properties::getMat4));
mt.set_function("getVec2",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec2*)const>(&cocos2d::Properties::getVec2));
mt.set_function("getVec3",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getVec3));
mt.set_function("getVec4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getVec4));
mt.set_function("getQuaternionFromAxisAngle",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Quaternion*)const>(&cocos2d::Properties::getQuaternionFromAxisAngle));
mt.set_function("getColor",sol::overload(static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getColor),static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getColor)));
mt.set_function("getPath",static_cast<bool(cocos2d::Properties::*)(const char*,std::string*)const>(&cocos2d::Properties::getPath));
mt.set_function("getVariable",sol::overload([](cocos2d::Properties* obj,const char* arg0){return obj->getVariable(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getVariable(arg0,arg1);}));
mt.set_function("setVariable",static_cast<void(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setVariable));
mt.set_function("createNonRefCounted",static_cast<cocos2d::Properties*(*)(const std::string&)>(&cocos2d::Properties::createNonRefCounted));
mt.set_function("parseVec2",static_cast<bool(*)(const char*,cocos2d::Vec2*)>(&cocos2d::Properties::parseVec2));
mt.set_function("parseVec3",static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseVec3));
mt.set_function("parseVec4",static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseVec4));
mt.set_function("parseAxisAngle",static_cast<bool(*)(const char*,cocos2d::Quaternion*)>(&cocos2d::Properties::parseAxisAngle));
mt.set_function("parseColor",sol::overload(static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseColor),static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseColor)));
}
void RegisterLuaCoreUserDefaultAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::UserDefault>("cc","UserDefault");
mt.set_function("getBoolForKey",sol::overload(static_cast<bool(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::getBoolForKey),static_cast<bool(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getBoolForKey)));
mt.set_function("getIntegerForKey",sol::overload(static_cast<int(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::getIntegerForKey),static_cast<int(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getIntegerForKey)));
mt.set_function("getLargeIntForKey",sol::overload(static_cast<int64_t(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::getLargeIntForKey),static_cast<int64_t(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getLargeIntForKey)));
mt.set_function("getFloatForKey",sol::overload(static_cast<float(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::getFloatForKey),static_cast<float(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getFloatForKey)));
mt.set_function("getDoubleForKey",sol::overload(static_cast<double(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::getDoubleForKey),static_cast<double(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getDoubleForKey)));
mt.set_function("getStringForKey",sol::overload(static_cast<std::string(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::getStringForKey),static_cast<std::string(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getStringForKey)));
mt.set_function("setBoolForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::setBoolForKey));
mt.set_function("setIntegerForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::setIntegerForKey));
mt.set_function("setLargeIntForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::setLargeIntForKey));
mt.set_function("setFloatForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::setFloatForKey));
mt.set_function("setDoubleForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::setDoubleForKey));
mt.set_function("setStringForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::setStringForKey));
mt.set_function("flush",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::flush));
mt.set_function("deleteValueForKey",static_cast<void(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::deleteValueForKey));
mt.set_function("Clear",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::Clear));
mt.set_function("setEncryptEnabled",static_cast<void(cocos2d::UserDefault::*)(bool,cxx17::string_view,cxx17::string_view)>(&cocos2d::UserDefault::setEncryptEnabled));
mt.set_function("encrypt",sol::overload(static_cast<void(cocos2d::UserDefault::*)(std::string&,int)>(&cocos2d::UserDefault::encrypt),static_cast<void(cocos2d::UserDefault::*)(char*,size_t,int)>(&cocos2d::UserDefault::encrypt)));
mt.set_function("getInstance",static_cast<cocos2d::UserDefault*(*)()>(&cocos2d::UserDefault::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::UserDefault::destroyInstance));
mt.set_function("setDelegate",static_cast<void(*)(cocos2d::UserDefault*)>(&cocos2d::UserDefault::setDelegate));
}
