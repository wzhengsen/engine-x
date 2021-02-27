#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsJointAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJoint>("PhysicsJoint",true);
ns["PhysicsJoint"] = mt;
lua["PhysicsJoint"] = sol::nil;
mt.set_function("getBodyA",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyA));
mt.set_function("getBodyB",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyB));
mt.set_function("getWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getWorld));
mt.set_function("getTag",static_cast<int(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getTag));
mt.set_function("setTag",static_cast<void(cocos2d::PhysicsJoint::*)(int)>(&cocos2d::PhysicsJoint::setTag));
mt.set_function("isEnabled",static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isEnabled));
mt.set_function("setEnable",static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setEnable));
mt.set_function("isCollisionEnabled",static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isCollisionEnabled));
mt.set_function("setCollisionEnabled",static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setCollisionEnabled));
mt.set_function("removeFormWorld",static_cast<void(cocos2d::PhysicsJoint::*)()>(&cocos2d::PhysicsJoint::removeFormWorld));
mt.set_function("setMaxForce",static_cast<void(cocos2d::PhysicsJoint::*)(float)>(&cocos2d::PhysicsJoint::setMaxForce));
mt.set_function("getMaxForce",static_cast<float(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getMaxForce));
}
void RegisterLuaPhysicsPhysicsJointFixedAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointFixed,cocos2d::PhysicsJoint>("PhysicsJointFixed",true);
ns["PhysicsJointFixed"] = mt;
lua["PhysicsJointFixed"] = sol::nil;
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointFixed::*)()>(&cocos2d::PhysicsJointFixed::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointFixed*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointFixed::construct));
}
void RegisterLuaPhysicsPhysicsJointLimitAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointLimit,cocos2d::PhysicsJoint>("PhysicsJointLimit",true);
ns["PhysicsJointLimit"] = mt;
lua["PhysicsJointLimit"] = sol::nil;
mt.set_function("getAnchr1",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr1));
mt.set_function("setAnchr1",static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr1));
mt.set_function("getAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr2));
mt.set_function("setAnchr2",static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr2));
mt.set_function("getMin",static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMin));
mt.set_function("setMin",static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMin));
mt.set_function("getMax",static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMax));
mt.set_function("setMax",static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMax));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointLimit::*)()>(&cocos2d::PhysicsJointLimit::createConstraints));
mt.set_function("construct",sol::overload(static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointLimit::construct),static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::construct)));
}
void RegisterLuaPhysicsPhysicsJointPinAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointPin,cocos2d::PhysicsJoint>("PhysicsJointPin",true);
ns["PhysicsJointPin"] = mt;
lua["PhysicsJointPin"] = sol::nil;
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointPin::*)()>(&cocos2d::PhysicsJointPin::createConstraints));
mt.set_function("construct",sol::overload(static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct),static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct)));
}
void RegisterLuaPhysicsPhysicsJointDistanceAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointDistance,cocos2d::PhysicsJoint>("PhysicsJointDistance",true);
ns["PhysicsJointDistance"] = mt;
lua["PhysicsJointDistance"] = sol::nil;
mt.set_function("getDistance",static_cast<float(cocos2d::PhysicsJointDistance::*)()const>(&cocos2d::PhysicsJointDistance::getDistance));
mt.set_function("setDistance",static_cast<void(cocos2d::PhysicsJointDistance::*)(float)>(&cocos2d::PhysicsJointDistance::setDistance));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointDistance::*)()>(&cocos2d::PhysicsJointDistance::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointDistance*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointDistance::construct));
}
void RegisterLuaPhysicsPhysicsJointSpringAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointSpring,cocos2d::PhysicsJoint>("PhysicsJointSpring",true);
ns["PhysicsJointSpring"] = mt;
lua["PhysicsJointSpring"] = sol::nil;
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
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointGroove,cocos2d::PhysicsJoint>("PhysicsJointGroove",true);
ns["PhysicsJointGroove"] = mt;
lua["PhysicsJointGroove"] = sol::nil;
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
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotarySpring,cocos2d::PhysicsJoint>("PhysicsJointRotarySpring",true);
ns["PhysicsJointRotarySpring"] = mt;
lua["PhysicsJointRotarySpring"] = sol::nil;
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
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotaryLimit,cocos2d::PhysicsJoint>("PhysicsJointRotaryLimit",true);
ns["PhysicsJointRotaryLimit"] = mt;
lua["PhysicsJointRotaryLimit"] = sol::nil;
mt.set_function("getMin",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMin));
mt.set_function("setMin",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMin));
mt.set_function("getMax",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMax));
mt.set_function("setMax",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMax));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointRotaryLimit::*)()>(&cocos2d::PhysicsJointRotaryLimit::createConstraints));
mt.set_function("construct",sol::overload(static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::PhysicsJointRotaryLimit::construct),static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotaryLimit::construct)));
}
void RegisterLuaPhysicsPhysicsJointRatchetAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsJointRatchet,cocos2d::PhysicsJoint>("PhysicsJointRatchet",true);
ns["PhysicsJointRatchet"] = mt;
lua["PhysicsJointRatchet"] = sol::nil;
mt.set_function("getAngle",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getAngle));
mt.set_function("setAngle",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setAngle));
mt.set_function("getPhase",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getPhase));
mt.set_function("setPhase",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setPhase));
mt.set_function("getRatchet",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getRatchet));
mt.set_function("setRatchet",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setRatchet));
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointRatchet::*)()>(&cocos2d::PhysicsJointRatchet::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointRatchet*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRatchet::construct));
}
#endif
