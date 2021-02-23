#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreFlipYAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipY,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipY");
mt.set_function("update",static_cast<void(cocos2d::FlipY::*)(float)>(&cocos2d::FlipY::update));
mt.set_function("reverse",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::reverse));
mt.set_function("clone",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::clone));
mt.set_function("initWithFlipY",static_cast<bool(cocos2d::FlipY::*)(bool)>(&cocos2d::FlipY::initWithFlipY));
mt.set_function("new",static_cast<cocos2d::FlipY*(*)(bool)>(&cocos2d::FlipY::create));
}
void RegisterLuaCorePlaceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Place,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Place");
mt.set_function("update",static_cast<void(cocos2d::Place::*)(float)>(&cocos2d::Place::update));
mt.set_function("reverse",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::reverse));
mt.set_function("clone",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::clone));
mt.set_function("initWithPosition",static_cast<bool(cocos2d::Place::*)(const cocos2d::Vec2&)>(&cocos2d::Place::initWithPosition));
mt.set_function("new",static_cast<cocos2d::Place*(*)(const cocos2d::Vec2&)>(&cocos2d::Place::create));
}
void RegisterLuaCoreCallFuncAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CallFunc,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CallFunc");
mt.set_function("execute",static_cast<void(cocos2d::CallFunc::*)()>(&cocos2d::CallFunc::execute));
mt.set_function("update",static_cast<void(cocos2d::CallFunc::*)(float)>(&cocos2d::CallFunc::update));
mt.set_function("reverse",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::reverse));
mt.set_function("clone",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::clone));
}
void RegisterLuaCoreGridActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","GridAction");
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::GridAction::*)()>(&cocos2d::GridAction::getGrid));
mt.set_function("clone",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::clone));
mt.set_function("reverse",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::GridAction::*)(cocos2d::Node*)>(&cocos2d::GridAction::startWithTarget));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::GridAction::*)(float,const cocos2d::Size&)>(&cocos2d::GridAction::initWithDuration));
}
void RegisterLuaCoreGrid3DActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Grid3DAction");
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::Grid3DAction::*)()>(&cocos2d::Grid3DAction::getGrid));
mt.set_function("clone",static_cast<cocos2d::Grid3DAction*(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::clone));
mt.set_function("getGridRect",static_cast<cocos2d::Rect(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::getGridRect));
}
void RegisterLuaCoreTiledGrid3DActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TiledGrid3DAction");
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::TiledGrid3DAction::*)()>(&cocos2d::TiledGrid3DAction::getGrid));
mt.set_function("clone",static_cast<cocos2d::TiledGrid3DAction*(cocos2d::TiledGrid3DAction::*)()const>(&cocos2d::TiledGrid3DAction::clone));
}
void RegisterLuaCoreStopGridAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::StopGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","StopGrid");
mt.set_function("startWithTarget",static_cast<void(cocos2d::StopGrid::*)(cocos2d::Node*)>(&cocos2d::StopGrid::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::clone));
mt.set_function("reverse",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::reverse));
mt.set_function("new",static_cast<cocos2d::StopGrid*(*)()>(&cocos2d::StopGrid::create));
}
void RegisterLuaCoreReuseGridAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ReuseGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ReuseGrid");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ReuseGrid::*)(cocos2d::Node*)>(&cocos2d::ReuseGrid::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::clone));
mt.set_function("reverse",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::reverse));
mt.set_function("initWithTimes",static_cast<bool(cocos2d::ReuseGrid::*)(int)>(&cocos2d::ReuseGrid::initWithTimes));
mt.set_function("new",static_cast<cocos2d::ReuseGrid*(*)(int)>(&cocos2d::ReuseGrid::create));
}
void RegisterLuaCoreWaves3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Waves3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Waves3D");
mt.set_function("getAmplitude",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Waves3D*(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Waves3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Waves3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::create));
}
void RegisterLuaCoreFlipX3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipX3D");
mt.set_function("clone",static_cast<cocos2d::FlipX3D*(cocos2d::FlipX3D::*)()const>(&cocos2d::FlipX3D::clone));
mt.set_function("update",static_cast<void(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::initWithDuration));
mt.set_function("initWithSize",static_cast<bool(cocos2d::FlipX3D::*)(const cocos2d::Size&,float)>(&cocos2d::FlipX3D::initWithSize));
mt.set_function("new",static_cast<cocos2d::FlipX3D*(*)(float)>(&cocos2d::FlipX3D::create));
}
void RegisterLuaCoreFlipY3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipY3D,cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipY3D");
mt.set_function("update",static_cast<void(cocos2d::FlipY3D::*)(float)>(&cocos2d::FlipY3D::update));
mt.set_function("clone",static_cast<cocos2d::FlipY3D*(cocos2d::FlipY3D::*)()const>(&cocos2d::FlipY3D::clone));
mt.set_function("new",static_cast<cocos2d::FlipY3D*(*)(float)>(&cocos2d::FlipY3D::create));
}
void RegisterLuaCoreLens3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Lens3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Lens3D");
mt.set_function("getLensEffect",static_cast<float(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getLensEffect));
mt.set_function("setLensEffect",static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::setLensEffect));
mt.set_function("setConcave",static_cast<void(cocos2d::Lens3D::*)(bool)>(&cocos2d::Lens3D::setConcave));
mt.set_function("getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getPosition));
mt.set_function("setPosition",static_cast<void(cocos2d::Lens3D::*)(const cocos2d::Vec2&)>(&cocos2d::Lens3D::setPosition));
mt.set_function("clone",static_cast<cocos2d::Lens3D*(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Lens3D::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Lens3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::create));
}
void RegisterLuaCoreRipple3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Ripple3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Ripple3D");
mt.set_function("getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getPosition));
mt.set_function("setPosition",static_cast<void(cocos2d::Ripple3D::*)(const cocos2d::Vec2&)>(&cocos2d::Ripple3D::setPosition));
mt.set_function("getAmplitude",static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Ripple3D*(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Ripple3D::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Ripple3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::create));
}
void RegisterLuaCoreShaky3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Shaky3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Shaky3D");
mt.set_function("clone",static_cast<cocos2d::Shaky3D*(cocos2d::Shaky3D::*)()const>(&cocos2d::Shaky3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Shaky3D::*)(float)>(&cocos2d::Shaky3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Shaky3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Shaky3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::create));
}
void RegisterLuaCoreLiquidAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Liquid,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Liquid");
mt.set_function("getAmplitude",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Liquid*(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::clone));
mt.set_function("update",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Liquid::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Liquid*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::create));
}
