#include "Zip/LuaRegisterZipFile.h"
#include "Zip/ZipFile.h"
#include "OO_Lua/OO_Lua.hpp"

using namespace OO_Lua;
using namespace StarryX;

static int ZipItem_GetInfo(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top != 1) {
		// 参数数量不合法。
		return 0;
	}
    const ZipFile::ZipItem** item = static_cast<const ZipFile::ZipItem**>(lua.CheckUserData(1, "ZipItem"));
	if (!item) {
		return 0;
	}
	const auto info = (*item)->GetInfo();
    lua.NewTable(0, 2);
	lua.SetField(-1, "name", info.name);
	lua.SetField(-1, "date", info.date);
	if (info.name.at(info.name.length() - 1) != '/') {
		lua.SetField(-1, "size", (Lua::Integer)info.size);
		lua.SetField(-1, "encrypt", info.encrypt);
	}
	return 1;
}

static int ZipItem_Read(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top < 1 || top > 2) {
		// 参数数量不合法。
		return 0;
	}
	const auto item = static_cast<ZipFile::ZipItem**>(lua.CheckUserData(1, "ZipItem"));
	if (!item) {
		return 0;
	}
	// 获取文件大小。
	const auto size = (*item)->GetInfo().size;

	auto b = Lua::Buffer();
	char* buffer = lua.BufferInitSize(&b, size);
	if (top == 2) {
		if (!(*item)->Read(buffer, size, lua.CheckString(2))) {
			return 0;
		}
	}
	else if(!(*item)->Read(buffer, size)){
		return 0;
	}
	Lua::PushResultSize(&b, size);

	return 1;
}

static int ZipFile_new(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top > 2 || top < 1) {
		// 参数数量不合法。
		return 0;
	}
	const std::string file = lua.CheckString(1);
	const ZipFile::ZipMode mode = top == 2 ? (ZipFile::ZipMode)(Lua::Integer)(lua.ToUserData(2)) : ZipFile::ZipMode::R;

	const ZipFile* zip = new (std::nothrow) ZipFile(file, mode);
    if (zip) {
        if (zip->Availed()) {
            lua.PushUserData(zip, "ZipFile");
            lua.PushValue();
            lua.SaveValue(zip);
            return 1;
        }
        delete zip;
        zip = nullptr;
        return 0;
    }
    return 0;
}

static int ZipFile_First(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top != 1) {
		// 参数数量不合法。
		return 0;
	}
	const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
	if (!zip) {
		return 0;
	}
	const auto item = (*zip)->First();
	if (!item) {
		return 0;
	}
	lua.LoadValue(item);// userdata"ZipItem"? userdata"ZipFile"
	// 检查是否有绑定的userdata
	if (!lua.TestUserData(-1, "ZipItem")) {
		lua.Pop(1);// userdata"ZipFile"
		lua.PushUserData(item, "ZipItem");// userdata"ZipItem" userdata"ZipFile"
		lua.PushValue();// userdata"ZipItem" userdata"ZipItem" userdata"ZipFile"
		lua.SaveValue(item);// userdata"ZipItem" userdata"ZipFile"
	}
	return 1;
}

static int ZipFile_Next(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top != 1) {
		// 参数数量不合法。
		return 0;
	}
	const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
	if (!zip) {
		return 0;
	}
	const auto item = (*zip)->Next();
	if (!item) {
		return 0;
	}
	lua.LoadValue(item);// userdata"ZipItem"? userdata"ZipFile"
	// 检查是否有绑定的userdata
	if (!lua.TestUserData(-1, "ZipItem")) {
		lua.Pop(1);// userdata"ZipFile"
		lua.PushUserData(item, "ZipItem");// userdata"ZipItem" userdata"ZipFile"
		lua.PushValue();// userdata"ZipItem" userdata"ZipItem" userdata"ZipFile"
		lua.SaveValue(item);// userdata"ZipItem" userdata"ZipFile"
	}
	return 1;
}

static int ZipFile_Seek(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top != 2) {
		// 参数数量不合法。
		return 0;
	}
	const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
	if (!zip) {
		return 0;
	}
	const char* fileName = lua.CheckString(2);
	const auto item = (*zip)->Seek(fileName);
	if (!item) {
		return 0;
	}
	lua.LoadValue(item);// userdata"ZipItem"? string userdata"ZipFile"
	// 检查是否有绑定的userdata
	if (!lua.TestUserData(-1, "ZipItem")) {
		lua.Pop(1);// string userdata"ZipFile"
		lua.PushUserData(item, "ZipItem");// userdata"ZipItem" string userdata"ZipFile"
		lua.PushValue();// userdata"ZipItem" userdata"ZipItem" string userdata"ZipFile"
		lua.SaveValue(item);// userdata"ZipItem" string userdata"ZipFile"
	}
	return 1;
}

static int ZipFile_Uncompress(lua_State* L) {
    const auto lua = Lua(L);

    const auto top = lua.GetTop();
    if (top < 2 || top > 3) {
        // 参数数量不合法。
        lua.Push(false);
        return 1;
    }

    const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
    if (!zip) {
        lua.Push(false);
        return 1;
    }
    const char* path = lua.CheckString(2);
    const char* password = nullptr;
    if (3 == top) {
        password = lua.CheckString(3);
    }
    lua.Push((*zip)->Uncompress(path, password));
    return 1;
}

// 栈-1
// 将栈顶的值作为ZipFile的异步函数，并弹出。
static std::function<void(ZipFile::AsyncData&)> ZipFile_MakeAsyncCallBack(const Lua& lua,ZipFile** zip) noexcept {
    // 保存回调函数。
    const int handler = lua.Ref(LUA_REGISTRYINDEX);
    return [handler, lua, zip](ZipFile::AsyncData& asyncData) {
        //...
        lua.GetField(LUA_REGISTRYINDEX, handler);// function? ...
        lua.Unref(LUA_REGISTRYINDEX, handler);// function? ...
        if (lua.IsFunction()) {
            lua.LoadValue(*zip);// userdata function ...
            lua.NewTable(0, 3);// table userdata function ...
            lua.SetField(-1, "suc", asyncData.suc);// table userdata function ...
            if (!asyncData.error.empty()) {
                lua.SetField(-1, "error", asyncData.error);
            }
            lua.XCall(2);// ...
            return;
        }
        lua.Pop(1);// ...
    };
}

static int ZipFile_UncompressAsync(lua_State* L) {
    const auto lua = Lua(L);

    const auto top = lua.GetTop();
    if (top < 2 || top > 4) {
        // 参数数量不合法。
        return 0;
    }

    const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
    if (!zip) {
        return 0;
    }
    const char* path = lua.CheckString(2);
    if (2 == top) {
        (*zip)->UncompressAsync(path);
    }
    else if (3 == top && lua.IsString()) {
        (*zip)->UncompressAsync(path,lua.CheckString(-1));
    }
    else {
        const char* password = nullptr;
        if (4 == top) {
            password = lua.CheckString(3);
        }
        if (!lua.IsFunction()) {
            return 0;
        }
        (*zip)->UncompressAsync(path, password, ZipFile_MakeAsyncCallBack(lua, zip));
    }
    return 0;
}

static int ZipFile_Compress(lua_State* L) {
    const auto lua = Lua(L);

    const auto top = lua.GetTop();
    if (top < 2 || top > 4) {
        // 参数数量不合法。
        lua.Push(false);
        return 1;
    }

    const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));// param1 userdata"ZipFile"
    if (!zip) {
        lua.Push(false);
        return 1;
    }
    if (2 == top) {
        if (lua.IsTable(2)) {// table userdata"ZipFile"
            lua.Push((*zip)->Compress(lua.ToStringArray(2)));// boolean table userdata"ZipFile"
            return 1;
        }
        lua.Push((*zip)->Compress(lua.CheckString(2)));
        return 1;
    }
    else if (3 == top) {
        if (lua.IsTable(2)) {// table table userdata"ZipFile"
            lua.Push((*zip)->Compress(lua.ToStringArray(2), lua.ToStringArray(3)));// boolean table table userdata"ZipFile"
            return 1;
        }
        lua.Push((*zip)->Compress(lua.CheckString(2), lua.CheckString(3)));
        return 1;
    }
    else if (4 == top){
        if (lua.IsTable(2)) {// string table table userdata"ZipFile"
            lua.Push((*zip)->Compress(lua.ToStringArray(2), lua.ToStringArray(3), lua.CheckString(4)));// boolean string table table userdata"ZipFile"
            return 1;
        }
        lua.Push((*zip)->Compress(lua.CheckString(2), lua.CheckString(3), lua.CheckString(4)));
        return 1;
    }
    lua.Push(false);
    return 1;
}

static int ZipFile_CompressAsync(lua_State* L) {
    const auto lua = Lua(L);

    const auto top = lua.GetTop();
    if (top < 2 || top > 5) {
        // 参数数量不合法。
        return 0;
    }

    const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
    if (!zip) {
        return 0;
    }

    if (2 == top) {
        if (lua.IsTable(-1)) {// table userdata"ZipFile"
            (*zip)->CompressAsync(lua.ToStringArray(2));// table userdata"ZipFile"
            return 0;
        }
        (*zip)->CompressAsync(lua.CheckString(-1));
    }
    else if (3 == top) {
        if (lua.IsString(-1) && lua.IsString(-2)) {// string string userdata"ZipFile"
            (*zip)->CompressAsync(lua.CheckString(-2),lua.CheckString(-1));
            return 0;
        }
        if (lua.IsTable(-1) && lua.IsTable(-2)) {// table table userdata"ZipFile"
            (*zip)->CompressAsync(lua.ToStringArray(2), lua.ToStringArray(3));// table table userdata"ZipFile"
            return 0;
        }
        if (lua.IsString(2) && lua.IsFunction(3)) {// function string userdata"ZipFile"
            (*zip)->CompressAsync(lua.CheckString(-1), ZipFile_MakeAsyncCallBack(lua, zip));// string userdata"ZipFile"
            return 0;
        }
        if (lua.IsTable(2) && lua.IsFunction(3)) {// function table userdata"ZipFile"
            (*zip)->CompressAsync(lua.ToStringArray(2), ZipFile_MakeAsyncCallBack(lua, zip)// table userdata"ZipFile"
            );
            return 0;
        }

        return 0;
    }
    else if (4 == top){
        if (lua.IsString(-1) && lua.IsString(-2) && lua.IsString(-3)) {// string string string userdata"ZipFile"
            (*zip)->CompressAsync(lua.CheckString(-3), lua.CheckString(-2), lua.CheckString(-1));
            return 0;
        }
        if (lua.IsFunction(-1) && lua.IsString(-2) && lua.IsString(-3)) {// function string string userdata"ZipFile"
            (*zip)->CompressAsync(lua.CheckString(-2), lua.CheckString(-1), ZipFile_MakeAsyncCallBack(lua, zip)); // string string userdata"ZipFile"
            return 0;
        }
        if (lua.IsFunction(-1) && lua.IsTable(-2) && lua.IsTable(-3)) {// function table table userdata"ZipFile"
            (*zip)->CompressAsync(lua.ToStringArray(2), lua.ToStringArray(3), ZipFile_MakeAsyncCallBack(lua, zip));// table table userdata"ZipFile"
            return 0;
        }
    }
    else if (5 == top) {
        if (lua.IsFunction(-1) && lua.IsTable(-3) && lua.IsTable(-4)) {// function string table table userdata"ZipFile"
            (*zip)->CompressAsync(lua.ToStringArray(2), lua.ToStringArray(3), lua.CheckString(-1), ZipFile_MakeAsyncCallBack(lua, zip)); // string table table userdata"ZipFile"
            return 0;
        }
        if (lua.IsFunction(-1) && lua.IsString(-3) && lua.IsString(-4)) {// function string string string userdata"ZipFile"
            (*zip)->CompressAsync(lua.CheckString(-3), lua.CheckString(-2), lua.CheckString(-1), ZipFile_MakeAsyncCallBack(lua, zip)); // string string string userdata"ZipFile"
            return 0;
        }
    }
    return 0;
}

static int ZipFile_delete(lua_State* L) {
	const auto lua = Lua(L);

	const auto top = lua.GetTop();
	if (top != 1) {
		// 参数数量不合法。
		return 0;
	}
	const auto zip = static_cast<ZipFile**>(lua.CheckUserData(1, "ZipFile"));
	if (!zip) {
		return 0;
	}
	const auto& internalItem = (*zip)->GetInternalZipItems();
	for (const auto& var : internalItem) {// userdata"ZipFile"
		const auto pointer = &var.second;
		lua.LoadValue(pointer);// userdata? userdata"ZipFile"
        if (lua.TestUserData(-1, "ZipItem")) {
            const ZipFile::ZipItem** item = static_cast<const ZipFile::ZipItem**>(lua.CheckUserData(-1, "ZipItem"));
            lua.Push();// nil userdata userdata"ZipFile"
            // 元表置空。
            lua.SetMetaTable(-2);// userdata userdata"ZipFile"
            lua.Pop(1);// userdata"ZipFile"

            lua.Push(); // nil userdata"ZipFile"
            lua.SaveValue(pointer);// userdata"ZipFile"
            *item = nullptr;
        }
        else {
            lua.Pop(1);// userdata"ZipFile"
        }
	}
    lua.Push();//nil userdata"ZipFile"
    lua.PushValue();//nil nil userdata"ZipFile"
    lua.SaveValue(*zip);//nil userdata"ZipFile"
    lua.SetMetaTable(-2);//userdata"ZipFile"
	delete *zip;
	*zip = nullptr;
	return 0;
}

static int luaopen_Zip(lua_State* L) {
	static const Lua::KVPair<const char*, Lua::CFunction> regKVFunc[] = {
		{"new",ZipFile_new},
		{"First",ZipFile_First},
		{"Next",ZipFile_Next},
		{"Seek",ZipFile_Seek},
        {"Uncompress",ZipFile_Uncompress},
        {"UncompressAsync",ZipFile_UncompressAsync},

        {"Compress",ZipFile_Compress},
        {"CompressAsync",ZipFile_CompressAsync},

		{"delete",ZipFile_delete},
	};

	static const Lua::KVPair<const char*, void*> regKVZipMode[] = {
		{"R",(void*)ZipFile::ZipMode::R},
		{"W",(void*)ZipFile::ZipMode::W}
	};

	const auto lua = Lua(L);

	lua.NewUserDataMetaTable("ZipFile");
	lua.SetPairs(-1, regKVFunc);
	lua.SetPairs(-1, regKVZipMode);


	static const Lua::KVPair<const char*, Lua::CFunction> regKVZipItemFunc[] = {
		{"Read",ZipItem_Read},
		{"GetInfo",ZipItem_GetInfo}
	};

    static const std::map<std::string, Lua::CFunction> itemGtor = {
        {"Info",ZipItem_GetInfo}
    };

	lua.NewUserDataMetaTable("ZipItem");
	lua.SetPairs(-1, regKVZipItemFunc);
    lua.Gtor(-1, itemGtor);
	lua.Pop(1);

	return 1;
}

void LuaRegisterZipFile(lua_State* L) noexcept {
	static Lua::KVPair<const char*, Lua::CFunction> regKV[] = {
		{"StarryX::ZipFile", luaopen_Zip}
	};
	const auto lua = Lua(L);

	lua.GetGlobal("package");
	lua.GetField(-1, "preload");
	lua.SetPairs(-1, regKV);

	lua.Pop(2);
}