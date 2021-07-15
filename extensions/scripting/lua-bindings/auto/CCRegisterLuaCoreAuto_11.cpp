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
void RegisterLuaCoreEaseCircleActionInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseCircleActionIn).name()] = sol::usertype_traits<cocos2d::EaseCircleActionIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseCircleActionIn>("deprecated.cocos2d::EaseCircleActionIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseCircleActionIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseCircleActionIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseCircleActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionIn::create);
}
void RegisterLuaCoreEaseCircleActionOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseCircleActionOut).name()] = sol::usertype_traits<cocos2d::EaseCircleActionOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseCircleActionOut>("deprecated.cocos2d::EaseCircleActionOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseCircleActionOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseCircleActionOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseCircleActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionOut::create);
}
void RegisterLuaCoreEaseCircleActionInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseCircleActionInOut).name()] = sol::usertype_traits<cocos2d::EaseCircleActionInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseCircleActionInOut>("deprecated.cocos2d::EaseCircleActionInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseCircleActionInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseCircleActionInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseCircleActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionInOut::create);
}
void RegisterLuaCoreEaseCubicActionInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseCubicActionIn).name()] = sol::usertype_traits<cocos2d::EaseCubicActionIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseCubicActionIn>("deprecated.cocos2d::EaseCubicActionIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseCubicActionIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseCubicActionIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseCubicActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionIn::create);
}
void RegisterLuaCoreEaseCubicActionOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseCubicActionOut).name()] = sol::usertype_traits<cocos2d::EaseCubicActionOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseCubicActionOut>("deprecated.cocos2d::EaseCubicActionOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseCubicActionOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseCubicActionOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseCubicActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionOut::create);
}
void RegisterLuaCoreEaseCubicActionInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseCubicActionInOut).name()] = sol::usertype_traits<cocos2d::EaseCubicActionInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseCubicActionInOut>("deprecated.cocos2d::EaseCubicActionInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseCubicActionInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseCubicActionInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseCubicActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionInOut::create);
}
void RegisterLuaCoreEaseInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseIn).name()] = sol::usertype_traits<cocos2d::EaseIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseIn>("deprecated.cocos2d::EaseIn");
dep[sol::base_classes]=sol::bases<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseIn*>::metatable(),sol::usertype_traits<cocos2d::EaseRateAction*>::metatable());
lua["cc"]["EaseIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseIn*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseIn::create);
}
void RegisterLuaCoreEaseOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseOut).name()] = sol::usertype_traits<cocos2d::EaseOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseOut>("deprecated.cocos2d::EaseOut");
dep[sol::base_classes]=sol::bases<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseOut*>::metatable(),sol::usertype_traits<cocos2d::EaseRateAction*>::metatable());
lua["cc"]["EaseOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseOut::create);
}
void RegisterLuaCoreEaseInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseInOut).name()] = sol::usertype_traits<cocos2d::EaseInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseInOut>("deprecated.cocos2d::EaseInOut");
dep[sol::base_classes]=sol::bases<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseInOut*>::metatable(),sol::usertype_traits<cocos2d::EaseRateAction*>::metatable());
lua["cc"]["EaseInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseInOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseInOut::create);
}
void RegisterLuaCoreEaseElasticAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseElastic).name()] = sol::usertype_traits<cocos2d::EaseElastic*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseElastic>("deprecated.cocos2d::EaseElastic");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseElastic*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseElastic"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetPeriod"]=static_cast<float(cocos2d::EaseElastic::*)()const>(&cocos2d::EaseElastic::getPeriod);
mt["get"]["Period"]=mt["GetPeriod"];
mt["SetPeriod"]=static_cast<void(cocos2d::EaseElastic::*)(float)>(&cocos2d::EaseElastic::setPeriod);
mt["set"]["Period"]=mt["SetPeriod"];
}
}
