#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioEventFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::EventFrame>("ccs","EventFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::EventFrame*(*)()>(&cocostudio::timeline::EventFrame::create));
mt.set_function("Init",static_cast<void(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::init));
mt.set_function("SetNode",static_cast<void(cocostudio::timeline::EventFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::EventFrame::setNode));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::EventFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::EventFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::clone));
mt.set_function("SetEvent",static_cast<void(cocostudio::timeline::EventFrame::*)(std::string)>(&cocostudio::timeline::EventFrame::setEvent));
mt.set_function("GetEvent",static_cast<std::string(cocostudio::timeline::EventFrame::*)()const>(&cocostudio::timeline::EventFrame::getEvent));
}
void RegisterLuaStudioZOrderFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ZOrderFrame>("ccs","ZOrderFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ZOrderFrame*(*)()>(&cocostudio::timeline::ZOrderFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::ZOrderFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::ZOrderFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::ZOrderFrame::*)()>(&cocostudio::timeline::ZOrderFrame::clone));
mt.set_function("SetZOrder",static_cast<void(cocostudio::timeline::ZOrderFrame::*)(int)>(&cocostudio::timeline::ZOrderFrame::setZOrder));
mt.set_function("GetZOrder",static_cast<int(cocostudio::timeline::ZOrderFrame::*)()const>(&cocostudio::timeline::ZOrderFrame::getZOrder));
}
void RegisterLuaStudioBlendFuncFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::BlendFuncFrame>("ccs","BlendFuncFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::BlendFuncFrame*(*)()>(&cocostudio::timeline::BlendFuncFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::BlendFuncFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::BlendFuncFrame::*)()>(&cocostudio::timeline::BlendFuncFrame::clone));
mt.set_function("GetBlendFunc",static_cast<cocos2d::BlendFunc(cocostudio::timeline::BlendFuncFrame::*)()const>(&cocostudio::timeline::BlendFuncFrame::getBlendFunc));
mt.set_function("SetBlendFunc",static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocos2d::BlendFunc)>(&cocostudio::timeline::BlendFuncFrame::setBlendFunc));
}
void RegisterLuaStudioPlayableFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::PlayableFrame>("ccs","PlayableFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::PlayableFrame*(*)()>(&cocostudio::timeline::PlayableFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::PlayableFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::PlayableFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::PlayableFrame::*)()>(&cocostudio::timeline::PlayableFrame::clone));
mt.set_function("GetPlayableAct",static_cast<std::string(cocostudio::timeline::PlayableFrame::*)()const>(&cocostudio::timeline::PlayableFrame::getPlayableAct));
mt.set_function("SetPlayableAct",static_cast<void(cocostudio::timeline::PlayableFrame::*)(std::string)>(&cocostudio::timeline::PlayableFrame::setPlayableAct));
mt["PLAYABLE_EXTENTION"]=sol::var(std::ref(cocostudio::timeline::PlayableFrame::PLAYABLE_EXTENTION));
}
void RegisterLuaStudioTimelineAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::Timeline>("ccs","Timeline",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::Timeline*(*)()>(&cocostudio::timeline::Timeline::create));
mt.set_function("GotoFrame",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::gotoFrame));
mt.set_function("StepToFrame",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::stepToFrame));
mt.set_function("GetFrames",static_cast<const cocos2d::Vector<cocostudio::timeline::Frame *>&(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getFrames));
mt.set_function("AddFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::addFrame));
mt.set_function("InsertFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Timeline::insertFrame));
mt.set_function("RemoveFrame",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::removeFrame));
mt.set_function("SetActionTag",static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::setActionTag));
mt.set_function("GetActionTag",static_cast<int(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTag));
mt.set_function("SetNode",static_cast<void(cocostudio::timeline::Timeline::*)(cocos2d::Node*)>(&cocostudio::timeline::Timeline::setNode));
mt.set_function("GetNode",static_cast<cocos2d::Node*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getNode));
mt.set_function("SetActionTimeline",static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::Timeline::setActionTimeline));
mt.set_function("GetActionTimeline",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTimeline));
mt.set_function("Clone",static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Timeline::*)()>(&cocostudio::timeline::Timeline::clone));
mt[sol::call_constructor]=sol::constructors<cocostudio::timeline::Timeline()>();
}
void RegisterLuaStudioActionTimelineDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineData>("ccs","ActionTimelineData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ActionTimelineData*(*)(int)>(&cocostudio::timeline::ActionTimelineData::create));
mt.set_function("SetActionTag",static_cast<void(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::setActionTag));
mt.set_function("GetActionTag",static_cast<int(cocostudio::timeline::ActionTimelineData::*)()const>(&cocostudio::timeline::ActionTimelineData::getActionTag));
}
void RegisterLuaStudioActionTimelineAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimeline>("ccs","ActionTimeline",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::PlayableProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ActionTimeline*(*)()>(&cocostudio::timeline::ActionTimeline::create));
mt.set_function("Play",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string,bool)>(&cocostudio::timeline::ActionTimeline::play));
mt.set_function("Init",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::init));
mt.set_function("GotoFrameAndPlay",sol::overload(static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay)));
mt.set_function("GotoFrameAndPause",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPause));
mt.set_function("Pause",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::pause));
mt.set_function("Resume",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::resume));
mt.set_function("IsPlaying",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isPlaying));
mt.set_function("SetTimeSpeed",static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::setTimeSpeed));
mt.set_function("GetTimeSpeed",static_cast<float(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimeSpeed));
mt.set_function("SetDuration",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setDuration));
mt.set_function("GetDuration",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getDuration));
mt.set_function("GetStartFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getStartFrame));
mt.set_function("GetEndFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getEndFrame));
mt.set_function("SetCurrentFrame",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setCurrentFrame));
mt.set_function("GetCurrentFrame",static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getCurrentFrame));
mt.set_function("AddTimeline",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::addTimeline));
mt.set_function("RemoveTimeline",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::removeTimeline));
mt.set_function("GetTimelines",static_cast<const cocos2d::Vector<cocostudio::timeline::Timeline *>&(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimelines));
mt.set_function("AddAnimationInfo",static_cast<void(cocostudio::timeline::ActionTimeline::*)(const cocostudio::timeline::AnimationInfo&)>(&cocostudio::timeline::ActionTimeline::addAnimationInfo));
mt.set_function("RemoveAnimationInfo",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string)>(&cocostudio::timeline::ActionTimeline::removeAnimationInfo));
mt.set_function("IsAnimationInfoExists",static_cast<bool(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::IsAnimationInfoExists));
mt.set_function("GetAnimationInfo",static_cast<const cocostudio::timeline::AnimationInfo&(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::getAnimationInfo));
mt.set_function("SetAnimationEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(const std::string,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setAnimationEndCallFunc));
mt.set_function("SetFrameEventCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void (cocostudio::timeline::Frame *)>)>(&cocostudio::timeline::ActionTimeline::setFrameEventCallFunc));
mt.set_function("ClearFrameEventCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEventCallFunc));
mt.set_function("SetLastFrameCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setLastFrameCallFunc));
mt.set_function("ClearLastFrameCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearLastFrameCallFunc));
mt.set_function("AddFrameEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::addFrameEndCallFunc));
mt.set_function("RemoveFrameEndCallFunc",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFunc));
mt.set_function("RemoveFrameEndCallFuncs",static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFuncs));
mt.set_function("ClearFrameEndCallFuncs",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEndCallFuncs));
mt.set_function("Clone",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::clone));
mt.set_function("Reverse",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::reverse));
mt.set_function("Step",static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::step));
mt.set_function("StartWithTarget",static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimeline::startWithTarget));
mt.set_function("IsDone",static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isDone));
mt.set_function("Start",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::start));
mt.set_function("Stop",static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::stop));
}
void RegisterLuaStudioActionTimelineNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineNode>("ccs","ActionTimelineNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::ActionTimelineNode*(*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::create));
mt.set_function("Init",sol::overload(static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::init),static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::init)));
mt.set_function("SetRoot",static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimelineNode::setRoot));
mt.set_function("GetRoot",static_cast<cocos2d::Node*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getRoot));
mt.set_function("SetActionTimeline",static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::setActionTimeline));
mt.set_function("GetActionTimeline",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getActionTimeline));
mt[sol::call_constructor]=sol::constructors<cocostudio::timeline::ActionTimelineNode()>();
}
void RegisterLuaStudioBoneNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::BoneNode>("ccs","BoneNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocostudio::timeline::BoneNode*(*)(int)>(&cocostudio::timeline::BoneNode::create),static_cast<cocostudio::timeline::BoneNode*(*)()>(&cocostudio::timeline::BoneNode::create)));
mt.set_function("AddChild",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,int)>(&cocostudio::timeline::BoneNode::addChild),static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,int,const std::string&)>(&cocostudio::timeline::BoneNode::addChild)));
mt.set_function("RemoveChild",static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Node*,bool)>(&cocostudio::timeline::BoneNode::removeChild));
mt.set_function("GetChildBones",sol::overload(static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getChildBones),static_cast<const cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getChildBones)));
mt.set_function("GetRootSkeletonNode",static_cast<cocostudio::timeline::SkeletonNode*(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getRootSkeletonNode));
mt.set_function("GetAllSubBones",static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubBones));
mt.set_function("AddSkin",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool,bool)>(&cocostudio::timeline::BoneNode::addSkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::addSkin)));
mt.set_function("DisplaySkin",sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&,bool)>(&cocostudio::timeline::BoneNode::displaySkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::displaySkin)));
mt.set_function("GetVisibleSkins",static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkins));
mt.set_function("GetSkins",sol::overload(static_cast<cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()>(&cocostudio::timeline::BoneNode::getSkins),static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getSkins)));
mt.set_function("GetAllSubSkins",static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubSkins));
mt.set_function("SetBlendFunc",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::BlendFunc&)>(&cocostudio::timeline::BoneNode::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBlendFunc));
mt.set_function("SetDebugDrawEnabled",static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setDebugDrawEnabled));
mt.set_function("IsDebugDrawEnabled",static_cast<bool(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::isDebugDrawEnabled));
mt.set_function("SetDebugDrawLength",static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawLength));
mt.set_function("GetDebugDrawLength",static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawLength));
mt.set_function("SetDebugDrawWidth",static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawWidth));
mt.set_function("GetDebugDrawWidth",static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawWidth));
mt.set_function("SetDebugDrawColor",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Color4F&)>(&cocostudio::timeline::BoneNode::setDebugDrawColor));
mt.set_function("GetDebugDrawColor",static_cast<cocos2d::Color4F(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawColor));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getBoundingBox));
mt.set_function("GetVisibleSkinsRect",static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkinsRect));
mt.set_function("Draw",static_cast<void(cocostudio::timeline::BoneNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocostudio::timeline::BoneNode::draw));
mt.set_function("SetLocalZOrder",static_cast<void(cocostudio::timeline::BoneNode::*)(int)>(&cocostudio::timeline::BoneNode::setLocalZOrder));
mt.set_function("SetName",static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&)>(&cocostudio::timeline::BoneNode::setName));
mt.set_function("SetVisible",static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setVisible));
mt.set_function("SetContentSize",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Size&)>(&cocostudio::timeline::BoneNode::setContentSize));
mt.set_function("SetAnchorPoint",static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Vec2&)>(&cocostudio::timeline::BoneNode::setAnchorPoint));
}
void RegisterLuaStudioSkeletonNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::SkeletonNode>("ccs","SkeletonNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::SkeletonNode*(*)()>(&cocostudio::timeline::SkeletonNode::create));
mt.set_function("GetBoneNode",static_cast<cocostudio::timeline::BoneNode*(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::getBoneNode));
mt.set_function("ChangeSkins",sol::overload(static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::changeSkins),static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&)>(&cocostudio::timeline::SkeletonNode::changeSkins)));
mt.set_function("AddSkinGroup",static_cast<void(cocostudio::timeline::SkeletonNode::*)(std::string,std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >)>(&cocostudio::timeline::SkeletonNode::addSkinGroup));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocostudio::timeline::SkeletonNode::*)()const>(&cocostudio::timeline::SkeletonNode::getBoundingBox));
}
