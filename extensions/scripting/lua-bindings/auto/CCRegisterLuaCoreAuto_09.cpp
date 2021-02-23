#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreWavesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Waves,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Waves");
mt.set_function("getAmplitude",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Waves*(cocos2d::Waves::*)()const>(&cocos2d::Waves::clone));
mt.set_function("update",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Waves::*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Waves*(*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::create));
}
void RegisterLuaCoreTwirlAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Twirl,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Twirl");
mt.set_function("getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getPosition));
mt.set_function("setPosition",static_cast<void(cocos2d::Twirl::*)(const cocos2d::Vec2&)>(&cocos2d::Twirl::setPosition));
mt.set_function("getAmplitude",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Twirl*(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::clone));
mt.set_function("update",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::Twirl::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::initWithDuration));
mt.set_function("new",static_cast<cocos2d::Twirl*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::create));
}
void RegisterLuaCoreActionManagerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionManager,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionManager");
mt.set_function("addAction",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*,cocos2d::Node*,bool)>(&cocos2d::ActionManager::addAction));
mt.set_function("removeAllActions",static_cast<void(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::removeAllActions));
mt.set_function("removeAllActionsFromTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsFromTarget));
mt.set_function("removeAction",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*)>(&cocos2d::ActionManager::removeAction));
mt.set_function("removeActionByTag",static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionByTag));
mt.set_function("removeAllActionsByTag",static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsByTag));
mt.set_function("removeActionsByFlags",static_cast<void(cocos2d::ActionManager::*)(unsigned int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionsByFlags));
mt.set_function("getActionByTag",static_cast<cocos2d::Action*(cocos2d::ActionManager::*)(int,const cocos2d::Node*)const>(&cocos2d::ActionManager::getActionByTag));
mt.set_function("getNumberOfRunningActionsInTarget",static_cast<ssize_t(cocos2d::ActionManager::*)(const cocos2d::Node*)const>(&cocos2d::ActionManager::getNumberOfRunningActionsInTarget));
mt.set_function("getNumberOfRunningActions",static_cast<ssize_t(cocos2d::ActionManager::*)()const>(&cocos2d::ActionManager::getNumberOfRunningActions));
mt.set_function("getNumberOfRunningActionsInTargetByTag",static_cast<size_t(cocos2d::ActionManager::*)(const cocos2d::Node*,int)>(&cocos2d::ActionManager::getNumberOfRunningActionsInTargetByTag));
mt.set_function("pauseTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::pauseTarget));
mt.set_function("resumeTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::resumeTarget));
mt.set_function("pauseAllRunningActions",static_cast<cocos2d::Vector<cocos2d::Node *>(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::pauseAllRunningActions));
mt.set_function("resumeTargets",static_cast<void(cocos2d::ActionManager::*)(const cocos2d::Vector<cocos2d::Node *>&)>(&cocos2d::ActionManager::resumeTargets));
mt.set_function("update",static_cast<void(cocos2d::ActionManager::*)(float)>(&cocos2d::ActionManager::update));
}
void RegisterLuaCorePageTurn3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PageTurn3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","PageTurn3D");
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::PageTurn3D::*)()>(&cocos2d::PageTurn3D::getGrid));
mt.set_function("clone",static_cast<cocos2d::PageTurn3D*(cocos2d::PageTurn3D::*)()const>(&cocos2d::PageTurn3D::clone));
mt.set_function("update",static_cast<void(cocos2d::PageTurn3D::*)(float)>(&cocos2d::PageTurn3D::update));
mt.set_function("new",static_cast<cocos2d::PageTurn3D*(*)(float,const cocos2d::Size&)>(&cocos2d::PageTurn3D::create));
}
void RegisterLuaCoreProgressToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProgressTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ProgressTo");
mt.set_function("clone",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::clone));
mt.set_function("reverse",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ProgressTo::*)(cocos2d::Node*)>(&cocos2d::ProgressTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ProgressTo::*)(float)>(&cocos2d::ProgressTo::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ProgressTo::*)(float,float)>(&cocos2d::ProgressTo::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ProgressTo*(*)(float,float)>(&cocos2d::ProgressTo::create));
}
void RegisterLuaCoreProgressFromToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProgressFromTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ProgressFromTo");
mt.set_function("clone",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::clone));
mt.set_function("reverse",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ProgressFromTo::*)(cocos2d::Node*)>(&cocos2d::ProgressFromTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ProgressFromTo::*)(float)>(&cocos2d::ProgressFromTo::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ProgressFromTo::*)(float,float,float)>(&cocos2d::ProgressFromTo::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ProgressFromTo*(*)(float,float,float)>(&cocos2d::ProgressFromTo::create));
}
void RegisterLuaCoreShakyTiles3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ShakyTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ShakyTiles3D");
mt.set_function("clone",static_cast<cocos2d::ShakyTiles3D*(cocos2d::ShakyTiles3D::*)()const>(&cocos2d::ShakyTiles3D::clone));
mt.set_function("update",static_cast<void(cocos2d::ShakyTiles3D::*)(float)>(&cocos2d::ShakyTiles3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ShakyTiles3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShakyTiles3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ShakyTiles3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShakyTiles3D::create));
}
void RegisterLuaCoreShatteredTiles3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ShatteredTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ShatteredTiles3D");
mt.set_function("clone",static_cast<cocos2d::ShatteredTiles3D*(cocos2d::ShatteredTiles3D::*)()const>(&cocos2d::ShatteredTiles3D::clone));
mt.set_function("update",static_cast<void(cocos2d::ShatteredTiles3D::*)(float)>(&cocos2d::ShatteredTiles3D::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ShatteredTiles3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShatteredTiles3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ShatteredTiles3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShatteredTiles3D::create));
}
void RegisterLuaCoreShuffleTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ShuffleTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ShuffleTiles");
mt.set_function("getDelta",static_cast<cocos2d::Size(cocos2d::ShuffleTiles::*)(const cocos2d::Size&)const>(&cocos2d::ShuffleTiles::getDelta));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ShuffleTiles::*)(cocos2d::Node*)>(&cocos2d::ShuffleTiles::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ShuffleTiles::*)(float)>(&cocos2d::ShuffleTiles::update));
mt.set_function("clone",static_cast<cocos2d::ShuffleTiles*(cocos2d::ShuffleTiles::*)()const>(&cocos2d::ShuffleTiles::clone));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ShuffleTiles::*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ShuffleTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::create));
}
void RegisterLuaCoreFadeOutTRTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutTRTiles");
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutTRTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutTRTiles::testFunc));
mt.set_function("turnOnTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOnTile));
mt.set_function("turnOffTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOffTile));
mt.set_function("transformTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutTRTiles::transformTile));
mt.set_function("update",static_cast<void(cocos2d::FadeOutTRTiles::*)(float)>(&cocos2d::FadeOutTRTiles::update));
mt.set_function("clone",static_cast<cocos2d::FadeOutTRTiles*(cocos2d::FadeOutTRTiles::*)()const>(&cocos2d::FadeOutTRTiles::clone));
mt.set_function("new",static_cast<cocos2d::FadeOutTRTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutTRTiles::create));
}
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
mt.set_function("turnOnTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile));
mt.set_function("turnOffTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile));
mt.set_function("clone",static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TurnOffTiles::*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::initWithDuration));
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
mt.set_function("initWithDuration",static_cast<bool(cocos2d::WavesTiles3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::initWithDuration));
mt.set_function("new",static_cast<cocos2d::WavesTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::create));
}
