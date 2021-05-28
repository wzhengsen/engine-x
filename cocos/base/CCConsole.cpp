/****************************************************************************
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 Copyright (c) 2020 c4games.com.

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

#include "base/CCConsole.h"

NS_CC_BEGIN

extern const char* cocos2dVersion(void);

void log(const char * format, ...)
{
    int bufferSize = MAX_LOG_LENGTH;
    char* buf = nullptr;
    int nret = 0;
    va_list args;
    do {
        buf = new (std::nothrow) char[bufferSize];
        if (buf == nullptr)
            return;
        /*
        pitfall: The behavior of vsnprintf between VS2013 and VS2015/2017 is different
        VS2013 or Unix-Like System will return -1 when buffer not enough, but VS2015/2017 will return the actural needed length for buffer at this station
        The _vsnprintf behavior is compatible API which always return -1 when buffer isn't enough at VS2013/2015/2017
        Yes, The vsnprintf is more efficient implemented by MSVC 19.0 or later, AND it's also standard-compliant, see reference: http://www.cplusplus.com/reference/cstdio/vsnprintf/
        */
        va_start(args, format);
        nret = vsnprintf(buf, bufferSize - 3, format, args);
        va_end(args);

        if (nret >= 0) { // VS2015/2017
            if (nret <= bufferSize - 3) {// success, so don't need to realloc
                break;
            }
            else {
                bufferSize = nret + 3;
                delete[] buf;
            }
        }
        else // < 0
        {	// VS2013 or Unix-like System(GCC)
            bufferSize *= 2;
            delete[] buf;
        }
    } while (true);
    buf[nret] = '\n';
    buf[++nret] = '\0';

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info", "%s", buf);

#elif CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32

    int pos = 0;
    int len = nret;
    char* tempBuf = new char[MAX_LOG_LENGTH + 1];
    WCHAR* wszBuf = new WCHAR[MAX_LOG_LENGTH + 1];

    do {
        std::copy(buf + pos, buf + pos + MAX_LOG_LENGTH, tempBuf);

        tempBuf[MAX_LOG_LENGTH] = 0;

        MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
        WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, sizeof(tempBuf), nullptr, FALSE);
        printf("%s", tempBuf);

        pos += MAX_LOG_LENGTH;

    } while (pos < len);
    delete[] tempBuf;
    delete[] wszBuf;
    fflush(stdout);
#else
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", buf);
    fflush(stdout);
#endif
    delete[] buf;
}

NS_CC_END
