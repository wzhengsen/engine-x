#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreTransitionEaseSceneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionEaseScene>("cc","TransitionEaseScene");
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction));
}
void RegisterLuaCoreTransitionSceneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionScene");
mt.set_function("finish",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish));
mt.set_function("hideOutShowIn",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn));
mt.set_function("getInScene",static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene));
mt.set_function("getDuration",static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration));
mt.set_function("draw",static_cast<void(cocos2d::TransitionScene::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionScene::draw));
mt.set_function("cleanup",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::cleanup));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TransitionScene::*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::initWithDuration));
mt.set_function("new",static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create));
}
void RegisterLuaCoreTransitionSceneOrientedAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionSceneOriented");
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TransitionSceneOriented::*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::initWithDuration));
mt.set_function("new",static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create));
}
void RegisterLuaCoreTransitionRotoZoomAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionRotoZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionRotoZoom");
mt.set_function("new",static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create));
}
void RegisterLuaCoreTransitionJumpZoomAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionJumpZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionJumpZoom");
mt.set_function("new",static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create));
}
void RegisterLuaCoreTransitionMoveInLAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInL");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction));
mt.set_function("new",static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create));
}
void RegisterLuaCoreTransitionMoveInRAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInR,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInR");
mt.set_function("new",static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create));
}
void RegisterLuaCoreTransitionMoveInTAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInT,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInT");
mt.set_function("new",static_cast<cocos2d::TransitionMoveInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInT::create));
}
void RegisterLuaCoreTransitionMoveInBAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInB,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInB");
mt.set_function("new",static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create));
}
void RegisterLuaCoreTransitionSlideInLAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInL");
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSlideInL::easeActionWithAction));
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action));
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
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionShrinkGrow::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionShrinkGrow::easeActionWithAction));
mt.set_function("new",static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create));
}
void RegisterLuaCoreTransitionFlipXAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipX");
mt.set_function("new",sol::overload(static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create)));
}
