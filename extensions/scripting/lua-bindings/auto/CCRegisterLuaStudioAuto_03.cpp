#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioComAttributeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComAttribute>("ccs","ComAttribute",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAttribute::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ComAttribute*(*)()>(&cocostudio::ComAttribute::create));
mt.set_function("Init",static_cast<bool(cocostudio::ComAttribute::*)()>(&cocostudio::ComAttribute::init));
mt.set_function("Serialize",static_cast<bool(cocostudio::ComAttribute::*)(void*)>(&cocostudio::ComAttribute::serialize));
mt.set_function("SetInt",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,int)>(&cocostudio::ComAttribute::setInt));
mt.set_function("SetFloat",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,float)>(&cocostudio::ComAttribute::setFloat));
mt.set_function("SetBool",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,bool)>(&cocostudio::ComAttribute::setBool));
mt.set_function("SetString",static_cast<void(cocostudio::ComAttribute::*)(const std::string&,const std::string&)>(&cocostudio::ComAttribute::setString));
mt.set_function("GetInt",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getInt(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,int arg1){return obj->getInt(arg0,arg1);}));
mt.set_function("GetFloat",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getFloat(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,float arg1){return obj->getFloat(arg0,arg1);}));
mt.set_function("GetBool",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getBool(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,bool arg1){return obj->getBool(arg0,arg1);}));
mt.set_function("GetString",sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getString(arg0);},[](cocostudio::ComAttribute* obj,const std::string& arg0,const std::string& arg1){return obj->getString(arg0,arg1);}));
mt.set_function("Parse",static_cast<bool(cocostudio::ComAttribute::*)(const std::string&)>(&cocostudio::ComAttribute::parse));
mt[sol::call_constructor]=sol::constructors<cocostudio::ComAttribute()>();
mt["Type"]=sol::var(std::ref(cocostudio::ComAttribute::Type));
mt["COMPONENT_NAME"]=sol::var(std::ref(cocostudio::ComAttribute::COMPONENT_NAME));
}
void RegisterLuaStudioComAudioAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComAudio>("ccs","ComAudio",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::PlayableProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAudio::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ComAudio*(*)()>(&cocostudio::ComAudio::create));
mt.set_function("Init",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::init));
mt.set_function("OnEnter",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onEnter));
mt.set_function("OnExit",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onExit));
mt.set_function("OnAdd",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onAdd));
mt.set_function("OnRemove",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onRemove));
mt.set_function("Serialize",static_cast<bool(cocostudio::ComAudio::*)(void*)>(&cocostudio::ComAudio::serialize));
mt.set_function("End",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::end));
mt.set_function("PreloadBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadBackgroundMusic));
mt.set_function("PlayBackgroundMusic",sol::overload(static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playBackgroundMusic)));
mt.set_function("StopBackgroundMusic",sol::overload(static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::stopBackgroundMusic)));
mt.set_function("PauseBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseBackgroundMusic));
mt.set_function("ResumeBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeBackgroundMusic));
mt.set_function("RewindBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::rewindBackgroundMusic));
mt.set_function("WillPlayBackgroundMusic",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::willPlayBackgroundMusic));
mt.set_function("IsBackgroundMusicPlaying",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isBackgroundMusicPlaying));
mt.set_function("GetBackgroundMusicVolume",static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getBackgroundMusicVolume));
mt.set_function("SetBackgroundMusicVolume",static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setBackgroundMusicVolume));
mt.set_function("GetEffectsVolume",static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getEffectsVolume));
mt.set_function("SetEffectsVolume",static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setEffectsVolume));
mt.set_function("PlayEffect",sol::overload(static_cast<unsigned int(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playEffect)));
mt.set_function("PauseEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::pauseEffect));
mt.set_function("PauseAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseAllEffects));
mt.set_function("ResumeEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::resumeEffect));
mt.set_function("ResumeAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeAllEffects));
mt.set_function("StopEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::stopEffect));
mt.set_function("StopAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopAllEffects));
mt.set_function("PreloadEffect",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadEffect));
mt.set_function("UnloadEffect",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::unloadEffect));
mt.set_function("SetFile",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::setFile));
mt.set_function("GetFile",static_cast<const char*(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getFile));
mt.set_function("SetLoop",static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::setLoop));
mt.set_function("IsLoop",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isLoop));
mt.set_function("Start",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::start));
mt.set_function("Stop",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stop));
mt["Type"]=sol::var(std::ref(cocostudio::ComAudio::Type));
mt["COMPONENT_NAME"]=sol::var(std::ref(cocostudio::ComAudio::COMPONENT_NAME));
}
void RegisterLuaStudioComControllerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComController>("ccs","ComController",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject,cocostudio::InputDelegate>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComController::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ComController*(*)()>(&cocostudio::ComController::create));
mt.set_function("Init",static_cast<bool(cocostudio::ComController::*)()>(&cocostudio::ComController::init));
mt.set_function("OnEnter",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onEnter));
mt.set_function("OnExit",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onExit));
mt.set_function("OnAdd",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onAdd));
mt.set_function("OnRemove",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onRemove));
mt.set_function("Update",static_cast<void(cocostudio::ComController::*)(float)>(&cocostudio::ComController::update));
mt[sol::call_constructor]=sol::constructors<cocostudio::ComController()>();
mt["Type"]=sol::var(std::ref(cocostudio::ComController::Type));
mt["COMPONENT_NAME"]=sol::var(std::ref(cocostudio::ComController::COMPONENT_NAME));
}
void RegisterLuaStudioComRenderAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComRender>("ccs","ComRender",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComRender::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocostudio::ComRender*(*)(cocos2d::Node*,const char*)>(&cocostudio::ComRender::create),static_cast<cocostudio::ComRender*(*)()>(&cocostudio::ComRender::create)));
mt.set_function("OnEnter",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onEnter));
mt.set_function("OnExit",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onExit));
mt.set_function("OnAdd",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onAdd));
mt.set_function("OnRemove",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onRemove));
mt.set_function("Serialize",static_cast<bool(cocostudio::ComRender::*)(void*)>(&cocostudio::ComRender::serialize));
mt.set_function("GetNode",static_cast<cocos2d::Node*(cocostudio::ComRender::*)()>(&cocostudio::ComRender::getNode));
mt.set_function("SetNode",static_cast<void(cocostudio::ComRender::*)(cocos2d::Node*)>(&cocostudio::ComRender::setNode));
mt["Type"]=sol::var(std::ref(cocostudio::ComRender::Type));
mt["COMPONENT_NAME"]=sol::var(std::ref(cocostudio::ComRender::COMPONENT_NAME));
}
void RegisterLuaStudioGUIReaderAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::GUIReader>("ccs","GUIReader",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocostudio::GUIReader*(*)()>(&cocostudio::GUIReader::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocostudio::GUIReader::destroyInstance));
mt.set_function("WidgetFromJsonFile",static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromJsonFile));
mt.set_function("WidgetFromBinaryFile",static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromBinaryFile));
mt.set_function("GetVersionInteger",static_cast<int(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::getVersionInteger));
mt.set_function("StoreFileDesignSize",static_cast<void(cocostudio::GUIReader::*)(const char*,const cocos2d::Size&)>(&cocostudio::GUIReader::storeFileDesignSize));
mt.set_function("GetFileDesignSize",static_cast<cocos2d::Size(cocostudio::GUIReader::*)(const char*)const>(&cocostudio::GUIReader::getFileDesignSize));
mt.set_function("SetFilePath",static_cast<void(cocostudio::GUIReader::*)(const std::string&)>(&cocostudio::GUIReader::setFilePath));
mt.set_function("GetFilePath",static_cast<const std::string&(cocostudio::GUIReader::*)()const>(&cocostudio::GUIReader::getFilePath));
mt.set_function("RegisterTypeAndCallBack",sol::overload(static_cast<void(cocostudio::GUIReader::*)(const std::string&,cocos2d::ObjectFactory::InstanceFunc,cocos2d::Ref*,cocostudio::SEL_ParseEvent)>(&cocostudio::GUIReader::registerTypeAndCallBack),static_cast<void(cocostudio::GUIReader::*)(const std::string&,cocos2d::ObjectFactory::Instance,cocos2d::Ref*,cocostudio::SEL_ParseEvent)>(&cocostudio::GUIReader::registerTypeAndCallBack)));
mt["Instance"]=sol::property(&cocostudio::GUIReader::getInstance,[](std::nullptr_t){cocostudio::GUIReader::destroyInstance();});
}
void RegisterLuaStudioSceneReaderAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::SceneReader>("ccs","SceneReader",true);
mt.set_function("GetInstance",static_cast<cocostudio::SceneReader*(*)()>(&cocostudio::SceneReader::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocostudio::SceneReader::destroyInstance));
mt.set_function("SceneReaderVersion",static_cast<const char*(*)()>(&cocostudio::SceneReader::sceneReaderVersion));
mt.set_function("CreateNodeWithSceneFile",sol::overload([](cocostudio::SceneReader* obj,const std::string& arg0){return obj->createNodeWithSceneFile(arg0);},[](cocostudio::SceneReader* obj,const std::string& arg0,cocostudio::SceneReader::AttachComponentType arg1){return obj->createNodeWithSceneFile(arg0,arg1);}));
mt.set_function("SetTarget",static_cast<void(cocostudio::SceneReader::*)(const std::function<void (cocos2d::Ref *, void *)>&)>(&cocostudio::SceneReader::setTarget));
mt.set_function("GetNodeByTag",static_cast<cocos2d::Node*(cocostudio::SceneReader::*)(int)>(&cocostudio::SceneReader::getNodeByTag));
mt.set_function("GetAttachComponentType",static_cast<cocostudio::SceneReader::AttachComponentType(cocostudio::SceneReader::*)()>(&cocostudio::SceneReader::getAttachComponentType));
mt["Instance"]=sol::property(&cocostudio::SceneReader::getInstance,[](std::nullptr_t){cocostudio::SceneReader::destroyInstance();});
}
void RegisterLuaStudioActionTimelineCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineCache>("ccs","ActionTimelineCache",true);
mt.set_function("GetInstance",static_cast<cocostudio::timeline::ActionTimelineCache*(*)()>(&cocostudio::timeline::ActionTimelineCache::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocostudio::timeline::ActionTimelineCache::destroyInstance));
mt.set_function("Purge",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::purge));
mt.set_function("Init",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::init));
mt.set_function("RemoveAction",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::removeAction));
mt.set_function("CreateAction",static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createAction));
mt.set_function("CreateActionFromJson",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromJson));
mt.set_function("CreateActionFromContent",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromContent));
mt.set_function("LoadAnimationActionWithFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFile));
mt.set_function("LoadAnimationActionWithContent",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithContent));
mt.set_function("CreateActionWithFlatBuffersFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersFile));
mt.set_function("CreateActionWithDataBuffer",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(cocos2d::Data,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithDataBuffer));
mt.set_function("LoadAnimationActionWithFlatBuffersFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFlatBuffersFile));
mt.set_function("LoadAnimationWithDataBuffer",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const cocos2d::Data&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationWithDataBuffer));
mt.set_function("CreateActionWithFlatBuffersForSimulator",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersForSimulator));
mt[sol::call_constructor]=sol::constructors<cocostudio::timeline::ActionTimelineCache()>();
mt["Instance"]=sol::property(&cocostudio::timeline::ActionTimelineCache::getInstance,[](std::nullptr_t){cocostudio::timeline::ActionTimelineCache::destroyInstance();});
}
void RegisterLuaStudioFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::Frame>("ccs","Frame",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetFrameIndex",static_cast<void(cocostudio::timeline::Frame::*)(unsigned int)>(&cocostudio::timeline::Frame::setFrameIndex));
mt.set_function("GetFrameIndex",static_cast<unsigned int(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getFrameIndex));
mt.set_function("SetTimeline",static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::Frame::setTimeline));
mt.set_function("GetTimeline",static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTimeline));
mt.set_function("SetNode",static_cast<void(cocostudio::timeline::Frame::*)(cocos2d::Node*)>(&cocostudio::timeline::Frame::setNode));
mt.set_function("GetNode",static_cast<cocos2d::Node*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getNode));
mt.set_function("SetTween",static_cast<void(cocostudio::timeline::Frame::*)(bool)>(&cocostudio::timeline::Frame::setTween));
mt.set_function("IsTween",static_cast<bool(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::isTween));
mt.set_function("SetTweenType",static_cast<void(cocostudio::timeline::Frame::*)(const cocos2d::tweenfunc::TweenType&)>(&cocostudio::timeline::Frame::setTweenType));
mt.set_function("GetTweenType",static_cast<cocos2d::tweenfunc::TweenType(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTweenType));
mt.set_function("SetEasingParams",static_cast<void(cocostudio::timeline::Frame::*)(const std::vector<float, std::allocator<float> >&)>(&cocostudio::timeline::Frame::setEasingParams));
mt.set_function("GetEasingParams",static_cast<const std::vector<float, std::allocator<float> >&(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getEasingParams));
mt.set_function("IsEnterWhenPassed",static_cast<bool(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::isEnterWhenPassed));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Frame::onEnter));
mt.set_function("Apply",static_cast<void(cocostudio::timeline::Frame::*)(float)>(&cocostudio::timeline::Frame::apply));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::clone));
}
void RegisterLuaStudioVisibleFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::VisibleFrame>("ccs","VisibleFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::VisibleFrame*(*)()>(&cocostudio::timeline::VisibleFrame::create));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::VisibleFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::VisibleFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::VisibleFrame::*)()>(&cocostudio::timeline::VisibleFrame::clone));
mt.set_function("SetVisible",static_cast<void(cocostudio::timeline::VisibleFrame::*)(bool)>(&cocostudio::timeline::VisibleFrame::setVisible));
mt.set_function("IsVisible",static_cast<bool(cocostudio::timeline::VisibleFrame::*)()const>(&cocostudio::timeline::VisibleFrame::isVisible));
}
void RegisterLuaStudioTextureFrameAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::TextureFrame>("ccs","TextureFrame",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::timeline::TextureFrame*(*)()>(&cocostudio::timeline::TextureFrame::create));
mt.set_function("SetNode",static_cast<void(cocostudio::timeline::TextureFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::TextureFrame::setNode));
mt.set_function("OnEnter",static_cast<void(cocostudio::timeline::TextureFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::TextureFrame::onEnter));
mt.set_function("Clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::TextureFrame::*)()>(&cocostudio::timeline::TextureFrame::clone));
mt.set_function("SetTextureName",static_cast<void(cocostudio::timeline::TextureFrame::*)(std::string)>(&cocostudio::timeline::TextureFrame::setTextureName));
mt.set_function("GetTextureName",static_cast<std::string(cocostudio::timeline::TextureFrame::*)()const>(&cocostudio::timeline::TextureFrame::getTextureName));
}
