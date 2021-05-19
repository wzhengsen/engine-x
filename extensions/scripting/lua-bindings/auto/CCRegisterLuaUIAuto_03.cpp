#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUIVideoPlayerEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["VideoPlayer"];
pTable.new_enum<cocos2d::ui::VideoPlayer::EventType>("EventType",{
{"PLAYING",cocos2d::ui::VideoPlayer::EventType::PLAYING}
,{"PAUSED",cocos2d::ui::VideoPlayer::EventType::PAUSED}
,{"STOPPED",cocos2d::ui::VideoPlayer::EventType::STOPPED}
,{"COMPLETED",cocos2d::ui::VideoPlayer::EventType::COMPLETED}
,{"V_ERROR",cocos2d::ui::VideoPlayer::EventType::V_ERROR}
});}
void RegisterLuaUIVideoPlayerStyleTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["VideoPlayer"];
pTable.new_enum<cocos2d::ui::VideoPlayer::StyleType>("StyleType",{
{"DEFAULT",cocos2d::ui::VideoPlayer::StyleType::DEFAULT}
,{"NONE",cocos2d::ui::VideoPlayer::StyleType::NONE}
});}
void RegisterLuaUIVideoPlayerAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::VideoPlayer>("ccui","VideoPlayer",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::VideoPlayer*(*)()>(&cocos2d::ui::VideoPlayer::create));
mt.set_function("SetFileName",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetFileName));
mt.set_function("GetFileName",static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetFileName));
mt.set_function("SetURL",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::string&)>(&cocos2d::ui::VideoPlayer::SetURL));
mt.set_function("GetURL",static_cast<const std::string&(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::GetURL));
mt.set_function("SetLooping",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetLooping));
mt.set_function("SetUserInputEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetUserInputEnabled));
mt.set_function("SetStyle",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::ui::VideoPlayer::StyleType)>(&cocos2d::ui::VideoPlayer::SetStyle));
mt.set_function("Play",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Play));
mt.set_function("Suspend",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Suspend));
mt.set_function("Recover",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Recover));
mt.set_function("Stop",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::Stop));
mt.set_function("SeekTo",static_cast<void(cocos2d::ui::VideoPlayer::*)(float)>(&cocos2d::ui::VideoPlayer::SeekTo));
mt.set_function("IsPlaying",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsPlaying));
mt.set_function("IsLooping",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsLooping));
mt.set_function("IsUserInputEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsUserInputEnabled));
mt.set_function("SetKeepAspectRatioEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetKeepAspectRatioEnabled));
mt.set_function("IsKeepAspectRatioEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsKeepAspectRatioEnabled));
mt.set_function("SetFullScreenEnabled",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::SetFullScreenEnabled));
mt.set_function("IsFullScreenEnabled",static_cast<bool(cocos2d::ui::VideoPlayer::*)()const>(&cocos2d::ui::VideoPlayer::IsFullScreenEnabled));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::VideoPlayer::*)(const cocos2d::ui::VideoPlayer::ccVideoPlayerCallback&)>(&cocos2d::ui::VideoPlayer::AddEventListener));
mt.set_function("OnPlayEvent",static_cast<void(cocos2d::ui::VideoPlayer::*)(int)>(&cocos2d::ui::VideoPlayer::OnPlayEvent));
mt.set_function("SetVisible",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::setVisible));
mt.set_function("Draw",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::VideoPlayer::draw));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onExit));
RegisterLuaUIVideoPlayerEventTypeAuto(lua);
RegisterLuaUIVideoPlayerStyleTypeAuto(lua);
}
void RegisterLuaUIWebViewAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::WebView>("ccui","WebView",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::WebView*(*)()>(&cocos2d::ui::WebView::create));
mt.set_function("SetJavascriptInterfaceScheme",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::setJavascriptInterfaceScheme));
mt.set_function("LoadData",static_cast<void(cocos2d::ui::WebView::*)(const cocos2d::Data&,const std::string&,const std::string&,const std::string&)>(&cocos2d::ui::WebView::loadData));
mt.set_function("LoadHTMLString",sol::overload([](cocos2d::ui::WebView* obj,const std::string& arg0){return obj->loadHTMLString(arg0);},[](cocos2d::ui::WebView* obj,const std::string& arg0,const std::string& arg1){return obj->loadHTMLString(arg0,arg1);}));
mt.set_function("LoadURL",sol::overload(static_cast<void(cocos2d::ui::WebView::*)(const std::string&,bool)>(&cocos2d::ui::WebView::loadURL),static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadURL)));
mt.set_function("LoadFile",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadFile));
mt.set_function("StopLoading",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::stopLoading));
mt.set_function("Reload",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::reload));
mt.set_function("CanGoBack",static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoBack));
mt.set_function("CanGoForward",static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoForward));
mt.set_function("GoBack",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goBack));
mt.set_function("GoForward",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goForward));
mt.set_function("EvaluateJS",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::evaluateJS));
mt.set_function("SetScalesPageToFit",static_cast<void(cocos2d::ui::WebView::*)(const bool)>(&cocos2d::ui::WebView::setScalesPageToFit));
mt.set_function("SetOnShouldStartLoading",static_cast<void(cocos2d::ui::WebView::*)(const std::function<bool (cocos2d::ui::WebView *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>&)>(&cocos2d::ui::WebView::setOnShouldStartLoading));
mt.set_function("SetOnDidFinishLoading",static_cast<void(cocos2d::ui::WebView::*)(const cocos2d::ui::WebView::ccWebViewCallback&)>(&cocos2d::ui::WebView::setOnDidFinishLoading));
mt.set_function("SetOnDidFailLoading",static_cast<void(cocos2d::ui::WebView::*)(const cocos2d::ui::WebView::ccWebViewCallback&)>(&cocos2d::ui::WebView::setOnDidFailLoading));
mt.set_function("SetOnJSCallback",static_cast<void(cocos2d::ui::WebView::*)(const cocos2d::ui::WebView::ccWebViewCallback&)>(&cocos2d::ui::WebView::setOnJSCallback));
mt.set_function("GetOnShouldStartLoading",static_cast<std::function<bool (cocos2d::ui::WebView *, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > &)>(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnShouldStartLoading));
mt.set_function("GetOnDidFinishLoading",static_cast<cocos2d::ui::WebView::ccWebViewCallback(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnDidFinishLoading));
mt.set_function("GetOnDidFailLoading",static_cast<cocos2d::ui::WebView::ccWebViewCallback(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnDidFailLoading));
mt.set_function("GetOnJSCallback",static_cast<cocos2d::ui::WebView::ccWebViewCallback(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnJSCallback));
mt.set_function("SetBounces",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setBounces));
mt.set_function("Draw",static_cast<void(cocos2d::ui::WebView::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::WebView::draw));
mt.set_function("SetVisible",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setVisible));
mt.set_function("SetOpacityWebView",static_cast<void(cocos2d::ui::WebView::*)(float)>(&cocos2d::ui::WebView::setOpacityWebView));
mt.set_function("GetOpacityWebView",static_cast<float(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOpacityWebView));
mt.set_function("SetBackgroundTransparent",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::setBackgroundTransparent));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onExit));
}
void RegisterLuaUIScale9SpriteStateAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Scale9Sprite"];
pTable.new_enum<cocos2d::ui::Scale9Sprite::State>("State",{
{"NORMAL",cocos2d::ui::Scale9Sprite::State::NORMAL}
,{"GRAY",cocos2d::ui::Scale9Sprite::State::GRAY}
});}
void RegisterLuaUIScale9SpriteRenderingTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Scale9Sprite"];
pTable.new_enum<cocos2d::ui::Scale9Sprite::RenderingType>("RenderingType",{
{"SIMPLE",cocos2d::ui::Scale9Sprite::RenderingType::SIMPLE}
,{"SLICE",cocos2d::ui::Scale9Sprite::RenderingType::SLICE}
});}
void RegisterLuaUIScale9SpriteAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Scale9Sprite>("ccui","Scale9Sprite",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)()>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)(const cocos2d::Rect&,const std::string&)>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::create)));
mt.set_function("CreateWithSpriteFrame",sol::overload(static_cast<cocos2d::ui::Scale9Sprite*(*)(cocos2d::SpriteFrame*,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrame),static_cast<cocos2d::ui::Scale9Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrame)));
mt.set_function("CreateWithSpriteFrameName",sol::overload(static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrameName),static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrameName)));
mt.set_function("InitWithFile",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Rect&,const std::string&)>(&cocos2d::ui::Scale9Sprite::initWithFile),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithFile),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithFile),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::initWithFile)));
mt.set_function("InitWithSpriteFrame",static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::SpriteFrame*,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithSpriteFrame));
mt.set_function("InitWithSpriteFrameName",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::initWithSpriteFrameName),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithSpriteFrameName)));
mt.set_function("Init",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::init),static_cast<bool(cocos2d::ui::Scale9Sprite::*)()>(&cocos2d::ui::Scale9Sprite::init),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::init),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::init)));
mt.set_function("ResizableSpriteWithCapInsets",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Rect&)const>(&cocos2d::ui::Scale9Sprite::resizableSpriteWithCapInsets));
mt.set_function("UpdateWithSprite",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::updateWithSprite),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::updateWithSprite)));
mt.set_function("SetSpriteFrame",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::SpriteFrame*,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::setSpriteFrame));
mt.set_function("SetState",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::ui::Scale9Sprite::State)>(&cocos2d::ui::Scale9Sprite::setState));
mt.set_function("GetState",static_cast<cocos2d::ui::Scale9Sprite::State(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getState));
mt.set_function("GetOriginalSize",static_cast<cocos2d::Size(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getOriginalSize));
mt.set_function("SetPreferredSize",static_cast<void(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Size&)>(&cocos2d::ui::Scale9Sprite::setPreferredSize));
mt.set_function("GetPreferredSize",static_cast<cocos2d::Size(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getPreferredSize));
mt.set_function("SetInsetLeft",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetLeft));
mt.set_function("GetInsetLeft",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetLeft));
mt.set_function("SetInsetTop",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetTop));
mt.set_function("GetInsetTop",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetTop));
mt.set_function("SetInsetRight",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetRight));
mt.set_function("GetInsetRight",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetRight));
mt.set_function("SetInsetBottom",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetBottom));
mt.set_function("GetInsetBottom",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetBottom));
mt.set_function("SetScale9Enabled",static_cast<void(cocos2d::ui::Scale9Sprite::*)(bool)>(&cocos2d::ui::Scale9Sprite::setScale9Enabled));
mt.set_function("IsScale9Enabled",static_cast<bool(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::isScale9Enabled));
mt.set_function("GetSprite",static_cast<cocos2d::Sprite*(cocos2d::ui::Scale9Sprite::*)()>(&cocos2d::ui::Scale9Sprite::getSprite));
mt.set_function("CopyTo",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::ui::Scale9Sprite*)const>(&cocos2d::ui::Scale9Sprite::copyTo));
mt.set_function("SetRenderingType",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::ui::Scale9Sprite::RenderingType)>(&cocos2d::ui::Scale9Sprite::setRenderingType));
mt.set_function("GetRenderingType",static_cast<cocos2d::ui::Scale9Sprite::RenderingType(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getRenderingType));
mt.set_function("SetCapInsets",static_cast<void(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::setCapInsets));
mt.set_function("GetCapInsets",static_cast<cocos2d::Rect(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getCapInsets));
mt.set_function("ResetRender",static_cast<void(cocos2d::ui::Scale9Sprite::*)()>(&cocos2d::ui::Scale9Sprite::resetRender));
RegisterLuaUIScale9SpriteStateAuto(lua);
RegisterLuaUIScale9SpriteRenderingTypeAuto(lua);
}
void RegisterLuaUIEditBoxEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum<cocos2d::ui::EditBox::EventType>("EventType",{
{"Began",cocos2d::ui::EditBox::EventType::Began}
,{"Ended",cocos2d::ui::EditBox::EventType::Ended}
,{"Changed",cocos2d::ui::EditBox::EventType::Changed}
,{"Return",cocos2d::ui::EditBox::EventType::Return}
});}
void RegisterLuaUIEditBoxKeyboardReturnTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum<cocos2d::ui::EditBox::KeyboardReturnType>("KeyboardReturnType",{
{"DEFAULT",cocos2d::ui::EditBox::KeyboardReturnType::DEFAULT}
,{"DONE",cocos2d::ui::EditBox::KeyboardReturnType::DONE}
,{"SEND",cocos2d::ui::EditBox::KeyboardReturnType::SEND}
,{"SEARCH",cocos2d::ui::EditBox::KeyboardReturnType::SEARCH}
,{"GO",cocos2d::ui::EditBox::KeyboardReturnType::GO}
,{"NEXT",cocos2d::ui::EditBox::KeyboardReturnType::NEXT}
});}
void RegisterLuaUIEditBoxInputModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum<cocos2d::ui::EditBox::InputMode>("InputMode",{
{"ANY",cocos2d::ui::EditBox::InputMode::ANY}
,{"EMAIL_ADDRESS",cocos2d::ui::EditBox::InputMode::EMAIL_ADDRESS}
,{"NUMERIC",cocos2d::ui::EditBox::InputMode::NUMERIC}
,{"PHONE_NUMBER",cocos2d::ui::EditBox::InputMode::PHONE_NUMBER}
,{"URL",cocos2d::ui::EditBox::InputMode::URL}
,{"DECIMAL",cocos2d::ui::EditBox::InputMode::DECIMAL}
,{"SINGLE_LINE",cocos2d::ui::EditBox::InputMode::SINGLE_LINE}
});}
void RegisterLuaUIEditBoxInputFlagAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum<cocos2d::ui::EditBox::InputFlag>("InputFlag",{
{"PASSWORD",cocos2d::ui::EditBox::InputFlag::PASSWORD}
,{"SENSITIVE",cocos2d::ui::EditBox::InputFlag::SENSITIVE}
,{"INITIAL_CAPS_WORD",cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD}
,{"INITIAL_CAPS_SENTENCE",cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_SENTENCE}
,{"INITIAL_CAPS_ALL_CHARACTERS",cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_ALL_CHARACTERS}
,{"LOWERCASE_ALL_CHARACTERS",cocos2d::ui::EditBox::InputFlag::LOWERCASE_ALL_CHARACTERS}
});}
void RegisterLuaUIEditBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::EditBox>("ccui","EditBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::IMEDelegate>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::EditBox*(*)(const cocos2d::Size&,const std::string&,cocos2d::ui::Widget::TextureResType)>(&cocos2d::ui::EditBox::create),[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,cocos2d::ui::Scale9Sprite* arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,cocos2d::ui::Scale9Sprite* arg1,cocos2d::ui::Scale9Sprite* arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,cocos2d::ui::Scale9Sprite* arg1,cocos2d::ui::Scale9Sprite* arg2,cocos2d::ui::Scale9Sprite* arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,cocos2d::ui::Widget::TextureResType arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("InitWithSizeAndBackgroundSprite",sol::overload(static_cast<bool(cocos2d::ui::EditBox::*)(const cocos2d::Size&,cocos2d::ui::Scale9Sprite*)>(&cocos2d::ui::EditBox::initWithSizeAndBackgroundSprite),[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1){return obj->initWithSizeAndBackgroundSprite(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->initWithSizeAndBackgroundSprite(arg0,arg1,arg2);},static_cast<bool(cocos2d::ui::EditBox::*)(const cocos2d::Size&,cocos2d::ui::Scale9Sprite*,cocos2d::ui::Scale9Sprite*,cocos2d::ui::Scale9Sprite*)>(&cocos2d::ui::EditBox::initWithSizeAndBackgroundSprite)));
mt.set_function("InitWithSizeAndTexture",sol::overload([](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1){return obj->initWithSizeAndTexture(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2){return obj->initWithSizeAndTexture(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3){return obj->initWithSizeAndTexture(arg0,arg1,arg2,arg3);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,cocos2d::ui::Widget::TextureResType arg4){return obj->initWithSizeAndTexture(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("LoadTextures",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0,const std::string& arg1){return obj->loadTextures(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->loadTextures(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->loadTextures(arg0,arg1,arg2,arg3);}));
mt.set_function("LoadTextureNormal",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0){return obj->loadTextureNormal(arg0);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureNormal(arg0,arg1);}));
mt.set_function("LoadTexturePressed",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0){return obj->loadTexturePressed(arg0);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTexturePressed(arg0,arg1);}));
mt.set_function("LoadTextureDisabled",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0){return obj->loadTextureDisabled(arg0);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureDisabled(arg0,arg1);}));
mt.set_function("SetCapInsets",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsets));
mt.set_function("SetCapInsetsNormalRenderer",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsetsNormalRenderer));
mt.set_function("GetCapInsetsNormalRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getCapInsetsNormalRenderer));
mt.set_function("SetCapInsetsPressedRenderer",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsetsPressedRenderer));
mt.set_function("GetCapInsetsPressedRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getCapInsetsPressedRenderer));
mt.set_function("SetCapInsetsDisabledRenderer",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsetsDisabledRenderer));
mt.set_function("GetCapInsetsDisabledRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getCapInsetsDisabledRenderer));
mt.set_function("SetDelegate",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBoxDelegate*)>(&cocos2d::ui::EditBox::setDelegate));
mt.set_function("GetDelegate",static_cast<cocos2d::ui::EditBoxDelegate*(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::getDelegate));
mt.set_function("SetEventHandler",static_cast<void(cocos2d::ui::EditBox::*)(const std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBox::EventType)>&)>(&cocos2d::ui::EditBox::SetEventHandler));
mt.set_function("GetEventHandler",static_cast<const std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBox::EventType)>&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::GetEventHandler));
mt.set_function("SetText",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setText));
mt.set_function("GetText",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getText));
mt.set_function("SetFont",static_cast<void(cocos2d::ui::EditBox::*)(const char*,int)>(&cocos2d::ui::EditBox::setFont));
mt.set_function("SetFontName",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setFontName));
mt.set_function("GetFontName",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getFontName));
mt.set_function("SetFontSize",static_cast<void(cocos2d::ui::EditBox::*)(int)>(&cocos2d::ui::EditBox::setFontSize));
mt.set_function("GetFontSize",static_cast<int(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getFontSize));
mt.set_function("SetFontColor",sol::overload(static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color4B&)>(&cocos2d::ui::EditBox::setFontColor),static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color3B&)>(&cocos2d::ui::EditBox::setFontColor)));
mt.set_function("GetFontColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getFontColor));
mt.set_function("SetPlaceholderFont",static_cast<void(cocos2d::ui::EditBox::*)(const char*,int)>(&cocos2d::ui::EditBox::setPlaceholderFont));
mt.set_function("SetPlaceholderFontName",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setPlaceholderFontName));
mt.set_function("GetPlaceholderFontName",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceholderFontName));
mt.set_function("SetPlaceholderFontSize",static_cast<void(cocos2d::ui::EditBox::*)(int)>(&cocos2d::ui::EditBox::setPlaceholderFontSize));
mt.set_function("GetPlaceholderFontSize",static_cast<int(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceholderFontSize));
mt.set_function("SetPlaceholderFontColor",sol::overload(static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color4B&)>(&cocos2d::ui::EditBox::setPlaceholderFontColor),static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color3B&)>(&cocos2d::ui::EditBox::setPlaceholderFontColor)));
mt.set_function("GetPlaceholderFontColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceholderFontColor));
mt.set_function("SetPlaceHolder",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setPlaceHolder));
mt.set_function("GetPlaceHolder",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceHolder));
mt.set_function("SetInputMode",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBox::InputMode)>(&cocos2d::ui::EditBox::setInputMode));
mt.set_function("GetInputMode",static_cast<cocos2d::ui::EditBox::InputMode(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getInputMode));
mt.set_function("SetMaxLength",static_cast<void(cocos2d::ui::EditBox::*)(int)>(&cocos2d::ui::EditBox::setMaxLength));
mt.set_function("GetMaxLength",static_cast<int(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::getMaxLength));
mt.set_function("SetInputFlag",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBox::InputFlag)>(&cocos2d::ui::EditBox::setInputFlag));
mt.set_function("GetInputFlag",static_cast<cocos2d::ui::EditBox::InputFlag(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getInputFlag));
mt.set_function("SetReturnType",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBox::KeyboardReturnType)>(&cocos2d::ui::EditBox::setReturnType));
mt.set_function("GetReturnType",static_cast<cocos2d::ui::EditBox::KeyboardReturnType(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getReturnType));
mt.set_function("SetTextHorizontalAlignment",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::EditBox::setTextHorizontalAlignment));
mt.set_function("GetTextHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getTextHorizontalAlignment));
mt.set_function("SetPosition",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Vec2&)>(&cocos2d::ui::EditBox::setPosition));
mt.set_function("SetVisible",static_cast<void(cocos2d::ui::EditBox::*)(bool)>(&cocos2d::ui::EditBox::setVisible));
mt.set_function("SetContentSize",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Size&)>(&cocos2d::ui::EditBox::setContentSize));
mt.set_function("SetAnchorPoint",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Vec2&)>(&cocos2d::ui::EditBox::setAnchorPoint));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getDescription));
mt.set_function("Draw",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::EditBox::draw));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::onExit));
mt.set_function("KeyboardWillShow",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardWillShow));
mt.set_function("KeyboardDidShow",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardDidShow));
mt.set_function("KeyboardWillHide",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardWillHide));
mt.set_function("KeyboardDidHide",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardDidHide));
mt.set_function("SetGlobalZOrder",static_cast<void(cocos2d::ui::EditBox::*)(float)>(&cocos2d::ui::EditBox::setGlobalZOrder));
mt.set_function("OpenKeyboard",static_cast<void(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::openKeyboard));
RegisterLuaUIEditBoxEventTypeAuto(lua);
RegisterLuaUIEditBoxKeyboardReturnTypeAuto(lua);
RegisterLuaUIEditBoxInputModeAuto(lua);
RegisterLuaUIEditBoxInputFlagAuto(lua);
}
void RegisterLuaUILayoutComponentHorizontalEdgeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LayoutComponent"];
pTable.new_enum<cocos2d::ui::LayoutComponent::HorizontalEdge>("HorizontalEdge",{
{"None",cocos2d::ui::LayoutComponent::HorizontalEdge::None}
,{"Left",cocos2d::ui::LayoutComponent::HorizontalEdge::Left}
,{"Right",cocos2d::ui::LayoutComponent::HorizontalEdge::Right}
,{"Center",cocos2d::ui::LayoutComponent::HorizontalEdge::Center}
});}
void RegisterLuaUILayoutComponentVerticalEdgeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LayoutComponent"];
pTable.new_enum<cocos2d::ui::LayoutComponent::VerticalEdge>("VerticalEdge",{
{"None",cocos2d::ui::LayoutComponent::VerticalEdge::None}
,{"Bottom",cocos2d::ui::LayoutComponent::VerticalEdge::Bottom}
,{"Top",cocos2d::ui::LayoutComponent::VerticalEdge::Top}
,{"Center",cocos2d::ui::LayoutComponent::VerticalEdge::Center}
});}
void RegisterLuaUILayoutComponentAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::LayoutComponent>("ccui","LayoutComponent",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Component,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Init",static_cast<bool(cocos2d::ui::LayoutComponent::*)()>(&cocos2d::ui::LayoutComponent::init));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::LayoutComponent*(*)()>(&cocos2d::ui::LayoutComponent::create));
mt.set_function("BindLayoutComponent",static_cast<cocos2d::ui::LayoutComponent*(*)(cocos2d::Node*)>(&cocos2d::ui::LayoutComponent::bindLayoutComponent));
mt.set_function("SetUsingPercentContentSize",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setUsingPercentContentSize));
mt.set_function("GetUsingPercentContentSize",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getUsingPercentContentSize));
mt.set_function("SetPercentContentSize",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Vec2&)>(&cocos2d::ui::LayoutComponent::setPercentContentSize));
mt.set_function("GetPercentContentSize",static_cast<cocos2d::Vec2(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPercentContentSize));
mt.set_function("GetAnchorPosition",static_cast<const cocos2d::Point&(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getAnchorPosition));
mt.set_function("SetAnchorPosition",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Point&)>(&cocos2d::ui::LayoutComponent::setAnchorPosition));
mt.set_function("GetPosition",static_cast<const cocos2d::Point&(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPosition));
mt.set_function("SetPosition",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Point&)>(&cocos2d::ui::LayoutComponent::setPosition));
mt.set_function("IsPositionPercentXEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPositionPercentXEnabled));
mt.set_function("SetPositionPercentXEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPositionPercentXEnabled));
mt.set_function("GetPositionPercentX",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPositionPercentX));
mt.set_function("SetPositionPercentX",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPositionPercentX));
mt.set_function("IsPositionPercentYEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPositionPercentYEnabled));
mt.set_function("SetPositionPercentYEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPositionPercentYEnabled));
mt.set_function("GetPositionPercentY",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPositionPercentY));
mt.set_function("SetPositionPercentY",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPositionPercentY));
mt.set_function("GetHorizontalEdge",static_cast<cocos2d::ui::LayoutComponent::HorizontalEdge(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getHorizontalEdge));
mt.set_function("SetHorizontalEdge",static_cast<void(cocos2d::ui::LayoutComponent::*)(cocos2d::ui::LayoutComponent::HorizontalEdge)>(&cocos2d::ui::LayoutComponent::setHorizontalEdge));
mt.set_function("GetVerticalEdge",static_cast<cocos2d::ui::LayoutComponent::VerticalEdge(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getVerticalEdge));
mt.set_function("SetVerticalEdge",static_cast<void(cocos2d::ui::LayoutComponent::*)(cocos2d::ui::LayoutComponent::VerticalEdge)>(&cocos2d::ui::LayoutComponent::setVerticalEdge));
mt.set_function("GetLeftMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getLeftMargin));
mt.set_function("SetLeftMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setLeftMargin));
mt.set_function("GetRightMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getRightMargin));
mt.set_function("SetRightMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setRightMargin));
mt.set_function("GetTopMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getTopMargin));
mt.set_function("SetTopMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setTopMargin));
mt.set_function("GetBottomMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getBottomMargin));
mt.set_function("SetBottomMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setBottomMargin));
mt.set_function("GetSize",static_cast<const cocos2d::Size&(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getSize));
mt.set_function("SetSize",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Size&)>(&cocos2d::ui::LayoutComponent::setSize));
mt.set_function("IsPercentWidthEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPercentWidthEnabled));
mt.set_function("SetPercentWidthEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPercentWidthEnabled));
mt.set_function("GetSizeWidth",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getSizeWidth));
mt.set_function("SetSizeWidth",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setSizeWidth));
mt.set_function("GetPercentWidth",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPercentWidth));
mt.set_function("SetPercentWidth",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPercentWidth));
mt.set_function("IsPercentHeightEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPercentHeightEnabled));
mt.set_function("SetPercentHeightEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPercentHeightEnabled));
mt.set_function("GetSizeHeight",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getSizeHeight));
mt.set_function("SetSizeHeight",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setSizeHeight));
mt.set_function("GetPercentHeight",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPercentHeight));
mt.set_function("SetPercentHeight",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPercentHeight));
mt.set_function("IsStretchWidthEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isStretchWidthEnabled));
mt.set_function("SetStretchWidthEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setStretchWidthEnabled));
mt.set_function("IsStretchHeightEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isStretchHeightEnabled));
mt.set_function("SetStretchHeightEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setStretchHeightEnabled));
mt.set_function("SetPercentOnlyEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPercentOnlyEnabled));
mt.set_function("SetActiveEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setActiveEnabled));
mt.set_function("RefreshLayout",static_cast<void(cocos2d::ui::LayoutComponent::*)()>(&cocos2d::ui::LayoutComponent::refreshLayout));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::LayoutComponent()>();
RegisterLuaUILayoutComponentHorizontalEdgeAuto(lua);
RegisterLuaUILayoutComponentVerticalEdgeAuto(lua);
}
void RegisterLuaUITabHeaderAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TabHeader>("ccui","TabHeader",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->create(arg0,arg1,arg2,arg3);},static_cast<cocos2d::ui::TabHeader*(*)()>(&cocos2d::ui::TabHeader::create),[](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,const std::string& arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,const std::string& arg5,cocos2d::ui::Widget::TextureResType arg6){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
mt.set_function("GetTitleRenderer",static_cast<cocos2d::Label*(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleRenderer));
mt.set_function("SetTitleText",static_cast<void(cocos2d::ui::TabHeader::*)(const std::string&)>(&cocos2d::ui::TabHeader::setTitleText));
mt.set_function("GetTitleText",static_cast<std::string(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleText));
mt.set_function("SetTitleColor",static_cast<void(cocos2d::ui::TabHeader::*)(const cocos2d::Color4B&)>(&cocos2d::ui::TabHeader::setTitleColor));
mt.set_function("GetTitleColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleColor));
mt.set_function("SetTitleFontSize",static_cast<void(cocos2d::ui::TabHeader::*)(float)>(&cocos2d::ui::TabHeader::setTitleFontSize));
mt.set_function("GetTitleFontSize",static_cast<float(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleFontSize));
mt.set_function("SetTitleFontName",static_cast<void(cocos2d::ui::TabHeader::*)(const std::string&)>(&cocos2d::ui::TabHeader::setTitleFontName));
mt.set_function("GetTitleFontName",static_cast<std::string(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleFontName));
mt.set_function("GetIndexInTabControl",static_cast<int(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getIndexInTabControl));
}
void RegisterLuaUITabControlDockAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["TabControl"];
pTable.new_enum<cocos2d::ui::TabControl::Dock>("Dock",{
{"TOP",cocos2d::ui::TabControl::Dock::TOP}
,{"LEFT",cocos2d::ui::TabControl::Dock::LEFT}
,{"BOTTOM",cocos2d::ui::TabControl::Dock::BOTTOM}
,{"RIGHT",cocos2d::ui::TabControl::Dock::RIGHT}
});}
void RegisterLuaUITabControlEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["TabControl"];
pTable.new_enum<cocos2d::ui::TabControl::EventType>("EventType",{
{"SELECT_CHANGED",cocos2d::ui::TabControl::EventType::SELECT_CHANGED}
});}
void RegisterLuaUITabControlAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TabControl>("ccui","TabControl",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::TabControl*(*)()>(&cocos2d::ui::TabControl::create));
mt.set_function("RemoveTab",static_cast<void(cocos2d::ui::TabControl::*)(int)>(&cocos2d::ui::TabControl::removeTab));
mt.set_function("SetSelectTab",sol::overload(static_cast<void(cocos2d::ui::TabControl::*)(cocos2d::ui::TabHeader*)>(&cocos2d::ui::TabControl::setSelectTab),static_cast<void(cocos2d::ui::TabControl::*)(int)>(&cocos2d::ui::TabControl::setSelectTab)));
mt.set_function("GetTabHeader",static_cast<cocos2d::ui::TabHeader*(cocos2d::ui::TabControl::*)(int)const>(&cocos2d::ui::TabControl::getTabHeader));
mt.set_function("GetTabContainer",static_cast<cocos2d::ui::Layout*(cocos2d::ui::TabControl::*)(int)const>(&cocos2d::ui::TabControl::getTabContainer));
mt.set_function("InsertTab",static_cast<void(cocos2d::ui::TabControl::*)(int,cocos2d::ui::TabHeader*,cocos2d::ui::Layout*)>(&cocos2d::ui::TabControl::insertTab));
mt.set_function("GetTabCount",static_cast<size_t(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getTabCount));
mt.set_function("GetSelectedTabIndex",static_cast<int(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getSelectedTabIndex));
mt.set_function("IndexOfTabHeader",static_cast<int(cocos2d::ui::TabControl::*)(const cocos2d::ui::TabHeader*)const>(&cocos2d::ui::TabControl::indexOfTabHeader));
mt.set_function("SetTabChangedEventListener",static_cast<void(cocos2d::ui::TabControl::*)(const cocos2d::ui::TabControl::ccTabControlCallback&)>(&cocos2d::ui::TabControl::setTabChangedEventListener));
mt.set_function("SetHeaderWidth",static_cast<void(cocos2d::ui::TabControl::*)(float)>(&cocos2d::ui::TabControl::setHeaderWidth));
mt.set_function("GetHeaderWidth",static_cast<float(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderWidth));
mt.set_function("SetHeaderHeight",static_cast<void(cocos2d::ui::TabControl::*)(float)>(&cocos2d::ui::TabControl::setHeaderHeight));
mt.set_function("GetHeaderHeight",static_cast<int(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderHeight));
mt.set_function("IgnoreHeadersTextureSize",static_cast<void(cocos2d::ui::TabControl::*)(bool)>(&cocos2d::ui::TabControl::ignoreHeadersTextureSize));
mt.set_function("IsIgnoreHeadersTextureSize",static_cast<bool(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::isIgnoreHeadersTextureSize));
mt.set_function("SetHeaderSelectedZoom",static_cast<void(cocos2d::ui::TabControl::*)(float)>(&cocos2d::ui::TabControl::setHeaderSelectedZoom));
mt.set_function("GetHeaderSelectedZoom",static_cast<float(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderSelectedZoom));
mt.set_function("SetHeaderDockPlace",static_cast<void(cocos2d::ui::TabControl::*)(cocos2d::ui::TabControl::Dock)>(&cocos2d::ui::TabControl::setHeaderDockPlace));
mt.set_function("GetHeaderDockPlace",static_cast<cocos2d::ui::TabControl::Dock(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderDockPlace));
RegisterLuaUITabControlDockAuto(lua);
RegisterLuaUITabControlEventTypeAuto(lua);
}
void RegisterLuaUIQrCodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::QrCode>("ccui","QrCode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::QrCode*(*)()>(&cocos2d::ui::QrCode::create),static_cast<cocos2d::ui::QrCode*(*)(const std::string&)>(&cocos2d::ui::QrCode::create)));
mt.set_function("LoadCodeByString",static_cast<bool(cocos2d::ui::QrCode::*)(const std::string&)>(&cocos2d::ui::QrCode::LoadCodeByString));
mt.set_function("SetOriginSize",static_cast<void(cocos2d::ui::QrCode::*)()>(&cocos2d::ui::QrCode::SetOriginSize));
}
