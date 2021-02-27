#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
void RegisterLuaCoreParticleFireAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleFire,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleFire",false);
ns["ParticleFire"] = mt;
lua["ParticleFire"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles));
}
void RegisterLuaCoreParticleFireworksAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleFireworks,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleFireworks",false);
ns["ParticleFireworks"] = mt;
lua["ParticleFireworks"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles));
}
void RegisterLuaCoreParticleSunAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleSun,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleSun",false);
ns["ParticleSun"] = mt;
lua["ParticleSun"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles));
}
void RegisterLuaCoreParticleGalaxyAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleGalaxy,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleGalaxy",false);
ns["ParticleGalaxy"] = mt;
lua["ParticleGalaxy"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles));
}
void RegisterLuaCoreParticleFlowerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleFlower,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleFlower",false);
ns["ParticleFlower"] = mt;
lua["ParticleFlower"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleFlower*(*)()>(&cocos2d::ParticleFlower::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFlower*(*)(int)>(&cocos2d::ParticleFlower::createWithTotalParticles));
}
void RegisterLuaCoreParticleMeteorAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleMeteor,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleMeteor",false);
ns["ParticleMeteor"] = mt;
lua["ParticleMeteor"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleMeteor*(*)()>(&cocos2d::ParticleMeteor::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleMeteor*(*)(int)>(&cocos2d::ParticleMeteor::createWithTotalParticles));
}
void RegisterLuaCoreParticleSpiralAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleSpiral,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleSpiral",false);
ns["ParticleSpiral"] = mt;
lua["ParticleSpiral"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSpiral*(*)()>(&cocos2d::ParticleSpiral::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSpiral*(*)(int)>(&cocos2d::ParticleSpiral::createWithTotalParticles));
}
void RegisterLuaCoreParticleExplosionAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleExplosion,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleExplosion",false);
ns["ParticleExplosion"] = mt;
lua["ParticleExplosion"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleExplosion*(*)()>(&cocos2d::ParticleExplosion::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleExplosion*(*)(int)>(&cocos2d::ParticleExplosion::createWithTotalParticles));
}
void RegisterLuaCoreParticleSmokeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleSmoke,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleSmoke",false);
ns["ParticleSmoke"] = mt;
lua["ParticleSmoke"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSmoke*(*)()>(&cocos2d::ParticleSmoke::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSmoke*(*)(int)>(&cocos2d::ParticleSmoke::createWithTotalParticles));
}
void RegisterLuaCoreParticleSnowAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParticleSnow,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("ParticleSnow",false);
ns["ParticleSnow"] = mt;
lua["ParticleSnow"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSnow*(*)()>(&cocos2d::ParticleSnow::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSnow*(*)(int)>(&cocos2d::ParticleSnow::createWithTotalParticles));
}
