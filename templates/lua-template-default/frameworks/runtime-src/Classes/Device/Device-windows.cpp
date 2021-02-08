#if WIN32
#include "cocos2d.h"
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "Device/Device.h"
#include <winbase.h>
#include <wlanapi.h>
#include <wininet.h>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <IPTypes.h>
#include <iphlpapi.h>

// Need to link with Wlanapi.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Iphlpapi.lib")

using namespace StarryX;
using namespace rapidjson;

StarryX::Device::OrientationType StarryX::Device::curOriType = StarryX::Device::OrientationType::Landscape;
bool StarryX::Device::isAutoOri = false;
bool StarryX::Device::firstGetOri = false;

double StarryX::Device::GetBatteryPercent() noexcept {
    _SYSTEM_POWER_STATUS sps = {};
    const auto ret = GetSystemPowerStatus(&sps);
    if (!ret) {
        return 0.;
    }
    const auto bp = sps.BatteryLifePercent;
    return BATTERY_PERCENTAGE_UNKNOWN == bp ? 0. : static_cast<double>(bp) / 100;
}

bool StarryX::Device::IsBatteryCharge() noexcept {
    _SYSTEM_POWER_STATUS sps = {};
    const auto ret = GetSystemPowerStatus(&sps);
    if (!ret) {
        return false;
    }
    const auto bf = sps.BatteryFlag;
    return BATTERY_FLAG_UNKNOWN == bf ? false : bf & BATTERY_FLAG_CHARGING;
}

uint8_t StarryX::Device::GetWifiLevel() noexcept {
    HANDLE hClient = nullptr;
    DWORD dwCurVersion = 0;
    if (ERROR_SUCCESS != WlanOpenHandle(2, 0, &dwCurVersion, &hClient)) {
        return 0;
    }

    PWLAN_INTERFACE_INFO_LIST pIfList = nullptr;
    if (ERROR_SUCCESS != WlanEnumInterfaces(hClient, NULL, &pIfList)) {
        WlanCloseHandle(hClient, nullptr);
        return 0;
    }

    PWLAN_INTERFACE_INFO pIfInfo = nullptr;
    //Loop through the List to find the connected Interface
    for (int i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
        PWLAN_INTERFACE_INFO tempIfInfo = (WLAN_INTERFACE_INFO*)&pIfList->InterfaceInfo[i];
        if (tempIfInfo->isState == wlan_interface_state_connected) {
            pIfInfo = tempIfInfo;
            break;
        }
    }

    PWLAN_AVAILABLE_NETWORK_LIST pBssList = nullptr;
    PWLAN_AVAILABLE_NETWORK pBssEntry = nullptr;
    if (pIfInfo && (ERROR_SUCCESS == WlanGetAvailableNetworkList(hClient,
        &pIfInfo->InterfaceGuid,
        0,
        nullptr,
        &pBssList))) {

        for (int j = 0; j < (int)pBssList->dwNumberOfItems; j++) {
            PWLAN_AVAILABLE_NETWORK tempBssEntry = (WLAN_AVAILABLE_NETWORK*)&pBssList->Network[j];
            if (tempBssEntry->dwFlags) {
                if (tempBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED) {
                    pBssEntry = tempBssEntry;
                    break;
                }
            }
        }
    }

    uint8_t wLevel = 0;
    if (pBssEntry) {
        if (0 == pBssEntry->wlanSignalQuality) {
            wLevel = 0;
        }
        else {
            wLevel = (pBssEntry->wlanSignalQuality - 1) / 20 + 1;
        }
    }

    if (pIfList) {
        WlanFreeMemory(pIfList);
        pIfList = nullptr;
    }
    if (pBssList) {
        WlanFreeMemory(pBssList);
        pBssList = nullptr;
    }
    WlanCloseHandle(hClient, nullptr);

    return wLevel;
}

StarryX::Device::NetworkType StarryX::Device::GetNetworkType() noexcept {
    DWORD flags = 0;
    const BOOL m_bOnline = InternetGetConnectedState(&flags, 0);
    if (!m_bOnline) {
        return NetworkType::None;
    }

    HANDLE hClient = nullptr;
    DWORD dwCurVersion = 0;
    if (ERROR_SUCCESS != WlanOpenHandle(2, nullptr, &dwCurVersion, &hClient)) {
        return NetworkType::Other;
    }

    PWLAN_INTERFACE_INFO_LIST pIfList = nullptr;
    if (ERROR_SUCCESS != WlanEnumInterfaces(hClient, nullptr, &pIfList)) {
        WlanCloseHandle(hClient, nullptr);
        return NetworkType::Other;
    }

    PWLAN_INTERFACE_INFO pIfInfo = nullptr;
    //Loop through the List to find the connected Interface
    for (int i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
        PWLAN_INTERFACE_INFO tempIfInfo = (WLAN_INTERFACE_INFO*)&pIfList->InterfaceInfo[i];
        if (tempIfInfo->isState == wlan_interface_state_connected) {
            pIfInfo = tempIfInfo;
            break;
        }
    }

    if (pIfList) {
        WlanFreeMemory(pIfList);
        pIfList = nullptr;
    }
    WlanCloseHandle(hClient, nullptr);

    return pIfInfo ? NetworkType::Wifi : NetworkType::Other;
}

StarryX::Device::OrientationType StarryX::Device::GetOrientation() {
    // 第一次的值，判断ConfigParser中的isLandscape作为依据。
    if (!firstGetOri) {
        firstGetOri = true;

        const cocos2d::FileUtils* const fu = cocos2d::FileUtils::getInstance();
        const std::string fileName = fu->fullPathForFilename("config.json");
        const std::string content = fu->getStringFromFile(fileName);
        Document docRootjson = Document();
        if (!docRootjson.Parse<ParseFlag::kParseNoFlags>(content.c_str()).HasParseError()) {
            if (docRootjson.HasMember("isLandscape") && docRootjson["isLandscape"].IsBool() && !docRootjson["isLandscape"].GetBool()) {
                curOriType = StarryX::Device::OrientationType::Portrait;
            }
        }
    }
    return curOriType;
}

void StarryX::Device::SetOrientation(StarryX::Device::OrientationType ot) {
    if (ot == curOriType) {
        return;
    }
    if (ot != StarryX::Device::OrientationType::Auto) {
        firstGetOri = true;
        isAutoOri = false;
        curOriType = ot;

        auto e = cocos2d::Director::getInstance()->getEventDispatcher();
        if (ot == StarryX::Device::OrientationType::Landscape) {
            e->dispatchCustomEvent("DeviceToLandscape");
        }
        else if (ot == StarryX::Device::OrientationType::Portrait) {
            e->dispatchCustomEvent("DeviceToPortrait");
        }
    }
    else {
        isAutoOri = true;
    }
}

bool StarryX::Device::IsAutoOrientation() noexcept {
    return isAutoOri;
}

std::string StarryX::Device::GetIp() {
    WSADATA wsaData = WSADATA();
    char ip[16] = {0};


    ::memset(ip, 0, sizeof(ip));
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
        addrinfo hints = addrinfo();
        addrinfo* res = nullptr;
        sockaddr_in* addr = nullptr;
        const char name[155] = { 0 };

        ::memset(&hints, 0, sizeof(addrinfo));
        hints.ai_family = AF_INET; /* Allow IPv4 */
        hints.ai_flags = AI_PASSIVE; /* For wildcard IP address */
        hints.ai_protocol = 0; /* Any protocol */
        hints.ai_socktype = SOCK_STREAM;

        const int ret = ::getaddrinfo(name, nullptr, &hints, &res);
        if (ret == 0 && res) {
            addr = reinterpret_cast<sockaddr_in*>(res->ai_addr);
            ::inet_ntop(AF_INET, &addr->sin_addr, ip, 16);
        }
        WSACleanup();
    }
    return ip;
}

std::string StarryX::Device::GetId() {
    std::string id = std::string();
    DWORD MACaddress = 0;
    IP_ADAPTER_INFO AdapterInfo[16] = { nullptr };       // Allocate information
    // for up to 16 NICs
    DWORD dwBufLen = sizeof(AdapterInfo);  // Save memory size of buffer

    const DWORD dwStatus = GetAdaptersInfo(      // Call GetAdapterInfo
        AdapterInfo,                 // [out] buffer to receive data
        &dwBufLen);                  // [in] size of receive data buffer
    if (dwStatus != NO_ERROR) {
        return id;
    };  // Verify return value is

    PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo; // Contains pointer to
    // current adapter info
    do {
        //if (MACaddress == 0)
        //    MACaddress = pAdapterInfo->Address[5] +
        //    pAdapterInfo->Address[4] * 256 +
        //    pAdapterInfo->Address[3] * 256 * 256 +
        //    pAdapterInfo->Address[2] * 256 * 256 * 256;
        const auto addr = pAdapterInfo->Address;

        char string[32] = {0};
        ::memset(string, 0, sizeof(string));
        sprintf_s(
            string,
            "%02X-%02X-%02X-%02X-%02X-%02X",
            addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]
        );
        id = string;

        break;// 不再获取后面的。
        pAdapterInfo = pAdapterInfo->Next;    // Progress through linked list
    } while (pAdapterInfo);                    // Terminate if last adapter

    return id;
}
#endif