#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
#if CC_USE_NAVMESH
void RegisterLuaNavMeshNavMeshAgentNavMeshAgentSyncFlagAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["NavMeshAgent"];
pTable.new_enum("NavMeshAgentSyncFlag"
,"NONE",0
,"NODE_TO_AGENT",1
,"AGENT_TO_NODE",2
,"NODE_AND_NODE",3
);}
void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::NavMeshAgent,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("NavMeshAgent",false);
ns["NavMeshAgent"] = mt;
lua["NavMeshAgent"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onExit));
mt.set_function("setRadius",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setRadius));
mt.set_function("getRadius",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getRadius));
mt.set_function("setHeight",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setHeight));
mt.set_function("getHeight",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getHeight));
mt.set_function("setMaxAcceleration",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxAcceleration));
mt.set_function("getMaxAcceleration",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxAcceleration));
mt.set_function("setMaxSpeed",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxSpeed));
mt.set_function("getMaxSpeed",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxSpeed));
mt.set_function("setSeparationWeight",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setSeparationWeight));
mt.set_function("getSeparationWeight",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSeparationWeight));
mt.set_function("setObstacleAvoidanceType",static_cast<void(cocos2d::NavMeshAgent::*)(unsigned char)>(&cocos2d::NavMeshAgent::setObstacleAvoidanceType));
mt.set_function("getObstacleAvoidanceType",static_cast<unsigned char(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getObstacleAvoidanceType));
mt.set_function("getCurrentVelocity",static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getCurrentVelocity));
mt.set_function("move",sol::overload([](cocos2d::NavMeshAgent* obj,const cocos2d::Vec3& arg0){return obj->move(arg0);},[](cocos2d::NavMeshAgent* obj,const cocos2d::Vec3& arg0,const std::function<void (cocos2d::NavMeshAgent *, float)>& arg1){return obj->move(arg0,arg1);}));
mt.set_function("pause",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::pause));
mt.set_function("resume",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::resume));
mt.set_function("stop",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::stop));
mt.set_function("setOrientationRefAxes",static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::Vec3&)>(&cocos2d::NavMeshAgent::setOrientationRefAxes));
mt.set_function("setAutoOrientation",static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoOrientation));
mt.set_function("setAutoTraverseOffMeshLink",static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoTraverseOffMeshLink));
mt.set_function("isOnOffMeshLink",static_cast<bool(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::isOnOffMeshLink));
mt.set_function("completeOffMeshLink",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::completeOffMeshLink));
mt.set_function("getCurrentOffMeshLinkData",static_cast<cocos2d::OffMeshLinkData(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::getCurrentOffMeshLinkData));
mt.set_function("setUserData",static_cast<void(cocos2d::NavMeshAgent::*)(void*)>(&cocos2d::NavMeshAgent::setUserData));
mt.set_function("getUserData",static_cast<void*(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getUserData));
mt.set_function("setSyncFlag",static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag&)>(&cocos2d::NavMeshAgent::setSyncFlag));
mt.set_function("getSyncFlag",static_cast<cocos2d::NavMeshAgent::NavMeshAgentSyncFlag(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSyncFlag));
mt.set_function("syncToAgent",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToAgent));
mt.set_function("syncToNode",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToNode));
mt.set_function("getVelocity",static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getVelocity));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::NavMeshAgent*(*)(const cocos2d::NavMeshAgentParam&)>(&cocos2d::NavMeshAgent::create));
mt.set_function("getNavMeshAgentComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshAgent::getNavMeshAgentComponentName));
RegisterLuaNavMeshNavMeshAgentNavMeshAgentSyncFlagAuto(lua);
}
void RegisterLuaNavMeshbackendProgramTypeAnonymousEnum_1348959449711010928_Auto(cocos2d::Lua& lua) {
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
void RegisterLuaNavMeshTextureFormatEXTAnonymousEnum__8996569140777308299_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFormatEXT"];
pTable["NONE"] = 0;
pTable["ETC1_ALPHA"] = 1;
}
void RegisterLuaNavMeshTextureFlagAnonymousEnum__2753430244883972378_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFlag"];
pTable["NONE"] = 0;
pTable["ANTIALIAS_ENABLED"] = 65536;
pTable["PREMULTIPLIEDALPHA"] = 131072;
pTable["RENDERTARGET"] = 262144;
}
void RegisterLuaNavMeshNavMeshObstacleNavMeshObstacleSyncFlagAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["NavMeshObstacle"];
pTable.new_enum("NavMeshObstacleSyncFlag"
,"NONE",0
,"NODE_TO_OBSTACLE",1
,"OBSTACLE_TO_NODE",2
,"NODE_AND_NODE",3
);}
void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::NavMeshObstacle,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("NavMeshObstacle",false);
ns["NavMeshObstacle"] = mt;
lua["NavMeshObstacle"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onExit));
mt.set_function("setRadius",static_cast<void(cocos2d::NavMeshObstacle::*)(float)>(&cocos2d::NavMeshObstacle::setRadius));
mt.set_function("getRadius",static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getRadius));
mt.set_function("setHeight",static_cast<void(cocos2d::NavMeshObstacle::*)(float)>(&cocos2d::NavMeshObstacle::setHeight));
mt.set_function("getHeight",static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getHeight));
mt.set_function("setSyncFlag",static_cast<void(cocos2d::NavMeshObstacle::*)(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag&)>(&cocos2d::NavMeshObstacle::setSyncFlag));
mt.set_function("getSyncFlag",static_cast<cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getSyncFlag));
mt.set_function("syncToObstacle",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToObstacle));
mt.set_function("syncToNode",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToNode));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::NavMeshObstacle*(*)(float,float)>(&cocos2d::NavMeshObstacle::create));
mt.set_function("getNavMeshObstacleComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName));
RegisterLuaNavMeshNavMeshObstacleNavMeshObstacleSyncFlagAuto(lua);
}
void RegisterLuaNavMeshNavMeshAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::NavMesh,cocos2d::Ref,cocos2d::LuaObject>("NavMesh",false);
ns["NavMesh"] = mt;
lua["NavMesh"] = sol::nil;
mt.set_function("update",static_cast<void(cocos2d::NavMesh::*)(float)>(&cocos2d::NavMesh::update));
mt.set_function("debugDraw",static_cast<void(cocos2d::NavMesh::*)(cocos2d::Renderer*)>(&cocos2d::NavMesh::debugDraw));
mt.set_function("setDebugDrawEnable",static_cast<void(cocos2d::NavMesh::*)(bool)>(&cocos2d::NavMesh::setDebugDrawEnable));
mt.set_function("isDebugDrawEnabled",static_cast<bool(cocos2d::NavMesh::*)()const>(&cocos2d::NavMesh::isDebugDrawEnabled));
mt.set_function("addNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::addNavMeshAgent));
mt.set_function("removeNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::removeNavMeshAgent));
mt.set_function("addNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::addNavMeshObstacle));
mt.set_function("removeNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::removeNavMeshObstacle));
mt.set_function("findPath",static_cast<void(cocos2d::NavMesh::*)(const cocos2d::Vec3&,const cocos2d::Vec3&,std::vector<cocos2d::Vec3>&)>(&cocos2d::NavMesh::findPath));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::NavMesh*(*)(const std::string&,const std::string&)>(&cocos2d::NavMesh::create));
}
#endif
