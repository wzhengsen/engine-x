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
mt["set"]["SkinData"]=[](cocostudio::SpriteDisplayData* obj,const cocostudio::BaseData& value){obj->skinData = value;};
mt["get"]["SkinData"]=[](cocostudio::SpriteDisplayData* obj)->const cocostudio::BaseData&{return obj->skinData;};
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
mt["set"]["Name"]=[](cocostudio::BoneData* obj,const std::string& value){obj->name = value;};
mt["get"]["Name"]=[](cocostudio::BoneData* obj)->const std::string&{return obj->name;};
mt["set"]["ParentName"]=[](cocostudio::BoneData* obj,const std::string& value){obj->parentName = value;};
mt["get"]["ParentName"]=[](cocostudio::BoneData* obj)->const std::string&{return obj->parentName;};
mt["set"]["BoneDataTransform"]=[](cocostudio::BoneData* obj,const cocos2d::AffineTransform& value){obj->boneDataTransform = value;};
mt["get"]["BoneDataTransform"]=[](cocostudio::BoneData* obj)->const cocos2d::AffineTransform&{return obj->boneDataTransform;};
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
mt["set"]["Name"]=[](cocostudio::ArmatureData* obj,const std::string& value){obj->name = value;};
mt["get"]["Name"]=[](cocostudio::ArmatureData* obj)->const std::string&{return obj->name;};
mt["set"]["DataVersion"]=[](cocostudio::ArmatureData* obj,const float& value){obj->dataVersion = value;};
mt["get"]["DataVersion"]=[](cocostudio::ArmatureData* obj)->const float&{return obj->dataVersion;};
}
void RegisterLuaStudioFrameDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::FrameData).name()] = sol::usertype_traits<cocostudio::FrameData*>::metatable();
auto dep=lua.new_usertype<cocostudio::FrameData>("deprecated.cocostudio::FrameData");
dep[sol::base_classes]=sol::bases<cocostudio::BaseData,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::FrameData*>::metatable(),sol::usertype_traits<cocostudio::BaseData*>::metatable());
lua["ccs"]["FrameData"]=mt;
mt["__new__"]=static_cast<cocostudio::FrameData*(*)()>(&cocostudio::FrameData::create);
mt["set"]["FrameID"]=[](cocostudio::FrameData* obj,const int& value){obj->frameID = value;};
mt["get"]["FrameID"]=[](cocostudio::FrameData* obj)->const int&{return obj->frameID;};
mt["set"]["Duration"]=[](cocostudio::FrameData* obj,const int& value){obj->duration = value;};
mt["get"]["Duration"]=[](cocostudio::FrameData* obj)->const int&{return obj->duration;};
mt["set"]["TweenEasing"]=[](cocostudio::FrameData* obj,const cocos2d::tweenfunc::TweenType& value){obj->tweenEasing = value;};
mt["get"]["TweenEasing"]=[](cocostudio::FrameData* obj)->const cocos2d::tweenfunc::TweenType&{return obj->tweenEasing;};
mt["set"]["EasingParamNumber"]=[](cocostudio::FrameData* obj,const int& value){obj->easingParamNumber = value;};
mt["get"]["EasingParamNumber"]=[](cocostudio::FrameData* obj)->const int&{return obj->easingParamNumber;};
mt["set"]["EasingParams"]=[](cocostudio::FrameData* obj,float* value){obj->easingParams = value;};
mt["get"]["EasingParams"]=[](cocostudio::FrameData* obj)->const float*{return obj->easingParams;};
mt["set"]["IsTween"]=[](cocostudio::FrameData* obj,const bool& value){obj->isTween = value;};
mt["get"]["IsTween"]=[](cocostudio::FrameData* obj)->const bool&{return obj->isTween;};
mt["set"]["DisplayIndex"]=[](cocostudio::FrameData* obj,const int& value){obj->displayIndex = value;};
mt["get"]["DisplayIndex"]=[](cocostudio::FrameData* obj)->const int&{return obj->displayIndex;};
mt["set"]["BlendFunc"]=[](cocostudio::FrameData* obj,const cocos2d::BlendFunc& value){obj->blendFunc = value;};
mt["get"]["BlendFunc"]=[](cocostudio::FrameData* obj)->const cocos2d::BlendFunc&{return obj->blendFunc;};
mt["set"]["StrEvent"]=[](cocostudio::FrameData* obj,const std::string& value){obj->strEvent = value;};
mt["get"]["StrEvent"]=[](cocostudio::FrameData* obj)->const std::string&{return obj->strEvent;};
mt["set"]["StrMovement"]=[](cocostudio::FrameData* obj,const std::string& value){obj->strMovement = value;};
mt["get"]["StrMovement"]=[](cocostudio::FrameData* obj)->const std::string&{return obj->strMovement;};
mt["set"]["StrSound"]=[](cocostudio::FrameData* obj,const std::string& value){obj->strSound = value;};
mt["get"]["StrSound"]=[](cocostudio::FrameData* obj)->const std::string&{return obj->strSound;};
mt["set"]["StrSoundEffect"]=[](cocostudio::FrameData* obj,const std::string& value){obj->strSoundEffect = value;};
mt["get"]["StrSoundEffect"]=[](cocostudio::FrameData* obj)->const std::string&{return obj->strSoundEffect;};
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
mt["set"]["Delay"]=[](cocostudio::MovementBoneData* obj,const float& value){obj->delay = value;};
mt["get"]["Delay"]=[](cocostudio::MovementBoneData* obj)->const float&{return obj->delay;};
mt["set"]["Scale"]=[](cocostudio::MovementBoneData* obj,const float& value){obj->scale = value;};
mt["get"]["Scale"]=[](cocostudio::MovementBoneData* obj)->const float&{return obj->scale;};
mt["set"]["Duration"]=[](cocostudio::MovementBoneData* obj,const float& value){obj->duration = value;};
mt["get"]["Duration"]=[](cocostudio::MovementBoneData* obj)->const float&{return obj->duration;};
mt["set"]["Name"]=[](cocostudio::MovementBoneData* obj,const std::string& value){obj->name = value;};
mt["get"]["Name"]=[](cocostudio::MovementBoneData* obj)->const std::string&{return obj->name;};
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
mt["set"]["Name"]=[](cocostudio::MovementData* obj,const std::string& value){obj->name = value;};
mt["get"]["Name"]=[](cocostudio::MovementData* obj)->const std::string&{return obj->name;};
mt["set"]["Duration"]=[](cocostudio::MovementData* obj,const int& value){obj->duration = value;};
mt["get"]["Duration"]=[](cocostudio::MovementData* obj)->const int&{return obj->duration;};
mt["set"]["Scale"]=[](cocostudio::MovementData* obj,const float& value){obj->scale = value;};
mt["get"]["Scale"]=[](cocostudio::MovementData* obj)->const float&{return obj->scale;};
mt["set"]["DurationTo"]=[](cocostudio::MovementData* obj,const int& value){obj->durationTo = value;};
mt["get"]["DurationTo"]=[](cocostudio::MovementData* obj)->const int&{return obj->durationTo;};
mt["set"]["DurationTween"]=[](cocostudio::MovementData* obj,const int& value){obj->durationTween = value;};
mt["get"]["DurationTween"]=[](cocostudio::MovementData* obj)->const int&{return obj->durationTween;};
mt["set"]["Loop"]=[](cocostudio::MovementData* obj,const bool& value){obj->loop = value;};
mt["get"]["Loop"]=[](cocostudio::MovementData* obj)->const bool&{return obj->loop;};
mt["set"]["TweenEasing"]=[](cocostudio::MovementData* obj,const cocos2d::tweenfunc::TweenType& value){obj->tweenEasing = value;};
mt["get"]["TweenEasing"]=[](cocostudio::MovementData* obj)->const cocos2d::tweenfunc::TweenType&{return obj->tweenEasing;};
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
mt["set"]["Name"]=[](cocostudio::AnimationData* obj,const std::string& value){obj->name = value;};
mt["get"]["Name"]=[](cocostudio::AnimationData* obj)->const std::string&{return obj->name;};
mt["set"]["MovementNames"]=[](cocostudio::AnimationData* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& value){obj->movementNames = value;};
mt["get"]["MovementNames"]=[](cocostudio::AnimationData* obj)->const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >&{return obj->movementNames;};
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
mt["set"]["VertexList"]=[](cocostudio::ContourData* obj,const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >& value){obj->vertexList = value;};
mt["get"]["VertexList"]=[](cocostudio::ContourData* obj)->const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&{return obj->vertexList;};
}
