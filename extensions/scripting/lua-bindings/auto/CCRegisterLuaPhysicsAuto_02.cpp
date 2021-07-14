#include "scripting/lua-bindings/auto/CCRegisterLuaPhysicsAuto.hpp"
#include "cocos2d.h"
#if CC_USE_PHYSICS
namespace cocos2d{
void RegisterLuaPhysicsPhysicsJointDistanceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointDistance).name()] = sol::usertype_traits<cocos2d::PhysicsJointDistance*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointDistance>("deprecated.cocos2d::PhysicsJointDistance");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointDistance*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointDistance"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointDistance*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointDistance::construct);
mt["GetDistance"]=static_cast<float(cocos2d::PhysicsJointDistance::*)()const>(&cocos2d::PhysicsJointDistance::getDistance);
mt["get"]["Distance"]=mt["GetDistance"];
mt["SetDistance"]=static_cast<void(cocos2d::PhysicsJointDistance::*)(float)>(&cocos2d::PhysicsJointDistance::setDistance);
mt["set"]["Distance"]=mt["SetDistance"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointDistance::*)()>(&cocos2d::PhysicsJointDistance::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointSpringAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointSpring).name()] = sol::usertype_traits<cocos2d::PhysicsJointSpring*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointSpring>("deprecated.cocos2d::PhysicsJointSpring");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointSpring*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointSpring"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointSpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,float,float)>(&cocos2d::PhysicsJointSpring::construct);
mt["GetAnchr1"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr1);
mt["get"]["Anchr1"]=mt["GetAnchr1"];
mt["SetAnchr1"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr1);
mt["set"]["Anchr1"]=mt["SetAnchr1"];
mt["GetAnchr2"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getAnchr2);
mt["get"]["Anchr2"]=mt["GetAnchr2"];
mt["SetAnchr2"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointSpring::setAnchr2);
mt["set"]["Anchr2"]=mt["SetAnchr2"];
mt["GetRestLength"]=static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getRestLength);
mt["get"]["RestLength"]=mt["GetRestLength"];
mt["SetRestLength"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setRestLength);
mt["set"]["RestLength"]=mt["SetRestLength"];
mt["GetStiffness"]=static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getStiffness);
mt["get"]["Stiffness"]=mt["GetStiffness"];
mt["SetStiffness"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setStiffness);
mt["set"]["Stiffness"]=mt["SetStiffness"];
mt["GetDamping"]=static_cast<float(cocos2d::PhysicsJointSpring::*)()const>(&cocos2d::PhysicsJointSpring::getDamping);
mt["get"]["Damping"]=mt["GetDamping"];
mt["SetDamping"]=static_cast<void(cocos2d::PhysicsJointSpring::*)(float)>(&cocos2d::PhysicsJointSpring::setDamping);
mt["set"]["Damping"]=mt["SetDamping"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointSpring::*)()>(&cocos2d::PhysicsJointSpring::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointGrooveAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointGroove).name()] = sol::usertype_traits<cocos2d::PhysicsJointGroove*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointGroove>("deprecated.cocos2d::PhysicsJointGroove");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointGroove*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointGroove"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointGroove*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::construct);
mt["GetGrooveA"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveA);
mt["get"]["GrooveA"]=mt["GetGrooveA"];
mt["SetGrooveA"]=static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveA);
mt["set"]["GrooveA"]=mt["SetGrooveA"];
mt["GetGrooveB"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getGrooveB);
mt["get"]["GrooveB"]=mt["GetGrooveB"];
mt["SetGrooveB"]=static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setGrooveB);
mt["set"]["GrooveB"]=mt["SetGrooveB"];
mt["GetAnchr2"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsJointGroove::*)()const>(&cocos2d::PhysicsJointGroove::getAnchr2);
mt["get"]["Anchr2"]=mt["GetAnchr2"];
mt["SetAnchr2"]=static_cast<void(cocos2d::PhysicsJointGroove::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsJointGroove::setAnchr2);
mt["set"]["Anchr2"]=mt["SetAnchr2"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointGroove::*)()>(&cocos2d::PhysicsJointGroove::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointRotarySpringAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointRotarySpring).name()] = sol::usertype_traits<cocos2d::PhysicsJointRotarySpring*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointRotarySpring>("deprecated.cocos2d::PhysicsJointRotarySpring");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointRotarySpring*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointRotarySpring"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointRotarySpring*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotarySpring::construct);
mt["GetRestAngle"]=static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getRestAngle);
mt["get"]["RestAngle"]=mt["GetRestAngle"];
mt["SetRestAngle"]=static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setRestAngle);
mt["set"]["RestAngle"]=mt["SetRestAngle"];
mt["GetStiffness"]=static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getStiffness);
mt["get"]["Stiffness"]=mt["GetStiffness"];
mt["SetStiffness"]=static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setStiffness);
mt["set"]["Stiffness"]=mt["SetStiffness"];
mt["GetDamping"]=static_cast<float(cocos2d::PhysicsJointRotarySpring::*)()const>(&cocos2d::PhysicsJointRotarySpring::getDamping);
mt["get"]["Damping"]=mt["GetDamping"];
mt["SetDamping"]=static_cast<void(cocos2d::PhysicsJointRotarySpring::*)(float)>(&cocos2d::PhysicsJointRotarySpring::setDamping);
mt["set"]["Damping"]=mt["SetDamping"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointRotarySpring::*)()>(&cocos2d::PhysicsJointRotarySpring::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointRotaryLimitAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointRotaryLimit).name()] = sol::usertype_traits<cocos2d::PhysicsJointRotaryLimit*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointRotaryLimit>("deprecated.cocos2d::PhysicsJointRotaryLimit");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointRotaryLimit*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointRotaryLimit"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=sol::overload(static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRotaryLimit::construct),static_cast<cocos2d::PhysicsJointRotaryLimit*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*)>(&cocos2d::PhysicsJointRotaryLimit::construct));
mt["GetMin"]=static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMin);
mt["get"]["Min"]=mt["GetMin"];
mt["SetMin"]=static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMin);
mt["set"]["Min"]=mt["SetMin"];
mt["GetMax"]=static_cast<float(cocos2d::PhysicsJointRotaryLimit::*)()const>(&cocos2d::PhysicsJointRotaryLimit::getMax);
mt["get"]["Max"]=mt["GetMax"];
mt["SetMax"]=static_cast<void(cocos2d::PhysicsJointRotaryLimit::*)(float)>(&cocos2d::PhysicsJointRotaryLimit::setMax);
mt["set"]["Max"]=mt["SetMax"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointRotaryLimit::*)()>(&cocos2d::PhysicsJointRotaryLimit::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointRatchetAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointRatchet).name()] = sol::usertype_traits<cocos2d::PhysicsJointRatchet*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointRatchet>("deprecated.cocos2d::PhysicsJointRatchet");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointRatchet*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointRatchet"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointRatchet*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointRatchet::construct);
mt["GetAngle"]=static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getAngle);
mt["get"]["Angle"]=mt["GetAngle"];
mt["SetAngle"]=static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setAngle);
mt["set"]["Angle"]=mt["SetAngle"];
mt["GetPhase"]=static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getPhase);
mt["get"]["Phase"]=mt["GetPhase"];
mt["SetPhase"]=static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setPhase);
mt["set"]["Phase"]=mt["SetPhase"];
mt["GetRatchet"]=static_cast<float(cocos2d::PhysicsJointRatchet::*)()const>(&cocos2d::PhysicsJointRatchet::getRatchet);
mt["get"]["Ratchet"]=mt["GetRatchet"];
mt["SetRatchet"]=static_cast<void(cocos2d::PhysicsJointRatchet::*)(float)>(&cocos2d::PhysicsJointRatchet::setRatchet);
mt["set"]["Ratchet"]=mt["SetRatchet"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointRatchet::*)()>(&cocos2d::PhysicsJointRatchet::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointGearAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointGear).name()] = sol::usertype_traits<cocos2d::PhysicsJointGear*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointGear>("deprecated.cocos2d::PhysicsJointGear");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointGear*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointGear"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointGear*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float,float)>(&cocos2d::PhysicsJointGear::construct);
mt["GetPhase"]=static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getPhase);
mt["get"]["Phase"]=mt["GetPhase"];
mt["SetPhase"]=static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setPhase);
mt["set"]["Phase"]=mt["SetPhase"];
mt["GetRatio"]=static_cast<float(cocos2d::PhysicsJointGear::*)()const>(&cocos2d::PhysicsJointGear::getRatio);
mt["get"]["Ratio"]=mt["GetRatio"];
mt["SetRatio"]=static_cast<void(cocos2d::PhysicsJointGear::*)(float)>(&cocos2d::PhysicsJointGear::setRatio);
mt["set"]["Ratio"]=mt["SetRatio"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointGear::*)()>(&cocos2d::PhysicsJointGear::createConstraints);
}
void RegisterLuaPhysicsPhysicsJointMotorAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsJointMotor).name()] = sol::usertype_traits<cocos2d::PhysicsJointMotor*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsJointMotor>("deprecated.cocos2d::PhysicsJointMotor");
dep[sol::base_classes]=sol::bases<cocos2d::PhysicsJoint>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsJointMotor*>::metatable(),sol::usertype_traits<cocos2d::PhysicsJoint*>::metatable());
lua["cc"]["PhysicsJointMotor"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["Construct"]=static_cast<cocos2d::PhysicsJointMotor*(*)(cocos2d::PhysicsBody*,cocos2d::PhysicsBody*,float)>(&cocos2d::PhysicsJointMotor::construct);
mt["GetRate"]=static_cast<float(cocos2d::PhysicsJointMotor::*)()const>(&cocos2d::PhysicsJointMotor::getRate);
mt["get"]["Rate"]=mt["GetRate"];
mt["SetRate"]=static_cast<void(cocos2d::PhysicsJointMotor::*)(float)>(&cocos2d::PhysicsJointMotor::setRate);
mt["set"]["Rate"]=mt["SetRate"];
mt["CreateConstraints"]=static_cast<bool(cocos2d::PhysicsJointMotor::*)()>(&cocos2d::PhysicsJointMotor::createConstraints);
}
void RegisterLuaPhysicsPhysicsWorldAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PhysicsWorld).name()] = sol::usertype_traits<cocos2d::PhysicsWorld*>::metatable();
auto dep=lua.new_usertype<cocos2d::PhysicsWorld>("deprecated.cocos2d::PhysicsWorld");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PhysicsWorld*>::metatable());
lua["cc"]["PhysicsWorld"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["AddJoint"]=static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsJoint*)>(&cocos2d::PhysicsWorld::addJoint);
mt["RemoveJoint"]=sol::overload([](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0,bool arg1){return obj->removeJoint(arg0,arg1);},[](cocos2d::PhysicsWorld* obj,cocos2d::PhysicsJoint* arg0){return obj->removeJoint(arg0);});
mt["RemoveAllJoints"]=sol::overload([](cocos2d::PhysicsWorld* obj,bool arg0){return obj->removeAllJoints(arg0);},[](cocos2d::PhysicsWorld* obj){return obj->removeAllJoints();});
mt["RemoveBody"]=sol::overload(static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::removeBody),static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsBody*)>(&cocos2d::PhysicsWorld::removeBody));
mt["RemoveAllBodies"]=static_cast<void(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::removeAllBodies);
mt["RayCast"]=static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsRayCastCallbackFunc,const cocos2d::Vec2&,const cocos2d::Vec2&,void*)>(&cocos2d::PhysicsWorld::rayCast);
mt["QueryRect"]=static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsQueryRectCallbackFunc,const cocos2d::Rect&,void*)>(&cocos2d::PhysicsWorld::queryRect);
mt["QueryPoint"]=static_cast<void(cocos2d::PhysicsWorld::*)(cocos2d::PhysicsQueryPointCallbackFunc,const cocos2d::Vec2&,void*)>(&cocos2d::PhysicsWorld::queryPoint);
mt["GetShapes"]=static_cast<cocos2d::Vector<cocos2d::PhysicsShape *>(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShapes);
mt["GetShape"]=static_cast<cocos2d::PhysicsShape*(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)const>(&cocos2d::PhysicsWorld::getShape);
mt["GetAllBodies"]=static_cast<const cocos2d::Vector<cocos2d::PhysicsBody *>&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getAllBodies);
mt["get"]["AllBodies"]=mt["GetAllBodies"];
mt["GetBody"]=static_cast<cocos2d::PhysicsBody*(cocos2d::PhysicsWorld::*)(int)const>(&cocos2d::PhysicsWorld::getBody);
mt["GetScene"]=static_cast<cocos2d::Scene&(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getScene);
mt["get"]["Scene"]=mt["GetScene"];
mt["GetGravity"]=static_cast<cocos2d::Vec2(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getGravity);
mt["get"]["Gravity"]=mt["GetGravity"];
mt["SetGravity"]=static_cast<void(cocos2d::PhysicsWorld::*)(const cocos2d::Vec2&)>(&cocos2d::PhysicsWorld::setGravity);
mt["set"]["Gravity"]=mt["SetGravity"];
mt["SetSpeed"]=static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::setSpeed);
mt["set"]["Speed"]=mt["SetSpeed"];
mt["GetSpeed"]=static_cast<float(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getSpeed);
mt["get"]["Speed"]=mt["GetSpeed"];
mt["SetUpdateRate"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setUpdateRate);
mt["set"]["UpdateRate"]=mt["SetUpdateRate"];
mt["GetUpdateRate"]=static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getUpdateRate);
mt["get"]["UpdateRate"]=mt["GetUpdateRate"];
mt["SetSubsteps"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setSubsteps);
mt["set"]["Substeps"]=mt["SetSubsteps"];
mt["GetSubsteps"]=static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getSubsteps);
mt["get"]["Substeps"]=mt["GetSubsteps"];
mt["SetFixedUpdateRate"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setFixedUpdateRate);
mt["set"]["FixedUpdateRate"]=mt["SetFixedUpdateRate"];
mt["GetFixedUpdateRate"]=static_cast<int(cocos2d::PhysicsWorld::*)()const>(&cocos2d::PhysicsWorld::getFixedUpdateRate);
mt["get"]["FixedUpdateRate"]=mt["GetFixedUpdateRate"];
mt["SetDebugDrawMask"]=static_cast<void(cocos2d::PhysicsWorld::*)(int)>(&cocos2d::PhysicsWorld::setDebugDrawMask);
mt["set"]["DebugDrawMask"]=mt["SetDebugDrawMask"];
mt["SetPreUpdateCallback"]=static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPreUpdateCallback);
mt["set"]["PreUpdateCallback"]=mt["SetPreUpdateCallback"];
mt["SetPostUpdateCallback"]=static_cast<void(cocos2d::PhysicsWorld::*)(const std::function<void ()>&)>(&cocos2d::PhysicsWorld::setPostUpdateCallback);
mt["set"]["PostUpdateCallback"]=mt["SetPostUpdateCallback"];
mt["GetDebugDrawMask"]=static_cast<int(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::getDebugDrawMask);
mt["get"]["DebugDrawMask"]=mt["GetDebugDrawMask"];
mt["SetAutoStep"]=static_cast<void(cocos2d::PhysicsWorld::*)(bool)>(&cocos2d::PhysicsWorld::setAutoStep);
mt["set"]["AutoStep"]=mt["SetAutoStep"];
mt["IsAutoStep"]=static_cast<bool(cocos2d::PhysicsWorld::*)()>(&cocos2d::PhysicsWorld::isAutoStep);
mt["get"]["AutoStep"]=mt["IsAutoStep"];
mt["Step"]=static_cast<void(cocos2d::PhysicsWorld::*)(float)>(&cocos2d::PhysicsWorld::step);
mt["static"]["get"]["DEBUGDRAW_NONE"]=[]()->const int&{return cocos2d::PhysicsWorld::DEBUGDRAW_NONE;};
mt["static"]["get"]["DEBUGDRAW_SHAPE"]=[]()->const int&{return cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE;};
mt["static"]["get"]["DEBUGDRAW_JOINT"]=[]()->const int&{return cocos2d::PhysicsWorld::DEBUGDRAW_JOINT;};
mt["static"]["get"]["DEBUGDRAW_CONTACT"]=[]()->const int&{return cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT;};
mt["static"]["get"]["DEBUGDRAW_ALL"]=[]()->const int&{return cocos2d::PhysicsWorld::DEBUGDRAW_ALL;};
}
}
#endif
