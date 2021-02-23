#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreEventFocusAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventFocus,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventFocus");
}
void RegisterLuaCoreEventListenerAccelerationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerAcceleration,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerAcceleration");
mt.set_function("clone",static_cast<cocos2d::EventListenerAcceleration*(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::checkAvailable));
mt.set_function("init",static_cast<bool(cocos2d::EventListenerAcceleration::*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::init));
}
void RegisterLuaCoreEventListenerFocusAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerFocus,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerFocus");
mt.set_function("clone",static_cast<cocos2d::EventListenerFocus*(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::checkAvailable));
mt.set_function("init",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::init));
}
void RegisterLuaCoreEventListenerKeyboardAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerKeyboard,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerKeyboard");
mt.set_function("clone",static_cast<cocos2d::EventListenerKeyboard*(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::checkAvailable));
mt.set_function("init",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::init));
}
void RegisterLuaCoreEventMouseAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventMouse,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventMouse");
mt.set_function("setScrollData",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setScrollData));
mt.set_function("getScrollX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollX));
mt.set_function("getScrollY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollY));
mt.set_function("setCursorPosition",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setCursorPosition));
mt.set_function("setMouseButton",static_cast<void(cocos2d::EventMouse::*)(cocos2d::EventMouse::MouseButton)>(&cocos2d::EventMouse::setMouseButton));
mt.set_function("getMouseButton",static_cast<cocos2d::EventMouse::MouseButton(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getMouseButton));
mt.set_function("getCursorX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorX));
mt.set_function("getCursorY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorY));
mt.set_function("getLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocation));
mt.set_function("getPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocation));
mt.set_function("getStartLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocation));
mt.set_function("getDelta",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getDelta));
mt.set_function("getLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocationInView));
mt.set_function("getPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocationInView));
mt.set_function("getStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocationInView));
}
void RegisterLuaCoreEventListenerMouseAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerMouse,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerMouse");
mt.set_function("clone",static_cast<cocos2d::EventListenerMouse*(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::checkAvailable));
mt.set_function("init",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::init));
}
void RegisterLuaCoreEventListenerControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerController");
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone));
}
void RegisterLuaCoreEventListenerTouchOneByOneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerTouchOneByOne,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerTouchOneByOne");
mt.set_function("setSwallowTouches",static_cast<void(cocos2d::EventListenerTouchOneByOne::*)(bool)>(&cocos2d::EventListenerTouchOneByOne::setSwallowTouches));
mt.set_function("isSwallowTouches",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::isSwallowTouches));
mt.set_function("clone",static_cast<cocos2d::EventListenerTouchOneByOne*(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::checkAvailable));
mt.set_function("init",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::init));
}
void RegisterLuaCoreEventListenerTouchAllAtOnceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerTouchAllAtOnce,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerTouchAllAtOnce");
mt.set_function("clone",static_cast<cocos2d::EventListenerTouchAllAtOnce*(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::checkAvailable));
mt.set_function("init",static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::init));
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
mt.set_function("clone",static_cast<cocos2d::OrbitCamera*(cocos2d::OrbitCamera::*)()const>(&cocos2d::OrbitCamera::clone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::OrbitCamera::*)(cocos2d::Node*)>(&cocos2d::OrbitCamera::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::OrbitCamera::*)(float)>(&cocos2d::OrbitCamera::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::OrbitCamera::*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::initWithDuration));
mt.set_function("new",static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create));
}
void RegisterLuaCoreCardinalSplineToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CardinalSplineTo");
mt.set_function("initWithDuration",static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration));
mt.set_function("updatePosition",static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition));
mt.set_function("getPoints",static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints));
mt.set_function("clone",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::clone));
mt.set_function("reverse",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::CardinalSplineTo::*)(float)>(&cocos2d::CardinalSplineTo::update));
}
void RegisterLuaCoreCardinalSplineByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CardinalSplineBy");
mt.set_function("startWithTarget",static_cast<void(cocos2d::CardinalSplineBy::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineBy::startWithTarget));
mt.set_function("updatePosition",static_cast<void(cocos2d::CardinalSplineBy::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineBy::updatePosition));
mt.set_function("clone",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::clone));
mt.set_function("reverse",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::reverse));
}
void RegisterLuaCoreCatmullRomToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CatmullRomTo,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CatmullRomTo");
mt.set_function("initWithDuration",static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration));
mt.set_function("clone",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::clone));
mt.set_function("reverse",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::reverse));
}
