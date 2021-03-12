#include "scripting/lua-bindings/auto/CCRegisterLuaNavMeshAuto.hpp"
#include "navmesh/CCNavMesh.h"
extern void RegisterLuaNavMeshNavMeshAgentAuto(cocos2d::Lua&);
extern void RegisterLuaNavMeshbackendProgramTypeAnonymousEnum_1348959449711010928_Auto(cocos2d::Lua&);
extern void RegisterLuaNavMeshTextureFormatEXTAnonymousEnum__8996569140777308299_Auto(cocos2d::Lua&);
extern void RegisterLuaNavMeshTextureFlagAnonymousEnum__2753430244883972378_Auto(cocos2d::Lua&);
extern void RegisterLuaNavMeshNavMeshObstacleAuto(cocos2d::Lua&);
extern void RegisterLuaNavMeshNavMeshAuto(cocos2d::Lua&);
void RegisterLuaNavMeshAuto(cocos2d::Lua& lua){
#if CC_USE_NAVMESH
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaNavMeshNavMeshAgentAuto(lua);
RegisterLuaNavMeshbackendProgramTypeAnonymousEnum_1348959449711010928_Auto(lua);
RegisterLuaNavMeshTextureFormatEXTAnonymousEnum__8996569140777308299_Auto(lua);
RegisterLuaNavMeshTextureFlagAnonymousEnum__2753430244883972378_Auto(lua);
RegisterLuaNavMeshNavMeshObstacleAuto(lua);
RegisterLuaNavMeshNavMeshAuto(lua);
#endif
}