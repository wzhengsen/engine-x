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
void RegisterLuaBackendSamplerAddressModeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("SamplerAddressMode"
,"REPEAT",0
,"MIRROR_REPEAT",1
,"CLAMP_TO_EDGE",2
,"DONT_CARE",3
);}
void RegisterLuaBackendSamplerFilterAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("SamplerFilter"
,"NEAREST",0
,"NEAREST_MIPMAP_NEAREST",1
,"NEAREST_MIPMAP_LINEAR",2
,"LINEAR",3
,"LINEAR_MIPMAP_LINEAR",4
,"LINEAR_MIPMAP_NEAREST",5
,"DONT_CARE",6
);}
void RegisterLuaBackendStencilOperationAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("StencilOperation"
,"KEEP",0
,"ZERO",1
,"REPLACE",2
,"INVERT",3
,"INCREMENT_WRAP",4
,"DECREMENT_WRAP",5
);}
void RegisterLuaBackendCompareFunctionAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("CompareFunction"
,"NEVER",0
,"LESS",1
,"LESS_EQUAL",2
,"GREATER",3
,"GREATER_EQUAL",4
,"EQUAL",5
,"NOT_EQUAL",6
,"ALWAYS",7
);}
void RegisterLuaBackendBlendOperationAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("BlendOperation"
,"ADD",0
,"SUBTRACT",1
,"RESERVE_SUBTRACT",2
);}
void RegisterLuaBackendBlendFactorAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("BlendFactor"
,"ZERO",0
,"ONE",1
,"SRC_COLOR",2
,"ONE_MINUS_SRC_COLOR",3
,"SRC_ALPHA",4
,"ONE_MINUS_SRC_ALPHA",5
,"DST_COLOR",6
,"ONE_MINUS_DST_COLOR",7
,"DST_ALPHA",8
,"ONE_MINUS_DST_ALPHA",9
,"CONSTANT_ALPHA",10
,"SRC_ALPHA_SATURATE",11
,"ONE_MINUS_CONSTANT_ALPHA",12
,"BLEND_CLOLOR",13
);}
void RegisterLuaBackendColorWriteMaskAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("ColorWriteMask"
,"RED_BIT",0
,"GREEN_BIT",1
,"BLUE_BIT",2
,"ALPHA_BIT",3
,"NONE",0
,"RED",1
,"GREEN",2
,"BLUE",4
,"ALPHA",8
,"ALL",15
);}
void RegisterLuaBackendCullModeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("CullMode"
,"NONE",0
,"BACK",1
,"FRONT",2
);}
void RegisterLuaBackendWindingAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("Winding"
,"CLOCK_WISE",0
,"COUNTER_CLOCK_WISE",1
);}
void RegisterLuaBackendTextureCubeFaceAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum("TextureCubeFace"
,"POSITIVE_X",0
,"NEGATIVE_X",1
,"POSITIVE_Y",2
,"NEGATIVE_Y",3
,"POSITIVE_Z",4
,"NEGATIVE_Z",5
);}
