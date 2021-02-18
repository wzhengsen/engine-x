#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if CC_USE_NAVMESH
#ifndef __lua_NavMesh_auto_h__
#define __lua_NavMesh_auto_h__
void RegisterLuaNavMeshAuto(cocos2d::Lua&);
#endif // __lua_NavMesh_auto_h__
#endif //#if CC_USE_NAVMESH
