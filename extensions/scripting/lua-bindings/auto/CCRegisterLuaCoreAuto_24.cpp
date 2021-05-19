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
void RegisterLuaCoreCameraBackgroundDepthBrushAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundDepthBrush>("cc","CameraBackgroundDepthBrush",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CameraBackgroundDepthBrush*(*)(float)>(&cocos2d::CameraBackgroundDepthBrush::create));
mt.set_function("GetBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundDepthBrush::*)()const>(&cocos2d::CameraBackgroundDepthBrush::getBrushType));
mt.set_function("DrawBackground",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundDepthBrush::drawBackground));
mt.set_function("SetDepth",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(float)>(&cocos2d::CameraBackgroundDepthBrush::setDepth));
}
void RegisterLuaCoreCameraBackgroundColorBrushAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundColorBrush>("cc","CameraBackgroundColorBrush",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundColorBrush::*)()const>(&cocos2d::CameraBackgroundColorBrush::getBrushType));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundColorBrush::create));
mt.set_function("DrawBackground",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundColorBrush::drawBackground));
mt.set_function("SetColor",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(const cocos2d::Color4F&)>(&cocos2d::CameraBackgroundColorBrush::setColor));
}
void RegisterLuaCoreCameraBackgroundSkyBoxBrushAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundSkyBoxBrush>("cc","CameraBackgroundSkyBoxBrush",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getBrushType));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::create),static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundSkyBoxBrush::create)));
mt.set_function("SetTexture",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::TextureCube*)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTexture));
mt.set_function("GetTexture",static_cast<cocos2d::TextureCube*(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getTexture));
mt.set_function("DrawBackground",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundSkyBoxBrush::drawBackground));
mt.set_function("IsActived",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::isActived));
mt.set_function("SetActived",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setActived));
mt.set_function("SetTextureValid",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTextureValid));
mt.set_function("IsValid",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::isValid));
}
void RegisterLuaCoreGridBaseAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GridBase>("cc","GridBase",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("BeforeBlit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeBlit));
mt.set_function("AfterBlit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::afterBlit));
mt.set_function("Blit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::blit));
mt.set_function("Reuse",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::reuse));
mt.set_function("CalculateVertexPoints",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::calculateVertexPoints));
mt.set_function("InitWithSize",sol::overload(static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize)));
mt.set_function("IsActive",static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isActive));
mt.set_function("SetActive",static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setActive));
mt.set_function("GetReuseGrid",static_cast<int(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getReuseGrid));
mt.set_function("SetReuseGrid",static_cast<void(cocos2d::GridBase::*)(int)>(&cocos2d::GridBase::setReuseGrid));
mt.set_function("GetGridSize",static_cast<const cocos2d::Size&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridSize));
mt.set_function("SetGridSize",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::setGridSize));
mt.set_function("GetStep",static_cast<const cocos2d::Vec2&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getStep));
mt.set_function("SetStep",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Vec2&)>(&cocos2d::GridBase::setStep));
mt.set_function("IsTextureFlipped",static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isTextureFlipped));
mt.set_function("SetTextureFlipped",static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setTextureFlipped));
mt.set_function("BeforeDraw",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeDraw));
mt.set_function("AfterDraw",static_cast<void(cocos2d::GridBase::*)(cocos2d::Node*)>(&cocos2d::GridBase::afterDraw));
mt.set_function("Set2DProjection",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::set2DProjection));
mt.set_function("SetGridRect",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Rect&)>(&cocos2d::GridBase::setGridRect));
mt.set_function("GetGridRect",static_cast<const cocos2d::Rect&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridRect));
}
void RegisterLuaCoreLightTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::LightType>("LightType",{
{"DIRECTIONAL",cocos2d::LightType::DIRECTIONAL}
,{"POINT",cocos2d::LightType::POINT}
,{"SPOT",cocos2d::LightType::SPOT}
,{"AMBIENT",cocos2d::LightType::AMBIENT}
});}
void RegisterLuaCoreLightFlagAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::LightFlag>("LightFlag",{
{"LIGHT0",cocos2d::LightFlag::LIGHT0}
,{"LIGHT1",cocos2d::LightFlag::LIGHT1}
,{"LIGHT2",cocos2d::LightFlag::LIGHT2}
,{"LIGHT3",cocos2d::LightFlag::LIGHT3}
,{"LIGHT4",cocos2d::LightFlag::LIGHT4}
,{"LIGHT5",cocos2d::LightFlag::LIGHT5}
,{"LIGHT6",cocos2d::LightFlag::LIGHT6}
,{"LIGHT7",cocos2d::LightFlag::LIGHT7}
,{"LIGHT8",cocos2d::LightFlag::LIGHT8}
,{"LIGHT9",cocos2d::LightFlag::LIGHT9}
,{"LIGHT10",cocos2d::LightFlag::LIGHT10}
,{"LIGHT11",cocos2d::LightFlag::LIGHT11}
,{"LIGHT12",cocos2d::LightFlag::LIGHT12}
,{"LIGHT13",cocos2d::LightFlag::LIGHT13}
,{"LIGHT14",cocos2d::LightFlag::LIGHT14}
,{"LIGHT15",cocos2d::LightFlag::LIGHT15}
});}
void RegisterLuaCoreBaseLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BaseLight>("cc","BaseLight",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightType));
mt.set_function("GetIntensity",static_cast<float(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getIntensity));
mt.set_function("SetIntensity",static_cast<void(cocos2d::BaseLight::*)(float)>(&cocos2d::BaseLight::setIntensity));
mt.set_function("GetLightFlag",static_cast<cocos2d::LightFlag(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightFlag));
mt.set_function("SetLightFlag",static_cast<void(cocos2d::BaseLight::*)(cocos2d::LightFlag)>(&cocos2d::BaseLight::setLightFlag));
mt.set_function("SetEnabled",static_cast<void(cocos2d::BaseLight::*)(bool)>(&cocos2d::BaseLight::setEnabled));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::isEnabled));
mt.set_function("OnEnter",static_cast<void(cocos2d::BaseLight::*)()>(&cocos2d::BaseLight::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::BaseLight::*)()>(&cocos2d::BaseLight::onExit));
}
void RegisterLuaCoreDirectionLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DirectionLight>("cc","DirectionLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getLightType));
mt.set_function("SetDirection",static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection));
mt.set_function("GetDirection",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection));
mt.set_function("GetDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld));
}
void RegisterLuaCorePointLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PointLight>("cc","PointLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getLightType));
mt.set_function("GetRange",static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange));
mt.set_function("SetRange",static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange));
}
void RegisterLuaCoreSpotLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpotLight>("cc","SpotLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getLightType));
mt.set_function("SetDirection",static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection));
mt.set_function("GetDirection",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection));
mt.set_function("GetDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld));
mt.set_function("SetRange",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange));
mt.set_function("GetRange",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange));
mt.set_function("SetInnerAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle));
mt.set_function("GetInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle));
mt.set_function("GetCosInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle));
mt.set_function("SetOuterAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle));
mt.set_function("GetOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle));
mt.set_function("GetCosOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle));
}
