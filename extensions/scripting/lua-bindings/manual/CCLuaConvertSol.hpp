/****************************************************************************
 Copyright (c) wzhengsen

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#pragma once
#include "scripting/lua-bindings/CCLua.h"

 /**
  * @brief       Any class which base of cocos2d::LuaObject will trigger this function when it be pushed into lua stack.
  *              Shound not be called by manual.
  */
template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::LuaObject, T>::value>::type>
int sol_lua_push(lua_State* L, const T* obj) {
    if (nullptr == obj) {
        return 0;
    }
    bool udExist = LUA_TTABLE == lua_getfield(L, LUA_REGISTRYINDEX, cocos2d::Lua::UserDataKey);// table?

    if (udExist) {
        // Try to get exist userdata from registry["SolWrapper.UD"].
        lua_pushlightuserdata(L, const_cast<T*>(obj));// table,light_ud
        udExist = LUA_TUSERDATA == lua_rawget(L, 1); // table,userdata?
    }
    if (!udExist) {
        lua_settop(L, 0);
        // New userdata.
        *static_cast<const T**>(lua_newuserdata(L, sizeof(const T*))) = obj;// ud

        // Make sure the registry["SolWrapper.UD"] is a table.
        if (LUA_TTABLE != lua_getfield(L, LUA_REGISTRYINDEX, cocos2d::Lua::UserDataKey)) {// ud,table?
            lua_pop(L, 1);// ud
            lua_newtable(L);// ud,table
            lua_pushvalue(L, -1);// ud,table,table
            lua_setfield(L, LUA_REGISTRYINDEX, cocos2d::Lua::UserDataKey);// ud,table
        }

        // Save object into registry["SolWrapper.UD"] with light_ud pointer as key.
        lua_pushlightuserdata(L, const_cast<T*>(obj));// ud,table,light_ud
        lua_pushvalue(L, -3);// ud,table,light_ud,ud
        lua_rawset(L, -3);// ud,table
        lua_pop(L, 1);//ud

        // Set uservalue for this userdata with a table.
        lua_newtable(L);// ud,table
        lua_setuservalue(L, -2);// ud

        // Set metatable for this userdata.
        if (luaL_getmetatable(L, sol::usertype_traits<T*>::metatable().c_str())) {// ud,mt?
            lua_setmetatable(L, -2);// ud
        }
        else {
            lua_pop(L, 1);// ud
        }
    }
    return 1;
}