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
void RegisterLuaCoreTiledGrid3DActionAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("TiledGrid3DAction",false);
ns["TiledGrid3DAction"] = mt;
lua["TiledGrid3DAction"] = sol::nil;
mt.set_function("getTile",static_cast<cocos2d::Quad3(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3DAction::getTile));
mt.set_function("getOriginalTile",static_cast<cocos2d::Quad3(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3DAction::getOriginalTile));
mt.set_function("setTile",static_cast<void(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&,const cocos2d::Quad3&)>(&cocos2d::TiledGrid3DAction::setTile));
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::TiledGrid3DAction::*)()>(&cocos2d::TiledGrid3DAction::getGrid));
mt.set_function("clone",static_cast<cocos2d::TiledGrid3DAction*(cocos2d::TiledGrid3DAction::*)()const>(&cocos2d::TiledGrid3DAction::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TiledGrid3DAction*(*)(float,const cocos2d::Size&)>(&cocos2d::TiledGrid3DAction::create));
}
void RegisterLuaCoreStopGridAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::StopGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("StopGrid",false);
ns["StopGrid"] = mt;
lua["StopGrid"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::StopGrid::*)(cocos2d::Node*)>(&cocos2d::StopGrid::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::clone));
mt.set_function("reverse",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::StopGrid*(*)()>(&cocos2d::StopGrid::create));
}
void RegisterLuaCoreReuseGridAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ReuseGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ReuseGrid",false);
ns["ReuseGrid"] = mt;
lua["ReuseGrid"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::ReuseGrid::*)(cocos2d::Node*)>(&cocos2d::ReuseGrid::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::clone));
mt.set_function("reverse",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ReuseGrid*(*)(int)>(&cocos2d::ReuseGrid::create));
}
void RegisterLuaCoreWaves3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Waves3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Waves3D",false);
ns["Waves3D"] = mt;
lua["Waves3D"] = sol::nil;
mt.set_function("getAmplitude",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Waves3D*(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Waves3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::create));
}
void RegisterLuaCoreFlipX3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FlipX3D",false);
ns["FlipX3D"] = mt;
lua["FlipX3D"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::FlipX3D*(cocos2d::FlipX3D::*)()const>(&cocos2d::FlipX3D::clone));
mt.set_function("update",static_cast<void(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FlipX3D*(*)(float)>(&cocos2d::FlipX3D::create));
}
void RegisterLuaCoreFlipY3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FlipY3D,cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FlipY3D",false);
ns["FlipY3D"] = mt;
lua["FlipY3D"] = sol::nil;
mt.set_function("update",static_cast<void(cocos2d::FlipY3D::*)(float)>(&cocos2d::FlipY3D::update));
mt.set_function("clone",static_cast<cocos2d::FlipY3D*(cocos2d::FlipY3D::*)()const>(&cocos2d::FlipY3D::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FlipY3D*(*)(float)>(&cocos2d::FlipY3D::create));
}
void RegisterLuaCoreShaky3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Shaky3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Shaky3D",false);
ns["Shaky3D"] = mt;
lua["Shaky3D"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::Shaky3D*(cocos2d::Shaky3D::*)()const>(&cocos2d::Shaky3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Shaky3D::*)(float)>(&cocos2d::Shaky3D::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Shaky3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::create));
}
void RegisterLuaCoreLiquidAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Liquid,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Liquid",false);
ns["Liquid"] = mt;
lua["Liquid"] = sol::nil;
mt.set_function("getAmplitude",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Liquid*(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::clone));
mt.set_function("update",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Liquid*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::create));
}
void RegisterLuaCoreWavesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Waves,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Waves",false);
ns["Waves"] = mt;
lua["Waves"] = sol::nil;
mt.set_function("getAmplitude",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Waves*(cocos2d::Waves::*)()const>(&cocos2d::Waves::clone));
mt.set_function("update",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Waves*(*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::create));
}
void RegisterLuaCoreTwirlAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Twirl,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Twirl",false);
ns["Twirl"] = mt;
lua["Twirl"] = sol::nil;
mt.set_function("getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getPosition));
mt.set_function("setPosition",static_cast<void(cocos2d::Twirl::*)(const cocos2d::Vec2&)>(&cocos2d::Twirl::setPosition));
mt.set_function("getAmplitude",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitude));
mt.set_function("setAmplitude",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitude));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitudeRate));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitudeRate));
mt.set_function("clone",static_cast<cocos2d::Twirl*(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::clone));
mt.set_function("update",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Twirl*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::create));
}
