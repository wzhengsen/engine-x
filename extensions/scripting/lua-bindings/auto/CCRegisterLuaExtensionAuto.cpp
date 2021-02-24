#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
#include "Particle3D/PU/CCPUEmitter.h"
#include "Particle3D/PU/CCPUAffector.h"
#include "Particle3D/PU/CCPUObserver.h"
#include "Particle3D/CCParticle3DAffector.h"
extern void RegisterLuaExtensionEventAssetsManagerExAuto(cocos2d::Lua&);
extern void RegisterLuaExtensionManifestAuto(cocos2d::Lua&);
extern void RegisterLuaExtensionAssetsManagerExAuto(cocos2d::Lua&);
extern void RegisterLuaExtensionEventListenerAssetsManagerExAuto(cocos2d::Lua&);
extern void RegisterLuaExtensionParticleSystem3DAuto(cocos2d::Lua&);
extern void RegisterLuaExtensionPUParticleSystem3DAuto(cocos2d::Lua&);
void RegisterLuaExtensionAuto(cocos2d::Lua& lua){
RegisterLuaExtensionEventAssetsManagerExAuto(lua);
RegisterLuaExtensionManifestAuto(lua);
RegisterLuaExtensionAssetsManagerExAuto(lua);
RegisterLuaExtensionEventListenerAssetsManagerExAuto(lua);
RegisterLuaExtensionParticleSystem3DAuto(lua);
RegisterLuaExtensionPUParticleSystem3DAuto(lua);
}