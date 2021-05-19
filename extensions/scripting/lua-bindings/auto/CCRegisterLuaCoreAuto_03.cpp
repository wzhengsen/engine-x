#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
void RegisterLuaCoreAutoPolygonAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AutoPolygon>("cc","AutoPolygon",false);
mt.set_function("Trace",sol::overload([](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0){return obj->trace(arg0);},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0,float arg1){return obj->trace(arg0,arg1);}));
mt.set_function("Reduce",sol::overload([](cocos2d::AutoPolygon* obj,const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >& arg0,const cocos2d::Rect& arg1){return obj->reduce(arg0,arg1);},[](cocos2d::AutoPolygon* obj,const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >& arg0,const cocos2d::Rect& arg1,float arg2){return obj->reduce(arg0,arg1,arg2);}));
mt.set_function("Expand",static_cast<std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >(cocos2d::AutoPolygon::*)(const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&,const cocos2d::Rect&,float)>(&cocos2d::AutoPolygon::expand));
mt.set_function("Triangulate",static_cast<cocos2d::TrianglesCommand::Triangles(cocos2d::AutoPolygon::*)(const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&)>(&cocos2d::AutoPolygon::triangulate));
mt.set_function("CalculateUV",static_cast<void(cocos2d::AutoPolygon::*)(const cocos2d::Rect&,cocos2d::V3F_C4B_T2F*,ssize_t)>(&cocos2d::AutoPolygon::calculateUV));
mt.set_function("GenerateTriangles",sol::overload([](cocos2d::AutoPolygon* obj){return obj->generateTriangles();},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0){return obj->generateTriangles(arg0);},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0,float arg1){return obj->generateTriangles(arg0,arg1);},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0,float arg1,float arg2){return obj->generateTriangles(arg0,arg1,arg2);}));
mt.set_function("GeneratePolygon",sol::overload([](cocos2d::AutoPolygon* obj,const std::string& arg0){return obj->generatePolygon(arg0);},[](cocos2d::AutoPolygon* obj,const std::string& arg0,const cocos2d::Rect& arg1){return obj->generatePolygon(arg0,arg1);},[](cocos2d::AutoPolygon* obj,const std::string& arg0,const cocos2d::Rect& arg1,float arg2){return obj->generatePolygon(arg0,arg1,arg2);},[](cocos2d::AutoPolygon* obj,const std::string& arg0,const cocos2d::Rect& arg1,float arg2,float arg3){return obj->generatePolygon(arg0,arg1,arg2,arg3);}));
mt[sol::call_constructor]=sol::constructors<cocos2d::AutoPolygon(const std::string&)>();
}
void RegisterLuaCoreSpriteFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpriteFrame>("cc","SpriteFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::create),static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::create)));
mt.set_function("CreateWithTexture",sol::overload(static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::createWithTexture),static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::createWithTexture)));
mt.set_function("GetRectInPixels",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRectInPixels));
mt.set_function("SetRectInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRectInPixels));
mt.set_function("IsRotated",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::isRotated));
mt.set_function("SetRotated",static_cast<void(cocos2d::SpriteFrame::*)(bool)>(&cocos2d::SpriteFrame::setRotated));
mt.set_function("GetRect",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRect));
mt.set_function("SetRect",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRect));
mt.set_function("GetCenterRect",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getCenterRect));
mt.set_function("SetCenterRectInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setCenterRectInPixels));
mt.set_function("HasCenterRect",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasCenterRect));
mt.set_function("GetOffsetInPixels",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffsetInPixels));
mt.set_function("SetOffsetInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffsetInPixels));
mt.set_function("GetOriginalSizeInPixels",static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSizeInPixels));
mt.set_function("SetOriginalSizeInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSizeInPixels));
mt.set_function("GetOriginalSize",static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSize));
mt.set_function("SetOriginalSize",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSize));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::SpriteFrame::*)()>(&cocos2d::SpriteFrame::getTexture));
mt.set_function("SetTexture",static_cast<void(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrame::setTexture));
mt.set_function("GetOffset",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffset));
mt.set_function("SetOffset",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffset));
mt.set_function("GetAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getAnchorPoint));
mt.set_function("SetAnchorPoint",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setAnchorPoint));
mt.set_function("HasAnchorPoint",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasAnchorPoint));
mt.set_function("Clone",static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::clone));
mt.set_function("SetPolygonInfo",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::PolygonInfo&)>(&cocos2d::SpriteFrame::setPolygonInfo));
mt.set_function("GetPolygonInfo",static_cast<const cocos2d::PolygonInfo&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getPolygonInfo));
mt.set_function("HasPolygonInfo",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasPolygonInfo));
}
void RegisterLuaCoreAnimationFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AnimationFrame>("cc","AnimationFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::AnimationFrame*(*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::create));
mt.set_function("GetSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getSpriteFrame));
mt.set_function("SetSpriteFrame",static_cast<void(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*)>(&cocos2d::AnimationFrame::setSpriteFrame));
mt.set_function("GetDelayUnits",static_cast<float(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getDelayUnits));
mt.set_function("SetDelayUnits",static_cast<void(cocos2d::AnimationFrame::*)(float)>(&cocos2d::AnimationFrame::setDelayUnits));
mt.set_function("GetUserInfo",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()>(&cocos2d::AnimationFrame::getUserInfo),static_cast<const cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getUserInfo)));
mt.set_function("SetUserInfo",static_cast<void(cocos2d::AnimationFrame::*)(const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::setUserInfo));
mt.set_function("Clone",static_cast<cocos2d::AnimationFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::clone));
}
void RegisterLuaCoreAnimationAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation>("cc","Animation",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1){return obj->create(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1,unsigned int arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::Animation*(*)()>(&cocos2d::Animation::create)));
mt.set_function("CreateWithSpriteFrames",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->createWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->createWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->createWithSpriteFrames(arg0,arg1,arg2);}));
mt.set_function("AddSpriteFrame",static_cast<void(cocos2d::Animation::*)(cocos2d::SpriteFrame*)>(&cocos2d::Animation::addSpriteFrame));
mt.set_function("AddSpriteFrameWithFile",static_cast<void(cocos2d::Animation::*)(const std::string&)>(&cocos2d::Animation::addSpriteFrameWithFile));
mt.set_function("AddSpriteFrameWithTexture",static_cast<void(cocos2d::Animation::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Animation::addSpriteFrameWithTexture));
mt.set_function("GetTotalDelayUnits",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getTotalDelayUnits));
mt.set_function("SetDelayPerUnit",static_cast<void(cocos2d::Animation::*)(float)>(&cocos2d::Animation::setDelayPerUnit));
mt.set_function("GetDelayPerUnit",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDelayPerUnit));
mt.set_function("GetDuration",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDuration));
mt.set_function("GetFrames",static_cast<const cocos2d::Vector<cocos2d::AnimationFrame *>&(cocos2d::Animation::*)()const>(&cocos2d::Animation::getFrames));
mt.set_function("SetFrames",static_cast<void(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&)>(&cocos2d::Animation::setFrames));
mt.set_function("GetRestoreOriginalFrame",static_cast<bool(cocos2d::Animation::*)()const>(&cocos2d::Animation::getRestoreOriginalFrame));
mt.set_function("SetRestoreOriginalFrame",static_cast<void(cocos2d::Animation::*)(bool)>(&cocos2d::Animation::setRestoreOriginalFrame));
mt.set_function("GetLoops",static_cast<unsigned int(cocos2d::Animation::*)()const>(&cocos2d::Animation::getLoops));
mt.set_function("SetLoops",static_cast<void(cocos2d::Animation::*)(unsigned int)>(&cocos2d::Animation::setLoops));
mt.set_function("Clone",static_cast<cocos2d::Animation*(cocos2d::Animation::*)()const>(&cocos2d::Animation::clone));
}
void RegisterLuaCoreActionIntervalAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionInterval>("cc","ActionInterval",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetElapsed",static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getElapsed));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::setAmplitudeRate));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getAmplitudeRate));
mt.set_function("IsDone",static_cast<bool(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::isDone));
mt.set_function("Step",static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::step));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ActionInterval::*)(cocos2d::Node*)>(&cocos2d::ActionInterval::startWithTarget));
mt.set_function("Reverse",static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::reverse));
mt.set_function("Clone",static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::clone));
}
void RegisterLuaCoreSequenceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sequence>("cc","Sequence",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Sequence*(*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Sequence::create));
mt.set_function("CreateWithVariableList",static_cast<cocos2d::Sequence*(*)(cocos2d::FiniteTimeAction*,va_list)>(&cocos2d::Sequence::createWithVariableList));
mt.set_function("CreateWithTwoActions",static_cast<cocos2d::Sequence*(*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Sequence::createWithTwoActions));
mt.set_function("Clone",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::clone));
mt.set_function("Reverse",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Sequence::*)(cocos2d::Node*)>(&cocos2d::Sequence::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Sequence::*)()>(&cocos2d::Sequence::stop));
mt.set_function("IsDone",static_cast<bool(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::isDone));
mt.set_function("Update",static_cast<void(cocos2d::Sequence::*)(float)>(&cocos2d::Sequence::update));
}
void RegisterLuaCoreRepeatAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Repeat>("cc","Repeat",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Repeat*(*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::create));
mt.set_function("SetInnerAction",static_cast<void(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*)>(&cocos2d::Repeat::setInnerAction));
mt.set_function("GetInnerAction",static_cast<cocos2d::FiniteTimeAction*(cocos2d::Repeat::*)()>(&cocos2d::Repeat::getInnerAction));
mt.set_function("Clone",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::clone));
mt.set_function("Reverse",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Repeat::*)(cocos2d::Node*)>(&cocos2d::Repeat::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Repeat::*)()>(&cocos2d::Repeat::stop));
mt.set_function("Update",static_cast<void(cocos2d::Repeat::*)(float)>(&cocos2d::Repeat::update));
mt.set_function("IsDone",static_cast<bool(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::isDone));
}
void RegisterLuaCoreRepeatForeverAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RepeatForever>("cc","RepeatForever",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::RepeatForever*(*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::create));
mt.set_function("SetInnerAction",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::setInnerAction));
mt.set_function("GetInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::RepeatForever::*)()>(&cocos2d::RepeatForever::getInnerAction));
mt.set_function("Clone",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::clone));
mt.set_function("Reverse",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::Node*)>(&cocos2d::RepeatForever::startWithTarget));
mt.set_function("Step",static_cast<void(cocos2d::RepeatForever::*)(float)>(&cocos2d::RepeatForever::step));
mt.set_function("IsDone",static_cast<bool(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::isDone));
}
void RegisterLuaCoreSpawnAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Spawn>("cc","Spawn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateWithVariableList",static_cast<cocos2d::Spawn*(*)(cocos2d::FiniteTimeAction*,va_list)>(&cocos2d::Spawn::createWithVariableList));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Spawn*(*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Spawn::create));
mt.set_function("CreateWithTwoActions",static_cast<cocos2d::Spawn*(*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Spawn::createWithTwoActions));
mt.set_function("Clone",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::clone));
mt.set_function("Reverse",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Spawn::*)(cocos2d::Node*)>(&cocos2d::Spawn::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Spawn::*)()>(&cocos2d::Spawn::stop));
mt.set_function("Update",static_cast<void(cocos2d::Spawn::*)(float)>(&cocos2d::Spawn::update));
}
void RegisterLuaCoreRotateToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RotateTo>("cc","RotateTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::RotateTo*(*)(float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::create)));
mt.set_function("Clone",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::RotateTo::*)(cocos2d::Node*)>(&cocos2d::RotateTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::RotateTo::*)(float)>(&cocos2d::RotateTo::update));
}
