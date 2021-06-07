/****************************************************************************
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
#include "main.h"
#include "cocos2d.h"
#include "../Classes/AppDelegate.h"
#include "include/cef_app.h"

USING_NS_CC;

int WINAPI _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);

    CefMainArgs mainArgs(hPrevInstance);
    // todo-remark
    // Create a new executable entry to bearer subprocess.
    // todo-end
    const auto exit_code = CefExecuteProcess(mainArgs, nullptr, nullptr);
    if (exit_code >= 0) {
        // The sub-process has completed so return here.
        std::exit(0);
    }

    CefEnableHighDPISupport();
    CefSettings settings;
    settings.multi_threaded_message_loop = false;
    settings.no_sandbox = true;
    settings.log_severity = cef_log_severity_t::LOGSEVERITY_ERROR;

    if (!CefInitialize(mainArgs, settings, nullptr, nullptr)) {
        return 1;
    }

    const std::wstring lpStr = lpCmdLine;
    const bool noCmd = lpStr.find(L"--noCmd") != std::wstring::npos;
    if (!noCmd) {
        AllocConsole();
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        SetConsoleOutputCP(CP_UTF8);
    }

    // create the application instance
    AppDelegate app;
    const int ret = Application::getInstance()->run();

    if (!noCmd) {
        FreeConsole();
    }
    CefShutdown();

    return ret;
}
