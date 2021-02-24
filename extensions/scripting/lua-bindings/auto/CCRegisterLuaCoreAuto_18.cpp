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
void RegisterLuaCoreMotionStreakAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MotionStreak,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","MotionStreak");
mt.set_function("setPosition",sol::overload(static_cast<void(cocos2d::MotionStreak::*)(float,float)>(&cocos2d::MotionStreak::setPosition),static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak::setPosition)));
mt.set_function("getPosition",sol::overload(static_cast<void(cocos2d::MotionStreak::*)(float*,float*)const>(&cocos2d::MotionStreak::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition)));
mt.set_function("setPositionX",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionX));
mt.set_function("setPositionY",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionY));
mt.set_function("getPositionX",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionX));
mt.set_function("getPositionY",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionY));
mt.set_function("getPosition3D",static_cast<cocos2d::Vec3(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition3D));
mt.set_function("draw",static_cast<void(cocos2d::MotionStreak::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::MotionStreak::draw));
mt.set_function("update",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::update));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::MotionStreak::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak::setTexture));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getBlendFunc));
mt.set_function("getOpacity",static_cast<uint8_t(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getOpacity));
mt.set_function("setOpacity",static_cast<void(cocos2d::MotionStreak::*)(uint8_t)>(&cocos2d::MotionStreak::setOpacity));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isOpacityModifyRGB));
mt.set_function("tintWithColor",static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak::tintWithColor));
mt.set_function("reset",static_cast<void(cocos2d::MotionStreak::*)()>(&cocos2d::MotionStreak::reset));
mt.set_function("isFastMode",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isFastMode));
mt.set_function("setFastMode",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setFastMode));
mt.set_function("getStroke",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getStroke));
mt.set_function("setStroke",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setStroke));
mt.set_function("isStartingPositionInitialized",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isStartingPositionInitialized));
mt.set_function("setStartingPositionInitialized",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setStartingPositionInitialized));
mt.set_function("setProgramState",static_cast<bool(cocos2d::MotionStreak::*)(cocos2d::backend::ProgramState*,bool)>(&cocos2d::MotionStreak::setProgramState));
mt.set_function("new",sol::overload(static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak::create),static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak::create)));
}
void RegisterLuaCoreNodeGridAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NodeGrid,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","NodeGrid");
mt.set_function("getGrid",sol::overload(static_cast<const cocos2d::GridBase*(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGrid),static_cast<cocos2d::GridBase*(cocos2d::NodeGrid::*)()>(&cocos2d::NodeGrid::getGrid)));
mt.set_function("setGrid",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::GridBase*)>(&cocos2d::NodeGrid::setGrid));
mt.set_function("setTarget",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Node*)>(&cocos2d::NodeGrid::setTarget));
mt.set_function("setGridRect",static_cast<void(cocos2d::NodeGrid::*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::setGridRect));
mt.set_function("getGridRect",static_cast<const cocos2d::Rect&(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGridRect));
mt.set_function("visit",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::NodeGrid::visit));
mt.set_function("new",sol::overload(static_cast<cocos2d::NodeGrid*(*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::create),static_cast<cocos2d::NodeGrid*(*)()>(&cocos2d::NodeGrid::create)));
}
void RegisterLuaCoreParticleBatchNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","ParticleBatchNode");
mt.set_function("insertChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::ParticleSystem*,int)>(&cocos2d::ParticleBatchNode::insertChild));
mt.set_function("removeChildAtIndex",static_cast<void(cocos2d::ParticleBatchNode::*)(int,bool)>(&cocos2d::ParticleBatchNode::removeChildAtIndex));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::ParticleBatchNode::*)(bool)>(&cocos2d::ParticleBatchNode::removeAllChildrenWithCleanup));
mt.set_function("disableParticle",static_cast<void(cocos2d::ParticleBatchNode::*)(int)>(&cocos2d::ParticleBatchNode::disableParticle));
mt.set_function("getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTextureAtlas));
mt.set_function("setTextureAtlas",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::ParticleBatchNode::setTextureAtlas));
mt.set_function("visit",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::visit));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParticleBatchNode::addChild),static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParticleBatchNode::addChild)));
mt.set_function("removeChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParticleBatchNode::removeChild));
mt.set_function("reorderChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::ParticleBatchNode::reorderChild));
mt.set_function("draw",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::draw));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleBatchNode::setTexture));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::ParticleBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleBatchNode::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getBlendFunc));
mt.set_function("createWithTexture",sol::overload([](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0,int arg1){return obj->createWithTexture(arg0,arg1);}));
mt.set_function("new",sol::overload([](cocos2d::ParticleBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ParticleBatchNode* obj,const std::string& arg0,int arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreParticleDataAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleData>("cc","ParticleData");
mt.set_function("init",static_cast<bool(cocos2d::ParticleData::*)(int)>(&cocos2d::ParticleData::init));
mt.set_function("release",static_cast<void(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::release));
mt.set_function("getMaxCount",static_cast<unsigned int(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::getMaxCount));
mt.set_function("copyParticle",static_cast<void(cocos2d::ParticleData::*)(int,int)>(&cocos2d::ParticleData::copyParticle));
mt["posx"] = &cocos2d::ParticleData::posx;
mt["posy"] = &cocos2d::ParticleData::posy;
mt["startPosX"] = &cocos2d::ParticleData::startPosX;
mt["startPosY"] = &cocos2d::ParticleData::startPosY;
mt["colorR"] = &cocos2d::ParticleData::colorR;
mt["colorG"] = &cocos2d::ParticleData::colorG;
mt["colorB"] = &cocos2d::ParticleData::colorB;
mt["colorA"] = &cocos2d::ParticleData::colorA;
mt["deltaColorR"] = &cocos2d::ParticleData::deltaColorR;
mt["deltaColorG"] = &cocos2d::ParticleData::deltaColorG;
mt["deltaColorB"] = &cocos2d::ParticleData::deltaColorB;
mt["deltaColorA"] = &cocos2d::ParticleData::deltaColorA;
mt["size"] = &cocos2d::ParticleData::size;
mt["deltaSize"] = &cocos2d::ParticleData::deltaSize;
mt["rotation"] = &cocos2d::ParticleData::rotation;
mt["deltaRotation"] = &cocos2d::ParticleData::deltaRotation;
mt["timeToLive"] = &cocos2d::ParticleData::timeToLive;
mt["atlasIndex"] = &cocos2d::ParticleData::atlasIndex;
mt["modeA"] = &cocos2d::ParticleData::modeA;
mt["modeB"] = &cocos2d::ParticleData::modeB;
mt["maxCount"] = &cocos2d::ParticleData::maxCount;
}
void RegisterLuaCoreParticleSystemAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSystem");
mt.set_function("addParticles",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::addParticles));
mt.set_function("stopSystem",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stopSystem));
mt.set_function("resetSystem",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::resetSystem));
mt.set_function("isFull",static_cast<bool(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::isFull));
mt.set_function("updateParticleQuads",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateParticleQuads));
mt.set_function("postStep",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::postStep));
mt.set_function("updateWithNoTime",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateWithNoTime));
mt.set_function("isAutoRemoveOnFinish",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isAutoRemoveOnFinish));
mt.set_function("setAutoRemoveOnFinish",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setAutoRemoveOnFinish));
mt.set_function("getGravity",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::getGravity));
mt.set_function("setGravity",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setGravity));
mt.set_function("getSpeed",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeed));
mt.set_function("setSpeed",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeed));
mt.set_function("getSpeedVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeedVar));
mt.set_function("setSpeedVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeedVar));
mt.set_function("getTangentialAccel",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccel));
mt.set_function("setTangentialAccel",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccel));
mt.set_function("getTangentialAccelVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccelVar));
mt.set_function("setTangentialAccelVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccelVar));
mt.set_function("getRadialAccel",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccel));
mt.set_function("setRadialAccel",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccel));
mt.set_function("getRadialAccelVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccelVar));
mt.set_function("setRadialAccelVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccelVar));
mt.set_function("getRotationIsDir",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotationIsDir));
mt.set_function("setRotationIsDir",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setRotationIsDir));
mt.set_function("getStartRadius",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadius));
mt.set_function("setStartRadius",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadius));
mt.set_function("getStartRadiusVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadiusVar));
mt.set_function("setStartRadiusVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadiusVar));
mt.set_function("getEndRadius",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadius));
mt.set_function("setEndRadius",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadius));
mt.set_function("getEndRadiusVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadiusVar));
mt.set_function("setEndRadiusVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadiusVar));
mt.set_function("getRotatePerSecond",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecond));
mt.set_function("setRotatePerSecond",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecond));
mt.set_function("getRotatePerSecondVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecondVar));
mt.set_function("setRotatePerSecondVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecondVar));
mt.set_function("setScale",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScale));
mt.set_function("setRotation",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotation));
mt.set_function("setScaleX",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleX));
mt.set_function("setScaleY",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleY));
mt.set_function("isActive",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isActive));
mt.set_function("isBlendAdditive",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isBlendAdditive));
mt.set_function("setBlendAdditive",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setBlendAdditive));
mt.set_function("getBatchNode",static_cast<cocos2d::ParticleBatchNode*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBatchNode));
mt.set_function("setBatchNode",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleBatchNode*)>(&cocos2d::ParticleSystem::setBatchNode));
mt.set_function("getAtlasIndex",static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAtlasIndex));
mt.set_function("setAtlasIndex",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setAtlasIndex));
mt.set_function("getParticleCount",static_cast<unsigned int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getParticleCount));
mt.set_function("getDuration",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getDuration));
mt.set_function("setDuration",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setDuration));
mt.set_function("getSourcePosition",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSourcePosition));
mt.set_function("setSourcePosition",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setSourcePosition));
mt.set_function("getPosVar",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPosVar));
mt.set_function("setPosVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setPosVar));
mt.set_function("getLife",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLife));
mt.set_function("setLife",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLife));
mt.set_function("getLifeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLifeVar));
mt.set_function("setLifeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLifeVar));
mt.set_function("getAngle",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngle));
mt.set_function("setAngle",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngle));
mt.set_function("getAngleVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngleVar));
mt.set_function("setAngleVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngleVar));
mt.set_function("getEmitterMode",static_cast<cocos2d::ParticleSystem::Mode(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmitterMode));
mt.set_function("setEmitterMode",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::Mode)>(&cocos2d::ParticleSystem::setEmitterMode));
mt.set_function("getStartSize",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSize));
mt.set_function("setStartSize",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSize));
mt.set_function("getStartSizeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSizeVar));
mt.set_function("setStartSizeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSizeVar));
mt.set_function("getEndSize",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSize));
mt.set_function("setEndSize",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSize));
mt.set_function("getEndSizeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSizeVar));
mt.set_function("setEndSizeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSizeVar));
mt.set_function("getStartColor",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColor));
mt.set_function("setStartColor",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColor));
mt.set_function("getStartColorVar",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColorVar));
mt.set_function("setStartColorVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColorVar));
mt.set_function("getEndColor",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColor));
mt.set_function("setEndColor",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColor));
mt.set_function("getEndColorVar",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColorVar));
mt.set_function("setEndColorVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColorVar));
mt.set_function("getStartSpin",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpin));
mt.set_function("setStartSpin",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpin));
mt.set_function("getStartSpinVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpinVar));
mt.set_function("setStartSpinVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpinVar));
mt.set_function("getEndSpin",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpin));
mt.set_function("setEndSpin",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpin));
mt.set_function("getEndSpinVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpinVar));
mt.set_function("setEndSpinVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpinVar));
mt.set_function("getEmissionRate",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmissionRate));
mt.set_function("setEmissionRate",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEmissionRate));
mt.set_function("getTotalParticles",static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTotalParticles));
mt.set_function("setTotalParticles",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setTotalParticles));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isOpacityModifyRGB));
mt.set_function("getPositionType",static_cast<cocos2d::ParticleSystem::PositionType(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPositionType));
mt.set_function("setPositionType",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::PositionType)>(&cocos2d::ParticleSystem::setPositionType));
mt.set_function("onEnter",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::onExit));
mt.set_function("update",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::update));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleSystem::setTexture));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBlendFunc));
mt.set_function("getResourceFile",static_cast<const std::string&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getResourceFile));
mt.set_function("start",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::start));
mt.set_function("stop",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stop));
mt.set_function("setSourcePositionCompatible",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setSourcePositionCompatible));
mt.set_function("isSourcePositionCompatible",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isSourcePositionCompatible));
mt.set_function("new",static_cast<cocos2d::ParticleSystem*(*)(const std::string&)>(&cocos2d::ParticleSystem::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSystem*(*)(int)>(&cocos2d::ParticleSystem::createWithTotalParticles));
mt.set_function("getAllParticleSystems",static_cast<cocos2d::Vector<cocos2d::ParticleSystem *>&(*)()>(&cocos2d::ParticleSystem::getAllParticleSystems));
}
void RegisterLuaCoreParticleSystemQuadAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSystemQuad");
mt.set_function("setDisplayFrame",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::SpriteFrame*)>(&cocos2d::ParticleSystemQuad::setDisplayFrame));
mt.set_function("setTextureWithRect",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::ParticleSystemQuad::setTextureWithRect));
mt.set_function("listenRendererRecreated",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::EventCustom*)>(&cocos2d::ParticleSystemQuad::listenRendererRecreated));
mt.set_function("setTexture",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleSystemQuad::setTexture));
mt.set_function("updateParticleQuads",static_cast<void(cocos2d::ParticleSystemQuad::*)()>(&cocos2d::ParticleSystemQuad::updateParticleQuads));
mt.set_function("draw",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleSystemQuad::draw));
mt.set_function("setBatchNode",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::ParticleBatchNode*)>(&cocos2d::ParticleSystemQuad::setBatchNode));
mt.set_function("setTotalParticles",static_cast<void(cocos2d::ParticleSystemQuad::*)(int)>(&cocos2d::ParticleSystemQuad::setTotalParticles));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ParticleSystemQuad::*)()const>(&cocos2d::ParticleSystemQuad::getDescription));
mt.set_function("new",sol::overload(static_cast<cocos2d::ParticleSystemQuad*(*)(const std::string&)>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)()>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystemQuad::create)));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSystemQuad*(*)(int)>(&cocos2d::ParticleSystemQuad::createWithTotalParticles));
}
void RegisterLuaCoreParticleFireAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFire,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFire");
mt.set_function("new",static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles));
}
void RegisterLuaCoreParticleFireworksAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFireworks,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFireworks");
mt.set_function("new",static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles));
}
void RegisterLuaCoreParticleSunAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSun,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSun");
mt.set_function("new",static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles));
}
void RegisterLuaCoreParticleGalaxyAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleGalaxy,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleGalaxy");
mt.set_function("new",static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create));
mt.set_function("createWithTotalParticles",static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles));
}
