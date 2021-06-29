#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
#include "network/CCConnection.h"
void RegisterLuaCoreReuseGridAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ReuseGrid).name()] = sol::usertype_traits<cocos2d::ReuseGrid*>::metatable();
auto dep=lua.new_usertype<cocos2d::ReuseGrid>("deprecated.cocos2d::ReuseGrid");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInstant,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ReuseGrid*>::metatable(),sol::usertype_traits<cocos2d::ActionInstant*>::metatable());
lua["cc"]["ReuseGrid"]=mt;
mt["__new__"]=static_cast<cocos2d::ReuseGrid*(*)(int)>(&cocos2d::ReuseGrid::create);
}
void RegisterLuaCoreWaves3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Waves3D).name()] = sol::usertype_traits<cocos2d::Waves3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Waves3D>("deprecated.cocos2d::Waves3D");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Waves3D*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Waves3D"]=mt;
mt["__new__"]=static_cast<cocos2d::Waves3D*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Waves3D::create);
mt["GetAmplitude"]=static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::Waves3D::*)()const>(&cocos2d::Waves3D::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::Waves3D::*)(float)>(&cocos2d::Waves3D::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
void RegisterLuaCoreFlipX3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FlipX3D).name()] = sol::usertype_traits<cocos2d::FlipX3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::FlipX3D>("deprecated.cocos2d::FlipX3D");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FlipX3D*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["FlipX3D"]=mt;
mt["__new__"]=static_cast<cocos2d::FlipX3D*(*)(float)>(&cocos2d::FlipX3D::create);
}
void RegisterLuaCoreFlipY3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::FlipY3D).name()] = sol::usertype_traits<cocos2d::FlipY3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::FlipY3D>("deprecated.cocos2d::FlipY3D");
dep[sol::base_classes]=sol::bases<cocos2d::FlipX3D,cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::FlipY3D*>::metatable(),sol::usertype_traits<cocos2d::FlipX3D*>::metatable());
lua["cc"]["FlipY3D"]=mt;
mt["__new__"]=static_cast<cocos2d::FlipY3D*(*)(float)>(&cocos2d::FlipY3D::create);
}
void RegisterLuaCoreLens3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Lens3D).name()] = sol::usertype_traits<cocos2d::Lens3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Lens3D>("deprecated.cocos2d::Lens3D");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Lens3D*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Lens3D"]=mt;
mt["__new__"]=static_cast<cocos2d::Lens3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float)>(&cocos2d::Lens3D::create);
mt["GetLensEffect"]=static_cast<float(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getLensEffect);
mt["get"]["LensEffect"]=mt["GetLensEffect"];
mt["SetLensEffect"]=static_cast<void(cocos2d::Lens3D::*)(float)>(&cocos2d::Lens3D::setLensEffect);
mt["set"]["LensEffect"]=mt["SetLensEffect"];
mt["SetConcave"]=static_cast<void(cocos2d::Lens3D::*)(bool)>(&cocos2d::Lens3D::setConcave);
mt["set"]["Concave"]=mt["SetConcave"];
mt["GetPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Lens3D::*)()const>(&cocos2d::Lens3D::getPosition);
mt["get"]["Position"]=mt["GetPosition"];
mt["SetPosition"]=static_cast<void(cocos2d::Lens3D::*)(const cocos2d::Vec2&)>(&cocos2d::Lens3D::setPosition);
mt["set"]["Position"]=mt["SetPosition"];
}
void RegisterLuaCoreRipple3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Ripple3D).name()] = sol::usertype_traits<cocos2d::Ripple3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Ripple3D>("deprecated.cocos2d::Ripple3D");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Ripple3D*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Ripple3D"]=mt;
mt["__new__"]=static_cast<cocos2d::Ripple3D*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,float,unsigned int,float)>(&cocos2d::Ripple3D::create);
mt["GetPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getPosition);
mt["get"]["Position"]=mt["GetPosition"];
mt["SetPosition"]=static_cast<void(cocos2d::Ripple3D::*)(const cocos2d::Vec2&)>(&cocos2d::Ripple3D::setPosition);
mt["set"]["Position"]=mt["SetPosition"];
mt["GetAmplitude"]=static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::Ripple3D::*)()const>(&cocos2d::Ripple3D::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::Ripple3D::*)(float)>(&cocos2d::Ripple3D::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
void RegisterLuaCoreShaky3DAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Shaky3D).name()] = sol::usertype_traits<cocos2d::Shaky3D*>::metatable();
auto dep=lua.new_usertype<cocos2d::Shaky3D>("deprecated.cocos2d::Shaky3D");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Shaky3D*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Shaky3D"]=mt;
mt["__new__"]=static_cast<cocos2d::Shaky3D*(*)(float,const cocos2d::Size&,int,bool)>(&cocos2d::Shaky3D::create);
}
void RegisterLuaCoreLiquidAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Liquid).name()] = sol::usertype_traits<cocos2d::Liquid*>::metatable();
auto dep=lua.new_usertype<cocos2d::Liquid>("deprecated.cocos2d::Liquid");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Liquid*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Liquid"]=mt;
mt["__new__"]=static_cast<cocos2d::Liquid*(*)(float,const cocos2d::Size&,unsigned int,float)>(&cocos2d::Liquid::create);
mt["GetAmplitude"]=static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::Liquid::*)()const>(&cocos2d::Liquid::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::Liquid::*)(float)>(&cocos2d::Liquid::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
void RegisterLuaCoreWavesAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Waves).name()] = sol::usertype_traits<cocos2d::Waves*>::metatable();
auto dep=lua.new_usertype<cocos2d::Waves>("deprecated.cocos2d::Waves");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Waves*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Waves"]=mt;
mt["__new__"]=static_cast<cocos2d::Waves*(*)(float,const cocos2d::Size&,unsigned int,float,bool,bool)>(&cocos2d::Waves::create);
mt["GetAmplitude"]=static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::Waves::*)()const>(&cocos2d::Waves::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::Waves::*)(float)>(&cocos2d::Waves::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
void RegisterLuaCoreTwirlAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Twirl).name()] = sol::usertype_traits<cocos2d::Twirl*>::metatable();
auto dep=lua.new_usertype<cocos2d::Twirl>("deprecated.cocos2d::Twirl");
dep[sol::base_classes]=sol::bases<cocos2d::Grid3DAction,cocos2d::GridAction,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Twirl*>::metatable(),sol::usertype_traits<cocos2d::Grid3DAction*>::metatable());
lua["cc"]["Twirl"]=mt;
mt["__new__"]=static_cast<cocos2d::Twirl*(*)(float,const cocos2d::Size&,const cocos2d::Vec2&,unsigned int,float)>(&cocos2d::Twirl::create);
mt["GetPosition"]=static_cast<const cocos2d::Vec2&(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getPosition);
mt["get"]["Position"]=mt["GetPosition"];
mt["SetPosition"]=static_cast<void(cocos2d::Twirl::*)(const cocos2d::Vec2&)>(&cocos2d::Twirl::setPosition);
mt["set"]["Position"]=mt["SetPosition"];
mt["GetAmplitude"]=static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitude);
mt["get"]["Amplitude"]=mt["GetAmplitude"];
mt["SetAmplitude"]=static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitude);
mt["set"]["Amplitude"]=mt["SetAmplitude"];
mt["GetAmplitudeRate"]=static_cast<float(cocos2d::Twirl::*)()const>(&cocos2d::Twirl::getAmplitudeRate);
mt["get"]["AmplitudeRate"]=mt["GetAmplitudeRate"];
mt["SetAmplitudeRate"]=static_cast<void(cocos2d::Twirl::*)(float)>(&cocos2d::Twirl::setAmplitudeRate);
mt["set"]["AmplitudeRate"]=mt["SetAmplitudeRate"];
}
