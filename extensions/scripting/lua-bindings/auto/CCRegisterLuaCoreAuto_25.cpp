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
void RegisterLuaCoreTextureCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TextureCache>("cc","TextureCache",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetETC1AlphaFileSuffix",static_cast<void(*)(const std::string&)>(&cocos2d::TextureCache::setETC1AlphaFileSuffix));
mt.set_function("GetETC1AlphaFileSuffix",static_cast<std::string(*)()>(&cocos2d::TextureCache::getETC1AlphaFileSuffix));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getDescription));
mt.set_function("AddImage",sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(cocos2d::Image*,const std::string&)>(&cocos2d::TextureCache::addImage),static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::addImage)));
mt.set_function("AddImageAsync",sol::overload(static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&,const std::string&)>(&cocos2d::TextureCache::addImageAsync),static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&)>(&cocos2d::TextureCache::addImageAsync)));
mt.set_function("UnbindImageAsync",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::unbindImageAsync));
mt.set_function("UnbindAllImageAsync",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::unbindAllImageAsync));
mt.set_function("GetTextureForKey",static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)const>(&cocos2d::TextureCache::getTextureForKey));
mt.set_function("ReloadTexture",static_cast<bool(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::reloadTexture));
mt.set_function("RemoveAllTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeAllTextures));
mt.set_function("RemoveUnusedTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeUnusedTextures));
mt.set_function("RemoveTexture",static_cast<void(cocos2d::TextureCache::*)(cocos2d::Texture2D*)>(&cocos2d::TextureCache::removeTexture));
mt.set_function("RemoveTextureForKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::removeTextureForKey));
mt.set_function("GetCachedTextureInfo",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getCachedTextureInfo));
mt.set_function("WaitForQuit",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::waitForQuit));
mt.set_function("GetTextureFilePath",static_cast<std::string(cocos2d::TextureCache::*)(cocos2d::Texture2D*)const>(&cocos2d::TextureCache::getTextureFilePath));
mt.set_function("RenameTextureWithKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::string&)>(&cocos2d::TextureCache::renameTextureWithKey));
mt[sol::call_constructor]=sol::constructors<cocos2d::TextureCache()>();
}
void RegisterLuaCoreDeviceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Device>("cc","Device",true);
mt.set_function("GetDPI",static_cast<int(*)()>(&cocos2d::Device::getDPI));
mt.set_function("SetAccelerometerEnabled",static_cast<void(*)(bool)>(&cocos2d::Device::setAccelerometerEnabled));
mt.set_function("SetAccelerometerInterval",static_cast<void(*)(float)>(&cocos2d::Device::setAccelerometerInterval));
mt.set_function("SetKeepScreenOn",static_cast<void(*)(bool)>(&cocos2d::Device::setKeepScreenOn));
mt.set_function("Vibrate",static_cast<void(*)(float)>(&cocos2d::Device::vibrate));
}
void RegisterLuaCoreApplicationProtocolPlatformAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["ApplicationProtocol"];
pTable.new_enum<cocos2d::ApplicationProtocol::Platform>("Platform",{
{"OS_WINDOWS",cocos2d::ApplicationProtocol::Platform::OS_WINDOWS}
,{"OS_LINUX",cocos2d::ApplicationProtocol::Platform::OS_LINUX}
,{"OS_MAC",cocos2d::ApplicationProtocol::Platform::OS_MAC}
,{"OS_ANDROID",cocos2d::ApplicationProtocol::Platform::OS_ANDROID}
,{"OS_IPHONE",cocos2d::ApplicationProtocol::Platform::OS_IPHONE}
,{"OS_IPAD",cocos2d::ApplicationProtocol::Platform::OS_IPAD}
});}
void RegisterLuaCoreApplicationProtocolAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ApplicationProtocol>("cc","ApplicationProtocol",true);
mt.set_function("ApplicationDidFinishLaunching",static_cast<bool(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::applicationDidFinishLaunching));
mt.set_function("ApplicationDidEnterBackground",static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::applicationDidEnterBackground));
mt.set_function("ApplicationWillEnterForeground",static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::applicationWillEnterForeground));
mt.set_function("SetAnimationInterval",static_cast<void(cocos2d::ApplicationProtocol::*)(float)>(&cocos2d::ApplicationProtocol::setAnimationInterval));
mt.set_function("InitGLContextAttrs",static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::initGLContextAttrs));
mt.set_function("GetCurrentLanguage",static_cast<cocos2d::LanguageType(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getCurrentLanguage));
mt.set_function("GetCurrentLanguageCode",static_cast<const char*(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getCurrentLanguageCode));
mt.set_function("GetTargetPlatform",static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getTargetPlatform));
mt.set_function("GetVersion",static_cast<std::string(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getVersion));
mt.set_function("GetCompileVersion",static_cast<int64_t(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::GetCompileVersion));
mt.set_function("OpenURL",static_cast<bool(cocos2d::ApplicationProtocol::*)(const std::string&)>(&cocos2d::ApplicationProtocol::openURL));
mt.set_function("RestartLuaEngine",static_cast<bool(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::RestartLuaEngine));
mt.set_function("Dialog",sol::overload([](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1){return obj->Dialog(arg0,arg1);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2){return obj->Dialog(arg0,arg1,arg2);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2,const std::function<void ()>& arg3){return obj->Dialog(arg0,arg1,arg2,arg3);}));
mt.set_function("Notify",sol::overload([](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1){return obj->Notify(arg0,arg1);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2){return obj->Notify(arg0,arg1,arg2);}));
RegisterLuaCoreApplicationProtocolPlatformAuto(lua);
}
void RegisterLuaCoreApplicationAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Application>("cc","Application",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ApplicationProtocol>());
mt.set_function("SetAnimationInterval",static_cast<void(cocos2d::Application::*)(float)>(&cocos2d::Application::setAnimationInterval));
mt.set_function("Run",static_cast<int(cocos2d::Application::*)()>(&cocos2d::Application::run));
mt.set_function("GetInstance",static_cast<cocos2d::Application*(*)()>(&cocos2d::Application::getInstance));
mt.set_function("GetCurrentLanguage",static_cast<cocos2d::LanguageType(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguage));
mt.set_function("GetCurrentLanguageCode",static_cast<const char*(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguageCode));
mt.set_function("GetTargetPlatform",static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::Application::*)()>(&cocos2d::Application::getTargetPlatform));
mt.set_function("GetVersion",static_cast<std::string(cocos2d::Application::*)()>(&cocos2d::Application::getVersion));
mt.set_function("GetCompileVersion",static_cast<int64_t(cocos2d::Application::*)()>(&cocos2d::Application::GetCompileVersion));
mt.set_function("OpenURL",static_cast<bool(cocos2d::Application::*)(const std::string&)>(&cocos2d::Application::openURL));
mt["Instance"]=sol::readonly_property(&cocos2d::Application::getInstance);
}
