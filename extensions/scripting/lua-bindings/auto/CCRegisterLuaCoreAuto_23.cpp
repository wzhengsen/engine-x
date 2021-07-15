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
namespace cocos2d{
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
void RegisterLuaCoreTransitionProgressInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgressInOut).name()] = sol::usertype_traits<cocos2d::TransitionProgressInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgressInOut>("deprecated.cocos2d::TransitionProgressInOut");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgressInOut*>::metatable(),sol::usertype_traits<cocos2d::TransitionProgress*>::metatable());
lua["cc"]["TransitionProgressInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgressInOut*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressInOut::create);
}
void RegisterLuaCoreTransitionProgressOutInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionProgressOutIn).name()] = sol::usertype_traits<cocos2d::TransitionProgressOutIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionProgressOutIn>("deprecated.cocos2d::TransitionProgressOutIn");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionProgressOutIn*>::metatable(),sol::usertype_traits<cocos2d::TransitionProgress*>::metatable());
lua["cc"]["TransitionProgressOutIn"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionProgressOutIn*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressOutIn::create);
}
void RegisterLuaCoreCameraFlagAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,9);
enumTable["DEFAULT"]=cocos2d::CameraFlag::DEFAULT;
enumTable["USER1"]=cocos2d::CameraFlag::USER1;
enumTable["USER2"]=cocos2d::CameraFlag::USER2;
enumTable["USER3"]=cocos2d::CameraFlag::USER3;
enumTable["USER4"]=cocos2d::CameraFlag::USER4;
enumTable["USER5"]=cocos2d::CameraFlag::USER5;
enumTable["USER6"]=cocos2d::CameraFlag::USER6;
enumTable["USER7"]=cocos2d::CameraFlag::USER7;
enumTable["USER8"]=cocos2d::CameraFlag::USER8;
lua["cc"]["CameraFlag"]=lua.NewEnum(enumTable);
}
}
