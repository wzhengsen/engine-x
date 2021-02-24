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
void RegisterLuaCoreFadeOutBLTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutBLTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutBLTiles");
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutBLTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutBLTiles::testFunc));
mt.set_function("clone",static_cast<cocos2d::FadeOutBLTiles*(cocos2d::FadeOutBLTiles::*)()const>(&cocos2d::FadeOutBLTiles::clone));
mt.set_function("new",static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create));
}
void RegisterLuaCoreFadeOutUpTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutUpTiles");
mt.set_function("transformTile",static_cast<void(cocos2d::FadeOutUpTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutUpTiles::transformTile));
mt.set_function("clone",static_cast<cocos2d::FadeOutUpTiles*(cocos2d::FadeOutUpTiles::*)()const>(&cocos2d::FadeOutUpTiles::clone));
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutUpTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutUpTiles::testFunc));
mt.set_function("new",static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create));
}
void RegisterLuaCoreFadeOutDownTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutDownTiles,cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutDownTiles");
mt.set_function("clone",static_cast<cocos2d::FadeOutDownTiles*(cocos2d::FadeOutDownTiles::*)()const>(&cocos2d::FadeOutDownTiles::clone));
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutDownTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutDownTiles::testFunc));
mt.set_function("new",static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create));
}
void RegisterLuaCoreTurnOffTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TurnOffTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TurnOffTiles");
mt.set_function("shuffle",static_cast<void(cocos2d::TurnOffTiles::*)(unsigned int*,unsigned int)>(&cocos2d::TurnOffTiles::shuffle));
mt.set_function("turnOnTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile));
mt.set_function("turnOffTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile));
mt.set_function("clone",static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update));
mt.set_function("new",sol::overload(static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create)));
}
void RegisterLuaCoreWavesTiles3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::WavesTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","WavesTiles3D");
mt.set_function("getAmplitude",static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::WavesTiles3D*(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::clone));
mt.set_function("update",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::update));
mt.set_function("new",static_cast<cocos2d::WavesTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::create));
}
void RegisterLuaCoreJumpTiles3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpTiles3D");
mt.set_function("getAmplitude",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone));
mt.set_function("update",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update));
mt.set_function("new",static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create));
}
void RegisterLuaCoreSplitRowsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitRows,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SplitRows");
mt.set_function("clone",static_cast<cocos2d::SplitRows*(cocos2d::SplitRows::*)()const>(&cocos2d::SplitRows::clone));
mt.set_function("update",static_cast<void(cocos2d::SplitRows::*)(float)>(&cocos2d::SplitRows::update));
mt.set_function("startWithTarget",static_cast<void(cocos2d::SplitRows::*)(cocos2d::Node*)>(&cocos2d::SplitRows::startWithTarget));
mt.set_function("new",static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create));
}
void RegisterLuaCoreSplitColsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitCols,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SplitCols");
mt.set_function("clone",static_cast<cocos2d::SplitCols*(cocos2d::SplitCols::*)()const>(&cocos2d::SplitCols::clone));
mt.set_function("update",static_cast<void(cocos2d::SplitCols::*)(float)>(&cocos2d::SplitCols::update));
mt.set_function("startWithTarget",static_cast<void(cocos2d::SplitCols::*)(cocos2d::Node*)>(&cocos2d::SplitCols::startWithTarget));
mt.set_function("new",static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create));
}
void RegisterLuaCoreActionTweenDelegateAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionTweenDelegate>("cc","ActionTweenDelegate");
mt.set_function("updateTweenAction",static_cast<void(cocos2d::ActionTweenDelegate::*)(float,const std::string&)>(&cocos2d::ActionTweenDelegate::updateTweenAction));
}
void RegisterLuaCoreActionTweenAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionTween,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionTween");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionTween::*)(cocos2d::Node*)>(&cocos2d::ActionTween::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ActionTween::*)(float)>(&cocos2d::ActionTween::update));
mt.set_function("reverse",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::clone));
mt.set_function("new",static_cast<cocos2d::ActionTween*(*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::create));
}
