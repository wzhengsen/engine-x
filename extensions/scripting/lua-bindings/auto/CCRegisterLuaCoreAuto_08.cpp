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
void RegisterLuaCoreCatmullRomByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CatmullRomBy,cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CatmullRomBy");
mt.set_function("initWithDuration",static_cast<bool(cocos2d::CatmullRomBy::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::initWithDuration));
mt.set_function("clone",static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::clone));
mt.set_function("reverse",static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::reverse));
mt.set_function("new",static_cast<cocos2d::CatmullRomBy*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::create));
}
void RegisterLuaCoreActionEaseAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionEase");
mt.set_function("getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::getInnerAction));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionEase::*)(cocos2d::Node*)>(&cocos2d::ActionEase::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::stop));
mt.set_function("update",static_cast<void(cocos2d::ActionEase::*)(float)>(&cocos2d::ActionEase::update));
}
void RegisterLuaCoreEaseRateActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseRateAction");
mt.set_function("setRate",static_cast<void(cocos2d::EaseRateAction::*)(float)>(&cocos2d::EaseRateAction::setRate));
mt.set_function("getRate",static_cast<float(cocos2d::EaseRateAction::*)()const>(&cocos2d::EaseRateAction::getRate));
mt.set_function("new",static_cast<cocos2d::EaseRateAction*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::create));
}
void RegisterLuaCoreEaseExponentialInAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseExponentialIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseExponentialIn");
mt.set_function("clone",static_cast<cocos2d::EaseExponentialIn*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseExponentialIn::*)(float)>(&cocos2d::EaseExponentialIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::reverse));
mt.set_function("new",static_cast<cocos2d::EaseExponentialIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialIn::create));
}
void RegisterLuaCoreEaseExponentialOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseExponentialOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseExponentialOut");
mt.set_function("clone",static_cast<cocos2d::EaseExponentialOut*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseExponentialOut::*)(float)>(&cocos2d::EaseExponentialOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseExponentialOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialOut::create));
}
void RegisterLuaCoreEaseExponentialInOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseExponentialInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseExponentialInOut");
mt.set_function("clone",static_cast<cocos2d::EaseExponentialInOut*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseExponentialInOut::*)(float)>(&cocos2d::EaseExponentialInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseExponentialInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialInOut::create));
}
void RegisterLuaCoreEaseSineInAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseSineIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseSineIn");
mt.set_function("clone",static_cast<cocos2d::EaseSineIn*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseSineIn::*)(float)>(&cocos2d::EaseSineIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::reverse));
mt.set_function("new",static_cast<cocos2d::EaseSineIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineIn::create));
}
void RegisterLuaCoreEaseSineOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseSineOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseSineOut");
mt.set_function("clone",static_cast<cocos2d::EaseSineOut*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseSineOut::*)(float)>(&cocos2d::EaseSineOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseSineOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineOut::create));
}
void RegisterLuaCoreEaseSineInOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseSineInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseSineInOut");
mt.set_function("clone",static_cast<cocos2d::EaseSineInOut*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseSineInOut::*)(float)>(&cocos2d::EaseSineInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseSineInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineInOut::create));
}
void RegisterLuaCoreEaseBounceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBounce,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBounce");
}
