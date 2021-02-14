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

#include "Lua.h"
namespace cocos2d {
    Lua* Lua::GetInstance() {
        if (!lua) {
            lua = new Lua();
        }
        return lua;
    }

    void Lua::Close() {
        delete lua;
        lua = nullptr;
    }

    void Lua::UnRefUserData(int ref) {
        if (LuaObject::LuaNoRef == ref) {
            return;
        }

        // Get lua_State*.
        auto l = GetInstance()->lua_state();// ...
        // Get registry["SolWrapper.UD"] as a table.
        if (LUA_TTABLE == lua_getfield(l, LUA_REGISTRYINDEX, "SolWrapper.UD")) {// ...table?
            luaL_unref(l, -1, ref);// ...table
        }
        // Keep lua stack.
        lua_pop(l, 1);// ...
    }
};