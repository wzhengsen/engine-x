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
void RegisterLuaCoreTextureCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TextureCache>("cc","TextureCache",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetETC1AlphaFileSuffix",static_cast<void(*)(const std::string&)>(&cocos2d::TextureCache::setETC1AlphaFileSuffix));
mt.set_function("GetETC1AlphaFileSuffix",static_cast<std::string(*)()>(&cocos2d::TextureCache::getETC1AlphaFileSuffix));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getDescription));
mt.set_function("AddImage",sol::overload(static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(cocos2d::Image*,const std::string&)>(&cocos2d::TextureCache::addImage),static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::addImage)));
mt.set_function("AddImageAsync",sol::overload(static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&,const std::string&)>(&cocos2d::TextureCache::addImageAsync),static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::function<void (cocos2d::Texture2D *)>&)>(&cocos2d::TextureCache::addImageAsync)));
mt.set_function("UnbindImageAsync",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::unbindImageAsync));
mt.set_function("UnbindAllImageAsync",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::unbindAllImageAsync));
mt.set_function("GetTextureForKey",static_cast<cocos2d::Texture2D*(cocos2d::TextureCache::*)(const std::string&)const>(&cocos2d::TextureCache::getTextureForKey));
mt.set_function("ReloadTexture",static_cast<bool(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::reloadTexture));
mt.set_function("RemoveAllTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeAllTextures));
mt.set_function("RemoveUnusedTextures",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::removeUnusedTextures));
mt.set_function("RemoveTexture",static_cast<void(cocos2d::TextureCache::*)(cocos2d::Texture2D*)>(&cocos2d::TextureCache::removeTexture));
mt.set_function("RemoveTextureForKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&)>(&cocos2d::TextureCache::removeTextureForKey));
mt.set_function("GetCachedTextureInfo",static_cast<std::string(cocos2d::TextureCache::*)()const>(&cocos2d::TextureCache::getCachedTextureInfo));
mt.set_function("WaitForQuit",static_cast<void(cocos2d::TextureCache::*)()>(&cocos2d::TextureCache::waitForQuit));
mt.set_function("GetTextureFilePath",static_cast<std::string(cocos2d::TextureCache::*)(cocos2d::Texture2D*)const>(&cocos2d::TextureCache::getTextureFilePath));
mt.set_function("RenameTextureWithKey",static_cast<void(cocos2d::TextureCache::*)(const std::string&,const std::string&)>(&cocos2d::TextureCache::renameTextureWithKey));
mt[sol::call_constructor]=sol::constructors<cocos2d::TextureCache()>();
}
void RegisterLuaCoreDeviceAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Device>("cc","Device",true);
mt.set_function("GetDPI",static_cast<int(*)()>(&cocos2d::Device::getDPI));
mt.set_function("SetAccelerometerEnabled",static_cast<void(*)(bool)>(&cocos2d::Device::setAccelerometerEnabled));
mt.set_function("SetAccelerometerInterval",static_cast<void(*)(float)>(&cocos2d::Device::setAccelerometerInterval));
mt.set_function("SetKeepScreenOn",static_cast<void(*)(bool)>(&cocos2d::Device::setKeepScreenOn));
mt.set_function("Vibrate",static_cast<void(*)(float)>(&cocos2d::Device::vibrate));
}
void RegisterLuaCoreApplicationProtocolPlatformAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["ApplicationProtocol"];
pTable.new_enum<cocos2d::ApplicationProtocol::Platform>("Platform",{
{"OS_WINDOWS",cocos2d::ApplicationProtocol::Platform::OS_WINDOWS}
,{"OS_LINUX",cocos2d::ApplicationProtocol::Platform::OS_LINUX}
,{"OS_MAC",cocos2d::ApplicationProtocol::Platform::OS_MAC}
,{"OS_ANDROID",cocos2d::ApplicationProtocol::Platform::OS_ANDROID}
,{"OS_IPHONE",cocos2d::ApplicationProtocol::Platform::OS_IPHONE}
,{"OS_IPAD",cocos2d::ApplicationProtocol::Platform::OS_IPAD}
});}
void RegisterLuaCoreApplicationProtocolAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ApplicationProtocol>("cc","ApplicationProtocol",true);
mt.set_function("ApplicationDidFinishLaunching",static_cast<bool(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::applicationDidFinishLaunching));
mt.set_function("ApplicationDidEnterBackground",static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::applicationDidEnterBackground));
mt.set_function("ApplicationWillEnterForeground",static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::applicationWillEnterForeground));
mt.set_function("SetAnimationInterval",static_cast<void(cocos2d::ApplicationProtocol::*)(float)>(&cocos2d::ApplicationProtocol::setAnimationInterval));
mt.set_function("InitGLContextAttrs",static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::initGLContextAttrs));
mt.set_function("GetCurrentLanguage",static_cast<cocos2d::LanguageType(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getCurrentLanguage));
mt.set_function("GetCurrentLanguageCode",static_cast<const char*(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getCurrentLanguageCode));
mt.set_function("GetTargetPlatform",static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getTargetPlatform));
mt.set_function("GetVersion",static_cast<std::string(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getVersion));
mt.set_function("GetCompileVersion",static_cast<int64_t(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::GetCompileVersion));
mt.set_function("OpenURL",static_cast<bool(cocos2d::ApplicationProtocol::*)(const std::string&)>(&cocos2d::ApplicationProtocol::openURL));
mt.set_function("RestartLuaEngine",static_cast<bool(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::RestartLuaEngine));
mt.set_function("Dialog",sol::overload([](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1){return obj->Dialog(arg0,arg1);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2){return obj->Dialog(arg0,arg1,arg2);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2,const std::function<void ()>& arg3){return obj->Dialog(arg0,arg1,arg2,arg3);}));
mt.set_function("Notify",sol::overload([](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1){return obj->Notify(arg0,arg1);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2){return obj->Notify(arg0,arg1,arg2);}));
RegisterLuaCoreApplicationProtocolPlatformAuto(lua);
}
void RegisterLuaCoreApplicationAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Application>("cc","Application",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ApplicationProtocol>());
mt.set_function("SetAnimationInterval",static_cast<void(cocos2d::Application::*)(float)>(&cocos2d::Application::setAnimationInterval));
mt.set_function("Run",static_cast<int(cocos2d::Application::*)()>(&cocos2d::Application::run));
mt.set_function("GetInstance",static_cast<cocos2d::Application*(*)()>(&cocos2d::Application::getInstance));
mt.set_function("GetCurrentLanguage",static_cast<cocos2d::LanguageType(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguage));
mt.set_function("GetCurrentLanguageCode",static_cast<const char*(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguageCode));
mt.set_function("GetTargetPlatform",static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::Application::*)()>(&cocos2d::Application::getTargetPlatform));
mt.set_function("GetVersion",static_cast<std::string(cocos2d::Application::*)()>(&cocos2d::Application::getVersion));
mt.set_function("GetCompileVersion",static_cast<int64_t(cocos2d::Application::*)()>(&cocos2d::Application::GetCompileVersion));
mt.set_function("OpenURL",static_cast<bool(cocos2d::Application::*)(const std::string&)>(&cocos2d::Application::openURL));
mt["Instance"]=sol::readonly_property(&cocos2d::Application::getInstance);
}
void RegisterLuaCoreGLViewImplAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::GLViewImpl>("cc","GLViewImpl",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::GLView,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::create));
mt.set_function("CreateWithRect",sol::overload([](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1){return obj->createWithRect(arg0,arg1);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2){return obj->createWithRect(arg0,arg1,arg2);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2,bool arg3){return obj->createWithRect(arg0,arg1,arg2,arg3);}));
mt.set_function("CreateWithFullScreen",static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::createWithFullScreen));
mt.set_function("IsOpenGLReady",static_cast<bool(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::isOpenGLReady));
mt.set_function("End",static_cast<void(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::end));
mt.set_function("SwapBuffers",static_cast<void(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::swapBuffers));
mt.set_function("SetIMEKeyboardState",static_cast<void(cocos2d::GLViewImpl::*)(bool)>(&cocos2d::GLViewImpl::setIMEKeyboardState));
mt.set_function("GetSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::GLViewImpl::*)()const>(&cocos2d::GLViewImpl::getSafeAreaRect));
}
void RegisterLuaCoreAnimationCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AnimationCache>("cc","AnimationCache",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocos2d::AnimationCache*(*)()>(&cocos2d::AnimationCache::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::AnimationCache::destroyInstance));
mt.set_function("Init",static_cast<bool(cocos2d::AnimationCache::*)()>(&cocos2d::AnimationCache::init));
mt.set_function("AddAnimation",static_cast<void(cocos2d::AnimationCache::*)(cocos2d::Animation*,const std::string&)>(&cocos2d::AnimationCache::addAnimation));
mt.set_function("RemoveAnimation",static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::removeAnimation));
mt.set_function("GetAnimation",static_cast<cocos2d::Animation*(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::getAnimation));
mt.set_function("AddAnimationsWithDictionary",static_cast<void(cocos2d::AnimationCache::*)(const cocos2d::ValueMap&,const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithDictionary));
mt.set_function("AddAnimations",static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithFile));
mt[sol::call_constructor]=sol::constructors<cocos2d::AnimationCache()>();
mt["Instance"]=sol::property(&cocos2d::AnimationCache::getInstance,[](std::nullptr_t){cocos2d::AnimationCache::destroyInstance();});
}
void RegisterLuaCoreSpriteBatchNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpriteBatchNode>("cc","SpriteBatchNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function("CreateWithTexture",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->createWithTexture(arg0,arg1);}));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->create(arg0,arg1);}));
mt.set_function("GetTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::getTextureAtlas));
mt.set_function("SetTextureAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::SpriteBatchNode::setTextureAtlas));
mt.set_function("GetDescendants",static_cast<const std::vector<cocos2d::Sprite *, std::allocator<cocos2d::Sprite *> >&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescendants));
mt.set_function("IncreaseAtlasCapacity",static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::increaseAtlasCapacity));
mt.set_function("RemoveChildAtIndex",static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t,bool)>(&cocos2d::SpriteBatchNode::removeChildAtIndex));
mt.set_function("AppendChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::appendChild));
mt.set_function("RemoveSpriteFromAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::removeSpriteFromAtlas));
mt.set_function("RebuildIndexInOrder",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::rebuildIndexInOrder));
mt.set_function("HighestAtlasIndexInChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::highestAtlasIndexInChild));
mt.set_function("LowestAtlasIndexInChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::lowestAtlasIndexInChild));
mt.set_function("AtlasIndexForChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int)>(&cocos2d::SpriteBatchNode::atlasIndexForChild));
mt.set_function("ReorderBatch",static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::reorderBatch));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getTexture));
mt.set_function("SetTexture",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteBatchNode::setTexture));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::SpriteBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::SpriteBatchNode::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getBlendFunc));
mt.set_function("Visit",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::visit));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::SpriteBatchNode::addChild),static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::SpriteBatchNode::addChild)));
mt.set_function("ReorderChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::SpriteBatchNode::reorderChild));
mt.set_function("RemoveChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::SpriteBatchNode::removeChild));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::removeAllChildrenWithCleanup));
mt.set_function("SortAllChildren",static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::sortAllChildren));
mt.set_function("Draw",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::draw));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescription));
mt.set_function("SetProgramState",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("InsertQuadFromSprite",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::insertQuadFromSprite));
mt.set_function("AddSpriteWithoutQuad",static_cast<cocos2d::SpriteBatchNode*(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int,int)>(&cocos2d::SpriteBatchNode::addSpriteWithoutQuad));
mt.set_function("ReserveCapacity",static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t)>(&cocos2d::SpriteBatchNode::reserveCapacity));
}
void RegisterLuaCoreSpriteFrameCacheAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpriteFrameCache>("cc","SpriteFrameCache",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetInstance",static_cast<cocos2d::SpriteFrameCache*(*)()>(&cocos2d::SpriteFrameCache::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::SpriteFrameCache::destroyInstance));
mt.set_function("Init",static_cast<bool(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::init));
mt.set_function("AddSpriteFrames",sol::overload(static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile)));
mt.set_function("AddSpriteFramesWithFileContent",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFileContent));
mt.set_function("AddSpriteFrame",static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::SpriteFrame*,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFrame));
mt.set_function("IsSpriteFramesWithFileLoaded",static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)const>(&cocos2d::SpriteFrameCache::isSpriteFramesWithFileLoaded));
mt.set_function("RemoveSpriteFrames",static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeSpriteFrames));
mt.set_function("RemoveUnusedSpriteFrames",static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeUnusedSpriteFrames));
mt.set_function("RemoveSpriteFrameByName",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFrameByName));
mt.set_function("RemoveSpriteFramesFromFile",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFile));
mt.set_function("RemoveSpriteFramesFromFileContent",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFileContent));
mt.set_function("RemoveSpriteFramesFromTexture",static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromTexture));
mt.set_function("GetSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::getSpriteFrameByName));
mt.set_function("ReloadTexture",static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::reloadTexture));
mt["Instance"]=sol::property(&cocos2d::SpriteFrameCache::getInstance,[](std::nullptr_t){cocos2d::SpriteFrameCache::destroyInstance();});
}
void RegisterLuaCoreParallaxNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ParallaxNode>("cc","ParallaxNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParallaxNode*(*)()>(&cocos2d::ParallaxNode::create));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParallaxNode::addChild)));
mt.set_function("RemoveChild",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParallaxNode::removeChild));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::ParallaxNode::*)(bool)>(&cocos2d::ParallaxNode::removeAllChildrenWithCleanup));
mt.set_function("Visit",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParallaxNode::visit));
}
void RegisterLuaCoreTMXObjectGroupAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXObjectGroup>("cc","TMXObjectGroup",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetGroupName",static_cast<const std::string&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getGroupName));
mt.set_function("SetGroupName",static_cast<void(cocos2d::TMXObjectGroup::*)(const std::string&)>(&cocos2d::TMXObjectGroup::setGroupName));
mt.set_function("GetProperty",static_cast<cocos2d::Value(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getProperty));
mt.set_function("GetObject",static_cast<cocos2d::ValueMap(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getObject));
mt.set_function("GetPositionOffset",static_cast<const cocos2d::Vec2&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getPositionOffset));
mt.set_function("SetPositionOffset",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::Vec2&)>(&cocos2d::TMXObjectGroup::setPositionOffset));
mt.set_function("GetProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getProperties)));
mt.set_function("SetProperties",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXObjectGroup::setProperties));
mt.set_function("GetObjects",sol::overload(static_cast<cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getObjects),static_cast<const cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getObjects)));
mt.set_function("SetObjects",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueVector&)>(&cocos2d::TMXObjectGroup::setObjects));
mt[sol::call_constructor]=sol::constructors<cocos2d::TMXObjectGroup()>();
}
