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
void RegisterLuaCoreTransitionPageTurnAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionPageTurn,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionPageTurn");
mt.set_function("draw",static_cast<void(cocos2d::TransitionPageTurn::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionPageTurn::draw));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration));
mt.set_function("actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionPageTurn::*)()>(&cocos2d::TransitionPageTurn::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionPageTurn::*)()>(&cocos2d::TransitionPageTurn::onExit));
mt.set_function("new",static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create));
}
void RegisterLuaCoreTransitionProgressAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgress");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionProgress::*)()>(&cocos2d::TransitionProgress::onExit));
mt.set_function("new",static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create));
}
void RegisterLuaCoreTransitionProgressRadialCCWAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressRadialCCW");
mt.set_function("new",static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create));
}
void RegisterLuaCoreTransitionProgressRadialCWAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressRadialCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressRadialCW");
mt.set_function("new",static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create));
}
void RegisterLuaCoreTransitionProgressHorizontalAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressHorizontal,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressHorizontal");
mt.set_function("new",static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create));
}
void RegisterLuaCoreTransitionProgressVerticalAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressVertical,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressVertical");
mt.set_function("new",static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create));
}
void RegisterLuaCoreTransitionProgressInOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressInOut,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressInOut");
mt.set_function("new",static_cast<cocos2d::TransitionProgressInOut*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressInOut::create));
}
void RegisterLuaCoreTransitionProgressOutInAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgressOutIn,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressOutIn");
mt.set_function("new",static_cast<cocos2d::TransitionProgressOutIn*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressOutIn::create));
}
void RegisterLuaCoreCameraAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Camera,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Camera");
mt.set_function("getType",static_cast<cocos2d::Camera::Type(cocos2d::Camera::*)()const>(&cocos2d::Camera::getType));
mt.set_function("getCameraFlag",static_cast<cocos2d::CameraFlag(cocos2d::Camera::*)()const>(&cocos2d::Camera::getCameraFlag));
mt.set_function("setCameraFlag",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraFlag)>(&cocos2d::Camera::setCameraFlag));
mt.set_function("lookAt",sol::overload([](cocos2d::Camera* obj,const cocos2d::Vec3& arg0){return obj->lookAt(arg0);},[](cocos2d::Camera* obj,const cocos2d::Vec3& arg0,const cocos2d::Vec3& arg1){return obj->lookAt(arg0,arg1);}));
mt.set_function("getProjectionMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getProjectionMatrix));
mt.set_function("getViewMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewMatrix));
mt.set_function("getViewProjectionMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewProjectionMatrix));
mt.set_function("project",static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::project));
mt.set_function("projectGL",static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::projectGL));
mt.set_function("unproject",sol::overload(static_cast<void(cocos2d::Camera::*)(const cocos2d::Size&,const cocos2d::Vec3*,cocos2d::Vec3*)const>(&cocos2d::Camera::unproject),static_cast<cocos2d::Vec3(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::unproject)));
mt.set_function("unprojectGL",sol::overload(static_cast<void(cocos2d::Camera::*)(const cocos2d::Size&,const cocos2d::Vec3*,cocos2d::Vec3*)const>(&cocos2d::Camera::unprojectGL),static_cast<cocos2d::Vec3(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::unprojectGL)));
mt.set_function("isVisibleInFrustum",static_cast<bool(cocos2d::Camera::*)(const cocos2d::AABB*)const>(&cocos2d::Camera::isVisibleInFrustum));
mt.set_function("getDepthInView",static_cast<float(cocos2d::Camera::*)(const cocos2d::Mat4&)const>(&cocos2d::Camera::getDepthInView));
mt.set_function("setDepth",static_cast<void(cocos2d::Camera::*)(int8_t)>(&cocos2d::Camera::setDepth));
mt.set_function("getDepth",static_cast<int8_t(cocos2d::Camera::*)()const>(&cocos2d::Camera::getDepth));
mt.set_function("getRenderOrder",static_cast<int(cocos2d::Camera::*)()const>(&cocos2d::Camera::getRenderOrder));
mt.set_function("getFarPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getFarPlane));
mt.set_function("getNearPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getNearPlane));
mt.set_function("onEnter",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::onExit));
mt.set_function("clearBackground",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::clearBackground));
mt.set_function("apply",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::apply));
mt.set_function("isViewProjectionUpdated",static_cast<bool(cocos2d::Camera::*)()const>(&cocos2d::Camera::isViewProjectionUpdated));
mt.set_function("setBackgroundBrush",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraBackgroundBrush*)>(&cocos2d::Camera::setBackgroundBrush));
mt.set_function("getBackgroundBrush",static_cast<cocos2d::CameraBackgroundBrush*(cocos2d::Camera::*)()const>(&cocos2d::Camera::getBackgroundBrush));
mt.set_function("visit",static_cast<void(cocos2d::Camera::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Camera::visit));
mt.set_function("isBrushValid",static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::isBrushValid));
mt.set_function("createPerspective",static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createPerspective));
mt.set_function("createOrthographic",static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createOrthographic));
mt.set_function("new",static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::create));
mt.set_function("getVisitingCamera",static_cast<const cocos2d::Camera*(*)()>(&cocos2d::Camera::getVisitingCamera));
mt.set_function("getDefaultViewport",static_cast<const cocos2d::Viewport&(*)()>(&cocos2d::Camera::getDefaultViewport));
mt.set_function("setDefaultViewport",static_cast<void(*)(const cocos2d::Viewport&)>(&cocos2d::Camera::setDefaultViewport));
mt.set_function("getDefaultCamera",static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::getDefaultCamera));
}
void RegisterLuaCoreCameraBackgroundBrushAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundBrush");
mt.set_function("getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundBrush::*)()const>(&cocos2d::CameraBackgroundBrush::getBrushType));
mt.set_function("drawBackground",static_cast<void(cocos2d::CameraBackgroundBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundBrush::drawBackground));
mt.set_function("isValid",static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::isValid));
mt.set_function("createNoneBrush",static_cast<cocos2d::CameraBackgroundBrush*(*)()>(&cocos2d::CameraBackgroundBrush::createNoneBrush));
mt.set_function("createDepthBrush",sol::overload([](cocos2d::CameraBackgroundBrush* obj){return obj->createDepthBrush();},[](cocos2d::CameraBackgroundBrush* obj,float arg0){return obj->createDepthBrush(arg0);}));
mt.set_function("createColorBrush",static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundBrush::createColorBrush));
mt.set_function("createSkyboxBrush",static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundBrush::createSkyboxBrush));
}
