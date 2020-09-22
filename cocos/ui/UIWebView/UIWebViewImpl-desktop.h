#include <string>
#include "CCGLView.h"
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

            static size_t CefBrowserCount;

            WebView* _webView;
#if _WIN32
            HWND mBrowserWindow = nullptr;
#elif __linux__
            X11Window mBrowserWindow = 0;
            X11Display* mXDisplay = nullptr;
#endif
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