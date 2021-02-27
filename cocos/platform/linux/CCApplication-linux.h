/****************************************************************************
Copyright (c) 2011      Laschweinski
Copyright (c) 2013-2016 Chukong Technologies Inc.
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
#pragma once

#include "platform/CCCommon.h"
#include "platform/CCApplicationProtocol.h"
#include <string>

NS_CC_BEGIN
class Rect;

class Application : public ApplicationProtocol
{
public:
    /**
     * @js ctor
     */
    Application();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~Application();

    /**
     @brief Callback by Director for limit FPS.
     @param interval    The time, which expressed in second in second, between current frame and next.
     */
    virtual void setAnimationInterval(float interval) override;

    /**
     @brief Run the message loop.
     */
    int run();

    /**
     @brief Get current application instance.
     @return Current application instance pointer.
     */
    static Application* getInstance();

    /** @deprecated Use getInstance() instead */
    CC_DEPRECATED_ATTRIBUTE static Application* sharedApplication();

    /* override functions */
    virtual LanguageType getCurrentLanguage() override;

    /**
    @brief Get current language iso 639-1 code
    @return Current language iso 639-1 code
    */
    virtual const char * getCurrentLanguageCode() override;

    /**
    @brief Get application version
    */
    virtual std::string getVersion() override {return "0";};

    /**
    @brief 获取应用的编译版本
    */
    virtual int64_t GetCompileVersion() override {return 0;};

    /**
     @brief Open url in default browser
     @param String with url to open.
     @return true if the resource located by the URL was successfully opened; otherwise false.
     */
    virtual bool openURL(const std::string &url) override;


    /**
     *  Sets the Resource root path.
     *  @deprecated Please use FileUtils::getInstance()->setSearchPaths() instead.
     */
    CC_DEPRECATED_ATTRIBUTE void setResourceRootPath(const std::string& rootResDir);

    /**
     *  Gets the Resource root path.
     *  @deprecated Please use FileUtils::getInstance()->getSearchPaths() instead.
     */
    CC_DEPRECATED_ATTRIBUTE const std::string& getResourceRootPath();

    /**
     @brief Get target platform
     */
    virtual Platform getTargetPlatform() override;

    /*
     @brief 创建一个模式对话框。
            提供0-2个回调，即有1-2个按钮，最少有一个“确定”按钮。
    */
    void Dialog(
        const std::string& title,
        const std::string& content,
        const std::function<void()>& okCallback = nullptr,
        const std::function<void()>& cancelCallback = nullptr
    ) override;

    /*
     @brief 创建一个通知。
    */
    void Notify(
        const std::string& title,
        const std::string& content,
        const std::function<void()>& clickCallback = nullptr
    ) override;

    void SetCefClose(bool b) { cefClose = b; }
protected:
    long       _animationInterval;  //micro second
    std::string _resourceRootPath;

    // CefCloseFlag
    bool cefClose = true;

    static Application * sm_pSharedApplication;
};

NS_CC_END
