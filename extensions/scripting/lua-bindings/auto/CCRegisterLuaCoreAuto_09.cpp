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
void RegisterLuaCoreEaseRateActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseRateAction).name()] = sol::usertype_traits<cocos2d::EaseRateAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseRateAction>("deprecated.cocos2d::EaseRateAction");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseRateAction*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseRateAction"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseRateAction*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::create);
mt["SetRate"]=static_cast<void(cocos2d::EaseRateAction::*)(float)>(&cocos2d::EaseRateAction::setRate);
mt["set"]["Rate"]=mt["SetRate"];
mt["GetRate"]=static_cast<float(cocos2d::EaseRateAction::*)()const>(&cocos2d::EaseRateAction::getRate);
mt["get"]["Rate"]=mt["GetRate"];
}
void RegisterLuaCoreEaseExponentialInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseExponentialIn).name()] = sol::usertype_traits<cocos2d::EaseExponentialIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseExponentialIn>("deprecated.cocos2d::EaseExponentialIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseExponentialIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseExponentialIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseExponentialIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialIn::create);
}
void RegisterLuaCoreEaseExponentialOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseExponentialOut).name()] = sol::usertype_traits<cocos2d::EaseExponentialOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseExponentialOut>("deprecated.cocos2d::EaseExponentialOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseExponentialOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseExponentialOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseExponentialOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialOut::create);
}
void RegisterLuaCoreEaseExponentialInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseExponentialInOut).name()] = sol::usertype_traits<cocos2d::EaseExponentialInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseExponentialInOut>("deprecated.cocos2d::EaseExponentialInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseExponentialInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseExponentialInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseExponentialInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialInOut::create);
}
void RegisterLuaCoreEaseSineInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseSineIn).name()] = sol::usertype_traits<cocos2d::EaseSineIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseSineIn>("deprecated.cocos2d::EaseSineIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseSineIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseSineIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseSineIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineIn::create);
}
void RegisterLuaCoreEaseSineOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseSineOut).name()] = sol::usertype_traits<cocos2d::EaseSineOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseSineOut>("deprecated.cocos2d::EaseSineOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseSineOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseSineOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseSineOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineOut::create);
}
void RegisterLuaCoreEaseSineInOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseSineInOut).name()] = sol::usertype_traits<cocos2d::EaseSineInOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseSineInOut>("deprecated.cocos2d::EaseSineInOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseSineInOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseSineInOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseSineInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineInOut::create);
}
void RegisterLuaCoreEaseBounceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBounce).name()] = sol::usertype_traits<cocos2d::EaseBounce*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBounce>("deprecated.cocos2d::EaseBounce");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBounce*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBounce"]=mt;
mt["__new__"] = [](){return nullptr;};
}
void RegisterLuaCoreEaseBounceInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBounceIn).name()] = sol::usertype_traits<cocos2d::EaseBounceIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBounceIn>("deprecated.cocos2d::EaseBounceIn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBounceIn*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBounceIn"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBounceIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceIn::create);
}
void RegisterLuaCoreEaseBounceOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EaseBounceOut).name()] = sol::usertype_traits<cocos2d::EaseBounceOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::EaseBounceOut>("deprecated.cocos2d::EaseBounceOut");
dep[sol::base_classes]=sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EaseBounceOut*>::metatable(),sol::usertype_traits<cocos2d::ActionEase*>::metatable());
lua["cc"]["EaseBounceOut"]=mt;
mt["__new__"]=static_cast<cocos2d::EaseBounceOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceOut::create);
}
