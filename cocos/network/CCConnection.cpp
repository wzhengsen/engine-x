/****************************************************************************
 Copyright (c) 2021 wzhengsen

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
#include "network/CCConnection.h"

using namespace cocos2d;
using namespace yasio::inet;

network::Connection::Connection() {
    ServiceVec.push_back(&_service);

    _service.set_option(YOPT_C_LFBFD_PARAMS, 0, 65535, 0, sizeof(uint32_t), 0);
    _service.set_option(YOPT_C_LFBFD_IBTS, 0, sizeof(uint32_t));
    SetHeartBeat();

    if (++InstanceCount == 1) {
        io_service::init_globals([](int level, const char* msg) {
            std::string text = "yasio Level " + std::to_string(level) + "->" + msg;
            cocos2d::log(text.c_str());
        });
        Director::getInstance()->getScheduler()->schedule([this](float) {
            // Copy it,Avoid destroying the service in the next message dispatch.
            auto tempSV = ServiceVec;
            for (auto s : tempSV) {
                s->dispatch();
            }
        }, const_cast<char*>(SchedulerId.data()), 0.02f, false, SchedulerId.data());
    }
}

network::Connection::~Connection() {
    _service.stop();
    auto s = std::find(ServiceVec.begin(), ServiceVec.end(), &_service);
    if (s != ServiceVec.end()) {
        ServiceVec.erase(s);
    }
    if (--InstanceCount == 0) {
        io_service::cleanup_globals();
        Director::getInstance()->getScheduler()->unschedule(SchedulerId.data(), const_cast<char*>(SchedulerId.data()));
    }
}

void network::Connection::SetHeartBeat(size_t interalMS, size_t times) {
    _service.set_option(YOPT_S_TCP_KEEPALIVE, 0, static_cast<int>(interalMS / 1000), static_cast<int>(interalMS / 1000), static_cast<int>(times));
}

void network::Connection::Open() {
    _service.open(0, _kind);
}

void network::Connection::Close() {
    _service.close(0);
}

network::Server::Server(const std::string_view& addr, uint16_t port, Kind kind) : Connection() {
    switch (kind) {
    case Kind::TCP:
        _kind = YCK_TCP_SERVER;
        break;
    case Kind::UDP:
        _kind = YCK_UDP_SERVER;
        break;
    case Kind::KCP:
        _kind = YCK_KCP_SERVER;
        break;
    default:
        break;
    }
    _service.set_option(YOPT_C_LOCAL_HOST, 0, addr.data());
    _service.set_option(YOPT_C_LOCAL_PORT, 0, static_cast<int>(port));
    _service.start([this](event_ptr&& ev) {
        auto transport = ev->transport();
        switch (ev->kind()) {
        case YEK_CONNECT_RESPONSE: {
            auto suc = !ev->status();
            auto ep = transport->remote_endpoint();
            auto ip = ep.ip();
            auto port = ep.port();
            this->OnConnect(transport, suc);
            if (suc) {
                _transports.emplace(transport->id(), transport);
            }
#if CC_ENABLE_LUA_BINDING
            if (this->_connectHandler) {
                this->_connectHandler(this, transport, suc, ip, port);
            }
#endif
            break;
        }
        case YEK_CONNECTION_LOST: {
            this->OnLose(transport);
            auto iter = _transports.find(transport->id());
            if (iter != _transports.end()) {
                _transports.erase(iter);
            }
#if CC_ENABLE_LUA_BINDING
            if (this->_loseHandler) {
                this->_loseHandler(this, transport);
            }
#endif
            break;
        }
        case YEK_PACKET: {
            auto& packet = ev->packet();
            std::string msg = { packet.data(), packet.size() };
            this->OnMessage(ev->transport(), msg);
#if CC_ENABLE_LUA_BINDING
            if (this->_messageHandler) {
                this->_messageHandler(this, transport, msg);
            }
#endif
            break;
        }
        default:
            break;
        }
    });
}

network::Server::~Server() {
    for (auto item : _transports) {
        if (_service.is_open(item.second)) {
            OnLose(item.second);
#if CC_ENABLE_LUA_BINDING
            if (_loseHandler) {
                _loseHandler(this, item.second);
            }
#endif
        }
    }
    _transports.clear();
}

int network::Server::Send(transport_handle_t transport, const std::string& msg) {
    const auto size = static_cast<uint32_t>(msg.size());
    auto nSize = ::htonl(size + sizeof(uint32_t));
    std::unique_ptr<char[]> buff = std::make_unique<char[]>(size + sizeof(uint32_t));
    std::memcpy(buff.get(), &nSize, sizeof(uint32_t));
    std::memcpy(buff.get() + sizeof(uint32_t), msg.data(), size);
    return _service.write(transport, buff.get(), size + sizeof(uint32_t));
}

void network::Server::Close(transport_handle_t transport) {
    _service.close(transport);
}

network::Client::Client(const std::string_view& addr, uint16_t port, Kind kind) : Connection() {
    switch (kind) {
    case Kind::TCP:
        _kind = YCK_TCP_CLIENT;
        break;
    case Kind::UDP:
        _kind = YCK_UDP_CLIENT;
        break;
    case Kind::KCP:
        _kind = YCK_KCP_CLIENT;
        break;
    default:
        break;
    }
    _service.set_option(YOPT_C_REMOTE_HOST, 0, addr.data());
    _service.set_option(YOPT_C_REMOTE_PORT, 0, static_cast<int>(port));
    _service.start([this](event_ptr&& ev) {
        switch (ev->kind()) {
        case YEK_CONNECT_RESPONSE: {
            auto suc = !ev->status();
            this->_transport = ev->transport();
            this->OnConnect(suc);
#if CC_ENABLE_LUA_BINDING
            if (this->_connectHandler) {
                this->_connectHandler(this, suc);
            }
#endif
            break;
        }
        case YEK_CONNECTION_LOST:
            this->_transport = nullptr;
            this->OnLose();
#if CC_ENABLE_LUA_BINDING
            if (this->_loseHandler) {
                this->_loseHandler(this);
            }
#endif
            break;
        case YEK_PACKET: {
            auto& packet = ev->packet();
            std::string msg = { packet.data(), packet.size() };
            this->OnMessage(msg);
#if CC_ENABLE_LUA_BINDING
            if (this->_messageHandler) {
                this->_messageHandler(this, msg);
            }
#endif
            break;
        }
        default:
            break;
        }
    });
}

network::Client::~Client() {
    if (_transport && _service.is_open(_transport)) {
        _transport = nullptr;
        OnLose();
#if CC_ENABLE_LUA_BINDING
        if (_loseHandler) {
            _loseHandler(this);
        }
#endif
    }
}

int network::Client::Send(const std::string& msg) {
    const auto size = static_cast<uint32_t>(msg.size());
    auto nSize = ::htonl(size + sizeof(uint32_t));
    std::unique_ptr<char[]> buff = std::make_unique<char[]>(size + sizeof(uint32_t));
    std::memcpy(buff.get(), &nSize, sizeof(uint32_t));
    std::memcpy(buff.get() + sizeof(uint32_t), msg.data(), size);
    return _service.write(_transport, buff.get(), size + sizeof(uint32_t));
}

void network::Client::Open(size_t mSec) {
    _service.set_option(YOPT_S_CONNECT_TIMEOUT, static_cast<int>(mSec / 1000));
    Open();
}