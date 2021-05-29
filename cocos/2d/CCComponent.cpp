/****************************************************************************
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

#include "2d/CCComponent.h"

NS_CC_BEGIN

Component::Component()
: _owner(nullptr)
, _enabled(true)
{
}

Component::~Component()
{
}

bool Component::init()
{
    return true;
}

void Component::onEnter()
{
#if CC_ENABLE_LUA_BINDING
    if (_enterHandler) {
        _enterHandler(this);
    }
#endif
}

void Component::onExit()
{
#if CC_ENABLE_LUA_BINDING
    if (_exitHandler) {
        _exitHandler(this);
    }
#endif
}

void Component::onAdd()
{
#if CC_ENABLE_LUA_BINDING
    if (_addHandler) {
        _addHandler(this);
    }
#endif
}

void Component::onRemove()
{
#if CC_ENABLE_LUA_BINDING
    if (_removeHandler) {
        _removeHandler(this);
    }
#endif
}

void Component::update(float /*delta*/)
{
}

bool Component::serialize(void* /*ar*/)
{
    return true;
}

Component* Component::create()
{
    Component * ret = new (std::nothrow) Component();

    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }

    return ret;
}

void Component::setOwner(Node *owner)
{
    _owner = owner;
}

void Component::setEnabled(bool enabled)
{
    _enabled = enabled;
}

NS_CC_END
