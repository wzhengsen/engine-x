#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
extern void RegisterLuaCSLoaderbackendProgramTypeAnonymousEnum_7806005948016515557_Auto(cocos2d::Lua&);
extern void RegisterLuaCSLoaderTextureFormatEXTAnonymousEnum_5937429663859482893_Auto(cocos2d::Lua&);
extern void RegisterLuaCSLoaderTextureFlagAnonymousEnum__1308082027129547088_Auto(cocos2d::Lua&);
extern void RegisterLuaCSLoaderCSLoaderAuto(cocos2d::Lua&);
void RegisterLuaCSLoaderAuto(cocos2d::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaCSLoaderbackendProgramTypeAnonymousEnum_7806005948016515557_Auto(lua);
RegisterLuaCSLoaderTextureFormatEXTAnonymousEnum_5937429663859482893_Auto(lua);
RegisterLuaCSLoaderTextureFlagAnonymousEnum__1308082027129547088_Auto(lua);
RegisterLuaCSLoaderCSLoaderAuto(lua);
}