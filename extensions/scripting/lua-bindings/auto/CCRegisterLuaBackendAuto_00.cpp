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
void RegisterLuaBackendBufferUsageAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::BufferUsage>("BufferUsage",{
{"STATIC",cocos2d::backend::BufferUsage::STATIC}
,{"DYNAMIC",cocos2d::backend::BufferUsage::DYNAMIC}
});}
void RegisterLuaBackendBufferTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::BufferType>("BufferType",{
{"VERTEX",cocos2d::backend::BufferType::VERTEX}
,{"INDEX",cocos2d::backend::BufferType::INDEX}
});}
void RegisterLuaBackendShaderStageAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::ShaderStage>("ShaderStage",{
{"VERTEX",cocos2d::backend::ShaderStage::VERTEX}
,{"FRAGMENT",cocos2d::backend::ShaderStage::FRAGMENT}
,{"VERTEX_AND_FRAGMENT",cocos2d::backend::ShaderStage::VERTEX_AND_FRAGMENT}
});}
void RegisterLuaBackendVertexFormatAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::VertexFormat>("VertexFormat",{
{"FLOAT4",cocos2d::backend::VertexFormat::FLOAT4}
,{"FLOAT3",cocos2d::backend::VertexFormat::FLOAT3}
,{"FLOAT2",cocos2d::backend::VertexFormat::FLOAT2}
,{"FLOAT",cocos2d::backend::VertexFormat::FLOAT}
,{"INT4",cocos2d::backend::VertexFormat::INT4}
,{"INT3",cocos2d::backend::VertexFormat::INT3}
,{"INT2",cocos2d::backend::VertexFormat::INT2}
,{"INT",cocos2d::backend::VertexFormat::INT}
,{"USHORT4",cocos2d::backend::VertexFormat::USHORT4}
,{"USHORT2",cocos2d::backend::VertexFormat::USHORT2}
,{"UBYTE4",cocos2d::backend::VertexFormat::UBYTE4}
});}
void RegisterLuaBackendPixelFormatAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::PixelFormat>("PixelFormat",{
{"PVRTC4",cocos2d::backend::PixelFormat::PVRTC4}
,{"PVRTC4A",cocos2d::backend::PixelFormat::PVRTC4A}
,{"PVRTC2",cocos2d::backend::PixelFormat::PVRTC2}
,{"PVRTC2A",cocos2d::backend::PixelFormat::PVRTC2A}
,{"ETC1",cocos2d::backend::PixelFormat::ETC1}
,{"ETC2_RGB",cocos2d::backend::PixelFormat::ETC2_RGB}
,{"ETC2_RGBA",cocos2d::backend::PixelFormat::ETC2_RGBA}
,{"S3TC_DXT1",cocos2d::backend::PixelFormat::S3TC_DXT1}
,{"S3TC_DXT3",cocos2d::backend::PixelFormat::S3TC_DXT3}
,{"S3TC_DXT5",cocos2d::backend::PixelFormat::S3TC_DXT5}
,{"ATC_RGB",cocos2d::backend::PixelFormat::ATC_RGB}
,{"ATC_EXPLICIT_ALPHA",cocos2d::backend::PixelFormat::ATC_EXPLICIT_ALPHA}
,{"ATC_INTERPOLATED_ALPHA",cocos2d::backend::PixelFormat::ATC_INTERPOLATED_ALPHA}
,{"ASTC4X4",cocos2d::backend::PixelFormat::ASTC4x4}
,{"ASTC5X5",cocos2d::backend::PixelFormat::ASTC5x5}
,{"ASTC6X6",cocos2d::backend::PixelFormat::ASTC6x6}
,{"ASTC8X5",cocos2d::backend::PixelFormat::ASTC8x5}
,{"ASTC8X6",cocos2d::backend::PixelFormat::ASTC8x6}
,{"ASTC8X8",cocos2d::backend::PixelFormat::ASTC8x8}
,{"ASTC10X5",cocos2d::backend::PixelFormat::ASTC10x5}
,{"RGBA8",cocos2d::backend::PixelFormat::RGBA8}
,{"BGRA8",cocos2d::backend::PixelFormat::BGRA8}
,{"RGB8",cocos2d::backend::PixelFormat::RGB8}
,{"RGB565",cocos2d::backend::PixelFormat::RGB565}
,{"RGBA4",cocos2d::backend::PixelFormat::RGBA4}
,{"RGB5A1",cocos2d::backend::PixelFormat::RGB5A1}
,{"A8",cocos2d::backend::PixelFormat::A8}
,{"L8",cocos2d::backend::PixelFormat::L8}
,{"LA8",cocos2d::backend::PixelFormat::LA8}
,{"D24S8",cocos2d::backend::PixelFormat::D24S8}
,{"COUNT",cocos2d::backend::PixelFormat::COUNT}
,{"NONE",cocos2d::backend::PixelFormat::NONE}
});}
void RegisterLuaBackendTextureUsageAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::TextureUsage>("TextureUsage",{
{"READ",cocos2d::backend::TextureUsage::READ}
,{"WRITE",cocos2d::backend::TextureUsage::WRITE}
,{"RENDER_TARGET",cocos2d::backend::TextureUsage::RENDER_TARGET}
});}
void RegisterLuaBackendIndexFormatAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::IndexFormat>("IndexFormat",{
{"U_SHORT",cocos2d::backend::IndexFormat::U_SHORT}
,{"U_INT",cocos2d::backend::IndexFormat::U_INT}
});}
void RegisterLuaBackendVertexStepModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::VertexStepMode>("VertexStepMode",{
{"VERTEX",cocos2d::backend::VertexStepMode::VERTEX}
,{"INSTANCE",cocos2d::backend::VertexStepMode::INSTANCE}
});}
void RegisterLuaBackendPrimitiveTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::PrimitiveType>("PrimitiveType",{
{"POINT",cocos2d::backend::PrimitiveType::POINT}
,{"LINE",cocos2d::backend::PrimitiveType::LINE}
,{"LINE_STRIP",cocos2d::backend::PrimitiveType::LINE_STRIP}
,{"TRIANGLE",cocos2d::backend::PrimitiveType::TRIANGLE}
,{"TRIANGLE_STRIP",cocos2d::backend::PrimitiveType::TRIANGLE_STRIP}
});}
void RegisterLuaBackendTextureTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::TextureType>("TextureType",{
{"TEXTURE_2D",cocos2d::backend::TextureType::TEXTURE_2D}
,{"TEXTURE_CUBE",cocos2d::backend::TextureType::TEXTURE_CUBE}
});}
