#pragma once
namespace StarryX {
    class Device final {
    public:
        /*
            Desc:       得到电量百分比。
            Return:     返回当前电量百分比。
         */
        static double GetBatteryPercent() noexcept;

        /*
            Desc:       当前是否正在充电。
            Return:     返回当前是否正在充电。
        */
        static bool IsBatteryCharge() noexcept;


        // 网络连接类型。
        enum class NetworkType {
            None,
            Wifi,
            Mobile,
            Other
        };

        /*
            Desc:       获取wifi信号强度。
            Return:     返回信号强度，0-5。
                        1为最弱，5为最强，0为没有wifi信号(可能是其他连接)。
        */
        static uint8_t GetWifiLevel() noexcept;

        /*
            Desc:       获取网络连接类型。
            Return:     返回当前网络连接类型。
                        在没有连接时，将返回NetworkType::None；
                        当windows连接有线网络时，可能返回Network::Other。
        */
        static NetworkType GetNetworkType() noexcept;

        // 当前设备方向类型。
        enum class OrientationType {
            // 横屏。
            Landscape,
            // 竖屏。
            Portrait,
            // 自动类型，跟随系统，在windows上不一定可用。
            Auto
        };

        /*
            Desc:设置当前设备的方向。
                设定方向后，屏幕会立刻旋转，并自动使用
                config.DesignResolution的两个值来设置设计分辨率。
                若参数是Landscape或Portrait，方向将被锁定，除非再次使用
                该函数改变方向。
        */
        static void SetOrientation(OrientationType ot);

        /*
            Desc:获取当前设备的方向。
                只会返回Landscape或Portrait，不会返回Auto。
                若需要获取当前是否是自动旋转方向，使用IsAutoOrientation.
        */
        static OrientationType GetOrientation();

        /*
            Desc:获取当前设备的方向是否是自动旋转的。
        */
        static bool IsAutoOrientation() noexcept;

        /*
            Desc:   获取IP。
        */
        static std::string GetIp();

        /*
            Desc:   获取唯一识别ID。
        */
        static std::string GetId();

    private:
        static OrientationType curOriType;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||\
    CC_TARGET_PLATFORM == CC_PLATFORM_LINUX ||\
    CC_TARGET_PLATFORM == CC_PLATFORM_MAC
        static bool isAutoOri;
        static bool firstGetOri;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    public:
        static int InterfaceOrientationMask;
#endif
    };
}
