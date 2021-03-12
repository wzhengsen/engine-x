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
void RegisterLuaBackendBufferUsageAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("BufferUsage"
,"STATIC",0
,"DYNAMIC",1
);}
void RegisterLuaBackendBufferTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("BufferType"
,"VERTEX",0
,"INDEX",1
);}
void RegisterLuaBackendShaderStageAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("ShaderStage"
,"VERTEX",0
,"FRAGMENT",1
,"VERTEX_AND_FRAGMENT",2
);}
void RegisterLuaBackendVertexFormatAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("VertexFormat"
,"FLOAT4",0
,"FLOAT3",1
,"FLOAT2",2
,"FLOAT",3
,"INT4",4
,"INT3",5
,"INT2",6
,"INT",7
,"USHORT4",8
,"USHORT2",9
,"UBYTE4",10
);}
void RegisterLuaBackendPixelFormatAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("PixelFormat"
,"PVRTC4",0
,"PVRTC4A",1
,"PVRTC2",2
,"PVRTC2A",3
,"ETC1",4
,"ETC2_RGB",5
,"ETC2_RGBA",6
,"S3TC_DXT1",7
,"S3TC_DXT3",8
,"S3TC_DXT5",9
,"ATC_RGB",10
,"ATC_EXPLICIT_ALPHA",11
,"ATC_INTERPOLATED_ALPHA",12
,"ASTC4x4",13
,"ASTC5x5",14
,"ASTC6x6",15
,"ASTC8x5",16
,"ASTC8x6",17
,"ASTC8x8",18
,"ASTC10x5",19
,"RGBA8",20
,"BGRA8",21
,"RGB8",22
,"RGB565",23
,"RGBA4",24
,"RGB5A1",25
,"A8",26
,"L8",27
,"LA8",28
,"D24S8",29
,"COUNT",30
,"NONE",65535
);}
void RegisterLuaBackendTextureUsageAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("TextureUsage"
,"READ",0
,"WRITE",1
,"RENDER_TARGET",2
);}
void RegisterLuaBackendIndexFormatAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("IndexFormat"
,"U_SHORT",0
,"U_INT",1
);}
void RegisterLuaBackendVertexStepModeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("VertexStepMode"
,"VERTEX",0
,"INSTANCE",1
);}
void RegisterLuaBackendPrimitiveTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("PrimitiveType"
,"POINT",0
,"LINE",1
,"LINE_STRIP",2
,"TRIANGLE",3
,"TRIANGLE_STRIP",4
);}
void RegisterLuaBackendTextureTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("TextureType"
,"TEXTURE_2D",0
,"TEXTURE_CUBE",1
);}
