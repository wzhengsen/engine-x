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
void RegisterLuaCoreParticleSunAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSun>("cc","ParticleSun",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles));
}
void RegisterLuaCoreParticleGalaxyAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleGalaxy>("cc","ParticleGalaxy",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles));
}
void RegisterLuaCoreParticleFlowerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFlower>("cc","ParticleFlower",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleFlower*(*)()>(&cocos2d::ParticleFlower::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleFlower*(*)(int)>(&cocos2d::ParticleFlower::createWithTotalParticles));
}
void RegisterLuaCoreParticleMeteorAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleMeteor>("cc","ParticleMeteor",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleMeteor*(*)()>(&cocos2d::ParticleMeteor::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleMeteor*(*)(int)>(&cocos2d::ParticleMeteor::createWithTotalParticles));
}
void RegisterLuaCoreParticleSpiralAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSpiral>("cc","ParticleSpiral",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSpiral*(*)()>(&cocos2d::ParticleSpiral::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleSpiral*(*)(int)>(&cocos2d::ParticleSpiral::createWithTotalParticles));
}
void RegisterLuaCoreParticleExplosionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleExplosion>("cc","ParticleExplosion",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleExplosion*(*)()>(&cocos2d::ParticleExplosion::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleExplosion*(*)(int)>(&cocos2d::ParticleExplosion::createWithTotalParticles));
}
void RegisterLuaCoreParticleSmokeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSmoke>("cc","ParticleSmoke",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSmoke*(*)()>(&cocos2d::ParticleSmoke::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleSmoke*(*)(int)>(&cocos2d::ParticleSmoke::createWithTotalParticles));
}
void RegisterLuaCoreParticleSnowAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSnow>("cc","ParticleSnow",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSnow*(*)()>(&cocos2d::ParticleSnow::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleSnow*(*)(int)>(&cocos2d::ParticleSnow::createWithTotalParticles));
}
void RegisterLuaCoreParticleRainAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleRain>("cc","ParticleRain",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleRain*(*)()>(&cocos2d::ParticleRain::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleRain*(*)(int)>(&cocos2d::ParticleRain::createWithTotalParticles));
}
void RegisterLuaCoreProgressTimerTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["ProgressTimer"];
pTable.new_enum<cocos2d::ProgressTimer::Type>("Type",{
{"RADIAL",cocos2d::ProgressTimer::Type::RADIAL}
,{"BAR",cocos2d::ProgressTimer::Type::BAR}
});}
void RegisterLuaCoreProgressTimerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProgressTimer>("cc","ProgressTimer",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ProgressTimer*(*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::create));
mt.set_function("GetType",static_cast<cocos2d::ProgressTimer::Type(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getType));
mt.set_function("GetPercentage",static_cast<float(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getPercentage));
mt.set_function("GetSprite",static_cast<cocos2d::Sprite*(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getSprite));
mt.set_function("SetPercentage",static_cast<void(cocos2d::ProgressTimer::*)(float)>(&cocos2d::ProgressTimer::setPercentage));
mt.set_function("SetSprite",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::setSprite));
mt.set_function("SetType",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::ProgressTimer::Type)>(&cocos2d::ProgressTimer::setType));
mt.set_function("IsReverseDirection",static_cast<bool(cocos2d::ProgressTimer::*)()>(&cocos2d::ProgressTimer::isReverseDirection));
mt.set_function("SetReverseDirection",static_cast<void(cocos2d::ProgressTimer::*)(bool)>(&cocos2d::ProgressTimer::setReverseDirection));
mt.set_function("SetMidpoint",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setMidpoint));
mt.set_function("GetMidpoint",static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getMidpoint));
mt.set_function("SetBarChangeRate",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setBarChangeRate));
mt.set_function("GetBarChangeRate",static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getBarChangeRate));
mt.set_function("Draw",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProgressTimer::draw));
mt.set_function("SetAnchorPoint",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setAnchorPoint));
mt.set_function("SetColor",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Color3B&)>(&cocos2d::ProgressTimer::setColor));
mt.set_function("GetColor",static_cast<const cocos2d::Color3B&(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getColor));
mt.set_function("SetOpacity",static_cast<void(cocos2d::ProgressTimer::*)(uint8_t)>(&cocos2d::ProgressTimer::setOpacity));
mt.set_function("GetOpacity",static_cast<uint8_t(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getOpacity));
RegisterLuaCoreProgressTimerTypeAuto(lua);
}
