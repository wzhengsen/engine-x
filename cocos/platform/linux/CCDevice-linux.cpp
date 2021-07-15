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
#include "platform/CCDevice.h"
#include "platform/CCFileUtils.h"

#include <X11/Xlib.h>
#include <stdio.h>

#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fontconfig/fontconfig.h>

#include "ft2build.h"
#include FT_FREETYPE_H

using namespace std;

// as FcFontMatch is quite an expensive call, cache the results of getFontFile
static std::map<std::string, std::string> fontCache;

struct LineBreakGlyph {
    FT_UInt glyphIndex;
    int paintPosition;
    int glyphWidth;

    int bearingX;
    int kerning;
    int horizAdvance;
};

struct LineBreakLine {
    LineBreakLine() : lineWidth(0) {}

    std::vector<LineBreakGlyph> glyphs;
    int lineWidth;

    void reset() {
        glyphs.clear();
        lineWidth = 0;
    }

    void calculateWidth() {
        lineWidth = 0;
        if ( glyphs.empty() == false ) {
            LineBreakGlyph& glyph = glyphs.at(glyphs.size() - 1);
            lineWidth = glyph.paintPosition + max(glyph.glyphWidth, glyph.horizAdvance - glyph.bearingX);
        }
    }
};

NS_CC_BEGIN

int Device::getDPI()
{
    static int dpi = -1;
    if (dpi == -1)
    {
        Display *dpy;
        char *displayname = NULL;
        int scr = 0; /* Screen number */
        dpy = XOpenDisplay (displayname);
        /*
         * there are 2.54 centimeters to an inch; so there are 25.4 millimeters.
         *
         *     dpi = N pixels / (M millimeters / (25.4 millimeters / 1 inch))
         *         = N pixels / (M inch / 25.4)
         *         = N * 25.4 pixels / M inch
         */
        double xres = ((((double) DisplayWidth(dpy,scr)) * 25.4) /
            ((double) DisplayWidthMM(dpy,scr)));
        dpi = (int) (xres + 0.5);
        //printf("dpi = %d\n", dpi);
        XCloseDisplay (dpy);
    }
    return dpi;
}

void Device::setAccelerometerEnabled(bool isEnabled)
{

}

void Device::setAccelerometerInterval(float interval)
{

}

class BitmapDC
{
private:
    static bool inited;
    static FT_Library library;
public:
    BitmapDC() {
        if (!inited) {
            libError = FT_Init_FreeType( &library );
            FcInit();
            inited = true;
        }
        _data = NULL;
        reset();
    }

    ~BitmapDC() {
        //fix me: Releasing resources here may conflict with gtk.
        //FT_Done_FreeType(library);
        //FcFini();

        reset();
    }

    void reset() {
        iMaxLineWidth = 0;
        iMaxLineHeight = 0;
        textLines.clear();
    }

    int utf8(char **p)
    {
        if ((**p & 0x80) == 0x00)
        {
            int a = *((*p)++);

            return a;
        }
        if ((**p & 0xE0) == 0xC0)
        {
            int a = *((*p)++) & 0x1F;
            int b = *((*p)++) & 0x3F;

            return (a << 6) | b;
        }
        if ((**p & 0xF0) == 0xE0)
        {
            int a = *((*p)++) & 0x0F;
            int b = *((*p)++) & 0x3F;
            int c = *((*p)++) & 0x3F;

            return (a << 12) | (b << 6) | c;
        }
        if ((**p & 0xF8) == 0xF0)
        {
            int a = *((*p)++) & 0x07;
            int b = *((*p)++) & 0x3F;
            int c = *((*p)++) & 0x3F;
            int d = *((*p)++) & 0x3F;

            return (a << 18) | (b << 12) | (c << 8) | d;
        }
        return 0;
    }

    bool isBreakPoint(FT_UInt currentCharacter, FT_UInt previousCharacter) {
        if ( previousCharacter == '-' || previousCharacter == '/' || previousCharacter == '\\' ) {
            // we can insert a line break after one of these characters
            return true;
        }
        return false;
    }

    bool divideString(FT_Face face, const char* sText, int iMaxWidth, int iMaxHeight) {
        const char* pText = sText;
        textLines.clear();
        iMaxLineWidth = 0;

        FT_UInt unicode;
        FT_UInt prevCharacter = 0;
        FT_UInt glyphIndex = 0;
        FT_UInt prevGlyphIndex = 0;
        FT_Vector delta;
        LineBreakLine currentLine;

        int currentPaintPosition = 0;
        int firstBreakIndex = -1;
        int lastBreakIndex = -1;
        bool hasKerning = FT_HAS_KERNING( face );
        while ((unicode=utf8((char**)&pText))) {
            if (unicode == '\n') {
                currentLine.calculateWidth();
                iMaxLineWidth = max(iMaxLineWidth, currentLine.lineWidth);
                textLines.push_back(currentLine);
                currentLine.reset();
                prevGlyphIndex = 0;
                prevCharacter = 0;
                firstBreakIndex = -1;
                lastBreakIndex = -1;
                currentPaintPosition = 0;
                continue;
            }

            if ( isBreakPoint(unicode, prevCharacter) ) {
                lastBreakIndex = currentLine.glyphs.size() - 1;
            }

            glyphIndex = FT_Get_Char_Index(face, unicode);
            if (FT_Load_Glyph(face, glyphIndex, FT_LOAD_DEFAULT)) {
                return false;
            }

            LineBreakGlyph glyph;
            glyph.glyphIndex = glyphIndex;
            glyph.glyphWidth = face->glyph->metrics.width >> 6;
            glyph.bearingX = face->glyph->metrics.horiBearingX >> 6;
            glyph.horizAdvance = face->glyph->metrics.horiAdvance >> 6;
            glyph.kerning = 0;

            if (prevGlyphIndex != 0 && hasKerning) {
                FT_Get_Kerning(face, prevGlyphIndex, glyphIndex, FT_KERNING_DEFAULT, &delta);
                glyph.kerning = delta.x >> 6;
            }

            if (iswspace(unicode)) {
                prevGlyphIndex = glyphIndex;
                prevCharacter = unicode;
                lastBreakIndex = currentLine.glyphs.size();

                if (firstBreakIndex == -1)
                    firstBreakIndex = lastBreakIndex;
            } else {
                if (iswspace(prevCharacter))
                    lastBreakIndex = currentLine.glyphs.size();

                if (iMaxWidth > 0 && currentPaintPosition + glyph.bearingX + glyph.kerning + glyph.glyphWidth > iMaxWidth) {
                    int glyphCount = currentLine.glyphs.size();
                    if ( lastBreakIndex >= 0 && lastBreakIndex < glyphCount && currentPaintPosition + glyph.bearingX + glyph.kerning + glyph.glyphWidth - currentLine.glyphs.at(lastBreakIndex).paintPosition < iMaxWidth ) {
                        // we insert a line break at our last break opportunity
                        std::vector<LineBreakGlyph> tempGlyphs;
                        std::vector<LineBreakGlyph>::iterator it = currentLine.glyphs.begin();
                        std::advance(it, lastBreakIndex);
                        tempGlyphs.insert(tempGlyphs.begin(), it, currentLine.glyphs.end());
                        if (firstBreakIndex == -1) {
                            currentLine.glyphs.erase(it, currentLine.glyphs.end());
                        } else {
                            it = currentLine.glyphs.begin();
                            std::advance(it, firstBreakIndex);
                            currentLine.glyphs.erase(it, currentLine.glyphs.end());
                        }
                        currentLine.calculateWidth();
                        iMaxLineWidth = max(iMaxLineWidth, currentLine.lineWidth);
                        textLines.push_back(currentLine);
                        currentLine.reset();
                        currentPaintPosition = 0;
                        for ( auto& glyph : tempGlyphs ) {
                            if ( currentLine.glyphs.empty() ) {
                                currentPaintPosition = -glyph.bearingX;
                                glyph.kerning = 0;
                            }
                            glyph.paintPosition = currentPaintPosition + glyph.bearingX + glyph.kerning;
                            currentLine.glyphs.push_back(glyph);
                            currentPaintPosition += glyph.kerning + glyph.horizAdvance;
                        }
                    } else {
                        // the current word is too big to fit into one line, insert line break right here
                        currentPaintPosition = 0;
                        glyph.kerning = 0;
                        currentLine.calculateWidth();
                        iMaxLineWidth = max(iMaxLineWidth, currentLine.lineWidth);
                        textLines.push_back(currentLine);
                        currentLine.reset();
                    }

                    prevGlyphIndex = 0;
                    prevCharacter = 0;
                    firstBreakIndex = -1;
                    lastBreakIndex = -1;
                } else {
                    prevGlyphIndex = glyphIndex;
                    prevCharacter = unicode;
                }
            }

            if ( currentLine.glyphs.empty() ) {
                currentPaintPosition = -glyph.bearingX;
            }
            glyph.paintPosition = currentPaintPosition + glyph.bearingX + glyph.kerning;
            currentLine.glyphs.push_back(glyph);
            currentPaintPosition += glyph.kerning + glyph.horizAdvance;
        }

        if ( currentLine.glyphs.empty() == false ) {
            currentLine.calculateWidth();
            iMaxLineWidth = max(iMaxLineWidth, currentLine.lineWidth);
            textLines.push_back(currentLine);
        }
        return true;
    }

    /**
     * compute the start pos of every line
     */
    int computeLineStart(FT_Face face, Device::TextAlign eAlignMask, int line) {
                int lineWidth = textLines.at(line).lineWidth;
        if (eAlignMask == Device::TextAlign::CENTER || eAlignMask == Device::TextAlign::TOP || eAlignMask == Device::TextAlign::BOTTOM) {
            return (iMaxLineWidth - lineWidth) / 2;
        } else if (eAlignMask == Device::TextAlign::RIGHT || eAlignMask == Device::TextAlign::TOP_RIGHT || eAlignMask == Device::TextAlign::BOTTOM_RIGHT) {
            return (iMaxLineWidth - lineWidth);
        }

        // left or other situation
        return 0;
    }

    int computeLineStartY( FT_Face face, Device::TextAlign eAlignMask, int txtHeight, int borderHeight ){
        int baseLinePos = ceilf(face->size->metrics.ascender/64.0f);
        if (eAlignMask == Device::TextAlign::CENTER || eAlignMask == Device::TextAlign::LEFT || eAlignMask == Device::TextAlign::RIGHT) {
            //vertical center
            return (borderHeight - txtHeight) / 2 + baseLinePos;
        } else if (eAlignMask == Device::TextAlign::BOTTOM_RIGHT || eAlignMask == Device::TextAlign::BOTTOM || eAlignMask == Device::TextAlign::BOTTOM_LEFT) {
            //vertical bottom
            return borderHeight - txtHeight + baseLinePos;
        }

        // top alignment
        return baseLinePos;
    }

    std::string getFontFile(const char* family_name) {
        std::string fontPath = family_name;

        std::map<std::string, std::string>::iterator it = fontCache.find(family_name);
        if ( it != fontCache.end() ) {
            return it->second;
        }

        // check if the parameter is a font file shipped with the application
        std::string lowerCasePath = fontPath;
        std::transform(lowerCasePath.begin(), lowerCasePath.end(), lowerCasePath.begin(), ::tolower);
        if ( lowerCasePath.find(".ttf") != std::string::npos ) {
            fontPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(fontPath);
            auto fileStream = cocos2d::FileUtils::getInstance()->openFileStream(fontPath, FileStream::Mode::READ);
            if ( fileStream ) {
                fontCache.insert(std::pair<std::string, std::string>(family_name, fontPath));
                return fontPath;
            }
        }

        // use fontconfig to match the parameter against the fonts installed on the system
        FcPattern *pattern = FcPatternBuild (0, FC_FAMILY, FcTypeString, family_name, (char *) 0);
        FcConfigSubstitute(0, pattern, FcMatchPattern);
        FcDefaultSubstitute(pattern);

        FcResult result;
        FcPattern *font = FcFontMatch(0, pattern, &result);
        if ( font ) {
            FcChar8 *s = NULL;
            if ( FcPatternGetString(font, FC_FILE, 0, &s) == FcResultMatch ) {
                fontPath = (const char*)s;

                FcPatternDestroy(font);
                FcPatternDestroy(pattern);

                fontCache.insert(std::pair<std::string, std::string>(family_name, fontPath));
                return fontPath;
            }
            FcPatternDestroy(font);
        }
        FcPatternDestroy(pattern);

        return family_name;
    }

    bool getBitmap(const char *text, const FontDefinition& textDefinition, Device::TextAlign eAlignMask) {
        if (libError) {
            return false;
        }

        FT_Face face;
        std::string fontfile = getFontFile(textDefinition._fontName.c_str());
        if ( FT_New_Face(library, fontfile.c_str(), 0, &face) ) {
            //no valid font found use default
            if ( FT_New_Face(library, "/usr/share/fonts/truetype/freefont/FreeSerif.ttf", 0, &face) ) {
                return false;
            }
        }

        //select utf8 charmap
        if ( FT_Select_Charmap(face, FT_ENCODING_UNICODE) ) {
            FT_Done_Face(face);
            return false;
        }

        if ( FT_Set_Pixel_Sizes(face, textDefinition._fontSize, textDefinition._fontSize) ) {
            FT_Done_Face(face);
            return false;
        }

        if ( divideString(face, text, textDefinition._dimensions.width, textDefinition._dimensions.height) == false ) {
            FT_Done_Face(face);
            return false;
        }

        //compute the final line width
        iMaxLineWidth = MAX(iMaxLineWidth, textDefinition._dimensions.width);

        //compute the final line height
        int lineHeight = face->size->metrics.height>>6;
        int txtHeight = (lineHeight * textLines.size());
        iMaxLineHeight = MAX(txtHeight, textDefinition._dimensions.height);

        _data = (unsigned char*)malloc(sizeof(unsigned char) * (iMaxLineWidth * iMaxLineHeight * 4));
        memset(_data,0, iMaxLineWidth * iMaxLineHeight*4);

        int iCurYCursor = computeLineStartY(face, eAlignMask, txtHeight, iMaxLineHeight);

        int lineCount = textLines.size();
        for (int line = 0; line < lineCount; line++) {
            int iCurXCursor = computeLineStart(face, eAlignMask, line);

            int glyphCount = textLines.at(line).glyphs.size();
            for (int i = 0; i < glyphCount; i++) {
                LineBreakGlyph glyph = textLines.at(line).glyphs.at(i);

                if (FT_Load_Glyph(face, glyph.glyphIndex, FT_LOAD_RENDER)) {
                    continue;
                }

                FT_Bitmap& bitmap = face->glyph->bitmap;
                int yoffset = iCurYCursor - (face->glyph->metrics.horiBearingY >> 6);
                int xoffset = iCurXCursor + glyph.paintPosition;

                for (int y = 0; y < bitmap.rows; ++y) {
                    int iY = yoffset + y;
                    if (iY>=iMaxLineHeight) {
                        //exceed the height truncate
                        break;
                    }
                    iY *= iMaxLineWidth;

                    int bitmap_y = y * bitmap.width;

                    for (int x = 0; x < bitmap.width; ++x) {
                        unsigned char cTemp = bitmap.buffer[bitmap_y + x];
                        if (cTemp == 0) {
                            continue;
                        }

                        int iX = xoffset + x;
                        //FIXME:wrong text color
                        int iTemp = cTemp << 24 | cTemp << 16 | cTemp << 8 | cTemp;
                        *(int*) &_data[(iY + iX) * 4 + 0] = iTemp;
                    }
                }
            }
            // step to next line
            iCurYCursor += lineHeight;
        }

        //  free face
        FT_Done_Face(face);
        return true;
    }

public:

    unsigned char *_data;
    int libError;
    std::vector<LineBreakLine> textLines;
    int iMaxLineWidth;
    int iMaxLineHeight;
};

static BitmapDC& sharedBitmapDC()
{
    static BitmapDC s_BmpDC;
    return s_BmpDC;
}
bool BitmapDC::inited = false;
FT_Library BitmapDC::library = nullptr;

Data Device::getTextureDataForText(const char * text, const FontDefinition& textDefinition, TextAlign align, int &width, int &height, bool& hasPremultipliedAlpha)
{
    Data ret;
    do
    {
        BitmapDC &dc = sharedBitmapDC();

        CC_BREAK_IF(! dc.getBitmap(text, textDefinition, align));
        CC_BREAK_IF(! dc._data);
        width = dc.iMaxLineWidth;
        height = dc.iMaxLineHeight;
        dc.reset();
        ret.fastSet(dc._data,width * height * 4);
        hasPremultipliedAlpha = true;
    } while (0);

    return ret;
}

void Device::setKeepScreenOn(bool /*value*/)
{
}

void Device::vibrate(float duration) {
    uint64_t time = duration * 1000;
    static bool inVibrate = false;
    if (inVibrate || time <= 0) {
        return;
    }

    uint32_t repeat = time / 20 + 1;
    cocos2d::Director* director = cocos2d::Director::getInstance();
    cocos2d::Scheduler* sh = director->getScheduler();
    cocos2d::GLView* glView = director->getOpenGLView();
    Display* dpy = (Display*)glView->getX11Display();
    Window x11 = glView->getX11Window();
    int screen = DefaultScreen(dpy);
    Window root = RootWindow(dpy, screen);

    int x = 0;
    int y = 0;
    Window dummy;
    XTranslateCoordinates(dpy, x11, root, 0, 0, &x, &y, &dummy);

    inVibrate = true;
    sh->schedule(
        [=](float dt) mutable noexcept{
            if(--repeat <= 0) {
                XMoveWindow(dpy, x11, x, y);
                XFlush(dpy);
                inVibrate = false;
            }
            else {
                XMoveWindow(dpy, x11, x + (repeat & 1 ? 1 : -1), y);
                XFlush(dpy);
            }
        },
        director,
        0.02f,repeat - 1,0.0f,
        false,"WindowVibrate"
    );
}

double Device::GetBatteryPercent() noexcept {
    FILE* bpf = ::fopen("/sys/class/power_supply/BAT0/capacity", "r");
    if (!bpf) {
        return 0.0;
    }
    char content[10] = { 0 };
    ::memset(content, 0, sizeof(content));
    ::fread(content, sizeof(char), sizeof(content), bpf);
    ::fclose(bpf);

    const auto lvl = static_cast<double>(::atoi(content));
    return lvl / 100.0;
}

bool Device::IsBatteryCharge() noexcept {
    FILE* bcf = ::fopen("/sys/class/power_supply/BAT0/charge_now", "r");
    if (!bcf) {
        return false;
    }
    char content = '\0';
    ::fread(&content, sizeof(char), sizeof(content), bcf);
    ::fclose(bcf);

    return content == '1';
}

uint8_t Device::GetWifiLevel() noexcept {
    int fd, intrface, retn = 0;
    ifconf ifc = {};
    iwreq iwr[INET_ADDRSTRLEN];
    iw_statistics stats = {};
    uint8_t level = 0;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ::memset(&iwr, 0, sizeof(iwr));
        ::memset(&stats, 0, sizeof(stats));
        for (auto i = 0;i < INET_ADDRSTRLEN;i++) {
            iwr[i].u.data.pointer = (caddr_t)&stats; /* result value */
            iwr[i].u.data.length = sizeof(stats);
            iwr[i].u.data.flags = 1; /* clear updated flag */
        }

        ifc.ifc_len = sizeof(iwr);
        ifc.ifc_buf = (caddr_t)iwr;

        if (!ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
            intrface = ifc.ifc_len / sizeof(iwreq);

            while (intrface-- > 0) {
                if (!ioctl(fd, SIOCGIWSTATS, (char*)&iwr[intrface])) {
                    level = stats.qual.level;
                    break;
                }
            }
        }
        ::close(fd);
    }

    if (level <= 0) {
        return 0;
    }
    level = (level - 1) / 20 + 1;

    if (level > 5) {
        level = 5;
    }

    return level;
}

static bool IsWirelessConnected() noexcept {
    int fd, intrface, retn = 0;
    ifconf ifc = {};
    iwreq iwr[INET_ADDRSTRLEN];
    iw_statistics stats = {};
    bool connected = false;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ::memset(&iwr, 0, sizeof(iwr));
        ::memset(&stats, 0, sizeof(stats));
        for (auto i = 0;i < INET_ADDRSTRLEN;i++) {
            iwr[i].u.data.pointer = (caddr_t)&stats; /* result value */
            iwr[i].u.data.length = sizeof(stats);
            iwr[i].u.data.flags = 1; /* clear updated flag */
        }

        ifc.ifc_len = sizeof(iwr);
        ifc.ifc_buf = (caddr_t)iwr;

        if (!ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
            intrface = ifc.ifc_len / sizeof(iwreq);

            while (intrface-- > 0) {
                if (!ioctl(fd, SIOCGIWSTATS, (char*)&iwr[intrface])) {
                    if (stats.status) {
                        connected = true;
                        break;
                    }
                }
            }
        }
        ::close(fd);
    }

    return connected;
}

Device::NetworkType Device::GetNetwork() noexcept {
    bool wConnected = IsWirelessConnected();
    if (wConnected) {
        return NetworkType::Wifi;
    }
    std::string ip = GetIp();
    if (ip.empty() || ip == "127.0.0.1") {
        return NetworkType::None;
    }
    return NetworkType::Other;
}

Device::OrientationType Device::GetOrientation() {
    // 第一次的值，判断ConfigParser中的isLandscape作为依据。
    if (!firstGetOri) {
        firstGetOri = true;

        const cocos2d::FileUtils* const fu = cocos2d::FileUtils::getInstance();
        const std::string fileName = fu->fullPathForFilename("config.json");
        const std::string content = fu->getStringFromFile(fileName);
        Document docRootjson = Document();
        if (!docRootjson.Parse<ParseFlag::kParseNoFlags>(content.c_str()).HasParseError()) {
            if (docRootjson.HasMember("isLandscape") && docRootjson["isLandscape"].IsBool() && !docRootjson["isLandscape"].GetBool()) {
                curOriType = Device::OrientationType::Portrait;
            }
        }
    }
    return curOriType;
}

void Device::SetOrientation(Device::OrientationType ot) {
    if (ot == curOriType) {
        return;
    }
    if (ot != Device::OrientationType::Auto) {
        firstGetOri = true;
        isAutoOri = false;
        curOriType = ot;

        auto e = cocos2d::Director::getInstance()->getEventDispatcher();
        if (ot == Device::OrientationType::Landscape) {
            e->dispatchCustomEvent("DeviceToLandscape");
        }
        else if (ot == Device::OrientationType::Portrait) {
            e->dispatchCustomEvent("DeviceToPortrait");
        }
    }
    else {
        isAutoOri = true;
    }
}

bool Device::IsAutoOrientation() noexcept {
    return isAutoOri;
}

std::string Device::GetIp() {
    int fd, intrface, retn = 0;
    ifreq buf[INET_ADDRSTRLEN];
    ifconf ifc = {};
    static char ip[INET_ADDRSTRLEN] = { 0 };
    ::memset(ip, 0, sizeof(ip));

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ifc.ifc_len = sizeof(buf);
        ifc.ifc_buf = (caddr_t)buf;

        if (!ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
            intrface = ifc.ifc_len / sizeof(ifreq);
            while (intrface-- > 0) {
                if (!(ioctl(fd, SIOCGIFADDR, (char*)&buf[intrface]))) {

                    ::memcpy(
                        ip,
                        inet_ntoa(((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr),
                        sizeof(ip)
                    );
                    if (::strcmp(ip, "127.0.0.1") == 0) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        ::close(fd);
    }

    return ip;
}

std::string Device::GetId() {
    int fd, intrface, retn = 0;
    ifreq buf[INET_ADDRSTRLEN];
    ifconf ifc = {};
    static char mac[18] = { 0 };
    ::memset(mac, 0, sizeof(mac));

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ifc.ifc_len = sizeof(buf);
        ifc.ifc_buf = (caddr_t)buf;

        if (!ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
            intrface = ifc.ifc_len / sizeof(ifreq);

            while (intrface-- > 0) {
                if (!(ioctl(fd, SIOCGIFHWADDR, (char*)&buf[intrface]))) {
                    ::close(fd);

                    snprintf(mac, sizeof(mac), "%02x:%02x:%02x:%02x:%02x:%02x",
                        (unsigned char)buf[intrface].ifr_hwaddr.sa_data[0],
                        (unsigned char)buf[intrface].ifr_hwaddr.sa_data[1],
                        (unsigned char)buf[intrface].ifr_hwaddr.sa_data[2],
                        (unsigned char)buf[intrface].ifr_hwaddr.sa_data[3],
                        (unsigned char)buf[intrface].ifr_hwaddr.sa_data[4],
                        (unsigned char)buf[intrface].ifr_hwaddr.sa_data[5]);

                    return mac;
                }
            }
        }
        ::close(fd);
    }

    return "";
}

NS_CC_END
