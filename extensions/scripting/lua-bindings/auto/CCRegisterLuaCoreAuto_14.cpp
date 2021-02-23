#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreTransitionFlipYAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipY");
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create)));
}
void RegisterLuaCoreTransitionFlipAngularAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipAngular");
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create)));
}
void RegisterLuaCoreTransitionZoomFlipXAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipX");
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create)));
}
void RegisterLuaCoreTransitionZoomFlipYAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipY");
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create)));
}
void RegisterLuaCoreTransitionZoomFlipAngularAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipAngular");
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipAngular::create),static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipAngular::create)));
}
void RegisterLuaCoreTransitionFadeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFade");
mt.set_function("initWithDuration",sol::overload(static_cast<bool(cocos2d::TransitionFade::*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::initWithDuration),static_cast<bool(cocos2d::TransitionFade::*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::initWithDuration)));
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::create),static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::create)));
}
void RegisterLuaCoreTransitionCrossFadeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionCrossFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionCrossFade");
mt.set_function("draw",static_cast<void(cocos2d::TransitionCrossFade::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionCrossFade::draw));
mt.set_function("new",static_cast<cocos2d::TransitionCrossFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionCrossFade::create));
}
void RegisterLuaCoreTransitionTurnOffTilesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionTurnOffTiles,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionTurnOffTiles");
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionTurnOffTiles::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionTurnOffTiles::easeActionWithAction));
mt.set_function("draw",static_cast<void(cocos2d::TransitionTurnOffTiles::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionTurnOffTiles::draw));
mt.set_function("new",static_cast<cocos2d::TransitionTurnOffTiles*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionTurnOffTiles::create));
}
void RegisterLuaCoreTransitionSplitColsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSplitCols");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::action));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSplitCols::easeActionWithAction));
mt.set_function("draw",static_cast<void(cocos2d::TransitionSplitCols::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionSplitCols::draw));
mt.set_function("new",static_cast<cocos2d::TransitionSplitCols*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitCols::create));
}
void RegisterLuaCoreTransitionSplitRowsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSplitRows,cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSplitRows");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitRows::*)()>(&cocos2d::TransitionSplitRows::action));
mt.set_function("new",static_cast<cocos2d::TransitionSplitRows*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitRows::create));
}
void RegisterLuaCoreTransitionFadeTRAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeTR");
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeTR::actionWithSize));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionFadeTR::easeActionWithAction));
mt.set_function("draw",static_cast<void(cocos2d::TransitionFadeTR::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionFadeTR::draw));
mt.set_function("new",static_cast<cocos2d::TransitionFadeTR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeTR::create));
}
void RegisterLuaCoreTransitionFadeBLAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeBL,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeBL");
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeBL::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeBL::actionWithSize));
mt.set_function("new",static_cast<cocos2d::TransitionFadeBL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeBL::create));
}
void RegisterLuaCoreTransitionFadeUpAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeUp,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeUp");
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeUp::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeUp::actionWithSize));
mt.set_function("new",static_cast<cocos2d::TransitionFadeUp*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeUp::create));
}
void RegisterLuaCoreTransitionFadeDownAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFadeDown,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeDown");
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeDown::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeDown::actionWithSize));
mt.set_function("new",static_cast<cocos2d::TransitionFadeDown*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeDown::create));
}
void RegisterLuaCoreTransitionPageTurnAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionPageTurn,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionPageTurn");
mt.set_function("draw",static_cast<void(cocos2d::TransitionPageTurn::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionPageTurn::draw));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration));
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize));
mt.set_function("new",static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create));
}
