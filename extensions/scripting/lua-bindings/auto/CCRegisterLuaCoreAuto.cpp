#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
static void RegisterLuaRef(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Ref");
mt["retain"]=static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::retain);
mt["release"]=static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::release);
mt["getReferenceCount"]=static_cast<unsigned int(cocos2d::Ref::*)()const>(&cocos2d::Ref::getReferenceCount);
}
static void RegisterLuaConsole(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Console,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Console");
mt["listenOnTCP"]=static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnTCP);
mt["listenOnFileDescriptor"]=static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnFileDescriptor);
mt["stop"]=static_cast<void(cocos2d::Console::*)()>(&cocos2d::Console::stop);
mt["delCommand"]=static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::delCommand);
mt["log"]=static_cast<void(cocos2d::Console::*)(const char*)>(&cocos2d::Console::log);
mt["setBindAddress"]=static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::setBindAddress);
mt["isIpv6Server"]=static_cast<bool(cocos2d::Console::*)()const>(&cocos2d::Console::isIpv6Server);
mt["setCommandSeparator"]=static_cast<void(cocos2d::Console::*)(char)>(&cocos2d::Console::setCommandSeparator);
}
static void RegisterLuaEventListener(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListener");
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListener::*)()>(&cocos2d::EventListener::checkAvailable);
mt["clone"]=static_cast<cocos2d::EventListener*(cocos2d::EventListener::*)()>(&cocos2d::EventListener::clone);
mt["setEnabled"]=static_cast<void(cocos2d::EventListener::*)(bool)>(&cocos2d::EventListener::setEnabled);
mt["isEnabled"]=static_cast<bool(cocos2d::EventListener::*)()const>(&cocos2d::EventListener::isEnabled);
}
static void RegisterLuaEventListenerCustom(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerCustom");
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::checkAvailable);
mt["clone"]=static_cast<cocos2d::EventListenerCustom*(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::clone);
}
static void RegisterLuaShaderCache(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::backend::ShaderCache,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ShaderCache");
mt["removeUnusedShader"]=static_cast<void(cocos2d::backend::ShaderCache::*)()>(&cocos2d::backend::ShaderCache::removeUnusedShader);
mt["getInstance"]=static_cast<cocos2d::backend::ShaderCache*(*)()>(&cocos2d::backend::ShaderCache::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::backend::ShaderCache::destroyInstance);
mt["newVertexShaderModule"]=static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newVertexShaderModule);
mt["newFragmentShaderModule"]=static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newFragmentShaderModule);
}
static void RegisterLuaTexture2D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Texture2D,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Texture2D");
mt["updateWithImage"]=sol::overload([](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1){return obj->updateWithImage(arg0,arg1);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2){return obj->updateWithImage(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2,int arg3){return obj->updateWithImage(arg0,arg1,arg2,arg3);});
mt["updateWithMipmaps"]=sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6,int arg7){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);});
mt["updateWithSubData"]=sol::overload([](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4,int arg5){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["drawAtPoint"]=static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Vec2&,float)>(&cocos2d::Texture2D::drawAtPoint);
mt["drawInRect"]=static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Rect&,float)>(&cocos2d::Texture2D::drawInRect);
mt["initWithImage"]=static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*,cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::initWithImage),static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*)>(&cocos2d::Texture2D::initWithImage);
mt["initWithString"]=sol::overload(static_cast<bool(cocos2d::Texture2D::*)(const char*,const cocos2d::FontDefinition&)>(&cocos2d::Texture2D::initWithString),[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2){return obj->initWithString(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithString(arg0,arg1,arg2,arg3);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithString(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6,int arg7){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);});
mt["updateTextureDescriptor"]=sol::overload([](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0,bool arg1){return obj->updateTextureDescriptor(arg0,arg1);});
mt["setRenderTarget"]=static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setRenderTarget);
mt["isRenderTarget"]=static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::isRenderTarget);
mt["generateMipmap"]=static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::generateMipmap);
mt["setAntiAliasTexParameters"]=static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAntiAliasTexParameters);
mt["setAliasTexParameters"]=static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAliasTexParameters);
mt["getStringForFormat"]=static_cast<const char*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getStringForFormat);
mt["getContentSizeInPixels"]=static_cast<const cocos2d::Size&(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::getContentSizeInPixels);
mt["hasPremultipliedAlpha"]=static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasPremultipliedAlpha);
mt["setPremultipliedAlpha"]=static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setPremultipliedAlpha);
mt["hasMipmaps"]=static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasMipmaps);
mt["getPixelFormat"]=static_cast<cocos2d::backend::PixelFormat(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelFormat);
mt["getTextureFormatEXT"]=static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getTextureFormatEXT);
mt["getPixelsWide"]=static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsWide);
mt["getPixelsHigh"]=static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsHigh);
mt["getBackendTexture"]=static_cast<cocos2d::backend::TextureBackend*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBackendTexture);
mt["getMaxS"]=static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxS);
mt["setMaxS"]=static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxS);
mt["getMaxT"]=static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxT);
mt["setMaxT"]=static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxT);
mt["getContentSize"]=static_cast<cocos2d::Size(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getContentSize);
mt["getPath"]=static_cast<std::string(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPath);
mt["setDefaultAlphaPixelFormat"]=static_cast<void(*)(cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::setDefaultAlphaPixelFormat);
mt["getDefaultAlphaPixelFormat"]=static_cast<cocos2d::backend::PixelFormat(*)()>(&cocos2d::Texture2D::getDefaultAlphaPixelFormat);
}
static void RegisterLuaComponent(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Component");
mt["init"]=static_cast<bool(cocos2d::Component::*)()>(&cocos2d::Component::init);
mt["isEnabled"]=static_cast<bool(cocos2d::Component::*)()const>(&cocos2d::Component::isEnabled);
mt["setEnabled"]=static_cast<void(cocos2d::Component::*)(bool)>(&cocos2d::Component::setEnabled);
mt["getName"]=static_cast<const std::string&(cocos2d::Component::*)()const>(&cocos2d::Component::getName);
mt["setName"]=static_cast<void(cocos2d::Component::*)(const std::string&)>(&cocos2d::Component::setName);
mt["getOwner"]=static_cast<cocos2d::Node*(cocos2d::Component::*)()const>(&cocos2d::Component::getOwner);
mt["setOwner"]=static_cast<void(cocos2d::Component::*)(cocos2d::Node*)>(&cocos2d::Component::setOwner);
mt["update"]=static_cast<void(cocos2d::Component::*)(float)>(&cocos2d::Component::update);
mt["onAdd"]=static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onAdd);
mt["onRemove"]=static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onRemove);
mt["new"]=static_cast<cocos2d::Component*(*)()>(&cocos2d::Component::create);
}
static void RegisterLuaNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Node");
mt["getDescription"]=static_cast<std::string(cocos2d::Node::*)()const>(&cocos2d::Node::getDescription);
mt["setLocalZOrder"]=static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::setLocalZOrder);
mt["_setLocalZOrder"]=static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::_setLocalZOrder);
mt["updateOrderOfArrival"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateOrderOfArrival);
mt["getLocalZOrder"]=static_cast<int32_t(cocos2d::Node::*)()const>(&cocos2d::Node::getLocalZOrder);
mt["setGlobalZOrder"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setGlobalZOrder);
mt["getGlobalZOrder"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getGlobalZOrder);
mt["setScaleX"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleX);
mt["getScaleX"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleX);
mt["setScaleY"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleY);
mt["getScaleY"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleY);
mt["setScaleZ"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleZ);
mt["getScaleZ"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleZ);
mt["setScale"]=static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setScale),static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScale);
mt["getScale"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScale);
mt["setPosition"]=static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setPosition),static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPosition);
mt["setPositionNormalized"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPositionNormalized);
mt["setNormalizedPosition"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setNormalizedPosition);
mt["getPositionXY"]=static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionXY);
mt["getPositionNormalized"]=static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionNormalized);
mt["getNormalizedPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getNormalizedPosition);
mt["setPositionX"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionX);
mt["getPositionX"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionX);
mt["setPositionY"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionY);
mt["getPositionY"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionY);
mt["setPosition3D"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setPosition3D);
mt["getPosition3D"]=static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getPosition3D);
mt["setPositionZ"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionZ);
mt["getPositionZ"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionZ);
mt["setSkewX"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewX);
mt["getSkewX"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewX);
mt["setSkewY"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewY);
mt["getSkewY"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewY);
mt["getAnchorPoint"]=static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPoint);
mt["getAnchorPointInPoints"]=static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPointInPoints);
mt["getContentSize"]=static_cast<const cocos2d::Size&(cocos2d::Node::*)()const>(&cocos2d::Node::getContentSize);
mt["getContentWidth"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentWidth);
mt["getContentHeight"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentHeight);
mt["setContentWidth"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentWidth);
mt["setContentHeight"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentHeight);
mt["setVisible"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setVisible);
mt["isVisible"]=static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isVisible);
mt["setRotation"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotation);
mt["getRotation"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation);
mt["setRotation3D"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setRotation3D);
mt["getRotation3D"]=static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation3D);
mt["setRotationSkewX"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewX);
mt["getRotationSkewX"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewX);
mt["setRotationSkewY"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewY);
mt["getRotationSkewY"]=static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewY);
mt["setIgnoreAnchorPointForPosition"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setIgnoreAnchorPointForPosition);
mt["isIgnoreAnchorPointForPosition"]=static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isIgnoreAnchorPointForPosition);
mt["addChild"]=static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Node::addChild);
mt["getChildByTag"]=static_cast<cocos2d::Node*(cocos2d::Node::*)(int)const>(&cocos2d::Node::getChildByTag);
mt["getChildByName"]=static_cast<cocos2d::Node*(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::getChildByName);
mt["getChildren"]=static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()const>(&cocos2d::Node::getChildren),static_cast<cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()>(&cocos2d::Node::getChildren);
mt["getChildrenCount"]=static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getChildrenCount);
mt["setParent"]=static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::setParent);
mt["getParent"]=static_cast<const cocos2d::Node*(cocos2d::Node::*)()const>(&cocos2d::Node::getParent),static_cast<cocos2d::Node*(cocos2d::Node::*)()>(&cocos2d::Node::getParent);
mt["removeFromParent"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeFromParent);
mt["removeFromParentAndCleanup"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeFromParentAndCleanup);
mt["removeChild"]=sol::overload([](cocos2d::Node* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Node* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);});
mt["removeChildByTag"]=sol::overload([](cocos2d::Node* obj,int arg0){return obj->removeChildByTag(arg0);},[](cocos2d::Node* obj,int arg0,bool arg1){return obj->removeChildByTag(arg0,arg1);});
mt["removeChildByName"]=sol::overload([](cocos2d::Node* obj,const std::string& arg0){return obj->removeChildByName(arg0);},[](cocos2d::Node* obj,const std::string& arg0,bool arg1){return obj->removeChildByName(arg0,arg1);});
mt["removeAllChildren"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllChildren);
mt["removeAllChildrenWithCleanup"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeAllChildrenWithCleanup);
mt["reorderChild"]=static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::reorderChild);
mt["sortAllChildren"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::sortAllChildren);
mt["getTag"]=static_cast<int(cocos2d::Node::*)()const>(&cocos2d::Node::getTag);
mt["setTag"]=static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::setTag);
mt["getName"]=static_cast<const std::string&(cocos2d::Node::*)()const>(&cocos2d::Node::getName);
mt["setName"]=static_cast<void(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::setName);
mt["setUserObject"]=static_cast<void(cocos2d::Node::*)(cocos2d::Ref*)>(&cocos2d::Node::setUserObject);
mt["isRunning"]=static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isRunning);
mt["cleanup"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::cleanup);
mt["draw"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::draw),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::draw);
mt["visit"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::visit),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::visit);
mt["getScene"]=static_cast<cocos2d::Scene*(cocos2d::Node::*)()const>(&cocos2d::Node::getScene);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocos2d::Node::*)()const>(&cocos2d::Node::getBoundingBox);
mt["setEventDispatcher"]=static_cast<void(cocos2d::Node::*)(cocos2d::EventDispatcher*)>(&cocos2d::Node::setEventDispatcher);
mt["getEventDispatcher"]=static_cast<cocos2d::EventDispatcher*(cocos2d::Node::*)()const>(&cocos2d::Node::getEventDispatcher);
mt["setActionManager"]=static_cast<void(cocos2d::Node::*)(cocos2d::ActionManager*)>(&cocos2d::Node::setActionManager);
mt["getActionManager"]=static_cast<const cocos2d::ActionManager*(cocos2d::Node::*)()const>(&cocos2d::Node::getActionManager),static_cast<cocos2d::ActionManager*(cocos2d::Node::*)()>(&cocos2d::Node::getActionManager);
mt["runAction"]=static_cast<cocos2d::Action*(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::runAction);
mt["stopAllActions"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::stopAllActions);
mt["stopAction"]=static_cast<void(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::stopAction);
mt["stopActionByTag"]=static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopActionByTag);
mt["stopAllActionsByTag"]=static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopAllActionsByTag);
mt["stopActionsByFlags"]=static_cast<void(cocos2d::Node::*)(unsigned int)>(&cocos2d::Node::stopActionsByFlags);
mt["getActionByTag"]=static_cast<cocos2d::Action*(cocos2d::Node::*)(int)>(&cocos2d::Node::getActionByTag);
mt["getNumberOfRunningActions"]=static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getNumberOfRunningActions);
mt["getNumberOfRunningActionsByTag"]=static_cast<ssize_t(cocos2d::Node::*)(int)const>(&cocos2d::Node::getNumberOfRunningActionsByTag);
mt["setScheduler"]=static_cast<void(cocos2d::Node::*)(cocos2d::Scheduler*)>(&cocos2d::Node::setScheduler);
mt["getScheduler"]=static_cast<const cocos2d::Scheduler*(cocos2d::Node::*)()const>(&cocos2d::Node::getScheduler),static_cast<cocos2d::Scheduler*(cocos2d::Node::*)()>(&cocos2d::Node::getScheduler);
mt["isScheduled"]=static_cast<bool(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::isScheduled),static_cast<bool(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)const>(&cocos2d::Node::isScheduled);
mt["resume"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::resume);
mt["pause"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::pause);
mt["update"]=static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::update);
mt["updateTransform"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateTransform);
mt["getNodeToParentTransform"]=static_cast<cocos2d::Mat4(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentTransform),static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentTransform);
mt["getNodeToParentAffineTransform"]=static_cast<cocos2d::AffineTransform(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentAffineTransform),static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentAffineTransform);
mt["setNodeToParentTransform"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4&)>(&cocos2d::Node::setNodeToParentTransform);
mt["getParentToNodeTransform"]=static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeTransform);
mt["getParentToNodeAffineTransform"]=static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeAffineTransform);
mt["getNodeToWorldTransform"]=static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldTransform);
mt["getNodeToWorldAffineTransform"]=static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldAffineTransform);
mt["getWorldToNodeTransform"]=static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeTransform);
mt["getWorldToNodeAffineTransform"]=static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeAffineTransform);
mt["convertToNodeSpace"]=static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpace);
mt["convertToWorldSpace"]=static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpace);
mt["convertToNodeSpaceAR"]=static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpaceAR);
mt["convertToWorldSpaceAR"]=static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpaceAR);
mt["convertTouchToNodeSpace"]=static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpace);
mt["convertTouchToNodeSpaceAR"]=static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpaceAR);
mt["getComponent"]=static_cast<cocos2d::Component*(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::getComponent);
mt["addComponent"]=static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::addComponent);
mt["removeComponent"]=static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::removeComponent),static_cast<bool(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::removeComponent);
mt["removeAllComponents"]=static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllComponents);
mt["getOpacity"]=static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getOpacity);
mt["getDisplayedOpacity"]=static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedOpacity);
mt["setOpacity"]=static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::setOpacity);
mt["updateDisplayedOpacity"]=static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::updateDisplayedOpacity);
mt["isCascadeOpacityEnabled"]=static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeOpacityEnabled);
mt["setCascadeOpacityEnabled"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeOpacityEnabled);
mt["getColor"]=static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getColor);
mt["getDisplayedColor"]=static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedColor);
mt["setColor"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::setColor);
mt["updateDisplayedColor"]=static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::updateDisplayedColor);
mt["isCascadeColorEnabled"]=static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeColorEnabled);
mt["setCascadeColorEnabled"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeColorEnabled);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isOpacityModifyRGB);
mt["SetOnEnterHandler"]=static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnEnterHandler);
mt["GetOnEnterHandler"]=static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnEnterHandler);
mt["SetOnExitHandler"]=static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnExitHandler);
mt["GetOnExitHandler"]=static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnExitHandler);
mt["SetOnEnterTransitionDidFinishHandler"]=static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnEnterTransitionDidFinishHandler);
mt["GetOnEnterTransitionDidFinishHandler"]=static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnEnterTransitionDidFinishHandler);
mt["SetOnExitTransitionDidStartHandler"]=static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnExitTransitionDidStartHandler);
mt["GetOnExitTransitionDidStartHandler"]=static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnExitTransitionDidStartHandler);
mt["SetOnCleanUpHandler"]=static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnCleanUpHandler);
mt["GetOnCleanUpHandler"]=static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnCleanUpHandler);
mt["SetOnUpdateHandler"]=static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnUpdateHandler);
mt["GetOnUpdateHandler"]=static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnUpdateHandler);
mt["getCameraMask"]=static_cast<unsigned short(cocos2d::Node::*)()const>(&cocos2d::Node::getCameraMask);
mt["setCameraMask"]=sol::overload([](cocos2d::Node* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Node* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);});
mt["setProgramState"]=sol::overload([](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);},static_cast<void(cocos2d::Node::*)(uint32_t)>(&cocos2d::Node::setProgramState));
mt["setProgramStateWithRegistry"]=static_cast<void(cocos2d::Node::*)(uint32_t,cocos2d::Texture2D*)>(&cocos2d::Node::setProgramStateWithRegistry);
mt["getProgramState"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::Node::*)()const>(&cocos2d::Node::getProgramState);
mt["updateProgramStateTexture"]=static_cast<void(cocos2d::Node::*)(cocos2d::Texture2D*)>(&cocos2d::Node::updateProgramStateTexture);
mt["init"]=static_cast<bool(cocos2d::Node::*)()>(&cocos2d::Node::init);
mt["setPhysicsBody"]=static_cast<void(cocos2d::Node::*)(cocos2d::PhysicsBody*)>(&cocos2d::Node::setPhysicsBody);
mt["getPhysicsBody"]=static_cast<cocos2d::PhysicsBody*(cocos2d::Node::*)()const>(&cocos2d::Node::getPhysicsBody);
mt["new"]=static_cast<cocos2d::Node*(*)()>(&cocos2d::Node::create);
mt["getAttachedNodeCount"]=static_cast<int(*)()>(&cocos2d::Node::getAttachedNodeCount);
}
static void RegisterLuaScene(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Scene");
mt["getDescription"]=static_cast<std::string(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDescription);
mt["getDefaultCamera"]=static_cast<cocos2d::Camera*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDefaultCamera);
mt["render"]=sol::overload([](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1){return obj->render(arg0,arg1);},[](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1,const cocos2d::Mat4* arg2){return obj->render(arg0,arg1,arg2);});
mt["removeAllChildren"]=static_cast<void(cocos2d::Scene::*)()>(&cocos2d::Scene::removeAllChildren);
mt["init"]=static_cast<bool(cocos2d::Scene::*)()>(&cocos2d::Scene::init);
mt["initWithSize"]=static_cast<bool(cocos2d::Scene::*)(const cocos2d::Size&)>(&cocos2d::Scene::initWithSize);
mt["setCameraOrderDirty"]=static_cast<void(cocos2d::Scene::*)()>(&cocos2d::Scene::setCameraOrderDirty);
mt["onProjectionChanged"]=static_cast<void(cocos2d::Scene::*)(cocos2d::EventCustom*)>(&cocos2d::Scene::onProjectionChanged);
mt["getPhysicsWorld"]=static_cast<cocos2d::PhysicsWorld*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getPhysicsWorld);
mt["initWithPhysics"]=static_cast<bool(cocos2d::Scene::*)()>(&cocos2d::Scene::initWithPhysics);
mt["stepPhysicsAndNavigation"]=static_cast<void(cocos2d::Scene::*)(float)>(&cocos2d::Scene::stepPhysicsAndNavigation);
mt["new"]=static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::create);
mt["createWithSize"]=static_cast<cocos2d::Scene*(*)(const cocos2d::Size&)>(&cocos2d::Scene::createWithSize);
mt["createWithPhysics"]=static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::createWithPhysics);
}
static void RegisterLuaEvent(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Event");
mt["getType"]=static_cast<cocos2d::Event::Type(cocos2d::Event::*)()const>(&cocos2d::Event::getType);
mt["stopPropagation"]=static_cast<void(cocos2d::Event::*)()>(&cocos2d::Event::stopPropagation);
mt["isStopped"]=static_cast<bool(cocos2d::Event::*)()const>(&cocos2d::Event::isStopped);
mt["getCurrentTarget"]=static_cast<cocos2d::Node*(cocos2d::Event::*)()>(&cocos2d::Event::getCurrentTarget);
}
static void RegisterLuaEventTouch(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventTouch,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventTouch");
mt["getEventCode"]=static_cast<cocos2d::EventTouch::EventCode(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getEventCode);
mt["setEventCode"]=static_cast<void(cocos2d::EventTouch::*)(cocos2d::EventTouch::EventCode)>(&cocos2d::EventTouch::setEventCode);
}
static void RegisterLuaGLView(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"GLView");
mt["endToLua"]=static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::end);
mt["isOpenGLReady"]=static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isOpenGLReady);
mt["swapBuffers"]=static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::swapBuffers);
mt["setIMEKeyboardState"]=static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setIMEKeyboardState);
mt["windowShouldClose"]=static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::windowShouldClose);
mt["pollEvents"]=static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::pollEvents);
mt["getFrameSize"]=static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameSize);
mt["setFrameSize"]=static_cast<void(cocos2d::GLView::*)(const cocos2d::Size&)>(&cocos2d::GLView::setFrameSize),static_cast<void(cocos2d::GLView::*)(float,float)>(&cocos2d::GLView::setFrameSize);
mt["setFrameZoomFactor"]=static_cast<void(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setFrameZoomFactor);
mt["getFrameZoomFactor"]=static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameZoomFactor);
mt["setCursorVisible"]=static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setCursorVisible);
mt["getRetinaFactor"]=static_cast<int(cocos2d::GLView::*)()const>(&cocos2d::GLView::getRetinaFactor);
mt["setContentScaleFactor"]=static_cast<bool(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setContentScaleFactor);
mt["getContentScaleFactor"]=static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getContentScaleFactor);
mt["isRetinaDisplay"]=static_cast<bool(cocos2d::GLView::*)()const>(&cocos2d::GLView::isRetinaDisplay);
mt["getVisibleSize"]=static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleSize);
mt["getVisibleOrigin"]=static_cast<cocos2d::Vec2(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleOrigin);
mt["getVisibleRect"]=static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleRect);
mt["getSafeAreaRect"]=static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getSafeAreaRect);
mt["setDesignResolutionSize"]=static_cast<void(cocos2d::GLView::*)(float,float,ResolutionPolicy)>(&cocos2d::GLView::setDesignResolutionSize);
mt["getDesignResolutionSize"]=static_cast<const cocos2d::Size&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getDesignResolutionSize);
mt["setViewPortInPoints"]=static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setViewPortInPoints);
mt["setScissorInPoints"]=static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setScissorInPoints);
mt["isScissorEnabled"]=static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isScissorEnabled);
mt["getScissorRect"]=static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScissorRect);
mt["setViewName"]=static_cast<void(cocos2d::GLView::*)(const std::string&)>(&cocos2d::GLView::setViewName);
mt["getViewName"]=static_cast<const std::string&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewName);
mt["setIcon"]=static_cast<void(cocos2d::GLView::*)(const std::vector<std::string>&)const>(&cocos2d::GLView::setIcon),static_cast<void(cocos2d::GLView::*)(const std::string&)const>(&cocos2d::GLView::setIcon);
mt["setDefaultIcon"]=static_cast<void(cocos2d::GLView::*)()const>(&cocos2d::GLView::setDefaultIcon);
mt["getViewPortRect"]=static_cast<const cocos2d::Rect&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewPortRect);
mt["getScaleX"]=static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleX);
mt["getScaleY"]=static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleY);
mt["getResolutionPolicy"]=static_cast<ResolutionPolicy(cocos2d::GLView::*)()const>(&cocos2d::GLView::getResolutionPolicy);
mt["renderScene"]=static_cast<void(cocos2d::GLView::*)(cocos2d::Scene*,cocos2d::Renderer*)>(&cocos2d::GLView::renderScene);
mt["setGLContextAttrs"]=static_cast<void(*)(GLContextAttrs&)>(&cocos2d::GLView::setGLContextAttrs);
mt["getGLContextAttrs"]=static_cast<GLContextAttrs(*)()>(&cocos2d::GLView::getGLContextAttrs);
}
static void RegisterLuaDirector(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Director>(lua.get_or("cc",lua.create_named_table("cc")),"Director");
mt["init"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::init);
mt["getRunningScene"]=static_cast<cocos2d::Scene*(cocos2d::Director::*)()>(&cocos2d::Director::getRunningScene);
mt["getAnimationInterval"]=static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getAnimationInterval);
mt["setAnimationInterval"]=static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setAnimationInterval);
mt["isDisplayStats"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isDisplayStats);
mt["setDisplayStats"]=static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setDisplayStats);
mt["getSecondsPerFrame"]=static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getSecondsPerFrame);
mt["getOpenGLView"]=static_cast<cocos2d::GLView*(cocos2d::Director::*)()>(&cocos2d::Director::getOpenGLView);
mt["setOpenGLView"]=static_cast<void(cocos2d::Director::*)(cocos2d::GLView*)>(&cocos2d::Director::setOpenGLView);
mt["getTextureCache"]=static_cast<cocos2d::TextureCache*(cocos2d::Director::*)()const>(&cocos2d::Director::getTextureCache);
mt["isNextDeltaTimeZero"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isNextDeltaTimeZero);
mt["setNextDeltaTimeZero"]=static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setNextDeltaTimeZero);
mt["isPaused"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isPaused);
mt["getTotalFrames"]=static_cast<unsigned int(cocos2d::Director::*)()>(&cocos2d::Director::getTotalFrames);
mt["setViewport"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setViewport);
mt["isSendCleanupToScene"]=static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isSendCleanupToScene);
mt["getNotificationNode"]=static_cast<cocos2d::Node*(cocos2d::Director::*)()const>(&cocos2d::Director::getNotificationNode);
mt["setNotificationNode"]=static_cast<void(cocos2d::Director::*)(cocos2d::Node*)>(&cocos2d::Director::setNotificationNode);
mt["getWinSize"]=static_cast<const cocos2d::Size&(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSize);
mt["getWinSizeInPixels"]=static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSizeInPixels);
mt["getVisibleSize"]=static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleSize);
mt["getVisibleOrigin"]=static_cast<cocos2d::Vec2(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleOrigin);
mt["getSafeAreaRect"]=static_cast<cocos2d::Rect(cocos2d::Director::*)()const>(&cocos2d::Director::getSafeAreaRect);
mt["convertToGL"]=static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToGL);
mt["convertToUI"]=static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToUI);
mt["getZEye"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getZEye);
mt["runWithScene"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::runWithScene);
mt["pushScene"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::pushScene);
mt["popScene"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popScene);
mt["popToRootScene"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popToRootScene);
mt["popToSceneStackLevel"]=static_cast<void(cocos2d::Director::*)(int)>(&cocos2d::Director::popToSceneStackLevel);
mt["replaceScene"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::replaceScene);
mt["endToLua"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::end);
mt["pause"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::pause);
mt["resume"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resume);
mt["restart"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::restart);
mt["stopAnimation"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::stopAnimation);
mt["startAnimation"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::startAnimation);
mt["drawScene"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::drawScene);
mt["purgeCachedData"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::purgeCachedData);
mt["setDefaultValues"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setDefaultValues);
mt["setGLDefaultValues"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setGLDefaultValues);
mt["setClearColor"]=static_cast<void(cocos2d::Director::*)(const cocos2d::Color4F&)>(&cocos2d::Director::setClearColor);
mt["mainLoop"]=static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::mainLoop),static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::mainLoop);
mt["setContentScaleFactor"]=static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setContentScaleFactor);
mt["getContentScaleFactor"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getContentScaleFactor);
mt["getScheduler"]=static_cast<cocos2d::Scheduler*(cocos2d::Director::*)()const>(&cocos2d::Director::getScheduler);
mt["setScheduler"]=static_cast<void(cocos2d::Director::*)(cocos2d::Scheduler*)>(&cocos2d::Director::setScheduler);
mt["getActionManager"]=static_cast<cocos2d::ActionManager*(cocos2d::Director::*)()const>(&cocos2d::Director::getActionManager);
mt["setActionManager"]=static_cast<void(cocos2d::Director::*)(cocos2d::ActionManager*)>(&cocos2d::Director::setActionManager);
mt["getEventDispatcher"]=static_cast<cocos2d::EventDispatcher*(cocos2d::Director::*)()const>(&cocos2d::Director::getEventDispatcher);
mt["setEventDispatcher"]=static_cast<void(cocos2d::Director::*)(cocos2d::EventDispatcher*)>(&cocos2d::Director::setEventDispatcher);
mt["getConsole"]=static_cast<cocos2d::Console*(cocos2d::Director::*)()const>(&cocos2d::Director::getConsole);
mt["getDeltaTime"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getDeltaTime);
mt["getFrameRate"]=static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getFrameRate);
mt["pushMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::pushMatrix);
mt["popMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::popMatrix);
mt["loadIdentityMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::loadIdentityMatrix);
mt["loadMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::loadMatrix);
mt["multiplyMatrix"]=static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::multiplyMatrix);
mt["getMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)const>(&cocos2d::Director::getMatrix);
mt["resetMatrixStack"]=static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resetMatrixStack);
mt["isValid"]=static_cast<bool(cocos2d::Director::*)()const>(&cocos2d::Director::isValid);
mt["getInstance"]=static_cast<cocos2d::Director*(*)()>(&cocos2d::Director::getInstance);
}
static void RegisterLuaTimer(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Timer,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Timer");
mt["setupTimerWithInterval"]=static_cast<void(cocos2d::Timer::*)(float,unsigned int,float)>(&cocos2d::Timer::setupTimerWithInterval);
mt["setAborted"]=static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::setAborted);
mt["isAborted"]=static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isAborted);
mt["isExhausted"]=static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isExhausted);
mt["trigger"]=static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::trigger);
mt["cancel"]=static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::cancel);
mt["update"]=static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::update);
}
static void RegisterLuaScheduler(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Scheduler,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Scheduler");
mt["getTimeScale"]=static_cast<float(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::getTimeScale);
mt["setTimeScale"]=static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::setTimeScale);
mt["removeAllFunctionsToBePerformedInCocosThread"]=static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::removeAllFunctionsToBePerformedInCocosThread);
}
static void RegisterLuaAsyncTaskPool(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::AsyncTaskPool>(lua.get_or("cc",lua.create_named_table("cc")),"AsyncTaskPool");
mt["stopTasks"]=static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks);
mt["enqueue"]=static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue),static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,cocos2d::AsyncTaskPool::TaskCallBack,void*,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue);
mt["getInstance"]=static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance);
}
static void RegisterLuaAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Action");
mt["clone"]=static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::clone);
mt["reverse"]=static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::reverse);
mt["isDone"]=static_cast<bool(cocos2d::Action::*)()const>(&cocos2d::Action::isDone);
mt["startWithTarget"]=static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Action::*)()>(&cocos2d::Action::stop);
mt["step"]=static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::step);
mt["update"]=static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::update);
mt["getTarget"]=static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getTarget);
mt["setTarget"]=static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setTarget);
mt["getOriginalTarget"]=static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getOriginalTarget);
mt["setOriginalTarget"]=static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setOriginalTarget);
mt["getTag"]=static_cast<int(cocos2d::Action::*)()const>(&cocos2d::Action::getTag);
mt["setTag"]=static_cast<void(cocos2d::Action::*)(int)>(&cocos2d::Action::setTag);
mt["getFlags"]=static_cast<unsigned int(cocos2d::Action::*)()const>(&cocos2d::Action::getFlags);
mt["setFlags"]=static_cast<void(cocos2d::Action::*)(unsigned int)>(&cocos2d::Action::setFlags);
}
static void RegisterLuaFiniteTimeAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FiniteTimeAction");
mt["getDuration"]=static_cast<float(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::getDuration);
mt["setDuration"]=static_cast<void(cocos2d::FiniteTimeAction::*)(float)>(&cocos2d::FiniteTimeAction::setDuration);
mt["reverse"]=static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::reverse);
mt["clone"]=static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::clone);
}
static void RegisterLuaSpeed(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Speed,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Speed");
mt["getSpeed"]=static_cast<float(cocos2d::Speed::*)()const>(&cocos2d::Speed::getSpeed);
mt["setSpeed"]=static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::setSpeed);
mt["setInnerAction"]=static_cast<void(cocos2d::Speed::*)(cocos2d::ActionInterval*)>(&cocos2d::Speed::setInnerAction);
mt["getInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::Speed::*)()const>(&cocos2d::Speed::getInnerAction);
mt["clone"]=static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::clone);
mt["reverse"]=static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::Speed::*)(cocos2d::Node*)>(&cocos2d::Speed::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Speed::*)()>(&cocos2d::Speed::stop);
mt["step"]=static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::step);
mt["isDone"]=static_cast<bool(cocos2d::Speed::*)()const>(&cocos2d::Speed::isDone);
mt["initWithAction"]=static_cast<bool(cocos2d::Speed::*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::initWithAction);
mt["new"]=static_cast<cocos2d::Speed*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::create);
}
static void RegisterLuaFollow(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Follow,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Follow");
mt["isBoundarySet"]=static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isBoundarySet);
mt["setBoundarySet"]=static_cast<void(cocos2d::Follow::*)(bool)>(&cocos2d::Follow::setBoundarySet);
mt["clone"]=static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::clone);
mt["reverse"]=static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::reverse);
mt["step"]=static_cast<void(cocos2d::Follow::*)(float)>(&cocos2d::Follow::step);
mt["isDone"]=static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isDone);
mt["stop"]=static_cast<void(cocos2d::Follow::*)()>(&cocos2d::Follow::stop);
mt["initWithTarget"]=sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->initWithTarget(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->initWithTarget(arg0,arg1);});
mt["initWithTargetAndOffset"]=sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->initWithTargetAndOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->initWithTargetAndOffset(arg0,arg1,arg2,arg3);});
mt["new"]=sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->create(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);});
mt["createWithOffset"]=sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->createWithOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->createWithOffset(arg0,arg1,arg2,arg3);});
}
static void RegisterLuaImage(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Image,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Image");
mt["initWithImageFile"]=static_cast<bool(cocos2d::Image::*)(const std::string&)>(&cocos2d::Image::initWithImageFile);
mt["getDataLen"]=static_cast<ssize_t(cocos2d::Image::*)()>(&cocos2d::Image::getDataLen);
mt["getFileType"]=static_cast<cocos2d::Image::Format(cocos2d::Image::*)()>(&cocos2d::Image::getFileType);
mt["getPixelFormat"]=static_cast<cocos2d::backend::PixelFormat(cocos2d::Image::*)()>(&cocos2d::Image::getPixelFormat);
mt["getWidth"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getWidth);
mt["getHeight"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getHeight);
mt["getNumberOfMipmaps"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getNumberOfMipmaps);
mt["hasPremultipliedAlpha"]=static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasPremultipliedAlpha);
mt["getFilePath"]=static_cast<std::string(cocos2d::Image::*)()const>(&cocos2d::Image::getFilePath);
mt["getBitPerPixel"]=static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getBitPerPixel);
mt["hasAlpha"]=static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasAlpha);
mt["isCompressed"]=static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::isCompressed);
mt["saveToFile"]=sol::overload([](cocos2d::Image* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::Image* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);});
mt["premultiplyAlpha"]=static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::premultiplyAlpha);
mt["reversePremultipliedAlpha"]=static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::reversePremultipliedAlpha);
mt["setPNGPremultipliedAlphaEnabled"]=static_cast<void(*)(bool)>(&cocos2d::Image::setPNGPremultipliedAlphaEnabled);
mt["setCompressedImagesHavePMA"]=static_cast<void(*)(uint32_t,bool)>(&cocos2d::Image::setCompressedImagesHavePMA);
mt["isCompressedImageHavePMA"]=static_cast<bool(*)(uint32_t)>(&cocos2d::Image::isCompressedImageHavePMA);
}
static void RegisterLuaPolygonInfo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::PolygonInfo>(lua.get_or("cc",lua.create_named_table("cc")),"PolygonInfo");
mt["setQuad"]=static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*)>(&cocos2d::PolygonInfo::setQuad);
mt["setQuads"]=static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*,int)>(&cocos2d::PolygonInfo::setQuads);
mt["setTriangles"]=static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::TrianglesCommand::Triangles&)>(&cocos2d::PolygonInfo::setTriangles);
mt["getVertCount"]=static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getVertCount);
mt["getTrianglesCount"]=static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getTrianglesCount);
mt["getArea"]=static_cast<float(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getArea);
mt["getRect"]=static_cast<const cocos2d::Rect&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getRect);
mt["setRect"]=static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::Rect&)>(&cocos2d::PolygonInfo::setRect);
mt["getFilename"]=static_cast<const std::string&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getFilename);
mt["setFilename"]=static_cast<void(cocos2d::PolygonInfo::*)(const std::string&)>(&cocos2d::PolygonInfo::setFilename);
}
static void RegisterLuaAutoPolygon(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::AutoPolygon>(lua.get_or("cc",lua.create_named_table("cc")),"AutoPolygon");
}
static void RegisterLuaSpriteFrame(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SpriteFrame,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SpriteFrame");
mt["getRectInPixels"]=static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRectInPixels);
mt["setRectInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRectInPixels);
mt["isRotated"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::isRotated);
mt["setRotated"]=static_cast<void(cocos2d::SpriteFrame::*)(bool)>(&cocos2d::SpriteFrame::setRotated);
mt["getRect"]=static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRect);
mt["setRect"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRect);
mt["getCenterRect"]=static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getCenterRect);
mt["setCenterRectInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setCenterRectInPixels);
mt["hasCenterRect"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasCenterRect);
mt["getOffsetInPixels"]=static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffsetInPixels);
mt["setOffsetInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffsetInPixels);
mt["getOriginalSizeInPixels"]=static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSizeInPixels);
mt["setOriginalSizeInPixels"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSizeInPixels);
mt["getOriginalSize"]=static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSize);
mt["setOriginalSize"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSize);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::SpriteFrame::*)()>(&cocos2d::SpriteFrame::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrame::setTexture);
mt["getOffset"]=static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffset);
mt["setOffset"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffset);
mt["getAnchorPoint"]=static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getAnchorPoint);
mt["setAnchorPoint"]=static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setAnchorPoint);
mt["hasAnchorPoint"]=static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasAnchorPoint);
mt["clone"]=static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::clone);
mt["initWithTexture"]=static_cast<bool(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::initWithTexture),static_cast<bool(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::initWithTexture);
mt["initWithTextureFilename"]=static_cast<bool(cocos2d::SpriteFrame::*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::initWithTextureFilename),static_cast<bool(cocos2d::SpriteFrame::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::initWithTextureFilename);
mt["new"]=static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::create),static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::create);
mt["createWithTexture"]=static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::createWithTexture),static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::createWithTexture);
}
static void RegisterLuaAnimationFrame(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::AnimationFrame,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"AnimationFrame");
mt["getSpriteFrame"]=static_cast<cocos2d::SpriteFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getSpriteFrame);
mt["setSpriteFrame"]=static_cast<void(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*)>(&cocos2d::AnimationFrame::setSpriteFrame);
mt["getDelayUnits"]=static_cast<float(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getDelayUnits);
mt["setDelayUnits"]=static_cast<void(cocos2d::AnimationFrame::*)(float)>(&cocos2d::AnimationFrame::setDelayUnits);
mt["getUserInfo"]=static_cast<cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()>(&cocos2d::AnimationFrame::getUserInfo),static_cast<const cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getUserInfo);
mt["setUserInfo"]=static_cast<void(cocos2d::AnimationFrame::*)(const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::setUserInfo);
mt["clone"]=static_cast<cocos2d::AnimationFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::clone);
mt["initWithSpriteFrame"]=static_cast<bool(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::initWithSpriteFrame);
mt["new"]=static_cast<cocos2d::AnimationFrame*(*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::create);
}
static void RegisterLuaAnimation(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Animation,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Animation");
mt["addSpriteFrame"]=static_cast<void(cocos2d::Animation::*)(cocos2d::SpriteFrame*)>(&cocos2d::Animation::addSpriteFrame);
mt["addSpriteFrameWithFile"]=static_cast<void(cocos2d::Animation::*)(const std::string&)>(&cocos2d::Animation::addSpriteFrameWithFile);
mt["addSpriteFrameWithTexture"]=static_cast<void(cocos2d::Animation::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Animation::addSpriteFrameWithTexture);
mt["getTotalDelayUnits"]=static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getTotalDelayUnits);
mt["setDelayPerUnit"]=static_cast<void(cocos2d::Animation::*)(float)>(&cocos2d::Animation::setDelayPerUnit);
mt["getDelayPerUnit"]=static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDelayPerUnit);
mt["getDuration"]=static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDuration);
mt["getFrames"]=static_cast<const cocos2d::Vector<cocos2d::AnimationFrame *>&(cocos2d::Animation::*)()const>(&cocos2d::Animation::getFrames);
mt["setFrames"]=static_cast<void(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&)>(&cocos2d::Animation::setFrames);
mt["getRestoreOriginalFrame"]=static_cast<bool(cocos2d::Animation::*)()const>(&cocos2d::Animation::getRestoreOriginalFrame);
mt["setRestoreOriginalFrame"]=static_cast<void(cocos2d::Animation::*)(bool)>(&cocos2d::Animation::setRestoreOriginalFrame);
mt["getLoops"]=static_cast<unsigned int(cocos2d::Animation::*)()const>(&cocos2d::Animation::getLoops);
mt["setLoops"]=static_cast<void(cocos2d::Animation::*)(unsigned int)>(&cocos2d::Animation::setLoops);
mt["clone"]=static_cast<cocos2d::Animation*(cocos2d::Animation::*)()const>(&cocos2d::Animation::clone);
mt["init"]=static_cast<bool(cocos2d::Animation::*)()>(&cocos2d::Animation::init);
mt["initWithSpriteFrames"]=sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->initWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->initWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->initWithSpriteFrames(arg0,arg1,arg2);});
mt["initWithAnimationFrames"]=static_cast<bool(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&,float,unsigned int)>(&cocos2d::Animation::initWithAnimationFrames);
mt["new"]=sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1){return obj->create(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1,unsigned int arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::Animation*(*)()>(&cocos2d::Animation::create));
mt["createWithSpriteFrames"]=sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->createWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->createWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->createWithSpriteFrames(arg0,arg1,arg2);});
}
static void RegisterLuaActionInterval(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionInterval");
mt["getElapsed"]=static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getElapsed);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::setAmplitudeRate);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getAmplitudeRate);
mt["isDone"]=static_cast<bool(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::isDone);
mt["step"]=static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::step);
mt["startWithTarget"]=static_cast<void(cocos2d::ActionInterval::*)(cocos2d::Node*)>(&cocos2d::ActionInterval::startWithTarget);
mt["reverse"]=static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::reverse);
mt["clone"]=static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::clone);
mt["initWithDuration"]=static_cast<bool(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::initWithDuration);
}
static void RegisterLuaSequence(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Sequence,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Sequence");
mt["clone"]=static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::clone);
mt["reverse"]=static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::Sequence::*)(cocos2d::Node*)>(&cocos2d::Sequence::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Sequence::*)()>(&cocos2d::Sequence::stop);
mt["isDone"]=static_cast<bool(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::isDone);
mt["update"]=static_cast<void(cocos2d::Sequence::*)(float)>(&cocos2d::Sequence::update);
mt["initWithTwoActions"]=static_cast<bool(cocos2d::Sequence::*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Sequence::initWithTwoActions);
mt["init"]=static_cast<bool(cocos2d::Sequence::*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Sequence::init);
}
static void RegisterLuaRepeat(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Repeat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Repeat");
mt["setInnerAction"]=static_cast<void(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*)>(&cocos2d::Repeat::setInnerAction);
mt["getInnerAction"]=static_cast<cocos2d::FiniteTimeAction*(cocos2d::Repeat::*)()>(&cocos2d::Repeat::getInnerAction);
mt["clone"]=static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::clone);
mt["reverse"]=static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::Repeat::*)(cocos2d::Node*)>(&cocos2d::Repeat::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Repeat::*)()>(&cocos2d::Repeat::stop);
mt["update"]=static_cast<void(cocos2d::Repeat::*)(float)>(&cocos2d::Repeat::update);
mt["isDone"]=static_cast<bool(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::isDone);
mt["initWithAction"]=static_cast<bool(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::initWithAction);
mt["new"]=static_cast<cocos2d::Repeat*(*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::create);
}
static void RegisterLuaRepeatForever(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::RepeatForever,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"RepeatForever");
mt["setInnerAction"]=static_cast<void(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::setInnerAction);
mt["getInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::RepeatForever::*)()>(&cocos2d::RepeatForever::getInnerAction);
mt["clone"]=static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::clone);
mt["reverse"]=static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::RepeatForever::*)(cocos2d::Node*)>(&cocos2d::RepeatForever::startWithTarget);
mt["step"]=static_cast<void(cocos2d::RepeatForever::*)(float)>(&cocos2d::RepeatForever::step);
mt["isDone"]=static_cast<bool(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::isDone);
mt["initWithAction"]=static_cast<bool(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::initWithAction);
mt["new"]=static_cast<cocos2d::RepeatForever*(*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::create);
}
static void RegisterLuaSpawn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Spawn,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Spawn");
mt["clone"]=static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::clone);
mt["reverse"]=static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::Spawn::*)(cocos2d::Node*)>(&cocos2d::Spawn::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Spawn::*)()>(&cocos2d::Spawn::stop);
mt["update"]=static_cast<void(cocos2d::Spawn::*)(float)>(&cocos2d::Spawn::update);
mt["initWithTwoActions"]=static_cast<bool(cocos2d::Spawn::*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Spawn::initWithTwoActions);
mt["init"]=static_cast<bool(cocos2d::Spawn::*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Spawn::init);
}
static void RegisterLuaRotateTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::RotateTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"RotateTo");
mt["clone"]=static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::clone);
mt["reverse"]=static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::RotateTo::*)(cocos2d::Node*)>(&cocos2d::RotateTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::RotateTo::*)(float)>(&cocos2d::RotateTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::RotateTo::*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::initWithDuration),static_cast<bool(cocos2d::RotateTo::*)(float,float,float)>(&cocos2d::RotateTo::initWithDuration);
mt["new"]=static_cast<cocos2d::RotateTo*(*)(float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::create);
}
static void RegisterLuaRotateBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::RotateBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"RotateBy");
mt["clone"]=static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::clone);
mt["reverse"]=static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::RotateBy::*)(cocos2d::Node*)>(&cocos2d::RotateBy::startWithTarget);
mt["update"]=static_cast<void(cocos2d::RotateBy::*)(float)>(&cocos2d::RotateBy::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::RotateBy::*)(float,float,float)>(&cocos2d::RotateBy::initWithDuration),static_cast<bool(cocos2d::RotateBy::*)(float,float)>(&cocos2d::RotateBy::initWithDuration),static_cast<bool(cocos2d::RotateBy::*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::initWithDuration);
mt["new"]=static_cast<cocos2d::RotateBy*(*)(float,float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::create);
}
static void RegisterLuaMoveBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MoveBy");
mt["clone"]=static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::clone);
mt["reverse"]=static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::MoveBy::*)(cocos2d::Node*)>(&cocos2d::MoveBy::startWithTarget);
mt["update"]=static_cast<void(cocos2d::MoveBy::*)(float)>(&cocos2d::MoveBy::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::MoveBy::*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::initWithDuration),static_cast<bool(cocos2d::MoveBy::*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::initWithDuration);
mt["new"]=static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::create),static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::create);
}
static void RegisterLuaMoveTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MoveTo,cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MoveTo");
mt["clone"]=static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::clone);
mt["reverse"]=static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::MoveTo::*)(cocos2d::Node*)>(&cocos2d::MoveTo::startWithTarget);
mt["initWithDuration"]=static_cast<bool(cocos2d::MoveTo::*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::initWithDuration),static_cast<bool(cocos2d::MoveTo::*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::initWithDuration);
mt["new"]=static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::create),static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::create);
}
static void RegisterLuaSkewTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SkewTo");
mt["clone"]=static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::clone);
mt["reverse"]=static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::SkewTo::*)(cocos2d::Node*)>(&cocos2d::SkewTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::SkewTo::*)(float)>(&cocos2d::SkewTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::SkewTo::*)(float,float,float)>(&cocos2d::SkewTo::initWithDuration);
mt["new"]=static_cast<cocos2d::SkewTo*(*)(float,float,float)>(&cocos2d::SkewTo::create);
}
static void RegisterLuaSkewBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SkewBy,cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SkewBy");
mt["startWithTarget"]=static_cast<void(cocos2d::SkewBy::*)(cocos2d::Node*)>(&cocos2d::SkewBy::startWithTarget);
mt["clone"]=static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::clone);
mt["reverse"]=static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::reverse);
mt["initWithDuration"]=static_cast<bool(cocos2d::SkewBy::*)(float,float,float)>(&cocos2d::SkewBy::initWithDuration);
mt["new"]=static_cast<cocos2d::SkewBy*(*)(float,float,float)>(&cocos2d::SkewBy::create);
}
static void RegisterLuaJumpBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"JumpBy");
mt["clone"]=static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::clone);
mt["reverse"]=static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::JumpBy::*)(cocos2d::Node*)>(&cocos2d::JumpBy::startWithTarget);
mt["update"]=static_cast<void(cocos2d::JumpBy::*)(float)>(&cocos2d::JumpBy::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::JumpBy::*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::initWithDuration);
mt["new"]=static_cast<cocos2d::JumpBy*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::create);
}
static void RegisterLuaJumpTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::JumpTo,cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"JumpTo");
mt["startWithTarget"]=static_cast<void(cocos2d::JumpTo::*)(cocos2d::Node*)>(&cocos2d::JumpTo::startWithTarget);
mt["clone"]=static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::clone);
mt["reverse"]=static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::reverse);
mt["initWithDuration"]=static_cast<bool(cocos2d::JumpTo::*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::initWithDuration);
mt["new"]=static_cast<cocos2d::JumpTo*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::create);
}
static void RegisterLuaBezierBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"BezierBy");
mt["clone"]=static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::clone);
mt["reverse"]=static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::BezierBy::*)(cocos2d::Node*)>(&cocos2d::BezierBy::startWithTarget);
mt["update"]=static_cast<void(cocos2d::BezierBy::*)(float)>(&cocos2d::BezierBy::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::BezierBy::*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierBy::initWithDuration);
}
static void RegisterLuaBezierTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::BezierTo,cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"BezierTo");
mt["startWithTarget"]=static_cast<void(cocos2d::BezierTo::*)(cocos2d::Node*)>(&cocos2d::BezierTo::startWithTarget);
mt["clone"]=static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::clone);
mt["reverse"]=static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::reverse);
mt["initWithDuration"]=static_cast<bool(cocos2d::BezierTo::*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierTo::initWithDuration);
}
static void RegisterLuaScaleTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ScaleTo");
mt["clone"]=static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::clone);
mt["reverse"]=static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::ScaleTo::*)(cocos2d::Node*)>(&cocos2d::ScaleTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::ScaleTo::*)(float)>(&cocos2d::ScaleTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::ScaleTo::*)(float,float,float)>(&cocos2d::ScaleTo::initWithDuration),static_cast<bool(cocos2d::ScaleTo::*)(float,float)>(&cocos2d::ScaleTo::initWithDuration),static_cast<bool(cocos2d::ScaleTo::*)(float,float,float,float)>(&cocos2d::ScaleTo::initWithDuration);
mt["new"]=static_cast<cocos2d::ScaleTo*(*)(float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float,float,float)>(&cocos2d::ScaleTo::create);
}
static void RegisterLuaScaleBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ScaleBy,cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ScaleBy");
mt["startWithTarget"]=static_cast<void(cocos2d::ScaleBy::*)(cocos2d::Node*)>(&cocos2d::ScaleBy::startWithTarget);
mt["clone"]=static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::clone);
mt["reverse"]=static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::reverse);
mt["new"]=static_cast<cocos2d::ScaleBy*(*)(float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float,float,float)>(&cocos2d::ScaleBy::create);
}
static void RegisterLuaBlink(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Blink,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Blink");
mt["clone"]=static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::clone);
mt["reverse"]=static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::reverse);
mt["update"]=static_cast<void(cocos2d::Blink::*)(float)>(&cocos2d::Blink::update);
mt["startWithTarget"]=static_cast<void(cocos2d::Blink::*)(cocos2d::Node*)>(&cocos2d::Blink::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Blink::*)()>(&cocos2d::Blink::stop);
mt["initWithDuration"]=static_cast<bool(cocos2d::Blink::*)(float,int)>(&cocos2d::Blink::initWithDuration);
mt["new"]=static_cast<cocos2d::Blink*(*)(float,int)>(&cocos2d::Blink::create);
}
static void RegisterLuaFadeTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeTo");
mt["clone"]=static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::clone);
mt["reverse"]=static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::FadeTo::*)(cocos2d::Node*)>(&cocos2d::FadeTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::FadeTo::*)(float)>(&cocos2d::FadeTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::FadeTo::*)(float,uint8_t)>(&cocos2d::FadeTo::initWithDuration);
mt["new"]=static_cast<cocos2d::FadeTo*(*)(float,uint8_t)>(&cocos2d::FadeTo::create);
}
static void RegisterLuaFadeIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeIn,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeIn");
mt["startWithTarget"]=static_cast<void(cocos2d::FadeIn::*)(cocos2d::Node*)>(&cocos2d::FadeIn::startWithTarget);
mt["clone"]=static_cast<cocos2d::FadeIn*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::clone);
mt["reverse"]=static_cast<cocos2d::FadeTo*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::reverse);
mt["setReverseAction"]=static_cast<void(cocos2d::FadeIn::*)(cocos2d::FadeTo*)>(&cocos2d::FadeIn::setReverseAction);
mt["new"]=static_cast<cocos2d::FadeIn*(*)(float)>(&cocos2d::FadeIn::create);
}
static void RegisterLuaFadeOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeOut,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeOut");
mt["startWithTarget"]=static_cast<void(cocos2d::FadeOut::*)(cocos2d::Node*)>(&cocos2d::FadeOut::startWithTarget);
mt["clone"]=static_cast<cocos2d::FadeOut*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::clone);
mt["reverse"]=static_cast<cocos2d::FadeTo*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::reverse);
mt["setReverseAction"]=static_cast<void(cocos2d::FadeOut::*)(cocos2d::FadeTo*)>(&cocos2d::FadeOut::setReverseAction);
mt["new"]=static_cast<cocos2d::FadeOut*(*)(float)>(&cocos2d::FadeOut::create);
}
static void RegisterLuaTintTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TintTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TintTo");
mt["clone"]=static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::clone);
mt["reverse"]=static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::TintTo::*)(cocos2d::Node*)>(&cocos2d::TintTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::TintTo::*)(float)>(&cocos2d::TintTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::TintTo::*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::initWithDuration);
mt["new"]=static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create);
}
static void RegisterLuaTintBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TintBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TintBy");
mt["clone"]=static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::clone);
mt["reverse"]=static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::TintBy::*)(cocos2d::Node*)>(&cocos2d::TintBy::startWithTarget);
mt["update"]=static_cast<void(cocos2d::TintBy::*)(float)>(&cocos2d::TintBy::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::TintBy::*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::initWithDuration);
mt["new"]=static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create);
}
static void RegisterLuaDelayTime(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::DelayTime,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"DelayTime");
mt["update"]=static_cast<void(cocos2d::DelayTime::*)(float)>(&cocos2d::DelayTime::update);
mt["reverse"]=static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::reverse);
mt["clone"]=static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::clone);
mt["new"]=static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create);
}
static void RegisterLuaAnimate(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Animate,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Animate");
mt["setAnimation"]=static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation);
mt["getAnimation"]=static_cast<const cocos2d::Animation*(cocos2d::Animate::*)()const>(&cocos2d::Animate::getAnimation),static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation);
mt["getCurrentFrameIndex"]=static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex);
mt["clone"]=static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::clone);
mt["reverse"]=static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::Animate::*)(cocos2d::Node*)>(&cocos2d::Animate::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::Animate::*)()>(&cocos2d::Animate::stop);
mt["update"]=static_cast<void(cocos2d::Animate::*)(float)>(&cocos2d::Animate::update);
mt["initWithAnimation"]=static_cast<bool(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::initWithAnimation);
mt["new"]=static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create);
}
static void RegisterLuaTargetedAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TargetedAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TargetedAction");
mt["setForcedTarget"]=static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget);
mt["getForcedTarget"]=static_cast<const cocos2d::Node*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::getForcedTarget),static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget);
mt["clone"]=static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::clone);
mt["reverse"]=static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::stop);
mt["update"]=static_cast<void(cocos2d::TargetedAction::*)(float)>(&cocos2d::TargetedAction::update);
mt["initWithTarget"]=static_cast<bool(cocos2d::TargetedAction::*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::initWithTarget);
mt["new"]=static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create);
}
static void RegisterLuaActionFloat(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionFloat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionFloat");
mt["startWithTarget"]=static_cast<void(cocos2d::ActionFloat::*)(cocos2d::Node*)>(&cocos2d::ActionFloat::startWithTarget);
mt["update"]=static_cast<void(cocos2d::ActionFloat::*)(float)>(&cocos2d::ActionFloat::update);
mt["reverse"]=static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::reverse);
mt["clone"]=static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::clone);
mt["initWithDuration"]=static_cast<bool(cocos2d::ActionFloat::*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::initWithDuration);
mt["new"]=static_cast<cocos2d::ActionFloat*(*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::create);
}
static void RegisterLuaEventKeyboard(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventKeyboard,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventKeyboard");
}
static void RegisterLuaProperties(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Properties>(lua.get_or("cc",lua.create_named_table("cc")),"Properties");
mt["getNextProperty"]=static_cast<const char*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextProperty);
mt["getNextNamespace"]=static_cast<cocos2d::Properties*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextNamespace);
mt["rewind"]=static_cast<void(cocos2d::Properties::*)()>(&cocos2d::Properties::rewind);
mt["getNamespace"]=sol::overload(static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getNamespace),[](cocos2d::Properties* obj,const char* arg0){return obj->getNamespace(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getNamespace(arg0,arg1);},[](cocos2d::Properties* obj,const char* arg0,bool arg1,bool arg2){return obj->getNamespace(arg0,arg1,arg2);});
mt["getId"]=static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getId);
mt["exists"]=static_cast<bool(cocos2d::Properties::*)(const char*)const>(&cocos2d::Properties::exists);
mt["getType"]=sol::overload([](cocos2d::Properties* obj){return obj->getType();},[](cocos2d::Properties* obj,const char* arg0){return obj->getType(arg0);});
mt["getString"]=sol::overload([](cocos2d::Properties* obj){return obj->getString();},[](cocos2d::Properties* obj,const char* arg0){return obj->getString(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getString(arg0,arg1);});
mt["setString"]=static_cast<bool(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setString);
mt["getBool"]=sol::overload([](cocos2d::Properties* obj){return obj->getBool();},[](cocos2d::Properties* obj,const char* arg0){return obj->getBool(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getBool(arg0,arg1);});
mt["getInt"]=sol::overload([](cocos2d::Properties* obj){return obj->getInt();},[](cocos2d::Properties* obj,const char* arg0){return obj->getInt(arg0);});
mt["getFloat"]=sol::overload([](cocos2d::Properties* obj){return obj->getFloat();},[](cocos2d::Properties* obj,const char* arg0){return obj->getFloat(arg0);});
mt["getLong"]=sol::overload([](cocos2d::Properties* obj){return obj->getLong();},[](cocos2d::Properties* obj,const char* arg0){return obj->getLong(arg0);});
mt["getMat4"]=static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Mat4*)const>(&cocos2d::Properties::getMat4);
mt["getVec2"]=static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec2*)const>(&cocos2d::Properties::getVec2);
mt["getVec3"]=static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getVec3);
mt["getVec4"]=static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getVec4);
mt["getQuaternionFromAxisAngle"]=static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Quaternion*)const>(&cocos2d::Properties::getQuaternionFromAxisAngle);
mt["getColor"]=static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getColor),static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getColor);
mt["getPath"]=static_cast<bool(cocos2d::Properties::*)(const char*,std::string*)const>(&cocos2d::Properties::getPath);
mt["getVariable"]=sol::overload([](cocos2d::Properties* obj,const char* arg0){return obj->getVariable(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getVariable(arg0,arg1);});
mt["setVariable"]=static_cast<void(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setVariable);
mt["parseVec2"]=static_cast<bool(*)(const char*,cocos2d::Vec2*)>(&cocos2d::Properties::parseVec2);
mt["parseVec3"]=static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseVec3);
mt["parseVec4"]=static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseVec4);
mt["parseAxisAngle"]=static_cast<bool(*)(const char*,cocos2d::Quaternion*)>(&cocos2d::Properties::parseAxisAngle);
mt["parseColor"]=static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseColor),static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseColor);
}
static void RegisterLuaUserDefault(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::UserDefault>(lua.get_or("cc",lua.create_named_table("cc")),"UserDefault");
mt["getBoolForKey"]=static_cast<bool(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::getBoolForKey),static_cast<bool(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getBoolForKey);
mt["getIntegerForKey"]=static_cast<int(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::getIntegerForKey),static_cast<int(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getIntegerForKey);
mt["getLargeIntForKey"]=static_cast<int64_t(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::getLargeIntForKey),static_cast<int64_t(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getLargeIntForKey);
mt["getFloatForKey"]=static_cast<float(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::getFloatForKey),static_cast<float(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getFloatForKey);
mt["getDoubleForKey"]=static_cast<double(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::getDoubleForKey),static_cast<double(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getDoubleForKey);
mt["getStringForKey"]=static_cast<std::string(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::getStringForKey),static_cast<std::string(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getStringForKey);
mt["setBoolForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::setBoolForKey);
mt["setIntegerForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::setIntegerForKey);
mt["setLargeIntForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::setLargeIntForKey);
mt["setFloatForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::setFloatForKey);
mt["setDoubleForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::setDoubleForKey);
mt["setStringForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::setStringForKey);
mt["flush"]=static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::flush);
mt["deleteValueForKey"]=static_cast<void(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::deleteValueForKey);
mt["Clear"]=static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::Clear);
mt["setEncryptEnabled"]=static_cast<void(cocos2d::UserDefault::*)(bool,cxx17::string_view,cxx17::string_view)>(&cocos2d::UserDefault::setEncryptEnabled);
mt["getInstance"]=static_cast<cocos2d::UserDefault*(*)()>(&cocos2d::UserDefault::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::UserDefault::destroyInstance);
}
static void RegisterLuaFileUtils(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FileUtils>(lua.get_or("cc",lua.create_named_table("cc")),"FileUtils");
mt["purgeCachedEntries"]=static_cast<void(cocos2d::FileUtils::*)()>(&cocos2d::FileUtils::purgeCachedEntries);
mt["getStringFromFile"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::string)>)const>(&cocos2d::FileUtils::getStringFromFile),static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getStringFromFile);
mt["fullPathForFilename"]=static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::fullPathForFilename);
mt["loadFilenameLookup"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::loadFilenameLookupDictionaryFromFile);
mt["setFilenameLookupDictionary"]=static_cast<void(cocos2d::FileUtils::*)(const cocos2d::ValueMap&)>(&cocos2d::FileUtils::setFilenameLookupDictionary);
mt["fullPathFromRelativeFile"]=static_cast<std::string(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::fullPathFromRelativeFile);
mt["setSearchResolutionsOrder"]=static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchResolutionsOrder);
mt["addSearchResolutionsOrder"]=sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchResolutionsOrder(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchResolutionsOrder(arg0,arg1);});
mt["getSearchResolutionsOrder"]=static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchResolutionsOrder);
mt["setSearchPaths"]=static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchPaths);
mt["getDefaultResourceRootPath"]=static_cast<const std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getDefaultResourceRootPath);
mt["setDefaultResourceRootPath"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setDefaultResourceRootPath);
mt["addSearchPath"]=sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchPath(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchPath(arg0,arg1);});
mt["getSearchPaths"]=static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchPaths);
mt["getOriginalSearchPaths"]=static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getOriginalSearchPaths);
mt["getWritablePath"]=static_cast<std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getWritablePath);
mt["setWritablePath"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setWritablePath);
mt["setPopupNotify"]=static_cast<void(cocos2d::FileUtils::*)(bool)>(&cocos2d::FileUtils::setPopupNotify);
mt["isPopupNotify"]=static_cast<bool(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::isPopupNotify);
mt["getValueMapFromFile"]=static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueMapFromFile);
mt["getValueMapFromData"]=static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const char*,int)const>(&cocos2d::FileUtils::getValueMapFromData);
mt["writeToFile"]=static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeToFile);
mt["writeStringToFile"]=static_cast<void(cocos2d::FileUtils::*)(std::string,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeStringToFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::writeStringToFile);
mt["writeValueMapToFile"]=static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueMap,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueMapToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeValueMapToFile);
mt["writeValueVectorToFile"]=static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueVector,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueVectorToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueVector&,const std::string&)const>(&cocos2d::FileUtils::writeValueVectorToFile);
mt["getValueVectorFromFile"]=static_cast<cocos2d::ValueVector(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueVectorFromFile);
mt["isFileExist"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isFileExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExist);
mt["getFileExtension"]=static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileExtension);
mt["isAbsolutePath"]=static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isAbsolutePath);
mt["isDirectoryExist"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isDirectoryExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExist);
mt["createDirectory"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::createDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::createDirectory);
mt["removeDirectory"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeDirectory);
mt["removeFile"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeFile);
mt["renameFile"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile);
mt["getFileSize"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (long long)>)const>(&cocos2d::FileUtils::getFileSize),static_cast<int64_t(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileSize);
mt["listFiles"]=static_cast<std::vector<std::string>(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::listFiles);
mt["listFilesAsync"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesAsync);
mt["listFilesRecursively"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::vector<std::string>*)const>(&cocos2d::FileUtils::listFilesRecursively);
mt["listFilesRecursivelyAsync"]=static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesRecursivelyAsync);
mt["getNewFilename"]=static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getNewFilename);
mt["isFileExistInternal"]=static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExistInternal);
mt["isDirectoryExistInternal"]=static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExistInternal);
mt["getInstance"]=static_cast<cocos2d::FileUtils*(*)()>(&cocos2d::FileUtils::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::FileUtils::destroyInstance);
mt["writeBinaryToFile"]=static_cast<bool(*)(const void*,size_t,const std::string&)>(&cocos2d::FileUtils::writeBinaryToFile);
mt["getFileShortName"]=static_cast<std::string(*)(const std::string&)>(&cocos2d::FileUtils::getFileShortName);
}
static void RegisterLuaEventAcceleration(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventAcceleration,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventAcceleration");
}
static void RegisterLuaEventCustom(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventCustom");
mt["getEventName"]=static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName);
}
static void RegisterLuaEventDispatcher(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventDispatcher,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventDispatcher");
mt["addEventListenerWithSceneGraphPriority"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority);
mt["addEventListenerWithFixedPriority"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority);
mt["removeEventListener"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*)>(&cocos2d::EventDispatcher::removeEventListener);
mt["removeEventListenersForType"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener::Type)>(&cocos2d::EventDispatcher::removeEventListenersForType);
mt["removeEventListenersForTarget"]=sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->removeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->removeEventListenersForTarget(arg0,arg1);});
mt["removeCustomEventListeners"]=static_cast<void(cocos2d::EventDispatcher::*)(const std::string&)>(&cocos2d::EventDispatcher::removeCustomEventListeners);
mt["removeAllEventListeners"]=static_cast<void(cocos2d::EventDispatcher::*)()>(&cocos2d::EventDispatcher::removeAllEventListeners);
mt["pauseEventListenersForTarget"]=sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->pauseEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->pauseEventListenersForTarget(arg0,arg1);});
mt["resumeEventListenersForTarget"]=sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->resumeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->resumeEventListenersForTarget(arg0,arg1);});
mt["setPriority"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::setPriority);
mt["setEnabled"]=static_cast<void(cocos2d::EventDispatcher::*)(bool)>(&cocos2d::EventDispatcher::setEnabled);
mt["isEnabled"]=static_cast<bool(cocos2d::EventDispatcher::*)()const>(&cocos2d::EventDispatcher::isEnabled);
mt["dispatchEvent"]=static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::Event*)>(&cocos2d::EventDispatcher::dispatchEvent);
mt["dispatchCustomEvent"]=sol::overload([](cocos2d::EventDispatcher* obj,const std::string& arg0){return obj->dispatchCustomEvent(arg0);},[](cocos2d::EventDispatcher* obj,const std::string& arg0,void* arg1){return obj->dispatchCustomEvent(arg0,arg1);});
mt["hasEventListener"]=static_cast<bool(cocos2d::EventDispatcher::*)(const cocos2d::EventListener::ListenerID&)const>(&cocos2d::EventDispatcher::hasEventListener);
}
static void RegisterLuaEventFocus(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventFocus,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventFocus");
}
static void RegisterLuaEventListenerAcceleration(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerAcceleration,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerAcceleration");
mt["clone"]=static_cast<cocos2d::EventListenerAcceleration*(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::clone);
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::checkAvailable);
mt["init"]=static_cast<bool(cocos2d::EventListenerAcceleration::*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::init);
}
static void RegisterLuaEventListenerFocus(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerFocus,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerFocus");
mt["clone"]=static_cast<cocos2d::EventListenerFocus*(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::clone);
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::checkAvailable);
mt["init"]=static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::init);
}
static void RegisterLuaEventListenerKeyboard(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerKeyboard,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerKeyboard");
mt["clone"]=static_cast<cocos2d::EventListenerKeyboard*(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::clone);
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::checkAvailable);
mt["init"]=static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::init);
}
static void RegisterLuaEventMouse(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventMouse,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventMouse");
mt["setScrollData"]=static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setScrollData);
mt["getScrollX"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollX);
mt["getScrollY"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollY);
mt["setCursorPosition"]=static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setCursorPosition);
mt["setMouseButton"]=static_cast<void(cocos2d::EventMouse::*)(cocos2d::EventMouse::MouseButton)>(&cocos2d::EventMouse::setMouseButton);
mt["getMouseButton"]=static_cast<cocos2d::EventMouse::MouseButton(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getMouseButton);
mt["getCursorX"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorX);
mt["getCursorY"]=static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorY);
mt["getLocation"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocation);
mt["getPreviousLocation"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocation);
mt["getStartLocation"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocation);
mt["getDelta"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getDelta);
mt["getLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocationInView);
mt["getPreviousLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocationInView);
mt["getStartLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocationInView);
}
static void RegisterLuaEventListenerMouse(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerMouse,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerMouse");
mt["clone"]=static_cast<cocos2d::EventListenerMouse*(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::clone);
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::checkAvailable);
mt["init"]=static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::init);
}
static void RegisterLuaEventListenerController(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerController");
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable);
mt["clone"]=static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone);
}
static void RegisterLuaEventListenerTouchOneByOne(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerTouchOneByOne,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerTouchOneByOne");
mt["setSwallowTouches"]=static_cast<void(cocos2d::EventListenerTouchOneByOne::*)(bool)>(&cocos2d::EventListenerTouchOneByOne::setSwallowTouches);
mt["isSwallowTouches"]=static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::isSwallowTouches);
mt["clone"]=static_cast<cocos2d::EventListenerTouchOneByOne*(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::clone);
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::checkAvailable);
mt["init"]=static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::init);
}
static void RegisterLuaEventListenerTouchAllAtOnce(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventListenerTouchAllAtOnce,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventListenerTouchAllAtOnce");
mt["clone"]=static_cast<cocos2d::EventListenerTouchAllAtOnce*(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::clone);
mt["checkAvailable"]=static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::checkAvailable);
mt["init"]=static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::init);
}
static void RegisterLuaEventController(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EventController");
mt["getControllerEventType"]=static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType);
mt["getController"]=static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController);
mt["getKeyCode"]=static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode);
mt["setKeyCode"]=static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode);
mt["setConnectStatus"]=static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus);
mt["isConnected"]=static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected);
}
static void RegisterLuaActionCamera(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionCamera");
mt["startWithTarget"]=static_cast<void(cocos2d::ActionCamera::*)(cocos2d::Node*)>(&cocos2d::ActionCamera::startWithTarget);
mt["reverse"]=static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::reverse);
mt["clone"]=static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::clone);
mt["setEye"]=static_cast<void(cocos2d::ActionCamera::*)(float,float,float)>(&cocos2d::ActionCamera::setEye),static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setEye);
mt["getEye"]=static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getEye);
mt["setCenter"]=static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setCenter);
mt["getCenter"]=static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getCenter);
mt["setUp"]=static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setUp);
mt["getUp"]=static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getUp);
}
static void RegisterLuaOrbitCamera(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::OrbitCamera,cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"OrbitCamera");
mt["clone"]=static_cast<cocos2d::OrbitCamera*(cocos2d::OrbitCamera::*)()const>(&cocos2d::OrbitCamera::clone);
mt["startWithTarget"]=static_cast<void(cocos2d::OrbitCamera::*)(cocos2d::Node*)>(&cocos2d::OrbitCamera::startWithTarget);
mt["update"]=static_cast<void(cocos2d::OrbitCamera::*)(float)>(&cocos2d::OrbitCamera::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::OrbitCamera::*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::initWithDuration);
mt["new"]=static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create);
}
static void RegisterLuaCardinalSplineTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CardinalSplineTo");
mt["initWithDuration"]=static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration);
mt["updatePosition"]=static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition);
mt["getPoints"]=static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints);
mt["clone"]=static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::clone);
mt["reverse"]=static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::CardinalSplineTo::*)(float)>(&cocos2d::CardinalSplineTo::update);
}
static void RegisterLuaCardinalSplineBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CardinalSplineBy");
mt["startWithTarget"]=static_cast<void(cocos2d::CardinalSplineBy::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineBy::startWithTarget);
mt["updatePosition"]=static_cast<void(cocos2d::CardinalSplineBy::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineBy::updatePosition);
mt["clone"]=static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::clone);
mt["reverse"]=static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::reverse);
}
static void RegisterLuaCatmullRomTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CatmullRomTo,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CatmullRomTo");
mt["initWithDuration"]=static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration);
mt["clone"]=static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::clone);
mt["reverse"]=static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::reverse);
}
static void RegisterLuaCatmullRomBy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CatmullRomBy,cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CatmullRomBy");
mt["initWithDuration"]=static_cast<bool(cocos2d::CatmullRomBy::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::initWithDuration);
mt["clone"]=static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::clone);
mt["reverse"]=static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::reverse);
}
static void RegisterLuaActionEase(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionEase");
mt["getInnerAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::getInnerAction);
mt["startWithTarget"]=static_cast<void(cocos2d::ActionEase::*)(cocos2d::Node*)>(&cocos2d::ActionEase::startWithTarget);
mt["stop"]=static_cast<void(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::stop);
mt["update"]=static_cast<void(cocos2d::ActionEase::*)(float)>(&cocos2d::ActionEase::update);
mt["initWithAction"]=static_cast<bool(cocos2d::ActionEase::*)(cocos2d::ActionInterval*)>(&cocos2d::ActionEase::initWithAction);
}
static void RegisterLuaEaseRateAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseRateAction");
mt["setRate"]=static_cast<void(cocos2d::EaseRateAction::*)(float)>(&cocos2d::EaseRateAction::setRate);
mt["getRate"]=static_cast<float(cocos2d::EaseRateAction::*)()const>(&cocos2d::EaseRateAction::getRate);
mt["initWithAction"]=static_cast<bool(cocos2d::EaseRateAction::*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::initWithAction);
mt["new"]=static_cast<cocos2d::EaseRateAction*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::create);
}
static void RegisterLuaEaseExponentialIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseExponentialIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseExponentialIn");
mt["clone"]=static_cast<cocos2d::EaseExponentialIn*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseExponentialIn::*)(float)>(&cocos2d::EaseExponentialIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::reverse);
mt["new"]=static_cast<cocos2d::EaseExponentialIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialIn::create);
}
static void RegisterLuaEaseExponentialOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseExponentialOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseExponentialOut");
mt["clone"]=static_cast<cocos2d::EaseExponentialOut*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseExponentialOut::*)(float)>(&cocos2d::EaseExponentialOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::reverse);
mt["new"]=static_cast<cocos2d::EaseExponentialOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialOut::create);
}
static void RegisterLuaEaseExponentialInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseExponentialInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseExponentialInOut");
mt["clone"]=static_cast<cocos2d::EaseExponentialInOut*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseExponentialInOut::*)(float)>(&cocos2d::EaseExponentialInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseExponentialInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialInOut::create);
}
static void RegisterLuaEaseSineIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseSineIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseSineIn");
mt["clone"]=static_cast<cocos2d::EaseSineIn*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseSineIn::*)(float)>(&cocos2d::EaseSineIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::reverse);
mt["new"]=static_cast<cocos2d::EaseSineIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineIn::create);
}
static void RegisterLuaEaseSineOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseSineOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseSineOut");
mt["clone"]=static_cast<cocos2d::EaseSineOut*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseSineOut::*)(float)>(&cocos2d::EaseSineOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::reverse);
mt["new"]=static_cast<cocos2d::EaseSineOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineOut::create);
}
static void RegisterLuaEaseSineInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseSineInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseSineInOut");
mt["clone"]=static_cast<cocos2d::EaseSineInOut*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseSineInOut::*)(float)>(&cocos2d::EaseSineInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseSineInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineInOut::create);
}
static void RegisterLuaEaseBounce(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBounce,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBounce");
}
static void RegisterLuaEaseBounceIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBounceIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBounceIn");
mt["clone"]=static_cast<cocos2d::EaseBounceIn*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseBounceIn::*)(float)>(&cocos2d::EaseBounceIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::reverse);
mt["new"]=static_cast<cocos2d::EaseBounceIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceIn::create);
}
static void RegisterLuaEaseBounceOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBounceOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBounceOut");
mt["clone"]=static_cast<cocos2d::EaseBounceOut*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseBounceOut::*)(float)>(&cocos2d::EaseBounceOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::reverse);
mt["new"]=static_cast<cocos2d::EaseBounceOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceOut::create);
}
static void RegisterLuaEaseBounceInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBounceInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBounceInOut");
mt["clone"]=static_cast<cocos2d::EaseBounceInOut*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseBounceInOut::*)(float)>(&cocos2d::EaseBounceInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseBounceInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceInOut::create);
}
static void RegisterLuaEaseBackIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBackIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBackIn");
mt["clone"]=static_cast<cocos2d::EaseBackIn*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseBackIn::*)(float)>(&cocos2d::EaseBackIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::reverse);
mt["new"]=static_cast<cocos2d::EaseBackIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackIn::create);
}
static void RegisterLuaEaseBackOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBackOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBackOut");
mt["clone"]=static_cast<cocos2d::EaseBackOut*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseBackOut::*)(float)>(&cocos2d::EaseBackOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::reverse);
mt["new"]=static_cast<cocos2d::EaseBackOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackOut::create);
}
static void RegisterLuaEaseBackInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBackInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBackInOut");
mt["clone"]=static_cast<cocos2d::EaseBackInOut*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseBackInOut::*)(float)>(&cocos2d::EaseBackInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseBackInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackInOut::create);
}
static void RegisterLuaEaseQuadraticActionIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuadraticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuadraticActionIn");
mt["clone"]=static_cast<cocos2d::EaseQuadraticActionIn*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuadraticActionIn::*)(float)>(&cocos2d::EaseQuadraticActionIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::reverse);
mt["new"]=static_cast<cocos2d::EaseQuadraticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionIn::create);
}
static void RegisterLuaEaseQuadraticActionOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuadraticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuadraticActionOut");
mt["clone"]=static_cast<cocos2d::EaseQuadraticActionOut*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuadraticActionOut::*)(float)>(&cocos2d::EaseQuadraticActionOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::reverse);
mt["new"]=static_cast<cocos2d::EaseQuadraticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionOut::create);
}
static void RegisterLuaEaseQuadraticActionInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuadraticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuadraticActionInOut");
mt["clone"]=static_cast<cocos2d::EaseQuadraticActionInOut*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuadraticActionInOut::*)(float)>(&cocos2d::EaseQuadraticActionInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseQuadraticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionInOut::create);
}
static void RegisterLuaEaseQuarticActionIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuarticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuarticActionIn");
mt["clone"]=static_cast<cocos2d::EaseQuarticActionIn*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuarticActionIn::*)(float)>(&cocos2d::EaseQuarticActionIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::reverse);
mt["new"]=static_cast<cocos2d::EaseQuarticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionIn::create);
}
static void RegisterLuaEaseQuarticActionOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuarticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuarticActionOut");
mt["clone"]=static_cast<cocos2d::EaseQuarticActionOut*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuarticActionOut::*)(float)>(&cocos2d::EaseQuarticActionOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::reverse);
mt["new"]=static_cast<cocos2d::EaseQuarticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionOut::create);
}
static void RegisterLuaEaseQuarticActionInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuarticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuarticActionInOut");
mt["clone"]=static_cast<cocos2d::EaseQuarticActionInOut*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuarticActionInOut::*)(float)>(&cocos2d::EaseQuarticActionInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseQuarticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionInOut::create);
}
static void RegisterLuaEaseQuinticActionIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuinticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuinticActionIn");
mt["clone"]=static_cast<cocos2d::EaseQuinticActionIn*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuinticActionIn::*)(float)>(&cocos2d::EaseQuinticActionIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::reverse);
mt["new"]=static_cast<cocos2d::EaseQuinticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionIn::create);
}
static void RegisterLuaEaseQuinticActionOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuinticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuinticActionOut");
mt["clone"]=static_cast<cocos2d::EaseQuinticActionOut*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuinticActionOut::*)(float)>(&cocos2d::EaseQuinticActionOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::reverse);
mt["new"]=static_cast<cocos2d::EaseQuinticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionOut::create);
}
static void RegisterLuaEaseQuinticActionInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseQuinticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseQuinticActionInOut");
mt["clone"]=static_cast<cocos2d::EaseQuinticActionInOut*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseQuinticActionInOut::*)(float)>(&cocos2d::EaseQuinticActionInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseQuinticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionInOut::create);
}
static void RegisterLuaEaseCircleActionIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseCircleActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseCircleActionIn");
mt["clone"]=static_cast<cocos2d::EaseCircleActionIn*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseCircleActionIn::*)(float)>(&cocos2d::EaseCircleActionIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::reverse);
mt["new"]=static_cast<cocos2d::EaseCircleActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionIn::create);
}
static void RegisterLuaEaseCircleActionOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseCircleActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseCircleActionOut");
mt["clone"]=static_cast<cocos2d::EaseCircleActionOut*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseCircleActionOut::*)(float)>(&cocos2d::EaseCircleActionOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::reverse);
mt["new"]=static_cast<cocos2d::EaseCircleActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionOut::create);
}
static void RegisterLuaEaseCircleActionInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseCircleActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseCircleActionInOut");
mt["clone"]=static_cast<cocos2d::EaseCircleActionInOut*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseCircleActionInOut::*)(float)>(&cocos2d::EaseCircleActionInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseCircleActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionInOut::create);
}
static void RegisterLuaEaseCubicActionIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseCubicActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseCubicActionIn");
mt["clone"]=static_cast<cocos2d::EaseCubicActionIn*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseCubicActionIn::*)(float)>(&cocos2d::EaseCubicActionIn::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::reverse);
mt["new"]=static_cast<cocos2d::EaseCubicActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionIn::create);
}
static void RegisterLuaEaseCubicActionOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseCubicActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseCubicActionOut");
mt["clone"]=static_cast<cocos2d::EaseCubicActionOut*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseCubicActionOut::*)(float)>(&cocos2d::EaseCubicActionOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::reverse);
mt["new"]=static_cast<cocos2d::EaseCubicActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionOut::create);
}
static void RegisterLuaEaseCubicActionInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseCubicActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseCubicActionInOut");
mt["clone"]=static_cast<cocos2d::EaseCubicActionInOut*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseCubicActionInOut::*)(float)>(&cocos2d::EaseCubicActionInOut::update);
mt["reverse"]=static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseCubicActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionInOut::create);
}
static void RegisterLuaEaseIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseIn,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseIn");
mt["clone"]=static_cast<cocos2d::EaseIn*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseIn::*)(float)>(&cocos2d::EaseIn::update);
mt["reverse"]=static_cast<cocos2d::EaseRateAction*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::reverse);
mt["new"]=static_cast<cocos2d::EaseIn*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseIn::create);
}
static void RegisterLuaEaseOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseOut,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseOut");
mt["clone"]=static_cast<cocos2d::EaseOut*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseOut::*)(float)>(&cocos2d::EaseOut::update);
mt["reverse"]=static_cast<cocos2d::EaseRateAction*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::reverse);
mt["new"]=static_cast<cocos2d::EaseOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseOut::create);
}
static void RegisterLuaEaseInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseInOut,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseInOut");
mt["clone"]=static_cast<cocos2d::EaseInOut*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseInOut::*)(float)>(&cocos2d::EaseInOut::update);
mt["reverse"]=static_cast<cocos2d::EaseRateAction*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::reverse);
mt["new"]=static_cast<cocos2d::EaseInOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseInOut::create);
}
static void RegisterLuaEaseElastic(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseElastic");
mt["getPeriod"]=static_cast<float(cocos2d::EaseElastic::*)()const>(&cocos2d::EaseElastic::getPeriod);
mt["setPeriod"]=static_cast<void(cocos2d::EaseElastic::*)(float)>(&cocos2d::EaseElastic::setPeriod);
mt["initWithAction"]=sol::overload([](cocos2d::EaseElastic* obj,cocos2d::ActionInterval* arg0){return obj->initWithAction(arg0);},[](cocos2d::EaseElastic* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->initWithAction(arg0,arg1);});
}
static void RegisterLuaEaseElasticIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseElasticIn,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseElasticIn");
mt["clone"]=static_cast<cocos2d::EaseElasticIn*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::clone);
mt["update"]=static_cast<void(cocos2d::EaseElasticIn::*)(float)>(&cocos2d::EaseElasticIn::update);
mt["reverse"]=static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::reverse);
mt["new"]=sol::overload([](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);});
}
static void RegisterLuaEaseElasticOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseElasticOut,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseElasticOut");
mt["clone"]=static_cast<cocos2d::EaseElasticOut*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseElasticOut::*)(float)>(&cocos2d::EaseElasticOut::update);
mt["reverse"]=static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::reverse);
mt["new"]=sol::overload([](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);});
}
static void RegisterLuaEaseElasticInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseElasticInOut,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseElasticInOut");
mt["clone"]=static_cast<cocos2d::EaseElasticInOut*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::clone);
mt["update"]=static_cast<void(cocos2d::EaseElasticInOut::*)(float)>(&cocos2d::EaseElasticInOut::update);
mt["reverse"]=static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::reverse);
mt["new"]=sol::overload([](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);});
}
static void RegisterLuaEaseBezierAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::EaseBezierAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"EaseBezierAction");
mt["update"]=static_cast<void(cocos2d::EaseBezierAction::*)(float)>(&cocos2d::EaseBezierAction::update);
mt["clone"]=static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::clone);
mt["reverse"]=static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::reverse);
mt["setBezierParamer"]=static_cast<void(cocos2d::EaseBezierAction::*)(float,float,float,float)>(&cocos2d::EaseBezierAction::setBezierParamer);
mt["new"]=static_cast<cocos2d::EaseBezierAction*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBezierAction::create);
}
static void RegisterLuaActionInstant(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionInstant");
mt["clone"]=static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::clone);
mt["reverse"]=static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::ActionInstant::*)(cocos2d::Node*)>(&cocos2d::ActionInstant::startWithTarget);
mt["isDone"]=static_cast<bool(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::isDone);
mt["step"]=static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::step);
mt["update"]=static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::update);
}
static void RegisterLuaShow(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Show,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Show");
mt["update"]=static_cast<void(cocos2d::Show::*)(float)>(&cocos2d::Show::update);
mt["reverse"]=static_cast<cocos2d::ActionInstant*(cocos2d::Show::*)()const>(&cocos2d::Show::reverse);
mt["clone"]=static_cast<cocos2d::Show*(cocos2d::Show::*)()const>(&cocos2d::Show::clone);
mt["new"]=static_cast<cocos2d::Show*(*)()>(&cocos2d::Show::create);
}
static void RegisterLuaHide(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Hide,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Hide");
mt["update"]=static_cast<void(cocos2d::Hide::*)(float)>(&cocos2d::Hide::update);
mt["reverse"]=static_cast<cocos2d::ActionInstant*(cocos2d::Hide::*)()const>(&cocos2d::Hide::reverse);
mt["clone"]=static_cast<cocos2d::Hide*(cocos2d::Hide::*)()const>(&cocos2d::Hide::clone);
mt["new"]=static_cast<cocos2d::Hide*(*)()>(&cocos2d::Hide::create);
}
static void RegisterLuaToggleVisibility(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ToggleVisibility,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ToggleVisibility");
mt["update"]=static_cast<void(cocos2d::ToggleVisibility::*)(float)>(&cocos2d::ToggleVisibility::update);
mt["reverse"]=static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::reverse);
mt["clone"]=static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::clone);
mt["new"]=static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create);
}
static void RegisterLuaRemoveSelf(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::RemoveSelf,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"RemoveSelf");
mt["update"]=static_cast<void(cocos2d::RemoveSelf::*)(float)>(&cocos2d::RemoveSelf::update);
mt["clone"]=static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::clone);
mt["reverse"]=static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::reverse);
mt["init"]=static_cast<bool(cocos2d::RemoveSelf::*)(bool)>(&cocos2d::RemoveSelf::init);
mt["new"]=sol::overload([](cocos2d::RemoveSelf* obj){return obj->create();},[](cocos2d::RemoveSelf* obj,bool arg0){return obj->create(arg0);});
}
static void RegisterLuaFlipX(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FlipX,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FlipX");
mt["update"]=static_cast<void(cocos2d::FlipX::*)(float)>(&cocos2d::FlipX::update);
mt["reverse"]=static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::reverse);
mt["clone"]=static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::clone);
mt["initWithFlipX"]=static_cast<bool(cocos2d::FlipX::*)(bool)>(&cocos2d::FlipX::initWithFlipX);
mt["new"]=static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create);
}
static void RegisterLuaFlipY(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FlipY,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FlipY");
mt["update"]=static_cast<void(cocos2d::FlipY::*)(float)>(&cocos2d::FlipY::update);
mt["reverse"]=static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::reverse);
mt["clone"]=static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::clone);
mt["initWithFlipY"]=static_cast<bool(cocos2d::FlipY::*)(bool)>(&cocos2d::FlipY::initWithFlipY);
mt["new"]=static_cast<cocos2d::FlipY*(*)(bool)>(&cocos2d::FlipY::create);
}
static void RegisterLuaPlace(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Place,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Place");
mt["update"]=static_cast<void(cocos2d::Place::*)(float)>(&cocos2d::Place::update);
mt["reverse"]=static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::reverse);
mt["clone"]=static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::clone);
mt["initWithPosition"]=static_cast<bool(cocos2d::Place::*)(const cocos2d::Vec2&)>(&cocos2d::Place::initWithPosition);
mt["new"]=static_cast<cocos2d::Place*(*)(const cocos2d::Vec2&)>(&cocos2d::Place::create);
}
static void RegisterLuaCallFunc(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CallFunc,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CallFunc");
mt["execute"]=static_cast<void(cocos2d::CallFunc::*)()>(&cocos2d::CallFunc::execute);
mt["update"]=static_cast<void(cocos2d::CallFunc::*)(float)>(&cocos2d::CallFunc::update);
mt["reverse"]=static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::reverse);
mt["clone"]=static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::clone);
}
static void RegisterLuaGridAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"GridAction");
mt["getGrid"]=static_cast<cocos2d::GridBase*(cocos2d::GridAction::*)()>(&cocos2d::GridAction::getGrid);
mt["clone"]=static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::clone);
mt["reverse"]=static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::GridAction::*)(cocos2d::Node*)>(&cocos2d::GridAction::startWithTarget);
mt["initWithDuration"]=static_cast<bool(cocos2d::GridAction::*)(float,const cocos2d::Size&)>(&cocos2d::GridAction::initWithDuration);
}
static void RegisterLuaGrid3DAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Grid3DAction");
mt["getGrid"]=static_cast<cocos2d::GridBase*(cocos2d::Grid3DAction::*)()>(&cocos2d::Grid3DAction::getGrid);
mt["clone"]=static_cast<cocos2d::Grid3DAction*(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::clone);
mt["getGridRect"]=static_cast<cocos2d::Rect(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::getGridRect);
}
static void RegisterLuaTiledGrid3DAction(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TiledGrid3DAction");
mt["getGrid"]=static_cast<cocos2d::GridBase*(cocos2d::TiledGrid3DAction::*)()>(&cocos2d::TiledGrid3DAction::getGrid);
mt["clone"]=static_cast<cocos2d::TiledGrid3DAction*(cocos2d::TiledGrid3DAction::*)()const>(&cocos2d::TiledGrid3DAction::clone);
}
static void RegisterLuaStopGrid(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::StopGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"StopGrid");
mt["startWithTarget"]=static_cast<void(cocos2d::StopGrid::*)(cocos2d::Node*)>(&cocos2d::StopGrid::startWithTarget);
mt["clone"]=static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::clone);
mt["reverse"]=static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::reverse);
mt["new"]=static_cast<cocos2d::StopGrid*(*)()>(&cocos2d::StopGrid::create);
}
static void RegisterLuaReuseGrid(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ReuseGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ReuseGrid");
mt["startWithTarget"]=static_cast<void(cocos2d::ReuseGrid::*)(cocos2d::Node*)>(&cocos2d::ReuseGrid::startWithTarget);
mt["clone"]=static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::clone);
mt["reverse"]=static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::reverse);
mt["initWithTimes"]=static_cast<bool(cocos2d::ReuseGrid::*)(int)>(&cocos2d::ReuseGrid::initWithTimes);
mt["new"]=static_cast<cocos2d::ReuseGrid*(*)(int)>(&cocos2d::ReuseGrid::create);
}
static void RegisterLuaWaves3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Waves3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Waves3D");
mt["getAmplitude"]=static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::Waves3D*(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::clone);
mt["update"]=static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Waves3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::initWithDuration);
mt["new"]=static_cast<cocos2d::Waves3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::create);
}
static void RegisterLuaFlipX3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FlipX3D");
mt["clone"]=static_cast<cocos2d::FlipX3D*(cocos2d::FlipX3D::*)()const>(&cocos2d::FlipX3D::clone);
mt["update"]=static_cast<void(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::initWithDuration);
mt["initWithSize"]=static_cast<bool(cocos2d::FlipX3D::*)(const cocos2d::Size&,float)>(&cocos2d::FlipX3D::initWithSize);
mt["new"]=static_cast<cocos2d::FlipX3D*(*)(float)>(&cocos2d::FlipX3D::create);
}
static void RegisterLuaFlipY3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FlipY3D,cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FlipY3D");
mt["update"]=static_cast<void(cocos2d::FlipY3D::*)(float)>(&cocos2d::FlipY3D::update);
mt["clone"]=static_cast<cocos2d::FlipY3D*(cocos2d::FlipY3D::*)()const>(&cocos2d::FlipY3D::clone);
mt["new"]=static_cast<cocos2d::FlipY3D*(*)(float)>(&cocos2d::FlipY3D::create);
}
static void RegisterLuaLens3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Lens3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Lens3D");
mt["getLensEffect"]=static_cast<float(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getLensEffect);
mt["setLensEffect"]=static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::setLensEffect);
mt["setConcave"]=static_cast<void(cocos2d::Lens3D::*)(bool)>(&cocos2d::Lens3D::setConcave);
mt["getPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getPosition);
mt["setPosition"]=static_cast<void(cocos2d::Lens3D::*)(const cocos2d::Vec2&)>(&cocos2d::Lens3D::setPosition);
mt["clone"]=static_cast<cocos2d::Lens3D*(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::clone);
mt["update"]=static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Lens3D::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::initWithDuration);
mt["new"]=static_cast<cocos2d::Lens3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::create);
}
static void RegisterLuaRipple3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Ripple3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Ripple3D");
mt["getPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getPosition);
mt["setPosition"]=static_cast<void(cocos2d::Ripple3D::*)(const cocos2d::Vec2&)>(&cocos2d::Ripple3D::setPosition);
mt["getAmplitude"]=static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::Ripple3D*(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::clone);
mt["update"]=static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Ripple3D::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::initWithDuration);
mt["new"]=static_cast<cocos2d::Ripple3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::create);
}
static void RegisterLuaShaky3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Shaky3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Shaky3D");
mt["clone"]=static_cast<cocos2d::Shaky3D*(cocos2d::Shaky3D::*)()const>(&cocos2d::Shaky3D::clone);
mt["update"]=static_cast<void(cocos2d::Shaky3D::*)(float)>(&cocos2d::Shaky3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Shaky3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::initWithDuration);
mt["new"]=static_cast<cocos2d::Shaky3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::create);
}
static void RegisterLuaLiquid(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Liquid,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Liquid");
mt["getAmplitude"]=static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::Liquid*(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::clone);
mt["update"]=static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Liquid::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::initWithDuration);
mt["new"]=static_cast<cocos2d::Liquid*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::create);
}
static void RegisterLuaWaves(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Waves,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Waves");
mt["getAmplitude"]=static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::Waves*(cocos2d::Waves::*)()const>(&cocos2d::Waves::clone);
mt["update"]=static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Waves::*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::initWithDuration);
mt["new"]=static_cast<cocos2d::Waves*(*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::create);
}
static void RegisterLuaTwirl(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Twirl,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Twirl");
mt["getPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getPosition);
mt["setPosition"]=static_cast<void(cocos2d::Twirl::*)(const cocos2d::Vec2&)>(&cocos2d::Twirl::setPosition);
mt["getAmplitude"]=static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::Twirl*(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::clone);
mt["update"]=static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::Twirl::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::initWithDuration);
mt["new"]=static_cast<cocos2d::Twirl*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::create);
}
static void RegisterLuaActionManager(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionManager,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionManager");
mt["addAction"]=static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*,cocos2d::Node*,bool)>(&cocos2d::ActionManager::addAction);
mt["removeAllActions"]=static_cast<void(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::removeAllActions);
mt["removeAllActionsFromTarget"]=static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsFromTarget);
mt["removeAction"]=static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*)>(&cocos2d::ActionManager::removeAction);
mt["removeActionByTag"]=static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionByTag);
mt["removeAllActionsByTag"]=static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsByTag);
mt["removeActionsByFlags"]=static_cast<void(cocos2d::ActionManager::*)(unsigned int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionsByFlags);
mt["getActionByTag"]=static_cast<cocos2d::Action*(cocos2d::ActionManager::*)(int,const cocos2d::Node*)const>(&cocos2d::ActionManager::getActionByTag);
mt["getNumberOfRunningActionsInTarget"]=static_cast<ssize_t(cocos2d::ActionManager::*)(const cocos2d::Node*)const>(&cocos2d::ActionManager::getNumberOfRunningActionsInTarget);
mt["getNumberOfRunningActions"]=static_cast<ssize_t(cocos2d::ActionManager::*)()const>(&cocos2d::ActionManager::getNumberOfRunningActions);
mt["getNumberOfRunningActionsInTargetByTag"]=static_cast<size_t(cocos2d::ActionManager::*)(const cocos2d::Node*,int)>(&cocos2d::ActionManager::getNumberOfRunningActionsInTargetByTag);
mt["pauseTarget"]=static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::pauseTarget);
mt["resumeTarget"]=static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::resumeTarget);
mt["pauseAllRunningActions"]=static_cast<cocos2d::Vector<cocos2d::Node *>(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::pauseAllRunningActions);
mt["resumeTargets"]=static_cast<void(cocos2d::ActionManager::*)(const cocos2d::Vector<cocos2d::Node *>&)>(&cocos2d::ActionManager::resumeTargets);
mt["update"]=static_cast<void(cocos2d::ActionManager::*)(float)>(&cocos2d::ActionManager::update);
}
static void RegisterLuaPageTurn3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::PageTurn3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"PageTurn3D");
mt["getGrid"]=static_cast<cocos2d::GridBase*(cocos2d::PageTurn3D::*)()>(&cocos2d::PageTurn3D::getGrid);
mt["clone"]=static_cast<cocos2d::PageTurn3D*(cocos2d::PageTurn3D::*)()const>(&cocos2d::PageTurn3D::clone);
mt["update"]=static_cast<void(cocos2d::PageTurn3D::*)(float)>(&cocos2d::PageTurn3D::update);
mt["new"]=static_cast<cocos2d::PageTurn3D*(*)(float,const cocos2d::Size&)>(&cocos2d::PageTurn3D::create);
}
static void RegisterLuaProgressTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ProgressTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ProgressTo");
mt["clone"]=static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::clone);
mt["reverse"]=static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::ProgressTo::*)(cocos2d::Node*)>(&cocos2d::ProgressTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::ProgressTo::*)(float)>(&cocos2d::ProgressTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::ProgressTo::*)(float,float)>(&cocos2d::ProgressTo::initWithDuration);
mt["new"]=static_cast<cocos2d::ProgressTo*(*)(float,float)>(&cocos2d::ProgressTo::create);
}
static void RegisterLuaProgressFromTo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ProgressFromTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ProgressFromTo");
mt["clone"]=static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::clone);
mt["reverse"]=static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::reverse);
mt["startWithTarget"]=static_cast<void(cocos2d::ProgressFromTo::*)(cocos2d::Node*)>(&cocos2d::ProgressFromTo::startWithTarget);
mt["update"]=static_cast<void(cocos2d::ProgressFromTo::*)(float)>(&cocos2d::ProgressFromTo::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::ProgressFromTo::*)(float,float,float)>(&cocos2d::ProgressFromTo::initWithDuration);
mt["new"]=static_cast<cocos2d::ProgressFromTo*(*)(float,float,float)>(&cocos2d::ProgressFromTo::create);
}
static void RegisterLuaShakyTiles3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ShakyTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ShakyTiles3D");
mt["clone"]=static_cast<cocos2d::ShakyTiles3D*(cocos2d::ShakyTiles3D::*)()const>(&cocos2d::ShakyTiles3D::clone);
mt["update"]=static_cast<void(cocos2d::ShakyTiles3D::*)(float)>(&cocos2d::ShakyTiles3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::ShakyTiles3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShakyTiles3D::initWithDuration);
mt["new"]=static_cast<cocos2d::ShakyTiles3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShakyTiles3D::create);
}
static void RegisterLuaShatteredTiles3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ShatteredTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ShatteredTiles3D");
mt["clone"]=static_cast<cocos2d::ShatteredTiles3D*(cocos2d::ShatteredTiles3D::*)()const>(&cocos2d::ShatteredTiles3D::clone);
mt["update"]=static_cast<void(cocos2d::ShatteredTiles3D::*)(float)>(&cocos2d::ShatteredTiles3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::ShatteredTiles3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShatteredTiles3D::initWithDuration);
mt["new"]=static_cast<cocos2d::ShatteredTiles3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShatteredTiles3D::create);
}
static void RegisterLuaShuffleTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ShuffleTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ShuffleTiles");
mt["getDelta"]=static_cast<cocos2d::Size(cocos2d::ShuffleTiles::*)(const cocos2d::Size&)const>(&cocos2d::ShuffleTiles::getDelta);
mt["startWithTarget"]=static_cast<void(cocos2d::ShuffleTiles::*)(cocos2d::Node*)>(&cocos2d::ShuffleTiles::startWithTarget);
mt["update"]=static_cast<void(cocos2d::ShuffleTiles::*)(float)>(&cocos2d::ShuffleTiles::update);
mt["clone"]=static_cast<cocos2d::ShuffleTiles*(cocos2d::ShuffleTiles::*)()const>(&cocos2d::ShuffleTiles::clone);
mt["initWithDuration"]=static_cast<bool(cocos2d::ShuffleTiles::*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::initWithDuration);
mt["new"]=static_cast<cocos2d::ShuffleTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::create);
}
static void RegisterLuaFadeOutTRTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeOutTRTiles");
mt["testFunc"]=static_cast<float(cocos2d::FadeOutTRTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutTRTiles::testFunc);
mt["turnOnTile"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOnTile);
mt["turnOffTile"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOffTile);
mt["transformTile"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutTRTiles::transformTile);
mt["update"]=static_cast<void(cocos2d::FadeOutTRTiles::*)(float)>(&cocos2d::FadeOutTRTiles::update);
mt["clone"]=static_cast<cocos2d::FadeOutTRTiles*(cocos2d::FadeOutTRTiles::*)()const>(&cocos2d::FadeOutTRTiles::clone);
mt["new"]=static_cast<cocos2d::FadeOutTRTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutTRTiles::create);
}
static void RegisterLuaFadeOutBLTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeOutBLTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeOutBLTiles");
mt["testFunc"]=static_cast<float(cocos2d::FadeOutBLTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutBLTiles::testFunc);
mt["clone"]=static_cast<cocos2d::FadeOutBLTiles*(cocos2d::FadeOutBLTiles::*)()const>(&cocos2d::FadeOutBLTiles::clone);
mt["new"]=static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create);
}
static void RegisterLuaFadeOutUpTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeOutUpTiles");
mt["transformTile"]=static_cast<void(cocos2d::FadeOutUpTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutUpTiles::transformTile);
mt["clone"]=static_cast<cocos2d::FadeOutUpTiles*(cocos2d::FadeOutUpTiles::*)()const>(&cocos2d::FadeOutUpTiles::clone);
mt["testFunc"]=static_cast<float(cocos2d::FadeOutUpTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutUpTiles::testFunc);
mt["new"]=static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create);
}
static void RegisterLuaFadeOutDownTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FadeOutDownTiles,cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FadeOutDownTiles");
mt["clone"]=static_cast<cocos2d::FadeOutDownTiles*(cocos2d::FadeOutDownTiles::*)()const>(&cocos2d::FadeOutDownTiles::clone);
mt["testFunc"]=static_cast<float(cocos2d::FadeOutDownTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutDownTiles::testFunc);
mt["new"]=static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create);
}
static void RegisterLuaTurnOffTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TurnOffTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TurnOffTiles");
mt["turnOnTile"]=static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile);
mt["turnOffTile"]=static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile);
mt["clone"]=static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone);
mt["startWithTarget"]=static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget);
mt["update"]=static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::TurnOffTiles::*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::initWithDuration);
mt["new"]=static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create);
}
static void RegisterLuaWavesTiles3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::WavesTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"WavesTiles3D");
mt["getAmplitude"]=static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::WavesTiles3D*(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::clone);
mt["update"]=static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::WavesTiles3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::initWithDuration);
mt["new"]=static_cast<cocos2d::WavesTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::create);
}
static void RegisterLuaJumpTiles3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::JumpTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"JumpTiles3D");
mt["getAmplitude"]=static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude);
mt["setAmplitude"]=static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude);
mt["getAmplitudeRate"]=static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate);
mt["setAmplitudeRate"]=static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate);
mt["clone"]=static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone);
mt["update"]=static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update);
mt["initWithDuration"]=static_cast<bool(cocos2d::JumpTiles3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::initWithDuration);
mt["new"]=static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create);
}
static void RegisterLuaSplitRows(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SplitRows,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SplitRows");
mt["clone"]=static_cast<cocos2d::SplitRows*(cocos2d::SplitRows::*)()const>(&cocos2d::SplitRows::clone);
mt["update"]=static_cast<void(cocos2d::SplitRows::*)(float)>(&cocos2d::SplitRows::update);
mt["startWithTarget"]=static_cast<void(cocos2d::SplitRows::*)(cocos2d::Node*)>(&cocos2d::SplitRows::startWithTarget);
mt["initWithDuration"]=static_cast<bool(cocos2d::SplitRows::*)(float,unsigned int)>(&cocos2d::SplitRows::initWithDuration);
mt["new"]=static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create);
}
static void RegisterLuaSplitCols(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SplitCols,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SplitCols");
mt["clone"]=static_cast<cocos2d::SplitCols*(cocos2d::SplitCols::*)()const>(&cocos2d::SplitCols::clone);
mt["update"]=static_cast<void(cocos2d::SplitCols::*)(float)>(&cocos2d::SplitCols::update);
mt["startWithTarget"]=static_cast<void(cocos2d::SplitCols::*)(cocos2d::Node*)>(&cocos2d::SplitCols::startWithTarget);
mt["initWithDuration"]=static_cast<bool(cocos2d::SplitCols::*)(float,unsigned int)>(&cocos2d::SplitCols::initWithDuration);
mt["new"]=static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create);
}
static void RegisterLuaActionTween(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ActionTween,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ActionTween");
mt["startWithTarget"]=static_cast<void(cocos2d::ActionTween::*)(cocos2d::Node*)>(&cocos2d::ActionTween::startWithTarget);
mt["update"]=static_cast<void(cocos2d::ActionTween::*)(float)>(&cocos2d::ActionTween::update);
mt["reverse"]=static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::reverse);
mt["clone"]=static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::clone);
mt["initWithDuration"]=static_cast<bool(cocos2d::ActionTween::*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::initWithDuration);
mt["new"]=static_cast<cocos2d::ActionTween*(*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::create);
}
static void RegisterLuaAtlasNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"AtlasNode");
mt["updateAtlasValues"]=static_cast<void(cocos2d::AtlasNode::*)()>(&cocos2d::AtlasNode::updateAtlasValues);
mt["draw"]=static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AtlasNode::draw);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Texture2D*)>(&cocos2d::AtlasNode::setTexture);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::isOpacityModifyRGB);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::AtlasNode::*)(bool)>(&cocos2d::AtlasNode::setOpacityModifyRGB);
mt["getColor"]=static_cast<const cocos2d::Color3B&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getColor);
mt["setColor"]=static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::Color3B&)>(&cocos2d::AtlasNode::setColor);
mt["setOpacity"]=static_cast<void(cocos2d::AtlasNode::*)(uint8_t)>(&cocos2d::AtlasNode::setOpacity);
mt["setBlendFunc"]=static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::AtlasNode::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getBlendFunc);
mt["setTextureAtlas"]=static_cast<void(cocos2d::AtlasNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::AtlasNode::setTextureAtlas);
mt["getTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTextureAtlas);
mt["setQuadsToDraw"]=static_cast<void(cocos2d::AtlasNode::*)(ssize_t)>(&cocos2d::AtlasNode::setQuadsToDraw);
mt["getQuadsToDraw"]=static_cast<size_t(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getQuadsToDraw);
mt["setProgramState"]=sol::overload([](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);});
mt["initWithTileFile"]=static_cast<bool(cocos2d::AtlasNode::*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::initWithTileFile);
mt["initWithTexture"]=static_cast<bool(cocos2d::AtlasNode::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::AtlasNode::initWithTexture);
mt["new"]=static_cast<cocos2d::AtlasNode*(*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::create);
}
static void RegisterLuaClippingNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ClippingNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ClippingNode");
mt["getStencil"]=static_cast<cocos2d::Node*(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getStencil);
mt["setStencil"]=static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::setStencil);
mt["hasContent"]=static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::hasContent);
mt["getAlphaThreshold"]=static_cast<float(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getAlphaThreshold);
mt["setAlphaThreshold"]=static_cast<void(cocos2d::ClippingNode::*)(float)>(&cocos2d::ClippingNode::setAlphaThreshold);
mt["isInverted"]=static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::isInverted);
mt["setInverted"]=static_cast<void(cocos2d::ClippingNode::*)(bool)>(&cocos2d::ClippingNode::setInverted);
mt["visit"]=static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingNode::visit);
mt["setCameraMask"]=sol::overload([](cocos2d::ClippingNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ClippingNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);});
mt["init"]=static_cast<bool(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::init),static_cast<bool(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::init);
mt["new"]=static_cast<cocos2d::ClippingNode*(*)(cocos2d::Node*)>(&cocos2d::ClippingNode::create),static_cast<cocos2d::ClippingNode*(*)()>(&cocos2d::ClippingNode::create);
}
static void RegisterLuaClippingRectangleNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ClippingRectangleNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ClippingRectangleNode");
mt["getClippingRegion"]=static_cast<const cocos2d::Rect&(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::getClippingRegion);
mt["setClippingRegion"]=static_cast<void(cocos2d::ClippingRectangleNode::*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::setClippingRegion);
mt["isClippingEnabled"]=static_cast<bool(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::isClippingEnabled);
mt["setClippingEnabled"]=static_cast<void(cocos2d::ClippingRectangleNode::*)(bool)>(&cocos2d::ClippingRectangleNode::setClippingEnabled);
mt["visit"]=static_cast<void(cocos2d::ClippingRectangleNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingRectangleNode::visit);
mt["new"]=static_cast<cocos2d::ClippingRectangleNode*(*)()>(&cocos2d::ClippingRectangleNode::create),static_cast<cocos2d::ClippingRectangleNode*(*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::create);
}
static void RegisterLuaDrawNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::DrawNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"DrawNode");
mt["drawPoint"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoint);
mt["drawLine"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawLine);
mt["drawRect"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect);
mt["drawCircle"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle);
mt["drawQuadBezier"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawQuadBezier);
mt["drawCubicBezier"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCubicBezier);
mt["drawDot"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawDot);
mt["drawSolidRect"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidRect);
mt["drawSolidCircle"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle);
mt["drawSegment"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSegment);
mt["drawTriangle"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawTriangle);
mt["clear"]=static_cast<void(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::clear);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::getBlendFunc);
mt["setBlendFunc"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::DrawNode::setBlendFunc);
mt["draw"]=static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::draw);
mt["visit"]=static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::visit);
mt["setLineWidth"]=static_cast<void(cocos2d::DrawNode::*)(float)>(&cocos2d::DrawNode::setLineWidth);
mt["getLineWidth"]=static_cast<float(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::getLineWidth);
mt["setIsolated"]=static_cast<void(cocos2d::DrawNode::*)(bool)>(&cocos2d::DrawNode::setIsolated);
mt["isIsolated"]=static_cast<bool(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::isIsolated);
mt["init"]=static_cast<bool(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::init);
mt["new"]=sol::overload([](cocos2d::DrawNode* obj){return obj->create();},[](cocos2d::DrawNode* obj,float arg0){return obj->create(arg0);});
}
static void RegisterLuaLabel(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Label,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::LabelProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"Label");
mt["setTTFConfig"]=static_cast<bool(cocos2d::Label::*)(const cocos2d::TTFConfig&)>(&cocos2d::Label::setTTFConfig);
mt["getTTFConfig"]=static_cast<const cocos2d::TTFConfig&(cocos2d::Label::*)()const>(&cocos2d::Label::getTTFConfig);
mt["setBMFontFilePath"]=sol::overload([](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2,float arg3){return obj->setBMFontFilePath(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0){return obj->setBMFontFilePath(arg0);},[](cocos2d::Label* obj,const std::string& arg0,float arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);});
mt["getBMFontFilePath"]=static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontFilePath);
mt["setCharMap"]=static_cast<bool(cocos2d::Label::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setCharMap);
mt["setSystemFontName"]=static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setSystemFontName);
mt["getSystemFontName"]=static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontName);
mt["setSystemFontSize"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setSystemFontSize);
mt["getSystemFontSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontSize);
mt["requestSystemFontRefresh"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::requestSystemFontRefresh);
mt["setString"]=static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setString);
mt["getString"]=static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getString);
mt["getStringNumLines"]=static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringNumLines);
mt["getStringLength"]=static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringLength);
mt["setTextColor"]=static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::setTextColor);
mt["getTextColor"]=static_cast<const cocos2d::Color4B&(cocos2d::Label::*)()const>(&cocos2d::Label::getTextColor);
mt["enableShadow"]=sol::overload([](cocos2d::Label* obj){return obj->enableShadow();},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableShadow(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){return obj->enableShadow(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1,int arg2){return obj->enableShadow(arg0,arg1,arg2);});
mt["enableOutline"]=sol::overload([](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableOutline(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,int arg1){return obj->enableOutline(arg0,arg1);});
mt["enableGlow"]=static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::enableGlow);
mt["enableItalics"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableItalics);
mt["enableBold"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableBold);
mt["enableUnderline"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableUnderline);
mt["enableStrikethrough"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableStrikethrough);
mt["disableEffect"]=static_cast<void(cocos2d::Label::*)(cocos2d::LabelEffect)>(&cocos2d::Label::disableEffect),static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::disableEffect);
mt["isShadowEnabled"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isShadowEnabled);
mt["getShadowOffset"]=static_cast<cocos2d::Size(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowOffset);
mt["getShadowBlurRadius"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowBlurRadius);
mt["getShadowColor"]=static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowColor);
mt["getOutlineSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getOutlineSize);
mt["getLabelEffectType"]=static_cast<cocos2d::LabelEffect(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelEffectType);
mt["getEffectColor"]=static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getEffectColor);
mt["setAlignment"]=static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::Label::setAlignment),static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setAlignment);
mt["getTextAlignment"]=static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getTextAlignment);
mt["setHorizontalAlignment"]=static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setHorizontalAlignment);
mt["getHorizontalAlignment"]=static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getHorizontalAlignment);
mt["setVerticalAlignment"]=static_cast<void(cocos2d::Label::*)(cocos2d::TextVAlignment)>(&cocos2d::Label::setVerticalAlignment);
mt["getVerticalAlignment"]=static_cast<cocos2d::TextVAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getVerticalAlignment);
mt["setLineBreakWithoutSpace"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setLineBreakWithoutSpace);
mt["setMaxLineWidth"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setMaxLineWidth);
mt["getMaxLineWidth"]=static_cast<float(cocos2d::Label::*)()>(&cocos2d::Label::getMaxLineWidth);
mt["setBMFontSize"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setBMFontSize);
mt["getBMFontSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontSize);
mt["enableWrap"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::enableWrap);
mt["isWrapEnabled"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isWrapEnabled);
mt["setOverflow"]=static_cast<void(cocos2d::Label::*)(cocos2d::Label::Overflow)>(&cocos2d::Label::setOverflow);
mt["getOverflow"]=static_cast<cocos2d::Label::Overflow(cocos2d::Label::*)()const>(&cocos2d::Label::getOverflow);
mt["setWidth"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setWidth);
mt["getWidth"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getWidth);
mt["setHeight"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setHeight);
mt["getHeight"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getHeight);
mt["setDimensions"]=static_cast<void(cocos2d::Label::*)(float,float)>(&cocos2d::Label::setDimensions);
mt["getDimensions"]=static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getDimensions);
mt["updateContent"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::updateContent);
mt["getLetter"]=static_cast<cocos2d::Sprite*(cocos2d::Label::*)(int)>(&cocos2d::Label::getLetter);
mt["setClipMarginEnabled"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setClipMarginEnabled);
mt["isClipMarginEnabled"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isClipMarginEnabled);
mt["setLineHeight"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineHeight);
mt["getLineHeight"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineHeight);
mt["setLineSpacing"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineSpacing);
mt["getLineSpacing"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineSpacing);
mt["getLabelType"]=static_cast<cocos2d::Label::LabelType(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelType);
mt["getRenderingFontSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getRenderingFontSize);
mt["setAdditionalKerning"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setAdditionalKerning);
mt["getAdditionalKerning"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getAdditionalKerning);
mt["setProgramState"]=sol::overload([](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);});
mt["getFontAtlas"]=static_cast<cocos2d::FontAtlas*(cocos2d::Label::*)()>(&cocos2d::Label::getFontAtlas);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::Label::*)()const>(&cocos2d::Label::getBlendFunc);
mt["setBlendFunc"]=static_cast<void(cocos2d::Label::*)(const cocos2d::BlendFunc&)>(&cocos2d::Label::setBlendFunc);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isOpacityModifyRGB);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setOpacityModifyRGB);
mt["updateDisplayedColor"]=static_cast<void(cocos2d::Label::*)(const cocos2d::Color3B&)>(&cocos2d::Label::updateDisplayedColor);
mt["updateDisplayedOpacity"]=static_cast<void(cocos2d::Label::*)(uint8_t)>(&cocos2d::Label::updateDisplayedOpacity);
mt["getDescription"]=static_cast<std::string(cocos2d::Label::*)()const>(&cocos2d::Label::getDescription);
mt["getContentSize"]=static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getContentSize);
mt["getBoundingBox"]=static_cast<cocos2d::Rect(cocos2d::Label::*)()const>(&cocos2d::Label::getBoundingBox);
mt["visit"]=static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::visit);
mt["draw"]=static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::draw);
mt["setCameraMask"]=sol::overload([](cocos2d::Label* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Label* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);});
mt["removeAllChildrenWithCleanup"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::removeAllChildrenWithCleanup);
mt["removeChild"]=sol::overload([](cocos2d::Label* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Label* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);});
mt["setGlobalZOrder"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setGlobalZOrder);
mt["initWithTTF"]=sol::overload([](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1){return obj->initWithTTF(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2){return obj->initWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2,int arg3){return obj->initWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithTTF(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithTTF(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["new"]=static_cast<cocos2d::Label*(*)()>(&cocos2d::Label::create);
mt["createWithSystemFont"]=sol::overload([](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithSystemFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->createWithSystemFont(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4,arg5);});
mt["createWithBMFont"]=sol::overload(static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const cocos2d::Rect&,bool)>(&cocos2d::Label::createWithBMFont),[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->createWithBMFont(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2){return obj->createWithBMFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2,int arg3){return obj->createWithBMFont(arg0,arg1,arg2,arg3);},static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const std::string&)>(&cocos2d::Label::createWithBMFont));
mt["createWithCharMap"]=static_cast<cocos2d::Label*(*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&)>(&cocos2d::Label::createWithCharMap);
}
static void RegisterLuaLabelAtlas(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::LabelAtlas,cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::LabelProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"LabelAtlas");
mt["initWithString"]=static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::initWithString);
mt["setString"]=static_cast<void(cocos2d::LabelAtlas::*)(const std::string&)>(&cocos2d::LabelAtlas::setString);
mt["getString"]=static_cast<const std::string&(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getString);
mt["updateAtlasValues"]=static_cast<void(cocos2d::LabelAtlas::*)()>(&cocos2d::LabelAtlas::updateAtlasValues);
mt["getDescription"]=static_cast<std::string(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getDescription);
mt["new"]=static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::create);
}
static void RegisterLuaTouch(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Touch,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Touch");
mt["getLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocation);
mt["getPreviousLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocation);
mt["getStartLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocation);
mt["getDelta"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getDelta);
mt["getLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocationInView);
mt["getPreviousLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocationInView);
mt["getStartLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocationInView);
mt["setTouchInfo"]=static_cast<void(cocos2d::Touch::*)(int,float,float,float,float)>(&cocos2d::Touch::setTouchInfo),static_cast<void(cocos2d::Touch::*)(int,float,float)>(&cocos2d::Touch::setTouchInfo);
mt["getId"]=static_cast<int(cocos2d::Touch::*)()const>(&cocos2d::Touch::getID);
mt["getCurrentForce"]=static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getCurrentForce);
mt["getMaxForce"]=static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getMaxForce);
}
static void RegisterLuaLayer(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Layer");
mt["getDescription"]=static_cast<std::string(cocos2d::Layer::*)()const>(&cocos2d::Layer::getDescription);
mt["init"]=static_cast<bool(cocos2d::Layer::*)()>(&cocos2d::Layer::init);
mt["SetTouchHandler"]=static_cast<void(cocos2d::Layer::*)(const std::function<bool (cocos2d::Layer *, cocos2d::EventTouch::EventCode, cocos2d::Touch *)>&)>(&cocos2d::Layer::SetTouchHandler);
mt["SetTouchesHandler"]=static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::EventTouch::EventCode, const std::vector<cocos2d::Touch *>&)>&)>(&cocos2d::Layer::SetTouchesHandler);
mt["SetKeyHandler"]=static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::EventKeyboard::KeyCode, bool)>&)>(&cocos2d::Layer::SetKeyHandler);
mt["SetAccelerationHandler"]=static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::Acceleration *)>&)>(&cocos2d::Layer::SetAccelerationHandler);
mt["new"]=static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create);
}
static void RegisterLuaLayerColor(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"LayerColor");
mt["changeWidth"]=static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeWidth);
mt["changeHeight"]=static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeHeight);
mt["changeWidthAndHeight"]=static_cast<void(cocos2d::LayerColor::*)(float,float)>(&cocos2d::LayerColor::changeWidthAndHeight);
mt["draw"]=static_cast<void(cocos2d::LayerColor::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerColor::draw);
mt["setContentSize"]=static_cast<void(cocos2d::LayerColor::*)(const cocos2d::Size&)>(&cocos2d::LayerColor::setContentSize);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::LayerColor::*)()const>(&cocos2d::LayerColor::getBlendFunc);
mt["setBlendFunc"]=static_cast<void(cocos2d::LayerColor::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerColor::setBlendFunc);
mt["init"]=static_cast<bool(cocos2d::LayerColor::*)()>(&cocos2d::LayerColor::init);
mt["initWithColor"]=static_cast<bool(cocos2d::LayerColor::*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::initWithColor),static_cast<bool(cocos2d::LayerColor::*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::initWithColor);
mt["new"]=static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)()>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::create);
}
static void RegisterLuaLayerGradient(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::LayerGradient,cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"LayerGradient");
mt["setCompressedInterpolation"]=static_cast<void(cocos2d::LayerGradient::*)(bool)>(&cocos2d::LayerGradient::setCompressedInterpolation);
mt["isCompressedInterpolation"]=static_cast<bool(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::isCompressedInterpolation);
mt["setStartColor"]=static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setStartColor);
mt["getStartColor"]=static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartColor);
mt["setEndColor"]=static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setEndColor);
mt["getEndColor"]=static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndColor);
mt["setStartOpacity"]=static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setStartOpacity);
mt["getStartOpacity"]=static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartOpacity);
mt["setEndOpacity"]=static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setEndOpacity);
mt["getEndOpacity"]=static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndOpacity);
mt["setVector"]=static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerGradient::setVector);
mt["getVector"]=static_cast<const cocos2d::Vec2&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getVector);
mt["getDescription"]=static_cast<std::string(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getDescription);
mt["init"]=static_cast<bool(cocos2d::LayerGradient::*)()>(&cocos2d::LayerGradient::init);
mt["initWithColor"]=static_cast<bool(cocos2d::LayerGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::initWithColor),static_cast<bool(cocos2d::LayerGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::initWithColor);
mt["new"]=static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)()>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::create);
}
static void RegisterLuaLayerRadialGradient(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::LayerRadialGradient,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"LayerRadialGradient");
mt["draw"]=static_cast<void(cocos2d::LayerRadialGradient::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerRadialGradient::draw);
mt["setContentSize"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Size&)>(&cocos2d::LayerRadialGradient::setContentSize);
mt["setStartOpacity"]=static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setStartOpacity);
mt["getStartOpacity"]=static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartOpacity);
mt["setEndOpacity"]=static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setEndOpacity);
mt["getEndOpacity"]=static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndOpacity);
mt["setRadius"]=static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setRadius);
mt["getRadius"]=static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getRadius);
mt["setCenter"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerRadialGradient::setCenter);
mt["getCenter"]=static_cast<cocos2d::Vec2(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getCenter);
mt["setExpand"]=static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setExpand);
mt["getExpand"]=static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getExpand);
mt["setStartColor"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setStartColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setStartColor);
mt["getStartColor"]=static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor);
mt["getStartColor3B"]=static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor3B);
mt["setEndColor"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setEndColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setEndColor);
mt["getEndColor"]=static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor);
mt["getEndColor3B"]=static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor3B);
mt["setBlendFunc"]=static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerRadialGradient::setBlendFunc);
mt["getBlendFunc"]=static_cast<cocos2d::BlendFunc(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getBlendFunc);
mt["initWithColor"]=static_cast<bool(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::initWithColor);
mt["new"]=static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create);
}
static void RegisterLuaLayerMultiplex(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::LayerMultiplex,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"LayerMultiplex");
mt["addLayer"]=static_cast<void(cocos2d::LayerMultiplex::*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::addLayer);
mt["switchTo"]=static_cast<void(cocos2d::LayerMultiplex::*)(int,bool)>(&cocos2d::LayerMultiplex::switchTo),static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchTo);
mt["switchToAndReleaseMe"]=static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchToAndReleaseMe);
mt["getDescription"]=static_cast<std::string(cocos2d::LayerMultiplex::*)()const>(&cocos2d::LayerMultiplex::getDescription);
mt["init"]=static_cast<bool(cocos2d::LayerMultiplex::*)()>(&cocos2d::LayerMultiplex::init);
mt["initWithArray"]=static_cast<bool(cocos2d::LayerMultiplex::*)(const cocos2d::Vector<cocos2d::Layer *>&)>(&cocos2d::LayerMultiplex::initWithArray);
}
static void RegisterLuaMenuItem(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItem");
mt["rect"]=static_cast<cocos2d::Rect(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::rect);
mt["activate"]=static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::activate);
mt["selected"]=static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::selected);
mt["unselected"]=static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::unselected);
mt["isEnabled"]=static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isEnabled);
mt["setEnabled"]=static_cast<void(cocos2d::MenuItem::*)(bool)>(&cocos2d::MenuItem::setEnabled);
mt["isSelected"]=static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isSelected);
mt["SetHandler"]=static_cast<void(cocos2d::MenuItem::*)(const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItem::SetHandler);
mt["getDescription"]=static_cast<std::string(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::getDescription);
}
static void RegisterLuaMenuItemLabel(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItemLabel");
mt["setString"]=static_cast<void(cocos2d::MenuItemLabel::*)(const std::string&)>(&cocos2d::MenuItemLabel::setString);
mt["getString"]=static_cast<std::string(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getString);
mt["getDisabledColor"]=static_cast<const cocos2d::Color3B&(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getDisabledColor);
mt["setDisabledColor"]=static_cast<void(cocos2d::MenuItemLabel::*)(const cocos2d::Color3B&)>(&cocos2d::MenuItemLabel::setDisabledColor);
mt["getLabel"]=static_cast<cocos2d::Node*(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getLabel);
mt["setLabel"]=static_cast<void(cocos2d::MenuItemLabel::*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::setLabel);
mt["activate"]=static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::activate);
mt["selected"]=static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::selected);
mt["unselected"]=static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::unselected);
mt["setEnabled"]=static_cast<void(cocos2d::MenuItemLabel::*)(bool)>(&cocos2d::MenuItemLabel::setEnabled);
mt["initWithLabel"]=static_cast<bool(cocos2d::MenuItemLabel::*)(cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemLabel::initWithLabel);
}
static void RegisterLuaMenuItemAtlasFont(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItemAtlasFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItemAtlasFont");
mt["initWithString"]=static_cast<bool(cocos2d::MenuItemAtlasFont::*)(const std::string&,const std::string&,int,int,char,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemAtlasFont::initWithString);
}
static void RegisterLuaMenuItemFont(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItemFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItemFont");
mt["setFontSizeObj"]=static_cast<void(cocos2d::MenuItemFont::*)(int)>(&cocos2d::MenuItemFont::setFontSizeObj);
mt["getFontSizeObj"]=static_cast<int(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontSizeObj);
mt["setFontNameObj"]=static_cast<void(cocos2d::MenuItemFont::*)(const std::string&)>(&cocos2d::MenuItemFont::setFontNameObj);
mt["getFontNameObj"]=static_cast<const std::string&(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontNameObj);
mt["initWithString"]=static_cast<bool(cocos2d::MenuItemFont::*)(const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemFont::initWithString);
mt["setFontSize"]=static_cast<void(*)(int)>(&cocos2d::MenuItemFont::setFontSize);
mt["getFontSize"]=static_cast<int(*)()>(&cocos2d::MenuItemFont::getFontSize);
mt["setFontName"]=static_cast<void(*)(const std::string&)>(&cocos2d::MenuItemFont::setFontName);
mt["getFontName"]=static_cast<const std::string&(*)()>(&cocos2d::MenuItemFont::getFontName);
}
static void RegisterLuaMenuItemSprite(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItemSprite");
mt["getNormalImage"]=static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getNormalImage);
mt["setNormalImage"]=static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setNormalImage);
mt["getSelectedImage"]=static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getSelectedImage);
mt["setSelectedImage"]=static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setSelectedImage);
mt["getDisabledImage"]=static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getDisabledImage);
mt["setDisabledImage"]=static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setDisabledImage);
mt["selected"]=static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::selected);
mt["unselected"]=static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::unselected);
mt["setEnabled"]=static_cast<void(cocos2d::MenuItemSprite::*)(bool)>(&cocos2d::MenuItemSprite::setEnabled);
mt["initWithNormalSprite"]=static_cast<bool(cocos2d::MenuItemSprite::*)(cocos2d::Node*,cocos2d::Node*,cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemSprite::initWithNormalSprite);
}
static void RegisterLuaMenuItemImage(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItemImage,cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItemImage");
mt["setNormalSpriteFrame"]=static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setNormalSpriteFrame);
mt["setSelectedSpriteFrame"]=static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setSelectedSpriteFrame);
mt["setDisabledSpriteFrame"]=static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setDisabledSpriteFrame);
mt["init"]=static_cast<bool(cocos2d::MenuItemImage::*)()>(&cocos2d::MenuItemImage::init);
mt["initWithNormalImage"]=static_cast<bool(cocos2d::MenuItemImage::*)(const std::string&,const std::string&,const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemImage::initWithNormalImage);
}
static void RegisterLuaMenuItemToggle(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MenuItemToggle,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"MenuItemToggle");
mt["addSubItem"]=static_cast<void(cocos2d::MenuItemToggle::*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::addSubItem);
mt["getSelectedItem"]=static_cast<cocos2d::MenuItem*(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::getSelectedItem);
mt["getSelectedIndex"]=static_cast<unsigned int(cocos2d::MenuItemToggle::*)()const>(&cocos2d::MenuItemToggle::getSelectedIndex);
mt["setSelectedIndex"]=static_cast<void(cocos2d::MenuItemToggle::*)(unsigned int)>(&cocos2d::MenuItemToggle::setSelectedIndex);
mt["setSubItems"]=static_cast<void(cocos2d::MenuItemToggle::*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::MenuItemToggle::setSubItems);
mt["activate"]=static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::activate);
mt["selected"]=static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::selected);
mt["unselected"]=static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::unselected);
mt["setEnabled"]=static_cast<void(cocos2d::MenuItemToggle::*)(bool)>(&cocos2d::MenuItemToggle::setEnabled);
mt["cleanup"]=static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::cleanup);
mt["initWithItem"]=static_cast<bool(cocos2d::MenuItemToggle::*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::initWithItem);
}
static void RegisterLuaMenu(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Menu,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Menu");
mt["alignItemsVertically"]=static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsVertically);
mt["alignItemsVerticallyWithPadding"]=static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsVerticallyWithPadding);
mt["alignItemsHorizontally"]=static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsHorizontally);
mt["alignItemsHorizontallyWithPadding"]=static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsHorizontallyWithPadding);
mt["isEnabled"]=static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isEnabled);
mt["setEnabled"]=static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setEnabled);
mt["removeChild"]=static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,bool)>(&cocos2d::Menu::removeChild);
mt["addChild"]=static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Menu::addChild);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isOpacityModifyRGB);
mt["getDescription"]=static_cast<std::string(cocos2d::Menu::*)()const>(&cocos2d::Menu::getDescription);
mt["init"]=static_cast<bool(cocos2d::Menu::*)()>(&cocos2d::Menu::init);
mt["initWithArray"]=static_cast<bool(cocos2d::Menu::*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::Menu::initWithArray);
}
static void RegisterLuaMotionStreak(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MotionStreak,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"MotionStreak");
mt["setPosition"]=static_cast<void(cocos2d::MotionStreak::*)(float,float)>(&cocos2d::MotionStreak::setPosition),static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak::setPosition);
mt["getPosition"]=static_cast<void(cocos2d::MotionStreak::*)(float*,float*)const>(&cocos2d::MotionStreak::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition);
mt["setPositionX"]=static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionX);
mt["setPositionY"]=static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionY);
mt["getPositionX"]=static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionX);
mt["getPositionY"]=static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionY);
mt["getPosition3D"]=static_cast<cocos2d::Vec3(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition3D);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::MotionStreak::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak::setTexture);
mt["setBlendFunc"]=static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getBlendFunc);
mt["getOpacity"]=static_cast<uint8_t(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getOpacity);
mt["setOpacity"]=static_cast<void(cocos2d::MotionStreak::*)(uint8_t)>(&cocos2d::MotionStreak::setOpacity);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isOpacityModifyRGB);
mt["tintWithColor"]=static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak::tintWithColor);
mt["reset"]=static_cast<void(cocos2d::MotionStreak::*)()>(&cocos2d::MotionStreak::reset);
mt["isFastMode"]=static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isFastMode);
mt["setFastMode"]=static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setFastMode);
mt["getStroke"]=static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getStroke);
mt["setStroke"]=static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setStroke);
mt["isStartingPositionInitialized"]=static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isStartingPositionInitialized);
mt["setStartingPositionInitialized"]=static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setStartingPositionInitialized);
mt["setProgramState"]=static_cast<bool(cocos2d::MotionStreak::*)(cocos2d::backend::ProgramState*,bool)>(&cocos2d::MotionStreak::setProgramState);
mt["initWithFade"]=static_cast<bool(cocos2d::MotionStreak::*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak::initWithFade),static_cast<bool(cocos2d::MotionStreak::*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak::initWithFade);
mt["new"]=static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak::create),static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak::create);
}
static void RegisterLuaNodeGrid(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::NodeGrid,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"NodeGrid");
mt["getGrid"]=static_cast<const cocos2d::GridBase*(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGrid),static_cast<cocos2d::GridBase*(cocos2d::NodeGrid::*)()>(&cocos2d::NodeGrid::getGrid);
mt["setGrid"]=static_cast<void(cocos2d::NodeGrid::*)(cocos2d::GridBase*)>(&cocos2d::NodeGrid::setGrid);
mt["setTarget"]=static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Node*)>(&cocos2d::NodeGrid::setTarget);
mt["setGridRect"]=static_cast<void(cocos2d::NodeGrid::*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::setGridRect);
mt["getGridRect"]=static_cast<const cocos2d::Rect&(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGridRect);
mt["visit"]=static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::NodeGrid::visit);
mt["new"]=static_cast<cocos2d::NodeGrid*(*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::create),static_cast<cocos2d::NodeGrid*(*)()>(&cocos2d::NodeGrid::create);
}
static void RegisterLuaParticleBatchNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleBatchNode");
mt["insertChild"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::ParticleSystem*,int)>(&cocos2d::ParticleBatchNode::insertChild);
mt["removeChildAtIndex"]=static_cast<void(cocos2d::ParticleBatchNode::*)(int,bool)>(&cocos2d::ParticleBatchNode::removeChildAtIndex);
mt["removeAllChildrenWithCleanup"]=static_cast<void(cocos2d::ParticleBatchNode::*)(bool)>(&cocos2d::ParticleBatchNode::removeAllChildrenWithCleanup);
mt["disableParticle"]=static_cast<void(cocos2d::ParticleBatchNode::*)(int)>(&cocos2d::ParticleBatchNode::disableParticle);
mt["getTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTextureAtlas);
mt["setTextureAtlas"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::ParticleBatchNode::setTextureAtlas);
mt["visit"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::visit);
mt["addChild"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParticleBatchNode::addChild),static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParticleBatchNode::addChild);
mt["removeChild"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParticleBatchNode::removeChild);
mt["reorderChild"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::ParticleBatchNode::reorderChild);
mt["draw"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::draw);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleBatchNode::setTexture);
mt["setBlendFunc"]=static_cast<void(cocos2d::ParticleBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleBatchNode::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getBlendFunc);
mt["initWithTexture"]=static_cast<bool(cocos2d::ParticleBatchNode::*)(cocos2d::Texture2D*,int)>(&cocos2d::ParticleBatchNode::initWithTexture);
mt["initWithFile"]=static_cast<bool(cocos2d::ParticleBatchNode::*)(const std::string&,int)>(&cocos2d::ParticleBatchNode::initWithFile);
mt["createWithTexture"]=sol::overload([](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0,int arg1){return obj->createWithTexture(arg0,arg1);});
mt["new"]=sol::overload([](cocos2d::ParticleBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ParticleBatchNode* obj,const std::string& arg0,int arg1){return obj->create(arg0,arg1);});
}
static void RegisterLuaParticleData(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleData>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleData");
mt["init"]=static_cast<bool(cocos2d::ParticleData::*)(int)>(&cocos2d::ParticleData::init);
mt["release"]=static_cast<void(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::release);
mt["getMaxCount"]=static_cast<unsigned int(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::getMaxCount);
mt["copyParticle"]=static_cast<void(cocos2d::ParticleData::*)(int,int)>(&cocos2d::ParticleData::copyParticle);
}
static void RegisterLuaParticleSystem(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSystem");
mt["addParticles"]=static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::addParticles);
mt["stopSystem"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stopSystem);
mt["resetSystem"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::resetSystem);
mt["isFull"]=static_cast<bool(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::isFull);
mt["updateParticleQuads"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateParticleQuads);
mt["postStep"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::postStep);
mt["updateWithNoTime"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateWithNoTime);
mt["isAutoRemoveOnFinish"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isAutoRemoveOnFinish);
mt["setAutoRemoveOnFinish"]=static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setAutoRemoveOnFinish);
mt["getGravity"]=static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::getGravity);
mt["setGravity"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setGravity);
mt["getSpeed"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeed);
mt["setSpeed"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeed);
mt["getSpeedVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeedVar);
mt["setSpeedVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeedVar);
mt["getTangentialAccel"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccel);
mt["setTangentialAccel"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccel);
mt["getTangentialAccelVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccelVar);
mt["setTangentialAccelVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccelVar);
mt["getRadialAccel"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccel);
mt["setRadialAccel"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccel);
mt["getRadialAccelVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccelVar);
mt["setRadialAccelVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccelVar);
mt["getRotationIsDir"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotationIsDir);
mt["setRotationIsDir"]=static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setRotationIsDir);
mt["getStartRadius"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadius);
mt["setStartRadius"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadius);
mt["getStartRadiusVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadiusVar);
mt["setStartRadiusVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadiusVar);
mt["getEndRadius"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadius);
mt["setEndRadius"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadius);
mt["getEndRadiusVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadiusVar);
mt["setEndRadiusVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadiusVar);
mt["getRotatePerSecond"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecond);
mt["setRotatePerSecond"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecond);
mt["getRotatePerSecondVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecondVar);
mt["setRotatePerSecondVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecondVar);
mt["setScale"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScale);
mt["setRotation"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotation);
mt["setScaleX"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleX);
mt["setScaleY"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleY);
mt["isActive"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isActive);
mt["isBlendAdditive"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isBlendAdditive);
mt["setBlendAdditive"]=static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setBlendAdditive);
mt["getBatchNode"]=static_cast<cocos2d::ParticleBatchNode*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBatchNode);
mt["setBatchNode"]=static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleBatchNode*)>(&cocos2d::ParticleSystem::setBatchNode);
mt["getAtlasIndex"]=static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAtlasIndex);
mt["setAtlasIndex"]=static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setAtlasIndex);
mt["getParticleCount"]=static_cast<unsigned int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getParticleCount);
mt["getDuration"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getDuration);
mt["setDuration"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setDuration);
mt["getSourcePosition"]=static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSourcePosition);
mt["setSourcePosition"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setSourcePosition);
mt["getPosVar"]=static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPosVar);
mt["setPosVar"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setPosVar);
mt["getLife"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLife);
mt["setLife"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLife);
mt["getLifeVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLifeVar);
mt["setLifeVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLifeVar);
mt["getAngle"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngle);
mt["setAngle"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngle);
mt["getAngleVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngleVar);
mt["setAngleVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngleVar);
mt["getEmitterMode"]=static_cast<cocos2d::ParticleSystem::Mode(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmitterMode);
mt["setEmitterMode"]=static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::Mode)>(&cocos2d::ParticleSystem::setEmitterMode);
mt["getStartSize"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSize);
mt["setStartSize"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSize);
mt["getStartSizeVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSizeVar);
mt["setStartSizeVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSizeVar);
mt["getEndSize"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSize);
mt["setEndSize"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSize);
mt["getEndSizeVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSizeVar);
mt["setEndSizeVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSizeVar);
mt["getStartColor"]=static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColor);
mt["setStartColor"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColor);
mt["getStartColorVar"]=static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColorVar);
mt["setStartColorVar"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColorVar);
mt["getEndColor"]=static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColor);
mt["setEndColor"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColor);
mt["getEndColorVar"]=static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColorVar);
mt["setEndColorVar"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColorVar);
mt["getStartSpin"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpin);
mt["setStartSpin"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpin);
mt["getStartSpinVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpinVar);
mt["setStartSpinVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpinVar);
mt["getEndSpin"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpin);
mt["setEndSpin"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpin);
mt["getEndSpinVar"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpinVar);
mt["setEndSpinVar"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpinVar);
mt["getEmissionRate"]=static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmissionRate);
mt["setEmissionRate"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEmissionRate);
mt["getTotalParticles"]=static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTotalParticles);
mt["setTotalParticles"]=static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setTotalParticles);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isOpacityModifyRGB);
mt["getPositionType"]=static_cast<cocos2d::ParticleSystem::PositionType(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPositionType);
mt["setPositionType"]=static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::PositionType)>(&cocos2d::ParticleSystem::setPositionType);
mt["update"]=static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::update);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleSystem::setTexture);
mt["setBlendFunc"]=static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBlendFunc);
mt["getResourceFile"]=static_cast<const std::string&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getResourceFile);
mt["start"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::start);
mt["stop"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stop);
mt["setSourcePositionCompatible"]=static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setSourcePositionCompatible);
mt["isSourcePositionCompatible"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isSourcePositionCompatible);
mt["init"]=static_cast<bool(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::init);
mt["initWithFile"]=static_cast<bool(cocos2d::ParticleSystem::*)(const std::string&)>(&cocos2d::ParticleSystem::initWithFile);
mt["initWithDictionary"]=static_cast<bool(cocos2d::ParticleSystem::*)(cocos2d::ValueMap&,const std::string&)>(&cocos2d::ParticleSystem::initWithDictionary),static_cast<bool(cocos2d::ParticleSystem::*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystem::initWithDictionary);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::initWithTotalParticles);
mt["isPaused"]=static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isPaused);
mt["pauseEmissions"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::pauseEmissions);
mt["resumeEmissions"]=static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::resumeEmissions);
mt["new"]=static_cast<cocos2d::ParticleSystem*(*)(const std::string&)>(&cocos2d::ParticleSystem::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleSystem*(*)(int)>(&cocos2d::ParticleSystem::createWithTotalParticles);
mt["getAllParticleSystems"]=static_cast<cocos2d::Vector<cocos2d::ParticleSystem *>&(*)()>(&cocos2d::ParticleSystem::getAllParticleSystems);
}
static void RegisterLuaParticleSystemQuad(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSystemQuad");
mt["setDisplayFrame"]=static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::SpriteFrame*)>(&cocos2d::ParticleSystemQuad::setDisplayFrame);
mt["setTextureWithRect"]=static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::ParticleSystemQuad::setTextureWithRect);
mt["listenRendererRecreated"]=static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::EventCustom*)>(&cocos2d::ParticleSystemQuad::listenRendererRecreated);
mt["updateParticleQuads"]=static_cast<void(cocos2d::ParticleSystemQuad::*)()>(&cocos2d::ParticleSystemQuad::updateParticleQuads);
mt["getDescription"]=static_cast<std::string(cocos2d::ParticleSystemQuad::*)()const>(&cocos2d::ParticleSystemQuad::getDescription);
mt["new"]=static_cast<cocos2d::ParticleSystemQuad*(*)(const std::string&)>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)()>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystemQuad::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleSystemQuad*(*)(int)>(&cocos2d::ParticleSystemQuad::createWithTotalParticles);
}
static void RegisterLuaParticleFire(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleFire,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleFire");
mt["init"]=static_cast<bool(cocos2d::ParticleFire::*)()>(&cocos2d::ParticleFire::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleFire::*)(int)>(&cocos2d::ParticleFire::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles);
}
static void RegisterLuaParticleFireworks(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleFireworks,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleFireworks");
mt["init"]=static_cast<bool(cocos2d::ParticleFireworks::*)()>(&cocos2d::ParticleFireworks::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleFireworks::*)(int)>(&cocos2d::ParticleFireworks::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles);
}
static void RegisterLuaParticleSun(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSun,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSun");
mt["init"]=static_cast<bool(cocos2d::ParticleSun::*)()>(&cocos2d::ParticleSun::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleSun::*)(int)>(&cocos2d::ParticleSun::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles);
}
static void RegisterLuaParticleGalaxy(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleGalaxy,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleGalaxy");
mt["init"]=static_cast<bool(cocos2d::ParticleGalaxy::*)()>(&cocos2d::ParticleGalaxy::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleGalaxy::*)(int)>(&cocos2d::ParticleGalaxy::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles);
}
static void RegisterLuaParticleFlower(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleFlower,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleFlower");
mt["init"]=static_cast<bool(cocos2d::ParticleFlower::*)()>(&cocos2d::ParticleFlower::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleFlower::*)(int)>(&cocos2d::ParticleFlower::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleFlower*(*)()>(&cocos2d::ParticleFlower::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleFlower*(*)(int)>(&cocos2d::ParticleFlower::createWithTotalParticles);
}
static void RegisterLuaParticleMeteor(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleMeteor,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleMeteor");
mt["init"]=static_cast<bool(cocos2d::ParticleMeteor::*)()>(&cocos2d::ParticleMeteor::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleMeteor::*)(int)>(&cocos2d::ParticleMeteor::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleMeteor*(*)()>(&cocos2d::ParticleMeteor::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleMeteor*(*)(int)>(&cocos2d::ParticleMeteor::createWithTotalParticles);
}
static void RegisterLuaParticleSpiral(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSpiral,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSpiral");
mt["init"]=static_cast<bool(cocos2d::ParticleSpiral::*)()>(&cocos2d::ParticleSpiral::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleSpiral::*)(int)>(&cocos2d::ParticleSpiral::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleSpiral*(*)()>(&cocos2d::ParticleSpiral::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleSpiral*(*)(int)>(&cocos2d::ParticleSpiral::createWithTotalParticles);
}
static void RegisterLuaParticleExplosion(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleExplosion,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleExplosion");
mt["init"]=static_cast<bool(cocos2d::ParticleExplosion::*)()>(&cocos2d::ParticleExplosion::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleExplosion::*)(int)>(&cocos2d::ParticleExplosion::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleExplosion*(*)()>(&cocos2d::ParticleExplosion::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleExplosion*(*)(int)>(&cocos2d::ParticleExplosion::createWithTotalParticles);
}
static void RegisterLuaParticleSmoke(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSmoke,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSmoke");
mt["init"]=static_cast<bool(cocos2d::ParticleSmoke::*)()>(&cocos2d::ParticleSmoke::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleSmoke::*)(int)>(&cocos2d::ParticleSmoke::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleSmoke*(*)()>(&cocos2d::ParticleSmoke::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleSmoke*(*)(int)>(&cocos2d::ParticleSmoke::createWithTotalParticles);
}
static void RegisterLuaParticleSnow(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleSnow,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleSnow");
mt["init"]=static_cast<bool(cocos2d::ParticleSnow::*)()>(&cocos2d::ParticleSnow::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleSnow::*)(int)>(&cocos2d::ParticleSnow::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleSnow*(*)()>(&cocos2d::ParticleSnow::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleSnow*(*)(int)>(&cocos2d::ParticleSnow::createWithTotalParticles);
}
static void RegisterLuaParticleRain(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParticleRain,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"ParticleRain");
mt["init"]=static_cast<bool(cocos2d::ParticleRain::*)()>(&cocos2d::ParticleRain::init);
mt["initWithTotalParticles"]=static_cast<bool(cocos2d::ParticleRain::*)(int)>(&cocos2d::ParticleRain::initWithTotalParticles);
mt["new"]=static_cast<cocos2d::ParticleRain*(*)()>(&cocos2d::ParticleRain::create);
mt["createWithTotalParticles"]=static_cast<cocos2d::ParticleRain*(*)(int)>(&cocos2d::ParticleRain::createWithTotalParticles);
}
static void RegisterLuaProgressTimer(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ProgressTimer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ProgressTimer");
mt["getType"]=static_cast<cocos2d::ProgressTimer::Type(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getType);
mt["getPercentage"]=static_cast<float(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getPercentage);
mt["getSprite"]=static_cast<cocos2d::Sprite*(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getSprite);
mt["setPercentage"]=static_cast<void(cocos2d::ProgressTimer::*)(float)>(&cocos2d::ProgressTimer::setPercentage);
mt["setSprite"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::setSprite);
mt["setType"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::ProgressTimer::Type)>(&cocos2d::ProgressTimer::setType);
mt["isReverseDirection"]=static_cast<bool(cocos2d::ProgressTimer::*)()>(&cocos2d::ProgressTimer::isReverseDirection);
mt["setReverseDirection"]=static_cast<void(cocos2d::ProgressTimer::*)(bool)>(&cocos2d::ProgressTimer::setReverseDirection);
mt["setMidpoint"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setMidpoint);
mt["getMidpoint"]=static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getMidpoint);
mt["setBarChangeRate"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setBarChangeRate);
mt["getBarChangeRate"]=static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getBarChangeRate);
mt["draw"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProgressTimer::draw);
mt["setAnchorPoint"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setAnchorPoint);
mt["setColor"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Color3B&)>(&cocos2d::ProgressTimer::setColor);
mt["getColor"]=static_cast<const cocos2d::Color3B&(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getColor);
mt["setOpacity"]=static_cast<void(cocos2d::ProgressTimer::*)(uint8_t)>(&cocos2d::ProgressTimer::setOpacity);
mt["getOpacity"]=static_cast<uint8_t(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getOpacity);
mt["initWithSprite"]=static_cast<bool(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::initWithSprite);
mt["new"]=static_cast<cocos2d::ProgressTimer*(*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::create);
}
static void RegisterLuaProtectedNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ProtectedNode");
mt["addProtectedChild"]=static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ProtectedNode::addProtectedChild);
mt["getProtectedChildByTag"]=static_cast<cocos2d::Node*(cocos2d::ProtectedNode::*)(int)>(&cocos2d::ProtectedNode::getProtectedChildByTag);
mt["removeProtectedChild"]=sol::overload([](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0){return obj->removeProtectedChild(arg0);},[](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0,bool arg1){return obj->removeProtectedChild(arg0,arg1);});
mt["removeProtectedChildByTag"]=sol::overload([](cocos2d::ProtectedNode* obj,int arg0){return obj->removeProtectedChildByTag(arg0);},[](cocos2d::ProtectedNode* obj,int arg0,bool arg1){return obj->removeProtectedChildByTag(arg0,arg1);});
mt["removeAllProtectedChildren"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::removeAllProtectedChildren);
mt["removeAllProtectedChildrenWithCleanup"]=static_cast<void(cocos2d::ProtectedNode::*)(bool)>(&cocos2d::ProtectedNode::removeAllProtectedChildrenWithCleanup);
mt["reorderProtectedChild"]=static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::reorderProtectedChild);
mt["sortAllProtectedChildren"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::sortAllProtectedChildren);
mt["visit"]=static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProtectedNode::visit);
mt["cleanup"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::cleanup);
mt["updateDisplayedOpacity"]=static_cast<void(cocos2d::ProtectedNode::*)(uint8_t)>(&cocos2d::ProtectedNode::updateDisplayedOpacity);
mt["updateDisplayedColor"]=static_cast<void(cocos2d::ProtectedNode::*)(const cocos2d::Color3B&)>(&cocos2d::ProtectedNode::updateDisplayedColor);
mt["disableCascadeColor"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeColor);
mt["disableCascadeOpacity"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeOpacity);
mt["setCameraMask"]=sol::overload([](cocos2d::ProtectedNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ProtectedNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);});
mt["setGlobalZOrder"]=static_cast<void(cocos2d::ProtectedNode::*)(float)>(&cocos2d::ProtectedNode::setGlobalZOrder);
mt["new"]=static_cast<cocos2d::ProtectedNode*(*)()>(&cocos2d::ProtectedNode::create);
}
static void RegisterLuaSprite(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"Sprite");
mt["updateTransform"]=static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::updateTransform);
mt["getBatchNode"]=static_cast<cocos2d::SpriteBatchNode*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBatchNode);
mt["setBatchNode"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteBatchNode*)>(&cocos2d::Sprite::setBatchNode);
mt["setTexture"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::setTexture),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setTexture);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTexture);
mt["setTextureRect"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&,bool,const cocos2d::Size&)>(&cocos2d::Sprite::setTextureRect),static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setTextureRect);
mt["setVertexRect"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setVertexRect);
mt["setCenterRectNormalized"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRectNormalized);
mt["getCenterRectNormalized"]=static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRectNormalized);
mt["setCenterRect"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRect);
mt["getCenterRect"]=static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRect);
mt["setSpriteFrame"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::setSpriteFrame),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setSpriteFrame);
mt["isFrameDisplayed"]=static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)const>(&cocos2d::Sprite::isFrameDisplayed);
mt["getSpriteFrame"]=static_cast<cocos2d::SpriteFrame*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getSpriteFrame);
mt["setDisplayFrameWithAnimationName"]=static_cast<void(cocos2d::Sprite::*)(const std::string&,unsigned int)>(&cocos2d::Sprite::setDisplayFrameWithAnimationName);
mt["isDirty"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isDirty);
mt["setDirty"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setDirty);
mt["getDescription"]=static_cast<std::string(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getDescription);
mt["setScaleX"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleX);
mt["setScaleY"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleY);
mt["setScale"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScale),static_cast<void(cocos2d::Sprite::*)(float,float)>(&cocos2d::Sprite::setScale);
mt["setRotation"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotation);
mt["setRotationSkewX"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewX);
mt["setRotationSkewY"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewY);
mt["setSkewX"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewX);
mt["setSkewY"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewY);
mt["removeChild"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,bool)>(&cocos2d::Sprite::removeChild);
mt["removeAllChildrenWithCleanup"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::removeAllChildrenWithCleanup);
mt["reorderChild"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int)>(&cocos2d::Sprite::reorderChild);
mt["addChild"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Sprite::addChild),static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,int)>(&cocos2d::Sprite::addChild);
mt["sortAllChildren"]=static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::sortAllChildren);
mt["setPositionZ"]=static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setPositionZ);
mt["setAnchorPoint"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Vec2&)>(&cocos2d::Sprite::setAnchorPoint);
mt["setContentSize"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Size&)>(&cocos2d::Sprite::setContentSize);
mt["setIgnoreAnchorPointForPosition"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setIgnoreAnchorPointForPosition);
mt["setVisible"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setVisible);
mt["draw"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite::draw);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isOpacityModifyRGB);
mt["isTextureRectRotated"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isTextureRectRotated);
mt["getAtlasIndex"]=static_cast<unsigned int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getAtlasIndex);
mt["setAtlasIndex"]=static_cast<void(cocos2d::Sprite::*)(unsigned int)>(&cocos2d::Sprite::setAtlasIndex);
mt["getTextureRect"]=static_cast<const cocos2d::Rect&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureRect);
mt["getTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureAtlas);
mt["setProgramState"]=sol::overload(static_cast<void(cocos2d::Sprite::*)(uint32_t)>(&cocos2d::Sprite::setProgramState),[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);});
mt["setTextureAtlas"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::TextureAtlas*)>(&cocos2d::Sprite::setTextureAtlas);
mt["getOffsetPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getOffsetPosition);
mt["isFlippedX"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedX);
mt["setFlippedX"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedX);
mt["isFlippedY"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedY);
mt["setFlippedY"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedY);
mt["setStretchEnabled"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setStretchEnabled);
mt["isStretchEnabled"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isStretchEnabled);
mt["setBlendFunc"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBlendFunc);
mt["getResourceType"]=static_cast<int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceType);
mt["getResourceName"]=static_cast<const std::string&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceName);
mt["init"]=static_cast<bool(cocos2d::Sprite::*)()>(&cocos2d::Sprite::init);
mt["initWithTexture"]=static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Sprite::initWithTexture),static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::initWithTexture),static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool)>(&cocos2d::Sprite::initWithTexture);
mt["initWithSpriteFrame"]=static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::initWithSpriteFrame);
mt["initWithSpriteFrameName"]=static_cast<bool(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::initWithSpriteFrameName);
mt["initWithFile"]=static_cast<bool(cocos2d::Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::Sprite::initWithFile),static_cast<bool(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::initWithFile);
mt["setVertexLayout"]=static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::setVertexLayout);
mt["createWithTexture"]=sol::overload([](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1){return obj->createWithTexture(arg0,arg1);},[](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1,bool arg2){return obj->createWithTexture(arg0,arg1,arg2);},static_cast<cocos2d::Sprite*(*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::createWithTexture));
mt["createWithSpriteFrame"]=static_cast<cocos2d::Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::createWithSpriteFrame);
mt["createWithSpriteFrameName"]=static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::createWithSpriteFrameName);
}
static void RegisterLuaRenderTexture(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::RenderTexture,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"RenderTexture");
mt["visit"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::visit);
mt["draw"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::draw);
mt["begin"]=static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::begin);
mt["beginWithClear"]=static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float,int)>(&cocos2d::RenderTexture::beginWithClear);
mt["endToLua"]=static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::end);
mt["clear"]=static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::clear);
mt["clearDepth"]=static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::clearDepth);
mt["clearStencil"]=static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::clearStencil);
mt["saveToFileAsNonPMA"]=sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(const std::string&,cocos2d::Image::Format,bool,std::function<void (cocos2d::RenderTexture *, const std::string&)>)>(&cocos2d::RenderTexture::saveToFileAsNonPMA),[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFileAsNonPMA(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFileAsNonPMA(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFileAsNonPMA(arg0,arg1,arg2);});
mt["saveToFile"]=sol::overload([](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg3){return obj->saveToFile(arg0,arg1,arg2,arg3);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFile(arg0,arg1,arg2);});
mt["getClearFlags"]=static_cast<cocos2d::ClearFlag(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearFlags);
mt["setClearFlags"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::ClearFlag)>(&cocos2d::RenderTexture::setClearFlags);
mt["getClearColor"]=static_cast<const cocos2d::Color4F&(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearColor);
mt["setClearColor"]=static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Color4F&)>(&cocos2d::RenderTexture::setClearColor);
mt["getClearDepth"]=static_cast<float(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearDepth);
mt["setClearDepth"]=static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::setClearDepth);
mt["getClearStencil"]=static_cast<int(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearStencil);
mt["setClearStencil"]=static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::setClearStencil);
mt["isAutoDraw"]=static_cast<bool(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::isAutoDraw);
mt["setAutoDraw"]=static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setAutoDraw);
mt["getSprite"]=static_cast<cocos2d::Sprite*(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getSprite);
mt["setSprite"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Sprite*)>(&cocos2d::RenderTexture::setSprite);
mt["setKeepMatrix"]=static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setKeepMatrix);
mt["setVirtualViewport"]=static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Vec2&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::RenderTexture::setVirtualViewport);
mt["initWithWidthAndHeight"]=static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight),static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight);
mt["new"]=static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int)>(&cocos2d::RenderTexture::create);
}
static void RegisterLuaTransitionEaseScene(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionEaseScene");
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction);
}
static void RegisterLuaTransitionScene(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionScene");
mt["finish"]=static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish);
mt["hideOutShowIn"]=static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn);
mt["getInScene"]=static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene);
mt["getDuration"]=static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration);
mt["draw"]=static_cast<void(cocos2d::TransitionScene::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionScene::draw);
mt["cleanup"]=static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::cleanup);
mt["initWithDuration"]=static_cast<bool(cocos2d::TransitionScene::*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::initWithDuration);
mt["new"]=static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create);
}
static void RegisterLuaTransitionSceneOriented(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSceneOriented");
mt["initWithDuration"]=static_cast<bool(cocos2d::TransitionSceneOriented::*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::initWithDuration);
mt["new"]=static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create);
}
static void RegisterLuaTransitionRotoZoom(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionRotoZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionRotoZoom");
mt["new"]=static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create);
}
static void RegisterLuaTransitionJumpZoom(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionJumpZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionJumpZoom");
mt["new"]=static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create);
}
static void RegisterLuaTransitionMoveInL(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionMoveInL");
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action);
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction);
mt["new"]=static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create);
}
static void RegisterLuaTransitionMoveInR(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionMoveInR,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionMoveInR");
mt["new"]=static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create);
}
static void RegisterLuaTransitionMoveInT(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionMoveInT,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionMoveInT");
mt["new"]=static_cast<cocos2d::TransitionMoveInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInT::create);
}
static void RegisterLuaTransitionMoveInB(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionMoveInB,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionMoveInB");
mt["new"]=static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create);
}
static void RegisterLuaTransitionSlideInL(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSlideInL");
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSlideInL::easeActionWithAction);
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action);
mt["new"]=static_cast<cocos2d::TransitionSlideInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInL::create);
}
static void RegisterLuaTransitionSlideInR(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSlideInR,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSlideInR");
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInR::*)()>(&cocos2d::TransitionSlideInR::action);
mt["new"]=static_cast<cocos2d::TransitionSlideInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInR::create);
}
static void RegisterLuaTransitionSlideInB(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSlideInB,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSlideInB");
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInB::*)()>(&cocos2d::TransitionSlideInB::action);
mt["new"]=static_cast<cocos2d::TransitionSlideInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInB::create);
}
static void RegisterLuaTransitionSlideInT(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSlideInT,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSlideInT");
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInT::*)()>(&cocos2d::TransitionSlideInT::action);
mt["new"]=static_cast<cocos2d::TransitionSlideInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInT::create);
}
static void RegisterLuaTransitionShrinkGrow(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionShrinkGrow,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionShrinkGrow");
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionShrinkGrow::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionShrinkGrow::easeActionWithAction);
mt["new"]=static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create);
}
static void RegisterLuaTransitionFlipX(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFlipX");
mt["new"]=static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create);
}
static void RegisterLuaTransitionFlipY(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFlipY");
mt["new"]=static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create);
}
static void RegisterLuaTransitionFlipAngular(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFlipAngular");
mt["new"]=static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create);
}
static void RegisterLuaTransitionZoomFlipX(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionZoomFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionZoomFlipX");
mt["new"]=static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create);
}
static void RegisterLuaTransitionZoomFlipY(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionZoomFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionZoomFlipY");
mt["new"]=static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create);
}
static void RegisterLuaTransitionZoomFlipAngular(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionZoomFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionZoomFlipAngular");
mt["new"]=static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipAngular::create),static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipAngular::create);
}
static void RegisterLuaTransitionFade(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFade");
mt["initWithDuration"]=static_cast<bool(cocos2d::TransitionFade::*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::initWithDuration),static_cast<bool(cocos2d::TransitionFade::*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::initWithDuration);
mt["new"]=static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::create),static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::create);
}
static void RegisterLuaTransitionCrossFade(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionCrossFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionCrossFade");
mt["draw"]=static_cast<void(cocos2d::TransitionCrossFade::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionCrossFade::draw);
mt["new"]=static_cast<cocos2d::TransitionCrossFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionCrossFade::create);
}
static void RegisterLuaTransitionTurnOffTiles(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionTurnOffTiles,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionTurnOffTiles");
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionTurnOffTiles::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionTurnOffTiles::easeActionWithAction);
mt["draw"]=static_cast<void(cocos2d::TransitionTurnOffTiles::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionTurnOffTiles::draw);
mt["new"]=static_cast<cocos2d::TransitionTurnOffTiles*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionTurnOffTiles::create);
}
static void RegisterLuaTransitionSplitCols(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSplitCols");
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::action);
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSplitCols::easeActionWithAction);
mt["draw"]=static_cast<void(cocos2d::TransitionSplitCols::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionSplitCols::draw);
mt["new"]=static_cast<cocos2d::TransitionSplitCols*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitCols::create);
}
static void RegisterLuaTransitionSplitRows(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionSplitRows,cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionSplitRows");
mt["action"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitRows::*)()>(&cocos2d::TransitionSplitRows::action);
mt["new"]=static_cast<cocos2d::TransitionSplitRows*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitRows::create);
}
static void RegisterLuaTransitionFadeTR(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFadeTR");
mt["actionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeTR::actionWithSize);
mt["easeActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionFadeTR::easeActionWithAction);
mt["draw"]=static_cast<void(cocos2d::TransitionFadeTR::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionFadeTR::draw);
mt["new"]=static_cast<cocos2d::TransitionFadeTR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeTR::create);
}
static void RegisterLuaTransitionFadeBL(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFadeBL,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFadeBL");
mt["actionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeBL::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeBL::actionWithSize);
mt["new"]=static_cast<cocos2d::TransitionFadeBL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeBL::create);
}
static void RegisterLuaTransitionFadeUp(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFadeUp,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFadeUp");
mt["actionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeUp::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeUp::actionWithSize);
mt["new"]=static_cast<cocos2d::TransitionFadeUp*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeUp::create);
}
static void RegisterLuaTransitionFadeDown(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionFadeDown,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionFadeDown");
mt["actionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeDown::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeDown::actionWithSize);
mt["new"]=static_cast<cocos2d::TransitionFadeDown*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeDown::create);
}
static void RegisterLuaTransitionPageTurn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionPageTurn,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionPageTurn");
mt["draw"]=static_cast<void(cocos2d::TransitionPageTurn::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionPageTurn::draw);
mt["initWithDuration"]=static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration);
mt["actionWithSize"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize);
mt["new"]=static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create);
}
static void RegisterLuaTransitionProgress(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgress");
mt["new"]=static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create);
}
static void RegisterLuaTransitionProgressRadialCCW(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgressRadialCCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgressRadialCCW");
mt["new"]=static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create);
}
static void RegisterLuaTransitionProgressRadialCW(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgressRadialCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgressRadialCW");
mt["new"]=static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create);
}
static void RegisterLuaTransitionProgressHorizontal(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgressHorizontal,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgressHorizontal");
mt["new"]=static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create);
}
static void RegisterLuaTransitionProgressVertical(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgressVertical,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgressVertical");
mt["new"]=static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create);
}
static void RegisterLuaTransitionProgressInOut(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgressInOut,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgressInOut");
mt["new"]=static_cast<cocos2d::TransitionProgressInOut*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressInOut::create);
}
static void RegisterLuaTransitionProgressOutIn(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TransitionProgressOutIn,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TransitionProgressOutIn");
mt["new"]=static_cast<cocos2d::TransitionProgressOutIn*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressOutIn::create);
}
static void RegisterLuaCamera(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Camera,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Camera");
mt["getType"]=static_cast<cocos2d::Camera::Type(cocos2d::Camera::*)()const>(&cocos2d::Camera::getType);
mt["getCameraFlag"]=static_cast<cocos2d::CameraFlag(cocos2d::Camera::*)()const>(&cocos2d::Camera::getCameraFlag);
mt["setCameraFlag"]=static_cast<void(cocos2d::Camera::*)(cocos2d::CameraFlag)>(&cocos2d::Camera::setCameraFlag);
mt["lookAt"]=sol::overload([](cocos2d::Camera* obj,const cocos2d::Vec3& arg0){return obj->lookAt(arg0);},[](cocos2d::Camera* obj,const cocos2d::Vec3& arg0,const cocos2d::Vec3& arg1){return obj->lookAt(arg0,arg1);});
mt["getProjectionMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getProjectionMatrix);
mt["getViewMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewMatrix);
mt["getViewProjectionMatrix"]=static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewProjectionMatrix);
mt["project"]=static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::project);
mt["projectGL"]=static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::projectGL);
mt["isVisibleInFrustum"]=static_cast<bool(cocos2d::Camera::*)(const cocos2d::AABB*)const>(&cocos2d::Camera::isVisibleInFrustum);
mt["getDepthInView"]=static_cast<float(cocos2d::Camera::*)(const cocos2d::Mat4&)const>(&cocos2d::Camera::getDepthInView);
mt["setDepth"]=static_cast<void(cocos2d::Camera::*)(int8_t)>(&cocos2d::Camera::setDepth);
mt["getDepth"]=static_cast<int8_t(cocos2d::Camera::*)()const>(&cocos2d::Camera::getDepth);
mt["getRenderOrder"]=static_cast<int(cocos2d::Camera::*)()const>(&cocos2d::Camera::getRenderOrder);
mt["getFarPlane"]=static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getFarPlane);
mt["getNearPlane"]=static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getNearPlane);
mt["clearBackground"]=static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::clearBackground);
mt["apply"]=static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::apply);
mt["isViewProjectionUpdated"]=static_cast<bool(cocos2d::Camera::*)()const>(&cocos2d::Camera::isViewProjectionUpdated);
mt["setBackgroundBrush"]=static_cast<void(cocos2d::Camera::*)(cocos2d::CameraBackgroundBrush*)>(&cocos2d::Camera::setBackgroundBrush);
mt["getBackgroundBrush"]=static_cast<cocos2d::CameraBackgroundBrush*(cocos2d::Camera::*)()const>(&cocos2d::Camera::getBackgroundBrush);
mt["visit"]=static_cast<void(cocos2d::Camera::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Camera::visit);
mt["isBrushValid"]=static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::isBrushValid);
mt["setScene"]=static_cast<void(cocos2d::Camera::*)(cocos2d::Scene*)>(&cocos2d::Camera::setScene);
mt["setAdditionalProjection"]=static_cast<void(cocos2d::Camera::*)(const cocos2d::Mat4&)>(&cocos2d::Camera::setAdditionalProjection);
mt["initDefault"]=static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::initDefault);
mt["initPerspective"]=static_cast<bool(cocos2d::Camera::*)(float,float,float,float)>(&cocos2d::Camera::initPerspective);
mt["initOrthographic"]=static_cast<bool(cocos2d::Camera::*)(float,float,float,float)>(&cocos2d::Camera::initOrthographic);
mt["applyViewport"]=static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::applyViewport);
mt["createPerspective"]=static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createPerspective);
mt["createOrthographic"]=static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createOrthographic);
mt["new"]=static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::create);
mt["getVisitingCamera"]=static_cast<const cocos2d::Camera*(*)()>(&cocos2d::Camera::getVisitingCamera);
mt["getDefaultViewport"]=static_cast<const cocos2d::Viewport&(*)()>(&cocos2d::Camera::getDefaultViewport);
mt["setDefaultViewport"]=static_cast<void(*)(const cocos2d::Viewport&)>(&cocos2d::Camera::setDefaultViewport);
mt["getDefaultCamera"]=static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::getDefaultCamera);
}
static void RegisterLuaCameraBackgroundBrush(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CameraBackgroundBrush");
mt["getBrushType"]=static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundBrush::*)()const>(&cocos2d::CameraBackgroundBrush::getBrushType);
mt["drawBackground"]=static_cast<void(cocos2d::CameraBackgroundBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundBrush::drawBackground);
mt["isValid"]=static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::isValid);
mt["init"]=static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::init);
mt["createNoneBrush"]=static_cast<cocos2d::CameraBackgroundBrush*(*)()>(&cocos2d::CameraBackgroundBrush::createNoneBrush);
mt["createDepthBrush"]=sol::overload([](cocos2d::CameraBackgroundBrush* obj){return obj->createDepthBrush();},[](cocos2d::CameraBackgroundBrush* obj,float arg0){return obj->createDepthBrush(arg0);});
mt["createColorBrush"]=static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundBrush::createColorBrush);
mt["createSkyboxBrush"]=static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundBrush::createSkyboxBrush);
}
static void RegisterLuaCameraBackgroundDepthBrush(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CameraBackgroundDepthBrush");
mt["getBrushType"]=static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundDepthBrush::*)()const>(&cocos2d::CameraBackgroundDepthBrush::getBrushType);
mt["drawBackground"]=static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundDepthBrush::drawBackground);
mt["setDepth"]=static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(float)>(&cocos2d::CameraBackgroundDepthBrush::setDepth);
mt["init"]=static_cast<bool(cocos2d::CameraBackgroundDepthBrush::*)()>(&cocos2d::CameraBackgroundDepthBrush::init);
mt["new"]=static_cast<cocos2d::CameraBackgroundDepthBrush*(*)(float)>(&cocos2d::CameraBackgroundDepthBrush::create);
}
static void RegisterLuaCameraBackgroundColorBrush(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CameraBackgroundColorBrush,cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CameraBackgroundColorBrush");
mt["getBrushType"]=static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundColorBrush::*)()const>(&cocos2d::CameraBackgroundColorBrush::getBrushType);
mt["drawBackground"]=static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundColorBrush::drawBackground);
mt["setColor"]=static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(const cocos2d::Color4F&)>(&cocos2d::CameraBackgroundColorBrush::setColor);
mt["init"]=static_cast<bool(cocos2d::CameraBackgroundColorBrush::*)()>(&cocos2d::CameraBackgroundColorBrush::init);
mt["new"]=static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundColorBrush::create);
}
static void RegisterLuaCameraBackgroundSkyBoxBrush(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::CameraBackgroundSkyBoxBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"CameraBackgroundSkyBoxBrush");
mt["getBrushType"]=static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getBrushType);
mt["setTexture"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::TextureCube*)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTexture);
mt["getTexture"]=static_cast<cocos2d::TextureCube*(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getTexture);
mt["drawBackground"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundSkyBoxBrush::drawBackground);
mt["isActived"]=static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::isActived);
mt["setActived"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setActived);
mt["setTextureValid"]=static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTextureValid);
mt["isValid"]=static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::isValid);
mt["init"]=static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::init);
mt["new"]=static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::create),static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundSkyBoxBrush::create);
}
static void RegisterLuaGridBase(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"GridBase");
mt["beforeBlit"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeBlit);
mt["afterBlit"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::afterBlit);
mt["blit"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::blit);
mt["reuse"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::reuse);
mt["calculateVertexPoints"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::calculateVertexPoints);
mt["initWithSize"]=static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize);
mt["isActive"]=static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isActive);
mt["setActive"]=static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setActive);
mt["getReuseGrid"]=static_cast<int(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getReuseGrid);
mt["setReuseGrid"]=static_cast<void(cocos2d::GridBase::*)(int)>(&cocos2d::GridBase::setReuseGrid);
mt["getGridSize"]=static_cast<const cocos2d::Size&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridSize);
mt["setGridSize"]=static_cast<void(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::setGridSize);
mt["getStep"]=static_cast<const cocos2d::Vec2&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getStep);
mt["setStep"]=static_cast<void(cocos2d::GridBase::*)(const cocos2d::Vec2&)>(&cocos2d::GridBase::setStep);
mt["isTextureFlipped"]=static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isTextureFlipped);
mt["setTextureFlipped"]=static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setTextureFlipped);
mt["beforeDraw"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeDraw);
mt["afterDraw"]=static_cast<void(cocos2d::GridBase::*)(cocos2d::Node*)>(&cocos2d::GridBase::afterDraw);
mt["set2DProjection"]=static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::set2DProjection);
mt["setGridRect"]=static_cast<void(cocos2d::GridBase::*)(const cocos2d::Rect&)>(&cocos2d::GridBase::setGridRect);
mt["getGridRect"]=static_cast<const cocos2d::Rect&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridRect);
}
static void RegisterLuaGrid3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Grid3D,cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Grid3D");
mt["beforeBlit"]=static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::beforeBlit);
mt["afterBlit"]=static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::afterBlit);
mt["blit"]=static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::blit);
mt["reuse"]=static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::reuse);
mt["calculateVertexPoints"]=static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::calculateVertexPoints);
mt["setNeedDepthTestForBlit"]=static_cast<void(cocos2d::Grid3D::*)(bool)>(&cocos2d::Grid3D::setNeedDepthTestForBlit);
mt["getNeedDepthTestForBlit"]=static_cast<bool(cocos2d::Grid3D::*)()const>(&cocos2d::Grid3D::getNeedDepthTestForBlit);
mt["new"]=static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::Grid3D::create);
}
static void RegisterLuaTiledGrid3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TiledGrid3D,cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TiledGrid3D");
mt["blit"]=static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::blit);
mt["reuse"]=static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::reuse);
mt["calculateVertexPoints"]=static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::calculateVertexPoints);
mt["new"]=static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create);
}
static void RegisterLuaBaseLight(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"BaseLight");
mt["getLightType"]=static_cast<cocos2d::LightType(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightType);
mt["getIntensity"]=static_cast<float(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getIntensity);
mt["setIntensity"]=static_cast<void(cocos2d::BaseLight::*)(float)>(&cocos2d::BaseLight::setIntensity);
mt["getLightFlag"]=static_cast<cocos2d::LightFlag(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightFlag);
mt["setLightFlag"]=static_cast<void(cocos2d::BaseLight::*)(cocos2d::LightFlag)>(&cocos2d::BaseLight::setLightFlag);
mt["setEnabled"]=static_cast<void(cocos2d::BaseLight::*)(bool)>(&cocos2d::BaseLight::setEnabled);
mt["isEnabled"]=static_cast<bool(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::isEnabled);
}
static void RegisterLuaDirectionLight(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::DirectionLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"DirectionLight");
mt["getLightType"]=static_cast<cocos2d::LightType(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getLightType);
mt["setDirection"]=static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection);
mt["getDirection"]=static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection);
mt["getDirectionInWorld"]=static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld);
mt["new"]=static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create);
}
static void RegisterLuaPointLight(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::PointLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"PointLight");
mt["getLightType"]=static_cast<cocos2d::LightType(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getLightType);
mt["getRange"]=static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange);
mt["setRange"]=static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange);
mt["new"]=static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create);
}
static void RegisterLuaSpotLight(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SpotLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SpotLight");
mt["getLightType"]=static_cast<cocos2d::LightType(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getLightType);
mt["setDirection"]=static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection);
mt["getDirection"]=static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection);
mt["getDirectionInWorld"]=static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld);
mt["setRange"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange);
mt["getRange"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange);
mt["setInnerAngle"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle);
mt["getInnerAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle);
mt["getCosInnerAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle);
mt["setOuterAngle"]=static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle);
mt["getOuterAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle);
mt["getCosOuterAngle"]=static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle);
mt["new"]=static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create);
}
static void RegisterLuaAmbientLight(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::AmbientLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"AmbientLight");
mt["getLightType"]=static_cast<cocos2d::LightType(cocos2d::AmbientLight::*)()const>(&cocos2d::AmbientLight::getLightType);
mt["new"]=static_cast<cocos2d::AmbientLight*(*)(const cocos2d::Color3B&)>(&cocos2d::AmbientLight::create);
}
static void RegisterLuaRenderState(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::RenderState,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"RenderState");
mt["getName"]=static_cast<std::string(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getName);
mt["bindPass"]=static_cast<void(cocos2d::RenderState::*)(cocos2d::Pass*,cocos2d::MeshCommand*)>(&cocos2d::RenderState::bindPass);
}
static void RegisterLuaTechnique(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Technique,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Technique");
mt["addPass"]=static_cast<void(cocos2d::Technique::*)(cocos2d::Pass*)>(&cocos2d::Technique::addPass);
mt["getName"]=static_cast<std::string(cocos2d::Technique::*)()const>(&cocos2d::Technique::getName);
mt["getPassByIndex"]=static_cast<cocos2d::Pass*(cocos2d::Technique::*)(ssize_t)const>(&cocos2d::Technique::getPassByIndex);
mt["getPassCount"]=static_cast<ssize_t(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPassCount);
mt["getPasses"]=static_cast<const cocos2d::Vector<cocos2d::Pass *>&(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPasses);
mt["clone"]=static_cast<cocos2d::Technique*(cocos2d::Technique::*)()const>(&cocos2d::Technique::clone);
mt["setMaterial"]=static_cast<void(cocos2d::Technique::*)(cocos2d::Material*)>(&cocos2d::Technique::setMaterial);
mt["createWithProgramState"]=static_cast<cocos2d::Technique*(*)(cocos2d::Material*,cocos2d::backend::ProgramState*)>(&cocos2d::Technique::createWithProgramState);
mt["new"]=static_cast<cocos2d::Technique*(*)(cocos2d::Material*)>(&cocos2d::Technique::create);
}
static void RegisterLuaMaterial(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Material");
mt["draw"]=static_cast<void(cocos2d::Material::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::CustomCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Material::draw);
mt["getName"]=static_cast<std::string(cocos2d::Material::*)()const>(&cocos2d::Material::getName);
mt["setName"]=static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setName);
mt["getTechniqueByName"]=static_cast<cocos2d::Technique*(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::getTechniqueByName);
mt["getTechniqueByIndex"]=static_cast<cocos2d::Technique*(cocos2d::Material::*)(ssize_t)>(&cocos2d::Material::getTechniqueByIndex);
mt["getTechnique"]=static_cast<cocos2d::Technique*(cocos2d::Material::*)()const>(&cocos2d::Material::getTechnique);
mt["getTechniques"]=static_cast<const cocos2d::Vector<cocos2d::Technique *>&(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniques);
mt["getTechniqueCount"]=static_cast<ssize_t(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniqueCount);
mt["addTechnique"]=static_cast<void(cocos2d::Material::*)(cocos2d::Technique*)>(&cocos2d::Material::addTechnique);
mt["setTechnique"]=static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setTechnique);
mt["clone"]=static_cast<cocos2d::Material*(cocos2d::Material::*)()const>(&cocos2d::Material::clone);
mt["getRenderState"]=static_cast<cocos2d::RenderState*(cocos2d::Material::*)()>(&cocos2d::Material::getRenderState);
mt["createWithFilename"]=static_cast<cocos2d::Material*(*)(const std::string&)>(&cocos2d::Material::createWithFilename);
mt["createWithProgramState"]=static_cast<cocos2d::Material*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Material::createWithProgramState);
mt["createWithProperties"]=static_cast<cocos2d::Material*(*)(cocos2d::Properties*)>(&cocos2d::Material::createWithProperties);
}
static void RegisterLuaPass(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Pass,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"Pass");
mt["getProgramState"]=static_cast<cocos2d::backend::ProgramState*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getProgramState);
mt["draw"]=static_cast<void(cocos2d::Pass::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::MeshCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Pass::draw);
mt["setVertexAttribBinding"]=static_cast<void(cocos2d::Pass::*)(cocos2d::VertexAttribBinding*)>(&cocos2d::Pass::setVertexAttribBinding);
mt["getVertexAttributeBinding"]=static_cast<cocos2d::VertexAttribBinding*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getVertexAttributeBinding);
mt["setName"]=static_cast<void(cocos2d::Pass::*)(const std::string&)>(&cocos2d::Pass::setName);
mt["getName"]=static_cast<const std::string&(cocos2d::Pass::*)()const>(&cocos2d::Pass::getName);
mt["clone"]=static_cast<cocos2d::Pass*(cocos2d::Pass::*)()const>(&cocos2d::Pass::clone);
mt["setTechnique"]=static_cast<void(cocos2d::Pass::*)(cocos2d::Technique*)>(&cocos2d::Pass::setTechnique);
mt["updateMVPUniform"]=static_cast<void(cocos2d::Pass::*)(const cocos2d::Mat4&)>(&cocos2d::Pass::updateMVPUniform);
mt["setUniformTexture"]=static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformTexture);
mt["setUniformNormTexture"]=static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformNormTexture);
mt["setUniformColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformColor);
mt["setUniformMatrixPalette"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformMatrixPalette);
mt["setUniformDirLightColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightColor);
mt["setUniformDirLightDir"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightDir);
mt["setUniformPointLightColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightColor);
mt["setUniformPointLightPosition"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightPosition);
mt["setUniformPointLightRangeInverse"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightRangeInverse);
mt["setUniformSpotLightColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightColor);
mt["setUniformSpotLightPosition"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightPosition);
mt["setUniformSpotLightDir"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightDir);
mt["setUniformSpotLightInnerAngleCos"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightInnerAngleCos);
mt["setUniformSpotLightOuterAngleCos"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightOuterAngleCos);
mt["setUniformSpotLightRangeInverse"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightRangeInverse);
mt["setUniformAmbientLigthColor"]=static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformAmbientLigthColor);
mt["createWithProgramState"]=static_cast<cocos2d::Pass*(*)(cocos2d::Technique*,cocos2d::backend::ProgramState*)>(&cocos2d::Pass::createWithProgramState);
mt["new"]=static_cast<cocos2d::Pass*(*)(cocos2d::Technique*)>(&cocos2d::Pass::create);
}
static void RegisterLuaRenderer(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Renderer>(lua.get_or("cc",lua.create_named_table("cc")),"Renderer");
mt["init"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::init);
mt["addCommand"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*,int)>(&cocos2d::Renderer::addCommand),static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*)>(&cocos2d::Renderer::addCommand);
mt["pushGroup"]=static_cast<void(cocos2d::Renderer::*)(int)>(&cocos2d::Renderer::pushGroup);
mt["popGroup"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::popGroup);
mt["createRenderQueue"]=static_cast<int(cocos2d::Renderer::*)()>(&cocos2d::Renderer::createRenderQueue);
mt["render"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::render);
mt["clean"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clean);
mt["getDrawnBatches"]=static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnBatches);
mt["addDrawnBatches"]=static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnBatches);
mt["getDrawnVertices"]=static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnVertices);
mt["addDrawnVertices"]=static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnVertices);
mt["clearDrawStats"]=static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clearDrawStats);
mt["getRenderTarget"]=static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTarget);
mt["setRenderTarget"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*)>(&cocos2d::Renderer::setRenderTarget);
mt["getDefaultRenderTarget"]=static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDefaultRenderTarget);
mt["clear"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::ClearFlag,const cocos2d::Color4F&,float,unsigned int,float)>(&cocos2d::Renderer::clear);
mt["getClearColor"]=static_cast<const cocos2d::Color4F&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearColor);
mt["getClearDepth"]=static_cast<float(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearDepth);
mt["getClearStencil"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearStencil);
mt["getClearFlag"]=static_cast<cocos2d::ClearFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearFlag);
mt["getRenderTargetFlag"]=static_cast<cocos2d::RenderTargetFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTargetFlag);
mt["setDepthTest"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthTest);
mt["setDepthWrite"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthWrite);
mt["setDepthCompareFunction"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction)>(&cocos2d::Renderer::setDepthCompareFunction);
mt["getDepthTest"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthTest);
mt["getDepthWrite"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthWrite);
mt["getDepthCompareFunction"]=static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthCompareFunction);
mt["setStencilTest"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setStencilTest);
mt["setStencilCompareFunction"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction,unsigned int,unsigned int)>(&cocos2d::Renderer::setStencilCompareFunction);
mt["setStencilOperation"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation)>(&cocos2d::Renderer::setStencilOperation);
mt["setStencilWriteMask"]=static_cast<void(cocos2d::Renderer::*)(unsigned int)>(&cocos2d::Renderer::setStencilWriteMask);
mt["getStencilTest"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilTest);
mt["getStencilFailureOperation"]=static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilFailureOperation);
mt["getStencilPassDepthFailureOperation"]=static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilPassDepthFailureOperation);
mt["getStencilDepthPassOperation"]=static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilDepthPassOperation);
mt["getStencilCompareFunction"]=static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilCompareFunction);
mt["getStencilReadMask"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReadMask);
mt["getStencilWriteMask"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilWriteMask);
mt["getStencilReferenceValue"]=static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReferenceValue);
mt["setDepthStencilDesc"]=static_cast<void(cocos2d::Renderer::*)(const cocos2d::backend::DepthStencilDescriptor&)>(&cocos2d::Renderer::setDepthStencilDesc);
mt["getDepthStencilDesc"]=static_cast<const cocos2d::backend::DepthStencilDescriptor&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthStencilDesc);
mt["setCullMode"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::CullMode)>(&cocos2d::Renderer::setCullMode);
mt["getCullMode"]=static_cast<cocos2d::CullMode(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getCullMode);
mt["setWinding"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::Winding)>(&cocos2d::Renderer::setWinding);
mt["getWinding"]=static_cast<cocos2d::Winding(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getWinding);
mt["setViewPort"]=static_cast<void(cocos2d::Renderer::*)(int,int,unsigned int,unsigned int)>(&cocos2d::Renderer::setViewPort);
mt["getViewport"]=static_cast<const cocos2d::Viewport&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getViewport);
mt["setScissorTest"]=static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setScissorTest);
mt["setScissorRect"]=static_cast<void(cocos2d::Renderer::*)(float,float,float,float)>(&cocos2d::Renderer::setScissorRect);
mt["getScissorTest"]=static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorTest);
mt["getScissorRect"]=static_cast<const cocos2d::ScissorRect&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorRect);
mt["checkVisibility"]=static_cast<bool(cocos2d::Renderer::*)(const cocos2d::Mat4&,const cocos2d::Size&)>(&cocos2d::Renderer::checkVisibility);
mt["readPixels"]=static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*,std::function<void (const cocos2d::backend::PixelBufferDescriptor &)>)>(&cocos2d::Renderer::readPixels);
}
static void RegisterLuaTextureCache(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TextureCache,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TextureCache");
mt["getDescription"]=static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getDescription);
mt["addImage"]=static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(cocos2d::Image*,const std::string&)>(&cocos2d::TextureCache::addImage),static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::addImage);
mt["unbindImageAsync"]=static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::unbindImageAsync);
mt["unbindAllImageAsync"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::unbindAllImageAsync);
mt["getTextureForKey"]=static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)const>(&cocos2d::TextureCache::getTextureForKey);
mt["reloadTexture"]=static_cast<bool(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::reloadTexture);
mt["removeAllTextures"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeAllTextures);
mt["removeUnusedTextures"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeUnusedTextures);
mt["removeTexture"]=static_cast<void(cocos2d::TextureCache::*)(cocos2d::Texture2D*)>(&cocos2d::TextureCache::removeTexture);
mt["removeTextureForKey"]=static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::removeTextureForKey);
mt["getCachedTextureInfo"]=static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getCachedTextureInfo);
mt["waitForQuit"]=static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::waitForQuit);
mt["getTextureFilePath"]=static_cast<std::string(cocos2d::TextureCache::*)(cocos2d::Texture2D*)const>(&cocos2d::TextureCache::getTextureFilePath);
mt["renameTextureWithKey"]=static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::string&)>(&cocos2d::TextureCache::renameTextureWithKey);
mt["setETC1AlphaFileSuffix"]=static_cast<void(*)(const std::string&)>(&cocos2d::TextureCache::setETC1AlphaFileSuffix);
mt["getETC1AlphaFileSuffix"]=static_cast<std::string(*)()>(&cocos2d::TextureCache::getETC1AlphaFileSuffix);
}
static void RegisterLuaDevice(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Device>(lua.get_or("cc",lua.create_named_table("cc")),"Device");
mt["getDPI"]=static_cast<int(*)()>(&cocos2d::Device::getDPI);
mt["setAccelerometerEnabled"]=static_cast<void(*)(bool)>(&cocos2d::Device::setAccelerometerEnabled);
mt["setAccelerometerInterval"]=static_cast<void(*)(float)>(&cocos2d::Device::setAccelerometerInterval);
mt["setKeepScreenOn"]=static_cast<void(*)(bool)>(&cocos2d::Device::setKeepScreenOn);
mt["vibrate"]=static_cast<void(*)(float)>(&cocos2d::Device::vibrate);
}
static void RegisterLuaApplication(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::Application>(lua.get_or("cc",lua.create_named_table("cc")),"Application");
mt["setAnimationInterval"]=static_cast<void(cocos2d::Application::*)(float)>(&cocos2d::Application::setAnimationInterval);
mt["getCurrentLanguage"]=static_cast<cocos2d::LanguageType(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguage);
mt["getCurrentLanguageCode"]=static_cast<const char*(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguageCode);
mt["getTargetPlatform"]=static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::Application::*)()>(&cocos2d::Application::getTargetPlatform);
mt["getVersion"]=static_cast<std::string(cocos2d::Application::*)()>(&cocos2d::Application::getVersion);
mt["GetCompileVersion"]=static_cast<int64_t(cocos2d::Application::*)()>(&cocos2d::Application::GetCompileVersion);
mt["openURL"]=static_cast<bool(cocos2d::Application::*)(const std::string&)>(&cocos2d::Application::openURL);
mt["getInstance"]=static_cast<cocos2d::Application*(*)()>(&cocos2d::Application::getInstance);
}
static void RegisterLuaGLViewImpl(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::GLViewImpl,cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"GLViewImpl");
mt["isOpenGLReady"]=static_cast<bool(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::isOpenGLReady);
mt["setIMEKeyboardState"]=static_cast<void(cocos2d::GLViewImpl::*)(bool)>(&cocos2d::GLViewImpl::setIMEKeyboardState);
mt["getSafeAreaRect"]=static_cast<cocos2d::Rect(cocos2d::GLViewImpl::*)()const>(&cocos2d::GLViewImpl::getSafeAreaRect);
mt["new"]=static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::create);
mt["createWithRect"]=sol::overload([](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1){return obj->createWithRect(arg0,arg1);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2){return obj->createWithRect(arg0,arg1,arg2);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2,bool arg3){return obj->createWithRect(arg0,arg1,arg2,arg3);});
mt["createWithFullScreen"]=static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::createWithFullScreen);
}
static void RegisterLuaAnimationCache(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::AnimationCache,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"AnimationCache");
mt["init"]=static_cast<bool(cocos2d::AnimationCache::*)()>(&cocos2d::AnimationCache::init);
mt["addAnimation"]=static_cast<void(cocos2d::AnimationCache::*)(cocos2d::Animation*,const std::string&)>(&cocos2d::AnimationCache::addAnimation);
mt["removeAnimation"]=static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::removeAnimation);
mt["getAnimation"]=static_cast<cocos2d::Animation*(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::getAnimation);
mt["addAnimationsWithDictionary"]=static_cast<void(cocos2d::AnimationCache::*)(const cocos2d::ValueMap&,const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithDictionary);
mt["addAnimations"]=static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithFile);
mt["getInstance"]=static_cast<cocos2d::AnimationCache*(*)()>(&cocos2d::AnimationCache::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::AnimationCache::destroyInstance);
}
static void RegisterLuaSpriteBatchNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SpriteBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"SpriteBatchNode");
mt["getTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::getTextureAtlas);
mt["setTextureAtlas"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::SpriteBatchNode::setTextureAtlas);
mt["increaseAtlasCapacity"]=static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::increaseAtlasCapacity);
mt["removeChildAtIndex"]=static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t,bool)>(&cocos2d::SpriteBatchNode::removeChildAtIndex);
mt["appendChild"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::appendChild);
mt["removeSpriteFromAtlas"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::removeSpriteFromAtlas);
mt["rebuildIndexInOrder"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::rebuildIndexInOrder);
mt["highestAtlasIndexInChild"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::highestAtlasIndexInChild);
mt["lowestAtlasIndexInChild"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::lowestAtlasIndexInChild);
mt["atlasIndexForChild"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int)>(&cocos2d::SpriteBatchNode::atlasIndexForChild);
mt["reorderBatch"]=static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::reorderBatch);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteBatchNode::setTexture);
mt["setBlendFunc"]=static_cast<void(cocos2d::SpriteBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::SpriteBatchNode::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getBlendFunc);
mt["visit"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::visit);
mt["addChild"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::SpriteBatchNode::addChild),static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::SpriteBatchNode::addChild);
mt["reorderChild"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::SpriteBatchNode::reorderChild);
mt["removeChild"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::SpriteBatchNode::removeChild);
mt["removeAllChildrenWithCleanup"]=static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::removeAllChildrenWithCleanup);
mt["sortAllChildren"]=static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::sortAllChildren);
mt["draw"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::draw);
mt["getDescription"]=static_cast<std::string(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescription);
mt["setProgramState"]=sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);});
mt["insertQuadFromSprite"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::insertQuadFromSprite);
mt["addSpriteWithoutQuad"]=static_cast<cocos2d::SpriteBatchNode*(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int,int)>(&cocos2d::SpriteBatchNode::addSpriteWithoutQuad);
mt["reserveCapacity"]=static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t)>(&cocos2d::SpriteBatchNode::reserveCapacity);
mt["initWithTexture"]=sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->initWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->initWithTexture(arg0,arg1);});
mt["initWithFile"]=sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->initWithFile(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->initWithFile(arg0,arg1);});
mt["init"]=static_cast<bool(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::init);
mt["createWithTexture"]=sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->createWithTexture(arg0,arg1);});
mt["new"]=sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->create(arg0,arg1);});
}
static void RegisterLuaSpriteFrameCache(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::SpriteFrameCache,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"SpriteFrameCache");
mt["init"]=static_cast<bool(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::init);
mt["addSpriteFrames"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile);
mt["addSpriteFramesWithFileContent"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFileContent);
mt["addSpriteFrame"]=static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::SpriteFrame*,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFrame);
mt["isSpriteFramesWithFileLoaded"]=static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)const>(&cocos2d::SpriteFrameCache::isSpriteFramesWithFileLoaded);
mt["removeSpriteFrames"]=static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeSpriteFrames);
mt["removeUnusedSpriteFrames"]=static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeUnusedSpriteFrames);
mt["removeSpriteFrameByName"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFrameByName);
mt["removeSpriteFramesFromFile"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFile);
mt["removeSpriteFramesFromFileContent"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFileContent);
mt["removeSpriteFramesFromTexture"]=static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromTexture);
mt["getSpriteFrame"]=static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::getSpriteFrameByName);
mt["reloadTexture"]=static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::reloadTexture);
mt["getInstance"]=static_cast<cocos2d::SpriteFrameCache*(*)()>(&cocos2d::SpriteFrameCache::getInstance);
mt["destroyInstance"]=static_cast<void(*)()>(&cocos2d::SpriteFrameCache::destroyInstance);
}
static void RegisterLuaParallaxNode(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ParallaxNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"ParallaxNode");
mt["addChild"]=static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParallaxNode::addChild);
mt["removeChild"]=static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParallaxNode::removeChild);
mt["removeAllChildrenWithCleanup"]=static_cast<void(cocos2d::ParallaxNode::*)(bool)>(&cocos2d::ParallaxNode::removeAllChildrenWithCleanup);
mt["visit"]=static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParallaxNode::visit);
mt["new"]=static_cast<cocos2d::ParallaxNode*(*)()>(&cocos2d::ParallaxNode::create);
}
static void RegisterLuaTMXObjectGroup(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TMXObjectGroup,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TMXObjectGroup");
mt["getGroupName"]=static_cast<const std::string&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getGroupName);
mt["setGroupName"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const std::string&)>(&cocos2d::TMXObjectGroup::setGroupName);
mt["getProperty"]=static_cast<cocos2d::Value(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getProperty);
mt["getObject"]=static_cast<cocos2d::ValueMap(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getObject);
mt["getPositionOffset"]=static_cast<const cocos2d::Vec2&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getPositionOffset);
mt["setPositionOffset"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::Vec2&)>(&cocos2d::TMXObjectGroup::setPositionOffset);
mt["getProperties"]=static_cast<cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getProperties);
mt["setProperties"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXObjectGroup::setProperties);
mt["getObjects"]=static_cast<cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getObjects),static_cast<const cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getObjects);
mt["setObjects"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueVector&)>(&cocos2d::TMXObjectGroup::setObjects);
}
static void RegisterLuaTMXLayerInfo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TMXLayerInfo,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TMXLayerInfo");
mt["setProperties"]=static_cast<void(cocos2d::TMXLayerInfo::*)(cocos2d::ValueMap)>(&cocos2d::TMXLayerInfo::setProperties);
mt["getProperties"]=static_cast<cocos2d::ValueMap&(cocos2d::TMXLayerInfo::*)()>(&cocos2d::TMXLayerInfo::getProperties);
}
static void RegisterLuaTMXTilesetInfo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TMXTilesetInfo,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TMXTilesetInfo");
mt["getRectForGID"]=static_cast<cocos2d::Rect(cocos2d::TMXTilesetInfo::*)(uint32_t)>(&cocos2d::TMXTilesetInfo::getRectForGID);
}
static void RegisterLuaTMXMapInfo(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TMXMapInfo>(lua.get_or("cc",lua.create_named_table("cc")),"TMXMapInfo");
mt["initWithTMXFile"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::initWithTMXFile);
mt["initWithXML"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::initWithXML);
mt["parseXMLFile"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLFile);
mt["parseXMLString"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLString);
mt["getTileProperties"]=static_cast<cocos2d::ValueMapIntKey&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTileProperties);
mt["setTileProperties"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMapIntKey&)>(&cocos2d::TMXMapInfo::setTileProperties);
mt["getOrientation"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getOrientation);
mt["setOrientation"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setOrientation);
mt["getStaggerAxis"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerAxis);
mt["setStaggerAxis"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerAxis);
mt["getStaggerIndex"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerIndex);
mt["setStaggerIndex"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerIndex);
mt["getHexSideLength"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getHexSideLength);
mt["setHexSideLength"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setHexSideLength);
mt["getMapSize"]=static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getMapSize);
mt["setMapSize"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setMapSize);
mt["getTileSize"]=static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTileSize);
mt["setTileSize"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setTileSize);
mt["getLayers"]=static_cast<cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getLayers),static_cast<const cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayers);
mt["setLayers"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXLayerInfo *>&)>(&cocos2d::TMXMapInfo::setLayers);
mt["getTilesets"]=static_cast<cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTilesets),static_cast<const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTilesets);
mt["setTilesets"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&)>(&cocos2d::TMXMapInfo::setTilesets);
mt["getObjectGroups"]=static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getObjectGroups);
mt["setObjectGroups"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::TMXMapInfo::setObjectGroups);
mt["getParentElement"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentElement);
mt["setParentElement"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentElement);
mt["getParentGID"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentGID);
mt["setParentGID"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentGID);
mt["getLayerAttribs"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayerAttribs);
mt["setLayerAttribs"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setLayerAttribs);
mt["isStoringCharacters"]=static_cast<bool(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::isStoringCharacters);
mt["setStoringCharacters"]=static_cast<void(cocos2d::TMXMapInfo::*)(bool)>(&cocos2d::TMXMapInfo::setStoringCharacters);
mt["getProperties"]=static_cast<cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getProperties);
mt["setProperties"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXMapInfo::setProperties);
mt["getCurrentString"]=static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getCurrentString);
mt["setCurrentString"]=static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setCurrentString);
mt["getTMXFileName"]=static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTMXFileName);
mt["setTMXFileName"]=static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setTMXFileName);
mt["getExternalTilesetFileName"]=static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getExternalTilesetFileName);
mt["new"]=static_cast<cocos2d::TMXMapInfo*(*)(const std::string&)>(&cocos2d::TMXMapInfo::create);
mt["createWithXML"]=static_cast<cocos2d::TMXMapInfo*(*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::createWithXML);
}
static void RegisterLuaTileMapAtlas(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TileMapAtlas,cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"TileMapAtlas");
mt["initWithTileFile"]=static_cast<bool(cocos2d::TileMapAtlas::*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::initWithTileFile);
mt["getTileAt"]=static_cast<cocos2d::Color3B(cocos2d::TileMapAtlas::*)(const cocos2d::Vec2&)const>(&cocos2d::TileMapAtlas::getTileAt);
mt["setTile"]=static_cast<void(cocos2d::TileMapAtlas::*)(const cocos2d::Color3B&,const cocos2d::Vec2&)>(&cocos2d::TileMapAtlas::setTile);
mt["releaseMap"]=static_cast<void(cocos2d::TileMapAtlas::*)()>(&cocos2d::TileMapAtlas::releaseMap);
mt["new"]=static_cast<cocos2d::TileMapAtlas*(*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::create);
}
static void RegisterLuaFastTMXLayer(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FastTMXLayer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FastTMXLayer");
mt["setTileGID"]=static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&,cocos2d::TMXTileFlags)>(&cocos2d::FastTMXLayer::setTileGID),static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::setTileGID);
mt["removeTileAt"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::removeTileAt);
mt["getPositionAt"]=static_cast<cocos2d::Vec2(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getPositionAt);
mt["getProperty"]=static_cast<cocos2d::Value(cocos2d::FastTMXLayer::*)(const std::string&)const>(&cocos2d::FastTMXLayer::getProperty);
mt["setupTiles"]=static_cast<void(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::setupTiles);
mt["getLayerName"]=static_cast<const std::string&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getLayerName);
mt["setLayerName"]=static_cast<void(cocos2d::FastTMXLayer::*)(const std::string&)>(&cocos2d::FastTMXLayer::setLayerName);
mt["getLayerSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerSize);
mt["setLayerSize"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setLayerSize);
mt["getMapTileSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getMapTileSize);
mt["setMapTileSize"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setMapTileSize);
mt["getTileSet"]=static_cast<cocos2d::TMXTilesetInfo*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileSet);
mt["setTileSet"]=static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*)>(&cocos2d::FastTMXLayer::setTileSet);
mt["getLayerOrientation"]=static_cast<int(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerOrientation);
mt["setLayerOrientation"]=static_cast<void(cocos2d::FastTMXLayer::*)(int)>(&cocos2d::FastTMXLayer::setLayerOrientation);
mt["getProperties"]=static_cast<cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getProperties);
mt["setProperties"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXLayer::setProperties);
mt["getTileAt"]=static_cast<cocos2d::Sprite*(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getTileAt);
mt["setupTileSprite"]=static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Sprite*,const cocos2d::Vec2&,uint32_t)>(&cocos2d::FastTMXLayer::setupTileSprite);
mt["getDescription"]=static_cast<std::string(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getDescription);
mt["draw"]=static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::FastTMXLayer::draw);
mt["removeChild"]=sol::overload([](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);});
mt["getAnimTileCoord"]=static_cast<const std::unordered_map<unsigned int, std::vector<cocos2d::Vec2>>*(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getAnimTileCoord);
mt["hasTileAnimation"]=static_cast<bool(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::hasTileAnimation);
mt["getTileAnimManager"]=static_cast<cocos2d::TMXTileAnimManager*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileAnimManager);
mt["initWithTilesetInfo"]=static_cast<bool(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::initWithTilesetInfo);
mt["new"]=static_cast<cocos2d::FastTMXLayer*(*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::create);
}
static void RegisterLuaTMXTileAnimTask(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TMXTileAnimTask,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TMXTileAnimTask");
mt["start"]=static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::start);
mt["stop"]=static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::stop);
mt["isRunning"]=static_cast<bool(cocos2d::TMXTileAnimTask::*)()const>(&cocos2d::TMXTileAnimTask::isRunning);
mt["new"]=static_cast<cocos2d::TMXTileAnimTask*(*)(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>(&cocos2d::TMXTileAnimTask::create);
}
static void RegisterLuaTMXTileAnimManager(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::TMXTileAnimManager,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"TMXTileAnimManager");
mt["startAll"]=static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll);
mt["stopAll"]=static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll);
mt["getTasks"]=static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks);
mt["new"]=static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create);
}
static void RegisterLuaFastTMXTiledMap(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::FastTMXTiledMap,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>(lua.get_or("cc",lua.create_named_table("cc")),"FastTMXTiledMap");
mt["getLayer"]=static_cast<cocos2d::FastTMXLayer*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getLayer);
mt["getObjectGroup"]=static_cast<cocos2d::TMXObjectGroup*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getObjectGroup);
mt["getProperty"]=static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getProperty);
mt["getPropertiesForGID"]=static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(int)const>(&cocos2d::FastTMXTiledMap::getPropertiesForGID);
mt["getMapSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapSize);
mt["setMapSize"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setMapSize);
mt["getTileSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getTileSize);
mt["setTileSize"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setTileSize);
mt["getMapOrientation"]=static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapOrientation);
mt["setMapOrientation"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(int)>(&cocos2d::FastTMXTiledMap::setMapOrientation);
mt["getObjectGroups"]=static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()>(&cocos2d::FastTMXTiledMap::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getObjectGroups);
mt["setObjectGroups"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::FastTMXTiledMap::setObjectGroups);
mt["getProperties"]=static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getProperties);
mt["setProperties"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXTiledMap::setProperties);
mt["getDescription"]=static_cast<std::string(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getDescription);
mt["setTileAnimEnabled"]=static_cast<void(cocos2d::FastTMXTiledMap::*)(bool)>(&cocos2d::FastTMXTiledMap::setTileAnimEnabled);
mt["getLayerCount"]=static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getLayerCount);
mt["getResourceFile"]=static_cast<const std::string&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getResourceFile);
mt["initWithTMXFile"]=static_cast<bool(cocos2d::FastTMXTiledMap::*)(const std::string&)>(&cocos2d::FastTMXTiledMap::initWithTMXFile);
mt["initWithXML"]=static_cast<bool(cocos2d::FastTMXTiledMap::*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::initWithXML);
mt["new"]=static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&)>(&cocos2d::FastTMXTiledMap::create);
mt["createWithXML"]=static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::createWithXML);
}
static void RegisterLuaMotionStreak3D(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::MotionStreak3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>(lua.get_or("cc",lua.create_named_table("cc")),"MotionStreak3D");
mt["tintWithColor"]=static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak3D::tintWithColor);
mt["reset"]=static_cast<void(cocos2d::MotionStreak3D::*)()>(&cocos2d::MotionStreak3D::reset);
mt["getStroke"]=static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getStroke);
mt["setStroke"]=static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setStroke);
mt["isStartingPositionInitialized"]=static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isStartingPositionInitialized);
mt["setStartingPositionInitialized"]=static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setStartingPositionInitialized);
mt["setPosition"]=static_cast<void(cocos2d::MotionStreak3D::*)(float,float)>(&cocos2d::MotionStreak3D::setPosition),static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak3D::setPosition);
mt["setPosition3D"]=static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setPosition3D);
mt["setRotation3D"]=static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setRotation3D);
mt["setRotationQuat"]=static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Quaternion&)>(&cocos2d::MotionStreak3D::setRotationQuat);
mt["getPosition"]=static_cast<void(cocos2d::MotionStreak3D::*)(float*,float*)const>(&cocos2d::MotionStreak3D::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition);
mt["setPositionX"]=static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionX);
mt["setPositionY"]=static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionY);
mt["getPositionX"]=static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionX);
mt["getPositionY"]=static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionY);
mt["getPosition3D"]=static_cast<cocos2d::Vec3(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition3D);
mt["draw"]=static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::MotionStreak3D::draw);
mt["update"]=static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::update);
mt["getTexture"]=static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getTexture);
mt["setTexture"]=static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::setTexture);
mt["setBlendFunc"]=static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak3D::setBlendFunc);
mt["getBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getBlendFunc);
mt["getOpacity"]=static_cast<uint8_t(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getOpacity);
mt["setOpacity"]=static_cast<void(cocos2d::MotionStreak3D::*)(uint8_t)>(&cocos2d::MotionStreak3D::setOpacity);
mt["setOpacityModifyRGB"]=static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setOpacityModifyRGB);
mt["isOpacityModifyRGB"]=static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isOpacityModifyRGB);
mt["setSweepAxis"]=static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setSweepAxis);
mt["getSweepAxis"]=static_cast<const cocos2d::Vec3&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getSweepAxis);
mt["initWithFade"]=static_cast<bool(cocos2d::MotionStreak3D::*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::initWithFade),static_cast<bool(cocos2d::MotionStreak3D::*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::initWithFade);
mt["new"]=static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::create),static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::create);
}
void RegisterLuaCoreAuto(cocos2d::Lua& lua) {
RegisterLuaRef(lua);
RegisterLuaConsole(lua);
RegisterLuaEventListener(lua);
RegisterLuaEventListenerCustom(lua);
RegisterLuaShaderCache(lua);
RegisterLuaTexture2D(lua);
RegisterLuaComponent(lua);
RegisterLuaNode(lua);
RegisterLuaScene(lua);
RegisterLuaEvent(lua);
RegisterLuaEventTouch(lua);
RegisterLuaGLView(lua);
RegisterLuaDirector(lua);
RegisterLuaTimer(lua);
RegisterLuaScheduler(lua);
RegisterLuaAsyncTaskPool(lua);
RegisterLuaAction(lua);
RegisterLuaFiniteTimeAction(lua);
RegisterLuaSpeed(lua);
RegisterLuaFollow(lua);
RegisterLuaImage(lua);
RegisterLuaPolygonInfo(lua);
RegisterLuaAutoPolygon(lua);
RegisterLuaSpriteFrame(lua);
RegisterLuaAnimationFrame(lua);
RegisterLuaAnimation(lua);
RegisterLuaActionInterval(lua);
RegisterLuaSequence(lua);
RegisterLuaRepeat(lua);
RegisterLuaRepeatForever(lua);
RegisterLuaSpawn(lua);
RegisterLuaRotateTo(lua);
RegisterLuaRotateBy(lua);
RegisterLuaMoveBy(lua);
RegisterLuaMoveTo(lua);
RegisterLuaSkewTo(lua);
RegisterLuaSkewBy(lua);
RegisterLuaJumpBy(lua);
RegisterLuaJumpTo(lua);
RegisterLuaBezierBy(lua);
RegisterLuaBezierTo(lua);
RegisterLuaScaleTo(lua);
RegisterLuaScaleBy(lua);
RegisterLuaBlink(lua);
RegisterLuaFadeTo(lua);
RegisterLuaFadeIn(lua);
RegisterLuaFadeOut(lua);
RegisterLuaTintTo(lua);
RegisterLuaTintBy(lua);
RegisterLuaDelayTime(lua);
RegisterLuaAnimate(lua);
RegisterLuaTargetedAction(lua);
RegisterLuaActionFloat(lua);
RegisterLuaEventKeyboard(lua);
RegisterLuaProperties(lua);
RegisterLuaUserDefault(lua);
RegisterLuaFileUtils(lua);
RegisterLuaEventAcceleration(lua);
RegisterLuaEventCustom(lua);
RegisterLuaEventDispatcher(lua);
RegisterLuaEventFocus(lua);
RegisterLuaEventListenerAcceleration(lua);
RegisterLuaEventListenerFocus(lua);
RegisterLuaEventListenerKeyboard(lua);
RegisterLuaEventMouse(lua);
RegisterLuaEventListenerMouse(lua);
RegisterLuaEventListenerController(lua);
RegisterLuaEventListenerTouchOneByOne(lua);
RegisterLuaEventListenerTouchAllAtOnce(lua);
RegisterLuaEventController(lua);
RegisterLuaActionCamera(lua);
RegisterLuaOrbitCamera(lua);
RegisterLuaCardinalSplineTo(lua);
RegisterLuaCardinalSplineBy(lua);
RegisterLuaCatmullRomTo(lua);
RegisterLuaCatmullRomBy(lua);
RegisterLuaActionEase(lua);
RegisterLuaEaseRateAction(lua);
RegisterLuaEaseExponentialIn(lua);
RegisterLuaEaseExponentialOut(lua);
RegisterLuaEaseExponentialInOut(lua);
RegisterLuaEaseSineIn(lua);
RegisterLuaEaseSineOut(lua);
RegisterLuaEaseSineInOut(lua);
RegisterLuaEaseBounce(lua);
RegisterLuaEaseBounceIn(lua);
RegisterLuaEaseBounceOut(lua);
RegisterLuaEaseBounceInOut(lua);
RegisterLuaEaseBackIn(lua);
RegisterLuaEaseBackOut(lua);
RegisterLuaEaseBackInOut(lua);
RegisterLuaEaseQuadraticActionIn(lua);
RegisterLuaEaseQuadraticActionOut(lua);
RegisterLuaEaseQuadraticActionInOut(lua);
RegisterLuaEaseQuarticActionIn(lua);
RegisterLuaEaseQuarticActionOut(lua);
RegisterLuaEaseQuarticActionInOut(lua);
RegisterLuaEaseQuinticActionIn(lua);
RegisterLuaEaseQuinticActionOut(lua);
RegisterLuaEaseQuinticActionInOut(lua);
RegisterLuaEaseCircleActionIn(lua);
RegisterLuaEaseCircleActionOut(lua);
RegisterLuaEaseCircleActionInOut(lua);
RegisterLuaEaseCubicActionIn(lua);
RegisterLuaEaseCubicActionOut(lua);
RegisterLuaEaseCubicActionInOut(lua);
RegisterLuaEaseIn(lua);
RegisterLuaEaseOut(lua);
RegisterLuaEaseInOut(lua);
RegisterLuaEaseElastic(lua);
RegisterLuaEaseElasticIn(lua);
RegisterLuaEaseElasticOut(lua);
RegisterLuaEaseElasticInOut(lua);
RegisterLuaEaseBezierAction(lua);
RegisterLuaActionInstant(lua);
RegisterLuaShow(lua);
RegisterLuaHide(lua);
RegisterLuaToggleVisibility(lua);
RegisterLuaRemoveSelf(lua);
RegisterLuaFlipX(lua);
RegisterLuaFlipY(lua);
RegisterLuaPlace(lua);
RegisterLuaCallFunc(lua);
RegisterLuaGridAction(lua);
RegisterLuaGrid3DAction(lua);
RegisterLuaTiledGrid3DAction(lua);
RegisterLuaStopGrid(lua);
RegisterLuaReuseGrid(lua);
RegisterLuaWaves3D(lua);
RegisterLuaFlipX3D(lua);
RegisterLuaFlipY3D(lua);
RegisterLuaLens3D(lua);
RegisterLuaRipple3D(lua);
RegisterLuaShaky3D(lua);
RegisterLuaLiquid(lua);
RegisterLuaWaves(lua);
RegisterLuaTwirl(lua);
RegisterLuaActionManager(lua);
RegisterLuaPageTurn3D(lua);
RegisterLuaProgressTo(lua);
RegisterLuaProgressFromTo(lua);
RegisterLuaShakyTiles3D(lua);
RegisterLuaShatteredTiles3D(lua);
RegisterLuaShuffleTiles(lua);
RegisterLuaFadeOutTRTiles(lua);
RegisterLuaFadeOutBLTiles(lua);
RegisterLuaFadeOutUpTiles(lua);
RegisterLuaFadeOutDownTiles(lua);
RegisterLuaTurnOffTiles(lua);
RegisterLuaWavesTiles3D(lua);
RegisterLuaJumpTiles3D(lua);
RegisterLuaSplitRows(lua);
RegisterLuaSplitCols(lua);
RegisterLuaActionTween(lua);
RegisterLuaAtlasNode(lua);
RegisterLuaClippingNode(lua);
RegisterLuaClippingRectangleNode(lua);
RegisterLuaDrawNode(lua);
RegisterLuaLabel(lua);
RegisterLuaLabelAtlas(lua);
RegisterLuaTouch(lua);
RegisterLuaLayer(lua);
RegisterLuaLayerColor(lua);
RegisterLuaLayerGradient(lua);
RegisterLuaLayerRadialGradient(lua);
RegisterLuaLayerMultiplex(lua);
RegisterLuaMenuItem(lua);
RegisterLuaMenuItemLabel(lua);
RegisterLuaMenuItemAtlasFont(lua);
RegisterLuaMenuItemFont(lua);
RegisterLuaMenuItemSprite(lua);
RegisterLuaMenuItemImage(lua);
RegisterLuaMenuItemToggle(lua);
RegisterLuaMenu(lua);
RegisterLuaMotionStreak(lua);
RegisterLuaNodeGrid(lua);
RegisterLuaParticleBatchNode(lua);
RegisterLuaParticleData(lua);
RegisterLuaParticleSystem(lua);
RegisterLuaParticleSystemQuad(lua);
RegisterLuaParticleFire(lua);
RegisterLuaParticleFireworks(lua);
RegisterLuaParticleSun(lua);
RegisterLuaParticleGalaxy(lua);
RegisterLuaParticleFlower(lua);
RegisterLuaParticleMeteor(lua);
RegisterLuaParticleSpiral(lua);
RegisterLuaParticleExplosion(lua);
RegisterLuaParticleSmoke(lua);
RegisterLuaParticleSnow(lua);
RegisterLuaParticleRain(lua);
RegisterLuaProgressTimer(lua);
RegisterLuaProtectedNode(lua);
RegisterLuaSprite(lua);
RegisterLuaRenderTexture(lua);
RegisterLuaTransitionEaseScene(lua);
RegisterLuaTransitionScene(lua);
RegisterLuaTransitionSceneOriented(lua);
RegisterLuaTransitionRotoZoom(lua);
RegisterLuaTransitionJumpZoom(lua);
RegisterLuaTransitionMoveInL(lua);
RegisterLuaTransitionMoveInR(lua);
RegisterLuaTransitionMoveInT(lua);
RegisterLuaTransitionMoveInB(lua);
RegisterLuaTransitionSlideInL(lua);
RegisterLuaTransitionSlideInR(lua);
RegisterLuaTransitionSlideInB(lua);
RegisterLuaTransitionSlideInT(lua);
RegisterLuaTransitionShrinkGrow(lua);
RegisterLuaTransitionFlipX(lua);
RegisterLuaTransitionFlipY(lua);
RegisterLuaTransitionFlipAngular(lua);
RegisterLuaTransitionZoomFlipX(lua);
RegisterLuaTransitionZoomFlipY(lua);
RegisterLuaTransitionZoomFlipAngular(lua);
RegisterLuaTransitionFade(lua);
RegisterLuaTransitionCrossFade(lua);
RegisterLuaTransitionTurnOffTiles(lua);
RegisterLuaTransitionSplitCols(lua);
RegisterLuaTransitionSplitRows(lua);
RegisterLuaTransitionFadeTR(lua);
RegisterLuaTransitionFadeBL(lua);
RegisterLuaTransitionFadeUp(lua);
RegisterLuaTransitionFadeDown(lua);
RegisterLuaTransitionPageTurn(lua);
RegisterLuaTransitionProgress(lua);
RegisterLuaTransitionProgressRadialCCW(lua);
RegisterLuaTransitionProgressRadialCW(lua);
RegisterLuaTransitionProgressHorizontal(lua);
RegisterLuaTransitionProgressVertical(lua);
RegisterLuaTransitionProgressInOut(lua);
RegisterLuaTransitionProgressOutIn(lua);
RegisterLuaCamera(lua);
RegisterLuaCameraBackgroundBrush(lua);
RegisterLuaCameraBackgroundDepthBrush(lua);
RegisterLuaCameraBackgroundColorBrush(lua);
RegisterLuaCameraBackgroundSkyBoxBrush(lua);
RegisterLuaGridBase(lua);
RegisterLuaGrid3D(lua);
RegisterLuaTiledGrid3D(lua);
RegisterLuaBaseLight(lua);
RegisterLuaDirectionLight(lua);
RegisterLuaPointLight(lua);
RegisterLuaSpotLight(lua);
RegisterLuaAmbientLight(lua);
RegisterLuaRenderState(lua);
RegisterLuaTechnique(lua);
RegisterLuaMaterial(lua);
RegisterLuaPass(lua);
RegisterLuaRenderer(lua);
RegisterLuaTextureCache(lua);
RegisterLuaDevice(lua);
RegisterLuaApplication(lua);
RegisterLuaGLViewImpl(lua);
RegisterLuaAnimationCache(lua);
RegisterLuaSpriteBatchNode(lua);
RegisterLuaSpriteFrameCache(lua);
RegisterLuaParallaxNode(lua);
RegisterLuaTMXObjectGroup(lua);
RegisterLuaTMXLayerInfo(lua);
RegisterLuaTMXTilesetInfo(lua);
RegisterLuaTMXMapInfo(lua);
RegisterLuaTileMapAtlas(lua);
RegisterLuaFastTMXLayer(lua);
RegisterLuaTMXTileAnimTask(lua);
RegisterLuaTMXTileAnimManager(lua);
RegisterLuaFastTMXTiledMap(lua);
RegisterLuaMotionStreak3D(lua);
}
