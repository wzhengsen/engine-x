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
#include "network/CCConnection.h"
void RegisterLuaCoreTMXTileAnimManagerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXTileAnimManager).name()] = sol::usertype_traits<cocos2d::TMXTileAnimManager*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXTileAnimManager>("deprecated.cocos2d::TMXTileAnimManager");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXTileAnimManager*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TMXTileAnimManager"]=mt;
mt["__new__"]=static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create);
mt["StartAll"]=static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll);
mt["StopAll"]=static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll);
mt["GetTasks"]=static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks);
mt["get"]["Tasks"]=mt["GetTasks"];
}
void RegisterLuaCoreFastTMXTiledMapAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FastTMXTiledMap).name()] = sol::usertype_traits<cocos2d::FastTMXTiledMap*>::metatable();
auto dep=lua.new_usertype<cocos2d::FastTMXTiledMap>("deprecated.cocos2d::FastTMXTiledMap");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FastTMXTiledMap*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["FastTMXTiledMap"]=mt;
mt["__new__"]=static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&)>(&cocos2d::FastTMXTiledMap::create);
mt["static"]["CreateWithXML"]=static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::createWithXML);
mt["GetLayer"]=static_cast<cocos2d::FastTMXLayer*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getLayer);
mt["GetObjectGroup"]=static_cast<cocos2d::TMXObjectGroup*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getObjectGroup);
mt["GetProperty"]=static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getProperty);
mt["GetPropertiesForGID"]=static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(int)const>(&cocos2d::FastTMXTiledMap::getPropertiesForGID);
mt["GetMapSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapSize);
mt["get"]["MapSize"]=mt["GetMapSize"];
mt["SetMapSize"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setMapSize);
mt["set"]["MapSize"]=mt["SetMapSize"];
mt["GetTileSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getTileSize);
mt["get"]["TileSize"]=mt["GetTileSize"];
mt["SetTileSize"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setTileSize);
mt["set"]["TileSize"]=mt["SetTileSize"];
mt["GetMapOrientation"]=static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapOrientation);
mt["get"]["MapOrientation"]=mt["GetMapOrientation"];
mt["SetMapOrientation"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(int)>(&cocos2d::FastTMXTiledMap::setMapOrientation);
mt["set"]["MapOrientation"]=mt["SetMapOrientation"];
mt["GetObjectGroups"]=static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getObjectGroups);
mt["get"]["ObjectGroups"]=mt["GetObjectGroups"];
mt["SetObjectGroups"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::FastTMXTiledMap::setObjectGroups);
mt["set"]["ObjectGroups"]=mt["SetObjectGroups"];
mt["GetProperties"]=static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getProperties);
mt["get"]["Properties"]=mt["GetProperties"];
mt["SetProperties"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXTiledMap::setProperties);
mt["set"]["Properties"]=mt["SetProperties"];
mt["SetTileAnimEnabled"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(bool)>(&cocos2d::FastTMXTiledMap::setTileAnimEnabled);
mt["set"]["TileAnimEnabled"]=mt["SetTileAnimEnabled"];
mt["GetLayerCount"]=static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getLayerCount);
mt["get"]["LayerCount"]=mt["GetLayerCount"];
mt["GetResourceFile"]=static_cast<const std::string&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getResourceFile);
mt["get"]["ResourceFile"]=mt["GetResourceFile"];
}
void RegisterLuaCoreConnectionKindAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["TCP"]=cocos2d::network::Connection::Kind::TCP;
enumTable["UDP"]=cocos2d::network::Connection::Kind::UDP;
enumTable["KCP"]=cocos2d::network::Connection::Kind::KCP;
lua["cc"]["Connection"]["static"]["Kind"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreConnectionAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::network::Connection).name()] = sol::usertype_traits<cocos2d::network::Connection*>::metatable();
auto dep=lua.new_usertype<cocos2d::network::Connection>("deprecated.cocos2d::network::Connection");
dep[sol::base_classes]=sol::bases<cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::network::Connection*>::metatable(),sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable());
lua["cc"]["Connection"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["Open"]=static_cast<void(cocos2d::network::Connection::*)()>(&cocos2d::network::Connection::Open);
mt["Close"]=static_cast<void(cocos2d::network::Connection::*)()>(&cocos2d::network::Connection::Close);
mt["Write"]=static_cast<int(cocos2d::network::Connection::*)(const std::string&)>(&cocos2d::network::Connection::Write);
mt["SetHeartBeat"]=sol::overload([](cocos2d::network::Connection* obj,size_t arg0,size_t arg1){return obj->SetHeartBeat(arg0,arg1);},[](cocos2d::network::Connection* obj,size_t arg0){return obj->SetHeartBeat(arg0);},[](cocos2d::network::Connection* obj){return obj->SetHeartBeat();});
mt["set"]["HeartBeat"]=mt["SetHeartBeat"];
RegisterLuaCoreConnectionKindAuto(lua);
}
void RegisterLuaCoreServerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::network::Server).name()] = sol::usertype_traits<cocos2d::network::Server*>::metatable();
auto dep=lua.new_usertype<cocos2d::network::Server>("deprecated.cocos2d::network::Server");
dep[sol::base_classes]=sol::bases<cocos2d::network::Connection,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::network::Server*>::metatable(),sol::usertype_traits<cocos2d::network::Connection*>::metatable());
lua["cc"]["Server"]=mt;
mt["__new__"]=sol::overload([](const std::string_view& arg0,uint16_t arg1,cocos2d::network::Connection::Kind arg2){return new cocos2d::network::Server(arg0,arg1,arg2);},[](uint16_t arg0,cocos2d::network::Connection::Kind arg1){return new cocos2d::network::Server(arg0,arg1);},[](const std::string_view& arg0,uint16_t arg1){return new cocos2d::network::Server(arg0,arg1);},[](uint16_t arg0){return new cocos2d::network::Server(arg0);});
mt["SetConnectHandler"]=static_cast<void(cocos2d::network::Server::*)(const cocos2d::network::Server::SC_Handler&)>(&cocos2d::network::Server::SetConnectHandler);
mt["set"]["ConnectHandler"]=mt["SetConnectHandler"];
mt["SetMessageHandler"]=static_cast<void(cocos2d::network::Server::*)(const cocos2d::network::Server::SM_Handler&)>(&cocos2d::network::Server::SetMessageHandler);
mt["set"]["MessageHandler"]=mt["SetMessageHandler"];
mt["SetLoseHandler"]=static_cast<void(cocos2d::network::Server::*)(const cocos2d::network::Server::SL_Handler&)>(&cocos2d::network::Server::SetLoseHandler);
mt["set"]["LoseHandler"]=mt["SetLoseHandler"];
mt["Write"]=sol::overload(static_cast<int(cocos2d::network::Server::*)(yasio::inet::transport_handle_t,const std::string&)>(&cocos2d::network::Server::Write),static_cast<int(cocos2d::network::Server::*)(const std::string&)>(&cocos2d::network::Server::Write));
mt["Close"]=static_cast<void(cocos2d::network::Server::*)(yasio::inet::transport_handle_t)>(&cocos2d::network::Server::Close);
}
void RegisterLuaCoreClientAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::network::Client).name()] = sol::usertype_traits<cocos2d::network::Client*>::metatable();
auto dep=lua.new_usertype<cocos2d::network::Client>("deprecated.cocos2d::network::Client");
dep[sol::base_classes]=sol::bases<cocos2d::network::Connection,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::network::Client*>::metatable(),sol::usertype_traits<cocos2d::network::Connection*>::metatable());
lua["cc"]["Client"]=mt;
mt["__new__"]=sol::overload([](const std::string_view& arg0,uint16_t arg1,cocos2d::network::Connection::Kind arg2){return new cocos2d::network::Client(arg0,arg1,arg2);},[](const std::string_view& arg0,uint16_t arg1){return new cocos2d::network::Client(arg0,arg1);});
mt["SetConnectHandler"]=static_cast<void(cocos2d::network::Client::*)(const cocos2d::network::Client::CC_Handler&)>(&cocos2d::network::Client::SetConnectHandler);
mt["set"]["ConnectHandler"]=mt["SetConnectHandler"];
mt["SetMessageHandler"]=static_cast<void(cocos2d::network::Client::*)(const cocos2d::network::Client::CM_Handler&)>(&cocos2d::network::Client::SetMessageHandler);
mt["set"]["MessageHandler"]=mt["SetMessageHandler"];
mt["SetLoseHandler"]=static_cast<void(cocos2d::network::Client::*)(const cocos2d::network::Client::CL_Handler&)>(&cocos2d::network::Client::SetLoseHandler);
mt["set"]["LoseHandler"]=mt["SetLoseHandler"];
mt["Open"]=sol::overload(static_cast<void(cocos2d::network::Client::*)(size_t)>(&cocos2d::network::Client::Open),static_cast<void(cocos2d::network::Client::*)()>(&cocos2d::network::Client::Open));
}
