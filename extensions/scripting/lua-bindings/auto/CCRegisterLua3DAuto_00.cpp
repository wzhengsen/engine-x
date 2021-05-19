#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DAnimation3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation3D>("cc","Animation3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::Animation3D* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::Animation3D* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);}));
mt.set_function("GetDuration",static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration));
mt.set_function("GetBoneCurveByName",static_cast<cocos2d::Animation3D::Curve*(cocos2d::Animation3D::*)(const std::string&)const>(&cocos2d::Animation3D::getBoneCurveByName));
mt.set_function("GetBoneCurves",static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::Animation3D::Curve *, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::Animation3D::Curve *> > >&(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getBoneCurves));
}
void RegisterLua3DAnimate3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate3D>("cc","Animate3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create)));
mt.set_function("CreateWithFrames",sol::overload([](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2){return obj->createWithFrames(arg0,arg1,arg2);},[](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return obj->createWithFrames(arg0,arg1,arg2,arg3);}));
mt.set_function("Stop",static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::stop));
mt.set_function("Step",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::step));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Node*)>(&cocos2d::Animate3D::startWithTarget));
mt.set_function("Reverse",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::reverse));
mt.set_function("Clone",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::update));
mt.set_function("GetSpeed",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed));
mt.set_function("SetSpeed",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed));
mt.set_function("GetWeight",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight));
mt.set_function("SetWeight",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight));
mt.set_function("SetOriginInterval",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval));
mt.set_function("GetOriginInterval",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval));
mt.set_function("GetTransitionTime",static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime));
mt.set_function("SetTransitionTime",static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime));
mt.set_function("SetQuality",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality));
mt.set_function("GetQuality",static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality));
mt.set_function("SetKeyFrameUserInfo",static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo));
mt.set_function("GetKeyFrameUserInfo",sol::overload(static_cast<cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)>(&cocos2d::Animate3D::getKeyFrameUserInfo),static_cast<const cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)const>(&cocos2d::Animate3D::getKeyFrameUserInfo)));
}
void RegisterLua3DTextureCubeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TextureCube>("cc","TextureCube",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TextureCube*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::TextureCube::create));
mt.set_function("SetTexParameters",static_cast<void(cocos2d::TextureCube::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::TextureCube::setTexParameters));
mt.set_function("GetBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::getBackendTexture));
mt.set_function("GetImagePaths",static_cast<const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >&(cocos2d::TextureCube::*)()const>(&cocos2d::TextureCube::getImagePaths));
mt.set_function("ReloadTexture",static_cast<bool(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::reloadTexture));
}
void RegisterLua3DAttachNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AttachNode>("cc","AttachNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::AttachNode*(*)(cocos2d::Bone3D*)>(&cocos2d::AttachNode::create));
mt.set_function("GetWorldToNodeTransform",static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getWorldToNodeTransform));
mt.set_function("GetNodeToWorldTransform",static_cast<cocos2d::Mat4(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToWorldTransform));
mt.set_function("GetNodeToParentTransform",static_cast<const cocos2d::Mat4&(cocos2d::AttachNode::*)()const>(&cocos2d::AttachNode::getNodeToParentTransform));
mt.set_function("Visit",static_cast<void(cocos2d::AttachNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AttachNode::visit));
}
void RegisterLua3DBillBoardAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BillBoard>("cc","BillBoard",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::BillBoard* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,cocos2d::BillBoard::Mode arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj){return obj->create();},[](cocos2d::BillBoard* obj,cocos2d::BillBoard::Mode arg0){return obj->create(arg0);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);},[](cocos2d::BillBoard* obj,const std::string& arg0,const cocos2d::Rect& arg1,cocos2d::BillBoard::Mode arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("CreateWithTexture",sol::overload([](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::BillBoard* obj,cocos2d::Texture2D* arg0,cocos2d::BillBoard::Mode arg1){return obj->createWithTexture(arg0,arg1);}));
mt.set_function("SetMode",static_cast<void(cocos2d::BillBoard::*)(cocos2d::BillBoard::Mode)>(&cocos2d::BillBoard::setMode));
mt.set_function("GetMode",static_cast<cocos2d::BillBoard::Mode(cocos2d::BillBoard::*)()const>(&cocos2d::BillBoard::getMode));
mt.set_function("Visit",static_cast<void(cocos2d::BillBoard::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::BillBoard::visit));
mt.set_function("Draw",static_cast<void(cocos2d::BillBoard::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::BillBoard::draw));
}
void RegisterLua3DMeshAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Mesh>("cc","Mesh",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Mesh*(*)(const std::vector<float, std::allocator<float> >&,int,const cocos2d::Mesh::IndexArray&,const std::vector<cocos2d::MeshVertexAttrib, std::allocator<cocos2d::MeshVertexAttrib> >&)>(&cocos2d::Mesh::create),static_cast<cocos2d::Mesh*(*)(const std::vector<float, std::allocator<float> >&,const std::vector<float, std::allocator<float> >&,const std::vector<float, std::allocator<float> >&,const cocos2d::Mesh::IndexArray&)>(&cocos2d::Mesh::create),[](cocos2d::Mesh* obj,const std::string& arg0,cocos2d::MeshIndexData* arg1){return obj->create(arg0,arg1);},[](cocos2d::Mesh* obj,const std::string& arg0,cocos2d::MeshIndexData* arg1,cocos2d::MeshSkin* arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("GetVertexBuffer",static_cast<cocos2d::backend::Buffer*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexBuffer));
mt.set_function("HasVertexAttrib",static_cast<bool(cocos2d::Mesh::*)(cocos2d::shaderinfos::VertexKey)const>(&cocos2d::Mesh::hasVertexAttrib));
mt.set_function("GetMeshVertexAttribCount",static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshVertexAttribCount));
mt.set_function("GetMeshVertexAttribute",static_cast<const cocos2d::MeshVertexAttrib&(cocos2d::Mesh::*)(int)>(&cocos2d::Mesh::getMeshVertexAttribute));
mt.set_function("GetVertexSizeInBytes",static_cast<int(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexSizeInBytes));
mt.set_function("SetTexture",sol::overload(static_cast<void(cocos2d::Mesh::*)(cocos2d::Texture2D*)>(&cocos2d::Mesh::setTexture),static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setTexture),[](cocos2d::Mesh* obj,cocos2d::Texture2D* arg0,cocos2d::NTextureData::Usage arg1){return obj->setTexture(arg0,arg1);},[](cocos2d::Mesh* obj,cocos2d::Texture2D* arg0,cocos2d::NTextureData::Usage arg1,bool arg2){return obj->setTexture(arg0,arg1,arg2);},static_cast<void(cocos2d::Mesh::*)(const std::string&,cocos2d::NTextureData::Usage)>(&cocos2d::Mesh::setTexture)));
mt.set_function("GetTexture",sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::Mesh::*)(cocos2d::NTextureData::Usage)>(&cocos2d::Mesh::getTexture),static_cast<cocos2d::Texture2D*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getTexture)));
mt.set_function("SetVisible",static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setVisible));
mt.set_function("IsVisible",static_cast<bool(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::isVisible));
mt.set_function("GetSkin",static_cast<cocos2d::MeshSkin*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getSkin));
mt.set_function("GetMeshIndexData",static_cast<cocos2d::MeshIndexData*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshIndexData));
mt.set_function("GetProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getProgramState));
mt.set_function("GetName",static_cast<const std::string&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getName));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::Mesh::*)(const cocos2d::BlendFunc&)>(&cocos2d::Mesh::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getBlendFunc));
mt.set_function("GetPrimitiveType",static_cast<cocos2d::CustomCommand::PrimitiveType(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getPrimitiveType));
mt.set_function("GetIndexCount",static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexCount));
mt.set_function("GetIndexFormat",static_cast<cocos2d::CustomCommand::IndexFormat(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexFormat));
mt.set_function("GetIndexBuffer",static_cast<cocos2d::backend::Buffer*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexBuffer));
mt.set_function("GetAABB",static_cast<const cocos2d::AABB&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getAABB));
mt.set_function("SetProgramState",static_cast<void(cocos2d::Mesh::*)(cocos2d::backend::ProgramState*)>(&cocos2d::Mesh::setProgramState));
mt.set_function("SetMaterial",static_cast<void(cocos2d::Mesh::*)(cocos2d::Material*)>(&cocos2d::Mesh::setMaterial));
mt.set_function("GetMaterial",static_cast<cocos2d::Material*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMaterial));
mt.set_function("Draw",static_cast<void(cocos2d::Mesh::*)(cocos2d::Renderer*,float,const cocos2d::Mat4&,uint32_t,unsigned int,const cocos2d::Vec4&,bool)>(&cocos2d::Mesh::draw));
mt.set_function("SetSkin",static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshSkin*)>(&cocos2d::Mesh::setSkin));
mt.set_function("SetMeshIndexData",static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshIndexData*)>(&cocos2d::Mesh::setMeshIndexData));
mt.set_function("SetName",static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setName));
mt.set_function("CalculateAABB",static_cast<void(cocos2d::Mesh::*)()>(&cocos2d::Mesh::calculateAABB));
mt.set_function("SetForce2DQueue",static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setForce2DQueue));
mt.set_function("GetTextureFileName",static_cast<std::string(cocos2d::Mesh::*)()>(&cocos2d::Mesh::getTextureFileName));
}
void RegisterLua3DSkeleton3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skeleton3D>("cc","Skeleton3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Skeleton3D*(*)(const std::vector<cocos2d::NodeData *, std::allocator<cocos2d::NodeData *> >&)>(&cocos2d::Skeleton3D::create));
mt.set_function("GetBoneCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getBoneCount));
mt.set_function("GetBoneByIndex",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(unsigned int)const>(&cocos2d::Skeleton3D::getBoneByIndex));
mt.set_function("GetBoneByName",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(const std::string&)const>(&cocos2d::Skeleton3D::getBoneByName));
mt.set_function("GetRootCount",static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getRootCount));
mt.set_function("GetRootBone",static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(int)const>(&cocos2d::Skeleton3D::getRootBone));
mt.set_function("GetBoneIndex",static_cast<int(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)const>(&cocos2d::Skeleton3D::getBoneIndex));
mt.set_function("UpdateBoneMatrix",static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::updateBoneMatrix));
}
void RegisterLua3DSkyboxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Skybox>("cc","Skybox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Skybox*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::create),static_cast<cocos2d::Skybox*(*)()>(&cocos2d::Skybox::create)));
mt.set_function("SetTexture",static_cast<void(cocos2d::Skybox::*)(cocos2d::TextureCube*)>(&cocos2d::Skybox::setTexture));
mt.set_function("Draw",static_cast<void(cocos2d::Skybox::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Skybox::draw));
mt.set_function("Reload",static_cast<void(cocos2d::Skybox::*)()>(&cocos2d::Skybox::reload));
}
void RegisterLua3DSprite3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3D>("cc","Sprite3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create)));
mt.set_function("CreateAsync",sol::overload(static_cast<void(*)(const std::string&,const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync),static_cast<void(*)(const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync)));
mt.set_function("SetTexture",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture)));
mt.set_function("GetMeshByIndex",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex));
mt.set_function("GetMeshByName",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName));
mt.set_function("GetMeshArrayByName",static_cast<std::vector<cocos2d::Mesh *, std::allocator<cocos2d::Mesh *> >(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshArrayByName));
mt.set_function("GetMesh",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh));
mt.set_function("GetMeshCount",static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount));
mt.set_function("GetSkeleton",static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton));
mt.set_function("GetAttachNode",static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode));
mt.set_function("RemoveAttachNode",static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode));
mt.set_function("RemoveAllAttachNode",static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::Sprite3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite3D::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBlendFunc));
mt.set_function("SetProgramState",sol::overload([](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("GetAABB",static_cast<const cocos2d::AABB&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getAABB));
mt.set_function("GetAABBRecursively",static_cast<cocos2d::AABB(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::getAABBRecursively));
mt.set_function("RunAction",static_cast<cocos2d::Action*(cocos2d::Sprite3D::*)(cocos2d::Action*)>(&cocos2d::Sprite3D::runAction));
mt.set_function("SetForceDepthWrite",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite));
mt.set_function("IsForceDepthWrite",static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBoundingBox));
mt.set_function("SetCullFace",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace));
mt.set_function("SetCullFaceEnabled",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled));
mt.set_function("SetLightMask",static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask));
mt.set_function("GetLightMask",static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask));
mt.set_function("Draw",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::draw));
mt.set_function("SetMaterial",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial)));
mt.set_function("GetMaterial",static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial));
mt.set_function("SetForce2DQueue",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue));
mt.set_function("GetMeshes",static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes));
mt.set_function("Visit",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::visit));
}
void RegisterLua3DSprite3DCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3DCache>("cc","Sprite3DCache",true);
mt.set_function("GetInstance",static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance));
mt.set_function("GetSpriteData",static_cast<cocos2d::Sprite3DCache::Sprite3DData*(cocos2d::Sprite3DCache::*)(const std::string&)const>(&cocos2d::Sprite3DCache::getSpriteData));
mt.set_function("AddSprite3DData",static_cast<bool(cocos2d::Sprite3DCache::*)(const std::string&,cocos2d::Sprite3DCache::Sprite3DData*)>(&cocos2d::Sprite3DCache::addSprite3DData));
mt.set_function("RemoveSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData));
mt.set_function("RemoveAllSprite3DData",static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData));
mt["Instance"]=sol::property(&cocos2d::Sprite3DCache::getInstance,[](std::nullptr_t){cocos2d::Sprite3DCache::destroyInstance();});
}
