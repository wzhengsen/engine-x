#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
extern void RegisterLuaPhysicsPhysicsShapeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeCircleAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapePolygonAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeBoxAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsBodyAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsContactAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsContactPreSolveAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsContactPostSolveAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointFixedAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointLimitAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointPinAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointDistanceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointSpringAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointGrooveAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointRotarySpringAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointRotaryLimitAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointRatchetAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointGearAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsJointMotorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaPhysicsPhysicsWorldAuto(cocos2d::extension::Lua&);
void RegisterLuaPhysicsAuto(cocos2d::extension::Lua& lua){
#if CC_USE_PHYSICS
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaPhysicsPhysicsShapeAuto(lua);
RegisterLuaPhysicsPhysicsShapeCircleAuto(lua);
RegisterLuaPhysicsPhysicsShapePolygonAuto(lua);
RegisterLuaPhysicsPhysicsShapeBoxAuto(lua);
RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(lua);
RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(lua);
RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(lua);
RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(lua);
RegisterLuaPhysicsPhysicsBodyAuto(lua);
RegisterLuaPhysicsPhysicsContactAuto(lua);
RegisterLuaPhysicsPhysicsContactPreSolveAuto(lua);
RegisterLuaPhysicsPhysicsContactPostSolveAuto(lua);
RegisterLuaPhysicsEventListenerPhysicsContactAuto(lua);
RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(lua);
RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(lua);
RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(lua);
RegisterLuaPhysicsPhysicsJointAuto(lua);
RegisterLuaPhysicsPhysicsJointFixedAuto(lua);
RegisterLuaPhysicsPhysicsJointLimitAuto(lua);
RegisterLuaPhysicsPhysicsJointPinAuto(lua);
RegisterLuaPhysicsPhysicsJointDistanceAuto(lua);
RegisterLuaPhysicsPhysicsJointSpringAuto(lua);
RegisterLuaPhysicsPhysicsJointGrooveAuto(lua);
RegisterLuaPhysicsPhysicsJointRotarySpringAuto(lua);
RegisterLuaPhysicsPhysicsJointRotaryLimitAuto(lua);
RegisterLuaPhysicsPhysicsJointRatchetAuto(lua);
RegisterLuaPhysicsPhysicsJointGearAuto(lua);
RegisterLuaPhysicsPhysicsJointMotorAuto(lua);
RegisterLuaPhysicsPhysicsWorldAuto(lua);
#endif
}