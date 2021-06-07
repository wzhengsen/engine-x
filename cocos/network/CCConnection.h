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
#pragma once
#include "yasio/yasio.hpp"
#include "scripting/lua-bindings/CCLuaObject.h"

NS_CC_BEGIN
namespace network {
#if CC_ENABLE_LUA_BINDING
    class CC_DLL Connection : public extension::LuaObject {
#else
    class CC_DLL Connection {
#endif
    public:
        enum class Kind {
            TCP, UDP, KCP
        };
        void Open();
        void Close();
        void SetHeartBeat(size_t interalMS = 15000,size_t times = 2);
        virtual ~Connection();
    protected:
        Connection();
        int _kind = 0;
        yasio::inet::io_service _service = {};
    private:
        inline static std::vector<yasio::inet::io_service*> ServiceVec = {};
        inline static size_t InstanceCount = 0;
        inline static const std::string_view SchedulerId = "CCConnection dispatch";
        Connection(const Connection&) = delete;
        Connection& operator=(const Connection&) = delete;
    };

    class CC_DLL Server : public Connection {
#if CC_ENABLE_LUA_BINDING
    public:
        typedef std::function<void(Server*, yasio::inet::transport_handle_t, bool, const std::string&, uint16_t)> SC_Handler;
        typedef std::function<void(Server*, yasio::inet::transport_handle_t, const std::string&)> SM_Handler;
        typedef std::function<void(Server*, yasio::inet::transport_handle_t)> SL_Handler;
        void SetConnectHandler(const SC_Handler& handler) { _connectHandler = handler; }
        void SetMessageHandler(const SM_Handler& handler) { _messageHandler = handler; }
        void SetLoseHandler(const SL_Handler& handler) { _loseHandler = handler; }
    protected:
        SC_Handler _connectHandler = nullptr;
        SM_Handler _messageHandler = nullptr;
        SL_Handler _loseHandler = nullptr;
#endif
    public:
        Server(const std::string_view& addr, uint16_t port, Kind kind = Kind::TCP);
        Server(uint16_t port, Kind kind = Kind::TCP) : Server("0.0.0.0", port, kind) {}
        ~Server();

        int Send(yasio::inet::transport_handle_t transport, const std::string& msg);
        void Close(yasio::inet::transport_handle_t transport);

    protected:
        std::unordered_map<uint32_t, yasio::inet::transport_handle_t> _transports = {};
        void OnConnect(yasio::inet::transport_handle_t transport, bool suc) {};
        void OnMessage(yasio::inet::transport_handle_t transport, const std::string& sv) {};
        void OnLose(yasio::inet::transport_handle_t transport) {};
    };

    class CC_DLL Client : public Connection {
#if CC_ENABLE_LUA_BINDING
    public:
        typedef std::function<void(Client*,bool)> CC_Handler;
        typedef std::function<void(Client*, const std::string&)> CM_Handler;
        typedef std::function<void(Client*)> CL_Handler;
        void SetConnectHandler(const CC_Handler& handler) { _connectHandler = handler; }
        void SetMessageHandler(const CM_Handler& handler) { _messageHandler = handler; }
        void SetLoseHandler(const CL_Handler& handler) { _loseHandler = handler; }
    protected:
        CC_Handler _connectHandler = nullptr;
        CM_Handler _messageHandler = nullptr;
        CL_Handler _loseHandler = nullptr;
#endif
    public:
        Client(const std::string_view& addr, uint16_t port, Kind kind = Kind::TCP);
        ~Client();
        int Send(const std::string& msg);

        /**
         * @brief       Open the connection with millsecond timeout.
         * @param mSec  The millseconds timeout you wish.
         *              The millseconds will be converted to seconds in factly.
         *              Keep millsecond implementation for future support of second.
        */
        void Open(size_t mSec);
        using Connection::Open;

    protected:
        void OnConnect(bool suc) {};
        void OnMessage(const std::string& s) {};
        void OnLose() {};
        yasio::inet::transport_handle_t _transport = nullptr;
    };
}
NS_CC_END