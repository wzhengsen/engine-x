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
#define SOL_PRINT_ERRORS 1
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

            /**
            * @brief    This is the mapping from typeid to metaname.
            *           It is used to convert to real type when base class pointer is pushed into lua.
            */
            inline static std::unordered_map<std::string, std::string> Id2Meta = {};

            /** ConfigType enum. */
            /* For compatibility. */
            enum class ConfigType {
                NONE,
                COCOSTUDIO
            };

            sol::function NewClass = sol::nil;
            sol::function NewEnum = sol::nil;
            sol::table OOPConfig = sol::nil;

            /**
            * @brief    This method should be called when a c++ instance registered in lua is destroyed.
            *           This method releases the userdata bound to the c++ instance pointer from the registry[UserDataKey] and points the userdata to the nullptr.
            * @param    obj Any c++ pointer.
            */
            void ReleaseInLua(void* obj);
            inline static constexpr char UserDataKey[] = { 'U','D',char(240),char(159),char(140),char(153) };
        protected:
            virtual void Init();
            using sol::state::state;
            inline static Lua* lua = nullptr;
        private:
            /**
            * @breif    Use LuaOOP and sol to provide object orientation in Lua.
            * @return   If there is no LuaOOP module,
            *           false is returned and no subsequent registrations will be completed.
            */
            bool RequireLuaOOP();
            void Register();
            void RegisterSol();
            void RegisterAuto();
            void RegisterManual();
        };
    }// namespace cocos2d::extension
} // namespace cocos2d