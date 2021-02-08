#include "lua-protobuf/LuaRegister_lua-protobuf.h"

void LuaRegister_luaprotobuf(lua_State* L) noexcept {
	static luaL_Reg reg[] = {
		{"pb", luaopen_pb},
		{"pb.io", luaopen_pb_io},
		{"pb.conv", luaopen_pb_conv},
		{"pb.slice", luaopen_pb_slice},
		{"pb.buffer", luaopen_pb_buffer},
		{"pb.unsafe", luaopen_pb_unsafe}
	};
	lua_getglobal(L, "package");
	lua_getfield(L, -1, "preload");
	for (const auto v : reg) {
		lua_pushcfunction(L, v.func);
		lua_setfield(L, -2, v.name);
	}
	lua_pop(L, 2);
}