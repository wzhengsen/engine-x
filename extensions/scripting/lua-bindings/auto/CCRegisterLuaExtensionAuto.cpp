#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
#include "Particle3D/PU/CCPUEmitter.h"
#include "Particle3D/PU/CCPUAffector.h"
#include "Particle3D/PU/CCPUObserver.h"
#include "Particle3D/CCParticle3DAffector.h"
extern void RegisterLuaExtensionLuaObjectAuto(cocos2d::extension::Lua&);
extern void RegisterLuaExtensionEventAssetsManagerExAuto(cocos2d::extension::Lua&);
extern void RegisterLuaExtensionManifestAuto(cocos2d::extension::Lua&);
extern void RegisterLuaExtensionAssetsManagerExAuto(cocos2d::extension::Lua&);
extern void RegisterLuaExtensionEventListenerAssetsManagerExAuto(cocos2d::extension::Lua&);
void RegisterLuaExtensionAuto(cocos2d::extension::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaExtensionLuaObjectAuto(lua);
RegisterLuaExtensionEventAssetsManagerExAuto(lua);
RegisterLuaExtensionManifestAuto(lua);
RegisterLuaExtensionAssetsManagerExAuto(lua);
RegisterLuaExtensionEventListenerAssetsManagerExAuto(lua);
}