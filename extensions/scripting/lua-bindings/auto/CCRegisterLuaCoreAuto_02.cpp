#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreSpawnAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Spawn,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Spawn");
mt.set_function("clone",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::clone));
mt.set_function("reverse",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Spawn::*)(cocos2d::Node*)>(&cocos2d::Spawn::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Spawn::*)()>(&cocos2d::Spawn::stop));
mt.set_function("update",static_cast<void(cocos2d::Spawn::*)(float)>(&cocos2d::Spawn::update));
mt.set_function("initWithTwoActions",static_cast<bool(cocos2d::Spawn::*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Spawn::initWithTwoActions));
mt.set_function("init",static_cast<bool(cocos2d::Spawn::*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Spawn::init));
}
void RegisterLuaCoreRotateToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RotateTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RotateTo");
mt.set_function("clone",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::clone));
mt.set_function("reverse",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::RotateTo::*)(cocos2d::Node*)>(&cocos2d::RotateTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::RotateTo::*)(float)>(&cocos2d::RotateTo::update));
mt.set_function("initWithDuration",sol::overload(static_cast<bool(cocos2d::RotateTo::*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::initWithDuration),static_cast<bool(cocos2d::RotateTo::*)(float,float,float)>(&cocos2d::RotateTo::initWithDuration)));
mt.set_function("new",sol::overload(static_cast<cocos2d::RotateTo*(*)(float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::create)));
}
void RegisterLuaCoreRotateByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RotateBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RotateBy");
mt.set_function("clone",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::clone));
mt.set_function("reverse",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::RotateBy::*)(cocos2d::Node*)>(&cocos2d::RotateBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::RotateBy::*)(float)>(&cocos2d::RotateBy::update));
mt.set_function("initWithDuration",sol::overload(static_cast<bool(cocos2d::RotateBy::*)(float,float,float)>(&cocos2d::RotateBy::initWithDuration),static_cast<bool(cocos2d::RotateBy::*)(float,float)>(&cocos2d::RotateBy::initWithDuration),static_cast<bool(cocos2d::RotateBy::*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::initWithDuration)));
mt.set_function("new",sol::overload(static_cast<cocos2d::RotateBy*(*)(float,float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::create)));
}
void RegisterLuaCoreMoveByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","MoveBy");
mt.set_function("clone",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::clone));
mt.set_function("reverse",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::MoveBy::*)(cocos2d::Node*)>(&cocos2d::MoveBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::MoveBy::*)(float)>(&cocos2d::MoveBy::update));
mt.set_function("initWithDuration",sol::overload(static_cast<bool(cocos2d::MoveBy::*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::initWithDuration),static_cast<bool(cocos2d::MoveBy::*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::initWithDuration)));
mt.set_function("new",sol::overload(static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::create),static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::create)));
}
void RegisterLuaCoreMoveToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MoveTo,cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","MoveTo");
mt.set_function("clone",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::clone));
mt.set_function("reverse",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::MoveTo::*)(cocos2d::Node*)>(&cocos2d::MoveTo::startWithTarget));
mt.set_function("initWithDuration",sol::overload(static_cast<bool(cocos2d::MoveTo::*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::initWithDuration),static_cast<bool(cocos2d::MoveTo::*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::initWithDuration)));
mt.set_function("new",sol::overload(static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::create),static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::create)));
}
void RegisterLuaCoreSkewToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SkewTo");
mt.set_function("clone",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::clone));
mt.set_function("reverse",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::SkewTo::*)(cocos2d::Node*)>(&cocos2d::SkewTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::SkewTo::*)(float)>(&cocos2d::SkewTo::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::SkewTo::*)(float,float,float)>(&cocos2d::SkewTo::initWithDuration));
mt.set_function("new",static_cast<cocos2d::SkewTo*(*)(float,float,float)>(&cocos2d::SkewTo::create));
}
void RegisterLuaCoreSkewByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SkewBy,cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SkewBy");
mt.set_function("startWithTarget",static_cast<void(cocos2d::SkewBy::*)(cocos2d::Node*)>(&cocos2d::SkewBy::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::clone));
mt.set_function("reverse",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::reverse));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::SkewBy::*)(float,float,float)>(&cocos2d::SkewBy::initWithDuration));
mt.set_function("new",static_cast<cocos2d::SkewBy*(*)(float,float,float)>(&cocos2d::SkewBy::create));
}
void RegisterLuaCoreJumpByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpBy");
mt.set_function("clone",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::clone));
mt.set_function("reverse",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::JumpBy::*)(cocos2d::Node*)>(&cocos2d::JumpBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::JumpBy::*)(float)>(&cocos2d::JumpBy::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::JumpBy::*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::initWithDuration));
mt.set_function("new",static_cast<cocos2d::JumpBy*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::create));
}
void RegisterLuaCoreJumpToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpTo,cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpTo");
mt.set_function("startWithTarget",static_cast<void(cocos2d::JumpTo::*)(cocos2d::Node*)>(&cocos2d::JumpTo::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::clone));
mt.set_function("reverse",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::reverse));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::JumpTo::*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::initWithDuration));
mt.set_function("new",static_cast<cocos2d::JumpTo*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::create));
}
void RegisterLuaCoreBezierByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","BezierBy");
mt.set_function("clone",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::clone));
mt.set_function("reverse",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::BezierBy::*)(cocos2d::Node*)>(&cocos2d::BezierBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::BezierBy::*)(float)>(&cocos2d::BezierBy::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::BezierBy::*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierBy::initWithDuration));
}
void RegisterLuaCoreBezierToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BezierTo,cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","BezierTo");
mt.set_function("startWithTarget",static_cast<void(cocos2d::BezierTo::*)(cocos2d::Node*)>(&cocos2d::BezierTo::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::clone));
mt.set_function("reverse",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::reverse));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::BezierTo::*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierTo::initWithDuration));
}
void RegisterLuaCoreScaleToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ScaleTo");
mt.set_function("clone",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::clone));
mt.set_function("reverse",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ScaleTo::*)(cocos2d::Node*)>(&cocos2d::ScaleTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ScaleTo::*)(float)>(&cocos2d::ScaleTo::update));
mt.set_function("initWithDuration",sol::overload(static_cast<bool(cocos2d::ScaleTo::*)(float,float,float)>(&cocos2d::ScaleTo::initWithDuration),static_cast<bool(cocos2d::ScaleTo::*)(float,float)>(&cocos2d::ScaleTo::initWithDuration),static_cast<bool(cocos2d::ScaleTo::*)(float,float,float,float)>(&cocos2d::ScaleTo::initWithDuration)));
mt.set_function("new",sol::overload(static_cast<cocos2d::ScaleTo*(*)(float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float,float,float)>(&cocos2d::ScaleTo::create)));
}
void RegisterLuaCoreScaleByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ScaleBy,cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ScaleBy");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ScaleBy::*)(cocos2d::Node*)>(&cocos2d::ScaleBy::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::clone));
mt.set_function("reverse",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::reverse));
mt.set_function("new",sol::overload(static_cast<cocos2d::ScaleBy*(*)(float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float,float,float)>(&cocos2d::ScaleBy::create)));
}
void RegisterLuaCoreBlinkAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Blink,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Blink");
mt.set_function("clone",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::clone));
mt.set_function("reverse",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::reverse));
mt.set_function("update",static_cast<void(cocos2d::Blink::*)(float)>(&cocos2d::Blink::update));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Blink::*)(cocos2d::Node*)>(&cocos2d::Blink::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Blink::*)()>(&cocos2d::Blink::stop));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Blink::*)(float,int)>(&cocos2d::Blink::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Blink*(*)(float,int)>(&cocos2d::Blink::create));
}
void RegisterLuaCoreFadeToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeTo");
mt.set_function("clone",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::clone));
mt.set_function("reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::FadeTo::*)(cocos2d::Node*)>(&cocos2d::FadeTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::FadeTo::*)(float)>(&cocos2d::FadeTo::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::FadeTo::*)(float,uint8_t)>(&cocos2d::FadeTo::initWithDuration));
mt.set_function("new",static_cast<cocos2d::FadeTo*(*)(float,uint8_t)>(&cocos2d::FadeTo::create));
}
