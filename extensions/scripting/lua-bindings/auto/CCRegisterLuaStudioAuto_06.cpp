#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioComExtensionDataAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocostudio::ComExtensionData>("ccs","ComExtensionData",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocostudio::ComExtensionData::createInstance));
mt.set_function("OnEnter",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onEnter));
mt.set_function("OnExit",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onExit));
mt.set_function("OnAdd",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onAdd));
mt.set_function("OnRemove",static_cast<void(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::onRemove));
mt.set_function(sol::meta_function::construct,static_cast<cocostudio::ComExtensionData*(*)()>(&cocostudio::ComExtensionData::create));
mt.set_function("Init",static_cast<bool(cocostudio::ComExtensionData::*)()>(&cocostudio::ComExtensionData::init));
mt.set_function("SetCustomProperty",static_cast<void(cocostudio::ComExtensionData::*)(const std::string&)>(&cocostudio::ComExtensionData::setCustomProperty));
mt.set_function("GetCustomProperty",static_cast<std::string(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getCustomProperty));
mt.set_function("SetActionTag",static_cast<void(cocostudio::ComExtensionData::*)(int)>(&cocostudio::ComExtensionData::setActionTag));
mt.set_function("GetActionTag",static_cast<int(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getActionTag));
mt[sol::call_constructor]=sol::constructors<cocostudio::ComExtensionData()>();
mt["Type"]=sol::var(std::ref(cocostudio::ComExtensionData::Type));
mt["COMPONENT_NAME"]=sol::var(std::ref(cocostudio::ComExtensionData::COMPONENT_NAME));
}
