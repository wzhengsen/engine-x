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
void RegisterLuaCoreRefAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Ref>("cc","Ref",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::extension::LuaObject>());
mt.set_function("Retain",static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::retain));
mt.set_function("Release",static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::release));
mt.set_function("Autorelease",static_cast<cocos2d::Ref*(cocos2d::Ref::*)()>(&cocos2d::Ref::autorelease));
mt.set_function("GetReferenceCount",static_cast<unsigned int(cocos2d::Ref::*)()const>(&cocos2d::Ref::getReferenceCount));
}
void RegisterLuaCoreConsoleAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Console>("cc","Console",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("ListenOnTCP",static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnTCP));
mt.set_function("ListenOnFileDescriptor",static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnFileDescriptor));
mt.set_function("Stop",static_cast<void(cocos2d::Console::*)()>(&cocos2d::Console::stop));
mt.set_function("AddCommand",static_cast<void(cocos2d::Console::*)(const cocos2d::Console::Command&)>(&cocos2d::Console::addCommand));
mt.set_function("AddSubCommand",sol::overload(static_cast<void(cocos2d::Console::*)(cocos2d::Console::Command&,const cocos2d::Console::Command&)>(&cocos2d::Console::addSubCommand),static_cast<void(cocos2d::Console::*)(const std::string&,const cocos2d::Console::Command&)>(&cocos2d::Console::addSubCommand)));
mt.set_function("GetCommand",static_cast<const cocos2d::Console::Command*(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::getCommand));
mt.set_function("GetSubCommand",sol::overload(static_cast<const cocos2d::Console::Command*(cocos2d::Console::*)(const cocos2d::Console::Command&,const std::string&)>(&cocos2d::Console::getSubCommand),static_cast<const cocos2d::Console::Command*(cocos2d::Console::*)(const std::string&,const std::string&)>(&cocos2d::Console::getSubCommand)));
mt.set_function("DelCommand",static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::delCommand));
mt.set_function("DelSubCommand",sol::overload(static_cast<void(cocos2d::Console::*)(cocos2d::Console::Command&,const std::string&)>(&cocos2d::Console::delSubCommand),static_cast<void(cocos2d::Console::*)(const std::string&,const std::string&)>(&cocos2d::Console::delSubCommand)));
mt.set_function("Log",static_cast<void(cocos2d::Console::*)(const char*)>(&cocos2d::Console::log));
mt.set_function("SetBindAddress",static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::setBindAddress));
mt.set_function("IsIpv6Server",static_cast<bool(cocos2d::Console::*)()const>(&cocos2d::Console::isIpv6Server));
mt.set_function("GetCommandSeparator",static_cast<char(cocos2d::Console::*)()const>(&cocos2d::Console::getCommandSeparator));
mt.set_function("SetCommandSeparator",static_cast<void(cocos2d::Console::*)(char)>(&cocos2d::Console::setCommandSeparator));
mt[sol::call_constructor]=sol::constructors<cocos2d::Console()>();
}
void RegisterLuaCoreTextVAlignmentAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::TextVAlignment>("TextVAlignment",{
{"TOP",cocos2d::TextVAlignment::TOP}
,{"CENTER",cocos2d::TextVAlignment::CENTER}
,{"BOTTOM",cocos2d::TextVAlignment::BOTTOM}
});}
void RegisterLuaCoreTextHAlignmentAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::TextHAlignment>("TextHAlignment",{
{"LEFT",cocos2d::TextHAlignment::LEFT}
,{"CENTER",cocos2d::TextHAlignment::CENTER}
,{"RIGHT",cocos2d::TextHAlignment::RIGHT}
});}
void RegisterLuaCoreGlyphCollectionAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::GlyphCollection>("GlyphCollection",{
{"DYNAMIC",cocos2d::GlyphCollection::DYNAMIC}
,{"NEHE",cocos2d::GlyphCollection::NEHE}
,{"ASCII",cocos2d::GlyphCollection::ASCII}
,{"CUSTOM",cocos2d::GlyphCollection::CUSTOM}
});}
void RegisterLuaCoreLabelEffectAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::LabelEffect>("LabelEffect",{
{"NORMAL",cocos2d::LabelEffect::NORMAL}
,{"OUTLINE",cocos2d::LabelEffect::OUTLINE}
,{"SHADOW",cocos2d::LabelEffect::SHADOW}
,{"GLOW",cocos2d::LabelEffect::GLOW}
,{"ITALICS",cocos2d::LabelEffect::ITALICS}
,{"BOLD",cocos2d::LabelEffect::BOLD}
,{"UNDERLINE",cocos2d::LabelEffect::UNDERLINE}
,{"STRIKETHROUGH",cocos2d::LabelEffect::STRIKETHROUGH}
,{"ALL",cocos2d::LabelEffect::ALL}
});}
void RegisterLuaCoreEventListenerTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventListener"];
pTable.new_enum<cocos2d::EventListener::Type>("Type",{
{"UNKNOWN",cocos2d::EventListener::Type::UNKNOWN}
,{"TOUCH_ONE_BY_ONE",cocos2d::EventListener::Type::TOUCH_ONE_BY_ONE}
,{"TOUCH_ALL_AT_ONCE",cocos2d::EventListener::Type::TOUCH_ALL_AT_ONCE}
,{"KEYBOARD",cocos2d::EventListener::Type::KEYBOARD}
,{"MOUSE",cocos2d::EventListener::Type::MOUSE}
,{"ACCELERATION",cocos2d::EventListener::Type::ACCELERATION}
,{"FOCUS",cocos2d::EventListener::Type::FOCUS}
,{"GAME_CONTROLLER",cocos2d::EventListener::Type::GAME_CONTROLLER}
,{"CUSTOM",cocos2d::EventListener::Type::CUSTOM}
});}
void RegisterLuaCoreEventListenerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListener>("cc","EventListener",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListener::*)()>(&cocos2d::EventListener::checkAvailable));
mt.set_function("Clone",static_cast<cocos2d::EventListener*(cocos2d::EventListener::*)()>(&cocos2d::EventListener::clone));
mt.set_function("SetEnabled",static_cast<void(cocos2d::EventListener::*)(bool)>(&cocos2d::EventListener::setEnabled));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::EventListener::*)()const>(&cocos2d::EventListener::isEnabled));
RegisterLuaCoreEventListenerTypeAuto(lua);
}
void RegisterLuaCoreEventListenerCustomAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventListenerCustom>("cc","EventListenerCustom",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::EventListenerCustom*(*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventListenerCustom::create));
mt.set_function("CheckAvailable",static_cast<bool(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::checkAvailable));
mt.set_function("Clone",static_cast<cocos2d::EventListenerCustom*(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::clone));
}
void RegisterLuaCoreTexture2DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Texture2D>("cc","Texture2D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetDefaultAlphaPixelFormat",static_cast<void(*)(cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::setDefaultAlphaPixelFormat));
mt.set_function("GetDefaultAlphaPixelFormat",static_cast<cocos2d::backend::PixelFormat(*)()>(&cocos2d::Texture2D::getDefaultAlphaPixelFormat));
mt.set_function("InitWithData",sol::overload([](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,int arg3,int arg4,const cocos2d::Size& arg5){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,int arg3,int arg4,const cocos2d::Size& arg5,bool arg6){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("InitWithMipmaps",sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->initWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->initWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("UpdateWithImage",sol::overload([](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1){return obj->updateWithImage(arg0,arg1);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2){return obj->updateWithImage(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2,int arg3){return obj->updateWithImage(arg0,arg1,arg2,arg3);}));
mt.set_function("UpdateWithData",sol::overload([](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7){return obj->updateWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7,int arg8){return obj->updateWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);}));
mt.set_function("UpdateWithMipmaps",sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6,int arg7){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}));
mt.set_function("UpdateWithSubData",sol::overload([](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4,int arg5){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("DrawAtPoint",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Vec2&,float)>(&cocos2d::Texture2D::drawAtPoint));
mt.set_function("DrawInRect",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Rect&,float)>(&cocos2d::Texture2D::drawInRect));
mt.set_function("InitWithImage",sol::overload(static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*,cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::initWithImage),static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*)>(&cocos2d::Texture2D::initWithImage)));
mt.set_function("InitWithString",sol::overload(static_cast<bool(cocos2d::Texture2D::*)(const char*,const cocos2d::FontDefinition&)>(&cocos2d::Texture2D::initWithString),[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2){return obj->initWithString(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithString(arg0,arg1,arg2,arg3);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithString(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6,int arg7){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);}));
mt.set_function("UpdateTextureDescriptor",sol::overload([](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0,bool arg1){return obj->updateTextureDescriptor(arg0,arg1);}));
mt.set_function("SetRenderTarget",static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setRenderTarget));
mt.set_function("IsRenderTarget",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::isRenderTarget));
mt.set_function("SetTexParameters",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::Texture2D::setTexParameters));
mt.set_function("GenerateMipmap",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::generateMipmap));
mt.set_function("SetAntiAliasTexParameters",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAntiAliasTexParameters));
mt.set_function("SetAliasTexParameters",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAliasTexParameters));
mt.set_function("GetStringForFormat",static_cast<const char*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getStringForFormat));
mt.set_function("GetBitsPerPixelForFormat",sol::overload(static_cast<unsigned int(cocos2d::Texture2D::*)(cocos2d::backend::PixelFormat)const>(&cocos2d::Texture2D::getBitsPerPixelForFormat),static_cast<unsigned int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBitsPerPixelForFormat)));
mt.set_function("GetContentSizeInPixels",static_cast<const cocos2d::Size&(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::getContentSizeInPixels));
mt.set_function("HasPremultipliedAlpha",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasPremultipliedAlpha));
mt.set_function("SetPremultipliedAlpha",static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setPremultipliedAlpha));
mt.set_function("HasMipmaps",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasMipmaps));
mt.set_function("GetPixelFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelFormat));
mt.set_function("GetTextureFormatEXT",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getTextureFormatEXT));
mt.set_function("GetPixelsWide",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsWide));
mt.set_function("GetPixelsHigh",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsHigh));
mt.set_function("GetBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBackendTexture));
mt.set_function("GetMaxS",static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxS));
mt.set_function("SetMaxS",static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxS));
mt.set_function("GetMaxT",static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxT));
mt.set_function("SetMaxT",static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxT));
mt.set_function("GetContentSize",static_cast<cocos2d::Size(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getContentSize));
mt.set_function("GetPath",static_cast<std::string(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPath));
mt[sol::call_constructor]=sol::constructors<cocos2d::Texture2D()>();
}
void RegisterLuaCoreLabelProtocolAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::LabelProtocol>("cc","LabelProtocol",true);
mt.set_function("SetString",static_cast<void(cocos2d::LabelProtocol::*)(const std::string&)>(&cocos2d::LabelProtocol::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::LabelProtocol::*)()const>(&cocos2d::LabelProtocol::getString));
}
