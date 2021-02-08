#include "cocos2d.h"
#import <UserNotifications/UserNotifications.h>
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import <UIKit/UIKit.h>
#import "BMKLocationKit/BMKLocationComponent.h"
@interface Cocos2dxHelper:NSObject<UNUserNotificationCenterDelegate,BMKLocationAuthDelegate,BMKLocationManagerDelegate> {

}
+(BOOL)RequestLocation:(int)luaCallback;
#else
@interface Cocos2dxHelper:NSObject<UNUserNotificationCenterDelegate> {

}
#endif
+(Cocos2dxHelper*)getInstance;
+(void)Notify:(NSString*)title :(NSString*)content :(int)luaCallback;
+(void)Notify:(NSString*)title :(NSString*)content;
@end
