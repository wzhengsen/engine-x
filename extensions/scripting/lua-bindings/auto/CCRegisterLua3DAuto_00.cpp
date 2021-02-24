#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DAnimation3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Animation3D");
mt.set_function("getDuration",static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration));
mt.set_function("getBoneCurveByName",static_cast<cocos2d::Animation3D::Curve*(cocos2d::Animation3D::*)(const std::string&)const>(&cocos2d::Animation3D::getBoneCurveByName));
mt.set_function("getBoneCurves",static_cast<const std::unordered_map<std::string, cocos2d::Animation3D::Curve *>&(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getBoneCurves));
mt.set_function("new",sol::overload([](cocos2d::Animation3D* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::Animation3D* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);}));
}
void RegisterLua3DAnimate3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate3D,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate3D");
mt.set_function("stop",static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::stop));
mt.set_function("step",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::step));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Node*)>(&cocos2d::Animate3D::startWithTarget));
mt.set_function("reverse",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::reverse));
mt.set_function("clone",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::update));
mt.set_function("getSpeed",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed));
mt.set_function("setSpeed",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed));
mt.set_function("getWeight",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight));
mt.set_function("setWeight",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight));
mt.set_function("setOriginInterval",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval));
mt.set_function("getOriginInterval",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval));
mt.set_function("setQuality",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality));
mt.set_function("getQuality",static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality));
mt.set_function("setKeyFrameUserInfo",static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo));
mt.set_function("getKeyFrameUserInfo",sol::overload(static_cast<cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)>(&cocos2d::Animate3D::getKeyFrameUserInfo),static_cast<const cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)const>(&cocos2d::Animate3D::getKeyFrameUserInfo)));
mt.set_function("new",sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create)));
mt.set_function("createWithFrames",sol::overload([](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2){return obj->createWithFrames(arg0,arg1,arg2);},[](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return obj->createWithFrames(arg0,arg1,arg2,arg3);}));
mt.set_function("getTransitionTime",static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime));
mt.set_function("setTransitionTime",static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime));
}
void RegisterLua3DTextureCubeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TextureCube,cocos2d::Ref,cocos2d::LuaObject>("cc","TextureCube");
mt.set_function("setTexParameters",static_cast<void(cocos2d::TextureCube::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::TextureCube::setTexParameters));
mt.set_function("getBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::getBackendTexture));
mt.set_function("getImagePaths",static_cast<const std::vector<std::string>&(cocos2d::TextureCube::*)()const>(&cocos2d::TextureCube::getImagePaths));
mt.set_function("reloadTexture",static_cast<bool(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::reloadTexture));
mt.set_function("new",static_cast<cocos2d::TextureCube*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::TextureCube::create));
}
void RegisterLua3DAttachNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AttachNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","AttachNode");
mt.set_function("getWorldToNodeTransform",static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getWorldToNodeTransform));
mt.set_function("getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToWorldTransform));
mt.set_function("getNodeToParentTransform",static_cast<const cocos2d::Mat4&(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToParentTransform));
mt.set_function("visit",static_cast<void(cocos2d::AttachNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AttachNode::visit));
mt.set_function("new",static_cast<cocos2d::AttachNode*(*)(cocos2d::Bone3D*)>(&cocos2d::AttachNode::create));
}
void RegisterLua3DBillBoardAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BillBoard,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","BillBoard");
mt.set_function("setMode",static_cast<void(cocos2d::BillBoard::*)(cocos2d::BillBoard::Mode)>(&cocos2d::BillBoard::setMode));
mt.set_function("getMode",static_cast<cocos2d::BillBoard::Mode(cocos2d::BillBoard::*)()const>(&cocos2d::BillBoard::getMode));
mt.set_function("visit",static_cast<void(cocos2d::BillBoard::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::BillBoard::visit));
mt.set_function("draw",static_cast<void(cocos2d::BillBoard::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::BillBoard::draw));
mt.set_function("new",sol::overload([](cocos2d::BillBoard* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,cocos2d::BillBoard::Mode arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj){return obj->create();},[](cocos2d::BillBoard* obj,cocos2d::BillBoard::Mode arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1,cocos2d::BillBoard::Mode arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("createWithTexture",sol::overload([](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0,cocos2d::BillBoard::Mode arg1){return obj->createWithTexture(arg0,arg1);}));
}
void RegisterLua3DMeshAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Mesh,cocos2d::Ref,cocos2d::LuaObject>("cc","Mesh");
mt.set_function("getVertexBuffer",static_cast<cocos2d::backend::Buffer*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexBuffer));
mt.set_function("hasVertexAttrib",static_cast<bool(cocos2d::Mesh::*)(cocos2d::shaderinfos::VertexKey)const>(&cocos2d::Mesh::hasVertexAttrib));
mt.set_function("getMeshVertexAttribCount",static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshVertexAttribCount));
mt.set_function("getMeshVertexAttribute",static_cast<const cocos2d::MeshVertexAttrib&(cocos2d::Mesh::*)(int)>(&cocos2d::Mesh::getMeshVertexAttribute));
mt.set_function("getVertexSizeInBytes",static_cast<int(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexSizeInBytes));
mt.set_function("setTexture",sol::overload(static_cast<void(cocos2d::Mesh::*)(cocos2d::Texture2D*)>(&cocos2d::Mesh::setTexture),static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setTexture),[](cocos2d::Mesh* obj,cocos2d::Texture2D* arg0,cocos2d::NTextureData::Usage arg1){return obj->setTexture(arg0,arg1);},[](cocos2d::Mesh* obj,cocos2d::Texture2D* arg0,cocos2d::NTextureData::Usage arg1,bool arg2){return obj->setTexture(arg0,arg1,arg2);},static_cast<void(cocos2d::Mesh::*)(const std::string&,cocos2d::NTextureData::Usage)>(&cocos2d::Mesh::setTexture)));
mt.set_function("getTexture",sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::Mesh::*)(cocos2d::NTextureData::Usage)>(&cocos2d::Mesh::getTexture),static_cast<cocos2d::Texture2D*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getTexture)));
mt.set_function("setVisible",static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setVisible));
mt.set_function("isVisible",static_cast<bool(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::isVisible));
mt.set_function("getSkin",static_cast<cocos2d::MeshSkin*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getSkin));
mt.set_function("getMeshIndexData",static_cast<cocos2d::MeshIndexData*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshIndexData));
mt.set_function("getProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getProgramState));
mt.set_function("getName",static_cast<const std::string&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getName));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::Mesh::*)(const cocos2d::BlendFunc&)>(&cocos2d::Mesh::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getBlendFunc));
mt.set_function("getPrimitiveType",static_cast<cocos2d::CustomCommand::PrimitiveType(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getPrimitiveType));
mt.set_function("getIndexCount",static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexCount));
mt.set_function("getIndexFormat",static_cast<cocos2d::CustomCommand::IndexFormat(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexFormat));
mt.set_function("getIndexBuffer",static_cast<cocos2d::backend::Buffer*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexBuffer));
mt.set_function("getAABB",static_cast<const cocos2d::AABB&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getAABB));
mt.set_function("setProgramState",static_cast<void(cocos2d::Mesh::*)(cocos2d::backend::ProgramState*)>(&cocos2d::Mesh::setProgramState));
mt.set_function("setMaterial",static_cast<void(cocos2d::Mesh::*)(cocos2d::Material*)>(&cocos2d::Mesh::setMaterial));
mt.set_function("getMaterial",static_cast<cocos2d::Material*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMaterial));
mt.set_function("draw",static_cast<void(cocos2d::Mesh::*)(cocos2d::Renderer*,float,const cocos2d::Mat4&,uint32_t,unsigned int,const cocos2d::Vec4&,bool)>(&cocos2d::Mesh::draw));
mt.set_function("setSkin",static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshSkin*)>(&cocos2d::Mesh::setSkin));
mt.set_function("setMeshIndexData",static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshIndexData*)>(&cocos2d::Mesh::setMeshIndexData));
mt.set_function("setName",static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setName));
mt.set_function("calculateAABB",static_cast<void(cocos2d::Mesh::*)()>(&cocos2d::Mesh::calculateAABB));
mt.set_function("setForce2DQueue",static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setForce2DQueue));
mt.set_function("getTextureFileName",static_cast<std::string(cocos2d::Mesh::*)()>(&cocos2d::Mesh::getTextureFileName));
mt.set_function("new",sol::overload(static_cast<cocos2d::Mesh*(*)(const std::vector<float>&,int,const cocos2d::Mesh::IndexArray&,const std::vector<cocos2d::MeshVertexAttrib>&)>(&cocos2d::Mesh::create),static_cast<cocos2d::Mesh*(*)(const std::vector<float>&,const std::vector<float>&,const std::vector<float>&,const cocos2d::Mesh::IndexArray&)>(&cocos2d::Mesh::create),[](cocos2d::Mesh* obj,const std::string& arg0,cocos2d::MeshIndexData* arg1){return obj->create(arg0,arg1);},[](cocos2d::Mesh* obj,const std::string& arg0,cocos2d::MeshIndexData* arg1,cocos2d::MeshSkin* arg2){return obj->create(arg0,arg1,arg2);}));
}
void RegisterLua3DSkeleton3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skeleton3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Skeleton3D");
mt.set_function("getBoneCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getBoneCount));
mt.set_function("getBoneByIndex",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(unsigned int)const>(&cocos2d::Skeleton3D::getBoneByIndex));
mt.set_function("getBoneByName",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(const std::string&)const>(&cocos2d::Skeleton3D::getBoneByName));
mt.set_function("getRootCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getRootCount));
mt.set_function("getRootBone",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(int)const>(&cocos2d::Skeleton3D::getRootBone));
mt.set_function("getBoneIndex",static_cast<int(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)const>(&cocos2d::Skeleton3D::getBoneIndex));
mt.set_function("updateBoneMatrix",static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::updateBoneMatrix));
mt.set_function("new",static_cast<cocos2d::Skeleton3D*(*)(const std::vector<cocos2d::NodeData *>&)>(&cocos2d::Skeleton3D::create));
}
void RegisterLua3DSkyboxAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skybox,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Skybox");
mt.set_function("setTexture",static_cast<void(cocos2d::Skybox::*)(cocos2d::TextureCube*)>(&cocos2d::Skybox::setTexture));
mt.set_function("draw",static_cast<void(cocos2d::Skybox::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Skybox::draw));
mt.set_function("reload",static_cast<void(cocos2d::Skybox::*)()>(&cocos2d::Skybox::reload));
mt.set_function("new",sol::overload(static_cast<cocos2d::Skybox*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::create),static_cast<cocos2d::Skybox*(*)()>(&cocos2d::Skybox::create)));
}
void RegisterLua3DSprite3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","Sprite3D");
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
mt.set_function("new",sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create)));
mt.set_function("createAsync",sol::overload(static_cast<void(*)(const std::string&,const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync),static_cast<void(*)(const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync)));
}
void RegisterLua3DSprite3DCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DCache>("cc","Sprite3DCache");
mt.set_function("getSpriteData",static_cast<cocos2d::Sprite3DCache::Sprite3DData*(cocos2d::Sprite3DCache::*)(const std::string&)const>(&cocos2d::Sprite3DCache::getSpriteData));
mt.set_function("addSprite3DData",static_cast<bool(cocos2d::Sprite3DCache::*)(const std::string&,cocos2d::Sprite3DCache::Sprite3DData*)>(&cocos2d::Sprite3DCache::addSprite3DData));
mt.set_function("removeSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData));
mt.set_function("removeAllSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData));
mt.set_function("getInstance",static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance));
}
