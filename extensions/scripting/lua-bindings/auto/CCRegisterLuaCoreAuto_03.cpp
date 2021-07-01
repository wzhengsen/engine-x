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
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AutoPolygon).name()] = sol::usertype_traits<cocos2d::AutoPolygon*>::metatable();
auto dep=lua.new_usertype<cocos2d::AutoPolygon>("deprecated.cocos2d::AutoPolygon");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AutoPolygon*>::metatable());
lua["cc"]["AutoPolygon"]=mt;
mt["Trace"]=sol::overload([](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0,float arg1){return obj->trace(arg0,arg1);},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0){return obj->trace(arg0);});
mt["Reduce"]=sol::overload([](cocos2d::AutoPolygon* obj,const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >& arg0,const cocos2d::Rect& arg1,float arg2){return obj->reduce(arg0,arg1,arg2);},[](cocos2d::AutoPolygon* obj,const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >& arg0,const cocos2d::Rect& arg1){return obj->reduce(arg0,arg1);});
mt["Expand"]=static_cast<std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >(cocos2d::AutoPolygon::*)(const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&,const cocos2d::Rect&,float)>(&cocos2d::AutoPolygon::expand);
mt["Triangulate"]=static_cast<cocos2d::TrianglesCommand::Triangles(cocos2d::AutoPolygon::*)(const std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >&)>(&cocos2d::AutoPolygon::triangulate);
mt["CalculateUV"]=static_cast<void(cocos2d::AutoPolygon::*)(const cocos2d::Rect&,cocos2d::V3F_C4B_T2F*,ssize_t)>(&cocos2d::AutoPolygon::calculateUV);
mt["GenerateTriangles"]=sol::overload([](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0,float arg1,float arg2){return obj->generateTriangles(arg0,arg1,arg2);},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0,float arg1){return obj->generateTriangles(arg0,arg1);},[](cocos2d::AutoPolygon* obj,const cocos2d::Rect& arg0){return obj->generateTriangles(arg0);},[](cocos2d::AutoPolygon* obj){return obj->generateTriangles();});
mt["static"]["GeneratePolygon"]=sol::overload([](const std::string& arg0,const cocos2d::Rect& arg1,float arg2,float arg3){return cocos2d::AutoPolygon::generatePolygon(arg0,arg1,arg2,arg3);},[](const std::string& arg0,const cocos2d::Rect& arg1,float arg2){return cocos2d::AutoPolygon::generatePolygon(arg0,arg1,arg2);},[](const std::string& arg0,const cocos2d::Rect& arg1){return cocos2d::AutoPolygon::generatePolygon(arg0,arg1);},[](const std::string& arg0){return cocos2d::AutoPolygon::generatePolygon(arg0);});
}
void RegisterLuaCoreSpriteFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SpriteFrame).name()] = sol::usertype_traits<cocos2d::SpriteFrame*>::metatable();
auto dep=lua.new_usertype<cocos2d::SpriteFrame>("deprecated.cocos2d::SpriteFrame");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SpriteFrame*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["SpriteFrame"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::create),static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::create));
mt["static"]["CreateWithTexture"]=sol::overload(static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::createWithTexture),static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::createWithTexture));
mt["GetRectInPixels"]=static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRectInPixels);
mt["get"]["RectInPixels"]=mt["GetRectInPixels"];
mt["SetRectInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRectInPixels);
mt["set"]["RectInPixels"]=mt["SetRectInPixels"];
mt["IsRotated"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::isRotated);
mt["get"]["Rotated"]=mt["IsRotated"];
mt["SetRotated"]=static_cast<void(cocos2d::SpriteFrame::*)(bool)>(&cocos2d::SpriteFrame::setRotated);
mt["set"]["Rotated"]=mt["SetRotated"];
mt["GetRect"]=static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRect);
mt["get"]["Rect"]=mt["GetRect"];
mt["SetRect"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRect);
mt["set"]["Rect"]=mt["SetRect"];
mt["GetCenterRect"]=static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getCenterRect);
mt["get"]["CenterRect"]=mt["GetCenterRect"];
mt["SetCenterRectInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setCenterRectInPixels);
mt["set"]["CenterRectInPixels"]=mt["SetCenterRectInPixels"];
mt["HasCenterRect"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasCenterRect);
mt["GetOffsetInPixels"]=static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffsetInPixels);
mt["get"]["OffsetInPixels"]=mt["GetOffsetInPixels"];
mt["SetOffsetInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffsetInPixels);
mt["set"]["OffsetInPixels"]=mt["SetOffsetInPixels"];
mt["GetOriginalSizeInPixels"]=static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSizeInPixels);
mt["get"]["OriginalSizeInPixels"]=mt["GetOriginalSizeInPixels"];
mt["SetOriginalSizeInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSizeInPixels);
mt["set"]["OriginalSizeInPixels"]=mt["SetOriginalSizeInPixels"];
mt["GetOriginalSize"]=static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSize);
mt["get"]["OriginalSize"]=mt["GetOriginalSize"];
mt["SetOriginalSize"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSize);
mt["set"]["OriginalSize"]=mt["SetOriginalSize"];
mt["GetTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::SpriteFrame::*)()>(&cocos2d::SpriteFrame::getTexture);
mt["get"]["Texture"]=mt["GetTexture"];
mt["SetTexture"]=static_cast<void(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrame::setTexture);
mt["set"]["Texture"]=mt["SetTexture"];
mt["GetOffset"]=static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffset);
mt["get"]["Offset"]=mt["GetOffset"];
mt["SetOffset"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffset);
mt["set"]["Offset"]=mt["SetOffset"];
mt["GetAnchorPoint"]=static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getAnchorPoint);
mt["get"]["AnchorPoint"]=mt["GetAnchorPoint"];
mt["SetAnchorPoint"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setAnchorPoint);
mt["set"]["AnchorPoint"]=mt["SetAnchorPoint"];
mt["HasAnchorPoint"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasAnchorPoint);
mt["SetPolygonInfo"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::PolygonInfo&)>(&cocos2d::SpriteFrame::setPolygonInfo);
mt["set"]["PolygonInfo"]=mt["SetPolygonInfo"];
mt["GetPolygonInfo"]=static_cast<const cocos2d::PolygonInfo&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getPolygonInfo);
mt["get"]["PolygonInfo"]=mt["GetPolygonInfo"];
mt["HasPolygonInfo"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasPolygonInfo);
}
void RegisterLuaCoreAnimationFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AnimationFrame).name()] = sol::usertype_traits<cocos2d::AnimationFrame*>::metatable();
auto dep=lua.new_usertype<cocos2d::AnimationFrame>("deprecated.cocos2d::AnimationFrame");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AnimationFrame*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["AnimationFrame"]=mt;
mt["__new__"]=static_cast<cocos2d::AnimationFrame*(*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::create);
mt["GetSpriteFrame"]=static_cast<cocos2d::SpriteFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getSpriteFrame);
mt["get"]["SpriteFrame"]=mt["GetSpriteFrame"];
mt["SetSpriteFrame"]=static_cast<void(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*)>(&cocos2d::AnimationFrame::setSpriteFrame);
mt["set"]["SpriteFrame"]=mt["SetSpriteFrame"];
mt["GetDelayUnits"]=static_cast<float(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getDelayUnits);
mt["get"]["DelayUnits"]=mt["GetDelayUnits"];
mt["SetDelayUnits"]=static_cast<void(cocos2d::AnimationFrame::*)(float)>(&cocos2d::AnimationFrame::setDelayUnits);
mt["set"]["DelayUnits"]=mt["SetDelayUnits"];
mt["GetUserInfo"]=static_cast<const cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getUserInfo);
mt["get"]["UserInfo"]=mt["GetUserInfo"];
mt["SetUserInfo"]=static_cast<void(cocos2d::AnimationFrame::*)(const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::setUserInfo);
mt["set"]["UserInfo"]=mt["SetUserInfo"];
}
void RegisterLuaCoreAnimationAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Animation).name()] = sol::usertype_traits<cocos2d::Animation*>::metatable();
auto dep=lua.new_usertype<cocos2d::Animation>("deprecated.cocos2d::Animation");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Animation*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["Animation"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1,unsigned int arg2){return cocos2d::Animation::create(arg0,arg1,arg2);},[](const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1){return cocos2d::Animation::create(arg0,arg1);},static_cast<cocos2d::Animation*(*)()>(&cocos2d::Animation::create));
mt["static"]["CreateWithSpriteFrames"]=sol::overload([](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return cocos2d::Animation::createWithSpriteFrames(arg0,arg1,arg2);},[](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return cocos2d::Animation::createWithSpriteFrames(arg0,arg1);},[](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return cocos2d::Animation::createWithSpriteFrames(arg0);});
mt["AddSpriteFrame"]=static_cast<void(cocos2d::Animation::*)(cocos2d::SpriteFrame*)>(&cocos2d::Animation::addSpriteFrame);
mt["AddSpriteFrameWithFile"]=static_cast<void(cocos2d::Animation::*)(const std::string&)>(&cocos2d::Animation::addSpriteFrameWithFile);
mt["AddSpriteFrameWithTexture"]=static_cast<void(cocos2d::Animation::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Animation::addSpriteFrameWithTexture);
mt["GetTotalDelayUnits"]=static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getTotalDelayUnits);
mt["get"]["TotalDelayUnits"]=mt["GetTotalDelayUnits"];
mt["SetDelayPerUnit"]=static_cast<void(cocos2d::Animation::*)(float)>(&cocos2d::Animation::setDelayPerUnit);
mt["set"]["DelayPerUnit"]=mt["SetDelayPerUnit"];
mt["GetDelayPerUnit"]=static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDelayPerUnit);
mt["get"]["DelayPerUnit"]=mt["GetDelayPerUnit"];
mt["GetDuration"]=static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDuration);
mt["get"]["Duration"]=mt["GetDuration"];
mt["GetFrames"]=static_cast<const cocos2d::Vector<cocos2d::AnimationFrame *>&(cocos2d::Animation::*)()const>(&cocos2d::Animation::getFrames);
mt["get"]["Frames"]=mt["GetFrames"];
mt["SetFrames"]=static_cast<void(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&)>(&cocos2d::Animation::setFrames);
mt["set"]["Frames"]=mt["SetFrames"];
mt["GetRestoreOriginalFrame"]=static_cast<bool(cocos2d::Animation::*)()const>(&cocos2d::Animation::getRestoreOriginalFrame);
mt["get"]["RestoreOriginalFrame"]=mt["GetRestoreOriginalFrame"];
mt["SetRestoreOriginalFrame"]=static_cast<void(cocos2d::Animation::*)(bool)>(&cocos2d::Animation::setRestoreOriginalFrame);
mt["set"]["RestoreOriginalFrame"]=mt["SetRestoreOriginalFrame"];
mt["GetLoops"]=static_cast<unsigned int(cocos2d::Animation::*)()const>(&cocos2d::Animation::getLoops);
mt["get"]["Loops"]=mt["GetLoops"];
mt["SetLoops"]=static_cast<void(cocos2d::Animation::*)(unsigned int)>(&cocos2d::Animation::setLoops);
mt["set"]["Loops"]=mt["SetLoops"];
}
void RegisterLuaCoreActionIntervalAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionInterval).name()] = sol::usertype_traits<cocos2d::ActionInterval*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionInterval>("deprecated.cocos2d::ActionInterval");
dep[sol::base_classes]=sol::bases<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionInterval*>::metatable(),sol::usertype_traits<cocos2d::FiniteTimeAction*>::metatable());
lua["cc"]["ActionInterval"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetElapsed"]=static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getElapsed);
mt["get"]["Elapsed"]=mt["GetElapsed"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
}
void RegisterLuaCoreSequenceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Sequence).name()] = sol::usertype_traits<cocos2d::Sequence*>::metatable();
auto dep=lua.new_usertype<cocos2d::Sequence>("deprecated.cocos2d::Sequence");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Sequence*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["Sequence"]=mt;
mt["__new__"]=static_cast<cocos2d::Sequence*(*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Sequence::create);
mt["static"]["CreateWithVariableList"]=static_cast<cocos2d::Sequence*(*)(cocos2d::FiniteTimeAction*,va_list)>(&cocos2d::Sequence::createWithVariableList);
mt["static"]["CreateWithTwoActions"]=static_cast<cocos2d::Sequence*(*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Sequence::createWithTwoActions);
}
void RegisterLuaCoreRepeatAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Repeat).name()] = sol::usertype_traits<cocos2d::Repeat*>::metatable();
auto dep=lua.new_usertype<cocos2d::Repeat>("deprecated.cocos2d::Repeat");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Repeat*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["Repeat"]=mt;
mt["__new__"]=static_cast<cocos2d::Repeat*(*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::create);
mt["SetInnerAction"]=static_cast<void(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*)>(&cocos2d::Repeat::setInnerAction);
mt["set"]["InnerAction"]=mt["SetInnerAction"];
mt["GetInnerAction"]=static_cast<cocos2d::FiniteTimeAction*(cocos2d::Repeat::*)()>(&cocos2d::Repeat::getInnerAction);
mt["get"]["InnerAction"]=mt["GetInnerAction"];
}
void RegisterLuaCoreRepeatForeverAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RepeatForever).name()] = sol::usertype_traits<cocos2d::RepeatForever*>::metatable();
auto dep=lua.new_usertype<cocos2d::RepeatForever>("deprecated.cocos2d::RepeatForever");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RepeatForever*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["RepeatForever"]=mt;
mt["__new__"]=static_cast<cocos2d::RepeatForever*(*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::create);
mt["SetInnerAction"]=static_cast<void(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::setInnerAction);
mt["set"]["InnerAction"]=mt["SetInnerAction"];
mt["GetInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::RepeatForever::*)()>(&cocos2d::RepeatForever::getInnerAction);
mt["get"]["InnerAction"]=mt["GetInnerAction"];
}
void RegisterLuaCoreSpawnAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Spawn).name()] = sol::usertype_traits<cocos2d::Spawn*>::metatable();
auto dep=lua.new_usertype<cocos2d::Spawn>("deprecated.cocos2d::Spawn");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Spawn*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["Spawn"]=mt;
mt["static"]["CreateWithVariableList"]=static_cast<cocos2d::Spawn*(*)(cocos2d::FiniteTimeAction*,va_list)>(&cocos2d::Spawn::createWithVariableList);
mt["__new__"]=static_cast<cocos2d::Spawn*(*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Spawn::create);
mt["static"]["CreateWithTwoActions"]=static_cast<cocos2d::Spawn*(*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Spawn::createWithTwoActions);
}
void RegisterLuaCoreRotateToAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RotateTo).name()] = sol::usertype_traits<cocos2d::RotateTo*>::metatable();
auto dep=lua.new_usertype<cocos2d::RotateTo>("deprecated.cocos2d::RotateTo");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RotateTo*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["RotateTo"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::RotateTo*(*)(float,float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,float)>(&cocos2d::RotateTo::create));
}
