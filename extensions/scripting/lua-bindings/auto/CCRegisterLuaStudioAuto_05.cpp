#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioEventFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::EventFrame).name()] = sol::usertype_traits<cocostudio::timeline::EventFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::EventFrame>("deprecated.cocostudio::timeline::EventFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::EventFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["EventFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::EventFrame*(*)()>(&cocostudio::timeline::EventFrame::create);
mt["Init"]=static_cast<void(cocostudio::timeline::EventFrame::*)()>(&cocostudio::timeline::EventFrame::init);
mt["SetEvent"]=static_cast<void(cocostudio::timeline::EventFrame::*)(std::string)>(&cocostudio::timeline::EventFrame::setEvent);
mt["set"]["Event"]=mt["SetEvent"];
mt["GetEvent"]=static_cast<std::string(cocostudio::timeline::EventFrame::*)()const>(&cocostudio::timeline::EventFrame::getEvent);
mt["get"]["Event"]=mt["GetEvent"];
}
void RegisterLuaStudioZOrderFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ZOrderFrame).name()] = sol::usertype_traits<cocostudio::timeline::ZOrderFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ZOrderFrame>("deprecated.cocostudio::timeline::ZOrderFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ZOrderFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["ZOrderFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::ZOrderFrame*(*)()>(&cocostudio::timeline::ZOrderFrame::create);
mt["SetZOrder"]=static_cast<void(cocostudio::timeline::ZOrderFrame::*)(int)>(&cocostudio::timeline::ZOrderFrame::setZOrder);
mt["set"]["ZOrder"]=mt["SetZOrder"];
mt["GetZOrder"]=static_cast<int(cocostudio::timeline::ZOrderFrame::*)()const>(&cocostudio::timeline::ZOrderFrame::getZOrder);
mt["get"]["ZOrder"]=mt["GetZOrder"];
}
void RegisterLuaStudioBlendFuncFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::BlendFuncFrame).name()] = sol::usertype_traits<cocostudio::timeline::BlendFuncFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::BlendFuncFrame>("deprecated.cocostudio::timeline::BlendFuncFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::BlendFuncFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["BlendFuncFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::BlendFuncFrame*(*)()>(&cocostudio::timeline::BlendFuncFrame::create);
mt["GetBlendFunc"]=static_cast<cocos2d::BlendFunc(cocostudio::timeline::BlendFuncFrame::*)()const>(&cocostudio::timeline::BlendFuncFrame::getBlendFunc);
mt["get"]["BlendFunc"]=mt["GetBlendFunc"];
mt["SetBlendFunc"]=static_cast<void(cocostudio::timeline::BlendFuncFrame::*)(cocos2d::BlendFunc)>(&cocostudio::timeline::BlendFuncFrame::setBlendFunc);
mt["set"]["BlendFunc"]=mt["SetBlendFunc"];
}
void RegisterLuaStudioPlayableFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::PlayableFrame).name()] = sol::usertype_traits<cocostudio::timeline::PlayableFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::PlayableFrame>("deprecated.cocostudio::timeline::PlayableFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::PlayableFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["PlayableFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::PlayableFrame*(*)()>(&cocostudio::timeline::PlayableFrame::create);
mt["GetPlayableAct"]=static_cast<std::string(cocostudio::timeline::PlayableFrame::*)()const>(&cocostudio::timeline::PlayableFrame::getPlayableAct);
mt["get"]["PlayableAct"]=mt["GetPlayableAct"];
mt["SetPlayableAct"]=static_cast<void(cocostudio::timeline::PlayableFrame::*)(std::string)>(&cocostudio::timeline::PlayableFrame::setPlayableAct);
mt["set"]["PlayableAct"]=mt["SetPlayableAct"];
mt["static"]["get"]["PLAYABLE_EXTENTION"]=[]()->const std::string&{return cocostudio::timeline::PlayableFrame::PLAYABLE_EXTENTION;};
}
void RegisterLuaStudioTimelineAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::Timeline).name()] = sol::usertype_traits<cocostudio::timeline::Timeline*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::Timeline>("deprecated.cocostudio::timeline::Timeline");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::Timeline*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["Timeline"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::Timeline*(*)()>(&cocostudio::timeline::Timeline::create);
mt["GotoFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::gotoFrame);
mt["StepToFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::stepToFrame);
mt["GetFrames"]=static_cast<const cocos2d::Vector<cocostudio::timeline::Frame *>&(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getFrames);
mt["get"]["Frames"]=mt["GetFrames"];
mt["AddFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::addFrame);
mt["InsertFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Timeline::insertFrame);
mt["RemoveFrame"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::Frame*)>(&cocostudio::timeline::Timeline::removeFrame);
mt["SetActionTag"]=static_cast<void(cocostudio::timeline::Timeline::*)(int)>(&cocostudio::timeline::Timeline::setActionTag);
mt["set"]["ActionTag"]=mt["SetActionTag"];
mt["GetActionTag"]=static_cast<int(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTag);
mt["get"]["ActionTag"]=mt["GetActionTag"];
mt["SetNode"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocos2d::Node*)>(&cocostudio::timeline::Timeline::setNode);
mt["set"]["Node"]=mt["SetNode"];
mt["GetNode"]=static_cast<cocos2d::Node*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getNode);
mt["get"]["Node"]=mt["GetNode"];
mt["SetActionTimeline"]=static_cast<void(cocostudio::timeline::Timeline::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::Timeline::setActionTimeline);
mt["set"]["ActionTimeline"]=mt["SetActionTimeline"];
mt["GetActionTimeline"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::Timeline::*)()const>(&cocostudio::timeline::Timeline::getActionTimeline);
mt["get"]["ActionTimeline"]=mt["GetActionTimeline"];
mt["Clone"]=static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Timeline::*)()>(&cocostudio::timeline::Timeline::clone);
}
void RegisterLuaStudioActionTimelineDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ActionTimelineData).name()] = sol::usertype_traits<cocostudio::timeline::ActionTimelineData*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ActionTimelineData>("deprecated.cocostudio::timeline::ActionTimelineData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ActionTimelineData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ActionTimelineData"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::ActionTimelineData*(*)(int)>(&cocostudio::timeline::ActionTimelineData::create);
mt["SetActionTag"]=static_cast<void(cocostudio::timeline::ActionTimelineData::*)(int)>(&cocostudio::timeline::ActionTimelineData::setActionTag);
mt["set"]["ActionTag"]=mt["SetActionTag"];
mt["GetActionTag"]=static_cast<int(cocostudio::timeline::ActionTimelineData::*)()const>(&cocostudio::timeline::ActionTimelineData::getActionTag);
mt["get"]["ActionTag"]=mt["GetActionTag"];
}
void RegisterLuaStudioActionTimelineAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ActionTimeline).name()] = sol::usertype_traits<cocostudio::timeline::ActionTimeline*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ActionTimeline>("deprecated.cocostudio::timeline::ActionTimeline");
dep[sol::base_classes]=sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ActionTimeline*>::metatable(),sol::usertype_traits<cocos2d::Action*>::metatable(),sol::usertype_traits<cocos2d::PlayableProtocol*>::metatable());
lua["ccs"]["ActionTimeline"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::ActionTimeline*(*)()>(&cocostudio::timeline::ActionTimeline::create);
mt["Play"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string,bool)>(&cocostudio::timeline::ActionTimeline::play);
mt["Init"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::init);
mt["GotoFrameAndPlay"]=sol::overload(static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,bool)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay),static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPlay));
mt["GotoFrameAndPause"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::gotoFrameAndPause);
mt["Pause"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::pause);
mt["Resume"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::resume);
mt["IsPlaying"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::isPlaying);
mt["get"]["Playing"]=mt["IsPlaying"];
mt["SetTimeSpeed"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(float)>(&cocostudio::timeline::ActionTimeline::setTimeSpeed);
mt["set"]["TimeSpeed"]=mt["SetTimeSpeed"];
mt["GetTimeSpeed"]=static_cast<float(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimeSpeed);
mt["get"]["TimeSpeed"]=mt["GetTimeSpeed"];
mt["SetDuration"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setDuration);
mt["set"]["Duration"]=mt["SetDuration"];
mt["GetDuration"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getDuration);
mt["get"]["Duration"]=mt["GetDuration"];
mt["GetStartFrame"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getStartFrame);
mt["get"]["StartFrame"]=mt["GetStartFrame"];
mt["GetEndFrame"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getEndFrame);
mt["get"]["EndFrame"]=mt["GetEndFrame"];
mt["SetCurrentFrame"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::setCurrentFrame);
mt["set"]["CurrentFrame"]=mt["SetCurrentFrame"];
mt["GetCurrentFrame"]=static_cast<int(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getCurrentFrame);
mt["get"]["CurrentFrame"]=mt["GetCurrentFrame"];
mt["AddTimeline"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::addTimeline);
mt["RemoveTimeline"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::ActionTimeline::removeTimeline);
mt["GetTimelines"]=static_cast<const cocos2d::Vector<cocostudio::timeline::Timeline *>&(cocostudio::timeline::ActionTimeline::*)()const>(&cocostudio::timeline::ActionTimeline::getTimelines);
mt["get"]["Timelines"]=mt["GetTimelines"];
mt["AddAnimationInfo"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(const cocostudio::timeline::AnimationInfo&)>(&cocostudio::timeline::ActionTimeline::addAnimationInfo);
mt["RemoveAnimationInfo"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::string)>(&cocostudio::timeline::ActionTimeline::removeAnimationInfo);
mt["IsAnimationInfoExists"]=static_cast<bool(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::IsAnimationInfoExists);
mt["GetAnimationInfo"]=static_cast<const cocostudio::timeline::AnimationInfo&(cocostudio::timeline::ActionTimeline::*)(const std::string&)>(&cocostudio::timeline::ActionTimeline::getAnimationInfo);
mt["SetAnimationEndCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(const std::string,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setAnimationEndCallFunc);
mt["SetFrameEventCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void (cocostudio::timeline::Frame *)>)>(&cocostudio::timeline::ActionTimeline::setFrameEventCallFunc);
mt["set"]["FrameEventCallFunc"]=mt["SetFrameEventCallFunc"];
mt["ClearFrameEventCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEventCallFunc);
mt["SetLastFrameCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::setLastFrameCallFunc);
mt["set"]["LastFrameCallFunc"]=mt["SetLastFrameCallFunc"];
mt["ClearLastFrameCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearLastFrameCallFunc);
mt["AddFrameEndCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&,std::function<void ()>)>(&cocostudio::timeline::ActionTimeline::addFrameEndCallFunc);
mt["RemoveFrameEndCallFunc"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int,const std::string&)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFunc);
mt["RemoveFrameEndCallFuncs"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)(int)>(&cocostudio::timeline::ActionTimeline::removeFrameEndCallFuncs);
mt["ClearFrameEndCallFuncs"]=static_cast<void(cocostudio::timeline::ActionTimeline::*)()>(&cocostudio::timeline::ActionTimeline::clearFrameEndCallFuncs);
}
void RegisterLuaStudioActionTimelineNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ActionTimelineNode).name()] = sol::usertype_traits<cocostudio::timeline::ActionTimelineNode*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ActionTimelineNode>("deprecated.cocostudio::timeline::ActionTimelineNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ActionTimelineNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["ccs"]["ActionTimelineNode"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::ActionTimelineNode*(*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::create);
mt["Init"]=sol::overload(static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*,cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::init),static_cast<bool(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::init));
mt["SetRoot"]=static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocos2d::Node*)>(&cocostudio::timeline::ActionTimelineNode::setRoot);
mt["set"]["Root"]=mt["SetRoot"];
mt["GetRoot"]=static_cast<cocos2d::Node*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getRoot);
mt["get"]["Root"]=mt["GetRoot"];
mt["SetActionTimeline"]=static_cast<void(cocostudio::timeline::ActionTimelineNode::*)(cocostudio::timeline::ActionTimeline*)>(&cocostudio::timeline::ActionTimelineNode::setActionTimeline);
mt["set"]["ActionTimeline"]=mt["SetActionTimeline"];
mt["GetActionTimeline"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineNode::*)()>(&cocostudio::timeline::ActionTimelineNode::getActionTimeline);
mt["get"]["ActionTimeline"]=mt["GetActionTimeline"];
}
void RegisterLuaStudioBoneNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::BoneNode).name()] = sol::usertype_traits<cocostudio::timeline::BoneNode*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::BoneNode>("deprecated.cocostudio::timeline::BoneNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::BoneNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::BlendProtocol*>::metatable());
lua["ccs"]["BoneNode"]=mt;
mt["__new__"]=sol::overload(static_cast<cocostudio::timeline::BoneNode*(*)(int)>(&cocostudio::timeline::BoneNode::create),static_cast<cocostudio::timeline::BoneNode*(*)()>(&cocostudio::timeline::BoneNode::create));
mt["GetChildBones"]=static_cast<const cocos2d::Vector<cocostudio::timeline::BoneNode *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getChildBones);
mt["get"]["ChildBones"]=mt["GetChildBones"];
mt["GetRootSkeletonNode"]=static_cast<cocostudio::timeline::SkeletonNode*(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getRootSkeletonNode);
mt["get"]["RootSkeletonNode"]=mt["GetRootSkeletonNode"];
mt["GetAllSubBones"]=static_cast<cocos2d::Vector<cocostudio::timeline::BoneNode *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubBones);
mt["get"]["AllSubBones"]=mt["GetAllSubBones"];
mt["AddSkin"]=sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool,bool)>(&cocostudio::timeline::BoneNode::addSkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::addSkin));
mt["DisplaySkin"]=sol::overload(static_cast<void(cocostudio::timeline::BoneNode::*)(const std::string&,bool)>(&cocostudio::timeline::BoneNode::displaySkin),static_cast<void(cocostudio::timeline::BoneNode::*)(cocostudio::timeline::SkinNode*,bool)>(&cocostudio::timeline::BoneNode::displaySkin));
mt["GetVisibleSkins"]=static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkins);
mt["get"]["VisibleSkins"]=mt["GetVisibleSkins"];
mt["GetSkins"]=static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getSkins);
mt["get"]["Skins"]=mt["GetSkins"];
mt["GetAllSubSkins"]=static_cast<cocos2d::Vector<cocos2d::Node *>(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getAllSubSkins);
mt["get"]["AllSubSkins"]=mt["GetAllSubSkins"];
mt["SetDebugDrawEnabled"]=static_cast<void(cocostudio::timeline::BoneNode::*)(bool)>(&cocostudio::timeline::BoneNode::setDebugDrawEnabled);
mt["set"]["DebugDrawEnabled"]=mt["SetDebugDrawEnabled"];
mt["IsDebugDrawEnabled"]=static_cast<bool(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::isDebugDrawEnabled);
mt["get"]["DebugDrawEnabled"]=mt["IsDebugDrawEnabled"];
mt["SetDebugDrawLength"]=static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawLength);
mt["set"]["DebugDrawLength"]=mt["SetDebugDrawLength"];
mt["GetDebugDrawLength"]=static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawLength);
mt["get"]["DebugDrawLength"]=mt["GetDebugDrawLength"];
mt["SetDebugDrawWidth"]=static_cast<void(cocostudio::timeline::BoneNode::*)(float)>(&cocostudio::timeline::BoneNode::setDebugDrawWidth);
mt["set"]["DebugDrawWidth"]=mt["SetDebugDrawWidth"];
mt["GetDebugDrawWidth"]=static_cast<float(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawWidth);
mt["get"]["DebugDrawWidth"]=mt["GetDebugDrawWidth"];
mt["SetDebugDrawColor"]=static_cast<void(cocostudio::timeline::BoneNode::*)(const cocos2d::Color4F&)>(&cocostudio::timeline::BoneNode::setDebugDrawColor);
mt["set"]["DebugDrawColor"]=mt["SetDebugDrawColor"];
mt["GetDebugDrawColor"]=static_cast<cocos2d::Color4F(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getDebugDrawColor);
mt["get"]["DebugDrawColor"]=mt["GetDebugDrawColor"];
mt["GetVisibleSkinsRect"]=static_cast<cocos2d::Rect(cocostudio::timeline::BoneNode::*)()const>(&cocostudio::timeline::BoneNode::getVisibleSkinsRect);
mt["get"]["VisibleSkinsRect"]=mt["GetVisibleSkinsRect"];
mt["SetLocalZOrder"]=static_cast<void(cocostudio::timeline::BoneNode::*)(int)>(&cocostudio::timeline::BoneNode::setLocalZOrder);
mt["set"]["LocalZOrder"]=mt["SetLocalZOrder"];
}
void RegisterLuaStudioSkeletonNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::SkeletonNode).name()] = sol::usertype_traits<cocostudio::timeline::SkeletonNode*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::SkeletonNode>("deprecated.cocostudio::timeline::SkeletonNode");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::BoneNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::SkeletonNode*>::metatable(),sol::usertype_traits<cocostudio::timeline::BoneNode*>::metatable());
lua["ccs"]["SkeletonNode"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::SkeletonNode*(*)()>(&cocostudio::timeline::SkeletonNode::create);
mt["GetBoneNode"]=static_cast<cocostudio::timeline::BoneNode*(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::getBoneNode);
mt["ChangeSkins"]=sol::overload(static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::string&)>(&cocostudio::timeline::SkeletonNode::changeSkins),static_cast<void(cocostudio::timeline::SkeletonNode::*)(const std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&)>(&cocostudio::timeline::SkeletonNode::changeSkins));
mt["AddSkinGroup"]=static_cast<void(cocostudio::timeline::SkeletonNode::*)(std::string,std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >)>(&cocostudio::timeline::SkeletonNode::addSkinGroup);
}
