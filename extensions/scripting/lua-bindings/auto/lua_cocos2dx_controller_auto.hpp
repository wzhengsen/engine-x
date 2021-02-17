#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#ifndef __lua_cocos2dx_controller_auto_h__
#define __lua_cocos2dx_controller_auto_h__
void register_all_cocos2dx_controller(cocos2d::Lua&);
#endif // __lua_cocos2dx_controller_auto_h__
#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
