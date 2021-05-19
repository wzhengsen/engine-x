#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsPhysicsShapeTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["PhysicsShape"];
pTable.new_enum<cocos2d::PhysicsShape::Type>("Type",{
{"UNKNOWN",cocos2d::PhysicsShape::Type::UNKNOWN}
,{"CIRCLE",cocos2d::PhysicsShape::Type::CIRCLE}
,{"BOX",cocos2d::PhysicsShape::Type::BOX}
,{"POLYGON",cocos2d::PhysicsShape::Type::POLYGON}
,{"EDGESEGMENT",cocos2d::PhysicsShape::Type::EDGESEGMENT}
,{"EDGEBOX",cocos2d::PhysicsShape::Type::EDGEBOX}
,{"EDGEPOLYGON",cocos2d::PhysicsShape::Type::EDGEPOLYGON}
,{"EDGECHAIN",cocos2d::PhysicsShape::Type::EDGECHAIN}
,{"POLYGEN",cocos2d::PhysicsShape::Type::POLYGEN}
,{"EDGEPOLYGEN",cocos2d::PhysicsShape::Type::EDGEPOLYGEN}
});}
void RegisterLuaPhysicsPhysicsShapeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShape>("cc","PhysicsShape",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetBody",static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getBody));
mt.set_function("GetType",static_cast<cocos2d::PhysicsShape::Type(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getType));
mt.set_function("GetArea",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getArea));
mt.set_function("GetMoment",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMoment));
mt.set_function("SetMoment",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMoment));
mt.set_function("SetTag",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setTag));
mt.set_function("GetTag",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getTag));
mt.set_function("GetMass",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMass));
mt.set_function("SetMass",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMass));
mt.set_function("GetDensity",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getDensity));
mt.set_function("SetDensity",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setDensity));
mt.set_function("GetRestitution",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getRestitution));
mt.set_function("SetRestitution",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setRestitution));
mt.set_function("GetFriction",static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getFriction));
mt.set_function("SetFriction",static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setFriction));
mt.set_function("GetMaterial",static_cast<const cocos2d::PhysicsMaterial&(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMaterial));
mt.set_function("SetMaterial",static_cast<void(cocos2d::PhysicsShape::*)(const cocos2d::PhysicsMaterial&)>(&cocos2d::PhysicsShape::setMaterial));
mt.set_function("IsSensor",static_cast<bool(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::isSensor));
mt.set_function("SetSensor",static_cast<void(cocos2d::PhysicsShape::*)(bool)>(&cocos2d::PhysicsShape::setSensor));
mt.set_function("CalculateDefaultMoment",static_cast<float(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::calculateDefaultMoment));
mt.set_function("GetOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getOffset));
mt.set_function("GetCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getCenter));
mt.set_function("ContainsPoint",static_cast<bool(cocos2d::PhysicsShape::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsShape::containsPoint));
mt.set_function("RecenterPoints",sol::overload([](cocos2d::PhysicsShape* obj,cocos2d::Vec2* arg0,int arg1){return obj->recenterPoints(arg0,arg1);},[](cocos2d::PhysicsShape* obj,cocos2d::Vec2* arg0,int arg1,const cocos2d::Vec2& arg2){return obj->recenterPoints(arg0,arg1,arg2);}));
mt.set_function("GetPolygonCenter",static_cast<cocos2d::Vec2(*)(const cocos2d::Vec2*,int)>(&cocos2d::PhysicsShape::getPolygonCenter));
mt.set_function("SetCategoryBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCategoryBitmask));
mt.set_function("GetCategoryBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCategoryBitmask));
mt.set_function("SetContactTestBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setContactTestBitmask));
mt.set_function("GetContactTestBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getContactTestBitmask));
mt.set_function("SetCollisionBitmask",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCollisionBitmask));
mt.set_function("GetCollisionBitmask",static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCollisionBitmask));
mt.set_function("SetGroup",static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setGroup));
mt.set_function("GetGroup",static_cast<int(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getGroup));
RegisterLuaPhysicsPhysicsShapeTypeAuto(lua);
}
void RegisterLuaPhysicsPhysicsShapeCircleAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeCircle>("cc","PhysicsShapeCircle",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("CalculateArea",static_cast<float(*)(float)>(&cocos2d::PhysicsShapeCircle::calculateArea));
mt.set_function("CalculateMoment",sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1){return obj->calculateMoment(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1,const cocos2d::Vec2& arg2){return obj->calculateMoment(arg0,arg1,arg2);}));
mt.set_function("CalculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::calculateDefaultMoment));
mt.set_function("GetRadius",static_cast<float(cocos2d::PhysicsShapeCircle::*)()const>(&cocos2d::PhysicsShapeCircle::getRadius));
mt.set_function("GetOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::getOffset));
}
void RegisterLuaPhysicsPhysicsShapePolygonAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapePolygon>("cc","PhysicsShapePolygon",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3,float arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("CalculateArea",static_cast<float(*)(const cocos2d::Vec2*,int)>(&cocos2d::PhysicsShapePolygon::calculateArea));
mt.set_function("CalculateMoment",sol::overload([](cocos2d::PhysicsShapePolygon* obj,float arg0,const cocos2d::Vec2* arg1,int arg2){return obj->calculateMoment(arg0,arg1,arg2);},[](cocos2d::PhysicsShapePolygon* obj,float arg0,const cocos2d::Vec2* arg1,int arg2,const cocos2d::Vec2& arg3){return obj->calculateMoment(arg0,arg1,arg2,arg3);},[](cocos2d::PhysicsShapePolygon* obj,float arg0,const cocos2d::Vec2* arg1,int arg2,const cocos2d::Vec2& arg3,float arg4){return obj->calculateMoment(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("CalculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::calculateDefaultMoment));
mt.set_function("GetPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)(int)const>(&cocos2d::PhysicsShapePolygon::getPoint));
mt.set_function("GetPoints",static_cast<void(cocos2d::PhysicsShapePolygon::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapePolygon::getPoints));
mt.set_function("GetPointsCount",static_cast<int(cocos2d::PhysicsShapePolygon::*)()const>(&cocos2d::PhysicsShapePolygon::getPointsCount));
mt.set_function("GetCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::getCenter));
}
void RegisterLuaPhysicsPhysicsShapeBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeBox>("cc","PhysicsShapeBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
mt.set_function("GetSize",static_cast<cocos2d::Size(cocos2d::PhysicsShapeBox::*)()const>(&cocos2d::PhysicsShapeBox::getSize));
mt.set_function("GetOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeBox::*)()>(&cocos2d::PhysicsShapeBox::getOffset));
}
void RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeSegment>("cc","PhysicsShapeEdgeSegment",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
mt.set_function("GetPointA",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointA));
mt.set_function("GetPointB",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointB));
mt.set_function("GetCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()>(&cocos2d::PhysicsShapeEdgeSegment::getCenter));
}
void RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgePolygon>("cc","PhysicsShapeEdgePolygon",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgePolygon* obj,const cocos2d::Vec2* arg0,int arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
mt.set_function("GetCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgePolygon::*)()>(&cocos2d::PhysicsShapeEdgePolygon::getCenter));
mt.set_function("GetPoints",static_cast<void(cocos2d::PhysicsShapeEdgePolygon::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapeEdgePolygon::getPoints));
mt.set_function("GetPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgePolygon::*)()const>(&cocos2d::PhysicsShapeEdgePolygon::getPointsCount));
}
void RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeBox>("cc","PhysicsShapeEdgeBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);}));
mt.set_function("GetOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeBox::*)()>(&cocos2d::PhysicsShapeEdgeBox::getOffset));
}
void RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeChain>("cc","PhysicsShapeEdgeChain",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgeChain* obj,const cocos2d::Vec2* arg0,int arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeChain* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeChain* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
mt.set_function("GetCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeChain::*)()>(&cocos2d::PhysicsShapeEdgeChain::getCenter));
mt.set_function("GetPoints",static_cast<void(cocos2d::PhysicsShapeEdgeChain::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapeEdgeChain::getPoints));
mt.set_function("GetPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgeChain::*)()const>(&cocos2d::PhysicsShapeEdgeChain::getPointsCount));
}
void RegisterLuaPhysicsPhysicsBodyAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsBody>("cc","PhysicsBody",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::PhysicsBody*(*)(float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)()>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)(float,float)>(&cocos2d::PhysicsBody::create)));
mt.set_function("CreateCircle",sol::overload([](cocos2d::PhysicsBody* obj,float arg0){return obj->createCircle(arg0);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createCircle(arg0,arg1);},[](cocos2d::PhysicsBody* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createCircle(arg0,arg1,arg2);}));
mt.set_function("CreateBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->createBox(arg0,arg1,arg2);}));
mt.set_function("CreatePolygon",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1){return obj->createPolygon(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createPolygon(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3){return obj->createPolygon(arg0,arg1,arg2,arg3);}));
mt.set_function("CreateEdgeSegment",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->createEdgeSegment(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeSegment(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeSegment(arg0,arg1,arg2,arg3);}));
mt.set_function("CreateEdgeBox",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0){return obj->createEdgeBox(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->createEdgeBox(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->createEdgeBox(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->createEdgeBox(arg0,arg1,arg2,arg3);}));
mt.set_function("CreateEdgePolygon",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1){return obj->createEdgePolygon(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgePolygon(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgePolygon(arg0,arg1,arg2,arg3);}));
mt.set_function("CreateEdgeChain",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1){return obj->createEdgeChain(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->createEdgeChain(arg0,arg1,arg2);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->createEdgeChain(arg0,arg1,arg2,arg3);}));
mt.set_function("AddShape",sol::overload([](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->addShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->addShape(arg0,arg1);}));
mt.set_function("RemoveShape",sol::overload([](cocos2d::PhysicsBody* obj,int arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,int arg0,bool arg1){return obj->removeShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->removeShape(arg0,arg1);}));
mt.set_function("RemoveAllShapes",sol::overload([](cocos2d::PhysicsBody* obj){return obj->removeAllShapes();},[](cocos2d::PhysicsBody* obj,bool arg0){return obj->removeAllShapes(arg0);}));
mt.set_function("GetShapes",static_cast<const cocos2d::Vector<cocos2d::PhysicsShape *>&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getShapes));
mt.set_function("GetFirstShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getFirstShape));
mt.set_function("GetShape",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)(int)const>(&cocos2d::PhysicsBody::getShape));
mt.set_function("ApplyForce",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyForce(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyForce(arg0,arg1);}));
mt.set_function("ResetForces",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::resetForces));
mt.set_function("ApplyImpulse",sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyImpulse(arg0);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyImpulse(arg0,arg1);}));
mt.set_function("ApplyTorque",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::applyTorque));
mt.set_function("SetVelocity",static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setVelocity));
mt.set_function("GetVelocity",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocity));
mt.set_function("SetAngularVelocity",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocity));
mt.set_function("GetVelocityAtLocalPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtLocalPoint));
mt.set_function("GetVelocityAtWorldPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtWorldPoint));
mt.set_function("GetAngularVelocity",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocity));
mt.set_function("SetVelocityLimit",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setVelocityLimit));
mt.set_function("GetVelocityLimit",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocityLimit));
mt.set_function("SetAngularVelocityLimit",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocityLimit));
mt.set_function("GetAngularVelocityLimit",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocityLimit));
mt.set_function("RemoveFromWorld",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::removeFromWorld));
mt.set_function("GetWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getWorld));
mt.set_function("GetJoints",static_cast<const std::vector<cocos2d::PhysicsJoint *, std::allocator<cocos2d::PhysicsJoint *> >&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getJoints));
mt.set_function("GetNode",static_cast<cocos2d::Node*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getNode));
mt.set_function("SetCategoryBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCategoryBitmask));
mt.set_function("SetContactTestBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setContactTestBitmask));
mt.set_function("SetCollisionBitmask",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCollisionBitmask));
mt.set_function("GetCategoryBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCategoryBitmask));
mt.set_function("GetContactTestBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getContactTestBitmask));
mt.set_function("GetCollisionBitmask",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCollisionBitmask));
mt.set_function("SetGroup",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setGroup));
mt.set_function("GetGroup",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getGroup));
mt.set_function("GetPosition",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPosition));
mt.set_function("GetRotation",static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getRotation));
mt.set_function("SetPositionOffset",static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setPositionOffset));
mt.set_function("GetPositionOffset",static_cast<const cocos2d::Vec2&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPositionOffset));
mt.set_function("SetRotationOffset",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setRotationOffset));
mt.set_function("GetRotationOffset",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getRotationOffset));
mt.set_function("IsDynamic",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isDynamic));
mt.set_function("SetDynamic",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setDynamic));
mt.set_function("SetMass",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMass));
mt.set_function("GetMass",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMass));
mt.set_function("AddMass",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMass));
mt.set_function("SetMoment",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMoment));
mt.set_function("GetMoment",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMoment));
mt.set_function("AddMoment",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMoment));
mt.set_function("GetLinearDamping",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getLinearDamping));
mt.set_function("SetLinearDamping",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setLinearDamping));
mt.set_function("GetAngularDamping",static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getAngularDamping));
mt.set_function("SetAngularDamping",static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularDamping));
mt.set_function("IsResting",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isResting));
mt.set_function("SetResting",static_cast<void(cocos2d::PhysicsBody::*)(bool)const>(&cocos2d::PhysicsBody::setResting));
mt.set_function("SetEnabled",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setEnabled));
mt.set_function("IsRotationEnabled",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isRotationEnabled));
mt.set_function("SetRotationEnable",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setRotationEnable));
mt.set_function("IsGravityEnabled",static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isGravityEnabled));
mt.set_function("SetGravityEnable",static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setGravityEnable));
mt.set_function("GetTag",static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getTag));
mt.set_function("SetTag",static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setTag));
mt.set_function("World2Local",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::world2Local));
mt.set_function("Local2World",static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::local2World));
mt.set_function("OnEnter",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onExit));
mt.set_function("OnAdd",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onAdd));
mt.set_function("OnRemove",static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::onRemove));
mt["COMPONENT_NAME"]=sol::var(std::ref(cocos2d::PhysicsBody::COMPONENT_NAME));
}
void RegisterLuaPhysicsPhysicsContactEventCodeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["PhysicsContact"];
pTable.new_enum<cocos2d::PhysicsContact::EventCode>("EventCode",{
{"NONE",cocos2d::PhysicsContact::EventCode::NONE}
,{"BEGIN",cocos2d::PhysicsContact::EventCode::BEGIN}
,{"PRESOLVE",cocos2d::PhysicsContact::EventCode::PRESOLVE}
,{"POSTSOLVE",cocos2d::PhysicsContact::EventCode::POSTSOLVE}
,{"SEPARATE",cocos2d::PhysicsContact::EventCode::SEPARATE}
});}
void RegisterLuaPhysicsPhysicsContactAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PhysicsContact>("cc","PhysicsContact",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetShapeA",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeA));
mt.set_function("GetShapeB",static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeB));
mt.set_function("GetContactData",static_cast<const cocos2d::PhysicsContactData*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getContactData));
mt.set_function("GetPreContactData",static_cast<const cocos2d::PhysicsContactData*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getPreContactData));
mt.set_function("GetData",static_cast<void*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getData));
mt.set_function("SetData",static_cast<void(cocos2d::PhysicsContact::*)(void*)>(&cocos2d::PhysicsContact::setData));
mt.set_function("GetEventCode",static_cast<cocos2d::PhysicsContact::EventCode(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getEventCode));
RegisterLuaPhysicsPhysicsContactEventCodeAuto(lua);
}
#endif
