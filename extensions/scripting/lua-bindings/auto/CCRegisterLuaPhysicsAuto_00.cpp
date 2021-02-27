#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
void RegisterLuaPhysicsbackendProgramTypeAnonymousEnum_6250464624676953325_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["backend"];
pTable = pTable["ProgramType"];
pTable["POSITION_COLOR_LENGTH_TEXTURE"] = 0;
pTable["POSITION_COLOR_TEXTURE_AS_POINTSIZE"] = 1;
pTable["POSITION_COLOR"] = 2;
pTable["POSITION_UCOLOR"] = 3;
pTable["POSITION_TEXTURE"] = 4;
pTable["POSITION_TEXTURE_COLOR"] = 5;
pTable["POSITION_TEXTURE_COLOR_ALPHA_TEST"] = 6;
pTable["LABEL_NORMAL"] = 7;
pTable["LABLE_OUTLINE"] = 8;
pTable["LABLE_DISTANCEFIELD_GLOW"] = 9;
pTable["LABEL_DISTANCE_NORMAL"] = 10;
pTable["LAYER_RADIA_GRADIENT"] = 11;
pTable["ETC1"] = 12;
pTable["ETC1_GRAY"] = 13;
pTable["GRAY_SCALE"] = 14;
pTable["CAMERA_CLEAR"] = 15;
pTable["TERRAIN_3D"] = 16;
pTable["LINE_COLOR_3D"] = 17;
pTable["SKYBOX_3D"] = 18;
pTable["SKINPOSITION_TEXTURE_3D"] = 19;
pTable["SKINPOSITION_NORMAL_TEXTURE_3D"] = 20;
pTable["POSITION_NORMAL_TEXTURE_3D"] = 21;
pTable["POSITION_NORMAL_3D"] = 22;
pTable["POSITION_TEXTURE_3D"] = 23;
pTable["POSITION_3D"] = 24;
pTable["POSITION_BUMPEDNORMAL_TEXTURE_3D"] = 25;
pTable["SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D"] = 26;
pTable["PARTICLE_TEXTURE_3D"] = 27;
pTable["PARTICLE_COLOR_3D"] = 28;
pTable["HSV"] = 29;
pTable["HSV_ETC1"] = 30;
pTable["BUILTIN_COUNT"] = 31;
pTable["CUSTOM_PROGRAM"] = 4096;
}
void RegisterLuaPhysicsTextureFormatEXTAnonymousEnum__3908417537970589657_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFormatEXT"];
pTable["NONE"] = 0;
pTable["ETC1_ALPHA"] = 1;
}
void RegisterLuaPhysicsTextureFlagAnonymousEnum__4586642565233315709_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFlag"];
pTable["NONE"] = 0;
pTable["ANTIALIAS_ENABLED"] = 65536;
pTable["PREMULTIPLIEDALPHA"] = 131072;
pTable["RENDERTARGET"] = 262144;
}
void RegisterLuaPhysicsPhysicsShapeTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["PhysicsShape"];
pTable.new_enum("Type"
,"UNKNOWN",0
,"CIRCLE",1
,"BOX",2
,"POLYGON",3
,"EDGESEGMENT",4
,"EDGEBOX",5
,"EDGEPOLYGON",6
,"EDGECHAIN",7
,"POLYGEN",3
,"EDGEPOLYGEN",6
);}
void RegisterLuaPhysicsPhysicsShapeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShape",true);
ns["PhysicsShape"] = mt;
lua["PhysicsShape"] = sol::nil;
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
mt.set_function("recenterPoints",sol::overload([](cocos2d::PhysicsShape* obj,cocos2d::Vec2* arg0,int arg1){return obj->recenterPoints(arg0,arg1);},[](cocos2d::PhysicsShape* obj,cocos2d::Vec2* arg0,int arg1,const cocos2d::Vec2& arg2){return obj->recenterPoints(arg0,arg1,arg2);}));
mt.set_function("getPolygonCenter",static_cast<cocos2d::Vec2(*)(const cocos2d::Vec2*,int)>(&cocos2d::PhysicsShape::getPolygonCenter));
RegisterLuaPhysicsPhysicsShapeTypeAuto(lua);
}
void RegisterLuaPhysicsPhysicsShapeCircleAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapeCircle,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapeCircle",false);
ns["PhysicsShapeCircle"] = mt;
lua["PhysicsShapeCircle"] = sol::nil;
mt.set_function("calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::calculateDefaultMoment));
mt.set_function("getRadius",static_cast<float(cocos2d::PhysicsShapeCircle::*)()const>(&cocos2d::PhysicsShapeCircle::getRadius));
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeCircle::*)()>(&cocos2d::PhysicsShapeCircle::getOffset));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("calculateArea",static_cast<float(*)(float)>(&cocos2d::PhysicsShapeCircle::calculateArea));
mt.set_function("calculateMoment",sol::overload([](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1){return obj->calculateMoment(arg0,arg1);},[](cocos2d::PhysicsShapeCircle* obj,float arg0,float arg1,const cocos2d::Vec2& arg2){return obj->calculateMoment(arg0,arg1,arg2);}));
}
void RegisterLuaPhysicsPhysicsShapePolygonAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapePolygon",false);
ns["PhysicsShapePolygon"] = mt;
lua["PhysicsShapePolygon"] = sol::nil;
mt.set_function("calculateDefaultMoment",static_cast<float(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::calculateDefaultMoment));
mt.set_function("getPoint",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)(int)const>(&cocos2d::PhysicsShapePolygon::getPoint));
mt.set_function("getPoints",static_cast<void(cocos2d::PhysicsShapePolygon::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapePolygon::getPoints));
mt.set_function("getPointsCount",static_cast<int(cocos2d::PhysicsShapePolygon::*)()const>(&cocos2d::PhysicsShapePolygon::getPointsCount));
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapePolygon::*)()>(&cocos2d::PhysicsShapePolygon::getCenter));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::PhysicsShapePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,const cocos2d::Vec2& arg3,float arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("calculateArea",static_cast<float(*)(const cocos2d::Vec2*,int)>(&cocos2d::PhysicsShapePolygon::calculateArea));
mt.set_function("calculateMoment",sol::overload([](cocos2d::PhysicsShapePolygon* obj,float arg0,const cocos2d::Vec2* arg1,int arg2){return obj->calculateMoment(arg0,arg1,arg2);},[](cocos2d::PhysicsShapePolygon* obj,float arg0,const cocos2d::Vec2* arg1,int arg2,const cocos2d::Vec2& arg3){return obj->calculateMoment(arg0,arg1,arg2,arg3);},[](cocos2d::PhysicsShapePolygon* obj,float arg0,const cocos2d::Vec2* arg1,int arg2,const cocos2d::Vec2& arg3,float arg4){return obj->calculateMoment(arg0,arg1,arg2,arg3,arg4);}));
}
void RegisterLuaPhysicsPhysicsShapeBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapeBox,cocos2d::PhysicsShapePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapeBox",false);
ns["PhysicsShapeBox"] = mt;
lua["PhysicsShapeBox"] = sol::nil;
mt.set_function("getSize",static_cast<cocos2d::Size(cocos2d::PhysicsShapeBox::*)()const>(&cocos2d::PhysicsShapeBox::getSize));
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeBox::*)()>(&cocos2d::PhysicsShapeBox::getOffset));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,const cocos2d::Vec2& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeSegment,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapeEdgeSegment",false);
ns["PhysicsShapeEdgeSegment"] = mt;
lua["PhysicsShapeEdgeSegment"] = sol::nil;
mt.set_function("getPointA",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointA));
mt.set_function("getPointB",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()const>(&cocos2d::PhysicsShapeEdgeSegment::getPointB));
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeSegment::*)()>(&cocos2d::PhysicsShapeEdgeSegment::getCenter));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeSegment* obj,const cocos2d::Vec2& arg0,const cocos2d::Vec2& arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapeEdgePolygon",false);
ns["PhysicsShapeEdgePolygon"] = mt;
lua["PhysicsShapeEdgePolygon"] = sol::nil;
mt.set_function("getCenter",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgePolygon::*)()>(&cocos2d::PhysicsShapeEdgePolygon::getCenter));
mt.set_function("getPoints",static_cast<void(cocos2d::PhysicsShapeEdgePolygon::*)(cocos2d::Vec2*)const>(&cocos2d::PhysicsShapeEdgePolygon::getPoints));
mt.set_function("getPointsCount",static_cast<int(cocos2d::PhysicsShapeEdgePolygon::*)()const>(&cocos2d::PhysicsShapeEdgePolygon::getPointsCount));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgePolygon* obj,const cocos2d::Vec2* arg0,int arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgePolygon* obj,const cocos2d::Vec2* arg0,int arg1,const cocos2d::PhysicsMaterial& arg2,float arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PhysicsShapeEdgeBox,cocos2d::PhysicsShapeEdgePolygon,cocos2d::PhysicsShape,cocos2d::Ref,cocos2d::LuaObject>("PhysicsShapeEdgeBox",false);
ns["PhysicsShapeEdgeBox"] = mt;
lua["PhysicsShapeEdgeBox"] = sol::nil;
mt.set_function("getOffset",static_cast<cocos2d::Vec2(cocos2d::PhysicsShapeEdgeBox::*)()>(&cocos2d::PhysicsShapeEdgeBox::getOffset));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0){return obj->create(arg0);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1){return obj->create(arg0,arg1);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::PhysicsShapeEdgeBox* obj,const cocos2d::Size& arg0,const cocos2d::PhysicsMaterial& arg1,float arg2,const cocos2d::Vec2& arg3){return obj->create(arg0,arg1,arg2,arg3);}));
}
#endif
