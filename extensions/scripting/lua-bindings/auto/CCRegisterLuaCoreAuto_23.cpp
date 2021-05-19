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
void RegisterLuaCoreTransitionFadeUpAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeUp>("cc","TransitionFadeUp",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeUp*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeUp::create));
mt.set_function("ActionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeUp::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeUp::actionWithSize));
}
void RegisterLuaCoreTransitionFadeDownAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeDown>("cc","TransitionFadeDown",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeDown*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeDown::create));
mt.set_function("ActionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeDown::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeDown::actionWithSize));
}
void RegisterLuaCoreTransitionPageTurnAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionPageTurn>("cc","TransitionPageTurn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionPageTurn::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionPageTurn::draw));
mt.set_function("InitWithDuration",static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration));
mt.set_function("ActionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionPageTurn::*)()>(&cocos2d::TransitionPageTurn::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionPageTurn::*)()>(&cocos2d::TransitionPageTurn::onExit));
}
void RegisterLuaCoreTransitionProgressAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgress>("cc","TransitionProgress",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onExit));
}
void RegisterLuaCoreTransitionProgressRadialCCWAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCCW>("cc","TransitionProgressRadialCCW",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create));
}
void RegisterLuaCoreTransitionProgressRadialCWAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCW>("cc","TransitionProgressRadialCW",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create));
}
void RegisterLuaCoreTransitionProgressHorizontalAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressHorizontal>("cc","TransitionProgressHorizontal",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create));
}
void RegisterLuaCoreTransitionProgressVerticalAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressVertical>("cc","TransitionProgressVertical",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create));
}
void RegisterLuaCoreTransitionProgressInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressInOut>("cc","TransitionProgressInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressInOut*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressInOut::create));
}
void RegisterLuaCoreTransitionProgressOutInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressOutIn>("cc","TransitionProgressOutIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressOutIn*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressOutIn::create));
}
