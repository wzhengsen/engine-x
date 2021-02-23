#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreEaseCubicActionInOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseCubicActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCubicActionInOut");
mt.set_function("clone",static_cast<cocos2d::EaseCubicActionInOut*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseCubicActionInOut::*)(float)>(&cocos2d::EaseCubicActionInOut::update));
mt.set_function("reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseCubicActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionInOut::create));
}
void RegisterLuaCoreEaseInAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseIn,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseIn");
mt.set_function("clone",static_cast<cocos2d::EaseIn*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseIn::*)(float)>(&cocos2d::EaseIn::update));
mt.set_function("reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::reverse));
mt.set_function("new",static_cast<cocos2d::EaseIn*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseIn::create));
}
void RegisterLuaCoreEaseOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseOut,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseOut");
mt.set_function("clone",static_cast<cocos2d::EaseOut*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseOut::*)(float)>(&cocos2d::EaseOut::update));
mt.set_function("reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseOut::create));
}
void RegisterLuaCoreEaseInOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseInOut,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseInOut");
mt.set_function("clone",static_cast<cocos2d::EaseInOut*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseInOut::*)(float)>(&cocos2d::EaseInOut::update));
mt.set_function("reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::reverse));
mt.set_function("new",static_cast<cocos2d::EaseInOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseInOut::create));
}
void RegisterLuaCoreEaseElasticAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElastic");
mt.set_function("getPeriod",static_cast<float(cocos2d::EaseElastic::*)()const>(&cocos2d::EaseElastic::getPeriod));
mt.set_function("setPeriod",static_cast<void(cocos2d::EaseElastic::*)(float)>(&cocos2d::EaseElastic::setPeriod));
mt.set_function("initWithAction",sol::overload([](cocos2d::EaseElastic* obj,cocos2d::ActionInterval* arg0){return obj->initWithAction(arg0);},[](cocos2d::EaseElastic* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->initWithAction(arg0,arg1);}));
}
void RegisterLuaCoreEaseElasticInAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElasticIn,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElasticIn");
mt.set_function("clone",static_cast<cocos2d::EaseElasticIn*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseElasticIn::*)(float)>(&cocos2d::EaseElasticIn::update));
mt.set_function("reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::reverse));
mt.set_function("new",sol::overload([](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreEaseElasticOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElasticOut,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElasticOut");
mt.set_function("clone",static_cast<cocos2d::EaseElasticOut*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseElasticOut::*)(float)>(&cocos2d::EaseElasticOut::update));
mt.set_function("reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::reverse));
mt.set_function("new",sol::overload([](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreEaseElasticInOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseElasticInOut,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElasticInOut");
mt.set_function("clone",static_cast<cocos2d::EaseElasticInOut*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::clone));
mt.set_function("update",static_cast<void(cocos2d::EaseElasticInOut::*)(float)>(&cocos2d::EaseElasticInOut::update));
mt.set_function("reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::reverse));
mt.set_function("new",sol::overload([](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreEaseBezierActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseBezierAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBezierAction");
mt.set_function("update",static_cast<void(cocos2d::EaseBezierAction::*)(float)>(&cocos2d::EaseBezierAction::update));
mt.set_function("clone",static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::clone));
mt.set_function("reverse",static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::reverse));
mt.set_function("setBezierParamer",static_cast<void(cocos2d::EaseBezierAction::*)(float,float,float,float)>(&cocos2d::EaseBezierAction::setBezierParamer));
mt.set_function("new",static_cast<cocos2d::EaseBezierAction*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBezierAction::create));
}
void RegisterLuaCoreActionInstantAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionInstant");
mt.set_function("clone",static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::clone));
mt.set_function("reverse",static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionInstant::*)(cocos2d::Node*)>(&cocos2d::ActionInstant::startWithTarget));
mt.set_function("isDone",static_cast<bool(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::isDone));
mt.set_function("step",static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::step));
mt.set_function("update",static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::update));
}
void RegisterLuaCoreShowAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Show,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Show");
mt.set_function("update",static_cast<void(cocos2d::Show::*)(float)>(&cocos2d::Show::update));
mt.set_function("reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Show::*)()const>(&cocos2d::Show::reverse));
mt.set_function("clone",static_cast<cocos2d::Show*(cocos2d::Show::*)()const>(&cocos2d::Show::clone));
mt.set_function("new",static_cast<cocos2d::Show*(*)()>(&cocos2d::Show::create));
}
void RegisterLuaCoreHideAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Hide,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Hide");
mt.set_function("update",static_cast<void(cocos2d::Hide::*)(float)>(&cocos2d::Hide::update));
mt.set_function("reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Hide::*)()const>(&cocos2d::Hide::reverse));
mt.set_function("clone",static_cast<cocos2d::Hide*(cocos2d::Hide::*)()const>(&cocos2d::Hide::clone));
mt.set_function("new",static_cast<cocos2d::Hide*(*)()>(&cocos2d::Hide::create));
}
void RegisterLuaCoreToggleVisibilityAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ToggleVisibility,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ToggleVisibility");
mt.set_function("update",static_cast<void(cocos2d::ToggleVisibility::*)(float)>(&cocos2d::ToggleVisibility::update));
mt.set_function("reverse",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::reverse));
mt.set_function("clone",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::clone));
mt.set_function("new",static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create));
}
void RegisterLuaCoreRemoveSelfAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RemoveSelf,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RemoveSelf");
mt.set_function("update",static_cast<void(cocos2d::RemoveSelf::*)(float)>(&cocos2d::RemoveSelf::update));
mt.set_function("clone",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::clone));
mt.set_function("reverse",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::reverse));
mt.set_function("init",static_cast<bool(cocos2d::RemoveSelf::*)(bool)>(&cocos2d::RemoveSelf::init));
mt.set_function("new",sol::overload([](cocos2d::RemoveSelf* obj){return obj->create();},[](cocos2d::RemoveSelf* obj,bool arg0){return obj->create(arg0);}));
}
void RegisterLuaCoreFlipXAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipX,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipX");
mt.set_function("update",static_cast<void(cocos2d::FlipX::*)(float)>(&cocos2d::FlipX::update));
mt.set_function("reverse",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::reverse));
mt.set_function("clone",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::clone));
mt.set_function("initWithFlipX",static_cast<bool(cocos2d::FlipX::*)(bool)>(&cocos2d::FlipX::initWithFlipX));
mt.set_function("new",static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create));
}
