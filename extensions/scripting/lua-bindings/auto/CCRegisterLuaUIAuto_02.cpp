#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUIHelperAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Helper>("ccui","Helper",true);
mt.set_function("SeekWidgetByTag",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekWidgetByTag));
mt.set_function("SeekWidgetByName",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,const std::string&)>(&cocos2d::ui::Helper::seekWidgetByName));
mt.set_function("SeekActionWidgetByActionTag",static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekActionWidgetByActionTag));
mt.set_function("GetSubStringOfUTF8String",static_cast<std::string(*)(const std::string&,std::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type,std::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type)>(&cocos2d::ui::Helper::getSubStringOfUTF8String));
mt.set_function("DoLayout",static_cast<void(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::doLayout));
mt.set_function("ChangeLayoutSystemActiveState",static_cast<void(*)(bool)>(&cocos2d::ui::Helper::changeLayoutSystemActiveState));
mt.set_function("RestrictCapInsetRect",static_cast<cocos2d::Rect(*)(const cocos2d::Rect&,const cocos2d::Size&)>(&cocos2d::ui::Helper::restrictCapInsetRect));
mt.set_function("ConvertBoundingBoxToScreen",static_cast<cocos2d::Rect(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::convertBoundingBoxToScreen));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::Helper()>();
}
void RegisterLuaUIRichElementTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichElement"];
pTable.new_enum<cocos2d::ui::RichElement::Type>("Type",{
{"TEXT",cocos2d::ui::RichElement::Type::TEXT}
,{"IMAGE",cocos2d::ui::RichElement::Type::IMAGE}
,{"CUSTOM",cocos2d::ui::RichElement::Type::CUSTOM}
,{"NEWLINE",cocos2d::ui::RichElement::Type::NEWLINE}
});}
void RegisterLuaUIRichElementAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElement>("ccui","RichElement",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Init",static_cast<bool(cocos2d::ui::RichElement::*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElement::init));
mt.set_function("EqualType",static_cast<bool(cocos2d::ui::RichElement::*)(cocos2d::ui::RichElement::Type)>(&cocos2d::ui::RichElement::equalType));
mt.set_function("SetColor",static_cast<void(cocos2d::ui::RichElement::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichElement::setColor));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::RichElement()>();
RegisterLuaUIRichElementTypeAuto(lua);
}
void RegisterLuaUIRichElementTextAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementText>("ccui","RichElementText",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Init",sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);}));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);}));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::RichElementText()>();
}
void RegisterLuaUIRichElementImageAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementImage>("ccui","RichElementImage",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Init",sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->init(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->init(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->create(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("SetWidth",static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setWidth));
mt.set_function("SetHeight",static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setHeight));
mt.set_function("SetUrl",static_cast<void(cocos2d::ui::RichElementImage::*)(const std::string&)>(&cocos2d::ui::RichElementImage::setUrl));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::RichElementImage()>();
}
void RegisterLuaUIRichElementCustomNodeAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementCustomNode>("ccui","RichElementCustomNode",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("Init",static_cast<bool(cocos2d::ui::RichElementCustomNode::*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::init));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RichElementCustomNode*(*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::create));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::RichElementCustomNode()>();
}
void RegisterLuaUIRichElementNewLineAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichElementNewLine>("ccui","RichElementNewLine",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RichElementNewLine*(*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElementNewLine::create));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::RichElementNewLine()>();
}
void RegisterLuaUIRichTextWrapModeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichText"];
pTable.new_enum<cocos2d::ui::RichText::WrapMode>("WrapMode",{
{"WRAP_PER_WORD",cocos2d::ui::RichText::WrapMode::WRAP_PER_WORD}
,{"WRAP_PER_CHAR",cocos2d::ui::RichText::WrapMode::WRAP_PER_CHAR}
});}
void RegisterLuaUIRichTextHorizontalAlignmentAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichText"];
pTable.new_enum<cocos2d::ui::RichText::HorizontalAlignment>("HorizontalAlignment",{
{"LEFT",cocos2d::ui::RichText::HorizontalAlignment::LEFT}
,{"CENTER",cocos2d::ui::RichText::HorizontalAlignment::CENTER}
,{"RIGHT",cocos2d::ui::RichText::HorizontalAlignment::RIGHT}
});}
void RegisterLuaUIRichTextAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RichText>("ccui","RichText",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RichText*(*)()>(&cocos2d::ui::RichText::create));
mt.set_function("CreateWithXML",sol::overload([](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1){return obj->createWithXML(arg0,arg1);},[](cocos2d::ui::RichText* obj,const std::string& arg0,const cocos2d::ValueMap& arg1,const cocos2d::ui::RichText::OpenUrlHandler& arg2){return obj->createWithXML(arg0,arg1,arg2);}));
mt.set_function("InsertElement",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*,int)>(&cocos2d::ui::RichText::insertElement));
mt.set_function("PushBackElement",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*)>(&cocos2d::ui::RichText::pushBackElement));
mt.set_function("RemoveElement",sol::overload(static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*)>(&cocos2d::ui::RichText::removeElement),static_cast<void(cocos2d::ui::RichText::*)(int)>(&cocos2d::ui::RichText::removeElement)));
mt.set_function("SetVerticalSpace",static_cast<void(cocos2d::ui::RichText::*)(float)>(&cocos2d::ui::RichText::setVerticalSpace));
mt.set_function("FormatText",static_cast<void(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::formatText));
mt.set_function("IgnoreContentAdaptWithSize",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::ignoreContentAdaptWithSize));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getDescription));
mt.set_function("SetWrapMode",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichText::WrapMode)>(&cocos2d::ui::RichText::setWrapMode));
mt.set_function("GetWrapMode",static_cast<cocos2d::ui::RichText::WrapMode(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getWrapMode));
mt.set_function("SetHorizontalAlignment",static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichText::HorizontalAlignment)>(&cocos2d::ui::RichText::setHorizontalAlignment));
mt.set_function("GetHorizontalAlignment",static_cast<cocos2d::ui::RichText::HorizontalAlignment(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getHorizontalAlignment));
mt.set_function("SetFontColor",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setFontColor));
mt.set_function("GetFontColor",static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontColor));
mt.set_function("GetFontColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontColor3B));
mt.set_function("SetFontSize",static_cast<void(cocos2d::ui::RichText::*)(float)>(&cocos2d::ui::RichText::setFontSize));
mt.set_function("GetFontSize",static_cast<float(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontSize));
mt.set_function("SetFontFace",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setFontFace));
mt.set_function("GetFontFace",static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontFace));
mt.set_function("SetAnchorFontColor",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setAnchorFontColor));
mt.set_function("GetAnchorFontColor",static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorFontColor));
mt.set_function("GetAnchorFontColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorFontColor3B));
mt.set_function("SetAnchorTextBold",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextBold));
mt.set_function("IsAnchorTextBoldEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextBoldEnabled));
mt.set_function("SetAnchorTextItalic",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextItalic));
mt.set_function("IsAnchorTextItalicEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextItalicEnabled));
mt.set_function("SetAnchorTextDel",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextDel));
mt.set_function("IsAnchorTextDelEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextDelEnabled));
mt.set_function("SetAnchorTextUnderline",static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextUnderline));
mt.set_function("IsAnchorTextUnderlineEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextUnderlineEnabled));
mt.set_function("SetAnchorTextOutline",sol::overload([](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextOutline(arg0);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextOutline(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,int arg2){return obj->setAnchorTextOutline(arg0,arg1,arg2);}));
mt.set_function("IsAnchorTextOutlineEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextOutlineEnabled));
mt.set_function("GetAnchorTextOutlineColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextOutlineColor3B));
mt.set_function("GetAnchorTextOutlineSize",static_cast<int(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextOutlineSize));
mt.set_function("SetAnchorTextShadow",sol::overload([](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextShadow(arg0);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextShadow(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,const cocos2d::Size& arg2){return obj->setAnchorTextShadow(arg0,arg1,arg2);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,const cocos2d::Size& arg2,int arg3){return obj->setAnchorTextShadow(arg0,arg1,arg2,arg3);}));
mt.set_function("IsAnchorTextShadowEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextShadowEnabled));
mt.set_function("GetAnchorTextShadowColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowColor3B));
mt.set_function("GetAnchorTextShadowOffset",static_cast<cocos2d::Size(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowOffset));
mt.set_function("GetAnchorTextShadowBlurRadius",static_cast<int(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowBlurRadius));
mt.set_function("SetAnchorTextGlow",sol::overload([](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextGlow(arg0);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextGlow(arg0,arg1);}));
mt.set_function("IsAnchorTextGlowEnabled",static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextGlowEnabled));
mt.set_function("GetAnchorTextGlowColor3B",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextGlowColor3B));
mt.set_function("SetDefaults",static_cast<void(cocos2d::ui::RichText::*)(const cocos2d::ValueMap&)>(&cocos2d::ui::RichText::setDefaults));
mt.set_function("GetDefaults",static_cast<cocos2d::ValueMap(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getDefaults));
mt.set_function("Color3BWithString",static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::color3BWithString));
mt.set_function("StringWithColor3B",static_cast<std::string(cocos2d::ui::RichText::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichText::stringWithColor3B));
mt.set_function("StringWithColor4B",static_cast<std::string(cocos2d::ui::RichText::*)(const cocos2d::Color4B&)>(&cocos2d::ui::RichText::stringWithColor4B));
mt.set_function("SetTagDescription",static_cast<void(*)(const std::string&,bool,cocos2d::ui::RichText::VisitEnterHandler)>(&cocos2d::ui::RichText::setTagDescription));
mt.set_function("RemoveTagDescription",static_cast<void(*)(const std::string&)>(&cocos2d::ui::RichText::removeTagDescription));
mt.set_function("OpenUrl",static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::openUrl));
mt.set_function("SetOpenUrlHandler",static_cast<void(cocos2d::ui::RichText::*)(const cocos2d::ui::RichText::OpenUrlHandler&)>(&cocos2d::ui::RichText::setOpenUrlHandler));
mt["KEY_VERTICAL_SPACE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_VERTICAL_SPACE));
mt["KEY_WRAP_MODE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_WRAP_MODE));
mt["KEY_HORIZONTAL_ALIGNMENT"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_HORIZONTAL_ALIGNMENT));
mt["KEY_FONT_COLOR_STRING"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_FONT_COLOR_STRING));
mt["KEY_FONT_SIZE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_FONT_SIZE));
mt["KEY_FONT_SMALL"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_FONT_SMALL));
mt["KEY_FONT_BIG"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_FONT_BIG));
mt["KEY_FONT_FACE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_FONT_FACE));
mt["KEY_TEXT_BOLD"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_BOLD));
mt["KEY_TEXT_ITALIC"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_ITALIC));
mt["KEY_TEXT_LINE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_LINE));
mt["VALUE_TEXT_LINE_NONE"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_LINE_NONE));
mt["VALUE_TEXT_LINE_DEL"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_LINE_DEL));
mt["VALUE_TEXT_LINE_UNDER"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_LINE_UNDER));
mt["KEY_TEXT_STYLE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_STYLE));
mt["VALUE_TEXT_STYLE_NONE"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_STYLE_NONE));
mt["VALUE_TEXT_STYLE_OUTLINE"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_STYLE_OUTLINE));
mt["VALUE_TEXT_STYLE_SHADOW"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_STYLE_SHADOW));
mt["VALUE_TEXT_STYLE_GLOW"]=sol::var(std::ref(cocos2d::ui::RichText::VALUE_TEXT_STYLE_GLOW));
mt["KEY_TEXT_OUTLINE_COLOR"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_OUTLINE_COLOR));
mt["KEY_TEXT_OUTLINE_SIZE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_OUTLINE_SIZE));
mt["KEY_TEXT_SHADOW_COLOR"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_SHADOW_COLOR));
mt["KEY_TEXT_SHADOW_OFFSET_WIDTH"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_WIDTH));
mt["KEY_TEXT_SHADOW_OFFSET_HEIGHT"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_HEIGHT));
mt["KEY_TEXT_SHADOW_BLUR_RADIUS"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_SHADOW_BLUR_RADIUS));
mt["KEY_TEXT_GLOW_COLOR"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_TEXT_GLOW_COLOR));
mt["KEY_URL"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_URL));
mt["KEY_ANCHOR_FONT_COLOR_STRING"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_FONT_COLOR_STRING));
mt["KEY_ANCHOR_TEXT_BOLD"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_BOLD));
mt["KEY_ANCHOR_TEXT_ITALIC"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_ITALIC));
mt["KEY_ANCHOR_TEXT_LINE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_LINE));
mt["KEY_ANCHOR_TEXT_STYLE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_STYLE));
mt["KEY_ANCHOR_TEXT_OUTLINE_COLOR"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_COLOR));
mt["KEY_ANCHOR_TEXT_OUTLINE_SIZE"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_SIZE));
mt["KEY_ANCHOR_TEXT_SHADOW_COLOR"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_COLOR));
mt["KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH));
mt["KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT));
mt["KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS));
mt["KEY_ANCHOR_TEXT_GLOW_COLOR"]=sol::var(std::ref(cocos2d::ui::RichText::KEY_ANCHOR_TEXT_GLOW_COLOR));
RegisterLuaUIRichTextWrapModeAuto(lua);
RegisterLuaUIRichTextHorizontalAlignmentAuto(lua);
}
void RegisterLuaUIHBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::HBox>("ccui","HBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::HBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::HBox::create),static_cast<cocos2d::ui::HBox*(*)()>(&cocos2d::ui::HBox::create)));
}
void RegisterLuaUIVBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::VBox>("ccui","VBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::VBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::VBox::create),static_cast<cocos2d::ui::VBox*(*)()>(&cocos2d::ui::VBox::create)));
}
void RegisterLuaUIRelativeBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RelativeBox>("ccui","RelativeBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::ui::RelativeBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::RelativeBox::create),static_cast<cocos2d::ui::RelativeBox*(*)()>(&cocos2d::ui::RelativeBox::create)));
}
