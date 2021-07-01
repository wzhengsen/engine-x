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
void RegisterLuaCoreTransitionZoomFlipYAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionZoomFlipY).name()] = sol::usertype_traits<cocos2d::TransitionZoomFlipY*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionZoomFlipY>("deprecated.cocos2d::TransitionZoomFlipY");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionZoomFlipY*>::metatable(),sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable());
lua["cc"]["TransitionZoomFlipY"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create));
}
void RegisterLuaCoreTransitionZoomFlipAngularAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionZoomFlipAngular).name()] = sol::usertype_traits<cocos2d::TransitionZoomFlipAngular*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionZoomFlipAngular>("deprecated.cocos2d::TransitionZoomFlipAngular");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionZoomFlipAngular*>::metatable(),sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable());
lua["cc"]["TransitionZoomFlipAngular"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipAngular::create),static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipAngular::create));
}
void RegisterLuaCoreTransitionFadeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionFade).name()] = sol::usertype_traits<cocos2d::TransitionFade*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionFade>("deprecated.cocos2d::TransitionFade");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionFade*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionFade"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::create),static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::create));
}
void RegisterLuaCoreTransitionCrossFadeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionCrossFade).name()] = sol::usertype_traits<cocos2d::TransitionCrossFade*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionCrossFade>("deprecated.cocos2d::TransitionCrossFade");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionCrossFade*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionCrossFade"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionCrossFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionCrossFade::create);
}
void RegisterLuaCoreTransitionTurnOffTilesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionTurnOffTiles).name()] = sol::usertype_traits<cocos2d::TransitionTurnOffTiles*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionTurnOffTiles>("deprecated.cocos2d::TransitionTurnOffTiles");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionTurnOffTiles*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable(),sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable());
lua["cc"]["TransitionTurnOffTiles"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionTurnOffTiles*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionTurnOffTiles::create);
}
void RegisterLuaCoreTransitionSplitColsAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionSplitCols).name()] = sol::usertype_traits<cocos2d::TransitionSplitCols*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionSplitCols>("deprecated.cocos2d::TransitionSplitCols");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionSplitCols*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable(),sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable());
lua["cc"]["TransitionSplitCols"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionSplitCols*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitCols::create);
mt["Action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::action);
}
