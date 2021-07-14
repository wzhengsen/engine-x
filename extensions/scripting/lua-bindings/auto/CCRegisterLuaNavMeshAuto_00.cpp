#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
#if CC_USE_NAVMESH
namespace cocos2d{
void RegisterLuaNavMeshNavMeshAgentNavMeshAgentSyncFlagAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["NONE"]=cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NONE;
enumTable["NODE_TO_AGENT"]=cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_TO_AGENT;
enumTable["AGENT_TO_NODE"]=cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::AGENT_TO_NODE;
enumTable["NODE_AND_NODE"]=cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_AND_NODE;
lua["cc"]["NavMeshAgent"]["static"]["NavMeshAgentSyncFlag"]=lua.NewEnum(enumTable);
}
void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::NavMeshAgent).name()] = sol::usertype_traits<cocos2d::NavMeshAgent*>::metatable();
auto dep=lua.new_usertype<cocos2d::NavMeshAgent>("deprecated.cocos2d::NavMeshAgent");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::NavMeshAgent*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable());
lua["cc"]["NavMeshAgent"]=mt;
mt["__new__"]=static_cast<cocos2d::NavMeshAgent*(*)(const cocos2d::NavMeshAgentParam&)>(&cocos2d::NavMeshAgent::create);
mt["static"]["GetNavMeshAgentComponentName"]=static_cast<const std::string&(*)()>(&cocos2d::NavMeshAgent::getNavMeshAgentComponentName);
mt["static"]["get"]["NavMeshAgentComponentName"]=mt["GetNavMeshAgentComponentName"];
mt["SetRadius"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setRadius);
mt["set"]["Radius"]=mt["SetRadius"];
mt["GetRadius"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getRadius);
mt["get"]["Radius"]=mt["GetRadius"];
mt["SetHeight"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setHeight);
mt["set"]["Height"]=mt["SetHeight"];
mt["GetHeight"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getHeight);
mt["get"]["Height"]=mt["GetHeight"];
mt["SetMaxAcceleration"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxAcceleration);
mt["set"]["MaxAcceleration"]=mt["SetMaxAcceleration"];
mt["GetMaxAcceleration"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxAcceleration);
mt["get"]["MaxAcceleration"]=mt["GetMaxAcceleration"];
mt["SetMaxSpeed"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setMaxSpeed);
mt["set"]["MaxSpeed"]=mt["SetMaxSpeed"];
mt["GetMaxSpeed"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getMaxSpeed);
mt["get"]["MaxSpeed"]=mt["GetMaxSpeed"];
mt["SetSeparationWeight"]=static_cast<void(cocos2d::NavMeshAgent::*)(float)>(&cocos2d::NavMeshAgent::setSeparationWeight);
mt["set"]["SeparationWeight"]=mt["SetSeparationWeight"];
mt["GetSeparationWeight"]=static_cast<float(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSeparationWeight);
mt["get"]["SeparationWeight"]=mt["GetSeparationWeight"];
mt["SetObstacleAvoidanceType"]=static_cast<void(cocos2d::NavMeshAgent::*)(unsigned char)>(&cocos2d::NavMeshAgent::setObstacleAvoidanceType);
mt["set"]["ObstacleAvoidanceType"]=mt["SetObstacleAvoidanceType"];
mt["GetObstacleAvoidanceType"]=static_cast<unsigned char(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getObstacleAvoidanceType);
mt["get"]["ObstacleAvoidanceType"]=mt["GetObstacleAvoidanceType"];
mt["GetCurrentVelocity"]=static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getCurrentVelocity);
mt["get"]["CurrentVelocity"]=mt["GetCurrentVelocity"];
mt["Move"]=sol::overload([](cocos2d::NavMeshAgent* obj,const cocos2d::Vec3& arg0,const cocos2d::NavMeshAgent::MoveCallback& arg1){return obj->move(arg0,arg1);},[](cocos2d::NavMeshAgent* obj,const cocos2d::Vec3& arg0){return obj->move(arg0);});
mt["Pause"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::pause);
mt["Resume"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::resume);
mt["Stop"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::stop);
mt["SetOrientationRefAxes"]=static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::Vec3&)>(&cocos2d::NavMeshAgent::setOrientationRefAxes);
mt["set"]["OrientationRefAxes"]=mt["SetOrientationRefAxes"];
mt["SetAutoOrientation"]=static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoOrientation);
mt["set"]["AutoOrientation"]=mt["SetAutoOrientation"];
mt["SetAutoTraverseOffMeshLink"]=static_cast<void(cocos2d::NavMeshAgent::*)(bool)>(&cocos2d::NavMeshAgent::setAutoTraverseOffMeshLink);
mt["set"]["AutoTraverseOffMeshLink"]=mt["SetAutoTraverseOffMeshLink"];
mt["IsOnOffMeshLink"]=static_cast<bool(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::isOnOffMeshLink);
mt["get"]["OnOffMeshLink"]=mt["IsOnOffMeshLink"];
mt["CompleteOffMeshLink"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::completeOffMeshLink);
mt["GetCurrentOffMeshLinkData"]=static_cast<cocos2d::OffMeshLinkData(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::getCurrentOffMeshLinkData);
mt["get"]["CurrentOffMeshLinkData"]=mt["GetCurrentOffMeshLinkData"];
mt["SetUserData"]=static_cast<void(cocos2d::NavMeshAgent::*)(void*)>(&cocos2d::NavMeshAgent::setUserData);
mt["set"]["UserData"]=mt["SetUserData"];
mt["GetUserData"]=static_cast<void*(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getUserData);
mt["get"]["UserData"]=mt["GetUserData"];
mt["SetSyncFlag"]=static_cast<void(cocos2d::NavMeshAgent::*)(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag&)>(&cocos2d::NavMeshAgent::setSyncFlag);
mt["set"]["SyncFlag"]=mt["SetSyncFlag"];
mt["GetSyncFlag"]=static_cast<cocos2d::NavMeshAgent::NavMeshAgentSyncFlag(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getSyncFlag);
mt["get"]["SyncFlag"]=mt["GetSyncFlag"];
mt["SyncToAgent"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToAgent);
mt["SyncToNode"]=static_cast<void(cocos2d::NavMeshAgent::*)()>(&cocos2d::NavMeshAgent::syncToNode);
mt["GetVelocity"]=static_cast<cocos2d::Vec3(cocos2d::NavMeshAgent::*)()const>(&cocos2d::NavMeshAgent::getVelocity);
mt["get"]["Velocity"]=mt["GetVelocity"];
RegisterLuaNavMeshNavMeshAgentNavMeshAgentSyncFlagAuto(lua);
}
void RegisterLuaNavMeshNavMeshObstacleNavMeshObstacleSyncFlagAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["NONE"]=cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NONE;
enumTable["NODE_TO_OBSTACLE"]=cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_TO_OBSTACLE;
enumTable["OBSTACLE_TO_NODE"]=cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::OBSTACLE_TO_NODE;
enumTable["NODE_AND_NODE"]=cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_AND_NODE;
lua["cc"]["NavMeshObstacle"]["static"]["NavMeshObstacleSyncFlag"]=lua.NewEnum(enumTable);
}
void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::NavMeshObstacle).name()] = sol::usertype_traits<cocos2d::NavMeshObstacle*>::metatable();
auto dep=lua.new_usertype<cocos2d::NavMeshObstacle>("deprecated.cocos2d::NavMeshObstacle");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::NavMeshObstacle*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable());
lua["cc"]["NavMeshObstacle"]=mt;
mt["__new__"]=static_cast<cocos2d::NavMeshObstacle*(*)(float,float)>(&cocos2d::NavMeshObstacle::create);
mt["static"]["GetNavMeshObstacleComponentName"]=static_cast<const std::string&(*)()>(&cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName);
mt["static"]["get"]["NavMeshObstacleComponentName"]=mt["GetNavMeshObstacleComponentName"];
mt["SetRadius"]=static_cast<void(cocos2d::NavMeshObstacle::*)(float)>(&cocos2d::NavMeshObstacle::setRadius);
mt["set"]["Radius"]=mt["SetRadius"];
mt["GetRadius"]=static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getRadius);
mt["get"]["Radius"]=mt["GetRadius"];
mt["SetHeight"]=static_cast<void(cocos2d::NavMeshObstacle::*)(float)>(&cocos2d::NavMeshObstacle::setHeight);
mt["set"]["Height"]=mt["SetHeight"];
mt["GetHeight"]=static_cast<float(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getHeight);
mt["get"]["Height"]=mt["GetHeight"];
mt["SetSyncFlag"]=static_cast<void(cocos2d::NavMeshObstacle::*)(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag&)>(&cocos2d::NavMeshObstacle::setSyncFlag);
mt["set"]["SyncFlag"]=mt["SetSyncFlag"];
mt["GetSyncFlag"]=static_cast<cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag(cocos2d::NavMeshObstacle::*)()const>(&cocos2d::NavMeshObstacle::getSyncFlag);
mt["get"]["SyncFlag"]=mt["GetSyncFlag"];
mt["SyncToObstacle"]=static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToObstacle);
mt["SyncToNode"]=static_cast<void(cocos2d::NavMeshObstacle::*)()>(&cocos2d::NavMeshObstacle::syncToNode);
RegisterLuaNavMeshNavMeshObstacleNavMeshObstacleSyncFlagAuto(lua);
}
void RegisterLuaNavMeshNavMeshAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::NavMesh).name()] = sol::usertype_traits<cocos2d::NavMesh*>::metatable();
auto dep=lua.new_usertype<cocos2d::NavMesh>("deprecated.cocos2d::NavMesh");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::NavMesh*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["NavMesh"]=mt;
mt["__new__"]=static_cast<cocos2d::NavMesh*(*)(const std::string&,const std::string&)>(&cocos2d::NavMesh::create);
mt["Update"]=static_cast<void(cocos2d::NavMesh::*)(float)>(&cocos2d::NavMesh::update);
mt["DebugDraw"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::Renderer*)>(&cocos2d::NavMesh::debugDraw);
mt["SetDebugDrawEnable"]=static_cast<void(cocos2d::NavMesh::*)(bool)>(&cocos2d::NavMesh::setDebugDrawEnable);
mt["set"]["DebugDrawEnable"]=mt["SetDebugDrawEnable"];
mt["IsDebugDrawEnabled"]=static_cast<bool(cocos2d::NavMesh::*)()const>(&cocos2d::NavMesh::isDebugDrawEnabled);
mt["get"]["DebugDrawEnabled"]=mt["IsDebugDrawEnabled"];
mt["AddNavMeshAgent"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::addNavMeshAgent);
mt["RemoveNavMeshAgent"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshAgent*)>(&cocos2d::NavMesh::removeNavMeshAgent);
mt["AddNavMeshObstacle"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::addNavMeshObstacle);
mt["RemoveNavMeshObstacle"]=static_cast<void(cocos2d::NavMesh::*)(cocos2d::NavMeshObstacle*)>(&cocos2d::NavMesh::removeNavMeshObstacle);
}
}
#endif
