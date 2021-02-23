#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUIListViewAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::ListView,cocos2d::ui::ScrollView,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("ccui","ListView");
mt.set_function("setItemModel",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::ListView::setItemModel));
mt.set_function("pushBackDefaultItem",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::pushBackDefaultItem));
mt.set_function("insertDefaultItem",static_cast<void(cocos2d::ui::ListView::*)(ssize_t)>(&cocos2d::ui::ListView::insertDefaultItem));
mt.set_function("pushBackCustomItem",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::ListView::pushBackCustomItem));
mt.set_function("insertCustomItem",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*,ssize_t)>(&cocos2d::ui::ListView::insertCustomItem));
mt.set_function("removeLastItem",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::removeLastItem));
mt.set_function("removeItem",static_cast<void(cocos2d::ui::ListView::*)(ssize_t)>(&cocos2d::ui::ListView::removeItem));
mt.set_function("removeAllItems",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::removeAllItems));
mt.set_function("getItem",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)(ssize_t)const>(&cocos2d::ui::ListView::getItem));
mt.set_function("getItems",static_cast<cocos2d::Vector<cocos2d::ui::Widget *>&(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::getItems));
mt.set_function("getIndex",static_cast<ssize_t(cocos2d::ui::ListView::*)(cocos2d::ui::Widget*)const>(&cocos2d::ui::ListView::getIndex));
mt.set_function("setGravity",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::ListView::Gravity)>(&cocos2d::ui::ListView::setGravity));
mt.set_function("setMagneticType",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::ListView::MagneticType)>(&cocos2d::ui::ListView::setMagneticType));
mt.set_function("getMagneticType",static_cast<cocos2d::ui::ListView::MagneticType(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getMagneticType));
mt.set_function("setMagneticAllowedOutOfBoundary",static_cast<void(cocos2d::ui::ListView::*)(bool)>(&cocos2d::ui::ListView::setMagneticAllowedOutOfBoundary));
mt.set_function("getMagneticAllowedOutOfBoundary",static_cast<bool(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getMagneticAllowedOutOfBoundary));
mt.set_function("setItemsMargin",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setItemsMargin));
mt.set_function("getItemsMargin",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getItemsMargin));
mt.set_function("setPadding",static_cast<void(cocos2d::ui::ListView::*)(float,float,float,float)>(&cocos2d::ui::ListView::setPadding));
mt.set_function("setLeftPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setLeftPadding));
mt.set_function("setTopPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setTopPadding));
mt.set_function("setRightPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setRightPadding));
mt.set_function("setBottomPadding",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setBottomPadding));
mt.set_function("getLeftPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getLeftPadding));
mt.set_function("getTopPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getTopPadding));
mt.set_function("getRightPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getRightPadding));
mt.set_function("getBottomPadding",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getBottomPadding));
mt.set_function("setScrollDuration",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::setScrollDuration));
mt.set_function("getScrollDuration",static_cast<float(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getScrollDuration));
mt.set_function("doLayout",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::doLayout));
mt.set_function("requestDoLayout",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::requestDoLayout));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*,int)>(&cocos2d::ui::ListView::addChild),static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*)>(&cocos2d::ui::ListView::addChild),static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*,int,int)>(&cocos2d::ui::ListView::addChild),static_cast<void(cocos2d::ui::ListView::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ui::ListView::addChild)));
mt.set_function("removeAllChildren",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::removeAllChildren));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::ui::ListView::*)(bool)>(&cocos2d::ui::ListView::removeAllChildrenWithCleanup));
mt.set_function("removeChild",sol::overload([](cocos2d::ui::ListView* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::ui::ListView* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("getClosestItemToPosition",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)(const cocos2d::Vec2&,const cocos2d::Vec2&)const>(&cocos2d::ui::ListView::getClosestItemToPosition));
mt.set_function("getClosestItemToPositionInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)(const cocos2d::Vec2&,const cocos2d::Vec2&)const>(&cocos2d::ui::ListView::getClosestItemToPositionInCurrentView));
mt.set_function("getCenterItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getCenterItemInCurrentView));
mt.set_function("getLeftmostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getLeftmostItemInCurrentView));
mt.set_function("getRightmostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getRightmostItemInCurrentView));
mt.set_function("getTopmostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getTopmostItemInCurrentView));
mt.set_function("getBottommostItemInCurrentView",static_cast<cocos2d::ui::Widget*(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getBottommostItemInCurrentView));
mt.set_function("jumpToBottom",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToBottom));
mt.set_function("jumpToTop",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToTop));
mt.set_function("jumpToLeft",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToLeft));
mt.set_function("jumpToRight",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToRight));
mt.set_function("jumpToTopLeft",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToTopLeft));
mt.set_function("jumpToTopRight",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToTopRight));
mt.set_function("jumpToBottomLeft",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToBottomLeft));
mt.set_function("jumpToBottomRight",static_cast<void(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::jumpToBottomRight));
mt.set_function("jumpToPercentVertical",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::jumpToPercentVertical));
mt.set_function("jumpToPercentHorizontal",static_cast<void(cocos2d::ui::ListView::*)(float)>(&cocos2d::ui::ListView::jumpToPercentHorizontal));
mt.set_function("jumpToPercentBothDirection",static_cast<void(cocos2d::ui::ListView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::ListView::jumpToPercentBothDirection));
mt.set_function("jumpToItem",static_cast<void(cocos2d::ui::ListView::*)(ssize_t,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ui::ListView::jumpToItem));
mt.set_function("scrollToItem",sol::overload(static_cast<void(cocos2d::ui::ListView::*)(ssize_t,const cocos2d::Vec2&,const cocos2d::Vec2&,float)>(&cocos2d::ui::ListView::scrollToItem),static_cast<void(cocos2d::ui::ListView::*)(ssize_t,const cocos2d::Vec2&,const cocos2d::Vec2&)>(&cocos2d::ui::ListView::scrollToItem)));
mt.set_function("getCurSelectedIndex",static_cast<ssize_t(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getCurSelectedIndex));
mt.set_function("setCurSelectedIndex",static_cast<void(cocos2d::ui::ListView::*)(int)>(&cocos2d::ui::ListView::setCurSelectedIndex));
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::ListView::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::ListView::EventType)>&)>(&cocos2d::ui::ListView::addEventListener));
mt.set_function("setDirection",static_cast<void(cocos2d::ui::ListView::*)(cocos2d::ui::ScrollView::Direction)>(&cocos2d::ui::ListView::setDirection));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::ListView::*)()const>(&cocos2d::ui::ListView::getDescription));
mt.set_function("init",static_cast<bool(cocos2d::ui::ListView::*)()>(&cocos2d::ui::ListView::init));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::ListView::createInstance));
mt.set_function("new",static_cast<cocos2d::ui::ListView*(*)()>(&cocos2d::ui::ListView::create));
}
void RegisterLuaUISliderAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Slider,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","Slider");
mt.set_function("loadBarTexture",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadBarTexture(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadBarTexture(arg0,arg1);}));
mt.set_function("setScale9Enabled",static_cast<void(cocos2d::ui::Slider::*)(bool)>(&cocos2d::ui::Slider::setScale9Enabled));
mt.set_function("isScale9Enabled",static_cast<bool(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::isScale9Enabled));
mt.set_function("setCapInsets",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::Rect&)>(&cocos2d::ui::Slider::setCapInsets));
mt.set_function("setCapInsetsBarRenderer",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::Rect&)>(&cocos2d::ui::Slider::setCapInsetsBarRenderer));
mt.set_function("getCapInsetsBarRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getCapInsetsBarRenderer));
mt.set_function("setCapInsetProgressBarRenderer",static_cast<void(cocos2d::ui::Slider::*)(const cocos2d::Rect&)>(&cocos2d::ui::Slider::setCapInsetProgressBarRenderer));
mt.set_function("getCapInsetsProgressBarRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getCapInsetsProgressBarRenderer));
mt.set_function("loadSlidBallTextures",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTextures(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1){return obj->loadSlidBallTextures(arg0,arg1);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->loadSlidBallTextures(arg0,arg1,arg2);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->loadSlidBallTextures(arg0,arg1,arg2,arg3);}));
mt.set_function("loadSlidBallTextureNormal",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTextureNormal(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadSlidBallTextureNormal(arg0,arg1);}));
mt.set_function("loadSlidBallTexturePressed",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTexturePressed(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadSlidBallTexturePressed(arg0,arg1);}));
mt.set_function("loadSlidBallTextureDisabled",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadSlidBallTextureDisabled(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadSlidBallTextureDisabled(arg0,arg1);}));
mt.set_function("loadProgressBarTexture",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0){return obj->loadProgressBarTexture(arg0);},[](cocos2d::ui::Slider* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadProgressBarTexture(arg0,arg1);}));
mt.set_function("setPercent",static_cast<void(cocos2d::ui::Slider::*)(int)>(&cocos2d::ui::Slider::setPercent));
mt.set_function("updateVisualSlider",static_cast<void(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::updateVisualSlider));
mt.set_function("getPercent",static_cast<int(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getPercent));
mt.set_function("setMaxPercent",static_cast<void(cocos2d::ui::Slider::*)(int)>(&cocos2d::ui::Slider::setMaxPercent));
mt.set_function("getMaxPercent",static_cast<int(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getMaxPercent));
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::Slider::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::Slider::EventType)>&)>(&cocos2d::ui::Slider::addEventListener));
mt.set_function("getVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getVirtualRendererSize));
mt.set_function("getVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getVirtualRenderer));
mt.set_function("ignoreContentAdaptWithSize",static_cast<void(cocos2d::ui::Slider::*)(bool)>(&cocos2d::ui::Slider::ignoreContentAdaptWithSize));
mt.set_function("hitTest",static_cast<bool(cocos2d::ui::Slider::*)(const cocos2d::Vec2&,const cocos2d::Camera*,cocos2d::Vec3*)const>(&cocos2d::ui::Slider::hitTest));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getDescription));
mt.set_function("setZoomScale",static_cast<void(cocos2d::ui::Slider::*)(float)>(&cocos2d::ui::Slider::setZoomScale));
mt.set_function("getZoomScale",static_cast<float(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getZoomScale));
mt.set_function("getSlidBallNormalRenderer",static_cast<cocos2d::Sprite*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallNormalRenderer));
mt.set_function("getSlidBallPressedRenderer",static_cast<cocos2d::Sprite*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallPressedRenderer));
mt.set_function("getSlidBallDisabledRenderer",static_cast<cocos2d::Sprite*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallDisabledRenderer));
mt.set_function("getSlidBallRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Slider::*)()const>(&cocos2d::ui::Slider::getSlidBallRenderer));
mt.set_function("getBackFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBackFile));
mt.set_function("getProgressBarFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getProgressBarFile));
mt.set_function("getBallNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBallNormalFile));
mt.set_function("getBallPressedFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBallPressedFile));
mt.set_function("getBallDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::getBallDisabledFile));
mt.set_function("init",static_cast<bool(cocos2d::ui::Slider::*)()>(&cocos2d::ui::Slider::init));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Slider::createInstance));
mt.set_function("new",sol::overload([](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::Slider* obj,const std::string& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->create(arg0,arg1,arg2);},static_cast<cocos2d::ui::Slider*(*)()>(&cocos2d::ui::Slider::create)));
}
void RegisterLuaUITextFieldAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TextField,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","TextField");
mt.set_function("setTouchSize",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Size&)>(&cocos2d::ui::TextField::setTouchSize));
mt.set_function("getTouchSize",static_cast<cocos2d::Size(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTouchSize));
mt.set_function("setTouchAreaEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setTouchAreaEnabled));
mt.set_function("hitTest",static_cast<bool(cocos2d::ui::TextField::*)(const cocos2d::Vec2&,const cocos2d::Camera*,cocos2d::Vec3*)const>(&cocos2d::ui::TextField::hitTest));
mt.set_function("setPlaceHolder",static_cast<void(cocos2d::ui::TextField::*)(const std::string&)>(&cocos2d::ui::TextField::setPlaceHolder));
mt.set_function("getPlaceHolder",static_cast<const std::string&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getPlaceHolder));
mt.set_function("getPlaceHolderColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getPlaceHolderColor));
mt.set_function("setPlaceHolderColor",sol::overload(static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Color4B&)>(&cocos2d::ui::TextField::setPlaceHolderColor),static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Color3B&)>(&cocos2d::ui::TextField::setPlaceHolderColor)));
mt.set_function("getTextColor",static_cast<const cocos2d::Color4B&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTextColor));
mt.set_function("setTextColor",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Color4B&)>(&cocos2d::ui::TextField::setTextColor));
mt.set_function("setFontSize",static_cast<void(cocos2d::ui::TextField::*)(int)>(&cocos2d::ui::TextField::setFontSize));
mt.set_function("getFontSize",static_cast<int(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getFontSize));
mt.set_function("setFontName",static_cast<void(cocos2d::ui::TextField::*)(const std::string&)>(&cocos2d::ui::TextField::setFontName));
mt.set_function("getFontName",static_cast<const std::string&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getFontName));
mt.set_function("didNotSelectSelf",static_cast<void(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::didNotSelectSelf));
mt.set_function("setString",static_cast<void(cocos2d::ui::TextField::*)(const std::string&)>(&cocos2d::ui::TextField::setString));
mt.set_function("getString",static_cast<const std::string&(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getString));
mt.set_function("setMaxLengthEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setMaxLengthEnabled));
mt.set_function("isMaxLengthEnabled",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::isMaxLengthEnabled));
mt.set_function("setMaxLength",static_cast<void(cocos2d::ui::TextField::*)(int)>(&cocos2d::ui::TextField::setMaxLength));
mt.set_function("getMaxLength",static_cast<int(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getMaxLength));
mt.set_function("getStringLength",static_cast<int(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getStringLength));
mt.set_function("setPasswordEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setPasswordEnabled));
mt.set_function("isPasswordEnabled",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::isPasswordEnabled));
mt.set_function("setPasswordStyleText",static_cast<void(cocos2d::ui::TextField::*)(const char*)>(&cocos2d::ui::TextField::setPasswordStyleText));
mt.set_function("getPasswordStyleText",static_cast<const char*(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getPasswordStyleText));
mt.set_function("update",static_cast<void(cocos2d::ui::TextField::*)(float)>(&cocos2d::ui::TextField::update));
mt.set_function("getAttachWithIME",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getAttachWithIME));
mt.set_function("setAttachWithIME",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setAttachWithIME));
mt.set_function("getDetachWithIME",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getDetachWithIME));
mt.set_function("setDetachWithIME",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setDetachWithIME));
mt.set_function("getInsertText",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getInsertText));
mt.set_function("setInsertText",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setInsertText));
mt.set_function("getDeleteBackward",static_cast<bool(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getDeleteBackward));
mt.set_function("setDeleteBackward",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setDeleteBackward));
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::TextField::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::TextField::EventType)>&)>(&cocos2d::ui::TextField::addEventListener));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getDescription));
mt.set_function("getAutoRenderSize",static_cast<cocos2d::Size(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::getAutoRenderSize));
mt.set_function("getVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getVirtualRendererSize));
mt.set_function("getVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::getVirtualRenderer));
mt.set_function("attachWithIME",static_cast<void(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::attachWithIME));
mt.set_function("setTextAreaSize",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Size&)>(&cocos2d::ui::TextField::setTextAreaSize));
mt.set_function("setTextHorizontalAlignment",static_cast<void(cocos2d::ui::TextField::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::TextField::setTextHorizontalAlignment));
mt.set_function("getTextHorizontalAlignment",static_cast<cocos2d::TextHAlignment(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTextHorizontalAlignment));
mt.set_function("setTextVerticalAlignment",static_cast<void(cocos2d::ui::TextField::*)(cocos2d::TextVAlignment)>(&cocos2d::ui::TextField::setTextVerticalAlignment));
mt.set_function("getTextVerticalAlignment",static_cast<cocos2d::TextVAlignment(cocos2d::ui::TextField::*)()const>(&cocos2d::ui::TextField::getTextVerticalAlignment));
mt.set_function("setCursorEnabled",static_cast<void(cocos2d::ui::TextField::*)(bool)>(&cocos2d::ui::TextField::setCursorEnabled));
mt.set_function("setCursorChar",static_cast<void(cocos2d::ui::TextField::*)(char)>(&cocos2d::ui::TextField::setCursorChar));
mt.set_function("setCursorPosition",static_cast<void(cocos2d::ui::TextField::*)(size_t)>(&cocos2d::ui::TextField::setCursorPosition));
mt.set_function("setCursorFromPoint",static_cast<void(cocos2d::ui::TextField::*)(const cocos2d::Vec2&,const cocos2d::Camera*)>(&cocos2d::ui::TextField::setCursorFromPoint));
mt.set_function("init",static_cast<bool(cocos2d::ui::TextField::*)()>(&cocos2d::ui::TextField::init));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::TextField::createInstance));
mt.set_function("new",sol::overload(static_cast<cocos2d::ui::TextField*(*)(const std::string&,const std::string&,int)>(&cocos2d::ui::TextField::create),static_cast<cocos2d::ui::TextField*(*)()>(&cocos2d::ui::TextField::create)));
}
void RegisterLuaUITextBMFontAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::TextBMFont,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","TextBMFont");
mt.set_function("setFntFile",static_cast<void(cocos2d::ui::TextBMFont::*)(const std::string&)>(&cocos2d::ui::TextBMFont::setFntFile));
mt.set_function("setString",static_cast<void(cocos2d::ui::TextBMFont::*)(const std::string&)>(&cocos2d::ui::TextBMFont::setString));
mt.set_function("getString",static_cast<const std::string&(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getString));
mt.set_function("getStringLength",static_cast<ssize_t(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getStringLength));
mt.set_function("getVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getVirtualRendererSize));
mt.set_function("getVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::TextBMFont::*)()>(&cocos2d::ui::TextBMFont::getVirtualRenderer));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::TextBMFont::*)()const>(&cocos2d::ui::TextBMFont::getDescription));
mt.set_function("getRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::TextBMFont::*)()>(&cocos2d::ui::TextBMFont::getRenderFile));
mt.set_function("resetRender",static_cast<void(cocos2d::ui::TextBMFont::*)()>(&cocos2d::ui::TextBMFont::resetRender));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::TextBMFont::createInstance));
mt.set_function("new",sol::overload(static_cast<cocos2d::ui::TextBMFont*(*)(const std::string&,const std::string&)>(&cocos2d::ui::TextBMFont::create),static_cast<cocos2d::ui::TextBMFont*(*)()>(&cocos2d::ui::TextBMFont::create)));
}
void RegisterLuaUIPageViewAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::PageView,cocos2d::ui::ListView,cocos2d::ui::ScrollView,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("ccui","PageView");
mt.set_function("setDirection",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::ScrollView::Direction)>(&cocos2d::ui::PageView::setDirection));
mt.set_function("addPage",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::PageView::addPage));
mt.set_function("insertPage",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::PageView::insertPage));
mt.set_function("removePage",static_cast<void(cocos2d::ui::PageView::*)(cocos2d::ui::Widget*)>(&cocos2d::ui::PageView::removePage));
mt.set_function("removePageAtIndex",static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::removePageAtIndex));
mt.set_function("removeAllPages",static_cast<void(cocos2d::ui::PageView::*)()>(&cocos2d::ui::PageView::removeAllPages));
mt.set_function("scrollToPage",sol::overload(static_cast<void(cocos2d::ui::PageView::*)(ssize_t,float)>(&cocos2d::ui::PageView::scrollToPage),static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::scrollToPage)));
mt.set_function("scrollToItem",sol::overload(static_cast<void(cocos2d::ui::PageView::*)(ssize_t,float)>(&cocos2d::ui::PageView::scrollToItem),static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::scrollToItem)));
mt.set_function("getCurrentPageIndex",static_cast<ssize_t(cocos2d::ui::PageView::*)()>(&cocos2d::ui::PageView::getCurrentPageIndex));
mt.set_function("setCurrentPageIndex",static_cast<void(cocos2d::ui::PageView::*)(ssize_t)>(&cocos2d::ui::PageView::setCurrentPageIndex));
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::PageView::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::PageView::EventType)>&)>(&cocos2d::ui::PageView::addEventListener));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getDescription));
mt.set_function("setIndicatorEnabled",static_cast<void(cocos2d::ui::PageView::*)(bool)>(&cocos2d::ui::PageView::setIndicatorEnabled));
mt.set_function("getIndicatorEnabled",static_cast<bool(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorEnabled));
mt.set_function("setIndicatorPositionAsAnchorPoint",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::PageView::setIndicatorPositionAsAnchorPoint));
mt.set_function("getIndicatorPositionAsAnchorPoint",static_cast<const cocos2d::Vec2&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorPositionAsAnchorPoint));
mt.set_function("setIndicatorPosition",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Vec2&)>(&cocos2d::ui::PageView::setIndicatorPosition));
mt.set_function("getIndicatorPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorPosition));
mt.set_function("setIndicatorSpaceBetweenIndexNodes",static_cast<void(cocos2d::ui::PageView::*)(float)>(&cocos2d::ui::PageView::setIndicatorSpaceBetweenIndexNodes));
mt.set_function("getIndicatorSpaceBetweenIndexNodes",static_cast<float(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorSpaceBetweenIndexNodes));
mt.set_function("setIndicatorSelectedIndexColor",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Color3B&)>(&cocos2d::ui::PageView::setIndicatorSelectedIndexColor));
mt.set_function("getIndicatorSelectedIndexColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorSelectedIndexColor));
mt.set_function("setIndicatorIndexNodesColor",static_cast<void(cocos2d::ui::PageView::*)(const cocos2d::Color3B&)>(&cocos2d::ui::PageView::setIndicatorIndexNodesColor));
mt.set_function("getIndicatorIndexNodesColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorIndexNodesColor));
mt.set_function("setIndicatorSelectedIndexOpacity",static_cast<void(cocos2d::ui::PageView::*)(uint8_t)>(&cocos2d::ui::PageView::setIndicatorSelectedIndexOpacity));
mt.set_function("getIndicatorSelectedIndexOpacity",static_cast<uint8_t(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorSelectedIndexOpacity));
mt.set_function("setIndicatorIndexNodesOpacity",static_cast<void(cocos2d::ui::PageView::*)(uint8_t)>(&cocos2d::ui::PageView::setIndicatorIndexNodesOpacity));
mt.set_function("getIndicatorIndexNodesOpacity",static_cast<uint8_t(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorIndexNodesOpacity));
mt.set_function("setIndicatorIndexNodesScale",static_cast<void(cocos2d::ui::PageView::*)(float)>(&cocos2d::ui::PageView::setIndicatorIndexNodesScale));
mt.set_function("setIndicatorIndexNodesTexture",sol::overload([](cocos2d::ui::PageView* obj,const std::string& arg0){return obj->setIndicatorIndexNodesTexture(arg0);},[](cocos2d::ui::PageView* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->setIndicatorIndexNodesTexture(arg0,arg1);}));
mt.set_function("getIndicatorIndexNodesScale",static_cast<float(cocos2d::ui::PageView::*)()const>(&cocos2d::ui::PageView::getIndicatorIndexNodesScale));
mt.set_function("setAutoScrollStopEpsilon",static_cast<void(cocos2d::ui::PageView::*)(float)>(&cocos2d::ui::PageView::setAutoScrollStopEpsilon));
mt.set_function("init",static_cast<bool(cocos2d::ui::PageView::*)()>(&cocos2d::ui::PageView::init));
mt.set_function("doLayout",static_cast<void(cocos2d::ui::PageView::*)()>(&cocos2d::ui::PageView::doLayout));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::PageView::createInstance));
mt.set_function("new",static_cast<cocos2d::ui::PageView*(*)()>(&cocos2d::ui::PageView::create));
}
void RegisterLuaUIHelperAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Helper>("ccui","Helper");
mt.set_function("seekWidgetByTag",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekWidgetByTag));
mt.set_function("seekWidgetByName",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,const std::string&)>(&cocos2d::ui::Helper::seekWidgetByName));
mt.set_function("seekActionWidgetByActionTag",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekActionWidgetByActionTag));
mt.set_function("getSubStringOfUTF8String",static_cast<std::string(*)(const std::string&,std::string::size_type,std::string::size_type)>(&cocos2d::ui::Helper::getSubStringOfUTF8String));
mt.set_function("doLayout",static_cast<void(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::doLayout));
mt.set_function("changeLayoutSystemActiveState",static_cast<void(*)(bool)>(&cocos2d::ui::Helper::changeLayoutSystemActiveState));
mt.set_function("restrictCapInsetRect",static_cast<cocos2d::Rect(*)(const cocos2d::Rect&,const cocos2d::Size&)>(&cocos2d::ui::Helper::restrictCapInsetRect));
mt.set_function("convertBoundingBoxToScreen",static_cast<cocos2d::Rect(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::convertBoundingBoxToScreen));
}
void RegisterLuaUIRichElementAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("ccui","RichElement");
mt.set_function("init",static_cast<bool(cocos2d::ui::RichElement::*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElement::init));
mt.set_function("equalType",static_cast<bool(cocos2d::ui::RichElement::*)(cocos2d::ui::RichElement::Type)>(&cocos2d::ui::RichElement::equalType));
mt.set_function("setColor",static_cast<void(cocos2d::ui::RichElement::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichElement::setColor));
}
void RegisterLuaUIRichElementTextAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementText,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("ccui","RichElementText");
mt.set_function("init",sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);}));
mt.set_function("new",sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);}));
}
void RegisterLuaUIRichElementImageAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementImage,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("ccui","RichElementImage");
mt.set_function("init",sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->init(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->init(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("setWidth",static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setWidth));
mt.set_function("setHeight",static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setHeight));
mt.set_function("setUrl",static_cast<void(cocos2d::ui::RichElementImage::*)(const std::string&)>(&cocos2d::ui::RichElementImage::setUrl));
mt.set_function("new",sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);}));
}
void RegisterLuaUIRichElementCustomNodeAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementCustomNode,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("ccui","RichElementCustomNode");
mt.set_function("init",static_cast<bool(cocos2d::ui::RichElementCustomNode::*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::init));
mt.set_function("new",static_cast<cocos2d::ui::RichElementCustomNode*(*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::create));
}
void RegisterLuaUIRichElementNewLineAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementNewLine,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("ccui","RichElementNewLine");
mt.set_function("new",static_cast<cocos2d::ui::RichElementNewLine*(*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElementNewLine::create));
}
void RegisterLuaUIRichTextAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichText,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","RichText");
mt.set_function("insertElement",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*,int)>(&cocos2d::ui::RichText::insertElement));
mt.set_function("pushBackElement",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*)>(&cocos2d::ui::RichText::pushBackElement));
mt.set_function("removeElement",sol::overload(static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*)>(&cocos2d::ui::RichText::removeElement),static_cast<void(cocos2d::ui::RichText::*)(int)>(&cocos2d::ui::RichText::removeElement)));
mt.set_function("setVerticalSpace",static_cast<void(cocos2d::ui::RichText::*)(float)>(&cocos2d::ui::RichText::setVerticalSpace));
mt.set_function("formatText",static_cast<void(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::formatText));
mt.set_function("ignoreContentAdaptWithSize",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::ignoreContentAdaptWithSize));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getDescription));
mt.set_function("setWrapMode",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichText::WrapMode)>(&cocos2d::ui::RichText::setWrapMode));
mt.set_function("getWrapMode",static_cast<cocos2d::ui::RichText::WrapMode(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getWrapMode));
mt.set_function("setHorizontalAlignment",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichText::HorizontalAlignment)>(&cocos2d::ui::RichText::setHorizontalAlignment));
mt.set_function("getHorizontalAlignment",static_cast<cocos2d::ui::RichText::HorizontalAlignment(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getHorizontalAlignment));
mt.set_function("setFontColor",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setFontColor));
mt.set_function("getFontColor",static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontColor));
mt.set_function("getFontColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontColor3B));
mt.set_function("setFontSize",static_cast<void(cocos2d::ui::RichText::*)(float)>(&cocos2d::ui::RichText::setFontSize));
mt.set_function("getFontSize",static_cast<float(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontSize));
mt.set_function("setFontFace",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setFontFace));
mt.set_function("getFontFace",static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontFace));
mt.set_function("setAnchorFontColor",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setAnchorFontColor));
mt.set_function("getAnchorFontColor",static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorFontColor));
mt.set_function("getAnchorFontColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorFontColor3B));
mt.set_function("setAnchorTextBold",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextBold));
mt.set_function("isAnchorTextBoldEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextBoldEnabled));
mt.set_function("setAnchorTextItalic",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextItalic));
mt.set_function("isAnchorTextItalicEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextItalicEnabled));
mt.set_function("setAnchorTextDel",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextDel));
mt.set_function("isAnchorTextDelEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextDelEnabled));
mt.set_function("setAnchorTextUnderline",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextUnderline));
mt.set_function("isAnchorTextUnderlineEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextUnderlineEnabled));
mt.set_function("setAnchorTextOutline",sol::overload([](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextOutline(arg0);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextOutline(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,int arg2){return obj->setAnchorTextOutline(arg0,arg1,arg2);}));
mt.set_function("isAnchorTextOutlineEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextOutlineEnabled));
mt.set_function("getAnchorTextOutlineColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextOutlineColor3B));
mt.set_function("getAnchorTextOutlineSize",static_cast<int(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextOutlineSize));
mt.set_function("setAnchorTextShadow",sol::overload([](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextShadow(arg0);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextShadow(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,const cocos2d::Size& arg2){return obj->setAnchorTextShadow(arg0,arg1,arg2);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,const cocos2d::Size& arg2,int arg3){return obj->setAnchorTextShadow(arg0,arg1,arg2,arg3);}));
mt.set_function("isAnchorTextShadowEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextShadowEnabled));
mt.set_function("getAnchorTextShadowColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowColor3B));
mt.set_function("getAnchorTextShadowOffset",static_cast<cocos2d::Size(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowOffset));
mt.set_function("getAnchorTextShadowBlurRadius",static_cast<int(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowBlurRadius));
mt.set_function("setAnchorTextGlow",sol::overload([](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextGlow(arg0);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextGlow(arg0,arg1);}));
mt.set_function("isAnchorTextGlowEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextGlowEnabled));
mt.set_function("getAnchorTextGlowColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextGlowColor3B));
mt.set_function("setDefaults",static_cast<void(cocos2d::ui::RichText::*)(const cocos2d::ValueMap&)>(&cocos2d::ui::RichText::setDefaults));
mt.set_function("getDefaults",static_cast<cocos2d::ValueMap(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getDefaults));
mt.set_function("color3BWithString",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::color3BWithString));
mt.set_function("stringWithColor3B",static_cast<std::string(cocos2d::ui::RichText::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichText::stringWithColor3B));
mt.set_function("stringWithColor4B",static_cast<std::string(cocos2d::ui::RichText::*)(const cocos2d::Color4B&)>(&cocos2d::ui::RichText::stringWithColor4B));
mt.set_function("openUrl",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::openUrl));
mt.set_function("init",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::init));
mt.set_function("initWithXML",sol::overload([](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1){return obj->initWithXML(arg0,arg1);},[](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1,const std::function<void (const std::string&)>& arg2){return obj->initWithXML(arg0,arg1,arg2);}));
mt.set_function("new",static_cast<cocos2d::ui::RichText*(*)()>(&cocos2d::ui::RichText::create));
mt.set_function("createWithXML",sol::overload([](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1){return obj->createWithXML(arg0,arg1);},[](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1,const std::function<void (const std::string&)>& arg2){return obj->createWithXML(arg0,arg1,arg2);}));
}
void RegisterLuaUIHBoxAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::HBox,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("ccui","HBox");
mt.set_function("init",static_cast<bool(cocos2d::ui::HBox::*)()>(&cocos2d::ui::HBox::init));
mt.set_function("initWithSize",static_cast<bool(cocos2d::ui::HBox::*)(const cocos2d::Size&)>(&cocos2d::ui::HBox::initWithSize));
mt.set_function("new",sol::overload(static_cast<cocos2d::ui::HBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::HBox::create),static_cast<cocos2d::ui::HBox*(*)()>(&cocos2d::ui::HBox::create)));
}
void RegisterLuaUIVBoxAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::VBox,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("ccui","VBox");
mt.set_function("init",static_cast<bool(cocos2d::ui::VBox::*)()>(&cocos2d::ui::VBox::init));
mt.set_function("initWithSize",static_cast<bool(cocos2d::ui::VBox::*)(const cocos2d::Size&)>(&cocos2d::ui::VBox::initWithSize));
mt.set_function("new",sol::overload(static_cast<cocos2d::ui::VBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::VBox::create),static_cast<cocos2d::ui::VBox*(*)()>(&cocos2d::ui::VBox::create)));
}
void RegisterLuaUIRelativeBoxAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RelativeBox,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("ccui","RelativeBox");
mt.set_function("init",static_cast<bool(cocos2d::ui::RelativeBox::*)()>(&cocos2d::ui::RelativeBox::init));
mt.set_function("initWithSize",static_cast<bool(cocos2d::ui::RelativeBox::*)(const cocos2d::Size&)>(&cocos2d::ui::RelativeBox::initWithSize));
mt.set_function("new",sol::overload(static_cast<cocos2d::ui::RelativeBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::RelativeBox::create),static_cast<cocos2d::ui::RelativeBox*(*)()>(&cocos2d::ui::RelativeBox::create)));
}
