#include "scripting/lua-bindings/auto/CCRegisterLuaWebViewAuto.hpp"
#include "ui/UIWebView/UIWebView.h"
static void RegisterLuaWebView(cocos2d::Lua& lua){
auto mt=cocos2d::Lua::NewUserType<cocos2d::ui::WebView,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>(lua.get_or("ccui",lua.create_named_table("ccui")),"WebView");
mt["setJavascriptInterfaceScheme"]=static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::setJavascriptInterfaceScheme);
mt["loadHTMLString"]=sol::overload([](cocos2d::ui::WebView* obj,const std::string& arg0){return obj->loadHTMLString(arg0);},[](cocos2d::ui::WebView* obj,const std::string& arg0,const std::string& arg1){return obj->loadHTMLString(arg0,arg1);});
mt["loadURL"]=static_cast<void(cocos2d::ui::WebView::*)(const std::string&,bool)>(&cocos2d::ui::WebView::loadURL),static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadURL);
mt["loadFile"]=static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::loadFile);
mt["stopLoading"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::stopLoading);
mt["reload"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::reload);
mt["canGoBack"]=static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoBack);
mt["canGoForward"]=static_cast<bool(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::canGoForward);
mt["goBack"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goBack);
mt["goForward"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::goForward);
mt["evaluateJS"]=static_cast<void(cocos2d::ui::WebView::*)(const std::string&)>(&cocos2d::ui::WebView::evaluateJS);
mt["setScalesPageToFit"]=static_cast<void(cocos2d::ui::WebView::*)(const bool)>(&cocos2d::ui::WebView::setScalesPageToFit);
mt["setBounces"]=static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setBounces);
mt["setVisible"]=static_cast<void(cocos2d::ui::WebView::*)(bool)>(&cocos2d::ui::WebView::setVisible);
mt["setOpacityWebView"]=static_cast<void(cocos2d::ui::WebView::*)(float)>(&cocos2d::ui::WebView::setOpacityWebView);
mt["getOpacityWebView"]=static_cast<float(cocos2d::ui::WebView::*)()const>(&cocos2d::ui::WebView::getOpacityWebView);
mt["setBackgroundTransparent"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::setBackgroundTransparent);
mt["onEnter"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onEnter);
mt["onExit"]=static_cast<void(cocos2d::ui::WebView::*)()>(&cocos2d::ui::WebView::onExit);
mt["new"]=static_cast<cocos2d::ui::WebView*(*)()>(&cocos2d::ui::WebView::create);
}
void RegisterLuaWebViewAuto(cocos2d::Lua& lua) {
RegisterLuaWebView(lua);
}
