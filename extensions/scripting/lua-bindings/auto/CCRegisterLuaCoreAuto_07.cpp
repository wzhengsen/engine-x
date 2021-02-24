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
void RegisterLuaCoreEventListenerControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerController");
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone));
mt.set_function("new",static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create));
mt["onConnected"] = &cocos2d::EventListenerController::onConnected;
mt["onDisconnected"] = &cocos2d::EventListenerController::onDisconnected;
mt["onKeyDown"] = &cocos2d::EventListenerController::onKeyDown;
mt["onKeyUp"] = &cocos2d::EventListenerController::onKeyUp;
mt["onKeyRepeat"] = &cocos2d::EventListenerController::onKeyRepeat;
mt["onAxisEvent"] = &cocos2d::EventListenerController::onAxisEvent;
}
void RegisterLuaCoreEventListenerTouchOneByOneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerTouchOneByOne,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerTouchOneByOne");
mt.set_function("setSwallowTouches",static_cast<void(cocos2d::EventListenerTouchOneByOne::*)(bool)>(&cocos2d::EventListenerTouchOneByOne::setSwallowTouches));
mt.set_function("isSwallowTouches",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::isSwallowTouches));
mt.set_function("clone",static_cast<cocos2d::EventListenerTouchOneByOne*(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::checkAvailable));
mt.set_function("new",static_cast<cocos2d::EventListenerTouchOneByOne*(*)()>(&cocos2d::EventListenerTouchOneByOne::create));
mt["onTouchBegan"] = &cocos2d::EventListenerTouchOneByOne::onTouchBegan;
mt["onTouchMoved"] = &cocos2d::EventListenerTouchOneByOne::onTouchMoved;
mt["onTouchEnded"] = &cocos2d::EventListenerTouchOneByOne::onTouchEnded;
mt["onTouchCancelled"] = &cocos2d::EventListenerTouchOneByOne::onTouchCancelled;
}
void RegisterLuaCoreEventListenerTouchAllAtOnceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerTouchAllAtOnce,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerTouchAllAtOnce");
mt.set_function("clone",static_cast<cocos2d::EventListenerTouchAllAtOnce*(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::checkAvailable));
mt.set_function("new",static_cast<cocos2d::EventListenerTouchAllAtOnce*(*)()>(&cocos2d::EventListenerTouchAllAtOnce::create));
mt["onTouchesBegan"] = &cocos2d::EventListenerTouchAllAtOnce::onTouchesBegan;
mt["onTouchesMoved"] = &cocos2d::EventListenerTouchAllAtOnce::onTouchesMoved;
mt["onTouchesEnded"] = &cocos2d::EventListenerTouchAllAtOnce::onTouchesEnded;
mt["onTouchesCancelled"] = &cocos2d::EventListenerTouchAllAtOnce::onTouchesCancelled;
}
void RegisterLuaCoreEventControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventController");
mt.set_function("getControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType));
mt.set_function("getController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController));
mt.set_function("getKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode));
mt.set_function("setKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode));
mt.set_function("setConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus));
mt.set_function("isConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected));
}
void RegisterLuaCoreActionCameraAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionCamera");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionCamera::*)(cocos2d::Node*)>(&cocos2d::ActionCamera::startWithTarget));
mt.set_function("reverse",static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::clone));
mt.set_function("setEye",sol::overload(static_cast<void(cocos2d::ActionCamera::*)(float,float,float)>(&cocos2d::ActionCamera::setEye),static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setEye)));
mt.set_function("getEye",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getEye));
mt.set_function("setCenter",static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setCenter));
mt.set_function("getCenter",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getCenter));
mt.set_function("setUp",static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setUp));
mt.set_function("getUp",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getUp));
}
void RegisterLuaCoreOrbitCameraAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::OrbitCamera,cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","OrbitCamera");
mt.set_function("sphericalRadius",static_cast<void(cocos2d::OrbitCamera::*)(float*,float*,float*)>(&cocos2d::OrbitCamera::sphericalRadius));
mt.set_function("clone",static_cast<cocos2d::OrbitCamera*(cocos2d::OrbitCamera::*)()const>(&cocos2d::OrbitCamera::clone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::OrbitCamera::*)(cocos2d::Node*)>(&cocos2d::OrbitCamera::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::OrbitCamera::*)(float)>(&cocos2d::OrbitCamera::update));
mt.set_function("new",static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create));
}
void RegisterLuaCorePointArrayAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PointArray,cocos2d::Ref,cocos2d::LuaObject>("cc","PointArray");
mt.set_function("initWithCapacity",static_cast<bool(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::initWithCapacity));
mt.set_function("addControlPoint",static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&)>(&cocos2d::PointArray::addControlPoint));
mt.set_function("insertControlPoint",static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::insertControlPoint));
mt.set_function("replaceControlPoint",static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::replaceControlPoint));
mt.set_function("getControlPointAtIndex",static_cast<const cocos2d::Vec2&(cocos2d::PointArray::*)(ssize_t)const>(&cocos2d::PointArray::getControlPointAtIndex));
mt.set_function("removeControlPointAtIndex",static_cast<void(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::removeControlPointAtIndex));
mt.set_function("count",static_cast<ssize_t(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::count));
mt.set_function("reverse",static_cast<cocos2d::PointArray*(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::reverse));
mt.set_function("reverseInline",static_cast<void(cocos2d::PointArray::*)()>(&cocos2d::PointArray::reverseInline));
mt.set_function("clone",static_cast<cocos2d::PointArray*(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::clone));
mt.set_function("getControlPoints",static_cast<const std::vector<cocos2d::Vec2>&(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::getControlPoints));
mt.set_function("setControlPoints",static_cast<void(cocos2d::PointArray::*)(std::vector<cocos2d::Vec2>)>(&cocos2d::PointArray::setControlPoints));
mt.set_function("new",static_cast<cocos2d::PointArray*(*)(ssize_t)>(&cocos2d::PointArray::create));
}
void RegisterLuaCoreCardinalSplineToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CardinalSplineTo");
mt.set_function("initWithDuration",static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration));
mt.set_function("updatePosition",static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition));
mt.set_function("getPoints",static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints));
mt.set_function("setPoints",static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::PointArray*)>(&cocos2d::CardinalSplineTo::setPoints));
mt.set_function("clone",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::clone));
mt.set_function("reverse",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::CardinalSplineTo::*)(float)>(&cocos2d::CardinalSplineTo::update));
mt.set_function("new",static_cast<cocos2d::CardinalSplineTo*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::create));
}
void RegisterLuaCoreCardinalSplineByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CardinalSplineBy");
mt.set_function("startWithTarget",static_cast<void(cocos2d::CardinalSplineBy::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineBy::startWithTarget));
mt.set_function("updatePosition",static_cast<void(cocos2d::CardinalSplineBy::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineBy::updatePosition));
mt.set_function("clone",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::clone));
mt.set_function("reverse",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::reverse));
mt.set_function("new",static_cast<cocos2d::CardinalSplineBy*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineBy::create));
}
void RegisterLuaCoreCatmullRomToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CatmullRomTo,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CatmullRomTo");
mt.set_function("initWithDuration",static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration));
mt.set_function("clone",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::clone));
mt.set_function("reverse",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::reverse));
mt.set_function("new",static_cast<cocos2d::CatmullRomTo*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::create));
}
