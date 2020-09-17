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
#include "platform/linux/CCApplication-linux.h"
#include <unistd.h>
#include <sys/time.h>
#include <string>
#include <gtk/gtk.h>
#include "libnotify/notify.h"
#include <thread>
#include <queue>
#include <mutex>
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "base/CCDirector.h"
#include "base/ccUtils.h"
#include "platform/CCFileUtils.h"

NS_CC_BEGIN
using namespace rapidjson;

// sharedApplication pointer
Application * Application::sm_pSharedApplication = nullptr;

static long getCurrentMillSecond() {
    long lLastTime;
    struct timeval stCurrentTime;

    gettimeofday(&stCurrentTime,NULL);
    lLastTime = stCurrentTime.tv_sec*1000+stCurrentTime.tv_usec*0.001; // milliseconds
    return lLastTime;
}

Application::Application()
: _animationInterval(1.0f/60.0f*1000.0f)
{
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = nullptr;
}

int Application::run()
{
    gtk_init(nullptr,nullptr);
    notify_init("StarryX");

    initGLContextAttrs();
    // Initialize instance and cocos2d.
    if (! applicationDidFinishLaunching())
    {
        return 0;
    }

    long lastTime = 0L;
    long curTime = 0L;

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    // Retain glview to avoid glview being released in the while loop
    glview->retain();

    while (!glview->windowShouldClose())
    {
        lastTime = getCurrentMillSecond();

        director->mainLoop();
        glview->pollEvents();

        curTime = getCurrentMillSecond();
        if (curTime - lastTime < _animationInterval)
        {
            usleep((_animationInterval - curTime + lastTime)*1000);
        }
    }
    /* Only work on Desktop
    *  Director::mainLoop is really one frame logic
    *  when we want to close the window, we should call Director::end();
    *  then call Director::mainLoop to do release of internal resources
    */
    if (glview->isOpenGLReady())
    {
        director->end();
        director->mainLoop();
        director = nullptr;
    }
    glview->release();

    notify_uninit();
    return EXIT_SUCCESS;
}

void Application::setAnimationInterval(float interval)
{
    //TODO do something else
    _animationInterval = interval*1000.0f;
}

void Application::setResourceRootPath(const std::string& rootResDir)
{
    _resourceRootPath = rootResDir;
    if (_resourceRootPath[_resourceRootPath.length() - 1] != '/')
    {
        _resourceRootPath += '/';
    }
    FileUtils* pFileUtils = FileUtils::getInstance();
    std::vector<std::string> searchPaths = pFileUtils->getSearchPaths();
    searchPaths.insert(searchPaths.begin(), _resourceRootPath);
    pFileUtils->setSearchPaths(searchPaths);
}

const std::string& Application::getResourceRootPath()
{
    return _resourceRootPath;
}

Application::Platform Application::getTargetPlatform()
{
    return Platform::OS_LINUX;
}

bool Application::openURL(const std::string &url)
{
    std::string op = std::string("xdg-open '").append(url).append("'");
    return system(op.c_str()) == 0;
}

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

// @deprecated Use getInstance() instead
Application* Application::sharedApplication()
{
    return Application::getInstance();
}

const char * Application::getCurrentLanguageCode()
{
    static char code[3]={0};
    char *pLanguageName = getenv("LANG");
    if (!pLanguageName)
        return "en";
    strtok(pLanguageName, "_");
    if (!pLanguageName)
        return "en";
    strncpy(code,pLanguageName,2);
    code[2]='\0';
    return code;
}

LanguageType Application::getCurrentLanguage()
{
    char *pLanguageName = getenv("LANG");
    if (!pLanguageName)
    {
        return LanguageType::ENGLISH;
    }
    strtok(pLanguageName, "_");
    if (!pLanguageName)
    {
        return LanguageType::ENGLISH;
    }

    return utils::getLanguageTypeByISO2(pLanguageName);
}

void Application::Dialog(
    const std::string& title,
    const std::string& content,
    const std::function<void()>& okCallback,
    const std::function<void()>& cancelCallback
) {
    GtkWidget* dialog = gtk_dialog_new_with_buttons(
        title.c_str(),
        nullptr,
        GtkDialogFlags::GTK_DIALOG_DESTROY_WITH_PARENT,
        nullptr,nullptr
    );
    GtkWidget* contentArea = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    gtk_widget_set_size_request(dialog,400,120);
    gtk_window_set_deletable(GTK_WINDOW(dialog),false);
    gtk_window_set_modal(GTK_WINDOW(dialog),true);
    gtk_window_set_resizable(GTK_WINDOW(dialog),false);
    gtk_dialog_add_button(GTK_DIALOG(dialog),"确定",0);
    if (nullptr != cancelCallback) {
        gtk_dialog_add_button(GTK_DIALOG(dialog),"取消",1);
    }
    gtk_dialog_set_default_response(GTK_DIALOG(dialog),0);

    GtkWidget* label = gtk_label_new(content.c_str());
    gtk_label_set_line_wrap(GTK_LABEL(label),true);
    gtk_label_set_line_wrap_mode(GTK_LABEL(label),PangoWrapMode::PANGO_WRAP_WORD_CHAR);
    gtk_label_set_max_width_chars(GTK_LABEL(label),40);
    gtk_label_set_yalign(GTK_LABEL(label),0.5);
    gtk_widget_set_size_request(label,400,100);

    GtkWidget* fixBox = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixBox),label,0,0);

    gtk_container_add(GTK_CONTAINER(contentArea),fixBox);

    gtk_widget_show_all(dialog);

    const gint rId = gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);

    while (g_main_context_iteration(nullptr, false));

    if (rId == 0 && okCallback) {
        okCallback();
    }
    else if (rId == 1 && cancelCallback) {
        cancelCallback();
    }
}

struct NotifyWrapper {
    std::string title = std::string();
    std::string content = std::string();
    std::function<void()> clickCallback = nullptr;
    std::function<void()> closeCallback = nullptr;
    bool callOnce = false;
    NotifyWrapper(
        const std::string& title,
        const std::string& content,
        const std::function<void()>& clickCallback,
        const std::function<void()>& closeCallback
    ):
    title(title),
    content(content),
    clickCallback(clickCallback),
    closeCallback(closeCallback){}
};

static void NotificationClicked(NotifyNotification* notification, char* action,gpointer gp) {
    NotifyWrapper* nw = reinterpret_cast<NotifyWrapper*>(gp);
    if (nw && !nw->callOnce) {
        nw->callOnce = true;
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([ccb = nw->clickCallback](){
            ccb();
        });
    }
}

static void NotificationClosed(NotifyNotification* notification, gpointer gp) {
    NotifyWrapper* nw = reinterpret_cast<NotifyWrapper*>(gp);
    if (nw && !nw->callOnce) {
        nw->callOnce = true;
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([ccb = nw->closeCallback](){
            ccb();
        });
    }
}

/*
    @brief 创建一个通知。
*/
void Application::Notify(
    const std::string& title,
    const std::string& content,
    const std::function<void()>& clickCallback,
    const std::function<void()>& closeCallback
) {
    // Static
    static auto iconPath = std::string();
    static auto nwQueue = std::queue<NotifyWrapper>();
    static std::mutex ntyMutex;
    static std::thread* ntyThread = nullptr;
    if (iconPath.empty()) {
        auto fu = cocos2d::FileUtils::getInstance();
        iconPath = "file://" + fu->getWritablePath();
        const std::string fileName = fu->fullPathForFilename("config.json");
        const std::string content = fu->getStringFromFile(fileName);
        Document docRootjson = Document();
        if (!docRootjson.Parse<ParseFlag::kParseNoFlags>(content.c_str()).HasParseError()) {
            if (docRootjson.HasMember("linuxIcon") && docRootjson["linuxIcon"].IsString()) {
                iconPath += docRootjson["linuxIcon"].GetString();
            }
        }
        else {
            iconPath += "linuxIcon.png";
        }
    }

    // Lock and pushback notify info to queue.
    const std::lock_guard<std::mutex> lg(ntyMutex);
    nwQueue.emplace(std::move(title),std::move(content),std::move(clickCallback),std::move(closeCallback));

    if (!ntyThread) {
        ntyThread = new std::thread([](){
            // Work thread,deal notify one by one.
            while(true) {
                ntyMutex.lock();
                if(!nwQueue.size()) {
                    ntyMutex.unlock();
                    break;
                }
                auto& nw = nwQueue.front();
                ntyMutex.unlock();

                NotifyNotification* nty = notify_notification_new(nw.title.c_str(), nw.content.c_str(), iconPath.c_str());
                notify_notification_set_urgency(nty, NotifyUrgency::NOTIFY_URGENCY_NORMAL);
                // Don't use a specific time,it not callback sometime.
                notify_notification_set_timeout(nty, NOTIFY_EXPIRES_NEVER);
                notify_notification_add_action(
                    nty,
                    "default", "确定",
                    (NotifyActionCallback)NotificationClicked, (gpointer)&nw,
                    nullptr
                );
                g_signal_connect(G_OBJECT(nty),"closed",G_CALLBACK(NotificationClosed),(gpointer)&nw);

                bool failed = !notify_notification_show(nty, nullptr);
                if (!failed) {
                    const auto beginTime = clock();
                    while(-1 == notify_notification_get_closed_reason(nty)) {
                        // Timeout 4 seconds.
                        if ((clock() - beginTime) / CLOCKS_PER_SEC > 3) {
                            failed = !notify_notification_close(nty,nullptr);
                            if (failed) {
                                break;
                            }
                        }
                        g_main_context_iteration(nullptr, false);
                    }
                }
                if (failed && nw.closeCallback){
                    // Notify show failed,call close callback directly.
                    nw.callOnce = true;
                    cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([ccb = nw.closeCallback](){
                        ccb();
                    });
                }
                g_object_unref(G_OBJECT(nty));
                while(g_main_context_iteration(nullptr, false));

                // Pop the front notify,deal next notify at next loop.
                ntyMutex.lock();
                nwQueue.pop();
                ntyMutex.unlock();
            }

            // All notify consumed,destory this thread.
            const std::lock_guard<std::mutex> lg(ntyMutex);
            delete ntyThread;
            ntyThread = nullptr;
        });
        ntyThread->detach();
    }
}

NS_CC_END
