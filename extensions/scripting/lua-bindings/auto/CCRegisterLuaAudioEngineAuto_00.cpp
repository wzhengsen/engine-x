#include "scripting/lua-bindings/auto/CCRegisterLuaAudioEngineAuto.hpp"
#include "audio/include/AudioEngine.h"
void RegisterLuaAudioEngineAudioProfileAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AudioProfile>("cc","AudioProfile");
mt["name"] = &cocos2d::AudioProfile::name;
mt["maxInstances"] = &cocos2d::AudioProfile::maxInstances;
mt["minDelay"] = &cocos2d::AudioProfile::minDelay;
}
void RegisterLuaAudioEngineAudioEngineAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AudioEngine>("cc","AudioEngine");
mt.set_function("lazyInit",static_cast<bool(*)()>(&cocos2d::AudioEngine::lazyInit));
mt.set_function("endToLua",static_cast<void(*)()>(&cocos2d::AudioEngine::end));
mt.set_function("getDefaultProfile",static_cast<cocos2d::AudioProfile*(*)()>(&cocos2d::AudioEngine::getDefaultProfile));
mt.set_function("play2d",sol::overload([](cocos2d::AudioEngine* obj,const std::string& arg0){return obj->play2d(arg0);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1){return obj->play2d(arg0,arg1);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1,float arg2){return obj->play2d(arg0,arg1,arg2);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1,float arg2,const cocos2d::AudioProfile* arg3){return obj->play2d(arg0,arg1,arg2,arg3);}));
mt.set_function("setLoop",static_cast<void(*)(int,bool)>(&cocos2d::AudioEngine::setLoop));
mt.set_function("isLoop",static_cast<bool(*)(int)>(&cocos2d::AudioEngine::isLoop));
mt.set_function("setVolume",static_cast<void(*)(int,float)>(&cocos2d::AudioEngine::setVolume));
mt.set_function("getVolume",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getVolume));
mt.set_function("pause",static_cast<void(*)(int)>(&cocos2d::AudioEngine::pause));
mt.set_function("pauseAll",static_cast<void(*)()>(&cocos2d::AudioEngine::pauseAll));
mt.set_function("BlockAll",static_cast<void(*)()>(&cocos2d::AudioEngine::BlockAll));
mt.set_function("UnblockAll",static_cast<void(*)()>(&cocos2d::AudioEngine::UnblockAll));
mt.set_function("resume",static_cast<void(*)(int)>(&cocos2d::AudioEngine::resume));
mt.set_function("resumeAll",static_cast<void(*)()>(&cocos2d::AudioEngine::resumeAll));
mt.set_function("stop",static_cast<void(*)(int)>(&cocos2d::AudioEngine::stop));
mt.set_function("stopAll",static_cast<void(*)()>(&cocos2d::AudioEngine::stopAll));
mt.set_function("setCurrentTime",static_cast<bool(*)(int,float)>(&cocos2d::AudioEngine::setCurrentTime));
mt.set_function("getCurrentTime",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getCurrentTime));
mt.set_function("getDuration",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getDuration));
mt.set_function("getState",static_cast<cocos2d::AudioEngine::AudioState(*)(int)>(&cocos2d::AudioEngine::getState));
mt.set_function("setFinishCallback",static_cast<void(*)(int,const std::function<void (int, const std::string&)>&)>(&cocos2d::AudioEngine::setFinishCallback));
mt.set_function("getMaxAudioInstance",static_cast<int(*)()>(&cocos2d::AudioEngine::getMaxAudioInstance));
mt.set_function("setMaxAudioInstance",static_cast<bool(*)(int)>(&cocos2d::AudioEngine::setMaxAudioInstance));
mt.set_function("uncache",static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::uncache));
mt.set_function("uncacheAll",static_cast<void(*)()>(&cocos2d::AudioEngine::uncacheAll));
mt.set_function("getProfile",sol::overload(static_cast<cocos2d::AudioProfile*(*)(const std::string&)>(&cocos2d::AudioEngine::getProfile),static_cast<cocos2d::AudioProfile*(*)(int)>(&cocos2d::AudioEngine::getProfile)));
mt.set_function("preload",sol::overload(static_cast<void(*)(const std::string&,std::function<void (bool)>)>(&cocos2d::AudioEngine::preload),static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::preload)));
mt.set_function("getPlayingAudioCount",static_cast<int(*)()>(&cocos2d::AudioEngine::getPlayingAudioCount));
mt.set_function("setEnabled",static_cast<void(*)(bool)>(&cocos2d::AudioEngine::setEnabled));
mt.set_function("isEnabled",static_cast<bool(*)()>(&cocos2d::AudioEngine::isEnabled));
}
