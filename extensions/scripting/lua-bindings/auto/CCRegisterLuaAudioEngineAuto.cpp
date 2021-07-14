#include "scripting/lua-bindings/auto/CCRegisterLuaAudioEngineAuto.hpp"
#include "audio/include/AudioEngine.h"
namespace cocos2d{
extern void RegisterLuaAudioEngineAudioProfileAuto(cocos2d::extension::Lua&);
extern void RegisterLuaAudioEngineAudioEngineAuto(cocos2d::extension::Lua&);
void RegisterLuaAudioEngineAuto(cocos2d::extension::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaAudioEngineAudioProfileAuto(lua);
RegisterLuaAudioEngineAudioEngineAuto(lua);
}
}