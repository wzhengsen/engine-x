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
void RegisterLuaCorePointLightAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::PointLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("PointLight",false);
ns["PointLight"] = mt;
lua["PointLight"] = sol::nil;
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getLightType));
mt.set_function("getRange",static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange));
mt.set_function("setRange",static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create));
}
void RegisterLuaCoreSpotLightAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::SpotLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("SpotLight",false);
ns["SpotLight"] = mt;
lua["SpotLight"] = sol::nil;
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getLightType));
mt.set_function("setDirection",static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection));
mt.set_function("getDirection",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection));
mt.set_function("getDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld));
mt.set_function("setRange",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange));
mt.set_function("getRange",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange));
mt.set_function("setInnerAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle));
mt.set_function("getInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle));
mt.set_function("getCosInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle));
mt.set_function("setOuterAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle));
mt.set_function("getOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle));
mt.set_function("getCosOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create));
}
void RegisterLuaCoreAmbientLightAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::AmbientLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("AmbientLight",false);
ns["AmbientLight"] = mt;
lua["AmbientLight"] = sol::nil;
mt.set_function("getLightType",static_cast<cocos2d::LightType(cocos2d::AmbientLight::*)()const>(&cocos2d::AmbientLight::getLightType));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::AmbientLight*(*)(const cocos2d::Color3B&)>(&cocos2d::AmbientLight::create));
}
void RegisterLuaCoreRenderStateStateBlockAnonymousEnum_4930690030536856272_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["RenderState"];
pTable = pTable["StateBlock"];
pTable["RS_BLEND"] = 1;
pTable["RS_BLEND_FUNC"] = 2;
pTable["RS_CULL_FACE"] = 4;
pTable["RS_DEPTH_TEST"] = 8;
pTable["RS_DEPTH_WRITE"] = 16;
pTable["RS_DEPTH_FUNC"] = 32;
pTable["RS_CULL_FACE_SIDE"] = 64;
pTable["RS_FRONT_FACE"] = 2048;
pTable["RS_ALL_ONES"] = 4294967295;
}
void RegisterLuaCoreRenderStateStateBlockAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::RenderState::StateBlock>("StateBlock",true);
ns = ns["RenderState"];
ns["StateBlock"] = mt;
lua["StateBlock"] = sol::nil;
mt.set_function("bind",static_cast<void(cocos2d::RenderState::StateBlock::*)(cocos2d::PipelineDescriptor*)>(&cocos2d::RenderState::StateBlock::bind));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::RenderState::StateBlock::*)(const cocos2d::BlendFunc&)>(&cocos2d::RenderState::StateBlock::setBlendFunc));
mt.set_function("setBlend",static_cast<void(cocos2d::RenderState::StateBlock::*)(bool)>(&cocos2d::RenderState::StateBlock::setBlend));
mt.set_function("setBlendSrc",static_cast<void(cocos2d::RenderState::StateBlock::*)(cocos2d::backend::BlendFactor)>(&cocos2d::RenderState::StateBlock::setBlendSrc));
mt.set_function("setBlendDst",static_cast<void(cocos2d::RenderState::StateBlock::*)(cocos2d::backend::BlendFactor)>(&cocos2d::RenderState::StateBlock::setBlendDst));
mt.set_function("setCullFace",static_cast<void(cocos2d::RenderState::StateBlock::*)(bool)>(&cocos2d::RenderState::StateBlock::setCullFace));
mt.set_function("setCullFaceSide",static_cast<void(cocos2d::RenderState::StateBlock::*)(cocos2d::CullFaceSide)>(&cocos2d::RenderState::StateBlock::setCullFaceSide));
mt.set_function("setFrontFace",static_cast<void(cocos2d::RenderState::StateBlock::*)(cocos2d::FrontFace)>(&cocos2d::RenderState::StateBlock::setFrontFace));
mt.set_function("setDepthTest",static_cast<void(cocos2d::RenderState::StateBlock::*)(bool)>(&cocos2d::RenderState::StateBlock::setDepthTest));
mt.set_function("setDepthWrite",static_cast<void(cocos2d::RenderState::StateBlock::*)(bool)>(&cocos2d::RenderState::StateBlock::setDepthWrite));
mt.set_function("setDepthFunction",static_cast<void(cocos2d::RenderState::StateBlock::*)(cocos2d::DepthFunction)>(&cocos2d::RenderState::StateBlock::setDepthFunction));
mt.set_function("setState",static_cast<void(cocos2d::RenderState::StateBlock::*)(const std::string&,const std::string&)>(&cocos2d::RenderState::StateBlock::setState));
mt.set_function("getHash",static_cast<uint32_t(cocos2d::RenderState::StateBlock::*)()const>(&cocos2d::RenderState::StateBlock::getHash));
mt.set_function("isDirty",static_cast<bool(cocos2d::RenderState::StateBlock::*)()const>(&cocos2d::RenderState::StateBlock::isDirty));
RegisterLuaCoreRenderStateStateBlockAnonymousEnum_4930690030536856272_Auto(lua);
}
void RegisterLuaCoreRenderStateAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::RenderState,cocos2d::Ref,cocos2d::LuaObject>("RenderState",true);
ns["RenderState"] = mt;
lua["RenderState"] = sol::nil;
mt.set_function("getName",static_cast<std::string(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getName));
mt.set_function("bindPass",static_cast<void(cocos2d::RenderState::*)(cocos2d::Pass*,cocos2d::MeshCommand*)>(&cocos2d::RenderState::bindPass));
mt.set_function("getStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getStateBlock));
RegisterLuaCoreRenderStateStateBlockAuto(lua);
}
void RegisterLuaCoreTechniqueAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Technique,cocos2d::Ref,cocos2d::LuaObject>("Technique",false);
ns["Technique"] = mt;
lua["Technique"] = sol::nil;
mt.set_function("addPass",static_cast<void(cocos2d::Technique::*)(cocos2d::Pass*)>(&cocos2d::Technique::addPass));
mt.set_function("getName",static_cast<std::string(cocos2d::Technique::*)()const>(&cocos2d::Technique::getName));
mt.set_function("getPassByIndex",static_cast<cocos2d::Pass*(cocos2d::Technique::*)(ssize_t)const>(&cocos2d::Technique::getPassByIndex));
mt.set_function("getPassCount",static_cast<ssize_t(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPassCount));
mt.set_function("getPasses",static_cast<const cocos2d::Vector<cocos2d::Pass *>&(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPasses));
mt.set_function("clone",static_cast<cocos2d::Technique*(cocos2d::Technique::*)()const>(&cocos2d::Technique::clone));
mt.set_function("setMaterial",static_cast<void(cocos2d::Technique::*)(cocos2d::Material*)>(&cocos2d::Technique::setMaterial));
mt.set_function("getStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Technique::*)()>(&cocos2d::Technique::getStateBlock));
mt.set_function("createWithProgramState",static_cast<cocos2d::Technique*(*)(cocos2d::Material*,cocos2d::backend::ProgramState*)>(&cocos2d::Technique::createWithProgramState));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Technique*(*)(cocos2d::Material*)>(&cocos2d::Technique::create));
}
void RegisterLuaCoreMaterialAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("Material",true);
ns["Material"] = mt;
lua["Material"] = sol::nil;
mt.set_function("draw",static_cast<void(cocos2d::Material::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::CustomCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Material::draw));
mt.set_function("getName",static_cast<std::string(cocos2d::Material::*)()const>(&cocos2d::Material::getName));
mt.set_function("setName",static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setName));
mt.set_function("getTechniqueByName",static_cast<cocos2d::Technique*(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::getTechniqueByName));
mt.set_function("getTechniqueByIndex",static_cast<cocos2d::Technique*(cocos2d::Material::*)(ssize_t)>(&cocos2d::Material::getTechniqueByIndex));
mt.set_function("getTechnique",static_cast<cocos2d::Technique*(cocos2d::Material::*)()const>(&cocos2d::Material::getTechnique));
mt.set_function("getTechniques",static_cast<const cocos2d::Vector<cocos2d::Technique *>&(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniques));
mt.set_function("getTechniqueCount",static_cast<ssize_t(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniqueCount));
mt.set_function("addTechnique",static_cast<void(cocos2d::Material::*)(cocos2d::Technique*)>(&cocos2d::Material::addTechnique));
mt.set_function("setTechnique",static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setTechnique));
mt.set_function("clone",static_cast<cocos2d::Material*(cocos2d::Material::*)()const>(&cocos2d::Material::clone));
mt.set_function("getStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Material::*)()>(&cocos2d::Material::getStateBlock));
mt.set_function("setStateBlock",static_cast<void(cocos2d::Material::*)(const cocos2d::RenderState::StateBlock&)>(&cocos2d::Material::setStateBlock));
mt.set_function("getRenderState",static_cast<cocos2d::RenderState*(cocos2d::Material::*)()>(&cocos2d::Material::getRenderState));
mt.set_function("createWithFilename",static_cast<cocos2d::Material*(*)(const std::string&)>(&cocos2d::Material::createWithFilename));
mt.set_function("createWithProgramState",static_cast<cocos2d::Material*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Material::createWithProgramState));
mt.set_function("createWithProperties",static_cast<cocos2d::Material*(*)(cocos2d::Properties*)>(&cocos2d::Material::createWithProperties));
}
void RegisterLuaCorePassAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Pass,cocos2d::Ref,cocos2d::LuaObject>("Pass",false);
ns["Pass"] = mt;
lua["Pass"] = sol::nil;
mt.set_function("getProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getProgramState));
mt.set_function("draw",static_cast<void(cocos2d::Pass::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::MeshCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Pass::draw));
mt.set_function("setVertexAttribBinding",static_cast<void(cocos2d::Pass::*)(cocos2d::VertexAttribBinding*)>(&cocos2d::Pass::setVertexAttribBinding));
mt.set_function("getVertexAttributeBinding",static_cast<cocos2d::VertexAttribBinding*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getVertexAttributeBinding));
mt.set_function("setName",static_cast<void(cocos2d::Pass::*)(const std::string&)>(&cocos2d::Pass::setName));
mt.set_function("getName",static_cast<const std::string&(cocos2d::Pass::*)()const>(&cocos2d::Pass::getName));
mt.set_function("getStateBlock",static_cast<cocos2d::RenderState::StateBlock&(cocos2d::Pass::*)()>(&cocos2d::Pass::getStateBlock));
mt.set_function("clone",static_cast<cocos2d::Pass*(cocos2d::Pass::*)()const>(&cocos2d::Pass::clone));
mt.set_function("setTechnique",static_cast<void(cocos2d::Pass::*)(cocos2d::Technique*)>(&cocos2d::Pass::setTechnique));
mt.set_function("updateMVPUniform",static_cast<void(cocos2d::Pass::*)(const cocos2d::Mat4&)>(&cocos2d::Pass::updateMVPUniform));
mt.set_function("setUniformTexture",static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformTexture));
mt.set_function("setUniformNormTexture",static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformNormTexture));
mt.set_function("setUniformColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformColor));
mt.set_function("setUniformMatrixPalette",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformMatrixPalette));
mt.set_function("setUniformDirLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightColor));
mt.set_function("setUniformDirLightDir",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightDir));
mt.set_function("setUniformPointLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightColor));
mt.set_function("setUniformPointLightPosition",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightPosition));
mt.set_function("setUniformPointLightRangeInverse",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightRangeInverse));
mt.set_function("setUniformSpotLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightColor));
mt.set_function("setUniformSpotLightPosition",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightPosition));
mt.set_function("setUniformSpotLightDir",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightDir));
mt.set_function("setUniformSpotLightInnerAngleCos",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightInnerAngleCos));
mt.set_function("setUniformSpotLightOuterAngleCos",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightOuterAngleCos));
mt.set_function("setUniformSpotLightRangeInverse",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightRangeInverse));
mt.set_function("setUniformAmbientLigthColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformAmbientLigthColor));
mt.set_function("createWithProgramState",static_cast<cocos2d::Pass*(*)(cocos2d::Technique*,cocos2d::backend::ProgramState*)>(&cocos2d::Pass::createWithProgramState));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Pass*(*)(cocos2d::Technique*)>(&cocos2d::Pass::create));
}
void RegisterLuaCoreRendererAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Renderer>("Renderer",true);
ns["Renderer"] = mt;
lua["Renderer"] = sol::nil;
mt.set_function("init",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::init));
mt.set_function("addCommand",sol::overload(static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*,int)>(&cocos2d::Renderer::addCommand),static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*)>(&cocos2d::Renderer::addCommand)));
mt.set_function("pushGroup",static_cast<void(cocos2d::Renderer::*)(int)>(&cocos2d::Renderer::pushGroup));
mt.set_function("popGroup",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::popGroup));
mt.set_function("createRenderQueue",static_cast<int(cocos2d::Renderer::*)()>(&cocos2d::Renderer::createRenderQueue));
mt.set_function("render",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::render));
mt.set_function("clean",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clean));
mt.set_function("getDrawnBatches",static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnBatches));
mt.set_function("addDrawnBatches",static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnBatches));
mt.set_function("getDrawnVertices",static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnVertices));
mt.set_function("addDrawnVertices",static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnVertices));
mt.set_function("clearDrawStats",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clearDrawStats));
mt.set_function("getRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTarget));
mt.set_function("setRenderTarget",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*)>(&cocos2d::Renderer::setRenderTarget));
mt.set_function("getDefaultRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDefaultRenderTarget));
mt.set_function("clear",static_cast<void(cocos2d::Renderer::*)(cocos2d::ClearFlag,const cocos2d::Color4F&,float,unsigned int,float)>(&cocos2d::Renderer::clear));
mt.set_function("getClearColor",static_cast<const cocos2d::Color4F&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearColor));
mt.set_function("getClearDepth",static_cast<float(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearDepth));
mt.set_function("getClearStencil",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearStencil));
mt.set_function("getClearFlag",static_cast<cocos2d::ClearFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearFlag));
mt.set_function("getRenderTargetFlag",static_cast<cocos2d::RenderTargetFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTargetFlag));
mt.set_function("setDepthTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthTest));
mt.set_function("setDepthWrite",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthWrite));
mt.set_function("setDepthCompareFunction",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction)>(&cocos2d::Renderer::setDepthCompareFunction));
mt.set_function("getDepthTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthTest));
mt.set_function("getDepthWrite",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthWrite));
mt.set_function("getDepthCompareFunction",static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthCompareFunction));
mt.set_function("setStencilTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setStencilTest));
mt.set_function("setStencilCompareFunction",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction,unsigned int,unsigned int)>(&cocos2d::Renderer::setStencilCompareFunction));
mt.set_function("setStencilOperation",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation)>(&cocos2d::Renderer::setStencilOperation));
mt.set_function("setStencilWriteMask",static_cast<void(cocos2d::Renderer::*)(unsigned int)>(&cocos2d::Renderer::setStencilWriteMask));
mt.set_function("getStencilTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilTest));
mt.set_function("getStencilFailureOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilFailureOperation));
mt.set_function("getStencilPassDepthFailureOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilPassDepthFailureOperation));
mt.set_function("getStencilDepthPassOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilDepthPassOperation));
mt.set_function("getStencilCompareFunction",static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilCompareFunction));
mt.set_function("getStencilReadMask",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReadMask));
mt.set_function("getStencilWriteMask",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilWriteMask));
mt.set_function("getStencilReferenceValue",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReferenceValue));
mt.set_function("setDepthStencilDesc",static_cast<void(cocos2d::Renderer::*)(const cocos2d::backend::DepthStencilDescriptor&)>(&cocos2d::Renderer::setDepthStencilDesc));
mt.set_function("getDepthStencilDesc",static_cast<const cocos2d::backend::DepthStencilDescriptor&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthStencilDesc));
mt.set_function("setCullMode",static_cast<void(cocos2d::Renderer::*)(cocos2d::CullMode)>(&cocos2d::Renderer::setCullMode));
mt.set_function("getCullMode",static_cast<cocos2d::CullMode(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getCullMode));
mt.set_function("setWinding",static_cast<void(cocos2d::Renderer::*)(cocos2d::Winding)>(&cocos2d::Renderer::setWinding));
mt.set_function("getWinding",static_cast<cocos2d::Winding(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getWinding));
mt.set_function("setViewPort",static_cast<void(cocos2d::Renderer::*)(int,int,unsigned int,unsigned int)>(&cocos2d::Renderer::setViewPort));
mt.set_function("getViewport",static_cast<const cocos2d::Viewport&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getViewport));
mt.set_function("setScissorTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setScissorTest));
mt.set_function("setScissorRect",static_cast<void(cocos2d::Renderer::*)(float,float,float,float)>(&cocos2d::Renderer::setScissorRect));
mt.set_function("getScissorTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorTest));
mt.set_function("getScissorRect",static_cast<const cocos2d::ScissorRect&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorRect));
mt.set_function("checkVisibility",static_cast<bool(cocos2d::Renderer::*)(const cocos2d::Mat4&,const cocos2d::Size&)>(&cocos2d::Renderer::checkVisibility));
mt.set_function("readPixels",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*,std::function<void (const cocos2d::backend::PixelBufferDescriptor &)>)>(&cocos2d::Renderer::readPixels));
}
void RegisterLuaCoreTextureCacheAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TextureCache,cocos2d::Ref,cocos2d::LuaObject>("TextureCache",true);
ns["TextureCache"] = mt;
lua["TextureCache"] = sol::nil;
mt.set_function("getDescription",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getDescription));
mt.set_function("addImage",sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(cocos2d::Image*,const std::string&)>(&cocos2d::TextureCache::addImage),static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::addImage)));
mt.set_function("addImageAsync",sol::overload(static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&,const std::string&)>(&cocos2d::TextureCache::addImageAsync),static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&)>(&cocos2d::TextureCache::addImageAsync)));
mt.set_function("unbindImageAsync",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::unbindImageAsync));
mt.set_function("unbindAllImageAsync",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::unbindAllImageAsync));
mt.set_function("getTextureForKey",static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)const>(&cocos2d::TextureCache::getTextureForKey));
mt.set_function("reloadTexture",static_cast<bool(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::reloadTexture));
mt.set_function("removeAllTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeAllTextures));
mt.set_function("removeUnusedTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeUnusedTextures));
mt.set_function("removeTexture",static_cast<void(cocos2d::TextureCache::*)(cocos2d::Texture2D*)>(&cocos2d::TextureCache::removeTexture));
mt.set_function("removeTextureForKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::removeTextureForKey));
mt.set_function("getCachedTextureInfo",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getCachedTextureInfo));
mt.set_function("waitForQuit",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::waitForQuit));
mt.set_function("getTextureFilePath",static_cast<std::string(cocos2d::TextureCache::*)(cocos2d::Texture2D*)const>(&cocos2d::TextureCache::getTextureFilePath));
mt.set_function("renameTextureWithKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::string&)>(&cocos2d::TextureCache::renameTextureWithKey));
mt.set_function("setETC1AlphaFileSuffix",static_cast<void(*)(const std::string&)>(&cocos2d::TextureCache::setETC1AlphaFileSuffix));
mt.set_function("getETC1AlphaFileSuffix",static_cast<std::string(*)()>(&cocos2d::TextureCache::getETC1AlphaFileSuffix));
}
void RegisterLuaCoreDeviceTextAlignAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Device"];
pTable.new_enum("TextAlign"
,"CENTER",51
,"TOP",19
,"TOP_RIGHT",18
,"RIGHT",50
,"BOTTOM_RIGHT",34
,"BOTTOM",35
,"BOTTOM_LEFT",33
,"LEFT",49
,"TOP_LEFT",17
);}
void RegisterLuaCoreDeviceAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Device>("Device",true);
ns["Device"] = mt;
lua["Device"] = sol::nil;
mt.set_function("getDPI",static_cast<int(*)()>(&cocos2d::Device::getDPI));
mt.set_function("setAccelerometerEnabled",static_cast<void(*)(bool)>(&cocos2d::Device::setAccelerometerEnabled));
mt.set_function("setAccelerometerInterval",static_cast<void(*)(float)>(&cocos2d::Device::setAccelerometerInterval));
mt.set_function("setKeepScreenOn",static_cast<void(*)(bool)>(&cocos2d::Device::setKeepScreenOn));
mt.set_function("vibrate",static_cast<void(*)(float)>(&cocos2d::Device::vibrate));
RegisterLuaCoreDeviceTextAlignAuto(lua);
}
