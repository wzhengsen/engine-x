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
#import "CCApplication.h"

#import <UIKit/UIKit.h>

#import "math/CCGeometry.h"
#import "platform/ios/CCDirectorCaller-ios.h"
#import "base/ccUtils.h"

NS_CC_BEGIN

Application* Application::sm_pSharedApplication = nullptr;
std::vector<Application::DialogFuncsWrapper> Application::VecDlgWrapper = std::vector<Application::DialogFuncsWrapper>();

Application::Application()
{
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = 0;
}

int Application::run()
{
    if (applicationDidFinishLaunching())
    {
        [[CCDirectorCaller sharedDirectorCaller] startMainLoop];
    }
    return 0;
}

void Application::setAnimationInterval(float interval)
{
    [[CCDirectorCaller sharedDirectorCaller] setAnimationInterval: interval ];
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

const char * Application::getCurrentLanguageCode()
{
    static char code[3]={0};
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];

    // get the current language code.(such as English is "en", Chinese is "zh" and so on)
    NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
    NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];
    [languageCode getCString:code maxLength:3 encoding:NSASCIIStringEncoding];
    code[2]='\0';
    return code;
}

LanguageType Application::getCurrentLanguage()
{
    // get the current language and country config
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];

    // get the current language code.(such as English is "en", Chinese is "zh" and so on)
    NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
    NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];

    return utils::getLanguageTypeByISO2([languageCode UTF8String]);

}

Application::Platform Application::getTargetPlatform()
{
    if ([UIDevice.currentDevice userInterfaceIdiom] == UIUserInterfaceIdiomPad) // idiom for iOS <= 3.2, otherwise: [UIDevice userInterfaceIdiom] is faster.
    {
        return Platform::OS_IPAD;
    }
    else
    {
        return Platform::OS_IPHONE;
    }
}

std::string Application::getVersion() {
    NSString* version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    if (version) {
        return [version UTF8String];
    }
    return "";
}

int64_t Application::GetCompileVersion() {
    NSString* version = [[[NSBundle mainBundle]infoDictionary] objectForKey:@"CFBundleVersion"];
    if (version) {
        return[version intValue];
    }
    return 0;
}

bool Application::openURL(const std::string &url)
{
    NSString* msg = [NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding];
    NSURL* nsUrl = [NSURL URLWithString:msg];
    
    id application = [UIApplication sharedApplication];
    if ([application respondsToSelector:@selector(openURL:options:completionHandler:)] )
    {
        [application openURL:nsUrl options:@{} completionHandler:nil];
    }
    else
    {
        return [application openURL:nsUrl];
    }
}

void Application::applicationScreenSizeChanged(int newWidth, int newHeight) {

}

void Application::Dialog(const std::string &title, const std::string &content,
                         const std::function<void()>& okCallback,
                         const std::function<void()>& cancelCallback) {
    UIAlertController* alert = [UIAlertController
        alertControllerWithTitle:[NSString
            stringWithCString:title.c_str()
            encoding:NSUTF8StringEncoding
        ]
        message:[NSString
            stringWithCString:content.c_str()
            encoding:NSUTF8StringEncoding
        ]
        preferredStyle:UIAlertControllerStyleAlert
    ];

    UIAlertAction* okAction = [UIAlertAction
        actionWithTitle:@"确定"
        style:UIAlertActionStyleDefault
        handler:^(UIAlertAction * action) {
        for(auto it = VecDlgWrapper.begin();it != VecDlgWrapper.end();it++){
                if ((*it).ok.action == action && (*it).ok.callback) {
                    (*it).ok.callback();
                    VecDlgWrapper.erase(it);
                    break;
                }
            }
        }
    ];
    [alert addAction:okAction];

    UIAlertAction* cancelAction = nullptr;
    if(cancelCallback) {
        cancelAction = [UIAlertAction
            actionWithTitle:@"取消"
            style:UIAlertActionStyleDefault
            handler:^(UIAlertAction * action) {
            for(auto it = VecDlgWrapper.begin();it != VecDlgWrapper.end();it++){
                if ((*it).cancel.action == action && (*it).cancel.callback) {
                    (*it).cancel.callback();
                    VecDlgWrapper.erase(it);
                    break;
                }
            }
        }
        ];
        [alert addAction:cancelAction];
    }

    VecDlgWrapper.emplace_back(okAction,okCallback,cancelAction,cancelCallback);

    auto rootViewController = [UIApplication sharedApplication].windows[0].rootViewController;
    [rootViewController presentViewController:alert animated:YES completion:nil];
}

void Application::Notify(const std::string &title, const std::string &content,
                         const std::function<void()>& clickCallback,
                         const std::function<void()>& closeCallback) {
    // Omit the c++ implementation and use luaj
}

NS_CC_END
