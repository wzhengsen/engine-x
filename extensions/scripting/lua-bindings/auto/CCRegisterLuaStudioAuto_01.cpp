#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioSpriteDisplayDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::SpriteDisplayData>("ccs","SpriteDisplayData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::DisplayData,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::SpriteDisplayData*(*)()>(&cocostudio::SpriteDisplayData::create));
mt.set_function("Copy",static_cast<void(cocostudio::SpriteDisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::SpriteDisplayData::copy));
mt[sol::call_constructor]=sol::constructors<cocostudio::SpriteDisplayData()>();
mt["SkinData"]=&cocostudio::SpriteDisplayData::skinData;
}
void RegisterLuaStudioArmatureDisplayDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureDisplayData>("ccs","ArmatureDisplayData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::DisplayData,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ArmatureDisplayData*(*)()>(&cocostudio::ArmatureDisplayData::create));
mt[sol::call_constructor]=sol::constructors<cocostudio::ArmatureDisplayData()>();
}
void RegisterLuaStudioParticleDisplayDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ParticleDisplayData>("ccs","ParticleDisplayData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::DisplayData,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ParticleDisplayData*(*)()>(&cocostudio::ParticleDisplayData::create));
mt[sol::call_constructor]=sol::constructors<cocostudio::ParticleDisplayData()>();
}
void RegisterLuaStudioBoneDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BoneData>("ccs","BoneData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::BaseData,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::BoneData*(*)()>(&cocostudio::BoneData::create));
mt.set_function("Init",static_cast<bool(cocostudio::BoneData::*)()>(&cocostudio::BoneData::init));
mt.set_function("AddDisplayData",static_cast<void(cocostudio::BoneData::*)(cocostudio::DisplayData*)>(&cocostudio::BoneData::addDisplayData));
mt.set_function("GetDisplayData",static_cast<cocostudio::DisplayData*(cocostudio::BoneData::*)(int)>(&cocostudio::BoneData::getDisplayData));
mt[sol::call_constructor]=sol::constructors<cocostudio::BoneData()>();
mt["Name"]=&cocostudio::BoneData::name;
mt["ParentName"]=&cocostudio::BoneData::parentName;
mt["BoneDataTransform"]=&cocostudio::BoneData::boneDataTransform;
}
void RegisterLuaStudioArmatureDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureData>("ccs","ArmatureData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ArmatureData*(*)()>(&cocostudio::ArmatureData::create));
mt.set_function("Init",static_cast<bool(cocostudio::ArmatureData::*)()>(&cocostudio::ArmatureData::init));
mt.set_function("AddBoneData",static_cast<void(cocostudio::ArmatureData::*)(cocostudio::BoneData*)>(&cocostudio::ArmatureData::addBoneData));
mt.set_function("GetBoneData",static_cast<cocostudio::BoneData*(cocostudio::ArmatureData::*)(const std::string&)>(&cocostudio::ArmatureData::getBoneData));
mt[sol::call_constructor]=sol::constructors<cocostudio::ArmatureData()>();
mt["Name"]=&cocostudio::ArmatureData::name;
mt["DataVersion"]=&cocostudio::ArmatureData::dataVersion;
}
void RegisterLuaStudioFrameDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::FrameData>("ccs","FrameData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::BaseData,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::FrameData*(*)()>(&cocostudio::FrameData::create));
mt.set_function("Copy",static_cast<void(cocostudio::FrameData::*)(const cocostudio::BaseData*)>(&cocostudio::FrameData::copy));
mt[sol::call_constructor]=sol::constructors<cocostudio::FrameData()>();
mt["FrameID"]=&cocostudio::FrameData::frameID;
mt["Duration"]=&cocostudio::FrameData::duration;
mt["TweenEasing"]=&cocostudio::FrameData::tweenEasing;
mt["EasingParamNumber"]=&cocostudio::FrameData::easingParamNumber;
mt["EasingParams"]=&cocostudio::FrameData::easingParams;
mt["IsTween"]=&cocostudio::FrameData::isTween;
mt["DisplayIndex"]=&cocostudio::FrameData::displayIndex;
mt["BlendFunc"]=&cocostudio::FrameData::blendFunc;
mt["StrEvent"]=&cocostudio::FrameData::strEvent;
mt["StrMovement"]=&cocostudio::FrameData::strMovement;
mt["StrSound"]=&cocostudio::FrameData::strSound;
mt["StrSoundEffect"]=&cocostudio::FrameData::strSoundEffect;
}
void RegisterLuaStudioMovementBoneDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::MovementBoneData>("ccs","MovementBoneData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::MovementBoneData*(*)()>(&cocostudio::MovementBoneData::create));
mt.set_function("Init",static_cast<bool(cocostudio::MovementBoneData::*)()>(&cocostudio::MovementBoneData::init));
mt.set_function("AddFrameData",static_cast<void(cocostudio::MovementBoneData::*)(cocostudio::FrameData*)>(&cocostudio::MovementBoneData::addFrameData));
mt.set_function("GetFrameData",static_cast<cocostudio::FrameData*(cocostudio::MovementBoneData::*)(int)>(&cocostudio::MovementBoneData::getFrameData));
mt[sol::call_constructor]=sol::constructors<cocostudio::MovementBoneData()>();
mt["Delay"]=&cocostudio::MovementBoneData::delay;
mt["Scale"]=&cocostudio::MovementBoneData::scale;
mt["Duration"]=&cocostudio::MovementBoneData::duration;
mt["Name"]=&cocostudio::MovementBoneData::name;
}
void RegisterLuaStudioMovementDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::MovementData>("ccs","MovementData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::MovementData*(*)()>(&cocostudio::MovementData::create));
mt.set_function("AddMovementBoneData",static_cast<void(cocostudio::MovementData::*)(cocostudio::MovementBoneData*)>(&cocostudio::MovementData::addMovementBoneData));
mt.set_function("GetMovementBoneData",static_cast<cocostudio::MovementBoneData*(cocostudio::MovementData::*)(const std::string&)>(&cocostudio::MovementData::getMovementBoneData));
mt[sol::call_constructor]=sol::constructors<cocostudio::MovementData()>();
mt["Name"]=&cocostudio::MovementData::name;
mt["Duration"]=&cocostudio::MovementData::duration;
mt["Scale"]=&cocostudio::MovementData::scale;
mt["DurationTo"]=&cocostudio::MovementData::durationTo;
mt["DurationTween"]=&cocostudio::MovementData::durationTween;
mt["Loop"]=&cocostudio::MovementData::loop;
mt["TweenEasing"]=&cocostudio::MovementData::tweenEasing;
}
void RegisterLuaStudioAnimationDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::AnimationData>("ccs","AnimationData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::AnimationData*(*)()>(&cocostudio::AnimationData::create));
mt.set_function("AddMovement",static_cast<void(cocostudio::AnimationData::*)(cocostudio::MovementData*)>(&cocostudio::AnimationData::addMovement));
mt.set_function("GetMovement",static_cast<cocostudio::MovementData*(cocostudio::AnimationData::*)(const std::string&)>(&cocostudio::AnimationData::getMovement));
mt.set_function("GetMovementCount",static_cast<ssize_t(cocostudio::AnimationData::*)()>(&cocostudio::AnimationData::getMovementCount));
mt[sol::call_constructor]=sol::constructors<cocostudio::AnimationData()>();
mt["Name"]=&cocostudio::AnimationData::name;
mt["MovementNames"]=&cocostudio::AnimationData::movementNames;
}
void RegisterLuaStudioContourDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ContourData>("ccs","ContourData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ContourData*(*)()>(&cocostudio::ContourData::create));
mt.set_function("Init",static_cast<bool(cocostudio::ContourData::*)()>(&cocostudio::ContourData::init));
mt.set_function("AddVertex",static_cast<void(cocostudio::ContourData::*)(cocos2d::Vec2&)>(&cocostudio::ContourData::addVertex));
mt[sol::call_constructor]=sol::constructors<cocostudio::ContourData()>();
mt["VertexList"]=&cocostudio::ContourData::vertexList;
}
