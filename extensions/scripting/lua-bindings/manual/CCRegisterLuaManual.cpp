#include "CCRegisterLuaManual.h"
#include "CCLuaConvertSol.hpp"
// lua socket.
#if __cplusplus
extern "C" {
#endif
#include "luasocket/luasocket.h"
#include "luasocket/luasocket_scripts.h"
#include "luasocket/mime.h"
#if __cplusplus
} // extern "C"
#endif

extern "C" {
#include "lua_cjson.h"
}

extern "C" {
LUALIB_API int luaopen_pb_conv(lua_State* L);
LUALIB_API int luaopen_pb_buffer(lua_State* L);
LUALIB_API int luaopen_pb_slice(lua_State* L);
LUALIB_API int luaopen_pb(lua_State* L);
LUALIB_API int luaopen_pb_io(lua_State* L);
LUALIB_API int luaopen_pb_unsafe(lua_State* L);
}

#include "2d/CCTMXXMLParser.h"
#include "platform/CCApplication.h"
#include "platform/CCDevice.h"
#include "2d/CCRenderTexture.h"
#include "2d/CCParallaxNode.h"
#include "base/ccCArray.h"
#include "renderer/backend/ProgramState.h"
#if CC_USE_PHYSICS
#include "physics/CCPhysicsBody.h"
#if CC_ENABLE_CHIPMUNK_INTEGRATION
#include "chipmunk/chipmunk_private.h"
#endif
#if CC_ENABLE_BOX2D_INTEGRATION
#include "box2d/box2d.h"
#endif
#endif
#include "CCDatas.h"
#include "ActionTimeline/CCSkeletonNode.h"
#include "network/CCLuaWebSocket.h"
#include "network/CCLuaHttpRequest.h"
#include "base/CCZip.h"
#include "base/ccUtils.h"

using namespace cocos2d;

static void RegisterLuaCoreZipManual(extension::Lua& lua) {
    sol::table zItem = lua["cc"]["RZip"]["ZipItem"];
    zItem["Read"] = [&lua](const RZip::ZipItem& item, const sol::variadic_args& va) {
        const char* pwd = nullptr;
        std::string pwdStr = {};
        if (va.size() >= 1) {
            pwdStr = va[0].as<std::string>();
            pwd = pwdStr.c_str();
        }
        const auto& info = item.GetInfo();
        const auto& name = info.name;
        auto L = lua.lua_state();
        if (name.length() > 0 && name[name.length() - 1] == '/') {
            std::vector<const RZip::ZipItem*> vecItem = {};
            bool ret = item.Read(vecItem);
            if (ret) {
                lua_createtable(L, static_cast<int>(vecItem.size()), 0);
                size_t idx = 0;
                for (const auto& i : vecItem) {
                    sol::stack::raw_set_field(L, ++idx, i);
                }
            }
            else {
                lua_pushnil(L);
            }
            return sol::object(L);
        }
        luaL_Buffer b = {};
        auto buffer = luaL_buffinitsize(L, &b, info.size);
        bool ret = item.Read(buffer, info.size, pwd);
        if (ret) {
            luaL_pushresultsize(&b, info.size);
        }
        else {
            luaL_pushresult(&b);
            lua_pushnil(L);
        }
        return sol::object(L);
    };

    sol::table rZip = lua["cc"]["RZip"];
    rZip["__pairs__"] = [](RZip* rZip) {
        auto begin = rZip->begin();
        return [=]() mutable {
            const RZip::ZipItem* item = nullptr;
            if (begin != RZip::end()) {
                item = &*(begin++);
            }
            return item;
        };
    };
}

static void RegisterLua_ProtobufManual(extension::Lua& lua) {
    static luaL_Reg reg[] = {{"pb", luaopen_pb}, {"pb.io", luaopen_pb_io}, {"pb.conv", luaopen_pb_conv},
        {"pb.slice", luaopen_pb_slice}, {"pb.buffer", luaopen_pb_buffer}, {"pb.unsafe", luaopen_pb_unsafe}};
    for (const auto v : reg) {
        lua["package"]["preload"][v.name] = v.func;
    }
}

static void RegisterCJsonManual(extension::Lua& lua) {
    lua["package"]["preload"]["cjson"]    = &luaopen_cjson_safe;
}

static void RegisterLuaSocketManual(extension::Lua& lua) {
    static constexpr luaL_Reg luax_exts[] = {
    {"socket.core", luaopen_socket_core},
    {"mime.core", luaopen_mime_core}
    };
    sol::table preload = lua["package"]["preload"];
    for (auto& iter : luax_exts) {
        preload[iter.name] = iter.func;
    }

    luaopen_luasocket_scripts(lua.lua_state());
}

static void RegisterLuaCoreTMXMapInfoManual(extension::Lua& lua) {
    sol::table tmi = lua["cc"]["TMXMapInfo"];
    tmi["StartElement"] = [](TMXMapInfo* tmi, const std::string_view& sv, const sol::table t) {
        const auto size = t.size();
        std::unique_ptr<const char* []> strs = std::make_unique<const char* []>(size + 1);
        std::vector<std::string> sVec = {};
        for (int i = 1; i <= size; i++) {
            std::string value = t[i];
            sVec.emplace_back(value);
        }
        strs[size] = nullptr;
        tmi->startElement(nullptr, sv.data(), strs.get());
    };
    tmi["EndElement"] = [](TMXMapInfo* tmi, const std::string_view& sv) {
        tmi->endElement(nullptr, sv.data());
    };
}

static void RegisterLuaCoreApplicationManual(extension::Lua& lua) {
    sol::table app = lua["cc"]["Application"];
#if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
    app["Dialog"] = [](Application* app, const std::string& title, const std::string& content, sol::variadic_args va) {
        const auto size = va.size();
        if (size == 0) {
            app->Dialog(title, content);
        }
        else if (size == 1) {
            sol::function f = va[0];
            app->Dialog(title, content, f);
        }
        else if (size == 2) {
            sol::function f1 = va[0];
            sol::object o = va[1];
            if (o.get_type() == sol::type::function) {
                sol::function f2 = o;
                app->Dialog(title, content, f1, f2);
            }
            else if (o.get_type() == sol::type::boolean) {
                app->Dialog(title, content, f1, o.as<bool>() ? []() {} : std::function<void()>(nullptr));
            }
            else if (o.get_type() == sol::type::nil) {
                sol::function f = va[0];
                app->Dialog(title, content, f);
            }
        }
    };
#endif
}

static void RegisterLuaCoreDeviceManual(extension::Lua& lua) {
    sol::table device = lua["cc"]["Device"];
    device["GetTextureDataForText"] = [](const std::string& text, const FontDefinition& fd, lua_Integer align) {
        int width = 0;
        int height = 0;
        bool hasPremultipliedAlpha = false;
        cocos2d::Data d = cocos2d::Device::getTextureDataForText(text.c_str(), fd, static_cast<cocos2d::Device::TextAlign>(align), width, height, hasPremultipliedAlpha);
        auto ret = std::string(reinterpret_cast<char*>(d.getBytes()), static_cast<size_t>(d.getSize()));
        return std::make_tuple(ret, width, height, hasPremultipliedAlpha);
    };
}

static void RegisterLuaCoreRenderTextureManual(extension::Lua& lua) {
    sol::table renderTexture = lua["cc"]["RenderTexture"];
    renderTexture["NewImage"] = [](RenderTexture* renderTexture, sol::function f, sol::variadic_args va) {
        renderTexture->newImage([f](RefPtr<Image> refPtr) {
            f(refPtr.get());
        }, va.size() == 0 ? false : va[0].as<bool>());
    };
}

static void RegisterLuaCoreParallaxNodeManual(extension::Lua& lua) {
    sol::table parallaxNode = lua["cc"]["ParallaxNode"];
    parallaxNode["SetParallaxArray"] = [](ParallaxNode* parallaxNode, sol::table t) {
        const auto size = static_cast<ssize_t>(t.size());
        _ccArray* arr = ccArrayNew(size);

        lua_State* L = t.lua_state();// userdata table
        lua_pushnil(L);// userdata table nil
        while (lua_next(L, -2)) {// userdata table key? value?
            void** p = (void**)lua_touserdata(L, -1);// userdata table key value
            ccArrayAppendObject(arr, *reinterpret_cast<Ref**>(p));// userdata table key value
            lua_pop(L, 1);// userdata table key
        }
        parallaxNode->setParallaxArray(arr);
    };
    parallaxNode["GetParallaxArray"] = [&lua](ParallaxNode* parallaxNode) {
        const _ccArray* const arr = parallaxNode->getParallaxArray();
        sol::table t = lua.create_table(static_cast<int>(arr->num));
        Ref* ref = nullptr;
        int i = 1;
        CCARRAYDATA_FOREACH(arr, ref) {
            t[i++] = ref;
        }
        return t;
    };
}

static void RegisterLuaBackendProgramStateManual(extension::Lua& lua) {
    sol::table programState = lua["ccb"]["ProgramState"];
    programState["GetCallbackUniforms"] = [&lua](backend::ProgramState* programState) {
        const auto& m = programState->getCallbackUniforms();
        sol::table t = lua.create_table(0, static_cast<int>(m.size()));
        for (const auto& it : m) {
            t[it.first] = it.second;
        }
        return t;
    };
    programState["GetVertexUniformBuffer"] = [&lua](backend::ProgramState* programState) {
        char* outStr = nullptr;
        size_t size = 0;
        programState->getVertexUniformBuffer(&outStr, size);
        return std::string(outStr, size);
    };

    programState["GetFragmentUniformBuffer"] = [&lua](backend::ProgramState* programState) {
        char* outStr = nullptr;
        size_t size = 0;
        programState->getFragmentUniformBuffer(&outStr, size);
        return std::string(outStr, size);
    };
}

static void RegisterLuaPhysicsPhysicsBodyManual(extension::Lua& lua) {
#if CC_USE_PHYSICS
    sol::table physicsBody = lua["cc"]["PhysicsBody"];
#if CC_ENABLE_CHIPMUNK_INTEGRATION
    physicsBody["GetCPBody"] = &PhysicsBody::getCPBody;
#endif
#if CC_ENABLE_BOX2D_INTEGRATION
    // todo
    physicsBody["GetB2DBody"] = []() {
        return 0;
    };
#endif
#endif
}

template<typename T, typename MT>
static void Cocos2dxVectorToTable(
    extension::Lua& lua,
    const std::string_view& svNameSpace,
    const std::string_view& svClassName,
    const std::string_view& svMethodName,
    MT&& mt) {
    sol::table cls = lua[svNameSpace][svClassName];
    cls[lua.OOPConfig["get"]][svMethodName] = [&lua, mt](T* obj) {
        // The returned table does not hold data.
        auto& dList = obj->*mt;
        sol::table t = lua.create_table(static_cast<int>(dList.size()));
        int i = 1;
        for (auto& data : dList) {
            t[i++] = data;
        }
        return t;
    };
}

template<typename T, typename MT>
static void Cocos2dxMapToTable(
    extension::Lua& lua,
    const std::string_view& svNameSpace,
    const std::string_view& svClassName,
    const std::string_view& svMethodName,
    MT&& mt) {
    sol::table cls = lua[svNameSpace][svClassName];
    cls[lua.OOPConfig["get"]][svMethodName] = [&lua, mt](T* obj) {
        // The returned table does not hold data.
        auto& dMap = obj->*mt;
        sol::table t = lua.create_table(0, static_cast<int>(dMap.size()));
        for (auto& data : dMap) {
            t[data.first] = data.second;
        }
        return t;
    };
}

inline static void RegisterLuaStudioBoneDataManual(extension::Lua& lua) {
    Cocos2dxVectorToTable<cocostudio::BoneData>(lua, "ccs", "BoneData", "displayDataList", &cocostudio::BoneData::displayDataList);
}

inline static void RegisterLuaStudioArmatureDataManual(extension::Lua& lua) {
    Cocos2dxMapToTable<cocostudio::ArmatureData>(lua, "ccs", "ArmatureData", "boneDataDic", &cocostudio::ArmatureData::boneDataDic);
}

inline static void RegisterLuaStudioMovementBoneDataManual(extension::Lua& lua) {
    Cocos2dxVectorToTable<cocostudio::MovementBoneData>(lua, "ccs", "MovementBoneData", "frameList", &cocostudio::MovementBoneData::frameList);
}

static void RegisterLuaStudioSkeletonNodeManual(extension::Lua& lua) {
    sol::table skeletonNode = lua["ccs"]["SkeletonNode"];
    skeletonNode["GetAllSubBonesMap"] = [&lua](cocostudio::timeline::SkeletonNode* skeletonNode) {
        // The returned table does not hold data.
        auto& sMap = skeletonNode->getAllSubBonesMap();
        sol::table t = lua.create_table(0, static_cast<int>(sMap.size()));
        for (auto& data : sMap) {
            t[data.first] = data.second;
        }
    };
}

inline static void RegisterLuaStudioAnimationDataManual(extension::Lua& lua) {
    Cocos2dxMapToTable<cocostudio::AnimationData>(lua, "ccs", "AnimationData", "movementDataDic", &cocostudio::AnimationData::movementDataDic);
}

inline static void RegisterLuaStudioTextureDataManual(extension::Lua& lua) {
    Cocos2dxVectorToTable<cocostudio::TextureData>(lua, "ccs", "TextureData", "contourDataList", &cocostudio::TextureData::contourDataList);
}

inline static void RegisterLuaStudioMovementDataManual(extension::Lua& lua) {
    Cocos2dxMapToTable<cocostudio::MovementData>(lua, "ccs", "MovementData", "movBoneDataDic", &cocostudio::MovementData::movBoneDataDic);
}

inline static void RegisterLuaCoreTMXTilesetInfoManual(extension::Lua& lua) {
    Cocos2dxMapToTable<cocos2d::TMXTilesetInfo>(lua, "cc", "TMXTilesetInfo", "_animationInfo", &cocos2d::TMXTilesetInfo::_animationInfo);
}

static void RegisterLuaCoreUtilsManual(extension::Lua& lua) {
    sol::table ccu = lua["ccu"];
    ccu["CaptureScreen"] = [](const sol::function& f) {
        utils::captureScreen(
            [f](RefPtr<Image> refPtr) {
                f(refPtr.get());
            }
        );
    };

    ccu["captureNode"] = [](Node* startNode, const sol::function& f, const sol::variadic_args& var) {
        if (var.size() == 0) {
            utils::captureNode(
                startNode,
                [f](RefPtr<Image> refPtr) {
                    f(refPtr.get());
                }
            );
        }
        else {
            utils::captureNode(
                startNode,
                [f](RefPtr<Image> refPtr) {
                    f(refPtr.get());
                },
                var[0].as<float>()
            );
        }
    };
}

void RegisterLuaManual(extension::Lua& lua) {
    RegisterCJsonManual(lua);
    RegisterLua_ProtobufManual(lua);
    RegisterLuaSocketManual(lua);
    RegisterLuaCoreTMXMapInfoManual(lua);
    RegisterLuaCoreApplicationManual(lua);
    RegisterLuaCoreDeviceManual(lua);
    RegisterLuaCoreRenderTextureManual(lua);
    RegisterLuaCoreParallaxNodeManual(lua);
    RegisterLuaBackendProgramStateManual(lua);
    RegisterLuaPhysicsPhysicsBodyManual(lua);
    RegisterLuaStudioBoneDataManual(lua);
    RegisterLuaStudioArmatureDataManual(lua);
    RegisterLuaStudioMovementBoneDataManual(lua);
    RegisterLuaStudioSkeletonNodeManual(lua);
    RegisterLuaStudioAnimationDataManual(lua);
    RegisterLuaStudioTextureDataManual(lua);
    RegisterLuaStudioMovementDataManual(lua);
    extension::LuaWebSocket::RegisterLuaWebSocketManual(lua);
    extension::LuaHttpRequest::RegisterLuaHttpRequestManual(lua);
    RegisterLuaCoreZipManual(lua);
    RegisterLuaCoreUtilsManual(lua);
}