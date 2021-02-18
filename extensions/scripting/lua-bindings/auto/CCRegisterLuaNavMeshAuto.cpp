#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#if CC_USE_NAVMESH
#include "navmesh/CCNavMesh.h"
static void RegisterLuaNavMeshAgent(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::NavMeshAgent,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMeshAgent"
,"onEnter",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onEnter)
,"onExit",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::onExit)
,"setRadius",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setRadius)
,"getRadius",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getRadius)
,"setHeight",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setHeight)
,"getHeight",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getHeight)
,"setMaxAcceleration",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxAcceleration)
,"getMaxAcceleration",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxAcceleration)
,"setMaxSpeed",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxSpeed)
,"getMaxSpeed",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxSpeed)
,"setSeparationWeight",static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setSeparationWeight)
,"getSeparationWeight",static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSeparationWeight)
,"setObstacleAvoidanceType",static_cast<void(cocos2d::NavMeshAgent::*)(unsigned char)>(&cocos2d::NavMeshAgent::setObstacleAvoidanceType)
,"getObstacleAvoidanceType",static_cast<unsigned char(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getObstacleAvoidanceType)
,"getCurrentVelocity",static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getCurrentVelocity)
,"pause",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::pause)
,"resume",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::resume)
,"stop",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::stop)
,"setOrientationRefAxes",static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::Vec3&)>(&cocos2d::NavMeshAgent::setOrientationRefAxes)
,"setAutoOrientation",static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoOrientation)
,"setAutoTraverseOffMeshLink",static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoTraverseOffMeshLink)
,"isOnOffMeshLink",static_cast<bool(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::isOnOffMeshLink)
,"completeOffMeshLink",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::completeOffMeshLink)
,"getCurrentOffMeshLinkData",static_cast<cocos2d::OffMeshLinkData(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::getCurrentOffMeshLinkData)
,"setUserData",static_cast<void(cocos2d::NavMeshAgent::*)(void*)>(&cocos2d::NavMeshAgent::setUserData)
,"getUserData",static_cast<void*(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getUserData)
,"setSyncFlag",static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag&)>(&cocos2d::NavMeshAgent::setSyncFlag)
,"getSyncFlag",static_cast<cocos2d::NavMeshAgent::NavMeshAgentSyncFlag(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSyncFlag)
,"syncToAgent",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToAgent)
,"syncToNode",static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToNode)
,"getVelocity",static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getVelocity)
,"new",static_cast<cocos2d::NavMeshAgent*(*)(const cocos2d::NavMeshAgentParam&)>(&cocos2d::NavMeshAgent::create)
,"getNavMeshAgentComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshAgent::getNavMeshAgentComponentName)
);}
static void RegisterLuaNavMeshObstacle(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::NavMeshObstacle,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMeshObstacle"
,"onEnter",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onEnter)
,"onExit",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::onExit)
,"getRadius",static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getRadius)
,"getHeight",static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getHeight)
,"setSyncFlag",static_cast<void(cocos2d::NavMeshObstacle::*)(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag&)>(&cocos2d::NavMeshObstacle::setSyncFlag)
,"getSyncFlag",static_cast<cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getSyncFlag)
,"syncToObstacle",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToObstacle)
,"syncToNode",static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToNode)
,"initWith",static_cast<bool(cocos2d::NavMeshObstacle::*)(float,float)>(&cocos2d::NavMeshObstacle::initWith)
,"new",static_cast<cocos2d::NavMeshObstacle*(*)(float,float)>(&cocos2d::NavMeshObstacle::create)
,"getNavMeshObstacleComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName)
);}
static void RegisterLuaNavMesh(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::NavMesh,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMesh"
,"update",static_cast<void(cocos2d::NavMesh::*)(float)>(&cocos2d::NavMesh::update)
,"debugDraw",static_cast<void(cocos2d::NavMesh::*)(cocos2d::Renderer*)>(&cocos2d::NavMesh::debugDraw)
,"setDebugDrawEnable",static_cast<void(cocos2d::NavMesh::*)(bool)>(&cocos2d::NavMesh::setDebugDrawEnable)
,"isDebugDrawEnabled",static_cast<bool(cocos2d::NavMesh::*)()const>(&cocos2d::NavMesh::isDebugDrawEnabled)
,"addNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::addNavMeshAgent)
,"removeNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::removeNavMeshAgent)
,"addNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::addNavMeshObstacle)
,"removeNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::removeNavMeshObstacle)
,"new",static_cast<cocos2d::NavMesh*(*)(const std::string&,const std::string&)>(&cocos2d::NavMesh::create)
);}
void RegisterLuaNavMeshAuto(cocos2d::Lua& lua) {
RegisterLuaNavMeshAgent(lua);
RegisterLuaNavMeshObstacle(lua);
RegisterLuaNavMesh(lua);
}
#endif
