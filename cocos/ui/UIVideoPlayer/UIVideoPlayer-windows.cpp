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

using namespace cocos2d;
using namespace cocos2d::ui;

libvlc_instance_t* VideoPlayer::vlcInstance = nullptr;
size_t VideoPlayer::VideoPlayerCount = 0;

void VideoPlayer::VLC_PlayerEventCallBack(const libvlc_event_t* p_event, void* p_data) {
    if (!p_data) {
        return;
    }
    const libvlc_event_t copyEvent = *p_event;
    Director::getInstance()->getScheduler()->performFunctionInCocosThread([p_data, copyEvent]() {
        VideoPlayer* vp = static_cast<VideoPlayer*>(p_data);
        switch (copyEvent.type) {
        case libvlc_MediaPlayerPlaying:
            vp->onPlayEvent((int)VideoPlayer::EventType::PLAYING);
            break;
        case libvlc_MediaPlayerPaused:
            vp->onPlayEvent((int)VideoPlayer::EventType::PAUSED);
            break;
        case libvlc_MediaPlayerStopped:
            vp->onPlayEvent((int)VideoPlayer::EventType::STOPPED);
            break;
        case libvlc_MediaPlayerEndReached:
            if (vp->isLooping()) {
                vp->play();
            }
            vp->onPlayEvent((int)VideoPlayer::EventType::COMPLETED);
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
, _videoPlayerIndex(-1)
, _eventCallback(nullptr)
, _isPlaying(false)
, _isLooping(false)
, _isUserInputEnabled(true)
, _styleType(StyleType::DEFAULT)
, _videoSource(Source::FILENAME)
, _videoView(nullptr) {

    if (!VideoPlayerCount) {
        // init vlc modules, should be done only once
        vlcInstance = libvlc_new(0, nullptr);
    }
    VideoPlayerCount++;

    HWND hwnd = cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window();
    HINSTANCE instance = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
    _videoView = ::CreateWindowEx(WS_EX_LEFT, L"STATIC", L"", WS_CHILD, 0, 0, 0, 0, hwnd, nullptr, instance, nullptr);

    vlcPlayer = libvlc_media_player_new(vlcInstance);
    // 渲染到_videoView
    libvlc_media_player_set_hwnd(vlcPlayer, _videoView);

    // 事件监听
    libvlc_event_manager_t* em = libvlc_media_player_event_manager(vlcPlayer);
    libvlc_event_attach(em, libvlc_MediaPlayerPlaying, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerPaused, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerStopped, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerEndReached, VLC_PlayerEventCallBack, this);

    setUserInputEnabled(true);

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

    const bool playing = isPlaying();
    // Stop playing
    libvlc_media_player_stop(vlcPlayer);

    // 手动调用一次STOPPED回调。
    if (playing || _isPaused) {
        onPlayEvent((int)VideoPlayer::EventType::STOPPED);
    }
    // Free the media_player
    libvlc_media_player_release(vlcPlayer);

    ::DestroyWindow(static_cast<HWND>(_videoView));

    VideoPlayerCount--;
    if (!VideoPlayerCount) {
        if (vlcInstance) {
            libvlc_release(vlcInstance);
            vlcInstance = nullptr;
        }
    }
}

void VideoPlayer::setFileName(const std::string& fileName) {
    _videoURL = FileUtils::getInstance()->fullPathForFilename(fileName);
    _videoSource = VideoPlayer::Source::FILENAME;
}

void VideoPlayer::setURL(const std::string& videoUrl) {
    _videoURL = videoUrl;
    _videoSource = VideoPlayer::Source::URL;
}

void VideoPlayer::setLooping(bool looping) {
    _isLooping = looping;
}

void VideoPlayer::setUserInputEnabled(bool enableInput) {
    _isUserInputEnabled = enableInput;
    libvlc_video_set_mouse_input(vlcPlayer, enableInput);
    libvlc_video_set_key_input(vlcPlayer, enableInput);
}

void VideoPlayer::setStyle(StyleType style) {
    _styleType = style;
}

void VideoPlayer::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags) {
    cocos2d::ui::Widget::draw(renderer,transform,flags);

    if ((!_fullScreenEnabled) && (flags & FLAGS_TRANSFORM_DIRTY)) {
        const auto uiRect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
        ::MoveWindow(
            static_cast<HWND>(_videoView),
            static_cast<int>(uiRect.origin.x), static_cast<int>(uiRect.origin.y),
            static_cast<int>(uiRect.size.width), static_cast<int>(uiRect.size.height),
            TRUE
        );
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

void VideoPlayer::setFullScreenEnabled(bool enabled) {
    if (_fullScreenEnabled != enabled) {
        _fullScreenEnabled = enabled;

        if (enabled) {
            const auto frameSize = Director::getInstance()->getOpenGLView()->getFrameSize();
            //libvlc_set_fullscreen(vlcPlayer, enabled);
            ::MoveWindow(
                static_cast<HWND>(_videoView),
                0, 0,
                static_cast<int>(frameSize.width), static_cast<int>(frameSize.height),
                TRUE
            );
        }
        else {
            const bool vs = isVisible();
            setVisible(!vs);
            setVisible(vs);
        }
    }
}

bool VideoPlayer::isFullScreenEnabled()const {
    return _fullScreenEnabled;
}

void VideoPlayer::setKeepAspectRatioEnabled(bool enable) {
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

void VideoPlayer::play() {
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

void VideoPlayer::pause() {
    if (! _videoURL.empty()) {
        libvlc_media_player_pause(vlcPlayer);
        _isPaused = true;
        _isPlaying = false;
    }
}

void VideoPlayer::resume() {
    if (! _videoURL.empty()) {
        libvlc_media_player_set_pause(vlcPlayer, 0);
        _isPaused = false;
        _isPlaying = true;
    }
}

void VideoPlayer::stop() {
    if (! _videoURL.empty()) {
        libvlc_media_player_stop(vlcPlayer);
        _isPlaying = false;
        _isPaused = false;
    }
}

void VideoPlayer::seekTo(float sec) {
    if (! _videoURL.empty()) {
        libvlc_media_player_set_time(vlcPlayer,static_cast<uint64_t>(sec * 1000));
    }
}

bool VideoPlayer::isPlaying() const {
    return libvlc_media_player_is_playing(vlcPlayer);
}

bool VideoPlayer::isLooping() const {
    return _isLooping;
}

bool VideoPlayer::isUserInputEnabled() const {
    return _isUserInputEnabled;
}

void VideoPlayer::setVisible(bool visible) {
    cocos2d::ui::Widget::setVisible(visible);

    if (!visible || isRunning()) {
        ::ShowWindow(static_cast<HWND>(_videoView), visible ? SW_SHOW : SW_HIDE);
    }
}

void VideoPlayer::onEnter() {
    Widget::onEnter();
    if (isVisible() && !_videoURL.empty()) {
        ::ShowWindow(static_cast<HWND>(_videoView), SW_SHOW);
    }
}

void VideoPlayer::onExit() {
    Widget::onExit();
    ::ShowWindow(static_cast<HWND>(_videoView), SW_HIDE);
}

void VideoPlayer::addEventListener(const VideoPlayer::ccVideoPlayerCallback& callback) {
    _eventCallback = callback;
}

void VideoPlayer::onPlayEvent(int event) {
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
        _videoPlayerIndex = videoPlayer->_videoPlayerIndex;
        _eventCallback = videoPlayer->_eventCallback;
        _videoView = videoPlayer->_videoView;
    }
}
