#include <map>
#include "OO_Lua/OO_Lua.hpp"
#include "Device/Device.h"
#include "Device/LuaRegisterDevice.h"


using namespace OO_Lua;
using namespace StarryX;

static int DeviceGetBatteryPercent(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push(Device::GetBatteryPercent());
    return 1;
}

static int DeviceIsBatteryCharge(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push(Device::IsBatteryCharge());
    return 1;
}

static int DeviceGetWifiLevel(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push(Device::GetWifiLevel());
    return 1;
}

static int DeviceGetNetworkType(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push((void*)Device::GetNetworkType());
    return 1;
}

static int DeviceSetOrientation(lua_State* L) {
    const auto lua = Lua(L);
    lua.ArgCheck(lua.GetTop() == 1, 1, "The function accept 1 param.");
    if (lua.IsLightUserData()) {
        const auto ori = (Device::OrientationType)(Lua::Integer)lua.ToPointer();
        Device::SetOrientation(ori);
    }
    else {
        lua.Error("Param must be a lightuserdata.");
    }
    return 0;
}

static int DeviceGetOrientation(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push((void*)Device::GetOrientation());
    return 1;
}

static int DeviceIsAutoOrientation(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push(Device::IsAutoOrientation());
    return 1;
}

static int DeviceGetIp(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push(Device::GetIp());
    return 1;
}

static int DeviceGetId(lua_State* L) noexcept {
    const auto lua = Lua(L);
    lua.ArgCheck(!lua.GetTop(), 0, "The function accept no param.");
    lua.Push(Device::GetId());
    return 1;
}

static int luaopen_Device(lua_State* L) {
    static const std::map<const char*, void*> ntType = {
    {"None",(void*)Device::NetworkType::None},
    {"Wifi",(void*)Device::NetworkType::Wifi},
    {"Mobile",(void*)Device::NetworkType::Mobile},
    {"Other",(void*)Device::NetworkType::Other}
    };
    static const std::map<const char*, void*> oriType = {
    {"Landscape",(void*)Device::OrientationType::Landscape},
    {"Portrait",(void*)Device::OrientationType::Portrait},
    {"Auto",(void*)Device::OrientationType::Auto}
    };
    static const Lua::KVPair<const char*, Lua::CFunction> regKVFunc[] = {
    {"GetBatteryPercent",DeviceGetBatteryPercent},
    {"IsBatteryCharge",DeviceIsBatteryCharge},
    {"GetWifiLevel",DeviceGetWifiLevel},
    {"GetNetworkType",DeviceGetNetworkType},
    {"SetOrientation",DeviceSetOrientation},
    {"GetOrientation",DeviceGetOrientation},
    {"IsAutoOrientation",DeviceIsAutoOrientation},
    {"GetIp",DeviceGetIp},
    {"GetId",DeviceGetId}
    };

    const auto lua = Lua(L);
    lua.NewTable();//table ...
    lua.Push(ntType);// table table ...
    lua.SetField(-2, "NetworkType");// table ...
    lua.Push(oriType);// table table ...
    lua.SetField(-2, "OrientationType");// table ...
    lua.SetPairs(-1, regKVFunc);// table ...

    return 1;
}

void LuaRegisterDevice(lua_State* L) noexcept {
    static Lua::KVPair<const char*, Lua::CFunction> regKV[] = {
    {"StarryX::Device", luaopen_Device}
    };
    const auto lua = Lua(L);

    lua.GetGlobal("package");
    lua.GetField(-1, "preload");
    lua.SetPairs(-1, regKV);

    lua.Pop(2);
}