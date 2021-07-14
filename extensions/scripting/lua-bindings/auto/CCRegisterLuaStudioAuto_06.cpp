#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
namespace cocos2d{
void RegisterLuaStudioComExtensionDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ComExtensionData).name()] = sol::usertype_traits<cocostudio::ComExtensionData*>::metatable();
auto dep=lua.new_usertype<cocostudio::ComExtensionData>("deprecated.cocostudio::ComExtensionData");
dep[sol::base_classes]=sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ComExtensionData*>::metatable(),sol::usertype_traits<cocos2d::Component*>::metatable());
lua["ccs"]["ComExtensionData"]=mt;
mt["__new__"]=static_cast<cocostudio::ComExtensionData*(*)()>(&cocostudio::ComExtensionData::create);
mt["SetCustomProperty"]=static_cast<void(cocostudio::ComExtensionData::*)(const std::string&)>(&cocostudio::ComExtensionData::setCustomProperty);
mt["set"]["CustomProperty"]=mt["SetCustomProperty"];
mt["GetCustomProperty"]=static_cast<std::string(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getCustomProperty);
mt["get"]["CustomProperty"]=mt["GetCustomProperty"];
mt["SetActionTag"]=static_cast<void(cocostudio::ComExtensionData::*)(int)>(&cocostudio::ComExtensionData::setActionTag);
mt["set"]["ActionTag"]=mt["SetActionTag"];
mt["GetActionTag"]=static_cast<int(cocostudio::ComExtensionData::*)()const>(&cocostudio::ComExtensionData::getActionTag);
mt["get"]["ActionTag"]=mt["GetActionTag"];
mt["static"]["set"]["Type"]=[](const sol::object&,const cocos2d::ObjectFactory::TInfo& value){cocostudio::ComExtensionData::Type = value;};
mt["static"]["get"]["Type"]=[]()->const cocos2d::ObjectFactory::TInfo&{return cocostudio::ComExtensionData::Type;};
mt["static"]["get"]["COMPONENT_NAME"]=[]()->const std::string&{return cocostudio::ComExtensionData::COMPONENT_NAME;};
}
}
