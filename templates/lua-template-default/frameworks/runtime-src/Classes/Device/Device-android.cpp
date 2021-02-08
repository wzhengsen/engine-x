#if ANDROID || __ANDROID__
#include "cocos2d.h"
#include "Device/Device.h"
#include "platform/android/jni/JniHelper.h"

static const std::string helperClassName = "org.cocos2dx.lib.Cocos2dxHelper";
using namespace StarryX;

double StarryX::Device::GetBatteryPercent() noexcept {
    return cocos2d::JniHelper::callStaticDoubleMethod(helperClassName, "GetBatteryPercent");
}

bool StarryX::Device::IsBatteryCharge() noexcept {
    return cocos2d::JniHelper::callStaticBooleanMethod(helperClassName, "IsBatteryCharge");
}

uint8_t StarryX::Device::GetWifiLevel() noexcept {
    return static_cast<uint8_t>(cocos2d::JniHelper::callStaticIntMethod(helperClassName, "GetWifiLevel"));
}

StarryX::Device::NetworkType StarryX::Device::GetNetworkType() noexcept {
    int ret = cocos2d::JniHelper::callStaticIntMethod(helperClassName, "GetNetworkType");
    return static_cast<NetworkType>(ret);
}

StarryX::Device::OrientationType StarryX::Device::GetOrientation() {
    int ret = cocos2d::JniHelper::callStaticIntMethod(helperClassName, "GetOrientation");
    return static_cast<OrientationType>(ret);
}

void StarryX::Device::SetOrientation(StarryX::Device::OrientationType ot) {
    cocos2d::JniHelper::callStaticVoidMethod(helperClassName, "SetOrientation", static_cast<int>(ot));
}

bool StarryX::Device::IsAutoOrientation() noexcept {
    return cocos2d::JniHelper::callStaticBooleanMethod(helperClassName, "IsAutoOrientation");
}

std::string StarryX::Device::GetIp() {
    return cocos2d::JniHelper::callStaticStringMethod(helperClassName, "GetIp");
}

std::string StarryX::Device::GetId() {
    return cocos2d::JniHelper::callStaticStringMethod(helperClassName, "GetId");
}
#endif