#include "Server.h"
#include <algorithm>
using namespace StarryX::Network;
Server::Server(Type ct) noexcept : Connection(ct) {}

Server::~Server() {
    for (auto conn : conVec) {
        if (conn) {
            if (!(conn->flags & MG_F_UDP)) {
                mgBuffMap.erase(conn);
            }
            conn->user_data = nullptr;
            conn->flags |= MG_F_CLOSE_IMMEDIATELY;
        }
    }
}

void Server::Send(mg_connection* mgCon,const void* buff, size_t len) const {
	if (State::Closed != cs && std::find(conVec.cbegin(), conVec.cend(), mgCon) != conVec.cend()) {
		const uint32_t u32Len = static_cast<uint32_t>(len);
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(u32Len + sizeof(u32Len));
			mg_send(mgCon, &nu32Len, sizeof(u32Len));
		}
		mg_send(mgCon, buff, u32Len);
	}
}

void Server::Send(mg_connection* mgCon,const char* buff) const {
	if (State::Closed != cs && std::find(conVec.cbegin(), conVec.cend(), mgCon) != conVec.cend()) {
		const uint32_t len = static_cast<uint32_t>(::strlen(buff));
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(len + sizeof(len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, buff, len);
	}
}

void Server::Send(mg_connection* mgCon,const std::string& str) const {
	if (State::Closed != cs && std::find(conVec.cbegin(), conVec.cend(), mgCon) != conVec.cend()) {
		const uint32_t len = static_cast<uint32_t>(str.length());
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(len + sizeof(len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, str.c_str(), len);
	}
}

void Server::Send(mg_connection* mgCon, const Message& msg) const {
	if (State::Closed != cs && std::find(conVec.cbegin(), conVec.cend(), mgCon) != conVec.cend()) {
        const uint32_t len = msg.GetLen();
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(len + sizeof(len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, msg.GetBuff(), len);
	}
}

bool Server::Bind(const std::string& addr, uint16_t port) {
	if (State::Closed != cs) {
		return false;
	}
	InitConnection(addr, port);
	mgCon = mg_bind(mgMgr, connAddr.c_str(), MG_EventHandler);
	if (!mgCon) {
		return false;
	}
	mgCon->user_data = this;
	cs = State::Listening;
	return true;
}

bool Server::Bind(uint16_t port) {
	return Bind("", port);
}

void Server::MG_EventHandler(mg_connection* nc, int ev, void* ev_data) {
	Connection::MG_EventHandler(nc, ev, ev_data);

	switch (ev) {
	case MG_EV_ACCEPT:
	case MG_EV_CLOSE: {
		auto conn = static_cast<Server*>(nc->user_data);
		if (conn) {
			if (ev == MG_EV_ACCEPT) {
				if (!(nc->flags & MG_F_UDP)) {
					mgBuffMap.emplace(nc, MessageBuffer::InitMsgLen);
				}
				conn->conVec.push_back(nc);
			}
			else if (ev == MG_EV_CLOSE) {
				if (!(nc->flags & MG_F_UDP)) {
					mgBuffMap.erase(nc);
				}
				auto it = std::find(conn->conVec.cbegin(), conn->conVec.cend(), nc);
				if (it != conn->conVec.cend()) {
					//conn断开连接
					conn->conVec.erase(it);
					nc->user_data = nullptr;
				}
				else if (conn->mgCon == nc){
					//server被关闭
					conn->cs = State::Closed;
					conn->mgCon->user_data = nullptr;
				}
			}
			if (conn->eventHandler) {
				auto info = Info();
				info.event = static_cast<Event>(ev);
				if (conn->mgCon) {
					info.conn = nc;
				}

				if (ev == MG_EV_ACCEPT) {
					char dst[61] = {};
					::memset(dst, 0, sizeof(dst));
					mg_conn_addr_to_str(nc, dst, sizeof(dst) - 1, MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_REMOTE);
					const auto port = ntohs(nc->sa.sin.sin_port);
					info.addr = dst;
					info.port = port;
				}
				conn->eventHandler(conn, &info);
			}
		}
		break;
	}
	default:
		break;
	}
}

void Server::Close() const {
	for (auto it = conVec.cbegin(); it != conVec.cend(); it++) {
		(*it)->flags |= MG_F_CLOSE_IMMEDIATELY;
	}
	Connection::Close();
}

void Server::Close(mg_connection* mgCon) const {
	auto it = std::find(conVec.cbegin(), conVec.cend(), mgCon);
	if (it != conVec.cend()) {
		mgCon->flags |= MG_F_CLOSE_IMMEDIATELY;
	}
}