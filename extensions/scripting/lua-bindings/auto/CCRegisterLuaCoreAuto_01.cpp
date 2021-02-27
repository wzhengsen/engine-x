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
void RegisterLuaCoreNodeAnonymousEnum__7131246953838212473_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Node"];
pTable["FLAGS_TRANSFORM_DIRTY"] = 1;
pTable["FLAGS_CONTENT_SIZE_DIRTY"] = 2;
pTable["FLAGS_RENDER_AS_3D"] = 8;
pTable["FLAGS_DIRTY_MASK"] = 3;
}
void RegisterLuaCoreNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("Node",false);
ns["Node"] = mt;
lua["Node"] = sol::nil;
mt.set_function("getDescription",static_cast<std::string(cocos2d::Node::*)()const>(&cocos2d::Node::getDescription));
mt.set_function("setLocalZOrder",static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::setLocalZOrder));
mt.set_function("_setLocalZOrder",static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::_setLocalZOrder));
mt.set_function("updateOrderOfArrival",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateOrderOfArrival));
mt.set_function("getLocalZOrder",static_cast<int32_t(cocos2d::Node::*)()const>(&cocos2d::Node::getLocalZOrder));
mt.set_function("setGlobalZOrder",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setGlobalZOrder));
mt.set_function("getGlobalZOrder",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getGlobalZOrder));
mt.set_function("setScaleX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleX));
mt.set_function("getScaleX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleX));
mt.set_function("setScaleY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleY));
mt.set_function("getScaleY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleY));
mt.set_function("setScaleZ",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleZ));
mt.set_function("getScaleZ",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleZ));
mt.set_function("setScale",sol::overload(static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setScale),static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScale)));
mt.set_function("getScale",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScale));
mt.set_function("setPosition",sol::overload(static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setPosition),static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPosition)));
mt.set_function("setPositionNormalized",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPositionNormalized));
mt.set_function("setNormalizedPosition",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setNormalizedPosition));
mt.set_function("getPosition",sol::overload(static_cast<void(cocos2d::Node::*)(float*,float*)const>(&cocos2d::Node::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPosition)));
mt.set_function("getPositionXY",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionXY));
mt.set_function("getPositionNormalized",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionNormalized));
mt.set_function("getNormalizedPosition",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getNormalizedPosition));
mt.set_function("setPositionX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionX));
mt.set_function("getPositionX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionX));
mt.set_function("setPositionY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionY));
mt.set_function("getPositionY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionY));
mt.set_function("setPosition3D",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setPosition3D));
mt.set_function("getPosition3D",static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getPosition3D));
mt.set_function("setPositionZ",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionZ));
mt.set_function("getPositionZ",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionZ));
mt.set_function("setSkewX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewX));
mt.set_function("getSkewX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewX));
mt.set_function("setSkewY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewY));
mt.set_function("getSkewY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewY));
mt.set_function("setAnchorPoint",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setAnchorPoint));
mt.set_function("getAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPoint));
mt.set_function("getAnchorPointInPoints",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPointInPoints));
mt.set_function("setContentSize",static_cast<void(cocos2d::Node::*)(const cocos2d::Size&)>(&cocos2d::Node::setContentSize));
mt.set_function("getContentSize",static_cast<const cocos2d::Size&(cocos2d::Node::*)()const>(&cocos2d::Node::getContentSize));
mt.set_function("getContentWidth",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentWidth));
mt.set_function("getContentHeight",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentHeight));
mt.set_function("setContentWidth",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentWidth));
mt.set_function("setContentHeight",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentHeight));
mt.set_function("setVisible",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setVisible));
mt.set_function("isVisible",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isVisible));
mt.set_function("setRotation",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotation));
mt.set_function("getRotation",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation));
mt.set_function("setRotation3D",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setRotation3D));
mt.set_function("getRotation3D",static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation3D));
mt.set_function("setRotationQuat",static_cast<void(cocos2d::Node::*)(const cocos2d::Quaternion&)>(&cocos2d::Node::setRotationQuat));
mt.set_function("getRotationQuat",static_cast<cocos2d::Quaternion(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationQuat));
mt.set_function("setRotationSkewX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewX));
mt.set_function("getRotationSkewX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewX));
mt.set_function("setRotationSkewY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewY));
mt.set_function("getRotationSkewY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewY));
mt.set_function("setIgnoreAnchorPointForPosition",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setIgnoreAnchorPointForPosition));
mt.set_function("isIgnoreAnchorPointForPosition",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isIgnoreAnchorPointForPosition));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Node::addChild)));
mt.set_function("getChildByTag",static_cast<cocos2d::Node*(cocos2d::Node::*)(int)const>(&cocos2d::Node::getChildByTag));
mt.set_function("getChildByName",static_cast<cocos2d::Node*(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::getChildByName));
mt.set_function("enumerateChildren",static_cast<void(cocos2d::Node::*)(const std::string&,std::function<bool (cocos2d::Node *)>)const>(&cocos2d::Node::enumerateChildren));
mt.set_function("getChildren",sol::overload(static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()const>(&cocos2d::Node::getChildren),static_cast<cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()>(&cocos2d::Node::getChildren)));
mt.set_function("getChildrenCount",static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getChildrenCount));
mt.set_function("setParent",static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::setParent));
mt.set_function("getParent",sol::overload(static_cast<const cocos2d::Node*(cocos2d::Node::*)()const>(&cocos2d::Node::getParent),static_cast<cocos2d::Node*(cocos2d::Node::*)()>(&cocos2d::Node::getParent)));
mt.set_function("removeFromParent",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeFromParent));
mt.set_function("removeFromParentAndCleanup",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeFromParentAndCleanup));
mt.set_function("removeChild",sol::overload([](cocos2d::Node* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Node* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("removeChildByTag",sol::overload([](cocos2d::Node* obj,int arg0){return obj->removeChildByTag(arg0);},[](cocos2d::Node* obj,int arg0,bool arg1){return obj->removeChildByTag(arg0,arg1);}));
mt.set_function("removeChildByName",sol::overload([](cocos2d::Node* obj,const std::string& arg0){return obj->removeChildByName(arg0);},[](cocos2d::Node* obj,const std::string& arg0,bool arg1){return obj->removeChildByName(arg0,arg1);}));
mt.set_function("removeAllChildren",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllChildren));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeAllChildrenWithCleanup));
mt.set_function("reorderChild",static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::reorderChild));
mt.set_function("sortAllChildren",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::sortAllChildren));
mt.set_function("getTag",static_cast<int(cocos2d::Node::*)()const>(&cocos2d::Node::getTag));
mt.set_function("setTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::setTag));
mt.set_function("getName",static_cast<const std::string&(cocos2d::Node::*)()const>(&cocos2d::Node::getName));
mt.set_function("setName",static_cast<void(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::setName));
mt.set_function("getUserData",sol::overload(static_cast<const void*(cocos2d::Node::*)()const>(&cocos2d::Node::getUserData),static_cast<void*(cocos2d::Node::*)()>(&cocos2d::Node::getUserData)));
mt.set_function("setUserData",static_cast<void(cocos2d::Node::*)(void*)>(&cocos2d::Node::setUserData));
mt.set_function("getUserObject",sol::overload(static_cast<const cocos2d::Ref*(cocos2d::Node::*)()const>(&cocos2d::Node::getUserObject),static_cast<cocos2d::Ref*(cocos2d::Node::*)()>(&cocos2d::Node::getUserObject)));
mt.set_function("setUserObject",static_cast<void(cocos2d::Node::*)(cocos2d::Ref*)>(&cocos2d::Node::setUserObject));
mt.set_function("isRunning",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isRunning));
mt.set_function("onEnter",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onEnter));
mt.set_function("onEnterTransitionDidFinish",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onEnterTransitionDidFinish));
mt.set_function("onExit",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onExit));
mt.set_function("onExitTransitionDidStart",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::onExitTransitionDidStart));
mt.set_function("cleanup",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::cleanup));
mt.set_function("draw",sol::overload(static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::draw),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::draw)));
mt.set_function("visit",sol::overload(static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::visit),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::visit)));
mt.set_function("getScene",static_cast<cocos2d::Scene*(cocos2d::Node::*)()const>(&cocos2d::Node::getScene));
mt.set_function("getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Node::*)()const>(&cocos2d::Node::getBoundingBox));
mt.set_function("setEventDispatcher",static_cast<void(cocos2d::Node::*)(cocos2d::EventDispatcher*)>(&cocos2d::Node::setEventDispatcher));
mt.set_function("getEventDispatcher",static_cast<cocos2d::EventDispatcher*(cocos2d::Node::*)()const>(&cocos2d::Node::getEventDispatcher));
mt.set_function("setActionManager",static_cast<void(cocos2d::Node::*)(cocos2d::ActionManager*)>(&cocos2d::Node::setActionManager));
mt.set_function("getActionManager",sol::overload(static_cast<const cocos2d::ActionManager*(cocos2d::Node::*)()const>(&cocos2d::Node::getActionManager),static_cast<cocos2d::ActionManager*(cocos2d::Node::*)()>(&cocos2d::Node::getActionManager)));
mt.set_function("runAction",static_cast<cocos2d::Action*(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::runAction));
mt.set_function("stopAllActions",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::stopAllActions));
mt.set_function("stopAction",static_cast<void(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::stopAction));
mt.set_function("stopActionByTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopActionByTag));
mt.set_function("stopAllActionsByTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopAllActionsByTag));
mt.set_function("stopActionsByFlags",static_cast<void(cocos2d::Node::*)(unsigned int)>(&cocos2d::Node::stopActionsByFlags));
mt.set_function("getActionByTag",static_cast<cocos2d::Action*(cocos2d::Node::*)(int)>(&cocos2d::Node::getActionByTag));
mt.set_function("getNumberOfRunningActions",static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getNumberOfRunningActions));
mt.set_function("getNumberOfRunningActionsByTag",static_cast<ssize_t(cocos2d::Node::*)(int)const>(&cocos2d::Node::getNumberOfRunningActionsByTag));
mt.set_function("setScheduler",static_cast<void(cocos2d::Node::*)(cocos2d::Scheduler*)>(&cocos2d::Node::setScheduler));
mt.set_function("getScheduler",sol::overload(static_cast<const cocos2d::Scheduler*(cocos2d::Node::*)()const>(&cocos2d::Node::getScheduler),static_cast<cocos2d::Scheduler*(cocos2d::Node::*)()>(&cocos2d::Node::getScheduler)));
mt.set_function("isScheduled",sol::overload(static_cast<bool(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::isScheduled),static_cast<bool(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)const>(&cocos2d::Node::isScheduled)));
mt.set_function("scheduleUpdate",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::scheduleUpdate));
mt.set_function("scheduleUpdateWithPriority",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::scheduleUpdateWithPriority));
mt.set_function("unscheduleUpdate",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::unscheduleUpdate));
mt.set_function("schedule",sol::overload(static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE,float)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE,float,unsigned int,float)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,const std::string&)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,float,const std::string&)>(&cocos2d::Node::schedule),static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,float,unsigned int,float,const std::string&)>(&cocos2d::Node::schedule)));
mt.set_function("scheduleOnce",sol::overload(static_cast<void(cocos2d::Node::*)(const std::function<void (float)>&,float,const std::string&)>(&cocos2d::Node::scheduleOnce),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE,float)>(&cocos2d::Node::scheduleOnce)));
mt.set_function("unschedule",sol::overload(static_cast<void(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::unschedule),static_cast<void(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)>(&cocos2d::Node::unschedule)));
mt.set_function("unscheduleAllCallbacks",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::unscheduleAllCallbacks));
mt.set_function("resume",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::resume));
mt.set_function("pause",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::pause));
mt.set_function("update",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::update));
mt.set_function("updateTransform",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateTransform));
mt.set_function("getNodeToParentTransform",sol::overload(static_cast<cocos2d::Mat4(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentTransform),static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentTransform)));
mt.set_function("getNodeToParentAffineTransform",sol::overload(static_cast<cocos2d::AffineTransform(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentAffineTransform),static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentAffineTransform)));
mt.set_function("setNodeToParentTransform",static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4&)>(&cocos2d::Node::setNodeToParentTransform));
mt.set_function("getParentToNodeTransform",static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeTransform));
mt.set_function("getParentToNodeAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeAffineTransform));
mt.set_function("getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldTransform));
mt.set_function("getNodeToWorldAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldAffineTransform));
mt.set_function("getWorldToNodeTransform",static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeTransform));
mt.set_function("getWorldToNodeAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeAffineTransform));
mt.set_function("convertToNodeSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpace));
mt.set_function("convertToWorldSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpace));
mt.set_function("convertToNodeSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpaceAR));
mt.set_function("convertToWorldSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpaceAR));
mt.set_function("convertTouchToNodeSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpace));
mt.set_function("convertTouchToNodeSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpaceAR));
mt.set_function("setAdditionalTransform",sol::overload(static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4&)>(&cocos2d::Node::setAdditionalTransform),static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4*)>(&cocos2d::Node::setAdditionalTransform),static_cast<void(cocos2d::Node::*)(const cocos2d::AffineTransform&)>(&cocos2d::Node::setAdditionalTransform)));
mt.set_function("getComponent",static_cast<cocos2d::Component*(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::getComponent));
mt.set_function("addComponent",static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::addComponent));
mt.set_function("removeComponent",sol::overload(static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::removeComponent),static_cast<bool(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::removeComponent)));
mt.set_function("removeAllComponents",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllComponents));
mt.set_function("getOpacity",static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getOpacity));
mt.set_function("getDisplayedOpacity",static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedOpacity));
mt.set_function("setOpacity",static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::setOpacity));
mt.set_function("updateDisplayedOpacity",static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::updateDisplayedOpacity));
mt.set_function("isCascadeOpacityEnabled",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeOpacityEnabled));
mt.set_function("setCascadeOpacityEnabled",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeOpacityEnabled));
mt.set_function("getColor",static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getColor));
mt.set_function("getDisplayedColor",static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedColor));
mt.set_function("setColor",static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::setColor));
mt.set_function("updateDisplayedColor",static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::updateDisplayedColor));
mt.set_function("isCascadeColorEnabled",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeColorEnabled));
mt.set_function("setCascadeColorEnabled",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeColorEnabled));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isOpacityModifyRGB));
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
mt.set_function("getCameraMask",static_cast<unsigned short(cocos2d::Node::*)()const>(&cocos2d::Node::getCameraMask));
mt.set_function("setCameraMask",sol::overload([](cocos2d::Node* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Node* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("setProgramState",sol::overload([](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);},static_cast<void(cocos2d::Node::*)(uint32_t)>(&cocos2d::Node::setProgramState)));
mt.set_function("setProgramStateWithRegistry",static_cast<void(cocos2d::Node::*)(uint32_t,cocos2d::Texture2D*)>(&cocos2d::Node::setProgramStateWithRegistry));
mt.set_function("getProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Node::*)()const>(&cocos2d::Node::getProgramState));
mt.set_function("updateProgramStateTexture",static_cast<void(cocos2d::Node::*)(cocos2d::Texture2D*)>(&cocos2d::Node::updateProgramStateTexture));
mt.set_function("setPhysicsBody",static_cast<void(cocos2d::Node::*)(cocos2d::PhysicsBody*)>(&cocos2d::Node::setPhysicsBody));
mt.set_function("getPhysicsBody",static_cast<cocos2d::PhysicsBody*(cocos2d::Node::*)()const>(&cocos2d::Node::getPhysicsBody));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Node*(*)()>(&cocos2d::Node::create));
mt.set_function("getAttachedNodeCount",static_cast<int(*)()>(&cocos2d::Node::getAttachedNodeCount));
RegisterLuaCoreNodeAnonymousEnum__7131246953838212473_Auto(lua);
}
void RegisterLuaCoreSceneAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("Scene",false);
ns["Scene"] = mt;
lua["Scene"] = sol::nil;
mt.set_function("getDescription",static_cast<std::string(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDescription));
mt.set_function("getCameras",static_cast<const std::vector<cocos2d::Camera *>&(cocos2d::Scene::*)()>(&cocos2d::Scene::getCameras));
mt.set_function("getDefaultCamera",static_cast<cocos2d::Camera*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDefaultCamera));
mt.set_function("getLights",static_cast<const std::vector<cocos2d::BaseLight *>&(cocos2d::Scene::*)()const>(&cocos2d::Scene::getLights));
mt.set_function("render",sol::overload([](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1){return obj->render(arg0,arg1);},[](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1,const cocos2d::Mat4* arg2){return obj->render(arg0,arg1,arg2);}));
mt.set_function("removeAllChildren",static_cast<void(cocos2d::Scene::*)()>(&cocos2d::Scene::removeAllChildren));
mt.set_function("getPhysicsWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getPhysicsWorld));
mt.set_function("setNavMesh",static_cast<void(cocos2d::Scene::*)(cocos2d::NavMesh*)>(&cocos2d::Scene::setNavMesh));
mt.set_function("getNavMesh",static_cast<cocos2d::NavMesh*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getNavMesh));
mt.set_function("setNavMeshDebugCamera",static_cast<void(cocos2d::Scene::*)(cocos2d::Camera*)>(&cocos2d::Scene::setNavMeshDebugCamera));
mt.set_function("stepPhysicsAndNavigation",static_cast<void(cocos2d::Scene::*)(float)>(&cocos2d::Scene::stepPhysicsAndNavigation));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::create));
mt.set_function("createWithSize",static_cast<cocos2d::Scene*(*)(const cocos2d::Size&)>(&cocos2d::Scene::createWithSize));
mt.set_function("createWithPhysics",static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::createWithPhysics));
}
void RegisterLuaCoreEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Event"];
pTable.new_enum("Type"
,"TOUCH",0
,"KEYBOARD",1
,"ACCELERATION",2
,"MOUSE",3
,"FOCUS",4
,"GAME_CONTROLLER",5
,"CUSTOM",6
);}
void RegisterLuaCoreEventAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("Event",true);
ns["Event"] = mt;
lua["Event"] = sol::nil;
mt.set_function("getType",static_cast<cocos2d::Event::Type(cocos2d::Event::*)()const>(&cocos2d::Event::getType));
mt.set_function("stopPropagation",static_cast<void(cocos2d::Event::*)()>(&cocos2d::Event::stopPropagation));
mt.set_function("isStopped",static_cast<bool(cocos2d::Event::*)()const>(&cocos2d::Event::isStopped));
mt.set_function("getCurrentTarget",static_cast<cocos2d::Node*(cocos2d::Event::*)()>(&cocos2d::Event::getCurrentTarget));
RegisterLuaCoreEventTypeAuto(lua);
}
void RegisterLuaCoreEventTouchEventCodeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventTouch"];
pTable.new_enum("EventCode"
,"BEGAN",0
,"MOVED",1
,"ENDED",2
,"CANCELLED",3
);}
void RegisterLuaCoreEventTouchAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventTouch,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventTouch",true);
ns["EventTouch"] = mt;
lua["EventTouch"] = sol::nil;
mt.set_function("getEventCode",static_cast<cocos2d::EventTouch::EventCode(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getEventCode));
mt.set_function("getTouches",static_cast<const std::vector<cocos2d::Touch *>&(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getTouches));
mt.set_function("setEventCode",static_cast<void(cocos2d::EventTouch::*)(cocos2d::EventTouch::EventCode)>(&cocos2d::EventTouch::setEventCode));
mt.set_function("setTouches",static_cast<void(cocos2d::EventTouch::*)(const std::vector<cocos2d::Touch *>&)>(&cocos2d::EventTouch::setTouches));
RegisterLuaCoreEventTouchEventCodeAuto(lua);
}
void RegisterLuaCoreGLViewAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>("GLView",true);
ns["GLView"] = mt;
lua["GLView"] = sol::nil;
mt.set_function("endToLua",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::end));
mt.set_function("isOpenGLReady",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isOpenGLReady));
mt.set_function("swapBuffers",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::swapBuffers));
mt.set_function("setIMEKeyboardState",static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setIMEKeyboardState));
mt.set_function("windowShouldClose",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::windowShouldClose));
mt.set_function("pollEvents",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::pollEvents));
mt.set_function("getFrameSize",static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameSize));
mt.set_function("setFrameSize",sol::overload(static_cast<void(cocos2d::GLView::*)(const cocos2d::Size&)>(&cocos2d::GLView::setFrameSize),static_cast<void(cocos2d::GLView::*)(float,float)>(&cocos2d::GLView::setFrameSize)));
mt.set_function("setFrameZoomFactor",static_cast<void(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setFrameZoomFactor));
mt.set_function("getFrameZoomFactor",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameZoomFactor));
mt.set_function("setCursorVisible",static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setCursorVisible));
mt.set_function("getRetinaFactor",static_cast<int(cocos2d::GLView::*)()const>(&cocos2d::GLView::getRetinaFactor));
mt.set_function("setContentScaleFactor",static_cast<bool(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setContentScaleFactor));
mt.set_function("getContentScaleFactor",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getContentScaleFactor));
mt.set_function("isRetinaDisplay",static_cast<bool(cocos2d::GLView::*)()const>(&cocos2d::GLView::isRetinaDisplay));
mt.set_function("getVisibleSize",static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleSize));
mt.set_function("getVisibleOrigin",static_cast<cocos2d::Vec2(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleOrigin));
mt.set_function("getVisibleRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleRect));
mt.set_function("getSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getSafeAreaRect));
mt.set_function("setDesignResolutionSize",static_cast<void(cocos2d::GLView::*)(float,float,ResolutionPolicy)>(&cocos2d::GLView::setDesignResolutionSize));
mt.set_function("getDesignResolutionSize",static_cast<const cocos2d::Size&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getDesignResolutionSize));
mt.set_function("setViewPortInPoints",static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setViewPortInPoints));
mt.set_function("setScissorInPoints",static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setScissorInPoints));
mt.set_function("isScissorEnabled",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isScissorEnabled));
mt.set_function("getScissorRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScissorRect));
mt.set_function("setViewName",static_cast<void(cocos2d::GLView::*)(const std::string&)>(&cocos2d::GLView::setViewName));
mt.set_function("getViewName",static_cast<const std::string&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewName));
mt.set_function("setIcon",sol::overload(static_cast<void(cocos2d::GLView::*)(const std::vector<std::string>&)const>(&cocos2d::GLView::setIcon),static_cast<void(cocos2d::GLView::*)(const std::string&)const>(&cocos2d::GLView::setIcon)));
mt.set_function("setDefaultIcon",static_cast<void(cocos2d::GLView::*)()const>(&cocos2d::GLView::setDefaultIcon));
mt.set_function("getViewPortRect",static_cast<const cocos2d::Rect&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewPortRect));
mt.set_function("getAllTouches",static_cast<std::vector<cocos2d::Touch *>(cocos2d::GLView::*)()const>(&cocos2d::GLView::getAllTouches));
mt.set_function("getScaleX",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleX));
mt.set_function("getScaleY",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleY));
mt.set_function("getResolutionPolicy",static_cast<ResolutionPolicy(cocos2d::GLView::*)()const>(&cocos2d::GLView::getResolutionPolicy));
mt.set_function("renderScene",static_cast<void(cocos2d::GLView::*)(cocos2d::Scene*,cocos2d::Renderer*)>(&cocos2d::GLView::renderScene));
mt.set_function("setGLContextAttrs",static_cast<void(*)(GLContextAttrs&)>(&cocos2d::GLView::setGLContextAttrs));
mt.set_function("getGLContextAttrs",static_cast<GLContextAttrs(*)()>(&cocos2d::GLView::getGLContextAttrs));
}
void RegisterLuaCoreDirectorProjectionAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Director"];
pTable.new_enum("Projection"
,"_2D",0
,"_3D",1
,"CUSTOM",2
,"DEFAULT",1
);}
void RegisterLuaCoreDirectorAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Director>("Director",true);
ns["Director"] = mt;
lua["Director"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::init));
mt.set_function("getRunningScene",static_cast<cocos2d::Scene*(cocos2d::Director::*)()>(&cocos2d::Director::getRunningScene));
mt.set_function("getAnimationInterval",static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getAnimationInterval));
mt.set_function("setAnimationInterval",static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setAnimationInterval));
mt.set_function("isDisplayStats",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isDisplayStats));
mt.set_function("setDisplayStats",static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setDisplayStats));
mt.set_function("getSecondsPerFrame",static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getSecondsPerFrame));
mt.set_function("getOpenGLView",static_cast<cocos2d::GLView*(cocos2d::Director::*)()>(&cocos2d::Director::getOpenGLView));
mt.set_function("setOpenGLView",static_cast<void(cocos2d::Director::*)(cocos2d::GLView*)>(&cocos2d::Director::setOpenGLView));
mt.set_function("getTextureCache",static_cast<cocos2d::TextureCache*(cocos2d::Director::*)()const>(&cocos2d::Director::getTextureCache));
mt.set_function("isNextDeltaTimeZero",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isNextDeltaTimeZero));
mt.set_function("setNextDeltaTimeZero",static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setNextDeltaTimeZero));
mt.set_function("isPaused",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isPaused));
mt.set_function("getTotalFrames",static_cast<unsigned int(cocos2d::Director::*)()>(&cocos2d::Director::getTotalFrames));
mt.set_function("getProjection",static_cast<cocos2d::Director::Projection(cocos2d::Director::*)()>(&cocos2d::Director::getProjection));
mt.set_function("setProjection",static_cast<void(cocos2d::Director::*)(cocos2d::Director::Projection)>(&cocos2d::Director::setProjection));
mt.set_function("setViewport",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setViewport));
mt.set_function("isSendCleanupToScene",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isSendCleanupToScene));
mt.set_function("getNotificationNode",static_cast<cocos2d::Node*(cocos2d::Director::*)()const>(&cocos2d::Director::getNotificationNode));
mt.set_function("setNotificationNode",static_cast<void(cocos2d::Director::*)(cocos2d::Node*)>(&cocos2d::Director::setNotificationNode));
mt.set_function("getWinSize",static_cast<const cocos2d::Size&(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSize));
mt.set_function("getWinSizeInPixels",static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSizeInPixels));
mt.set_function("getVisibleSize",static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleSize));
mt.set_function("getVisibleOrigin",static_cast<cocos2d::Vec2(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleOrigin));
mt.set_function("getSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::Director::*)()const>(&cocos2d::Director::getSafeAreaRect));
mt.set_function("convertToGL",static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToGL));
mt.set_function("convertToUI",static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToUI));
mt.set_function("getZEye",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getZEye));
mt.set_function("runWithScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::runWithScene));
mt.set_function("pushScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::pushScene));
mt.set_function("popScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popScene));
mt.set_function("popToRootScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popToRootScene));
mt.set_function("popToSceneStackLevel",static_cast<void(cocos2d::Director::*)(int)>(&cocos2d::Director::popToSceneStackLevel));
mt.set_function("replaceScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::replaceScene));
mt.set_function("endToLua",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::end));
mt.set_function("pause",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::pause));
mt.set_function("resume",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resume));
mt.set_function("restart",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::restart));
mt.set_function("stopAnimation",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::stopAnimation));
mt.set_function("startAnimation",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::startAnimation));
mt.set_function("drawScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::drawScene));
mt.set_function("purgeCachedData",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::purgeCachedData));
mt.set_function("setDefaultValues",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setDefaultValues));
mt.set_function("setGLDefaultValues",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setGLDefaultValues));
mt.set_function("setClearColor",static_cast<void(cocos2d::Director::*)(const cocos2d::Color4F&)>(&cocos2d::Director::setClearColor));
mt.set_function("mainLoop",sol::overload(static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::mainLoop),static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::mainLoop)));
mt.set_function("setContentScaleFactor",static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setContentScaleFactor));
mt.set_function("getContentScaleFactor",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getContentScaleFactor));
mt.set_function("getScheduler",static_cast<cocos2d::Scheduler*(cocos2d::Director::*)()const>(&cocos2d::Director::getScheduler));
mt.set_function("setScheduler",static_cast<void(cocos2d::Director::*)(cocos2d::Scheduler*)>(&cocos2d::Director::setScheduler));
mt.set_function("getActionManager",static_cast<cocos2d::ActionManager*(cocos2d::Director::*)()const>(&cocos2d::Director::getActionManager));
mt.set_function("setActionManager",static_cast<void(cocos2d::Director::*)(cocos2d::ActionManager*)>(&cocos2d::Director::setActionManager));
mt.set_function("getEventDispatcher",static_cast<cocos2d::EventDispatcher*(cocos2d::Director::*)()const>(&cocos2d::Director::getEventDispatcher));
mt.set_function("setEventDispatcher",static_cast<void(cocos2d::Director::*)(cocos2d::EventDispatcher*)>(&cocos2d::Director::setEventDispatcher));
mt.set_function("getRenderer",static_cast<cocos2d::Renderer*(cocos2d::Director::*)()const>(&cocos2d::Director::getRenderer));
mt.set_function("getConsole",static_cast<cocos2d::Console*(cocos2d::Director::*)()const>(&cocos2d::Director::getConsole));
mt.set_function("getDeltaTime",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getDeltaTime));
mt.set_function("getFrameRate",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getFrameRate));
mt.set_function("pushMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::pushMatrix));
mt.set_function("popMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::popMatrix));
mt.set_function("loadIdentityMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::loadIdentityMatrix));
mt.set_function("loadMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::loadMatrix));
mt.set_function("multiplyMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::multiplyMatrix));
mt.set_function("getMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)const>(&cocos2d::Director::getMatrix));
mt.set_function("resetMatrixStack",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resetMatrixStack));
mt.set_function("getCocos2dThreadId",static_cast<const std::thread::id&(cocos2d::Director::*)()const>(&cocos2d::Director::getCocos2dThreadId));
mt.set_function("isValid",static_cast<bool(cocos2d::Director::*)()const>(&cocos2d::Director::isValid));
mt.set_function("getInstance",static_cast<cocos2d::Director*(*)()>(&cocos2d::Director::getInstance));
RegisterLuaCoreDirectorProjectionAuto(lua);
}
void RegisterLuaCoreTimerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Timer,cocos2d::Ref,cocos2d::LuaObject>("Timer",true);
ns["Timer"] = mt;
lua["Timer"] = sol::nil;
mt.set_function("setupTimerWithInterval",static_cast<void(cocos2d::Timer::*)(float,unsigned int,float)>(&cocos2d::Timer::setupTimerWithInterval));
mt.set_function("setAborted",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::setAborted));
mt.set_function("isAborted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isAborted));
mt.set_function("isExhausted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isExhausted));
mt.set_function("trigger",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::trigger));
mt.set_function("cancel",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::cancel));
mt.set_function("update",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::update));
}
void RegisterLuaCoreSchedulerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Scheduler,cocos2d::Ref,cocos2d::LuaObject>("Scheduler",true);
ns["Scheduler"] = mt;
lua["Scheduler"] = sol::nil;
mt.set_function("getTimeScale",static_cast<float(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::getTimeScale));
mt.set_function("setTimeScale",static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::setTimeScale));
mt.set_function("update",static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::update));
mt.set_function("schedule",sol::overload(static_cast<void(cocos2d::Scheduler::*)(const std::function<void (float)>&,void*,float,bool,const std::string&)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(const std::function<void (float)>&,void*,float,unsigned int,float,bool,const std::string&)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*,float,unsigned int,float,bool)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*,float,bool)>(&cocos2d::Scheduler::schedule)));
mt.set_function("unschedule",sol::overload(static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*)>(&cocos2d::Scheduler::unschedule),static_cast<void(cocos2d::Scheduler::*)(const std::string&,void*)>(&cocos2d::Scheduler::unschedule)));
mt.set_function("unscheduleUpdate",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::unscheduleUpdate));
mt.set_function("unscheduleAllForTarget",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::unscheduleAllForTarget));
mt.set_function("unscheduleAll",static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::unscheduleAll));
mt.set_function("unscheduleAllWithMinPriority",static_cast<void(cocos2d::Scheduler::*)(int)>(&cocos2d::Scheduler::unscheduleAllWithMinPriority));
mt.set_function("isScheduled",sol::overload(static_cast<bool(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,const cocos2d::Ref*)const>(&cocos2d::Scheduler::isScheduled),static_cast<bool(cocos2d::Scheduler::*)(const std::string&,const void*)const>(&cocos2d::Scheduler::isScheduled)));
mt.set_function("pauseTarget",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::pauseTarget));
mt.set_function("resumeTarget",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::resumeTarget));
mt.set_function("isTargetPaused",static_cast<bool(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::isTargetPaused));
mt.set_function("pauseAllTargets",static_cast<std::set<void *>(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::pauseAllTargets));
mt.set_function("pauseAllTargetsWithMinPriority",static_cast<std::set<void *>(cocos2d::Scheduler::*)(int)>(&cocos2d::Scheduler::pauseAllTargetsWithMinPriority));
mt.set_function("resumeTargets",static_cast<void(cocos2d::Scheduler::*)(const std::set<void *>&)>(&cocos2d::Scheduler::resumeTargets));
mt.set_function("performFunctionInCocosThread",static_cast<void(cocos2d::Scheduler::*)(std::function<void ()>)>(&cocos2d::Scheduler::performFunctionInCocosThread));
mt.set_function("removeAllFunctionsToBePerformedInCocosThread",static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::removeAllFunctionsToBePerformedInCocosThread));
}
void RegisterLuaCoreAsyncTaskPoolTaskTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["AsyncTaskPool"];
pTable.new_enum("TaskType"
,"TASK_IO",0
,"TASK_NETWORK",1
,"TASK_OTHER",2
,"TASK_MAX_TYPE",3
);}
void RegisterLuaCoreAsyncTaskPoolAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::AsyncTaskPool>("AsyncTaskPool",true);
ns["AsyncTaskPool"] = mt;
lua["AsyncTaskPool"] = sol::nil;
mt.set_function("stopTasks",static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks));
mt.set_function("enqueue",sol::overload(static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue),static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,cocos2d::AsyncTaskPool::TaskCallBack,void*,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue)));
mt.set_function("getInstance",static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance));
RegisterLuaCoreAsyncTaskPoolTaskTypeAuto(lua);
}
void RegisterLuaCoreActionAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Action",true);
ns["Action"] = mt;
lua["Action"] = sol::nil;
mt.set_function("description",static_cast<std::string(cocos2d::Action::*)()const>(&cocos2d::Action::description));
mt.set_function("clone",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::clone));
mt.set_function("reverse",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::reverse));
mt.set_function("isDone",static_cast<bool(cocos2d::Action::*)()const>(&cocos2d::Action::isDone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Action::*)()>(&cocos2d::Action::stop));
mt.set_function("step",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::step));
mt.set_function("update",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::update));
mt.set_function("getTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getTarget));
mt.set_function("setTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setTarget));
mt.set_function("getOriginalTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getOriginalTarget));
mt.set_function("setOriginalTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setOriginalTarget));
mt.set_function("getTag",static_cast<int(cocos2d::Action::*)()const>(&cocos2d::Action::getTag));
mt.set_function("setTag",static_cast<void(cocos2d::Action::*)(int)>(&cocos2d::Action::setTag));
mt.set_function("getFlags",static_cast<unsigned int(cocos2d::Action::*)()const>(&cocos2d::Action::getFlags));
mt.set_function("setFlags",static_cast<void(cocos2d::Action::*)(unsigned int)>(&cocos2d::Action::setFlags));
}
