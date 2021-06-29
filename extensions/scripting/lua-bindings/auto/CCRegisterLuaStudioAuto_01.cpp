#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioSpriteDisplayDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::SpriteDisplayData).name()] = sol::usertype_traits<cocostudio::SpriteDisplayData*>::metatable();
auto dep=lua.new_usertype<cocostudio::SpriteDisplayData>("deprecated.cocostudio::SpriteDisplayData");
dep[sol::base_classes]=sol::bases<cocostudio::DisplayData,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::SpriteDisplayData*>::metatable(),sol::usertype_traits<cocostudio::DisplayData*>::metatable());
lua["ccs"]["SpriteDisplayData"]=mt;
mt["__new__"]=static_cast<cocostudio::SpriteDisplayData*(*)()>(&cocostudio::SpriteDisplayData::create);
mt["get"]["SkinData"]=[](cocostudio::SpriteDisplayData* obj){return obj->skinData;};;
}
void RegisterLuaStudioArmatureDisplayDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ArmatureDisplayData).name()] = sol::usertype_traits<cocostudio::ArmatureDisplayData*>::metatable();
auto dep=lua.new_usertype<cocostudio::ArmatureDisplayData>("deprecated.cocostudio::ArmatureDisplayData");
dep[sol::base_classes]=sol::bases<cocostudio::DisplayData,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ArmatureDisplayData*>::metatable(),sol::usertype_traits<cocostudio::DisplayData*>::metatable());
lua["ccs"]["ArmatureDisplayData"]=mt;
mt["__new__"]=static_cast<cocostudio::ArmatureDisplayData*(*)()>(&cocostudio::ArmatureDisplayData::create);
}
void RegisterLuaStudioParticleDisplayDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ParticleDisplayData).name()] = sol::usertype_traits<cocostudio::ParticleDisplayData*>::metatable();
auto dep=lua.new_usertype<cocostudio::ParticleDisplayData>("deprecated.cocostudio::ParticleDisplayData");
dep[sol::base_classes]=sol::bases<cocostudio::DisplayData,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ParticleDisplayData*>::metatable(),sol::usertype_traits<cocostudio::DisplayData*>::metatable());
lua["ccs"]["ParticleDisplayData"]=mt;
mt["__new__"]=static_cast<cocostudio::ParticleDisplayData*(*)()>(&cocostudio::ParticleDisplayData::create);
}
void RegisterLuaStudioBoneDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::BoneData).name()] = sol::usertype_traits<cocostudio::BoneData*>::metatable();
auto dep=lua.new_usertype<cocostudio::BoneData>("deprecated.cocostudio::BoneData");
dep[sol::base_classes]=sol::bases<cocostudio::BaseData,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::BoneData*>::metatable(),sol::usertype_traits<cocostudio::BaseData*>::metatable());
lua["ccs"]["BoneData"]=mt;
mt["__new__"]=static_cast<cocostudio::BoneData*(*)()>(&cocostudio::BoneData::create);
mt["Init"]=static_cast<bool(cocostudio::BoneData::*)()>(&cocostudio::BoneData::init);
mt["AddDisplayData"]=static_cast<void(cocostudio::BoneData::*)(cocostudio::DisplayData*)>(&cocostudio::BoneData::addDisplayData);
mt["GetDisplayData"]=static_cast<cocostudio::DisplayData*(cocostudio::BoneData::*)(int)>(&cocostudio::BoneData::getDisplayData);
mt["get"]["Name"]=[](cocostudio::BoneData* obj){return obj->name;};;
mt["get"]["ParentName"]=[](cocostudio::BoneData* obj){return obj->parentName;};;
mt["get"]["BoneDataTransform"]=[](cocostudio::BoneData* obj){return obj->boneDataTransform;};;
}
void RegisterLuaStudioArmatureDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ArmatureData).name()] = sol::usertype_traits<cocostudio::ArmatureData*>::metatable();
auto dep=lua.new_usertype<cocostudio::ArmatureData>("deprecated.cocostudio::ArmatureData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ArmatureData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ArmatureData"]=mt;
mt["__new__"]=static_cast<cocostudio::ArmatureData*(*)()>(&cocostudio::ArmatureData::create);
mt["Init"]=static_cast<bool(cocostudio::ArmatureData::*)()>(&cocostudio::ArmatureData::init);
mt["AddBoneData"]=static_cast<void(cocostudio::ArmatureData::*)(cocostudio::BoneData*)>(&cocostudio::ArmatureData::addBoneData);
mt["GetBoneData"]=static_cast<cocostudio::BoneData*(cocostudio::ArmatureData::*)(const std::string&)>(&cocostudio::ArmatureData::getBoneData);
mt["get"]["Name"]=[](cocostudio::ArmatureData* obj){return obj->name;};;
mt["get"]["DataVersion"]=[](cocostudio::ArmatureData* obj){return obj->dataVersion;};;
}
void RegisterLuaStudioFrameDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::FrameData).name()] = sol::usertype_traits<cocostudio::FrameData*>::metatable();
auto dep=lua.new_usertype<cocostudio::FrameData>("deprecated.cocostudio::FrameData");
dep[sol::base_classes]=sol::bases<cocostudio::BaseData,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::FrameData*>::metatable(),sol::usertype_traits<cocostudio::BaseData*>::metatable());
lua["ccs"]["FrameData"]=mt;
mt["__new__"]=static_cast<cocostudio::FrameData*(*)()>(&cocostudio::FrameData::create);
mt["get"]["FrameID"]=[](cocostudio::FrameData* obj){return obj->frameID;};;
mt["get"]["Duration"]=[](cocostudio::FrameData* obj){return obj->duration;};;
mt["get"]["TweenEasing"]=[](cocostudio::FrameData* obj){return obj->tweenEasing;};;
mt["get"]["EasingParamNumber"]=[](cocostudio::FrameData* obj){return obj->easingParamNumber;};;
mt["get"]["EasingParams"]=[](cocostudio::FrameData* obj){return obj->easingParams;};;
mt["get"]["IsTween"]=[](cocostudio::FrameData* obj){return obj->isTween;};;
mt["get"]["DisplayIndex"]=[](cocostudio::FrameData* obj){return obj->displayIndex;};;
mt["get"]["BlendFunc"]=[](cocostudio::FrameData* obj){return obj->blendFunc;};;
mt["get"]["StrEvent"]=[](cocostudio::FrameData* obj){return obj->strEvent;};;
mt["get"]["StrMovement"]=[](cocostudio::FrameData* obj){return obj->strMovement;};;
mt["get"]["StrSound"]=[](cocostudio::FrameData* obj){return obj->strSound;};;
mt["get"]["StrSoundEffect"]=[](cocostudio::FrameData* obj){return obj->strSoundEffect;};;
}
void RegisterLuaStudioMovementBoneDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::MovementBoneData).name()] = sol::usertype_traits<cocostudio::MovementBoneData*>::metatable();
auto dep=lua.new_usertype<cocostudio::MovementBoneData>("deprecated.cocostudio::MovementBoneData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::MovementBoneData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["MovementBoneData"]=mt;
mt["__new__"]=static_cast<cocostudio::MovementBoneData*(*)()>(&cocostudio::MovementBoneData::create);
mt["Init"]=static_cast<bool(cocostudio::MovementBoneData::*)()>(&cocostudio::MovementBoneData::init);
mt["AddFrameData"]=static_cast<void(cocostudio::MovementBoneData::*)(cocostudio::FrameData*)>(&cocostudio::MovementBoneData::addFrameData);
mt["GetFrameData"]=static_cast<cocostudio::FrameData*(cocostudio::MovementBoneData::*)(int)>(&cocostudio::MovementBoneData::getFrameData);
mt["get"]["Delay"]=[](cocostudio::MovementBoneData* obj){return obj->delay;};;
mt["get"]["Scale"]=[](cocostudio::MovementBoneData* obj){return obj->scale;};;
mt["get"]["Duration"]=[](cocostudio::MovementBoneData* obj){return obj->duration;};;
mt["get"]["Name"]=[](cocostudio::MovementBoneData* obj){return obj->name;};;
}
void RegisterLuaStudioMovementDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::MovementData).name()] = sol::usertype_traits<cocostudio::MovementData*>::metatable();
auto dep=lua.new_usertype<cocostudio::MovementData>("deprecated.cocostudio::MovementData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::MovementData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["MovementData"]=mt;
mt["__new__"]=static_cast<cocostudio::MovementData*(*)()>(&cocostudio::MovementData::create);
mt["AddMovementBoneData"]=static_cast<void(cocostudio::MovementData::*)(cocostudio::MovementBoneData*)>(&cocostudio::MovementData::addMovementBoneData);
mt["GetMovementBoneData"]=static_cast<cocostudio::MovementBoneData*(cocostudio::MovementData::*)(const std::string&)>(&cocostudio::MovementData::getMovementBoneData);
mt["get"]["Name"]=[](cocostudio::MovementData* obj){return obj->name;};;
mt["get"]["Duration"]=[](cocostudio::MovementData* obj){return obj->duration;};;
mt["get"]["Scale"]=[](cocostudio::MovementData* obj){return obj->scale;};;
mt["get"]["DurationTo"]=[](cocostudio::MovementData* obj){return obj->durationTo;};;
mt["get"]["DurationTween"]=[](cocostudio::MovementData* obj){return obj->durationTween;};;
mt["get"]["Loop"]=[](cocostudio::MovementData* obj){return obj->loop;};;
mt["get"]["TweenEasing"]=[](cocostudio::MovementData* obj){return obj->tweenEasing;};;
}
void RegisterLuaStudioAnimationDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::AnimationData).name()] = sol::usertype_traits<cocostudio::AnimationData*>::metatable();
auto dep=lua.new_usertype<cocostudio::AnimationData>("deprecated.cocostudio::AnimationData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::AnimationData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["AnimationData"]=mt;
mt["__new__"]=static_cast<cocostudio::AnimationData*(*)()>(&cocostudio::AnimationData::create);
mt["AddMovement"]=static_cast<void(cocostudio::AnimationData::*)(cocostudio::MovementData*)>(&cocostudio::AnimationData::addMovement);
mt["GetMovement"]=static_cast<cocostudio::MovementData*(cocostudio::AnimationData::*)(const std::string&)>(&cocostudio::AnimationData::getMovement);
mt["GetMovementCount"]=static_cast<ssize_t(cocostudio::AnimationData::*)()>(&cocostudio::AnimationData::getMovementCount);
mt["get"]["MovementCount"]=mt["GetMovementCount"];
mt["get"]["Name"]=[](cocostudio::AnimationData* obj){return obj->name;};;
mt["get"]["MovementNames"]=[](cocostudio::AnimationData* obj){return obj->movementNames;};;
}
void RegisterLuaStudioContourDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ContourData).name()] = sol::usertype_traits<cocostudio::ContourData*>::metatable();
auto dep=lua.new_usertype<cocostudio::ContourData>("deprecated.cocostudio::ContourData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ContourData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ContourData"]=mt;
mt["__new__"]=static_cast<cocostudio::ContourData*(*)()>(&cocostudio::ContourData::create);
mt["Init"]=static_cast<bool(cocostudio::ContourData::*)()>(&cocostudio::ContourData::init);
mt["AddVertex"]=static_cast<void(cocostudio::ContourData::*)(cocos2d::Vec2&)>(&cocostudio::ContourData::addVertex);
mt["get"]["VertexList"]=[](cocostudio::ContourData* obj){return obj->vertexList;};;
}
