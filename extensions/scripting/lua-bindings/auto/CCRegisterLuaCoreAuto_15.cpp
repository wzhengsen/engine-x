#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreTransitionProgressAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgress");
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
mt.set_function("isVisibleInFrustum",static_cast<bool(cocos2d::Camera::*)(const cocos2d::AABB*)const>(&cocos2d::Camera::isVisibleInFrustum));
mt.set_function("getDepthInView",static_cast<float(cocos2d::Camera::*)(const cocos2d::Mat4&)const>(&cocos2d::Camera::getDepthInView));
mt.set_function("setDepth",static_cast<void(cocos2d::Camera::*)(int8_t)>(&cocos2d::Camera::setDepth));
mt.set_function("getDepth",static_cast<int8_t(cocos2d::Camera::*)()const>(&cocos2d::Camera::getDepth));
mt.set_function("getRenderOrder",static_cast<int(cocos2d::Camera::*)()const>(&cocos2d::Camera::getRenderOrder));
mt.set_function("getFarPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getFarPlane));
mt.set_function("getNearPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getNearPlane));
mt.set_function("clearBackground",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::clearBackground));
mt.set_function("apply",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::apply));
mt.set_function("isViewProjectionUpdated",static_cast<bool(cocos2d::Camera::*)()const>(&cocos2d::Camera::isViewProjectionUpdated));
mt.set_function("setBackgroundBrush",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraBackgroundBrush*)>(&cocos2d::Camera::setBackgroundBrush));
mt.set_function("getBackgroundBrush",static_cast<cocos2d::CameraBackgroundBrush*(cocos2d::Camera::*)()const>(&cocos2d::Camera::getBackgroundBrush));
mt.set_function("visit",static_cast<void(cocos2d::Camera::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Camera::visit));
mt.set_function("isBrushValid",static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::isBrushValid));
mt.set_function("setScene",static_cast<void(cocos2d::Camera::*)(cocos2d::Scene*)>(&cocos2d::Camera::setScene));
mt.set_function("setAdditionalProjection",static_cast<void(cocos2d::Camera::*)(const cocos2d::Mat4&)>(&cocos2d::Camera::setAdditionalProjection));
mt.set_function("initDefault",static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::initDefault));
mt.set_function("initPerspective",static_cast<bool(cocos2d::Camera::*)(float,float,float,float)>(&cocos2d::Camera::initPerspective));
mt.set_function("initOrthographic",static_cast<bool(cocos2d::Camera::*)(float,float,float,float)>(&cocos2d::Camera::initOrthographic));
mt.set_function("applyViewport",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::applyViewport));
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
mt.set_function("init",static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::init));
mt.set_function("createNoneBrush",static_cast<cocos2d::CameraBackgroundBrush*(*)()>(&cocos2d::CameraBackgroundBrush::createNoneBrush));
mt.set_function("createDepthBrush",sol::overload([](cocos2d::CameraBackgroundBrush* obj){return obj->createDepthBrush();},[](cocos2d::CameraBackgroundBrush* obj,float arg0){return obj->createDepthBrush(arg0);}));
mt.set_function("createColorBrush",static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundBrush::createColorBrush));
mt.set_function("createSkyboxBrush",static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundBrush::createSkyboxBrush));
}
void RegisterLuaCoreCameraBackgroundDepthBrushAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundDepthBrush");
mt.set_function("getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundDepthBrush::*)()const>(&cocos2d::CameraBackgroundDepthBrush::getBrushType));
mt.set_function("drawBackground",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundDepthBrush::drawBackground));
mt.set_function("setDepth",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(float)>(&cocos2d::CameraBackgroundDepthBrush::setDepth));
mt.set_function("init",static_cast<bool(cocos2d::CameraBackgroundDepthBrush::*)()>(&cocos2d::CameraBackgroundDepthBrush::init));
mt.set_function("new",static_cast<cocos2d::CameraBackgroundDepthBrush*(*)(float)>(&cocos2d::CameraBackgroundDepthBrush::create));
}
void RegisterLuaCoreCameraBackgroundColorBrushAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CameraBackgroundColorBrush,cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundColorBrush");
mt.set_function("getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundColorBrush::*)()const>(&cocos2d::CameraBackgroundColorBrush::getBrushType));
mt.set_function("drawBackground",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundColorBrush::drawBackground));
mt.set_function("setColor",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(const cocos2d::Color4F&)>(&cocos2d::CameraBackgroundColorBrush::setColor));
mt.set_function("init",static_cast<bool(cocos2d::CameraBackgroundColorBrush::*)()>(&cocos2d::CameraBackgroundColorBrush::init));
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
mt.set_function("init",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::init));
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
mt.set_function("new",sol::overload(static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create)));
}
