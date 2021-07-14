#include "scripting/lua-bindings/auto/CCRegisterLuaControllerAuto.hpp"
#include "base/CCGameController.h"
namespace cocos2d{
extern void RegisterLuaControllerControllerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaControllerEventControllerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaControllerEventListenerControllerAuto(cocos2d::extension::Lua&);
void RegisterLuaControllerAuto(cocos2d::extension::Lua& lua){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaControllerControllerAuto(lua);
RegisterLuaControllerEventControllerAuto(lua);
RegisterLuaControllerEventListenerControllerAuto(lua);
#endif
}
}