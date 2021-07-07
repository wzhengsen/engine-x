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
void RegisterLuaCoreTransitionFadeTRAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFadeTR).name()] = sol::usertype_traits<cocos2d::TransitionFadeTR*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFadeTR>("deprecated.cocos2d::TransitionFadeTR");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFadeTR*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable(),sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable());
lua["cc"]["TransitionFadeTR"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionFadeTR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeTR::create);
mt["ActionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeTR::actionWithSize);
}
void RegisterLuaCoreTransitionFadeBLAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFadeBL).name()] = sol::usertype_traits<cocos2d::TransitionFadeBL*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFadeBL>("deprecated.cocos2d::TransitionFadeBL");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFadeBL*>::metatable(),sol::usertype_traits<cocos2d::TransitionFadeTR*>::metatable());
lua["cc"]["TransitionFadeBL"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionFadeBL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeBL::create);
}
void RegisterLuaCoreTransitionFadeUpAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFadeUp).name()] = sol::usertype_traits<cocos2d::TransitionFadeUp*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFadeUp>("deprecated.cocos2d::TransitionFadeUp");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFadeUp*>::metatable(),sol::usertype_traits<cocos2d::TransitionFadeTR*>::metatable());
lua["cc"]["TransitionFadeUp"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionFadeUp*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeUp::create);
}
void RegisterLuaCoreTransitionFadeDownAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFadeDown).name()] = sol::usertype_traits<cocos2d::TransitionFadeDown*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFadeDown>("deprecated.cocos2d::TransitionFadeDown");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFadeDown*>::metatable(),sol::usertype_traits<cocos2d::TransitionFadeTR*>::metatable());
lua["cc"]["TransitionFadeDown"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionFadeDown*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeDown::create);
}
void RegisterLuaCoreTransitionPageTurnAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionPageTurn).name()] = sol::usertype_traits<cocos2d::TransitionPageTurn*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionPageTurn>("deprecated.cocos2d::TransitionPageTurn");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionPageTurn*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionPageTurn"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration);
mt["ActionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize);
}
void RegisterLuaCoreTransitionProgressAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgress).name()] = sol::usertype_traits<cocos2d::TransitionProgress*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgress>("deprecated.cocos2d::TransitionProgress");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgress*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionProgress"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create);
}
void RegisterLuaCoreTransitionProgressRadialCCWAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgressRadialCCW).name()] = sol::usertype_traits<cocos2d::TransitionProgressRadialCCW*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgressRadialCCW>("deprecated.cocos2d::TransitionProgressRadialCCW");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgressRadialCCW*>::metatable(),sol::usertype_traits<cocos2d::TransitionProgress*>::metatable());
lua["cc"]["TransitionProgressRadialCCW"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create);
}
void RegisterLuaCoreTransitionProgressRadialCWAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgressRadialCW).name()] = sol::usertype_traits<cocos2d::TransitionProgressRadialCW*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgressRadialCW>("deprecated.cocos2d::TransitionProgressRadialCW");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgressRadialCW*>::metatable(),sol::usertype_traits<cocos2d::TransitionProgress*>::metatable());
lua["cc"]["TransitionProgressRadialCW"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create);
}
void RegisterLuaCoreTransitionProgressHorizontalAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgressHorizontal).name()] = sol::usertype_traits<cocos2d::TransitionProgressHorizontal*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgressHorizontal>("deprecated.cocos2d::TransitionProgressHorizontal");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgressHorizontal*>::metatable(),sol::usertype_traits<cocos2d::TransitionProgress*>::metatable());
lua["cc"]["TransitionProgressHorizontal"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create);
}
void RegisterLuaCoreTransitionProgressVerticalAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgressVertical).name()] = sol::usertype_traits<cocos2d::TransitionProgressVertical*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgressVertical>("deprecated.cocos2d::TransitionProgressVertical");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgressVertical*>::metatable(),sol::usertype_traits<cocos2d::TransitionProgress*>::metatable());
lua["cc"]["TransitionProgressVertical"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create);
}
