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
#include <map>
#include "sol/sol.hpp"
#include "CCLuaObject.h"
#include "platform/CCPlatformMacros.h"

template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::LuaObject, T>::value>::type>
int sol_lua_push(lua_State* L, T* obj) {
    if (nullptr == obj) {
        return 0;
    }
    int luaRef = obj->GetLuaRef();
    bool udExist =
        (luaRef != cocos2d::LuaObject::LuaNoRef) &&
        (LUA_TTABLE == lua_getfield(L, LUA_REGISTRYINDEX, "SolWrapper.UD"));// table?

    if (udExist) {
        // Try to get exist userdata from registry["SolWrapper.UD"].
        udExist = LUA_TUSERDATA == lua_rawgeti(L, 1, obj->GetLuaRef()); // table,userdata?
    }
    if (!udExist) {
        lua_settop(L, 0);
        // New userdata.
        *static_cast<const T**>(lua_newuserdata(L, sizeof(const T*))) = obj;// ud

        // Make sure the registry["SolWrapper.UD"] is a table.
        if (LUA_TTABLE != lua_getfield(L, LUA_REGISTRYINDEX, "SolWrapper.UD")) {// ud,table?
            lua_pop(L, 1);// ud
            lua_newtable(L);// ud,table
            lua_pushvalue(L, -1);// ud,table,table
            lua_setfield(L, LUA_REGISTRYINDEX, "SolWrapper.UD");// ud,table
        }

        // Save lua ref into LuaObject.
        lua_pushvalue(L, 1);// ud,table,ud
        obj->SetLuaRef(luaL_ref(L, -2));//ud,table
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

template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::LuaObject, T>::value>::type>
int sol_lua_push(lua_State* L, const T* obj) {
    return sol_lua_push(L, const_cast<T*>(obj));
}

namespace cocos2d {
    class CC_DLL Lua : public sol::state {
    public:
        static Lua* GetInstance();
        static void Close();

        template<typename U, typename ...B>
        static sol::usertype<U> NewUserType(sol::table& t, const std::string& name) {
            auto ut = t.new_usertype<U>(name,
                sol::base_classes, sol::bases<B...>(),
                sol::meta_function::new_index, [](lua_State* L) {
                if (LUA_TTABLE == lua_getuservalue(L, 1)) {//ud,k,v,table
                    lua_insert(L, -3);//ud,table,k,v
                    lua_rawset(L, -3);//ud,table
                }
                return 0;
            },
                sol::meta_function::index, [](lua_State* L) {
                if (LUA_TTABLE == lua_getuservalue(L, 1)) {//ud,k,table
                    lua_insert(L, -2);//ud,table,k
                    lua_rawget(L, -2);//ud,table,v
                    return 1;
                }
                return 0;
            },
                sol::meta_function::pairs, [](lua_State* L) {
                lua_pushcfunction(L, [](lua_State* l) {
                    if (LUA_TTABLE == lua_getuservalue(l, 1)) {//ud,k,table
                        lua_insert(l, -2);//ud,table,k
                        if (lua_next(l, -2) != 0) {
                            //ud,table,nextK,nextV
                            return 2;
                        }
                    }
                    return 0;
                });// userdata,function
                lua_pushvalue(L, 1);// userdata,function,userdata
                lua_pushnil(L);// userdata,function,userdata,nil
                return 3;
            });
            ut["mtor"] = [ut](const std::string& name, const sol::function& method) mutable {
                auto iter = MethodToSolMap.find(name);
                if (iter == MethodToSolMap.cend()) {
                    auto L = ut.lua_state();
                    luaL_error(L, "Unsupported %s metamethod!", name.c_str());
                    return;
                }
                ut[iter->second] = method;
            };
            ut["stor"] = [ut](const sol::table& stor) mutable {
                stor.for_each([ut](const sol::object& o1, const sol::object& o2) mutable {
                    sol::function f = o2.as<sol::function>();
                    ut[o1.as<std::string>()] = sol::writeonly_property([f](U* self, sol::object& v) {
                        f(self, v);
                    });
                });
            };
            ut["gtor"] = [ut](const sol::table& gtor) mutable {
                gtor.for_each([ut](const sol::object& o1, const sol::object& o2) mutable {
                    sol::function f = o2.as<sol::function>();
                    ut[o1.as<std::string>()] = sol::readonly_property([f](U* self) {
                        return f(self);
                    });
                });
            };
            return ut;
        }

        void UnRefUserData(int ref);
    protected:
        using sol::state::state;
        inline static Lua* lua = nullptr;
        inline static const std::map<std::string, sol::meta_function> MethodToSolMap = {
            {"__index",sol::meta_function::index},
            {"__newindex",sol::meta_function::new_index},
            {"__gc",sol::meta_function::garbage_collect},
            {"__mode",sol::meta_function::mode},
            {"__len",sol::meta_function::length},
            {"__eq",sol::meta_function::equal_to},
            {"__add",sol::meta_function::addition},
            {"__sub",sol::meta_function::subtraction},
            {"__mul",sol::meta_function::multiplication},
            {"__mod",sol::meta_function::modulus},
            {"__pow",sol::meta_function::power_of},
            {"__div",sol::meta_function::division},
            {"__idiv",sol::meta_function::floor_division},
            {"__band",sol::meta_function::bitwise_and},
            {"__bor",sol::meta_function::bitwise_or},
            {"__bxor",sol::meta_function::bitwise_xor},
            {"__shl",sol::meta_function::bitwise_left_shift},
            {"__shr",sol::meta_function::bitwise_right_shift},
            {"__unm",sol::meta_function::unary_minus},
            {"__bnot",sol::meta_function::bitwise_not},
            {"__lt",sol::meta_function::less_than},
            {"__le",sol::meta_function::less_than_or_equal_to},
            {"__concat",sol::meta_function::concatenation},
            {"__call",sol::meta_function::call},
            {"__tostring",sol::meta_function::to_string},
            {"__pairs",sol::meta_function::pairs},
            {"__metatable",sol::meta_function::metatable}
        };
    };
} // namespace cocos2d