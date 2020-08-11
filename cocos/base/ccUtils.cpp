/****************************************************************************
Copyright (c) 2010      cocos2d-x.org
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
Copyright (c) 2020 c4games.com

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

#include "base/ccUtils.h"

#include <cmath>
#include <stdlib.h>

#include <signal.h>
#if !defined(_WIN32)
// for unix/linux kill
#include <unistd.h>
#endif

#include "md5/md5.h"

#include "base/CCDirector.h"
#include "base/CCAsyncTaskPool.h"
#include "base/CCEventDispatcher.h"
#include "base/base64.h"
#include "base/ccConstants.h"
#include "base/ccUTF8.h"
#include "renderer/CCCustomCommand.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCRenderState.h"
#include "renderer/backend/Types.h"
#include "renderer/backend/PixelBufferDescriptor.h"

#include "platform/CCImage.h"
#include "platform/CCFileUtils.h"
#include "2d/CCSprite.h"
#include "2d/CCRenderTexture.h"

NS_CC_BEGIN

int ccNextPOT(int x)
{
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >>16);
    return x + 1;
}

namespace utils
{
/*
 * Capture screen interface
 */
static EventListenerCustom* s_captureScreenListener;
static CallbackCommand s_captureScreenCommand;
void captureScreen(std::function<void(RefPtr<Image>)> imageCallback)
{
    if (s_captureScreenListener)
    {
        CCLOG("Warning: CaptureScreen has been called already, don't call more than once in one frame.");
        return;
    }

    auto director = Director::getInstance();
    auto renderer = director->getRenderer();
    auto eventDispatcher = director->getEventDispatcher();

    s_captureScreenListener = eventDispatcher->addCustomEventListener(Director::EVENT_AFTER_DRAW, [=](EventCustom* /*event*/) {
        eventDispatcher->removeEventListener(s_captureScreenListener);
        s_captureScreenListener = nullptr;
        
        // !!!GL: AFTER_DRAW and BEFORE_END_FRAME
        renderer->readPixels(nullptr, [=](const backend::PixelBufferDescriptor& pbd) {
            if (pbd) {
                auto image = utils::makeInstance<Image>(&Image::initWithRawData, pbd._data.getBytes(), pbd._data.getSize(), pbd._width, pbd._height, 8, false);
                imageCallback(image);
            }
            else imageCallback(nullptr);
            });
    });
}

static std::unordered_map<Node*, EventListenerCustom*> s_captureNodeListener;
void captureNode(Node* startNode, std::function<void(RefPtr<Image>)> imageCallback, float scale)
{
    if (s_captureNodeListener.find(startNode) != s_captureNodeListener.end())
    {
        CCLOG("Warning: current node has been captured already");
        return;
    }

    auto callback = [startNode, scale, imageCallback](EventCustom* /*event*/) {
        auto director = Director::getInstance();
        auto captureNodeListener = s_captureNodeListener[startNode];
        director->getEventDispatcher()->removeEventListener((EventListener*)(captureNodeListener));
        s_captureNodeListener.erase(startNode);
        auto& size = startNode->getContentSize();
        
        director->setNextDeltaTimeZero(true);
        
        RenderTexture* finalRtx = nullptr;
        
        auto rtx = RenderTexture::create(size.width, size.height, backend::PixelFormat::RGBA8888, PixelFormat::D24S8);
        // rtx->setKeepMatrix(true);
        Point savedPos = startNode->getPosition();
        Point anchor;
        if (!startNode->isIgnoreAnchorPointForPosition()) {
            anchor = startNode->getAnchorPoint();
        }
        startNode->setPosition(Point(size.width * anchor.x, size.height * anchor.y));
        rtx->begin();
        startNode->visit();
        rtx->end();
        startNode->setPosition(savedPos);
        
        if (std::abs(scale - 1.0f) < 1e-6f/* no scale */)
            finalRtx = rtx;
        else {
            /* scale */
            auto finalRect = Rect(0, 0, size.width, size.height);
            Sprite *sprite = Sprite::createWithTexture(rtx->getSprite()->getTexture(), finalRect);
            sprite->setAnchorPoint(Point(0, 0));
            sprite->setFlippedY(true);
            finalRtx = RenderTexture::create(size.width * scale, size.height * scale, backend::PixelFormat::RGBA8888, PixelFormat::D24S8);
            
            sprite->setScale(scale); // or use finalRtx->setKeepMatrix(true);
            finalRtx->begin();
            sprite->visit();
            finalRtx->end();
        }

        director->getRenderer()->render();
        
        finalRtx->newImage(imageCallback);
    };
    
    auto listener = Director::getInstance()->getEventDispatcher()->addCustomEventListener(Director::EVENT_BEFORE_DRAW, callback);
    
    s_captureNodeListener[startNode] = listener;
}

// [DEPRECATED]
void captureScreen(std::function<void(bool, const std::string&)> afterCap, const std::string& filename)
{
    std::string outfile;
    if (FileUtils::getInstance()->isAbsolutePath(filename))
        outfile = filename;
    else
        outfile = FileUtils::getInstance()->getWritablePath() + filename;

    captureScreen([_afterCap = std::move(afterCap), _outfile = std::move(outfile)](RefPtr<Image> image) mutable {
        AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_IO, [_afterCap = std::move(_afterCap), image = std::move(image), _outfile = std::move(_outfile)]() mutable
        {
            bool ok = image->saveToFile(_outfile);
            Director::getInstance()->getScheduler()->performFunctionInCocosThread([ok, _afterCap = std::move(_afterCap), _outfile = std::move(_outfile)]{
                _afterCap(ok, _outfile);
                });
        });
    });
}

std::vector<Node*> findChildren(const Node &node, const std::string &name)
{
    std::vector<Node*> vec;
    
    node.enumerateChildren(name, [&vec](Node* nodeFound) -> bool {
        vec.push_back(nodeFound);
        return false;
    });

    return vec;
}

#define MAX_ITOA_BUFFER_SIZE 256
double atof(const char* str)
{
    if (str == nullptr)
    {
        return 0.0;
    }
    
    char buf[MAX_ITOA_BUFFER_SIZE];
    strncpy(buf, str, MAX_ITOA_BUFFER_SIZE);
    
    // strip string, only remain 7 numbers after '.'
    char* dot = strchr(buf, '.');
    if (dot != nullptr && dot - buf + 8 <  MAX_ITOA_BUFFER_SIZE)
    {
        dot[8] = '\0';
    }
    
    return ::atof(buf);
}

double gettime()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);

    return (double)tv.tv_sec + (double)tv.tv_usec/1000000;
}

long long getTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday (&tv, nullptr);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

Rect getCascadeBoundingBox(Node *node)
{
    Rect cbb;
    Size contentSize = node->getContentSize();
    
    // check all children bounding box, get maximize box
    Node* child = nullptr;
    bool merge = false;
    for(auto object : node->getChildren())
    {
        child = dynamic_cast<Node*>(object);
        if (!child->isVisible()) continue;
        
        const Rect box = getCascadeBoundingBox(child);
        if (box.size.width <= 0 || box.size.height <= 0) continue;
        
        if (!merge)
        {
            cbb = box;
            merge = true;
        }
        else
        {
            cbb.merge(box);
        }
    }
    
    // merge content size
    if (contentSize.width > 0 && contentSize.height > 0)
    {
        const Rect box = RectApplyAffineTransform(Rect(0, 0, contentSize.width, contentSize.height), node->getNodeToWorldAffineTransform());
        if (!merge)
        {
            cbb = box;
        }
        else
        {
            cbb.merge(box);
        }
    }
    
    return cbb;
}

Sprite* createSpriteFromBase64Cached(const char* base64String, const char* key)
{
    Texture2D* texture = Director::getInstance()->getTextureCache()->getTextureForKey(key);

    if (texture == nullptr)
    {
        unsigned char* decoded;
        int length = base64Decode((const unsigned char*)base64String, (unsigned int)strlen(base64String), &decoded);

        Image *image = new (std::nothrow) Image();
        bool imageResult = image->initWithImageData(decoded, length, true);
        CCASSERT(imageResult, "Failed to create image from base64!");

        if (!imageResult) {
            CC_SAFE_RELEASE_NULL(image);
            return nullptr;
        }

        texture = Director::getInstance()->getTextureCache()->addImage(image, key);
        image->release();
    }

    Sprite* sprite = Sprite::createWithTexture(texture);
    
    return sprite;
}

Sprite* createSpriteFromBase64(const char* base64String)
{
    unsigned char* decoded;
    int length = base64Decode((const unsigned char*)base64String, (unsigned int)strlen(base64String), &decoded);

    Image *image = new (std::nothrow) Image();
    bool imageResult = image->initWithImageData(decoded, length, decoded);
    CCASSERT(imageResult, "Failed to create image from base64!");

    if (!imageResult) {
        CC_SAFE_RELEASE_NULL(image);
        return nullptr;
    }

    Texture2D *texture = new (std::nothrow) Texture2D();
    texture->initWithImage(image);
    texture->setAliasTexParameters();
    image->release();

    Sprite* sprite = Sprite::createWithTexture(texture);
    texture->release();

    return sprite;
}

Node* findChild(Node* levelRoot, const std::string& name)
{
    if (levelRoot == nullptr || name.empty())
        return nullptr;

    // Find this node
    auto target = levelRoot->getChildByName(name);
    if (target != nullptr)
        return target;

    // Find recursively
    for (auto& child : levelRoot->getChildren())
    {
        target = findChild(child, name);
        if (target != nullptr)
            return target;
    }
    return nullptr;
}

Node* findChild(Node* levelRoot, int tag)
{
    if (levelRoot == nullptr || tag == Node::INVALID_TAG)
        return nullptr;

    // Find this node
    auto target = levelRoot->getChildByTag(tag);
    if (target != nullptr)
        return target;

    // Find recursively
    for (auto& child : levelRoot->getChildren())
    {
        target = findChild(child, tag);
        if (target != nullptr)
            return target;
    }

    return nullptr;
}

std::string getFileMD5Hash(const std::string &filename)
{
    Data data;
    FileUtils::getInstance()->getContents(filename, &data);

    return getDataMD5Hash(data);
}

std::string getDataMD5Hash(const Data &data)
{
    static const unsigned int MD5_DIGEST_LENGTH = 16;

    if (data.isNull())
    {
        return std::string();
    }

    md5_state_t state;
    md5_byte_t digest[MD5_DIGEST_LENGTH];
    char hexOutput[(MD5_DIGEST_LENGTH << 1) + 1] = { 0 };

    md5_init(&state);
    md5_append(&state, (const md5_byte_t *)data.getBytes(), (int)data.getSize());
    md5_finish(&state, digest);

    for (int di = 0; di < 16; ++di)
        sprintf(hexOutput + di * 2, "%02x", digest[di]);

    return hexOutput;
}

LanguageType getLanguageTypeByISO2(const char* code)
{
    // this function is used by all platforms to get system language
    // except windows: cocos/platform/win32/CCApplication-win32.cpp
    LanguageType ret = LanguageType::ENGLISH;

    if (strncmp(code, "zh", 2) == 0)
    {
        ret = LanguageType::CHINESE;
    }
    else if (strncmp(code, "ja", 2) == 0)
    {
        ret = LanguageType::JAPANESE;
    }
    else if (strncmp(code, "fr", 2) == 0)
    {
        ret = LanguageType::FRENCH;
    }
    else if (strncmp(code, "it", 2) == 0)
    {
        ret = LanguageType::ITALIAN;
    }
    else if (strncmp(code, "de", 2) == 0)
    {
        ret = LanguageType::GERMAN;
    }
    else if (strncmp(code, "es", 2) == 0)
    {
        ret = LanguageType::SPANISH;
    }
    else if (strncmp(code, "nl", 2) == 0)
    {
        ret = LanguageType::DUTCH;
    }
    else if (strncmp(code, "ru", 2) == 0)
    {
        ret = LanguageType::RUSSIAN;
    }
    else if (strncmp(code, "hu", 2) == 0)
    {
        ret = LanguageType::HUNGARIAN;
    }
    else if (strncmp(code, "pt", 2) == 0)
    {
        ret = LanguageType::PORTUGUESE;
    }
    else if (strncmp(code, "ko", 2) == 0)
    {
        ret = LanguageType::KOREAN;
    }
    else if (strncmp(code, "ar", 2) == 0)
    {
        ret = LanguageType::ARABIC;
    }
    else if (strncmp(code, "nb", 2) == 0)
    {
        ret = LanguageType::NORWEGIAN;
    }
    else if (strncmp(code, "pl", 2) == 0)
    {
        ret = LanguageType::POLISH;
    }
    else if (strncmp(code, "tr", 2) == 0)
    {
        ret = LanguageType::TURKISH;
    }
    else if (strncmp(code, "uk", 2) == 0)
    {
        ret = LanguageType::UKRAINIAN;
    }
    else if (strncmp(code, "ro", 2) == 0)
    {
        ret = LanguageType::ROMANIAN;
    }
    else if (strncmp(code, "bg", 2) == 0)
    {
        ret = LanguageType::BULGARIAN;
    }
    else if (strncmp(code, "be", 2) == 0)
    {
        ret = LanguageType::BELARUSIAN;
    }
    return ret;
}
    
backend::BlendFactor toBackendBlendFactor(int factor)
{
    switch (factor) {
        case GLBlendConst::ONE:
            return backend::BlendFactor::ONE;
        case GLBlendConst::ZERO:
            return backend::BlendFactor::ZERO;
        case GLBlendConst::SRC_COLOR:
            return backend::BlendFactor::SRC_COLOR;
        case GLBlendConst::ONE_MINUS_SRC_COLOR:
            return backend::BlendFactor::ONE_MINUS_SRC_COLOR;
        case GLBlendConst::SRC_ALPHA:
            return backend::BlendFactor::SRC_ALPHA;
        case GLBlendConst::ONE_MINUS_SRC_ALPHA:
            return backend::BlendFactor::ONE_MINUS_SRC_ALPHA;
        case GLBlendConst::DST_COLOR:
            return backend::BlendFactor::DST_COLOR;
        case GLBlendConst::ONE_MINUS_DST_COLOR:
            return backend::BlendFactor::ONE_MINUS_DST_COLOR;
        case GLBlendConst::DST_ALPHA:
            return backend::BlendFactor::DST_ALPHA;
        case GLBlendConst::ONE_MINUS_DST_ALPHA:
            return backend::BlendFactor::ONE_MINUS_DST_ALPHA;
        case GLBlendConst::SRC_ALPHA_SATURATE:
            return backend::BlendFactor::SRC_ALPHA_SATURATE;
        case GLBlendConst::BLEND_COLOR:
            return backend::BlendFactor::BLEND_CLOLOR;
        case GLBlendConst::CONSTANT_ALPHA:
            return backend::BlendFactor::CONSTANT_ALPHA;
        case GLBlendConst::ONE_MINUS_CONSTANT_ALPHA:
            return backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA;
        default:
            assert(false);
            break;
    }
    return backend::BlendFactor::ONE;
}

int toGLBlendFactor(backend::BlendFactor blendFactor)
{
    int ret = GLBlendConst::ONE;
    switch (blendFactor)
    {
    case backend::BlendFactor::ZERO:
        ret = GLBlendConst::ZERO;
        break;
    case backend::BlendFactor::ONE:
        ret = GLBlendConst::ONE;
        break;
    case backend::BlendFactor::SRC_COLOR:
        ret = GLBlendConst::SRC_COLOR;
        break;
    case backend::BlendFactor::ONE_MINUS_SRC_COLOR:
        ret = GLBlendConst::ONE_MINUS_SRC_COLOR;
        break;
    case backend::BlendFactor::SRC_ALPHA:
        ret = GLBlendConst::SRC_ALPHA;
        break;
    case backend::BlendFactor::ONE_MINUS_SRC_ALPHA:
        ret = GLBlendConst::ONE_MINUS_SRC_ALPHA;
        break;
    case backend::BlendFactor::DST_COLOR:
        ret = GLBlendConst::DST_COLOR;
        break;
    case backend::BlendFactor::ONE_MINUS_DST_COLOR:
        ret = GLBlendConst::ONE_MINUS_DST_COLOR;
        break;
    case backend::BlendFactor::DST_ALPHA:
        ret = GLBlendConst::DST_ALPHA;
        break;
    case backend::BlendFactor::ONE_MINUS_DST_ALPHA:
        ret = GLBlendConst::ONE_MINUS_DST_ALPHA;
        break;
    case backend::BlendFactor::SRC_ALPHA_SATURATE:
        ret = GLBlendConst::SRC_ALPHA_SATURATE;
        break;
    case backend::BlendFactor::BLEND_CLOLOR:
        ret = GLBlendConst::BLEND_COLOR;
        break;
    default:
        break;
    }
    return ret;
}

backend::SamplerFilter toBackendSamplerFilter(int mode)
{
    switch (mode)
    {
    case GLTexParamConst::LINEAR:
    case GLTexParamConst::LINEAR_MIPMAP_LINEAR:
    case GLTexParamConst::LINEAR_MIPMAP_NEAREST:
    case GLTexParamConst::NEAREST_MIPMAP_LINEAR:
        return backend::SamplerFilter::LINEAR;
    case GLTexParamConst::NEAREST:
    case GLTexParamConst::NEAREST_MIPMAP_NEAREST:
        return backend::SamplerFilter::NEAREST;
    default:
        CCASSERT(false, "invalid GL sampler filter!");
        return backend::SamplerFilter::LINEAR;
    }
}

backend::SamplerAddressMode toBackendAddressMode(int mode)
{
    switch (mode)
    {
    case GLTexParamConst::REPEAT:
        return backend::SamplerAddressMode::REPEAT;
    case GLTexParamConst::CLAMP:
    case GLTexParamConst::CLAMP_TO_EDGE:
        return backend::SamplerAddressMode::CLAMP_TO_EDGE;
    case GLTexParamConst::MIRROR_REPEAT:
        return backend::SamplerAddressMode::MIRROR_REPEAT;
    default:
        CCASSERT(false, "invalid GL address mode");
        return backend::SamplerAddressMode::REPEAT;
    }
}

const Mat4& getAdjustMatrix()
{
    static cocos2d::Mat4 adjustMatrix = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 0.5, 0.5,
        0, 0, 0, 1
    };

    return adjustMatrix;
}

std::vector<float> getNormalMat3OfMat4(const Mat4 &mat)
{
    std::vector<float> normalMat(9);
    Mat4 mvInverse = mat;
    mvInverse.m[12] = mvInverse.m[13] = mvInverse.m[14] = 0.0f;
    mvInverse.inverse();
    mvInverse.transpose();
    normalMat[0] = mvInverse.m[0]; normalMat[1] = mvInverse.m[1]; normalMat[2] = mvInverse.m[2];
    normalMat[3] = mvInverse.m[4]; normalMat[4] = mvInverse.m[5]; normalMat[5] = mvInverse.m[6];
    normalMat[6] = mvInverse.m[8]; normalMat[7] = mvInverse.m[9]; normalMat[8] = mvInverse.m[10];
    return normalMat;
}

std::vector<int> parseIntegerList(const std::string &intsString) {
    std::vector<int> result;

    const char *cStr = intsString.c_str();
    char *endptr;

    for (long int i = strtol(cStr, &endptr, 10); endptr != cStr; i = strtol(cStr, &endptr, 10)) {
        if (errno == ERANGE) {
            errno = 0;
            CCLOGWARN("%s contains out of range integers", intsString.c_str());
        }
        result.push_back(static_cast<int>(i));
        cStr= endptr;
    }

    return result;
}

std::string bin2hex(const std::string& binary /*charstring also regard as binary in C/C++*/, int delim, bool prefix)
{
    char low;
    char high;
    size_t len = binary.length();

    bool delim_needed = delim != -1 || delim == ' ';

    std::string result;
    result.reserve((len << 1) + (delim_needed ? len : 0) + (prefix ? (len << 1) : 0));


    for (size_t i = 0; i < len; ++i)
    {
        auto ch = binary[i];
        high = (ch >> 4) & 0x0f;
        low = ch & 0x0f;
        if (prefix) {
            result.push_back('0');
            result.push_back('x');
        }

        auto hic = CC_HEX2CHAR(high);
        auto lic = CC_HEX2CHAR(low);
        result.push_back(hic);
        result.push_back(lic);
        if (delim_needed)
        {
            result.push_back(delim);
        }
    }

    return result;
}

void killCurrentProcess()
{
#if !defined(_WIN32)
    ::kill(::getpid(), SIGKILL);
#else
    ::TerminateProcess(::GetCurrentProcess(), SIGTERM);
#endif
}

// 多字节编码转为UTF8编码
bool MBToUTF8(std::string& pu8, const char* pmb, int mLen) {
    std::vector<char> vec = std::vector<char>();
    if (MBToUTF8(vec, pmb, mLen)) {
        pu8.assign(vec.data(), vec.size());
        return true;
    }
    return false;
}

bool MBToUTF8(std::vector<char>& pu8, const char* pmb, int mLen)
{
	// convert an MBCS string to widechar   
	int nLen = MultiByteToWideChar(CP_ACP, 0, pmb, mLen, NULL, 0);

	WCHAR* lpszW = new WCHAR[nLen];

	int nRtn = MultiByteToWideChar(CP_ACP, 0, pmb, mLen, lpszW, nLen);

	if (nRtn != nLen)
	{
		delete[] lpszW;
		return false;
	}
	// convert an widechar string to utf8  
	int utf8Len = WideCharToMultiByte(CP_UTF8, 0, lpszW, nLen, NULL, 0, NULL, NULL);
	if (utf8Len <= 0)
	{
		return false;
	}
	pu8.resize(utf8Len);
	nRtn = WideCharToMultiByte(CP_UTF8, 0, lpszW, nLen, &*pu8.begin(), utf8Len, NULL, NULL);
	delete[] lpszW;

	if (nRtn != utf8Len)
	{
		pu8.clear();
		return false;
	}
	return true;
}

// UTF8编码转为多字节编码  
bool UTF8ToMB(std::string& pmb, const char* pu8, int utf8Len) {
    std::vector<char> vec = std::vector<char>();
    if (UTF8ToMB(vec, pu8, utf8Len)) {
        pmb.assign(vec.data(), vec.size());
        return true;
    }
    return false;
}
bool UTF8ToMB(std::vector<char>& pmb, const char* pu8, int utf8Len)
{
	// convert an UTF8 string to widechar   
	int nLen = MultiByteToWideChar(CP_UTF8, 0, pu8, utf8Len, NULL, 0);

	WCHAR* lpszW = new WCHAR[nLen];

	int nRtn = MultiByteToWideChar(CP_UTF8, 0, pu8, utf8Len, lpszW, nLen);

	if (nRtn != nLen)
	{
		delete[] lpszW;
		return false;
	}

	// convert an widechar string to Multibyte   
	int MBLen = WideCharToMultiByte(CP_ACP, 0, lpszW, nLen, NULL, 0, NULL, NULL);
	if (MBLen <= 0)
	{
		return false;
	}
	pmb.resize(MBLen);
	nRtn = WideCharToMultiByte(CP_ACP, 0, lpszW, nLen, &*pmb.begin(), MBLen, NULL, NULL);
	delete[] lpszW;

	if (nRtn != MBLen)
	{
		pmb.clear();
		return false;
	}
	return true;
}

// 多字节编码转为Unicode编码  
bool MBToUnicode(std::vector<wchar_t>& pun, const char* pmb, int mLen)
{
	// convert an MBCS string to widechar   
	int uLen = MultiByteToWideChar(CP_ACP, 0, pmb, mLen, NULL, 0);

	if (uLen <= 0)
	{
		return false;
	}
	pun.resize(uLen);

	int nRtn = MultiByteToWideChar(CP_ACP, 0, pmb, mLen, &*pun.begin(), uLen);

	if (nRtn != uLen)
	{
		pun.clear();
		return false;
	}
	return true;
}

//Unicode编码转为多字节编码  
bool UnicodeToMB(std::vector<char>& pmb, const wchar_t* pun, int uLen)
{
	// convert an widechar string to Multibyte   
	int MBLen = WideCharToMultiByte(CP_ACP, 0, pun, uLen, NULL, 0, NULL, NULL);
	if (MBLen <= 0)
	{
		return false;
	}
	pmb.resize(MBLen);
	int nRtn = WideCharToMultiByte(CP_ACP, 0, pun, uLen, &*pmb.begin(), MBLen, NULL, NULL);

	if (nRtn != MBLen)
	{
		pmb.clear();
		return false;
	}
	return true;
}

// UTF8编码转为Unicode  
bool UTF8ToUnicode(std::vector<wchar_t>& pun, const char* pu8, int utf8Len)
{
	// convert an UTF8 string to widechar   
	int nLen = MultiByteToWideChar(CP_UTF8, 0, pu8, utf8Len, NULL, 0);
	if (nLen <= 0)
	{
		return false;
	}
	pun.resize(nLen);
	int nRtn = MultiByteToWideChar(CP_UTF8, 0, pu8, utf8Len, &*pun.begin(), nLen);

	if (nRtn != nLen)
	{
		pun.clear();
		return false;
	}

	return true;
}

// Unicode编码转为UTF8  
bool UnicodeToUTF8(std::vector<char>& pu8, const wchar_t* pun, int uLen)
{
	// convert an widechar string to utf8  
	int utf8Len = WideCharToMultiByte(CP_UTF8, 0, pun, uLen, NULL, 0, NULL, NULL);
	if (utf8Len <= 0)
	{
		return false;
	}
	pu8.resize(utf8Len);
	int nRtn = WideCharToMultiByte(CP_UTF8, 0, pun, uLen, &*pu8.begin(), utf8Len, NULL, NULL);

	if (nRtn != utf8Len)
	{
		pu8.clear();
		return false;
	}
	return true;
}

static int invalid_date(const struct tm* ptm) {
#define datevalue_in_range(min, max, value) ((min) <= (value) && (value) <= (max))
    return (!datevalue_in_range(0, 207, ptm->tm_year) ||
        !datevalue_in_range(0, 11, ptm->tm_mon) ||
        !datevalue_in_range(1, 31, ptm->tm_mday) ||
        !datevalue_in_range(0, 23, ptm->tm_hour) ||
        !datevalue_in_range(0, 59, ptm->tm_min) ||
        !datevalue_in_range(0, 59, ptm->tm_sec));
#undef datevalue_in_range
}

uint32_t Time2DosDate(const struct tm* ptm) {
    struct tm fixed_tm;

    /* Years supported:
    * [00, 79]      (assumed to be between 2000 and 2079)
    * [80, 207]     (assumed to be between 1980 and 2107, typical output of old
                     software that does 'year-1900' to get a double digit year)
    * [1980, 2107]  (due to the date format limitations, only years between 1980 and 2107 can be stored.)
    */

    memcpy(&fixed_tm, ptm, sizeof(struct tm));
    if (fixed_tm.tm_year >= 1980) /* range [1980, 2107] */
        fixed_tm.tm_year -= 1980;
    else if (fixed_tm.tm_year >= 80) /* range [80, 99] */
        fixed_tm.tm_year -= 80;
    else /* range [00, 79] */
        fixed_tm.tm_year += 20;

    if (invalid_date(ptm))
        return 0;

    return (uint32_t)(((fixed_tm.tm_mday) + (32 * (fixed_tm.tm_mon + 1)) + (512 * fixed_tm.tm_year)) << 16) |
        ((fixed_tm.tm_sec / 2) + (32 * fixed_tm.tm_min) + (2048 * (uint32_t)fixed_tm.tm_hour));
}

}

NS_CC_END
