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
void RegisterLuaCoreTransitionProgressAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgress>("cc","TransitionProgress",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onExit));
}
void RegisterLuaCoreTransitionProgressRadialCCWAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCCW>("cc","TransitionProgressRadialCCW",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create));
}
void RegisterLuaCoreTransitionProgressRadialCWAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCW>("cc","TransitionProgressRadialCW",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create));
}
void RegisterLuaCoreTransitionProgressHorizontalAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressHorizontal>("cc","TransitionProgressHorizontal",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create));
}
void RegisterLuaCoreTransitionProgressVerticalAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressVertical>("cc","TransitionProgressVertical",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create));
}
void RegisterLuaCoreTransitionProgressInOutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressInOut>("cc","TransitionProgressInOut",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressInOut*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressInOut::create));
}
void RegisterLuaCoreTransitionProgressOutInAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressOutIn>("cc","TransitionProgressOutIn",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionProgressOutIn*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressOutIn::create));
}
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
