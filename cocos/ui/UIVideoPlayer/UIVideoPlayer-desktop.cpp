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

#include "UIVideoPlayer.h"

#include <unordered_map>
#include <stdlib.h>
#include <string>
#include "base/CCDirector.h"
#include "base/CCEventListenerKeyboard.h"
#include "platform/CCFileUtils.h"
#include "ui/UIHelper.h"
#include "vlc/vlc.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#include <X11/Xlib.h>
#endif

using namespace cocos2d;
using namespace cocos2d::ui;

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 ||\
    CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
libvlc_instance_t* VideoPlayer::vlcInstance = nullptr;
size_t VideoPlayer::VideoPlayerCount = 0;

void VideoPlayer::CreateVLC() {
    vlcPlayer = libvlc_media_player_new(vlcInstance);

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    HWND hwnd = cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window();
    HINSTANCE instance = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
    _videoView = ::CreateWindowEx(WS_EX_LEFT, L"STATIC", L"", WS_CHILD, 0, 0, 0, 0, hwnd, nullptr, instance, nullptr);
    // 渲染到_videoView
    libvlc_media_player_set_hwnd(vlcPlayer, _videoView);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    auto glView = cocos2d::Director::getInstance()->getOpenGLView();
    dpy = (Display*)glView->getX11Display();
    win = glView->getX11Window();
    const int screen_num = DefaultScreen(dpy);
    const int white = WhitePixel(dpy, screen_num);

    _videoView = XCreateSimpleWindow((Display*)dpy,win,-1,-1,1,1,0,white,white);
    // 渲染到_videoView
    libvlc_media_player_set_xwindow(vlcPlayer, _videoView);
#endif
}

void VideoPlayer::ResizeMoveVLC(int32_t x, int32_t y,uint32_t w, uint32_t h) noexcept {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    ::MoveWindow(_videoView, x, y, w, h, TRUE);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    if (w == 0 || h == 0) {
        // A zero size X11Window may be cause a error.
        x = -1;
        y = -1;
        w = 1;
        h = 1;
    }
    XMoveResizeWindow((Display*)dpy, _videoView, x, y, w, h);
#endif
}

void VideoPlayer::ShowVLC(bool b) noexcept {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    ::ShowWindow(_videoView, b ? SW_SHOW : SW_HIDE);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    if(b) {
        XMapWindow((Display*)dpy,_videoView);
    }
    else {
        XUnmapWindow((Display*)dpy,_videoView);
    }
#endif
}

void VideoPlayer::DestroyVLC() noexcept {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    ::DestroyWindow(_videoView);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    XDestroyWindow((Display*)dpy,_videoView);
#endif
}


#endif

void VideoPlayer::VLC_PlayerEventCallBack(const libvlc_event_t* p_event, void* p_data) {
    if (!p_data) {
        return;
    }
    const libvlc_event_t copyEvent = *p_event;
    Director::getInstance()->getScheduler()->performFunctionInCocosThread([p_data, copyEvent]() {
        VideoPlayer* vp = static_cast<VideoPlayer*>(p_data);
        switch (copyEvent.type) {
        case libvlc_MediaPlayerPlaying:
            vp->OnPlayEvent((int)VideoPlayer::EventType::PLAYING);
            break;
        case libvlc_MediaPlayerPaused:
            vp->OnPlayEvent((int)VideoPlayer::EventType::PAUSED);
            break;
        case libvlc_MediaPlayerStopped:
            vp->OnPlayEvent((int)VideoPlayer::EventType::STOPPED);
            break;
        case libvlc_MediaPlayerEndReached:
            if (vp->IsLooping()) {
                vp->Play();
            }
            vp->OnPlayEvent((int)VideoPlayer::EventType::COMPLETED);
            break;
        default:
            break;
        }
        });
}

VideoPlayer::VideoPlayer()
: _fullScreenDirty(false)
, _fullScreenEnabled(false)
, _keepAspectRatioEnabled(false)
, _eventCallback(nullptr)
, _isPlaying(false)
, _isLooping(false)
, _isUserInputEnabled(true)
, _styleType(StyleType::DEFAULT)
, _videoSource(Source::FILENAME) {

    if (!VideoPlayerCount) {
        // init vlc modules, should be done only once
        vlcInstance = libvlc_new(0, nullptr);
    }
    VideoPlayerCount++;
    CreateVLC();
    ShowVLC(true);

    // 事件监听
    libvlc_event_manager_t* em = libvlc_media_player_event_manager(vlcPlayer);
    libvlc_event_attach(em, libvlc_MediaPlayerPlaying, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerPaused, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerStopped, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerEndReached, VLC_PlayerEventCallBack, this);

    SetUserInputEnabled(true);

#if CC_VIDEOPLAYER_DEBUG_DRAW
    _debugDrawNode = DrawNode::create();
    addChild(_debugDrawNode);
#endif
}

VideoPlayer::~VideoPlayer() {
    // 注销事件
    libvlc_event_manager_t* em = libvlc_media_player_event_manager(vlcPlayer);
    libvlc_event_detach(em, libvlc_MediaPlayerPlaying, VLC_PlayerEventCallBack, this);
    libvlc_event_detach(em, libvlc_MediaPlayerPaused, VLC_PlayerEventCallBack, this);
    libvlc_event_detach(em, libvlc_MediaPlayerStopped, VLC_PlayerEventCallBack, this);
    libvlc_event_detach(em, libvlc_MediaPlayerEndReached, VLC_PlayerEventCallBack, this);

    const bool playing = IsPlaying();
    // Stop playing
    libvlc_media_player_stop(vlcPlayer);

    // 手动调用一次STOPPED回调。
    if (playing || _isPaused) {
        OnPlayEvent((int)VideoPlayer::EventType::STOPPED);
    }
    // Free the media_player
    libvlc_media_player_release(vlcPlayer);
    DestroyVLC();

    VideoPlayerCount--;
    if (!VideoPlayerCount) {
        if (vlcInstance) {
            libvlc_release(vlcInstance);
            vlcInstance = nullptr;
        }
    }
}

void VideoPlayer::SetFileName(const std::string& fileName) {
    _videoURL = FileUtils::getInstance()->fullPathForFilename(fileName);
    _videoSource = VideoPlayer::Source::FILENAME;
}

void VideoPlayer::SetURL(const std::string& videoUrl) {
    _videoURL = videoUrl;
    _videoSource = VideoPlayer::Source::URL;
}

void VideoPlayer::SetLooping(bool looping) {
    _isLooping = looping;
}

void VideoPlayer::SetUserInputEnabled(bool enableInput) {
    _isUserInputEnabled = enableInput;
    libvlc_video_set_mouse_input(vlcPlayer, enableInput);
    libvlc_video_set_key_input(vlcPlayer, enableInput);
}

void VideoPlayer::SetStyle(StyleType style) {
    _styleType = style;
}

void VideoPlayer::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags) {
    cocos2d::ui::Widget::draw(renderer,transform,flags);

    if ((!_fullScreenEnabled) && (flags & FLAGS_TRANSFORM_DIRTY)) {
        const auto uiRect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
        ResizeMoveVLC(uiRect.origin.x, uiRect.origin.y, uiRect.size.width, uiRect.size.height);
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
    _debugdrawNode->drawPoly(vertices, 4, true, Color4F(1.0, 1.0, 1.0, 1.0));
#endif
}

void VideoPlayer::SetFullScreenEnabled(bool enabled) {
    if (_fullScreenEnabled != enabled) {
        _fullScreenEnabled = enabled;

        if (enabled) {
            const auto frameSize = Director::getInstance()->getOpenGLView()->getFrameSize();
            //libvlc_set_fullscreen(vlcPlayer, enabled);
            ResizeMoveVLC(0, 0, frameSize.width, frameSize.height);
        }
        else {
            const bool vs = isVisible();
            setVisible(!vs);
            setVisible(vs);
        }
    }
}

bool VideoPlayer::IsFullScreenEnabled()const {
    return _fullScreenEnabled;
}

void VideoPlayer::SetKeepAspectRatioEnabled(bool enable) {
    if (_keepAspectRatioEnabled != enable) {
        _keepAspectRatioEnabled = enable;
        libvlc_video_set_aspect_ratio(vlcPlayer, enable ? "16:9" : nullptr);
    }
}

#if CC_VIDEOPLAYER_DEBUG_DRAW
void VideoPlayer::drawDebugData()
{
    Director* director = Director::getInstance();
    CCASSERT(nullptr != director, "Director is null when setting matrix stack");

    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);

    auto size = getContentSize();

    Point vertices[4]=
    {
        Point::ZERO,
        Point(size.width, 0),
        Point(size.width, size.height),
        Point(0, size.height)
    };

    DrawPrimitives::drawPoly(vertices, 4, true);

    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
#endif

void VideoPlayer::Play() {
    if (! _videoURL.empty()) {
        // Create a new item
        libvlc_media_t* m = libvlc_media_new_location(vlcInstance, (_videoSource == VideoPlayer::Source::FILENAME ? "file:///" + _videoURL : _videoURL).c_str());
        if (m) {
            // Create a media player playing environement
            libvlc_media_player_set_media(vlcPlayer, m);
            // play the media_player
            libvlc_media_player_play(vlcPlayer);
            // No need to keep the media now
            libvlc_media_release(m);
            _isPlaying = true;
            _isPaused = false;
        }
    }
}

void VideoPlayer::Pause() {
    if (! _videoURL.empty()) {
        libvlc_media_player_pause(vlcPlayer);
        _isPaused = true;
        _isPlaying = false;
    }
}

void VideoPlayer::Resume() {
    if (! _videoURL.empty()) {
        libvlc_media_player_set_pause(vlcPlayer, 0);
        _isPaused = false;
        _isPlaying = true;
    }
}

void VideoPlayer::Stop() {
    if (! _videoURL.empty()) {
        libvlc_media_player_stop(vlcPlayer);
        _isPlaying = false;
        _isPaused = false;
    }
}

void VideoPlayer::SeekTo(float sec) {
    if (! _videoURL.empty()) {
        libvlc_media_player_set_time(vlcPlayer,static_cast<uint64_t>(sec * 1000));
    }
}

bool VideoPlayer::IsPlaying() const {
    return libvlc_media_player_is_playing(vlcPlayer);
}

bool VideoPlayer::IsLooping() const {
    return _isLooping;
}

bool VideoPlayer::IsUserInputEnabled() const {
    return _isUserInputEnabled;
}

void VideoPlayer::setVisible(bool visible) {
    cocos2d::ui::Widget::setVisible(visible);
    if (!visible || isRunning()) {
        ShowVLC(visible);
    }
}

void VideoPlayer::onEnter() {
    Widget::onEnter();
    if (isVisible() && !_videoURL.empty()) {
        ShowVLC(true);
    }
}

void VideoPlayer::onExit() {
    Widget::onExit();
    ShowVLC(false);
}

void VideoPlayer::AddEventListener(const VideoPlayer::ccVideoPlayerCallback& callback) {
    _eventCallback = callback;
}

void VideoPlayer::OnPlayEvent(int event) {
    if (_eventCallback) {
        _eventCallback(this, (VideoPlayer::EventType)event);
    }
}

cocos2d::ui::Widget* VideoPlayer::createCloneInstance() {
    return VideoPlayer::create();
}

void VideoPlayer::copySpecialProperties(Widget *widget) {
    VideoPlayer* videoPlayer = dynamic_cast<VideoPlayer*>(widget);
    if (videoPlayer) {
        _isPlaying = videoPlayer->_isPlaying;
        _isLooping = videoPlayer->_isLooping;
        _isUserInputEnabled = videoPlayer->_isUserInputEnabled;
        _styleType = videoPlayer->_styleType;
        _fullScreenEnabled = videoPlayer->_fullScreenEnabled;
        _fullScreenDirty = videoPlayer->_fullScreenDirty;
        _videoURL = videoPlayer->_videoURL;
        _keepAspectRatioEnabled = videoPlayer->_keepAspectRatioEnabled;
        _videoSource = videoPlayer->_videoSource;
        _eventCallback = videoPlayer->_eventCallback;
    }
}