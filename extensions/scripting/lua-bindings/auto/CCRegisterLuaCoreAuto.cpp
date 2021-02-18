#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
static void RegisterLuaRef(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Ref,cocos2d::LuaObject>("cc","Ref"
,"retain",static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::retain)
,"release",static_cast<void(cocos2d::Ref::*)()>(&cocos2d::Ref::release)
,"getReferenceCount",static_cast<unsigned int(cocos2d::Ref::*)()const>(&cocos2d::Ref::getReferenceCount)
);}
static void RegisterLuaConsole(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Console,cocos2d::Ref,cocos2d::LuaObject>("cc","Console"
,"listenOnTCP",static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnTCP)
,"listenOnFileDescriptor",static_cast<bool(cocos2d::Console::*)(int)>(&cocos2d::Console::listenOnFileDescriptor)
,"stop",static_cast<void(cocos2d::Console::*)()>(&cocos2d::Console::stop)
,"delCommand",static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::delCommand)
,"log",static_cast<void(cocos2d::Console::*)(const char*)>(&cocos2d::Console::log)
,"setBindAddress",static_cast<void(cocos2d::Console::*)(const std::string&)>(&cocos2d::Console::setBindAddress)
,"isIpv6Server",static_cast<bool(cocos2d::Console::*)()const>(&cocos2d::Console::isIpv6Server)
,"setCommandSeparator",static_cast<void(cocos2d::Console::*)(char)>(&cocos2d::Console::setCommandSeparator)
);}
static void RegisterLuaEventListener(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListener"
,"checkAvailable",static_cast<bool(cocos2d::EventListener::*)()>(&cocos2d::EventListener::checkAvailable)
,"clone",static_cast<cocos2d::EventListener*(cocos2d::EventListener::*)()>(&cocos2d::EventListener::clone)
,"setEnabled",static_cast<void(cocos2d::EventListener::*)(bool)>(&cocos2d::EventListener::setEnabled)
,"isEnabled",static_cast<bool(cocos2d::EventListener::*)()const>(&cocos2d::EventListener::isEnabled)
);}
static void RegisterLuaEventListenerCustom(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerCustom,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerCustom"
,"checkAvailable",static_cast<bool(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::checkAvailable)
,"clone",static_cast<cocos2d::EventListenerCustom*(cocos2d::EventListenerCustom::*)()>(&cocos2d::EventListenerCustom::clone)
);}
static void RegisterLuaShaderCache(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::backend::ShaderCache,cocos2d::Ref,cocos2d::LuaObject>("cc","ShaderCache"
,"removeUnusedShader",static_cast<void(cocos2d::backend::ShaderCache::*)()>(&cocos2d::backend::ShaderCache::removeUnusedShader)
,"getInstance",static_cast<cocos2d::backend::ShaderCache*(*)()>(&cocos2d::backend::ShaderCache::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::backend::ShaderCache::destroyInstance)
,"newVertexShaderModule",static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newVertexShaderModule)
,"newFragmentShaderModule",static_cast<cocos2d::backend::ShaderModule*(*)(const std::string&)>(&cocos2d::backend::ShaderCache::newFragmentShaderModule)
);}
static void RegisterLuaTexture2D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Texture2D,cocos2d::Ref,cocos2d::LuaObject>("cc","Texture2D"
,"updateWithImage",sol::overload([](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1){return obj->updateWithImage(arg0,arg1);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2){return obj->updateWithImage(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,cocos2d::Image* arg0,cocos2d::backend::PixelFormat arg1,int arg2,int arg3){return obj->updateWithImage(arg0,arg1,arg2,arg3);})
,"updateWithMipmaps",sol::overload([](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,cocos2d::MipmapInfo* arg0,int arg1,cocos2d::backend::PixelFormat arg2,cocos2d::backend::PixelFormat arg3,int arg4,int arg5,bool arg6,int arg7){return obj->updateWithMipmaps(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);})
,"updateWithSubData",sol::overload([](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,void* arg0,int arg1,int arg2,int arg3,int arg4,int arg5){return obj->updateWithSubData(arg0,arg1,arg2,arg3,arg4,arg5);})
,"drawAtPoint",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Vec2&,float)>(&cocos2d::Texture2D::drawAtPoint)
,"drawInRect",static_cast<void(cocos2d::Texture2D::*)(const cocos2d::Rect&,float)>(&cocos2d::Texture2D::drawInRect)
,"initWithImage",sol::overload(static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*,cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::initWithImage),static_cast<bool(cocos2d::Texture2D::*)(cocos2d::Image*)>(&cocos2d::Texture2D::initWithImage))
,"initWithString",sol::overload(static_cast<bool(cocos2d::Texture2D::*)(const char*,const cocos2d::FontDefinition&)>(&cocos2d::Texture2D::initWithString),[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2){return obj->initWithString(arg0,arg1,arg2);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithString(arg0,arg1,arg2,arg3);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithString(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::Texture2D* obj,const char* arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5,bool arg6,int arg7){return obj->initWithString(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);})
,"updateTextureDescriptor",sol::overload([](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0){return obj->updateTextureDescriptor(arg0);},[](cocos2d::Texture2D* obj,const cocos2d::backend::TextureDescriptor& arg0,bool arg1){return obj->updateTextureDescriptor(arg0,arg1);})
,"setRenderTarget",static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setRenderTarget)
,"isRenderTarget",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::isRenderTarget)
,"generateMipmap",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::generateMipmap)
,"setAntiAliasTexParameters",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAntiAliasTexParameters)
,"setAliasTexParameters",static_cast<void(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::setAliasTexParameters)
,"getStringForFormat",static_cast<const char*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getStringForFormat)
,"getContentSizeInPixels",static_cast<const cocos2d::Size&(cocos2d::Texture2D::*)()>(&cocos2d::Texture2D::getContentSizeInPixels)
,"hasPremultipliedAlpha",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasPremultipliedAlpha)
,"setPremultipliedAlpha",static_cast<void(cocos2d::Texture2D::*)(bool)>(&cocos2d::Texture2D::setPremultipliedAlpha)
,"hasMipmaps",static_cast<bool(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::hasMipmaps)
,"getPixelFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelFormat)
,"getTextureFormatEXT",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getTextureFormatEXT)
,"getPixelsWide",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsWide)
,"getPixelsHigh",static_cast<int(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPixelsHigh)
,"getBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getBackendTexture)
,"getMaxS",static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxS)
,"setMaxS",static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxS)
,"getMaxT",static_cast<float(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getMaxT)
,"setMaxT",static_cast<void(cocos2d::Texture2D::*)(float)>(&cocos2d::Texture2D::setMaxT)
,"getContentSize",static_cast<cocos2d::Size(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getContentSize)
,"getPath",static_cast<std::string(cocos2d::Texture2D::*)()const>(&cocos2d::Texture2D::getPath)
,"setDefaultAlphaPixelFormat",static_cast<void(*)(cocos2d::backend::PixelFormat)>(&cocos2d::Texture2D::setDefaultAlphaPixelFormat)
,"getDefaultAlphaPixelFormat",static_cast<cocos2d::backend::PixelFormat(*)()>(&cocos2d::Texture2D::getDefaultAlphaPixelFormat)
);}
static void RegisterLuaComponent(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("cc","Component"
,"init",static_cast<bool(cocos2d::Component::*)()>(&cocos2d::Component::init)
,"isEnabled",static_cast<bool(cocos2d::Component::*)()const>(&cocos2d::Component::isEnabled)
,"setEnabled",static_cast<void(cocos2d::Component::*)(bool)>(&cocos2d::Component::setEnabled)
,"getName",static_cast<const std::string&(cocos2d::Component::*)()const>(&cocos2d::Component::getName)
,"setName",static_cast<void(cocos2d::Component::*)(const std::string&)>(&cocos2d::Component::setName)
,"getOwner",static_cast<cocos2d::Node*(cocos2d::Component::*)()const>(&cocos2d::Component::getOwner)
,"setOwner",static_cast<void(cocos2d::Component::*)(cocos2d::Node*)>(&cocos2d::Component::setOwner)
,"update",static_cast<void(cocos2d::Component::*)(float)>(&cocos2d::Component::update)
,"onAdd",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onAdd)
,"onRemove",static_cast<void(cocos2d::Component::*)()>(&cocos2d::Component::onRemove)
,"new",static_cast<cocos2d::Component*(*)()>(&cocos2d::Component::create)
);}
static void RegisterLuaNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Node"
,"getDescription",static_cast<std::string(cocos2d::Node::*)()const>(&cocos2d::Node::getDescription)
,"setLocalZOrder",static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::setLocalZOrder)
,"_setLocalZOrder",static_cast<void(cocos2d::Node::*)(int32_t)>(&cocos2d::Node::_setLocalZOrder)
,"updateOrderOfArrival",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateOrderOfArrival)
,"getLocalZOrder",static_cast<int32_t(cocos2d::Node::*)()const>(&cocos2d::Node::getLocalZOrder)
,"setGlobalZOrder",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setGlobalZOrder)
,"getGlobalZOrder",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getGlobalZOrder)
,"setScaleX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleX)
,"getScaleX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleX)
,"setScaleY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleY)
,"getScaleY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleY)
,"setScaleZ",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScaleZ)
,"getScaleZ",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScaleZ)
,"setScale",sol::overload(static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setScale),static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setScale))
,"getScale",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getScale)
,"setPosition",sol::overload(static_cast<void(cocos2d::Node::*)(float,float)>(&cocos2d::Node::setPosition),static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPosition))
,"setPositionNormalized",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setPositionNormalized)
,"setNormalizedPosition",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec2&)>(&cocos2d::Node::setNormalizedPosition)
,"getPositionXY",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionXY)
,"getPositionNormalized",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionNormalized)
,"getNormalizedPosition",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getNormalizedPosition)
,"setPositionX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionX)
,"getPositionX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionX)
,"setPositionY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionY)
,"getPositionY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionY)
,"setPosition3D",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setPosition3D)
,"getPosition3D",static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getPosition3D)
,"setPositionZ",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setPositionZ)
,"getPositionZ",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getPositionZ)
,"setSkewX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewX)
,"getSkewX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewX)
,"setSkewY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setSkewY)
,"getSkewY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getSkewY)
,"getAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPoint)
,"getAnchorPointInPoints",static_cast<const cocos2d::Vec2&(cocos2d::Node::*)()const>(&cocos2d::Node::getAnchorPointInPoints)
,"getContentSize",static_cast<const cocos2d::Size&(cocos2d::Node::*)()const>(&cocos2d::Node::getContentSize)
,"getContentWidth",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentWidth)
,"getContentHeight",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getContentHeight)
,"setContentWidth",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentWidth)
,"setContentHeight",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setContentHeight)
,"setVisible",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setVisible)
,"isVisible",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isVisible)
,"setRotation",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotation)
,"getRotation",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation)
,"setRotation3D",static_cast<void(cocos2d::Node::*)(const cocos2d::Vec3&)>(&cocos2d::Node::setRotation3D)
,"getRotation3D",static_cast<cocos2d::Vec3(cocos2d::Node::*)()const>(&cocos2d::Node::getRotation3D)
,"setRotationSkewX",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewX)
,"getRotationSkewX",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewX)
,"setRotationSkewY",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::setRotationSkewY)
,"getRotationSkewY",static_cast<float(cocos2d::Node::*)()const>(&cocos2d::Node::getRotationSkewY)
,"setIgnoreAnchorPointForPosition",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setIgnoreAnchorPointForPosition)
,"isIgnoreAnchorPointForPosition",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isIgnoreAnchorPointForPosition)
,"addChild",sol::overload(static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,int)>(&cocos2d::Node::addChild),static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Node::addChild))
,"getChildByTag",static_cast<cocos2d::Node*(cocos2d::Node::*)(int)const>(&cocos2d::Node::getChildByTag)
,"getChildByName",static_cast<cocos2d::Node*(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::getChildByName)
,"getChildren",sol::overload(static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()const>(&cocos2d::Node::getChildren),static_cast<cocos2d::Vector<cocos2d::Node *>&(cocos2d::Node::*)()>(&cocos2d::Node::getChildren))
,"getChildrenCount",static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getChildrenCount)
,"setParent",static_cast<void(cocos2d::Node::*)(cocos2d::Node*)>(&cocos2d::Node::setParent)
,"getParent",sol::overload(static_cast<const cocos2d::Node*(cocos2d::Node::*)()const>(&cocos2d::Node::getParent),static_cast<cocos2d::Node*(cocos2d::Node::*)()>(&cocos2d::Node::getParent))
,"removeFromParent",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeFromParent)
,"removeFromParentAndCleanup",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeFromParentAndCleanup)
,"removeChild",sol::overload([](cocos2d::Node* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Node* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);})
,"removeChildByTag",sol::overload([](cocos2d::Node* obj,int arg0){return obj->removeChildByTag(arg0);},[](cocos2d::Node* obj,int arg0,bool arg1){return obj->removeChildByTag(arg0,arg1);})
,"removeChildByName",sol::overload([](cocos2d::Node* obj,const std::string& arg0){return obj->removeChildByName(arg0);},[](cocos2d::Node* obj,const std::string& arg0,bool arg1){return obj->removeChildByName(arg0,arg1);})
,"removeAllChildren",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllChildren)
,"removeAllChildrenWithCleanup",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::removeAllChildrenWithCleanup)
,"reorderChild",static_cast<void(cocos2d::Node::*)(cocos2d::Node*,int)>(&cocos2d::Node::reorderChild)
,"sortAllChildren",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::sortAllChildren)
,"getTag",static_cast<int(cocos2d::Node::*)()const>(&cocos2d::Node::getTag)
,"setTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::setTag)
,"getName",static_cast<const std::string&(cocos2d::Node::*)()const>(&cocos2d::Node::getName)
,"setName",static_cast<void(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::setName)
,"setUserObject",static_cast<void(cocos2d::Node::*)(cocos2d::Ref*)>(&cocos2d::Node::setUserObject)
,"isRunning",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isRunning)
,"cleanup",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::cleanup)
,"draw",sol::overload(static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::draw),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::draw))
,"visit",sol::overload(static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::visit),static_cast<void(cocos2d::Node::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Node::visit))
,"getScene",static_cast<cocos2d::Scene*(cocos2d::Node::*)()const>(&cocos2d::Node::getScene)
,"getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Node::*)()const>(&cocos2d::Node::getBoundingBox)
,"setEventDispatcher",static_cast<void(cocos2d::Node::*)(cocos2d::EventDispatcher*)>(&cocos2d::Node::setEventDispatcher)
,"getEventDispatcher",static_cast<cocos2d::EventDispatcher*(cocos2d::Node::*)()const>(&cocos2d::Node::getEventDispatcher)
,"setActionManager",static_cast<void(cocos2d::Node::*)(cocos2d::ActionManager*)>(&cocos2d::Node::setActionManager)
,"getActionManager",sol::overload(static_cast<const cocos2d::ActionManager*(cocos2d::Node::*)()const>(&cocos2d::Node::getActionManager),static_cast<cocos2d::ActionManager*(cocos2d::Node::*)()>(&cocos2d::Node::getActionManager))
,"runAction",static_cast<cocos2d::Action*(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::runAction)
,"stopAllActions",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::stopAllActions)
,"stopAction",static_cast<void(cocos2d::Node::*)(cocos2d::Action*)>(&cocos2d::Node::stopAction)
,"stopActionByTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopActionByTag)
,"stopAllActionsByTag",static_cast<void(cocos2d::Node::*)(int)>(&cocos2d::Node::stopAllActionsByTag)
,"stopActionsByFlags",static_cast<void(cocos2d::Node::*)(unsigned int)>(&cocos2d::Node::stopActionsByFlags)
,"getActionByTag",static_cast<cocos2d::Action*(cocos2d::Node::*)(int)>(&cocos2d::Node::getActionByTag)
,"getNumberOfRunningActions",static_cast<ssize_t(cocos2d::Node::*)()const>(&cocos2d::Node::getNumberOfRunningActions)
,"getNumberOfRunningActionsByTag",static_cast<ssize_t(cocos2d::Node::*)(int)const>(&cocos2d::Node::getNumberOfRunningActionsByTag)
,"setScheduler",static_cast<void(cocos2d::Node::*)(cocos2d::Scheduler*)>(&cocos2d::Node::setScheduler)
,"getScheduler",sol::overload(static_cast<const cocos2d::Scheduler*(cocos2d::Node::*)()const>(&cocos2d::Node::getScheduler),static_cast<cocos2d::Scheduler*(cocos2d::Node::*)()>(&cocos2d::Node::getScheduler))
,"isScheduled",sol::overload(static_cast<bool(cocos2d::Node::*)(const std::string&)const>(&cocos2d::Node::isScheduled),static_cast<bool(cocos2d::Node::*)(cocos2d::SEL_SCHEDULE)const>(&cocos2d::Node::isScheduled))
,"resume",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::resume)
,"pause",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::pause)
,"update",static_cast<void(cocos2d::Node::*)(float)>(&cocos2d::Node::update)
,"updateTransform",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::updateTransform)
,"getNodeToParentTransform",sol::overload(static_cast<cocos2d::Mat4(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentTransform),static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentTransform))
,"getNodeToParentAffineTransform",sol::overload(static_cast<cocos2d::AffineTransform(cocos2d::Node::*)(cocos2d::Node*)const>(&cocos2d::Node::getNodeToParentAffineTransform),static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToParentAffineTransform))
,"setNodeToParentTransform",static_cast<void(cocos2d::Node::*)(const cocos2d::Mat4&)>(&cocos2d::Node::setNodeToParentTransform)
,"getParentToNodeTransform",static_cast<const cocos2d::Mat4&(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeTransform)
,"getParentToNodeAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getParentToNodeAffineTransform)
,"getNodeToWorldTransform",static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldTransform)
,"getNodeToWorldAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getNodeToWorldAffineTransform)
,"getWorldToNodeTransform",static_cast<cocos2d::Mat4(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeTransform)
,"getWorldToNodeAffineTransform",static_cast<cocos2d::AffineTransform(cocos2d::Node::*)()const>(&cocos2d::Node::getWorldToNodeAffineTransform)
,"convertToNodeSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpace)
,"convertToWorldSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpace)
,"convertToNodeSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToNodeSpaceAR)
,"convertToWorldSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(const cocos2d::Vec2&)const>(&cocos2d::Node::convertToWorldSpaceAR)
,"convertTouchToNodeSpace",static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpace)
,"convertTouchToNodeSpaceAR",static_cast<cocos2d::Vec2(cocos2d::Node::*)(cocos2d::Touch*)const>(&cocos2d::Node::convertTouchToNodeSpaceAR)
,"getComponent",static_cast<cocos2d::Component*(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::getComponent)
,"addComponent",static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::addComponent)
,"removeComponent",sol::overload(static_cast<bool(cocos2d::Node::*)(cocos2d::Component*)>(&cocos2d::Node::removeComponent),static_cast<bool(cocos2d::Node::*)(const std::string&)>(&cocos2d::Node::removeComponent))
,"removeAllComponents",static_cast<void(cocos2d::Node::*)()>(&cocos2d::Node::removeAllComponents)
,"getOpacity",static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getOpacity)
,"getDisplayedOpacity",static_cast<uint8_t(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedOpacity)
,"setOpacity",static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::setOpacity)
,"updateDisplayedOpacity",static_cast<void(cocos2d::Node::*)(uint8_t)>(&cocos2d::Node::updateDisplayedOpacity)
,"isCascadeOpacityEnabled",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeOpacityEnabled)
,"setCascadeOpacityEnabled",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeOpacityEnabled)
,"getColor",static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getColor)
,"getDisplayedColor",static_cast<const cocos2d::Color3B&(cocos2d::Node::*)()const>(&cocos2d::Node::getDisplayedColor)
,"setColor",static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::setColor)
,"updateDisplayedColor",static_cast<void(cocos2d::Node::*)(const cocos2d::Color3B&)>(&cocos2d::Node::updateDisplayedColor)
,"isCascadeColorEnabled",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isCascadeColorEnabled)
,"setCascadeColorEnabled",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setCascadeColorEnabled)
,"setOpacityModifyRGB",static_cast<void(cocos2d::Node::*)(bool)>(&cocos2d::Node::setOpacityModifyRGB)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::Node::*)()const>(&cocos2d::Node::isOpacityModifyRGB)
,"SetOnEnterHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnEnterHandler)
,"GetOnEnterHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnEnterHandler)
,"SetOnExitHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnExitHandler)
,"GetOnExitHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnExitHandler)
,"SetOnEnterTransitionDidFinishHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnEnterTransitionDidFinishHandler)
,"GetOnEnterTransitionDidFinishHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnEnterTransitionDidFinishHandler)
,"SetOnExitTransitionDidStartHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnExitTransitionDidStartHandler)
,"GetOnExitTransitionDidStartHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnExitTransitionDidStartHandler)
,"SetOnCleanUpHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnCleanUpHandler)
,"GetOnCleanUpHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnCleanUpHandler)
,"SetOnUpdateHandler",static_cast<void(cocos2d::Node::*)(const std::function<void (cocos2d::Node *)>&)>(&cocos2d::Node::SetOnUpdateHandler)
,"GetOnUpdateHandler",static_cast<const std::function<void (cocos2d::Node *)>&(cocos2d::Node::*)()const>(&cocos2d::Node::GetOnUpdateHandler)
,"getCameraMask",static_cast<unsigned short(cocos2d::Node::*)()const>(&cocos2d::Node::getCameraMask)
,"setCameraMask",sol::overload([](cocos2d::Node* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Node* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);})
,"setProgramState",sol::overload([](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Node* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);},static_cast<void(cocos2d::Node::*)(uint32_t)>(&cocos2d::Node::setProgramState))
,"setProgramStateWithRegistry",static_cast<void(cocos2d::Node::*)(uint32_t,cocos2d::Texture2D*)>(&cocos2d::Node::setProgramStateWithRegistry)
,"getProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Node::*)()const>(&cocos2d::Node::getProgramState)
,"updateProgramStateTexture",static_cast<void(cocos2d::Node::*)(cocos2d::Texture2D*)>(&cocos2d::Node::updateProgramStateTexture)
,"init",static_cast<bool(cocos2d::Node::*)()>(&cocos2d::Node::init)
,"setPhysicsBody",static_cast<void(cocos2d::Node::*)(cocos2d::PhysicsBody*)>(&cocos2d::Node::setPhysicsBody)
,"getPhysicsBody",static_cast<cocos2d::PhysicsBody*(cocos2d::Node::*)()const>(&cocos2d::Node::getPhysicsBody)
,"new",static_cast<cocos2d::Node*(*)()>(&cocos2d::Node::create)
,"getAttachedNodeCount",static_cast<int(*)()>(&cocos2d::Node::getAttachedNodeCount)
);}
static void RegisterLuaScene(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Scene"
,"getDescription",static_cast<std::string(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDescription)
,"getDefaultCamera",static_cast<cocos2d::Camera*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getDefaultCamera)
,"render",sol::overload([](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1){return obj->render(arg0,arg1);},[](cocos2d::Scene* obj,cocos2d::Renderer* arg0,const cocos2d::Mat4& arg1,const cocos2d::Mat4* arg2){return obj->render(arg0,arg1,arg2);})
,"removeAllChildren",static_cast<void(cocos2d::Scene::*)()>(&cocos2d::Scene::removeAllChildren)
,"init",static_cast<bool(cocos2d::Scene::*)()>(&cocos2d::Scene::init)
,"initWithSize",static_cast<bool(cocos2d::Scene::*)(const cocos2d::Size&)>(&cocos2d::Scene::initWithSize)
,"setCameraOrderDirty",static_cast<void(cocos2d::Scene::*)()>(&cocos2d::Scene::setCameraOrderDirty)
,"onProjectionChanged",static_cast<void(cocos2d::Scene::*)(cocos2d::EventCustom*)>(&cocos2d::Scene::onProjectionChanged)
,"getPhysicsWorld",static_cast<cocos2d::PhysicsWorld*(cocos2d::Scene::*)()const>(&cocos2d::Scene::getPhysicsWorld)
,"initWithPhysics",static_cast<bool(cocos2d::Scene::*)()>(&cocos2d::Scene::initWithPhysics)
,"stepPhysicsAndNavigation",static_cast<void(cocos2d::Scene::*)(float)>(&cocos2d::Scene::stepPhysicsAndNavigation)
,"new",static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::create)
,"createWithSize",static_cast<cocos2d::Scene*(*)(const cocos2d::Size&)>(&cocos2d::Scene::createWithSize)
,"createWithPhysics",static_cast<cocos2d::Scene*(*)()>(&cocos2d::Scene::createWithPhysics)
);}
static void RegisterLuaEvent(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","Event"
,"getType",static_cast<cocos2d::Event::Type(cocos2d::Event::*)()const>(&cocos2d::Event::getType)
,"stopPropagation",static_cast<void(cocos2d::Event::*)()>(&cocos2d::Event::stopPropagation)
,"isStopped",static_cast<bool(cocos2d::Event::*)()const>(&cocos2d::Event::isStopped)
,"getCurrentTarget",static_cast<cocos2d::Node*(cocos2d::Event::*)()>(&cocos2d::Event::getCurrentTarget)
);}
static void RegisterLuaEventTouch(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventTouch,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventTouch"
,"getEventCode",static_cast<cocos2d::EventTouch::EventCode(cocos2d::EventTouch::*)()const>(&cocos2d::EventTouch::getEventCode)
,"setEventCode",static_cast<void(cocos2d::EventTouch::*)(cocos2d::EventTouch::EventCode)>(&cocos2d::EventTouch::setEventCode)
);}
static void RegisterLuaGLView(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>("cc","GLView"
,"endToLua",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::end)
,"isOpenGLReady",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isOpenGLReady)
,"swapBuffers",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::swapBuffers)
,"setIMEKeyboardState",static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setIMEKeyboardState)
,"windowShouldClose",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::windowShouldClose)
,"pollEvents",static_cast<void(cocos2d::GLView::*)()>(&cocos2d::GLView::pollEvents)
,"getFrameSize",static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameSize)
,"setFrameSize",sol::overload(static_cast<void(cocos2d::GLView::*)(const cocos2d::Size&)>(&cocos2d::GLView::setFrameSize),static_cast<void(cocos2d::GLView::*)(float,float)>(&cocos2d::GLView::setFrameSize))
,"setFrameZoomFactor",static_cast<void(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setFrameZoomFactor)
,"getFrameZoomFactor",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getFrameZoomFactor)
,"setCursorVisible",static_cast<void(cocos2d::GLView::*)(bool)>(&cocos2d::GLView::setCursorVisible)
,"getRetinaFactor",static_cast<int(cocos2d::GLView::*)()const>(&cocos2d::GLView::getRetinaFactor)
,"setContentScaleFactor",static_cast<bool(cocos2d::GLView::*)(float)>(&cocos2d::GLView::setContentScaleFactor)
,"getContentScaleFactor",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getContentScaleFactor)
,"isRetinaDisplay",static_cast<bool(cocos2d::GLView::*)()const>(&cocos2d::GLView::isRetinaDisplay)
,"getVisibleSize",static_cast<cocos2d::Size(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleSize)
,"getVisibleOrigin",static_cast<cocos2d::Vec2(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleOrigin)
,"getVisibleRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getVisibleRect)
,"getSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getSafeAreaRect)
,"setDesignResolutionSize",static_cast<void(cocos2d::GLView::*)(float,float,ResolutionPolicy)>(&cocos2d::GLView::setDesignResolutionSize)
,"getDesignResolutionSize",static_cast<const cocos2d::Size&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getDesignResolutionSize)
,"setViewPortInPoints",static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setViewPortInPoints)
,"setScissorInPoints",static_cast<void(cocos2d::GLView::*)(float,float,float,float)>(&cocos2d::GLView::setScissorInPoints)
,"isScissorEnabled",static_cast<bool(cocos2d::GLView::*)()>(&cocos2d::GLView::isScissorEnabled)
,"getScissorRect",static_cast<cocos2d::Rect(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScissorRect)
,"setViewName",static_cast<void(cocos2d::GLView::*)(const std::string&)>(&cocos2d::GLView::setViewName)
,"getViewName",static_cast<const std::string&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewName)
,"setIcon",sol::overload(static_cast<void(cocos2d::GLView::*)(const std::vector<std::string>&)const>(&cocos2d::GLView::setIcon),static_cast<void(cocos2d::GLView::*)(const std::string&)const>(&cocos2d::GLView::setIcon))
,"setDefaultIcon",static_cast<void(cocos2d::GLView::*)()const>(&cocos2d::GLView::setDefaultIcon)
,"getViewPortRect",static_cast<const cocos2d::Rect&(cocos2d::GLView::*)()const>(&cocos2d::GLView::getViewPortRect)
,"getScaleX",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleX)
,"getScaleY",static_cast<float(cocos2d::GLView::*)()const>(&cocos2d::GLView::getScaleY)
,"getResolutionPolicy",static_cast<ResolutionPolicy(cocos2d::GLView::*)()const>(&cocos2d::GLView::getResolutionPolicy)
,"renderScene",static_cast<void(cocos2d::GLView::*)(cocos2d::Scene*,cocos2d::Renderer*)>(&cocos2d::GLView::renderScene)
,"setGLContextAttrs",static_cast<void(*)(GLContextAttrs&)>(&cocos2d::GLView::setGLContextAttrs)
,"getGLContextAttrs",static_cast<GLContextAttrs(*)()>(&cocos2d::GLView::getGLContextAttrs)
);}
static void RegisterLuaDirector(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Director>("cc","Director"
,"init",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::init)
,"getRunningScene",static_cast<cocos2d::Scene*(cocos2d::Director::*)()>(&cocos2d::Director::getRunningScene)
,"getAnimationInterval",static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getAnimationInterval)
,"setAnimationInterval",static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setAnimationInterval)
,"isDisplayStats",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isDisplayStats)
,"setDisplayStats",static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setDisplayStats)
,"getSecondsPerFrame",static_cast<float(cocos2d::Director::*)()>(&cocos2d::Director::getSecondsPerFrame)
,"getOpenGLView",static_cast<cocos2d::GLView*(cocos2d::Director::*)()>(&cocos2d::Director::getOpenGLView)
,"setOpenGLView",static_cast<void(cocos2d::Director::*)(cocos2d::GLView*)>(&cocos2d::Director::setOpenGLView)
,"getTextureCache",static_cast<cocos2d::TextureCache*(cocos2d::Director::*)()const>(&cocos2d::Director::getTextureCache)
,"isNextDeltaTimeZero",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isNextDeltaTimeZero)
,"setNextDeltaTimeZero",static_cast<void(cocos2d::Director::*)(bool)>(&cocos2d::Director::setNextDeltaTimeZero)
,"isPaused",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isPaused)
,"getTotalFrames",static_cast<unsigned int(cocos2d::Director::*)()>(&cocos2d::Director::getTotalFrames)
,"setViewport",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setViewport)
,"isSendCleanupToScene",static_cast<bool(cocos2d::Director::*)()>(&cocos2d::Director::isSendCleanupToScene)
,"getNotificationNode",static_cast<cocos2d::Node*(cocos2d::Director::*)()const>(&cocos2d::Director::getNotificationNode)
,"setNotificationNode",static_cast<void(cocos2d::Director::*)(cocos2d::Node*)>(&cocos2d::Director::setNotificationNode)
,"getWinSize",static_cast<const cocos2d::Size&(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSize)
,"getWinSizeInPixels",static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getWinSizeInPixels)
,"getVisibleSize",static_cast<cocos2d::Size(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleSize)
,"getVisibleOrigin",static_cast<cocos2d::Vec2(cocos2d::Director::*)()const>(&cocos2d::Director::getVisibleOrigin)
,"getSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::Director::*)()const>(&cocos2d::Director::getSafeAreaRect)
,"convertToGL",static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToGL)
,"convertToUI",static_cast<cocos2d::Vec2(cocos2d::Director::*)(const cocos2d::Vec2&)>(&cocos2d::Director::convertToUI)
,"getZEye",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getZEye)
,"runWithScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::runWithScene)
,"pushScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::pushScene)
,"popScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popScene)
,"popToRootScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::popToRootScene)
,"popToSceneStackLevel",static_cast<void(cocos2d::Director::*)(int)>(&cocos2d::Director::popToSceneStackLevel)
,"replaceScene",static_cast<void(cocos2d::Director::*)(cocos2d::Scene*)>(&cocos2d::Director::replaceScene)
,"endToLua",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::end)
,"pause",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::pause)
,"resume",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resume)
,"restart",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::restart)
,"stopAnimation",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::stopAnimation)
,"startAnimation",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::startAnimation)
,"drawScene",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::drawScene)
,"purgeCachedData",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::purgeCachedData)
,"setDefaultValues",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setDefaultValues)
,"setGLDefaultValues",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::setGLDefaultValues)
,"setClearColor",static_cast<void(cocos2d::Director::*)(const cocos2d::Color4F&)>(&cocos2d::Director::setClearColor)
,"mainLoop",sol::overload(static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::mainLoop),static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::mainLoop))
,"setContentScaleFactor",static_cast<void(cocos2d::Director::*)(float)>(&cocos2d::Director::setContentScaleFactor)
,"getContentScaleFactor",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getContentScaleFactor)
,"getScheduler",static_cast<cocos2d::Scheduler*(cocos2d::Director::*)()const>(&cocos2d::Director::getScheduler)
,"setScheduler",static_cast<void(cocos2d::Director::*)(cocos2d::Scheduler*)>(&cocos2d::Director::setScheduler)
,"getActionManager",static_cast<cocos2d::ActionManager*(cocos2d::Director::*)()const>(&cocos2d::Director::getActionManager)
,"setActionManager",static_cast<void(cocos2d::Director::*)(cocos2d::ActionManager*)>(&cocos2d::Director::setActionManager)
,"getEventDispatcher",static_cast<cocos2d::EventDispatcher*(cocos2d::Director::*)()const>(&cocos2d::Director::getEventDispatcher)
,"setEventDispatcher",static_cast<void(cocos2d::Director::*)(cocos2d::EventDispatcher*)>(&cocos2d::Director::setEventDispatcher)
,"getConsole",static_cast<cocos2d::Console*(cocos2d::Director::*)()const>(&cocos2d::Director::getConsole)
,"getDeltaTime",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getDeltaTime)
,"getFrameRate",static_cast<float(cocos2d::Director::*)()const>(&cocos2d::Director::getFrameRate)
,"pushMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::pushMatrix)
,"popMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::popMatrix)
,"loadIdentityMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)>(&cocos2d::Director::loadIdentityMatrix)
,"loadMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::loadMatrix)
,"multiplyMatrix",static_cast<void(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE,const cocos2d::Mat4&)>(&cocos2d::Director::multiplyMatrix)
,"getMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Director::*)(cocos2d::MATRIX_STACK_TYPE)const>(&cocos2d::Director::getMatrix)
,"resetMatrixStack",static_cast<void(cocos2d::Director::*)()>(&cocos2d::Director::resetMatrixStack)
,"isValid",static_cast<bool(cocos2d::Director::*)()const>(&cocos2d::Director::isValid)
,"getInstance",static_cast<cocos2d::Director*(*)()>(&cocos2d::Director::getInstance)
);}
static void RegisterLuaTimer(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Timer,cocos2d::Ref,cocos2d::LuaObject>("cc","Timer"
,"setupTimerWithInterval",static_cast<void(cocos2d::Timer::*)(float,unsigned int,float)>(&cocos2d::Timer::setupTimerWithInterval)
,"setAborted",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::setAborted)
,"isAborted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isAborted)
,"isExhausted",static_cast<bool(cocos2d::Timer::*)()const>(&cocos2d::Timer::isExhausted)
,"trigger",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::trigger)
,"cancel",static_cast<void(cocos2d::Timer::*)()>(&cocos2d::Timer::cancel)
,"update",static_cast<void(cocos2d::Timer::*)(float)>(&cocos2d::Timer::update)
);}
static void RegisterLuaScheduler(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Scheduler,cocos2d::Ref,cocos2d::LuaObject>("cc","Scheduler"
,"getTimeScale",static_cast<float(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::getTimeScale)
,"setTimeScale",static_cast<void(cocos2d::Scheduler::*)(float)>(&cocos2d::Scheduler::setTimeScale)
,"removeAllFunctionsToBePerformedInCocosThread",static_cast<void(cocos2d::Scheduler::*)()>(&cocos2d::Scheduler::removeAllFunctionsToBePerformedInCocosThread)
);}
static void RegisterLuaAsyncTaskPool(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AsyncTaskPool>("cc","AsyncTaskPool"
,"stopTasks",static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks)
,"enqueue",sol::overload(static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue),static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,cocos2d::AsyncTaskPool::TaskCallBack,void*,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue))
,"getInstance",static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance)
);}
static void RegisterLuaAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Action"
,"clone",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::clone)
,"reverse",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::reverse)
,"isDone",static_cast<bool(cocos2d::Action::*)()const>(&cocos2d::Action::isDone)
,"startWithTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::startWithTarget)
,"stop",static_cast<void(cocos2d::Action::*)()>(&cocos2d::Action::stop)
,"step",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::step)
,"update",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::update)
,"getTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getTarget)
,"setTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setTarget)
,"getOriginalTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getOriginalTarget)
,"setOriginalTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setOriginalTarget)
,"getTag",static_cast<int(cocos2d::Action::*)()const>(&cocos2d::Action::getTag)
,"setTag",static_cast<void(cocos2d::Action::*)(int)>(&cocos2d::Action::setTag)
,"getFlags",static_cast<unsigned int(cocos2d::Action::*)()const>(&cocos2d::Action::getFlags)
,"setFlags",static_cast<void(cocos2d::Action::*)(unsigned int)>(&cocos2d::Action::setFlags)
);}
static void RegisterLuaFiniteTimeAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FiniteTimeAction"
,"getDuration",static_cast<float(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::getDuration)
,"setDuration",static_cast<void(cocos2d::FiniteTimeAction::*)(float)>(&cocos2d::FiniteTimeAction::setDuration)
,"reverse",static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::reverse)
,"clone",static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::clone)
);}
static void RegisterLuaSpeed(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Speed,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Speed"
,"getSpeed",static_cast<float(cocos2d::Speed::*)()const>(&cocos2d::Speed::getSpeed)
,"setSpeed",static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::setSpeed)
,"setInnerAction",static_cast<void(cocos2d::Speed::*)(cocos2d::ActionInterval*)>(&cocos2d::Speed::setInnerAction)
,"getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::Speed::*)()const>(&cocos2d::Speed::getInnerAction)
,"clone",static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::clone)
,"reverse",static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::reverse)
,"startWithTarget",static_cast<void(cocos2d::Speed::*)(cocos2d::Node*)>(&cocos2d::Speed::startWithTarget)
,"stop",static_cast<void(cocos2d::Speed::*)()>(&cocos2d::Speed::stop)
,"step",static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::step)
,"isDone",static_cast<bool(cocos2d::Speed::*)()const>(&cocos2d::Speed::isDone)
,"initWithAction",static_cast<bool(cocos2d::Speed::*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::initWithAction)
,"new",static_cast<cocos2d::Speed*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::create)
);}
static void RegisterLuaFollow(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Follow,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Follow"
,"isBoundarySet",static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isBoundarySet)
,"setBoundarySet",static_cast<void(cocos2d::Follow::*)(bool)>(&cocos2d::Follow::setBoundarySet)
,"clone",static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::clone)
,"reverse",static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::reverse)
,"step",static_cast<void(cocos2d::Follow::*)(float)>(&cocos2d::Follow::step)
,"isDone",static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isDone)
,"stop",static_cast<void(cocos2d::Follow::*)()>(&cocos2d::Follow::stop)
,"initWithTarget",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->initWithTarget(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->initWithTarget(arg0,arg1);})
,"initWithTargetAndOffset",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->initWithTargetAndOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->initWithTargetAndOffset(arg0,arg1,arg2,arg3);})
,"new",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->create(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);})
,"createWithOffset",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->createWithOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->createWithOffset(arg0,arg1,arg2,arg3);})
);}
static void RegisterLuaImage(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Image,cocos2d::Ref,cocos2d::LuaObject>("cc","Image"
,"initWithImageFile",static_cast<bool(cocos2d::Image::*)(const std::string&)>(&cocos2d::Image::initWithImageFile)
,"getDataLen",static_cast<ssize_t(cocos2d::Image::*)()>(&cocos2d::Image::getDataLen)
,"getFileType",static_cast<cocos2d::Image::Format(cocos2d::Image::*)()>(&cocos2d::Image::getFileType)
,"getPixelFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::Image::*)()>(&cocos2d::Image::getPixelFormat)
,"getWidth",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getWidth)
,"getHeight",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getHeight)
,"getNumberOfMipmaps",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getNumberOfMipmaps)
,"hasPremultipliedAlpha",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasPremultipliedAlpha)
,"getFilePath",static_cast<std::string(cocos2d::Image::*)()const>(&cocos2d::Image::getFilePath)
,"getBitPerPixel",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getBitPerPixel)
,"hasAlpha",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasAlpha)
,"isCompressed",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::isCompressed)
,"saveToFile",sol::overload([](cocos2d::Image* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::Image* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);})
,"premultiplyAlpha",static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::premultiplyAlpha)
,"reversePremultipliedAlpha",static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::reversePremultipliedAlpha)
,"setPNGPremultipliedAlphaEnabled",static_cast<void(*)(bool)>(&cocos2d::Image::setPNGPremultipliedAlphaEnabled)
,"setCompressedImagesHavePMA",static_cast<void(*)(uint32_t,bool)>(&cocos2d::Image::setCompressedImagesHavePMA)
,"isCompressedImageHavePMA",static_cast<bool(*)(uint32_t)>(&cocos2d::Image::isCompressedImageHavePMA)
);}
static void RegisterLuaPolygonInfo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PolygonInfo>("cc","PolygonInfo"
,"setQuad",static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*)>(&cocos2d::PolygonInfo::setQuad)
,"setQuads",static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*,int)>(&cocos2d::PolygonInfo::setQuads)
,"setTriangles",static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::TrianglesCommand::Triangles&)>(&cocos2d::PolygonInfo::setTriangles)
,"getVertCount",static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getVertCount)
,"getTrianglesCount",static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getTrianglesCount)
,"getArea",static_cast<float(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getArea)
,"getRect",static_cast<const cocos2d::Rect&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getRect)
,"setRect",static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::Rect&)>(&cocos2d::PolygonInfo::setRect)
,"getFilename",static_cast<const std::string&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getFilename)
,"setFilename",static_cast<void(cocos2d::PolygonInfo::*)(const std::string&)>(&cocos2d::PolygonInfo::setFilename)
);}
static void RegisterLuaAutoPolygon(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AutoPolygon>("cc","AutoPolygon"
);}
static void RegisterLuaSpriteFrame(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SpriteFrame,cocos2d::Ref,cocos2d::LuaObject>("cc","SpriteFrame"
,"getRectInPixels",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRectInPixels)
,"setRectInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRectInPixels)
,"isRotated",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::isRotated)
,"setRotated",static_cast<void(cocos2d::SpriteFrame::*)(bool)>(&cocos2d::SpriteFrame::setRotated)
,"getRect",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRect)
,"setRect",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRect)
,"getCenterRect",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getCenterRect)
,"setCenterRectInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setCenterRectInPixels)
,"hasCenterRect",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasCenterRect)
,"getOffsetInPixels",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffsetInPixels)
,"setOffsetInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffsetInPixels)
,"getOriginalSizeInPixels",static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSizeInPixels)
,"setOriginalSizeInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSizeInPixels)
,"getOriginalSize",static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSize)
,"setOriginalSize",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSize)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::SpriteFrame::*)()>(&cocos2d::SpriteFrame::getTexture)
,"setTexture",static_cast<void(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrame::setTexture)
,"getOffset",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffset)
,"setOffset",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffset)
,"getAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getAnchorPoint)
,"setAnchorPoint",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setAnchorPoint)
,"hasAnchorPoint",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasAnchorPoint)
,"clone",static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::clone)
,"initWithTexture",sol::overload(static_cast<bool(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::initWithTexture),static_cast<bool(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::initWithTexture))
,"initWithTextureFilename",sol::overload(static_cast<bool(cocos2d::SpriteFrame::*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::initWithTextureFilename),static_cast<bool(cocos2d::SpriteFrame::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::initWithTextureFilename))
,"new",sol::overload(static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::create),static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::create))
,"createWithTexture",sol::overload(static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::createWithTexture),static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::createWithTexture))
);}
static void RegisterLuaAnimationFrame(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AnimationFrame,cocos2d::Ref,cocos2d::LuaObject>("cc","AnimationFrame"
,"getSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getSpriteFrame)
,"setSpriteFrame",static_cast<void(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*)>(&cocos2d::AnimationFrame::setSpriteFrame)
,"getDelayUnits",static_cast<float(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getDelayUnits)
,"setDelayUnits",static_cast<void(cocos2d::AnimationFrame::*)(float)>(&cocos2d::AnimationFrame::setDelayUnits)
,"getUserInfo",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()>(&cocos2d::AnimationFrame::getUserInfo),static_cast<const cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getUserInfo))
,"setUserInfo",static_cast<void(cocos2d::AnimationFrame::*)(const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::setUserInfo)
,"clone",static_cast<cocos2d::AnimationFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::clone)
,"initWithSpriteFrame",static_cast<bool(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::initWithSpriteFrame)
,"new",static_cast<cocos2d::AnimationFrame*(*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::create)
);}
static void RegisterLuaAnimation(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Animation,cocos2d::Ref,cocos2d::LuaObject>("cc","Animation"
,"addSpriteFrame",static_cast<void(cocos2d::Animation::*)(cocos2d::SpriteFrame*)>(&cocos2d::Animation::addSpriteFrame)
,"addSpriteFrameWithFile",static_cast<void(cocos2d::Animation::*)(const std::string&)>(&cocos2d::Animation::addSpriteFrameWithFile)
,"addSpriteFrameWithTexture",static_cast<void(cocos2d::Animation::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Animation::addSpriteFrameWithTexture)
,"getTotalDelayUnits",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getTotalDelayUnits)
,"setDelayPerUnit",static_cast<void(cocos2d::Animation::*)(float)>(&cocos2d::Animation::setDelayPerUnit)
,"getDelayPerUnit",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDelayPerUnit)
,"getDuration",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDuration)
,"getFrames",static_cast<const cocos2d::Vector<cocos2d::AnimationFrame *>&(cocos2d::Animation::*)()const>(&cocos2d::Animation::getFrames)
,"setFrames",static_cast<void(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&)>(&cocos2d::Animation::setFrames)
,"getRestoreOriginalFrame",static_cast<bool(cocos2d::Animation::*)()const>(&cocos2d::Animation::getRestoreOriginalFrame)
,"setRestoreOriginalFrame",static_cast<void(cocos2d::Animation::*)(bool)>(&cocos2d::Animation::setRestoreOriginalFrame)
,"getLoops",static_cast<unsigned int(cocos2d::Animation::*)()const>(&cocos2d::Animation::getLoops)
,"setLoops",static_cast<void(cocos2d::Animation::*)(unsigned int)>(&cocos2d::Animation::setLoops)
,"clone",static_cast<cocos2d::Animation*(cocos2d::Animation::*)()const>(&cocos2d::Animation::clone)
,"init",static_cast<bool(cocos2d::Animation::*)()>(&cocos2d::Animation::init)
,"initWithSpriteFrames",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->initWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->initWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->initWithSpriteFrames(arg0,arg1,arg2);})
,"initWithAnimationFrames",static_cast<bool(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&,float,unsigned int)>(&cocos2d::Animation::initWithAnimationFrames)
,"new",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1){return obj->create(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1,unsigned int arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::Animation*(*)()>(&cocos2d::Animation::create))
,"createWithSpriteFrames",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->createWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->createWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->createWithSpriteFrames(arg0,arg1,arg2);})
);}
static void RegisterLuaActionInterval(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionInterval"
,"getElapsed",static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getElapsed)
,"setAmplitudeRate",static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::setAmplitudeRate)
,"getAmplitudeRate",static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getAmplitudeRate)
,"isDone",static_cast<bool(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::isDone)
,"step",static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::step)
,"startWithTarget",static_cast<void(cocos2d::ActionInterval::*)(cocos2d::Node*)>(&cocos2d::ActionInterval::startWithTarget)
,"reverse",static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::reverse)
,"clone",static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::clone)
,"initWithDuration",static_cast<bool(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::initWithDuration)
);}
static void RegisterLuaSequence(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Sequence,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Sequence"
,"clone",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::clone)
,"reverse",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::reverse)
,"startWithTarget",static_cast<void(cocos2d::Sequence::*)(cocos2d::Node*)>(&cocos2d::Sequence::startWithTarget)
,"stop",static_cast<void(cocos2d::Sequence::*)()>(&cocos2d::Sequence::stop)
,"isDone",static_cast<bool(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::isDone)
,"update",static_cast<void(cocos2d::Sequence::*)(float)>(&cocos2d::Sequence::update)
,"initWithTwoActions",static_cast<bool(cocos2d::Sequence::*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Sequence::initWithTwoActions)
,"init",static_cast<bool(cocos2d::Sequence::*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Sequence::init)
);}
static void RegisterLuaRepeat(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Repeat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Repeat"
,"setInnerAction",static_cast<void(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*)>(&cocos2d::Repeat::setInnerAction)
,"getInnerAction",static_cast<cocos2d::FiniteTimeAction*(cocos2d::Repeat::*)()>(&cocos2d::Repeat::getInnerAction)
,"clone",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::clone)
,"reverse",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::reverse)
,"startWithTarget",static_cast<void(cocos2d::Repeat::*)(cocos2d::Node*)>(&cocos2d::Repeat::startWithTarget)
,"stop",static_cast<void(cocos2d::Repeat::*)()>(&cocos2d::Repeat::stop)
,"update",static_cast<void(cocos2d::Repeat::*)(float)>(&cocos2d::Repeat::update)
,"isDone",static_cast<bool(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::isDone)
,"initWithAction",static_cast<bool(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::initWithAction)
,"new",static_cast<cocos2d::Repeat*(*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::create)
);}
static void RegisterLuaRepeatForever(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::RepeatForever,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RepeatForever"
,"setInnerAction",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::setInnerAction)
,"getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::RepeatForever::*)()>(&cocos2d::RepeatForever::getInnerAction)
,"clone",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::clone)
,"reverse",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::reverse)
,"startWithTarget",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::Node*)>(&cocos2d::RepeatForever::startWithTarget)
,"step",static_cast<void(cocos2d::RepeatForever::*)(float)>(&cocos2d::RepeatForever::step)
,"isDone",static_cast<bool(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::isDone)
,"initWithAction",static_cast<bool(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::initWithAction)
,"new",static_cast<cocos2d::RepeatForever*(*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::create)
);}
static void RegisterLuaSpawn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Spawn,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Spawn"
,"clone",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::clone)
,"reverse",static_cast<cocos2d::Spawn*(cocos2d::Spawn::*)()const>(&cocos2d::Spawn::reverse)
,"startWithTarget",static_cast<void(cocos2d::Spawn::*)(cocos2d::Node*)>(&cocos2d::Spawn::startWithTarget)
,"stop",static_cast<void(cocos2d::Spawn::*)()>(&cocos2d::Spawn::stop)
,"update",static_cast<void(cocos2d::Spawn::*)(float)>(&cocos2d::Spawn::update)
,"initWithTwoActions",static_cast<bool(cocos2d::Spawn::*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Spawn::initWithTwoActions)
,"init",static_cast<bool(cocos2d::Spawn::*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Spawn::init)
);}
static void RegisterLuaRotateTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::RotateTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RotateTo"
,"clone",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::clone)
,"reverse",static_cast<cocos2d::RotateTo*(cocos2d::RotateTo::*)()const>(&cocos2d::RotateTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::RotateTo::*)(cocos2d::Node*)>(&cocos2d::RotateTo::startWithTarget)
,"update",static_cast<void(cocos2d::RotateTo::*)(float)>(&cocos2d::RotateTo::update)
,"initWithDuration",sol::overload(static_cast<bool(cocos2d::RotateTo::*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::initWithDuration),static_cast<bool(cocos2d::RotateTo::*)(float,float,float)>(&cocos2d::RotateTo::initWithDuration))
,"new",sol::overload(static_cast<cocos2d::RotateTo*(*)(float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,float,float)>(&cocos2d::RotateTo::create),static_cast<cocos2d::RotateTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateTo::create))
);}
static void RegisterLuaRotateBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::RotateBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RotateBy"
,"clone",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::clone)
,"reverse",static_cast<cocos2d::RotateBy*(cocos2d::RotateBy::*)()const>(&cocos2d::RotateBy::reverse)
,"startWithTarget",static_cast<void(cocos2d::RotateBy::*)(cocos2d::Node*)>(&cocos2d::RotateBy::startWithTarget)
,"update",static_cast<void(cocos2d::RotateBy::*)(float)>(&cocos2d::RotateBy::update)
,"initWithDuration",sol::overload(static_cast<bool(cocos2d::RotateBy::*)(float,float,float)>(&cocos2d::RotateBy::initWithDuration),static_cast<bool(cocos2d::RotateBy::*)(float,float)>(&cocos2d::RotateBy::initWithDuration),static_cast<bool(cocos2d::RotateBy::*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::initWithDuration))
,"new",sol::overload(static_cast<cocos2d::RotateBy*(*)(float,float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,float)>(&cocos2d::RotateBy::create),static_cast<cocos2d::RotateBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::RotateBy::create))
);}
static void RegisterLuaMoveBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","MoveBy"
,"clone",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::clone)
,"reverse",static_cast<cocos2d::MoveBy*(cocos2d::MoveBy::*)()const>(&cocos2d::MoveBy::reverse)
,"startWithTarget",static_cast<void(cocos2d::MoveBy::*)(cocos2d::Node*)>(&cocos2d::MoveBy::startWithTarget)
,"update",static_cast<void(cocos2d::MoveBy::*)(float)>(&cocos2d::MoveBy::update)
,"initWithDuration",sol::overload(static_cast<bool(cocos2d::MoveBy::*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::initWithDuration),static_cast<bool(cocos2d::MoveBy::*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::initWithDuration))
,"new",sol::overload(static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveBy::create),static_cast<cocos2d::MoveBy*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveBy::create))
);}
static void RegisterLuaMoveTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MoveTo,cocos2d::MoveBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","MoveTo"
,"clone",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::clone)
,"reverse",static_cast<cocos2d::MoveTo*(cocos2d::MoveTo::*)()const>(&cocos2d::MoveTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::MoveTo::*)(cocos2d::Node*)>(&cocos2d::MoveTo::startWithTarget)
,"initWithDuration",sol::overload(static_cast<bool(cocos2d::MoveTo::*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::initWithDuration),static_cast<bool(cocos2d::MoveTo::*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::initWithDuration))
,"new",sol::overload(static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec3&)>(&cocos2d::MoveTo::create),static_cast<cocos2d::MoveTo*(*)(float,const cocos2d::Vec2&)>(&cocos2d::MoveTo::create))
);}
static void RegisterLuaSkewTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SkewTo"
,"clone",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::clone)
,"reverse",static_cast<cocos2d::SkewTo*(cocos2d::SkewTo::*)()const>(&cocos2d::SkewTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::SkewTo::*)(cocos2d::Node*)>(&cocos2d::SkewTo::startWithTarget)
,"update",static_cast<void(cocos2d::SkewTo::*)(float)>(&cocos2d::SkewTo::update)
,"initWithDuration",static_cast<bool(cocos2d::SkewTo::*)(float,float,float)>(&cocos2d::SkewTo::initWithDuration)
,"new",static_cast<cocos2d::SkewTo*(*)(float,float,float)>(&cocos2d::SkewTo::create)
);}
static void RegisterLuaSkewBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SkewBy,cocos2d::SkewTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SkewBy"
,"startWithTarget",static_cast<void(cocos2d::SkewBy::*)(cocos2d::Node*)>(&cocos2d::SkewBy::startWithTarget)
,"clone",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::clone)
,"reverse",static_cast<cocos2d::SkewBy*(cocos2d::SkewBy::*)()const>(&cocos2d::SkewBy::reverse)
,"initWithDuration",static_cast<bool(cocos2d::SkewBy::*)(float,float,float)>(&cocos2d::SkewBy::initWithDuration)
,"new",static_cast<cocos2d::SkewBy*(*)(float,float,float)>(&cocos2d::SkewBy::create)
);}
static void RegisterLuaJumpBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpBy"
,"clone",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::clone)
,"reverse",static_cast<cocos2d::JumpBy*(cocos2d::JumpBy::*)()const>(&cocos2d::JumpBy::reverse)
,"startWithTarget",static_cast<void(cocos2d::JumpBy::*)(cocos2d::Node*)>(&cocos2d::JumpBy::startWithTarget)
,"update",static_cast<void(cocos2d::JumpBy::*)(float)>(&cocos2d::JumpBy::update)
,"initWithDuration",static_cast<bool(cocos2d::JumpBy::*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::initWithDuration)
,"new",static_cast<cocos2d::JumpBy*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpBy::create)
);}
static void RegisterLuaJumpTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::JumpTo,cocos2d::JumpBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpTo"
,"startWithTarget",static_cast<void(cocos2d::JumpTo::*)(cocos2d::Node*)>(&cocos2d::JumpTo::startWithTarget)
,"clone",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::clone)
,"reverse",static_cast<cocos2d::JumpTo*(cocos2d::JumpTo::*)()const>(&cocos2d::JumpTo::reverse)
,"initWithDuration",static_cast<bool(cocos2d::JumpTo::*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::initWithDuration)
,"new",static_cast<cocos2d::JumpTo*(*)(float,const cocos2d::Vec2&,float,int)>(&cocos2d::JumpTo::create)
);}
static void RegisterLuaBezierBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","BezierBy"
,"clone",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::clone)
,"reverse",static_cast<cocos2d::BezierBy*(cocos2d::BezierBy::*)()const>(&cocos2d::BezierBy::reverse)
,"startWithTarget",static_cast<void(cocos2d::BezierBy::*)(cocos2d::Node*)>(&cocos2d::BezierBy::startWithTarget)
,"update",static_cast<void(cocos2d::BezierBy::*)(float)>(&cocos2d::BezierBy::update)
,"initWithDuration",static_cast<bool(cocos2d::BezierBy::*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierBy::initWithDuration)
);}
static void RegisterLuaBezierTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::BezierTo,cocos2d::BezierBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","BezierTo"
,"startWithTarget",static_cast<void(cocos2d::BezierTo::*)(cocos2d::Node*)>(&cocos2d::BezierTo::startWithTarget)
,"clone",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::clone)
,"reverse",static_cast<cocos2d::BezierTo*(cocos2d::BezierTo::*)()const>(&cocos2d::BezierTo::reverse)
,"initWithDuration",static_cast<bool(cocos2d::BezierTo::*)(float,const cocos2d::ccBezierConfig&)>(&cocos2d::BezierTo::initWithDuration)
);}
static void RegisterLuaScaleTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ScaleTo"
,"clone",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::clone)
,"reverse",static_cast<cocos2d::ScaleTo*(cocos2d::ScaleTo::*)()const>(&cocos2d::ScaleTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::ScaleTo::*)(cocos2d::Node*)>(&cocos2d::ScaleTo::startWithTarget)
,"update",static_cast<void(cocos2d::ScaleTo::*)(float)>(&cocos2d::ScaleTo::update)
,"initWithDuration",sol::overload(static_cast<bool(cocos2d::ScaleTo::*)(float,float,float)>(&cocos2d::ScaleTo::initWithDuration),static_cast<bool(cocos2d::ScaleTo::*)(float,float)>(&cocos2d::ScaleTo::initWithDuration),static_cast<bool(cocos2d::ScaleTo::*)(float,float,float,float)>(&cocos2d::ScaleTo::initWithDuration))
,"new",sol::overload(static_cast<cocos2d::ScaleTo*(*)(float,float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float)>(&cocos2d::ScaleTo::create),static_cast<cocos2d::ScaleTo*(*)(float,float,float,float)>(&cocos2d::ScaleTo::create))
);}
static void RegisterLuaScaleBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ScaleBy,cocos2d::ScaleTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ScaleBy"
,"startWithTarget",static_cast<void(cocos2d::ScaleBy::*)(cocos2d::Node*)>(&cocos2d::ScaleBy::startWithTarget)
,"clone",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::clone)
,"reverse",static_cast<cocos2d::ScaleBy*(cocos2d::ScaleBy::*)()const>(&cocos2d::ScaleBy::reverse)
,"new",sol::overload(static_cast<cocos2d::ScaleBy*(*)(float,float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float)>(&cocos2d::ScaleBy::create),static_cast<cocos2d::ScaleBy*(*)(float,float,float,float)>(&cocos2d::ScaleBy::create))
);}
static void RegisterLuaBlink(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Blink,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Blink"
,"clone",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::clone)
,"reverse",static_cast<cocos2d::Blink*(cocos2d::Blink::*)()const>(&cocos2d::Blink::reverse)
,"update",static_cast<void(cocos2d::Blink::*)(float)>(&cocos2d::Blink::update)
,"startWithTarget",static_cast<void(cocos2d::Blink::*)(cocos2d::Node*)>(&cocos2d::Blink::startWithTarget)
,"stop",static_cast<void(cocos2d::Blink::*)()>(&cocos2d::Blink::stop)
,"initWithDuration",static_cast<bool(cocos2d::Blink::*)(float,int)>(&cocos2d::Blink::initWithDuration)
,"new",static_cast<cocos2d::Blink*(*)(float,int)>(&cocos2d::Blink::create)
);}
static void RegisterLuaFadeTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeTo"
,"clone",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::clone)
,"reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeTo::*)()const>(&cocos2d::FadeTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::FadeTo::*)(cocos2d::Node*)>(&cocos2d::FadeTo::startWithTarget)
,"update",static_cast<void(cocos2d::FadeTo::*)(float)>(&cocos2d::FadeTo::update)
,"initWithDuration",static_cast<bool(cocos2d::FadeTo::*)(float,uint8_t)>(&cocos2d::FadeTo::initWithDuration)
,"new",static_cast<cocos2d::FadeTo*(*)(float,uint8_t)>(&cocos2d::FadeTo::create)
);}
static void RegisterLuaFadeIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeIn,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeIn"
,"startWithTarget",static_cast<void(cocos2d::FadeIn::*)(cocos2d::Node*)>(&cocos2d::FadeIn::startWithTarget)
,"clone",static_cast<cocos2d::FadeIn*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::clone)
,"reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeIn::*)()const>(&cocos2d::FadeIn::reverse)
,"setReverseAction",static_cast<void(cocos2d::FadeIn::*)(cocos2d::FadeTo*)>(&cocos2d::FadeIn::setReverseAction)
,"new",static_cast<cocos2d::FadeIn*(*)(float)>(&cocos2d::FadeIn::create)
);}
static void RegisterLuaFadeOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeOut,cocos2d::FadeTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOut"
,"startWithTarget",static_cast<void(cocos2d::FadeOut::*)(cocos2d::Node*)>(&cocos2d::FadeOut::startWithTarget)
,"clone",static_cast<cocos2d::FadeOut*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::clone)
,"reverse",static_cast<cocos2d::FadeTo*(cocos2d::FadeOut::*)()const>(&cocos2d::FadeOut::reverse)
,"setReverseAction",static_cast<void(cocos2d::FadeOut::*)(cocos2d::FadeTo*)>(&cocos2d::FadeOut::setReverseAction)
,"new",static_cast<cocos2d::FadeOut*(*)(float)>(&cocos2d::FadeOut::create)
);}
static void RegisterLuaTintTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TintTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TintTo"
,"clone",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::clone)
,"reverse",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::TintTo::*)(cocos2d::Node*)>(&cocos2d::TintTo::startWithTarget)
,"update",static_cast<void(cocos2d::TintTo::*)(float)>(&cocos2d::TintTo::update)
,"initWithDuration",static_cast<bool(cocos2d::TintTo::*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::initWithDuration)
,"new",sol::overload(static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create))
);}
static void RegisterLuaTintBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TintBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TintBy"
,"clone",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::clone)
,"reverse",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::reverse)
,"startWithTarget",static_cast<void(cocos2d::TintBy::*)(cocos2d::Node*)>(&cocos2d::TintBy::startWithTarget)
,"update",static_cast<void(cocos2d::TintBy::*)(float)>(&cocos2d::TintBy::update)
,"initWithDuration",static_cast<bool(cocos2d::TintBy::*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::initWithDuration)
,"new",static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create)
);}
static void RegisterLuaDelayTime(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::DelayTime,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","DelayTime"
,"update",static_cast<void(cocos2d::DelayTime::*)(float)>(&cocos2d::DelayTime::update)
,"reverse",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::reverse)
,"clone",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::clone)
,"new",static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create)
);}
static void RegisterLuaAnimate(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Animate,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Animate"
,"setAnimation",static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation)
,"getAnimation",sol::overload(static_cast<const cocos2d::Animation*(cocos2d::Animate::*)()const>(&cocos2d::Animate::getAnimation),static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation))
,"getCurrentFrameIndex",static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex)
,"clone",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::clone)
,"reverse",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::reverse)
,"startWithTarget",static_cast<void(cocos2d::Animate::*)(cocos2d::Node*)>(&cocos2d::Animate::startWithTarget)
,"stop",static_cast<void(cocos2d::Animate::*)()>(&cocos2d::Animate::stop)
,"update",static_cast<void(cocos2d::Animate::*)(float)>(&cocos2d::Animate::update)
,"initWithAnimation",static_cast<bool(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::initWithAnimation)
,"new",static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create)
);}
static void RegisterLuaTargetedAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TargetedAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TargetedAction"
,"setForcedTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget)
,"getForcedTarget",sol::overload(static_cast<const cocos2d::Node*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::getForcedTarget),static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget))
,"clone",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::clone)
,"reverse",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::reverse)
,"startWithTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::startWithTarget)
,"stop",static_cast<void(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::stop)
,"update",static_cast<void(cocos2d::TargetedAction::*)(float)>(&cocos2d::TargetedAction::update)
,"initWithTarget",static_cast<bool(cocos2d::TargetedAction::*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::initWithTarget)
,"new",static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create)
);}
static void RegisterLuaActionFloat(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionFloat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionFloat"
,"startWithTarget",static_cast<void(cocos2d::ActionFloat::*)(cocos2d::Node*)>(&cocos2d::ActionFloat::startWithTarget)
,"update",static_cast<void(cocos2d::ActionFloat::*)(float)>(&cocos2d::ActionFloat::update)
,"reverse",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::reverse)
,"clone",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::clone)
,"initWithDuration",static_cast<bool(cocos2d::ActionFloat::*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::initWithDuration)
,"new",static_cast<cocos2d::ActionFloat*(*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::create)
);}
static void RegisterLuaEventKeyboard(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventKeyboard,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventKeyboard"
);}
static void RegisterLuaProperties(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Properties>("cc","Properties"
,"getNextProperty",static_cast<const char*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextProperty)
,"getNextNamespace",static_cast<cocos2d::Properties*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextNamespace)
,"rewind",static_cast<void(cocos2d::Properties::*)()>(&cocos2d::Properties::rewind)
,"getNamespace",sol::overload(static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getNamespace),[](cocos2d::Properties* obj,const char* arg0){return obj->getNamespace(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getNamespace(arg0,arg1);},[](cocos2d::Properties* obj,const char* arg0,bool arg1,bool arg2){return obj->getNamespace(arg0,arg1,arg2);})
,"getId",static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getId)
,"exists",static_cast<bool(cocos2d::Properties::*)(const char*)const>(&cocos2d::Properties::exists)
,"getType",sol::overload([](cocos2d::Properties* obj){return obj->getType();},[](cocos2d::Properties* obj,const char* arg0){return obj->getType(arg0);})
,"getString",sol::overload([](cocos2d::Properties* obj){return obj->getString();},[](cocos2d::Properties* obj,const char* arg0){return obj->getString(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getString(arg0,arg1);})
,"setString",static_cast<bool(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setString)
,"getBool",sol::overload([](cocos2d::Properties* obj){return obj->getBool();},[](cocos2d::Properties* obj,const char* arg0){return obj->getBool(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getBool(arg0,arg1);})
,"getInt",sol::overload([](cocos2d::Properties* obj){return obj->getInt();},[](cocos2d::Properties* obj,const char* arg0){return obj->getInt(arg0);})
,"getFloat",sol::overload([](cocos2d::Properties* obj){return obj->getFloat();},[](cocos2d::Properties* obj,const char* arg0){return obj->getFloat(arg0);})
,"getLong",sol::overload([](cocos2d::Properties* obj){return obj->getLong();},[](cocos2d::Properties* obj,const char* arg0){return obj->getLong(arg0);})
,"getMat4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Mat4*)const>(&cocos2d::Properties::getMat4)
,"getVec2",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec2*)const>(&cocos2d::Properties::getVec2)
,"getVec3",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getVec3)
,"getVec4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getVec4)
,"getQuaternionFromAxisAngle",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Quaternion*)const>(&cocos2d::Properties::getQuaternionFromAxisAngle)
,"getColor",sol::overload(static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getColor),static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getColor))
,"getPath",static_cast<bool(cocos2d::Properties::*)(const char*,std::string*)const>(&cocos2d::Properties::getPath)
,"getVariable",sol::overload([](cocos2d::Properties* obj,const char* arg0){return obj->getVariable(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getVariable(arg0,arg1);})
,"setVariable",static_cast<void(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setVariable)
,"parseVec2",static_cast<bool(*)(const char*,cocos2d::Vec2*)>(&cocos2d::Properties::parseVec2)
,"parseVec3",static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseVec3)
,"parseVec4",static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseVec4)
,"parseAxisAngle",static_cast<bool(*)(const char*,cocos2d::Quaternion*)>(&cocos2d::Properties::parseAxisAngle)
,"parseColor",sol::overload(static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseColor),static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseColor))
);}
static void RegisterLuaUserDefault(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::UserDefault>("cc","UserDefault"
,"getBoolForKey",sol::overload(static_cast<bool(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::getBoolForKey),static_cast<bool(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getBoolForKey))
,"getIntegerForKey",sol::overload(static_cast<int(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::getIntegerForKey),static_cast<int(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getIntegerForKey))
,"getLargeIntForKey",sol::overload(static_cast<int64_t(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::getLargeIntForKey),static_cast<int64_t(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getLargeIntForKey))
,"getFloatForKey",sol::overload(static_cast<float(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::getFloatForKey),static_cast<float(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getFloatForKey))
,"getDoubleForKey",sol::overload(static_cast<double(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::getDoubleForKey),static_cast<double(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getDoubleForKey))
,"getStringForKey",sol::overload(static_cast<std::string(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::getStringForKey),static_cast<std::string(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getStringForKey))
,"setBoolForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::setBoolForKey)
,"setIntegerForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::setIntegerForKey)
,"setLargeIntForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::setLargeIntForKey)
,"setFloatForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::setFloatForKey)
,"setDoubleForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::setDoubleForKey)
,"setStringForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::setStringForKey)
,"flush",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::flush)
,"deleteValueForKey",static_cast<void(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::deleteValueForKey)
,"Clear",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::Clear)
,"setEncryptEnabled",static_cast<void(cocos2d::UserDefault::*)(bool,cxx17::string_view,cxx17::string_view)>(&cocos2d::UserDefault::setEncryptEnabled)
,"getInstance",static_cast<cocos2d::UserDefault*(*)()>(&cocos2d::UserDefault::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::UserDefault::destroyInstance)
);}
static void RegisterLuaFileUtils(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FileUtils>("cc","FileUtils"
,"purgeCachedEntries",static_cast<void(cocos2d::FileUtils::*)()>(&cocos2d::FileUtils::purgeCachedEntries)
,"getStringFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::string)>)const>(&cocos2d::FileUtils::getStringFromFile),static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getStringFromFile))
,"fullPathForFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::fullPathForFilename)
,"loadFilenameLookup",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::loadFilenameLookupDictionaryFromFile)
,"setFilenameLookupDictionary",static_cast<void(cocos2d::FileUtils::*)(const cocos2d::ValueMap&)>(&cocos2d::FileUtils::setFilenameLookupDictionary)
,"fullPathFromRelativeFile",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::fullPathFromRelativeFile)
,"setSearchResolutionsOrder",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchResolutionsOrder)
,"addSearchResolutionsOrder",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchResolutionsOrder(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchResolutionsOrder(arg0,arg1);})
,"getSearchResolutionsOrder",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchResolutionsOrder)
,"setSearchPaths",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchPaths)
,"getDefaultResourceRootPath",static_cast<const std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getDefaultResourceRootPath)
,"setDefaultResourceRootPath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setDefaultResourceRootPath)
,"addSearchPath",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchPath(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchPath(arg0,arg1);})
,"getSearchPaths",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchPaths)
,"getOriginalSearchPaths",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getOriginalSearchPaths)
,"getWritablePath",static_cast<std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getWritablePath)
,"setWritablePath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setWritablePath)
,"setPopupNotify",static_cast<void(cocos2d::FileUtils::*)(bool)>(&cocos2d::FileUtils::setPopupNotify)
,"isPopupNotify",static_cast<bool(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::isPopupNotify)
,"getValueMapFromFile",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueMapFromFile)
,"getValueMapFromData",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const char*,int)const>(&cocos2d::FileUtils::getValueMapFromData)
,"writeToFile",static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeToFile)
,"writeStringToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(std::string,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeStringToFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::writeStringToFile))
,"writeValueMapToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueMap,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueMapToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeValueMapToFile))
,"writeValueVectorToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueVector,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueVectorToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueVector&,const std::string&)const>(&cocos2d::FileUtils::writeValueVectorToFile))
,"getValueVectorFromFile",static_cast<cocos2d::ValueVector(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueVectorFromFile)
,"isFileExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isFileExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExist))
,"getFileExtension",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileExtension)
,"isAbsolutePath",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isAbsolutePath)
,"isDirectoryExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isDirectoryExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExist))
,"createDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::createDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::createDirectory))
,"removeDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeDirectory))
,"removeFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeFile))
,"renameFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile))
,"getFileSize",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (long long)>)const>(&cocos2d::FileUtils::getFileSize),static_cast<int64_t(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileSize))
,"listFiles",static_cast<std::vector<std::string>(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::listFiles)
,"listFilesAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesAsync)
,"listFilesRecursively",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::vector<std::string>*)const>(&cocos2d::FileUtils::listFilesRecursively)
,"listFilesRecursivelyAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesRecursivelyAsync)
,"getNewFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getNewFilename)
,"isFileExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExistInternal)
,"isDirectoryExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExistInternal)
,"getInstance",static_cast<cocos2d::FileUtils*(*)()>(&cocos2d::FileUtils::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::FileUtils::destroyInstance)
,"writeBinaryToFile",static_cast<bool(*)(const void*,size_t,const std::string&)>(&cocos2d::FileUtils::writeBinaryToFile)
,"getFileShortName",static_cast<std::string(*)(const std::string&)>(&cocos2d::FileUtils::getFileShortName)
);}
static void RegisterLuaEventAcceleration(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventAcceleration,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventAcceleration"
);}
static void RegisterLuaEventCustom(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventCustom,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventCustom"
,"getEventName",static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName)
);}
static void RegisterLuaEventDispatcher(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventDispatcher,cocos2d::Ref,cocos2d::LuaObject>("cc","EventDispatcher"
,"addEventListenerWithSceneGraphPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority)
,"addEventListenerWithFixedPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority)
,"removeEventListener",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*)>(&cocos2d::EventDispatcher::removeEventListener)
,"removeEventListenersForType",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener::Type)>(&cocos2d::EventDispatcher::removeEventListenersForType)
,"removeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->removeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->removeEventListenersForTarget(arg0,arg1);})
,"removeCustomEventListeners",static_cast<void(cocos2d::EventDispatcher::*)(const std::string&)>(&cocos2d::EventDispatcher::removeCustomEventListeners)
,"removeAllEventListeners",static_cast<void(cocos2d::EventDispatcher::*)()>(&cocos2d::EventDispatcher::removeAllEventListeners)
,"pauseEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->pauseEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->pauseEventListenersForTarget(arg0,arg1);})
,"resumeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->resumeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->resumeEventListenersForTarget(arg0,arg1);})
,"setPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::setPriority)
,"setEnabled",static_cast<void(cocos2d::EventDispatcher::*)(bool)>(&cocos2d::EventDispatcher::setEnabled)
,"isEnabled",static_cast<bool(cocos2d::EventDispatcher::*)()const>(&cocos2d::EventDispatcher::isEnabled)
,"dispatchEvent",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::Event*)>(&cocos2d::EventDispatcher::dispatchEvent)
,"dispatchCustomEvent",sol::overload([](cocos2d::EventDispatcher* obj,const std::string& arg0){return obj->dispatchCustomEvent(arg0);},[](cocos2d::EventDispatcher* obj,const std::string& arg0,void* arg1){return obj->dispatchCustomEvent(arg0,arg1);})
,"hasEventListener",static_cast<bool(cocos2d::EventDispatcher::*)(const cocos2d::EventListener::ListenerID&)const>(&cocos2d::EventDispatcher::hasEventListener)
);}
static void RegisterLuaEventFocus(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventFocus,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventFocus"
);}
static void RegisterLuaEventListenerAcceleration(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerAcceleration,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerAcceleration"
,"clone",static_cast<cocos2d::EventListenerAcceleration*(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::clone)
,"checkAvailable",static_cast<bool(cocos2d::EventListenerAcceleration::*)()>(&cocos2d::EventListenerAcceleration::checkAvailable)
,"init",static_cast<bool(cocos2d::EventListenerAcceleration::*)(const std::function<void (cocos2d::Acceleration *, cocos2d::Event *)>&)>(&cocos2d::EventListenerAcceleration::init)
);}
static void RegisterLuaEventListenerFocus(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerFocus,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerFocus"
,"clone",static_cast<cocos2d::EventListenerFocus*(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::clone)
,"checkAvailable",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::checkAvailable)
,"init",static_cast<bool(cocos2d::EventListenerFocus::*)()>(&cocos2d::EventListenerFocus::init)
);}
static void RegisterLuaEventListenerKeyboard(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerKeyboard,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerKeyboard"
,"clone",static_cast<cocos2d::EventListenerKeyboard*(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::clone)
,"checkAvailable",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::checkAvailable)
,"init",static_cast<bool(cocos2d::EventListenerKeyboard::*)()>(&cocos2d::EventListenerKeyboard::init)
);}
static void RegisterLuaEventMouse(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventMouse,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventMouse"
,"setScrollData",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setScrollData)
,"getScrollX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollX)
,"getScrollY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getScrollY)
,"setCursorPosition",static_cast<void(cocos2d::EventMouse::*)(float,float)>(&cocos2d::EventMouse::setCursorPosition)
,"setMouseButton",static_cast<void(cocos2d::EventMouse::*)(cocos2d::EventMouse::MouseButton)>(&cocos2d::EventMouse::setMouseButton)
,"getMouseButton",static_cast<cocos2d::EventMouse::MouseButton(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getMouseButton)
,"getCursorX",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorX)
,"getCursorY",static_cast<float(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getCursorY)
,"getLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocation)
,"getPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocation)
,"getStartLocation",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocation)
,"getDelta",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getDelta)
,"getLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getLocationInView)
,"getPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getPreviousLocationInView)
,"getStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::EventMouse::*)()const>(&cocos2d::EventMouse::getStartLocationInView)
);}
static void RegisterLuaEventListenerMouse(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerMouse,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerMouse"
,"clone",static_cast<cocos2d::EventListenerMouse*(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::clone)
,"checkAvailable",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::checkAvailable)
,"init",static_cast<bool(cocos2d::EventListenerMouse::*)()>(&cocos2d::EventListenerMouse::init)
);}
static void RegisterLuaEventListenerController(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerController,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerController"
,"checkAvailable",static_cast<bool(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::checkAvailable)
,"clone",static_cast<cocos2d::EventListenerController*(cocos2d::EventListenerController::*)()>(&cocos2d::EventListenerController::clone)
);}
static void RegisterLuaEventListenerTouchOneByOne(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerTouchOneByOne,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerTouchOneByOne"
,"setSwallowTouches",static_cast<void(cocos2d::EventListenerTouchOneByOne::*)(bool)>(&cocos2d::EventListenerTouchOneByOne::setSwallowTouches)
,"isSwallowTouches",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::isSwallowTouches)
,"clone",static_cast<cocos2d::EventListenerTouchOneByOne*(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::clone)
,"checkAvailable",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::checkAvailable)
,"init",static_cast<bool(cocos2d::EventListenerTouchOneByOne::*)()>(&cocos2d::EventListenerTouchOneByOne::init)
);}
static void RegisterLuaEventListenerTouchAllAtOnce(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventListenerTouchAllAtOnce,cocos2d::EventListener,cocos2d::Ref,cocos2d::LuaObject>("cc","EventListenerTouchAllAtOnce"
,"clone",static_cast<cocos2d::EventListenerTouchAllAtOnce*(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::clone)
,"checkAvailable",static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::checkAvailable)
,"init",static_cast<bool(cocos2d::EventListenerTouchAllAtOnce::*)()>(&cocos2d::EventListenerTouchAllAtOnce::init)
);}
static void RegisterLuaEventController(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EventController,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("cc","EventController"
,"getControllerEventType",static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType)
,"getController",static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController)
,"getKeyCode",static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode)
,"setKeyCode",static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode)
,"setConnectStatus",static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus)
,"isConnected",static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected)
);}
static void RegisterLuaActionCamera(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionCamera"
,"startWithTarget",static_cast<void(cocos2d::ActionCamera::*)(cocos2d::Node*)>(&cocos2d::ActionCamera::startWithTarget)
,"reverse",static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::reverse)
,"clone",static_cast<cocos2d::ActionCamera*(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::clone)
,"setEye",sol::overload(static_cast<void(cocos2d::ActionCamera::*)(float,float,float)>(&cocos2d::ActionCamera::setEye),static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setEye))
,"getEye",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getEye)
,"setCenter",static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setCenter)
,"getCenter",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getCenter)
,"setUp",static_cast<void(cocos2d::ActionCamera::*)(const cocos2d::Vec3&)>(&cocos2d::ActionCamera::setUp)
,"getUp",static_cast<const cocos2d::Vec3&(cocos2d::ActionCamera::*)()const>(&cocos2d::ActionCamera::getUp)
);}
static void RegisterLuaOrbitCamera(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::OrbitCamera,cocos2d::ActionCamera,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","OrbitCamera"
,"clone",static_cast<cocos2d::OrbitCamera*(cocos2d::OrbitCamera::*)()const>(&cocos2d::OrbitCamera::clone)
,"startWithTarget",static_cast<void(cocos2d::OrbitCamera::*)(cocos2d::Node*)>(&cocos2d::OrbitCamera::startWithTarget)
,"update",static_cast<void(cocos2d::OrbitCamera::*)(float)>(&cocos2d::OrbitCamera::update)
,"initWithDuration",static_cast<bool(cocos2d::OrbitCamera::*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::initWithDuration)
,"new",static_cast<cocos2d::OrbitCamera*(*)(float,float,float,float,float,float,float)>(&cocos2d::OrbitCamera::create)
);}
static void RegisterLuaCardinalSplineTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CardinalSplineTo"
,"initWithDuration",static_cast<bool(cocos2d::CardinalSplineTo::*)(float,cocos2d::PointArray*,float)>(&cocos2d::CardinalSplineTo::initWithDuration)
,"updatePosition",static_cast<void(cocos2d::CardinalSplineTo::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineTo::updatePosition)
,"getPoints",static_cast<cocos2d::PointArray*(cocos2d::CardinalSplineTo::*)()>(&cocos2d::CardinalSplineTo::getPoints)
,"clone",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::clone)
,"reverse",static_cast<cocos2d::CardinalSplineTo*(cocos2d::CardinalSplineTo::*)()const>(&cocos2d::CardinalSplineTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::CardinalSplineTo::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineTo::startWithTarget)
,"update",static_cast<void(cocos2d::CardinalSplineTo::*)(float)>(&cocos2d::CardinalSplineTo::update)
);}
static void RegisterLuaCardinalSplineBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CardinalSplineBy"
,"startWithTarget",static_cast<void(cocos2d::CardinalSplineBy::*)(cocos2d::Node*)>(&cocos2d::CardinalSplineBy::startWithTarget)
,"updatePosition",static_cast<void(cocos2d::CardinalSplineBy::*)(const cocos2d::Vec2&)>(&cocos2d::CardinalSplineBy::updatePosition)
,"clone",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::clone)
,"reverse",static_cast<cocos2d::CardinalSplineBy*(cocos2d::CardinalSplineBy::*)()const>(&cocos2d::CardinalSplineBy::reverse)
);}
static void RegisterLuaCatmullRomTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CatmullRomTo,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CatmullRomTo"
,"initWithDuration",static_cast<bool(cocos2d::CatmullRomTo::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomTo::initWithDuration)
,"clone",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::clone)
,"reverse",static_cast<cocos2d::CatmullRomTo*(cocos2d::CatmullRomTo::*)()const>(&cocos2d::CatmullRomTo::reverse)
);}
static void RegisterLuaCatmullRomBy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CatmullRomBy,cocos2d::CardinalSplineBy,cocos2d::CardinalSplineTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CatmullRomBy"
,"initWithDuration",static_cast<bool(cocos2d::CatmullRomBy::*)(float,cocos2d::PointArray*)>(&cocos2d::CatmullRomBy::initWithDuration)
,"clone",static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::clone)
,"reverse",static_cast<cocos2d::CatmullRomBy*(cocos2d::CatmullRomBy::*)()const>(&cocos2d::CatmullRomBy::reverse)
);}
static void RegisterLuaActionEase(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionEase"
,"getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::getInnerAction)
,"startWithTarget",static_cast<void(cocos2d::ActionEase::*)(cocos2d::Node*)>(&cocos2d::ActionEase::startWithTarget)
,"stop",static_cast<void(cocos2d::ActionEase::*)()>(&cocos2d::ActionEase::stop)
,"update",static_cast<void(cocos2d::ActionEase::*)(float)>(&cocos2d::ActionEase::update)
,"initWithAction",static_cast<bool(cocos2d::ActionEase::*)(cocos2d::ActionInterval*)>(&cocos2d::ActionEase::initWithAction)
);}
static void RegisterLuaEaseRateAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseRateAction"
,"setRate",static_cast<void(cocos2d::EaseRateAction::*)(float)>(&cocos2d::EaseRateAction::setRate)
,"getRate",static_cast<float(cocos2d::EaseRateAction::*)()const>(&cocos2d::EaseRateAction::getRate)
,"initWithAction",static_cast<bool(cocos2d::EaseRateAction::*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::initWithAction)
,"new",static_cast<cocos2d::EaseRateAction*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseRateAction::create)
);}
static void RegisterLuaEaseExponentialIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseExponentialIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseExponentialIn"
,"clone",static_cast<cocos2d::EaseExponentialIn*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::clone)
,"update",static_cast<void(cocos2d::EaseExponentialIn::*)(float)>(&cocos2d::EaseExponentialIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialIn::*)()const>(&cocos2d::EaseExponentialIn::reverse)
,"new",static_cast<cocos2d::EaseExponentialIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialIn::create)
);}
static void RegisterLuaEaseExponentialOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseExponentialOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseExponentialOut"
,"clone",static_cast<cocos2d::EaseExponentialOut*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::clone)
,"update",static_cast<void(cocos2d::EaseExponentialOut::*)(float)>(&cocos2d::EaseExponentialOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialOut::*)()const>(&cocos2d::EaseExponentialOut::reverse)
,"new",static_cast<cocos2d::EaseExponentialOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialOut::create)
);}
static void RegisterLuaEaseExponentialInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseExponentialInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseExponentialInOut"
,"clone",static_cast<cocos2d::EaseExponentialInOut*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::clone)
,"update",static_cast<void(cocos2d::EaseExponentialInOut::*)(float)>(&cocos2d::EaseExponentialInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseExponentialInOut::*)()const>(&cocos2d::EaseExponentialInOut::reverse)
,"new",static_cast<cocos2d::EaseExponentialInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseExponentialInOut::create)
);}
static void RegisterLuaEaseSineIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseSineIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseSineIn"
,"clone",static_cast<cocos2d::EaseSineIn*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::clone)
,"update",static_cast<void(cocos2d::EaseSineIn::*)(float)>(&cocos2d::EaseSineIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineIn::*)()const>(&cocos2d::EaseSineIn::reverse)
,"new",static_cast<cocos2d::EaseSineIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineIn::create)
);}
static void RegisterLuaEaseSineOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseSineOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseSineOut"
,"clone",static_cast<cocos2d::EaseSineOut*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::clone)
,"update",static_cast<void(cocos2d::EaseSineOut::*)(float)>(&cocos2d::EaseSineOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineOut::*)()const>(&cocos2d::EaseSineOut::reverse)
,"new",static_cast<cocos2d::EaseSineOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineOut::create)
);}
static void RegisterLuaEaseSineInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseSineInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseSineInOut"
,"clone",static_cast<cocos2d::EaseSineInOut*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::clone)
,"update",static_cast<void(cocos2d::EaseSineInOut::*)(float)>(&cocos2d::EaseSineInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseSineInOut::*)()const>(&cocos2d::EaseSineInOut::reverse)
,"new",static_cast<cocos2d::EaseSineInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseSineInOut::create)
);}
static void RegisterLuaEaseBounce(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBounce,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBounce"
);}
static void RegisterLuaEaseBounceIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBounceIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBounceIn"
,"clone",static_cast<cocos2d::EaseBounceIn*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::clone)
,"update",static_cast<void(cocos2d::EaseBounceIn::*)(float)>(&cocos2d::EaseBounceIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceIn::*)()const>(&cocos2d::EaseBounceIn::reverse)
,"new",static_cast<cocos2d::EaseBounceIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceIn::create)
);}
static void RegisterLuaEaseBounceOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBounceOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBounceOut"
,"clone",static_cast<cocos2d::EaseBounceOut*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::clone)
,"update",static_cast<void(cocos2d::EaseBounceOut::*)(float)>(&cocos2d::EaseBounceOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceOut::*)()const>(&cocos2d::EaseBounceOut::reverse)
,"new",static_cast<cocos2d::EaseBounceOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceOut::create)
);}
static void RegisterLuaEaseBounceInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBounceInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBounceInOut"
,"clone",static_cast<cocos2d::EaseBounceInOut*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::clone)
,"update",static_cast<void(cocos2d::EaseBounceInOut::*)(float)>(&cocos2d::EaseBounceInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBounceInOut::*)()const>(&cocos2d::EaseBounceInOut::reverse)
,"new",static_cast<cocos2d::EaseBounceInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBounceInOut::create)
);}
static void RegisterLuaEaseBackIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBackIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBackIn"
,"clone",static_cast<cocos2d::EaseBackIn*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::clone)
,"update",static_cast<void(cocos2d::EaseBackIn::*)(float)>(&cocos2d::EaseBackIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackIn::*)()const>(&cocos2d::EaseBackIn::reverse)
,"new",static_cast<cocos2d::EaseBackIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackIn::create)
);}
static void RegisterLuaEaseBackOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBackOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBackOut"
,"clone",static_cast<cocos2d::EaseBackOut*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::clone)
,"update",static_cast<void(cocos2d::EaseBackOut::*)(float)>(&cocos2d::EaseBackOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackOut::*)()const>(&cocos2d::EaseBackOut::reverse)
,"new",static_cast<cocos2d::EaseBackOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackOut::create)
);}
static void RegisterLuaEaseBackInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBackInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBackInOut"
,"clone",static_cast<cocos2d::EaseBackInOut*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::clone)
,"update",static_cast<void(cocos2d::EaseBackInOut::*)(float)>(&cocos2d::EaseBackInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseBackInOut::*)()const>(&cocos2d::EaseBackInOut::reverse)
,"new",static_cast<cocos2d::EaseBackInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBackInOut::create)
);}
static void RegisterLuaEaseQuadraticActionIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuadraticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuadraticActionIn"
,"clone",static_cast<cocos2d::EaseQuadraticActionIn*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::clone)
,"update",static_cast<void(cocos2d::EaseQuadraticActionIn::*)(float)>(&cocos2d::EaseQuadraticActionIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionIn::*)()const>(&cocos2d::EaseQuadraticActionIn::reverse)
,"new",static_cast<cocos2d::EaseQuadraticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionIn::create)
);}
static void RegisterLuaEaseQuadraticActionOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuadraticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuadraticActionOut"
,"clone",static_cast<cocos2d::EaseQuadraticActionOut*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::clone)
,"update",static_cast<void(cocos2d::EaseQuadraticActionOut::*)(float)>(&cocos2d::EaseQuadraticActionOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionOut::*)()const>(&cocos2d::EaseQuadraticActionOut::reverse)
,"new",static_cast<cocos2d::EaseQuadraticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionOut::create)
);}
static void RegisterLuaEaseQuadraticActionInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuadraticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuadraticActionInOut"
,"clone",static_cast<cocos2d::EaseQuadraticActionInOut*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::clone)
,"update",static_cast<void(cocos2d::EaseQuadraticActionInOut::*)(float)>(&cocos2d::EaseQuadraticActionInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuadraticActionInOut::*)()const>(&cocos2d::EaseQuadraticActionInOut::reverse)
,"new",static_cast<cocos2d::EaseQuadraticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuadraticActionInOut::create)
);}
static void RegisterLuaEaseQuarticActionIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuarticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuarticActionIn"
,"clone",static_cast<cocos2d::EaseQuarticActionIn*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::clone)
,"update",static_cast<void(cocos2d::EaseQuarticActionIn::*)(float)>(&cocos2d::EaseQuarticActionIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionIn::*)()const>(&cocos2d::EaseQuarticActionIn::reverse)
,"new",static_cast<cocos2d::EaseQuarticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionIn::create)
);}
static void RegisterLuaEaseQuarticActionOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuarticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuarticActionOut"
,"clone",static_cast<cocos2d::EaseQuarticActionOut*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::clone)
,"update",static_cast<void(cocos2d::EaseQuarticActionOut::*)(float)>(&cocos2d::EaseQuarticActionOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionOut::*)()const>(&cocos2d::EaseQuarticActionOut::reverse)
,"new",static_cast<cocos2d::EaseQuarticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionOut::create)
);}
static void RegisterLuaEaseQuarticActionInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuarticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuarticActionInOut"
,"clone",static_cast<cocos2d::EaseQuarticActionInOut*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::clone)
,"update",static_cast<void(cocos2d::EaseQuarticActionInOut::*)(float)>(&cocos2d::EaseQuarticActionInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuarticActionInOut::*)()const>(&cocos2d::EaseQuarticActionInOut::reverse)
,"new",static_cast<cocos2d::EaseQuarticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuarticActionInOut::create)
);}
static void RegisterLuaEaseQuinticActionIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuinticActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuinticActionIn"
,"clone",static_cast<cocos2d::EaseQuinticActionIn*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::clone)
,"update",static_cast<void(cocos2d::EaseQuinticActionIn::*)(float)>(&cocos2d::EaseQuinticActionIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionIn::*)()const>(&cocos2d::EaseQuinticActionIn::reverse)
,"new",static_cast<cocos2d::EaseQuinticActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionIn::create)
);}
static void RegisterLuaEaseQuinticActionOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuinticActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuinticActionOut"
,"clone",static_cast<cocos2d::EaseQuinticActionOut*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::clone)
,"update",static_cast<void(cocos2d::EaseQuinticActionOut::*)(float)>(&cocos2d::EaseQuinticActionOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionOut::*)()const>(&cocos2d::EaseQuinticActionOut::reverse)
,"new",static_cast<cocos2d::EaseQuinticActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionOut::create)
);}
static void RegisterLuaEaseQuinticActionInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseQuinticActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseQuinticActionInOut"
,"clone",static_cast<cocos2d::EaseQuinticActionInOut*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::clone)
,"update",static_cast<void(cocos2d::EaseQuinticActionInOut::*)(float)>(&cocos2d::EaseQuinticActionInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseQuinticActionInOut::*)()const>(&cocos2d::EaseQuinticActionInOut::reverse)
,"new",static_cast<cocos2d::EaseQuinticActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseQuinticActionInOut::create)
);}
static void RegisterLuaEaseCircleActionIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseCircleActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCircleActionIn"
,"clone",static_cast<cocos2d::EaseCircleActionIn*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::clone)
,"update",static_cast<void(cocos2d::EaseCircleActionIn::*)(float)>(&cocos2d::EaseCircleActionIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionIn::*)()const>(&cocos2d::EaseCircleActionIn::reverse)
,"new",static_cast<cocos2d::EaseCircleActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionIn::create)
);}
static void RegisterLuaEaseCircleActionOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseCircleActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCircleActionOut"
,"clone",static_cast<cocos2d::EaseCircleActionOut*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::clone)
,"update",static_cast<void(cocos2d::EaseCircleActionOut::*)(float)>(&cocos2d::EaseCircleActionOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionOut::*)()const>(&cocos2d::EaseCircleActionOut::reverse)
,"new",static_cast<cocos2d::EaseCircleActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionOut::create)
);}
static void RegisterLuaEaseCircleActionInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseCircleActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCircleActionInOut"
,"clone",static_cast<cocos2d::EaseCircleActionInOut*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::clone)
,"update",static_cast<void(cocos2d::EaseCircleActionInOut::*)(float)>(&cocos2d::EaseCircleActionInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCircleActionInOut::*)()const>(&cocos2d::EaseCircleActionInOut::reverse)
,"new",static_cast<cocos2d::EaseCircleActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCircleActionInOut::create)
);}
static void RegisterLuaEaseCubicActionIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseCubicActionIn,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCubicActionIn"
,"clone",static_cast<cocos2d::EaseCubicActionIn*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::clone)
,"update",static_cast<void(cocos2d::EaseCubicActionIn::*)(float)>(&cocos2d::EaseCubicActionIn::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionIn::*)()const>(&cocos2d::EaseCubicActionIn::reverse)
,"new",static_cast<cocos2d::EaseCubicActionIn*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionIn::create)
);}
static void RegisterLuaEaseCubicActionOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseCubicActionOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCubicActionOut"
,"clone",static_cast<cocos2d::EaseCubicActionOut*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::clone)
,"update",static_cast<void(cocos2d::EaseCubicActionOut::*)(float)>(&cocos2d::EaseCubicActionOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionOut::*)()const>(&cocos2d::EaseCubicActionOut::reverse)
,"new",static_cast<cocos2d::EaseCubicActionOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionOut::create)
);}
static void RegisterLuaEaseCubicActionInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseCubicActionInOut,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseCubicActionInOut"
,"clone",static_cast<cocos2d::EaseCubicActionInOut*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::clone)
,"update",static_cast<void(cocos2d::EaseCubicActionInOut::*)(float)>(&cocos2d::EaseCubicActionInOut::update)
,"reverse",static_cast<cocos2d::ActionEase*(cocos2d::EaseCubicActionInOut::*)()const>(&cocos2d::EaseCubicActionInOut::reverse)
,"new",static_cast<cocos2d::EaseCubicActionInOut*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseCubicActionInOut::create)
);}
static void RegisterLuaEaseIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseIn,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseIn"
,"clone",static_cast<cocos2d::EaseIn*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::clone)
,"update",static_cast<void(cocos2d::EaseIn::*)(float)>(&cocos2d::EaseIn::update)
,"reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseIn::*)()const>(&cocos2d::EaseIn::reverse)
,"new",static_cast<cocos2d::EaseIn*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseIn::create)
);}
static void RegisterLuaEaseOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseOut,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseOut"
,"clone",static_cast<cocos2d::EaseOut*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::clone)
,"update",static_cast<void(cocos2d::EaseOut::*)(float)>(&cocos2d::EaseOut::update)
,"reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseOut::*)()const>(&cocos2d::EaseOut::reverse)
,"new",static_cast<cocos2d::EaseOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseOut::create)
);}
static void RegisterLuaEaseInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseInOut,cocos2d::EaseRateAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseInOut"
,"clone",static_cast<cocos2d::EaseInOut*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::clone)
,"update",static_cast<void(cocos2d::EaseInOut::*)(float)>(&cocos2d::EaseInOut::update)
,"reverse",static_cast<cocos2d::EaseRateAction*(cocos2d::EaseInOut::*)()const>(&cocos2d::EaseInOut::reverse)
,"new",static_cast<cocos2d::EaseInOut*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::EaseInOut::create)
);}
static void RegisterLuaEaseElastic(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElastic"
,"getPeriod",static_cast<float(cocos2d::EaseElastic::*)()const>(&cocos2d::EaseElastic::getPeriod)
,"setPeriod",static_cast<void(cocos2d::EaseElastic::*)(float)>(&cocos2d::EaseElastic::setPeriod)
,"initWithAction",sol::overload([](cocos2d::EaseElastic* obj,cocos2d::ActionInterval* arg0){return obj->initWithAction(arg0);},[](cocos2d::EaseElastic* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->initWithAction(arg0,arg1);})
);}
static void RegisterLuaEaseElasticIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseElasticIn,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElasticIn"
,"clone",static_cast<cocos2d::EaseElasticIn*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::clone)
,"update",static_cast<void(cocos2d::EaseElasticIn::*)(float)>(&cocos2d::EaseElasticIn::update)
,"reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticIn::*)()const>(&cocos2d::EaseElasticIn::reverse)
,"new",sol::overload([](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticIn* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);})
);}
static void RegisterLuaEaseElasticOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseElasticOut,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElasticOut"
,"clone",static_cast<cocos2d::EaseElasticOut*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::clone)
,"update",static_cast<void(cocos2d::EaseElasticOut::*)(float)>(&cocos2d::EaseElasticOut::update)
,"reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticOut::*)()const>(&cocos2d::EaseElasticOut::reverse)
,"new",sol::overload([](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);})
);}
static void RegisterLuaEaseElasticInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseElasticInOut,cocos2d::EaseElastic,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseElasticInOut"
,"clone",static_cast<cocos2d::EaseElasticInOut*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::clone)
,"update",static_cast<void(cocos2d::EaseElasticInOut::*)(float)>(&cocos2d::EaseElasticInOut::update)
,"reverse",static_cast<cocos2d::EaseElastic*(cocos2d::EaseElasticInOut::*)()const>(&cocos2d::EaseElasticInOut::reverse)
,"new",sol::overload([](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0){return obj->create(arg0);},[](cocos2d::EaseElasticInOut* obj,cocos2d::ActionInterval* arg0,float arg1){return obj->create(arg0,arg1);})
);}
static void RegisterLuaEaseBezierAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::EaseBezierAction,cocos2d::ActionEase,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","EaseBezierAction"
,"update",static_cast<void(cocos2d::EaseBezierAction::*)(float)>(&cocos2d::EaseBezierAction::update)
,"clone",static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::clone)
,"reverse",static_cast<cocos2d::EaseBezierAction*(cocos2d::EaseBezierAction::*)()const>(&cocos2d::EaseBezierAction::reverse)
,"setBezierParamer",static_cast<void(cocos2d::EaseBezierAction::*)(float,float,float,float)>(&cocos2d::EaseBezierAction::setBezierParamer)
,"new",static_cast<cocos2d::EaseBezierAction*(*)(cocos2d::ActionInterval*)>(&cocos2d::EaseBezierAction::create)
);}
static void RegisterLuaActionInstant(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionInstant"
,"clone",static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::clone)
,"reverse",static_cast<cocos2d::ActionInstant*(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::reverse)
,"startWithTarget",static_cast<void(cocos2d::ActionInstant::*)(cocos2d::Node*)>(&cocos2d::ActionInstant::startWithTarget)
,"isDone",static_cast<bool(cocos2d::ActionInstant::*)()const>(&cocos2d::ActionInstant::isDone)
,"step",static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::step)
,"update",static_cast<void(cocos2d::ActionInstant::*)(float)>(&cocos2d::ActionInstant::update)
);}
static void RegisterLuaShow(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Show,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Show"
,"update",static_cast<void(cocos2d::Show::*)(float)>(&cocos2d::Show::update)
,"reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Show::*)()const>(&cocos2d::Show::reverse)
,"clone",static_cast<cocos2d::Show*(cocos2d::Show::*)()const>(&cocos2d::Show::clone)
,"new",static_cast<cocos2d::Show*(*)()>(&cocos2d::Show::create)
);}
static void RegisterLuaHide(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Hide,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Hide"
,"update",static_cast<void(cocos2d::Hide::*)(float)>(&cocos2d::Hide::update)
,"reverse",static_cast<cocos2d::ActionInstant*(cocos2d::Hide::*)()const>(&cocos2d::Hide::reverse)
,"clone",static_cast<cocos2d::Hide*(cocos2d::Hide::*)()const>(&cocos2d::Hide::clone)
,"new",static_cast<cocos2d::Hide*(*)()>(&cocos2d::Hide::create)
);}
static void RegisterLuaToggleVisibility(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ToggleVisibility,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ToggleVisibility"
,"update",static_cast<void(cocos2d::ToggleVisibility::*)(float)>(&cocos2d::ToggleVisibility::update)
,"reverse",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::reverse)
,"clone",static_cast<cocos2d::ToggleVisibility*(cocos2d::ToggleVisibility::*)()const>(&cocos2d::ToggleVisibility::clone)
,"new",static_cast<cocos2d::ToggleVisibility*(*)()>(&cocos2d::ToggleVisibility::create)
);}
static void RegisterLuaRemoveSelf(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::RemoveSelf,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RemoveSelf"
,"update",static_cast<void(cocos2d::RemoveSelf::*)(float)>(&cocos2d::RemoveSelf::update)
,"clone",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::clone)
,"reverse",static_cast<cocos2d::RemoveSelf*(cocos2d::RemoveSelf::*)()const>(&cocos2d::RemoveSelf::reverse)
,"init",static_cast<bool(cocos2d::RemoveSelf::*)(bool)>(&cocos2d::RemoveSelf::init)
,"new",sol::overload([](cocos2d::RemoveSelf* obj){return obj->create();},[](cocos2d::RemoveSelf* obj,bool arg0){return obj->create(arg0);})
);}
static void RegisterLuaFlipX(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FlipX,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipX"
,"update",static_cast<void(cocos2d::FlipX::*)(float)>(&cocos2d::FlipX::update)
,"reverse",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::reverse)
,"clone",static_cast<cocos2d::FlipX*(cocos2d::FlipX::*)()const>(&cocos2d::FlipX::clone)
,"initWithFlipX",static_cast<bool(cocos2d::FlipX::*)(bool)>(&cocos2d::FlipX::initWithFlipX)
,"new",static_cast<cocos2d::FlipX*(*)(bool)>(&cocos2d::FlipX::create)
);}
static void RegisterLuaFlipY(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FlipY,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipY"
,"update",static_cast<void(cocos2d::FlipY::*)(float)>(&cocos2d::FlipY::update)
,"reverse",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::reverse)
,"clone",static_cast<cocos2d::FlipY*(cocos2d::FlipY::*)()const>(&cocos2d::FlipY::clone)
,"initWithFlipY",static_cast<bool(cocos2d::FlipY::*)(bool)>(&cocos2d::FlipY::initWithFlipY)
,"new",static_cast<cocos2d::FlipY*(*)(bool)>(&cocos2d::FlipY::create)
);}
static void RegisterLuaPlace(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Place,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Place"
,"update",static_cast<void(cocos2d::Place::*)(float)>(&cocos2d::Place::update)
,"reverse",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::reverse)
,"clone",static_cast<cocos2d::Place*(cocos2d::Place::*)()const>(&cocos2d::Place::clone)
,"initWithPosition",static_cast<bool(cocos2d::Place::*)(const cocos2d::Vec2&)>(&cocos2d::Place::initWithPosition)
,"new",static_cast<cocos2d::Place*(*)(const cocos2d::Vec2&)>(&cocos2d::Place::create)
);}
static void RegisterLuaCallFunc(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CallFunc,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","CallFunc"
,"execute",static_cast<void(cocos2d::CallFunc::*)()>(&cocos2d::CallFunc::execute)
,"update",static_cast<void(cocos2d::CallFunc::*)(float)>(&cocos2d::CallFunc::update)
,"reverse",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::reverse)
,"clone",static_cast<cocos2d::CallFunc*(cocos2d::CallFunc::*)()const>(&cocos2d::CallFunc::clone)
);}
static void RegisterLuaGridAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","GridAction"
,"getGrid",static_cast<cocos2d::GridBase*(cocos2d::GridAction::*)()>(&cocos2d::GridAction::getGrid)
,"clone",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::clone)
,"reverse",static_cast<cocos2d::GridAction*(cocos2d::GridAction::*)()const>(&cocos2d::GridAction::reverse)
,"startWithTarget",static_cast<void(cocos2d::GridAction::*)(cocos2d::Node*)>(&cocos2d::GridAction::startWithTarget)
,"initWithDuration",static_cast<bool(cocos2d::GridAction::*)(float,const cocos2d::Size&)>(&cocos2d::GridAction::initWithDuration)
);}
static void RegisterLuaGrid3DAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Grid3DAction"
,"getGrid",static_cast<cocos2d::GridBase*(cocos2d::Grid3DAction::*)()>(&cocos2d::Grid3DAction::getGrid)
,"clone",static_cast<cocos2d::Grid3DAction*(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::clone)
,"getGridRect",static_cast<cocos2d::Rect(cocos2d::Grid3DAction::*)()const>(&cocos2d::Grid3DAction::getGridRect)
);}
static void RegisterLuaTiledGrid3DAction(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TiledGrid3DAction"
,"getGrid",static_cast<cocos2d::GridBase*(cocos2d::TiledGrid3DAction::*)()>(&cocos2d::TiledGrid3DAction::getGrid)
,"clone",static_cast<cocos2d::TiledGrid3DAction*(cocos2d::TiledGrid3DAction::*)()const>(&cocos2d::TiledGrid3DAction::clone)
);}
static void RegisterLuaStopGrid(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::StopGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","StopGrid"
,"startWithTarget",static_cast<void(cocos2d::StopGrid::*)(cocos2d::Node*)>(&cocos2d::StopGrid::startWithTarget)
,"clone",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::clone)
,"reverse",static_cast<cocos2d::StopGrid*(cocos2d::StopGrid::*)()const>(&cocos2d::StopGrid::reverse)
,"new",static_cast<cocos2d::StopGrid*(*)()>(&cocos2d::StopGrid::create)
);}
static void RegisterLuaReuseGrid(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ReuseGrid,cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ReuseGrid"
,"startWithTarget",static_cast<void(cocos2d::ReuseGrid::*)(cocos2d::Node*)>(&cocos2d::ReuseGrid::startWithTarget)
,"clone",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::clone)
,"reverse",static_cast<cocos2d::ReuseGrid*(cocos2d::ReuseGrid::*)()const>(&cocos2d::ReuseGrid::reverse)
,"initWithTimes",static_cast<bool(cocos2d::ReuseGrid::*)(int)>(&cocos2d::ReuseGrid::initWithTimes)
,"new",static_cast<cocos2d::ReuseGrid*(*)(int)>(&cocos2d::ReuseGrid::create)
);}
static void RegisterLuaWaves3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Waves3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Waves3D"
,"getAmplitude",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitudeRate)
,"clone",static_cast<cocos2d::Waves3D*(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::clone)
,"update",static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::update)
,"initWithDuration",static_cast<bool(cocos2d::Waves3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::initWithDuration)
,"new",static_cast<cocos2d::Waves3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::create)
);}
static void RegisterLuaFlipX3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipX3D"
,"clone",static_cast<cocos2d::FlipX3D*(cocos2d::FlipX3D::*)()const>(&cocos2d::FlipX3D::clone)
,"update",static_cast<void(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::update)
,"initWithDuration",static_cast<bool(cocos2d::FlipX3D::*)(float)>(&cocos2d::FlipX3D::initWithDuration)
,"initWithSize",static_cast<bool(cocos2d::FlipX3D::*)(const cocos2d::Size&,float)>(&cocos2d::FlipX3D::initWithSize)
,"new",static_cast<cocos2d::FlipX3D*(*)(float)>(&cocos2d::FlipX3D::create)
);}
static void RegisterLuaFlipY3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FlipY3D,cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FlipY3D"
,"update",static_cast<void(cocos2d::FlipY3D::*)(float)>(&cocos2d::FlipY3D::update)
,"clone",static_cast<cocos2d::FlipY3D*(cocos2d::FlipY3D::*)()const>(&cocos2d::FlipY3D::clone)
,"new",static_cast<cocos2d::FlipY3D*(*)(float)>(&cocos2d::FlipY3D::create)
);}
static void RegisterLuaLens3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Lens3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Lens3D"
,"getLensEffect",static_cast<float(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getLensEffect)
,"setLensEffect",static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::setLensEffect)
,"setConcave",static_cast<void(cocos2d::Lens3D::*)(bool)>(&cocos2d::Lens3D::setConcave)
,"getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getPosition)
,"setPosition",static_cast<void(cocos2d::Lens3D::*)(const cocos2d::Vec2&)>(&cocos2d::Lens3D::setPosition)
,"clone",static_cast<cocos2d::Lens3D*(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::clone)
,"update",static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::update)
,"initWithDuration",static_cast<bool(cocos2d::Lens3D::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::initWithDuration)
,"new",static_cast<cocos2d::Lens3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::create)
);}
static void RegisterLuaRipple3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Ripple3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Ripple3D"
,"getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getPosition)
,"setPosition",static_cast<void(cocos2d::Ripple3D::*)(const cocos2d::Vec2&)>(&cocos2d::Ripple3D::setPosition)
,"getAmplitude",static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitudeRate)
,"clone",static_cast<cocos2d::Ripple3D*(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::clone)
,"update",static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::update)
,"initWithDuration",static_cast<bool(cocos2d::Ripple3D::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::initWithDuration)
,"new",static_cast<cocos2d::Ripple3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::create)
);}
static void RegisterLuaShaky3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Shaky3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Shaky3D"
,"clone",static_cast<cocos2d::Shaky3D*(cocos2d::Shaky3D::*)()const>(&cocos2d::Shaky3D::clone)
,"update",static_cast<void(cocos2d::Shaky3D::*)(float)>(&cocos2d::Shaky3D::update)
,"initWithDuration",static_cast<bool(cocos2d::Shaky3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::initWithDuration)
,"new",static_cast<cocos2d::Shaky3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::create)
);}
static void RegisterLuaLiquid(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Liquid,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Liquid"
,"getAmplitude",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitudeRate)
,"clone",static_cast<cocos2d::Liquid*(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::clone)
,"update",static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::update)
,"initWithDuration",static_cast<bool(cocos2d::Liquid::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::initWithDuration)
,"new",static_cast<cocos2d::Liquid*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::create)
);}
static void RegisterLuaWaves(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Waves,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Waves"
,"getAmplitude",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitudeRate)
,"clone",static_cast<cocos2d::Waves*(cocos2d::Waves::*)()const>(&cocos2d::Waves::clone)
,"update",static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::update)
,"initWithDuration",static_cast<bool(cocos2d::Waves::*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::initWithDuration)
,"new",static_cast<cocos2d::Waves*(*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::create)
);}
static void RegisterLuaTwirl(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Twirl,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Twirl"
,"getPosition",static_cast<const cocos2d::Vec2&(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getPosition)
,"setPosition",static_cast<void(cocos2d::Twirl::*)(const cocos2d::Vec2&)>(&cocos2d::Twirl::setPosition)
,"getAmplitude",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitudeRate)
,"clone",static_cast<cocos2d::Twirl*(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::clone)
,"update",static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::update)
,"initWithDuration",static_cast<bool(cocos2d::Twirl::*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::initWithDuration)
,"new",static_cast<cocos2d::Twirl*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::create)
);}
static void RegisterLuaActionManager(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionManager,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionManager"
,"addAction",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*,cocos2d::Node*,bool)>(&cocos2d::ActionManager::addAction)
,"removeAllActions",static_cast<void(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::removeAllActions)
,"removeAllActionsFromTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsFromTarget)
,"removeAction",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Action*)>(&cocos2d::ActionManager::removeAction)
,"removeActionByTag",static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionByTag)
,"removeAllActionsByTag",static_cast<void(cocos2d::ActionManager::*)(int,cocos2d::Node*)>(&cocos2d::ActionManager::removeAllActionsByTag)
,"removeActionsByFlags",static_cast<void(cocos2d::ActionManager::*)(unsigned int,cocos2d::Node*)>(&cocos2d::ActionManager::removeActionsByFlags)
,"getActionByTag",static_cast<cocos2d::Action*(cocos2d::ActionManager::*)(int,const cocos2d::Node*)const>(&cocos2d::ActionManager::getActionByTag)
,"getNumberOfRunningActionsInTarget",static_cast<ssize_t(cocos2d::ActionManager::*)(const cocos2d::Node*)const>(&cocos2d::ActionManager::getNumberOfRunningActionsInTarget)
,"getNumberOfRunningActions",static_cast<ssize_t(cocos2d::ActionManager::*)()const>(&cocos2d::ActionManager::getNumberOfRunningActions)
,"getNumberOfRunningActionsInTargetByTag",static_cast<size_t(cocos2d::ActionManager::*)(const cocos2d::Node*,int)>(&cocos2d::ActionManager::getNumberOfRunningActionsInTargetByTag)
,"pauseTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::pauseTarget)
,"resumeTarget",static_cast<void(cocos2d::ActionManager::*)(cocos2d::Node*)>(&cocos2d::ActionManager::resumeTarget)
,"pauseAllRunningActions",static_cast<cocos2d::Vector<cocos2d::Node *>(cocos2d::ActionManager::*)()>(&cocos2d::ActionManager::pauseAllRunningActions)
,"resumeTargets",static_cast<void(cocos2d::ActionManager::*)(const cocos2d::Vector<cocos2d::Node *>&)>(&cocos2d::ActionManager::resumeTargets)
,"update",static_cast<void(cocos2d::ActionManager::*)(float)>(&cocos2d::ActionManager::update)
);}
static void RegisterLuaPageTurn3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PageTurn3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","PageTurn3D"
,"getGrid",static_cast<cocos2d::GridBase*(cocos2d::PageTurn3D::*)()>(&cocos2d::PageTurn3D::getGrid)
,"clone",static_cast<cocos2d::PageTurn3D*(cocos2d::PageTurn3D::*)()const>(&cocos2d::PageTurn3D::clone)
,"update",static_cast<void(cocos2d::PageTurn3D::*)(float)>(&cocos2d::PageTurn3D::update)
,"new",static_cast<cocos2d::PageTurn3D*(*)(float,const cocos2d::Size&)>(&cocos2d::PageTurn3D::create)
);}
static void RegisterLuaProgressTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ProgressTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ProgressTo"
,"clone",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::clone)
,"reverse",static_cast<cocos2d::ProgressTo*(cocos2d::ProgressTo::*)()const>(&cocos2d::ProgressTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::ProgressTo::*)(cocos2d::Node*)>(&cocos2d::ProgressTo::startWithTarget)
,"update",static_cast<void(cocos2d::ProgressTo::*)(float)>(&cocos2d::ProgressTo::update)
,"initWithDuration",static_cast<bool(cocos2d::ProgressTo::*)(float,float)>(&cocos2d::ProgressTo::initWithDuration)
,"new",static_cast<cocos2d::ProgressTo*(*)(float,float)>(&cocos2d::ProgressTo::create)
);}
static void RegisterLuaProgressFromTo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ProgressFromTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ProgressFromTo"
,"clone",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::clone)
,"reverse",static_cast<cocos2d::ProgressFromTo*(cocos2d::ProgressFromTo::*)()const>(&cocos2d::ProgressFromTo::reverse)
,"startWithTarget",static_cast<void(cocos2d::ProgressFromTo::*)(cocos2d::Node*)>(&cocos2d::ProgressFromTo::startWithTarget)
,"update",static_cast<void(cocos2d::ProgressFromTo::*)(float)>(&cocos2d::ProgressFromTo::update)
,"initWithDuration",static_cast<bool(cocos2d::ProgressFromTo::*)(float,float,float)>(&cocos2d::ProgressFromTo::initWithDuration)
,"new",static_cast<cocos2d::ProgressFromTo*(*)(float,float,float)>(&cocos2d::ProgressFromTo::create)
);}
static void RegisterLuaShakyTiles3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ShakyTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ShakyTiles3D"
,"clone",static_cast<cocos2d::ShakyTiles3D*(cocos2d::ShakyTiles3D::*)()const>(&cocos2d::ShakyTiles3D::clone)
,"update",static_cast<void(cocos2d::ShakyTiles3D::*)(float)>(&cocos2d::ShakyTiles3D::update)
,"initWithDuration",static_cast<bool(cocos2d::ShakyTiles3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShakyTiles3D::initWithDuration)
,"new",static_cast<cocos2d::ShakyTiles3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShakyTiles3D::create)
);}
static void RegisterLuaShatteredTiles3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ShatteredTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ShatteredTiles3D"
,"clone",static_cast<cocos2d::ShatteredTiles3D*(cocos2d::ShatteredTiles3D::*)()const>(&cocos2d::ShatteredTiles3D::clone)
,"update",static_cast<void(cocos2d::ShatteredTiles3D::*)(float)>(&cocos2d::ShatteredTiles3D::update)
,"initWithDuration",static_cast<bool(cocos2d::ShatteredTiles3D::*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShatteredTiles3D::initWithDuration)
,"new",static_cast<cocos2d::ShatteredTiles3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::ShatteredTiles3D::create)
);}
static void RegisterLuaShuffleTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ShuffleTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ShuffleTiles"
,"getDelta",static_cast<cocos2d::Size(cocos2d::ShuffleTiles::*)(const cocos2d::Size&)const>(&cocos2d::ShuffleTiles::getDelta)
,"startWithTarget",static_cast<void(cocos2d::ShuffleTiles::*)(cocos2d::Node*)>(&cocos2d::ShuffleTiles::startWithTarget)
,"update",static_cast<void(cocos2d::ShuffleTiles::*)(float)>(&cocos2d::ShuffleTiles::update)
,"clone",static_cast<cocos2d::ShuffleTiles*(cocos2d::ShuffleTiles::*)()const>(&cocos2d::ShuffleTiles::clone)
,"initWithDuration",static_cast<bool(cocos2d::ShuffleTiles::*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::initWithDuration)
,"new",static_cast<cocos2d::ShuffleTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::ShuffleTiles::create)
);}
static void RegisterLuaFadeOutTRTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutTRTiles"
,"testFunc",static_cast<float(cocos2d::FadeOutTRTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutTRTiles::testFunc)
,"turnOnTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOnTile)
,"turnOffTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&)>(&cocos2d::FadeOutTRTiles::turnOffTile)
,"transformTile",static_cast<void(cocos2d::FadeOutTRTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutTRTiles::transformTile)
,"update",static_cast<void(cocos2d::FadeOutTRTiles::*)(float)>(&cocos2d::FadeOutTRTiles::update)
,"clone",static_cast<cocos2d::FadeOutTRTiles*(cocos2d::FadeOutTRTiles::*)()const>(&cocos2d::FadeOutTRTiles::clone)
,"new",static_cast<cocos2d::FadeOutTRTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutTRTiles::create)
);}
static void RegisterLuaFadeOutBLTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeOutBLTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutBLTiles"
,"testFunc",static_cast<float(cocos2d::FadeOutBLTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutBLTiles::testFunc)
,"clone",static_cast<cocos2d::FadeOutBLTiles*(cocos2d::FadeOutBLTiles::*)()const>(&cocos2d::FadeOutBLTiles::clone)
,"new",static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create)
);}
static void RegisterLuaFadeOutUpTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutUpTiles"
,"transformTile",static_cast<void(cocos2d::FadeOutUpTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutUpTiles::transformTile)
,"clone",static_cast<cocos2d::FadeOutUpTiles*(cocos2d::FadeOutUpTiles::*)()const>(&cocos2d::FadeOutUpTiles::clone)
,"testFunc",static_cast<float(cocos2d::FadeOutUpTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutUpTiles::testFunc)
,"new",static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create)
);}
static void RegisterLuaFadeOutDownTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FadeOutDownTiles,cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FadeOutDownTiles"
,"clone",static_cast<cocos2d::FadeOutDownTiles*(cocos2d::FadeOutDownTiles::*)()const>(&cocos2d::FadeOutDownTiles::clone)
,"testFunc",static_cast<float(cocos2d::FadeOutDownTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutDownTiles::testFunc)
,"new",static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create)
);}
static void RegisterLuaTurnOffTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TurnOffTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","TurnOffTiles"
,"turnOnTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile)
,"turnOffTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile)
,"clone",static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone)
,"startWithTarget",static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget)
,"update",static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update)
,"initWithDuration",static_cast<bool(cocos2d::TurnOffTiles::*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::initWithDuration)
,"new",sol::overload(static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create))
);}
static void RegisterLuaWavesTiles3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::WavesTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","WavesTiles3D"
,"getAmplitude",static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::setAmplitudeRate)
,"clone",static_cast<cocos2d::WavesTiles3D*(cocos2d::WavesTiles3D::*)()const>(&cocos2d::WavesTiles3D::clone)
,"update",static_cast<void(cocos2d::WavesTiles3D::*)(float)>(&cocos2d::WavesTiles3D::update)
,"initWithDuration",static_cast<bool(cocos2d::WavesTiles3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::initWithDuration)
,"new",static_cast<cocos2d::WavesTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::WavesTiles3D::create)
);}
static void RegisterLuaJumpTiles3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::JumpTiles3D,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","JumpTiles3D"
,"getAmplitude",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude)
,"setAmplitude",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude)
,"getAmplitudeRate",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate)
,"setAmplitudeRate",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate)
,"clone",static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone)
,"update",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update)
,"initWithDuration",static_cast<bool(cocos2d::JumpTiles3D::*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::initWithDuration)
,"new",static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create)
);}
static void RegisterLuaSplitRows(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SplitRows,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SplitRows"
,"clone",static_cast<cocos2d::SplitRows*(cocos2d::SplitRows::*)()const>(&cocos2d::SplitRows::clone)
,"update",static_cast<void(cocos2d::SplitRows::*)(float)>(&cocos2d::SplitRows::update)
,"startWithTarget",static_cast<void(cocos2d::SplitRows::*)(cocos2d::Node*)>(&cocos2d::SplitRows::startWithTarget)
,"initWithDuration",static_cast<bool(cocos2d::SplitRows::*)(float,unsigned int)>(&cocos2d::SplitRows::initWithDuration)
,"new",static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create)
);}
static void RegisterLuaSplitCols(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SplitCols,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","SplitCols"
,"clone",static_cast<cocos2d::SplitCols*(cocos2d::SplitCols::*)()const>(&cocos2d::SplitCols::clone)
,"update",static_cast<void(cocos2d::SplitCols::*)(float)>(&cocos2d::SplitCols::update)
,"startWithTarget",static_cast<void(cocos2d::SplitCols::*)(cocos2d::Node*)>(&cocos2d::SplitCols::startWithTarget)
,"initWithDuration",static_cast<bool(cocos2d::SplitCols::*)(float,unsigned int)>(&cocos2d::SplitCols::initWithDuration)
,"new",static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create)
);}
static void RegisterLuaActionTween(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ActionTween,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionTween"
,"startWithTarget",static_cast<void(cocos2d::ActionTween::*)(cocos2d::Node*)>(&cocos2d::ActionTween::startWithTarget)
,"update",static_cast<void(cocos2d::ActionTween::*)(float)>(&cocos2d::ActionTween::update)
,"reverse",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::reverse)
,"clone",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::clone)
,"initWithDuration",static_cast<bool(cocos2d::ActionTween::*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::initWithDuration)
,"new",static_cast<cocos2d::ActionTween*(*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::create)
);}
static void RegisterLuaAtlasNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","AtlasNode"
,"updateAtlasValues",static_cast<void(cocos2d::AtlasNode::*)()>(&cocos2d::AtlasNode::updateAtlasValues)
,"draw",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AtlasNode::draw)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTexture)
,"setTexture",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Texture2D*)>(&cocos2d::AtlasNode::setTexture)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::isOpacityModifyRGB)
,"setOpacityModifyRGB",static_cast<void(cocos2d::AtlasNode::*)(bool)>(&cocos2d::AtlasNode::setOpacityModifyRGB)
,"getColor",static_cast<const cocos2d::Color3B&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getColor)
,"setColor",static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::Color3B&)>(&cocos2d::AtlasNode::setColor)
,"setOpacity",static_cast<void(cocos2d::AtlasNode::*)(uint8_t)>(&cocos2d::AtlasNode::setOpacity)
,"setBlendFunc",static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::AtlasNode::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getBlendFunc)
,"setTextureAtlas",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::AtlasNode::setTextureAtlas)
,"getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTextureAtlas)
,"setQuadsToDraw",static_cast<void(cocos2d::AtlasNode::*)(ssize_t)>(&cocos2d::AtlasNode::setQuadsToDraw)
,"getQuadsToDraw",static_cast<size_t(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getQuadsToDraw)
,"setProgramState",sol::overload([](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);})
,"initWithTileFile",static_cast<bool(cocos2d::AtlasNode::*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::initWithTileFile)
,"initWithTexture",static_cast<bool(cocos2d::AtlasNode::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::AtlasNode::initWithTexture)
,"new",static_cast<cocos2d::AtlasNode*(*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::create)
);}
static void RegisterLuaClippingNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ClippingNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ClippingNode"
,"getStencil",static_cast<cocos2d::Node*(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getStencil)
,"setStencil",static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::setStencil)
,"hasContent",static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::hasContent)
,"getAlphaThreshold",static_cast<float(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getAlphaThreshold)
,"setAlphaThreshold",static_cast<void(cocos2d::ClippingNode::*)(float)>(&cocos2d::ClippingNode::setAlphaThreshold)
,"isInverted",static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::isInverted)
,"setInverted",static_cast<void(cocos2d::ClippingNode::*)(bool)>(&cocos2d::ClippingNode::setInverted)
,"visit",static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingNode::visit)
,"setCameraMask",sol::overload([](cocos2d::ClippingNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ClippingNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);})
,"init",sol::overload(static_cast<bool(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::init),static_cast<bool(cocos2d::ClippingNode::*)()>(&cocos2d::ClippingNode::init))
,"new",sol::overload(static_cast<cocos2d::ClippingNode*(*)(cocos2d::Node*)>(&cocos2d::ClippingNode::create),static_cast<cocos2d::ClippingNode*(*)()>(&cocos2d::ClippingNode::create))
);}
static void RegisterLuaClippingRectangleNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ClippingRectangleNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ClippingRectangleNode"
,"getClippingRegion",static_cast<const cocos2d::Rect&(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::getClippingRegion)
,"setClippingRegion",static_cast<void(cocos2d::ClippingRectangleNode::*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::setClippingRegion)
,"isClippingEnabled",static_cast<bool(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::isClippingEnabled)
,"setClippingEnabled",static_cast<void(cocos2d::ClippingRectangleNode::*)(bool)>(&cocos2d::ClippingRectangleNode::setClippingEnabled)
,"visit",static_cast<void(cocos2d::ClippingRectangleNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ClippingRectangleNode::visit)
,"new",sol::overload(static_cast<cocos2d::ClippingRectangleNode*(*)()>(&cocos2d::ClippingRectangleNode::create),static_cast<cocos2d::ClippingRectangleNode*(*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::create))
);}
static void RegisterLuaDrawNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::DrawNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","DrawNode"
,"drawPoint",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoint)
,"drawLine",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawLine)
,"drawRect",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect))
,"drawCircle",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle))
,"drawQuadBezier",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawQuadBezier)
,"drawCubicBezier",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCubicBezier)
,"drawDot",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawDot)
,"drawSolidRect",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidRect)
,"drawSolidCircle",sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle))
,"drawSegment",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSegment)
,"drawTriangle",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawTriangle)
,"clear",static_cast<void(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::clear)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::getBlendFunc)
,"setBlendFunc",static_cast<void(cocos2d::DrawNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::DrawNode::setBlendFunc)
,"draw",static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::draw)
,"visit",static_cast<void(cocos2d::DrawNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::DrawNode::visit)
,"setLineWidth",static_cast<void(cocos2d::DrawNode::*)(float)>(&cocos2d::DrawNode::setLineWidth)
,"getLineWidth",static_cast<float(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::getLineWidth)
,"setIsolated",static_cast<void(cocos2d::DrawNode::*)(bool)>(&cocos2d::DrawNode::setIsolated)
,"isIsolated",static_cast<bool(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::isIsolated)
,"init",static_cast<bool(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::init)
,"new",sol::overload([](cocos2d::DrawNode* obj){return obj->create();},[](cocos2d::DrawNode* obj,float arg0){return obj->create(arg0);})
);}
static void RegisterLuaLabel(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Label,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::LabelProtocol,cocos2d::BlendProtocol>("cc","Label"
,"setTTFConfig",static_cast<bool(cocos2d::Label::*)(const cocos2d::TTFConfig&)>(&cocos2d::Label::setTTFConfig)
,"getTTFConfig",static_cast<const cocos2d::TTFConfig&(cocos2d::Label::*)()const>(&cocos2d::Label::getTTFConfig)
,"setBMFontFilePath",sol::overload([](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2,float arg3){return obj->setBMFontFilePath(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0){return obj->setBMFontFilePath(arg0);},[](cocos2d::Label* obj,const std::string& arg0,float arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);})
,"getBMFontFilePath",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontFilePath)
,"setCharMap",sol::overload(static_cast<bool(cocos2d::Label::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setCharMap))
,"setSystemFontName",static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setSystemFontName)
,"getSystemFontName",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontName)
,"setSystemFontSize",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setSystemFontSize)
,"getSystemFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontSize)
,"requestSystemFontRefresh",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::requestSystemFontRefresh)
,"setString",static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setString)
,"getString",static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getString)
,"getStringNumLines",static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringNumLines)
,"getStringLength",static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringLength)
,"setTextColor",static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::setTextColor)
,"getTextColor",static_cast<const cocos2d::Color4B&(cocos2d::Label::*)()const>(&cocos2d::Label::getTextColor)
,"enableShadow",sol::overload([](cocos2d::Label* obj){return obj->enableShadow();},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableShadow(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){return obj->enableShadow(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1,int arg2){return obj->enableShadow(arg0,arg1,arg2);})
,"enableOutline",sol::overload([](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableOutline(arg0);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,int arg1){return obj->enableOutline(arg0,arg1);})
,"enableGlow",static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::enableGlow)
,"enableItalics",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableItalics)
,"enableBold",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableBold)
,"enableUnderline",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableUnderline)
,"enableStrikethrough",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableStrikethrough)
,"disableEffect",sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::LabelEffect)>(&cocos2d::Label::disableEffect),static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::disableEffect))
,"isShadowEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isShadowEnabled)
,"getShadowOffset",static_cast<cocos2d::Size(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowOffset)
,"getShadowBlurRadius",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowBlurRadius)
,"getShadowColor",static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowColor)
,"getOutlineSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getOutlineSize)
,"getLabelEffectType",static_cast<cocos2d::LabelEffect(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelEffectType)
,"getEffectColor",static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getEffectColor)
,"setAlignment",sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::Label::setAlignment),static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setAlignment))
,"getTextAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getTextAlignment)
,"setHorizontalAlignment",static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setHorizontalAlignment)
,"getHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getHorizontalAlignment)
,"setVerticalAlignment",static_cast<void(cocos2d::Label::*)(cocos2d::TextVAlignment)>(&cocos2d::Label::setVerticalAlignment)
,"getVerticalAlignment",static_cast<cocos2d::TextVAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getVerticalAlignment)
,"setLineBreakWithoutSpace",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setLineBreakWithoutSpace)
,"setMaxLineWidth",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setMaxLineWidth)
,"getMaxLineWidth",static_cast<float(cocos2d::Label::*)()>(&cocos2d::Label::getMaxLineWidth)
,"setBMFontSize",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setBMFontSize)
,"getBMFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontSize)
,"enableWrap",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::enableWrap)
,"isWrapEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isWrapEnabled)
,"setOverflow",static_cast<void(cocos2d::Label::*)(cocos2d::Label::Overflow)>(&cocos2d::Label::setOverflow)
,"getOverflow",static_cast<cocos2d::Label::Overflow(cocos2d::Label::*)()const>(&cocos2d::Label::getOverflow)
,"setWidth",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setWidth)
,"getWidth",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getWidth)
,"setHeight",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setHeight)
,"getHeight",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getHeight)
,"setDimensions",static_cast<void(cocos2d::Label::*)(float,float)>(&cocos2d::Label::setDimensions)
,"getDimensions",static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getDimensions)
,"updateContent",static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::updateContent)
,"getLetter",static_cast<cocos2d::Sprite*(cocos2d::Label::*)(int)>(&cocos2d::Label::getLetter)
,"setClipMarginEnabled",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setClipMarginEnabled)
,"isClipMarginEnabled",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isClipMarginEnabled)
,"setLineHeight",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineHeight)
,"getLineHeight",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineHeight)
,"setLineSpacing",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineSpacing)
,"getLineSpacing",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineSpacing)
,"getLabelType",static_cast<cocos2d::Label::LabelType(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelType)
,"getRenderingFontSize",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getRenderingFontSize)
,"setAdditionalKerning",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setAdditionalKerning)
,"getAdditionalKerning",static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getAdditionalKerning)
,"setProgramState",sol::overload([](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Label* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);})
,"getFontAtlas",static_cast<cocos2d::FontAtlas*(cocos2d::Label::*)()>(&cocos2d::Label::getFontAtlas)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Label::*)()const>(&cocos2d::Label::getBlendFunc)
,"setBlendFunc",static_cast<void(cocos2d::Label::*)(const cocos2d::BlendFunc&)>(&cocos2d::Label::setBlendFunc)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isOpacityModifyRGB)
,"setOpacityModifyRGB",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setOpacityModifyRGB)
,"updateDisplayedColor",static_cast<void(cocos2d::Label::*)(const cocos2d::Color3B&)>(&cocos2d::Label::updateDisplayedColor)
,"updateDisplayedOpacity",static_cast<void(cocos2d::Label::*)(uint8_t)>(&cocos2d::Label::updateDisplayedOpacity)
,"getDescription",static_cast<std::string(cocos2d::Label::*)()const>(&cocos2d::Label::getDescription)
,"getContentSize",static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getContentSize)
,"getBoundingBox",static_cast<cocos2d::Rect(cocos2d::Label::*)()const>(&cocos2d::Label::getBoundingBox)
,"visit",static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::visit)
,"draw",static_cast<void(cocos2d::Label::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Label::draw)
,"setCameraMask",sol::overload([](cocos2d::Label* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::Label* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);})
,"removeAllChildrenWithCleanup",static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::removeAllChildrenWithCleanup)
,"removeChild",sol::overload([](cocos2d::Label* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::Label* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);})
,"setGlobalZOrder",static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setGlobalZOrder)
,"initWithTTF",sol::overload([](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1){return obj->initWithTTF(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2){return obj->initWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2,int arg3){return obj->initWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->initWithTTF(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->initWithTTF(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->initWithTTF(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->initWithTTF(arg0,arg1,arg2,arg3,arg4,arg5);})
,"new",static_cast<cocos2d::Label*(*)()>(&cocos2d::Label::create)
,"createWithSystemFont",sol::overload([](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->createWithSystemFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return obj->createWithSystemFont(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return obj->createWithSystemFont(arg0,arg1,arg2,arg3,arg4,arg5);})
,"createWithBMFont",sol::overload(static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const cocos2d::Rect&,bool)>(&cocos2d::Label::createWithBMFont),[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->createWithBMFont(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2){return obj->createWithBMFont(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2,int arg3){return obj->createWithBMFont(arg0,arg1,arg2,arg3);},static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const std::string&)>(&cocos2d::Label::createWithBMFont))
,"createWithCharMap",sol::overload(static_cast<cocos2d::Label*(*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&)>(&cocos2d::Label::createWithCharMap))
);}
static void RegisterLuaLabelAtlas(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::LabelAtlas,cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::LabelProtocol>("cc","LabelAtlas"
,"initWithString",sol::overload(static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::initWithString))
,"setString",static_cast<void(cocos2d::LabelAtlas::*)(const std::string&)>(&cocos2d::LabelAtlas::setString)
,"getString",static_cast<const std::string&(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getString)
,"updateAtlasValues",static_cast<void(cocos2d::LabelAtlas::*)()>(&cocos2d::LabelAtlas::updateAtlasValues)
,"getDescription",static_cast<std::string(cocos2d::LabelAtlas::*)()const>(&cocos2d::LabelAtlas::getDescription)
,"new",sol::overload(static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::create))
);}
static void RegisterLuaTouch(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Touch,cocos2d::Ref,cocos2d::LuaObject>("cc","Touch"
,"getLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocation)
,"getPreviousLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocation)
,"getStartLocation",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocation)
,"getDelta",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getDelta)
,"getLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocationInView)
,"getPreviousLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocationInView)
,"getStartLocationInView",static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocationInView)
,"setTouchInfo",sol::overload(static_cast<void(cocos2d::Touch::*)(int,float,float,float,float)>(&cocos2d::Touch::setTouchInfo),static_cast<void(cocos2d::Touch::*)(int,float,float)>(&cocos2d::Touch::setTouchInfo))
,"getId",static_cast<int(cocos2d::Touch::*)()const>(&cocos2d::Touch::getID)
,"getCurrentForce",static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getCurrentForce)
,"getMaxForce",static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getMaxForce)
);}
static void RegisterLuaLayer(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Layer"
,"getDescription",static_cast<std::string(cocos2d::Layer::*)()const>(&cocos2d::Layer::getDescription)
,"init",static_cast<bool(cocos2d::Layer::*)()>(&cocos2d::Layer::init)
,"SetTouchHandler",static_cast<void(cocos2d::Layer::*)(const std::function<bool (cocos2d::Layer *, cocos2d::EventTouch::EventCode, cocos2d::Touch *)>&)>(&cocos2d::Layer::SetTouchHandler)
,"SetTouchesHandler",static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::EventTouch::EventCode, const std::vector<cocos2d::Touch *>&)>&)>(&cocos2d::Layer::SetTouchesHandler)
,"SetKeyHandler",static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::EventKeyboard::KeyCode, bool)>&)>(&cocos2d::Layer::SetKeyHandler)
,"SetAccelerationHandler",static_cast<void(cocos2d::Layer::*)(const std::function<void (cocos2d::Layer *, cocos2d::Acceleration *)>&)>(&cocos2d::Layer::SetAccelerationHandler)
,"new",static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create)
);}
static void RegisterLuaLayerColor(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","LayerColor"
,"changeWidth",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeWidth)
,"changeHeight",static_cast<void(cocos2d::LayerColor::*)(float)>(&cocos2d::LayerColor::changeHeight)
,"changeWidthAndHeight",static_cast<void(cocos2d::LayerColor::*)(float,float)>(&cocos2d::LayerColor::changeWidthAndHeight)
,"draw",static_cast<void(cocos2d::LayerColor::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerColor::draw)
,"setContentSize",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::Size&)>(&cocos2d::LayerColor::setContentSize)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::LayerColor::*)()const>(&cocos2d::LayerColor::getBlendFunc)
,"setBlendFunc",static_cast<void(cocos2d::LayerColor::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerColor::setBlendFunc)
,"init",static_cast<bool(cocos2d::LayerColor::*)()>(&cocos2d::LayerColor::init)
,"initWithColor",sol::overload(static_cast<bool(cocos2d::LayerColor::*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::initWithColor),static_cast<bool(cocos2d::LayerColor::*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::initWithColor))
,"new",sol::overload(static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&,float,float)>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)()>(&cocos2d::LayerColor::create),static_cast<cocos2d::LayerColor*(*)(const cocos2d::Color4B&)>(&cocos2d::LayerColor::create))
);}
static void RegisterLuaLayerGradient(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::LayerGradient,cocos2d::LayerColor,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::BlendProtocol>("cc","LayerGradient"
,"setCompressedInterpolation",static_cast<void(cocos2d::LayerGradient::*)(bool)>(&cocos2d::LayerGradient::setCompressedInterpolation)
,"isCompressedInterpolation",static_cast<bool(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::isCompressedInterpolation)
,"setStartColor",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setStartColor)
,"getStartColor",static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartColor)
,"setEndColor",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerGradient::setEndColor)
,"getEndColor",static_cast<const cocos2d::Color3B&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndColor)
,"setStartOpacity",static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setStartOpacity)
,"getStartOpacity",static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getStartOpacity)
,"setEndOpacity",static_cast<void(cocos2d::LayerGradient::*)(uint8_t)>(&cocos2d::LayerGradient::setEndOpacity)
,"getEndOpacity",static_cast<uint8_t(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getEndOpacity)
,"setVector",static_cast<void(cocos2d::LayerGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerGradient::setVector)
,"getVector",static_cast<const cocos2d::Vec2&(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getVector)
,"getDescription",static_cast<std::string(cocos2d::LayerGradient::*)()const>(&cocos2d::LayerGradient::getDescription)
,"init",static_cast<bool(cocos2d::LayerGradient::*)()>(&cocos2d::LayerGradient::init)
,"initWithColor",sol::overload(static_cast<bool(cocos2d::LayerGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::initWithColor),static_cast<bool(cocos2d::LayerGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::initWithColor))
,"new",sol::overload(static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&)>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)()>(&cocos2d::LayerGradient::create),static_cast<cocos2d::LayerGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,const cocos2d::Vec2&)>(&cocos2d::LayerGradient::create))
);}
static void RegisterLuaLayerRadialGradient(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::LayerRadialGradient,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","LayerRadialGradient"
,"draw",static_cast<void(cocos2d::LayerRadialGradient::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::LayerRadialGradient::draw)
,"setContentSize",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Size&)>(&cocos2d::LayerRadialGradient::setContentSize)
,"setStartOpacity",static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setStartOpacity)
,"getStartOpacity",static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartOpacity)
,"setEndOpacity",static_cast<void(cocos2d::LayerRadialGradient::*)(uint8_t)>(&cocos2d::LayerRadialGradient::setEndOpacity)
,"getEndOpacity",static_cast<uint8_t(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndOpacity)
,"setRadius",static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setRadius)
,"getRadius",static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getRadius)
,"setCenter",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Vec2&)>(&cocos2d::LayerRadialGradient::setCenter)
,"getCenter",static_cast<cocos2d::Vec2(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getCenter)
,"setExpand",static_cast<void(cocos2d::LayerRadialGradient::*)(float)>(&cocos2d::LayerRadialGradient::setExpand)
,"getExpand",static_cast<float(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getExpand)
,"setStartColor",sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setStartColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setStartColor))
,"getStartColor",static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor)
,"getStartColor3B",static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getStartColor3B)
,"setEndColor",sol::overload(static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&)>(&cocos2d::LayerRadialGradient::setEndColor),static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::Color3B&)>(&cocos2d::LayerRadialGradient::setEndColor))
,"getEndColor",static_cast<cocos2d::Color4B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor)
,"getEndColor3B",static_cast<cocos2d::Color3B(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getEndColor3B)
,"setBlendFunc",static_cast<void(cocos2d::LayerRadialGradient::*)(const cocos2d::BlendFunc&)>(&cocos2d::LayerRadialGradient::setBlendFunc)
,"getBlendFunc",static_cast<cocos2d::BlendFunc(cocos2d::LayerRadialGradient::*)()const>(&cocos2d::LayerRadialGradient::getBlendFunc)
,"initWithColor",static_cast<bool(cocos2d::LayerRadialGradient::*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::initWithColor)
,"new",sol::overload(static_cast<cocos2d::LayerRadialGradient*(*)()>(&cocos2d::LayerRadialGradient::create),static_cast<cocos2d::LayerRadialGradient*(*)(const cocos2d::Color4B&,const cocos2d::Color4B&,float,const cocos2d::Vec2&,float)>(&cocos2d::LayerRadialGradient::create))
);}
static void RegisterLuaLayerMultiplex(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::LayerMultiplex,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","LayerMultiplex"
,"addLayer",static_cast<void(cocos2d::LayerMultiplex::*)(cocos2d::Layer*)>(&cocos2d::LayerMultiplex::addLayer)
,"switchTo",sol::overload(static_cast<void(cocos2d::LayerMultiplex::*)(int,bool)>(&cocos2d::LayerMultiplex::switchTo),static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchTo))
,"switchToAndReleaseMe",static_cast<void(cocos2d::LayerMultiplex::*)(int)>(&cocos2d::LayerMultiplex::switchToAndReleaseMe)
,"getDescription",static_cast<std::string(cocos2d::LayerMultiplex::*)()const>(&cocos2d::LayerMultiplex::getDescription)
,"init",static_cast<bool(cocos2d::LayerMultiplex::*)()>(&cocos2d::LayerMultiplex::init)
,"initWithArray",static_cast<bool(cocos2d::LayerMultiplex::*)(const cocos2d::Vector<cocos2d::Layer *>&)>(&cocos2d::LayerMultiplex::initWithArray)
);}
static void RegisterLuaMenuItem(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItem"
,"rect",static_cast<cocos2d::Rect(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::rect)
,"activate",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::activate)
,"selected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::selected)
,"unselected",static_cast<void(cocos2d::MenuItem::*)()>(&cocos2d::MenuItem::unselected)
,"isEnabled",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isEnabled)
,"setEnabled",static_cast<void(cocos2d::MenuItem::*)(bool)>(&cocos2d::MenuItem::setEnabled)
,"isSelected",static_cast<bool(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::isSelected)
,"SetHandler",static_cast<void(cocos2d::MenuItem::*)(const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItem::SetHandler)
,"getDescription",static_cast<std::string(cocos2d::MenuItem::*)()const>(&cocos2d::MenuItem::getDescription)
);}
static void RegisterLuaMenuItemLabel(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemLabel"
,"setString",static_cast<void(cocos2d::MenuItemLabel::*)(const std::string&)>(&cocos2d::MenuItemLabel::setString)
,"getString",static_cast<std::string(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getString)
,"getDisabledColor",static_cast<const cocos2d::Color3B&(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getDisabledColor)
,"setDisabledColor",static_cast<void(cocos2d::MenuItemLabel::*)(const cocos2d::Color3B&)>(&cocos2d::MenuItemLabel::setDisabledColor)
,"getLabel",static_cast<cocos2d::Node*(cocos2d::MenuItemLabel::*)()const>(&cocos2d::MenuItemLabel::getLabel)
,"setLabel",static_cast<void(cocos2d::MenuItemLabel::*)(cocos2d::Node*)>(&cocos2d::MenuItemLabel::setLabel)
,"activate",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::activate)
,"selected",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::selected)
,"unselected",static_cast<void(cocos2d::MenuItemLabel::*)()>(&cocos2d::MenuItemLabel::unselected)
,"setEnabled",static_cast<void(cocos2d::MenuItemLabel::*)(bool)>(&cocos2d::MenuItemLabel::setEnabled)
,"initWithLabel",static_cast<bool(cocos2d::MenuItemLabel::*)(cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemLabel::initWithLabel)
);}
static void RegisterLuaMenuItemAtlasFont(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItemAtlasFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemAtlasFont"
,"initWithString",static_cast<bool(cocos2d::MenuItemAtlasFont::*)(const std::string&,const std::string&,int,int,char,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemAtlasFont::initWithString)
);}
static void RegisterLuaMenuItemFont(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItemFont,cocos2d::MenuItemLabel,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemFont"
,"setFontSizeObj",static_cast<void(cocos2d::MenuItemFont::*)(int)>(&cocos2d::MenuItemFont::setFontSizeObj)
,"getFontSizeObj",static_cast<int(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontSizeObj)
,"setFontNameObj",static_cast<void(cocos2d::MenuItemFont::*)(const std::string&)>(&cocos2d::MenuItemFont::setFontNameObj)
,"getFontNameObj",static_cast<const std::string&(cocos2d::MenuItemFont::*)()const>(&cocos2d::MenuItemFont::getFontNameObj)
,"initWithString",static_cast<bool(cocos2d::MenuItemFont::*)(const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemFont::initWithString)
,"setFontSize",static_cast<void(*)(int)>(&cocos2d::MenuItemFont::setFontSize)
,"getFontSize",static_cast<int(*)()>(&cocos2d::MenuItemFont::getFontSize)
,"setFontName",static_cast<void(*)(const std::string&)>(&cocos2d::MenuItemFont::setFontName)
,"getFontName",static_cast<const std::string&(*)()>(&cocos2d::MenuItemFont::getFontName)
);}
static void RegisterLuaMenuItemSprite(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemSprite"
,"getNormalImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getNormalImage)
,"setNormalImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setNormalImage)
,"getSelectedImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getSelectedImage)
,"setSelectedImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setSelectedImage)
,"getDisabledImage",static_cast<cocos2d::Node*(cocos2d::MenuItemSprite::*)()const>(&cocos2d::MenuItemSprite::getDisabledImage)
,"setDisabledImage",static_cast<void(cocos2d::MenuItemSprite::*)(cocos2d::Node*)>(&cocos2d::MenuItemSprite::setDisabledImage)
,"selected",static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::selected)
,"unselected",static_cast<void(cocos2d::MenuItemSprite::*)()>(&cocos2d::MenuItemSprite::unselected)
,"setEnabled",static_cast<void(cocos2d::MenuItemSprite::*)(bool)>(&cocos2d::MenuItemSprite::setEnabled)
,"initWithNormalSprite",static_cast<bool(cocos2d::MenuItemSprite::*)(cocos2d::Node*,cocos2d::Node*,cocos2d::Node*,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemSprite::initWithNormalSprite)
);}
static void RegisterLuaMenuItemImage(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItemImage,cocos2d::MenuItemSprite,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemImage"
,"setNormalSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setNormalSpriteFrame)
,"setSelectedSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setSelectedSpriteFrame)
,"setDisabledSpriteFrame",static_cast<void(cocos2d::MenuItemImage::*)(cocos2d::SpriteFrame*)>(&cocos2d::MenuItemImage::setDisabledSpriteFrame)
,"init",static_cast<bool(cocos2d::MenuItemImage::*)()>(&cocos2d::MenuItemImage::init)
,"initWithNormalImage",static_cast<bool(cocos2d::MenuItemImage::*)(const std::string&,const std::string&,const std::string&,const std::function<void (cocos2d::MenuItem *)>&)>(&cocos2d::MenuItemImage::initWithNormalImage)
);}
static void RegisterLuaMenuItemToggle(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MenuItemToggle,cocos2d::MenuItem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","MenuItemToggle"
,"addSubItem",static_cast<void(cocos2d::MenuItemToggle::*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::addSubItem)
,"getSelectedItem",static_cast<cocos2d::MenuItem*(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::getSelectedItem)
,"getSelectedIndex",static_cast<unsigned int(cocos2d::MenuItemToggle::*)()const>(&cocos2d::MenuItemToggle::getSelectedIndex)
,"setSelectedIndex",static_cast<void(cocos2d::MenuItemToggle::*)(unsigned int)>(&cocos2d::MenuItemToggle::setSelectedIndex)
,"setSubItems",static_cast<void(cocos2d::MenuItemToggle::*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::MenuItemToggle::setSubItems)
,"activate",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::activate)
,"selected",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::selected)
,"unselected",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::unselected)
,"setEnabled",static_cast<void(cocos2d::MenuItemToggle::*)(bool)>(&cocos2d::MenuItemToggle::setEnabled)
,"cleanup",static_cast<void(cocos2d::MenuItemToggle::*)()>(&cocos2d::MenuItemToggle::cleanup)
,"initWithItem",static_cast<bool(cocos2d::MenuItemToggle::*)(cocos2d::MenuItem*)>(&cocos2d::MenuItemToggle::initWithItem)
);}
static void RegisterLuaMenu(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Menu,cocos2d::Layer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Menu"
,"alignItemsVertically",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsVertically)
,"alignItemsVerticallyWithPadding",static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsVerticallyWithPadding)
,"alignItemsHorizontally",static_cast<void(cocos2d::Menu::*)()>(&cocos2d::Menu::alignItemsHorizontally)
,"alignItemsHorizontallyWithPadding",static_cast<void(cocos2d::Menu::*)(float)>(&cocos2d::Menu::alignItemsHorizontallyWithPadding)
,"isEnabled",static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isEnabled)
,"setEnabled",static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setEnabled)
,"removeChild",static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,bool)>(&cocos2d::Menu::removeChild)
,"addChild",sol::overload(static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,int)>(&cocos2d::Menu::addChild),static_cast<void(cocos2d::Menu::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Menu::addChild))
,"setOpacityModifyRGB",static_cast<void(cocos2d::Menu::*)(bool)>(&cocos2d::Menu::setOpacityModifyRGB)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::Menu::*)()const>(&cocos2d::Menu::isOpacityModifyRGB)
,"getDescription",static_cast<std::string(cocos2d::Menu::*)()const>(&cocos2d::Menu::getDescription)
,"init",static_cast<bool(cocos2d::Menu::*)()>(&cocos2d::Menu::init)
,"initWithArray",static_cast<bool(cocos2d::Menu::*)(const cocos2d::Vector<cocos2d::MenuItem *>&)>(&cocos2d::Menu::initWithArray)
);}
static void RegisterLuaMotionStreak(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MotionStreak,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","MotionStreak"
,"setPosition",sol::overload(static_cast<void(cocos2d::MotionStreak::*)(float,float)>(&cocos2d::MotionStreak::setPosition),static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak::setPosition))
,"getPosition",sol::overload(static_cast<void(cocos2d::MotionStreak::*)(float*,float*)const>(&cocos2d::MotionStreak::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition))
,"setPositionX",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionX)
,"setPositionY",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setPositionY)
,"getPositionX",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionX)
,"getPositionY",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPositionY)
,"getPosition3D",static_cast<cocos2d::Vec3(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getPosition3D)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getTexture)
,"setTexture",static_cast<void(cocos2d::MotionStreak::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak::setTexture)
,"setBlendFunc",static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getBlendFunc)
,"getOpacity",static_cast<uint8_t(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getOpacity)
,"setOpacity",static_cast<void(cocos2d::MotionStreak::*)(uint8_t)>(&cocos2d::MotionStreak::setOpacity)
,"setOpacityModifyRGB",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setOpacityModifyRGB)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isOpacityModifyRGB)
,"tintWithColor",static_cast<void(cocos2d::MotionStreak::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak::tintWithColor)
,"reset",static_cast<void(cocos2d::MotionStreak::*)()>(&cocos2d::MotionStreak::reset)
,"isFastMode",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isFastMode)
,"setFastMode",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setFastMode)
,"getStroke",static_cast<float(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::getStroke)
,"setStroke",static_cast<void(cocos2d::MotionStreak::*)(float)>(&cocos2d::MotionStreak::setStroke)
,"isStartingPositionInitialized",static_cast<bool(cocos2d::MotionStreak::*)()const>(&cocos2d::MotionStreak::isStartingPositionInitialized)
,"setStartingPositionInitialized",static_cast<void(cocos2d::MotionStreak::*)(bool)>(&cocos2d::MotionStreak::setStartingPositionInitialized)
,"setProgramState",static_cast<bool(cocos2d::MotionStreak::*)(cocos2d::backend::ProgramState*,bool)>(&cocos2d::MotionStreak::setProgramState)
,"initWithFade",sol::overload(static_cast<bool(cocos2d::MotionStreak::*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak::initWithFade),static_cast<bool(cocos2d::MotionStreak::*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak::initWithFade))
,"new",sol::overload(static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak::create),static_cast<cocos2d::MotionStreak*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak::create))
);}
static void RegisterLuaNodeGrid(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::NodeGrid,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","NodeGrid"
,"getGrid",sol::overload(static_cast<const cocos2d::GridBase*(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGrid),static_cast<cocos2d::GridBase*(cocos2d::NodeGrid::*)()>(&cocos2d::NodeGrid::getGrid))
,"setGrid",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::GridBase*)>(&cocos2d::NodeGrid::setGrid)
,"setTarget",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Node*)>(&cocos2d::NodeGrid::setTarget)
,"setGridRect",static_cast<void(cocos2d::NodeGrid::*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::setGridRect)
,"getGridRect",static_cast<const cocos2d::Rect&(cocos2d::NodeGrid::*)()const>(&cocos2d::NodeGrid::getGridRect)
,"visit",static_cast<void(cocos2d::NodeGrid::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::NodeGrid::visit)
,"new",sol::overload(static_cast<cocos2d::NodeGrid*(*)(const cocos2d::Rect&)>(&cocos2d::NodeGrid::create),static_cast<cocos2d::NodeGrid*(*)()>(&cocos2d::NodeGrid::create))
);}
static void RegisterLuaParticleBatchNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","ParticleBatchNode"
,"insertChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::ParticleSystem*,int)>(&cocos2d::ParticleBatchNode::insertChild)
,"removeChildAtIndex",static_cast<void(cocos2d::ParticleBatchNode::*)(int,bool)>(&cocos2d::ParticleBatchNode::removeChildAtIndex)
,"removeAllChildrenWithCleanup",static_cast<void(cocos2d::ParticleBatchNode::*)(bool)>(&cocos2d::ParticleBatchNode::removeAllChildrenWithCleanup)
,"disableParticle",static_cast<void(cocos2d::ParticleBatchNode::*)(int)>(&cocos2d::ParticleBatchNode::disableParticle)
,"getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTextureAtlas)
,"setTextureAtlas",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::ParticleBatchNode::setTextureAtlas)
,"visit",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::visit)
,"addChild",sol::overload(static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParticleBatchNode::addChild),static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParticleBatchNode::addChild))
,"removeChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParticleBatchNode::removeChild)
,"reorderChild",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::ParticleBatchNode::reorderChild)
,"draw",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParticleBatchNode::draw)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getTexture)
,"setTexture",static_cast<void(cocos2d::ParticleBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleBatchNode::setTexture)
,"setBlendFunc",static_cast<void(cocos2d::ParticleBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleBatchNode::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleBatchNode::*)()const>(&cocos2d::ParticleBatchNode::getBlendFunc)
,"initWithTexture",static_cast<bool(cocos2d::ParticleBatchNode::*)(cocos2d::Texture2D*,int)>(&cocos2d::ParticleBatchNode::initWithTexture)
,"initWithFile",static_cast<bool(cocos2d::ParticleBatchNode::*)(const std::string&,int)>(&cocos2d::ParticleBatchNode::initWithFile)
,"createWithTexture",sol::overload([](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::ParticleBatchNode* obj,cocos2d::Texture2D* arg0,int arg1){return obj->createWithTexture(arg0,arg1);})
,"new",sol::overload([](cocos2d::ParticleBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ParticleBatchNode* obj,const std::string& arg0,int arg1){return obj->create(arg0,arg1);})
);}
static void RegisterLuaParticleData(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleData>("cc","ParticleData"
,"init",static_cast<bool(cocos2d::ParticleData::*)(int)>(&cocos2d::ParticleData::init)
,"release",static_cast<void(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::release)
,"getMaxCount",static_cast<unsigned int(cocos2d::ParticleData::*)()>(&cocos2d::ParticleData::getMaxCount)
,"copyParticle",static_cast<void(cocos2d::ParticleData::*)(int,int)>(&cocos2d::ParticleData::copyParticle)
);}
static void RegisterLuaParticleSystem(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSystem"
,"addParticles",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::addParticles)
,"stopSystem",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stopSystem)
,"resetSystem",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::resetSystem)
,"isFull",static_cast<bool(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::isFull)
,"updateParticleQuads",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateParticleQuads)
,"postStep",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::postStep)
,"updateWithNoTime",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::updateWithNoTime)
,"isAutoRemoveOnFinish",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isAutoRemoveOnFinish)
,"setAutoRemoveOnFinish",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setAutoRemoveOnFinish)
,"getGravity",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::getGravity)
,"setGravity",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setGravity)
,"getSpeed",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeed)
,"setSpeed",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeed)
,"getSpeedVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSpeedVar)
,"setSpeedVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setSpeedVar)
,"getTangentialAccel",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccel)
,"setTangentialAccel",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccel)
,"getTangentialAccelVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTangentialAccelVar)
,"setTangentialAccelVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setTangentialAccelVar)
,"getRadialAccel",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccel)
,"setRadialAccel",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccel)
,"getRadialAccelVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRadialAccelVar)
,"setRadialAccelVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRadialAccelVar)
,"getRotationIsDir",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotationIsDir)
,"setRotationIsDir",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setRotationIsDir)
,"getStartRadius",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadius)
,"setStartRadius",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadius)
,"getStartRadiusVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartRadiusVar)
,"setStartRadiusVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartRadiusVar)
,"getEndRadius",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadius)
,"setEndRadius",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadius)
,"getEndRadiusVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndRadiusVar)
,"setEndRadiusVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndRadiusVar)
,"getRotatePerSecond",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecond)
,"setRotatePerSecond",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecond)
,"getRotatePerSecondVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getRotatePerSecondVar)
,"setRotatePerSecondVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotatePerSecondVar)
,"setScale",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScale)
,"setRotation",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setRotation)
,"setScaleX",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleX)
,"setScaleY",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setScaleY)
,"isActive",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isActive)
,"isBlendAdditive",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isBlendAdditive)
,"setBlendAdditive",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setBlendAdditive)
,"getBatchNode",static_cast<cocos2d::ParticleBatchNode*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBatchNode)
,"setBatchNode",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleBatchNode*)>(&cocos2d::ParticleSystem::setBatchNode)
,"getAtlasIndex",static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAtlasIndex)
,"setAtlasIndex",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setAtlasIndex)
,"getParticleCount",static_cast<unsigned int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getParticleCount)
,"getDuration",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getDuration)
,"setDuration",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setDuration)
,"getSourcePosition",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getSourcePosition)
,"setSourcePosition",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setSourcePosition)
,"getPosVar",static_cast<const cocos2d::Vec2&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPosVar)
,"setPosVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Vec2&)>(&cocos2d::ParticleSystem::setPosVar)
,"getLife",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLife)
,"setLife",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLife)
,"getLifeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getLifeVar)
,"setLifeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setLifeVar)
,"getAngle",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngle)
,"setAngle",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngle)
,"getAngleVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getAngleVar)
,"setAngleVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setAngleVar)
,"getEmitterMode",static_cast<cocos2d::ParticleSystem::Mode(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmitterMode)
,"setEmitterMode",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::Mode)>(&cocos2d::ParticleSystem::setEmitterMode)
,"getStartSize",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSize)
,"setStartSize",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSize)
,"getStartSizeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSizeVar)
,"setStartSizeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSizeVar)
,"getEndSize",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSize)
,"setEndSize",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSize)
,"getEndSizeVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSizeVar)
,"setEndSizeVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSizeVar)
,"getStartColor",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColor)
,"setStartColor",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColor)
,"getStartColorVar",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartColorVar)
,"setStartColorVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setStartColorVar)
,"getEndColor",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColor)
,"setEndColor",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColor)
,"getEndColorVar",static_cast<const cocos2d::Color4F&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndColorVar)
,"setEndColorVar",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::Color4F&)>(&cocos2d::ParticleSystem::setEndColorVar)
,"getStartSpin",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpin)
,"setStartSpin",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpin)
,"getStartSpinVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getStartSpinVar)
,"setStartSpinVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setStartSpinVar)
,"getEndSpin",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpin)
,"setEndSpin",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpin)
,"getEndSpinVar",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEndSpinVar)
,"setEndSpinVar",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEndSpinVar)
,"getEmissionRate",static_cast<float(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getEmissionRate)
,"setEmissionRate",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::setEmissionRate)
,"getTotalParticles",static_cast<int(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTotalParticles)
,"setTotalParticles",static_cast<void(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::setTotalParticles)
,"setOpacityModifyRGB",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setOpacityModifyRGB)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isOpacityModifyRGB)
,"getPositionType",static_cast<cocos2d::ParticleSystem::PositionType(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getPositionType)
,"setPositionType",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::ParticleSystem::PositionType)>(&cocos2d::ParticleSystem::setPositionType)
,"update",static_cast<void(cocos2d::ParticleSystem::*)(float)>(&cocos2d::ParticleSystem::update)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getTexture)
,"setTexture",static_cast<void(cocos2d::ParticleSystem::*)(cocos2d::Texture2D*)>(&cocos2d::ParticleSystem::setTexture)
,"setBlendFunc",static_cast<void(cocos2d::ParticleSystem::*)(const cocos2d::BlendFunc&)>(&cocos2d::ParticleSystem::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getBlendFunc)
,"getResourceFile",static_cast<const std::string&(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::getResourceFile)
,"start",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::start)
,"stop",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::stop)
,"setSourcePositionCompatible",static_cast<void(cocos2d::ParticleSystem::*)(bool)>(&cocos2d::ParticleSystem::setSourcePositionCompatible)
,"isSourcePositionCompatible",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isSourcePositionCompatible)
,"init",static_cast<bool(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::init)
,"initWithFile",static_cast<bool(cocos2d::ParticleSystem::*)(const std::string&)>(&cocos2d::ParticleSystem::initWithFile)
,"initWithDictionary",sol::overload(static_cast<bool(cocos2d::ParticleSystem::*)(cocos2d::ValueMap&,const std::string&)>(&cocos2d::ParticleSystem::initWithDictionary),static_cast<bool(cocos2d::ParticleSystem::*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystem::initWithDictionary))
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleSystem::*)(int)>(&cocos2d::ParticleSystem::initWithTotalParticles)
,"isPaused",static_cast<bool(cocos2d::ParticleSystem::*)()const>(&cocos2d::ParticleSystem::isPaused)
,"pauseEmissions",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::pauseEmissions)
,"resumeEmissions",static_cast<void(cocos2d::ParticleSystem::*)()>(&cocos2d::ParticleSystem::resumeEmissions)
,"new",static_cast<cocos2d::ParticleSystem*(*)(const std::string&)>(&cocos2d::ParticleSystem::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleSystem*(*)(int)>(&cocos2d::ParticleSystem::createWithTotalParticles)
,"getAllParticleSystems",static_cast<cocos2d::Vector<cocos2d::ParticleSystem *>&(*)()>(&cocos2d::ParticleSystem::getAllParticleSystems)
);}
static void RegisterLuaParticleSystemQuad(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSystemQuad"
,"setDisplayFrame",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::SpriteFrame*)>(&cocos2d::ParticleSystemQuad::setDisplayFrame)
,"setTextureWithRect",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::ParticleSystemQuad::setTextureWithRect)
,"listenRendererRecreated",static_cast<void(cocos2d::ParticleSystemQuad::*)(cocos2d::EventCustom*)>(&cocos2d::ParticleSystemQuad::listenRendererRecreated)
,"updateParticleQuads",static_cast<void(cocos2d::ParticleSystemQuad::*)()>(&cocos2d::ParticleSystemQuad::updateParticleQuads)
,"getDescription",static_cast<std::string(cocos2d::ParticleSystemQuad::*)()const>(&cocos2d::ParticleSystemQuad::getDescription)
,"new",sol::overload(static_cast<cocos2d::ParticleSystemQuad*(*)(const std::string&)>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)()>(&cocos2d::ParticleSystemQuad::create),static_cast<cocos2d::ParticleSystemQuad*(*)(cocos2d::ValueMap&)>(&cocos2d::ParticleSystemQuad::create))
,"createWithTotalParticles",static_cast<cocos2d::ParticleSystemQuad*(*)(int)>(&cocos2d::ParticleSystemQuad::createWithTotalParticles)
);}
static void RegisterLuaParticleFire(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleFire,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFire"
,"init",static_cast<bool(cocos2d::ParticleFire::*)()>(&cocos2d::ParticleFire::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleFire::*)(int)>(&cocos2d::ParticleFire::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleFire*(*)()>(&cocos2d::ParticleFire::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleFire*(*)(int)>(&cocos2d::ParticleFire::createWithTotalParticles)
);}
static void RegisterLuaParticleFireworks(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleFireworks,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFireworks"
,"init",static_cast<bool(cocos2d::ParticleFireworks::*)()>(&cocos2d::ParticleFireworks::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleFireworks::*)(int)>(&cocos2d::ParticleFireworks::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleFireworks*(*)()>(&cocos2d::ParticleFireworks::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleFireworks*(*)(int)>(&cocos2d::ParticleFireworks::createWithTotalParticles)
);}
static void RegisterLuaParticleSun(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSun,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSun"
,"init",static_cast<bool(cocos2d::ParticleSun::*)()>(&cocos2d::ParticleSun::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleSun::*)(int)>(&cocos2d::ParticleSun::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleSun*(*)()>(&cocos2d::ParticleSun::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleSun*(*)(int)>(&cocos2d::ParticleSun::createWithTotalParticles)
);}
static void RegisterLuaParticleGalaxy(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleGalaxy,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleGalaxy"
,"init",static_cast<bool(cocos2d::ParticleGalaxy::*)()>(&cocos2d::ParticleGalaxy::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleGalaxy::*)(int)>(&cocos2d::ParticleGalaxy::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleGalaxy*(*)()>(&cocos2d::ParticleGalaxy::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleGalaxy*(*)(int)>(&cocos2d::ParticleGalaxy::createWithTotalParticles)
);}
static void RegisterLuaParticleFlower(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleFlower,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleFlower"
,"init",static_cast<bool(cocos2d::ParticleFlower::*)()>(&cocos2d::ParticleFlower::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleFlower::*)(int)>(&cocos2d::ParticleFlower::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleFlower*(*)()>(&cocos2d::ParticleFlower::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleFlower*(*)(int)>(&cocos2d::ParticleFlower::createWithTotalParticles)
);}
static void RegisterLuaParticleMeteor(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleMeteor,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleMeteor"
,"init",static_cast<bool(cocos2d::ParticleMeteor::*)()>(&cocos2d::ParticleMeteor::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleMeteor::*)(int)>(&cocos2d::ParticleMeteor::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleMeteor*(*)()>(&cocos2d::ParticleMeteor::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleMeteor*(*)(int)>(&cocos2d::ParticleMeteor::createWithTotalParticles)
);}
static void RegisterLuaParticleSpiral(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSpiral,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSpiral"
,"init",static_cast<bool(cocos2d::ParticleSpiral::*)()>(&cocos2d::ParticleSpiral::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleSpiral::*)(int)>(&cocos2d::ParticleSpiral::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleSpiral*(*)()>(&cocos2d::ParticleSpiral::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleSpiral*(*)(int)>(&cocos2d::ParticleSpiral::createWithTotalParticles)
);}
static void RegisterLuaParticleExplosion(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleExplosion,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleExplosion"
,"init",static_cast<bool(cocos2d::ParticleExplosion::*)()>(&cocos2d::ParticleExplosion::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleExplosion::*)(int)>(&cocos2d::ParticleExplosion::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleExplosion*(*)()>(&cocos2d::ParticleExplosion::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleExplosion*(*)(int)>(&cocos2d::ParticleExplosion::createWithTotalParticles)
);}
static void RegisterLuaParticleSmoke(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSmoke,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSmoke"
,"init",static_cast<bool(cocos2d::ParticleSmoke::*)()>(&cocos2d::ParticleSmoke::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleSmoke::*)(int)>(&cocos2d::ParticleSmoke::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleSmoke*(*)()>(&cocos2d::ParticleSmoke::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleSmoke*(*)(int)>(&cocos2d::ParticleSmoke::createWithTotalParticles)
);}
static void RegisterLuaParticleSnow(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleSnow,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleSnow"
,"init",static_cast<bool(cocos2d::ParticleSnow::*)()>(&cocos2d::ParticleSnow::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleSnow::*)(int)>(&cocos2d::ParticleSnow::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleSnow*(*)()>(&cocos2d::ParticleSnow::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleSnow*(*)(int)>(&cocos2d::ParticleSnow::createWithTotalParticles)
);}
static void RegisterLuaParticleRain(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParticleRain,cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>("cc","ParticleRain"
,"init",static_cast<bool(cocos2d::ParticleRain::*)()>(&cocos2d::ParticleRain::init)
,"initWithTotalParticles",static_cast<bool(cocos2d::ParticleRain::*)(int)>(&cocos2d::ParticleRain::initWithTotalParticles)
,"new",static_cast<cocos2d::ParticleRain*(*)()>(&cocos2d::ParticleRain::create)
,"createWithTotalParticles",static_cast<cocos2d::ParticleRain*(*)(int)>(&cocos2d::ParticleRain::createWithTotalParticles)
);}
static void RegisterLuaProgressTimer(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ProgressTimer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ProgressTimer"
,"getType",static_cast<cocos2d::ProgressTimer::Type(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getType)
,"getPercentage",static_cast<float(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getPercentage)
,"getSprite",static_cast<cocos2d::Sprite*(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getSprite)
,"setPercentage",static_cast<void(cocos2d::ProgressTimer::*)(float)>(&cocos2d::ProgressTimer::setPercentage)
,"setSprite",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::setSprite)
,"setType",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::ProgressTimer::Type)>(&cocos2d::ProgressTimer::setType)
,"isReverseDirection",static_cast<bool(cocos2d::ProgressTimer::*)()>(&cocos2d::ProgressTimer::isReverseDirection)
,"setReverseDirection",static_cast<void(cocos2d::ProgressTimer::*)(bool)>(&cocos2d::ProgressTimer::setReverseDirection)
,"setMidpoint",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setMidpoint)
,"getMidpoint",static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getMidpoint)
,"setBarChangeRate",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setBarChangeRate)
,"getBarChangeRate",static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getBarChangeRate)
,"draw",static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProgressTimer::draw)
,"setAnchorPoint",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setAnchorPoint)
,"setColor",static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Color3B&)>(&cocos2d::ProgressTimer::setColor)
,"getColor",static_cast<const cocos2d::Color3B&(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getColor)
,"setOpacity",static_cast<void(cocos2d::ProgressTimer::*)(uint8_t)>(&cocos2d::ProgressTimer::setOpacity)
,"getOpacity",static_cast<uint8_t(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getOpacity)
,"initWithSprite",static_cast<bool(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::initWithSprite)
,"new",static_cast<cocos2d::ProgressTimer*(*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::create)
);}
static void RegisterLuaProtectedNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ProtectedNode"
,"addProtectedChild",sol::overload(static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ProtectedNode::addProtectedChild))
,"getProtectedChildByTag",static_cast<cocos2d::Node*(cocos2d::ProtectedNode::*)(int)>(&cocos2d::ProtectedNode::getProtectedChildByTag)
,"removeProtectedChild",sol::overload([](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0){return obj->removeProtectedChild(arg0);},[](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0,bool arg1){return obj->removeProtectedChild(arg0,arg1);})
,"removeProtectedChildByTag",sol::overload([](cocos2d::ProtectedNode* obj,int arg0){return obj->removeProtectedChildByTag(arg0);},[](cocos2d::ProtectedNode* obj,int arg0,bool arg1){return obj->removeProtectedChildByTag(arg0,arg1);})
,"removeAllProtectedChildren",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::removeAllProtectedChildren)
,"removeAllProtectedChildrenWithCleanup",static_cast<void(cocos2d::ProtectedNode::*)(bool)>(&cocos2d::ProtectedNode::removeAllProtectedChildrenWithCleanup)
,"reorderProtectedChild",static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::reorderProtectedChild)
,"sortAllProtectedChildren",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::sortAllProtectedChildren)
,"visit",static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProtectedNode::visit)
,"cleanup",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::cleanup)
,"updateDisplayedOpacity",static_cast<void(cocos2d::ProtectedNode::*)(uint8_t)>(&cocos2d::ProtectedNode::updateDisplayedOpacity)
,"updateDisplayedColor",static_cast<void(cocos2d::ProtectedNode::*)(const cocos2d::Color3B&)>(&cocos2d::ProtectedNode::updateDisplayedColor)
,"disableCascadeColor",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeColor)
,"disableCascadeOpacity",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeOpacity)
,"setCameraMask",sol::overload([](cocos2d::ProtectedNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ProtectedNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);})
,"setGlobalZOrder",static_cast<void(cocos2d::ProtectedNode::*)(float)>(&cocos2d::ProtectedNode::setGlobalZOrder)
,"new",static_cast<cocos2d::ProtectedNode*(*)()>(&cocos2d::ProtectedNode::create)
);}
static void RegisterLuaSprite(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","Sprite"
,"updateTransform",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::updateTransform)
,"getBatchNode",static_cast<cocos2d::SpriteBatchNode*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBatchNode)
,"setBatchNode",static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteBatchNode*)>(&cocos2d::Sprite::setBatchNode)
,"setTexture",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::setTexture),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setTexture))
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTexture)
,"setTextureRect",sol::overload(static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&,bool,const cocos2d::Size&)>(&cocos2d::Sprite::setTextureRect),static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setTextureRect))
,"setVertexRect",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setVertexRect)
,"setCenterRectNormalized",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRectNormalized)
,"getCenterRectNormalized",static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRectNormalized)
,"setCenterRect",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRect)
,"getCenterRect",static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRect)
,"setSpriteFrame",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::setSpriteFrame),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setSpriteFrame))
,"isFrameDisplayed",static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)const>(&cocos2d::Sprite::isFrameDisplayed)
,"getSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getSpriteFrame)
,"setDisplayFrameWithAnimationName",static_cast<void(cocos2d::Sprite::*)(const std::string&,unsigned int)>(&cocos2d::Sprite::setDisplayFrameWithAnimationName)
,"isDirty",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isDirty)
,"setDirty",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setDirty)
,"getDescription",static_cast<std::string(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getDescription)
,"setScaleX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleX)
,"setScaleY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleY)
,"setScale",sol::overload(static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScale),static_cast<void(cocos2d::Sprite::*)(float,float)>(&cocos2d::Sprite::setScale))
,"setRotation",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotation)
,"setRotationSkewX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewX)
,"setRotationSkewY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewY)
,"setSkewX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewX)
,"setSkewY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewY)
,"removeChild",static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,bool)>(&cocos2d::Sprite::removeChild)
,"removeAllChildrenWithCleanup",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::removeAllChildrenWithCleanup)
,"reorderChild",static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int)>(&cocos2d::Sprite::reorderChild)
,"addChild",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Sprite::addChild),static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,int)>(&cocos2d::Sprite::addChild))
,"sortAllChildren",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::sortAllChildren)
,"setPositionZ",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setPositionZ)
,"setAnchorPoint",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Vec2&)>(&cocos2d::Sprite::setAnchorPoint)
,"setContentSize",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Size&)>(&cocos2d::Sprite::setContentSize)
,"setIgnoreAnchorPointForPosition",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setIgnoreAnchorPointForPosition)
,"setVisible",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setVisible)
,"draw",static_cast<void(cocos2d::Sprite::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite::draw)
,"setOpacityModifyRGB",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setOpacityModifyRGB)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isOpacityModifyRGB)
,"isTextureRectRotated",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isTextureRectRotated)
,"getAtlasIndex",static_cast<unsigned int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getAtlasIndex)
,"setAtlasIndex",static_cast<void(cocos2d::Sprite::*)(unsigned int)>(&cocos2d::Sprite::setAtlasIndex)
,"getTextureRect",static_cast<const cocos2d::Rect&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureRect)
,"getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureAtlas)
,"setProgramState",sol::overload(static_cast<void(cocos2d::Sprite::*)(uint32_t)>(&cocos2d::Sprite::setProgramState),[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);})
,"setTextureAtlas",static_cast<void(cocos2d::Sprite::*)(cocos2d::TextureAtlas*)>(&cocos2d::Sprite::setTextureAtlas)
,"getOffsetPosition",static_cast<const cocos2d::Vec2&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getOffsetPosition)
,"isFlippedX",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedX)
,"setFlippedX",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedX)
,"isFlippedY",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedY)
,"setFlippedY",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedY)
,"setStretchEnabled",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setStretchEnabled)
,"isStretchEnabled",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isStretchEnabled)
,"setBlendFunc",static_cast<void(cocos2d::Sprite::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBlendFunc)
,"getResourceType",static_cast<int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceType)
,"getResourceName",static_cast<const std::string&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceName)
,"init",static_cast<bool(cocos2d::Sprite::*)()>(&cocos2d::Sprite::init)
,"initWithTexture",sol::overload(static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Sprite::initWithTexture),static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::initWithTexture),static_cast<bool(cocos2d::Sprite::*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool)>(&cocos2d::Sprite::initWithTexture))
,"initWithSpriteFrame",static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::initWithSpriteFrame)
,"initWithSpriteFrameName",static_cast<bool(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::initWithSpriteFrameName)
,"initWithFile",sol::overload(static_cast<bool(cocos2d::Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::Sprite::initWithFile),static_cast<bool(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::initWithFile))
,"setVertexLayout",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::setVertexLayout)
,"createWithTexture",sol::overload([](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1){return obj->createWithTexture(arg0,arg1);},[](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1,bool arg2){return obj->createWithTexture(arg0,arg1,arg2);},static_cast<cocos2d::Sprite*(*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::createWithTexture))
,"createWithSpriteFrame",static_cast<cocos2d::Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::createWithSpriteFrame)
,"createWithSpriteFrameName",static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::createWithSpriteFrameName)
);}
static void RegisterLuaRenderTexture(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::RenderTexture,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","RenderTexture"
,"visit",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::visit)
,"draw",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::draw)
,"begin",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::begin)
,"beginWithClear",sol::overload(static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float,int)>(&cocos2d::RenderTexture::beginWithClear))
,"endToLua",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::end)
,"clear",static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::clear)
,"clearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::clearDepth)
,"clearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::clearStencil)
,"saveToFileAsNonPMA",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(const std::string&,cocos2d::Image::Format,bool,std::function<void (cocos2d::RenderTexture *, const std::string&)>)>(&cocos2d::RenderTexture::saveToFileAsNonPMA),[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFileAsNonPMA(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFileAsNonPMA(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFileAsNonPMA(arg0,arg1,arg2);})
,"saveToFile",sol::overload([](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg3){return obj->saveToFile(arg0,arg1,arg2,arg3);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFile(arg0,arg1,arg2);})
,"getClearFlags",static_cast<cocos2d::ClearFlag(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearFlags)
,"setClearFlags",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::ClearFlag)>(&cocos2d::RenderTexture::setClearFlags)
,"getClearColor",static_cast<const cocos2d::Color4F&(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearColor)
,"setClearColor",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Color4F&)>(&cocos2d::RenderTexture::setClearColor)
,"getClearDepth",static_cast<float(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearDepth)
,"setClearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::setClearDepth)
,"getClearStencil",static_cast<int(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearStencil)
,"setClearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::setClearStencil)
,"isAutoDraw",static_cast<bool(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::isAutoDraw)
,"setAutoDraw",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setAutoDraw)
,"getSprite",static_cast<cocos2d::Sprite*(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getSprite)
,"setSprite",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Sprite*)>(&cocos2d::RenderTexture::setSprite)
,"setKeepMatrix",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setKeepMatrix)
,"setVirtualViewport",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Vec2&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::RenderTexture::setVirtualViewport)
,"initWithWidthAndHeight",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight),static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight))
,"new",sol::overload(static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int)>(&cocos2d::RenderTexture::create))
);}
static void RegisterLuaTransitionEaseScene(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionEaseScene>("cc","TransitionEaseScene"
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction)
);}
static void RegisterLuaTransitionScene(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionScene"
,"finish",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish)
,"hideOutShowIn",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn)
,"getInScene",static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene)
,"getDuration",static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration)
,"draw",static_cast<void(cocos2d::TransitionScene::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionScene::draw)
,"cleanup",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::cleanup)
,"initWithDuration",static_cast<bool(cocos2d::TransitionScene::*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::initWithDuration)
,"new",static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create)
);}
static void RegisterLuaTransitionSceneOriented(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionSceneOriented"
,"initWithDuration",static_cast<bool(cocos2d::TransitionSceneOriented::*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::initWithDuration)
,"new",static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create)
);}
static void RegisterLuaTransitionRotoZoom(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionRotoZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionRotoZoom"
,"new",static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create)
);}
static void RegisterLuaTransitionJumpZoom(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionJumpZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionJumpZoom"
,"new",static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create)
);}
static void RegisterLuaTransitionMoveInL(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInL"
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action)
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction)
,"new",static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create)
);}
static void RegisterLuaTransitionMoveInR(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionMoveInR,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInR"
,"new",static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create)
);}
static void RegisterLuaTransitionMoveInT(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionMoveInT,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInT"
,"new",static_cast<cocos2d::TransitionMoveInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInT::create)
);}
static void RegisterLuaTransitionMoveInB(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionMoveInB,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInB"
,"new",static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create)
);}
static void RegisterLuaTransitionSlideInL(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInL"
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSlideInL::easeActionWithAction)
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInL::*)()>(&cocos2d::TransitionSlideInL::action)
,"new",static_cast<cocos2d::TransitionSlideInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInL::create)
);}
static void RegisterLuaTransitionSlideInR(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSlideInR,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInR"
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInR::*)()>(&cocos2d::TransitionSlideInR::action)
,"new",static_cast<cocos2d::TransitionSlideInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInR::create)
);}
static void RegisterLuaTransitionSlideInB(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSlideInB,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInB"
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInB::*)()>(&cocos2d::TransitionSlideInB::action)
,"new",static_cast<cocos2d::TransitionSlideInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInB::create)
);}
static void RegisterLuaTransitionSlideInT(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSlideInT,cocos2d::TransitionSlideInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSlideInT"
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSlideInT::*)()>(&cocos2d::TransitionSlideInT::action)
,"new",static_cast<cocos2d::TransitionSlideInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSlideInT::create)
);}
static void RegisterLuaTransitionShrinkGrow(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionShrinkGrow,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionShrinkGrow"
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionShrinkGrow::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionShrinkGrow::easeActionWithAction)
,"new",static_cast<cocos2d::TransitionShrinkGrow*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionShrinkGrow::create)
);}
static void RegisterLuaTransitionFlipX(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipX"
,"new",sol::overload(static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipX::create),static_cast<cocos2d::TransitionFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipX::create))
);}
static void RegisterLuaTransitionFlipY(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipY"
,"new",sol::overload(static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipY::create),static_cast<cocos2d::TransitionFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipY::create))
);}
static void RegisterLuaTransitionFlipAngular(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFlipAngular"
,"new",sol::overload(static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFlipAngular::create),static_cast<cocos2d::TransitionFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionFlipAngular::create))
);}
static void RegisterLuaTransitionZoomFlipX(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionZoomFlipX,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipX"
,"new",sol::overload(static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipX::create),static_cast<cocos2d::TransitionZoomFlipX*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipX::create))
);}
static void RegisterLuaTransitionZoomFlipY(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionZoomFlipY,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipY"
,"new",sol::overload(static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipY::create),static_cast<cocos2d::TransitionZoomFlipY*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipY::create))
);}
static void RegisterLuaTransitionZoomFlipAngular(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionZoomFlipAngular,cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionZoomFlipAngular"
,"new",sol::overload(static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionZoomFlipAngular::create),static_cast<cocos2d::TransitionZoomFlipAngular*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionZoomFlipAngular::create))
);}
static void RegisterLuaTransitionFade(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionFade"
,"initWithDuration",sol::overload(static_cast<bool(cocos2d::TransitionFade::*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::initWithDuration),static_cast<bool(cocos2d::TransitionFade::*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::initWithDuration))
,"new",sol::overload(static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFade::create),static_cast<cocos2d::TransitionFade*(*)(float,cocos2d::Scene*,const cocos2d::Color3B&)>(&cocos2d::TransitionFade::create))
);}
static void RegisterLuaTransitionCrossFade(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionCrossFade,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionCrossFade"
,"draw",static_cast<void(cocos2d::TransitionCrossFade::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionCrossFade::draw)
,"new",static_cast<cocos2d::TransitionCrossFade*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionCrossFade::create)
);}
static void RegisterLuaTransitionTurnOffTiles(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionTurnOffTiles,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionTurnOffTiles"
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionTurnOffTiles::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionTurnOffTiles::easeActionWithAction)
,"draw",static_cast<void(cocos2d::TransitionTurnOffTiles::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionTurnOffTiles::draw)
,"new",static_cast<cocos2d::TransitionTurnOffTiles*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionTurnOffTiles::create)
);}
static void RegisterLuaTransitionSplitCols(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSplitCols"
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)()>(&cocos2d::TransitionSplitCols::action)
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitCols::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionSplitCols::easeActionWithAction)
,"draw",static_cast<void(cocos2d::TransitionSplitCols::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionSplitCols::draw)
,"new",static_cast<cocos2d::TransitionSplitCols*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitCols::create)
);}
static void RegisterLuaTransitionSplitRows(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionSplitRows,cocos2d::TransitionSplitCols,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionSplitRows"
,"action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionSplitRows::*)()>(&cocos2d::TransitionSplitRows::action)
,"new",static_cast<cocos2d::TransitionSplitRows*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionSplitRows::create)
);}
static void RegisterLuaTransitionFadeTR(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeTR"
,"actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeTR::actionWithSize)
,"easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeTR::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionFadeTR::easeActionWithAction)
,"draw",static_cast<void(cocos2d::TransitionFadeTR::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionFadeTR::draw)
,"new",static_cast<cocos2d::TransitionFadeTR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeTR::create)
);}
static void RegisterLuaTransitionFadeBL(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFadeBL,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeBL"
,"actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeBL::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeBL::actionWithSize)
,"new",static_cast<cocos2d::TransitionFadeBL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeBL::create)
);}
static void RegisterLuaTransitionFadeUp(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFadeUp,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeUp"
,"actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeUp::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeUp::actionWithSize)
,"new",static_cast<cocos2d::TransitionFadeUp*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeUp::create)
);}
static void RegisterLuaTransitionFadeDown(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionFadeDown,cocos2d::TransitionFadeTR,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionFadeDown"
,"actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionFadeDown::*)(const cocos2d::Size&)>(&cocos2d::TransitionFadeDown::actionWithSize)
,"new",static_cast<cocos2d::TransitionFadeDown*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionFadeDown::create)
);}
static void RegisterLuaTransitionPageTurn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionPageTurn,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionPageTurn"
,"draw",static_cast<void(cocos2d::TransitionPageTurn::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionPageTurn::draw)
,"initWithDuration",static_cast<bool(cocos2d::TransitionPageTurn::*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::initWithDuration)
,"actionWithSize",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionPageTurn::*)(const cocos2d::Size&)>(&cocos2d::TransitionPageTurn::actionWithSize)
,"new",static_cast<cocos2d::TransitionPageTurn*(*)(float,cocos2d::Scene*,bool)>(&cocos2d::TransitionPageTurn::create)
);}
static void RegisterLuaTransitionProgress(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgress"
,"new",static_cast<cocos2d::TransitionProgress*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgress::create)
);}
static void RegisterLuaTransitionProgressRadialCCW(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgressRadialCCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressRadialCCW"
,"new",static_cast<cocos2d::TransitionProgressRadialCCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCCW::create)
);}
static void RegisterLuaTransitionProgressRadialCW(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgressRadialCW,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressRadialCW"
,"new",static_cast<cocos2d::TransitionProgressRadialCW*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressRadialCW::create)
);}
static void RegisterLuaTransitionProgressHorizontal(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgressHorizontal,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressHorizontal"
,"new",static_cast<cocos2d::TransitionProgressHorizontal*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressHorizontal::create)
);}
static void RegisterLuaTransitionProgressVertical(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgressVertical,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressVertical"
,"new",static_cast<cocos2d::TransitionProgressVertical*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressVertical::create)
);}
static void RegisterLuaTransitionProgressInOut(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgressInOut,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressInOut"
,"new",static_cast<cocos2d::TransitionProgressInOut*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressInOut::create)
);}
static void RegisterLuaTransitionProgressOutIn(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TransitionProgressOutIn,cocos2d::TransitionProgress,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionProgressOutIn"
,"new",static_cast<cocos2d::TransitionProgressOutIn*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionProgressOutIn::create)
);}
static void RegisterLuaCamera(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Camera,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","Camera"
,"getType",static_cast<cocos2d::Camera::Type(cocos2d::Camera::*)()const>(&cocos2d::Camera::getType)
,"getCameraFlag",static_cast<cocos2d::CameraFlag(cocos2d::Camera::*)()const>(&cocos2d::Camera::getCameraFlag)
,"setCameraFlag",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraFlag)>(&cocos2d::Camera::setCameraFlag)
,"lookAt",sol::overload([](cocos2d::Camera* obj,const cocos2d::Vec3& arg0){return obj->lookAt(arg0);},[](cocos2d::Camera* obj,const cocos2d::Vec3& arg0,const cocos2d::Vec3& arg1){return obj->lookAt(arg0,arg1);})
,"getProjectionMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getProjectionMatrix)
,"getViewMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewMatrix)
,"getViewProjectionMatrix",static_cast<const cocos2d::Mat4&(cocos2d::Camera::*)()const>(&cocos2d::Camera::getViewProjectionMatrix)
,"project",static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::project)
,"projectGL",static_cast<cocos2d::Vec2(cocos2d::Camera::*)(const cocos2d::Vec3&)const>(&cocos2d::Camera::projectGL)
,"isVisibleInFrustum",static_cast<bool(cocos2d::Camera::*)(const cocos2d::AABB*)const>(&cocos2d::Camera::isVisibleInFrustum)
,"getDepthInView",static_cast<float(cocos2d::Camera::*)(const cocos2d::Mat4&)const>(&cocos2d::Camera::getDepthInView)
,"setDepth",static_cast<void(cocos2d::Camera::*)(int8_t)>(&cocos2d::Camera::setDepth)
,"getDepth",static_cast<int8_t(cocos2d::Camera::*)()const>(&cocos2d::Camera::getDepth)
,"getRenderOrder",static_cast<int(cocos2d::Camera::*)()const>(&cocos2d::Camera::getRenderOrder)
,"getFarPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getFarPlane)
,"getNearPlane",static_cast<float(cocos2d::Camera::*)()const>(&cocos2d::Camera::getNearPlane)
,"clearBackground",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::clearBackground)
,"apply",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::apply)
,"isViewProjectionUpdated",static_cast<bool(cocos2d::Camera::*)()const>(&cocos2d::Camera::isViewProjectionUpdated)
,"setBackgroundBrush",static_cast<void(cocos2d::Camera::*)(cocos2d::CameraBackgroundBrush*)>(&cocos2d::Camera::setBackgroundBrush)
,"getBackgroundBrush",static_cast<cocos2d::CameraBackgroundBrush*(cocos2d::Camera::*)()const>(&cocos2d::Camera::getBackgroundBrush)
,"visit",static_cast<void(cocos2d::Camera::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Camera::visit)
,"isBrushValid",static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::isBrushValid)
,"setScene",static_cast<void(cocos2d::Camera::*)(cocos2d::Scene*)>(&cocos2d::Camera::setScene)
,"setAdditionalProjection",static_cast<void(cocos2d::Camera::*)(const cocos2d::Mat4&)>(&cocos2d::Camera::setAdditionalProjection)
,"initDefault",static_cast<bool(cocos2d::Camera::*)()>(&cocos2d::Camera::initDefault)
,"initPerspective",static_cast<bool(cocos2d::Camera::*)(float,float,float,float)>(&cocos2d::Camera::initPerspective)
,"initOrthographic",static_cast<bool(cocos2d::Camera::*)(float,float,float,float)>(&cocos2d::Camera::initOrthographic)
,"applyViewport",static_cast<void(cocos2d::Camera::*)()>(&cocos2d::Camera::applyViewport)
,"createPerspective",static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createPerspective)
,"createOrthographic",static_cast<cocos2d::Camera*(*)(float,float,float,float)>(&cocos2d::Camera::createOrthographic)
,"new",static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::create)
,"getVisitingCamera",static_cast<const cocos2d::Camera*(*)()>(&cocos2d::Camera::getVisitingCamera)
,"getDefaultViewport",static_cast<const cocos2d::Viewport&(*)()>(&cocos2d::Camera::getDefaultViewport)
,"setDefaultViewport",static_cast<void(*)(const cocos2d::Viewport&)>(&cocos2d::Camera::setDefaultViewport)
,"getDefaultCamera",static_cast<cocos2d::Camera*(*)()>(&cocos2d::Camera::getDefaultCamera)
);}
static void RegisterLuaCameraBackgroundBrush(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundBrush"
,"getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundBrush::*)()const>(&cocos2d::CameraBackgroundBrush::getBrushType)
,"drawBackground",static_cast<void(cocos2d::CameraBackgroundBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundBrush::drawBackground)
,"isValid",static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::isValid)
,"init",static_cast<bool(cocos2d::CameraBackgroundBrush::*)()>(&cocos2d::CameraBackgroundBrush::init)
,"createNoneBrush",static_cast<cocos2d::CameraBackgroundBrush*(*)()>(&cocos2d::CameraBackgroundBrush::createNoneBrush)
,"createDepthBrush",sol::overload([](cocos2d::CameraBackgroundBrush* obj){return obj->createDepthBrush();},[](cocos2d::CameraBackgroundBrush* obj,float arg0){return obj->createDepthBrush(arg0);})
,"createColorBrush",static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundBrush::createColorBrush)
,"createSkyboxBrush",static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundBrush::createSkyboxBrush)
);}
static void RegisterLuaCameraBackgroundDepthBrush(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundDepthBrush"
,"getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundDepthBrush::*)()const>(&cocos2d::CameraBackgroundDepthBrush::getBrushType)
,"drawBackground",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundDepthBrush::drawBackground)
,"setDepth",static_cast<void(cocos2d::CameraBackgroundDepthBrush::*)(float)>(&cocos2d::CameraBackgroundDepthBrush::setDepth)
,"init",static_cast<bool(cocos2d::CameraBackgroundDepthBrush::*)()>(&cocos2d::CameraBackgroundDepthBrush::init)
,"new",static_cast<cocos2d::CameraBackgroundDepthBrush*(*)(float)>(&cocos2d::CameraBackgroundDepthBrush::create)
);}
static void RegisterLuaCameraBackgroundColorBrush(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CameraBackgroundColorBrush,cocos2d::CameraBackgroundDepthBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundColorBrush"
,"getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundColorBrush::*)()const>(&cocos2d::CameraBackgroundColorBrush::getBrushType)
,"drawBackground",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundColorBrush::drawBackground)
,"setColor",static_cast<void(cocos2d::CameraBackgroundColorBrush::*)(const cocos2d::Color4F&)>(&cocos2d::CameraBackgroundColorBrush::setColor)
,"init",static_cast<bool(cocos2d::CameraBackgroundColorBrush::*)()>(&cocos2d::CameraBackgroundColorBrush::init)
,"new",static_cast<cocos2d::CameraBackgroundColorBrush*(*)(const cocos2d::Color4F&,float)>(&cocos2d::CameraBackgroundColorBrush::create)
);}
static void RegisterLuaCameraBackgroundSkyBoxBrush(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::CameraBackgroundSkyBoxBrush,cocos2d::CameraBackgroundBrush,cocos2d::Ref,cocos2d::LuaObject>("cc","CameraBackgroundSkyBoxBrush"
,"getBrushType",static_cast<cocos2d::CameraBackgroundBrush::BrushType(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getBrushType)
,"setTexture",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::TextureCube*)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTexture)
,"getTexture",static_cast<cocos2d::TextureCube*(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::getTexture)
,"drawBackground",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(cocos2d::Camera*)>(&cocos2d::CameraBackgroundSkyBoxBrush::drawBackground)
,"isActived",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()const>(&cocos2d::CameraBackgroundSkyBoxBrush::isActived)
,"setActived",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setActived)
,"setTextureValid",static_cast<void(cocos2d::CameraBackgroundSkyBoxBrush::*)(bool)>(&cocos2d::CameraBackgroundSkyBoxBrush::setTextureValid)
,"isValid",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::isValid)
,"init",static_cast<bool(cocos2d::CameraBackgroundSkyBoxBrush::*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::init)
,"new",sol::overload(static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)()>(&cocos2d::CameraBackgroundSkyBoxBrush::create),static_cast<cocos2d::CameraBackgroundSkyBoxBrush*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::CameraBackgroundSkyBoxBrush::create))
);}
static void RegisterLuaGridBase(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>("cc","GridBase"
,"beforeBlit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeBlit)
,"afterBlit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::afterBlit)
,"blit",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::blit)
,"reuse",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::reuse)
,"calculateVertexPoints",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::calculateVertexPoints)
,"initWithSize",sol::overload(static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::GridBase::initWithSize),static_cast<bool(cocos2d::GridBase::*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::GridBase::initWithSize))
,"isActive",static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isActive)
,"setActive",static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setActive)
,"getReuseGrid",static_cast<int(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getReuseGrid)
,"setReuseGrid",static_cast<void(cocos2d::GridBase::*)(int)>(&cocos2d::GridBase::setReuseGrid)
,"getGridSize",static_cast<const cocos2d::Size&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridSize)
,"setGridSize",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Size&)>(&cocos2d::GridBase::setGridSize)
,"getStep",static_cast<const cocos2d::Vec2&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getStep)
,"setStep",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Vec2&)>(&cocos2d::GridBase::setStep)
,"isTextureFlipped",static_cast<bool(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::isTextureFlipped)
,"setTextureFlipped",static_cast<void(cocos2d::GridBase::*)(bool)>(&cocos2d::GridBase::setTextureFlipped)
,"beforeDraw",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::beforeDraw)
,"afterDraw",static_cast<void(cocos2d::GridBase::*)(cocos2d::Node*)>(&cocos2d::GridBase::afterDraw)
,"set2DProjection",static_cast<void(cocos2d::GridBase::*)()>(&cocos2d::GridBase::set2DProjection)
,"setGridRect",static_cast<void(cocos2d::GridBase::*)(const cocos2d::Rect&)>(&cocos2d::GridBase::setGridRect)
,"getGridRect",static_cast<const cocos2d::Rect&(cocos2d::GridBase::*)()const>(&cocos2d::GridBase::getGridRect)
);}
static void RegisterLuaGrid3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Grid3D,cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>("cc","Grid3D"
,"beforeBlit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::beforeBlit)
,"afterBlit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::afterBlit)
,"blit",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::blit)
,"reuse",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::reuse)
,"calculateVertexPoints",static_cast<void(cocos2d::Grid3D::*)()>(&cocos2d::Grid3D::calculateVertexPoints)
,"setNeedDepthTestForBlit",static_cast<void(cocos2d::Grid3D::*)(bool)>(&cocos2d::Grid3D::setNeedDepthTestForBlit)
,"getNeedDepthTestForBlit",static_cast<bool(cocos2d::Grid3D::*)()const>(&cocos2d::Grid3D::getNeedDepthTestForBlit)
,"new",sol::overload(static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::Grid3D::create),static_cast<cocos2d::Grid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::Grid3D::create))
);}
static void RegisterLuaTiledGrid3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TiledGrid3D,cocos2d::GridBase,cocos2d::Ref,cocos2d::LuaObject>("cc","TiledGrid3D"
,"blit",static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::blit)
,"reuse",static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::reuse)
,"calculateVertexPoints",static_cast<void(cocos2d::TiledGrid3D::*)()>(&cocos2d::TiledGrid3D::calculateVertexPoints)
,"new",sol::overload(static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool)>(&cocos2d::TiledGrid3D::create),static_cast<cocos2d::TiledGrid3D*(*)(const cocos2d::Size&,cocos2d::Texture2D*,bool,const cocos2d::Rect&)>(&cocos2d::TiledGrid3D::create))
);}
static void RegisterLuaBaseLight(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","BaseLight"
,"getLightType",static_cast<cocos2d::LightType(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightType)
,"getIntensity",static_cast<float(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getIntensity)
,"setIntensity",static_cast<void(cocos2d::BaseLight::*)(float)>(&cocos2d::BaseLight::setIntensity)
,"getLightFlag",static_cast<cocos2d::LightFlag(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::getLightFlag)
,"setLightFlag",static_cast<void(cocos2d::BaseLight::*)(cocos2d::LightFlag)>(&cocos2d::BaseLight::setLightFlag)
,"setEnabled",static_cast<void(cocos2d::BaseLight::*)(bool)>(&cocos2d::BaseLight::setEnabled)
,"isEnabled",static_cast<bool(cocos2d::BaseLight::*)()const>(&cocos2d::BaseLight::isEnabled)
);}
static void RegisterLuaDirectionLight(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::DirectionLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","DirectionLight"
,"getLightType",static_cast<cocos2d::LightType(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getLightType)
,"setDirection",static_cast<void(cocos2d::DirectionLight::*)(const cocos2d::Vec3&)>(&cocos2d::DirectionLight::setDirection)
,"getDirection",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirection)
,"getDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::DirectionLight::*)()const>(&cocos2d::DirectionLight::getDirectionInWorld)
,"new",static_cast<cocos2d::DirectionLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&)>(&cocos2d::DirectionLight::create)
);}
static void RegisterLuaPointLight(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::PointLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","PointLight"
,"getLightType",static_cast<cocos2d::LightType(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getLightType)
,"getRange",static_cast<float(cocos2d::PointLight::*)()const>(&cocos2d::PointLight::getRange)
,"setRange",static_cast<void(cocos2d::PointLight::*)(float)>(&cocos2d::PointLight::setRange)
,"new",static_cast<cocos2d::PointLight*(*)(const cocos2d::Vec3&,const cocos2d::Color3B&,float)>(&cocos2d::PointLight::create)
);}
static void RegisterLuaSpotLight(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SpotLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","SpotLight"
,"getLightType",static_cast<cocos2d::LightType(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getLightType)
,"setDirection",static_cast<void(cocos2d::SpotLight::*)(const cocos2d::Vec3&)>(&cocos2d::SpotLight::setDirection)
,"getDirection",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirection)
,"getDirectionInWorld",static_cast<cocos2d::Vec3(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getDirectionInWorld)
,"setRange",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setRange)
,"getRange",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getRange)
,"setInnerAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setInnerAngle)
,"getInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getInnerAngle)
,"getCosInnerAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosInnerAngle)
,"setOuterAngle",static_cast<void(cocos2d::SpotLight::*)(float)>(&cocos2d::SpotLight::setOuterAngle)
,"getOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getOuterAngle)
,"getCosOuterAngle",static_cast<float(cocos2d::SpotLight::*)()const>(&cocos2d::SpotLight::getCosOuterAngle)
,"new",static_cast<cocos2d::SpotLight*(*)(const cocos2d::Vec3&,const cocos2d::Vec3&,const cocos2d::Color3B&,float,float,float)>(&cocos2d::SpotLight::create)
);}
static void RegisterLuaAmbientLight(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AmbientLight,cocos2d::BaseLight,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","AmbientLight"
,"getLightType",static_cast<cocos2d::LightType(cocos2d::AmbientLight::*)()const>(&cocos2d::AmbientLight::getLightType)
,"new",static_cast<cocos2d::AmbientLight*(*)(const cocos2d::Color3B&)>(&cocos2d::AmbientLight::create)
);}
static void RegisterLuaRenderState(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::RenderState,cocos2d::Ref,cocos2d::LuaObject>("cc","RenderState"
,"getName",static_cast<std::string(cocos2d::RenderState::*)()const>(&cocos2d::RenderState::getName)
,"bindPass",static_cast<void(cocos2d::RenderState::*)(cocos2d::Pass*,cocos2d::MeshCommand*)>(&cocos2d::RenderState::bindPass)
);}
static void RegisterLuaTechnique(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Technique,cocos2d::Ref,cocos2d::LuaObject>("cc","Technique"
,"addPass",static_cast<void(cocos2d::Technique::*)(cocos2d::Pass*)>(&cocos2d::Technique::addPass)
,"getName",static_cast<std::string(cocos2d::Technique::*)()const>(&cocos2d::Technique::getName)
,"getPassByIndex",static_cast<cocos2d::Pass*(cocos2d::Technique::*)(ssize_t)const>(&cocos2d::Technique::getPassByIndex)
,"getPassCount",static_cast<ssize_t(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPassCount)
,"getPasses",static_cast<const cocos2d::Vector<cocos2d::Pass *>&(cocos2d::Technique::*)()const>(&cocos2d::Technique::getPasses)
,"clone",static_cast<cocos2d::Technique*(cocos2d::Technique::*)()const>(&cocos2d::Technique::clone)
,"setMaterial",static_cast<void(cocos2d::Technique::*)(cocos2d::Material*)>(&cocos2d::Technique::setMaterial)
,"createWithProgramState",static_cast<cocos2d::Technique*(*)(cocos2d::Material*,cocos2d::backend::ProgramState*)>(&cocos2d::Technique::createWithProgramState)
,"new",static_cast<cocos2d::Technique*(*)(cocos2d::Material*)>(&cocos2d::Technique::create)
);}
static void RegisterLuaMaterial(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Material,cocos2d::Ref,cocos2d::LuaObject>("cc","Material"
,"draw",static_cast<void(cocos2d::Material::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::CustomCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Material::draw)
,"getName",static_cast<std::string(cocos2d::Material::*)()const>(&cocos2d::Material::getName)
,"setName",static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setName)
,"getTechniqueByName",static_cast<cocos2d::Technique*(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::getTechniqueByName)
,"getTechniqueByIndex",static_cast<cocos2d::Technique*(cocos2d::Material::*)(ssize_t)>(&cocos2d::Material::getTechniqueByIndex)
,"getTechnique",static_cast<cocos2d::Technique*(cocos2d::Material::*)()const>(&cocos2d::Material::getTechnique)
,"getTechniques",static_cast<const cocos2d::Vector<cocos2d::Technique *>&(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniques)
,"getTechniqueCount",static_cast<ssize_t(cocos2d::Material::*)()const>(&cocos2d::Material::getTechniqueCount)
,"addTechnique",static_cast<void(cocos2d::Material::*)(cocos2d::Technique*)>(&cocos2d::Material::addTechnique)
,"setTechnique",static_cast<void(cocos2d::Material::*)(const std::string&)>(&cocos2d::Material::setTechnique)
,"clone",static_cast<cocos2d::Material*(cocos2d::Material::*)()const>(&cocos2d::Material::clone)
,"getRenderState",static_cast<cocos2d::RenderState*(cocos2d::Material::*)()>(&cocos2d::Material::getRenderState)
,"createWithFilename",static_cast<cocos2d::Material*(*)(const std::string&)>(&cocos2d::Material::createWithFilename)
,"createWithProgramState",static_cast<cocos2d::Material*(*)(cocos2d::backend::ProgramState*)>(&cocos2d::Material::createWithProgramState)
,"createWithProperties",static_cast<cocos2d::Material*(*)(cocos2d::Properties*)>(&cocos2d::Material::createWithProperties)
);}
static void RegisterLuaPass(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Pass,cocos2d::Ref,cocos2d::LuaObject>("cc","Pass"
,"getProgramState",static_cast<cocos2d::backend::ProgramState*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getProgramState)
,"draw",static_cast<void(cocos2d::Pass::*)(cocos2d::MeshCommand*,float,cocos2d::backend::Buffer*,cocos2d::backend::Buffer*,cocos2d::CustomCommand::PrimitiveType,cocos2d::MeshCommand::IndexFormat,unsigned int,const cocos2d::Mat4&)>(&cocos2d::Pass::draw)
,"setVertexAttribBinding",static_cast<void(cocos2d::Pass::*)(cocos2d::VertexAttribBinding*)>(&cocos2d::Pass::setVertexAttribBinding)
,"getVertexAttributeBinding",static_cast<cocos2d::VertexAttribBinding*(cocos2d::Pass::*)()const>(&cocos2d::Pass::getVertexAttributeBinding)
,"setName",static_cast<void(cocos2d::Pass::*)(const std::string&)>(&cocos2d::Pass::setName)
,"getName",static_cast<const std::string&(cocos2d::Pass::*)()const>(&cocos2d::Pass::getName)
,"clone",static_cast<cocos2d::Pass*(cocos2d::Pass::*)()const>(&cocos2d::Pass::clone)
,"setTechnique",static_cast<void(cocos2d::Pass::*)(cocos2d::Technique*)>(&cocos2d::Pass::setTechnique)
,"updateMVPUniform",static_cast<void(cocos2d::Pass::*)(const cocos2d::Mat4&)>(&cocos2d::Pass::updateMVPUniform)
,"setUniformTexture",static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformTexture)
,"setUniformNormTexture",static_cast<void(cocos2d::Pass::*)(uint32_t,cocos2d::backend::TextureBackend*)>(&cocos2d::Pass::setUniformNormTexture)
,"setUniformColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformColor)
,"setUniformMatrixPalette",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformMatrixPalette)
,"setUniformDirLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightColor)
,"setUniformDirLightDir",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformDirLightDir)
,"setUniformPointLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightColor)
,"setUniformPointLightPosition",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightPosition)
,"setUniformPointLightRangeInverse",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformPointLightRangeInverse)
,"setUniformSpotLightColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightColor)
,"setUniformSpotLightPosition",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightPosition)
,"setUniformSpotLightDir",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightDir)
,"setUniformSpotLightInnerAngleCos",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightInnerAngleCos)
,"setUniformSpotLightOuterAngleCos",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightOuterAngleCos)
,"setUniformSpotLightRangeInverse",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformSpotLightRangeInverse)
,"setUniformAmbientLigthColor",static_cast<void(cocos2d::Pass::*)(const void*,size_t)>(&cocos2d::Pass::setUniformAmbientLigthColor)
,"createWithProgramState",static_cast<cocos2d::Pass*(*)(cocos2d::Technique*,cocos2d::backend::ProgramState*)>(&cocos2d::Pass::createWithProgramState)
,"new",static_cast<cocos2d::Pass*(*)(cocos2d::Technique*)>(&cocos2d::Pass::create)
);}
static void RegisterLuaRenderer(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Renderer>("cc","Renderer"
,"init",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::init)
,"addCommand",sol::overload(static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*,int)>(&cocos2d::Renderer::addCommand),static_cast<void(cocos2d::Renderer::*)(cocos2d::RenderCommand*)>(&cocos2d::Renderer::addCommand))
,"pushGroup",static_cast<void(cocos2d::Renderer::*)(int)>(&cocos2d::Renderer::pushGroup)
,"popGroup",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::popGroup)
,"createRenderQueue",static_cast<int(cocos2d::Renderer::*)()>(&cocos2d::Renderer::createRenderQueue)
,"render",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::render)
,"clean",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clean)
,"getDrawnBatches",static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnBatches)
,"addDrawnBatches",static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnBatches)
,"getDrawnVertices",static_cast<ssize_t(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDrawnVertices)
,"addDrawnVertices",static_cast<void(cocos2d::Renderer::*)(ssize_t)>(&cocos2d::Renderer::addDrawnVertices)
,"clearDrawStats",static_cast<void(cocos2d::Renderer::*)()>(&cocos2d::Renderer::clearDrawStats)
,"getRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTarget)
,"setRenderTarget",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*)>(&cocos2d::Renderer::setRenderTarget)
,"getDefaultRenderTarget",static_cast<cocos2d::backend::RenderTarget*(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDefaultRenderTarget)
,"clear",static_cast<void(cocos2d::Renderer::*)(cocos2d::ClearFlag,const cocos2d::Color4F&,float,unsigned int,float)>(&cocos2d::Renderer::clear)
,"getClearColor",static_cast<const cocos2d::Color4F&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearColor)
,"getClearDepth",static_cast<float(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearDepth)
,"getClearStencil",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearStencil)
,"getClearFlag",static_cast<cocos2d::ClearFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getClearFlag)
,"getRenderTargetFlag",static_cast<cocos2d::RenderTargetFlag(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getRenderTargetFlag)
,"setDepthTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthTest)
,"setDepthWrite",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setDepthWrite)
,"setDepthCompareFunction",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction)>(&cocos2d::Renderer::setDepthCompareFunction)
,"getDepthTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthTest)
,"getDepthWrite",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthWrite)
,"getDepthCompareFunction",static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthCompareFunction)
,"setStencilTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setStencilTest)
,"setStencilCompareFunction",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::CompareFunction,unsigned int,unsigned int)>(&cocos2d::Renderer::setStencilCompareFunction)
,"setStencilOperation",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation,cocos2d::backend::StencilOperation)>(&cocos2d::Renderer::setStencilOperation)
,"setStencilWriteMask",static_cast<void(cocos2d::Renderer::*)(unsigned int)>(&cocos2d::Renderer::setStencilWriteMask)
,"getStencilTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilTest)
,"getStencilFailureOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilFailureOperation)
,"getStencilPassDepthFailureOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilPassDepthFailureOperation)
,"getStencilDepthPassOperation",static_cast<cocos2d::backend::StencilOperation(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilDepthPassOperation)
,"getStencilCompareFunction",static_cast<cocos2d::backend::CompareFunction(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilCompareFunction)
,"getStencilReadMask",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReadMask)
,"getStencilWriteMask",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilWriteMask)
,"getStencilReferenceValue",static_cast<unsigned int(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getStencilReferenceValue)
,"setDepthStencilDesc",static_cast<void(cocos2d::Renderer::*)(const cocos2d::backend::DepthStencilDescriptor&)>(&cocos2d::Renderer::setDepthStencilDesc)
,"getDepthStencilDesc",static_cast<const cocos2d::backend::DepthStencilDescriptor&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getDepthStencilDesc)
,"setCullMode",static_cast<void(cocos2d::Renderer::*)(cocos2d::CullMode)>(&cocos2d::Renderer::setCullMode)
,"getCullMode",static_cast<cocos2d::CullMode(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getCullMode)
,"setWinding",static_cast<void(cocos2d::Renderer::*)(cocos2d::Winding)>(&cocos2d::Renderer::setWinding)
,"getWinding",static_cast<cocos2d::Winding(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getWinding)
,"setViewPort",static_cast<void(cocos2d::Renderer::*)(int,int,unsigned int,unsigned int)>(&cocos2d::Renderer::setViewPort)
,"getViewport",static_cast<const cocos2d::Viewport&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getViewport)
,"setScissorTest",static_cast<void(cocos2d::Renderer::*)(bool)>(&cocos2d::Renderer::setScissorTest)
,"setScissorRect",static_cast<void(cocos2d::Renderer::*)(float,float,float,float)>(&cocos2d::Renderer::setScissorRect)
,"getScissorTest",static_cast<bool(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorTest)
,"getScissorRect",static_cast<const cocos2d::ScissorRect&(cocos2d::Renderer::*)()const>(&cocos2d::Renderer::getScissorRect)
,"checkVisibility",static_cast<bool(cocos2d::Renderer::*)(const cocos2d::Mat4&,const cocos2d::Size&)>(&cocos2d::Renderer::checkVisibility)
,"readPixels",static_cast<void(cocos2d::Renderer::*)(cocos2d::backend::RenderTarget*,std::function<void (const cocos2d::backend::PixelBufferDescriptor &)>)>(&cocos2d::Renderer::readPixels)
);}
static void RegisterLuaTextureCache(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TextureCache,cocos2d::Ref,cocos2d::LuaObject>("cc","TextureCache"
,"getDescription",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getDescription)
,"addImage",sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(cocos2d::Image*,const std::string&)>(&cocos2d::TextureCache::addImage),static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::addImage))
,"unbindImageAsync",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::unbindImageAsync)
,"unbindAllImageAsync",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::unbindAllImageAsync)
,"getTextureForKey",static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)const>(&cocos2d::TextureCache::getTextureForKey)
,"reloadTexture",static_cast<bool(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::reloadTexture)
,"removeAllTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeAllTextures)
,"removeUnusedTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeUnusedTextures)
,"removeTexture",static_cast<void(cocos2d::TextureCache::*)(cocos2d::Texture2D*)>(&cocos2d::TextureCache::removeTexture)
,"removeTextureForKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::removeTextureForKey)
,"getCachedTextureInfo",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getCachedTextureInfo)
,"waitForQuit",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::waitForQuit)
,"getTextureFilePath",static_cast<std::string(cocos2d::TextureCache::*)(cocos2d::Texture2D*)const>(&cocos2d::TextureCache::getTextureFilePath)
,"renameTextureWithKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::string&)>(&cocos2d::TextureCache::renameTextureWithKey)
,"setETC1AlphaFileSuffix",static_cast<void(*)(const std::string&)>(&cocos2d::TextureCache::setETC1AlphaFileSuffix)
,"getETC1AlphaFileSuffix",static_cast<std::string(*)()>(&cocos2d::TextureCache::getETC1AlphaFileSuffix)
);}
static void RegisterLuaDevice(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Device>("cc","Device"
,"getDPI",static_cast<int(*)()>(&cocos2d::Device::getDPI)
,"setAccelerometerEnabled",static_cast<void(*)(bool)>(&cocos2d::Device::setAccelerometerEnabled)
,"setAccelerometerInterval",static_cast<void(*)(float)>(&cocos2d::Device::setAccelerometerInterval)
,"setKeepScreenOn",static_cast<void(*)(bool)>(&cocos2d::Device::setKeepScreenOn)
,"vibrate",static_cast<void(*)(float)>(&cocos2d::Device::vibrate)
);}
static void RegisterLuaApplication(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::Application>("cc","Application"
,"setAnimationInterval",static_cast<void(cocos2d::Application::*)(float)>(&cocos2d::Application::setAnimationInterval)
,"getCurrentLanguage",static_cast<cocos2d::LanguageType(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguage)
,"getCurrentLanguageCode",static_cast<const char*(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguageCode)
,"getTargetPlatform",static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::Application::*)()>(&cocos2d::Application::getTargetPlatform)
,"getVersion",static_cast<std::string(cocos2d::Application::*)()>(&cocos2d::Application::getVersion)
,"GetCompileVersion",static_cast<int64_t(cocos2d::Application::*)()>(&cocos2d::Application::GetCompileVersion)
,"openURL",static_cast<bool(cocos2d::Application::*)(const std::string&)>(&cocos2d::Application::openURL)
,"getInstance",static_cast<cocos2d::Application*(*)()>(&cocos2d::Application::getInstance)
);}
static void RegisterLuaGLViewImpl(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::GLViewImpl,cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>("cc","GLViewImpl"
,"isOpenGLReady",static_cast<bool(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::isOpenGLReady)
,"setIMEKeyboardState",static_cast<void(cocos2d::GLViewImpl::*)(bool)>(&cocos2d::GLViewImpl::setIMEKeyboardState)
,"getSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::GLViewImpl::*)()const>(&cocos2d::GLViewImpl::getSafeAreaRect)
,"new",static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::create)
,"createWithRect",sol::overload([](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1){return obj->createWithRect(arg0,arg1);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2){return obj->createWithRect(arg0,arg1,arg2);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2,bool arg3){return obj->createWithRect(arg0,arg1,arg2,arg3);})
,"createWithFullScreen",static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::createWithFullScreen)
);}
static void RegisterLuaAnimationCache(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::AnimationCache,cocos2d::Ref,cocos2d::LuaObject>("cc","AnimationCache"
,"init",static_cast<bool(cocos2d::AnimationCache::*)()>(&cocos2d::AnimationCache::init)
,"addAnimation",static_cast<void(cocos2d::AnimationCache::*)(cocos2d::Animation*,const std::string&)>(&cocos2d::AnimationCache::addAnimation)
,"removeAnimation",static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::removeAnimation)
,"getAnimation",static_cast<cocos2d::Animation*(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::getAnimation)
,"addAnimationsWithDictionary",static_cast<void(cocos2d::AnimationCache::*)(const cocos2d::ValueMap&,const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithDictionary)
,"addAnimations",static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithFile)
,"getInstance",static_cast<cocos2d::AnimationCache*(*)()>(&cocos2d::AnimationCache::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::AnimationCache::destroyInstance)
);}
static void RegisterLuaSpriteBatchNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SpriteBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","SpriteBatchNode"
,"getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::getTextureAtlas)
,"setTextureAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::SpriteBatchNode::setTextureAtlas)
,"increaseAtlasCapacity",static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::increaseAtlasCapacity)
,"removeChildAtIndex",static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t,bool)>(&cocos2d::SpriteBatchNode::removeChildAtIndex)
,"appendChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::appendChild)
,"removeSpriteFromAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::removeSpriteFromAtlas)
,"rebuildIndexInOrder",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::rebuildIndexInOrder)
,"highestAtlasIndexInChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::highestAtlasIndexInChild)
,"lowestAtlasIndexInChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::lowestAtlasIndexInChild)
,"atlasIndexForChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int)>(&cocos2d::SpriteBatchNode::atlasIndexForChild)
,"reorderBatch",static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::reorderBatch)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getTexture)
,"setTexture",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteBatchNode::setTexture)
,"setBlendFunc",static_cast<void(cocos2d::SpriteBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::SpriteBatchNode::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getBlendFunc)
,"visit",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::visit)
,"addChild",sol::overload(static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::SpriteBatchNode::addChild),static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::SpriteBatchNode::addChild))
,"reorderChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::SpriteBatchNode::reorderChild)
,"removeChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::SpriteBatchNode::removeChild)
,"removeAllChildrenWithCleanup",static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::removeAllChildrenWithCleanup)
,"sortAllChildren",static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::sortAllChildren)
,"draw",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::draw)
,"getDescription",static_cast<std::string(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescription)
,"setProgramState",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);})
,"insertQuadFromSprite",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::insertQuadFromSprite)
,"addSpriteWithoutQuad",static_cast<cocos2d::SpriteBatchNode*(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int,int)>(&cocos2d::SpriteBatchNode::addSpriteWithoutQuad)
,"reserveCapacity",static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t)>(&cocos2d::SpriteBatchNode::reserveCapacity)
,"initWithTexture",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->initWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->initWithTexture(arg0,arg1);})
,"initWithFile",sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->initWithFile(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->initWithFile(arg0,arg1);})
,"init",static_cast<bool(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::init)
,"createWithTexture",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->createWithTexture(arg0,arg1);})
,"new",sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->create(arg0,arg1);})
);}
static void RegisterLuaSpriteFrameCache(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::SpriteFrameCache,cocos2d::Ref,cocos2d::LuaObject>("cc","SpriteFrameCache"
,"init",static_cast<bool(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::init)
,"addSpriteFrames",sol::overload(static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile))
,"addSpriteFramesWithFileContent",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFileContent)
,"addSpriteFrame",static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::SpriteFrame*,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFrame)
,"isSpriteFramesWithFileLoaded",static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)const>(&cocos2d::SpriteFrameCache::isSpriteFramesWithFileLoaded)
,"removeSpriteFrames",static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeSpriteFrames)
,"removeUnusedSpriteFrames",static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeUnusedSpriteFrames)
,"removeSpriteFrameByName",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFrameByName)
,"removeSpriteFramesFromFile",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFile)
,"removeSpriteFramesFromFileContent",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFileContent)
,"removeSpriteFramesFromTexture",static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromTexture)
,"getSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::getSpriteFrameByName)
,"reloadTexture",static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::reloadTexture)
,"getInstance",static_cast<cocos2d::SpriteFrameCache*(*)()>(&cocos2d::SpriteFrameCache::getInstance)
,"destroyInstance",static_cast<void(*)()>(&cocos2d::SpriteFrameCache::destroyInstance)
);}
static void RegisterLuaParallaxNode(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ParallaxNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ParallaxNode"
,"addChild",sol::overload(static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParallaxNode::addChild))
,"removeChild",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParallaxNode::removeChild)
,"removeAllChildrenWithCleanup",static_cast<void(cocos2d::ParallaxNode::*)(bool)>(&cocos2d::ParallaxNode::removeAllChildrenWithCleanup)
,"visit",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParallaxNode::visit)
,"new",static_cast<cocos2d::ParallaxNode*(*)()>(&cocos2d::ParallaxNode::create)
);}
static void RegisterLuaTMXObjectGroup(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TMXObjectGroup,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXObjectGroup"
,"getGroupName",static_cast<const std::string&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getGroupName)
,"setGroupName",static_cast<void(cocos2d::TMXObjectGroup::*)(const std::string&)>(&cocos2d::TMXObjectGroup::setGroupName)
,"getProperty",static_cast<cocos2d::Value(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getProperty)
,"getObject",static_cast<cocos2d::ValueMap(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getObject)
,"getPositionOffset",static_cast<const cocos2d::Vec2&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getPositionOffset)
,"setPositionOffset",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::Vec2&)>(&cocos2d::TMXObjectGroup::setPositionOffset)
,"getProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getProperties))
,"setProperties",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXObjectGroup::setProperties)
,"getObjects",sol::overload(static_cast<cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getObjects),static_cast<const cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getObjects))
,"setObjects",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueVector&)>(&cocos2d::TMXObjectGroup::setObjects)
);}
static void RegisterLuaTMXLayerInfo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TMXLayerInfo,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXLayerInfo"
,"setProperties",static_cast<void(cocos2d::TMXLayerInfo::*)(cocos2d::ValueMap)>(&cocos2d::TMXLayerInfo::setProperties)
,"getProperties",static_cast<cocos2d::ValueMap&(cocos2d::TMXLayerInfo::*)()>(&cocos2d::TMXLayerInfo::getProperties)
);}
static void RegisterLuaTMXTilesetInfo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TMXTilesetInfo,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTilesetInfo"
,"getRectForGID",static_cast<cocos2d::Rect(cocos2d::TMXTilesetInfo::*)(uint32_t)>(&cocos2d::TMXTilesetInfo::getRectForGID)
);}
static void RegisterLuaTMXMapInfo(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TMXMapInfo>("cc","TMXMapInfo"
,"initWithTMXFile",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::initWithTMXFile)
,"initWithXML",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::initWithXML)
,"parseXMLFile",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLFile)
,"parseXMLString",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLString)
,"getTileProperties",static_cast<cocos2d::ValueMapIntKey&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTileProperties)
,"setTileProperties",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMapIntKey&)>(&cocos2d::TMXMapInfo::setTileProperties)
,"getOrientation",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getOrientation)
,"setOrientation",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setOrientation)
,"getStaggerAxis",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerAxis)
,"setStaggerAxis",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerAxis)
,"getStaggerIndex",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerIndex)
,"setStaggerIndex",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerIndex)
,"getHexSideLength",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getHexSideLength)
,"setHexSideLength",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setHexSideLength)
,"getMapSize",static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getMapSize)
,"setMapSize",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setMapSize)
,"getTileSize",static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTileSize)
,"setTileSize",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setTileSize)
,"getLayers",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getLayers),static_cast<const cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayers))
,"setLayers",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXLayerInfo *>&)>(&cocos2d::TMXMapInfo::setLayers)
,"getTilesets",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTilesets),static_cast<const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTilesets))
,"setTilesets",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&)>(&cocos2d::TMXMapInfo::setTilesets)
,"getObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getObjectGroups))
,"setObjectGroups",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::TMXMapInfo::setObjectGroups)
,"getParentElement",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentElement)
,"setParentElement",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentElement)
,"getParentGID",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentGID)
,"setParentGID",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentGID)
,"getLayerAttribs",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayerAttribs)
,"setLayerAttribs",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setLayerAttribs)
,"isStoringCharacters",static_cast<bool(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::isStoringCharacters)
,"setStoringCharacters",static_cast<void(cocos2d::TMXMapInfo::*)(bool)>(&cocos2d::TMXMapInfo::setStoringCharacters)
,"getProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getProperties))
,"setProperties",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXMapInfo::setProperties)
,"getCurrentString",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getCurrentString)
,"setCurrentString",static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setCurrentString)
,"getTMXFileName",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTMXFileName)
,"setTMXFileName",static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setTMXFileName)
,"getExternalTilesetFileName",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getExternalTilesetFileName)
,"new",static_cast<cocos2d::TMXMapInfo*(*)(const std::string&)>(&cocos2d::TMXMapInfo::create)
,"createWithXML",static_cast<cocos2d::TMXMapInfo*(*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::createWithXML)
);}
static void RegisterLuaTileMapAtlas(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TileMapAtlas,cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","TileMapAtlas"
,"initWithTileFile",static_cast<bool(cocos2d::TileMapAtlas::*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::initWithTileFile)
,"getTileAt",static_cast<cocos2d::Color3B(cocos2d::TileMapAtlas::*)(const cocos2d::Vec2&)const>(&cocos2d::TileMapAtlas::getTileAt)
,"setTile",static_cast<void(cocos2d::TileMapAtlas::*)(const cocos2d::Color3B&,const cocos2d::Vec2&)>(&cocos2d::TileMapAtlas::setTile)
,"releaseMap",static_cast<void(cocos2d::TileMapAtlas::*)()>(&cocos2d::TileMapAtlas::releaseMap)
,"new",static_cast<cocos2d::TileMapAtlas*(*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::create)
);}
static void RegisterLuaFastTMXLayer(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FastTMXLayer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","FastTMXLayer"
,"setTileGID",sol::overload(static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&,cocos2d::TMXTileFlags)>(&cocos2d::FastTMXLayer::setTileGID),static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::setTileGID))
,"removeTileAt",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::removeTileAt)
,"getPositionAt",static_cast<cocos2d::Vec2(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getPositionAt)
,"getProperty",static_cast<cocos2d::Value(cocos2d::FastTMXLayer::*)(const std::string&)const>(&cocos2d::FastTMXLayer::getProperty)
,"setupTiles",static_cast<void(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::setupTiles)
,"getLayerName",static_cast<const std::string&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getLayerName)
,"setLayerName",static_cast<void(cocos2d::FastTMXLayer::*)(const std::string&)>(&cocos2d::FastTMXLayer::setLayerName)
,"getLayerSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerSize)
,"setLayerSize",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setLayerSize)
,"getMapTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getMapTileSize)
,"setMapTileSize",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setMapTileSize)
,"getTileSet",static_cast<cocos2d::TMXTilesetInfo*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileSet)
,"setTileSet",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*)>(&cocos2d::FastTMXLayer::setTileSet)
,"getLayerOrientation",static_cast<int(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerOrientation)
,"setLayerOrientation",static_cast<void(cocos2d::FastTMXLayer::*)(int)>(&cocos2d::FastTMXLayer::setLayerOrientation)
,"getProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getProperties))
,"setProperties",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXLayer::setProperties)
,"getTileAt",static_cast<cocos2d::Sprite*(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getTileAt)
,"setupTileSprite",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Sprite*,const cocos2d::Vec2&,uint32_t)>(&cocos2d::FastTMXLayer::setupTileSprite)
,"getDescription",static_cast<std::string(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getDescription)
,"draw",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::FastTMXLayer::draw)
,"removeChild",sol::overload([](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);})
,"getAnimTileCoord",static_cast<const std::unordered_map<unsigned int, std::vector<cocos2d::Vec2>>*(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getAnimTileCoord)
,"hasTileAnimation",static_cast<bool(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::hasTileAnimation)
,"getTileAnimManager",static_cast<cocos2d::TMXTileAnimManager*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileAnimManager)
,"initWithTilesetInfo",static_cast<bool(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::initWithTilesetInfo)
,"new",static_cast<cocos2d::FastTMXLayer*(*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::create)
);}
static void RegisterLuaTMXTileAnimTask(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TMXTileAnimTask,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTileAnimTask"
,"start",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::start)
,"stop",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::stop)
,"isRunning",static_cast<bool(cocos2d::TMXTileAnimTask::*)()const>(&cocos2d::TMXTileAnimTask::isRunning)
,"new",static_cast<cocos2d::TMXTileAnimTask*(*)(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>(&cocos2d::TMXTileAnimTask::create)
);}
static void RegisterLuaTMXTileAnimManager(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::TMXTileAnimManager,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTileAnimManager"
,"startAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll)
,"stopAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll)
,"getTasks",static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks)
,"new",static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create)
);}
static void RegisterLuaFastTMXTiledMap(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::FastTMXTiledMap,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","FastTMXTiledMap"
,"getLayer",static_cast<cocos2d::FastTMXLayer*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getLayer)
,"getObjectGroup",static_cast<cocos2d::TMXObjectGroup*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getObjectGroup)
,"getProperty",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getProperty)
,"getPropertiesForGID",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(int)const>(&cocos2d::FastTMXTiledMap::getPropertiesForGID)
,"getMapSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapSize)
,"setMapSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setMapSize)
,"getTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getTileSize)
,"setTileSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setTileSize)
,"getMapOrientation",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapOrientation)
,"setMapOrientation",static_cast<void(cocos2d::FastTMXTiledMap::*)(int)>(&cocos2d::FastTMXTiledMap::setMapOrientation)
,"getObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()>(&cocos2d::FastTMXTiledMap::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getObjectGroups))
,"setObjectGroups",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::FastTMXTiledMap::setObjectGroups)
,"getProperties",static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getProperties)
,"setProperties",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXTiledMap::setProperties)
,"getDescription",static_cast<std::string(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getDescription)
,"setTileAnimEnabled",static_cast<void(cocos2d::FastTMXTiledMap::*)(bool)>(&cocos2d::FastTMXTiledMap::setTileAnimEnabled)
,"getLayerCount",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getLayerCount)
,"getResourceFile",static_cast<const std::string&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getResourceFile)
,"initWithTMXFile",static_cast<bool(cocos2d::FastTMXTiledMap::*)(const std::string&)>(&cocos2d::FastTMXTiledMap::initWithTMXFile)
,"initWithXML",static_cast<bool(cocos2d::FastTMXTiledMap::*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::initWithXML)
,"new",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&)>(&cocos2d::FastTMXTiledMap::create)
,"createWithXML",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::createWithXML)
);}
static void RegisterLuaMotionStreak3D(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::MotionStreak3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","MotionStreak3D"
,"tintWithColor",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak3D::tintWithColor)
,"reset",static_cast<void(cocos2d::MotionStreak3D::*)()>(&cocos2d::MotionStreak3D::reset)
,"getStroke",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getStroke)
,"setStroke",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setStroke)
,"isStartingPositionInitialized",static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isStartingPositionInitialized)
,"setStartingPositionInitialized",static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setStartingPositionInitialized)
,"setPosition",sol::overload(static_cast<void(cocos2d::MotionStreak3D::*)(float,float)>(&cocos2d::MotionStreak3D::setPosition),static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak3D::setPosition))
,"setPosition3D",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setPosition3D)
,"setRotation3D",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setRotation3D)
,"setRotationQuat",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Quaternion&)>(&cocos2d::MotionStreak3D::setRotationQuat)
,"getPosition",sol::overload(static_cast<void(cocos2d::MotionStreak3D::*)(float*,float*)const>(&cocos2d::MotionStreak3D::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition))
,"setPositionX",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionX)
,"setPositionY",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionY)
,"getPositionX",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionX)
,"getPositionY",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionY)
,"getPosition3D",static_cast<cocos2d::Vec3(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition3D)
,"draw",static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::MotionStreak3D::draw)
,"update",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::update)
,"getTexture",static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getTexture)
,"setTexture",static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::setTexture)
,"setBlendFunc",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak3D::setBlendFunc)
,"getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getBlendFunc)
,"getOpacity",static_cast<uint8_t(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getOpacity)
,"setOpacity",static_cast<void(cocos2d::MotionStreak3D::*)(uint8_t)>(&cocos2d::MotionStreak3D::setOpacity)
,"setOpacityModifyRGB",static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setOpacityModifyRGB)
,"isOpacityModifyRGB",static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isOpacityModifyRGB)
,"setSweepAxis",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setSweepAxis)
,"getSweepAxis",static_cast<const cocos2d::Vec3&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getSweepAxis)
,"initWithFade",sol::overload(static_cast<bool(cocos2d::MotionStreak3D::*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::initWithFade),static_cast<bool(cocos2d::MotionStreak3D::*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::initWithFade))
,"new",sol::overload(static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::create),static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::create))
);}
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
