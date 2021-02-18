#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#if CC_USE_PHYSICS
#include "cocos2d.h"
static void RegisterLuaPhysicsShape(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShape"
,"getBody",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getBody)
,"getType",static_cast<cocos2d::PhysicsShape::Type(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getType)
,"getArea",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getArea)
,"getMoment",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMoment)
,"setMoment",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMoment)
,"setTag",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setTag)
,"getTag",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getTag)
,"getMass",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMass)
,"setMass",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMass)
,"getDensity",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getDensity)
,"setDensity",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setDensity)
,"getRestitution",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getRestitution)
,"setRestitution",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setRestitution)
,"getFriction",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getFriction)
,"setFriction",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setFriction)
,"getMaterial",static_cast<const cocos2d::PhysicsMaterial&(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMaterial)
,"setMaterial",static_cast<void(cocos2d::PhysicsShape::*)(const cocos2d::PhysicsMaterial&)>(&cocos2d::PhysicsShape::setMaterial)
,"isSensor",static_cast<bool(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::isSensor)
,"setSensor",static_cast<void(cocos2d::PhysicsShape::*)(bool)>(&cocos2d::PhysicsShape::setSensor)
,"calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::calculateDefaultMoment)
,"getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getOffset)
,"getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getCenter)
,"containsPoint",static_cast<bool(cocos2d::PhysicsShape::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsShape::containsPoint)
,"setCategoryBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCategoryBitmask)
,"getCategoryBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCategoryBitmask)
,"setContactTestBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setContactTestBitmask)
,"getContactTestBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getContactTestBitmask)
,"setCollisionBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCollisionBitmask)
,"getCollisionBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCollisionBitmask)
,"setGroup",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setGroup)
,"getGroup",static_cast<int(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getGroup)
);}
static void RegisterLuaPhysicsShapeCircle(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapeCircle,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeCircle"
,"calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::calculateDefaultMoment)
,"getRadius",static_cast<float(cocos2d::PhysicsShapeCircle::*)()const>(&cocos2d::PhysicsShapeCircle::getRadius)
,"getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::getOffset)
,"new",sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);})
,"calculateArea",static_cast<float(*)(float)>(&cocos2d::PhysicsShapeCircle::calculateArea)
,"calculateMoment",sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1){return obj->calculateMoment(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1,const cocos2d::Vec2& arg2){return obj->calculateMoment(arg0,arg1,arg2);})
);}
static void RegisterLuaPhysicsShapePolygon(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapePolygon"
,"calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::calculateDefaultMoment)
,"getPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)(int)const>(&cocos2d::PhysicsShapePolygon::getPoint)
,"getPointsCount",static_cast<int(cocos2d::PhysicsShapePolygon::*)()const>(&cocos2d::PhysicsShapePolygon::getPointsCount)
,"getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::getCenter)
);}
static void RegisterLuaPhysicsShapeBox(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapeBox,cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeBox"
,"getSize",static_cast<cocos2d::Size(cocos2d::PhysicsShapeBox::*)()const>(&cocos2d::PhysicsShapeBox::getSize)
,"getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeBox::*)()>(&cocos2d::PhysicsShapeBox::getOffset)
,"new",sol::overload([](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);})
);}
static void RegisterLuaPhysicsShapeEdgeSegment(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapeEdgeSegment,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeSegment"
,"getPointA",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointA)
,"getPointB",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointB)
,"getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()>(&cocos2d::PhysicsShapeEdgeSegment::getCenter)
,"new",sol::overload([](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);})
);}
static void RegisterLuaPhysicsShapeEdgePolygon(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgePolygon"
,"getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgePolygon::*)()>(&cocos2d::PhysicsShapeEdgePolygon::getCenter)
,"getPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgePolygon::*)()const>(&cocos2d::PhysicsShapeEdgePolygon::getPointsCount)
);}
static void RegisterLuaPhysicsShapeEdgeBox(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapeEdgeBox,cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeBox"
,"getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeBox::*)()>(&cocos2d::PhysicsShapeEdgeBox::getOffset)
,"new",sol::overload([](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);})
);}
static void RegisterLuaPhysicsShapeEdgeChain(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsShapeEdgeChain,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsShapeEdgeChain"
,"getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeChain::*)()>(&cocos2d::PhysicsShapeEdgeChain::getCenter)
,"getPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgeChain::*)()const>(&cocos2d::PhysicsShapeEdgeChain::getPointsCount)
);}
static void RegisterLuaPhysicsBody(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsBody,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsBody"
,"addShape",sol::overload([](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->addShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->addShape(arg0,arg1);})
,"removeShape",sol::overload([](cocos2d::PhysicsBody* obj,int arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,int arg0,bool arg1){return obj->removeShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->removeShape(arg0,arg1);})
,"removeAllShapes",sol::overload([](cocos2d::PhysicsBody* obj){return obj->removeAllShapes();},[](cocos2d::PhysicsBody* obj,bool arg0){return obj->removeAllShapes(arg0);})
,"getShapes",static_cast<const cocos2d::Vector<cocos2d::PhysicsShape *>&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getShapes)
,"getFirstShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getFirstShape)
,"getShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)(int)const>(&cocos2d::PhysicsBody::getShape)
,"applyForce",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyForce(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyForce(arg0,arg1);})
,"resetForces",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::resetForces)
,"applyImpulse",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyImpulse(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyImpulse(arg0,arg1);})
,"applyTorque",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::applyTorque)
,"setVelocity",static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setVelocity)
,"getVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocity)
,"setAngularVelocity",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocity)
,"getVelocityAtLocalPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtLocalPoint)
,"getVelocityAtWorldPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtWorldPoint)
,"getAngularVelocity",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocity)
,"setVelocityLimit",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setVelocityLimit)
,"getVelocityLimit",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocityLimit)
,"setAngularVelocityLimit",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocityLimit)
,"getAngularVelocityLimit",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocityLimit)
,"removeFromWorld",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::removeFromWorld)
,"getWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getWorld)
,"getNode",static_cast<cocos2d::Node*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getNode)
,"setCategoryBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCategoryBitmask)
,"setContactTestBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setContactTestBitmask)
,"setCollisionBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCollisionBitmask)
,"getCategoryBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCategoryBitmask)
,"getContactTestBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getContactTestBitmask)
,"getCollisionBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCollisionBitmask)
,"setGroup",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setGroup)
,"getGroup",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getGroup)
,"getPosition",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPosition)
,"getRotation",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getRotation)
,"setPositionOffset",static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setPositionOffset)
,"getPositionOffset",static_cast<const cocos2d::Vec2&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPositionOffset)
,"setRotationOffset",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setRotationOffset)
,"getRotationOffset",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getRotationOffset)
,"isDynamic",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isDynamic)
,"setDynamic",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setDynamic)
,"setMass",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMass)
,"getMass",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMass)
,"addMass",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMass)
,"setMoment",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMoment)
,"getMoment",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMoment)
,"addMoment",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMoment)
,"getLinearDamping",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getLinearDamping)
,"setLinearDamping",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setLinearDamping)
,"getAngularDamping",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getAngularDamping)
,"setAngularDamping",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularDamping)
,"isResting",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isResting)
,"setResting",static_cast<void(cocos2d::PhysicsBody::*)(bool)const>(&cocos2d::PhysicsBody::setResting)
,"setEnabled",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setEnabled)
,"isRotationEnabled",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isRotationEnabled)
,"setRotationEnable",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setRotationEnable)
,"isGravityEnabled",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isGravityEnabled)
,"setGravityEnable",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setGravityEnable)
,"getTag",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getTag)
,"setTag",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setTag)
,"world2Local",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::world2Local)
,"local2World",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::local2World)
,"onEnter",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onEnter)
,"onExit",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onExit)
,"onAdd",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onAdd)
,"onRemove",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onRemove)
,"new",sol::overload(static_cast<cocos2d::PhysicsBody*(*)(float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)()>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)(float,float)>(&cocos2d::PhysicsBody::create))
,"createCircle",sol::overload([](cocos2d::PhysicsBody* obj,float arg0){return obj->createCircle(arg0);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createCircle(arg0,arg1);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createCircle(arg0,arg1,arg2);})
,"createBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createBox(arg0,arg1,arg2);})
,"createEdgeSegment",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->createEdgeSegment(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeSegment(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeSegment(arg0,arg1,arg2,arg3);})
,"createEdgeBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createEdgeBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createEdgeBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->createEdgeBox(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->createEdgeBox(arg0,arg1,arg2,arg3);})
);}
static void RegisterLuaPhysicsContact(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsContact,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","PhysicsContact"
,"getShapeA",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeA)
,"getShapeB",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeB)
,"getEventCode",static_cast<cocos2d::PhysicsContact::EventCode(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getEventCode)
);}
static void RegisterLuaPhysicsContactPreSolve(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsContactPreSolve>("cc","PhysicsContactPreSolve"
,"getRestitution",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getRestitution)
,"getFriction",static_cast<float(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getFriction)
,"getSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPreSolve::*)()const>(&cocos2d::PhysicsContactPreSolve::getSurfaceVelocity)
,"setRestitution",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setRestitution)
,"setFriction",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(float)>(&cocos2d::PhysicsContactPreSolve::setFriction)
,"setSurfaceVelocity",static_cast<void(cocos2d::PhysicsContactPreSolve::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsContactPreSolve::setSurfaceVelocity)
,"ignore",static_cast<void(cocos2d::PhysicsContactPreSolve::*)()>(&cocos2d::PhysicsContactPreSolve::ignore)
);}
static void RegisterLuaPhysicsContactPostSolve(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsContactPostSolve>("cc","PhysicsContactPostSolve"
,"getRestitution",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getRestitution)
,"getFriction",static_cast<float(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getFriction)
,"getSurfaceVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsContactPostSolve::*)()const>(&cocos2d::PhysicsContactPostSolve::getSurfaceVelocity)
);}
static void RegisterLuaEventListenerPhysicsContact(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContact"
,"checkAvailable",static_cast<bool(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::checkAvailable)
,"clone",static_cast<cocos2d::EventListenerPhysicsContact*(cocos2d::EventListenerPhysicsContact::*)()>(&cocos2d::EventListenerPhysicsContact::clone)
,"new",static_cast<cocos2d::EventListenerPhysicsContact*(*)()>(&cocos2d::EventListenerPhysicsContact::create)
);}
static void RegisterLuaEventListenerPhysicsContactWithBodies(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerPhysicsContactWithBodies,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithBodies"
,"hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithBodies::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithBodies::hitTest)
,"clone",static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(cocos2d::EventListenerPhysicsContactWithBodies::*)()>(&cocos2d::EventListenerPhysicsContactWithBodies::clone)
,"new",static_cast<cocos2d::EventListenerPhysicsContactWithBodies*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::EventListenerPhysicsContactWithBodies::create)
);}
static void RegisterLuaEventListenerPhysicsContactWithShapes(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerPhysicsContactWithShapes,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithShapes"
,"hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithShapes::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::hitTest)
,"clone",static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(cocos2d::EventListenerPhysicsContactWithShapes::*)()>(&cocos2d::EventListenerPhysicsContactWithShapes::clone)
,"new",static_cast<cocos2d::EventListenerPhysicsContactWithShapes*(*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithShapes::create)
);}
static void RegisterLuaEventListenerPhysicsContactWithGroup(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerPhysicsContactWithGroup,cocos2d::EventListenerPhysicsContact,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerPhysicsContactWithGroup"
,"hitTest",static_cast<bool(cocos2d::EventListenerPhysicsContactWithGroup::*)(cocos2d::PhysicsShape*,cocos2d::PhysicsShape*)>(&cocos2d::EventListenerPhysicsContactWithGroup::hitTest)
,"clone",static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(cocos2d::EventListenerPhysicsContactWithGroup::*)()>(&cocos2d::EventListenerPhysicsContactWithGroup::clone)
,"new",static_cast<cocos2d::EventListenerPhysicsContactWithGroup*(*)(int)>(&cocos2d::EventListenerPhysicsContactWithGroup::create)
);}
static void RegisterLuaPhysicsJoint(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJoint>("cc","PhysicsJoint"
,"getBodyA",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyA)
,"getBodyB",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getBodyB)
,"getWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getWorld)
,"getTag",static_cast<int(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getTag)
,"setTag",static_cast<void(cocos2d::PhysicsJoint::*)(int)>(&cocos2d::PhysicsJoint::setTag)
,"isEnabled",static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isEnabled)
,"setEnable",static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setEnable)
,"isCollisionEnabled",static_cast<bool(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::isCollisionEnabled)
,"setCollisionEnabled",static_cast<void(cocos2d::PhysicsJoint::*)(bool)>(&cocos2d::PhysicsJoint::setCollisionEnabled)
,"removeFormWorld",static_cast<void(cocos2d::PhysicsJoint::*)()>(&cocos2d::PhysicsJoint::removeFormWorld)
,"setMaxForce",static_cast<void(cocos2d::PhysicsJoint::*)(float)>(&cocos2d::PhysicsJoint::setMaxForce)
,"getMaxForce",static_cast<float(cocos2d::PhysicsJoint::*)()const>(&cocos2d::PhysicsJoint::getMaxForce)
);}
static void RegisterLuaPhysicsJointFixed(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointFixed,cocos2d::PhysicsJoint>("cc","PhysicsJointFixed"
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointFixed::*)()>(&cocos2d::PhysicsJointFixed::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointFixed*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointFixed::construct)
);}
static void RegisterLuaPhysicsJointLimit(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointLimit,cocos2d::PhysicsJoint>("cc","PhysicsJointLimit"
,"getAnchr1",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr1)
,"setAnchr1",static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr1)
,"getAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getAnchr2)
,"setAnchr2",static_cast<void(cocos2d::PhysicsJointLimit::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::setAnchr2)
,"getMin",static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMin)
,"setMin",static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMin)
,"getMax",static_cast<float(cocos2d::PhysicsJointLimit::*)()const>(&cocos2d::PhysicsJointLimit::getMax)
,"setMax",static_cast<void(cocos2d::PhysicsJointLimit::*)(float)>(&cocos2d::PhysicsJointLimit::setMax)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointLimit::*)()>(&cocos2d::PhysicsJointLimit::createConstraints)
,"construct",sol::overload(static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointLimit::construct),static_cast<cocos2d::PhysicsJointLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointLimit::construct))
);}
static void RegisterLuaPhysicsJointPin(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointPin,cocos2d::PhysicsJoint>("cc","PhysicsJointPin"
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointPin::*)()>(&cocos2d::PhysicsJointPin::createConstraints)
,"construct",sol::overload(static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct),static_cast<cocos2d::PhysicsJointPin*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointPin::construct))
);}
static void RegisterLuaPhysicsJointDistance(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointDistance,cocos2d::PhysicsJoint>("cc","PhysicsJointDistance"
,"getDistance",static_cast<float(cocos2d::PhysicsJointDistance::*)()const>(&cocos2d::PhysicsJointDistance::getDistance)
,"setDistance",static_cast<void(cocos2d::PhysicsJointDistance::*)(float)>(&cocos2d::PhysicsJointDistance::setDistance)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointDistance::*)()>(&cocos2d::PhysicsJointDistance::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointDistance*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointDistance::construct)
);}
static void RegisterLuaPhysicsJointSpring(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointSpring,cocos2d::PhysicsJoint>("cc","PhysicsJointSpring"
,"getAnchr1",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr1)
,"setAnchr1",static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr1)
,"getAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr2)
,"setAnchr2",static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr2)
,"getRestLength",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getRestLength)
,"setRestLength",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setRestLength)
,"getStiffness",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getStiffness)
,"setStiffness",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setStiffness)
,"getDamping",static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getDamping)
,"setDamping",static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setDamping)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointSpring::*)()>(&cocos2d::PhysicsJointSpring::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointSpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointSpring::construct)
);}
static void RegisterLuaPhysicsJointGroove(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointGroove,cocos2d::PhysicsJoint>("cc","PhysicsJointGroove"
,"getGrooveA",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveA)
,"setGrooveA",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveA)
,"getGrooveB",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveB)
,"setGrooveB",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveB)
,"getAnchr2",static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getAnchr2)
,"setAnchr2",static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setAnchr2)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointGroove::*)()>(&cocos2d::PhysicsJointGroove::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointGroove*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::construct)
);}
static void RegisterLuaPhysicsJointRotarySpring(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointRotarySpring,cocos2d::PhysicsJoint>("cc","PhysicsJointRotarySpring"
,"getRestAngle",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getRestAngle)
,"setRestAngle",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setRestAngle)
,"getStiffness",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getStiffness)
,"setStiffness",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setStiffness)
,"getDamping",static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getDamping)
,"setDamping",static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setDamping)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointRotarySpring::*)()>(&cocos2d::PhysicsJointRotarySpring::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointRotarySpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotarySpring::construct)
);}
static void RegisterLuaPhysicsJointRotaryLimit(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointRotaryLimit,cocos2d::PhysicsJoint>("cc","PhysicsJointRotaryLimit"
,"getMin",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMin)
,"setMin",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMin)
,"getMax",static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMax)
,"setMax",static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMax)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointRotaryLimit::*)()>(&cocos2d::PhysicsJointRotaryLimit::createConstraints)
,"construct",sol::overload(static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::PhysicsJointRotaryLimit::construct),static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotaryLimit::construct))
);}
static void RegisterLuaPhysicsJointRatchet(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointRatchet,cocos2d::PhysicsJoint>("cc","PhysicsJointRatchet"
,"getAngle",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getAngle)
,"setAngle",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setAngle)
,"getPhase",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getPhase)
,"setPhase",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setPhase)
,"getRatchet",static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getRatchet)
,"setRatchet",static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setRatchet)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointRatchet::*)()>(&cocos2d::PhysicsJointRatchet::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointRatchet*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRatchet::construct)
);}
static void RegisterLuaPhysicsJointGear(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointGear,cocos2d::PhysicsJoint>("cc","PhysicsJointGear"
,"getPhase",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getPhase)
,"setPhase",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setPhase)
,"getRatio",static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getRatio)
,"setRatio",static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setRatio)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointGear::*)()>(&cocos2d::PhysicsJointGear::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointGear*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointGear::construct)
);}
static void RegisterLuaPhysicsJointMotor(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsJointMotor,cocos2d::PhysicsJoint>("cc","PhysicsJointMotor"
,"getRate",static_cast<float(cocos2d::PhysicsJointMotor::*)()const>(&cocos2d::PhysicsJointMotor::getRate)
,"setRate",static_cast<void(cocos2d::PhysicsJointMotor::*)(float)>(&cocos2d::PhysicsJointMotor::setRate)
,"createConstraints",static_cast<bool(cocos2d::PhysicsJointMotor::*)()>(&cocos2d::PhysicsJointMotor::createConstraints)
,"construct",static_cast<cocos2d::PhysicsJointMotor*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float)>(&cocos2d::PhysicsJointMotor::construct)
);}
static void RegisterLuaPhysicsWorld(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PhysicsWorld>("cc","PhysicsWorld"
,"addJoint",static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsJoint*)>(&cocos2d::PhysicsWorld::addJoint)
,"removeJoint",sol::overload([](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0){return obj->removeJoint(arg0);},[](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0,bool arg1){return obj->removeJoint(arg0,arg1);})
,"removeAllJoints",sol::overload([](cocos2d::PhysicsWorld* obj){return obj->removeAllJoints();},[](cocos2d::PhysicsWorld* obj,bool arg0){return obj->removeAllJoints(arg0);})
,"removeBody",sol::overload(static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::removeBody),static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsBody*)>(&cocos2d::PhysicsWorld::removeBody))
,"removeAllBodies",static_cast<void(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::removeAllBodies)
,"getShapes",static_cast<cocos2d::Vector<cocos2d::PhysicsShape *>(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShapes)
,"getShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShape)
,"getAllBodies",static_cast<const cocos2d::Vector<cocos2d::PhysicsBody *>&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getAllBodies)
,"getBody",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsWorld::*)(int)const>(&cocos2d::PhysicsWorld::getBody)
,"getGravity",static_cast<cocos2d::Vec2(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getGravity)
,"setGravity",static_cast<void(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsWorld::setGravity)
,"setSpeed",static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::setSpeed)
,"getSpeed",static_cast<float(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getSpeed)
,"setUpdateRate",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setUpdateRate)
,"getUpdateRate",static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getUpdateRate)
,"setSubsteps",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setSubsteps)
,"getSubsteps",static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getSubsteps)
,"setFixedUpdateRate",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setFixedUpdateRate)
,"getFixedUpdateRate",static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getFixedUpdateRate)
,"setDebugDrawMask",static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setDebugDrawMask)
,"setPreUpdateCallback",static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPreUpdateCallback)
,"setPostUpdateCallback",static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPostUpdateCallback)
,"getDebugDrawMask",static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getDebugDrawMask)
,"setAutoStep",static_cast<void(cocos2d::PhysicsWorld::*)(bool)>(&cocos2d::PhysicsWorld::setAutoStep)
,"isAutoStep",static_cast<bool(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::isAutoStep)
,"step",static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::step)
);}
void RegisterLuaPhysicsAuto(cocos2d::Lua& lua) {
RegisterLuaPhysicsShape(lua);
RegisterLuaPhysicsShapeCircle(lua);
RegisterLuaPhysicsShapePolygon(lua);
RegisterLuaPhysicsShapeBox(lua);
RegisterLuaPhysicsShapeEdgeSegment(lua);
RegisterLuaPhysicsShapeEdgePolygon(lua);
RegisterLuaPhysicsShapeEdgeBox(lua);
RegisterLuaPhysicsShapeEdgeChain(lua);
RegisterLuaPhysicsBody(lua);
RegisterLuaPhysicsContact(lua);
RegisterLuaPhysicsContactPreSolve(lua);
RegisterLuaPhysicsContactPostSolve(lua);
RegisterLuaEventListenerPhysicsContact(lua);
RegisterLuaEventListenerPhysicsContactWithBodies(lua);
RegisterLuaEventListenerPhysicsContactWithShapes(lua);
RegisterLuaEventListenerPhysicsContactWithGroup(lua);
RegisterLuaPhysicsJoint(lua);
RegisterLuaPhysicsJointFixed(lua);
RegisterLuaPhysicsJointLimit(lua);
RegisterLuaPhysicsJointPin(lua);
RegisterLuaPhysicsJointDistance(lua);
RegisterLuaPhysicsJointSpring(lua);
RegisterLuaPhysicsJointGroove(lua);
RegisterLuaPhysicsJointRotarySpring(lua);
RegisterLuaPhysicsJointRotaryLimit(lua);
RegisterLuaPhysicsJointRatchet(lua);
RegisterLuaPhysicsJointGear(lua);
RegisterLuaPhysicsJointMotor(lua);
RegisterLuaPhysicsWorld(lua);
}
#endif
