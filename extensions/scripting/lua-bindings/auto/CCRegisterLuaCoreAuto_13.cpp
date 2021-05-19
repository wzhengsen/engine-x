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
void RegisterLuaCoreFlipYAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipY>("cc","FlipY",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FlipY*(*)(bool)>(&cocos2d::FlipY::create));
mt.set_function("Update",static_cast<void(cocos2d::FlipY::*)(float)>(&cocos2d::FlipY::update));
mt.set_function("Reverse",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::reverse));
mt.set_function("Clone",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::clone));
}
void RegisterLuaCorePlaceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Place>("cc","Place",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Place*(*)(const cocos2d::Vec2&)>(&cocos2d::Place::create));
mt.set_function("Update",static_cast<void(cocos2d::Place::*)(float)>(&cocos2d::Place::update));
mt.set_function("Reverse",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::reverse));
mt.set_function("Clone",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::clone));
}
void RegisterLuaCoreCallFuncAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CallFunc>("cc","CallFunc",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CallFunc*(*)(const std::function<void ()>&)>(&cocos2d::CallFunc::create));
mt.set_function("Execute",static_cast<void(cocos2d::CallFunc::*)()>(&cocos2d::CallFunc::execute));
mt.set_function("Update",static_cast<void(cocos2d::CallFunc::*)(float)>(&cocos2d::CallFunc::update));
mt.set_function("Reverse",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::reverse));
mt.set_function("Clone",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::clone));
}
void RegisterLuaCoreGridActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GridAction>("cc","GridAction",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetGrid",static_cast<cocos2d::GridBase*(cocos2d::GridAction::*)()>(&cocos2d::GridAction::getGrid));
mt.set_function("Clone",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::clone));
mt.set_function("Reverse",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::GridAction::*)(cocos2d::Node*)>(&cocos2d::GridAction::startWithTarget));
}
void RegisterLuaCoreGrid3DActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Grid3DAction>("cc","Grid3DAction",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetGrid",static_cast<cocos2d::GridBase*(cocos2d::Grid3DAction::*)()>(&cocos2d::Grid3DAction::getGrid));
mt.set_function("GetVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3DAction::getVertex));
mt.set_function("GetOriginalVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3DAction::getOriginalVertex));
mt.set_function("SetVertex",static_cast<void(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&,const cocos2d::Vec3&)>(&cocos2d::Grid3DAction::setVertex));
mt.set_function("Clone",static_cast<cocos2d::Grid3DAction*(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::clone));
mt.set_function("GetGridRect",static_cast<cocos2d::Rect(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::getGridRect));
}
void RegisterLuaCoreTiledGrid3DActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TiledGrid3DAction>("cc","TiledGrid3DAction",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TiledGrid3DAction*(*)(float,const cocos2d::Size&)>(&cocos2d::TiledGrid3DAction::create));
mt.set_function("GetTile",static_cast<cocos2d::Quad3(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3DAction::getTile));
mt.set_function("GetOriginalTile",static_cast<cocos2d::Quad3(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3DAction::getOriginalTile));
mt.set_function("SetTile",static_cast<void(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&,const cocos2d::Quad3&)>(&cocos2d::TiledGrid3DAction::setTile));
mt.set_function("GetGrid",static_cast<cocos2d::GridBase*(cocos2d::TiledGrid3DAction::*)()>(&cocos2d::TiledGrid3DAction::getGrid));
mt.set_function("Clone",static_cast<cocos2d::TiledGrid3DAction*(cocos2d::TiledGrid3DAction::*)()const>(&cocos2d::TiledGrid3DAction::clone));
}
void RegisterLuaCoreStopGridAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::StopGrid>("cc","StopGrid",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::StopGrid*(*)()>(&cocos2d::StopGrid::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::StopGrid::*)(cocos2d::Node*)>(&cocos2d::StopGrid::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::clone));
mt.set_function("Reverse",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::reverse));
}
void RegisterLuaCoreReuseGridAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ReuseGrid>("cc","ReuseGrid",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ReuseGrid*(*)(int)>(&cocos2d::ReuseGrid::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ReuseGrid::*)(cocos2d::Node*)>(&cocos2d::ReuseGrid::startWithTarget));
mt.set_function("Clone",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::clone));
mt.set_function("Reverse",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::reverse));
}
void RegisterLuaCoreWaves3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Waves3D>("cc","Waves3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Waves3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::create));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::Waves3D*(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::update));
}
void RegisterLuaCoreFlipX3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipX3D>("cc","FlipX3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FlipX3D*(*)(float)>(&cocos2d::FlipX3D::create));
mt.set_function("Clone",static_cast<cocos2d::FlipX3D*(cocos2d::FlipX3D::*)()const>(&cocos2d::FlipX3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::update));
}
