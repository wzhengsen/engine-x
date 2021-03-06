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

namespace cocos2d {
    namespace extension {
        /**
        * @brief Simply wrapped sol::state type, all cocos lua operations are centralized to this class.
        */
        class CC_DLL Lua : public sol::state {
        public:
            /**
            * @brief    Get lua instance.
            *           Will create a new sol::state as lua state on first call or after called Lua::Close().
            *           The lua stack will keep alive utill call Lua::Close().
            * @return   cocos2d::Lua*
            */
            static Lua* GetInstance();

            /**
            * @brief    Close the opened lua instance.
            */
            static void Close();

            /** ConfigType enum. */
            /* For compatibility. */
            enum class ConfigType {
                NONE,
                COCOSTUDIO
            };


            template<typename U, typename ...B>
            sol::usertype<U> NewUserType(const std::string& name, bool no_ctor = false) {
                auto ut = no_ctor ?
                    new_usertype<U>(name, sol::no_constructor, sol::base_classes, sol::bases<B...>()) :
                    new_usertype<U>(name, sol::base_classes, sol::bases<B...>());
                ut[sol::meta_function::new_index] = [](lua_State* L) {
                    if (LUA_TTABLE == lua_getuservalue(L, 1)) {//ud,k,v,table
                        lua_insert(L, -3);//ud,table,k,v
                        lua_rawset(L, -3);//ud,table
                    }
                    return 0;
                };
                ut[sol::meta_function::index] = [](lua_State* L) {
                    if (LUA_TTABLE == lua_getuservalue(L, 1)) {//ud,k,table
                        lua_insert(L, -2);//ud,table,k
                        lua_rawget(L, -2);//ud,table,v
                        return 1;
                    }
                    return 0;
                };
                ut[sol::meta_function::pairs] = [](lua_State* L) {
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
                };
                // Provides a way to register a meta-method in lua.
                ut["mtor"] = [ut](const std::string& name, const sol::function& method) mutable {
                    auto iter = MethodToSolMap.find(name);
                    if (iter == MethodToSolMap.cend()) {
                        auto L = ut.lua_state();
                        luaL_error(L, "Unsupported %s metamethod!", name.c_str());
                        return;
                    }
                    ut[iter->second] = method;
                };
                // Provides a way to register property in lua.
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
            /**
            * @brief    A wrapper of sol::table::new_usertype.
            *           The __newindex/__index/__pairs meta-method has been registered in advance.
            * @param    U The class or struct which want to be register into lua table.
            * @param    B All of base class of U,such as base's base,and so on.
            * @param    tName The name of the table in which the type being registered is located,split by ".".
            * @param    name The class name in lua.
            * @param    no_ctor default = false,means no "new" method.
            * @return   You can use it to register your own member-method or meta-method.
            */
            template<typename U, typename ...B>
            sol::usertype<U> NewUserType(const std::string& tName, const std::string& name, bool no_ctor = false) {
                std::vector<std::string> vecNS = {};
                size_t pos = 0;
                size_t begin = 0;
                while (true) {
                    pos = tName.find(".", pos);
                    if (pos == std::string::npos) {
                        vecNS.emplace_back(tName.substr(begin));
                        break;
                    }
                    vecNS.emplace_back(tName.substr(begin, pos - begin));
                    begin = ++pos;
                };
                sol::table nsTable = (*this)["_G"];
                for (const auto& ns : vecNS) {
                    sol::object nsObj = nsTable[ns];
                    if (!nsObj.valid()) {
                        nsTable = nsTable.create_named(ns);
                        continue;
                    }
                    nsTable = nsObj.as<sol::table>();
                }
                auto mt = NewUserType<U, B...>(name, no_ctor);
                nsTable[name] = mt;
                set(name, sol::nil);
                return mt;
            }

            /**
            * @brief    This method should be called when a c++ instance registered in lua is destroyed.
            *           This method releases the userdata bound to the c++ instance pointer from the registry["SolWrapper.UD"] and points the userdata to the nullptr.
            * @param    obj Any c++ pointer.
            */
            void ReleaseInLua(void* obj);
            inline static constexpr char UserDataKey[] = "Lua.UD?";
        protected:
            virtual void Init();
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
        private:
            void Register();
            void RegisterSol();
            void RegisterAuto();
            void RegisterManual();
        };
    }// namespace cocos2d::extension
} // namespace cocos2d