#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreParticleFireAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFire,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFire");
mt.set_function("init",static_cast<bool(cocos2d::ParticleFire::*)()>(&cocos2d::ParticleFire::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleFire::*)(int)>(&cocos2d::ParticleFire::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles));
}
void RegisterLuaCoreParticleFireworksAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFireworks,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFireworks");
mt.set_function("init",static_cast<bool(cocos2d::ParticleFireworks::*)()>(&cocos2d::ParticleFireworks::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleFireworks::*)(int)>(&cocos2d::ParticleFireworks::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles));
}
void RegisterLuaCoreParticleSunAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSun,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSun");
mt.set_function("init",static_cast<bool(cocos2d::ParticleSun::*)()>(&cocos2d::ParticleSun::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleSun::*)(int)>(&cocos2d::ParticleSun::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles));
}
void RegisterLuaCoreParticleGalaxyAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleGalaxy,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleGalaxy");
mt.set_function("init",static_cast<bool(cocos2d::ParticleGalaxy::*)()>(&cocos2d::ParticleGalaxy::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleGalaxy::*)(int)>(&cocos2d::ParticleGalaxy::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles));
}
void RegisterLuaCoreParticleFlowerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFlower,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFlower");
mt.set_function("init",static_cast<bool(cocos2d::ParticleFlower::*)()>(&cocos2d::ParticleFlower::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleFlower::*)(int)>(&cocos2d::ParticleFlower::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleFlower*(*)()>(&cocos2d::ParticleFlower::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFlower*(*)(int)>(&cocos2d::ParticleFlower::createWithTotalParticles));
}
void RegisterLuaCoreParticleMeteorAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleMeteor,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleMeteor");
mt.set_function("init",static_cast<bool(cocos2d::ParticleMeteor::*)()>(&cocos2d::ParticleMeteor::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleMeteor::*)(int)>(&cocos2d::ParticleMeteor::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleMeteor*(*)()>(&cocos2d::ParticleMeteor::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleMeteor*(*)(int)>(&cocos2d::ParticleMeteor::createWithTotalParticles));
}
void RegisterLuaCoreParticleSpiralAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSpiral,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSpiral");
mt.set_function("init",static_cast<bool(cocos2d::ParticleSpiral::*)()>(&cocos2d::ParticleSpiral::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleSpiral::*)(int)>(&cocos2d::ParticleSpiral::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleSpiral*(*)()>(&cocos2d::ParticleSpiral::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSpiral*(*)(int)>(&cocos2d::ParticleSpiral::createWithTotalParticles));
}
void RegisterLuaCoreParticleExplosionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleExplosion,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleExplosion");
mt.set_function("init",static_cast<bool(cocos2d::ParticleExplosion::*)()>(&cocos2d::ParticleExplosion::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleExplosion::*)(int)>(&cocos2d::ParticleExplosion::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleExplosion*(*)()>(&cocos2d::ParticleExplosion::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleExplosion*(*)(int)>(&cocos2d::ParticleExplosion::createWithTotalParticles));
}
void RegisterLuaCoreParticleSmokeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSmoke,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSmoke");
mt.set_function("init",static_cast<bool(cocos2d::ParticleSmoke::*)()>(&cocos2d::ParticleSmoke::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleSmoke::*)(int)>(&cocos2d::ParticleSmoke::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleSmoke*(*)()>(&cocos2d::ParticleSmoke::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSmoke*(*)(int)>(&cocos2d::ParticleSmoke::createWithTotalParticles));
}
void RegisterLuaCoreParticleSnowAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSnow,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSnow");
mt.set_function("init",static_cast<bool(cocos2d::ParticleSnow::*)()>(&cocos2d::ParticleSnow::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleSnow::*)(int)>(&cocos2d::ParticleSnow::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleSnow*(*)()>(&cocos2d::ParticleSnow::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSnow*(*)(int)>(&cocos2d::ParticleSnow::createWithTotalParticles));
}
void RegisterLuaCoreParticleRainAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleRain,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleRain");
mt.set_function("init",static_cast<bool(cocos2d::ParticleRain::*)()>(&cocos2d::ParticleRain::init));
mt.set_function("initWithTotalParticles",static_cast<bool(cocos2d::ParticleRain::*)(int)>(&cocos2d::ParticleRain::initWithTotalParticles));
mt.set_function("new",static_cast<cocos2d::ParticleRain*(*)()>(&cocos2d::ParticleRain::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleRain*(*)(int)>(&cocos2d::ParticleRain::createWithTotalParticles));
}
void RegisterLuaCoreProgressTimerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProgressTimer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ProgressTimer");
mt.set_function("getType",static_cast<cocos2d::ProgressTimer::Type(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getType));
mt.set_function("getPercentage",static_cast<float(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getPercentage));
mt.set_function("getSprite",static_cast<cocos2d::Sprite*(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getSprite));
mt.set_function("setPercentage",static_cast<void(cocos2d::ProgressTimer::*)(float)>(&cocos2d::ProgressTimer::setPercentage));
mt.set_function("setSprite",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::setSprite));
mt.set_function("setType",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::ProgressTimer::Type)>(&cocos2d::ProgressTimer::setType));
mt.set_function("isReverseDirection",static_cast<bool(cocos2d::ProgressTimer::*)()>(&cocos2d::ProgressTimer::isReverseDirection));
mt.set_function("setReverseDirection",static_cast<void(cocos2d::ProgressTimer::*)(bool)>(&cocos2d::ProgressTimer::setReverseDirection));
mt.set_function("setMidpoint",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setMidpoint));
mt.set_function("getMidpoint",static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getMidpoint));
mt.set_function("setBarChangeRate",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setBarChangeRate));
mt.set_function("getBarChangeRate",static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getBarChangeRate));
mt.set_function("draw",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProgressTimer::draw));
mt.set_function("setAnchorPoint",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setAnchorPoint));
mt.set_function("setColor",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Color3B&)>(&cocos2d::ProgressTimer::setColor));
mt.set_function("getColor",static_cast<const cocos2d::Color3B&(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getColor));
mt.set_function("setOpacity",static_cast<void(cocos2d::ProgressTimer::*)(uint8_t)>(&cocos2d::ProgressTimer::setOpacity));
mt.set_function("getOpacity",static_cast<uint8_t(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getOpacity));
mt.set_function("initWithSprite",static_cast<bool(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::initWithSprite));
mt.set_function("new",static_cast<cocos2d::ProgressTimer*(*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::create));
}
void RegisterLuaCoreProtectedNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ProtectedNode");
mt.set_function("addProtectedChild",sol::overload(static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ProtectedNode::addProtectedChild)));
mt.set_function("getProtectedChildByTag",static_cast<cocos2d::Node*(cocos2d::ProtectedNode::*)(int)>(&cocos2d::ProtectedNode::getProtectedChildByTag));
mt.set_function("removeProtectedChild",sol::overload([](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0){return obj->removeProtectedChild(arg0);},[](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0,bool arg1){return obj->removeProtectedChild(arg0,arg1);}));
mt.set_function("removeProtectedChildByTag",sol::overload([](cocos2d::ProtectedNode* obj,int arg0){return obj->removeProtectedChildByTag(arg0);},[](cocos2d::ProtectedNode* obj,int arg0,bool arg1){return obj->removeProtectedChildByTag(arg0,arg1);}));
mt.set_function("removeAllProtectedChildren",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::removeAllProtectedChildren));
mt.set_function("removeAllProtectedChildrenWithCleanup",static_cast<void(cocos2d::ProtectedNode::*)(bool)>(&cocos2d::ProtectedNode::removeAllProtectedChildrenWithCleanup));
mt.set_function("reorderProtectedChild",static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::reorderProtectedChild));
mt.set_function("sortAllProtectedChildren",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::sortAllProtectedChildren));
mt.set_function("visit",static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProtectedNode::visit));
mt.set_function("cleanup",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::cleanup));
mt.set_function("updateDisplayedOpacity",static_cast<void(cocos2d::ProtectedNode::*)(uint8_t)>(&cocos2d::ProtectedNode::updateDisplayedOpacity));
mt.set_function("updateDisplayedColor",static_cast<void(cocos2d::ProtectedNode::*)(const cocos2d::Color3B&)>(&cocos2d::ProtectedNode::updateDisplayedColor));
mt.set_function("disableCascadeColor",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeColor));
mt.set_function("disableCascadeOpacity",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeOpacity));
mt.set_function("setCameraMask",sol::overload([](cocos2d::ProtectedNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ProtectedNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("setGlobalZOrder",static_cast<void(cocos2d::ProtectedNode::*)(float)>(&cocos2d::ProtectedNode::setGlobalZOrder));
mt.set_function("new",static_cast<cocos2d::ProtectedNode*(*)()>(&cocos2d::ProtectedNode::create));
}
void RegisterLuaCoreSpriteAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","Sprite");
mt.set_function("updateTransform",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::updateTransform));
mt.set_function("getBatchNode",static_cast<cocos2d::SpriteBatchNode*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBatchNode));
mt.set_function("setBatchNode",static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteBatchNode*)>(&cocos2d::Sprite::setBatchNode));
mt.set_function("setTexture",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::setTexture),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setTexture)));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTexture));
mt.set_function("setTextureRect",sol::overload(static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&,bool,const cocos2d::Size&)>(&cocos2d::Sprite::setTextureRect),static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setTextureRect)));
mt.set_function("setVertexRect",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setVertexRect));
mt.set_function("setCenterRectNormalized",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRectNormalized));
mt.set_function("getCenterRectNormalized",static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRectNormalized));
mt.set_function("setCenterRect",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRect));
mt.set_function("getCenterRect",static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRect));
mt.set_function("setSpriteFrame",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::setSpriteFrame),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setSpriteFrame)));
mt.set_function("isFrameDisplayed",static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)const>(&cocos2d::Sprite::isFrameDisplayed));
mt.set_function("getSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getSpriteFrame));
mt.set_function("setDisplayFrameWithAnimationName",static_cast<void(cocos2d::Sprite::*)(const std::string&,unsigned int)>(&cocos2d::Sprite::setDisplayFrameWithAnimationName));
mt.set_function("isDirty",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isDirty));
mt.set_function("setDirty",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setDirty));
mt.set_function("getDescription",static_cast<std::string(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getDescription));
mt.set_function("setScaleX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleX));
mt.set_function("setScaleY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleY));
mt.set_function("setScale",sol::overload(static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScale),static_cast<void(cocos2d::Sprite::*)(float,float)>(&cocos2d::Sprite::setScale)));
mt.set_function("setRotation",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotation));
mt.set_function("setRotationSkewX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewX));
mt.set_function("setRotationSkewY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewY));
mt.set_function("setSkewX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewX));
mt.set_function("setSkewY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewY));
mt.set_function("removeChild",static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,bool)>(&cocos2d::Sprite::removeChild));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::removeAllChildrenWithCleanup));
mt.set_function("reorderChild",static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int)>(&cocos2d::Sprite::reorderChild));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Sprite::addChild),static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,int)>(&cocos2d::Sprite::addChild)));
mt.set_function("sortAllChildren",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::sortAllChildren));
mt.set_function("setPositionZ",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setPositionZ));
mt.set_function("setAnchorPoint",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Vec2&)>(&cocos2d::Sprite::setAnchorPoint));
mt.set_function("setContentSize",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Size&)>(&cocos2d::Sprite::setContentSize));
mt.set_function("setIgnoreAnchorPointForPosition",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setIgnoreAnchorPointForPosition));
mt.set_function("setVisible",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setVisible));
mt.set_function("draw",static_cast<void(cocos2d::Sprite::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite::draw));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isOpacityModifyRGB));
mt.set_function("isTextureRectRotated",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isTextureRectRotated));
mt.set_function("getAtlasIndex",static_cast<unsigned int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getAtlasIndex));
mt.set_function("setAtlasIndex",static_cast<void(cocos2d::Sprite::*)(unsigned int)>(&cocos2d::Sprite::setAtlasIndex));
mt.set_function("getTextureRect",static_cast<const cocos2d::Rect&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureRect));
mt.set_function("getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureAtlas));
mt.set_function("setProgramState",sol::overload(static_cast<void(cocos2d::Sprite::*)(uint32_t)>(&cocos2d::Sprite::setProgramState),[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("setTextureAtlas",static_cast<void(cocos2d::Sprite::*)(cocos2d::TextureAtlas*)>(&cocos2d::Sprite::setTextureAtlas));
mt.set_function("getOffsetPosition",static_cast<const cocos2d::Vec2&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getOffsetPosition));
mt.set_function("isFlippedX",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedX));
mt.set_function("setFlippedX",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedX));
mt.set_function("isFlippedY",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedY));
mt.set_function("setFlippedY",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedY));
mt.set_function("setStretchEnabled",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setStretchEnabled));
mt.set_function("isStretchEnabled",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isStretchEnabled));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::Sprite::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBlendFunc));
mt.set_function("getResourceType",static_cast<int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceType));
mt.set_function("getResourceName",static_cast<const std::string&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceName));
mt.set_function("init",static_cast<bool(cocos2d::Sprite::*)()>(&cocos2d::Sprite::init));
mt.set_function("initWithTexture",sol::overload(static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Sprite::initWithTexture),static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::initWithTexture),static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool)>(&cocos2d::Sprite::initWithTexture)));
mt.set_function("initWithSpriteFrame",static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::initWithSpriteFrame));
mt.set_function("initWithSpriteFrameName",static_cast<bool(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::initWithSpriteFrameName));
mt.set_function("initWithFile",sol::overload(static_cast<bool(cocos2d::Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::Sprite::initWithFile),static_cast<bool(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::initWithFile)));
mt.set_function("setVertexLayout",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::setVertexLayout));
mt.set_function("createWithTexture",sol::overload([](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1){return obj->createWithTexture(arg0,arg1);},[](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1,bool arg2){return obj->createWithTexture(arg0,arg1,arg2);},static_cast<cocos2d::Sprite*(*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::createWithTexture)));
mt.set_function("createWithSpriteFrame",static_cast<cocos2d::Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::createWithSpriteFrame));
mt.set_function("createWithSpriteFrameName",static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::createWithSpriteFrameName));
}
void RegisterLuaCoreRenderTextureAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RenderTexture,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","RenderTexture");
mt.set_function("visit",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::visit));
mt.set_function("draw",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::draw));
mt.set_function("begin",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::begin));
mt.set_function("beginWithClear",sol::overload(static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float,int)>(&cocos2d::RenderTexture::beginWithClear)));
mt.set_function("endToLua",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::end));
mt.set_function("clear",static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::clear));
mt.set_function("clearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::clearDepth));
mt.set_function("clearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::clearStencil));
mt.set_function("saveToFileAsNonPMA",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(const std::string&,cocos2d::Image::Format,bool,std::function<void (cocos2d::RenderTexture *, const std::string&)>)>(&cocos2d::RenderTexture::saveToFileAsNonPMA),[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFileAsNonPMA(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFileAsNonPMA(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFileAsNonPMA(arg0,arg1,arg2);}));
mt.set_function("saveToFile",sol::overload([](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg3){return obj->saveToFile(arg0,arg1,arg2,arg3);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFile(arg0,arg1,arg2);}));
mt.set_function("getClearFlags",static_cast<cocos2d::ClearFlag(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearFlags));
mt.set_function("setClearFlags",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::ClearFlag)>(&cocos2d::RenderTexture::setClearFlags));
mt.set_function("getClearColor",static_cast<const cocos2d::Color4F&(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearColor));
mt.set_function("setClearColor",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Color4F&)>(&cocos2d::RenderTexture::setClearColor));
mt.set_function("getClearDepth",static_cast<float(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearDepth));
mt.set_function("setClearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::setClearDepth));
mt.set_function("getClearStencil",static_cast<int(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearStencil));
mt.set_function("setClearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::setClearStencil));
mt.set_function("isAutoDraw",static_cast<bool(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::isAutoDraw));
mt.set_function("setAutoDraw",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setAutoDraw));
mt.set_function("getSprite",static_cast<cocos2d::Sprite*(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getSprite));
mt.set_function("setSprite",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Sprite*)>(&cocos2d::RenderTexture::setSprite));
mt.set_function("setKeepMatrix",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setKeepMatrix));
mt.set_function("setVirtualViewport",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Vec2&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::RenderTexture::setVirtualViewport));
mt.set_function("initWithWidthAndHeight",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight),static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight)));
mt.set_function("new",sol::overload(static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int)>(&cocos2d::RenderTexture::create)));
}
