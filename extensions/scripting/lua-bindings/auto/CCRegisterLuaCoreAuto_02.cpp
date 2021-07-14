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
namespace cocos2d{
void RegisterLuaCoreDirectorAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Director).name()] = sol::usertype_traits<cocos2d::Director*>::metatable();
auto dep=lua.new_usertype<cocos2d::Director>("deprecated.cocos2d::Director");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Director*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Director"]=mt;
mt["__new__"]=[](){return new cocos2d::Director();};
mt["static"]["GetInstance"]=static_cast<cocos2d::Director*(*)()>(&cocos2d::Director::getInstance);
mt["Init"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::init);
mt["GetRunningScene"]=static_cast<cocos2d::Scene*(cocos2d::Director::*)()>(&cocos2d::Director::getRunningScene);
mt["get"]["RunningScene"]=mt["GetRunningScene"];
mt["GetAnimationInterval"]=static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getAnimationInterval);
mt["get"]["AnimationInterval"]=mt["GetAnimationInterval"];
mt["SetAnimationInterval"]=static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setAnimationInterval);
mt["set"]["AnimationInterval"]=mt["SetAnimationInterval"];
mt["IsDisplayStats"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isDisplayStats);
mt["get"]["DisplayStats"]=mt["IsDisplayStats"];
mt["SetDisplayStats"]=static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setDisplayStats);
mt["set"]["DisplayStats"]=mt["SetDisplayStats"];
mt["GetSecondsPerFrame"]=static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getSecondsPerFrame);
mt["get"]["SecondsPerFrame"]=mt["GetSecondsPerFrame"];
mt["GetOpenGLView"]=static_cast<cocos2d::GLView*(cocos2d::Director::*)()>(&cocos2d::Director::getOpenGLView);
mt["get"]["OpenGLView"]=mt["GetOpenGLView"];
mt["SetOpenGLView"]=static_cast<void(cocos2d::Director::*)(cocos2d::GLView*)>(&cocos2d::Director::setOpenGLView);
mt["set"]["OpenGLView"]=mt["SetOpenGLView"];
mt["GetTextureCache"]=static_cast<cocos2d::TextureCache*(cocos2d::Director::*)()const>(&cocos2d::Director::getTextureCache);
mt["get"]["TextureCache"]=mt["GetTextureCache"];
mt["IsNextDeltaTimeZero"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isNextDeltaTimeZero);
mt["get"]["NextDeltaTimeZero"]=mt["IsNextDeltaTimeZero"];
mt["SetNextDeltaTimeZero"]=static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setNextDeltaTimeZero);
mt["set"]["NextDeltaTimeZero"]=mt["SetNextDeltaTimeZero"];
mt["IsPaused"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isPaused);
mt["get"]["Paused"]=mt["IsPaused"];
mt["GetTotalFrames"]=static_cast<unsigned int(cocos2d::Director::*)()>(&cocos2d::Director::getTotalFrames);
mt["get"]["TotalFrames"]=mt["GetTotalFrames"];
mt["GetProjection"]=static_cast<cocos2d::Director::Projection(cocos2d::Director::*)()>(&cocos2d::Director::getProjection);
mt["get"]["Projection"]=mt["GetProjection"];
mt["SetProjection"]=static_cast<void(cocos2d::Director::*)(cocos2d::Director::Projection)>(&cocos2d::Director::setProjection);
mt["set"]["Projection"]=mt["SetProjection"];
mt["SetViewport"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setViewport);
mt["IsSendCleanupToScene"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isSendCleanupToScene);
mt["get"]["SendCleanupToScene"]=mt["IsSendCleanupToScene"];
mt["GetNotificationNode"]=static_cast<cocos2d::Node*(cocos2d::Director::*)()const>(&cocos2d::Director::getNotificationNode);
mt["get"]["NotificationNode"]=mt["GetNotificationNode"];
mt["SetNotificationNode"]=static_cast<void(cocos2d::Director::*)(cocos2d::Node*)>(&cocos2d::Director::setNotificationNode);
mt["set"]["NotificationNode"]=mt["SetNotificationNode"];
mt["GetWinSize"]=static_cast<const cocos2d::Size&(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSize);
mt["get"]["WinSize"]=mt["GetWinSize"];
mt["GetWinSizeInPixels"]=static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSizeInPixels);
mt["get"]["WinSizeInPixels"]=mt["GetWinSizeInPixels"];
mt["GetVisibleSize"]=static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleSize);
mt["get"]["VisibleSize"]=mt["GetVisibleSize"];
mt["GetVisibleOrigin"]=static_cast<cocos2d::Vec2(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleOrigin);
mt["get"]["VisibleOrigin"]=mt["GetVisibleOrigin"];
mt["GetSafeAreaRect"]=static_cast<cocos2d::Rect(cocos2d::Director::*)()const>(&cocos2d::Director::getSafeAreaRect);
mt["get"]["SafeAreaRect"]=mt["GetSafeAreaRect"];
mt["ConvertToGL"]=static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToGL);
mt["ConvertToUI"]=static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToUI);
mt["GetZEye"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getZEye);
mt["get"]["ZEye"]=mt["GetZEye"];
mt["RunWithScene"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::runWithScene);
mt["PushScene"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::pushScene);
mt["PopScene"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popScene);
mt["PopToRootScene"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popToRootScene);
mt["PopToSceneStackLevel"]=static_cast<void(cocos2d::Director::*)(int)>(&cocos2d::Director::popToSceneStackLevel);
mt["ReplaceScene"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::replaceScene);
mt["End"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::end);
mt["Pause"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::pause);
mt["Resume"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resume);
mt["Restart"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::restart);
mt["StopAnimation"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::stopAnimation);
mt["StartAnimation"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::startAnimation);
mt["DrawScene"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::drawScene);
mt["PurgeCachedData"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::purgeCachedData);
mt["SetDefaultValues"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setDefaultValues);
mt["SetGLDefaultValues"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setGLDefaultValues);
mt["SetClearColor"]=static_cast<void(cocos2d::Director::*)(const cocos2d::Color4F&)>(&cocos2d::Director::setClearColor);
mt["set"]["ClearColor"]=mt["SetClearColor"];
mt["MainLoop"]=sol::overload(static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::mainLoop),static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::mainLoop));
mt["SetContentScaleFactor"]=static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setContentScaleFactor);
mt["set"]["ContentScaleFactor"]=mt["SetContentScaleFactor"];
mt["GetContentScaleFactor"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getContentScaleFactor);
mt["get"]["ContentScaleFactor"]=mt["GetContentScaleFactor"];
mt["GetScheduler"]=static_cast<cocos2d::Scheduler*(cocos2d::Director::*)()const>(&cocos2d::Director::getScheduler);
mt["get"]["Scheduler"]=mt["GetScheduler"];
mt["SetScheduler"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scheduler*)>(&cocos2d::Director::setScheduler);
mt["set"]["Scheduler"]=mt["SetScheduler"];
mt["GetActionManager"]=static_cast<cocos2d::ActionManager*(cocos2d::Director::*)()const>(&cocos2d::Director::getActionManager);
mt["get"]["ActionManager"]=mt["GetActionManager"];
mt["SetActionManager"]=static_cast<void(cocos2d::Director::*)(cocos2d::ActionManager*)>(&cocos2d::Director::setActionManager);
mt["set"]["ActionManager"]=mt["SetActionManager"];
mt["GetEventDispatcher"]=static_cast<cocos2d::EventDispatcher*(cocos2d::Director::*)()const>(&cocos2d::Director::getEventDispatcher);
mt["get"]["EventDispatcher"]=mt["GetEventDispatcher"];
mt["SetEventDispatcher"]=static_cast<void(cocos2d::Director::*)(cocos2d::EventDispatcher*)>(&cocos2d::Director::setEventDispatcher);
mt["set"]["EventDispatcher"]=mt["SetEventDispatcher"];
mt["GetRenderer"]=static_cast<cocos2d::Renderer*(cocos2d::Director::*)()const>(&cocos2d::Director::getRenderer);
mt["get"]["Renderer"]=mt["GetRenderer"];
mt["GetDeltaTime"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getDeltaTime);
mt["get"]["DeltaTime"]=mt["GetDeltaTime"];
mt["GetFrameRate"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getFrameRate);
mt["get"]["FrameRate"]=mt["GetFrameRate"];
mt["PushMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::pushMatrix);
mt["PopMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::popMatrix);
mt["LoadIdentityMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::loadIdentityMatrix);
mt["LoadMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::loadMatrix);
mt["MultiplyMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::multiplyMatrix);
mt["GetMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)const>(&cocos2d::Director::getMatrix);
mt["ResetMatrixStack"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resetMatrixStack);
mt["GetCocos2DThreadId"]=static_cast<const std::thread::id&(cocos2d::Director::*)()const>(&cocos2d::Director::getCocos2dThreadId);
mt["get"]["Cocos2DThreadId"]=mt["GetCocos2DThreadId"];
mt["IsValid"]=static_cast<bool(cocos2d::Director::*)()const>(&cocos2d::Director::isValid);
mt["get"]["Valid"]=mt["IsValid"];
mt["static"]["get"]["Instance"]=&cocos2d::Director::getInstance;
}
void RegisterLuaCoreTimerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Timer).name()] = sol::usertype_traits<cocos2d::Timer*>::metatable();
auto dep=lua.new_usertype<cocos2d::Timer>("deprecated.cocos2d::Timer");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Timer*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Timer"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["SetupTimerWithInterval"]=static_cast<void(cocos2d::Timer::*)(float,unsigned int,float)>(&cocos2d::Timer::setupTimerWithInterval);
mt["SetAborted"]=static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::setAborted);
mt["IsAborted"]=static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isAborted);
mt["get"]["Aborted"]=mt["IsAborted"];
mt["IsExhausted"]=static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isExhausted);
mt["get"]["Exhausted"]=mt["IsExhausted"];
mt["Trigger"]=static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::trigger);
mt["Cancel"]=static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::cancel);
mt["Update"]=static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::update);
}
void RegisterLuaCoreSchedulerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Scheduler).name()] = sol::usertype_traits<cocos2d::Scheduler*>::metatable();
auto dep=lua.new_usertype<cocos2d::Scheduler>("deprecated.cocos2d::Scheduler");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Scheduler*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Scheduler"]=mt;
mt["__new__"]=[](){return new cocos2d::Scheduler();};
mt["GetTimeScale"]=static_cast<float(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::getTimeScale);
mt["get"]["TimeScale"]=mt["GetTimeScale"];
mt["SetTimeScale"]=static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::setTimeScale);
mt["set"]["TimeScale"]=mt["SetTimeScale"];
mt["Update"]=static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::update);
mt["Schedule"]=sol::overload(static_cast<void(cocos2d::Scheduler::*)(const cocos2d::ccSchedulerFunc&,void*,float,unsigned int,float,bool,const std::string&)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*,float,unsigned int,float,bool)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(const cocos2d::ccSchedulerFunc&,void*,float,bool,const std::string&)>(&cocos2d::Scheduler::schedule),static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*,float,bool)>(&cocos2d::Scheduler::schedule));
mt["Unschedule"]=sol::overload(static_cast<void(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,cocos2d::Ref*)>(&cocos2d::Scheduler::unschedule),static_cast<void(cocos2d::Scheduler::*)(const std::string&,void*)>(&cocos2d::Scheduler::unschedule));
mt["UnscheduleUpdate"]=static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::unscheduleUpdate);
mt["UnscheduleAllForTarget"]=static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::unscheduleAllForTarget);
mt["UnscheduleAll"]=static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::unscheduleAll);
mt["UnscheduleAllWithMinPriority"]=static_cast<void(cocos2d::Scheduler::*)(int)>(&cocos2d::Scheduler::unscheduleAllWithMinPriority);
mt["IsScheduled"]=sol::overload(static_cast<bool(cocos2d::Scheduler::*)(cocos2d::SEL_SCHEDULE,const cocos2d::Ref*)const>(&cocos2d::Scheduler::isScheduled),static_cast<bool(cocos2d::Scheduler::*)(const std::string&,const void*)const>(&cocos2d::Scheduler::isScheduled));
mt["PauseTarget"]=static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::pauseTarget);
mt["ResumeTarget"]=static_cast<void(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::resumeTarget);
mt["IsTargetPaused"]=static_cast<bool(cocos2d::Scheduler::*)(void*)>(&cocos2d::Scheduler::isTargetPaused);
mt["PauseAllTargets"]=static_cast<std::set<void *, std::less<void *>, std::allocator<void *> >(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::pauseAllTargets);
mt["PauseAllTargetsWithMinPriority"]=static_cast<std::set<void *, std::less<void *>, std::allocator<void *> >(cocos2d::Scheduler::*)(int)>(&cocos2d::Scheduler::pauseAllTargetsWithMinPriority);
mt["ResumeTargets"]=static_cast<void(cocos2d::Scheduler::*)(const std::set<void *, std::less<void *>, std::allocator<void *> >&)>(&cocos2d::Scheduler::resumeTargets);
mt["PerformFunctionInCocosThread"]=static_cast<void(cocos2d::Scheduler::*)(std::function<void ()>)>(&cocos2d::Scheduler::performFunctionInCocosThread);
mt["RemoveAllFunctionsToBePerformedInCocosThread"]=static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::removeAllFunctionsToBePerformedInCocosThread);
mt["static"]["get"]["PRIORITY_SYSTEM"]=[]()->const int&{return cocos2d::Scheduler::PRIORITY_SYSTEM;};
mt["static"]["get"]["PRIORITY_NON_SYSTEM_MIN"]=[]()->const int&{return cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN;};
}
void RegisterLuaCoreAsyncTaskPoolTaskTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["TASK_IO"]=cocos2d::AsyncTaskPool::TaskType::TASK_IO;
enumTable["TASK_NETWORK"]=cocos2d::AsyncTaskPool::TaskType::TASK_NETWORK;
enumTable["TASK_OTHER"]=cocos2d::AsyncTaskPool::TaskType::TASK_OTHER;
enumTable["TASK_MAX_TYPE"]=cocos2d::AsyncTaskPool::TaskType::TASK_MAX_TYPE;
lua["cc"]["AsyncTaskPool"]["static"]["TaskType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreAsyncTaskPoolAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AsyncTaskPool).name()] = sol::usertype_traits<cocos2d::AsyncTaskPool*>::metatable();
auto dep=lua.new_usertype<cocos2d::AsyncTaskPool>("deprecated.cocos2d::AsyncTaskPool");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AsyncTaskPool*>::metatable());
lua["cc"]["AsyncTaskPool"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance);
mt["StopTasks"]=static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks);
RegisterLuaCoreAsyncTaskPoolTaskTypeAuto(lua);
mt["static"]["get"]["Instance"]=&cocos2d::AsyncTaskPool::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocos2d::AsyncTaskPool::destroyInstance();};
}
void RegisterLuaCoreActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Action).name()] = sol::usertype_traits<cocos2d::Action*>::metatable();
auto dep=lua.new_usertype<cocos2d::Action>("deprecated.cocos2d::Action");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Action*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["Action"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["Description"]=static_cast<std::string(cocos2d::Action::*)()const>(&cocos2d::Action::description);
mt["Reverse"]=static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::reverse);
mt["IsDone"]=static_cast<bool(cocos2d::Action::*)()const>(&cocos2d::Action::isDone);
mt["get"]["Done"]=mt["IsDone"];
mt["StartWithTarget"]=static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::startWithTarget);
mt["Stop"]=static_cast<void(cocos2d::Action::*)()>(&cocos2d::Action::stop);
mt["Step"]=static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::step);
mt["Update"]=static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::update);
mt["GetTarget"]=static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getTarget);
mt["get"]["Target"]=mt["GetTarget"];
mt["SetTarget"]=static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setTarget);
mt["set"]["Target"]=mt["SetTarget"];
mt["GetOriginalTarget"]=static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getOriginalTarget);
mt["get"]["OriginalTarget"]=mt["GetOriginalTarget"];
mt["SetOriginalTarget"]=static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setOriginalTarget);
mt["set"]["OriginalTarget"]=mt["SetOriginalTarget"];
mt["GetTag"]=static_cast<int(cocos2d::Action::*)()const>(&cocos2d::Action::getTag);
mt["get"]["Tag"]=mt["GetTag"];
mt["SetTag"]=static_cast<void(cocos2d::Action::*)(int)>(&cocos2d::Action::setTag);
mt["set"]["Tag"]=mt["SetTag"];
mt["GetFlags"]=static_cast<unsigned int(cocos2d::Action::*)()const>(&cocos2d::Action::getFlags);
mt["get"]["Flags"]=mt["GetFlags"];
mt["SetFlags"]=static_cast<void(cocos2d::Action::*)(unsigned int)>(&cocos2d::Action::setFlags);
mt["set"]["Flags"]=mt["SetFlags"];
mt["static"]["get"]["INVALID_TAG"]=[]()->const int&{return cocos2d::Action::INVALID_TAG;};
}
void RegisterLuaCoreFiniteTimeActionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FiniteTimeAction).name()] = sol::usertype_traits<cocos2d::FiniteTimeAction*>::metatable();
auto dep=lua.new_usertype<cocos2d::FiniteTimeAction>("deprecated.cocos2d::FiniteTimeAction");
dep[sol::base_classes]=sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FiniteTimeAction*>::metatable(),sol::usertype_traits<cocos2d::Action*>::metatable());
lua["cc"]["FiniteTimeAction"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetDuration"]=static_cast<float(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::getDuration);
mt["get"]["Duration"]=mt["GetDuration"];
mt["SetDuration"]=static_cast<void(cocos2d::FiniteTimeAction::*)(float)>(&cocos2d::FiniteTimeAction::setDuration);
mt["set"]["Duration"]=mt["SetDuration"];
}
void RegisterLuaCoreSpeedAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Speed).name()] = sol::usertype_traits<cocos2d::Speed*>::metatable();
auto dep=lua.new_usertype<cocos2d::Speed>("deprecated.cocos2d::Speed");
dep[sol::base_classes]=sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Speed*>::metatable(),sol::usertype_traits<cocos2d::Action*>::metatable());
lua["cc"]["Speed"]=mt;
mt["__new__"]=static_cast<cocos2d::Speed*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::create);
mt["GetSpeed"]=static_cast<float(cocos2d::Speed::*)()const>(&cocos2d::Speed::getSpeed);
mt["get"]["Speed"]=mt["GetSpeed"];
mt["SetSpeed"]=static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::setSpeed);
mt["set"]["Speed"]=mt["SetSpeed"];
mt["SetInnerAction"]=static_cast<void(cocos2d::Speed::*)(cocos2d::ActionInterval*)>(&cocos2d::Speed::setInnerAction);
mt["set"]["InnerAction"]=mt["SetInnerAction"];
mt["GetInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::Speed::*)()const>(&cocos2d::Speed::getInnerAction);
mt["get"]["InnerAction"]=mt["GetInnerAction"];
}
void RegisterLuaCoreFollowAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Follow).name()] = sol::usertype_traits<cocos2d::Follow*>::metatable();
auto dep=lua.new_usertype<cocos2d::Follow>("deprecated.cocos2d::Follow");
dep[sol::base_classes]=sol::bases<cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Follow*>::metatable(),sol::usertype_traits<cocos2d::Action*>::metatable());
lua["cc"]["Follow"]=mt;
mt["__new__"]=sol::overload([](cocos2d::Node* arg0,const cocos2d::Rect& arg1){return cocos2d::Follow::create(arg0,arg1);},[](cocos2d::Node* arg0){return cocos2d::Follow::create(arg0);});
mt["static"]["CreateWithOffset"]=sol::overload([](cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return cocos2d::Follow::createWithOffset(arg0,arg1,arg2,arg3);},[](cocos2d::Node* arg0,float arg1,float arg2){return cocos2d::Follow::createWithOffset(arg0,arg1,arg2);});
mt["IsBoundarySet"]=static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isBoundarySet);
mt["get"]["BoundarySet"]=mt["IsBoundarySet"];
mt["SetBoundarySet"]=static_cast<void(cocos2d::Follow::*)(bool)>(&cocos2d::Follow::setBoundarySet);
mt["set"]["BoundarySet"]=mt["SetBoundarySet"];
}
void RegisterLuaCoreImageFormatAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,13);
enumTable["JPG"]=cocos2d::Image::Format::JPG;
enumTable["PNG"]=cocos2d::Image::Format::PNG;
enumTable["BMP"]=cocos2d::Image::Format::BMP;
enumTable["WEBP"]=cocos2d::Image::Format::WEBP;
enumTable["PVR"]=cocos2d::Image::Format::PVR;
enumTable["ETC1"]=cocos2d::Image::Format::ETC1;
enumTable["ETC2"]=cocos2d::Image::Format::ETC2;
enumTable["S3TC"]=cocos2d::Image::Format::S3TC;
enumTable["ATITC"]=cocos2d::Image::Format::ATITC;
enumTable["TGA"]=cocos2d::Image::Format::TGA;
enumTable["ASTC"]=cocos2d::Image::Format::ASTC;
enumTable["RAW_DATA"]=cocos2d::Image::Format::RAW_DATA;
enumTable["UNKNOWN"]=cocos2d::Image::Format::UNKNOWN;
lua["cc"]["Image"]["static"]["Format"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreImageAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Image).name()] = sol::usertype_traits<cocos2d::Image*>::metatable();
auto dep=lua.new_usertype<cocos2d::Image>("deprecated.cocos2d::Image");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Image*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Image"]=mt;
mt["__new__"]=[](){return new cocos2d::Image();};
mt["static"]["SetPNGPremultipliedAlphaEnabled"]=static_cast<void(*)(bool)>(&cocos2d::Image::setPNGPremultipliedAlphaEnabled);
mt["static"]["set"]["PNGPremultipliedAlphaEnabled"]=mt["SetPNGPremultipliedAlphaEnabled"];
mt["static"]["SetCompressedImagesHavePMA"]=static_cast<void(*)(uint32_t,bool)>(&cocos2d::Image::setCompressedImagesHavePMA);
mt["static"]["IsCompressedImageHavePMA"]=static_cast<bool(*)(uint32_t)>(&cocos2d::Image::isCompressedImageHavePMA);
mt["InitWithImageFile"]=static_cast<bool(cocos2d::Image::*)(const std::string&)>(&cocos2d::Image::initWithImageFile);
mt["InitWithImageData"]=sol::overload(static_cast<bool(cocos2d::Image::*)(uint8_t*,ssize_t,bool)>(&cocos2d::Image::initWithImageData),static_cast<bool(cocos2d::Image::*)(const uint8_t*,ssize_t)>(&cocos2d::Image::initWithImageData));
mt["InitWithRawData"]=sol::overload([](cocos2d::Image* obj,const uint8_t* arg0,ssize_t arg1,int arg2,int arg3,int arg4,bool arg5){return obj->initWithRawData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Image* obj,const uint8_t* arg0,ssize_t arg1,int arg2,int arg3,int arg4){return obj->initWithRawData(arg0,arg1,arg2,arg3,arg4);});
mt["GetData"]=static_cast<uint8_t*(cocos2d::Image::*)()>(&cocos2d::Image::getData);
mt["get"]["Data"]=mt["GetData"];
mt["GetDataLen"]=static_cast<ssize_t(cocos2d::Image::*)()>(&cocos2d::Image::getDataLen);
mt["get"]["DataLen"]=mt["GetDataLen"];
mt["GetFileType"]=static_cast<cocos2d::Image::Format(cocos2d::Image::*)()>(&cocos2d::Image::getFileType);
mt["get"]["FileType"]=mt["GetFileType"];
mt["GetPixelFormat"]=static_cast<cocos2d::backend::PixelFormat(cocos2d::Image::*)()>(&cocos2d::Image::getPixelFormat);
mt["get"]["PixelFormat"]=mt["GetPixelFormat"];
mt["GetWidth"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getWidth);
mt["get"]["Width"]=mt["GetWidth"];
mt["GetHeight"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getHeight);
mt["get"]["Height"]=mt["GetHeight"];
mt["GetNumberOfMipmaps"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getNumberOfMipmaps);
mt["get"]["NumberOfMipmaps"]=mt["GetNumberOfMipmaps"];
mt["GetMipmaps"]=static_cast<cocos2d::MipmapInfo*(cocos2d::Image::*)()>(&cocos2d::Image::getMipmaps);
mt["get"]["Mipmaps"]=mt["GetMipmaps"];
mt["HasPremultipliedAlpha"]=static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasPremultipliedAlpha);
mt["GetFilePath"]=static_cast<std::string(cocos2d::Image::*)()const>(&cocos2d::Image::getFilePath);
mt["get"]["FilePath"]=mt["GetFilePath"];
mt["GetBitPerPixel"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getBitPerPixel);
mt["get"]["BitPerPixel"]=mt["GetBitPerPixel"];
mt["HasAlpha"]=static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasAlpha);
mt["IsCompressed"]=static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::isCompressed);
mt["get"]["Compressed"]=mt["IsCompressed"];
mt["SaveToFile"]=sol::overload([](cocos2d::Image* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::Image* obj,const std::string& arg0){return obj->saveToFile(arg0);});
mt["PremultiplyAlpha"]=static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::premultiplyAlpha);
mt["ReversePremultipliedAlpha"]=static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::reversePremultipliedAlpha);
RegisterLuaCoreImageFormatAuto(lua);
}
void RegisterLuaCorePolygonInfoAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::PolygonInfo).name()] = sol::usertype_traits<cocos2d::PolygonInfo*>::metatable();
auto dep=lua.new_usertype<cocos2d::PolygonInfo>("deprecated.cocos2d::PolygonInfo");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::PolygonInfo*>::metatable());
lua["cc"]["PolygonInfo"]=mt;
mt["Operator="]=static_cast<cocos2d::PolygonInfo&(cocos2d::PolygonInfo::*)(const cocos2d::PolygonInfo&)>(&cocos2d::PolygonInfo::operator=);
mt["SetQuad"]=static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*)>(&cocos2d::PolygonInfo::setQuad);
mt["set"]["Quad"]=mt["SetQuad"];
mt["SetQuads"]=static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*,int)>(&cocos2d::PolygonInfo::setQuads);
mt["SetTriangles"]=static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::TrianglesCommand::Triangles&)>(&cocos2d::PolygonInfo::setTriangles);
mt["set"]["Triangles"]=mt["SetTriangles"];
mt["GetVertCount"]=static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getVertCount);
mt["get"]["VertCount"]=mt["GetVertCount"];
mt["GetTrianglesCount"]=static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getTrianglesCount);
mt["get"]["TrianglesCount"]=mt["GetTrianglesCount"];
mt["GetArea"]=static_cast<float(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getArea);
mt["get"]["Area"]=mt["GetArea"];
mt["GetRect"]=static_cast<const cocos2d::Rect&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getRect);
mt["get"]["Rect"]=mt["GetRect"];
mt["SetRect"]=static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::Rect&)>(&cocos2d::PolygonInfo::setRect);
mt["set"]["Rect"]=mt["SetRect"];
mt["GetFilename"]=static_cast<const std::string&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getFilename);
mt["get"]["Filename"]=mt["GetFilename"];
mt["SetFilename"]=static_cast<void(cocos2d::PolygonInfo::*)(const std::string&)>(&cocos2d::PolygonInfo::setFilename);
mt["set"]["Filename"]=mt["SetFilename"];
mt["set"]["Triangles"]=[](cocos2d::PolygonInfo* obj,const cocos2d::TrianglesCommand::Triangles& value){obj->triangles = value;};
mt["get"]["Triangles"]=[](cocos2d::PolygonInfo* obj)->const cocos2d::TrianglesCommand::Triangles&{return obj->triangles;};
}
}
