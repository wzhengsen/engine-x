#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
void RegisterLuaCSLoaderCSLoaderAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::CSLoader).name()] = sol::usertype_traits<cocos2d::CSLoader*>::metatable();
auto dep=lua.new_usertype<cocos2d::CSLoader>("deprecated.cocos2d::CSLoader");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::CSLoader*>::metatable());
lua["cc"]["CSLoader"]=mt;
mt["static"]["GetInstance"]=static_cast<cocos2d::CSLoader*(*)()>(&cocos2d::CSLoader::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocos2d::CSLoader::destroyInstance);
mt["Init"]=static_cast<void(cocos2d::CSLoader::*)()>(&cocos2d::CSLoader::init);
mt["static"]["CreateNode"]=sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const cocos2d::Size&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const cocos2d::Data&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const std::string&,const cocos2d::Size&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const std::string&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const cocos2d::Data&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNode));
mt["static"]["CreateNodeWithVisibleSize"]=sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const cocos2d::ccNodeLoadCallback&)>(&cocos2d::CSLoader::createNodeWithVisibleSize),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithVisibleSize));
mt["static"]["CreateTimeline"]=sol::overload(static_cast<cocostudio::timeline::ActionTimeline*(*)(const cocos2d::Data&,const std::string&)>(&cocos2d::CSLoader::createTimeline),static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocos2d::CSLoader::createTimeline));
mt["CreateNodeFromJson"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeFromJson);
mt["LoadNodeWithFile"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithFile);
mt["LoadNodeWithContent"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithContent);
mt["SetRecordJsonPath"]=static_cast<void(cocos2d::CSLoader::*)(bool)>(&cocos2d::CSLoader::setRecordJsonPath);
mt["set"]["RecordJsonPath"]=mt["SetRecordJsonPath"];
mt["IsRecordJsonPath"]=static_cast<bool(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::isRecordJsonPath);
mt["get"]["RecordJsonPath"]=mt["IsRecordJsonPath"];
mt["SetJsonPath"]=static_cast<void(cocos2d::CSLoader::*)(std::string)>(&cocos2d::CSLoader::setJsonPath);
mt["set"]["JsonPath"]=mt["SetJsonPath"];
mt["GetJsonPath"]=static_cast<std::string(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::getJsonPath);
mt["get"]["JsonPath"]=mt["GetJsonPath"];
mt["CreateNodeWithFlatBuffersFile"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersFile);
mt["NodeWithFlatBuffersFile"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::nodeWithFlatBuffersFile);
mt["NodeWithFlatBuffers"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const flatbuffers::NodeTree*)>(&cocos2d::CSLoader::nodeWithFlatBuffers);
mt["BindCallback"]=static_cast<bool(cocos2d::CSLoader::*)(const std::string&,const std::string&,cocos2d::ui::Widget*,cocos2d::Node*)>(&cocos2d::CSLoader::bindCallback);
mt["RegistReaderObject"]=static_cast<void(cocos2d::CSLoader::*)(const std::string&,cocos2d::ObjectFactory::Instance)>(&cocos2d::CSLoader::registReaderObject);
mt["CreateNodeWithFlatBuffersForSimulator"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersForSimulator);
mt["NodeWithFlatBuffersForSimulator"]=static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const flatbuffers::NodeTree*)>(&cocos2d::CSLoader::nodeWithFlatBuffersForSimulator);
mt["static"]["get"]["Instance"]=&cocos2d::CSLoader::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocos2d::CSLoader::destroyInstance();};
}
