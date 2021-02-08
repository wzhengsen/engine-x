#include "cocos2d.h"
#include "Cocos2dx/LuaRegisterCocos2dx.h"
#include "network/CCDownloader.h"
#include "OO_Lua/OO_Lua.hpp"
#include "ui/CocosGUI.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "cocos/resource.h"
#include "../../../proj.windows/resource.h"
#endif

using namespace OO_Lua;
using namespace cocos2d;
using namespace cocos2d::network;

static int ApplicationNewDialog(lua_State* L) {
    const Lua lua = Lua(L);
    const int argc = lua.GetTop();
    if (argc >= 3 && argc <= 5) {
        if (argc == 3) {
            cocos2d::Application::getInstance()->Dialog(lua.CheckString(2), lua.CheckString(3));
        }
        else if (argc == 4) {
            const int okCB = lua.SaveFunction();
            cocos2d::Application::getInstance()->Dialog(
                lua.CheckString(2),
                lua.CheckString(3),
                [lua, okCB]() noexcept {
                    // ...
                    lua.LoadFunction(okCB);// function ...
                    lua.Call();// ...
                    lua.ClearFunction(okCB);// ...
                }
            );
        }
        else if (argc == 5) {
            if (lua.IsFunction()) {
                const int cancelCB = lua.SaveFunction();
                const int okCB = lua.SaveFunction();
                cocos2d::Application::getInstance()->Dialog(
                    lua.CheckString(2),
                    lua.CheckString(3),
                    [lua, okCB, cancelCB]() noexcept {
                        // ...
                        lua.LoadFunction(okCB);// function ...
                        lua.Call();// ...
                        lua.ClearFunction(okCB);// ...
                        lua.ClearFunction(cancelCB);// ...
                    },
                    [lua, okCB, cancelCB]() noexcept {
                        // ...
                        lua.LoadFunction(cancelCB);// function ...
                        lua.Call();// ...
                        lua.ClearFunction(okCB);// ...
                        lua.ClearFunction(cancelCB);// ...
                    }
                );
            }
            else {
                const bool showCancel = lua.ToBoolean();
                lua.Pop(1);
                const int okCB = lua.SaveFunction();
                cocos2d::Application::getInstance()->Dialog(
                    lua.CheckString(2),
                    lua.CheckString(3),
                    [lua, okCB]() noexcept {
                        // ...
                        lua.LoadFunction(okCB);// function ...
                        lua.Call();// ...
                        lua.ClearFunction(okCB);// ...
                    },
                    showCancel ? [lua, okCB]() noexcept {
                        lua.ClearFunction(okCB);// ...
                    } : std::function<void()>(nullptr)
                    );
            }
        }
    }
    else {
        lua.Error("Dialog param must between 3-5.");
    }
    return 0;
}

static int ApplicationNewNotify(lua_State* L) {
    const Lua lua = Lua(L);
    const int argc = lua.GetTop();
    if (argc == 3) {
        cocos2d::Application::getInstance()->Notify(
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
            IDI_ICON1,
#endif
            lua.ToString(2),
            lua.ToString(3)
        );
    }
    else if (argc == 4) {
        const int clickCB = lua.SaveFunction();
        cocos2d::Application::getInstance()->Notify(
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
            IDI_ICON1,
#endif
            lua.ToString(2),
            lua.ToString(3),
            [lua, clickCB]() noexcept {
            // ...
            lua.LoadFunction(clickCB);// function ...
            lua.Call();// ...
            lua.ClearFunction(clickCB);// ...
            },
            [lua, clickCB]() noexcept {
                // ...
                lua.ClearFunction(clickCB);// ...
            }
        );
    }
    else {
        lua.Error("Notify param must between 3-4.");
    }
    return 0;
}


static void ExtendApplication(const Lua& lua) noexcept {
    lua.RawGet(Lua::RegistryIndex, "cc.Application");
    if (lua.IsTable()) {
        lua.RawSet(-1, "Dialog", ApplicationNewDialog);
        lua.RawSet(-1, "Notify", ApplicationNewNotify);
    }
    lua.Pop(1);
}

static void PushPhysicsContactData(const Lua& lua,const PhysicsContactData* cd) noexcept {
    lua.NewTable(0, 3);
    lua.SetField(-1, "count", cd->count);

    lua.NewTable(0, 2);
    lua.SetField(-1, "x", cd->normal.x);
    lua.SetField(-1, "y", cd->normal.y);
    lua.SetField(-2, "normal");

    lua.NewTable(cd->count, 0);
    for (int i = 0; i < cd->count; i++) {
        lua.NewTable(0, 2);
        lua.SetField(-1, "x", cd->points[i].x);
        lua.SetField(-1, "y", cd->points[i].y);
        lua.SetField(-2, i + 1);
    }
    lua.SetField(-2, "points");
}

static int PhysicsContact_getContactData(lua_State* L) {
    const Lua lua = Lua(L);
    const int argc = lua.GetTop();
    if (1 == argc) {
        const cocos2d::PhysicsContact* cobj = static_cast<cocos2d::PhysicsContact*>(tolua_tousertype(L, 1, nullptr));
        const PhysicsContactData* cd = cobj->getContactData();
        if (cd) {
            PushPhysicsContactData(lua, cd);
        }
        else {
            lua.Push();
        }
    }
    else {
        lua.ArgError(1, "cocos2d::PhysicsContact::getContactData accept 1 param.");
    }
    return 1;
}

static int PhysicsContact_getPreContactData(lua_State* L) {
    const Lua lua = Lua(L);
    const int argc = lua.GetTop();
    if (1 == argc) {
        const cocos2d::PhysicsContact* cobj = static_cast<cocos2d::PhysicsContact*>(tolua_tousertype(L, 1, nullptr));
        const PhysicsContactData* cd = cobj->getPreContactData();
        if (cd) {
            PushPhysicsContactData(lua, cd);
        }
        else {
            lua.Push();
        }
    }
    else {
        lua.ArgError(1, "cocos2d::PhysicsContact::getPreContactData accept 1 param.");
    }
    return 1;
}


static void ExtendPhysics(const Lua& lua) noexcept {
    lua.RawGet(Lua::RegistryIndex, "cc.PhysicsContact");
    if (lua.IsTable()) {
        lua.RawSet(-1, "getContactData", PhysicsContact_getContactData);
        lua.RawSet(-1, "getPreContactData", PhysicsContact_getPreContactData);
    }
    lua.Pop(1);
}


void LuaRegisterCocos2dx(lua_State* L) noexcept {
    const Lua lua = Lua(L);
    ExtendApplication(lua);
}

static int LuaDownloaderNew(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    if (3 < top) {
        return 0;
    }
    else if (3 >= top) {
        auto hints = DownloaderHints();
        if (1 <= top) {
            hints.countOfMaxProcessingTasks = lua.CheckInteger(1);
        }
        if (2 <= top) {
            hints.timeoutInMS = lua.CheckInteger(2);
        }
        if (3 <= top) {
            hints.tempFileNameSuffix = lua.CheckString(3);
        }
        const auto downloader = new (std::nothrow) Downloader(hints);
        lua.BindUserData(downloader, "Downloader");//userdata ...
    }
    return 1;
}

static int LuaDownloaderDelete(lua_State* L) {
    const auto lua = Lua(L);
    lua.ArgCheck(lua.GetTop() == 1, 1);

    const auto downloader = lua.CheckUserData<Downloader*>(-1, "Downloader");
    if (downloader) {
        lua.Push();
        lua.PushValue();
        lua.SaveValue(*downloader);
        lua.SetMetaTable(-2);
        delete* downloader;
        *downloader = nullptr;
    }
    return 0;
}

static int LuaDownloaderDownload(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(top >= 2 && top <= 4, 0, "Param Number Error.");

    const auto downloader = lua.CheckUserData<Downloader*>(1, "Downloader");
    if (downloader) {
        const char* url = lua.CheckString(2);
        if (2 == top) {
            const auto task = (*downloader)->createDownloadDataTask(url);
            lua.BindUserData(task.get(), "DownloadTask");
            return 1;
        }
        const char* path = lua.CheckString(3);
        const char* md5Sum = "";
        if (4 == top) {
            md5Sum = lua.CheckString(4);
        }
        if (!FileUtils::getInstance()->isAbsolutePath(path)) {
            CCLOGWARN("Downloader use a relative path maybe cause some error.");
        }
        const auto task = (*downloader)->createDownloadFileTask(url, path, md5Sum);
        lua.BindUserData(task.get(), "DownloadTask");
        return 1;
    }
    return 0;
}

static int LuaDownloaderOnError(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(2 >= top, 0, "Param Number Error.");

    const auto downloader = lua.CheckUserData<Downloader*>(1, "Downloader");
    if (downloader) {
        if (1 == top || (2 == top && lua.IsNil())) {
            (*downloader)->setOnTaskError(nullptr);
            return 0;
        }
        //function userdata
        lua.GetUserValue(1);//table function userdata
        lua.PushValue(-2);//function table function userdata
        lua.SetField(-2, "@_OnError_");//table function userdata

        (*downloader)->setOnTaskError([downloader, lua](
            const DownloadTask& task,
            int errorCode,
            int errorCodeInternal,
            const std::string& errorStr) noexcept {
                lua.LoadValue(*downloader);// userdata ...
                lua.GetUserValue(-1);// table userdata ...
                lua.GetField(-1, "@_OnError_");// function? table userdata ...

                if (lua.IsFunction()) {
                    lua.PushValue(-3);// userdata function table userdata ...

                    lua.LoadValue(&task);// userdata"DownloadTask"? userdata function table userdata ...
                    // 检查是否有绑定的userdata
                    if (!lua.TestUserData(-1, "DownloadTask")) {
                        lua.Pop(1);// userdata function table userdata ...
                        lua.BindUserData(&task, "DownloadTask");// userdata"DownloadTask" userdata function table userdata ...
                    }
                    lua.Rotate(-5, -2);// table userdata userdata"DownloadTask" userdata function...
                    lua.Pop(2);// userdata"DownloadTask" userdata function ...
                    lua.SetField(-1, "@_error_", errorStr);// userdata"DownloadTask" userdata function ...
                    lua.Call(2);// ...
                }
            });
    }
    return 0;
}

static int LuaDownloaderOnSuccess(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(2 >= top, 0, "Param Number Error.");

    const auto downloader = lua.CheckUserData<Downloader*>(1, "Downloader");
    if (downloader) {
        if (1 == top || (2 == top && lua.IsNil())) {
            (*downloader)->setOnFileTaskSuccess(nullptr);
            (*downloader)->onDataTaskSuccess = nullptr;
            return 0;
        }
        //function userdata
        lua.GetUserValue(1);//table function userdata
        lua.PushValue(-2);//function table function userdata
        lua.SetField(-2, "@_OnSuccess_");//table function userdata

        (*downloader)->setOnFileTaskSuccess([downloader, lua](const DownloadTask& task) noexcept {
            lua.LoadValue(*downloader);// userdata ...
            lua.GetUserValue(-1);// table userdata ...
            lua.GetField(-1, "@_OnSuccess_");// function? table userdata ...

            if (lua.IsFunction()) {
                lua.PushValue(-3);// userdata function table userdata ...
                lua.LoadValue(&task);// userdata"DownloadTask"? userdata function table userdata ...
                // 检查是否有绑定的userdata
                if (!lua.TestUserData(-1, "DownloadTask")) {
                    lua.Pop(1);// userdata function table userdata ...
                    lua.BindUserData(&task, "DownloadTask");// userdata"DownloadTask" userdata function table userdata ...
                }
                lua.Rotate(-5, -2);// table userdata userdata userdata function ...
                lua.Pop(2);// userdata userdata function ...
                lua.Call(2);// ...
            }
            });

        (*downloader)->onDataTaskSuccess = ([downloader, lua](const DownloadTask& task, std::vector<unsigned char>& data) noexcept {
            lua.LoadValue(*downloader);// userdata ...
            lua.GetUserValue(-1);// table userdata ...
            lua.GetField(-1, "@_OnSuccess_");// function? table userdata ...

            if (lua.IsFunction()) {
                lua.PushValue(-3);// userdata function table userdata ...
                lua.LoadValue(&task);// userdata"DownloadTask"? userdata function table userdata ...
                // 检查是否有绑定的userdata
                if (!lua.TestUserData(-1, "DownloadTask")) {
                    lua.Pop(1);// userdata function table userdata ...
                    lua.BindUserData(&task, "DownloadTask");// userdata"DownloadTask" userdata function table userdata ...
                }
                lua.Push(data.data(), data.size());// string userdata userdata function table userdata ...
                lua.SetField(-2, "@_data_");// userdata userdata function table userdata ...
                lua.Rotate(-5, -2);// table userdata userdata userdata function ...
                lua.Pop(2);// userdata userdata function ...
                lua.Call(2);// ...
            }
            });
    }
    return 0;
}

static int LuaDownloaderOnProgress(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(2 >= top, 0, "Param Number Error.");

    const auto downloader = lua.CheckUserData<Downloader*>(1, "Downloader");
    if (downloader) {
        if (1 == top || (2 == top && lua.IsNil())) {
            (*downloader)->setOnTaskProgress(nullptr);
            return 0;
        }
        //function userdata
        lua.GetUserValue(1);//table function userdata
        lua.PushValue(-2);//function table function userdata
        lua.SetField(-2, "@_OnProgress_");//table function userdata

        (*downloader)->setOnTaskProgress([downloader, lua](const DownloadTask& task) noexcept {
                lua.LoadValue(*downloader);// userdata ...
                lua.GetUserValue(-1);// table userdata ...
                lua.GetField(-1, "@_OnProgress_");// function? table userdata ...

                if (lua.IsFunction()) {
                    lua.PushValue(-3);// userdata function table userdata ...
                    lua.LoadValue(&task);// userdata"DownloadTask"? userdata function table userdata ...
                    // 检查是否有绑定的userdata
                    if (!lua.TestUserData(-1, "DownloadTask")) {
                        lua.Pop(1);// userdata function table userdata ...
                        lua.BindUserData(&task, "DownloadTask");// userdata"DownloadTask" userdata function table userdata ...
                    }
                    lua.Rotate(-5, -2);// table userdata userdata"DownloadTask" userdata function...
                    lua.Pop(2);// userdata"DownloadTask" userdata function ...
                    lua.Call(2);// ...
                }
            });
    }
    return 0;
}

static int LuaDownloadTaskCancel(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        (*task)->cancel();
    }
    return 0;
}

static int LuaDownloadTaskSpeedGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.Push((*task)->progressInfo.speedInBytes);
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskSizeGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.Push((*task)->progressInfo.totalBytesExpected);
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskReceivedGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.Push((*task)->progressInfo.bytesReceived);
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskGotGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.Push((*task)->progressInfo.totalBytesReceived);
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskUrlGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.Push((*task)->requestURL);
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskPathGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.Push((*task)->storagePath);
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskDataGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.GetField(1, "@_data_");
        return 1;
    }
    return 0;
}

static int LuaDownloadTaskErrorGtor(lua_State* L) {
    const auto lua = Lua(L);
    const auto top = lua.GetTop();
    lua.ArgCheck(1 == top, 0, "Param Number Error.");

    DownloadTask** task = lua.CheckUserData<DownloadTask*>(1, "DownloadTask");
    if (*task) {
        lua.GetField(1, "@_error_");
        return 1;
    }
    return 0;
}

static int luaopen_Network_Downloader(lua_State* L) {
    static const Lua::KVPair<const char*, Lua::CFunction> regKVFunc[] = {
        {"new",LuaDownloaderNew},
        {"delete",LuaDownloaderDelete},
        {"Download",LuaDownloaderDownload},
        {"SetOnError",LuaDownloaderOnError},
        {"SetOnSuccess",LuaDownloaderOnSuccess},
        {"SetOnProgress",LuaDownloaderOnProgress},
    };

    static const Lua::KVPair<const char*, Lua::CFunction> regKVDownloadTaskFunc[] = {
        {"Cancel",LuaDownloadTaskCancel}
    };

    static const std::map<std::string, Lua::CFunction> downloadTaskGtor = {
        {"Speed",LuaDownloadTaskSpeedGtor},
        {"Got",LuaDownloadTaskGotGtor},
        {"Size",LuaDownloadTaskSizeGtor},
        {"Received",LuaDownloadTaskReceivedGtor},

        {"Url",LuaDownloadTaskUrlGtor},
        {"Path",LuaDownloadTaskPathGtor},

        {"Data",LuaDownloadTaskDataGtor},
        {"Error",LuaDownloadTaskErrorGtor},
    };

    const auto lua = Lua(L);

    lua.NewUserDataMetaTable("Downloader");
    lua.SetPairs(-1, regKVFunc);
    // 不用时请调用delete()删除。
    CCLOGWARN("Downloader does not follow Cocos2dx and Lua's automatic recycling strategy. Be sure to manually call delete() to recycle when not in use.");

    lua.NewUserDataMetaTable("DownloadTask");
    lua.SetPairs(-1, regKVDownloadTaskFunc);
    lua.Gtor(-1, downloadTaskGtor);
    lua.Pop(1);

    return 1;
}

void LuaRegisterDownloader(lua_State* L) noexcept {
    static Lua::KVPair<const char*, Lua::CFunction> regKV[] = {
        {"Starry::Downloader", luaopen_Network_Downloader}
    };
    const auto lua = Lua(L);

    lua.GetGlobal("package");
    lua.GetField(-1, "preload");
    lua.SetPairs(-1, regKV);

    lua.Pop(2);
}