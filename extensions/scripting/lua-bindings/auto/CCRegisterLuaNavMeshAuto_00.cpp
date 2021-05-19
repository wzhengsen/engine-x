#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
#if CC_USE_NAVMESH
void RegisterLuaNavMeshNavMeshAgentNavMeshAgentSyncFlagAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["NavMeshAgent"];
pTable.new_enum<cocos2d::NavMeshAgent::NavMeshAgentSyncFlag>("NavMeshAgentSyncFlag",{
{"NONE",cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NONE}
,{"NODE_TO_AGENT",cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_TO_AGENT}
,{"AGENT_TO_NODE",cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::AGENT_TO_NODE}
,{"NODE_AND_NODE",cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_AND_NODE}
});}
void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMeshAgent>("cc","NavMeshAgent",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::NavMeshAgent*(*)(const cocos2d::NavMeshAgentParam&)>(&cocos2d::NavMeshAgent::create));
mt.set_function("GetNavMeshAgentComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshAgent::getNavMeshAgentComponentName));
mt.set_function("OnEnter",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onExit));
mt.set_function("SetRadius",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setRadius));
mt.set_function("GetRadius",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getRadius));
mt.set_function("SetHeight",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setHeight));
mt.set_function("GetHeight",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getHeight));
mt.set_function("SetMaxAcceleration",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxAcceleration));
mt.set_function("GetMaxAcceleration",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxAcceleration));
mt.set_function("SetMaxSpeed",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxSpeed));
mt.set_function("GetMaxSpeed",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxSpeed));
mt.set_function("SetSeparationWeight",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setSeparationWeight));
mt.set_function("GetSeparationWeight",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSeparationWeight));
mt.set_function("SetObstacleAvoidanceType",static_cast<void(cocos2d::NavMeshAgent::*)(unsigned char)>(&cocos2d::NavMeshAgent::setObstacleAvoidanceType));
mt.set_function("GetObstacleAvoidanceType",static_cast<unsigned char(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getObstacleAvoidanceType));
mt.set_function("GetCurrentVelocity",static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getCurrentVelocity));
mt.set_function("Move",sol::overload([](cocos2d::NavMeshAgent* obj,const cocos2d::Vec3& arg0){return obj->move(arg0);},[](cocos2d::NavMeshAgent* obj,const cocos2d::Vec3& arg0,const cocos2d::NavMeshAgent::MoveCallback& arg1){return obj->move(arg0,arg1);}));
mt.set_function("Pause",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::pause));
mt.set_function("Resume",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::resume));
mt.set_function("Stop",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::stop));
mt.set_function("SetOrientationRefAxes",static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::Vec3&)>(&cocos2d::NavMeshAgent::setOrientationRefAxes));
mt.set_function("SetAutoOrientation",static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoOrientation));
mt.set_function("SetAutoTraverseOffMeshLink",static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoTraverseOffMeshLink));
mt.set_function("IsOnOffMeshLink",static_cast<bool(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::isOnOffMeshLink));
mt.set_function("CompleteOffMeshLink",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::completeOffMeshLink));
mt.set_function("GetCurrentOffMeshLinkData",static_cast<cocos2d::OffMeshLinkData(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::getCurrentOffMeshLinkData));
mt.set_function("SetUserData",static_cast<void(cocos2d::NavMeshAgent::*)(void*)>(&cocos2d::NavMeshAgent::setUserData));
mt.set_function("GetUserData",static_cast<void*(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getUserData));
mt.set_function("SetSyncFlag",static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag&)>(&cocos2d::NavMeshAgent::setSyncFlag));
mt.set_function("GetSyncFlag",static_cast<cocos2d::NavMeshAgent::NavMeshAgentSyncFlag(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSyncFlag));
mt.set_function("SyncToAgent",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToAgent));
mt.set_function("SyncToNode",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToNode));
mt.set_function("GetVelocity",static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getVelocity));
RegisterLuaNavMeshNavMeshAgentNavMeshAgentSyncFlagAuto(lua);
}
void RegisterLuaNavMeshNavMeshObstacleNavMeshObstacleSyncFlagAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["NavMeshObstacle"];
pTable.new_enum<cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag>("NavMeshObstacleSyncFlag",{
{"NONE",cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NONE}
,{"NODE_TO_OBSTACLE",cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_TO_OBSTACLE}
,{"OBSTACLE_TO_NODE",cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::OBSTACLE_TO_NODE}
,{"NODE_AND_NODE",cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_AND_NODE}
});}
void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMeshObstacle>("cc","NavMeshObstacle",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::NavMeshObstacle*(*)(float,float)>(&cocos2d::NavMeshObstacle::create));
mt.set_function("GetNavMeshObstacleComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName));
mt.set_function("OnEnter",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onExit));
mt.set_function("SetRadius",static_cast<void(cocos2d::NavMeshObstacle::*)(float)>(&cocos2d::NavMeshObstacle::setRadius));
mt.set_function("GetRadius",static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getRadius));
mt.set_function("SetHeight",static_cast<void(cocos2d::NavMeshObstacle::*)(float)>(&cocos2d::NavMeshObstacle::setHeight));
mt.set_function("GetHeight",static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getHeight));
mt.set_function("SetSyncFlag",static_cast<void(cocos2d::NavMeshObstacle::*)(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag&)>(&cocos2d::NavMeshObstacle::setSyncFlag));
mt.set_function("GetSyncFlag",static_cast<cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getSyncFlag));
mt.set_function("SyncToObstacle",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToObstacle));
mt.set_function("SyncToNode",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToNode));
RegisterLuaNavMeshNavMeshObstacleNavMeshObstacleSyncFlagAuto(lua);
}
void RegisterLuaNavMeshNavMeshAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMesh>("cc","NavMesh",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::NavMesh*(*)(const std::string&,const std::string&)>(&cocos2d::NavMesh::create));
mt.set_function("Update",static_cast<void(cocos2d::NavMesh::*)(float)>(&cocos2d::NavMesh::update));
mt.set_function("DebugDraw",static_cast<void(cocos2d::NavMesh::*)(cocos2d::Renderer*)>(&cocos2d::NavMesh::debugDraw));
mt.set_function("SetDebugDrawEnable",static_cast<void(cocos2d::NavMesh::*)(bool)>(&cocos2d::NavMesh::setDebugDrawEnable));
mt.set_function("IsDebugDrawEnabled",static_cast<bool(cocos2d::NavMesh::*)()const>(&cocos2d::NavMesh::isDebugDrawEnabled));
mt.set_function("AddNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::addNavMeshAgent));
mt.set_function("RemoveNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::removeNavMeshAgent));
mt.set_function("AddNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::addNavMeshObstacle));
mt.set_function("RemoveNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::removeNavMeshObstacle));
mt.set_function("FindPath",static_cast<void(cocos2d::NavMesh::*)(const cocos2d::Vec3&,const cocos2d::Vec3&,std::vector<cocos2d::Vec3, std::allocator<cocos2d::Vec3> >&)>(&cocos2d::NavMesh::findPath));
}
#endif
