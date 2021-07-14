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
void RegisterLuaCoreRotateByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RotateBy).name()] = sol::usertype_traits<cocos2d::RotateBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::RotateBy>("deprecated.cocos2d::RotateBy");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RotateBy*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["RotateBy"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::RotateBy*(*)(float,float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,float)>(&cocos2d::RotateBy::create));
}
void RegisterLuaCoreMoveByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::MoveBy).name()] = sol::usertype_traits<cocos2d::MoveBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::MoveBy>("deprecated.cocos2d::MoveBy");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::MoveBy*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["MoveBy"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::create),static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::create));
}
void RegisterLuaCoreMoveToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::MoveTo).name()] = sol::usertype_traits<cocos2d::MoveTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::MoveTo>("deprecated.cocos2d::MoveTo");
dep[sol::base_classes]=sol::bases<cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::MoveTo*>::metatable(),sol::usertype_traits<cocos2d::MoveBy*>::metatable());
lua["cc"]["MoveTo"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::create),static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::create));
}
void RegisterLuaCoreSkewToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SkewTo).name()] = sol::usertype_traits<cocos2d::SkewTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::SkewTo>("deprecated.cocos2d::SkewTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SkewTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["SkewTo"]=mt;
mt["__new__"]=static_cast<cocos2d::SkewTo*(*)(float,float,float)>(&cocos2d::SkewTo::create);
}
void RegisterLuaCoreSkewByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SkewBy).name()] = sol::usertype_traits<cocos2d::SkewBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::SkewBy>("deprecated.cocos2d::SkewBy");
dep[sol::base_classes]=sol::bases<cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SkewBy*>::metatable(),sol::usertype_traits<cocos2d::SkewTo*>::metatable());
lua["cc"]["SkewBy"]=mt;
mt["__new__"]=static_cast<cocos2d::SkewBy*(*)(float,float,float)>(&cocos2d::SkewBy::create);
}
void RegisterLuaCoreJumpByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::JumpBy).name()] = sol::usertype_traits<cocos2d::JumpBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::JumpBy>("deprecated.cocos2d::JumpBy");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::JumpBy*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["JumpBy"]=mt;
mt["__new__"]=static_cast<cocos2d::JumpBy*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::create);
}
void RegisterLuaCoreJumpToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::JumpTo).name()] = sol::usertype_traits<cocos2d::JumpTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::JumpTo>("deprecated.cocos2d::JumpTo");
dep[sol::base_classes]=sol::bases<cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::JumpTo*>::metatable(),sol::usertype_traits<cocos2d::JumpBy*>::metatable());
lua["cc"]["JumpTo"]=mt;
mt["__new__"]=static_cast<cocos2d::JumpTo*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::create);
}
void RegisterLuaCoreBezierByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::BezierBy).name()] = sol::usertype_traits<cocos2d::BezierBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::BezierBy>("deprecated.cocos2d::BezierBy");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::BezierBy*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["BezierBy"]=mt;
mt["__new__"]=static_cast<cocos2d::BezierBy*(*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierBy::create);
}
void RegisterLuaCoreBezierToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::BezierTo).name()] = sol::usertype_traits<cocos2d::BezierTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::BezierTo>("deprecated.cocos2d::BezierTo");
dep[sol::base_classes]=sol::bases<cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::BezierTo*>::metatable(),sol::usertype_traits<cocos2d::BezierBy*>::metatable());
lua["cc"]["BezierTo"]=mt;
mt["__new__"]=static_cast<cocos2d::BezierTo*(*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierTo::create);
}
void RegisterLuaCoreScaleToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ScaleTo).name()] = sol::usertype_traits<cocos2d::ScaleTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::ScaleTo>("deprecated.cocos2d::ScaleTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ScaleTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["ScaleTo"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ScaleTo*(*)(float,float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float)>(&cocos2d::ScaleTo::create));
}
}
