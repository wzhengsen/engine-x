#include "scripting/lua-bindings/auto/CCRegisterLuaAudioEngineAuto.hpp"
#include "audio/include/AudioEngine.h"
extern void RegisterLuaAudioEngineAudioProfileAuto(cocos2d::Lua&);
extern void RegisterLuaAudioEngineAudioEngineAuto(cocos2d::Lua&);
void RegisterLuaAudioEngineAuto(cocos2d::Lua& lua){
RegisterLuaAudioEngineAudioProfileAuto(lua);
RegisterLuaAudioEngineAudioEngineAuto(lua);
}