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
#include "network/CCConnection.h"
void RegisterLuaCoreParticleSystemQuadAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleSystemQuad).name()] = sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleSystemQuad>("deprecated.cocos2d::ParticleSystemQuad");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystem*>::metatable());
lua["cc"]["ParticleSystemQuad"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ParticleSystemQuad*(*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)(const std::string&)>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)()>(&cocos2d::ParticleSystemQuad::create));
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleSystemQuad*(*)(int)>(&cocos2d::ParticleSystemQuad::createWithTotalParticles);
mt["SetDisplayFrame"]=static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::SpriteFrame*)>(&cocos2d::ParticleSystemQuad::setDisplayFrame);
mt["set"]["DisplayFrame"]=mt["SetDisplayFrame"];
mt["SetTextureWithRect"]=static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::ParticleSystemQuad::setTextureWithRect);
mt["ListenRendererRecreated"]=static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::EventCustom*)>(&cocos2d::ParticleSystemQuad::listenRendererRecreated);
}
void RegisterLuaCoreParticleFireAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleFire).name()] = sol::usertype_traits<cocos2d::ParticleFire*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleFire>("deprecated.cocos2d::ParticleFire");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleFire*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleFire"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles);
}
void RegisterLuaCoreParticleFireworksAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleFireworks).name()] = sol::usertype_traits<cocos2d::ParticleFireworks*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleFireworks>("deprecated.cocos2d::ParticleFireworks");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleFireworks*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleFireworks"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles);
}
void RegisterLuaCoreParticleSunAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleSun).name()] = sol::usertype_traits<cocos2d::ParticleSun*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleSun>("deprecated.cocos2d::ParticleSun");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleSun*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleSun"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles);
}
void RegisterLuaCoreParticleGalaxyAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleGalaxy).name()] = sol::usertype_traits<cocos2d::ParticleGalaxy*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleGalaxy>("deprecated.cocos2d::ParticleGalaxy");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleGalaxy*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleGalaxy"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles);
}
void RegisterLuaCoreParticleFlowerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleFlower).name()] = sol::usertype_traits<cocos2d::ParticleFlower*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleFlower>("deprecated.cocos2d::ParticleFlower");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleFlower*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleFlower"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleFlower*(*)()>(&cocos2d::ParticleFlower::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleFlower*(*)(int)>(&cocos2d::ParticleFlower::createWithTotalParticles);
}
void RegisterLuaCoreParticleMeteorAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleMeteor).name()] = sol::usertype_traits<cocos2d::ParticleMeteor*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleMeteor>("deprecated.cocos2d::ParticleMeteor");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleMeteor*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleMeteor"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleMeteor*(*)()>(&cocos2d::ParticleMeteor::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleMeteor*(*)(int)>(&cocos2d::ParticleMeteor::createWithTotalParticles);
}
void RegisterLuaCoreParticleSpiralAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleSpiral).name()] = sol::usertype_traits<cocos2d::ParticleSpiral*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleSpiral>("deprecated.cocos2d::ParticleSpiral");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleSpiral*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleSpiral"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleSpiral*(*)()>(&cocos2d::ParticleSpiral::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleSpiral*(*)(int)>(&cocos2d::ParticleSpiral::createWithTotalParticles);
}
void RegisterLuaCoreParticleExplosionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleExplosion).name()] = sol::usertype_traits<cocos2d::ParticleExplosion*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleExplosion>("deprecated.cocos2d::ParticleExplosion");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleExplosion*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleExplosion"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleExplosion*(*)()>(&cocos2d::ParticleExplosion::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleExplosion*(*)(int)>(&cocos2d::ParticleExplosion::createWithTotalParticles);
}
void RegisterLuaCoreParticleSmokeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleSmoke).name()] = sol::usertype_traits<cocos2d::ParticleSmoke*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleSmoke>("deprecated.cocos2d::ParticleSmoke");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleSmoke*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleSmoke"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleSmoke*(*)()>(&cocos2d::ParticleSmoke::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleSmoke*(*)(int)>(&cocos2d::ParticleSmoke::createWithTotalParticles);
}
