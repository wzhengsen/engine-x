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
void RegisterLuaCoreRefAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Ref,cocos2d::LuaObject>("Ref",true);
ns["Ref"] = mt;
lua["Ref"] = sol::nil;
mt.set_function("retain",static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::retain));
mt.set_function("release",static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::release));
mt.set_function("autorelease",static_cast<cocos2d::Ref*(cocos2d::Ref::*)()>(&cocos2d::Ref::autorelease));
mt.set_function("getReferenceCount",static_cast<unsigned int(cocos2d::Ref::*)()const>(&cocos2d::Ref::getReferenceCount));
}
void RegisterLuaCoreConsoleUtilityAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Console::Utility>("Utility",true);
ns = ns["Console"];
ns["Utility"] = mt;
lua["Utility"] = sol::nil;
mt.set_function("ltrim",static_cast<std::string&(*)(std::string&)>(&cocos2d::Console::Utility::ltrim));
mt.set_function("rtrim",static_cast<std::string&(*)(std::string&)>(&cocos2d::Console::Utility::rtrim));
mt.set_function("trim",static_cast<std::string&(*)(std::string&)>(&cocos2d::Console::Utility::trim));
mt.set_function("split",sol::overload(static_cast<std::vector<std::string>(*)(const std::string&,char)>(&cocos2d::Console::Utility::split),static_cast<std::vector<std::string>&(*)(const std::string&,char,std::vector<std::string>&)>(&cocos2d::Console::Utility::split)));
mt.set_function("isFloat",static_cast<bool(*)(const std::string&)>(&cocos2d::Console::Utility::isFloat));
mt.set_function("sendToConsole",sol::overload([](cocos2d::Console::Utility* obj,int arg0,const void* arg1,size_t arg2){return obj->sendToConsole(arg0,arg1,arg2);},[](cocos2d::Console::Utility* obj,int arg0,const void* arg1,size_t arg2,int arg3){return obj->sendToConsole(arg0,arg1,arg2,arg3);}));
mt.set_function("sendPrompt",static_cast<void(*)(int)>(&cocos2d::Console::Utility::sendPrompt));
mt.set_function("setPrompt",static_cast<void(*)(const std::string&)>(&cocos2d::Console::Utility::setPrompt));
mt.set_function("getPrompt",static_cast<const std::string&(*)()>(&cocos2d::Console::Utility::getPrompt));
}
void RegisterLuaCoreConsoleCommandAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Console::Command>("Command",true);
ns = ns["Console"];
ns["Command"] = mt;
lua["Command"] = sol::nil;
mt.set_function("operator=",static_cast<cocos2d::Console::Command&(cocos2d::Console::Command::*)(const cocos2d::Console::Command&)>(&cocos2d::Console::Command::operator=));
mt.set_function("addCallback",static_cast<void(cocos2d::Console::Command::*)(const std::function<void (int, const std::string&)>&)>(&cocos2d::Console::Command::addCallback));
mt.set_function("addSubCommand",static_cast<void(cocos2d::Console::Command::*)(const cocos2d::Console::Command&)>(&cocos2d::Console::Command::addSubCommand));
mt.set_function("getSubCommand",static_cast<const cocos2d::Console::Command*(cocos2d::Console::Command::*)(const std::string&)const>(&cocos2d::Console::Command::getSubCommand));
mt.set_function("delSubCommand",static_cast<void(cocos2d::Console::Command::*)(const std::string&)>(&cocos2d::Console::Command::delSubCommand));
mt.set_function("commandHelp",static_cast<void(cocos2d::Console::Command::*)(int,const std::string&)>(&cocos2d::Console::Command::commandHelp));
mt.set_function("commandGeneric",static_cast<void(cocos2d::Console::Command::*)(int,const std::string&)>(&cocos2d::Console::Command::commandGeneric));
mt.set_function("getName",static_cast<const std::string&(cocos2d::Console::Command::*)()const>(&cocos2d::Console::Command::getName));
mt.set_function("getHelp",static_cast<const std::string&(cocos2d::Console::Command::*)()const>(&cocos2d::Console::Command::getHelp));
}
void RegisterLuaCoreConsoleAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Console,cocos2d::Ref,cocos2d::LuaObject>("Console",true);
ns["Console"] = mt;
lua["Console"] = sol::nil;
mt.set_function("listenOnTCP",static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnTCP));
mt.set_function("listenOnFileDescriptor",static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnFileDescriptor));
mt.set_function("stop",static_cast<void(cocos2d::Console::*)()>(&cocos2d::Console::stop));
mt.set_function("addCommand",static_cast<void(cocos2d::Console::*)(const cocos2d::Console::Command&)>(&cocos2d::Console::addCommand));
mt.set_function("addSubCommand",sol::overload(static_cast<void(cocos2d::Console::*)(cocos2d::Console::Command&,const cocos2d::Console::Command&)>(&cocos2d::Console::addSubCommand),static_cast<void(cocos2d::Console::*)(const std::string&,const cocos2d::Console::Command&)>(&cocos2d::Console::addSubCommand)));
mt.set_function("getCommand",static_cast<const cocos2d::Console::Command*(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::getCommand));
mt.set_function("getSubCommand",sol::overload(static_cast<const cocos2d::Console::Command*(cocos2d::Console::*)(const cocos2d::Console::Command&,const std::string&)>(&cocos2d::Console::getSubCommand),static_cast<const cocos2d::Console::Command*(cocos2d::Console::*)(const std::string&,const std::string&)>(&cocos2d::Console::getSubCommand)));
mt.set_function("delCommand",static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::delCommand));
mt.set_function("delSubCommand",sol::overload(static_cast<void(cocos2d::Console::*)(cocos2d::Console::Command&,const std::string&)>(&cocos2d::Console::delSubCommand),static_cast<void(cocos2d::Console::*)(const std::string&,const std::string&)>(&cocos2d::Console::delSubCommand)));
mt.set_function("log",static_cast<void(cocos2d::Console::*)(const char*)>(&cocos2d::Console::log));
mt.set_function("setBindAddress",static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::setBindAddress));
mt.set_function("isIpv6Server",static_cast<bool(cocos2d::Console::*)()const>(&cocos2d::Console::isIpv6Server));
mt.set_function("getCommandSeparator",static_cast<char(cocos2d::Console::*)()const>(&cocos2d::Console::getCommandSeparator));
mt.set_function("setCommandSeparator",static_cast<void(cocos2d::Console::*)(char)>(&cocos2d::Console::setCommandSeparator));
RegisterLuaCoreConsoleUtilityAuto(lua);
RegisterLuaCoreConsoleCommandAuto(lua);
}
void RegisterLuaCorebackendProgramTypeAnonymousEnum__6956807042943340246_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["backend"];
pTable = pTable["ProgramType"];
pTable["POSITION_COLOR_LENGTH_TEXTURE"] = 0;
pTable["POSITION_COLOR_TEXTURE_AS_POINTSIZE"] = 1;
pTable["POSITION_COLOR"] = 2;
pTable["POSITION_UCOLOR"] = 3;
pTable["POSITION_TEXTURE"] = 4;
pTable["POSITION_TEXTURE_COLOR"] = 5;
pTable["POSITION_TEXTURE_COLOR_ALPHA_TEST"] = 6;
pTable["LABEL_NORMAL"] = 7;
pTable["LABLE_OUTLINE"] = 8;
pTable["LABLE_DISTANCEFIELD_GLOW"] = 9;
pTable["LABEL_DISTANCE_NORMAL"] = 10;
pTable["LAYER_RADIA_GRADIENT"] = 11;
pTable["ETC1"] = 12;
pTable["ETC1_GRAY"] = 13;
pTable["GRAY_SCALE"] = 14;
pTable["CAMERA_CLEAR"] = 15;
pTable["TERRAIN_3D"] = 16;
pTable["LINE_COLOR_3D"] = 17;
pTable["SKYBOX_3D"] = 18;
pTable["SKINPOSITION_TEXTURE_3D"] = 19;
pTable["SKINPOSITION_NORMAL_TEXTURE_3D"] = 20;
pTable["POSITION_NORMAL_TEXTURE_3D"] = 21;
pTable["POSITION_NORMAL_3D"] = 22;
pTable["POSITION_TEXTURE_3D"] = 23;
pTable["POSITION_3D"] = 24;
pTable["POSITION_BUMPEDNORMAL_TEXTURE_3D"] = 25;
pTable["SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D"] = 26;
pTable["PARTICLE_TEXTURE_3D"] = 27;
pTable["PARTICLE_COLOR_3D"] = 28;
pTable["HSV"] = 29;
pTable["HSV_ETC1"] = 30;
pTable["BUILTIN_COUNT"] = 31;
pTable["CUSTOM_PROGRAM"] = 4096;
}
void RegisterLuaCoreTextureFormatEXTAnonymousEnum_1115752373665206590_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFormatEXT"];
pTable["NONE"] = 0;
pTable["ETC1_ALPHA"] = 1;
}
void RegisterLuaCoreTextureFlagAnonymousEnum__7597419615267980143_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFlag"];
pTable["NONE"] = 0;
pTable["ANTIALIAS_ENABLED"] = 65536;
pTable["PREMULTIPLIEDALPHA"] = 131072;
pTable["RENDERTARGET"] = 262144;
}
void RegisterLuaCoreEventListenerTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventListener"];
pTable.new_enum("Type"
,"UNKNOWN",0
,"TOUCH_ONE_BY_ONE",1
,"TOUCH_ALL_AT_ONCE",2
,"KEYBOARD",3
,"MOUSE",4
,"ACCELERATION",5
,"FOCUS",6
,"GAME_CONTROLLER",7
,"CUSTOM",8
);}
void RegisterLuaCoreEventListenerAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListener",true);
ns["EventListener"] = mt;
lua["EventListener"] = sol::nil;
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListener::*)()>(&cocos2d::EventListener::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListener*(cocos2d::EventListener::*)()>(&cocos2d::EventListener::clone));
mt.set_function("setEnabled",static_cast<void(cocos2d::EventListener::*)(bool)>(&cocos2d::EventListener::setEnabled));
mt.set_function("isEnabled",static_cast<bool(cocos2d::EventListener::*)()const>(&cocos2d::EventListener::isEnabled));
RegisterLuaCoreEventListenerTypeAuto(lua);
}
void RegisterLuaCoreEventListenerCustomAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("EventListenerCustom",false);
ns["EventListenerCustom"] = mt;
lua["EventListenerCustom"] = sol::nil;
mt.set_function("checkAvailable",static_cast<bool(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::checkAvailable));
mt.set_function("clone",static_cast<cocos2d::EventListenerCustom*(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerCustom*(*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventListenerCustom::create));
}
void RegisterLuaCoreTexture2DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Texture2D,cocos2d::Ref,cocos2d::LuaObject>("Texture2D",true);
ns["Texture2D"] = mt;
lua["Texture2D"] = sol::nil;
mt.set_function("initWithData",sol::overload([](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,int arg3,int arg4,const cocos2d::Size& arg5){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,int arg3,int arg4,const cocos2d::Size& arg5,bool arg6){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("initWithMipmaps",sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->initWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->initWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("updateWithImage",sol::overload([](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1){return obj->updateWithImage(arg0,arg1);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2){return obj->updateWithImage(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2,int arg3){return obj->updateWithImage(arg0,arg1,arg2,arg3);}));
mt.set_function("updateWithData",sol::overload([](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7){return obj->updateWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7,int arg8){return obj->updateWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);}));
mt.set_function("updateWithMipmaps",sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6,int arg7){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}));
mt.set_function("updateWithSubData",sol::overload([](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4,int arg5){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("drawAtPoint",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Vec2&,float)>(&cocos2d::Texture2D::drawAtPoint));
mt.set_function("drawInRect",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Rect&,float)>(&cocos2d::Texture2D::drawInRect));
mt.set_function("initWithImage",sol::overload(static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*,cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::initWithImage),static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*)>(&cocos2d::Texture2D::initWithImage)));
mt.set_function("initWithString",sol::overload(static_cast<bool(cocos2d::Texture2D::*)(const char*,const cocos2d::FontDefinition&)>(&cocos2d::Texture2D::initWithString),[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2){return obj->initWithString(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithString(arg0,arg1,arg2,arg3);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithString(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6,int arg7){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}));
mt.set_function("updateTextureDescriptor",sol::overload([](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0,bool arg1){return obj->updateTextureDescriptor(arg0,arg1);}));
mt.set_function("setRenderTarget",static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setRenderTarget));
mt.set_function("isRenderTarget",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::isRenderTarget));
mt.set_function("setTexParameters",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::Texture2D::setTexParameters));
mt.set_function("generateMipmap",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::generateMipmap));
mt.set_function("setAntiAliasTexParameters",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAntiAliasTexParameters));
mt.set_function("setAliasTexParameters",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAliasTexParameters));
mt.set_function("getStringForFormat",static_cast<const char*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getStringForFormat));
mt.set_function("getBitsPerPixelForFormat",sol::overload(static_cast<unsigned int(cocos2d::Texture2D::*)(cocos2d::backend::PixelFormat)const>(&cocos2d::Texture2D::getBitsPerPixelForFormat),static_cast<unsigned int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBitsPerPixelForFormat)));
mt.set_function("getContentSizeInPixels",static_cast<const cocos2d::Size&(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::getContentSizeInPixels));
mt.set_function("hasPremultipliedAlpha",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasPremultipliedAlpha));
mt.set_function("setPremultipliedAlpha",static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setPremultipliedAlpha));
mt.set_function("hasMipmaps",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasMipmaps));
mt.set_function("getPixelFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelFormat));
mt.set_function("getTextureFormatEXT",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getTextureFormatEXT));
mt.set_function("getPixelsWide",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsWide));
mt.set_function("getPixelsHigh",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsHigh));
mt.set_function("getBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBackendTexture));
mt.set_function("getMaxS",static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxS));
mt.set_function("setMaxS",static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxS));
mt.set_function("getMaxT",static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxT));
mt.set_function("setMaxT",static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxT));
mt.set_function("getContentSize",static_cast<cocos2d::Size(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getContentSize));
mt.set_function("getPath",static_cast<std::string(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPath));
mt.set_function("setDefaultAlphaPixelFormat",static_cast<void(*)(cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::setDefaultAlphaPixelFormat));
mt.set_function("getDefaultAlphaPixelFormat",static_cast<cocos2d::backend::PixelFormat(*)()>(&cocos2d::Texture2D::getDefaultAlphaPixelFormat));
}
void RegisterLuaCoreLabelProtocolAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::LabelProtocol>("LabelProtocol",true);
ns["LabelProtocol"] = mt;
lua["LabelProtocol"] = sol::nil;
mt.set_function("setString",static_cast<void(cocos2d::LabelProtocol::*)(const std::string&)>(&cocos2d::LabelProtocol::setString));
mt.set_function("getString",static_cast<const std::string&(cocos2d::LabelProtocol::*)()const>(&cocos2d::LabelProtocol::getString));
}
void RegisterLuaCoreComponentAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("Component",false);
ns["Component"] = mt;
lua["Component"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::Component::*)()>(&cocos2d::Component::init));
mt.set_function("isEnabled",static_cast<bool(cocos2d::Component::*)()const>(&cocos2d::Component::isEnabled));
mt.set_function("setEnabled",static_cast<void(cocos2d::Component::*)(bool)>(&cocos2d::Component::setEnabled));
mt.set_function("getName",static_cast<const std::string&(cocos2d::Component::*)()const>(&cocos2d::Component::getName));
mt.set_function("setName",static_cast<void(cocos2d::Component::*)(const std::string&)>(&cocos2d::Component::setName));
mt.set_function("getOwner",static_cast<cocos2d::Node*(cocos2d::Component::*)()const>(&cocos2d::Component::getOwner));
mt.set_function("setOwner",static_cast<void(cocos2d::Component::*)(cocos2d::Node*)>(&cocos2d::Component::setOwner));
mt.set_function("update",static_cast<void(cocos2d::Component::*)(float)>(&cocos2d::Component::update));
mt.set_function("serialize",static_cast<bool(cocos2d::Component::*)(void*)>(&cocos2d::Component::serialize));
mt.set_function("onEnter",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onExit));
mt.set_function("onAdd",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onAdd));
mt.set_function("onRemove",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onRemove));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Component*(*)()>(&cocos2d::Component::create));
}
