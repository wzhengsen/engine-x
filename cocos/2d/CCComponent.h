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

#ifndef __CC_FRAMEWORK_COMPONENT_H__
#define __CC_FRAMEWORK_COMPONENT_H__

/// @cond DO_NOT_SHOW
#include <string>
#include "base/CCRef.h"

NS_CC_BEGIN

class Node;

class CC_DLL Component : public Ref
{
public:
    static Component* create();

    /**
     * @js NA
     * @lua NA
     */
    virtual ~Component();

    virtual bool init();

    bool isEnabled() const { return _enabled; }
    virtual void setEnabled(bool enabled);
    
    const std::string& getName() const { return _name; }
    virtual void setName(const std::string& name) { _name = name; }
    
    Node* getOwner() const { return _owner; }
    virtual void setOwner(Node *owner);

    virtual void update(float delta);
    virtual bool serialize(void* r);

    virtual void onEnter();
    virtual void onExit();
    virtual void onAdd();
    virtual void onRemove();
#if CC_ENABLE_LUA_BINDING
    void SetEnterHandler(const std::function<void(Component*)>& handler) { _enterHandler = handler; }
    void SetExitHandler(const std::function<void(Component*)>& handler) { _exitHandler = handler; }
    void SetAddHandler(const std::function<void(Component*)>& handler) { _addHandler = handler; }
    void SetRemoveHandler(const std::function<void(Component*)>& handler) { _removeHandler = handler; }
#endif

CC_CONSTRUCTOR_ACCESS:
    /**
    * @js ctor
    */
    Component();

protected:
#if CC_ENABLE_LUA_BINDING
    std::function<void(Component*)> _enterHandler = nullptr;
    std::function<void(Component*)> _exitHandler = nullptr;
    std::function<void(Component*)> _addHandler = nullptr;
    std::function<void(Component*)> _removeHandler = nullptr;
#endif
    Node* _owner;
    std::string _name;
    bool _enabled;
};

NS_CC_END

/// @endcond
#endif  // __CC_FRAMEWORK_COMPONENT_H__
