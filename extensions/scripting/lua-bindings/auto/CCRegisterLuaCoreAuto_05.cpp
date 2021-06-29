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
#include "network/CCConnection.h"
void RegisterLuaCoreScaleByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ScaleBy).name()] = sol::usertype_traits<cocos2d::ScaleBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::ScaleBy>("deprecated.cocos2d::ScaleBy");
dep[sol::base_classes]=sol::bases<cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ScaleBy*>::metatable(),sol::usertype_traits<cocos2d::ScaleTo*>::metatable());
lua["cc"]["ScaleBy"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ScaleBy*(*)(float,float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float)>(&cocos2d::ScaleBy::create));
}
void RegisterLuaCoreBlinkAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Blink).name()] = sol::usertype_traits<cocos2d::Blink*>::metatable();
auto dep=lua.new_usertype<cocos2d::Blink>("deprecated.cocos2d::Blink");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Blink*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["Blink"]=mt;
mt["__new__"]=static_cast<cocos2d::Blink*(*)(float,int)>(&cocos2d::Blink::create);
}
void RegisterLuaCoreFadeToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeTo).name()] = sol::usertype_traits<cocos2d::FadeTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeTo>("deprecated.cocos2d::FadeTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["FadeTo"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeTo*(*)(float,uint8_t)>(&cocos2d::FadeTo::create);
}
void RegisterLuaCoreFadeInAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeIn).name()] = sol::usertype_traits<cocos2d::FadeIn*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeIn>("deprecated.cocos2d::FadeIn");
dep[sol::base_classes]=sol::bases<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeIn*>::metatable(),sol::usertype_traits<cocos2d::FadeTo*>::metatable());
lua["cc"]["FadeIn"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeIn*(*)(float)>(&cocos2d::FadeIn::create);
mt["SetReverseAction"]=static_cast<void(cocos2d::FadeIn::*)(cocos2d::FadeTo*)>(&cocos2d::FadeIn::setReverseAction);
mt["set"]["ReverseAction"]=mt["SetReverseAction"];
}
void RegisterLuaCoreFadeOutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeOut).name()] = sol::usertype_traits<cocos2d::FadeOut*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeOut>("deprecated.cocos2d::FadeOut");
dep[sol::base_classes]=sol::bases<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeOut*>::metatable(),sol::usertype_traits<cocos2d::FadeTo*>::metatable());
lua["cc"]["FadeOut"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeOut*(*)(float)>(&cocos2d::FadeOut::create);
mt["SetReverseAction"]=static_cast<void(cocos2d::FadeOut::*)(cocos2d::FadeTo*)>(&cocos2d::FadeOut::setReverseAction);
mt["set"]["ReverseAction"]=mt["SetReverseAction"];
}
void RegisterLuaCoreTintToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TintTo).name()] = sol::usertype_traits<cocos2d::TintTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::TintTo>("deprecated.cocos2d::TintTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TintTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["TintTo"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create));
}
void RegisterLuaCoreTintByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TintBy).name()] = sol::usertype_traits<cocos2d::TintBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::TintBy>("deprecated.cocos2d::TintBy");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TintBy*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["TintBy"]=mt;
mt["__new__"]=static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create);
}
void RegisterLuaCoreDelayTimeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::DelayTime).name()] = sol::usertype_traits<cocos2d::DelayTime*>::metatable();
auto dep=lua.new_usertype<cocos2d::DelayTime>("deprecated.cocos2d::DelayTime");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::DelayTime*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["DelayTime"]=mt;
mt["__new__"]=static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create);
}
void RegisterLuaCoreAnimateAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Animate).name()] = sol::usertype_traits<cocos2d::Animate*>::metatable();
auto dep=lua.new_usertype<cocos2d::Animate>("deprecated.cocos2d::Animate");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Animate*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["Animate"]=mt;
mt["__new__"]=static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create);
mt["SetAnimation"]=static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation);
mt["set"]["Animation"]=mt["SetAnimation"];
mt["GetAnimation"]=static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation);
mt["get"]["Animation"]=mt["GetAnimation"];
mt["GetCurrentFrameIndex"]=static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex);
mt["get"]["CurrentFrameIndex"]=mt["GetCurrentFrameIndex"];
}
void RegisterLuaCoreTargetedActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TargetedAction).name()] = sol::usertype_traits<cocos2d::TargetedAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::TargetedAction>("deprecated.cocos2d::TargetedAction");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TargetedAction*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["TargetedAction"]=mt;
mt["__new__"]=static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create);
mt["SetForcedTarget"]=static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget);
mt["set"]["ForcedTarget"]=mt["SetForcedTarget"];
mt["GetForcedTarget"]=static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget);
mt["get"]["ForcedTarget"]=mt["GetForcedTarget"];
}
