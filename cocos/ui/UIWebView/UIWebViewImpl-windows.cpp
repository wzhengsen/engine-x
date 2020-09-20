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

#include "platform/CCPlatformConfig.h"

 // Webview not available on tvOS
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "UIWebViewImpl-windows.h"
#include "renderer/CCRenderer.h"
#include "base/CCDirector.h"
#include "platform/CCGLView.h"
#include "platform/CCFileUtils.h"
#include "ui/UIWebView/UIWebView.h"
#include "ui/UIHelper.h"
#include "include/cef_parser.h"
#include "include/base/cef_scoped_ptr.h"
#include "include/cef_browser.h"
#include "include/wrapper/cef_helpers.h"


namespace cocos2d {
    namespace ui {
        WebViewImpl::WebViewImpl(WebView* webView) :
            _webView(webView) {
            CreateCefBrowser();
        }

        WebViewImpl::~WebViewImpl() {}

        void WebViewImpl::setJavascriptInterfaceScheme(const std::string& scheme) {
            mJsScheme = scheme;
        }

        void WebViewImpl::loadData(const Data& data,
            const std::string& MIMEType,
            const std::string& encoding,
            const std::string& baseURL) {
            std::string dataString(reinterpret_cast<char*>(data.getBytes()), static_cast<unsigned int>(data.getSize()));
            mUrl = GetDataURI(dataString, MIMEType);
            if (BrowserValid()) {
                mBrowser->GetMainFrame()->LoadURL(mUrl);
            }
        }

        void WebViewImpl::loadHTMLString(const std::string& string, const std::string& baseURL) {
            mUrl = GetDataURI(string, "text/html");
            if (BrowserValid()) {
                mBrowser->GetMainFrame()->LoadURL(mUrl);
            }
        }

        void WebViewImpl::loadURL(const std::string& url) {
            loadURL(url, false);
        }

        void WebViewImpl::loadURL(const std::string& url, bool cleanCachedData) {
            mUrl = url;
            if (BrowserValid()) {
                mBrowser->GetMainFrame()->LoadURL(mUrl);
            }
        }

        void WebViewImpl::loadFile(const std::string& fileName) {
            loadURL(cocos2d::FileUtils::getInstance()->fullPathForFilename(fileName), false);
        }

        void WebViewImpl::stopLoading() {
            if (BrowserValid()) {
                mBrowser->StopLoad();
            }
        }

        void WebViewImpl::reload() {
            if (BrowserValid()) {
                mBrowser->ReloadIgnoreCache();
            }
        }

        bool WebViewImpl::canGoBack() {
            if (BrowserValid()) {
                return mBrowser->CanGoBack();
            }
            return false;
        }

        bool WebViewImpl::canGoForward() {
            if (BrowserValid()) {
                return mBrowser->CanGoForward();
            }
            return false;
        }

        void WebViewImpl::goBack() {
            if (BrowserValid()) {
                mBrowser->GoBack();
            }
        }

        void WebViewImpl::goForward() {
            if (BrowserValid()) {
                mBrowser->GoForward();
            }
        }

        void WebViewImpl::evaluateJS(const std::string& js) {
            if (BrowserValid()) {
                mBrowser->GetMainFrame()->ExecuteJavaScript(js, "", 0);
            }
        }

        void WebViewImpl::setBounces(bool bounces) {}

        static double GetDeviceScaleFactor() {
            static double scale_factor = 1.0;
            static bool initialized = false;

            if (!initialized) {
                // This value is safe to cache for the life time of the app since the user
                // must logout to change the DPI setting. This value also applies to all
                // screens.
                HDC screen_dc = ::GetDC(NULL);
                int dpi_x = GetDeviceCaps(screen_dc, LOGPIXELSX);
                scale_factor = static_cast<double>(dpi_x) / 96.0;
                ::ReleaseDC(NULL, screen_dc);
                initialized = true;
            }

            return scale_factor;
        }

        void WebViewImpl::setScalesPageToFit(const bool scalesPageToFit) {
            mScalesPageToFit = scalesPageToFit;
            if (BrowserValid()) {
                mBrowser->GetHost()->SetZoomLevel(scalesPageToFit ? GetDeviceScaleFactor() : 0.0);
            }
        }

        void WebViewImpl::draw(cocos2d::Renderer* renderer, cocos2d::Mat4 const& transform, uint32_t flags) {
            if (flags & cocos2d::Node::FLAGS_TRANSFORM_DIRTY) {
                ResizeMoveCefBrowser();
            }
        }

        void WebViewImpl::setVisible(bool visible) {
            mVisible = visible;
            if (mHWND) {
                ShowWindow(mHWND, visible ? SW_SHOW : SW_HIDE);
                if (!visible) {
                    // When the frame window is minimized set the browser window size to 0x0 to
                    // reduce resource usage.
                    SetWindowPos(mHWND, nullptr,
                        0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
                }
            }
        }

        void WebViewImpl::setOpacityWebView(float opacity) {}

        float WebViewImpl::getOpacityWebView() const {
            return 1.0f;
        }

        void WebViewImpl::setBackgroundTransparent() {}

        void WebViewImpl::CreateCefBrowser() {
            CefWindowInfo windowInfo;
            windowInfo.SetAsChild(cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window(), { 0,0,0,0 });
            auto settings = CefBrowserSettings();
            CefBrowserHost::CreateBrowser(windowInfo, this, "", settings, nullptr, nullptr);
        }

        void WebViewImpl::ResizeMoveCefBrowser() {
            if (!mHWND) {
                return;
            }
            const auto uiRect = cocos2d::ui::Helper::convertBoundingBoxToScreen(_webView);
            // Set the browser window bounds.
            SetWindowPos(
                mHWND, nullptr,
                static_cast<int>(uiRect.origin.x), static_cast<int>(uiRect.origin.y),
                static_cast<int>(uiRect.size.width), static_cast<int>(uiRect.size.height),
                SWP_NOZORDER
            );
        }

        void WebViewImpl::DestroyCefBrowser() {
            if (mBrowser) {
                mBrowser->GetHost()->CloseBrowser(true);
                DestroyWindow(mHWND);
                mBrowser = nullptr;
            }
        }

        void WebViewImpl::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
            CEF_REQUIRE_UI_THREAD();
            mHWND = browser->GetHost()->GetWindowHandle();
            mBrowser = browser;
            if (!mUrl.empty()) {
                mBrowser->GetMainFrame()->LoadURL(mUrl);
            }
            _webView->_transformUpdated = _webView->_transformDirty = _webView->_inverseDirty = true;
            if (mScalesPageToFit) {
                setScalesPageToFit(true);
            }
            setVisible(mVisible);
        }

        bool WebViewImpl::DoClose(CefRefPtr<CefBrowser> browser) {
            CEF_REQUIRE_UI_THREAD();
            mIsClosing = true;
            // Allow the close. For windowed browsers this will result in the OS close
            // event being sent.
            return true;
        }

        void WebViewImpl::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
            CEF_REQUIRE_UI_THREAD();
            mIsClosing = false;
            mIsClosed = true;
        }

        void WebViewImpl::OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode) {
            CEF_REQUIRE_UI_THREAD();
            if (_webView->_onDidFinishLoading) {
                _webView->_onDidFinishLoading(_webView, frame->GetURL());
            }
        }

        void WebViewImpl::OnLoadError(CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            ErrorCode errorCode,
            const CefString& errorText,
            const CefString& failedUrl) {
            CEF_REQUIRE_UI_THREAD();

            // Don't display an error for downloaded files.
            if (errorCode == ERR_ABORTED)
                return;

            // Display a load error message.
            auto ss = std::stringstream();
            ss << "<html><body bgcolor=\"white\">"
                "<h2>Failed to load URL " << std::string(failedUrl) <<
                " with error " << std::string(errorText) << " (" << errorCode <<
                ").</h2></body></html>";

            frame->LoadURL(GetDataURI(ss.str(), "text/html"));

            if (_webView->_onDidFailLoading) {
                _webView->_onDidFailLoading(_webView, failedUrl);
            }
        }

        void WebViewImpl::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            CefRefPtr<CefContextMenuParams> params,
            CefRefPtr<CefMenuModel> model) {
            CEF_REQUIRE_UI_THREAD();
            model->Clear();
        }

        bool WebViewImpl::OnBeforeBrowse(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request, bool user_gesture, bool is_redirect) {
            const std::string url = request->GetURL();
            std::string scheme = url.substr(0, url.find_first_of(':'));
            if (scheme == mJsScheme) {
                if (_webView->_onJSCallback) {
                    _webView->_onJSCallback(_webView, url);
                }
                return true;
            }

            if (_webView->_onShouldStartLoading && !url.empty()) {
                return !_webView->_onShouldStartLoading(_webView, url);
            }

            return false;
        }

        bool WebViewImpl::OnBeforePopup(CefRefPtr<CefBrowser> browser,
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
            bool* no_javascript_access) {
            CEF_REQUIRE_UI_THREAD();

            switch (target_disposition) {
            case WOD_NEW_FOREGROUND_TAB:
            case WOD_NEW_BACKGROUND_TAB:
            case WOD_NEW_POPUP:
            case WOD_NEW_WINDOW:
                browser->GetMainFrame()->LoadURL(target_url);
                return true; //cancel create
            }

            return false;
        }

    } // namespace ui
} //namespace cocos2d

#endif // CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
