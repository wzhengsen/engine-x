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

#include "CCLua.h"
#include "base/CCData.h"
#include "platform/CCFileUtils.h"
#include "auto/lua_cocos2dx_auto.hpp"
#include "auto/lua_cocos2dx_3d_auto.hpp"
#include "auto/lua_cocos2dx_audioengine_auto.hpp"
#include "auto/lua_cocos2dx_backend_auto.hpp"
#include "auto/lua_cocos2dx_controller_auto.hpp"
#include "auto/lua_cocos2dx_csloader_auto.hpp"
#include "auto/lua_cocos2dx_extension_auto.hpp"
#include "auto/lua_cocos2dx_navmesh_auto.hpp"
#include "auto/lua_cocos2dx_physics3d_auto.hpp"
#include "auto/lua_cocos2dx_spine_auto.hpp"
#include "auto/lua_cocos2dx_studio_auto.hpp"
#include "auto/lua_cocos2dx_ui_auto.hpp"
#include "auto/lua_cocos2dx_video_auto.hpp"
#include "auto/lua_cocos2dx_webview_auto.hpp"

using namespace cocos2d;
namespace cocos2d {
    Lua* Lua::GetInstance() {
        if (!lua) {
            lua = new Lua();
            lua->Init();
        }
        return lua;
    }

    void Lua::Init() {
        open_libraries();
        add_package_loader([this](const std::string& fileName) {
            static const std::string ExtLuaC = ".luac";
            static const std::string ExtLua = ".lua";
            std::string searchName = fileName;
            std::string searchPath = (*lua)["package"]["path"];
            Data chunk = {};
            std::string chunkName = {};
            FileUtils* utils = FileUtils::getInstance();

            size_t pos = 0;
            for (const std::string& ext : { ExtLuaC,ExtLua }) {
                pos = searchName.rfind(ext);
                if (pos != std::string::npos && pos == searchName.length() - ext.length()) {
                    // searchName ignore end with ".lua" or ".luac".
                    searchName = searchName.substr(0, pos);
                    break;
                }
            }

            while (std::string::npos != (pos = searchName.find_first_of('.'))) {
                // searchName replace . by /
                searchName.replace(pos, 1, "/");
            }

            // search file in package.path
            size_t begin = 0;
            size_t next = 0;

            while (std::string::npos != (next = searchPath.find_first_of(';', begin))) {
                std::string prefix = searchPath.substr(begin, next - begin);
                if (prefix[0] == '.' && prefix[1] == '/') {
                    // prefix skip start with "./".
                    prefix = prefix.substr(2);
                }
                for (const std::string& ext : { ExtLuaC,ExtLua }) {
                    pos = prefix.rfind(ext);
                    if (pos != std::string::npos && pos == prefix.length() - ext.length()) {
                        // prefix ignore end with ".lua" or ".luac".
                        prefix = prefix.substr(0, pos);
                        break;
                    }
                }

                // prefix replace ? by searchName.
                pos = prefix.find_first_of('?', 0);
                while (pos != std::string::npos) {
                    prefix.replace(pos, 1, searchName);
                    pos = prefix.find_first_of('?', pos + searchName.length() + 1);
                }

                bool breakOut = false;
                for (const std::string& ext : { ExtLuaC,ExtLua,std::string() }) {
                    // Test ".luac"/".lua" and no ext.
                    chunkName = prefix + ext;
                    if (utils->isFileExist(chunkName)) {
                        chunk = utils->getDataFromFile(chunkName);
                        breakOut = true;
                        break;
                    }
                }
                if (breakOut) {
                    break;
                }

                begin = next + 1;
            }
            const uint8_t* cByte = chunk.getBytes();
            size_t cSize = static_cast<size_t>(chunk.getSize());
            if (chunk.getSize() >= 3) {
                // SkipBOM
                if (cByte[0] == 0xEF && cByte[1] == 0xBB && cByte[2] == 0xBF) {
                    cByte += 3;
                    cSize -= 3;
                }
            }
            return load_buffer(reinterpret_cast<const std::byte*>(cByte), cSize, chunkName);
        });

        // Move the custom searcher to index 2.
        sol::table searchers = (*this)["package"]["searchers"];
        for (auto i = searchers.size() + 1; i > 2; i--) {
            searchers[i] = searchers[i - 1];
        }
        auto sSize = searchers.size();
        searchers[2] = searchers[sSize];
        searchers[sSize] = sol::nil;

        // Register auto types and manual types.
        Register();
    }

    void Lua::Close() {
        delete lua;
        lua = nullptr;
    }

    void Lua::ReleaseInLua(void* obj) {
        // Get lua_State*.
        auto l = lua_state();// ...
        // Get registry["SolWrapper.UD"] as a table.
        if (LUA_TTABLE == lua_getfield(l, LUA_REGISTRYINDEX, UserDataKey)) {// ...table?
            lua_pushlightuserdata(l, obj);// ...table,light_ud
            lua_pushvalue(l, -1);// ...table,light_ud,light_ud
            if (LUA_TUSERDATA == lua_rawget(l, -2)) {// ...table,light_ud,userdata?
                void** ud = (void**)lua_touserdata(l, -1);// ...table,light_ud,userdata
                lua_pushnil(l);// ...table,light_ud,userdata,nil
                lua_setmetatable(l, 2);// ...table,light_ud,userdata
                if (ud) {
                    *ud = nullptr;
                }
            }
            lua_pop(l, 1);// ...table,light_ud
            lua_pushnil(l);// ...table,light_ud,nil
            lua_rawset(l, -3);// ...table
        }
        // Keep lua stack.
        lua_pop(l, 1);// ...
    }

    void Lua::Register() {
        // Register sol function.
        create_named_table("sol",
            "Null", [](lua_State* l) {
            if (1 != lua_gettop(l)) {
                luaL_error(l, "sol.Null accept 1 param(s) but got %d param(s).", lua_gettop(l));
                return 0;
            }
            const int luaType = lua_type(l, 1);
            if (LUA_TNIL == luaType) {
                lua_pushboolean(l, TRUE);
                return 1;
            }
            else if (LUA_TUSERDATA == luaType) {
                void** ud = (void**)lua_touserdata(l, 1);
                if (ud == nullptr || *ud == nullptr) {
                    lua_pushboolean(l, TRUE);
                    return 1;
                }
            }
            lua_pushboolean(l, FALSE);
            return 1;
        });

        // Register all auto code.
        register_all_cocos2dx(*this);
        register_all_cocos2dx_3d(*this);
        register_all_cocos2dx_audioengine(*this);
        register_all_cocos2dx_backend(*this);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        register_all_cocos2dx_controller(*this);
#endif
        register_all_cocos2dx_csloader(*this);
        register_all_cocos2dx_extension(*this);
        register_all_cocos2dx_navmesh(*this);
        register_all_cocos2dx_spine(*this);
        register_all_cocos2dx_studio(*this);
        register_all_cocos2dx_ui(*this);
        register_all_cocos2dx_video(*this);
        register_all_cocos2dx_webview(*this);
        // Register all manual code.
    }
}