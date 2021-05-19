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
void RegisterLuaCoreTransitionSlideInRAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInR>("cc","TransitionSlideInR",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInR::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInR::*)()>(&cocos2d::TransitionSlideInR::action));
}
void RegisterLuaCoreTransitionSlideInBAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInB>("cc","TransitionSlideInB",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInB::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInB::*)()>(&cocos2d::TransitionSlideInB::action));
}
void RegisterLuaCoreTransitionSlideInTAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInT>("cc","TransitionSlideInT",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInT::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInT::*)()>(&cocos2d::TransitionSlideInT::action));
}
void RegisterLuaCoreTransitionShrinkGrowAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionShrinkGrow>("cc","TransitionShrinkGrow",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionShrinkGrow::*)()>(&cocos2d::TransitionShrinkGrow::onEnter));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionShrinkGrow::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionShrinkGrow::easeActionWithAction));
}
void RegisterLuaCoreTransitionFlipXAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipX>("cc","TransitionFlipX",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionFlipX::*)()>(&cocos2d::TransitionFlipX::onEnter));
}
void RegisterLuaCoreTransitionFlipYAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipY>("cc","TransitionFlipY",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionFlipY::*)()>(&cocos2d::TransitionFlipY::onEnter));
}
void RegisterLuaCoreTransitionFlipAngularAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipAngular>("cc","TransitionFlipAngular",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create)));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionFlipAngular::*)()>(&cocos2d::TransitionFlipAngular::onEnter));
}
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
