#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "base/CCGameController.h"
static void RegisterLuaControllerController(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Controller>("cc","Controller");
mt["getDeviceName"]=static_cast<const std::string&(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName);
mt["getDeviceId"]=static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId);
mt["isConnected"]=static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected);
mt["receiveExternalKeyEvent"]=static_cast<void(cocos2d::Controller::*)(int,bool)>(&cocos2d::Controller::receiveExternalKeyEvent);
mt["setTag"]=static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag);
mt["getTag"]=static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag);
mt["getControllerByTag"]=static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag);
mt["getControllerByDeviceId"]=static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId);
mt["startDiscoveryController"]=static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController);
mt["stopDiscoveryController"]=static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController);
}
static void RegisterLuaControllerEventController(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventController");
mt["getControllerEventType"]=static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType);
mt["getController"]=static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController);
mt["getKeyCode"]=static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode);
mt["setKeyCode"]=static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode);
mt["setConnectStatus"]=static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus);
mt["isConnected"]=static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected);
}
static void RegisterLuaControllerEventListenerController(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerController");
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable);
mt["clone"]=static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone);
mt["new"]=static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create);
}
void RegisterLuaControllerAuto(cocos2d::Lua& lua) {
RegisterLuaControllerController(lua);
RegisterLuaControllerEventController(lua);
RegisterLuaControllerEventListenerController(lua);
}
#endif
