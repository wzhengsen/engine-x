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
void RegisterLuaCoreRotateByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RotateBy>("cc","RotateBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::RotateBy*(*)(float,float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::create)));
mt.set_function("Clone",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::RotateBy::*)(cocos2d::Node*)>(&cocos2d::RotateBy::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::RotateBy::*)(float)>(&cocos2d::RotateBy::update));
}
void RegisterLuaCoreMoveByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MoveBy>("cc","MoveBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::create),static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::create)));
mt.set_function("Clone",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::MoveBy::*)(cocos2d::Node*)>(&cocos2d::MoveBy::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::MoveBy::*)(float)>(&cocos2d::MoveBy::update));
}
void RegisterLuaCoreMoveToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MoveTo>("cc","MoveTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::create),static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::create)));
mt.set_function("Clone",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::MoveTo::*)(cocos2d::Node*)>(&cocos2d::MoveTo::startWithTarget));
}
void RegisterLuaCoreSkewToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SkewTo>("cc","SkewTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SkewTo*(*)(float,float,float)>(&cocos2d::SkewTo::create));
mt.set_function("Clone",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::SkewTo::*)(cocos2d::Node*)>(&cocos2d::SkewTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::SkewTo::*)(float)>(&cocos2d::SkewTo::update));
}
void RegisterLuaCoreSkewByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SkewBy>("cc","SkewBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SkewBy*(*)(float,float,float)>(&cocos2d::SkewBy::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::SkewBy::*)(cocos2d::Node*)>(&cocos2d::SkewBy::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::reverse));
}
void RegisterLuaCoreJumpByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpBy>("cc","JumpBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpBy*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::create));
mt.set_function("Clone",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::JumpBy::*)(cocos2d::Node*)>(&cocos2d::JumpBy::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::JumpBy::*)(float)>(&cocos2d::JumpBy::update));
}
void RegisterLuaCoreJumpToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpTo>("cc","JumpTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpTo*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::JumpTo::*)(cocos2d::Node*)>(&cocos2d::JumpTo::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::reverse));
}
void RegisterLuaCoreBezierByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BezierBy>("cc","BezierBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::BezierBy*(*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierBy::create));
mt.set_function("Clone",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::BezierBy::*)(cocos2d::Node*)>(&cocos2d::BezierBy::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::BezierBy::*)(float)>(&cocos2d::BezierBy::update));
}
void RegisterLuaCoreBezierToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BezierTo>("cc","BezierTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::BezierTo*(*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierTo::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::BezierTo::*)(cocos2d::Node*)>(&cocos2d::BezierTo::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::reverse));
}
void RegisterLuaCoreScaleToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ScaleTo>("cc","ScaleTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ScaleTo*(*)(float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float,float,float)>(&cocos2d::ScaleTo::create)));
mt.set_function("Clone",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ScaleTo::*)(cocos2d::Node*)>(&cocos2d::ScaleTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::ScaleTo::*)(float)>(&cocos2d::ScaleTo::update));
}
