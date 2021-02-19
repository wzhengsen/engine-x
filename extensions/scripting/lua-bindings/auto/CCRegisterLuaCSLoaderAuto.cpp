#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
static void RegisterLuaCSLoaderCSLoader(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CSLoader>("cc","CSLoader");
mt["init"]=static_cast<void(cocos2d::CSLoader::*)()>(&cocos2d::CSLoader::init);
mt["createNodeFromJson"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeFromJson);
mt["loadNodeWithFile"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithFile);
mt["loadNodeWithContent"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithContent);
mt["setRecordJsonPath"]=static_cast<void(cocos2d::CSLoader::*)(bool)>(&cocos2d::CSLoader::setRecordJsonPath);
mt["isRecordJsonPath"]=static_cast<bool(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::isRecordJsonPath);
mt["setJsonPath"]=static_cast<void(cocos2d::CSLoader::*)(std::string)>(&cocos2d::CSLoader::setJsonPath);
mt["getJsonPath"]=static_cast<std::string(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::getJsonPath);
mt["createNodeWithFlatBuffersFile"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersFile);
mt["bindCallback"]=static_cast<bool(cocos2d::CSLoader::*)(const std::string&,const std::string&,cocos2d::ui::Widget*,cocos2d::Node*)>(&cocos2d::CSLoader::bindCallback);
mt["registReaderObject"]=static_cast<void(cocos2d::CSLoader::*)(const std::string&,cocos2d::ObjectFactory::Instance)>(&cocos2d::CSLoader::registReaderObject);
mt["createNodeWithFlatBuffersForSimulator"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersForSimulator);
mt["getInstance"]=static_cast<cocos2d::CSLoader*(*)()>(&cocos2d::CSLoader::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::CSLoader::destroyInstance);
mt["createNodeWithVisibleSize"]=sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::CSLoader::createNodeWithVisibleSize),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithVisibleSize));
}
void RegisterLuaCSLoaderAuto(cocos2d::Lua& lua) {
RegisterLuaCSLoaderCSLoader(lua);
}
