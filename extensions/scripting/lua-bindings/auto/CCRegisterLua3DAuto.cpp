#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
namespace cocos2d{
extern void RegisterLua3DAnimation3DAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DAnimate3DAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DTextureCubeAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DAttachNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DBillBoardAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DMeshAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DSkeleton3DAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DSkyboxAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DSprite3DAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DSprite3DCacheAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DSprite3DMaterialAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DTerrainAuto(cocos2d::extension::Lua&);
extern void RegisterLua3DBundle3DAuto(cocos2d::extension::Lua&);
void RegisterLua3DAuto(cocos2d::extension::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLua3DAnimation3DAuto(lua);
RegisterLua3DAnimate3DAuto(lua);
RegisterLua3DTextureCubeAuto(lua);
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
}