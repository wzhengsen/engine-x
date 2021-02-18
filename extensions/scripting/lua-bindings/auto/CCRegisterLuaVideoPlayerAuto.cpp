#include "scripting/lua-bindings/auto/CCRegisterLuaVideoPlayerAuto.hpp"
#include "ui/UIVideoPlayer/UIVideoPlayer.h"
static void RegisterLuaVideoPlayer(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ui::VideoPlayer,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","VideoPlayer"
,"SetFileName",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetFileName)
,"GetFileName",static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetFileName)
,"SetURL",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetURL)
,"GetURL",static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetURL)
,"SetLooping",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetLooping)
,"SetUserInputEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetUserInputEnabled)
,"SetStyle",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::ui::VideoPlayer::StyleType)>(&cocos2d::ui::VideoPlayer::SetStyle)
,"Play",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Play)
,"Pause",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Pause)
,"Resume",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Resume)
,"Stop",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Stop)
,"SeekTo",static_cast<void(cocos2d::ui::VideoPlayer::*)(float)>(&cocos2d::ui::VideoPlayer::SeekTo)
,"IsPlaying",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsPlaying)
,"IsLooping",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsLooping)
,"IsUserInputEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsUserInputEnabled)
,"SetKeepAspectRatioEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetKeepAspectRatioEnabled)
,"IsKeepAspectRatioEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsKeepAspectRatioEnabled)
,"SetFullScreenEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetFullScreenEnabled)
,"IsFullScreenEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsFullScreenEnabled)
,"OnPlayEvent",static_cast<void(cocos2d::ui::VideoPlayer::*)(int)>(&cocos2d::ui::VideoPlayer::OnPlayEvent)
,"setVisible",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::setVisible)
,"draw",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::VideoPlayer::draw)
,"onEnter",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onEnter)
,"onExit",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onExit)
,"new",static_cast<cocos2d::ui::VideoPlayer*(*)()>(&cocos2d::ui::VideoPlayer::create)
);}
void RegisterLuaVideoPlayerAuto(cocos2d::Lua& lua) {
RegisterLuaVideoPlayer(lua);
}
