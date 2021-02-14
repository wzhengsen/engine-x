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

using namespace cocos2d;
namespace cocos2d {
    Lua* Lua::GetInstance() {
        if (!lua) {
            lua = new Lua();
            lua->open_libraries();
            lua->add_package_loader([](std::string fileName) {
                static const std::string ExtLuaC = ".luac";
                static const std::string ExtLua = ".lua";
                std::string searchPath = (*lua)["package"]["path"];
                Data chunk = {};
                std::string chunkName = {};
                FileUtils* utils = FileUtils::getInstance();

                size_t pos = 0;
                for (const std::string& ext : { ExtLuaC,ExtLua }) {
                    pos = fileName.rfind(ext);
                    if (pos != std::string::npos && pos == fileName.length() - ext.length()) {
                        // fileName ignore end with ".lua" or ".luac".
                        fileName = fileName.substr(0, pos);
                        break;
                    }
                }

                while (std::string::npos != (pos = fileName.find_first_of('.'))) {
                    // fileName replace . by /
                    fileName.replace(pos, 1, "/");
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

                    // prefix replace ? by fileName.
                    pos = prefix.find_first_of('?', 0);
                    while (pos != std::string::npos) {
                        prefix.replace(pos, 1, fileName);
                        pos = prefix.find_first_of('?', pos + fileName.length() + 1);
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
                return lua->load_buffer(reinterpret_cast<const std::byte*>(cByte), cSize, chunkName);
            });
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
        auto l = lua_state();// ...
        // Get registry["SolWrapper.UD"] as a table.
        if (LUA_TTABLE == lua_getfield(l, LUA_REGISTRYINDEX, "SolWrapper.UD")) {// ...table?
            luaL_unref(l, -1, ref);// ...table
        }
        // Keep lua stack.
        lua_pop(l, 1);// ...
    }
}