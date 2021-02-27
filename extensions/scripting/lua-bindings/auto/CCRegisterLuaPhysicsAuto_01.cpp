#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeChain,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapeEdgeChain",false);
ns["PhysicsShapeEdgeChain"] = mt;
lua["PhysicsShapeEdgeChain"] = sol::nil;
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeChain::*)()>(&cocos2d::PhysicsShapeEdgeChain::getCenter));
mt.set_function("getPoints",static_cast<void(cocos2d::PhysicsShapeEdgeChain::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapeEdgeChain::getPoints));
mt.set_function("getPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgeChain::*)()const>(&cocos2d::PhysicsShapeEdgeChain::getPointsCount));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgeChain* obj,const cocos2d::Vec2* arg0,int arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeChain* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeChain* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsBodyAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsBody,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("PhysicsBody",false);
ns["PhysicsBody"] = mt;
lua["PhysicsBody"] = sol::nil;
mt.set_function("addShape",sol::overload([](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->addShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->addShape(arg0,arg1);}));
mt.set_function("removeShape",sol::overload([](cocos2d::PhysicsBody* obj,int arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,int arg0,bool arg1){return obj->removeShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->removeShape(arg0,arg1);}));
mt.set_function("removeAllShapes",sol::overload([](cocos2d::PhysicsBody* obj){return obj->removeAllShapes();},[](cocos2d::PhysicsBody* obj,bool arg0){return obj->removeAllShapes(arg0);}));
mt.set_function("getShapes",static_cast<const cocos2d::Vector<cocos2d::PhysicsShape *>&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getShapes));
mt.set_function("getFirstShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getFirstShape));
mt.set_function("getShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)(int)const>(&cocos2d::PhysicsBody::getShape));
mt.set_function("applyForce",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyForce(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyForce(arg0,arg1);}));
mt.set_function("resetForces",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::resetForces));
mt.set_function("applyImpulse",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyImpulse(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyImpulse(arg0,arg1);}));
mt.set_function("applyTorque",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::applyTorque));
mt.set_function("setVelocity",static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setVelocity));
mt.set_function("getVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocity));
mt.set_function("setAngularVelocity",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocity));
mt.set_function("getVelocityAtLocalPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtLocalPoint));
mt.set_function("getVelocityAtWorldPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtWorldPoint));
mt.set_function("getAngularVelocity",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocity));
mt.set_function("setVelocityLimit",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setVelocityLimit));
mt.set_function("getVelocityLimit",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocityLimit));
mt.set_function("setAngularVelocityLimit",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocityLimit));
mt.set_function("getAngularVelocityLimit",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocityLimit));
mt.set_function("removeFromWorld",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::removeFromWorld));
mt.set_function("getWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getWorld));
mt.set_function("getJoints",static_cast<const std::vector<cocos2d::PhysicsJoint *>&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getJoints));
mt.set_function("getNode",static_cast<cocos2d::Node*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getNode));
mt.set_function("setCategoryBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCategoryBitmask));
mt.set_function("setContactTestBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setContactTestBitmask));
mt.set_function("setCollisionBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCollisionBitmask));
mt.set_function("getCategoryBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCategoryBitmask));
mt.set_function("getContactTestBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getContactTestBitmask));
mt.set_function("getCollisionBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCollisionBitmask));
mt.set_function("setGroup",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setGroup));
mt.set_function("getGroup",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getGroup));
mt.set_function("getPosition",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPosition));
mt.set_function("getRotation",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getRotation));
mt.set_function("setPositionOffset",static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setPositionOffset));
mt.set_function("getPositionOffset",static_cast<const cocos2d::Vec2&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPositionOffset));
mt.set_function("setRotationOffset",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setRotationOffset));
mt.set_function("getRotationOffset",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getRotationOffset));
mt.set_function("isDynamic",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isDynamic));
mt.set_function("setDynamic",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setDynamic));
mt.set_function("setMass",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMass));
mt.set_function("getMass",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMass));
mt.set_function("addMass",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMass));
mt.set_function("setMoment",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMoment));
mt.set_function("getMoment",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMoment));
mt.set_function("addMoment",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMoment));
mt.set_function("getLinearDamping",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getLinearDamping));
mt.set_function("setLinearDamping",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setLinearDamping));
mt.set_function("getAngularDamping",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getAngularDamping));
mt.set_function("setAngularDamping",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularDamping));
mt.set_function("isResting",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isResting));
mt.set_function("setResting",static_cast<void(cocos2d::PhysicsBody::*)(bool)const>(&cocos2d::PhysicsBody::setResting));
mt.set_function("setEnabled",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setEnabled));
mt.set_function("isRotationEnabled",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isRotationEnabled));
mt.set_function("setRotationEnable",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setRotationEnable));
mt.set_function("isGravityEnabled",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isGravityEnabled));
mt.set_function("setGravityEnable",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setGravityEnable));
mt.set_function("getTag",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getTag));
mt.set_function("setTag",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setTag));
mt.set_function("world2Local",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::world2Local));
mt.set_function("local2World",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::local2World));
mt.set_function("onEnter",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onExit));
mt.set_function("onAdd",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onAdd));
mt.set_function("onRemove",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onRemove));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::PhysicsBody*(*)(float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)()>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)(float,float)>(&cocos2d::PhysicsBody::create)));
mt.set_function("createCircle",sol::overload([](cocos2d::PhysicsBody* obj,float arg0){return obj->createCircle(arg0);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createCircle(arg0,arg1);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createCircle(arg0,arg1,arg2);}));
mt.set_function("createBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createBox(arg0,arg1,arg2);}));
mt.set_function("createPolygon",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1){return obj->createPolygon(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createPolygon(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3){return obj->createPolygon(arg0,arg1,arg2,arg3);}));
mt.set_function("createEdgeSegment",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->createEdgeSegment(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeSegment(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeSegment(arg0,arg1,arg2,arg3);}));
mt.set_function("createEdgeBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createEdgeBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createEdgeBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->createEdgeBox(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->createEdgeBox(arg0,arg1,arg2,arg3);}));
mt.set_function("createEdgePolygon",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1){return obj->createEdgePolygon(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgePolygon(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgePolygon(arg0,arg1,arg2,arg3);}));
mt.set_function("createEdgeChain",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1){return obj->createEdgeChain(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeChain(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeChain(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsAnonymousEnum__5467860361024739651_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["CCZ_COMPRESSION_ZLIB"] = 0;
pTable["CCZ_COMPRESSION_BZIP2"] = 1;
pTable["CCZ_COMPRESSION_GZIP"] = 2;
pTable["CCZ_COMPRESSION_NONE"] = 3;
}
void RegisterLuaPhysicsPhysicsContactEventCodeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["PhysicsContact"];
pTable.new_enum("EventCode"
,"NONE",0
,"BEGIN",1
,"PRESOLVE",2
,"POSTSOLVE",3
,"SEPARATE",4
);}
void RegisterLuaPhysicsPhysicsContactAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsContact,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("PhysicsContact",true);
ns["PhysicsContact"] = mt;
lua["PhysicsContact"] = sol::nil;
mt.set_function("getShapeA",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeA));
mt.set_function("getShapeB",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeB));
mt.set_function("getContactData",static_cast<const cocos2d::PhysicsContactData*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getContactData));
mt.set_function("getPreContactData",static_cast<const cocos2d::PhysicsContactData*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getPreContactData));
mt.set_function("getData",static_cast<void*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getData));
mt.set_function("setData",static_cast<void(cocos2d::PhysicsContact::*)(void*)>(&cocos2d::PhysicsContact::setData));
mt.set_function("getEventCode",static_cast<cocos2d::PhysicsContact::EventCode(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getEventCode));
RegisterLuaPhysicsPhysicsContactEventCodeAuto(lua);
}
void RegisterLuaPhysicsPhysicsContactPreSolveAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsContactPreSolve>("PhysicsContactPreSolve",true);
ns["PhysicsContactPreSolve"] = mt;
lua["PhysicsContactPreSolve"] = sol::nil;
mt.set_function("getRestitution",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getRestitution));
mt.set_function("getFriction",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getFriction));
mt.set_function("getSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getSurfaceVelocity));
mt.set_function("setRestitution",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setRestitution));
mt.set_function("setFriction",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setFriction));
mt.set_function("setSurfaceVelocity",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsContactPreSolve::setSurfaceVelocity));
mt.set_function("ignore",static_cast<void(cocos2d::PhysicsContactPreSolve::*)()>(&cocos2d::PhysicsContactPreSolve::ignore));
}
void RegisterLuaPhysicsPhysicsContactPostSolveAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsContactPostSolve>("PhysicsContactPostSolve",true);
ns["PhysicsContactPostSolve"] = mt;
lua["PhysicsContactPostSolve"] = sol::nil;
mt.set_function("getRestitution",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getRestitution));
mt.set_function("getFriction",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getFriction));
mt.set_function("getSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getSurfaceVelocity));
}
void RegisterLuaPhysicsEventListenerPhysicsContactAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerPhysicsContact",false);
ns["EventListenerPhysicsContact"] = mt;
lua["EventListenerPhysicsContact"] = sol::nil;
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContact*(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContact*(*)()>(&cocos2d::EventListenerPhysicsContact::create));
mt["onContactBegin"] = &cocos2d::EventListenerPhysicsContact::onContactBegin;
mt["onContactPreSolve"] = &cocos2d::EventListenerPhysicsContact::onContactPreSolve;
mt["onContactPostSolve"] = &cocos2d::EventListenerPhysicsContact::onContactPostSolve;
mt["onContactSeparate"] = &cocos2d::EventListenerPhysicsContact::onContactSeparate;
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithBodies,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerPhysicsContactWithBodies",false);
ns["EventListenerPhysicsContactWithBodies"] = mt;
lua["EventListenerPhysicsContactWithBodies"] = sol::nil;
mt.set_function("hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithBodies::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithBodies::hitTest));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(cocos2d::EventListenerPhysicsContactWithBodies::*)()>(&cocos2d::EventListenerPhysicsContactWithBodies::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::EventListenerPhysicsContactWithBodies::create));
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithShapes,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerPhysicsContactWithShapes",false);
ns["EventListenerPhysicsContactWithShapes"] = mt;
lua["EventListenerPhysicsContactWithShapes"] = sol::nil;
mt.set_function("hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithShapes::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::hitTest));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(cocos2d::EventListenerPhysicsContactWithShapes::*)()>(&cocos2d::EventListenerPhysicsContactWithShapes::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::create));
}
void RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithGroup,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerPhysicsContactWithGroup",false);
ns["EventListenerPhysicsContactWithGroup"] = mt;
lua["EventListenerPhysicsContactWithGroup"] = sol::nil;
mt.set_function("hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithGroup::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithGroup::hitTest));
mt.set_function("clone",static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(cocos2d::EventListenerPhysicsContactWithGroup::*)()>(&cocos2d::EventListenerPhysicsContactWithGroup::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(*)(int)>(&cocos2d::EventListenerPhysicsContactWithGroup::create));
}
#endif
