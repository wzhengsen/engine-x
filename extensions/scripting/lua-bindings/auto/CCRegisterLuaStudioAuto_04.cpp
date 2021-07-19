#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
namespace cocos2d{
void RegisterLuaStudioRotationFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::RotationFrame).name()] = sol::usertype_traits<cocostudio::timeline::RotationFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::RotationFrame>("deprecated.cocostudio::timeline::RotationFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::RotationFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["RotationFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::RotationFrame*(*)()>(&cocostudio::timeline::RotationFrame::create);
mt["SetRotation"]=static_cast<void(cocostudio::timeline::RotationFrame::*)(float)>(&cocostudio::timeline::RotationFrame::setRotation);
mt["set"]["Rotation"]=mt["SetRotation"];
mt["GetRotation"]=static_cast<float(cocostudio::timeline::RotationFrame::*)()const>(&cocostudio::timeline::RotationFrame::getRotation);
mt["get"]["Rotation"]=mt["GetRotation"];
}
void RegisterLuaStudioSkewFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::SkewFrame).name()] = sol::usertype_traits<cocostudio::timeline::SkewFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::SkewFrame>("deprecated.cocostudio::timeline::SkewFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::SkewFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["SkewFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::SkewFrame*(*)()>(&cocostudio::timeline::SkewFrame::create);
mt["SetSkewX"]=static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewX);
mt["set"]["SkewX"]=mt["SetSkewX"];
mt["GetSkewX"]=static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewX);
mt["get"]["SkewX"]=mt["GetSkewX"];
mt["SetSkewY"]=static_cast<void(cocostudio::timeline::SkewFrame::*)(float)>(&cocostudio::timeline::SkewFrame::setSkewY);
mt["set"]["SkewY"]=mt["SetSkewY"];
mt["GetSkewY"]=static_cast<float(cocostudio::timeline::SkewFrame::*)()const>(&cocostudio::timeline::SkewFrame::getSkewY);
mt["get"]["SkewY"]=mt["GetSkewY"];
}
void RegisterLuaStudioRotationSkewFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::RotationSkewFrame).name()] = sol::usertype_traits<cocostudio::timeline::RotationSkewFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::RotationSkewFrame>("deprecated.cocostudio::timeline::RotationSkewFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::SkewFrame,cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::RotationSkewFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::SkewFrame*>::metatable());
lua["ccs"]["RotationSkewFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::RotationSkewFrame*(*)()>(&cocostudio::timeline::RotationSkewFrame::create);
}
void RegisterLuaStudioPositionFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::PositionFrame).name()] = sol::usertype_traits<cocostudio::timeline::PositionFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::PositionFrame>("deprecated.cocostudio::timeline::PositionFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::PositionFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["PositionFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::PositionFrame*(*)()>(&cocostudio::timeline::PositionFrame::create);
mt["SetPosition"]=static_cast<void(cocostudio::timeline::PositionFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::PositionFrame::setPosition);
mt["set"]["Position"]=mt["SetPosition"];
mt["GetPosition"]=static_cast<cocos2d::Point(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getPosition);
mt["get"]["Position"]=mt["GetPosition"];
mt["SetX"]=static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setX);
mt["set"]["X"]=mt["SetX"];
mt["SetY"]=static_cast<void(cocostudio::timeline::PositionFrame::*)(float)>(&cocostudio::timeline::PositionFrame::setY);
mt["set"]["Y"]=mt["SetY"];
mt["GetX"]=static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getX);
mt["get"]["X"]=mt["GetX"];
mt["GetY"]=static_cast<float(cocostudio::timeline::PositionFrame::*)()const>(&cocostudio::timeline::PositionFrame::getY);
mt["get"]["Y"]=mt["GetY"];
}
void RegisterLuaStudioScaleFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ScaleFrame).name()] = sol::usertype_traits<cocostudio::timeline::ScaleFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ScaleFrame>("deprecated.cocostudio::timeline::ScaleFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ScaleFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["ScaleFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::ScaleFrame*(*)()>(&cocostudio::timeline::ScaleFrame::create);
mt["SetScale"]=static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScale);
mt["set"]["Scale"]=mt["SetScale"];
mt["SetScaleX"]=static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleX);
mt["set"]["ScaleX"]=mt["SetScaleX"];
mt["GetScaleX"]=static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleX);
mt["get"]["ScaleX"]=mt["GetScaleX"];
mt["SetScaleY"]=static_cast<void(cocostudio::timeline::ScaleFrame::*)(float)>(&cocostudio::timeline::ScaleFrame::setScaleY);
mt["set"]["ScaleY"]=mt["SetScaleY"];
mt["GetScaleY"]=static_cast<float(cocostudio::timeline::ScaleFrame::*)()const>(&cocostudio::timeline::ScaleFrame::getScaleY);
mt["get"]["ScaleY"]=mt["GetScaleY"];
}
void RegisterLuaStudioAnchorPointFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::AnchorPointFrame).name()] = sol::usertype_traits<cocostudio::timeline::AnchorPointFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::AnchorPointFrame>("deprecated.cocostudio::timeline::AnchorPointFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::AnchorPointFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["AnchorPointFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::AnchorPointFrame*(*)()>(&cocostudio::timeline::AnchorPointFrame::create);
mt["SetAnchorPoint"]=static_cast<void(cocostudio::timeline::AnchorPointFrame::*)(const cocos2d::Point&)>(&cocostudio::timeline::AnchorPointFrame::setAnchorPoint);
mt["set"]["AnchorPoint"]=mt["SetAnchorPoint"];
mt["GetAnchorPoint"]=static_cast<cocos2d::Point(cocostudio::timeline::AnchorPointFrame::*)()const>(&cocostudio::timeline::AnchorPointFrame::getAnchorPoint);
mt["get"]["AnchorPoint"]=mt["GetAnchorPoint"];
}
void RegisterLuaStudioInnerActionTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table(lua.lua_state(),0,3);
enumTable["LoopAction"]=cocostudio::timeline::InnerActionType::LoopAction;
enumTable["NoLoopAction"]=cocostudio::timeline::InnerActionType::NoLoopAction;
enumTable["SingleFrame"]=cocostudio::timeline::InnerActionType::SingleFrame;
lua["ccs"]["InnerActionType"]=lua.NewEnum(enumTable);
}
void RegisterLuaStudioInnerActionFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::InnerActionFrame).name()] = sol::usertype_traits<cocostudio::timeline::InnerActionFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::InnerActionFrame>("deprecated.cocostudio::timeline::InnerActionFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::InnerActionFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["InnerActionFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::InnerActionFrame*(*)()>(&cocostudio::timeline::InnerActionFrame::create);
mt["SetInnerActionType"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(cocostudio::timeline::InnerActionType)>(&cocostudio::timeline::InnerActionFrame::setInnerActionType);
mt["set"]["InnerActionType"]=mt["SetInnerActionType"];
mt["GetInnerActionType"]=static_cast<cocostudio::timeline::InnerActionType(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getInnerActionType);
mt["get"]["InnerActionType"]=mt["GetInnerActionType"];
mt["SetEnterWithName"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(bool)>(&cocostudio::timeline::InnerActionFrame::setEnterWithName);
mt["set"]["EnterWithName"]=mt["SetEnterWithName"];
mt["SetStartFrameIndex"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setStartFrameIndex);
mt["set"]["StartFrameIndex"]=mt["SetStartFrameIndex"];
mt["GetStartFrameIndex"]=static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getStartFrameIndex);
mt["get"]["StartFrameIndex"]=mt["GetStartFrameIndex"];
mt["SetEndFrameIndex"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setEndFrameIndex);
mt["set"]["EndFrameIndex"]=mt["SetEndFrameIndex"];
mt["GetEndFrameIndex"]=static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getEndFrameIndex);
mt["get"]["EndFrameIndex"]=mt["GetEndFrameIndex"];
mt["SetAnimationName"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(const std::string&)>(&cocostudio::timeline::InnerActionFrame::setAnimationName);
mt["set"]["AnimationName"]=mt["SetAnimationName"];
mt["SetSingleFrameIndex"]=static_cast<void(cocostudio::timeline::InnerActionFrame::*)(int)>(&cocostudio::timeline::InnerActionFrame::setSingleFrameIndex);
mt["set"]["SingleFrameIndex"]=mt["SetSingleFrameIndex"];
mt["GetSingleFrameIndex"]=static_cast<int(cocostudio::timeline::InnerActionFrame::*)()const>(&cocostudio::timeline::InnerActionFrame::getSingleFrameIndex);
mt["get"]["SingleFrameIndex"]=mt["GetSingleFrameIndex"];
mt["static"]["get"]["AnimationAllName"]=[]()->const std::string&{return cocostudio::timeline::InnerActionFrame::AnimationAllName;};
}
void RegisterLuaStudioColorFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::ColorFrame).name()] = sol::usertype_traits<cocostudio::timeline::ColorFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::ColorFrame>("deprecated.cocostudio::timeline::ColorFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::ColorFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["ColorFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::ColorFrame*(*)()>(&cocostudio::timeline::ColorFrame::create);
mt["SetColor"]=static_cast<void(cocostudio::timeline::ColorFrame::*)(const cocos2d::Color3B&)>(&cocostudio::timeline::ColorFrame::setColor);
mt["set"]["Color"]=mt["SetColor"];
mt["GetColor"]=static_cast<cocos2d::Color3B(cocostudio::timeline::ColorFrame::*)()const>(&cocostudio::timeline::ColorFrame::getColor);
mt["get"]["Color"]=mt["GetColor"];
}
void RegisterLuaStudioAlphaFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::timeline::AlphaFrame).name()] = sol::usertype_traits<cocostudio::timeline::AlphaFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::timeline::AlphaFrame>("deprecated.cocostudio::timeline::AlphaFrame");
dep[sol::base_classes]=sol::bases<cocostudio::timeline::Frame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::timeline::AlphaFrame*>::metatable(),sol::usertype_traits<cocostudio::timeline::Frame*>::metatable());
lua["ccs"]["AlphaFrame"]=mt;
mt["__new__"]=static_cast<cocostudio::timeline::AlphaFrame*(*)()>(&cocostudio::timeline::AlphaFrame::create);
mt["SetAlpha"]=static_cast<void(cocostudio::timeline::AlphaFrame::*)(uint8_t)>(&cocostudio::timeline::AlphaFrame::setAlpha);
mt["set"]["Alpha"]=mt["SetAlpha"];
mt["GetAlpha"]=static_cast<uint8_t(cocostudio::timeline::AlphaFrame::*)()const>(&cocostudio::timeline::AlphaFrame::getAlpha);
mt["get"]["Alpha"]=mt["GetAlpha"];
}
}
