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
void RegisterLuaCoreFadeOutBLTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutBLTiles>("cc","FadeOutBLTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutBLTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutBLTiles::create));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutBLTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutBLTiles::testFunc));
mt.set_function("Clone",static_cast<cocos2d::FadeOutBLTiles*(cocos2d::FadeOutBLTiles::*)()const>(&cocos2d::FadeOutBLTiles::clone));
}
void RegisterLuaCoreFadeOutUpTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutUpTiles>("cc","FadeOutUpTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutUpTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutUpTiles::create));
mt.set_function("TransformTile",static_cast<void(cocos2d::FadeOutUpTiles::*)(const cocos2d::Vec2&,float)>(&cocos2d::FadeOutUpTiles::transformTile));
mt.set_function("Clone",static_cast<cocos2d::FadeOutUpTiles*(cocos2d::FadeOutUpTiles::*)()const>(&cocos2d::FadeOutUpTiles::clone));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutUpTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutUpTiles::testFunc));
}
void RegisterLuaCoreFadeOutDownTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FadeOutDownTiles>("cc","FadeOutDownTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::FadeOutUpTiles,cocos2d::FadeOutTRTiles,cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::FadeOutDownTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::FadeOutDownTiles::create));
mt.set_function("Clone",static_cast<cocos2d::FadeOutDownTiles*(cocos2d::FadeOutDownTiles::*)()const>(&cocos2d::FadeOutDownTiles::clone));
mt.set_function("TestFunc",static_cast<float(cocos2d::FadeOutDownTiles::*)(const cocos2d::Size&,float)>(&cocos2d::FadeOutDownTiles::testFunc));
}
void RegisterLuaCoreTurnOffTilesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TurnOffTiles>("cc","TurnOffTiles",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&,unsigned int)>(&cocos2d::TurnOffTiles::create),static_cast<cocos2d::TurnOffTiles*(*)(float,const cocos2d::Size&)>(&cocos2d::TurnOffTiles::create)));
mt.set_function("Shuffle",static_cast<void(cocos2d::TurnOffTiles::*)(unsigned int*,unsigned int)>(&cocos2d::TurnOffTiles::shuffle));
mt.set_function("TurnOnTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOnTile));
mt.set_function("TurnOffTile",static_cast<void(cocos2d::TurnOffTiles::*)(const cocos2d::Vec2&)>(&cocos2d::TurnOffTiles::turnOffTile));
mt.set_function("Clone",static_cast<cocos2d::TurnOffTiles*(cocos2d::TurnOffTiles::*)()const>(&cocos2d::TurnOffTiles::clone));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::TurnOffTiles::*)(cocos2d::Node*)>(&cocos2d::TurnOffTiles::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::TurnOffTiles::*)(float)>(&cocos2d::TurnOffTiles::update));
}
void RegisterLuaCoreJumpTiles3DAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::JumpTiles3D>("cc","JumpTiles3D",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::JumpTiles3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::JumpTiles3D::create));
mt.set_function("GetAmplitude",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitude));
mt.set_function("SetAmplitude",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitude));
mt.set_function("GetAmplitudeRate",static_cast<float(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::getAmplitudeRate));
mt.set_function("SetAmplitudeRate",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::setAmplitudeRate));
mt.set_function("Clone",static_cast<cocos2d::JumpTiles3D*(cocos2d::JumpTiles3D::*)()const>(&cocos2d::JumpTiles3D::clone));
mt.set_function("Update",static_cast<void(cocos2d::JumpTiles3D::*)(float)>(&cocos2d::JumpTiles3D::update));
}
void RegisterLuaCoreSplitRowsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitRows>("cc","SplitRows",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SplitRows*(*)(float,unsigned int)>(&cocos2d::SplitRows::create));
mt.set_function("Clone",static_cast<cocos2d::SplitRows*(cocos2d::SplitRows::*)()const>(&cocos2d::SplitRows::clone));
mt.set_function("Update",static_cast<void(cocos2d::SplitRows::*)(float)>(&cocos2d::SplitRows::update));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::SplitRows::*)(cocos2d::Node*)>(&cocos2d::SplitRows::startWithTarget));
}
void RegisterLuaCoreSplitColsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SplitCols>("cc","SplitCols",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::TiledGrid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::SplitCols*(*)(float,unsigned int)>(&cocos2d::SplitCols::create));
mt.set_function("Clone",static_cast<cocos2d::SplitCols*(cocos2d::SplitCols::*)()const>(&cocos2d::SplitCols::clone));
mt.set_function("Update",static_cast<void(cocos2d::SplitCols::*)(float)>(&cocos2d::SplitCols::update));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::SplitCols::*)(cocos2d::Node*)>(&cocos2d::SplitCols::startWithTarget));
}
void RegisterLuaCoreActionTweenDelegateAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionTweenDelegate>("cc","ActionTweenDelegate",true);
mt.set_function("UpdateTweenAction",static_cast<void(cocos2d::ActionTweenDelegate::*)(float,const std::string&)>(&cocos2d::ActionTweenDelegate::updateTweenAction));
}
void RegisterLuaCoreActionTweenAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionTween>("cc","ActionTween",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ActionTween*(*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ActionTween::*)(cocos2d::Node*)>(&cocos2d::ActionTween::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::ActionTween::*)(float)>(&cocos2d::ActionTween::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::reverse));
mt.set_function("Clone",static_cast<cocos2d::ActionTween*(cocos2d::ActionTween::*)()const>(&cocos2d::ActionTween::clone));
}
void RegisterLuaCoreAtlasNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AtlasNode>("cc","AtlasNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::AtlasNode*(*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::create));
mt.set_function("UpdateAtlasValues",static_cast<void(cocos2d::AtlasNode::*)()>(&cocos2d::AtlasNode::updateAtlasValues));
mt.set_function("Draw",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::AtlasNode::draw));
mt.set_function("GetTexture",static_cast<cocos2d::Texture2D*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTexture));
mt.set_function("SetTexture",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::Texture2D*)>(&cocos2d::AtlasNode::setTexture));
mt.set_function("IsOpacityModifyRGB",static_cast<bool(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::isOpacityModifyRGB));
mt.set_function("SetOpacityModifyRGB",static_cast<void(cocos2d::AtlasNode::*)(bool)>(&cocos2d::AtlasNode::setOpacityModifyRGB));
mt.set_function("GetColor",static_cast<const cocos2d::Color3B&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getColor));
mt.set_function("SetColor",static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::Color3B&)>(&cocos2d::AtlasNode::setColor));
mt.set_function("SetOpacity",static_cast<void(cocos2d::AtlasNode::*)(uint8_t)>(&cocos2d::AtlasNode::setOpacity));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::AtlasNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::AtlasNode::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getBlendFunc));
mt.set_function("SetTextureAtlas",static_cast<void(cocos2d::AtlasNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::AtlasNode::setTextureAtlas));
mt.set_function("GetTextureAtlas",static_cast<cocos2d::TextureAtlas*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTextureAtlas));
mt.set_function("SetQuadsToDraw",static_cast<void(cocos2d::AtlasNode::*)(ssize_t)>(&cocos2d::AtlasNode::setQuadsToDraw));
mt.set_function("GetQuadsToDraw",static_cast<size_t(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getQuadsToDraw));
mt.set_function("SetProgramState",sol::overload([](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0){return obj->setProgramState(arg0);},[](cocos2d::AtlasNode* obj,cocos2d::backend::ProgramState* arg0,bool arg1){return obj->setProgramState(arg0,arg1);}));
}
