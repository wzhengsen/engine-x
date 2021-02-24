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
void RegisterLuaCoreAnimationCacheAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AnimationCache,cocos2d::Ref,cocos2d::LuaObject>("cc","AnimationCache");
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
auto mt=lua.NewUserType<cocos2d::SpriteBatchNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("cc","SpriteBatchNode");
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
mt["_properties"] = &cocos2d::TMXLayerInfo::_properties;
mt["_name"] = &cocos2d::TMXLayerInfo::_name;
mt["_layerSize"] = &cocos2d::TMXLayerInfo::_layerSize;
mt["_tiles"] = &cocos2d::TMXLayerInfo::_tiles;
mt["_visible"] = &cocos2d::TMXLayerInfo::_visible;
mt["_opacity"] = &cocos2d::TMXLayerInfo::_opacity;
mt["_ownTiles"] = &cocos2d::TMXLayerInfo::_ownTiles;
mt["_offset"] = &cocos2d::TMXLayerInfo::_offset;
}
void RegisterLuaCoreTMXTilesetInfoAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTilesetInfo,cocos2d::Ref,cocos2d::LuaObject>("cc","TMXTilesetInfo");
mt.set_function("getRectForGID",static_cast<cocos2d::Rect(cocos2d::TMXTilesetInfo::*)(uint32_t)>(&cocos2d::TMXTilesetInfo::getRectForGID));
mt["_name"] = &cocos2d::TMXTilesetInfo::_name;
mt["_firstGid"] = &cocos2d::TMXTilesetInfo::_firstGid;
mt["_tileSize"] = &cocos2d::TMXTilesetInfo::_tileSize;
mt["_spacing"] = &cocos2d::TMXTilesetInfo::_spacing;
mt["_margin"] = &cocos2d::TMXTilesetInfo::_margin;
mt["_tileOffset"] = &cocos2d::TMXTilesetInfo::_tileOffset;
mt["_sourceImage"] = &cocos2d::TMXTilesetInfo::_sourceImage;
mt["_imageSize"] = &cocos2d::TMXTilesetInfo::_imageSize;
mt["_originSourceImage"] = &cocos2d::TMXTilesetInfo::_originSourceImage;
}
void RegisterLuaCoreTMXMapInfoAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXMapInfo,cocos2d::Ref,cocos2d::LuaObject,cocos2d::SAXDelegator>("cc","TMXMapInfo");
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
mt.set_function("endElement",static_cast<void(cocos2d::TMXMapInfo::*)(void*,const char*)>(&cocos2d::TMXMapInfo::endElement));
mt.set_function("textHandler",static_cast<void(cocos2d::TMXMapInfo::*)(void*,const char*,size_t)>(&cocos2d::TMXMapInfo::textHandler));
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
mt.set_function("getTGAInfo",static_cast<cocos2d::sImageTGA*(cocos2d::TileMapAtlas::*)()const>(&cocos2d::TileMapAtlas::getTGAInfo));
mt.set_function("setTGAInfo",static_cast<void(cocos2d::TileMapAtlas::*)(cocos2d::sImageTGA*)>(&cocos2d::TileMapAtlas::setTGAInfo));
mt.set_function("new",static_cast<cocos2d::TileMapAtlas*(*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::create));
}
void RegisterLuaCoreFastTMXLayerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FastTMXLayer,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","FastTMXLayer");
mt.set_function("getTileGIDAt",sol::overload([](cocos2d::FastTMXLayer* obj,const cocos2d::Vec2& arg0){return obj->getTileGIDAt(arg0);},[](cocos2d::FastTMXLayer* obj,const cocos2d::Vec2& arg0,cocos2d::TMXTileFlags* arg1){return obj->getTileGIDAt(arg0,arg1);}));
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
mt.set_function("getTiles",static_cast<const uint32_t*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTiles));
mt.set_function("setTiles",static_cast<void(cocos2d::FastTMXLayer::*)(uint32_t*)>(&cocos2d::FastTMXLayer::setTiles));
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
mt.set_function("new",static_cast<cocos2d::FastTMXLayer*(*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::create));
}
