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

#include "scripting/lua-bindings/manual/CCLuaBridge.h"

NS_CC_BEGIN

lua_State *LuaBridge::L = nullptr;
int        LuaBridge::s_newFunctionId = 0;

LuaStack *LuaBridge::getStack()
{
    return LuaEngine::getInstance()->getLuaStack();
}

bool LuaBridge::pushLuaFunctionById(int functionId)
{
    int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);            /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_geti(L, -1, functionId) != LUA_TFUNCTION) /* L: id_f */
    {
        lua_settop(L, top);
        lua_pushnil(L);
        return false;
    }

    return true;
}

int LuaBridge::retainLuaFunctionById(int functionId)
{
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_RETAIN);              /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE)     /* L: id_r */
    {
        lua_pop(L, 1);
        return 0;
    }

    // get counter
    lua_pushinteger(L, functionId);                             /* L: id_r id */
    if (lua_rawget(L, -2) != LUA_TNUMBER)               /* L: id_r r */
    {
        lua_pop(L, 2);
        return 0;
    }

    // increase counter
    int retainCount = lua_tointeger(L, -1);
    retainCount++;
    lua_pop(L, 1);                                              /* L: id_r */
    lua_pushinteger(L, functionId);                             /* L: id_r id */
    lua_pushinteger(L, retainCount);                            /* L: id_r id r */
    lua_rawset(L, -3);                            /* id_r[id] = r, L: id_r */
    lua_pop(L, 1);

    CCLOG("CCLuaBridge::retainLuaFunctionById(%d) - retain count = %d", functionId, retainCount);

    return retainCount;

}

int LuaBridge::releaseLuaFunctionById(int functionId)
{
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);            /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE)    /* L: id_f */
    {
        lua_pop(L, 1);
        CCLOG("CCLuaBridge::releaseLuaFunctionById() - LUA_BRIDGE_REGISTRY_FUNCTION not exists");
        return 0;
    }

    lua_pushstring(L, LUA_BRIDGE_REGISTRY_RETAIN);              /* L: id_f key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE)    /* L: id_f id_r */
    {
        lua_pop(L, 2);
        CCLOG("CCLuaBridge::releaseLuaFunctionById() - LUA_BRIDGE_REGISTRY_RETAIN not exists");
        return 0;
    }

    lua_pushinteger(L, functionId);                             /* L: id_f id_r id */
    if (lua_rawget(L, -2) != LUA_TNUMBER)                   /* L: id_f id_r r */
    {
        lua_pop(L, 3);
        CCLOG("CCLuaBridge::releaseLuaFunctionById() - function id %d not found", functionId);
        return 0;
    }

    int retainCount = lua_tointeger(L, -1);
    retainCount--;

    if (retainCount > 0)
    {
        // update counter
        lua_pop(L, 1);                                          /* L: id_f id_r */
        lua_pushinteger(L, functionId);                         /* L: id_f id_r id */
        lua_pushinteger(L, retainCount);                        /* L: id_f id_r id r */
        lua_rawset(L, -3);                        /* id_r[id] = r, L: id_f id_r */
        lua_pop(L, 2);
        CCLOG("CCLuaBridge::releaseLuaFunctionById() - function id %d retain count = %d", functionId, retainCount);
        return retainCount;
    }

    // remove lua function reference
    lua_pop(L, 1);                                              /* L: id_f id_r */
    lua_pushinteger(L, functionId);                             /* L: id_f id_r id */
    lua_pushnil(L);                                             /* L: id_f id_r id nil */
    lua_rawset(L, -3);                          /* id_r[id] = nil, L: id_f id_r */
    lua_pop(L, 1);                                              /* L: id_f */

    lua_pushinteger(L, functionId);                             /* L: id_f id */
    lua_rawget(L, -2);                                     /* L: id_f f */
    lua_pushnil(L);                                             /* L: id_f f nil */
    lua_rawset(L, -3);                                      /* L: id_f */

    lua_pushinteger(L, functionId);                             /* L: id_f id */
    lua_pushnil(L);                                             /* L: id_f id nil */
    lua_rawset(L, -3);                                            /* L: id_f */

    lua_pop(L, 1);
    CCLOG("CCLuaBridge::releaseLuaFunctionById() - function id %d released", functionId);
    return 0;
}

int LuaBridge::retainLuaFunction(lua_State *L, int functionIndex, int *retainCountReturn)
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

    lua_pushstring(L, LUA_BRIDGE_REGISTRY_RETAIN);              /* L: f ... id_f key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE)    /* L: f ... id_f id_r */
    {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushstring(L, LUA_BRIDGE_REGISTRY_RETAIN);
        lua_pushvalue(L, -2);
        lua_rawset(L, LUA_REGISTRYINDEX);
    }

    // get function id
    lua_pushvalue(L, functionIndex - 2);                        /* L: f ... id_f id_r f */

    int functionId;
    if (lua_rawget(L, -3) != LUA_TNUMBER)                   /* L: f ... id_f id_r id */
    {
        // first retain, create new id
        lua_pop(L, 1);                                          /* L: f ... id_f id_r */
        functionId = ++s_newFunctionId;

        lua_pushvalue(L, functionIndex - 2);                    /* L: f ... id_f id_r f */
        lua_pushinteger(L, functionId);                         /* L: f ... id_f id_r f id */
        lua_rawset(L, -4);                        /* id_f[f] = id, L: f ... id_f id_r */

        lua_pushinteger(L, functionId);                         /* L: f ... id_f id_r id*/
        lua_pushvalue(L, functionIndex - 3);                    /* L: f ... id_f id_r id f */
        lua_rawset(L, -4);                        /* id_f[id] = f, L: f ... id_f id_r */

        lua_pushinteger(L, functionId);                         /* L: f ... id_f id_r id */
    }
    else
    {
        functionId = lua_tointeger(L, -1);
    }

    // get function retain
    lua_pushvalue(L, -1);                                       /* L: f ... id_f id_r id id */
    int retainCount = 1;
    if (lua_rawget(L, -3) != LUA_TNUMBER)                       /* L: f ... id_f id_r id r */
    {
        // first retain, set retain count = 1
        lua_pop(L, 1);
        lua_pushinteger(L, retainCount);
    }
    else
    {
        // add retain count
        retainCount = lua_tointeger(L, -1);
        retainCount++;
        lua_pop(L, 1);
        lua_pushinteger(L, retainCount);
    }

    lua_rawset(L, -3);                            /* id_r[id] = r, L: f ... id_f id_r */
    lua_pop(L, 2);                                              /* L: f ... */

    if (retainCountReturn) *retainCountReturn = retainCount;
    return functionId;
}

int LuaBridge::callLuaFunctionById(int functionId, const char *arg)
{
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
    || lua_geti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_pushstring(L, arg);
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);
    return ok;
}

int LuaBridge::callLuaFunctionById(int functionId, int64_t arg)
{
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_geti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_pushinteger(L, arg);
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);
    return ok;
}

int LuaBridge::callLuaFunctionById(int functionId, bool arg)
{
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_geti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_pushboolean(L, arg);
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);
    return ok;
}

int LuaBridge::callLuaFunctionById(int functionId, const std::map<std::string,std::string>& arg) {
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_geti(L, -1, functionId) != LUA_TFUNCTION)
    {
        lua_settop(L, top);
        return -1;
    }

    lua_createtable(L, 0, arg.size());
    for(const auto& it : arg) {
        lua_pushlstring(L, it.second.c_str(), it.second.length());
        lua_setfield(L, -2, it.first.c_str());
    }
    int ok = lua_pcall(L, 1, 0, 0);
    lua_settop(L, top);

    return ok;
}

int LuaBridge::callLuaFunctionById(int functionId)
{
    const int top = lua_gettop(L);
    /* L: */
    lua_pushstring(L, LUA_BRIDGE_REGISTRY_FUNCTION);                  /* L: key */
    if (lua_rawget(L, LUA_REGISTRYINDEX) != LUA_TTABLE
        || lua_geti(L, -1, functionId) != LUA_TFUNCTION)
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
