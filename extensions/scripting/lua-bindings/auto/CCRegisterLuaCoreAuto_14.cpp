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
void RegisterLuaCoreFlipY3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipY3D>("cc","FlipY3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FlipY3D*(*)(float)>(&cocos2d::FlipY3D::create));
mt.set_function("Update",static_cast<void(cocos2d::FlipY3D::*)(float)>(&cocos2d::FlipY3D::update));
mt.set_function("Clone",static_cast<cocos2d::FlipY3D*(cocos2d::FlipY3D::*)()const>(&cocos2d::FlipY3D::clone));
}
void RegisterLuaCoreShaky3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Shaky3D>("cc","Shaky3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Shaky3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::create));
mt.set_function("Clone",static_cast<cocos2d::Shaky3D*(cocos2d::Shaky3D::*)()const>(&cocos2d::Shaky3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::Shaky3D::*)(float)>(&cocos2d::Shaky3D::update));
}
void RegisterLuaCoreLiquidAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Liquid>("cc","Liquid",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Liquid*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::create));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::Liquid*(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::clone));
mt.set_function("Update",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::update));
}
void RegisterLuaCoreWavesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Waves>("cc","Waves",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Waves*(*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::create));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::Waves*(cocos2d::Waves::*)()const>(&cocos2d::Waves::clone));
mt.set_function("Update",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::update));
}
void RegisterLuaCoreTwirlAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Twirl>("cc","Twirl",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Twirl*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::create));
mt.set_function("GetPosition",static_cast<const cocos2d::Vec2&(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getPosition));
mt.set_function("SetPosition",static_cast<void(cocos2d::Twirl::*)(const cocos2d::Vec2&)>(&cocos2d::Twirl::setPosition));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::Twirl*(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::clone));
mt.set_function("Update",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::update));
}
void RegisterLuaCoreActionManagerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionManager>("cc","ActionManager",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("AddAction",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*,cocos2d::Node*,bool)>(&cocos2d::ActionManager::addAction));
mt.set_function("RemoveAllActions",static_cast<void(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::removeAllActions));
mt.set_function("RemoveAllActionsFromTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsFromTarget));
mt.set_function("RemoveAction",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*)>(&cocos2d::ActionManager::removeAction));
mt.set_function("RemoveActionByTag",static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionByTag));
mt.set_function("RemoveAllActionsByTag",static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsByTag));
mt.set_function("RemoveActionsByFlags",static_cast<void(cocos2d::ActionManager::*)(unsigned int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionsByFlags));
mt.set_function("GetActionByTag",static_cast<cocos2d::Action*(cocos2d::ActionManager::*)(int,const cocos2d::Node*)const>(&cocos2d::ActionManager::getActionByTag));
mt.set_function("GetNumberOfRunningActionsInTarget",static_cast<ssize_t(cocos2d::ActionManager::*)(const cocos2d::Node*)const>(&cocos2d::ActionManager::getNumberOfRunningActionsInTarget));
mt.set_function("GetNumberOfRunningActions",static_cast<ssize_t(cocos2d::ActionManager::*)()const>(&cocos2d::ActionManager::getNumberOfRunningActions));
mt.set_function("GetNumberOfRunningActionsInTargetByTag",static_cast<size_t(cocos2d::ActionManager::*)(const cocos2d::Node*,int)>(&cocos2d::ActionManager::getNumberOfRunningActionsInTargetByTag));
mt.set_function("PauseTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::pauseTarget));
mt.set_function("ResumeTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::resumeTarget));
mt.set_function("PauseAllRunningActions",static_cast<cocos2d::Vector<cocos2d::Node *>(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::pauseAllRunningActions));
mt.set_function("ResumeTargets",static_cast<void(cocos2d::ActionManager::*)(const cocos2d::Vector<cocos2d::Node *>&)>(&cocos2d::ActionManager::resumeTargets));
mt.set_function("Update",static_cast<void(cocos2d::ActionManager::*)(float)>(&cocos2d::ActionManager::update));
mt[sol::call_constructor]=sol::constructors<cocos2d::ActionManager()>();
}
void RegisterLuaCoreProgressToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProgressTo>("cc","ProgressTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ProgressTo*(*)(float,float)>(&cocos2d::ProgressTo::create));
mt.set_function("Clone",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ProgressTo::*)(cocos2d::Node*)>(&cocos2d::ProgressTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::ProgressTo::*)(float)>(&cocos2d::ProgressTo::update));
}
void RegisterLuaCoreProgressFromToAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProgressFromTo>("cc","ProgressFromTo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ProgressFromTo*(*)(float,float,float)>(&cocos2d::ProgressFromTo::create));
mt.set_function("Clone",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::clone));
mt.set_function("Reverse",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ProgressFromTo::*)(cocos2d::Node*)>(&cocos2d::ProgressFromTo::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::ProgressFromTo::*)(float)>(&cocos2d::ProgressFromTo::update));
}
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
