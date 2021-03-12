/****************************************************************************
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

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

#include "base/CCConsole.h"
#include "scripting/lua-bindings/manual/CCLuaBridge.h"


NS_CC_BEGIN

lua_State* LuaBridge::L = nullptr;
int LuaBridge::increaseIdLevel = -1;
constexpr int functionRetainLimit = 4096;

void LuaBridge::SetLua(lua_State* L) {
    if (LuaBridge::L != L){
        LuaBridge::L = L;
        if (increaseIdLevel < 0) {
            increaseIdLevel = 0;
        }
        else {
            increaseIdLevel += functionRetainLimit;
        }
    }
}

void LuaBridge::releaseLuaFunction(int functionId)
{
    if (functionId > increaseIdLevel + functionRetainLimit || functionId <= increaseIdLevel) {
        return;
    }
    functionId -= increaseIdLevel;
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);            /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE)    /* L: id_f */
    {
        lua_pop(L, 1);//
        CCLOG("CCLuaBridge::releaseLuaFunction() - LUA_BRIDGE_REGISTRY_FUNCTION not exists");
        return;
    }

    if (lua_rawgeti(L, -1, functionId) != LUA_TFUNCTION) {// table function?
        lua_pop(L, 2); //
        return;
    }

    lua_pop(L, 1);// table
    luaL_unref(L, -1, functionId);
    lua_pop(L, 1);//

    CCLOG("CCLuaBridge::releaseLuaFunction() - function id %d released", functionId);
}

int LuaBridge::retainLuaFunction(int functionIndex)
{
    /* L: f ... */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);            /* L: f ... key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE)     /* L: f ... id_f */
    {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);
        lua_pushvalue(L, -2);
        lua_rawset(L, LUA_REGISTRYINDEX);
    }

    if (functionIndex < 0) {
        // positive index keep it is.
        functionIndex--;
    }
    lua_pushvalue(L, functionIndex);                // function ... table function
    const auto ref = luaL_ref(L, -2);               // function ... table(ref)
    if (ref > functionRetainLimit) {
        luaL_unref(L, -1, ref);                     // function ... table
        lua_pop(L, 1);                              // function ...
        return 0;
    }
    lua_pop(L, 1);                                  // function ...
    return ref + increaseIdLevel;
}

int LuaBridge::callLuaFunction(int functionId, const char *arg)
{
    if (functionId > increaseIdLevel + functionRetainLimit || functionId <= increaseIdLevel) {
        return -1;
    }
    functionId -= increaseIdLevel;
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_rawgeti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_pushstring(L, arg);
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);
    return ok;
}

int LuaBridge::callLuaFunction(int functionId, int64_t arg)
{
    if (functionId > increaseIdLevel + functionRetainLimit || functionId <= increaseIdLevel) {
        return -1;
    }
    functionId -= increaseIdLevel;
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_rawgeti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_pushinteger(L, arg);
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);
    return ok;
}

int LuaBridge::callLuaFunction(int functionId, bool arg)
{
    if (functionId > increaseIdLevel + functionRetainLimit || functionId <= increaseIdLevel) {
        return -1;
    }
    functionId -= increaseIdLevel;
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_rawgeti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_pushboolean(L, arg);
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);
    return ok;
}

int LuaBridge::callLuaFunction(int functionId, const std::map<std::string,std::string>& arg) {
    if (functionId > increaseIdLevel + functionRetainLimit || functionId <= increaseIdLevel) {
        return -1;
    }
    functionId -= increaseIdLevel;
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_rawgeti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_createtable(L, 0, static_cast<int>(arg.size()));
    for(const auto& it : arg) {
        lua_pushlstring(L, it.second.c_str(), it.second.length());
        lua_setfield(L, -2, it.first.c_str());
    }
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);

    return ok;
}

int LuaBridge::callLuaFunction(int functionId)
{
    if (functionId > increaseIdLevel + functionRetainLimit || functionId <= increaseIdLevel) {
        return -1;
    }
    functionId -= increaseIdLevel;
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_rawgeti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    const int ok = lua_pcall(L, 0, 0, 0);                     /* L: id_f ret|err */
    lua_settop(L, top);
    return ok;
}

// call lua global function
int LuaBridge::callLuaGlobalFunction(const char *functionName, const char *arg)
{
    int top = lua_gettop(L);

    lua_getglobal(L, functionName);
    int ok = -1;
    if (lua_isfunction(L, -1))
    {
        lua_pushstring(L, arg);
        ok = lua_pcall(L, 1, 0, 0);
    }

    lua_settop(L, top);
    return ok;
}

NS_CC_END
