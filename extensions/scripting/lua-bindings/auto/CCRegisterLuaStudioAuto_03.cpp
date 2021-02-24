#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioComAudioAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComAudio,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject,cocos2d::PlayableProtocol>("ccs","ComAudio");
mt.set_function("init",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::init));
mt.set_function("onEnter",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onEnter));
mt.set_function("onExit",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onExit));
mt.set_function("onAdd",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onAdd));
mt.set_function("onRemove",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::onRemove));
mt.set_function("serialize",static_cast<bool(cocostudio::ComAudio::*)(void*)>(&cocostudio::ComAudio::serialize));
mt.set_function("endToLua",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::end));
mt.set_function("preloadBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadBackgroundMusic));
mt.set_function("playBackgroundMusic",sol::overload(static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playBackgroundMusic)));
mt.set_function("stopBackgroundMusic",sol::overload(static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::stopBackgroundMusic)));
mt.set_function("pauseBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseBackgroundMusic));
mt.set_function("resumeBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeBackgroundMusic));
mt.set_function("rewindBackgroundMusic",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::rewindBackgroundMusic));
mt.set_function("willPlayBackgroundMusic",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::willPlayBackgroundMusic));
mt.set_function("isBackgroundMusicPlaying",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isBackgroundMusicPlaying));
mt.set_function("getBackgroundMusicVolume",static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getBackgroundMusicVolume));
mt.set_function("setBackgroundMusicVolume",static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setBackgroundMusicVolume));
mt.set_function("getEffectsVolume",static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getEffectsVolume));
mt.set_function("setEffectsVolume",static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setEffectsVolume));
mt.set_function("playEffect",sol::overload(static_cast<unsigned int(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playEffect)));
mt.set_function("pauseEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::pauseEffect));
mt.set_function("pauseAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseAllEffects));
mt.set_function("resumeEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::resumeEffect));
mt.set_function("resumeAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeAllEffects));
mt.set_function("stopEffect",static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::stopEffect));
mt.set_function("stopAllEffects",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopAllEffects));
mt.set_function("preloadEffect",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadEffect));
mt.set_function("unloadEffect",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::unloadEffect));
mt.set_function("setFile",static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::setFile));
mt.set_function("getFile",static_cast<const char*(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getFile));
mt.set_function("setLoop",static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::setLoop));
mt.set_function("isLoop",static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isLoop));
mt.set_function("start",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::start));
mt.set_function("stop",static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stop));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComAudio::createInstance));
mt.set_function("new",static_cast<cocostudio::ComAudio*(*)()>(&cocostudio::ComAudio::create));
}
void RegisterLuaStudioComControllerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComController,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject,cocostudio::InputDelegate>("ccs","ComController");
mt.set_function("init",static_cast<bool(cocostudio::ComController::*)()>(&cocostudio::ComController::init));
mt.set_function("onEnter",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onEnter));
mt.set_function("onExit",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onExit));
mt.set_function("onAdd",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onAdd));
mt.set_function("onRemove",static_cast<void(cocostudio::ComController::*)()>(&cocostudio::ComController::onRemove));
mt.set_function("update",static_cast<void(cocostudio::ComController::*)(float)>(&cocostudio::ComController::update));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComController::createInstance));
mt.set_function("new",static_cast<cocostudio::ComController*(*)()>(&cocostudio::ComController::create));
}
void RegisterLuaStudioComRenderAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComRender,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("ccs","ComRender");
mt.set_function("onEnter",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onEnter));
mt.set_function("onExit",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onExit));
mt.set_function("onAdd",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onAdd));
mt.set_function("onRemove",static_cast<void(cocostudio::ComRender::*)()>(&cocostudio::ComRender::onRemove));
mt.set_function("serialize",static_cast<bool(cocostudio::ComRender::*)(void*)>(&cocostudio::ComRender::serialize));
mt.set_function("getNode",static_cast<cocos2d::Node*(cocostudio::ComRender::*)()>(&cocostudio::ComRender::getNode));
mt.set_function("setNode",static_cast<void(cocostudio::ComRender::*)(cocos2d::Node*)>(&cocostudio::ComRender::setNode));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComRender::createInstance));
mt.set_function("new",sol::overload(static_cast<cocostudio::ComRender*(*)(cocos2d::Node*,const char*)>(&cocostudio::ComRender::create),static_cast<cocostudio::ComRender*(*)()>(&cocostudio::ComRender::create)));
}
void RegisterLuaStudioGUIReaderAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::GUIReader,cocos2d::Ref,cocos2d::LuaObject>("ccs","GUIReader");
mt.set_function("widgetFromJsonFile",static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromJsonFile));
mt.set_function("widgetFromBinaryFile",static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromBinaryFile));
mt.set_function("getVersionInteger",static_cast<int(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::getVersionInteger));
mt.set_function("storeFileDesignSize",static_cast<void(cocostudio::GUIReader::*)(const char*,const cocos2d::Size&)>(&cocostudio::GUIReader::storeFileDesignSize));
mt.set_function("getFileDesignSize",static_cast<cocos2d::Size(cocostudio::GUIReader::*)(const char*)const>(&cocostudio::GUIReader::getFileDesignSize));
mt.set_function("setFilePath",static_cast<void(cocostudio::GUIReader::*)(const std::string&)>(&cocostudio::GUIReader::setFilePath));
mt.set_function("getFilePath",static_cast<const std::string&(cocostudio::GUIReader::*)()const>(&cocostudio::GUIReader::getFilePath));
mt.set_function("registerTypeAndCallBack",sol::overload(static_cast<void(cocostudio::GUIReader::*)(const std::string&,cocos2d::ObjectFactory::InstanceFunc,cocos2d::Ref*,cocostudio::SEL_ParseEvent)>(&cocostudio::GUIReader::registerTypeAndCallBack),static_cast<void(cocostudio::GUIReader::*)(const std::string&,cocos2d::ObjectFactory::Instance,cocos2d::Ref*,cocostudio::SEL_ParseEvent)>(&cocostudio::GUIReader::registerTypeAndCallBack)));
mt.set_function("getInstance",static_cast<cocostudio::GUIReader*(*)()>(&cocostudio::GUIReader::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocostudio::GUIReader::destroyInstance));
}
void RegisterLuaStudioSceneReaderAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::SceneReader>("ccs","SceneReader");
mt.set_function("createNodeWithSceneFile",sol::overload([](cocostudio::SceneReader* obj,const std::string& arg0){return obj->createNodeWithSceneFile(arg0);},[](cocostudio::SceneReader* obj,const std::string& arg0,cocostudio::SceneReader::AttachComponentType arg1){return obj->createNodeWithSceneFile(arg0,arg1);}));
mt.set_function("setTarget",static_cast<void(cocostudio::SceneReader::*)(const std::function<void (cocos2d::Ref *, void *)>&)>(&cocostudio::SceneReader::setTarget));
mt.set_function("getNodeByTag",static_cast<cocos2d::Node*(cocostudio::SceneReader::*)(int)>(&cocostudio::SceneReader::getNodeByTag));
mt.set_function("getAttachComponentType",static_cast<cocostudio::SceneReader::AttachComponentType(cocostudio::SceneReader::*)()>(&cocostudio::SceneReader::getAttachComponentType));
mt.set_function("getInstance",static_cast<cocostudio::SceneReader*(*)()>(&cocostudio::SceneReader::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocostudio::SceneReader::destroyInstance));
mt.set_function("sceneReaderVersion",static_cast<const char*(*)()>(&cocostudio::SceneReader::sceneReaderVersion));
}
void RegisterLuaStudioActionTimelineCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::ActionTimelineCache>("ccs","ActionTimelineCache");
mt.set_function("purge",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::purge));
mt.set_function("init",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::init));
mt.set_function("removeAction",static_cast<void(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::removeAction));
mt.set_function("createActionFromJson",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromJson));
mt.set_function("createActionFromContent",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromContent));
mt.set_function("loadAnimationActionWithFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFile));
mt.set_function("loadAnimationActionWithContent",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithContent));
mt.set_function("createActionWithFlatBuffersFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersFile));
mt.set_function("createActionWithDataBuffer",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(cocos2d::Data,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithDataBuffer));
mt.set_function("loadAnimationActionWithFlatBuffersFile",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFlatBuffersFile));
mt.set_function("loadAnimationWithDataBuffer",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const cocos2d::Data&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationWithDataBuffer));
mt.set_function("createActionWithFlatBuffersForSimulator",static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersForSimulator));
mt.set_function("getInstance",static_cast<cocostudio::timeline::ActionTimelineCache*(*)()>(&cocostudio::timeline::ActionTimelineCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocostudio::timeline::ActionTimelineCache::destroyInstance));
mt.set_function("createAction",static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createAction));
}
void RegisterLuaStudioFrameAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","Frame");
mt.set_function("setFrameIndex",static_cast<void(cocostudio::timeline::Frame::*)(unsigned int)>(&cocostudio::timeline::Frame::setFrameIndex));
mt.set_function("getFrameIndex",static_cast<unsigned int(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getFrameIndex));
mt.set_function("setTimeline",static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::Frame::setTimeline));
mt.set_function("getTimeline",static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTimeline));
mt.set_function("setNode",static_cast<void(cocostudio::timeline::Frame::*)(cocos2d::Node*)>(&cocostudio::timeline::Frame::setNode));
mt.set_function("getNode",static_cast<cocos2d::Node*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getNode));
mt.set_function("setTween",static_cast<void(cocostudio::timeline::Frame::*)(bool)>(&cocostudio::timeline::Frame::setTween));
mt.set_function("isTween",static_cast<bool(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::isTween));
mt.set_function("setTweenType",static_cast<void(cocostudio::timeline::Frame::*)(const cocos2d::tweenfunc::TweenType&)>(&cocostudio::timeline::Frame::setTweenType));
mt.set_function("getTweenType",static_cast<cocos2d::tweenfunc::TweenType(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTweenType));
mt.set_function("setEasingParams",static_cast<void(cocostudio::timeline::Frame::*)(const std::vector<float>&)>(&cocostudio::timeline::Frame::setEasingParams));
mt.set_function("getEasingParams",static_cast<const std::vector<float>&(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getEasingParams));
mt.set_function("isEnterWhenPassed",static_cast<bool(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::isEnterWhenPassed));
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Frame::onEnter));
mt.set_function("apply",static_cast<void(cocostudio::timeline::Frame::*)(float)>(&cocostudio::timeline::Frame::apply));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::clone));
}
void RegisterLuaStudioVisibleFrameAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::VisibleFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","VisibleFrame");
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::VisibleFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::VisibleFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::VisibleFrame::*)()>(&cocostudio::timeline::VisibleFrame::clone));
mt.set_function("setVisible",static_cast<void(cocostudio::timeline::VisibleFrame::*)(bool)>(&cocostudio::timeline::VisibleFrame::setVisible));
mt.set_function("isVisible",static_cast<bool(cocostudio::timeline::VisibleFrame::*)()const>(&cocostudio::timeline::VisibleFrame::isVisible));
mt.set_function("new",static_cast<cocostudio::timeline::VisibleFrame*(*)()>(&cocostudio::timeline::VisibleFrame::create));
}
void RegisterLuaStudioTextureFrameAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::TextureFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","TextureFrame");
mt.set_function("setNode",static_cast<void(cocostudio::timeline::TextureFrame::*)(cocos2d::Node*)>(&cocostudio::timeline::TextureFrame::setNode));
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::TextureFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::TextureFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::TextureFrame::*)()>(&cocostudio::timeline::TextureFrame::clone));
mt.set_function("setTextureName",static_cast<void(cocostudio::timeline::TextureFrame::*)(std::string)>(&cocostudio::timeline::TextureFrame::setTextureName));
mt.set_function("getTextureName",static_cast<std::string(cocostudio::timeline::TextureFrame::*)()const>(&cocostudio::timeline::TextureFrame::getTextureName));
mt.set_function("new",static_cast<cocostudio::timeline::TextureFrame*(*)()>(&cocostudio::timeline::TextureFrame::create));
}
void RegisterLuaStudioRotationFrameAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocostudio::timeline::RotationFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::LuaObject>("ccs","RotationFrame");
mt.set_function("onEnter",static_cast<void(cocostudio::timeline::RotationFrame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::RotationFrame::onEnter));
mt.set_function("clone",static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::RotationFrame::*)()>(&cocostudio::timeline::RotationFrame::clone));
mt.set_function("setRotation",static_cast<void(cocostudio::timeline::RotationFrame::*)(float)>(&cocostudio::timeline::RotationFrame::setRotation));
mt.set_function("getRotation",static_cast<float(cocostudio::timeline::RotationFrame::*)()const>(&cocostudio::timeline::RotationFrame::getRotation));
mt.set_function("new",static_cast<cocostudio::timeline::RotationFrame*(*)()>(&cocostudio::timeline::RotationFrame::create));
}
