#include "scripting/lua-bindings/auto/CCRegisterLuaBackendAuto.hpp"
#include "renderer/backend/Types.h"
#include "renderer/backend/ProgramState.h"
#include "renderer/backend/Texture.h"
#include "renderer/backend/VertexLayout.h"
#include "renderer/backend/Device.h"
#include "renderer/backend/RenderTarget.h"
#include "renderer/backend/CommandBuffer.h"
#include "renderer/backend/Buffer.h"
#include "renderer/backend/RenderPipeline.h"
void RegisterLuaBackendProgramAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Program,cocos2d::Ref,cocos2d::LuaObject>("ccb","Program");
mt.set_function("getUniformLocation",sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::Program::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getUniformLocation)));
mt.set_function("getAttributeLocation",sol::overload(static_cast<int(cocos2d::backend::Program::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::Program::getAttributeLocation),static_cast<int(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getAttributeLocation)));
mt.set_function("getMaxVertexLocation",static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxVertexLocation));
mt.set_function("getMaxFragmentLocation",static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxFragmentLocation));
mt.set_function("getActiveAttributes",static_cast<const std::unordered_map<std::string, cocos2d::backend::AttributeBindInfo>(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getActiveAttributes));
mt.set_function("getVertexShader",static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getVertexShader));
mt.set_function("getFragmentShader",static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getFragmentShader));
mt.set_function("getProgramType",static_cast<uint32_t(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getProgramType));
mt.set_function("getUniformBufferSize",static_cast<size_t(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getUniformBufferSize));
mt.set_function("getActiveUniformInfo",static_cast<const cocos2d::backend::UniformInfo&(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage,int)const>(&cocos2d::backend::Program::getActiveUniformInfo));
mt.set_function("getAllActiveUniformInfo",static_cast<const std::unordered_map<std::string, cocos2d::backend::UniformInfo>&(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getAllActiveUniformInfo));
mt.set_function("setProgramType",static_cast<void(cocos2d::backend::Program::*)(uint32_t)>(&cocos2d::backend::Program::setProgramType));
mt.set_function("getBuiltinProgram",static_cast<cocos2d::backend::Program*(*)(uint32_t)>(&cocos2d::backend::Program::getBuiltinProgram));
}
void RegisterLuaBackendVertexLayoutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::VertexLayout>("ccb","VertexLayout");
mt.set_function("setAttribute",static_cast<void(cocos2d::backend::VertexLayout::*)(const std::string&,size_t,cocos2d::backend::VertexFormat,size_t,bool)>(&cocos2d::backend::VertexLayout::setAttribute));
mt.set_function("setLayout",static_cast<void(cocos2d::backend::VertexLayout::*)(size_t)>(&cocos2d::backend::VertexLayout::setLayout));
mt.set_function("getStride",static_cast<size_t(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getStride));
mt.set_function("getVertexStepMode",static_cast<cocos2d::backend::VertexStepMode(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getVertexStepMode));
mt.set_function("getAttributes",static_cast<const std::unordered_map<std::string, cocos2d::backend::VertexLayout::Attribute>&(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getAttributes));
mt.set_function("isValid",static_cast<bool(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::isValid));
}
void RegisterLuaBackendProgramStateAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::ProgramState,cocos2d::Ref,cocos2d::LuaObject>("ccb","ProgramState");
mt.set_function("clone",static_cast<cocos2d::backend::ProgramState*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::clone));
mt.set_function("getProgram",static_cast<cocos2d::backend::Program*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getProgram));
mt.set_function("setUniform",static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,const void*,size_t)>(&cocos2d::backend::ProgramState::setUniform));
mt.set_function("getUniformLocation",sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::ProgramState::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::ProgramState::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getUniformLocation)));
mt.set_function("getAttributeLocation",sol::overload(static_cast<int(cocos2d::backend::ProgramState::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::ProgramState::getAttributeLocation),static_cast<int(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getAttributeLocation)));
mt.set_function("setCallbackUniform",static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,const std::function<void (cocos2d::backend::ProgramState *, const cocos2d::backend::UniformLocation &)>&)>(&cocos2d::backend::ProgramState::setCallbackUniform));
mt.set_function("setTexture",sol::overload(static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture)));
mt.set_function("setTextureArray",static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,std::vector<unsigned short>,std::vector<cocos2d::backend::TextureBackend *>)>(&cocos2d::backend::ProgramState::setTextureArray));
mt.set_function("getVertexTextureInfos",static_cast<const std::unordered_map<int, cocos2d::backend::TextureInfo>&(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getVertexTextureInfos));
mt.set_function("getFragmentTextureInfos",static_cast<const std::unordered_map<int, cocos2d::backend::TextureInfo>&(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getFragmentTextureInfos));
mt.set_function("setParameterAutoBinding",static_cast<void(cocos2d::backend::ProgramState::*)(const std::string&,const std::string&)>(&cocos2d::backend::ProgramState::setParameterAutoBinding));
mt.set_function("getVertexLayout",static_cast<std::shared_ptr<cocos2d::backend::VertexLayout>(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getVertexLayout));
mt.set_function("getUniformID",static_cast<uint32_t(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getUniformID));
mt.set_function("updateUniformID",sol::overload([](cocos2d::backend::ProgramState* obj){return obj->updateUniformID();},[](cocos2d::backend::ProgramState* obj,int arg0){return obj->updateUniformID(arg0);}));
}
void RegisterLuaBackendTextureBackendAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::LuaObject>("ccb","TextureBackend");
mt.set_function("updateSamplerDescriptor",static_cast<void(cocos2d::backend::TextureBackend::*)(const cocos2d::backend::SamplerDescriptor&)>(&cocos2d::backend::TextureBackend::updateSamplerDescriptor));
mt.set_function("generateMipmaps",static_cast<void(cocos2d::backend::TextureBackend::*)()>(&cocos2d::backend::TextureBackend::generateMipmaps));
mt.set_function("updateTextureDescriptor",sol::overload([](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0,int arg1){return obj->updateTextureDescriptor(arg0,arg1);}));
mt.set_function("getTextureFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureFormat));
mt.set_function("getTextureUsage",static_cast<cocos2d::backend::TextureUsage(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureUsage));
mt.set_function("getTextureType",static_cast<cocos2d::backend::TextureType(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureType));
mt.set_function("hasMipmaps",static_cast<bool(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::hasMipmaps));
mt.set_function("getCount",static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getCount));
mt.set_function("getHandler",sol::overload([](cocos2d::backend::TextureBackend* obj){return obj->getHandler();},[](cocos2d::backend::TextureBackend* obj,int arg0){return obj->getHandler(arg0);}));
mt.set_function("getWidth",static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getWidth));
mt.set_function("getHeight",static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getHeight));
}
void RegisterLuaBackendTexture2DBackendAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Texture2DBackend,cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::LuaObject>("ccb","Texture2DBackend");
mt.set_function("updateData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3){return obj->updateData(arg0,arg1,arg2,arg3);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,int arg4){return obj->updateData(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("updateCompressedData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,int arg5){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("updateSubData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5,int arg6){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("updateCompressedSubData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6,int arg7){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}));
mt.set_function("getWidth",static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getWidth));
mt.set_function("getHeight",static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getHeight));
}
void RegisterLuaBackendTextureCubemapBackendAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::TextureCubemapBackend,cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::LuaObject>("ccb","TextureCubemapBackend");
mt.set_function("updateFaceData",sol::overload([](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1){return obj->updateFaceData(arg0,arg1);},[](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1,int arg2){return obj->updateFaceData(arg0,arg1,arg2);}));
}
void RegisterLuaBackendDeviceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Device,cocos2d::Ref,cocos2d::LuaObject>("ccb","Device");
mt.set_function("newCommandBuffer",static_cast<cocos2d::backend::CommandBuffer*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newCommandBuffer));
mt.set_function("newBuffer",static_cast<cocos2d::backend::Buffer*(cocos2d::backend::Device::*)(size_t,cocos2d::backend::BufferType,cocos2d::backend::BufferUsage)>(&cocos2d::backend::Device::newBuffer));
mt.set_function("newTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::backend::Device::*)(const cocos2d::backend::TextureDescriptor&)>(&cocos2d::backend::Device::newTexture));
mt.set_function("newDefaultRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::backend::Device::*)(cocos2d::backend::TargetBufferFlags)>(&cocos2d::backend::Device::newDefaultRenderTarget));
mt.set_function("newRenderTarget",sol::overload([](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0){return obj->newRenderTarget(arg0);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1){return obj->newRenderTarget(arg0,arg1);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2){return obj->newRenderTarget(arg0,arg1,arg2);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2,cocos2d::backend::TextureBackend* arg3){return obj->newRenderTarget(arg0,arg1,arg2,arg3);}));
mt.set_function("newDepthStencilState",static_cast<cocos2d::backend::DepthStencilState*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newDepthStencilState));
mt.set_function("newRenderPipeline",static_cast<cocos2d::backend::RenderPipeline*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newRenderPipeline));
mt.set_function("setFrameBufferOnly",static_cast<void(cocos2d::backend::Device::*)(bool)>(&cocos2d::backend::Device::setFrameBufferOnly));
mt.set_function("newProgram",static_cast<cocos2d::backend::Program*(cocos2d::backend::Device::*)(const std::string&,const std::string&)>(&cocos2d::backend::Device::newProgram));
mt.set_function("getDeviceInfo",static_cast<cocos2d::backend::DeviceInfo*(cocos2d::backend::Device::*)()const>(&cocos2d::backend::Device::getDeviceInfo));
mt.set_function("getInstance",static_cast<cocos2d::backend::Device*(*)()>(&cocos2d::backend::Device::getInstance));
}
