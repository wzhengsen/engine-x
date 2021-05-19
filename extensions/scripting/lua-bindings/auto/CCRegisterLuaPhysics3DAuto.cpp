#include "scripting/lua-bindings/auto/CCRegisterLuaPhysics3DAuto.hpp"
#include "physics3d/CCPhysics3D.h"
void RegisterLuaPhysics3DAuto(cocos2d::extension::Lua& lua){
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
lua["cc"]=lua.get_or("cc",lua.create_table());
#endif
}