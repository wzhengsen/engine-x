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
void RegisterLuaCoreClonableAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Clonable).name()] = sol::usertype_traits<cocos2d::Clonable*>::metatable();
auto dep=lua.new_usertype<cocos2d::Clonable>("deprecated.cocos2d::Clonable");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Clonable*>::metatable());
lua["cc"]["Clonable"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["Clone"]=static_cast<cocos2d::Clonable*(cocos2d::Clonable::*)()const>(&cocos2d::Clonable::clone);
}
void RegisterLuaCoreRefAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Ref).name()] = sol::usertype_traits<cocos2d::Ref*>::metatable();
auto dep=lua.new_usertype<cocos2d::Ref>("deprecated.cocos2d::Ref");
dep[sol::base_classes]=sol::bases<cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::extension::LuaObject*>::metatable());
lua["cc"]["Ref"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["Retain"]=static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::retain);
mt["Release"]=static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::release);
mt["Autorelease"]=static_cast<cocos2d::Ref*(cocos2d::Ref::*)()>(&cocos2d::Ref::autorelease);
mt["GetReferenceCount"]=static_cast<unsigned int(cocos2d::Ref::*)()const>(&cocos2d::Ref::getReferenceCount);
mt["get"]["ReferenceCount"]=mt["GetReferenceCount"];
}
void RegisterLuaCoreTextVAlignmentAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["TOP"]=cocos2d::TextVAlignment::TOP;
enumTable["CENTER"]=cocos2d::TextVAlignment::CENTER;
enumTable["BOTTOM"]=cocos2d::TextVAlignment::BOTTOM;
lua["cc"]["TextVAlignment"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreTextHAlignmentAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["LEFT"]=cocos2d::TextHAlignment::LEFT;
enumTable["CENTER"]=cocos2d::TextHAlignment::CENTER;
enumTable["RIGHT"]=cocos2d::TextHAlignment::RIGHT;
lua["cc"]["TextHAlignment"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreGlyphCollectionAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["DYNAMIC"]=cocos2d::GlyphCollection::DYNAMIC;
enumTable["NEHE"]=cocos2d::GlyphCollection::NEHE;
enumTable["ASCII"]=cocos2d::GlyphCollection::ASCII;
enumTable["CUSTOM"]=cocos2d::GlyphCollection::CUSTOM;
lua["cc"]["GlyphCollection"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreLabelEffectAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,9);
enumTable["NORMAL"]=cocos2d::LabelEffect::NORMAL;
enumTable["OUTLINE"]=cocos2d::LabelEffect::OUTLINE;
enumTable["SHADOW"]=cocos2d::LabelEffect::SHADOW;
enumTable["GLOW"]=cocos2d::LabelEffect::GLOW;
enumTable["ITALICS"]=cocos2d::LabelEffect::ITALICS;
enumTable["BOLD"]=cocos2d::LabelEffect::BOLD;
enumTable["UNDERLINE"]=cocos2d::LabelEffect::UNDERLINE;
enumTable["STRIKETHROUGH"]=cocos2d::LabelEffect::STRIKETHROUGH;
enumTable["ALL"]=cocos2d::LabelEffect::ALL;
lua["cc"]["LabelEffect"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreEventListenerTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,9);
enumTable["UNKNOWN"]=cocos2d::EventListener::Type::UNKNOWN;
enumTable["TOUCH_ONE_BY_ONE"]=cocos2d::EventListener::Type::TOUCH_ONE_BY_ONE;
enumTable["TOUCH_ALL_AT_ONCE"]=cocos2d::EventListener::Type::TOUCH_ALL_AT_ONCE;
enumTable["KEYBOARD"]=cocos2d::EventListener::Type::KEYBOARD;
enumTable["MOUSE"]=cocos2d::EventListener::Type::MOUSE;
enumTable["ACCELERATION"]=cocos2d::EventListener::Type::ACCELERATION;
enumTable["FOCUS"]=cocos2d::EventListener::Type::FOCUS;
enumTable["GAME_CONTROLLER"]=cocos2d::EventListener::Type::GAME_CONTROLLER;
enumTable["CUSTOM"]=cocos2d::EventListener::Type::CUSTOM;
lua["cc"]["EventListener"]["static"]["Type"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreEventListenerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListener).name()] = sol::usertype_traits<cocos2d::EventListener*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListener>("deprecated.cocos2d::EventListener");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListener*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["EventListener"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["CheckAvailable"]=static_cast<bool(cocos2d::EventListener::*)()>(&cocos2d::EventListener::checkAvailable);
mt["Clone"]=static_cast<cocos2d::EventListener*(cocos2d::EventListener::*)()>(&cocos2d::EventListener::clone);
mt["SetEnabled"]=static_cast<void(cocos2d::EventListener::*)(bool)>(&cocos2d::EventListener::setEnabled);
mt["set"]["Enabled"]=mt["SetEnabled"];
mt["IsEnabled"]=static_cast<bool(cocos2d::EventListener::*)()const>(&cocos2d::EventListener::isEnabled);
mt["get"]["Enabled"]=mt["IsEnabled"];
RegisterLuaCoreEventListenerTypeAuto(lua);
}
void RegisterLuaCoreEventListenerCustomAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::EventListenerCustom).name()] = sol::usertype_traits<cocos2d::EventListenerCustom*>::metatable();
auto dep=lua.new_usertype<cocos2d::EventListenerCustom>("deprecated.cocos2d::EventListenerCustom");
dep[sol::base_classes]=sol::bases<cocos2d::EventListener,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::EventListenerCustom*>::metatable(),sol::usertype_traits<cocos2d::EventListener*>::metatable());
lua["cc"]["EventListenerCustom"]=mt;
mt["__new__"]=static_cast<cocos2d::EventListenerCustom*(*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventListenerCustom::create);
}
void RegisterLuaCoreTexture2DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Texture2D).name()] = sol::usertype_traits<cocos2d::Texture2D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Texture2D>("deprecated.cocos2d::Texture2D");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Texture2D*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Texture2D"]=mt;
mt["__new__"]=[](){return new cocos2d::Texture2D();};
mt["static"]["SetDefaultAlphaPixelFormat"]=static_cast<void(*)(cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::setDefaultAlphaPixelFormat);
mt["static"]["set"]["DefaultAlphaPixelFormat"]=mt["SetDefaultAlphaPixelFormat"];
mt["static"]["GetDefaultAlphaPixelFormat"]=static_cast<cocos2d::backend::PixelFormat(*)()>(&cocos2d::Texture2D::getDefaultAlphaPixelFormat);
mt["static"]["get"]["DefaultAlphaPixelFormat"]=mt["GetDefaultAlphaPixelFormat"];
mt["InitWithData"]=sol::overload([](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,int arg3,int arg4,const cocos2d::Size& arg5,bool arg6){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,int arg3,int arg4,const cocos2d::Size& arg5){return obj->initWithData(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["InitWithMipmaps"]=sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->initWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->initWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["UpdateWithImage"]=sol::overload([](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2){return obj->updateWithImage(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1){return obj->updateWithImage(arg0,arg1);});
mt["UpdateWithData"]=sol::overload([](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7,int arg8){return obj->updateWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::Texture2D* obj,const void* arg0,ssize_t arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,const cocos2d::Size& arg6,bool arg7){return obj->updateWithData(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);});
mt["UpdateWithMipmaps"]=sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6,int arg7){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["UpdateWithSubData"]=sol::overload([](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4,int arg5){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4);});
mt["DrawAtPoint"]=static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Vec2&,float)>(&cocos2d::Texture2D::drawAtPoint);
mt["DrawInRect"]=static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Rect&,float)>(&cocos2d::Texture2D::drawInRect);
mt["InitWithImage"]=sol::overload(static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*,cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::initWithImage),static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*)>(&cocos2d::Texture2D::initWithImage));
mt["InitWithString"]=sol::overload([](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6,int arg7){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithString(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithString(arg0,arg1,arg2,arg3);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2){return obj->initWithString(arg0,arg1,arg2);},static_cast<bool(cocos2d::Texture2D::*)(const char*,const cocos2d::FontDefinition&)>(&cocos2d::Texture2D::initWithString));
mt["UpdateTextureDescriptor"]=sol::overload([](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0,bool arg1){return obj->updateTextureDescriptor(arg0,arg1);},[](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);});
mt["SetRenderTarget"]=static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setRenderTarget);
mt["set"]["RenderTarget"]=mt["SetRenderTarget"];
mt["IsRenderTarget"]=static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::isRenderTarget);
mt["get"]["RenderTarget"]=mt["IsRenderTarget"];
mt["SetTexParameters"]=static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::Texture2D::setTexParameters);
mt["set"]["TexParameters"]=mt["SetTexParameters"];
mt["GenerateMipmap"]=static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::generateMipmap);
mt["SetAntiAliasTexParameters"]=static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAntiAliasTexParameters);
mt["SetAliasTexParameters"]=static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAliasTexParameters);
mt["GetStringForFormat"]=static_cast<const char*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getStringForFormat);
mt["get"]["StringForFormat"]=mt["GetStringForFormat"];
mt["GetBitsPerPixelForFormat"]=sol::overload(static_cast<unsigned int(cocos2d::Texture2D::*)(cocos2d::backend::PixelFormat)const>(&cocos2d::Texture2D::getBitsPerPixelForFormat),static_cast<unsigned int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBitsPerPixelForFormat));
mt["get"]["BitsPerPixelForFormat"]=mt["GetBitsPerPixelForFormat"];
mt["GetContentSizeInPixels"]=static_cast<const cocos2d::Size&(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::getContentSizeInPixels);
mt["get"]["ContentSizeInPixels"]=mt["GetContentSizeInPixels"];
mt["HasPremultipliedAlpha"]=static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasPremultipliedAlpha);
mt["SetPremultipliedAlpha"]=static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setPremultipliedAlpha);
mt["set"]["PremultipliedAlpha"]=mt["SetPremultipliedAlpha"];
mt["HasMipmaps"]=static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasMipmaps);
mt["GetPixelFormat"]=static_cast<cocos2d::backend::PixelFormat(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelFormat);
mt["get"]["PixelFormat"]=mt["GetPixelFormat"];
mt["GetSamplerFlags"]=static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getSamplerFlags);
mt["get"]["SamplerFlags"]=mt["GetSamplerFlags"];
mt["GetPixelsWide"]=static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsWide);
mt["get"]["PixelsWide"]=mt["GetPixelsWide"];
mt["GetPixelsHigh"]=static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsHigh);
mt["get"]["PixelsHigh"]=mt["GetPixelsHigh"];
mt["GetBackendTexture"]=static_cast<cocos2d::backend::TextureBackend*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBackendTexture);
mt["get"]["BackendTexture"]=mt["GetBackendTexture"];
mt["GetMaxS"]=static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxS);
mt["get"]["MaxS"]=mt["GetMaxS"];
mt["SetMaxS"]=static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxS);
mt["set"]["MaxS"]=mt["SetMaxS"];
mt["GetMaxT"]=static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxT);
mt["get"]["MaxT"]=mt["GetMaxT"];
mt["SetMaxT"]=static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxT);
mt["set"]["MaxT"]=mt["SetMaxT"];
mt["GetContentSize"]=static_cast<cocos2d::Size(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getContentSize);
mt["get"]["ContentSize"]=mt["GetContentSize"];
mt["GetPath"]=static_cast<std::string(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPath);
mt["get"]["Path"]=mt["GetPath"];
}
void RegisterLuaCoreLabelProtocolAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LabelProtocol).name()] = sol::usertype_traits<cocos2d::LabelProtocol*>::metatable();
auto dep=lua.new_usertype<cocos2d::LabelProtocol>("deprecated.cocos2d::LabelProtocol");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LabelProtocol*>::metatable());
lua["cc"]["LabelProtocol"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["SetString"]=static_cast<void(cocos2d::LabelProtocol::*)(const std::string&)>(&cocos2d::LabelProtocol::setString);
mt["set"]["String"]=mt["SetString"];
mt["GetString"]=static_cast<const std::string&(cocos2d::LabelProtocol::*)()const>(&cocos2d::LabelProtocol::getString);
mt["get"]["String"]=mt["GetString"];
}
