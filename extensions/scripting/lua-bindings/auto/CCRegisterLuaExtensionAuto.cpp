#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
static void RegisterLuaEventAssetsManagerEx(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::extension::EventAssetsManagerEx,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventAssetsManagerEx"
,"getEventCode",static_cast<cocos2d::extension::EventAssetsManagerEx::EventCode(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getEventCode)
,"getCURLECode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLECode)
,"getCURLMCode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLMCode)
,"getMessage",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getMessage)
,"getAssetId",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetId)
,"getAssetsManagerEx",static_cast<cocos2d::extension::AssetsManagerEx*(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetsManagerEx)
,"getPercent",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercent)
,"getPercentByFile",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercentByFile)
);}
static void RegisterLuaManifest(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::extension::Manifest,cocos2d::Ref,cocos2d::LuaObject>("cc","Manifest"
,"isVersionLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isVersionLoaded)
,"isLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isLoaded)
,"getPackageUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getPackageUrl)
,"getManifestFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getManifestFileUrl)
,"getVersionFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersionFileUrl)
,"getVersion",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersion)
,"getSearchPaths",static_cast<std::vector<std::string>(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getSearchPaths)
);}
static void RegisterLuaAssetsManagerEx(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::extension::AssetsManagerEx,cocos2d::Ref,cocos2d::LuaObject>("cc","AssetsManagerEx"
,"checkUpdate",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::checkUpdate)
,"update",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::update)
,"downloadFailedAssets",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::downloadFailedAssets)
,"getState",static_cast<cocos2d::extension::AssetsManagerEx::State(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getState)
,"getStoragePath",static_cast<const std::string&(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getStoragePath)
,"getLocalManifest",static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getLocalManifest)
,"getRemoteManifest",static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getRemoteManifest)
,"getMaxConcurrentTask",static_cast<const int(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getMaxConcurrentTask)
,"setMaxConcurrentTask",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const int)>(&cocos2d::extension::AssetsManagerEx::setMaxConcurrentTask)
,"setVersionCompareHandle",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<int (const std::string&, const std::string&)>&)>(&cocos2d::extension::AssetsManagerEx::setVersionCompareHandle)
,"setVerifyCallback",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<bool (const std::string&, cocos2d::extension::ManifestAsset)>&)>(&cocos2d::extension::AssetsManagerEx::setVerifyCallback)
,"new",sol::overload([](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1,uint32_t arg2){return obj->create(arg0,arg1,arg2);})
);}
static void RegisterLuaEventListenerAssetsManagerEx(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::extension::EventListenerAssetsManagerEx,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerAssetsManagerEx"
,"checkAvailable",static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::checkAvailable)
,"clone",static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::clone)
,"init",static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)(const cocos2d::extension::AssetsManagerEx*,const std::function<void (cocos2d::extension::EventAssetsManagerEx *)>&)>(&cocos2d::extension::EventListenerAssetsManagerEx::init)
);}
static void RegisterLuaParticleSystem3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSystem3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","ParticleSystem3D"
,"update",static_cast<void(cocos2d::ParticleSystem3D::*)(float)>(&cocos2d::ParticleSystem3D::update)
,"draw",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleSystem3D::draw)
,"setBlendFunc",static_cast<void(cocos2d::ParticleSystem3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem3D::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getBlendFunc)
,"startParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::startParticleSystem)
,"stopParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::stopParticleSystem)
,"pauseParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::pauseParticleSystem)
,"resumeParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::resumeParticleSystem)
,"setEmitter",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DEmitter*)>(&cocos2d::ParticleSystem3D::setEmitter)
,"setRender",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DRender*)>(&cocos2d::ParticleSystem3D::setRender)
,"getRender",static_cast<cocos2d::Particle3DRender*(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::getRender)
,"addAffector",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DAffector*)>(&cocos2d::ParticleSystem3D::addAffector)
,"removeAffector",static_cast<void(cocos2d::ParticleSystem3D::*)(int)>(&cocos2d::ParticleSystem3D::removeAffector)
,"removeAllAffector",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::removeAllAffector)
,"getParticleQuota",static_cast<unsigned int(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getParticleQuota)
,"setParticleQuota",static_cast<void(cocos2d::ParticleSystem3D::*)(unsigned int)>(&cocos2d::ParticleSystem3D::setParticleQuota)
,"getAliveParticleCount",static_cast<int(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getAliveParticleCount)
,"getState",static_cast<cocos2d::ParticleSystem3D::State(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getState)
,"isKeepLocal",static_cast<bool(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::isKeepLocal)
,"setKeepLocal",static_cast<void(cocos2d::ParticleSystem3D::*)(bool)>(&cocos2d::ParticleSystem3D::setKeepLocal)
,"setEnabled",static_cast<void(cocos2d::ParticleSystem3D::*)(bool)>(&cocos2d::ParticleSystem3D::setEnabled)
,"isEnabled",static_cast<bool(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::isEnabled)
);}
static void RegisterLuaPUParticleSystem3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PUParticleSystem3D,cocos2d::ParticleSystem3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","PUParticleSystem3D"
,"draw",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::PUParticleSystem3D::draw)
,"update",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::update)
,"forceUpdate",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::forceUpdate)
,"startParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::startParticleSystem)
,"stopParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::stopParticleSystem)
,"pauseParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::pauseParticleSystem)
,"resumeParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::resumeParticleSystem)
,"getAliveParticleCount",static_cast<int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getAliveParticleCount)
,"getParticleSystemScaleVelocity",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getParticleSystemScaleVelocity)
,"setParticleSystemScaleVelocity",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::setParticleSystemScaleVelocity)
,"rotationOffset",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::Vec3&)>(&cocos2d::PUParticleSystem3D::rotationOffset)
,"getTimeElapsedSinceStart",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getTimeElapsedSinceStart)
,"getDefaultWidth",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultWidth)
,"setDefaultWidth",static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultWidth)
,"getDefaultHeight",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultHeight)
,"setDefaultHeight",static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultHeight)
,"getDefaultDepth",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultDepth)
,"setDefaultDepth",static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultDepth)
,"getDerivedPosition",static_cast<cocos2d::Vec3(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedPosition)
,"getDerivedScale",static_cast<cocos2d::Vec3(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedScale)
,"getMaxVelocity",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getMaxVelocity)
,"setMaxVelocity",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::setMaxVelocity)
,"setMaterialName",static_cast<void(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::setMaterialName)
,"getMaterialName",static_cast<const std::string&(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getMaterialName)
,"forceEmission",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUEmitter*,unsigned int)>(&cocos2d::PUParticleSystem3D::forceEmission)
,"addEmitter",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUEmitter*)>(&cocos2d::PUParticleSystem3D::addEmitter)
,"removeAllEmitter",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllEmitter)
,"addListener",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUListener*)>(&cocos2d::PUParticleSystem3D::addListener)
,"removeListener",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUListener*)>(&cocos2d::PUParticleSystem3D::removeListener)
,"removeAllListener",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllListener)
,"addObserver",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUObserver*)>(&cocos2d::PUParticleSystem3D::addObserver)
,"removerAllObserver",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removerAllObserver)
,"addBehaviourTemplate",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUBehaviour*)>(&cocos2d::PUParticleSystem3D::addBehaviourTemplate)
,"removeAllBehaviourTemplate",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllBehaviourTemplate)
,"isMarkedForEmission",static_cast<bool(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::isMarkedForEmission)
,"setMarkedForEmission",static_cast<void(cocos2d::PUParticleSystem3D::*)(bool)>(&cocos2d::PUParticleSystem3D::setMarkedForEmission)
,"clearAllParticles",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::clearAllParticles)
,"getEmittedEmitterQuota",static_cast<unsigned int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedEmitterQuota)
,"setEmittedEmitterQuota",static_cast<void(cocos2d::PUParticleSystem3D::*)(unsigned int)>(&cocos2d::PUParticleSystem3D::setEmittedEmitterQuota)
,"getEmittedSystemQuota",static_cast<unsigned int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedSystemQuota)
,"setEmittedSystemQuota",static_cast<void(cocos2d::PUParticleSystem3D::*)(unsigned int)>(&cocos2d::PUParticleSystem3D::setEmittedSystemQuota)
,"getParentParticleSystem",static_cast<cocos2d::PUParticleSystem3D*(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getParentParticleSystem)
,"makeParticleLocal",static_cast<bool(cocos2d::PUParticleSystem3D::*)(cocos2d::PUParticle3D*)>(&cocos2d::PUParticleSystem3D::makeParticleLocal)
,"calulateRotationOffset",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::calulateRotationOffset)
,"clone",static_cast<cocos2d::PUParticleSystem3D*(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::clone)
,"copyAttributesTo",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUParticleSystem3D*)>(&cocos2d::PUParticleSystem3D::copyAttributesTo)
,"initSystem",static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::initSystem)
,"initWithFilePath",static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::initWithFilePath)
,"initWithFilePathAndMaterialPath",static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&,const std::string&)>(&cocos2d::PUParticleSystem3D::initWithFilePathAndMaterialPath)
,"new",sol::overload(static_cast<cocos2d::PUParticleSystem3D*(*)(const std::string&)>(&cocos2d::PUParticleSystem3D::create),static_cast<cocos2d::PUParticleSystem3D*(*)()>(&cocos2d::PUParticleSystem3D::create),static_cast<cocos2d::PUParticleSystem3D*(*)(const std::string&,const std::string&)>(&cocos2d::PUParticleSystem3D::create))
);}
void RegisterLuaExtensionAuto(cocos2d::Lua& lua) {
RegisterLuaEventAssetsManagerEx(lua);
RegisterLuaManifest(lua);
RegisterLuaAssetsManagerEx(lua);
RegisterLuaEventListenerAssetsManagerEx(lua);
RegisterLuaParticleSystem3D(lua);
RegisterLuaPUParticleSystem3D(lua);
}
