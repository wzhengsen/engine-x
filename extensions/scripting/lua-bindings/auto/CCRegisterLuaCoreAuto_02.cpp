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
void RegisterLuaCoreDirectorAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Director>("cc","Director",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocos2d::Director*(*)()>(&cocos2d::Director::getInstance));
mt.set_function("Init",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::init));
mt.set_function("GetRunningScene",static_cast<cocos2d::Scene*(cocos2d::Director::*)()>(&cocos2d::Director::getRunningScene));
mt.set_function("GetAnimationInterval",static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getAnimationInterval));
mt.set_function("SetAnimationInterval",static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setAnimationInterval));
mt.set_function("IsDisplayStats",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isDisplayStats));
mt.set_function("SetDisplayStats",static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setDisplayStats));
mt.set_function("GetSecondsPerFrame",static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getSecondsPerFrame));
mt.set_function("GetOpenGLView",static_cast<cocos2d::GLView*(cocos2d::Director::*)()>(&cocos2d::Director::getOpenGLView));
mt.set_function("SetOpenGLView",static_cast<void(cocos2d::Director::*)(cocos2d::GLView*)>(&cocos2d::Director::setOpenGLView));
mt.set_function("GetTextureCache",static_cast<cocos2d::TextureCache*(cocos2d::Director::*)()const>(&cocos2d::Director::getTextureCache));
mt.set_function("IsNextDeltaTimeZero",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isNextDeltaTimeZero));
mt.set_function("SetNextDeltaTimeZero",static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setNextDeltaTimeZero));
mt.set_function("IsPaused",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isPaused));
mt.set_function("GetTotalFrames",static_cast<unsigned int(cocos2d::Director::*)()>(&cocos2d::Director::getTotalFrames));
mt.set_function("GetProjection",static_cast<cocos2d::Director::Projection(cocos2d::Director::*)()>(&cocos2d::Director::getProjection));
mt.set_function("SetProjection",static_cast<void(cocos2d::Director::*)(cocos2d::Director::Projection)>(&cocos2d::Director::setProjection));
mt.set_function("SetViewport",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setViewport));
mt.set_function("IsSendCleanupToScene",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isSendCleanupToScene));
mt.set_function("GetNotificationNode",static_cast<cocos2d::Node*(cocos2d::Director::*)()const>(&cocos2d::Director::getNotificationNode));
mt.set_function("SetNotificationNode",static_cast<void(cocos2d::Director::*)(cocos2d::Node*)>(&cocos2d::Director::setNotificationNode));
mt.set_function("GetWinSize",static_cast<const cocos2d::Size&(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSize));
mt.set_function("GetWinSizeInPixels",static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSizeInPixels));
mt.set_function("GetVisibleSize",static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleSize));
mt.set_function("GetVisibleOrigin",static_cast<cocos2d::Vec2(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleOrigin));
mt.set_function("GetSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::Director::*)()const>(&cocos2d::Director::getSafeAreaRect));
mt.set_function("ConvertToGL",static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToGL));
mt.set_function("ConvertToUI",static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToUI));
mt.set_function("GetZEye",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getZEye));
mt.set_function("RunWithScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::runWithScene));
mt.set_function("PushScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::pushScene));
mt.set_function("PopScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popScene));
mt.set_function("PopToRootScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popToRootScene));
mt.set_function("PopToSceneStackLevel",static_cast<void(cocos2d::Director::*)(int)>(&cocos2d::Director::popToSceneStackLevel));
mt.set_function("ReplaceScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::replaceScene));
mt.set_function("End",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::end));
mt.set_function("Pause",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::pause));
mt.set_function("Resume",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resume));
mt.set_function("Restart",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::restart));
mt.set_function("StopAnimation",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::stopAnimation));
mt.set_function("StartAnimation",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::startAnimation));
mt.set_function("DrawScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::drawScene));
mt.set_function("PurgeCachedData",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::purgeCachedData));
mt.set_function("SetDefaultValues",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setDefaultValues));
mt.set_function("SetGLDefaultValues",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setGLDefaultValues));
mt.set_function("SetClearColor",static_cast<void(cocos2d::Director::*)(const cocos2d::Color4F&)>(&cocos2d::Director::setClearColor));
mt.set_function("MainLoop",sol::overload(static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::mainLoop),static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::mainLoop)));
mt.set_function("SetContentScaleFactor",static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setContentScaleFactor));
mt.set_function("GetContentScaleFactor",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getContentScaleFactor));
mt.set_function("GetScheduler",static_cast<cocos2d::Scheduler*(cocos2d::Director::*)()const>(&cocos2d::Director::getScheduler));
mt.set_function("SetScheduler",static_cast<void(cocos2d::Director::*)(cocos2d::Scheduler*)>(&cocos2d::Director::setScheduler));
mt.set_function("GetActionManager",static_cast<cocos2d::ActionManager*(cocos2d::Director::*)()const>(&cocos2d::Director::getActionManager));
mt.set_function("SetActionManager",static_cast<void(cocos2d::Director::*)(cocos2d::ActionManager*)>(&cocos2d::Director::setActionManager));
mt.set_function("GetEventDispatcher",static_cast<cocos2d::EventDispatcher*(cocos2d::Director::*)()const>(&cocos2d::Director::getEventDispatcher));
mt.set_function("SetEventDispatcher",static_cast<void(cocos2d::Director::*)(cocos2d::EventDispatcher*)>(&cocos2d::Director::setEventDispatcher));
mt.set_function("GetRenderer",static_cast<cocos2d::Renderer*(cocos2d::Director::*)()const>(&cocos2d::Director::getRenderer));
mt.set_function("GetConsole",static_cast<cocos2d::Console*(cocos2d::Director::*)()const>(&cocos2d::Director::getConsole));
mt.set_function("GetDeltaTime",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getDeltaTime));
mt.set_function("GetFrameRate",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getFrameRate));
mt.set_function("PushMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::pushMatrix));
mt.set_function("PopMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::popMatrix));
mt.set_function("LoadIdentityMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::loadIdentityMatrix));
mt.set_function("LoadMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::loadMatrix));
mt.set_function("MultiplyMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::multiplyMatrix));
mt.set_function("GetMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)const>(&cocos2d::Director::getMatrix));
mt.set_function("ResetMatrixStack",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resetMatrixStack));
mt.set_function("GetCocos2DThreadId",static_cast<const std::thread::id&(cocos2d::Director::*)()const>(&cocos2d::Director::getCocos2dThreadId));
mt.set_function("IsValid",static_cast<bool(cocos2d::Director::*)()const>(&cocos2d::Director::isValid));
mt[sol::call_constructor]=sol::constructors<cocos2d::Director()>();
mt["EVENT_BEFORE_SET_NEXT_SCENE"]=sol::var(std::ref(cocos2d::Director::EVENT_BEFORE_SET_NEXT_SCENE));
mt["EVENT_AFTER_SET_NEXT_SCENE"]=sol::var(std::ref(cocos2d::Director::EVENT_AFTER_SET_NEXT_SCENE));
mt["EVENT_PROJECTION_CHANGED"]=sol::var(std::ref(cocos2d::Director::EVENT_PROJECTION_CHANGED));
mt["EVENT_BEFORE_UPDATE"]=sol::var(std::ref(cocos2d::Director::EVENT_BEFORE_UPDATE));
mt["EVENT_AFTER_UPDATE"]=sol::var(std::ref(cocos2d::Director::EVENT_AFTER_UPDATE));
mt["EVENT_RESET"]=sol::var(std::ref(cocos2d::Director::EVENT_RESET));
mt["EVENT_AFTER_VISIT"]=sol::var(std::ref(cocos2d::Director::EVENT_AFTER_VISIT));
mt["EVENT_AFTER_DRAW"]=sol::var(std::ref(cocos2d::Director::EVENT_AFTER_DRAW));
mt["EVENT_BEFORE_DRAW"]=sol::var(std::ref(cocos2d::Director::EVENT_BEFORE_DRAW));
mt["Instance"]=sol::readonly_property(&cocos2d::Director::getInstance);
}
void RegisterLuaCoreTimerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Timer>("cc","Timer",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetupTimerWithInterval",static_cast<void(cocos2d::Timer::*)(float,unsigned int,float)>(&cocos2d::Timer::setupTimerWithInterval));
mt.set_function("SetAborted",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::setAborted));
mt.set_function("IsAborted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isAborted));
mt.set_function("IsExhausted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isExhausted));
mt.set_function("Trigger",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::trigger));
mt.set_function("Cancel",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::cancel));
mt.set_function("Update",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::update));
}
void RegisterLuaCoreSchedulerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Scheduler>("cc","Scheduler",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetTimeScale",static_cast<float(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::getTimeScale));
mt.set_function("SetTimeScale",static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::setTimeScale));
mt.set_function("Update",static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::update));
mt.set_function("Schedule",sol::overload(static_cast<void(cocos2d::Scheduler::*)(const cocos2d::ccSchedulerFunc&,void*,float,bool,const std::string&)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(const cocos2d::ccSchedulerFunc&,void*,float,unsigned int,float,bool,const std::string&)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*,float,unsigned int,float,bool)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*,float,bool)>(&cocos2d::Scheduler::schedule)));
mt.set_function("Unschedule",sol::overload(static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*)>(&cocos2d::Scheduler::unschedule),static_cast<void(cocos2d::Scheduler::*)(const std::string&,void*)>(&cocos2d::Scheduler::unschedule)));
mt.set_function("UnscheduleUpdate",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::unscheduleUpdate));
mt.set_function("UnscheduleAllForTarget",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::unscheduleAllForTarget));
mt.set_function("UnscheduleAll",static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::unscheduleAll));
mt.set_function("UnscheduleAllWithMinPriority",static_cast<void(cocos2d::Scheduler::*)(int)>(&cocos2d::Scheduler::unscheduleAllWithMinPriority));
mt.set_function("IsScheduled",sol::overload(static_cast<bool(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,const cocos2d::Ref*)const>(&cocos2d::Scheduler::isScheduled),static_cast<bool(cocos2d::Scheduler::*)(const std::string&,const void*)const>(&cocos2d::Scheduler::isScheduled)));
mt.set_function("PauseTarget",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::pauseTarget));
mt.set_function("ResumeTarget",static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::resumeTarget));
mt.set_function("IsTargetPaused",static_cast<bool(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::isTargetPaused));
mt.set_function("PauseAllTargets",static_cast<std::set<void *, std::less<void *>, std::allocator<void *> >(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::pauseAllTargets));
mt.set_function("PauseAllTargetsWithMinPriority",static_cast<std::set<void *, std::less<void *>, std::allocator<void *> >(cocos2d::Scheduler::*)(int)>(&cocos2d::Scheduler::pauseAllTargetsWithMinPriority));
mt.set_function("ResumeTargets",static_cast<void(cocos2d::Scheduler::*)(const std::set<void *, std::less<void *>, std::allocator<void *> >&)>(&cocos2d::Scheduler::resumeTargets));
mt.set_function("PerformFunctionInCocosThread",static_cast<void(cocos2d::Scheduler::*)(std::function<void ()>)>(&cocos2d::Scheduler::performFunctionInCocosThread));
mt.set_function("RemoveAllFunctionsToBePerformedInCocosThread",static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::removeAllFunctionsToBePerformedInCocosThread));
mt[sol::call_constructor]=sol::constructors<cocos2d::Scheduler()>();
mt["PRIORITY_SYSTEM"]=sol::var(std::ref(cocos2d::Scheduler::PRIORITY_SYSTEM));
mt["PRIORITY_NON_SYSTEM_MIN"]=sol::var(std::ref(cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN));
}
void RegisterLuaCoreAsyncTaskPoolTaskTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["AsyncTaskPool"];
pTable.new_enum<cocos2d::AsyncTaskPool::TaskType>("TaskType",{
{"TASK_IO",cocos2d::AsyncTaskPool::TaskType::TASK_IO}
,{"TASK_NETWORK",cocos2d::AsyncTaskPool::TaskType::TASK_NETWORK}
,{"TASK_OTHER",cocos2d::AsyncTaskPool::TaskType::TASK_OTHER}
,{"TASK_MAX_TYPE",cocos2d::AsyncTaskPool::TaskType::TASK_MAX_TYPE}
});}
void RegisterLuaCoreAsyncTaskPoolAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AsyncTaskPool>("cc","AsyncTaskPool",true);
mt.set_function("GetInstance",static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance));
mt.set_function("StopTasks",static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks));
RegisterLuaCoreAsyncTaskPoolTaskTypeAuto(lua);
mt["Instance"]=sol::property(&cocos2d::AsyncTaskPool::getInstance,[](std::nullptr_t){cocos2d::AsyncTaskPool::destroyInstance();});
}
void RegisterLuaCoreActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Action>("cc","Action",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Description",static_cast<std::string(cocos2d::Action::*)()const>(&cocos2d::Action::description));
mt.set_function("Clone",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::clone));
mt.set_function("Reverse",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::reverse));
mt.set_function("IsDone",static_cast<bool(cocos2d::Action::*)()const>(&cocos2d::Action::isDone));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Action::*)()>(&cocos2d::Action::stop));
mt.set_function("Step",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::step));
mt.set_function("Update",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::update));
mt.set_function("GetTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getTarget));
mt.set_function("SetTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setTarget));
mt.set_function("GetOriginalTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getOriginalTarget));
mt.set_function("SetOriginalTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setOriginalTarget));
mt.set_function("GetTag",static_cast<int(cocos2d::Action::*)()const>(&cocos2d::Action::getTag));
mt.set_function("SetTag",static_cast<void(cocos2d::Action::*)(int)>(&cocos2d::Action::setTag));
mt.set_function("GetFlags",static_cast<unsigned int(cocos2d::Action::*)()const>(&cocos2d::Action::getFlags));
mt.set_function("SetFlags",static_cast<void(cocos2d::Action::*)(unsigned int)>(&cocos2d::Action::setFlags));
mt["INVALID_TAG"]=sol::var(std::ref(cocos2d::Action::INVALID_TAG));
}
void RegisterLuaCoreFiniteTimeActionAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FiniteTimeAction>("cc","FiniteTimeAction",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetDuration",static_cast<float(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::getDuration));
mt.set_function("SetDuration",static_cast<void(cocos2d::FiniteTimeAction::*)(float)>(&cocos2d::FiniteTimeAction::setDuration));
mt.set_function("Reverse",static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::reverse));
mt.set_function("Clone",static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::clone));
}
void RegisterLuaCoreSpeedAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Speed>("cc","Speed",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Speed*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::create));
mt.set_function("GetSpeed",static_cast<float(cocos2d::Speed::*)()const>(&cocos2d::Speed::getSpeed));
mt.set_function("SetSpeed",static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::setSpeed));
mt.set_function("SetInnerAction",static_cast<void(cocos2d::Speed::*)(cocos2d::ActionInterval*)>(&cocos2d::Speed::setInnerAction));
mt.set_function("GetInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::Speed::*)()const>(&cocos2d::Speed::getInnerAction));
mt.set_function("Clone",static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::clone));
mt.set_function("Reverse",static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::reverse));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::Speed::*)(cocos2d::Node*)>(&cocos2d::Speed::startWithTarget));
mt.set_function("Stop",static_cast<void(cocos2d::Speed::*)()>(&cocos2d::Speed::stop));
mt.set_function("Step",static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::step));
mt.set_function("IsDone",static_cast<bool(cocos2d::Speed::*)()const>(&cocos2d::Speed::isDone));
}
void RegisterLuaCoreFollowAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Follow>("cc","Follow",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->create(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);}));
mt.set_function("CreateWithOffset",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->createWithOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->createWithOffset(arg0,arg1,arg2,arg3);}));
mt.set_function("IsBoundarySet",static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isBoundarySet));
mt.set_function("SetBoundarySet",static_cast<void(cocos2d::Follow::*)(bool)>(&cocos2d::Follow::setBoundarySet));
mt.set_function("Clone",static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::clone));
mt.set_function("Reverse",static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::reverse));
mt.set_function("Step",static_cast<void(cocos2d::Follow::*)(float)>(&cocos2d::Follow::step));
mt.set_function("IsDone",static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isDone));
mt.set_function("Stop",static_cast<void(cocos2d::Follow::*)()>(&cocos2d::Follow::stop));
}
void RegisterLuaCoreImageFormatAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Image"];
pTable.new_enum<cocos2d::Image::Format>("Format",{
{"JPG",cocos2d::Image::Format::JPG}
,{"PNG",cocos2d::Image::Format::PNG}
,{"BMP",cocos2d::Image::Format::BMP}
,{"WEBP",cocos2d::Image::Format::WEBP}
,{"PVR",cocos2d::Image::Format::PVR}
,{"ETC1",cocos2d::Image::Format::ETC1}
,{"ETC2",cocos2d::Image::Format::ETC2}
,{"S3TC",cocos2d::Image::Format::S3TC}
,{"ATITC",cocos2d::Image::Format::ATITC}
,{"TGA",cocos2d::Image::Format::TGA}
,{"ASTC",cocos2d::Image::Format::ASTC}
,{"RAW_DATA",cocos2d::Image::Format::RAW_DATA}
,{"UNKNOWN",cocos2d::Image::Format::UNKNOWN}
});}
void RegisterLuaCoreImageAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Image>("cc","Image",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetPNGPremultipliedAlphaEnabled",static_cast<void(*)(bool)>(&cocos2d::Image::setPNGPremultipliedAlphaEnabled));
mt.set_function("SetCompressedImagesHavePMA",static_cast<void(*)(uint32_t,bool)>(&cocos2d::Image::setCompressedImagesHavePMA));
mt.set_function("IsCompressedImageHavePMA",static_cast<bool(*)(uint32_t)>(&cocos2d::Image::isCompressedImageHavePMA));
mt.set_function("InitWithImageFile",static_cast<bool(cocos2d::Image::*)(const std::string&)>(&cocos2d::Image::initWithImageFile));
mt.set_function("InitWithImageData",sol::overload([](cocos2d::Image* obj,const uint8_t* arg0,ssize_t arg1){return obj->initWithImageData(arg0,arg1);},[](cocos2d::Image* obj,const uint8_t* arg0,ssize_t arg1,bool arg2){return obj->initWithImageData(arg0,arg1,arg2);}));
mt.set_function("InitWithRawData",sol::overload([](cocos2d::Image* obj,const uint8_t* arg0,ssize_t arg1,int arg2,int arg3,int arg4){return obj->initWithRawData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Image* obj,const uint8_t* arg0,ssize_t arg1,int arg2,int arg3,int arg4,bool arg5){return obj->initWithRawData(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("GetData",static_cast<uint8_t*(cocos2d::Image::*)()>(&cocos2d::Image::getData));
mt.set_function("GetDataLen",static_cast<ssize_t(cocos2d::Image::*)()>(&cocos2d::Image::getDataLen));
mt.set_function("GetFileType",static_cast<cocos2d::Image::Format(cocos2d::Image::*)()>(&cocos2d::Image::getFileType));
mt.set_function("GetPixelFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::Image::*)()>(&cocos2d::Image::getPixelFormat));
mt.set_function("GetWidth",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getWidth));
mt.set_function("GetHeight",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getHeight));
mt.set_function("GetNumberOfMipmaps",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getNumberOfMipmaps));
mt.set_function("GetMipmaps",static_cast<cocos2d::MipmapInfo*(cocos2d::Image::*)()>(&cocos2d::Image::getMipmaps));
mt.set_function("HasPremultipliedAlpha",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasPremultipliedAlpha));
mt.set_function("GetFilePath",static_cast<std::string(cocos2d::Image::*)()const>(&cocos2d::Image::getFilePath));
mt.set_function("GetBitPerPixel",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getBitPerPixel));
mt.set_function("HasAlpha",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasAlpha));
mt.set_function("IsCompressed",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::isCompressed));
mt.set_function("SaveToFile",sol::overload([](cocos2d::Image* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::Image* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);}));
mt.set_function("PremultiplyAlpha",static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::premultiplyAlpha));
mt.set_function("ReversePremultipliedAlpha",static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::reversePremultipliedAlpha));
mt[sol::call_constructor]=sol::constructors<cocos2d::Image()>();
RegisterLuaCoreImageFormatAuto(lua);
}
void RegisterLuaCorePolygonInfoAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PolygonInfo>("cc","PolygonInfo",false);
mt.set_function("Operator=",static_cast<cocos2d::PolygonInfo&(cocos2d::PolygonInfo::*)(const cocos2d::PolygonInfo&)>(&cocos2d::PolygonInfo::operator=));
mt.set_function("SetQuad",static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*)>(&cocos2d::PolygonInfo::setQuad));
mt.set_function("SetQuads",static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*,int)>(&cocos2d::PolygonInfo::setQuads));
mt.set_function("SetTriangles",static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::TrianglesCommand::Triangles&)>(&cocos2d::PolygonInfo::setTriangles));
mt.set_function("GetVertCount",static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getVertCount));
mt.set_function("GetTrianglesCount",static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getTrianglesCount));
mt.set_function("GetArea",static_cast<float(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getArea));
mt.set_function("GetRect",static_cast<const cocos2d::Rect&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getRect));
mt.set_function("SetRect",static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::Rect&)>(&cocos2d::PolygonInfo::setRect));
mt.set_function("GetFilename",static_cast<const std::string&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getFilename));
mt.set_function("SetFilename",static_cast<void(cocos2d::PolygonInfo::*)(const std::string&)>(&cocos2d::PolygonInfo::setFilename));
mt[sol::call_constructor]=sol::constructors<cocos2d::PolygonInfo(),cocos2d::PolygonInfo(const cocos2d::PolygonInfo&)>();
mt["Triangles"]=&cocos2d::PolygonInfo::triangles;
}
