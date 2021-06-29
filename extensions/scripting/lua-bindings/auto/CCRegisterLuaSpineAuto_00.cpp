#include "scripting/lua-bindings/auto/CCRegisterLuaSpineAuto.hpp"
#include "spine/spine-cocos2dx.h"
void RegisterLuaSpineSkeletonRendererAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(spine::SkeletonRenderer).name()] = sol::usertype_traits<spine::SkeletonRenderer*>::metatable();
auto dep=lua.new_usertype<spine::SkeletonRenderer>("deprecated.spine::SkeletonRenderer");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<spine::SkeletonRenderer*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::BlendProtocol*>::metatable());
lua["sp"]["SkeletonRenderer"]=mt;
mt["__new__"]=static_cast<spine::SkeletonRenderer*(*)()>(&spine::SkeletonRenderer::create);
mt["static"]["CreateWithSkeleton"]=sol::overload([](spine::Skeleton* arg0,bool arg1,bool arg2){return spine::SkeletonRenderer::createWithSkeleton(arg0,arg1,arg2);},[](spine::Skeleton* arg0,bool arg1){return spine::SkeletonRenderer::createWithSkeleton(arg0,arg1);},[](spine::Skeleton* arg0){return spine::SkeletonRenderer::createWithSkeleton(arg0);});
mt["static"]["CreateWithData"]=sol::overload([](spine::SkeletonData* arg0,bool arg1){return spine::SkeletonRenderer::createWithData(arg0,arg1);},[](spine::SkeletonData* arg0){return spine::SkeletonRenderer::createWithData(arg0);});
mt["static"]["CreateWithFile"]=sol::overload([](const std::string& arg0,const std::string& arg1,float arg2){return spine::SkeletonRenderer::createWithFile(arg0,arg1,arg2);},[](const std::string& arg0,spine::Atlas* arg1,float arg2){return spine::SkeletonRenderer::createWithFile(arg0,arg1,arg2);},[](const std::string& arg0,const std::string& arg1){return spine::SkeletonRenderer::createWithFile(arg0,arg1);},[](const std::string& arg0,spine::Atlas* arg1){return spine::SkeletonRenderer::createWithFile(arg0,arg1);});
mt["GetSkeleton"]=static_cast<spine::Skeleton*(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getSkeleton);
mt["get"]["Skeleton"]=mt["GetSkeleton"];
mt["SetTimeScale"]=static_cast<void(spine::SkeletonRenderer::*)(float)>(&spine::SkeletonRenderer::setTimeScale);
mt["set"]["TimeScale"]=mt["SetTimeScale"];
mt["GetTimeScale"]=static_cast<float(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getTimeScale);
mt["get"]["TimeScale"]=mt["GetTimeScale"];
mt["SetDebugSlotsEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugSlotsEnabled);
mt["set"]["DebugSlotsEnabled"]=mt["SetDebugSlotsEnabled"];
mt["GetDebugSlotsEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugSlotsEnabled);
mt["get"]["DebugSlotsEnabled"]=mt["GetDebugSlotsEnabled"];
mt["SetDebugBonesEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugBonesEnabled);
mt["set"]["DebugBonesEnabled"]=mt["SetDebugBonesEnabled"];
mt["GetDebugBonesEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugBonesEnabled);
mt["get"]["DebugBonesEnabled"]=mt["GetDebugBonesEnabled"];
mt["SetDebugMeshesEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugMeshesEnabled);
mt["set"]["DebugMeshesEnabled"]=mt["SetDebugMeshesEnabled"];
mt["GetDebugMeshesEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugMeshesEnabled);
mt["get"]["DebugMeshesEnabled"]=mt["GetDebugMeshesEnabled"];
mt["SetDebugBoundingRectEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugBoundingRectEnabled);
mt["set"]["DebugBoundingRectEnabled"]=mt["SetDebugBoundingRectEnabled"];
mt["GetDebugBoundingRectEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugBoundingRectEnabled);
mt["get"]["DebugBoundingRectEnabled"]=mt["GetDebugBoundingRectEnabled"];
mt["UpdateWorldTransform"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::updateWorldTransform);
mt["SetToSetupPose"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setToSetupPose);
mt["SetBonesToSetupPose"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setBonesToSetupPose);
mt["SetSlotsToSetupPose"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setSlotsToSetupPose);
mt["FindBone"]=static_cast<spine::Bone*(spine::SkeletonRenderer::*)(const std::string&)const>(&spine::SkeletonRenderer::findBone);
mt["FindSlot"]=static_cast<spine::Slot*(spine::SkeletonRenderer::*)(const std::string&)const>(&spine::SkeletonRenderer::findSlot);
mt["SetSkin"]=sol::overload(static_cast<void(spine::SkeletonRenderer::*)(const char*)>(&spine::SkeletonRenderer::setSkin),static_cast<void(spine::SkeletonRenderer::*)(const std::string&)>(&spine::SkeletonRenderer::setSkin));
mt["set"]["Skin"]=mt["SetSkin"];
mt["GetAttachment"]=static_cast<spine::Attachment*(spine::SkeletonRenderer::*)(const std::string&,const std::string&)const>(&spine::SkeletonRenderer::getAttachment);
mt["SetAttachment"]=sol::overload(static_cast<bool(spine::SkeletonRenderer::*)(const std::string&,const char*)>(&spine::SkeletonRenderer::setAttachment),static_cast<bool(spine::SkeletonRenderer::*)(const std::string&,const std::string&)>(&spine::SkeletonRenderer::setAttachment));
mt["SetTwoColorTint"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setTwoColorTint);
mt["set"]["TwoColorTint"]=mt["SetTwoColorTint"];
mt["IsTwoColorTint"]=static_cast<bool(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::isTwoColorTint);
mt["get"]["TwoColorTint"]=mt["IsTwoColorTint"];
mt["SetVertexEffect"]=static_cast<void(spine::SkeletonRenderer::*)(spine::VertexEffect*)>(&spine::SkeletonRenderer::setVertexEffect);
mt["set"]["VertexEffect"]=mt["SetVertexEffect"];
mt["SetSlotsRange"]=static_cast<void(spine::SkeletonRenderer::*)(int,int)>(&spine::SkeletonRenderer::setSlotsRange);
}
void RegisterLuaSpineSkeletonAnimationAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(spine::SkeletonAnimation).name()] = sol::usertype_traits<spine::SkeletonAnimation*>::metatable();
auto dep=lua.new_usertype<spine::SkeletonAnimation>("deprecated.spine::SkeletonAnimation");
dep[sol::base_classes]=sol::bases<spine::SkeletonRenderer,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<spine::SkeletonAnimation*>::metatable(),sol::usertype_traits<spine::SkeletonRenderer*>::metatable());
lua["sp"]["SkeletonAnimation"]=mt;
mt["__new__"]=static_cast<spine::SkeletonAnimation*(*)()>(&spine::SkeletonAnimation::create);
mt["static"]["CreateWithData"]=sol::overload([](spine::SkeletonData* arg0,bool arg1){return spine::SkeletonAnimation::createWithData(arg0,arg1);},[](spine::SkeletonData* arg0){return spine::SkeletonAnimation::createWithData(arg0);});
mt["static"]["CreateWithJsonFile"]=sol::overload([](const std::string& arg0,const std::string& arg1,float arg2){return spine::SkeletonAnimation::createWithJsonFile(arg0,arg1,arg2);},[](const std::string& arg0,spine::Atlas* arg1,float arg2){return spine::SkeletonAnimation::createWithJsonFile(arg0,arg1,arg2);},[](const std::string& arg0,const std::string& arg1){return spine::SkeletonAnimation::createWithJsonFile(arg0,arg1);},[](const std::string& arg0,spine::Atlas* arg1){return spine::SkeletonAnimation::createWithJsonFile(arg0,arg1);});
mt["static"]["CreateWithBinaryFile"]=sol::overload([](const std::string& arg0,const std::string& arg1,float arg2){return spine::SkeletonAnimation::createWithBinaryFile(arg0,arg1,arg2);},[](const std::string& arg0,spine::Atlas* arg1,float arg2){return spine::SkeletonAnimation::createWithBinaryFile(arg0,arg1,arg2);},[](const std::string& arg0,const std::string& arg1){return spine::SkeletonAnimation::createWithBinaryFile(arg0,arg1);},[](const std::string& arg0,spine::Atlas* arg1){return spine::SkeletonAnimation::createWithBinaryFile(arg0,arg1);});
mt["SetAnimationStateData"]=static_cast<void(spine::SkeletonAnimation::*)(spine::AnimationStateData*)>(&spine::SkeletonAnimation::setAnimationStateData);
mt["set"]["AnimationStateData"]=mt["SetAnimationStateData"];
mt["SetMix"]=static_cast<void(spine::SkeletonAnimation::*)(const std::string&,const std::string&,float)>(&spine::SkeletonAnimation::setMix);
mt["SetAnimation"]=static_cast<spine::TrackEntry*(spine::SkeletonAnimation::*)(int,const std::string&,bool)>(&spine::SkeletonAnimation::setAnimation);
mt["AddAnimation"]=sol::overload([](spine::SkeletonAnimation* obj,int arg0,const std::string& arg1,bool arg2,float arg3){return obj->addAnimation(arg0,arg1,arg2,arg3);},[](spine::SkeletonAnimation* obj,int arg0,const std::string& arg1,bool arg2){return obj->addAnimation(arg0,arg1,arg2);});
mt["SetEmptyAnimation"]=static_cast<spine::TrackEntry*(spine::SkeletonAnimation::*)(int,float)>(&spine::SkeletonAnimation::setEmptyAnimation);
mt["SetEmptyAnimations"]=static_cast<void(spine::SkeletonAnimation::*)(float)>(&spine::SkeletonAnimation::setEmptyAnimations);
mt["set"]["EmptyAnimations"]=mt["SetEmptyAnimations"];
mt["AddEmptyAnimation"]=sol::overload([](spine::SkeletonAnimation* obj,int arg0,float arg1,float arg2){return obj->addEmptyAnimation(arg0,arg1,arg2);},[](spine::SkeletonAnimation* obj,int arg0,float arg1){return obj->addEmptyAnimation(arg0,arg1);});
mt["FindAnimation"]=static_cast<spine::Animation*(spine::SkeletonAnimation::*)(const std::string&)const>(&spine::SkeletonAnimation::findAnimation);
mt["GetCurrent"]=sol::overload([](spine::SkeletonAnimation* obj,int arg0){return obj->getCurrent(arg0);},[](spine::SkeletonAnimation* obj){return obj->getCurrent();});
mt["get"]["Current"]=mt["GetCurrent"];
mt["ClearTracks"]=static_cast<void(spine::SkeletonAnimation::*)()>(&spine::SkeletonAnimation::clearTracks);
mt["ClearTrack"]=sol::overload([](spine::SkeletonAnimation* obj,int arg0){return obj->clearTrack(arg0);},[](spine::SkeletonAnimation* obj){return obj->clearTrack();});
mt["SetStartListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::StartListener&)>(&spine::SkeletonAnimation::setStartListener);
mt["set"]["StartListener"]=mt["SetStartListener"];
mt["SetInterruptListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::InterruptListener&)>(&spine::SkeletonAnimation::setInterruptListener);
mt["set"]["InterruptListener"]=mt["SetInterruptListener"];
mt["SetEndListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::EndListener&)>(&spine::SkeletonAnimation::setEndListener);
mt["set"]["EndListener"]=mt["SetEndListener"];
mt["SetDisposeListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::DisposeListener&)>(&spine::SkeletonAnimation::setDisposeListener);
mt["set"]["DisposeListener"]=mt["SetDisposeListener"];
mt["SetCompleteListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::CompleteListener&)>(&spine::SkeletonAnimation::setCompleteListener);
mt["set"]["CompleteListener"]=mt["SetCompleteListener"];
mt["SetEventListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::EventListener&)>(&spine::SkeletonAnimation::setEventListener);
mt["set"]["EventListener"]=mt["SetEventListener"];
mt["SetPreUpdateWorldTransformsListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::UpdateWorldTransformsListener&)>(&spine::SkeletonAnimation::setPreUpdateWorldTransformsListener);
mt["set"]["PreUpdateWorldTransformsListener"]=mt["SetPreUpdateWorldTransformsListener"];
mt["SetPostUpdateWorldTransformsListener"]=static_cast<void(spine::SkeletonAnimation::*)(const spine::UpdateWorldTransformsListener&)>(&spine::SkeletonAnimation::setPostUpdateWorldTransformsListener);
mt["set"]["PostUpdateWorldTransformsListener"]=mt["SetPostUpdateWorldTransformsListener"];
mt["SetTrackStartListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const spine::StartListener&)>(&spine::SkeletonAnimation::setTrackStartListener);
mt["SetTrackInterruptListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const spine::InterruptListener&)>(&spine::SkeletonAnimation::setTrackInterruptListener);
mt["SetTrackEndListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const spine::EndListener&)>(&spine::SkeletonAnimation::setTrackEndListener);
mt["SetTrackDisposeListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const spine::DisposeListener&)>(&spine::SkeletonAnimation::setTrackDisposeListener);
mt["SetTrackCompleteListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const spine::CompleteListener&)>(&spine::SkeletonAnimation::setTrackCompleteListener);
mt["SetTrackEventListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const spine::EventListener&)>(&spine::SkeletonAnimation::setTrackEventListener);
mt["OnAnimationStateEvent"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,spine::EventType,spine::Event*)>(&spine::SkeletonAnimation::onAnimationStateEvent);
mt["OnTrackEntryEvent"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,spine::EventType,spine::Event*)>(&spine::SkeletonAnimation::onTrackEntryEvent);
mt["GetState"]=static_cast<spine::AnimationState*(spine::SkeletonAnimation::*)()const>(&spine::SkeletonAnimation::getState);
mt["get"]["State"]=mt["GetState"];
mt["SetUpdateOnlyIfVisible"]=static_cast<void(spine::SkeletonAnimation::*)(bool)>(&spine::SkeletonAnimation::setUpdateOnlyIfVisible);
mt["set"]["UpdateOnlyIfVisible"]=mt["SetUpdateOnlyIfVisible"];
}