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
void RegisterLuaCoreCameraTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,2);
enumTable["PERSPECTIVE"]=cocos2d::Camera::Type::PERSPECTIVE;
enumTable["ORTHOGRAPHIC"]=cocos2d::Camera::Type::ORTHOGRAPHIC;
lua["cc"]["Camera"]["static"]["Type"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreCameraAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Camera).name()] = sol::usertype_traits<cocos2d::Camera*>::metatable();
auto dep=lua.new_usertype<cocos2d::Camera>("deprecated.cocos2d::Camera");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Camera*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["Camera"]=mt;
mt["static"]["CreatePerspective"]=static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createPerspective);
mt["static"]["CreateOrthographic"]=static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createOrthographic);
mt["__new__"]=static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::create);
mt["static"]["GetVisitingCamera"]=static_cast<const cocos2d::Camera*(*)()>(&cocos2d::Camera::getVisitingCamera);
mt["static"]["get"]["VisitingCamera"]=mt["GetVisitingCamera"];
mt["static"]["GetDefaultViewport"]=static_cast<const cocos2d::Viewport&(*)()>(&cocos2d::Camera::getDefaultViewport);
mt["static"]["get"]["DefaultViewport"]=mt["GetDefaultViewport"];
mt["static"]["SetDefaultViewport"]=static_cast<void(*)(const cocos2d::Viewport&)>(&cocos2d::Camera::setDefaultViewport);
mt["static"]["set"]["DefaultViewport"]=mt["SetDefaultViewport"];
mt["static"]["GetDefaultCamera"]=static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::getDefaultCamera);
mt["static"]["get"]["DefaultCamera"]=mt["GetDefaultCamera"];
mt["GetType"]=static_cast<cocos2d::Camera::Type(cocos2d::Camera::*)()const>(&cocos2d::Camera::getType);
mt["get"]["Type"]=mt["GetType"];
mt["GetCameraFlag"]=static_cast<cocos2d::CameraFlag(cocos2d::Camera::*)()const>(&cocos2d::Camera::getCameraFlag);
mt["get"]["CameraFlag"]=mt["GetCameraFlag"];
mt["SetCameraFlag"]=static_cast<void(cocos2d::Camera::*)(cocos2d::CameraFlag)>(&cocos2d::Camera::setCameraFlag);
mt["set"]["CameraFlag"]=mt["SetCameraFlag"];
mt["LookAt"]=sol::overload([](cocos2d::Camera* obj,const cocos2d::Vec3& arg0,const cocos2d::Vec3& arg1){return obj->lookAt(arg0,arg1);},[](cocos2d::Camera* obj,const cocos2d::Vec3& arg0){return obj->lookAt(arg0);});
mt["GetProjectionMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getProjectionMatrix);
mt["get"]["ProjectionMatrix"]=mt["GetProjectionMatrix"];
mt["GetViewMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewMatrix);
mt["get"]["ViewMatrix"]=mt["GetViewMatrix"];
mt["GetViewProjectionMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewProjectionMatrix);
mt["get"]["ViewProjectionMatrix"]=mt["GetViewProjectionMatrix"];
mt["Project"]=static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::project);
mt["ProjectGL"]=static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::projectGL);
mt["Unproject"]=sol::overload(static_cast<void(cocos2d::Camera::*)(const cocos2d::Size&,const cocos2d::Vec3*,cocos2d::Vec3*)const>(&cocos2d::Camera::unproject),static_cast<cocos2d::Vec3(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::unproject));
mt["UnprojectGL"]=sol::overload(static_cast<void(cocos2d::Camera::*)(const cocos2d::Size&,const cocos2d::Vec3*,cocos2d::Vec3*)const>(&cocos2d::Camera::unprojectGL),static_cast<cocos2d::Vec3(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::unprojectGL));
mt["IsVisibleInFrustum"]=static_cast<bool(cocos2d::Camera::*)(const cocos2d::AABB*)const>(&cocos2d::Camera::isVisibleInFrustum);
mt["GetDepthInView"]=static_cast<float(cocos2d::Camera::*)(const cocos2d::Mat4&)const>(&cocos2d::Camera::getDepthInView);
mt["SetDepth"]=static_cast<void(cocos2d::Camera::*)(int8_t)>(&cocos2d::Camera::setDepth);
mt["set"]["Depth"]=mt["SetDepth"];
mt["GetDepth"]=static_cast<int8_t(cocos2d::Camera::*)()const>(&cocos2d::Camera::getDepth);
mt["get"]["Depth"]=mt["GetDepth"];
mt["GetRenderOrder"]=static_cast<int(cocos2d::Camera::*)()const>(&cocos2d::Camera::getRenderOrder);
mt["get"]["RenderOrder"]=mt["GetRenderOrder"];
mt["GetFarPlane"]=static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getFarPlane);
mt["get"]["FarPlane"]=mt["GetFarPlane"];
mt["GetNearPlane"]=static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getNearPlane);
mt["get"]["NearPlane"]=mt["GetNearPlane"];
mt["ClearBackground"]=static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::clearBackground);
mt["Apply"]=static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::apply);
mt["IsViewProjectionUpdated"]=static_cast<bool(cocos2d::Camera::*)()const>(&cocos2d::Camera::isViewProjectionUpdated);
mt["get"]["ViewProjectionUpdated"]=mt["IsViewProjectionUpdated"];
mt["SetBackgroundBrush"]=static_cast<void(cocos2d::Camera::*)(cocos2d::CameraBackgroundBrush*)>(&cocos2d::Camera::setBackgroundBrush);
mt["set"]["BackgroundBrush"]=mt["SetBackgroundBrush"];
mt["GetBackgroundBrush"]=static_cast<cocos2d::CameraBackgroundBrush*(cocos2d::Camera::*)()const>(&cocos2d::Camera::getBackgroundBrush);
mt["get"]["BackgroundBrush"]=mt["GetBackgroundBrush"];
mt["IsBrushValid"]=static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::isBrushValid);
mt["get"]["BrushValid"]=mt["IsBrushValid"];
RegisterLuaCoreCameraTypeAuto(lua);
}
void RegisterLuaCoreCameraBackgroundBrushBrushTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,4);
enumTable["NONE"]=cocos2d::CameraBackgroundBrush::BrushType::NONE;
enumTable["DEPTH"]=cocos2d::CameraBackgroundBrush::BrushType::DEPTH;
enumTable["COLOR"]=cocos2d::CameraBackgroundBrush::BrushType::COLOR;
enumTable["SKYBOX"]=cocos2d::CameraBackgroundBrush::BrushType::SKYBOX;
lua["cc"]["CameraBackgroundBrush"]["static"]["BrushType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreCameraBackgroundBrushAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CameraBackgroundBrush).name()] = sol::usertype_traits<cocos2d::CameraBackgroundBrush*>::metatable();
auto dep=lua.new_usertype<cocos2d::CameraBackgroundBrush>("deprecated.cocos2d::CameraBackgroundBrush");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CameraBackgroundBrush*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["CameraBackgroundBrush"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetBrushType"]=static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundBrush::*)()const>(&cocos2d::CameraBackgroundBrush::getBrushType);
mt["get"]["BrushType"]=mt["GetBrushType"];
mt["static"]["CreateNoneBrush"]=static_cast<cocos2d::CameraBackgroundBrush*(*)()>(&cocos2d::CameraBackgroundBrush::createNoneBrush);
mt["static"]["CreateDepthBrush"]=sol::overload([](float arg0){return cocos2d::CameraBackgroundBrush::createDepthBrush(arg0);},[](){return cocos2d::CameraBackgroundBrush::createDepthBrush();});
mt["static"]["CreateColorBrush"]=static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundBrush::createColorBrush);
mt["static"]["CreateSkyboxBrush"]=static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundBrush::createSkyboxBrush);
mt["DrawBackground"]=static_cast<void(cocos2d::CameraBackgroundBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundBrush::drawBackground);
mt["IsValid"]=static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::isValid);
mt["get"]["Valid"]=mt["IsValid"];
RegisterLuaCoreCameraBackgroundBrushBrushTypeAuto(lua);
}
void RegisterLuaCoreCameraBackgroundDepthBrushAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CameraBackgroundDepthBrush).name()] = sol::usertype_traits<cocos2d::CameraBackgroundDepthBrush*>::metatable();
auto dep=lua.new_usertype<cocos2d::CameraBackgroundDepthBrush>("deprecated.cocos2d::CameraBackgroundDepthBrush");
dep[sol::base_classes]=sol::bases<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CameraBackgroundDepthBrush*>::metatable(),sol::usertype_traits<cocos2d::CameraBackgroundBrush*>::metatable());
lua["cc"]["CameraBackgroundDepthBrush"]=mt;
mt["__new__"]=static_cast<cocos2d::CameraBackgroundDepthBrush*(*)(float)>(&cocos2d::CameraBackgroundDepthBrush::create);
mt["SetDepth"]=static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(float)>(&cocos2d::CameraBackgroundDepthBrush::setDepth);
mt["set"]["Depth"]=mt["SetDepth"];
}
void RegisterLuaCoreCameraBackgroundColorBrushAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CameraBackgroundColorBrush).name()] = sol::usertype_traits<cocos2d::CameraBackgroundColorBrush*>::metatable();
auto dep=lua.new_usertype<cocos2d::CameraBackgroundColorBrush>("deprecated.cocos2d::CameraBackgroundColorBrush");
dep[sol::base_classes]=sol::bases<cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CameraBackgroundColorBrush*>::metatable(),sol::usertype_traits<cocos2d::CameraBackgroundDepthBrush*>::metatable());
lua["cc"]["CameraBackgroundColorBrush"]=mt;
mt["__new__"]=static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundColorBrush::create);
mt["SetColor"]=static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(const cocos2d::Color4F&)>(&cocos2d::CameraBackgroundColorBrush::setColor);
mt["set"]["Color"]=mt["SetColor"];
}
void RegisterLuaCoreCameraBackgroundSkyBoxBrushAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CameraBackgroundSkyBoxBrush).name()] = sol::usertype_traits<cocos2d::CameraBackgroundSkyBoxBrush*>::metatable();
auto dep=lua.new_usertype<cocos2d::CameraBackgroundSkyBoxBrush>("deprecated.cocos2d::CameraBackgroundSkyBoxBrush");
dep[sol::base_classes]=sol::bases<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CameraBackgroundSkyBoxBrush*>::metatable(),sol::usertype_traits<cocos2d::CameraBackgroundBrush*>::metatable());
lua["cc"]["CameraBackgroundSkyBoxBrush"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundSkyBoxBrush::create),static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::create));
mt["SetTexture"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::TextureCube*)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTexture);
mt["set"]["Texture"]=mt["SetTexture"];
mt["GetTexture"]=static_cast<cocos2d::TextureCube*(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getTexture);
mt["get"]["Texture"]=mt["GetTexture"];
mt["IsActived"]=static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::isActived);
mt["get"]["Actived"]=mt["IsActived"];
mt["SetActived"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setActived);
mt["set"]["Actived"]=mt["SetActived"];
mt["SetTextureValid"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTextureValid);
mt["set"]["TextureValid"]=mt["SetTextureValid"];
}
void RegisterLuaCoreGridBaseAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::GridBase).name()] = sol::usertype_traits<cocos2d::GridBase*>::metatable();
auto dep=lua.new_usertype<cocos2d::GridBase>("deprecated.cocos2d::GridBase");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::GridBase*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["GridBase"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["BeforeBlit"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeBlit);
mt["AfterBlit"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::afterBlit);
mt["Blit"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::blit);
mt["Reuse"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::reuse);
mt["CalculateVertexPoints"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::calculateVertexPoints);
mt["InitWithSize"]=sol::overload(static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::initWithSize));
mt["IsActive"]=static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isActive);
mt["get"]["Active"]=mt["IsActive"];
mt["SetActive"]=static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setActive);
mt["set"]["Active"]=mt["SetActive"];
mt["GetReuseGrid"]=static_cast<int(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getReuseGrid);
mt["get"]["ReuseGrid"]=mt["GetReuseGrid"];
mt["SetReuseGrid"]=static_cast<void(cocos2d::GridBase::*)(int)>(&cocos2d::GridBase::setReuseGrid);
mt["set"]["ReuseGrid"]=mt["SetReuseGrid"];
mt["GetGridSize"]=static_cast<const cocos2d::Size&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridSize);
mt["get"]["GridSize"]=mt["GetGridSize"];
mt["SetGridSize"]=static_cast<void(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::setGridSize);
mt["set"]["GridSize"]=mt["SetGridSize"];
mt["GetStep"]=static_cast<const cocos2d::Vec2&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getStep);
mt["get"]["Step"]=mt["GetStep"];
mt["SetStep"]=static_cast<void(cocos2d::GridBase::*)(const cocos2d::Vec2&)>(&cocos2d::GridBase::setStep);
mt["set"]["Step"]=mt["SetStep"];
mt["IsTextureFlipped"]=static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isTextureFlipped);
mt["get"]["TextureFlipped"]=mt["IsTextureFlipped"];
mt["SetTextureFlipped"]=static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setTextureFlipped);
mt["set"]["TextureFlipped"]=mt["SetTextureFlipped"];
mt["BeforeDraw"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeDraw);
mt["AfterDraw"]=static_cast<void(cocos2d::GridBase::*)(cocos2d::Node*)>(&cocos2d::GridBase::afterDraw);
mt["Set2DProjection"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::set2DProjection);
mt["SetGridRect"]=static_cast<void(cocos2d::GridBase::*)(const cocos2d::Rect&)>(&cocos2d::GridBase::setGridRect);
mt["set"]["GridRect"]=mt["SetGridRect"];
mt["GetGridRect"]=static_cast<const cocos2d::Rect&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridRect);
mt["get"]["GridRect"]=mt["GetGridRect"];
}
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
sol::table enumTable = lua.create_table(lua.lua_state(),0,4);
enumTable["DIRECTIONAL"]=cocos2d::LightType::DIRECTIONAL;
enumTable["POINT"]=cocos2d::LightType::POINT;
enumTable["SPOT"]=cocos2d::LightType::SPOT;
enumTable["AMBIENT"]=cocos2d::LightType::AMBIENT;
lua["cc"]["LightType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreLightFlagAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,16);
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
}
