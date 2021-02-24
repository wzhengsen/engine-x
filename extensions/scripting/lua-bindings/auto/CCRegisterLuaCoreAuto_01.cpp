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
void RegisterLuaCoreEventAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","Event");
mt.set_function("getType",static_cast<cocos2d::Event::Type(cocos2d::Event::*)()const>(&cocos2d::Event::getType));
mt.set_function("stopPropagation",static_cast<void(cocos2d::Event::*)()>(&cocos2d::Event::stopPropagation));
mt.set_function("isStopped",static_cast<bool(cocos2d::Event::*)()const>(&cocos2d::Event::isStopped));
mt.set_function("getCurrentTarget",static_cast<cocos2d::Node*(cocos2d::Event::*)()>(&cocos2d::Event::getCurrentTarget));
}
void RegisterLuaCoreEventTouchAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventTouch,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventTouch");
mt.set_function("getEventCode",static_cast<cocos2d::EventTouch::EventCode(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getEventCode));
mt.set_function("getTouches",static_cast<const std::vector<cocos2d::Touch *>&(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getTouches));
mt.set_function("setEventCode",static_cast<void(cocos2d::EventTouch::*)(cocos2d::EventTouch::EventCode)>(&cocos2d::EventTouch::setEventCode));
mt.set_function("setTouches",static_cast<void(cocos2d::EventTouch::*)(const std::vector<cocos2d::Touch *>&)>(&cocos2d::EventTouch::setTouches));
}
void RegisterLuaCoreGLViewAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>("cc","GLView");
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
void RegisterLuaCoreDirectorAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Director>("cc","Director");
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
}
void RegisterLuaCoreTimerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Timer,cocos2d::Ref,cocos2d::LuaObject>("cc","Timer");
mt.set_function("setupTimerWithInterval",static_cast<void(cocos2d::Timer::*)(float,unsigned int,float)>(&cocos2d::Timer::setupTimerWithInterval));
mt.set_function("setAborted",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::setAborted));
mt.set_function("isAborted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isAborted));
mt.set_function("isExhausted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isExhausted));
mt.set_function("trigger",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::trigger));
mt.set_function("cancel",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::cancel));
mt.set_function("update",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::update));
}
void RegisterLuaCoreSchedulerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Scheduler,cocos2d::Ref,cocos2d::LuaObject>("cc","Scheduler");
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
void RegisterLuaCoreAsyncTaskPoolAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AsyncTaskPool>("cc","AsyncTaskPool");
mt.set_function("stopTasks",static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks));
mt.set_function("enqueue",sol::overload(static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue),static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,cocos2d::AsyncTaskPool::TaskCallBack,void*,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue)));
mt.set_function("getInstance",static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance));
}
void RegisterLuaCoreAnimation3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation3D,cocos2d::Ref,cocos2d::LuaObject>("cc","Animation3D");
mt.set_function("getDuration",static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration));
mt.set_function("getBoneCurveByName",static_cast<cocos2d::Animation3D::Curve*(cocos2d::Animation3D::*)(const std::string&)const>(&cocos2d::Animation3D::getBoneCurveByName));
mt.set_function("getBoneCurves",static_cast<const std::unordered_map<std::string, cocos2d::Animation3D::Curve *>&(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getBoneCurves));
mt.set_function("new",sol::overload([](cocos2d::Animation3D* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::Animation3D* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreAnimation3DCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation3DCache>("cc","Animation3DCache");
mt.set_function("getAnimation",static_cast<cocos2d::Animation3D*(cocos2d::Animation3DCache::*)(const std::string&)>(&cocos2d::Animation3DCache::getAnimation));
mt.set_function("addAnimation",static_cast<void(cocos2d::Animation3DCache::*)(const std::string&,cocos2d::Animation3D*)>(&cocos2d::Animation3DCache::addAnimation));
mt.set_function("removeAllAnimations",static_cast<void(cocos2d::Animation3DCache::*)()>(&cocos2d::Animation3DCache::removeAllAnimations));
mt.set_function("removeUnusedAnimation",static_cast<void(cocos2d::Animation3DCache::*)()>(&cocos2d::Animation3DCache::removeUnusedAnimation));
mt.set_function("getInstance",static_cast<cocos2d::Animation3DCache*(*)()>(&cocos2d::Animation3DCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::Animation3DCache::destroyInstance));
}
void RegisterLuaCoreActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Action");
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
