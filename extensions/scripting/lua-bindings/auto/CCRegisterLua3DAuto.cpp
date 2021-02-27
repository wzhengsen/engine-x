#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
extern void RegisterLua3DbackendProgramTypeAnonymousEnum__6471240522010613515_Auto(cocos2d::Lua&);
extern void RegisterLua3DTextureFormatEXTAnonymousEnum_328354290637961909_Auto(cocos2d::Lua&);
extern void RegisterLua3DTextureFlagAnonymousEnum_979699189084109002_Auto(cocos2d::Lua&);
extern void RegisterLua3DAnimation3DAuto(cocos2d::Lua&);
extern void RegisterLua3DAnimate3DAuto(cocos2d::Lua&);
extern void RegisterLua3DAnonymousEnum__584764158701715967_Auto(cocos2d::Lua&);
extern void RegisterLua3DTextureCubeAuto(cocos2d::Lua&);
extern void RegisterLua3DAnonymousEnum__778307205223700478_Auto(cocos2d::Lua&);
extern void RegisterLua3DAnonymousEnum__859397383549052567_Auto(cocos2d::Lua&);
extern void RegisterLua3DAnonymousEnum_1924853843510107983_Auto(cocos2d::Lua&);
extern void RegisterLua3DAnonymousEnum__6134653066911589495_Auto(cocos2d::Lua&);
extern void RegisterLua3DAnonymousEnum__7541095390690929856_Auto(cocos2d::Lua&);
extern void RegisterLua3DAttachNodeAuto(cocos2d::Lua&);
extern void RegisterLua3DBillBoardAuto(cocos2d::Lua&);
extern void RegisterLua3DMeshAuto(cocos2d::Lua&);
extern void RegisterLua3DSkeleton3DAuto(cocos2d::Lua&);
extern void RegisterLua3DSkyboxAuto(cocos2d::Lua&);
extern void RegisterLua3DSprite3DAuto(cocos2d::Lua&);
extern void RegisterLua3DSprite3DCacheAuto(cocos2d::Lua&);
extern void RegisterLua3DSprite3DMaterialAuto(cocos2d::Lua&);
extern void RegisterLua3DTerrainAuto(cocos2d::Lua&);
extern void RegisterLua3DBundle3DAuto(cocos2d::Lua&);
void RegisterLua3DAuto(cocos2d::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLua3DbackendProgramTypeAnonymousEnum__6471240522010613515_Auto(lua);
RegisterLua3DTextureFormatEXTAnonymousEnum_328354290637961909_Auto(lua);
RegisterLua3DTextureFlagAnonymousEnum_979699189084109002_Auto(lua);
RegisterLua3DAnimation3DAuto(lua);
RegisterLua3DAnimate3DAuto(lua);
RegisterLua3DAnonymousEnum__584764158701715967_Auto(lua);
RegisterLua3DTextureCubeAuto(lua);
RegisterLua3DAnonymousEnum__778307205223700478_Auto(lua);
RegisterLua3DAnonymousEnum__859397383549052567_Auto(lua);
RegisterLua3DAnonymousEnum_1924853843510107983_Auto(lua);
RegisterLua3DAnonymousEnum__6134653066911589495_Auto(lua);
RegisterLua3DAnonymousEnum__7541095390690929856_Auto(lua);
RegisterLua3DAttachNodeAuto(lua);
RegisterLua3DBillBoardAuto(lua);
RegisterLua3DMeshAuto(lua);
RegisterLua3DSkeleton3DAuto(lua);
RegisterLua3DSkyboxAuto(lua);
RegisterLua3DSprite3DAuto(lua);
RegisterLua3DSprite3DCacheAuto(lua);
RegisterLua3DSprite3DMaterialAuto(lua);
RegisterLua3DTerrainAuto(lua);
RegisterLua3DBundle3DAuto(lua);
}