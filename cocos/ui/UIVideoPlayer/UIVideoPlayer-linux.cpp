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

using namespace cocos2d;
using namespace cocos2d::ui;

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

}

VideoPlayer::~VideoPlayer() {
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
}

void VideoPlayer::setStyle(StyleType style) {
    _styleType = style;
}

void VideoPlayer::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags) {
    cocos2d::ui::Widget::draw(renderer,transform,flags);

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

}

bool VideoPlayer::isFullScreenEnabled()const {
    return _fullScreenEnabled;
}

void VideoPlayer::setKeepAspectRatioEnabled(bool enable) {

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

}

void VideoPlayer::pause() {

}

void VideoPlayer::resume() {

}

void VideoPlayer::stop() {

}

void VideoPlayer::seekTo(float sec) {

}

bool VideoPlayer::isPlaying() const {
    return false;
}

bool VideoPlayer::isLooping() const {
    return _isLooping;
}

bool VideoPlayer::isUserInputEnabled() const {
    return _isUserInputEnabled;
}

void VideoPlayer::setVisible(bool visible) {
    cocos2d::ui::Widget::setVisible(visible);
}

void VideoPlayer::onEnter() {
    Widget::onEnter();

}

void VideoPlayer::onExit() {
    Widget::onExit();
}

void VideoPlayer::addEventListener(const VideoPlayer::ccVideoPlayerCallback& callback) {
    _eventCallback = callback;
}

void VideoPlayer::onPlayEvent(int event) {
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
