#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if CC_USE_PHYSICS
#ifndef __lua_cocos2dx_physics_auto_h__
#define __lua_cocos2dx_physics_auto_h__
void register_all_cocos2dx_physics(cocos2d::Lua&);
#endif // __lua_cocos2dx_physics_auto_h__
#endif //#if CC_USE_PHYSICS
