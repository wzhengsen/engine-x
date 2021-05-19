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
void RegisterLuaCoreNodeGridAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::NodeGrid>("cc","NodeGrid",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::NodeGrid*(*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::create),static_cast<cocos2d::NodeGrid*(*)()>(&cocos2d::NodeGrid::create)));
mt.set_function("GetGrid",sol::overload(static_cast<const cocos2d::GridBase*(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGrid),static_cast<cocos2d::GridBase*(cocos2d::NodeGrid::*)()>(&cocos2d::NodeGrid::getGrid)));
mt.set_function("SetGrid",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::GridBase*)>(&cocos2d::NodeGrid::setGrid));
mt.set_function("SetTarget",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Node*)>(&cocos2d::NodeGrid::setTarget));
mt.set_function("SetGridRect",static_cast<void(cocos2d::NodeGrid::*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::setGridRect));
mt.set_function("GetGridRect",static_cast<const cocos2d::Rect&(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGridRect));
mt.set_function("Visit",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::NodeGrid::visit));
}
void RegisterLuaCoreParticleBatchNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleBatchNode>("cc","ParticleBatchNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function("CreateWithTexture",sol::overload([](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0,int arg1){return obj->createWithTexture(arg0,arg1);}));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ParticleBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ParticleBatchNode* obj,const std::string& arg0,int arg1){return obj->create(arg0,arg1);}));
mt.set_function("InsertChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::ParticleSystem*,int)>(&cocos2d::ParticleBatchNode::insertChild));
mt.set_function("RemoveChildAtIndex",static_cast<void(cocos2d::ParticleBatchNode::*)(int,bool)>(&cocos2d::ParticleBatchNode::removeChildAtIndex));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::ParticleBatchNode::*)(bool)>(&cocos2d::ParticleBatchNode::removeAllChildrenWithCleanup));
mt.set_function("DisableParticle",static_cast<void(cocos2d::ParticleBatchNode::*)(int)>(&cocos2d::ParticleBatchNode::disableParticle));
mt.set_function("GetTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTextureAtlas));
mt.set_function("SetTextureAtlas",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::ParticleBatchNode::setTextureAtlas));
mt.set_function("Visit",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::visit));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParticleBatchNode::addChild),static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParticleBatchNode::addChild)));
mt.set_function("RemoveChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParticleBatchNode::removeChild));
mt.set_function("ReorderChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::ParticleBatchNode::reorderChild));
mt.set_function("Draw",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::draw));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTexture));
mt.set_function("SetTexture",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleBatchNode::setTexture));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::ParticleBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleBatchNode::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getBlendFunc));
}
void RegisterLuaCoreParticleDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleData>("cc","ParticleData",false);
mt.set_function("Init",static_cast<bool(cocos2d::ParticleData::*)(int)>(&cocos2d::ParticleData::init));
mt.set_function("Release",static_cast<void(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::release));
mt.set_function("GetMaxCount",static_cast<unsigned int(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::getMaxCount));
mt.set_function("CopyParticle",static_cast<void(cocos2d::ParticleData::*)(int,int)>(&cocos2d::ParticleData::copyParticle));
mt[sol::call_constructor]=sol::constructors<cocos2d::ParticleData()>();
mt["Posx"]=&cocos2d::ParticleData::posx;
mt["Posy"]=&cocos2d::ParticleData::posy;
mt["StartPosX"]=&cocos2d::ParticleData::startPosX;
mt["StartPosY"]=&cocos2d::ParticleData::startPosY;
mt["ColorR"]=&cocos2d::ParticleData::colorR;
mt["ColorG"]=&cocos2d::ParticleData::colorG;
mt["ColorB"]=&cocos2d::ParticleData::colorB;
mt["ColorA"]=&cocos2d::ParticleData::colorA;
mt["DeltaColorR"]=&cocos2d::ParticleData::deltaColorR;
mt["DeltaColorG"]=&cocos2d::ParticleData::deltaColorG;
mt["DeltaColorB"]=&cocos2d::ParticleData::deltaColorB;
mt["DeltaColorA"]=&cocos2d::ParticleData::deltaColorA;
mt["Size"]=&cocos2d::ParticleData::size;
mt["DeltaSize"]=&cocos2d::ParticleData::deltaSize;
mt["Rotation"]=&cocos2d::ParticleData::rotation;
mt["DeltaRotation"]=&cocos2d::ParticleData::deltaRotation;
mt["TimeToLive"]=&cocos2d::ParticleData::timeToLive;
mt["AtlasIndex"]=&cocos2d::ParticleData::atlasIndex;
mt["ModeA"]=&cocos2d::ParticleData::modeA;
mt["ModeB"]=&cocos2d::ParticleData::modeB;
mt["MaxCount"]=&cocos2d::ParticleData::maxCount;
}
void RegisterLuaCoreParticleSystemModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["ParticleSystem"];
pTable.new_enum<cocos2d::ParticleSystem::Mode>("Mode",{
{"GRAVITY",cocos2d::ParticleSystem::Mode::GRAVITY}
,{"RADIUS",cocos2d::ParticleSystem::Mode::RADIUS}
});}
void RegisterLuaCoreParticleSystemPositionTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["ParticleSystem"];
pTable.new_enum<cocos2d::ParticleSystem::PositionType>("PositionType",{
{"FREE",cocos2d::ParticleSystem::PositionType::FREE}
,{"RELATIVE",cocos2d::ParticleSystem::PositionType::RELATIVE}
,{"GROUPED",cocos2d::ParticleSystem::PositionType::GROUPED}
});}
void RegisterLuaCoreParticleSystemAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSystem>("cc","ParticleSystem",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleSystem*(*)(const std::string&)>(&cocos2d::ParticleSystem::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleSystem*(*)(int)>(&cocos2d::ParticleSystem::createWithTotalParticles));
mt.set_function("GetAllParticleSystems",static_cast<cocos2d::Vector<cocos2d::ParticleSystem *>&(*)()>(&cocos2d::ParticleSystem::getAllParticleSystems));
mt.set_function("AddParticles",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::addParticles));
mt.set_function("StopSystem",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stopSystem));
mt.set_function("ResetSystem",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::resetSystem));
mt.set_function("IsFull",static_cast<bool(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::isFull));
mt.set_function("UpdateParticleQuads",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateParticleQuads));
mt.set_function("PostStep",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::postStep));
mt.set_function("UpdateWithNoTime",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateWithNoTime));
mt.set_function("IsAutoRemoveOnFinish",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isAutoRemoveOnFinish));
mt.set_function("SetAutoRemoveOnFinish",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setAutoRemoveOnFinish));
mt.set_function("GetGravity",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::getGravity));
mt.set_function("SetGravity",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setGravity));
mt.set_function("GetSpeed",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeed));
mt.set_function("SetSpeed",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeed));
mt.set_function("GetSpeedVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeedVar));
mt.set_function("SetSpeedVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeedVar));
mt.set_function("GetTangentialAccel",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccel));
mt.set_function("SetTangentialAccel",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccel));
mt.set_function("GetTangentialAccelVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccelVar));
mt.set_function("SetTangentialAccelVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccelVar));
mt.set_function("GetRadialAccel",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccel));
mt.set_function("SetRadialAccel",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccel));
mt.set_function("GetRadialAccelVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccelVar));
mt.set_function("SetRadialAccelVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccelVar));
mt.set_function("GetRotationIsDir",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotationIsDir));
mt.set_function("SetRotationIsDir",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setRotationIsDir));
mt.set_function("GetStartRadius",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadius));
mt.set_function("SetStartRadius",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadius));
mt.set_function("GetStartRadiusVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadiusVar));
mt.set_function("SetStartRadiusVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadiusVar));
mt.set_function("GetEndRadius",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadius));
mt.set_function("SetEndRadius",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadius));
mt.set_function("GetEndRadiusVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadiusVar));
mt.set_function("SetEndRadiusVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadiusVar));
mt.set_function("GetRotatePerSecond",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecond));
mt.set_function("SetRotatePerSecond",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecond));
mt.set_function("GetRotatePerSecondVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecondVar));
mt.set_function("SetRotatePerSecondVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecondVar));
mt.set_function("SetScale",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScale));
mt.set_function("SetRotation",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotation));
mt.set_function("SetScaleX",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleX));
mt.set_function("SetScaleY",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleY));
mt.set_function("IsActive",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isActive));
mt.set_function("IsBlendAdditive",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isBlendAdditive));
mt.set_function("SetBlendAdditive",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setBlendAdditive));
mt.set_function("GetBatchNode",static_cast<cocos2d::ParticleBatchNode*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBatchNode));
mt.set_function("SetBatchNode",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleBatchNode*)>(&cocos2d::ParticleSystem::setBatchNode));
mt.set_function("GetAtlasIndex",static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAtlasIndex));
mt.set_function("SetAtlasIndex",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setAtlasIndex));
mt.set_function("GetParticleCount",static_cast<unsigned int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getParticleCount));
mt.set_function("GetDuration",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getDuration));
mt.set_function("SetDuration",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setDuration));
mt.set_function("GetSourcePosition",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSourcePosition));
mt.set_function("SetSourcePosition",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setSourcePosition));
mt.set_function("GetPosVar",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPosVar));
mt.set_function("SetPosVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setPosVar));
mt.set_function("GetLife",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLife));
mt.set_function("SetLife",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLife));
mt.set_function("GetLifeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLifeVar));
mt.set_function("SetLifeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLifeVar));
mt.set_function("GetAngle",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngle));
mt.set_function("SetAngle",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngle));
mt.set_function("GetAngleVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngleVar));
mt.set_function("SetAngleVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngleVar));
mt.set_function("GetEmitterMode",static_cast<cocos2d::ParticleSystem::Mode(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmitterMode));
mt.set_function("SetEmitterMode",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::Mode)>(&cocos2d::ParticleSystem::setEmitterMode));
mt.set_function("GetStartSize",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSize));
mt.set_function("SetStartSize",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSize));
mt.set_function("GetStartSizeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSizeVar));
mt.set_function("SetStartSizeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSizeVar));
mt.set_function("GetEndSize",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSize));
mt.set_function("SetEndSize",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSize));
mt.set_function("GetEndSizeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSizeVar));
mt.set_function("SetEndSizeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSizeVar));
mt.set_function("GetStartColor",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColor));
mt.set_function("SetStartColor",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColor));
mt.set_function("GetStartColorVar",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColorVar));
mt.set_function("SetStartColorVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColorVar));
mt.set_function("GetEndColor",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColor));
mt.set_function("SetEndColor",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColor));
mt.set_function("GetEndColorVar",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColorVar));
mt.set_function("SetEndColorVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColorVar));
mt.set_function("GetStartSpin",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpin));
mt.set_function("SetStartSpin",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpin));
mt.set_function("GetStartSpinVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpinVar));
mt.set_function("SetStartSpinVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpinVar));
mt.set_function("GetEndSpin",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpin));
mt.set_function("SetEndSpin",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpin));
mt.set_function("GetEndSpinVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpinVar));
mt.set_function("SetEndSpinVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpinVar));
mt.set_function("GetEmissionRate",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmissionRate));
mt.set_function("SetEmissionRate",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEmissionRate));
mt.set_function("GetTotalParticles",static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTotalParticles));
mt.set_function("SetTotalParticles",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setTotalParticles));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setOpacityModifyRGB));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isOpacityModifyRGB));
mt.set_function("GetPositionType",static_cast<cocos2d::ParticleSystem::PositionType(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPositionType));
mt.set_function("SetPositionType",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::PositionType)>(&cocos2d::ParticleSystem::setPositionType));
mt.set_function("OnEnter",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::onExit));
mt.set_function("Update",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::update));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTexture));
mt.set_function("SetTexture",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleSystem::setTexture));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBlendFunc));
mt.set_function("GetResourceFile",static_cast<const std::string&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getResourceFile));
mt.set_function("Start",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::start));
mt.set_function("Stop",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stop));
mt.set_function("SetSourcePositionCompatible",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setSourcePositionCompatible));
mt.set_function("IsSourcePositionCompatible",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isSourcePositionCompatible));
RegisterLuaCoreParticleSystemModeAuto(lua);
RegisterLuaCoreParticleSystemPositionTypeAuto(lua);
}
void RegisterLuaCoreParticleSystemQuadAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSystemQuad>("cc","ParticleSystemQuad",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ParticleSystemQuad*(*)(const std::string&)>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)()>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystemQuad::create)));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleSystemQuad*(*)(int)>(&cocos2d::ParticleSystemQuad::createWithTotalParticles));
mt.set_function("SetDisplayFrame",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::SpriteFrame*)>(&cocos2d::ParticleSystemQuad::setDisplayFrame));
mt.set_function("SetTextureWithRect",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::ParticleSystemQuad::setTextureWithRect));
mt.set_function("ListenRendererRecreated",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::EventCustom*)>(&cocos2d::ParticleSystemQuad::listenRendererRecreated));
mt.set_function("SetTexture",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleSystemQuad::setTexture));
mt.set_function("UpdateParticleQuads",static_cast<void(cocos2d::ParticleSystemQuad::*)()>(&cocos2d::ParticleSystemQuad::updateParticleQuads));
mt.set_function("Draw",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleSystemQuad::draw));
mt.set_function("SetBatchNode",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::ParticleBatchNode*)>(&cocos2d::ParticleSystemQuad::setBatchNode));
mt.set_function("SetTotalParticles",static_cast<void(cocos2d::ParticleSystemQuad::*)(int)>(&cocos2d::ParticleSystemQuad::setTotalParticles));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ParticleSystemQuad::*)()const>(&cocos2d::ParticleSystemQuad::getDescription));
}
void RegisterLuaCoreParticleFireAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFire>("cc","ParticleFire",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles));
}
void RegisterLuaCoreParticleFireworksAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleFireworks>("cc","ParticleFireworks",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create));
mt.set_function("CreateWithTotalParticles",static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles));
}
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
