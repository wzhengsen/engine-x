#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
void RegisterLuaCoreAsyncTaskPoolAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AsyncTaskPool>("cc","AsyncTaskPool");
mt.set_function("stopTasks",static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType)>(&cocos2d::AsyncTaskPool::stopTasks));
mt.set_function("enqueue",sol::overload(static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue),static_cast<void(cocos2d::AsyncTaskPool::*)(cocos2d::AsyncTaskPool::TaskType,cocos2d::AsyncTaskPool::TaskCallBack,void*,std::function<void ()>)>(&cocos2d::AsyncTaskPool::enqueue)));
mt.set_function("getInstance",static_cast<cocos2d::AsyncTaskPool*(*)()>(&cocos2d::AsyncTaskPool::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::AsyncTaskPool::destroyInstance));
}
void RegisterLuaCoreActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Action");
mt.set_function("clone",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::clone));
mt.set_function("reverse",static_cast<cocos2d::Action*(cocos2d::Action::*)()const>(&cocos2d::Action::reverse));
mt.set_function("isDone",static_cast<bool(cocos2d::Action::*)()const>(&cocos2d::Action::isDone));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Action::*)()>(&cocos2d::Action::stop));
mt.set_function("step",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::step));
mt.set_function("update",static_cast<void(cocos2d::Action::*)(float)>(&cocos2d::Action::update));
mt.set_function("getTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getTarget));
mt.set_function("setTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setTarget));
mt.set_function("getOriginalTarget",static_cast<cocos2d::Node*(cocos2d::Action::*)()const>(&cocos2d::Action::getOriginalTarget));
mt.set_function("setOriginalTarget",static_cast<void(cocos2d::Action::*)(cocos2d::Node*)>(&cocos2d::Action::setOriginalTarget));
mt.set_function("getTag",static_cast<int(cocos2d::Action::*)()const>(&cocos2d::Action::getTag));
mt.set_function("setTag",static_cast<void(cocos2d::Action::*)(int)>(&cocos2d::Action::setTag));
mt.set_function("getFlags",static_cast<unsigned int(cocos2d::Action::*)()const>(&cocos2d::Action::getFlags));
mt.set_function("setFlags",static_cast<void(cocos2d::Action::*)(unsigned int)>(&cocos2d::Action::setFlags));
}
void RegisterLuaCoreFiniteTimeActionAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","FiniteTimeAction");
mt.set_function("getDuration",static_cast<float(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::getDuration));
mt.set_function("setDuration",static_cast<void(cocos2d::FiniteTimeAction::*)(float)>(&cocos2d::FiniteTimeAction::setDuration));
mt.set_function("reverse",static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::reverse));
mt.set_function("clone",static_cast<cocos2d::FiniteTimeAction*(cocos2d::FiniteTimeAction::*)()const>(&cocos2d::FiniteTimeAction::clone));
}
void RegisterLuaCoreSpeedAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Speed,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Speed");
mt.set_function("getSpeed",static_cast<float(cocos2d::Speed::*)()const>(&cocos2d::Speed::getSpeed));
mt.set_function("setSpeed",static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::setSpeed));
mt.set_function("setInnerAction",static_cast<void(cocos2d::Speed::*)(cocos2d::ActionInterval*)>(&cocos2d::Speed::setInnerAction));
mt.set_function("getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::Speed::*)()const>(&cocos2d::Speed::getInnerAction));
mt.set_function("clone",static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::clone));
mt.set_function("reverse",static_cast<cocos2d::Speed*(cocos2d::Speed::*)()const>(&cocos2d::Speed::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Speed::*)(cocos2d::Node*)>(&cocos2d::Speed::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Speed::*)()>(&cocos2d::Speed::stop));
mt.set_function("step",static_cast<void(cocos2d::Speed::*)(float)>(&cocos2d::Speed::step));
mt.set_function("isDone",static_cast<bool(cocos2d::Speed::*)()const>(&cocos2d::Speed::isDone));
mt.set_function("initWithAction",static_cast<bool(cocos2d::Speed::*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::initWithAction));
mt.set_function("new",static_cast<cocos2d::Speed*(*)(cocos2d::ActionInterval*,float)>(&cocos2d::Speed::create));
}
void RegisterLuaCoreFollowAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Follow,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Follow");
mt.set_function("isBoundarySet",static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isBoundarySet));
mt.set_function("setBoundarySet",static_cast<void(cocos2d::Follow::*)(bool)>(&cocos2d::Follow::setBoundarySet));
mt.set_function("clone",static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::clone));
mt.set_function("reverse",static_cast<cocos2d::Follow*(cocos2d::Follow::*)()const>(&cocos2d::Follow::reverse));
mt.set_function("step",static_cast<void(cocos2d::Follow::*)(float)>(&cocos2d::Follow::step));
mt.set_function("isDone",static_cast<bool(cocos2d::Follow::*)()const>(&cocos2d::Follow::isDone));
mt.set_function("stop",static_cast<void(cocos2d::Follow::*)()>(&cocos2d::Follow::stop));
mt.set_function("initWithTarget",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->initWithTarget(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->initWithTarget(arg0,arg1);}));
mt.set_function("initWithTargetAndOffset",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->initWithTargetAndOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->initWithTargetAndOffset(arg0,arg1,arg2,arg3);}));
mt.set_function("new",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0){return obj->create(arg0);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,const cocos2d::Rect& arg1){return obj->create(arg0,arg1);}));
mt.set_function("createWithOffset",sol::overload([](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2){return obj->createWithOffset(arg0,arg1,arg2);},[](cocos2d::Follow* obj,cocos2d::Node* arg0,float arg1,float arg2,const cocos2d::Rect& arg3){return obj->createWithOffset(arg0,arg1,arg2,arg3);}));
}
void RegisterLuaCoreImageAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Image,cocos2d::Ref,cocos2d::LuaObject>("cc","Image");
mt.set_function("initWithImageFile",static_cast<bool(cocos2d::Image::*)(const std::string&)>(&cocos2d::Image::initWithImageFile));
mt.set_function("getDataLen",static_cast<ssize_t(cocos2d::Image::*)()>(&cocos2d::Image::getDataLen));
mt.set_function("getFileType",static_cast<cocos2d::Image::Format(cocos2d::Image::*)()>(&cocos2d::Image::getFileType));
mt.set_function("getPixelFormat",static_cast<cocos2d::backend::PixelFormat(cocos2d::Image::*)()>(&cocos2d::Image::getPixelFormat));
mt.set_function("getWidth",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getWidth));
mt.set_function("getHeight",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getHeight));
mt.set_function("getNumberOfMipmaps",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getNumberOfMipmaps));
mt.set_function("hasPremultipliedAlpha",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasPremultipliedAlpha));
mt.set_function("getFilePath",static_cast<std::string(cocos2d::Image::*)()const>(&cocos2d::Image::getFilePath));
mt.set_function("getBitPerPixel",static_cast<int(cocos2d::Image::*)()>(&cocos2d::Image::getBitPerPixel));
mt.set_function("hasAlpha",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::hasAlpha));
mt.set_function("isCompressed",static_cast<bool(cocos2d::Image::*)()>(&cocos2d::Image::isCompressed));
mt.set_function("saveToFile",sol::overload([](cocos2d::Image* obj,const std::string& arg0){return obj->saveToFile(arg0);},[](cocos2d::Image* obj,const std::string& arg0,bool arg1){return obj->saveToFile(arg0,arg1);}));
mt.set_function("premultiplyAlpha",static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::premultiplyAlpha));
mt.set_function("reversePremultipliedAlpha",static_cast<void(cocos2d::Image::*)()>(&cocos2d::Image::reversePremultipliedAlpha));
mt.set_function("setPNGPremultipliedAlphaEnabled",static_cast<void(*)(bool)>(&cocos2d::Image::setPNGPremultipliedAlphaEnabled));
mt.set_function("setCompressedImagesHavePMA",static_cast<void(*)(uint32_t,bool)>(&cocos2d::Image::setCompressedImagesHavePMA));
mt.set_function("isCompressedImageHavePMA",static_cast<bool(*)(uint32_t)>(&cocos2d::Image::isCompressedImageHavePMA));
}
void RegisterLuaCorePolygonInfoAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::PolygonInfo>("cc","PolygonInfo");
mt.set_function("setQuad",static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*)>(&cocos2d::PolygonInfo::setQuad));
mt.set_function("setQuads",static_cast<void(cocos2d::PolygonInfo::*)(cocos2d::V3F_C4B_T2F_Quad*,int)>(&cocos2d::PolygonInfo::setQuads));
mt.set_function("setTriangles",static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::TrianglesCommand::Triangles&)>(&cocos2d::PolygonInfo::setTriangles));
mt.set_function("getVertCount",static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getVertCount));
mt.set_function("getTrianglesCount",static_cast<unsigned int(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getTrianglesCount));
mt.set_function("getArea",static_cast<float(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getArea));
mt.set_function("getRect",static_cast<const cocos2d::Rect&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getRect));
mt.set_function("setRect",static_cast<void(cocos2d::PolygonInfo::*)(const cocos2d::Rect&)>(&cocos2d::PolygonInfo::setRect));
mt.set_function("getFilename",static_cast<const std::string&(cocos2d::PolygonInfo::*)()const>(&cocos2d::PolygonInfo::getFilename));
mt.set_function("setFilename",static_cast<void(cocos2d::PolygonInfo::*)(const std::string&)>(&cocos2d::PolygonInfo::setFilename));
}
void RegisterLuaCoreAutoPolygonAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AutoPolygon>("cc","AutoPolygon");
}
void RegisterLuaCoreSpriteFrameAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::SpriteFrame,cocos2d::Ref,cocos2d::LuaObject>("cc","SpriteFrame");
mt.set_function("getRectInPixels",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRectInPixels));
mt.set_function("setRectInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRectInPixels));
mt.set_function("isRotated",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::isRotated));
mt.set_function("setRotated",static_cast<void(cocos2d::SpriteFrame::*)(bool)>(&cocos2d::SpriteFrame::setRotated));
mt.set_function("getRect",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getRect));
mt.set_function("setRect",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setRect));
mt.set_function("getCenterRect",static_cast<const cocos2d::Rect&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getCenterRect));
mt.set_function("setCenterRectInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Rect&)>(&cocos2d::SpriteFrame::setCenterRectInPixels));
mt.set_function("hasCenterRect",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasCenterRect));
mt.set_function("getOffsetInPixels",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffsetInPixels));
mt.set_function("setOffsetInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffsetInPixels));
mt.set_function("getOriginalSizeInPixels",static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSizeInPixels));
mt.set_function("setOriginalSizeInPixels",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSizeInPixels));
mt.set_function("getOriginalSize",static_cast<const cocos2d::Size&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOriginalSize));
mt.set_function("setOriginalSize",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Size&)>(&cocos2d::SpriteFrame::setOriginalSize));
mt.set_function("getTexture",static_cast<cocos2d::Texture2D*(cocos2d::SpriteFrame::*)()>(&cocos2d::SpriteFrame::getTexture));
mt.set_function("setTexture",static_cast<void(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*)>(&cocos2d::SpriteFrame::setTexture));
mt.set_function("getOffset",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getOffset));
mt.set_function("setOffset",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setOffset));
mt.set_function("getAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::getAnchorPoint));
mt.set_function("setAnchorPoint",static_cast<void(cocos2d::SpriteFrame::*)(const cocos2d::Vec2&)>(&cocos2d::SpriteFrame::setAnchorPoint));
mt.set_function("hasAnchorPoint",static_cast<bool(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::hasAnchorPoint));
mt.set_function("clone",static_cast<cocos2d::SpriteFrame*(cocos2d::SpriteFrame::*)()const>(&cocos2d::SpriteFrame::clone));
mt.set_function("initWithTexture",sol::overload(static_cast<bool(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::initWithTexture),static_cast<bool(cocos2d::SpriteFrame::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::initWithTexture)));
mt.set_function("initWithTextureFilename",sol::overload(static_cast<bool(cocos2d::SpriteFrame::*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::initWithTextureFilename),static_cast<bool(cocos2d::SpriteFrame::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::initWithTextureFilename)));
mt.set_function("new",sol::overload(static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::create),static_cast<cocos2d::SpriteFrame*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::create)));
mt.set_function("createWithTexture",sol::overload(static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&)>(&cocos2d::SpriteFrame::createWithTexture),static_cast<cocos2d::SpriteFrame*(*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::SpriteFrame::createWithTexture)));
}
void RegisterLuaCoreAnimationFrameAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::AnimationFrame,cocos2d::Ref,cocos2d::LuaObject>("cc","AnimationFrame");
mt.set_function("getSpriteFrame",static_cast<cocos2d::SpriteFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getSpriteFrame));
mt.set_function("setSpriteFrame",static_cast<void(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*)>(&cocos2d::AnimationFrame::setSpriteFrame));
mt.set_function("getDelayUnits",static_cast<float(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getDelayUnits));
mt.set_function("setDelayUnits",static_cast<void(cocos2d::AnimationFrame::*)(float)>(&cocos2d::AnimationFrame::setDelayUnits));
mt.set_function("getUserInfo",sol::overload(static_cast<cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()>(&cocos2d::AnimationFrame::getUserInfo),static_cast<const cocos2d::ValueMap&(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::getUserInfo)));
mt.set_function("setUserInfo",static_cast<void(cocos2d::AnimationFrame::*)(const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::setUserInfo));
mt.set_function("clone",static_cast<cocos2d::AnimationFrame*(cocos2d::AnimationFrame::*)()const>(&cocos2d::AnimationFrame::clone));
mt.set_function("initWithSpriteFrame",static_cast<bool(cocos2d::AnimationFrame::*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::initWithSpriteFrame));
mt.set_function("new",static_cast<cocos2d::AnimationFrame*(*)(cocos2d::SpriteFrame*,float,const cocos2d::ValueMap&)>(&cocos2d::AnimationFrame::create));
}
void RegisterLuaCoreAnimationAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Animation,cocos2d::Ref,cocos2d::LuaObject>("cc","Animation");
mt.set_function("addSpriteFrame",static_cast<void(cocos2d::Animation::*)(cocos2d::SpriteFrame*)>(&cocos2d::Animation::addSpriteFrame));
mt.set_function("addSpriteFrameWithFile",static_cast<void(cocos2d::Animation::*)(const std::string&)>(&cocos2d::Animation::addSpriteFrameWithFile));
mt.set_function("addSpriteFrameWithTexture",static_cast<void(cocos2d::Animation::*)(cocos2d::Texture2D*,const cocos2d::Rect&)>(&cocos2d::Animation::addSpriteFrameWithTexture));
mt.set_function("getTotalDelayUnits",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getTotalDelayUnits));
mt.set_function("setDelayPerUnit",static_cast<void(cocos2d::Animation::*)(float)>(&cocos2d::Animation::setDelayPerUnit));
mt.set_function("getDelayPerUnit",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDelayPerUnit));
mt.set_function("getDuration",static_cast<float(cocos2d::Animation::*)()const>(&cocos2d::Animation::getDuration));
mt.set_function("getFrames",static_cast<const cocos2d::Vector<cocos2d::AnimationFrame *>&(cocos2d::Animation::*)()const>(&cocos2d::Animation::getFrames));
mt.set_function("setFrames",static_cast<void(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&)>(&cocos2d::Animation::setFrames));
mt.set_function("getRestoreOriginalFrame",static_cast<bool(cocos2d::Animation::*)()const>(&cocos2d::Animation::getRestoreOriginalFrame));
mt.set_function("setRestoreOriginalFrame",static_cast<void(cocos2d::Animation::*)(bool)>(&cocos2d::Animation::setRestoreOriginalFrame));
mt.set_function("getLoops",static_cast<unsigned int(cocos2d::Animation::*)()const>(&cocos2d::Animation::getLoops));
mt.set_function("setLoops",static_cast<void(cocos2d::Animation::*)(unsigned int)>(&cocos2d::Animation::setLoops));
mt.set_function("clone",static_cast<cocos2d::Animation*(cocos2d::Animation::*)()const>(&cocos2d::Animation::clone));
mt.set_function("init",static_cast<bool(cocos2d::Animation::*)()>(&cocos2d::Animation::init));
mt.set_function("initWithSpriteFrames",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->initWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->initWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->initWithSpriteFrames(arg0,arg1,arg2);}));
mt.set_function("initWithAnimationFrames",static_cast<bool(cocos2d::Animation::*)(const cocos2d::Vector<cocos2d::AnimationFrame *>&,float,unsigned int)>(&cocos2d::Animation::initWithAnimationFrames));
mt.set_function("new",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1){return obj->create(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::AnimationFrame *>& arg0,float arg1,unsigned int arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::Animation*(*)()>(&cocos2d::Animation::create)));
mt.set_function("createWithSpriteFrames",sol::overload([](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){return obj->createWithSpriteFrames(arg0);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1){return obj->createWithSpriteFrames(arg0,arg1);},[](cocos2d::Animation* obj,const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0,float arg1,unsigned int arg2){return obj->createWithSpriteFrames(arg0,arg1,arg2);}));
}
void RegisterLuaCoreActionIntervalAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","ActionInterval");
mt.set_function("getElapsed",static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getElapsed));
mt.set_function("setAmplitudeRate",static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::setAmplitudeRate));
mt.set_function("getAmplitudeRate",static_cast<float(cocos2d::ActionInterval::*)()>(&cocos2d::ActionInterval::getAmplitudeRate));
mt.set_function("isDone",static_cast<bool(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::isDone));
mt.set_function("step",static_cast<void(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::step));
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionInterval::*)(cocos2d::Node*)>(&cocos2d::ActionInterval::startWithTarget));
mt.set_function("reverse",static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionInterval*(cocos2d::ActionInterval::*)()const>(&cocos2d::ActionInterval::clone));
mt.set_function("initWithDuration",static_cast<bool(cocos2d::ActionInterval::*)(float)>(&cocos2d::ActionInterval::initWithDuration));
}
void RegisterLuaCoreSequenceAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Sequence,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Sequence");
mt.set_function("clone",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::clone));
mt.set_function("reverse",static_cast<cocos2d::Sequence*(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Sequence::*)(cocos2d::Node*)>(&cocos2d::Sequence::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Sequence::*)()>(&cocos2d::Sequence::stop));
mt.set_function("isDone",static_cast<bool(cocos2d::Sequence::*)()const>(&cocos2d::Sequence::isDone));
mt.set_function("update",static_cast<void(cocos2d::Sequence::*)(float)>(&cocos2d::Sequence::update));
mt.set_function("initWithTwoActions",static_cast<bool(cocos2d::Sequence::*)(cocos2d::FiniteTimeAction*,cocos2d::FiniteTimeAction*)>(&cocos2d::Sequence::initWithTwoActions));
mt.set_function("init",static_cast<bool(cocos2d::Sequence::*)(const cocos2d::Vector<cocos2d::FiniteTimeAction *>&)>(&cocos2d::Sequence::init));
}
void RegisterLuaCoreRepeatAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Repeat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","Repeat");
mt.set_function("setInnerAction",static_cast<void(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*)>(&cocos2d::Repeat::setInnerAction));
mt.set_function("getInnerAction",static_cast<cocos2d::FiniteTimeAction*(cocos2d::Repeat::*)()>(&cocos2d::Repeat::getInnerAction));
mt.set_function("clone",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::clone));
mt.set_function("reverse",static_cast<cocos2d::Repeat*(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Repeat::*)(cocos2d::Node*)>(&cocos2d::Repeat::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Repeat::*)()>(&cocos2d::Repeat::stop));
mt.set_function("update",static_cast<void(cocos2d::Repeat::*)(float)>(&cocos2d::Repeat::update));
mt.set_function("isDone",static_cast<bool(cocos2d::Repeat::*)()const>(&cocos2d::Repeat::isDone));
mt.set_function("initWithAction",static_cast<bool(cocos2d::Repeat::*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::initWithAction));
mt.set_function("new",static_cast<cocos2d::Repeat*(*)(cocos2d::FiniteTimeAction*,unsigned int)>(&cocos2d::Repeat::create));
}
void RegisterLuaCoreRepeatForeverAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::RepeatForever,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("cc","RepeatForever");
mt.set_function("setInnerAction",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::setInnerAction));
mt.set_function("getInnerAction",static_cast<cocos2d::ActionInterval*(cocos2d::RepeatForever::*)()>(&cocos2d::RepeatForever::getInnerAction));
mt.set_function("clone",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::clone));
mt.set_function("reverse",static_cast<cocos2d::RepeatForever*(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::RepeatForever::*)(cocos2d::Node*)>(&cocos2d::RepeatForever::startWithTarget));
mt.set_function("step",static_cast<void(cocos2d::RepeatForever::*)(float)>(&cocos2d::RepeatForever::step));
mt.set_function("isDone",static_cast<bool(cocos2d::RepeatForever::*)()const>(&cocos2d::RepeatForever::isDone));
mt.set_function("initWithAction",static_cast<bool(cocos2d::RepeatForever::*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::initWithAction));
mt.set_function("new",static_cast<cocos2d::RepeatForever*(*)(cocos2d::ActionInterval*)>(&cocos2d::RepeatForever::create));
}
