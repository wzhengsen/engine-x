#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
#ifndef __lua_Physics3d_auto_h__
#define __lua_Physics3d_auto_h__
void RegisterLuaPhysics3dAuto(cocos2d::Lua&);
#endif // __lua_Physics3d_auto_h__
#endif //#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
