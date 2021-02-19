#include "scripting/lua-bindings/auto/CCRegisterLuaBackendAuto.hpp"
#include "renderer/backend/Types.h"
#include "renderer/backend/ProgramState.h"
#include "renderer/backend/Texture.h"
#include "renderer/backend/VertexLayout.h"
#include "renderer/backend/Device.h"
#include "renderer/backend/RenderTarget.h"
static void RegisterLuaBackendBufferUsage(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("BufferUsage"
,"STATIC", 0
,"DYNAMIC", 1
);
}
static void RegisterLuaBackendBufferType(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("BufferType"
,"VERTEX", 0
,"INDEX", 1
);
}
static void RegisterLuaBackendShaderStage(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("ShaderStage"
,"VERTEX", 0
,"FRAGMENT", 1
,"VERTEX_AND_FRAGMENT", 2
);
}
static void RegisterLuaBackendVertexFormat(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("VertexFormat"
,"FLOAT4", 0
,"FLOAT3", 1
,"FLOAT2", 2
,"FLOAT", 3
,"INT4", 4
,"INT3", 5
,"INT2", 6
,"INT", 7
,"USHORT4", 8
,"USHORT2", 9
,"UBYTE4", 10
);
}
static void RegisterLuaBackendPixelFormat(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("PixelFormat"
,"PVRTC4", 0
,"PVRTC4A", 1
,"PVRTC2", 2
,"PVRTC2A", 3
,"ETC1", 4
,"ETC2_RGB", 5
,"ETC2_RGBA", 6
,"S3TC_DXT1", 7
,"S3TC_DXT3", 8
,"S3TC_DXT5", 9
,"ATC_RGB", 10
,"ATC_EXPLICIT_ALPHA", 11
,"ATC_INTERPOLATED_ALPHA", 12
,"ASTC4x4", 13
,"ASTC5x5", 14
,"ASTC6x6", 15
,"ASTC8x5", 16
,"ASTC8x6", 17
,"ASTC8x8", 18
,"ASTC10x5", 19
,"RGBA8", 20
,"BGRA8", 21
,"RGB8", 22
,"RGB565", 23
,"RGBA4", 24
,"RGB5A1", 25
,"A8", 26
,"L8", 27
,"LA8", 28
,"D24S8", 29
,"COUNT", 30
,"NONE", 65535
);
}
static void RegisterLuaBackendTextureUsage(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("TextureUsage"
,"READ", 0
,"WRITE", 1
,"RENDER_TARGET", 2
);
}
static void RegisterLuaBackendIndexFormat(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("IndexFormat"
,"U_SHORT", 0
,"U_INT", 1
);
}
static void RegisterLuaBackendVertexStepMode(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("VertexStepMode"
,"VERTEX", 0
,"INSTANCE", 1
);
}
static void RegisterLuaBackendPrimitiveType(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("PrimitiveType"
,"POINT", 0
,"LINE", 1
,"LINE_STRIP", 2
,"TRIANGLE", 3
,"TRIANGLE_STRIP", 4
);
}
static void RegisterLuaBackendTextureType(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("TextureType"
,"TEXTURE_2D", 0
,"TEXTURE_CUBE", 1
);
}
static void RegisterLuaBackendSamplerAddressMode(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("SamplerAddressMode"
,"REPEAT", 0
,"MIRROR_REPEAT", 1
,"CLAMP_TO_EDGE", 2
,"DONT_CARE", 3
);
}
static void RegisterLuaBackendSamplerFilter(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("SamplerFilter"
,"NEAREST", 0
,"NEAREST_MIPMAP_NEAREST", 1
,"NEAREST_MIPMAP_LINEAR", 2
,"LINEAR", 3
,"LINEAR_MIPMAP_LINEAR", 4
,"LINEAR_MIPMAP_NEAREST", 5
,"DONT_CARE", 6
);
}
static void RegisterLuaBackendStencilOperation(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("StencilOperation"
,"KEEP", 0
,"ZERO", 1
,"REPLACE", 2
,"INVERT", 3
,"INCREMENT_WRAP", 4
,"DECREMENT_WRAP", 5
);
}
static void RegisterLuaBackendCompareFunction(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("CompareFunction"
,"NEVER", 0
,"LESS", 1
,"LESS_EQUAL", 2
,"GREATER", 3
,"GREATER_EQUAL", 4
,"EQUAL", 5
,"NOT_EQUAL", 6
,"ALWAYS", 7
);
}
static void RegisterLuaBackendBlendOperation(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("BlendOperation"
,"ADD", 0
,"SUBTRACT", 1
,"RESERVE_SUBTRACT", 2
);
}
static void RegisterLuaBackendBlendFactor(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("BlendFactor"
,"ZERO", 0
,"ONE", 1
,"SRC_COLOR", 2
,"ONE_MINUS_SRC_COLOR", 3
,"SRC_ALPHA", 4
,"ONE_MINUS_SRC_ALPHA", 5
,"DST_COLOR", 6
,"ONE_MINUS_DST_COLOR", 7
,"DST_ALPHA", 8
,"ONE_MINUS_DST_ALPHA", 9
,"CONSTANT_ALPHA", 10
,"SRC_ALPHA_SATURATE", 11
,"ONE_MINUS_CONSTANT_ALPHA", 12
,"BLEND_CLOLOR", 13
);
}
static void RegisterLuaBackendColorWriteMask(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("ColorWriteMask"
,"RED_BIT", 0
,"GREEN_BIT", 1
,"BLUE_BIT", 2
,"ALPHA_BIT", 3
,"NONE", 0
,"RED", 1
,"GREEN", 2
,"BLUE", 4
,"ALPHA", 8
,"ALL", 15
);
}
static void RegisterLuaBackendCullMode(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("CullMode"
,"NONE", 0
,"BACK", 1
,"FRONT", 2
);
}
static void RegisterLuaBackendWinding(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("Winding"
,"CLOCK_WISE", 0
,"COUNTER_CLOCK_WISE", 1
);
}
static void RegisterLuaBackendTextureCubeFace(cocos2d::Lua& lua) {
sol::table ccb = lua.get_or("ccb",lua.create_named_table("ccb"));
ccb.new_enum("TextureCubeFace"
,"POSITIVE_X", 0
,"NEGATIVE_X", 1
,"POSITIVE_Y", 2
,"NEGATIVE_Y", 3
,"POSITIVE_Z", 4
,"NEGATIVE_Z", 5
);
}
static void RegisterLuaBackendProgram(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Program,cocos2d::Ref,cocos2d::LuaObject>("ccb","Program");
mt["getUniformLocation"]=sol::overload(static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(cocos2d::backend::Uniform)const>(&cocos2d::backend::Program::getUniformLocation),static_cast<cocos2d::backend::UniformLocation(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getUniformLocation));
mt["getAttributeLocation"]=sol::overload(static_cast<int(cocos2d::backend::Program::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::Program::getAttributeLocation),static_cast<int(cocos2d::backend::Program::*)(const std::string&)const>(&cocos2d::backend::Program::getAttributeLocation));
mt["getMaxVertexLocation"]=static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxVertexLocation);
mt["getMaxFragmentLocation"]=static_cast<int(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getMaxFragmentLocation);
mt["getActiveAttributes"]=static_cast<const std::unordered_map<std::string, cocos2d::backend::AttributeBindInfo>(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getActiveAttributes);
mt["getVertexShader"]=static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getVertexShader);
mt["getFragmentShader"]=static_cast<const std::string&(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getFragmentShader);
mt["getProgramType"]=static_cast<uint32_t(cocos2d::backend::Program::*)()const>(&cocos2d::backend::Program::getProgramType);
mt["getUniformBufferSize"]=static_cast<size_t(cocos2d::backend::Program::*)(cocos2d::backend::ShaderStage)const>(&cocos2d::backend::Program::getUniformBufferSize);
mt["setProgramType"]=static_cast<void(cocos2d::backend::Program::*)(uint32_t)>(&cocos2d::backend::Program::setProgramType);
mt["getBuiltinProgram"]=static_cast<cocos2d::backend::Program*(*)(uint32_t)>(&cocos2d::backend::Program::getBuiltinProgram);
}
static void RegisterLuaBackendVertexLayout(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::VertexLayout>("ccb","VertexLayout");
mt["setAttribute"]=static_cast<void(cocos2d::backend::VertexLayout::*)(const std::string&,size_t,cocos2d::backend::VertexFormat,size_t,bool)>(&cocos2d::backend::VertexLayout::setAttribute);
mt["setLayout"]=static_cast<void(cocos2d::backend::VertexLayout::*)(size_t)>(&cocos2d::backend::VertexLayout::setLayout);
mt["getStride"]=static_cast<size_t(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getStride);
mt["getVertexStepMode"]=static_cast<cocos2d::backend::VertexStepMode(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::getVertexStepMode);
mt["isValid"]=static_cast<bool(cocos2d::backend::VertexLayout::*)()const>(&cocos2d::backend::VertexLayout::isValid);
}
static void RegisterLuaBackendProgramState(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::ProgramState,cocos2d::Ref,cocos2d::LuaObject>("ccb","ProgramState");
mt["clone"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::clone);
mt["getProgram"]=static_cast<cocos2d::backend::Program*(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getProgram);
mt["getAttributeLocation"]=sol::overload(static_cast<int(cocos2d::backend::ProgramState::*)(cocos2d::backend::Attribute)const>(&cocos2d::backend::ProgramState::getAttributeLocation),static_cast<int(cocos2d::backend::ProgramState::*)(const std::string&)const>(&cocos2d::backend::ProgramState::getAttributeLocation));
mt["setTexture"]=sol::overload(static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture),static_cast<void(cocos2d::backend::ProgramState::*)(const cocos2d::backend::UniformLocation&,uint16_t,uint16_t,cocos2d::backend::TextureBackend*)>(&cocos2d::backend::ProgramState::setTexture));
mt["setParameterAutoBinding"]=static_cast<void(cocos2d::backend::ProgramState::*)(const std::string&,const std::string&)>(&cocos2d::backend::ProgramState::setParameterAutoBinding);
mt["getUniformID"]=static_cast<uint32_t(cocos2d::backend::ProgramState::*)()const>(&cocos2d::backend::ProgramState::getUniformID);
mt["updateUniformID"]=sol::overload([](cocos2d::backend::ProgramState* obj){return obj->updateUniformID();},[](cocos2d::backend::ProgramState* obj,int arg0){return obj->updateUniformID(arg0);});
}
static void RegisterLuaBackendTextureBackend(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::LuaObject>("ccb","TextureBackend");
mt["updateSamplerDescriptor"]=static_cast<void(cocos2d::backend::TextureBackend::*)(const cocos2d::backend::SamplerDescriptor&)>(&cocos2d::backend::TextureBackend::updateSamplerDescriptor);
mt["generateMipmaps"]=static_cast<void(cocos2d::backend::TextureBackend::*)()>(&cocos2d::backend::TextureBackend::generateMipmaps);
mt["updateTextureDescriptor"]=sol::overload([](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::backend::TextureBackend* obj,const cocos2d::backend::TextureDescriptor& arg0,int arg1){return obj->updateTextureDescriptor(arg0,arg1);});
mt["getTextureFormat"]=static_cast<cocos2d::backend::PixelFormat(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureFormat);
mt["getTextureUsage"]=static_cast<cocos2d::backend::TextureUsage(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureUsage);
mt["getTextureType"]=static_cast<cocos2d::backend::TextureType(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getTextureType);
mt["hasMipmaps"]=static_cast<bool(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::hasMipmaps);
mt["getCount"]=static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getCount);
mt["getHandler"]=sol::overload([](cocos2d::backend::TextureBackend* obj){return obj->getHandler();},[](cocos2d::backend::TextureBackend* obj,int arg0){return obj->getHandler(arg0);});
mt["getWidth"]=static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getWidth);
mt["getHeight"]=static_cast<int(cocos2d::backend::TextureBackend::*)()const>(&cocos2d::backend::TextureBackend::getHeight);
}
static void RegisterLuaBackendTexture2DBackend(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Texture2DBackend,cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::LuaObject>("ccb","Texture2DBackend");
mt["updateData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3){return obj->updateData(arg0,arg1,arg2,arg3);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,int arg4){return obj->updateData(arg0,arg1,arg2,arg3,arg4);});
mt["updateCompressedData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::backend::Texture2DBackend* obj,uint8_t* arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,int arg5){return obj->updateCompressedData(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["updateSubData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,uint8_t* arg5,int arg6){return obj->updateSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);});
mt["updateCompressedSubData"]=sol::overload([](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::backend::Texture2DBackend* obj,size_t arg0,size_t arg1,size_t arg2,size_t arg3,size_t arg4,size_t arg5,uint8_t* arg6,int arg7){return obj->updateCompressedSubData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);});
mt["getWidth"]=static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getWidth);
mt["getHeight"]=static_cast<size_t(cocos2d::backend::Texture2DBackend::*)()const>(&cocos2d::backend::Texture2DBackend::getHeight);
}
static void RegisterLuaBackendTextureCubemapBackend(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::TextureCubemapBackend,cocos2d::backend::TextureBackend,cocos2d::Ref,cocos2d::LuaObject>("ccb","TextureCubemapBackend");
mt["updateFaceData"]=sol::overload([](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1){return obj->updateFaceData(arg0,arg1);},[](cocos2d::backend::TextureCubemapBackend* obj,cocos2d::backend::TextureCubeFace arg0,void* arg1,int arg2){return obj->updateFaceData(arg0,arg1,arg2);});
}
static void RegisterLuaBackendDevice(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::backend::Device,cocos2d::Ref,cocos2d::LuaObject>("ccb","Device");
mt["newDefaultRenderTarget"]=static_cast<cocos2d::backend::RenderTarget*(cocos2d::backend::Device::*)(cocos2d::backend::TargetBufferFlags)>(&cocos2d::backend::Device::newDefaultRenderTarget);
mt["newRenderTarget"]=sol::overload([](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0){return obj->newRenderTarget(arg0);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1){return obj->newRenderTarget(arg0,arg1);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2){return obj->newRenderTarget(arg0,arg1,arg2);},[](cocos2d::backend::Device* obj,cocos2d::backend::TargetBufferFlags arg0,cocos2d::backend::TextureBackend* arg1,cocos2d::backend::TextureBackend* arg2,cocos2d::backend::TextureBackend* arg3){return obj->newRenderTarget(arg0,arg1,arg2,arg3);});
mt["newDepthStencilState"]=static_cast<cocos2d::backend::DepthStencilState*(cocos2d::backend::Device::*)()>(&cocos2d::backend::Device::newDepthStencilState);
mt["newProgram"]=static_cast<cocos2d::backend::Program*(cocos2d::backend::Device::*)(const std::string&,const std::string&)>(&cocos2d::backend::Device::newProgram);
mt["getInstance"]=static_cast<cocos2d::backend::Device*(*)()>(&cocos2d::backend::Device::getInstance);
}
void RegisterLuaBackendAuto(cocos2d::Lua& lua) {
RegisterLuaBackendBufferUsage(lua);
RegisterLuaBackendBufferType(lua);
RegisterLuaBackendShaderStage(lua);
RegisterLuaBackendVertexFormat(lua);
RegisterLuaBackendPixelFormat(lua);
RegisterLuaBackendTextureUsage(lua);
RegisterLuaBackendIndexFormat(lua);
RegisterLuaBackendVertexStepMode(lua);
RegisterLuaBackendPrimitiveType(lua);
RegisterLuaBackendTextureType(lua);
RegisterLuaBackendSamplerAddressMode(lua);
RegisterLuaBackendSamplerFilter(lua);
RegisterLuaBackendStencilOperation(lua);
RegisterLuaBackendCompareFunction(lua);
RegisterLuaBackendBlendOperation(lua);
RegisterLuaBackendBlendFactor(lua);
RegisterLuaBackendColorWriteMask(lua);
RegisterLuaBackendCullMode(lua);
RegisterLuaBackendWinding(lua);
RegisterLuaBackendTextureCubeFace(lua);
RegisterLuaBackendProgram(lua);
RegisterLuaBackendVertexLayout(lua);
RegisterLuaBackendProgramState(lua);
RegisterLuaBackendTextureBackend(lua);
RegisterLuaBackendTexture2DBackend(lua);
RegisterLuaBackendTextureCubemapBackend(lua);
RegisterLuaBackendDevice(lua);
}
