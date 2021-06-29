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
#include "network/CCConnection.h"
void RegisterLuaCoreToggleVisibilityAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ToggleVisibility).name()] = sol::usertype_traits<cocos2d::ToggleVisibility*>::metatable();
auto dep=lua.new_usertype<cocos2d::ToggleVisibility>("deprecated.cocos2d::ToggleVisibility");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ToggleVisibility*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["ToggleVisibility"]=mt;
mt["__new__"]=static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create);
}
void RegisterLuaCoreRemoveSelfAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RemoveSelf).name()] = sol::usertype_traits<cocos2d::RemoveSelf*>::metatable();
auto dep=lua.new_usertype<cocos2d::RemoveSelf>("deprecated.cocos2d::RemoveSelf");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RemoveSelf*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["RemoveSelf"]=mt;
mt["__new__"]=sol::overload([](bool arg0){return cocos2d::RemoveSelf::create(arg0);},[](){return cocos2d::RemoveSelf::create();});
}
void RegisterLuaCoreFlipXAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FlipX).name()] = sol::usertype_traits<cocos2d::FlipX*>::metatable();
auto dep=lua.new_usertype<cocos2d::FlipX>("deprecated.cocos2d::FlipX");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FlipX*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["FlipX"]=mt;
mt["__new__"]=static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create);
}
void RegisterLuaCoreFlipYAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FlipY).name()] = sol::usertype_traits<cocos2d::FlipY*>::metatable();
auto dep=lua.new_usertype<cocos2d::FlipY>("deprecated.cocos2d::FlipY");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FlipY*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["FlipY"]=mt;
mt["__new__"]=static_cast<cocos2d::FlipY*(*)(bool)>(&cocos2d::FlipY::create);
}
void RegisterLuaCorePlaceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Place).name()] = sol::usertype_traits<cocos2d::Place*>::metatable();
auto dep=lua.new_usertype<cocos2d::Place>("deprecated.cocos2d::Place");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Place*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["Place"]=mt;
mt["__new__"]=static_cast<cocos2d::Place*(*)(const cocos2d::Vec2&)>(&cocos2d::Place::create);
}
void RegisterLuaCoreCallFuncAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CallFunc).name()] = sol::usertype_traits<cocos2d::CallFunc*>::metatable();
auto dep=lua.new_usertype<cocos2d::CallFunc>("deprecated.cocos2d::CallFunc");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CallFunc*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["CallFunc"]=mt;
mt["__new__"]=static_cast<cocos2d::CallFunc*(*)(const std::function<void ()>&)>(&cocos2d::CallFunc::create);
mt["Execute"]=static_cast<void(cocos2d::CallFunc::*)()>(&cocos2d::CallFunc::execute);
}
void RegisterLuaCoreGridActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::GridAction).name()] = sol::usertype_traits<cocos2d::GridAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::GridAction>("deprecated.cocos2d::GridAction");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::GridAction*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["GridAction"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetGrid"]=static_cast<cocos2d::GridBase*(cocos2d::GridAction::*)()>(&cocos2d::GridAction::getGrid);
mt["get"]["Grid"]=mt["GetGrid"];
}
void RegisterLuaCoreGrid3DActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Grid3DAction).name()] = sol::usertype_traits<cocos2d::Grid3DAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::Grid3DAction>("deprecated.cocos2d::Grid3DAction");
dep[sol::base_classes]=sol::bases<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Grid3DAction*>::metatable(),sol::usertype_traits<cocos2d::GridAction*>::metatable());
lua["cc"]["Grid3DAction"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetVertex"]=static_cast<cocos2d::Vec3(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3DAction::getVertex);
mt["GetOriginalVertex"]=static_cast<cocos2d::Vec3(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3DAction::getOriginalVertex);
mt["SetVertex"]=static_cast<void(cocos2d::Grid3DAction::*)(const cocos2d::Vec2&,const cocos2d::Vec3&)>(&cocos2d::Grid3DAction::setVertex);
mt["GetGridRect"]=static_cast<cocos2d::Rect(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::getGridRect);
mt["get"]["GridRect"]=mt["GetGridRect"];
}
void RegisterLuaCoreTiledGrid3DActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TiledGrid3DAction).name()] = sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::TiledGrid3DAction>("deprecated.cocos2d::TiledGrid3DAction");
dep[sol::base_classes]=sol::bases<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TiledGrid3DAction*>::metatable(),sol::usertype_traits<cocos2d::GridAction*>::metatable());
lua["cc"]["TiledGrid3DAction"]=mt;
mt["__new__"]=static_cast<cocos2d::TiledGrid3DAction*(*)(float,const cocos2d::Size&)>(&cocos2d::TiledGrid3DAction::create);
mt["GetTile"]=static_cast<cocos2d::Quad3(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3DAction::getTile);
mt["GetOriginalTile"]=static_cast<cocos2d::Quad3(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3DAction::getOriginalTile);
mt["SetTile"]=static_cast<void(cocos2d::TiledGrid3DAction::*)(const cocos2d::Vec2&,const cocos2d::Quad3&)>(&cocos2d::TiledGrid3DAction::setTile);
}
void RegisterLuaCoreStopGridAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::StopGrid).name()] = sol::usertype_traits<cocos2d::StopGrid*>::metatable();
auto dep=lua.new_usertype<cocos2d::StopGrid>("deprecated.cocos2d::StopGrid");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::StopGrid*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["StopGrid"]=mt;
mt["__new__"]=static_cast<cocos2d::StopGrid*(*)()>(&cocos2d::StopGrid::create);
}
