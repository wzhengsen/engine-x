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
void RegisterLuaCoreTintToAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TintTo,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("TintTo",false);
ns["TintTo"] = mt;
lua["TintTo"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::clone));
mt.set_function("reverse",static_cast<cocos2d::TintTo*(cocos2d::TintTo::*)()const>(&cocos2d::TintTo::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TintTo::*)(cocos2d::Node*)>(&cocos2d::TintTo::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TintTo::*)(float)>(&cocos2d::TintTo::update));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::TintTo*(*)(float,const cocos2d::Color3B&)>(&cocos2d::TintTo::create),static_cast<cocos2d::TintTo*(*)(float,uint8_t,uint8_t,uint8_t)>(&cocos2d::TintTo::create)));
}
void RegisterLuaCoreTintByAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TintBy,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("TintBy",false);
ns["TintBy"] = mt;
lua["TintBy"] = sol::nil;
mt.set_function("clone",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::clone));
mt.set_function("reverse",static_cast<cocos2d::TintBy*(cocos2d::TintBy::*)()const>(&cocos2d::TintBy::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TintBy::*)(cocos2d::Node*)>(&cocos2d::TintBy::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::TintBy::*)(float)>(&cocos2d::TintBy::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TintBy*(*)(float,int16_t,int16_t,int16_t)>(&cocos2d::TintBy::create));
}
void RegisterLuaCoreDelayTimeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::DelayTime,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("DelayTime",false);
ns["DelayTime"] = mt;
lua["DelayTime"] = sol::nil;
mt.set_function("update",static_cast<void(cocos2d::DelayTime::*)(float)>(&cocos2d::DelayTime::update));
mt.set_function("reverse",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::reverse));
mt.set_function("clone",static_cast<cocos2d::DelayTime*(cocos2d::DelayTime::*)()const>(&cocos2d::DelayTime::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::DelayTime*(*)(float)>(&cocos2d::DelayTime::create));
}
void RegisterLuaCoreAnimateAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Animate,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Animate",false);
ns["Animate"] = mt;
lua["Animate"] = sol::nil;
mt.set_function("setAnimation",static_cast<void(cocos2d::Animate::*)(cocos2d::Animation*)>(&cocos2d::Animate::setAnimation));
mt.set_function("getAnimation",sol::overload(static_cast<const cocos2d::Animation*(cocos2d::Animate::*)()const>(&cocos2d::Animate::getAnimation),static_cast<cocos2d::Animation*(cocos2d::Animate::*)()>(&cocos2d::Animate::getAnimation)));
mt.set_function("getCurrentFrameIndex",static_cast<int(cocos2d::Animate::*)()>(&cocos2d::Animate::getCurrentFrameIndex));
mt.set_function("clone",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::clone));
mt.set_function("reverse",static_cast<cocos2d::Animate*(cocos2d::Animate::*)()const>(&cocos2d::Animate::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Animate::*)(cocos2d::Node*)>(&cocos2d::Animate::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::Animate::*)()>(&cocos2d::Animate::stop));
mt.set_function("update",static_cast<void(cocos2d::Animate::*)(float)>(&cocos2d::Animate::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::Animate*(*)(cocos2d::Animation*)>(&cocos2d::Animate::create));
}
void RegisterLuaCoreTargetedActionAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TargetedAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("TargetedAction",false);
ns["TargetedAction"] = mt;
lua["TargetedAction"] = sol::nil;
mt.set_function("setForcedTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::setForcedTarget));
mt.set_function("getForcedTarget",sol::overload(static_cast<const cocos2d::Node*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::getForcedTarget),static_cast<cocos2d::Node*(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::getForcedTarget)));
mt.set_function("clone",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::clone));
mt.set_function("reverse",static_cast<cocos2d::TargetedAction*(cocos2d::TargetedAction::*)()const>(&cocos2d::TargetedAction::reverse));
mt.set_function("startWithTarget",static_cast<void(cocos2d::TargetedAction::*)(cocos2d::Node*)>(&cocos2d::TargetedAction::startWithTarget));
mt.set_function("stop",static_cast<void(cocos2d::TargetedAction::*)()>(&cocos2d::TargetedAction::stop));
mt.set_function("update",static_cast<void(cocos2d::TargetedAction::*)(float)>(&cocos2d::TargetedAction::update));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TargetedAction*(*)(cocos2d::Node*,cocos2d::FiniteTimeAction*)>(&cocos2d::TargetedAction::create));
}
void RegisterLuaCoreActionFloatAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::ActionFloat,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("ActionFloat",false);
ns["ActionFloat"] = mt;
lua["ActionFloat"] = sol::nil;
mt.set_function("startWithTarget",static_cast<void(cocos2d::ActionFloat::*)(cocos2d::Node*)>(&cocos2d::ActionFloat::startWithTarget));
mt.set_function("update",static_cast<void(cocos2d::ActionFloat::*)(float)>(&cocos2d::ActionFloat::update));
mt.set_function("reverse",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::reverse));
mt.set_function("clone",static_cast<cocos2d::ActionFloat*(cocos2d::ActionFloat::*)()const>(&cocos2d::ActionFloat::clone));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ActionFloat*(*)(float,float,float,cocos2d::ActionFloat::ActionFloatCallback)>(&cocos2d::ActionFloat::create));
}
void RegisterLuaCoreEventKeyboardKeyCodeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["EventKeyboard"];
pTable.new_enum("KeyCode"
,"KEY_NONE",0
,"KEY_PAUSE",1
,"KEY_SCROLL_LOCK",2
,"KEY_PRINT",3
,"KEY_SYSREQ",4
,"KEY_BREAK",5
,"KEY_ESCAPE",6
,"KEY_BACK",6
,"KEY_BACKSPACE",7
,"KEY_TAB",8
,"KEY_BACK_TAB",9
,"KEY_RETURN",10
,"KEY_CAPS_LOCK",11
,"KEY_SHIFT",12
,"KEY_LEFT_SHIFT",12
,"KEY_RIGHT_SHIFT",13
,"KEY_CTRL",14
,"KEY_LEFT_CTRL",14
,"KEY_RIGHT_CTRL",15
,"KEY_ALT",16
,"KEY_LEFT_ALT",16
,"KEY_RIGHT_ALT",17
,"KEY_MENU",18
,"KEY_HYPER",19
,"KEY_INSERT",20
,"KEY_HOME",21
,"KEY_PG_UP",22
,"KEY_DELETE",23
,"KEY_END",24
,"KEY_PG_DOWN",25
,"KEY_LEFT_ARROW",26
,"KEY_RIGHT_ARROW",27
,"KEY_UP_ARROW",28
,"KEY_DOWN_ARROW",29
,"KEY_NUM_LOCK",30
,"KEY_KP_PLUS",31
,"KEY_KP_MINUS",32
,"KEY_KP_MULTIPLY",33
,"KEY_KP_DIVIDE",34
,"KEY_KP_ENTER",35
,"KEY_KP_HOME",36
,"KEY_KP_UP",37
,"KEY_KP_PG_UP",38
,"KEY_KP_LEFT",39
,"KEY_KP_FIVE",40
,"KEY_KP_RIGHT",41
,"KEY_KP_END",42
,"KEY_KP_DOWN",43
,"KEY_KP_PG_DOWN",44
,"KEY_KP_INSERT",45
,"KEY_KP_DELETE",46
,"KEY_F1",47
,"KEY_F2",48
,"KEY_F3",49
,"KEY_F4",50
,"KEY_F5",51
,"KEY_F6",52
,"KEY_F7",53
,"KEY_F8",54
,"KEY_F9",55
,"KEY_F10",56
,"KEY_F11",57
,"KEY_F12",58
,"KEY_SPACE",59
,"KEY_EXCLAM",60
,"KEY_QUOTE",61
,"KEY_NUMBER",62
,"KEY_DOLLAR",63
,"KEY_PERCENT",64
,"KEY_CIRCUMFLEX",65
,"KEY_AMPERSAND",66
,"KEY_APOSTROPHE",67
,"KEY_LEFT_PARENTHESIS",68
,"KEY_RIGHT_PARENTHESIS",69
,"KEY_ASTERISK",70
,"KEY_PLUS",71
,"KEY_COMMA",72
,"KEY_MINUS",73
,"KEY_PERIOD",74
,"KEY_SLASH",75
,"KEY_0",76
,"KEY_1",77
,"KEY_2",78
,"KEY_3",79
,"KEY_4",80
,"KEY_5",81
,"KEY_6",82
,"KEY_7",83
,"KEY_8",84
,"KEY_9",85
,"KEY_COLON",86
,"KEY_SEMICOLON",87
,"KEY_LESS_THAN",88
,"KEY_EQUAL",89
,"KEY_GREATER_THAN",90
,"KEY_QUESTION",91
,"KEY_AT",92
,"KEY_CAPITAL_A",93
,"KEY_CAPITAL_B",94
,"KEY_CAPITAL_C",95
,"KEY_CAPITAL_D",96
,"KEY_CAPITAL_E",97
,"KEY_CAPITAL_F",98
,"KEY_CAPITAL_G",99
,"KEY_CAPITAL_H",100
,"KEY_CAPITAL_I",101
,"KEY_CAPITAL_J",102
,"KEY_CAPITAL_K",103
,"KEY_CAPITAL_L",104
,"KEY_CAPITAL_M",105
,"KEY_CAPITAL_N",106
,"KEY_CAPITAL_O",107
,"KEY_CAPITAL_P",108
,"KEY_CAPITAL_Q",109
,"KEY_CAPITAL_R",110
,"KEY_CAPITAL_S",111
,"KEY_CAPITAL_T",112
,"KEY_CAPITAL_U",113
,"KEY_CAPITAL_V",114
,"KEY_CAPITAL_W",115
,"KEY_CAPITAL_X",116
,"KEY_CAPITAL_Y",117
,"KEY_CAPITAL_Z",118
,"KEY_LEFT_BRACKET",119
,"KEY_BACK_SLASH",120
,"KEY_RIGHT_BRACKET",121
,"KEY_UNDERSCORE",122
,"KEY_GRAVE",123
,"KEY_A",124
,"KEY_B",125
,"KEY_C",126
,"KEY_D",127
,"KEY_E",128
,"KEY_F",129
,"KEY_G",130
,"KEY_H",131
,"KEY_I",132
,"KEY_J",133
,"KEY_K",134
,"KEY_L",135
,"KEY_M",136
,"KEY_N",137
,"KEY_O",138
,"KEY_P",139
,"KEY_Q",140
,"KEY_R",141
,"KEY_S",142
,"KEY_T",143
,"KEY_U",144
,"KEY_V",145
,"KEY_W",146
,"KEY_X",147
,"KEY_Y",148
,"KEY_Z",149
,"KEY_LEFT_BRACE",150
,"KEY_BAR",151
,"KEY_RIGHT_BRACE",152
,"KEY_TILDE",153
,"KEY_EURO",154
,"KEY_POUND",155
,"KEY_YEN",156
,"KEY_MIDDLE_DOT",157
,"KEY_SEARCH",158
,"KEY_DPAD_LEFT",159
,"KEY_DPAD_RIGHT",160
,"KEY_DPAD_UP",161
,"KEY_DPAD_DOWN",162
,"KEY_DPAD_CENTER",163
,"KEY_ENTER",164
,"KEY_PLAY",165
);}
void RegisterLuaCoreEventKeyboardAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::EventKeyboard,cocos2d::Event,cocos2d::Ref,cocos2d::LuaObject>("EventKeyboard",true);
ns["EventKeyboard"] = mt;
lua["EventKeyboard"] = sol::nil;
RegisterLuaCoreEventKeyboardKeyCodeAuto(lua);
}
void RegisterLuaCorePropertiesTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["Properties"];
pTable.new_enum("Type"
,"NONE",0
,"STRING",1
,"NUMBER",2
,"VECTOR2",3
,"VECTOR3",4
,"VECTOR4",5
,"MATRIX",6
);}
void RegisterLuaCorePropertiesAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Properties>("Properties",true);
ns["Properties"] = mt;
lua["Properties"] = sol::nil;
mt.set_function("getNextProperty",static_cast<const char*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextProperty));
mt.set_function("getNextNamespace",static_cast<cocos2d::Properties*(cocos2d::Properties::*)()>(&cocos2d::Properties::getNextNamespace));
mt.set_function("rewind",static_cast<void(cocos2d::Properties::*)()>(&cocos2d::Properties::rewind));
mt.set_function("getNamespace",sol::overload(static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getNamespace),[](cocos2d::Properties* obj,const char* arg0){return obj->getNamespace(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getNamespace(arg0,arg1);},[](cocos2d::Properties* obj,const char* arg0,bool arg1,bool arg2){return obj->getNamespace(arg0,arg1,arg2);}));
mt.set_function("getId",static_cast<const char*(cocos2d::Properties::*)()const>(&cocos2d::Properties::getId));
mt.set_function("exists",static_cast<bool(cocos2d::Properties::*)(const char*)const>(&cocos2d::Properties::exists));
mt.set_function("getType",sol::overload([](cocos2d::Properties* obj){return obj->getType();},[](cocos2d::Properties* obj,const char* arg0){return obj->getType(arg0);}));
mt.set_function("getString",sol::overload([](cocos2d::Properties* obj){return obj->getString();},[](cocos2d::Properties* obj,const char* arg0){return obj->getString(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getString(arg0,arg1);}));
mt.set_function("setString",static_cast<bool(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setString));
mt.set_function("getBool",sol::overload([](cocos2d::Properties* obj){return obj->getBool();},[](cocos2d::Properties* obj,const char* arg0){return obj->getBool(arg0);},[](cocos2d::Properties* obj,const char* arg0,bool arg1){return obj->getBool(arg0,arg1);}));
mt.set_function("getInt",sol::overload([](cocos2d::Properties* obj){return obj->getInt();},[](cocos2d::Properties* obj,const char* arg0){return obj->getInt(arg0);}));
mt.set_function("getFloat",sol::overload([](cocos2d::Properties* obj){return obj->getFloat();},[](cocos2d::Properties* obj,const char* arg0){return obj->getFloat(arg0);}));
mt.set_function("getLong",sol::overload([](cocos2d::Properties* obj){return obj->getLong();},[](cocos2d::Properties* obj,const char* arg0){return obj->getLong(arg0);}));
mt.set_function("getMat4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Mat4*)const>(&cocos2d::Properties::getMat4));
mt.set_function("getVec2",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec2*)const>(&cocos2d::Properties::getVec2));
mt.set_function("getVec3",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getVec3));
mt.set_function("getVec4",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getVec4));
mt.set_function("getQuaternionFromAxisAngle",static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Quaternion*)const>(&cocos2d::Properties::getQuaternionFromAxisAngle));
mt.set_function("getColor",sol::overload(static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec4*)const>(&cocos2d::Properties::getColor),static_cast<bool(cocos2d::Properties::*)(const char*,cocos2d::Vec3*)const>(&cocos2d::Properties::getColor)));
mt.set_function("getPath",static_cast<bool(cocos2d::Properties::*)(const char*,std::string*)const>(&cocos2d::Properties::getPath));
mt.set_function("getVariable",sol::overload([](cocos2d::Properties* obj,const char* arg0){return obj->getVariable(arg0);},[](cocos2d::Properties* obj,const char* arg0,const char* arg1){return obj->getVariable(arg0,arg1);}));
mt.set_function("setVariable",static_cast<void(cocos2d::Properties::*)(const char*,const char*)>(&cocos2d::Properties::setVariable));
mt.set_function("createNonRefCounted",static_cast<cocos2d::Properties*(*)(const std::string&)>(&cocos2d::Properties::createNonRefCounted));
mt.set_function("parseVec2",static_cast<bool(*)(const char*,cocos2d::Vec2*)>(&cocos2d::Properties::parseVec2));
mt.set_function("parseVec3",static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseVec3));
mt.set_function("parseVec4",static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseVec4));
mt.set_function("parseAxisAngle",static_cast<bool(*)(const char*,cocos2d::Quaternion*)>(&cocos2d::Properties::parseAxisAngle));
mt.set_function("parseColor",sol::overload(static_cast<bool(*)(const char*,cocos2d::Vec4*)>(&cocos2d::Properties::parseColor),static_cast<bool(*)(const char*,cocos2d::Vec3*)>(&cocos2d::Properties::parseColor)));
RegisterLuaCorePropertiesTypeAuto(lua);
}
void RegisterLuaCoreUserDefaultAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::UserDefault>("UserDefault",true);
ns["UserDefault"] = mt;
lua["UserDefault"] = sol::nil;
mt.set_function("getBoolForKey",sol::overload(static_cast<bool(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::getBoolForKey),static_cast<bool(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getBoolForKey)));
mt.set_function("getIntegerForKey",sol::overload(static_cast<int(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::getIntegerForKey),static_cast<int(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getIntegerForKey)));
mt.set_function("getLargeIntForKey",sol::overload(static_cast<int64_t(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::getLargeIntForKey),static_cast<int64_t(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getLargeIntForKey)));
mt.set_function("getFloatForKey",sol::overload(static_cast<float(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::getFloatForKey),static_cast<float(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getFloatForKey)));
mt.set_function("getDoubleForKey",sol::overload(static_cast<double(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::getDoubleForKey),static_cast<double(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getDoubleForKey)));
mt.set_function("getStringForKey",sol::overload(static_cast<std::string(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::getStringForKey),static_cast<std::string(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::getStringForKey)));
mt.set_function("setBoolForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,bool)>(&cocos2d::UserDefault::setBoolForKey));
mt.set_function("setIntegerForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int)>(&cocos2d::UserDefault::setIntegerForKey));
mt.set_function("setLargeIntForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,int64_t)>(&cocos2d::UserDefault::setLargeIntForKey));
mt.set_function("setFloatForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,float)>(&cocos2d::UserDefault::setFloatForKey));
mt.set_function("setDoubleForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,double)>(&cocos2d::UserDefault::setDoubleForKey));
mt.set_function("setStringForKey",static_cast<void(cocos2d::UserDefault::*)(const char*,const std::string&)>(&cocos2d::UserDefault::setStringForKey));
mt.set_function("flush",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::flush));
mt.set_function("deleteValueForKey",static_cast<void(cocos2d::UserDefault::*)(const char*)>(&cocos2d::UserDefault::deleteValueForKey));
mt.set_function("Clear",static_cast<void(cocos2d::UserDefault::*)()>(&cocos2d::UserDefault::Clear));
mt.set_function("setEncryptEnabled",static_cast<void(cocos2d::UserDefault::*)(bool,cxx17::string_view,cxx17::string_view)>(&cocos2d::UserDefault::setEncryptEnabled));
mt.set_function("encrypt",sol::overload(static_cast<void(cocos2d::UserDefault::*)(std::string&,int)>(&cocos2d::UserDefault::encrypt),static_cast<void(cocos2d::UserDefault::*)(char*,size_t,int)>(&cocos2d::UserDefault::encrypt)));
mt.set_function("getInstance",static_cast<cocos2d::UserDefault*(*)()>(&cocos2d::UserDefault::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::UserDefault::destroyInstance));
mt.set_function("setDelegate",static_cast<void(*)(cocos2d::UserDefault*)>(&cocos2d::UserDefault::setDelegate));
}
void RegisterLuaCoreFileUtilsStatusAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["FileUtils"];
pTable.new_enum("Status"
,"OK",0
,"NotExists",1
,"OpenFailed",2
,"ReadFailed",3
,"NotInitialized",4
,"TooLarge",5
,"ObtainSizeFailed",6
,"NotRegularFileType",7
);}
void RegisterLuaCoreFileUtilsAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::FileUtils>("FileUtils",true);
ns["FileUtils"] = mt;
lua["FileUtils"] = sol::nil;
mt.set_function("purgeCachedEntries",static_cast<void(cocos2d::FileUtils::*)()>(&cocos2d::FileUtils::purgeCachedEntries));
mt.set_function("getStringFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::string)>)const>(&cocos2d::FileUtils::getStringFromFile),static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getStringFromFile)));
mt.set_function("getDataFromFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (cocos2d::Data)>)const>(&cocos2d::FileUtils::getDataFromFile),static_cast<cocos2d::Data(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getDataFromFile)));
mt.set_function("getContents",static_cast<cocos2d::FileUtils::Status(cocos2d::FileUtils::*)(const std::string&,cocos2d::ResizableBuffer*)const>(&cocos2d::FileUtils::getContents));
mt.set_function("fullPathForFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::fullPathForFilename));
mt.set_function("loadFilenameLookup",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::loadFilenameLookupDictionaryFromFile));
mt.set_function("setFilenameLookupDictionary",static_cast<void(cocos2d::FileUtils::*)(const cocos2d::ValueMap&)>(&cocos2d::FileUtils::setFilenameLookupDictionary));
mt.set_function("fullPathFromRelativeFile",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::fullPathFromRelativeFile));
mt.set_function("setSearchResolutionsOrder",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchResolutionsOrder));
mt.set_function("addSearchResolutionsOrder",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchResolutionsOrder(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchResolutionsOrder(arg0,arg1);}));
mt.set_function("getSearchResolutionsOrder",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchResolutionsOrder));
mt.set_function("setSearchPaths",static_cast<void(cocos2d::FileUtils::*)(const std::vector<std::string>&)>(&cocos2d::FileUtils::setSearchPaths));
mt.set_function("getDefaultResourceRootPath",static_cast<const std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getDefaultResourceRootPath));
mt.set_function("setDefaultResourceRootPath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setDefaultResourceRootPath));
mt.set_function("addSearchPath",sol::overload([](cocos2d::FileUtils* obj,const std::string& arg0){return obj->addSearchPath(arg0);},[](cocos2d::FileUtils* obj,const std::string& arg0,const bool arg1){return obj->addSearchPath(arg0,arg1);}));
mt.set_function("getSearchPaths",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getSearchPaths));
mt.set_function("getOriginalSearchPaths",static_cast<const std::vector<std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getOriginalSearchPaths));
mt.set_function("getWritablePath",static_cast<std::string(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getWritablePath));
mt.set_function("setWritablePath",static_cast<void(cocos2d::FileUtils::*)(const std::string&)>(&cocos2d::FileUtils::setWritablePath));
mt.set_function("setPopupNotify",static_cast<void(cocos2d::FileUtils::*)(bool)>(&cocos2d::FileUtils::setPopupNotify));
mt.set_function("isPopupNotify",static_cast<bool(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::isPopupNotify));
mt.set_function("getValueMapFromFile",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueMapFromFile));
mt.set_function("getValueMapFromData",static_cast<cocos2d::ValueMap(cocos2d::FileUtils::*)(const char*,int)const>(&cocos2d::FileUtils::getValueMapFromData));
mt.set_function("writeToFile",static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeToFile));
mt.set_function("writeStringToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(std::string,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeStringToFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::writeStringToFile)));
mt.set_function("writeDataToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::Data,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeDataToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::Data&,const std::string&)const>(&cocos2d::FileUtils::writeDataToFile)));
mt.set_function("writeValueMapToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueMap,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueMapToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueMap&,const std::string&)const>(&cocos2d::FileUtils::writeValueMapToFile)));
mt.set_function("writeValueVectorToFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(cocos2d::ValueVector,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::writeValueVectorToFile),static_cast<bool(cocos2d::FileUtils::*)(const cocos2d::ValueVector&,const std::string&)const>(&cocos2d::FileUtils::writeValueVectorToFile)));
mt.set_function("getValueVectorFromFile",static_cast<cocos2d::ValueVector(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getValueVectorFromFile));
mt.set_function("isFileExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isFileExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExist)));
mt.set_function("getFileExtension",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileExtension));
mt.set_function("isAbsolutePath",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isAbsolutePath));
mt.set_function("isDirectoryExist",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::isDirectoryExist),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExist)));
mt.set_function("createDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::createDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::createDirectory)));
mt.set_function("removeDirectory",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeDirectory),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeDirectory)));
mt.set_function("removeFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::removeFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::removeFile)));
mt.set_function("renameFile",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<bool(cocos2d::FileUtils::*)(const std::string&,const std::string&)const>(&cocos2d::FileUtils::renameFile),static_cast<void(cocos2d::FileUtils::*)(const std::string&,const std::string&,std::function<void (bool)>)const>(&cocos2d::FileUtils::renameFile)));
mt.set_function("getFileSize",sol::overload(static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (long long)>)const>(&cocos2d::FileUtils::getFileSize),static_cast<int64_t(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getFileSize)));
mt.set_function("listFiles",static_cast<std::vector<std::string>(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::listFiles));
mt.set_function("listFilesAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesAsync));
mt.set_function("listFilesRecursively",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::vector<std::string>*)const>(&cocos2d::FileUtils::listFilesRecursively));
mt.set_function("listFilesRecursivelyAsync",static_cast<void(cocos2d::FileUtils::*)(const std::string&,std::function<void (std::vector<std::string>)>)const>(&cocos2d::FileUtils::listFilesRecursivelyAsync));
mt.set_function("getFullPathCache",static_cast<const std::unordered_map<std::string, std::string>(cocos2d::FileUtils::*)()const>(&cocos2d::FileUtils::getFullPathCache));
mt.set_function("getNewFilename",static_cast<std::string(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::getNewFilename));
mt.set_function("isFileExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isFileExistInternal));
mt.set_function("isDirectoryExistInternal",static_cast<bool(cocos2d::FileUtils::*)(const std::string&)const>(&cocos2d::FileUtils::isDirectoryExistInternal));
mt.set_function("getInstance",static_cast<cocos2d::FileUtils*(*)()>(&cocos2d::FileUtils::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::FileUtils::destroyInstance));
mt.set_function("setDelegate",static_cast<void(*)(cocos2d::FileUtils*)>(&cocos2d::FileUtils::setDelegate));
mt.set_function("writeBinaryToFile",static_cast<bool(*)(const void*,size_t,const std::string&)>(&cocos2d::FileUtils::writeBinaryToFile));
mt.set_function("getFileShortName",static_cast<std::string(*)(const std::string&)>(&cocos2d::FileUtils::getFileShortName));
RegisterLuaCoreFileUtilsStatusAuto(lua);
}
