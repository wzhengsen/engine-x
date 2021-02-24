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
void RegisterLuaCoredtProximityGridAuto(cocos2d::Lua& lua){
auto mt=lua.NewUserType<dtProximityGrid>("cc","dtProximityGrid");
mt.set_function("init",static_cast<bool(dtProximityGrid::*)(const int,const float)>(&dtProximityGrid::init));
mt.set_function("clear",static_cast<void(dtProximityGrid::*)()>(&dtProximityGrid::clear));
mt.set_function("addItem",static_cast<void(dtProximityGrid::*)(const unsigned short,const float,const float,const float,const float)>(&dtProximityGrid::addItem));
mt.set_function("queryItems",static_cast<int(dtProximityGrid::*)(const float,const float,const float,const float,unsigned short*,const int)const>(&dtProximityGrid::queryItems));
mt.set_function("getItemCountAt",static_cast<int(dtProximityGrid::*)(const int,const int)const>(&dtProximityGrid::getItemCountAt));
mt.set_function("getBounds",static_cast<const int*(dtProximityGrid::*)()const>(&dtProximityGrid::getBounds));
mt.set_function("getCellSize",static_cast<float(dtProximityGrid::*)()const>(&dtProximityGrid::getCellSize));
}
