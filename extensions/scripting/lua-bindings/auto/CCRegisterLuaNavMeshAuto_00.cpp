#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
#if CC_USE_NAVMESH
void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMeshAgent,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMeshAgent");
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
mt.set_function("new",static_cast<cocos2d::NavMeshAgent*(*)(const cocos2d::NavMeshAgentParam&)>(&cocos2d::NavMeshAgent::create));
mt.set_function("getNavMeshAgentComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshAgent::getNavMeshAgentComponentName));
}
void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMeshObstacle,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMeshObstacle");
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
mt.set_function("new",static_cast<cocos2d::NavMeshObstacle*(*)(float,float)>(&cocos2d::NavMeshObstacle::create));
mt.set_function("getNavMeshObstacleComponentName",static_cast<const std::string&(*)()>(&cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName));
}
void RegisterLuaNavMeshNavMeshAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NavMesh,cocos2d::Ref,cocos2d::LuaObject>("cc","NavMesh");
mt.set_function("update",static_cast<void(cocos2d::NavMesh::*)(float)>(&cocos2d::NavMesh::update));
mt.set_function("debugDraw",static_cast<void(cocos2d::NavMesh::*)(cocos2d::Renderer*)>(&cocos2d::NavMesh::debugDraw));
mt.set_function("setDebugDrawEnable",static_cast<void(cocos2d::NavMesh::*)(bool)>(&cocos2d::NavMesh::setDebugDrawEnable));
mt.set_function("isDebugDrawEnabled",static_cast<bool(cocos2d::NavMesh::*)()const>(&cocos2d::NavMesh::isDebugDrawEnabled));
mt.set_function("addNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::addNavMeshAgent));
mt.set_function("removeNavMeshAgent",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::removeNavMeshAgent));
mt.set_function("addNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::addNavMeshObstacle));
mt.set_function("removeNavMeshObstacle",static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::removeNavMeshObstacle));
mt.set_function("findPath",static_cast<void(cocos2d::NavMesh::*)(const cocos2d::Vec3&,const cocos2d::Vec3&,std::vector<cocos2d::Vec3>&)>(&cocos2d::NavMesh::findPath));
mt.set_function("new",static_cast<cocos2d::NavMesh*(*)(const std::string&,const std::string&)>(&cocos2d::NavMesh::create));
}
#endif
