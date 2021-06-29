#include "scripting/lua-bindings/auto/CCRegisterLuaAudioEngineAuto.hpp"
#include "audio/include/AudioEngine.h"
void RegisterLuaAudioEngineAudioProfileAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AudioProfile).name()] = sol::usertype_traits<cocos2d::AudioProfile*>::metatable();
auto dep=lua.new_usertype<cocos2d::AudioProfile>("deprecated.cocos2d::AudioProfile");
dep[sol::base_classes]=sol::bases<cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AudioProfile*>::metatable(),sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable());
lua["cc"]["AudioProfile"]=mt;
mt["__new__"]=[](){return new cocos2d::AudioProfile();};
mt["get"]["Name"]=[](cocos2d::AudioProfile* obj){return obj->name;};;
mt["get"]["MaxInstances"]=[](cocos2d::AudioProfile* obj){return obj->maxInstances;};;
mt["get"]["MinDelay"]=[](cocos2d::AudioProfile* obj){return obj->minDelay;};;
}
void RegisterLuaAudioEngineAudioEngineAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AudioEngine).name()] = sol::usertype_traits<cocos2d::AudioEngine*>::metatable();
auto dep=lua.new_usertype<cocos2d::AudioEngine>("deprecated.cocos2d::AudioEngine");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AudioEngine*>::metatable());
lua["cc"]["AudioEngine"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["LazyInit"]=static_cast<bool(*)()>(&cocos2d::AudioEngine::lazyInit);
mt["static"]["End"]=static_cast<void(*)()>(&cocos2d::AudioEngine::end);
mt["static"]["GetDefaultProfile"]=static_cast<cocos2d::AudioProfile*(*)()>(&cocos2d::AudioEngine::getDefaultProfile);
mt["static"]["get"]["DefaultProfile"]=mt["GetDefaultProfile"];
mt["static"]["Play2D"]=sol::overload([](const std::string& arg0,bool arg1,float arg2,const cocos2d::AudioProfile* arg3){return cocos2d::AudioEngine::play2d(arg0,arg1,arg2,arg3);},[](const std::string& arg0,bool arg1,float arg2){return cocos2d::AudioEngine::play2d(arg0,arg1,arg2);},[](const std::string& arg0,bool arg1){return cocos2d::AudioEngine::play2d(arg0,arg1);},[](const std::string& arg0){return cocos2d::AudioEngine::play2d(arg0);});
mt["static"]["SetLoop"]=static_cast<void(*)(int,bool)>(&cocos2d::AudioEngine::setLoop);
mt["static"]["IsLoop"]=static_cast<bool(*)(int)>(&cocos2d::AudioEngine::isLoop);
mt["static"]["SetVolume"]=static_cast<void(*)(int,float)>(&cocos2d::AudioEngine::setVolume);
mt["static"]["GetVolume"]=static_cast<float(*)(int)>(&cocos2d::AudioEngine::getVolume);
mt["static"]["Pause"]=static_cast<void(*)(int)>(&cocos2d::AudioEngine::pause);
mt["static"]["PauseAll"]=static_cast<void(*)()>(&cocos2d::AudioEngine::pauseAll);
mt["static"]["BlockAll"]=static_cast<void(*)()>(&cocos2d::AudioEngine::BlockAll);
mt["static"]["UnblockAll"]=static_cast<void(*)()>(&cocos2d::AudioEngine::UnblockAll);
mt["static"]["Resume"]=static_cast<void(*)(int)>(&cocos2d::AudioEngine::resume);
mt["static"]["ResumeAll"]=static_cast<void(*)()>(&cocos2d::AudioEngine::resumeAll);
mt["static"]["Stop"]=static_cast<void(*)(int)>(&cocos2d::AudioEngine::stop);
mt["static"]["StopAll"]=static_cast<void(*)()>(&cocos2d::AudioEngine::stopAll);
mt["static"]["SetCurrentTime"]=static_cast<bool(*)(int,float)>(&cocos2d::AudioEngine::setCurrentTime);
mt["static"]["GetCurrentTime"]=static_cast<float(*)(int)>(&cocos2d::AudioEngine::getCurrentTime);
mt["static"]["GetDuration"]=static_cast<float(*)(int)>(&cocos2d::AudioEngine::getDuration);
mt["static"]["GetState"]=static_cast<cocos2d::AudioEngine::AudioState(*)(int)>(&cocos2d::AudioEngine::getState);
mt["static"]["SetFinishCallback"]=static_cast<void(*)(int,const std::function<void (int, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>&)>(&cocos2d::AudioEngine::setFinishCallback);
mt["static"]["GetMaxAudioInstance"]=static_cast<int(*)()>(&cocos2d::AudioEngine::getMaxAudioInstance);
mt["static"]["get"]["MaxAudioInstance"]=mt["GetMaxAudioInstance"];
mt["static"]["SetMaxAudioInstance"]=static_cast<bool(*)(int)>(&cocos2d::AudioEngine::setMaxAudioInstance);
mt["static"]["set"]["MaxAudioInstance"]=mt["SetMaxAudioInstance"];
mt["static"]["Uncache"]=static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::uncache);
mt["static"]["UncacheAll"]=static_cast<void(*)()>(&cocos2d::AudioEngine::uncacheAll);
mt["static"]["GetProfile"]=sol::overload(static_cast<cocos2d::AudioProfile*(*)(const std::string&)>(&cocos2d::AudioEngine::getProfile),static_cast<cocos2d::AudioProfile*(*)(int)>(&cocos2d::AudioEngine::getProfile));
mt["static"]["Preload"]=sol::overload(static_cast<void(*)(const std::string&,std::function<void (bool)>)>(&cocos2d::AudioEngine::preload),static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::preload));
mt["static"]["GetPlayingAudioCount"]=static_cast<int(*)()>(&cocos2d::AudioEngine::getPlayingAudioCount);
mt["static"]["get"]["PlayingAudioCount"]=mt["GetPlayingAudioCount"];
mt["static"]["SetEnabled"]=static_cast<void(*)(bool)>(&cocos2d::AudioEngine::setEnabled);
mt["static"]["set"]["Enabled"]=mt["SetEnabled"];
mt["static"]["IsEnabled"]=static_cast<bool(*)()>(&cocos2d::AudioEngine::isEnabled);
mt["static"]["get"]["Enabled"]=mt["IsEnabled"];
mt["get"]["INVALID_AUDIO_ID"]=[](){return cocos2d::AudioEngine::INVALID_AUDIO_ID;};;
mt["get"]["TIME_UNKNOWN"]=[](){return cocos2d::AudioEngine::TIME_UNKNOWN;};;
}
