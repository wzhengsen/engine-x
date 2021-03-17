/****************************************************************************
 Copyright (c) wzhengsen

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
#include "scripting/lua-bindings/CCLua.h"
#include "network/WebSocket.h"
using namespace cocos2d::network;

NS_CC_BEGIN
namespace extension {
    class LuaWebSocket : public WebSocket, public WebSocket::Delegate, public LuaObject {
    public:
        static void RegisterLuaWebSocketManual(Lua&);
    private:
        void SetOpenHandler(std::function<void(LuaWebSocket*)>);
        void SetMessageHandler(std::function<void(LuaWebSocket*, const std::string_view&, bool isBin)>);
        void SetCloseHandler(std::function<void(LuaWebSocket*)>);
        void SetErrorHandler(std::function<void(LuaWebSocket*, const WebSocket::ErrorCode&)>);

        std::function<void(LuaWebSocket*)> _openHandler = nullptr;
        std::function<void(LuaWebSocket*, const std::string_view&, bool)> _messageHandler = nullptr;
        std::function<void(LuaWebSocket*)> _closeHandler = nullptr;
        std::function<void(LuaWebSocket*, const WebSocket::ErrorCode&)> _errorHandler = nullptr;

        void onOpen(WebSocket*);
        void onMessage(WebSocket*, const WebSocket::Data&);
        void onClose(WebSocket*);
        void onError(WebSocket*, const WebSocket::ErrorCode&);
    };
}
NS_CC_END