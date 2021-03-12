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
void RegisterLuaCoreTransitionFadeTRAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionFadeTR",false);
ns["TransitionFadeTR"] = mt;
lua["TransitionFadeTR"] = sol::nil;
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeTR::actionWithSize));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFadeTR::*)()>(&cocos2d::TransitionFadeTR::onEnter));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionFadeTR::easeActionWithAction));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionFadeTR::*)()>(&cocos2d::TransitionFadeTR::onExit));
mt.set_function("draw",static_cast<void(cocos2d::TransitionFadeTR::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionFadeTR::draw));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeTR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeTR::create));
}
void RegisterLuaCoreTransitionFadeBLAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFadeBL,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionFadeBL",false);
ns["TransitionFadeBL"] = mt;
lua["TransitionFadeBL"] = sol::nil;
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeBL::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeBL::actionWithSize));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeBL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeBL::create));
}
void RegisterLuaCoreTransitionFadeUpAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFadeUp,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionFadeUp",false);
ns["TransitionFadeUp"] = mt;
lua["TransitionFadeUp"] = sol::nil;
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeUp::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeUp::actionWithSize));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeUp*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeUp::create));
}
void RegisterLuaCoreTransitionFadeDownAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFadeDown,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionFadeDown",false);
ns["TransitionFadeDown"] = mt;
lua["TransitionFadeDown"] = sol::nil;
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeDown::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeDown::actionWithSize));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeDown*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeDown::create));
}
void RegisterLuaCoreTransitionPageTurnAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionPageTurn,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionPageTurn",false);
ns["TransitionPageTurn"] = mt;
lua["TransitionPageTurn"] = sol::nil;
mt.set_function("draw",static_cast<void(cocos2d::TransitionPageTurn::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionPageTurn::draw));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration));
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionPageTurn::*)()>(&cocos2d::TransitionPageTurn::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionPageTurn::*)()>(&cocos2d::TransitionPageTurn::onExit));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create));
}
void RegisterLuaCoreTransitionProgressAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionProgress",false);
ns["TransitionProgress"] = mt;
lua["TransitionProgress"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onExit));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create));
}
void RegisterLuaCoreTransitionProgressRadialCCWAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionProgressRadialCCW",false);
ns["TransitionProgressRadialCCW"] = mt;
lua["TransitionProgressRadialCCW"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create));
}
void RegisterLuaCoreTransitionProgressRadialCWAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionProgressRadialCW",false);
ns["TransitionProgressRadialCW"] = mt;
lua["TransitionProgressRadialCW"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create));
}
void RegisterLuaCoreTransitionProgressHorizontalAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionProgressHorizontal,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionProgressHorizontal",false);
ns["TransitionProgressHorizontal"] = mt;
lua["TransitionProgressHorizontal"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create));
}
void RegisterLuaCoreTransitionProgressVerticalAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionProgressVertical,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionProgressVertical",false);
ns["TransitionProgressVertical"] = mt;
lua["TransitionProgressVertical"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create));
}
