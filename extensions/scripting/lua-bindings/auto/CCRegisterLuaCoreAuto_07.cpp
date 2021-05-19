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
void RegisterLuaCoreEventListenerAccelerationAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerAcceleration>("cc","EventListenerAcceleration",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerAcceleration*(*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::create));
mt.set_function("Clone",static_cast<cocos2d::EventListenerAcceleration*(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::clone));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::checkAvailable));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerAcceleration::LISTENER_ID));
}
void RegisterLuaCoreEventListenerFocusAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerFocus>("cc","EventListenerFocus",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerFocus*(*)()>(&cocos2d::EventListenerFocus::create));
mt.set_function("Clone",static_cast<cocos2d::EventListenerFocus*(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::clone));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::checkAvailable));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerFocus::LISTENER_ID));
mt["OnFocusChanged"]=&cocos2d::EventListenerFocus::onFocusChanged;
}
void RegisterLuaCoreEventListenerKeyboardAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerKeyboard>("cc","EventListenerKeyboard",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerKeyboard*(*)()>(&cocos2d::EventListenerKeyboard::create));
mt.set_function("Clone",static_cast<cocos2d::EventListenerKeyboard*(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::clone));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::checkAvailable));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerKeyboard::LISTENER_ID));
mt["OnKeyPressed"]=&cocos2d::EventListenerKeyboard::onKeyPressed;
mt["OnKeyReleased"]=&cocos2d::EventListenerKeyboard::onKeyReleased;
}
void RegisterLuaCoreEventMouseMouseEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventMouse"];
pTable.new_enum<cocos2d::EventMouse::MouseEventType>("MouseEventType",{
{"MOUSE_NONE",cocos2d::EventMouse::MouseEventType::MOUSE_NONE}
,{"MOUSE_DOWN",cocos2d::EventMouse::MouseEventType::MOUSE_DOWN}
,{"MOUSE_UP",cocos2d::EventMouse::MouseEventType::MOUSE_UP}
,{"MOUSE_MOVE",cocos2d::EventMouse::MouseEventType::MOUSE_MOVE}
,{"MOUSE_SCROLL",cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL}
});}
void RegisterLuaCoreEventMouseMouseButtonAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventMouse"];
pTable.new_enum<cocos2d::EventMouse::MouseButton>("MouseButton",{
{"BUTTON_UNSET",cocos2d::EventMouse::MouseButton::BUTTON_UNSET}
,{"BUTTON_LEFT",cocos2d::EventMouse::MouseButton::BUTTON_LEFT}
,{"BUTTON_RIGHT",cocos2d::EventMouse::MouseButton::BUTTON_RIGHT}
,{"BUTTON_MIDDLE",cocos2d::EventMouse::MouseButton::BUTTON_MIDDLE}
,{"BUTTON_4",cocos2d::EventMouse::MouseButton::BUTTON_4}
,{"BUTTON_5",cocos2d::EventMouse::MouseButton::BUTTON_5}
,{"BUTTON_6",cocos2d::EventMouse::MouseButton::BUTTON_6}
,{"BUTTON_7",cocos2d::EventMouse::MouseButton::BUTTON_7}
,{"BUTTON_8",cocos2d::EventMouse::MouseButton::BUTTON_8}
});}
void RegisterLuaCoreEventMouseAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventMouse>("cc","EventMouse",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetScrollData",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setScrollData));
mt.set_function("GetScrollX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollX));
mt.set_function("GetScrollY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollY));
mt.set_function("SetCursorPosition",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setCursorPosition));
mt.set_function("SetMouseButton",static_cast<void(cocos2d::EventMouse::*)(cocos2d::EventMouse::MouseButton)>(&cocos2d::EventMouse::setMouseButton));
mt.set_function("GetMouseButton",static_cast<cocos2d::EventMouse::MouseButton(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getMouseButton));
mt.set_function("GetCursorX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorX));
mt.set_function("GetCursorY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorY));
mt.set_function("GetLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocation));
mt.set_function("GetPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocation));
mt.set_function("GetStartLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocation));
mt.set_function("GetDelta",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getDelta));
mt.set_function("GetLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocationInView));
mt.set_function("GetPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocationInView));
mt.set_function("GetStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocationInView));
mt[sol::call_constructor]=sol::constructors<cocos2d::EventMouse(cocos2d::EventMouse::MouseEventType)>();
RegisterLuaCoreEventMouseMouseEventTypeAuto(lua);
RegisterLuaCoreEventMouseMouseButtonAuto(lua);
}
void RegisterLuaCoreEventListenerMouseAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerMouse>("cc","EventListenerMouse",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerMouse*(*)()>(&cocos2d::EventListenerMouse::create));
mt.set_function("Clone",static_cast<cocos2d::EventListenerMouse*(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::clone));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::checkAvailable));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerMouse::LISTENER_ID));
mt["OnMouseDown"]=&cocos2d::EventListenerMouse::onMouseDown;
mt["OnMouseUp"]=&cocos2d::EventListenerMouse::onMouseUp;
mt["OnMouseMove"]=&cocos2d::EventListenerMouse::onMouseMove;
mt["OnMouseScroll"]=&cocos2d::EventListenerMouse::onMouseScroll;
}
void RegisterLuaCoreEventListenerControllerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerController>("cc","EventListenerController",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable));
mt.set_function("Clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerController::LISTENER_ID));
mt["OnConnected"]=&cocos2d::EventListenerController::onConnected;
mt["OnDisconnected"]=&cocos2d::EventListenerController::onDisconnected;
mt["OnKeyDown"]=&cocos2d::EventListenerController::onKeyDown;
mt["OnKeyUp"]=&cocos2d::EventListenerController::onKeyUp;
mt["OnKeyRepeat"]=&cocos2d::EventListenerController::onKeyRepeat;
mt["OnAxisEvent"]=&cocos2d::EventListenerController::onAxisEvent;
}
void RegisterLuaCoreEventListenerTouchOneByOneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerTouchOneByOne>("cc","EventListenerTouchOneByOne",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerTouchOneByOne*(*)()>(&cocos2d::EventListenerTouchOneByOne::create));
mt.set_function("SetSwallowTouches",static_cast<void(cocos2d::EventListenerTouchOneByOne::*)(bool)>(&cocos2d::EventListenerTouchOneByOne::setSwallowTouches));
mt.set_function("IsSwallowTouches",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::isSwallowTouches));
mt.set_function("Clone",static_cast<cocos2d::EventListenerTouchOneByOne*(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::clone));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::checkAvailable));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerTouchOneByOne::LISTENER_ID));
mt["OnTouchBegan"]=&cocos2d::EventListenerTouchOneByOne::onTouchBegan;
mt["OnTouchMoved"]=&cocos2d::EventListenerTouchOneByOne::onTouchMoved;
mt["OnTouchEnded"]=&cocos2d::EventListenerTouchOneByOne::onTouchEnded;
mt["OnTouchCancelled"]=&cocos2d::EventListenerTouchOneByOne::onTouchCancelled;
}
void RegisterLuaCoreEventListenerTouchAllAtOnceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerTouchAllAtOnce>("cc","EventListenerTouchAllAtOnce",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerTouchAllAtOnce*(*)()>(&cocos2d::EventListenerTouchAllAtOnce::create));
mt.set_function("Clone",static_cast<cocos2d::EventListenerTouchAllAtOnce*(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::clone));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::checkAvailable));
mt["LISTENER_ID"]=sol::var(std::ref(cocos2d::EventListenerTouchAllAtOnce::LISTENER_ID));
mt["OnTouchesBegan"]=&cocos2d::EventListenerTouchAllAtOnce::onTouchesBegan;
mt["OnTouchesMoved"]=&cocos2d::EventListenerTouchAllAtOnce::onTouchesMoved;
mt["OnTouchesEnded"]=&cocos2d::EventListenerTouchAllAtOnce::onTouchesEnded;
mt["OnTouchesCancelled"]=&cocos2d::EventListenerTouchAllAtOnce::onTouchesCancelled;
}
void RegisterLuaCoreEventControllerControllerEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventController"];
pTable.new_enum<cocos2d::EventController::ControllerEventType>("ControllerEventType",{
{"CONNECTION",cocos2d::EventController::ControllerEventType::CONNECTION}
,{"BUTTON_STATUS_CHANGED",cocos2d::EventController::ControllerEventType::BUTTON_STATUS_CHANGED}
,{"AXIS_STATUS_CHANGED",cocos2d::EventController::ControllerEventType::AXIS_STATUS_CHANGED}
});}
void RegisterLuaCoreEventControllerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventController>("cc","EventController",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType));
mt.set_function("GetController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController));
mt.set_function("GetKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode));
mt.set_function("SetKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode));
mt.set_function("SetConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus));
mt.set_function("IsConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected));
mt[sol::call_constructor]=sol::constructors<cocos2d::EventController(cocos2d::EventController::ControllerEventType,cocos2d::Controller*,int),cocos2d::EventController(cocos2d::EventController::ControllerEventType,cocos2d::Controller*,bool)>();
RegisterLuaCoreEventControllerControllerEventTypeAuto(lua);
}
void RegisterLuaCoreActionCameraAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionCamera>("cc","ActionCamera",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ActionCamera::*)(cocos2d::Node*)>(&cocos2d::ActionCamera::startWithTarget));
mt.set_function("Reverse",static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::reverse));
mt.set_function("Clone",static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::clone));
mt.set_function("SetEye",sol::overload(static_cast<void(cocos2d::ActionCamera::*)(float,float,float)>(&cocos2d::ActionCamera::setEye),static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setEye)));
mt.set_function("GetEye",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getEye));
mt.set_function("SetCenter",static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setCenter));
mt.set_function("GetCenter",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getCenter));
mt.set_function("SetUp",static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setUp));
mt.set_function("GetUp",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getUp));
mt[sol::call_constructor]=sol::constructors<cocos2d::ActionCamera()>();
}
