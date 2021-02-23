#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
void RegisterLuaCSLoaderCSLoaderAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CSLoader>("cc","CSLoader");
mt.set_function("init",static_cast<void(cocos2d::CSLoader::*)()>(&cocos2d::CSLoader::init));
mt.set_function("createNodeFromJson",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeFromJson));
mt.set_function("loadNodeWithFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithFile));
mt.set_function("loadNodeWithContent",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithContent));
mt.set_function("setRecordJsonPath",static_cast<void(cocos2d::CSLoader::*)(bool)>(&cocos2d::CSLoader::setRecordJsonPath));
mt.set_function("isRecordJsonPath",static_cast<bool(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::isRecordJsonPath));
mt.set_function("setJsonPath",static_cast<void(cocos2d::CSLoader::*)(std::string)>(&cocos2d::CSLoader::setJsonPath));
mt.set_function("getJsonPath",static_cast<std::string(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::getJsonPath));
mt.set_function("createNodeWithFlatBuffersFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersFile));
mt.set_function("bindCallback",static_cast<bool(cocos2d::CSLoader::*)(const std::string&,const std::string&,cocos2d::ui::Widget*,cocos2d::Node*)>(&cocos2d::CSLoader::bindCallback));
mt.set_function("registReaderObject",static_cast<void(cocos2d::CSLoader::*)(const std::string&,cocos2d::ObjectFactory::Instance)>(&cocos2d::CSLoader::registReaderObject));
mt.set_function("createNodeWithFlatBuffersForSimulator",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersForSimulator));
mt.set_function("getInstance",static_cast<cocos2d::CSLoader*(*)()>(&cocos2d::CSLoader::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::CSLoader::destroyInstance));
mt.set_function("createNodeWithVisibleSize",sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::CSLoader::createNodeWithVisibleSize),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithVisibleSize)));
}
