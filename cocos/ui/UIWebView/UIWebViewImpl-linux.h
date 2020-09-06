#include "platform/CCPlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#pragma once
/// @cond DO_NOT_SHOW

#include <stdint.h>
#include <iosfwd>


namespace cocos2d {

class Data;
class Renderer;
class Mat4;

namespace ui{

class WebView;

class WebViewImpl {
public:
    WebViewImpl(WebView *webView){};

    virtual ~WebViewImpl(){};

    void setJavascriptInterfaceScheme(const std::string &scheme){};

    void loadData(const cocos2d::Data &data,
                  const std::string &MIMEType,
                  const std::string &encoding,
                  const std::string &baseURL){};

    void loadHTMLString(const std::string &string, const std::string &baseURL){};

    void loadURL(const std::string &url){};
    void loadURL(const std::string &url, bool cleanCachedData){};

    void loadFile(const std::string &fileName){};

    void stopLoading(){};

    void reload(){};

    bool canGoBack(){return false;};

    bool canGoForward(){return false;};

    void goBack(){};

    void goForward(){};

    void evaluateJS(const std::string &js){};

    void setScalesPageToFit(const bool scalesPageToFit){};

    virtual void draw(cocos2d::Renderer *renderer, cocos2d::Mat4 const &transform, uint32_t flags){};

    virtual void setVisible(bool visible){};

    void setBounces(bool bounces){};

    virtual void setOpacityWebView(float opacity){};

    virtual float getOpacityWebView() const{return 0.0;};

    virtual void setBackgroundTransparent(){};

private:
    WebView *_webView;
};

    } // namespace ui
}//namespace cocos2d

/// @endcond
#endif