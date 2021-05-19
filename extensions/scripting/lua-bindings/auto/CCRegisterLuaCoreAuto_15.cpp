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
void RegisterLuaCoreShuffleTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ShuffleTiles>("cc","ShuffleTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ShuffleTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::create));
mt.set_function("Shuffle",static_cast<void(cocos2d::ShuffleTiles::*)(unsigned int*,unsigned int)>(&cocos2d::ShuffleTiles::shuffle));
mt.set_function("GetDelta",static_cast<cocos2d::Size(cocos2d::ShuffleTiles::*)(const cocos2d::Size&)const>(&cocos2d::ShuffleTiles::getDelta));
mt.set_function("PlaceTile",static_cast<void(cocos2d::ShuffleTiles::*)(const cocos2d::Vec2&,cocos2d::Tile*)>(&cocos2d::ShuffleTiles::placeTile));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ShuffleTiles::*)(cocos2d::Node*)>(&cocos2d::ShuffleTiles::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::ShuffleTiles::*)(float)>(&cocos2d::ShuffleTiles::update));
mt.set_function("Clone",static_cast<cocos2d::ShuffleTiles*(cocos2d::ShuffleTiles::*)()const>(&cocos2d::ShuffleTiles::clone));
}
void RegisterLuaCoreFadeOutTRTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutTRTiles>("cc","FadeOutTRTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutTRTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutTRTiles::create));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutTRTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutTRTiles::testFunc));
mt.set_function("TurnOnTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOnTile));
mt.set_function("TurnOffTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOffTile));
mt.set_function("TransformTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutTRTiles::transformTile));
mt.set_function("Update",static_cast<void(cocos2d::FadeOutTRTiles::*)(float)>(&cocos2d::FadeOutTRTiles::update));
mt.set_function("Clone",static_cast<cocos2d::FadeOutTRTiles*(cocos2d::FadeOutTRTiles::*)()const>(&cocos2d::FadeOutTRTiles::clone));
}
void RegisterLuaCoreFadeOutBLTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutBLTiles>("cc","FadeOutBLTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutBLTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutBLTiles::testFunc));
mt.set_function("Clone",static_cast<cocos2d::FadeOutBLTiles*(cocos2d::FadeOutBLTiles::*)()const>(&cocos2d::FadeOutBLTiles::clone));
}
void RegisterLuaCoreFadeOutUpTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutUpTiles>("cc","FadeOutUpTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create));
mt.set_function("TransformTile",static_cast<void(cocos2d::FadeOutUpTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutUpTiles::transformTile));
mt.set_function("Clone",static_cast<cocos2d::FadeOutUpTiles*(cocos2d::FadeOutUpTiles::*)()const>(&cocos2d::FadeOutUpTiles::clone));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutUpTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutUpTiles::testFunc));
}
void RegisterLuaCoreFadeOutDownTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutDownTiles>("cc","FadeOutDownTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create));
mt.set_function("Clone",static_cast<cocos2d::FadeOutDownTiles*(cocos2d::FadeOutDownTiles::*)()const>(&cocos2d::FadeOutDownTiles::clone));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutDownTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutDownTiles::testFunc));
}
void RegisterLuaCoreTurnOffTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TurnOffTiles>("cc","TurnOffTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create)));
mt.set_function("Shuffle",static_cast<void(cocos2d::TurnOffTiles::*)(unsigned int*,unsigned int)>(&cocos2d::TurnOffTiles::shuffle));
mt.set_function("TurnOnTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile));
mt.set_function("TurnOffTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile));
mt.set_function("Clone",static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update));
}
void RegisterLuaCoreWavesTiles3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::WavesTiles3D>("cc","WavesTiles3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::WavesTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::create));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::WavesTiles3D*(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::update));
}
void RegisterLuaCoreJumpTiles3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpTiles3D>("cc","JumpTiles3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update));
}
void RegisterLuaCoreSplitRowsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitRows>("cc","SplitRows",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create));
mt.set_function("Clone",static_cast<cocos2d::SplitRows*(cocos2d::SplitRows::*)()const>(&cocos2d::SplitRows::clone));
mt.set_function("Update",static_cast<void(cocos2d::SplitRows::*)(float)>(&cocos2d::SplitRows::update));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::SplitRows::*)(cocos2d::Node*)>(&cocos2d::SplitRows::startWithTarget));
}
void RegisterLuaCoreSplitColsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitCols>("cc","SplitCols",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create));
mt.set_function("Clone",static_cast<cocos2d::SplitCols*(cocos2d::SplitCols::*)()const>(&cocos2d::SplitCols::clone));
mt.set_function("Update",static_cast<void(cocos2d::SplitCols::*)(float)>(&cocos2d::SplitCols::update));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::SplitCols::*)(cocos2d::Node*)>(&cocos2d::SplitCols::startWithTarget));
}
