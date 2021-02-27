#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#include "base/CCGameController.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void RegisterLuaControllerControllerKeyAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Controller"];
pTable.new_enum("Key"
,"KEY_NONE",0
,"JOYSTICK_LEFT_X",1000
,"JOYSTICK_LEFT_Y",1001
,"JOYSTICK_RIGHT_X",1002
,"JOYSTICK_RIGHT_Y",1003
,"BUTTON_A",1004
,"BUTTON_B",1005
,"BUTTON_C",1006
,"BUTTON_X",1007
,"BUTTON_Y",1008
,"BUTTON_Z",1009
,"BUTTON_DPAD_UP",1010
,"BUTTON_DPAD_DOWN",1011
,"BUTTON_DPAD_LEFT",1012
,"BUTTON_DPAD_RIGHT",1013
,"BUTTON_DPAD_CENTER",1014
,"BUTTON_LEFT_SHOULDER",1015
,"BUTTON_RIGHT_SHOULDER",1016
,"AXIS_LEFT_TRIGGER",1017
,"AXIS_RIGHT_TRIGGER",1018
,"BUTTON_LEFT_THUMBSTICK",1019
,"BUTTON_RIGHT_THUMBSTICK",1020
,"BUTTON_START",1021
,"BUTTON_SELECT",1022
,"BUTTON_PAUSE",1023
,"KEY_MAX",1024
);}
void RegisterLuaControllerControllerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Controller>("Controller",true);
ns["Controller"] = mt;
lua["Controller"] = sol::nil;
mt.set_function("getDeviceName",static_cast<const std::string&(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName));
mt.set_function("getDeviceId",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId));
mt.set_function("isConnected",static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected));
mt.set_function("getKeyStatus",static_cast<const cocos2d::Controller::KeyStatus&(cocos2d::Controller::*)(int)>(&cocos2d::Controller::getKeyStatus));
mt.set_function("receiveExternalKeyEvent",static_cast<void(cocos2d::Controller::*)(int,bool)>(&cocos2d::Controller::receiveExternalKeyEvent));
mt.set_function("setTag",static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag));
mt.set_function("getTag",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag));
mt.set_function("getAllController",static_cast<const std::vector<cocos2d::Controller *>&(*)()>(&cocos2d::Controller::getAllController));
mt.set_function("getControllerByTag",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag));
mt.set_function("getControllerByDeviceId",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId));
mt.set_function("startDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController));
mt.set_function("stopDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController));
RegisterLuaControllerControllerKeyAuto(lua);
}
void RegisterLuaControllerEventControllerControllerEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventController"];
pTable.new_enum("ControllerEventType"
,"CONNECTION",0
,"BUTTON_STATUS_CHANGED",1
,"AXIS_STATUS_CHANGED",2
);}
void RegisterLuaControllerEventControllerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventController",true);
ns["EventController"] = mt;
lua["EventController"] = sol::nil;
mt.set_function("getControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType));
mt.set_function("getController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController));
mt.set_function("getKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode));
mt.set_function("setKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode));
mt.set_function("setConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus));
mt.set_function("isConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected));
RegisterLuaControllerEventControllerControllerEventTypeAuto(lua);
}
void RegisterLuaControllerEventListenerControllerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerController",false);
ns["EventListenerController"] = mt;
lua["EventListenerController"] = sol::nil;
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create));
mt["onConnected"] = &cocos2d::EventListenerController::onConnected;
mt["onDisconnected"] = &cocos2d::EventListenerController::onDisconnected;
mt["onKeyDown"] = &cocos2d::EventListenerController::onKeyDown;
mt["onKeyUp"] = &cocos2d::EventListenerController::onKeyUp;
mt["onKeyRepeat"] = &cocos2d::EventListenerController::onKeyRepeat;
mt["onAxisEvent"] = &cocos2d::EventListenerController::onAxisEvent;
}
#endif
