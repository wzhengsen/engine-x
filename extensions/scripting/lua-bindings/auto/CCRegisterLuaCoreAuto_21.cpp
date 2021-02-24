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
void RegisterLuaCoreTransitionSlideInLAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInL");
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSlideInL::easeActionWithAction));
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::onEnter));
mt.set_function("new",static_cast<cocos2d::TransitionSlideInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInL::create));
}
void RegisterLuaCoreTransitionSlideInRAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInR,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInR");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInR::*)()>(&cocos2d::TransitionSlideInR::action));
mt.set_function("new",static_cast<cocos2d::TransitionSlideInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInR::create));
}
void RegisterLuaCoreTransitionSlideInBAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInB,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInB");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInB::*)()>(&cocos2d::TransitionSlideInB::action));
mt.set_function("new",static_cast<cocos2d::TransitionSlideInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInB::create));
}
void RegisterLuaCoreTransitionSlideInTAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInT,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInT");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInT::*)()>(&cocos2d::TransitionSlideInT::action));
mt.set_function("new",static_cast<cocos2d::TransitionSlideInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInT::create));
}
void RegisterLuaCoreTransitionShrinkGrowAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionShrinkGrow,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionShrinkGrow");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionShrinkGrow::*)()>(&cocos2d::TransitionShrinkGrow::onEnter));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionShrinkGrow::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionShrinkGrow::easeActionWithAction));
mt.set_function("new",static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create));
}
void RegisterLuaCoreTransitionFlipXAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipX");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFlipX::*)()>(&cocos2d::TransitionFlipX::onEnter));
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create)));
}
void RegisterLuaCoreTransitionFlipYAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipY");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFlipY::*)()>(&cocos2d::TransitionFlipY::onEnter));
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create)));
}
void RegisterLuaCoreTransitionFlipAngularAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipAngular");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFlipAngular::*)()>(&cocos2d::TransitionFlipAngular::onEnter));
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create)));
}
void RegisterLuaCoreTransitionZoomFlipXAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipX");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionZoomFlipX::*)()>(&cocos2d::TransitionZoomFlipX::onEnter));
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create)));
}
void RegisterLuaCoreTransitionZoomFlipYAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionZoomFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipY");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionZoomFlipY::*)()>(&cocos2d::TransitionZoomFlipY::onEnter));
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create)));
}
