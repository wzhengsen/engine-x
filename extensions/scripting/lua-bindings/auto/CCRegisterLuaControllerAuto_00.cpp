#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#include "base/CCGameController.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void RegisterLuaControllerControllerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Controller>("cc","Controller",true);
mt.set_function("GetAllController",static_cast<const std::vector<cocos2d::Controller *, std::allocator<cocos2d::Controller *> >&(*)()>(&cocos2d::Controller::getAllController));
mt.set_function("GetControllerByTag",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag));
mt.set_function("GetControllerByDeviceId",static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId));
mt.set_function("StartDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController));
mt.set_function("StopDiscoveryController",static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController));
mt.set_function("GetDeviceName",static_cast<const std::string&(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName));
mt.set_function("GetDeviceId",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId));
mt.set_function("IsConnected",static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected));
mt.set_function("GetKeyStatus",static_cast<const cocos2d::Controller::KeyStatus&(cocos2d::Controller::*)(int)>(&cocos2d::Controller::getKeyStatus));
mt.set_function("ReceiveExternalKeyEvent",static_cast<void(cocos2d::Controller::*)(int,bool)>(&cocos2d::Controller::receiveExternalKeyEvent));
mt.set_function("SetTag",static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag));
mt.set_function("GetTag",static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag));
mt["TAG_UNSET"]=sol::var(std::ref(cocos2d::Controller::TAG_UNSET));
}
void RegisterLuaControllerEventControllerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventController>("cc","EventController",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType));
mt.set_function("GetController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController));
mt.set_function("GetKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode));
mt.set_function("SetKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode));
mt.set_function("SetConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus));
mt.set_function("IsConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected));
mt[sol::call_constructor]=sol::constructors<cocos2d::EventController(cocos2d::EventController::ControllerEventType,cocos2d::Controller*,int),cocos2d::EventController(cocos2d::EventController::ControllerEventType,cocos2d::Controller*,bool)>();
}
void RegisterLuaControllerEventListenerControllerAuto(cocos2d::extension::Lua& lua){
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
#endif
