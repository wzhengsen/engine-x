#include "scripting/lua-bindings/auto/CCRegisterLuaAudioEngineAuto.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include "audio/include/AudioEngine.h"
static void RegisterLuaAudioProfile(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AudioProfile>("cc","AudioProfile"
);}
static void RegisterLuaAudioEngine(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AudioEngine>("cc","AudioEngine"
,"lazyInit",static_cast<bool(*)()>(&cocos2d::AudioEngine::lazyInit)
,"endToLua",static_cast<void(*)()>(&cocos2d::AudioEngine::end)
,"getDefaultProfile",static_cast<cocos2d::AudioProfile*(*)()>(&cocos2d::AudioEngine::getDefaultProfile)
,"play2d",sol::overload([](cocos2d::AudioEngine* obj,const std::string& arg0){return obj->play2d(arg0);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1){return obj->play2d(arg0,arg1);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1,float arg2){return obj->play2d(arg0,arg1,arg2);},[](cocos2d::AudioEngine* obj,const std::string& arg0,bool arg1,float arg2,const cocos2d::AudioProfile* arg3){return obj->play2d(arg0,arg1,arg2,arg3);})
,"setLoop",static_cast<void(*)(int,bool)>(&cocos2d::AudioEngine::setLoop)
,"isLoop",static_cast<bool(*)(int)>(&cocos2d::AudioEngine::isLoop)
,"setVolume",static_cast<void(*)(int,float)>(&cocos2d::AudioEngine::setVolume)
,"getVolume",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getVolume)
,"pause",static_cast<void(*)(int)>(&cocos2d::AudioEngine::pause)
,"pauseAll",static_cast<void(*)()>(&cocos2d::AudioEngine::pauseAll)
,"resume",static_cast<void(*)(int)>(&cocos2d::AudioEngine::resume)
,"resumeAll",static_cast<void(*)()>(&cocos2d::AudioEngine::resumeAll)
,"stop",static_cast<void(*)(int)>(&cocos2d::AudioEngine::stop)
,"stopAll",static_cast<void(*)()>(&cocos2d::AudioEngine::stopAll)
,"setCurrentTime",static_cast<bool(*)(int,float)>(&cocos2d::AudioEngine::setCurrentTime)
,"getCurrentTime",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getCurrentTime)
,"getDuration",static_cast<float(*)(int)>(&cocos2d::AudioEngine::getDuration)
,"getState",static_cast<cocos2d::AudioEngine::AudioState(*)(int)>(&cocos2d::AudioEngine::getState)
,"getMaxAudioInstance",static_cast<int(*)()>(&cocos2d::AudioEngine::getMaxAudioInstance)
,"setMaxAudioInstance",static_cast<bool(*)(int)>(&cocos2d::AudioEngine::setMaxAudioInstance)
,"uncache",static_cast<void(*)(const std::string&)>(&cocos2d::AudioEngine::uncache)
,"uncacheAll",static_cast<void(*)()>(&cocos2d::AudioEngine::uncacheAll)
,"getProfile",sol::overload(static_cast<cocos2d::AudioProfile*(*)(const std::string&)>(&cocos2d::AudioEngine::getProfile),static_cast<cocos2d::AudioProfile*(*)(int)>(&cocos2d::AudioEngine::getProfile))
,"getPlayingAudioCount",static_cast<int(*)()>(&cocos2d::AudioEngine::getPlayingAudioCount)
,"setEnabled",static_cast<void(*)(bool)>(&cocos2d::AudioEngine::setEnabled)
,"isEnabled",static_cast<bool(*)()>(&cocos2d::AudioEngine::isEnabled)
);}
void RegisterLuaAudioEngineAuto(cocos2d::Lua& lua) {
RegisterLuaAudioProfile(lua);
RegisterLuaAudioEngine(lua);
}
#endif
