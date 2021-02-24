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
void RegisterLuaCoreShowAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Show,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Show");
mt.set_function("update",static_cast<void(cocos2d::Show::*)(float)>(&cocos2d::Show::update));
mt.set_function("reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Show::*)()const>(&cocos2d::Show::reverse));
mt.set_function("clone",static_cast<cocos2d::Show*(cocos2d::Show::*)()const>(&cocos2d::Show::clone));
mt.set_function("new",static_cast<cocos2d::Show*(*)()>(&cocos2d::Show::create));
}
void RegisterLuaCoreHideAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Hide,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Hide");
mt.set_function("update",static_cast<void(cocos2d::Hide::*)(float)>(&cocos2d::Hide::update));
mt.set_function("reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Hide::*)()const>(&cocos2d::Hide::reverse));
mt.set_function("clone",static_cast<cocos2d::Hide*(cocos2d::Hide::*)()const>(&cocos2d::Hide::clone));
mt.set_function("new",static_cast<cocos2d::Hide*(*)()>(&cocos2d::Hide::create));
}
void RegisterLuaCoreToggleVisibilityAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ToggleVisibility,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ToggleVisibility");
mt.set_function("update",static_cast<void(cocos2d::ToggleVisibility::*)(float)>(&cocos2d::ToggleVisibility::update));
mt.set_function("reverse",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::reverse));
mt.set_function("clone",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::clone));
mt.set_function("new",static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create));
}
void RegisterLuaCoreRemoveSelfAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RemoveSelf,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RemoveSelf");
mt.set_function("update",static_cast<void(cocos2d::RemoveSelf::*)(float)>(&cocos2d::RemoveSelf::update));
mt.set_function("clone",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::clone));
mt.set_function("reverse",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::reverse));
mt.set_function("new",sol::overload([](cocos2d::RemoveSelf* obj){return obj->create();},[](cocos2d::RemoveSelf* obj,bool arg0){return obj->create(arg0);}));
}
void RegisterLuaCoreFlipXAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipX,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipX");
mt.set_function("update",static_cast<void(cocos2d::FlipX::*)(float)>(&cocos2d::FlipX::update));
mt.set_function("reverse",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::reverse));
mt.set_function("clone",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::clone));
mt.set_function("new",static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create));
}
void RegisterLuaCoreFlipYAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FlipY,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipY");
mt.set_function("update",static_cast<void(cocos2d::FlipY::*)(float)>(&cocos2d::FlipY::update));
mt.set_function("reverse",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::reverse));
mt.set_function("clone",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::clone));
mt.set_function("new",static_cast<cocos2d::FlipY*(*)(bool)>(&cocos2d::FlipY::create));
}
void RegisterLuaCorePlaceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Place,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Place");
mt.set_function("update",static_cast<void(cocos2d::Place::*)(float)>(&cocos2d::Place::update));
mt.set_function("reverse",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::reverse));
mt.set_function("clone",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::clone));
mt.set_function("new",static_cast<cocos2d::Place*(*)(const cocos2d::Vec2&)>(&cocos2d::Place::create));
}
void RegisterLuaCoreCallFuncAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CallFunc,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CallFunc");
mt.set_function("execute",static_cast<void(cocos2d::CallFunc::*)()>(&cocos2d::CallFunc::execute));
mt.set_function("update",static_cast<void(cocos2d::CallFunc::*)(float)>(&cocos2d::CallFunc::update));
mt.set_function("reverse",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::reverse));
mt.set_function("clone",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::clone));
mt.set_function("new",static_cast<cocos2d::CallFunc*(*)(const std::function<void ()>&)>(&cocos2d::CallFunc::create));
}
void RegisterLuaCoreGridActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","GridAction");
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::GridAction::*)()>(&cocos2d::GridAction::getGrid));
mt.set_function("clone",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::clone));
mt.set_function("reverse",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::GridAction::*)(cocos2d::Node*)>(&cocos2d::GridAction::startWithTarget));
}
void RegisterLuaCoreGrid3DActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Grid3DAction");
mt.set_function("getGrid",static_cast<cocos2d::GridBase*(cocos2d::Grid3DAction::*)()>(&cocos2d::Grid3DAction::getGrid));
mt.set_function("getVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3DAction::getVertex));
mt.set_function("getOriginalVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3DAction::getOriginalVertex));
mt.set_function("setVertex",static_cast<void(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&,const cocos2d::Vec3&)>(&cocos2d::Grid3DAction::setVertex));
mt.set_function("clone",static_cast<cocos2d::Grid3DAction*(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::clone));
mt.set_function("getGridRect",static_cast<cocos2d::Rect(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::getGridRect));
}
