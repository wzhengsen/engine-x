#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreFadeInAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeIn,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeIn");
mt.set_function("startWithTarget",static_cast<void(cocos2d::FadeIn::*)(cocos2d::Node*)>(&cocos2d::FadeIn::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::FadeIn*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::clone));
mt.set_function("reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::reverse));
mt.set_function("setReverseAction",static_cast<void(cocos2d::FadeIn::*)(cocos2d::FadeTo*)>(&cocos2d::FadeIn::setReverseAction));
mt.set_function("new",static_cast<cocos2d::FadeIn*(*)(float)>(&cocos2d::FadeIn::create));
}
void RegisterLuaCoreFadeOutAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOut,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOut");
mt.set_function("startWithTarget",static_cast<void(cocos2d::FadeOut::*)(cocos2d::Node*)>(&cocos2d::FadeOut::startWithTarget));
mt.set_function("clone",static_cast<cocos2d::FadeOut*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::clone));
mt.set_function("reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::reverse));
mt.set_function("setReverseAction",static_cast<void(cocos2d::FadeOut::*)(cocos2d::FadeTo*)>(&cocos2d::FadeOut::setReverseAction));
mt.set_function("new",static_cast<cocos2d::FadeOut*(*)(float)>(&cocos2d::FadeOut::create));
}
void RegisterLuaCoreTintToAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TintTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TintTo");
mt.set_function("clone",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::clone));
mt.set_function("reverse",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TintTo::*)(cocos2d::Node*)>(&cocos2d::TintTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TintTo::*)(float)>(&cocos2d::TintTo::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TintTo::*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::initWithDuration));
mt.set_function("new",sol::overload(static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create)));
}
void RegisterLuaCoreTintByAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TintBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TintBy");
mt.set_function("clone",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::clone));
mt.set_function("reverse",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TintBy::*)(cocos2d::Node*)>(&cocos2d::TintBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TintBy::*)(float)>(&cocos2d::TintBy::update));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::TintBy::*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::initWithDuration));
mt.set_function("new",static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create));
}
void RegisterLuaCoreDelayTimeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::DelayTime,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","DelayTime");
mt.set_function("update",static_cast<void(cocos2d::DelayTime::*)(float)>(&cocos2d::DelayTime::update));
mt.set_function("reverse",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::reverse));
mt.set_function("clone",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::clone));
mt.set_function("new",static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create));
}
void RegisterLuaCoreAnimateAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animate,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate");
mt.set_function("setAnimation",static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation));
mt.set_function("getAnimation",sol::overload(static_cast<const cocos2d::Animation*(cocos2d::Animate::*)()const>(&cocos2d::Animate::getAnimation),static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation)));
mt.set_function("getCurrentFrameIndex",static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex));
mt.set_function("clone",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::clone));
mt.set_function("reverse",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Animate::*)(cocos2d::Node*)>(&cocos2d::Animate::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Animate::*)()>(&cocos2d::Animate::stop));
mt.set_function("update",static_cast<void(cocos2d::Animate::*)(float)>(&cocos2d::Animate::update));
mt.set_function("initWithAnimation",static_cast<bool(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::initWithAnimation));
mt.set_function("new",static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create));
}
void RegisterLuaCoreTargetedActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TargetedAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TargetedAction");
mt.set_function("setForcedTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget));
mt.set_function("getForcedTarget",sol::overload(static_cast<const cocos2d::Node*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::getForcedTarget),static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget)));
mt.set_function("clone",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::clone));
mt.set_function("reverse",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::stop));
mt.set_function("update",static_cast<void(cocos2d::TargetedAction::*)(float)>(&cocos2d::TargetedAction::update));
mt.set_function("initWithTarget",static_cast<bool(cocos2d::TargetedAction::*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::initWithTarget));
mt.set_function("new",static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create));
}
void RegisterLuaCoreActionFloatAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionFloat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionFloat");
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionFloat::*)(cocos2d::Node*)>(&cocos2d::ActionFloat::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ActionFloat::*)(float)>(&cocos2d::ActionFloat::update));
mt.set_function("reverse",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::clone));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ActionFloat::*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::initWithDuration));
mt.set_function("new",static_cast<cocos2d::ActionFloat*(*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::create));
}
void RegisterLuaCoreEventKeyboardAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventKeyboard,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventKeyboard");
}
void RegisterLuaCorePropertiesAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Properties>("cc","Properties");
mt.set_function("getNextProperty",static_cast<const char*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextProperty));
mt.set_function("getNextNamespace",static_cast<cocos2d::Properties*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextNamespace));
mt.set_function("rewind",static_cast<void(cocos2d::Properties::*)()>(&cocos2d::Properties::rewind));
mt.set_function("getNamespace",sol::overload(static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getNamespace),[](cocos2d::Properties* obj,const char* arg0){return obj->getNamespace(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getNamespace(arg0,arg1);},[](cocos2d::Properties* obj,const char* arg0,bool arg1,bool arg2){return obj->getNamespace(arg0,arg1,arg2);}));
mt.set_function("getId",static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getId));
mt.set_function("exists",static_cast<bool(cocos2d::Properties::*)(const char*)const>(&cocos2d::Properties::exists));
mt.set_function("getType",sol::overload([](cocos2d::Properties* obj){return obj->getType();},[](cocos2d::Properties* obj,const char* arg0){return obj->getType(arg0);}));
mt.set_function("getString",sol::overload([](cocos2d::Properties* obj){return obj->getString();},[](cocos2d::Properties* obj,const char* arg0){return obj->getString(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getString(arg0,arg1);}));
mt.set_function("setString",static_cast<bool(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setString));
mt.set_function("getBool",sol::overload([](cocos2d::Properties* obj){return obj->getBool();},[](cocos2d::Properties* obj,const char* arg0){return obj->getBool(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getBool(arg0,arg1);}));
mt.set_function("getInt",sol::overload([](cocos2d::Properties* obj){return obj->getInt();},[](cocos2d::Properties* obj,const char* arg0){return obj->getInt(arg0);}));
mt.set_function("getFloat",sol::overload([](cocos2d::Properties* obj){return obj->getFloat();},[](cocos2d::Properties* obj,const char* arg0){return obj->getFloat(arg0);}));
mt.set_function("getLong",sol::overload([](cocos2d::Properties* obj){return obj->getLong();},[](cocos2d::Properties* obj,const char* arg0){return obj->getLong(arg0);}));
mt.set_function("getMat4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Mat4*)const>(&cocos2d::Properties::getMat4));
mt.set_function("getVec2",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec2*)const>(&cocos2d::Properties::getVec2));
mt.set_function("getVec3",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getVec3));
mt.set_function("getVec4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getVec4));
mt.set_function("getQuaternionFromAxisAngle",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Quaternion*)const>(&cocos2d::Properties::getQuaternionFromAxisAngle));
mt.set_function("getColor",sol::overload(static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getColor),static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getColor)));
mt.set_function("getPath",static_cast<bool(cocos2d::Properties::*)(const char*,std::string*)const>(&cocos2d::Properties::getPath));
mt.set_function("getVariable",sol::overload([](cocos2d::Properties* obj,const char* arg0){return obj->getVariable(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getVariable(arg0,arg1);}));
mt.set_function("setVariable",static_cast<void(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setVariable));
mt.set_function("parseVec2",static_cast<bool(*)(const char*,cocos2d::Vec2*)>(&cocos2d::Properties::parseVec2));
mt.set_function("parseVec3",static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseVec3));
mt.set_function("parseVec4",static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseVec4));
mt.set_function("parseAxisAngle",static_cast<bool(*)(const char*,cocos2d::Quaternion*)>(&cocos2d::Properties::parseAxisAngle));
mt.set_function("parseColor",sol::overload(static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseColor),static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseColor)));
}
void RegisterLuaCoreUserDefaultAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::UserDefault>("cc","UserDefault");
mt.set_function("getBoolForKey",sol::overload(static_cast<bool(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::getBoolForKey),static_cast<bool(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getBoolForKey)));
mt.set_function("getIntegerForKey",sol::overload(static_cast<int(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::getIntegerForKey),static_cast<int(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getIntegerForKey)));
mt.set_function("getLargeIntForKey",sol::overload(static_cast<int64_t(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::getLargeIntForKey),static_cast<int64_t(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getLargeIntForKey)));
mt.set_function("getFloatForKey",sol::overload(static_cast<float(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::getFloatForKey),static_cast<float(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getFloatForKey)));
mt.set_function("getDoubleForKey",sol::overload(static_cast<double(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::getDoubleForKey),static_cast<double(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getDoubleForKey)));
mt.set_function("getStringForKey",sol::overload(static_cast<std::string(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::getStringForKey),static_cast<std::string(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getStringForKey)));
mt.set_function("setBoolForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::setBoolForKey));
mt.set_function("setIntegerForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::setIntegerForKey));
mt.set_function("setLargeIntForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::setLargeIntForKey));
mt.set_function("setFloatForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::setFloatForKey));
mt.set_function("setDoubleForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::setDoubleForKey));
mt.set_function("setStringForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::setStringForKey));
mt.set_function("flush",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::flush));
mt.set_function("deleteValueForKey",static_cast<void(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::deleteValueForKey));
mt.set_function("Clear",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::Clear));
mt.set_function("setEncryptEnabled",static_cast<void(cocos2d::UserDefault::*)(bool,cxx17::string_view,cxx17::string_view)>(&cocos2d::UserDefault::setEncryptEnabled));
mt.set_function("getInstance",static_cast<cocos2d::UserDefault*(*)()>(&cocos2d::UserDefault::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::UserDefault::destroyInstance));
}
void RegisterLuaCoreFileUtilsAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FileUtils>("cc","FileUtils");
mt.set_function("purgeCachedEntries",static_cast<void(cocos2d::FileUtils::*)()>(&cocos2d::FileUtils::purgeCachedEntries));
mt.set_function("getStringFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::string)>)const>(&cocos2d::FileUtils::getStringFromFile),static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getStringFromFile)));
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
mt.set_function("getNewFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getNewFilename));
mt.set_function("isFileExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExistInternal));
mt.set_function("isDirectoryExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExistInternal));
mt.set_function("getInstance",static_cast<cocos2d::FileUtils*(*)()>(&cocos2d::FileUtils::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::FileUtils::destroyInstance));
mt.set_function("writeBinaryToFile",static_cast<bool(*)(const void*,size_t,const std::string&)>(&cocos2d::FileUtils::writeBinaryToFile));
mt.set_function("getFileShortName",static_cast<std::string(*)(const std::string&)>(&cocos2d::FileUtils::getFileShortName));
}
void RegisterLuaCoreEventAccelerationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventAcceleration,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventAcceleration");
}
void RegisterLuaCoreEventCustomAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventCustom");
mt.set_function("getEventName",static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName));
}
void RegisterLuaCoreEventDispatcherAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventDispatcher,cocos2d::Ref,cocos2d::LuaObject>("cc","EventDispatcher");
mt.set_function("addEventListenerWithSceneGraphPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority));
mt.set_function("addEventListenerWithFixedPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority));
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
