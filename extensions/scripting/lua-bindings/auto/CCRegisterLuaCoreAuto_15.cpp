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
namespace cocos2d{
void RegisterLuaCoreShuffleTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ShuffleTiles).name()] = sol::usertype_traits<cocos2d::ShuffleTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::ShuffleTiles>("deprecated.cocos2d::ShuffleTiles");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ShuffleTiles*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["ShuffleTiles"]=mt;
mt["__new__"]=static_cast<cocos2d::ShuffleTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::create);
mt["Shuffle"]=static_cast<void(cocos2d::ShuffleTiles::*)(unsigned int*,unsigned int)>(&cocos2d::ShuffleTiles::shuffle);
mt["GetDelta"]=static_cast<cocos2d::Size(cocos2d::ShuffleTiles::*)(const cocos2d::Size&)const>(&cocos2d::ShuffleTiles::getDelta);
mt["PlaceTile"]=static_cast<void(cocos2d::ShuffleTiles::*)(const cocos2d::Vec2&,cocos2d::Tile*)>(&cocos2d::ShuffleTiles::placeTile);
}
void RegisterLuaCoreFadeOutTRTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeOutTRTiles).name()] = sol::usertype_traits<cocos2d::FadeOutTRTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeOutTRTiles>("deprecated.cocos2d::FadeOutTRTiles");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeOutTRTiles*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["FadeOutTRTiles"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeOutTRTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutTRTiles::create);
mt["TestFunc"]=static_cast<float(cocos2d::FadeOutTRTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutTRTiles::testFunc);
mt["TurnOnTile"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOnTile);
mt["TurnOffTile"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOffTile);
mt["TransformTile"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutTRTiles::transformTile);
}
void RegisterLuaCoreFadeOutBLTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeOutBLTiles).name()] = sol::usertype_traits<cocos2d::FadeOutBLTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeOutBLTiles>("deprecated.cocos2d::FadeOutBLTiles");
dep[sol::base_classes]=sol::bases<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeOutBLTiles*>::metatable(),sol::usertype_traits<cocos2d::FadeOutTRTiles*>::metatable());
lua["cc"]["FadeOutBLTiles"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create);
}
void RegisterLuaCoreFadeOutUpTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeOutUpTiles).name()] = sol::usertype_traits<cocos2d::FadeOutUpTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeOutUpTiles>("deprecated.cocos2d::FadeOutUpTiles");
dep[sol::base_classes]=sol::bases<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeOutUpTiles*>::metatable(),sol::usertype_traits<cocos2d::FadeOutTRTiles*>::metatable());
lua["cc"]["FadeOutUpTiles"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create);
}
void RegisterLuaCoreFadeOutDownTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FadeOutDownTiles).name()] = sol::usertype_traits<cocos2d::FadeOutDownTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::FadeOutDownTiles>("deprecated.cocos2d::FadeOutDownTiles");
dep[sol::base_classes]=sol::bases<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FadeOutDownTiles*>::metatable(),sol::usertype_traits<cocos2d::FadeOutUpTiles*>::metatable());
lua["cc"]["FadeOutDownTiles"]=mt;
mt["__new__"]=static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create);
}
void RegisterLuaCoreTurnOffTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TurnOffTiles).name()] = sol::usertype_traits<cocos2d::TurnOffTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::TurnOffTiles>("deprecated.cocos2d::TurnOffTiles");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TurnOffTiles*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["TurnOffTiles"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create));
mt["Shuffle"]=static_cast<void(cocos2d::TurnOffTiles::*)(unsigned int*,unsigned int)>(&cocos2d::TurnOffTiles::shuffle);
mt["TurnOnTile"]=static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile);
mt["TurnOffTile"]=static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile);
}
void RegisterLuaCoreWavesTiles3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::WavesTiles3D).name()] = sol::usertype_traits<cocos2d::WavesTiles3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::WavesTiles3D>("deprecated.cocos2d::WavesTiles3D");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::WavesTiles3D*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["WavesTiles3D"]=mt;
mt["__new__"]=static_cast<cocos2d::WavesTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::create);
mt["GetAmplitude"]=static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
void RegisterLuaCoreJumpTiles3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::JumpTiles3D).name()] = sol::usertype_traits<cocos2d::JumpTiles3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::JumpTiles3D>("deprecated.cocos2d::JumpTiles3D");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::JumpTiles3D*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["JumpTiles3D"]=mt;
mt["__new__"]=static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create);
mt["GetAmplitude"]=static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
void RegisterLuaCoreSplitRowsAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SplitRows).name()] = sol::usertype_traits<cocos2d::SplitRows*>::metatable();
auto dep=lua.new_usertype<cocos2d::SplitRows>("deprecated.cocos2d::SplitRows");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SplitRows*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["SplitRows"]=mt;
mt["__new__"]=static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create);
}
void RegisterLuaCoreSplitColsAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SplitCols).name()] = sol::usertype_traits<cocos2d::SplitCols*>::metatable();
auto dep=lua.new_usertype<cocos2d::SplitCols>("deprecated.cocos2d::SplitCols");
dep[sol::base_classes]=sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SplitCols*>::metatable(),sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable());
lua["cc"]["SplitCols"]=mt;
mt["__new__"]=static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create);
}
}
