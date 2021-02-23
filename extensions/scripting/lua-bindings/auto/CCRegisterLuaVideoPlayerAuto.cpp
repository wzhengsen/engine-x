#include "scripting/lua-bindings/auto/CCRegisterLuaVideoPlayerAuto.hpp"
#include "ui/UIVideoPlayer/UIVideoPlayer.h"
extern void RegisterLuaVideoPlayerVideoPlayerAuto(cocos2d::Lua&);
void RegisterLuaVideoPlayerAuto(cocos2d::Lua& lua){
RegisterLuaVideoPlayerVideoPlayerAuto(lua);
}