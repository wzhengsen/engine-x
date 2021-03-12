#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsJointGearAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointGear,cocos2d::PhysicsJoint>("PhysicsJointGear",true);
ns["PhysicsJointGear"] = mt;
lua["PhysicsJointGear"] = sol::nil;
mt.set_function("getPhase",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getPhase));
mt.set_function("setPhase",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setPhase));
mt.set_function("getRatio",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getRatio));
mt.set_function("setRatio",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setRatio));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointGear::*)()>(&cocos2d::PhysicsJointGear::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointGear*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointGear::construct));
}
void RegisterLuaPhysicsPhysicsJointMotorAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointMotor,cocos2d::PhysicsJoint>("PhysicsJointMotor",true);
ns["PhysicsJointMotor"] = mt;
lua["PhysicsJointMotor"] = sol::nil;
mt.set_function("getRate",static_cast<float(cocos2d::PhysicsJointMotor::*)()const>(&cocos2d::PhysicsJointMotor::getRate));
mt.set_function("setRate",static_cast<void(cocos2d::PhysicsJointMotor::*)(float)>(&cocos2d::PhysicsJointMotor::setRate));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointMotor::*)()>(&cocos2d::PhysicsJointMotor::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointMotor*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float)>(&cocos2d::PhysicsJointMotor::construct));
}
void RegisterLuaPhysicsPhysicsWorldAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsWorld>("PhysicsWorld",true);
ns["PhysicsWorld"] = mt;
lua["PhysicsWorld"] = sol::nil;
mt.set_function("addJoint",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsJoint*)>(&cocos2d::PhysicsWorld::addJoint));
mt.set_function("removeJoint",sol::overload([](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0){return obj->removeJoint(arg0);},[](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0,bool arg1){return obj->removeJoint(arg0,arg1);}));
mt.set_function("removeAllJoints",sol::overload([](cocos2d::PhysicsWorld* obj){return obj->removeAllJoints();},[](cocos2d::PhysicsWorld* obj,bool arg0){return obj->removeAllJoints(arg0);}));
mt.set_function("removeBody",sol::overload(static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::removeBody),static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsBody*)>(&cocos2d::PhysicsWorld::removeBody)));
mt.set_function("removeAllBodies",static_cast<void(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::removeAllBodies));
mt.set_function("rayCast",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsRayCastCallbackFunc,const cocos2d::Vec2&,const cocos2d::Vec2&,void*)>(&cocos2d::PhysicsWorld::rayCast));
mt.set_function("queryRect",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsQueryRectCallbackFunc,const cocos2d::Rect&,void*)>(&cocos2d::PhysicsWorld::queryRect));
mt.set_function("queryPoint",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsQueryPointCallbackFunc,const cocos2d::Vec2&,void*)>(&cocos2d::PhysicsWorld::queryPoint));
mt.set_function("getShapes",static_cast<cocos2d::Vector<cocos2d::PhysicsShape *>(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShapes));
mt.set_function("getShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShape));
mt.set_function("getAllBodies",static_cast<const cocos2d::Vector<cocos2d::PhysicsBody *>&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getAllBodies));
mt.set_function("getBody",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsWorld::*)(int)const>(&cocos2d::PhysicsWorld::getBody));
mt.set_function("getScene",static_cast<cocos2d::Scene&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getScene));
mt.set_function("getGravity",static_cast<cocos2d::Vec2(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getGravity));
mt.set_function("setGravity",static_cast<void(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsWorld::setGravity));
mt.set_function("setSpeed",static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::setSpeed));
mt.set_function("getSpeed",static_cast<float(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getSpeed));
mt.set_function("setUpdateRate",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setUpdateRate));
mt.set_function("getUpdateRate",static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getUpdateRate));
mt.set_function("setSubsteps",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setSubsteps));
mt.set_function("getSubsteps",static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getSubsteps));
mt.set_function("setFixedUpdateRate",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setFixedUpdateRate));
mt.set_function("getFixedUpdateRate",static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getFixedUpdateRate));
mt.set_function("setDebugDrawMask",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setDebugDrawMask));
mt.set_function("setPreUpdateCallback",static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPreUpdateCallback));
mt.set_function("setPostUpdateCallback",static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPostUpdateCallback));
mt.set_function("getDebugDrawMask",static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getDebugDrawMask));
mt.set_function("setAutoStep",static_cast<void(cocos2d::PhysicsWorld::*)(bool)>(&cocos2d::PhysicsWorld::setAutoStep));
mt.set_function("isAutoStep",static_cast<bool(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::isAutoStep));
mt.set_function("step",static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::step));
}
void RegisterLuaPhysicsAnonymousEnum__2064568361537248434_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXLayerAttribNone"] = 1;
pTable["TMXLayerAttribBase64"] = 2;
pTable["TMXLayerAttribGzip"] = 4;
pTable["TMXLayerAttribZlib"] = 8;
pTable["TMXLayerAttribCSV"] = 16;
}
void RegisterLuaPhysicsAnonymousEnum_6176446865269678677_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXPropertyNone"] = 0;
pTable["TMXPropertyMap"] = 1;
pTable["TMXPropertyLayer"] = 2;
pTable["TMXPropertyObjectGroup"] = 3;
pTable["TMXPropertyObject"] = 4;
pTable["TMXPropertyTile"] = 5;
pTable["TMXPropertyAnimation"] = 6;
}
void RegisterLuaPhysicsAnonymousEnum_6071847353538284064_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXOrientationOrtho"] = 0;
pTable["TMXOrientationHex"] = 1;
pTable["TMXOrientationIso"] = 2;
pTable["TMXOrientationStaggered"] = 3;
}
void RegisterLuaPhysicsAnonymousEnum_3937662979076660802_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXStaggerAxis_X"] = 0;
pTable["TMXStaggerAxis_Y"] = 1;
}
void RegisterLuaPhysicsAnonymousEnum__1091098247105229482_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXStaggerIndex_Odd"] = 0;
pTable["TMXStaggerIndex_Even"] = 1;
}
#endif
