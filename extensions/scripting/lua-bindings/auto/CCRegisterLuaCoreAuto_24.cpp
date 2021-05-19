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
void RegisterLuaCoreCameraFlagAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::CameraFlag>("CameraFlag",{
{"DEFAULT",cocos2d::CameraFlag::DEFAULT}
,{"USER1",cocos2d::CameraFlag::USER1}
,{"USER2",cocos2d::CameraFlag::USER2}
,{"USER3",cocos2d::CameraFlag::USER3}
,{"USER4",cocos2d::CameraFlag::USER4}
,{"USER5",cocos2d::CameraFlag::USER5}
,{"USER6",cocos2d::CameraFlag::USER6}
,{"USER7",cocos2d::CameraFlag::USER7}
,{"USER8",cocos2d::CameraFlag::USER8}
});}
void RegisterLuaCoreCameraTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Camera"];
pTable.new_enum<cocos2d::Camera::Type>("Type",{
{"PERSPECTIVE",cocos2d::Camera::Type::PERSPECTIVE}
,{"ORTHOGRAPHIC",cocos2d::Camera::Type::ORTHOGRAPHIC}
});}
void RegisterLuaCoreCameraAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Camera>("cc","Camera",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreatePerspective",static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createPerspective));
mt.set_function("CreateOrthographic",static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createOrthographic));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::create));
mt.set_function("GetVisitingCamera",static_cast<const cocos2d::Camera*(*)()>(&cocos2d::Camera::getVisitingCamera));
mt.set_function("GetDefaultViewport",static_cast<const cocos2d::Viewport&(*)()>(&cocos2d::Camera::getDefaultViewport));
mt.set_function("SetDefaultViewport",static_cast<void(*)(const cocos2d::Viewport&)>(&cocos2d::Camera::setDefaultViewport));
mt.set_function("GetDefaultCamera",static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::getDefaultCamera));
mt.set_function("GetType",static_cast<cocos2d::Camera::Type(cocos2d::Camera::*)()const>(&cocos2d::Camera::getType));
mt.set_function("GetCameraFlag",static_cast<cocos2d::CameraFlag(cocos2d::Camera::*)()const>(&cocos2d::Camera::getCameraFlag));
mt.set_function("SetCameraFlag",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraFlag)>(&cocos2d::Camera::setCameraFlag));
mt.set_function("LookAt",sol::overload([](cocos2d::Camera* obj,const cocos2d::Vec3& arg0){return obj->lookAt(arg0);},[](cocos2d::Camera* obj,const cocos2d::Vec3& arg0,const cocos2d::Vec3& arg1){return obj->lookAt(arg0,arg1);}));
mt.set_function("GetProjectionMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getProjectionMatrix));
mt.set_function("GetViewMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewMatrix));
mt.set_function("GetViewProjectionMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewProjectionMatrix));
mt.set_function("Project",static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::project));
mt.set_function("ProjectGL",static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::projectGL));
mt.set_function("Unproject",sol::overload(static_cast<void(cocos2d::Camera::*)(const cocos2d::Size&,const cocos2d::Vec3*,cocos2d::Vec3*)const>(&cocos2d::Camera::unproject),static_cast<cocos2d::Vec3(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::unproject)));
mt.set_function("UnprojectGL",sol::overload(static_cast<void(cocos2d::Camera::*)(const cocos2d::Size&,const cocos2d::Vec3*,cocos2d::Vec3*)const>(&cocos2d::Camera::unprojectGL),static_cast<cocos2d::Vec3(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::unprojectGL)));
mt.set_function("IsVisibleInFrustum",static_cast<bool(cocos2d::Camera::*)(const cocos2d::AABB*)const>(&cocos2d::Camera::isVisibleInFrustum));
mt.set_function("GetDepthInView",static_cast<float(cocos2d::Camera::*)(const cocos2d::Mat4&)const>(&cocos2d::Camera::getDepthInView));
mt.set_function("SetDepth",static_cast<void(cocos2d::Camera::*)(int8_t)>(&cocos2d::Camera::setDepth));
mt.set_function("GetDepth",static_cast<int8_t(cocos2d::Camera::*)()const>(&cocos2d::Camera::getDepth));
mt.set_function("GetRenderOrder",static_cast<int(cocos2d::Camera::*)()const>(&cocos2d::Camera::getRenderOrder));
mt.set_function("GetFarPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getFarPlane));
mt.set_function("GetNearPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getNearPlane));
mt.set_function("OnEnter",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::onExit));
mt.set_function("ClearBackground",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::clearBackground));
mt.set_function("Apply",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::apply));
mt.set_function("IsViewProjectionUpdated",static_cast<bool(cocos2d::Camera::*)()const>(&cocos2d::Camera::isViewProjectionUpdated));
mt.set_function("SetBackgroundBrush",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraBackgroundBrush*)>(&cocos2d::Camera::setBackgroundBrush));
mt.set_function("GetBackgroundBrush",static_cast<cocos2d::CameraBackgroundBrush*(cocos2d::Camera::*)()const>(&cocos2d::Camera::getBackgroundBrush));
mt.set_function("Visit",static_cast<void(cocos2d::Camera::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Camera::visit));
mt.set_function("IsBrushValid",static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::isBrushValid));
RegisterLuaCoreCameraTypeAuto(lua);
}
void RegisterLuaCoreCameraBackgroundBrushBrushTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["CameraBackgroundBrush"];
pTable.new_enum<cocos2d::CameraBackgroundBrush::BrushType>("BrushType",{
{"NONE",cocos2d::CameraBackgroundBrush::BrushType::NONE}
,{"DEPTH",cocos2d::CameraBackgroundBrush::BrushType::DEPTH}
,{"COLOR",cocos2d::CameraBackgroundBrush::BrushType::COLOR}
,{"SKYBOX",cocos2d::CameraBackgroundBrush::BrushType::SKYBOX}
});}
void RegisterLuaCoreCameraBackgroundBrushAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundBrush>("cc","CameraBackgroundBrush",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundBrush::*)()const>(&cocos2d::CameraBackgroundBrush::getBrushType));
mt.set_function("CreateNoneBrush",static_cast<cocos2d::CameraBackgroundBrush*(*)()>(&cocos2d::CameraBackgroundBrush::createNoneBrush));
mt.set_function("CreateDepthBrush",sol::overload([](cocos2d::CameraBackgroundBrush* obj){return obj->createDepthBrush();},[](cocos2d::CameraBackgroundBrush* obj,float arg0){return obj->createDepthBrush(arg0);}));
mt.set_function("CreateColorBrush",static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundBrush::createColorBrush));
mt.set_function("CreateSkyboxBrush",static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundBrush::createSkyboxBrush));
mt.set_function("DrawBackground",static_cast<void(cocos2d::CameraBackgroundBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundBrush::drawBackground));
mt.set_function("IsValid",static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::isValid));
RegisterLuaCoreCameraBackgroundBrushBrushTypeAuto(lua);
}
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
void RegisterLuaCoreGrid3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Grid3D>("cc","Grid3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::GridBase,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::Grid3D::create)));
mt.set_function("GetVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3D::getVertex));
mt.set_function("GetOriginalVertex",static_cast<cocos2d::Vec3(cocos2d::Grid3D::*)(const cocos2d::Vec2&)const>(&cocos2d::Grid3D::getOriginalVertex));
mt.set_function("SetVertex",static_cast<void(cocos2d::Grid3D::*)(const cocos2d::Vec2&,const cocos2d::Vec3&)>(&cocos2d::Grid3D::setVertex));
mt.set_function("BeforeBlit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::beforeBlit));
mt.set_function("AfterBlit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::afterBlit));
mt.set_function("Blit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::blit));
mt.set_function("Reuse",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::reuse));
mt.set_function("CalculateVertexPoints",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::calculateVertexPoints));
mt.set_function("SetNeedDepthTestForBlit",static_cast<void(cocos2d::Grid3D::*)(bool)>(&cocos2d::Grid3D::setNeedDepthTestForBlit));
mt.set_function("GetNeedDepthTestForBlit",static_cast<bool(cocos2d::Grid3D::*)()const>(&cocos2d::Grid3D::getNeedDepthTestForBlit));
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
