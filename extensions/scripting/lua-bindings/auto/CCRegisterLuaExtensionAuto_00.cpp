#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
#include "Particle3D/PU/CCPUEmitter.h"
#include "Particle3D/PU/CCPUAffector.h"
#include "Particle3D/PU/CCPUObserver.h"
#include "Particle3D/CCParticle3DAffector.h"
void RegisterLuaExtensionEventAssetsManagerExAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::EventAssetsManagerEx,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventAssetsManagerEx");
mt.set_function("getEventCode",static_cast<cocos2d::extension::EventAssetsManagerEx::EventCode(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getEventCode));
mt.set_function("getCURLECode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLECode));
mt.set_function("getCURLMCode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLMCode));
mt.set_function("getMessage",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getMessage));
mt.set_function("getAssetId",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetId));
mt.set_function("getAssetsManagerEx",static_cast<cocos2d::extension::AssetsManagerEx*(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetsManagerEx));
mt.set_function("getPercent",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercent));
mt.set_function("getPercentByFile",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercentByFile));
}
void RegisterLuaExtensionManifestAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::Manifest,cocos2d::Ref,cocos2d::LuaObject>("cc","Manifest");
mt.set_function("isVersionLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isVersionLoaded));
mt.set_function("isLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isLoaded));
mt.set_function("getPackageUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getPackageUrl));
mt.set_function("getManifestFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getManifestFileUrl));
mt.set_function("getVersionFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersionFileUrl));
mt.set_function("getVersion",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersion));
mt.set_function("getSearchPaths",static_cast<std::vector<std::string>(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getSearchPaths));
}
void RegisterLuaExtensionAssetsManagerExAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::AssetsManagerEx,cocos2d::Ref,cocos2d::LuaObject>("cc","AssetsManagerEx");
mt.set_function("checkUpdate",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::checkUpdate));
mt.set_function("update",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::update));
mt.set_function("downloadFailedAssets",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::downloadFailedAssets));
mt.set_function("getState",static_cast<cocos2d::extension::AssetsManagerEx::State(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getState));
mt.set_function("getStoragePath",static_cast<const std::string&(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getStoragePath));
mt.set_function("getLocalManifest",static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getLocalManifest));
mt.set_function("getRemoteManifest",static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getRemoteManifest));
mt.set_function("getMaxConcurrentTask",static_cast<const int(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getMaxConcurrentTask));
mt.set_function("setMaxConcurrentTask",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const int)>(&cocos2d::extension::AssetsManagerEx::setMaxConcurrentTask));
mt.set_function("setVersionCompareHandle",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<int (const std::string&, const std::string&)>&)>(&cocos2d::extension::AssetsManagerEx::setVersionCompareHandle));
mt.set_function("setVerifyCallback",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<bool (const std::string&, cocos2d::extension::ManifestAsset)>&)>(&cocos2d::extension::AssetsManagerEx::setVerifyCallback));
mt.set_function("new",sol::overload([](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1,uint32_t arg2){return obj->create(arg0,arg1,arg2);}));
}
void RegisterLuaExtensionEventListenerAssetsManagerExAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::EventListenerAssetsManagerEx,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerAssetsManagerEx");
mt.set_function("checkAvailable",static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::clone));
mt.set_function("new",static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(*)(cocos2d::extension::AssetsManagerEx*,const std::function<void (cocos2d::extension::EventAssetsManagerEx *)>&)>(&cocos2d::extension::EventListenerAssetsManagerEx::create));
}
void RegisterLuaExtensionParticleSystem3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParticleSystem3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","ParticleSystem3D");
mt.set_function("update",static_cast<void(cocos2d::ParticleSystem3D::*)(float)>(&cocos2d::ParticleSystem3D::update));
mt.set_function("draw",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleSystem3D::draw));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::ParticleSystem3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem3D::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getBlendFunc));
mt.set_function("startParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::startParticleSystem));
mt.set_function("stopParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::stopParticleSystem));
mt.set_function("pauseParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::pauseParticleSystem));
mt.set_function("resumeParticleSystem",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::resumeParticleSystem));
mt.set_function("setEmitter",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DEmitter*)>(&cocos2d::ParticleSystem3D::setEmitter));
mt.set_function("setRender",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DRender*)>(&cocos2d::ParticleSystem3D::setRender));
mt.set_function("getRender",static_cast<cocos2d::Particle3DRender*(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::getRender));
mt.set_function("addAffector",static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DAffector*)>(&cocos2d::ParticleSystem3D::addAffector));
mt.set_function("removeAffector",static_cast<void(cocos2d::ParticleSystem3D::*)(int)>(&cocos2d::ParticleSystem3D::removeAffector));
mt.set_function("removeAllAffector",static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::removeAllAffector));
mt.set_function("getParticleQuota",static_cast<unsigned int(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getParticleQuota));
mt.set_function("setParticleQuota",static_cast<void(cocos2d::ParticleSystem3D::*)(unsigned int)>(&cocos2d::ParticleSystem3D::setParticleQuota));
mt.set_function("getAffector",static_cast<cocos2d::Particle3DAffector*(cocos2d::ParticleSystem3D::*)(int)>(&cocos2d::ParticleSystem3D::getAffector));
mt.set_function("getParticlePool",static_cast<const cocos2d::ParticlePool&(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::getParticlePool));
mt.set_function("getAliveParticleCount",static_cast<int(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getAliveParticleCount));
mt.set_function("getState",static_cast<cocos2d::ParticleSystem3D::State(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getState));
mt.set_function("isKeepLocal",static_cast<bool(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::isKeepLocal));
mt.set_function("setKeepLocal",static_cast<void(cocos2d::ParticleSystem3D::*)(bool)>(&cocos2d::ParticleSystem3D::setKeepLocal));
mt.set_function("setEnabled",static_cast<void(cocos2d::ParticleSystem3D::*)(bool)>(&cocos2d::ParticleSystem3D::setEnabled));
mt.set_function("isEnabled",static_cast<bool(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::isEnabled));
}
void RegisterLuaExtensionPUParticleSystem3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PUParticleSystem3D,cocos2d::ParticleSystem3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","PUParticleSystem3D");
mt.set_function("draw",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::PUParticleSystem3D::draw));
mt.set_function("update",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::update));
mt.set_function("forceUpdate",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::forceUpdate));
mt.set_function("startParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::startParticleSystem));
mt.set_function("stopParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::stopParticleSystem));
mt.set_function("pauseParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::pauseParticleSystem));
mt.set_function("resumeParticleSystem",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::resumeParticleSystem));
mt.set_function("getAliveParticleCount",static_cast<int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getAliveParticleCount));
mt.set_function("getParticleSystemScaleVelocity",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getParticleSystemScaleVelocity));
mt.set_function("setParticleSystemScaleVelocity",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::setParticleSystemScaleVelocity));
mt.set_function("rotationOffset",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::Vec3&)>(&cocos2d::PUParticleSystem3D::rotationOffset));
mt.set_function("getTimeElapsedSinceStart",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getTimeElapsedSinceStart));
mt.set_function("getDefaultWidth",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultWidth));
mt.set_function("setDefaultWidth",static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultWidth));
mt.set_function("getDefaultHeight",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultHeight));
mt.set_function("setDefaultHeight",static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultHeight));
mt.set_function("getDefaultDepth",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultDepth));
mt.set_function("setDefaultDepth",static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultDepth));
mt.set_function("getDerivedPosition",static_cast<cocos2d::Vec3(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedPosition));
mt.set_function("getDerivedOrientation",static_cast<cocos2d::Quaternion(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedOrientation));
mt.set_function("getDerivedScale",static_cast<cocos2d::Vec3(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedScale));
mt.set_function("getMaxVelocity",static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getMaxVelocity));
mt.set_function("setMaxVelocity",static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::setMaxVelocity));
mt.set_function("setMaterialName",static_cast<void(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::setMaterialName));
mt.set_function("getMaterialName",static_cast<const std::string&(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getMaterialName));
mt.set_function("forceEmission",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUEmitter*,unsigned int)>(&cocos2d::PUParticleSystem3D::forceEmission));
mt.set_function("addEmitter",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUEmitter*)>(&cocos2d::PUParticleSystem3D::addEmitter));
mt.set_function("getAffector",static_cast<cocos2d::PUAffector*(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::getAffector));
mt.set_function("getEmitter",static_cast<cocos2d::PUEmitter*(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::getEmitter));
mt.set_function("removeAllEmitter",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllEmitter));
mt.set_function("addListener",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUListener*)>(&cocos2d::PUParticleSystem3D::addListener));
mt.set_function("removeListener",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUListener*)>(&cocos2d::PUParticleSystem3D::removeListener));
mt.set_function("removeAllListener",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllListener));
mt.set_function("addObserver",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUObserver*)>(&cocos2d::PUParticleSystem3D::addObserver));
mt.set_function("getObserver",static_cast<cocos2d::PUObserver*(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::getObserver));
mt.set_function("removerAllObserver",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removerAllObserver));
mt.set_function("addBehaviourTemplate",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUBehaviour*)>(&cocos2d::PUParticleSystem3D::addBehaviourTemplate));
mt.set_function("removeAllBehaviourTemplate",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllBehaviourTemplate));
mt.set_function("isMarkedForEmission",static_cast<bool(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::isMarkedForEmission));
mt.set_function("setMarkedForEmission",static_cast<void(cocos2d::PUParticleSystem3D::*)(bool)>(&cocos2d::PUParticleSystem3D::setMarkedForEmission));
mt.set_function("clearAllParticles",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::clearAllParticles));
mt.set_function("getEmittedEmitterQuota",static_cast<unsigned int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedEmitterQuota));
mt.set_function("setEmittedEmitterQuota",static_cast<void(cocos2d::PUParticleSystem3D::*)(unsigned int)>(&cocos2d::PUParticleSystem3D::setEmittedEmitterQuota));
mt.set_function("getEmittedSystemQuota",static_cast<unsigned int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedSystemQuota));
mt.set_function("setEmittedSystemQuota",static_cast<void(cocos2d::PUParticleSystem3D::*)(unsigned int)>(&cocos2d::PUParticleSystem3D::setEmittedSystemQuota));
mt.set_function("getParentParticleSystem",static_cast<cocos2d::PUParticleSystem3D*(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getParentParticleSystem));
mt.set_function("getEmittedEmitterParticlePool",static_cast<const cocos2d::PUParticleSystem3D::ParticlePoolMap&(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedEmitterParticlePool));
mt.set_function("getEmittedSystemParticlePool",static_cast<const cocos2d::PUParticleSystem3D::ParticlePoolMap&(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedSystemParticlePool));
mt.set_function("makeParticleLocal",static_cast<bool(cocos2d::PUParticleSystem3D::*)(cocos2d::PUParticle3D*)>(&cocos2d::PUParticleSystem3D::makeParticleLocal));
mt.set_function("calulateRotationOffset",static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::calulateRotationOffset));
mt.set_function("clone",static_cast<cocos2d::PUParticleSystem3D*(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::clone));
mt.set_function("copyAttributesTo",static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUParticleSystem3D*)>(&cocos2d::PUParticleSystem3D::copyAttributesTo));
mt.set_function("initSystem",static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::initSystem));
mt.set_function("new",sol::overload(static_cast<cocos2d::PUParticleSystem3D*(*)(const std::string&)>(&cocos2d::PUParticleSystem3D::create),static_cast<cocos2d::PUParticleSystem3D*(*)()>(&cocos2d::PUParticleSystem3D::create),static_cast<cocos2d::PUParticleSystem3D*(*)(const std::string&,const std::string&)>(&cocos2d::PUParticleSystem3D::create)));
}
