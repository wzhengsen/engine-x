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
#include "CCLuaHttpRequest.h"
using namespace cocos2d::network;

NS_CC_BEGIN
namespace extension {
    void LuaHttpRequest::RegisterLuaHttpRequestManual(Lua& lua) {
        auto ut = lua.NewUserType<LuaHttpRequest>("cc", "HttpRequest", false);
        Lua::SetBases(ut, sol::bases<Ref, LuaObject>());
        ut[sol::meta_function::construct] = []() {
            return new (std::nothrow) LuaHttpRequest();
        };
        ut["Timeout"] = sol::writeonly_property(&LuaHttpRequest::SetTimeout);
        ut["Async"] = sol::writeonly_property(&LuaHttpRequest::SetAsync);
        ut["Headers"] = sol::writeonly_property(&LuaHttpRequest::SetHeaders);
        ut["Data"] = sol::writeonly_property(&LuaHttpRequest::SetData);
        ut["Handler"] = sol::writeonly_property(&LuaHttpRequest::SetHandler);
        ut["Get"] = &LuaHttpRequest::Get;
        ut["Post"] = &LuaHttpRequest::Post;
        ut["Delete"] = &LuaHttpRequest::Delete;
        ut["Put"] = &LuaHttpRequest::Put;
    }

    void LuaHttpRequest::AddHeaders(const sol::table& headers) {
        headers.for_each([this](const sol::object& key, const sol::object& value) {
            std::string sKey = key.as<std::string>();
            std::string sValue = value.as<std::string>();
            auto iter = _headersMap.find(sKey);
            if (iter == _headersMap.end()) {
                _headersMap[sKey] = sValue;
            }
            else {
                _headersMap[sKey] += ("," + sValue);
            }
        });
    }

    void LuaHttpRequest::SetHeaders(const sol::table& headers) {
        _headers.clear();
        _headersMap.clear();
        AddHeaders(headers);
    }

    void LuaHttpRequest::SetData(const std::string_view& data) {
        setRequestData(data.data(), data.length());
    }

    void LuaHttpRequest::SetHandler(const std::function<void(LuaHttpRequest*, int, const std::string_view&, const std::string_view&)>& handler) {
        _handler = handler;
    }

    void LuaHttpRequest::Send(const std::string_view& url) {
        setUrl({ url.data(),url.length() });
        for (auto& pair : _headersMap) {
            _headers.emplace_back(pair.first + ":" + pair.second);
        }
        setResponseCallback([this](HttpClient*, HttpResponse* response) {
            if (_handler) {
                const std::vector<char>* header = response->getResponseHeader();
                const std::string_view svHeader = { header->data(),header->size() };

                const std::vector<char>* data = response->getResponseData();
                const std::string_view svData = { data->data(),data->size() };

                _handler(this, response->getResponseCode(), svHeader, svData);
            }

            release();
        });
        HttpClient::getInstance()->sendImmediate(this);
    }

    void LuaHttpRequest::Get(const std::string_view& url) {
        setRequestType(Type::GET);
        Send(url);
    }

    void LuaHttpRequest::Post(const std::string_view& url) {
        setRequestType(Type::POST);
        Send(url);
    }

    void LuaHttpRequest::Delete(const std::string_view& url) {
        setRequestType(Type::DELETE);
        Send(url);
    }

    void LuaHttpRequest::Put(const std::string_view& url) {
        setRequestType(Type::PUT);
        Send(url);
    }
}
NS_CC_END