#import "Cocos2dxHelper.h"
#import "platform/ios/CCLuaObjcBridge.h"
#import "base/CCDirector.h"
#import "base/CCScheduler.h"
#include <map>

using namespace cocos2d;

static Cocos2dxHelper* inst = nullptr;
static std::vector<int> VecLuaNotifyClickId = std::vector<int>();
static std::recursive_mutex vlncMutex;

@implementation Cocos2dxHelper {
    UNUserNotificationCenter* center;
    BOOL isBMKLocationAuth;
}

+(Cocos2dxHelper*)getInstance {
    if (inst == nullptr) {
        inst = [[Cocos2dxHelper alloc] init];
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        [[BMKLocationAuth sharedInstance] checkPermisionWithKey:@"PtfNlWH5PBBi5qkC2eLZPi3oMOkmWX7Q" authDelegate:inst];
#endif
    }
    return inst;
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
- (void)onCheckPermissionState:(BMKLocationAuthErrorCode)iError {
    isBMKLocationAuth = iError == BMKLocationAuthErrorSuccess;
}
#endif

// The method will be called on the delegate only if the application is in the foreground. If the method is not implemented or the handler is not called in a timely manner then the notification will not be presented. The application can choose to have the notification presented as a sound, badge, alert and/or in the notification list. This decision should be based on whether the information in the notification is otherwise visible to the user.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
    completionHandler(UNNotificationPresentationOptionSound | UNNotificationPresentationOptionAlert);
}

// The method will be called on the delegate when the user responded to the notification by opening the application, dismissing the notification or choosing a UNNotificationAction. The delegate must be set before the application returns from application:didFinishLaunchingWithOptions:.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler {
    NSDictionary* dict = response.notification.request.content.userInfo;
    NSString* idf = response.notification.request.identifier;
    NSString* cId = response.notification.request.content.categoryIdentifier;
    if (dict != nullptr
        && (idf != nullptr && [idf containsString:@"LuaNotify_"])
        && (cId != nullptr && [cId isEqualToString:@"LuaNotifyCategory"])) {
        NSNumber* num = [dict objectForKey:@"LuaNotifyClickCallback"];
        if (num != nullptr) {
            int clickCallback = [num intValue];
            if ([UNNotificationDefaultActionIdentifier isEqualToString:response.actionIdentifier]) {
                LuaObjcBridge::callLuaFunction(clickCallback);
            }
            LuaObjcBridge::releaseLuaFunction(clickCallback);
            
            std::lock_guard<std::recursive_mutex> lg(vlncMutex);
            for(auto it = VecLuaNotifyClickId.begin();it != VecLuaNotifyClickId.end();it++){
                if (clickCallback == *it) {
                    VecLuaNotifyClickId.erase(it);
                    break;
                }
            }
        }
    }
    completionHandler();
}

// The method will be called on the delegate when the application is launched in response to the user's request to view in-app notification settings. Add UNAuthorizationOptionProvidesAppNotificationSettings as an option in requestAuthorizationWithOptions:completionHandler: to add a button to inline notification settings view and the notification settings view in Settings. The notification will be nil when opened from Settings.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center openSettingsForNotification:(nullable UNNotification *)notification {

}

-(id)init {
    self = [super init];

    isBMKLocationAuth = NO;
    center = [UNUserNotificationCenter currentNotificationCenter];
    //监听回调事件
    center.delegate = self;
    // UNNotificationCategoryOptionCustomDismissAction表明可以触发通知的dismiss回调
    UNNotificationCategory *category = [UNNotificationCategory categoryWithIdentifier:@"LuaNotifyCategory" actions:@[] intentIdentifiers:@[] options:UNNotificationCategoryOptionCustomDismissAction];
    // 注册category到通知中心
    [center setNotificationCategories:[NSSet setWithObjects:category, nil]];
    return self;
}

+(void)CreateLuaNotifyWithTitle:(NSString*)title Conetent:(NSString*)content ClickCallback:(NSNumber*)clickCallback {
    UNMutableNotificationContent * unContent = [[UNMutableNotificationContent alloc]init];
    unContent.title = title;
    unContent.body = content;
    unContent.sound = [UNNotificationSound defaultSound];
    unContent.userInfo = [NSDictionary dictionaryWithObject:clickCallback forKey:@"LuaNotifyClickCallback"];
    unContent.categoryIdentifier = @"LuaNotifyCategory";

    NSString* idf = [NSString stringWithFormat:@"LuaNotify_%d",clickCallback == nil ? 0 : [clickCallback intValue]];
    UNNotificationRequest* request = [UNNotificationRequest requestWithIdentifier:idf content:unContent trigger:nil];

    //将建立的通知请求添加到通知中心
    [[Cocos2dxHelper getInstance]->center addNotificationRequest:request withCompletionHandler:^(NSError * _Nullable error) {
        if(!error) {
            const auto click = [clickCallback intValue];
            std::lock_guard<std::recursive_mutex> lg(vlncMutex);
            VecLuaNotifyClickId.emplace_back(click);
        }
    }];
}
+(void)Notify:(NSString*)title :(NSString*)content {
    [Cocos2dxHelper Notify:title :content :0];
}
+(void)Notify:(NSString*)title :(NSString*)content :(int)clickCallback {
    [[Cocos2dxHelper getInstance]->center getDeliveredNotificationsWithCompletionHandler:^(NSArray<UNNotification*>* notifications) {
        std::lock_guard<std::recursive_mutex> lg(vlncMutex);
        for(auto it = VecLuaNotifyClickId.begin();it != VecLuaNotifyClickId.end();) {
            int clickId = *it;
            bool found = false;
            for(UNNotification* unN in notifications) {
                NSDictionary* d = unN.request.content.userInfo;
                if (d != nullptr) {
                    NSNumber* clickIdNumber = [d objectForKey:@"LuaNotifyClickCallback"];
                    if (clickIdNumber != nullptr && clickId == [clickIdNumber intValue]) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                LuaObjcBridge::releaseLuaFunction(clickId);
                it = VecLuaNotifyClickId.erase(it);
                continue;
            }
            it++;
        }
        [[Cocos2dxHelper getInstance]->center getNotificationSettingsWithCompletionHandler:^(UNNotificationSettings * _Nonnull settings) {
            if (settings.authorizationStatus == UNAuthorizationStatusAuthorized
                && settings.notificationCenterSetting == UNNotificationSettingEnabled) {
                NSNumber* click = [NSNumber numberWithInt:clickCallback];
                [Cocos2dxHelper CreateLuaNotifyWithTitle:title Conetent:content ClickCallback:click];
            }
            else if (settings.authorizationStatus == UNAuthorizationStatusNotDetermined) {
                //iOS 10 使用以下方法注册，才能得到授权
                [[Cocos2dxHelper getInstance]->center requestAuthorizationWithOptions:(UNAuthorizationOptionAlert + UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
                    if (granted) {
                        NSNumber* click = [NSNumber numberWithInt:clickCallback];
                        [Cocos2dxHelper CreateLuaNotifyWithTitle:title Conetent:content ClickCallback:click];
                    }
                    else {
                        if (clickCallback) {
                            Director::getInstance()->getScheduler()->performFunctionInCocosThread([clickCallback](){
                                LuaObjcBridge::releaseLuaFunction(clickCallback);
                            });
                        }
                    }
                }];
            }
            else {
                if (clickCallback) {
                    Director::getInstance()->getScheduler()->performFunctionInCocosThread([clickCallback](){
                        LuaObjcBridge::releaseLuaFunction(clickCallback);
                    });
                }
            }
        }];
    }];
}
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
+(BOOL)RequestLocation:(int)luaCallback {
    Cocos2dxHelper* inst = [Cocos2dxHelper getInstance];
    if (!inst->isBMKLocationAuth){
        return NO;
    }
    BMKLocationManager  *locationManager = [[BMKLocationManager alloc] init];
    locationManager.delegate = inst;
    locationManager.activityType = CLActivityTypeOther;

    BOOL ret = [locationManager requestLocationWithReGeocode:YES withNetworkState:YES completionBlock:^(BMKLocation * _Nullable location, BMKLocationNetworkState state, NSError * _Nullable error) {
        auto locInfo = std::map<std::string,std::string>();
        if (location){
            auto rgc = location.rgcData;
            auto coor = location.location.coordinate;
            if(error) {
                locInfo["code"] = error.code;
            }
            locInfo["x"] = std::move(std::to_string(coor.longitude));
            locInfo["y"] = std::move(std::to_string(coor.latitude));
            if(rgc.province) {
                locInfo["province"] = [rgc.province UTF8String];
            }
            if(rgc.city) {
                locInfo["city"] = [rgc.city UTF8String];
            }
            if(rgc.district) {
                locInfo["district"] = [rgc.district UTF8String];
            }
            if(rgc.street) {
                locInfo["street"] = [rgc.street UTF8String];
            }
            if(rgc.streetNumber) {
                locInfo["num"] = [rgc.streetNumber UTF8String];
            }
        }
        LuaObjcBridge::callLuaFunction(luaCallback, locInfo);
        LuaObjcBridge::releaseLuaFunction(luaCallback);
    }];
    if (!ret) {
        LuaObjcBridge::releaseLuaFunction(luaCallback);
    }
    return ret;
}
#endif

@end
