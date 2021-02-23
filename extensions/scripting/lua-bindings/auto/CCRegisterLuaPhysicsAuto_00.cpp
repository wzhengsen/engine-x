#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsShapeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShape");
mt.set_function("getBody",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getBody));
mt.set_function("getType",static_cast<cocos2d::PhysicsShape::Type(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getType));
mt.set_function("getArea",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getArea));
mt.set_function("getMoment",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMoment));
mt.set_function("setMoment",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMoment));
mt.set_function("setTag",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setTag));
mt.set_function("getTag",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getTag));
mt.set_function("getMass",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMass));
mt.set_function("setMass",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMass));
mt.set_function("getDensity",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getDensity));
mt.set_function("setDensity",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setDensity));
mt.set_function("getRestitution",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getRestitution));
mt.set_function("setRestitution",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setRestitution));
mt.set_function("getFriction",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getFriction));
mt.set_function("setFriction",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setFriction));
mt.set_function("getMaterial",static_cast<const cocos2d::PhysicsMaterial&(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMaterial));
mt.set_function("setMaterial",static_cast<void(cocos2d::PhysicsShape::*)(const cocos2d::PhysicsMaterial&)>(&cocos2d::PhysicsShape::setMaterial));
mt.set_function("isSensor",static_cast<bool(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::isSensor));
mt.set_function("setSensor",static_cast<void(cocos2d::PhysicsShape::*)(bool)>(&cocos2d::PhysicsShape::setSensor));
mt.set_function("calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::calculateDefaultMoment));
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getOffset));
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getCenter));
mt.set_function("containsPoint",static_cast<bool(cocos2d::PhysicsShape::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsShape::containsPoint));
mt.set_function("setCategoryBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCategoryBitmask));
mt.set_function("getCategoryBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCategoryBitmask));
mt.set_function("setContactTestBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setContactTestBitmask));
mt.set_function("getContactTestBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getContactTestBitmask));
mt.set_function("setCollisionBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCollisionBitmask));
mt.set_function("getCollisionBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCollisionBitmask));
mt.set_function("setGroup",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setGroup));
mt.set_function("getGroup",static_cast<int(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getGroup));
}
void RegisterLuaPhysicsPhysicsShapeCircleAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeCircle,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeCircle");
mt.set_function("calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::calculateDefaultMoment));
mt.set_function("getRadius",static_cast<float(cocos2d::PhysicsShapeCircle::*)()const>(&cocos2d::PhysicsShapeCircle::getRadius));
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::getOffset));
mt.set_function("new",sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("calculateArea",static_cast<float(*)(float)>(&cocos2d::PhysicsShapeCircle::calculateArea));
mt.set_function("calculateMoment",sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1){return obj->calculateMoment(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1,const cocos2d::Vec2& arg2){return obj->calculateMoment(arg0,arg1,arg2);}));
}
void RegisterLuaPhysicsPhysicsShapePolygonAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapePolygon");
mt.set_function("calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::calculateDefaultMoment));
mt.set_function("getPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)(int)const>(&cocos2d::PhysicsShapePolygon::getPoint));
mt.set_function("getPointsCount",static_cast<int(cocos2d::PhysicsShapePolygon::*)()const>(&cocos2d::PhysicsShapePolygon::getPointsCount));
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::getCenter));
}
void RegisterLuaPhysicsPhysicsShapeBoxAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeBox,cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeBox");
mt.set_function("getSize",static_cast<cocos2d::Size(cocos2d::PhysicsShapeBox::*)()const>(&cocos2d::PhysicsShapeBox::getSize));
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeBox::*)()>(&cocos2d::PhysicsShapeBox::getOffset));
mt.set_function("new",sol::overload([](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeSegment,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeSegment");
mt.set_function("getPointA",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointA));
mt.set_function("getPointB",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointB));
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()>(&cocos2d::PhysicsShapeEdgeSegment::getCenter));
mt.set_function("new",sol::overload([](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgePolygon");
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgePolygon::*)()>(&cocos2d::PhysicsShapeEdgePolygon::getCenter));
mt.set_function("getPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgePolygon::*)()const>(&cocos2d::PhysicsShapeEdgePolygon::getPointsCount));
}
void RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeBox,cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeBox");
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeBox::*)()>(&cocos2d::PhysicsShapeEdgeBox::getOffset));
mt.set_function("new",sol::overload([](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeChain,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeChain");
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeChain::*)()>(&cocos2d::PhysicsShapeEdgeChain::getCenter));
mt.set_function("getPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgeChain::*)()const>(&cocos2d::PhysicsShapeEdgeChain::getPointsCount));
}
void RegisterLuaPhysicsPhysicsBodyAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsBody,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsBody");
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
mt.set_function("new",sol::overload(static_cast<cocos2d::PhysicsBody*(*)(float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)()>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)(float,float)>(&cocos2d::PhysicsBody::create)));
mt.set_function("createCircle",sol::overload([](cocos2d::PhysicsBody* obj,float arg0){return obj->createCircle(arg0);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createCircle(arg0,arg1);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createCircle(arg0,arg1,arg2);}));
mt.set_function("createBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createBox(arg0,arg1,arg2);}));
mt.set_function("createEdgeSegment",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->createEdgeSegment(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeSegment(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeSegment(arg0,arg1,arg2,arg3);}));
mt.set_function("createEdgeBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createEdgeBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createEdgeBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->createEdgeBox(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->createEdgeBox(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsContactAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContact,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsContact");
mt.set_function("getShapeA",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeA));
mt.set_function("getShapeB",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeB));
mt.set_function("getEventCode",static_cast<cocos2d::PhysicsContact::EventCode(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getEventCode));
}
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
#endif
