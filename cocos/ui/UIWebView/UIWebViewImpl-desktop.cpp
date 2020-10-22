#include "platform/CCPlatformConfig.h"
#include "platform/CCApplication.h"
#include "UIWebViewImpl-desktop.h"
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
#if __linux__
#include <X11/Xlib.h>
#endif

namespace cocos2d {
    namespace ui {
        size_t WebViewImpl::CefBrowserCount = 0;
        WebViewImpl::WebViewImpl(WebView* webView) :
            _webView(webView) {
#if __linux__
            mXDisplay = cocos2d::Director::getInstance()->getOpenGLView()->getX11Display();
#endif
            CefBrowserCount++;
            cocos2d::Application::getInstance()->SetCefClose(false);
            CreateCefBrowser();
        }

        WebViewImpl::~WebViewImpl() {
            CefBrowserCount--;
            if (!CefBrowserCount) {
                cocos2d::Application::getInstance()->SetCefClose(true);
            }
        }

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
            auto fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(fileName);
            if (fullPath.find("file://") != 0) {
                fullPath = "file://" + fullPath;
            }
            loadURL(fullPath, false);
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
#if _WIN32
                HDC screen_dc = ::GetDC(NULL);
                int dpi_x = GetDeviceCaps(screen_dc, LOGPIXELSX);
                scale_factor = static_cast<double>(dpi_x) / 96.0;
                ::ReleaseDC(NULL, screen_dc);
#endif
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
            if (mBrowserWindow && mBrowser) {
#if _WIN32
                ShowWindow(mBrowserWindow, visible ? SW_SHOW : SW_HIDE);
                if (!visible) {
                    // When the frame window is minimized set the browser window size to 0x0 to
                    // reduce resource usage.
                    SetWindowPos(mBrowserWindow, nullptr,
                        0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
                }
#elif __linux__
                if (!visible) {
                    XUnmapWindow((Display*)mXDisplay, mBrowserWindow);
                    XMoveResizeWindow(
                        (Display*)mXDisplay, mBrowserWindow,
                        -1, -1, 1, 1
                    );
                }
                else {
                    XMapWindow((Display*)mXDisplay, mBrowserWindow);
                }
#endif
            }
        }

        void WebViewImpl::setOpacityWebView(float opacity) {}

        float WebViewImpl::getOpacityWebView() const {
            return 1.0f;
        }

        void WebViewImpl::setBackgroundTransparent() {}

        void WebViewImpl::CreateCefBrowser() {
            CefWindowInfo windowInfo;
#if _WIN32
            windowInfo.SetAsChild(cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window(), { 0,0,0,0 });
#elif __linux__
            windowInfo.SetAsChild(cocos2d::Director::getInstance()->getOpenGLView()->getX11Window(), { -1,-1,1,1 });
#endif
            auto settings = CefBrowserSettings();
            CefBrowserHost::CreateBrowser(windowInfo, this, "", settings, nullptr, nullptr);
        }

        void WebViewImpl::ResizeMoveCefBrowser() {
            if (!mBrowserWindow || !mBrowser || !_webView) {
                return;
            }
            const auto uiRect = cocos2d::ui::Helper::convertBoundingBoxToScreen(_webView);
            // Set the browser window bounds.
#if _WIN32
            SetWindowPos(
                mBrowserWindow, nullptr,
                static_cast<int>(uiRect.origin.x), static_cast<int>(uiRect.origin.y),
                static_cast<int>(uiRect.size.width), static_cast<int>(uiRect.size.height),
                SWP_NOZORDER
            );
#elif __linux__
            int x = static_cast<int>(uiRect.origin.x);
            int y = static_cast<int>(uiRect.origin.y);
            int w = static_cast<int>(uiRect.size.width);
            int h = static_cast<int>(uiRect.size.height);
            if (w == 0 || h == 0) {
                x = -1;y = -1;w = 1;h = 1;
            }
            XMoveResizeWindow(
                (Display*)mXDisplay, mBrowserWindow,
                x, y, w, h
            );
#endif
        }

        void WebViewImpl::DestroyCefBrowser() {
            _webView = nullptr;
            if (mBrowser) {
                mBrowser->GetHost()->CloseBrowser(true);
#if _WIN32
                DestroyWindow(mBrowserWindow);
                mBrowserWindow = nullptr;
#elif __linux__
                XUnmapWindow((Display*)mXDisplay, mBrowserWindow);
                //XDestroyWindow((Display*)mXDisplay, mBrowserWindow);
                mBrowserWindow = 0;
#endif
                mBrowser = nullptr;
            }
        }

        void WebViewImpl::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
            CEF_REQUIRE_UI_THREAD();

            mBrowserWindow = browser->GetHost()->GetWindowHandle();
            mBrowser = browser;
            if (!_webView) {
                DestroyCefBrowser();
                return;
            }
            if (!mUrl.empty()) {
                mBrowser->GetMainFrame()->LoadURL(mUrl);
            }
            if (_webView) {
                _webView->_transformUpdated = _webView->_transformDirty = _webView->_inverseDirty = true;
            }
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
#if _WIN32
            return true;
#elif __linux__
            return false;
#endif
        }

        void WebViewImpl::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
            CEF_REQUIRE_UI_THREAD();
            mIsClosing = false;
            mIsClosed = true;
        }

        void WebViewImpl::OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode) {
            CEF_REQUIRE_UI_THREAD();
            if (_webView && _webView->_onDidFinishLoading) {
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

            if (_webView && _webView->_onDidFailLoading) {
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
                if (_webView && _webView->_onJSCallback) {
                    _webView->_onJSCallback(_webView, url);
                }
                return true;
            }

            if (_webView && _webView->_onShouldStartLoading && !url.empty()) {
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
