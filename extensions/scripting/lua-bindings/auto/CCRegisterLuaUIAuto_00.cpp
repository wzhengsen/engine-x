#include "scripting/lua-bindings/auto/CCRegisterLuaUIAuto.hpp"
#include "ui/CocosGUI.h"
void RegisterLuaUILayoutParameterTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LayoutParameter"];
pTable.new_enum<cocos2d::ui::LayoutParameter::Type>("Type",{
{"NONE",cocos2d::ui::LayoutParameter::Type::NONE}
,{"LINEAR",cocos2d::ui::LayoutParameter::Type::LINEAR}
,{"RELATIVE",cocos2d::ui::LayoutParameter::Type::RELATIVE}
});}
void RegisterLuaUILayoutParameterAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::LayoutParameter>("ccui","LayoutParameter",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::LayoutParameter*(*)()>(&cocos2d::ui::LayoutParameter::create));
mt.set_function("SetMargin",static_cast<void(cocos2d::ui::LayoutParameter::*)(const cocos2d::ui::Margin&)>(&cocos2d::ui::LayoutParameter::setMargin));
mt.set_function("GetMargin",static_cast<const cocos2d::ui::Margin&(cocos2d::ui::LayoutParameter::*)()const>(&cocos2d::ui::LayoutParameter::getMargin));
mt.set_function("GetLayoutType",static_cast<cocos2d::ui::LayoutParameter::Type(cocos2d::ui::LayoutParameter::*)()const>(&cocos2d::ui::LayoutParameter::getLayoutType));
mt.set_function("Clone",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::LayoutParameter::*)()>(&cocos2d::ui::LayoutParameter::clone));
mt.set_function("CreateCloneInstance",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::LayoutParameter::*)()>(&cocos2d::ui::LayoutParameter::createCloneInstance));
mt.set_function("CopyProperties",static_cast<void(cocos2d::ui::LayoutParameter::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::LayoutParameter::copyProperties));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::LayoutParameter()>();
RegisterLuaUILayoutParameterTypeAuto(lua);
}
void RegisterLuaUILinearLayoutParameterLinearGravityAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["LinearLayoutParameter"];
pTable.new_enum<cocos2d::ui::LinearLayoutParameter::LinearGravity>("LinearGravity",{
{"NONE",cocos2d::ui::LinearLayoutParameter::LinearGravity::NONE}
,{"LEFT",cocos2d::ui::LinearLayoutParameter::LinearGravity::LEFT}
,{"TOP",cocos2d::ui::LinearLayoutParameter::LinearGravity::TOP}
,{"RIGHT",cocos2d::ui::LinearLayoutParameter::LinearGravity::RIGHT}
,{"BOTTOM",cocos2d::ui::LinearLayoutParameter::LinearGravity::BOTTOM}
,{"CENTER_VERTICAL",cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_VERTICAL}
,{"CENTER_HORIZONTAL",cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL}
});}
void RegisterLuaUILinearLayoutParameterAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::LinearLayoutParameter>("ccui","LinearLayoutParameter",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::LayoutParameter,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::LinearLayoutParameter*(*)()>(&cocos2d::ui::LinearLayoutParameter::create));
mt.set_function("SetGravity",static_cast<void(cocos2d::ui::LinearLayoutParameter::*)(cocos2d::ui::LinearLayoutParameter::LinearGravity)>(&cocos2d::ui::LinearLayoutParameter::setGravity));
mt.set_function("GetGravity",static_cast<cocos2d::ui::LinearLayoutParameter::LinearGravity(cocos2d::ui::LinearLayoutParameter::*)()const>(&cocos2d::ui::LinearLayoutParameter::getGravity));
mt.set_function("CreateCloneInstance",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::LinearLayoutParameter::*)()>(&cocos2d::ui::LinearLayoutParameter::createCloneInstance));
mt.set_function("CopyProperties",static_cast<void(cocos2d::ui::LinearLayoutParameter::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::LinearLayoutParameter::copyProperties));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::LinearLayoutParameter()>();
RegisterLuaUILinearLayoutParameterLinearGravityAuto(lua);
}
void RegisterLuaUIRelativeLayoutParameterRelativeAlignAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RelativeLayoutParameter"];
pTable.new_enum<cocos2d::ui::RelativeLayoutParameter::RelativeAlign>("RelativeAlign",{
{"NONE",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::NONE}
,{"PARENT_TOP_LEFT",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_LEFT}
,{"PARENT_TOP_CENTER_HORIZONTAL",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_CENTER_HORIZONTAL}
,{"PARENT_TOP_RIGHT",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_TOP_RIGHT}
,{"PARENT_LEFT_CENTER_VERTICAL",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL}
,{"CENTER_IN_PARENT",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT}
,{"PARENT_RIGHT_CENTER_VERTICAL",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL}
,{"PARENT_LEFT_BOTTOM",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_BOTTOM}
,{"PARENT_BOTTOM_CENTER_HORIZONTAL",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_BOTTOM_CENTER_HORIZONTAL}
,{"PARENT_RIGHT_BOTTOM",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_BOTTOM}
,{"LOCATION_ABOVE_LEFTALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_LEFTALIGN}
,{"LOCATION_ABOVE_CENTER",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_CENTER}
,{"LOCATION_ABOVE_RIGHTALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_ABOVE_RIGHTALIGN}
,{"LOCATION_LEFT_OF_TOPALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_TOPALIGN}
,{"LOCATION_LEFT_OF_CENTER",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_CENTER}
,{"LOCATION_LEFT_OF_BOTTOMALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_LEFT_OF_BOTTOMALIGN}
,{"LOCATION_RIGHT_OF_TOPALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_TOPALIGN}
,{"LOCATION_RIGHT_OF_CENTER",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_CENTER}
,{"LOCATION_RIGHT_OF_BOTTOMALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_RIGHT_OF_BOTTOMALIGN}
,{"LOCATION_BELOW_LEFTALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_LEFTALIGN}
,{"LOCATION_BELOW_CENTER",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_CENTER}
,{"LOCATION_BELOW_RIGHTALIGN",cocos2d::ui::RelativeLayoutParameter::RelativeAlign::LOCATION_BELOW_RIGHTALIGN}
});}
void RegisterLuaUIRelativeLayoutParameterAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RelativeLayoutParameter>("ccui","RelativeLayoutParameter",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::LayoutParameter,cocos2d::Ref,cocos2d::extension::LuaObject>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RelativeLayoutParameter*(*)()>(&cocos2d::ui::RelativeLayoutParameter::create));
mt.set_function("SetAlign",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(cocos2d::ui::RelativeLayoutParameter::RelativeAlign)>(&cocos2d::ui::RelativeLayoutParameter::setAlign));
mt.set_function("GetAlign",static_cast<cocos2d::ui::RelativeLayoutParameter::RelativeAlign(cocos2d::ui::RelativeLayoutParameter::*)()const>(&cocos2d::ui::RelativeLayoutParameter::getAlign));
mt.set_function("SetRelativeToWidgetName",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(const std::string&)>(&cocos2d::ui::RelativeLayoutParameter::setRelativeToWidgetName));
mt.set_function("GetRelativeToWidgetName",static_cast<const std::string&(cocos2d::ui::RelativeLayoutParameter::*)()const>(&cocos2d::ui::RelativeLayoutParameter::getRelativeToWidgetName));
mt.set_function("SetRelativeName",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(const std::string&)>(&cocos2d::ui::RelativeLayoutParameter::setRelativeName));
mt.set_function("GetRelativeName",static_cast<const std::string&(cocos2d::ui::RelativeLayoutParameter::*)()const>(&cocos2d::ui::RelativeLayoutParameter::getRelativeName));
mt.set_function("CreateCloneInstance",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::RelativeLayoutParameter::*)()>(&cocos2d::ui::RelativeLayoutParameter::createCloneInstance));
mt.set_function("CopyProperties",static_cast<void(cocos2d::ui::RelativeLayoutParameter::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::RelativeLayoutParameter::copyProperties));
mt[sol::call_constructor]=sol::constructors<cocos2d::ui::RelativeLayoutParameter()>();
RegisterLuaUIRelativeLayoutParameterRelativeAlignAuto(lua);
}
void RegisterLuaUIWidgetFocusDirectionAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum<cocos2d::ui::Widget::FocusDirection>("FocusDirection",{
{"LEFT",cocos2d::ui::Widget::FocusDirection::LEFT}
,{"RIGHT",cocos2d::ui::Widget::FocusDirection::RIGHT}
,{"UP",cocos2d::ui::Widget::FocusDirection::UP}
,{"DOWN",cocos2d::ui::Widget::FocusDirection::DOWN}
});}
void RegisterLuaUIWidgetPositionTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum<cocos2d::ui::Widget::PositionType>("PositionType",{
{"ABSOLUTE",cocos2d::ui::Widget::PositionType::ABSOLUTE}
,{"PERCENT",cocos2d::ui::Widget::PositionType::PERCENT}
});}
void RegisterLuaUIWidgetSizeTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum<cocos2d::ui::Widget::SizeType>("SizeType",{
{"ABSOLUTE",cocos2d::ui::Widget::SizeType::ABSOLUTE}
,{"PERCENT",cocos2d::ui::Widget::SizeType::PERCENT}
});}
void RegisterLuaUIWidgetTouchEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum<cocos2d::ui::Widget::TouchEventType>("TouchEventType",{
{"BEGAN",cocos2d::ui::Widget::TouchEventType::BEGAN}
,{"MOVED",cocos2d::ui::Widget::TouchEventType::MOVED}
,{"ENDED",cocos2d::ui::Widget::TouchEventType::ENDED}
,{"CANCELED",cocos2d::ui::Widget::TouchEventType::CANCELED}
});}
void RegisterLuaUIWidgetTextureResTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum<cocos2d::ui::Widget::TextureResType>("TextureResType",{
{"LOCAL",cocos2d::ui::Widget::TextureResType::LOCAL}
,{"PLIST",cocos2d::ui::Widget::TextureResType::PLIST}
});}
void RegisterLuaUIWidgetBrightStyleAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Widget"];
pTable.new_enum<cocos2d::ui::Widget::BrightStyle>("BrightStyle",{
{"NONE",cocos2d::ui::Widget::BrightStyle::NONE}
,{"NORMAL",cocos2d::ui::Widget::BrightStyle::NORMAL}
,{"HIGHLIGHT",cocos2d::ui::Widget::BrightStyle::HIGHLIGHT}
});}
void RegisterLuaUIWidgetAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Widget>("ccui","Widget",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::Widget*(*)()>(&cocos2d::ui::Widget::create));
mt.set_function("SetEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setEnabled));
mt.set_function("IsEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isEnabled));
mt.set_function("SetBright",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setBright));
mt.set_function("IsBright",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isBright));
mt.set_function("SetTouchEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setTouchEnabled));
mt.set_function("SetBrightStyle",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::BrightStyle)>(&cocos2d::ui::Widget::setBrightStyle));
mt.set_function("IsTouchEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isTouchEnabled));
mt.set_function("IsHighlighted",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isHighlighted));
mt.set_function("SetHighlighted",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setHighlighted));
mt.set_function("GetLeftBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getLeftBoundary));
mt.set_function("GetBottomBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getBottomBoundary));
mt.set_function("GetRightBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getRightBoundary));
mt.set_function("GetTopBoundary",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTopBoundary));
mt.set_function("Visit",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::Widget::visit));
mt.set_function("AddTouchEventListener",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::ui::Widget::ccWidgetTouchCallback&)>(&cocos2d::ui::Widget::addTouchEventListener));
mt.set_function("AddClickEventListener",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::ui::Widget::ccWidgetClickCallback&)>(&cocos2d::ui::Widget::addClickEventListener));
mt.set_function("AddCCSEventListener",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::ui::Widget::ccWidgetEventCallback&)>(&cocos2d::ui::Widget::addCCSEventListener));
mt.set_function("SetPosition",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::setPosition));
mt.set_function("SetPositionPercent",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::setPositionPercent));
mt.set_function("GetPositionPercent",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getPositionPercent));
mt.set_function("SetPositionType",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::PositionType)>(&cocos2d::ui::Widget::setPositionType));
mt.set_function("GetPositionType",static_cast<cocos2d::ui::Widget::PositionType(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getPositionType));
mt.set_function("SetFlippedX",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFlippedX));
mt.set_function("IsFlippedX",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFlippedX));
mt.set_function("SetFlippedY",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFlippedY));
mt.set_function("IsFlippedY",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFlippedY));
mt.set_function("SetScaleX",static_cast<void(cocos2d::ui::Widget::*)(float)>(&cocos2d::ui::Widget::setScaleX));
mt.set_function("SetScaleY",static_cast<void(cocos2d::ui::Widget::*)(float)>(&cocos2d::ui::Widget::setScaleY));
mt.set_function("SetScale",sol::overload(static_cast<void(cocos2d::ui::Widget::*)(float,float)>(&cocos2d::ui::Widget::setScale),static_cast<void(cocos2d::ui::Widget::*)(float)>(&cocos2d::ui::Widget::setScale)));
mt.set_function("GetScaleX",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getScaleX));
mt.set_function("GetScaleY",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getScaleY));
mt.set_function("GetScale",static_cast<float(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getScale));
mt.set_function("IsClippingParentContainsPoint",static_cast<bool(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::isClippingParentContainsPoint));
mt.set_function("GetTouchBeganPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTouchBeganPosition));
mt.set_function("GetTouchMovePosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTouchMovePosition));
mt.set_function("GetTouchEndPosition",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getTouchEndPosition));
mt.set_function("SetContentSize",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Size&)>(&cocos2d::ui::Widget::setContentSize));
mt.set_function("SetSizePercent",static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Widget::setSizePercent));
mt.set_function("SetSizeType",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::SizeType)>(&cocos2d::ui::Widget::setSizeType));
mt.set_function("GetSizeType",static_cast<cocos2d::ui::Widget::SizeType(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getSizeType));
mt.set_function("GetCustomSize",static_cast<const cocos2d::Size&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getCustomSize));
mt.set_function("GetLayoutSize",static_cast<const cocos2d::Size&(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getLayoutSize));
mt.set_function("GetSizePercent",static_cast<const cocos2d::Vec2&(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getSizePercent));
mt.set_function("HitTest",static_cast<bool(cocos2d::ui::Widget::*)(const cocos2d::Vec2&,const cocos2d::Camera*,cocos2d::Vec3*)const>(&cocos2d::ui::Widget::hitTest));
mt.set_function("OnTouchBegan",static_cast<bool(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchBegan));
mt.set_function("OnTouchMoved",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchMoved));
mt.set_function("OnTouchEnded",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchEnded));
mt.set_function("OnTouchCancelled",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::Widget::onTouchCancelled));
mt.set_function("SetLayoutParameter",static_cast<void(cocos2d::ui::Widget::*)(cocos2d::ui::LayoutParameter*)>(&cocos2d::ui::Widget::setLayoutParameter));
mt.set_function("GetLayoutParameter",static_cast<cocos2d::ui::LayoutParameter*(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getLayoutParameter));
mt.set_function("IgnoreContentAdaptWithSize",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::ignoreContentAdaptWithSize));
mt.set_function("IsIgnoreContentAdaptWithSize",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isIgnoreContentAdaptWithSize));
mt.set_function("GetWorldPosition",static_cast<cocos2d::Vec2(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getWorldPosition));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::getVirtualRenderer));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getVirtualRendererSize));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getDescription));
mt.set_function("Clone",static_cast<cocos2d::ui::Widget*(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::clone));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::onExit));
mt.set_function("UpdateSizeAndPosition",sol::overload(static_cast<void(cocos2d::ui::Widget::*)(const cocos2d::Size&)>(&cocos2d::ui::Widget::updateSizeAndPosition),static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::updateSizeAndPosition)));
mt.set_function("SetActionTag",static_cast<void(cocos2d::ui::Widget::*)(int)>(&cocos2d::ui::Widget::setActionTag));
mt.set_function("GetActionTag",static_cast<int(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getActionTag));
mt.set_function("SetPropagateTouchEvents",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setPropagateTouchEvents));
mt.set_function("IsPropagateTouchEvents",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isPropagateTouchEvents));
mt.set_function("SetSwallowTouches",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setSwallowTouches));
mt.set_function("IsSwallowTouches",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isSwallowTouches));
mt.set_function("IsFocused",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFocused));
mt.set_function("SetFocused",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFocused));
mt.set_function("IsFocusEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isFocusEnabled));
mt.set_function("SetFocusEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setFocusEnabled));
mt.set_function("FindNextFocusedWidget",static_cast<cocos2d::ui::Widget*(cocos2d::ui::Widget::*)(cocos2d::ui::Widget::FocusDirection,cocos2d::ui::Widget*)>(&cocos2d::ui::Widget::findNextFocusedWidget));
mt.set_function("RequestFocus",static_cast<void(cocos2d::ui::Widget::*)()>(&cocos2d::ui::Widget::requestFocus));
mt.set_function("GetCurrentFocusedWidget",static_cast<cocos2d::ui::Widget*(*)()>(&cocos2d::ui::Widget::getCurrentFocusedWidget));
mt.set_function("EnableDpadNavigation",static_cast<void(*)(bool)>(&cocos2d::ui::Widget::enableDpadNavigation));
mt.set_function("SetUnifySizeEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setUnifySizeEnabled));
mt.set_function("IsUnifySizeEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isUnifySizeEnabled));
mt.set_function("SetCallbackName",static_cast<void(cocos2d::ui::Widget::*)(const std::string&)>(&cocos2d::ui::Widget::setCallbackName));
mt.set_function("GetCallbackName",static_cast<const std::string&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getCallbackName));
mt.set_function("SetCallbackType",static_cast<void(cocos2d::ui::Widget::*)(const std::string&)>(&cocos2d::ui::Widget::setCallbackType));
mt.set_function("GetCallbackType",static_cast<const std::string&(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::getCallbackType));
mt.set_function("SetLayoutComponentEnabled",static_cast<void(cocos2d::ui::Widget::*)(bool)>(&cocos2d::ui::Widget::setLayoutComponentEnabled));
mt.set_function("IsLayoutComponentEnabled",static_cast<bool(cocos2d::ui::Widget::*)()const>(&cocos2d::ui::Widget::isLayoutComponentEnabled));
mt["OnFocusChanged"]=&cocos2d::ui::Widget::onFocusChanged;
mt["OnNextFocusedWidget"]=&cocos2d::ui::Widget::onNextFocusedWidget;
RegisterLuaUIWidgetFocusDirectionAuto(lua);
RegisterLuaUIWidgetPositionTypeAuto(lua);
RegisterLuaUIWidgetSizeTypeAuto(lua);
RegisterLuaUIWidgetTouchEventTypeAuto(lua);
RegisterLuaUIWidgetTextureResTypeAuto(lua);
RegisterLuaUIWidgetBrightStyleAuto(lua);
}
void RegisterLuaUILayoutTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Layout"];
pTable.new_enum<cocos2d::ui::Layout::Type>("Type",{
{"ABSOLUTE",cocos2d::ui::Layout::Type::ABSOLUTE}
,{"VERTICAL",cocos2d::ui::Layout::Type::VERTICAL}
,{"CENTER_VERTICAL",cocos2d::ui::Layout::Type::CENTER_VERTICAL}
,{"HORIZONTAL",cocos2d::ui::Layout::Type::HORIZONTAL}
,{"RELATIVE",cocos2d::ui::Layout::Type::RELATIVE}
});}
void RegisterLuaUILayoutClippingTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Layout"];
pTable.new_enum<cocos2d::ui::Layout::ClippingType>("ClippingType",{
{"STENCIL",cocos2d::ui::Layout::ClippingType::STENCIL}
,{"SCISSOR",cocos2d::ui::Layout::ClippingType::SCISSOR}
});}
void RegisterLuaUILayoutBackGroundColorTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["Layout"];
pTable.new_enum<cocos2d::ui::Layout::BackGroundColorType>("BackGroundColorType",{
{"NONE",cocos2d::ui::Layout::BackGroundColorType::NONE}
,{"SOLID",cocos2d::ui::Layout::BackGroundColorType::SOLID}
,{"GRADIENT",cocos2d::ui::Layout::BackGroundColorType::GRADIENT}
});}
void RegisterLuaUILayoutAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Layout>("ccui","Layout",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol,cocos2d::ui::LayoutProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Layout::createInstance));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::Layout*(*)()>(&cocos2d::ui::Layout::create));
mt.set_function("SetBackGroundImage",sol::overload([](cocos2d::ui::Layout* obj,const std::string& arg0){return obj->setBackGroundImage(arg0);},[](cocos2d::ui::Layout* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->setBackGroundImage(arg0,arg1);}));
mt.set_function("SetBackGroundImageCapInsets",static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Rect&)>(&cocos2d::ui::Layout::setBackGroundImageCapInsets));
mt.set_function("GetBackGroundImageCapInsets",static_cast<const cocos2d::Rect&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageCapInsets));
mt.set_function("SetBackGroundColorType",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::ui::Layout::BackGroundColorType)>(&cocos2d::ui::Layout::setBackGroundColorType));
mt.set_function("GetBackGroundColorType",static_cast<cocos2d::ui::Layout::BackGroundColorType(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColorType));
mt.set_function("SetBackGroundImageScale9Enabled",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setBackGroundImageScale9Enabled));
mt.set_function("IsBackGroundImageScale9Enabled",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isBackGroundImageScale9Enabled));
mt.set_function("SetBackGroundColor",sol::overload(static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Color3B&,const cocos2d::Color3B&)>(&cocos2d::ui::Layout::setBackGroundColor),static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Color3B&)>(&cocos2d::ui::Layout::setBackGroundColor)));
mt.set_function("GetBackGroundColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColor));
mt.set_function("GetBackGroundStartColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundStartColor));
mt.set_function("GetBackGroundEndColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundEndColor));
mt.set_function("SetBackGroundColorOpacity",static_cast<void(cocos2d::ui::Layout::*)(uint8_t)>(&cocos2d::ui::Layout::setBackGroundColorOpacity));
mt.set_function("GetBackGroundColorOpacity",static_cast<uint8_t(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColorOpacity));
mt.set_function("SetBackGroundColorVector",static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Vec2&)>(&cocos2d::ui::Layout::setBackGroundColorVector));
mt.set_function("GetBackGroundColorVector",static_cast<const cocos2d::Vec2&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundColorVector));
mt.set_function("SetBackGroundImageColor",static_cast<void(cocos2d::ui::Layout::*)(const cocos2d::Color3B&)>(&cocos2d::ui::Layout::setBackGroundImageColor));
mt.set_function("SetBackGroundImageOpacity",static_cast<void(cocos2d::ui::Layout::*)(uint8_t)>(&cocos2d::ui::Layout::setBackGroundImageOpacity));
mt.set_function("GetBackGroundImageColor",static_cast<const cocos2d::Color3B&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageColor));
mt.set_function("GetBackGroundImageOpacity",static_cast<uint8_t(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageOpacity));
mt.set_function("RemoveBackGroundImage",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::removeBackGroundImage));
mt.set_function("GetBackGroundImageTextureSize",static_cast<const cocos2d::Size&(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getBackGroundImageTextureSize));
mt.set_function("SetClippingEnabled",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setClippingEnabled));
mt.set_function("SetClippingType",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::ui::Layout::ClippingType)>(&cocos2d::ui::Layout::setClippingType));
mt.set_function("GetClippingType",static_cast<cocos2d::ui::Layout::ClippingType(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getClippingType));
mt.set_function("IsClippingEnabled",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isClippingEnabled));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getDescription));
mt.set_function("SetLayoutType",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::ui::Layout::Type)>(&cocos2d::ui::Layout::setLayoutType));
mt.set_function("GetLayoutType",static_cast<cocos2d::ui::Layout::Type(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::getLayoutType));
mt.set_function("AddChild",sol::overload(static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*,int)>(&cocos2d::ui::Layout::addChild),static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*)>(&cocos2d::ui::Layout::addChild),static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*,int,int)>(&cocos2d::ui::Layout::addChild),static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Node*,int,const std::string&)>(&cocos2d::ui::Layout::addChild)));
mt.set_function("Visit",static_cast<void(cocos2d::ui::Layout::*)(cocos2d::Renderer*,const cocos2d::Mat4&,uint32_t)>(&cocos2d::ui::Layout::visit));
mt.set_function("RemoveChild",sol::overload([](cocos2d::ui::Layout* obj,cocos2d::Node* arg0){return obj->removeChild(arg0);},[](cocos2d::ui::Layout* obj,cocos2d::Node* arg0,bool arg1){return obj->removeChild(arg0,arg1);}));
mt.set_function("RemoveAllChildren",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::removeAllChildren));
mt.set_function("RemoveAllChildrenWithCleanup",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::removeAllChildrenWithCleanup));
mt.set_function("ForceDoLayout",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::forceDoLayout));
mt.set_function("RequestDoLayout",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::requestDoLayout));
mt.set_function("OnEnter",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::onEnter));
mt.set_function("OnExit",static_cast<void(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::onExit));
mt.set_function("SetGlobalZOrder",static_cast<void(cocos2d::ui::Layout::*)(float)>(&cocos2d::ui::Layout::setGlobalZOrder));
mt.set_function("SetLoopFocus",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setLoopFocus));
mt.set_function("IsLoopFocus",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isLoopFocus));
mt.set_function("SetPassFocusToChild",static_cast<void(cocos2d::ui::Layout::*)(bool)>(&cocos2d::ui::Layout::setPassFocusToChild));
mt.set_function("IsPassFocusToChild",static_cast<bool(cocos2d::ui::Layout::*)()const>(&cocos2d::ui::Layout::isPassFocusToChild));
mt.set_function("FindNextFocusedWidget",static_cast<cocos2d::ui::Widget*(cocos2d::ui::Layout::*)(cocos2d::ui::Widget::FocusDirection,cocos2d::ui::Widget*)>(&cocos2d::ui::Layout::findNextFocusedWidget));
mt.set_function("SetCameraMask",sol::overload([](cocos2d::ui::Layout* obj,unsigned short arg0){return obj->setCameraMask(arg0);},[](cocos2d::ui::Layout* obj,unsigned short arg0,bool arg1){return obj->setCameraMask(arg0,arg1);}));
mt.set_function("GetRenderFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Layout::*)()>(&cocos2d::ui::Layout::getRenderFile));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::Layout::__Type));
mt["OnPassFocusToChild"]=&cocos2d::ui::Layout::onPassFocusToChild;
RegisterLuaUILayoutTypeAuto(lua);
RegisterLuaUILayoutClippingTypeAuto(lua);
RegisterLuaUILayoutBackGroundColorTypeAuto(lua);
}
void RegisterLuaUIButtonAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::Button>("ccui","Button",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::Button::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->create(arg0,arg1,arg2);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->create(arg0,arg1,arg2,arg3);},static_cast<cocos2d::ui::Button*(*)()>(&cocos2d::ui::Button::create)));
mt.set_function("LoadTextures",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1){return obj->loadTextures(arg0,arg1);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2){return obj->loadTextures(arg0,arg1,arg2);},[](cocos2d::ui::Button* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,cocos2d::ui::Widget::TextureResType arg3){return obj->loadTextures(arg0,arg1,arg2,arg3);}));
mt.set_function("LoadTextureNormal",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->loadTextureNormal(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureNormal(arg0,arg1);}));
mt.set_function("LoadTexturePressed",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->loadTexturePressed(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTexturePressed(arg0,arg1);}));
mt.set_function("LoadTextureDisabled",sol::overload([](cocos2d::ui::Button* obj,const std::string& arg0){return obj->loadTextureDisabled(arg0);},[](cocos2d::ui::Button* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureDisabled(arg0,arg1);}));
mt.set_function("SetCapInsets",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsets));
mt.set_function("SetCapInsetsNormalRenderer",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsetsNormalRenderer));
mt.set_function("GetCapInsetsNormalRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getCapInsetsNormalRenderer));
mt.set_function("SetCapInsetsPressedRenderer",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsetsPressedRenderer));
mt.set_function("GetCapInsetsPressedRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getCapInsetsPressedRenderer));
mt.set_function("SetCapInsetsDisabledRenderer",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Rect&)>(&cocos2d::ui::Button::setCapInsetsDisabledRenderer));
mt.set_function("GetCapInsetsDisabledRenderer",static_cast<const cocos2d::Rect&(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getCapInsetsDisabledRenderer));
mt.set_function("SetScale9Enabled",static_cast<void(cocos2d::ui::Button::*)(bool)>(&cocos2d::ui::Button::setScale9Enabled));
mt.set_function("IsScale9Enabled",static_cast<bool(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::isScale9Enabled));
mt.set_function("SetPressedActionEnabled",static_cast<void(cocos2d::ui::Button::*)(bool)>(&cocos2d::ui::Button::setPressedActionEnabled));
mt.set_function("IgnoreContentAdaptWithSize",static_cast<void(cocos2d::ui::Button::*)(bool)>(&cocos2d::ui::Button::ignoreContentAdaptWithSize));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getVirtualRenderer));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getDescription));
mt.set_function("GetTitleRenderer",static_cast<cocos2d::Label*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleRenderer));
mt.set_function("SetTitleText",static_cast<void(cocos2d::ui::Button::*)(const std::string&)>(&cocos2d::ui::Button::setTitleText));
mt.set_function("GetTitleText",static_cast<std::string(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleText));
mt.set_function("SetTitleColor",static_cast<void(cocos2d::ui::Button::*)(const cocos2d::Color3B&)>(&cocos2d::ui::Button::setTitleColor));
mt.set_function("GetTitleColor",static_cast<cocos2d::Color3B(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleColor));
mt.set_function("SetTitleFontSize",static_cast<void(cocos2d::ui::Button::*)(float)>(&cocos2d::ui::Button::setTitleFontSize));
mt.set_function("GetTitleFontSize",static_cast<float(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleFontSize));
mt.set_function("SetTitleFontName",static_cast<void(cocos2d::ui::Button::*)(const std::string&)>(&cocos2d::ui::Button::setTitleFontName));
mt.set_function("GetTitleFontName",static_cast<std::string(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleFontName));
mt.set_function("SetTitleAlignment",sol::overload(static_cast<void(cocos2d::ui::Button::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::ui::Button::setTitleAlignment),static_cast<void(cocos2d::ui::Button::*)(cocos2d::TextHAlignment)>(&cocos2d::ui::Button::setTitleAlignment)));
mt.set_function("SetTitleLabel",static_cast<void(cocos2d::ui::Button::*)(cocos2d::Label*)>(&cocos2d::ui::Button::setTitleLabel));
mt.set_function("GetTitleLabel",static_cast<cocos2d::Label*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getTitleLabel));
mt.set_function("SetZoomScale",static_cast<void(cocos2d::ui::Button::*)(float)>(&cocos2d::ui::Button::setZoomScale));
mt.set_function("GetZoomScale",static_cast<float(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getZoomScale));
mt.set_function("GetRendererNormal",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getRendererNormal));
mt.set_function("GetRendererClicked",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getRendererClicked));
mt.set_function("GetRendererDisabled",static_cast<cocos2d::ui::Scale9Sprite*(cocos2d::ui::Button::*)()const>(&cocos2d::ui::Button::getRendererDisabled));
mt.set_function("ResetNormalRender",static_cast<void(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::resetNormalRender));
mt.set_function("ResetPressedRender",static_cast<void(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::resetPressedRender));
mt.set_function("ResetDisabledRender",static_cast<void(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::resetDisabledRender));
mt.set_function("GetNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getNormalFile));
mt.set_function("GetPressedFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getPressedFile));
mt.set_function("GetDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::Button::*)()>(&cocos2d::ui::Button::getDisabledFile));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::Button::__Type));
}
void RegisterLuaUIAbstractCheckButtonAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::AbstractCheckButton>("ccui","AbstractCheckButton",true);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("LoadTextures",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4){return obj->loadTextures(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->loadTextures(arg0,arg1,arg2,arg3,arg4,arg5);}));
mt.set_function("LoadTextureBackGround",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureBackGround(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureBackGround(arg0,arg1);}));
mt.set_function("LoadTextureBackGroundSelected",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureBackGroundSelected(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureBackGroundSelected(arg0,arg1);}));
mt.set_function("LoadTextureFrontCross",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureFrontCross(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureFrontCross(arg0,arg1);}));
mt.set_function("LoadTextureBackGroundDisabled",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureBackGroundDisabled(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureBackGroundDisabled(arg0,arg1);}));
mt.set_function("LoadTextureFrontCrossDisabled",sol::overload([](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0){return obj->loadTextureFrontCrossDisabled(arg0);},[](cocos2d::ui::AbstractCheckButton* obj,const std::string& arg0,cocos2d::ui::Widget::TextureResType arg1){return obj->loadTextureFrontCrossDisabled(arg0,arg1);}));
mt.set_function("IsSelected",static_cast<bool(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::isSelected));
mt.set_function("SetSelected",static_cast<void(cocos2d::ui::AbstractCheckButton::*)(bool)>(&cocos2d::ui::AbstractCheckButton::setSelected));
mt.set_function("GetVirtualRendererSize",static_cast<cocos2d::Size(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getVirtualRendererSize));
mt.set_function("GetVirtualRenderer",static_cast<cocos2d::Node*(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getVirtualRenderer));
mt.set_function("SetZoomScale",static_cast<void(cocos2d::ui::AbstractCheckButton::*)(float)>(&cocos2d::ui::AbstractCheckButton::setZoomScale));
mt.set_function("GetZoomScale",static_cast<float(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getZoomScale));
mt.set_function("GetRendererBackground",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererBackground));
mt.set_function("GetRendererBackgroundSelected",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererBackgroundSelected));
mt.set_function("GetRendererFrontCross",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererFrontCross));
mt.set_function("GetRendererBackgroundDisabled",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererBackgroundDisabled));
mt.set_function("GetRendererFrontCrossDisabled",static_cast<cocos2d::Sprite*(cocos2d::ui::AbstractCheckButton::*)()const>(&cocos2d::ui::AbstractCheckButton::getRendererFrontCrossDisabled));
mt.set_function("GetBackNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getBackNormalFile));
mt.set_function("GetBackPressedFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getBackPressedFile));
mt.set_function("GetBackDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getBackDisabledFile));
mt.set_function("GetCrossNormalFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getCrossNormalFile));
mt.set_function("GetCrossDisabledFile",static_cast<cocos2d::ResourceData(cocos2d::ui::AbstractCheckButton::*)()>(&cocos2d::ui::AbstractCheckButton::getCrossDisabledFile));
}
void RegisterLuaUICheckBoxEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["CheckBox"];
pTable.new_enum<cocos2d::ui::CheckBox::EventType>("EventType",{
{"SELECTED",cocos2d::ui::CheckBox::EventType::SELECTED}
,{"UNSELECTED",cocos2d::ui::CheckBox::EventType::UNSELECTED}
});}
void RegisterLuaUICheckBoxAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::CheckBox>("ccui","CheckBox",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::CheckBox::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},static_cast<cocos2d::ui::CheckBox*(*)()>(&cocos2d::ui::CheckBox::create),[](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::CheckBox* obj,const std::string& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::CheckBox::*)(const cocos2d::ui::CheckBox::ccCheckBoxCallback&)>(&cocos2d::ui::CheckBox::addEventListener));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::CheckBox::*)()const>(&cocos2d::ui::CheckBox::getDescription));
mt.set_function("OnTouchEnded",static_cast<void(cocos2d::ui::CheckBox::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::ui::CheckBox::onTouchEnded));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::CheckBox::__Type));
RegisterLuaUICheckBoxEventTypeAuto(lua);
}
void RegisterLuaUIRadioButtonEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RadioButton"];
pTable.new_enum<cocos2d::ui::RadioButton::EventType>("EventType",{
{"SELECTED",cocos2d::ui::RadioButton::EventType::SELECTED}
,{"UNSELECTED",cocos2d::ui::RadioButton::EventType::UNSELECTED}
});}
void RegisterLuaUIRadioButtonAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RadioButton>("ccui","RadioButton",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::AbstractCheckButton,cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function("CreateInstance",static_cast<cocos2d::Ref*(*)()>(&cocos2d::ui::RadioButton::createInstance));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4){return obj->create(arg0,arg1,arg2,arg3,arg4);},[](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1,const std::string& arg2,const std::string& arg3,const std::string& arg4,cocos2d::ui::Widget::TextureResType arg5){return obj->create(arg0,arg1,arg2,arg3,arg4,arg5);},static_cast<cocos2d::ui::RadioButton*(*)()>(&cocos2d::ui::RadioButton::create),[](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);},[](cocos2d::ui::RadioButton* obj,const std::string& arg0,const std::string& arg1,cocos2d::ui::Widget::TextureResType arg2){return obj->create(arg0,arg1,arg2);}));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::RadioButton::*)(const cocos2d::ui::RadioButton::ccRadioButtonCallback&)>(&cocos2d::ui::RadioButton::addEventListener));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::RadioButton::*)()const>(&cocos2d::ui::RadioButton::getDescription));
mt["_Type"]=sol::var(std::ref(cocos2d::ui::RadioButton::__Type));
RegisterLuaUIRadioButtonEventTypeAuto(lua);
}
void RegisterLuaUIRadioButtonGroupEventTypeAuto(cocos2d::extension::Lua& lua) {
sol::table pTable = lua["ccui"];
pTable = pTable["RadioButtonGroup"];
pTable.new_enum<cocos2d::ui::RadioButtonGroup::EventType>("EventType",{
{"SELECT_CHANGED",cocos2d::ui::RadioButtonGroup::EventType::SELECT_CHANGED}
});}
void RegisterLuaUIRadioButtonGroupAuto(cocos2d::extension::Lua& lua){
auto mt=lua.NewUserType<cocos2d::ui::RadioButtonGroup>("ccui","RadioButtonGroup",false);
cocos2d::extension::Lua::SetBases(mt,sol::bases<cocos2d::ui::Widget,cocos2d::ProtectedNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::ui::LayoutParameterProtocol>());
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::ui::RadioButtonGroup*(*)()>(&cocos2d::ui::RadioButtonGroup::create));
mt.set_function("AddEventListener",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(const cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback&)>(&cocos2d::ui::RadioButtonGroup::addEventListener));
mt.set_function("GetSelectedButtonIndex",static_cast<int(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::getSelectedButtonIndex));
mt.set_function("SetSelectedButton",sol::overload(static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::setSelectedButton),static_cast<void(cocos2d::ui::RadioButtonGroup::*)(int)>(&cocos2d::ui::RadioButtonGroup::setSelectedButton)));
mt.set_function("SetSelectedButtonWithoutEvent",sol::overload(static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::setSelectedButtonWithoutEvent),static_cast<void(cocos2d::ui::RadioButtonGroup::*)(int)>(&cocos2d::ui::RadioButtonGroup::setSelectedButtonWithoutEvent)));
mt.set_function("AddRadioButton",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::addRadioButton));
mt.set_function("RemoveRadioButton",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(cocos2d::ui::RadioButton*)>(&cocos2d::ui::RadioButtonGroup::removeRadioButton));
mt.set_function("RemoveAllRadioButtons",static_cast<void(cocos2d::ui::RadioButtonGroup::*)()>(&cocos2d::ui::RadioButtonGroup::removeAllRadioButtons));
mt.set_function("GetNumberOfRadioButtons",static_cast<ssize_t(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::getNumberOfRadioButtons));
mt.set_function("GetRadioButtonByIndex",static_cast<cocos2d::ui::RadioButton*(cocos2d::ui::RadioButtonGroup::*)(int)const>(&cocos2d::ui::RadioButtonGroup::getRadioButtonByIndex));
mt.set_function("SetAllowedNoSelection",static_cast<void(cocos2d::ui::RadioButtonGroup::*)(bool)>(&cocos2d::ui::RadioButtonGroup::setAllowedNoSelection));
mt.set_function("IsAllowedNoSelection",static_cast<bool(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::isAllowedNoSelection));
mt.set_function("GetDescription",static_cast<std::string(cocos2d::ui::RadioButtonGroup::*)()const>(&cocos2d::ui::RadioButtonGroup::getDescription));
RegisterLuaUIRadioButtonGroupEventTypeAuto(lua);
}
