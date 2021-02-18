#include "base/ccConfig.h"
#include "scripting/lua-bindings/CCLua.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#ifndef __lua_Controller_auto_h__
#define __lua_Controller_auto_h__
void RegisterLuaControllerAuto(cocos2d::Lua&);
#endif // __lua_Controller_auto_h__
#endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
