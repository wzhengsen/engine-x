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
#include "ui/UILayoutParameter.h"

 /**
  * @brief          Any class which base of cocos2d::extension::LuaObject will trigger this function when it be pushed into lua stack.
  *                 Shound not be called by manual.
  * @note           int sol_lua_push(sol::types<const T*>, lua_State* L, const T* obj); => for "const T*" types
  *                 int sol_lua_push(sol::types<T*>, lua_State* L, const T* obj);       => for "T*" and "T&" types
  *                 int sol_lua_push(sol::types<T>, lua_State* L, const T& obj);        => for "const T&" and "const T" and "T" types
  */
template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::extension::LuaObject, T>::value>::type>
int sol_lua_push(sol::types<const T*>, lua_State* L, const T* obj) {
    if (nullptr == obj) {
        lua_pushnil(L);
        return 1;
    }
    
    lua_pushlstring(L, cocos2d::extension::Lua::UserDataKey, sizeof(cocos2d::extension::Lua::UserDataKey));// UserDataKey
    if (LUA_TTABLE != lua_rawget(L, LUA_REGISTRYINDEX)) {// table?
        // Make sure the registry[UserDataKey] is a table.
        lua_pop(L, -1);//
        lua_createtable(L, 0, 1024);// table
        lua_pushlstring(L, cocos2d::extension::Lua::UserDataKey, sizeof(cocos2d::extension::Lua::UserDataKey));// table UserDataKey
        lua_pushvalue(L, -2);// table UserDataKey table
        lua_rawset(L, LUA_REGISTRYINDEX);// table
    }

    // Try to get exist userdata from registry[UserDataKey].
    if (LUA_TUSERDATA == lua_rawgetp(L, -1, obj)) {// table,userdata?
        lua_remove(L, -2); // userdata
    }
    else {
        lua_pop(L, 1);// table
        // New userdata.
        *static_cast<const T**>(lua_newuserdata(L, sizeof(const T*))) = obj;// table ud

        lua_insert(L, -2);// ud table

        // Save object into registry[UserDataKey] with light_ud pointer as key.
        lua_pushvalue(L, -2);// ud,table,ud
        lua_rawsetp(L, -2, obj);// ud,table
        lua_pop(L, 1);//ud

        // meta name?
        const char* metaName = sol::usertype_traits<T*>::metatable().c_str();
        const std::string& name = typeid(*obj).name();
        auto iter = cocos2d::extension::Lua::Id2Meta.find(name);
        if (iter != cocos2d::extension::Lua::Id2Meta.end()) {
            metaName = cocos2d::extension::Lua::Id2Meta.at(name).c_str();
        }

        // Set metatable for this userdata.
        if (luaL_getmetatable(L, metaName)) {// ud,mt?
            lua_setmetatable(L, -2);// ud
        }
        else {
            lua_pop(L, 1);// ud
        }
    }
    return 1;
}

template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::extension::LuaObject, T>::value>::type>
int sol_lua_push(sol::types<T*>, lua_State* L, const T* obj) {
    return sol_lua_push(sol::types<const T*>(), L, obj);
}

template<typename T, typename = typename std::enable_if<std::is_base_of<cocos2d::extension::LuaObject, T>::value>::type>
int sol_lua_push(sol::types<T>, lua_State* L, const T& obj) {
    return sol_lua_push(sol::types<const T*>(), L, &obj);
}

template <typename Handler>
inline static bool CheckSimpleTable(lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    const auto success = sol::stack::check<sol::table>(L, index, std::forward<Handler>(handler));
    tracking.use(1);
    return success;
}

// Convert cocos2d::Vec2
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Vec2>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Vec2>, lua_State* L, const cocos2d::Vec2& val);
cocos2d::Vec2 sol_lua_get(sol::types<cocos2d::Vec2>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Vec3
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Vec3>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Vec3>, lua_State* L, const cocos2d::Vec3& val);
cocos2d::Vec3 sol_lua_get(sol::types<cocos2d::Vec3>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Vec4
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Vec4>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Vec4>, lua_State* L, const cocos2d::Vec4& val);
cocos2d::Vec4 sol_lua_get(sol::types<cocos2d::Vec4>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::BlendFunc
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::BlendFunc>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::BlendFunc>, lua_State* L, const cocos2d::BlendFunc& val);
cocos2d::BlendFunc sol_lua_get(sol::types<cocos2d::BlendFunc>, lua_State* L, int idx, sol::stack::record& tracking);

#if CC_USE_PHYSICS
// Convert cocos2d::PhysicsMaterial
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::PhysicsMaterial>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::PhysicsMaterial>, lua_State* L, const cocos2d::PhysicsMaterial& val);
cocos2d::PhysicsMaterial sol_lua_get(sol::types<cocos2d::PhysicsMaterial>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::PhysicsRayCastInfo
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::PhysicsRayCastInfo>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::PhysicsRayCastInfo>, lua_State* L, const cocos2d::PhysicsRayCastInfo& val);
int sol_lua_push(sol::types<const cocos2d::PhysicsRayCastInfo*>, lua_State* L, const cocos2d::PhysicsRayCastInfo* val);
int sol_lua_push(sol::types<cocos2d::PhysicsRayCastInfo*>, lua_State* L, const cocos2d::PhysicsRayCastInfo* val);
cocos2d::PhysicsRayCastInfo sol_lua_get(sol::types<cocos2d::PhysicsRayCastInfo>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::PhysicsContactData
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::PhysicsContactData>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::PhysicsContactData>, lua_State* L, const cocos2d::PhysicsContactData& val);
int sol_lua_push(sol::types<const cocos2d::PhysicsContactData*>, lua_State* L, const cocos2d::PhysicsContactData* val);
cocos2d::PhysicsContactData sol_lua_get(sol::types<cocos2d::PhysicsContactData>, lua_State* L, int idx, sol::stack::record& tracking);
#endif

// Convert cocos2d::Size
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Size>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Size>, lua_State* L, const cocos2d::Size& val);
cocos2d::Size sol_lua_get(sol::types<cocos2d::Size>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Rect
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Rect>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Rect>, lua_State* L, const cocos2d::Rect& val);
cocos2d::Rect sol_lua_get(sol::types<cocos2d::Rect>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Color4B
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Color4B>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Color4B>, lua_State* L, const cocos2d::Color4B& val);
cocos2d::Color4B sol_lua_get(sol::types<cocos2d::Color4B>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Color4F
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Color4F>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Color4F>, lua_State* L, const cocos2d::Color4F& val);
cocos2d::Color4F sol_lua_get(sol::types<cocos2d::Color4F>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Color3B
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Color3B>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Color3B>, lua_State* L, const cocos2d::Color3B& val);
cocos2d::Color3B sol_lua_get(sol::types<cocos2d::Color3B>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::AffineTransform
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::AffineTransform>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::AffineTransform>, lua_State* L, const cocos2d::AffineTransform& val);
cocos2d::AffineTransform sol_lua_get(sol::types<cocos2d::AffineTransform>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::FontDefinition
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::FontDefinition>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::FontDefinition>, lua_State* L, const cocos2d::FontDefinition& val);
cocos2d::FontDefinition sol_lua_get(sol::types<cocos2d::FontDefinition>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::TTFConfig
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::TTFConfig>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::TTFConfig>, lua_State* L, const cocos2d::TTFConfig& val);
cocos2d::TTFConfig sol_lua_get(sol::types<cocos2d::TTFConfig>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Mat4
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Mat4>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Mat4>, lua_State* L, const cocos2d::Mat4& val);
cocos2d::Mat4 sol_lua_get(sol::types<cocos2d::Mat4>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::MeshVertexAttrib
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::MeshVertexAttrib>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::MeshVertexAttrib>, lua_State* L, const cocos2d::MeshVertexAttrib& val);
cocos2d::MeshVertexAttrib sol_lua_get(sol::types<cocos2d::MeshVertexAttrib>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Quaternion
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Quaternion>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Quaternion>, lua_State* L, const cocos2d::Quaternion& val);
cocos2d::Quaternion sol_lua_get(sol::types<cocos2d::Quaternion>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Texture2D::TexParams
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Texture2D::TexParams>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Texture2D::TexParams>, lua_State* L, const cocos2d::Texture2D::TexParams& val);
cocos2d::Texture2D::TexParams sol_lua_get(sol::types<cocos2d::Texture2D::TexParams>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::Tex2F
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Tex2F>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::Tex2F>, lua_State* L, const cocos2d::Tex2F& val);
cocos2d::Tex2F sol_lua_get(sol::types<cocos2d::Tex2F>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::V3F_C4B_T2F
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::V3F_C4B_T2F>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::V3F_C4B_T2F>, lua_State* L, const cocos2d::V3F_C4B_T2F& val);
cocos2d::V3F_C4B_T2F sol_lua_get(sol::types<cocos2d::V3F_C4B_T2F>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::backend::UniformLocation
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::backend::UniformLocation>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::backend::UniformLocation>, lua_State* L, const cocos2d::backend::UniformLocation& val);
cocos2d::backend::UniformLocation sol_lua_get(sol::types<cocos2d::backend::UniformLocation>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::backend::AttributeBindInfo
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::backend::AttributeBindInfo>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::backend::AttributeBindInfo>, lua_State* L, const cocos2d::backend::AttributeBindInfo& val);
cocos2d::backend::AttributeBindInfo sol_lua_get(sol::types<cocos2d::backend::AttributeBindInfo>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::RZip::ZipInfo
int sol_lua_push(sol::types<cocos2d::RZip::ZipInfo>, lua_State* L, const cocos2d::RZip::ZipInfo& val);

// Convert cocos2d::network::DownloaderHints
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::network::DownloaderHints>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::network::DownloaderHints>, lua_State* L, const cocos2d::network::DownloaderHints& val);
cocos2d::network::DownloaderHints sol_lua_get(sol::types<cocos2d::network::DownloaderHints>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::network::DownloadTask::ProgressInfo
int sol_lua_push(sol::types<cocos2d::network::DownloadTask::ProgressInfo>, lua_State* L, const cocos2d::network::DownloadTask::ProgressInfo& val);

// Convert std::vector<char/unsigned char>
template <typename Handler>
bool sol_lua_check(sol::types<std::vector<char>>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    bool success = sol::stack::check<std::string>(L, index, std::forward<Handler>(handler));
    tracking.use(1);
    return success;
}
template <typename Handler>
bool sol_lua_check(sol::types<std::vector<unsigned char>>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return sol_lua_check(sol::types<std::vector<char>>(), L, index, std::forward<Handler>(handler), tracking);
}
std::vector<char> sol_lua_get(sol::types<std::vector<char>>, lua_State* L, int idx, sol::stack::record& tracking);
std::vector<unsigned char> sol_lua_get(sol::types<std::vector<unsigned char>>, lua_State* L, int idx, sol::stack::record& tracking);
int sol_lua_push(sol::types<std::vector<char>>, lua_State* L, const std::vector<char>& val);
int sol_lua_push(sol::types<std::vector<unsigned char>>, lua_State* L, const std::vector<unsigned char>& val);
int sol_lua_push(sol::types<const std::vector<char>*>, lua_State* L, const std::vector<char>* val);
int sol_lua_push(sol::types<const std::vector<unsigned char>*>, lua_State* L, const std::vector<unsigned char>* val);

// Convert std::vector<T>
template <typename Handler,typename T>
bool sol_lua_check(sol::types<std::vector<T>>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L,index,std::forward<Handler>(handler),tracking);
}
template <typename T>
std::vector<T> sol_lua_get(sol::types<std::vector<T>>, lua_State* L, int idx, sol::stack::record& tracking) {
    std::vector<T> vec = {};
    sol::table t = sol::table(L, idx);
    t.for_each([&vec](const sol::object& k,const sol::object& v) {
        vec.emplace_back(v.as<T>());
    });
    tracking.use(1);
    return vec;
}
template <typename T>
int sol_lua_push(sol::types<std::vector<T>>, lua_State* L, const std::vector<T>& val) {
    lua_createtable(L, static_cast<int>(val.size()), 0);
    size_t i = 1;
    for (const auto& v : val) {
        sol::stack::raw_set_field(L, i, v);
        i++;
    }
    return 1;
}

template <typename T>
int sol_lua_push(sol::types<const std::vector<T>*>, lua_State* L, const std::vector<T>* val) {
    if (!val) {
        lua_pushnil(L);
        return 1;
    }
    return sol_lua_push(sol::types<std::vector<T>>(), L, *val);
}

// Convert cocos2d::Data
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::Data>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    bool success = sol::stack::check<std::string>(L, index, std::forward<Handler>(handler));
    tracking.use(1);
    return success;
}
int sol_lua_push(sol::types<cocos2d::Data>, lua_State* L, const cocos2d::Data& val);
cocos2d::Data sol_lua_get(sol::types<cocos2d::Data>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert cocos2d::ui::Margin
template <typename Handler>
bool sol_lua_check(sol::types<cocos2d::ui::Margin>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}
int sol_lua_push(sol::types<cocos2d::ui::Margin>, lua_State* L, const cocos2d::ui::Margin& val);
cocos2d::ui::Margin sol_lua_get(sol::types<cocos2d::ui::Margin>, lua_State* L, int idx, sol::stack::record& tracking);

// Convert std::map<K,V>/std::unordered_map<K,V>
template <typename Handler,typename K,typename V>
bool sol_lua_check(sol::types<std::map<K, V>>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return CheckSimpleTable(L, index, std::forward<Handler>(handler), tracking);
}

template <typename Handler, typename K, typename V>
bool sol_lua_check(sol::types<std::unordered_map<K, V>>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking) {
    return sol_lua_check(sol::types<std::map<K, V>>(), L, index, std::forward<Handler>(handler), tracking);
}

template <typename K, typename V>
std::map<K, V> sol_lua_get(sol::types<std::map<K, V>>, lua_State* L, int idx, sol::stack::record& tracking) {
    std::map<K, V> _map = {};
    sol::table t = sol::table(L, idx);
    t.for_each([&_map](const sol::object& k, const sol::object& v) {
        _map[k.as<K>()] = v.as<V>();
        });
    tracking.use(1);
    return _map;
}
template <typename K, typename V>
std::unordered_map<K, V> sol_lua_get(sol::types<std::unordered_map<K, V>>, lua_State* L, int idx, sol::stack::record& tracking) {
    std::unordered_map<K, V> _map = {};
    sol::table t = sol::table(L, idx);
    t.for_each([&_map](const sol::object& k, const sol::object& v) {
        _map[k.as<K>()] = v.as<V>();
        });
    tracking.use(1);
    return _map;
}

template <typename K, typename V>
int sol_lua_push(sol::types<std::map<K, V>>, lua_State* L, const std::map<K, V>& val) {
    lua_createtable(L, 0,static_cast<int>(val.size()));
    for (const auto iter : val) {
        sol::stack::raw_set_field(L, iter.first, iter.second);
    }
    return 1;
}

template <typename K, typename V>
int sol_lua_push(sol::types<std::map<K, V>*>, lua_State* L, const std::map<K, V>* val) {
    if (!val) {
        lua_pushnil(L);
        return 1;
    }
    return sol_lua_push(sol::types<std::map<K, V>>(), L, *val);
}

template <typename K, typename V>
int sol_lua_push(sol::types<std::unordered_map<K, V>>, lua_State* L, const std::unordered_map<K, V>& val) {
    lua_createtable(L, 0, static_cast<int>(val.size()));
    for (const auto iter : val) {
        sol::stack::raw_set_field(L, iter.first, iter.second);
    }
    return 1;
}

template <typename K, typename V>
int sol_lua_push(sol::types<std::unordered_map<K, V>*>, lua_State* L, const std::unordered_map<K, V>* val) {
    if (!val) {
        lua_pushnil(L);
        return 1;
    }
    return sol_lua_push(sol::types<std::unordered_map<K, V>>(), L, *val);
}