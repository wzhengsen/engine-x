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
void RegisterLuaCoreSequenceAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Sequence,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Sequence",false);
ns["Sequence"] = mt;
lua["Sequence"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::clone));
mt.set_function("reverse",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Sequence::*)(cocos2d::Node*)>(&cocos2d::Sequence::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Sequence::*)()>(&cocos2d::Sequence::stop));
mt.set_function("isDone",static_cast<bool(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::isDone));
mt.set_function("update",static_cast<void(cocos2d::Sequence::*)(float)>(&cocos2d::Sequence::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Sequence*(*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Sequence::create));
mt.set_function("createWithVariableList",static_cast<cocos2d::Sequence*(*)(cocos2d::FiniteTimeAction*,va_list)>(&cocos2d::Sequence::createWithVariableList));
mt.set_function("createWithTwoActions",static_cast<cocos2d::Sequence*(*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Sequence::createWithTwoActions));
}
void RegisterLuaCoreRepeatAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Repeat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Repeat",false);
ns["Repeat"] = mt;
lua["Repeat"] = sol::nil;
mt.set_function("setInnerAction",static_cast<void(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*)>(&cocos2d::Repeat::setInnerAction));
mt.set_function("getInnerAction",static_cast<cocos2d::FiniteTimeAction*(cocos2d::Repeat::*)()>(&cocos2d::Repeat::getInnerAction));
mt.set_function("clone",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::clone));
mt.set_function("reverse",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Repeat::*)(cocos2d::Node*)>(&cocos2d::Repeat::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Repeat::*)()>(&cocos2d::Repeat::stop));
mt.set_function("update",static_cast<void(cocos2d::Repeat::*)(float)>(&cocos2d::Repeat::update));
mt.set_function("isDone",static_cast<bool(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::isDone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Repeat*(*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::create));
}
void RegisterLuaCoreRepeatForeverAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::RepeatForever,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("RepeatForever",false);
ns["RepeatForever"] = mt;
lua["RepeatForever"] = sol::nil;
mt.set_function("setInnerAction",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::setInnerAction));
mt.set_function("getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::RepeatForever::*)()>(&cocos2d::RepeatForever::getInnerAction));
mt.set_function("clone",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::clone));
mt.set_function("reverse",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::Node*)>(&cocos2d::RepeatForever::startWithTarget));
mt.set_function("step",static_cast<void(cocos2d::RepeatForever::*)(float)>(&cocos2d::RepeatForever::step));
mt.set_function("isDone",static_cast<bool(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::isDone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::RepeatForever*(*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::create));
}
void RegisterLuaCoreSpawnAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Spawn,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Spawn",false);
ns["Spawn"] = mt;
lua["Spawn"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::clone));
mt.set_function("reverse",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Spawn::*)(cocos2d::Node*)>(&cocos2d::Spawn::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Spawn::*)()>(&cocos2d::Spawn::stop));
mt.set_function("update",static_cast<void(cocos2d::Spawn::*)(float)>(&cocos2d::Spawn::update));
mt.set_function("createWithVariableList",static_cast<cocos2d::Spawn*(*)(cocos2d::FiniteTimeAction*,va_list)>(&cocos2d::Spawn::createWithVariableList));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Spawn*(*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Spawn::create));
mt.set_function("createWithTwoActions",static_cast<cocos2d::Spawn*(*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Spawn::createWithTwoActions));
}
void RegisterLuaCoreRotateToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::RotateTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("RotateTo",false);
ns["RotateTo"] = mt;
lua["RotateTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::clone));
mt.set_function("reverse",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::RotateTo::*)(cocos2d::Node*)>(&cocos2d::RotateTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::RotateTo::*)(float)>(&cocos2d::RotateTo::update));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::RotateTo*(*)(float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::create)));
}
void RegisterLuaCoreRotateByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::RotateBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("RotateBy",false);
ns["RotateBy"] = mt;
lua["RotateBy"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::clone));
mt.set_function("reverse",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::RotateBy::*)(cocos2d::Node*)>(&cocos2d::RotateBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::RotateBy::*)(float)>(&cocos2d::RotateBy::update));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::RotateBy*(*)(float,float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::create)));
}
void RegisterLuaCoreMoveByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("MoveBy",false);
ns["MoveBy"] = mt;
lua["MoveBy"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::clone));
mt.set_function("reverse",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::MoveBy::*)(cocos2d::Node*)>(&cocos2d::MoveBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::MoveBy::*)(float)>(&cocos2d::MoveBy::update));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::create),static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::create)));
}
void RegisterLuaCoreMoveToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::MoveTo,cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("MoveTo",false);
ns["MoveTo"] = mt;
lua["MoveTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::clone));
mt.set_function("reverse",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::MoveTo::*)(cocos2d::Node*)>(&cocos2d::MoveTo::startWithTarget));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::create),static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::create)));
}
void RegisterLuaCoreSkewToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("SkewTo",false);
ns["SkewTo"] = mt;
lua["SkewTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::clone));
mt.set_function("reverse",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::SkewTo::*)(cocos2d::Node*)>(&cocos2d::SkewTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::SkewTo::*)(float)>(&cocos2d::SkewTo::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SkewTo*(*)(float,float,float)>(&cocos2d::SkewTo::create));
}
void RegisterLuaCoreSkewByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::SkewBy,cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("SkewBy",false);
ns["SkewBy"] = mt;
lua["SkewBy"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::SkewBy::*)(cocos2d::Node*)>(&cocos2d::SkewBy::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::clone));
mt.set_function("reverse",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SkewBy*(*)(float,float,float)>(&cocos2d::SkewBy::create));
}
