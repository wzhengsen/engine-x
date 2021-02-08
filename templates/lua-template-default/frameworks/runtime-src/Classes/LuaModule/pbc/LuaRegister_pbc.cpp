#include "pbc/LuaRegister_pbc.h"

void LuaRegister_pbc(lua_State* L) noexcept {
	static luaL_Reg reg[] = {
		{"protobuf.c", luaopen_protobuf_c},
	};
	lua_getglobal(L, "package");
	lua_getfield(L, -1, "preload");
	for (const auto v : reg) {
		lua_pushcfunction(L, v.func);
		lua_setfield(L, -2, v.name);
	}
	lua_pop(L, 2);
}