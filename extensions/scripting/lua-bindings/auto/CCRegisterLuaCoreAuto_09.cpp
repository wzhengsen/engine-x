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
void RegisterLuaCoreEaseBounceInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseBounceIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseBounceIn",false);
ns["EaseBounceIn"] = mt;
lua["EaseBounceIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseBounceIn*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseBounceIn::*)(float)>(&cocos2d::EaseBounceIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBounceIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceIn::create));
}
void RegisterLuaCoreEaseBounceOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseBounceOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseBounceOut",false);
ns["EaseBounceOut"] = mt;
lua["EaseBounceOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseBounceOut*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseBounceOut::*)(float)>(&cocos2d::EaseBounceOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBounceOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceOut::create));
}
void RegisterLuaCoreEaseBounceInOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseBounceInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseBounceInOut",false);
ns["EaseBounceInOut"] = mt;
lua["EaseBounceInOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseBounceInOut*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseBounceInOut::*)(float)>(&cocos2d::EaseBounceInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBounceInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceInOut::create));
}
void RegisterLuaCoreEaseBackInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseBackIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseBackIn",false);
ns["EaseBackIn"] = mt;
lua["EaseBackIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseBackIn*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseBackIn::*)(float)>(&cocos2d::EaseBackIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBackIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackIn::create));
}
void RegisterLuaCoreEaseBackOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseBackOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseBackOut",false);
ns["EaseBackOut"] = mt;
lua["EaseBackOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseBackOut*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseBackOut::*)(float)>(&cocos2d::EaseBackOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBackOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackOut::create));
}
void RegisterLuaCoreEaseBackInOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseBackInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseBackInOut",false);
ns["EaseBackInOut"] = mt;
lua["EaseBackInOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseBackInOut*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseBackInOut::*)(float)>(&cocos2d::EaseBackInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseBackInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackInOut::create));
}
void RegisterLuaCoreEaseQuadraticActionInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuadraticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuadraticActionIn",false);
ns["EaseQuadraticActionIn"] = mt;
lua["EaseQuadraticActionIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuadraticActionIn*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuadraticActionIn::*)(float)>(&cocos2d::EaseQuadraticActionIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuadraticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionIn::create));
}
void RegisterLuaCoreEaseQuadraticActionOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuadraticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuadraticActionOut",false);
ns["EaseQuadraticActionOut"] = mt;
lua["EaseQuadraticActionOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuadraticActionOut*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuadraticActionOut::*)(float)>(&cocos2d::EaseQuadraticActionOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuadraticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionOut::create));
}
void RegisterLuaCoreEaseQuadraticActionInOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuadraticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuadraticActionInOut",false);
ns["EaseQuadraticActionInOut"] = mt;
lua["EaseQuadraticActionInOut"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuadraticActionInOut*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuadraticActionInOut::*)(float)>(&cocos2d::EaseQuadraticActionInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuadraticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionInOut::create));
}
void RegisterLuaCoreEaseQuarticActionInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EaseQuarticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("EaseQuarticActionIn",false);
ns["EaseQuarticActionIn"] = mt;
lua["EaseQuarticActionIn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EaseQuarticActionIn*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseQuarticActionIn::*)(float)>(&cocos2d::EaseQuarticActionIn::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseQuarticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionIn::create));
}
