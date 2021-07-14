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
void RegisterLuaCoreEaseBounceInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBounceInOut).name()] = sol::usertype_traits<cocos2d::EaseBounceInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBounceInOut>("deprecated.cocos2d::EaseBounceInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBounceInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBounceInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBounceInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceInOut::create);
}
void RegisterLuaCoreEaseBackInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBackIn).name()] = sol::usertype_traits<cocos2d::EaseBackIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBackIn>("deprecated.cocos2d::EaseBackIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBackIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBackIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBackIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackIn::create);
}
void RegisterLuaCoreEaseBackOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBackOut).name()] = sol::usertype_traits<cocos2d::EaseBackOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBackOut>("deprecated.cocos2d::EaseBackOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBackOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBackOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBackOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackOut::create);
}
void RegisterLuaCoreEaseBackInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBackInOut).name()] = sol::usertype_traits<cocos2d::EaseBackInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBackInOut>("deprecated.cocos2d::EaseBackInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBackInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBackInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBackInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackInOut::create);
}
void RegisterLuaCoreEaseQuadraticActionInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuadraticActionIn).name()] = sol::usertype_traits<cocos2d::EaseQuadraticActionIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuadraticActionIn>("deprecated.cocos2d::EaseQuadraticActionIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuadraticActionIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuadraticActionIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuadraticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionIn::create);
}
void RegisterLuaCoreEaseQuadraticActionOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuadraticActionOut).name()] = sol::usertype_traits<cocos2d::EaseQuadraticActionOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuadraticActionOut>("deprecated.cocos2d::EaseQuadraticActionOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuadraticActionOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuadraticActionOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuadraticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionOut::create);
}
void RegisterLuaCoreEaseQuadraticActionInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuadraticActionInOut).name()] = sol::usertype_traits<cocos2d::EaseQuadraticActionInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuadraticActionInOut>("deprecated.cocos2d::EaseQuadraticActionInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuadraticActionInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuadraticActionInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuadraticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionInOut::create);
}
void RegisterLuaCoreEaseQuarticActionInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuarticActionIn).name()] = sol::usertype_traits<cocos2d::EaseQuarticActionIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuarticActionIn>("deprecated.cocos2d::EaseQuarticActionIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuarticActionIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuarticActionIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuarticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionIn::create);
}
void RegisterLuaCoreEaseQuarticActionOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuarticActionOut).name()] = sol::usertype_traits<cocos2d::EaseQuarticActionOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuarticActionOut>("deprecated.cocos2d::EaseQuarticActionOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuarticActionOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuarticActionOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuarticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionOut::create);
}
void RegisterLuaCoreEaseQuarticActionInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseQuarticActionInOut).name()] = sol::usertype_traits<cocos2d::EaseQuarticActionInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseQuarticActionInOut>("deprecated.cocos2d::EaseQuarticActionInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseQuarticActionInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseQuarticActionInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseQuarticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionInOut::create);
}
}
