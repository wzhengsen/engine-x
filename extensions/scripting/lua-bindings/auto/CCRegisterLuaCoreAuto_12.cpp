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
void RegisterLuaCoreEaseElasticInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElasticIn>("cc","EaseElasticIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);}));
mt.set_function("Clone",static_cast<cocos2d::EaseElasticIn*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseElasticIn::*)(float)>(&cocos2d::EaseElasticIn::update));
mt.set_function("Reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::reverse));
}
void RegisterLuaCoreEaseElasticOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElasticOut>("cc","EaseElasticOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);}));
mt.set_function("Clone",static_cast<cocos2d::EaseElasticOut*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseElasticOut::*)(float)>(&cocos2d::EaseElasticOut::update));
mt.set_function("Reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::reverse));
}
void RegisterLuaCoreEaseElasticInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElasticInOut>("cc","EaseElasticInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);}));
mt.set_function("Clone",static_cast<cocos2d::EaseElasticInOut*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseElasticInOut::*)(float)>(&cocos2d::EaseElasticInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::reverse));
}
void RegisterLuaCoreEaseBezierActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBezierAction>("cc","EaseBezierAction",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBezierAction*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBezierAction::create));
mt.set_function("Update",static_cast<void(cocos2d::EaseBezierAction::*)(float)>(&cocos2d::EaseBezierAction::update));
mt.set_function("Clone",static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::clone));
mt.set_function("Reverse",static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::reverse));
mt.set_function("SetBezierParamer",static_cast<void(cocos2d::EaseBezierAction::*)(float,float,float,float)>(&cocos2d::EaseBezierAction::setBezierParamer));
}
void RegisterLuaCoreActionInstantAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionInstant>("cc","ActionInstant",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Clone",static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::clone));
mt.set_function("Reverse",static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ActionInstant::*)(cocos2d::Node*)>(&cocos2d::ActionInstant::startWithTarget));
mt.set_function("IsDone",static_cast<bool(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::isDone));
mt.set_function("Step",static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::step));
mt.set_function("Update",static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::update));
}
void RegisterLuaCoreShowAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Show>("cc","Show",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Show*(*)()>(&cocos2d::Show::create));
mt.set_function("Update",static_cast<void(cocos2d::Show::*)(float)>(&cocos2d::Show::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Show::*)()const>(&cocos2d::Show::reverse));
mt.set_function("Clone",static_cast<cocos2d::Show*(cocos2d::Show::*)()const>(&cocos2d::Show::clone));
}
void RegisterLuaCoreHideAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Hide>("cc","Hide",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Hide*(*)()>(&cocos2d::Hide::create));
mt.set_function("Update",static_cast<void(cocos2d::Hide::*)(float)>(&cocos2d::Hide::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Hide::*)()const>(&cocos2d::Hide::reverse));
mt.set_function("Clone",static_cast<cocos2d::Hide*(cocos2d::Hide::*)()const>(&cocos2d::Hide::clone));
}
void RegisterLuaCoreToggleVisibilityAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ToggleVisibility>("cc","ToggleVisibility",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create));
mt.set_function("Update",static_cast<void(cocos2d::ToggleVisibility::*)(float)>(&cocos2d::ToggleVisibility::update));
mt.set_function("Reverse",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::reverse));
mt.set_function("Clone",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::clone));
}
void RegisterLuaCoreRemoveSelfAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RemoveSelf>("cc","RemoveSelf",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::RemoveSelf* obj){return obj->create();},[](cocos2d::RemoveSelf* obj,bool arg0){return obj->create(arg0);}));
mt.set_function("Update",static_cast<void(cocos2d::RemoveSelf::*)(float)>(&cocos2d::RemoveSelf::update));
mt.set_function("Clone",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::clone));
mt.set_function("Reverse",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::reverse));
}
void RegisterLuaCoreFlipXAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipX>("cc","FlipX",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create));
mt.set_function("Update",static_cast<void(cocos2d::FlipX::*)(float)>(&cocos2d::FlipX::update));
mt.set_function("Reverse",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::reverse));
mt.set_function("Clone",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::clone));
}
