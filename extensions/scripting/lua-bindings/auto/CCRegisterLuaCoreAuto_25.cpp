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
void RegisterLuaCoreBaseLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::BaseLight>("cc","BaseLight",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightType));
mt.set_function("GetIntensity",static_cast<float(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getIntensity));
mt.set_function("SetIntensity",static_cast<void(cocos2d::BaseLight::*)(float)>(&cocos2d::BaseLight::setIntensity));
mt.set_function("GetLightFlag",static_cast<cocos2d::LightFlag(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightFlag));
mt.set_function("SetLightFlag",static_cast<void(cocos2d::BaseLight::*)(cocos2d::LightFlag)>(&cocos2d::BaseLight::setLightFlag));
mt.set_function("SetEnabled",static_cast<void(cocos2d::BaseLight::*)(bool)>(&cocos2d::BaseLight::setEnabled));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::isEnabled));
mt.set_function("OnEnter",static_cast<void(cocos2d::BaseLight::*)()>(&cocos2d::BaseLight::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::BaseLight::*)()>(&cocos2d::BaseLight::onExit));
}
void RegisterLuaCoreDirectionLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DirectionLight>("cc","DirectionLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getLightType));
mt.set_function("SetDirection",static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection));
mt.set_function("GetDirection",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection));
mt.set_function("GetDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld));
}
void RegisterLuaCorePointLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PointLight>("cc","PointLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getLightType));
mt.set_function("GetRange",static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange));
mt.set_function("SetRange",static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange));
}
void RegisterLuaCoreSpotLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpotLight>("cc","SpotLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getLightType));
mt.set_function("SetDirection",static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection));
mt.set_function("GetDirection",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection));
mt.set_function("GetDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld));
mt.set_function("SetRange",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange));
mt.set_function("GetRange",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange));
mt.set_function("SetInnerAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle));
mt.set_function("GetInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle));
mt.set_function("GetCosInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle));
mt.set_function("SetOuterAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle));
mt.set_function("GetOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle));
mt.set_function("GetCosOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle));
}
void RegisterLuaCoreAmbientLightAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AmbientLight>("cc","AmbientLight",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::AmbientLight*(*)(const cocos2d::Color3B&)>(&cocos2d::AmbientLight::create));
mt.set_function("GetLightType",static_cast<cocos2d::LightType(cocos2d::AmbientLight::*)()const>(&cocos2d::AmbientLight::getLightType));
}
void RegisterLuaCoreRenderStateAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RenderState>("cc","RenderState",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetName",static_cast<std::string(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getName));
mt.set_function("BindPass",static_cast<void(cocos2d::RenderState::*)(cocos2d::Pass*,cocos2d::MeshCommand*)>(&cocos2d::RenderState::bindPass));
mt.set_function("GetStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getStateBlock));
}
void RegisterLuaCoreTechniqueAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Technique>("cc","Technique",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateWithProgramState",static_cast<cocos2d::Technique*(*)(cocos2d::Material*,cocos2d::backend::ProgramState*)>(&cocos2d::Technique::createWithProgramState));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Technique*(*)(cocos2d::Material*)>(&cocos2d::Technique::create));
mt.set_function("AddPass",static_cast<void(cocos2d::Technique::*)(cocos2d::Pass*)>(&cocos2d::Technique::addPass));
mt.set_function("GetName",static_cast<std::string(cocos2d::Technique::*)()const>(&cocos2d::Technique::getName));
mt.set_function("GetPassByIndex",static_cast<cocos2d::Pass*(cocos2d::Technique::*)(ssize_t)const>(&cocos2d::Technique::getPassByIndex));
mt.set_function("GetPassCount",static_cast<ssize_t(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPassCount));
mt.set_function("GetPasses",static_cast<const cocos2d::Vector<cocos2d::Pass *>&(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPasses));
mt.set_function("Clone",static_cast<cocos2d::Technique*(cocos2d::Technique::*)()const>(&cocos2d::Technique::clone));
mt.set_function("SetMaterial",static_cast<void(cocos2d::Technique::*)(cocos2d::Material*)>(&cocos2d::Technique::setMaterial));
mt.set_function("GetStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Technique::*)()>(&cocos2d::Technique::getStateBlock));
}
void RegisterLuaCoreMaterialAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Material>("cc","Material",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateWithFilename",static_cast<cocos2d::Material*(*)(const std::string&)>(&cocos2d::Material::createWithFilename));
mt.set_function("CreateWithProgramState",static_cast<cocos2d::Material*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Material::createWithProgramState));
mt.set_function("CreateWithProperties",static_cast<cocos2d::Material*(*)(cocos2d::Properties*)>(&cocos2d::Material::createWithProperties));
mt.set_function("Draw",static_cast<void(cocos2d::Material::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::CustomCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Material::draw));
mt.set_function("GetName",static_cast<std::string(cocos2d::Material::*)()const>(&cocos2d::Material::getName));
mt.set_function("SetName",static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setName));
mt.set_function("GetTechniqueByName",static_cast<cocos2d::Technique*(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::getTechniqueByName));
mt.set_function("GetTechniqueByIndex",static_cast<cocos2d::Technique*(cocos2d::Material::*)(ssize_t)>(&cocos2d::Material::getTechniqueByIndex));
mt.set_function("GetTechnique",static_cast<cocos2d::Technique*(cocos2d::Material::*)()const>(&cocos2d::Material::getTechnique));
mt.set_function("GetTechniques",static_cast<const cocos2d::Vector<cocos2d::Technique *>&(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniques));
mt.set_function("GetTechniqueCount",static_cast<ssize_t(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniqueCount));
mt.set_function("AddTechnique",static_cast<void(cocos2d::Material::*)(cocos2d::Technique*)>(&cocos2d::Material::addTechnique));
mt.set_function("SetTechnique",static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setTechnique));
mt.set_function("Clone",static_cast<cocos2d::Material*(cocos2d::Material::*)()const>(&cocos2d::Material::clone));
mt.set_function("GetStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Material::*)()>(&cocos2d::Material::getStateBlock));
mt.set_function("SetStateBlock",static_cast<void(cocos2d::Material::*)(const cocos2d::RenderState::StateBlock&)>(&cocos2d::Material::setStateBlock));
mt.set_function("GetRenderState",static_cast<cocos2d::RenderState*(cocos2d::Material::*)()>(&cocos2d::Material::getRenderState));
}
void RegisterLuaCorePassAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Pass>("cc","Pass",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateWithProgramState",static_cast<cocos2d::Pass*(*)(cocos2d::Technique*,cocos2d::backend::ProgramState*)>(&cocos2d::Pass::createWithProgramState));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Pass*(*)(cocos2d::Technique*)>(&cocos2d::Pass::create));
mt.set_function("GetProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getProgramState));
mt.set_function("Draw",static_cast<void(cocos2d::Pass::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::MeshCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Pass::draw));
mt.set_function("SetVertexAttribBinding",static_cast<void(cocos2d::Pass::*)(cocos2d::VertexAttribBinding*)>(&cocos2d::Pass::setVertexAttribBinding));
mt.set_function("GetVertexAttributeBinding",static_cast<cocos2d::VertexAttribBinding*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getVertexAttributeBinding));
mt.set_function("SetName",static_cast<void(cocos2d::Pass::*)(const std::string&)>(&cocos2d::Pass::setName));
mt.set_function("GetName",static_cast<const std::string&(cocos2d::Pass::*)()const>(&cocos2d::Pass::getName));
mt.set_function("GetStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Pass::*)()>(&cocos2d::Pass::getStateBlock));
mt.set_function("Clone",static_cast<cocos2d::Pass*(cocos2d::Pass::*)()const>(&cocos2d::Pass::clone));
mt.set_function("SetTechnique",static_cast<void(cocos2d::Pass::*)(cocos2d::Technique*)>(&cocos2d::Pass::setTechnique));
mt.set_function("UpdateMVPUniform",static_cast<void(cocos2d::Pass::*)(const cocos2d::Mat4&)>(&cocos2d::Pass::updateMVPUniform));
mt.set_function("SetUniformTexture",static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformTexture));
mt.set_function("SetUniformNormTexture",static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformNormTexture));
mt.set_function("SetUniformColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformColor));
mt.set_function("SetUniformMatrixPalette",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformMatrixPalette));
mt.set_function("SetUniformDirLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightColor));
mt.set_function("SetUniformDirLightDir",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightDir));
mt.set_function("SetUniformPointLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightColor));
mt.set_function("SetUniformPointLightPosition",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightPosition));
mt.set_function("SetUniformPointLightRangeInverse",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightRangeInverse));
mt.set_function("SetUniformSpotLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightColor));
mt.set_function("SetUniformSpotLightPosition",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightPosition));
mt.set_function("SetUniformSpotLightDir",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightDir));
mt.set_function("SetUniformSpotLightInnerAngleCos",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightInnerAngleCos));
mt.set_function("SetUniformSpotLightOuterAngleCos",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightOuterAngleCos));
mt.set_function("SetUniformSpotLightRangeInverse",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightRangeInverse));
mt.set_function("SetUniformAmbientLigthColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformAmbientLigthColor));
}
void RegisterLuaCoreRendererAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Renderer>("cc","Renderer",false);
mt.set_function("Init",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::init));
mt.set_function("AddCommand",sol::overload(static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*,int)>(&cocos2d::Renderer::addCommand),static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*)>(&cocos2d::Renderer::addCommand)));
mt.set_function("PushGroup",static_cast<void(cocos2d::Renderer::*)(int)>(&cocos2d::Renderer::pushGroup));
mt.set_function("PopGroup",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::popGroup));
mt.set_function("CreateRenderQueue",static_cast<int(cocos2d::Renderer::*)()>(&cocos2d::Renderer::createRenderQueue));
mt.set_function("Render",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::render));
mt.set_function("Clean",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clean));
mt.set_function("GetDrawnBatches",static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnBatches));
mt.set_function("AddDrawnBatches",static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnBatches));
mt.set_function("GetDrawnVertices",static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnVertices));
mt.set_function("AddDrawnVertices",static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnVertices));
mt.set_function("ClearDrawStats",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clearDrawStats));
mt.set_function("GetRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTarget));
mt.set_function("SetRenderTarget",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*)>(&cocos2d::Renderer::setRenderTarget));
mt.set_function("GetDefaultRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDefaultRenderTarget));
mt.set_function("Clear",static_cast<void(cocos2d::Renderer::*)(cocos2d::ClearFlag,const cocos2d::Color4F&,float,unsigned int,float)>(&cocos2d::Renderer::clear));
mt.set_function("GetClearColor",static_cast<const cocos2d::Color4F&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearColor));
mt.set_function("GetClearDepth",static_cast<float(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearDepth));
mt.set_function("GetClearStencil",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearStencil));
mt.set_function("GetClearFlag",static_cast<cocos2d::ClearFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearFlag));
mt.set_function("GetRenderTargetFlag",static_cast<cocos2d::RenderTargetFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTargetFlag));
mt.set_function("SetDepthTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthTest));
mt.set_function("SetDepthWrite",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthWrite));
mt.set_function("SetDepthCompareFunction",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction)>(&cocos2d::Renderer::setDepthCompareFunction));
mt.set_function("GetDepthTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthTest));
mt.set_function("GetDepthWrite",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthWrite));
mt.set_function("GetDepthCompareFunction",static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthCompareFunction));
mt.set_function("SetStencilTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setStencilTest));
mt.set_function("SetStencilCompareFunction",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction,unsigned int,unsigned int)>(&cocos2d::Renderer::setStencilCompareFunction));
mt.set_function("SetStencilOperation",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation)>(&cocos2d::Renderer::setStencilOperation));
mt.set_function("SetStencilWriteMask",static_cast<void(cocos2d::Renderer::*)(unsigned int)>(&cocos2d::Renderer::setStencilWriteMask));
mt.set_function("GetStencilTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilTest));
mt.set_function("GetStencilFailureOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilFailureOperation));
mt.set_function("GetStencilPassDepthFailureOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilPassDepthFailureOperation));
mt.set_function("GetStencilDepthPassOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilDepthPassOperation));
mt.set_function("GetStencilCompareFunction",static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilCompareFunction));
mt.set_function("GetStencilReadMask",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReadMask));
mt.set_function("GetStencilWriteMask",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilWriteMask));
mt.set_function("GetStencilReferenceValue",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReferenceValue));
mt.set_function("SetDepthStencilDesc",static_cast<void(cocos2d::Renderer::*)(const cocos2d::backend::DepthStencilDescriptor&)>(&cocos2d::Renderer::setDepthStencilDesc));
mt.set_function("GetDepthStencilDesc",static_cast<const cocos2d::backend::DepthStencilDescriptor&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthStencilDesc));
mt.set_function("SetCullMode",static_cast<void(cocos2d::Renderer::*)(cocos2d::CullMode)>(&cocos2d::Renderer::setCullMode));
mt.set_function("GetCullMode",static_cast<cocos2d::CullMode(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getCullMode));
mt.set_function("SetWinding",static_cast<void(cocos2d::Renderer::*)(cocos2d::Winding)>(&cocos2d::Renderer::setWinding));
mt.set_function("GetWinding",static_cast<cocos2d::Winding(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getWinding));
mt.set_function("SetViewPort",static_cast<void(cocos2d::Renderer::*)(int,int,unsigned int,unsigned int)>(&cocos2d::Renderer::setViewPort));
mt.set_function("GetViewport",static_cast<const cocos2d::Viewport&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getViewport));
mt.set_function("SetScissorTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setScissorTest));
mt.set_function("SetScissorRect",static_cast<void(cocos2d::Renderer::*)(float,float,float,float)>(&cocos2d::Renderer::setScissorRect));
mt.set_function("GetScissorTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorTest));
mt.set_function("GetScissorRect",static_cast<const cocos2d::ScissorRect&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorRect));
mt.set_function("CheckVisibility",static_cast<bool(cocos2d::Renderer::*)(const cocos2d::Mat4&,const cocos2d::Size&)>(&cocos2d::Renderer::checkVisibility));
mt.set_function("ReadPixels",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*,std::function<void (const cocos2d::backend::PixelBufferDescriptor &)>)>(&cocos2d::Renderer::readPixels));
mt[sol::call_constructor]=sol::constructors<cocos2d::Renderer()>();
mt["VBO_SIZE"]=sol::var(std::ref(cocos2d::Renderer::VBO_SIZE));
mt["INDEX_VBO_SIZE"]=sol::var(std::ref(cocos2d::Renderer::INDEX_VBO_SIZE));
mt["BATCH_TRIAGCOMMAND_RESERVED_SIZE"]=sol::var(std::ref(cocos2d::Renderer::BATCH_TRIAGCOMMAND_RESERVED_SIZE));
mt["MATERIAL_ID_DO_NOT_BATCH"]=sol::var(std::ref(cocos2d::Renderer::MATERIAL_ID_DO_NOT_BATCH));
}
