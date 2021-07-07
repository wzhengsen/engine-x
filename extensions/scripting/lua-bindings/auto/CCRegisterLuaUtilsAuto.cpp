#include "scripting/lua-bindings/auto/CCRegisterLuaUtilsAuto.hpp"
#include "base/ccUtils.h"
extern void RegisterLuaUtilsGetTimeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsgetTimeInMillisecondsAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsgetCascadeBoundingBoxAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilscreateSpriteFromBase64CachedAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilscreateSpriteFromBase64Auto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsgetLanguageTypeByISO2Auto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilstoBackendBlendFactorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilstoGLBlendFactorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilstoBackendSamplerFilterAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilstoBackendAddressModeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsparseIntegerListAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsBin2HexAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilskillCurrentProcessAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsConvertAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsGetClipboardAuto(cocos2d::extension::Lua&);
extern void RegisterLuaUtilsSetClipboardAuto(cocos2d::extension::Lua&);
void RegisterLuaUtilsAuto(cocos2d::extension::Lua& lua){
lua["ccu"]=lua.get_or("ccu",lua.create_table());
RegisterLuaUtilsGetTimeAuto(lua);
RegisterLuaUtilsgetTimeInMillisecondsAuto(lua);
RegisterLuaUtilsgetCascadeBoundingBoxAuto(lua);
RegisterLuaUtilscreateSpriteFromBase64CachedAuto(lua);
RegisterLuaUtilscreateSpriteFromBase64Auto(lua);
RegisterLuaUtilsgetLanguageTypeByISO2Auto(lua);
RegisterLuaUtilstoBackendBlendFactorAuto(lua);
RegisterLuaUtilstoGLBlendFactorAuto(lua);
RegisterLuaUtilstoBackendSamplerFilterAuto(lua);
RegisterLuaUtilstoBackendAddressModeAuto(lua);
RegisterLuaUtilsparseIntegerListAuto(lua);
RegisterLuaUtilsBin2HexAuto(lua);
RegisterLuaUtilskillCurrentProcessAuto(lua);
RegisterLuaUtilsConvertAuto(lua);
RegisterLuaUtilsGetClipboardAuto(lua);
RegisterLuaUtilsSetClipboardAuto(lua);
}