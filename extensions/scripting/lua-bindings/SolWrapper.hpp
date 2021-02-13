#pragma once
#include <tuple>
#include "cocos2d.h"
#include "sol/sol.hpp"

namespace cocos2d {
    class SolWrapper {
    public:
        template<typename U, typename ...B>
        static sol::usertype<U> NewUserType(sol::table& t, const std::string& name) {
            auto ut = t.new_usertype<U>(name);
            ut[sol::base_classes] = sol::bases<B...>();
            ut[sol::meta_function::new_index] = [](lua_State* L) {
                GetUserdataBindTable(L, 1);//ud,k,v,table
                lua_insert(L, -3);//ud,table,k,v
                lua_rawset(L, -3);//ud,table
                return 0;
            };
            ut[sol::meta_function::index] = [](lua_State* L) {
                GetUserdataBindTable(L, 1);//ud,k,table
                lua_insert(L, -2);//ud,table,k
                lua_rawget(L, -2);//ud,table,v
                return 1;
            };
            ut["mtor"] = [ut](const std::string& name, const sol::function& method) mutable {
                auto iter = MethodToSolMap.find(name);
                if (iter == MethodToSolMap.cend()) {
                    auto L = ut.lua_state();
                    luaL_error(L, "No matched metamethod!");
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
            ut[sol::meta_function::pairs] = [](lua_State* L) {
                lua_pushcfunction(L, [](lua_State* l)->int {
                    GetUserdataBindTable(l, 1);//ud,k,table
                    lua_insert(l, -2);//ud,table,k
                    if (lua_next(l, -2) != 0) {
                        //ud,table,nextK,nextV
                        return 2;
                    }
                    return 0;
                });
                return 1;
            };
            return ut;
        }
    private:
        // @brief:Push userdata binded table to stack top,the userdata located at 'idx'.
        static void GetUserdataBindTable(lua_State* L, int idx) {
            if (lua_getuservalue(L, idx) == LUA_TTABLE) {//...ud...table
                return;
            }
            lua_pop(L, 1);//...ud...
            void* lud = *((void**)lua_touserdata(L, idx));//...ud...
            if (lua_getfield(L, LUA_REGISTRYINDEX, "__valueTables") != LUA_TTABLE) {//...ud...__valueTables
                lua_pop(L, 1);//...ud...
                lua_newtable(L);//...ud...__valueTables
                lua_pushvalue(L, -1);//...ud...__valueTables,__valueTables
                lua_setfield(L, LUA_REGISTRYINDEX, "__valueTables");//...ud...__valueTables
                // lua_createtable(L, 0, 1);//...ud...__valueTables,metatable
                // lua_pushliteral(L, "v");//...ud...__valueTables,metatable,"v"
                // lua_setfield(L, -2, "__mode");//...ud...__valueTables,metatable
                // lua_setmetatable(L, -2);//...ud...__valueTables
            }
            lua_pushlightuserdata(L, lud);//...ud...__valueTables,light_ud
            lua_pushvalue(L, -1);//...ud...__valueTables,light_ud,light_ud
            if (lua_rawget(L, -3) != LUA_TTABLE) {//...ud...__valueTables,light_ud,table
                lua_pop(L, 1);//...ud...__valueTables,light_ud
                lua_newtable(L);//...ud...__valueTables,light_ud,table
                lua_pushvalue(L, -1);//...ud...__valueTables,light_ud,table,
                lua_insert(L, -4);//...ud...table,__valueTables,light_ud,table
                lua_rawset(L, -3);//...ud...table,__valueTables
                lua_pop(L, 1);//...ud...table
            }
            else {
                lua_insert(L, -3);//...ud...table,__valueTables,light_ud
                lua_pop(L, 2);//...ud...table
            }
            lua_pushvalue(L, -1);//...ud...table,table
            lua_setuservalue(L, idx);//...ud...table
        }
        SolWrapper() = delete;
        SolWrapper(const SolWrapper&) = delete;
        SolWrapper& operator=(const SolWrapper&) = delete;
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
};