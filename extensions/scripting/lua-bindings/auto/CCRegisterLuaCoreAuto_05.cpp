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
void RegisterLuaCoreScaleByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ScaleBy>("cc","ScaleBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ScaleBy*(*)(float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float,float,float)>(&cocos2d::ScaleBy::create)));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ScaleBy::*)(cocos2d::Node*)>(&cocos2d::ScaleBy::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::reverse));
}
void RegisterLuaCoreBlinkAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Blink>("cc","Blink",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Blink*(*)(float,int)>(&cocos2d::Blink::create));
mt.set_function("Clone",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::clone));
mt.set_function("Reverse",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::reverse));
mt.set_function("Update",static_cast<void(cocos2d::Blink::*)(float)>(&cocos2d::Blink::update));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Blink::*)(cocos2d::Node*)>(&cocos2d::Blink::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Blink::*)()>(&cocos2d::Blink::stop));
}
void RegisterLuaCoreFadeToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeTo>("cc","FadeTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeTo*(*)(float,uint8_t)>(&cocos2d::FadeTo::create));
mt.set_function("Clone",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::FadeTo::*)(cocos2d::Node*)>(&cocos2d::FadeTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::FadeTo::*)(float)>(&cocos2d::FadeTo::update));
}
void RegisterLuaCoreFadeInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeIn>("cc","FadeIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeIn*(*)(float)>(&cocos2d::FadeIn::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::FadeIn::*)(cocos2d::Node*)>(&cocos2d::FadeIn::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::FadeIn*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::clone));
mt.set_function("Reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::reverse));
mt.set_function("SetReverseAction",static_cast<void(cocos2d::FadeIn::*)(cocos2d::FadeTo*)>(&cocos2d::FadeIn::setReverseAction));
}
void RegisterLuaCoreFadeOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOut>("cc","FadeOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOut*(*)(float)>(&cocos2d::FadeOut::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::FadeOut::*)(cocos2d::Node*)>(&cocos2d::FadeOut::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::FadeOut*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::clone));
mt.set_function("Reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::reverse));
mt.set_function("SetReverseAction",static_cast<void(cocos2d::FadeOut::*)(cocos2d::FadeTo*)>(&cocos2d::FadeOut::setReverseAction));
}
void RegisterLuaCoreTintToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TintTo>("cc","TintTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create)));
mt.set_function("Clone",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::TintTo::*)(cocos2d::Node*)>(&cocos2d::TintTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::TintTo::*)(float)>(&cocos2d::TintTo::update));
}
void RegisterLuaCoreTintByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TintBy>("cc","TintBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create));
mt.set_function("Clone",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::TintBy::*)(cocos2d::Node*)>(&cocos2d::TintBy::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::TintBy::*)(float)>(&cocos2d::TintBy::update));
}
void RegisterLuaCoreDelayTimeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DelayTime>("cc","DelayTime",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create));
mt.set_function("Update",static_cast<void(cocos2d::DelayTime::*)(float)>(&cocos2d::DelayTime::update));
mt.set_function("Reverse",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::reverse));
mt.set_function("Clone",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::clone));
}
void RegisterLuaCoreAnimateAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate>("cc","Animate",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create));
mt.set_function("SetAnimation",static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation));
mt.set_function("GetAnimation",sol::overload(static_cast<const cocos2d::Animation*(cocos2d::Animate::*)()const>(&cocos2d::Animate::getAnimation),static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation)));
mt.set_function("GetCurrentFrameIndex",static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex));
mt.set_function("Clone",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::clone));
mt.set_function("Reverse",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Animate::*)(cocos2d::Node*)>(&cocos2d::Animate::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Animate::*)()>(&cocos2d::Animate::stop));
mt.set_function("Update",static_cast<void(cocos2d::Animate::*)(float)>(&cocos2d::Animate::update));
}
void RegisterLuaCoreTargetedActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TargetedAction>("cc","TargetedAction",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create));
mt.set_function("SetForcedTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget));
mt.set_function("GetForcedTarget",sol::overload(static_cast<const cocos2d::Node*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::getForcedTarget),static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget)));
mt.set_function("Clone",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::clone));
mt.set_function("Reverse",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::stop));
mt.set_function("Update",static_cast<void(cocos2d::TargetedAction::*)(float)>(&cocos2d::TargetedAction::update));
}
