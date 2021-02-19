#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#if CC_USE_NAVMESH
#include "navmesh/CCNavMesh.h"
static void RegisterLuaNavMeshNavMeshAgent(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMeshAgent,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMeshAgent");
mt["onEnter"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onEnter);
mt["onExit"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onExit);
mt["setRadius"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setRadius);
mt["getRadius"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getRadius);
mt["setHeight"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setHeight);
mt["getHeight"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getHeight);
mt["setMaxAcceleration"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxAcceleration);
mt["getMaxAcceleration"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxAcceleration);
mt["setMaxSpeed"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxSpeed);
mt["getMaxSpeed"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxSpeed);
mt["setSeparationWeight"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setSeparationWeight);
mt["getSeparationWeight"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSeparationWeight);
mt["setObstacleAvoidanceType"]=static_cast<void(cocos2d::NavMeshAgent::*)(unsigned char)>(&cocos2d::NavMeshAgent::setObstacleAvoidanceType);
mt["getObstacleAvoidanceType"]=static_cast<unsigned char(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getObstacleAvoidanceType);
mt["getCurrentVelocity"]=static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getCurrentVelocity);
mt["pause"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::pause);
mt["resume"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::resume);
mt["stop"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::stop);
mt["setOrientationRefAxes"]=static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::Vec3&)>(&cocos2d::NavMeshAgent::setOrientationRefAxes);
mt["setAutoOrientation"]=static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoOrientation);
mt["setAutoTraverseOffMeshLink"]=static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoTraverseOffMeshLink);
mt["isOnOffMeshLink"]=static_cast<bool(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::isOnOffMeshLink);
mt["completeOffMeshLink"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::completeOffMeshLink);
mt["getCurrentOffMeshLinkData"]=static_cast<cocos2d::OffMeshLinkData(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::getCurrentOffMeshLinkData);
mt["setUserData"]=static_cast<void(cocos2d::NavMeshAgent::*)(void*)>(&cocos2d::NavMeshAgent::setUserData);
mt["getUserData"]=static_cast<void*(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getUserData);
mt["setSyncFlag"]=static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag&)>(&cocos2d::NavMeshAgent::setSyncFlag);
mt["getSyncFlag"]=static_cast<cocos2d::NavMeshAgent::NavMeshAgentSyncFlag(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSyncFlag);
mt["syncToAgent"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToAgent);
mt["syncToNode"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToNode);
mt["getVelocity"]=static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getVelocity);
mt["new"]=static_cast<cocos2d::NavMeshAgent*(*)(const cocos2d::NavMeshAgentParam&)>(&cocos2d::NavMeshAgent::create);
mt["getNavMeshAgentComponentName"]=static_cast<const std::string&(*)()>(&cocos2d::NavMeshAgent::getNavMeshAgentComponentName);
}
static void RegisterLuaNavMeshNavMeshObstacle(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMeshObstacle,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMeshObstacle");
mt["onEnter"]=static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onEnter);
mt["onExit"]=static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onExit);
mt["getRadius"]=static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getRadius);
mt["getHeight"]=static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getHeight);
mt["setSyncFlag"]=static_cast<void(cocos2d::NavMeshObstacle::*)(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag&)>(&cocos2d::NavMeshObstacle::setSyncFlag);
mt["getSyncFlag"]=static_cast<cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getSyncFlag);
mt["syncToObstacle"]=static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToObstacle);
mt["syncToNode"]=static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToNode);
mt["initWith"]=static_cast<bool(cocos2d::NavMeshObstacle::*)(float,float)>(&cocos2d::NavMeshObstacle::initWith);
mt["new"]=static_cast<cocos2d::NavMeshObstacle*(*)(float,float)>(&cocos2d::NavMeshObstacle::create);
mt["getNavMeshObstacleComponentName"]=static_cast<const std::string&(*)()>(&cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName);
}
static void RegisterLuaNavMeshNavMesh(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMesh,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMesh");
mt["update"]=static_cast<void(cocos2d::NavMesh::*)(float)>(&cocos2d::NavMesh::update);
mt["debugDraw"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::Renderer*)>(&cocos2d::NavMesh::debugDraw);
mt["setDebugDrawEnable"]=static_cast<void(cocos2d::NavMesh::*)(bool)>(&cocos2d::NavMesh::setDebugDrawEnable);
mt["isDebugDrawEnabled"]=static_cast<bool(cocos2d::NavMesh::*)()const>(&cocos2d::NavMesh::isDebugDrawEnabled);
mt["addNavMeshAgent"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::addNavMeshAgent);
mt["removeNavMeshAgent"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::removeNavMeshAgent);
mt["addNavMeshObstacle"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::addNavMeshObstacle);
mt["removeNavMeshObstacle"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::removeNavMeshObstacle);
mt["new"]=static_cast<cocos2d::NavMesh*(*)(const std::string&,const std::string&)>(&cocos2d::NavMesh::create);
}
void RegisterLuaNavMeshAuto(cocos2d::Lua& lua) {
RegisterLuaNavMeshNavMeshAgent(lua);
RegisterLuaNavMeshNavMeshObstacle(lua);
RegisterLuaNavMeshNavMesh(lua);
}
#endif
