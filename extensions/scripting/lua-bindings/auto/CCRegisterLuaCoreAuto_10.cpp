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
void RegisterLuaCoreEaseBackInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBackInOut>("cc","EaseBackInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBackInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseBackInOut*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseBackInOut::*)(float)>(&cocos2d::EaseBackInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::reverse));
}
void RegisterLuaCoreEaseQuadraticActionInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuadraticActionIn>("cc","EaseQuadraticActionIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuadraticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuadraticActionIn*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuadraticActionIn::*)(float)>(&cocos2d::EaseQuadraticActionIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::reverse));
}
void RegisterLuaCoreEaseQuadraticActionOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuadraticActionOut>("cc","EaseQuadraticActionOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuadraticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuadraticActionOut*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuadraticActionOut::*)(float)>(&cocos2d::EaseQuadraticActionOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::reverse));
}
void RegisterLuaCoreEaseQuadraticActionInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuadraticActionInOut>("cc","EaseQuadraticActionInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuadraticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuadraticActionInOut*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuadraticActionInOut::*)(float)>(&cocos2d::EaseQuadraticActionInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::reverse));
}
void RegisterLuaCoreEaseQuarticActionInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuarticActionIn>("cc","EaseQuarticActionIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuarticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuarticActionIn*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuarticActionIn::*)(float)>(&cocos2d::EaseQuarticActionIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::reverse));
}
void RegisterLuaCoreEaseQuarticActionOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuarticActionOut>("cc","EaseQuarticActionOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuarticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuarticActionOut*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuarticActionOut::*)(float)>(&cocos2d::EaseQuarticActionOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::reverse));
}
void RegisterLuaCoreEaseQuarticActionInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuarticActionInOut>("cc","EaseQuarticActionInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuarticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuarticActionInOut*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuarticActionInOut::*)(float)>(&cocos2d::EaseQuarticActionInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::reverse));
}
void RegisterLuaCoreEaseQuinticActionInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuinticActionIn>("cc","EaseQuinticActionIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuinticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuinticActionIn*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuinticActionIn::*)(float)>(&cocos2d::EaseQuinticActionIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::reverse));
}
void RegisterLuaCoreEaseQuinticActionOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuinticActionOut>("cc","EaseQuinticActionOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuinticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuinticActionOut*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuinticActionOut::*)(float)>(&cocos2d::EaseQuinticActionOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::reverse));
}
void RegisterLuaCoreEaseQuinticActionInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseQuinticActionInOut>("cc","EaseQuinticActionInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuinticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionInOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseQuinticActionInOut*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseQuinticActionInOut::*)(float)>(&cocos2d::EaseQuinticActionInOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::reverse));
}
