/****************************************************************************
 Copyright (c) 2014-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

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

#ifndef __COCOS2D_UI_WEBVIEWIMPL_WIN32_H_
#define __COCOS2D_UI_WEBVIEWIMPL_WIN32_H_
 /// @cond DO_NOT_SHOW

#include <string>
#include "include/base/cef_lock.h"
#include "include/cef_client.h"
#include "include/cef_parser.h"

namespace cocos2d {

    class Data;
    class Renderer;
    class Mat4;

    namespace ui {

        class WebView;

        class WebViewImpl :
            public CefClient,
            public CefLifeSpanHandler,
            public CefLoadHandler,
            public CefContextMenuHandler,
            public CefRequestHandler {
        public:
            WebViewImpl(WebView* webView);
            virtual ~WebViewImpl();
            void setJavascriptInterfaceScheme(const std::string& scheme);
            void loadData(const cocos2d::Data& data,
                const std::string& MIMEType,
                const std::string& encoding,
                const std::string& baseURL);
            void loadHTMLString(const std::string& string, const std::string& baseURL);
            void loadURL(const std::string& url);
            void loadURL(const std::string& url, bool cleanCachedData);
            void loadFile(const std::string& fileName);
            void stopLoading();
            void reload();
            bool canGoBack();
            bool canGoForward();
            void goBack();
            void goForward();
            void evaluateJS(const std::string& js);
            void setScalesPageToFit(const bool scalesPageToFit);
            virtual void draw(cocos2d::Renderer* renderer, cocos2d::Mat4 const& transform, uint32_t flags);
            virtual void setVisible(bool visible);
            void setBounces(bool bounces);
            virtual void setOpacityWebView(float opacity);
            virtual float getOpacityWebView() const;
            virtual void setBackgroundTransparent();

        public:

            virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE { return this; }
            virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE { return this; }
            virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() OVERRIDE { return this; }
            virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE { return this; }

            // CefLifeSpanHandler methods:
            virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
            virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
            virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
            virtual bool OnBeforePopup(
                CefRefPtr<CefBrowser> browser,
                CefRefPtr<CefFrame> frame,
                const CefString& target_url,
                const CefString& target_frame_name,
                CefLifeSpanHandler::WindowOpenDisposition target_disposition,
                bool user_gesture,
                const CefPopupFeatures& popupFeatures,
                CefWindowInfo& windowInfo,
                CefRefPtr<CefClient>& client,
                CefBrowserSettings& settings,
                CefRefPtr<CefDictionaryValue>& extra_info,
                bool* no_javascript_access
            ) OVERRIDE;

            // CefLoadHandler methods:
            virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,
                CefRefPtr<CefFrame> frame,
                int httpStatusCode) OVERRIDE;
            virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
                CefRefPtr<CefFrame> frame,
                ErrorCode errorCode,
                const CefString& errorText,
                const CefString& failedUrl) OVERRIDE;

            // CefContextMenuHandler methods:
            virtual void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
                CefRefPtr<CefFrame> frame,
                CefRefPtr<CefContextMenuParams> params,
                CefRefPtr<CefMenuModel> model) OVERRIDE;

            // CefRequestHandler methods:
            bool OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
                CefRefPtr<CefFrame> frame,
                CefRefPtr<CefRequest> request,
                bool user_gesture,
                bool is_redirect) OVERRIDE;

            void DestroyCefBrowser();
        private:
            // Create a new browser and native window.
            void CreateCefBrowser();
            void ResizeMoveCefBrowser();
            bool BrowserValid() const {
                return mBrowser && !mIsClosed && !mIsClosing;
            };

            static std::string GetDataURI(const std::string& data, const std::string& mime_type) {
                return "data:" + mime_type +
                    ";base64," + CefURIEncode(CefBase64Encode(data.data(), data.size()), false).ToString();
            }

            WebView* _webView;
            HWND mHWND = nullptr;
            CefRefPtr<CefBrowser> mBrowser = nullptr;
            bool mIsClosing = false;
            bool mIsClosed = false;
            bool mScalesPageToFit = false;
            bool mVisible = true;
            std::string mJsScheme = std::string();

            // Include filename or url or string.
            std::string mUrl = std::string();

            // Include the default reference counting implementation.
            IMPLEMENT_REFCOUNTING(WebViewImpl);
            DISALLOW_COPY_AND_ASSIGN(WebViewImpl);
        };
    } // namespace ui
}//namespace cocos2d

/// @endcond
#endif /* __COCOS2D_UI_WEBVIEWIMPL_WIN32_H_ */