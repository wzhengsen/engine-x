#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
namespace cocos2d{
void RegisterLuaUIHelperAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::Helper).name()] = sol::usertype_traits<cocos2d::ui::Helper*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::Helper>("deprecated.cocos2d::ui::Helper");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::Helper*>::metatable());
lua["ccui"]["Helper"]=mt;
mt["static"]["SeekWidgetByTag"]=static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekWidgetByTag);
mt["static"]["SeekWidgetByName"]=static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,const std::string&)>(&cocos2d::ui::Helper::seekWidgetByName);
mt["static"]["SeekActionWidgetByActionTag"]=static_cast<cocos2d::ui::Widget*(*)(cocos2d::ui::Widget*,int)>(&cocos2d::ui::Helper::seekActionWidgetByActionTag);
mt["static"]["GetSubStringOfUTF8String"]=static_cast<std::string(*)(const std::string&,std::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type,std::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type)>(&cocos2d::ui::Helper::getSubStringOfUTF8String);
mt["static"]["DoLayout"]=static_cast<void(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::doLayout);
mt["static"]["ChangeLayoutSystemActiveState"]=static_cast<void(*)(bool)>(&cocos2d::ui::Helper::changeLayoutSystemActiveState);
mt["static"]["RestrictCapInsetRect"]=static_cast<cocos2d::Rect(*)(const cocos2d::Rect&,const cocos2d::Size&)>(&cocos2d::ui::Helper::restrictCapInsetRect);
mt["static"]["ConvertBoundingBoxToScreen"]=static_cast<cocos2d::Rect(*)(cocos2d::Node*)>(&cocos2d::ui::Helper::convertBoundingBoxToScreen);
}
void RegisterLuaUIRichElementTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["TEXT"]=cocos2d::ui::RichElement::Type::TEXT;
enumTable["IMAGE"]=cocos2d::ui::RichElement::Type::IMAGE;
enumTable["CUSTOM"]=cocos2d::ui::RichElement::Type::CUSTOM;
enumTable["NEWLINE"]=cocos2d::ui::RichElement::Type::NEWLINE;
lua["ccui"]["RichElement"]["static"]["Type"]=lua.NewEnum(enumTable);
}
void RegisterLuaUIRichElementAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RichElement).name()] = sol::usertype_traits<cocos2d::ui::RichElement*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RichElement>("deprecated.cocos2d::ui::RichElement");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RichElement*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccui"]["RichElement"]=mt;
mt["__new__"]=[](){return new cocos2d::ui::RichElement();};
mt["Init"]=static_cast<bool(cocos2d::ui::RichElement::*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElement::init);
mt["EqualType"]=static_cast<bool(cocos2d::ui::RichElement::*)(cocos2d::ui::RichElement::Type)>(&cocos2d::ui::RichElement::equalType);
mt["SetColor"]=static_cast<void(cocos2d::ui::RichElement::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichElement::setColor);
mt["set"]["Color"]=mt["SetColor"];
RegisterLuaUIRichElementTypeAuto(lua);
}
void RegisterLuaUIRichElementText_AE_ff9af6f53f75664505926a1d29222f37_Auto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RichElementText"];
pTable["static"]["const"]["ITALICS_FLAG"] = cocos2d::ui::RichElementText::ITALICS_FLAG;
pTable["static"]["const"]["BOLD_FLAG"] = cocos2d::ui::RichElementText::BOLD_FLAG;
pTable["static"]["const"]["UNDERLINE_FLAG"] = cocos2d::ui::RichElementText::UNDERLINE_FLAG;
pTable["static"]["const"]["STRIKETHROUGH_FLAG"] = cocos2d::ui::RichElementText::STRIKETHROUGH_FLAG;
pTable["static"]["const"]["URL_FLAG"] = cocos2d::ui::RichElementText::URL_FLAG;
pTable["static"]["const"]["OUTLINE_FLAG"] = cocos2d::ui::RichElementText::OUTLINE_FLAG;
pTable["static"]["const"]["SHADOW_FLAG"] = cocos2d::ui::RichElementText::SHADOW_FLAG;
pTable["static"]["const"]["GLOW_FLAG"] = cocos2d::ui::RichElementText::GLOW_FLAG;
}
void RegisterLuaUIRichElementTextAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RichElementText).name()] = sol::usertype_traits<cocos2d::ui::RichElementText*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RichElementText>("deprecated.cocos2d::ui::RichElementText");
dep[sol::base_classes]=sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RichElementText*>::metatable(),sol::usertype_traits<cocos2d::ui::RichElement*>::metatable());
lua["ccui"]["RichElementText"]=mt;
mt["Init"]=sol::overload([](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](cocos2d::ui::RichElementText* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);});
mt["__new__"]=sol::overload([](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12,const cocos2d::Color3B& arg13){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11,int arg12){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10,const cocos2d::Size& arg11){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9,const cocos2d::Color3B& arg10){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8,int arg9){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7,const cocos2d::Color3B& arg8){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6,const std::string& arg7){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5,uint32_t arg6){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5,arg6);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,float arg5){return cocos2d::ui::RichElementText::create(arg0,arg1,arg2,arg3,arg4,arg5);});
RegisterLuaUIRichElementText_AE_ff9af6f53f75664505926a1d29222f37_Auto(lua);
}
void RegisterLuaUIRichElementImageAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RichElementImage).name()] = sol::usertype_traits<cocos2d::ui::RichElementImage*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RichElementImage>("deprecated.cocos2d::ui::RichElementImage");
dep[sol::base_classes]=sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RichElementImage*>::metatable(),sol::usertype_traits<cocos2d::ui::RichElement*>::metatable());
lua["ccui"]["RichElementImage"]=mt;
mt["Init"]=sol::overload([](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->init(arg0,arg1,arg2,arg3,arg4,arg5);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return obj->init(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RichElementImage* obj,int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return obj->init(arg0,arg1,arg2,arg3);});
mt["__new__"]=sol::overload([](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return cocos2d::ui::RichElementImage::create(arg0,arg1,arg2,arg3,arg4,arg5);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3,const std::string& arg4){return cocos2d::ui::RichElementImage::create(arg0,arg1,arg2,arg3,arg4);},[](int arg0,const cocos2d::Color3B& arg1,uint8_t arg2,const std::string& arg3){return cocos2d::ui::RichElementImage::create(arg0,arg1,arg2,arg3);});
mt["SetWidth"]=static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setWidth);
mt["set"]["Width"]=mt["SetWidth"];
mt["SetHeight"]=static_cast<void(cocos2d::ui::RichElementImage::*)(int)>(&cocos2d::ui::RichElementImage::setHeight);
mt["set"]["Height"]=mt["SetHeight"];
mt["SetUrl"]=static_cast<void(cocos2d::ui::RichElementImage::*)(const std::string&)>(&cocos2d::ui::RichElementImage::setUrl);
mt["set"]["Url"]=mt["SetUrl"];
}
void RegisterLuaUIRichElementCustomNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RichElementCustomNode).name()] = sol::usertype_traits<cocos2d::ui::RichElementCustomNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RichElementCustomNode>("deprecated.cocos2d::ui::RichElementCustomNode");
dep[sol::base_classes]=sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RichElementCustomNode*>::metatable(),sol::usertype_traits<cocos2d::ui::RichElement*>::metatable());
lua["ccui"]["RichElementCustomNode"]=mt;
mt["Init"]=static_cast<bool(cocos2d::ui::RichElementCustomNode::*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::init);
mt["__new__"]=static_cast<cocos2d::ui::RichElementCustomNode*(*)(int,const cocos2d::Color3B&,uint8_t,cocos2d::Node*)>(&cocos2d::ui::RichElementCustomNode::create);
}
void RegisterLuaUIRichElementNewLineAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RichElementNewLine).name()] = sol::usertype_traits<cocos2d::ui::RichElementNewLine*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RichElementNewLine>("deprecated.cocos2d::ui::RichElementNewLine");
dep[sol::base_classes]=sol::bases<cocos2d::ui::RichElement,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RichElementNewLine*>::metatable(),sol::usertype_traits<cocos2d::ui::RichElement*>::metatable());
lua["ccui"]["RichElementNewLine"]=mt;
mt["__new__"]=static_cast<cocos2d::ui::RichElementNewLine*(*)(int,const cocos2d::Color3B&,uint8_t)>(&cocos2d::ui::RichElementNewLine::create);
}
void RegisterLuaUIRichTextWrapModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["WRAP_PER_WORD"]=cocos2d::ui::RichText::WrapMode::WRAP_PER_WORD;
enumTable["WRAP_PER_CHAR"]=cocos2d::ui::RichText::WrapMode::WRAP_PER_CHAR;
lua["ccui"]["RichText"]["static"]["WrapMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaUIRichTextHorizontalAlignmentAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,3);
enumTable["LEFT"]=cocos2d::ui::RichText::HorizontalAlignment::LEFT;
enumTable["CENTER"]=cocos2d::ui::RichText::HorizontalAlignment::CENTER;
enumTable["RIGHT"]=cocos2d::ui::RichText::HorizontalAlignment::RIGHT;
lua["ccui"]["RichText"]["static"]["HorizontalAlignment"]=lua.NewEnum(enumTable);
}
void RegisterLuaUIRichTextAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RichText).name()] = sol::usertype_traits<cocos2d::ui::RichText*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RichText>("deprecated.cocos2d::ui::RichText");
dep[sol::base_classes]=sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RichText*>::metatable(),sol::usertype_traits<cocos2d::ui::Widget*>::metatable());
lua["ccui"]["RichText"]=mt;
mt["__new__"]=static_cast<cocos2d::ui::RichText*(*)()>(&cocos2d::ui::RichText::create);
mt["static"]["CreateWithXML"]=sol::overload([](const std::string& arg0,const cocos2d::ValueMap& arg1,const cocos2d::ui::RichText::OpenUrlHandler& arg2){return cocos2d::ui::RichText::createWithXML(arg0,arg1,arg2);},[](const std::string& arg0,const cocos2d::ValueMap& arg1){return cocos2d::ui::RichText::createWithXML(arg0,arg1);});
mt["InsertElement"]=static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*,int)>(&cocos2d::ui::RichText::insertElement);
mt["PushBackElement"]=static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*)>(&cocos2d::ui::RichText::pushBackElement);
mt["RemoveElement"]=sol::overload(static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichElement*)>(&cocos2d::ui::RichText::removeElement),static_cast<void(cocos2d::ui::RichText::*)(int)>(&cocos2d::ui::RichText::removeElement));
mt["SetVerticalSpace"]=static_cast<void(cocos2d::ui::RichText::*)(float)>(&cocos2d::ui::RichText::setVerticalSpace);
mt["set"]["VerticalSpace"]=mt["SetVerticalSpace"];
mt["FormatText"]=static_cast<void(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::formatText);
mt["SetWrapMode"]=static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichText::WrapMode)>(&cocos2d::ui::RichText::setWrapMode);
mt["set"]["WrapMode"]=mt["SetWrapMode"];
mt["GetWrapMode"]=static_cast<cocos2d::ui::RichText::WrapMode(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getWrapMode);
mt["get"]["WrapMode"]=mt["GetWrapMode"];
mt["SetHorizontalAlignment"]=static_cast<void(cocos2d::ui::RichText::*)(cocos2d::ui::RichText::HorizontalAlignment)>(&cocos2d::ui::RichText::setHorizontalAlignment);
mt["set"]["HorizontalAlignment"]=mt["SetHorizontalAlignment"];
mt["GetHorizontalAlignment"]=static_cast<cocos2d::ui::RichText::HorizontalAlignment(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getHorizontalAlignment);
mt["get"]["HorizontalAlignment"]=mt["GetHorizontalAlignment"];
mt["SetFontColor"]=static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setFontColor);
mt["set"]["FontColor"]=mt["SetFontColor"];
mt["GetFontColor"]=static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontColor);
mt["get"]["FontColor"]=mt["GetFontColor"];
mt["GetFontColor3B"]=static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontColor3B);
mt["get"]["FontColor3B"]=mt["GetFontColor3B"];
mt["SetFontSize"]=static_cast<void(cocos2d::ui::RichText::*)(float)>(&cocos2d::ui::RichText::setFontSize);
mt["set"]["FontSize"]=mt["SetFontSize"];
mt["GetFontSize"]=static_cast<float(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontSize);
mt["get"]["FontSize"]=mt["GetFontSize"];
mt["SetFontFace"]=static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setFontFace);
mt["set"]["FontFace"]=mt["SetFontFace"];
mt["GetFontFace"]=static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getFontFace);
mt["get"]["FontFace"]=mt["GetFontFace"];
mt["SetAnchorFontColor"]=static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::setAnchorFontColor);
mt["set"]["AnchorFontColor"]=mt["SetAnchorFontColor"];
mt["GetAnchorFontColor"]=static_cast<std::string(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorFontColor);
mt["get"]["AnchorFontColor"]=mt["GetAnchorFontColor"];
mt["GetAnchorFontColor3B"]=static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorFontColor3B);
mt["get"]["AnchorFontColor3B"]=mt["GetAnchorFontColor3B"];
mt["SetAnchorTextBold"]=static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextBold);
mt["set"]["AnchorTextBold"]=mt["SetAnchorTextBold"];
mt["IsAnchorTextBoldEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextBoldEnabled);
mt["get"]["AnchorTextBoldEnabled"]=mt["IsAnchorTextBoldEnabled"];
mt["SetAnchorTextItalic"]=static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextItalic);
mt["set"]["AnchorTextItalic"]=mt["SetAnchorTextItalic"];
mt["IsAnchorTextItalicEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextItalicEnabled);
mt["get"]["AnchorTextItalicEnabled"]=mt["IsAnchorTextItalicEnabled"];
mt["SetAnchorTextDel"]=static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextDel);
mt["set"]["AnchorTextDel"]=mt["SetAnchorTextDel"];
mt["IsAnchorTextDelEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextDelEnabled);
mt["get"]["AnchorTextDelEnabled"]=mt["IsAnchorTextDelEnabled"];
mt["SetAnchorTextUnderline"]=static_cast<void(cocos2d::ui::RichText::*)(bool)>(&cocos2d::ui::RichText::setAnchorTextUnderline);
mt["set"]["AnchorTextUnderline"]=mt["SetAnchorTextUnderline"];
mt["IsAnchorTextUnderlineEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextUnderlineEnabled);
mt["get"]["AnchorTextUnderlineEnabled"]=mt["IsAnchorTextUnderlineEnabled"];
mt["SetAnchorTextOutline"]=sol::overload([](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,int arg2){return obj->setAnchorTextOutline(arg0,arg1,arg2);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextOutline(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextOutline(arg0);});
mt["set"]["AnchorTextOutline"]=mt["SetAnchorTextOutline"];
mt["IsAnchorTextOutlineEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextOutlineEnabled);
mt["get"]["AnchorTextOutlineEnabled"]=mt["IsAnchorTextOutlineEnabled"];
mt["GetAnchorTextOutlineColor3B"]=static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextOutlineColor3B);
mt["get"]["AnchorTextOutlineColor3B"]=mt["GetAnchorTextOutlineColor3B"];
mt["GetAnchorTextOutlineSize"]=static_cast<int(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextOutlineSize);
mt["get"]["AnchorTextOutlineSize"]=mt["GetAnchorTextOutlineSize"];
mt["SetAnchorTextShadow"]=sol::overload([](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,const cocos2d::Size& arg2,int arg3){return obj->setAnchorTextShadow(arg0,arg1,arg2,arg3);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1,const cocos2d::Size& arg2){return obj->setAnchorTextShadow(arg0,arg1,arg2);},[](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextShadow(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextShadow(arg0);});
mt["set"]["AnchorTextShadow"]=mt["SetAnchorTextShadow"];
mt["IsAnchorTextShadowEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextShadowEnabled);
mt["get"]["AnchorTextShadowEnabled"]=mt["IsAnchorTextShadowEnabled"];
mt["GetAnchorTextShadowColor3B"]=static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowColor3B);
mt["get"]["AnchorTextShadowColor3B"]=mt["GetAnchorTextShadowColor3B"];
mt["GetAnchorTextShadowOffset"]=static_cast<cocos2d::Size(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowOffset);
mt["get"]["AnchorTextShadowOffset"]=mt["GetAnchorTextShadowOffset"];
mt["GetAnchorTextShadowBlurRadius"]=static_cast<int(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextShadowBlurRadius);
mt["get"]["AnchorTextShadowBlurRadius"]=mt["GetAnchorTextShadowBlurRadius"];
mt["SetAnchorTextGlow"]=sol::overload([](cocos2d::ui::RichText* obj,bool arg0,const cocos2d::Color3B& arg1){return obj->setAnchorTextGlow(arg0,arg1);},[](cocos2d::ui::RichText* obj,bool arg0){return obj->setAnchorTextGlow(arg0);});
mt["set"]["AnchorTextGlow"]=mt["SetAnchorTextGlow"];
mt["IsAnchorTextGlowEnabled"]=static_cast<bool(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::isAnchorTextGlowEnabled);
mt["get"]["AnchorTextGlowEnabled"]=mt["IsAnchorTextGlowEnabled"];
mt["GetAnchorTextGlowColor3B"]=static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)()>(&cocos2d::ui::RichText::getAnchorTextGlowColor3B);
mt["get"]["AnchorTextGlowColor3B"]=mt["GetAnchorTextGlowColor3B"];
mt["SetDefaults"]=static_cast<void(cocos2d::ui::RichText::*)(const cocos2d::ValueMap&)>(&cocos2d::ui::RichText::setDefaults);
mt["set"]["Defaults"]=mt["SetDefaults"];
mt["GetDefaults"]=static_cast<cocos2d::ValueMap(cocos2d::ui::RichText::*)()const>(&cocos2d::ui::RichText::getDefaults);
mt["get"]["Defaults"]=mt["GetDefaults"];
mt["Color3BWithString"]=static_cast<cocos2d::Color3B(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::color3BWithString);
mt["StringWithColor3B"]=static_cast<std::string(cocos2d::ui::RichText::*)(const cocos2d::Color3B&)>(&cocos2d::ui::RichText::stringWithColor3B);
mt["StringWithColor4B"]=static_cast<std::string(cocos2d::ui::RichText::*)(const cocos2d::Color4B&)>(&cocos2d::ui::RichText::stringWithColor4B);
mt["static"]["SetTagDescription"]=static_cast<void(*)(const std::string&,bool,cocos2d::ui::RichText::VisitEnterHandler)>(&cocos2d::ui::RichText::setTagDescription);
mt["static"]["RemoveTagDescription"]=static_cast<void(*)(const std::string&)>(&cocos2d::ui::RichText::removeTagDescription);
mt["OpenUrl"]=static_cast<void(cocos2d::ui::RichText::*)(const std::string&)>(&cocos2d::ui::RichText::openUrl);
mt["SetOpenUrlHandler"]=static_cast<void(cocos2d::ui::RichText::*)(const cocos2d::ui::RichText::OpenUrlHandler&)>(&cocos2d::ui::RichText::setOpenUrlHandler);
mt["set"]["OpenUrlHandler"]=mt["SetOpenUrlHandler"];
mt["static"]["get"]["KEY_VERTICAL_SPACE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_VERTICAL_SPACE;};
mt["static"]["get"]["KEY_WRAP_MODE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_WRAP_MODE;};
mt["static"]["get"]["KEY_HORIZONTAL_ALIGNMENT"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_HORIZONTAL_ALIGNMENT;};
mt["static"]["get"]["KEY_FONT_COLOR_STRING"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_FONT_COLOR_STRING;};
mt["static"]["get"]["KEY_FONT_SIZE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_FONT_SIZE;};
mt["static"]["get"]["KEY_FONT_SMALL"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_FONT_SMALL;};
mt["static"]["get"]["KEY_FONT_BIG"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_FONT_BIG;};
mt["static"]["get"]["KEY_FONT_FACE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_FONT_FACE;};
mt["static"]["get"]["KEY_TEXT_BOLD"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_BOLD;};
mt["static"]["get"]["KEY_TEXT_ITALIC"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_ITALIC;};
mt["static"]["get"]["KEY_TEXT_LINE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_LINE;};
mt["static"]["get"]["VALUE_TEXT_LINE_NONE"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_LINE_NONE;};
mt["static"]["get"]["VALUE_TEXT_LINE_DEL"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_LINE_DEL;};
mt["static"]["get"]["VALUE_TEXT_LINE_UNDER"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_LINE_UNDER;};
mt["static"]["get"]["KEY_TEXT_STYLE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_STYLE;};
mt["static"]["get"]["VALUE_TEXT_STYLE_NONE"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_STYLE_NONE;};
mt["static"]["get"]["VALUE_TEXT_STYLE_OUTLINE"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_STYLE_OUTLINE;};
mt["static"]["get"]["VALUE_TEXT_STYLE_SHADOW"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_STYLE_SHADOW;};
mt["static"]["get"]["VALUE_TEXT_STYLE_GLOW"]=[]()->const std::string&{return cocos2d::ui::RichText::VALUE_TEXT_STYLE_GLOW;};
mt["static"]["get"]["KEY_TEXT_OUTLINE_COLOR"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_OUTLINE_COLOR;};
mt["static"]["get"]["KEY_TEXT_OUTLINE_SIZE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_OUTLINE_SIZE;};
mt["static"]["get"]["KEY_TEXT_SHADOW_COLOR"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_SHADOW_COLOR;};
mt["static"]["get"]["KEY_TEXT_SHADOW_OFFSET_WIDTH"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_WIDTH;};
mt["static"]["get"]["KEY_TEXT_SHADOW_OFFSET_HEIGHT"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_SHADOW_OFFSET_HEIGHT;};
mt["static"]["get"]["KEY_TEXT_SHADOW_BLUR_RADIUS"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_SHADOW_BLUR_RADIUS;};
mt["static"]["get"]["KEY_TEXT_GLOW_COLOR"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_TEXT_GLOW_COLOR;};
mt["static"]["get"]["KEY_URL"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_URL;};
mt["static"]["get"]["KEY_ANCHOR_FONT_COLOR_STRING"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_FONT_COLOR_STRING;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_BOLD"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_BOLD;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_ITALIC"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_ITALIC;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_LINE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_LINE;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_STYLE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_STYLE;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_OUTLINE_COLOR"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_COLOR;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_OUTLINE_SIZE"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_OUTLINE_SIZE;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_SHADOW_COLOR"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_COLOR;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS;};
mt["static"]["get"]["KEY_ANCHOR_TEXT_GLOW_COLOR"]=[]()->const std::string&{return cocos2d::ui::RichText::KEY_ANCHOR_TEXT_GLOW_COLOR;};
RegisterLuaUIRichTextWrapModeAuto(lua);
RegisterLuaUIRichTextHorizontalAlignmentAuto(lua);
}
void RegisterLuaUIHBoxAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::HBox).name()] = sol::usertype_traits<cocos2d::ui::HBox*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::HBox>("deprecated.cocos2d::ui::HBox");
dep[sol::base_classes]=sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::HBox*>::metatable(),sol::usertype_traits<cocos2d::ui::Layout*>::metatable());
lua["ccui"]["HBox"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ui::HBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::HBox::create),static_cast<cocos2d::ui::HBox*(*)()>(&cocos2d::ui::HBox::create));
}
void RegisterLuaUIVBoxAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::VBox).name()] = sol::usertype_traits<cocos2d::ui::VBox*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::VBox>("deprecated.cocos2d::ui::VBox");
dep[sol::base_classes]=sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::VBox*>::metatable(),sol::usertype_traits<cocos2d::ui::Layout*>::metatable());
lua["ccui"]["VBox"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ui::VBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::VBox::create),static_cast<cocos2d::ui::VBox*(*)()>(&cocos2d::ui::VBox::create));
}
void RegisterLuaUIRelativeBoxAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ui::RelativeBox).name()] = sol::usertype_traits<cocos2d::ui::RelativeBox*>::metatable();
auto dep=lua.new_usertype<cocos2d::ui::RelativeBox>("deprecated.cocos2d::ui::RelativeBox");
dep[sol::base_classes]=sol::bases<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ui::RelativeBox*>::metatable(),sol::usertype_traits<cocos2d::ui::Layout*>::metatable());
lua["ccui"]["RelativeBox"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ui::RelativeBox*(*)(const cocos2d::Size&)>(&cocos2d::ui::RelativeBox::create),static_cast<cocos2d::ui::RelativeBox*(*)()>(&cocos2d::ui::RelativeBox::create));
}
}
