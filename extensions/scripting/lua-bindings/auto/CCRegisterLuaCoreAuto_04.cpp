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
void RegisterLuaCoreJumpByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("JumpBy",false);
ns["JumpBy"] = mt;
lua["JumpBy"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::clone));
mt.set_function("reverse",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::JumpBy::*)(cocos2d::Node*)>(&cocos2d::JumpBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::JumpBy::*)(float)>(&cocos2d::JumpBy::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpBy*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::create));
}
void RegisterLuaCoreJumpToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::JumpTo,cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("JumpTo",false);
ns["JumpTo"] = mt;
lua["JumpTo"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::JumpTo::*)(cocos2d::Node*)>(&cocos2d::JumpTo::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::clone));
mt.set_function("reverse",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpTo*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::create));
}
void RegisterLuaCoreBezierByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("BezierBy",false);
ns["BezierBy"] = mt;
lua["BezierBy"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::clone));
mt.set_function("reverse",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::BezierBy::*)(cocos2d::Node*)>(&cocos2d::BezierBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::BezierBy::*)(float)>(&cocos2d::BezierBy::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::BezierBy*(*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierBy::create));
}
void RegisterLuaCoreBezierToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::BezierTo,cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("BezierTo",false);
ns["BezierTo"] = mt;
lua["BezierTo"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::BezierTo::*)(cocos2d::Node*)>(&cocos2d::BezierTo::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::clone));
mt.set_function("reverse",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::reverse));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::BezierTo*(*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierTo::create));
}
void RegisterLuaCoreScaleToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ScaleTo",false);
ns["ScaleTo"] = mt;
lua["ScaleTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::clone));
mt.set_function("reverse",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ScaleTo::*)(cocos2d::Node*)>(&cocos2d::ScaleTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ScaleTo::*)(float)>(&cocos2d::ScaleTo::update));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ScaleTo*(*)(float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float,float,float)>(&cocos2d::ScaleTo::create)));
}
void RegisterLuaCoreScaleByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ScaleBy,cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ScaleBy",false);
ns["ScaleBy"] = mt;
lua["ScaleBy"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::ScaleBy::*)(cocos2d::Node*)>(&cocos2d::ScaleBy::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::clone));
mt.set_function("reverse",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::reverse));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ScaleBy*(*)(float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float,float,float)>(&cocos2d::ScaleBy::create)));
}
void RegisterLuaCoreBlinkAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Blink,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Blink",false);
ns["Blink"] = mt;
lua["Blink"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::clone));
mt.set_function("reverse",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::reverse));
mt.set_function("update",static_cast<void(cocos2d::Blink::*)(float)>(&cocos2d::Blink::update));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Blink::*)(cocos2d::Node*)>(&cocos2d::Blink::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Blink::*)()>(&cocos2d::Blink::stop));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Blink*(*)(float,int)>(&cocos2d::Blink::create));
}
void RegisterLuaCoreFadeToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeTo",false);
ns["FadeTo"] = mt;
lua["FadeTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::clone));
mt.set_function("reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::FadeTo::*)(cocos2d::Node*)>(&cocos2d::FadeTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::FadeTo::*)(float)>(&cocos2d::FadeTo::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeTo*(*)(float,uint8_t)>(&cocos2d::FadeTo::create));
}
void RegisterLuaCoreFadeInAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeIn,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeIn",false);
ns["FadeIn"] = mt;
lua["FadeIn"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::FadeIn::*)(cocos2d::Node*)>(&cocos2d::FadeIn::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::FadeIn*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::clone));
mt.set_function("reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::reverse));
mt.set_function("setReverseAction",static_cast<void(cocos2d::FadeIn::*)(cocos2d::FadeTo*)>(&cocos2d::FadeIn::setReverseAction));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeIn*(*)(float)>(&cocos2d::FadeIn::create));
}
void RegisterLuaCoreFadeOutAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FadeOut,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("FadeOut",false);
ns["FadeOut"] = mt;
lua["FadeOut"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::FadeOut::*)(cocos2d::Node*)>(&cocos2d::FadeOut::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::FadeOut*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::clone));
mt.set_function("reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::reverse));
mt.set_function("setReverseAction",static_cast<void(cocos2d::FadeOut::*)(cocos2d::FadeTo*)>(&cocos2d::FadeOut::setReverseAction));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOut*(*)(float)>(&cocos2d::FadeOut::create));
}
