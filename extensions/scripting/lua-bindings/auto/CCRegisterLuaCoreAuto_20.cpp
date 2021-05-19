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
void RegisterLuaCoreTransitionEaseSceneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionEaseScene>("cc","TransitionEaseScene",true);
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction));
}
void RegisterLuaCoreTransitionSceneOrientationAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TransitionScene"];
pTable.new_enum<cocos2d::TransitionScene::Orientation>("Orientation",{
{"LEFT_OVER",cocos2d::TransitionScene::Orientation::LEFT_OVER}
,{"RIGHT_OVER",cocos2d::TransitionScene::Orientation::RIGHT_OVER}
,{"UP_OVER",cocos2d::TransitionScene::Orientation::UP_OVER}
,{"DOWN_OVER",cocos2d::TransitionScene::Orientation::DOWN_OVER}
});}
void RegisterLuaCoreTransitionSceneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionScene>("cc","TransitionScene",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create));
mt.set_function("Finish",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish));
mt.set_function("HideOutShowIn",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn));
mt.set_function("GetInScene",static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene));
mt.set_function("GetDuration",static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionScene::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionScene::draw));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::onExit));
mt.set_function("Cleanup",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::cleanup));
RegisterLuaCoreTransitionSceneOrientationAuto(lua);
}
void RegisterLuaCoreTransitionSceneOrientedAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSceneOriented>("cc","TransitionSceneOriented",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create));
}
void RegisterLuaCoreTransitionRotoZoomAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionRotoZoom>("cc","TransitionRotoZoom",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionRotoZoom::*)()>(&cocos2d::TransitionRotoZoom::onEnter));
}
void RegisterLuaCoreTransitionJumpZoomAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionJumpZoom>("cc","TransitionJumpZoom",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionJumpZoom::*)()>(&cocos2d::TransitionJumpZoom::onEnter));
}
void RegisterLuaCoreTransitionMoveInLAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInL>("cc","TransitionMoveInL",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::onEnter));
}
void RegisterLuaCoreTransitionMoveInRAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInR>("cc","TransitionMoveInR",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create));
}
void RegisterLuaCoreTransitionMoveInTAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInT>("cc","TransitionMoveInT",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInT::create));
}
void RegisterLuaCoreTransitionMoveInBAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInB>("cc","TransitionMoveInB",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create));
}
void RegisterLuaCoreTransitionSlideInLAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSlideInL>("cc","TransitionSlideInL",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInL::create));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSlideInL::easeActionWithAction));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::onEnter));
}
