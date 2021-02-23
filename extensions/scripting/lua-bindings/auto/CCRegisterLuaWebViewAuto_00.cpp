#include "scripting/lua-bindings/auto/CCRegisterLuaWebViewAuto.hpp"
#include "ui/UIWebView/UIWebView.h"
void RegisterLuaWebViewWebViewAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::WebView,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","WebView");
mt.set_function("setJavascriptInterfaceScheme",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::setJavascriptInterfaceScheme));
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
mt.set_function("setBounces",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setBounces));
mt.set_function("setVisible",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setVisible));
mt.set_function("setOpacityWebView",static_cast<void(cocos2d::ui::WebView::*)(float)>(&cocos2d::ui::WebView::setOpacityWebView));
mt.set_function("getOpacityWebView",static_cast<float(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOpacityWebView));
mt.set_function("setBackgroundTransparent",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::setBackgroundTransparent));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onExit));
mt.set_function("new",static_cast<cocos2d::ui::WebView*(*)()>(&cocos2d::ui::WebView::create));
}
