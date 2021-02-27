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
void RegisterLuaCoreAnonymousEnum__1675882520335264955_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["CCZ_COMPRESSION_ZLIB"] = 0;
pTable["CCZ_COMPRESSION_BZIP2"] = 1;
pTable["CCZ_COMPRESSION_GZIP"] = 2;
pTable["CCZ_COMPRESSION_NONE"] = 3;
}
void RegisterLuaCoreEventAccelerationAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventAcceleration,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventAcceleration",true);
ns["EventAcceleration"] = mt;
lua["EventAcceleration"] = sol::nil;
}
void RegisterLuaCoreEventCustomAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventCustom",true);
ns["EventCustom"] = mt;
lua["EventCustom"] = sol::nil;
mt.set_function("setUserData",static_cast<void(cocos2d::EventCustom::*)(void*)>(&cocos2d::EventCustom::setUserData));
mt.set_function("getUserData",static_cast<void*(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getUserData));
mt.set_function("getEventName",static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName));
}
void RegisterLuaCoreEventDispatcherAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventDispatcher,cocos2d::Ref,cocos2d::LuaObject>("EventDispatcher",true);
ns["EventDispatcher"] = mt;
lua["EventDispatcher"] = sol::nil;
mt.set_function("addEventListenerWithSceneGraphPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority));
mt.set_function("addEventListenerWithFixedPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority));
mt.set_function("addCustomEventListener",static_cast<cocos2d::EventListenerCustom*(cocos2d::EventDispatcher::*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventDispatcher::addCustomEventListener));
mt.set_function("removeEventListener",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*)>(&cocos2d::EventDispatcher::removeEventListener));
mt.set_function("removeEventListenersForType",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener::Type)>(&cocos2d::EventDispatcher::removeEventListenersForType));
mt.set_function("removeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->removeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->removeEventListenersForTarget(arg0,arg1);}));
mt.set_function("removeCustomEventListeners",static_cast<void(cocos2d::EventDispatcher::*)(const std::string&)>(&cocos2d::EventDispatcher::removeCustomEventListeners));
mt.set_function("removeAllEventListeners",static_cast<void(cocos2d::EventDispatcher::*)()>(&cocos2d::EventDispatcher::removeAllEventListeners));
mt.set_function("pauseEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->pauseEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->pauseEventListenersForTarget(arg0,arg1);}));
mt.set_function("resumeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->resumeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->resumeEventListenersForTarget(arg0,arg1);}));
mt.set_function("setPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::setPriority));
mt.set_function("setEnabled",static_cast<void(cocos2d::EventDispatcher::*)(bool)>(&cocos2d::EventDispatcher::setEnabled));
mt.set_function("isEnabled",static_cast<bool(cocos2d::EventDispatcher::*)()const>(&cocos2d::EventDispatcher::isEnabled));
mt.set_function("dispatchEvent",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::Event*)>(&cocos2d::EventDispatcher::dispatchEvent));
mt.set_function("dispatchCustomEvent",sol::overload([](cocos2d::EventDispatcher* obj,const std::string& arg0){return obj->dispatchCustomEvent(arg0);},[](cocos2d::EventDispatcher* obj,const std::string& arg0,void* arg1){return obj->dispatchCustomEvent(arg0,arg1);}));
mt.set_function("hasEventListener",static_cast<bool(cocos2d::EventDispatcher::*)(const cocos2d::EventListener::ListenerID&)const>(&cocos2d::EventDispatcher::hasEventListener));
}
void RegisterLuaCoreEventFocusAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventFocus,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventFocus",true);
ns["EventFocus"] = mt;
lua["EventFocus"] = sol::nil;
}
void RegisterLuaCoreEventListenerAccelerationAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerAcceleration,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerAcceleration",false);
ns["EventListenerAcceleration"] = mt;
lua["EventListenerAcceleration"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EventListenerAcceleration*(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::checkAvailable));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerAcceleration*(*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::create));
}
void RegisterLuaCoreEventListenerFocusAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerFocus,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerFocus",false);
ns["EventListenerFocus"] = mt;
lua["EventListenerFocus"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EventListenerFocus*(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::checkAvailable));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerFocus*(*)()>(&cocos2d::EventListenerFocus::create));
mt["onFocusChanged"] = &cocos2d::EventListenerFocus::onFocusChanged;
}
void RegisterLuaCoreEventListenerKeyboardAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerKeyboard,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerKeyboard",false);
ns["EventListenerKeyboard"] = mt;
lua["EventListenerKeyboard"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EventListenerKeyboard*(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::checkAvailable));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerKeyboard*(*)()>(&cocos2d::EventListenerKeyboard::create));
mt["onKeyPressed"] = &cocos2d::EventListenerKeyboard::onKeyPressed;
mt["onKeyReleased"] = &cocos2d::EventListenerKeyboard::onKeyReleased;
}
void RegisterLuaCoreEventMouseMouseEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventMouse"];
pTable.new_enum("MouseEventType"
,"MOUSE_NONE",0
,"MOUSE_DOWN",1
,"MOUSE_UP",2
,"MOUSE_MOVE",3
,"MOUSE_SCROLL",4
);}
void RegisterLuaCoreEventMouseMouseButtonAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventMouse"];
pTable.new_enum("MouseButton"
,"BUTTON_UNSET",-1
,"BUTTON_LEFT",0
,"BUTTON_RIGHT",1
,"BUTTON_MIDDLE",2
,"BUTTON_4",3
,"BUTTON_5",4
,"BUTTON_6",5
,"BUTTON_7",6
,"BUTTON_8",7
);}
void RegisterLuaCoreEventMouseAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventMouse,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventMouse",true);
ns["EventMouse"] = mt;
lua["EventMouse"] = sol::nil;
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
RegisterLuaCoreEventMouseMouseEventTypeAuto(lua);
RegisterLuaCoreEventMouseMouseButtonAuto(lua);
}
void RegisterLuaCoreEventListenerMouseAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerMouse,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerMouse",false);
ns["EventListenerMouse"] = mt;
lua["EventListenerMouse"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::EventListenerMouse*(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::checkAvailable));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerMouse*(*)()>(&cocos2d::EventListenerMouse::create));
mt["onMouseDown"] = &cocos2d::EventListenerMouse::onMouseDown;
mt["onMouseUp"] = &cocos2d::EventListenerMouse::onMouseUp;
mt["onMouseMove"] = &cocos2d::EventListenerMouse::onMouseMove;
mt["onMouseScroll"] = &cocos2d::EventListenerMouse::onMouseScroll;
}
