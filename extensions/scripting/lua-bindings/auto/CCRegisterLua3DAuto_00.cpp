#include "scripting/lua-bindings/auto/CCRegisterLua3DAuto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "renderer/backend/Buffer.h"
void RegisterLua3DbackendProgramTypeAnonymousEnum__6471240522010613515_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["backend"];
pTable = pTable["ProgramType"];
pTable["POSITION_COLOR_LENGTH_TEXTURE"] = 0;
pTable["POSITION_COLOR_TEXTURE_AS_POINTSIZE"] = 1;
pTable["POSITION_COLOR"] = 2;
pTable["POSITION_UCOLOR"] = 3;
pTable["POSITION_TEXTURE"] = 4;
pTable["POSITION_TEXTURE_COLOR"] = 5;
pTable["POSITION_TEXTURE_COLOR_ALPHA_TEST"] = 6;
pTable["LABEL_NORMAL"] = 7;
pTable["LABLE_OUTLINE"] = 8;
pTable["LABLE_DISTANCEFIELD_GLOW"] = 9;
pTable["LABEL_DISTANCE_NORMAL"] = 10;
pTable["LAYER_RADIA_GRADIENT"] = 11;
pTable["ETC1"] = 12;
pTable["ETC1_GRAY"] = 13;
pTable["GRAY_SCALE"] = 14;
pTable["CAMERA_CLEAR"] = 15;
pTable["TERRAIN_3D"] = 16;
pTable["LINE_COLOR_3D"] = 17;
pTable["SKYBOX_3D"] = 18;
pTable["SKINPOSITION_TEXTURE_3D"] = 19;
pTable["SKINPOSITION_NORMAL_TEXTURE_3D"] = 20;
pTable["POSITION_NORMAL_TEXTURE_3D"] = 21;
pTable["POSITION_NORMAL_3D"] = 22;
pTable["POSITION_TEXTURE_3D"] = 23;
pTable["POSITION_3D"] = 24;
pTable["POSITION_BUMPEDNORMAL_TEXTURE_3D"] = 25;
pTable["SKINPOSITION_BUMPEDNORMAL_TEXTURE_3D"] = 26;
pTable["PARTICLE_TEXTURE_3D"] = 27;
pTable["PARTICLE_COLOR_3D"] = 28;
pTable["HSV"] = 29;
pTable["HSV_ETC1"] = 30;
pTable["BUILTIN_COUNT"] = 31;
pTable["CUSTOM_PROGRAM"] = 4096;
}
void RegisterLua3DTextureFormatEXTAnonymousEnum_328354290637961909_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFormatEXT"];
pTable["NONE"] = 0;
pTable["ETC1_ALPHA"] = 1;
}
void RegisterLua3DTextureFlagAnonymousEnum_979699189084109002_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFlag"];
pTable["NONE"] = 0;
pTable["ANTIALIAS_ENABLED"] = 65536;
pTable["PREMULTIPLIEDALPHA"] = 131072;
pTable["RENDERTARGET"] = 262144;
}
void RegisterLua3DAnimation3DCurveAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Animation3D::Curve>("Curve",true);
ns = ns["Animation3D"];
ns["Curve"] = mt;
lua["Curve"] = sol::nil;
mt["translateCurve"] = &cocos2d::Animation3D::Curve::translateCurve;
mt["rotCurve"] = &cocos2d::Animation3D::Curve::rotCurve;
mt["scaleCurve"] = &cocos2d::Animation3D::Curve::scaleCurve;
}
void RegisterLua3DAnimation3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Animation3D,cocos2d::Ref,cocos2d::LuaObject>("Animation3D",false);
ns["Animation3D"] = mt;
lua["Animation3D"] = sol::nil;
mt.set_function("getDuration",static_cast<float(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getDuration));
mt.set_function("getBoneCurveByName",static_cast<cocos2d::Animation3D::Curve*(cocos2d::Animation3D::*)(const std::string&)const>(&cocos2d::Animation3D::getBoneCurveByName));
mt.set_function("getBoneCurves",static_cast<const std::unordered_map<std::string, cocos2d::Animation3D::Curve *>&(cocos2d::Animation3D::*)()const>(&cocos2d::Animation3D::getBoneCurves));
mt.set_function(sol::meta_function::construct,sol::overload([](cocos2d::Animation3D* obj,const std::string& arg0){return obj->create(arg0);},[](cocos2d::Animation3D* obj,const std::string& arg0,const std::string& arg1){return obj->create(arg0,arg1);}));
RegisterLua3DAnimation3DCurveAuto(lua);
}
void RegisterLua3DAnimate3DAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::Animate3D,cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::LuaObject>("Animate3D",false);
ns["Animate3D"] = mt;
lua["Animate3D"] = sol::nil;
mt.set_function("stop",static_cast<void(cocos2d::Animate3D::*)()>(&cocos2d::Animate3D::stop));
mt.set_function("step",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::step));
mt.set_function("startWithTarget",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Node*)>(&cocos2d::Animate3D::startWithTarget));
mt.set_function("reverse",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::reverse));
mt.set_function("clone",static_cast<cocos2d::Animate3D*(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::clone));
mt.set_function("update",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::update));
mt.set_function("getSpeed",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getSpeed));
mt.set_function("setSpeed",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setSpeed));
mt.set_function("getWeight",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getWeight));
mt.set_function("setWeight",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setWeight));
mt.set_function("setOriginInterval",static_cast<void(cocos2d::Animate3D::*)(float)>(&cocos2d::Animate3D::setOriginInterval));
mt.set_function("getOriginInterval",static_cast<float(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getOriginInterval));
mt.set_function("setQuality",static_cast<void(cocos2d::Animate3D::*)(cocos2d::Animate3DQuality)>(&cocos2d::Animate3D::setQuality));
mt.set_function("getQuality",static_cast<cocos2d::Animate3DQuality(cocos2d::Animate3D::*)()const>(&cocos2d::Animate3D::getQuality));
mt.set_function("setKeyFrameUserInfo",static_cast<void(cocos2d::Animate3D::*)(int,const cocos2d::ValueMap&)>(&cocos2d::Animate3D::setKeyFrameUserInfo));
mt.set_function("getKeyFrameUserInfo",sol::overload(static_cast<cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)>(&cocos2d::Animate3D::getKeyFrameUserInfo),static_cast<const cocos2d::ValueMap*(cocos2d::Animate3D::*)(int)const>(&cocos2d::Animate3D::getKeyFrameUserInfo)));
mt.set_function(sol::meta_function::construct,sol::overload(static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*,float,float)>(&cocos2d::Animate3D::create),static_cast<cocos2d::Animate3D*(*)(cocos2d::Animation3D*)>(&cocos2d::Animate3D::create)));
mt.set_function("createWithFrames",sol::overload([](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2){return obj->createWithFrames(arg0,arg1,arg2);},[](cocos2d::Animate3D* obj,cocos2d::Animation3D* arg0,int arg1,int arg2,float arg3){return obj->createWithFrames(arg0,arg1,arg2,arg3);}));
mt.set_function("getTransitionTime",static_cast<float(*)()>(&cocos2d::Animate3D::getTransitionTime));
mt.set_function("setTransitionTime",static_cast<void(*)(float)>(&cocos2d::Animate3D::setTransitionTime));
}
void RegisterLua3DAnonymousEnum__584764158701715967_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["CCZ_COMPRESSION_ZLIB"] = 0;
pTable["CCZ_COMPRESSION_BZIP2"] = 1;
pTable["CCZ_COMPRESSION_GZIP"] = 2;
pTable["CCZ_COMPRESSION_NONE"] = 3;
}
void RegisterLua3DTextureCubeAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::TextureCube,cocos2d::Ref,cocos2d::LuaObject>("TextureCube",false);
ns["TextureCube"] = mt;
lua["TextureCube"] = sol::nil;
mt.set_function("setTexParameters",static_cast<void(cocos2d::TextureCube::*)(const cocos2d::Texture2D::TexParams&)>(&cocos2d::TextureCube::setTexParameters));
mt.set_function("getBackendTexture",static_cast<cocos2d::backend::TextureBackend*(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::getBackendTexture));
mt.set_function("getImagePaths",static_cast<const std::vector<std::string>&(cocos2d::TextureCube::*)()const>(&cocos2d::TextureCube::getImagePaths));
mt.set_function("reloadTexture",static_cast<bool(cocos2d::TextureCube::*)()>(&cocos2d::TextureCube::reloadTexture));
mt.set_function(sol::meta_function::construct,static_cast<cocos2d::TextureCube*(*)(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&)>(&cocos2d::TextureCube::create));
}
void RegisterLua3DAnonymousEnum__778307205223700478_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXLayerAttribNone"] = 1;
pTable["TMXLayerAttribBase64"] = 2;
pTable["TMXLayerAttribGzip"] = 4;
pTable["TMXLayerAttribZlib"] = 8;
pTable["TMXLayerAttribCSV"] = 16;
}
void RegisterLua3DAnonymousEnum__859397383549052567_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXPropertyNone"] = 0;
pTable["TMXPropertyMap"] = 1;
pTable["TMXPropertyLayer"] = 2;
pTable["TMXPropertyObjectGroup"] = 3;
pTable["TMXPropertyObject"] = 4;
pTable["TMXPropertyTile"] = 5;
pTable["TMXPropertyAnimation"] = 6;
}
void RegisterLua3DAnonymousEnum_1924853843510107983_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable["TMXOrientationOrtho"] = 0;
pTable["TMXOrientationHex"] = 1;
pTable["TMXOrientationIso"] = 2;
pTable["TMXOrientationStaggered"] = 3;
}
