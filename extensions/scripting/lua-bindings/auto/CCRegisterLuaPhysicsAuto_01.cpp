#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsContactPreSolveAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContactPreSolve>("cc","PhysicsContactPreSolve",true);
mt.set_function("GetRestitution",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getRestitution));
mt.set_function("GetFriction",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getFriction));
mt.set_function("GetSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getSurfaceVelocity));
mt.set_function("SetRestitution",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setRestitution));
mt.set_function("SetFriction",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setFriction));
mt.set_function("SetSurfaceVelocity",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsContactPreSolve::setSurfaceVelocity));
mt.set_function("Ignore",static_cast<void(cocos2d::PhysicsContactPreSolve::*)()>(&cocos2d::PhysicsContactPreSolve::ignore));
}
void RegisterLuaPhysicsPhysicsContactPostSolveAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContactPostSolve>("cc","PhysicsContactPostSolve",true);
mt.set_function("GetRestitution",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getRestitution));
mt.set_function("GetFriction",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getFriction));
mt.set_function("GetSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getSurfaceVelocity));
}
void RegisterLuaPhysicsEventListenerPhysicsContactAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContact>("cc","EventListenerPhysicsContact",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContact*(*)()>(&cocos2d::EventListenerPhysicsContact::create));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::checkAvailable));
mt.set_function("Clone",static_cast<cocos2d::EventListenerPhysicsContact*(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::clone));
mt["OnContactBegin"]=&cocos2d::EventListenerPhysicsContact::onContactBegin;
mt["OnContactPreSolve"]=&cocos2d::EventListenerPhysicsContact::onContactPreSolve;
mt["OnContactPostSolve"]=&cocos2d::EventListenerPhysicsContact::onContactPostSolve;
mt["OnContactSeparate"]=&cocos2d::EventListenerPhysicsContact::onContactSeparate;
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithBodies>("cc","EventListenerPhysicsContactWithBodies",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::EventListenerPhysicsContactWithBodies::create));
mt.set_function("HitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithBodies::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithBodies::hitTest));
mt.set_function("Clone",static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(cocos2d::EventListenerPhysicsContactWithBodies::*)()>(&cocos2d::EventListenerPhysicsContactWithBodies::clone));
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithShapes>("cc","EventListenerPhysicsContactWithShapes",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::create));
mt.set_function("HitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithShapes::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::hitTest));
mt.set_function("Clone",static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(cocos2d::EventListenerPhysicsContactWithShapes::*)()>(&cocos2d::EventListenerPhysicsContactWithShapes::clone));
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithGroup>("cc","EventListenerPhysicsContactWithGroup",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(*)(int)>(&cocos2d::EventListenerPhysicsContactWithGroup::create));
mt.set_function("HitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithGroup::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithGroup::hitTest));
mt.set_function("Clone",static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(cocos2d::EventListenerPhysicsContactWithGroup::*)()>(&cocos2d::EventListenerPhysicsContactWithGroup::clone));
}
void RegisterLuaPhysicsPhysicsJointAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJoint>("cc","PhysicsJoint",true);
mt.set_function("GetBodyA",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyA));
mt.set_function("GetBodyB",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyB));
mt.set_function("GetWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getWorld));
mt.set_function("GetTag",static_cast<int(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getTag));
mt.set_function("SetTag",static_cast<void(cocos2d::PhysicsJoint::*)(int)>(&cocos2d::PhysicsJoint::setTag));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isEnabled));
mt.set_function("SetEnable",static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setEnable));
mt.set_function("IsCollisionEnabled",static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isCollisionEnabled));
mt.set_function("SetCollisionEnabled",static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setCollisionEnabled));
mt.set_function("RemoveFormWorld",static_cast<void(cocos2d::PhysicsJoint::*)()>(&cocos2d::PhysicsJoint::removeFormWorld));
mt.set_function("SetMaxForce",static_cast<void(cocos2d::PhysicsJoint::*)(float)>(&cocos2d::PhysicsJoint::setMaxForce));
mt.set_function("GetMaxForce",static_cast<float(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getMaxForce));
}
void RegisterLuaPhysicsPhysicsJointFixedAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointFixed>("cc","PhysicsJointFixed",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",static_cast<cocos2d::PhysicsJointFixed*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointFixed::construct));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointFixed::*)()>(&cocos2d::PhysicsJointFixed::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointLimitAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointLimit>("cc","PhysicsJointLimit",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",sol::overload(static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointLimit::construct),static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::construct)));
mt.set_function("GetAnchr1",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr1));
mt.set_function("SetAnchr1",static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr1));
mt.set_function("GetAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr2));
mt.set_function("SetAnchr2",static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr2));
mt.set_function("GetMin",static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMin));
mt.set_function("SetMin",static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMin));
mt.set_function("GetMax",static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMax));
mt.set_function("SetMax",static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMax));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointLimit::*)()>(&cocos2d::PhysicsJointLimit::createConstraints));
}
void RegisterLuaPhysicsPhysicsJointPinAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointPin>("cc","PhysicsJointPin",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsJoint>());
mt.set_function("Construct",sol::overload(static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct),static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct)));
mt.set_function("CreateConstraints",static_cast<bool(cocos2d::PhysicsJointPin::*)()>(&cocos2d::PhysicsJointPin::createConstraints));
}
#endif
