#include "LuaRegister_cjson.h"
extern "C" {
#include "lua_cjson.h"
}
#include "OO_Lua/OO_Lua.hpp"
using namespace OO_Lua;

void LuaRegister_cjson(lua_State* L) noexcept{
	const static Lua::KVPair<const char*,Lua::CFunction> reg[] = {
		{"cjson", luaopen_cjson_safe}
	};

	const auto lua = Lua(L);
	lua.GetGlobal("package");
	lua.GetField(-1, "preload");
	lua.SetPairs(-1, reg);
	lua.Pop(2);
}