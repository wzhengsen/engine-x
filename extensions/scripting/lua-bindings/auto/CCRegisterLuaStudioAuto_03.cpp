#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
namespace cocos2d{
void RegisterLuaStudioComAttributeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ComAttribute).name()] = sol::usertype_traits<cocostudio::ComAttribute*>::metatable();
auto dep=lua.new_usertype<cocostudio::ComAttribute>("deprecated.cocostudio::ComAttribute");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ComAttribute*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable());
lua["ccs"]["ComAttribute"]=mt;
mt["__new__"]=static_cast<cocostudio::ComAttribute*(*)()>(&cocostudio::ComAttribute::create);
mt["SetInt"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,int)>(&cocostudio::ComAttribute::setInt);
mt["SetFloat"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,float)>(&cocostudio::ComAttribute::setFloat);
mt["SetBool"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,bool)>(&cocostudio::ComAttribute::setBool);
mt["SetString"]=static_cast<void(cocostudio::ComAttribute::*)(const std::string&,const std::string&)>(&cocostudio::ComAttribute::setString);
mt["GetInt"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0,int arg1){return obj->getInt(arg0,arg1);},[](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getInt(arg0);});
mt["GetFloat"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0,float arg1){return obj->getFloat(arg0,arg1);},[](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getFloat(arg0);});
mt["GetBool"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0,bool arg1){return obj->getBool(arg0,arg1);},[](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getBool(arg0);});
mt["GetString"]=sol::overload([](cocostudio::ComAttribute* obj,const std::string& arg0,const std::string& arg1){return obj->getString(arg0,arg1);},[](cocostudio::ComAttribute* obj,const std::string& arg0){return obj->getString(arg0);});
mt["Parse"]=static_cast<bool(cocostudio::ComAttribute::*)(const std::string&)>(&cocostudio::ComAttribute::parse);
mt["static"]["set"]["Type"]=[](const sol::object&,const cocos2d::ObjectFactory::TInfo& value){cocostudio::ComAttribute::Type = value;};
mt["static"]["get"]["Type"]=[]()->const cocos2d::ObjectFactory::TInfo&{return cocostudio::ComAttribute::Type;};
mt["static"]["get"]["COMPONENT_NAME"]=[]()->const std::string&{return cocostudio::ComAttribute::COMPONENT_NAME;};
}
void RegisterLuaStudioComAudioAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ComAudio).name()] = sol::usertype_traits<cocostudio::ComAudio*>::metatable();
auto dep=lua.new_usertype<cocostudio::ComAudio>("deprecated.cocostudio::ComAudio");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ComAudio*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable(),sol::usertype_traits<cocos2d::PlayableProtocol*>::metatable());
lua["ccs"]["ComAudio"]=mt;
mt["__new__"]=static_cast<cocostudio::ComAudio*(*)()>(&cocostudio::ComAudio::create);
mt["End"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::end);
mt["PreloadBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadBackgroundMusic);
mt["PlayBackgroundMusic"]=sol::overload(static_cast<void(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playBackgroundMusic));
mt["StopBackgroundMusic"]=sol::overload(static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::stopBackgroundMusic),static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopBackgroundMusic));
mt["PauseBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseBackgroundMusic);
mt["ResumeBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeBackgroundMusic);
mt["RewindBackgroundMusic"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::rewindBackgroundMusic);
mt["WillPlayBackgroundMusic"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::willPlayBackgroundMusic);
mt["IsBackgroundMusicPlaying"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isBackgroundMusicPlaying);
mt["get"]["BackgroundMusicPlaying"]=mt["IsBackgroundMusicPlaying"];
mt["GetBackgroundMusicVolume"]=static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getBackgroundMusicVolume);
mt["get"]["BackgroundMusicVolume"]=mt["GetBackgroundMusicVolume"];
mt["SetBackgroundMusicVolume"]=static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setBackgroundMusicVolume);
mt["set"]["BackgroundMusicVolume"]=mt["SetBackgroundMusicVolume"];
mt["GetEffectsVolume"]=static_cast<float(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getEffectsVolume);
mt["get"]["EffectsVolume"]=mt["GetEffectsVolume"];
mt["SetEffectsVolume"]=static_cast<void(cocostudio::ComAudio::*)(float)>(&cocostudio::ComAudio::setEffectsVolume);
mt["set"]["EffectsVolume"]=mt["SetEffectsVolume"];
mt["PlayEffect"]=sol::overload(static_cast<unsigned int(cocostudio::ComAudio::*)(const char*,bool)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::playEffect),static_cast<unsigned int(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::playEffect));
mt["PauseEffect"]=static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::pauseEffect);
mt["PauseAllEffects"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::pauseAllEffects);
mt["ResumeEffect"]=static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::resumeEffect);
mt["ResumeAllEffects"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::resumeAllEffects);
mt["StopEffect"]=static_cast<void(cocostudio::ComAudio::*)(unsigned int)>(&cocostudio::ComAudio::stopEffect);
mt["StopAllEffects"]=static_cast<void(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::stopAllEffects);
mt["PreloadEffect"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::preloadEffect);
mt["UnloadEffect"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::unloadEffect);
mt["SetFile"]=static_cast<void(cocostudio::ComAudio::*)(const char*)>(&cocostudio::ComAudio::setFile);
mt["set"]["File"]=mt["SetFile"];
mt["GetFile"]=static_cast<const char*(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::getFile);
mt["get"]["File"]=mt["GetFile"];
mt["SetLoop"]=static_cast<void(cocostudio::ComAudio::*)(bool)>(&cocostudio::ComAudio::setLoop);
mt["set"]["Loop"]=mt["SetLoop"];
mt["IsLoop"]=static_cast<bool(cocostudio::ComAudio::*)()>(&cocostudio::ComAudio::isLoop);
mt["get"]["Loop"]=mt["IsLoop"];
mt["static"]["set"]["Type"]=[](const sol::object&,const cocos2d::ObjectFactory::TInfo& value){cocostudio::ComAudio::Type = value;};
mt["static"]["get"]["Type"]=[]()->const cocos2d::ObjectFactory::TInfo&{return cocostudio::ComAudio::Type;};
mt["static"]["get"]["COMPONENT_NAME"]=[]()->const std::string&{return cocostudio::ComAudio::COMPONENT_NAME;};
}
void RegisterLuaStudioComControllerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ComController).name()] = sol::usertype_traits<cocostudio::ComController*>::metatable();
auto dep=lua.new_usertype<cocostudio::ComController>("deprecated.cocostudio::ComController");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject,cocostudio::InputDelegate>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ComController*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable(),sol::usertype_traits<cocostudio::InputDelegate*>::metatable());
lua["ccs"]["ComController"]=mt;
mt["__new__"]=static_cast<cocostudio::ComController*(*)()>(&cocostudio::ComController::create);
mt["static"]["set"]["Type"]=[](const sol::object&,const cocos2d::ObjectFactory::TInfo& value){cocostudio::ComController::Type = value;};
mt["static"]["get"]["Type"]=[]()->const cocos2d::ObjectFactory::TInfo&{return cocostudio::ComController::Type;};
mt["static"]["get"]["COMPONENT_NAME"]=[]()->const std::string&{return cocostudio::ComController::COMPONENT_NAME;};
}
void RegisterLuaStudioComRenderAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ComRender).name()] = sol::usertype_traits<cocostudio::ComRender*>::metatable();
auto dep=lua.new_usertype<cocostudio::ComRender>("deprecated.cocostudio::ComRender");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ComRender*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable());
lua["ccs"]["ComRender"]=mt;
mt["__new__"]=sol::overload(static_cast<cocostudio::ComRender*(*)(cocos2d::Node*,const char*)>(&cocostudio::ComRender::create),static_cast<cocostudio::ComRender*(*)()>(&cocostudio::ComRender::create));
mt["GetNode"]=static_cast<cocos2d::Node*(cocostudio::ComRender::*)()>(&cocostudio::ComRender::getNode);
mt["get"]["Node"]=mt["GetNode"];
mt["SetNode"]=static_cast<void(cocostudio::ComRender::*)(cocos2d::Node*)>(&cocostudio::ComRender::setNode);
mt["set"]["Node"]=mt["SetNode"];
mt["static"]["set"]["Type"]=[](const sol::object&,const cocos2d::ObjectFactory::TInfo& value){cocostudio::ComRender::Type = value;};
mt["static"]["get"]["Type"]=[]()->const cocos2d::ObjectFactory::TInfo&{return cocostudio::ComRender::Type;};
mt["static"]["get"]["COMPONENT_NAME"]=[]()->const std::string&{return cocostudio::ComRender::COMPONENT_NAME;};
}
void RegisterLuaStudioGUIReaderAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::GUIReader).name()] = sol::usertype_traits<cocostudio::GUIReader*>::metatable();
auto dep=lua.new_usertype<cocostudio::GUIReader>("deprecated.cocostudio::GUIReader");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::GUIReader*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["GUIReader"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocostudio::GUIReader*(*)()>(&cocostudio::GUIReader::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocostudio::GUIReader::destroyInstance);
mt["WidgetFromJsonFile"]=static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromJsonFile);
mt["WidgetFromBinaryFile"]=static_cast<cocos2d::ui::Widget*(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::widgetFromBinaryFile);
mt["GetVersionInteger"]=static_cast<int(cocostudio::GUIReader::*)(const char*)>(&cocostudio::GUIReader::getVersionInteger);
mt["StoreFileDesignSize"]=static_cast<void(cocostudio::GUIReader::*)(const char*,const cocos2d::Size&)>(&cocostudio::GUIReader::storeFileDesignSize);
mt["GetFileDesignSize"]=static_cast<cocos2d::Size(cocostudio::GUIReader::*)(const char*)const>(&cocostudio::GUIReader::getFileDesignSize);
mt["SetFilePath"]=static_cast<void(cocostudio::GUIReader::*)(const std::string&)>(&cocostudio::GUIReader::setFilePath);
mt["set"]["FilePath"]=mt["SetFilePath"];
mt["GetFilePath"]=static_cast<const std::string&(cocostudio::GUIReader::*)()const>(&cocostudio::GUIReader::getFilePath);
mt["get"]["FilePath"]=mt["GetFilePath"];
mt["static"]["get"]["Instance"]=&cocostudio::GUIReader::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocostudio::GUIReader::destroyInstance();};
}
void RegisterLuaStudioSceneReaderAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::SceneReader).name()] = sol::usertype_traits<cocostudio::SceneReader*>::metatable();
auto dep=lua.new_usertype<cocostudio::SceneReader>("deprecated.cocostudio::SceneReader");
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::SceneReader*>::metatable());
lua["ccs"]["SceneReader"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocostudio::SceneReader*(*)()>(&cocostudio::SceneReader::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocostudio::SceneReader::destroyInstance);
mt["static"]["SceneReaderVersion"]=static_cast<const char*(*)()>(&cocostudio::SceneReader::sceneReaderVersion);
mt["CreateNodeWithSceneFile"]=sol::overload([](cocostudio::SceneReader* obj,const std::string& arg0,cocostudio::SceneReader::AttachComponentType arg1){return obj->createNodeWithSceneFile(arg0,arg1);},[](cocostudio::SceneReader* obj,const std::string& arg0){return obj->createNodeWithSceneFile(arg0);});
mt["SetTarget"]=static_cast<void(cocostudio::SceneReader::*)(const std::function<void (cocos2d::Ref *, void *)>&)>(&cocostudio::SceneReader::setTarget);
mt["set"]["Target"]=mt["SetTarget"];
mt["GetNodeByTag"]=static_cast<cocos2d::Node*(cocostudio::SceneReader::*)(int)>(&cocostudio::SceneReader::getNodeByTag);
mt["GetAttachComponentType"]=static_cast<cocostudio::SceneReader::AttachComponentType(cocostudio::SceneReader::*)()>(&cocostudio::SceneReader::getAttachComponentType);
mt["get"]["AttachComponentType"]=mt["GetAttachComponentType"];
mt["static"]["get"]["Instance"]=&cocostudio::SceneReader::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocostudio::SceneReader::destroyInstance();};
}
void RegisterLuaStudioActionTimelineCacheAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ActionTimelineCache).name()] = sol::usertype_traits<cocostudio::timeline::ActionTimelineCache*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ActionTimelineCache>("deprecated.cocostudio::timeline::ActionTimelineCache");
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ActionTimelineCache*>::metatable());
lua["ccs"]["ActionTimelineCache"]=mt;
mt["static"]["GetInstance"]=static_cast<cocostudio::timeline::ActionTimelineCache*(*)()>(&cocostudio::timeline::ActionTimelineCache::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocostudio::timeline::ActionTimelineCache::destroyInstance);
mt["Purge"]=static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::purge);
mt["Init"]=static_cast<void(cocostudio::timeline::ActionTimelineCache::*)()>(&cocostudio::timeline::ActionTimelineCache::init);
mt["RemoveAction"]=static_cast<void(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::removeAction);
mt["static"]["CreateAction"]=static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createAction);
mt["CreateActionFromJson"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromJson);
mt["CreateActionFromContent"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionFromContent);
mt["LoadAnimationActionWithFile"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFile);
mt["LoadAnimationActionWithContent"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithContent);
mt["CreateActionWithFlatBuffersFile"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersFile);
mt["CreateActionWithDataBuffer"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(cocos2d::Data,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithDataBuffer);
mt["LoadAnimationActionWithFlatBuffersFile"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationActionWithFlatBuffersFile);
mt["LoadAnimationWithDataBuffer"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const cocos2d::Data&,const std::string&)>(&cocostudio::timeline::ActionTimelineCache::loadAnimationWithDataBuffer);
mt["CreateActionWithFlatBuffersForSimulator"]=static_cast<cocostudio::timeline::ActionTimeline*(cocostudio::timeline::ActionTimelineCache::*)(const std::string&)>(&cocostudio::timeline::ActionTimelineCache::createActionWithFlatBuffersForSimulator);
mt["static"]["get"]["Instance"]=&cocostudio::timeline::ActionTimelineCache::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocostudio::timeline::ActionTimelineCache::destroyInstance();};
}
void RegisterLuaStudioFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::Frame).name()] = sol::usertype_traits<cocostudio::timeline::Frame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::Frame>("deprecated.cocostudio::timeline::Frame");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::Frame*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["Frame"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["SetFrameIndex"]=static_cast<void(cocostudio::timeline::Frame::*)(unsigned int)>(&cocostudio::timeline::Frame::setFrameIndex);
mt["set"]["FrameIndex"]=mt["SetFrameIndex"];
mt["GetFrameIndex"]=static_cast<unsigned int(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getFrameIndex);
mt["get"]["FrameIndex"]=mt["GetFrameIndex"];
mt["SetTimeline"]=static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Timeline*)>(&cocostudio::timeline::Frame::setTimeline);
mt["set"]["Timeline"]=mt["SetTimeline"];
mt["GetTimeline"]=static_cast<cocostudio::timeline::Timeline*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTimeline);
mt["get"]["Timeline"]=mt["GetTimeline"];
mt["SetNode"]=static_cast<void(cocostudio::timeline::Frame::*)(cocos2d::Node*)>(&cocostudio::timeline::Frame::setNode);
mt["set"]["Node"]=mt["SetNode"];
mt["GetNode"]=static_cast<cocos2d::Node*(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getNode);
mt["get"]["Node"]=mt["GetNode"];
mt["SetTween"]=static_cast<void(cocostudio::timeline::Frame::*)(bool)>(&cocostudio::timeline::Frame::setTween);
mt["set"]["Tween"]=mt["SetTween"];
mt["IsTween"]=static_cast<bool(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::isTween);
mt["get"]["Tween"]=mt["IsTween"];
mt["SetTweenType"]=static_cast<void(cocostudio::timeline::Frame::*)(const cocos2d::tweenfunc::TweenType&)>(&cocostudio::timeline::Frame::setTweenType);
mt["set"]["TweenType"]=mt["SetTweenType"];
mt["GetTweenType"]=static_cast<cocos2d::tweenfunc::TweenType(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getTweenType);
mt["get"]["TweenType"]=mt["GetTweenType"];
mt["SetEasingParams"]=static_cast<void(cocostudio::timeline::Frame::*)(const std::vector<float, std::allocator<float> >&)>(&cocostudio::timeline::Frame::setEasingParams);
mt["set"]["EasingParams"]=mt["SetEasingParams"];
mt["GetEasingParams"]=static_cast<const std::vector<float, std::allocator<float> >&(cocostudio::timeline::Frame::*)()const>(&cocostudio::timeline::Frame::getEasingParams);
mt["get"]["EasingParams"]=mt["GetEasingParams"];
mt["IsEnterWhenPassed"]=static_cast<bool(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::isEnterWhenPassed);
mt["get"]["EnterWhenPassed"]=mt["IsEnterWhenPassed"];
mt["OnEnter"]=static_cast<void(cocostudio::timeline::Frame::*)(cocostudio::timeline::Frame*,int)>(&cocostudio::timeline::Frame::onEnter);
mt["Apply"]=static_cast<void(cocostudio::timeline::Frame::*)(float)>(&cocostudio::timeline::Frame::apply);
mt["Clone"]=static_cast<cocostudio::timeline::Frame*(cocostudio::timeline::Frame::*)()>(&cocostudio::timeline::Frame::clone);
}
void RegisterLuaStudioVisibleFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::VisibleFrame).name()] = sol::usertype_traits<cocostudio::timeline::VisibleFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::VisibleFrame>("deprecated.cocostudio::timeline::VisibleFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::VisibleFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["VisibleFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::VisibleFrame*(*)()>(&cocostudio::timeline::VisibleFrame::create);
mt["SetVisible"]=static_cast<void(cocostudio::timeline::VisibleFrame::*)(bool)>(&cocostudio::timeline::VisibleFrame::setVisible);
mt["set"]["Visible"]=mt["SetVisible"];
mt["IsVisible"]=static_cast<bool(cocostudio::timeline::VisibleFrame::*)()const>(&cocostudio::timeline::VisibleFrame::isVisible);
mt["get"]["Visible"]=mt["IsVisible"];
}
void RegisterLuaStudioTextureFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::TextureFrame).name()] = sol::usertype_traits<cocostudio::timeline::TextureFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::TextureFrame>("deprecated.cocostudio::timeline::TextureFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::TextureFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["TextureFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::TextureFrame*(*)()>(&cocostudio::timeline::TextureFrame::create);
mt["SetTextureName"]=static_cast<void(cocostudio::timeline::TextureFrame::*)(std::string)>(&cocostudio::timeline::TextureFrame::setTextureName);
mt["set"]["TextureName"]=mt["SetTextureName"];
mt["GetTextureName"]=static_cast<std::string(cocostudio::timeline::TextureFrame::*)()const>(&cocostudio::timeline::TextureFrame::getTextureName);
mt["get"]["TextureName"]=mt["GetTextureName"];
}
}
