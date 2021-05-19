#include "scripting/lua-bindings/auto/CCRegisterLuaAudioEngineAuto.hpp"
#include "audio/include/AudioEngine.h"
void RegisterLuaAudioEngineAudioProfileAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AudioProfile>("cc","AudioProfile",false);
mt[sol::call_constructor]=sol::constructors<cocos2d::AudioProfile()>();
mt["Name"]=&cocos2d::AudioProfile::name;
mt["MaxInstances"]=&cocos2d::AudioProfile::maxInstances;
mt["MinDelay"]=&cocos2d::AudioProfile::minDelay;
}
void RegisterLuaAudioEngineAudioEngineAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AudioEngine>("cc","AudioEngine",true);
mt.set_function("LazyInit",static_cast<bool(*)()>(&cocos2d::AudioEngine::lazyInit));
mt.set_function("End",static_cast<void(*)()>(&cocos2d::AudioEngine::end));
mt.set_function("GetDefaultProfile",static_cast<cocos2d::AudioProfile*(*)()>(&cocos2d::AudioEngine::getDefaultProfile));
mt.set_function("Play2D",sol::overload([](cocos2d::AudioEngine* obj,const std::string& arg0){return obj->play2d(arg0);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1){return obj->play2d(arg0,arg1);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1,float arg2){return obj->play2d(arg0,arg1,arg2);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1,float arg2,const cocos2d::AudioProfile* arg3){return obj->play2d(arg0,arg1,arg2,arg3);}));
mt.set_function("SetLoop",static_cast<void(*)(int,bool)>(&cocos2d::AudioEngine::setLoop));
mt.set_function("IsLoop",static_cast<bool(*)(int)>(&cocos2d::AudioEngine::isLoop));
mt.set_function("SetVolume",static_cast<void(*)(int,float)>(&cocos2d::AudioEngine::setVolume));
mt.set_function("GetVolume",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getVolume));
mt.set_function("Pause",static_cast<void(*)(int)>(&cocos2d::AudioEngine::pause));
mt.set_function("PauseAll",static_cast<void(*)()>(&cocos2d::AudioEngine::pauseAll));
mt.set_function("BlockAll",static_cast<void(*)()>(&cocos2d::AudioEngine::BlockAll));
mt.set_function("UnblockAll",static_cast<void(*)()>(&cocos2d::AudioEngine::UnblockAll));
mt.set_function("Resume",static_cast<void(*)(int)>(&cocos2d::AudioEngine::resume));
mt.set_function("ResumeAll",static_cast<void(*)()>(&cocos2d::AudioEngine::resumeAll));
mt.set_function("Stop",static_cast<void(*)(int)>(&cocos2d::AudioEngine::stop));
mt.set_function("StopAll",static_cast<void(*)()>(&cocos2d::AudioEngine::stopAll));
mt.set_function("SetCurrentTime",static_cast<bool(*)(int,float)>(&cocos2d::AudioEngine::setCurrentTime));
mt.set_function("GetCurrentTime",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getCurrentTime));
mt.set_function("GetDuration",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getDuration));
mt.set_function("GetState",static_cast<cocos2d::AudioEngine::AudioState(*)(int)>(&cocos2d::AudioEngine::getState));
mt.set_function("SetFinishCallback",static_cast<void(*)(int,const std::function<void (int, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>&)>(&cocos2d::AudioEngine::setFinishCallback));
mt.set_function("GetMaxAudioInstance",static_cast<int(*)()>(&cocos2d::AudioEngine::getMaxAudioInstance));
mt.set_function("SetMaxAudioInstance",static_cast<bool(*)(int)>(&cocos2d::AudioEngine::setMaxAudioInstance));
mt.set_function("Uncache",static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::uncache));
mt.set_function("UncacheAll",static_cast<void(*)()>(&cocos2d::AudioEngine::uncacheAll));
mt.set_function("GetProfile",sol::overload(static_cast<cocos2d::AudioProfile*(*)(const std::string&)>(&cocos2d::AudioEngine::getProfile),static_cast<cocos2d::AudioProfile*(*)(int)>(&cocos2d::AudioEngine::getProfile)));
mt.set_function("Preload",sol::overload(static_cast<void(*)(const std::string&,std::function<void (bool)>)>(&cocos2d::AudioEngine::preload),static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::preload)));
mt.set_function("GetPlayingAudioCount",static_cast<int(*)()>(&cocos2d::AudioEngine::getPlayingAudioCount));
mt.set_function("SetEnabled",static_cast<void(*)(bool)>(&cocos2d::AudioEngine::setEnabled));
mt.set_function("IsEnabled",static_cast<bool(*)()>(&cocos2d::AudioEngine::isEnabled));
mt[sol::call_constructor]=sol::constructors<cocos2d::AudioEngine()>();
mt["INVALID_AUDIO_ID"]=sol::var(std::ref(cocos2d::AudioEngine::INVALID_AUDIO_ID));
mt["TIME_UNKNOWN"]=sol::var(std::ref(cocos2d::AudioEngine::TIME_UNKNOWN));
}
