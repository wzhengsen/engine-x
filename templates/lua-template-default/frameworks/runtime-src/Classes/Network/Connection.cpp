#include "Connection.h"
#include <sstream>
using namespace StarryX::Network;

constexpr uint32_t Connection::MessageBuffer::InitMsgLen;
bool Connection::MessageBuffer::ParseData(const void* buff, size_t len) {
    // 数据追加到msgBuff后。
	if (Append(buff, len)) {
		const uint32_t flagLen = *static_cast<const uint32_t*>(buffer);
		if (flagLen <= Message::MaxMsgLen && flagLen) {
			return true;
		}
        // 大于Message::MaxMsgLen或等于0的头部信息不合法。
        size = 0;
	}
	return false;
}

bool Connection::MessageBuffer::Append(const void* src,size_t len) {
	if (!len || len + size > MaxMsgLen) {
        // 总消息长度超限，不可追加，返回失败。
		return false;
	}
	if (len + size > capacity) {
        // 若当前容量不够分配，考虑扩展容量。
		while (capacity <= MaxMsgLen) {
            // 尝试扩大2倍。
			capacity *= 2;
			if (len + size <= capacity) {
                buffer = ::realloc(buffer, capacity);
				break;
			}
		}
	}
    // 在尾部追加。
	::memcpy(static_cast<uint8_t*>(buffer) + size, src, len);
	size += len;
	return true;
}

const void* Connection::MessageBuffer::GetData(size_t& len) const noexcept {
    len = GetLen();
    if (len) {
        return static_cast<uint8_t*>(buffer) + sizeof(uint32_t);
    }
    return nullptr;
}

uint32_t Connection::MessageBuffer::GetLen() const noexcept {
    if (size < sizeof(uint32_t)) {
        // 长度未达到头部标识的最低字节数。
        return 0;
    }
    const uint32_t flagLen = *reinterpret_cast<const uint32_t*>(buffer);
    if (!flagLen || flagLen > size - sizeof(uint32_t) || flagLen > size) {
        // 头部标识长度为0或大于长度。
        return 0;
    }
    return flagLen;
}

void Connection::MessageBuffer::Cut(size_t len) noexcept {
	if (size < len + sizeof(uint32_t)) {
        size = 0;
		return;
	}
	::memmove(buffer, static_cast<uint8_t*>(buffer) + len + sizeof(uint32_t), size - len - sizeof(uint32_t));
	size -= (len + sizeof(uint32_t));
}

Connection::MessageBuffer::MessageBuffer(size_t initSize) noexcept {
    buffer = ::malloc(initSize);
	capacity = initSize;
}

Connection::MessageBuffer::~MessageBuffer() {
	if (buffer) {
		::free(buffer);
		buffer = nullptr;
	}
}

constexpr char Connection::UDP_Header[];
constexpr char Connection::TCP_Header[];
size_t Connection::activeCount = 0;
mg_mgr* Connection::mgMgr = nullptr;
std::map<const mg_connection*, Connection::MessageBuffer> Connection::mgBuffMap = std::map<const mg_connection*, Connection::MessageBuffer>();

Connection::Connection(Type ct) noexcept : ct(ct) {
    activeCount++;
}

Connection::~Connection() {
    activeCount--;
	Close();
	if (mgCon) {
		if (!(mgCon->flags & MG_F_UDP)) {
			mgBuffMap.erase(mgCon);
		}
		mgCon->user_data = nullptr;
	}

	SetHandler(nullptr);
}

void Connection::InitConnection(const std::string& addr, uint16_t port) {
	this->addr = addr;
	this->port = port;

	auto sString = std::stringstream();
	sString << port;

	//添加UPD或TCP头
	connAddr = (ct == TCP ? TCP_Header : UDP_Header) + addr + ":" + sString.str();
    if (!mgMgr) {
        mgMgr = static_cast<mg_mgr*>(::malloc(sizeof(mg_mgr)));
        mg_mgr_init(mgMgr, nullptr);
    }
}

void Connection::Close() const {
	if (mgCon) {
		mgCon->flags |= MG_F_CLOSE_IMMEDIATELY;
	}
    if (!activeCount) {
        CloseMGR();
    }
}

void Connection::CloseMGR() noexcept {
    if (!mgMgr) {
        return;
    }
	mg_mgr_free(mgMgr);
	mgMgr = nullptr;
}

void Connection::Poll() noexcept {
	if (!mgMgr) {
		return;
	}
	mg_mgr_poll(mgMgr, 0);
}

void Connection::MG_EventHandler(mg_connection* nc, int ev, void* ev_data) {
	switch(ev){
	case MG_EV_POLL:
		break;
	case MG_EV_RECV: {
		auto conn = static_cast<Connection*>(nc->user_data);
		if (conn && conn->eventHandler) {
			const char* buf = nc->recv_mbuf.buf;
			auto len = nc->recv_mbuf.len;

			if (nc->flags & MG_F_UDP) {
				if (!len || len > Message::MaxMsgLen) {
					//解析的消息不合法时会关闭该连接
					conn->mgCon->flags |= MG_F_CLOSE_IMMEDIATELY;
					nc->flags |= MG_F_CLOSE_IMMEDIATELY;
					mbuf_remove(&nc->recv_mbuf, nc->recv_mbuf.len);
					return;
				}
                auto info = Info();
				info.event = static_cast<Event>(ev);
				info.conn = nc;
				info.msg->Resize(len);
                ::memcpy(info.msg->GetBuff(), buf, len);
				conn->eventHandler(conn, &info);
			}
			else {
                auto iter = mgBuffMap.find(nc);
                if (iter != mgBuffMap.end()) {
                    const auto ret = iter->second.ParseData(buf, len);
                    if (!ret) {
                        //解析的消息不合法时会关闭该连接
                        nc->flags |= MG_F_CLOSE_IMMEDIATELY;
                        mbuf_remove(&nc->recv_mbuf, nc->recv_mbuf.len);
                        iter->second.Clear();
                        return;
                    }

                    size_t msgLen = 0;
                    do {
                        const void* msgBuff = iter->second.GetData(msgLen);

                        if (msgLen) {
                            auto info = Info();
							info.event = static_cast<Event>(ev);
							info.conn = nc;
							info.msg->Resize(msgLen);
                            ::memcpy(info.msg->GetBuff(), msgBuff, msgLen);
                            iter->second.Cut(msgLen);
							conn->eventHandler(conn, &info);
                        }
                    } while (msgLen);
                }
				else {
					nc->flags |= MG_F_CLOSE_IMMEDIATELY;
					mbuf_remove(&nc->recv_mbuf, nc->recv_mbuf.len);
					return;
				}
			}
		}
		//移除接收缓存
		mbuf_remove(&nc->recv_mbuf, nc->recv_mbuf.len);
		break;
	}
	default:
		break;
	}
}
