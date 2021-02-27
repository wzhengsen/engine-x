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
void RegisterLuaCoreSprite3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Sprite3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("Sprite3D",false);
ns["Sprite3D"] = mt;
lua["Sprite3D"] = sol::nil;
mt.set_function("setTexture",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture)));
mt.set_function("getMeshByIndex",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex));
mt.set_function("getMeshByName",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName));
mt.set_function("getMeshArrayByName",static_cast<std::vector<cocos2d::Mesh *>(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshArrayByName));
mt.set_function("getMesh",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh));
mt.set_function("getMeshCount",static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount));
mt.set_function("getSkeleton",static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton));
mt.set_function("getAttachNode",static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode));
mt.set_function("removeAttachNode",static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode));
mt.set_function("removeAllAttachNode",static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::Sprite3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite3D::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBlendFunc));
mt.set_function("setProgramState",sol::overload([](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("getAABB",static_cast<const cocos2d::AABB&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getAABB));
mt.set_function("getAABBRecursively",static_cast<cocos2d::AABB(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::getAABBRecursively));
mt.set_function("runAction",static_cast<cocos2d::Action*(cocos2d::Sprite3D::*)(cocos2d::Action*)>(&cocos2d::Sprite3D::runAction));
mt.set_function("setForceDepthWrite",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite));
mt.set_function("isForceDepthWrite",static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBoundingBox));
mt.set_function("setCullFace",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace));
mt.set_function("setCullFaceEnabled",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled));
mt.set_function("setLightMask",static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask));
mt.set_function("getLightMask",static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask));
mt.set_function("draw",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::draw));
mt.set_function("setMaterial",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial)));
mt.set_function("getMaterial",static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial));
mt.set_function("setForce2DQueue",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue));
mt.set_function("getMeshes",static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes));
mt.set_function("visit",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::visit));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create)));
mt.set_function("createAsync",sol::overload(static_cast<void(*)(const std::string&,const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync),static_cast<void(*)(const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync)));
}
void RegisterLuaCoreSprite3DCacheAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Sprite3DCache>("Sprite3DCache",true);
ns["Sprite3DCache"] = mt;
lua["Sprite3DCache"] = sol::nil;
mt.set_function("getSpriteData",static_cast<cocos2d::Sprite3DCache::Sprite3DData*(cocos2d::Sprite3DCache::*)(const std::string&)const>(&cocos2d::Sprite3DCache::getSpriteData));
mt.set_function("addSprite3DData",static_cast<bool(cocos2d::Sprite3DCache::*)(const std::string&,cocos2d::Sprite3DCache::Sprite3DData*)>(&cocos2d::Sprite3DCache::addSprite3DData));
mt.set_function("removeSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData));
mt.set_function("removeAllSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData));
mt.set_function("getInstance",static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance));
}
void RegisterLuaCoreSprite3DMaterialMaterialTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Sprite3DMaterial"];
pTable.new_enum("MaterialType"
,"UNLIT",0
,"UNLIT_NOTEX",1
,"VERTEX_LIT",2
,"DIFFUSE",3
,"DIFFUSE_NOTEX",4
,"BUMPED_DIFFUSE",5
,"CUSTOM",6
);}
void RegisterLuaCoreSprite3DMaterialAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterial,cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("Sprite3DMaterial",true);
ns["Sprite3DMaterial"] = mt;
lua["Sprite3DMaterial"] = sol::nil;
mt.set_function("getMaterialType",static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType));
mt.set_function("setTexture",static_cast<void(cocos2d::Sprite3DMaterial::*)(cocos2d::Texture2D*,cocos2d::NTextureData::Usage)>(&cocos2d::Sprite3DMaterial::setTexture));
mt.set_function("clone",static_cast<cocos2d::Material*(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::clone));
mt.set_function("createBuiltInMaterial",sol::overload(static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial)));
mt.set_function("createWithFilename",static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename));
mt.set_function("createWithProgramState",static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState));
mt.set_function("releaseBuiltInMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial));
mt.set_function("releaseCachedMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial));
RegisterLuaCoreSprite3DMaterialMaterialTypeAuto(lua);
}
void RegisterLuaCoreSprite3DMaterialCacheAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterialCache>("Sprite3DMaterialCache",true);
ns["Sprite3DMaterialCache"] = mt;
lua["Sprite3DMaterialCache"] = sol::nil;
mt.set_function("addSprite3DMaterial",static_cast<bool(cocos2d::Sprite3DMaterialCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::Sprite3DMaterialCache::addSprite3DMaterial));
mt.set_function("getSprite3DMaterial",static_cast<cocos2d::Texture2D*(cocos2d::Sprite3DMaterialCache::*)(const std::string&)>(&cocos2d::Sprite3DMaterialCache::getSprite3DMaterial));
mt.set_function("removeAllSprite3DMaterial",static_cast<void(cocos2d::Sprite3DMaterialCache::*)()>(&cocos2d::Sprite3DMaterialCache::removeAllSprite3DMaterial));
mt.set_function("removeUnusedSprite3DMaterial",static_cast<void(cocos2d::Sprite3DMaterialCache::*)()>(&cocos2d::Sprite3DMaterialCache::removeUnusedSprite3DMaterial));
mt.set_function("getInstance",static_cast<cocos2d::Sprite3DMaterialCache*(*)()>(&cocos2d::Sprite3DMaterialCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DMaterialCache::destroyInstance));
}
void RegisterLuaCoreAnonymousEnum__6153635611689382057_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TGA_OK"] = 0;
pTable["TGA_ERROR_FILE_OPEN"] = 1;
pTable["TGA_ERROR_READING_FILE"] = 2;
pTable["TGA_ERROR_INDEXED_COLOR"] = 3;
pTable["TGA_ERROR_MEMORY"] = 4;
pTable["TGA_ERROR_COMPRESSED_FILE"] = 5;
}
