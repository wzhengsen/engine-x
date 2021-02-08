#if CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/wireless.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "cocos2d.h"
#include "Device/Device.h"

using namespace StarryX;
using namespace rapidjson;

StarryX::Device::OrientationType StarryX::Device::curOriType = StarryX::Device::OrientationType::Landscape;
bool StarryX::Device::isAutoOri = false;
bool StarryX::Device::firstGetOri = false;

double StarryX::Device::GetBatteryPercent() noexcept {
    FILE* bpf = ::fopen("/sys/class/power_supply/BAT0/capacity","r");
    if(!bpf) {
        return 0.0;
    }
    char content[10] = {0};
    ::memset(content,0,sizeof(content));
    ::fread(content,sizeof(char),sizeof(content),bpf);
    ::fclose(bpf);

    const auto lvl = static_cast<double>(::atoi(content));
    return lvl / 100.0;
}

bool StarryX::Device::IsBatteryCharge() noexcept {
    FILE* bcf = ::fopen("/sys/class/power_supply/BAT0/charge_now","r");
    if(!bcf) {
        return false;
    }
    char content = '\0';
    ::fread(&content,sizeof(char),sizeof(content),bcf);
    ::fclose(bcf);

    return content == '1';
}

uint8_t StarryX::Device::GetWifiLevel() noexcept {
    int fd, intrface, retn = 0;
    ifconf ifc = {};
    iwreq iwr[INET_ADDRSTRLEN];
    iw_statistics stats = {};
    uint8_t level = 0;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ::memset(&iwr, 0, sizeof(iwr));
        ::memset(&stats, 0, sizeof(stats));
        for(auto i = 0;i < INET_ADDRSTRLEN;i++) {
            iwr[i].u.data.pointer = (caddr_t) &stats; /* result value */
            iwr[i].u.data.length = sizeof(stats);
            iwr[i].u.data.flags = 1; /* clear updated flag */
        }

        ifc.ifc_len = sizeof(iwr);
        ifc.ifc_buf = (caddr_t)iwr;

        if (!ioctl(fd, SIOCGIFCONF, (char *)&ifc)) {
            intrface = ifc.ifc_len / sizeof(iwreq);

            while (intrface-- > 0) {
                if (!ioctl(fd, SIOCGIWSTATS, (char *)&iwr[intrface])) {
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
        for(auto i = 0;i < INET_ADDRSTRLEN;i++) {
            iwr[i].u.data.pointer = (caddr_t) &stats; /* result value */
            iwr[i].u.data.length = sizeof(stats);
            iwr[i].u.data.flags = 1; /* clear updated flag */
        }

        ifc.ifc_len = sizeof(iwr);
        ifc.ifc_buf = (caddr_t)iwr;

        if (!ioctl(fd, SIOCGIFCONF, (char *)&ifc)) {
            intrface = ifc.ifc_len / sizeof(iwreq);

            while (intrface-- > 0) {
                if (!ioctl(fd, SIOCGIWSTATS, (char *)&iwr[intrface])) {
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

StarryX::Device::NetworkType StarryX::Device::GetNetworkType() noexcept {
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
    int fd, intrface, retn = 0;
    ifreq buf[INET_ADDRSTRLEN];
    ifconf ifc = {};
    static char ip[INET_ADDRSTRLEN] = {0};
    ::memset(ip,0,sizeof(ip));

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ifc.ifc_len = sizeof(buf);
        ifc.ifc_buf = (caddr_t)buf;

        if (!ioctl(fd, SIOCGIFCONF, (char *)&ifc)) {
            intrface = ifc.ifc_len / sizeof(ifreq);
            while (intrface-- > 0) {
                if (!(ioctl(fd, SIOCGIFADDR, (char *)&buf[intrface]))) {

                    ::memcpy(
                        ip,
                        inet_ntoa(((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr),
                        sizeof(ip)
                    );
                    if (::strcmp(ip,"127.0.0.1") == 0) {
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

std::string StarryX::Device::GetId() {
    int fd, intrface, retn = 0;
    ifreq buf[INET_ADDRSTRLEN];
    ifconf ifc = {};
    static char mac[18] = {0};
    ::memset(mac,0,sizeof(mac));

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ifc.ifc_len = sizeof(buf);
        ifc.ifc_buf = (caddr_t)buf;

        if (!ioctl(fd, SIOCGIFCONF, (char *)&ifc)) {
            intrface = ifc.ifc_len / sizeof(ifreq);

            while (intrface-- > 0) {
                if (!(ioctl(fd, SIOCGIFHWADDR, (char *)&buf[intrface]))) {
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
#endif