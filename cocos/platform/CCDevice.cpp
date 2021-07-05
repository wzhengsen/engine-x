/****************************************************************************
 Copyright (c) 2021 wzhengsen

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
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||\
CC_TARGET_PLATFORM == CC_PLATFORM_LINUX ||\
CC_TARGET_PLATFORM == CC_PLATFORM_MAC
#include "platform/CCDevice.h"
#include "platform/CCFileUtils.h"
#include "platform/CCStdC.h"
#include "rapidjson/document.h"
#include "rapidjson/reader.h"

using namespace rapidjson;

NS_CC_BEGIN

Device::OrientationType Device::GetOrientation() {
    // The value of the first time, judging isLandscape in config.json as the basis.
    if (!firstGetOri) {
        firstGetOri = true;

        auto fu = FileUtils::getInstance();
        const std::string fileName = fu->fullPathForFilename("config.json");
        const std::string content = fu->getStringFromFile(fileName);
        Document docRootjson = Document();
        if (!docRootjson.Parse<ParseFlag::kParseNoFlags>(content.c_str()).HasParseError()
            && docRootjson.HasMember("isLandscape")
            && docRootjson["isLandscape"].IsBool()
            && !docRootjson["isLandscape"].GetBool()
            ) {
            curOriType = Device::OrientationType::Portrait;
        }
    }
    return curOriType;
}

void Device::SetOrientation(OrientationType ot) {
    if (ot == curOriType) {
        return;
    }
    if (ot != OrientationType::Auto) {
        firstGetOri = true;
        isAutoOri = false;
        curOriType = ot;

#if CC_ENABLE_LUA_BINDING
        auto e = Director::getInstance()->getEventDispatcher();
        if (ot == OrientationType::Landscape) {
            e->dispatchCustomEvent("DeviceToLandscape");
        }
        else if (ot == OrientationType::Portrait) {
            e->dispatchCustomEvent("DeviceToPortrait");
        }
#endif
    }
    else {
        isAutoOri = true;
    }
}

bool Device::IsAutoOrientation() noexcept {
    return isAutoOri;
}

NS_CC_END
#endif