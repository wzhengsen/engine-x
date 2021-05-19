#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
#include "Particle3D/PU/CCPUEmitter.h"
#include "Particle3D/PU/CCPUAffector.h"
#include "Particle3D/PU/CCPUObserver.h"
#include "Particle3D/CCParticle3DAffector.h"
void RegisterLuaExtensionLuaObjectAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::LuaObject>("cc","LuaObject",true);
mt.set_function("SetDtorHandler",static_cast<void(cocos2d::extension::LuaObject::*)(std::function<void (cocos2d::extension::LuaObject *)>&)>(&cocos2d::extension::LuaObject::SetDtorHandler));
mt.set_function("delete",static_cast<void(cocos2d::extension::LuaObject::*)()>(&cocos2d::extension::LuaObject::__delete__));
}
void RegisterLuaExtensionEventAssetsManagerExEventCodeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventAssetsManagerEx"];
pTable.new_enum<cocos2d::extension::EventAssetsManagerEx::EventCode>("EventCode",{
{"ERROR_NO_LOCAL_MANIFEST",cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_NO_LOCAL_MANIFEST}
,{"ERROR_DOWNLOAD_MANIFEST",cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_DOWNLOAD_MANIFEST}
,{"ERROR_PARSE_MANIFEST",cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_PARSE_MANIFEST}
,{"NEW_VERSION_FOUND",cocos2d::extension::EventAssetsManagerEx::EventCode::NEW_VERSION_FOUND}
,{"ALREADY_UP_TO_DATE",cocos2d::extension::EventAssetsManagerEx::EventCode::ALREADY_UP_TO_DATE}
,{"UPDATE_PROGRESSION",cocos2d::extension::EventAssetsManagerEx::EventCode::UPDATE_PROGRESSION}
,{"ASSET_UPDATED",cocos2d::extension::EventAssetsManagerEx::EventCode::ASSET_UPDATED}
,{"ERROR_UPDATING",cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_UPDATING}
,{"UPDATE_FINISHED",cocos2d::extension::EventAssetsManagerEx::EventCode::UPDATE_FINISHED}
,{"UPDATE_FAILED",cocos2d::extension::EventAssetsManagerEx::EventCode::UPDATE_FAILED}
,{"ERROR_DECOMPRESS",cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_DECOMPRESS}
});}
void RegisterLuaExtensionEventAssetsManagerExAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::EventAssetsManagerEx>("cc","EventAssetsManagerEx",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetEventCode",static_cast<cocos2d::extension::EventAssetsManagerEx::EventCode(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getEventCode));
mt.set_function("GetCURLECode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLECode));
mt.set_function("GetCURLMCode",static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLMCode));
mt.set_function("GetMessage",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getMessage));
mt.set_function("GetAssetId",static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetId));
mt.set_function("GetAssetsManagerEx",static_cast<cocos2d::extension::AssetsManagerEx*(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetsManagerEx));
mt.set_function("GetPercent",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercent));
mt.set_function("GetPercentByFile",static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercentByFile));
RegisterLuaExtensionEventAssetsManagerExEventCodeAuto(lua);
}
void RegisterLuaExtensionManifestAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::Manifest>("cc","Manifest",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("IsVersionLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isVersionLoaded));
mt.set_function("IsLoaded",static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isLoaded));
mt.set_function("GetPackageUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getPackageUrl));
mt.set_function("GetManifestFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getManifestFileUrl));
mt.set_function("GetVersionFileUrl",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersionFileUrl));
mt.set_function("GetVersion",static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersion));
mt.set_function("GetSearchPaths",static_cast<std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getSearchPaths));
mt["ValZipFileName"]=sol::var(std::ref(cocos2d::extension::Manifest::ValZipFileName));
}
void RegisterLuaExtensionAssetsManagerExAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::AssetsManagerEx>("cc","AssetsManagerEx",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::extension::AssetsManagerEx* obj,const std::string& arg0,const std::string& arg1,uint32_t arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("CheckUpdate",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::checkUpdate));
mt.set_function("Update",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::update));
mt.set_function("DownloadFailedAssets",static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::downloadFailedAssets));
mt.set_function("GetState",static_cast<cocos2d::extension::AssetsManagerEx::State(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getState));
mt.set_function("GetStoragePath",static_cast<const std::string&(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getStoragePath));
mt.set_function("GetLocalManifest",static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getLocalManifest));
mt.set_function("GetRemoteManifest",static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getRemoteManifest));
mt.set_function("GetMaxConcurrentTask",static_cast<const int(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getMaxConcurrentTask));
mt.set_function("SetMaxConcurrentTask",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const int)>(&cocos2d::extension::AssetsManagerEx::setMaxConcurrentTask));
mt.set_function("SetVersionCompareHandle",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<int (const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>&)>(&cocos2d::extension::AssetsManagerEx::setVersionCompareHandle));
mt.set_function("SetVerifyCallback",static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<bool (const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, cocos2d::extension::ManifestAsset)>&)>(&cocos2d::extension::AssetsManagerEx::setVerifyCallback));
mt["VERSION_ID"]=sol::var(std::ref(cocos2d::extension::AssetsManagerEx::VERSION_ID));
mt["MANIFEST_ID"]=sol::var(std::ref(cocos2d::extension::AssetsManagerEx::MANIFEST_ID));
mt["DEFAULT_CONNECTION_TIMEOUT_MS"]=sol::var(std::ref(cocos2d::extension::AssetsManagerEx::DEFAULT_CONNECTION_TIMEOUT_MS));
}
void RegisterLuaExtensionEventListenerAssetsManagerExAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::extension::EventListenerAssetsManagerEx>("cc","EventListenerAssetsManagerEx",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(*)(cocos2d::extension::AssetsManagerEx*,const std::function<void (cocos2d::extension::EventAssetsManagerEx *)>&)>(&cocos2d::extension::EventListenerAssetsManagerEx::create));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::checkAvailable));
mt.set_function("Clone",static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(cocos2d::extension::EventListenerAssetsManagerEx::*)()>(&cocos2d::extension::EventListenerAssetsManagerEx::clone));
}
