#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
static void RegisterLua3DAnimation3D(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Animation3D");
mt["getDuration"]=static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration);
mt["init"]=static_cast<bool(cocos2d::Animation3D::*)(const cocos2d::Animation3DData&)>(&cocos2d::Animation3D::init);
mt["initWithFile"]=static_cast<bool(cocos2d::Animation3D::*)(const std::string&,const std::string&)>(&cocos2d::Animation3D::initWithFile);
mt["new"]=sol::overload([](cocos2d::Animation3D* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::Animation3D* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);});
}
static void RegisterLua3DAnimate3D(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate3D,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate3D");
mt["stop"]=static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::stop);
mt["step"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::step);
mt["startWithTarget"]=static_cast<void(cocos2d::Animate3D::*)(cocos2d::Node*)>(&cocos2d::Animate3D::startWithTarget);
mt["reverse"]=static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::reverse);
mt["clone"]=static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::clone);
mt["update"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::update);
mt["getSpeed"]=static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed);
mt["setSpeed"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed);
mt["getWeight"]=static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight);
mt["setWeight"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight);
mt["setOriginInterval"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval);
mt["getOriginInterval"]=static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval);
mt["setQuality"]=static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality);
mt["getQuality"]=static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality);
mt["setKeyFrameUserInfo"]=static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo);
mt["removeFromMap"]=static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::removeFromMap);
mt["init"]=sol::overload(static_cast<bool(cocos2d::Animate3D::*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::init),static_cast<bool(cocos2d::Animate3D::*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::init));
mt["initWithFrames"]=static_cast<bool(cocos2d::Animate3D::*)(cocos2d::Animation3D*,int,int,float)>(&cocos2d::Animate3D::initWithFrames);
mt["new"]=sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create));
mt["createWithFrames"]=sol::overload([](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2){return obj->createWithFrames(arg0,arg1,arg2);},[](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return obj->createWithFrames(arg0,arg1,arg2,arg3);});
mt["getTransitionTime"]=static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime);
mt["setTransitionTime"]=static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime);
}
static void RegisterLua3DTextureCube(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TextureCube,cocos2d::Ref,cocos2d::LuaObject>("cc","TextureCube");
mt["setTexParameters"]=static_cast<void(cocos2d::TextureCube::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::TextureCube::setTexParameters);
mt["getBackendTexture"]=static_cast<cocos2d::backend::TextureBackend*(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::getBackendTexture);
mt["getImagePaths"]=static_cast<const std::vector<std::string>&(cocos2d::TextureCube::*)()const>(&cocos2d::TextureCube::getImagePaths);
mt["reloadTexture"]=static_cast<bool(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::reloadTexture);
mt["new"]=static_cast<cocos2d::TextureCube*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::TextureCube::create);
}
static void RegisterLua3DAttachNode(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AttachNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","AttachNode");
mt["getWorldToNodeTransform"]=static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getWorldToNodeTransform);
mt["getNodeToWorldTransform"]=static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToWorldTransform);
mt["getNodeToParentTransform"]=static_cast<const cocos2d::Mat4&(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToParentTransform);
mt["visit"]=static_cast<void(cocos2d::AttachNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AttachNode::visit);
mt["new"]=static_cast<cocos2d::AttachNode*(*)(cocos2d::Bone3D*)>(&cocos2d::AttachNode::create);
}
static void RegisterLua3DBillBoard(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BillBoard,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","BillBoard");
mt["setMode"]=static_cast<void(cocos2d::BillBoard::*)(cocos2d::BillBoard::Mode)>(&cocos2d::BillBoard::setMode);
mt["getMode"]=static_cast<cocos2d::BillBoard::Mode(cocos2d::BillBoard::*)()const>(&cocos2d::BillBoard::getMode);
mt["visit"]=static_cast<void(cocos2d::BillBoard::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::BillBoard::visit);
mt["new"]=sol::overload([](cocos2d::BillBoard* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,cocos2d::BillBoard::Mode arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj){return obj->create();},[](cocos2d::BillBoard* obj,cocos2d::BillBoard::Mode arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1,cocos2d::BillBoard::Mode arg2){return obj->create(arg0,arg1,arg2);});
mt["createWithTexture"]=sol::overload([](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0,cocos2d::BillBoard::Mode arg1){return obj->createWithTexture(arg0,arg1);});
}
static void RegisterLua3DMesh(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Mesh,cocos2d::Ref,cocos2d::LuaObject>("cc","Mesh");
mt["getMeshVertexAttribCount"]=static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshVertexAttribCount);
mt["getMeshVertexAttribute"]=static_cast<const cocos2d::MeshVertexAttrib&(cocos2d::Mesh::*)(int)>(&cocos2d::Mesh::getMeshVertexAttribute);
mt["getVertexSizeInBytes"]=static_cast<int(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexSizeInBytes);
mt["setVisible"]=static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setVisible);
mt["isVisible"]=static_cast<bool(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::isVisible);
mt["getProgramState"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getProgramState);
mt["getName"]=static_cast<const std::string&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getName);
mt["setBlendFunc"]=static_cast<void(cocos2d::Mesh::*)(const cocos2d::BlendFunc&)>(&cocos2d::Mesh::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getBlendFunc);
mt["setProgramState"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::backend::ProgramState*)>(&cocos2d::Mesh::setProgramState);
mt["setMaterial"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::Material*)>(&cocos2d::Mesh::setMaterial);
mt["getMaterial"]=static_cast<cocos2d::Material*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMaterial);
mt["draw"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::Renderer*,float,const cocos2d::Mat4&,uint32_t,unsigned int,const cocos2d::Vec4&,bool)>(&cocos2d::Mesh::draw);
mt["setSkin"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshSkin*)>(&cocos2d::Mesh::setSkin);
mt["setMeshIndexData"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshIndexData*)>(&cocos2d::Mesh::setMeshIndexData);
mt["setName"]=static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setName);
mt["calculateAABB"]=static_cast<void(cocos2d::Mesh::*)()>(&cocos2d::Mesh::calculateAABB);
mt["setForce2DQueue"]=static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setForce2DQueue);
mt["getTextureFileName"]=static_cast<std::string(cocos2d::Mesh::*)()>(&cocos2d::Mesh::getTextureFileName);
}
static void RegisterLua3DSkeleton3D(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skeleton3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Skeleton3D");
mt["getBoneCount"]=static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getBoneCount);
mt["getBoneByIndex"]=static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(unsigned int)const>(&cocos2d::Skeleton3D::getBoneByIndex);
mt["getBoneByName"]=static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(const std::string&)const>(&cocos2d::Skeleton3D::getBoneByName);
mt["getRootCount"]=static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getRootCount);
mt["getRootBone"]=static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(int)const>(&cocos2d::Skeleton3D::getRootBone);
mt["getBoneIndex"]=static_cast<int(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)const>(&cocos2d::Skeleton3D::getBoneIndex);
mt["updateBoneMatrix"]=static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::updateBoneMatrix);
mt["removeAllBones"]=static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::removeAllBones);
mt["addBone"]=static_cast<void(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)>(&cocos2d::Skeleton3D::addBone);
}
static void RegisterLua3DSkybox(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skybox,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Skybox");
mt["setTexture"]=static_cast<void(cocos2d::Skybox::*)(cocos2d::TextureCube*)>(&cocos2d::Skybox::setTexture);
mt["draw"]=static_cast<void(cocos2d::Skybox::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Skybox::draw);
mt["reload"]=static_cast<void(cocos2d::Skybox::*)()>(&cocos2d::Skybox::reload);
mt["init"]=sol::overload(static_cast<bool(cocos2d::Skybox::*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::init),static_cast<bool(cocos2d::Skybox::*)()>(&cocos2d::Skybox::init));
mt["new"]=sol::overload(static_cast<cocos2d::Skybox*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::create),static_cast<cocos2d::Skybox*(*)()>(&cocos2d::Skybox::create));
}
static void RegisterLua3DSprite3D(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","Sprite3D");
mt["setTexture"]=sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture));
mt["getMeshByIndex"]=static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex);
mt["getMeshByName"]=static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName);
mt["getMesh"]=static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh);
mt["getMeshCount"]=static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount);
mt["getSkeleton"]=static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton);
mt["getAttachNode"]=static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode);
mt["removeAttachNode"]=static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode);
mt["removeAllAttachNode"]=static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode);
mt["setBlendFunc"]=static_cast<void(cocos2d::Sprite3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite3D::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBlendFunc);
mt["setProgramState"]=sol::overload([](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);});
mt["runAction"]=static_cast<cocos2d::Action*(cocos2d::Sprite3D::*)(cocos2d::Action*)>(&cocos2d::Sprite3D::runAction);
mt["setForceDepthWrite"]=static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite);
mt["isForceDepthWrite"]=static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBoundingBox);
mt["setCullFace"]=static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace);
mt["setCullFaceEnabled"]=static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled);
mt["setLightMask"]=static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask);
mt["getLightMask"]=static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask);
mt["draw"]=static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::draw);
mt["setMaterial"]=sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial));
mt["getMaterial"]=static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial);
mt["setForce2DQueue"]=static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue);
mt["getMeshes"]=static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes);
mt["genMaterial"]=sol::overload([](cocos2d::Sprite3D* obj){return obj->genMaterial();},[](cocos2d::Sprite3D* obj,bool arg0){return obj->genMaterial(arg0);});
mt["new"]=sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create));
}
static void RegisterLua3DSprite3DCache(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DCache>("cc","Sprite3DCache");
mt["removeSprite3DData"]=static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData);
mt["removeAllSprite3DData"]=static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData);
mt["getInstance"]=static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance);
}
static void RegisterLua3DSprite3DMaterial(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DMaterial,cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("cc","Sprite3DMaterial");
mt["getMaterialType"]=static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType);
mt["clone"]=static_cast<cocos2d::Material*(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::clone);
mt["createBuiltInMaterial"]=sol::overload(static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial));
mt["createWithFilename"]=static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename);
mt["createWithProgramState"]=static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState);
mt["releaseBuiltInMaterial"]=static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial);
mt["releaseCachedMaterial"]=static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial);
}
static void RegisterLua3DTerrain(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Terrain,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Terrain");
mt["setLightMap"]=static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::setLightMap);
mt["setLightDir"]=static_cast<void(cocos2d::Terrain::*)(const cocos2d::Vec3&)>(&cocos2d::Terrain::setLightDir);
mt["initProperties"]=static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initProperties);
mt["initHeightMap"]=static_cast<bool(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::initHeightMap);
mt["initTextures"]=static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initTextures);
mt["getNormal"]=static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getNormal);
mt["getImageHeight"]=static_cast<float(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getImageHeight);
mt["setDrawWire"]=static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setDrawWire);
mt["setLODDistance"]=static_cast<void(cocos2d::Terrain::*)(float,float,float)>(&cocos2d::Terrain::setLODDistance);
mt["setIsEnableFrustumCull"]=static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setIsEnableFrustumCull);
mt["setAlphaMap"]=static_cast<void(cocos2d::Terrain::*)(cocos2d::Texture2D*)>(&cocos2d::Terrain::setAlphaMap);
mt["setDetailMap"]=static_cast<void(cocos2d::Terrain::*)(unsigned int,cocos2d::Terrain::DetailMap)>(&cocos2d::Terrain::setDetailMap);
mt["draw"]=static_cast<void(cocos2d::Terrain::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Terrain::draw);
mt["setMaxDetailMapAmount"]=static_cast<void(cocos2d::Terrain::*)(int)>(&cocos2d::Terrain::setMaxDetailMapAmount);
mt["convertToTerrainSpace"]=static_cast<cocos2d::Vec2(cocos2d::Terrain::*)(const cocos2d::Vec2&)const>(&cocos2d::Terrain::convertToTerrainSpace);
mt["resetHeightMap"]=static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::resetHeightMap);
mt["getMinHeight"]=static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMinHeight);
mt["getMaxHeight"]=static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMaxHeight);
mt["setSkirtHeightRatio"]=static_cast<void(cocos2d::Terrain::*)(float)>(&cocos2d::Terrain::setSkirtHeightRatio);
mt["reload"]=static_cast<void(cocos2d::Terrain::*)()>(&cocos2d::Terrain::reload);
mt["getTerrainSize"]=static_cast<cocos2d::Size(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getTerrainSize);
mt["getHeightData"]=static_cast<std::vector<float>(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getHeightData);
mt["initWithTerrainData"]=static_cast<bool(cocos2d::Terrain::*)(cocos2d::Terrain::TerrainData&,cocos2d::Terrain::CrackFixedType)>(&cocos2d::Terrain::initWithTerrainData);
}
static void RegisterLua3DBundle3D(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Bundle3D>("cc","Bundle3D");
mt["clear"]=static_cast<void(cocos2d::Bundle3D::*)()>(&cocos2d::Bundle3D::clear);
mt["load"]=static_cast<bool(cocos2d::Bundle3D::*)(const std::string&)>(&cocos2d::Bundle3D::load);
mt["loadSkinData"]=static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::SkinData*)>(&cocos2d::Bundle3D::loadSkinData);
mt["loadAnimationData"]=static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::Animation3DData*)>(&cocos2d::Bundle3D::loadAnimationData);
mt["loadNodes"]=static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::NodeDatas&)>(&cocos2d::Bundle3D::loadNodes);
mt["loadMaterials"]=static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MaterialDatas&)>(&cocos2d::Bundle3D::loadMaterials);
mt["createBundle"]=static_cast<cocos2d::Bundle3D*(*)()>(&cocos2d::Bundle3D::createBundle);
mt["destroyBundle"]=static_cast<void(*)(cocos2d::Bundle3D*)>(&cocos2d::Bundle3D::destroyBundle);
mt["parseGLDataType"]=static_cast<cocos2d::backend::VertexFormat(*)(const std::string&,int)>(&cocos2d::Bundle3D::parseGLDataType);
mt["parseSamplerAddressMode"]=static_cast<cocos2d::backend::SamplerAddressMode(*)(const std::string&)>(&cocos2d::Bundle3D::parseSamplerAddressMode);
}
void RegisterLua3DAuto(cocos2d::Lua& lua) {
RegisterLua3DAnimation3D(lua);
RegisterLua3DAnimate3D(lua);
RegisterLua3DTextureCube(lua);
RegisterLua3DAttachNode(lua);
RegisterLua3DBillBoard(lua);
RegisterLua3DMesh(lua);
RegisterLua3DSkeleton3D(lua);
RegisterLua3DSkybox(lua);
RegisterLua3DSprite3D(lua);
RegisterLua3DSprite3DCache(lua);
RegisterLua3DSprite3DMaterial(lua);
RegisterLua3DTerrain(lua);
RegisterLua3DBundle3D(lua);
}
