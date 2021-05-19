#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DSprite3DMaterialAuto(cocos2d::extension::Lua& lua){
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
}
void RegisterLua3DTerrainAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Terrain>("cc","Terrain",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetLightMap",static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::setLightMap));
mt.set_function("SetLightDir",static_cast<void(cocos2d::Terrain::*)(const cocos2d::Vec3&)>(&cocos2d::Terrain::setLightDir));
mt.set_function("InitProperties",static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initProperties));
mt.set_function("InitHeightMap",static_cast<bool(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::initHeightMap));
mt.set_function("InitTextures",static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initTextures));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::Terrain* obj,cocos2d::Terrain::TerrainData& arg0){return obj->create(arg0);},[](cocos2d::Terrain* obj,cocos2d::Terrain::TerrainData& arg0,cocos2d::Terrain::CrackFixedType arg1){return obj->create(arg0,arg1);}));
mt.set_function("GetHeight",sol::overload([](cocos2d::Terrain* obj,const cocos2d::Vec2& arg0){return obj->getHeight(arg0);},[](cocos2d::Terrain* obj,const cocos2d::Vec2& arg0,cocos2d::Vec3* arg1){return obj->getHeight(arg0,arg1);},[](cocos2d::Terrain* obj,float arg0,float arg1){return obj->getHeight(arg0,arg1);},[](cocos2d::Terrain* obj,float arg0,float arg1,cocos2d::Vec3* arg2){return obj->getHeight(arg0,arg1,arg2);}));
mt.set_function("GetNormal",static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getNormal));
mt.set_function("GetImageHeight",static_cast<float(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getImageHeight));
mt.set_function("SetDrawWire",static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setDrawWire));
mt.set_function("SetLODDistance",static_cast<void(cocos2d::Terrain::*)(float,float,float)>(&cocos2d::Terrain::setLODDistance));
mt.set_function("SetIsEnableFrustumCull",static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setIsEnableFrustumCull));
mt.set_function("SetAlphaMap",static_cast<void(cocos2d::Terrain::*)(cocos2d::Texture2D*)>(&cocos2d::Terrain::setAlphaMap));
mt.set_function("SetDetailMap",static_cast<void(cocos2d::Terrain::*)(unsigned int,cocos2d::Terrain::DetailMap)>(&cocos2d::Terrain::setDetailMap));
mt.set_function("Draw",static_cast<void(cocos2d::Terrain::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Terrain::draw));
mt.set_function("GetIntersectionPoint",sol::overload(static_cast<bool(cocos2d::Terrain::*)(const cocos2d::Ray&,cocos2d::Vec3&)const>(&cocos2d::Terrain::getIntersectionPoint),static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(const cocos2d::Ray&)const>(&cocos2d::Terrain::getIntersectionPoint)));
mt.set_function("SetMaxDetailMapAmount",static_cast<void(cocos2d::Terrain::*)(int)>(&cocos2d::Terrain::setMaxDetailMapAmount));
mt.set_function("ConvertToTerrainSpace",static_cast<cocos2d::Vec2(cocos2d::Terrain::*)(const cocos2d::Vec2&)const>(&cocos2d::Terrain::convertToTerrainSpace));
mt.set_function("ResetHeightMap",static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::resetHeightMap));
mt.set_function("GetMinHeight",static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMinHeight));
mt.set_function("GetMaxHeight",static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMaxHeight));
mt.set_function("GetAABB",static_cast<cocos2d::AABB(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getAABB));
mt.set_function("SetSkirtHeightRatio",static_cast<void(cocos2d::Terrain::*)(float)>(&cocos2d::Terrain::setSkirtHeightRatio));
mt.set_function("Reload",static_cast<void(cocos2d::Terrain::*)()>(&cocos2d::Terrain::reload));
mt.set_function("GetTerrainSize",static_cast<cocos2d::Size(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getTerrainSize));
mt.set_function("GetHeightData",static_cast<std::vector<float, std::allocator<float> >(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getHeightData));
}
void RegisterLua3DBundle3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Bundle3D>("cc","Bundle3D",true);
mt.set_function("CreateBundle",static_cast<cocos2d::Bundle3D*(*)()>(&cocos2d::Bundle3D::createBundle));
mt.set_function("DestroyBundle",static_cast<void(*)(cocos2d::Bundle3D*)>(&cocos2d::Bundle3D::destroyBundle));
mt.set_function("Clear",static_cast<void(cocos2d::Bundle3D::*)()>(&cocos2d::Bundle3D::clear));
mt.set_function("ParseGLDataType",static_cast<cocos2d::backend::VertexFormat(*)(const std::string&,int)>(&cocos2d::Bundle3D::parseGLDataType));
mt.set_function("ParseSamplerAddressMode",static_cast<cocos2d::backend::SamplerAddressMode(*)(const std::string&)>(&cocos2d::Bundle3D::parseSamplerAddressMode));
mt.set_function("Load",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&)>(&cocos2d::Bundle3D::load));
mt.set_function("LoadSkinData",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::SkinData*)>(&cocos2d::Bundle3D::loadSkinData));
mt.set_function("LoadAnimationData",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::Animation3DData*)>(&cocos2d::Bundle3D::loadAnimationData));
mt.set_function("LoadMeshDatas",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MeshDatas&)>(&cocos2d::Bundle3D::loadMeshDatas));
mt.set_function("LoadNodes",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::NodeDatas&)>(&cocos2d::Bundle3D::loadNodes));
mt.set_function("LoadMaterials",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MaterialDatas&)>(&cocos2d::Bundle3D::loadMaterials));
mt.set_function("GetTrianglesList",static_cast<std::vector<cocos2d::Vec3, std::allocator<cocos2d::Vec3> >(*)(const std::string&)>(&cocos2d::Bundle3D::getTrianglesList));
mt.set_function("LoadObj",sol::overload([](cocos2d::Bundle3D* obj,cocos2d::MeshDatas& arg0,cocos2d::MaterialDatas& arg1,cocos2d::NodeDatas& arg2,const std::string& arg3){return obj->loadObj(arg0,arg1,arg2,arg3);},[](cocos2d::Bundle3D* obj,cocos2d::MeshDatas& arg0,cocos2d::MaterialDatas& arg1,cocos2d::NodeDatas& arg2,const std::string& arg3,const char* arg4){return obj->loadObj(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("CalculateAABB",static_cast<cocos2d::AABB(*)(const std::vector<float, std::allocator<float> >&,int,const std::vector<unsigned short, std::allocator<unsigned short> >&)>(&cocos2d::Bundle3D::calculateAABB));
}
