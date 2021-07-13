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
#include "scripting/lua-bindings/manual/CCLuaConvertSol.hpp"
#include "network/HttpClient.h"
using namespace cocos2d::network;

NS_CC_BEGIN
namespace extension {
    class LuaHttpRequest : public HttpRequest {
    public:
        static void RegisterLuaHttpRequestManual(Lua&);
    private:
        void AddHeaders(const sol::table& headers);
        void SetHeaders(const sol::table& headers);
        void SetData(const std::string_view& data);
        void SetHandler(const std::function<void(LuaHttpRequest*, int, const HttpResponse::ResponseHeaderMap&, const std::string_view&)>& handler);
        void Send(const std::string_view& url);
        void Get(const std::string_view& url);
        void Post(const std::string_view& url);
        void Delete(const std::string_view& url);
        void Put(const std::string_view& url);

        std::function<void(LuaHttpRequest*, int, const HttpResponse::ResponseHeaderMap&, const std::string_view&)> _handler = nullptr;
        std::unordered_map<std::string, std::string> _headersMap = {};
    };
}
NS_CC_END