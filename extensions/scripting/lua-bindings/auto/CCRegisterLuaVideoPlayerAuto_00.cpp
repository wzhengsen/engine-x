#include "scripting/lua-bindings/auto/CCRegisterLuaVideoPlayerAuto.hpp"
#include "ui/UIVideoPlayer/UIVideoPlayer.h"
void RegisterLuaVideoPlayerVideoPlayerAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::VideoPlayer,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","VideoPlayer");
mt.set_function("SetFileName",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetFileName));
mt.set_function("GetFileName",static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetFileName));
mt.set_function("SetURL",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetURL));
mt.set_function("GetURL",static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetURL));
mt.set_function("SetLooping",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetLooping));
mt.set_function("SetUserInputEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetUserInputEnabled));
mt.set_function("SetStyle",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::ui::VideoPlayer::StyleType)>(&cocos2d::ui::VideoPlayer::SetStyle));
mt.set_function("Play",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Play));
mt.set_function("Pause",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Pause));
mt.set_function("Resume",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Resume));
mt.set_function("Stop",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Stop));
mt.set_function("SeekTo",static_cast<void(cocos2d::ui::VideoPlayer::*)(float)>(&cocos2d::ui::VideoPlayer::SeekTo));
mt.set_function("IsPlaying",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsPlaying));
mt.set_function("IsLooping",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsLooping));
mt.set_function("IsUserInputEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsUserInputEnabled));
mt.set_function("SetKeepAspectRatioEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetKeepAspectRatioEnabled));
mt.set_function("IsKeepAspectRatioEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsKeepAspectRatioEnabled));
mt.set_function("SetFullScreenEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetFullScreenEnabled));
mt.set_function("IsFullScreenEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsFullScreenEnabled));
mt.set_function("OnPlayEvent",static_cast<void(cocos2d::ui::VideoPlayer::*)(int)>(&cocos2d::ui::VideoPlayer::OnPlayEvent));
mt.set_function("setVisible",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::setVisible));
mt.set_function("draw",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::VideoPlayer::draw));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onExit));
mt.set_function("new",static_cast<cocos2d::ui::VideoPlayer*(*)()>(&cocos2d::ui::VideoPlayer::create));
}
