#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsJointDistanceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointDistance>("cc","PhysicsJointDistance",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointDistance*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointDistance::construct));
mt.set_function("GetDistance",static_cast<float(cocos2d::PhysicsJointDistance::*)()const>(&cocos2d::PhysicsJointDistance::getDistance));
mt.set_function("SetDistance",static_cast<void(cocos2d::PhysicsJointDistance::*)(float)>(&cocos2d::PhysicsJointDistance::setDistance));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointDistance::*)()>(&cocos2d::PhysicsJointDistance::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointSpringAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointSpring>("cc","PhysicsJointSpring",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointSpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointSpring::construct));
mt.set_function("GetAnchr1",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr1));
mt.set_function("SetAnchr1",static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr1));
mt.set_function("GetAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr2));
mt.set_function("SetAnchr2",static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr2));
mt.set_function("GetRestLength",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getRestLength));
mt.set_function("SetRestLength",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setRestLength));
mt.set_function("GetStiffness",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getStiffness));
mt.set_function("SetStiffness",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setStiffness));
mt.set_function("GetDamping",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getDamping));
mt.set_function("SetDamping",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setDamping));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointSpring::*)()>(&cocos2d::PhysicsJointSpring::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointGrooveAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointGroove>("cc","PhysicsJointGroove",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointGroove*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::construct));
mt.set_function("GetGrooveA",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveA));
mt.set_function("SetGrooveA",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveA));
mt.set_function("GetGrooveB",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveB));
mt.set_function("SetGrooveB",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveB));
mt.set_function("GetAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getAnchr2));
mt.set_function("SetAnchr2",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setAnchr2));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointGroove::*)()>(&cocos2d::PhysicsJointGroove::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointRotarySpringAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotarySpring>("cc","PhysicsJointRotarySpring",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointRotarySpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotarySpring::construct));
mt.set_function("GetRestAngle",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getRestAngle));
mt.set_function("SetRestAngle",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setRestAngle));
mt.set_function("GetStiffness",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getStiffness));
mt.set_function("SetStiffness",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setStiffness));
mt.set_function("GetDamping",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getDamping));
mt.set_function("SetDamping",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setDamping));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointRotarySpring::*)()>(&cocos2d::PhysicsJointRotarySpring::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointRotaryLimitAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotaryLimit>("cc","PhysicsJointRotaryLimit",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",sol::overload(static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::PhysicsJointRotaryLimit::construct),static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotaryLimit::construct)));
mt.set_function("GetMin",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMin));
mt.set_function("SetMin",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMin));
mt.set_function("GetMax",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMax));
mt.set_function("SetMax",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMax));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointRotaryLimit::*)()>(&cocos2d::PhysicsJointRotaryLimit::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointRatchetAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRatchet>("cc","PhysicsJointRatchet",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointRatchet*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRatchet::construct));
mt.set_function("GetAngle",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getAngle));
mt.set_function("SetAngle",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setAngle));
mt.set_function("GetPhase",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getPhase));
mt.set_function("SetPhase",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setPhase));
mt.set_function("GetRatchet",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getRatchet));
mt.set_function("SetRatchet",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setRatchet));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointRatchet::*)()>(&cocos2d::PhysicsJointRatchet::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointGearAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointGear>("cc","PhysicsJointGear",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointGear*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointGear::construct));
mt.set_function("GetPhase",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getPhase));
mt.set_function("SetPhase",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setPhase));
mt.set_function("GetRatio",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getRatio));
mt.set_function("SetRatio",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setRatio));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointGear::*)()>(&cocos2d::PhysicsJointGear::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointMotorAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointMotor>("cc","PhysicsJointMotor",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointMotor*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float)>(&cocos2d::PhysicsJointMotor::construct));
mt.set_function("GetRate",static_cast<float(cocos2d::PhysicsJointMotor::*)()const>(&cocos2d::PhysicsJointMotor::getRate));
mt.set_function("SetRate",static_cast<void(cocos2d::PhysicsJointMotor::*)(float)>(&cocos2d::PhysicsJointMotor::setRate));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointMotor::*)()>(&cocos2d::PhysicsJointMotor::createConstraints));
}
void RegisterLuaPhysicsPhysicsWorldAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsWorld>("cc","PhysicsWorld",true);
mt.set_function("AddJoint",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsJoint*)>(&cocos2d::PhysicsWorld::addJoint));
mt.set_function("RemoveJoint",sol::overload([](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0){return obj->removeJoint(arg0);},[](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0,bool arg1){return obj->removeJoint(arg0,arg1);}));
mt.set_function("RemoveAllJoints",sol::overload([](cocos2d::PhysicsWorld* obj){return obj->removeAllJoints();},[](cocos2d::PhysicsWorld* obj,bool arg0){return obj->removeAllJoints(arg0);}));
mt.set_function("RemoveBody",sol::overload(static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::removeBody),static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsBody*)>(&cocos2d::PhysicsWorld::removeBody)));
mt.set_function("RemoveAllBodies",static_cast<void(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::removeAllBodies));
mt.set_function("RayCast",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsRayCastCallbackFunc,const cocos2d::Vec2&,const cocos2d::Vec2&,void*)>(&cocos2d::PhysicsWorld::rayCast));
mt.set_function("QueryRect",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsQueryRectCallbackFunc,const cocos2d::Rect&,void*)>(&cocos2d::PhysicsWorld::queryRect));
mt.set_function("QueryPoint",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsQueryPointCallbackFunc,const cocos2d::Vec2&,void*)>(&cocos2d::PhysicsWorld::queryPoint));
mt.set_function("GetShapes",static_cast<cocos2d::Vector<cocos2d::PhysicsShape *>(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShapes));
mt.set_function("GetShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShape));
mt.set_function("GetAllBodies",static_cast<const cocos2d::Vector<cocos2d::PhysicsBody *>&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getAllBodies));
mt.set_function("GetBody",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsWorld::*)(int)const>(&cocos2d::PhysicsWorld::getBody));
mt.set_function("GetScene",static_cast<cocos2d::Scene&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getScene));
mt.set_function("GetGravity",static_cast<cocos2d::Vec2(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getGravity));
mt.set_function("SetGravity",static_cast<void(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsWorld::setGravity));
mt.set_function("SetSpeed",static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::setSpeed));
mt.set_function("GetSpeed",static_cast<float(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getSpeed));
mt.set_function("SetUpdateRate",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setUpdateRate));
mt.set_function("GetUpdateRate",static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getUpdateRate));
mt.set_function("SetSubsteps",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setSubsteps));
mt.set_function("GetSubsteps",static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getSubsteps));
mt.set_function("SetFixedUpdateRate",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setFixedUpdateRate));
mt.set_function("GetFixedUpdateRate",static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getFixedUpdateRate));
mt.set_function("SetDebugDrawMask",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setDebugDrawMask));
mt.set_function("SetPreUpdateCallback",static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPreUpdateCallback));
mt.set_function("SetPostUpdateCallback",static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPostUpdateCallback));
mt.set_function("GetDebugDrawMask",static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getDebugDrawMask));
mt.set_function("SetAutoStep",static_cast<void(cocos2d::PhysicsWorld::*)(bool)>(&cocos2d::PhysicsWorld::setAutoStep));
mt.set_function("IsAutoStep",static_cast<bool(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::isAutoStep));
mt.set_function("Step",static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::step));
mt["DEBUGDRAW_NONE"]=sol::var(std::ref(cocos2d::PhysicsWorld::DEBUGDRAW_NONE));
mt["DEBUGDRAW_SHAPE"]=sol::var(std::ref(cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE));
mt["DEBUGDRAW_JOINT"]=sol::var(std::ref(cocos2d::PhysicsWorld::DEBUGDRAW_JOINT));
mt["DEBUGDRAW_CONTACT"]=sol::var(std::ref(cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT));
mt["DEBUGDRAW_ALL"]=sol::var(std::ref(cocos2d::PhysicsWorld::DEBUGDRAW_ALL));
}
#endif
