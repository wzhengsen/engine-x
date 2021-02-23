#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#include "base/CCGameController.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void RegisterLuaControllerControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Controller>("cc","Controller");
mt.set_function("getDeviceName",static_cast<const std::string&(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName));
mt.set_function("getDeviceId",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId));
mt.set_function("isConnected",static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected));
mt.set_function("receiveExternalKeyEvent",static_cast<void(cocos2d::Controller::*)(int,bool)>(&cocos2d::Controller::receiveExternalKeyEvent));
mt.set_function("setTag",static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag));
mt.set_function("getTag",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag));
mt.set_function("getControllerByTag",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag));
mt.set_function("getControllerByDeviceId",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId));
mt.set_function("startDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController));
mt.set_function("stopDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController));
}
void RegisterLuaControllerEventControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventController");
mt.set_function("getControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType));
mt.set_function("getController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController));
mt.set_function("getKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode));
mt.set_function("setKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode));
mt.set_function("setConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus));
mt.set_function("isConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected));
}
void RegisterLuaControllerEventListenerControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerController");
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone));
mt.set_function("new",static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create));
}
#endif
