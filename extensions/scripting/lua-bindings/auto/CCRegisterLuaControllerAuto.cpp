#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#include "base/CCGameController.h"
extern void RegisterLuaControllerControllerAuto(cocos2d::Lua&);
extern void RegisterLuaControllerEventControllerAuto(cocos2d::Lua&);
extern void RegisterLuaControllerEventListenerControllerAuto(cocos2d::Lua&);
void RegisterLuaControllerAuto(cocos2d::Lua& lua){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
RegisterLuaControllerControllerAuto(lua);
RegisterLuaControllerEventControllerAuto(lua);
RegisterLuaControllerEventListenerControllerAuto(lua);
#endif
}