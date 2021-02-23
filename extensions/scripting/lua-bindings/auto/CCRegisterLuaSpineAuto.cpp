#include "scripting/lua-bindings/auto/CCRegisterLuaSpineAuto.hpp"
#include "spine/spine-cocos2dx.h"
extern void RegisterLuaSpineSkeletonRendererAuto(cocos2d::Lua&);
extern void RegisterLuaSpineSkeletonAnimationAuto(cocos2d::Lua&);
void RegisterLuaSpineAuto(cocos2d::Lua& lua){
RegisterLuaSpineSkeletonRendererAuto(lua);
RegisterLuaSpineSkeletonAnimationAuto(lua);
}