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

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
std::map<HWND, VideoPlayer*> VideoPlayer::VideoPlayerMap = std::map<HWND, VideoPlayer*>();
bool VideoPlayer::sIsInitialized = false;
WNDPROC VideoPlayer::sPrevCocosWndProc = nullptr;

LRESULT VideoPlayer::hookGLFWWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND:
        if (HIWORD(wParam) == STN_CLICKED) {
            HWND vpView = (HWND)lParam;
            if (VideoPlayerMap.find(vpView) != VideoPlayerMap.end()) {
                VideoPlayer* pThis = (VideoPlayer*)GetWindowLongPtrW(vpView, GWLP_USERDATA);
                if (pThis && pThis->_isUserInputEnabled) {
                    if (pThis->_isPlaying) {
                        pThis->Suspend();
                    }
                    else if (pThis->_isPaused) {
                        pThis->Recover();
                    }
                }
            }
        }
        break;
    default:
        break;
    }
    return ::CallWindowProcW(sPrevCocosWndProc, hwnd, uMsg, wParam, lParam);
}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
std::map<X11Window, VideoPlayer*> VideoPlayer::VideoPlayerMap = std::map<X11Window, VideoPlayer*>();
#endif

void VideoPlayer::CreateVLC() {
    vlcPlayer = libvlc_media_player_new(vlcInstance);

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    HWND hwnd = cocos2d::Director::getInstance()->getOpenGLView()->getWin32Window();
    HINSTANCE instance = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
    if (!sIsInitialized) {
        sIsInitialized = true;
        sPrevCocosWndProc = (WNDPROC)SetWindowLongPtrW(hwnd, GWLP_WNDPROC, (LONG_PTR)hookGLFWWindowProc);
    }

    _videoView = ::CreateWindow(L"STATIC", L"", WS_CHILD | SS_BITMAP | WS_VISIBLE | SS_NOTIFY, 0, 0, 0, 0, hwnd, nullptr, instance, nullptr);
    SetWindowLongPtrW(_videoView, GWLP_USERDATA, (LONG_PTR)this);
    // 渲染到_videoView
    libvlc_media_player_set_hwnd(vlcPlayer, _videoView);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    auto glView = cocos2d::Director::getInstance()->getOpenGLView();
    dpy = (Display*)glView->getX11Display();
    win = glView->getX11Window();
    const int screen_num = DefaultScreen(dpy);
    const int white = WhitePixel(dpy, screen_num);

    _videoView = XCreateSimpleWindow((Display*)dpy, win, -1, -1, 1, 1, 0, white, white);
    // 渲染到_videoView
    libvlc_media_player_set_xwindow(vlcPlayer, _videoView);
#endif
}

void VideoPlayer::ResizeMoveVLC() noexcept {
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    if (_fullScreenEnabled) {
        const auto frameSize = Director::getInstance()->getOpenGLView()->getFrameSize();
        w = static_cast<uint32_t>(frameSize.width);
        h = static_cast<uint32_t>(frameSize.height);
    }
    else {
        const auto uiRect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
        x = static_cast<int>(uiRect.origin.x);
        y = static_cast<int>(uiRect.origin.y);
        w = static_cast<uint32_t>(uiRect.size.width);
        h = static_cast<uint32_t>(uiRect.size.height);
    }
    int _x = x;
    int _y = y;
    int _w = w;
    int _h = h;
    if (mVideoWidth && mVideoHeight) {
        if (_keepAspectRatioEnabled) {
            if (mVideoWidth * h > w * mVideoHeight) {
                _h = w * mVideoHeight / mVideoWidth;
            }
            else if (mVideoWidth * h < w * mVideoHeight) {
                _w = h * mVideoWidth / mVideoHeight;
            }
            _x = x + (w - _w) / 2;
            _y = y + (h - _h) / 2;
            libvlc_video_set_aspect_ratio(vlcPlayer, nullptr);
        }
        else {
            std::stringstream sStr = std::stringstream();
            sStr << static_cast<int>(_w) << ":" << static_cast<int>(_h);
            std::string str = std::string();
            sStr >> str;
            libvlc_video_set_aspect_ratio(vlcPlayer, str.c_str());
        }
    }
    else {
        _w = 0;
        _h = 0;
    }
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    ::MoveWindow(_videoView, _x, _y, _w, _h, TRUE);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    if (_w == 0 || _h == 0) {
        // A zero size X11Window may be cause a error.
        _x = -1;
        _y = -1;
        _w = 1;
        _h = 1;
    }
    XMoveResizeWindow((Display*)dpy, _videoView, _x, _y, _w, _h);
#endif
}

void VideoPlayer::ShowVLC(bool b) noexcept {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    ::ShowWindow(_videoView, b ? SW_SHOW : SW_HIDE);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    if (b) {
        XMapWindow((Display*)dpy, _videoView);
    }
    else {
        XUnmapWindow((Display*)dpy, _videoView);
    }
#endif
}

void VideoPlayer::DestroyVLC() noexcept {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    ::DestroyWindow(_videoView);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    XDestroyWindow((Display*)dpy, _videoView);
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
            libvlc_video_get_size(vp->vlcPlayer, 0, &vp->mVideoWidth, &vp->mVideoHeight);
            vp->_transformUpdated = vp->_transformDirty = vp->_inverseDirty = true;
            vp->_isPlaying = true;
            vp->_isPaused = false;
            vp->OnPlayEvent((int)VideoPlayer::EventType::PLAYING);
            break;
        case libvlc_MediaPlayerPaused:
            vp->_isPlaying = false;
            vp->_isPaused = true;
            vp->OnPlayEvent((int)VideoPlayer::EventType::PAUSED);
            break;
        case libvlc_MediaPlayerStopped:
            vp->_isPlaying = false;
            vp->_isPaused = false;
            vp->OnPlayEvent((int)VideoPlayer::EventType::STOPPED);
            break;
        case libvlc_MediaPlayerEndReached:
            if (vp->IsLooping()) {
                vp->Play();
            }
            vp->OnPlayEvent((int)VideoPlayer::EventType::COMPLETED);
            break;
        case libvlc_MediaPlayerEncounteredError:
            vp->OnPlayEvent((int)VideoPlayer::EventType::V_ERROR);
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

    if (VideoPlayerMap.empty()) {
        // init vlc modules, should be done only once
        vlcInstance = libvlc_new(0, nullptr);
    }
    CreateVLC();
    VideoPlayerMap.emplace(_videoView, this);
    ShowVLC(true);

    ReigsterVisibleNotify();

    // 事件监听
    libvlc_event_manager_t* em = libvlc_media_player_event_manager(vlcPlayer);
    libvlc_event_attach(em, libvlc_MediaPlayerPlaying, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerPaused, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerStopped, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerEndReached, VLC_PlayerEventCallBack, this);
    libvlc_event_attach(em, libvlc_MediaPlayerEncounteredError, VLC_PlayerEventCallBack, this);

    // Disable mouse and key event,it handled by self win32 proc.
    libvlc_video_set_mouse_input(vlcPlayer, false);
    libvlc_video_set_key_input(vlcPlayer, false);

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
    libvlc_event_detach(em, libvlc_MediaPlayerEncounteredError, VLC_PlayerEventCallBack, this);

    // Stop playing
    libvlc_media_player_stop(vlcPlayer);

    // 手动调用一次STOPPED回调。
    if (_isPlaying || _isPaused) {
        OnPlayEvent((int)VideoPlayer::EventType::STOPPED);
    }
    // Free the media_player
    libvlc_media_player_release(vlcPlayer);
    DestroyVLC();

    UnreigsterVisibleNotify();

    VideoPlayerMap.erase(_videoView);
    if (VideoPlayerMap.empty()) {
        if (vlcInstance) {
            libvlc_release(vlcInstance);
            vlcInstance = nullptr;
        }
    }
}

void VideoPlayer::SetFileName(const std::string& fileName) {
    std::string fullFilePath = FileUtils::getInstance()->fullPathForFilename(fileName);
    if (fullFilePath.find("file:///") != 0) {
        if (fullFilePath[0] == '/') {
            fullFilePath = "file://" + fullFilePath;
        }
        else {
            fullFilePath = "file:///" + fullFilePath;
        }
    }
    if (_videoURL == fullFilePath) {
        return;
    }
    Stop();
    _videoURL = fullFilePath;
    _videoSource = VideoPlayer::Source::FILENAME;
}

void VideoPlayer::SetURL(const std::string& videoUrl) {
    if (_videoURL == videoUrl) {
        return;
    }
    Stop();
    _videoURL = videoUrl;
    _videoSource = VideoPlayer::Source::URL;
}

void VideoPlayer::SetLooping(bool looping) {
    _isLooping = looping;
}

void VideoPlayer::SetUserInputEnabled(bool enableInput) {
    if (_isUserInputEnabled != enableInput) {
        _isUserInputEnabled = enableInput;
    }
}

void VideoPlayer::SetStyle(StyleType style) {
    _styleType = style;
}

void VideoPlayer::draw(Renderer* renderer, const Mat4& transform, uint32_t flags) {
    cocos2d::ui::Widget::draw(renderer, transform, flags);

    if (flags & FLAGS_TRANSFORM_DIRTY) {
        ResizeMoveVLC();
    }

#if CC_VIDEOPLAYER_DEBUG_DRAW
    _debugDrawNode->clear();
    auto size = getContentSize();
    Point vertices[4] =
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
        _transformUpdated = _transformDirty = _inverseDirty = true;
    }
}

bool VideoPlayer::IsFullScreenEnabled()const {
    return _fullScreenEnabled;
}

void VideoPlayer::SetKeepAspectRatioEnabled(bool enable) {
    if (_keepAspectRatioEnabled != enable) {
        _keepAspectRatioEnabled = enable;
        _transformUpdated = _transformDirty = _inverseDirty = true;
    }
}

#if CC_VIDEOPLAYER_DEBUG_DRAW
void VideoPlayer::drawDebugData() {
    Director* director = Director::getInstance();
    CCASSERT(nullptr != director, "Director is null when setting matrix stack");

    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);

    auto size = getContentSize();

    Point vertices[4] =
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
    if (!_videoURL.empty()) {
        // Create a new item
        libvlc_media_t* m = libvlc_media_new_location(vlcInstance, _videoURL.c_str());
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

void VideoPlayer::Suspend() {
    if (!_videoURL.empty()) {
        libvlc_media_player_pause(vlcPlayer);
    }
}

void VideoPlayer::Recover() {
    if (!_videoURL.empty()) {
        libvlc_media_player_set_pause(vlcPlayer, 0);
    }
}

void VideoPlayer::Stop() {
    if (!_videoURL.empty()) {
        libvlc_media_player_stop(vlcPlayer);
    }
}

void VideoPlayer::SeekTo(float sec) {
    if (!_videoURL.empty()) {
        libvlc_media_player_set_time(vlcPlayer, static_cast<uint64_t>(sec * 1000));
    }
}

bool VideoPlayer::IsPlaying() const {
    return _isPlaying;
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

void VideoPlayer::OnVisibleChanged(bool visible) {
    Widget::OnVisibleChanged(visible);
    ShowVLC(visible);
}

void VideoPlayer::onEnter() {
    Widget::onEnter();
    if (IsDisplay() && !_videoURL.empty()) {
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

void VideoPlayer::copySpecialProperties(Widget* widget) {
    VideoPlayer* videoPlayer = dynamic_cast<VideoPlayer*>(widget);
    if (videoPlayer) {
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
