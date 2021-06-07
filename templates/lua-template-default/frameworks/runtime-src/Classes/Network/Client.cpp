#include "Client.h"
using namespace StarryX::Network;
Client::Client(Type ct) noexcept : Connection(ct) {}

bool Client::Connect(const std::string& addr, uint16_t port, bool broadcast/* = false*/, uint32_t timeout/* = ConnectTimeout*/) {
	if (State::Closed != cs) {
		return false;
	}
	if (broadcast && ct == TCP) {
		return false;
	}
	InitConnection(addr, port);
	if (!broadcast) {
		mgCon = mg_connect(mgMgr, connAddr.c_str(), MG_EventHandler);
	}
	else {
		auto opts = mg_connect_opts();
		::memset(&opts, 0, sizeof(opts));
		opts.flags |= MG_F_ENABLE_BROADCAST;
		mgCon = mg_connect_opt(mgMgr, connAddr.c_str(), MG_EventHandler, opts);
	}
	if (!mgCon) {
		return false;
	}
	mgCon->user_data = this;
	cs = State::Connecting;
	//设定超时
	mg_set_timer(mgCon, mg_time() + static_cast<double>(timeout / 1000));
	return true;
}

void Client::Send(const void* buff, size_t len) const noexcept {
	if (State::Closed != cs && mgCon) {
		uint32_t u32Len = static_cast<uint32_t>(len);
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(u32Len + sizeof(u32Len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, buff, u32Len);
	}
}

void Client::Send(const char* buff) const noexcept {
	if (State::Closed != cs && mgCon) {
		uint32_t len = static_cast<uint32_t>(::strlen(buff));
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(len + sizeof(len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, buff, len);
	}
}

void Client::Send(const std::string& str) const noexcept {
	if (State::Closed != cs && mgCon) {
		uint32_t len = static_cast<uint32_t>(str.length());
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(len + sizeof(len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, str.c_str(), len);
	}
}

void Client::Send(const Message& msg) const noexcept {
	if (State::Closed != cs && mgCon) {
        uint32_t len = msg.GetLen();
		if (!(mgCon->flags & MG_F_UDP)) {
            // 先发送一次头部。
			const auto nu32Len = htonl(len + sizeof(len));
			mg_send(mgCon, &nu32Len, sizeof(nu32Len));
		}
		mg_send(mgCon, msg.GetBuff(), len);
	}
}


void Client::MG_EventHandler(mg_connection* nc, int ev, void* ev_data) {
	//先交由基类处理
	Connection::MG_EventHandler(nc, ev, ev_data);

	switch (ev) {
	case MG_EV_TIMER:
		nc->flags |= MG_F_CLOSE_IMMEDIATELY;
		break;
	case MG_EV_CONNECT: {
		if (!(nc->flags & MG_F_UDP)) {
			mgBuffMap.emplace(nc, MessageBuffer::InitMsgLen);
		}
	}
	case MG_EV_CLOSE: {
		auto conn = static_cast<Client*>(nc->user_data);
		if (conn) {
			if (ev == MG_EV_CONNECT) {
				//及时连接，清除超时计时器
				mg_set_timer(nc, 0);
				if (!*static_cast<bool*>(ev_data)) {
					conn->cs = State::Connected;
				}
			}
			else if (ev == MG_EV_CLOSE) {
				conn->cs = State:: Closed;
				conn->mgCon->user_data = nullptr;
				conn->mgCon = nullptr;
				nc->user_data = nullptr;
				if (!(nc->flags & MG_F_UDP)) {
					mgBuffMap.erase(nc);
				}
			}

			if (conn->eventHandler) {
				auto info = Info();
				info.event = static_cast<Event>(ev);
				info.conn = nc;
				if (ev == MG_EV_CONNECT) {
					info.suc = !*static_cast<bool*>(ev_data);
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