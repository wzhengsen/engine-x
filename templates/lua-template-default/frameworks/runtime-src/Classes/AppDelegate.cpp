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

#include "AppDelegate.h"

#include "cjson/LuaRegister_cjson.h"
#include "crypto/LuaRegister_crypto.h"
#include "Network/LuaRegisterConnection.h"
#include "lua-protobuf/LuaRegister_lua-protobuf.h"
#include "Cocos2dx/LuaRegisterCocos2dx.h"
#include "Device/LuaRegisterDevice.h"
#include "ExtLib/LuaRegisterExtLib.h"

#include "audio/include/AudioEngine.h"
#include "scripting/lua-bindings/CCLua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "proj.windows/resource.h"
#endif

 // if you want to use the package manager to install more packages,
 // don't modify or remove this function
static int register_all_packages() {
    return 0; //flag for packages manager
}
static int register_custom_function(lua_State* L) noexcept {
    LuaRegister_cjson(L);
    LuaRegister_crypto(L);
    LuaRegisterConnection(L);
    LuaRegisterDownloader(L);
    LuaRegister_luaprotobuf(L);
    LuaRegisterZipFile(L);
    LuaRegisterDevice(L);
    LuaRegisterExtLib(L);
    return 0;
}

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    _iconRes = IDI_ICON1;
#endif
}

AppDelegate::~AppDelegate() {
    AudioEngine::end();
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs() {
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // set default FPS
    Director::getInstance()->setAnimationInterval(1.0f / 60.0f);
    return RestartLuaEngine();
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    auto dr = Director::getInstance();
    dr->stopAnimation();
    // Block all sound.
    AudioEngine::BlockAll();
    dr->getEventDispatcher()->dispatchCustomEvent("applicationDidEnterBackground");
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    auto dr = Director::getInstance();
    dr->startAnimation();
    AudioEngine::UnblockAll();
    dr->getEventDispatcher()->dispatchCustomEvent("applicationWillEnterForeground");
}

// Restart Lua engine and run with main.lua
bool AppDelegate::RestartLuaEngine() {
    auto fu = FileUtils::getInstance();
    fu->addSearchPath(fu->getWritablePath(), true);
    // Release last Lua engine.
    extension::Lua::Close();
    // New Lua.
    auto lua = extension::Lua::GetInstance();
    // Register some module
    register_all_packages();
    // Register custom module
    register_custom_function(lua->lua_state());
    return lua->script("require('src.main');").valid();
}
