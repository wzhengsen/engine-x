#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioTextureDataAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::TextureData,cocos2d::Ref,cocos2d::LuaObject>("ccs","TextureData");
mt.set_function("init",static_cast<bool(cocostudio::TextureData::*)()>(&cocostudio::TextureData::init));
mt.set_function("addContourData",static_cast<void(cocostudio::TextureData::*)(cocostudio::ContourData*)>(&cocostudio::TextureData::addContourData));
mt.set_function("getContourData",static_cast<cocostudio::ContourData*(cocostudio::TextureData::*)(int)>(&cocostudio::TextureData::getContourData));
mt.set_function("new",static_cast<cocostudio::TextureData*(*)()>(&cocostudio::TextureData::create));
mt["height"] = &cocostudio::TextureData::height;
mt["width"] = &cocostudio::TextureData::width;
mt["pivotX"] = &cocostudio::TextureData::pivotX;
mt["pivotY"] = &cocostudio::TextureData::pivotY;
mt["name"] = &cocostudio::TextureData::name;
}
void RegisterLuaStudioTweenAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Tween,cocostudio::ProcessBase,cocos2d::Ref,cocos2d::LuaObject>("ccs","Tween");
mt.set_function("init",static_cast<bool(cocostudio::Tween::*)(cocostudio::Bone*)>(&cocostudio::Tween::init));
mt.set_function("play",static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*,int,int,int,int)>(&cocostudio::Tween::play));
mt.set_function("setAnimation",static_cast<void(cocostudio::Tween::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Tween::setAnimation));
mt.set_function("getAnimation",static_cast<cocostudio::ArmatureAnimation*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getAnimation));
mt.set_function("gotoAndPlay",static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPlay));
mt.set_function("gotoAndPause",static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPause));
mt.set_function("setMovementBoneData",static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*)>(&cocostudio::Tween::setMovementBoneData));
mt.set_function("getMovementBoneData",static_cast<const cocostudio::MovementBoneData*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getMovementBoneData));
mt.set_function("new",static_cast<cocostudio::Tween*(*)(cocostudio::Bone*)>(&cocostudio::Tween::create));
}
void RegisterLuaStudioDisplayManagerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::DisplayManager,cocos2d::Ref,cocos2d::LuaObject>("ccs","DisplayManager");
mt.set_function("init",static_cast<bool(cocostudio::DisplayManager::*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::init));
mt.set_function("initDisplayList",static_cast<void(cocostudio::DisplayManager::*)(cocostudio::BoneData*)>(&cocostudio::DisplayManager::initDisplayList));
mt.set_function("addDisplay",sol::overload(static_cast<void(cocostudio::DisplayManager::*)(cocos2d::Node*,int)>(&cocostudio::DisplayManager::addDisplay),static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DisplayData*,int)>(&cocostudio::DisplayManager::addDisplay)));
mt.set_function("removeDisplay",static_cast<void(cocostudio::DisplayManager::*)(int)>(&cocostudio::DisplayManager::removeDisplay));
mt.set_function("getDecorativeDisplayList",static_cast<const cocos2d::Vector<cocostudio::DecorativeDisplay *>&(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDecorativeDisplayList));
mt.set_function("changeDisplayWithIndex",static_cast<void(cocostudio::DisplayManager::*)(int,bool)>(&cocostudio::DisplayManager::changeDisplayWithIndex));
mt.set_function("changeDisplayWithName",static_cast<void(cocostudio::DisplayManager::*)(const std::string&,bool)>(&cocostudio::DisplayManager::changeDisplayWithName));
mt.set_function("getDisplayRenderNode",static_cast<cocos2d::Node*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNode));
mt.set_function("getDisplayRenderNodeType",static_cast<cocostudio::DisplayType(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNodeType));
mt.set_function("getCurrentDisplayIndex",static_cast<int(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDisplayIndex));
mt.set_function("setCurrentDecorativeDisplay",static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DecorativeDisplay*)>(&cocostudio::DisplayManager::setCurrentDecorativeDisplay));
mt.set_function("getCurrentDecorativeDisplay",static_cast<cocostudio::DecorativeDisplay*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDecorativeDisplay));
mt.set_function("getDecorativeDisplayByIndex",static_cast<cocostudio::DecorativeDisplay*(cocostudio::DisplayManager::*)(int)const>(&cocostudio::DisplayManager::getDecorativeDisplayByIndex));
mt.set_function("setVisible",static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setVisible));
mt.set_function("isVisible",static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isVisible));
mt.set_function("getContentSize",static_cast<cocos2d::Size(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getContentSize));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getBoundingBox));
mt.set_function("getAnchorPoint",static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPoint));
mt.set_function("getAnchorPointInPoints",static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPointInPoints));
mt.set_function("containPoint",sol::overload(static_cast<bool(cocostudio::DisplayManager::*)(float,float)>(&cocostudio::DisplayManager::containPoint),static_cast<bool(cocostudio::DisplayManager::*)(cocos2d::Vec2&)>(&cocostudio::DisplayManager::containPoint)));
mt.set_function("setForceChangeDisplay",static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setForceChangeDisplay));
mt.set_function("isForceChangeDisplay",static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isForceChangeDisplay));
mt.set_function("new",static_cast<cocostudio::DisplayManager*(*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::create));
}
void RegisterLuaStudioBoneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Bone,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","Bone");
mt.set_function("init",sol::overload(static_cast<bool(cocostudio::Bone::*)(const std::string&)>(&cocostudio::Bone::init),static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::init)));
mt.set_function("addDisplay",sol::overload(static_cast<void(cocostudio::Bone::*)(cocos2d::Node*,int)>(&cocostudio::Bone::addDisplay),static_cast<void(cocostudio::Bone::*)(cocostudio::DisplayData*,int)>(&cocostudio::Bone::addDisplay)));
mt.set_function("removeDisplay",static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::removeDisplay));
mt.set_function("changeDisplayWithIndex",static_cast<void(cocostudio::Bone::*)(int,bool)>(&cocostudio::Bone::changeDisplayWithIndex));
mt.set_function("changeDisplayWithName",static_cast<void(cocostudio::Bone::*)(const std::string&,bool)>(&cocostudio::Bone::changeDisplayWithName));
mt.set_function("addChildBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::addChildBone));
mt.set_function("setParentBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::setParentBone));
mt.set_function("getParentBone",static_cast<cocostudio::Bone*(cocostudio::Bone::*)()>(&cocostudio::Bone::getParentBone));
mt.set_function("removeFromParent",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::removeFromParent));
mt.set_function("removeChildBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*,bool)>(&cocostudio::Bone::removeChildBone));
mt.set_function("update",static_cast<void(cocostudio::Bone::*)(float)>(&cocostudio::Bone::update));
mt.set_function("updateDisplayedColor",static_cast<void(cocostudio::Bone::*)(const cocos2d::Color3B&)>(&cocostudio::Bone::updateDisplayedColor));
mt.set_function("updateDisplayedOpacity",static_cast<void(cocostudio::Bone::*)(uint8_t)>(&cocostudio::Bone::updateDisplayedOpacity));
mt.set_function("updateColor",static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateColor));
mt.set_function("updateZOrder",static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateZOrder));
mt.set_function("setLocalZOrder",static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::setLocalZOrder));
mt.set_function("getTween",static_cast<cocostudio::Tween*(cocostudio::Bone::*)()>(&cocostudio::Bone::getTween));
mt.set_function("setTransformDirty",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setTransformDirty));
mt.set_function("isTransformDirty",static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isTransformDirty));
mt.set_function("getNodeToArmatureTransform",static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToArmatureTransform));
mt.set_function("getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToWorldTransform));
mt.set_function("getDisplayRenderNode",static_cast<cocos2d::Node*(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNode));
mt.set_function("getDisplayRenderNodeType",static_cast<cocostudio::DisplayType(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNodeType));
mt.set_function("getColliderDetector",static_cast<cocostudio::ColliderDetector*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getColliderDetector));
mt.set_function("setBoneData",static_cast<void(cocostudio::Bone::*)(cocostudio::BoneData*)>(&cocostudio::Bone::setBoneData));
mt.set_function("getBoneData",static_cast<cocostudio::BoneData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getBoneData));
mt.set_function("setArmature",static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setArmature));
mt.set_function("getArmature",static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getArmature));
mt.set_function("setChildArmature",static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setChildArmature));
mt.set_function("getChildArmature",static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getChildArmature));
mt.set_function("getDisplayManager",static_cast<cocostudio::DisplayManager*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getDisplayManager));
mt.set_function("setIgnoreMovementBoneData",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setIgnoreMovementBoneData));
mt.set_function("isIgnoreMovementBoneData",static_cast<bool(cocostudio::Bone::*)()const>(&cocostudio::Bone::isIgnoreMovementBoneData));
mt.set_function("setBlendFunc",static_cast<void(cocostudio::Bone::*)(const cocos2d::BlendFunc&)>(&cocostudio::Bone::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<cocos2d::BlendFunc(cocostudio::Bone::*)()>(&cocostudio::Bone::getBlendFunc));
mt.set_function("setBlendDirty",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setBlendDirty));
mt.set_function("isBlendDirty",static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isBlendDirty));
mt.set_function("getTweenData",static_cast<cocostudio::FrameData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getTweenData));
mt.set_function("getWorldInfo",static_cast<cocostudio::BaseData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getWorldInfo));
mt.set_function("new",sol::overload(static_cast<cocostudio::Bone*(*)(const std::string&)>(&cocostudio::Bone::create),static_cast<cocostudio::Bone*(*)()>(&cocostudio::Bone::create)));
}
void RegisterLuaStudioBatchNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","BatchNode");
mt.set_function("init",static_cast<bool(cocostudio::BatchNode::*)()>(&cocostudio::BatchNode::init));
mt.set_function("addChild",sol::overload(static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::BatchNode::addChild),static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,int)>(&cocostudio::BatchNode::addChild)));
mt.set_function("removeChild",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,bool)>(&cocostudio::BatchNode::removeChild));
mt.set_function("visit",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::BatchNode::visit));
mt.set_function("draw",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::BatchNode::draw));
mt.set_function("new",static_cast<cocostudio::BatchNode*(*)()>(&cocostudio::BatchNode::create));
}
void RegisterLuaStudioArmatureAnimationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureAnimation,cocostudio::ProcessBase,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureAnimation");
mt.set_function("init",static_cast<bool(cocostudio::ArmatureAnimation::*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::init));
mt.set_function("setSpeedScale",static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::setSpeedScale));
mt.set_function("getSpeedScale",static_cast<float(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getSpeedScale));
mt.set_function("play",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::string& arg0){return obj->play(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1){return obj->play(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1,int arg2){return obj->play(arg0,arg1,arg2);}));
mt.set_function("playWithIndex",sol::overload([](cocostudio::ArmatureAnimation* obj,int arg0){return obj->playWithIndex(arg0);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1){return obj->playWithIndex(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1,int arg2){return obj->playWithIndex(arg0,arg1,arg2);}));
mt.set_function("playWithNames",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0){return obj->playWithNames(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0,int arg1){return obj->playWithNames(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0,int arg1,bool arg2){return obj->playWithNames(arg0,arg1,arg2);}));
mt.set_function("playWithIndexes",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0){return obj->playWithIndexes(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0,int arg1){return obj->playWithIndexes(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0,int arg1,bool arg2){return obj->playWithIndexes(arg0,arg1,arg2);}));
mt.set_function("gotoAndPlay",static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPlay));
mt.set_function("gotoAndPause",static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPause));
mt.set_function("pause",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::pause));
mt.set_function("resume",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::resume));
mt.set_function("stop",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::stop));
mt.set_function("getMovementCount",static_cast<ssize_t(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getMovementCount));
mt.set_function("update",static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::update));
mt.set_function("getCurrentMovementID",static_cast<std::string(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getCurrentMovementID));
mt.set_function("setMovementEventCallFunc",static_cast<void(cocostudio::ArmatureAnimation::*)(std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const std::string&)>)>(&cocostudio::ArmatureAnimation::setMovementEventCallFunc));
mt.set_function("setFrameEventCallFunc",static_cast<void(cocostudio::ArmatureAnimation::*)(std::function<void (cocostudio::Bone *, const std::string&, int, int)>)>(&cocostudio::ArmatureAnimation::setFrameEventCallFunc));
mt.set_function("setAnimationData",static_cast<void(cocostudio::ArmatureAnimation::*)(cocostudio::AnimationData*)>(&cocostudio::ArmatureAnimation::setAnimationData));
mt.set_function("getAnimationData",static_cast<cocostudio::AnimationData*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getAnimationData));
mt.set_function("getUserObject",sol::overload(static_cast<const cocos2d::Ref*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getUserObject),static_cast<cocos2d::Ref*(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::getUserObject)));
mt.set_function("setUserObject",static_cast<void(cocostudio::ArmatureAnimation::*)(cocos2d::Ref*)>(&cocostudio::ArmatureAnimation::setUserObject));
mt.set_function("new",static_cast<cocostudio::ArmatureAnimation*(*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::create));
}
void RegisterLuaStudioArmatureDataManagerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureDataManager,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureDataManager");
mt.set_function("init",static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::init));
mt.set_function("addArmatureData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1){return obj->addArmatureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1,const std::string& arg2){return obj->addArmatureData(arg0,arg1,arg2);}));
mt.set_function("getArmatureData",static_cast<cocostudio::ArmatureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getArmatureData));
mt.set_function("removeArmatureData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureData));
mt.set_function("addAnimationData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1){return obj->addAnimationData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1,const std::string& arg2){return obj->addAnimationData(arg0,arg1,arg2);}));
mt.set_function("getAnimationData",static_cast<cocostudio::AnimationData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getAnimationData));
mt.set_function("removeAnimationData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeAnimationData));
mt.set_function("addTextureData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1){return obj->addTextureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1,const std::string& arg2){return obj->addTextureData(arg0,arg1,arg2);}));
mt.set_function("getTextureData",static_cast<cocostudio::TextureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getTextureData));
mt.set_function("removeTextureData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeTextureData));
mt.set_function("addArmatureFileInfo",sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo)));
mt.set_function("addArmatureFileInfoAsync",sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync)));
mt.set_function("addSpriteFrameFromFile",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1){return obj->addSpriteFrameFromFile(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->addSpriteFrameFromFile(arg0,arg1,arg2);}));
mt.set_function("removeArmatureFileInfo",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureFileInfo));
mt.set_function("isAutoLoadSpriteFile",static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::isAutoLoadSpriteFile));
mt.set_function("getArmatureDatas",static_cast<const cocos2d::Map<std::string, cocostudio::ArmatureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getArmatureDatas));
mt.set_function("getAnimationDatas",static_cast<const cocos2d::Map<std::string, cocostudio::AnimationData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getAnimationDatas));
mt.set_function("getTextureDatas",static_cast<const cocos2d::Map<std::string, cocostudio::TextureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getTextureDatas));
mt.set_function("addRelativeData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addRelativeData));
mt.set_function("getRelativeData",static_cast<cocostudio::RelativeData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getRelativeData));
mt.set_function("getInstance",static_cast<cocostudio::ArmatureDataManager*(*)()>(&cocostudio::ArmatureDataManager::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocostudio::ArmatureDataManager::destroyInstance));
}
void RegisterLuaStudioArmatureAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Armature,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","Armature");
mt.set_function("init",sol::overload(static_cast<bool(cocostudio::Armature::*)(const std::string&)>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)()>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::init)));
mt.set_function("addBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::addBone));
mt.set_function("getBone",static_cast<cocostudio::Bone*(cocostudio::Armature::*)(const std::string&)const>(&cocostudio::Armature::getBone));
mt.set_function("changeBoneParent",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::changeBoneParent));
mt.set_function("removeBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,bool)>(&cocostudio::Armature::removeBone));
mt.set_function("getBoneDic",static_cast<const cocos2d::Map<std::string, cocostudio::Bone *>&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoneDic));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoundingBox));
mt.set_function("getBoneAtPoint",static_cast<cocostudio::Bone*(cocostudio::Armature::*)(float,float)const>(&cocostudio::Armature::getBoneAtPoint));
mt.set_function("visit",static_cast<void(cocostudio::Armature::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Armature::visit));
mt.set_function("draw",static_cast<void(cocostudio::Armature::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Armature::draw));
mt.set_function("update",static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::update));
mt.set_function("onEnter",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::onEnter));
mt.set_function("onExit",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::onExit));
mt.set_function("getNodeToParentTransform",static_cast<const cocos2d::Mat4&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getNodeToParentTransform));
mt.set_function("setBlendFunc",static_cast<void(cocostudio::Armature::*)(const cocos2d::BlendFunc&)>(&cocostudio::Armature::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBlendFunc));
mt.set_function("updateOffsetPoint",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::updateOffsetPoint));
mt.set_function("setAnchorPoint",static_cast<void(cocostudio::Armature::*)(const cocos2d::Vec2&)>(&cocostudio::Armature::setAnchorPoint));
mt.set_function("getAnchorPointInPoints",static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnchorPointInPoints));
mt.set_function("getOffsetPoints",static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getOffsetPoints));
mt.set_function("setAnimation",static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Armature::setAnimation));
mt.set_function("getAnimation",static_cast<cocostudio::ArmatureAnimation*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnimation));
mt.set_function("getArmatureTransformDirty",static_cast<bool(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureTransformDirty));
mt.set_function("setArmatureData",static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureData*)>(&cocostudio::Armature::setArmatureData));
mt.set_function("getArmatureData",static_cast<cocostudio::ArmatureData*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureData));
mt.set_function("setParentBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*)>(&cocostudio::Armature::setParentBone));
mt.set_function("getParentBone",static_cast<cocostudio::Bone*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getParentBone));
mt.set_function("setVersion",static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::setVersion));
mt.set_function("getVersion",static_cast<float(cocostudio::Armature::*)()const>(&cocostudio::Armature::getVersion));
mt.set_function("setBatchNode",static_cast<void(cocostudio::Armature::*)(cocostudio::BatchNode*)>(&cocostudio::Armature::setBatchNode));
mt.set_function("getBatchNode",static_cast<cocostudio::BatchNode*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBatchNode));
mt.set_function("new",sol::overload(static_cast<cocostudio::Armature*(*)(const std::string&)>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)()>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::create)));
}
void RegisterLuaStudioSkinAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Skin,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("ccs","Skin");
mt.set_function("initWithSpriteFrameName",static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithSpriteFrameName));
mt.set_function("initWithFile",static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithFile));
mt.set_function("updateArmatureTransform",static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateArmatureTransform));
mt.set_function("updateTransform",static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateTransform));
mt.set_function("getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransform));
mt.set_function("getNodeToWorldTransformAR",static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransformAR));
mt.set_function("draw",static_cast<void(cocostudio::Skin::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Skin::draw));
mt.set_function("setSkinData",static_cast<void(cocostudio::Skin::*)(const cocostudio::BaseData&)>(&cocostudio::Skin::setSkinData));
mt.set_function("getSkinData",static_cast<const cocostudio::BaseData&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getSkinData));
mt.set_function("setBone",static_cast<void(cocostudio::Skin::*)(cocostudio::Bone*)>(&cocostudio::Skin::setBone));
mt.set_function("getBone",static_cast<cocostudio::Bone*(cocostudio::Skin::*)()const>(&cocostudio::Skin::getBone));
mt.set_function("getDisplayName",static_cast<const std::string&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getDisplayName));
mt.set_function("new",sol::overload(static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::create),static_cast<cocostudio::Skin*(*)()>(&cocostudio::Skin::create)));
mt.set_function("createWithSpriteFrameName",static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::createWithSpriteFrameName));
}
void RegisterLuaStudioComAttributeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComAttribute,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComAttribute");
mt.set_function("init",static_cast<bool(cocostudio::ComAttribute::*)()>(&cocostudio::ComAttribute::init));
mt.set_function("serialize",static_cast<bool(cocostudio::ComAttribute::*)(void*)>(&cocostudio::ComAttribute::serialize));
mt.set_function("setInt",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,int)>(&cocostudio::ComAttribute::setInt));
mt.set_function("setFloat",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,float)>(&cocostudio::ComAttribute::setFloat));
mt.set_function("setBool",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,bool)>(&cocostudio::ComAttribute::setBool));
mt.set_function("setString",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,const std::string&)>(&cocostudio::ComAttribute::setString));
mt.set_function("getInt",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getInt(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,int arg1){return obj->getInt(arg0,arg1);}));
mt.set_function("getFloat",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getFloat(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,float arg1){return obj->getFloat(arg0,arg1);}));
mt.set_function("getBool",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getBool(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,bool arg1){return obj->getBool(arg0,arg1);}));
mt.set_function("getString",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getString(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,const std::string& arg1){return obj->getString(arg0,arg1);}));
mt.set_function("parse",static_cast<bool(cocostudio::ComAttribute::*)(const std::string&)>(&cocostudio::ComAttribute::parse));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAttribute::createInstance));
mt.set_function("new",static_cast<cocostudio::ComAttribute*(*)()>(&cocostudio::ComAttribute::create));
}
