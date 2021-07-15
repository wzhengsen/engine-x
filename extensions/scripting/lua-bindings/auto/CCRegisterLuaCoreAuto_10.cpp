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
}
