#include "scripting/lua-bindings/auto/CCRegisterLuaWebViewAuto.hpp"
#include "ui/UIWebView/UIWebView.h"
extern void RegisterLuaWebViewWebViewAuto(cocos2d::Lua&);
void RegisterLuaWebViewAuto(cocos2d::Lua& lua){
RegisterLuaWebViewWebViewAuto(lua);
}