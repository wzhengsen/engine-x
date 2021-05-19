#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUIImageViewAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::ImageView>("ccui","ImageView",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::BlendProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::ImageView::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::ImageView* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ui::ImageView* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->create(arg0,arg1);},static_cast<cocos2d::ui::ImageView*(*)()>(&cocos2d::ui::ImageView::create)));
mt.set_function("LoadTexture",sol::overload([](cocos2d::ui::ImageView* obj,const std::string& arg0){return obj->loadTexture(arg0);},[](cocos2d::ui::ImageView* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTexture(arg0,arg1);}));
mt.set_function("SetTextureRect",static_cast<void(cocos2d::ui::ImageView::*)(const cocos2d::Rect&)>(&cocos2d::ui::ImageView::setTextureRect));
mt.set_function("SetScale9Enabled",static_cast<void(cocos2d::ui::ImageView::*)(bool)>(&cocos2d::ui::ImageView::setScale9Enabled));
mt.set_function("IsScale9Enabled",static_cast<bool(cocos2d::ui::ImageView::*)()const>(&cocos2d::ui::ImageView::isScale9Enabled));
mt.set_function("SetCapInsets",static_cast<void(cocos2d::ui::ImageView::*)(const cocos2d::Rect&)>(&cocos2d::ui::ImageView::setCapInsets));
mt.set_function("GetCapInsets",static_cast<const cocos2d::Rect&(cocos2d::ui::ImageView::*)()const>(&cocos2d::ui::ImageView::getCapInsets));
mt.set_function("GetRenderer",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::ImageView::*)()const>(&cocos2d::ui::ImageView::getRenderer));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::ui::ImageView::*)(const cocos2d::BlendFunc&)>(&cocos2d::ui::ImageView::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ui::ImageView::*)()const>(&cocos2d::ui::ImageView::getBlendFunc));
mt.set_function("IgnoreContentAdaptWithSize",static_cast<void(cocos2d::ui::ImageView::*)(bool)>(&cocos2d::ui::ImageView::ignoreContentAdaptWithSize));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::ImageView::*)()const>(&cocos2d::ui::ImageView::getDescription));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::ImageView::*)()const>(&cocos2d::ui::ImageView::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::ImageView::*)()>(&cocos2d::ui::ImageView::getVirtualRenderer));
mt.set_function("GetRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::ImageView::*)()>(&cocos2d::ui::ImageView::getRenderFile));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::ImageView::__Type));
}
void RegisterLuaUITextTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Text"];
pTable.new_enum<cocos2d::ui::Text::Type>("Type",{
{"SYSTEM",cocos2d::ui::Text::Type::SYSTEM}
,{"TTF",cocos2d::ui::Text::Type::TTF}
});}
void RegisterLuaUITextAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Text>("ccui","Text",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::BlendProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Text::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::Text*(*)(const std::string&,const std::string&,float)>(&cocos2d::ui::Text::create),static_cast<cocos2d::ui::Text*(*)()>(&cocos2d::ui::Text::create)));
mt.set_function("SetString",static_cast<void(cocos2d::ui::Text::*)(const std::string&)>(&cocos2d::ui::Text::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getString));
mt.set_function("GetStringLength",static_cast<ssize_t(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getStringLength));
mt.set_function("SetFontSize",static_cast<void(cocos2d::ui::Text::*)(float)>(&cocos2d::ui::Text::setFontSize));
mt.set_function("GetFontSize",static_cast<float(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getFontSize));
mt.set_function("SetFontName",static_cast<void(cocos2d::ui::Text::*)(const std::string&)>(&cocos2d::ui::Text::setFontName));
mt.set_function("GetFontName",static_cast<const std::string&(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getFontName));
mt.set_function("GetType",static_cast<cocos2d::ui::Text::Type(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getType));
mt.set_function("SetTouchScaleChangeEnabled",static_cast<void(cocos2d::ui::Text::*)(bool)>(&cocos2d::ui::Text::setTouchScaleChangeEnabled));
mt.set_function("IsTouchScaleChangeEnabled",static_cast<bool(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::isTouchScaleChangeEnabled));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Text::*)()>(&cocos2d::ui::Text::getVirtualRenderer));
mt.set_function("GetAutoRenderSize",static_cast<cocos2d::Size(cocos2d::ui::Text::*)()>(&cocos2d::ui::Text::getAutoRenderSize));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getDescription));
mt.set_function("SetTextAreaSize",static_cast<void(cocos2d::ui::Text::*)(const cocos2d::Size&)>(&cocos2d::ui::Text::setTextAreaSize));
mt.set_function("GetTextAreaSize",static_cast<const cocos2d::Size&(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getTextAreaSize));
mt.set_function("SetTextHorizontalAlignment",static_cast<void(cocos2d::ui::Text::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::Text::setTextHorizontalAlignment));
mt.set_function("GetTextHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getTextHorizontalAlignment));
mt.set_function("SetTextVerticalAlignment",static_cast<void(cocos2d::ui::Text::*)(cocos2d::TextVAlignment)>(&cocos2d::ui::Text::setTextVerticalAlignment));
mt.set_function("GetTextVerticalAlignment",static_cast<cocos2d::TextVAlignment(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getTextVerticalAlignment));
mt.set_function("SetTextColor",static_cast<void(cocos2d::ui::Text::*)(const cocos2d::Color4B)>(&cocos2d::ui::Text::setTextColor));
mt.set_function("GetTextColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getTextColor));
mt.set_function("EnableShadow",sol::overload([](cocos2d::ui::Text* obj){return obj->enableShadow();},[](cocos2d::ui::Text* obj,const cocos2d::Color4B& arg0){return obj->enableShadow(arg0);},[](cocos2d::ui::Text* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){return obj->enableShadow(arg0,arg1);},[](cocos2d::ui::Text* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1,int arg2){return obj->enableShadow(arg0,arg1,arg2);}));
mt.set_function("EnableOutline",sol::overload([](cocos2d::ui::Text* obj,const cocos2d::Color4B& arg0){return obj->enableOutline(arg0);},[](cocos2d::ui::Text* obj,const cocos2d::Color4B& arg0,int arg1){return obj->enableOutline(arg0,arg1);}));
mt.set_function("EnableGlow",static_cast<void(cocos2d::ui::Text::*)(const cocos2d::Color4B&)>(&cocos2d::ui::Text::enableGlow));
mt.set_function("DisableEffect",sol::overload(static_cast<void(cocos2d::ui::Text::*)(cocos2d::LabelEffect)>(&cocos2d::ui::Text::disableEffect),static_cast<void(cocos2d::ui::Text::*)()>(&cocos2d::ui::Text::disableEffect)));
mt.set_function("IsShadowEnabled",static_cast<bool(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::isShadowEnabled));
mt.set_function("GetShadowOffset",static_cast<cocos2d::Size(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getShadowOffset));
mt.set_function("GetShadowBlurRadius",static_cast<float(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getShadowBlurRadius));
mt.set_function("GetShadowColor",static_cast<cocos2d::Color4B(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getShadowColor));
mt.set_function("GetOutlineSize",static_cast<int(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getOutlineSize));
mt.set_function("GetLabelEffectType",static_cast<cocos2d::LabelEffect(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getLabelEffectType));
mt.set_function("GetEffectColor",static_cast<cocos2d::Color4B(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getEffectColor));
mt.set_function("GetLetter",static_cast<cocos2d::Sprite*(cocos2d::ui::Text::*)(int)>(&cocos2d::ui::Text::getLetter));
mt.set_function("SetBlendFunc",static_cast<void(cocos2d::ui::Text::*)(const cocos2d::BlendFunc&)>(&cocos2d::ui::Text::setBlendFunc));
mt.set_function("GetBlendFunc",static_cast<const cocos2d::BlendFunc&(cocos2d::ui::Text::*)()const>(&cocos2d::ui::Text::getBlendFunc));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::Text::__Type));
RegisterLuaUITextTypeAuto(lua);
}
void RegisterLuaUITextAtlasAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TextAtlas>("ccui","TextAtlas",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::TextAtlas::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::TextAtlas*(*)(const std::string&,const std::string&,int,int,const std::string&)>(&cocos2d::ui::TextAtlas::create),static_cast<cocos2d::ui::TextAtlas*(*)()>(&cocos2d::ui::TextAtlas::create)));
mt.set_function("SetProperty",static_cast<void(cocos2d::ui::TextAtlas::*)(const std::string&,const std::string&,int,int,const std::string&)>(&cocos2d::ui::TextAtlas::setProperty));
mt.set_function("SetString",static_cast<void(cocos2d::ui::TextAtlas::*)(const std::string&)>(&cocos2d::ui::TextAtlas::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::ui::TextAtlas::*)()const>(&cocos2d::ui::TextAtlas::getString));
mt.set_function("GetStringLength",static_cast<ssize_t(cocos2d::ui::TextAtlas::*)()const>(&cocos2d::ui::TextAtlas::getStringLength));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::TextAtlas::*)()const>(&cocos2d::ui::TextAtlas::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::TextAtlas::*)()>(&cocos2d::ui::TextAtlas::getVirtualRenderer));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::TextAtlas::*)()const>(&cocos2d::ui::TextAtlas::getDescription));
mt.set_function("AdaptRenderers",static_cast<void(cocos2d::ui::TextAtlas::*)()>(&cocos2d::ui::TextAtlas::adaptRenderers));
mt.set_function("GetRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::TextAtlas::*)()>(&cocos2d::ui::TextAtlas::getRenderFile));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::TextAtlas::__Type));
}
void RegisterLuaUILoadingBarDirectionAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LoadingBar"];
pTable.new_enum<cocos2d::ui::LoadingBar::Direction>("Direction",{
{"LEFT",cocos2d::ui::LoadingBar::Direction::LEFT}
,{"RIGHT",cocos2d::ui::LoadingBar::Direction::RIGHT}
});}
void RegisterLuaUILoadingBarAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::LoadingBar>("ccui","LoadingBar",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::LoadingBar::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::LoadingBar* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ui::LoadingBar* obj,const std::string& arg0,float arg1){return obj->create(arg0,arg1);},static_cast<cocos2d::ui::LoadingBar*(*)()>(&cocos2d::ui::LoadingBar::create),[](cocos2d::ui::LoadingBar* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::LoadingBar* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1,float arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("SetDirection",static_cast<void(cocos2d::ui::LoadingBar::*)(cocos2d::ui::LoadingBar::Direction)>(&cocos2d::ui::LoadingBar::setDirection));
mt.set_function("GetDirection",static_cast<cocos2d::ui::LoadingBar::Direction(cocos2d::ui::LoadingBar::*)()const>(&cocos2d::ui::LoadingBar::getDirection));
mt.set_function("LoadTexture",sol::overload([](cocos2d::ui::LoadingBar* obj,const std::string& arg0){return obj->loadTexture(arg0);},[](cocos2d::ui::LoadingBar* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTexture(arg0,arg1);}));
mt.set_function("SetPercent",static_cast<void(cocos2d::ui::LoadingBar::*)(float)>(&cocos2d::ui::LoadingBar::setPercent));
mt.set_function("GetPercent",static_cast<float(cocos2d::ui::LoadingBar::*)()const>(&cocos2d::ui::LoadingBar::getPercent));
mt.set_function("SetScale9Enabled",static_cast<void(cocos2d::ui::LoadingBar::*)(bool)>(&cocos2d::ui::LoadingBar::setScale9Enabled));
mt.set_function("IsScale9Enabled",static_cast<bool(cocos2d::ui::LoadingBar::*)()const>(&cocos2d::ui::LoadingBar::isScale9Enabled));
mt.set_function("SetCapInsets",static_cast<void(cocos2d::ui::LoadingBar::*)(const cocos2d::Rect&)>(&cocos2d::ui::LoadingBar::setCapInsets));
mt.set_function("GetCapInsets",static_cast<const cocos2d::Rect&(cocos2d::ui::LoadingBar::*)()const>(&cocos2d::ui::LoadingBar::getCapInsets));
mt.set_function("IgnoreContentAdaptWithSize",static_cast<void(cocos2d::ui::LoadingBar::*)(bool)>(&cocos2d::ui::LoadingBar::ignoreContentAdaptWithSize));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::LoadingBar::*)()const>(&cocos2d::ui::LoadingBar::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::LoadingBar::*)()>(&cocos2d::ui::LoadingBar::getVirtualRenderer));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::LoadingBar::*)()const>(&cocos2d::ui::LoadingBar::getDescription));
mt.set_function("GetRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::LoadingBar::*)()>(&cocos2d::ui::LoadingBar::getRenderFile));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::LoadingBar::__Type));
RegisterLuaUILoadingBarDirectionAuto(lua);
}
void RegisterLuaUIScrollViewDirectionAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["ScrollView"];
pTable.new_enum<cocos2d::ui::ScrollView::Direction>("Direction",{
{"NONE",cocos2d::ui::ScrollView::Direction::NONE}
,{"VERTICAL",cocos2d::ui::ScrollView::Direction::VERTICAL}
,{"HORIZONTAL",cocos2d::ui::ScrollView::Direction::HORIZONTAL}
,{"BOTH",cocos2d::ui::ScrollView::Direction::BOTH}
});}
void RegisterLuaUIScrollViewEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["ScrollView"];
pTable.new_enum<cocos2d::ui::ScrollView::EventType>("EventType",{
{"SCROLL_TO_TOP",cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP}
,{"SCROLL_TO_BOTTOM",cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM}
,{"SCROLL_TO_LEFT",cocos2d::ui::ScrollView::EventType::SCROLL_TO_LEFT}
,{"SCROLL_TO_RIGHT",cocos2d::ui::ScrollView::EventType::SCROLL_TO_RIGHT}
,{"SCROLLING",cocos2d::ui::ScrollView::EventType::SCROLLING}
,{"BOUNCE_TOP",cocos2d::ui::ScrollView::EventType::BOUNCE_TOP}
,{"BOUNCE_BOTTOM",cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM}
,{"BOUNCE_LEFT",cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT}
,{"BOUNCE_RIGHT",cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT}
,{"CONTAINER_MOVED",cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED}
,{"SCROLLING_BEGAN",cocos2d::ui::ScrollView::EventType::SCROLLING_BEGAN}
,{"SCROLLING_ENDED",cocos2d::ui::ScrollView::EventType::SCROLLING_ENDED}
,{"AUTOSCROLL_ENDED",cocos2d::ui::ScrollView::EventType::AUTOSCROLL_ENDED}
});}
void RegisterLuaUIScrollViewAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::ScrollView>("ccui","ScrollView",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::ScrollView::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::ScrollView*(*)()>(&cocos2d::ui::ScrollView::create));
mt.set_function("SetDirection",static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::ui::ScrollView::Direction)>(&cocos2d::ui::ScrollView::setDirection));
mt.set_function("GetDirection",static_cast<cocos2d::ui::ScrollView::Direction(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getDirection));
mt.set_function("GetInnerContainer",static_cast<cocos2d::ui::Layout*(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getInnerContainer));
mt.set_function("StopScroll",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::stopScroll));
mt.set_function("StopAutoScroll",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::stopAutoScroll));
mt.set_function("StopOverallScroll",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::stopOverallScroll));
mt.set_function("ScrollToBottom",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToBottom));
mt.set_function("ScrollToTop",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToTop));
mt.set_function("ScrollToLeft",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToLeft));
mt.set_function("ScrollToRight",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToRight));
mt.set_function("ScrollToTopLeft",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToTopLeft));
mt.set_function("ScrollToTopRight",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToTopRight));
mt.set_function("ScrollToBottomLeft",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToBottomLeft));
mt.set_function("ScrollToBottomRight",static_cast<void(cocos2d::ui::ScrollView::*)(float,bool)>(&cocos2d::ui::ScrollView::scrollToBottomRight));
mt.set_function("ScrollToPercentVertical",static_cast<void(cocos2d::ui::ScrollView::*)(float,float,bool)>(&cocos2d::ui::ScrollView::scrollToPercentVertical));
mt.set_function("ScrollToPercentHorizontal",static_cast<void(cocos2d::ui::ScrollView::*)(float,float,bool)>(&cocos2d::ui::ScrollView::scrollToPercentHorizontal));
mt.set_function("ScrollToPercentBothDirection",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Vec2&,float,bool)>(&cocos2d::ui::ScrollView::scrollToPercentBothDirection));
mt.set_function("GetScrolledPercentVertical",static_cast<float(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrolledPercentVertical));
mt.set_function("GetScrolledPercentHorizontal",static_cast<float(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrolledPercentHorizontal));
mt.set_function("GetScrolledPercentBothDirection",static_cast<cocos2d::Vec2(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrolledPercentBothDirection));
mt.set_function("JumpToBottom",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToBottom));
mt.set_function("JumpToTop",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToTop));
mt.set_function("JumpToLeft",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToLeft));
mt.set_function("JumpToRight",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToRight));
mt.set_function("JumpToTopLeft",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToTopLeft));
mt.set_function("JumpToTopRight",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToTopRight));
mt.set_function("JumpToBottomLeft",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToBottomLeft));
mt.set_function("JumpToBottomRight",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::jumpToBottomRight));
mt.set_function("JumpToPercentVertical",static_cast<void(cocos2d::ui::ScrollView::*)(float)>(&cocos2d::ui::ScrollView::jumpToPercentVertical));
mt.set_function("JumpToPercentHorizontal",static_cast<void(cocos2d::ui::ScrollView::*)(float)>(&cocos2d::ui::ScrollView::jumpToPercentHorizontal));
mt.set_function("JumpToPercentBothDirection",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ScrollView::jumpToPercentBothDirection));
mt.set_function("SetInnerContainerSize",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Size&)>(&cocos2d::ui::ScrollView::setInnerContainerSize));
mt.set_function("GetInnerContainerSize",static_cast<const cocos2d::Size&(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getInnerContainerSize));
mt.set_function("SetInnerContainerPosition",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ScrollView::setInnerContainerPosition));
mt.set_function("GetInnerContainerPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getInnerContainerPosition));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::ui::ScrollView::ccScrollViewCallback&)>(&cocos2d::ui::ScrollView::addEventListener));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Node*,int)>(&cocos2d::ui::ScrollView::addChild),static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Node*)>(&cocos2d::ui::ScrollView::addChild),static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Node*,int,int)>(&cocos2d::ui::ScrollView::addChild),static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ui::ScrollView::addChild)));
mt.set_function("RemoveAllChildren",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::removeAllChildren));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::ui::ScrollView::*)(bool)>(&cocos2d::ui::ScrollView::removeAllChildrenWithCleanup));
mt.set_function("RemoveChild",sol::overload([](cocos2d::ui::ScrollView* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::ui::ScrollView* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("GetChildren",sol::overload(static_cast<const cocos2d::Vector<cocos2d::Node *>&(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getChildren),static_cast<cocos2d::Vector<cocos2d::Node *>&(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::getChildren)));
mt.set_function("GetChildrenCount",static_cast<ssize_t(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getChildrenCount));
mt.set_function("GetChildByTag",static_cast<cocos2d::Node*(cocos2d::ui::ScrollView::*)(int)const>(&cocos2d::ui::ScrollView::getChildByTag));
mt.set_function("GetChildByName",static_cast<cocos2d::Node*(cocos2d::ui::ScrollView::*)(const std::string&)const>(&cocos2d::ui::ScrollView::getChildByName));
mt.set_function("OnTouchBegan",static_cast<bool(cocos2d::ui::ScrollView::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::ScrollView::onTouchBegan));
mt.set_function("OnTouchMoved",static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::ScrollView::onTouchMoved));
mt.set_function("OnTouchEnded",static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::ScrollView::onTouchEnded));
mt.set_function("OnTouchCancelled",static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::ScrollView::onTouchCancelled));
mt.set_function("Update",static_cast<void(cocos2d::ui::ScrollView::*)(float)>(&cocos2d::ui::ScrollView::update));
mt.set_function("SetBounceEnabled",static_cast<void(cocos2d::ui::ScrollView::*)(bool)>(&cocos2d::ui::ScrollView::setBounceEnabled));
mt.set_function("IsBounceEnabled",static_cast<bool(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::isBounceEnabled));
mt.set_function("SetInertiaScrollEnabled",static_cast<void(cocos2d::ui::ScrollView::*)(bool)>(&cocos2d::ui::ScrollView::setInertiaScrollEnabled));
mt.set_function("IsInertiaScrollEnabled",static_cast<bool(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::isInertiaScrollEnabled));
mt.set_function("SetScrollBarEnabled",static_cast<void(cocos2d::ui::ScrollView::*)(bool)>(&cocos2d::ui::ScrollView::setScrollBarEnabled));
mt.set_function("IsScrollBarEnabled",static_cast<bool(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::isScrollBarEnabled));
mt.set_function("SetScrollBarPositionFromCorner",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ScrollView::setScrollBarPositionFromCorner));
mt.set_function("SetScrollBarPositionFromCornerForVertical",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ScrollView::setScrollBarPositionFromCornerForVertical));
mt.set_function("GetScrollBarPositionFromCornerForVertical",static_cast<cocos2d::Vec2(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrollBarPositionFromCornerForVertical));
mt.set_function("SetScrollBarPositionFromCornerForHorizontal",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ScrollView::setScrollBarPositionFromCornerForHorizontal));
mt.set_function("GetScrollBarPositionFromCornerForHorizontal",static_cast<cocos2d::Vec2(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrollBarPositionFromCornerForHorizontal));
mt.set_function("SetScrollBarWidth",static_cast<void(cocos2d::ui::ScrollView::*)(float)>(&cocos2d::ui::ScrollView::setScrollBarWidth));
mt.set_function("GetScrollBarWidth",static_cast<float(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrollBarWidth));
mt.set_function("SetScrollBarColor",static_cast<void(cocos2d::ui::ScrollView::*)(const cocos2d::Color3B&)>(&cocos2d::ui::ScrollView::setScrollBarColor));
mt.set_function("GetScrollBarColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrollBarColor));
mt.set_function("SetScrollBarOpacity",static_cast<void(cocos2d::ui::ScrollView::*)(uint8_t)>(&cocos2d::ui::ScrollView::setScrollBarOpacity));
mt.set_function("GetScrollBarOpacity",static_cast<uint8_t(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrollBarOpacity));
mt.set_function("SetScrollBarAutoHideEnabled",static_cast<void(cocos2d::ui::ScrollView::*)(bool)>(&cocos2d::ui::ScrollView::setScrollBarAutoHideEnabled));
mt.set_function("IsScrollBarAutoHideEnabled",static_cast<bool(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::isScrollBarAutoHideEnabled));
mt.set_function("SetScrollBarAutoHideTime",static_cast<void(cocos2d::ui::ScrollView::*)(float)>(&cocos2d::ui::ScrollView::setScrollBarAutoHideTime));
mt.set_function("GetScrollBarAutoHideTime",static_cast<float(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getScrollBarAutoHideTime));
mt.set_function("SetTouchTotalTimeThreshold",static_cast<void(cocos2d::ui::ScrollView::*)(float)>(&cocos2d::ui::ScrollView::setTouchTotalTimeThreshold));
mt.set_function("GetTouchTotalTimeThreshold",static_cast<float(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getTouchTotalTimeThreshold));
mt.set_function("SetLayoutType",static_cast<void(cocos2d::ui::ScrollView::*)(cocos2d::ui::Layout::Type)>(&cocos2d::ui::ScrollView::setLayoutType));
mt.set_function("GetLayoutType",static_cast<cocos2d::ui::Layout::Type(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getLayoutType));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::getDescription));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ui::ScrollView::*)()>(&cocos2d::ui::ScrollView::onExit));
mt.set_function("FindNextFocusedWidget",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ScrollView::*)(cocos2d::ui::Widget::FocusDirection,cocos2d::ui::Widget*)>(&cocos2d::ui::ScrollView::findNextFocusedWidget));
mt.set_function("IsScrolling",static_cast<bool(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::isScrolling));
mt.set_function("IsAutoScrolling",static_cast<bool(cocos2d::ui::ScrollView::*)()const>(&cocos2d::ui::ScrollView::isAutoScrolling));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::ScrollView::__Type));
RegisterLuaUIScrollViewDirectionAuto(lua);
RegisterLuaUIScrollViewEventTypeAuto(lua);
}
void RegisterLuaUIListViewGravityAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["ListView"];
pTable.new_enum<cocos2d::ui::ListView::Gravity>("Gravity",{
{"LEFT",cocos2d::ui::ListView::Gravity::LEFT}
,{"RIGHT",cocos2d::ui::ListView::Gravity::RIGHT}
,{"CENTER_HORIZONTAL",cocos2d::ui::ListView::Gravity::CENTER_HORIZONTAL}
,{"TOP",cocos2d::ui::ListView::Gravity::TOP}
,{"BOTTOM",cocos2d::ui::ListView::Gravity::BOTTOM}
,{"CENTER_VERTICAL",cocos2d::ui::ListView::Gravity::CENTER_VERTICAL}
});}
void RegisterLuaUIListViewEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["ListView"];
pTable.new_enum<cocos2d::ui::ListView::EventType>("EventType",{
{"ON_SELECTED_ITEM_START",cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START}
,{"ON_SELECTED_ITEM_END",cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END}
});}
void RegisterLuaUIListViewMagneticTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["ListView"];
pTable.new_enum<cocos2d::ui::ListView::MagneticType>("MagneticType",{
{"NONE",cocos2d::ui::ListView::MagneticType::NONE}
,{"CENTER",cocos2d::ui::ListView::MagneticType::CENTER}
,{"BOTH_END",cocos2d::ui::ListView::MagneticType::BOTH_END}
,{"LEFT",cocos2d::ui::ListView::MagneticType::LEFT}
,{"RIGHT",cocos2d::ui::ListView::MagneticType::RIGHT}
,{"TOP",cocos2d::ui::ListView::MagneticType::TOP}
,{"BOTTOM",cocos2d::ui::ListView::MagneticType::BOTTOM}
});}
void RegisterLuaUIListViewAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::ListView>("ccui","ListView",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::ScrollView,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::ListView::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::ListView*(*)()>(&cocos2d::ui::ListView::create));
mt.set_function("SetItemModel",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::ListView::setItemModel));
mt.set_function("PushBackDefaultItem",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::pushBackDefaultItem));
mt.set_function("InsertDefaultItem",static_cast<void(cocos2d::ui::ListView::*)(ssize_t)>(&cocos2d::ui::ListView::insertDefaultItem));
mt.set_function("PushBackCustomItem",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::ListView::pushBackCustomItem));
mt.set_function("InsertCustomItem",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*,ssize_t)>(&cocos2d::ui::ListView::insertCustomItem));
mt.set_function("RemoveLastItem",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::removeLastItem));
mt.set_function("RemoveItem",static_cast<void(cocos2d::ui::ListView::*)(ssize_t)>(&cocos2d::ui::ListView::removeItem));
mt.set_function("RemoveAllItems",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::removeAllItems));
mt.set_function("GetItem",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)(ssize_t)const>(&cocos2d::ui::ListView::getItem));
mt.set_function("GetItems",static_cast<cocos2d::Vector<cocos2d::ui::Widget *>&(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::getItems));
mt.set_function("GetIndex",static_cast<ssize_t(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*)const>(&cocos2d::ui::ListView::getIndex));
mt.set_function("SetGravity",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::ListView::Gravity)>(&cocos2d::ui::ListView::setGravity));
mt.set_function("SetMagneticType",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::ListView::MagneticType)>(&cocos2d::ui::ListView::setMagneticType));
mt.set_function("GetMagneticType",static_cast<cocos2d::ui::ListView::MagneticType(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getMagneticType));
mt.set_function("SetMagneticAllowedOutOfBoundary",static_cast<void(cocos2d::ui::ListView::*)(bool)>(&cocos2d::ui::ListView::setMagneticAllowedOutOfBoundary));
mt.set_function("GetMagneticAllowedOutOfBoundary",static_cast<bool(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getMagneticAllowedOutOfBoundary));
mt.set_function("SetItemsMargin",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setItemsMargin));
mt.set_function("GetItemsMargin",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getItemsMargin));
mt.set_function("SetPadding",static_cast<void(cocos2d::ui::ListView::*)(float,float,float,float)>(&cocos2d::ui::ListView::setPadding));
mt.set_function("SetLeftPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setLeftPadding));
mt.set_function("SetTopPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setTopPadding));
mt.set_function("SetRightPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setRightPadding));
mt.set_function("SetBottomPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setBottomPadding));
mt.set_function("GetLeftPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getLeftPadding));
mt.set_function("GetTopPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getTopPadding));
mt.set_function("GetRightPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getRightPadding));
mt.set_function("GetBottomPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getBottomPadding));
mt.set_function("SetScrollDuration",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setScrollDuration));
mt.set_function("GetScrollDuration",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getScrollDuration));
mt.set_function("DoLayout",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::doLayout));
mt.set_function("RequestDoLayout",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::requestDoLayout));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*,int)>(&cocos2d::ui::ListView::addChild),static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*)>(&cocos2d::ui::ListView::addChild),static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*,int,int)>(&cocos2d::ui::ListView::addChild),static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ui::ListView::addChild)));
mt.set_function("RemoveAllChildren",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::removeAllChildren));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::ui::ListView::*)(bool)>(&cocos2d::ui::ListView::removeAllChildrenWithCleanup));
mt.set_function("RemoveChild",sol::overload([](cocos2d::ui::ListView* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::ui::ListView* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("GetClosestItemToPosition",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)(const cocos2d::Vec2&,const cocos2d::Vec2&)const>(&cocos2d::ui::ListView::getClosestItemToPosition));
mt.set_function("GetClosestItemToPositionInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)(const cocos2d::Vec2&,const cocos2d::Vec2&)const>(&cocos2d::ui::ListView::getClosestItemToPositionInCurrentView));
mt.set_function("GetCenterItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getCenterItemInCurrentView));
mt.set_function("GetLeftmostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getLeftmostItemInCurrentView));
mt.set_function("GetRightmostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getRightmostItemInCurrentView));
mt.set_function("GetTopmostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getTopmostItemInCurrentView));
mt.set_function("GetBottommostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getBottommostItemInCurrentView));
mt.set_function("JumpToBottom",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToBottom));
mt.set_function("JumpToTop",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToTop));
mt.set_function("JumpToLeft",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToLeft));
mt.set_function("JumpToRight",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToRight));
mt.set_function("JumpToTopLeft",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToTopLeft));
mt.set_function("JumpToTopRight",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToTopRight));
mt.set_function("JumpToBottomLeft",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToBottomLeft));
mt.set_function("JumpToBottomRight",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToBottomRight));
mt.set_function("JumpToPercentVertical",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::jumpToPercentVertical));
mt.set_function("JumpToPercentHorizontal",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::jumpToPercentHorizontal));
mt.set_function("JumpToPercentBothDirection",static_cast<void(cocos2d::ui::ListView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ListView::jumpToPercentBothDirection));
mt.set_function("JumpToItem",static_cast<void(cocos2d::ui::ListView::*)(ssize_t,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ui::ListView::jumpToItem));
mt.set_function("ScrollToItem",sol::overload(static_cast<void(cocos2d::ui::ListView::*)(ssize_t,const cocos2d::Vec2&,const cocos2d::Vec2&,float)>(&cocos2d::ui::ListView::scrollToItem),static_cast<void(cocos2d::ui::ListView::*)(ssize_t,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ui::ListView::scrollToItem)));
mt.set_function("GetCurSelectedIndex",static_cast<ssize_t(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getCurSelectedIndex));
mt.set_function("SetCurSelectedIndex",static_cast<void(cocos2d::ui::ListView::*)(int)>(&cocos2d::ui::ListView::setCurSelectedIndex));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::ListView::*)(const cocos2d::ui::ListView::ccListViewCallback&)>(&cocos2d::ui::ListView::addEventListener));
mt.set_function("SetDirection",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::ScrollView::Direction)>(&cocos2d::ui::ListView::setDirection));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getDescription));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::ListView::__Type));
RegisterLuaUIListViewGravityAuto(lua);
RegisterLuaUIListViewEventTypeAuto(lua);
RegisterLuaUIListViewMagneticTypeAuto(lua);
}
void RegisterLuaUISliderEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Slider"];
pTable.new_enum<cocos2d::ui::Slider::EventType>("EventType",{
{"ON_PERCENTAGE_CHANGED",cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED}
,{"ON_SLIDEBALL_DOWN",cocos2d::ui::Slider::EventType::ON_SLIDEBALL_DOWN}
,{"ON_SLIDEBALL_UP",cocos2d::ui::Slider::EventType::ON_SLIDEBALL_UP}
,{"ON_SLIDEBALL_CANCEL",cocos2d::ui::Slider::EventType::ON_SLIDEBALL_CANCEL}
});}
void RegisterLuaUISliderAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Slider>("ccui","Slider",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Slider::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::ui::Slider*(*)()>(&cocos2d::ui::Slider::create)));
mt.set_function("LoadBarTexture",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadBarTexture(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadBarTexture(arg0,arg1);}));
mt.set_function("SetScale9Enabled",static_cast<void(cocos2d::ui::Slider::*)(bool)>(&cocos2d::ui::Slider::setScale9Enabled));
mt.set_function("IsScale9Enabled",static_cast<bool(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::isScale9Enabled));
mt.set_function("SetCapInsets",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::Rect&)>(&cocos2d::ui::Slider::setCapInsets));
mt.set_function("SetCapInsetsBarRenderer",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::Rect&)>(&cocos2d::ui::Slider::setCapInsetsBarRenderer));
mt.set_function("GetCapInsetsBarRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getCapInsetsBarRenderer));
mt.set_function("SetCapInsetProgressBarRenderer",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::Rect&)>(&cocos2d::ui::Slider::setCapInsetProgressBarRenderer));
mt.set_function("GetCapInsetsProgressBarRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getCapInsetsProgressBarRenderer));
mt.set_function("LoadSlidBallTextures",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTextures(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1){return obj->loadSlidBallTextures(arg0,arg1);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->loadSlidBallTextures(arg0,arg1,arg2);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->loadSlidBallTextures(arg0,arg1,arg2,arg3);}));
mt.set_function("LoadSlidBallTextureNormal",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTextureNormal(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadSlidBallTextureNormal(arg0,arg1);}));
mt.set_function("LoadSlidBallTexturePressed",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTexturePressed(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadSlidBallTexturePressed(arg0,arg1);}));
mt.set_function("LoadSlidBallTextureDisabled",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTextureDisabled(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadSlidBallTextureDisabled(arg0,arg1);}));
mt.set_function("LoadProgressBarTexture",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadProgressBarTexture(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadProgressBarTexture(arg0,arg1);}));
mt.set_function("SetPercent",static_cast<void(cocos2d::ui::Slider::*)(int)>(&cocos2d::ui::Slider::setPercent));
mt.set_function("UpdateVisualSlider",static_cast<void(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::updateVisualSlider));
mt.set_function("GetPercent",static_cast<int(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getPercent));
mt.set_function("SetMaxPercent",static_cast<void(cocos2d::ui::Slider::*)(int)>(&cocos2d::ui::Slider::setMaxPercent));
mt.set_function("GetMaxPercent",static_cast<int(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getMaxPercent));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::ui::Slider::ccSliderCallback&)>(&cocos2d::ui::Slider::addEventListener));
mt.set_function("OnTouchBegan",static_cast<bool(cocos2d::ui::Slider::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Slider::onTouchBegan));
mt.set_function("OnTouchMoved",static_cast<void(cocos2d::ui::Slider::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Slider::onTouchMoved));
mt.set_function("OnTouchEnded",static_cast<void(cocos2d::ui::Slider::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Slider::onTouchEnded));
mt.set_function("OnTouchCancelled",static_cast<void(cocos2d::ui::Slider::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Slider::onTouchCancelled));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getVirtualRenderer));
mt.set_function("IgnoreContentAdaptWithSize",static_cast<void(cocos2d::ui::Slider::*)(bool)>(&cocos2d::ui::Slider::ignoreContentAdaptWithSize));
mt.set_function("HitTest",static_cast<bool(cocos2d::ui::Slider::*)(const cocos2d::Vec2&,const cocos2d::Camera*,cocos2d::Vec3*)const>(&cocos2d::ui::Slider::hitTest));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getDescription));
mt.set_function("SetZoomScale",static_cast<void(cocos2d::ui::Slider::*)(float)>(&cocos2d::ui::Slider::setZoomScale));
mt.set_function("GetZoomScale",static_cast<float(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getZoomScale));
mt.set_function("GetSlidBallNormalRenderer",static_cast<cocos2d::Sprite*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallNormalRenderer));
mt.set_function("GetSlidBallPressedRenderer",static_cast<cocos2d::Sprite*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallPressedRenderer));
mt.set_function("GetSlidBallDisabledRenderer",static_cast<cocos2d::Sprite*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallDisabledRenderer));
mt.set_function("GetSlidBallRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallRenderer));
mt.set_function("GetBackFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBackFile));
mt.set_function("GetProgressBarFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getProgressBarFile));
mt.set_function("GetBallNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBallNormalFile));
mt.set_function("GetBallPressedFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBallPressedFile));
mt.set_function("GetBallDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBallDisabledFile));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::Slider::__Type));
RegisterLuaUISliderEventTypeAuto(lua);
}
void RegisterLuaUITextFieldEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["TextField"];
pTable.new_enum<cocos2d::ui::TextField::EventType>("EventType",{
{"ATTACH_WITH_IME",cocos2d::ui::TextField::EventType::ATTACH_WITH_IME}
,{"DETACH_WITH_IME",cocos2d::ui::TextField::EventType::DETACH_WITH_IME}
,{"INSERT_TEXT",cocos2d::ui::TextField::EventType::INSERT_TEXT}
,{"DELETE_BACKWARD",cocos2d::ui::TextField::EventType::DELETE_BACKWARD}
});}
void RegisterLuaUITextFieldAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TextField>("ccui","TextField",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::TextField::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::TextField*(*)(const std::string&,const std::string&,int)>(&cocos2d::ui::TextField::create),static_cast<cocos2d::ui::TextField*(*)()>(&cocos2d::ui::TextField::create)));
mt.set_function("SetTouchSize",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Size&)>(&cocos2d::ui::TextField::setTouchSize));
mt.set_function("GetTouchSize",static_cast<cocos2d::Size(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTouchSize));
mt.set_function("SetTouchAreaEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setTouchAreaEnabled));
mt.set_function("HitTest",static_cast<bool(cocos2d::ui::TextField::*)(const cocos2d::Vec2&,const cocos2d::Camera*,cocos2d::Vec3*)const>(&cocos2d::ui::TextField::hitTest));
mt.set_function("SetPlaceHolder",static_cast<void(cocos2d::ui::TextField::*)(const std::string&)>(&cocos2d::ui::TextField::setPlaceHolder));
mt.set_function("GetPlaceHolder",static_cast<const std::string&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getPlaceHolder));
mt.set_function("GetPlaceHolderColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getPlaceHolderColor));
mt.set_function("SetPlaceHolderColor",sol::overload(static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Color4B&)>(&cocos2d::ui::TextField::setPlaceHolderColor),static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Color3B&)>(&cocos2d::ui::TextField::setPlaceHolderColor)));
mt.set_function("GetTextColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTextColor));
mt.set_function("SetTextColor",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Color4B&)>(&cocos2d::ui::TextField::setTextColor));
mt.set_function("SetFontSize",static_cast<void(cocos2d::ui::TextField::*)(int)>(&cocos2d::ui::TextField::setFontSize));
mt.set_function("GetFontSize",static_cast<int(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getFontSize));
mt.set_function("SetFontName",static_cast<void(cocos2d::ui::TextField::*)(const std::string&)>(&cocos2d::ui::TextField::setFontName));
mt.set_function("GetFontName",static_cast<const std::string&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getFontName));
mt.set_function("DidNotSelectSelf",static_cast<void(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::didNotSelectSelf));
mt.set_function("SetString",static_cast<void(cocos2d::ui::TextField::*)(const std::string&)>(&cocos2d::ui::TextField::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getString));
mt.set_function("OnTouchBegan",static_cast<bool(cocos2d::ui::TextField::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::TextField::onTouchBegan));
mt.set_function("SetMaxLengthEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setMaxLengthEnabled));
mt.set_function("IsMaxLengthEnabled",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::isMaxLengthEnabled));
mt.set_function("SetMaxLength",static_cast<void(cocos2d::ui::TextField::*)(int)>(&cocos2d::ui::TextField::setMaxLength));
mt.set_function("GetMaxLength",static_cast<int(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getMaxLength));
mt.set_function("GetStringLength",static_cast<int(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getStringLength));
mt.set_function("SetPasswordEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setPasswordEnabled));
mt.set_function("IsPasswordEnabled",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::isPasswordEnabled));
mt.set_function("SetPasswordStyleText",static_cast<void(cocos2d::ui::TextField::*)(const char*)>(&cocos2d::ui::TextField::setPasswordStyleText));
mt.set_function("GetPasswordStyleText",static_cast<const char*(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getPasswordStyleText));
mt.set_function("Update",static_cast<void(cocos2d::ui::TextField::*)(float)>(&cocos2d::ui::TextField::update));
mt.set_function("GetAttachWithIME",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getAttachWithIME));
mt.set_function("SetAttachWithIME",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setAttachWithIME));
mt.set_function("GetDetachWithIME",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getDetachWithIME));
mt.set_function("SetDetachWithIME",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setDetachWithIME));
mt.set_function("GetInsertText",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getInsertText));
mt.set_function("SetInsertText",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setInsertText));
mt.set_function("GetDeleteBackward",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getDeleteBackward));
mt.set_function("SetDeleteBackward",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setDeleteBackward));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::ui::TextField::ccTextFieldCallback&)>(&cocos2d::ui::TextField::addEventListener));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getDescription));
mt.set_function("GetAutoRenderSize",static_cast<cocos2d::Size(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::getAutoRenderSize));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::getVirtualRenderer));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::onEnter));
mt.set_function("AttachWithIME",static_cast<void(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::attachWithIME));
mt.set_function("SetTextAreaSize",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Size&)>(&cocos2d::ui::TextField::setTextAreaSize));
mt.set_function("SetTextHorizontalAlignment",static_cast<void(cocos2d::ui::TextField::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::TextField::setTextHorizontalAlignment));
mt.set_function("GetTextHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTextHorizontalAlignment));
mt.set_function("SetTextVerticalAlignment",static_cast<void(cocos2d::ui::TextField::*)(cocos2d::TextVAlignment)>(&cocos2d::ui::TextField::setTextVerticalAlignment));
mt.set_function("GetTextVerticalAlignment",static_cast<cocos2d::TextVAlignment(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTextVerticalAlignment));
mt.set_function("SetCursorEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setCursorEnabled));
mt.set_function("SetCursorChar",static_cast<void(cocos2d::ui::TextField::*)(char)>(&cocos2d::ui::TextField::setCursorChar));
mt.set_function("SetCursorPosition",static_cast<void(cocos2d::ui::TextField::*)(size_t)>(&cocos2d::ui::TextField::setCursorPosition));
mt.set_function("SetCursorFromPoint",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Vec2&,const cocos2d::Camera*)>(&cocos2d::ui::TextField::setCursorFromPoint));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::TextField::__Type));
RegisterLuaUITextFieldEventTypeAuto(lua);
}
void RegisterLuaUITextBMFontAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TextBMFont>("ccui","TextBMFont",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::TextBMFont::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::TextBMFont*(*)(const std::string&,const std::string&)>(&cocos2d::ui::TextBMFont::create),static_cast<cocos2d::ui::TextBMFont*(*)()>(&cocos2d::ui::TextBMFont::create)));
mt.set_function("SetFntFile",static_cast<void(cocos2d::ui::TextBMFont::*)(const std::string&)>(&cocos2d::ui::TextBMFont::setFntFile));
mt.set_function("SetString",static_cast<void(cocos2d::ui::TextBMFont::*)(const std::string&)>(&cocos2d::ui::TextBMFont::setString));
mt.set_function("GetString",static_cast<const std::string&(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getString));
mt.set_function("GetStringLength",static_cast<ssize_t(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getStringLength));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::TextBMFont::*)()>(&cocos2d::ui::TextBMFont::getVirtualRenderer));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getDescription));
mt.set_function("GetRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::TextBMFont::*)()>(&cocos2d::ui::TextBMFont::getRenderFile));
mt.set_function("ResetRender",static_cast<void(cocos2d::ui::TextBMFont::*)()>(&cocos2d::ui::TextBMFont::resetRender));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::TextBMFont::__Type));
}
void RegisterLuaUIPageViewEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["PageView"];
pTable.new_enum<cocos2d::ui::PageView::EventType>("EventType",{
{"TURNING",cocos2d::ui::PageView::EventType::TURNING}
});}
void RegisterLuaUIPageViewTouchDirectionAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["PageView"];
pTable.new_enum<cocos2d::ui::PageView::TouchDirection>("TouchDirection",{
{"LEFT",cocos2d::ui::PageView::TouchDirection::LEFT}
,{"RIGHT",cocos2d::ui::PageView::TouchDirection::RIGHT}
,{"UP",cocos2d::ui::PageView::TouchDirection::UP}
,{"DOWN",cocos2d::ui::PageView::TouchDirection::DOWN}
});}
void RegisterLuaUIPageViewAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::PageView>("ccui","PageView",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::ListView,cocos2d::ui::ScrollView,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::PageView::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::PageView*(*)()>(&cocos2d::ui::PageView::create));
mt.set_function("SetDirection",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::ScrollView::Direction)>(&cocos2d::ui::PageView::setDirection));
mt.set_function("AddPage",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::PageView::addPage));
mt.set_function("InsertPage",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::PageView::insertPage));
mt.set_function("RemovePage",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::PageView::removePage));
mt.set_function("RemovePageAtIndex",static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::removePageAtIndex));
mt.set_function("RemoveAllPages",static_cast<void(cocos2d::ui::PageView::*)()>(&cocos2d::ui::PageView::removeAllPages));
mt.set_function("ScrollToPage",sol::overload(static_cast<void(cocos2d::ui::PageView::*)(ssize_t,float)>(&cocos2d::ui::PageView::scrollToPage),static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::scrollToPage)));
mt.set_function("ScrollToItem",sol::overload(static_cast<void(cocos2d::ui::PageView::*)(ssize_t,float)>(&cocos2d::ui::PageView::scrollToItem),static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::scrollToItem)));
mt.set_function("GetCurrentPageIndex",static_cast<ssize_t(cocos2d::ui::PageView::*)()>(&cocos2d::ui::PageView::getCurrentPageIndex));
mt.set_function("SetCurrentPageIndex",static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::setCurrentPageIndex));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::ui::PageView::ccPageViewCallback&)>(&cocos2d::ui::PageView::addEventListener));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getDescription));
mt.set_function("SetIndicatorEnabled",static_cast<void(cocos2d::ui::PageView::*)(bool)>(&cocos2d::ui::PageView::setIndicatorEnabled));
mt.set_function("GetIndicatorEnabled",static_cast<bool(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorEnabled));
mt.set_function("SetIndicatorPositionAsAnchorPoint",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::PageView::setIndicatorPositionAsAnchorPoint));
mt.set_function("GetIndicatorPositionAsAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorPositionAsAnchorPoint));
mt.set_function("SetIndicatorPosition",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::PageView::setIndicatorPosition));
mt.set_function("GetIndicatorPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorPosition));
mt.set_function("SetIndicatorSpaceBetweenIndexNodes",static_cast<void(cocos2d::ui::PageView::*)(float)>(&cocos2d::ui::PageView::setIndicatorSpaceBetweenIndexNodes));
mt.set_function("GetIndicatorSpaceBetweenIndexNodes",static_cast<float(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorSpaceBetweenIndexNodes));
mt.set_function("SetIndicatorSelectedIndexColor",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Color3B&)>(&cocos2d::ui::PageView::setIndicatorSelectedIndexColor));
mt.set_function("GetIndicatorSelectedIndexColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorSelectedIndexColor));
mt.set_function("SetIndicatorIndexNodesColor",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Color3B&)>(&cocos2d::ui::PageView::setIndicatorIndexNodesColor));
mt.set_function("GetIndicatorIndexNodesColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorIndexNodesColor));
mt.set_function("SetIndicatorSelectedIndexOpacity",static_cast<void(cocos2d::ui::PageView::*)(uint8_t)>(&cocos2d::ui::PageView::setIndicatorSelectedIndexOpacity));
mt.set_function("GetIndicatorSelectedIndexOpacity",static_cast<uint8_t(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorSelectedIndexOpacity));
mt.set_function("SetIndicatorIndexNodesOpacity",static_cast<void(cocos2d::ui::PageView::*)(uint8_t)>(&cocos2d::ui::PageView::setIndicatorIndexNodesOpacity));
mt.set_function("GetIndicatorIndexNodesOpacity",static_cast<uint8_t(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorIndexNodesOpacity));
mt.set_function("SetIndicatorIndexNodesScale",static_cast<void(cocos2d::ui::PageView::*)(float)>(&cocos2d::ui::PageView::setIndicatorIndexNodesScale));
mt.set_function("SetIndicatorIndexNodesTexture",sol::overload([](cocos2d::ui::PageView* obj,const std::string& arg0){return obj->setIndicatorIndexNodesTexture(arg0);},[](cocos2d::ui::PageView* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->setIndicatorIndexNodesTexture(arg0,arg1);}));
mt.set_function("GetIndicatorIndexNodesScale",static_cast<float(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorIndexNodesScale));
mt.set_function("SetAutoScrollStopEpsilon",static_cast<void(cocos2d::ui::PageView::*)(float)>(&cocos2d::ui::PageView::setAutoScrollStopEpsilon));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::PageView::__Type));
RegisterLuaUIPageViewEventTypeAuto(lua);
RegisterLuaUIPageViewTouchDirectionAuto(lua);
}
