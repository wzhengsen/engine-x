#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
namespace cocos2d{
extern void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::extension::Lua&);
extern void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::extension::Lua&);
extern void RegisterLuaNavMeshNavMeshAuto(cocos2d::extension::Lua&);
void RegisterLuaNavMeshAuto(cocos2d::extension::Lua& lua){
#if CC_USE_NAVMESH
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaNavMeshNavMeshAgentAuto(lua);
RegisterLuaNavMeshNavMeshObstacleAuto(lua);
RegisterLuaNavMeshNavMeshAuto(lua);
#endif
}
}