#include "cocos2d.h"
#include "ExtLib/LuaRegisterExtLib.h"
#include "OO_Lua/OO_Lua.hpp"
#if _WIN32
#include "iconv.h"
#else
#include <iconv.h>
#if ANDROID || __ANDROID__
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
static const std::string helperClassName = "org.cocos2dx.lib.Cocos2dxHelper";
#endif
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || _WIN32)
#include "glfw3.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
extern int Lua_os_GetClipboard(lua_State* L);
extern int Lua_os_SetClipboard(lua_State* L);
#endif

using namespace OO_Lua;

#if ANDROID || __ANDROID__
static int Lua_os_GetClipboard(lua_State* L) {
    const auto lua = Lua(L);
    lua.Push(cocos2d::JniHelper::callStaticStringMethod(helperClassName, "GetClipboard"));
    return 1;
}
static int Lua_os_SetClipboard(lua_State* L) {
    const auto lua = Lua(L);
    cocos2d::JniHelper::callStaticVoidMethod(helperClassName, "SetClipboard",lua.CheckString(1));
    return 0;
}
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || _WIN32)
static int Lua_os_GetClipboard(lua_State* L) {
    const char* c = glfwGetClipboardString(nullptr);
    Lua(L).Push(c ? c : "");
    return 1;
}
static int Lua_os_SetClipboard(lua_State* L) {
    glfwSetClipboardString(nullptr,Lua(L).CheckString(1));
    return 0;
}
#endif

static int Lua_string_Convert(lua_State* L) {
    const auto lua = Lua(L);
    const char* to = lua.CheckString(2);
    const char* from = lua.CheckString(3);
    auto i = iconv_open(to,from);
    if (i == (iconv_t)-1){
        // Can't convert.
        lua.Push();
        return 1;
    }
    size_t strLen = 0;
    const char* str = lua.CheckString(1,strLen);
    auto b = Lua::Buffer();
    size_t cvtLen = strLen * 4;
    char* buffer = lua.BufferInitSize(&b,strLen * 4);

    size_t cvtLeft = cvtLen;
    const auto cvCount = iconv(i,const_cast<char**>(&str),&strLen,&buffer,&cvtLeft);
    iconv_close(i);
    if (cvCount == static_cast<size_t>(-1)){
        lua.Push();
        return 1;
    }
    OO_Lua::Lua::PushResultSize(&b,cvtLen - cvtLeft);
    return 1;
}

void LuaRegisterExtLib(lua_State* L) noexcept {
    const auto lua = Lua(L);
    static Lua::KVPair<const char*, Lua::CFunction> regOSKV[] = {
    {"SetClipboard", Lua_os_SetClipboard},
    {"GetClipboard", Lua_os_GetClipboard}
    };

    lua.GetGlobal("os");
    lua.SetPairs(-1, regOSKV);
    lua.Pop(1);

    static Lua::KVPair<const char*, Lua::CFunction> regStrKV[] = {
    {"Convert", Lua_string_Convert}
    };

    lua.GetGlobal("string");
    lua.SetPairs(-1, regStrKV);
    lua.Pop(1);
}
