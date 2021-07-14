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
void RegisterLuaCoreEaseQuinticActionInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuinticActionIn).name()] = sol::usertype_traits<cocos2d::EaseQuinticActionIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuinticActionIn>("deprecated.cocos2d::EaseQuinticActionIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuinticActionIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuinticActionIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuinticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionIn::create);
}
void RegisterLuaCoreEaseQuinticActionOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuinticActionOut).name()] = sol::usertype_traits<cocos2d::EaseQuinticActionOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuinticActionOut>("deprecated.cocos2d::EaseQuinticActionOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuinticActionOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuinticActionOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuinticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionOut::create);
}
void RegisterLuaCoreEaseQuinticActionInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuinticActionInOut).name()] = sol::usertype_traits<cocos2d::EaseQuinticActionInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuinticActionInOut>("deprecated.cocos2d::EaseQuinticActionInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuinticActionInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuinticActionInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuinticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionInOut::create);
}
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
}
