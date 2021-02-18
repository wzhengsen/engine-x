#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if CC_USE_PHYSICS
#ifndef __lua_Physics_auto_h__
#define __lua_Physics_auto_h__
void RegisterLuaPhysicsAuto(cocos2d::Lua&);
#endif // __lua_Physics_auto_h__
#endif //#if CC_USE_PHYSICS
