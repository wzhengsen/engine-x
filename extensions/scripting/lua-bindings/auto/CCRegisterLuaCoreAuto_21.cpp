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
namespace cocos2d{
void RegisterLuaCoreTransitionMoveInBAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionMoveInB).name()] = sol::usertype_traits<cocos2d::TransitionMoveInB*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionMoveInB>("deprecated.cocos2d::TransitionMoveInB");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionMoveInB*>::metatable(),sol::usertype_traits<cocos2d::TransitionMoveInL*>::metatable());
lua["cc"]["TransitionMoveInB"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create);
}
void RegisterLuaCoreTransitionSlideInLAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionSlideInL).name()] = sol::usertype_traits<cocos2d::TransitionSlideInL*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionSlideInL>("deprecated.cocos2d::TransitionSlideInL");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionSlideInL*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable(),sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable());
lua["cc"]["TransitionSlideInL"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionSlideInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInL::create);
mt["Action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action);
}
void RegisterLuaCoreTransitionSlideInRAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionSlideInR).name()] = sol::usertype_traits<cocos2d::TransitionSlideInR*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionSlideInR>("deprecated.cocos2d::TransitionSlideInR");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionSlideInR*>::metatable(),sol::usertype_traits<cocos2d::TransitionSlideInL*>::metatable());
lua["cc"]["TransitionSlideInR"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionSlideInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInR::create);
}
void RegisterLuaCoreTransitionSlideInBAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionSlideInB).name()] = sol::usertype_traits<cocos2d::TransitionSlideInB*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionSlideInB>("deprecated.cocos2d::TransitionSlideInB");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionSlideInB*>::metatable(),sol::usertype_traits<cocos2d::TransitionSlideInL*>::metatable());
lua["cc"]["TransitionSlideInB"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionSlideInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInB::create);
}
void RegisterLuaCoreTransitionSlideInTAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionSlideInT).name()] = sol::usertype_traits<cocos2d::TransitionSlideInT*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionSlideInT>("deprecated.cocos2d::TransitionSlideInT");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionSlideInT*>::metatable(),sol::usertype_traits<cocos2d::TransitionSlideInL*>::metatable());
lua["cc"]["TransitionSlideInT"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionSlideInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInT::create);
}
void RegisterLuaCoreTransitionShrinkGrowAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionShrinkGrow).name()] = sol::usertype_traits<cocos2d::TransitionShrinkGrow*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionShrinkGrow>("deprecated.cocos2d::TransitionShrinkGrow");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionShrinkGrow*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable(),sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable());
lua["cc"]["TransitionShrinkGrow"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create);
}
void RegisterLuaCoreTransitionFlipXAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFlipX).name()] = sol::usertype_traits<cocos2d::TransitionFlipX*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFlipX>("deprecated.cocos2d::TransitionFlipX");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFlipX*>::metatable(),sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable());
lua["cc"]["TransitionFlipX"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create));
}
void RegisterLuaCoreTransitionFlipYAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFlipY).name()] = sol::usertype_traits<cocos2d::TransitionFlipY*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFlipY>("deprecated.cocos2d::TransitionFlipY");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFlipY*>::metatable(),sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable());
lua["cc"]["TransitionFlipY"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create));
}
void RegisterLuaCoreTransitionFlipAngularAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFlipAngular).name()] = sol::usertype_traits<cocos2d::TransitionFlipAngular*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFlipAngular>("deprecated.cocos2d::TransitionFlipAngular");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFlipAngular*>::metatable(),sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable());
lua["cc"]["TransitionFlipAngular"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create));
}
void RegisterLuaCoreTransitionZoomFlipXAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionZoomFlipX).name()] = sol::usertype_traits<cocos2d::TransitionZoomFlipX*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionZoomFlipX>("deprecated.cocos2d::TransitionZoomFlipX");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionZoomFlipX*>::metatable(),sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable());
lua["cc"]["TransitionZoomFlipX"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create));
}
}
