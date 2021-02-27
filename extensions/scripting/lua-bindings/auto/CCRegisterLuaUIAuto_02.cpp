#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUIHelperAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::Helper>("Helper",true);
ns["Helper"] = mt;
lua["Helper"] = sol::nil;
mt.set_function("seekWidgetByTag",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekWidgetByTag));
mt.set_function("seekWidgetByName",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,const std::string&)>(&cocos2d::ui::Helper::seekWidgetByName));
mt.set_function("seekActionWidgetByActionTag",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekActionWidgetByActionTag));
mt.set_function("getSubStringOfUTF8String",static_cast<std::string(*)(const std::string&,std::string::size_type,std::string::size_type)>(&cocos2d::ui::Helper::getSubStringOfUTF8String));
mt.set_function("doLayout",static_cast<void(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::doLayout));
mt.set_function("changeLayoutSystemActiveState",static_cast<void(*)(bool)>(&cocos2d::ui::Helper::changeLayoutSystemActiveState));
mt.set_function("restrictCapInsetRect",static_cast<cocos2d::Rect(*)(const cocos2d::Rect&,const cocos2d::Size&)>(&cocos2d::ui::Helper::restrictCapInsetRect));
mt.set_function("convertBoundingBoxToScreen",static_cast<cocos2d::Rect(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::convertBoundingBoxToScreen));
}
void RegisterLuaUIRichElementTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichElement"];
pTable.new_enum("Type"
,"TEXT",0
,"IMAGE",1
,"CUSTOM",2
,"NEWLINE",3
);}
void RegisterLuaUIRichElementAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("RichElement",true);
ns["RichElement"] = mt;
lua["RichElement"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::ui::RichElement::*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElement::init));
mt.set_function("equalType",static_cast<bool(cocos2d::ui::RichElement::*)(cocos2d::ui::RichElement::Type)>(&cocos2d::ui::RichElement::equalType));
mt.set_function("setColor",static_cast<void(cocos2d::ui::RichElement::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichElement::setColor));
RegisterLuaUIRichElementTypeAuto(lua);
}
void RegisterLuaUIRichElementTextAnonymousEnum__6876464989088795333_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichElementText"];
pTable["ITALICS_FLAG"] = 1;
pTable["BOLD_FLAG"] = 2;
pTable["UNDERLINE_FLAG"] = 4;
pTable["STRIKETHROUGH_FLAG"] = 8;
pTable["URL_FLAG"] = 16;
pTable["OUTLINE_FLAG"] = 32;
pTable["SHADOW_FLAG"] = 64;
pTable["GLOW_FLAG"] = 128;
}
void RegisterLuaUIRichElementTextAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RichElementText,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("RichElementText",false);
ns["RichElementText"] = mt;
lua["RichElementText"] = sol::nil;
mt.set_function("init",sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);}));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);}));
RegisterLuaUIRichElementTextAnonymousEnum__6876464989088795333_Auto(lua);
}
void RegisterLuaUIRichElementImageAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RichElementImage,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("RichElementImage",false);
ns["RichElementImage"] = mt;
lua["RichElementImage"] = sol::nil;
mt.set_function("init",sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->init(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->init(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("setWidth",static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setWidth));
mt.set_function("setHeight",static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setHeight));
mt.set_function("setUrl",static_cast<void(cocos2d::ui::RichElementImage::*)(const std::string&)>(&cocos2d::ui::RichElementImage::setUrl));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);}));
}
void RegisterLuaUIRichElementCustomNodeAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RichElementCustomNode,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("RichElementCustomNode",false);
ns["RichElementCustomNode"] = mt;
lua["RichElementCustomNode"] = sol::nil;
mt.set_function("init",static_cast<bool(cocos2d::ui::RichElementCustomNode::*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::init));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RichElementCustomNode*(*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::create));
}
void RegisterLuaUIRichElementNewLineAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RichElementNewLine,cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::LuaObject>("RichElementNewLine",false);
ns["RichElementNewLine"] = mt;
lua["RichElementNewLine"] = sol::nil;
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RichElementNewLine*(*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElementNewLine::create));
}
void RegisterLuaUIRichTextWrapModeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichText"];
pTable.new_enum("WrapMode"
,"WRAP_PER_WORD",0
,"WRAP_PER_CHAR",1
);}
void RegisterLuaUIRichTextHorizontalAlignmentAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichText"];
pTable.new_enum("HorizontalAlignment"
,"LEFT",0
,"CENTER",1
,"RIGHT",2
);}
void RegisterLuaUIRichTextAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RichText,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("RichText",false);
ns["RichText"] = mt;
lua["RichText"] = sol::nil;
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
mt.set_function("setOpenUrlHandler",static_cast<void(cocos2d::ui::RichText::*)(const std::function<void (const std::string&)>&)>(&cocos2d::ui::RichText::setOpenUrlHandler));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RichText*(*)()>(&cocos2d::ui::RichText::create));
mt.set_function("createWithXML",sol::overload([](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1){return obj->createWithXML(arg0,arg1);},[](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1,const std::function<void (const std::string&)>& arg2){return obj->createWithXML(arg0,arg1,arg2);}));
mt.set_function("setTagDescription",static_cast<void(*)(const std::string&,bool,cocos2d::ui::RichText::VisitEnterHandler)>(&cocos2d::ui::RichText::setTagDescription));
mt.set_function("removeTagDescription",static_cast<void(*)(const std::string&)>(&cocos2d::ui::RichText::removeTagDescription));
RegisterLuaUIRichTextWrapModeAuto(lua);
RegisterLuaUIRichTextHorizontalAlignmentAuto(lua);
}
void RegisterLuaUIHBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::HBox,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("HBox",false);
ns["HBox"] = mt;
lua["HBox"] = sol::nil;
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::HBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::HBox::create),static_cast<cocos2d::ui::HBox*(*)()>(&cocos2d::ui::HBox::create)));
}
void RegisterLuaUIVBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::VBox,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("VBox",false);
ns["VBox"] = mt;
lua["VBox"] = sol::nil;
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::VBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::VBox::create),static_cast<cocos2d::ui::VBox*(*)()>(&cocos2d::ui::VBox::create)));
}
void RegisterLuaUIRelativeBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RelativeBox,cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("RelativeBox",false);
ns["RelativeBox"] = mt;
lua["RelativeBox"] = sol::nil;
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::RelativeBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::RelativeBox::create),static_cast<cocos2d::ui::RelativeBox*(*)()>(&cocos2d::ui::RelativeBox::create)));
}
