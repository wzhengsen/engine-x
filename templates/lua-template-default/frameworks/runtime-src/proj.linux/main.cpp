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

#include "../Classes/AppDelegate.h"
#include "cocos2d.h"
#include "include/cef_app.h"
#include "X11/Xlib.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

USING_NS_CC;

int XErrorHandlerImpl(Display* display, XErrorEvent* event) {
  LOG(WARNING) << "X error received: "
    << "type " << event->type << ", "
    << "serial " << event->serial << ", "
    << "error_code " << static_cast<int>(event->error_code) << ", "
    << "request_code " << static_cast<int>(event->request_code)
    << ", "
    << "minor_code " << static_cast<int>(event->minor_code);
  return 0;
}

int XIOErrorHandlerImpl(Display* display) {
  return 0;
}

int main(int argc, char** argv) {
  CefMainArgs mainArgs(argc, argv);
  // todo-remark
  // Create a new executable entry to bearer subprocess.
  // todo-end
  const auto exit_code = CefExecuteProcess(mainArgs, nullptr, nullptr);
  if (exit_code >= 0) {
    // The sub-process has completed so return here.
    return exit_code;
  }

  // Install xlib error handlers so that the application won't be terminated
  // on non-fatal errors.
  XSetErrorHandler(XErrorHandlerImpl);
  XSetIOErrorHandler(XIOErrorHandlerImpl);

  CefEnableHighDPISupport();
  CefSettings settings;
  settings.multi_threaded_message_loop = false;
  settings.no_sandbox = true;
  settings.log_severity = cef_log_severity_t::LOGSEVERITY_ERROR;

  if (!CefInitialize(mainArgs, settings, nullptr, nullptr)) {
    return 1;
  }

  // create the application instance
  AppDelegate app;
  const auto ret = Application::getInstance()->run();

  CefShutdown();
  return ret;
}
