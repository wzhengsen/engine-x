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
#include "platform/CCApplication.h"
#include "base/CCDirector.h"
#include <algorithm>
#include "platform/CCFileUtils.h"
#include <shellapi.h>
#include <WinVer.h>
#include "cocos/resource.h"
#include <VersionHelpers.h>
#define NTCVT_CP_DEFAULT CP_UTF8
#include "windows-specific/ntcvt/ntcvt.hpp"

/**
@brief    This function change the PVRFrame show/hide setting in register.
@param  bEnable If true show the PVRFrame window, otherwise hide.
*/
static void PVRFrameEnableControlWindow(bool bEnable);

static HMODULE GetSelfModuleHandle();

static WNDPROC g_oldWindowProc = nullptr;

NS_CC_BEGIN

// sharedApplication pointer
Application* Application::sm_pSharedApplication = nullptr;
std::vector<Application::DialogWrapper> Application::VecDlgWrapper = std::vector<Application::DialogWrapper>();
std::map<uint16_t, Application::NotifyWrapper> Application::MapNotifyWrapper = std::map<uint16_t, Application::NotifyWrapper>();
uint16_t Application::NotifyID = 0;

LRESULT CALLBACK Application::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_USER + NotifyMsgID:
        NotifyProc(hWnd, wParam, lParam);
        break;
    }
    return g_oldWindowProc(hWnd, uMsg, wParam, lParam);
}

INT_PTR CALLBACK Application::DialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_INITDIALOG:
        PeekMessage(nullptr, nullptr, 0, 0, PM_REMOVE);
        return TRUE;

    case WM_COMMAND: {
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            PeekMessage(nullptr, nullptr, 0, 0, PM_REMOVE);
            if (VecDlgWrapper.size() > 0) {
                const auto& bw = VecDlgWrapper.back();
                if (bw.dlgWnd == hWnd) {
                    if (LOWORD(wParam) == IDOK && bw.okCallback) {
                        bw.okCallback();
                    }
                    else if (LOWORD(wParam) == IDCANCEL && bw.cancelCallback) {
                        bw.cancelCallback();
                    }
                    DestroyWindow(hWnd);
                    VecDlgWrapper.pop_back();
                }
            }
            return TRUE;
        }
        break;
    }
    default:
        break;
    }
    return FALSE;
}

void Application::NotifyProc(HWND hwnd, WPARAM wParam, LPARAM lParam) {
    const auto msg = LOWORD(lParam);
    if (msg >= WM_MOUSEFIRST && msg <= WM_MOUSELAST) {
        return;
    }
    UINT uID = 0;
    if (IsWindows10OrGreater()) {
        uID = LOWORD(wParam);
    }
    else {
        uID = HIWORD(lParam);
    }
    const auto it = MapNotifyWrapper.find(uID);
    if (it == MapNotifyWrapper.cend()) {
        return;
    }
    switch (msg) {
    case NIN_BALLOONUSERCLICK:
    case NIN_BALLOONTIMEOUT:
    {
        NOTIFYICONDATA nd = NOTIFYICONDATA();
        nd.cbSize = sizeof(NOTIFYICONDATA);;
        nd.hWnd = hwnd;
        nd.uID = uID;

        Shell_NotifyIcon(NIM_DELETE, &nd);

        if (msg == NIN_BALLOONUSERCLICK && (*it).second.clickCallback) {
            (*it).second.clickCallback();
        }
        if (msg == NIN_BALLOONTIMEOUT && (*it).second.closeCallback) {
            (*it).second.closeCallback();
        }
        MapNotifyWrapper.erase(uID);
    }
        break;
    }
}

Application::Application()
: _instance(nullptr)
, _accelTable(nullptr)
{
    _instance    = GetModuleHandle(nullptr);
    _animationInterval.QuadPart = 0;
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = nullptr;
}

void Application::Dialog(
    const std::string& title,
    const std::string& content,
    std::function<void()> okCallback,
    std::function<void()> cancelCallback
) {
    HWND hwnd = cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window();
    // �����Ի���
    HWND dlgWnd = CreateDialog(
        GetSelfModuleHandle(),
        MAKEINTRESOURCE(IDD_COCOS_DIALOG),
        hwnd,
        DialogProc);

    if (dlgWnd) {
        const std::wstring wstrT = ntcvt::from_chars(title);
        const std::wstring wstrC = ntcvt::from_chars(content);

        // ���������ݡ�
        SetWindowText(dlgWnd, wstrT.c_str());
        SetWindowText(GetDlgItem(dlgWnd, IDC_STATIC1), wstrC.c_str());

        if (!cancelCallback) {
            // �����������ȡ����ť������ȷ���ƶ���ȡ������
            HWND ok = GetDlgItem(dlgWnd, IDOK);
            HWND cancel = GetDlgItem(dlgWnd, IDCANCEL);

            ShowWindow(cancel, SW_HIDE);
            RECT rect = {};

            if (GetWindowRect(cancel, &rect)) {
                POINT pt = {
                    rect.left,
                    rect.top
                };
                ScreenToClient(dlgWnd, &pt);
                MoveWindow(ok, pt.x, pt.y, rect.right - rect.left, rect.bottom - rect.top, true);
            }
        }

        UpdateWindow(dlgWnd);
        VecDlgWrapper.emplace_back(dlgWnd, okCallback, cancelCallback);
    }
}

void Application::DialogMessageFilter() noexcept {
    static MSG msg = {};
    if (PeekMessage(&msg, nullptr, 0, 0, PM_NOREMOVE) && VecDlgWrapper.size() > 0){
        for (auto& wrapper : VecDlgWrapper) {
            if (IsDialogMessage(wrapper.dlgWnd, &msg)) {
                return;
            }
        }
    }
}

void Application::Notify(
    uint16_t icon,
    const std::string& title,
    const std::string& content,
    std::function<void()> clickCallback,
    std::function<void()> closeCallback
) {
    const std::wstring wstrT = ntcvt::from_chars(title);
    const std::wstring wstrC = ntcvt::from_chars(content);
    HWND hwnd = cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window();
    NOTIFYICONDATA nd = NOTIFYICONDATA();

    nd.cbSize = sizeof(NOTIFYICONDATA);
    nd.hWnd = hwnd;
    nd.uID = NotifyID;
    nd.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
    nd.uCallbackMessage = WM_USER + NotifyMsgID;
    wcscpy_s(nd.szTip, wstrT.c_str());
    wcscpy_s(nd.szInfo, wstrC.c_str());
    wcscpy_s(nd.szInfoTitle, wstrT.c_str());
    nd.hIcon = LoadIcon(_instance, MAKEINTRESOURCE(icon));
    nd.hBalloonIcon = LoadIcon(_instance, MAKEINTRESOURCE(icon));
    nd.dwInfoFlags = NIIF_USER | NIIF_LARGE_ICON;
    nd.uVersion = NOTIFYICON_VERSION_4;

    Shell_NotifyIcon(NIM_ADD,&nd);
    Shell_NotifyIcon(NIM_SETVERSION, &nd);

    MapNotifyWrapper.emplace(NotifyID, NotifyWrapper{ clickCallback,closeCallback });
    NotifyID++;
}

int Application::run()
{
    PVRFrameEnableControlWindow(false);

    ///////////////////////////////////////////////////////////////////////////
    /////////////// changing timer resolution
    ///////////////////////////////////////////////////////////////////////////
    constexpr UINT TARGET_RESOLUTION = 1; // 1 millisecond target resolution
    TIMECAPS tc = {};
    UINT wTimerRes = 0;
    if (TIMERR_NOERROR == timeGetDevCaps(&tc, sizeof(TIMECAPS)))
    {
        wTimerRes = std::min(std::max(tc.wPeriodMin, TARGET_RESOLUTION), tc.wPeriodMax);
        timeBeginPeriod(wTimerRes);
    }

    // Main message loop:
    LARGE_INTEGER nLast;
    LARGE_INTEGER nNow;

    QueryPerformanceCounter(&nLast);

    initGLContextAttrs();

    // Initialize instance and cocos2d.
    if (!applicationDidFinishLaunching())
    {
        return 1;
    }

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    // Retain glview to avoid glview being released in the while loop
    glview->retain();

    LONGLONG interval = 0LL;
    LONG waitMS = 0L;

    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);

    g_oldWindowProc = (WNDPROC)SetWindowLongPtr(glview->getWin32Window(), GWLP_WNDPROC, (LONG_PTR)WindowProc);

    while(!glview->windowShouldClose())
    {
        QueryPerformanceCounter(&nNow);
        interval = nNow.QuadPart - nLast.QuadPart;
        if (interval >= _animationInterval.QuadPart)
        {
            nLast.QuadPart = nNow.QuadPart;
            DialogMessageFilter();
            director->mainLoop();
            glview->pollEvents();
        }
        else
        {
            // The precision of timer on Windows is set to highest (1ms) by 'timeBeginPeriod' from above code,
            // but it's still not precise enough. For example, if the precision of timer is 1ms,
            // Sleep(3) may make a sleep of 2ms or 4ms. Therefore, we subtract 1ms here to make Sleep time shorter.
            // If 'waitMS' is equal or less than 1ms, don't sleep and run into next loop to
            // boost CPU to next frame accurately.
            waitMS = static_cast<LONG>((_animationInterval.QuadPart - interval) * 1000LL / freq.QuadPart - 1L);
            if (waitMS > 1L)
                Sleep(waitMS);
        }
    }

    // Director should still do a cleanup if the window was closed manually.
    if (glview->isOpenGLReady())
    {
        director->end();
        director->mainLoop();
        director = nullptr;
    }
    glview->release();

    ///////////////////////////////////////////////////////////////////////////
    /////////////// restoring timer resolution
    ///////////////////////////////////////////////////////////////////////////
    if (wTimerRes != 0)
    {
        timeEndPeriod(wTimerRes);
    }
    return 0;
}

void Application::setAnimationInterval(float interval)
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    _animationInterval.QuadPart = (LONGLONG)(interval * freq.QuadPart);
}

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

LanguageType Application::getCurrentLanguage()
{
    LanguageType ret = LanguageType::ENGLISH;
    
    LCID localeID = GetUserDefaultLCID();
    unsigned short primaryLanguageID = localeID & 0xFF;
    
    switch (primaryLanguageID)
    {
        case LANG_CHINESE:
            ret = LanguageType::CHINESE;
            break;
        case LANG_ENGLISH:
            ret = LanguageType::ENGLISH;
            break;
        case LANG_FRENCH:
            ret = LanguageType::FRENCH;
            break;
        case LANG_ITALIAN:
            ret = LanguageType::ITALIAN;
            break;
        case LANG_GERMAN:
            ret = LanguageType::GERMAN;
            break;
        case LANG_SPANISH:
            ret = LanguageType::SPANISH;
            break;
        case LANG_DUTCH:
            ret = LanguageType::DUTCH;
            break;
        case LANG_RUSSIAN:
            ret = LanguageType::RUSSIAN;
            break;
        case LANG_KOREAN:
            ret = LanguageType::KOREAN;
            break;
        case LANG_JAPANESE:
            ret = LanguageType::JAPANESE;
            break;
        case LANG_HUNGARIAN:
            ret = LanguageType::HUNGARIAN;
            break;
        case LANG_PORTUGUESE:
            ret = LanguageType::PORTUGUESE;
            break;
        case LANG_ARABIC:
            ret = LanguageType::ARABIC;
            break;
        case LANG_NORWEGIAN:
            ret = LanguageType::NORWEGIAN;
            break;
        case LANG_POLISH:
            ret = LanguageType::POLISH;
            break;
        case LANG_TURKISH:
            ret = LanguageType::TURKISH;
            break;
        case LANG_UKRAINIAN:
            ret = LanguageType::UKRAINIAN;
            break;
        case LANG_ROMANIAN:
            ret = LanguageType::ROMANIAN;
            break;
        case LANG_BULGARIAN:
            ret = LanguageType::BULGARIAN;
            break;
        case LANG_BELARUSIAN:
            ret = LanguageType::BELARUSIAN;
            break;
    }
    
    return ret;
}

const char * Application::getCurrentLanguageCode()
{
    LANGID lid = GetUserDefaultUILanguage();
    const LCID locale_id = MAKELCID(lid, SORT_DEFAULT);
    static char code[3] = { 0 };
    GetLocaleInfoA(locale_id, LOCALE_SISO639LANGNAME, code, sizeof(code));
    code[2] = '\0';
    return code;
}

Application::Platform Application::getTargetPlatform()
{
    return Platform::OS_WINDOWS;
}

std::string Application::getVersion()
{
    char verString[256] = { 0 };
    TCHAR szVersionFile[MAX_PATH];
    GetModuleFileName(NULL, szVersionFile, MAX_PATH);
    DWORD  verHandle = NULL;
    UINT   size = 0;
    LPBYTE lpBuffer = NULL;
    DWORD  verSize = GetFileVersionInfoSize(szVersionFile, &verHandle);
    
    if (verSize != NULL)
    {
        LPSTR verData = new char[verSize];
        
        if (GetFileVersionInfo(szVersionFile, verHandle, verSize, verData))
        {
            if (VerQueryValue(verData, L"\\", (VOID FAR* FAR*)&lpBuffer, &size))
            {
                if (size)
                {
                    VS_FIXEDFILEINFO *verInfo = (VS_FIXEDFILEINFO *)lpBuffer;
                    if (verInfo->dwSignature == 0xfeef04bd)
                    {
                        
                        // Doesn't matter if you are on 32 bit or 64 bit,
                        // DWORD is always 32 bits, so first two revision numbers
                        // come from dwFileVersionMS, last two come from dwFileVersionLS
                        sprintf(verString, "%d.%d.%d.%d", (verInfo->dwFileVersionMS >> 16) & 0xffff,
                                (verInfo->dwFileVersionMS >> 0) & 0xffff,
                                (verInfo->dwFileVersionLS >> 16) & 0xffff,
                                (verInfo->dwFileVersionLS >> 0) & 0xffff
                                );
                    }
                }
            }
        }
        delete[] verData;
    }
    return verString;
}

int64_t Application::GetCompileVersion() {
    char verString[256] = { 0 };
    TCHAR szVersionFile[MAX_PATH];
    GetModuleFileName(NULL, szVersionFile, MAX_PATH);
    DWORD  verHandle = NULL;
    UINT   size = 0;
    LPBYTE lpBuffer = NULL;
    DWORD  verSize = GetFileVersionInfoSize(szVersionFile, &verHandle);
    int64_t compileVer = 0;

    if (verSize != NULL) {
        LPSTR verData = new char[verSize];

        if (GetFileVersionInfo(szVersionFile, verHandle, verSize, verData)) {
            if (VerQueryValue(verData, L"\\", (VOID FAR * FAR*) & lpBuffer, &size)) {
                if (size) {
                    VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
                    if (verInfo->dwSignature == 0xfeef04bd) {
                        // ʹ��dwProductVersionMS��Ϊ��32λ��dwProductVersionLS��Ϊ��32λ��������ʾ����汾��
                        compileVer = ((int64_t)(verInfo->dwProductVersionMS) << 32) + verInfo->dwProductVersionLS;
                    }
                }
            }
        }
        delete[] verData;
    }
    return compileVer;
}

bool Application::openURL(const std::string &url)
{
    WCHAR *temp = new WCHAR[url.size() + 1];
    int wchars_num = MultiByteToWideChar(CP_UTF8, 0, url.c_str(), url.size() + 1, temp, url.size() + 1);
    HINSTANCE r = ShellExecuteW(NULL, L"open", temp, NULL, NULL, SW_SHOWNORMAL);
    delete[] temp;
    return (size_t)r>32;
}

void Application::setResourceRootPath(const std::string& rootResDir)
{
    _resourceRootPath = rootResDir;
    std::replace(_resourceRootPath.begin(), _resourceRootPath.end(), '\\', '/');
    if (_resourceRootPath[_resourceRootPath.length() - 1] != '/')
    {
        _resourceRootPath += '/';
    }
    FileUtils* pFileUtils = FileUtils::getInstance();
    std::vector<std::string> searchPaths = pFileUtils->getSearchPaths();
    searchPaths.insert(searchPaths.begin(), _resourceRootPath);
    pFileUtils->setSearchPaths(searchPaths);
}

const std::string& Application::getResourceRootPath(void)
{
    return _resourceRootPath;
}

void Application::setStartupScriptFilename(const std::string& startupScriptFile)
{
    _startupScriptFilename = startupScriptFile;
    std::replace(_startupScriptFilename.begin(), _startupScriptFilename.end(), '\\', '/');
}

NS_CC_END

//////////////////////////////////////////////////////////////////////////
// Local function
//////////////////////////////////////////////////////////////////////////
static void PVRFrameEnableControlWindow(bool bEnable)
{
    HKEY hKey = 0;

    // Open PVRFrame control key, if not exist create it.
    if(ERROR_SUCCESS != RegCreateKeyExW(HKEY_CURRENT_USER,
        L"Software\\Imagination Technologies\\PVRVFRame\\STARTUP\\",
        0,
        0,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        0,
        &hKey,
        nullptr))
    {
        return;
    }

    const WCHAR* wszValue = L"hide_gui";
    const WCHAR* wszNewData = (bEnable) ? L"NO" : L"YES";
    WCHAR wszOldData[256] = {0};
    DWORD   dwSize = sizeof(wszOldData);
    LSTATUS status = RegQueryValueExW(hKey, wszValue, 0, nullptr, (LPBYTE)wszOldData, &dwSize);
    if (ERROR_FILE_NOT_FOUND == status              // the key not exist
        || (ERROR_SUCCESS == status                 // or the hide_gui value is exist
        && 0 != wcscmp(wszNewData, wszOldData)))    // but new data and old data not equal
    {
        dwSize = sizeof(WCHAR) * (wcslen(wszNewData) + 1);
        RegSetValueEx(hKey, wszValue, 0, REG_SZ, (const BYTE *)wszNewData, dwSize);
    }

    RegCloseKey(hKey);
}

static HMODULE GetSelfModuleHandle() {
    MEMORY_BASIC_INFORMATION mbi;

    return ((::VirtualQuery(GetSelfModuleHandle, &mbi, sizeof(mbi)) != 0)
        ? (HMODULE)mbi.AllocationBase : NULL);
}