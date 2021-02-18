#include "scripting/lua-bindings/auto/CCRegisterLuaVideoPlayerAuto.hpp"
#include "ui/UIVideoPlayer/UIVideoPlayer.h"
static void RegisterLuaVideoPlayer(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ui::VideoPlayer,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>(lua.get_or("ccui",lua.create_named_table("ccui")),"VideoPlayer");
mt["SetFileName"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetFileName);
mt["GetFileName"]=static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetFileName);
mt["SetURL"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetURL);
mt["GetURL"]=static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetURL);
mt["SetLooping"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetLooping);
mt["SetUserInputEnabled"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetUserInputEnabled);
mt["SetStyle"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::ui::VideoPlayer::StyleType)>(&cocos2d::ui::VideoPlayer::SetStyle);
mt["Play"]=static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Play);
mt["Pause"]=static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Pause);
mt["Resume"]=static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Resume);
mt["Stop"]=static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Stop);
mt["SeekTo"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(float)>(&cocos2d::ui::VideoPlayer::SeekTo);
mt["IsPlaying"]=static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsPlaying);
mt["IsLooping"]=static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsLooping);
mt["IsUserInputEnabled"]=static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsUserInputEnabled);
mt["SetKeepAspectRatioEnabled"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetKeepAspectRatioEnabled);
mt["IsKeepAspectRatioEnabled"]=static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsKeepAspectRatioEnabled);
mt["SetFullScreenEnabled"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetFullScreenEnabled);
mt["IsFullScreenEnabled"]=static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsFullScreenEnabled);
mt["OnPlayEvent"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(int)>(&cocos2d::ui::VideoPlayer::OnPlayEvent);
mt["setVisible"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::setVisible);
mt["draw"]=static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::VideoPlayer::draw);
mt["onEnter"]=static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onEnter);
mt["onExit"]=static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onExit);
mt["new"]=static_cast<cocos2d::ui::VideoPlayer*(*)()>(&cocos2d::ui::VideoPlayer::create);
}
void RegisterLuaVideoPlayerAuto(cocos2d::Lua& lua) {
RegisterLuaVideoPlayer(lua);
}
