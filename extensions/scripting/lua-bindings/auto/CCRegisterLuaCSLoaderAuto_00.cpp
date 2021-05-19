#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
void RegisterLuaCSLoaderCSLoaderAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::CSLoader>("cc","CSLoader",false);
mt.set_function("GetInstance",static_cast<cocos2d::CSLoader*(*)()>(&cocos2d::CSLoader::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::CSLoader::destroyInstance));
mt.set_function("Init",static_cast<void(cocos2d::CSLoader::*)()>(&cocos2d::CSLoader::init));
mt.set_function("CreateNode",sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const cocos2d::Data&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const cocos2d::Data&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNode)));
mt.set_function("CreateNodeWithVisibleSize",sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNodeWithVisibleSize),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithVisibleSize)));
mt.set_function("CreateTimeline",sol::overload(static_cast<cocostudio::timeline::ActionTimeline*(*)(const cocos2d::Data&,const std::string&)>(&cocos2d::CSLoader::createTimeline),static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocos2d::CSLoader::createTimeline)));
mt.set_function("CreateNodeFromJson",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeFromJson));
mt.set_function("LoadNodeWithFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithFile));
mt.set_function("LoadNodeWithContent",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithContent));
mt.set_function("SetRecordJsonPath",static_cast<void(cocos2d::CSLoader::*)(bool)>(&cocos2d::CSLoader::setRecordJsonPath));
mt.set_function("IsRecordJsonPath",static_cast<bool(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::isRecordJsonPath));
mt.set_function("SetJsonPath",static_cast<void(cocos2d::CSLoader::*)(std::string)>(&cocos2d::CSLoader::setJsonPath));
mt.set_function("GetJsonPath",static_cast<std::string(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::getJsonPath));
mt.set_function("CreateNodeWithFlatBuffersFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersFile));
mt.set_function("NodeWithFlatBuffersFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::nodeWithFlatBuffersFile));
mt.set_function("NodeWithFlatBuffers",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const flatbuffers::NodeTree*)>(&cocos2d::CSLoader::nodeWithFlatBuffers));
mt.set_function("BindCallback",static_cast<bool(cocos2d::CSLoader::*)(const std::string&,const std::string&,cocos2d::ui::Widget*,cocos2d::Node*)>(&cocos2d::CSLoader::bindCallback));
mt.set_function("RegistReaderObject",static_cast<void(cocos2d::CSLoader::*)(const std::string&,cocos2d::ObjectFactory::Instance)>(&cocos2d::CSLoader::registReaderObject));
mt.set_function("CreateNodeWithFlatBuffersForSimulator",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersForSimulator));
mt.set_function("NodeWithFlatBuffersForSimulator",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const flatbuffers::NodeTree*)>(&cocos2d::CSLoader::nodeWithFlatBuffersForSimulator));
mt[sol::call_constructor]=sol::constructors<cocos2d::CSLoader()>();
mt["Instance"]=sol::property(&cocos2d::CSLoader::getInstance,[](std::nullptr_t){cocos2d::CSLoader::destroyInstance();});
}
