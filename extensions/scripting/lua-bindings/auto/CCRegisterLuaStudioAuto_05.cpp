#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioBlendFuncFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::BlendFuncFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("BlendFuncFrame",false);
ns["BlendFuncFrame"] = mt;
lua["BlendFuncFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::BlendFuncFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::BlendFuncFrame::*)()>(&cocostudio::timeline::BlendFuncFrame::clone));
mt.set_function("getBlendFunc",static_cast<cocos2d::BlendFunc(cocostudio::timeline::BlendFuncFrame::*)()const>(&cocostudio::timeline::BlendFuncFrame::getBlendFunc));
mt.set_function("setBlendFunc",static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocos2d::BlendFunc)>(&cocostudio::timeline::BlendFuncFrame::setBlendFunc));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::BlendFuncFrame*(*)()>(&cocostudio::timeline::BlendFuncFrame::create));
}
void RegisterLuaStudioPlayableFrameAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::PlayableFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("PlayableFrame",false);
ns["PlayableFrame"] = mt;
lua["PlayableFrame"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::PlayableFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::PlayableFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PlayableFrame::*)()>(&cocostudio::timeline::PlayableFrame::clone));
mt.set_function("getPlayableAct",static_cast<std::string(cocostudio::timeline::PlayableFrame::*)()const>(&cocostudio::timeline::PlayableFrame::getPlayableAct));
mt.set_function("setPlayableAct",static_cast<void(cocostudio::timeline::PlayableFrame::*)(std::string)>(&cocostudio::timeline::PlayableFrame::setPlayableAct));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::PlayableFrame*(*)()>(&cocostudio::timeline::PlayableFrame::create));
}
void RegisterLuaStudioTimelineAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::Timeline,cocos2d::Ref,cocos2d::LuaObject>("Timeline",false);
ns["Timeline"] = mt;
lua["Timeline"] = sol::nil;
mt.set_function("gotoFrame",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::gotoFrame));
mt.set_function("stepToFrame",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::stepToFrame));
mt.set_function("getFrames",static_cast<const cocos2d::Vector<cocostudio::timeline::Frame *>&(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getFrames));
mt.set_function("addFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::addFrame));
mt.set_function("insertFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Timeline::insertFrame));
mt.set_function("removeFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::removeFrame));
mt.set_function("setActionTag",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::setActionTag));
mt.set_function("getActionTag",static_cast<int(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTag));
mt.set_function("setNode",static_cast<void(cocostudio::timeline::Timeline::*)(cocos2d::Node*)>(&cocostudio::timeline::Timeline::setNode));
mt.set_function("getNode",static_cast<cocos2d::Node*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getNode));
mt.set_function("setActionTimeline",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::Timeline::setActionTimeline));
mt.set_function("getActionTimeline",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTimeline));
mt.set_function("clone",static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Timeline::*)()>(&cocostudio::timeline::Timeline::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::Timeline*(*)()>(&cocostudio::timeline::Timeline::create));
}
void RegisterLuaStudioActionTimelineDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineData,cocos2d::Ref,cocos2d::LuaObject>("ActionTimelineData",false);
ns["ActionTimelineData"] = mt;
lua["ActionTimelineData"] = sol::nil;
mt.set_function("setActionTag",static_cast<void(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::setActionTag));
mt.set_function("getActionTag",static_cast<int(cocostudio::timeline::ActionTimelineData::*)()const>(&cocostudio::timeline::ActionTimelineData::getActionTag));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ActionTimelineData*(*)(int)>(&cocostudio::timeline::ActionTimelineData::create));
}
void RegisterLuaStudioActionTimelineAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimeline,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject,cocos2d::Clonable,cocos2d::PlayableProtocol>("ActionTimeline",false);
ns["ActionTimeline"] = mt;
lua["ActionTimeline"] = sol::nil;
mt.set_function("play",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string,bool)>(&cocostudio::timeline::ActionTimeline::play));
mt.set_function("init",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::init));
mt.set_function("gotoFrameAndPlay",sol::overload(static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay)));
mt.set_function("gotoFrameAndPause",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPause));
mt.set_function("pause",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::pause));
mt.set_function("resume",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::resume));
mt.set_function("isPlaying",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isPlaying));
mt.set_function("setTimeSpeed",static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::setTimeSpeed));
mt.set_function("getTimeSpeed",static_cast<float(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimeSpeed));
mt.set_function("setDuration",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setDuration));
mt.set_function("getDuration",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getDuration));
mt.set_function("getStartFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getStartFrame));
mt.set_function("getEndFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getEndFrame));
mt.set_function("setCurrentFrame",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setCurrentFrame));
mt.set_function("getCurrentFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getCurrentFrame));
mt.set_function("addTimeline",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::addTimeline));
mt.set_function("removeTimeline",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::removeTimeline));
mt.set_function("getTimelines",static_cast<const cocos2d::Vector<cocostudio::timeline::Timeline *>&(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimelines));
mt.set_function("addAnimationInfo",static_cast<void(cocostudio::timeline::ActionTimeline::*)(const cocostudio::timeline::AnimationInfo&)>(&cocostudio::timeline::ActionTimeline::addAnimationInfo));
mt.set_function("removeAnimationInfo",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string)>(&cocostudio::timeline::ActionTimeline::removeAnimationInfo));
mt.set_function("IsAnimationInfoExists",static_cast<bool(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::IsAnimationInfoExists));
mt.set_function("getAnimationInfo",static_cast<const cocostudio::timeline::AnimationInfo&(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::getAnimationInfo));
mt.set_function("setAnimationEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(const std::string,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setAnimationEndCallFunc));
mt.set_function("setFrameEventCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void (cocostudio::timeline::Frame *)>)>(&cocostudio::timeline::ActionTimeline::setFrameEventCallFunc));
mt.set_function("clearFrameEventCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEventCallFunc));
mt.set_function("setLastFrameCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setLastFrameCallFunc));
mt.set_function("clearLastFrameCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearLastFrameCallFunc));
mt.set_function("addFrameEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::addFrameEndCallFunc));
mt.set_function("removeFrameEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFunc));
mt.set_function("removeFrameEndCallFuncs",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFuncs));
mt.set_function("clearFrameEndCallFuncs",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEndCallFuncs));
mt.set_function("clone",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::clone));
mt.set_function("reverse",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::reverse));
mt.set_function("step",static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::step));
mt.set_function("startWithTarget",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimeline::startWithTarget));
mt.set_function("isDone",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isDone));
mt.set_function("start",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::start));
mt.set_function("stop",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::stop));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ActionTimeline*(*)()>(&cocostudio::timeline::ActionTimeline::create));
}
void RegisterLuaStudioActionTimelineNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ActionTimelineNode",false);
ns["ActionTimelineNode"] = mt;
lua["ActionTimelineNode"] = sol::nil;
mt.set_function("init",sol::overload(static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::init),static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::init)));
mt.set_function("setRoot",static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimelineNode::setRoot));
mt.set_function("getRoot",static_cast<cocos2d::Node*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getRoot));
mt.set_function("setActionTimeline",static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::setActionTimeline));
mt.set_function("getActionTimeline",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getActionTimeline));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ActionTimelineNode*(*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::create));
}
void RegisterLuaStudioBoneNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("BoneNode",false);
ns["BoneNode"] = mt;
lua["BoneNode"] = sol::nil;
mt.set_function("addChild",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,int)>(&cocostudio::timeline::BoneNode::addChild),static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::timeline::BoneNode::addChild)));
mt.set_function("removeChild",static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,bool)>(&cocostudio::timeline::BoneNode::removeChild));
mt.set_function("getChildBones",sol::overload(static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getChildBones),static_cast<const cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getChildBones)));
mt.set_function("getRootSkeletonNode",static_cast<cocostudio::timeline::SkeletonNode*(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getRootSkeletonNode));
mt.set_function("getAllSubBones",static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubBones));
mt.set_function("addSkin",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool,bool)>(&cocostudio::timeline::BoneNode::addSkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::addSkin)));
mt.set_function("displaySkin",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&,bool)>(&cocostudio::timeline::BoneNode::displaySkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::displaySkin)));
mt.set_function("getVisibleSkins",static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkins));
mt.set_function("getSkins",sol::overload(static_cast<cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getSkins),static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getSkins)));
mt.set_function("getAllSubSkins",static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubSkins));
mt.set_function("setBlendFunc",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::BlendFunc&)>(&cocostudio::timeline::BoneNode::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBlendFunc));
mt.set_function("setDebugDrawEnabled",static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setDebugDrawEnabled));
mt.set_function("isDebugDrawEnabled",static_cast<bool(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::isDebugDrawEnabled));
mt.set_function("setDebugDrawLength",static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawLength));
mt.set_function("getDebugDrawLength",static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawLength));
mt.set_function("setDebugDrawWidth",static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawWidth));
mt.set_function("getDebugDrawWidth",static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawWidth));
mt.set_function("setDebugDrawColor",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Color4F&)>(&cocostudio::timeline::BoneNode::setDebugDrawColor));
mt.set_function("getDebugDrawColor",static_cast<cocos2d::Color4F(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawColor));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBoundingBox));
mt.set_function("getVisibleSkinsRect",static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkinsRect));
mt.set_function("draw",static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::timeline::BoneNode::draw));
mt.set_function("setLocalZOrder",static_cast<void(cocostudio::timeline::BoneNode::*)(int)>(&cocostudio::timeline::BoneNode::setLocalZOrder));
mt.set_function("setName",static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&)>(&cocostudio::timeline::BoneNode::setName));
mt.set_function("setVisible",static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setVisible));
mt.set_function("setContentSize",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Size&)>(&cocostudio::timeline::BoneNode::setContentSize));
mt.set_function("setAnchorPoint",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Vec2&)>(&cocostudio::timeline::BoneNode::setAnchorPoint));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocostudio::timeline::BoneNode*(*)(int)>(&cocostudio::timeline::BoneNode::create),static_cast<cocostudio::timeline::BoneNode*(*)()>(&cocostudio::timeline::BoneNode::create)));
}
void RegisterLuaStudioSkeletonNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::timeline::SkeletonNode,cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("SkeletonNode",false);
ns["SkeletonNode"] = mt;
lua["SkeletonNode"] = sol::nil;
mt.set_function("getBoneNode",static_cast<cocostudio::timeline::BoneNode*(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::getBoneNode));
mt.set_function("changeSkins",sol::overload(static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::changeSkins),static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::map<std::string, std::string>&)>(&cocostudio::timeline::SkeletonNode::changeSkins)));
mt.set_function("addSkinGroup",static_cast<void(cocostudio::timeline::SkeletonNode::*)(std::string,std::map<std::string, std::string>)>(&cocostudio::timeline::SkeletonNode::addSkinGroup));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocostudio::timeline::SkeletonNode::*)()const>(&cocostudio::timeline::SkeletonNode::getBoundingBox));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::SkeletonNode*(*)()>(&cocostudio::timeline::SkeletonNode::create));
}
void RegisterLuaStudioComExtensionDataAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccs"];
auto mt=lua.NewUserType<cocostudio::ComExtensionData,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ComExtensionData",false);
ns["ComExtensionData"] = mt;
lua["ComExtensionData"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onEnter));
mt.set_function("onExit",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onExit));
mt.set_function("onAdd",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onAdd));
mt.set_function("onRemove",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onRemove));
mt.set_function("init",static_cast<bool(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::init));
mt.set_function("setCustomProperty",static_cast<void(cocostudio::ComExtensionData::*)(const std::string&)>(&cocostudio::ComExtensionData::setCustomProperty));
mt.set_function("getCustomProperty",static_cast<std::string(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getCustomProperty));
mt.set_function("setActionTag",static_cast<void(cocostudio::ComExtensionData::*)(int)>(&cocostudio::ComExtensionData::setActionTag));
mt.set_function("getActionTag",static_cast<int(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getActionTag));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComExtensionData::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ComExtensionData*(*)()>(&cocostudio::ComExtensionData::create));
}
