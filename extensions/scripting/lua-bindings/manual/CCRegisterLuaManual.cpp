#include "CCRegisterLuaManual.h"
// lua socket.
#if __cplusplus
extern "C" {
#endif
#include "luasocket/luasocket.h"
#include "luasocket/luasocket_scripts.h"
#include "luasocket/mime.h"
#if __cplusplus
} // extern "C"
#endif

using namespace cocos2d;

void ReigsterLuaSocketManual(Lua& lua) {
    static constexpr luaL_Reg luax_exts[] = {
    {"socket.core", luaopen_socket_core},
    {"mime.core", luaopen_mime_core}
    };
    sol::table preload = lua["package"]["preload"];
    for (auto& iter : luax_exts) {
        preload[iter.name] = iter.func;
    }

    luaopen_luasocket_scripts(lua.lua_state());
}

void RegisterLuaManual(Lua& lua) {
    ReigsterLuaSocketManual(lua);
}