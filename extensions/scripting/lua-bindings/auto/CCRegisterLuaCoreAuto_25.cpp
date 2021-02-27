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
void RegisterLuaCoreApplicationAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Application>("Application",true);
ns["Application"] = mt;
lua["Application"] = sol::nil;
mt.set_function("setAnimationInterval",static_cast<void(cocos2d::Application::*)(float)>(&cocos2d::Application::setAnimationInterval));
mt.set_function("run",static_cast<int(cocos2d::Application::*)()>(&cocos2d::Application::run));
mt.set_function("getCurrentLanguage",static_cast<cocos2d::LanguageType(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguage));
mt.set_function("getCurrentLanguageCode",static_cast<const char*(cocos2d::Application::*)()>(&cocos2d::Application::getCurrentLanguageCode));
mt.set_function("getTargetPlatform",static_cast<cocos2d::ApplicationProtocol::Platform(cocos2d::Application::*)()>(&cocos2d::Application::getTargetPlatform));
mt.set_function("getVersion",static_cast<std::string(cocos2d::Application::*)()>(&cocos2d::Application::getVersion));
mt.set_function("GetCompileVersion",static_cast<int64_t(cocos2d::Application::*)()>(&cocos2d::Application::GetCompileVersion));
mt.set_function("openURL",static_cast<bool(cocos2d::Application::*)(const std::string&)>(&cocos2d::Application::openURL));
mt.set_function("getInstance",static_cast<cocos2d::Application*(*)()>(&cocos2d::Application::getInstance));
}
void RegisterLuaCoreGLViewImplAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::GLViewImpl,cocos2d::GLView,cocos2d::Ref,cocos2d::LuaObject>("GLViewImpl",false);
ns["GLViewImpl"] = mt;
lua["GLViewImpl"] = sol::nil;
mt.set_function("isOpenGLReady",static_cast<bool(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::isOpenGLReady));
mt.set_function("end",static_cast<void(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::end));
mt.set_function("swapBuffers",static_cast<void(cocos2d::GLViewImpl::*)()>(&cocos2d::GLViewImpl::swapBuffers));
mt.set_function("setIMEKeyboardState",static_cast<void(cocos2d::GLViewImpl::*)(bool)>(&cocos2d::GLViewImpl::setIMEKeyboardState));
mt.set_function("getSafeAreaRect",static_cast<cocos2d::Rect(cocos2d::GLViewImpl::*)()const>(&cocos2d::GLViewImpl::getSafeAreaRect));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::create));
mt.set_function("createWithRect",sol::overload([](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1){return obj->createWithRect(arg0,arg1);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2){return obj->createWithRect(arg0,arg1,arg2);},[](cocos2d::GLViewImpl* obj,const std::string& arg0,cocos2d::Rect arg1,float arg2,bool arg3){return obj->createWithRect(arg0,arg1,arg2,arg3);}));
mt.set_function("createWithFullScreen",static_cast<cocos2d::GLViewImpl*(*)(const std::string&)>(&cocos2d::GLViewImpl::createWithFullScreen));
}
void RegisterLuaCoreAnimationCacheAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::AnimationCache,cocos2d::Ref,cocos2d::LuaObject>("AnimationCache",true);
ns["AnimationCache"] = mt;
lua["AnimationCache"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::AnimationCache::*)()>(&cocos2d::AnimationCache::init));
mt.set_function("addAnimation",static_cast<void(cocos2d::AnimationCache::*)(cocos2d::Animation*,const std::string&)>(&cocos2d::AnimationCache::addAnimation));
mt.set_function("removeAnimation",static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::removeAnimation));
mt.set_function("getAnimation",static_cast<cocos2d::Animation*(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::getAnimation));
mt.set_function("addAnimationsWithDictionary",static_cast<void(cocos2d::AnimationCache::*)(const cocos2d::ValueMap&,const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithDictionary));
mt.set_function("addAnimations",static_cast<void(cocos2d::AnimationCache::*)(const std::string&)>(&cocos2d::AnimationCache::addAnimationsWithFile));
mt.set_function("getInstance",static_cast<cocos2d::AnimationCache*(*)()>(&cocos2d::AnimationCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::AnimationCache::destroyInstance));
}
void RegisterLuaCoreSpriteBatchNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::SpriteBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("SpriteBatchNode",false);
ns["SpriteBatchNode"] = mt;
lua["SpriteBatchNode"] = sol::nil;
mt.set_function("getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::getTextureAtlas));
mt.set_function("setTextureAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::SpriteBatchNode::setTextureAtlas));
mt.set_function("getDescendants",static_cast<const std::vector<cocos2d::Sprite *>&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescendants));
mt.set_function("increaseAtlasCapacity",static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::increaseAtlasCapacity));
mt.set_function("removeChildAtIndex",static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t,bool)>(&cocos2d::SpriteBatchNode::removeChildAtIndex));
mt.set_function("appendChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::appendChild));
mt.set_function("removeSpriteFromAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::removeSpriteFromAtlas));
mt.set_function("rebuildIndexInOrder",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::rebuildIndexInOrder));
mt.set_function("highestAtlasIndexInChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::highestAtlasIndexInChild));
mt.set_function("lowestAtlasIndexInChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*)>(&cocos2d::SpriteBatchNode::lowestAtlasIndexInChild));
mt.set_function("atlasIndexForChild",static_cast<ssize_t(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int)>(&cocos2d::SpriteBatchNode::atlasIndexForChild));
mt.set_function("reorderBatch",static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::reorderBatch));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteBatchNode::setTexture));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::SpriteBatchNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::SpriteBatchNode::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getBlendFunc));
mt.set_function("visit",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::visit));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::SpriteBatchNode::addChild),static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int,int)>(&cocos2d::SpriteBatchNode::addChild)));
mt.set_function("reorderChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,int)>(&cocos2d::SpriteBatchNode::reorderChild));
mt.set_function("removeChild",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Node*,bool)>(&cocos2d::SpriteBatchNode::removeChild));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::SpriteBatchNode::*)(bool)>(&cocos2d::SpriteBatchNode::removeAllChildrenWithCleanup));
mt.set_function("sortAllChildren",static_cast<void(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::sortAllChildren));
mt.set_function("draw",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::SpriteBatchNode::draw));
mt.set_function("getDescription",static_cast<std::string(cocos2d::SpriteBatchNode::*)()const>(&cocos2d::SpriteBatchNode::getDescription));
mt.set_function("setProgramState",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("insertQuadFromSprite",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,ssize_t)>(&cocos2d::SpriteBatchNode::insertQuadFromSprite));
mt.set_function("addSpriteWithoutQuad",static_cast<cocos2d::SpriteBatchNode*(cocos2d::SpriteBatchNode::*)(cocos2d::Sprite*,int,int)>(&cocos2d::SpriteBatchNode::addSpriteWithoutQuad));
mt.set_function("reserveCapacity",static_cast<void(cocos2d::SpriteBatchNode::*)(ssize_t)>(&cocos2d::SpriteBatchNode::reserveCapacity));
mt.set_function("createWithTexture",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->createWithTexture(arg0,arg1);}));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreSpriteFrameCacheAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::SpriteFrameCache,cocos2d::Ref,cocos2d::LuaObject>("SpriteFrameCache",true);
ns["SpriteFrameCache"] = mt;
lua["SpriteFrameCache"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::init));
mt.set_function("addSpriteFrames",sol::overload(static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile),static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFile)));
mt.set_function("addSpriteFramesWithFileContent",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&,cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::addSpriteFramesWithFileContent));
mt.set_function("addSpriteFrame",static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::SpriteFrame*,const std::string&)>(&cocos2d::SpriteFrameCache::addSpriteFrame));
mt.set_function("isSpriteFramesWithFileLoaded",static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)const>(&cocos2d::SpriteFrameCache::isSpriteFramesWithFileLoaded));
mt.set_function("removeSpriteFrames",static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeSpriteFrames));
mt.set_function("removeUnusedSpriteFrames",static_cast<void(cocos2d::SpriteFrameCache::*)()>(&cocos2d::SpriteFrameCache::removeUnusedSpriteFrames));
mt.set_function("removeSpriteFrameByName",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFrameByName));
mt.set_function("removeSpriteFramesFromFile",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFile));
mt.set_function("removeSpriteFramesFromFileContent",static_cast<void(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromFileContent));
mt.set_function("removeSpriteFramesFromTexture",static_cast<void(cocos2d::SpriteFrameCache::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrameCache::removeSpriteFramesFromTexture));
mt.set_function("getSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::getSpriteFrameByName));
mt.set_function("reloadTexture",static_cast<bool(cocos2d::SpriteFrameCache::*)(const std::string&)>(&cocos2d::SpriteFrameCache::reloadTexture));
mt.set_function("getInstance",static_cast<cocos2d::SpriteFrameCache*(*)()>(&cocos2d::SpriteFrameCache::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::SpriteFrameCache::destroyInstance));
}
void RegisterLuaCoreParallaxNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ParallaxNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("ParallaxNode",false);
ns["ParallaxNode"] = mt;
lua["ParallaxNode"] = sol::nil;
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParallaxNode::addChild)));
mt.set_function("removeChild",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParallaxNode::removeChild));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::ParallaxNode::*)(bool)>(&cocos2d::ParallaxNode::removeAllChildrenWithCleanup));
mt.set_function("visit",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParallaxNode::visit));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ParallaxNode*(*)()>(&cocos2d::ParallaxNode::create));
}
void RegisterLuaCoreTMXObjectGroupAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TMXObjectGroup,cocos2d::Ref,cocos2d::LuaObject>("TMXObjectGroup",true);
ns["TMXObjectGroup"] = mt;
lua["TMXObjectGroup"] = sol::nil;
mt.set_function("getGroupName",static_cast<const std::string&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getGroupName));
mt.set_function("setGroupName",static_cast<void(cocos2d::TMXObjectGroup::*)(const std::string&)>(&cocos2d::TMXObjectGroup::setGroupName));
mt.set_function("getProperty",static_cast<cocos2d::Value(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getProperty));
mt.set_function("getObject",static_cast<cocos2d::ValueMap(cocos2d::TMXObjectGroup::*)(const std::string&)const>(&cocos2d::TMXObjectGroup::getObject));
mt.set_function("getPositionOffset",static_cast<const cocos2d::Vec2&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getPositionOffset));
mt.set_function("setPositionOffset",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::Vec2&)>(&cocos2d::TMXObjectGroup::setPositionOffset));
mt.set_function("getProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getProperties)));
mt.set_function("setProperties",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXObjectGroup::setProperties));
mt.set_function("getObjects",sol::overload(static_cast<cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()>(&cocos2d::TMXObjectGroup::getObjects),static_cast<const cocos2d::ValueVector&(cocos2d::TMXObjectGroup::*)()const>(&cocos2d::TMXObjectGroup::getObjects)));
mt.set_function("setObjects",static_cast<void(cocos2d::TMXObjectGroup::*)(const cocos2d::ValueVector&)>(&cocos2d::TMXObjectGroup::setObjects));
}
void RegisterLuaCoreAnonymousEnum__143677541661601506_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXLayerAttribNone"] = 1;
pTable["TMXLayerAttribBase64"] = 2;
pTable["TMXLayerAttribGzip"] = 4;
pTable["TMXLayerAttribZlib"] = 8;
pTable["TMXLayerAttribCSV"] = 16;
}
void RegisterLuaCoreAnonymousEnum_5106521162491456473_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXPropertyNone"] = 0;
pTable["TMXPropertyMap"] = 1;
pTable["TMXPropertyLayer"] = 2;
pTable["TMXPropertyObjectGroup"] = 3;
pTable["TMXPropertyObject"] = 4;
pTable["TMXPropertyTile"] = 5;
pTable["TMXPropertyAnimation"] = 6;
}
void RegisterLuaCoreAnonymousEnum_1430269504163263798_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXOrientationOrtho"] = 0;
pTable["TMXOrientationHex"] = 1;
pTable["TMXOrientationIso"] = 2;
pTable["TMXOrientationStaggered"] = 3;
}
