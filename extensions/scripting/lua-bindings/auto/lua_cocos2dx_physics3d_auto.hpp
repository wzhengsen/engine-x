#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
#ifndef __lua_cocos2dx_physics3d_auto_h__
#define __lua_cocos2dx_physics3d_auto_h__
void register_all_cocos2dx_physics3d(cocos2d::Lua&);
#endif // __lua_cocos2dx_physics3d_auto_h__
#endif //#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
