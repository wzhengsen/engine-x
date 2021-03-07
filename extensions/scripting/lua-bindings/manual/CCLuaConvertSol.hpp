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
#include "scripting/lua-bindings/CCLua.h"
#include "cocos2d.h"

 /**
  * @brief       Any class which base of cocos2d::extension::LuaObject will trigger this function when it be pushed into lua stack.
  *              Shound not be called by manual.
  */
template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::extension::LuaObject, T>::value>::type>
int sol_lua_push(lua_State* L, const T* obj) {
    if (nullptr == obj) {
        return 0;
    }
    bool udExist = LUA_TTABLE == lua_getfield(L, LUA_REGISTRYINDEX, cocos2d::extension::Lua::UserDataKey);// table?

    if (udExist) {
        // Try to get exist userdata from registry["SolWrapper.UD"].
        udExist = LUA_TUSERDATA == lua_rawgetp(L, 1, obj); // table,userdata?
    }
    if (!udExist) {
        lua_settop(L, 0);
        // New userdata.
        *static_cast<const T**>(lua_newuserdata(L, sizeof(const T*))) = obj;// ud

        // Make sure the registry["SolWrapper.UD"] is a table.
        if (LUA_TTABLE != lua_getfield(L, LUA_REGISTRYINDEX, cocos2d::extension::Lua::UserDataKey)) {// ud,table?
            lua_pop(L, 1);// ud
            lua_newtable(L);// ud,table
            lua_pushvalue(L, -1);// ud,table,table
            lua_setfield(L, LUA_REGISTRYINDEX, cocos2d::extension::Lua::UserDataKey);// ud,table
        }

        // Save object into registry["SolWrapper.UD"] with light_ud pointer as key.
        lua_pushvalue(L, -2);// ud,table,ud
        lua_rawsetp(L, -2, obj);// ud,table
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

// Convert cocos2d::Vec2
int sol_lua_push(lua_State* L, const cocos2d::Vec2& val);
cocos2d::Vec2 sol_lua_get(sol::types<cocos2d::Vec2>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Vec3
int sol_lua_push(lua_State* L, const cocos2d::Vec3& val);
cocos2d::Vec3 sol_lua_get(sol::types<cocos2d::Vec3>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Vec4
int sol_lua_push(lua_State* L, const cocos2d::Vec4& val);
cocos2d::Vec4 sol_lua_get(sol::types<cocos2d::Vec4>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::BlendFunc
int sol_lua_push(lua_State* L, const cocos2d::BlendFunc& val);
cocos2d::BlendFunc sol_lua_get(sol::types<cocos2d::BlendFunc>, lua_State* L, int idx, sol::stack::record& tracking);

#if CC_USE_PHYSICS
// Convert cocos2d::PhysicsMaterial
int sol_lua_push(lua_State* L, const cocos2d::PhysicsMaterial& val);
cocos2d::PhysicsMaterial sol_lua_get(sol::types<cocos2d::PhysicsMaterial>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::PhysicsRayCastInfo
int sol_lua_push(lua_State* L, const cocos2d::PhysicsRayCastInfo& val);
int sol_lua_push(lua_State* L, const cocos2d::PhysicsRayCastInfo* val);
cocos2d::PhysicsRayCastInfo sol_lua_get(sol::types<cocos2d::PhysicsRayCastInfo>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::PhysicsContactData
int sol_lua_push(lua_State* L, const cocos2d::PhysicsContactData& val);
cocos2d::PhysicsContactData sol_lua_get(sol::types<cocos2d::PhysicsContactData>, lua_State* L, int idx, sol::stack::record& tracking);
#endif

// Convert cocos2d::Size
int sol_lua_push(lua_State* L, const cocos2d::Size& val);
cocos2d::Size sol_lua_get(sol::types<cocos2d::Size>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Rect
int sol_lua_push(lua_State* L, const cocos2d::Rect& val);
cocos2d::Rect sol_lua_get(sol::types<cocos2d::Rect>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Color4B
int sol_lua_push(lua_State* L, const cocos2d::Color4B& val);
cocos2d::Color4B sol_lua_get(sol::types<cocos2d::Color4B>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Color4F
int sol_lua_push(lua_State* L, const cocos2d::Color4F& val);
cocos2d::Color4F sol_lua_get(sol::types<cocos2d::Color4F>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Color3B
int sol_lua_push(lua_State* L, const cocos2d::Color3B& val);
cocos2d::Color3B sol_lua_get(sol::types<cocos2d::Color3B>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::AffineTransform
int sol_lua_push(lua_State* L, const cocos2d::AffineTransform& val);
cocos2d::AffineTransform sol_lua_get(sol::types<cocos2d::AffineTransform>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::FontDefinition
int sol_lua_push(lua_State* L, const cocos2d::FontDefinition& val);
cocos2d::FontDefinition sol_lua_get(sol::types<cocos2d::FontDefinition>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::TTFConfig
int sol_lua_push(lua_State* L, const cocos2d::TTFConfig& val);
cocos2d::TTFConfig sol_lua_get(sol::types<cocos2d::TTFConfig>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Mat4
int sol_lua_push(lua_State* L, const cocos2d::Mat4& val);
cocos2d::Mat4 sol_lua_get(sol::types<cocos2d::Mat4>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::MeshVertexAttrib
int sol_lua_push(lua_State* L, const cocos2d::MeshVertexAttrib& val);
cocos2d::MeshVertexAttrib sol_lua_get(sol::types<cocos2d::MeshVertexAttrib>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Quaternion
int sol_lua_push(lua_State* L, const cocos2d::Quaternion& val);
cocos2d::Quaternion sol_lua_get(sol::types<cocos2d::Quaternion>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Texture2D::TexParams
int sol_lua_push(lua_State* L, const cocos2d::Texture2D::TexParams& val);
cocos2d::Texture2D::TexParams sol_lua_get(sol::types<cocos2d::Texture2D::TexParams>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Tex2F
int sol_lua_push(lua_State* L, const cocos2d::Tex2F& val);
cocos2d::Tex2F sol_lua_get(sol::types<cocos2d::Tex2F>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::V3F_C4B_T2F
int sol_lua_push(lua_State* L, const cocos2d::V3F_C4B_T2F& val);
cocos2d::V3F_C4B_T2F sol_lua_get(sol::types<cocos2d::V3F_C4B_T2F>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::backend::UniformLocation
int sol_lua_push(lua_State* L, const cocos2d::backend::UniformLocation& val);
cocos2d::backend::UniformLocation sol_lua_get(sol::types<cocos2d::backend::UniformLocation>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::backend::AttributeBindInfo
int sol_lua_push(lua_State* L, const cocos2d::backend::AttributeBindInfo& val);
cocos2d::backend::AttributeBindInfo sol_lua_get(sol::types<cocos2d::backend::AttributeBindInfo>, lua_State* L, int idx, sol::stack::record& tracking);
