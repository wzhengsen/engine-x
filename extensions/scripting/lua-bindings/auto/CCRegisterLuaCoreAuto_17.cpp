#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreSpriteBatchNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpriteBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","SpriteBatchNode");
mt.set_function("getTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::getTextureAtlas));
mt.set_function("setTextureAtlas",static_cast<void(cocos2d::SpriteBatchNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::SpriteBatchNode::setTextureAtlas));
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
mt.set_function("initWithTexture",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->initWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->initWithTexture(arg0,arg1);}));
mt.set_function("initWithFile",sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->initWithFile(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->initWithFile(arg0,arg1);}));
mt.set_function("init",static_cast<bool(cocos2d::SpriteBatchNode::*)()>(&cocos2d::SpriteBatchNode::init));
mt.set_function("createWithTexture",sol::overload([](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0){return obj->createWithTexture(arg0);},[](cocos2d::SpriteBatchNode* obj,cocos2d::Texture2D* arg0,ssize_t arg1){return obj->createWithTexture(arg0,arg1);}));
mt.set_function("new",sol::overload([](cocos2d::SpriteBatchNode* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::SpriteBatchNode* obj,const std::string& arg0,ssize_t arg1){return obj->create(arg0,arg1);}));
}
void RegisterLuaCoreSpriteFrameCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpriteFrameCache,cocos2d::Ref,cocos2d::LuaObject>("cc","SpriteFrameCache");
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
auto mt=lua.NewUserType<cocos2d::ParallaxNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","ParallaxNode");
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ParallaxNode::addChild),static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ParallaxNode::addChild)));
mt.set_function("removeChild",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Node*,bool)>(&cocos2d::ParallaxNode::removeChild));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::ParallaxNode::*)(bool)>(&cocos2d::ParallaxNode::removeAllChildrenWithCleanup));
mt.set_function("visit",static_cast<void(cocos2d::ParallaxNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ParallaxNode::visit));
mt.set_function("new",static_cast<cocos2d::ParallaxNode*(*)()>(&cocos2d::ParallaxNode::create));
}
void RegisterLuaCoreTMXObjectGroupAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXObjectGroup,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXObjectGroup");
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
void RegisterLuaCoreTMXLayerInfoAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXLayerInfo,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXLayerInfo");
mt.set_function("setProperties",static_cast<void(cocos2d::TMXLayerInfo::*)(cocos2d::ValueMap)>(&cocos2d::TMXLayerInfo::setProperties));
mt.set_function("getProperties",static_cast<cocos2d::ValueMap&(cocos2d::TMXLayerInfo::*)()>(&cocos2d::TMXLayerInfo::getProperties));
}
void RegisterLuaCoreTMXTilesetInfoAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTilesetInfo,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTilesetInfo");
mt.set_function("getRectForGID",static_cast<cocos2d::Rect(cocos2d::TMXTilesetInfo::*)(uint32_t)>(&cocos2d::TMXTilesetInfo::getRectForGID));
}
void RegisterLuaCoreTMXMapInfoAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXMapInfo>("cc","TMXMapInfo");
mt.set_function("initWithTMXFile",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::initWithTMXFile));
mt.set_function("initWithXML",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::initWithXML));
mt.set_function("parseXMLFile",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLFile));
mt.set_function("parseXMLString",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLString));
mt.set_function("getTileProperties",static_cast<cocos2d::ValueMapIntKey&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTileProperties));
mt.set_function("setTileProperties",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMapIntKey&)>(&cocos2d::TMXMapInfo::setTileProperties));
mt.set_function("getOrientation",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getOrientation));
mt.set_function("setOrientation",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setOrientation));
mt.set_function("getStaggerAxis",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerAxis));
mt.set_function("setStaggerAxis",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerAxis));
mt.set_function("getStaggerIndex",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerIndex));
mt.set_function("setStaggerIndex",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerIndex));
mt.set_function("getHexSideLength",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getHexSideLength));
mt.set_function("setHexSideLength",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setHexSideLength));
mt.set_function("getMapSize",static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getMapSize));
mt.set_function("setMapSize",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setMapSize));
mt.set_function("getTileSize",static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTileSize));
mt.set_function("setTileSize",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setTileSize));
mt.set_function("getLayers",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getLayers),static_cast<const cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayers)));
mt.set_function("setLayers",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXLayerInfo *>&)>(&cocos2d::TMXMapInfo::setLayers));
mt.set_function("getTilesets",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTilesets),static_cast<const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTilesets)));
mt.set_function("setTilesets",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&)>(&cocos2d::TMXMapInfo::setTilesets));
mt.set_function("getObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getObjectGroups)));
mt.set_function("setObjectGroups",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::TMXMapInfo::setObjectGroups));
mt.set_function("getParentElement",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentElement));
mt.set_function("setParentElement",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentElement));
mt.set_function("getParentGID",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentGID));
mt.set_function("setParentGID",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentGID));
mt.set_function("getLayerAttribs",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayerAttribs));
mt.set_function("setLayerAttribs",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setLayerAttribs));
mt.set_function("isStoringCharacters",static_cast<bool(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::isStoringCharacters));
mt.set_function("setStoringCharacters",static_cast<void(cocos2d::TMXMapInfo::*)(bool)>(&cocos2d::TMXMapInfo::setStoringCharacters));
mt.set_function("getProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getProperties)));
mt.set_function("setProperties",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXMapInfo::setProperties));
mt.set_function("getCurrentString",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getCurrentString));
mt.set_function("setCurrentString",static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setCurrentString));
mt.set_function("getTMXFileName",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTMXFileName));
mt.set_function("setTMXFileName",static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setTMXFileName));
mt.set_function("getExternalTilesetFileName",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getExternalTilesetFileName));
mt.set_function("new",static_cast<cocos2d::TMXMapInfo*(*)(const std::string&)>(&cocos2d::TMXMapInfo::create));
mt.set_function("createWithXML",static_cast<cocos2d::TMXMapInfo*(*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::createWithXML));
}
void RegisterLuaCoreTileMapAtlasAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TileMapAtlas,cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","TileMapAtlas");
mt.set_function("initWithTileFile",static_cast<bool(cocos2d::TileMapAtlas::*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::initWithTileFile));
mt.set_function("getTileAt",static_cast<cocos2d::Color3B(cocos2d::TileMapAtlas::*)(const cocos2d::Vec2&)const>(&cocos2d::TileMapAtlas::getTileAt));
mt.set_function("setTile",static_cast<void(cocos2d::TileMapAtlas::*)(const cocos2d::Color3B&,const cocos2d::Vec2&)>(&cocos2d::TileMapAtlas::setTile));
mt.set_function("releaseMap",static_cast<void(cocos2d::TileMapAtlas::*)()>(&cocos2d::TileMapAtlas::releaseMap));
mt.set_function("new",static_cast<cocos2d::TileMapAtlas*(*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::create));
}
void RegisterLuaCoreFastTMXLayerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FastTMXLayer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","FastTMXLayer");
mt.set_function("setTileGID",sol::overload(static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&,cocos2d::TMXTileFlags)>(&cocos2d::FastTMXLayer::setTileGID),static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::setTileGID)));
mt.set_function("removeTileAt",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::removeTileAt));
mt.set_function("getPositionAt",static_cast<cocos2d::Vec2(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getPositionAt));
mt.set_function("getProperty",static_cast<cocos2d::Value(cocos2d::FastTMXLayer::*)(const std::string&)const>(&cocos2d::FastTMXLayer::getProperty));
mt.set_function("setupTiles",static_cast<void(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::setupTiles));
mt.set_function("getLayerName",static_cast<const std::string&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getLayerName));
mt.set_function("setLayerName",static_cast<void(cocos2d::FastTMXLayer::*)(const std::string&)>(&cocos2d::FastTMXLayer::setLayerName));
mt.set_function("getLayerSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerSize));
mt.set_function("setLayerSize",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setLayerSize));
mt.set_function("getMapTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getMapTileSize));
mt.set_function("setMapTileSize",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setMapTileSize));
mt.set_function("getTileSet",static_cast<cocos2d::TMXTilesetInfo*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileSet));
mt.set_function("setTileSet",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*)>(&cocos2d::FastTMXLayer::setTileSet));
mt.set_function("getLayerOrientation",static_cast<int(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerOrientation));
mt.set_function("setLayerOrientation",static_cast<void(cocos2d::FastTMXLayer::*)(int)>(&cocos2d::FastTMXLayer::setLayerOrientation));
mt.set_function("getProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getProperties)));
mt.set_function("setProperties",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXLayer::setProperties));
mt.set_function("getTileAt",static_cast<cocos2d::Sprite*(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getTileAt));
mt.set_function("setupTileSprite",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Sprite*,const cocos2d::Vec2&,uint32_t)>(&cocos2d::FastTMXLayer::setupTileSprite));
mt.set_function("getDescription",static_cast<std::string(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getDescription));
mt.set_function("draw",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::FastTMXLayer::draw));
mt.set_function("removeChild",sol::overload([](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("getAnimTileCoord",static_cast<const std::unordered_map<unsigned int, std::vector<cocos2d::Vec2>>*(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getAnimTileCoord));
mt.set_function("hasTileAnimation",static_cast<bool(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::hasTileAnimation));
mt.set_function("getTileAnimManager",static_cast<cocos2d::TMXTileAnimManager*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileAnimManager));
mt.set_function("initWithTilesetInfo",static_cast<bool(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::initWithTilesetInfo));
mt.set_function("new",static_cast<cocos2d::FastTMXLayer*(*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::create));
}
void RegisterLuaCoreTMXTileAnimTaskAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTileAnimTask,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTileAnimTask");
mt.set_function("start",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::start));
mt.set_function("stop",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::stop));
mt.set_function("isRunning",static_cast<bool(cocos2d::TMXTileAnimTask::*)()const>(&cocos2d::TMXTileAnimTask::isRunning));
mt.set_function("new",static_cast<cocos2d::TMXTileAnimTask*(*)(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>(&cocos2d::TMXTileAnimTask::create));
}
void RegisterLuaCoreTMXTileAnimManagerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTileAnimManager,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTileAnimManager");
mt.set_function("startAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll));
mt.set_function("stopAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll));
mt.set_function("getTasks",static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks));
mt.set_function("new",static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create));
}
void RegisterLuaCoreFastTMXTiledMapAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FastTMXTiledMap,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","FastTMXTiledMap");
mt.set_function("getLayer",static_cast<cocos2d::FastTMXLayer*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getLayer));
mt.set_function("getObjectGroup",static_cast<cocos2d::TMXObjectGroup*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getObjectGroup));
mt.set_function("getProperty",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getProperty));
mt.set_function("getPropertiesForGID",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(int)const>(&cocos2d::FastTMXTiledMap::getPropertiesForGID));
mt.set_function("getMapSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapSize));
mt.set_function("setMapSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setMapSize));
mt.set_function("getTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getTileSize));
mt.set_function("setTileSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setTileSize));
mt.set_function("getMapOrientation",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapOrientation));
mt.set_function("setMapOrientation",static_cast<void(cocos2d::FastTMXTiledMap::*)(int)>(&cocos2d::FastTMXTiledMap::setMapOrientation));
mt.set_function("getObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()>(&cocos2d::FastTMXTiledMap::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getObjectGroups)));
mt.set_function("setObjectGroups",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::FastTMXTiledMap::setObjectGroups));
mt.set_function("getProperties",static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getProperties));
mt.set_function("setProperties",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXTiledMap::setProperties));
mt.set_function("getDescription",static_cast<std::string(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getDescription));
mt.set_function("setTileAnimEnabled",static_cast<void(cocos2d::FastTMXTiledMap::*)(bool)>(&cocos2d::FastTMXTiledMap::setTileAnimEnabled));
mt.set_function("getLayerCount",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getLayerCount));
mt.set_function("getResourceFile",static_cast<const std::string&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getResourceFile));
mt.set_function("initWithTMXFile",static_cast<bool(cocos2d::FastTMXTiledMap::*)(const std::string&)>(&cocos2d::FastTMXTiledMap::initWithTMXFile));
mt.set_function("initWithXML",static_cast<bool(cocos2d::FastTMXTiledMap::*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::initWithXML));
mt.set_function("new",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&)>(&cocos2d::FastTMXTiledMap::create));
mt.set_function("createWithXML",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::createWithXML));
}
void RegisterLuaCoreMotionStreak3DAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::MotionStreak3D,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","MotionStreak3D");
mt.set_function("tintWithColor",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Color3B&)>(&cocos2d::MotionStreak3D::tintWithColor));
mt.set_function("reset",static_cast<void(cocos2d::MotionStreak3D::*)()>(&cocos2d::MotionStreak3D::reset));
mt.set_function("getStroke",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getStroke));
mt.set_function("setStroke",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setStroke));
mt.set_function("isStartingPositionInitialized",static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isStartingPositionInitialized));
mt.set_function("setStartingPositionInitialized",static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setStartingPositionInitialized));
mt.set_function("setPosition",sol::overload(static_cast<void(cocos2d::MotionStreak3D::*)(float,float)>(&cocos2d::MotionStreak3D::setPosition),static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec2&)>(&cocos2d::MotionStreak3D::setPosition)));
mt.set_function("setPosition3D",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setPosition3D));
mt.set_function("setRotation3D",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setRotation3D));
mt.set_function("setRotationQuat",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Quaternion&)>(&cocos2d::MotionStreak3D::setRotationQuat));
mt.set_function("getPosition",sol::overload(static_cast<void(cocos2d::MotionStreak3D::*)(float*,float*)const>(&cocos2d::MotionStreak3D::getPosition),static_cast<const cocos2d::Vec2&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition)));
mt.set_function("setPositionX",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionX));
mt.set_function("setPositionY",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::setPositionY));
mt.set_function("getPositionX",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionX));
mt.set_function("getPositionY",static_cast<float(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPositionY));
mt.set_function("getPosition3D",static_cast<cocos2d::Vec3(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getPosition3D));
mt.set_function("draw",static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::MotionStreak3D::draw));
mt.set_function("update",static_cast<void(cocos2d::MotionStreak3D::*)(float)>(&cocos2d::MotionStreak3D::update));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::MotionStreak3D::*)(cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::setTexture));
mt.set_function("setBlendFunc",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::MotionStreak3D::setBlendFunc));
mt.set_function("getBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getBlendFunc));
mt.set_function("getOpacity",static_cast<uint8_t(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getOpacity));
mt.set_function("setOpacity",static_cast<void(cocos2d::MotionStreak3D::*)(uint8_t)>(&cocos2d::MotionStreak3D::setOpacity));
mt.set_function("setOpacityModifyRGB",static_cast<void(cocos2d::MotionStreak3D::*)(bool)>(&cocos2d::MotionStreak3D::setOpacityModifyRGB));
mt.set_function("isOpacityModifyRGB",static_cast<bool(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::isOpacityModifyRGB));
mt.set_function("setSweepAxis",static_cast<void(cocos2d::MotionStreak3D::*)(const cocos2d::Vec3&)>(&cocos2d::MotionStreak3D::setSweepAxis));
mt.set_function("getSweepAxis",static_cast<const cocos2d::Vec3&(cocos2d::MotionStreak3D::*)()const>(&cocos2d::MotionStreak3D::getSweepAxis));
mt.set_function("initWithFade",sol::overload(static_cast<bool(cocos2d::MotionStreak3D::*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::initWithFade),static_cast<bool(cocos2d::MotionStreak3D::*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::initWithFade)));
mt.set_function("new",sol::overload(static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,cocos2d::Texture2D*)>(&cocos2d::MotionStreak3D::create),static_cast<cocos2d::MotionStreak3D*(*)(float,float,float,const cocos2d::Color3B&,const std::string&)>(&cocos2d::MotionStreak3D::create)));
}
