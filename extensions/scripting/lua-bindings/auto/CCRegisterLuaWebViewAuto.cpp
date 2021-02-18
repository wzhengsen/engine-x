#include "scripting/lua-bindings/auto/CCRegisterLuaWebViewAuto.hpp"
#include "ui/UIWebView/UIWebView.h"
static void RegisterLuaWebView(cocos2d::Lua& lua){
lua.NewUserType<cocos2d::ui::WebView,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("ccui","WebView"
,"setJavascriptInterfaceScheme",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::setJavascriptInterfaceScheme)
,"loadHTMLString",sol::overload([](cocos2d::ui::WebView* obj,const std::string& arg0){return obj->loadHTMLString(arg0);},[](cocos2d::ui::WebView* obj,const std::string& arg0,const std::string& arg1){return obj->loadHTMLString(arg0,arg1);})
,"loadURL",sol::overload(static_cast<void(cocos2d::ui::WebView::*)(const std::string&,bool)>(&cocos2d::ui::WebView::loadURL),static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadURL))
,"loadFile",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadFile)
,"stopLoading",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::stopLoading)
,"reload",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::reload)
,"canGoBack",static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoBack)
,"canGoForward",static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoForward)
,"goBack",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goBack)
,"goForward",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goForward)
,"evaluateJS",static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::evaluateJS)
,"setScalesPageToFit",static_cast<void(cocos2d::ui::WebView::*)(const bool)>(&cocos2d::ui::WebView::setScalesPageToFit)
,"setBounces",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setBounces)
,"setVisible",static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setVisible)
,"setOpacityWebView",static_cast<void(cocos2d::ui::WebView::*)(float)>(&cocos2d::ui::WebView::setOpacityWebView)
,"getOpacityWebView",static_cast<float(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOpacityWebView)
,"setBackgroundTransparent",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::setBackgroundTransparent)
,"onEnter",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onEnter)
,"onExit",static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onExit)
,"new",static_cast<cocos2d::ui::WebView*(*)()>(&cocos2d::ui::WebView::create)
);}
void RegisterLuaWebViewAuto(cocos2d::Lua& lua) {
RegisterLuaWebView(lua);
}
