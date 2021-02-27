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
void RegisterLuaCoreTransitionFlipYAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionFlipY",false);
ns["TransitionFlipY"] = mt;
lua["TransitionFlipY"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFlipY::*)()>(&cocos2d::TransitionFlipY::onEnter));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create)));
}
void RegisterLuaCoreTransitionFlipAngularAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionFlipAngular",false);
ns["TransitionFlipAngular"] = mt;
lua["TransitionFlipAngular"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFlipAngular::*)()>(&cocos2d::TransitionFlipAngular::onEnter));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create)));
}
void RegisterLuaCoreTransitionZoomFlipXAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionZoomFlipX",false);
ns["TransitionZoomFlipX"] = mt;
lua["TransitionZoomFlipX"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionZoomFlipX::*)()>(&cocos2d::TransitionZoomFlipX::onEnter));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create)));
}
void RegisterLuaCoreTransitionZoomFlipYAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionZoomFlipY",false);
ns["TransitionZoomFlipY"] = mt;
lua["TransitionZoomFlipY"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionZoomFlipY::*)()>(&cocos2d::TransitionZoomFlipY::onEnter));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create)));
}
void RegisterLuaCoreTransitionZoomFlipAngularAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionZoomFlipAngular",false);
ns["TransitionZoomFlipAngular"] = mt;
lua["TransitionZoomFlipAngular"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionZoomFlipAngular::*)()>(&cocos2d::TransitionZoomFlipAngular::onEnter));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipAngular::create),static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipAngular::create)));
}
void RegisterLuaCoreTransitionFadeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionFade",false);
ns["TransitionFade"] = mt;
lua["TransitionFade"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFade::*)()>(&cocos2d::TransitionFade::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionFade::*)()>(&cocos2d::TransitionFade::onExit));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::create),static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::create)));
}
void RegisterLuaCoreTransitionCrossFadeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionCrossFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionCrossFade",false);
ns["TransitionCrossFade"] = mt;
lua["TransitionCrossFade"] = sol::nil;
mt.set_function("draw",static_cast<void(cocos2d::TransitionCrossFade::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionCrossFade::draw));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionCrossFade::*)()>(&cocos2d::TransitionCrossFade::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionCrossFade::*)()>(&cocos2d::TransitionCrossFade::onExit));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionCrossFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionCrossFade::create));
}
void RegisterLuaCoreTransitionTurnOffTilesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionTurnOffTiles,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionTurnOffTiles",false);
ns["TransitionTurnOffTiles"] = mt;
lua["TransitionTurnOffTiles"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionTurnOffTiles::*)()>(&cocos2d::TransitionTurnOffTiles::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionTurnOffTiles::*)()>(&cocos2d::TransitionTurnOffTiles::onExit));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionTurnOffTiles::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionTurnOffTiles::easeActionWithAction));
mt.set_function("draw",static_cast<void(cocos2d::TransitionTurnOffTiles::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionTurnOffTiles::draw));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionTurnOffTiles*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionTurnOffTiles::create));
}
void RegisterLuaCoreTransitionSplitColsAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionSplitCols",false);
ns["TransitionSplitCols"] = mt;
lua["TransitionSplitCols"] = sol::nil;
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::action));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::onEnter));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSplitCols::easeActionWithAction));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::onExit));
mt.set_function("draw",static_cast<void(cocos2d::TransitionSplitCols::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionSplitCols::draw));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSplitCols*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitCols::create));
}
void RegisterLuaCoreTransitionSplitRowsAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionSplitRows,cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionSplitRows",false);
ns["TransitionSplitRows"] = mt;
lua["TransitionSplitRows"] = sol::nil;
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitRows::*)()>(&cocos2d::TransitionSplitRows::action));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSplitRows*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitRows::create));
}
