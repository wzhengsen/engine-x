#include "scripting/lua-bindings/auto/CCRegisterLuaExtensionAuto.hpp"
#include "cocos-ext.h"
#include "Particle3D/PU/CCPUEmitter.h"
#include "Particle3D/PU/CCPUAffector.h"
#include "Particle3D/PU/CCPUObserver.h"
#include "Particle3D/CCParticle3DAffector.h"
void RegisterLuaExtensionLuaObjectAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::extension::LuaObject).name()] = sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable();
auto dep=lua.new_usertype<cocos2d::extension::LuaObject>("deprecated.cocos2d::extension::LuaObject");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable());
lua["cc"]["LuaObject"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["SetDeleteHandler"]=static_cast<void(cocos2d::extension::LuaObject::*)(const std::function<void (cocos2d::extension::LuaObject *)>&)>(&cocos2d::extension::LuaObject::SetDeleteHandler);
mt["set"]["DeleteHandler"]=mt["SetDeleteHandler"];
mt["__delete__"]=static_cast<void(cocos2d::extension::LuaObject::*)()>(&cocos2d::extension::LuaObject::__delete__);
}
void RegisterLuaExtensionEventAssetsManagerExEventCodeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,11);
enumTable["ERROR_NO_LOCAL_MANIFEST"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_NO_LOCAL_MANIFEST;
enumTable["ERROR_DOWNLOAD_MANIFEST"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_DOWNLOAD_MANIFEST;
enumTable["ERROR_PARSE_MANIFEST"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_PARSE_MANIFEST;
enumTable["NEW_VERSION_FOUND"]=cocos2d::extension::EventAssetsManagerEx::EventCode::NEW_VERSION_FOUND;
enumTable["ALREADY_UP_TO_DATE"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ALREADY_UP_TO_DATE;
enumTable["UPDATE_PROGRESSION"]=cocos2d::extension::EventAssetsManagerEx::EventCode::UPDATE_PROGRESSION;
enumTable["ASSET_UPDATED"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ASSET_UPDATED;
enumTable["ERROR_UPDATING"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_UPDATING;
enumTable["UPDATE_FINISHED"]=cocos2d::extension::EventAssetsManagerEx::EventCode::UPDATE_FINISHED;
enumTable["UPDATE_FAILED"]=cocos2d::extension::EventAssetsManagerEx::EventCode::UPDATE_FAILED;
enumTable["ERROR_DECOMPRESS"]=cocos2d::extension::EventAssetsManagerEx::EventCode::ERROR_DECOMPRESS;
lua["cc"]["EventAssetsManagerEx"]["static"]["EventCode"]=lua.NewEnum(enumTable);
}
void RegisterLuaExtensionEventAssetsManagerExAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::extension::EventAssetsManagerEx).name()] = sol::usertype_traits<cocos2d::extension::EventAssetsManagerEx*>::metatable();
auto dep=lua.new_usertype<cocos2d::extension::EventAssetsManagerEx>("deprecated.cocos2d::extension::EventAssetsManagerEx");
dep[sol::base_classes]=sol::bases<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::extension::EventAssetsManagerEx*>::metatable(),sol::usertype_traits<cocos2d::EventCustom*>::metatable());
lua["cc"]["EventAssetsManagerEx"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["GetEventCode"]=static_cast<cocos2d::extension::EventAssetsManagerEx::EventCode(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getEventCode);
mt["get"]["EventCode"]=mt["GetEventCode"];
mt["GetCURLECode"]=static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLECode);
mt["get"]["CURLECode"]=mt["GetCURLECode"];
mt["GetCURLMCode"]=static_cast<int(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getCURLMCode);
mt["get"]["CURLMCode"]=mt["GetCURLMCode"];
mt["GetMessage"]=static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getMessage);
mt["get"]["Message"]=mt["GetMessage"];
mt["GetAssetId"]=static_cast<std::string(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetId);
mt["get"]["AssetId"]=mt["GetAssetId"];
mt["GetAssetsManagerEx"]=static_cast<cocos2d::extension::AssetsManagerEx*(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getAssetsManagerEx);
mt["get"]["AssetsManagerEx"]=mt["GetAssetsManagerEx"];
mt["GetPercent"]=static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercent);
mt["get"]["Percent"]=mt["GetPercent"];
mt["GetPercentByFile"]=static_cast<float(cocos2d::extension::EventAssetsManagerEx::*)()const>(&cocos2d::extension::EventAssetsManagerEx::getPercentByFile);
mt["get"]["PercentByFile"]=mt["GetPercentByFile"];
RegisterLuaExtensionEventAssetsManagerExEventCodeAuto(lua);
}
void RegisterLuaExtensionManifestAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::extension::Manifest).name()] = sol::usertype_traits<cocos2d::extension::Manifest*>::metatable();
auto dep=lua.new_usertype<cocos2d::extension::Manifest>("deprecated.cocos2d::extension::Manifest");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::extension::Manifest*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Manifest"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["IsVersionLoaded"]=static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isVersionLoaded);
mt["get"]["VersionLoaded"]=mt["IsVersionLoaded"];
mt["IsLoaded"]=static_cast<bool(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::isLoaded);
mt["get"]["Loaded"]=mt["IsLoaded"];
mt["GetPackageUrl"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getPackageUrl);
mt["get"]["PackageUrl"]=mt["GetPackageUrl"];
mt["GetManifestFileUrl"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getManifestFileUrl);
mt["get"]["ManifestFileUrl"]=mt["GetManifestFileUrl"];
mt["GetVersionFileUrl"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersionFileUrl);
mt["get"]["VersionFileUrl"]=mt["GetVersionFileUrl"];
mt["GetVersion"]=static_cast<const std::string&(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getVersion);
mt["get"]["Version"]=mt["GetVersion"];
mt["GetSearchPaths"]=static_cast<std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(cocos2d::extension::Manifest::*)()const>(&cocos2d::extension::Manifest::getSearchPaths);
mt["get"]["SearchPaths"]=mt["GetSearchPaths"];
mt["static"]["get"]["ValZipFileName"]=[]()->const std::string&{return cocos2d::extension::Manifest::ValZipFileName;};
}
void RegisterLuaExtensionAssetsManagerExAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::extension::AssetsManagerEx).name()] = sol::usertype_traits<cocos2d::extension::AssetsManagerEx*>::metatable();
auto dep=lua.new_usertype<cocos2d::extension::AssetsManagerEx>("deprecated.cocos2d::extension::AssetsManagerEx");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::extension::AssetsManagerEx*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["AssetsManagerEx"]=mt;
mt["__new__"]=sol::overload([](const std::string& arg0,const std::string& arg1,uint32_t arg2){return cocos2d::extension::AssetsManagerEx::create(arg0,arg1,arg2);},[](const std::string& arg0,const std::string& arg1){return cocos2d::extension::AssetsManagerEx::create(arg0,arg1);});
mt["CheckUpdate"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::checkUpdate);
mt["Update"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::update);
mt["DownloadFailedAssets"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)()>(&cocos2d::extension::AssetsManagerEx::downloadFailedAssets);
mt["GetState"]=static_cast<cocos2d::extension::AssetsManagerEx::State(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getState);
mt["get"]["State"]=mt["GetState"];
mt["GetStoragePath"]=static_cast<const std::string&(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getStoragePath);
mt["get"]["StoragePath"]=mt["GetStoragePath"];
mt["GetLocalManifest"]=static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getLocalManifest);
mt["get"]["LocalManifest"]=mt["GetLocalManifest"];
mt["GetRemoteManifest"]=static_cast<const cocos2d::extension::Manifest*(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getRemoteManifest);
mt["get"]["RemoteManifest"]=mt["GetRemoteManifest"];
mt["GetMaxConcurrentTask"]=static_cast<const int(cocos2d::extension::AssetsManagerEx::*)()const>(&cocos2d::extension::AssetsManagerEx::getMaxConcurrentTask);
mt["get"]["MaxConcurrentTask"]=mt["GetMaxConcurrentTask"];
mt["SetMaxConcurrentTask"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const int)>(&cocos2d::extension::AssetsManagerEx::setMaxConcurrentTask);
mt["set"]["MaxConcurrentTask"]=mt["SetMaxConcurrentTask"];
mt["SetVersionCompareHandle"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<int (const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>&)>(&cocos2d::extension::AssetsManagerEx::setVersionCompareHandle);
mt["set"]["VersionCompareHandle"]=mt["SetVersionCompareHandle"];
mt["SetVerifyCallback"]=static_cast<void(cocos2d::extension::AssetsManagerEx::*)(const std::function<bool (const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, cocos2d::extension::ManifestAsset)>&)>(&cocos2d::extension::AssetsManagerEx::setVerifyCallback);
mt["set"]["VerifyCallback"]=mt["SetVerifyCallback"];
mt["static"]["get"]["VERSION_ID"]=[]()->const std::string&{return cocos2d::extension::AssetsManagerEx::VERSION_ID;};
mt["static"]["get"]["MANIFEST_ID"]=[]()->const std::string&{return cocos2d::extension::AssetsManagerEx::MANIFEST_ID;};
mt["static"]["get"]["DEFAULT_CONNECTION_TIMEOUT_MS"]=[]()->const uint32_t&{return cocos2d::extension::AssetsManagerEx::DEFAULT_CONNECTION_TIMEOUT_MS;};
}
void RegisterLuaExtensionEventListenerAssetsManagerExAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::extension::EventListenerAssetsManagerEx).name()] = sol::usertype_traits<cocos2d::extension::EventListenerAssetsManagerEx*>::metatable();
auto dep=lua.new_usertype<cocos2d::extension::EventListenerAssetsManagerEx>("deprecated.cocos2d::extension::EventListenerAssetsManagerEx");
dep[sol::base_classes]=sol::bases<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::extension::EventListenerAssetsManagerEx*>::metatable(),sol::usertype_traits<cocos2d::EventListenerCustom*>::metatable());
lua["cc"]["EventListenerAssetsManagerEx"]=mt;
mt["__new__"]=static_cast<cocos2d::extension::EventListenerAssetsManagerEx*(*)(cocos2d::extension::AssetsManagerEx*,const std::function<void (cocos2d::extension::EventAssetsManagerEx *)>&)>(&cocos2d::extension::EventListenerAssetsManagerEx::create);
}
