#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
static void RegisterLuaActionFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionFrame"
,"setFrameIndex",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameIndex)
,"getFrameIndex",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameIndex)
,"setFrameTime",static_cast<void(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::setFrameTime)
,"getFrameTime",static_cast<float(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameTime)
,"setFrameType",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameType)
,"getFrameType",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameType)
,"setEasingType",static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setEasingType)
,"getEasingType",static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getEasingType)
,"getAction",sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::getAction))
,"setEasingParameter",static_cast<void(cocostudio::ActionFrame::*)(std::vector<float>&)>(&cocostudio::ActionFrame::setEasingParameter)
);}
static void RegisterLuaActionMoveFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionMoveFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionMoveFrame"
,"setPosition",static_cast<void(cocostudio::ActionMoveFrame::*)(cocos2d::Vec2)>(&cocostudio::ActionMoveFrame::setPosition)
,"getPosition",static_cast<cocos2d::Vec2(cocostudio::ActionMoveFrame::*)()>(&cocostudio::ActionMoveFrame::getPosition)
,"getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionMoveFrame::*)(float)>(&cocostudio::ActionMoveFrame::getAction)
);}
static void RegisterLuaActionScaleFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionScaleFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionScaleFrame"
,"setScaleX",static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleX)
,"getScaleX",static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleX)
,"setScaleY",static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleY)
,"getScaleY",static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleY)
,"getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::getAction)
);}
static void RegisterLuaActionRotationFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionRotationFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionRotationFrame"
,"setRotation",static_cast<void(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::setRotation)
,"getRotation",static_cast<float(cocostudio::ActionRotationFrame::*)()>(&cocostudio::ActionRotationFrame::getRotation)
,"getAction",sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionRotationFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::getAction))
);}
static void RegisterLuaActionFadeFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionFadeFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionFadeFrame"
,"setOpacity",static_cast<void(cocostudio::ActionFadeFrame::*)(int)>(&cocostudio::ActionFadeFrame::setOpacity)
,"getOpacity",static_cast<int(cocostudio::ActionFadeFrame::*)()>(&cocostudio::ActionFadeFrame::getOpacity)
,"getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionFadeFrame::*)(float)>(&cocostudio::ActionFadeFrame::getAction)
);}
static void RegisterLuaActionTintFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionTintFrame,cocostudio::ActionFrame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionTintFrame"
,"setColor",static_cast<void(cocostudio::ActionTintFrame::*)(cocos2d::Color3B)>(&cocostudio::ActionTintFrame::setColor)
,"getColor",static_cast<cocos2d::Color3B(cocostudio::ActionTintFrame::*)()>(&cocostudio::ActionTintFrame::getColor)
,"getAction",static_cast<cocos2d::ActionInterval*(cocostudio::ActionTintFrame::*)(float)>(&cocostudio::ActionTintFrame::getAction)
);}
static void RegisterLuaActionObject(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionObject,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionObject"
,"setName",static_cast<void(cocostudio::ActionObject::*)(const char*)>(&cocostudio::ActionObject::setName)
,"getName",static_cast<const char*(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getName)
,"setLoop",static_cast<void(cocostudio::ActionObject::*)(bool)>(&cocostudio::ActionObject::setLoop)
,"getLoop",static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getLoop)
,"setUnitTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setUnitTime)
,"getUnitTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getUnitTime)
,"setCurrentTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setCurrentTime)
,"getCurrentTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getCurrentTime)
,"getTotalTime",static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getTotalTime)
,"isPlaying",static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::isPlaying)
,"play",sol::overload(static_cast<void(cocostudio::ActionObject::*)(cocos2d::CallFunc*)>(&cocostudio::ActionObject::play),static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::play))
,"pause",static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::pause)
,"stop",static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::stop)
,"addActionNode",static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::addActionNode)
,"removeActionNode",static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::removeActionNode)
,"updateToFrameByTime",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::updateToFrameByTime)
,"simulationActionUpdate",static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::simulationActionUpdate)
);}
static void RegisterLuaActionManagerEx(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ActionManagerEx,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionManagerEx"
,"getActionByName",static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::getActionByName)
,"playActionByName",sol::overload(static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*,cocos2d::CallFunc*)>(&cocostudio::ActionManagerEx::playActionByName),static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::playActionByName))
,"stopActionByName",static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::stopActionByName)
,"releaseActions",static_cast<void(cocostudio::ActionManagerEx::*)()>(&cocostudio::ActionManagerEx::releaseActions)
,"getStudioVersionNumber",static_cast<int(cocostudio::ActionManagerEx::*)()const>(&cocostudio::ActionManagerEx::getStudioVersionNumber)
,"getInstance",static_cast<cocostudio::ActionManagerEx*(*)()>(&cocostudio::ActionManagerEx::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocostudio::ActionManagerEx::destroyInstance)
);}
static void RegisterLuaBaseData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("ccs","BaseData"
,"setColor",static_cast<void(cocostudio::BaseData::*)(const cocos2d::Color4B&)>(&cocostudio::BaseData::setColor)
,"getColor",static_cast<cocos2d::Color4B(cocostudio::BaseData::*)()>(&cocostudio::BaseData::getColor)
,"new",static_cast<cocostudio::BaseData*(*)()>(&cocostudio::BaseData::create)
);}
static void RegisterLuaDisplayData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","DisplayData"
,"copy",static_cast<void(cocostudio::DisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::DisplayData::copy)
,"new",static_cast<cocostudio::DisplayData*(*)()>(&cocostudio::DisplayData::create)
,"changeDisplayToTexture",static_cast<std::string(*)(const std::string&)>(&cocostudio::DisplayData::changeDisplayToTexture)
);}
static void RegisterLuaSpriteDisplayData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::SpriteDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","SpriteDisplayData"
,"copy",static_cast<void(cocostudio::SpriteDisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::SpriteDisplayData::copy)
,"new",static_cast<cocostudio::SpriteDisplayData*(*)()>(&cocostudio::SpriteDisplayData::create)
);}
static void RegisterLuaArmatureDisplayData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ArmatureDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureDisplayData"
,"new",static_cast<cocostudio::ArmatureDisplayData*(*)()>(&cocostudio::ArmatureDisplayData::create)
);}
static void RegisterLuaParticleDisplayData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ParticleDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ParticleDisplayData"
,"new",static_cast<cocostudio::ParticleDisplayData*(*)()>(&cocostudio::ParticleDisplayData::create)
);}
static void RegisterLuaBoneData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::BoneData,cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("ccs","BoneData"
,"init",static_cast<bool(cocostudio::BoneData::*)()>(&cocostudio::BoneData::init)
,"addDisplayData",static_cast<void(cocostudio::BoneData::*)(cocostudio::DisplayData*)>(&cocostudio::BoneData::addDisplayData)
,"getDisplayData",static_cast<cocostudio::DisplayData*(cocostudio::BoneData::*)(int)>(&cocostudio::BoneData::getDisplayData)
,"new",static_cast<cocostudio::BoneData*(*)()>(&cocostudio::BoneData::create)
);}
static void RegisterLuaArmatureData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ArmatureData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureData"
,"init",static_cast<bool(cocostudio::ArmatureData::*)()>(&cocostudio::ArmatureData::init)
,"addBoneData",static_cast<void(cocostudio::ArmatureData::*)(cocostudio::BoneData*)>(&cocostudio::ArmatureData::addBoneData)
,"getBoneData",static_cast<cocostudio::BoneData*(cocostudio::ArmatureData::*)(const std::string&)>(&cocostudio::ArmatureData::getBoneData)
,"new",static_cast<cocostudio::ArmatureData*(*)()>(&cocostudio::ArmatureData::create)
);}
static void RegisterLuaFrameData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::FrameData,cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("ccs","FrameData"
,"copy",static_cast<void(cocostudio::FrameData::*)(const cocostudio::BaseData*)>(&cocostudio::FrameData::copy)
,"new",static_cast<cocostudio::FrameData*(*)()>(&cocostudio::FrameData::create)
);}
static void RegisterLuaMovementBoneData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::MovementBoneData,cocos2d::Ref,cocos2d::LuaObject>("ccs","MovementBoneData"
,"init",static_cast<bool(cocostudio::MovementBoneData::*)()>(&cocostudio::MovementBoneData::init)
,"addFrameData",static_cast<void(cocostudio::MovementBoneData::*)(cocostudio::FrameData*)>(&cocostudio::MovementBoneData::addFrameData)
,"getFrameData",static_cast<cocostudio::FrameData*(cocostudio::MovementBoneData::*)(int)>(&cocostudio::MovementBoneData::getFrameData)
,"new",static_cast<cocostudio::MovementBoneData*(*)()>(&cocostudio::MovementBoneData::create)
);}
static void RegisterLuaMovementData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::MovementData,cocos2d::Ref,cocos2d::LuaObject>("ccs","MovementData"
,"addMovementBoneData",static_cast<void(cocostudio::MovementData::*)(cocostudio::MovementBoneData*)>(&cocostudio::MovementData::addMovementBoneData)
,"getMovementBoneData",static_cast<cocostudio::MovementBoneData*(cocostudio::MovementData::*)(const std::string&)>(&cocostudio::MovementData::getMovementBoneData)
,"new",static_cast<cocostudio::MovementData*(*)()>(&cocostudio::MovementData::create)
);}
static void RegisterLuaAnimationData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::AnimationData,cocos2d::Ref,cocos2d::LuaObject>("ccs","AnimationData"
,"addMovement",static_cast<void(cocostudio::AnimationData::*)(cocostudio::MovementData*)>(&cocostudio::AnimationData::addMovement)
,"getMovement",static_cast<cocostudio::MovementData*(cocostudio::AnimationData::*)(const std::string&)>(&cocostudio::AnimationData::getMovement)
,"getMovementCount",static_cast<ssize_t(cocostudio::AnimationData::*)()>(&cocostudio::AnimationData::getMovementCount)
,"new",static_cast<cocostudio::AnimationData*(*)()>(&cocostudio::AnimationData::create)
);}
static void RegisterLuaContourData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ContourData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ContourData"
,"init",static_cast<bool(cocostudio::ContourData::*)()>(&cocostudio::ContourData::init)
,"addVertex",static_cast<void(cocostudio::ContourData::*)(cocos2d::Vec2&)>(&cocostudio::ContourData::addVertex)
,"new",static_cast<cocostudio::ContourData*(*)()>(&cocostudio::ContourData::create)
);}
static void RegisterLuaTextureData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::TextureData,cocos2d::Ref,cocos2d::LuaObject>("ccs","TextureData"
,"init",static_cast<bool(cocostudio::TextureData::*)()>(&cocostudio::TextureData::init)
,"addContourData",static_cast<void(cocostudio::TextureData::*)(cocostudio::ContourData*)>(&cocostudio::TextureData::addContourData)
,"getContourData",static_cast<cocostudio::ContourData*(cocostudio::TextureData::*)(int)>(&cocostudio::TextureData::getContourData)
,"new",static_cast<cocostudio::TextureData*(*)()>(&cocostudio::TextureData::create)
);}
static void RegisterLuaTween(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::Tween,cocostudio::ProcessBase,cocos2d::Ref,cocos2d::LuaObject>("ccs","Tween"
,"init",static_cast<bool(cocostudio::Tween::*)(cocostudio::Bone*)>(&cocostudio::Tween::init)
,"play",static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*,int,int,int,int)>(&cocostudio::Tween::play)
,"setAnimation",static_cast<void(cocostudio::Tween::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Tween::setAnimation)
,"getAnimation",static_cast<cocostudio::ArmatureAnimation*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getAnimation)
,"gotoAndPlay",static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPlay)
,"gotoAndPause",static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPause)
,"new",static_cast<cocostudio::Tween*(*)(cocostudio::Bone*)>(&cocostudio::Tween::create)
);}
static void RegisterLuaDisplayManager(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::DisplayManager,cocos2d::Ref,cocos2d::LuaObject>("ccs","DisplayManager"
,"init",static_cast<bool(cocostudio::DisplayManager::*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::init)
,"addDisplay",sol::overload(static_cast<void(cocostudio::DisplayManager::*)(cocos2d::Node*,int)>(&cocostudio::DisplayManager::addDisplay),static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DisplayData*,int)>(&cocostudio::DisplayManager::addDisplay))
,"removeDisplay",static_cast<void(cocostudio::DisplayManager::*)(int)>(&cocostudio::DisplayManager::removeDisplay)
,"getDecorativeDisplayList",static_cast<const cocos2d::Vector<cocostudio::DecorativeDisplay *>&(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDecorativeDisplayList)
,"changeDisplayWithIndex",static_cast<void(cocostudio::DisplayManager::*)(int,bool)>(&cocostudio::DisplayManager::changeDisplayWithIndex)
,"changeDisplayWithName",static_cast<void(cocostudio::DisplayManager::*)(const std::string&,bool)>(&cocostudio::DisplayManager::changeDisplayWithName)
,"getDisplayRenderNode",static_cast<cocos2d::Node*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNode)
,"getDisplayRenderNodeType",static_cast<cocostudio::DisplayType(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNodeType)
,"getCurrentDisplayIndex",static_cast<int(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDisplayIndex)
,"setVisible",static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setVisible)
,"isVisible",static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isVisible)
,"getContentSize",static_cast<cocos2d::Size(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getContentSize)
,"getBoundingBox",static_cast<cocos2d::Rect(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getBoundingBox)
,"getAnchorPoint",static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPoint)
,"getAnchorPointInPoints",static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPointInPoints)
,"containPoint",sol::overload(static_cast<bool(cocostudio::DisplayManager::*)(float,float)>(&cocostudio::DisplayManager::containPoint),static_cast<bool(cocostudio::DisplayManager::*)(cocos2d::Vec2&)>(&cocostudio::DisplayManager::containPoint))
,"setForceChangeDisplay",static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setForceChangeDisplay)
,"isForceChangeDisplay",static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isForceChangeDisplay)
,"new",static_cast<cocostudio::DisplayManager*(*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::create)
);}
static void RegisterLuaBone(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::Bone,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","Bone"
,"init",sol::overload(static_cast<bool(cocostudio::Bone::*)(const std::string&)>(&cocostudio::Bone::init),static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::init))
,"addDisplay",sol::overload(static_cast<void(cocostudio::Bone::*)(cocos2d::Node*,int)>(&cocostudio::Bone::addDisplay),static_cast<void(cocostudio::Bone::*)(cocostudio::DisplayData*,int)>(&cocostudio::Bone::addDisplay))
,"removeDisplay",static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::removeDisplay)
,"changeDisplayWithIndex",static_cast<void(cocostudio::Bone::*)(int,bool)>(&cocostudio::Bone::changeDisplayWithIndex)
,"changeDisplayWithName",static_cast<void(cocostudio::Bone::*)(const std::string&,bool)>(&cocostudio::Bone::changeDisplayWithName)
,"addChildBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::addChildBone)
,"setParentBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::setParentBone)
,"getParentBone",static_cast<cocostudio::Bone*(cocostudio::Bone::*)()>(&cocostudio::Bone::getParentBone)
,"removeFromParent",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::removeFromParent)
,"removeChildBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*,bool)>(&cocostudio::Bone::removeChildBone)
,"update",static_cast<void(cocostudio::Bone::*)(float)>(&cocostudio::Bone::update)
,"updateDisplayedColor",static_cast<void(cocostudio::Bone::*)(const cocos2d::Color3B&)>(&cocostudio::Bone::updateDisplayedColor)
,"updateDisplayedOpacity",static_cast<void(cocostudio::Bone::*)(uint8_t)>(&cocostudio::Bone::updateDisplayedOpacity)
,"updateColor",static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateColor)
,"updateZOrder",static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateZOrder)
,"setLocalZOrder",static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::setLocalZOrder)
,"getTween",static_cast<cocostudio::Tween*(cocostudio::Bone::*)()>(&cocostudio::Bone::getTween)
,"setTransformDirty",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setTransformDirty)
,"isTransformDirty",static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isTransformDirty)
,"getNodeToArmatureTransform",static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToArmatureTransform)
,"getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToWorldTransform)
,"getDisplayRenderNode",static_cast<cocos2d::Node*(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNode)
,"getDisplayRenderNodeType",static_cast<cocostudio::DisplayType(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNodeType)
,"getColliderDetector",static_cast<cocostudio::ColliderDetector*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getColliderDetector)
,"setBoneData",static_cast<void(cocostudio::Bone::*)(cocostudio::BoneData*)>(&cocostudio::Bone::setBoneData)
,"getBoneData",static_cast<cocostudio::BoneData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getBoneData)
,"setArmature",static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setArmature)
,"getArmature",static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getArmature)
,"setChildArmature",static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setChildArmature)
,"getChildArmature",static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getChildArmature)
,"getDisplayManager",static_cast<cocostudio::DisplayManager*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getDisplayManager)
,"isIgnoreMovementBoneData",static_cast<bool(cocostudio::Bone::*)()const>(&cocostudio::Bone::isIgnoreMovementBoneData)
,"setBlendFunc",static_cast<void(cocostudio::Bone::*)(const cocos2d::BlendFunc&)>(&cocostudio::Bone::setBlendFunc)
,"getBlendFunc",static_cast<cocos2d::BlendFunc(cocostudio::Bone::*)()>(&cocostudio::Bone::getBlendFunc)
,"setBlendDirty",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setBlendDirty)
,"isBlendDirty",static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isBlendDirty)
,"getTweenData",static_cast<cocostudio::FrameData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getTweenData)
,"getWorldInfo",static_cast<cocostudio::BaseData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getWorldInfo)
,"new",sol::overload(static_cast<cocostudio::Bone*(*)(const std::string&)>(&cocostudio::Bone::create),static_cast<cocostudio::Bone*(*)()>(&cocostudio::Bone::create))
);}
static void RegisterLuaBatchNode(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::BatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","BatchNode"
,"init",static_cast<bool(cocostudio::BatchNode::*)()>(&cocostudio::BatchNode::init)
,"addChild",sol::overload(static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::BatchNode::addChild),static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,int)>(&cocostudio::BatchNode::addChild))
,"removeChild",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,bool)>(&cocostudio::BatchNode::removeChild)
,"draw",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::BatchNode::draw)
,"new",static_cast<cocostudio::BatchNode*(*)()>(&cocostudio::BatchNode::create)
);}
static void RegisterLuaArmatureAnimation(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ArmatureAnimation,cocostudio::ProcessBase,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureAnimation"
,"init",static_cast<bool(cocostudio::ArmatureAnimation::*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::init)
,"setSpeedScale",static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::setSpeedScale)
,"getSpeedScale",static_cast<float(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getSpeedScale)
,"play",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::string& arg0){return obj->play(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1){return obj->play(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1,int arg2){return obj->play(arg0,arg1,arg2);})
,"playWithIndex",sol::overload([](cocostudio::ArmatureAnimation* obj,int arg0){return obj->playWithIndex(arg0);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1){return obj->playWithIndex(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1,int arg2){return obj->playWithIndex(arg0,arg1,arg2);})
,"playWithNames",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0){return obj->playWithNames(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0,int arg1){return obj->playWithNames(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::string>& arg0,int arg1,bool arg2){return obj->playWithNames(arg0,arg1,arg2);})
,"playWithIndexes",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0){return obj->playWithIndexes(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0,int arg1){return obj->playWithIndexes(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int>& arg0,int arg1,bool arg2){return obj->playWithIndexes(arg0,arg1,arg2);})
,"gotoAndPlay",static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPlay)
,"gotoAndPause",static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPause)
,"pause",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::pause)
,"resume",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::resume)
,"stop",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::stop)
,"getMovementCount",static_cast<ssize_t(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getMovementCount)
,"update",static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::update)
,"getCurrentMovementID",static_cast<std::string(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getCurrentMovementID)
,"setAnimationData",static_cast<void(cocostudio::ArmatureAnimation::*)(cocostudio::AnimationData*)>(&cocostudio::ArmatureAnimation::setAnimationData)
,"getAnimationData",static_cast<cocostudio::AnimationData*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getAnimationData)
,"new",static_cast<cocostudio::ArmatureAnimation*(*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::create)
);}
static void RegisterLuaArmatureDataManager(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ArmatureDataManager,cocos2d::Ref,cocos2d::LuaObject>("ccs","ArmatureDataManager"
,"init",static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::init)
,"addArmatureData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1){return obj->addArmatureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1,const std::string& arg2){return obj->addArmatureData(arg0,arg1,arg2);})
,"getArmatureData",static_cast<cocostudio::ArmatureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getArmatureData)
,"removeArmatureData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureData)
,"addAnimationData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1){return obj->addAnimationData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1,const std::string& arg2){return obj->addAnimationData(arg0,arg1,arg2);})
,"getAnimationData",static_cast<cocostudio::AnimationData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getAnimationData)
,"removeAnimationData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeAnimationData)
,"addTextureData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1){return obj->addTextureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1,const std::string& arg2){return obj->addTextureData(arg0,arg1,arg2);})
,"getTextureData",static_cast<cocostudio::TextureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getTextureData)
,"removeTextureData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeTextureData)
,"addArmatureFileInfo",sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo))
,"addArmatureFileInfoAsync",sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync))
,"addSpriteFrameFromFile",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1){return obj->addSpriteFrameFromFile(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->addSpriteFrameFromFile(arg0,arg1,arg2);})
,"removeArmatureFileInfo",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureFileInfo)
,"isAutoLoadSpriteFile",static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::isAutoLoadSpriteFile)
,"getArmatureDatas",static_cast<const cocos2d::Map<std::string, cocostudio::ArmatureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getArmatureDatas)
,"getAnimationDatas",static_cast<const cocos2d::Map<std::string, cocostudio::AnimationData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getAnimationDatas)
,"getTextureDatas",static_cast<const cocos2d::Map<std::string, cocostudio::TextureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getTextureDatas)
,"addRelativeData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addRelativeData)
,"getRelativeData",static_cast<cocostudio::RelativeData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getRelativeData)
,"getInstance",static_cast<cocostudio::ArmatureDataManager*(*)()>(&cocostudio::ArmatureDataManager::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocostudio::ArmatureDataManager::destroyInstance)
);}
static void RegisterLuaArmature(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::Armature,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","Armature"
,"init",sol::overload(static_cast<bool(cocostudio::Armature::*)(const std::string&)>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)()>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::init))
,"addBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::addBone)
,"getBone",static_cast<cocostudio::Bone*(cocostudio::Armature::*)(const std::string&)const>(&cocostudio::Armature::getBone)
,"changeBoneParent",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::changeBoneParent)
,"removeBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,bool)>(&cocostudio::Armature::removeBone)
,"getBoneDic",static_cast<const cocos2d::Map<std::string, cocostudio::Bone *>&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoneDic)
,"getBoundingBox",static_cast<cocos2d::Rect(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoundingBox)
,"getBoneAtPoint",static_cast<cocostudio::Bone*(cocostudio::Armature::*)(float,float)const>(&cocostudio::Armature::getBoneAtPoint)
,"draw",static_cast<void(cocostudio::Armature::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Armature::draw)
,"update",static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::update)
,"getNodeToParentTransform",static_cast<const cocos2d::Mat4&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getNodeToParentTransform)
,"setBlendFunc",static_cast<void(cocostudio::Armature::*)(const cocos2d::BlendFunc&)>(&cocostudio::Armature::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBlendFunc)
,"updateOffsetPoint",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::updateOffsetPoint)
,"setAnchorPoint",static_cast<void(cocostudio::Armature::*)(const cocos2d::Vec2&)>(&cocostudio::Armature::setAnchorPoint)
,"getAnchorPointInPoints",static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnchorPointInPoints)
,"getOffsetPoints",static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getOffsetPoints)
,"setAnimation",static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Armature::setAnimation)
,"getAnimation",static_cast<cocostudio::ArmatureAnimation*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnimation)
,"getArmatureTransformDirty",static_cast<bool(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureTransformDirty)
,"setArmatureData",static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureData*)>(&cocostudio::Armature::setArmatureData)
,"getArmatureData",static_cast<cocostudio::ArmatureData*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureData)
,"setParentBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*)>(&cocostudio::Armature::setParentBone)
,"getParentBone",static_cast<cocostudio::Bone*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getParentBone)
,"setVersion",static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::setVersion)
,"getVersion",static_cast<float(cocostudio::Armature::*)()const>(&cocostudio::Armature::getVersion)
,"setBatchNode",static_cast<void(cocostudio::Armature::*)(cocostudio::BatchNode*)>(&cocostudio::Armature::setBatchNode)
,"getBatchNode",static_cast<cocostudio::BatchNode*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBatchNode)
,"new",sol::overload(static_cast<cocostudio::Armature*(*)(const std::string&)>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)()>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::create))
);}
static void RegisterLuaSkin(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::Skin,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("ccs","Skin"
,"initWithSpriteFrameName",static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithSpriteFrameName)
,"initWithFile",static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithFile)
,"updateArmatureTransform",static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateArmatureTransform)
,"updateTransform",static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateTransform)
,"getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransform)
,"getNodeToWorldTransformAR",static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransformAR)
,"draw",static_cast<void(cocostudio::Skin::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Skin::draw)
,"setBone",static_cast<void(cocostudio::Skin::*)(cocostudio::Bone*)>(&cocostudio::Skin::setBone)
,"getBone",static_cast<cocostudio::Bone*(cocostudio::Skin::*)()const>(&cocostudio::Skin::getBone)
,"getDisplayName",static_cast<const std::string&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getDisplayName)
,"new",sol::overload(static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::create),static_cast<cocostudio::Skin*(*)()>(&cocostudio::Skin::create))
,"createWithSpriteFrameName",static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::createWithSpriteFrameName)
);}
static void RegisterLuaComAttribute(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ComAttribute,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComAttribute"
,"init",static_cast<bool(cocostudio::ComAttribute::*)()>(&cocostudio::ComAttribute::init)
,"serialize",static_cast<bool(cocostudio::ComAttribute::*)(void*)>(&cocostudio::ComAttribute::serialize)
,"setInt",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,int)>(&cocostudio::ComAttribute::setInt)
,"setFloat",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,float)>(&cocostudio::ComAttribute::setFloat)
,"setBool",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,bool)>(&cocostudio::ComAttribute::setBool)
,"setString",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,const std::string&)>(&cocostudio::ComAttribute::setString)
,"getInt",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getInt(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,int arg1){return obj->getInt(arg0,arg1);})
,"getFloat",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getFloat(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,float arg1){return obj->getFloat(arg0,arg1);})
,"getBool",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getBool(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,bool arg1){return obj->getBool(arg0,arg1);})
,"getString",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getString(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,const std::string& arg1){return obj->getString(arg0,arg1);})
,"parse",static_cast<bool(cocostudio::ComAttribute::*)(const std::string&)>(&cocostudio::ComAttribute::parse)
,"createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAttribute::createInstance)
,"new",static_cast<cocostudio::ComAttribute*(*)()>(&cocostudio::ComAttribute::create)
);}
static void RegisterLuaComAudio(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ComAudio,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject,cocos2d::PlayableProtocol>("ccs","ComAudio"
,"init",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::init)
,"onAdd",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onAdd)
,"onRemove",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onRemove)
,"serialize",static_cast<bool(cocostudio::ComAudio::*)(void*)>(&cocostudio::ComAudio::serialize)
,"endToLua",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::end)
,"preloadBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadBackgroundMusic)
,"playBackgroundMusic",sol::overload(static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playBackgroundMusic))
,"stopBackgroundMusic",sol::overload(static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::stopBackgroundMusic))
,"pauseBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseBackgroundMusic)
,"resumeBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeBackgroundMusic)
,"rewindBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::rewindBackgroundMusic)
,"willPlayBackgroundMusic",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::willPlayBackgroundMusic)
,"isBackgroundMusicPlaying",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isBackgroundMusicPlaying)
,"getBackgroundMusicVolume",static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getBackgroundMusicVolume)
,"setBackgroundMusicVolume",static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setBackgroundMusicVolume)
,"getEffectsVolume",static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getEffectsVolume)
,"setEffectsVolume",static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setEffectsVolume)
,"playEffect",sol::overload(static_cast<unsigned int(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playEffect))
,"pauseEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::pauseEffect)
,"pauseAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseAllEffects)
,"resumeEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::resumeEffect)
,"resumeAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeAllEffects)
,"stopEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::stopEffect)
,"stopAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopAllEffects)
,"preloadEffect",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadEffect)
,"unloadEffect",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::unloadEffect)
,"setFile",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::setFile)
,"getFile",static_cast<const char*(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getFile)
,"setLoop",static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::setLoop)
,"isLoop",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isLoop)
,"start",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::start)
,"stop",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stop)
,"createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAudio::createInstance)
,"new",static_cast<cocostudio::ComAudio*(*)()>(&cocostudio::ComAudio::create)
);}
static void RegisterLuaComController(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ComController,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject,cocostudio::InputDelegate>("ccs","ComController"
,"init",static_cast<bool(cocostudio::ComController::*)()>(&cocostudio::ComController::init)
,"onAdd",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onAdd)
,"onRemove",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onRemove)
,"update",static_cast<void(cocostudio::ComController::*)(float)>(&cocostudio::ComController::update)
,"createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComController::createInstance)
,"new",static_cast<cocostudio::ComController*(*)()>(&cocostudio::ComController::create)
);}
static void RegisterLuaComRender(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ComRender,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComRender"
,"onAdd",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onAdd)
,"onRemove",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onRemove)
,"serialize",static_cast<bool(cocostudio::ComRender::*)(void*)>(&cocostudio::ComRender::serialize)
,"getNode",static_cast<cocos2d::Node*(cocostudio::ComRender::*)()>(&cocostudio::ComRender::getNode)
,"setNode",static_cast<void(cocostudio::ComRender::*)(cocos2d::Node*)>(&cocostudio::ComRender::setNode)
,"createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComRender::createInstance)
,"new",sol::overload(static_cast<cocostudio::ComRender*(*)(cocos2d::Node*,const char*)>(&cocostudio::ComRender::create),static_cast<cocostudio::ComRender*(*)()>(&cocostudio::ComRender::create))
);}
static void RegisterLuaGUIReader(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::GUIReader,cocos2d::Ref,cocos2d::LuaObject>("ccs","GUIReader"
,"widgetFromJsonFile",static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromJsonFile)
,"widgetFromBinaryFile",static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromBinaryFile)
,"getVersionInteger",static_cast<int(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::getVersionInteger)
,"setFilePath",static_cast<void(cocostudio::GUIReader::*)(const std::string&)>(&cocostudio::GUIReader::setFilePath)
,"getFilePath",static_cast<const std::string&(cocostudio::GUIReader::*)()const>(&cocostudio::GUIReader::getFilePath)
,"getInstance",static_cast<cocostudio::GUIReader*(*)()>(&cocostudio::GUIReader::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocostudio::GUIReader::destroyInstance)
);}
static void RegisterLuaSceneReader(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::SceneReader>("ccs","SceneReader"
,"createNodeWithSceneFile",sol::overload([](cocostudio::SceneReader* obj,const std::string& arg0){return obj->createNodeWithSceneFile(arg0);},[](cocostudio::SceneReader* obj,const std::string& arg0,cocostudio::SceneReader::AttachComponentType arg1){return obj->createNodeWithSceneFile(arg0,arg1);})
,"setTarget",static_cast<void(cocostudio::SceneReader::*)(const std::function<void (cocos2d::Ref *, void *)>&)>(&cocostudio::SceneReader::setTarget)
,"getNodeByTag",static_cast<cocos2d::Node*(cocostudio::SceneReader::*)(int)>(&cocostudio::SceneReader::getNodeByTag)
,"getAttachComponentType",static_cast<cocostudio::SceneReader::AttachComponentType(cocostudio::SceneReader::*)()>(&cocostudio::SceneReader::getAttachComponentType)
,"getInstance",static_cast<cocostudio::SceneReader*(*)()>(&cocostudio::SceneReader::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocostudio::SceneReader::destroyInstance)
,"sceneReaderVersion",static_cast<const char*(*)()>(&cocostudio::SceneReader::sceneReaderVersion)
);}
static void RegisterLuaActionTimelineCache(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ActionTimelineCache>("ccs","ActionTimelineCache"
,"purge",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::purge)
,"init",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::init)
,"removeAction",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::removeAction)
,"createActionFromJson",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromJson)
,"createActionFromContent",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromContent)
,"loadAnimationActionWithFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFile)
,"loadAnimationActionWithContent",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithContent)
,"createActionWithFlatBuffersFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersFile)
,"loadAnimationActionWithFlatBuffersFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFlatBuffersFile)
,"createActionWithFlatBuffersForSimulator",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersForSimulator)
,"destroyInstance",static_cast<void(*)()>(&cocostudio::timeline::ActionTimelineCache::destroyInstance)
,"createAction",static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createAction)
);}
static void RegisterLuaFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","Frame"
,"setFrameIndex",static_cast<void(cocostudio::timeline::Frame::*)(unsigned int)>(&cocostudio::timeline::Frame::setFrameIndex)
,"getFrameIndex",static_cast<unsigned int(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getFrameIndex)
,"setTimeline",static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::Frame::setTimeline)
,"getTimeline",static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTimeline)
,"setNode",static_cast<void(cocostudio::timeline::Frame::*)(cocos2d::Node*)>(&cocostudio::timeline::Frame::setNode)
,"getNode",static_cast<cocos2d::Node*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getNode)
,"setTween",static_cast<void(cocostudio::timeline::Frame::*)(bool)>(&cocostudio::timeline::Frame::setTween)
,"isTween",static_cast<bool(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::isTween)
,"setTweenType",static_cast<void(cocostudio::timeline::Frame::*)(const cocos2d::tweenfunc::TweenType&)>(&cocostudio::timeline::Frame::setTweenType)
,"getTweenType",static_cast<cocos2d::tweenfunc::TweenType(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTweenType)
,"setEasingParams",static_cast<void(cocostudio::timeline::Frame::*)(const std::vector<float>&)>(&cocostudio::timeline::Frame::setEasingParams)
,"getEasingParams",static_cast<const std::vector<float>&(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getEasingParams)
,"isEnterWhenPassed",static_cast<bool(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::isEnterWhenPassed)
,"apply",static_cast<void(cocostudio::timeline::Frame::*)(float)>(&cocostudio::timeline::Frame::apply)
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::clone)
);}
static void RegisterLuaVisibleFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::VisibleFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","VisibleFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::VisibleFrame::*)()>(&cocostudio::timeline::VisibleFrame::clone)
,"setVisible",static_cast<void(cocostudio::timeline::VisibleFrame::*)(bool)>(&cocostudio::timeline::VisibleFrame::setVisible)
,"isVisible",static_cast<bool(cocostudio::timeline::VisibleFrame::*)()const>(&cocostudio::timeline::VisibleFrame::isVisible)
,"new",static_cast<cocostudio::timeline::VisibleFrame*(*)()>(&cocostudio::timeline::VisibleFrame::create)
);}
static void RegisterLuaTextureFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::TextureFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","TextureFrame"
,"setNode",static_cast<void(cocostudio::timeline::TextureFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::TextureFrame::setNode)
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::TextureFrame::*)()>(&cocostudio::timeline::TextureFrame::clone)
,"setTextureName",static_cast<void(cocostudio::timeline::TextureFrame::*)(std::string)>(&cocostudio::timeline::TextureFrame::setTextureName)
,"getTextureName",static_cast<std::string(cocostudio::timeline::TextureFrame::*)()const>(&cocostudio::timeline::TextureFrame::getTextureName)
,"new",static_cast<cocostudio::timeline::TextureFrame*(*)()>(&cocostudio::timeline::TextureFrame::create)
);}
static void RegisterLuaRotationFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::RotationFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","RotationFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationFrame::*)()>(&cocostudio::timeline::RotationFrame::clone)
,"setRotation",static_cast<void(cocostudio::timeline::RotationFrame::*)(float)>(&cocostudio::timeline::RotationFrame::setRotation)
,"getRotation",static_cast<float(cocostudio::timeline::RotationFrame::*)()const>(&cocostudio::timeline::RotationFrame::getRotation)
,"new",static_cast<cocostudio::timeline::RotationFrame*(*)()>(&cocostudio::timeline::RotationFrame::create)
);}
static void RegisterLuaSkewFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","SkewFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::SkewFrame::*)()>(&cocostudio::timeline::SkewFrame::clone)
,"setSkewX",static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewX)
,"getSkewX",static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewX)
,"setSkewY",static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewY)
,"getSkewY",static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewY)
,"new",static_cast<cocostudio::timeline::SkewFrame*(*)()>(&cocostudio::timeline::SkewFrame::create)
);}
static void RegisterLuaRotationSkewFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::RotationSkewFrame,cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","RotationSkewFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationSkewFrame::*)()>(&cocostudio::timeline::RotationSkewFrame::clone)
,"new",static_cast<cocostudio::timeline::RotationSkewFrame*(*)()>(&cocostudio::timeline::RotationSkewFrame::create)
);}
static void RegisterLuaPositionFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::PositionFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","PositionFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PositionFrame::*)()>(&cocostudio::timeline::PositionFrame::clone)
,"setPosition",static_cast<void(cocostudio::timeline::PositionFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::PositionFrame::setPosition)
,"getPosition",static_cast<cocos2d::Point(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getPosition)
,"setX",static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setX)
,"setY",static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setY)
,"getX",static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getX)
,"getY",static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getY)
,"new",static_cast<cocostudio::timeline::PositionFrame*(*)()>(&cocostudio::timeline::PositionFrame::create)
);}
static void RegisterLuaScaleFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ScaleFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ScaleFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ScaleFrame::*)()>(&cocostudio::timeline::ScaleFrame::clone)
,"setScale",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScale)
,"setScaleX",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleX)
,"getScaleX",static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleX)
,"setScaleY",static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleY)
,"getScaleY",static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleY)
,"new",static_cast<cocostudio::timeline::ScaleFrame*(*)()>(&cocostudio::timeline::ScaleFrame::create)
);}
static void RegisterLuaAnchorPointFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::AnchorPointFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","AnchorPointFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AnchorPointFrame::*)()>(&cocostudio::timeline::AnchorPointFrame::clone)
,"setAnchorPoint",static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::AnchorPointFrame::setAnchorPoint)
,"getAnchorPoint",static_cast<cocos2d::Point(cocostudio::timeline::AnchorPointFrame::*)()const>(&cocostudio::timeline::AnchorPointFrame::getAnchorPoint)
,"new",static_cast<cocostudio::timeline::AnchorPointFrame*(*)()>(&cocostudio::timeline::AnchorPointFrame::create)
);}
static void RegisterLuaInnerActionFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::InnerActionFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","InnerActionFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::InnerActionFrame::*)()>(&cocostudio::timeline::InnerActionFrame::clone)
,"setInnerActionType",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::InnerActionType)>(&cocostudio::timeline::InnerActionFrame::setInnerActionType)
,"getInnerActionType",static_cast<cocostudio::timeline::InnerActionType(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getInnerActionType)
,"setEnterWithName",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(bool)>(&cocostudio::timeline::InnerActionFrame::setEnterWithName)
,"setStartFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setStartFrameIndex)
,"getStartFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getStartFrameIndex)
,"setEndFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setEndFrameIndex)
,"getEndFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getEndFrameIndex)
,"setAnimationName",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(const std::string&)>(&cocostudio::timeline::InnerActionFrame::setAnimationName)
,"setSingleFrameIndex",static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setSingleFrameIndex)
,"getSingleFrameIndex",static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getSingleFrameIndex)
,"new",static_cast<cocostudio::timeline::InnerActionFrame*(*)()>(&cocostudio::timeline::InnerActionFrame::create)
);}
static void RegisterLuaColorFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ColorFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ColorFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ColorFrame::*)()>(&cocostudio::timeline::ColorFrame::clone)
,"setColor",static_cast<void(cocostudio::timeline::ColorFrame::*)(const cocos2d::Color3B&)>(&cocostudio::timeline::ColorFrame::setColor)
,"getColor",static_cast<cocos2d::Color3B(cocostudio::timeline::ColorFrame::*)()const>(&cocostudio::timeline::ColorFrame::getColor)
,"new",static_cast<cocostudio::timeline::ColorFrame*(*)()>(&cocostudio::timeline::ColorFrame::create)
);}
static void RegisterLuaAlphaFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::AlphaFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","AlphaFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::AlphaFrame::*)()>(&cocostudio::timeline::AlphaFrame::clone)
,"setAlpha",static_cast<void(cocostudio::timeline::AlphaFrame::*)(uint8_t)>(&cocostudio::timeline::AlphaFrame::setAlpha)
,"getAlpha",static_cast<uint8_t(cocostudio::timeline::AlphaFrame::*)()const>(&cocostudio::timeline::AlphaFrame::getAlpha)
,"new",static_cast<cocostudio::timeline::AlphaFrame*(*)()>(&cocostudio::timeline::AlphaFrame::create)
);}
static void RegisterLuaEventFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::EventFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","EventFrame"
,"init",static_cast<void(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::init)
,"setNode",static_cast<void(cocostudio::timeline::EventFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::EventFrame::setNode)
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::clone)
,"setEvent",static_cast<void(cocostudio::timeline::EventFrame::*)(std::string)>(&cocostudio::timeline::EventFrame::setEvent)
,"getEvent",static_cast<std::string(cocostudio::timeline::EventFrame::*)()const>(&cocostudio::timeline::EventFrame::getEvent)
,"new",static_cast<cocostudio::timeline::EventFrame*(*)()>(&cocostudio::timeline::EventFrame::create)
);}
static void RegisterLuaZOrderFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ZOrderFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","ZOrderFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ZOrderFrame::*)()>(&cocostudio::timeline::ZOrderFrame::clone)
,"setZOrder",static_cast<void(cocostudio::timeline::ZOrderFrame::*)(int)>(&cocostudio::timeline::ZOrderFrame::setZOrder)
,"getZOrder",static_cast<int(cocostudio::timeline::ZOrderFrame::*)()const>(&cocostudio::timeline::ZOrderFrame::getZOrder)
,"new",static_cast<cocostudio::timeline::ZOrderFrame*(*)()>(&cocostudio::timeline::ZOrderFrame::create)
);}
static void RegisterLuaBlendFuncFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::BlendFuncFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","BlendFuncFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::BlendFuncFrame::*)()>(&cocostudio::timeline::BlendFuncFrame::clone)
,"getBlendFunc",static_cast<cocos2d::BlendFunc(cocostudio::timeline::BlendFuncFrame::*)()const>(&cocostudio::timeline::BlendFuncFrame::getBlendFunc)
,"setBlendFunc",static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocos2d::BlendFunc)>(&cocostudio::timeline::BlendFuncFrame::setBlendFunc)
,"new",static_cast<cocostudio::timeline::BlendFuncFrame*(*)()>(&cocostudio::timeline::BlendFuncFrame::create)
);}
static void RegisterLuaPlayableFrame(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::PlayableFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","PlayableFrame"
,"clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PlayableFrame::*)()>(&cocostudio::timeline::PlayableFrame::clone)
,"getPlayableAct",static_cast<std::string(cocostudio::timeline::PlayableFrame::*)()const>(&cocostudio::timeline::PlayableFrame::getPlayableAct)
,"setPlayableAct",static_cast<void(cocostudio::timeline::PlayableFrame::*)(std::string)>(&cocostudio::timeline::PlayableFrame::setPlayableAct)
,"new",static_cast<cocostudio::timeline::PlayableFrame*(*)()>(&cocostudio::timeline::PlayableFrame::create)
);}
static void RegisterLuaTimeline(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::Timeline,cocos2d::Ref,cocos2d::LuaObject>("ccs","Timeline"
,"gotoFrame",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::gotoFrame)
,"stepToFrame",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::stepToFrame)
,"getFrames",static_cast<const cocos2d::Vector<cocostudio::timeline::Frame *>&(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getFrames)
,"addFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::addFrame)
,"insertFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Timeline::insertFrame)
,"removeFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::removeFrame)
,"setActionTag",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::setActionTag)
,"getActionTag",static_cast<int(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTag)
,"setNode",static_cast<void(cocostudio::timeline::Timeline::*)(cocos2d::Node*)>(&cocostudio::timeline::Timeline::setNode)
,"getNode",static_cast<cocos2d::Node*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getNode)
,"setActionTimeline",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::Timeline::setActionTimeline)
,"getActionTimeline",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTimeline)
,"clone",static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Timeline::*)()>(&cocostudio::timeline::Timeline::clone)
,"new",static_cast<cocostudio::timeline::Timeline*(*)()>(&cocostudio::timeline::Timeline::create)
);}
static void RegisterLuaActionTimelineData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ActionTimelineData,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionTimelineData"
,"setActionTag",static_cast<void(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::setActionTag)
,"getActionTag",static_cast<int(cocostudio::timeline::ActionTimelineData::*)()const>(&cocostudio::timeline::ActionTimelineData::getActionTag)
,"init",static_cast<bool(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::init)
,"new",static_cast<cocostudio::timeline::ActionTimelineData*(*)(int)>(&cocostudio::timeline::ActionTimelineData::create)
);}
static void RegisterLuaActionTimeline(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ActionTimeline,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject,cocos2d::Clonable,cocos2d::PlayableProtocol>("ccs","ActionTimeline"
,"play",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string,bool)>(&cocostudio::timeline::ActionTimeline::play)
,"init",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::init)
,"gotoFrameAndPlay",sol::overload(static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay))
,"gotoFrameAndPause",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPause)
,"pause",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::pause)
,"resume",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::resume)
,"isPlaying",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isPlaying)
,"setTimeSpeed",static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::setTimeSpeed)
,"getTimeSpeed",static_cast<float(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimeSpeed)
,"setDuration",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setDuration)
,"getDuration",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getDuration)
,"getStartFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getStartFrame)
,"getEndFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getEndFrame)
,"setCurrentFrame",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setCurrentFrame)
,"getCurrentFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getCurrentFrame)
,"addTimeline",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::addTimeline)
,"removeTimeline",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::removeTimeline)
,"getTimelines",static_cast<const cocos2d::Vector<cocostudio::timeline::Timeline *>&(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimelines)
,"addAnimationInfo",static_cast<void(cocostudio::timeline::ActionTimeline::*)(const cocostudio::timeline::AnimationInfo&)>(&cocostudio::timeline::ActionTimeline::addAnimationInfo)
,"removeAnimationInfo",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string)>(&cocostudio::timeline::ActionTimeline::removeAnimationInfo)
,"IsAnimationInfoExists",static_cast<bool(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::IsAnimationInfoExists)
,"getAnimationInfo",static_cast<const cocostudio::timeline::AnimationInfo&(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::getAnimationInfo)
,"setAnimationEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(const std::string,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setAnimationEndCallFunc)
,"clearFrameEventCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEventCallFunc)
,"setLastFrameCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setLastFrameCallFunc)
,"clearLastFrameCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearLastFrameCallFunc)
,"addFrameEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::addFrameEndCallFunc)
,"removeFrameEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFunc)
,"removeFrameEndCallFuncs",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFuncs)
,"clearFrameEndCallFuncs",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEndCallFuncs)
,"clone",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::clone)
,"reverse",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::reverse)
,"step",static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::step)
,"startWithTarget",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimeline::startWithTarget)
,"isDone",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isDone)
,"start",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::start)
,"stop",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::stop)
,"new",static_cast<cocostudio::timeline::ActionTimeline*(*)()>(&cocostudio::timeline::ActionTimeline::create)
);}
static void RegisterLuaActionTimelineNode(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::ActionTimelineNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ccs","ActionTimelineNode"
,"init",sol::overload(static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::init),static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::init))
,"setRoot",static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimelineNode::setRoot)
,"getRoot",static_cast<cocos2d::Node*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getRoot)
,"setActionTimeline",static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::setActionTimeline)
,"getActionTimeline",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getActionTimeline)
,"new",static_cast<cocostudio::timeline::ActionTimelineNode*(*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::create)
);}
static void RegisterLuaBoneNode(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","BoneNode"
,"addChild",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,int)>(&cocostudio::timeline::BoneNode::addChild),static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::timeline::BoneNode::addChild))
,"removeChild",static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,bool)>(&cocostudio::timeline::BoneNode::removeChild)
,"getChildBones",sol::overload(static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getChildBones),static_cast<const cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getChildBones))
,"getRootSkeletonNode",static_cast<cocostudio::timeline::SkeletonNode*(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getRootSkeletonNode)
,"getAllSubBones",static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubBones)
,"addSkin",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool,bool)>(&cocostudio::timeline::BoneNode::addSkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::addSkin))
,"displaySkin",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&,bool)>(&cocostudio::timeline::BoneNode::displaySkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::displaySkin))
,"getVisibleSkins",static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkins)
,"getSkins",sol::overload(static_cast<cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getSkins),static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getSkins))
,"getAllSubSkins",static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubSkins)
,"setBlendFunc",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::BlendFunc&)>(&cocostudio::timeline::BoneNode::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBlendFunc)
,"setDebugDrawEnabled",static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setDebugDrawEnabled)
,"isDebugDrawEnabled",static_cast<bool(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::isDebugDrawEnabled)
,"setDebugDrawLength",static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawLength)
,"getDebugDrawLength",static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawLength)
,"setDebugDrawWidth",static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawWidth)
,"getDebugDrawWidth",static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawWidth)
,"setDebugDrawColor",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Color4F&)>(&cocostudio::timeline::BoneNode::setDebugDrawColor)
,"getDebugDrawColor",static_cast<cocos2d::Color4F(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawColor)
,"getBoundingBox",static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBoundingBox)
,"getVisibleSkinsRect",static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkinsRect)
,"draw",static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::timeline::BoneNode::draw)
,"setLocalZOrder",static_cast<void(cocostudio::timeline::BoneNode::*)(int)>(&cocostudio::timeline::BoneNode::setLocalZOrder)
,"setName",static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&)>(&cocostudio::timeline::BoneNode::setName)
,"setVisible",static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setVisible)
,"setContentSize",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Size&)>(&cocostudio::timeline::BoneNode::setContentSize)
,"setAnchorPoint",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Vec2&)>(&cocostudio::timeline::BoneNode::setAnchorPoint)
,"init",static_cast<bool(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::init)
,"new",sol::overload(static_cast<cocostudio::timeline::BoneNode*(*)(int)>(&cocostudio::timeline::BoneNode::create),static_cast<cocostudio::timeline::BoneNode*(*)()>(&cocostudio::timeline::BoneNode::create))
);}
static void RegisterLuaSkeletonNode(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::timeline::SkeletonNode,cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("ccs","SkeletonNode"
,"getBoneNode",static_cast<cocostudio::timeline::BoneNode*(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::getBoneNode)
,"getAllSubBonesMap",static_cast<const cocos2d::Map<std::string, cocostudio::timeline::BoneNode *>&(cocostudio::timeline::SkeletonNode::*)()const>(&cocostudio::timeline::SkeletonNode::getAllSubBonesMap)
,"changeSkins",sol::overload(static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::changeSkins),static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::map<std::string, std::string>&)>(&cocostudio::timeline::SkeletonNode::changeSkins))
,"addSkinGroup",static_cast<void(cocostudio::timeline::SkeletonNode::*)(std::string,std::map<std::string, std::string>)>(&cocostudio::timeline::SkeletonNode::addSkinGroup)
,"getBoundingBox",static_cast<cocos2d::Rect(cocostudio::timeline::SkeletonNode::*)()const>(&cocostudio::timeline::SkeletonNode::getBoundingBox)
,"init",static_cast<bool(cocostudio::timeline::SkeletonNode::*)()>(&cocostudio::timeline::SkeletonNode::init)
,"new",static_cast<cocostudio::timeline::SkeletonNode*(*)()>(&cocostudio::timeline::SkeletonNode::create)
);}
static void RegisterLuaComExtensionData(cocos2d::Lua& lua){
lua.NewUserType<cocostudio::ComExtensionData,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComExtensionData"
,"onAdd",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onAdd)
,"onRemove",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onRemove)
,"init",static_cast<bool(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::init)
,"setCustomProperty",static_cast<void(cocostudio::ComExtensionData::*)(const std::string&)>(&cocostudio::ComExtensionData::setCustomProperty)
,"getCustomProperty",static_cast<std::string(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getCustomProperty)
,"setActionTag",static_cast<void(cocostudio::ComExtensionData::*)(int)>(&cocostudio::ComExtensionData::setActionTag)
,"getActionTag",static_cast<int(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getActionTag)
,"createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComExtensionData::createInstance)
,"new",static_cast<cocostudio::ComExtensionData*(*)()>(&cocostudio::ComExtensionData::create)
);}
void RegisterLuaStudioAuto(cocos2d::Lua& lua) {
RegisterLuaActionFrame(lua);
RegisterLuaActionMoveFrame(lua);
RegisterLuaActionScaleFrame(lua);
RegisterLuaActionRotationFrame(lua);
RegisterLuaActionFadeFrame(lua);
RegisterLuaActionTintFrame(lua);
RegisterLuaActionObject(lua);
RegisterLuaActionManagerEx(lua);
RegisterLuaBaseData(lua);
RegisterLuaDisplayData(lua);
RegisterLuaSpriteDisplayData(lua);
RegisterLuaArmatureDisplayData(lua);
RegisterLuaParticleDisplayData(lua);
RegisterLuaBoneData(lua);
RegisterLuaArmatureData(lua);
RegisterLuaFrameData(lua);
RegisterLuaMovementBoneData(lua);
RegisterLuaMovementData(lua);
RegisterLuaAnimationData(lua);
RegisterLuaContourData(lua);
RegisterLuaTextureData(lua);
RegisterLuaTween(lua);
RegisterLuaDisplayManager(lua);
RegisterLuaBone(lua);
RegisterLuaBatchNode(lua);
RegisterLuaArmatureAnimation(lua);
RegisterLuaArmatureDataManager(lua);
RegisterLuaArmature(lua);
RegisterLuaSkin(lua);
RegisterLuaComAttribute(lua);
RegisterLuaComAudio(lua);
RegisterLuaComController(lua);
RegisterLuaComRender(lua);
RegisterLuaGUIReader(lua);
RegisterLuaSceneReader(lua);
RegisterLuaActionTimelineCache(lua);
RegisterLuaFrame(lua);
RegisterLuaVisibleFrame(lua);
RegisterLuaTextureFrame(lua);
RegisterLuaRotationFrame(lua);
RegisterLuaSkewFrame(lua);
RegisterLuaRotationSkewFrame(lua);
RegisterLuaPositionFrame(lua);
RegisterLuaScaleFrame(lua);
RegisterLuaAnchorPointFrame(lua);
RegisterLuaInnerActionFrame(lua);
RegisterLuaColorFrame(lua);
RegisterLuaAlphaFrame(lua);
RegisterLuaEventFrame(lua);
RegisterLuaZOrderFrame(lua);
RegisterLuaBlendFuncFrame(lua);
RegisterLuaPlayableFrame(lua);
RegisterLuaTimeline(lua);
RegisterLuaActionTimelineData(lua);
RegisterLuaActionTimeline(lua);
RegisterLuaActionTimelineNode(lua);
RegisterLuaBoneNode(lua);
RegisterLuaSkeletonNode(lua);
RegisterLuaComExtensionData(lua);
}
