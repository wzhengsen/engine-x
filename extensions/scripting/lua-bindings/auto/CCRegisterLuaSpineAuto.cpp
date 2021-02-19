#include "scripting/lua-bindings/auto/CCRegisterLuaSpineAuto.hpp"
#include "spine/spine-cocos2dx.h"
static void RegisterLuaSpineSkeletonRenderer(cocos2d::Lua& lua){
auto mt=lua.NewUserType<spine::SkeletonRenderer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("sp","SkeletonRenderer");
mt["getBoundingBox"]=static_cast<cocos2d::Rect(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getBoundingBox);
mt["onEnter"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::onEnter);
mt["onExit"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::onExit);
mt["getSkeleton"]=static_cast<spine::Skeleton*(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getSkeleton);
mt["setTimeScale"]=static_cast<void(spine::SkeletonRenderer::*)(float)>(&spine::SkeletonRenderer::setTimeScale);
mt["getTimeScale"]=static_cast<float(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getTimeScale);
mt["setDebugSlotsEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugSlotsEnabled);
mt["getDebugSlotsEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugSlotsEnabled);
mt["setDebugBonesEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugBonesEnabled);
mt["getDebugBonesEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugBonesEnabled);
mt["setDebugMeshesEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugMeshesEnabled);
mt["getDebugMeshesEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugMeshesEnabled);
mt["setDebugBoundingRectEnabled"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugBoundingRectEnabled);
mt["getDebugBoundingRectEnabled"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugBoundingRectEnabled);
mt["updateWorldTransform"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::updateWorldTransform);
mt["setToSetupPose"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setToSetupPose);
mt["setBonesToSetupPose"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setBonesToSetupPose);
mt["setSlotsToSetupPose"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setSlotsToSetupPose);
mt["setSkin"]=sol::overload(static_cast<void(spine::SkeletonRenderer::*)(const char*)>(&spine::SkeletonRenderer::setSkin),static_cast<void(spine::SkeletonRenderer::*)(const std::string&)>(&spine::SkeletonRenderer::setSkin));
mt["setTwoColorTint"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setTwoColorTint);
mt["isTwoColorTint"]=static_cast<bool(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::isTwoColorTint);
mt["setVertexEffect"]=static_cast<void(spine::SkeletonRenderer::*)(spine::VertexEffect*)>(&spine::SkeletonRenderer::setVertexEffect);
mt["setSlotsRange"]=static_cast<void(spine::SkeletonRenderer::*)(int,int)>(&spine::SkeletonRenderer::setSlotsRange);
mt["setBlendFunc"]=static_cast<void(spine::SkeletonRenderer::*)(const cocos2d::BlendFunc&)>(&spine::SkeletonRenderer::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getBlendFunc);
mt["setOpacityModifyRGB"]=static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::isOpacityModifyRGB);
mt["initWithSkeleton"]=sol::overload([](spine::SkeletonRenderer* obj,spine::Skeleton* arg0){return obj->initWithSkeleton(arg0);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1){return obj->initWithSkeleton(arg0,arg1);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1,bool arg2){return obj->initWithSkeleton(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1,bool arg2,bool arg3){return obj->initWithSkeleton(arg0,arg1,arg2,arg3);});
mt["initWithData"]=sol::overload([](spine::SkeletonRenderer* obj,spine::SkeletonData* arg0){return obj->initWithData(arg0);},[](spine::SkeletonRenderer* obj,spine::SkeletonData* arg0,bool arg1){return obj->initWithData(arg0,arg1);});
mt["initWithJsonFile"]=sol::overload([](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1){return obj->initWithJsonFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithJsonFile(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1){return obj->initWithJsonFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->initWithJsonFile(arg0,arg1,arg2);});
mt["initWithBinaryFile"]=sol::overload([](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1){return obj->initWithBinaryFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithBinaryFile(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1){return obj->initWithBinaryFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->initWithBinaryFile(arg0,arg1,arg2);});
mt["initialize"]=static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::initialize);
mt["new"]=static_cast<spine::SkeletonRenderer*(*)()>(&spine::SkeletonRenderer::create);
mt["createWithSkeleton"]=sol::overload([](spine::SkeletonRenderer* obj,spine::Skeleton* arg0){return obj->createWithSkeleton(arg0);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1){return obj->createWithSkeleton(arg0,arg1);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1,bool arg2){return obj->createWithSkeleton(arg0,arg1,arg2);});
mt["createWithFile"]=sol::overload([](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1){return obj->createWithFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithFile(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1){return obj->createWithFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->createWithFile(arg0,arg1,arg2);});
}
static void RegisterLuaSpineSkeletonAnimation(cocos2d::Lua& lua){
auto mt=lua.NewUserType<spine::SkeletonAnimation,spine::SkeletonRenderer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("sp","SkeletonAnimation");
mt["setMix"]=static_cast<void(spine::SkeletonAnimation::*)(const std::string&,const std::string&,float)>(&spine::SkeletonAnimation::setMix);
mt["setEmptyAnimation"]=static_cast<spine::TrackEntry*(spine::SkeletonAnimation::*)(int,float)>(&spine::SkeletonAnimation::setEmptyAnimation);
mt["setEmptyAnimations"]=static_cast<void(spine::SkeletonAnimation::*)(float)>(&spine::SkeletonAnimation::setEmptyAnimations);
mt["addEmptyAnimation"]=sol::overload([](spine::SkeletonAnimation* obj,int arg0,float arg1){return obj->addEmptyAnimation(arg0,arg1);},[](spine::SkeletonAnimation* obj,int arg0,float arg1,float arg2){return obj->addEmptyAnimation(arg0,arg1,arg2);});
mt["findAnimation"]=static_cast<spine::Animation*(spine::SkeletonAnimation::*)(const std::string&)const>(&spine::SkeletonAnimation::findAnimation);
mt["clearTracks"]=static_cast<void(spine::SkeletonAnimation::*)()>(&spine::SkeletonAnimation::clearTracks);
mt["clearTrack"]=sol::overload([](spine::SkeletonAnimation* obj){return obj->clearTrack();},[](spine::SkeletonAnimation* obj,int arg0){return obj->clearTrack(arg0);});
mt["setStartListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setStartListener);
mt["setInterruptListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setInterruptListener);
mt["setEndListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setEndListener);
mt["setDisposeListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setDisposeListener);
mt["setCompleteListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setCompleteListener);
mt["setEventListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *, spine::Event *)>&)>(&spine::SkeletonAnimation::setEventListener);
mt["setPreUpdateWorldTransformsListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::SkeletonAnimation *)>&)>(&spine::SkeletonAnimation::setPreUpdateWorldTransformsListener);
mt["setPostUpdateWorldTransformsListener"]=static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::SkeletonAnimation *)>&)>(&spine::SkeletonAnimation::setPostUpdateWorldTransformsListener);
mt["setTrackStartListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackStartListener);
mt["setTrackInterruptListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackInterruptListener);
mt["setTrackEndListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackEndListener);
mt["setTrackDisposeListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackDisposeListener);
mt["setTrackCompleteListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackCompleteListener);
mt["setTrackEventListener"]=static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *, spine::Event *)>&)>(&spine::SkeletonAnimation::setTrackEventListener);
mt["setUpdateOnlyIfVisible"]=static_cast<void(spine::SkeletonAnimation::*)(bool)>(&spine::SkeletonAnimation::setUpdateOnlyIfVisible);
mt["initialize"]=static_cast<void(spine::SkeletonAnimation::*)()>(&spine::SkeletonAnimation::initialize);
mt["new"]=static_cast<spine::SkeletonAnimation*(*)()>(&spine::SkeletonAnimation::create);
mt["createWithJsonFile"]=sol::overload([](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1){return obj->createWithJsonFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithJsonFile(arg0,arg1,arg2);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1){return obj->createWithJsonFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->createWithJsonFile(arg0,arg1,arg2);});
mt["createWithBinaryFile"]=sol::overload([](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1){return obj->createWithBinaryFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithBinaryFile(arg0,arg1,arg2);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1){return obj->createWithBinaryFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->createWithBinaryFile(arg0,arg1,arg2);});
}
void RegisterLuaSpineAuto(cocos2d::Lua& lua) {
RegisterLuaSpineSkeletonRenderer(lua);
RegisterLuaSpineSkeletonAnimation(lua);
}
