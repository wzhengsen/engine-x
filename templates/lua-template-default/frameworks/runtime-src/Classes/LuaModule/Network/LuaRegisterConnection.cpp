#include "LuaRegisterConnection.h"
#include "Network/Client.h"
#include "Network/Server.h"
#include "OO_Lua/OO_Lua.hpp"

using namespace StarryX::Network;
using namespace OO_Lua;

static Connection** CheckClientOrServer(const Lua& lua, int index) noexcept {
	auto conn = lua.TestUserData(index, "Connection.Client");
	if (!conn) {
		conn = lua.TestUserData(index, "Connection.Server");
	}
	lua.ArgCheck(conn != nullptr, index);
	return static_cast<Connection**>(conn);
}

static Client** CheckClient(const Lua& lua, int index) noexcept {
	auto conn = lua.CheckUserData(index, "Connection.Client");
	if (conn) {
		return static_cast<Client**>(conn);
	}
	return nullptr;
}

static Server** CheckServer(const Lua& lua, int index) noexcept {
	auto conn = lua.CheckUserData(index, "Connection.Server");
	if (conn) {
		return static_cast<Server**>(conn);
	}
	return nullptr;
}

template<typename T>
static int LuaNewConnection(lua_State* L) {
	const auto lua = Lua(L);
	const auto argc = lua.GetTop();
	if (argc > 1) {
		return 0;
	}
	auto type = Connection::Type::TCP;
	if (argc == 1) {
		type = (Connection::Type)(Lua::Integer)lua.ToUserData(-1);
	}

	auto conn = new T(type);
	lua.PushUserData(
		conn,
		std::is_same<T, Client>() ? "Connection.Client" : "Connection.Server"
	);//-1 UserData
	lua.PushValue();//-1 UserData -2 UserData...
	lua.SaveValue(conn);//-1 UserData
	return 1;
}

static int LuaDeleteConnection(lua_State* L) noexcept {
	const auto lua = Lua(L);
	lua.ArgCheck(lua.GetTop() == 1, 1);

	auto conn = CheckClientOrServer(lua, -1);
	if (conn && *conn) {
		lua.Push();
		lua.PushValue();
		lua.SaveValue(*conn);
		lua.SetMetaTable(-2);
		delete *conn;
		*conn = nullptr;
	}
	return 0;
}

static int LuaServerBind(lua_State* L) {
	const auto lua = Lua(L);
	const auto argc = lua.GetTop();
	if (argc == 3) {
		auto server = CheckServer(lua, -3);
		if (server && *server) {

			const u_short port = static_cast<u_short>(lua.CheckInteger(-1));
			const auto addr = lua.CheckString(-2);

			lua.Push((*server)->Bind(addr, port));
			return 1;
		}
	}
	else {
		auto server = CheckServer(lua, -2);
		if (server && *server) {
			const u_short port = static_cast<u_short>(lua.CheckInteger(-1));
			lua.Push((*server)->Bind(port));
			return 1;
		}
	}

	return 0;
}

static int LuaServerSend(lua_State* L) {
	const auto lua = Lua(L);

    const auto server = CheckServer(lua, 1);
	if (server && *server) {
		size_t len = 0;
        if (lua.GetTop() == 3) {
            const char* msg = lua.CheckLString(-1, &len);
            auto mgCon = static_cast<mg_connection*>(lua.ToUserData(-2));
            (*server)->Send(mgCon, msg, len);
        }
        else {
            const char* msg = lua.CheckLString(2, &len);
            (*server)->Send(msg, len);
        }
	}
	return 0;
}

static int LuaServerClose(lua_State* L) {
	const auto lua = Lua(L);

	const auto argc = lua.GetTop();
	if (argc == 2) {
		const auto server = CheckServer(lua, -2);
		if (server && *server) {
			auto mgCon = static_cast<mg_connection*>(lua.ToUserData(-1));
			(*server)->Close(mgCon);
		}
	}
	else if (argc == 1) {
		const auto server = CheckServer(lua, -1);
		if (server && *server) {
			(*server)->Close();
		}
	}

	return 0;
}

static int LuaServerGetState(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(lua.GetTop() == 1, 1);

	const auto conn = CheckServer(lua, -1);
	if (conn && *conn) {
		lua.Push((void*)(*conn)->GetState());
		return 1;
	}
	return 0;
}

static int LuaServerGetSockets(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(lua.GetTop() == 1, 1);

	const auto conn = CheckServer(lua, -1);
	if (conn && *conn) {
		auto& vec = (*conn)->GetSockets();
		lua.NewTable(static_cast<int>(vec.size()));
		Lua::Integer i = 1;
		for (auto it = vec.cbegin(); it != vec.cend(); it++) {
			lua.SetField(-1, i, (void*)*it);
			i++;
		}
		return 1;
	}
	return 0;
}

static int luaopen_Network_Server(const Lua& lua) noexcept {
	static const Lua::KVPair<const char*, Lua::CFunction> regKVFunc[] = {
	{"new",LuaNewConnection<Server>},
	{"Bind",LuaServerBind},
	{"Send",LuaServerSend},
	{"Close",LuaServerClose},
	{"GetState",LuaServerGetState},
	{"GetSockets",LuaServerGetSockets}
	};

	static const Lua::KVPair<const char*, void*> regKVEnum[] = {
	{"Closed",(void*)Server::State::Closed},
	{"Listening",(void*)Server::State::Listening}
	};

	lua.NewUserDataMetaTable("Connection.Server");

	lua.SetPairs(-1, regKVFunc);
	lua.SetPairs(-1, regKVEnum);

	return 1;
}

static int LuaClientConnect(lua_State* L) {
	const auto lua = Lua(L);

	auto client = CheckClient(lua, 1);
	if (client && *client) {
		const int top = lua.GetTop() - 1;
		const auto addr = lua.CheckString(2);
		const u_short port = static_cast<u_short>(lua.CheckInteger(3));
		if (top == 2) {
			lua.Push((*client)->Connect(addr, port));
			return 1;
		}
		else if (top == 4 && lua.IsBoolean(4)) {
			lua.Push((*client)->Connect(addr, port, lua.ToBoolean(4), static_cast<uint32_t>(lua.CheckInteger(5))));
			return 1;
		}
		else if (top == 3) {
			if (lua.IsBoolean(4)) {
				lua.Push((*client)->Connect(addr, port, lua.ToBoolean(4)));
			}
			else {
				lua.Push((*client)->Connect(addr, port, false, static_cast<uint32_t>(lua.CheckInteger(4))));
			}
			return 1;
		}
		else {
			lua.Error("Wrong param on Client.Connect!");
		}

	}
	lua.Push(false);
	return 1;
}

static int LuaClientSend(lua_State* L) noexcept {
	const auto lua = Lua(L);

	const auto client = CheckClient(lua, -2);
	if (client && *client) {
		(*client)->Send(lua.CheckString(-1));
	}
	return 0;
}

static int LuaClientGetState(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(lua.GetTop() == 1, 1);

	const auto conn = CheckClient(lua, -1);
	if (conn && *conn) {
		lua.Push((void*)(*conn)->GetState());
		return 1;
	}
	return 0;
}


static int luaopen_Network_Client(const Lua& lua) noexcept {
	static const Lua::KVPair<const char*,Lua::CFunction> regKVFunc[] = {
	{"new",LuaNewConnection<Client>},
	{"Connect",LuaClientConnect},
	{"Send",LuaClientSend},
	{"GetState",LuaClientGetState}
	};

	static const Lua::KVPair<const char*, void*> regKVEnum[] = {
	{"Closed",(void*)Client::State::Closed},
	{"Connecting",(void*)Client::State::Connecting},
	{"Connected",(void*)Client::State::Connected}
	};

	lua.NewUserDataMetaTable("Connection.Client");

	lua.SetPairs(-1, regKVFunc);
	lua.SetPairs(-1, regKVEnum);

	return 1;
}

static int LuaConnectionClose(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(lua.GetTop() == 1,1);

	const auto conn = CheckClientOrServer(lua, -1);
	if (conn && *conn) {
		(*conn)->Close();
	}
	return 0;
}

static int LuaConnectionCloseMGR(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(!lua.GetTop(), 1);
	Connection::CloseMGR();
	return 0;
}

static int LuaConnectionPoll(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(!lua.GetTop(), 1);
	Connection::Poll();
	return 0;
}

static int LuaConnectionGetType(lua_State* L) noexcept {
	const auto lua = Lua(L);

	lua.ArgCheck(lua.GetTop() == 1, 1);

	const auto conn = CheckClientOrServer(lua, -1);
	if (conn && *conn) {
		auto state = (*conn)->GetType();
		lua.Push((void*)state);
		return 1;
	}
	return 0;
}

static int LuaConnectionGetHandler(lua_State* L) noexcept {
	const auto lua = Lua(L);//conn

	const auto conn = CheckClientOrServer(lua, -1);
	if (conn && *conn) {
		lua.GetUserValue(-1);//table conn
		lua.GetField(-1, "@__EventHandler__");//table["@__EventHandler__"] table conn
		return 1;
	}

	return 0;
}

static int LuaConnectionSetHandler(lua_State* L) noexcept {
	const auto lua = Lua(L);//function conn

	auto conn = CheckClientOrServer(lua, -2);
	if (conn && *conn) {
		if (lua.IsFunction()) {
			(*conn)->SetHandler([L](const Connection * conn, const Connection::Info* info) noexcept {
				const auto lua = Lua(L);
				lua.LoadValue(conn);//userdata...
				if (lua.IsNil()) {
					lua.Pop(1);
					return;
				}
				lua.GetUserValue(-1);//table userdata...
				lua.GetField(-1, "@__EventHandler__");//function table userdata...
				if (lua.IsFunction()) {
					lua.Insert(-3);//table userdata function...
					lua.Pop(1);//userdata function...
					lua.NewTable(0, 3);//table userdata function...
					lua.SetField(-1, "event", (void*)info->event);//table userdata function...
					switch (info->event) {
					case Connection::Event::MG_Accept: {
						lua.SetField(-1, "conn", (void*)info->conn);
						lua.SetField(-1, "addr", info->addr);
						lua.SetField(-1, "port", info->port);
						break;
					}
					case Connection::Event::MG_Close: {
						if (info->conn) {
							if (conn->GetConnection() == info->conn) {
								lua.PushValue(-2);//userdata table userdata function...
								lua.SetField(-2, "conn");//table userdata function...
							}
							else {
								lua.SetField(-1, "conn", (void*)info->conn);
							}
						}
						break;
					}
					case Connection::Event::MG_Recv: {
						lua.SetField(-1, "conn", (void*)info->conn);
						lua.Push(static_cast<const char*>(info->msg->GetBuff()), info->msg->GetLen());//string table userdata function...
						lua.SetField(-2, "msg");//table userdata function...
						break;
					}
					case Connection::Event::MG_Connect: {
						lua.SetField(-1, "conn", (void*)info->conn);
						lua.SetField(-1, "suc", info->suc);
						break;
					}
					default:
						break;
					}
					lua.Call(2);//table userdata function...
				}
				else {
					lua.Pop(3);
				}
			});
		}
		else if (lua.IsNil()) {
			(*conn)->SetHandler(nullptr);
		}
		else {
			lua.ArgCheck(false, -2);
		}
	}
	else {
		return 0;
	}
	lua.GetUserValue(-2);//table function conn
	lua.Insert(-2);//function table conn
	lua.SetField(-2, "@__EventHandler__");
	return 0;
}


static int luaopen_Network_Connection(lua_State* L) {
	static const Lua::KVPair<const char*,Lua::CFunction> regKVFunc[] = {
	{"Close",LuaConnectionClose},
	{"GetType",LuaConnectionGetType},
	{"GetHandler",LuaConnectionGetHandler},
	{"SetHandler",LuaConnectionSetHandler},
	{"delete",LuaDeleteConnection},
	{"CloseMGR",LuaConnectionCloseMGR},
	{"Poll",LuaConnectionPoll}
	};

	static const std::map<std::string, Lua::CFunction> connGtor = {
		{"Type",LuaConnectionGetType},
		{"Handler",LuaConnectionGetHandler},
	};

	static const std::map<std::string, Lua::CFunction> connStor = {
		{"Handler",LuaConnectionSetHandler},
	};


	static const Lua::KVPair<const char*, void*> regKVEnum[] = {
	{"MG_Accept",(void*)Connection::Event::MG_Accept},
	{"MG_Connect",(void*)Connection::Event::MG_Connect},
	{"MG_Recv",(void*)Connection::Event::MG_Recv},
	{"MG_Close",(void*)Connection::Event::MG_Close},
	{"MG_None",(void*)Connection::Event::MG_None},

	{"TCP",(void*)Connection::Type::TCP},
	{"UDP",(void*)Connection::Type::UDP},
	};
	const auto lua = Lua(L);

	lua.NewUserDataMetaTable("Connection");
	lua.Gtor(-1, connGtor);
	lua.Stor(-1, connStor);
	lua.SetPairs(-1, regKVFunc);
	lua.SetPairs(-1, regKVEnum);

	luaopen_Network_Client(lua);
	lua.PushValue(-2);
	lua.SetMetaTable(-2);
	lua.SetField(-2, "Client");

	luaopen_Network_Server(lua);
	lua.PushValue(-2);
	lua.SetMetaTable(-2);
	lua.SetField(-2, "Server");

	return 1;
}

void LuaRegisterConnection(lua_State* L) noexcept {
	static Lua::KVPair<const char*, Lua::CFunction> regKV[] = {
		{"StarryX::Connection", luaopen_Network_Connection}
	};
	const auto lua = Lua(L);

	lua.GetGlobal("package");
	lua.GetField(-1, "preload");
	lua.SetPairs(-1, regKV);

	lua.Pop(2);
}