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
namespace cocos2d{
void RegisterLuaCoreEventCustomAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventCustom).name()] = sol::usertype_traits<cocos2d::EventCustom*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventCustom>("deprecated.cocos2d::EventCustom");
dep[sol::base_classes]=sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventCustom*>::metatable(),sol::usertype_traits<cocos2d::Event*>::metatable());
lua["cc"]["EventCustom"]=mt;
mt["__new__"]=[](const std::string& arg0){return new cocos2d::EventCustom(arg0);};
mt["SetUserData"]=static_cast<void(cocos2d::EventCustom::*)(void*)>(&cocos2d::EventCustom::setUserData);
mt["set"]["UserData"]=mt["SetUserData"];
mt["GetUserData"]=static_cast<void*(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getUserData);
mt["get"]["UserData"]=mt["GetUserData"];
mt["GetEventName"]=static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName);
mt["get"]["EventName"]=mt["GetEventName"];
}
void RegisterLuaCoreEventDispatcherAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventDispatcher).name()] = sol::usertype_traits<cocos2d::EventDispatcher*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventDispatcher>("deprecated.cocos2d::EventDispatcher");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventDispatcher*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["EventDispatcher"]=mt;
mt["__new__"]=[](){return new cocos2d::EventDispatcher();};
mt["AddEventListenerWithSceneGraphPriority"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority);
mt["AddEventListenerWithFixedPriority"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority);
mt["AddCustomEventListener"]=static_cast<cocos2d::EventListenerCustom*(cocos2d::EventDispatcher::*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventDispatcher::addCustomEventListener);
mt["RemoveEventListener"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*)>(&cocos2d::EventDispatcher::removeEventListener);
mt["RemoveEventListenersForType"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener::Type)>(&cocos2d::EventDispatcher::removeEventListenersForType);
mt["RemoveEventListenersForTarget"]=sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->removeEventListenersForTarget(arg0,arg1);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->removeEventListenersForTarget(arg0);});
mt["RemoveCustomEventListeners"]=static_cast<void(cocos2d::EventDispatcher::*)(const std::string&)>(&cocos2d::EventDispatcher::removeCustomEventListeners);
mt["RemoveAllEventListeners"]=static_cast<void(cocos2d::EventDispatcher::*)()>(&cocos2d::EventDispatcher::removeAllEventListeners);
mt["PauseEventListenersForTarget"]=sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->pauseEventListenersForTarget(arg0,arg1);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->pauseEventListenersForTarget(arg0);});
mt["ResumeEventListenersForTarget"]=sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->resumeEventListenersForTarget(arg0,arg1);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->resumeEventListenersForTarget(arg0);});
mt["SetPriority"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::setPriority);
mt["SetEnabled"]=static_cast<void(cocos2d::EventDispatcher::*)(bool)>(&cocos2d::EventDispatcher::setEnabled);
mt["set"]["Enabled"]=mt["SetEnabled"];
mt["IsEnabled"]=static_cast<bool(cocos2d::EventDispatcher::*)()const>(&cocos2d::EventDispatcher::isEnabled);
mt["get"]["Enabled"]=mt["IsEnabled"];
mt["DispatchEvent"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::Event*)>(&cocos2d::EventDispatcher::dispatchEvent);
mt["DispatchCustomEvent"]=sol::overload([](cocos2d::EventDispatcher* obj,const std::string& arg0,void* arg1){return obj->dispatchCustomEvent(arg0,arg1);},[](cocos2d::EventDispatcher* obj,const std::string& arg0){return obj->dispatchCustomEvent(arg0);});
mt["HasEventListener"]=static_cast<bool(cocos2d::EventDispatcher::*)(const cocos2d::EventListener::ListenerID&)const>(&cocos2d::EventDispatcher::hasEventListener);
}
void RegisterLuaCoreEventFocusAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventFocus).name()] = sol::usertype_traits<cocos2d::EventFocus*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventFocus>("deprecated.cocos2d::EventFocus");
dep[sol::base_classes]=sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventFocus*>::metatable(),sol::usertype_traits<cocos2d::Event*>::metatable());
lua["cc"]["EventFocus"]=mt;
mt["__new__"]=[](cocos2d::ui::Widget* arg0,cocos2d::ui::Widget* arg1){return new cocos2d::EventFocus(arg0,arg1);};
}
void RegisterLuaCoreEventListenerAccelerationAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerAcceleration).name()] = sol::usertype_traits<cocos2d::EventListenerAcceleration*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerAcceleration>("deprecated.cocos2d::EventListenerAcceleration");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerAcceleration*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerAcceleration"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerAcceleration*(*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::create);
mt["static"]["get"]["LISTENER_ID"]=[]()->const std::string&{return cocos2d::EventListenerAcceleration::LISTENER_ID;};
}
void RegisterLuaCoreEventListenerFocusAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerFocus).name()] = sol::usertype_traits<cocos2d::EventListenerFocus*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerFocus>("deprecated.cocos2d::EventListenerFocus");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerFocus*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerFocus"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerFocus*(*)()>(&cocos2d::EventListenerFocus::create);
mt["static"]["get"]["LISTENER_ID"]=[]()->const std::string&{return cocos2d::EventListenerFocus::LISTENER_ID;};
mt["set"]["OnFocusChanged"]=[](cocos2d::EventListenerFocus* obj,const std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)>& value){obj->onFocusChanged = value;};
mt["get"]["OnFocusChanged"]=[](cocos2d::EventListenerFocus* obj)->const std::function<void (cocos2d::ui::Widget *, cocos2d::ui::Widget *)>&{return obj->onFocusChanged;};
}
void RegisterLuaCoreEventListenerKeyboardAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerKeyboard).name()] = sol::usertype_traits<cocos2d::EventListenerKeyboard*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerKeyboard>("deprecated.cocos2d::EventListenerKeyboard");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerKeyboard*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerKeyboard"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerKeyboard*(*)()>(&cocos2d::EventListenerKeyboard::create);
mt["static"]["get"]["LISTENER_ID"]=[]()->const std::string&{return cocos2d::EventListenerKeyboard::LISTENER_ID;};
mt["set"]["OnKeyPressed"]=[](cocos2d::EventListenerKeyboard* obj,const std::function<void (cocos2d::EventKeyboard::KeyCode, cocos2d::Event *)>& value){obj->onKeyPressed = value;};
mt["get"]["OnKeyPressed"]=[](cocos2d::EventListenerKeyboard* obj)->const std::function<void (cocos2d::EventKeyboard::KeyCode, cocos2d::Event *)>&{return obj->onKeyPressed;};
mt["set"]["OnKeyReleased"]=[](cocos2d::EventListenerKeyboard* obj,const std::function<void (cocos2d::EventKeyboard::KeyCode, cocos2d::Event *)>& value){obj->onKeyReleased = value;};
mt["get"]["OnKeyReleased"]=[](cocos2d::EventListenerKeyboard* obj)->const std::function<void (cocos2d::EventKeyboard::KeyCode, cocos2d::Event *)>&{return obj->onKeyReleased;};
}
void RegisterLuaCoreEventMouseMouseEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,5);
enumTable["MOUSE_NONE"]=cocos2d::EventMouse::MouseEventType::MOUSE_NONE;
enumTable["MOUSE_DOWN"]=cocos2d::EventMouse::MouseEventType::MOUSE_DOWN;
enumTable["MOUSE_UP"]=cocos2d::EventMouse::MouseEventType::MOUSE_UP;
enumTable["MOUSE_MOVE"]=cocos2d::EventMouse::MouseEventType::MOUSE_MOVE;
enumTable["MOUSE_SCROLL"]=cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL;
lua["cc"]["EventMouse"]["static"]["MouseEventType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreEventMouseMouseButtonAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,9);
enumTable["BUTTON_UNSET"]=cocos2d::EventMouse::MouseButton::BUTTON_UNSET;
enumTable["BUTTON_LEFT"]=cocos2d::EventMouse::MouseButton::BUTTON_LEFT;
enumTable["BUTTON_RIGHT"]=cocos2d::EventMouse::MouseButton::BUTTON_RIGHT;
enumTable["BUTTON_MIDDLE"]=cocos2d::EventMouse::MouseButton::BUTTON_MIDDLE;
enumTable["BUTTON_4"]=cocos2d::EventMouse::MouseButton::BUTTON_4;
enumTable["BUTTON_5"]=cocos2d::EventMouse::MouseButton::BUTTON_5;
enumTable["BUTTON_6"]=cocos2d::EventMouse::MouseButton::BUTTON_6;
enumTable["BUTTON_7"]=cocos2d::EventMouse::MouseButton::BUTTON_7;
enumTable["BUTTON_8"]=cocos2d::EventMouse::MouseButton::BUTTON_8;
lua["cc"]["EventMouse"]["static"]["MouseButton"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreEventMouseAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventMouse).name()] = sol::usertype_traits<cocos2d::EventMouse*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventMouse>("deprecated.cocos2d::EventMouse");
dep[sol::base_classes]=sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventMouse*>::metatable(),sol::usertype_traits<cocos2d::Event*>::metatable());
lua["cc"]["EventMouse"]=mt;
mt["__new__"]=[](cocos2d::EventMouse::MouseEventType arg0){return new cocos2d::EventMouse(arg0);};
mt["SetScrollData"]=static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setScrollData);
mt["GetScrollX"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollX);
mt["get"]["ScrollX"]=mt["GetScrollX"];
mt["GetScrollY"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollY);
mt["get"]["ScrollY"]=mt["GetScrollY"];
mt["SetCursorPosition"]=static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setCursorPosition);
mt["SetMouseButton"]=static_cast<void(cocos2d::EventMouse::*)(cocos2d::EventMouse::MouseButton)>(&cocos2d::EventMouse::setMouseButton);
mt["set"]["MouseButton"]=mt["SetMouseButton"];
mt["GetMouseButton"]=static_cast<cocos2d::EventMouse::MouseButton(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getMouseButton);
mt["get"]["MouseButton"]=mt["GetMouseButton"];
mt["GetCursorX"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorX);
mt["get"]["CursorX"]=mt["GetCursorX"];
mt["GetCursorY"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorY);
mt["get"]["CursorY"]=mt["GetCursorY"];
mt["GetLocation"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocation);
mt["get"]["Location"]=mt["GetLocation"];
mt["GetPreviousLocation"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocation);
mt["get"]["PreviousLocation"]=mt["GetPreviousLocation"];
mt["GetStartLocation"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocation);
mt["get"]["StartLocation"]=mt["GetStartLocation"];
mt["GetDelta"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getDelta);
mt["get"]["Delta"]=mt["GetDelta"];
mt["GetLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocationInView);
mt["get"]["LocationInView"]=mt["GetLocationInView"];
mt["GetPreviousLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocationInView);
mt["get"]["PreviousLocationInView"]=mt["GetPreviousLocationInView"];
mt["GetStartLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocationInView);
mt["get"]["StartLocationInView"]=mt["GetStartLocationInView"];
RegisterLuaCoreEventMouseMouseEventTypeAuto(lua);
RegisterLuaCoreEventMouseMouseButtonAuto(lua);
}
void RegisterLuaCoreEventListenerMouseAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerMouse).name()] = sol::usertype_traits<cocos2d::EventListenerMouse*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerMouse>("deprecated.cocos2d::EventListenerMouse");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerMouse*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerMouse"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerMouse*(*)()>(&cocos2d::EventListenerMouse::create);
mt["static"]["get"]["LISTENER_ID"]=[]()->const std::string&{return cocos2d::EventListenerMouse::LISTENER_ID;};
mt["set"]["OnMouseDown"]=[](cocos2d::EventListenerMouse* obj,const std::function<void (cocos2d::EventMouse *)>& value){obj->onMouseDown = value;};
mt["get"]["OnMouseDown"]=[](cocos2d::EventListenerMouse* obj)->const std::function<void (cocos2d::EventMouse *)>&{return obj->onMouseDown;};
mt["set"]["OnMouseUp"]=[](cocos2d::EventListenerMouse* obj,const std::function<void (cocos2d::EventMouse *)>& value){obj->onMouseUp = value;};
mt["get"]["OnMouseUp"]=[](cocos2d::EventListenerMouse* obj)->const std::function<void (cocos2d::EventMouse *)>&{return obj->onMouseUp;};
mt["set"]["OnMouseMove"]=[](cocos2d::EventListenerMouse* obj,const std::function<void (cocos2d::EventMouse *)>& value){obj->onMouseMove = value;};
mt["get"]["OnMouseMove"]=[](cocos2d::EventListenerMouse* obj)->const std::function<void (cocos2d::EventMouse *)>&{return obj->onMouseMove;};
mt["set"]["OnMouseScroll"]=[](cocos2d::EventListenerMouse* obj,const std::function<void (cocos2d::EventMouse *)>& value){obj->onMouseScroll = value;};
mt["get"]["OnMouseScroll"]=[](cocos2d::EventListenerMouse* obj)->const std::function<void (cocos2d::EventMouse *)>&{return obj->onMouseScroll;};
}
void RegisterLuaCoreEventListenerControllerAuto(cocos2d::extension::Lua& lua){
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
void RegisterLuaCoreEventListenerTouchOneByOneAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerTouchOneByOne).name()] = sol::usertype_traits<cocos2d::EventListenerTouchOneByOne*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerTouchOneByOne>("deprecated.cocos2d::EventListenerTouchOneByOne");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerTouchOneByOne*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerTouchOneByOne"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerTouchOneByOne*(*)()>(&cocos2d::EventListenerTouchOneByOne::create);
mt["SetSwallowTouches"]=static_cast<void(cocos2d::EventListenerTouchOneByOne::*)(bool)>(&cocos2d::EventListenerTouchOneByOne::setSwallowTouches);
mt["set"]["SwallowTouches"]=mt["SetSwallowTouches"];
mt["IsSwallowTouches"]=static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::isSwallowTouches);
mt["get"]["SwallowTouches"]=mt["IsSwallowTouches"];
mt["static"]["get"]["LISTENER_ID"]=[]()->const std::string&{return cocos2d::EventListenerTouchOneByOne::LISTENER_ID;};
mt["set"]["OnTouchBegan"]=[](cocos2d::EventListenerTouchOneByOne* obj,const cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback& value){obj->onTouchBegan = value;};
mt["get"]["OnTouchBegan"]=[](cocos2d::EventListenerTouchOneByOne* obj)->const cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback&{return obj->onTouchBegan;};
mt["set"]["OnTouchMoved"]=[](cocos2d::EventListenerTouchOneByOne* obj,const cocos2d::EventListenerTouchOneByOne::ccTouchCallback& value){obj->onTouchMoved = value;};
mt["get"]["OnTouchMoved"]=[](cocos2d::EventListenerTouchOneByOne* obj)->const cocos2d::EventListenerTouchOneByOne::ccTouchCallback&{return obj->onTouchMoved;};
mt["set"]["OnTouchEnded"]=[](cocos2d::EventListenerTouchOneByOne* obj,const cocos2d::EventListenerTouchOneByOne::ccTouchCallback& value){obj->onTouchEnded = value;};
mt["get"]["OnTouchEnded"]=[](cocos2d::EventListenerTouchOneByOne* obj)->const cocos2d::EventListenerTouchOneByOne::ccTouchCallback&{return obj->onTouchEnded;};
mt["set"]["OnTouchCancelled"]=[](cocos2d::EventListenerTouchOneByOne* obj,const cocos2d::EventListenerTouchOneByOne::ccTouchCallback& value){obj->onTouchCancelled = value;};
mt["get"]["OnTouchCancelled"]=[](cocos2d::EventListenerTouchOneByOne* obj)->const cocos2d::EventListenerTouchOneByOne::ccTouchCallback&{return obj->onTouchCancelled;};
}
}
