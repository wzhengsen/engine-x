#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DAnimation3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Animation3D).name()] = sol::usertype_traits<cocos2d::Animation3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Animation3D>("deprecated.cocos2d::Animation3D");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Animation3D*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Animation3D"]=mt;
mt["__new__"]=sol::overload([](const std::string& arg0,const std::string& arg1){return cocos2d::Animation3D::create(arg0,arg1);},[](const std::string& arg0){return cocos2d::Animation3D::create(arg0);});
mt["GetDuration"]=static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration);
mt["get"]["Duration"]=mt["GetDuration"];
mt["GetBoneCurveByName"]=static_cast<cocos2d::Animation3D::Curve*(cocos2d::Animation3D::*)(const std::string&)const>(&cocos2d::Animation3D::getBoneCurveByName);
mt["GetBoneCurves"]=static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::Animation3D::Curve *, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::Animation3D::Curve *> > >&(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getBoneCurves);
mt["get"]["BoneCurves"]=mt["GetBoneCurves"];
}
void RegisterLua3DAnimate3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Animate3D).name()] = sol::usertype_traits<cocos2d::Animate3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Animate3D>("deprecated.cocos2d::Animate3D");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Animate3D*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["Animate3D"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create));
mt["static"]["CreateWithFrames"]=sol::overload([](cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return cocos2d::Animate3D::createWithFrames(arg0,arg1,arg2,arg3);},[](cocos2d::Animation3D* arg0,int arg1,int arg2){return cocos2d::Animate3D::createWithFrames(arg0,arg1,arg2);});
mt["GetSpeed"]=static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed);
mt["get"]["Speed"]=mt["GetSpeed"];
mt["SetSpeed"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed);
mt["set"]["Speed"]=mt["SetSpeed"];
mt["GetWeight"]=static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight);
mt["get"]["Weight"]=mt["GetWeight"];
mt["SetWeight"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight);
mt["set"]["Weight"]=mt["SetWeight"];
mt["SetOriginInterval"]=static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval);
mt["set"]["OriginInterval"]=mt["SetOriginInterval"];
mt["GetOriginInterval"]=static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval);
mt["get"]["OriginInterval"]=mt["GetOriginInterval"];
mt["static"]["GetTransitionTime"]=static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime);
mt["static"]["get"]["TransitionTime"]=mt["GetTransitionTime"];
mt["static"]["SetTransitionTime"]=static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime);
mt["static"]["set"]["TransitionTime"]=mt["SetTransitionTime"];
mt["SetQuality"]=static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality);
mt["set"]["Quality"]=mt["SetQuality"];
mt["GetQuality"]=static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality);
mt["get"]["Quality"]=mt["GetQuality"];
mt["SetKeyFrameUserInfo"]=static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo);
mt["GetKeyFrameUserInfo"]=static_cast<const cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)const>(&cocos2d::Animate3D::getKeyFrameUserInfo);
}
void RegisterLua3DTextureCubeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TextureCube).name()] = sol::usertype_traits<cocos2d::TextureCube*>::metatable();
auto dep=lua.new_usertype<cocos2d::TextureCube>("deprecated.cocos2d::TextureCube");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TextureCube*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TextureCube"]=mt;
mt["__new__"]=static_cast<cocos2d::TextureCube*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::TextureCube::create);
mt["SetTexParameters"]=static_cast<void(cocos2d::TextureCube::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::TextureCube::setTexParameters);
mt["set"]["TexParameters"]=mt["SetTexParameters"];
mt["GetBackendTexture"]=static_cast<cocos2d::backend::TextureBackend*(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::getBackendTexture);
mt["get"]["BackendTexture"]=mt["GetBackendTexture"];
mt["GetImagePaths"]=static_cast<const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >&(cocos2d::TextureCube::*)()const>(&cocos2d::TextureCube::getImagePaths);
mt["get"]["ImagePaths"]=mt["GetImagePaths"];
mt["ReloadTexture"]=static_cast<bool(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::reloadTexture);
}
void RegisterLua3DAttachNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AttachNode).name()] = sol::usertype_traits<cocos2d::AttachNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::AttachNode>("deprecated.cocos2d::AttachNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AttachNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["AttachNode"]=mt;
mt["__new__"]=static_cast<cocos2d::AttachNode*(*)(cocos2d::Bone3D*)>(&cocos2d::AttachNode::create);
}
void RegisterLua3DBillBoardAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::BillBoard).name()] = sol::usertype_traits<cocos2d::BillBoard*>::metatable();
auto dep=lua.new_usertype<cocos2d::BillBoard>("deprecated.cocos2d::BillBoard");
dep[sol::base_classes]=sol::bases<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::BillBoard*>::metatable(),sol::usertype_traits<cocos2d::Sprite*>::metatable());
lua["cc"]["BillBoard"]=mt;
mt["__new__"]=sol::overload([](const std::string& arg0,const cocos2d::Rect& arg1,cocos2d::BillBoard::Mode arg2){return cocos2d::BillBoard::create(arg0,arg1,arg2);},[](const std::string& arg0,const cocos2d::Rect& arg1){return cocos2d::BillBoard::create(arg0,arg1);},[](const std::string& arg0,cocos2d::BillBoard::Mode arg1){return cocos2d::BillBoard::create(arg0,arg1);},[](const std::string& arg0){return cocos2d::BillBoard::create(arg0);},[](cocos2d::BillBoard::Mode arg0){return cocos2d::BillBoard::create(arg0);},[](){return cocos2d::BillBoard::create();});
mt["static"]["CreateWithTexture"]=sol::overload([](cocos2d::Texture2D* arg0,cocos2d::BillBoard::Mode arg1){return cocos2d::BillBoard::createWithTexture(arg0,arg1);},[](cocos2d::Texture2D* arg0){return cocos2d::BillBoard::createWithTexture(arg0);});
mt["SetMode"]=static_cast<void(cocos2d::BillBoard::*)(cocos2d::BillBoard::Mode)>(&cocos2d::BillBoard::setMode);
mt["set"]["Mode"]=mt["SetMode"];
mt["GetMode"]=static_cast<cocos2d::BillBoard::Mode(cocos2d::BillBoard::*)()const>(&cocos2d::BillBoard::getMode);
mt["get"]["Mode"]=mt["GetMode"];
}
void RegisterLua3DMeshAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Mesh).name()] = sol::usertype_traits<cocos2d::Mesh*>::metatable();
auto dep=lua.new_usertype<cocos2d::Mesh>("deprecated.cocos2d::Mesh");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Mesh*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Mesh"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::Mesh*(*)(const std::vector<float, std::allocator<float> >&,int,const cocos2d::Mesh::IndexArray&,const std::vector<cocos2d::MeshVertexAttrib, std::allocator<cocos2d::MeshVertexAttrib> >&)>(&cocos2d::Mesh::create),static_cast<cocos2d::Mesh*(*)(const std::vector<float, std::allocator<float> >&,const std::vector<float, std::allocator<float> >&,const std::vector<float, std::allocator<float> >&,const cocos2d::Mesh::IndexArray&)>(&cocos2d::Mesh::create),[](const std::string& arg0,cocos2d::MeshIndexData* arg1,cocos2d::MeshSkin* arg2){return cocos2d::Mesh::create(arg0,arg1,arg2);},[](const std::string& arg0,cocos2d::MeshIndexData* arg1){return cocos2d::Mesh::create(arg0,arg1);});
mt["GetVertexBuffer"]=static_cast<cocos2d::backend::Buffer*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexBuffer);
mt["get"]["VertexBuffer"]=mt["GetVertexBuffer"];
mt["HasVertexAttrib"]=static_cast<bool(cocos2d::Mesh::*)(cocos2d::shaderinfos::VertexKey)const>(&cocos2d::Mesh::hasVertexAttrib);
mt["GetMeshVertexAttribCount"]=static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshVertexAttribCount);
mt["get"]["MeshVertexAttribCount"]=mt["GetMeshVertexAttribCount"];
mt["GetMeshVertexAttribute"]=static_cast<const cocos2d::MeshVertexAttrib&(cocos2d::Mesh::*)(int)>(&cocos2d::Mesh::getMeshVertexAttribute);
mt["GetVertexSizeInBytes"]=static_cast<int(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getVertexSizeInBytes);
mt["get"]["VertexSizeInBytes"]=mt["GetVertexSizeInBytes"];
mt["SetTexture"]=sol::overload([](cocos2d::Mesh* obj,cocos2d::Texture2D* arg0,cocos2d::NTextureData::Usage arg1,bool arg2){return obj->setTexture(arg0,arg1,arg2);},static_cast<void(cocos2d::Mesh::*)(const std::string&,cocos2d::NTextureData::Usage)>(&cocos2d::Mesh::setTexture),[](cocos2d::Mesh* obj,cocos2d::Texture2D* arg0,cocos2d::NTextureData::Usage arg1){return obj->setTexture(arg0,arg1);},static_cast<void(cocos2d::Mesh::*)(cocos2d::Texture2D*)>(&cocos2d::Mesh::setTexture),static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setTexture));
mt["set"]["Texture"]=mt["SetTexture"];
mt["GetTexture"]=sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::Mesh::*)(cocos2d::NTextureData::Usage)>(&cocos2d::Mesh::getTexture),static_cast<cocos2d::Texture2D*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getTexture));
mt["get"]["Texture"]=mt["GetTexture"];
mt["SetVisible"]=static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setVisible);
mt["set"]["Visible"]=mt["SetVisible"];
mt["IsVisible"]=static_cast<bool(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::isVisible);
mt["get"]["Visible"]=mt["IsVisible"];
mt["GetSkin"]=static_cast<cocos2d::MeshSkin*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getSkin);
mt["get"]["Skin"]=mt["GetSkin"];
mt["GetMeshIndexData"]=static_cast<cocos2d::MeshIndexData*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMeshIndexData);
mt["get"]["MeshIndexData"]=mt["GetMeshIndexData"];
mt["GetProgramState"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getProgramState);
mt["get"]["ProgramState"]=mt["GetProgramState"];
mt["GetName"]=static_cast<const std::string&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getName);
mt["get"]["Name"]=mt["GetName"];
mt["SetBlendFunc"]=static_cast<void(cocos2d::Mesh::*)(const cocos2d::BlendFunc&)>(&cocos2d::Mesh::setBlendFunc);
mt["set"]["BlendFunc"]=mt["SetBlendFunc"];
mt["GetBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getBlendFunc);
mt["get"]["BlendFunc"]=mt["GetBlendFunc"];
mt["GetPrimitiveType"]=static_cast<cocos2d::CustomCommand::PrimitiveType(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getPrimitiveType);
mt["get"]["PrimitiveType"]=mt["GetPrimitiveType"];
mt["GetIndexCount"]=static_cast<ssize_t(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexCount);
mt["get"]["IndexCount"]=mt["GetIndexCount"];
mt["GetIndexFormat"]=static_cast<cocos2d::CustomCommand::IndexFormat(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexFormat);
mt["get"]["IndexFormat"]=mt["GetIndexFormat"];
mt["GetIndexBuffer"]=static_cast<cocos2d::backend::Buffer*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getIndexBuffer);
mt["get"]["IndexBuffer"]=mt["GetIndexBuffer"];
mt["GetAABB"]=static_cast<const cocos2d::AABB&(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getAABB);
mt["get"]["AABB"]=mt["GetAABB"];
mt["SetProgramState"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::backend::ProgramState*)>(&cocos2d::Mesh::setProgramState);
mt["set"]["ProgramState"]=mt["SetProgramState"];
mt["SetMaterial"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::Material*)>(&cocos2d::Mesh::setMaterial);
mt["set"]["Material"]=mt["SetMaterial"];
mt["GetMaterial"]=static_cast<cocos2d::Material*(cocos2d::Mesh::*)()const>(&cocos2d::Mesh::getMaterial);
mt["get"]["Material"]=mt["GetMaterial"];
mt["Draw"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::Renderer*,float,const cocos2d::Mat4&,uint32_t,unsigned int,const cocos2d::Vec4&,bool)>(&cocos2d::Mesh::draw);
mt["SetSkin"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshSkin*)>(&cocos2d::Mesh::setSkin);
mt["set"]["Skin"]=mt["SetSkin"];
mt["SetMeshIndexData"]=static_cast<void(cocos2d::Mesh::*)(cocos2d::MeshIndexData*)>(&cocos2d::Mesh::setMeshIndexData);
mt["set"]["MeshIndexData"]=mt["SetMeshIndexData"];
mt["SetName"]=static_cast<void(cocos2d::Mesh::*)(const std::string&)>(&cocos2d::Mesh::setName);
mt["set"]["Name"]=mt["SetName"];
mt["CalculateAABB"]=static_cast<void(cocos2d::Mesh::*)()>(&cocos2d::Mesh::calculateAABB);
mt["SetForce2DQueue"]=static_cast<void(cocos2d::Mesh::*)(bool)>(&cocos2d::Mesh::setForce2DQueue);
mt["set"]["Force2DQueue"]=mt["SetForce2DQueue"];
mt["GetTextureFileName"]=static_cast<std::string(cocos2d::Mesh::*)()>(&cocos2d::Mesh::getTextureFileName);
mt["get"]["TextureFileName"]=mt["GetTextureFileName"];
}
void RegisterLua3DSkeleton3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Skeleton3D).name()] = sol::usertype_traits<cocos2d::Skeleton3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Skeleton3D>("deprecated.cocos2d::Skeleton3D");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Skeleton3D*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Skeleton3D"]=mt;
mt["__new__"]=static_cast<cocos2d::Skeleton3D*(*)(const std::vector<cocos2d::NodeData *, std::allocator<cocos2d::NodeData *> >&)>(&cocos2d::Skeleton3D::create);
mt["GetBoneCount"]=static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getBoneCount);
mt["get"]["BoneCount"]=mt["GetBoneCount"];
mt["GetBoneByIndex"]=static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(unsigned int)const>(&cocos2d::Skeleton3D::getBoneByIndex);
mt["GetBoneByName"]=static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(const std::string&)const>(&cocos2d::Skeleton3D::getBoneByName);
mt["GetRootCount"]=static_cast<ssize_t(cocos2d::Skeleton3D::*)()const>(&cocos2d::Skeleton3D::getRootCount);
mt["get"]["RootCount"]=mt["GetRootCount"];
mt["GetRootBone"]=static_cast<cocos2d::Bone3D*(cocos2d::Skeleton3D::*)(int)const>(&cocos2d::Skeleton3D::getRootBone);
mt["GetBoneIndex"]=static_cast<int(cocos2d::Skeleton3D::*)(cocos2d::Bone3D*)const>(&cocos2d::Skeleton3D::getBoneIndex);
mt["UpdateBoneMatrix"]=static_cast<void(cocos2d::Skeleton3D::*)()>(&cocos2d::Skeleton3D::updateBoneMatrix);
}
void RegisterLua3DSkyboxAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Skybox).name()] = sol::usertype_traits<cocos2d::Skybox*>::metatable();
auto dep=lua.new_usertype<cocos2d::Skybox>("deprecated.cocos2d::Skybox");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Skybox*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["Skybox"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::Skybox*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::Skybox::create),static_cast<cocos2d::Skybox*(*)()>(&cocos2d::Skybox::create));
mt["SetTexture"]=static_cast<void(cocos2d::Skybox::*)(cocos2d::TextureCube*)>(&cocos2d::Skybox::setTexture);
mt["set"]["Texture"]=mt["SetTexture"];
mt["Reload"]=static_cast<void(cocos2d::Skybox::*)()>(&cocos2d::Skybox::reload);
}
void RegisterLua3DSprite3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Sprite3D).name()] = sol::usertype_traits<cocos2d::Sprite3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Sprite3D>("deprecated.cocos2d::Sprite3D");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Sprite3D*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::BlendProtocol*>::metatable());
lua["cc"]["Sprite3D"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create));
mt["static"]["CreateAsync"]=sol::overload(static_cast<void(*)(const std::string&,const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync),static_cast<void(*)(const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync));
mt["SetTexture"]=sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture));
mt["set"]["Texture"]=mt["SetTexture"];
mt["GetMeshByIndex"]=static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex);
mt["GetMeshByName"]=static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName);
mt["GetMeshArrayByName"]=static_cast<std::vector<cocos2d::Mesh *, std::allocator<cocos2d::Mesh *> >(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshArrayByName);
mt["GetMesh"]=static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh);
mt["get"]["Mesh"]=mt["GetMesh"];
mt["GetMeshCount"]=static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount);
mt["get"]["MeshCount"]=mt["GetMeshCount"];
mt["GetSkeleton"]=static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton);
mt["get"]["Skeleton"]=mt["GetSkeleton"];
mt["GetAttachNode"]=static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode);
mt["RemoveAttachNode"]=static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode);
mt["RemoveAllAttachNode"]=static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode);
mt["GetAABB"]=static_cast<const cocos2d::AABB&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getAABB);
mt["get"]["AABB"]=mt["GetAABB"];
mt["GetAABBRecursively"]=static_cast<cocos2d::AABB(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::getAABBRecursively);
mt["get"]["AABBRecursively"]=mt["GetAABBRecursively"];
mt["SetForceDepthWrite"]=static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite);
mt["set"]["ForceDepthWrite"]=mt["SetForceDepthWrite"];
mt["IsForceDepthWrite"]=static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite);
mt["get"]["ForceDepthWrite"]=mt["IsForceDepthWrite"];
mt["SetCullFace"]=static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace);
mt["set"]["CullFace"]=mt["SetCullFace"];
mt["SetCullFaceEnabled"]=static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled);
mt["set"]["CullFaceEnabled"]=mt["SetCullFaceEnabled"];
mt["SetLightMask"]=static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask);
mt["set"]["LightMask"]=mt["SetLightMask"];
mt["GetLightMask"]=static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask);
mt["get"]["LightMask"]=mt["GetLightMask"];
mt["SetMaterial"]=sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial));
mt["set"]["Material"]=mt["SetMaterial"];
mt["GetMaterial"]=static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial);
mt["SetForce2DQueue"]=static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue);
mt["set"]["Force2DQueue"]=mt["SetForce2DQueue"];
mt["GetMeshes"]=static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes);
mt["get"]["Meshes"]=mt["GetMeshes"];
}
void RegisterLua3DSprite3DCacheAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Sprite3DCache).name()] = sol::usertype_traits<cocos2d::Sprite3DCache*>::metatable();
auto dep=lua.new_usertype<cocos2d::Sprite3DCache>("deprecated.cocos2d::Sprite3DCache");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Sprite3DCache*>::metatable());
lua["cc"]["Sprite3DCache"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocos2d::Sprite3DCache*(*)()>(&cocos2d::Sprite3DCache::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocos2d::Sprite3DCache::destroyInstance);
mt["GetSpriteData"]=static_cast<cocos2d::Sprite3DCache::Sprite3DData*(cocos2d::Sprite3DCache::*)(const std::string&)const>(&cocos2d::Sprite3DCache::getSpriteData);
mt["AddSprite3DData"]=static_cast<bool(cocos2d::Sprite3DCache::*)(const std::string&,cocos2d::Sprite3DCache::Sprite3DData*)>(&cocos2d::Sprite3DCache::addSprite3DData);
mt["RemoveSprite3DData"]=static_cast<void(cocos2d::Sprite3DCache::*)(const std::string&)>(&cocos2d::Sprite3DCache::removeSprite3DData);
mt["RemoveAllSprite3DData"]=static_cast<void(cocos2d::Sprite3DCache::*)()>(&cocos2d::Sprite3DCache::removeAllSprite3DData);
mt["static"]["get"]["Instance"]=&cocos2d::Sprite3DCache::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocos2d::Sprite3DCache::destroyInstance();};
}
