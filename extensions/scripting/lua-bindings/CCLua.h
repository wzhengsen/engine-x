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
            sol::usertype<U> NewUserType(const std::string& name, bool noCtor = false) {
                auto ut = noCtor ?
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
                ut[sol::meta_function::garbage_collect] = [](const sol::userdata& ud) {
                    sol::object __gc = ud["__gc__"];
                    // Force the non-nil value to be recognized as a function and throw an error early.
                    if (sol::type::nil != __gc.get_type()) {
                        __gc.as<sol::function>()(ud);
                    }
                };
                ut[sol::meta_function::equal_to] = [](const sol::userdata& ud1, const sol::userdata& ud2)->bool {
                    for (const auto& ud : { ud1,ud2 }) {
                        sol::object __eq = ud["__eq__"];
                        // Force the non-nil value to be recognized as a function and throw an error early.
                        if (sol::type::nil != __eq.get_type()) {
                            return __eq.as<sol::function>()(ud1, ud2);
                        }
                    }
                    return false;
                };
                // Provides a way to register meta-method in lua.
                // You can implement __metaname__ on a usertype or it's bases.
                for (const auto& meta : MetaNeedImpl) {
                    ut[meta.second] = [&meta](const sol::userdata ud, const sol::variadic_args& args) {
                        sol::object __meta = ud[meta.first];
                        if (sol::type::function == __meta.get_type()) {
                            return __meta.as<sol::function>()(ud, args);
                        }
                        throw sol::error(sol::detail::direct_error, "You must implement the " + std::string(meta.first) + " meta-method.");
                    };
                }
                // Provides a way to register property in lua.
                ut["__properties__"] = sol::writeonly_property([ut](sol::object properties) mutable {
                    if (sol::type::function == properties.get_type()) {
                        properties = properties.as<sol::function>()(ut);
                    }
                    SetProperties(ut, properties.as<sol::table>());
                });
                return ut;
            }
            /**
            * @brief    A wrapper of sol::table::new_usertype.
            *           The __newindex/__index meta-method has been registered in advance.
            * @param    U The class or struct which want to be register into lua table.
            * @param    B All of base class of U,such as base's base,and so on.
            * @param    tName The name of the table in which the type being registered is located,split by ".".
            * @param    name The class name in lua.
            * @param    noCtor default = false,means no "new" method.
            * @return   You can use it to register your own member-method or meta-method.
            */
            template<typename U, typename ...B>
            sol::usertype<U> NewUserType(const std::string& tName, const std::string& name, bool noCtor = false) {
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
                auto ut = NewUserType<U, B...>(name, noCtor);
                nsTable[name] = ut;
                set(name, sol::nil);
                return ut;
            }

            /**
            * @brief    This method should be called when a c++ instance registered in lua is destroyed.
            *           This method releases the userdata bound to the c++ instance pointer from the registry[UserDataKey] and points the userdata to the nullptr.
            * @param    obj Any c++ pointer.
            */
            void ReleaseInLua(void* obj);
            inline static constexpr char UserDataKey[] = "Lua.UD?";
        protected:
            virtual void Init();
            using sol::state::state;
            inline static Lua* lua = nullptr;
            inline static const std::vector<std::pair<const char*, sol::meta_function>> MetaNeedImpl = {
                {"__len__",sol::meta_function::length},
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
                {"__pairs__",sol::meta_function::pairs}
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
                    solObj.as<sol::table>().for_each([&pMap](const sol::object& key, const sol::object& val) {
                        const std::string sKey = key.as<std::string>();
                        if (pMap.cend() == pMap.find(sKey)) {
                            pMap.emplace(sKey, std::pair{ nullptr,nullptr });
                        }
                        auto& pair = pMap[sKey];
                        if constexpr (isGetter) {
                            pair.first = val.as<std::function<sol::object(const U*)>>();
                        }
                        else {
                            pair.second = val.as<std::function<void(const U*, const sol::object&)>>();
                        }
                    });
                }
            }

            template<typename U>
            static void SetProperties(sol::usertype<U>& ut, const sol::table& properties) {
                std::map<std::string, gsPair<U>> pMap = {};
                // For "r" key(read).
                GS_Pair<true>(pMap, properties["r"]);
                // For "w" key(write).
                GS_Pair<false>(pMap, properties["w"]);
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
            }
        };
    }// namespace cocos2d::extension
} // namespace cocos2d