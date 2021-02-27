#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUILayoutParameterTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LayoutParameter"];
pTable.new_enum("Type"
,"NONE",0
,"LINEAR",1
,"RELATIVE",2
);}
void RegisterLuaUILayoutParameterAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::LayoutParameter,cocos2d::Ref,cocos2d::LuaObject>("LayoutParameter",false);
ns["LayoutParameter"] = mt;
lua["LayoutParameter"] = sol::nil;
mt.set_function("setMargin",static_cast<void(cocos2d::ui::LayoutParameter::*)(const cocos2d::ui::Margin&)>(&cocos2d::ui::LayoutParameter::setMargin));
mt.set_function("getMargin",static_cast<const cocos2d::ui::Margin&(cocos2d::ui::LayoutParameter::*)()const>(&cocos2d::ui::LayoutParameter::getMargin));
mt.set_function("getLayoutType",static_cast<cocos2d::ui::LayoutParameter::Type(cocos2d::ui::LayoutParameter::*)()const>(&cocos2d::ui::LayoutParameter::getLayoutType));
mt.set_function("clone",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::LayoutParameter::*)()>(&cocos2d::ui::LayoutParameter::clone));
mt.set_function("createCloneInstance",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::LayoutParameter::*)()>(&cocos2d::ui::LayoutParameter::createCloneInstance));
mt.set_function("copyProperties",static_cast<void(cocos2d::ui::LayoutParameter::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::LayoutParameter::copyProperties));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::LayoutParameter*(*)()>(&cocos2d::ui::LayoutParameter::create));
RegisterLuaUILayoutParameterTypeAuto(lua);
}
void RegisterLuaUILinearLayoutParameterLinearGravityAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LinearLayoutParameter"];
pTable.new_enum("LinearGravity"
,"NONE",0
,"LEFT",1
,"TOP",2
,"RIGHT",3
,"BOTTOM",4
,"CENTER_VERTICAL",5
,"CENTER_HORIZONTAL",6
);}
void RegisterLuaUILinearLayoutParameterAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::LinearLayoutParameter,cocos2d::ui::LayoutParameter,cocos2d::Ref,cocos2d::LuaObject>("LinearLayoutParameter",false);
ns["LinearLayoutParameter"] = mt;
lua["LinearLayoutParameter"] = sol::nil;
mt.set_function("setGravity",static_cast<void(cocos2d::ui::LinearLayoutParameter::*)(cocos2d::ui::LinearLayoutParameter::LinearGravity)>(&cocos2d::ui::LinearLayoutParameter::setGravity));
mt.set_function("getGravity",static_cast<cocos2d::ui::LinearLayoutParameter::LinearGravity(cocos2d::ui::LinearLayoutParameter::*)()const>(&cocos2d::ui::LinearLayoutParameter::getGravity));
mt.set_function("createCloneInstance",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::LinearLayoutParameter::*)()>(&cocos2d::ui::LinearLayoutParameter::createCloneInstance));
mt.set_function("copyProperties",static_cast<void(cocos2d::ui::LinearLayoutParameter::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::LinearLayoutParameter::copyProperties));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::LinearLayoutParameter*(*)()>(&cocos2d::ui::LinearLayoutParameter::create));
RegisterLuaUILinearLayoutParameterLinearGravityAuto(lua);
}
void RegisterLuaUIRelativeLayoutParameterRelativeAlignAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RelativeLayoutParameter"];
pTable.new_enum("RelativeAlign"
,"NONE",0
,"PARENT_TOP_LEFT",1
,"PARENT_TOP_CENTER_HORIZONTAL",2
,"PARENT_TOP_RIGHT",3
,"PARENT_LEFT_CENTER_VERTICAL",4
,"CENTER_IN_PARENT",5
,"PARENT_RIGHT_CENTER_VERTICAL",6
,"PARENT_LEFT_BOTTOM",7
,"PARENT_BOTTOM_CENTER_HORIZONTAL",8
,"PARENT_RIGHT_BOTTOM",9
,"LOCATION_ABOVE_LEFTALIGN",10
,"LOCATION_ABOVE_CENTER",11
,"LOCATION_ABOVE_RIGHTALIGN",12
,"LOCATION_LEFT_OF_TOPALIGN",13
,"LOCATION_LEFT_OF_CENTER",14
,"LOCATION_LEFT_OF_BOTTOMALIGN",15
,"LOCATION_RIGHT_OF_TOPALIGN",16
,"LOCATION_RIGHT_OF_CENTER",17
,"LOCATION_RIGHT_OF_BOTTOMALIGN",18
,"LOCATION_BELOW_LEFTALIGN",19
,"LOCATION_BELOW_CENTER",20
,"LOCATION_BELOW_RIGHTALIGN",21
);}
void RegisterLuaUIRelativeLayoutParameterAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RelativeLayoutParameter,cocos2d::ui::LayoutParameter,cocos2d::Ref,cocos2d::LuaObject>("RelativeLayoutParameter",false);
ns["RelativeLayoutParameter"] = mt;
lua["RelativeLayoutParameter"] = sol::nil;
mt.set_function("setAlign",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(cocos2d::ui::RelativeLayoutParameter::RelativeAlign)>(&cocos2d::ui::RelativeLayoutParameter::setAlign));
mt.set_function("getAlign",static_cast<cocos2d::ui::RelativeLayoutParameter::RelativeAlign(cocos2d::ui::RelativeLayoutParameter::*)()const>(&cocos2d::ui::RelativeLayoutParameter::getAlign));
mt.set_function("setRelativeToWidgetName",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(const std::string&)>(&cocos2d::ui::RelativeLayoutParameter::setRelativeToWidgetName));
mt.set_function("getRelativeToWidgetName",static_cast<const std::string&(cocos2d::ui::RelativeLayoutParameter::*)()const>(&cocos2d::ui::RelativeLayoutParameter::getRelativeToWidgetName));
mt.set_function("setRelativeName",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(const std::string&)>(&cocos2d::ui::RelativeLayoutParameter::setRelativeName));
mt.set_function("getRelativeName",static_cast<const std::string&(cocos2d::ui::RelativeLayoutParameter::*)()const>(&cocos2d::ui::RelativeLayoutParameter::getRelativeName));
mt.set_function("createCloneInstance",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::RelativeLayoutParameter::*)()>(&cocos2d::ui::RelativeLayoutParameter::createCloneInstance));
mt.set_function("copyProperties",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::RelativeLayoutParameter::copyProperties));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RelativeLayoutParameter*(*)()>(&cocos2d::ui::RelativeLayoutParameter::create));
RegisterLuaUIRelativeLayoutParameterRelativeAlignAuto(lua);
}
void RegisterLuaUIWidgetFocusDirectionAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum("FocusDirection"
,"LEFT",0
,"RIGHT",1
,"UP",2
,"DOWN",3
);}
void RegisterLuaUIWidgetPositionTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum("PositionType"
,"ABSOLUTE",0
,"PERCENT",1
);}
void RegisterLuaUIWidgetSizeTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum("SizeType"
,"ABSOLUTE",0
,"PERCENT",1
);}
void RegisterLuaUIWidgetTouchEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum("TouchEventType"
,"BEGAN",0
,"MOVED",1
,"ENDED",2
,"CANCELED",3
);}
void RegisterLuaUIWidgetTextureResTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum("TextureResType"
,"LOCAL",0
,"PLIST",1
);}
void RegisterLuaUIWidgetBrightStyleAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum("BrightStyle"
,"NONE",-1
,"NORMAL",0
,"HIGHLIGHT",1
);}
void RegisterLuaUIWidgetAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("Widget",false);
ns["Widget"] = mt;
lua["Widget"] = sol::nil;
mt.set_function("setEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setEnabled));
mt.set_function("isEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isEnabled));
mt.set_function("setBright",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setBright));
mt.set_function("isBright",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isBright));
mt.set_function("setTouchEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setTouchEnabled));
mt.set_function("setBrightStyle",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::BrightStyle)>(&cocos2d::ui::Widget::setBrightStyle));
mt.set_function("isTouchEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isTouchEnabled));
mt.set_function("isHighlighted",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isHighlighted));
mt.set_function("setHighlighted",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setHighlighted));
mt.set_function("getLeftBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getLeftBoundary));
mt.set_function("getBottomBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getBottomBoundary));
mt.set_function("getRightBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getRightBoundary));
mt.set_function("getTopBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTopBoundary));
mt.set_function("visit",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::Widget::visit));
mt.set_function("addTouchEventListener",static_cast<void(cocos2d::ui::Widget::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::Widget::TouchEventType)>&)>(&cocos2d::ui::Widget::addTouchEventListener));
mt.set_function("addClickEventListener",static_cast<void(cocos2d::ui::Widget::*)(const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::ui::Widget::addClickEventListener));
mt.set_function("addCCSEventListener",static_cast<void(cocos2d::ui::Widget::*)(const std::function<void (cocos2d::Ref *, int)>&)>(&cocos2d::ui::Widget::addCCSEventListener));
mt.set_function("setPosition",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::setPosition));
mt.set_function("setPositionPercent",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::setPositionPercent));
mt.set_function("getPositionPercent",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getPositionPercent));
mt.set_function("setPositionType",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::PositionType)>(&cocos2d::ui::Widget::setPositionType));
mt.set_function("getPositionType",static_cast<cocos2d::ui::Widget::PositionType(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getPositionType));
mt.set_function("setFlippedX",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFlippedX));
mt.set_function("isFlippedX",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFlippedX));
mt.set_function("setFlippedY",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFlippedY));
mt.set_function("isFlippedY",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFlippedY));
mt.set_function("setScaleX",static_cast<void(cocos2d::ui::Widget::*)(float)>(&cocos2d::ui::Widget::setScaleX));
mt.set_function("setScaleY",static_cast<void(cocos2d::ui::Widget::*)(float)>(&cocos2d::ui::Widget::setScaleY));
mt.set_function("setScale",sol::overload(static_cast<void(cocos2d::ui::Widget::*)(float,float)>(&cocos2d::ui::Widget::setScale),static_cast<void(cocos2d::ui::Widget::*)(float)>(&cocos2d::ui::Widget::setScale)));
mt.set_function("getScaleX",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getScaleX));
mt.set_function("getScaleY",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getScaleY));
mt.set_function("getScale",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getScale));
mt.set_function("isClippingParentContainsPoint",static_cast<bool(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::isClippingParentContainsPoint));
mt.set_function("getTouchBeganPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTouchBeganPosition));
mt.set_function("getTouchMovePosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTouchMovePosition));
mt.set_function("getTouchEndPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTouchEndPosition));
mt.set_function("setContentSize",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Size&)>(&cocos2d::ui::Widget::setContentSize));
mt.set_function("setSizePercent",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::setSizePercent));
mt.set_function("setSizeType",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::SizeType)>(&cocos2d::ui::Widget::setSizeType));
mt.set_function("getSizeType",static_cast<cocos2d::ui::Widget::SizeType(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getSizeType));
mt.set_function("getCustomSize",static_cast<const cocos2d::Size&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getCustomSize));
mt.set_function("getLayoutSize",static_cast<const cocos2d::Size&(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getLayoutSize));
mt.set_function("getSizePercent",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getSizePercent));
mt.set_function("hitTest",static_cast<bool(cocos2d::ui::Widget::*)(const cocos2d::Vec2&,const cocos2d::Camera*,cocos2d::Vec3*)const>(&cocos2d::ui::Widget::hitTest));
mt.set_function("onTouchBegan",static_cast<bool(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchBegan));
mt.set_function("onTouchMoved",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchMoved));
mt.set_function("onTouchEnded",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchEnded));
mt.set_function("onTouchCancelled",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchCancelled));
mt.set_function("setLayoutParameter",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::Widget::setLayoutParameter));
mt.set_function("getLayoutParameter",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getLayoutParameter));
mt.set_function("ignoreContentAdaptWithSize",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::ignoreContentAdaptWithSize));
mt.set_function("isIgnoreContentAdaptWithSize",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isIgnoreContentAdaptWithSize));
mt.set_function("getWorldPosition",static_cast<cocos2d::Vec2(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getWorldPosition));
mt.set_function("getVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getVirtualRenderer));
mt.set_function("getVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getVirtualRendererSize));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getDescription));
mt.set_function("clone",static_cast<cocos2d::ui::Widget*(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::clone));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::onExit));
mt.set_function("updateSizeAndPosition",sol::overload(static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Size&)>(&cocos2d::ui::Widget::updateSizeAndPosition),static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::updateSizeAndPosition)));
mt.set_function("setActionTag",static_cast<void(cocos2d::ui::Widget::*)(int)>(&cocos2d::ui::Widget::setActionTag));
mt.set_function("getActionTag",static_cast<int(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getActionTag));
mt.set_function("setPropagateTouchEvents",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setPropagateTouchEvents));
mt.set_function("isPropagateTouchEvents",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isPropagateTouchEvents));
mt.set_function("setSwallowTouches",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setSwallowTouches));
mt.set_function("isSwallowTouches",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isSwallowTouches));
mt.set_function("isFocused",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFocused));
mt.set_function("setFocused",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFocused));
mt.set_function("isFocusEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFocusEnabled));
mt.set_function("setFocusEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFocusEnabled));
mt.set_function("findNextFocusedWidget",static_cast<cocos2d::ui::Widget*(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::FocusDirection,cocos2d::ui::Widget*)>(&cocos2d::ui::Widget::findNextFocusedWidget));
mt.set_function("requestFocus",static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::requestFocus));
mt.set_function("setUnifySizeEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setUnifySizeEnabled));
mt.set_function("isUnifySizeEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isUnifySizeEnabled));
mt.set_function("setCallbackName",static_cast<void(cocos2d::ui::Widget::*)(const std::string&)>(&cocos2d::ui::Widget::setCallbackName));
mt.set_function("getCallbackName",static_cast<const std::string&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getCallbackName));
mt.set_function("setCallbackType",static_cast<void(cocos2d::ui::Widget::*)(const std::string&)>(&cocos2d::ui::Widget::setCallbackType));
mt.set_function("getCallbackType",static_cast<const std::string&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getCallbackType));
mt.set_function("setLayoutComponentEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setLayoutComponentEnabled));
mt.set_function("isLayoutComponentEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isLayoutComponentEnabled));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::Widget*(*)()>(&cocos2d::ui::Widget::create));
mt.set_function("getCurrentFocusedWidget",static_cast<cocos2d::ui::Widget*(*)()>(&cocos2d::ui::Widget::getCurrentFocusedWidget));
mt.set_function("enableDpadNavigation",static_cast<void(*)(bool)>(&cocos2d::ui::Widget::enableDpadNavigation));
mt["onFocusChanged"] = &cocos2d::ui::Widget::onFocusChanged;
mt["onNextFocusedWidget"] = &cocos2d::ui::Widget::onNextFocusedWidget;
RegisterLuaUIWidgetFocusDirectionAuto(lua);
RegisterLuaUIWidgetPositionTypeAuto(lua);
RegisterLuaUIWidgetSizeTypeAuto(lua);
RegisterLuaUIWidgetTouchEventTypeAuto(lua);
RegisterLuaUIWidgetTextureResTypeAuto(lua);
RegisterLuaUIWidgetBrightStyleAuto(lua);
}
void RegisterLuaUILayoutTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Layout"];
pTable.new_enum("Type"
,"ABSOLUTE",0
,"VERTICAL",1
,"CENTER_VERTICAL",2
,"HORIZONTAL",3
,"RELATIVE",4
);}
void RegisterLuaUILayoutClippingTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Layout"];
pTable.new_enum("ClippingType"
,"STENCIL",0
,"SCISSOR",1
);}
void RegisterLuaUILayoutBackGroundColorTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Layout"];
pTable.new_enum("BackGroundColorType"
,"NONE",0
,"SOLID",1
,"GRADIENT",2
);}
void RegisterLuaUILayoutAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::Layout,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>("Layout",false);
ns["Layout"] = mt;
lua["Layout"] = sol::nil;
mt.set_function("setBackGroundImage",sol::overload([](cocos2d::ui::Layout* obj,const std::string& arg0){return obj->setBackGroundImage(arg0);},[](cocos2d::ui::Layout* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->setBackGroundImage(arg0,arg1);}));
mt.set_function("setBackGroundImageCapInsets",static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Rect&)>(&cocos2d::ui::Layout::setBackGroundImageCapInsets));
mt.set_function("getBackGroundImageCapInsets",static_cast<const cocos2d::Rect&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageCapInsets));
mt.set_function("setBackGroundColorType",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::ui::Layout::BackGroundColorType)>(&cocos2d::ui::Layout::setBackGroundColorType));
mt.set_function("getBackGroundColorType",static_cast<cocos2d::ui::Layout::BackGroundColorType(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColorType));
mt.set_function("setBackGroundImageScale9Enabled",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setBackGroundImageScale9Enabled));
mt.set_function("isBackGroundImageScale9Enabled",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isBackGroundImageScale9Enabled));
mt.set_function("setBackGroundColor",sol::overload(static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Color3B&,const cocos2d::Color3B&)>(&cocos2d::ui::Layout::setBackGroundColor),static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Color3B&)>(&cocos2d::ui::Layout::setBackGroundColor)));
mt.set_function("getBackGroundColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColor));
mt.set_function("getBackGroundStartColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundStartColor));
mt.set_function("getBackGroundEndColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundEndColor));
mt.set_function("setBackGroundColorOpacity",static_cast<void(cocos2d::ui::Layout::*)(uint8_t)>(&cocos2d::ui::Layout::setBackGroundColorOpacity));
mt.set_function("getBackGroundColorOpacity",static_cast<uint8_t(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColorOpacity));
mt.set_function("setBackGroundColorVector",static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Layout::setBackGroundColorVector));
mt.set_function("getBackGroundColorVector",static_cast<const cocos2d::Vec2&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColorVector));
mt.set_function("setBackGroundImageColor",static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Color3B&)>(&cocos2d::ui::Layout::setBackGroundImageColor));
mt.set_function("setBackGroundImageOpacity",static_cast<void(cocos2d::ui::Layout::*)(uint8_t)>(&cocos2d::ui::Layout::setBackGroundImageOpacity));
mt.set_function("getBackGroundImageColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageColor));
mt.set_function("getBackGroundImageOpacity",static_cast<uint8_t(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageOpacity));
mt.set_function("removeBackGroundImage",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::removeBackGroundImage));
mt.set_function("getBackGroundImageTextureSize",static_cast<const cocos2d::Size&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageTextureSize));
mt.set_function("setClippingEnabled",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setClippingEnabled));
mt.set_function("setClippingType",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::ui::Layout::ClippingType)>(&cocos2d::ui::Layout::setClippingType));
mt.set_function("getClippingType",static_cast<cocos2d::ui::Layout::ClippingType(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getClippingType));
mt.set_function("isClippingEnabled",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isClippingEnabled));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getDescription));
mt.set_function("setLayoutType",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::ui::Layout::Type)>(&cocos2d::ui::Layout::setLayoutType));
mt.set_function("getLayoutType",static_cast<cocos2d::ui::Layout::Type(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getLayoutType));
mt.set_function("addChild",sol::overload(static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*,int)>(&cocos2d::ui::Layout::addChild),static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*)>(&cocos2d::ui::Layout::addChild),static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*,int,int)>(&cocos2d::ui::Layout::addChild),static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ui::Layout::addChild)));
mt.set_function("visit",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::Layout::visit));
mt.set_function("removeChild",sol::overload([](cocos2d::ui::Layout* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::ui::Layout* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("removeAllChildren",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::removeAllChildren));
mt.set_function("removeAllChildrenWithCleanup",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::removeAllChildrenWithCleanup));
mt.set_function("forceDoLayout",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::forceDoLayout));
mt.set_function("requestDoLayout",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::requestDoLayout));
mt.set_function("onEnter",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::onEnter));
mt.set_function("onExit",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::onExit));
mt.set_function("setGlobalZOrder",static_cast<void(cocos2d::ui::Layout::*)(float)>(&cocos2d::ui::Layout::setGlobalZOrder));
mt.set_function("setLoopFocus",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setLoopFocus));
mt.set_function("isLoopFocus",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isLoopFocus));
mt.set_function("setPassFocusToChild",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setPassFocusToChild));
mt.set_function("isPassFocusToChild",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isPassFocusToChild));
mt.set_function("findNextFocusedWidget",static_cast<cocos2d::ui::Widget*(cocos2d::ui::Layout::*)(cocos2d::ui::Widget::FocusDirection,cocos2d::ui::Widget*)>(&cocos2d::ui::Layout::findNextFocusedWidget));
mt.set_function("setCameraMask",sol::overload([](cocos2d::ui::Layout* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ui::Layout* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("getRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::getRenderFile));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Layout::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::Layout*(*)()>(&cocos2d::ui::Layout::create));
mt["onPassFocusToChild"] = &cocos2d::ui::Layout::onPassFocusToChild;
RegisterLuaUILayoutTypeAuto(lua);
RegisterLuaUILayoutClippingTypeAuto(lua);
RegisterLuaUILayoutBackGroundColorTypeAuto(lua);
}
void RegisterLuaUIButtonAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::Button,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("Button",false);
ns["Button"] = mt;
lua["Button"] = sol::nil;
mt.set_function("loadTextures",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1){return obj->loadTextures(arg0,arg1);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->loadTextures(arg0,arg1,arg2);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->loadTextures(arg0,arg1,arg2,arg3);}));
mt.set_function("loadTextureNormal",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->loadTextureNormal(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureNormal(arg0,arg1);}));
mt.set_function("loadTexturePressed",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->loadTexturePressed(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTexturePressed(arg0,arg1);}));
mt.set_function("loadTextureDisabled",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->loadTextureDisabled(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureDisabled(arg0,arg1);}));
mt.set_function("setCapInsets",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsets));
mt.set_function("setCapInsetsNormalRenderer",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsetsNormalRenderer));
mt.set_function("getCapInsetsNormalRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getCapInsetsNormalRenderer));
mt.set_function("setCapInsetsPressedRenderer",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsetsPressedRenderer));
mt.set_function("getCapInsetsPressedRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getCapInsetsPressedRenderer));
mt.set_function("setCapInsetsDisabledRenderer",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsetsDisabledRenderer));
mt.set_function("getCapInsetsDisabledRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getCapInsetsDisabledRenderer));
mt.set_function("setScale9Enabled",static_cast<void(cocos2d::ui::Button::*)(bool)>(&cocos2d::ui::Button::setScale9Enabled));
mt.set_function("isScale9Enabled",static_cast<bool(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::isScale9Enabled));
mt.set_function("setPressedActionEnabled",static_cast<void(cocos2d::ui::Button::*)(bool)>(&cocos2d::ui::Button::setPressedActionEnabled));
mt.set_function("ignoreContentAdaptWithSize",static_cast<void(cocos2d::ui::Button::*)(bool)>(&cocos2d::ui::Button::ignoreContentAdaptWithSize));
mt.set_function("getVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getVirtualRendererSize));
mt.set_function("getVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getVirtualRenderer));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getDescription));
mt.set_function("getTitleRenderer",static_cast<cocos2d::Label*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleRenderer));
mt.set_function("setTitleText",static_cast<void(cocos2d::ui::Button::*)(const std::string&)>(&cocos2d::ui::Button::setTitleText));
mt.set_function("getTitleText",static_cast<std::string(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleText));
mt.set_function("setTitleColor",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Color3B&)>(&cocos2d::ui::Button::setTitleColor));
mt.set_function("getTitleColor",static_cast<cocos2d::Color3B(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleColor));
mt.set_function("setTitleFontSize",static_cast<void(cocos2d::ui::Button::*)(float)>(&cocos2d::ui::Button::setTitleFontSize));
mt.set_function("getTitleFontSize",static_cast<float(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleFontSize));
mt.set_function("setTitleFontName",static_cast<void(cocos2d::ui::Button::*)(const std::string&)>(&cocos2d::ui::Button::setTitleFontName));
mt.set_function("getTitleFontName",static_cast<std::string(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleFontName));
mt.set_function("setTitleAlignment",sol::overload(static_cast<void(cocos2d::ui::Button::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::ui::Button::setTitleAlignment),static_cast<void(cocos2d::ui::Button::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::Button::setTitleAlignment)));
mt.set_function("setTitleLabel",static_cast<void(cocos2d::ui::Button::*)(cocos2d::Label*)>(&cocos2d::ui::Button::setTitleLabel));
mt.set_function("getTitleLabel",static_cast<cocos2d::Label*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleLabel));
mt.set_function("setZoomScale",static_cast<void(cocos2d::ui::Button::*)(float)>(&cocos2d::ui::Button::setZoomScale));
mt.set_function("getZoomScale",static_cast<float(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getZoomScale));
mt.set_function("getRendererNormal",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getRendererNormal));
mt.set_function("getRendererClicked",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getRendererClicked));
mt.set_function("getRendererDisabled",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getRendererDisabled));
mt.set_function("resetNormalRender",static_cast<void(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::resetNormalRender));
mt.set_function("resetPressedRender",static_cast<void(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::resetPressedRender));
mt.set_function("resetDisabledRender",static_cast<void(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::resetDisabledRender));
mt.set_function("getNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getNormalFile));
mt.set_function("getPressedFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getPressedFile));
mt.set_function("getDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getDisabledFile));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Button::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->create(arg0,arg1,arg2,arg3);},static_cast<cocos2d::ui::Button*(*)()>(&cocos2d::ui::Button::create)));
}
void RegisterLuaUIAbstractCheckButtonAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("AbstractCheckButton",true);
ns["AbstractCheckButton"] = mt;
lua["AbstractCheckButton"] = sol::nil;
mt.set_function("loadTextures",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4){return obj->loadTextures(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->loadTextures(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("loadTextureBackGround",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureBackGround(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureBackGround(arg0,arg1);}));
mt.set_function("loadTextureBackGroundSelected",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureBackGroundSelected(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureBackGroundSelected(arg0,arg1);}));
mt.set_function("loadTextureFrontCross",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureFrontCross(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureFrontCross(arg0,arg1);}));
mt.set_function("loadTextureBackGroundDisabled",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureBackGroundDisabled(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureBackGroundDisabled(arg0,arg1);}));
mt.set_function("loadTextureFrontCrossDisabled",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureFrontCrossDisabled(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureFrontCrossDisabled(arg0,arg1);}));
mt.set_function("isSelected",static_cast<bool(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::isSelected));
mt.set_function("setSelected",static_cast<void(cocos2d::ui::AbstractCheckButton::*)(bool)>(&cocos2d::ui::AbstractCheckButton::setSelected));
mt.set_function("getVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getVirtualRendererSize));
mt.set_function("getVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getVirtualRenderer));
mt.set_function("setZoomScale",static_cast<void(cocos2d::ui::AbstractCheckButton::*)(float)>(&cocos2d::ui::AbstractCheckButton::setZoomScale));
mt.set_function("getZoomScale",static_cast<float(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getZoomScale));
mt.set_function("getRendererBackground",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererBackground));
mt.set_function("getRendererBackgroundSelected",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererBackgroundSelected));
mt.set_function("getRendererFrontCross",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererFrontCross));
mt.set_function("getRendererBackgroundDisabled",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererBackgroundDisabled));
mt.set_function("getRendererFrontCrossDisabled",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererFrontCrossDisabled));
mt.set_function("getBackNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getBackNormalFile));
mt.set_function("getBackPressedFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getBackPressedFile));
mt.set_function("getBackDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getBackDisabledFile));
mt.set_function("getCrossNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getCrossNormalFile));
mt.set_function("getCrossDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getCrossDisabledFile));
}
void RegisterLuaUICheckBoxEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["CheckBox"];
pTable.new_enum("EventType"
,"SELECTED",0
,"UNSELECTED",1
);}
void RegisterLuaUICheckBoxAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::CheckBox,cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("CheckBox",false);
ns["CheckBox"] = mt;
lua["CheckBox"] = sol::nil;
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::CheckBox::*)(const std::function<void (cocos2d::Ref *, cocos2d::ui::CheckBox::EventType)>&)>(&cocos2d::ui::CheckBox::addEventListener));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::CheckBox::*)()const>(&cocos2d::ui::CheckBox::getDescription));
mt.set_function("onTouchEnded",static_cast<void(cocos2d::ui::CheckBox::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::CheckBox::onTouchEnded));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::CheckBox::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},static_cast<cocos2d::ui::CheckBox*(*)()>(&cocos2d::ui::CheckBox::create),[](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->create(arg0,arg1,arg2);}));
RegisterLuaUICheckBoxEventTypeAuto(lua);
}
void RegisterLuaUIRadioButtonEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RadioButton"];
pTable.new_enum("EventType"
,"SELECTED",0
,"UNSELECTED",1
);}
void RegisterLuaUIRadioButtonAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RadioButton,cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("RadioButton",false);
ns["RadioButton"] = mt;
lua["RadioButton"] = sol::nil;
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::RadioButton::*)(const std::function<void (cocos2d::ui::RadioButton *, cocos2d::ui::RadioButton::EventType)>&)>(&cocos2d::ui::RadioButton::addEventListener));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::RadioButton::*)()const>(&cocos2d::ui::RadioButton::getDescription));
mt.set_function("createInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::RadioButton::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},static_cast<cocos2d::ui::RadioButton*(*)()>(&cocos2d::ui::RadioButton::create),[](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->create(arg0,arg1,arg2);}));
RegisterLuaUIRadioButtonEventTypeAuto(lua);
}
void RegisterLuaUIRadioButtonGroupEventTypeAuto(cocos2d::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RadioButtonGroup"];
pTable.new_enum("EventType"
,"SELECT_CHANGED",0
);}
void RegisterLuaUIRadioButtonGroupAuto(cocos2d::Lua& lua){
sol::table ns = lua["ccui"];
auto mt=lua.NewUserType<cocos2d::ui::RadioButtonGroup,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::LuaObject,cocos2d::ui::LayoutParameterProtocol>("RadioButtonGroup",false);
ns["RadioButtonGroup"] = mt;
lua["RadioButtonGroup"] = sol::nil;
mt.set_function("addEventListener",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(const std::function<void (cocos2d::ui::RadioButton *, int, cocos2d::ui::RadioButtonGroup::EventType)>&)>(&cocos2d::ui::RadioButtonGroup::addEventListener));
mt.set_function("getSelectedButtonIndex",static_cast<int(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::getSelectedButtonIndex));
mt.set_function("setSelectedButton",sol::overload(static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::setSelectedButton),static_cast<void(cocos2d::ui::RadioButtonGroup::*)(int)>(&cocos2d::ui::RadioButtonGroup::setSelectedButton)));
mt.set_function("setSelectedButtonWithoutEvent",sol::overload(static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::setSelectedButtonWithoutEvent),static_cast<void(cocos2d::ui::RadioButtonGroup::*)(int)>(&cocos2d::ui::RadioButtonGroup::setSelectedButtonWithoutEvent)));
mt.set_function("addRadioButton",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::addRadioButton));
mt.set_function("removeRadioButton",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::removeRadioButton));
mt.set_function("removeAllRadioButtons",static_cast<void(cocos2d::ui::RadioButtonGroup::*)()>(&cocos2d::ui::RadioButtonGroup::removeAllRadioButtons));
mt.set_function("getNumberOfRadioButtons",static_cast<ssize_t(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::getNumberOfRadioButtons));
mt.set_function("getRadioButtonByIndex",static_cast<cocos2d::ui::RadioButton*(cocos2d::ui::RadioButtonGroup::*)(int)const>(&cocos2d::ui::RadioButtonGroup::getRadioButtonByIndex));
mt.set_function("setAllowedNoSelection",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(bool)>(&cocos2d::ui::RadioButtonGroup::setAllowedNoSelection));
mt.set_function("isAllowedNoSelection",static_cast<bool(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::isAllowedNoSelection));
mt.set_function("getDescription",static_cast<std::string(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::getDescription));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RadioButtonGroup*(*)()>(&cocos2d::ui::RadioButtonGroup::create));
RegisterLuaUIRadioButtonGroupEventTypeAuto(lua);
}
