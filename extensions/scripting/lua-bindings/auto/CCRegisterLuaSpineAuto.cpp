#include "scripting/lua-bindings/auto/CCRegisterLuaSpineAuto.hpp"
#include "spine/spine-cocos2dx.h"
extern void RegisterLuaSpineSkeletonRendererAuto(cocos2d::extension::Lua&);
extern void RegisterLuaSpineSkeletonAnimationAuto(cocos2d::extension::Lua&);
void RegisterLuaSpineAuto(cocos2d::extension::Lua& lua){
lua["sp"]=lua.get_or("sp",lua.create_table());
RegisterLuaSpineSkeletonRendererAuto(lua);
RegisterLuaSpineSkeletonAnimationAuto(lua);
}