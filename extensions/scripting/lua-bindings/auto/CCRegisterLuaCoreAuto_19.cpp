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
namespace cocos2d{
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
void RegisterLuaCoreParticleSnowAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleSnow).name()] = sol::usertype_traits<cocos2d::ParticleSnow*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleSnow>("deprecated.cocos2d::ParticleSnow");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleSnow*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleSnow"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleSnow*(*)()>(&cocos2d::ParticleSnow::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleSnow*(*)(int)>(&cocos2d::ParticleSnow::createWithTotalParticles);
}
void RegisterLuaCoreParticleRainAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleRain).name()] = sol::usertype_traits<cocos2d::ParticleRain*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleRain>("deprecated.cocos2d::ParticleRain");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleRain*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleRain"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleRain*(*)()>(&cocos2d::ParticleRain::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleRain*(*)(int)>(&cocos2d::ParticleRain::createWithTotalParticles);
}
void RegisterLuaCoreProgressTimerTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,2);
enumTable["RADIAL"]=cocos2d::ProgressTimer::Type::RADIAL;
enumTable["BAR"]=cocos2d::ProgressTimer::Type::BAR;
lua["cc"]["ProgressTimer"]["static"]["Type"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreProgressTimerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ProgressTimer).name()] = sol::usertype_traits<cocos2d::ProgressTimer*>::metatable();
auto dep=lua.new_usertype<cocos2d::ProgressTimer>("deprecated.cocos2d::ProgressTimer");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ProgressTimer*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ProgressTimer"]=mt;
mt["__new__"]=static_cast<cocos2d::ProgressTimer*(*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::create);
mt["GetType"]=static_cast<cocos2d::ProgressTimer::Type(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getType);
mt["get"]["Type"]=mt["GetType"];
mt["GetPercentage"]=static_cast<float(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getPercentage);
mt["get"]["Percentage"]=mt["GetPercentage"];
mt["GetSprite"]=static_cast<cocos2d::Sprite*(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getSprite);
mt["get"]["Sprite"]=mt["GetSprite"];
mt["SetPercentage"]=static_cast<void(cocos2d::ProgressTimer::*)(float)>(&cocos2d::ProgressTimer::setPercentage);
mt["set"]["Percentage"]=mt["SetPercentage"];
mt["SetSprite"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::setSprite);
mt["set"]["Sprite"]=mt["SetSprite"];
mt["SetType"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::ProgressTimer::Type)>(&cocos2d::ProgressTimer::setType);
mt["set"]["Type"]=mt["SetType"];
mt["IsReverseDirection"]=static_cast<bool(cocos2d::ProgressTimer::*)()>(&cocos2d::ProgressTimer::isReverseDirection);
mt["get"]["ReverseDirection"]=mt["IsReverseDirection"];
mt["SetReverseDirection"]=static_cast<void(cocos2d::ProgressTimer::*)(bool)>(&cocos2d::ProgressTimer::setReverseDirection);
mt["set"]["ReverseDirection"]=mt["SetReverseDirection"];
mt["SetMidpoint"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setMidpoint);
mt["set"]["Midpoint"]=mt["SetMidpoint"];
mt["GetMidpoint"]=static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getMidpoint);
mt["get"]["Midpoint"]=mt["GetMidpoint"];
mt["SetBarChangeRate"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setBarChangeRate);
mt["set"]["BarChangeRate"]=mt["SetBarChangeRate"];
mt["GetBarChangeRate"]=static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getBarChangeRate);
mt["get"]["BarChangeRate"]=mt["GetBarChangeRate"];
RegisterLuaCoreProgressTimerTypeAuto(lua);
}
void RegisterLuaCoreProtectedNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ProtectedNode).name()] = sol::usertype_traits<cocos2d::ProtectedNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::ProtectedNode>("deprecated.cocos2d::ProtectedNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ProtectedNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ProtectedNode"]=mt;
mt["__new__"]=static_cast<cocos2d::ProtectedNode*(*)()>(&cocos2d::ProtectedNode::create);
mt["AddProtectedChild"]=sol::overload(static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*)>(&cocos2d::ProtectedNode::addProtectedChild));
mt["GetProtectedChildByTag"]=static_cast<cocos2d::Node*(cocos2d::ProtectedNode::*)(int)>(&cocos2d::ProtectedNode::getProtectedChildByTag);
mt["RemoveProtectedChild"]=sol::overload([](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0,bool arg1){return obj->removeProtectedChild(arg0,arg1);},[](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0){return obj->removeProtectedChild(arg0);});
mt["RemoveProtectedChildByTag"]=sol::overload([](cocos2d::ProtectedNode* obj,int arg0,bool arg1){return obj->removeProtectedChildByTag(arg0,arg1);},[](cocos2d::ProtectedNode* obj,int arg0){return obj->removeProtectedChildByTag(arg0);});
mt["RemoveAllProtectedChildren"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::removeAllProtectedChildren);
mt["RemoveAllProtectedChildrenWithCleanup"]=static_cast<void(cocos2d::ProtectedNode::*)(bool)>(&cocos2d::ProtectedNode::removeAllProtectedChildrenWithCleanup);
mt["ReorderProtectedChild"]=static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::reorderProtectedChild);
mt["SortAllProtectedChildren"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::sortAllProtectedChildren);
mt["DisableCascadeColor"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeColor);
mt["DisableCascadeOpacity"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeOpacity);
}
}
