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
#include "network/CCConnection.h"
void RegisterLuaCoreEventListenerTouchAllAtOnceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerTouchAllAtOnce).name()] = sol::usertype_traits<cocos2d::EventListenerTouchAllAtOnce*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerTouchAllAtOnce>("deprecated.cocos2d::EventListenerTouchAllAtOnce");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerTouchAllAtOnce*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerTouchAllAtOnce"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerTouchAllAtOnce*(*)()>(&cocos2d::EventListenerTouchAllAtOnce::create);
mt["get"]["LISTENER_ID"]=[](){return cocos2d::EventListenerTouchAllAtOnce::LISTENER_ID;};;
mt["get"]["OnTouchesBegan"]=[](cocos2d::EventListenerTouchAllAtOnce* obj){return obj->onTouchesBegan;};;
mt["get"]["OnTouchesMoved"]=[](cocos2d::EventListenerTouchAllAtOnce* obj){return obj->onTouchesMoved;};;
mt["get"]["OnTouchesEnded"]=[](cocos2d::EventListenerTouchAllAtOnce* obj){return obj->onTouchesEnded;};;
mt["get"]["OnTouchesCancelled"]=[](cocos2d::EventListenerTouchAllAtOnce* obj){return obj->onTouchesCancelled;};;
}
void RegisterLuaCoreEventControllerControllerEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["CONNECTION"]=cocos2d::EventController::ControllerEventType::CONNECTION;
enumTable["BUTTON_STATUS_CHANGED"]=cocos2d::EventController::ControllerEventType::BUTTON_STATUS_CHANGED;
enumTable["AXIS_STATUS_CHANGED"]=cocos2d::EventController::ControllerEventType::AXIS_STATUS_CHANGED;
lua["cc"]["EventController"]["static"]["ControllerEventType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreEventControllerAuto(cocos2d::extension::Lua& lua){
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
RegisterLuaCoreEventControllerControllerEventTypeAuto(lua);
}
void RegisterLuaCoreActionCameraAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionCamera).name()] = sol::usertype_traits<cocos2d::ActionCamera*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionCamera>("deprecated.cocos2d::ActionCamera");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionCamera*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["ActionCamera"]=mt;
mt["__new__"]=[](){return new cocos2d::ActionCamera();};
mt["SetEye"]=sol::overload(static_cast<void(cocos2d::ActionCamera::*)(float,float,float)>(&cocos2d::ActionCamera::setEye),static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setEye));
mt["set"]["Eye"]=mt["SetEye"];
mt["GetEye"]=static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getEye);
mt["get"]["Eye"]=mt["GetEye"];
mt["SetCenter"]=static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setCenter);
mt["set"]["Center"]=mt["SetCenter"];
mt["GetCenter"]=static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getCenter);
mt["get"]["Center"]=mt["GetCenter"];
mt["SetUp"]=static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setUp);
mt["set"]["Up"]=mt["SetUp"];
mt["GetUp"]=static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getUp);
mt["get"]["Up"]=mt["GetUp"];
}
void RegisterLuaCoreOrbitCameraAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::OrbitCamera).name()] = sol::usertype_traits<cocos2d::OrbitCamera*>::metatable();
auto dep=lua.new_usertype<cocos2d::OrbitCamera>("deprecated.cocos2d::OrbitCamera");
dep[sol::base_classes]=sol::bases<cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::OrbitCamera*>::metatable(),sol::usertype_traits<cocos2d::ActionCamera*>::metatable());
lua["cc"]["OrbitCamera"]=mt;
mt["__new__"]=static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create);
mt["SphericalRadius"]=static_cast<void(cocos2d::OrbitCamera::*)(float*,float*,float*)>(&cocos2d::OrbitCamera::sphericalRadius);
}
void RegisterLuaCorePointArrayAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PointArray).name()] = sol::usertype_traits<cocos2d::PointArray*>::metatable();
auto dep=lua.new_usertype<cocos2d::PointArray>("deprecated.cocos2d::PointArray");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PointArray*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["PointArray"]=mt;
mt["__new__"]=static_cast<cocos2d::PointArray*(*)(ssize_t)>(&cocos2d::PointArray::create);
mt["InitWithCapacity"]=static_cast<bool(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::initWithCapacity);
mt["AddControlPoint"]=static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&)>(&cocos2d::PointArray::addControlPoint);
mt["InsertControlPoint"]=static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::insertControlPoint);
mt["ReplaceControlPoint"]=static_cast<void(cocos2d::PointArray::*)(const cocos2d::Vec2&,ssize_t)>(&cocos2d::PointArray::replaceControlPoint);
mt["GetControlPointAtIndex"]=static_cast<const cocos2d::Vec2&(cocos2d::PointArray::*)(ssize_t)const>(&cocos2d::PointArray::getControlPointAtIndex);
mt["RemoveControlPointAtIndex"]=static_cast<void(cocos2d::PointArray::*)(ssize_t)>(&cocos2d::PointArray::removeControlPointAtIndex);
mt["Count"]=static_cast<ssize_t(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::count);
mt["Reverse"]=static_cast<cocos2d::PointArray*(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::reverse);
mt["ReverseInline"]=static_cast<void(cocos2d::PointArray::*)()>(&cocos2d::PointArray::reverseInline);
mt["GetControlPoints"]=static_cast<const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&(cocos2d::PointArray::*)()const>(&cocos2d::PointArray::getControlPoints);
mt["get"]["ControlPoints"]=mt["GetControlPoints"];
mt["SetControlPoints"]=static_cast<void(cocos2d::PointArray::*)(std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >)>(&cocos2d::PointArray::setControlPoints);
mt["set"]["ControlPoints"]=mt["SetControlPoints"];
}
void RegisterLuaCoreCardinalSplineToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CardinalSplineTo).name()] = sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::CardinalSplineTo>("deprecated.cocos2d::CardinalSplineTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["CardinalSplineTo"]=mt;
mt["__new__"]=static_cast<cocos2d::CardinalSplineTo*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration);
mt["UpdatePosition"]=static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition);
mt["GetPoints"]=static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints);
mt["get"]["Points"]=mt["GetPoints"];
mt["SetPoints"]=static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::PointArray*)>(&cocos2d::CardinalSplineTo::setPoints);
mt["set"]["Points"]=mt["SetPoints"];
}
void RegisterLuaCoreCardinalSplineByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CardinalSplineBy).name()] = sol::usertype_traits<cocos2d::CardinalSplineBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::CardinalSplineBy>("deprecated.cocos2d::CardinalSplineBy");
dep[sol::base_classes]=sol::bases<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CardinalSplineBy*>::metatable(),sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable());
lua["cc"]["CardinalSplineBy"]=mt;
mt["__new__"]=static_cast<cocos2d::CardinalSplineBy*(*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineBy::create);
}
void RegisterLuaCoreCatmullRomToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CatmullRomTo).name()] = sol::usertype_traits<cocos2d::CatmullRomTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::CatmullRomTo>("deprecated.cocos2d::CatmullRomTo");
dep[sol::base_classes]=sol::bases<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CatmullRomTo*>::metatable(),sol::usertype_traits<cocos2d::CardinalSplineTo*>::metatable());
lua["cc"]["CatmullRomTo"]=mt;
mt["__new__"]=static_cast<cocos2d::CatmullRomTo*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration);
}
void RegisterLuaCoreCatmullRomByAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CatmullRomBy).name()] = sol::usertype_traits<cocos2d::CatmullRomBy*>::metatable();
auto dep=lua.new_usertype<cocos2d::CatmullRomBy>("deprecated.cocos2d::CatmullRomBy");
dep[sol::base_classes]=sol::bases<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CatmullRomBy*>::metatable(),sol::usertype_traits<cocos2d::CardinalSplineBy*>::metatable());
lua["cc"]["CatmullRomBy"]=mt;
mt["__new__"]=static_cast<cocos2d::CatmullRomBy*(*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::create);
mt["InitWithDuration"]=static_cast<bool(cocos2d::CatmullRomBy::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::initWithDuration);
}
void RegisterLuaCoreActionEaseAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionEase).name()] = sol::usertype_traits<cocos2d::ActionEase*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionEase>("deprecated.cocos2d::ActionEase");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionEase*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["ActionEase"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::getInnerAction);
mt["get"]["InnerAction"]=mt["GetInnerAction"];
}
