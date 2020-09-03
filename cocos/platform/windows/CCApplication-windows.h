/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
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

#include "platform/CCStdC.h"
#include "platform/CCCommon.h"
#include "platform/CCApplicationProtocol.h"
#include <string>
#include <vector>

NS_CC_BEGIN

class CC_DLL Application : public ApplicationProtocol
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
    @brief    Run the message loop.
    */
    int run();

    /**
    @brief    Get current application instance.
    @return Current application instance pointer.
    */
    static Application* getInstance();

    /* override functions */
    virtual void setAnimationInterval(float interval) override;

    virtual LanguageType getCurrentLanguage();

    virtual const char * getCurrentLanguageCode();

    /**
     @brief Get target platform
     */
    virtual Platform getTargetPlatform();

    /**
    @brief Get application version
    */
    virtual std::string getVersion() override;

    /**
    @brief 获取应用的编译版本
    */
    virtual int64_t GetCompileVersion() override;

    /**
     @brief Open url in default browser
     @param String with url to open.
     @return true if the resource located by the URL was successfully opened; otherwise false.
     */
    virtual bool openURL(const std::string &url);

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

    void setStartupScriptFilename(const std::string& startupScriptFile);

    const std::string& getStartupScriptFilename()
    {
        return _startupScriptFilename;
    }

    /*
     @brief 创建一个非模式对话框。
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
        uint16_t icon,
        const std::string& title,
        const std::string& content,
        const std::function<void()>& clickCallback = nullptr,
        const std::function<void()>& closeCallback = nullptr
    ) override;


protected:
    HINSTANCE           _instance;
    HACCEL              _accelTable;
    LARGE_INTEGER       _animationInterval;
    std::string         _resourceRootPath;
    std::string         _startupScriptFilename;

    struct DialogWrapper {
        DialogWrapper(HWND dlgWnd, const std::function<void()>& okCallback, const std::function<void()>& cancelCallback) :
            dlgWnd(dlgWnd),
            okCallback(okCallback),
            cancelCallback(cancelCallback){}
        HWND dlgWnd = nullptr;
        std::function<void()> okCallback = nullptr;
        std::function<void()> cancelCallback = nullptr;
    };
    struct NotifyWrapper {
        NotifyWrapper(const std::function<void()>& clickCallback, const std::function<void()>& closeCallback) :
            clickCallback(clickCallback),
            closeCallback(closeCallback) {}
        std::function<void()> clickCallback = nullptr;
        std::function<void()> closeCallback = nullptr;
    };

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    // 用于存放非模式对话框句柄。
    static std::vector<DialogWrapper> VecDlgWrapper;
    // 判断MSG是否应是对话框处理。
    void DialogMessageFilter() noexcept;
    static INT_PTR CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    static const uint32_t NotifyMsgID = 99;
    static void NotifyProc(HWND hwnd, WPARAM wParam, LPARAM lParam);

    // 用于临时存放通知信息。
    static std::map<uint16_t,NotifyWrapper> MapNotifyWrapper;
    // 通知ID
    static uint16_t NotifyID;

    static Application * sm_pSharedApplication;
};

NS_CC_END
