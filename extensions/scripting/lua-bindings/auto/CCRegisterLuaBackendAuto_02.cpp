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
namespace cocos2d{
void RegisterLuaBackendShaderCacheAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::ShaderCache).name()] = sol::usertype_traits<cocos2d::backend::ShaderCache*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::ShaderCache>("deprecated.cocos2d::backend::ShaderCache");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::ShaderCache*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccb"]["ShaderCache"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocos2d::backend::ShaderCache*(*)()>(&cocos2d::backend::ShaderCache::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocos2d::backend::ShaderCache::destroyInstance);
mt["static"]["NewVertexShaderModule"]=static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newVertexShaderModule);
mt["static"]["NewFragmentShaderModule"]=static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newFragmentShaderModule);
mt["RemoveUnusedShader"]=static_cast<void(cocos2d::backend::ShaderCache::*)()>(&cocos2d::backend::ShaderCache::removeUnusedShader);
mt["static"]["get"]["Instance"]=&cocos2d::backend::ShaderCache::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocos2d::backend::ShaderCache::destroyInstance();};
}
void RegisterLuaBackendProgramAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::Program).name()] = sol::usertype_traits<cocos2d::backend::Program*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::Program>("deprecated.cocos2d::backend::Program");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::Program*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccb"]["Program"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetBuiltinProgram"]=static_cast<cocos2d::backend::Program*(*)(uint32_t)>(&cocos2d::backend::Program::getBuiltinProgram);
mt["GetUniformLocation"]=sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::Program::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getUniformLocation));
mt["GetAttributeLocation"]=sol::overload(static_cast<int(cocos2d::backend::Program::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::Program::getAttributeLocation),static_cast<int(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getAttributeLocation));
mt["GetMaxVertexLocation"]=static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxVertexLocation);
mt["get"]["MaxVertexLocation"]=mt["GetMaxVertexLocation"];
mt["GetMaxFragmentLocation"]=static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxFragmentLocation);
mt["get"]["MaxFragmentLocation"]=mt["GetMaxFragmentLocation"];
mt["GetActiveAttributes"]=static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::AttributeBindInfo, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::AttributeBindInfo> > >(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getActiveAttributes);
mt["get"]["ActiveAttributes"]=mt["GetActiveAttributes"];
mt["GetVertexShader"]=static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getVertexShader);
mt["get"]["VertexShader"]=mt["GetVertexShader"];
mt["GetFragmentShader"]=static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getFragmentShader);
mt["get"]["FragmentShader"]=mt["GetFragmentShader"];
mt["GetProgramType"]=static_cast<uint32_t(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getProgramType);
mt["get"]["ProgramType"]=mt["GetProgramType"];
mt["GetUniformBufferSize"]=static_cast<size_t(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getUniformBufferSize);
mt["GetActiveUniformInfo"]=static_cast<const cocos2d::backend::UniformInfo&(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage,int)const>(&cocos2d::backend::Program::getActiveUniformInfo);
mt["GetAllActiveUniformInfo"]=static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::UniformInfo, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::UniformInfo> > >&(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getAllActiveUniformInfo);
mt["SetProgramType"]=static_cast<void(cocos2d::backend::Program::*)(uint32_t)>(&cocos2d::backend::Program::setProgramType);
mt["set"]["ProgramType"]=mt["SetProgramType"];
}
void RegisterLuaBackendVertexLayoutAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::VertexLayout).name()] = sol::usertype_traits<cocos2d::backend::VertexLayout*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::VertexLayout>("deprecated.cocos2d::backend::VertexLayout");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::VertexLayout*>::metatable());
lua["ccb"]["VertexLayout"]=mt;
mt["SetAttribute"]=static_cast<void(cocos2d::backend::VertexLayout::*)(const std::string&,size_t,cocos2d::backend::VertexFormat,size_t,bool)>(&cocos2d::backend::VertexLayout::setAttribute);
mt["SetLayout"]=static_cast<void(cocos2d::backend::VertexLayout::*)(size_t)>(&cocos2d::backend::VertexLayout::setLayout);
mt["set"]["Layout"]=mt["SetLayout"];
mt["GetStride"]=static_cast<size_t(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getStride);
mt["get"]["Stride"]=mt["GetStride"];
mt["GetVertexStepMode"]=static_cast<cocos2d::backend::VertexStepMode(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getVertexStepMode);
mt["get"]["VertexStepMode"]=mt["GetVertexStepMode"];
mt["GetAttributes"]=static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::VertexLayout::Attribute, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, cocos2d::backend::VertexLayout::Attribute> > >&(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getAttributes);
mt["get"]["Attributes"]=mt["GetAttributes"];
mt["IsValid"]=static_cast<bool(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::isValid);
mt["get"]["Valid"]=mt["IsValid"];
}
void RegisterLuaBackendProgramStateAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::ProgramState).name()] = sol::usertype_traits<cocos2d::backend::ProgramState*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::ProgramState>("deprecated.cocos2d::backend::ProgramState");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::ProgramState*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccb"]["ProgramState"]=mt;
mt["__new__"]=[](cocos2d::backend::Program* arg0){return new cocos2d::backend::ProgramState(arg0);};
mt["Clone"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::clone);
mt["GetProgram"]=static_cast<cocos2d::backend::Program*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getProgram);
mt["get"]["Program"]=mt["GetProgram"];
mt["SetUniform"]=static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,const void*,size_t)>(&cocos2d::backend::ProgramState::setUniform);
mt["GetUniformLocation"]=sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::ProgramState::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::ProgramState::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getUniformLocation));
mt["GetAttributeLocation"]=sol::overload(static_cast<int(cocos2d::backend::ProgramState::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::ProgramState::getAttributeLocation),static_cast<int(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getAttributeLocation));
mt["SetCallbackUniform"]=static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,const cocos2d::backend::ProgramState::UniformCallback&)>(&cocos2d::backend::ProgramState::setCallbackUniform);
mt["SetTexture"]=sol::overload(static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture));
mt["set"]["Texture"]=mt["SetTexture"];
mt["SetTextureArray"]=static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,std::vector<unsigned short, std::allocator<unsigned short> >,std::vector<cocos2d::backend::TextureBackend *, std::allocator<cocos2d::backend::TextureBackend *> >)>(&cocos2d::backend::ProgramState::setTextureArray);
mt["GetVertexTextureInfos"]=static_cast<const std::unordered_map<int, cocos2d::backend::TextureInfo, std::hash<int>, std::equal_to<int>, std::allocator<std::pair<const int, cocos2d::backend::TextureInfo> > >&(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getVertexTextureInfos);
mt["get"]["VertexTextureInfos"]=mt["GetVertexTextureInfos"];
mt["GetFragmentTextureInfos"]=static_cast<const std::unordered_map<int, cocos2d::backend::TextureInfo, std::hash<int>, std::equal_to<int>, std::allocator<std::pair<const int, cocos2d::backend::TextureInfo> > >&(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getFragmentTextureInfos);
mt["get"]["FragmentTextureInfos"]=mt["GetFragmentTextureInfos"];
mt["SetParameterAutoBinding"]=static_cast<void(cocos2d::backend::ProgramState::*)(const std::string&,const std::string&)>(&cocos2d::backend::ProgramState::setParameterAutoBinding);
mt["GetVertexLayout"]=static_cast<std::shared_ptr<cocos2d::backend::VertexLayout>(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getVertexLayout);
mt["get"]["VertexLayout"]=mt["GetVertexLayout"];
mt["GetUniformID"]=static_cast<uint32_t(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getUniformID);
mt["get"]["UniformID"]=mt["GetUniformID"];
mt["UpdateUniformID"]=sol::overload([](cocos2d::backend::ProgramState* obj,int arg0){return obj->updateUniformID(arg0);},[](cocos2d::backend::ProgramState* obj){return obj->updateUniformID();});
}
void RegisterLuaBackendTextureBackendAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::TextureBackend).name()] = sol::usertype_traits<cocos2d::backend::TextureBackend*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::TextureBackend>("deprecated.cocos2d::backend::TextureBackend");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::TextureBackend*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccb"]["TextureBackend"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["UpdateSamplerDescriptor"]=static_cast<void(cocos2d::backend::TextureBackend::*)(const cocos2d::backend::SamplerDescriptor&)>(&cocos2d::backend::TextureBackend::updateSamplerDescriptor);
mt["GenerateMipmaps"]=static_cast<void(cocos2d::backend::TextureBackend::*)()>(&cocos2d::backend::TextureBackend::generateMipmaps);
mt["UpdateTextureDescriptor"]=sol::overload([](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0,int arg1){return obj->updateTextureDescriptor(arg0,arg1);},[](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);});
mt["GetTextureFormat"]=static_cast<cocos2d::backend::PixelFormat(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureFormat);
mt["get"]["TextureFormat"]=mt["GetTextureFormat"];
mt["GetTextureUsage"]=static_cast<cocos2d::backend::TextureUsage(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureUsage);
mt["get"]["TextureUsage"]=mt["GetTextureUsage"];
mt["GetTextureType"]=static_cast<cocos2d::backend::TextureType(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureType);
mt["get"]["TextureType"]=mt["GetTextureType"];
mt["HasMipmaps"]=static_cast<bool(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::hasMipmaps);
mt["GetCount"]=static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getCount);
mt["get"]["Count"]=mt["GetCount"];
mt["GetHandler"]=sol::overload([](cocos2d::backend::TextureBackend* obj,int arg0){return obj->getHandler(arg0);},[](cocos2d::backend::TextureBackend* obj){return obj->getHandler();});
mt["get"]["Handler"]=mt["GetHandler"];
mt["GetWidth"]=static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getWidth);
mt["get"]["Width"]=mt["GetWidth"];
mt["GetHeight"]=static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getHeight);
mt["get"]["Height"]=mt["GetHeight"];
}
void RegisterLuaBackendTexture2DBackendAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::Texture2DBackend).name()] = sol::usertype_traits<cocos2d::backend::Texture2DBackend*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::Texture2DBackend>("deprecated.cocos2d::backend::Texture2DBackend");
dep[sol::base_classes]=sol::bases<cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::Texture2DBackend*>::metatable(),sol::usertype_traits<cocos2d::backend::TextureBackend*>::metatable());
lua["ccb"]["Texture2DBackend"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["UpdateData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,int arg4){return obj->updateData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3){return obj->updateData(arg0,arg1,arg2,arg3);});
mt["UpdateCompressedData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,int arg5){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4);});
mt["UpdateSubData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5,int arg6){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["UpdateCompressedSubData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6,int arg7){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);});
mt["GetWidth"]=static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getWidth);
mt["get"]["Width"]=mt["GetWidth"];
mt["GetHeight"]=static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getHeight);
mt["get"]["Height"]=mt["GetHeight"];
}
void RegisterLuaBackendTextureCubemapBackendAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::TextureCubemapBackend).name()] = sol::usertype_traits<cocos2d::backend::TextureCubemapBackend*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::TextureCubemapBackend>("deprecated.cocos2d::backend::TextureCubemapBackend");
dep[sol::base_classes]=sol::bases<cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::TextureCubemapBackend*>::metatable(),sol::usertype_traits<cocos2d::backend::TextureBackend*>::metatable());
lua["ccb"]["TextureCubemapBackend"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["UpdateFaceData"]=sol::overload([](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1,int arg2){return obj->updateFaceData(arg0,arg1,arg2);},[](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1){return obj->updateFaceData(arg0,arg1);});
}
void RegisterLuaBackendDeviceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::backend::Device).name()] = sol::usertype_traits<cocos2d::backend::Device*>::metatable();
auto dep=lua.new_usertype<cocos2d::backend::Device>("deprecated.cocos2d::backend::Device");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::backend::Device*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccb"]["Device"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocos2d::backend::Device*(*)()>(&cocos2d::backend::Device::getInstance);
mt["NewCommandBuffer"]=static_cast<cocos2d::backend::CommandBuffer*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newCommandBuffer);
mt["NewBuffer"]=static_cast<cocos2d::backend::Buffer*(cocos2d::backend::Device::*)(size_t,cocos2d::backend::BufferType,cocos2d::backend::BufferUsage)>(&cocos2d::backend::Device::newBuffer);
mt["NewTexture"]=static_cast<cocos2d::backend::TextureBackend*(cocos2d::backend::Device::*)(const cocos2d::backend::TextureDescriptor&)>(&cocos2d::backend::Device::newTexture);
mt["NewDefaultRenderTarget"]=static_cast<cocos2d::backend::RenderTarget*(cocos2d::backend::Device::*)(cocos2d::backend::TargetBufferFlags)>(&cocos2d::backend::Device::newDefaultRenderTarget);
mt["NewRenderTarget"]=sol::overload([](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2,cocos2d::backend::TextureBackend* arg3){return obj->newRenderTarget(arg0,arg1,arg2,arg3);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2){return obj->newRenderTarget(arg0,arg1,arg2);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1){return obj->newRenderTarget(arg0,arg1);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0){return obj->newRenderTarget(arg0);});
mt["NewDepthStencilState"]=static_cast<cocos2d::backend::DepthStencilState*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newDepthStencilState);
mt["NewRenderPipeline"]=static_cast<cocos2d::backend::RenderPipeline*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newRenderPipeline);
mt["SetFrameBufferOnly"]=static_cast<void(cocos2d::backend::Device::*)(bool)>(&cocos2d::backend::Device::setFrameBufferOnly);
mt["set"]["FrameBufferOnly"]=mt["SetFrameBufferOnly"];
mt["NewProgram"]=static_cast<cocos2d::backend::Program*(cocos2d::backend::Device::*)(const std::string&,const std::string&)>(&cocos2d::backend::Device::newProgram);
mt["GetDeviceInfo"]=static_cast<cocos2d::backend::DeviceInfo*(cocos2d::backend::Device::*)()const>(&cocos2d::backend::Device::getDeviceInfo);
mt["get"]["DeviceInfo"]=mt["GetDeviceInfo"];
mt["static"]["get"]["Instance"]=&cocos2d::backend::Device::getInstance;
}
}
