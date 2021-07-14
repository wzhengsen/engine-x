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
void RegisterLuaCoreParticleRainAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ParticleRain).name()] = sol::usertype_traits<cocos2d::ParticleRain*>::metatable();
auto dep=lua.new_usertype<cocos2d::ParticleRain>("deprecated.cocos2d::ParticleRain");
dep[sol::base_classes]=sol::bases<cocos2d::ParticleSystemQuad,cocos2d::ParticleSystem,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::PlayableProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ParticleRain*>::metatable(),sol::usertype_traits<cocos2d::ParticleSystemQuad*>::metatable());
lua["cc"]["ParticleRain"]=mt;
mt["__new__"]=static_cast<cocos2d::ParticleRain*(*)()>(&cocos2d::ParticleRain::create);
mt["static"]["CreateWithTotalParticles"]=static_cast<cocos2d::ParticleRain*(*)(int)>(&cocos2d::ParticleRain::createWithTotalParticles);
}
void RegisterLuaCoreProgressTimerTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["RADIAL"]=cocos2d::ProgressTimer::Type::RADIAL;
enumTable["BAR"]=cocos2d::ProgressTimer::Type::BAR;
lua["cc"]["ProgressTimer"]["static"]["Type"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreProgressTimerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ProgressTimer).name()] = sol::usertype_traits<cocos2d::ProgressTimer*>::metatable();
auto dep=lua.new_usertype<cocos2d::ProgressTimer>("deprecated.cocos2d::ProgressTimer");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ProgressTimer*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ProgressTimer"]=mt;
mt["__new__"]=static_cast<cocos2d::ProgressTimer*(*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::create);
mt["GetType"]=static_cast<cocos2d::ProgressTimer::Type(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getType);
mt["get"]["Type"]=mt["GetType"];
mt["GetPercentage"]=static_cast<float(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getPercentage);
mt["get"]["Percentage"]=mt["GetPercentage"];
mt["GetSprite"]=static_cast<cocos2d::Sprite*(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getSprite);
mt["get"]["Sprite"]=mt["GetSprite"];
mt["SetPercentage"]=static_cast<void(cocos2d::ProgressTimer::*)(float)>(&cocos2d::ProgressTimer::setPercentage);
mt["set"]["Percentage"]=mt["SetPercentage"];
mt["SetSprite"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::Sprite*)>(&cocos2d::ProgressTimer::setSprite);
mt["set"]["Sprite"]=mt["SetSprite"];
mt["SetType"]=static_cast<void(cocos2d::ProgressTimer::*)(cocos2d::ProgressTimer::Type)>(&cocos2d::ProgressTimer::setType);
mt["set"]["Type"]=mt["SetType"];
mt["IsReverseDirection"]=static_cast<bool(cocos2d::ProgressTimer::*)()>(&cocos2d::ProgressTimer::isReverseDirection);
mt["get"]["ReverseDirection"]=mt["IsReverseDirection"];
mt["SetReverseDirection"]=static_cast<void(cocos2d::ProgressTimer::*)(bool)>(&cocos2d::ProgressTimer::setReverseDirection);
mt["set"]["ReverseDirection"]=mt["SetReverseDirection"];
mt["SetMidpoint"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setMidpoint);
mt["set"]["Midpoint"]=mt["SetMidpoint"];
mt["GetMidpoint"]=static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getMidpoint);
mt["get"]["Midpoint"]=mt["GetMidpoint"];
mt["SetBarChangeRate"]=static_cast<void(cocos2d::ProgressTimer::*)(const cocos2d::Vec2&)>(&cocos2d::ProgressTimer::setBarChangeRate);
mt["set"]["BarChangeRate"]=mt["SetBarChangeRate"];
mt["GetBarChangeRate"]=static_cast<cocos2d::Vec2(cocos2d::ProgressTimer::*)()const>(&cocos2d::ProgressTimer::getBarChangeRate);
mt["get"]["BarChangeRate"]=mt["GetBarChangeRate"];
RegisterLuaCoreProgressTimerTypeAuto(lua);
}
void RegisterLuaCoreProtectedNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ProtectedNode).name()] = sol::usertype_traits<cocos2d::ProtectedNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::ProtectedNode>("deprecated.cocos2d::ProtectedNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ProtectedNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ProtectedNode"]=mt;
mt["__new__"]=static_cast<cocos2d::ProtectedNode*(*)()>(&cocos2d::ProtectedNode::create);
mt["AddProtectedChild"]=sol::overload(static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*)>(&cocos2d::ProtectedNode::addProtectedChild));
mt["GetProtectedChildByTag"]=static_cast<cocos2d::Node*(cocos2d::ProtectedNode::*)(int)>(&cocos2d::ProtectedNode::getProtectedChildByTag);
mt["RemoveProtectedChild"]=sol::overload([](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0,bool arg1){return obj->removeProtectedChild(arg0,arg1);},[](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0){return obj->removeProtectedChild(arg0);});
mt["RemoveProtectedChildByTag"]=sol::overload([](cocos2d::ProtectedNode* obj,int arg0,bool arg1){return obj->removeProtectedChildByTag(arg0,arg1);},[](cocos2d::ProtectedNode* obj,int arg0){return obj->removeProtectedChildByTag(arg0);});
mt["RemoveAllProtectedChildren"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::removeAllProtectedChildren);
mt["RemoveAllProtectedChildrenWithCleanup"]=static_cast<void(cocos2d::ProtectedNode::*)(bool)>(&cocos2d::ProtectedNode::removeAllProtectedChildrenWithCleanup);
mt["ReorderProtectedChild"]=static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::reorderProtectedChild);
mt["SortAllProtectedChildren"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::sortAllProtectedChildren);
mt["DisableCascadeColor"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeColor);
mt["DisableCascadeOpacity"]=static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeOpacity);
}
void RegisterLuaCoreSpriteRenderModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["QUAD"]=cocos2d::Sprite::RenderMode::QUAD;
enumTable["POLYGON"]=cocos2d::Sprite::RenderMode::POLYGON;
enumTable["SLICE9"]=cocos2d::Sprite::RenderMode::SLICE9;
enumTable["QUAD_BATCHNODE"]=cocos2d::Sprite::RenderMode::QUAD_BATCHNODE;
lua["cc"]["Sprite"]["static"]["RenderMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreSpriteAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Sprite).name()] = sol::usertype_traits<cocos2d::Sprite*>::metatable();
auto dep=lua.new_usertype<cocos2d::Sprite>("deprecated.cocos2d::Sprite");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Sprite*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::TextureProtocol*>::metatable());
lua["cc"]["Sprite"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::Sprite*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::Sprite::create),static_cast<cocos2d::Sprite*(*)(const cocos2d::PolygonInfo&)>(&cocos2d::Sprite::create),static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::create),static_cast<cocos2d::Sprite*(*)()>(&cocos2d::Sprite::create));
mt["static"]["CreateWithTexture"]=sol::overload([](cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1,bool arg2){return cocos2d::Sprite::createWithTexture(arg0,arg1,arg2);},[](cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1){return cocos2d::Sprite::createWithTexture(arg0,arg1);},static_cast<cocos2d::Sprite*(*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::createWithTexture));
mt["static"]["CreateWithSpriteFrame"]=static_cast<cocos2d::Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::createWithSpriteFrame);
mt["static"]["CreateWithSpriteFrameName"]=static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::createWithSpriteFrameName);
mt["GetBatchNode"]=static_cast<cocos2d::SpriteBatchNode*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBatchNode);
mt["get"]["BatchNode"]=mt["GetBatchNode"];
mt["SetBatchNode"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteBatchNode*)>(&cocos2d::Sprite::setBatchNode);
mt["set"]["BatchNode"]=mt["SetBatchNode"];
mt["SetTexture"]=sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::setTexture),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setTexture));
mt["set"]["Texture"]=mt["SetTexture"];
mt["SetTextureRect"]=sol::overload(static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&,bool,const cocos2d::Size&)>(&cocos2d::Sprite::setTextureRect),static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setTextureRect));
mt["set"]["TextureRect"]=mt["SetTextureRect"];
mt["SetVertexRect"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setVertexRect);
mt["set"]["VertexRect"]=mt["SetVertexRect"];
mt["SetCenterRectNormalized"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRectNormalized);
mt["set"]["CenterRectNormalized"]=mt["SetCenterRectNormalized"];
mt["GetCenterRectNormalized"]=static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRectNormalized);
mt["get"]["CenterRectNormalized"]=mt["GetCenterRectNormalized"];
mt["SetCenterRect"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRect);
mt["set"]["CenterRect"]=mt["SetCenterRect"];
mt["GetCenterRect"]=static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRect);
mt["get"]["CenterRect"]=mt["GetCenterRect"];
mt["SetSpriteFrame"]=sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::setSpriteFrame),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setSpriteFrame));
mt["set"]["SpriteFrame"]=mt["SetSpriteFrame"];
mt["IsFrameDisplayed"]=static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)const>(&cocos2d::Sprite::isFrameDisplayed);
mt["GetSpriteFrame"]=static_cast<cocos2d::SpriteFrame*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getSpriteFrame);
mt["get"]["SpriteFrame"]=mt["GetSpriteFrame"];
mt["SetDisplayFrameWithAnimationName"]=static_cast<void(cocos2d::Sprite::*)(const std::string&,unsigned int)>(&cocos2d::Sprite::setDisplayFrameWithAnimationName);
mt["IsDirty"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isDirty);
mt["get"]["Dirty"]=mt["IsDirty"];
mt["SetDirty"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setDirty);
mt["set"]["Dirty"]=mt["SetDirty"];
mt["GetQuad"]=static_cast<cocos2d::V3F_C4B_T2F_Quad(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getQuad);
mt["get"]["Quad"]=mt["GetQuad"];
mt["IsTextureRectRotated"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isTextureRectRotated);
mt["get"]["TextureRectRotated"]=mt["IsTextureRectRotated"];
mt["GetAtlasIndex"]=static_cast<unsigned int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getAtlasIndex);
mt["get"]["AtlasIndex"]=mt["GetAtlasIndex"];
mt["SetAtlasIndex"]=static_cast<void(cocos2d::Sprite::*)(unsigned int)>(&cocos2d::Sprite::setAtlasIndex);
mt["set"]["AtlasIndex"]=mt["SetAtlasIndex"];
mt["GetTextureRect"]=static_cast<const cocos2d::Rect&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureRect);
mt["get"]["TextureRect"]=mt["GetTextureRect"];
mt["GetTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureAtlas);
mt["get"]["TextureAtlas"]=mt["GetTextureAtlas"];
mt["SetTextureAtlas"]=static_cast<void(cocos2d::Sprite::*)(cocos2d::TextureAtlas*)>(&cocos2d::Sprite::setTextureAtlas);
mt["set"]["TextureAtlas"]=mt["SetTextureAtlas"];
mt["GetOffsetPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getOffsetPosition);
mt["get"]["OffsetPosition"]=mt["GetOffsetPosition"];
mt["IsFlippedX"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedX);
mt["get"]["FlippedX"]=mt["IsFlippedX"];
mt["SetFlippedX"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedX);
mt["set"]["FlippedX"]=mt["SetFlippedX"];
mt["IsFlippedY"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedY);
mt["get"]["FlippedY"]=mt["IsFlippedY"];
mt["SetFlippedY"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedY);
mt["set"]["FlippedY"]=mt["SetFlippedY"];
mt["GetPolygonInfo"]=static_cast<const cocos2d::PolygonInfo&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getPolygonInfo);
mt["get"]["PolygonInfo"]=mt["GetPolygonInfo"];
mt["SetPolygonInfo"]=static_cast<void(cocos2d::Sprite::*)(const cocos2d::PolygonInfo&)>(&cocos2d::Sprite::setPolygonInfo);
mt["set"]["PolygonInfo"]=mt["SetPolygonInfo"];
mt["SetStretchEnabled"]=static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setStretchEnabled);
mt["set"]["StretchEnabled"]=mt["SetStretchEnabled"];
mt["IsStretchEnabled"]=static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isStretchEnabled);
mt["get"]["StretchEnabled"]=mt["IsStretchEnabled"];
mt["GetResourceType"]=static_cast<int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceType);
mt["get"]["ResourceType"]=mt["GetResourceType"];
mt["GetResourceName"]=static_cast<const std::string&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceName);
mt["get"]["ResourceName"]=mt["GetResourceName"];
mt["SetVertexLayout"]=static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::setVertexLayout);
mt["static"]["get"]["INDEX_NOT_INITIALIZED"]=[]()->const int&{return cocos2d::Sprite::INDEX_NOT_INITIALIZED;};
RegisterLuaCoreSpriteRenderModeAuto(lua);
}
void RegisterLuaCoreRenderTextureAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::RenderTexture).name()] = sol::usertype_traits<cocos2d::RenderTexture*>::metatable();
auto dep=lua.new_usertype<cocos2d::RenderTexture>("deprecated.cocos2d::RenderTexture");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::RenderTexture*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["RenderTexture"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int)>(&cocos2d::RenderTexture::create));
mt["Begin"]=static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::begin);
mt["BeginWithClear"]=sol::overload(static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float,int)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear));
mt["End"]=static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::end);
mt["Clear"]=static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::clear);
mt["ClearDepth"]=static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::clearDepth);
mt["ClearStencil"]=static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::clearStencil);
mt["SaveToFileAsNonPMA"]=sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(const std::string&,cocos2d::Image::Format,bool,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>)>(&cocos2d::RenderTexture::saveToFileAsNonPMA),[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)> arg2){return obj->saveToFileAsNonPMA(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFileAsNonPMA(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFileAsNonPMA(arg0);});
mt["SaveToFile"]=sol::overload([](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)> arg3){return obj->saveToFile(arg0,arg1,arg2,arg3);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)> arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFile(arg0);});
mt["ListenToBackground"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::EventCustom*)>(&cocos2d::RenderTexture::listenToBackground);
mt["ListenToForeground"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::EventCustom*)>(&cocos2d::RenderTexture::listenToForeground);
mt["GetClearFlags"]=static_cast<cocos2d::ClearFlag(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearFlags);
mt["get"]["ClearFlags"]=mt["GetClearFlags"];
mt["SetClearFlags"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::ClearFlag)>(&cocos2d::RenderTexture::setClearFlags);
mt["set"]["ClearFlags"]=mt["SetClearFlags"];
mt["GetClearColor"]=static_cast<const cocos2d::Color4F&(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearColor);
mt["get"]["ClearColor"]=mt["GetClearColor"];
mt["SetClearColor"]=static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Color4F&)>(&cocos2d::RenderTexture::setClearColor);
mt["set"]["ClearColor"]=mt["SetClearColor"];
mt["GetClearDepth"]=static_cast<float(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearDepth);
mt["get"]["ClearDepth"]=mt["GetClearDepth"];
mt["SetClearDepth"]=static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::setClearDepth);
mt["set"]["ClearDepth"]=mt["SetClearDepth"];
mt["GetClearStencil"]=static_cast<int(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearStencil);
mt["get"]["ClearStencil"]=mt["GetClearStencil"];
mt["SetClearStencil"]=static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::setClearStencil);
mt["set"]["ClearStencil"]=mt["SetClearStencil"];
mt["IsAutoDraw"]=static_cast<bool(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::isAutoDraw);
mt["get"]["AutoDraw"]=mt["IsAutoDraw"];
mt["SetAutoDraw"]=static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setAutoDraw);
mt["set"]["AutoDraw"]=mt["SetAutoDraw"];
mt["GetSprite"]=static_cast<cocos2d::Sprite*(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getSprite);
mt["get"]["Sprite"]=mt["GetSprite"];
mt["SetSprite"]=static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Sprite*)>(&cocos2d::RenderTexture::setSprite);
mt["set"]["Sprite"]=mt["SetSprite"];
mt["SetKeepMatrix"]=static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setKeepMatrix);
mt["set"]["KeepMatrix"]=mt["SetKeepMatrix"];
mt["SetVirtualViewport"]=static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Vec2&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::RenderTexture::setVirtualViewport);
mt["InitWithWidthAndHeight"]=sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight),static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight));
}
void RegisterLuaCoreTransitionEaseSceneAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionEaseScene).name()] = sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionEaseScene>("deprecated.cocos2d::TransitionEaseScene");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionEaseScene*>::metatable());
lua["cc"]["TransitionEaseScene"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["EaseActionWithAction"]=static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction);
}
void RegisterLuaCoreTransitionSceneOrientationAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["LEFT_OVER"]=cocos2d::TransitionScene::Orientation::LEFT_OVER;
enumTable["RIGHT_OVER"]=cocos2d::TransitionScene::Orientation::RIGHT_OVER;
enumTable["UP_OVER"]=cocos2d::TransitionScene::Orientation::UP_OVER;
enumTable["DOWN_OVER"]=cocos2d::TransitionScene::Orientation::DOWN_OVER;
lua["cc"]["TransitionScene"]["static"]["Orientation"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreTransitionSceneAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionScene).name()] = sol::usertype_traits<cocos2d::TransitionScene*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionScene>("deprecated.cocos2d::TransitionScene");
dep[sol::base_classes]=sol::bases<cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionScene*>::metatable(),sol::usertype_traits<cocos2d::Scene*>::metatable());
lua["cc"]["TransitionScene"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create);
mt["Finish"]=static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish);
mt["HideOutShowIn"]=static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn);
mt["GetInScene"]=static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene);
mt["get"]["InScene"]=mt["GetInScene"];
mt["GetDuration"]=static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration);
mt["get"]["Duration"]=mt["GetDuration"];
RegisterLuaCoreTransitionSceneOrientationAuto(lua);
}
void RegisterLuaCoreTransitionSceneOrientedAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionSceneOriented).name()] = sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionSceneOriented>("deprecated.cocos2d::TransitionSceneOriented");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionSceneOriented*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionSceneOriented"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create);
}
void RegisterLuaCoreTransitionRotoZoomAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionRotoZoom).name()] = sol::usertype_traits<cocos2d::TransitionRotoZoom*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionRotoZoom>("deprecated.cocos2d::TransitionRotoZoom");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionRotoZoom*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionRotoZoom"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create);
}
void RegisterLuaCoreTransitionJumpZoomAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::TransitionJumpZoom).name()] = sol::usertype_traits<cocos2d::TransitionJumpZoom*>::metatable();
auto dep=lua.new_usertype<cocos2d::TransitionJumpZoom>("deprecated.cocos2d::TransitionJumpZoom");
dep[sol::base_classes]=sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::TransitionJumpZoom*>::metatable(),sol::usertype_traits<cocos2d::TransitionScene*>::metatable());
lua["cc"]["TransitionJumpZoom"]=mt;
mt["__new__"]=static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create);
}
}
