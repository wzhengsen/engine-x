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
void RegisterLuaCoreGrid3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Grid3D).name()] = sol::usertype_traits<cocos2d::Grid3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Grid3D>("deprecated.cocos2d::Grid3D");
dep[sol::base_classes]=sol::bases<cocos2d::GridBase,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Grid3D*>::metatable(),sol::usertype_traits<cocos2d::GridBase*>::metatable());
lua["cc"]["Grid3D"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&)>(&cocos2d::Grid3D::create));
mt["GetVertex"]=static_cast<cocos2d::Vec3(cocos2d::Grid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3D::getVertex);
mt["GetOriginalVertex"]=static_cast<cocos2d::Vec3(cocos2d::Grid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3D::getOriginalVertex);
mt["SetVertex"]=static_cast<void(cocos2d::Grid3D::*)(const cocos2d::Vec2&,const cocos2d::Vec3&)>(&cocos2d::Grid3D::setVertex);
mt["SetNeedDepthTestForBlit"]=static_cast<void(cocos2d::Grid3D::*)(bool)>(&cocos2d::Grid3D::setNeedDepthTestForBlit);
mt["set"]["NeedDepthTestForBlit"]=mt["SetNeedDepthTestForBlit"];
mt["GetNeedDepthTestForBlit"]=static_cast<bool(cocos2d::Grid3D::*)()const>(&cocos2d::Grid3D::getNeedDepthTestForBlit);
mt["get"]["NeedDepthTestForBlit"]=mt["GetNeedDepthTestForBlit"];
}
void RegisterLuaCoreLightTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["DIRECTIONAL"]=cocos2d::LightType::DIRECTIONAL;
enumTable["POINT"]=cocos2d::LightType::POINT;
enumTable["SPOT"]=cocos2d::LightType::SPOT;
enumTable["AMBIENT"]=cocos2d::LightType::AMBIENT;
lua["cc"]["LightType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreLightFlagAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,16);
enumTable["LIGHT0"]=cocos2d::LightFlag::LIGHT0;
enumTable["LIGHT1"]=cocos2d::LightFlag::LIGHT1;
enumTable["LIGHT2"]=cocos2d::LightFlag::LIGHT2;
enumTable["LIGHT3"]=cocos2d::LightFlag::LIGHT3;
enumTable["LIGHT4"]=cocos2d::LightFlag::LIGHT4;
enumTable["LIGHT5"]=cocos2d::LightFlag::LIGHT5;
enumTable["LIGHT6"]=cocos2d::LightFlag::LIGHT6;
enumTable["LIGHT7"]=cocos2d::LightFlag::LIGHT7;
enumTable["LIGHT8"]=cocos2d::LightFlag::LIGHT8;
enumTable["LIGHT9"]=cocos2d::LightFlag::LIGHT9;
enumTable["LIGHT10"]=cocos2d::LightFlag::LIGHT10;
enumTable["LIGHT11"]=cocos2d::LightFlag::LIGHT11;
enumTable["LIGHT12"]=cocos2d::LightFlag::LIGHT12;
enumTable["LIGHT13"]=cocos2d::LightFlag::LIGHT13;
enumTable["LIGHT14"]=cocos2d::LightFlag::LIGHT14;
enumTable["LIGHT15"]=cocos2d::LightFlag::LIGHT15;
lua["cc"]["LightFlag"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreBaseLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::BaseLight).name()] = sol::usertype_traits<cocos2d::BaseLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::BaseLight>("deprecated.cocos2d::BaseLight");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::BaseLight*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["BaseLight"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetLightType"]=static_cast<cocos2d::LightType(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightType);
mt["get"]["LightType"]=mt["GetLightType"];
mt["GetIntensity"]=static_cast<float(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getIntensity);
mt["get"]["Intensity"]=mt["GetIntensity"];
mt["SetIntensity"]=static_cast<void(cocos2d::BaseLight::*)(float)>(&cocos2d::BaseLight::setIntensity);
mt["set"]["Intensity"]=mt["SetIntensity"];
mt["GetLightFlag"]=static_cast<cocos2d::LightFlag(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightFlag);
mt["get"]["LightFlag"]=mt["GetLightFlag"];
mt["SetLightFlag"]=static_cast<void(cocos2d::BaseLight::*)(cocos2d::LightFlag)>(&cocos2d::BaseLight::setLightFlag);
mt["set"]["LightFlag"]=mt["SetLightFlag"];
mt["SetEnabled"]=static_cast<void(cocos2d::BaseLight::*)(bool)>(&cocos2d::BaseLight::setEnabled);
mt["set"]["Enabled"]=mt["SetEnabled"];
mt["IsEnabled"]=static_cast<bool(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::isEnabled);
mt["get"]["Enabled"]=mt["IsEnabled"];
}
void RegisterLuaCoreDirectionLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::DirectionLight).name()] = sol::usertype_traits<cocos2d::DirectionLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::DirectionLight>("deprecated.cocos2d::DirectionLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::DirectionLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["DirectionLight"]=mt;
mt["__new__"]=static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create);
mt["SetDirection"]=static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection);
mt["set"]["Direction"]=mt["SetDirection"];
mt["GetDirection"]=static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection);
mt["get"]["Direction"]=mt["GetDirection"];
mt["GetDirectionInWorld"]=static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld);
mt["get"]["DirectionInWorld"]=mt["GetDirectionInWorld"];
}
void RegisterLuaCorePointLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PointLight).name()] = sol::usertype_traits<cocos2d::PointLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::PointLight>("deprecated.cocos2d::PointLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PointLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["PointLight"]=mt;
mt["__new__"]=static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create);
mt["GetRange"]=static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange);
mt["get"]["Range"]=mt["GetRange"];
mt["SetRange"]=static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange);
mt["set"]["Range"]=mt["SetRange"];
}
void RegisterLuaCoreSpotLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SpotLight).name()] = sol::usertype_traits<cocos2d::SpotLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::SpotLight>("deprecated.cocos2d::SpotLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SpotLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["SpotLight"]=mt;
mt["__new__"]=static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create);
mt["SetDirection"]=static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection);
mt["set"]["Direction"]=mt["SetDirection"];
mt["GetDirection"]=static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection);
mt["get"]["Direction"]=mt["GetDirection"];
mt["GetDirectionInWorld"]=static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld);
mt["get"]["DirectionInWorld"]=mt["GetDirectionInWorld"];
mt["SetRange"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange);
mt["set"]["Range"]=mt["SetRange"];
mt["GetRange"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange);
mt["get"]["Range"]=mt["GetRange"];
mt["SetInnerAngle"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle);
mt["set"]["InnerAngle"]=mt["SetInnerAngle"];
mt["GetInnerAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle);
mt["get"]["InnerAngle"]=mt["GetInnerAngle"];
mt["GetCosInnerAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle);
mt["get"]["CosInnerAngle"]=mt["GetCosInnerAngle"];
mt["SetOuterAngle"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle);
mt["set"]["OuterAngle"]=mt["SetOuterAngle"];
mt["GetOuterAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle);
mt["get"]["OuterAngle"]=mt["GetOuterAngle"];
mt["GetCosOuterAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle);
mt["get"]["CosOuterAngle"]=mt["GetCosOuterAngle"];
}
void RegisterLuaCoreAmbientLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AmbientLight).name()] = sol::usertype_traits<cocos2d::AmbientLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::AmbientLight>("deprecated.cocos2d::AmbientLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AmbientLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["AmbientLight"]=mt;
mt["__new__"]=static_cast<cocos2d::AmbientLight*(*)(const cocos2d::Color3B&)>(&cocos2d::AmbientLight::create);
}
void RegisterLuaCoreRenderStateAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RenderState).name()] = sol::usertype_traits<cocos2d::RenderState*>::metatable();
auto dep=lua.new_usertype<cocos2d::RenderState>("deprecated.cocos2d::RenderState");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RenderState*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["RenderState"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetName"]=static_cast<std::string(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getName);
mt["get"]["Name"]=mt["GetName"];
mt["BindPass"]=static_cast<void(cocos2d::RenderState::*)(cocos2d::Pass*,cocos2d::MeshCommand*)>(&cocos2d::RenderState::bindPass);
mt["GetStateBlock"]=static_cast<cocos2d::RenderState::StateBlock&(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getStateBlock);
mt["get"]["StateBlock"]=mt["GetStateBlock"];
}
void RegisterLuaCoreTechniqueAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Technique).name()] = sol::usertype_traits<cocos2d::Technique*>::metatable();
auto dep=lua.new_usertype<cocos2d::Technique>("deprecated.cocos2d::Technique");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Technique*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Technique"]=mt;
mt["static"]["CreateWithProgramState"]=static_cast<cocos2d::Technique*(*)(cocos2d::Material*,cocos2d::backend::ProgramState*)>(&cocos2d::Technique::createWithProgramState);
mt["__new__"]=static_cast<cocos2d::Technique*(*)(cocos2d::Material*)>(&cocos2d::Technique::create);
mt["AddPass"]=static_cast<void(cocos2d::Technique::*)(cocos2d::Pass*)>(&cocos2d::Technique::addPass);
mt["GetName"]=static_cast<std::string(cocos2d::Technique::*)()const>(&cocos2d::Technique::getName);
mt["get"]["Name"]=mt["GetName"];
mt["GetPassByIndex"]=static_cast<cocos2d::Pass*(cocos2d::Technique::*)(ssize_t)const>(&cocos2d::Technique::getPassByIndex);
mt["GetPassCount"]=static_cast<ssize_t(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPassCount);
mt["get"]["PassCount"]=mt["GetPassCount"];
mt["GetPasses"]=static_cast<const cocos2d::Vector<cocos2d::Pass *>&(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPasses);
mt["get"]["Passes"]=mt["GetPasses"];
mt["Clone"]=static_cast<cocos2d::Technique*(cocos2d::Technique::*)()const>(&cocos2d::Technique::clone);
mt["SetMaterial"]=static_cast<void(cocos2d::Technique::*)(cocos2d::Material*)>(&cocos2d::Technique::setMaterial);
mt["set"]["Material"]=mt["SetMaterial"];
mt["GetStateBlock"]=static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Technique::*)()>(&cocos2d::Technique::getStateBlock);
mt["get"]["StateBlock"]=mt["GetStateBlock"];
}
