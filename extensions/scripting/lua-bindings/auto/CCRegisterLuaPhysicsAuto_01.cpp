#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
namespace cocos2d{
void RegisterLuaPhysicsPhysicsContactPreSolveAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsContactPreSolve).name()] = sol::usertype_traits<cocos2d::PhysicsContactPreSolve*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsContactPreSolve>("deprecated.cocos2d::PhysicsContactPreSolve");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsContactPreSolve*>::metatable());
lua["cc"]["PhysicsContactPreSolve"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetRestitution"]=static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getRestitution);
mt["get"]["Restitution"]=mt["GetRestitution"];
mt["GetFriction"]=static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getFriction);
mt["get"]["Friction"]=mt["GetFriction"];
mt["GetSurfaceVelocity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getSurfaceVelocity);
mt["get"]["SurfaceVelocity"]=mt["GetSurfaceVelocity"];
mt["SetRestitution"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setRestitution);
mt["set"]["Restitution"]=mt["SetRestitution"];
mt["SetFriction"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setFriction);
mt["set"]["Friction"]=mt["SetFriction"];
mt["SetSurfaceVelocity"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsContactPreSolve::setSurfaceVelocity);
mt["set"]["SurfaceVelocity"]=mt["SetSurfaceVelocity"];
mt["Ignore"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)()>(&cocos2d::PhysicsContactPreSolve::ignore);
}
void RegisterLuaPhysicsPhysicsContactPostSolveAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsContactPostSolve).name()] = sol::usertype_traits<cocos2d::PhysicsContactPostSolve*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsContactPostSolve>("deprecated.cocos2d::PhysicsContactPostSolve");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsContactPostSolve*>::metatable());
lua["cc"]["PhysicsContactPostSolve"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetRestitution"]=static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getRestitution);
mt["get"]["Restitution"]=mt["GetRestitution"];
mt["GetFriction"]=static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getFriction);
mt["get"]["Friction"]=mt["GetFriction"];
mt["GetSurfaceVelocity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getSurfaceVelocity);
mt["get"]["SurfaceVelocity"]=mt["GetSurfaceVelocity"];
}
void RegisterLuaPhysicsEventListenerPhysicsContactAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerPhysicsContact).name()] = sol::usertype_traits<cocos2d::EventListenerPhysicsContact*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerPhysicsContact>("deprecated.cocos2d::EventListenerPhysicsContact");
dep[sol::base_classes]=sol::bases<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerPhysicsContact*>::metatable(),sol::usertype_traits<cocos2d::EventListenerCustom*>::metatable());
lua["cc"]["EventListenerPhysicsContact"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerPhysicsContact*(*)()>(&cocos2d::EventListenerPhysicsContact::create);
mt["set"]["OnContactBegin"]=[](cocos2d::EventListenerPhysicsContact* obj,const std::function<bool (cocos2d::PhysicsContact &)>& value){obj->onContactBegin = value;};
mt["get"]["OnContactBegin"]=[](cocos2d::EventListenerPhysicsContact* obj)->const std::function<bool (cocos2d::PhysicsContact &)>&{return obj->onContactBegin;};
mt["set"]["OnContactPreSolve"]=[](cocos2d::EventListenerPhysicsContact* obj,const std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)>& value){obj->onContactPreSolve = value;};
mt["get"]["OnContactPreSolve"]=[](cocos2d::EventListenerPhysicsContact* obj)->const std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)>&{return obj->onContactPreSolve;};
mt["set"]["OnContactPostSolve"]=[](cocos2d::EventListenerPhysicsContact* obj,const std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)>& value){obj->onContactPostSolve = value;};
mt["get"]["OnContactPostSolve"]=[](cocos2d::EventListenerPhysicsContact* obj)->const std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)>&{return obj->onContactPostSolve;};
mt["set"]["OnContactSeparate"]=[](cocos2d::EventListenerPhysicsContact* obj,const std::function<void (cocos2d::PhysicsContact &)>& value){obj->onContactSeparate = value;};
mt["get"]["OnContactSeparate"]=[](cocos2d::EventListenerPhysicsContact* obj)->const std::function<void (cocos2d::PhysicsContact &)>&{return obj->onContactSeparate;};
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerPhysicsContactWithBodies).name()] = sol::usertype_traits<cocos2d::EventListenerPhysicsContactWithBodies*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerPhysicsContactWithBodies>("deprecated.cocos2d::EventListenerPhysicsContactWithBodies");
dep[sol::base_classes]=sol::bases<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerPhysicsContactWithBodies*>::metatable(),sol::usertype_traits<cocos2d::EventListenerPhysicsContact*>::metatable());
lua["cc"]["EventListenerPhysicsContactWithBodies"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::EventListenerPhysicsContactWithBodies::create);
mt["HitTest"]=static_cast<bool(cocos2d::EventListenerPhysicsContactWithBodies::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithBodies::hitTest);
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerPhysicsContactWithShapes).name()] = sol::usertype_traits<cocos2d::EventListenerPhysicsContactWithShapes*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerPhysicsContactWithShapes>("deprecated.cocos2d::EventListenerPhysicsContactWithShapes");
dep[sol::base_classes]=sol::bases<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerPhysicsContactWithShapes*>::metatable(),sol::usertype_traits<cocos2d::EventListenerPhysicsContact*>::metatable());
lua["cc"]["EventListenerPhysicsContactWithShapes"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::create);
mt["HitTest"]=static_cast<bool(cocos2d::EventListenerPhysicsContactWithShapes::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::hitTest);
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerPhysicsContactWithGroup).name()] = sol::usertype_traits<cocos2d::EventListenerPhysicsContactWithGroup*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerPhysicsContactWithGroup>("deprecated.cocos2d::EventListenerPhysicsContactWithGroup");
dep[sol::base_classes]=sol::bases<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerPhysicsContactWithGroup*>::metatable(),sol::usertype_traits<cocos2d::EventListenerPhysicsContact*>::metatable());
lua["cc"]["EventListenerPhysicsContactWithGroup"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(*)(int)>(&cocos2d::EventListenerPhysicsContactWithGroup::create);
mt["HitTest"]=static_cast<bool(cocos2d::EventListenerPhysicsContactWithGroup::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithGroup::hitTest);
}
void RegisterLuaPhysicsPhysicsJointAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJoint).name()] = sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJoint>("deprecated.cocos2d::PhysicsJoint");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJoint"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetBodyA"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyA);
mt["get"]["BodyA"]=mt["GetBodyA"];
mt["GetBodyB"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyB);
mt["get"]["BodyB"]=mt["GetBodyB"];
mt["GetWorld"]=static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getWorld);
mt["get"]["World"]=mt["GetWorld"];
mt["GetTag"]=static_cast<int(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getTag);
mt["get"]["Tag"]=mt["GetTag"];
mt["SetTag"]=static_cast<void(cocos2d::PhysicsJoint::*)(int)>(&cocos2d::PhysicsJoint::setTag);
mt["set"]["Tag"]=mt["SetTag"];
mt["IsEnabled"]=static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isEnabled);
mt["get"]["Enabled"]=mt["IsEnabled"];
mt["SetEnable"]=static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setEnable);
mt["set"]["Enable"]=mt["SetEnable"];
mt["IsCollisionEnabled"]=static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isCollisionEnabled);
mt["get"]["CollisionEnabled"]=mt["IsCollisionEnabled"];
mt["SetCollisionEnabled"]=static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setCollisionEnabled);
mt["set"]["CollisionEnabled"]=mt["SetCollisionEnabled"];
mt["RemoveFormWorld"]=static_cast<void(cocos2d::PhysicsJoint::*)()>(&cocos2d::PhysicsJoint::removeFormWorld);
mt["SetMaxForce"]=static_cast<void(cocos2d::PhysicsJoint::*)(float)>(&cocos2d::PhysicsJoint::setMaxForce);
mt["set"]["MaxForce"]=mt["SetMaxForce"];
mt["GetMaxForce"]=static_cast<float(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getMaxForce);
mt["get"]["MaxForce"]=mt["GetMaxForce"];
}
void RegisterLuaPhysicsPhysicsJointFixedAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointFixed).name()] = sol::usertype_traits<cocos2d::PhysicsJointFixed*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointFixed>("deprecated.cocos2d::PhysicsJointFixed");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointFixed*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointFixed"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointFixed*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointFixed::construct);
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointFixed::*)()>(&cocos2d::PhysicsJointFixed::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointLimitAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointLimit).name()] = sol::usertype_traits<cocos2d::PhysicsJointLimit*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointLimit>("deprecated.cocos2d::PhysicsJointLimit");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointLimit*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointLimit"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=sol::overload(static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointLimit::construct),static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::construct));
mt["GetAnchr1"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr1);
mt["get"]["Anchr1"]=mt["GetAnchr1"];
mt["SetAnchr1"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr1);
mt["set"]["Anchr1"]=mt["SetAnchr1"];
mt["GetAnchr2"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr2);
mt["get"]["Anchr2"]=mt["GetAnchr2"];
mt["SetAnchr2"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr2);
mt["set"]["Anchr2"]=mt["SetAnchr2"];
mt["GetMin"]=static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMin);
mt["get"]["Min"]=mt["GetMin"];
mt["SetMin"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMin);
mt["set"]["Min"]=mt["SetMin"];
mt["GetMax"]=static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMax);
mt["get"]["Max"]=mt["GetMax"];
mt["SetMax"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMax);
mt["set"]["Max"]=mt["SetMax"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointLimit::*)()>(&cocos2d::PhysicsJointLimit::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointPinAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointPin).name()] = sol::usertype_traits<cocos2d::PhysicsJointPin*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointPin>("deprecated.cocos2d::PhysicsJointPin");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointPin*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointPin"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=sol::overload(static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct),static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct));
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointPin::*)()>(&cocos2d::PhysicsJointPin::createConstraints);
}
}
#endif
