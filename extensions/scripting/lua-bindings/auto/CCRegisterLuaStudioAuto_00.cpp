#include "scripting/lua-bindings/auto/CCRegisterLuaStudioAuto.hpp"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CCComExtensionData.h"
void RegisterLuaStudioActionFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionFrame).name()] = sol::usertype_traits<cocostudio::ActionFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionFrame>("deprecated.cocostudio::ActionFrame");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionFrame*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ActionFrame"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionFrame();};
mt["SetFrameIndex"]=static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameIndex);
mt["set"]["FrameIndex"]=mt["SetFrameIndex"];
mt["GetFrameIndex"]=static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameIndex);
mt["get"]["FrameIndex"]=mt["GetFrameIndex"];
mt["SetFrameTime"]=static_cast<void(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::setFrameTime);
mt["set"]["FrameTime"]=mt["SetFrameTime"];
mt["GetFrameTime"]=static_cast<float(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameTime);
mt["get"]["FrameTime"]=mt["GetFrameTime"];
mt["SetFrameType"]=static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setFrameType);
mt["set"]["FrameType"]=mt["SetFrameType"];
mt["GetFrameType"]=static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getFrameType);
mt["get"]["FrameType"]=mt["GetFrameType"];
mt["SetEasingType"]=static_cast<void(cocostudio::ActionFrame::*)(int)>(&cocostudio::ActionFrame::setEasingType);
mt["set"]["EasingType"]=mt["SetEasingType"];
mt["GetEasingType"]=static_cast<int(cocostudio::ActionFrame::*)()>(&cocostudio::ActionFrame::getEasingType);
mt["get"]["EasingType"]=mt["GetEasingType"];
mt["GetAction"]=sol::overload(static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float,cocostudio::ActionFrame*)>(&cocostudio::ActionFrame::getAction),static_cast<cocos2d::ActionInterval*(cocostudio::ActionFrame::*)(float)>(&cocostudio::ActionFrame::getAction));
mt["SetEasingParameter"]=static_cast<void(cocostudio::ActionFrame::*)(std::vector<float, std::allocator<float> >&)>(&cocostudio::ActionFrame::setEasingParameter);
mt["set"]["EasingParameter"]=mt["SetEasingParameter"];
}
void RegisterLuaStudioActionMoveFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionMoveFrame).name()] = sol::usertype_traits<cocostudio::ActionMoveFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionMoveFrame>("deprecated.cocostudio::ActionMoveFrame");
dep[sol::base_classes]=sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionMoveFrame*>::metatable(),sol::usertype_traits<cocostudio::ActionFrame*>::metatable());
lua["ccs"]["ActionMoveFrame"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionMoveFrame();};
mt["SetPosition"]=static_cast<void(cocostudio::ActionMoveFrame::*)(cocos2d::Vec2)>(&cocostudio::ActionMoveFrame::setPosition);
mt["set"]["Position"]=mt["SetPosition"];
mt["GetPosition"]=static_cast<cocos2d::Vec2(cocostudio::ActionMoveFrame::*)()>(&cocostudio::ActionMoveFrame::getPosition);
mt["get"]["Position"]=mt["GetPosition"];
}
void RegisterLuaStudioActionScaleFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionScaleFrame).name()] = sol::usertype_traits<cocostudio::ActionScaleFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionScaleFrame>("deprecated.cocostudio::ActionScaleFrame");
dep[sol::base_classes]=sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionScaleFrame*>::metatable(),sol::usertype_traits<cocostudio::ActionFrame*>::metatable());
lua["ccs"]["ActionScaleFrame"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionScaleFrame();};
mt["SetScaleX"]=static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleX);
mt["set"]["ScaleX"]=mt["SetScaleX"];
mt["GetScaleX"]=static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleX);
mt["get"]["ScaleX"]=mt["GetScaleX"];
mt["SetScaleY"]=static_cast<void(cocostudio::ActionScaleFrame::*)(float)>(&cocostudio::ActionScaleFrame::setScaleY);
mt["set"]["ScaleY"]=mt["SetScaleY"];
mt["GetScaleY"]=static_cast<float(cocostudio::ActionScaleFrame::*)()>(&cocostudio::ActionScaleFrame::getScaleY);
mt["get"]["ScaleY"]=mt["GetScaleY"];
}
void RegisterLuaStudioActionRotationFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionRotationFrame).name()] = sol::usertype_traits<cocostudio::ActionRotationFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionRotationFrame>("deprecated.cocostudio::ActionRotationFrame");
dep[sol::base_classes]=sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionRotationFrame*>::metatable(),sol::usertype_traits<cocostudio::ActionFrame*>::metatable());
lua["ccs"]["ActionRotationFrame"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionRotationFrame();};
mt["SetRotation"]=static_cast<void(cocostudio::ActionRotationFrame::*)(float)>(&cocostudio::ActionRotationFrame::setRotation);
mt["set"]["Rotation"]=mt["SetRotation"];
mt["GetRotation"]=static_cast<float(cocostudio::ActionRotationFrame::*)()>(&cocostudio::ActionRotationFrame::getRotation);
mt["get"]["Rotation"]=mt["GetRotation"];
mt["get"]["Rotation"]=[](cocostudio::ActionRotationFrame* obj){return obj->_rotation;};;
}
void RegisterLuaStudioActionFadeFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionFadeFrame).name()] = sol::usertype_traits<cocostudio::ActionFadeFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionFadeFrame>("deprecated.cocostudio::ActionFadeFrame");
dep[sol::base_classes]=sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionFadeFrame*>::metatable(),sol::usertype_traits<cocostudio::ActionFrame*>::metatable());
lua["ccs"]["ActionFadeFrame"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionFadeFrame();};
mt["SetOpacity"]=static_cast<void(cocostudio::ActionFadeFrame::*)(int)>(&cocostudio::ActionFadeFrame::setOpacity);
mt["set"]["Opacity"]=mt["SetOpacity"];
mt["GetOpacity"]=static_cast<int(cocostudio::ActionFadeFrame::*)()>(&cocostudio::ActionFadeFrame::getOpacity);
mt["get"]["Opacity"]=mt["GetOpacity"];
}
void RegisterLuaStudioActionTintFrameAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionTintFrame).name()] = sol::usertype_traits<cocostudio::ActionTintFrame*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionTintFrame>("deprecated.cocostudio::ActionTintFrame");
dep[sol::base_classes]=sol::bases<cocostudio::ActionFrame,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionTintFrame*>::metatable(),sol::usertype_traits<cocostudio::ActionFrame*>::metatable());
lua["ccs"]["ActionTintFrame"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionTintFrame();};
mt["SetColor"]=static_cast<void(cocostudio::ActionTintFrame::*)(cocos2d::Color3B)>(&cocostudio::ActionTintFrame::setColor);
mt["set"]["Color"]=mt["SetColor"];
mt["GetColor"]=static_cast<cocos2d::Color3B(cocostudio::ActionTintFrame::*)()>(&cocostudio::ActionTintFrame::getColor);
mt["get"]["Color"]=mt["GetColor"];
}
void RegisterLuaStudioActionObjectAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionObject).name()] = sol::usertype_traits<cocostudio::ActionObject*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionObject>("deprecated.cocostudio::ActionObject");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionObject*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ActionObject"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionObject();};
mt["SetName"]=static_cast<void(cocostudio::ActionObject::*)(const char*)>(&cocostudio::ActionObject::setName);
mt["set"]["Name"]=mt["SetName"];
mt["GetName"]=static_cast<const char*(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getName);
mt["get"]["Name"]=mt["GetName"];
mt["SetLoop"]=static_cast<void(cocostudio::ActionObject::*)(bool)>(&cocostudio::ActionObject::setLoop);
mt["set"]["Loop"]=mt["SetLoop"];
mt["GetLoop"]=static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getLoop);
mt["get"]["Loop"]=mt["GetLoop"];
mt["SetUnitTime"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setUnitTime);
mt["set"]["UnitTime"]=mt["SetUnitTime"];
mt["GetUnitTime"]=static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getUnitTime);
mt["get"]["UnitTime"]=mt["GetUnitTime"];
mt["SetCurrentTime"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::setCurrentTime);
mt["set"]["CurrentTime"]=mt["SetCurrentTime"];
mt["GetCurrentTime"]=static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getCurrentTime);
mt["get"]["CurrentTime"]=mt["GetCurrentTime"];
mt["GetTotalTime"]=static_cast<float(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::getTotalTime);
mt["get"]["TotalTime"]=mt["GetTotalTime"];
mt["IsPlaying"]=static_cast<bool(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::isPlaying);
mt["get"]["Playing"]=mt["IsPlaying"];
mt["Play"]=sol::overload(static_cast<void(cocostudio::ActionObject::*)(cocos2d::CallFunc*)>(&cocostudio::ActionObject::play),static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::play));
mt["Pause"]=static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::pause);
mt["Stop"]=static_cast<void(cocostudio::ActionObject::*)()>(&cocostudio::ActionObject::stop);
mt["AddActionNode"]=static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::addActionNode);
mt["RemoveActionNode"]=static_cast<void(cocostudio::ActionObject::*)(cocostudio::ActionNode*)>(&cocostudio::ActionObject::removeActionNode);
mt["UpdateToFrameByTime"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::updateToFrameByTime);
mt["InitWithDictionary"]=static_cast<void(cocostudio::ActionObject::*)(const rapidjson::Value&,cocos2d::Ref*)>(&cocostudio::ActionObject::initWithDictionary);
mt["InitWithBinary"]=static_cast<void(cocostudio::ActionObject::*)(cocostudio::CocoLoader*,cocostudio::stExpCocoNode*,cocos2d::Ref*)>(&cocostudio::ActionObject::initWithBinary);
mt["SimulationActionUpdate"]=static_cast<void(cocostudio::ActionObject::*)(float)>(&cocostudio::ActionObject::simulationActionUpdate);
}
void RegisterLuaStudioActionManagerExAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::ActionManagerEx).name()] = sol::usertype_traits<cocostudio::ActionManagerEx*>::metatable();
auto dep=lua.new_usertype<cocostudio::ActionManagerEx>("deprecated.cocostudio::ActionManagerEx");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::ActionManagerEx*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["ActionManagerEx"]=mt;
mt["__new__"]=[](){return new cocostudio::ActionManagerEx();};
mt["static"]["GetInstance"]=static_cast<cocostudio::ActionManagerEx*(*)()>(&cocostudio::ActionManagerEx::getInstance);
mt["static"]["DestroyInstance"]=static_cast<void(*)()>(&cocostudio::ActionManagerEx::destroyInstance);
mt["GetActionByName"]=static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::getActionByName);
mt["PlayActionByName"]=sol::overload(static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*,cocos2d::CallFunc*)>(&cocostudio::ActionManagerEx::playActionByName),static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::playActionByName));
mt["StopActionByName"]=static_cast<cocostudio::ActionObject*(cocostudio::ActionManagerEx::*)(const char*,const char*)>(&cocostudio::ActionManagerEx::stopActionByName);
mt["InitWithDictionary"]=sol::overload([](cocostudio::ActionManagerEx* obj,const char* arg0,const rapidjson::Value& arg1,cocos2d::Ref* arg2,int arg3){return obj->initWithDictionary(arg0,arg1,arg2,arg3);},[](cocostudio::ActionManagerEx* obj,const char* arg0,const rapidjson::Value& arg1,cocos2d::Ref* arg2){return obj->initWithDictionary(arg0,arg1,arg2);});
mt["InitWithBinary"]=static_cast<void(cocostudio::ActionManagerEx::*)(const char*,cocos2d::Ref*,cocostudio::CocoLoader*,cocostudio::stExpCocoNode*)>(&cocostudio::ActionManagerEx::initWithBinary);
mt["ReleaseActions"]=static_cast<void(cocostudio::ActionManagerEx::*)()>(&cocostudio::ActionManagerEx::releaseActions);
mt["GetStudioVersionNumber"]=static_cast<int(cocostudio::ActionManagerEx::*)()const>(&cocostudio::ActionManagerEx::getStudioVersionNumber);
mt["get"]["StudioVersionNumber"]=mt["GetStudioVersionNumber"];
mt["static"]["get"]["Instance"]=&cocostudio::ActionManagerEx::getInstance;
mt["static"]["set"]["Instance"]=[](std::nullptr_t){cocostudio::ActionManagerEx::destroyInstance();};
}
void RegisterLuaStudioBaseDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::BaseData).name()] = sol::usertype_traits<cocostudio::BaseData*>::metatable();
auto dep=lua.new_usertype<cocostudio::BaseData>("deprecated.cocostudio::BaseData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::BaseData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["BaseData"]=mt;
mt["__new__"]=static_cast<cocostudio::BaseData*(*)()>(&cocostudio::BaseData::create);
mt["Copy"]=static_cast<void(cocostudio::BaseData::*)(const cocostudio::BaseData*)>(&cocostudio::BaseData::copy);
mt["Subtract"]=static_cast<void(cocostudio::BaseData::*)(cocostudio::BaseData*,cocostudio::BaseData*,bool)>(&cocostudio::BaseData::subtract);
mt["SetColor"]=static_cast<void(cocostudio::BaseData::*)(const cocos2d::Color4B&)>(&cocostudio::BaseData::setColor);
mt["set"]["Color"]=mt["SetColor"];
mt["GetColor"]=static_cast<cocos2d::Color4B(cocostudio::BaseData::*)()>(&cocostudio::BaseData::getColor);
mt["get"]["Color"]=mt["GetColor"];
mt["get"]["X"]=[](cocostudio::BaseData* obj){return obj->x;};;
mt["get"]["Y"]=[](cocostudio::BaseData* obj){return obj->y;};;
mt["get"]["ZOrder"]=[](cocostudio::BaseData* obj){return obj->zOrder;};;
mt["get"]["SkewX"]=[](cocostudio::BaseData* obj){return obj->skewX;};;
mt["get"]["SkewY"]=[](cocostudio::BaseData* obj){return obj->skewY;};;
mt["get"]["ScaleX"]=[](cocostudio::BaseData* obj){return obj->scaleX;};;
mt["get"]["ScaleY"]=[](cocostudio::BaseData* obj){return obj->scaleY;};;
mt["get"]["TweenRotate"]=[](cocostudio::BaseData* obj){return obj->tweenRotate;};;
mt["get"]["IsUseColorInfo"]=[](cocostudio::BaseData* obj){return obj->isUseColorInfo;};;
mt["get"]["A"]=[](cocostudio::BaseData* obj){return obj->a;};;
mt["get"]["R"]=[](cocostudio::BaseData* obj){return obj->r;};;
mt["get"]["G"]=[](cocostudio::BaseData* obj){return obj->g;};;
mt["get"]["B"]=[](cocostudio::BaseData* obj){return obj->b;};;
}
void RegisterLuaStudioDisplayDataAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocostudio::DisplayData).name()] = sol::usertype_traits<cocostudio::DisplayData*>::metatable();
auto dep=lua.new_usertype<cocostudio::DisplayData>("deprecated.cocostudio::DisplayData");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocostudio::DisplayData*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["ccs"]["DisplayData"]=mt;
mt["__new__"]=static_cast<cocostudio::DisplayData*(*)()>(&cocostudio::DisplayData::create);
mt["static"]["ChangeDisplayToTexture"]=static_cast<std::string(*)(const std::string&)>(&cocostudio::DisplayData::changeDisplayToTexture);
mt["Copy"]=static_cast<void(cocostudio::DisplayData::*)(cocostudio::DisplayData*)>(&cocostudio::DisplayData::copy);
mt["get"]["DisplayType"]=[](cocostudio::DisplayData* obj){return obj->displayType;};;
mt["get"]["DisplayName"]=[](cocostudio::DisplayData* obj){return obj->displayName;};;
}
