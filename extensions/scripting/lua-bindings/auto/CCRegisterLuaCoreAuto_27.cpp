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
void RegisterLuaCoreTMXTileAnimTaskAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTileAnimTask,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTileAnimTask");
mt.set_function("start",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::start));
mt.set_function("stop",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::stop));
mt.set_function("isRunning",static_cast<bool(cocos2d::TMXTileAnimTask::*)()const>(&cocos2d::TMXTileAnimTask::isRunning));
mt.set_function("new",static_cast<cocos2d::TMXTileAnimTask*(*)(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>(&cocos2d::TMXTileAnimTask::create));
}
void RegisterLuaCoreTMXTileAnimManagerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTileAnimManager,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTileAnimManager");
mt.set_function("startAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll));
mt.set_function("stopAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll));
mt.set_function("getTasks",static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks));
mt.set_function("new",static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create));
}
void RegisterLuaCoreFastTMXTiledMapAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FastTMXTiledMap,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","FastTMXTiledMap");
mt.set_function("getLayer",static_cast<cocos2d::FastTMXLayer*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getLayer));
mt.set_function("getObjectGroup",static_cast<cocos2d::TMXObjectGroup*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getObjectGroup));
mt.set_function("getProperty",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getProperty));
mt.set_function("getPropertiesForGID",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(int)const>(&cocos2d::FastTMXTiledMap::getPropertiesForGID));
mt.set_function("getMapSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapSize));
mt.set_function("setMapSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setMapSize));
mt.set_function("getTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getTileSize));
mt.set_function("setTileSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setTileSize));
mt.set_function("getMapOrientation",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapOrientation));
mt.set_function("setMapOrientation",static_cast<void(cocos2d::FastTMXTiledMap::*)(int)>(&cocos2d::FastTMXTiledMap::setMapOrientation));
mt.set_function("getObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()>(&cocos2d::FastTMXTiledMap::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getObjectGroups)));
mt.set_function("setObjectGroups",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::FastTMXTiledMap::setObjectGroups));
mt.set_function("getProperties",static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getProperties));
mt.set_function("setProperties",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXTiledMap::setProperties));
mt.set_function("getDescription",static_cast<std::string(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getDescription));
mt.set_function("setTileAnimEnabled",static_cast<void(cocos2d::FastTMXTiledMap::*)(bool)>(&cocos2d::FastTMXTiledMap::setTileAnimEnabled));
mt.set_function("getLayerCount",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getLayerCount));
mt.set_function("getResourceFile",static_cast<const std::string&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getResourceFile));
mt.set_function("new",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&)>(&cocos2d::FastTMXTiledMap::create));
mt.set_function("createWithXML",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::createWithXML));
}
void RegisterLuaCoreMotionStreak3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MotionStreak3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","MotionStreak3D");
mt.set_function("tintWithColor",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak3D::tintWithColor));
mt.set_function("reset",static_cast<void(cocos2d::MotionStreak3D::*)()>(&cocos2d::MotionStreak3D::reset));
mt.set_function("getStroke",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getStroke));
mt.set_function("setStroke",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setStroke));
mt.set_function("isStartingPositionInitialized",static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isStartingPositionInitialized));
mt.set_function("setStartingPositionInitialized",static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setStartingPositionInitialized));
mt.set_function("setPosition",sol::overload(static_cast<void(cocos2d::MotionStreak3D::*)(float,float)>(&cocos2d::MotionStreak3D::setPosition),static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak3D::setPosition)));
mt.set_function("setPosition3D",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setPosition3D));
mt.set_function("setRotation3D",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setRotation3D));
mt.set_function("setRotationQuat",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Quaternion&)>(&cocos2d::MotionStreak3D::setRotationQuat));
mt.set_function("getPosition",sol::overload(static_cast<void(cocos2d::MotionStreak3D::*)(float*,float*)const>(&cocos2d::MotionStreak3D::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition)));
mt.set_function("setPositionX",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionX));
mt.set_function("setPositionY",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionY));
mt.set_function("getPositionX",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionX));
mt.set_function("getPositionY",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionY));
mt.set_function("getPosition3D",static_cast<cocos2d::Vec3(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition3D));
mt.set_function("draw",static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::MotionStreak3D::draw));
mt.set_function("update",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::update));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::setTexture));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak3D::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getBlendFunc));
mt.set_function("getOpacity",static_cast<uint8_t(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getOpacity));
mt.set_function("setOpacity",static_cast<void(cocos2d::MotionStreak3D::*)(uint8_t)>(&cocos2d::MotionStreak3D::setOpacity));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isOpacityModifyRGB));
mt.set_function("setSweepAxis",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setSweepAxis));
mt.set_function("getSweepAxis",static_cast<const cocos2d::Vec3&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getSweepAxis));
mt.set_function("new",sol::overload(static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::create),static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::create)));
}
void RegisterLuaCoreBone3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Bone3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Bone3D");
mt.set_function("getInverseBindPose",static_cast<const cocos2d::Mat4&(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::getInverseBindPose));
mt.set_function("updateWorldMat",static_cast<void(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::updateWorldMat));
mt.set_function("getWorldMat",static_cast<const cocos2d::Mat4&(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::getWorldMat));
mt.set_function("getName",static_cast<const std::string&(cocos2d::Bone3D::*)()const>(&cocos2d::Bone3D::getName));
mt.set_function("setAnimationValue",sol::overload([](cocos2d::Bone3D* obj,float* arg0,float* arg1,float* arg2){return obj->setAnimationValue(arg0,arg1,arg2);},[](cocos2d::Bone3D* obj,float* arg0,float* arg1,float* arg2,void* arg3){return obj->setAnimationValue(arg0,arg1,arg2,arg3);},[](cocos2d::Bone3D* obj,float* arg0,float* arg1,float* arg2,void* arg3,float arg4){return obj->setAnimationValue(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("clearBoneBlendState",static_cast<void(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::clearBoneBlendState));
mt.set_function("setInverseBindPose",static_cast<void(cocos2d::Bone3D::*)(const cocos2d::Mat4&)>(&cocos2d::Bone3D::setInverseBindPose));
mt.set_function("setOriPose",static_cast<void(cocos2d::Bone3D::*)(const cocos2d::Mat4&)>(&cocos2d::Bone3D::setOriPose));
mt.set_function("resetPose",static_cast<void(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::resetPose));
mt.set_function("updateJointMatrix",static_cast<void(cocos2d::Bone3D::*)(cocos2d::Vec4*)>(&cocos2d::Bone3D::updateJointMatrix));
mt.set_function("getParentBone",static_cast<cocos2d::Bone3D*(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::getParentBone));
mt.set_function("getChildBoneCount",static_cast<ssize_t(cocos2d::Bone3D::*)()const>(&cocos2d::Bone3D::getChildBoneCount));
mt.set_function("getChildBoneByIndex",static_cast<cocos2d::Bone3D*(cocos2d::Bone3D::*)(int)const>(&cocos2d::Bone3D::getChildBoneByIndex));
mt.set_function("addChildBone",static_cast<void(cocos2d::Bone3D::*)(cocos2d::Bone3D*)>(&cocos2d::Bone3D::addChildBone));
mt.set_function("removeChildBoneByIndex",static_cast<void(cocos2d::Bone3D::*)(int)>(&cocos2d::Bone3D::removeChildBoneByIndex));
mt.set_function("removeChildBone",static_cast<void(cocos2d::Bone3D::*)(cocos2d::Bone3D*)>(&cocos2d::Bone3D::removeChildBone));
mt.set_function("removeAllChildBone",static_cast<void(cocos2d::Bone3D::*)()>(&cocos2d::Bone3D::removeAllChildBone));
mt.set_function("new",static_cast<cocos2d::Bone3D*(*)(const std::string&)>(&cocos2d::Bone3D::create));
}
void RegisterLuaCoreSkeleton3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skeleton3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Skeleton3D");
mt.set_function("getBoneCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getBoneCount));
mt.set_function("getBoneByIndex",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(unsigned int)const>(&cocos2d::Skeleton3D::getBoneByIndex));
mt.set_function("getBoneByName",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(const std::string&)const>(&cocos2d::Skeleton3D::getBoneByName));
mt.set_function("getRootCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getRootCount));
mt.set_function("getRootBone",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(int)const>(&cocos2d::Skeleton3D::getRootBone));
mt.set_function("getBoneIndex",static_cast<int(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)const>(&cocos2d::Skeleton3D::getBoneIndex));
mt.set_function("updateBoneMatrix",static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::updateBoneMatrix));
mt.set_function("new",static_cast<cocos2d::Skeleton3D*(*)(const std::vector<cocos2d::NodeData *>&)>(&cocos2d::Skeleton3D::create));
}
void RegisterLuaCoreSprite3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","Sprite3D");
mt.set_function("setTexture",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture)));
mt.set_function("getMeshByIndex",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex));
mt.set_function("getMeshByName",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName));
mt.set_function("getMeshArrayByName",static_cast<std::vector<cocos2d::Mesh *>(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshArrayByName));
mt.set_function("getMesh",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh));
mt.set_function("getMeshCount",static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount));
mt.set_function("getSkeleton",static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton));
mt.set_function("getAttachNode",static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode));
mt.set_function("removeAttachNode",static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode));
mt.set_function("removeAllAttachNode",static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::Sprite3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite3D::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBlendFunc));
mt.set_function("setProgramState",sol::overload([](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("getAABB",static_cast<const cocos2d::AABB&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getAABB));
mt.set_function("getAABBRecursively",static_cast<cocos2d::AABB(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::getAABBRecursively));
mt.set_function("runAction",static_cast<cocos2d::Action*(cocos2d::Sprite3D::*)(cocos2d::Action*)>(&cocos2d::Sprite3D::runAction));
mt.set_function("setForceDepthWrite",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite));
mt.set_function("isForceDepthWrite",static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBoundingBox));
mt.set_function("setCullFace",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace));
mt.set_function("setCullFaceEnabled",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled));
mt.set_function("setLightMask",static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask));
mt.set_function("getLightMask",static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask));
mt.set_function("draw",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::draw));
mt.set_function("setMaterial",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial)));
mt.set_function("getMaterial",static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial));
mt.set_function("setForce2DQueue",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue));
mt.set_function("getMeshes",static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes));
mt.set_function("visit",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::visit));
mt.set_function("new",sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create)));
mt.set_function("createAsync",sol::overload(static_cast<void(*)(const std::string&,const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync),static_cast<void(*)(const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync)));
}
void RegisterLuaCoreSprite3DCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DCache>("cc","Sprite3DCache");
mt.set_function("getSpriteData",static_cast<cocos2d::Sprite3DCache::Sprite3DData*(cocos2d::Sprite3DCache::*)(const std::string&)const>(&cocos2d::Sprite3DCache::getSpriteData));
mt.set_function("addSprite3DData",static_cast<bool(cocos2d::Sprite3DCache::*)(const std::string&,cocos2d::Sprite3DCache::Sprite3DData*)>(&cocos2d::Sprite3DCache::addSprite3DData));
mt.set_function("removeSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData));
mt.set_function("removeAllSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData));
mt.set_function("getInstance",static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance));
}
void RegisterLuaCoreSprite3DMaterialAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterial,cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("cc","Sprite3DMaterial");
mt.set_function("getMaterialType",static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType));
mt.set_function("setTexture",static_cast<void(cocos2d::Sprite3DMaterial::*)(cocos2d::Texture2D*,cocos2d::NTextureData::Usage)>(&cocos2d::Sprite3DMaterial::setTexture));
mt.set_function("clone",static_cast<cocos2d::Material*(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::clone));
mt.set_function("createBuiltInMaterial",sol::overload(static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial)));
mt.set_function("createWithFilename",static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename));
mt.set_function("createWithProgramState",static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState));
mt.set_function("releaseBuiltInMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial));
mt.set_function("releaseCachedMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial));
}
void RegisterLuaCoreSprite3DMaterialCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterialCache>("cc","Sprite3DMaterialCache");
mt.set_function("addSprite3DMaterial",static_cast<bool(cocos2d::Sprite3DMaterialCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::Sprite3DMaterialCache::addSprite3DMaterial));
mt.set_function("getSprite3DMaterial",static_cast<cocos2d::Texture2D*(cocos2d::Sprite3DMaterialCache::*)(const std::string&)>(&cocos2d::Sprite3DMaterialCache::getSprite3DMaterial));
mt.set_function("removeAllSprite3DMaterial",static_cast<void(cocos2d::Sprite3DMaterialCache::*)()>(&cocos2d::Sprite3DMaterialCache::removeAllSprite3DMaterial));
mt.set_function("removeUnusedSprite3DMaterial",static_cast<void(cocos2d::Sprite3DMaterialCache::*)()>(&cocos2d::Sprite3DMaterialCache::removeUnusedSprite3DMaterial));
mt.set_function("getInstance",static_cast<cocos2d::Sprite3DMaterialCache*(*)()>(&cocos2d::Sprite3DMaterialCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DMaterialCache::destroyInstance));
}
