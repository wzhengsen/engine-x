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
void RegisterLuaCoreActionManagerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ActionManager,cocos2d::Ref,cocos2d::LuaObject>("ActionManager",true);
ns["ActionManager"] = mt;
lua["ActionManager"] = sol::nil;
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
void RegisterLuaCoreProgressToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ProgressTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ProgressTo",false);
ns["ProgressTo"] = mt;
lua["ProgressTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::clone));
mt.set_function("reverse",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ProgressTo::*)(cocos2d::Node*)>(&cocos2d::ProgressTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ProgressTo::*)(float)>(&cocos2d::ProgressTo::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ProgressTo*(*)(float,float)>(&cocos2d::ProgressTo::create));
}
void RegisterLuaCoreProgressFromToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ProgressFromTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ProgressFromTo",false);
ns["ProgressFromTo"] = mt;
lua["ProgressFromTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::clone));
mt.set_function("reverse",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ProgressFromTo::*)(cocos2d::Node*)>(&cocos2d::ProgressFromTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ProgressFromTo::*)(float)>(&cocos2d::ProgressFromTo::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ProgressFromTo*(*)(float,float,float)>(&cocos2d::ProgressFromTo::create));
}
void RegisterLuaCoreShuffleTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ShuffleTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ShuffleTiles",false);
ns["ShuffleTiles"] = mt;
lua["ShuffleTiles"] = sol::nil;
mt.set_function("shuffle",static_cast<void(cocos2d::ShuffleTiles::*)(unsigned int*,unsigned int)>(&cocos2d::ShuffleTiles::shuffle));
mt.set_function("getDelta",static_cast<cocos2d::Size(cocos2d::ShuffleTiles::*)(const cocos2d::Size&)const>(&cocos2d::ShuffleTiles::getDelta));
mt.set_function("placeTile",static_cast<void(cocos2d::ShuffleTiles::*)(const cocos2d::Vec2&,cocos2d::Tile*)>(&cocos2d::ShuffleTiles::placeTile));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ShuffleTiles::*)(cocos2d::Node*)>(&cocos2d::ShuffleTiles::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ShuffleTiles::*)(float)>(&cocos2d::ShuffleTiles::update));
mt.set_function("clone",static_cast<cocos2d::ShuffleTiles*(cocos2d::ShuffleTiles::*)()const>(&cocos2d::ShuffleTiles::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ShuffleTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::create));
}
void RegisterLuaCoreFadeOutTRTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeOutTRTiles",false);
ns["FadeOutTRTiles"] = mt;
lua["FadeOutTRTiles"] = sol::nil;
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutTRTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutTRTiles::testFunc));
mt.set_function("turnOnTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOnTile));
mt.set_function("turnOffTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOffTile));
mt.set_function("transformTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutTRTiles::transformTile));
mt.set_function("update",static_cast<void(cocos2d::FadeOutTRTiles::*)(float)>(&cocos2d::FadeOutTRTiles::update));
mt.set_function("clone",static_cast<cocos2d::FadeOutTRTiles*(cocos2d::FadeOutTRTiles::*)()const>(&cocos2d::FadeOutTRTiles::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutTRTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutTRTiles::create));
}
void RegisterLuaCoreFadeOutBLTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeOutBLTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeOutBLTiles",false);
ns["FadeOutBLTiles"] = mt;
lua["FadeOutBLTiles"] = sol::nil;
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutBLTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutBLTiles::testFunc));
mt.set_function("clone",static_cast<cocos2d::FadeOutBLTiles*(cocos2d::FadeOutBLTiles::*)()const>(&cocos2d::FadeOutBLTiles::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create));
}
void RegisterLuaCoreFadeOutUpTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeOutUpTiles",false);
ns["FadeOutUpTiles"] = mt;
lua["FadeOutUpTiles"] = sol::nil;
mt.set_function("transformTile",static_cast<void(cocos2d::FadeOutUpTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutUpTiles::transformTile));
mt.set_function("clone",static_cast<cocos2d::FadeOutUpTiles*(cocos2d::FadeOutUpTiles::*)()const>(&cocos2d::FadeOutUpTiles::clone));
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutUpTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutUpTiles::testFunc));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create));
}
void RegisterLuaCoreFadeOutDownTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeOutDownTiles,cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeOutDownTiles",false);
ns["FadeOutDownTiles"] = mt;
lua["FadeOutDownTiles"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::FadeOutDownTiles*(cocos2d::FadeOutDownTiles::*)()const>(&cocos2d::FadeOutDownTiles::clone));
mt.set_function("testFunc",static_cast<float(cocos2d::FadeOutDownTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutDownTiles::testFunc));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create));
}
void RegisterLuaCoreTurnOffTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TurnOffTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("TurnOffTiles",false);
ns["TurnOffTiles"] = mt;
lua["TurnOffTiles"] = sol::nil;
mt.set_function("shuffle",static_cast<void(cocos2d::TurnOffTiles::*)(unsigned int*,unsigned int)>(&cocos2d::TurnOffTiles::shuffle));
mt.set_function("turnOnTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile));
mt.set_function("turnOffTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile));
mt.set_function("clone",static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create)));
}
void RegisterLuaCoreJumpTiles3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::JumpTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("JumpTiles3D",false);
ns["JumpTiles3D"] = mt;
lua["JumpTiles3D"] = sol::nil;
mt.set_function("getAmplitude",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone));
mt.set_function("update",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create));
}
