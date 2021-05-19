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
void RegisterLuaCoreOrbitCameraAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::OrbitCamera>("cc","OrbitCamera",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create));
mt.set_function("SphericalRadius",static_cast<void(cocos2d::OrbitCamera::*)(float*,float*,float*)>(&cocos2d::OrbitCamera::sphericalRadius));
mt.set_function("Clone",static_cast<cocos2d::OrbitCamera*(cocos2d::OrbitCamera::*)()const>(&cocos2d::OrbitCamera::clone));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::OrbitCamera::*)(cocos2d::Node*)>(&cocos2d::OrbitCamera::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::OrbitCamera::*)(float)>(&cocos2d::OrbitCamera::update));
}
void RegisterLuaCorePointArrayAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PointArray>("cc","PointArray",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::PointArray*(*)(ssize_t)>(&cocos2d::PointArray::create));
mt.set_function("InitWithCapacity",static_cast<bool(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::initWithCapacity));
mt.set_function("AddControlPoint",static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&)>(&cocos2d::PointArray::addControlPoint));
mt.set_function("InsertControlPoint",static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::insertControlPoint));
mt.set_function("ReplaceControlPoint",static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::replaceControlPoint));
mt.set_function("GetControlPointAtIndex",static_cast<const cocos2d::Vec2&(cocos2d::PointArray::*)(ssize_t)const>(&cocos2d::PointArray::getControlPointAtIndex));
mt.set_function("RemoveControlPointAtIndex",static_cast<void(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::removeControlPointAtIndex));
mt.set_function("Count",static_cast<ssize_t(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::count));
mt.set_function("Reverse",static_cast<cocos2d::PointArray*(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::reverse));
mt.set_function("ReverseInline",static_cast<void(cocos2d::PointArray::*)()>(&cocos2d::PointArray::reverseInline));
mt.set_function("Clone",static_cast<cocos2d::PointArray*(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::clone));
mt.set_function("GetControlPoints",static_cast<const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::getControlPoints));
mt.set_function("SetControlPoints",static_cast<void(cocos2d::PointArray::*)(std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >)>(&cocos2d::PointArray::setControlPoints));
mt[sol::call_constructor]=sol::constructors<cocos2d::PointArray()>();
}
void RegisterLuaCoreCardinalSplineToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CardinalSplineTo>("cc","CardinalSplineTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CardinalSplineTo*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::create));
mt.set_function("InitWithDuration",static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration));
mt.set_function("UpdatePosition",static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition));
mt.set_function("GetPoints",static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints));
mt.set_function("SetPoints",static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::PointArray*)>(&cocos2d::CardinalSplineTo::setPoints));
mt.set_function("Clone",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::CardinalSplineTo::*)(float)>(&cocos2d::CardinalSplineTo::update));
mt[sol::call_constructor]=sol::constructors<cocos2d::CardinalSplineTo()>();
}
void RegisterLuaCoreCardinalSplineByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CardinalSplineBy>("cc","CardinalSplineBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CardinalSplineBy*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineBy::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::CardinalSplineBy::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineBy::startWithTarget));
mt.set_function("UpdatePosition",static_cast<void(cocos2d::CardinalSplineBy::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineBy::updatePosition));
mt.set_function("Clone",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::reverse));
mt[sol::call_constructor]=sol::constructors<cocos2d::CardinalSplineBy()>();
}
void RegisterLuaCoreCatmullRomToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CatmullRomTo>("cc","CatmullRomTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CatmullRomTo*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::create));
mt.set_function("InitWithDuration",static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration));
mt.set_function("Clone",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::reverse));
}
void RegisterLuaCoreCatmullRomByAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CatmullRomBy>("cc","CatmullRomBy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CatmullRomBy*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::create));
mt.set_function("InitWithDuration",static_cast<bool(cocos2d::CatmullRomBy::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::initWithDuration));
mt.set_function("Clone",static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::clone));
mt.set_function("Reverse",static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::reverse));
}
void RegisterLuaCoreActionEaseAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionEase>("cc","ActionEase",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::getInnerAction));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ActionEase::*)(cocos2d::Node*)>(&cocos2d::ActionEase::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::stop));
mt.set_function("Update",static_cast<void(cocos2d::ActionEase::*)(float)>(&cocos2d::ActionEase::update));
}
void RegisterLuaCoreEaseRateActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseRateAction>("cc","EaseRateAction",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseRateAction*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::create));
mt.set_function("SetRate",static_cast<void(cocos2d::EaseRateAction::*)(float)>(&cocos2d::EaseRateAction::setRate));
mt.set_function("GetRate",static_cast<float(cocos2d::EaseRateAction::*)()const>(&cocos2d::EaseRateAction::getRate));
}
void RegisterLuaCoreEaseExponentialInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseExponentialIn>("cc","EaseExponentialIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseExponentialIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialIn::create));
mt.set_function("Clone",static_cast<cocos2d::EaseExponentialIn*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseExponentialIn::*)(float)>(&cocos2d::EaseExponentialIn::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::reverse));
}
void RegisterLuaCoreEaseExponentialOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EaseExponentialOut>("cc","EaseExponentialOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EaseExponentialOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialOut::create));
mt.set_function("Clone",static_cast<cocos2d::EaseExponentialOut*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::clone));
mt.set_function("Update",static_cast<void(cocos2d::EaseExponentialOut::*)(float)>(&cocos2d::EaseExponentialOut::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::reverse));
}
