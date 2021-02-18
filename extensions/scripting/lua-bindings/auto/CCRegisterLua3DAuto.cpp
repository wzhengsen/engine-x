#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
static void RegisterLuaAnimation3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Animation3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Animation3D"
,"getDuration",static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration)
,"init",static_cast<bool(cocos2d::Animation3D::*)(const cocos2d::Animation3DData&)>(&cocos2d::Animation3D::init)
,"initWithFile",static_cast<bool(cocos2d::Animation3D::*)(const std::string&,const std::string&)>(&cocos2d::Animation3D::initWithFile)
,"new",sol::overload([](cocos2d::Animation3D* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::Animation3D* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);})
);}
static void RegisterLuaAnimate3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Animate3D,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate3D"
,"stop",static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::stop)
,"step",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::step)
,"startWithTarget",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Node*)>(&cocos2d::Animate3D::startWithTarget)
,"reverse",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::reverse)
,"clone",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::clone)
,"update",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::update)
,"getSpeed",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed)
,"setSpeed",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed)
,"getWeight",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight)
,"setWeight",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight)
,"setOriginInterval",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval)
,"getOriginInterval",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval)
,"setQuality",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality)
,"getQuality",static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality)
,"setKeyFrameUserInfo",static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo)
,"removeFromMap",static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::removeFromMap)
,"init",sol::overload(static_cast<bool(cocos2d::Animate3D::*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::init),static_cast<bool(cocos2d::Animate3D::*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::init))
,"initWithFrames",static_cast<bool(cocos2d::Animate3D::*)(cocos2d::Animation3D*,int,int,float)>(&cocos2d::Animate3D::initWithFrames)
,"new",sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create))
,"createWithFrames",sol::overload([](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2){return obj->createWithFrames(arg0,arg1,arg2);},[](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return obj->createWithFrames(arg0,arg1,arg2,arg3);})
,"getTransitionTime",static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime)
,"setTransitionTime",static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime)
);}
static void RegisterLuaTextureCube(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TextureCube,cocos2d::Ref,cocos2d::LuaObject>("cc","TextureCube"
,"setTexParameters",static_cast<void(cocos2d::TextureCube::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::TextureCube::setTexParameters)
,"getBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::getBackendTexture)
,"getImagePaths",static_cast<const std::vector<std::string>&(cocos2d::TextureCube::*)()const>(&cocos2d::TextureCube::getImagePaths)
,"reloadTexture",static_cast<bool(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::reloadTexture)
,"new",static_cast<cocos2d::TextureCube*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::TextureCube::create)
);}
static void RegisterLuaAttachNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AttachNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","AttachNode"
,"getWorldToNodeTransform",static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getWorldToNodeTransform)
,"getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToWorldTransform)
,"getNodeToParentTransform",static_cast<const cocos2d::Mat4&(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToParentTransform)
,"visit",static_cast<void(cocos2d::AttachNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AttachNode::visit)
,"new",static_cast<cocos2d::AttachNode*(*)(cocos2d::Bone3D*)>(&cocos2d::AttachNode::create)
);}
static void RegisterLuaBillBoard(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::BillBoard,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","BillBoard"
,"setMode",static_cast<void(cocos2d::BillBoard::*)(cocos2d::BillBoard::Mode)>(&cocos2d::BillBoard::setMode)
,"getMode",static_cast<cocos2d::BillBoard::Mode(cocos2d::BillBoard::*)()const>(&cocos2d::BillBoard::getMode)
,"visit",static_cast<void(cocos2d::BillBoard::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::BillBoard::visit)
,"new",sol::overload([](cocos2d::BillBoard* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,cocos2d::BillBoard::Mode arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj){return obj->create();},[](cocos2d::BillBoard* obj,cocos2d::BillBoard::Mode arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1,cocos2d::BillBoard::Mode arg2){return obj->create(arg0,arg1,arg2);})
,"createWithTexture",sol::overload([](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0,cocos2d::BillBoard::Mode arg1){return obj->createWithTexture(arg0,arg1);})
);}
static void RegisterLuaMesh(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Mesh,cocos2d::Ref,cocos2d::LuaObject>("cc","Mesh"
,"getMeshVertexAttribCount",static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshVertexAttribCount)
,"getMeshVertexAttribute",static_cast<const cocos2d::MeshVertexAttrib&(cocos2d::Mesh::*)(int)>(&cocos2d::Mesh::getMeshVertexAttribute)
,"getVertexSizeInBytes",static_cast<int(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexSizeInBytes)
,"setVisible",static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setVisible)
,"isVisible",static_cast<bool(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::isVisible)
,"getProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getProgramState)
,"getName",static_cast<const std::string&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getName)
,"setBlendFunc",static_cast<void(cocos2d::Mesh::*)(const cocos2d::BlendFunc&)>(&cocos2d::Mesh::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getBlendFunc)
,"setProgramState",static_cast<void(cocos2d::Mesh::*)(cocos2d::backend::ProgramState*)>(&cocos2d::Mesh::setProgramState)
,"setMaterial",static_cast<void(cocos2d::Mesh::*)(cocos2d::Material*)>(&cocos2d::Mesh::setMaterial)
,"getMaterial",static_cast<cocos2d::Material*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMaterial)
,"draw",static_cast<void(cocos2d::Mesh::*)(cocos2d::Renderer*,float,const cocos2d::Mat4&,uint32_t,unsigned int,const cocos2d::Vec4&,bool)>(&cocos2d::Mesh::draw)
,"setSkin",static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshSkin*)>(&cocos2d::Mesh::setSkin)
,"setMeshIndexData",static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshIndexData*)>(&cocos2d::Mesh::setMeshIndexData)
,"setName",static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setName)
,"calculateAABB",static_cast<void(cocos2d::Mesh::*)()>(&cocos2d::Mesh::calculateAABB)
,"setForce2DQueue",static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setForce2DQueue)
,"getTextureFileName",static_cast<std::string(cocos2d::Mesh::*)()>(&cocos2d::Mesh::getTextureFileName)
);}
static void RegisterLuaSkeleton3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Skeleton3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Skeleton3D"
,"getBoneCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getBoneCount)
,"getBoneByIndex",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(unsigned int)const>(&cocos2d::Skeleton3D::getBoneByIndex)
,"getBoneByName",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(const std::string&)const>(&cocos2d::Skeleton3D::getBoneByName)
,"getRootCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getRootCount)
,"getRootBone",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(int)const>(&cocos2d::Skeleton3D::getRootBone)
,"getBoneIndex",static_cast<int(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)const>(&cocos2d::Skeleton3D::getBoneIndex)
,"updateBoneMatrix",static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::updateBoneMatrix)
,"removeAllBones",static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::removeAllBones)
,"addBone",static_cast<void(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)>(&cocos2d::Skeleton3D::addBone)
);}
static void RegisterLuaSkybox(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Skybox,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Skybox"
,"setTexture",static_cast<void(cocos2d::Skybox::*)(cocos2d::TextureCube*)>(&cocos2d::Skybox::setTexture)
,"draw",static_cast<void(cocos2d::Skybox::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Skybox::draw)
,"reload",static_cast<void(cocos2d::Skybox::*)()>(&cocos2d::Skybox::reload)
,"init",sol::overload(static_cast<bool(cocos2d::Skybox::*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::init),static_cast<bool(cocos2d::Skybox::*)()>(&cocos2d::Skybox::init))
,"new",sol::overload(static_cast<cocos2d::Skybox*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::create),static_cast<cocos2d::Skybox*(*)()>(&cocos2d::Skybox::create))
);}
static void RegisterLuaSprite3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Sprite3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","Sprite3D"
,"setTexture",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture))
,"getMeshByIndex",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex)
,"getMeshByName",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName)
,"getMesh",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh)
,"getMeshCount",static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount)
,"getSkeleton",static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton)
,"getAttachNode",static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode)
,"removeAttachNode",static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode)
,"removeAllAttachNode",static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode)
,"setBlendFunc",static_cast<void(cocos2d::Sprite3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite3D::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBlendFunc)
,"setProgramState",sol::overload([](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);})
,"runAction",static_cast<cocos2d::Action*(cocos2d::Sprite3D::*)(cocos2d::Action*)>(&cocos2d::Sprite3D::runAction)
,"setForceDepthWrite",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite)
,"isForceDepthWrite",static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite)
,"getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBoundingBox)
,"setCullFace",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace)
,"setCullFaceEnabled",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled)
,"setLightMask",static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask)
,"getLightMask",static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask)
,"draw",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::draw)
,"setMaterial",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial))
,"getMaterial",static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial)
,"setForce2DQueue",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue)
,"getMeshes",static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes)
,"genMaterial",sol::overload([](cocos2d::Sprite3D* obj){return obj->genMaterial();},[](cocos2d::Sprite3D* obj,bool arg0){return obj->genMaterial(arg0);})
,"new",sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create))
);}
static void RegisterLuaSprite3DCache(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Sprite3DCache>("cc","Sprite3DCache"
,"removeSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData)
,"removeAllSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData)
,"getInstance",static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance)
);}
static void RegisterLuaSprite3DMaterial(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Sprite3DMaterial,cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("cc","Sprite3DMaterial"
,"getMaterialType",static_cast<cocos2d::Sprite3DMaterial::MaterialType(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::getMaterialType)
,"clone",static_cast<cocos2d::Material*(cocos2d::Sprite3DMaterial::*)()const>(&cocos2d::Sprite3DMaterial::clone)
,"createBuiltInMaterial",sol::overload(static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial),static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::Sprite3DMaterial::MaterialType,bool)>(&cocos2d::Sprite3DMaterial::createBuiltInMaterial))
,"createWithFilename",static_cast<cocos2d::Sprite3DMaterial*(*)(const std::string&)>(&cocos2d::Sprite3DMaterial::createWithFilename)
,"createWithProgramState",static_cast<cocos2d::Sprite3DMaterial*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Sprite3DMaterial::createWithProgramState)
,"releaseBuiltInMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseBuiltInMaterial)
,"releaseCachedMaterial",static_cast<void(*)()>(&cocos2d::Sprite3DMaterial::releaseCachedMaterial)
);}
static void RegisterLuaTerrain(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Terrain,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Terrain"
,"setLightMap",static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::setLightMap)
,"setLightDir",static_cast<void(cocos2d::Terrain::*)(const cocos2d::Vec3&)>(&cocos2d::Terrain::setLightDir)
,"initProperties",static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initProperties)
,"initHeightMap",static_cast<bool(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::initHeightMap)
,"initTextures",static_cast<bool(cocos2d::Terrain::*)()>(&cocos2d::Terrain::initTextures)
,"getNormal",static_cast<cocos2d::Vec3(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getNormal)
,"getImageHeight",static_cast<float(cocos2d::Terrain::*)(int,int)const>(&cocos2d::Terrain::getImageHeight)
,"setDrawWire",static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setDrawWire)
,"setLODDistance",static_cast<void(cocos2d::Terrain::*)(float,float,float)>(&cocos2d::Terrain::setLODDistance)
,"setIsEnableFrustumCull",static_cast<void(cocos2d::Terrain::*)(bool)>(&cocos2d::Terrain::setIsEnableFrustumCull)
,"setAlphaMap",static_cast<void(cocos2d::Terrain::*)(cocos2d::Texture2D*)>(&cocos2d::Terrain::setAlphaMap)
,"setDetailMap",static_cast<void(cocos2d::Terrain::*)(unsigned int,cocos2d::Terrain::DetailMap)>(&cocos2d::Terrain::setDetailMap)
,"draw",static_cast<void(cocos2d::Terrain::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Terrain::draw)
,"setMaxDetailMapAmount",static_cast<void(cocos2d::Terrain::*)(int)>(&cocos2d::Terrain::setMaxDetailMapAmount)
,"convertToTerrainSpace",static_cast<cocos2d::Vec2(cocos2d::Terrain::*)(const cocos2d::Vec2&)const>(&cocos2d::Terrain::convertToTerrainSpace)
,"resetHeightMap",static_cast<void(cocos2d::Terrain::*)(const std::string&)>(&cocos2d::Terrain::resetHeightMap)
,"getMinHeight",static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMinHeight)
,"getMaxHeight",static_cast<float(cocos2d::Terrain::*)()>(&cocos2d::Terrain::getMaxHeight)
,"setSkirtHeightRatio",static_cast<void(cocos2d::Terrain::*)(float)>(&cocos2d::Terrain::setSkirtHeightRatio)
,"reload",static_cast<void(cocos2d::Terrain::*)()>(&cocos2d::Terrain::reload)
,"getTerrainSize",static_cast<cocos2d::Size(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getTerrainSize)
,"getHeightData",static_cast<std::vector<float>(cocos2d::Terrain::*)()const>(&cocos2d::Terrain::getHeightData)
,"initWithTerrainData",static_cast<bool(cocos2d::Terrain::*)(cocos2d::Terrain::TerrainData&,cocos2d::Terrain::CrackFixedType)>(&cocos2d::Terrain::initWithTerrainData)
);}
static void RegisterLuaBundle3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Bundle3D>("cc","Bundle3D"
,"clear",static_cast<void(cocos2d::Bundle3D::*)()>(&cocos2d::Bundle3D::clear)
,"load",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&)>(&cocos2d::Bundle3D::load)
,"loadSkinData",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::SkinData*)>(&cocos2d::Bundle3D::loadSkinData)
,"loadAnimationData",static_cast<bool(cocos2d::Bundle3D::*)(const std::string&,cocos2d::Animation3DData*)>(&cocos2d::Bundle3D::loadAnimationData)
,"loadNodes",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::NodeDatas&)>(&cocos2d::Bundle3D::loadNodes)
,"loadMaterials",static_cast<bool(cocos2d::Bundle3D::*)(cocos2d::MaterialDatas&)>(&cocos2d::Bundle3D::loadMaterials)
,"createBundle",static_cast<cocos2d::Bundle3D*(*)()>(&cocos2d::Bundle3D::createBundle)
,"destroyBundle",static_cast<void(*)(cocos2d::Bundle3D*)>(&cocos2d::Bundle3D::destroyBundle)
,"parseGLDataType",static_cast<cocos2d::backend::VertexFormat(*)(const std::string&,int)>(&cocos2d::Bundle3D::parseGLDataType)
,"parseSamplerAddressMode",static_cast<cocos2d::backend::SamplerAddressMode(*)(const std::string&)>(&cocos2d::Bundle3D::parseSamplerAddressMode)
);}
void RegisterLua3DAuto(cocos2d::Lua& lua) {
RegisterLuaAnimation3D(lua);
RegisterLuaAnimate3D(lua);
RegisterLuaTextureCube(lua);
RegisterLuaAttachNode(lua);
RegisterLuaBillBoard(lua);
RegisterLuaMesh(lua);
RegisterLuaSkeleton3D(lua);
RegisterLuaSkybox(lua);
RegisterLuaSprite3D(lua);
RegisterLuaSprite3DCache(lua);
RegisterLuaSprite3DMaterial(lua);
RegisterLuaTerrain(lua);
RegisterLuaBundle3D(lua);
}
