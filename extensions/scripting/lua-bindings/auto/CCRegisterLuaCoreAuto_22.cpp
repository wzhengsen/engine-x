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
void RegisterLuaCoreTransitionZoomFlipXAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipX>("cc","TransitionZoomFlipX",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionZoomFlipX::*)()>(&cocos2d::TransitionZoomFlipX::onEnter));
}
void RegisterLuaCoreTransitionZoomFlipYAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipY>("cc","TransitionZoomFlipY",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionZoomFlipY::*)()>(&cocos2d::TransitionZoomFlipY::onEnter));
}
void RegisterLuaCoreTransitionZoomFlipAngularAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipAngular>("cc","TransitionZoomFlipAngular",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipAngular::create),static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipAngular::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionZoomFlipAngular::*)()>(&cocos2d::TransitionZoomFlipAngular::onEnter));
}
void RegisterLuaCoreTransitionFadeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFade>("cc","TransitionFade",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::create),static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionFade::*)()>(&cocos2d::TransitionFade::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionFade::*)()>(&cocos2d::TransitionFade::onExit));
}
void RegisterLuaCoreTransitionCrossFadeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionCrossFade>("cc","TransitionCrossFade",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionCrossFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionCrossFade::create));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionCrossFade::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionCrossFade::draw));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionCrossFade::*)()>(&cocos2d::TransitionCrossFade::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionCrossFade::*)()>(&cocos2d::TransitionCrossFade::onExit));
}
void RegisterLuaCoreTransitionTurnOffTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionTurnOffTiles>("cc","TransitionTurnOffTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionTurnOffTiles*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionTurnOffTiles::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionTurnOffTiles::*)()>(&cocos2d::TransitionTurnOffTiles::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionTurnOffTiles::*)()>(&cocos2d::TransitionTurnOffTiles::onExit));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionTurnOffTiles::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionTurnOffTiles::easeActionWithAction));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionTurnOffTiles::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionTurnOffTiles::draw));
}
void RegisterLuaCoreTransitionSplitColsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSplitCols>("cc","TransitionSplitCols",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSplitCols*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitCols::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::action));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::onEnter));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSplitCols::easeActionWithAction));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::onExit));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionSplitCols::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionSplitCols::draw));
}
void RegisterLuaCoreTransitionSplitRowsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSplitRows>("cc","TransitionSplitRows",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSplitRows*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitRows::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitRows::*)()>(&cocos2d::TransitionSplitRows::action));
}
void RegisterLuaCoreTransitionFadeTRAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeTR>("cc","TransitionFadeTR",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeTR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeTR::create));
mt.set_function("ActionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeTR::actionWithSize));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionFadeTR::*)()>(&cocos2d::TransitionFadeTR::onEnter));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionFadeTR::easeActionWithAction));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionFadeTR::*)()>(&cocos2d::TransitionFadeTR::onExit));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionFadeTR::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionFadeTR::draw));
}
void RegisterLuaCoreTransitionFadeBLAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeBL>("cc","TransitionFadeBL",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionFadeBL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeBL::create));
mt.set_function("ActionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeBL::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeBL::actionWithSize));
}
