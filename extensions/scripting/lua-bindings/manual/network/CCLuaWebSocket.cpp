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
#include "CCLuaWebSocket.h"
using namespace cocos2d::network;

NS_CC_BEGIN
namespace extension {
    void LuaWebSocket::RegisterLuaWebSocketManual(Lua& lua) {
        cocos2d::extension::Lua::Id2Meta[typeid(LuaWebSocket).name()] = sol::usertype_traits<LuaWebSocket*>::metatable();
        auto dep = lua.new_usertype<LuaWebSocket>("deprecated.cocos2d::extension::LuaWebSocket");
        dep[sol::base_classes] = sol::bases<cocos2d::network::WebSocket,cocos2d::extension::LuaObject>();

        sol::table mt = lua.NewClass(sol::usertype_traits<LuaWebSocket*>::metatable(), sol::usertype_traits<LuaObject*>::metatable());
        lua["cc"]["WebSocket"] = mt;
        mt[lua.OOPConfig["__new__"]] = [](const std::string& url, const sol::object& protocols, const sol::object& caFile)->LuaWebSocket* {
            auto ws = new (std::nothrow) LuaWebSocket();
            const auto pType = protocols.get_type();
            std::vector<std::string>* pVec = nullptr;
            std::string caStr = "";
            if (pType == sol::type::table) {
                sol::table pTab = protocols;
                std::vector<std::string> vecP = std::vector<std::string>(pTab.size());
                for (size_t i = 1; i <= pTab.size(); i++) {
                    std::string strP = pTab[i];
                    vecP.emplace_back(strP);
                }
                if (caFile.get_type() != sol::type::nil) {
                    caStr = caFile.as<std::string>();
                }
                pVec = &vecP;
            }
            else if (pType == sol::type::string) {
                caStr = protocols.as<std::string>();
            }
            if (!ws->init(*ws, url, pVec, caStr)) {
                delete ws;
                ws = nullptr;
            }
            return ws;
        };
        mt["Send"] = [](lua_State* L)->int {
            LuaWebSocket** ws = reinterpret_cast<LuaWebSocket**>(lua_touserdata(L, 1));
            if (ws && *ws) {
                size_t strLen = 0;
                const unsigned char* str = reinterpret_cast<const unsigned char*>(luaL_checklstring(L, 2, &strLen));
                (*ws)->send(str, static_cast<unsigned int>(strLen));
            }
            return 0;
        };
        mt["Close"] = sol::overload(&LuaWebSocket::close, [](LuaWebSocket* ws, bool async) {
            if (async) {
                return ws->closeAsync();
            }
            ws->close();
        });

        const std::string& set = lua.OOPConfig["set"];
        const std::string& get = lua.OOPConfig["get"];
        const std::string& _static = lua.OOPConfig["Qualifiers"]["static"];
        mt[get]["ReadyState"] = &LuaWebSocket::getReadyState;
        mt[get]["Url"] = &LuaWebSocket::getUrl;
        mt[get]["Protocol"] = &LuaWebSocket::getProtocol;
        mt[set]["OpenHandler"] = &LuaWebSocket::SetOpenHandler;
        mt[set]["MessageHandler"] = &LuaWebSocket::SetMessageHandler;
        mt[set]["CloseHandler"] = &LuaWebSocket::SetCloseHandler;
        mt[set]["ErrorHandler"] = &LuaWebSocket::SetErrorHandler;


        mt[_static]["State"] = lua.NewEnum(lua.create_table_with(
            "CONNECTING", WebSocket::State::CONNECTING,
            "OPEN", WebSocket::State::OPEN,
            "CLOSED", WebSocket::State::CLOSED,
            "CLOSING", WebSocket::State::CLOSING
        ));
        mt[_static]["ErrorCode"] = lua.NewEnum(lua.create_table_with(
            "CONNECTION_FAILURE", WebSocket::ErrorCode::CONNECTION_FAILURE,
            "TIME_OUT", WebSocket::ErrorCode::TIME_OUT,
            "UNKNOWN", WebSocket::ErrorCode::UNKNOWN
        ));
    }
    void LuaWebSocket::SetOpenHandler(const std::function<void(LuaWebSocket*)>& handler) {
        _openHandler = handler;
    }
    void LuaWebSocket::SetMessageHandler(const std::function<void(LuaWebSocket*, const std::string_view&, bool)>& handler) {
        _messageHandler = handler;
    }
    void LuaWebSocket::SetCloseHandler(const std::function<void(LuaWebSocket*)>& handler) {
        _closeHandler = handler;
    }
    void LuaWebSocket::SetErrorHandler(const std::function<void(LuaWebSocket*, const WebSocket::ErrorCode&)>& handler) {
        _errorHandler = handler;
    }
    void LuaWebSocket::onOpen(WebSocket*) {
        if (_openHandler) {
            _openHandler(this);
        }
    }
    void LuaWebSocket::onMessage(WebSocket*, const WebSocket::Data& data) {
        if (_messageHandler) {
            _messageHandler(this, std::string_view(data.bytes, static_cast<size_t>(data.len)), data.isBinary);
        }
    }
    void LuaWebSocket::onClose(WebSocket*) {
        if (_closeHandler) {
            _closeHandler(this);
        }
    }
    void LuaWebSocket::onError(WebSocket*, const WebSocket::ErrorCode& e) {
        if (_errorHandler) {
            _errorHandler(this, e);
        }
    }
}
NS_CC_END