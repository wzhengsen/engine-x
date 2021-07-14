#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#include "base/CCGameController.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
namespace cocos2d{
void RegisterLuaControllerControllerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Controller).name()] = sol::usertype_traits<cocos2d::Controller*>::metatable();
auto dep=lua.new_usertype<cocos2d::Controller>("deprecated.cocos2d::Controller");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Controller*>::metatable());
lua["cc"]["Controller"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetAllController"]=static_cast<const std::vector<cocos2d::Controller *, std::allocator<cocos2d::Controller *> >&(*)()>(&cocos2d::Controller::getAllController);
mt["static"]["get"]["AllController"]=mt["GetAllController"];
mt["static"]["GetControllerByTag"]=static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag);
mt["static"]["GetControllerByDeviceId"]=static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId);
mt["static"]["StartDiscoveryController"]=static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController);
mt["static"]["StopDiscoveryController"]=static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController);
mt["GetDeviceName"]=static_cast<const std::string&(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName);
mt["get"]["DeviceName"]=mt["GetDeviceName"];
mt["GetDeviceId"]=static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId);
mt["get"]["DeviceId"]=mt["GetDeviceId"];
mt["IsConnected"]=static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected);
mt["get"]["Connected"]=mt["IsConnected"];
mt["GetKeyStatus"]=static_cast<const cocos2d::Controller::KeyStatus&(cocos2d::Controller::*)(int)>(&cocos2d::Controller::getKeyStatus);
mt["ReceiveExternalKeyEvent"]=static_cast<void(cocos2d::Controller::*)(int,bool)>(&cocos2d::Controller::receiveExternalKeyEvent);
mt["SetTag"]=static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag);
mt["set"]["Tag"]=mt["SetTag"];
mt["GetTag"]=static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag);
mt["get"]["Tag"]=mt["GetTag"];
mt["static"]["get"]["TAG_UNSET"]=[]()->const int&{return cocos2d::Controller::TAG_UNSET;};
}
void RegisterLuaControllerEventControllerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventController).name()] = sol::usertype_traits<cocos2d::EventController*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventController>("deprecated.cocos2d::EventController");
dep[sol::base_classes]=sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventController*>::metatable(),sol::usertype_traits<cocos2d::Event*>::metatable());
lua["cc"]["EventController"]=mt;
mt["__new__"]=sol::overload([](cocos2d::EventController::ControllerEventType arg0,cocos2d::Controller* arg1,bool arg2){return new cocos2d::EventController(arg0,arg1,arg2);},[](cocos2d::EventController::ControllerEventType arg0,cocos2d::Controller* arg1,int arg2){return new cocos2d::EventController(arg0,arg1,arg2);});
mt["GetControllerEventType"]=static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType);
mt["get"]["ControllerEventType"]=mt["GetControllerEventType"];
mt["GetController"]=static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController);
mt["get"]["Controller"]=mt["GetController"];
mt["GetKeyCode"]=static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode);
mt["get"]["KeyCode"]=mt["GetKeyCode"];
mt["SetKeyCode"]=static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode);
mt["set"]["KeyCode"]=mt["SetKeyCode"];
mt["SetConnectStatus"]=static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus);
mt["set"]["ConnectStatus"]=mt["SetConnectStatus"];
mt["IsConnected"]=static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected);
mt["get"]["Connected"]=mt["IsConnected"];
}
void RegisterLuaControllerEventListenerControllerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerController).name()] = sol::usertype_traits<cocos2d::EventListenerController*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerController>("deprecated.cocos2d::EventListenerController");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerController*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerController"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create);
mt["static"]["get"]["LISTENER_ID"]=[]()->const std::string&{return cocos2d::EventListenerController::LISTENER_ID;};
mt["set"]["OnConnected"]=[](cocos2d::EventListenerController* obj,const std::function<void (cocos2d::Controller *, cocos2d::Event *)>& value){obj->onConnected = value;};
mt["get"]["OnConnected"]=[](cocos2d::EventListenerController* obj)->const std::function<void (cocos2d::Controller *, cocos2d::Event *)>&{return obj->onConnected;};
mt["set"]["OnDisconnected"]=[](cocos2d::EventListenerController* obj,const std::function<void (cocos2d::Controller *, cocos2d::Event *)>& value){obj->onDisconnected = value;};
mt["get"]["OnDisconnected"]=[](cocos2d::EventListenerController* obj)->const std::function<void (cocos2d::Controller *, cocos2d::Event *)>&{return obj->onDisconnected;};
mt["set"]["OnKeyDown"]=[](cocos2d::EventListenerController* obj,const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>& value){obj->onKeyDown = value;};
mt["get"]["OnKeyDown"]=[](cocos2d::EventListenerController* obj)->const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>&{return obj->onKeyDown;};
mt["set"]["OnKeyUp"]=[](cocos2d::EventListenerController* obj,const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>& value){obj->onKeyUp = value;};
mt["get"]["OnKeyUp"]=[](cocos2d::EventListenerController* obj)->const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>&{return obj->onKeyUp;};
mt["set"]["OnKeyRepeat"]=[](cocos2d::EventListenerController* obj,const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>& value){obj->onKeyRepeat = value;};
mt["get"]["OnKeyRepeat"]=[](cocos2d::EventListenerController* obj)->const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>&{return obj->onKeyRepeat;};
mt["set"]["OnAxisEvent"]=[](cocos2d::EventListenerController* obj,const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>& value){obj->onAxisEvent = value;};
mt["get"]["OnAxisEvent"]=[](cocos2d::EventListenerController* obj)->const std::function<void (cocos2d::Controller *, int, cocos2d::Event *)>&{return obj->onAxisEvent;};
}
}
#endif
