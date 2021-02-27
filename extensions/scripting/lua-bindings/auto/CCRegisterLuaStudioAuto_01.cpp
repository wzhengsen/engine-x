#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioSpriteDisplayDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::SpriteDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("SpriteDisplayData",false);
ns["SpriteDisplayData"] = mt;
lua["SpriteDisplayData"] = sol::nil;
mt.set_function("copy",static_cast<void(cocostudio::SpriteDisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::SpriteDisplayData::copy));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::SpriteDisplayData*(*)()>(&cocostudio::SpriteDisplayData::create));
mt["skinData"] = &cocostudio::SpriteDisplayData::skinData;
}
void RegisterLuaStudioArmatureDisplayDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ArmatureDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ArmatureDisplayData",false);
ns["ArmatureDisplayData"] = mt;
lua["ArmatureDisplayData"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ArmatureDisplayData*(*)()>(&cocostudio::ArmatureDisplayData::create));
}
void RegisterLuaStudioParticleDisplayDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ParticleDisplayData,cocostudio::DisplayData,cocos2d::Ref,cocos2d::LuaObject>("ParticleDisplayData",false);
ns["ParticleDisplayData"] = mt;
lua["ParticleDisplayData"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ParticleDisplayData*(*)()>(&cocostudio::ParticleDisplayData::create));
}
void RegisterLuaStudioBoneDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::BoneData,cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("BoneData",false);
ns["BoneData"] = mt;
lua["BoneData"] = sol::nil;
mt.set_function("init",static_cast<bool(cocostudio::BoneData::*)()>(&cocostudio::BoneData::init));
mt.set_function("addDisplayData",static_cast<void(cocostudio::BoneData::*)(cocostudio::DisplayData*)>(&cocostudio::BoneData::addDisplayData));
mt.set_function("getDisplayData",static_cast<cocostudio::DisplayData*(cocostudio::BoneData::*)(int)>(&cocostudio::BoneData::getDisplayData));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::BoneData*(*)()>(&cocostudio::BoneData::create));
mt["name"] = &cocostudio::BoneData::name;
mt["parentName"] = &cocostudio::BoneData::parentName;
mt["boneDataTransform"] = &cocostudio::BoneData::boneDataTransform;
}
void RegisterLuaStudioArmatureDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ArmatureData,cocos2d::Ref,cocos2d::LuaObject>("ArmatureData",false);
ns["ArmatureData"] = mt;
lua["ArmatureData"] = sol::nil;
mt.set_function("init",static_cast<bool(cocostudio::ArmatureData::*)()>(&cocostudio::ArmatureData::init));
mt.set_function("addBoneData",static_cast<void(cocostudio::ArmatureData::*)(cocostudio::BoneData*)>(&cocostudio::ArmatureData::addBoneData));
mt.set_function("getBoneData",static_cast<cocostudio::BoneData*(cocostudio::ArmatureData::*)(const std::string&)>(&cocostudio::ArmatureData::getBoneData));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ArmatureData*(*)()>(&cocostudio::ArmatureData::create));
mt["name"] = &cocostudio::ArmatureData::name;
mt["dataVersion"] = &cocostudio::ArmatureData::dataVersion;
}
void RegisterLuaStudioFrameDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::FrameData,cocostudio::BaseData,cocos2d::Ref,cocos2d::LuaObject>("FrameData",false);
ns["FrameData"] = mt;
lua["FrameData"] = sol::nil;
mt.set_function("copy",static_cast<void(cocostudio::FrameData::*)(const cocostudio::BaseData*)>(&cocostudio::FrameData::copy));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::FrameData*(*)()>(&cocostudio::FrameData::create));
mt["frameID"] = &cocostudio::FrameData::frameID;
mt["duration"] = &cocostudio::FrameData::duration;
mt["tweenEasing"] = &cocostudio::FrameData::tweenEasing;
mt["easingParamNumber"] = &cocostudio::FrameData::easingParamNumber;
mt["easingParams"] = &cocostudio::FrameData::easingParams;
mt["isTween"] = &cocostudio::FrameData::isTween;
mt["displayIndex"] = &cocostudio::FrameData::displayIndex;
mt["blendFunc"] = &cocostudio::FrameData::blendFunc;
mt["strEvent"] = &cocostudio::FrameData::strEvent;
mt["strMovement"] = &cocostudio::FrameData::strMovement;
mt["strSound"] = &cocostudio::FrameData::strSound;
mt["strSoundEffect"] = &cocostudio::FrameData::strSoundEffect;
}
void RegisterLuaStudioMovementBoneDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::MovementBoneData,cocos2d::Ref,cocos2d::LuaObject>("MovementBoneData",false);
ns["MovementBoneData"] = mt;
lua["MovementBoneData"] = sol::nil;
mt.set_function("init",static_cast<bool(cocostudio::MovementBoneData::*)()>(&cocostudio::MovementBoneData::init));
mt.set_function("addFrameData",static_cast<void(cocostudio::MovementBoneData::*)(cocostudio::FrameData*)>(&cocostudio::MovementBoneData::addFrameData));
mt.set_function("getFrameData",static_cast<cocostudio::FrameData*(cocostudio::MovementBoneData::*)(int)>(&cocostudio::MovementBoneData::getFrameData));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::MovementBoneData*(*)()>(&cocostudio::MovementBoneData::create));
mt["delay"] = &cocostudio::MovementBoneData::delay;
mt["scale"] = &cocostudio::MovementBoneData::scale;
mt["duration"] = &cocostudio::MovementBoneData::duration;
mt["name"] = &cocostudio::MovementBoneData::name;
}
void RegisterLuaStudioMovementDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::MovementData,cocos2d::Ref,cocos2d::LuaObject>("MovementData",false);
ns["MovementData"] = mt;
lua["MovementData"] = sol::nil;
mt.set_function("addMovementBoneData",static_cast<void(cocostudio::MovementData::*)(cocostudio::MovementBoneData*)>(&cocostudio::MovementData::addMovementBoneData));
mt.set_function("getMovementBoneData",static_cast<cocostudio::MovementBoneData*(cocostudio::MovementData::*)(const std::string&)>(&cocostudio::MovementData::getMovementBoneData));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::MovementData*(*)()>(&cocostudio::MovementData::create));
mt["name"] = &cocostudio::MovementData::name;
mt["duration"] = &cocostudio::MovementData::duration;
mt["scale"] = &cocostudio::MovementData::scale;
mt["durationTo"] = &cocostudio::MovementData::durationTo;
mt["durationTween"] = &cocostudio::MovementData::durationTween;
mt["loop"] = &cocostudio::MovementData::loop;
mt["tweenEasing"] = &cocostudio::MovementData::tweenEasing;
}
void RegisterLuaStudioAnimationDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::AnimationData,cocos2d::Ref,cocos2d::LuaObject>("AnimationData",false);
ns["AnimationData"] = mt;
lua["AnimationData"] = sol::nil;
mt.set_function("addMovement",static_cast<void(cocostudio::AnimationData::*)(cocostudio::MovementData*)>(&cocostudio::AnimationData::addMovement));
mt.set_function("getMovement",static_cast<cocostudio::MovementData*(cocostudio::AnimationData::*)(const std::string&)>(&cocostudio::AnimationData::getMovement));
mt.set_function("getMovementCount",static_cast<ssize_t(cocostudio::AnimationData::*)()>(&cocostudio::AnimationData::getMovementCount));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::AnimationData*(*)()>(&cocostudio::AnimationData::create));
mt["name"] = &cocostudio::AnimationData::name;
mt["movementNames"] = &cocostudio::AnimationData::movementNames;
}
void RegisterLuaStudioContourDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ContourData,cocos2d::Ref,cocos2d::LuaObject>("ContourData",false);
ns["ContourData"] = mt;
lua["ContourData"] = sol::nil;
mt.set_function("init",static_cast<bool(cocostudio::ContourData::*)()>(&cocostudio::ContourData::init));
mt.set_function("addVertex",static_cast<void(cocostudio::ContourData::*)(cocos2d::Vec2&)>(&cocostudio::ContourData::addVertex));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ContourData*(*)()>(&cocostudio::ContourData::create));
mt["vertexList"] = &cocostudio::ContourData::vertexList;
}
