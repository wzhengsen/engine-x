#pragma once
#include "lua.hpp"
/*
	cc::network::Downloader的另一种lua绑定，cocos原来的绑定由lua垃圾回收管理，
	可能引起不可预料的内存回收
	新的lua绑定重新设计了绑定函数函数，由于没有继承cc::Ref，将由手动回收
*/
void LuaRegisterDownloader(lua_State* L) noexcept;