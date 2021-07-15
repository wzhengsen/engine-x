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
void RegisterLuaCoreOrbitCameraAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::OrbitCamera).name()] = sol::usertype_traits<cocos2d::OrbitCamera*>::metatable();
auto dep=lua.new_usertype<cocos2d::OrbitCamera>("deprecated.cocos2d::OrbitCamera");
dep[sol::base_classes]=sol::bases<cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::OrbitCamera*>::metatable(),sol::usertype_traits<cocos2d::ActionCamera*>::metatable());
lua["cc"]["OrbitCamera"]=mt;
mt["__new__"]=static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create);
mt["SphericalRadius"]=static_cast<void(cocos2d::OrbitCamera::*)(float*,float*,float*)>(&cocos2d::OrbitCamera::sphericalRadius);
}
void RegisterLuaCorePointArrayAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PointArray).name()] = sol::usertype_traits<cocos2d::PointArray*>::metatable();
auto dep=lua.new_usertype<cocos2d::PointArray>("deprecated.cocos2d::PointArray");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PointArray*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["PointArray"]=mt;
mt["__new__"]=static_cast<cocos2d::PointArray*(*)(ssize_t)>(&cocos2d::PointArray::create);
mt["InitWithCapacity"]=static_cast<bool(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::initWithCapacity);
mt["AddControlPoint"]=static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&)>(&cocos2d::PointArray::addControlPoint);
mt["InsertControlPoint"]=static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::insertControlPoint);
mt["ReplaceControlPoint"]=static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::replaceControlPoint);
mt["GetControlPointAtIndex"]=static_cast<const cocos2d::Vec2&(cocos2d::PointArray::*)(ssize_t)const>(&cocos2d::PointArray::getControlPointAtIndex);
mt["RemoveControlPointAtIndex"]=static_cast<void(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::removeControlPointAtIndex);
mt["Count"]=static_cast<ssize_t(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::count);
mt["Reverse"]=static_cast<cocos2d::PointArray*(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::reverse);
mt["ReverseInline"]=static_cast<void(cocos2d::PointArray::*)()>(&cocos2d::PointArray::reverseInline);
mt["GetControlPoints"]=static_cast<const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::getControlPoints);
mt["get"]["ControlPoints"]=mt["GetControlPoints"];
mt["SetControlPoints"]=static_cast<void(cocos2d::PointArray::*)(std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >)>(&cocos2d::PointArray::setControlPoints);
mt["set"]["ControlPoints"]=mt["SetControlPoints"];
}
void RegisterLuaCoreCardinalSplineToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CardinalSplineTo).name()] = sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::CardinalSplineTo>("deprecated.cocos2d::CardinalSplineTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["CardinalSplineTo"]=mt;
mt["__new__"]=static_cast<cocos2d::CardinalSplineTo*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration);
mt["UpdatePosition"]=static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition);
mt["GetPoints"]=static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints);
mt["get"]["Points"]=mt["GetPoints"];
mt["SetPoints"]=static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::PointArray*)>(&cocos2d::CardinalSplineTo::setPoints);
mt["set"]["Points"]=mt["SetPoints"];
}
void RegisterLuaCoreCardinalSplineByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CardinalSplineBy).name()] = sol::usertype_traits<cocos2d::CardinalSplineBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::CardinalSplineBy>("deprecated.cocos2d::CardinalSplineBy");
dep[sol::base_classes]=sol::bases<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CardinalSplineBy*>::metatable(),sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable());
lua["cc"]["CardinalSplineBy"]=mt;
mt["__new__"]=static_cast<cocos2d::CardinalSplineBy*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineBy::create);
}
void RegisterLuaCoreCatmullRomToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CatmullRomTo).name()] = sol::usertype_traits<cocos2d::CatmullRomTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::CatmullRomTo>("deprecated.cocos2d::CatmullRomTo");
dep[sol::base_classes]=sol::bases<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CatmullRomTo*>::metatable(),sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable());
lua["cc"]["CatmullRomTo"]=mt;
mt["__new__"]=static_cast<cocos2d::CatmullRomTo*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration);
}
void RegisterLuaCoreCatmullRomByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CatmullRomBy).name()] = sol::usertype_traits<cocos2d::CatmullRomBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::CatmullRomBy>("deprecated.cocos2d::CatmullRomBy");
dep[sol::base_classes]=sol::bases<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CatmullRomBy*>::metatable(),sol::usertype_traits<cocos2d::CardinalSplineBy*>::metatable());
lua["cc"]["CatmullRomBy"]=mt;
mt["__new__"]=static_cast<cocos2d::CatmullRomBy*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::CatmullRomBy::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::initWithDuration);
}
void RegisterLuaCoreActionEaseAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionEase).name()] = sol::usertype_traits<cocos2d::ActionEase*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionEase>("deprecated.cocos2d::ActionEase");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionEase*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["ActionEase"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::getInnerAction);
mt["get"]["InnerAction"]=mt["GetInnerAction"];
}
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
}
