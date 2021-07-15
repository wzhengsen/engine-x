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

#include "platform/CCPlatformConfig.h"
#include "platform/CCDevice.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#include <Foundation/Foundation.h>
#include <Cocoa/Cocoa.h>
#include <string>

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS ||\
CC_TARGET_PLATFORM == CC_PLATFORM_MAC
#import <ifaddrs.h>
#import <arpa/inet.h>
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <UIKit/UIKit.h>

#else
#import <IOKit/ps/IOPowerSources.h>
#import <IOKit/ps/IOPSKeys.h>
#import <CoreWLAN/CoreWLAN.h>
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
using namespace rapidjson;
#endif

#include "base/ccTypes.h"
#include "platform/apple/CCDevice-apple.h"

namespace FontUtils {
    NSMutableParagraphStyle* _calculateParagraphStyle(bool enableWrap, int overflow)
    {
        NSMutableParagraphStyle* paragraphStyle = [[[NSMutableParagraphStyle alloc] init] autorelease];
        paragraphStyle.lineBreakMode = NSLineBreakByWordWrapping;
        return paragraphStyle;
    }
    
    NSTextAlignment _calculateTextAlignment(cocos2d::Device::TextAlign align)
    {
        unsigned uHoriFlag = (int)align & 0x0f;
        NSTextAlignment nsAlign = (2 == uHoriFlag) ? NSTextAlignmentRight
        : (3 == uHoriFlag) ? NSTextAlignmentCenter
        : NSTextAlignmentLeft;
        
        return nsAlign;
    }
    

    
    CGFloat _calculateTextDrawStartWidth(cocos2d::Device::TextAlign align, CGSize realDimensions, CGSize dimensions)
    {
        CGFloat xPadding = 0;
        unsigned uHoriFlag = (int)align & 0x0f;
        switch (uHoriFlag) {
                //center
            case 3: xPadding = (dimensions.width - realDimensions.width) / 2.0f; break;
                //right
            case 2: xPadding = dimensions.width - realDimensions.width; break;
            default: break;
        }
        return xPadding;
    }

}


#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
int Device::InterfaceOrientationMask = UIInterfaceOrientationMaskLandscape;

double Device::GetBatteryPercent() noexcept {
    [UIDevice currentDevice] .batteryMonitoringEnabled = YES;
    double bl = [[UIDevice currentDevice]batteryLevel];
    if (bl < 0.0) {
        bl = 0.0;
    }
    return bl;
}

bool Device::IsBatteryCharge() noexcept {
    return[UIDevice currentDevice].batteryState == UIDeviceBatteryStateCharging;
}

uint8_t Device::GetWifiLevel() noexcept {
    uint8_t signalStrength = 0;
    if (@available(iOS 13.0, *)) {
        UIStatusBarManager* statusBarManager = [UIApplication sharedApplication].keyWindow.windowScene.statusBarManager;

        id statusBar = nil;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundeclared-selector"
        if ([statusBarManager respondsToSelector : @selector(createLocalStatusBar)]) {
            UIView* localStatusBar = [statusBarManager performSelector : @selector(createLocalStatusBar)];
            if ([localStatusBar respondsToSelector : @selector(statusBar)]) {
                statusBar = [localStatusBar performSelector : @selector(statusBar)];
            }
        }
#pragma clang diagnostic pop
        if (statusBar) {
            id currentData = [[statusBar valueForKeyPath : @"_statusBar"]valueForKeyPath:@"currentData"];
            id _wifiEntry = [currentData valueForKeyPath : @"wifiEntry"];
            //id _cellularEntry = [currentData valueForKeyPath:@"cellularEntry"];
            if (_wifiEntry && [[_wifiEntry valueForKeyPath : @"isEnabled"]boolValue]) {
                // If wifiEntry is enabled, is WiFi.
                if ([_wifiEntry isKindOfClass : NSClassFromString(@"_UIStatusBarDataIntegerEntry")]) {
                    // 层级：_UIStatusBarDataNetworkEntry、_UIStatusBarDataIntegerEntry、_UIStatusBarDataEntry
                    signalStrength = [[_wifiEntry valueForKey : @"displayValue"]unsignedCharValue];
                }
            }
        }
        if (signalStrength == 2) {
            signalStrength = 3;
        }
        else if (signalStrength == 3) {
            signalStrength = 5;
        }
        else if (signalStrength > 5) {
            signalStrength = 5;
        }
    }
    return signalStrength;
}

Device::NetworkType Device::GetNetwork() noexcept {
    Device::NetworkType nt = Device::NetworkType::None;
    UIApplication* app = [UIApplication sharedApplication];
    id statusBar = nil;
    if (@available(iOS 13.0, *)) {
        UIStatusBarManager* statusBarManager = [UIApplication sharedApplication].keyWindow.windowScene.statusBarManager;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundeclared-selector"
        if ([statusBarManager respondsToSelector : @selector(createLocalStatusBar)]) {
            UIView* localStatusBar = [statusBarManager performSelector : @selector(createLocalStatusBar)];
            if ([localStatusBar respondsToSelector : @selector(statusBar)]) {
                statusBar = [localStatusBar performSelector : @selector(statusBar)];
            }
        }
#pragma clang diagnostic pop

        if (statusBar) {
            // UIStatusBarDataCellularEntry
            id currentData = [[statusBar valueForKeyPath : @"_statusBar"]valueForKeyPath:@"currentData"];
            id _wifiEntry = [currentData valueForKeyPath : @"wifiEntry"];
            id _cellularEntry = [currentData valueForKeyPath : @"cellularEntry"];
            if (_wifiEntry && [[_wifiEntry valueForKeyPath : @"isEnabled"]boolValue]) {
                // If wifiEntry is enabled, is WiFi.
                nt = NetworkType::Wifi;
            }
            else if (_cellularEntry && [[_cellularEntry valueForKeyPath : @"isEnabled"]boolValue]) {
                nt = NetworkType::Mobile;
            }
        }
    }
    return nt;
}

Device::OrientationType Device::GetOrientation() {
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;

    if (orientation == UIInterfaceOrientationLandscapeLeft || orientation == UIInterfaceOrientationLandscapeRight) {
        return Device::OrientationType::Landscape;
    }
    return Device::OrientationType::Portrait;
}

void Device::SetOrientation(Device::OrientationType ot) {
    if (ot == OrientationType::Auto && IsAutoOrientation()) {
        return;
    }
    else if (ot == GetOrientation()) {
        return;
    }
    if (ot == OrientationType::Landscape) {
        [[UIDevice currentDevice]setValue:@(UIInterfaceOrientationUnknown)forKey : @"orientation"];
        InterfaceOrientationMask = UIInterfaceOrientationMaskLandscape;
        [[UIDevice currentDevice]setValue:@(UIInterfaceOrientationLandscapeLeft)forKey : @"orientation"];
    }
    else if (ot == OrientationType::Portrait) {
        [[UIDevice currentDevice]setValue:@(UIInterfaceOrientationUnknown)forKey : @"orientation"];
        InterfaceOrientationMask = UIInterfaceOrientationMaskPortrait;
        [[UIDevice currentDevice]setValue:@(UIInterfaceOrientationPortrait)forKey : @"orientation"];
    }
    else {
        InterfaceOrientationMask = UIInterfaceOrientationMaskAllButUpsideDown;
    }
    [UIViewController attemptRotationToDeviceOrientation] ;
}

bool Device::IsAutoOrientation() noexcept {
    return InterfaceOrientationMask == UIInterfaceOrientationMaskAllButUpsideDown || InterfaceOrientationMask == UIInterfaceOrientationMaskAll;
}
#else
double Device::GetBatteryPercent() noexcept {
    double ret = 0.;
    CFTypeRef cft = IOPSCopyPowerSourcesInfo();
    if (!cft) {
        return ret;
    }
    CFArrayRef cftArr = IOPSCopyPowerSourcesList(cft);
    if (!cftArr) {
        CFRelease(cft);
        return ret;
    }
    NSArray* array = (__bridge NSArray*)cftArr;
    for (id v : array) {
        CFTypeRef ps = (CFTypeRef)v;
        CFDictionaryRef info = IOPSGetPowerSourceDescription(cft, ps);
        NSDictionary* dictInfo = (__bridge NSDictionary*)info;
        NSNumber* lvl = [dictInfo objectForKey : @kIOPSCurrentCapacityKey];
        NSNumber* maxLvl = [dictInfo objectForKey : @kIOPSMaxCapacityKey];
        signed int iLvl = [lvl unsignedIntegerValue];
        signed int iMaxLvl = [maxLvl unsignedIntegerValue];
        ret = (double)iLvl / (double)iMaxLvl;
        dictInfo = nil;
        break;
    }
    CFRelease(cftArr);
    CFRelease(cft);
    cftArr = nil;

    return ret;
}

bool Device::IsBatteryCharge() noexcept {
    double ret = false;
    CFTypeRef cft = IOPSCopyPowerSourcesInfo();
    if (!cft) {
        return ret;
    }
    CFArrayRef cftArr = IOPSCopyPowerSourcesList(cft);
    if (!cftArr) {
        CFRelease(cft);
        return ret;
    }
    NSArray* array = (__bridge NSArray*)cftArr;
    for (id v : array) {
        CFTypeRef ps = (CFTypeRef)v;
        CFDictionaryRef info = IOPSGetPowerSourceDescription(cft, ps);
        NSDictionary* dictInfo = (__bridge NSDictionary*)info;
        NSNumber* charging = [dictInfo objectForKey : @kIOPSIsChargingKey];
        dictInfo = nil;
        break;
    }
    CFRelease(cftArr);
    CFRelease(cft);
    cftArr = nil;

    return ret;
}

uint8_t Device::GetWifiLevel() noexcept {
    CWInterface* wifi = [[CWWiFiClient sharedWiFiClient]interface];
    if (!wifi || !wifi.powerOn || !wifi.ssid) {
        return 0;
    }
    uint8_t lvl = 0;
    auto rssi = 100 + wifi.rssiValue;;
    if (rssi > 0) {
        lvl = (rssi - 1) / 20 + 1;
        if (lvl > 5) {
            lvl = 5;
        }
    }
    return lvl;
}

Device::NetworkType Device::GetNetwork() noexcept {
    CWInterface* wifi = [[CWWiFiClient sharedWiFiClient]interface];
    std::string addr = "";
    if (!wifi || !wifi.powerOn || !wifi.ssid) {
        addr = GetIp();
        if (addr.empty()) {
            return NetworkType::None;
        }
        return NetworkType::Other;
    }
    return NetworkType::Wifi;
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
#endif
std::string Device::GetIp() {
    std::string address = "";
    struct ifaddrs* interfaces = NULL;
    struct ifaddrs* temp_addr = NULL;
    int success = 0;

    success = getifaddrs(&interfaces);
    if (success == 0) { // 0 表示获取成功

        temp_addr = interfaces;
        while (temp_addr != NULL) {
            if (temp_addr->ifa_addr->sa_family == AF_INET) {
                // Check if interface is en0 which is the wifi connection
                const std::string ifa_name = temp_addr->ifa_name;
                if (ifa_name.find("en") == 0) {
                    // Get NSString from C String
                    address = inet_ntoa(((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr);
                    if (!address.empty()) {
                        break;
                    }
                }
            }

            temp_addr = temp_addr->ifa_next;
        }
    }

    freeifaddrs(interfaces);
    return address;
}


static NSMutableDictionary* GetKeychainQuery(NSString* service) {
    return[NSMutableDictionary dictionaryWithObjectsAndKeys :
    (id)kSecClassGenericPassword, (id)kSecClass,
        service, (id)kSecAttrService,
        service, (id)kSecAttrAccount,
        (id)kSecAttrAccessibleAfterFirstUnlock, (id)kSecAttrAccessible,
        nil];
}

static void SaveKeyData(NSString* service, id data) {
    //Get search dictionary
    NSMutableDictionary* keychainQuery = GetKeychainQuery(service);

    //Delete old item before add new item
    SecItemDelete((CFDictionaryRef)keychainQuery);

    //Add new object to searchdictionary(Attention:the data format)
    [keychainQuery setObject : [NSKeyedArchiver archivedDataWithRootObject : data] forKey : (id)kSecValueData] ;

    //Add item to keychain with the searchdictionary
    SecItemAdd((CFDictionaryRef)keychainQuery, NULL);
}

static id LoadKeyData(NSString* service) {
    id ret = nil;

    NSMutableDictionary* keychainQuery = GetKeychainQuery(service);
    //Configure the search setting

    //Since in our simple case we areexpecting only a single attribute to be returned (the password) wecan set the attribute kSecReturnData to kCFBooleanTrue
    [keychainQuery setObject : (id)kCFBooleanTrue forKey : (id)kSecReturnData];
    [keychainQuery setObject : (id)kSecMatchLimitOne forKey : (id)kSecMatchLimit] ;

    CFDataRef keyData = NULL;
    if (SecItemCopyMatching((CFDictionaryRef)keychainQuery, (CFTypeRef*)&keyData) == noErr) {
        @try {
            ret = [NSKeyedUnarchiver unarchiveObjectWithData : (__bridge NSData*)keyData];
        }@catch (NSException* e) {
            NSLog(@"Unarchive of %@ failed: %@", service, e);
        }@finally {
        }
    }

    if (keyData) {
        CFRelease(keyData);
    }
    return ret;
}

static void DeleteKeyData(NSString* service) {
    NSMutableDictionary* keychainQuery = GetKeychainQuery(service);
    SecItemDelete((CFDictionaryRef)keychainQuery);
}

std::string Device::GetId() {
    static std::string dId = std::string();
    if (dId.empty()) {
        NSString* ID = [NSString stringWithFormat : @"%@.%@", [[NSBundle mainBundle]bundleIdentifier], @"UniqueID"];
        NSString* strUUID = (NSString*)LoadKeyData(ID);

        //首次执行该方法时，uuid为空
        if (!strUUID || [strUUID isEqualToString : @""]) {
            //生成一个uuid的方法
            CFUUIDRef uuidRef = CFUUIDCreate(kCFAllocatorDefault);
            strUUID = (NSString*)CFBridgingRelease(CFUUIDCreateString(kCFAllocatorDefault, uuidRef));
            //将该uuid保存到keychain
            SaveKeyData(ID, strUUID);
        }
        dId = [strUUID UTF8String];
    }

    return dId;
}
#endif
