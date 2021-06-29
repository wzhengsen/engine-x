#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioTextureDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::TextureData).name()] = sol::usertype_traits<cocostudio::TextureData*>::metatable();
auto dep=lua.new_usertype<cocostudio::TextureData>("deprecated.cocostudio::TextureData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::TextureData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["TextureData"]=mt;
mt["__new__"]=static_cast<cocostudio::TextureData*(*)()>(&cocostudio::TextureData::create);
mt["Init"]=static_cast<bool(cocostudio::TextureData::*)()>(&cocostudio::TextureData::init);
mt["AddContourData"]=static_cast<void(cocostudio::TextureData::*)(cocostudio::ContourData*)>(&cocostudio::TextureData::addContourData);
mt["GetContourData"]=static_cast<cocostudio::ContourData*(cocostudio::TextureData::*)(int)>(&cocostudio::TextureData::getContourData);
mt["get"]["Height"]=[](cocostudio::TextureData* obj){return obj->height;};;
mt["get"]["Width"]=[](cocostudio::TextureData* obj){return obj->width;};;
mt["get"]["PivotX"]=[](cocostudio::TextureData* obj){return obj->pivotX;};;
mt["get"]["PivotY"]=[](cocostudio::TextureData* obj){return obj->pivotY;};;
mt["get"]["Name"]=[](cocostudio::TextureData* obj){return obj->name;};;
}
void RegisterLuaStudioTweenAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::Tween).name()] = sol::usertype_traits<cocostudio::Tween*>::metatable();
auto dep=lua.new_usertype<cocostudio::Tween>("deprecated.cocostudio::Tween");
dep[sol::base_classes]=sol::bases<cocostudio::ProcessBase,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::Tween*>::metatable(),sol::usertype_traits<cocostudio::ProcessBase*>::metatable());
lua["ccs"]["Tween"]=mt;
mt["__new__"]=static_cast<cocostudio::Tween*(*)(cocostudio::Bone*)>(&cocostudio::Tween::create);
mt["Init"]=static_cast<bool(cocostudio::Tween::*)(cocostudio::Bone*)>(&cocostudio::Tween::init);
mt["Play"]=static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*,int,int,int,int)>(&cocostudio::Tween::play);
mt["SetAnimation"]=static_cast<void(cocostudio::Tween::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Tween::setAnimation);
mt["set"]["Animation"]=mt["SetAnimation"];
mt["GetAnimation"]=static_cast<cocostudio::ArmatureAnimation*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getAnimation);
mt["get"]["Animation"]=mt["GetAnimation"];
mt["GotoAndPlay"]=static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPlay);
mt["GotoAndPause"]=static_cast<void(cocostudio::Tween::*)(int)>(&cocostudio::Tween::gotoAndPause);
mt["SetMovementBoneData"]=static_cast<void(cocostudio::Tween::*)(cocostudio::MovementBoneData*)>(&cocostudio::Tween::setMovementBoneData);
mt["set"]["MovementBoneData"]=mt["SetMovementBoneData"];
mt["GetMovementBoneData"]=static_cast<const cocostudio::MovementBoneData*(cocostudio::Tween::*)()const>(&cocostudio::Tween::getMovementBoneData);
mt["get"]["MovementBoneData"]=mt["GetMovementBoneData"];
}
void RegisterLuaStudioDisplayManagerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::DisplayManager).name()] = sol::usertype_traits<cocostudio::DisplayManager*>::metatable();
auto dep=lua.new_usertype<cocostudio::DisplayManager>("deprecated.cocostudio::DisplayManager");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::DisplayManager*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["DisplayManager"]=mt;
mt["__new__"]=static_cast<cocostudio::DisplayManager*(*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::create);
mt["Init"]=static_cast<bool(cocostudio::DisplayManager::*)(cocostudio::Bone*)>(&cocostudio::DisplayManager::init);
mt["InitDisplayList"]=static_cast<void(cocostudio::DisplayManager::*)(cocostudio::BoneData*)>(&cocostudio::DisplayManager::initDisplayList);
mt["AddDisplay"]=sol::overload(static_cast<void(cocostudio::DisplayManager::*)(cocos2d::Node*,int)>(&cocostudio::DisplayManager::addDisplay),static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DisplayData*,int)>(&cocostudio::DisplayManager::addDisplay));
mt["RemoveDisplay"]=static_cast<void(cocostudio::DisplayManager::*)(int)>(&cocostudio::DisplayManager::removeDisplay);
mt["GetDecorativeDisplayList"]=static_cast<const cocos2d::Vector<cocostudio::DecorativeDisplay *>&(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDecorativeDisplayList);
mt["get"]["DecorativeDisplayList"]=mt["GetDecorativeDisplayList"];
mt["ChangeDisplayWithIndex"]=static_cast<void(cocostudio::DisplayManager::*)(int,bool)>(&cocostudio::DisplayManager::changeDisplayWithIndex);
mt["ChangeDisplayWithName"]=static_cast<void(cocostudio::DisplayManager::*)(const std::string&,bool)>(&cocostudio::DisplayManager::changeDisplayWithName);
mt["GetDisplayRenderNode"]=static_cast<cocos2d::Node*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNode);
mt["get"]["DisplayRenderNode"]=mt["GetDisplayRenderNode"];
mt["GetDisplayRenderNodeType"]=static_cast<cocostudio::DisplayType(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getDisplayRenderNodeType);
mt["get"]["DisplayRenderNodeType"]=mt["GetDisplayRenderNodeType"];
mt["GetCurrentDisplayIndex"]=static_cast<int(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDisplayIndex);
mt["get"]["CurrentDisplayIndex"]=mt["GetCurrentDisplayIndex"];
mt["SetCurrentDecorativeDisplay"]=static_cast<void(cocostudio::DisplayManager::*)(cocostudio::DecorativeDisplay*)>(&cocostudio::DisplayManager::setCurrentDecorativeDisplay);
mt["set"]["CurrentDecorativeDisplay"]=mt["SetCurrentDecorativeDisplay"];
mt["GetCurrentDecorativeDisplay"]=static_cast<cocostudio::DecorativeDisplay*(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getCurrentDecorativeDisplay);
mt["get"]["CurrentDecorativeDisplay"]=mt["GetCurrentDecorativeDisplay"];
mt["GetDecorativeDisplayByIndex"]=static_cast<cocostudio::DecorativeDisplay*(cocostudio::DisplayManager::*)(int)const>(&cocostudio::DisplayManager::getDecorativeDisplayByIndex);
mt["SetVisible"]=static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setVisible);
mt["set"]["Visible"]=mt["SetVisible"];
mt["IsVisible"]=static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isVisible);
mt["get"]["Visible"]=mt["IsVisible"];
mt["GetContentSize"]=static_cast<cocos2d::Size(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getContentSize);
mt["get"]["ContentSize"]=mt["GetContentSize"];
mt["GetBoundingBox"]=static_cast<cocos2d::Rect(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getBoundingBox);
mt["get"]["BoundingBox"]=mt["GetBoundingBox"];
mt["GetAnchorPoint"]=static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPoint);
mt["get"]["AnchorPoint"]=mt["GetAnchorPoint"];
mt["GetAnchorPointInPoints"]=static_cast<cocos2d::Vec2(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::getAnchorPointInPoints);
mt["get"]["AnchorPointInPoints"]=mt["GetAnchorPointInPoints"];
mt["ContainPoint"]=sol::overload(static_cast<bool(cocostudio::DisplayManager::*)(float,float)>(&cocostudio::DisplayManager::containPoint),static_cast<bool(cocostudio::DisplayManager::*)(cocos2d::Vec2&)>(&cocostudio::DisplayManager::containPoint));
mt["SetForceChangeDisplay"]=static_cast<void(cocostudio::DisplayManager::*)(bool)>(&cocostudio::DisplayManager::setForceChangeDisplay);
mt["set"]["ForceChangeDisplay"]=mt["SetForceChangeDisplay"];
mt["IsForceChangeDisplay"]=static_cast<bool(cocostudio::DisplayManager::*)()const>(&cocostudio::DisplayManager::isForceChangeDisplay);
mt["get"]["ForceChangeDisplay"]=mt["IsForceChangeDisplay"];
}
void RegisterLuaStudioBoneAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::Bone).name()] = sol::usertype_traits<cocostudio::Bone*>::metatable();
auto dep=lua.new_usertype<cocostudio::Bone>("deprecated.cocostudio::Bone");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::Bone*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["ccs"]["Bone"]=mt;
mt["__new__"]=sol::overload(static_cast<cocostudio::Bone*(*)(const std::string&)>(&cocostudio::Bone::create),static_cast<cocostudio::Bone*(*)()>(&cocostudio::Bone::create));
mt["Init"]=sol::overload(static_cast<bool(cocostudio::Bone::*)(const std::string&)>(&cocostudio::Bone::init),static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::init));
mt["AddDisplay"]=sol::overload(static_cast<void(cocostudio::Bone::*)(cocos2d::Node*,int)>(&cocostudio::Bone::addDisplay),static_cast<void(cocostudio::Bone::*)(cocostudio::DisplayData*,int)>(&cocostudio::Bone::addDisplay));
mt["RemoveDisplay"]=static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::removeDisplay);
mt["ChangeDisplayWithIndex"]=static_cast<void(cocostudio::Bone::*)(int,bool)>(&cocostudio::Bone::changeDisplayWithIndex);
mt["ChangeDisplayWithName"]=static_cast<void(cocostudio::Bone::*)(const std::string&,bool)>(&cocostudio::Bone::changeDisplayWithName);
mt["AddChildBone"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::addChildBone);
mt["SetParentBone"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*)>(&cocostudio::Bone::setParentBone);
mt["set"]["ParentBone"]=mt["SetParentBone"];
mt["GetParentBone"]=static_cast<cocostudio::Bone*(cocostudio::Bone::*)()>(&cocostudio::Bone::getParentBone);
mt["get"]["ParentBone"]=mt["GetParentBone"];
mt["RemoveFromParent"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::removeFromParent);
mt["RemoveChildBone"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Bone*,bool)>(&cocostudio::Bone::removeChildBone);
mt["UpdateColor"]=static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateColor);
mt["UpdateZOrder"]=static_cast<void(cocostudio::Bone::*)()>(&cocostudio::Bone::updateZOrder);
mt["SetLocalZOrder"]=static_cast<void(cocostudio::Bone::*)(int)>(&cocostudio::Bone::setLocalZOrder);
mt["set"]["LocalZOrder"]=mt["SetLocalZOrder"];
mt["GetTween"]=static_cast<cocostudio::Tween*(cocostudio::Bone::*)()>(&cocostudio::Bone::getTween);
mt["get"]["Tween"]=mt["GetTween"];
mt["SetTransformDirty"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setTransformDirty);
mt["set"]["TransformDirty"]=mt["SetTransformDirty"];
mt["IsTransformDirty"]=static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isTransformDirty);
mt["get"]["TransformDirty"]=mt["IsTransformDirty"];
mt["GetNodeToArmatureTransform"]=static_cast<cocos2d::Mat4(cocostudio::Bone::*)()const>(&cocostudio::Bone::getNodeToArmatureTransform);
mt["get"]["NodeToArmatureTransform"]=mt["GetNodeToArmatureTransform"];
mt["GetDisplayRenderNode"]=static_cast<cocos2d::Node*(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNode);
mt["get"]["DisplayRenderNode"]=mt["GetDisplayRenderNode"];
mt["GetDisplayRenderNodeType"]=static_cast<cocostudio::DisplayType(cocostudio::Bone::*)()>(&cocostudio::Bone::getDisplayRenderNodeType);
mt["get"]["DisplayRenderNodeType"]=mt["GetDisplayRenderNodeType"];
mt["GetColliderDetector"]=static_cast<cocostudio::ColliderDetector*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getColliderDetector);
mt["get"]["ColliderDetector"]=mt["GetColliderDetector"];
mt["SetBoneData"]=static_cast<void(cocostudio::Bone::*)(cocostudio::BoneData*)>(&cocostudio::Bone::setBoneData);
mt["set"]["BoneData"]=mt["SetBoneData"];
mt["GetBoneData"]=static_cast<cocostudio::BoneData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getBoneData);
mt["get"]["BoneData"]=mt["GetBoneData"];
mt["SetArmature"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setArmature);
mt["set"]["Armature"]=mt["SetArmature"];
mt["GetArmature"]=static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getArmature);
mt["get"]["Armature"]=mt["GetArmature"];
mt["SetChildArmature"]=static_cast<void(cocostudio::Bone::*)(cocostudio::Armature*)>(&cocostudio::Bone::setChildArmature);
mt["set"]["ChildArmature"]=mt["SetChildArmature"];
mt["GetChildArmature"]=static_cast<cocostudio::Armature*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getChildArmature);
mt["get"]["ChildArmature"]=mt["GetChildArmature"];
mt["GetDisplayManager"]=static_cast<cocostudio::DisplayManager*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getDisplayManager);
mt["get"]["DisplayManager"]=mt["GetDisplayManager"];
mt["SetIgnoreMovementBoneData"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setIgnoreMovementBoneData);
mt["set"]["IgnoreMovementBoneData"]=mt["SetIgnoreMovementBoneData"];
mt["IsIgnoreMovementBoneData"]=static_cast<bool(cocostudio::Bone::*)()const>(&cocostudio::Bone::isIgnoreMovementBoneData);
mt["get"]["IgnoreMovementBoneData"]=mt["IsIgnoreMovementBoneData"];
mt["SetBlendFunc"]=static_cast<void(cocostudio::Bone::*)(const cocos2d::BlendFunc&)>(&cocostudio::Bone::setBlendFunc);
mt["set"]["BlendFunc"]=mt["SetBlendFunc"];
mt["GetBlendFunc"]=static_cast<cocos2d::BlendFunc(cocostudio::Bone::*)()>(&cocostudio::Bone::getBlendFunc);
mt["get"]["BlendFunc"]=mt["GetBlendFunc"];
mt["SetBlendDirty"]=static_cast<void(cocostudio::Bone::*)(bool)>(&cocostudio::Bone::setBlendDirty);
mt["set"]["BlendDirty"]=mt["SetBlendDirty"];
mt["IsBlendDirty"]=static_cast<bool(cocostudio::Bone::*)()>(&cocostudio::Bone::isBlendDirty);
mt["get"]["BlendDirty"]=mt["IsBlendDirty"];
mt["GetTweenData"]=static_cast<cocostudio::FrameData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getTweenData);
mt["get"]["TweenData"]=mt["GetTweenData"];
mt["GetWorldInfo"]=static_cast<cocostudio::BaseData*(cocostudio::Bone::*)()const>(&cocostudio::Bone::getWorldInfo);
mt["get"]["WorldInfo"]=mt["GetWorldInfo"];
}
void RegisterLuaStudioBatchNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::BatchNode).name()] = sol::usertype_traits<cocostudio::BatchNode*>::metatable();
auto dep=lua.new_usertype<cocostudio::BatchNode>("deprecated.cocostudio::BatchNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::BatchNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["ccs"]["BatchNode"]=mt;
mt["__new__"]=static_cast<cocostudio::BatchNode*(*)()>(&cocostudio::BatchNode::create);
mt["Init"]=static_cast<bool(cocostudio::BatchNode::*)()>(&cocostudio::BatchNode::init);
}
void RegisterLuaStudioMovementEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["START"]=cocostudio::MovementEventType::START;
enumTable["COMPLETE"]=cocostudio::MovementEventType::COMPLETE;
enumTable["LOOP_COMPLETE"]=cocostudio::MovementEventType::LOOP_COMPLETE;
lua["ccs"]["MovementEventType"]=lua.NewEnum(enumTable);
}
void RegisterLuaStudioArmatureAnimationAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ArmatureAnimation).name()] = sol::usertype_traits<cocostudio::ArmatureAnimation*>::metatable();
auto dep=lua.new_usertype<cocostudio::ArmatureAnimation>("deprecated.cocostudio::ArmatureAnimation");
dep[sol::base_classes]=sol::bases<cocostudio::ProcessBase,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ArmatureAnimation*>::metatable(),sol::usertype_traits<cocostudio::ProcessBase*>::metatable());
lua["ccs"]["ArmatureAnimation"]=mt;
mt["__new__"]=static_cast<cocostudio::ArmatureAnimation*(*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::create);
mt["Init"]=static_cast<bool(cocostudio::ArmatureAnimation::*)(cocostudio::Armature*)>(&cocostudio::ArmatureAnimation::init);
mt["SetSpeedScale"]=static_cast<void(cocostudio::ArmatureAnimation::*)(float)>(&cocostudio::ArmatureAnimation::setSpeedScale);
mt["set"]["SpeedScale"]=mt["SetSpeedScale"];
mt["GetSpeedScale"]=static_cast<float(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getSpeedScale);
mt["get"]["SpeedScale"]=mt["GetSpeedScale"];
mt["Play"]=sol::overload([](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1,int arg2){return obj->play(arg0,arg1,arg2);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0,int arg1){return obj->play(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::string& arg0){return obj->play(arg0);});
mt["PlayWithIndex"]=sol::overload([](cocostudio::ArmatureAnimation* obj,int arg0,int arg1,int arg2){return obj->playWithIndex(arg0,arg1,arg2);},[](cocostudio::ArmatureAnimation* obj,int arg0,int arg1){return obj->playWithIndex(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,int arg0){return obj->playWithIndex(arg0);});
mt["PlayWithNames"]=sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& arg0,int arg1,bool arg2){return obj->playWithNames(arg0,arg1,arg2);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& arg0,int arg1){return obj->playWithNames(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >& arg0){return obj->playWithNames(arg0);});
mt["PlayWithIndexes"]=sol::overload([](cocostudio::ArmatureAnimation* obj,const std::vector<int, std::allocator<int> >& arg0,int arg1,bool arg2){return obj->playWithIndexes(arg0,arg1,arg2);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int, std::allocator<int> >& arg0,int arg1){return obj->playWithIndexes(arg0,arg1);},[](cocostudio::ArmatureAnimation* obj,const std::vector<int, std::allocator<int> >& arg0){return obj->playWithIndexes(arg0);});
mt["GotoAndPlay"]=static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPlay);
mt["GotoAndPause"]=static_cast<void(cocostudio::ArmatureAnimation::*)(int)>(&cocostudio::ArmatureAnimation::gotoAndPause);
mt["GetMovementCount"]=static_cast<ssize_t(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getMovementCount);
mt["get"]["MovementCount"]=mt["GetMovementCount"];
mt["GetCurrentMovementID"]=static_cast<std::string(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getCurrentMovementID);
mt["get"]["CurrentMovementID"]=mt["GetCurrentMovementID"];
mt["SetMovementEventCallFunc"]=static_cast<void(cocostudio::ArmatureAnimation::*)(std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>)>(&cocostudio::ArmatureAnimation::setMovementEventCallFunc);
mt["set"]["MovementEventCallFunc"]=mt["SetMovementEventCallFunc"];
mt["SetFrameEventCallFunc"]=static_cast<void(cocostudio::ArmatureAnimation::*)(std::function<void (cocostudio::Bone *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, int, int)>)>(&cocostudio::ArmatureAnimation::setFrameEventCallFunc);
mt["set"]["FrameEventCallFunc"]=mt["SetFrameEventCallFunc"];
mt["SetAnimationData"]=static_cast<void(cocostudio::ArmatureAnimation::*)(cocostudio::AnimationData*)>(&cocostudio::ArmatureAnimation::setAnimationData);
mt["set"]["AnimationData"]=mt["SetAnimationData"];
mt["GetAnimationData"]=static_cast<cocostudio::AnimationData*(cocostudio::ArmatureAnimation::*)()const>(&cocostudio::ArmatureAnimation::getAnimationData);
mt["get"]["AnimationData"]=mt["GetAnimationData"];
mt["GetUserObject"]=static_cast<cocos2d::Ref*(cocostudio::ArmatureAnimation::*)()>(&cocostudio::ArmatureAnimation::getUserObject);
mt["get"]["UserObject"]=mt["GetUserObject"];
mt["SetUserObject"]=static_cast<void(cocostudio::ArmatureAnimation::*)(cocos2d::Ref*)>(&cocostudio::ArmatureAnimation::setUserObject);
mt["set"]["UserObject"]=mt["SetUserObject"];
}
void RegisterLuaStudioArmatureDataManagerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ArmatureDataManager).name()] = sol::usertype_traits<cocostudio::ArmatureDataManager*>::metatable();
auto dep=lua.new_usertype<cocostudio::ArmatureDataManager>("deprecated.cocostudio::ArmatureDataManager");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ArmatureDataManager*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ArmatureDataManager"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocostudio::ArmatureDataManager*(*)()>(&cocostudio::ArmatureDataManager::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocostudio::ArmatureDataManager::destroyInstance);
mt["Init"]=static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::init);
mt["AddArmatureData"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1,const std::string& arg2){return obj->addArmatureData(arg0,arg1,arg2);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::ArmatureData* arg1){return obj->addArmatureData(arg0,arg1);});
mt["GetArmatureData"]=static_cast<cocostudio::ArmatureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getArmatureData);
mt["RemoveArmatureData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureData);
mt["AddAnimationData"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1,const std::string& arg2){return obj->addAnimationData(arg0,arg1,arg2);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::AnimationData* arg1){return obj->addAnimationData(arg0,arg1);});
mt["GetAnimationData"]=static_cast<cocostudio::AnimationData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getAnimationData);
mt["RemoveAnimationData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeAnimationData);
mt["AddTextureData"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1,const std::string& arg2){return obj->addTextureData(arg0,arg1,arg2);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,cocostudio::TextureData* arg1){return obj->addTextureData(arg0,arg1);});
mt["GetTextureData"]=static_cast<cocostudio::TextureData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getTextureData);
mt["RemoveTextureData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeTextureData);
mt["AddArmatureFileInfo"]=sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addArmatureFileInfo));
mt["AddArmatureFileInfoAsync"]=sol::overload(static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,const std::string&,const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync),static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&,cocos2d::Ref*,cocos2d::SEL_SCHEDULE)>(&cocostudio::ArmatureDataManager::addArmatureFileInfoAsync));
mt["AddSpriteFrameFromFile"]=sol::overload([](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->addSpriteFrameFromFile(arg0,arg1,arg2);},[](cocostudio::ArmatureDataManager* obj,const std::string& arg0,const std::string& arg1){return obj->addSpriteFrameFromFile(arg0,arg1);});
mt["RemoveArmatureFileInfo"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::removeArmatureFileInfo);
mt["IsAutoLoadSpriteFile"]=static_cast<bool(cocostudio::ArmatureDataManager::*)()>(&cocostudio::ArmatureDataManager::isAutoLoadSpriteFile);
mt["get"]["AutoLoadSpriteFile"]=mt["IsAutoLoadSpriteFile"];
mt["GetArmatureDatas"]=static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::ArmatureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getArmatureDatas);
mt["get"]["ArmatureDatas"]=mt["GetArmatureDatas"];
mt["GetAnimationDatas"]=static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::AnimationData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getAnimationDatas);
mt["get"]["AnimationDatas"]=mt["GetAnimationDatas"];
mt["GetTextureDatas"]=static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::TextureData *>&(cocostudio::ArmatureDataManager::*)()const>(&cocostudio::ArmatureDataManager::getTextureDatas);
mt["get"]["TextureDatas"]=mt["GetTextureDatas"];
mt["AddRelativeData"]=static_cast<void(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::addRelativeData);
mt["GetRelativeData"]=static_cast<cocostudio::RelativeData*(cocostudio::ArmatureDataManager::*)(const std::string&)>(&cocostudio::ArmatureDataManager::getRelativeData);
mt["static"]["get"]["Instance"]=&cocostudio::ArmatureDataManager::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocostudio::ArmatureDataManager::destroyInstance();};
}
void RegisterLuaStudioArmatureAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::Armature).name()] = sol::usertype_traits<cocostudio::Armature*>::metatable();
auto dep=lua.new_usertype<cocostudio::Armature>("deprecated.cocostudio::Armature");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::Armature*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::BlendProtocol*>::metatable());
lua["ccs"]["Armature"]=mt;
mt["__new__"]=sol::overload(static_cast<cocostudio::Armature*(*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)(const std::string&)>(&cocostudio::Armature::create),static_cast<cocostudio::Armature*(*)()>(&cocostudio::Armature::create));
mt["Init"]=sol::overload(static_cast<bool(cocostudio::Armature::*)(const std::string&,cocostudio::Bone*)>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)(const std::string&)>(&cocostudio::Armature::init),static_cast<bool(cocostudio::Armature::*)()>(&cocostudio::Armature::init));
mt["AddBone"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::addBone);
mt["GetBone"]=static_cast<cocostudio::Bone*(cocostudio::Armature::*)(const std::string&)const>(&cocostudio::Armature::getBone);
mt["ChangeBoneParent"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,const std::string&)>(&cocostudio::Armature::changeBoneParent);
mt["RemoveBone"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*,bool)>(&cocostudio::Armature::removeBone);
mt["GetBoneDic"]=static_cast<const cocos2d::Map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocostudio::Bone *>&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBoneDic);
mt["get"]["BoneDic"]=mt["GetBoneDic"];
mt["GetBoneAtPoint"]=static_cast<cocostudio::Bone*(cocostudio::Armature::*)(float,float)const>(&cocostudio::Armature::getBoneAtPoint);
mt["UpdateOffsetPoint"]=static_cast<void(cocostudio::Armature::*)()>(&cocostudio::Armature::updateOffsetPoint);
mt["GetOffsetPoints"]=static_cast<const cocos2d::Vec2&(cocostudio::Armature::*)()const>(&cocostudio::Armature::getOffsetPoints);
mt["get"]["OffsetPoints"]=mt["GetOffsetPoints"];
mt["SetAnimation"]=static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureAnimation*)>(&cocostudio::Armature::setAnimation);
mt["set"]["Animation"]=mt["SetAnimation"];
mt["GetAnimation"]=static_cast<cocostudio::ArmatureAnimation*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getAnimation);
mt["get"]["Animation"]=mt["GetAnimation"];
mt["GetArmatureTransformDirty"]=static_cast<bool(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureTransformDirty);
mt["get"]["ArmatureTransformDirty"]=mt["GetArmatureTransformDirty"];
mt["SetArmatureData"]=static_cast<void(cocostudio::Armature::*)(cocostudio::ArmatureData*)>(&cocostudio::Armature::setArmatureData);
mt["set"]["ArmatureData"]=mt["SetArmatureData"];
mt["GetArmatureData"]=static_cast<cocostudio::ArmatureData*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getArmatureData);
mt["get"]["ArmatureData"]=mt["GetArmatureData"];
mt["SetParentBone"]=static_cast<void(cocostudio::Armature::*)(cocostudio::Bone*)>(&cocostudio::Armature::setParentBone);
mt["set"]["ParentBone"]=mt["SetParentBone"];
mt["GetParentBone"]=static_cast<cocostudio::Bone*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getParentBone);
mt["get"]["ParentBone"]=mt["GetParentBone"];
mt["SetVersion"]=static_cast<void(cocostudio::Armature::*)(float)>(&cocostudio::Armature::setVersion);
mt["set"]["Version"]=mt["SetVersion"];
mt["GetVersion"]=static_cast<float(cocostudio::Armature::*)()const>(&cocostudio::Armature::getVersion);
mt["get"]["Version"]=mt["GetVersion"];
mt["SetBatchNode"]=static_cast<void(cocostudio::Armature::*)(cocostudio::BatchNode*)>(&cocostudio::Armature::setBatchNode);
mt["set"]["BatchNode"]=mt["SetBatchNode"];
mt["GetBatchNode"]=static_cast<cocostudio::BatchNode*(cocostudio::Armature::*)()const>(&cocostudio::Armature::getBatchNode);
mt["get"]["BatchNode"]=mt["GetBatchNode"];
}
void RegisterLuaStudioSkinAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::Skin).name()] = sol::usertype_traits<cocostudio::Skin*>::metatable();
auto dep=lua.new_usertype<cocostudio::Skin>("deprecated.cocostudio::Skin");
dep[sol::base_classes]=sol::bases<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::Skin*>::metatable(),sol::usertype_traits<cocos2d::Sprite*>::metatable());
lua["ccs"]["Skin"]=mt;
mt["__new__"]=sol::overload(static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::create),static_cast<cocostudio::Skin*(*)()>(&cocostudio::Skin::create));
mt["static"]["CreateWithSpriteFrameName"]=static_cast<cocostudio::Skin*(*)(const std::string&)>(&cocostudio::Skin::createWithSpriteFrameName);
mt["InitWithSpriteFrameName"]=static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithSpriteFrameName);
mt["InitWithFile"]=static_cast<bool(cocostudio::Skin::*)(const std::string&)>(&cocostudio::Skin::initWithFile);
mt["UpdateArmatureTransform"]=static_cast<void(cocostudio::Skin::*)()>(&cocostudio::Skin::updateArmatureTransform);
mt["GetNodeToWorldTransformAR"]=static_cast<cocos2d::Mat4(cocostudio::Skin::*)()const>(&cocostudio::Skin::getNodeToWorldTransformAR);
mt["get"]["NodeToWorldTransformAR"]=mt["GetNodeToWorldTransformAR"];
mt["SetSkinData"]=static_cast<void(cocostudio::Skin::*)(const cocostudio::BaseData&)>(&cocostudio::Skin::setSkinData);
mt["set"]["SkinData"]=mt["SetSkinData"];
mt["GetSkinData"]=static_cast<const cocostudio::BaseData&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getSkinData);
mt["get"]["SkinData"]=mt["GetSkinData"];
mt["SetBone"]=static_cast<void(cocostudio::Skin::*)(cocostudio::Bone*)>(&cocostudio::Skin::setBone);
mt["set"]["Bone"]=mt["SetBone"];
mt["GetBone"]=static_cast<cocostudio::Bone*(cocostudio::Skin::*)()const>(&cocostudio::Skin::getBone);
mt["get"]["Bone"]=mt["GetBone"];
mt["GetDisplayName"]=static_cast<const std::string&(cocostudio::Skin::*)()const>(&cocostudio::Skin::getDisplayName);
mt["get"]["DisplayName"]=mt["GetDisplayName"];
}