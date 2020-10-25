/****************************************************************************
 Copyright (c) 2014-2016 Chukong Technologies Inc.
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

#include "ui/UIVideoPlayer/UIVideoPlayer.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) ||\
(CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

using namespace cocos2d::ui;
//-------------------------------------------------------------------------------------
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "platform/ios/CCEAGLView-ios.h"
#import <AVKit/AVPlayerViewController.h>
#else
#import <AppKit/AppKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVPlayerLayer.h>
#endif
#import <CoreMedia/CMTime.h>
#include "base/CCDirector.h"
#include "platform/CCFileUtils.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
@class UIVideoViewWrapperApple;
@interface PlayerView : NSView
-(void)mouseDown:(NSEvent *)event;
@property (assign, nonatomic) UIVideoViewWrapperApple * wrapper;
@end
@interface PlayerViewController : AVPlayerLayer
@property (assign, nonatomic) PlayerView * view;
@end
@implementation PlayerViewController
@end
#endif

@interface UIVideoViewWrapperApple : NSObject

typedef NS_ENUM(NSInteger, PlayerbackState) {
    PlayerbackStateUnknown = 0,
    PlayerbackStatePaused,
    PlayerbackStopped,
    PlayerbackStatePlaying,
    PlayerbackStateCompleted
};
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
@property (assign, nonatomic) AVPlayerViewController * playerController;
#else
@property (assign, nonatomic) PlayerViewController* playerController;
@property (assign, nonatomic) PlayerbackState state;
@property (assign, nonatomic) BOOL userInteractionEnabled;
#endif

- (void) setFrame:(int) left :(int) top :(int) width :(int) height;
- (void) setURL:(int) videoSource :(std::string&) videoUrl;
- (void) play;
- (void) pause;
- (void) resume;
- (void) stop;
- (void) seekTo:(float) sec;
- (void) setVisible:(BOOL) visible;
- (void) setKeepRatioEnabled:(BOOL) enabled;
- (void) showPlaybackControls:(BOOL) value;
- (void) setRepeatEnabled:(BOOL)enabled;
- (void) setUserInteractionEnabled:(BOOL)userInteractionEnabled;


-(id) init:(void*) videoPlayer;
-(void) videoFinished:(NSNotification*) notification;

@end

@implementation UIVideoViewWrapperApple
{
    int _left;
    int _top;
    int _width;
    int _height;
    BOOL _keepRatioEnabled;
    BOOL _repeatEnabled;
    BOOL _showPlaybackControls;
    BOOL _userInteractionEnabled;
    PlayerbackState _state;
    VideoPlayer* _videoPlayer;
}

-(id)init:(void*)videoPlayer
{
    if (self = [super init]) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        self.playerController = [AVPlayerViewController new];
#else
        self.playerController = [PlayerViewController new];
        self.playerController.view = [PlayerView new];
        self.playerController.view.layer = self.playerController;
        self.playerController.view.wrapper = self;
#endif

        [self setRepeatEnabled:FALSE];
        [self showPlaybackControls : FALSE] ;
        [self setUserInteractionEnabled:TRUE];
        [self setKeepRatioEnabled:FALSE];

        _videoPlayer = (VideoPlayer*)videoPlayer;
        _state = PlayerbackStateUnknown;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTapped:)];
        tap.numberOfTapsRequired = 1;
        [self.playerController.view addGestureRecognizer:tap];
#endif
    }

    return self;
}
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
-(void) viewTapped:(UITapGestureRecognizer *)_ {
    if (_userInteractionEnabled && self.playerController.player) {
        if (_state == PlayerbackStatePaused) {
            [self resume];
        }
        else if (_state == PlayerbackStatePlaying) {
            [self pause];
        }
    }
}
#endif

-(void) dealloc
{
    _videoPlayer = nullptr;
    [self clean];
    [self.playerController release];
    [super dealloc];
}

-(void) clean
{
    [self stop];
    [self removePlayerEventListener];
    [self.playerController.view removeFromSuperview];
}

-(void) setFrame:(int)left :(int)top :(int)width :(int)height
{
    _left = left;
    _width = width;
    _top = top;
    _height = height;
    [self.playerController.view setFrame:CGRectMake(left, top, width, height)];
}

-(void) showPlaybackControls:(BOOL)value
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    _showPlaybackControls = value;
    self.playerController.showsPlaybackControls = value;
#endif
}

-(void) setRepeatEnabled:(BOOL)enabled
{
    _repeatEnabled = enabled;
    if (self.playerController.player) {
        if (_repeatEnabled)
            self.playerController.player.actionAtItemEnd = AVPlayerActionAtItemEndNone;
        else
            self.playerController.player.actionAtItemEnd = AVPlayerActionAtItemEndPause;
    }
}

-(void) setUserInteractionEnabled:(BOOL)userInteractionEnabled
{
    _userInteractionEnabled = userInteractionEnabled;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    self.playerController.view.userInteractionEnabled = _userInteractionEnabled;
#endif
}

-(void) setURL:(int)videoSource :(std::string &)videoUrl
{
    [self clean];

    if (videoSource == 1)
        self.playerController.player = [[[AVPlayer alloc] initWithURL:[NSURL URLWithString:@(videoUrl.c_str())]] autorelease];
    else
        self.playerController.player = [[[AVPlayer alloc] initWithURL:[NSURL fileURLWithPath:@(videoUrl.c_str())]] autorelease];

    [self setRepeatEnabled:_repeatEnabled];
    [self setKeepRatioEnabled:_keepRatioEnabled];
    [self setUserInteractionEnabled:_userInteractionEnabled];
    [self showPlaybackControls:_showPlaybackControls];

    auto view = cocos2d::Director::getInstance()->getOpenGLView();
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    auto eaglview = (CCEAGLView *) view->getEAGLView();
    [eaglview addSubview:self.playerController.view];
#else
    auto cocoaWindow = (NSWindow *) view->getCocoaWindow();
    [cocoaWindow.contentView addSubview:self.playerController.view];
#endif
    [self registerPlayerEventListener];
}

-(void) videoFinished:(NSNotification *)notification
{
    if(_videoPlayer != nullptr) {
        _videoPlayer->OnPlayEvent((int)VideoPlayer::EventType::COMPLETED);
        _state = PlayerbackStateCompleted;

        if (_repeatEnabled) {
            [self seekTo:0];
            [self play];
        }
    }
}

-(void) videoError:(NSNotification *)notification
{
    if(_videoPlayer != nullptr) {
        _videoPlayer->OnPlayEvent((int)VideoPlayer::EventType::V_ERROR);
        _state = PlayerbackStateUnknown;
    }
}

-(void) seekTo:(float)sec
{
    if (self.playerController.player)
        [self.playerController.player seekToTime:CMTimeMake(sec, 1)];
}

-(void) setVisible:(BOOL)visible
{
    [self.playerController.view setHidden:!visible];
}

-(void) setKeepRatioEnabled:(BOOL)enabled
{
    _keepRatioEnabled = enabled;
    if (_keepRatioEnabled)
        self.playerController.videoGravity = AVLayerVideoGravityResizeAspect;
    else
        self.playerController.videoGravity = AVLayerVideoGravityResizeAspectFill;
}

-(void) play
{
    if (self.playerController.player && _state != PlayerbackStatePlaying) {
        [self.playerController.player play];
        _state = PlayerbackStatePlaying;
        _videoPlayer->OnPlayEvent((int)VideoPlayer::EventType::PLAYING);
    }
}

-(void) pause
{
    if (self.playerController.player && _state == PlayerbackStatePlaying) {
        [self.playerController.player pause];
        _state = PlayerbackStatePaused;
        _videoPlayer->OnPlayEvent((int)VideoPlayer::EventType::PAUSED);
    }
}

-(void) resume
{
    if (self.playerController.player && _state == PlayerbackStatePaused)
        [self play];
}

-(void) stop
{
    // AVPlayer doesn't have stop, so just pause it, and seek time to 0.
    if (self.playerController.player && _state != PlayerbackStopped) {
        [self seekTo:0];
        [self.playerController.player pause];
        _state = PlayerbackStopped;

        // stop() will be invoked in dealloc, which is invoked by _videoPlayer's destructor,
        // so do't send the message when _videoPlayer is being deleted.
        if (_videoPlayer)
            _videoPlayer->OnPlayEvent((int)VideoPlayer::EventType::STOPPED);
    }
}

-(void) registerPlayerEventListener
{
    if (self.playerController.player) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(videoFinished:)
                                                 name:AVPlayerItemDidPlayToEndTimeNotification
                                                 object:self.playerController.player.currentItem];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(videoFinished:)
                                                     name:AVPlayerItemFailedToPlayToEndTimeNotification
                                                   object:self.playerController.player.currentItem];
    }
}

-(void) removePlayerEventListener
{
    if (self.playerController.player) {
        [[NSNotificationCenter defaultCenter] removeObserver:self
                                              name:AVPlayerItemDidPlayToEndTimeNotification
                                              object:self.playerController.player.currentItem];
        [[NSNotificationCenter defaultCenter] removeObserver:self
                                                        name:AVPlayerItemFailedToPlayToEndTimeNotification
                                                      object:self.playerController.player.currentItem];
    }
}

@end
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
@implementation PlayerView
-(void)mouseDown:(NSEvent *)event {
    if (_wrapper.userInteractionEnabled && _wrapper.playerController.player) {
        if (_wrapper.state == PlayerbackStatePaused) {
            [_wrapper resume];
        }
        else if (_wrapper.state == PlayerbackStatePlaying) {
            [_wrapper pause];
        }
    }
}
@end
#endif
//------------------------------------------------------------------------------------------------------------

VideoPlayer::VideoPlayer()
{
    _videoView = [[UIVideoViewWrapperApple alloc] init:this];
    ReigsterVisibleNotify();
#if CC_VIDEOPLAYER_DEBUG_DRAW
    _debugDrawNode = DrawNode::create();
    addChild(_debugDrawNode);
#endif
}

VideoPlayer::~VideoPlayer()
{
    if(_videoView)
    {
        [((UIVideoViewWrapperApple*)_videoView) dealloc];
        if (_isPlaying || _isPaused) {
            OnPlayEvent((int)VideoPlayer::EventType::STOPPED);
        }
    }
    UnreigsterVisibleNotify();
}

void VideoPlayer::SetFileName(const std::string& fileName)
{
    std::string fullFilePath = FileUtils::getInstance()->fullPathForFilename(fileName);
    if (_videoURL == fullFilePath) {
        return;
    }
    Stop();
    _videoURL = fullFilePath;
    _videoSource = VideoPlayer::Source::FILENAME;
    [((UIVideoViewWrapperApple*)_videoView) setURL:(int)_videoSource :_videoURL];
}

void VideoPlayer::SetURL(const std::string& videoUrl)
{
    if (_videoURL == videoUrl) {
        return;
    }
    Stop();
    _videoURL = videoUrl;
    _videoSource = VideoPlayer::Source::URL;
    [((UIVideoViewWrapperApple*)_videoView) setURL:(int)_videoSource :_videoURL];
}

void VideoPlayer::SetLooping(bool looping)
{
    _isLooping = looping;
    [((UIVideoViewWrapperApple*)_videoView) setRepeatEnabled:_isLooping];
}

void VideoPlayer::SetUserInputEnabled(bool enableInput)
{
    _isUserInputEnabled = enableInput;
    [((UIVideoViewWrapperApple*)_videoView) setUserInteractionEnabled:enableInput];
}

void VideoPlayer::SetStyle(StyleType style)
{
    _styleType = style;

    switch (style) {
        case StyleType::DEFAULT:
            [((UIVideoViewWrapperApple*)_videoView) showPlaybackControls:TRUE];
            break;

        case StyleType::NONE:
            [((UIVideoViewWrapperApple*)_videoView) showPlaybackControls:FALSE];
            break;
    }
}

void VideoPlayer::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags)
{
    cocos2d::ui::Widget::draw(renderer,transform,flags);

    if (flags & FLAGS_TRANSFORM_DIRTY)
    {
        auto directorInstance = Director::getInstance();
        auto glView = directorInstance->getOpenGLView();
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        auto scaleFactor = [static_cast<CCEAGLView *>(glView->getEAGLView()) contentScaleFactor];
#else
        auto scaleFactor = 1.0;
#endif
        auto winSize = directorInstance->getWinSize();

        if (!_fullScreenEnabled){
            auto frameSize = glView->getFrameSize();
            auto leftBottom = convertToWorldSpace(Vec2::ZERO);
            auto rightTop = convertToWorldSpace(Vec2(_contentSize.width,_contentSize.height));

            auto uiLeft = (frameSize.width / 2 + (leftBottom.x - winSize.width / 2 ) * glView->getScaleX()) / scaleFactor;
            auto uiTop = (frameSize.height /2 - (rightTop.y - winSize.height / 2) * glView->getScaleY()) / scaleFactor;

            [((UIVideoViewWrapperApple*)_videoView) setFrame :uiLeft :uiTop
                                                              :(rightTop.x - leftBottom.x) * glView->getScaleX() / scaleFactor
                                                              :( (rightTop.y - leftBottom.y) * glView->getScaleY()/scaleFactor)];
        }
        else {
            [((UIVideoViewWrapperApple*)_videoView) setFrame :0 :0
                                                           :winSize.width * glView->getScaleX() / scaleFactor
                                                           :winSize.height * glView->getScaleY()/scaleFactor];
        }
    }

#if CC_VIDEOPLAYER_DEBUG_DRAW
    _debugDrawNode->clear();
    auto size = getContentSize();
    Point vertices[4]=
    {
        Point::ZERO,
        Point(size.width, 0),
        Point(size.width, size.height),
        Point(0, size.height)
    };
    _debugDrawNode->drawPoly(vertices, 4, true, Color4F(1.0, 1.0, 1.0, 1.0));
#endif
}

bool VideoPlayer::IsFullScreenEnabled()const
{
    return _fullScreenEnabled;
}

void VideoPlayer::SetFullScreenEnabled(bool enabled)
{
    if (_fullScreenEnabled != enabled) {
        _fullScreenEnabled = enabled;
        _transformUpdated = _transformDirty = _inverseDirty = true;
    }
}

void VideoPlayer::SetKeepAspectRatioEnabled(bool enable)
{
    if (_keepAspectRatioEnabled != enable)
    {
        _keepAspectRatioEnabled = enable;
        [((UIVideoViewWrapperApple*)_videoView) setKeepRatioEnabled:enable];
    }
}

void VideoPlayer::Play()
{
    if (! _videoURL.empty())
    {
        [((UIVideoViewWrapperApple*)_videoView) play];
    }
}

void VideoPlayer::Pause()
{
    if (! _videoURL.empty())
    {
        [((UIVideoViewWrapperApple*)_videoView) pause];
    }
}

void VideoPlayer::Resume()
{
    if (! _videoURL.empty())
    {
        [((UIVideoViewWrapperApple*)_videoView) resume];
    }
}

void VideoPlayer::Stop()
{
    if (! _videoURL.empty())
    {
        [((UIVideoViewWrapperApple*)_videoView) stop];
    }
}

void VideoPlayer::SeekTo(float sec)
{
    if (! _videoURL.empty())
    {
        [((UIVideoViewWrapperApple*)_videoView) seekTo:sec];
    }
}

bool VideoPlayer::IsPlaying() const
{
    return _isPlaying;
}

bool VideoPlayer::IsLooping() const
{
    return _isLooping;
}

bool VideoPlayer::IsUserInputEnabled() const
{
    return _isUserInputEnabled;
}

void VideoPlayer::setVisible(bool visible)
{
    cocos2d::ui::Widget::setVisible(visible);

    if (!visible)
    {
        [((UIVideoViewWrapperApple*)_videoView) setVisible:NO];
    }
    else if(isRunning())
    {
        [((UIVideoViewWrapperApple*)_videoView) setVisible:YES];
    }
}

void VideoPlayer::OnVisibleChanged(bool visible) {
    Widget::OnVisibleChanged(visible);
    if (visible) {
        [((UIVideoViewWrapperApple*)_videoView) setVisible:YES];
    }
    else {
        [((UIVideoViewWrapperApple*)_videoView) setVisible:NO];
    }
}

void VideoPlayer::onEnter()
{
    Widget::onEnter();
    if (IsDisplay() && !_videoURL.empty())
    {
        [((UIVideoViewWrapperApple*)_videoView) setVisible: YES];
    }
}

void VideoPlayer::onExit()
{
    Widget::onExit();
    [((UIVideoViewWrapperApple*)_videoView) setVisible: NO];
}

void VideoPlayer::AddEventListener(const VideoPlayer::ccVideoPlayerCallback& callback)
{
    _eventCallback = callback;
}

void VideoPlayer::OnPlayEvent(int event)
{
    if (event == (int)VideoPlayer::EventType::PLAYING) {
        _isPlaying = true;
    } else {
        _isPlaying = false;
    }

    if (_eventCallback)
    {
        _eventCallback(this, (VideoPlayer::EventType)event);
    }
}

cocos2d::ui::Widget* VideoPlayer::createCloneInstance()
{
    return VideoPlayer::create();
}

void VideoPlayer::copySpecialProperties(Widget *widget)
{
    VideoPlayer* videoPlayer = dynamic_cast<VideoPlayer*>(widget);
    if (videoPlayer)
    {
        _isLooping = videoPlayer->_isLooping;
        _styleType = videoPlayer->_styleType;
        _fullScreenDirty = videoPlayer->_fullScreenDirty;
        _videoURL = videoPlayer->_videoURL;
        _videoSource = videoPlayer->_videoSource;
        _eventCallback = videoPlayer->_eventCallback;
        SetUserInputEnabled(videoPlayer->_isUserInputEnabled);
        SetFullScreenEnabled(videoPlayer->_fullScreenEnabled);
        SetKeepAspectRatioEnabled(videoPlayer->_keepAspectRatioEnabled);
    }
}

#endif
