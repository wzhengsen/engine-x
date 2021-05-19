#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioTextureDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::TextureData>("ccs","TextureData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::TextureData*(*)()>(&cocostudio::TextureData::create));
mt.set_function("Init",static_cast<bool(cocostudio::TextureData::*)()>(&cocostudio::TextureData::init));
mt.set_function("AddContourData",static_cast<void(cocostudio::TextureData::*)(cocostudio::ContourData*)>(&cocostudio::TextureData::addContourData));
mt.set_function("GetContourData",static_cast<cocostudio::ContourData*(cocostudio::TextureData::*)(int)>(&cocostudio::TextureData::getContourData));
mt[sol::call_constructor]=sol::constructors<cocostudio::TextureData()>();
mt["Height"]=&cocostudio::TextureData::height;
mt["Width"]=&cocostudio::TextureData::width;
mt["PivotX"]=&cocostudio::TextureData::pivotX;
mt["PivotY"]=&cocostudio::TextureData::pivotY;
mt["Name"]=&cocostudio::TextureData::name;
}
void RegisterLuaStudioTweenAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Tween>("ccs","Tween",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ProcessBase,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::Tween*(*)(cocostudio::Bone*)>(&cocostudio::Tween::create));
mt.set_function("Init",static_cast<bool(cocostudio::Tween::*)(cocostudio::Bone*)>(&cocostudio::Tween::init));
mt.set_function("Play",static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*,int,int,int,int)>(&cocostudio::Tween::play));
mt.set_function("SetAnimation",static_cast<void(cocostudio::Tween::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Tween::setAnimation));
mt.set_function("GetAnimation",static_cast<cocostudio::ArmatureAnimation*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getAnimation));
mt.set_function("GotoAndPlay",static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPlay));
mt.set_function("GotoAndPause",static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPause));
mt.set_function("SetMovementBoneData",static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*)>(&cocostudio::Tween::setMovementBoneData));
mt.set_function("GetMovementBoneData",static_cast<const cocostudio::MovementBoneData*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getMovementBoneData));
mt[sol::call_constructor]=sol::constructors<cocostudio::Tween()>();
}
void RegisterLuaStudioDisplayManagerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::DisplayManager>("ccs","DisplayManager",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::DisplayManager*(*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::create));
mt.set_function("Init",static_cast<bool(cocostudio::DisplayManager::*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::init));
mt.set_function("InitDisplayList",static_cast<void(cocostudio::DisplayManager::*)(cocostudio::BoneData*)>(&cocostudio::DisplayManager::initDisplayList));
mt.set_function("AddDisplay",sol::overload(static_cast<void(cocostudio::DisplayManager::*)(cocos2d::Node*,int)>(&cocostudio::DisplayManager::addDisplay),static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DisplayData*,int)>(&cocostudio::DisplayManager::addDisplay)));
mt.set_function("RemoveDisplay",static_cast<void(cocostudio::DisplayManager::*)(int)>(&cocostudio::DisplayManager::removeDisplay));
mt.set_function("GetDecorativeDisplayList",static_cast<const cocos2d::Vector<cocostudio::DecorativeDisplay *>&(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDecorativeDisplayList));
mt.set_function("ChangeDisplayWithIndex",static_cast<void(cocostudio::DisplayManager::*)(int,bool)>(&cocostudio::DisplayManager::changeDisplayWithIndex));
mt.set_function("ChangeDisplayWithName",static_cast<void(cocostudio::DisplayManager::*)(const std::string&,bool)>(&cocostudio::DisplayManager::changeDisplayWithName));
mt.set_function("GetDisplayRenderNode",static_cast<cocos2d::Node*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNode));
mt.set_function("GetDisplayRenderNodeType",static_cast<cocostudio::DisplayType(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNodeType));
mt.set_function("GetCurrentDisplayIndex",static_cast<int(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDisplayIndex));
mt.set_function("SetCurrentDecorativeDisplay",static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DecorativeDisplay*)>(&cocostudio::DisplayManager::setCurrentDecorativeDisplay));
mt.set_function("GetCurrentDecorativeDisplay",static_cast<cocostudio::DecorativeDisplay*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDecorativeDisplay));
mt.set_function("GetDecorativeDisplayByIndex",static_cast<cocostudio::DecorativeDisplay*(cocostudio::DisplayManager::*)(int)const>(&cocostudio::DisplayManager::getDecorativeDisplayByIndex));
mt.set_function("SetVisible",static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setVisible));
mt.set_function("IsVisible",static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isVisible));
mt.set_function("GetContentSize",static_cast<cocos2d::Size(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getContentSize));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getBoundingBox));
mt.set_function("GetAnchorPoint",static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPoint));
mt.set_function("GetAnchorPointInPoints",static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPointInPoints));
mt.set_function("ContainPoint",sol::overload(static_cast<bool(cocostudio::DisplayManager::*)(float,float)>(&cocostudio::DisplayManager::containPoint),static_cast<bool(cocostudio::DisplayManager::*)(cocos2d::Vec2&)>(&cocostudio::DisplayManager::containPoint)));
mt.set_function("SetForceChangeDisplay",static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setForceChangeDisplay));
mt.set_function("IsForceChangeDisplay",static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isForceChangeDisplay));
mt[sol::call_constructor]=sol::constructors<cocostudio::DisplayManager()>();
}
void RegisterLuaStudioBoneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Bone>("ccs","Bone",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocostudio::Bone*(*)(const std::string&)>(&cocostudio::Bone::create),static_cast<cocostudio::Bone*(*)()>(&cocostudio::Bone::create)));
mt.set_function("Init",sol::overload(static_cast<bool(cocostudio::Bone::*)(const std::string&)>(&cocostudio::Bone::init),static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::init)));
mt.set_function("AddDisplay",sol::overload(static_cast<void(cocostudio::Bone::*)(cocos2d::Node*,int)>(&cocostudio::Bone::addDisplay),static_cast<void(cocostudio::Bone::*)(cocostudio::DisplayData*,int)>(&cocostudio::Bone::addDisplay)));
mt.set_function("RemoveDisplay",static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::removeDisplay));
mt.set_function("ChangeDisplayWithIndex",static_cast<void(cocostudio::Bone::*)(int,bool)>(&cocostudio::Bone::changeDisplayWithIndex));
mt.set_function("ChangeDisplayWithName",static_cast<void(cocostudio::Bone::*)(const std::string&,bool)>(&cocostudio::Bone::changeDisplayWithName));
mt.set_function("AddChildBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::addChildBone));
mt.set_function("SetParentBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::setParentBone));
mt.set_function("GetParentBone",static_cast<cocostudio::Bone*(cocostudio::Bone::*)()>(&cocostudio::Bone::getParentBone));
mt.set_function("RemoveFromParent",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::removeFromParent));
mt.set_function("RemoveChildBone",static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*,bool)>(&cocostudio::Bone::removeChildBone));
mt.set_function("Update",static_cast<void(cocostudio::Bone::*)(float)>(&cocostudio::Bone::update));
mt.set_function("UpdateDisplayedColor",static_cast<void(cocostudio::Bone::*)(const cocos2d::Color3B&)>(&cocostudio::Bone::updateDisplayedColor));
mt.set_function("UpdateDisplayedOpacity",static_cast<void(cocostudio::Bone::*)(uint8_t)>(&cocostudio::Bone::updateDisplayedOpacity));
mt.set_function("UpdateColor",static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateColor));
mt.set_function("UpdateZOrder",static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateZOrder));
mt.set_function("SetLocalZOrder",static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::setLocalZOrder));
mt.set_function("GetTween",static_cast<cocostudio::Tween*(cocostudio::Bone::*)()>(&cocostudio::Bone::getTween));
mt.set_function("SetTransformDirty",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setTransformDirty));
mt.set_function("IsTransformDirty",static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isTransformDirty));
mt.set_function("GetNodeToArmatureTransform",static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToArmatureTransform));
mt.set_function("GetNodeToWorldTransform",static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToWorldTransform));
mt.set_function("GetDisplayRenderNode",static_cast<cocos2d::Node*(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNode));
mt.set_function("GetDisplayRenderNodeType",static_cast<cocostudio::DisplayType(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNodeType));
mt.set_function("GetColliderDetector",static_cast<cocostudio::ColliderDetector*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getColliderDetector));
mt.set_function("SetBoneData",static_cast<void(cocostudio::Bone::*)(cocostudio::BoneData*)>(&cocostudio::Bone::setBoneData));
mt.set_function("GetBoneData",static_cast<cocostudio::BoneData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getBoneData));
mt.set_function("SetArmature",static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setArmature));
mt.set_function("GetArmature",static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getArmature));
mt.set_function("SetChildArmature",static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setChildArmature));
mt.set_function("GetChildArmature",static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getChildArmature));
mt.set_function("GetDisplayManager",static_cast<cocostudio::DisplayManager*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getDisplayManager));
mt.set_function("SetIgnoreMovementBoneData",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setIgnoreMovementBoneData));
mt.set_function("IsIgnoreMovementBoneData",static_cast<bool(cocostudio::Bone::*)()const>(&cocostudio::Bone::isIgnoreMovementBoneData));
mt.set_function("SetBlendFunc",static_cast<void(cocostudio::Bone::*)(const cocos2d::BlendFunc&)>(&cocostudio::Bone::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<cocos2d::BlendFunc(cocostudio::Bone::*)()>(&cocostudio::Bone::getBlendFunc));
mt.set_function("SetBlendDirty",static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setBlendDirty));
mt.set_function("IsBlendDirty",static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isBlendDirty));
mt.set_function("GetTweenData",static_cast<cocostudio::FrameData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getTweenData));
mt.set_function("GetWorldInfo",static_cast<cocostudio::BaseData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getWorldInfo));
mt[sol::call_constructor]=sol::constructors<cocostudio::Bone()>();
}
void RegisterLuaStudioBatchNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::BatchNode>("ccs","BatchNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::BatchNode*(*)()>(&cocostudio::BatchNode::create));
mt.set_function("Init",static_cast<bool(cocostudio::BatchNode::*)()>(&cocostudio::BatchNode::init));
mt.set_function("AddChild",sol::overload(static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::BatchNode::addChild),static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,int,int)>(&cocostudio::BatchNode::addChild)));
mt.set_function("RemoveChild",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Node*,bool)>(&cocostudio::BatchNode::removeChild));
mt.set_function("Visit",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::BatchNode::visit));
mt.set_function("Draw",static_cast<void(cocostudio::BatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::BatchNode::draw));
mt[sol::call_constructor]=sol::constructors<cocostudio::BatchNode()>();
}
void RegisterLuaStudioMovementEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccs"];
pTable.new_enum<cocostudio::MovementEventType>("MovementEventType",{
{"START",cocostudio::MovementEventType::START}
,{"COMPLETE",cocostudio::MovementEventType::COMPLETE}
,{"LOOP_COMPLETE",cocostudio::MovementEventType::LOOP_COMPLETE}
});}
void RegisterLuaStudioArmatureAnimationAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureAnimation>("ccs","ArmatureAnimation",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::ProcessBase,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ArmatureAnimation*(*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::create));
mt.set_function("Init",static_cast<bool(cocostudio::ArmatureAnimation::*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::init));
mt.set_function("SetSpeedScale",static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::setSpeedScale));
mt.set_function("GetSpeedScale",static_cast<float(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getSpeedScale));
mt.set_function("Play",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::string& arg0){return obj->play(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1){return obj->play(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1,int arg2){return obj->play(arg0,arg1,arg2);}));
mt.set_function("PlayWithIndex",sol::overload([](cocostudio::ArmatureAnimation* obj,int arg0){return obj->playWithIndex(arg0);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1){return obj->playWithIndex(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1,int arg2){return obj->playWithIndex(arg0,arg1,arg2);}));
mt.set_function("PlayWithNames",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& arg0){return obj->playWithNames(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& arg0,int arg1){return obj->playWithNames(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& arg0,int arg1,bool arg2){return obj->playWithNames(arg0,arg1,arg2);}));
mt.set_function("PlayWithIndexes",sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<int, std::allocator<int> >& arg0){return obj->playWithIndexes(arg0);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int, std::allocator<int> >& arg0,int arg1){return obj->playWithIndexes(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int, std::allocator<int> >& arg0,int arg1,bool arg2){return obj->playWithIndexes(arg0,arg1,arg2);}));
mt.set_function("GotoAndPlay",static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPlay));
mt.set_function("GotoAndPause",static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPause));
mt.set_function("Pause",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::pause));
mt.set_function("Resume",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::resume));
mt.set_function("Stop",static_cast<void(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::stop));
mt.set_function("GetMovementCount",static_cast<ssize_t(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getMovementCount));
mt.set_function("Update",static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::update));
mt.set_function("GetCurrentMovementID",static_cast<std::string(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getCurrentMovementID));
mt.set_function("SetMovementEventCallFunc",static_cast<void(cocostudio::ArmatureAnimation::*)(std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>)>(&cocostudio::ArmatureAnimation::setMovementEventCallFunc));
mt.set_function("SetFrameEventCallFunc",static_cast<void(cocostudio::ArmatureAnimation::*)(std::function<void (cocostudio::Bone *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, int, int)>)>(&cocostudio::ArmatureAnimation::setFrameEventCallFunc));
mt.set_function("SetAnimationData",static_cast<void(cocostudio::ArmatureAnimation::*)(cocostudio::AnimationData*)>(&cocostudio::ArmatureAnimation::setAnimationData));
mt.set_function("GetAnimationData",static_cast<cocostudio::AnimationData*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getAnimationData));
mt.set_function("GetUserObject",sol::overload(static_cast<const cocos2d::Ref*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getUserObject),static_cast<cocos2d::Ref*(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::getUserObject)));
mt.set_function("SetUserObject",static_cast<void(cocostudio::ArmatureAnimation::*)(cocos2d::Ref*)>(&cocostudio::ArmatureAnimation::setUserObject));
mt[sol::call_constructor]=sol::constructors<cocostudio::ArmatureAnimation()>();
}
void RegisterLuaStudioArmatureDataManagerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ArmatureDataManager>("ccs","ArmatureDataManager",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocostudio::ArmatureDataManager*(*)()>(&cocostudio::ArmatureDataManager::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocostudio::ArmatureDataManager::destroyInstance));
mt.set_function("Init",static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::init));
mt.set_function("AddArmatureData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1){return obj->addArmatureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1,const std::string& arg2){return obj->addArmatureData(arg0,arg1,arg2);}));
mt.set_function("GetArmatureData",static_cast<cocostudio::ArmatureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getArmatureData));
mt.set_function("RemoveArmatureData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureData));
mt.set_function("AddAnimationData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1){return obj->addAnimationData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1,const std::string& arg2){return obj->addAnimationData(arg0,arg1,arg2);}));
mt.set_function("GetAnimationData",static_cast<cocostudio::AnimationData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getAnimationData));
mt.set_function("RemoveAnimationData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeAnimationData));
mt.set_function("AddTextureData",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1){return obj->addTextureData(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1,const std::string& arg2){return obj->addTextureData(arg0,arg1,arg2);}));
mt.set_function("GetTextureData",static_cast<cocostudio::TextureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getTextureData));
mt.set_function("RemoveTextureData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeTextureData));
mt.set_function("AddArmatureFileInfo",sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo)));
mt.set_function("AddArmatureFileInfoAsync",sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync)));
mt.set_function("AddSpriteFrameFromFile",sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1){return obj->addSpriteFrameFromFile(arg0,arg1);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->addSpriteFrameFromFile(arg0,arg1,arg2);}));
mt.set_function("RemoveArmatureFileInfo",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureFileInfo));
mt.set_function("IsAutoLoadSpriteFile",static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::isAutoLoadSpriteFile));
mt.set_function("GetArmatureDatas",static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::ArmatureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getArmatureDatas));
mt.set_function("GetAnimationDatas",static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::AnimationData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getAnimationDatas));
mt.set_function("GetTextureDatas",static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::TextureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getTextureDatas));
mt.set_function("AddRelativeData",static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addRelativeData));
mt.set_function("GetRelativeData",static_cast<cocostudio::RelativeData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getRelativeData));
mt["Instance"]=sol::property(&cocostudio::ArmatureDataManager::getInstance,[](std::nullptr_t){cocostudio::ArmatureDataManager::destroyInstance();});
}
void RegisterLuaStudioArmatureAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Armature>("ccs","Armature",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocostudio::Armature*(*)(const std::string&)>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)()>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::create)));
mt.set_function("Init",sol::overload(static_cast<bool(cocostudio::Armature::*)(const std::string&)>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)()>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::init)));
mt.set_function("AddBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::addBone));
mt.set_function("GetBone",static_cast<cocostudio::Bone*(cocostudio::Armature::*)(const std::string&)const>(&cocostudio::Armature::getBone));
mt.set_function("ChangeBoneParent",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::changeBoneParent));
mt.set_function("RemoveBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,bool)>(&cocostudio::Armature::removeBone));
mt.set_function("GetBoneDic",static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::Bone *>&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoneDic));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoundingBox));
mt.set_function("GetBoneAtPoint",static_cast<cocostudio::Bone*(cocostudio::Armature::*)(float,float)const>(&cocostudio::Armature::getBoneAtPoint));
mt.set_function("Visit",static_cast<void(cocostudio::Armature::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Armature::visit));
mt.set_function("Draw",static_cast<void(cocostudio::Armature::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Armature::draw));
mt.set_function("Update",static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::update));
mt.set_function("OnEnter",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::onEnter));
mt.set_function("OnExit",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::onExit));
mt.set_function("GetNodeToParentTransform",static_cast<const cocos2d::Mat4&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getNodeToParentTransform));
mt.set_function("SetBlendFunc",static_cast<void(cocostudio::Armature::*)(const cocos2d::BlendFunc&)>(&cocostudio::Armature::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBlendFunc));
mt.set_function("UpdateOffsetPoint",static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::updateOffsetPoint));
mt.set_function("SetAnchorPoint",static_cast<void(cocostudio::Armature::*)(const cocos2d::Vec2&)>(&cocostudio::Armature::setAnchorPoint));
mt.set_function("GetAnchorPointInPoints",static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnchorPointInPoints));
mt.set_function("GetOffsetPoints",static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getOffsetPoints));
mt.set_function("SetAnimation",static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Armature::setAnimation));
mt.set_function("GetAnimation",static_cast<cocostudio::ArmatureAnimation*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnimation));
mt.set_function("GetArmatureTransformDirty",static_cast<bool(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureTransformDirty));
mt.set_function("SetArmatureData",static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureData*)>(&cocostudio::Armature::setArmatureData));
mt.set_function("GetArmatureData",static_cast<cocostudio::ArmatureData*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureData));
mt.set_function("SetParentBone",static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*)>(&cocostudio::Armature::setParentBone));
mt.set_function("GetParentBone",static_cast<cocostudio::Bone*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getParentBone));
mt.set_function("SetVersion",static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::setVersion));
mt.set_function("GetVersion",static_cast<float(cocostudio::Armature::*)()const>(&cocostudio::Armature::getVersion));
mt.set_function("SetBatchNode",static_cast<void(cocostudio::Armature::*)(cocostudio::BatchNode*)>(&cocostudio::Armature::setBatchNode));
mt.set_function("GetBatchNode",static_cast<cocostudio::BatchNode*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBatchNode));
}
void RegisterLuaStudioSkinAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::Skin>("ccs","Skin",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::create),static_cast<cocostudio::Skin*(*)()>(&cocostudio::Skin::create)));
mt.set_function("CreateWithSpriteFrameName",static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::createWithSpriteFrameName));
mt.set_function("InitWithSpriteFrameName",static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithSpriteFrameName));
mt.set_function("InitWithFile",static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithFile));
mt.set_function("UpdateArmatureTransform",static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateArmatureTransform));
mt.set_function("UpdateTransform",static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateTransform));
mt.set_function("GetNodeToWorldTransform",static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransform));
mt.set_function("GetNodeToWorldTransformAR",static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransformAR));
mt.set_function("Draw",static_cast<void(cocostudio::Skin::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::Skin::draw));
mt.set_function("SetSkinData",static_cast<void(cocostudio::Skin::*)(const cocostudio::BaseData&)>(&cocostudio::Skin::setSkinData));
mt.set_function("GetSkinData",static_cast<const cocostudio::BaseData&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getSkinData));
mt.set_function("SetBone",static_cast<void(cocostudio::Skin::*)(cocostudio::Bone*)>(&cocostudio::Skin::setBone));
mt.set_function("GetBone",static_cast<cocostudio::Bone*(cocostudio::Skin::*)()const>(&cocostudio::Skin::getBone));
mt.set_function("GetDisplayName",static_cast<const std::string&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getDisplayName));
}
