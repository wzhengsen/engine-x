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
void RegisterLuaCoreEaseElasticInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseElasticIn).name()] = sol::usertype_traits<cocos2d::EaseElasticIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseElasticIn>("deprecated.cocos2d::EaseElasticIn");
dep[sol::base_classes]=sol::bases<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseElasticIn*>::metatable(),sol::usertype_traits<cocos2d::EaseElastic*>::metatable());
lua["cc"]["EaseElasticIn"]=mt;
mt["__new__"]=sol::overload([](cocos2d::ActionInterval* arg0,float arg1){return cocos2d::EaseElasticIn::create(arg0,arg1);},[](cocos2d::ActionInterval* arg0){return cocos2d::EaseElasticIn::create(arg0);});
}
void RegisterLuaCoreEaseElasticOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseElasticOut).name()] = sol::usertype_traits<cocos2d::EaseElasticOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseElasticOut>("deprecated.cocos2d::EaseElasticOut");
dep[sol::base_classes]=sol::bases<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseElasticOut*>::metatable(),sol::usertype_traits<cocos2d::EaseElastic*>::metatable());
lua["cc"]["EaseElasticOut"]=mt;
mt["__new__"]=sol::overload([](cocos2d::ActionInterval* arg0,float arg1){return cocos2d::EaseElasticOut::create(arg0,arg1);},[](cocos2d::ActionInterval* arg0){return cocos2d::EaseElasticOut::create(arg0);});
}
void RegisterLuaCoreEaseElasticInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseElasticInOut).name()] = sol::usertype_traits<cocos2d::EaseElasticInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseElasticInOut>("deprecated.cocos2d::EaseElasticInOut");
dep[sol::base_classes]=sol::bases<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseElasticInOut*>::metatable(),sol::usertype_traits<cocos2d::EaseElastic*>::metatable());
lua["cc"]["EaseElasticInOut"]=mt;
mt["__new__"]=sol::overload([](cocos2d::ActionInterval* arg0,float arg1){return cocos2d::EaseElasticInOut::create(arg0,arg1);},[](cocos2d::ActionInterval* arg0){return cocos2d::EaseElasticInOut::create(arg0);});
}
void RegisterLuaCoreEaseBezierActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBezierAction).name()] = sol::usertype_traits<cocos2d::EaseBezierAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBezierAction>("deprecated.cocos2d::EaseBezierAction");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBezierAction*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBezierAction"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBezierAction*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBezierAction::create);
mt["SetBezierParamer"]=static_cast<void(cocos2d::EaseBezierAction::*)(float,float,float,float)>(&cocos2d::EaseBezierAction::setBezierParamer);
}
void RegisterLuaCoreActionInstantAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionInstant).name()] = sol::usertype_traits<cocos2d::ActionInstant*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionInstant>("deprecated.cocos2d::ActionInstant");
dep[sol::base_classes]=sol::bases<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionInstant*>::metatable(),sol::usertype_traits<cocos2d::FiniteTimeAction*>::metatable());
lua["cc"]["ActionInstant"]=mt;
mt["__new__"] = [](){return nullptr;};
}
void RegisterLuaCoreShowAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Show).name()] = sol::usertype_traits<cocos2d::Show*>::metatable();
auto dep=lua.new_usertype<cocos2d::Show>("deprecated.cocos2d::Show");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Show*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["Show"]=mt;
mt["__new__"]=static_cast<cocos2d::Show*(*)()>(&cocos2d::Show::create);
}
void RegisterLuaCoreHideAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Hide).name()] = sol::usertype_traits<cocos2d::Hide*>::metatable();
auto dep=lua.new_usertype<cocos2d::Hide>("deprecated.cocos2d::Hide");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Hide*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["Hide"]=mt;
mt["__new__"]=static_cast<cocos2d::Hide*(*)()>(&cocos2d::Hide::create);
}
void RegisterLuaCoreToggleVisibilityAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ToggleVisibility).name()] = sol::usertype_traits<cocos2d::ToggleVisibility*>::metatable();
auto dep=lua.new_usertype<cocos2d::ToggleVisibility>("deprecated.cocos2d::ToggleVisibility");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ToggleVisibility*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["ToggleVisibility"]=mt;
mt["__new__"]=static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create);
}
void RegisterLuaCoreRemoveSelfAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RemoveSelf).name()] = sol::usertype_traits<cocos2d::RemoveSelf*>::metatable();
auto dep=lua.new_usertype<cocos2d::RemoveSelf>("deprecated.cocos2d::RemoveSelf");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RemoveSelf*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["RemoveSelf"]=mt;
mt["__new__"]=sol::overload([](bool arg0){return cocos2d::RemoveSelf::create(arg0);},[](){return cocos2d::RemoveSelf::create();});
}
void RegisterLuaCoreFlipXAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FlipX).name()] = sol::usertype_traits<cocos2d::FlipX*>::metatable();
auto dep=lua.new_usertype<cocos2d::FlipX>("deprecated.cocos2d::FlipX");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FlipX*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["FlipX"]=mt;
mt["__new__"]=static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create);
}
}
