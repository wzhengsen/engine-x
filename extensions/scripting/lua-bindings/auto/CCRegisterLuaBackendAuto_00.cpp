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
void RegisterLuaBackendBufferUsageAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["STATIC"]=cocos2d::backend::BufferUsage::STATIC;
enumTable["DYNAMIC"]=cocos2d::backend::BufferUsage::DYNAMIC;
lua["ccb"]["BufferUsage"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendBufferTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["VERTEX"]=cocos2d::backend::BufferType::VERTEX;
enumTable["INDEX"]=cocos2d::backend::BufferType::INDEX;
lua["ccb"]["BufferType"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendShaderStageAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["VERTEX"]=cocos2d::backend::ShaderStage::VERTEX;
enumTable["FRAGMENT"]=cocos2d::backend::ShaderStage::FRAGMENT;
enumTable["VERTEX_AND_FRAGMENT"]=cocos2d::backend::ShaderStage::VERTEX_AND_FRAGMENT;
lua["ccb"]["ShaderStage"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendVertexFormatAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,11);
enumTable["FLOAT4"]=cocos2d::backend::VertexFormat::FLOAT4;
enumTable["FLOAT3"]=cocos2d::backend::VertexFormat::FLOAT3;
enumTable["FLOAT2"]=cocos2d::backend::VertexFormat::FLOAT2;
enumTable["FLOAT"]=cocos2d::backend::VertexFormat::FLOAT;
enumTable["INT4"]=cocos2d::backend::VertexFormat::INT4;
enumTable["INT3"]=cocos2d::backend::VertexFormat::INT3;
enumTable["INT2"]=cocos2d::backend::VertexFormat::INT2;
enumTable["INT"]=cocos2d::backend::VertexFormat::INT;
enumTable["USHORT4"]=cocos2d::backend::VertexFormat::USHORT4;
enumTable["USHORT2"]=cocos2d::backend::VertexFormat::USHORT2;
enumTable["UBYTE4"]=cocos2d::backend::VertexFormat::UBYTE4;
lua["ccb"]["VertexFormat"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendPixelFormatAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,32);
enumTable["PVRTC4"]=cocos2d::backend::PixelFormat::PVRTC4;
enumTable["PVRTC4A"]=cocos2d::backend::PixelFormat::PVRTC4A;
enumTable["PVRTC2"]=cocos2d::backend::PixelFormat::PVRTC2;
enumTable["PVRTC2A"]=cocos2d::backend::PixelFormat::PVRTC2A;
enumTable["ETC1"]=cocos2d::backend::PixelFormat::ETC1;
enumTable["ETC2_RGB"]=cocos2d::backend::PixelFormat::ETC2_RGB;
enumTable["ETC2_RGBA"]=cocos2d::backend::PixelFormat::ETC2_RGBA;
enumTable["S3TC_DXT1"]=cocos2d::backend::PixelFormat::S3TC_DXT1;
enumTable["S3TC_DXT3"]=cocos2d::backend::PixelFormat::S3TC_DXT3;
enumTable["S3TC_DXT5"]=cocos2d::backend::PixelFormat::S3TC_DXT5;
enumTable["ATC_RGB"]=cocos2d::backend::PixelFormat::ATC_RGB;
enumTable["ATC_EXPLICIT_ALPHA"]=cocos2d::backend::PixelFormat::ATC_EXPLICIT_ALPHA;
enumTable["ATC_INTERPOLATED_ALPHA"]=cocos2d::backend::PixelFormat::ATC_INTERPOLATED_ALPHA;
enumTable["ASTC4X4"]=cocos2d::backend::PixelFormat::ASTC4x4;
enumTable["ASTC5X5"]=cocos2d::backend::PixelFormat::ASTC5x5;
enumTable["ASTC6X6"]=cocos2d::backend::PixelFormat::ASTC6x6;
enumTable["ASTC8X5"]=cocos2d::backend::PixelFormat::ASTC8x5;
enumTable["ASTC8X6"]=cocos2d::backend::PixelFormat::ASTC8x6;
enumTable["ASTC8X8"]=cocos2d::backend::PixelFormat::ASTC8x8;
enumTable["ASTC10X5"]=cocos2d::backend::PixelFormat::ASTC10x5;
enumTable["RGBA8"]=cocos2d::backend::PixelFormat::RGBA8;
enumTable["BGRA8"]=cocos2d::backend::PixelFormat::BGRA8;
enumTable["RGB8"]=cocos2d::backend::PixelFormat::RGB8;
enumTable["RGB565"]=cocos2d::backend::PixelFormat::RGB565;
enumTable["RGBA4"]=cocos2d::backend::PixelFormat::RGBA4;
enumTable["RGB5A1"]=cocos2d::backend::PixelFormat::RGB5A1;
enumTable["A8"]=cocos2d::backend::PixelFormat::A8;
enumTable["L8"]=cocos2d::backend::PixelFormat::L8;
enumTable["LA8"]=cocos2d::backend::PixelFormat::LA8;
enumTable["D24S8"]=cocos2d::backend::PixelFormat::D24S8;
enumTable["COUNT"]=cocos2d::backend::PixelFormat::COUNT;
enumTable["NONE"]=cocos2d::backend::PixelFormat::NONE;
lua["ccb"]["PixelFormat"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendTextureUsageAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["READ"]=cocos2d::backend::TextureUsage::READ;
enumTable["WRITE"]=cocos2d::backend::TextureUsage::WRITE;
enumTable["RENDER_TARGET"]=cocos2d::backend::TextureUsage::RENDER_TARGET;
lua["ccb"]["TextureUsage"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendIndexFormatAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["U_SHORT"]=cocos2d::backend::IndexFormat::U_SHORT;
enumTable["U_INT"]=cocos2d::backend::IndexFormat::U_INT;
lua["ccb"]["IndexFormat"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendVertexStepModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["VERTEX"]=cocos2d::backend::VertexStepMode::VERTEX;
enumTable["INSTANCE"]=cocos2d::backend::VertexStepMode::INSTANCE;
lua["ccb"]["VertexStepMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendPrimitiveTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,5);
enumTable["POINT"]=cocos2d::backend::PrimitiveType::POINT;
enumTable["LINE"]=cocos2d::backend::PrimitiveType::LINE;
enumTable["LINE_STRIP"]=cocos2d::backend::PrimitiveType::LINE_STRIP;
enumTable["TRIANGLE"]=cocos2d::backend::PrimitiveType::TRIANGLE;
enumTable["TRIANGLE_STRIP"]=cocos2d::backend::PrimitiveType::TRIANGLE_STRIP;
lua["ccb"]["PrimitiveType"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendTextureTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["TEXTURE_2D"]=cocos2d::backend::TextureType::TEXTURE_2D;
enumTable["TEXTURE_CUBE"]=cocos2d::backend::TextureType::TEXTURE_CUBE;
lua["ccb"]["TextureType"]=lua.NewEnum(enumTable);
}
}
