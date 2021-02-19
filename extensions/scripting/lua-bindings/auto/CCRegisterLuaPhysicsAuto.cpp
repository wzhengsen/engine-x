#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#if CC_USE_PHYSICS
#include "cocos2d.h"
static void RegisterLuaPhysicsPhysicsShape(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShape");
mt["getBody"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getBody);
mt["getType"]=static_cast<cocos2d::PhysicsShape::Type(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getType);
mt["getArea"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getArea);
mt["getMoment"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMoment);
mt["setMoment"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMoment);
mt["setTag"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setTag);
mt["getTag"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getTag);
mt["getMass"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMass);
mt["setMass"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMass);
mt["getDensity"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getDensity);
mt["setDensity"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setDensity);
mt["getRestitution"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getRestitution);
mt["setRestitution"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setRestitution);
mt["getFriction"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getFriction);
mt["setFriction"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setFriction);
mt["getMaterial"]=static_cast<const cocos2d::PhysicsMaterial&(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMaterial);
mt["setMaterial"]=static_cast<void(cocos2d::PhysicsShape::*)(const cocos2d::PhysicsMaterial&)>(&cocos2d::PhysicsShape::setMaterial);
mt["isSensor"]=static_cast<bool(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::isSensor);
mt["setSensor"]=static_cast<void(cocos2d::PhysicsShape::*)(bool)>(&cocos2d::PhysicsShape::setSensor);
mt["calculateDefaultMoment"]=static_cast<float(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::calculateDefaultMoment);
mt["getOffset"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getOffset);
mt["getCenter"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getCenter);
mt["containsPoint"]=static_cast<bool(cocos2d::PhysicsShape::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsShape::containsPoint);
mt["setCategoryBitmask"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCategoryBitmask);
mt["getCategoryBitmask"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCategoryBitmask);
mt["setContactTestBitmask"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setContactTestBitmask);
mt["getContactTestBitmask"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getContactTestBitmask);
mt["setCollisionBitmask"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCollisionBitmask);
mt["getCollisionBitmask"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCollisionBitmask);
mt["setGroup"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setGroup);
mt["getGroup"]=static_cast<int(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getGroup);
}
static void RegisterLuaPhysicsPhysicsShapeCircle(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeCircle,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeCircle");
mt["calculateDefaultMoment"]=static_cast<float(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::calculateDefaultMoment);
mt["getRadius"]=static_cast<float(cocos2d::PhysicsShapeCircle::*)()const>(&cocos2d::PhysicsShapeCircle::getRadius);
mt["getOffset"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::getOffset);
mt["new"]=sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);});
mt["calculateArea"]=static_cast<float(*)(float)>(&cocos2d::PhysicsShapeCircle::calculateArea);
mt["calculateMoment"]=sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1){return obj->calculateMoment(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1,const cocos2d::Vec2& arg2){return obj->calculateMoment(arg0,arg1,arg2);});
}
static void RegisterLuaPhysicsPhysicsShapePolygon(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapePolygon");
mt["calculateDefaultMoment"]=static_cast<float(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::calculateDefaultMoment);
mt["getPoint"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)(int)const>(&cocos2d::PhysicsShapePolygon::getPoint);
mt["getPointsCount"]=static_cast<int(cocos2d::PhysicsShapePolygon::*)()const>(&cocos2d::PhysicsShapePolygon::getPointsCount);
mt["getCenter"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::getCenter);
}
static void RegisterLuaPhysicsPhysicsShapeBox(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeBox,cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeBox");
mt["getSize"]=static_cast<cocos2d::Size(cocos2d::PhysicsShapeBox::*)()const>(&cocos2d::PhysicsShapeBox::getSize);
mt["getOffset"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeBox::*)()>(&cocos2d::PhysicsShapeBox::getOffset);
mt["new"]=sol::overload([](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);});
}
static void RegisterLuaPhysicsPhysicsShapeEdgeSegment(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeSegment,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeSegment");
mt["getPointA"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointA);
mt["getPointB"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointB);
mt["getCenter"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()>(&cocos2d::PhysicsShapeEdgeSegment::getCenter);
mt["new"]=sol::overload([](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);});
}
static void RegisterLuaPhysicsPhysicsShapeEdgePolygon(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgePolygon");
mt["getCenter"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgePolygon::*)()>(&cocos2d::PhysicsShapeEdgePolygon::getCenter);
mt["getPointsCount"]=static_cast<int(cocos2d::PhysicsShapeEdgePolygon::*)()const>(&cocos2d::PhysicsShapeEdgePolygon::getPointsCount);
}
static void RegisterLuaPhysicsPhysicsShapeEdgeBox(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeBox,cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeBox");
mt["getOffset"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeBox::*)()>(&cocos2d::PhysicsShapeEdgeBox::getOffset);
mt["new"]=sol::overload([](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);});
}
static void RegisterLuaPhysicsPhysicsShapeEdgeChain(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeChain,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeChain");
mt["getCenter"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeChain::*)()>(&cocos2d::PhysicsShapeEdgeChain::getCenter);
mt["getPointsCount"]=static_cast<int(cocos2d::PhysicsShapeEdgeChain::*)()const>(&cocos2d::PhysicsShapeEdgeChain::getPointsCount);
}
static void RegisterLuaPhysicsPhysicsBody(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsBody,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsBody");
mt["addShape"]=sol::overload([](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->addShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->addShape(arg0,arg1);});
mt["removeShape"]=sol::overload([](cocos2d::PhysicsBody* obj,int arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,int arg0,bool arg1){return obj->removeShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->removeShape(arg0,arg1);});
mt["removeAllShapes"]=sol::overload([](cocos2d::PhysicsBody* obj){return obj->removeAllShapes();},[](cocos2d::PhysicsBody* obj,bool arg0){return obj->removeAllShapes(arg0);});
mt["getShapes"]=static_cast<const cocos2d::Vector<cocos2d::PhysicsShape *>&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getShapes);
mt["getFirstShape"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getFirstShape);
mt["getShape"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)(int)const>(&cocos2d::PhysicsBody::getShape);
mt["applyForce"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyForce(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyForce(arg0,arg1);});
mt["resetForces"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::resetForces);
mt["applyImpulse"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyImpulse(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyImpulse(arg0,arg1);});
mt["applyTorque"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::applyTorque);
mt["setVelocity"]=static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setVelocity);
mt["getVelocity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocity);
mt["setAngularVelocity"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocity);
mt["getVelocityAtLocalPoint"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtLocalPoint);
mt["getVelocityAtWorldPoint"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtWorldPoint);
mt["getAngularVelocity"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocity);
mt["setVelocityLimit"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setVelocityLimit);
mt["getVelocityLimit"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocityLimit);
mt["setAngularVelocityLimit"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocityLimit);
mt["getAngularVelocityLimit"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocityLimit);
mt["removeFromWorld"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::removeFromWorld);
mt["getWorld"]=static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getWorld);
mt["getNode"]=static_cast<cocos2d::Node*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getNode);
mt["setCategoryBitmask"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCategoryBitmask);
mt["setContactTestBitmask"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setContactTestBitmask);
mt["setCollisionBitmask"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCollisionBitmask);
mt["getCategoryBitmask"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCategoryBitmask);
mt["getContactTestBitmask"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getContactTestBitmask);
mt["getCollisionBitmask"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCollisionBitmask);
mt["setGroup"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setGroup);
mt["getGroup"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getGroup);
mt["getPosition"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPosition);
mt["getRotation"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getRotation);
mt["setPositionOffset"]=static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setPositionOffset);
mt["getPositionOffset"]=static_cast<const cocos2d::Vec2&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPositionOffset);
mt["setRotationOffset"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setRotationOffset);
mt["getRotationOffset"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getRotationOffset);
mt["isDynamic"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isDynamic);
mt["setDynamic"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setDynamic);
mt["setMass"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMass);
mt["getMass"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMass);
mt["addMass"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMass);
mt["setMoment"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMoment);
mt["getMoment"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMoment);
mt["addMoment"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMoment);
mt["getLinearDamping"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getLinearDamping);
mt["setLinearDamping"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setLinearDamping);
mt["getAngularDamping"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getAngularDamping);
mt["setAngularDamping"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularDamping);
mt["isResting"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isResting);
mt["setResting"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)const>(&cocos2d::PhysicsBody::setResting);
mt["setEnabled"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setEnabled);
mt["isRotationEnabled"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isRotationEnabled);
mt["setRotationEnable"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setRotationEnable);
mt["isGravityEnabled"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isGravityEnabled);
mt["setGravityEnable"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setGravityEnable);
mt["getTag"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getTag);
mt["setTag"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setTag);
mt["world2Local"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::world2Local);
mt["local2World"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::local2World);
mt["onEnter"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onEnter);
mt["onExit"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onExit);
mt["onAdd"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onAdd);
mt["onRemove"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onRemove);
mt["new"]=sol::overload(static_cast<cocos2d::PhysicsBody*(*)(float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)()>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)(float,float)>(&cocos2d::PhysicsBody::create));
mt["createCircle"]=sol::overload([](cocos2d::PhysicsBody* obj,float arg0){return obj->createCircle(arg0);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createCircle(arg0,arg1);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createCircle(arg0,arg1,arg2);});
mt["createBox"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createBox(arg0,arg1,arg2);});
mt["createEdgeSegment"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->createEdgeSegment(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeSegment(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeSegment(arg0,arg1,arg2,arg3);});
mt["createEdgeBox"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createEdgeBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createEdgeBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->createEdgeBox(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->createEdgeBox(arg0,arg1,arg2,arg3);});
}
static void RegisterLuaPhysicsPhysicsContact(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContact,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsContact");
mt["getShapeA"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeA);
mt["getShapeB"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeB);
mt["getEventCode"]=static_cast<cocos2d::PhysicsContact::EventCode(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getEventCode);
}
static void RegisterLuaPhysicsPhysicsContactPreSolve(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContactPreSolve>("cc","PhysicsContactPreSolve");
mt["getRestitution"]=static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getRestitution);
mt["getFriction"]=static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getFriction);
mt["getSurfaceVelocity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getSurfaceVelocity);
mt["setRestitution"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setRestitution);
mt["setFriction"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setFriction);
mt["setSurfaceVelocity"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsContactPreSolve::setSurfaceVelocity);
mt["ignore"]=static_cast<void(cocos2d::PhysicsContactPreSolve::*)()>(&cocos2d::PhysicsContactPreSolve::ignore);
}
static void RegisterLuaPhysicsPhysicsContactPostSolve(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContactPostSolve>("cc","PhysicsContactPostSolve");
mt["getRestitution"]=static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getRestitution);
mt["getFriction"]=static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getFriction);
mt["getSurfaceVelocity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getSurfaceVelocity);
}
static void RegisterLuaPhysicsEventListenerPhysicsContact(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContact");
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::checkAvailable);
mt["clone"]=static_cast<cocos2d::EventListenerPhysicsContact*(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::clone);
mt["new"]=static_cast<cocos2d::EventListenerPhysicsContact*(*)()>(&cocos2d::EventListenerPhysicsContact::create);
}
static void RegisterLuaPhysicsEventListenerPhysicsContactWithBodies(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithBodies,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithBodies");
mt["hitTest"]=static_cast<bool(cocos2d::EventListenerPhysicsContactWithBodies::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithBodies::hitTest);
mt["clone"]=static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(cocos2d::EventListenerPhysicsContactWithBodies::*)()>(&cocos2d::EventListenerPhysicsContactWithBodies::clone);
mt["new"]=static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::EventListenerPhysicsContactWithBodies::create);
}
static void RegisterLuaPhysicsEventListenerPhysicsContactWithShapes(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithShapes,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithShapes");
mt["hitTest"]=static_cast<bool(cocos2d::EventListenerPhysicsContactWithShapes::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::hitTest);
mt["clone"]=static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(cocos2d::EventListenerPhysicsContactWithShapes::*)()>(&cocos2d::EventListenerPhysicsContactWithShapes::clone);
mt["new"]=static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::create);
}
static void RegisterLuaPhysicsEventListenerPhysicsContactWithGroup(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerPhysicsContactWithGroup,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithGroup");
mt["hitTest"]=static_cast<bool(cocos2d::EventListenerPhysicsContactWithGroup::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithGroup::hitTest);
mt["clone"]=static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(cocos2d::EventListenerPhysicsContactWithGroup::*)()>(&cocos2d::EventListenerPhysicsContactWithGroup::clone);
mt["new"]=static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(*)(int)>(&cocos2d::EventListenerPhysicsContactWithGroup::create);
}
static void RegisterLuaPhysicsPhysicsJoint(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJoint>("cc","PhysicsJoint");
mt["getBodyA"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyA);
mt["getBodyB"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyB);
mt["getWorld"]=static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getWorld);
mt["getTag"]=static_cast<int(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getTag);
mt["setTag"]=static_cast<void(cocos2d::PhysicsJoint::*)(int)>(&cocos2d::PhysicsJoint::setTag);
mt["isEnabled"]=static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isEnabled);
mt["setEnable"]=static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setEnable);
mt["isCollisionEnabled"]=static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isCollisionEnabled);
mt["setCollisionEnabled"]=static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setCollisionEnabled);
mt["removeFormWorld"]=static_cast<void(cocos2d::PhysicsJoint::*)()>(&cocos2d::PhysicsJoint::removeFormWorld);
mt["setMaxForce"]=static_cast<void(cocos2d::PhysicsJoint::*)(float)>(&cocos2d::PhysicsJoint::setMaxForce);
mt["getMaxForce"]=static_cast<float(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getMaxForce);
}
static void RegisterLuaPhysicsPhysicsJointFixed(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointFixed,cocos2d::PhysicsJoint>("cc","PhysicsJointFixed");
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointFixed::*)()>(&cocos2d::PhysicsJointFixed::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointFixed*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointFixed::construct);
}
static void RegisterLuaPhysicsPhysicsJointLimit(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointLimit,cocos2d::PhysicsJoint>("cc","PhysicsJointLimit");
mt["getAnchr1"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr1);
mt["setAnchr1"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr1);
mt["getAnchr2"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr2);
mt["setAnchr2"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr2);
mt["getMin"]=static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMin);
mt["setMin"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMin);
mt["getMax"]=static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMax);
mt["setMax"]=static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMax);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointLimit::*)()>(&cocos2d::PhysicsJointLimit::createConstraints);
mt["construct"]=sol::overload(static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointLimit::construct),static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::construct));
}
static void RegisterLuaPhysicsPhysicsJointPin(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointPin,cocos2d::PhysicsJoint>("cc","PhysicsJointPin");
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointPin::*)()>(&cocos2d::PhysicsJointPin::createConstraints);
mt["construct"]=sol::overload(static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct),static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct));
}
static void RegisterLuaPhysicsPhysicsJointDistance(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointDistance,cocos2d::PhysicsJoint>("cc","PhysicsJointDistance");
mt["getDistance"]=static_cast<float(cocos2d::PhysicsJointDistance::*)()const>(&cocos2d::PhysicsJointDistance::getDistance);
mt["setDistance"]=static_cast<void(cocos2d::PhysicsJointDistance::*)(float)>(&cocos2d::PhysicsJointDistance::setDistance);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointDistance::*)()>(&cocos2d::PhysicsJointDistance::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointDistance*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointDistance::construct);
}
static void RegisterLuaPhysicsPhysicsJointSpring(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointSpring,cocos2d::PhysicsJoint>("cc","PhysicsJointSpring");
mt["getAnchr1"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr1);
mt["setAnchr1"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr1);
mt["getAnchr2"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr2);
mt["setAnchr2"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr2);
mt["getRestLength"]=static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getRestLength);
mt["setRestLength"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setRestLength);
mt["getStiffness"]=static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getStiffness);
mt["setStiffness"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setStiffness);
mt["getDamping"]=static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getDamping);
mt["setDamping"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setDamping);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointSpring::*)()>(&cocos2d::PhysicsJointSpring::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointSpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointSpring::construct);
}
static void RegisterLuaPhysicsPhysicsJointGroove(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointGroove,cocos2d::PhysicsJoint>("cc","PhysicsJointGroove");
mt["getGrooveA"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveA);
mt["setGrooveA"]=static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveA);
mt["getGrooveB"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveB);
mt["setGrooveB"]=static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveB);
mt["getAnchr2"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getAnchr2);
mt["setAnchr2"]=static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setAnchr2);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointGroove::*)()>(&cocos2d::PhysicsJointGroove::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointGroove*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::construct);
}
static void RegisterLuaPhysicsPhysicsJointRotarySpring(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotarySpring,cocos2d::PhysicsJoint>("cc","PhysicsJointRotarySpring");
mt["getRestAngle"]=static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getRestAngle);
mt["setRestAngle"]=static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setRestAngle);
mt["getStiffness"]=static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getStiffness);
mt["setStiffness"]=static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setStiffness);
mt["getDamping"]=static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getDamping);
mt["setDamping"]=static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setDamping);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointRotarySpring::*)()>(&cocos2d::PhysicsJointRotarySpring::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointRotarySpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotarySpring::construct);
}
static void RegisterLuaPhysicsPhysicsJointRotaryLimit(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRotaryLimit,cocos2d::PhysicsJoint>("cc","PhysicsJointRotaryLimit");
mt["getMin"]=static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMin);
mt["setMin"]=static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMin);
mt["getMax"]=static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMax);
mt["setMax"]=static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMax);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointRotaryLimit::*)()>(&cocos2d::PhysicsJointRotaryLimit::createConstraints);
mt["construct"]=sol::overload(static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::PhysicsJointRotaryLimit::construct),static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotaryLimit::construct));
}
static void RegisterLuaPhysicsPhysicsJointRatchet(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointRatchet,cocos2d::PhysicsJoint>("cc","PhysicsJointRatchet");
mt["getAngle"]=static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getAngle);
mt["setAngle"]=static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setAngle);
mt["getPhase"]=static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getPhase);
mt["setPhase"]=static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setPhase);
mt["getRatchet"]=static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getRatchet);
mt["setRatchet"]=static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setRatchet);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointRatchet::*)()>(&cocos2d::PhysicsJointRatchet::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointRatchet*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRatchet::construct);
}
static void RegisterLuaPhysicsPhysicsJointGear(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointGear,cocos2d::PhysicsJoint>("cc","PhysicsJointGear");
mt["getPhase"]=static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getPhase);
mt["setPhase"]=static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setPhase);
mt["getRatio"]=static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getRatio);
mt["setRatio"]=static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setRatio);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointGear::*)()>(&cocos2d::PhysicsJointGear::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointGear*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointGear::construct);
}
static void RegisterLuaPhysicsPhysicsJointMotor(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsJointMotor,cocos2d::PhysicsJoint>("cc","PhysicsJointMotor");
mt["getRate"]=static_cast<float(cocos2d::PhysicsJointMotor::*)()const>(&cocos2d::PhysicsJointMotor::getRate);
mt["setRate"]=static_cast<void(cocos2d::PhysicsJointMotor::*)(float)>(&cocos2d::PhysicsJointMotor::setRate);
mt["createConstraints"]=static_cast<bool(cocos2d::PhysicsJointMotor::*)()>(&cocos2d::PhysicsJointMotor::createConstraints);
mt["construct"]=static_cast<cocos2d::PhysicsJointMotor*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float)>(&cocos2d::PhysicsJointMotor::construct);
}
static void RegisterLuaPhysicsPhysicsWorld(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsWorld>("cc","PhysicsWorld");
mt["addJoint"]=static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsJoint*)>(&cocos2d::PhysicsWorld::addJoint);
mt["removeJoint"]=sol::overload([](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0){return obj->removeJoint(arg0);},[](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0,bool arg1){return obj->removeJoint(arg0,arg1);});
mt["removeAllJoints"]=sol::overload([](cocos2d::PhysicsWorld* obj){return obj->removeAllJoints();},[](cocos2d::PhysicsWorld* obj,bool arg0){return obj->removeAllJoints(arg0);});
mt["removeBody"]=sol::overload(static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::removeBody),static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsBody*)>(&cocos2d::PhysicsWorld::removeBody));
mt["removeAllBodies"]=static_cast<void(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::removeAllBodies);
mt["getShapes"]=static_cast<cocos2d::Vector<cocos2d::PhysicsShape *>(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShapes);
mt["getShape"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShape);
mt["getAllBodies"]=static_cast<const cocos2d::Vector<cocos2d::PhysicsBody *>&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getAllBodies);
mt["getBody"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsWorld::*)(int)const>(&cocos2d::PhysicsWorld::getBody);
mt["getGravity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getGravity);
mt["setGravity"]=static_cast<void(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsWorld::setGravity);
mt["setSpeed"]=static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::setSpeed);
mt["getSpeed"]=static_cast<float(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getSpeed);
mt["setUpdateRate"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setUpdateRate);
mt["getUpdateRate"]=static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getUpdateRate);
mt["setSubsteps"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setSubsteps);
mt["getSubsteps"]=static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getSubsteps);
mt["setFixedUpdateRate"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setFixedUpdateRate);
mt["getFixedUpdateRate"]=static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getFixedUpdateRate);
mt["setDebugDrawMask"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setDebugDrawMask);
mt["setPreUpdateCallback"]=static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPreUpdateCallback);
mt["setPostUpdateCallback"]=static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPostUpdateCallback);
mt["getDebugDrawMask"]=static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getDebugDrawMask);
mt["setAutoStep"]=static_cast<void(cocos2d::PhysicsWorld::*)(bool)>(&cocos2d::PhysicsWorld::setAutoStep);
mt["isAutoStep"]=static_cast<bool(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::isAutoStep);
mt["step"]=static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::step);
}
void RegisterLuaPhysicsAuto(cocos2d::Lua& lua) {
RegisterLuaPhysicsPhysicsShape(lua);
RegisterLuaPhysicsPhysicsShapeCircle(lua);
RegisterLuaPhysicsPhysicsShapePolygon(lua);
RegisterLuaPhysicsPhysicsShapeBox(lua);
RegisterLuaPhysicsPhysicsShapeEdgeSegment(lua);
RegisterLuaPhysicsPhysicsShapeEdgePolygon(lua);
RegisterLuaPhysicsPhysicsShapeEdgeBox(lua);
RegisterLuaPhysicsPhysicsShapeEdgeChain(lua);
RegisterLuaPhysicsPhysicsBody(lua);
RegisterLuaPhysicsPhysicsContact(lua);
RegisterLuaPhysicsPhysicsContactPreSolve(lua);
RegisterLuaPhysicsPhysicsContactPostSolve(lua);
RegisterLuaPhysicsEventListenerPhysicsContact(lua);
RegisterLuaPhysicsEventListenerPhysicsContactWithBodies(lua);
RegisterLuaPhysicsEventListenerPhysicsContactWithShapes(lua);
RegisterLuaPhysicsEventListenerPhysicsContactWithGroup(lua);
RegisterLuaPhysicsPhysicsJoint(lua);
RegisterLuaPhysicsPhysicsJointFixed(lua);
RegisterLuaPhysicsPhysicsJointLimit(lua);
RegisterLuaPhysicsPhysicsJointPin(lua);
RegisterLuaPhysicsPhysicsJointDistance(lua);
RegisterLuaPhysicsPhysicsJointSpring(lua);
RegisterLuaPhysicsPhysicsJointGroove(lua);
RegisterLuaPhysicsPhysicsJointRotarySpring(lua);
RegisterLuaPhysicsPhysicsJointRotaryLimit(lua);
RegisterLuaPhysicsPhysicsJointRatchet(lua);
RegisterLuaPhysicsPhysicsJointGear(lua);
RegisterLuaPhysicsPhysicsJointMotor(lua);
RegisterLuaPhysicsPhysicsWorld(lua);
}
#endif
