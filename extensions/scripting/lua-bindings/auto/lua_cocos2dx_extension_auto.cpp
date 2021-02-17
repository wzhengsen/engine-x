#include "scripting/lua-bindings/auto/lua_cocos2dx_extension_auto.hpp"
#include "cocos-ext.h"
void lua_register_cocos2dx_extension_EventAssetsManagerEx(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::extension::EventAssetsManagerEx,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventAssetsManagerEx");
mt["getEventCode"]=static_cast<cocos2d::extension::EventAssetsManagerEx::EventCode(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getEventCode);
mt["getCURLECode"]=static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLECode);
mt["getCURLMCode"]=static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLMCode);
mt["getMessage"]=static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getMessage);
mt["getAssetId"]=static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetId);
mt["getAssetsManagerEx"]=static_cast<cocos2d::extension::AssetsManagerEx*(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetsManagerEx);
mt["getPercent"]=static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercent);
mt["getPercentByFile"]=static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercentByFile);
}
void lua_register_cocos2dx_extension_Manifest(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::extension::Manifest,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Manifest");
mt["isVersionLoaded"]=static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isVersionLoaded);
mt["isLoaded"]=static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isLoaded);
mt["getPackageUrl"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getPackageUrl);
mt["getManifestFileUrl"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getManifestFileUrl);
mt["getVersionFileUrl"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersionFileUrl);
mt["getVersion"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersion);
mt["getSearchPaths"]=static_cast<std::vector<std::string>(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getSearchPaths);
}
void lua_register_cocos2dx_extension_AssetsManagerEx(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::extension::AssetsManagerEx,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"AssetsManagerEx");
mt["checkUpdate"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::checkUpdate);
mt["update"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::update);
mt["downloadFailedAssets"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::downloadFailedAssets);
mt["getState"]=static_cast<cocos2d::extension::AssetsManagerEx::State(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getState);
mt["getStoragePath"]=static_cast<const std::string&(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getStoragePath);
mt["getLocalManifest"]=static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getLocalManifest);
mt["getRemoteManifest"]=static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getRemoteManifest);
mt["getMaxConcurrentTask"]=static_cast<const int(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getMaxConcurrentTask);
mt["setMaxConcurrentTask"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const int)>(&cocos2d::extension::AssetsManagerEx::setMaxConcurrentTask);
mt["setVersionCompareHandle"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<int (const std::string&, const std::string&)>&)>(&cocos2d::extension::AssetsManagerEx::setVersionCompareHandle);
mt["setVerifyCallback"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<bool (const std::string&, cocos2d::extension::ManifestAsset)>&)>(&cocos2d::extension::AssetsManagerEx::setVerifyCallback);
mt["create"]=sol::overload([](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1,uint32_t arg2){return obj->create(arg0,arg1,arg2);});
}
void lua_register_cocos2dx_extension_EventListenerAssetsManagerEx(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::extension::EventListenerAssetsManagerEx,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerAssetsManagerEx");
mt["checkAvailable"]=static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::checkAvailable);
mt["clone"]=static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::clone);
mt["init"]=static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)(const cocos2d::extension::AssetsManagerEx*,const std::function<void (cocos2d::extension::EventAssetsManagerEx *)>&)>(&cocos2d::extension::EventListenerAssetsManagerEx::init);
}
void lua_register_cocos2dx_extension_ParticleSystem3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSystem3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSystem3D");
mt["update"]=static_cast<void(cocos2d::ParticleSystem3D::*)(float)>(&cocos2d::ParticleSystem3D::update);
mt["draw"]=static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleSystem3D::draw);
mt["setBlendFunc"]=static_cast<void(cocos2d::ParticleSystem3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem3D::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getBlendFunc);
mt["startParticleSystem"]=static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::startParticleSystem);
mt["stopParticleSystem"]=static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::stopParticleSystem);
mt["pauseParticleSystem"]=static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::pauseParticleSystem);
mt["resumeParticleSystem"]=static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::resumeParticleSystem);
mt["setEmitter"]=static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DEmitter*)>(&cocos2d::ParticleSystem3D::setEmitter);
mt["setRender"]=static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DRender*)>(&cocos2d::ParticleSystem3D::setRender);
mt["getRender"]=static_cast<cocos2d::Particle3DRender*(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::getRender);
mt["addAffector"]=static_cast<void(cocos2d::ParticleSystem3D::*)(cocos2d::Particle3DAffector*)>(&cocos2d::ParticleSystem3D::addAffector);
mt["removeAffector"]=static_cast<void(cocos2d::ParticleSystem3D::*)(int)>(&cocos2d::ParticleSystem3D::removeAffector);
mt["removeAllAffector"]=static_cast<void(cocos2d::ParticleSystem3D::*)()>(&cocos2d::ParticleSystem3D::removeAllAffector);
mt["getParticleQuota"]=static_cast<unsigned int(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getParticleQuota);
mt["setParticleQuota"]=static_cast<void(cocos2d::ParticleSystem3D::*)(unsigned int)>(&cocos2d::ParticleSystem3D::setParticleQuota);
mt["getAliveParticleCount"]=static_cast<int(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getAliveParticleCount);
mt["getState"]=static_cast<cocos2d::ParticleSystem3D::State(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::getState);
mt["isKeepLocal"]=static_cast<bool(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::isKeepLocal);
mt["setKeepLocal"]=static_cast<void(cocos2d::ParticleSystem3D::*)(bool)>(&cocos2d::ParticleSystem3D::setKeepLocal);
mt["setEnabled"]=static_cast<void(cocos2d::ParticleSystem3D::*)(bool)>(&cocos2d::ParticleSystem3D::setEnabled);
mt["isEnabled"]=static_cast<bool(cocos2d::ParticleSystem3D::*)()const>(&cocos2d::ParticleSystem3D::isEnabled);
}
void lua_register_cocos2dx_extension_PUParticleSystem3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::PUParticleSystem3D,cocos2d::ParticleSystem3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"PUParticleSystem3D");
mt["draw"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::PUParticleSystem3D::draw);
mt["update"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::update);
mt["forceUpdate"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::forceUpdate);
mt["startParticleSystem"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::startParticleSystem);
mt["stopParticleSystem"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::stopParticleSystem);
mt["pauseParticleSystem"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::pauseParticleSystem);
mt["resumeParticleSystem"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::resumeParticleSystem);
mt["getAliveParticleCount"]=static_cast<int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getAliveParticleCount);
mt["getParticleSystemScaleVelocity"]=static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getParticleSystemScaleVelocity);
mt["setParticleSystemScaleVelocity"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::setParticleSystemScaleVelocity);
mt["rotationOffset"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::Vec3&)>(&cocos2d::PUParticleSystem3D::rotationOffset);
mt["getTimeElapsedSinceStart"]=static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getTimeElapsedSinceStart);
mt["getDefaultWidth"]=static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultWidth);
mt["setDefaultWidth"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultWidth);
mt["getDefaultHeight"]=static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultHeight);
mt["setDefaultHeight"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultHeight);
mt["getDefaultDepth"]=static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getDefaultDepth);
mt["setDefaultDepth"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(const float)>(&cocos2d::PUParticleSystem3D::setDefaultDepth);
mt["getDerivedPosition"]=static_cast<cocos2d::Vec3(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedPosition);
mt["getDerivedScale"]=static_cast<cocos2d::Vec3(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::getDerivedScale);
mt["getMaxVelocity"]=static_cast<float(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getMaxVelocity);
mt["setMaxVelocity"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(float)>(&cocos2d::PUParticleSystem3D::setMaxVelocity);
mt["setMaterialName"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::setMaterialName);
mt["getMaterialName"]=static_cast<const std::string&(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getMaterialName);
mt["forceEmission"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUEmitter*,unsigned int)>(&cocos2d::PUParticleSystem3D::forceEmission);
mt["addEmitter"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUEmitter*)>(&cocos2d::PUParticleSystem3D::addEmitter);
mt["removeAllEmitter"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllEmitter);
mt["addListener"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUListener*)>(&cocos2d::PUParticleSystem3D::addListener);
mt["removeListener"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUListener*)>(&cocos2d::PUParticleSystem3D::removeListener);
mt["removeAllListener"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllListener);
mt["addObserver"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUObserver*)>(&cocos2d::PUParticleSystem3D::addObserver);
mt["removerAllObserver"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removerAllObserver);
mt["addBehaviourTemplate"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUBehaviour*)>(&cocos2d::PUParticleSystem3D::addBehaviourTemplate);
mt["removeAllBehaviourTemplate"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::removeAllBehaviourTemplate);
mt["isMarkedForEmission"]=static_cast<bool(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::isMarkedForEmission);
mt["setMarkedForEmission"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(bool)>(&cocos2d::PUParticleSystem3D::setMarkedForEmission);
mt["clearAllParticles"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::clearAllParticles);
mt["getEmittedEmitterQuota"]=static_cast<unsigned int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedEmitterQuota);
mt["setEmittedEmitterQuota"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(unsigned int)>(&cocos2d::PUParticleSystem3D::setEmittedEmitterQuota);
mt["getEmittedSystemQuota"]=static_cast<unsigned int(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getEmittedSystemQuota);
mt["setEmittedSystemQuota"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(unsigned int)>(&cocos2d::PUParticleSystem3D::setEmittedSystemQuota);
mt["getParentParticleSystem"]=static_cast<cocos2d::PUParticleSystem3D*(cocos2d::PUParticleSystem3D::*)()const>(&cocos2d::PUParticleSystem3D::getParentParticleSystem);
mt["makeParticleLocal"]=static_cast<bool(cocos2d::PUParticleSystem3D::*)(cocos2d::PUParticle3D*)>(&cocos2d::PUParticleSystem3D::makeParticleLocal);
mt["calulateRotationOffset"]=static_cast<void(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::calulateRotationOffset);
mt["clone"]=static_cast<cocos2d::PUParticleSystem3D*(cocos2d::PUParticleSystem3D::*)()>(&cocos2d::PUParticleSystem3D::clone);
mt["copyAttributesTo"]=static_cast<void(cocos2d::PUParticleSystem3D::*)(cocos2d::PUParticleSystem3D*)>(&cocos2d::PUParticleSystem3D::copyAttributesTo);
mt["initSystem"]=static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::initSystem);
mt["initWithFilePath"]=static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&)>(&cocos2d::PUParticleSystem3D::initWithFilePath);
mt["initWithFilePathAndMaterialPath"]=static_cast<bool(cocos2d::PUParticleSystem3D::*)(const std::string&,const std::string&)>(&cocos2d::PUParticleSystem3D::initWithFilePathAndMaterialPath);
mt["create"]=static_cast<cocos2d::PUParticleSystem3D*(*)(const std::string&)>(&cocos2d::PUParticleSystem3D::create),static_cast<cocos2d::PUParticleSystem3D*(*)()>(&cocos2d::PUParticleSystem3D::create),static_cast<cocos2d::PUParticleSystem3D*(*)(const std::string&,const std::string&)>(&cocos2d::PUParticleSystem3D::create);
}
void register_all_cocos2dx_extension(cocos2d::Lua& lua) {
	lua_register_cocos2dx_extension_EventAssetsManagerEx(lua);
	lua_register_cocos2dx_extension_Manifest(lua);
	lua_register_cocos2dx_extension_AssetsManagerEx(lua);
	lua_register_cocos2dx_extension_EventListenerAssetsManagerEx(lua);
	lua_register_cocos2dx_extension_ParticleSystem3D(lua);
	lua_register_cocos2dx_extension_PUParticleSystem3D(lua);
}
