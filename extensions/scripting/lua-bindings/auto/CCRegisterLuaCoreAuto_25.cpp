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
namespace cocos2d{
void RegisterLuaCoreDirectionLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::DirectionLight).name()] = sol::usertype_traits<cocos2d::DirectionLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::DirectionLight>("deprecated.cocos2d::DirectionLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::DirectionLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["DirectionLight"]=mt;
mt["__new__"]=static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create);
mt["SetDirection"]=static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection);
mt["set"]["Direction"]=mt["SetDirection"];
mt["GetDirection"]=static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection);
mt["get"]["Direction"]=mt["GetDirection"];
mt["GetDirectionInWorld"]=static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld);
mt["get"]["DirectionInWorld"]=mt["GetDirectionInWorld"];
}
void RegisterLuaCorePointLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PointLight).name()] = sol::usertype_traits<cocos2d::PointLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::PointLight>("deprecated.cocos2d::PointLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PointLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["PointLight"]=mt;
mt["__new__"]=static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create);
mt["GetRange"]=static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange);
mt["get"]["Range"]=mt["GetRange"];
mt["SetRange"]=static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange);
mt["set"]["Range"]=mt["SetRange"];
}
void RegisterLuaCoreSpotLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SpotLight).name()] = sol::usertype_traits<cocos2d::SpotLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::SpotLight>("deprecated.cocos2d::SpotLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SpotLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["SpotLight"]=mt;
mt["__new__"]=static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create);
mt["SetDirection"]=static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection);
mt["set"]["Direction"]=mt["SetDirection"];
mt["GetDirection"]=static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection);
mt["get"]["Direction"]=mt["GetDirection"];
mt["GetDirectionInWorld"]=static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld);
mt["get"]["DirectionInWorld"]=mt["GetDirectionInWorld"];
mt["SetRange"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange);
mt["set"]["Range"]=mt["SetRange"];
mt["GetRange"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange);
mt["get"]["Range"]=mt["GetRange"];
mt["SetInnerAngle"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle);
mt["set"]["InnerAngle"]=mt["SetInnerAngle"];
mt["GetInnerAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle);
mt["get"]["InnerAngle"]=mt["GetInnerAngle"];
mt["GetCosInnerAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle);
mt["get"]["CosInnerAngle"]=mt["GetCosInnerAngle"];
mt["SetOuterAngle"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle);
mt["set"]["OuterAngle"]=mt["SetOuterAngle"];
mt["GetOuterAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle);
mt["get"]["OuterAngle"]=mt["GetOuterAngle"];
mt["GetCosOuterAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle);
mt["get"]["CosOuterAngle"]=mt["GetCosOuterAngle"];
}
void RegisterLuaCoreAmbientLightAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AmbientLight).name()] = sol::usertype_traits<cocos2d::AmbientLight*>::metatable();
auto dep=lua.new_usertype<cocos2d::AmbientLight>("deprecated.cocos2d::AmbientLight");
dep[sol::base_classes]=sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AmbientLight*>::metatable(),sol::usertype_traits<cocos2d::BaseLight*>::metatable());
lua["cc"]["AmbientLight"]=mt;
mt["__new__"]=static_cast<cocos2d::AmbientLight*(*)(const cocos2d::Color3B&)>(&cocos2d::AmbientLight::create);
}
void RegisterLuaCoreRenderStateAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RenderState).name()] = sol::usertype_traits<cocos2d::RenderState*>::metatable();
auto dep=lua.new_usertype<cocos2d::RenderState>("deprecated.cocos2d::RenderState");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RenderState*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["RenderState"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetName"]=static_cast<std::string(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getName);
mt["get"]["Name"]=mt["GetName"];
mt["BindPass"]=static_cast<void(cocos2d::RenderState::*)(cocos2d::Pass*,cocos2d::MeshCommand*)>(&cocos2d::RenderState::bindPass);
mt["GetStateBlock"]=static_cast<cocos2d::RenderState::StateBlock&(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getStateBlock);
mt["get"]["StateBlock"]=mt["GetStateBlock"];
}
void RegisterLuaCoreTechniqueAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Technique).name()] = sol::usertype_traits<cocos2d::Technique*>::metatable();
auto dep=lua.new_usertype<cocos2d::Technique>("deprecated.cocos2d::Technique");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Technique*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Technique"]=mt;
mt["static"]["CreateWithProgramState"]=static_cast<cocos2d::Technique*(*)(cocos2d::Material*,cocos2d::backend::ProgramState*)>(&cocos2d::Technique::createWithProgramState);
mt["__new__"]=static_cast<cocos2d::Technique*(*)(cocos2d::Material*)>(&cocos2d::Technique::create);
mt["AddPass"]=static_cast<void(cocos2d::Technique::*)(cocos2d::Pass*)>(&cocos2d::Technique::addPass);
mt["GetName"]=static_cast<std::string(cocos2d::Technique::*)()const>(&cocos2d::Technique::getName);
mt["get"]["Name"]=mt["GetName"];
mt["GetPassByIndex"]=static_cast<cocos2d::Pass*(cocos2d::Technique::*)(ssize_t)const>(&cocos2d::Technique::getPassByIndex);
mt["GetPassCount"]=static_cast<ssize_t(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPassCount);
mt["get"]["PassCount"]=mt["GetPassCount"];
mt["GetPasses"]=static_cast<const cocos2d::Vector<cocos2d::Pass *>&(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPasses);
mt["get"]["Passes"]=mt["GetPasses"];
mt["Clone"]=static_cast<cocos2d::Technique*(cocos2d::Technique::*)()const>(&cocos2d::Technique::clone);
mt["SetMaterial"]=static_cast<void(cocos2d::Technique::*)(cocos2d::Material*)>(&cocos2d::Technique::setMaterial);
mt["set"]["Material"]=mt["SetMaterial"];
mt["GetStateBlock"]=static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Technique::*)()>(&cocos2d::Technique::getStateBlock);
mt["get"]["StateBlock"]=mt["GetStateBlock"];
}
void RegisterLuaCoreMaterialAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Material).name()] = sol::usertype_traits<cocos2d::Material*>::metatable();
auto dep=lua.new_usertype<cocos2d::Material>("deprecated.cocos2d::Material");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Material*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Material"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["CreateWithFilename"]=static_cast<cocos2d::Material*(*)(const std::string&)>(&cocos2d::Material::createWithFilename);
mt["static"]["CreateWithProgramState"]=static_cast<cocos2d::Material*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Material::createWithProgramState);
mt["static"]["CreateWithProperties"]=static_cast<cocos2d::Material*(*)(cocos2d::Properties*)>(&cocos2d::Material::createWithProperties);
mt["Draw"]=static_cast<void(cocos2d::Material::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::CustomCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Material::draw);
mt["GetName"]=static_cast<std::string(cocos2d::Material::*)()const>(&cocos2d::Material::getName);
mt["get"]["Name"]=mt["GetName"];
mt["SetName"]=static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setName);
mt["set"]["Name"]=mt["SetName"];
mt["GetTechniqueByName"]=static_cast<cocos2d::Technique*(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::getTechniqueByName);
mt["GetTechniqueByIndex"]=static_cast<cocos2d::Technique*(cocos2d::Material::*)(ssize_t)>(&cocos2d::Material::getTechniqueByIndex);
mt["GetTechnique"]=static_cast<cocos2d::Technique*(cocos2d::Material::*)()const>(&cocos2d::Material::getTechnique);
mt["get"]["Technique"]=mt["GetTechnique"];
mt["GetTechniques"]=static_cast<const cocos2d::Vector<cocos2d::Technique *>&(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniques);
mt["get"]["Techniques"]=mt["GetTechniques"];
mt["GetTechniqueCount"]=static_cast<ssize_t(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniqueCount);
mt["get"]["TechniqueCount"]=mt["GetTechniqueCount"];
mt["AddTechnique"]=static_cast<void(cocos2d::Material::*)(cocos2d::Technique*)>(&cocos2d::Material::addTechnique);
mt["SetTechnique"]=static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setTechnique);
mt["set"]["Technique"]=mt["SetTechnique"];
mt["Clone"]=static_cast<cocos2d::Material*(cocos2d::Material::*)()const>(&cocos2d::Material::clone);
mt["GetStateBlock"]=static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Material::*)()>(&cocos2d::Material::getStateBlock);
mt["get"]["StateBlock"]=mt["GetStateBlock"];
mt["SetStateBlock"]=static_cast<void(cocos2d::Material::*)(const cocos2d::RenderState::StateBlock&)>(&cocos2d::Material::setStateBlock);
mt["set"]["StateBlock"]=mt["SetStateBlock"];
mt["GetRenderState"]=static_cast<cocos2d::RenderState*(cocos2d::Material::*)()>(&cocos2d::Material::getRenderState);
mt["get"]["RenderState"]=mt["GetRenderState"];
}
void RegisterLuaCorePassAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Pass).name()] = sol::usertype_traits<cocos2d::Pass*>::metatable();
auto dep=lua.new_usertype<cocos2d::Pass>("deprecated.cocos2d::Pass");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Pass*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Pass"]=mt;
mt["static"]["CreateWithProgramState"]=static_cast<cocos2d::Pass*(*)(cocos2d::Technique*,cocos2d::backend::ProgramState*)>(&cocos2d::Pass::createWithProgramState);
mt["__new__"]=static_cast<cocos2d::Pass*(*)(cocos2d::Technique*)>(&cocos2d::Pass::create);
mt["GetProgramState"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getProgramState);
mt["get"]["ProgramState"]=mt["GetProgramState"];
mt["Draw"]=static_cast<void(cocos2d::Pass::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::MeshCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Pass::draw);
mt["SetVertexAttribBinding"]=static_cast<void(cocos2d::Pass::*)(cocos2d::VertexAttribBinding*)>(&cocos2d::Pass::setVertexAttribBinding);
mt["set"]["VertexAttribBinding"]=mt["SetVertexAttribBinding"];
mt["GetVertexAttributeBinding"]=static_cast<cocos2d::VertexAttribBinding*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getVertexAttributeBinding);
mt["get"]["VertexAttributeBinding"]=mt["GetVertexAttributeBinding"];
mt["SetName"]=static_cast<void(cocos2d::Pass::*)(const std::string&)>(&cocos2d::Pass::setName);
mt["set"]["Name"]=mt["SetName"];
mt["GetName"]=static_cast<const std::string&(cocos2d::Pass::*)()const>(&cocos2d::Pass::getName);
mt["get"]["Name"]=mt["GetName"];
mt["GetStateBlock"]=static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Pass::*)()>(&cocos2d::Pass::getStateBlock);
mt["get"]["StateBlock"]=mt["GetStateBlock"];
mt["Clone"]=static_cast<cocos2d::Pass*(cocos2d::Pass::*)()const>(&cocos2d::Pass::clone);
mt["SetTechnique"]=static_cast<void(cocos2d::Pass::*)(cocos2d::Technique*)>(&cocos2d::Pass::setTechnique);
mt["set"]["Technique"]=mt["SetTechnique"];
mt["UpdateMVPUniform"]=static_cast<void(cocos2d::Pass::*)(const cocos2d::Mat4&)>(&cocos2d::Pass::updateMVPUniform);
mt["SetUniformTexture"]=static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformTexture);
mt["SetUniformNormTexture"]=static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformNormTexture);
mt["SetUniformColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformColor);
mt["SetUniformMatrixPalette"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformMatrixPalette);
mt["SetUniformDirLightColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightColor);
mt["SetUniformDirLightDir"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightDir);
mt["SetUniformPointLightColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightColor);
mt["SetUniformPointLightPosition"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightPosition);
mt["SetUniformPointLightRangeInverse"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightRangeInverse);
mt["SetUniformSpotLightColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightColor);
mt["SetUniformSpotLightPosition"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightPosition);
mt["SetUniformSpotLightDir"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightDir);
mt["SetUniformSpotLightInnerAngleCos"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightInnerAngleCos);
mt["SetUniformSpotLightOuterAngleCos"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightOuterAngleCos);
mt["SetUniformSpotLightRangeInverse"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightRangeInverse);
mt["SetUniformAmbientLigthColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformAmbientLigthColor);
}
void RegisterLuaCoreRendererAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Renderer).name()] = sol::usertype_traits<cocos2d::Renderer*>::metatable();
auto dep=lua.new_usertype<cocos2d::Renderer>("deprecated.cocos2d::Renderer");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Renderer*>::metatable());
lua["cc"]["Renderer"]=mt;
mt["Init"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::init);
mt["AddCommand"]=sol::overload(static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*,int)>(&cocos2d::Renderer::addCommand),static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*)>(&cocos2d::Renderer::addCommand));
mt["PushGroup"]=static_cast<void(cocos2d::Renderer::*)(int)>(&cocos2d::Renderer::pushGroup);
mt["PopGroup"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::popGroup);
mt["CreateRenderQueue"]=static_cast<int(cocos2d::Renderer::*)()>(&cocos2d::Renderer::createRenderQueue);
mt["Render"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::render);
mt["Clean"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clean);
mt["GetDrawnBatches"]=static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnBatches);
mt["get"]["DrawnBatches"]=mt["GetDrawnBatches"];
mt["AddDrawnBatches"]=static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnBatches);
mt["GetDrawnVertices"]=static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnVertices);
mt["get"]["DrawnVertices"]=mt["GetDrawnVertices"];
mt["AddDrawnVertices"]=static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnVertices);
mt["ClearDrawStats"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clearDrawStats);
mt["GetRenderTarget"]=static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTarget);
mt["get"]["RenderTarget"]=mt["GetRenderTarget"];
mt["SetRenderTarget"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*)>(&cocos2d::Renderer::setRenderTarget);
mt["set"]["RenderTarget"]=mt["SetRenderTarget"];
mt["GetDefaultRenderTarget"]=static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDefaultRenderTarget);
mt["get"]["DefaultRenderTarget"]=mt["GetDefaultRenderTarget"];
mt["Clear"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::ClearFlag,const cocos2d::Color4F&,float,unsigned int,float)>(&cocos2d::Renderer::clear);
mt["GetClearColor"]=static_cast<const cocos2d::Color4F&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearColor);
mt["get"]["ClearColor"]=mt["GetClearColor"];
mt["GetClearDepth"]=static_cast<float(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearDepth);
mt["get"]["ClearDepth"]=mt["GetClearDepth"];
mt["GetClearStencil"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearStencil);
mt["get"]["ClearStencil"]=mt["GetClearStencil"];
mt["GetClearFlag"]=static_cast<cocos2d::ClearFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearFlag);
mt["get"]["ClearFlag"]=mt["GetClearFlag"];
mt["GetRenderTargetFlag"]=static_cast<cocos2d::RenderTargetFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTargetFlag);
mt["get"]["RenderTargetFlag"]=mt["GetRenderTargetFlag"];
mt["SetDepthTest"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthTest);
mt["set"]["DepthTest"]=mt["SetDepthTest"];
mt["SetDepthWrite"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthWrite);
mt["set"]["DepthWrite"]=mt["SetDepthWrite"];
mt["SetDepthCompareFunction"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction)>(&cocos2d::Renderer::setDepthCompareFunction);
mt["set"]["DepthCompareFunction"]=mt["SetDepthCompareFunction"];
mt["GetDepthTest"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthTest);
mt["get"]["DepthTest"]=mt["GetDepthTest"];
mt["GetDepthWrite"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthWrite);
mt["get"]["DepthWrite"]=mt["GetDepthWrite"];
mt["GetDepthCompareFunction"]=static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthCompareFunction);
mt["get"]["DepthCompareFunction"]=mt["GetDepthCompareFunction"];
mt["SetStencilTest"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setStencilTest);
mt["set"]["StencilTest"]=mt["SetStencilTest"];
mt["SetStencilCompareFunction"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction,unsigned int,unsigned int)>(&cocos2d::Renderer::setStencilCompareFunction);
mt["SetStencilOperation"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation)>(&cocos2d::Renderer::setStencilOperation);
mt["SetStencilWriteMask"]=static_cast<void(cocos2d::Renderer::*)(unsigned int)>(&cocos2d::Renderer::setStencilWriteMask);
mt["set"]["StencilWriteMask"]=mt["SetStencilWriteMask"];
mt["GetStencilTest"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilTest);
mt["get"]["StencilTest"]=mt["GetStencilTest"];
mt["GetStencilFailureOperation"]=static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilFailureOperation);
mt["get"]["StencilFailureOperation"]=mt["GetStencilFailureOperation"];
mt["GetStencilPassDepthFailureOperation"]=static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilPassDepthFailureOperation);
mt["get"]["StencilPassDepthFailureOperation"]=mt["GetStencilPassDepthFailureOperation"];
mt["GetStencilDepthPassOperation"]=static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilDepthPassOperation);
mt["get"]["StencilDepthPassOperation"]=mt["GetStencilDepthPassOperation"];
mt["GetStencilCompareFunction"]=static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilCompareFunction);
mt["get"]["StencilCompareFunction"]=mt["GetStencilCompareFunction"];
mt["GetStencilReadMask"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReadMask);
mt["get"]["StencilReadMask"]=mt["GetStencilReadMask"];
mt["GetStencilWriteMask"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilWriteMask);
mt["get"]["StencilWriteMask"]=mt["GetStencilWriteMask"];
mt["GetStencilReferenceValue"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReferenceValue);
mt["get"]["StencilReferenceValue"]=mt["GetStencilReferenceValue"];
mt["SetDepthStencilDesc"]=static_cast<void(cocos2d::Renderer::*)(const cocos2d::backend::DepthStencilDescriptor&)>(&cocos2d::Renderer::setDepthStencilDesc);
mt["set"]["DepthStencilDesc"]=mt["SetDepthStencilDesc"];
mt["GetDepthStencilDesc"]=static_cast<const cocos2d::backend::DepthStencilDescriptor&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthStencilDesc);
mt["get"]["DepthStencilDesc"]=mt["GetDepthStencilDesc"];
mt["SetCullMode"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::CullMode)>(&cocos2d::Renderer::setCullMode);
mt["set"]["CullMode"]=mt["SetCullMode"];
mt["GetCullMode"]=static_cast<cocos2d::CullMode(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getCullMode);
mt["get"]["CullMode"]=mt["GetCullMode"];
mt["SetWinding"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::Winding)>(&cocos2d::Renderer::setWinding);
mt["set"]["Winding"]=mt["SetWinding"];
mt["GetWinding"]=static_cast<cocos2d::Winding(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getWinding);
mt["get"]["Winding"]=mt["GetWinding"];
mt["SetViewPort"]=static_cast<void(cocos2d::Renderer::*)(int,int,unsigned int,unsigned int)>(&cocos2d::Renderer::setViewPort);
mt["GetViewport"]=static_cast<const cocos2d::Viewport&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getViewport);
mt["get"]["Viewport"]=mt["GetViewport"];
mt["SetScissorTest"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setScissorTest);
mt["set"]["ScissorTest"]=mt["SetScissorTest"];
mt["SetScissorRect"]=static_cast<void(cocos2d::Renderer::*)(float,float,float,float)>(&cocos2d::Renderer::setScissorRect);
mt["GetScissorTest"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorTest);
mt["get"]["ScissorTest"]=mt["GetScissorTest"];
mt["GetScissorRect"]=static_cast<const cocos2d::ScissorRect&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorRect);
mt["get"]["ScissorRect"]=mt["GetScissorRect"];
mt["CheckVisibility"]=static_cast<bool(cocos2d::Renderer::*)(const cocos2d::Mat4&,const cocos2d::Size&)>(&cocos2d::Renderer::checkVisibility);
mt["ReadPixels"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*,std::function<void (const cocos2d::backend::PixelBufferDescriptor &)>)>(&cocos2d::Renderer::readPixels);
mt["BeginRenderPass"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::beginRenderPass);
mt["EndRenderPass"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::endRenderPass);
mt["static"]["get"]["VBO_SIZE"]=[]()->const int&{return cocos2d::Renderer::VBO_SIZE;};
mt["static"]["get"]["INDEX_VBO_SIZE"]=[]()->const int&{return cocos2d::Renderer::INDEX_VBO_SIZE;};
mt["static"]["get"]["BATCH_TRIAGCOMMAND_RESERVED_SIZE"]=[]()->const int&{return cocos2d::Renderer::BATCH_TRIAGCOMMAND_RESERVED_SIZE;};
mt["static"]["get"]["MATERIAL_ID_DO_NOT_BATCH"]=[]()->const int&{return cocos2d::Renderer::MATERIAL_ID_DO_NOT_BATCH;};
}
void RegisterLuaCoreTextureCacheAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TextureCache).name()] = sol::usertype_traits<cocos2d::TextureCache*>::metatable();
auto dep=lua.new_usertype<cocos2d::TextureCache>("deprecated.cocos2d::TextureCache");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TextureCache*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TextureCache"]=mt;
mt["__new__"]=[](){return new cocos2d::TextureCache();};
mt["static"]["SetETC1AlphaFileSuffix"]=static_cast<void(*)(const std::string&)>(&cocos2d::TextureCache::setETC1AlphaFileSuffix);
mt["static"]["set"]["ETC1AlphaFileSuffix"]=mt["SetETC1AlphaFileSuffix"];
mt["static"]["GetETC1AlphaFileSuffix"]=static_cast<std::string(*)()>(&cocos2d::TextureCache::getETC1AlphaFileSuffix);
mt["static"]["get"]["ETC1AlphaFileSuffix"]=mt["GetETC1AlphaFileSuffix"];
mt["GetDescription"]=static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getDescription);
mt["get"]["Description"]=mt["GetDescription"];
mt["AddImage"]=sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(cocos2d::Image*,const std::string&)>(&cocos2d::TextureCache::addImage),static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::addImage));
mt["AddImageAsync"]=sol::overload(static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&,const std::string&)>(&cocos2d::TextureCache::addImageAsync),static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&)>(&cocos2d::TextureCache::addImageAsync));
mt["UnbindImageAsync"]=static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::unbindImageAsync);
mt["UnbindAllImageAsync"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::unbindAllImageAsync);
mt["GetTextureForKey"]=static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)const>(&cocos2d::TextureCache::getTextureForKey);
mt["ReloadTexture"]=static_cast<bool(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::reloadTexture);
mt["RemoveAllTextures"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeAllTextures);
mt["RemoveUnusedTextures"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeUnusedTextures);
mt["RemoveTexture"]=static_cast<void(cocos2d::TextureCache::*)(cocos2d::Texture2D*)>(&cocos2d::TextureCache::removeTexture);
mt["RemoveTextureForKey"]=static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::removeTextureForKey);
mt["GetCachedTextureInfo"]=static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getCachedTextureInfo);
mt["get"]["CachedTextureInfo"]=mt["GetCachedTextureInfo"];
mt["WaitForQuit"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::waitForQuit);
mt["GetTextureFilePath"]=static_cast<std::string(cocos2d::TextureCache::*)(cocos2d::Texture2D*)const>(&cocos2d::TextureCache::getTextureFilePath);
mt["RenameTextureWithKey"]=static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::string&)>(&cocos2d::TextureCache::renameTextureWithKey);
}
}
