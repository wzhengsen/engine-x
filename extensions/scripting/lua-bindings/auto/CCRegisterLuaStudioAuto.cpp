#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
static void RegisterLuaStudioActionFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionFrame");
mt["setFrameIndex"]=static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameIndex);
mt["getFrameIndex"]=static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameIndex);
mt["setFrameTime"]=static_cast<void(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::setFrameTime);
mt["getFrameTime"]=static_cast<float(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameTime);
mt["setFrameType"]=static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameType);
mt["getFrameType"]=static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameType);
mt["setEasingType"]=static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setEasingType);
mt["getEasingType"]=static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getEasingType);
mt["getAction"]=sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::getAction));
mt["setEasingParameter"]=static_cast<void(cocostudio::ActionFrame::*)(std::vector<float>&)>(&cocostudio::ActionFrame::setEasingParameter);
}
static void RegisterLuaStudioActionMoveFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionMoveFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionMoveFrame");
mt["setPosition"]=static_cast<void(cocostudio::ActionMoveFrame::*)(cocos2d::Vec2)>(&cocostudio::ActionMoveFrame::setPosition);
mt["getPosition"]=static_cast<cocos2d::Vec2(cocostudio::ActionMoveFrame::*)()>(&cocostudio::ActionMoveFrame::getPosition);
mt["getAction"]=static_cast<cocos2d::ActionInterval*(cocostudio::ActionMoveFrame::*)(float)>(&cocostudio::ActionMoveFrame::getAction);
}
static void RegisterLuaStudioActionScaleFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionScaleFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionScaleFrame");
mt["setScaleX"]=static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleX);
mt["getScaleX"]=static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleX);
mt["setScaleY"]=static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleY);
mt["getScaleY"]=static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleY);
mt["getAction"]=static_cast<cocos2d::ActionInterval*(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::getAction);
}
static void RegisterLuaStudioActionRotationFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionRotationFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionRotationFrame");
mt["setRotation"]=static_cast<void(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::setRotation);
mt["getRotation"]=static_cast<float(cocostudio::ActionRotationFrame::*)()>(&cocostudio::ActionRotationFrame::getRotation);
mt["getAction"]=sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionRotationFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::getAction));
}
static void RegisterLuaStudioActionFadeFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionFadeFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionFadeFrame");
mt["setOpacity"]=static_cast<void(cocostudio::ActionFadeFrame::*)(int)>(&cocostudio::ActionFadeFrame::setOpacity);
mt["getOpacity"]=static_cast<int(cocostudio::ActionFadeFrame::*)()>(&cocostudio::ActionFadeFrame::getOpacity);
mt["getAction"]=static_cast<cocos2d::ActionInterval*(cocostudio::ActionFadeFrame::*)(float)>(&cocostudio::ActionFadeFrame::getAction);
}
static void RegisterLuaStudioActionTintFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionTintFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionTintFrame");
mt["setColor"]=static_cast<void(cocostudio::ActionTintFrame::*)(cocos2d::Color3B)>(&cocostudio::ActionTintFrame::setColor);
mt["getColor"]=static_cast<cocos2d::Color3B(cocostudio::ActionTintFrame::*)()>(&cocostudio::ActionTintFrame::getColor);
mt["getAction"]=static_cast<cocos2d::ActionInterval*(cocostudio::ActionTintFrame::*)(float)>(&cocostudio::ActionTintFrame::getAction);
}
static void RegisterLuaStudioActionObject(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionObject,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionObject");
mt["setName"]=static_cast<void(cocostudio::ActionObject::*)(const char*)>(&cocostudio::ActionObject::setName);
mt["getName"]=static_cast<const char*(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getName);
mt["setLoop"]=static_cast<void(cocostudio::ActionObject::*)(bool)>(&cocostudio::ActionObject::setLoop);
mt["getLoop"]=static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getLoop);
mt["setUnitTime"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setUnitTime);
mt["getUnitTime"]=static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getUnitTime);
mt["setCurrentTime"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setCurrentTime);
mt["getCurrentTime"]=static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getCurrentTime);
mt["getTotalTime"]=static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getTotalTime);
mt["isPlaying"]=static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::isPlaying);
mt["play"]=sol::overload(static_cast<void(cocostudio::ActionObject::*)(cocos2d::CallFunc*)>(&cocostudio::ActionObject::play),static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::play));
mt["pause"]=static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::pause);
mt["stop"]=static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::stop);
mt["addActionNode"]=static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::addActionNode);
mt["removeActionNode"]=static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::removeActionNode);
mt["updateToFrameByTime"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::updateToFrameByTime);
mt["simulationActionUpdate"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::simulationActionUpdate);
}
static void RegisterLuaStudioActionManagerEx(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ActionManagerEx,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionManagerEx");
mt["getActionByName"]=static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::getActionByName);
mt["playActionByName"]=sol::overload(static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*,cocos2d::CallFunc*)>(&cocostudio::ActionManagerEx::playActionByName),static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::playActionByName));
mt["stopActionByName"]=static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::stopActionByName);
mt["releaseActions"]=static_cast<void(cocostudio::ActionManagerEx::*)()>(&cocostudio::ActionManagerEx::releaseActions);
mt["getStudioVersionNumber"]=static_cast<int(cocostudio::ActionManagerEx::*)()const>(&cocostudio::ActionManagerEx::getStudioVersionNumber);
mt["getInstance"]=static_cast<cocostudio::ActionManagerEx*(*)()>(&cocostudio::ActionManagerEx::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocostudio::ActionManagerEx::destroyInstance);
}
static void RegisterLuaStudioBaseData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("ccs","BaseData");
mt["setColor"]=static_cast<void(cocostudio::BaseData::*)(const cocos2d::Color4B&)>(&cocostudio::BaseData::setColor);
mt["getColor"]=static_cast<cocos2d::Color4B(cocostudio::BaseData::*)()>(&cocostudio::BaseData::getColor);
mt["new"]=static_cast<cocostudio::BaseData*(*)()>(&cocostudio::BaseData::create);
}
static void RegisterLuaStudioDisplayData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","DisplayData");
mt["copy"]=static_cast<void(cocostudio::DisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::DisplayData::copy);
mt["new"]=static_cast<cocostudio::DisplayData*(*)()>(&cocostudio::DisplayData::create);
mt["changeDisplayToTexture"]=static_cast<std::string(*)(const std::string&)>(&cocostudio::DisplayData::changeDisplayToTexture);
}
static void RegisterLuaStudioSpriteDisplayData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::SpriteDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","SpriteDisplayData");
mt["copy"]=static_cast<void(cocostudio::SpriteDisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::SpriteDisplayData::copy);
mt["new"]=static_cast<cocostudio::SpriteDisplayData*(*)()>(&cocostudio::SpriteDisplayData::create);
}
static void RegisterLuaStudioArmatureDisplayData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureDisplayData");
mt["new"]=static_cast<cocostudio::ArmatureDisplayData*(*)()>(&cocostudio::ArmatureDisplayData::create);
}
static void RegisterLuaStudioParticleDisplayData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ParticleDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ParticleDisplayData");
mt["new"]=static_cast<cocostudio::ParticleDisplayData*(*)()>(&cocostudio::ParticleDisplayData::create);
}
static void RegisterLuaStudioBoneData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BoneData,cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("ccs","BoneData");
mt["init"]=static_cast<bool(cocostudio::BoneData::*)()>(&cocostudio::BoneData::init);
mt["addDisplayData"]=static_cast<void(cocostudio::BoneData::*)(cocostudio::DisplayData*)>(&cocostudio::BoneData::addDisplayData);
mt["getDisplayData"]=static_cast<cocostudio::DisplayData*(cocostudio::BoneData::*)(int)>(&cocostudio::BoneData::getDisplayData);
mt["new"]=static_cast<cocostudio::BoneData*(*)()>(&cocostudio::BoneData::create);
}
static void RegisterLuaStudioArmatureData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureData");
mt["init"]=static_cast<bool(cocostudio::ArmatureData::*)()>(&cocostudio::ArmatureData::init);
mt["addBoneData"]=static_cast<void(cocostudio::ArmatureData::*)(cocostudio::BoneData*)>(&cocostudio::ArmatureData::addBoneData);
mt["getBoneData"]=static_cast<cocostudio::BoneData*(cocostudio::ArmatureData::*)(const std::string&)>(&cocostudio::ArmatureData::getBoneData);
mt["new"]=static_cast<cocostudio::ArmatureData*(*)()>(&cocostudio::ArmatureData::create);
}
static void RegisterLuaStudioFrameData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::FrameData,cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("ccs","FrameData");
mt["copy"]=static_cast<void(cocostudio::FrameData::*)(const cocostudio::BaseData*)>(&cocostudio::FrameData::copy);
mt["new"]=static_cast<cocostudio::FrameData*(*)()>(&cocostudio::FrameData::create);
}
static void RegisterLuaStudioMovementBoneData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::MovementBoneData,cocos2d::Ref,cocos2d::LuaObject>("ccs","MovementBoneData");
mt["init"]=static_cast<bool(cocostudio::MovementBoneData::*)()>(&cocostudio::MovementBoneData::init);
mt["addFrameData"]=static_cast<void(cocostudio::MovementBoneData::*)(cocostudio::FrameData*)>(&cocostudio::MovementBoneData::addFrameData);
mt["getFrameData"]=static_cast<cocostudio::FrameData*(cocostudio::MovementBoneData::*)(int)>(&cocostudio::MovementBoneData::getFrameData);
mt["new"]=static_cast<cocostudio::MovementBoneData*(*)()>(&cocostudio::MovementBoneData::create);
}
static void RegisterLuaStudioMovementData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::MovementData,cocos2d::Ref,cocos2d::LuaObject>("ccs","MovementData");
mt["addMovementBoneData"]=static_cast<void(cocostudio::MovementData::*)(cocostudio::MovementBoneData*)>(&cocostudio::MovementData::addMovementBoneData);
mt["getMovementBoneData"]=static_cast<cocostudio::MovementBoneData*(cocostudio::MovementData::*)(const std::string&)>(&cocostudio::MovementData::getMovementBoneData);
mt["new"]=static_cast<cocostudio::MovementData*(*)()>(&cocostudio::MovementData::create);
}
static void RegisterLuaStudioAnimationData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::AnimationData,cocos2d::Ref,cocos2d::LuaObject>("ccs","AnimationData");
mt["addMovement"]=static_cast<void(cocostudio::AnimationData::*)(cocostudio::MovementData*)>(&cocostudio::AnimationData::addMovement);
mt["getMovement"]=static_cast<cocostudio::MovementData*(cocostudio::AnimationData::*)(const std::string&)>(&cocostudio::AnimationData::getMovement);
mt["getMovementCount"]=static_cast<ssize_t(cocostudio::AnimationData::*)()>(&cocostudio::AnimationData::getMovementCount);
mt["new"]=static_cast<cocostudio::AnimationData*(*)()>(&cocostudio::AnimationData::create);
}
static void RegisterLuaStudioContourData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ContourData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ContourData");
mt["init"]=static_cast<bool(cocostudio::ContourData::*)()>(&cocostudio::ContourData::init);
mt["addVertex"]=static_cast<void(cocostudio::ContourData::*)(cocos2d::Vec2&)>(&cocostudio::ContourData::addVertex);
mt["new"]=static_cast<cocostudio::ContourData*(*)()>(&cocostudio::ContourData::create);
}
static void RegisterLuaStudioTextureData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::TextureData,cocos2d::Ref,cocos2d::LuaObject>("ccs","TextureData");
mt["init"]=static_cast<bool(cocostudio::TextureData::*)()>(&cocostudio::TextureData::init);
mt["addContourData"]=static_cast<void(cocostudio::TextureData::*)(cocostudio::ContourData*)>(&cocostudio::TextureData::addContourData);
mt["getContourData"]=static_cast<cocostudio::ContourData*(cocostudio::TextureData::*)(int)>(&cocostudio::TextureData::getContourData);
mt["new"]=static_cast<cocostudio::TextureData*(*)()>(&cocostudio::TextureData::create);
}
static void RegisterLuaStudioTween(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Tween,cocostudio::ProcessBase,cocos2d::Ref,cocos2d::LuaObject>("ccs","Tween");
mt["init"]=static_cast<bool(cocostudio::Tween::*)(cocostudio::Bone*)>(&cocostudio::Tween::init);
mt["play"]=static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*,int,int,int,int)>(&cocostudio::Tween::play);
mt["setAnimation"]=static_cast<void(cocostudio::Tween::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Tween::setAnimation);
mt["getAnimation"]=static_cast<cocostudio::ArmatureAnimation*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getAnimation);
mt["gotoAndPlay"]=static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPlay);
mt["gotoAndPause"]=static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPause);
mt["new"]=static_cast<cocostudio::Tween*(*)(cocostudio::Bone*)>(&cocostudio::Tween::create);
}
static void RegisterLuaStudioDisplayManager(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::DisplayManager,cocos2d::Ref,cocos2d::LuaObject>("ccs","DisplayManager");
mt["init"]=static_cast<bool(cocostudio::DisplayManager::*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::init);
mt["addDisplay"]=sol::overload(static_cast<void(cocostudio::DisplayManager::*)(cocos2d::Node*,int)>(&cocostudio::DisplayManager::addDisplay),static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DisplayData*,int)>(&cocostudio::DisplayManager::addDisplay));
mt["removeDisplay"]=static_cast<void(cocostudio::DisplayManager::*)(int)>(&cocostudio::DisplayManager::removeDisplay);
mt["getDecorativeDisplayList"]=static_cast<const cocos2d::Vector<cocostudio::DecorativeDisplay *>&(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDecorativeDisplayList);
mt["changeDisplayWithIndex"]=static_cast<void(cocostudio::DisplayManager::*)(int,bool)>(&cocostudio::DisplayManager::changeDisplayWithIndex);
mt["changeDisplayWithName"]=static_cast<void(cocostudio::DisplayManager::*)(const std::string&,bool)>(&cocostudio::DisplayManager::changeDisplayWithName);
mt["getDisplayRenderNode"]=static_cast<cocos2d::Node*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNode);
mt["getDisplayRenderNodeType"]=static_cast<cocostudio::DisplayType(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNodeType);
mt["getCurrentDisplayIndex"]=static_cast<int(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDisplayIndex);
mt["setVisible"]=static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setVisible);
mt["isVisible"]=static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isVisible);
mt["getContentSize"]=static_cast<cocos2d::Size(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getContentSize);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getBoundingBox);
mt["getAnchorPoint"]=static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPoint);
mt["getAnchorPointInPoints"]=static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPointInPoints);
mt["containPoint"]=sol::overload(static_cast<bool(cocostudio::DisplayManager::*)(float,float)>(&cocostudio::DisplayManager::containPoint),static_cast<bool(cocostudio::DisplayManager::*)(cocos2d::Vec2&)>(&cocostudio::DisplayManager::containPoint));
mt["setForceChangeDisplay"]=static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setForceChangeDisplay);
mt["isForceChangeDisplay"]=static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isForceChangeDisplay);
mt["new"]=static_cast<cocostudio::DisplayManager*(*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::create);
}
static void RegisterLuaStudioBone(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Bone,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","Bone");
mt["init"]=sol::overload(static_cast<bool(cocostudio::Bone::*)(const std::string&)>(&cocostudio::Bone::init),static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::init));
mt["addDisplay"]=sol::overload(static_cast<void(cocostudio::Bone::*)(cocos2d::Node*,int)>(&cocostudio::Bone::addDisplay),static_cast<void(cocostudio::Bone::*)(cocostudio::DisplayData*,int)>(&cocostudio::Bone::addDisplay));
mt["removeDisplay"]=static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::removeDisplay);
mt["changeDisplayWithIndex"]=static_cast<void(cocostudio::Bone::*)(int,bool)>(&cocostudio::Bone::changeDisplayWithIndex);
mt["changeDisplayWithName"]=static_cast<void(cocostudio::Bone::*)(const std::string&,bool)>(&cocostudio::Bone::changeDisplayWithName);
mt["addChildBone"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::addChildBone);
mt["setParentBone"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::setParentBone);
mt["getParentBone"]=static_cast<cocostudio::Bone*(cocostudio::Bone::*)()>(&cocostudio::Bone::getParentBone);
mt["removeFromParent"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::removeFromParent);
mt["removeChildBone"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*,bool)>(&cocostudio::Bone::removeChildBone);
mt["update"]=static_cast<void(cocostudio::Bone::*)(float)>(&cocostudio::Bone::update);
mt["updateDisplayedColor"]=static_cast<void(cocostudio::Bone::*)(const cocos2d::Color3B&)>(&cocostudio::Bone::updateDisplayedColor);
mt["updateDisplayedOpacity"]=static_cast<void(cocostudio::Bone::*)(uint8_t)>(&cocostudio::Bone::updateDisplayedOpacity);
mt["updateColor"]=static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateColor);
mt["updateZOrder"]=static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateZOrder);
mt["setLocalZOrder"]=static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::setLocalZOrder);
mt["getTween"]=static_cast<cocostudio::Tween*(cocostudio::Bone::*)()>(&cocostudio::Bone::getTween);
mt["setTransformDirty"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setTransformDirty);
mt["isTransformDirty"]=static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isTransformDirty);
mt["getNodeToArmatureTransform"]=static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToArmatureTransform);
mt["getNodeToWorldTransform"]=static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToWorldTransform);
mt["getDisplayRenderNode"]=static_cast<cocos2d::Node*(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNode);
mt["getDisplayRenderNodeType"]=static_cast<cocostudio::DisplayType(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNodeType);
mt["getColliderDetector"]=static_cast<cocostudio::ColliderDetector*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getColliderDetector);
mt["setBoneData"]=static_cast<void(cocostudio::Bone::*)(cocostudio::BoneData*)>(&cocostudio::Bone::setBoneData);
mt["getBoneData"]=static_cast<cocostudio::BoneData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getBoneData);
mt["setArmature"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setArmature);
mt["getArmature"]=static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getArmature);
mt["setChildArmature"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setChildArmature);
mt["getChildArmature"]=static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getChildArmature);
mt["getDisplayManager"]=static_cast<cocostudio::DisplayManager*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getDisplayManager);
mt["isIgnoreMovementBoneData"]=static_cast<bool(cocostudio::Bone::*)()const>(&cocostudio::Bone::isIgnoreMovementBoneData);
mt["setBlendFunc"]=static_cast<void(cocostudio::Bone::*)(const cocos2d::BlendFunc&)>(&cocostudio::Bone::setBlendFunc);
mt["getBlendFunc"]=static_cast<cocos2d::BlendFunc(cocostudio::Bone::*)()>(&cocostudio::Bone::getBlendFunc);
mt["setBlendDirty"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setBlendDirty);
mt["isBlendDirty"]=static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isBlendDirty);
mt["getTweenData"]=static_cast<cocostudio::FrameData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getTweenData);
mt["getWorldInfo"]=static_cast<cocostudio::BaseData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getWorldInfo);
mt["new"]=sol::overload(static_cast<cocostudio::Bone*(*)(const std::string&)>(&cocostudio::Bone::create),static_cast<cocostudio::Bone*(*)()>(&cocostudio::Bone::create));
}
static void RegisterLuaStudioBatchNode(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","BatchNode");
mt["init"]=static_cast<bool(cocostudio::BatchNode::*)()>(&cocostudio::BatchNode::init);
mt["addChild"]=sol::overload(static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::BatchNode::addChild),static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,int)>(&cocostudio::BatchNode::addChild));
mt["removeChild"]=static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,bool)>(&cocostudio::BatchNode::removeChild);
mt["draw"]=static_cast<void(cocostudio::BatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::BatchNode::draw);
mt["new"]=static_cast<cocostudio::BatchNode*(*)()>(&cocostudio::BatchNode::create);
}
static void RegisterLuaStudioArmatureAnimation(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureAnimation,cocostudio::ProcessBase,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureAnimation");
mt["init"]=static_cast<bool(cocostudio::ArmatureAnimation::*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::init);
mt["setSpeedScale"]=static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::setSpeedScale);
mt["getSpeedScale"]=static_cast<float(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getSpeedScale);
mt["play"]=sol::overload([](cocostudio::ArmatureAnimation* obj,const std::string& arg0){return obj->play(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1){return obj->play(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1,int arg2){return obj->play(arg0,arg1,arg2);});
mt["playWithIndex"]=sol::overload([](cocostudio::ArmatureAnimation* obj,int arg0){return obj->playWithIndex(arg0);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1){return obj->playWithIndex(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1,int arg2){return obj->playWithIndex(arg0,arg1,arg2);});
mt["playWithNames"]=sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0){return obj->playWithNames(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0,int arg1){return obj->playWithNames(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0,int arg1,bool arg2){return obj->playWithNames(arg0,arg1,arg2);});
mt["playWithIndexes"]=sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0){return obj->playWithIndexes(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0,int arg1){return obj->playWithIndexes(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0,int arg1,bool arg2){return obj->playWithIndexes(arg0,arg1,arg2);});
mt["gotoAndPlay"]=static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPlay);
mt["gotoAndPause"]=static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPause);
mt["pause"]=static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::pause);
mt["resume"]=static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::resume);
mt["stop"]=static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::stop);
mt["getMovementCount"]=static_cast<ssize_t(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getMovementCount);
mt["update"]=static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::update);
mt["getCurrentMovementID"]=static_cast<std::string(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getCurrentMovementID);
mt["setAnimationData"]=static_cast<void(cocostudio::ArmatureAnimation::*)(cocostudio::AnimationData*)>(&cocostudio::ArmatureAnimation::setAnimationData);
mt["getAnimationData"]=static_cast<cocostudio::AnimationData*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getAnimationData);
mt["new"]=static_cast<cocostudio::ArmatureAnimation*(*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::create);
}
static void RegisterLuaStudioArmatureDataManager(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureDataManager,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureDataManager");
mt["init"]=static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::init);
mt["addArmatureData"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1){return obj->addArmatureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1,const std::string& arg2){return obj->addArmatureData(arg0,arg1,arg2);});
mt["getArmatureData"]=static_cast<cocostudio::ArmatureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getArmatureData);
mt["removeArmatureData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureData);
mt["addAnimationData"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1){return obj->addAnimationData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1,const std::string& arg2){return obj->addAnimationData(arg0,arg1,arg2);});
mt["getAnimationData"]=static_cast<cocostudio::AnimationData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getAnimationData);
mt["removeAnimationData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeAnimationData);
mt["addTextureData"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1){return obj->addTextureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1,const std::string& arg2){return obj->addTextureData(arg0,arg1,arg2);});
mt["getTextureData"]=static_cast<cocostudio::TextureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getTextureData);
mt["removeTextureData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeTextureData);
mt["addArmatureFileInfo"]=sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo));
mt["addArmatureFileInfoAsync"]=sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync));
mt["addSpriteFrameFromFile"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1){return obj->addSpriteFrameFromFile(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->addSpriteFrameFromFile(arg0,arg1,arg2);});
mt["removeArmatureFileInfo"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureFileInfo);
mt["isAutoLoadSpriteFile"]=static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::isAutoLoadSpriteFile);
mt["getArmatureDatas"]=static_cast<const cocos2d::Map<std::string, cocostudio::ArmatureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getArmatureDatas);
mt["getAnimationDatas"]=static_cast<const cocos2d::Map<std::string, cocostudio::AnimationData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getAnimationDatas);
mt["getTextureDatas"]=static_cast<const cocos2d::Map<std::string, cocostudio::TextureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getTextureDatas);
mt["addRelativeData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addRelativeData);
mt["getRelativeData"]=static_cast<cocostudio::RelativeData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getRelativeData);
mt["getInstance"]=static_cast<cocostudio::ArmatureDataManager*(*)()>(&cocostudio::ArmatureDataManager::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocostudio::ArmatureDataManager::destroyInstance);
}
static void RegisterLuaStudioArmature(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Armature,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","Armature");
mt["init"]=sol::overload(static_cast<bool(cocostudio::Armature::*)(const std::string&)>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)()>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::init));
mt["addBone"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::addBone);
mt["getBone"]=static_cast<cocostudio::Bone*(cocostudio::Armature::*)(const std::string&)const>(&cocostudio::Armature::getBone);
mt["changeBoneParent"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::changeBoneParent);
mt["removeBone"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,bool)>(&cocostudio::Armature::removeBone);
mt["getBoneDic"]=static_cast<const cocos2d::Map<std::string, cocostudio::Bone *>&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoneDic);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoundingBox);
mt["getBoneAtPoint"]=static_cast<cocostudio::Bone*(cocostudio::Armature::*)(float,float)const>(&cocostudio::Armature::getBoneAtPoint);
mt["draw"]=static_cast<void(cocostudio::Armature::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Armature::draw);
mt["update"]=static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::update);
mt["getNodeToParentTransform"]=static_cast<const cocos2d::Mat4&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getNodeToParentTransform);
mt["setBlendFunc"]=static_cast<void(cocostudio::Armature::*)(const cocos2d::BlendFunc&)>(&cocostudio::Armature::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBlendFunc);
mt["updateOffsetPoint"]=static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::updateOffsetPoint);
mt["setAnchorPoint"]=static_cast<void(cocostudio::Armature::*)(const cocos2d::Vec2&)>(&cocostudio::Armature::setAnchorPoint);
mt["getAnchorPointInPoints"]=static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnchorPointInPoints);
mt["getOffsetPoints"]=static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getOffsetPoints);
mt["setAnimation"]=static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Armature::setAnimation);
mt["getAnimation"]=static_cast<cocostudio::ArmatureAnimation*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnimation);
mt["getArmatureTransformDirty"]=static_cast<bool(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureTransformDirty);
mt["setArmatureData"]=static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureData*)>(&cocostudio::Armature::setArmatureData);
mt["getArmatureData"]=static_cast<cocostudio::ArmatureData*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureData);
mt["setParentBone"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*)>(&cocostudio::Armature::setParentBone);
mt["getParentBone"]=static_cast<cocostudio::Bone*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getParentBone);
mt["setVersion"]=static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::setVersion);
mt["getVersion"]=static_cast<float(cocostudio::Armature::*)()const>(&cocostudio::Armature::getVersion);
mt["setBatchNode"]=static_cast<void(cocostudio::Armature::*)(cocostudio::BatchNode*)>(&cocostudio::Armature::setBatchNode);
mt["getBatchNode"]=static_cast<cocostudio::BatchNode*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBatchNode);
mt["new"]=sol::overload(static_cast<cocostudio::Armature*(*)(const std::string&)>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)()>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::create));
}
static void RegisterLuaStudioSkin(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Skin,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("ccs","Skin");
mt["initWithSpriteFrameName"]=static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithSpriteFrameName);
mt["initWithFile"]=static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithFile);
mt["updateArmatureTransform"]=static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateArmatureTransform);
mt["updateTransform"]=static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateTransform);
mt["getNodeToWorldTransform"]=static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransform);
mt["getNodeToWorldTransformAR"]=static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransformAR);
mt["draw"]=static_cast<void(cocostudio::Skin::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Skin::draw);
mt["setBone"]=static_cast<void(cocostudio::Skin::*)(cocostudio::Bone*)>(&cocostudio::Skin::setBone);
mt["getBone"]=static_cast<cocostudio::Bone*(cocostudio::Skin::*)()const>(&cocostudio::Skin::getBone);
mt["getDisplayName"]=static_cast<const std::string&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getDisplayName);
mt["new"]=sol::overload(static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::create),static_cast<cocostudio::Skin*(*)()>(&cocostudio::Skin::create));
mt["createWithSpriteFrameName"]=static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::createWithSpriteFrameName);
}
static void RegisterLuaStudioComAttribute(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComAttribute,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComAttribute");
mt["init"]=static_cast<bool(cocostudio::ComAttribute::*)()>(&cocostudio::ComAttribute::init);
mt["serialize"]=static_cast<bool(cocostudio::ComAttribute::*)(void*)>(&cocostudio::ComAttribute::serialize);
mt["setInt"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,int)>(&cocostudio::ComAttribute::setInt);
mt["setFloat"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,float)>(&cocostudio::ComAttribute::setFloat);
mt["setBool"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,bool)>(&cocostudio::ComAttribute::setBool);
mt["setString"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,const std::string&)>(&cocostudio::ComAttribute::setString);
mt["getInt"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getInt(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,int arg1){return obj->getInt(arg0,arg1);});
mt["getFloat"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getFloat(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,float arg1){return obj->getFloat(arg0,arg1);});
mt["getBool"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getBool(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,bool arg1){return obj->getBool(arg0,arg1);});
mt["getString"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getString(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,const std::string& arg1){return obj->getString(arg0,arg1);});
mt["parse"]=static_cast<bool(cocostudio::ComAttribute::*)(const std::string&)>(&cocostudio::ComAttribute::parse);
mt["createInstance"]=static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAttribute::createInstance);
mt["new"]=static_cast<cocostudio::ComAttribute*(*)()>(&cocostudio::ComAttribute::create);
}
static void RegisterLuaStudioComAudio(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComAudio,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject,cocos2d::PlayableProtocol>("ccs","ComAudio");
mt["init"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::init);
mt["onAdd"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onAdd);
mt["onRemove"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onRemove);
mt["serialize"]=static_cast<bool(cocostudio::ComAudio::*)(void*)>(&cocostudio::ComAudio::serialize);
mt["endToLua"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::end);
mt["preloadBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadBackgroundMusic);
mt["playBackgroundMusic"]=sol::overload(static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playBackgroundMusic));
mt["stopBackgroundMusic"]=sol::overload(static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::stopBackgroundMusic));
mt["pauseBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseBackgroundMusic);
mt["resumeBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeBackgroundMusic);
mt["rewindBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::rewindBackgroundMusic);
mt["willPlayBackgroundMusic"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::willPlayBackgroundMusic);
mt["isBackgroundMusicPlaying"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isBackgroundMusicPlaying);
mt["getBackgroundMusicVolume"]=static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getBackgroundMusicVolume);
mt["setBackgroundMusicVolume"]=static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setBackgroundMusicVolume);
mt["getEffectsVolume"]=static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getEffectsVolume);
mt["setEffectsVolume"]=static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setEffectsVolume);
mt["playEffect"]=sol::overload(static_cast<unsigned int(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playEffect));
mt["pauseEffect"]=static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::pauseEffect);
mt["pauseAllEffects"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseAllEffects);
mt["resumeEffect"]=static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::resumeEffect);
mt["resumeAllEffects"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeAllEffects);
mt["stopEffect"]=static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::stopEffect);
mt["stopAllEffects"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopAllEffects);
mt["preloadEffect"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadEffect);
mt["unloadEffect"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::unloadEffect);
mt["setFile"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::setFile);
mt["getFile"]=static_cast<const char*(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getFile);
mt["setLoop"]=static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::setLoop);
mt["isLoop"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isLoop);
mt["start"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::start);
mt["stop"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stop);
mt["createInstance"]=static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAudio::createInstance);
mt["new"]=static_cast<cocostudio::ComAudio*(*)()>(&cocostudio::ComAudio::create);
}
static void RegisterLuaStudioComController(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComController,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject,cocostudio::InputDelegate>("ccs","ComController");
mt["init"]=static_cast<bool(cocostudio::ComController::*)()>(&cocostudio::ComController::init);
mt["onAdd"]=static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onAdd);
mt["onRemove"]=static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onRemove);
mt["update"]=static_cast<void(cocostudio::ComController::*)(float)>(&cocostudio::ComController::update);
mt["createInstance"]=static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComController::createInstance);
mt["new"]=static_cast<cocostudio::ComController*(*)()>(&cocostudio::ComController::create);
}
static void RegisterLuaStudioComRender(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComRender,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComRender");
mt["onAdd"]=static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onAdd);
mt["onRemove"]=static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onRemove);
mt["serialize"]=static_cast<bool(cocostudio::ComRender::*)(void*)>(&cocostudio::ComRender::serialize);
mt["getNode"]=static_cast<cocos2d::Node*(cocostudio::ComRender::*)()>(&cocostudio::ComRender::getNode);
mt["setNode"]=static_cast<void(cocostudio::ComRender::*)(cocos2d::Node*)>(&cocostudio::ComRender::setNode);
mt["createInstance"]=static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComRender::createInstance);
mt["new"]=sol::overload(static_cast<cocostudio::ComRender*(*)(cocos2d::Node*,const char*)>(&cocostudio::ComRender::create),static_cast<cocostudio::ComRender*(*)()>(&cocostudio::ComRender::create));
}
static void RegisterLuaStudioGUIReader(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::GUIReader,cocos2d::Ref,cocos2d::LuaObject>("ccs","GUIReader");
mt["widgetFromJsonFile"]=static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromJsonFile);
mt["widgetFromBinaryFile"]=static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromBinaryFile);
mt["getVersionInteger"]=static_cast<int(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::getVersionInteger);
mt["setFilePath"]=static_cast<void(cocostudio::GUIReader::*)(const std::string&)>(&cocostudio::GUIReader::setFilePath);
mt["getFilePath"]=static_cast<const std::string&(cocostudio::GUIReader::*)()const>(&cocostudio::GUIReader::getFilePath);
mt["getInstance"]=static_cast<cocostudio::GUIReader*(*)()>(&cocostudio::GUIReader::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocostudio::GUIReader::destroyInstance);
}
static void RegisterLuaStudioSceneReader(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::SceneReader>("ccs","SceneReader");
mt["createNodeWithSceneFile"]=sol::overload([](cocostudio::SceneReader* obj,const std::string& arg0){return obj->createNodeWithSceneFile(arg0);},[](cocostudio::SceneReader* obj,const std::string& arg0,cocostudio::SceneReader::AttachComponentType arg1){return obj->createNodeWithSceneFile(arg0,arg1);});
mt["setTarget"]=static_cast<void(cocostudio::SceneReader::*)(const std::function<void (cocos2d::Ref *, void *)>&)>(&cocostudio::SceneReader::setTarget);
mt["getNodeByTag"]=static_cast<cocos2d::Node*(cocostudio::SceneReader::*)(int)>(&cocostudio::SceneReader::getNodeByTag);
mt["getAttachComponentType"]=static_cast<cocostudio::SceneReader::AttachComponentType(cocostudio::SceneReader::*)()>(&cocostudio::SceneReader::getAttachComponentType);
mt["getInstance"]=static_cast<cocostudio::SceneReader*(*)()>(&cocostudio::SceneReader::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocostudio::SceneReader::destroyInstance);
mt["sceneReaderVersion"]=static_cast<const char*(*)()>(&cocostudio::SceneReader::sceneReaderVersion);
}
static void RegisterLuaStudioActionTimelineCache(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineCache>("ccs","ActionTimelineCache");
mt["purge"]=static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::purge);
mt["init"]=static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::init);
mt["removeAction"]=static_cast<void(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::removeAction);
mt["createActionFromJson"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromJson);
mt["createActionFromContent"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromContent);
mt["loadAnimationActionWithFile"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFile);
mt["loadAnimationActionWithContent"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithContent);
mt["createActionWithFlatBuffersFile"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersFile);
mt["loadAnimationActionWithFlatBuffersFile"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFlatBuffersFile);
mt["createActionWithFlatBuffersForSimulator"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersForSimulator);
mt["destroyInstance"]=static_cast<void(*)()>(&cocostudio::timeline::ActionTimelineCache::destroyInstance);
mt["createAction"]=static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createAction);
}
static void RegisterLuaStudioFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","Frame");
mt["setFrameIndex"]=static_cast<void(cocostudio::timeline::Frame::*)(unsigned int)>(&cocostudio::timeline::Frame::setFrameIndex);
mt["getFrameIndex"]=static_cast<unsigned int(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getFrameIndex);
mt["setTimeline"]=static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::Frame::setTimeline);
mt["getTimeline"]=static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTimeline);
mt["setNode"]=static_cast<void(cocostudio::timeline::Frame::*)(cocos2d::Node*)>(&cocostudio::timeline::Frame::setNode);
mt["getNode"]=static_cast<cocos2d::Node*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getNode);
mt["setTween"]=static_cast<void(cocostudio::timeline::Frame::*)(bool)>(&cocostudio::timeline::Frame::setTween);
mt["isTween"]=static_cast<bool(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::isTween);
mt["setTweenType"]=static_cast<void(cocostudio::timeline::Frame::*)(const cocos2d::tweenfunc::TweenType&)>(&cocostudio::timeline::Frame::setTweenType);
mt["getTweenType"]=static_cast<cocos2d::tweenfunc::TweenType(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTweenType);
mt["setEasingParams"]=static_cast<void(cocostudio::timeline::Frame::*)(const std::vector<float>&)>(&cocostudio::timeline::Frame::setEasingParams);
mt["getEasingParams"]=static_cast<const std::vector<float>&(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getEasingParams);
mt["isEnterWhenPassed"]=static_cast<bool(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::isEnterWhenPassed);
mt["apply"]=static_cast<void(cocostudio::timeline::Frame::*)(float)>(&cocostudio::timeline::Frame::apply);
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::clone);
}
static void RegisterLuaStudioVisibleFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::VisibleFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","VisibleFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::VisibleFrame::*)()>(&cocostudio::timeline::VisibleFrame::clone);
mt["setVisible"]=static_cast<void(cocostudio::timeline::VisibleFrame::*)(bool)>(&cocostudio::timeline::VisibleFrame::setVisible);
mt["isVisible"]=static_cast<bool(cocostudio::timeline::VisibleFrame::*)()const>(&cocostudio::timeline::VisibleFrame::isVisible);
mt["new"]=static_cast<cocostudio::timeline::VisibleFrame*(*)()>(&cocostudio::timeline::VisibleFrame::create);
}
static void RegisterLuaStudioTextureFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::TextureFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","TextureFrame");
mt["setNode"]=static_cast<void(cocostudio::timeline::TextureFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::TextureFrame::setNode);
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::TextureFrame::*)()>(&cocostudio::timeline::TextureFrame::clone);
mt["setTextureName"]=static_cast<void(cocostudio::timeline::TextureFrame::*)(std::string)>(&cocostudio::timeline::TextureFrame::setTextureName);
mt["getTextureName"]=static_cast<std::string(cocostudio::timeline::TextureFrame::*)()const>(&cocostudio::timeline::TextureFrame::getTextureName);
mt["new"]=static_cast<cocostudio::timeline::TextureFrame*(*)()>(&cocostudio::timeline::TextureFrame::create);
}
static void RegisterLuaStudioRotationFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::RotationFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","RotationFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationFrame::*)()>(&cocostudio::timeline::RotationFrame::clone);
mt["setRotation"]=static_cast<void(cocostudio::timeline::RotationFrame::*)(float)>(&cocostudio::timeline::RotationFrame::setRotation);
mt["getRotation"]=static_cast<float(cocostudio::timeline::RotationFrame::*)()const>(&cocostudio::timeline::RotationFrame::getRotation);
mt["new"]=static_cast<cocostudio::timeline::RotationFrame*(*)()>(&cocostudio::timeline::RotationFrame::create);
}
static void RegisterLuaStudioSkewFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","SkewFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::SkewFrame::*)()>(&cocostudio::timeline::SkewFrame::clone);
mt["setSkewX"]=static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewX);
mt["getSkewX"]=static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewX);
mt["setSkewY"]=static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewY);
mt["getSkewY"]=static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewY);
mt["new"]=static_cast<cocostudio::timeline::SkewFrame*(*)()>(&cocostudio::timeline::SkewFrame::create);
}
static void RegisterLuaStudioRotationSkewFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::RotationSkewFrame,cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","RotationSkewFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationSkewFrame::*)()>(&cocostudio::timeline::RotationSkewFrame::clone);
mt["new"]=static_cast<cocostudio::timeline::RotationSkewFrame*(*)()>(&cocostudio::timeline::RotationSkewFrame::create);
}
static void RegisterLuaStudioPositionFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::PositionFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","PositionFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PositionFrame::*)()>(&cocostudio::timeline::PositionFrame::clone);
mt["setPosition"]=static_cast<void(cocostudio::timeline::PositionFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::PositionFrame::setPosition);
mt["getPosition"]=static_cast<cocos2d::Point(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getPosition);
mt["setX"]=static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setX);
mt["setY"]=static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setY);
mt["getX"]=static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getX);
mt["getY"]=static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getY);
mt["new"]=static_cast<cocostudio::timeline::PositionFrame*(*)()>(&cocostudio::timeline::PositionFrame::create);
}
static void RegisterLuaStudioScaleFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ScaleFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ScaleFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ScaleFrame::*)()>(&cocostudio::timeline::ScaleFrame::clone);
mt["setScale"]=static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScale);
mt["setScaleX"]=static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleX);
mt["getScaleX"]=static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleX);
mt["setScaleY"]=static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleY);
mt["getScaleY"]=static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleY);
mt["new"]=static_cast<cocostudio::timeline::ScaleFrame*(*)()>(&cocostudio::timeline::ScaleFrame::create);
}
static void RegisterLuaStudioAnchorPointFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::AnchorPointFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","AnchorPointFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AnchorPointFrame::*)()>(&cocostudio::timeline::AnchorPointFrame::clone);
mt["setAnchorPoint"]=static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::AnchorPointFrame::setAnchorPoint);
mt["getAnchorPoint"]=static_cast<cocos2d::Point(cocostudio::timeline::AnchorPointFrame::*)()const>(&cocostudio::timeline::AnchorPointFrame::getAnchorPoint);
mt["new"]=static_cast<cocostudio::timeline::AnchorPointFrame*(*)()>(&cocostudio::timeline::AnchorPointFrame::create);
}
static void RegisterLuaStudioInnerActionFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::InnerActionFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","InnerActionFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::InnerActionFrame::*)()>(&cocostudio::timeline::InnerActionFrame::clone);
mt["setInnerActionType"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::InnerActionType)>(&cocostudio::timeline::InnerActionFrame::setInnerActionType);
mt["getInnerActionType"]=static_cast<cocostudio::timeline::InnerActionType(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getInnerActionType);
mt["setEnterWithName"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(bool)>(&cocostudio::timeline::InnerActionFrame::setEnterWithName);
mt["setStartFrameIndex"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setStartFrameIndex);
mt["getStartFrameIndex"]=static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getStartFrameIndex);
mt["setEndFrameIndex"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setEndFrameIndex);
mt["getEndFrameIndex"]=static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getEndFrameIndex);
mt["setAnimationName"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(const std::string&)>(&cocostudio::timeline::InnerActionFrame::setAnimationName);
mt["setSingleFrameIndex"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setSingleFrameIndex);
mt["getSingleFrameIndex"]=static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getSingleFrameIndex);
mt["new"]=static_cast<cocostudio::timeline::InnerActionFrame*(*)()>(&cocostudio::timeline::InnerActionFrame::create);
}
static void RegisterLuaStudioColorFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ColorFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ColorFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ColorFrame::*)()>(&cocostudio::timeline::ColorFrame::clone);
mt["setColor"]=static_cast<void(cocostudio::timeline::ColorFrame::*)(const cocos2d::Color3B&)>(&cocostudio::timeline::ColorFrame::setColor);
mt["getColor"]=static_cast<cocos2d::Color3B(cocostudio::timeline::ColorFrame::*)()const>(&cocostudio::timeline::ColorFrame::getColor);
mt["new"]=static_cast<cocostudio::timeline::ColorFrame*(*)()>(&cocostudio::timeline::ColorFrame::create);
}
static void RegisterLuaStudioAlphaFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::AlphaFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","AlphaFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AlphaFrame::*)()>(&cocostudio::timeline::AlphaFrame::clone);
mt["setAlpha"]=static_cast<void(cocostudio::timeline::AlphaFrame::*)(uint8_t)>(&cocostudio::timeline::AlphaFrame::setAlpha);
mt["getAlpha"]=static_cast<uint8_t(cocostudio::timeline::AlphaFrame::*)()const>(&cocostudio::timeline::AlphaFrame::getAlpha);
mt["new"]=static_cast<cocostudio::timeline::AlphaFrame*(*)()>(&cocostudio::timeline::AlphaFrame::create);
}
static void RegisterLuaStudioEventFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::EventFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","EventFrame");
mt["init"]=static_cast<void(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::init);
mt["setNode"]=static_cast<void(cocostudio::timeline::EventFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::EventFrame::setNode);
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::clone);
mt["setEvent"]=static_cast<void(cocostudio::timeline::EventFrame::*)(std::string)>(&cocostudio::timeline::EventFrame::setEvent);
mt["getEvent"]=static_cast<std::string(cocostudio::timeline::EventFrame::*)()const>(&cocostudio::timeline::EventFrame::getEvent);
mt["new"]=static_cast<cocostudio::timeline::EventFrame*(*)()>(&cocostudio::timeline::EventFrame::create);
}
static void RegisterLuaStudioZOrderFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ZOrderFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ZOrderFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ZOrderFrame::*)()>(&cocostudio::timeline::ZOrderFrame::clone);
mt["setZOrder"]=static_cast<void(cocostudio::timeline::ZOrderFrame::*)(int)>(&cocostudio::timeline::ZOrderFrame::setZOrder);
mt["getZOrder"]=static_cast<int(cocostudio::timeline::ZOrderFrame::*)()const>(&cocostudio::timeline::ZOrderFrame::getZOrder);
mt["new"]=static_cast<cocostudio::timeline::ZOrderFrame*(*)()>(&cocostudio::timeline::ZOrderFrame::create);
}
static void RegisterLuaStudioBlendFuncFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::BlendFuncFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","BlendFuncFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::BlendFuncFrame::*)()>(&cocostudio::timeline::BlendFuncFrame::clone);
mt["getBlendFunc"]=static_cast<cocos2d::BlendFunc(cocostudio::timeline::BlendFuncFrame::*)()const>(&cocostudio::timeline::BlendFuncFrame::getBlendFunc);
mt["setBlendFunc"]=static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocos2d::BlendFunc)>(&cocostudio::timeline::BlendFuncFrame::setBlendFunc);
mt["new"]=static_cast<cocostudio::timeline::BlendFuncFrame*(*)()>(&cocostudio::timeline::BlendFuncFrame::create);
}
static void RegisterLuaStudioPlayableFrame(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::PlayableFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","PlayableFrame");
mt["clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PlayableFrame::*)()>(&cocostudio::timeline::PlayableFrame::clone);
mt["getPlayableAct"]=static_cast<std::string(cocostudio::timeline::PlayableFrame::*)()const>(&cocostudio::timeline::PlayableFrame::getPlayableAct);
mt["setPlayableAct"]=static_cast<void(cocostudio::timeline::PlayableFrame::*)(std::string)>(&cocostudio::timeline::PlayableFrame::setPlayableAct);
mt["new"]=static_cast<cocostudio::timeline::PlayableFrame*(*)()>(&cocostudio::timeline::PlayableFrame::create);
}
static void RegisterLuaStudioTimeline(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::Timeline,cocos2d::Ref,cocos2d::LuaObject>("ccs","Timeline");
mt["gotoFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::gotoFrame);
mt["stepToFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::stepToFrame);
mt["getFrames"]=static_cast<const cocos2d::Vector<cocostudio::timeline::Frame *>&(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getFrames);
mt["addFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::addFrame);
mt["insertFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Timeline::insertFrame);
mt["removeFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::removeFrame);
mt["setActionTag"]=static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::setActionTag);
mt["getActionTag"]=static_cast<int(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTag);
mt["setNode"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocos2d::Node*)>(&cocostudio::timeline::Timeline::setNode);
mt["getNode"]=static_cast<cocos2d::Node*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getNode);
mt["setActionTimeline"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::Timeline::setActionTimeline);
mt["getActionTimeline"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTimeline);
mt["clone"]=static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Timeline::*)()>(&cocostudio::timeline::Timeline::clone);
mt["new"]=static_cast<cocostudio::timeline::Timeline*(*)()>(&cocostudio::timeline::Timeline::create);
}
static void RegisterLuaStudioActionTimelineData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionTimelineData");
mt["setActionTag"]=static_cast<void(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::setActionTag);
mt["getActionTag"]=static_cast<int(cocostudio::timeline::ActionTimelineData::*)()const>(&cocostudio::timeline::ActionTimelineData::getActionTag);
mt["init"]=static_cast<bool(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::init);
mt["new"]=static_cast<cocostudio::timeline::ActionTimelineData*(*)(int)>(&cocostudio::timeline::ActionTimelineData::create);
}
static void RegisterLuaStudioActionTimeline(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimeline,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject,cocos2d::Clonable,cocos2d::PlayableProtocol>("ccs","ActionTimeline");
mt["play"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string,bool)>(&cocostudio::timeline::ActionTimeline::play);
mt["init"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::init);
mt["gotoFrameAndPlay"]=sol::overload(static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay));
mt["gotoFrameAndPause"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPause);
mt["pause"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::pause);
mt["resume"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::resume);
mt["isPlaying"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isPlaying);
mt["setTimeSpeed"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::setTimeSpeed);
mt["getTimeSpeed"]=static_cast<float(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimeSpeed);
mt["setDuration"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setDuration);
mt["getDuration"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getDuration);
mt["getStartFrame"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getStartFrame);
mt["getEndFrame"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getEndFrame);
mt["setCurrentFrame"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setCurrentFrame);
mt["getCurrentFrame"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getCurrentFrame);
mt["addTimeline"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::addTimeline);
mt["removeTimeline"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::removeTimeline);
mt["getTimelines"]=static_cast<const cocos2d::Vector<cocostudio::timeline::Timeline *>&(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimelines);
mt["addAnimationInfo"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(const cocostudio::timeline::AnimationInfo&)>(&cocostudio::timeline::ActionTimeline::addAnimationInfo);
mt["removeAnimationInfo"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string)>(&cocostudio::timeline::ActionTimeline::removeAnimationInfo);
mt["IsAnimationInfoExists"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::IsAnimationInfoExists);
mt["getAnimationInfo"]=static_cast<const cocostudio::timeline::AnimationInfo&(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::getAnimationInfo);
mt["setAnimationEndCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(const std::string,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setAnimationEndCallFunc);
mt["clearFrameEventCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEventCallFunc);
mt["setLastFrameCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setLastFrameCallFunc);
mt["clearLastFrameCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearLastFrameCallFunc);
mt["addFrameEndCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::addFrameEndCallFunc);
mt["removeFrameEndCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFunc);
mt["removeFrameEndCallFuncs"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFuncs);
mt["clearFrameEndCallFuncs"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEndCallFuncs);
mt["clone"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::clone);
mt["reverse"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::reverse);
mt["step"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::step);
mt["startWithTarget"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimeline::startWithTarget);
mt["isDone"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isDone);
mt["start"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::start);
mt["stop"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::stop);
mt["new"]=static_cast<cocostudio::timeline::ActionTimeline*(*)()>(&cocostudio::timeline::ActionTimeline::create);
}
static void RegisterLuaStudioActionTimelineNode(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionTimelineNode");
mt["init"]=sol::overload(static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::init),static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::init));
mt["setRoot"]=static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimelineNode::setRoot);
mt["getRoot"]=static_cast<cocos2d::Node*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getRoot);
mt["setActionTimeline"]=static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::setActionTimeline);
mt["getActionTimeline"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getActionTimeline);
mt["new"]=static_cast<cocostudio::timeline::ActionTimelineNode*(*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::create);
}
static void RegisterLuaStudioBoneNode(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","BoneNode");
mt["addChild"]=sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,int)>(&cocostudio::timeline::BoneNode::addChild),static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::timeline::BoneNode::addChild));
mt["removeChild"]=static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,bool)>(&cocostudio::timeline::BoneNode::removeChild);
mt["getChildBones"]=sol::overload(static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getChildBones),static_cast<const cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getChildBones));
mt["getRootSkeletonNode"]=static_cast<cocostudio::timeline::SkeletonNode*(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getRootSkeletonNode);
mt["getAllSubBones"]=static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubBones);
mt["addSkin"]=sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool,bool)>(&cocostudio::timeline::BoneNode::addSkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::addSkin));
mt["displaySkin"]=sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&,bool)>(&cocostudio::timeline::BoneNode::displaySkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::displaySkin));
mt["getVisibleSkins"]=static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkins);
mt["getSkins"]=sol::overload(static_cast<cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getSkins),static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getSkins));
mt["getAllSubSkins"]=static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubSkins);
mt["setBlendFunc"]=static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::BlendFunc&)>(&cocostudio::timeline::BoneNode::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBlendFunc);
mt["setDebugDrawEnabled"]=static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setDebugDrawEnabled);
mt["isDebugDrawEnabled"]=static_cast<bool(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::isDebugDrawEnabled);
mt["setDebugDrawLength"]=static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawLength);
mt["getDebugDrawLength"]=static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawLength);
mt["setDebugDrawWidth"]=static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawWidth);
mt["getDebugDrawWidth"]=static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawWidth);
mt["setDebugDrawColor"]=static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Color4F&)>(&cocostudio::timeline::BoneNode::setDebugDrawColor);
mt["getDebugDrawColor"]=static_cast<cocos2d::Color4F(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawColor);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBoundingBox);
mt["getVisibleSkinsRect"]=static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkinsRect);
mt["draw"]=static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::timeline::BoneNode::draw);
mt["setLocalZOrder"]=static_cast<void(cocostudio::timeline::BoneNode::*)(int)>(&cocostudio::timeline::BoneNode::setLocalZOrder);
mt["setName"]=static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&)>(&cocostudio::timeline::BoneNode::setName);
mt["setVisible"]=static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setVisible);
mt["setContentSize"]=static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Size&)>(&cocostudio::timeline::BoneNode::setContentSize);
mt["setAnchorPoint"]=static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Vec2&)>(&cocostudio::timeline::BoneNode::setAnchorPoint);
mt["init"]=static_cast<bool(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::init);
mt["new"]=sol::overload(static_cast<cocostudio::timeline::BoneNode*(*)(int)>(&cocostudio::timeline::BoneNode::create),static_cast<cocostudio::timeline::BoneNode*(*)()>(&cocostudio::timeline::BoneNode::create));
}
static void RegisterLuaStudioSkeletonNode(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::SkeletonNode,cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","SkeletonNode");
mt["getBoneNode"]=static_cast<cocostudio::timeline::BoneNode*(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::getBoneNode);
mt["getAllSubBonesMap"]=static_cast<const cocos2d::Map<std::string, cocostudio::timeline::BoneNode *>&(cocostudio::timeline::SkeletonNode::*)()const>(&cocostudio::timeline::SkeletonNode::getAllSubBonesMap);
mt["changeSkins"]=sol::overload(static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::changeSkins),static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::map<std::string, std::string>&)>(&cocostudio::timeline::SkeletonNode::changeSkins));
mt["addSkinGroup"]=static_cast<void(cocostudio::timeline::SkeletonNode::*)(std::string,std::map<std::string, std::string>)>(&cocostudio::timeline::SkeletonNode::addSkinGroup);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocostudio::timeline::SkeletonNode::*)()const>(&cocostudio::timeline::SkeletonNode::getBoundingBox);
mt["init"]=static_cast<bool(cocostudio::timeline::SkeletonNode::*)()>(&cocostudio::timeline::SkeletonNode::init);
mt["new"]=static_cast<cocostudio::timeline::SkeletonNode*(*)()>(&cocostudio::timeline::SkeletonNode::create);
}
static void RegisterLuaStudioComExtensionData(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComExtensionData,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComExtensionData");
mt["onAdd"]=static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onAdd);
mt["onRemove"]=static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onRemove);
mt["init"]=static_cast<bool(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::init);
mt["setCustomProperty"]=static_cast<void(cocostudio::ComExtensionData::*)(const std::string&)>(&cocostudio::ComExtensionData::setCustomProperty);
mt["getCustomProperty"]=static_cast<std::string(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getCustomProperty);
mt["setActionTag"]=static_cast<void(cocostudio::ComExtensionData::*)(int)>(&cocostudio::ComExtensionData::setActionTag);
mt["getActionTag"]=static_cast<int(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getActionTag);
mt["createInstance"]=static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComExtensionData::createInstance);
mt["new"]=static_cast<cocostudio::ComExtensionData*(*)()>(&cocostudio::ComExtensionData::create);
}
void RegisterLuaStudioAuto(cocos2d::Lua& lua) {
RegisterLuaStudioActionFrame(lua);
RegisterLuaStudioActionMoveFrame(lua);
RegisterLuaStudioActionScaleFrame(lua);
RegisterLuaStudioActionRotationFrame(lua);
RegisterLuaStudioActionFadeFrame(lua);
RegisterLuaStudioActionTintFrame(lua);
RegisterLuaStudioActionObject(lua);
RegisterLuaStudioActionManagerEx(lua);
RegisterLuaStudioBaseData(lua);
RegisterLuaStudioDisplayData(lua);
RegisterLuaStudioSpriteDisplayData(lua);
RegisterLuaStudioArmatureDisplayData(lua);
RegisterLuaStudioParticleDisplayData(lua);
RegisterLuaStudioBoneData(lua);
RegisterLuaStudioArmatureData(lua);
RegisterLuaStudioFrameData(lua);
RegisterLuaStudioMovementBoneData(lua);
RegisterLuaStudioMovementData(lua);
RegisterLuaStudioAnimationData(lua);
RegisterLuaStudioContourData(lua);
RegisterLuaStudioTextureData(lua);
RegisterLuaStudioTween(lua);
RegisterLuaStudioDisplayManager(lua);
RegisterLuaStudioBone(lua);
RegisterLuaStudioBatchNode(lua);
RegisterLuaStudioArmatureAnimation(lua);
RegisterLuaStudioArmatureDataManager(lua);
RegisterLuaStudioArmature(lua);
RegisterLuaStudioSkin(lua);
RegisterLuaStudioComAttribute(lua);
RegisterLuaStudioComAudio(lua);
RegisterLuaStudioComController(lua);
RegisterLuaStudioComRender(lua);
RegisterLuaStudioGUIReader(lua);
RegisterLuaStudioSceneReader(lua);
RegisterLuaStudioActionTimelineCache(lua);
RegisterLuaStudioFrame(lua);
RegisterLuaStudioVisibleFrame(lua);
RegisterLuaStudioTextureFrame(lua);
RegisterLuaStudioRotationFrame(lua);
RegisterLuaStudioSkewFrame(lua);
RegisterLuaStudioRotationSkewFrame(lua);
RegisterLuaStudioPositionFrame(lua);
RegisterLuaStudioScaleFrame(lua);
RegisterLuaStudioAnchorPointFrame(lua);
RegisterLuaStudioInnerActionFrame(lua);
RegisterLuaStudioColorFrame(lua);
RegisterLuaStudioAlphaFrame(lua);
RegisterLuaStudioEventFrame(lua);
RegisterLuaStudioZOrderFrame(lua);
RegisterLuaStudioBlendFuncFrame(lua);
RegisterLuaStudioPlayableFrame(lua);
RegisterLuaStudioTimeline(lua);
RegisterLuaStudioActionTimelineData(lua);
RegisterLuaStudioActionTimeline(lua);
RegisterLuaStudioActionTimelineNode(lua);
RegisterLuaStudioBoneNode(lua);
RegisterLuaStudioSkeletonNode(lua);
RegisterLuaStudioComExtensionData(lua);
}
