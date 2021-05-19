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
void RegisterLuaCoreEaseExponentialInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseExponentialInOut>("cc","EaseExponentialInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseExponentialInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseExponentialInOut*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseExponentialInOut::*)(float)>(&cocos2d::EaseExponentialInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::reverse));
}
void RegisterLuaCoreEaseSineInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseSineIn>("cc","EaseSineIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseSineIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseSineIn*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseSineIn::*)(float)>(&cocos2d::EaseSineIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::reverse));
}
void RegisterLuaCoreEaseSineOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseSineOut>("cc","EaseSineOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseSineOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseSineOut*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseSineOut::*)(float)>(&cocos2d::EaseSineOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::reverse));
}
void RegisterLuaCoreEaseSineInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseSineInOut>("cc","EaseSineInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseSineInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseSineInOut*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseSineInOut::*)(float)>(&cocos2d::EaseSineInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::reverse));
}
void RegisterLuaCoreEaseBounceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBounce>("cc","EaseBounce",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
}
void RegisterLuaCoreEaseBounceInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBounceIn>("cc","EaseBounceIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBounceIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseBounceIn*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseBounceIn::*)(float)>(&cocos2d::EaseBounceIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::reverse));
}
void RegisterLuaCoreEaseBounceOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBounceOut>("cc","EaseBounceOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBounceOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseBounceOut*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseBounceOut::*)(float)>(&cocos2d::EaseBounceOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::reverse));
}
void RegisterLuaCoreEaseBounceInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBounceInOut>("cc","EaseBounceInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBounceInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseBounceInOut*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseBounceInOut::*)(float)>(&cocos2d::EaseBounceInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::reverse));
}
void RegisterLuaCoreEaseBackInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBackIn>("cc","EaseBackIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBackIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseBackIn*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseBackIn::*)(float)>(&cocos2d::EaseBackIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::reverse));
}
void RegisterLuaCoreEaseBackOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBackOut>("cc","EaseBackOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBackOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseBackOut*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseBackOut::*)(float)>(&cocos2d::EaseBackOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::reverse));
}
