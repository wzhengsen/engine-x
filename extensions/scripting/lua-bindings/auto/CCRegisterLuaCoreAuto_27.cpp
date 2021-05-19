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
void RegisterLuaCoreTMXTileFlags_Auto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::TMXTileFlags_>("TMXTileFlags",{
{"KTMXTileHorizontalFlag",cocos2d::TMXTileFlags_::kTMXTileHorizontalFlag}
,{"KTMXTileVerticalFlag",cocos2d::TMXTileFlags_::kTMXTileVerticalFlag}
,{"KTMXTileDiagonalFlag",cocos2d::TMXTileFlags_::kTMXTileDiagonalFlag}
,{"KTMXFlipedAll",cocos2d::TMXTileFlags_::kTMXFlipedAll}
,{"KTMXFlippedMask",cocos2d::TMXTileFlags_::kTMXFlippedMask}
});}
void RegisterLuaCoreTMXLayerInfoAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXLayerInfo>("cc","TMXLayerInfo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetProperties",static_cast<void(cocos2d::TMXLayerInfo::*)(cocos2d::ValueMap)>(&cocos2d::TMXLayerInfo::setProperties));
mt.set_function("GetProperties",static_cast<cocos2d::ValueMap&(cocos2d::TMXLayerInfo::*)()>(&cocos2d::TMXLayerInfo::getProperties));
mt[sol::call_constructor]=sol::constructors<cocos2d::TMXLayerInfo()>();
mt["Properties"]=&cocos2d::TMXLayerInfo::_properties;
mt["Name"]=&cocos2d::TMXLayerInfo::_name;
mt["LayerSize"]=&cocos2d::TMXLayerInfo::_layerSize;
mt["Tiles"]=&cocos2d::TMXLayerInfo::_tiles;
mt["Visible"]=&cocos2d::TMXLayerInfo::_visible;
mt["Opacity"]=&cocos2d::TMXLayerInfo::_opacity;
mt["OwnTiles"]=&cocos2d::TMXLayerInfo::_ownTiles;
mt["Offset"]=&cocos2d::TMXLayerInfo::_offset;
}
void RegisterLuaCoreTMXTilesetInfoAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTilesetInfo>("cc","TMXTilesetInfo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("GetRectForGID",static_cast<cocos2d::Rect(cocos2d::TMXTilesetInfo::*)(uint32_t)>(&cocos2d::TMXTilesetInfo::getRectForGID));
mt[sol::call_constructor]=sol::constructors<cocos2d::TMXTilesetInfo()>();
mt["Name"]=&cocos2d::TMXTilesetInfo::_name;
mt["FirstGid"]=&cocos2d::TMXTilesetInfo::_firstGid;
mt["TileSize"]=&cocos2d::TMXTilesetInfo::_tileSize;
mt["Spacing"]=&cocos2d::TMXTilesetInfo::_spacing;
mt["Margin"]=&cocos2d::TMXTilesetInfo::_margin;
mt["TileOffset"]=&cocos2d::TMXTilesetInfo::_tileOffset;
mt["SourceImage"]=&cocos2d::TMXTilesetInfo::_sourceImage;
mt["ImageSize"]=&cocos2d::TMXTilesetInfo::_imageSize;
mt["OriginSourceImage"]=&cocos2d::TMXTilesetInfo::_originSourceImage;
}
void RegisterLuaCoreTMXMapInfoAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXMapInfo>("cc","TMXMapInfo",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::SAXDelegator>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TMXMapInfo*(*)(const std::string&)>(&cocos2d::TMXMapInfo::create));
mt.set_function("CreateWithXML",static_cast<cocos2d::TMXMapInfo*(*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::createWithXML));
mt.set_function("InitWithTMXFile",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::initWithTMXFile));
mt.set_function("InitWithXML",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::initWithXML));
mt.set_function("ParseXMLFile",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLFile));
mt.set_function("ParseXMLString",static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLString));
mt.set_function("GetTileProperties",static_cast<cocos2d::ValueMapIntKey&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTileProperties));
mt.set_function("SetTileProperties",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMapIntKey&)>(&cocos2d::TMXMapInfo::setTileProperties));
mt.set_function("GetOrientation",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getOrientation));
mt.set_function("SetOrientation",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setOrientation));
mt.set_function("GetStaggerAxis",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerAxis));
mt.set_function("SetStaggerAxis",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerAxis));
mt.set_function("GetStaggerIndex",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerIndex));
mt.set_function("SetStaggerIndex",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerIndex));
mt.set_function("GetHexSideLength",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getHexSideLength));
mt.set_function("SetHexSideLength",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setHexSideLength));
mt.set_function("GetMapSize",static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getMapSize));
mt.set_function("SetMapSize",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setMapSize));
mt.set_function("GetTileSize",static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTileSize));
mt.set_function("SetTileSize",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setTileSize));
mt.set_function("GetLayers",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getLayers),static_cast<const cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayers)));
mt.set_function("SetLayers",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXLayerInfo *>&)>(&cocos2d::TMXMapInfo::setLayers));
mt.set_function("GetTilesets",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTilesets),static_cast<const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTilesets)));
mt.set_function("SetTilesets",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&)>(&cocos2d::TMXMapInfo::setTilesets));
mt.set_function("GetObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getObjectGroups)));
mt.set_function("SetObjectGroups",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::TMXMapInfo::setObjectGroups));
mt.set_function("GetParentElement",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentElement));
mt.set_function("SetParentElement",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentElement));
mt.set_function("GetParentGID",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentGID));
mt.set_function("SetParentGID",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentGID));
mt.set_function("GetLayerAttribs",static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayerAttribs));
mt.set_function("SetLayerAttribs",static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setLayerAttribs));
mt.set_function("IsStoringCharacters",static_cast<bool(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::isStoringCharacters));
mt.set_function("SetStoringCharacters",static_cast<void(cocos2d::TMXMapInfo::*)(bool)>(&cocos2d::TMXMapInfo::setStoringCharacters));
mt.set_function("GetProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getProperties)));
mt.set_function("SetProperties",static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXMapInfo::setProperties));
mt.set_function("TextHandler",static_cast<void(cocos2d::TMXMapInfo::*)(void*,const char*,size_t)>(&cocos2d::TMXMapInfo::textHandler));
mt.set_function("GetCurrentString",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getCurrentString));
mt.set_function("SetCurrentString",static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setCurrentString));
mt.set_function("GetTMXFileName",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTMXFileName));
mt.set_function("SetTMXFileName",static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setTMXFileName));
mt.set_function("GetExternalTilesetFileName",static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getExternalTilesetFileName));
}
void RegisterLuaCoreTileMapAtlasAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TileMapAtlas>("cc","TileMapAtlas",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TileMapAtlas*(*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::create));
mt.set_function("InitWithTileFile",static_cast<bool(cocos2d::TileMapAtlas::*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::initWithTileFile));
mt.set_function("GetTileAt",static_cast<cocos2d::Color3B(cocos2d::TileMapAtlas::*)(const cocos2d::Vec2&)const>(&cocos2d::TileMapAtlas::getTileAt));
mt.set_function("SetTile",static_cast<void(cocos2d::TileMapAtlas::*)(const cocos2d::Color3B&,const cocos2d::Vec2&)>(&cocos2d::TileMapAtlas::setTile));
mt.set_function("ReleaseMap",static_cast<void(cocos2d::TileMapAtlas::*)()>(&cocos2d::TileMapAtlas::releaseMap));
mt.set_function("GetTGAInfo",static_cast<cocos2d::sImageTGA*(cocos2d::TileMapAtlas::*)()const>(&cocos2d::TileMapAtlas::getTGAInfo));
mt.set_function("SetTGAInfo",static_cast<void(cocos2d::TileMapAtlas::*)(cocos2d::sImageTGA*)>(&cocos2d::TileMapAtlas::setTGAInfo));
}
void RegisterLuaCoreFastTMXLayerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FastTMXLayer>("cc","FastTMXLayer",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FastTMXLayer*(*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::create));
mt.set_function("GetTileGIDAt",sol::overload([](cocos2d::FastTMXLayer* obj,const cocos2d::Vec2& arg0){return obj->getTileGIDAt(arg0);},[](cocos2d::FastTMXLayer* obj,const cocos2d::Vec2& arg0,cocos2d::TMXTileFlags* arg1){return obj->getTileGIDAt(arg0,arg1);}));
mt.set_function("SetTileGID",sol::overload(static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&,cocos2d::TMXTileFlags)>(&cocos2d::FastTMXLayer::setTileGID),static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::setTileGID)));
mt.set_function("RemoveTileAt",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::removeTileAt));
mt.set_function("GetPositionAt",static_cast<cocos2d::Vec2(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getPositionAt));
mt.set_function("GetProperty",static_cast<cocos2d::Value(cocos2d::FastTMXLayer::*)(const std::string&)const>(&cocos2d::FastTMXLayer::getProperty));
mt.set_function("SetupTiles",static_cast<void(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::setupTiles));
mt.set_function("GetLayerName",static_cast<const std::string&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getLayerName));
mt.set_function("SetLayerName",static_cast<void(cocos2d::FastTMXLayer::*)(const std::string&)>(&cocos2d::FastTMXLayer::setLayerName));
mt.set_function("GetLayerSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerSize));
mt.set_function("SetLayerSize",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setLayerSize));
mt.set_function("GetMapTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getMapTileSize));
mt.set_function("SetMapTileSize",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setMapTileSize));
mt.set_function("GetTiles",static_cast<const uint32_t*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTiles));
mt.set_function("SetTiles",static_cast<void(cocos2d::FastTMXLayer::*)(uint32_t*)>(&cocos2d::FastTMXLayer::setTiles));
mt.set_function("GetTileSet",static_cast<cocos2d::TMXTilesetInfo*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileSet));
mt.set_function("SetTileSet",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*)>(&cocos2d::FastTMXLayer::setTileSet));
mt.set_function("GetLayerOrientation",static_cast<int(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerOrientation));
mt.set_function("SetLayerOrientation",static_cast<void(cocos2d::FastTMXLayer::*)(int)>(&cocos2d::FastTMXLayer::setLayerOrientation));
mt.set_function("GetProperties",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getProperties),static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getProperties)));
mt.set_function("SetProperties",static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXLayer::setProperties));
mt.set_function("GetTileAt",static_cast<cocos2d::Sprite*(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getTileAt));
mt.set_function("SetupTileSprite",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Sprite*,const cocos2d::Vec2&,uint32_t)>(&cocos2d::FastTMXLayer::setupTileSprite));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getDescription));
mt.set_function("Draw",static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::FastTMXLayer::draw));
mt.set_function("RemoveChild",sol::overload([](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::FastTMXLayer* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("GetAnimTileCoord",static_cast<const std::unordered_map<unsigned int, std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> > > > >*(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getAnimTileCoord));
mt.set_function("HasTileAnimation",static_cast<bool(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::hasTileAnimation));
mt.set_function("GetTileAnimManager",static_cast<cocos2d::TMXTileAnimManager*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileAnimManager));
mt[sol::call_constructor]=sol::constructors<cocos2d::FastTMXLayer()>();
mt["FAST_TMX_ORIENTATION_ORTHO"]=sol::var(std::ref(cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ORTHO));
mt["FAST_TMX_ORIENTATION_HEX"]=sol::var(std::ref(cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_HEX));
mt["FAST_TMX_ORIENTATION_ISO"]=sol::var(std::ref(cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ISO));
}
void RegisterLuaCoreTMXTileAnimTaskAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTileAnimTask>("cc","TMXTileAnimTask",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TMXTileAnimTask*(*)(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>(&cocos2d::TMXTileAnimTask::create));
mt.set_function("Start",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::start));
mt.set_function("Stop",static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::stop));
mt.set_function("IsRunning",static_cast<bool(cocos2d::TMXTileAnimTask::*)()const>(&cocos2d::TMXTileAnimTask::isRunning));
mt[sol::call_constructor]=sol::constructors<cocos2d::TMXTileAnimTask(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>();
}
void RegisterLuaCoreTMXTileAnimManagerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TMXTileAnimManager>("cc","TMXTileAnimManager",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create));
mt.set_function("StartAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll));
mt.set_function("StopAll",static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll));
mt.set_function("GetTasks",static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks));
mt[sol::call_constructor]=sol::constructors<cocos2d::TMXTileAnimManager(cocos2d::FastTMXLayer*)>();
}
void RegisterLuaCoreFastTMXTiledMapAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FastTMXTiledMap>("cc","FastTMXTiledMap",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&)>(&cocos2d::FastTMXTiledMap::create));
mt.set_function("CreateWithXML",static_cast<cocos2d::FastTMXTiledMap*(*)(const std::string&,const std::string&)>(&cocos2d::FastTMXTiledMap::createWithXML));
mt.set_function("GetLayer",static_cast<cocos2d::FastTMXLayer*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getLayer));
mt.set_function("GetObjectGroup",static_cast<cocos2d::TMXObjectGroup*(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getObjectGroup));
mt.set_function("GetProperty",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(const std::string&)const>(&cocos2d::FastTMXTiledMap::getProperty));
mt.set_function("GetPropertiesForGID",static_cast<cocos2d::Value(cocos2d::FastTMXTiledMap::*)(int)const>(&cocos2d::FastTMXTiledMap::getPropertiesForGID));
mt.set_function("GetMapSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapSize));
mt.set_function("SetMapSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setMapSize));
mt.set_function("GetTileSize",static_cast<const cocos2d::Size&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getTileSize));
mt.set_function("SetTileSize",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Size&)>(&cocos2d::FastTMXTiledMap::setTileSize));
mt.set_function("GetMapOrientation",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getMapOrientation));
mt.set_function("SetMapOrientation",static_cast<void(cocos2d::FastTMXTiledMap::*)(int)>(&cocos2d::FastTMXTiledMap::setMapOrientation));
mt.set_function("GetObjectGroups",sol::overload(static_cast<cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()>(&cocos2d::FastTMXTiledMap::getObjectGroups),static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getObjectGroups)));
mt.set_function("SetObjectGroups",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::FastTMXTiledMap::setObjectGroups));
mt.set_function("GetProperties",static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getProperties));
mt.set_function("SetProperties",static_cast<void(cocos2d::FastTMXTiledMap::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXTiledMap::setProperties));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getDescription));
mt.set_function("SetTileAnimEnabled",static_cast<void(cocos2d::FastTMXTiledMap::*)(bool)>(&cocos2d::FastTMXTiledMap::setTileAnimEnabled));
mt.set_function("GetLayerCount",static_cast<int(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getLayerCount));
mt.set_function("GetResourceFile",static_cast<const std::string&(cocos2d::FastTMXTiledMap::*)()const>(&cocos2d::FastTMXTiledMap::getResourceFile));
}
void RegisterLuaCoreSprite3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite3D>("cc","Sprite3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Sprite3D*(*)(const std::string&)>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)()>(&cocos2d::Sprite3D::create),static_cast<cocos2d::Sprite3D*(*)(const std::string&,const std::string&)>(&cocos2d::Sprite3D::create)));
mt.set_function("CreateAsync",sol::overload(static_cast<void(*)(const std::string&,const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync),static_cast<void(*)(const std::string&,const std::function<void (cocos2d::Sprite3D *, void *)>&,void*)>(&cocos2d::Sprite3D::createAsync)));
mt.set_function("SetTexture",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite3D::setTexture),static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::setTexture)));
mt.set_function("GetMeshByIndex",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMeshByIndex));
mt.set_function("GetMeshByName",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshByName));
mt.set_function("GetMeshArrayByName",static_cast<std::vector<cocos2d::Mesh *, std::allocator<cocos2d::Mesh *> >(cocos2d::Sprite3D::*)(const std::string&)const>(&cocos2d::Sprite3D::getMeshArrayByName));
mt.set_function("GetMesh",static_cast<cocos2d::Mesh*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMesh));
mt.set_function("GetMeshCount",static_cast<ssize_t(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshCount));
mt.set_function("GetSkeleton",static_cast<cocos2d::Skeleton3D*(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getSkeleton));
mt.set_function("GetAttachNode",static_cast<cocos2d::AttachNode*(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::getAttachNode));
mt.set_function("RemoveAttachNode",static_cast<void(cocos2d::Sprite3D::*)(const std::string&)>(&cocos2d::Sprite3D::removeAttachNode));
mt.set_function("RemoveAllAttachNode",static_cast<void(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::removeAllAttachNode));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::Sprite3D::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite3D::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBlendFunc));
mt.set_function("SetProgramState",sol::overload([](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite3D* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("GetAABB",static_cast<const cocos2d::AABB&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getAABB));
mt.set_function("GetAABBRecursively",static_cast<cocos2d::AABB(cocos2d::Sprite3D::*)()>(&cocos2d::Sprite3D::getAABBRecursively));
mt.set_function("RunAction",static_cast<cocos2d::Action*(cocos2d::Sprite3D::*)(cocos2d::Action*)>(&cocos2d::Sprite3D::runAction));
mt.set_function("SetForceDepthWrite",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForceDepthWrite));
mt.set_function("IsForceDepthWrite",static_cast<bool(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::isForceDepthWrite));
mt.set_function("GetBoundingBox",static_cast<cocos2d::Rect(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getBoundingBox));
mt.set_function("SetCullFace",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::CullFaceSide)>(&cocos2d::Sprite3D::setCullFace));
mt.set_function("SetCullFaceEnabled",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setCullFaceEnabled));
mt.set_function("SetLightMask",static_cast<void(cocos2d::Sprite3D::*)(unsigned int)>(&cocos2d::Sprite3D::setLightMask));
mt.set_function("GetLightMask",static_cast<unsigned int(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getLightMask));
mt.set_function("Draw",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::draw));
mt.set_function("SetMaterial",sol::overload(static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*,int)>(&cocos2d::Sprite3D::setMaterial),static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Material*)>(&cocos2d::Sprite3D::setMaterial)));
mt.set_function("GetMaterial",static_cast<cocos2d::Material*(cocos2d::Sprite3D::*)(int)const>(&cocos2d::Sprite3D::getMaterial));
mt.set_function("SetForce2DQueue",static_cast<void(cocos2d::Sprite3D::*)(bool)>(&cocos2d::Sprite3D::setForce2DQueue));
mt.set_function("GetMeshes",static_cast<const cocos2d::Vector<cocos2d::Mesh *>&(cocos2d::Sprite3D::*)()const>(&cocos2d::Sprite3D::getMeshes));
mt.set_function("Visit",static_cast<void(cocos2d::Sprite3D::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite3D::visit));
}
