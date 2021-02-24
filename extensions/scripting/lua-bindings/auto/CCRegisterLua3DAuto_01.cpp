#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DSprite3DMaterialAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterial,cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("cc","Sprite3DMaterial");
mt.set_function("getMaterialType",static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType));
mt.set_function("setTexture",static_cast<void(cocos2d::Sprite3DMaterial::*)(cocos2d::Texture2D*,cocos2d::NTextureData::Usage)>(&cocos2d::Sprite3DMaterial::setTexture));
mt.set_function("clone",static_cast<cocos2d::Material*(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::clone));
mt.set_function("createBuiltInMaterial",sol::overload(static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial)));
mt.set_function("createWithFilename",static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename));
mt.set_function("createWithProgramState",static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState));
mt.set_function("releaseBuiltInMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial));
mt.set_function("releaseCachedMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial));
}
void RegisterLua3DTerrainAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Terrain,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Terrain");
mt.set_function("setLightMap",static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::setLightMap));
mt.set_function("setLightDir",static_cast<void(cocos2d::Terrain::*)(const cocos2d::Vec3&)>(&cocos2d::Terrain::setLightDir));
mt.set_function("initProperties",static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initProperties));
mt.set_function("initHeightMap",static_cast<bool(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::initHeightMap));
mt.set_function("initTextures",static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initTextures));
mt.set_function("getHeight",sol::overload([](cocos2d::Terrain* obj,const cocos2d::Vec2& arg0){return obj->getHeight(arg0);},[](cocos2d::Terrain* obj,const cocos2d::Vec2& arg0,cocos2d::Vec3* arg1){return obj->getHeight(arg0,arg1);},[](cocos2d::Terrain* obj,float arg0,float arg1){return obj->getHeight(arg0,arg1);},[](cocos2d::Terrain* obj,float arg0,float arg1,cocos2d::Vec3* arg2){return obj->getHeight(arg0,arg1,arg2);}));
mt.set_function("getNormal",static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getNormal));
mt.set_function("getImageHeight",static_cast<float(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getImageHeight));
mt.set_function("setDrawWire",static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setDrawWire));
mt.set_function("setLODDistance",static_cast<void(cocos2d::Terrain::*)(float,float,float)>(&cocos2d::Terrain::setLODDistance));
mt.set_function("setIsEnableFrustumCull",static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setIsEnableFrustumCull));
mt.set_function("setAlphaMap",static_cast<void(cocos2d::Terrain::*)(cocos2d::Texture2D*)>(&cocos2d::Terrain::setAlphaMap));
mt.set_function("setDetailMap",static_cast<void(cocos2d::Terrain::*)(unsigned int,cocos2d::Terrain::DetailMap)>(&cocos2d::Terrain::setDetailMap));
mt.set_function("draw",static_cast<void(cocos2d::Terrain::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Terrain::draw));
mt.set_function("getIntersectionPoint",sol::overload(static_cast<bool(cocos2d::Terrain::*)(const cocos2d::Ray&,cocos2d::Vec3&)const>(&cocos2d::Terrain::getIntersectionPoint),static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(const cocos2d::Ray&)const>(&cocos2d::Terrain::getIntersectionPoint)));
mt.set_function("setMaxDetailMapAmount",static_cast<void(cocos2d::Terrain::*)(int)>(&cocos2d::Terrain::setMaxDetailMapAmount));
mt.set_function("convertToTerrainSpace",static_cast<cocos2d::Vec2(cocos2d::Terrain::*)(const cocos2d::Vec2&)const>(&cocos2d::Terrain::convertToTerrainSpace));
mt.set_function("resetHeightMap",static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::resetHeightMap));
mt.set_function("getMinHeight",static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMinHeight));
mt.set_function("getMaxHeight",static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMaxHeight));
mt.set_function("getAABB",static_cast<cocos2d::AABB(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getAABB));
mt.set_function("setSkirtHeightRatio",static_cast<void(cocos2d::Terrain::*)(float)>(&cocos2d::Terrain::setSkirtHeightRatio));
mt.set_function("reload",static_cast<void(cocos2d::Terrain::*)()>(&cocos2d::Terrain::reload));
mt.set_function("getTerrainSize",static_cast<cocos2d::Size(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getTerrainSize));
mt.set_function("getHeightData",static_cast<std::vector<float>(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getHeightData));
mt.set_function("new",sol::overload([](cocos2d::Terrain* obj,cocos2d::Terrain::TerrainData& arg0){return obj->create(arg0);},[](cocos2d::Terrain* obj,cocos2d::Terrain::TerrainData& arg0,cocos2d::Terrain::CrackFixedType arg1){return obj->create(arg0,arg1);}));
}
void RegisterLua3DBundle3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Bundle3D>("cc","Bundle3D");
mt.set_function("clear",static_cast<void(cocos2d::Bundle3D::*)()>(&cocos2d::Bundle3D::clear));
mt.set_function("load",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&)>(&cocos2d::Bundle3D::load));
mt.set_function("loadSkinData",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::SkinData*)>(&cocos2d::Bundle3D::loadSkinData));
mt.set_function("loadAnimationData",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::Animation3DData*)>(&cocos2d::Bundle3D::loadAnimationData));
mt.set_function("loadMeshDatas",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MeshDatas&)>(&cocos2d::Bundle3D::loadMeshDatas));
mt.set_function("loadNodes",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::NodeDatas&)>(&cocos2d::Bundle3D::loadNodes));
mt.set_function("loadMaterials",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MaterialDatas&)>(&cocos2d::Bundle3D::loadMaterials));
mt.set_function("createBundle",static_cast<cocos2d::Bundle3D*(*)()>(&cocos2d::Bundle3D::createBundle));
mt.set_function("destroyBundle",static_cast<void(*)(cocos2d::Bundle3D*)>(&cocos2d::Bundle3D::destroyBundle));
mt.set_function("parseGLDataType",static_cast<cocos2d::backend::VertexFormat(*)(const std::string&,int)>(&cocos2d::Bundle3D::parseGLDataType));
mt.set_function("parseSamplerAddressMode",static_cast<cocos2d::backend::SamplerAddressMode(*)(const std::string&)>(&cocos2d::Bundle3D::parseSamplerAddressMode));
mt.set_function("getTrianglesList",static_cast<std::vector<cocos2d::Vec3>(*)(const std::string&)>(&cocos2d::Bundle3D::getTrianglesList));
mt.set_function("loadObj",sol::overload([](cocos2d::Bundle3D* obj,cocos2d::MeshDatas& arg0,cocos2d::MaterialDatas& arg1,cocos2d::NodeDatas& arg2,const std::string& arg3){return obj->loadObj(arg0,arg1,arg2,arg3);},[](cocos2d::Bundle3D* obj,cocos2d::MeshDatas& arg0,cocos2d::MaterialDatas& arg1,cocos2d::NodeDatas& arg2,const std::string& arg3,const char* arg4){return obj->loadObj(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("calculateAABB",static_cast<cocos2d::AABB(*)(const std::vector<float>&,int,const std::vector<unsigned short>&)>(&cocos2d::Bundle3D::calculateAABB));
}
