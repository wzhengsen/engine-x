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
void RegisterLuaCoreCameraBackgroundDepthBrushAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundDepthBrush");
mt.set_function("getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundDepthBrush::*)()const>(&cocos2d::CameraBackgroundDepthBrush::getBrushType));
mt.set_function("drawBackground",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundDepthBrush::drawBackground));
mt.set_function("setDepth",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(float)>(&cocos2d::CameraBackgroundDepthBrush::setDepth));
mt.set_function("new",static_cast<cocos2d::CameraBackgroundDepthBrush*(*)(float)>(&cocos2d::CameraBackgroundDepthBrush::create));
}
void RegisterLuaCoreCameraBackgroundColorBrushAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundColorBrush,cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundColorBrush");
mt.set_function("getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundColorBrush::*)()const>(&cocos2d::CameraBackgroundColorBrush::getBrushType));
mt.set_function("drawBackground",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundColorBrush::drawBackground));
mt.set_function("setColor",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(const cocos2d::Color4F&)>(&cocos2d::CameraBackgroundColorBrush::setColor));
mt.set_function("new",static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundColorBrush::create));
}
void RegisterLuaCoreCameraBackgroundSkyBoxBrushAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundSkyBoxBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundSkyBoxBrush");
mt.set_function("getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getBrushType));
mt.set_function("setTexture",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::TextureCube*)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTexture));
mt.set_function("getTexture",static_cast<cocos2d::TextureCube*(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getTexture));
mt.set_function("drawBackground",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundSkyBoxBrush::drawBackground));
mt.set_function("isActived",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::isActived));
mt.set_function("setActived",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setActived));
mt.set_function("setTextureValid",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTextureValid));
mt.set_function("isValid",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::isValid));
mt.set_function("new",sol::overload(static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::create),static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundSkyBoxBrush::create)));
}
void RegisterLuaCoreGridBaseAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>("cc","GridBase");
mt.set_function("beforeBlit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeBlit));
mt.set_function("afterBlit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::afterBlit));
mt.set_function("blit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::blit));
mt.set_function("reuse",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::reuse));
mt.set_function("calculateVertexPoints",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::calculateVertexPoints));
mt.set_function("initWithSize",sol::overload(static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize)));
mt.set_function("isActive",static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isActive));
mt.set_function("setActive",static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setActive));
mt.set_function("getReuseGrid",static_cast<int(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getReuseGrid));
mt.set_function("setReuseGrid",static_cast<void(cocos2d::GridBase::*)(int)>(&cocos2d::GridBase::setReuseGrid));
mt.set_function("getGridSize",static_cast<const cocos2d::Size&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridSize));
mt.set_function("setGridSize",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::setGridSize));
mt.set_function("getStep",static_cast<const cocos2d::Vec2&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getStep));
mt.set_function("setStep",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Vec2&)>(&cocos2d::GridBase::setStep));
mt.set_function("isTextureFlipped",static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isTextureFlipped));
mt.set_function("setTextureFlipped",static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setTextureFlipped));
mt.set_function("beforeDraw",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeDraw));
mt.set_function("afterDraw",static_cast<void(cocos2d::GridBase::*)(cocos2d::Node*)>(&cocos2d::GridBase::afterDraw));
mt.set_function("set2DProjection",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::set2DProjection));
mt.set_function("setGridRect",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Rect&)>(&cocos2d::GridBase::setGridRect));
mt.set_function("getGridRect",static_cast<const cocos2d::Rect&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridRect));
}
void RegisterLuaCoreGrid3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Grid3D,cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>("cc","Grid3D");
mt.set_function("getVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3D::getVertex));
mt.set_function("getOriginalVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3D::getOriginalVertex));
mt.set_function("setVertex",static_cast<void(cocos2d::Grid3D::*)(const cocos2d::Vec2&,const cocos2d::Vec3&)>(&cocos2d::Grid3D::setVertex));
mt.set_function("beforeBlit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::beforeBlit));
mt.set_function("afterBlit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::afterBlit));
mt.set_function("blit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::blit));
mt.set_function("reuse",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::reuse));
mt.set_function("calculateVertexPoints",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::calculateVertexPoints));
mt.set_function("setNeedDepthTestForBlit",static_cast<void(cocos2d::Grid3D::*)(bool)>(&cocos2d::Grid3D::setNeedDepthTestForBlit));
mt.set_function("getNeedDepthTestForBlit",static_cast<bool(cocos2d::Grid3D::*)()const>(&cocos2d::Grid3D::getNeedDepthTestForBlit));
mt.set_function("new",sol::overload(static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::Grid3D::create)));
}
void RegisterLuaCoreTiledGrid3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TiledGrid3D,cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>("cc","TiledGrid3D");
mt.set_function("blit",static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::blit));
mt.set_function("reuse",static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::reuse));
mt.set_function("calculateVertexPoints",static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::calculateVertexPoints));
mt.set_function("getTile",static_cast<cocos2d::Quad3(cocos2d::TiledGrid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3D::getTile));
mt.set_function("getOriginalTile",static_cast<cocos2d::Quad3(cocos2d::TiledGrid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::TiledGrid3D::getOriginalTile));
mt.set_function("setTile",static_cast<void(cocos2d::TiledGrid3D::*)(const cocos2d::Vec2&,const cocos2d::Quad3&)>(&cocos2d::TiledGrid3D::setTile));
mt.set_function("new",sol::overload(static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create)));
}
void RegisterLuaCoreBaseLightAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","BaseLight");
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightType));
mt.set_function("getIntensity",static_cast<float(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getIntensity));
mt.set_function("setIntensity",static_cast<void(cocos2d::BaseLight::*)(float)>(&cocos2d::BaseLight::setIntensity));
mt.set_function("getLightFlag",static_cast<cocos2d::LightFlag(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightFlag));
mt.set_function("setLightFlag",static_cast<void(cocos2d::BaseLight::*)(cocos2d::LightFlag)>(&cocos2d::BaseLight::setLightFlag));
mt.set_function("setEnabled",static_cast<void(cocos2d::BaseLight::*)(bool)>(&cocos2d::BaseLight::setEnabled));
mt.set_function("isEnabled",static_cast<bool(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::isEnabled));
mt.set_function("onEnter",static_cast<void(cocos2d::BaseLight::*)()>(&cocos2d::BaseLight::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::BaseLight::*)()>(&cocos2d::BaseLight::onExit));
}
void RegisterLuaCoreDirectionLightAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DirectionLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","DirectionLight");
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getLightType));
mt.set_function("setDirection",static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection));
mt.set_function("getDirection",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection));
mt.set_function("getDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld));
mt.set_function("new",static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create));
}
void RegisterLuaCorePointLightAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PointLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","PointLight");
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getLightType));
mt.set_function("getRange",static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange));
mt.set_function("setRange",static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange));
mt.set_function("new",static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create));
}
void RegisterLuaCoreSpotLightAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpotLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","SpotLight");
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getLightType));
mt.set_function("setDirection",static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection));
mt.set_function("getDirection",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection));
mt.set_function("getDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld));
mt.set_function("setRange",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange));
mt.set_function("getRange",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange));
mt.set_function("setInnerAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle));
mt.set_function("getInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle));
mt.set_function("getCosInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle));
mt.set_function("setOuterAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle));
mt.set_function("getOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle));
mt.set_function("getCosOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle));
mt.set_function("new",static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create));
}
