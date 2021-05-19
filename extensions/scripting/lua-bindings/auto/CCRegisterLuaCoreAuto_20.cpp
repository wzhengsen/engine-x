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
void RegisterLuaCoreProtectedNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ProtectedNode>("cc","ProtectedNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ProtectedNode*(*)()>(&cocos2d::ProtectedNode::create));
mt.set_function("AddProtectedChild",sol::overload(static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*)>(&cocos2d::ProtectedNode::addProtectedChild),static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int,int)>(&cocos2d::ProtectedNode::addProtectedChild)));
mt.set_function("GetProtectedChildByTag",static_cast<cocos2d::Node*(cocos2d::ProtectedNode::*)(int)>(&cocos2d::ProtectedNode::getProtectedChildByTag));
mt.set_function("RemoveProtectedChild",sol::overload([](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0){return obj->removeProtectedChild(arg0);},[](cocos2d::ProtectedNode* obj,cocos2d::Node* arg0,bool arg1){return obj->removeProtectedChild(arg0,arg1);}));
mt.set_function("RemoveProtectedChildByTag",sol::overload([](cocos2d::ProtectedNode* obj,int arg0){return obj->removeProtectedChildByTag(arg0);},[](cocos2d::ProtectedNode* obj,int arg0,bool arg1){return obj->removeProtectedChildByTag(arg0,arg1);}));
mt.set_function("RemoveAllProtectedChildren",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::removeAllProtectedChildren));
mt.set_function("RemoveAllProtectedChildrenWithCleanup",static_cast<void(cocos2d::ProtectedNode::*)(bool)>(&cocos2d::ProtectedNode::removeAllProtectedChildrenWithCleanup));
mt.set_function("ReorderProtectedChild",static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Node*,int)>(&cocos2d::ProtectedNode::reorderProtectedChild));
mt.set_function("SortAllProtectedChildren",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::sortAllProtectedChildren));
mt.set_function("Visit",static_cast<void(cocos2d::ProtectedNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ProtectedNode::visit));
mt.set_function("Cleanup",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::cleanup));
mt.set_function("OnEnter",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::onEnter));
mt.set_function("OnEnterTransitionDidFinish",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::onEnterTransitionDidFinish));
mt.set_function("OnExit",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::onExit));
mt.set_function("OnExitTransitionDidStart",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::onExitTransitionDidStart));
mt.set_function("UpdateDisplayedOpacity",static_cast<void(cocos2d::ProtectedNode::*)(uint8_t)>(&cocos2d::ProtectedNode::updateDisplayedOpacity));
mt.set_function("UpdateDisplayedColor",static_cast<void(cocos2d::ProtectedNode::*)(const cocos2d::Color3B&)>(&cocos2d::ProtectedNode::updateDisplayedColor));
mt.set_function("DisableCascadeColor",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeColor));
mt.set_function("DisableCascadeOpacity",static_cast<void(cocos2d::ProtectedNode::*)()>(&cocos2d::ProtectedNode::disableCascadeOpacity));
mt.set_function("SetCameraMask",sol::overload([](cocos2d::ProtectedNode* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ProtectedNode* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("SetGlobalZOrder",static_cast<void(cocos2d::ProtectedNode::*)(float)>(&cocos2d::ProtectedNode::setGlobalZOrder));
}
void RegisterLuaCoreSpriteRenderModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Sprite"];
pTable.new_enum<cocos2d::Sprite::RenderMode>("RenderMode",{
{"QUAD",cocos2d::Sprite::RenderMode::QUAD}
,{"POLYGON",cocos2d::Sprite::RenderMode::POLYGON}
,{"SLICE9",cocos2d::Sprite::RenderMode::SLICE9}
,{"QUAD_BATCHNODE",cocos2d::Sprite::RenderMode::QUAD_BATCHNODE}
});}
void RegisterLuaCoreSpriteAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sprite>("cc","Sprite",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::create),static_cast<cocos2d::Sprite*(*)()>(&cocos2d::Sprite::create),static_cast<cocos2d::Sprite*(*)(const cocos2d::PolygonInfo&)>(&cocos2d::Sprite::create),static_cast<cocos2d::Sprite*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::Sprite::create)));
mt.set_function("CreateWithTexture",sol::overload([](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1){return obj->createWithTexture(arg0,arg1);},[](cocos2d::Sprite* obj,cocos2d::Texture2D* arg0,const cocos2d::Rect& arg1,bool arg2){return obj->createWithTexture(arg0,arg1,arg2);},static_cast<cocos2d::Sprite*(*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::createWithTexture)));
mt.set_function("CreateWithSpriteFrame",static_cast<cocos2d::Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::createWithSpriteFrame));
mt.set_function("CreateWithSpriteFrameName",static_cast<cocos2d::Sprite*(*)(const std::string&)>(&cocos2d::Sprite::createWithSpriteFrameName));
mt.set_function("UpdateTransform",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::updateTransform));
mt.set_function("GetBatchNode",static_cast<cocos2d::SpriteBatchNode*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBatchNode));
mt.set_function("SetBatchNode",static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteBatchNode*)>(&cocos2d::Sprite::setBatchNode));
mt.set_function("SetTexture",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Texture2D*)>(&cocos2d::Sprite::setTexture),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setTexture)));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTexture));
mt.set_function("SetTextureRect",sol::overload(static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&,bool,const cocos2d::Size&)>(&cocos2d::Sprite::setTextureRect),static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setTextureRect)));
mt.set_function("SetVertexRect",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setVertexRect));
mt.set_function("SetCenterRectNormalized",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRectNormalized));
mt.set_function("GetCenterRectNormalized",static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRectNormalized));
mt.set_function("SetCenterRect",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Rect&)>(&cocos2d::Sprite::setCenterRect));
mt.set_function("GetCenterRect",static_cast<cocos2d::Rect(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getCenterRect));
mt.set_function("SetSpriteFrame",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)>(&cocos2d::Sprite::setSpriteFrame),static_cast<void(cocos2d::Sprite::*)(const std::string&)>(&cocos2d::Sprite::setSpriteFrame)));
mt.set_function("IsFrameDisplayed",static_cast<bool(cocos2d::Sprite::*)(cocos2d::SpriteFrame*)const>(&cocos2d::Sprite::isFrameDisplayed));
mt.set_function("GetSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getSpriteFrame));
mt.set_function("SetDisplayFrameWithAnimationName",static_cast<void(cocos2d::Sprite::*)(const std::string&,unsigned int)>(&cocos2d::Sprite::setDisplayFrameWithAnimationName));
mt.set_function("IsDirty",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isDirty));
mt.set_function("SetDirty",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setDirty));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getDescription));
mt.set_function("SetScaleX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleX));
mt.set_function("SetScaleY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScaleY));
mt.set_function("SetScale",sol::overload(static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setScale),static_cast<void(cocos2d::Sprite::*)(float,float)>(&cocos2d::Sprite::setScale)));
mt.set_function("SetPosition",sol::overload(static_cast<void(cocos2d::Sprite::*)(float,float)>(&cocos2d::Sprite::setPosition),static_cast<void(cocos2d::Sprite::*)(const cocos2d::Vec2&)>(&cocos2d::Sprite::setPosition)));
mt.set_function("SetRotation",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotation));
mt.set_function("SetRotationSkewX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewX));
mt.set_function("SetRotationSkewY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setRotationSkewY));
mt.set_function("SetSkewX",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewX));
mt.set_function("SetSkewY",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setSkewY));
mt.set_function("RemoveChild",static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,bool)>(&cocos2d::Sprite::removeChild));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::removeAllChildrenWithCleanup));
mt.set_function("ReorderChild",static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int)>(&cocos2d::Sprite::reorderChild));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::Sprite::addChild),static_cast<void(cocos2d::Sprite::*)(cocos2d::Node*,int,int)>(&cocos2d::Sprite::addChild)));
mt.set_function("SortAllChildren",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::sortAllChildren));
mt.set_function("SetPositionZ",static_cast<void(cocos2d::Sprite::*)(float)>(&cocos2d::Sprite::setPositionZ));
mt.set_function("SetAnchorPoint",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Vec2&)>(&cocos2d::Sprite::setAnchorPoint));
mt.set_function("SetContentSize",static_cast<void(cocos2d::Sprite::*)(const cocos2d::Size&)>(&cocos2d::Sprite::setContentSize));
mt.set_function("SetIgnoreAnchorPointForPosition",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setIgnoreAnchorPointForPosition));
mt.set_function("SetVisible",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setVisible));
mt.set_function("Draw",static_cast<void(cocos2d::Sprite::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::Sprite::draw));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setOpacityModifyRGB));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isOpacityModifyRGB));
mt.set_function("GetQuad",static_cast<cocos2d::V3F_C4B_T2F_Quad(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getQuad));
mt.set_function("IsTextureRectRotated",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isTextureRectRotated));
mt.set_function("GetAtlasIndex",static_cast<unsigned int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getAtlasIndex));
mt.set_function("SetAtlasIndex",static_cast<void(cocos2d::Sprite::*)(unsigned int)>(&cocos2d::Sprite::setAtlasIndex));
mt.set_function("GetTextureRect",static_cast<const cocos2d::Rect&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureRect));
mt.set_function("GetTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getTextureAtlas));
mt.set_function("SetProgramState",sol::overload(static_cast<void(cocos2d::Sprite::*)(uint32_t)>(&cocos2d::Sprite::setProgramState),[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::Sprite* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
mt.set_function("SetTextureAtlas",static_cast<void(cocos2d::Sprite::*)(cocos2d::TextureAtlas*)>(&cocos2d::Sprite::setTextureAtlas));
mt.set_function("GetOffsetPosition",static_cast<const cocos2d::Vec2&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getOffsetPosition));
mt.set_function("IsFlippedX",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedX));
mt.set_function("SetFlippedX",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedX));
mt.set_function("IsFlippedY",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isFlippedY));
mt.set_function("SetFlippedY",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setFlippedY));
mt.set_function("GetPolygonInfo",static_cast<const cocos2d::PolygonInfo&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getPolygonInfo));
mt.set_function("SetPolygonInfo",static_cast<void(cocos2d::Sprite::*)(const cocos2d::PolygonInfo&)>(&cocos2d::Sprite::setPolygonInfo));
mt.set_function("SetStretchEnabled",static_cast<void(cocos2d::Sprite::*)(bool)>(&cocos2d::Sprite::setStretchEnabled));
mt.set_function("IsStretchEnabled",static_cast<bool(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::isStretchEnabled));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::Sprite::*)(const cocos2d::BlendFunc&)>(&cocos2d::Sprite::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getBlendFunc));
mt.set_function("GetResourceType",static_cast<int(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceType));
mt.set_function("GetResourceName",static_cast<const std::string&(cocos2d::Sprite::*)()const>(&cocos2d::Sprite::getResourceName));
mt.set_function("SetVertexLayout",static_cast<void(cocos2d::Sprite::*)()>(&cocos2d::Sprite::setVertexLayout));
mt["INDEX_NOT_INITIALIZED"]=sol::var(std::ref(cocos2d::Sprite::INDEX_NOT_INITIALIZED));
RegisterLuaCoreSpriteRenderModeAuto(lua);
}
void RegisterLuaCoreRenderTextureAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RenderTexture>("cc","RenderTexture",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int)>(&cocos2d::RenderTexture::create)));
mt.set_function("Visit",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::visit));
mt.set_function("Draw",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::draw));
mt.set_function("Begin",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::begin));
mt.set_function("BeginWithClear",sol::overload(static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float,int)>(&cocos2d::RenderTexture::beginWithClear)));
mt.set_function("End",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::end));
mt.set_function("Clear",static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::clear));
mt.set_function("ClearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::clearDepth));
mt.set_function("ClearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::clearStencil));
mt.set_function("SaveToFileAsNonPMA",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(const std::string&,cocos2d::Image::Format,bool,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>)>(&cocos2d::RenderTexture::saveToFileAsNonPMA),[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFileAsNonPMA(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFileAsNonPMA(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)> arg2){return obj->saveToFileAsNonPMA(arg0,arg1,arg2);}));
mt.set_function("SaveToFile",sol::overload([](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)> arg3){return obj->saveToFile(arg0,arg1,arg2,arg3);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)> arg2){return obj->saveToFile(arg0,arg1,arg2);}));
mt.set_function("ListenToBackground",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::EventCustom*)>(&cocos2d::RenderTexture::listenToBackground));
mt.set_function("ListenToForeground",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::EventCustom*)>(&cocos2d::RenderTexture::listenToForeground));
mt.set_function("GetClearFlags",static_cast<cocos2d::ClearFlag(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearFlags));
mt.set_function("SetClearFlags",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::ClearFlag)>(&cocos2d::RenderTexture::setClearFlags));
mt.set_function("GetClearColor",static_cast<const cocos2d::Color4F&(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearColor));
mt.set_function("SetClearColor",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Color4F&)>(&cocos2d::RenderTexture::setClearColor));
mt.set_function("GetClearDepth",static_cast<float(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearDepth));
mt.set_function("SetClearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::setClearDepth));
mt.set_function("GetClearStencil",static_cast<int(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearStencil));
mt.set_function("SetClearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::setClearStencil));
mt.set_function("IsAutoDraw",static_cast<bool(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::isAutoDraw));
mt.set_function("SetAutoDraw",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setAutoDraw));
mt.set_function("GetSprite",static_cast<cocos2d::Sprite*(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getSprite));
mt.set_function("SetSprite",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Sprite*)>(&cocos2d::RenderTexture::setSprite));
mt.set_function("SetKeepMatrix",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setKeepMatrix));
mt.set_function("SetVirtualViewport",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Vec2&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::RenderTexture::setVirtualViewport));
mt.set_function("InitWithWidthAndHeight",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight),static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight)));
mt[sol::call_constructor]=sol::constructors<cocos2d::RenderTexture()>();
}
void RegisterLuaCoreTransitionEaseSceneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionEaseScene>("cc","TransitionEaseScene",true);
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction));
}
void RegisterLuaCoreTransitionSceneOrientationAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TransitionScene"];
pTable.new_enum<cocos2d::TransitionScene::Orientation>("Orientation",{
{"LEFT_OVER",cocos2d::TransitionScene::Orientation::LEFT_OVER}
,{"RIGHT_OVER",cocos2d::TransitionScene::Orientation::RIGHT_OVER}
,{"UP_OVER",cocos2d::TransitionScene::Orientation::UP_OVER}
,{"DOWN_OVER",cocos2d::TransitionScene::Orientation::DOWN_OVER}
});}
void RegisterLuaCoreTransitionSceneAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionScene>("cc","TransitionScene",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create));
mt.set_function("Finish",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish));
mt.set_function("HideOutShowIn",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn));
mt.set_function("GetInScene",static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene));
mt.set_function("GetDuration",static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration));
mt.set_function("Draw",static_cast<void(cocos2d::TransitionScene::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionScene::draw));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::onExit));
mt.set_function("Cleanup",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::cleanup));
RegisterLuaCoreTransitionSceneOrientationAuto(lua);
}
void RegisterLuaCoreTransitionSceneOrientedAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSceneOriented>("cc","TransitionSceneOriented",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create));
}
void RegisterLuaCoreTransitionRotoZoomAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionRotoZoom>("cc","TransitionRotoZoom",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionRotoZoom::*)()>(&cocos2d::TransitionRotoZoom::onEnter));
}
void RegisterLuaCoreTransitionJumpZoomAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionJumpZoom>("cc","TransitionJumpZoom",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionJumpZoom::*)()>(&cocos2d::TransitionJumpZoom::onEnter));
}
void RegisterLuaCoreTransitionMoveInLAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInL>("cc","TransitionMoveInL",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create));
mt.set_function("Action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action));
mt.set_function("EaseActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction));
mt.set_function("OnEnter",static_cast<void(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::onEnter));
}
void RegisterLuaCoreTransitionMoveInRAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInR>("cc","TransitionMoveInR",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TransitionEaseScene>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create));
}
