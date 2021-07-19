#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
namespace cocos2d{
void RegisterLuaPhysicsPhysicsShapeTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,10);
enumTable["UNKNOWN"]=cocos2d::PhysicsShape::Type::UNKNOWN;
enumTable["CIRCLE"]=cocos2d::PhysicsShape::Type::CIRCLE;
enumTable["BOX"]=cocos2d::PhysicsShape::Type::BOX;
enumTable["POLYGON"]=cocos2d::PhysicsShape::Type::POLYGON;
enumTable["EDGESEGMENT"]=cocos2d::PhysicsShape::Type::EDGESEGMENT;
enumTable["EDGEBOX"]=cocos2d::PhysicsShape::Type::EDGEBOX;
enumTable["EDGEPOLYGON"]=cocos2d::PhysicsShape::Type::EDGEPOLYGON;
enumTable["EDGECHAIN"]=cocos2d::PhysicsShape::Type::EDGECHAIN;
enumTable["POLYGEN"]=cocos2d::PhysicsShape::Type::POLYGEN;
enumTable["EDGEPOLYGEN"]=cocos2d::PhysicsShape::Type::EDGEPOLYGEN;
lua["cc"]["PhysicsShape"]["static"]["Type"]=lua.NewEnum(enumTable);
}
void RegisterLuaPhysicsPhysicsShapeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShape).name()] = sol::usertype_traits<cocos2d::PhysicsShape*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShape>("deprecated.cocos2d::PhysicsShape");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShape*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["PhysicsShape"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetBody"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getBody);
mt["get"]["Body"]=mt["GetBody"];
mt["GetType"]=static_cast<cocos2d::PhysicsShape::Type(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getType);
mt["get"]["Type"]=mt["GetType"];
mt["GetArea"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getArea);
mt["get"]["Area"]=mt["GetArea"];
mt["GetMoment"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMoment);
mt["get"]["Moment"]=mt["GetMoment"];
mt["SetMoment"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMoment);
mt["set"]["Moment"]=mt["SetMoment"];
mt["SetTag"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setTag);
mt["set"]["Tag"]=mt["SetTag"];
mt["GetTag"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getTag);
mt["get"]["Tag"]=mt["GetTag"];
mt["GetMass"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMass);
mt["get"]["Mass"]=mt["GetMass"];
mt["SetMass"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setMass);
mt["set"]["Mass"]=mt["SetMass"];
mt["GetDensity"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getDensity);
mt["get"]["Density"]=mt["GetDensity"];
mt["SetDensity"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setDensity);
mt["set"]["Density"]=mt["SetDensity"];
mt["GetRestitution"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getRestitution);
mt["get"]["Restitution"]=mt["GetRestitution"];
mt["SetRestitution"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setRestitution);
mt["set"]["Restitution"]=mt["SetRestitution"];
mt["GetFriction"]=static_cast<float(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getFriction);
mt["get"]["Friction"]=mt["GetFriction"];
mt["SetFriction"]=static_cast<void(cocos2d::PhysicsShape::*)(float)>(&cocos2d::PhysicsShape::setFriction);
mt["set"]["Friction"]=mt["SetFriction"];
mt["GetMaterial"]=static_cast<const cocos2d::PhysicsMaterial&(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getMaterial);
mt["get"]["Material"]=mt["GetMaterial"];
mt["SetMaterial"]=static_cast<void(cocos2d::PhysicsShape::*)(const cocos2d::PhysicsMaterial&)>(&cocos2d::PhysicsShape::setMaterial);
mt["set"]["Material"]=mt["SetMaterial"];
mt["IsSensor"]=static_cast<bool(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::isSensor);
mt["get"]["Sensor"]=mt["IsSensor"];
mt["SetSensor"]=static_cast<void(cocos2d::PhysicsShape::*)(bool)>(&cocos2d::PhysicsShape::setSensor);
mt["set"]["Sensor"]=mt["SetSensor"];
mt["CalculateDefaultMoment"]=static_cast<float(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::calculateDefaultMoment);
mt["GetOffset"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getOffset);
mt["get"]["Offset"]=mt["GetOffset"];
mt["GetCenter"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getCenter);
mt["get"]["Center"]=mt["GetCenter"];
mt["ContainsPoint"]=static_cast<bool(cocos2d::PhysicsShape::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsShape::containsPoint);
mt["static"]["RecenterPoints"]=sol::overload([](cocos2d::Vec2* arg0,int arg1,const cocos2d::Vec2& arg2){return cocos2d::PhysicsShape::recenterPoints(arg0,arg1,arg2);},[](cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsShape::recenterPoints(arg0,arg1);});
mt["static"]["GetPolygonCenter"]=static_cast<cocos2d::Vec2(*)(const cocos2d::Vec2*,int)>(&cocos2d::PhysicsShape::getPolygonCenter);
mt["SetCategoryBitmask"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCategoryBitmask);
mt["set"]["CategoryBitmask"]=mt["SetCategoryBitmask"];
mt["GetCategoryBitmask"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCategoryBitmask);
mt["get"]["CategoryBitmask"]=mt["GetCategoryBitmask"];
mt["SetContactTestBitmask"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setContactTestBitmask);
mt["set"]["ContactTestBitmask"]=mt["SetContactTestBitmask"];
mt["GetContactTestBitmask"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getContactTestBitmask);
mt["get"]["ContactTestBitmask"]=mt["GetContactTestBitmask"];
mt["SetCollisionBitmask"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setCollisionBitmask);
mt["set"]["CollisionBitmask"]=mt["SetCollisionBitmask"];
mt["GetCollisionBitmask"]=static_cast<int(cocos2d::PhysicsShape::*)()const>(&cocos2d::PhysicsShape::getCollisionBitmask);
mt["get"]["CollisionBitmask"]=mt["GetCollisionBitmask"];
mt["SetGroup"]=static_cast<void(cocos2d::PhysicsShape::*)(int)>(&cocos2d::PhysicsShape::setGroup);
mt["set"]["Group"]=mt["SetGroup"];
mt["GetGroup"]=static_cast<int(cocos2d::PhysicsShape::*)()>(&cocos2d::PhysicsShape::getGroup);
mt["get"]["Group"]=mt["GetGroup"];
RegisterLuaPhysicsPhysicsShapeTypeAuto(lua);
}
void RegisterLuaPhysicsPhysicsShapeCircleAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapeCircle).name()] = sol::usertype_traits<cocos2d::PhysicsShapeCircle*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapeCircle>("deprecated.cocos2d::PhysicsShapeCircle");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapeCircle*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShape*>::metatable());
lua["cc"]["PhysicsShapeCircle"]=mt;
mt["__new__"]=sol::overload([](float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return cocos2d::PhysicsShapeCircle::create(arg0,arg1,arg2);},[](float arg0,const cocos2d::PhysicsMaterial& arg1){return cocos2d::PhysicsShapeCircle::create(arg0,arg1);},[](float arg0){return cocos2d::PhysicsShapeCircle::create(arg0);});
mt["static"]["CalculateArea"]=static_cast<float(*)(float)>(&cocos2d::PhysicsShapeCircle::calculateArea);
mt["static"]["CalculateMoment"]=sol::overload([](float arg0,float arg1,const cocos2d::Vec2& arg2){return cocos2d::PhysicsShapeCircle::calculateMoment(arg0,arg1,arg2);},[](float arg0,float arg1){return cocos2d::PhysicsShapeCircle::calculateMoment(arg0,arg1);});
mt["GetRadius"]=static_cast<float(cocos2d::PhysicsShapeCircle::*)()const>(&cocos2d::PhysicsShapeCircle::getRadius);
mt["get"]["Radius"]=mt["GetRadius"];
}
void RegisterLuaPhysicsPhysicsShapePolygonAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapePolygon).name()] = sol::usertype_traits<cocos2d::PhysicsShapePolygon*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapePolygon>("deprecated.cocos2d::PhysicsShapePolygon");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapePolygon*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShape*>::metatable());
lua["cc"]["PhysicsShapePolygon"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3,float arg4){return cocos2d::PhysicsShapePolygon::create(arg0,arg1,arg2,arg3,arg4);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3){return cocos2d::PhysicsShapePolygon::create(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsShapePolygon::create(arg0,arg1,arg2);},[](const cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsShapePolygon::create(arg0,arg1);});
mt["static"]["CalculateArea"]=static_cast<float(*)(const cocos2d::Vec2*,int)>(&cocos2d::PhysicsShapePolygon::calculateArea);
mt["static"]["CalculateMoment"]=sol::overload([](float arg0,const cocos2d::Vec2* arg1,int arg2,const cocos2d::Vec2& arg3,float arg4){return cocos2d::PhysicsShapePolygon::calculateMoment(arg0,arg1,arg2,arg3,arg4);},[](float arg0,const cocos2d::Vec2* arg1,int arg2,const cocos2d::Vec2& arg3){return cocos2d::PhysicsShapePolygon::calculateMoment(arg0,arg1,arg2,arg3);},[](float arg0,const cocos2d::Vec2* arg1,int arg2){return cocos2d::PhysicsShapePolygon::calculateMoment(arg0,arg1,arg2);});
mt["GetPoint"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)(int)const>(&cocos2d::PhysicsShapePolygon::getPoint);
mt["GetPoints"]=static_cast<void(cocos2d::PhysicsShapePolygon::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapePolygon::getPoints);
mt["GetPointsCount"]=static_cast<int(cocos2d::PhysicsShapePolygon::*)()const>(&cocos2d::PhysicsShapePolygon::getPointsCount);
mt["get"]["PointsCount"]=mt["GetPointsCount"];
}
void RegisterLuaPhysicsPhysicsShapeBoxAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapeBox).name()] = sol::usertype_traits<cocos2d::PhysicsShapeBox*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapeBox>("deprecated.cocos2d::PhysicsShapeBox");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapeBox*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShapePolygon*>::metatable());
lua["cc"]["PhysicsShapeBox"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2,float arg3){return cocos2d::PhysicsShapeBox::create(arg0,arg1,arg2,arg3);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return cocos2d::PhysicsShapeBox::create(arg0,arg1,arg2);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return cocos2d::PhysicsShapeBox::create(arg0,arg1);},[](const cocos2d::Size& arg0){return cocos2d::PhysicsShapeBox::create(arg0);});
mt["GetSize"]=static_cast<cocos2d::Size(cocos2d::PhysicsShapeBox::*)()const>(&cocos2d::PhysicsShapeBox::getSize);
mt["get"]["Size"]=mt["GetSize"];
}
void RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapeEdgeSegment).name()] = sol::usertype_traits<cocos2d::PhysicsShapeEdgeSegment*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapeEdgeSegment>("deprecated.cocos2d::PhysicsShapeEdgeSegment");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapeEdgeSegment*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShape*>::metatable());
lua["cc"]["PhysicsShapeEdgeSegment"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return cocos2d::PhysicsShapeEdgeSegment::create(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsShapeEdgeSegment::create(arg0,arg1,arg2);},[](const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return cocos2d::PhysicsShapeEdgeSegment::create(arg0,arg1);});
mt["GetPointA"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointA);
mt["get"]["PointA"]=mt["GetPointA"];
mt["GetPointB"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointB);
mt["get"]["PointB"]=mt["GetPointB"];
}
void RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapeEdgePolygon).name()] = sol::usertype_traits<cocos2d::PhysicsShapeEdgePolygon*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapeEdgePolygon>("deprecated.cocos2d::PhysicsShapeEdgePolygon");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapeEdgePolygon*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShape*>::metatable());
lua["cc"]["PhysicsShapeEdgePolygon"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return cocos2d::PhysicsShapeEdgePolygon::create(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsShapeEdgePolygon::create(arg0,arg1,arg2);},[](const cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsShapeEdgePolygon::create(arg0,arg1);});
mt["GetPoints"]=static_cast<void(cocos2d::PhysicsShapeEdgePolygon::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapeEdgePolygon::getPoints);
mt["GetPointsCount"]=static_cast<int(cocos2d::PhysicsShapeEdgePolygon::*)()const>(&cocos2d::PhysicsShapeEdgePolygon::getPointsCount);
mt["get"]["PointsCount"]=mt["GetPointsCount"];
}
void RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapeEdgeBox).name()] = sol::usertype_traits<cocos2d::PhysicsShapeEdgeBox*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapeEdgeBox>("deprecated.cocos2d::PhysicsShapeEdgeBox");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapeEdgeBox*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShapeEdgePolygon*>::metatable());
lua["cc"]["PhysicsShapeEdgeBox"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return cocos2d::PhysicsShapeEdgeBox::create(arg0,arg1,arg2,arg3);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return cocos2d::PhysicsShapeEdgeBox::create(arg0,arg1,arg2);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return cocos2d::PhysicsShapeEdgeBox::create(arg0,arg1);},[](const cocos2d::Size& arg0){return cocos2d::PhysicsShapeEdgeBox::create(arg0);});
}
void RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsShapeEdgeChain).name()] = sol::usertype_traits<cocos2d::PhysicsShapeEdgeChain*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsShapeEdgeChain>("deprecated.cocos2d::PhysicsShapeEdgeChain");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsShapeEdgeChain*>::metatable(),sol::usertype_traits<cocos2d::PhysicsShape*>::metatable());
lua["cc"]["PhysicsShapeEdgeChain"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return cocos2d::PhysicsShapeEdgeChain::create(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsShapeEdgeChain::create(arg0,arg1,arg2);},[](const cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsShapeEdgeChain::create(arg0,arg1);});
mt["GetPoints"]=static_cast<void(cocos2d::PhysicsShapeEdgeChain::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapeEdgeChain::getPoints);
mt["GetPointsCount"]=static_cast<int(cocos2d::PhysicsShapeEdgeChain::*)()const>(&cocos2d::PhysicsShapeEdgeChain::getPointsCount);
mt["get"]["PointsCount"]=mt["GetPointsCount"];
}
void RegisterLuaPhysicsPhysicsBodyAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsBody).name()] = sol::usertype_traits<cocos2d::PhysicsBody*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsBody>("deprecated.cocos2d::PhysicsBody");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsBody*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable());
lua["cc"]["PhysicsBody"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::PhysicsBody*(*)(float,float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)(float)>(&cocos2d::PhysicsBody::create),static_cast<cocos2d::PhysicsBody*(*)()>(&cocos2d::PhysicsBody::create));
mt["static"]["CreateCircle"]=sol::overload([](float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return cocos2d::PhysicsBody::createCircle(arg0,arg1,arg2);},[](float arg0,const cocos2d::PhysicsMaterial& arg1){return cocos2d::PhysicsBody::createCircle(arg0,arg1);},[](float arg0){return cocos2d::PhysicsBody::createCircle(arg0);});
mt["static"]["CreateBox"]=sol::overload([](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return cocos2d::PhysicsBody::createBox(arg0,arg1,arg2);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return cocos2d::PhysicsBody::createBox(arg0,arg1);},[](const cocos2d::Size& arg0){return cocos2d::PhysicsBody::createBox(arg0);});
mt["static"]["CreatePolygon"]=sol::overload([](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3){return cocos2d::PhysicsBody::createPolygon(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsBody::createPolygon(arg0,arg1,arg2);},[](const cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsBody::createPolygon(arg0,arg1);});
mt["static"]["CreateEdgeSegment"]=sol::overload([](const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return cocos2d::PhysicsBody::createEdgeSegment(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsBody::createEdgeSegment(arg0,arg1,arg2);},[](const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return cocos2d::PhysicsBody::createEdgeSegment(arg0,arg1);});
mt["static"]["CreateEdgeBox"]=sol::overload([](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return cocos2d::PhysicsBody::createEdgeBox(arg0,arg1,arg2,arg3);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return cocos2d::PhysicsBody::createEdgeBox(arg0,arg1,arg2);},[](const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return cocos2d::PhysicsBody::createEdgeBox(arg0,arg1);},[](const cocos2d::Size& arg0){return cocos2d::PhysicsBody::createEdgeBox(arg0);});
mt["static"]["CreateEdgePolygon"]=sol::overload([](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return cocos2d::PhysicsBody::createEdgePolygon(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsBody::createEdgePolygon(arg0,arg1,arg2);},[](const cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsBody::createEdgePolygon(arg0,arg1);});
mt["static"]["CreateEdgeChain"]=sol::overload([](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return cocos2d::PhysicsBody::createEdgeChain(arg0,arg1,arg2,arg3);},[](const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return cocos2d::PhysicsBody::createEdgeChain(arg0,arg1,arg2);},[](const cocos2d::Vec2* arg0,int arg1){return cocos2d::PhysicsBody::createEdgeChain(arg0,arg1);});
mt["AddShape"]=sol::overload([](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->addShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->addShape(arg0);});
mt["RemoveShape"]=sol::overload([](cocos2d::PhysicsBody* obj,int arg0,bool arg1){return obj->removeShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0,bool arg1){return obj->removeShape(arg0,arg1);},[](cocos2d::PhysicsBody* obj,int arg0){return obj->removeShape(arg0);},[](cocos2d::PhysicsBody* obj,cocos2d::PhysicsShape* arg0){return obj->removeShape(arg0);});
mt["RemoveAllShapes"]=sol::overload([](cocos2d::PhysicsBody* obj,bool arg0){return obj->removeAllShapes(arg0);},[](cocos2d::PhysicsBody* obj){return obj->removeAllShapes();});
mt["GetShapes"]=static_cast<const cocos2d::Vector<cocos2d::PhysicsShape *>&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getShapes);
mt["get"]["Shapes"]=mt["GetShapes"];
mt["GetFirstShape"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getFirstShape);
mt["get"]["FirstShape"]=mt["GetFirstShape"];
mt["GetShape"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsBody::*)(int)const>(&cocos2d::PhysicsBody::getShape);
mt["ApplyForce"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyForce(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyForce(arg0);});
mt["ResetForces"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::resetForces);
mt["ApplyImpulse"]=sol::overload([](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->applyImpulse(arg0,arg1);},[](cocos2d::PhysicsBody* obj,const cocos2d::Vec2& arg0){return obj->applyImpulse(arg0);});
mt["ApplyTorque"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::applyTorque);
mt["SetVelocity"]=static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setVelocity);
mt["set"]["Velocity"]=mt["SetVelocity"];
mt["GetVelocity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocity);
mt["get"]["Velocity"]=mt["GetVelocity"];
mt["SetAngularVelocity"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocity);
mt["set"]["AngularVelocity"]=mt["SetAngularVelocity"];
mt["GetVelocityAtLocalPoint"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtLocalPoint);
mt["GetVelocityAtWorldPoint"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::getVelocityAtWorldPoint);
mt["GetAngularVelocity"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocity);
mt["get"]["AngularVelocity"]=mt["GetAngularVelocity"];
mt["SetVelocityLimit"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setVelocityLimit);
mt["set"]["VelocityLimit"]=mt["SetVelocityLimit"];
mt["GetVelocityLimit"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getVelocityLimit);
mt["get"]["VelocityLimit"]=mt["GetVelocityLimit"];
mt["SetAngularVelocityLimit"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularVelocityLimit);
mt["set"]["AngularVelocityLimit"]=mt["SetAngularVelocityLimit"];
mt["GetAngularVelocityLimit"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getAngularVelocityLimit);
mt["get"]["AngularVelocityLimit"]=mt["GetAngularVelocityLimit"];
mt["RemoveFromWorld"]=static_cast<void(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::removeFromWorld);
mt["GetWorld"]=static_cast<cocos2d::PhysicsWorld*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getWorld);
mt["get"]["World"]=mt["GetWorld"];
mt["GetJoints"]=static_cast<const std::vector<cocos2d::PhysicsJoint *, std::allocator<cocos2d::PhysicsJoint *> >&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getJoints);
mt["get"]["Joints"]=mt["GetJoints"];
mt["GetNode"]=static_cast<cocos2d::Node*(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getNode);
mt["get"]["Node"]=mt["GetNode"];
mt["SetCategoryBitmask"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCategoryBitmask);
mt["set"]["CategoryBitmask"]=mt["SetCategoryBitmask"];
mt["SetContactTestBitmask"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setContactTestBitmask);
mt["set"]["ContactTestBitmask"]=mt["SetContactTestBitmask"];
mt["SetCollisionBitmask"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setCollisionBitmask);
mt["set"]["CollisionBitmask"]=mt["SetCollisionBitmask"];
mt["GetCategoryBitmask"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCategoryBitmask);
mt["get"]["CategoryBitmask"]=mt["GetCategoryBitmask"];
mt["GetContactTestBitmask"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getContactTestBitmask);
mt["get"]["ContactTestBitmask"]=mt["GetContactTestBitmask"];
mt["GetCollisionBitmask"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getCollisionBitmask);
mt["get"]["CollisionBitmask"]=mt["GetCollisionBitmask"];
mt["SetGroup"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setGroup);
mt["set"]["Group"]=mt["SetGroup"];
mt["GetGroup"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getGroup);
mt["get"]["Group"]=mt["GetGroup"];
mt["GetPosition"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPosition);
mt["get"]["Position"]=mt["GetPosition"];
mt["GetRotation"]=static_cast<float(cocos2d::PhysicsBody::*)()>(&cocos2d::PhysicsBody::getRotation);
mt["get"]["Rotation"]=mt["GetRotation"];
mt["SetPositionOffset"]=static_cast<void(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::setPositionOffset);
mt["set"]["PositionOffset"]=mt["SetPositionOffset"];
mt["GetPositionOffset"]=static_cast<const cocos2d::Vec2&(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getPositionOffset);
mt["get"]["PositionOffset"]=mt["GetPositionOffset"];
mt["SetRotationOffset"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setRotationOffset);
mt["set"]["RotationOffset"]=mt["SetRotationOffset"];
mt["GetRotationOffset"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getRotationOffset);
mt["get"]["RotationOffset"]=mt["GetRotationOffset"];
mt["IsDynamic"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isDynamic);
mt["get"]["Dynamic"]=mt["IsDynamic"];
mt["SetDynamic"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setDynamic);
mt["set"]["Dynamic"]=mt["SetDynamic"];
mt["SetMass"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMass);
mt["set"]["Mass"]=mt["SetMass"];
mt["GetMass"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMass);
mt["get"]["Mass"]=mt["GetMass"];
mt["AddMass"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMass);
mt["SetMoment"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setMoment);
mt["set"]["Moment"]=mt["SetMoment"];
mt["GetMoment"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getMoment);
mt["get"]["Moment"]=mt["GetMoment"];
mt["AddMoment"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::addMoment);
mt["GetLinearDamping"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getLinearDamping);
mt["get"]["LinearDamping"]=mt["GetLinearDamping"];
mt["SetLinearDamping"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setLinearDamping);
mt["set"]["LinearDamping"]=mt["SetLinearDamping"];
mt["GetAngularDamping"]=static_cast<float(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getAngularDamping);
mt["get"]["AngularDamping"]=mt["GetAngularDamping"];
mt["SetAngularDamping"]=static_cast<void(cocos2d::PhysicsBody::*)(float)>(&cocos2d::PhysicsBody::setAngularDamping);
mt["set"]["AngularDamping"]=mt["SetAngularDamping"];
mt["IsResting"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isResting);
mt["get"]["Resting"]=mt["IsResting"];
mt["SetResting"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)const>(&cocos2d::PhysicsBody::setResting);
mt["set"]["Resting"]=mt["SetResting"];
mt["IsRotationEnabled"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isRotationEnabled);
mt["get"]["RotationEnabled"]=mt["IsRotationEnabled"];
mt["SetRotationEnable"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setRotationEnable);
mt["set"]["RotationEnable"]=mt["SetRotationEnable"];
mt["IsGravityEnabled"]=static_cast<bool(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::isGravityEnabled);
mt["get"]["GravityEnabled"]=mt["IsGravityEnabled"];
mt["SetGravityEnable"]=static_cast<void(cocos2d::PhysicsBody::*)(bool)>(&cocos2d::PhysicsBody::setGravityEnable);
mt["set"]["GravityEnable"]=mt["SetGravityEnable"];
mt["GetTag"]=static_cast<int(cocos2d::PhysicsBody::*)()const>(&cocos2d::PhysicsBody::getTag);
mt["get"]["Tag"]=mt["GetTag"];
mt["SetTag"]=static_cast<void(cocos2d::PhysicsBody::*)(int)>(&cocos2d::PhysicsBody::setTag);
mt["set"]["Tag"]=mt["SetTag"];
mt["World2Local"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::world2Local);
mt["Local2World"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsBody::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsBody::local2World);
mt["static"]["get"]["COMPONENT_NAME"]=[]()->const std::string&{return cocos2d::PhysicsBody::COMPONENT_NAME;};
}
void RegisterLuaPhysicsPhysicsContactEventCodeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,5);
enumTable["NONE"]=cocos2d::PhysicsContact::EventCode::NONE;
enumTable["BEGIN"]=cocos2d::PhysicsContact::EventCode::BEGIN;
enumTable["PRESOLVE"]=cocos2d::PhysicsContact::EventCode::PRESOLVE;
enumTable["POSTSOLVE"]=cocos2d::PhysicsContact::EventCode::POSTSOLVE;
enumTable["SEPARATE"]=cocos2d::PhysicsContact::EventCode::SEPARATE;
lua["cc"]["PhysicsContact"]["static"]["EventCode"]=lua.NewEnum(enumTable);
}
void RegisterLuaPhysicsPhysicsContactAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsContact).name()] = sol::usertype_traits<cocos2d::PhysicsContact*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsContact>("deprecated.cocos2d::PhysicsContact");
dep[sol::base_classes]=sol::bases<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsContact*>::metatable(),sol::usertype_traits<cocos2d::EventCustom*>::metatable());
lua["cc"]["PhysicsContact"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetShapeA"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeA);
mt["get"]["ShapeA"]=mt["GetShapeA"];
mt["GetShapeB"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getShapeB);
mt["get"]["ShapeB"]=mt["GetShapeB"];
mt["GetContactData"]=static_cast<const cocos2d::PhysicsContactData*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getContactData);
mt["get"]["ContactData"]=mt["GetContactData"];
mt["GetPreContactData"]=static_cast<const cocos2d::PhysicsContactData*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getPreContactData);
mt["get"]["PreContactData"]=mt["GetPreContactData"];
mt["GetData"]=static_cast<void*(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getData);
mt["get"]["Data"]=mt["GetData"];
mt["SetData"]=static_cast<void(cocos2d::PhysicsContact::*)(void*)>(&cocos2d::PhysicsContact::setData);
mt["set"]["Data"]=mt["SetData"];
mt["GetEventCode"]=static_cast<cocos2d::PhysicsContact::EventCode(cocos2d::PhysicsContact::*)()const>(&cocos2d::PhysicsContact::getEventCode);
mt["get"]["EventCode"]=mt["GetEventCode"];
RegisterLuaPhysicsPhysicsContactEventCodeAuto(lua);
}
}
#endif
