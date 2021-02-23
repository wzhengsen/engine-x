#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
extern void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::Lua&);
extern void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::Lua&);
extern void RegisterLuaNavMeshNavMeshAuto(cocos2d::Lua&);
void RegisterLuaNavMeshAuto(cocos2d::Lua& lua){
#if CC_USE_NAVMESH
RegisterLuaNavMeshNavMeshAgentAuto(lua);
RegisterLuaNavMeshNavMeshObstacleAuto(lua);
RegisterLuaNavMeshNavMeshAuto(lua);
#endif
}