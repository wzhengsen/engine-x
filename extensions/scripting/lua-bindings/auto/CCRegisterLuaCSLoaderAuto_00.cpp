#include "scripting/lua-bindings/auto/CCRegisterLuaCSLoaderAuto.hpp"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
void RegisterLuaCSLoaderbackendProgramTypeAnonymousEnum_7806005948016515557_Auto(cocos2d::Lua& lua) {
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
void RegisterLuaCSLoaderTextureFormatEXTAnonymousEnum_5937429663859482893_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFormatEXT"];
pTable["NONE"] = 0;
pTable["ETC1_ALPHA"] = 1;
}
void RegisterLuaCSLoaderTextureFlagAnonymousEnum__1308082027129547088_Auto(cocos2d::Lua& lua) {
sol::table pTable = lua["cc"];
pTable = pTable["TextureFlag"];
pTable["NONE"] = 0;
pTable["ANTIALIAS_ENABLED"] = 65536;
pTable["PREMULTIPLIEDALPHA"] = 131072;
pTable["RENDERTARGET"] = 262144;
}
void RegisterLuaCSLoaderCSLoaderAuto(cocos2d::Lua& lua){
sol::table ns = lua["cc"];
auto mt=lua.NewUserType<cocos2d::CSLoader>("CSLoader",true);
ns["CSLoader"] = mt;
lua["CSLoader"] = sol::nil;
mt.set_function("init",static_cast<void(cocos2d::CSLoader::*)()>(&cocos2d::CSLoader::init));
mt.set_function("createNodeFromJson",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeFromJson));
mt.set_function("loadNodeWithFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithFile));
mt.set_function("loadNodeWithContent",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::loadNodeWithContent));
mt.set_function("setRecordJsonPath",static_cast<void(cocos2d::CSLoader::*)(bool)>(&cocos2d::CSLoader::setRecordJsonPath));
mt.set_function("isRecordJsonPath",static_cast<bool(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::isRecordJsonPath));
mt.set_function("setJsonPath",static_cast<void(cocos2d::CSLoader::*)(std::string)>(&cocos2d::CSLoader::setJsonPath));
mt.set_function("getJsonPath",static_cast<std::string(cocos2d::CSLoader::*)()const>(&cocos2d::CSLoader::getJsonPath));
mt.set_function("createNodeWithFlatBuffersFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersFile));
mt.set_function("nodeWithFlatBuffersFile",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::nodeWithFlatBuffersFile));
mt.set_function("nodeWithFlatBuffers",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const flatbuffers::NodeTree*)>(&cocos2d::CSLoader::nodeWithFlatBuffers));
mt.set_function("bindCallback",static_cast<bool(cocos2d::CSLoader::*)(const std::string&,const std::string&,cocos2d::ui::Widget*,cocos2d::Node*)>(&cocos2d::CSLoader::bindCallback));
mt.set_function("registReaderObject",static_cast<void(cocos2d::CSLoader::*)(const std::string&,cocos2d::ObjectFactory::Instance)>(&cocos2d::CSLoader::registReaderObject));
mt.set_function("createNodeWithFlatBuffersForSimulator",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithFlatBuffersForSimulator));
mt.set_function("nodeWithFlatBuffersForSimulator",static_cast<cocos2d::Node*(cocos2d::CSLoader::*)(const flatbuffers::NodeTree*)>(&cocos2d::CSLoader::nodeWithFlatBuffersForSimulator));
mt.set_function("getInstance",static_cast<cocos2d::CSLoader*(*)()>(&cocos2d::CSLoader::getInstance));
mt.set_function("destroyInstance",static_cast<void(*)()>(&cocos2d::CSLoader::destroyInstance));
mt.set_function("createNode",sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const cocos2d::Data&)>(&cocos2d::CSLoader::createNode),static_cast<cocos2d::Node*(*)(const cocos2d::Data&,const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::CSLoader::createNode)));
mt.set_function("createNodeWithVisibleSize",sol::overload(static_cast<cocos2d::Node*(*)(const std::string&,const std::function<void (cocos2d::Ref *)>&)>(&cocos2d::CSLoader::createNodeWithVisibleSize),static_cast<cocos2d::Node*(*)(const std::string&)>(&cocos2d::CSLoader::createNodeWithVisibleSize)));
mt.set_function("createTimeline",sol::overload(static_cast<cocostudio::timeline::ActionTimeline*(*)(const cocos2d::Data&,const std::string&)>(&cocos2d::CSLoader::createTimeline),static_cast<cocostudio::timeline::ActionTimeline*(*)(const std::string&)>(&cocos2d::CSLoader::createTimeline)));
}
