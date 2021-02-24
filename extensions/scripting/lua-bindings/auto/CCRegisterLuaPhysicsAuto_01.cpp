#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsContactPreSolveAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContactPreSolve>("cc","PhysicsContactPreSolve");
mt.set_function("getRestitution",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getRestitution));
mt.set_function("getFriction",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getFriction));
mt.set_function("getSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getSurfaceVelocity));
mt.set_function("setRestitution",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setRestitution));
mt.set_function("setFriction",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setFriction));
mt.set_function("setSurfaceVelocity",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsContactPreSolve::setSurfaceVelocity));
mt.set_function("ignore",static_cast<void(cocos2d::PhysicsContactPreSolve::*)()>(&cocos2d::PhysicsContactPreSolve::ignore));
}
void RegisterLuaPhysicsPhysicsContactPostSolveAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContactPostSolve>("cc","PhysicsContactPostSolve");
mt.set_function("getRestitution",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getRestitution));
mt.set_function("getFriction",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getFriction));
mt.set_function("getSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getSurfaceVelocity));
}
void RegisterLuaPhysicsEventListenerPhysicsContactAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContact");
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContact*(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::clone));
mt.set_function("new",static_cast<cocos2d::EventListenerPhysicsContact*(*)()>(&cocos2d::EventListenerPhysicsContact::create));
mt["onContactBegin"] = &cocos2d::EventListenerPhysicsContact::onContactBegin;
mt["onContactPreSolve"] = &cocos2d::EventListenerPhysicsContact::onContactPreSolve;
mt["onContactPostSolve"] = &cocos2d::EventListenerPhysicsContact::onContactPostSolve;
mt["onContactSeparate"] = &cocos2d::EventListenerPhysicsContact::onContactSeparate;
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithBodies,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithBodies");
mt.set_function("hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithBodies::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithBodies::hitTest));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(cocos2d::EventListenerPhysicsContactWithBodies::*)()>(&cocos2d::EventListenerPhysicsContactWithBodies::clone));
mt.set_function("new",static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::EventListenerPhysicsContactWithBodies::create));
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithShapes,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithShapes");
mt.set_function("hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithShapes::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::hitTest));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(cocos2d::EventListenerPhysicsContactWithShapes::*)()>(&cocos2d::EventListenerPhysicsContactWithShapes::clone));
mt.set_function("new",static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::create));
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithGroup,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithGroup");
mt.set_function("hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithGroup::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithGroup::hitTest));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(cocos2d::EventListenerPhysicsContactWithGroup::*)()>(&cocos2d::EventListenerPhysicsContactWithGroup::clone));
mt.set_function("new",static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(*)(int)>(&cocos2d::EventListenerPhysicsContactWithGroup::create));
}
void RegisterLuaPhysicsPhysicsJointAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJoint>("cc","PhysicsJoint");
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
auto mt=lua.NewUserType<cocos2d::PhysicsJointFixed,cocos2d::PhysicsJoint>("cc","PhysicsJointFixed");
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointFixed::*)()>(&cocos2d::PhysicsJointFixed::createConstraints));
mt.set_function("construct",static_cast<cocos2d::PhysicsJointFixed*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointFixed::construct));
}
void RegisterLuaPhysicsPhysicsJointLimitAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointLimit,cocos2d::PhysicsJoint>("cc","PhysicsJointLimit");
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
auto mt=lua.NewUserType<cocos2d::PhysicsJointPin,cocos2d::PhysicsJoint>("cc","PhysicsJointPin");
mt.set_function("createConstraints",static_cast<bool(cocos2d::PhysicsJointPin::*)()>(&cocos2d::PhysicsJointPin::createConstraints));
mt.set_function("construct",sol::overload(static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct),static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct)));
}
#endif
