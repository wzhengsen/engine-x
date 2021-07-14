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
sol::table enumTable = lua.create_table_with(0,5);
enumTable["KTMXTileHorizontalFlag"]=cocos2d::TMXTileFlags_::kTMXTileHorizontalFlag;
enumTable["KTMXTileVerticalFlag"]=cocos2d::TMXTileFlags_::kTMXTileVerticalFlag;
enumTable["KTMXTileDiagonalFlag"]=cocos2d::TMXTileFlags_::kTMXTileDiagonalFlag;
enumTable["KTMXFlipedAll"]=cocos2d::TMXTileFlags_::kTMXFlipedAll;
enumTable["KTMXFlippedMask"]=cocos2d::TMXTileFlags_::kTMXFlippedMask;
lua["cc"]["TMXTileFlags"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreTMXLayerInfoAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXLayerInfo).name()] = sol::usertype_traits<cocos2d::TMXLayerInfo*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXLayerInfo>("deprecated.cocos2d::TMXLayerInfo");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXLayerInfo*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TMXLayerInfo"]=mt;
mt["__new__"]=[](){return new cocos2d::TMXLayerInfo();};
mt["SetProperties"]=static_cast<void(cocos2d::TMXLayerInfo::*)(cocos2d::ValueMap)>(&cocos2d::TMXLayerInfo::setProperties);
mt["set"]["Properties"]=mt["SetProperties"];
mt["GetProperties"]=static_cast<cocos2d::ValueMap&(cocos2d::TMXLayerInfo::*)()>(&cocos2d::TMXLayerInfo::getProperties);
mt["get"]["Properties"]=mt["GetProperties"];
mt["set"]["Properties"]=[](cocos2d::TMXLayerInfo* obj,const cocos2d::ValueMap& value){obj->_properties = value;};
mt["get"]["Properties"]=[](cocos2d::TMXLayerInfo* obj)->const cocos2d::ValueMap&{return obj->_properties;};
mt["set"]["Name"]=[](cocos2d::TMXLayerInfo* obj,const std::string& value){obj->_name = value;};
mt["get"]["Name"]=[](cocos2d::TMXLayerInfo* obj)->const std::string&{return obj->_name;};
mt["set"]["LayerSize"]=[](cocos2d::TMXLayerInfo* obj,const cocos2d::Size& value){obj->_layerSize = value;};
mt["get"]["LayerSize"]=[](cocos2d::TMXLayerInfo* obj)->const cocos2d::Size&{return obj->_layerSize;};
mt["set"]["Tiles"]=[](cocos2d::TMXLayerInfo* obj,uint32_t* value){obj->_tiles = value;};
mt["get"]["Tiles"]=[](cocos2d::TMXLayerInfo* obj)->const uint32_t*{return obj->_tiles;};
mt["set"]["Visible"]=[](cocos2d::TMXLayerInfo* obj,const bool& value){obj->_visible = value;};
mt["get"]["Visible"]=[](cocos2d::TMXLayerInfo* obj)->const bool&{return obj->_visible;};
mt["set"]["Opacity"]=[](cocos2d::TMXLayerInfo* obj,const unsigned char& value){obj->_opacity = value;};
mt["get"]["Opacity"]=[](cocos2d::TMXLayerInfo* obj)->const unsigned char&{return obj->_opacity;};
mt["set"]["OwnTiles"]=[](cocos2d::TMXLayerInfo* obj,const bool& value){obj->_ownTiles = value;};
mt["get"]["OwnTiles"]=[](cocos2d::TMXLayerInfo* obj)->const bool&{return obj->_ownTiles;};
mt["set"]["Offset"]=[](cocos2d::TMXLayerInfo* obj,const cocos2d::Vec2& value){obj->_offset = value;};
mt["get"]["Offset"]=[](cocos2d::TMXLayerInfo* obj)->const cocos2d::Vec2&{return obj->_offset;};
}
void RegisterLuaCoreTMXTilesetInfoAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXTilesetInfo).name()] = sol::usertype_traits<cocos2d::TMXTilesetInfo*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXTilesetInfo>("deprecated.cocos2d::TMXTilesetInfo");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXTilesetInfo*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TMXTilesetInfo"]=mt;
mt["__new__"]=[](){return new cocos2d::TMXTilesetInfo();};
mt["GetRectForGID"]=static_cast<cocos2d::Rect(cocos2d::TMXTilesetInfo::*)(uint32_t)>(&cocos2d::TMXTilesetInfo::getRectForGID);
mt["set"]["Name"]=[](cocos2d::TMXTilesetInfo* obj,const std::string& value){obj->_name = value;};
mt["get"]["Name"]=[](cocos2d::TMXTilesetInfo* obj)->const std::string&{return obj->_name;};
mt["set"]["FirstGid"]=[](cocos2d::TMXTilesetInfo* obj,const int& value){obj->_firstGid = value;};
mt["get"]["FirstGid"]=[](cocos2d::TMXTilesetInfo* obj)->const int&{return obj->_firstGid;};
mt["set"]["TileSize"]=[](cocos2d::TMXTilesetInfo* obj,const cocos2d::Size& value){obj->_tileSize = value;};
mt["get"]["TileSize"]=[](cocos2d::TMXTilesetInfo* obj)->const cocos2d::Size&{return obj->_tileSize;};
mt["set"]["Spacing"]=[](cocos2d::TMXTilesetInfo* obj,const int& value){obj->_spacing = value;};
mt["get"]["Spacing"]=[](cocos2d::TMXTilesetInfo* obj)->const int&{return obj->_spacing;};
mt["set"]["Margin"]=[](cocos2d::TMXTilesetInfo* obj,const int& value){obj->_margin = value;};
mt["get"]["Margin"]=[](cocos2d::TMXTilesetInfo* obj)->const int&{return obj->_margin;};
mt["set"]["TileOffset"]=[](cocos2d::TMXTilesetInfo* obj,const cocos2d::Vec2& value){obj->_tileOffset = value;};
mt["get"]["TileOffset"]=[](cocos2d::TMXTilesetInfo* obj)->const cocos2d::Vec2&{return obj->_tileOffset;};
mt["set"]["SourceImage"]=[](cocos2d::TMXTilesetInfo* obj,const std::string& value){obj->_sourceImage = value;};
mt["get"]["SourceImage"]=[](cocos2d::TMXTilesetInfo* obj)->const std::string&{return obj->_sourceImage;};
mt["set"]["ImageSize"]=[](cocos2d::TMXTilesetInfo* obj,const cocos2d::Size& value){obj->_imageSize = value;};
mt["get"]["ImageSize"]=[](cocos2d::TMXTilesetInfo* obj)->const cocos2d::Size&{return obj->_imageSize;};
mt["set"]["OriginSourceImage"]=[](cocos2d::TMXTilesetInfo* obj,const std::string& value){obj->_originSourceImage = value;};
mt["get"]["OriginSourceImage"]=[](cocos2d::TMXTilesetInfo* obj)->const std::string&{return obj->_originSourceImage;};
}
void RegisterLuaCoreTMXMapInfoAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXMapInfo).name()] = sol::usertype_traits<cocos2d::TMXMapInfo*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXMapInfo>("deprecated.cocos2d::TMXMapInfo");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::SAXDelegator>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXMapInfo*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable(),sol::usertype_traits<cocos2d::SAXDelegator*>::metatable());
lua["cc"]["TMXMapInfo"]=mt;
mt["__new__"]=static_cast<cocos2d::TMXMapInfo*(*)(const std::string&)>(&cocos2d::TMXMapInfo::create);
mt["static"]["CreateWithXML"]=static_cast<cocos2d::TMXMapInfo*(*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::createWithXML);
mt["InitWithTMXFile"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::initWithTMXFile);
mt["InitWithXML"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&,const std::string&)>(&cocos2d::TMXMapInfo::initWithXML);
mt["ParseXMLFile"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLFile);
mt["ParseXMLString"]=static_cast<bool(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::parseXMLString);
mt["GetTileProperties"]=static_cast<cocos2d::ValueMapIntKey&(cocos2d::TMXMapInfo::*)()>(&cocos2d::TMXMapInfo::getTileProperties);
mt["get"]["TileProperties"]=mt["GetTileProperties"];
mt["SetTileProperties"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMapIntKey&)>(&cocos2d::TMXMapInfo::setTileProperties);
mt["set"]["TileProperties"]=mt["SetTileProperties"];
mt["GetOrientation"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getOrientation);
mt["get"]["Orientation"]=mt["GetOrientation"];
mt["SetOrientation"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setOrientation);
mt["set"]["Orientation"]=mt["SetOrientation"];
mt["GetStaggerAxis"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerAxis);
mt["get"]["StaggerAxis"]=mt["GetStaggerAxis"];
mt["SetStaggerAxis"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerAxis);
mt["set"]["StaggerAxis"]=mt["SetStaggerAxis"];
mt["GetStaggerIndex"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getStaggerIndex);
mt["get"]["StaggerIndex"]=mt["GetStaggerIndex"];
mt["SetStaggerIndex"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setStaggerIndex);
mt["set"]["StaggerIndex"]=mt["SetStaggerIndex"];
mt["GetHexSideLength"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getHexSideLength);
mt["get"]["HexSideLength"]=mt["GetHexSideLength"];
mt["SetHexSideLength"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setHexSideLength);
mt["set"]["HexSideLength"]=mt["SetHexSideLength"];
mt["GetMapSize"]=static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getMapSize);
mt["get"]["MapSize"]=mt["GetMapSize"];
mt["SetMapSize"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setMapSize);
mt["set"]["MapSize"]=mt["SetMapSize"];
mt["GetTileSize"]=static_cast<const cocos2d::Size&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTileSize);
mt["get"]["TileSize"]=mt["GetTileSize"];
mt["SetTileSize"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Size&)>(&cocos2d::TMXMapInfo::setTileSize);
mt["set"]["TileSize"]=mt["SetTileSize"];
mt["GetLayers"]=static_cast<const cocos2d::Vector<cocos2d::TMXLayerInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayers);
mt["get"]["Layers"]=mt["GetLayers"];
mt["SetLayers"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXLayerInfo *>&)>(&cocos2d::TMXMapInfo::setLayers);
mt["set"]["Layers"]=mt["SetLayers"];
mt["GetTilesets"]=static_cast<const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTilesets);
mt["get"]["Tilesets"]=mt["GetTilesets"];
mt["SetTilesets"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&)>(&cocos2d::TMXMapInfo::setTilesets);
mt["set"]["Tilesets"]=mt["SetTilesets"];
mt["GetObjectGroups"]=static_cast<const cocos2d::Vector<cocos2d::TMXObjectGroup *>&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getObjectGroups);
mt["get"]["ObjectGroups"]=mt["GetObjectGroups"];
mt["SetObjectGroups"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::Vector<cocos2d::TMXObjectGroup *>&)>(&cocos2d::TMXMapInfo::setObjectGroups);
mt["set"]["ObjectGroups"]=mt["SetObjectGroups"];
mt["GetParentElement"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentElement);
mt["get"]["ParentElement"]=mt["GetParentElement"];
mt["SetParentElement"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentElement);
mt["set"]["ParentElement"]=mt["SetParentElement"];
mt["GetParentGID"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getParentGID);
mt["get"]["ParentGID"]=mt["GetParentGID"];
mt["SetParentGID"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setParentGID);
mt["set"]["ParentGID"]=mt["SetParentGID"];
mt["GetLayerAttribs"]=static_cast<int(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getLayerAttribs);
mt["get"]["LayerAttribs"]=mt["GetLayerAttribs"];
mt["SetLayerAttribs"]=static_cast<void(cocos2d::TMXMapInfo::*)(int)>(&cocos2d::TMXMapInfo::setLayerAttribs);
mt["set"]["LayerAttribs"]=mt["SetLayerAttribs"];
mt["IsStoringCharacters"]=static_cast<bool(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::isStoringCharacters);
mt["get"]["StoringCharacters"]=mt["IsStoringCharacters"];
mt["SetStoringCharacters"]=static_cast<void(cocos2d::TMXMapInfo::*)(bool)>(&cocos2d::TMXMapInfo::setStoringCharacters);
mt["set"]["StoringCharacters"]=mt["SetStoringCharacters"];
mt["GetProperties"]=static_cast<const cocos2d::ValueMap&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getProperties);
mt["get"]["Properties"]=mt["GetProperties"];
mt["SetProperties"]=static_cast<void(cocos2d::TMXMapInfo::*)(const cocos2d::ValueMap&)>(&cocos2d::TMXMapInfo::setProperties);
mt["set"]["Properties"]=mt["SetProperties"];
mt["GetCurrentString"]=static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getCurrentString);
mt["get"]["CurrentString"]=mt["GetCurrentString"];
mt["SetCurrentString"]=static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setCurrentString);
mt["set"]["CurrentString"]=mt["SetCurrentString"];
mt["GetTMXFileName"]=static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getTMXFileName);
mt["get"]["TMXFileName"]=mt["GetTMXFileName"];
mt["SetTMXFileName"]=static_cast<void(cocos2d::TMXMapInfo::*)(const std::string&)>(&cocos2d::TMXMapInfo::setTMXFileName);
mt["set"]["TMXFileName"]=mt["SetTMXFileName"];
mt["GetExternalTilesetFileName"]=static_cast<const std::string&(cocos2d::TMXMapInfo::*)()const>(&cocos2d::TMXMapInfo::getExternalTilesetFileName);
mt["get"]["ExternalTilesetFileName"]=mt["GetExternalTilesetFileName"];
}
void RegisterLuaCoreTileMapAtlasAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TileMapAtlas).name()] = sol::usertype_traits<cocos2d::TileMapAtlas*>::metatable();
auto dep=lua.new_usertype<cocos2d::TileMapAtlas>("deprecated.cocos2d::TileMapAtlas");
dep[sol::base_classes]=sol::bases<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TileMapAtlas*>::metatable(),sol::usertype_traits<cocos2d::AtlasNode*>::metatable());
lua["cc"]["TileMapAtlas"]=mt;
mt["__new__"]=static_cast<cocos2d::TileMapAtlas*(*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::create);
mt["InitWithTileFile"]=static_cast<bool(cocos2d::TileMapAtlas::*)(const std::string&,const std::string&,int,int)>(&cocos2d::TileMapAtlas::initWithTileFile);
mt["GetTileAt"]=static_cast<cocos2d::Color3B(cocos2d::TileMapAtlas::*)(const cocos2d::Vec2&)const>(&cocos2d::TileMapAtlas::getTileAt);
mt["SetTile"]=static_cast<void(cocos2d::TileMapAtlas::*)(const cocos2d::Color3B&,const cocos2d::Vec2&)>(&cocos2d::TileMapAtlas::setTile);
mt["ReleaseMap"]=static_cast<void(cocos2d::TileMapAtlas::*)()>(&cocos2d::TileMapAtlas::releaseMap);
mt["GetTGAInfo"]=static_cast<cocos2d::sImageTGA*(cocos2d::TileMapAtlas::*)()const>(&cocos2d::TileMapAtlas::getTGAInfo);
mt["get"]["TGAInfo"]=mt["GetTGAInfo"];
mt["SetTGAInfo"]=static_cast<void(cocos2d::TileMapAtlas::*)(cocos2d::sImageTGA*)>(&cocos2d::TileMapAtlas::setTGAInfo);
mt["set"]["TGAInfo"]=mt["SetTGAInfo"];
}
void RegisterLuaCoreFastTMXLayerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FastTMXLayer).name()] = sol::usertype_traits<cocos2d::FastTMXLayer*>::metatable();
auto dep=lua.new_usertype<cocos2d::FastTMXLayer>("deprecated.cocos2d::FastTMXLayer");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FastTMXLayer*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["FastTMXLayer"]=mt;
mt["__new__"]=static_cast<cocos2d::FastTMXLayer*(*)(cocos2d::TMXTilesetInfo*,cocos2d::TMXLayerInfo*,cocos2d::TMXMapInfo*)>(&cocos2d::FastTMXLayer::create);
mt["GetTileGIDAt"]=sol::overload([](cocos2d::FastTMXLayer* obj,const cocos2d::Vec2& arg0,cocos2d::TMXTileFlags* arg1){return obj->getTileGIDAt(arg0,arg1);},[](cocos2d::FastTMXLayer* obj,const cocos2d::Vec2& arg0){return obj->getTileGIDAt(arg0);});
mt["SetTileGID"]=sol::overload(static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&,cocos2d::TMXTileFlags)>(&cocos2d::FastTMXLayer::setTileGID),static_cast<void(cocos2d::FastTMXLayer::*)(int,const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::setTileGID));
mt["RemoveTileAt"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::removeTileAt);
mt["GetPositionAt"]=static_cast<cocos2d::Vec2(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getPositionAt);
mt["GetProperty"]=static_cast<cocos2d::Value(cocos2d::FastTMXLayer::*)(const std::string&)const>(&cocos2d::FastTMXLayer::getProperty);
mt["SetupTiles"]=static_cast<void(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::setupTiles);
mt["GetLayerName"]=static_cast<const std::string&(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getLayerName);
mt["get"]["LayerName"]=mt["GetLayerName"];
mt["SetLayerName"]=static_cast<void(cocos2d::FastTMXLayer::*)(const std::string&)>(&cocos2d::FastTMXLayer::setLayerName);
mt["set"]["LayerName"]=mt["SetLayerName"];
mt["GetLayerSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerSize);
mt["get"]["LayerSize"]=mt["GetLayerSize"];
mt["SetLayerSize"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setLayerSize);
mt["set"]["LayerSize"]=mt["SetLayerSize"];
mt["GetMapTileSize"]=static_cast<const cocos2d::Size&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getMapTileSize);
mt["get"]["MapTileSize"]=mt["GetMapTileSize"];
mt["SetMapTileSize"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::Size&)>(&cocos2d::FastTMXLayer::setMapTileSize);
mt["set"]["MapTileSize"]=mt["SetMapTileSize"];
mt["GetTiles"]=static_cast<const uint32_t*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTiles);
mt["get"]["Tiles"]=mt["GetTiles"];
mt["SetTiles"]=static_cast<void(cocos2d::FastTMXLayer::*)(uint32_t*)>(&cocos2d::FastTMXLayer::setTiles);
mt["set"]["Tiles"]=mt["SetTiles"];
mt["GetTileSet"]=static_cast<cocos2d::TMXTilesetInfo*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileSet);
mt["get"]["TileSet"]=mt["GetTileSet"];
mt["SetTileSet"]=static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::TMXTilesetInfo*)>(&cocos2d::FastTMXLayer::setTileSet);
mt["set"]["TileSet"]=mt["SetTileSet"];
mt["GetLayerOrientation"]=static_cast<int(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getLayerOrientation);
mt["get"]["LayerOrientation"]=mt["GetLayerOrientation"];
mt["SetLayerOrientation"]=static_cast<void(cocos2d::FastTMXLayer::*)(int)>(&cocos2d::FastTMXLayer::setLayerOrientation);
mt["set"]["LayerOrientation"]=mt["SetLayerOrientation"];
mt["GetProperties"]=static_cast<const cocos2d::ValueMap&(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getProperties);
mt["get"]["Properties"]=mt["GetProperties"];
mt["SetProperties"]=static_cast<void(cocos2d::FastTMXLayer::*)(const cocos2d::ValueMap&)>(&cocos2d::FastTMXLayer::setProperties);
mt["set"]["Properties"]=mt["SetProperties"];
mt["GetTileAt"]=static_cast<cocos2d::Sprite*(cocos2d::FastTMXLayer::*)(const cocos2d::Vec2&)>(&cocos2d::FastTMXLayer::getTileAt);
mt["SetupTileSprite"]=static_cast<void(cocos2d::FastTMXLayer::*)(cocos2d::Sprite*,const cocos2d::Vec2&,uint32_t)>(&cocos2d::FastTMXLayer::setupTileSprite);
mt["GetAnimTileCoord"]=static_cast<const std::unordered_map<unsigned int, std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> >, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> > > > >*(cocos2d::FastTMXLayer::*)()>(&cocos2d::FastTMXLayer::getAnimTileCoord);
mt["get"]["AnimTileCoord"]=mt["GetAnimTileCoord"];
mt["HasTileAnimation"]=static_cast<bool(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::hasTileAnimation);
mt["GetTileAnimManager"]=static_cast<cocos2d::TMXTileAnimManager*(cocos2d::FastTMXLayer::*)()const>(&cocos2d::FastTMXLayer::getTileAnimManager);
mt["get"]["TileAnimManager"]=mt["GetTileAnimManager"];
mt["static"]["get"]["FAST_TMX_ORIENTATION_ORTHO"]=[]()->const int&{return cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ORTHO;};
mt["static"]["get"]["FAST_TMX_ORIENTATION_HEX"]=[]()->const int&{return cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_HEX;};
mt["static"]["get"]["FAST_TMX_ORIENTATION_ISO"]=[]()->const int&{return cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ISO;};
}
void RegisterLuaCoreTMXTileAnimTaskAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXTileAnimTask).name()] = sol::usertype_traits<cocos2d::TMXTileAnimTask*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXTileAnimTask>("deprecated.cocos2d::TMXTileAnimTask");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXTileAnimTask*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TMXTileAnimTask"]=mt;
mt["__new__"]=static_cast<cocos2d::TMXTileAnimTask*(*)(cocos2d::FastTMXLayer*,cocos2d::TMXTileAnimInfo*,const cocos2d::Vec2&)>(&cocos2d::TMXTileAnimTask::create);
mt["Start"]=static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::start);
mt["Stop"]=static_cast<void(cocos2d::TMXTileAnimTask::*)()>(&cocos2d::TMXTileAnimTask::stop);
mt["IsRunning"]=static_cast<bool(cocos2d::TMXTileAnimTask::*)()const>(&cocos2d::TMXTileAnimTask::isRunning);
mt["get"]["Running"]=mt["IsRunning"];
}
void RegisterLuaCoreTMXTileAnimManagerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TMXTileAnimManager).name()] = sol::usertype_traits<cocos2d::TMXTileAnimManager*>::metatable();
auto dep=lua.new_usertype<cocos2d::TMXTileAnimManager>("deprecated.cocos2d::TMXTileAnimManager");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TMXTileAnimManager*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["TMXTileAnimManager"]=mt;
mt["__new__"]=static_cast<cocos2d::TMXTileAnimManager*(*)(cocos2d::FastTMXLayer*)>(&cocos2d::TMXTileAnimManager::create);
mt["StartAll"]=static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::startAll);
mt["StopAll"]=static_cast<void(cocos2d::TMXTileAnimManager::*)()>(&cocos2d::TMXTileAnimManager::stopAll);
mt["GetTasks"]=static_cast<const cocos2d::Vector<cocos2d::TMXTileAnimTask *>&(cocos2d::TMXTileAnimManager::*)()const>(&cocos2d::TMXTileAnimManager::getTasks);
mt["get"]["Tasks"]=mt["GetTasks"];
}
}
