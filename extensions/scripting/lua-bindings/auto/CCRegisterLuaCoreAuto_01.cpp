#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
void RegisterLuaCoreComponentAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Component>("cc","Component",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Component*(*)()>(&cocos2d::Component::create));
mt.set_function("Init",static_cast<bool(cocos2d::Component::*)()>(&cocos2d::Component::init));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::Component::*)()const>(&cocos2d::Component::isEnabled));
mt.set_function("SetEnabled",static_cast<void(cocos2d::Component::*)(bool)>(&cocos2d::Component::setEnabled));
mt.set_function("GetName",static_cast<const std::string&(cocos2d::Component::*)()const>(&cocos2d::Component::getName));
mt.set_function("SetName",static_cast<void(cocos2d::Component::*)(const std::string&)>(&cocos2d::Component::setName));
mt.set_function("GetOwner",static_cast<cocos2d::Node*(cocos2d::Component::*)()const>(&cocos2d::Component::getOwner));
mt.set_function("SetOwner",static_cast<void(cocos2d::Component::*)(cocos2d::Node*)>(&cocos2d::Component::setOwner));
mt.set_function("Update",static_cast<void(cocos2d::Component::*)(float)>(&cocos2d::Component::update));
mt.set_function("Serialize",static_cast<bool(cocos2d::Component::*)(void*)>(&cocos2d::Component::serialize));
mt.set_function("OnEnter",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onExit));
mt.set_function("OnAdd",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onAdd));
mt.set_function("OnRemove",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onRemove));
}
void RegisterLuaCorePHYSICSSHAPE_MATERIAL_DEFAULTAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["PHYSICSSHAPE_MATERIAL_DEFAULT"] = cocos2d::PHYSICSSHAPE_MATERIAL_DEFAULT;
}

void RegisterLuaCorePHYSICSBODY_MATERIAL_DEFAULTAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["PHYSICSBODY_MATERIAL_DEFAULT"] = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT;
}

void RegisterLuaCoreNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Node>("cc","Node",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Node*(*)()>(&cocos2d::Node::create));
mt.set_function("GetAttachedNodeCount",static_cast<int(*)()>(&cocos2d::Node::getAttachedNodeCount));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::Node::*)()const>(&cocos2d::Node::getDescription));
mt.set_function("SetLocalZOrder",static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::setLocalZOrder));
mt.set_function("SetLocalZOrder",static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::_setLocalZOrder));
mt.set_function("UpdateOrderOfArrival",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateOrderOfArrival));
mt.set_function("GetLocalZOrder",static_cast<int32_t(cocos2d::Node::*)()const>(&cocos2d::Node::getLocalZOrder));
mt.set_function("SetGlobalZOrder",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setGlobalZOrder));
mt.set_function("GetGlobalZOrder",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getGlobalZOrder));
mt.set_function("SetScaleX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleX));
mt.set_function("GetScaleX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleX));
mt.set_function("SetScaleY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleY));
mt.set_function("GetScaleY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleY));
mt.set_function("SetScaleZ",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleZ));
mt.set_function("GetScaleZ",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleZ));
mt.set_function("SetScale",sol::overload(static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setScale),static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScale)));
mt.set_function("GetScale",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScale));
mt.set_function("SetPosition",sol::overload(static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setPosition),static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPosition)));
mt.set_function("SetPositionNormalized",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPositionNormalized));
mt.set_function("SetNormalizedPosition",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setNormalizedPosition));
mt.set_function("GetPosition",sol::overload(static_cast<void(cocos2d::Node::*)(float*,float*)const>(&cocos2d::Node::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPosition)));
mt.set_function("GetPositionXY",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionXY));
mt.set_function("GetPositionNormalized",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionNormalized));
mt.set_function("GetNormalizedPosition",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getNormalizedPosition));
mt.set_function("SetPositionX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionX));
mt.set_function("GetPositionX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionX));
mt.set_function("SetPositionY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionY));
mt.set_function("GetPositionY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionY));
mt.set_function("SetPosition3D",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setPosition3D));
mt.set_function("GetPosition3D",static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getPosition3D));
mt.set_function("SetPositionZ",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionZ));
mt.set_function("GetPositionZ",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionZ));
mt.set_function("SetSkewX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewX));
mt.set_function("GetSkewX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewX));
mt.set_function("SetSkewY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewY));
mt.set_function("GetSkewY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewY));
mt.set_function("SetAnchorPoint",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setAnchorPoint));
mt.set_function("GetAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPoint));
mt.set_function("GetAnchorPointInPoints",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPointInPoints));
mt.set_function("SetContentSize",static_cast<void(cocos2d::Node::*)(const cocos2d::Size&)>(&cocos2d::Node::setContentSize));
mt.set_function("GetContentSize",static_cast<const cocos2d::Size&(cocos2d::Node::*)()const>(&cocos2d::Node::getContentSize));
mt.set_function("GetContentWidth",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentWidth));
mt.set_function("GetContentHeight",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentHeight));
mt.set_function("SetContentWidth",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentWidth));
mt.set_function("SetContentHeight",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentHeight));
mt.set_function("SetVisible",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setVisible));
mt.set_function("IsVisible",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isVisible));
mt.set_function("SetRotation",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotation));
mt.set_function("GetRotation",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation));
mt.set_function("SetRotation3D",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setRotation3D));
mt.set_function("GetRotation3D",static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation3D));
mt.set_function("SetRotationQuat",static_cast<void(cocos2d::Node::*)(const cocos2d::Quaternion&)>(&cocos2d::Node::setRotationQuat));
mt.set_function("GetRotationQuat",static_cast<cocos2d::Quaternion(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationQuat));
mt.set_function("SetRotationSkewX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewX));
mt.set_function("GetRotationSkewX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewX));
mt.set_function("SetRotationSkewY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewY));
mt.set_function("GetRotationSkewY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewY));
mt.set_function("SetIgnoreAnchorPointForPosition",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setIgnoreAnchorPointForPosition));
mt.set_function("IsIgnoreAnchorPointForPosition",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isIgnoreAnchorPointForPosition));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Node::addChild)));
mt.set_function("GetChildByTag",static_cast<cocos2d::Node*(cocos2d::Node::*)(int)const>(&cocos2d::Node::getChildByTag));
mt.set_function("GetChildByName",static_cast<cocos2d::Node*(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::getChildByName));
mt.set_function("EnumerateChildren",static_cast<void(cocos2d::Node::*)(const std::string&,std::function<bool (cocos2d::Node *)>)const>(&cocos2d::Node::enumerateChildren));
mt.set_function("GetChildren",sol::overload(static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()const>(&cocos2d::Node::getChildren),static_cast<cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()>(&cocos2d::Node::getChildren)));
mt.set_function("GetChildrenCount",static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getChildrenCount));
mt.set_function("SetParent",static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::setParent));
mt.set_function("GetParent",sol::overload(static_cast<const cocos2d::Node*(cocos2d::Node::*)()const>(&cocos2d::Node::getParent),static_cast<cocos2d::Node*(cocos2d::Node::*)()>(&cocos2d::Node::getParent)));
mt.set_function("RemoveFromParent",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeFromParent));
mt.set_function("RemoveFromParentAndCleanup",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeFromParentAndCleanup));
mt.set_function("RemoveChild",sol::overload([](cocos2d::Node* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Node* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("RemoveChildByTag",sol::overload([](cocos2d::Node* obj,int arg0){return obj->removeChildByTag(arg0);},[](cocos2d::Node* obj,int arg0,bool arg1){return obj->removeChildByTag(arg0,arg1);}));
mt.set_function("RemoveChildByName",sol::overload([](cocos2d::Node* obj,const std::string& arg0){return obj->removeChildByName(arg0);},[](cocos2d::Node* obj,const std::string& arg0,bool arg1){return obj->removeChildByName(arg0,arg1);}));
mt.set_function("RemoveAllChildren",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllChildren));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeAllChildrenWithCleanup));
mt.set_function("ReorderChild",static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::reorderChild));
mt.set_function("SortAllChildren",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::sortAllChildren));
mt.set_function("GetTag",static_cast<int(cocos2d::Node::*)()const>(&cocos2d::Node::getTag));
mt.set_function("SetTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::setTag));
mt.set_function("GetName",static_cast<const std::string&(cocos2d::Node::*)()const>(&cocos2d::Node::getName));
mt.set_function("SetName",static_cast<void(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::setName));
mt.set_function("GetUserData",sol::overload(static_cast<const void*(cocos2d::Node::*)()const>(&cocos2d::Node::getUserData),static_cast<void*(cocos2d::Node::*)()>(&cocos2d::Node::getUserData)));
mt.set_function("SetUserData",static_cast<void(cocos2d::Node::*)(void*)>(&cocos2d::Node::setUserData));
mt.set_function("GetUserObject",sol::overload(static_cast<const cocos2d::Ref*(cocos2d::Node::*)()const>(&cocos2d::Node::getUserObject),static_cast<cocos2d::Ref*(cocos2d::Node::*)()>(&cocos2d::Node::getUserObject)));
mt.set_function("SetUserObject",static_cast<void(cocos2d::Node::*)(cocos2d::Ref*)>(&cocos2d::Node::setUserObject));
mt.set_function("IsRunning",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isRunning));
mt.set_function("OnEnter",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onEnter));
mt.set_function("OnEnterTransitionDidFinish",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onEnterTransitionDidFinish));
mt.set_function("OnExit",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onExit));
mt.set_function("OnExitTransitionDidStart",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onExitTransitionDidStart));
mt.set_function("Cleanup",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::cleanup));
mt.set_function("Draw",sol::overload(static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::draw),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::draw)));
mt.set_function("Visit",sol::overload(static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::visit),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::visit)));
mt.set_function("GetScene",static_cast<cocos2d::Scene*(cocos2d::Node::*)()const>(&cocos2d::Node::getScene));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocos2d::Node::*)()const>(&cocos2d::Node::getBoundingBox));
mt.set_function("SetEventDispatcher",static_cast<void(cocos2d::Node::*)(cocos2d::EventDispatcher*)>(&cocos2d::Node::setEventDispatcher));
mt.set_function("GetEventDispatcher",static_cast<cocos2d::EventDispatcher*(cocos2d::Node::*)()const>(&cocos2d::Node::getEventDispatcher));
mt.set_function("SetActionManager",static_cast<void(cocos2d::Node::*)(cocos2d::ActionManager*)>(&cocos2d::Node::setActionManager));
mt.set_function("GetActionManager",sol::overload(static_cast<const cocos2d::ActionManager*(cocos2d::Node::*)()const>(&cocos2d::Node::getActionManager),static_cast<cocos2d::ActionManager*(cocos2d::Node::*)()>(&cocos2d::Node::getActionManager)));
mt.set_function("RunAction",static_cast<cocos2d::Action*(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::runAction));
mt.set_function("StopAllActions",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::stopAllActions));
mt.set_function("StopAction",static_cast<void(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::stopAction));
mt.set_function("StopActionByTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopActionByTag));
mt.set_function("StopAllActionsByTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopAllActionsByTag));
mt.set_function("StopActionsByFlags",static_cast<void(cocos2d::Node::*)(unsigned int)>(&cocos2d::Node::stopActionsByFlags));
mt.set_function("GetActionByTag",static_cast<cocos2d::Action*(cocos2d::Node::*)(int)>(&cocos2d::Node::getActionByTag));
mt.set_function("GetNumberOfRunningActions",static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getNumberOfRunningActions));
mt.set_function("GetNumberOfRunningActionsByTag",static_cast<ssize_t(cocos2d::Node::*)(int)const>(&cocos2d::Node::getNumberOfRunningActionsByTag));
mt.set_function("SetScheduler",static_cast<void(cocos2d::Node::*)(cocos2d::Scheduler*)>(&cocos2d::Node::setScheduler));
mt.set_function("GetScheduler",sol::overload(static_cast<const cocos2d::Scheduler*(cocos2d::Node::*)()const>(&cocos2d::Node::getScheduler),static_cast<cocos2d::Scheduler*(cocos2d::Node::*)()>(&cocos2d::Node::getScheduler)));
mt.set_function("IsScheduled",sol::overload(static_cast<bool(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::isScheduled),static_cast<bool(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)const>(&cocos2d::Node::isScheduled)));
mt.set_function("ScheduleUpdate",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::scheduleUpdate));
mt.set_function("ScheduleUpdateWithPriority",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::scheduleUpdateWithPriority));
mt.set_function("UnscheduleUpdate",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::unscheduleUpdate));
mt.set_function("Schedule",sol::overload(static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE,float)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE,float,unsigned int,float)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,const std::string&)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,float,const std::string&)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,float,unsigned int,float,const std::string&)>(&cocos2d::Node::schedule)));
mt.set_function("ScheduleOnce",sol::overload(static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,float,const std::string&)>(&cocos2d::Node::scheduleOnce),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE,float)>(&cocos2d::Node::scheduleOnce)));
mt.set_function("Unschedule",sol::overload(static_cast<void(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::unschedule),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)>(&cocos2d::Node::unschedule)));
mt.set_function("UnscheduleAllCallbacks",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::unscheduleAllCallbacks));
mt.set_function("Resume",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::resume));
mt.set_function("Pause",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::pause));
mt.set_function("Update",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::update));
mt.set_function("UpdateTransform",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateTransform));
mt.set_function("GetNodeToParentTransform",sol::overload(static_cast<cocos2d::Mat4(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentTransform),static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentTransform)));
mt.set_function("GetNodeToParentAffineTransform",sol::overload(static_cast<cocos2d::AffineTransform(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentAffineTransform),static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentAffineTransform)));
mt.set_function("SetNodeToParentTransform",static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4&)>(&cocos2d::Node::setNodeToParentTransform));
mt.set_function("GetParentToNodeTransform",static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeTransform));
mt.set_function("GetParentToNodeAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeAffineTransform));
mt.set_function("GetNodeToWorldTransform",static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldTransform));
mt.set_function("GetNodeToWorldAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldAffineTransform));
mt.set_function("GetWorldToNodeTransform",static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeTransform));
mt.set_function("GetWorldToNodeAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeAffineTransform));
mt.set_function("ConvertToNodeSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpace));
mt.set_function("ConvertToWorldSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpace));
mt.set_function("ConvertToNodeSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpaceAR));
mt.set_function("ConvertToWorldSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpaceAR));
mt.set_function("ConvertTouchToNodeSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpace));
mt.set_function("ConvertTouchToNodeSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpaceAR));
mt.set_function("SetAdditionalTransform",sol::overload(static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4&)>(&cocos2d::Node::setAdditionalTransform),static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4*)>(&cocos2d::Node::setAdditionalTransform),static_cast<void(cocos2d::Node::*)(const cocos2d::AffineTransform&)>(&cocos2d::Node::setAdditionalTransform)));
mt.set_function("GetComponent",static_cast<cocos2d::Component*(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::getComponent));
mt.set_function("AddComponent",static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::addComponent));
mt.set_function("RemoveComponent",sol::overload(static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::removeComponent),static_cast<bool(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::removeComponent)));
mt.set_function("RemoveAllComponents",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllComponents));
mt.set_function("GetOpacity",static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getOpacity));
mt.set_function("GetDisplayedOpacity",static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedOpacity));
mt.set_function("SetOpacity",static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::setOpacity));
mt.set_function("UpdateDisplayedOpacity",static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::updateDisplayedOpacity));
mt.set_function("IsCascadeOpacityEnabled",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeOpacityEnabled));
mt.set_function("SetCascadeOpacityEnabled",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeOpacityEnabled));
mt.set_function("GetColor",static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getColor));
mt.set_function("GetDisplayedColor",static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedColor));
mt.set_function("SetColor",static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::setColor));
mt.set_function("UpdateDisplayedColor",static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::updateDisplayedColor));
mt.set_function("IsCascadeColorEnabled",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeColorEnabled));
mt.set_function("SetCascadeColorEnabled",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeColorEnabled));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setOpacityModifyRGB));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isOpacityModifyRGB));
mt.set_function("SetOnEnterHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnEnterHandler));
mt.set_function("GetOnEnterHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnEnterHandler));
mt.set_function("SetOnExitHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnExitHandler));
mt.set_function("GetOnExitHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnExitHandler));
mt.set_function("SetOnEnterTransitionDidFinishHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnEnterTransitionDidFinishHandler));
mt.set_function("GetOnEnterTransitionDidFinishHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnEnterTransitionDidFinishHandler));
mt.set_function("SetOnExitTransitionDidStartHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnExitTransitionDidStartHandler));
mt.set_function("GetOnExitTransitionDidStartHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnExitTransitionDidStartHandler));
mt.set_function("SetOnCleanUpHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnCleanUpHandler));
mt.set_function("GetOnCleanUpHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnCleanUpHandler));
mt.set_function("SetOnUpdateHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnUpdateHandler));
mt.set_function("GetOnUpdateHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnUpdateHandler));
mt.set_function("GetCameraMask",static_cast<unsigned short(cocos2d::Node::*)()const>(&cocos2d::Node::getCameraMask));
mt.set_function("SetCameraMask",sol::overload([](cocos2d::Node* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Node* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("SetProgramState",sol::overload([](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);},static_cast<void(cocos2d::Node::*)(uint32_t)>(&cocos2d::Node::setProgramState)));
mt.set_function("SetProgramStateWithRegistry",static_cast<void(cocos2d::Node::*)(uint32_t,cocos2d::Texture2D*)>(&cocos2d::Node::setProgramStateWithRegistry));
mt.set_function("GetProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Node::*)()const>(&cocos2d::Node::getProgramState));
mt.set_function("UpdateProgramStateTexture",static_cast<void(cocos2d::Node::*)(cocos2d::Texture2D*)>(&cocos2d::Node::updateProgramStateTexture));
mt.set_function("SetPhysicsBody",static_cast<void(cocos2d::Node::*)(cocos2d::PhysicsBody*)>(&cocos2d::Node::setPhysicsBody));
mt.set_function("GetPhysicsBody",static_cast<cocos2d::PhysicsBody*(cocos2d::Node::*)()const>(&cocos2d::Node::getPhysicsBody));
mt["INVALID_TAG"]=sol::var(std::ref(cocos2d::Node::INVALID_TAG));
mt["AttachedNodeCount"]=sol::var(std::ref(cocos2d::Node::__attachedNodeCount));
}
void RegisterLuaCoreSceneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Scene>("cc","Scene",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::create));
mt.set_function("CreateWithSize",static_cast<cocos2d::Scene*(*)(const cocos2d::Size&)>(&cocos2d::Scene::createWithSize));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDescription));
mt.set_function("GetCameras",static_cast<const std::vector<cocos2d::Camera *, std::allocator<cocos2d::Camera *> >&(cocos2d::Scene::*)()>(&cocos2d::Scene::getCameras));
mt.set_function("GetDefaultCamera",static_cast<cocos2d::Camera*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDefaultCamera));
mt.set_function("GetLights",static_cast<const std::vector<cocos2d::BaseLight *, std::allocator<cocos2d::BaseLight *> >&(cocos2d::Scene::*)()const>(&cocos2d::Scene::getLights));
mt.set_function("Render",sol::overload([](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1){return obj->render(arg0,arg1);},[](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1,const cocos2d::Mat4* arg2){return obj->render(arg0,arg1,arg2);}));
mt.set_function("RemoveAllChildren",static_cast<void(cocos2d::Scene::*)()>(&cocos2d::Scene::removeAllChildren));
mt.set_function("GetPhysicsWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getPhysicsWorld));
mt.set_function("CreateWithPhysics",static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::createWithPhysics));
mt.set_function("SetNavMesh",static_cast<void(cocos2d::Scene::*)(cocos2d::NavMesh*)>(&cocos2d::Scene::setNavMesh));
mt.set_function("GetNavMesh",static_cast<cocos2d::NavMesh*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getNavMesh));
mt.set_function("SetNavMeshDebugCamera",static_cast<void(cocos2d::Scene::*)(cocos2d::Camera*)>(&cocos2d::Scene::setNavMeshDebugCamera));
mt.set_function("StepPhysicsAndNavigation",static_cast<void(cocos2d::Scene::*)(float)>(&cocos2d::Scene::stepPhysicsAndNavigation));
}
void RegisterLuaCoreEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Event"];
pTable.new_enum<cocos2d::Event::Type>("Type",{
{"TOUCH",cocos2d::Event::Type::TOUCH}
,{"KEYBOARD",cocos2d::Event::Type::KEYBOARD}
,{"ACCELERATION",cocos2d::Event::Type::ACCELERATION}
,{"MOUSE",cocos2d::Event::Type::MOUSE}
,{"FOCUS",cocos2d::Event::Type::FOCUS}
,{"GAME_CONTROLLER",cocos2d::Event::Type::GAME_CONTROLLER}
,{"CUSTOM",cocos2d::Event::Type::CUSTOM}
});}
void RegisterLuaCoreEventAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Event>("cc","Event",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetType",static_cast<cocos2d::Event::Type(cocos2d::Event::*)()const>(&cocos2d::Event::getType));
mt.set_function("StopPropagation",static_cast<void(cocos2d::Event::*)()>(&cocos2d::Event::stopPropagation));
mt.set_function("IsStopped",static_cast<bool(cocos2d::Event::*)()const>(&cocos2d::Event::isStopped));
mt.set_function("GetCurrentTarget",static_cast<cocos2d::Node*(cocos2d::Event::*)()>(&cocos2d::Event::getCurrentTarget));
RegisterLuaCoreEventTypeAuto(lua);
}
void RegisterLuaCoreEventTouchEventCodeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventTouch"];
pTable.new_enum<cocos2d::EventTouch::EventCode>("EventCode",{
{"BEGAN",cocos2d::EventTouch::EventCode::BEGAN}
,{"MOVED",cocos2d::EventTouch::EventCode::MOVED}
,{"ENDED",cocos2d::EventTouch::EventCode::ENDED}
,{"CANCELLED",cocos2d::EventTouch::EventCode::CANCELLED}
});}
void RegisterLuaCoreEventTouchAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventTouch>("cc","EventTouch",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetEventCode",static_cast<cocos2d::EventTouch::EventCode(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getEventCode));
mt.set_function("GetTouches",static_cast<const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getTouches));
mt.set_function("SetEventCode",static_cast<void(cocos2d::EventTouch::*)(cocos2d::EventTouch::EventCode)>(&cocos2d::EventTouch::setEventCode));
mt.set_function("SetTouches",static_cast<void(cocos2d::EventTouch::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&)>(&cocos2d::EventTouch::setTouches));
mt[sol::call_constructor]=sol::constructors<cocos2d::EventTouch()>();
mt["MAX_TOUCHES"]=sol::var(std::ref(cocos2d::EventTouch::MAX_TOUCHES));
RegisterLuaCoreEventTouchEventCodeAuto(lua);
}
void RegisterLuaCoreResolutionPolicyAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::ResolutionPolicy>("ResolutionPolicy",{
{"EXACT_FIT",cocos2d::ResolutionPolicy::EXACT_FIT}
,{"NO_BORDER",cocos2d::ResolutionPolicy::NO_BORDER}
,{"SHOW_ALL",cocos2d::ResolutionPolicy::SHOW_ALL}
,{"FIXED_HEIGHT",cocos2d::ResolutionPolicy::FIXED_HEIGHT}
,{"FIXED_WIDTH",cocos2d::ResolutionPolicy::FIXED_WIDTH}
,{"UNKNOWN",cocos2d::ResolutionPolicy::UNKNOWN}
});}
void RegisterLuaCoreGLViewAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GLView>("cc","GLView",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("End",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::end));
mt.set_function("IsOpenGLReady",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isOpenGLReady));
mt.set_function("SwapBuffers",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::swapBuffers));
mt.set_function("SetIMEKeyboardState",static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setIMEKeyboardState));
mt.set_function("WindowShouldClose",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::windowShouldClose));
mt.set_function("SetGLContextAttrs",static_cast<void(*)(GLContextAttrs&)>(&cocos2d::GLView::setGLContextAttrs));
mt.set_function("GetGLContextAttrs",static_cast<GLContextAttrs(*)()>(&cocos2d::GLView::getGLContextAttrs));
mt.set_function("PollEvents",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::pollEvents));
mt.set_function("GetFrameSize",static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameSize));
mt.set_function("SetFrameSize",sol::overload(static_cast<void(cocos2d::GLView::*)(const cocos2d::Size&)>(&cocos2d::GLView::setFrameSize),static_cast<void(cocos2d::GLView::*)(float,float)>(&cocos2d::GLView::setFrameSize)));
mt.set_function("SetFrameZoomFactor",static_cast<void(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setFrameZoomFactor));
mt.set_function("GetFrameZoomFactor",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameZoomFactor));
mt.set_function("SetCursorVisible",static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setCursorVisible));
mt.set_function("GetRetinaFactor",static_cast<int(cocos2d::GLView::*)()const>(&cocos2d::GLView::getRetinaFactor));
mt.set_function("SetContentScaleFactor",static_cast<bool(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setContentScaleFactor));
mt.set_function("GetContentScaleFactor",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getContentScaleFactor));
mt.set_function("IsRetinaDisplay",static_cast<bool(cocos2d::GLView::*)()const>(&cocos2d::GLView::isRetinaDisplay));
mt.set_function("GetVisibleSize",static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleSize));
mt.set_function("GetVisibleOrigin",static_cast<cocos2d::Vec2(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleOrigin));
mt.set_function("GetVisibleRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleRect));
mt.set_function("GetSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getSafeAreaRect));
mt.set_function("SetDesignResolutionSize",static_cast<void(cocos2d::GLView::*)(float,float,cocos2d::ResolutionPolicy)>(&cocos2d::GLView::setDesignResolutionSize));
mt.set_function("GetDesignResolutionSize",static_cast<const cocos2d::Size&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getDesignResolutionSize));
mt.set_function("SetViewPortInPoints",static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setViewPortInPoints));
mt.set_function("SetScissorInPoints",static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setScissorInPoints));
mt.set_function("IsScissorEnabled",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isScissorEnabled));
mt.set_function("GetScissorRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScissorRect));
mt.set_function("SetViewName",static_cast<void(cocos2d::GLView::*)(const std::string&)>(&cocos2d::GLView::setViewName));
mt.set_function("GetViewName",static_cast<const std::string&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewName));
mt.set_function("HandleTouchesBegin",static_cast<void(cocos2d::GLView::*)(int,intptr_t [],float [],float [])>(&cocos2d::GLView::handleTouchesBegin));
mt.set_function("HandleTouchesMove",sol::overload(static_cast<void(cocos2d::GLView::*)(int,intptr_t [],float [],float [],float [],float [])>(&cocos2d::GLView::handleTouchesMove),static_cast<void(cocos2d::GLView::*)(int,intptr_t [],float [],float [])>(&cocos2d::GLView::handleTouchesMove)));
mt.set_function("HandleTouchesEnd",static_cast<void(cocos2d::GLView::*)(int,intptr_t [],float [],float [])>(&cocos2d::GLView::handleTouchesEnd));
mt.set_function("HandleTouchesCancel",static_cast<void(cocos2d::GLView::*)(int,intptr_t [],float [],float [])>(&cocos2d::GLView::handleTouchesCancel));
mt.set_function("SetIcon",sol::overload(static_cast<void(cocos2d::GLView::*)(const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >&)const>(&cocos2d::GLView::setIcon),static_cast<void(cocos2d::GLView::*)(const std::string&)const>(&cocos2d::GLView::setIcon)));
mt.set_function("SetDefaultIcon",static_cast<void(cocos2d::GLView::*)()const>(&cocos2d::GLView::setDefaultIcon));
mt.set_function("GetViewPortRect",static_cast<const cocos2d::Rect&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewPortRect));
mt.set_function("GetAllTouches",static_cast<std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >(cocos2d::GLView::*)()const>(&cocos2d::GLView::getAllTouches));
mt.set_function("GetScaleX",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleX));
mt.set_function("GetScaleY",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleY));
mt.set_function("GetResolutionPolicy",static_cast<cocos2d::ResolutionPolicy(cocos2d::GLView::*)()const>(&cocos2d::GLView::getResolutionPolicy));
mt.set_function("RenderScene",static_cast<void(cocos2d::GLView::*)(cocos2d::Scene*,cocos2d::Renderer*)>(&cocos2d::GLView::renderScene));
mt["GlContextAttrs"]=sol::var(std::ref(cocos2d::GLView::_glContextAttrs));
}
void RegisterLuaCoreMATRIX_STACK_TYPEAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::MATRIX_STACK_TYPE>("MATRIX_STACK_TYPE",{
{"MATRIX_STACK_MODELVIEW",cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW}
,{"MATRIX_STACK_PROJECTION",cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION}
,{"MATRIX_STACK_TEXTURE",cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE}
});}
