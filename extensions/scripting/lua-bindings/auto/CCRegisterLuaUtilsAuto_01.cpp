#include "scripting/lua-bindings/auto/CCRegisterLuaUtilsAuto.hpp"
#include "base/ccUtils.h"
void RegisterLuaUtilsparseIntegerListAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccu"];
pTable["ParseIntegerList"] = static_cast<std::vector<int, std::allocator<int> >(*)(const std::string&)>(&cocos2d::utils::parseIntegerList);
}

void RegisterLuaUtilsBin2HexAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccu"];
pTable["Bin2Hex"] = [](const std::string& arg0,int arg1,bool arg2){return cocos2d::utils::bin2hex(arg0,arg1,arg2);},[](const std::string& arg0,int arg1){return cocos2d::utils::bin2hex(arg0,arg1);},[](const std::string& arg0){return cocos2d::utils::bin2hex(arg0);};
}

void RegisterLuaUtilskillCurrentProcessAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccu"];
pTable["KillCurrentProcess"] = static_cast<void(*)()>(&cocos2d::utils::killCurrentProcess);
}

void RegisterLuaUtilsConvertAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccu"];
pTable["Convert"] = [](const std::string_view& arg0,const std::string_view& arg1,const std::string_view& arg2,bool* arg3){return cocos2d::utils::Convert(arg0,arg1,arg2,arg3);},[](const std::string_view& arg0,const std::string_view& arg1,const std::string_view& arg2){return cocos2d::utils::Convert(arg0,arg1,arg2);};
}

void RegisterLuaUtilsGetClipboardAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccu"];
pTable["GetClipboard"] = static_cast<std::string(*)()>(&cocos2d::utils::GetClipboard);
}

void RegisterLuaUtilsSetClipboardAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccu"];
pTable["SetClipboard"] = static_cast<void(*)(const char*)>(&cocos2d::utils::SetClipboard);
}

