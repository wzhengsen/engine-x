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
#include <vector>
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
                    lua_pushnil(L);
                    return 1;
                };
                // Provides a way to register property in lua.
                ut["__properties__"] = sol::writeonly_property([ut](const sol::table& properties) mutable {
                    std::map<std::string, gsPair<U>> pMap = {};
                    // For "r" key(read).
                    GS_Pair<true>(properties["r"], rObj);
                    // For "w" key(write).
                    GS_Pair<false>(properties["w"], wObj);
                    for (auto& gs : pMap) {
                        const auto& funcs = gs.second;
                        if (funcs.first && funcs.second) {
                            ut[gs.first] = sol::property(funcs.first, funcs.second);
                        }
                        else if (funcs.first) {
                            ut[gs.first] = sol::readonly_property(funcs.first);
                        }
                        else if (funcs.second) {
                            ut[gs.first] = sol::writeonly_property(funcs.second);
                        }
                    }
                });
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
                auto ut = NewUserType<U, B...>(name, no_ctor);
                nsTable[name] = ut;
                set(name, sol::nil);
                return ut;
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
            inline static const std::vector<std::pair<const char*, sol::meta_function>> MethodToSol = {
                // Don't use __index and __newindex metamethod,used for NewUserType already.
                // {"__index__",sol::meta_function::index},
                // {"__newindex__",sol::meta_function::new_index},
                {"__gc__",sol::meta_function::garbage_collect},
                {"__mode__",sol::meta_function::mode},
                {"__len__",sol::meta_function::length},
                {"__eq__",sol::meta_function::equal_to},
                {"__add__",sol::meta_function::addition},
                {"__sub__",sol::meta_function::subtraction},
                {"__mul__",sol::meta_function::multiplication},
                {"__mod__",sol::meta_function::modulus},
                {"__pow__",sol::meta_function::power_of},
                {"__div__",sol::meta_function::division},
                {"__idiv__",sol::meta_function::floor_division},
                {"__band__",sol::meta_function::bitwise_and},
                {"__bor__",sol::meta_function::bitwise_or},
                {"__bxor__",sol::meta_function::bitwise_xor},
                {"__shl__",sol::meta_function::bitwise_left_shift},
                {"__shr__",sol::meta_function::bitwise_right_shift},
                {"__unm__",sol::meta_function::unary_minus},
                {"__bnot__",sol::meta_function::bitwise_not},
                {"__lt__",sol::meta_function::less_than},
                {"__le__",sol::meta_function::less_than_or_equal_to},
                {"__concat__",sol::meta_function::concatenation},
                {"__call__",sol::meta_function::call},
                {"__tostring__",sol::meta_function::to_string},
                {"__pairs__",sol::meta_function::pairs},
                {"__metatable__",sol::meta_function::metatable}
            };
        private:
            void Register();
            void RegisterSol();
            void RegisterAuto();
            void RegisterManual();

            template<typename U>
            using gsPair = std::pair<std::function<sol::object(const U*)>, std::function<void(const U*, const sol::object&)>>;
            template<bool isGetter, typename U>
            static void GS_Pair(std::map<std::string, gsPair<U>>& pMap, const sol::object& solObj) {
                if (sol::type::table == solObj.get_type()) {
                    sol::table table = solObj;
                    table.for_each([&pMap](const sol::object& key, const sol::object& val) {
                        if (sol::type::string == key.get_type() && sol::type::function == val.get_type()) {
                            const std::string sKey = key.as<std::string>();
                            if (pMap.cend() == pMap.find(sKey)) {
                                pMap.emplace(sKey, std::pair{ nullptr,nullptr });
                            }
                            auto& pair = pMap[sKey];
                            if constexpr (isGetter) {
                                auto func = val.as<std::function<sol::object(const U*)>>();
                                pair.first = func;
                            }
                            else {
                                auto func = val.as<std::function<void(const U*, const sol::object&)>>();
                                pair.second = func;
                            }
                        }
                    });
                }
            }
        };
    }// namespace cocos2d::extension
} // namespace cocos2d