#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
namespace cocos2d{
extern void RegisterLuaCSLoaderCSLoaderAuto(cocos2d::extension::Lua&);
void RegisterLuaCSLoaderAuto(cocos2d::extension::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaCSLoaderCSLoaderAuto(lua);
}
}