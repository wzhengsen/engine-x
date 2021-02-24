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
void RegisterLuaCoreRenderTextureAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RenderTexture,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","RenderTexture");
mt.set_function("visit",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::visit));
mt.set_function("draw",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::RenderTexture::draw));
mt.set_function("begin",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::begin));
mt.set_function("beginWithClear",sol::overload(static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::beginWithClear),static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float,float,int)>(&cocos2d::RenderTexture::beginWithClear)));
mt.set_function("endToLua",static_cast<void(cocos2d::RenderTexture::*)()>(&cocos2d::RenderTexture::end));
mt.set_function("clear",static_cast<void(cocos2d::RenderTexture::*)(float,float,float,float)>(&cocos2d::RenderTexture::clear));
mt.set_function("clearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::clearDepth));
mt.set_function("clearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::clearStencil));
mt.set_function("saveToFileAsNonPMA",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(const std::string&,cocos2d::Image::Format,bool,std::function<void (cocos2d::RenderTexture *, const std::string&)>)>(&cocos2d::RenderTexture::saveToFileAsNonPMA),[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFileAsNonPMA(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFileAsNonPMA(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFileAsNonPMA(arg0,arg1,arg2);}));
mt.set_function("saveToFile",sol::overload([](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2){return obj->saveToFile(arg0,arg1,arg2);},[](cocos2d::RenderTexture* obj,const std::string& arg0,cocos2d::Image::Format arg1,bool arg2,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg3){return obj->saveToFile(arg0,arg1,arg2,arg3);},[](cocos2d::RenderTexture* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);},[](cocos2d::RenderTexture* obj,const std::string& arg0,bool arg1,std::function<void (cocos2d::RenderTexture *, const std::string&)> arg2){return obj->saveToFile(arg0,arg1,arg2);}));
mt.set_function("listenToBackground",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::EventCustom*)>(&cocos2d::RenderTexture::listenToBackground));
mt.set_function("listenToForeground",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::EventCustom*)>(&cocos2d::RenderTexture::listenToForeground));
mt.set_function("getClearFlags",static_cast<cocos2d::ClearFlag(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearFlags));
mt.set_function("setClearFlags",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::ClearFlag)>(&cocos2d::RenderTexture::setClearFlags));
mt.set_function("getClearColor",static_cast<const cocos2d::Color4F&(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearColor));
mt.set_function("setClearColor",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Color4F&)>(&cocos2d::RenderTexture::setClearColor));
mt.set_function("getClearDepth",static_cast<float(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearDepth));
mt.set_function("setClearDepth",static_cast<void(cocos2d::RenderTexture::*)(float)>(&cocos2d::RenderTexture::setClearDepth));
mt.set_function("getClearStencil",static_cast<int(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getClearStencil));
mt.set_function("setClearStencil",static_cast<void(cocos2d::RenderTexture::*)(int)>(&cocos2d::RenderTexture::setClearStencil));
mt.set_function("isAutoDraw",static_cast<bool(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::isAutoDraw));
mt.set_function("setAutoDraw",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setAutoDraw));
mt.set_function("getSprite",static_cast<cocos2d::Sprite*(cocos2d::RenderTexture::*)()const>(&cocos2d::RenderTexture::getSprite));
mt.set_function("setSprite",static_cast<void(cocos2d::RenderTexture::*)(cocos2d::Sprite*)>(&cocos2d::RenderTexture::setSprite));
mt.set_function("setKeepMatrix",static_cast<void(cocos2d::RenderTexture::*)(bool)>(&cocos2d::RenderTexture::setKeepMatrix));
mt.set_function("setVirtualViewport",static_cast<void(cocos2d::RenderTexture::*)(const cocos2d::Vec2&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::RenderTexture::setVirtualViewport));
mt.set_function("initWithWidthAndHeight",sol::overload(static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight),static_cast<bool(cocos2d::RenderTexture::*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::initWithWidthAndHeight)));
mt.set_function("new",sol::overload(static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int,cocos2d::backend::PixelFormat,cocos2d::backend::PixelFormat)>(&cocos2d::RenderTexture::create),static_cast<cocos2d::RenderTexture*(*)(int,int)>(&cocos2d::RenderTexture::create)));
}
void RegisterLuaCoreTransitionEaseSceneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionEaseScene>("cc","TransitionEaseScene");
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionEaseScene::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionEaseScene::easeActionWithAction));
}
void RegisterLuaCoreTransitionSceneAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionScene");
mt.set_function("finish",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::finish));
mt.set_function("hideOutShowIn",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::hideOutShowIn));
mt.set_function("getInScene",static_cast<cocos2d::Scene*(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getInScene));
mt.set_function("getDuration",static_cast<float(cocos2d::TransitionScene::*)()const>(&cocos2d::TransitionScene::getDuration));
mt.set_function("draw",static_cast<void(cocos2d::TransitionScene::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::TransitionScene::draw));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::onExit));
mt.set_function("cleanup",static_cast<void(cocos2d::TransitionScene::*)()>(&cocos2d::TransitionScene::cleanup));
mt.set_function("new",static_cast<cocos2d::TransitionScene*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionScene::create));
}
void RegisterLuaCoreTransitionSceneOrientedAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionSceneOriented,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionSceneOriented");
mt.set_function("new",static_cast<cocos2d::TransitionSceneOriented*(*)(float,cocos2d::Scene*,cocos2d::TransitionScene::Orientation)>(&cocos2d::TransitionSceneOriented::create));
}
void RegisterLuaCoreTransitionRotoZoomAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionRotoZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionRotoZoom");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionRotoZoom::*)()>(&cocos2d::TransitionRotoZoom::onEnter));
mt.set_function("new",static_cast<cocos2d::TransitionRotoZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionRotoZoom::create));
}
void RegisterLuaCoreTransitionJumpZoomAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionJumpZoom,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject>("cc","TransitionJumpZoom");
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionJumpZoom::*)()>(&cocos2d::TransitionJumpZoom::onEnter));
mt.set_function("new",static_cast<cocos2d::TransitionJumpZoom*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionJumpZoom::create));
}
void RegisterLuaCoreTransitionMoveInLAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInL");
mt.set_function("action",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::action));
mt.set_function("easeActionWithAction",static_cast<cocos2d::ActionInterval*(cocos2d::TransitionMoveInL::*)(cocos2d::ActionInterval*)>(&cocos2d::TransitionMoveInL::easeActionWithAction));
mt.set_function("onEnter",static_cast<void(cocos2d::TransitionMoveInL::*)()>(&cocos2d::TransitionMoveInL::onEnter));
mt.set_function("new",static_cast<cocos2d::TransitionMoveInL*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInL::create));
}
void RegisterLuaCoreTransitionMoveInRAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInR,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInR");
mt.set_function("new",static_cast<cocos2d::TransitionMoveInR*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInR::create));
}
void RegisterLuaCoreTransitionMoveInTAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInT,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInT");
mt.set_function("new",static_cast<cocos2d::TransitionMoveInT*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInT::create));
}
void RegisterLuaCoreTransitionMoveInBAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::TransitionMoveInB,cocos2d::TransitionMoveInL,cocos2d::TransitionScene,cocos2d::Scene,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TransitionEaseScene>("cc","TransitionMoveInB");
mt.set_function("new",static_cast<cocos2d::TransitionMoveInB*(*)(float,cocos2d::Scene*)>(&cocos2d::TransitionMoveInB::create));
}
