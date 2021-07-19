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
void RegisterLuaCoreDeviceTextAlignAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,9);
enumTable["CENTER"]=cocos2d::Device::TextAlign::CENTER;
enumTable["TOP"]=cocos2d::Device::TextAlign::TOP;
enumTable["TOP_RIGHT"]=cocos2d::Device::TextAlign::TOP_RIGHT;
enumTable["RIGHT"]=cocos2d::Device::TextAlign::RIGHT;
enumTable["BOTTOM_RIGHT"]=cocos2d::Device::TextAlign::BOTTOM_RIGHT;
enumTable["BOTTOM"]=cocos2d::Device::TextAlign::BOTTOM;
enumTable["BOTTOM_LEFT"]=cocos2d::Device::TextAlign::BOTTOM_LEFT;
enumTable["LEFT"]=cocos2d::Device::TextAlign::LEFT;
enumTable["TOP_LEFT"]=cocos2d::Device::TextAlign::TOP_LEFT;
lua["cc"]["Device"]["static"]["TextAlign"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreDeviceNetworkTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,4);
enumTable["None"]=cocos2d::Device::NetworkType::None;
enumTable["Wifi"]=cocos2d::Device::NetworkType::Wifi;
enumTable["Mobile"]=cocos2d::Device::NetworkType::Mobile;
enumTable["Other"]=cocos2d::Device::NetworkType::Other;
lua["cc"]["Device"]["static"]["NetworkType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreDeviceOrientationTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,3);
enumTable["Landscape"]=cocos2d::Device::OrientationType::Landscape;
enumTable["Portrait"]=cocos2d::Device::OrientationType::Portrait;
enumTable["Auto"]=cocos2d::Device::OrientationType::Auto;
lua["cc"]["Device"]["static"]["OrientationType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreDeviceAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Device).name()] = sol::usertype_traits<cocos2d::Device*>::metatable();
auto dep=lua.new_usertype<cocos2d::Device>("deprecated.cocos2d::Device");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Device*>::metatable());
lua["cc"]["Device"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetDPI"]=static_cast<int(*)()>(&cocos2d::Device::getDPI);
mt["static"]["get"]["DPI"]=mt["GetDPI"];
mt["static"]["SetAccelerometerEnabled"]=static_cast<void(*)(bool)>(&cocos2d::Device::setAccelerometerEnabled);
mt["static"]["set"]["AccelerometerEnabled"]=mt["SetAccelerometerEnabled"];
mt["static"]["SetAccelerometerInterval"]=static_cast<void(*)(float)>(&cocos2d::Device::setAccelerometerInterval);
mt["static"]["set"]["AccelerometerInterval"]=mt["SetAccelerometerInterval"];
mt["static"]["SetKeepScreenOn"]=static_cast<void(*)(bool)>(&cocos2d::Device::setKeepScreenOn);
mt["static"]["set"]["KeepScreenOn"]=mt["SetKeepScreenOn"];
mt["static"]["Vibrate"]=static_cast<void(*)(uint32_t)>(&cocos2d::Device::vibrate);
mt["static"]["GetBatteryPercent"]=static_cast<double(*)()>(&cocos2d::Device::GetBatteryPercent);
mt["static"]["get"]["BatteryPercent"]=mt["GetBatteryPercent"];
mt["static"]["IsBatteryCharge"]=static_cast<bool(*)()>(&cocos2d::Device::IsBatteryCharge);
mt["static"]["get"]["BatteryCharge"]=mt["IsBatteryCharge"];
mt["static"]["GetNetwork"]=static_cast<cocos2d::Device::NetworkType(*)()>(&cocos2d::Device::GetNetwork);
mt["static"]["get"]["Network"]=mt["GetNetwork"];
mt["static"]["GetWifiLevel"]=static_cast<uint8_t(*)()>(&cocos2d::Device::GetWifiLevel);
mt["static"]["get"]["WifiLevel"]=mt["GetWifiLevel"];
mt["static"]["SetOrientation"]=static_cast<void(*)(cocos2d::Device::OrientationType)>(&cocos2d::Device::SetOrientation);
mt["static"]["set"]["Orientation"]=mt["SetOrientation"];
mt["static"]["GetOrientation"]=static_cast<cocos2d::Device::OrientationType(*)()>(&cocos2d::Device::GetOrientation);
mt["static"]["get"]["Orientation"]=mt["GetOrientation"];
mt["static"]["IsAutoOrientation"]=static_cast<bool(*)()>(&cocos2d::Device::IsAutoOrientation);
mt["static"]["get"]["AutoOrientation"]=mt["IsAutoOrientation"];
mt["static"]["GetIp"]=static_cast<std::string(*)()>(&cocos2d::Device::GetIp);
mt["static"]["get"]["Ip"]=mt["GetIp"];
mt["static"]["GetId"]=static_cast<std::string(*)()>(&cocos2d::Device::GetId);
mt["static"]["get"]["Id"]=mt["GetId"];
RegisterLuaCoreDeviceTextAlignAuto(lua);
RegisterLuaCoreDeviceNetworkTypeAuto(lua);
RegisterLuaCoreDeviceOrientationTypeAuto(lua);
}
void RegisterLuaCoreApplicationProtocolPlatformAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,6);
enumTable["OS_WINDOWS"]=cocos2d::ApplicationProtocol::Platform::OS_WINDOWS;
enumTable["OS_LINUX"]=cocos2d::ApplicationProtocol::Platform::OS_LINUX;
enumTable["OS_MAC"]=cocos2d::ApplicationProtocol::Platform::OS_MAC;
enumTable["OS_ANDROID"]=cocos2d::ApplicationProtocol::Platform::OS_ANDROID;
enumTable["OS_IPHONE"]=cocos2d::ApplicationProtocol::Platform::OS_IPHONE;
enumTable["OS_IPAD"]=cocos2d::ApplicationProtocol::Platform::OS_IPAD;
lua["cc"]["ApplicationProtocol"]["static"]["Platform"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreApplicationProtocolAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ApplicationProtocol).name()] = sol::usertype_traits<cocos2d::ApplicationProtocol*>::metatable();
auto dep=lua.new_usertype<cocos2d::ApplicationProtocol>("deprecated.cocos2d::ApplicationProtocol");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ApplicationProtocol*>::metatable());
lua["cc"]["ApplicationProtocol"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["ApplicationDidEnterPortrait"]=static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::ApplicationDidEnterPortrait);
mt["ApplicationDidEnterLandscape"]=static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::ApplicationDidEnterLandscape);
mt["SetAnimationInterval"]=static_cast<void(cocos2d::ApplicationProtocol::*)(float)>(&cocos2d::ApplicationProtocol::setAnimationInterval);
mt["set"]["AnimationInterval"]=mt["SetAnimationInterval"];
mt["InitGLContextAttrs"]=static_cast<void(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::initGLContextAttrs);
mt["GetCurrentLanguage"]=static_cast<cocos2d::LanguageType(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getCurrentLanguage);
mt["get"]["CurrentLanguage"]=mt["GetCurrentLanguage"];
mt["GetCurrentLanguageCode"]=static_cast<const char*(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getCurrentLanguageCode);
mt["get"]["CurrentLanguageCode"]=mt["GetCurrentLanguageCode"];
mt["GetTargetPlatform"]=static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getTargetPlatform);
mt["get"]["TargetPlatform"]=mt["GetTargetPlatform"];
mt["GetVersion"]=static_cast<std::string(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::getVersion);
mt["get"]["Version"]=mt["GetVersion"];
mt["GetCompileVersion"]=static_cast<int64_t(cocos2d::ApplicationProtocol::*)()>(&cocos2d::ApplicationProtocol::GetCompileVersion);
mt["get"]["CompileVersion"]=mt["GetCompileVersion"];
mt["OpenURL"]=static_cast<bool(cocos2d::ApplicationProtocol::*)(const std::string&)>(&cocos2d::ApplicationProtocol::openURL);
mt["Notify"]=sol::overload([](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1,const std::function<void ()>& arg2){return obj->Notify(arg0,arg1,arg2);},[](cocos2d::ApplicationProtocol* obj,const std::string& arg0,const std::string& arg1){return obj->Notify(arg0,arg1);});
RegisterLuaCoreApplicationProtocolPlatformAuto(lua);
}
void RegisterLuaCoreApplicationAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Application).name()] = sol::usertype_traits<cocos2d::Application*>::metatable();
auto dep=lua.new_usertype<cocos2d::Application>("deprecated.cocos2d::Application");
dep[sol::base_classes]=sol::bases<cocos2d::ApplicationProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Application*>::metatable(),sol::usertype_traits<cocos2d::ApplicationProtocol*>::metatable());
lua["cc"]["Application"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["Run"]=static_cast<int(cocos2d::Application::*)()>(&cocos2d::Application::run);
mt["static"]["GetInstance"]=static_cast<cocos2d::Application*(*)()>(&cocos2d::Application::getInstance);
mt["static"]["get"]["Instance"]=&cocos2d::Application::getInstance;
}
void RegisterLuaCoreGLViewImplAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::GLViewImpl).name()] = sol::usertype_traits<cocos2d::GLViewImpl*>::metatable();
auto dep=lua.new_usertype<cocos2d::GLViewImpl>("deprecated.cocos2d::GLViewImpl");
dep[sol::base_classes]=sol::bases<cocos2d::GLView,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::GLViewImpl*>::metatable(),sol::usertype_traits<cocos2d::GLView*>::metatable());
lua["cc"]["GLViewImpl"]=mt;
mt["__new__"]=static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::create);
mt["static"]["CreateWithRect"]=sol::overload([](const std::string& arg0,cocos2d::Rect arg1,float arg2,bool arg3){return cocos2d::GLViewImpl::createWithRect(arg0,arg1,arg2,arg3);},[](const std::string& arg0,cocos2d::Rect arg1,float arg2){return cocos2d::GLViewImpl::createWithRect(arg0,arg1,arg2);},[](const std::string& arg0,cocos2d::Rect arg1){return cocos2d::GLViewImpl::createWithRect(arg0,arg1);});
mt["static"]["CreateWithFullScreen"]=static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::createWithFullScreen);
}
void RegisterLuaCoreAnimationCacheAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AnimationCache).name()] = sol::usertype_traits<cocos2d::AnimationCache*>::metatable();
auto dep=lua.new_usertype<cocos2d::AnimationCache>("deprecated.cocos2d::AnimationCache");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AnimationCache*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["AnimationCache"]=mt;
mt["__new__"]=[](){return new cocos2d::AnimationCache();};
mt["static"]["GetInstance"]=static_cast<cocos2d::AnimationCache*(*)()>(&cocos2d::AnimationCache::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocos2d::AnimationCache::destroyInstance);
mt["Init"]=static_cast<bool(cocos2d::AnimationCache::*)()>(&cocos2d::AnimationCache::init);
mt["AddAnimation"]=static_cast<void(cocos2d::AnimationCache::*)(cocos2d::Animation*,const std::string&)>(&cocos2d::AnimationCache::addAnimation);
mt["RemoveAnimation"]=static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::removeAnimation);
mt["GetAnimation"]=static_cast<cocos2d::Animation*(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::getAnimation);
mt["AddAnimationsWithDictionary"]=static_cast<void(cocos2d::AnimationCache::*)(const cocos2d::ValueMap&,const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithDictionary);
mt["AddAnimations"]=static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithFile);
mt["static"]["get"]["Instance"]=&cocos2d::AnimationCache::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocos2d::AnimationCache::destroyInstance();};
}
void RegisterLuaCoreSpriteBatchNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SpriteBatchNode).name()] = sol::usertype_traits<cocos2d::SpriteBatchNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::SpriteBatchNode>("deprecated.cocos2d::SpriteBatchNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SpriteBatchNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::TextureProtocol*>::metatable());
lua["cc"]["SpriteBatchNode"]=mt;
mt["static"]["CreateWithTexture"]=sol::overload([](cocos2d::Texture2D* arg0,ssize_t arg1){return cocos2d::SpriteBatchNode::createWithTexture(arg0,arg1);},[](cocos2d::Texture2D* arg0){return cocos2d::SpriteBatchNode::createWithTexture(arg0);});
mt["__new__"]=sol::overload([](const std::string& arg0,ssize_t arg1){return cocos2d::SpriteBatchNode::create(arg0,arg1);},[](const std::string& arg0){return cocos2d::SpriteBatchNode::create(arg0);});
mt["GetTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::getTextureAtlas);
mt["get"]["TextureAtlas"]=mt["GetTextureAtlas"];
mt["SetTextureAtlas"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::SpriteBatchNode::setTextureAtlas);
mt["set"]["TextureAtlas"]=mt["SetTextureAtlas"];
mt["GetDescendants"]=static_cast<const std::vector<cocos2d::Sprite *, std::allocator<cocos2d::Sprite *> >&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescendants);
mt["get"]["Descendants"]=mt["GetDescendants"];
mt["IncreaseAtlasCapacity"]=static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::increaseAtlasCapacity);
mt["RemoveChildAtIndex"]=static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t,bool)>(&cocos2d::SpriteBatchNode::removeChildAtIndex);
mt["AppendChild"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::appendChild);
mt["RemoveSpriteFromAtlas"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::removeSpriteFromAtlas);
mt["RebuildIndexInOrder"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::rebuildIndexInOrder);
mt["HighestAtlasIndexInChild"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::highestAtlasIndexInChild);
mt["LowestAtlasIndexInChild"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::lowestAtlasIndexInChild);
mt["AtlasIndexForChild"]=static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int)>(&cocos2d::SpriteBatchNode::atlasIndexForChild);
mt["ReorderBatch"]=static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::reorderBatch);
mt["InsertQuadFromSprite"]=static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::insertQuadFromSprite);
mt["AddSpriteWithoutQuad"]=static_cast<cocos2d::SpriteBatchNode*(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int,int)>(&cocos2d::SpriteBatchNode::addSpriteWithoutQuad);
mt["ReserveCapacity"]=static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t)>(&cocos2d::SpriteBatchNode::reserveCapacity);
}
void RegisterLuaCoreSpriteFrameCacheAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::SpriteFrameCache).name()] = sol::usertype_traits<cocos2d::SpriteFrameCache*>::metatable();
auto dep=lua.new_usertype<cocos2d::SpriteFrameCache>("deprecated.cocos2d::SpriteFrameCache");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::SpriteFrameCache*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["SpriteFrameCache"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["static"]["GetInstance"]=static_cast<cocos2d::SpriteFrameCache*(*)()>(&cocos2d::SpriteFrameCache::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocos2d::SpriteFrameCache::destroyInstance);
mt["Init"]=static_cast<bool(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::init);
mt["AddSpriteFrames"]=sol::overload(static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile));
mt["AddSpriteFramesWithFileContent"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFileContent);
mt["AddSpriteFrame"]=static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::SpriteFrame*,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFrame);
mt["IsSpriteFramesWithFileLoaded"]=static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)const>(&cocos2d::SpriteFrameCache::isSpriteFramesWithFileLoaded);
mt["RemoveSpriteFrames"]=static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeSpriteFrames);
mt["RemoveUnusedSpriteFrames"]=static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeUnusedSpriteFrames);
mt["RemoveSpriteFrameByName"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFrameByName);
mt["RemoveSpriteFramesFromFile"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFile);
mt["RemoveSpriteFramesFromFileContent"]=static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFileContent);
mt["RemoveSpriteFramesFromTexture"]=static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromTexture);
mt["GetSpriteFrame"]=static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::getSpriteFrameByName);
mt["ReloadTexture"]=static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::reloadTexture);
mt["static"]["get"]["Instance"]=&cocos2d::SpriteFrameCache::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocos2d::SpriteFrameCache::destroyInstance();};
}
void RegisterLuaCoreParallaxNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParallaxNode).name()] = sol::usertype_traits<cocos2d::ParallaxNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParallaxNode>("deprecated.cocos2d::ParallaxNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParallaxNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ParallaxNode"]=mt;
mt["__new__"]=static_cast<cocos2d::ParallaxNode*(*)()>(&cocos2d::ParallaxNode::create);
mt["AddChild"]=sol::overload(static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*)>(&cocos2d::ParallaxNode::addChild));
}
void RegisterLuaCoreTMXObjectGroupAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXObjectGroup).name()] = sol::usertype_traits<cocos2d::TMXObjectGroup*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXObjectGroup>("deprecated.cocos2d::TMXObjectGroup");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXObjectGroup*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TMXObjectGroup"]=mt;
mt["__new__"]=[](){return new cocos2d::TMXObjectGroup();};
mt["GetGroupName"]=static_cast<const std::string&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getGroupName);
mt["get"]["GroupName"]=mt["GetGroupName"];
mt["SetGroupName"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const std::string&)>(&cocos2d::TMXObjectGroup::setGroupName);
mt["set"]["GroupName"]=mt["SetGroupName"];
mt["GetProperty"]=static_cast<cocos2d::Value(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getProperty);
mt["GetObject"]=static_cast<cocos2d::ValueMap(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getObject);
mt["GetPositionOffset"]=static_cast<const cocos2d::Vec2&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getPositionOffset);
mt["get"]["PositionOffset"]=mt["GetPositionOffset"];
mt["SetPositionOffset"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::Vec2&)>(&cocos2d::TMXObjectGroup::setPositionOffset);
mt["set"]["PositionOffset"]=mt["SetPositionOffset"];
mt["GetProperties"]=static_cast<const cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getProperties);
mt["get"]["Properties"]=mt["GetProperties"];
mt["SetProperties"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXObjectGroup::setProperties);
mt["set"]["Properties"]=mt["SetProperties"];
mt["GetObjects"]=static_cast<const cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getObjects);
mt["get"]["Objects"]=mt["GetObjects"];
mt["SetObjects"]=static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueVector&)>(&cocos2d::TMXObjectGroup::setObjects);
mt["set"]["Objects"]=mt["SetObjects"];
}
void RegisterLuaCoreTMXTileFlags_Auto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,5);
enumTable["KTMXTileHorizontalFlag"]=cocos2d::TMXTileFlags_::kTMXTileHorizontalFlag;
enumTable["KTMXTileVerticalFlag"]=cocos2d::TMXTileFlags_::kTMXTileVerticalFlag;
enumTable["KTMXTileDiagonalFlag"]=cocos2d::TMXTileFlags_::kTMXTileDiagonalFlag;
enumTable["KTMXFlipedAll"]=cocos2d::TMXTileFlags_::kTMXFlipedAll;
enumTable["KTMXFlippedMask"]=cocos2d::TMXTileFlags_::kTMXFlippedMask;
lua["cc"]["TMXTileFlags"]=lua.NewEnum(enumTable);
}
}
