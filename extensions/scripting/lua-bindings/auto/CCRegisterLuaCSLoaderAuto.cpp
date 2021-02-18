#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
static void RegisterLuaCSLoader(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CSLoader>("cc","CSLoader"
,"init",static_cast<void(cocos2d::CSLoader::*)()>(&cocos2d::CSLoader::init)
,"createNodeFromJson",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeFromJson)
,"loadNodeWithFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithFile)
,"loadNodeWithContent",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithContent)
,"setRecordJsonPath",static_cast<void(cocos2d::CSLoader::*)(bool)>(&cocos2d::CSLoader::setRecordJsonPath)
,"isRecordJsonPath",static_cast<bool(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::isRecordJsonPath)
,"setJsonPath",static_cast<void(cocos2d::CSLoader::*)(std::string)>(&cocos2d::CSLoader::setJsonPath)
,"getJsonPath",static_cast<std::string(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::getJsonPath)
,"createNodeWithFlatBuffersFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersFile)
,"bindCallback",static_cast<bool(cocos2d::CSLoader::*)(const std::string&,const std::string&,cocos2d::ui::Widget*,cocos2d::Node*)>(&cocos2d::CSLoader::bindCallback)
,"registReaderObject",static_cast<void(cocos2d::CSLoader::*)(const std::string&,cocos2d::ObjectFactory::Instance)>(&cocos2d::CSLoader::registReaderObject)
,"createNodeWithFlatBuffersForSimulator",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersForSimulator)
,"getInstance",static_cast<cocos2d::CSLoader*(*)()>(&cocos2d::CSLoader::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::CSLoader::destroyInstance)
,"createNodeWithVisibleSize",sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::CSLoader::createNodeWithVisibleSize),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithVisibleSize))
);}
void RegisterLuaCSLoaderAuto(cocos2d::Lua& lua) {
RegisterLuaCSLoader(lua);
}
