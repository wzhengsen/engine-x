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

#ifndef __CCDEVICE_H__
#define __CCDEVICE_H__

#include "platform/CCPlatformMacros.h"
#include "base/ccMacros.h"
#include "base/CCData.h"

NS_CC_BEGIN

struct FontDefinition;

/**
 * @addtogroup platform
 * @{
 */

/**
 * @class Device
 * @brief 
 */
class CC_DLL Device
{
public:
    /** Defines the alignment of text. */
    enum class TextAlign
    {
        CENTER        = 0x33, /** Horizontal center and vertical center. */
        TOP           = 0x13, /** Horizontal center and vertical top. */
        TOP_RIGHT     = 0x12, /** Horizontal right and vertical top. */
        RIGHT         = 0x32, /** Horizontal right and vertical center. */
        BOTTOM_RIGHT  = 0x22, /** Horizontal right and vertical bottom. */
        BOTTOM        = 0x23, /** Horizontal center and vertical bottom. */
        BOTTOM_LEFT   = 0x21, /** Horizontal left and vertical bottom. */
        LEFT          = 0x31, /** Horizontal left and vertical center. */
        TOP_LEFT      = 0x11, /** Horizontal left and vertical top. */
    };

    /**
     *  Gets the DPI of device
     *  @return The DPI of device.
     */
    static int getDPI();
    
    /**
     * To enable or disable accelerometer.
     */
    static void setAccelerometerEnabled(bool isEnabled);

    /**
     *  Sets the interval of accelerometer.
     */
    static void setAccelerometerInterval(float interval);

    /**
     * Controls whether the screen should remain on.
     * 
     * @param keepScreenOn One flag indicating that the screen should remain on.
     */
    static void setKeepScreenOn(bool keepScreenOn);

    /**
     * Vibrate for the specified amount of time.
     * If vibrate is not supported, then invoking this method has no effect.
     * Some platforms limit to a maximum duration of 5 seconds.
     * Duration is ignored on iOS due to API limitations.
     * @param duration The duration in millseconds.
     */
    static void vibrate(uint32_t duration);

    /**
     * Gets texture data for text.
     */
    static Data getTextureDataForText(const char * text, const FontDefinition& textDefinition, TextAlign align, int &width, int &height, bool& hasPremultipliedAlpha);


    /**
    * @return 0-1
    */
    static double GetBatteryPercent() noexcept;
    static bool IsBatteryCharge() noexcept;

    enum class NetworkType {
        None,
        Wifi,
        Mobile,
        Other
    };
    /**
    * @return   NetworkType::None will be returned if there is no connection.
    */
    static NetworkType GetNetwork() noexcept;

    /**
    * @return   0-5.
    *           1 is the weakest,
    *           5 is the strongest,
    *           and 0 is no wifi signal (possibly other connections).
    */
    static uint8_t GetWifiLevel() noexcept;

    enum class OrientationType {
        Landscape,
        Portrait,
        // Automatic type, following the system, are not always available on PC.
        Auto
    };

    /**
    * @brief    Set the orientation of the current device.
    * @note     After setting the orientation,the screen will immediately rotate
    *           and lock to the current orientation unless the function is used again to change the orientation.
    */
    static void SetOrientation(OrientationType ot);

    /**
    * @return   Only OrientationType::Landscape or OrientationType::Portrait will be returned,
    *           not OrientationType::Auto.
    *           If you need to get whether the current orientation is automatic, use IsAutoOrientation.
    */
    static OrientationType GetOrientation();

    static bool IsAutoOrientation() noexcept;

    /**
    * @return The empty string will be returned on failure.
    */
    static std::string GetIp();

    static std::string GetId();

private:
    CC_DISALLOW_IMPLICIT_CONSTRUCTORS(Device);

private:
    inline static OrientationType curOriType = OrientationType::Landscape;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||\
    CC_TARGET_PLATFORM == CC_PLATFORM_LINUX ||\
    CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    inline static bool isAutoOri = false;
    inline static bool firstGetOri = false;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
public:
    inline static int InterfaceOrientationMask = UIInterfaceOrientationMaskLandscape;
#endif
};

// end group
/// @}

NS_CC_END

#endif /* __CCDEVICE_H__ */
