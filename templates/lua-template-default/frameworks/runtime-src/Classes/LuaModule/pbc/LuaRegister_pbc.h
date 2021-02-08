#pragma once
#include "lua.hpp"
#ifdef __cplusplus
extern "C" {
#endif
    int luaopen_protobuf_c(lua_State* L);
#ifdef __cplusplus
}
#endif

void LuaRegister_pbc(lua_State* L) noexcept;