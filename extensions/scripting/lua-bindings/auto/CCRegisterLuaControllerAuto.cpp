#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "base/CCGameController.h"
static void RegisterLuaController(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Controller>("cc","Controller"
,"getDeviceName",static_cast<const std::string&(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName)
,"getDeviceId",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId)
,"isConnected",static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected)
,"receiveExternalKeyEvent",static_cast<void(cocos2d::Controller::*)(int,bool)>(&cocos2d::Controller::receiveExternalKeyEvent)
,"setTag",static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag)
,"getTag",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag)
,"getControllerByTag",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag)
,"getControllerByDeviceId",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId)
,"startDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController)
,"stopDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController)
);}
static void RegisterLuaEventController(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventController"
,"getControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType)
,"getController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController)
,"getKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode)
,"setKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode)
,"setConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus)
,"isConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected)
);}
static void RegisterLuaEventListenerController(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerController"
,"checkAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable)
,"clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone)
,"new",static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create)
);}
void RegisterLuaControllerAuto(cocos2d::Lua& lua) {
RegisterLuaController(lua);
RegisterLuaEventController(lua);
RegisterLuaEventListenerController(lua);
}
#endif
