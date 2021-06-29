#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DSprite3DMaterialAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Sprite3DMaterial).name()] = sol::usertype_traits<cocos2d::Sprite3DMaterial*>::metatable();
auto dep=lua.new_usertype<cocos2d::Sprite3DMaterial>("deprecated.cocos2d::Sprite3DMaterial");
dep[sol::base_classes]=sol::bases<cocos2d::Material,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Sprite3DMaterial*>::metatable(),sol::usertype_traits<cocos2d::Material*>::metatable());
lua["cc"]["Sprite3DMaterial"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetMaterialType"]=static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType);
mt["get"]["MaterialType"]=mt["GetMaterialType"];
mt["static"]["CreateBuiltInMaterial"]=sol::overload(static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial));
mt["static"]["CreateWithFilename"]=static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename);
mt["static"]["CreateWithProgramState"]=static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState);
mt["SetTexture"]=static_cast<void(cocos2d::Sprite3DMaterial::*)(cocos2d::Texture2D*,cocos2d::NTextureData::Usage)>(&cocos2d::Sprite3DMaterial::setTexture);
mt["static"]["ReleaseBuiltInMaterial"]=static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial);
mt["static"]["ReleaseCachedMaterial"]=static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial);
}
void RegisterLua3DTerrainAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Terrain).name()] = sol::usertype_traits<cocos2d::Terrain*>::metatable();
auto dep=lua.new_usertype<cocos2d::Terrain>("deprecated.cocos2d::Terrain");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Terrain*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["Terrain"]=mt;
mt["SetLightMap"]=static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::setLightMap);
mt["set"]["LightMap"]=mt["SetLightMap"];
mt["SetLightDir"]=static_cast<void(cocos2d::Terrain::*)(const cocos2d::Vec3&)>(&cocos2d::Terrain::setLightDir);
mt["set"]["LightDir"]=mt["SetLightDir"];
mt["InitProperties"]=static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initProperties);
mt["InitHeightMap"]=static_cast<bool(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::initHeightMap);
mt["InitTextures"]=static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initTextures);
mt["__new__"]=sol::overload([](cocos2d::Terrain::TerrainData& arg0,cocos2d::Terrain::CrackFixedType arg1){return cocos2d::Terrain::create(arg0,arg1);},[](cocos2d::Terrain::TerrainData& arg0){return cocos2d::Terrain::create(arg0);});
mt["GetHeight"]=sol::overload([](cocos2d::Terrain* obj,float arg0,float arg1,cocos2d::Vec3* arg2){return obj->getHeight(arg0,arg1,arg2);},[](cocos2d::Terrain* obj,const cocos2d::Vec2& arg0,cocos2d::Vec3* arg1){return obj->getHeight(arg0,arg1);},[](cocos2d::Terrain* obj,float arg0,float arg1){return obj->getHeight(arg0,arg1);},[](cocos2d::Terrain* obj,const cocos2d::Vec2& arg0){return obj->getHeight(arg0);});
mt["GetNormal"]=static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getNormal);
mt["GetImageHeight"]=static_cast<float(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getImageHeight);
mt["SetDrawWire"]=static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setDrawWire);
mt["set"]["DrawWire"]=mt["SetDrawWire"];
mt["SetLODDistance"]=static_cast<void(cocos2d::Terrain::*)(float,float,float)>(&cocos2d::Terrain::setLODDistance);
mt["SetIsEnableFrustumCull"]=static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setIsEnableFrustumCull);
mt["set"]["IsEnableFrustumCull"]=mt["SetIsEnableFrustumCull"];
mt["SetAlphaMap"]=static_cast<void(cocos2d::Terrain::*)(cocos2d::Texture2D*)>(&cocos2d::Terrain::setAlphaMap);
mt["set"]["AlphaMap"]=mt["SetAlphaMap"];
mt["SetDetailMap"]=static_cast<void(cocos2d::Terrain::*)(unsigned int,cocos2d::Terrain::DetailMap)>(&cocos2d::Terrain::setDetailMap);
mt["GetIntersectionPoint"]=sol::overload(static_cast<bool(cocos2d::Terrain::*)(const cocos2d::Ray&,cocos2d::Vec3&)const>(&cocos2d::Terrain::getIntersectionPoint),static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(const cocos2d::Ray&)const>(&cocos2d::Terrain::getIntersectionPoint));
mt["SetMaxDetailMapAmount"]=static_cast<void(cocos2d::Terrain::*)(int)>(&cocos2d::Terrain::setMaxDetailMapAmount);
mt["set"]["MaxDetailMapAmount"]=mt["SetMaxDetailMapAmount"];
mt["ConvertToTerrainSpace"]=static_cast<cocos2d::Vec2(cocos2d::Terrain::*)(const cocos2d::Vec2&)const>(&cocos2d::Terrain::convertToTerrainSpace);
mt["ResetHeightMap"]=static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::resetHeightMap);
mt["GetMinHeight"]=static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMinHeight);
mt["get"]["MinHeight"]=mt["GetMinHeight"];
mt["GetMaxHeight"]=static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMaxHeight);
mt["get"]["MaxHeight"]=mt["GetMaxHeight"];
mt["GetAABB"]=static_cast<cocos2d::AABB(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getAABB);
mt["get"]["AABB"]=mt["GetAABB"];
mt["SetSkirtHeightRatio"]=static_cast<void(cocos2d::Terrain::*)(float)>(&cocos2d::Terrain::setSkirtHeightRatio);
mt["set"]["SkirtHeightRatio"]=mt["SetSkirtHeightRatio"];
mt["Reload"]=static_cast<void(cocos2d::Terrain::*)()>(&cocos2d::Terrain::reload);
mt["GetTerrainSize"]=static_cast<cocos2d::Size(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getTerrainSize);
mt["get"]["TerrainSize"]=mt["GetTerrainSize"];
mt["GetHeightData"]=static_cast<std::vector<float, std::allocator<float> >(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getHeightData);
mt["get"]["HeightData"]=mt["GetHeightData"];
}
void RegisterLua3DBundle3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Bundle3D).name()] = sol::usertype_traits<cocos2d::Bundle3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Bundle3D>("deprecated.cocos2d::Bundle3D");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Bundle3D*>::metatable());
lua["cc"]["Bundle3D"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["CreateBundle"]=static_cast<cocos2d::Bundle3D*(*)()>(&cocos2d::Bundle3D::createBundle);
mt["static"]["DestroyBundle"]=static_cast<void(*)(cocos2d::Bundle3D*)>(&cocos2d::Bundle3D::destroyBundle);
mt["Clear"]=static_cast<void(cocos2d::Bundle3D::*)()>(&cocos2d::Bundle3D::clear);
mt["static"]["ParseGLDataType"]=static_cast<cocos2d::backend::VertexFormat(*)(const std::string&,int)>(&cocos2d::Bundle3D::parseGLDataType);
mt["static"]["ParseSamplerAddressMode"]=static_cast<cocos2d::backend::SamplerAddressMode(*)(const std::string&)>(&cocos2d::Bundle3D::parseSamplerAddressMode);
mt["Load"]=static_cast<bool(cocos2d::Bundle3D::*)(const std::string&)>(&cocos2d::Bundle3D::load);
mt["LoadSkinData"]=static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::SkinData*)>(&cocos2d::Bundle3D::loadSkinData);
mt["LoadAnimationData"]=static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::Animation3DData*)>(&cocos2d::Bundle3D::loadAnimationData);
mt["LoadMeshDatas"]=static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MeshDatas&)>(&cocos2d::Bundle3D::loadMeshDatas);
mt["LoadNodes"]=static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::NodeDatas&)>(&cocos2d::Bundle3D::loadNodes);
mt["LoadMaterials"]=static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MaterialDatas&)>(&cocos2d::Bundle3D::loadMaterials);
mt["static"]["GetTrianglesList"]=static_cast<std::vector<cocos2d::Vec3, std::allocator<cocos2d::Vec3> >(*)(const std::string&)>(&cocos2d::Bundle3D::getTrianglesList);
mt["static"]["LoadObj"]=sol::overload([](cocos2d::MeshDatas& arg0,cocos2d::MaterialDatas& arg1,cocos2d::NodeDatas& arg2,const std::string& arg3,const char* arg4){return cocos2d::Bundle3D::loadObj(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::MeshDatas& arg0,cocos2d::MaterialDatas& arg1,cocos2d::NodeDatas& arg2,const std::string& arg3){return cocos2d::Bundle3D::loadObj(arg0,arg1,arg2,arg3);});
mt["static"]["CalculateAABB"]=static_cast<cocos2d::AABB(*)(const std::vector<float, std::allocator<float> >&,int,const std::vector<unsigned short, std::allocator<unsigned short> >&)>(&cocos2d::Bundle3D::calculateAABB);
}
