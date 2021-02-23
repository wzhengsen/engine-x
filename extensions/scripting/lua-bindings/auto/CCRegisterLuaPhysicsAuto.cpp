#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
extern void RegisterLuaPhysicsPhysicsShapeAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeCircleAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapePolygonAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeBoxAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgeSegmentAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgePolygonAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgeBoxAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsShapeEdgeChainAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsBodyAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsContactAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsContactPreSolveAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsContactPostSolveAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactWithBodiesAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactWithShapesAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsEventListenerPhysicsContactWithGroupAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointFixedAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointLimitAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointPinAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointDistanceAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointSpringAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointGrooveAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointRotarySpringAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointRotaryLimitAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointRatchetAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointGearAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsJointMotorAuto(cocos2d::Lua&);
extern void RegisterLuaPhysicsPhysicsWorldAuto(cocos2d::Lua&);
void RegisterLuaPhysicsAuto(cocos2d::Lua& lua){
#if CC_USE_PHYSICS
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