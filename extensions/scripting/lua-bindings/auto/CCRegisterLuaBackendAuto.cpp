#include "scripting/lua-bindings/auto/CCRegisterLuaBackendAuto.hpp"
#include "renderer/backend/Types.h"
#include "renderer/backend/ProgramState.h"
#include "renderer/backend/Texture.h"
#include "renderer/backend/VertexLayout.h"
#include "renderer/backend/Device.h"
#include "renderer/backend/RenderTarget.h"
extern void RegisterLuaBackendBufferUsageAuto(cocos2d::Lua&);
extern void RegisterLuaBackendBufferTypeAuto(cocos2d::Lua&);
extern void RegisterLuaBackendShaderStageAuto(cocos2d::Lua&);
extern void RegisterLuaBackendVertexFormatAuto(cocos2d::Lua&);
extern void RegisterLuaBackendPixelFormatAuto(cocos2d::Lua&);
extern void RegisterLuaBackendTextureUsageAuto(cocos2d::Lua&);
extern void RegisterLuaBackendIndexFormatAuto(cocos2d::Lua&);
extern void RegisterLuaBackendVertexStepModeAuto(cocos2d::Lua&);
extern void RegisterLuaBackendPrimitiveTypeAuto(cocos2d::Lua&);
extern void RegisterLuaBackendTextureTypeAuto(cocos2d::Lua&);
extern void RegisterLuaBackendSamplerAddressModeAuto(cocos2d::Lua&);
extern void RegisterLuaBackendSamplerFilterAuto(cocos2d::Lua&);
extern void RegisterLuaBackendStencilOperationAuto(cocos2d::Lua&);
extern void RegisterLuaBackendCompareFunctionAuto(cocos2d::Lua&);
extern void RegisterLuaBackendBlendOperationAuto(cocos2d::Lua&);
extern void RegisterLuaBackendBlendFactorAuto(cocos2d::Lua&);
extern void RegisterLuaBackendColorWriteMaskAuto(cocos2d::Lua&);
extern void RegisterLuaBackendCullModeAuto(cocos2d::Lua&);
extern void RegisterLuaBackendWindingAuto(cocos2d::Lua&);
extern void RegisterLuaBackendTextureCubeFaceAuto(cocos2d::Lua&);
extern void RegisterLuaBackendProgramAuto(cocos2d::Lua&);
extern void RegisterLuaBackendVertexLayoutAuto(cocos2d::Lua&);
extern void RegisterLuaBackendProgramStateAuto(cocos2d::Lua&);
extern void RegisterLuaBackendTextureBackendAuto(cocos2d::Lua&);
extern void RegisterLuaBackendTexture2DBackendAuto(cocos2d::Lua&);
extern void RegisterLuaBackendTextureCubemapBackendAuto(cocos2d::Lua&);
extern void RegisterLuaBackendDeviceAuto(cocos2d::Lua&);
void RegisterLuaBackendAuto(cocos2d::Lua& lua){
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
RegisterLuaBackendProgramAuto(lua);
RegisterLuaBackendVertexLayoutAuto(lua);
RegisterLuaBackendProgramStateAuto(lua);
RegisterLuaBackendTextureBackendAuto(lua);
RegisterLuaBackendTexture2DBackendAuto(lua);
RegisterLuaBackendTextureCubemapBackendAuto(lua);
RegisterLuaBackendDeviceAuto(lua);
}