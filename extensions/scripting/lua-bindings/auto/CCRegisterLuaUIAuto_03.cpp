#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUIVideoPlayerEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["VideoPlayer"];
pTable.new_enum("EventType"
,"PLAYING",0
,"PAUSED",1
,"STOPPED",2
,"COMPLETED",3
,"V_ERROR",4
);}
void RegisterLuaUIVideoPlayerStyleTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["VideoPlayer"];
pTable.new_enum("StyleType"
,"DEFAULT",0
,"NONE",1
);}
void RegisterLuaUIVideoPlayerAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::VideoPlayer,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("VideoPlayer",false);
ns["VideoPlayer"] = mt;
lua["VideoPlayer"] = sol::nil;
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
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::VideoPlayer::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::VideoPlayer::EventType)>&)>(&cocos2d::ui::VideoPlayer::AddEventListener));
mt.set_function("OnPlayEvent",static_cast<void(cocos2d::ui::VideoPlayer::*)(int)>(&cocos2d::ui::VideoPlayer::OnPlayEvent));
mt.set_function("setVisible",static_cast<void(cocos2d::ui::VideoPlayer::*)(bool)>(&cocos2d::ui::VideoPlayer::setVisible));
mt.set_function("draw",static_cast<void(cocos2d::ui::VideoPlayer::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::VideoPlayer::draw));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::VideoPlayer::*)()>(&cocos2d::ui::VideoPlayer::onExit));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::VideoPlayer*(*)()>(&cocos2d::ui::VideoPlayer::create));
RegisterLuaUIVideoPlayerEventTypeAuto(lua);
RegisterLuaUIVideoPlayerStyleTypeAuto(lua);
}
void RegisterLuaUIWebViewAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::WebView,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("WebView",false);
ns["WebView"] = mt;
lua["WebView"] = sol::nil;
mt.set_function("setJavascriptInterfaceScheme",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::setJavascriptInterfaceScheme));
mt.set_function("loadData",static_cast<void(cocos2d::ui::WebView::*)(const cocos2d::Data&,const std::string&,const std::string&,const std::string&)>(&cocos2d::ui::WebView::loadData));
mt.set_function("loadHTMLString",sol::overload([](cocos2d::ui::WebView* obj,const std::string& arg0){return obj->loadHTMLString(arg0);},[](cocos2d::ui::WebView* obj,const std::string& arg0,const std::string& arg1){return obj->loadHTMLString(arg0,arg1);}));
mt.set_function("loadURL",sol::overload(static_cast<void(cocos2d::ui::WebView::*)(const std::string&,bool)>(&cocos2d::ui::WebView::loadURL),static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadURL)));
mt.set_function("loadFile",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadFile));
mt.set_function("stopLoading",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::stopLoading));
mt.set_function("reload",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::reload));
mt.set_function("canGoBack",static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoBack));
mt.set_function("canGoForward",static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoForward));
mt.set_function("goBack",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goBack));
mt.set_function("goForward",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goForward));
mt.set_function("evaluateJS",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::evaluateJS));
mt.set_function("setScalesPageToFit",static_cast<void(cocos2d::ui::WebView::*)(const bool)>(&cocos2d::ui::WebView::setScalesPageToFit));
mt.set_function("setOnShouldStartLoading",static_cast<void(cocos2d::ui::WebView::*)(const std::function<bool (cocos2d::ui::WebView *, const std::string&)>&)>(&cocos2d::ui::WebView::setOnShouldStartLoading));
mt.set_function("setOnDidFinishLoading",static_cast<void(cocos2d::ui::WebView::*)(const std::function<void (cocos2d::ui::WebView *, const std::string&)>&)>(&cocos2d::ui::WebView::setOnDidFinishLoading));
mt.set_function("setOnDidFailLoading",static_cast<void(cocos2d::ui::WebView::*)(const std::function<void (cocos2d::ui::WebView *, const std::string&)>&)>(&cocos2d::ui::WebView::setOnDidFailLoading));
mt.set_function("setOnJSCallback",static_cast<void(cocos2d::ui::WebView::*)(const std::function<void (cocos2d::ui::WebView *, const std::string&)>&)>(&cocos2d::ui::WebView::setOnJSCallback));
mt.set_function("getOnShouldStartLoading",static_cast<std::function<bool (cocos2d::ui::WebView *, const std::string&)>(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnShouldStartLoading));
mt.set_function("getOnDidFinishLoading",static_cast<cocos2d::ui::WebView::ccWebViewCallback(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnDidFinishLoading));
mt.set_function("getOnDidFailLoading",static_cast<cocos2d::ui::WebView::ccWebViewCallback(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnDidFailLoading));
mt.set_function("getOnJSCallback",static_cast<cocos2d::ui::WebView::ccWebViewCallback(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOnJSCallback));
mt.set_function("setBounces",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setBounces));
mt.set_function("draw",static_cast<void(cocos2d::ui::WebView::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::WebView::draw));
mt.set_function("setVisible",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setVisible));
mt.set_function("setOpacityWebView",static_cast<void(cocos2d::ui::WebView::*)(float)>(&cocos2d::ui::WebView::setOpacityWebView));
mt.set_function("getOpacityWebView",static_cast<float(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOpacityWebView));
mt.set_function("setBackgroundTransparent",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::setBackgroundTransparent));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onExit));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::WebView*(*)()>(&cocos2d::ui::WebView::create));
}
void RegisterLuaUIScale9SpriteStateAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Scale9Sprite"];
pTable.new_enum("State"
,"NORMAL",0
,"GRAY",1
);}
void RegisterLuaUIScale9SpriteRenderingTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Scale9Sprite"];
pTable.new_enum("RenderingType"
,"SIMPLE",0
,"SLICE",1
);}
void RegisterLuaUIScale9SpriteAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::Scale9Sprite,cocos2d::Sprite,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>("Scale9Sprite",false);
ns["Scale9Sprite"] = mt;
lua["Scale9Sprite"] = sol::nil;
mt.set_function("initWithFile",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Rect&,const std::string&)>(&cocos2d::ui::Scale9Sprite::initWithFile),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithFile),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithFile),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::initWithFile)));
mt.set_function("initWithSpriteFrame",static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::SpriteFrame*,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithSpriteFrame));
mt.set_function("initWithSpriteFrameName",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::initWithSpriteFrameName),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::initWithSpriteFrameName)));
mt.set_function("init",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::init),static_cast<bool(cocos2d::ui::Scale9Sprite::*)()>(&cocos2d::ui::Scale9Sprite::init),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::init),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::init)));
mt.set_function("resizableSpriteWithCapInsets",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Rect&)const>(&cocos2d::ui::Scale9Sprite::resizableSpriteWithCapInsets));
mt.set_function("updateWithSprite",sol::overload(static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Vec2&,const cocos2d::Size&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::updateWithSprite),static_cast<bool(cocos2d::ui::Scale9Sprite::*)(cocos2d::Sprite*,const cocos2d::Rect&,bool,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::updateWithSprite)));
mt.set_function("setSpriteFrame",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::SpriteFrame*,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::setSpriteFrame));
mt.set_function("setState",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::ui::Scale9Sprite::State)>(&cocos2d::ui::Scale9Sprite::setState));
mt.set_function("getState",static_cast<cocos2d::ui::Scale9Sprite::State(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getState));
mt.set_function("getOriginalSize",static_cast<cocos2d::Size(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getOriginalSize));
mt.set_function("setPreferredSize",static_cast<void(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Size&)>(&cocos2d::ui::Scale9Sprite::setPreferredSize));
mt.set_function("getPreferredSize",static_cast<cocos2d::Size(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getPreferredSize));
mt.set_function("setInsetLeft",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetLeft));
mt.set_function("getInsetLeft",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetLeft));
mt.set_function("setInsetTop",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetTop));
mt.set_function("getInsetTop",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetTop));
mt.set_function("setInsetRight",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetRight));
mt.set_function("getInsetRight",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetRight));
mt.set_function("setInsetBottom",static_cast<void(cocos2d::ui::Scale9Sprite::*)(float)>(&cocos2d::ui::Scale9Sprite::setInsetBottom));
mt.set_function("getInsetBottom",static_cast<float(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getInsetBottom));
mt.set_function("setScale9Enabled",static_cast<void(cocos2d::ui::Scale9Sprite::*)(bool)>(&cocos2d::ui::Scale9Sprite::setScale9Enabled));
mt.set_function("isScale9Enabled",static_cast<bool(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::isScale9Enabled));
mt.set_function("getSprite",static_cast<cocos2d::Sprite*(cocos2d::ui::Scale9Sprite::*)()>(&cocos2d::ui::Scale9Sprite::getSprite));
mt.set_function("copyTo",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::ui::Scale9Sprite*)const>(&cocos2d::ui::Scale9Sprite::copyTo));
mt.set_function("setRenderingType",static_cast<void(cocos2d::ui::Scale9Sprite::*)(cocos2d::ui::Scale9Sprite::RenderingType)>(&cocos2d::ui::Scale9Sprite::setRenderingType));
mt.set_function("getRenderingType",static_cast<cocos2d::ui::Scale9Sprite::RenderingType(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getRenderingType));
mt.set_function("setCapInsets",static_cast<void(cocos2d::ui::Scale9Sprite::*)(const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::setCapInsets));
mt.set_function("getCapInsets",static_cast<cocos2d::Rect(cocos2d::ui::Scale9Sprite::*)()const>(&cocos2d::ui::Scale9Sprite::getCapInsets));
mt.set_function("resetRender",static_cast<void(cocos2d::ui::Scale9Sprite::*)()>(&cocos2d::ui::Scale9Sprite::resetRender));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&,const cocos2d::Rect&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)()>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)(const cocos2d::Rect&,const std::string&)>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::create),static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::create)));
mt.set_function("createWithSpriteFrame",sol::overload(static_cast<cocos2d::ui::Scale9Sprite*(*)(cocos2d::SpriteFrame*,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrame),static_cast<cocos2d::ui::Scale9Sprite*(*)(cocos2d::SpriteFrame*)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrame)));
mt.set_function("createWithSpriteFrameName",sol::overload(static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&,const cocos2d::Rect&)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrameName),static_cast<cocos2d::ui::Scale9Sprite*(*)(const std::string&)>(&cocos2d::ui::Scale9Sprite::createWithSpriteFrameName)));
RegisterLuaUIScale9SpriteStateAuto(lua);
RegisterLuaUIScale9SpriteRenderingTypeAuto(lua);
}
void RegisterLuaUIEditBoxEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum("EventType"
,"Began",0
,"Ended",1
,"Changed",2
,"Return",3
);}
void RegisterLuaUIEditBoxKeyboardReturnTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum("KeyboardReturnType"
,"DEFAULT",0
,"DONE",1
,"SEND",2
,"SEARCH",3
,"GO",4
,"NEXT",5
);}
void RegisterLuaUIEditBoxInputModeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum("InputMode"
,"ANY",0
,"EMAIL_ADDRESS",1
,"NUMERIC",2
,"PHONE_NUMBER",3
,"URL",4
,"DECIMAL",5
,"SINGLE_LINE",6
);}
void RegisterLuaUIEditBoxInputFlagAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["EditBox"];
pTable.new_enum("InputFlag"
,"PASSWORD",0
,"SENSITIVE",1
,"INITIAL_CAPS_WORD",2
,"INITIAL_CAPS_SENTENCE",3
,"INITIAL_CAPS_ALL_CHARACTERS",4
,"LOWERCASE_ALL_CHARACTERS",5
);}
void RegisterLuaUIEditBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::EditBox,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::IMEDelegate>("EditBox",false);
ns["EditBox"] = mt;
lua["EditBox"] = sol::nil;
mt.set_function("initWithSizeAndBackgroundSprite",sol::overload(static_cast<bool(cocos2d::ui::EditBox::*)(const cocos2d::Size&,cocos2d::ui::Scale9Sprite*)>(&cocos2d::ui::EditBox::initWithSizeAndBackgroundSprite),[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1){return obj->initWithSizeAndBackgroundSprite(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->initWithSizeAndBackgroundSprite(arg0,arg1,arg2);},static_cast<bool(cocos2d::ui::EditBox::*)(const cocos2d::Size&,cocos2d::ui::Scale9Sprite*,cocos2d::ui::Scale9Sprite*,cocos2d::ui::Scale9Sprite*)>(&cocos2d::ui::EditBox::initWithSizeAndBackgroundSprite)));
mt.set_function("initWithSizeAndTexture",sol::overload([](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1){return obj->initWithSizeAndTexture(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2){return obj->initWithSizeAndTexture(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3){return obj->initWithSizeAndTexture(arg0,arg1,arg2,arg3);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,cocos2d::ui::Widget::TextureResType arg4){return obj->initWithSizeAndTexture(arg0,arg1,arg2,arg3,arg4);}));
mt.set_function("loadTextures",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0,const std::string& arg1){return obj->loadTextures(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->loadTextures(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->loadTextures(arg0,arg1,arg2,arg3);}));
mt.set_function("loadTextureNormal",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0){return obj->loadTextureNormal(arg0);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureNormal(arg0,arg1);}));
mt.set_function("loadTexturePressed",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0){return obj->loadTexturePressed(arg0);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTexturePressed(arg0,arg1);}));
mt.set_function("loadTextureDisabled",sol::overload([](cocos2d::ui::EditBox* obj,const std::string& arg0){return obj->loadTextureDisabled(arg0);},[](cocos2d::ui::EditBox* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureDisabled(arg0,arg1);}));
mt.set_function("setCapInsets",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsets));
mt.set_function("setCapInsetsNormalRenderer",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsetsNormalRenderer));
mt.set_function("getCapInsetsNormalRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getCapInsetsNormalRenderer));
mt.set_function("setCapInsetsPressedRenderer",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsetsPressedRenderer));
mt.set_function("getCapInsetsPressedRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getCapInsetsPressedRenderer));
mt.set_function("setCapInsetsDisabledRenderer",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Rect&)>(&cocos2d::ui::EditBox::setCapInsetsDisabledRenderer));
mt.set_function("getCapInsetsDisabledRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getCapInsetsDisabledRenderer));
mt.set_function("setDelegate",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBoxDelegate*)>(&cocos2d::ui::EditBox::setDelegate));
mt.set_function("getDelegate",static_cast<cocos2d::ui::EditBoxDelegate*(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::getDelegate));
mt.set_function("SetEventHandler",static_cast<void(cocos2d::ui::EditBox::*)(const std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBox::EventType)>&)>(&cocos2d::ui::EditBox::SetEventHandler));
mt.set_function("GetEventHandler",static_cast<const std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBox::EventType)>&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::GetEventHandler));
mt.set_function("setText",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setText));
mt.set_function("getText",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getText));
mt.set_function("setFont",static_cast<void(cocos2d::ui::EditBox::*)(const char*,int)>(&cocos2d::ui::EditBox::setFont));
mt.set_function("setFontName",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setFontName));
mt.set_function("getFontName",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getFontName));
mt.set_function("setFontSize",static_cast<void(cocos2d::ui::EditBox::*)(int)>(&cocos2d::ui::EditBox::setFontSize));
mt.set_function("getFontSize",static_cast<int(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getFontSize));
mt.set_function("setFontColor",sol::overload(static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color4B&)>(&cocos2d::ui::EditBox::setFontColor),static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color3B&)>(&cocos2d::ui::EditBox::setFontColor)));
mt.set_function("getFontColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getFontColor));
mt.set_function("setPlaceholderFont",static_cast<void(cocos2d::ui::EditBox::*)(const char*,int)>(&cocos2d::ui::EditBox::setPlaceholderFont));
mt.set_function("setPlaceholderFontName",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setPlaceholderFontName));
mt.set_function("getPlaceholderFontName",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceholderFontName));
mt.set_function("setPlaceholderFontSize",static_cast<void(cocos2d::ui::EditBox::*)(int)>(&cocos2d::ui::EditBox::setPlaceholderFontSize));
mt.set_function("getPlaceholderFontSize",static_cast<int(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceholderFontSize));
mt.set_function("setPlaceholderFontColor",sol::overload(static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color4B&)>(&cocos2d::ui::EditBox::setPlaceholderFontColor),static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Color3B&)>(&cocos2d::ui::EditBox::setPlaceholderFontColor)));
mt.set_function("getPlaceholderFontColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceholderFontColor));
mt.set_function("setPlaceHolder",static_cast<void(cocos2d::ui::EditBox::*)(const char*)>(&cocos2d::ui::EditBox::setPlaceHolder));
mt.set_function("getPlaceHolder",static_cast<const char*(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getPlaceHolder));
mt.set_function("setInputMode",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBox::InputMode)>(&cocos2d::ui::EditBox::setInputMode));
mt.set_function("getInputMode",static_cast<cocos2d::ui::EditBox::InputMode(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getInputMode));
mt.set_function("setMaxLength",static_cast<void(cocos2d::ui::EditBox::*)(int)>(&cocos2d::ui::EditBox::setMaxLength));
mt.set_function("getMaxLength",static_cast<int(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::getMaxLength));
mt.set_function("setInputFlag",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBox::InputFlag)>(&cocos2d::ui::EditBox::setInputFlag));
mt.set_function("getInputFlag",static_cast<cocos2d::ui::EditBox::InputFlag(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getInputFlag));
mt.set_function("setReturnType",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::ui::EditBox::KeyboardReturnType)>(&cocos2d::ui::EditBox::setReturnType));
mt.set_function("getReturnType",static_cast<cocos2d::ui::EditBox::KeyboardReturnType(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getReturnType));
mt.set_function("setTextHorizontalAlignment",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::EditBox::setTextHorizontalAlignment));
mt.set_function("getTextHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getTextHorizontalAlignment));
mt.set_function("setPosition",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Vec2&)>(&cocos2d::ui::EditBox::setPosition));
mt.set_function("setVisible",static_cast<void(cocos2d::ui::EditBox::*)(bool)>(&cocos2d::ui::EditBox::setVisible));
mt.set_function("setContentSize",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Size&)>(&cocos2d::ui::EditBox::setContentSize));
mt.set_function("setAnchorPoint",static_cast<void(cocos2d::ui::EditBox::*)(const cocos2d::Vec2&)>(&cocos2d::ui::EditBox::setAnchorPoint));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::getDescription));
mt.set_function("draw",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::EditBox::draw));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::EditBox::*)()>(&cocos2d::ui::EditBox::onExit));
mt.set_function("keyboardWillShow",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardWillShow));
mt.set_function("keyboardDidShow",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardDidShow));
mt.set_function("keyboardWillHide",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardWillHide));
mt.set_function("keyboardDidHide",static_cast<void(cocos2d::ui::EditBox::*)(cocos2d::IMEKeyboardNotificationInfo&)>(&cocos2d::ui::EditBox::keyboardDidHide));
mt.set_function("setGlobalZOrder",static_cast<void(cocos2d::ui::EditBox::*)(float)>(&cocos2d::ui::EditBox::setGlobalZOrder));
mt.set_function("openKeyboard",static_cast<void(cocos2d::ui::EditBox::*)()const>(&cocos2d::ui::EditBox::openKeyboard));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::EditBox*(*)(const cocos2d::Size&,const std::string&,cocos2d::ui::Widget::TextureResType)>(&cocos2d::ui::EditBox::create),[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,cocos2d::ui::Scale9Sprite* arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,cocos2d::ui::Scale9Sprite* arg1,cocos2d::ui::Scale9Sprite* arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,cocos2d::ui::Scale9Sprite* arg1,cocos2d::ui::Scale9Sprite* arg2,cocos2d::ui::Scale9Sprite* arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::EditBox* obj,const cocos2d::Size& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,cocos2d::ui::Widget::TextureResType arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);}));
RegisterLuaUIEditBoxEventTypeAuto(lua);
RegisterLuaUIEditBoxKeyboardReturnTypeAuto(lua);
RegisterLuaUIEditBoxInputModeAuto(lua);
RegisterLuaUIEditBoxInputFlagAuto(lua);
}
void RegisterLuaUILayoutComponentHorizontalEdgeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LayoutComponent"];
pTable.new_enum("HorizontalEdge"
,"None",0
,"Left",1
,"Right",2
,"Center",3
);}
void RegisterLuaUILayoutComponentVerticalEdgeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LayoutComponent"];
pTable.new_enum("VerticalEdge"
,"None",0
,"Bottom",1
,"Top",2
,"Center",3
);}
void RegisterLuaUILayoutComponentAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::LayoutComponent,cocos2d::Component,cocos2d::Ref,cocos2d::LuaObject>("LayoutComponent",false);
ns["LayoutComponent"] = mt;
lua["LayoutComponent"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::ui::LayoutComponent::*)()>(&cocos2d::ui::LayoutComponent::init));
mt.set_function("setUsingPercentContentSize",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setUsingPercentContentSize));
mt.set_function("getUsingPercentContentSize",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getUsingPercentContentSize));
mt.set_function("setPercentContentSize",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Vec2&)>(&cocos2d::ui::LayoutComponent::setPercentContentSize));
mt.set_function("getPercentContentSize",static_cast<cocos2d::Vec2(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPercentContentSize));
mt.set_function("getAnchorPosition",static_cast<const cocos2d::Point&(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getAnchorPosition));
mt.set_function("setAnchorPosition",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Point&)>(&cocos2d::ui::LayoutComponent::setAnchorPosition));
mt.set_function("getPosition",static_cast<const cocos2d::Point&(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPosition));
mt.set_function("setPosition",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Point&)>(&cocos2d::ui::LayoutComponent::setPosition));
mt.set_function("isPositionPercentXEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPositionPercentXEnabled));
mt.set_function("setPositionPercentXEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPositionPercentXEnabled));
mt.set_function("getPositionPercentX",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPositionPercentX));
mt.set_function("setPositionPercentX",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPositionPercentX));
mt.set_function("isPositionPercentYEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPositionPercentYEnabled));
mt.set_function("setPositionPercentYEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPositionPercentYEnabled));
mt.set_function("getPositionPercentY",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPositionPercentY));
mt.set_function("setPositionPercentY",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPositionPercentY));
mt.set_function("getHorizontalEdge",static_cast<cocos2d::ui::LayoutComponent::HorizontalEdge(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getHorizontalEdge));
mt.set_function("setHorizontalEdge",static_cast<void(cocos2d::ui::LayoutComponent::*)(cocos2d::ui::LayoutComponent::HorizontalEdge)>(&cocos2d::ui::LayoutComponent::setHorizontalEdge));
mt.set_function("getVerticalEdge",static_cast<cocos2d::ui::LayoutComponent::VerticalEdge(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getVerticalEdge));
mt.set_function("setVerticalEdge",static_cast<void(cocos2d::ui::LayoutComponent::*)(cocos2d::ui::LayoutComponent::VerticalEdge)>(&cocos2d::ui::LayoutComponent::setVerticalEdge));
mt.set_function("getLeftMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getLeftMargin));
mt.set_function("setLeftMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setLeftMargin));
mt.set_function("getRightMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getRightMargin));
mt.set_function("setRightMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setRightMargin));
mt.set_function("getTopMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getTopMargin));
mt.set_function("setTopMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setTopMargin));
mt.set_function("getBottomMargin",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getBottomMargin));
mt.set_function("setBottomMargin",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setBottomMargin));
mt.set_function("getSize",static_cast<const cocos2d::Size&(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getSize));
mt.set_function("setSize",static_cast<void(cocos2d::ui::LayoutComponent::*)(const cocos2d::Size&)>(&cocos2d::ui::LayoutComponent::setSize));
mt.set_function("isPercentWidthEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPercentWidthEnabled));
mt.set_function("setPercentWidthEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPercentWidthEnabled));
mt.set_function("getSizeWidth",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getSizeWidth));
mt.set_function("setSizeWidth",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setSizeWidth));
mt.set_function("getPercentWidth",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPercentWidth));
mt.set_function("setPercentWidth",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPercentWidth));
mt.set_function("isPercentHeightEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isPercentHeightEnabled));
mt.set_function("setPercentHeightEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPercentHeightEnabled));
mt.set_function("getSizeHeight",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getSizeHeight));
mt.set_function("setSizeHeight",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setSizeHeight));
mt.set_function("getPercentHeight",static_cast<float(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::getPercentHeight));
mt.set_function("setPercentHeight",static_cast<void(cocos2d::ui::LayoutComponent::*)(float)>(&cocos2d::ui::LayoutComponent::setPercentHeight));
mt.set_function("isStretchWidthEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isStretchWidthEnabled));
mt.set_function("setStretchWidthEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setStretchWidthEnabled));
mt.set_function("isStretchHeightEnabled",static_cast<bool(cocos2d::ui::LayoutComponent::*)()const>(&cocos2d::ui::LayoutComponent::isStretchHeightEnabled));
mt.set_function("setStretchHeightEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setStretchHeightEnabled));
mt.set_function("setPercentOnlyEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setPercentOnlyEnabled));
mt.set_function("setActiveEnabled",static_cast<void(cocos2d::ui::LayoutComponent::*)(bool)>(&cocos2d::ui::LayoutComponent::setActiveEnabled));
mt.set_function("refreshLayout",static_cast<void(cocos2d::ui::LayoutComponent::*)()>(&cocos2d::ui::LayoutComponent::refreshLayout));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::LayoutComponent*(*)()>(&cocos2d::ui::LayoutComponent::create));
mt.set_function("bindLayoutComponent",static_cast<cocos2d::ui::LayoutComponent*(*)(cocos2d::Node*)>(&cocos2d::ui::LayoutComponent::bindLayoutComponent));
RegisterLuaUILayoutComponentHorizontalEdgeAuto(lua);
RegisterLuaUILayoutComponentVerticalEdgeAuto(lua);
}
void RegisterLuaUITabHeaderEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["TabHeader"];
pTable.new_enum("EventType"
,"SELECTED",0
,"UNSELECTED",1
);}
void RegisterLuaUITabHeaderAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::TabHeader,cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("TabHeader",false);
ns["TabHeader"] = mt;
lua["TabHeader"] = sol::nil;
mt.set_function("getTitleRenderer",static_cast<cocos2d::Label*(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleRenderer));
mt.set_function("setTitleText",static_cast<void(cocos2d::ui::TabHeader::*)(const std::string&)>(&cocos2d::ui::TabHeader::setTitleText));
mt.set_function("getTitleText",static_cast<std::string(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleText));
mt.set_function("setTitleColor",static_cast<void(cocos2d::ui::TabHeader::*)(const cocos2d::Color4B&)>(&cocos2d::ui::TabHeader::setTitleColor));
mt.set_function("getTitleColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleColor));
mt.set_function("setTitleFontSize",static_cast<void(cocos2d::ui::TabHeader::*)(float)>(&cocos2d::ui::TabHeader::setTitleFontSize));
mt.set_function("getTitleFontSize",static_cast<float(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleFontSize));
mt.set_function("setTitleFontName",static_cast<void(cocos2d::ui::TabHeader::*)(const std::string&)>(&cocos2d::ui::TabHeader::setTitleFontName));
mt.set_function("getTitleFontName",static_cast<std::string(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getTitleFontName));
mt.set_function("getIndexInTabControl",static_cast<int(cocos2d::ui::TabHeader::*)()const>(&cocos2d::ui::TabHeader::getIndexInTabControl));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->create(arg0,arg1,arg2,arg3);},static_cast<cocos2d::ui::TabHeader*(*)()>(&cocos2d::ui::TabHeader::create),[](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,const std::string& arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::ui::TabHeader* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,const std::string& arg5,cocos2d::ui::Widget::TextureResType arg6){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6);}));
RegisterLuaUITabHeaderEventTypeAuto(lua);
}
void RegisterLuaUITabControlDockAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["TabControl"];
pTable.new_enum("Dock"
,"TOP",0
,"LEFT",1
,"BOTTOM",2
,"RIGHT",3
);}
void RegisterLuaUITabControlEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["TabControl"];
pTable.new_enum("EventType"
,"SELECT_CHANGED",0
);}
void RegisterLuaUITabControlAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::TabControl,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("TabControl",false);
ns["TabControl"] = mt;
lua["TabControl"] = sol::nil;
mt.set_function("removeTab",static_cast<void(cocos2d::ui::TabControl::*)(int)>(&cocos2d::ui::TabControl::removeTab));
mt.set_function("setSelectTab",sol::overload(static_cast<void(cocos2d::ui::TabControl::*)(cocos2d::ui::TabHeader*)>(&cocos2d::ui::TabControl::setSelectTab),static_cast<void(cocos2d::ui::TabControl::*)(int)>(&cocos2d::ui::TabControl::setSelectTab)));
mt.set_function("getTabHeader",static_cast<cocos2d::ui::TabHeader*(cocos2d::ui::TabControl::*)(int)const>(&cocos2d::ui::TabControl::getTabHeader));
mt.set_function("getTabContainer",static_cast<cocos2d::ui::Layout*(cocos2d::ui::TabControl::*)(int)const>(&cocos2d::ui::TabControl::getTabContainer));
mt.set_function("insertTab",static_cast<void(cocos2d::ui::TabControl::*)(int,cocos2d::ui::TabHeader*,cocos2d::ui::Layout*)>(&cocos2d::ui::TabControl::insertTab));
mt.set_function("getTabCount",static_cast<size_t(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getTabCount));
mt.set_function("getSelectedTabIndex",static_cast<int(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getSelectedTabIndex));
mt.set_function("indexOfTabHeader",static_cast<int(cocos2d::ui::TabControl::*)(const cocos2d::ui::TabHeader*)const>(&cocos2d::ui::TabControl::indexOfTabHeader));
mt.set_function("setTabChangedEventListener",static_cast<void(cocos2d::ui::TabControl::*)(const std::function<void (int, cocos2d::ui::TabControl::EventType)>&)>(&cocos2d::ui::TabControl::setTabChangedEventListener));
mt.set_function("setHeaderWidth",static_cast<void(cocos2d::ui::TabControl::*)(float)>(&cocos2d::ui::TabControl::setHeaderWidth));
mt.set_function("getHeaderWidth",static_cast<float(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderWidth));
mt.set_function("setHeaderHeight",static_cast<void(cocos2d::ui::TabControl::*)(float)>(&cocos2d::ui::TabControl::setHeaderHeight));
mt.set_function("getHeaderHeight",static_cast<int(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderHeight));
mt.set_function("ignoreHeadersTextureSize",static_cast<void(cocos2d::ui::TabControl::*)(bool)>(&cocos2d::ui::TabControl::ignoreHeadersTextureSize));
mt.set_function("isIgnoreHeadersTextureSize",static_cast<bool(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::isIgnoreHeadersTextureSize));
mt.set_function("setHeaderSelectedZoom",static_cast<void(cocos2d::ui::TabControl::*)(float)>(&cocos2d::ui::TabControl::setHeaderSelectedZoom));
mt.set_function("getHeaderSelectedZoom",static_cast<float(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderSelectedZoom));
mt.set_function("setHeaderDockPlace",static_cast<void(cocos2d::ui::TabControl::*)(cocos2d::ui::TabControl::Dock)>(&cocos2d::ui::TabControl::setHeaderDockPlace));
mt.set_function("getHeaderDockPlace",static_cast<cocos2d::ui::TabControl::Dock(cocos2d::ui::TabControl::*)()const>(&cocos2d::ui::TabControl::getHeaderDockPlace));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::TabControl*(*)()>(&cocos2d::ui::TabControl::create));
RegisterLuaUITabControlDockAuto(lua);
RegisterLuaUITabControlEventTypeAuto(lua);
}
void RegisterLuaUIQrCodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::QrCode,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("QrCode",false);
ns["QrCode"] = mt;
lua["QrCode"] = sol::nil;
mt.set_function("LoadCodeByString",static_cast<bool(cocos2d::ui::QrCode::*)(const std::string&)>(&cocos2d::ui::QrCode::LoadCodeByString));
mt.set_function("SetOriginSize",static_cast<void(cocos2d::ui::QrCode::*)()>(&cocos2d::ui::QrCode::SetOriginSize));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::QrCode*(*)()>(&cocos2d::ui::QrCode::create),static_cast<cocos2d::ui::QrCode*(*)(const std::string&)>(&cocos2d::ui::QrCode::create)));
}
