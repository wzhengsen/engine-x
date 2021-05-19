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
void RegisterLuaCoreSprite3DMaterialMaterialTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Sprite3DMaterial"];
pTable.new_enum<cocos2d::Sprite3DMaterial::MaterialType>("MaterialType",{
{"UNLIT",cocos2d::Sprite3DMaterial::MaterialType::UNLIT}
,{"UNLIT_NOTEX",cocos2d::Sprite3DMaterial::MaterialType::UNLIT_NOTEX}
,{"VERTEX_LIT",cocos2d::Sprite3DMaterial::MaterialType::VERTEX_LIT}
,{"DIFFUSE",cocos2d::Sprite3DMaterial::MaterialType::DIFFUSE}
,{"DIFFUSE_NOTEX",cocos2d::Sprite3DMaterial::MaterialType::DIFFUSE_NOTEX}
,{"BUMPED_DIFFUSE",cocos2d::Sprite3DMaterial::MaterialType::BUMPED_DIFFUSE}
,{"CUSTOM",cocos2d::Sprite3DMaterial::MaterialType::CUSTOM}
});}
void RegisterLuaCoreSprite3DMaterialAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterial>("cc","Sprite3DMaterial",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Material,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetMaterialType",static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType));
mt.set_function("CreateBuiltInMaterial",sol::overload(static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial)));
mt.set_function("CreateWithFilename",static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename));
mt.set_function("CreateWithProgramState",static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState));
mt.set_function("SetTexture",static_cast<void(cocos2d::Sprite3DMaterial::*)(cocos2d::Texture2D*,cocos2d::NTextureData::Usage)>(&cocos2d::Sprite3DMaterial::setTexture));
mt.set_function("ReleaseBuiltInMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial));
mt.set_function("ReleaseCachedMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial));
mt.set_function("Clone",static_cast<cocos2d::Material*(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::clone));
RegisterLuaCoreSprite3DMaterialMaterialTypeAuto(lua);
}
void RegisterLuaCoreSprite3DMaterialCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterialCache>("cc","Sprite3DMaterialCache",true);
mt.set_function("GetInstance",static_cast<cocos2d::Sprite3DMaterialCache*(*)()>(&cocos2d::Sprite3DMaterialCache::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DMaterialCache::destroyInstance));
mt.set_function("AddSprite3DMaterial",static_cast<bool(cocos2d::Sprite3DMaterialCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::Sprite3DMaterialCache::addSprite3DMaterial));
mt.set_function("GetSprite3DMaterial",static_cast<cocos2d::Texture2D*(cocos2d::Sprite3DMaterialCache::*)(const std::string&)>(&cocos2d::Sprite3DMaterialCache::getSprite3DMaterial));
mt.set_function("RemoveAllSprite3DMaterial",static_cast<void(cocos2d::Sprite3DMaterialCache::*)()>(&cocos2d::Sprite3DMaterialCache::removeAllSprite3DMaterial));
mt.set_function("RemoveUnusedSprite3DMaterial",static_cast<void(cocos2d::Sprite3DMaterialCache::*)()>(&cocos2d::Sprite3DMaterialCache::removeUnusedSprite3DMaterial));
mt["Instance"]=sol::property(&cocos2d::Sprite3DMaterialCache::getInstance,[](std::nullptr_t){cocos2d::Sprite3DMaterialCache::destroyInstance();});
}
