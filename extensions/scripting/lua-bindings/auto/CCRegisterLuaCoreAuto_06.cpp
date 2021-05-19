#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
void RegisterLuaCoreActionFloatAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ActionFloat>("cc","ActionFloat",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ActionFloat*(*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::create));
mt.set_function("StartWithTarget",static_cast<void(cocos2d::ActionFloat::*)(cocos2d::Node*)>(&cocos2d::ActionFloat::startWithTarget));
mt.set_function("Update",static_cast<void(cocos2d::ActionFloat::*)(float)>(&cocos2d::ActionFloat::update));
mt.set_function("Reverse",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::reverse));
mt.set_function("Clone",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::clone));
}
void RegisterLuaCoreEventKeyboardKeyCodeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventKeyboard"];
pTable.new_enum<cocos2d::EventKeyboard::KeyCode>("KeyCode",{
{"KEY_NONE",cocos2d::EventKeyboard::KeyCode::KEY_NONE}
,{"KEY_PAUSE",cocos2d::EventKeyboard::KeyCode::KEY_PAUSE}
,{"KEY_SCROLL_LOCK",cocos2d::EventKeyboard::KeyCode::KEY_SCROLL_LOCK}
,{"KEY_PRINT",cocos2d::EventKeyboard::KeyCode::KEY_PRINT}
,{"KEY_SYSREQ",cocos2d::EventKeyboard::KeyCode::KEY_SYSREQ}
,{"KEY_BREAK",cocos2d::EventKeyboard::KeyCode::KEY_BREAK}
,{"KEY_ESCAPE",cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE}
,{"KEY_BACK",cocos2d::EventKeyboard::KeyCode::KEY_BACK}
,{"KEY_BACKSPACE",cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE}
,{"KEY_TAB",cocos2d::EventKeyboard::KeyCode::KEY_TAB}
,{"KEY_BACK_TAB",cocos2d::EventKeyboard::KeyCode::KEY_BACK_TAB}
,{"KEY_RETURN",cocos2d::EventKeyboard::KeyCode::KEY_RETURN}
,{"KEY_CAPS_LOCK",cocos2d::EventKeyboard::KeyCode::KEY_CAPS_LOCK}
,{"KEY_SHIFT",cocos2d::EventKeyboard::KeyCode::KEY_SHIFT}
,{"KEY_LEFT_SHIFT",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_SHIFT}
,{"KEY_RIGHT_SHIFT",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_SHIFT}
,{"KEY_CTRL",cocos2d::EventKeyboard::KeyCode::KEY_CTRL}
,{"KEY_LEFT_CTRL",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_CTRL}
,{"KEY_RIGHT_CTRL",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_CTRL}
,{"KEY_ALT",cocos2d::EventKeyboard::KeyCode::KEY_ALT}
,{"KEY_LEFT_ALT",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ALT}
,{"KEY_RIGHT_ALT",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ALT}
,{"KEY_MENU",cocos2d::EventKeyboard::KeyCode::KEY_MENU}
,{"KEY_HYPER",cocos2d::EventKeyboard::KeyCode::KEY_HYPER}
,{"KEY_INSERT",cocos2d::EventKeyboard::KeyCode::KEY_INSERT}
,{"KEY_HOME",cocos2d::EventKeyboard::KeyCode::KEY_HOME}
,{"KEY_PG_UP",cocos2d::EventKeyboard::KeyCode::KEY_PG_UP}
,{"KEY_DELETE",cocos2d::EventKeyboard::KeyCode::KEY_DELETE}
,{"KEY_END",cocos2d::EventKeyboard::KeyCode::KEY_END}
,{"KEY_PG_DOWN",cocos2d::EventKeyboard::KeyCode::KEY_PG_DOWN}
,{"KEY_LEFT_ARROW",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW}
,{"KEY_RIGHT_ARROW",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW}
,{"KEY_UP_ARROW",cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW}
,{"KEY_DOWN_ARROW",cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW}
,{"KEY_NUM_LOCK",cocos2d::EventKeyboard::KeyCode::KEY_NUM_LOCK}
,{"KEY_KP_PLUS",cocos2d::EventKeyboard::KeyCode::KEY_KP_PLUS}
,{"KEY_KP_MINUS",cocos2d::EventKeyboard::KeyCode::KEY_KP_MINUS}
,{"KEY_KP_MULTIPLY",cocos2d::EventKeyboard::KeyCode::KEY_KP_MULTIPLY}
,{"KEY_KP_DIVIDE",cocos2d::EventKeyboard::KeyCode::KEY_KP_DIVIDE}
,{"KEY_KP_ENTER",cocos2d::EventKeyboard::KeyCode::KEY_KP_ENTER}
,{"KEY_KP_HOME",cocos2d::EventKeyboard::KeyCode::KEY_KP_HOME}
,{"KEY_KP_UP",cocos2d::EventKeyboard::KeyCode::KEY_KP_UP}
,{"KEY_KP_PG_UP",cocos2d::EventKeyboard::KeyCode::KEY_KP_PG_UP}
,{"KEY_KP_LEFT",cocos2d::EventKeyboard::KeyCode::KEY_KP_LEFT}
,{"KEY_KP_FIVE",cocos2d::EventKeyboard::KeyCode::KEY_KP_FIVE}
,{"KEY_KP_RIGHT",cocos2d::EventKeyboard::KeyCode::KEY_KP_RIGHT}
,{"KEY_KP_END",cocos2d::EventKeyboard::KeyCode::KEY_KP_END}
,{"KEY_KP_DOWN",cocos2d::EventKeyboard::KeyCode::KEY_KP_DOWN}
,{"KEY_KP_PG_DOWN",cocos2d::EventKeyboard::KeyCode::KEY_KP_PG_DOWN}
,{"KEY_KP_INSERT",cocos2d::EventKeyboard::KeyCode::KEY_KP_INSERT}
,{"KEY_KP_DELETE",cocos2d::EventKeyboard::KeyCode::KEY_KP_DELETE}
,{"KEY_F1",cocos2d::EventKeyboard::KeyCode::KEY_F1}
,{"KEY_F2",cocos2d::EventKeyboard::KeyCode::KEY_F2}
,{"KEY_F3",cocos2d::EventKeyboard::KeyCode::KEY_F3}
,{"KEY_F4",cocos2d::EventKeyboard::KeyCode::KEY_F4}
,{"KEY_F5",cocos2d::EventKeyboard::KeyCode::KEY_F5}
,{"KEY_F6",cocos2d::EventKeyboard::KeyCode::KEY_F6}
,{"KEY_F7",cocos2d::EventKeyboard::KeyCode::KEY_F7}
,{"KEY_F8",cocos2d::EventKeyboard::KeyCode::KEY_F8}
,{"KEY_F9",cocos2d::EventKeyboard::KeyCode::KEY_F9}
,{"KEY_F10",cocos2d::EventKeyboard::KeyCode::KEY_F10}
,{"KEY_F11",cocos2d::EventKeyboard::KeyCode::KEY_F11}
,{"KEY_F12",cocos2d::EventKeyboard::KeyCode::KEY_F12}
,{"KEY_SPACE",cocos2d::EventKeyboard::KeyCode::KEY_SPACE}
,{"KEY_EXCLAM",cocos2d::EventKeyboard::KeyCode::KEY_EXCLAM}
,{"KEY_QUOTE",cocos2d::EventKeyboard::KeyCode::KEY_QUOTE}
,{"KEY_NUMBER",cocos2d::EventKeyboard::KeyCode::KEY_NUMBER}
,{"KEY_DOLLAR",cocos2d::EventKeyboard::KeyCode::KEY_DOLLAR}
,{"KEY_PERCENT",cocos2d::EventKeyboard::KeyCode::KEY_PERCENT}
,{"KEY_CIRCUMFLEX",cocos2d::EventKeyboard::KeyCode::KEY_CIRCUMFLEX}
,{"KEY_AMPERSAND",cocos2d::EventKeyboard::KeyCode::KEY_AMPERSAND}
,{"KEY_APOSTROPHE",cocos2d::EventKeyboard::KeyCode::KEY_APOSTROPHE}
,{"KEY_LEFT_PARENTHESIS",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_PARENTHESIS}
,{"KEY_RIGHT_PARENTHESIS",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_PARENTHESIS}
,{"KEY_ASTERISK",cocos2d::EventKeyboard::KeyCode::KEY_ASTERISK}
,{"KEY_PLUS",cocos2d::EventKeyboard::KeyCode::KEY_PLUS}
,{"KEY_COMMA",cocos2d::EventKeyboard::KeyCode::KEY_COMMA}
,{"KEY_MINUS",cocos2d::EventKeyboard::KeyCode::KEY_MINUS}
,{"KEY_PERIOD",cocos2d::EventKeyboard::KeyCode::KEY_PERIOD}
,{"KEY_SLASH",cocos2d::EventKeyboard::KeyCode::KEY_SLASH}
,{"KEY_0",cocos2d::EventKeyboard::KeyCode::KEY_0}
,{"KEY_1",cocos2d::EventKeyboard::KeyCode::KEY_1}
,{"KEY_2",cocos2d::EventKeyboard::KeyCode::KEY_2}
,{"KEY_3",cocos2d::EventKeyboard::KeyCode::KEY_3}
,{"KEY_4",cocos2d::EventKeyboard::KeyCode::KEY_4}
,{"KEY_5",cocos2d::EventKeyboard::KeyCode::KEY_5}
,{"KEY_6",cocos2d::EventKeyboard::KeyCode::KEY_6}
,{"KEY_7",cocos2d::EventKeyboard::KeyCode::KEY_7}
,{"KEY_8",cocos2d::EventKeyboard::KeyCode::KEY_8}
,{"KEY_9",cocos2d::EventKeyboard::KeyCode::KEY_9}
,{"KEY_COLON",cocos2d::EventKeyboard::KeyCode::KEY_COLON}
,{"KEY_SEMICOLON",cocos2d::EventKeyboard::KeyCode::KEY_SEMICOLON}
,{"KEY_LESS_THAN",cocos2d::EventKeyboard::KeyCode::KEY_LESS_THAN}
,{"KEY_EQUAL",cocos2d::EventKeyboard::KeyCode::KEY_EQUAL}
,{"KEY_GREATER_THAN",cocos2d::EventKeyboard::KeyCode::KEY_GREATER_THAN}
,{"KEY_QUESTION",cocos2d::EventKeyboard::KeyCode::KEY_QUESTION}
,{"KEY_AT",cocos2d::EventKeyboard::KeyCode::KEY_AT}
,{"KEY_CAPITAL_A",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A}
,{"KEY_CAPITAL_B",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_B}
,{"KEY_CAPITAL_C",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_C}
,{"KEY_CAPITAL_D",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D}
,{"KEY_CAPITAL_E",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_E}
,{"KEY_CAPITAL_F",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_F}
,{"KEY_CAPITAL_G",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_G}
,{"KEY_CAPITAL_H",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_H}
,{"KEY_CAPITAL_I",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_I}
,{"KEY_CAPITAL_J",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_J}
,{"KEY_CAPITAL_K",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_K}
,{"KEY_CAPITAL_L",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_L}
,{"KEY_CAPITAL_M",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_M}
,{"KEY_CAPITAL_N",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_N}
,{"KEY_CAPITAL_O",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_O}
,{"KEY_CAPITAL_P",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_P}
,{"KEY_CAPITAL_Q",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Q}
,{"KEY_CAPITAL_R",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_R}
,{"KEY_CAPITAL_S",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S}
,{"KEY_CAPITAL_T",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_T}
,{"KEY_CAPITAL_U",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_U}
,{"KEY_CAPITAL_V",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_V}
,{"KEY_CAPITAL_W",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W}
,{"KEY_CAPITAL_X",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_X}
,{"KEY_CAPITAL_Y",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Y}
,{"KEY_CAPITAL_Z",cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Z}
,{"KEY_LEFT_BRACKET",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_BRACKET}
,{"KEY_BACK_SLASH",cocos2d::EventKeyboard::KeyCode::KEY_BACK_SLASH}
,{"KEY_RIGHT_BRACKET",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_BRACKET}
,{"KEY_UNDERSCORE",cocos2d::EventKeyboard::KeyCode::KEY_UNDERSCORE}
,{"KEY_GRAVE",cocos2d::EventKeyboard::KeyCode::KEY_GRAVE}
,{"KEY_A",cocos2d::EventKeyboard::KeyCode::KEY_A}
,{"KEY_B",cocos2d::EventKeyboard::KeyCode::KEY_B}
,{"KEY_C",cocos2d::EventKeyboard::KeyCode::KEY_C}
,{"KEY_D",cocos2d::EventKeyboard::KeyCode::KEY_D}
,{"KEY_E",cocos2d::EventKeyboard::KeyCode::KEY_E}
,{"KEY_F",cocos2d::EventKeyboard::KeyCode::KEY_F}
,{"KEY_G",cocos2d::EventKeyboard::KeyCode::KEY_G}
,{"KEY_H",cocos2d::EventKeyboard::KeyCode::KEY_H}
,{"KEY_I",cocos2d::EventKeyboard::KeyCode::KEY_I}
,{"KEY_J",cocos2d::EventKeyboard::KeyCode::KEY_J}
,{"KEY_K",cocos2d::EventKeyboard::KeyCode::KEY_K}
,{"KEY_L",cocos2d::EventKeyboard::KeyCode::KEY_L}
,{"KEY_M",cocos2d::EventKeyboard::KeyCode::KEY_M}
,{"KEY_N",cocos2d::EventKeyboard::KeyCode::KEY_N}
,{"KEY_O",cocos2d::EventKeyboard::KeyCode::KEY_O}
,{"KEY_P",cocos2d::EventKeyboard::KeyCode::KEY_P}
,{"KEY_Q",cocos2d::EventKeyboard::KeyCode::KEY_Q}
,{"KEY_R",cocos2d::EventKeyboard::KeyCode::KEY_R}
,{"KEY_S",cocos2d::EventKeyboard::KeyCode::KEY_S}
,{"KEY_T",cocos2d::EventKeyboard::KeyCode::KEY_T}
,{"KEY_U",cocos2d::EventKeyboard::KeyCode::KEY_U}
,{"KEY_V",cocos2d::EventKeyboard::KeyCode::KEY_V}
,{"KEY_W",cocos2d::EventKeyboard::KeyCode::KEY_W}
,{"KEY_X",cocos2d::EventKeyboard::KeyCode::KEY_X}
,{"KEY_Y",cocos2d::EventKeyboard::KeyCode::KEY_Y}
,{"KEY_Z",cocos2d::EventKeyboard::KeyCode::KEY_Z}
,{"KEY_LEFT_BRACE",cocos2d::EventKeyboard::KeyCode::KEY_LEFT_BRACE}
,{"KEY_BAR",cocos2d::EventKeyboard::KeyCode::KEY_BAR}
,{"KEY_RIGHT_BRACE",cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_BRACE}
,{"KEY_TILDE",cocos2d::EventKeyboard::KeyCode::KEY_TILDE}
,{"KEY_EURO",cocos2d::EventKeyboard::KeyCode::KEY_EURO}
,{"KEY_POUND",cocos2d::EventKeyboard::KeyCode::KEY_POUND}
,{"KEY_YEN",cocos2d::EventKeyboard::KeyCode::KEY_YEN}
,{"KEY_MIDDLE_DOT",cocos2d::EventKeyboard::KeyCode::KEY_MIDDLE_DOT}
,{"KEY_SEARCH",cocos2d::EventKeyboard::KeyCode::KEY_SEARCH}
,{"KEY_DPAD_LEFT",cocos2d::EventKeyboard::KeyCode::KEY_DPAD_LEFT}
,{"KEY_DPAD_RIGHT",cocos2d::EventKeyboard::KeyCode::KEY_DPAD_RIGHT}
,{"KEY_DPAD_UP",cocos2d::EventKeyboard::KeyCode::KEY_DPAD_UP}
,{"KEY_DPAD_DOWN",cocos2d::EventKeyboard::KeyCode::KEY_DPAD_DOWN}
,{"KEY_DPAD_CENTER",cocos2d::EventKeyboard::KeyCode::KEY_DPAD_CENTER}
,{"KEY_ENTER",cocos2d::EventKeyboard::KeyCode::KEY_ENTER}
,{"KEY_PLAY",cocos2d::EventKeyboard::KeyCode::KEY_PLAY}
});}
void RegisterLuaCoreEventKeyboardAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventKeyboard>("cc","EventKeyboard",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt[sol::call_constructor]=sol::constructors<cocos2d::EventKeyboard(cocos2d::EventKeyboard::KeyCode,bool)>();
RegisterLuaCoreEventKeyboardKeyCodeAuto(lua);
}
void RegisterLuaCorePropertiesAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::Properties>("cc","Properties",true);
mt.set_function("CreateNonRefCounted",static_cast<cocos2d::Properties*(*)(const std::string&)>(&cocos2d::Properties::createNonRefCounted));
mt.set_function("GetNextProperty",static_cast<const char*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextProperty));
mt.set_function("GetNextNamespace",static_cast<cocos2d::Properties*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextNamespace));
mt.set_function("Rewind",static_cast<void(cocos2d::Properties::*)()>(&cocos2d::Properties::rewind));
mt.set_function("GetNamespace",sol::overload(static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getNamespace),[](cocos2d::Properties* obj,const char* arg0){return obj->getNamespace(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getNamespace(arg0,arg1);},[](cocos2d::Properties* obj,const char* arg0,bool arg1,bool arg2){return obj->getNamespace(arg0,arg1,arg2);}));
mt.set_function("GetId",static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getId));
mt.set_function("Exists",static_cast<bool(cocos2d::Properties::*)(const char*)const>(&cocos2d::Properties::exists));
mt.set_function("GetType",sol::overload([](cocos2d::Properties* obj){return obj->getType();},[](cocos2d::Properties* obj,const char* arg0){return obj->getType(arg0);}));
mt.set_function("GetString",sol::overload([](cocos2d::Properties* obj){return obj->getString();},[](cocos2d::Properties* obj,const char* arg0){return obj->getString(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getString(arg0,arg1);}));
mt.set_function("SetString",static_cast<bool(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setString));
mt.set_function("GetBool",sol::overload([](cocos2d::Properties* obj){return obj->getBool();},[](cocos2d::Properties* obj,const char* arg0){return obj->getBool(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getBool(arg0,arg1);}));
mt.set_function("GetInt",sol::overload([](cocos2d::Properties* obj){return obj->getInt();},[](cocos2d::Properties* obj,const char* arg0){return obj->getInt(arg0);}));
mt.set_function("GetFloat",sol::overload([](cocos2d::Properties* obj){return obj->getFloat();},[](cocos2d::Properties* obj,const char* arg0){return obj->getFloat(arg0);}));
mt.set_function("GetLong",sol::overload([](cocos2d::Properties* obj){return obj->getLong();},[](cocos2d::Properties* obj,const char* arg0){return obj->getLong(arg0);}));
mt.set_function("GetMat4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Mat4*)const>(&cocos2d::Properties::getMat4));
mt.set_function("GetVec2",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec2*)const>(&cocos2d::Properties::getVec2));
mt.set_function("GetVec3",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getVec3));
mt.set_function("GetVec4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getVec4));
mt.set_function("GetQuaternionFromAxisAngle",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Quaternion*)const>(&cocos2d::Properties::getQuaternionFromAxisAngle));
mt.set_function("GetColor",sol::overload(static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getColor),static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getColor)));
mt.set_function("GetPath",static_cast<bool(cocos2d::Properties::*)(const char*,std::string*)const>(&cocos2d::Properties::getPath));
mt.set_function("GetVariable",sol::overload([](cocos2d::Properties* obj,const char* arg0){return obj->getVariable(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getVariable(arg0,arg1);}));
mt.set_function("SetVariable",static_cast<void(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setVariable));
mt.set_function("ParseVec2",static_cast<bool(*)(const char*,cocos2d::Vec2*)>(&cocos2d::Properties::parseVec2));
mt.set_function("ParseVec3",static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseVec3));
mt.set_function("ParseVec4",static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseVec4));
mt.set_function("ParseAxisAngle",static_cast<bool(*)(const char*,cocos2d::Quaternion*)>(&cocos2d::Properties::parseAxisAngle));
mt.set_function("ParseColor",sol::overload(static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseColor),static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseColor)));
}
void RegisterLuaCoreUserDefaultAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::UserDefault>("cc","UserDefault",true);
mt.set_function("GetBoolForKey",sol::overload(static_cast<bool(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::getBoolForKey),static_cast<bool(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getBoolForKey)));
mt.set_function("GetIntegerForKey",sol::overload(static_cast<int(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::getIntegerForKey),static_cast<int(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getIntegerForKey)));
mt.set_function("GetLargeIntForKey",sol::overload(static_cast<int64_t(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::getLargeIntForKey),static_cast<int64_t(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getLargeIntForKey)));
mt.set_function("GetFloatForKey",sol::overload(static_cast<float(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::getFloatForKey),static_cast<float(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getFloatForKey)));
mt.set_function("GetDoubleForKey",sol::overload(static_cast<double(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::getDoubleForKey),static_cast<double(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getDoubleForKey)));
mt.set_function("GetStringForKey",sol::overload(static_cast<std::string(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::getStringForKey),static_cast<std::string(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getStringForKey)));
mt.set_function("SetBoolForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::setBoolForKey));
mt.set_function("SetIntegerForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::setIntegerForKey));
mt.set_function("SetLargeIntForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::setLargeIntForKey));
mt.set_function("SetFloatForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::setFloatForKey));
mt.set_function("SetDoubleForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::setDoubleForKey));
mt.set_function("SetStringForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::setStringForKey));
mt.set_function("Flush",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::flush));
mt.set_function("DeleteValueForKey",static_cast<void(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::deleteValueForKey));
mt.set_function("Clear",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::Clear));
mt.set_function("GetInstance",static_cast<cocos2d::UserDefault*(*)()>(&cocos2d::UserDefault::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::UserDefault::destroyInstance));
mt.set_function("SetDelegate",static_cast<void(*)(cocos2d::UserDefault*)>(&cocos2d::UserDefault::setDelegate));
mt.set_function("SetEncryptEnabled",static_cast<void(cocos2d::UserDefault::*)(bool,cxx17::string_view,cxx17::string_view)>(&cocos2d::UserDefault::setEncryptEnabled));
mt.set_function("Encrypt",sol::overload(static_cast<void(cocos2d::UserDefault::*)(std::string&,int)>(&cocos2d::UserDefault::encrypt),static_cast<void(cocos2d::UserDefault::*)(char*,size_t,int)>(&cocos2d::UserDefault::encrypt)));
mt["Instance"]=sol::property(&cocos2d::UserDefault::getInstance,[](std::nullptr_t){cocos2d::UserDefault::destroyInstance();});
}
void RegisterLuaCoreFileUtilsAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::FileUtils>("cc","FileUtils",true);
mt.set_function("GetInstance",static_cast<cocos2d::FileUtils*(*)()>(&cocos2d::FileUtils::getInstance));
mt.set_function("DestroyInstance",static_cast<void(*)()>(&cocos2d::FileUtils::destroyInstance));
mt.set_function("SetDelegate",static_cast<void(*)(cocos2d::FileUtils*)>(&cocos2d::FileUtils::setDelegate));
mt.set_function("PurgeCachedEntries",static_cast<void(cocos2d::FileUtils::*)()>(&cocos2d::FileUtils::purgeCachedEntries));
mt.set_function("GetStringFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::basic_string<char, std::char_traits<char>, std::allocator<char> >)>)const>(&cocos2d::FileUtils::getStringFromFile),static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getStringFromFile)));
mt.set_function("GetDataFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (cocos2d::Data)>)const>(&cocos2d::FileUtils::getDataFromFile),static_cast<cocos2d::Data(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getDataFromFile)));
mt.set_function("GetContents",static_cast<cocos2d::FileUtils::Status(cocos2d::FileUtils::*)(const std::string&,cocos2d::ResizableBuffer*)const>(&cocos2d::FileUtils::getContents));
mt.set_function("FullPathForFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::fullPathForFilename));
mt.set_function("LoadFilenameLookup",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::loadFilenameLookupDictionaryFromFile));
mt.set_function("SetFilenameLookupDictionary",static_cast<void(cocos2d::FileUtils::*)(const cocos2d::ValueMap&)>(&cocos2d::FileUtils::setFilenameLookupDictionary));
mt.set_function("FullPathFromRelativeFile",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::fullPathFromRelativeFile));
mt.set_function("SetSearchResolutionsOrder",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >&)>(&cocos2d::FileUtils::setSearchResolutionsOrder));
mt.set_function("AddSearchResolutionsOrder",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchResolutionsOrder(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchResolutionsOrder(arg0,arg1);}));
mt.set_function("GetSearchResolutionsOrder",static_cast<const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchResolutionsOrder));
mt.set_function("SetSearchPaths",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >&)>(&cocos2d::FileUtils::setSearchPaths));
mt.set_function("GetDefaultResourceRootPath",static_cast<const std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getDefaultResourceRootPath));
mt.set_function("SetDefaultResourceRootPath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setDefaultResourceRootPath));
mt.set_function("AddSearchPath",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchPath(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchPath(arg0,arg1);}));
mt.set_function("GetSearchPaths",static_cast<const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchPaths));
mt.set_function("GetOriginalSearchPaths",static_cast<const std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getOriginalSearchPaths));
mt.set_function("GetWritablePath",static_cast<std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getWritablePath));
mt.set_function("SetWritablePath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setWritablePath));
mt.set_function("SetPopupNotify",static_cast<void(cocos2d::FileUtils::*)(bool)>(&cocos2d::FileUtils::setPopupNotify));
mt.set_function("IsPopupNotify",static_cast<bool(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::isPopupNotify));
mt.set_function("GetValueMapFromFile",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueMapFromFile));
mt.set_function("GetValueMapFromData",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const char*,int)const>(&cocos2d::FileUtils::getValueMapFromData));
mt.set_function("WriteToFile",static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeToFile));
mt.set_function("WriteStringToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(std::string,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeStringToFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::writeStringToFile)));
mt.set_function("WriteDataToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::Data,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeDataToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::Data&,const std::string&)const>(&cocos2d::FileUtils::writeDataToFile)));
mt.set_function("WriteBinaryToFile",static_cast<bool(*)(const void*,size_t,const std::string&)>(&cocos2d::FileUtils::writeBinaryToFile));
mt.set_function("WriteValueMapToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueMap,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueMapToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeValueMapToFile)));
mt.set_function("WriteValueVectorToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueVector,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueVectorToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueVector&,const std::string&)const>(&cocos2d::FileUtils::writeValueVectorToFile)));
mt.set_function("GetValueVectorFromFile",static_cast<cocos2d::ValueVector(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueVectorFromFile));
mt.set_function("IsFileExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isFileExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExist)));
mt.set_function("GetFileExtension",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileExtension));
mt.set_function("GetFileShortName",static_cast<std::string(*)(const std::string&)>(&cocos2d::FileUtils::getFileShortName));
mt.set_function("IsAbsolutePath",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isAbsolutePath));
mt.set_function("IsDirectoryExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isDirectoryExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExist)));
mt.set_function("CreateDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::createDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::createDirectory)));
mt.set_function("RemoveDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeDirectory)));
mt.set_function("RemoveFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeFile)));
mt.set_function("RenameFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile)));
mt.set_function("GetFileSize",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (long long)>)const>(&cocos2d::FileUtils::getFileSize),static_cast<int64_t(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileSize)));
mt.set_function("ListFiles",static_cast<std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::listFiles));
mt.set_function("ListFilesAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >)>)const>(&cocos2d::FileUtils::listFilesAsync));
mt.set_function("ListFilesRecursively",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >*)const>(&cocos2d::FileUtils::listFilesRecursively));
mt.set_function("ListFilesRecursivelyAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >)>)const>(&cocos2d::FileUtils::listFilesRecursivelyAsync));
mt.set_function("GetFullPathCache",static_cast<const std::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getFullPathCache));
mt.set_function("GetNewFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getNewFilename));
mt.set_function("IsFileExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExistInternal));
mt.set_function("IsDirectoryExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExistInternal));
mt["Instance"]=sol::property(&cocos2d::FileUtils::getInstance,[](std::nullptr_t){cocos2d::FileUtils::destroyInstance();});
}
void RegisterLuaCoreLanguageTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["cc"];
pTable.new_enum<cocos2d::LanguageType>("LanguageType",{
{"ENGLISH",cocos2d::LanguageType::ENGLISH}
,{"CHINESE",cocos2d::LanguageType::CHINESE}
,{"FRENCH",cocos2d::LanguageType::FRENCH}
,{"ITALIAN",cocos2d::LanguageType::ITALIAN}
,{"GERMAN",cocos2d::LanguageType::GERMAN}
,{"SPANISH",cocos2d::LanguageType::SPANISH}
,{"DUTCH",cocos2d::LanguageType::DUTCH}
,{"RUSSIAN",cocos2d::LanguageType::RUSSIAN}
,{"KOREAN",cocos2d::LanguageType::KOREAN}
,{"JAPANESE",cocos2d::LanguageType::JAPANESE}
,{"HUNGARIAN",cocos2d::LanguageType::HUNGARIAN}
,{"PORTUGUESE",cocos2d::LanguageType::PORTUGUESE}
,{"ARABIC",cocos2d::LanguageType::ARABIC}
,{"NORWEGIAN",cocos2d::LanguageType::NORWEGIAN}
,{"POLISH",cocos2d::LanguageType::POLISH}
,{"TURKISH",cocos2d::LanguageType::TURKISH}
,{"UKRAINIAN",cocos2d::LanguageType::UKRAINIAN}
,{"ROMANIAN",cocos2d::LanguageType::ROMANIAN}
,{"BULGARIAN",cocos2d::LanguageType::BULGARIAN}
,{"BELARUSIAN",cocos2d::LanguageType::BELARUSIAN}
});}
void RegisterLuaCoreEventAccelerationAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventAcceleration>("cc","EventAcceleration",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt[sol::call_constructor]=sol::constructors<cocos2d::EventAcceleration(const cocos2d::Acceleration&)>();
}
void RegisterLuaCoreEventCustomAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventCustom>("cc","EventCustom",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("SetUserData",static_cast<void(cocos2d::EventCustom::*)(void*)>(&cocos2d::EventCustom::setUserData));
mt.set_function("GetUserData",static_cast<void*(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getUserData));
mt.set_function("GetEventName",static_cast<const std::string&(cocos2d::EventCustom::*)()const>(&cocos2d::EventCustom::getEventName));
mt[sol::call_constructor]=sol::constructors<cocos2d::EventCustom(const std::string&)>();
}
void RegisterLuaCoreEventDispatcherAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventDispatcher>("cc","EventDispatcher",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function("AddEventListenerWithSceneGraphPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,cocos2d::Node*)>(&cocos2d::EventDispatcher::addEventListenerWithSceneGraphPriority));
mt.set_function("AddEventListenerWithFixedPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::addEventListenerWithFixedPriority));
mt.set_function("AddCustomEventListener",static_cast<cocos2d::EventListenerCustom*(cocos2d::EventDispatcher::*)(const std::string&,const std::function<void (cocos2d::EventCustom *)>&)>(&cocos2d::EventDispatcher::addCustomEventListener));
mt.set_function("RemoveEventListener",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*)>(&cocos2d::EventDispatcher::removeEventListener));
mt.set_function("RemoveEventListenersForType",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener::Type)>(&cocos2d::EventDispatcher::removeEventListenersForType));
mt.set_function("RemoveEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->removeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->removeEventListenersForTarget(arg0,arg1);}));
mt.set_function("RemoveCustomEventListeners",static_cast<void(cocos2d::EventDispatcher::*)(const std::string&)>(&cocos2d::EventDispatcher::removeCustomEventListeners));
mt.set_function("RemoveAllEventListeners",static_cast<void(cocos2d::EventDispatcher::*)()>(&cocos2d::EventDispatcher::removeAllEventListeners));
mt.set_function("PauseEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->pauseEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->pauseEventListenersForTarget(arg0,arg1);}));
mt.set_function("ResumeEventListenersForTarget",sol::overload([](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0){return obj->resumeEventListenersForTarget(arg0);},[](cocos2d::EventDispatcher* obj,cocos2d::Node* arg0,bool arg1){return obj->resumeEventListenersForTarget(arg0,arg1);}));
mt.set_function("SetPriority",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::EventListener*,int)>(&cocos2d::EventDispatcher::setPriority));
mt.set_function("SetEnabled",static_cast<void(cocos2d::EventDispatcher::*)(bool)>(&cocos2d::EventDispatcher::setEnabled));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::EventDispatcher::*)()const>(&cocos2d::EventDispatcher::isEnabled));
mt.set_function("DispatchEvent",static_cast<void(cocos2d::EventDispatcher::*)(cocos2d::Event*)>(&cocos2d::EventDispatcher::dispatchEvent));
mt.set_function("DispatchCustomEvent",sol::overload([](cocos2d::EventDispatcher* obj,const std::string& arg0){return obj->dispatchCustomEvent(arg0);},[](cocos2d::EventDispatcher* obj,const std::string& arg0,void* arg1){return obj->dispatchCustomEvent(arg0,arg1);}));
mt.set_function("HasEventListener",static_cast<bool(cocos2d::EventDispatcher::*)(const cocos2d::EventListener::ListenerID&)const>(&cocos2d::EventDispatcher::hasEventListener));
mt[sol::call_constructor]=sol::constructors<cocos2d::EventDispatcher()>();
}
void RegisterLuaCoreEventFocusAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::EventFocus>("cc","EventFocus",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Event,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt[sol::call_constructor]=sol::constructors<cocos2d::EventFocus(cocos2d::ui::Widget*,cocos2d::ui::Widget*)>();
}
