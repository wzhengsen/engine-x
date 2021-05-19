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
void RegisterLuaBackendSamplerAddressModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::SamplerAddressMode>("SamplerAddressMode",{
{"REPEAT",cocos2d::backend::SamplerAddressMode::REPEAT}
,{"MIRROR_REPEAT",cocos2d::backend::SamplerAddressMode::MIRROR_REPEAT}
,{"CLAMP_TO_EDGE",cocos2d::backend::SamplerAddressMode::CLAMP_TO_EDGE}
,{"DONT_CARE",cocos2d::backend::SamplerAddressMode::DONT_CARE}
});}
void RegisterLuaBackendSamplerFilterAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::SamplerFilter>("SamplerFilter",{
{"NEAREST",cocos2d::backend::SamplerFilter::NEAREST}
,{"NEAREST_MIPMAP_NEAREST",cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_NEAREST}
,{"NEAREST_MIPMAP_LINEAR",cocos2d::backend::SamplerFilter::NEAREST_MIPMAP_LINEAR}
,{"LINEAR",cocos2d::backend::SamplerFilter::LINEAR}
,{"LINEAR_MIPMAP_LINEAR",cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_LINEAR}
,{"LINEAR_MIPMAP_NEAREST",cocos2d::backend::SamplerFilter::LINEAR_MIPMAP_NEAREST}
,{"DONT_CARE",cocos2d::backend::SamplerFilter::DONT_CARE}
});}
void RegisterLuaBackendStencilOperationAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::StencilOperation>("StencilOperation",{
{"KEEP",cocos2d::backend::StencilOperation::KEEP}
,{"ZERO",cocos2d::backend::StencilOperation::ZERO}
,{"REPLACE",cocos2d::backend::StencilOperation::REPLACE}
,{"INVERT",cocos2d::backend::StencilOperation::INVERT}
,{"INCREMENT_WRAP",cocos2d::backend::StencilOperation::INCREMENT_WRAP}
,{"DECREMENT_WRAP",cocos2d::backend::StencilOperation::DECREMENT_WRAP}
});}
void RegisterLuaBackendCompareFunctionAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::CompareFunction>("CompareFunction",{
{"NEVER",cocos2d::backend::CompareFunction::NEVER}
,{"LESS",cocos2d::backend::CompareFunction::LESS}
,{"LESS_EQUAL",cocos2d::backend::CompareFunction::LESS_EQUAL}
,{"GREATER",cocos2d::backend::CompareFunction::GREATER}
,{"GREATER_EQUAL",cocos2d::backend::CompareFunction::GREATER_EQUAL}
,{"EQUAL",cocos2d::backend::CompareFunction::EQUAL}
,{"NOT_EQUAL",cocos2d::backend::CompareFunction::NOT_EQUAL}
,{"ALWAYS",cocos2d::backend::CompareFunction::ALWAYS}
});}
void RegisterLuaBackendBlendOperationAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::BlendOperation>("BlendOperation",{
{"ADD",cocos2d::backend::BlendOperation::ADD}
,{"SUBTRACT",cocos2d::backend::BlendOperation::SUBTRACT}
,{"RESERVE_SUBTRACT",cocos2d::backend::BlendOperation::RESERVE_SUBTRACT}
});}
void RegisterLuaBackendBlendFactorAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::BlendFactor>("BlendFactor",{
{"ZERO",cocos2d::backend::BlendFactor::ZERO}
,{"ONE",cocos2d::backend::BlendFactor::ONE}
,{"SRC_COLOR",cocos2d::backend::BlendFactor::SRC_COLOR}
,{"ONE_MINUS_SRC_COLOR",cocos2d::backend::BlendFactor::ONE_MINUS_SRC_COLOR}
,{"SRC_ALPHA",cocos2d::backend::BlendFactor::SRC_ALPHA}
,{"ONE_MINUS_SRC_ALPHA",cocos2d::backend::BlendFactor::ONE_MINUS_SRC_ALPHA}
,{"DST_COLOR",cocos2d::backend::BlendFactor::DST_COLOR}
,{"ONE_MINUS_DST_COLOR",cocos2d::backend::BlendFactor::ONE_MINUS_DST_COLOR}
,{"DST_ALPHA",cocos2d::backend::BlendFactor::DST_ALPHA}
,{"ONE_MINUS_DST_ALPHA",cocos2d::backend::BlendFactor::ONE_MINUS_DST_ALPHA}
,{"CONSTANT_ALPHA",cocos2d::backend::BlendFactor::CONSTANT_ALPHA}
,{"SRC_ALPHA_SATURATE",cocos2d::backend::BlendFactor::SRC_ALPHA_SATURATE}
,{"ONE_MINUS_CONSTANT_ALPHA",cocos2d::backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA}
,{"BLEND_CLOLOR",cocos2d::backend::BlendFactor::BLEND_CLOLOR}
});}
void RegisterLuaBackendColorWriteMaskAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::ColorWriteMask>("ColorWriteMask",{
{"RED_BIT",cocos2d::backend::ColorWriteMask::RED_BIT}
,{"GREEN_BIT",cocos2d::backend::ColorWriteMask::GREEN_BIT}
,{"BLUE_BIT",cocos2d::backend::ColorWriteMask::BLUE_BIT}
,{"ALPHA_BIT",cocos2d::backend::ColorWriteMask::ALPHA_BIT}
,{"NONE",cocos2d::backend::ColorWriteMask::NONE}
,{"RED",cocos2d::backend::ColorWriteMask::RED}
,{"GREEN",cocos2d::backend::ColorWriteMask::GREEN}
,{"BLUE",cocos2d::backend::ColorWriteMask::BLUE}
,{"ALPHA",cocos2d::backend::ColorWriteMask::ALPHA}
,{"ALL",cocos2d::backend::ColorWriteMask::ALL}
});}
void RegisterLuaBackendCullModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::CullMode>("CullMode",{
{"NONE",cocos2d::backend::CullMode::NONE}
,{"BACK",cocos2d::backend::CullMode::BACK}
,{"FRONT",cocos2d::backend::CullMode::FRONT}
});}
void RegisterLuaBackendWindingAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::Winding>("Winding",{
{"CLOCK_WISE",cocos2d::backend::Winding::CLOCK_WISE}
,{"COUNTER_CLOCK_WISE",cocos2d::backend::Winding::COUNTER_CLOCK_WISE}
});}
void RegisterLuaBackendTextureCubeFaceAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccb"];
pTable.new_enum<cocos2d::backend::TextureCubeFace>("TextureCubeFace",{
{"POSITIVE_X",cocos2d::backend::TextureCubeFace::POSITIVE_X}
,{"NEGATIVE_X",cocos2d::backend::TextureCubeFace::NEGATIVE_X}
,{"POSITIVE_Y",cocos2d::backend::TextureCubeFace::POSITIVE_Y}
,{"NEGATIVE_Y",cocos2d::backend::TextureCubeFace::NEGATIVE_Y}
,{"POSITIVE_Z",cocos2d::backend::TextureCubeFace::POSITIVE_Z}
,{"NEGATIVE_Z",cocos2d::backend::TextureCubeFace::NEGATIVE_Z}
});}
