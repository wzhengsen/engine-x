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
namespace cocos2d{
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
void RegisterLuaCoreDownloadTaskAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::network::DownloadTask).name()] = sol::usertype_traits<cocos2d::network::DownloadTask*>::metatable();
auto dep=lua.new_usertype<cocos2d::network::DownloadTask>("deprecated.cocos2d::network::DownloadTask");
dep[sol::base_classes]=sol::bases<cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::network::DownloadTask*>::metatable(),sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable());
lua["cc"]["DownloadTask"]=mt;
mt["__new__"]=sol::overload([](const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,bool arg4){return new cocos2d::network::DownloadTask(arg0,arg1,arg2,arg3,arg4);},[](const std::string& arg0,const std::string& arg1){return new cocos2d::network::DownloadTask(arg0,arg1);},[](){return new cocos2d::network::DownloadTask();});
mt["Cancel"]=static_cast<void(cocos2d::network::DownloadTask::*)()>(&cocos2d::network::DownloadTask::cancel);
mt["static"]["get"]["ERROR_NO_ERROR"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_NO_ERROR;};
mt["static"]["get"]["ERROR_INVALID_PARAMS"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_INVALID_PARAMS;};
mt["static"]["get"]["ERROR_OPEN_FILE_FAILED"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_OPEN_FILE_FAILED;};
mt["static"]["get"]["ERROR_IMPL_INTERNAL"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_IMPL_INTERNAL;};
mt["static"]["get"]["ERROR_TASK_DUPLICATED"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_TASK_DUPLICATED;};
mt["static"]["get"]["ERROR_CREATE_DIR_FAILED"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_CREATE_DIR_FAILED;};
mt["static"]["get"]["ERROR_REMOVE_FILE_FAILED"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_REMOVE_FILE_FAILED;};
mt["static"]["get"]["ERROR_RENAME_FILE_FAILED"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_RENAME_FILE_FAILED;};
mt["static"]["get"]["ERROR_CHECK_SUM_FAILED"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_CHECK_SUM_FAILED;};
mt["static"]["get"]["ERROR_ORIGIN_FILE_MISSING"]=[]()->const int&{return cocos2d::network::DownloadTask::ERROR_ORIGIN_FILE_MISSING;};
mt["set"]["Identifier"]=[](cocos2d::network::DownloadTask* obj,const std::string& value){obj->identifier = value;};
mt["get"]["Identifier"]=[](cocos2d::network::DownloadTask* obj)->const std::string&{return obj->identifier;};
mt["set"]["RequestURL"]=[](cocos2d::network::DownloadTask* obj,const std::string& value){obj->requestURL = value;};
mt["get"]["RequestURL"]=[](cocos2d::network::DownloadTask* obj)->const std::string&{return obj->requestURL;};
mt["set"]["StoragePath"]=[](cocos2d::network::DownloadTask* obj,const std::string& value){obj->storagePath = value;};
mt["get"]["StoragePath"]=[](cocos2d::network::DownloadTask* obj)->const std::string&{return obj->storagePath;};
mt["set"]["ProgressInfo"]=[](cocos2d::network::DownloadTask* obj,const cocos2d::network::DownloadTask::ProgressInfo& value){obj->progressInfo = value;};
mt["get"]["ProgressInfo"]=[](cocos2d::network::DownloadTask* obj)->const cocos2d::network::DownloadTask::ProgressInfo&{return obj->progressInfo;};
mt["set"]["Checksum"]=[](cocos2d::network::DownloadTask* obj,const std::string& value){obj->checksum = value;};
mt["get"]["Checksum"]=[](cocos2d::network::DownloadTask* obj)->const std::string&{return obj->checksum;};
mt["set"]["Background"]=[](cocos2d::network::DownloadTask* obj,const bool& value){obj->background = value;};
mt["get"]["Background"]=[](cocos2d::network::DownloadTask* obj)->const bool&{return obj->background;};
}
void RegisterLuaCoreDownloaderAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::network::Downloader).name()] = sol::usertype_traits<cocos2d::network::Downloader*>::metatable();
auto dep=lua.new_usertype<cocos2d::network::Downloader>("deprecated.cocos2d::network::Downloader");
dep[sol::base_classes]=sol::bases<cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::network::Downloader*>::metatable(),sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable());
lua["cc"]["Downloader"]=mt;
mt["__new__"]=sol::overload([](const cocos2d::network::DownloaderHints& arg0){return new cocos2d::network::Downloader(arg0);},[](){return new cocos2d::network::Downloader();});
mt["DownloadData"]=sol::overload([](cocos2d::network::Downloader* obj,const std::string& arg0,const std::string& arg1){return obj->createDownloadDataTask(arg0,arg1);},[](cocos2d::network::Downloader* obj,const std::string& arg0){return obj->createDownloadDataTask(arg0);});
mt["DownloadFile"]=sol::overload([](cocos2d::network::Downloader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,bool arg4){return obj->createDownloadFileTask(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::network::Downloader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3){return obj->createDownloadFileTask(arg0,arg1,arg2,arg3);},[](cocos2d::network::Downloader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->createDownloadFileTask(arg0,arg1,arg2);},[](cocos2d::network::Downloader* obj,const std::string& arg0,const std::string& arg1){return obj->createDownloadFileTask(arg0,arg1);});
mt["set"]["OnDataTaskSuccess"]=[](cocos2d::network::Downloader* obj,const std::function<void (const cocos2d::network::DownloadTask *, std::vector<unsigned char, std::allocator<unsigned char> > &)>& value){obj->onDataTaskSuccess = value;};
mt["get"]["OnDataTaskSuccess"]=[](cocos2d::network::Downloader* obj)->const std::function<void (const cocos2d::network::DownloadTask *, std::vector<unsigned char, std::allocator<unsigned char> > &)>&{return obj->onDataTaskSuccess;};
mt["set"]["OnFileTaskSuccess"]=[](cocos2d::network::Downloader* obj,const std::function<void (const cocos2d::network::DownloadTask *)>& value){obj->onFileTaskSuccess = value;};
mt["get"]["OnFileTaskSuccess"]=[](cocos2d::network::Downloader* obj)->const std::function<void (const cocos2d::network::DownloadTask *)>&{return obj->onFileTaskSuccess;};
mt["set"]["OnTaskProgress"]=[](cocos2d::network::Downloader* obj,const std::function<void (const cocos2d::network::DownloadTask *)>& value){obj->onTaskProgress = value;};
mt["get"]["OnTaskProgress"]=[](cocos2d::network::Downloader* obj)->const std::function<void (const cocos2d::network::DownloadTask *)>&{return obj->onTaskProgress;};
mt["set"]["OnTaskError"]=[](cocos2d::network::Downloader* obj,const std::function<void (const cocos2d::network::DownloadTask *, int, int, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>& value){obj->onTaskError = value;};
mt["get"]["OnTaskError"]=[](cocos2d::network::Downloader* obj)->const std::function<void (const cocos2d::network::DownloadTask *, int, int, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>&{return obj->onTaskError;};
}
}
