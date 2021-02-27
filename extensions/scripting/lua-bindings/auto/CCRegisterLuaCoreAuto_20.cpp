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
void RegisterLuaCoreTransitionMoveInLAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionMoveInL",false);
ns["TransitionMoveInL"] = mt;
lua["TransitionMoveInL"] = sol::nil;
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::onEnter));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create));
}
void RegisterLuaCoreTransitionMoveInRAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionMoveInR,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionMoveInR",false);
ns["TransitionMoveInR"] = mt;
lua["TransitionMoveInR"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create));
}
void RegisterLuaCoreTransitionMoveInTAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionMoveInT,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionMoveInT",false);
ns["TransitionMoveInT"] = mt;
lua["TransitionMoveInT"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInT::create));
}
void RegisterLuaCoreTransitionMoveInBAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionMoveInB,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionMoveInB",false);
ns["TransitionMoveInB"] = mt;
lua["TransitionMoveInB"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create));
}
void RegisterLuaCoreTransitionSlideInLAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionSlideInL",false);
ns["TransitionSlideInL"] = mt;
lua["TransitionSlideInL"] = sol::nil;
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSlideInL::easeActionWithAction));
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::onEnter));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInL::create));
}
void RegisterLuaCoreTransitionSlideInRAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionSlideInR,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionSlideInR",false);
ns["TransitionSlideInR"] = mt;
lua["TransitionSlideInR"] = sol::nil;
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInR::*)()>(&cocos2d::TransitionSlideInR::action));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInR::create));
}
void RegisterLuaCoreTransitionSlideInBAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionSlideInB,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionSlideInB",false);
ns["TransitionSlideInB"] = mt;
lua["TransitionSlideInB"] = sol::nil;
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInB::*)()>(&cocos2d::TransitionSlideInB::action));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInB::create));
}
void RegisterLuaCoreTransitionSlideInTAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionSlideInT,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionSlideInT",false);
ns["TransitionSlideInT"] = mt;
lua["TransitionSlideInT"] = sol::nil;
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInT::*)()>(&cocos2d::TransitionSlideInT::action));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSlideInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInT::create));
}
void RegisterLuaCoreTransitionShrinkGrowAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionShrinkGrow,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("TransitionShrinkGrow",false);
ns["TransitionShrinkGrow"] = mt;
lua["TransitionShrinkGrow"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionShrinkGrow::*)()>(&cocos2d::TransitionShrinkGrow::onEnter));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionShrinkGrow::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionShrinkGrow::easeActionWithAction));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create));
}
void RegisterLuaCoreTransitionFlipXAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TransitionFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("TransitionFlipX",false);
ns["TransitionFlipX"] = mt;
lua["TransitionFlipX"] = sol::nil;
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionFlipX::*)()>(&cocos2d::TransitionFlipX::onEnter));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create)));
}
