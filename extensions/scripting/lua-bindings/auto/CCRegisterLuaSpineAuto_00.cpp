#include "scripting/lua-bindings/auto/CCRegisterLuaSpineAuto.hpp"
#include "spine/spine-cocos2dx.h"
void RegisterLuaSpineSkeletonRendererAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<spine::SkeletonRenderer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("sp","SkeletonRenderer");
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getBoundingBox));
mt.set_function("onEnter",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::onEnter));
mt.set_function("onExit",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::onExit));
mt.set_function("getSkeleton",static_cast<spine::Skeleton*(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getSkeleton));
mt.set_function("setTimeScale",static_cast<void(spine::SkeletonRenderer::*)(float)>(&spine::SkeletonRenderer::setTimeScale));
mt.set_function("getTimeScale",static_cast<float(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getTimeScale));
mt.set_function("setDebugSlotsEnabled",static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugSlotsEnabled));
mt.set_function("getDebugSlotsEnabled",static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugSlotsEnabled));
mt.set_function("setDebugBonesEnabled",static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugBonesEnabled));
mt.set_function("getDebugBonesEnabled",static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugBonesEnabled));
mt.set_function("setDebugMeshesEnabled",static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugMeshesEnabled));
mt.set_function("getDebugMeshesEnabled",static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugMeshesEnabled));
mt.set_function("setDebugBoundingRectEnabled",static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setDebugBoundingRectEnabled));
mt.set_function("getDebugBoundingRectEnabled",static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getDebugBoundingRectEnabled));
mt.set_function("updateWorldTransform",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::updateWorldTransform));
mt.set_function("setToSetupPose",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setToSetupPose));
mt.set_function("setBonesToSetupPose",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setBonesToSetupPose));
mt.set_function("setSlotsToSetupPose",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::setSlotsToSetupPose));
mt.set_function("setSkin",sol::overload(static_cast<void(spine::SkeletonRenderer::*)(const char*)>(&spine::SkeletonRenderer::setSkin),static_cast<void(spine::SkeletonRenderer::*)(const std::string&)>(&spine::SkeletonRenderer::setSkin)));
mt.set_function("setTwoColorTint",static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setTwoColorTint));
mt.set_function("isTwoColorTint",static_cast<bool(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::isTwoColorTint));
mt.set_function("setVertexEffect",static_cast<void(spine::SkeletonRenderer::*)(spine::VertexEffect*)>(&spine::SkeletonRenderer::setVertexEffect));
mt.set_function("setSlotsRange",static_cast<void(spine::SkeletonRenderer::*)(int,int)>(&spine::SkeletonRenderer::setSlotsRange));
mt.set_function("setBlendFunc",static_cast<void(spine::SkeletonRenderer::*)(const cocos2d::BlendFunc&)>(&spine::SkeletonRenderer::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::getBlendFunc));
mt.set_function("setOpacityModifyRGB",static_cast<void(spine::SkeletonRenderer::*)(bool)>(&spine::SkeletonRenderer::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(spine::SkeletonRenderer::*)()const>(&spine::SkeletonRenderer::isOpacityModifyRGB));
mt.set_function("initWithSkeleton",sol::overload([](spine::SkeletonRenderer* obj,spine::Skeleton* arg0){return obj->initWithSkeleton(arg0);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1){return obj->initWithSkeleton(arg0,arg1);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1,bool arg2){return obj->initWithSkeleton(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1,bool arg2,bool arg3){return obj->initWithSkeleton(arg0,arg1,arg2,arg3);}));
mt.set_function("initWithData",sol::overload([](spine::SkeletonRenderer* obj,spine::SkeletonData* arg0){return obj->initWithData(arg0);},[](spine::SkeletonRenderer* obj,spine::SkeletonData* arg0,bool arg1){return obj->initWithData(arg0,arg1);}));
mt.set_function("initWithJsonFile",sol::overload([](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1){return obj->initWithJsonFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithJsonFile(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1){return obj->initWithJsonFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->initWithJsonFile(arg0,arg1,arg2);}));
mt.set_function("initWithBinaryFile",sol::overload([](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1){return obj->initWithBinaryFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithBinaryFile(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1){return obj->initWithBinaryFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->initWithBinaryFile(arg0,arg1,arg2);}));
mt.set_function("initialize",static_cast<void(spine::SkeletonRenderer::*)()>(&spine::SkeletonRenderer::initialize));
mt.set_function("new",static_cast<spine::SkeletonRenderer*(*)()>(&spine::SkeletonRenderer::create));
mt.set_function("createWithSkeleton",sol::overload([](spine::SkeletonRenderer* obj,spine::Skeleton* arg0){return obj->createWithSkeleton(arg0);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1){return obj->createWithSkeleton(arg0,arg1);},[](spine::SkeletonRenderer* obj,spine::Skeleton* arg0,bool arg1,bool arg2){return obj->createWithSkeleton(arg0,arg1,arg2);}));
mt.set_function("createWithFile",sol::overload([](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1){return obj->createWithFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithFile(arg0,arg1,arg2);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1){return obj->createWithFile(arg0,arg1);},[](spine::SkeletonRenderer* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->createWithFile(arg0,arg1,arg2);}));
}
void RegisterLuaSpineSkeletonAnimationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<spine::SkeletonAnimation,spine::SkeletonRenderer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("sp","SkeletonAnimation");
mt.set_function("setMix",static_cast<void(spine::SkeletonAnimation::*)(const std::string&,const std::string&,float)>(&spine::SkeletonAnimation::setMix));
mt.set_function("setEmptyAnimation",static_cast<spine::TrackEntry*(spine::SkeletonAnimation::*)(int,float)>(&spine::SkeletonAnimation::setEmptyAnimation));
mt.set_function("setEmptyAnimations",static_cast<void(spine::SkeletonAnimation::*)(float)>(&spine::SkeletonAnimation::setEmptyAnimations));
mt.set_function("addEmptyAnimation",sol::overload([](spine::SkeletonAnimation* obj,int arg0,float arg1){return obj->addEmptyAnimation(arg0,arg1);},[](spine::SkeletonAnimation* obj,int arg0,float arg1,float arg2){return obj->addEmptyAnimation(arg0,arg1,arg2);}));
mt.set_function("findAnimation",static_cast<spine::Animation*(spine::SkeletonAnimation::*)(const std::string&)const>(&spine::SkeletonAnimation::findAnimation));
mt.set_function("clearTracks",static_cast<void(spine::SkeletonAnimation::*)()>(&spine::SkeletonAnimation::clearTracks));
mt.set_function("clearTrack",sol::overload([](spine::SkeletonAnimation* obj){return obj->clearTrack();},[](spine::SkeletonAnimation* obj,int arg0){return obj->clearTrack(arg0);}));
mt.set_function("setStartListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setStartListener));
mt.set_function("setInterruptListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setInterruptListener));
mt.set_function("setEndListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setEndListener));
mt.set_function("setDisposeListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setDisposeListener));
mt.set_function("setCompleteListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setCompleteListener));
mt.set_function("setEventListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::TrackEntry *, spine::Event *)>&)>(&spine::SkeletonAnimation::setEventListener));
mt.set_function("setPreUpdateWorldTransformsListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::SkeletonAnimation *)>&)>(&spine::SkeletonAnimation::setPreUpdateWorldTransformsListener));
mt.set_function("setPostUpdateWorldTransformsListener",static_cast<void(spine::SkeletonAnimation::*)(const std::function<void (spine::SkeletonAnimation *)>&)>(&spine::SkeletonAnimation::setPostUpdateWorldTransformsListener));
mt.set_function("setTrackStartListener",static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackStartListener));
mt.set_function("setTrackInterruptListener",static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackInterruptListener));
mt.set_function("setTrackEndListener",static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackEndListener));
mt.set_function("setTrackDisposeListener",static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackDisposeListener));
mt.set_function("setTrackCompleteListener",static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *)>&)>(&spine::SkeletonAnimation::setTrackCompleteListener));
mt.set_function("setTrackEventListener",static_cast<void(spine::SkeletonAnimation::*)(spine::TrackEntry*,const std::function<void (spine::TrackEntry *, spine::Event *)>&)>(&spine::SkeletonAnimation::setTrackEventListener));
mt.set_function("setUpdateOnlyIfVisible",static_cast<void(spine::SkeletonAnimation::*)(bool)>(&spine::SkeletonAnimation::setUpdateOnlyIfVisible));
mt.set_function("initialize",static_cast<void(spine::SkeletonAnimation::*)()>(&spine::SkeletonAnimation::initialize));
mt.set_function("new",static_cast<spine::SkeletonAnimation*(*)()>(&spine::SkeletonAnimation::create));
mt.set_function("createWithJsonFile",sol::overload([](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1){return obj->createWithJsonFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithJsonFile(arg0,arg1,arg2);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1){return obj->createWithJsonFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->createWithJsonFile(arg0,arg1,arg2);}));
mt.set_function("createWithBinaryFile",sol::overload([](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1){return obj->createWithBinaryFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithBinaryFile(arg0,arg1,arg2);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1){return obj->createWithBinaryFile(arg0,arg1);},[](spine::SkeletonAnimation* obj,const std::string& arg0,spine::Atlas* arg1,float arg2){return obj->createWithBinaryFile(arg0,arg1,arg2);}));
}
