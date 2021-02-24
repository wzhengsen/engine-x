#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
void RegisterLuaCoreFileUtilsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FileUtils>("cc","FileUtils");
mt.set_function("purgeCachedEntries",static_cast<void(cocos2d::FileUtils::*)()>(&cocos2d::FileUtils::purgeCachedEntries));
mt.set_function("getStringFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::string)>)const>(&cocos2d::FileUtils::getStringFromFile),static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getStringFromFile)));
mt.set_function("getDataFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (cocos2d::Data)>)const>(&cocos2d::FileUtils::getDataFromFile),static_cast<cocos2d::Data(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getDataFromFile)));
mt.set_function("getContents",static_cast<cocos2d::FileUtils::Status(cocos2d::FileUtils::*)(const std::string&,cocos2d::ResizableBuffer*)const>(&cocos2d::FileUtils::getContents));
mt.set_function("fullPathForFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::fullPathForFilename));
mt.set_function("loadFilenameLookup",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::loadFilenameLookupDictionaryFromFile));
mt.set_function("setFilenameLookupDictionary",static_cast<void(cocos2d::FileUtils::*)(const cocos2d::ValueMap&)>(&cocos2d::FileUtils::setFilenameLookupDictionary));
mt.set_function("fullPathFromRelativeFile",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::fullPathFromRelativeFile));
mt.set_function("setSearchResolutionsOrder",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchResolutionsOrder));
mt.set_function("addSearchResolutionsOrder",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchResolutionsOrder(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchResolutionsOrder(arg0,arg1);}));
mt.set_function("getSearchResolutionsOrder",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchResolutionsOrder));
mt.set_function("setSearchPaths",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchPaths));
mt.set_function("getDefaultResourceRootPath",static_cast<const std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getDefaultResourceRootPath));
mt.set_function("setDefaultResourceRootPath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setDefaultResourceRootPath));
mt.set_function("addSearchPath",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchPath(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchPath(arg0,arg1);}));
mt.set_function("getSearchPaths",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchPaths));
mt.set_function("getOriginalSearchPaths",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getOriginalSearchPaths));
mt.set_function("getWritablePath",static_cast<std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getWritablePath));
mt.set_function("setWritablePath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setWritablePath));
mt.set_function("setPopupNotify",static_cast<void(cocos2d::FileUtils::*)(bool)>(&cocos2d::FileUtils::setPopupNotify));
mt.set_function("isPopupNotify",static_cast<bool(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::isPopupNotify));
mt.set_function("getValueMapFromFile",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueMapFromFile));
mt.set_function("getValueMapFromData",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const char*,int)const>(&cocos2d::FileUtils::getValueMapFromData));
mt.set_function("writeToFile",static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeToFile));
mt.set_function("writeStringToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(std::string,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeStringToFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::writeStringToFile)));
mt.set_function("writeDataToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::Data,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeDataToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::Data&,const std::string&)const>(&cocos2d::FileUtils::writeDataToFile)));
mt.set_function("writeValueMapToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueMap,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueMapToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeValueMapToFile)));
mt.set_function("writeValueVectorToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueVector,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueVectorToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueVector&,const std::string&)const>(&cocos2d::FileUtils::writeValueVectorToFile)));
mt.set_function("getValueVectorFromFile",static_cast<cocos2d::ValueVector(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueVectorFromFile));
mt.set_function("isFileExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isFileExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExist)));
mt.set_function("getFileExtension",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileExtension));
mt.set_function("isAbsolutePath",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isAbsolutePath));
mt.set_function("isDirectoryExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isDirectoryExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExist)));
mt.set_function("createDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::createDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::createDirectory)));
mt.set_function("removeDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeDirectory)));
mt.set_function("removeFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeFile)));
mt.set_function("renameFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile)));
mt.set_function("getFileSize",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (long long)>)const>(&cocos2d::FileUtils::getFileSize),static_cast<int64_t(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileSize)));
mt.set_function("listFiles",static_cast<std::vector<std::string>(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::listFiles));
mt.set_function("listFilesAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesAsync));
mt.set_function("listFilesRecursively",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::vector<std::string>*)const>(&cocos2d::FileUtils::listFilesRecursively));
mt.set_function("listFilesRecursivelyAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesRecursivelyAsync));
mt.set_function("getFullPathCache",static_cast<const std::unordered_map<std::string, std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getFullPathCache));
mt.set_function("getNewFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getNewFilename));
mt.set_function("isFileExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExistInternal));
mt.set_function("isDirectoryExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExistInternal));
mt.set_function("getInstance",static_cast<cocos2d::FileUtils*(*)()>(&cocos2d::FileUtils::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::FileUtils::destroyInstance));
mt.set_function("setDelegate",static_cast<void(*)(cocos2d::FileUtils*)>(&cocos2d::FileUtils::setDelegate));
mt.set_function("writeBinaryToFile",static_cast<bool(*)(const void*,size_t,const std::string&)>(&cocos2d::FileUtils::writeBinaryToFile));
mt.set_function("getFileShortName",static_cast<std::string(*)(const std::string&)>(&cocos2d::FileUtils::getFileShortName));
}
void RegisterLuaCoreEventAccelerationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventAcceleration,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventAcceleration");
}
void RegisterLuaCoreEventCustomAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventCustom");
mt.set_function("setUserData",static_cast<void(cocos2d::EventCustom::*)(void*)>(&cocos2d::EventCustom::setUserData));
mt.set_function("getUserData",static_cast<void*(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getUserData));
mt.set_function("getEventName",static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName));
}
void RegisterLuaCoreEventDispatcherAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventDispatcher,cocos2d::Ref,cocos2d::LuaObject>("cc","EventDispatcher");
mt.set_function("addEventListenerWithSceneGraphPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority));
mt.set_function("addEventListenerWithFixedPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority));
mt.set_function("addCustomEventListener",static_cast<cocos2d::EventListenerCustom*(cocos2d::EventDispatcher::*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventDispatcher::addCustomEventListener));
mt.set_function("removeEventListener",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*)>(&cocos2d::EventDispatcher::removeEventListener));
mt.set_function("removeEventListenersForType",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener::Type)>(&cocos2d::EventDispatcher::removeEventListenersForType));
mt.set_function("removeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->removeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->removeEventListenersForTarget(arg0,arg1);}));
mt.set_function("removeCustomEventListeners",static_cast<void(cocos2d::EventDispatcher::*)(const std::string&)>(&cocos2d::EventDispatcher::removeCustomEventListeners));
mt.set_function("removeAllEventListeners",static_cast<void(cocos2d::EventDispatcher::*)()>(&cocos2d::EventDispatcher::removeAllEventListeners));
mt.set_function("pauseEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->pauseEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->pauseEventListenersForTarget(arg0,arg1);}));
mt.set_function("resumeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->resumeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->resumeEventListenersForTarget(arg0,arg1);}));
mt.set_function("setPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::setPriority));
mt.set_function("setEnabled",static_cast<void(cocos2d::EventDispatcher::*)(bool)>(&cocos2d::EventDispatcher::setEnabled));
mt.set_function("isEnabled",static_cast<bool(cocos2d::EventDispatcher::*)()const>(&cocos2d::EventDispatcher::isEnabled));
mt.set_function("dispatchEvent",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::Event*)>(&cocos2d::EventDispatcher::dispatchEvent));
mt.set_function("dispatchCustomEvent",sol::overload([](cocos2d::EventDispatcher* obj,const std::string& arg0){return obj->dispatchCustomEvent(arg0);},[](cocos2d::EventDispatcher* obj,const std::string& arg0,void* arg1){return obj->dispatchCustomEvent(arg0,arg1);}));
mt.set_function("hasEventListener",static_cast<bool(cocos2d::EventDispatcher::*)(const cocos2d::EventListener::ListenerID&)const>(&cocos2d::EventDispatcher::hasEventListener));
}
void RegisterLuaCoreEventFocusAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventFocus,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventFocus");
}
void RegisterLuaCoreEventListenerAccelerationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerAcceleration,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerAcceleration");
mt.set_function("clone",static_cast<cocos2d::EventListenerAcceleration*(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::checkAvailable));
mt.set_function("new",static_cast<cocos2d::EventListenerAcceleration*(*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::create));
}
void RegisterLuaCoreEventListenerFocusAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerFocus,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerFocus");
mt.set_function("clone",static_cast<cocos2d::EventListenerFocus*(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::checkAvailable));
mt.set_function("new",static_cast<cocos2d::EventListenerFocus*(*)()>(&cocos2d::EventListenerFocus::create));
mt["onFocusChanged"] = &cocos2d::EventListenerFocus::onFocusChanged;
}
void RegisterLuaCoreEventListenerKeyboardAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerKeyboard,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerKeyboard");
mt.set_function("clone",static_cast<cocos2d::EventListenerKeyboard*(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::checkAvailable));
mt.set_function("new",static_cast<cocos2d::EventListenerKeyboard*(*)()>(&cocos2d::EventListenerKeyboard::create));
mt["onKeyPressed"] = &cocos2d::EventListenerKeyboard::onKeyPressed;
mt["onKeyReleased"] = &cocos2d::EventListenerKeyboard::onKeyReleased;
}
void RegisterLuaCoreEventMouseAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventMouse,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventMouse");
mt.set_function("setScrollData",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setScrollData));
mt.set_function("getScrollX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollX));
mt.set_function("getScrollY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollY));
mt.set_function("setCursorPosition",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setCursorPosition));
mt.set_function("setMouseButton",static_cast<void(cocos2d::EventMouse::*)(cocos2d::EventMouse::MouseButton)>(&cocos2d::EventMouse::setMouseButton));
mt.set_function("getMouseButton",static_cast<cocos2d::EventMouse::MouseButton(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getMouseButton));
mt.set_function("getCursorX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorX));
mt.set_function("getCursorY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorY));
mt.set_function("getLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocation));
mt.set_function("getPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocation));
mt.set_function("getStartLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocation));
mt.set_function("getDelta",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getDelta));
mt.set_function("getLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocationInView));
mt.set_function("getPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocationInView));
mt.set_function("getStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocationInView));
}
void RegisterLuaCoreEventListenerMouseAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerMouse,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerMouse");
mt.set_function("clone",static_cast<cocos2d::EventListenerMouse*(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::clone));
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::checkAvailable));
mt.set_function("new",static_cast<cocos2d::EventListenerMouse*(*)()>(&cocos2d::EventListenerMouse::create));
mt["onMouseDown"] = &cocos2d::EventListenerMouse::onMouseDown;
mt["onMouseUp"] = &cocos2d::EventListenerMouse::onMouseUp;
mt["onMouseMove"] = &cocos2d::EventListenerMouse::onMouseMove;
mt["onMouseScroll"] = &cocos2d::EventListenerMouse::onMouseScroll;
}
