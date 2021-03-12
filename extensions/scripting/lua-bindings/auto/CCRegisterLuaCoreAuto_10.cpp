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
void RegisterLuaCoreEaseQuarticActionOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuarticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuarticActionOut",false);
ns["EaseQuarticActionOut"] = mt;
lua["EaseQuarticActionOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuarticActionOut*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuarticActionOut::*)(float)>(&cocos2d::EaseQuarticActionOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuarticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionOut::create));
}
void RegisterLuaCoreEaseQuarticActionInOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuarticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuarticActionInOut",false);
ns["EaseQuarticActionInOut"] = mt;
lua["EaseQuarticActionInOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuarticActionInOut*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuarticActionInOut::*)(float)>(&cocos2d::EaseQuarticActionInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuarticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionInOut::create));
}
void RegisterLuaCoreEaseQuinticActionInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuinticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuinticActionIn",false);
ns["EaseQuinticActionIn"] = mt;
lua["EaseQuinticActionIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuinticActionIn*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuinticActionIn::*)(float)>(&cocos2d::EaseQuinticActionIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuinticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionIn::create));
}
void RegisterLuaCoreEaseQuinticActionOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuinticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuinticActionOut",false);
ns["EaseQuinticActionOut"] = mt;
lua["EaseQuinticActionOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuinticActionOut*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuinticActionOut::*)(float)>(&cocos2d::EaseQuinticActionOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuinticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionOut::create));
}
void RegisterLuaCoreEaseQuinticActionInOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuinticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuinticActionInOut",false);
ns["EaseQuinticActionInOut"] = mt;
lua["EaseQuinticActionInOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuinticActionInOut*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuinticActionInOut::*)(float)>(&cocos2d::EaseQuinticActionInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuinticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionInOut::create));
}
void RegisterLuaCoreEaseCircleActionInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseCircleActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseCircleActionIn",false);
ns["EaseCircleActionIn"] = mt;
lua["EaseCircleActionIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseCircleActionIn*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseCircleActionIn::*)(float)>(&cocos2d::EaseCircleActionIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCircleActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionIn::create));
}
void RegisterLuaCoreEaseCircleActionOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseCircleActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseCircleActionOut",false);
ns["EaseCircleActionOut"] = mt;
lua["EaseCircleActionOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseCircleActionOut*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseCircleActionOut::*)(float)>(&cocos2d::EaseCircleActionOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCircleActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionOut::create));
}
void RegisterLuaCoreEaseCircleActionInOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseCircleActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseCircleActionInOut",false);
ns["EaseCircleActionInOut"] = mt;
lua["EaseCircleActionInOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseCircleActionInOut*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseCircleActionInOut::*)(float)>(&cocos2d::EaseCircleActionInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCircleActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionInOut::create));
}
void RegisterLuaCoreEaseCubicActionInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseCubicActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseCubicActionIn",false);
ns["EaseCubicActionIn"] = mt;
lua["EaseCubicActionIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseCubicActionIn*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseCubicActionIn::*)(float)>(&cocos2d::EaseCubicActionIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCubicActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionIn::create));
}
void RegisterLuaCoreEaseCubicActionOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseCubicActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseCubicActionOut",false);
ns["EaseCubicActionOut"] = mt;
lua["EaseCubicActionOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseCubicActionOut*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseCubicActionOut::*)(float)>(&cocos2d::EaseCubicActionOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseCubicActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionOut::create));
}
