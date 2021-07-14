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
void RegisterLuaBackendSamplerAddressModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["REPEAT"]=cocos2d::backend::SamplerAddressMode::REPEAT;
enumTable["MIRROR_REPEAT"]=cocos2d::backend::SamplerAddressMode::MIRROR_REPEAT;
enumTable["CLAMP_TO_EDGE"]=cocos2d::backend::SamplerAddressMode::CLAMP_TO_EDGE;
enumTable["DONT_CARE"]=cocos2d::backend::SamplerAddressMode::DONT_CARE;
lua["ccb"]["SamplerAddressMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendSamplerFilterAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,7);
enumTable["NEAREST"]=cocos2d::backend::SamplerFilter::NEAREST;
enumTable["NEAREST_MIPMAP_NEAREST"]=cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_NEAREST;
enumTable["NEAREST_MIPMAP_LINEAR"]=cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_LINEAR;
enumTable["LINEAR"]=cocos2d::backend::SamplerFilter::LINEAR;
enumTable["LINEAR_MIPMAP_LINEAR"]=cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_LINEAR;
enumTable["LINEAR_MIPMAP_NEAREST"]=cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
enumTable["DONT_CARE"]=cocos2d::backend::SamplerFilter::DONT_CARE;
lua["ccb"]["SamplerFilter"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendStencilOperationAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,6);
enumTable["KEEP"]=cocos2d::backend::StencilOperation::KEEP;
enumTable["ZERO"]=cocos2d::backend::StencilOperation::ZERO;
enumTable["REPLACE"]=cocos2d::backend::StencilOperation::REPLACE;
enumTable["INVERT"]=cocos2d::backend::StencilOperation::INVERT;
enumTable["INCREMENT_WRAP"]=cocos2d::backend::StencilOperation::INCREMENT_WRAP;
enumTable["DECREMENT_WRAP"]=cocos2d::backend::StencilOperation::DECREMENT_WRAP;
lua["ccb"]["StencilOperation"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendCompareFunctionAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,8);
enumTable["NEVER"]=cocos2d::backend::CompareFunction::NEVER;
enumTable["LESS"]=cocos2d::backend::CompareFunction::LESS;
enumTable["LESS_EQUAL"]=cocos2d::backend::CompareFunction::LESS_EQUAL;
enumTable["GREATER"]=cocos2d::backend::CompareFunction::GREATER;
enumTable["GREATER_EQUAL"]=cocos2d::backend::CompareFunction::GREATER_EQUAL;
enumTable["EQUAL"]=cocos2d::backend::CompareFunction::EQUAL;
enumTable["NOT_EQUAL"]=cocos2d::backend::CompareFunction::NOT_EQUAL;
enumTable["ALWAYS"]=cocos2d::backend::CompareFunction::ALWAYS;
lua["ccb"]["CompareFunction"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendBlendOperationAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["ADD"]=cocos2d::backend::BlendOperation::ADD;
enumTable["SUBTRACT"]=cocos2d::backend::BlendOperation::SUBTRACT;
enumTable["RESERVE_SUBTRACT"]=cocos2d::backend::BlendOperation::RESERVE_SUBTRACT;
lua["ccb"]["BlendOperation"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendBlendFactorAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,14);
enumTable["ZERO"]=cocos2d::backend::BlendFactor::ZERO;
enumTable["ONE"]=cocos2d::backend::BlendFactor::ONE;
enumTable["SRC_COLOR"]=cocos2d::backend::BlendFactor::SRC_COLOR;
enumTable["ONE_MINUS_SRC_COLOR"]=cocos2d::backend::BlendFactor::ONE_MINUS_SRC_COLOR;
enumTable["SRC_ALPHA"]=cocos2d::backend::BlendFactor::SRC_ALPHA;
enumTable["ONE_MINUS_SRC_ALPHA"]=cocos2d::backend::BlendFactor::ONE_MINUS_SRC_ALPHA;
enumTable["DST_COLOR"]=cocos2d::backend::BlendFactor::DST_COLOR;
enumTable["ONE_MINUS_DST_COLOR"]=cocos2d::backend::BlendFactor::ONE_MINUS_DST_COLOR;
enumTable["DST_ALPHA"]=cocos2d::backend::BlendFactor::DST_ALPHA;
enumTable["ONE_MINUS_DST_ALPHA"]=cocos2d::backend::BlendFactor::ONE_MINUS_DST_ALPHA;
enumTable["CONSTANT_ALPHA"]=cocos2d::backend::BlendFactor::CONSTANT_ALPHA;
enumTable["SRC_ALPHA_SATURATE"]=cocos2d::backend::BlendFactor::SRC_ALPHA_SATURATE;
enumTable["ONE_MINUS_CONSTANT_ALPHA"]=cocos2d::backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA;
enumTable["BLEND_CLOLOR"]=cocos2d::backend::BlendFactor::BLEND_CLOLOR;
lua["ccb"]["BlendFactor"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendColorWriteMaskAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,10);
enumTable["RED_BIT"]=cocos2d::backend::ColorWriteMask::RED_BIT;
enumTable["GREEN_BIT"]=cocos2d::backend::ColorWriteMask::GREEN_BIT;
enumTable["BLUE_BIT"]=cocos2d::backend::ColorWriteMask::BLUE_BIT;
enumTable["ALPHA_BIT"]=cocos2d::backend::ColorWriteMask::ALPHA_BIT;
enumTable["NONE"]=cocos2d::backend::ColorWriteMask::NONE;
enumTable["RED"]=cocos2d::backend::ColorWriteMask::RED;
enumTable["GREEN"]=cocos2d::backend::ColorWriteMask::GREEN;
enumTable["BLUE"]=cocos2d::backend::ColorWriteMask::BLUE;
enumTable["ALPHA"]=cocos2d::backend::ColorWriteMask::ALPHA;
enumTable["ALL"]=cocos2d::backend::ColorWriteMask::ALL;
lua["ccb"]["ColorWriteMask"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendCullModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["NONE"]=cocos2d::backend::CullMode::NONE;
enumTable["BACK"]=cocos2d::backend::CullMode::BACK;
enumTable["FRONT"]=cocos2d::backend::CullMode::FRONT;
lua["ccb"]["CullMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendWindingAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["CLOCK_WISE"]=cocos2d::backend::Winding::CLOCK_WISE;
enumTable["COUNTER_CLOCK_WISE"]=cocos2d::backend::Winding::COUNTER_CLOCK_WISE;
lua["ccb"]["Winding"]=lua.NewEnum(enumTable);
}
void RegisterLuaBackendTextureCubeFaceAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,6);
enumTable["POSITIVE_X"]=cocos2d::backend::TextureCubeFace::POSITIVE_X;
enumTable["NEGATIVE_X"]=cocos2d::backend::TextureCubeFace::NEGATIVE_X;
enumTable["POSITIVE_Y"]=cocos2d::backend::TextureCubeFace::POSITIVE_Y;
enumTable["NEGATIVE_Y"]=cocos2d::backend::TextureCubeFace::NEGATIVE_Y;
enumTable["POSITIVE_Z"]=cocos2d::backend::TextureCubeFace::POSITIVE_Z;
enumTable["NEGATIVE_Z"]=cocos2d::backend::TextureCubeFace::NEGATIVE_Z;
lua["ccb"]["TextureCubeFace"]=lua.NewEnum(enumTable);
}
}
