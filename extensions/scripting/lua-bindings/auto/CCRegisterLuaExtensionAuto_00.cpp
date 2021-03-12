#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
#include "Particle3D/PU/CCPUEmitter.h"
#include "Particle3D/PU/CCPUAffector.h"
#include "Particle3D/PU/CCPUObserver.h"
#include "Particle3D/CCParticle3DAffector.h"
void RegisterLuaExtensionEventAssetsManagerExEventCodeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventAssetsManagerEx"];
pTable.new_enum("EventCode"
,"ERROR_NO_LOCAL_MANIFEST",0
,"ERROR_DOWNLOAD_MANIFEST",1
,"ERROR_PARSE_MANIFEST",2
,"NEW_VERSION_FOUND",3
,"ALREADY_UP_TO_DATE",4
,"UPDATE_PROGRESSION",5
,"ASSET_UPDATED",6
,"ERROR_UPDATING",7
,"UPDATE_FINISHED",8
,"UPDATE_FAILED",9
,"ERROR_DECOMPRESS",10
);}
void RegisterLuaExtensionEventAssetsManagerExAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::extension::EventAssetsManagerEx,cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventAssetsManagerEx",true);
ns["EventAssetsManagerEx"] = mt;
lua["EventAssetsManagerEx"] = sol::nil;
mt.set_function("getEventCode",static_cast<cocos2d::extension::EventAssetsManagerEx::EventCode(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getEventCode));
mt.set_function("getCURLECode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLECode));
mt.set_function("getCURLMCode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLMCode));
mt.set_function("getMessage",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getMessage));
mt.set_function("getAssetId",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetId));
mt.set_function("getAssetsManagerEx",static_cast<cocos2d::extension::AssetsManagerEx*(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetsManagerEx));
mt.set_function("getPercent",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercent));
mt.set_function("getPercentByFile",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercentByFile));
RegisterLuaExtensionEventAssetsManagerExEventCodeAuto(lua);
}
void RegisterLuaExtensionManifestDiffTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Manifest"];
pTable.new_enum("DiffType"
,"ADDED",0
,"DELETED",1
,"MODIFIED",2
);}
void RegisterLuaExtensionManifestDownloadStateAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Manifest"];
pTable.new_enum("DownloadState"
,"UNSTARTED",0
,"DOWNLOADING",1
,"SUCCESSED",2
,"UNMARKED",3
);}
void RegisterLuaExtensionManifestAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::extension::Manifest,cocos2d::Ref,cocos2d::LuaObject>("Manifest",true);
ns["Manifest"] = mt;
lua["Manifest"] = sol::nil;
mt.set_function("isVersionLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isVersionLoaded));
mt.set_function("isLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isLoaded));
mt.set_function("getPackageUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getPackageUrl));
mt.set_function("getManifestFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getManifestFileUrl));
mt.set_function("getVersionFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersionFileUrl));
mt.set_function("getVersion",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersion));
mt.set_function("getSearchPaths",static_cast<std::vector<std::string>(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getSearchPaths));
RegisterLuaExtensionManifestDiffTypeAuto(lua);
RegisterLuaExtensionManifestDownloadStateAuto(lua);
}
void RegisterLuaExtensionAssetsManagerExStateAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["AssetsManagerEx"];
pTable.new_enum("State"
,"UNCHECKED",0
,"PREDOWNLOAD_VERSION",1
,"DOWNLOADING_VERSION",2
,"VERSION_LOADED",3
,"PREDOWNLOAD_MANIFEST",4
,"DOWNLOADING_MANIFEST",5
,"MANIFEST_LOADED",6
,"NEED_UPDATE",7
,"UPDATING",8
,"UNZIPPING",9
,"UP_TO_DATE",10
,"FAIL_TO_UPDATE",11
);}
void RegisterLuaExtensionAssetsManagerExAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::extension::AssetsManagerEx,cocos2d::Ref,cocos2d::LuaObject>("AssetsManagerEx",false);
ns["AssetsManagerEx"] = mt;
lua["AssetsManagerEx"] = sol::nil;
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
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1,uint32_t arg2){return obj->create(arg0,arg1,arg2);}));
RegisterLuaExtensionAssetsManagerExStateAuto(lua);
}
void RegisterLuaExtensionEventListenerAssetsManagerExAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::extension::EventListenerAssetsManagerEx,cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerAssetsManagerEx",false);
ns["EventListenerAssetsManagerEx"] = mt;
lua["EventListenerAssetsManagerEx"] = sol::nil;
mt.set_function("checkAvailable",static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(*)(cocos2d::extension::AssetsManagerEx*,const std::function<void (cocos2d::extension::EventAssetsManagerEx *)>&)>(&cocos2d::extension::EventListenerAssetsManagerEx::create));
}
