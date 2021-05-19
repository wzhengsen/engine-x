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
void RegisterLuaCoreEaseCircleActionInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCircleActionIn>("cc","EaseCircleActionIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCircleActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseCircleActionIn*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseCircleActionIn::*)(float)>(&cocos2d::EaseCircleActionIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::reverse));
}
void RegisterLuaCoreEaseCircleActionOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCircleActionOut>("cc","EaseCircleActionOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCircleActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseCircleActionOut*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseCircleActionOut::*)(float)>(&cocos2d::EaseCircleActionOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::reverse));
}
void RegisterLuaCoreEaseCircleActionInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCircleActionInOut>("cc","EaseCircleActionInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCircleActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseCircleActionInOut*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseCircleActionInOut::*)(float)>(&cocos2d::EaseCircleActionInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::reverse));
}
void RegisterLuaCoreEaseCubicActionInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCubicActionIn>("cc","EaseCubicActionIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCubicActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseCubicActionIn*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseCubicActionIn::*)(float)>(&cocos2d::EaseCubicActionIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::reverse));
}
void RegisterLuaCoreEaseCubicActionOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCubicActionOut>("cc","EaseCubicActionOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCubicActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseCubicActionOut*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseCubicActionOut::*)(float)>(&cocos2d::EaseCubicActionOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::reverse));
}
void RegisterLuaCoreEaseCubicActionInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCubicActionInOut>("cc","EaseCubicActionInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCubicActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseCubicActionInOut*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseCubicActionInOut::*)(float)>(&cocos2d::EaseCubicActionInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::reverse));
}
void RegisterLuaCoreEaseInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseIn>("cc","EaseIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseIn*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseIn*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseIn::*)(float)>(&cocos2d::EaseIn::update));
mt.set_function("Reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::reverse));
}
void RegisterLuaCoreEaseOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseOut>("cc","EaseOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseOut*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseOut::*)(float)>(&cocos2d::EaseOut::update));
mt.set_function("Reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::reverse));
}
void RegisterLuaCoreEaseInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseInOut>("cc","EaseInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseInOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseInOut*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseInOut::*)(float)>(&cocos2d::EaseInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::reverse));
}
void RegisterLuaCoreEaseElasticAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElastic>("cc","EaseElastic",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetPeriod",static_cast<float(cocos2d::EaseElastic::*)()const>(&cocos2d::EaseElastic::getPeriod));
mt.set_function("SetPeriod",static_cast<void(cocos2d::EaseElastic::*)(float)>(&cocos2d::EaseElastic::setPeriod));
}
