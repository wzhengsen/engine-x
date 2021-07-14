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
extern void RegisterLuaBackendBufferUsageAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendBufferTypeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendShaderStageAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendVertexFormatAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendPixelFormatAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendTextureUsageAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendIndexFormatAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendVertexStepModeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendPrimitiveTypeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendTextureTypeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendSamplerAddressModeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendSamplerFilterAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendStencilOperationAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendCompareFunctionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendBlendOperationAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendBlendFactorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendColorWriteMaskAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendCullModeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendWindingAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendTextureCubeFaceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendShaderCacheAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendProgramAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendVertexLayoutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendProgramStateAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendTextureBackendAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendTexture2DBackendAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendTextureCubemapBackendAuto(cocos2d::extension::Lua&);
extern void RegisterLuaBackendDeviceAuto(cocos2d::extension::Lua&);
void RegisterLuaBackendAuto(cocos2d::extension::Lua& lua){
lua["ccb"]=lua.get_or("ccb",lua.create_table());
RegisterLuaBackendBufferUsageAuto(lua);
RegisterLuaBackendBufferTypeAuto(lua);
RegisterLuaBackendShaderStageAuto(lua);
RegisterLuaBackendVertexFormatAuto(lua);
RegisterLuaBackendPixelFormatAuto(lua);
RegisterLuaBackendTextureUsageAuto(lua);
RegisterLuaBackendIndexFormatAuto(lua);
RegisterLuaBackendVertexStepModeAuto(lua);
RegisterLuaBackendPrimitiveTypeAuto(lua);
RegisterLuaBackendTextureTypeAuto(lua);
RegisterLuaBackendSamplerAddressModeAuto(lua);
RegisterLuaBackendSamplerFilterAuto(lua);
RegisterLuaBackendStencilOperationAuto(lua);
RegisterLuaBackendCompareFunctionAuto(lua);
RegisterLuaBackendBlendOperationAuto(lua);
RegisterLuaBackendBlendFactorAuto(lua);
RegisterLuaBackendColorWriteMaskAuto(lua);
RegisterLuaBackendCullModeAuto(lua);
RegisterLuaBackendWindingAuto(lua);
RegisterLuaBackendTextureCubeFaceAuto(lua);
RegisterLuaBackendShaderCacheAuto(lua);
RegisterLuaBackendProgramAuto(lua);
RegisterLuaBackendVertexLayoutAuto(lua);
RegisterLuaBackendProgramStateAuto(lua);
RegisterLuaBackendTextureBackendAuto(lua);
RegisterLuaBackendTexture2DBackendAuto(lua);
RegisterLuaBackendTextureCubemapBackendAuto(lua);
RegisterLuaBackendDeviceAuto(lua);
}
}