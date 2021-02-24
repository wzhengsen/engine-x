#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsJointDistanceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointDistance,cocos2d::PhysicsJoint>("cc","PhysicsJointDistance");
mt.set_function("getDistance",static_cast<float(cocos2d::PhysicsJointDistance::*)()const>(&cocos2d::PhysicsJointDistance::getDistance));
mt.set_function("setDistance",static_cast<void(cocos2d::PhysicsJointDistance::*)(float)>(&cocos2d::PhysicsJointDistance::setDistance));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointDistance::*)()>(&cocos2d::PhysicsJointDistance::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointDistance*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointDistance::construct));
}
void RegisterLuaPhysicsPhysicsJointSpringAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointSpring,cocos2d::PhysicsJoint>("cc","PhysicsJointSpring");
mt.set_function("getAnchr1",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr1));
mt.set_function("setAnchr1",static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr1));
mt.set_function("getAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr2));
mt.set_function("setAnchr2",static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr2));
mt.set_function("getRestLength",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getRestLength));
mt.set_function("setRestLength",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setRestLength));
mt.set_function("getStiffness",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getStiffness));
mt.set_function("setStiffness",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setStiffness));
mt.set_function("getDamping",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getDamping));
mt.set_function("setDamping",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setDamping));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointSpring::*)()>(&cocos2d::PhysicsJointSpring::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointSpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointSpring::construct));
}
void RegisterLuaPhysicsPhysicsJointGrooveAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointGroove,cocos2d::PhysicsJoint>("cc","PhysicsJointGroove");
mt.set_function("getGrooveA",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveA));
mt.set_function("setGrooveA",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveA));
mt.set_function("getGrooveB",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveB));
mt.set_function("setGrooveB",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveB));
mt.set_function("getAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getAnchr2));
mt.set_function("setAnchr2",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setAnchr2));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointGroove::*)()>(&cocos2d::PhysicsJointGroove::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointGroove*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::construct));
}
void RegisterLuaPhysicsPhysicsJointRotarySpringAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotarySpring,cocos2d::PhysicsJoint>("cc","PhysicsJointRotarySpring");
mt.set_function("getRestAngle",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getRestAngle));
mt.set_function("setRestAngle",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setRestAngle));
mt.set_function("getStiffness",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getStiffness));
mt.set_function("setStiffness",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setStiffness));
mt.set_function("getDamping",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getDamping));
mt.set_function("setDamping",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setDamping));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointRotarySpring::*)()>(&cocos2d::PhysicsJointRotarySpring::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointRotarySpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotarySpring::construct));
}
void RegisterLuaPhysicsPhysicsJointRotaryLimitAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotaryLimit,cocos2d::PhysicsJoint>("cc","PhysicsJointRotaryLimit");
mt.set_function("getMin",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMin));
mt.set_function("setMin",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMin));
mt.set_function("getMax",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMax));
mt.set_function("setMax",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMax));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointRotaryLimit::*)()>(&cocos2d::PhysicsJointRotaryLimit::createConstraints));
mt.set_function("construct",sol::overload(static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::PhysicsJointRotaryLimit::construct),static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotaryLimit::construct)));
}
void RegisterLuaPhysicsPhysicsJointRatchetAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRatchet,cocos2d::PhysicsJoint>("cc","PhysicsJointRatchet");
mt.set_function("getAngle",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getAngle));
mt.set_function("setAngle",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setAngle));
mt.set_function("getPhase",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getPhase));
mt.set_function("setPhase",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setPhase));
mt.set_function("getRatchet",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getRatchet));
mt.set_function("setRatchet",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setRatchet));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointRatchet::*)()>(&cocos2d::PhysicsJointRatchet::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointRatchet*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRatchet::construct));
}
void RegisterLuaPhysicsPhysicsJointGearAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointGear,cocos2d::PhysicsJoint>("cc","PhysicsJointGear");
mt.set_function("getPhase",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getPhase));
mt.set_function("setPhase",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setPhase));
mt.set_function("getRatio",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getRatio));
mt.set_function("setRatio",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setRatio));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointGear::*)()>(&cocos2d::PhysicsJointGear::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointGear*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointGear::construct));
}
void RegisterLuaPhysicsPhysicsJointMotorAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointMotor,cocos2d::PhysicsJoint>("cc","PhysicsJointMotor");
mt.set_function("getRate",static_cast<float(cocos2d::PhysicsJointMotor::*)()const>(&cocos2d::PhysicsJointMotor::getRate));
mt.set_function("setRate",static_cast<void(cocos2d::PhysicsJointMotor::*)(float)>(&cocos2d::PhysicsJointMotor::setRate));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointMotor::*)()>(&cocos2d::PhysicsJointMotor::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointMotor*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float)>(&cocos2d::PhysicsJointMotor::construct));
}
void RegisterLuaPhysicsPhysicsWorldAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsWorld>("cc","PhysicsWorld");
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
#endif
