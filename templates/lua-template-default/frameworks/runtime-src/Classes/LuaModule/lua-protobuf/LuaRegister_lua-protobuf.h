#pragma once

#include "lua.hpp"
extern "C" {
	LUALIB_API int luaopen_pb_conv(lua_State* L);
	LUALIB_API int luaopen_pb_buffer(lua_State* L);
	LUALIB_API int luaopen_pb_slice(lua_State* L);
	LUALIB_API int luaopen_pb(lua_State* L);
	LUALIB_API int luaopen_pb_io(lua_State* L);
	LUALIB_API int luaopen_pb_unsafe(lua_State* L); 
}

void LuaRegister_luaprotobuf(lua_State* L) noexcept;