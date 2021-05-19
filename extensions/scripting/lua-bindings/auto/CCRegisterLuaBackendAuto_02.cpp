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
void RegisterLuaBackendProgramTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::ProgramType>("ProgramType",{
{"POSITION_COLOR_LENGTH_TEXTURE",cocos2d::backend::ProgramType::POSITION_COLOR_LENGTH_TEXTURE}
,{"POSITION_COLOR_TEXTURE_AS_POINTSIZE",cocos2d::backend::ProgramType::POSITION_COLOR_TEXTURE_AS_POINTSIZE}
,{"POSITION_COLOR",cocos2d::backend::ProgramType::POSITION_COLOR}
,{"POSITION_UCOLOR",cocos2d::backend::ProgramType::POSITION_UCOLOR}
,{"POSITION_TEXTURE",cocos2d::backend::ProgramType::POSITION_TEXTURE}
,{"POSITION_TEXTURE_COLOR",cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR}
,{"POSITION_TEXTURE_COLOR_ALPHA_TEST",cocos2d::backend::ProgramType::POSITION_TEXTURE_COLOR_ALPHA_TEST}
,{"LABEL_NORMAL",cocos2d::backend::ProgramType::LABEL_NORMAL}
,{"LABLE_OUTLINE",cocos2d::backend::ProgramType::LABLE_OUTLINE}
,{"LABLE_DISTANCEFIELD_GLOW",cocos2d::backend::ProgramType::LABLE_DISTANCEFIELD_GLOW}
,{"LABEL_DISTANCE_NORMAL",cocos2d::backend::ProgramType::LABEL_DISTANCE_NORMAL}
,{"LAYER_RADIA_GRADIENT",cocos2d::backend::ProgramType::LAYER_RADIA_GRADIENT}
,{"ETC1",cocos2d::backend::ProgramType::ETC1}
,{"ETC1_GRAY",cocos2d::backend::ProgramType::ETC1_GRAY}
,{"GRAY_SCALE",cocos2d::backend::ProgramType::GRAY_SCALE}
,{"CAMERA_CLEAR",cocos2d::backend::ProgramType::CAMERA_CLEAR}
,{"TERRAIN_3D",cocos2d::backend::ProgramType::TERRAIN_3D}
,{"LINE_COLOR_3D",cocos2d::backend::ProgramType::LINE_COLOR_3D}
,{"SKYBOX_3D",cocos2d::backend::ProgramType::SKYBOX_3D}
,{"SKINPOSITION_TEXTURE_3D",cocos2d::backend::ProgramType::SKINPOSITION_TEXTURE_3D}
,{"SKINPOSITION_NORMAL_TEXTURE_3D",cocos2d::backend::ProgramType::SKINPOSITION_NORMAL_TEXTURE_3D}
,{"POSITION_NORMAL_TEXTURE_3D",cocos2d::backend::ProgramType::POSITION_NORMAL_TEXTURE_3D}
,{"POSITION_NORMAL_3D",cocos2d::backend::ProgramType::POSITION_NORMAL_3D}
,{"POSITION_TEXTURE_3D",cocos2d::backend::ProgramType::POSITION_TEXTURE_3D}
,{"POSITION_3D",cocos2d::backend::ProgramType::POSITION_3D}
,{"POSITION_BUMPEDNORMAL_TEXTURE_3D",cocos2d::backend::ProgramType::POSITION_BUMPEDNORMAL_TEXTURE_3D}
,{"SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D",cocos2d::backend::ProgramType::SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D}
,{"PARTICLE_TEXTURE_3D",cocos2d::backend::ProgramType::PARTICLE_TEXTURE_3D}
,{"PARTICLE_COLOR_3D",cocos2d::backend::ProgramType::PARTICLE_COLOR_3D}
,{"HSV",cocos2d::backend::ProgramType::HSV}
,{"HSV_ETC1",cocos2d::backend::ProgramType::HSV_ETC1}
,{"BUILTIN_COUNT",cocos2d::backend::ProgramType::BUILTIN_COUNT}
,{"CUSTOM_PROGRAM",cocos2d::backend::ProgramType::CUSTOM_PROGRAM}
});}
void RegisterLuaBackendShaderCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::ShaderCache>("ccb","ShaderCache",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocos2d::backend::ShaderCache*(*)()>(&cocos2d::backend::ShaderCache::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::backend::ShaderCache::destroyInstance));
mt.set_function("NewVertexShaderModule",static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newVertexShaderModule));
mt.set_function("NewFragmentShaderModule",static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newFragmentShaderModule));
mt.set_function("RemoveUnusedShader",static_cast<void(cocos2d::backend::ShaderCache::*)()>(&cocos2d::backend::ShaderCache::removeUnusedShader));
mt["Instance"]=sol::property(&cocos2d::backend::ShaderCache::getInstance,[](std::nullptr_t){cocos2d::backend::ShaderCache::destroyInstance();});
}
void RegisterLuaBackendProgramAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Program>("ccb","Program",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetBuiltinProgram",static_cast<cocos2d::backend::Program*(*)(uint32_t)>(&cocos2d::backend::Program::getBuiltinProgram));
mt.set_function("GetUniformLocation",sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::Program::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getUniformLocation)));
mt.set_function("GetAttributeLocation",sol::overload(static_cast<int(cocos2d::backend::Program::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::Program::getAttributeLocation),static_cast<int(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getAttributeLocation)));
mt.set_function("GetMaxVertexLocation",static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxVertexLocation));
mt.set_function("GetMaxFragmentLocation",static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxFragmentLocation));
mt.set_function("GetActiveAttributes",static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::AttributeBindInfo, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::AttributeBindInfo> > >(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getActiveAttributes));
mt.set_function("GetVertexShader",static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getVertexShader));
mt.set_function("GetFragmentShader",static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getFragmentShader));
mt.set_function("GetProgramType",static_cast<uint32_t(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getProgramType));
mt.set_function("GetUniformBufferSize",static_cast<size_t(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getUniformBufferSize));
mt.set_function("GetActiveUniformInfo",static_cast<const cocos2d::backend::UniformInfo&(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage,int)const>(&cocos2d::backend::Program::getActiveUniformInfo));
mt.set_function("GetAllActiveUniformInfo",static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::UniformInfo, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::UniformInfo> > >&(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getAllActiveUniformInfo));
mt.set_function("SetProgramType",static_cast<void(cocos2d::backend::Program::*)(uint32_t)>(&cocos2d::backend::Program::setProgramType));
}
void RegisterLuaBackendVertexLayoutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::VertexLayout>("ccb","VertexLayout",false);
mt.set_function("SetAttribute",static_cast<void(cocos2d::backend::VertexLayout::*)(const std::string&,size_t,cocos2d::backend::VertexFormat,size_t,bool)>(&cocos2d::backend::VertexLayout::setAttribute));
mt.set_function("SetLayout",static_cast<void(cocos2d::backend::VertexLayout::*)(size_t)>(&cocos2d::backend::VertexLayout::setLayout));
mt.set_function("GetStride",static_cast<size_t(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getStride));
mt.set_function("GetVertexStepMode",static_cast<cocos2d::backend::VertexStepMode(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getVertexStepMode));
mt.set_function("GetAttributes",static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::VertexLayout::Attribute, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::VertexLayout::Attribute> > >&(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getAttributes));
mt.set_function("IsValid",static_cast<bool(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::isValid));
mt[sol::call_constructor]=sol::constructors<cocos2d::backend::VertexLayout()>();
}
void RegisterLuaBackendProgramStateAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::ProgramState>("ccb","ProgramState",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Clone",static_cast<cocos2d::backend::ProgramState*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::clone));
mt.set_function("GetProgram",static_cast<cocos2d::backend::Program*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getProgram));
mt.set_function("SetUniform",static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,const void*,size_t)>(&cocos2d::backend::ProgramState::setUniform));
mt.set_function("GetUniformLocation",sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::ProgramState::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::ProgramState::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getUniformLocation)));
mt.set_function("GetAttributeLocation",sol::overload(static_cast<int(cocos2d::backend::ProgramState::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::ProgramState::getAttributeLocation),static_cast<int(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getAttributeLocation)));
mt.set_function("SetCallbackUniform",static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,const cocos2d::backend::ProgramState::UniformCallback&)>(&cocos2d::backend::ProgramState::setCallbackUniform));
mt.set_function("SetTexture",sol::overload(static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture)));
mt.set_function("SetTextureArray",static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,std::vector<unsigned short, std::allocator<unsigned short> >,std::vector<cocos2d::backend::TextureBackend *, std::allocator<cocos2d::backend::TextureBackend *> >)>(&cocos2d::backend::ProgramState::setTextureArray));
mt.set_function("GetVertexTextureInfos",static_cast<const std::unordered_map<int, cocos2d::backend::TextureInfo, std::hash<int>, std::equal_to<int>, std::allocator<std::pair<const int, cocos2d::backend::TextureInfo> > >&(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getVertexTextureInfos));
mt.set_function("GetFragmentTextureInfos",static_cast<const std::unordered_map<int, cocos2d::backend::TextureInfo, std::hash<int>, std::equal_to<int>, std::allocator<std::pair<const int, cocos2d::backend::TextureInfo> > >&(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getFragmentTextureInfos));
mt.set_function("SetParameterAutoBinding",static_cast<void(cocos2d::backend::ProgramState::*)(const std::string&,const std::string&)>(&cocos2d::backend::ProgramState::setParameterAutoBinding));
mt.set_function("GetVertexLayout",static_cast<std::shared_ptr<cocos2d::backend::VertexLayout>(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getVertexLayout));
mt.set_function("GetUniformID",static_cast<uint32_t(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getUniformID));
mt.set_function("UpdateUniformID",sol::overload([](cocos2d::backend::ProgramState* obj){return obj->updateUniformID();},[](cocos2d::backend::ProgramState* obj,int arg0){return obj->updateUniformID(arg0);}));
mt[sol::call_constructor]=sol::constructors<cocos2d::backend::ProgramState(cocos2d::backend::Program*)>();
}
void RegisterLuaBackendTextureBackendAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::TextureBackend>("ccb","TextureBackend",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("UpdateSamplerDescriptor",static_cast<void(cocos2d::backend::TextureBackend::*)(const cocos2d::backend::SamplerDescriptor&)>(&cocos2d::backend::TextureBackend::updateSamplerDescriptor));
mt.set_function("GenerateMipmaps",static_cast<void(cocos2d::backend::TextureBackend::*)()>(&cocos2d::backend::TextureBackend::generateMipmaps));
mt.set_function("UpdateTextureDescriptor",sol::overload([](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0,int arg1){return obj->updateTextureDescriptor(arg0,arg1);}));
mt.set_function("GetTextureFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureFormat));
mt.set_function("GetTextureUsage",static_cast<cocos2d::backend::TextureUsage(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureUsage));
mt.set_function("GetTextureType",static_cast<cocos2d::backend::TextureType(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureType));
mt.set_function("HasMipmaps",static_cast<bool(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::hasMipmaps));
mt.set_function("GetCount",static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getCount));
mt.set_function("GetHandler",sol::overload([](cocos2d::backend::TextureBackend* obj){return obj->getHandler();},[](cocos2d::backend::TextureBackend* obj,int arg0){return obj->getHandler(arg0);}));
mt.set_function("GetWidth",static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getWidth));
mt.set_function("GetHeight",static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getHeight));
}
void RegisterLuaBackendTexture2DBackendAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Texture2DBackend>("ccb","Texture2DBackend",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("UpdateData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3){return obj->updateData(arg0,arg1,arg2,arg3);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,int arg4){return obj->updateData(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("UpdateCompressedData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,int arg5){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("UpdateSubData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5,int arg6){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("UpdateCompressedSubData",sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6,int arg7){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}));
mt.set_function("GetWidth",static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getWidth));
mt.set_function("GetHeight",static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getHeight));
}
void RegisterLuaBackendTextureCubemapBackendAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::TextureCubemapBackend>("ccb","TextureCubemapBackend",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("UpdateFaceData",sol::overload([](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1){return obj->updateFaceData(arg0,arg1);},[](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1,int arg2){return obj->updateFaceData(arg0,arg1,arg2);}));
}
void RegisterLuaBackendDeviceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Device>("ccb","Device",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocos2d::backend::Device*(*)()>(&cocos2d::backend::Device::getInstance));
mt.set_function("NewCommandBuffer",static_cast<cocos2d::backend::CommandBuffer*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newCommandBuffer));
mt.set_function("NewBuffer",static_cast<cocos2d::backend::Buffer*(cocos2d::backend::Device::*)(size_t,cocos2d::backend::BufferType,cocos2d::backend::BufferUsage)>(&cocos2d::backend::Device::newBuffer));
mt.set_function("NewTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::backend::Device::*)(const cocos2d::backend::TextureDescriptor&)>(&cocos2d::backend::Device::newTexture));
mt.set_function("NewDefaultRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::backend::Device::*)(cocos2d::backend::TargetBufferFlags)>(&cocos2d::backend::Device::newDefaultRenderTarget));
mt.set_function("NewRenderTarget",sol::overload([](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0){return obj->newRenderTarget(arg0);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1){return obj->newRenderTarget(arg0,arg1);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2){return obj->newRenderTarget(arg0,arg1,arg2);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2,cocos2d::backend::TextureBackend* arg3){return obj->newRenderTarget(arg0,arg1,arg2,arg3);}));
mt.set_function("NewDepthStencilState",static_cast<cocos2d::backend::DepthStencilState*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newDepthStencilState));
mt.set_function("NewRenderPipeline",static_cast<cocos2d::backend::RenderPipeline*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newRenderPipeline));
mt.set_function("SetFrameBufferOnly",static_cast<void(cocos2d::backend::Device::*)(bool)>(&cocos2d::backend::Device::setFrameBufferOnly));
mt.set_function("NewProgram",static_cast<cocos2d::backend::Program*(cocos2d::backend::Device::*)(const std::string&,const std::string&)>(&cocos2d::backend::Device::newProgram));
mt.set_function("GetDeviceInfo",static_cast<cocos2d::backend::DeviceInfo*(cocos2d::backend::Device::*)()const>(&cocos2d::backend::Device::getDeviceInfo));
mt["Instance"]=sol::readonly_property(&cocos2d::backend::Device::getInstance);
}
