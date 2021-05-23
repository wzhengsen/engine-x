#include "cocos2d.h"
#include "Cocos2dx/LuaRegisterCocos2dx.h"
#include "network/CCDownloader.h"
#include "OO_Lua/OO_Lua.hpp"
#include "ui/CocosGUI.h"

using namespace OO_Lua;
using namespace cocos2d;
using namespace cocos2d::network;

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