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
namespace cocos2d{
void RegisterLuaCoreActionTweenDelegateAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionTweenDelegate).name()] = sol::usertype_traits<cocos2d::ActionTweenDelegate*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionTweenDelegate>("deprecated.cocos2d::ActionTweenDelegate");
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionTweenDelegate*>::metatable());
lua["cc"]["ActionTweenDelegate"]=mt;
mt["__new__"] = [](){return nullptr;};
mt["UpdateTweenAction"]=static_cast<void(cocos2d::ActionTweenDelegate::*)(float,const std::string&)>(&cocos2d::ActionTweenDelegate::updateTweenAction);
}
void RegisterLuaCoreActionTweenAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ActionTween).name()] = sol::usertype_traits<cocos2d::ActionTween*>::metatable();
auto dep=lua.new_usertype<cocos2d::ActionTween>("deprecated.cocos2d::ActionTween");
dep[sol::base_classes]=sol::bases<cocos2d::ActionInterval,cocos2d::FiniteTimeAction,cocos2d::Action,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::Clonable>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ActionTween*>::metatable(),sol::usertype_traits<cocos2d::ActionInterval*>::metatable());
lua["cc"]["ActionTween"]=mt;
mt["__new__"]=static_cast<cocos2d::ActionTween*(*)(float,const std::string&,float,float)>(&cocos2d::ActionTween::create);
}
void RegisterLuaCoreAtlasNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::AtlasNode).name()] = sol::usertype_traits<cocos2d::AtlasNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::AtlasNode>("deprecated.cocos2d::AtlasNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::AtlasNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::TextureProtocol*>::metatable());
lua["cc"]["AtlasNode"]=mt;
mt["__new__"]=static_cast<cocos2d::AtlasNode*(*)(const std::string&,int,int,int)>(&cocos2d::AtlasNode::create);
mt["UpdateAtlasValues"]=static_cast<void(cocos2d::AtlasNode::*)()>(&cocos2d::AtlasNode::updateAtlasValues);
mt["SetTextureAtlas"]=static_cast<void(cocos2d::AtlasNode::*)(cocos2d::TextureAtlas*)>(&cocos2d::AtlasNode::setTextureAtlas);
mt["set"]["TextureAtlas"]=mt["SetTextureAtlas"];
mt["GetTextureAtlas"]=static_cast<cocos2d::TextureAtlas*(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getTextureAtlas);
mt["get"]["TextureAtlas"]=mt["GetTextureAtlas"];
mt["SetQuadsToDraw"]=static_cast<void(cocos2d::AtlasNode::*)(ssize_t)>(&cocos2d::AtlasNode::setQuadsToDraw);
mt["set"]["QuadsToDraw"]=mt["SetQuadsToDraw"];
mt["GetQuadsToDraw"]=static_cast<size_t(cocos2d::AtlasNode::*)()const>(&cocos2d::AtlasNode::getQuadsToDraw);
mt["get"]["QuadsToDraw"]=mt["GetQuadsToDraw"];
}
void RegisterLuaCoreClippingNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ClippingNode).name()] = sol::usertype_traits<cocos2d::ClippingNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::ClippingNode>("deprecated.cocos2d::ClippingNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ClippingNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ClippingNode"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ClippingNode*(*)(cocos2d::Node*)>(&cocos2d::ClippingNode::create),static_cast<cocos2d::ClippingNode*(*)()>(&cocos2d::ClippingNode::create));
mt["GetStencil"]=static_cast<cocos2d::Node*(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getStencil);
mt["get"]["Stencil"]=mt["GetStencil"];
mt["SetStencil"]=static_cast<void(cocos2d::ClippingNode::*)(cocos2d::Node*)>(&cocos2d::ClippingNode::setStencil);
mt["set"]["Stencil"]=mt["SetStencil"];
mt["HasContent"]=static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::hasContent);
mt["GetAlphaThreshold"]=static_cast<float(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::getAlphaThreshold);
mt["get"]["AlphaThreshold"]=mt["GetAlphaThreshold"];
mt["SetAlphaThreshold"]=static_cast<void(cocos2d::ClippingNode::*)(float)>(&cocos2d::ClippingNode::setAlphaThreshold);
mt["set"]["AlphaThreshold"]=mt["SetAlphaThreshold"];
mt["IsInverted"]=static_cast<bool(cocos2d::ClippingNode::*)()const>(&cocos2d::ClippingNode::isInverted);
mt["get"]["Inverted"]=mt["IsInverted"];
mt["SetInverted"]=static_cast<void(cocos2d::ClippingNode::*)(bool)>(&cocos2d::ClippingNode::setInverted);
mt["set"]["Inverted"]=mt["SetInverted"];
}
void RegisterLuaCoreClippingRectangleNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::ClippingRectangleNode).name()] = sol::usertype_traits<cocos2d::ClippingRectangleNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::ClippingRectangleNode>("deprecated.cocos2d::ClippingRectangleNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::ClippingRectangleNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["ClippingRectangleNode"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::ClippingRectangleNode*(*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::create),static_cast<cocos2d::ClippingRectangleNode*(*)()>(&cocos2d::ClippingRectangleNode::create));
mt["GetClippingRegion"]=static_cast<const cocos2d::Rect&(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::getClippingRegion);
mt["get"]["ClippingRegion"]=mt["GetClippingRegion"];
mt["SetClippingRegion"]=static_cast<void(cocos2d::ClippingRectangleNode::*)(const cocos2d::Rect&)>(&cocos2d::ClippingRectangleNode::setClippingRegion);
mt["set"]["ClippingRegion"]=mt["SetClippingRegion"];
mt["IsClippingEnabled"]=static_cast<bool(cocos2d::ClippingRectangleNode::*)()const>(&cocos2d::ClippingRectangleNode::isClippingEnabled);
mt["get"]["ClippingEnabled"]=mt["IsClippingEnabled"];
mt["SetClippingEnabled"]=static_cast<void(cocos2d::ClippingRectangleNode::*)(bool)>(&cocos2d::ClippingRectangleNode::setClippingEnabled);
mt["set"]["ClippingEnabled"]=mt["SetClippingEnabled"];
}
void RegisterLuaCoreDrawNodeAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::DrawNode).name()] = sol::usertype_traits<cocos2d::DrawNode*>::metatable();
auto dep=lua.new_usertype<cocos2d::DrawNode>("deprecated.cocos2d::DrawNode");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::DrawNode*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["DrawNode"]=mt;
mt["__new__"]=sol::overload([](float arg0){return cocos2d::DrawNode::create(arg0);},[](){return cocos2d::DrawNode::create();});
mt["DrawPoint"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoint);
mt["DrawPoints"]=sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,const float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoints),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoints));
mt["DrawLine"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawLine);
mt["DrawRect"]=sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawRect));
mt["DrawPoly"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPoly);
mt["DrawCircle"]=sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,bool,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCircle));
mt["DrawQuadBezier"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawQuadBezier);
mt["DrawCubicBezier"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCubicBezier);
mt["DrawCardinalSpline"]=static_cast<void(cocos2d::DrawNode::*)(cocos2d::PointArray*,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCardinalSpline);
mt["DrawCatmullRom"]=static_cast<void(cocos2d::DrawNode::*)(cocos2d::PointArray*,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawCatmullRom);
mt["DrawDot"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawDot);
mt["DrawSolidRect"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidRect);
mt["DrawSolidPoly"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidPoly);
mt["DrawSolidCircle"]=sol::overload(static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,float,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle),static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,float,float,unsigned int,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSolidCircle));
mt["DrawSegment"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawSegment);
mt["DrawPolygon"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2*,int,const cocos2d::Color4F&,float,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawPolygon);
mt["DrawTriangle"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Vec2&,const cocos2d::Color4F&)>(&cocos2d::DrawNode::drawTriangle);
mt["Clear"]=static_cast<void(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::clear);
mt["GetBlendFunc"]=static_cast<const cocos2d::BlendFunc&(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::getBlendFunc);
mt["get"]["BlendFunc"]=mt["GetBlendFunc"];
mt["SetBlendFunc"]=static_cast<void(cocos2d::DrawNode::*)(const cocos2d::BlendFunc&)>(&cocos2d::DrawNode::setBlendFunc);
mt["set"]["BlendFunc"]=mt["SetBlendFunc"];
mt["SetLineWidth"]=static_cast<void(cocos2d::DrawNode::*)(float)>(&cocos2d::DrawNode::setLineWidth);
mt["set"]["LineWidth"]=mt["SetLineWidth"];
mt["GetLineWidth"]=static_cast<float(cocos2d::DrawNode::*)()>(&cocos2d::DrawNode::getLineWidth);
mt["get"]["LineWidth"]=mt["GetLineWidth"];
mt["SetIsolated"]=static_cast<void(cocos2d::DrawNode::*)(bool)>(&cocos2d::DrawNode::setIsolated);
mt["set"]["Isolated"]=mt["SetIsolated"];
mt["IsIsolated"]=static_cast<bool(cocos2d::DrawNode::*)()const>(&cocos2d::DrawNode::isIsolated);
mt["get"]["Isolated"]=mt["IsIsolated"];
}
void RegisterLuaCoreLabelOverflowAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["NONE"]=cocos2d::Label::Overflow::NONE;
enumTable["CLAMP"]=cocos2d::Label::Overflow::CLAMP;
enumTable["SHRINK"]=cocos2d::Label::Overflow::SHRINK;
enumTable["RESIZE_HEIGHT"]=cocos2d::Label::Overflow::RESIZE_HEIGHT;
lua["cc"]["Label"]["static"]["Overflow"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreLabelLabelTypeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,4);
enumTable["TTF"]=cocos2d::Label::LabelType::TTF;
enumTable["BMFONT"]=cocos2d::Label::LabelType::BMFONT;
enumTable["CHARMAP"]=cocos2d::Label::LabelType::CHARMAP;
enumTable["STRING_TEXTURE"]=cocos2d::Label::LabelType::STRING_TEXTURE;
lua["cc"]["Label"]["static"]["LabelType"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreLabelAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Label).name()] = sol::usertype_traits<cocos2d::Label*>::metatable();
auto dep=lua.new_usertype<cocos2d::Label>("deprecated.cocos2d::Label");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::LabelProtocol,cocos2d::BlendProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Label*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable(),sol::usertype_traits<cocos2d::LabelProtocol*>::metatable(),sol::usertype_traits<cocos2d::BlendProtocol*>::metatable());
lua["cc"]["Label"]=mt;
mt["__new__"]=static_cast<cocos2d::Label*(*)()>(&cocos2d::Label::create);
mt["static"]["CreateWithSystemFont"]=sol::overload([](const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return cocos2d::Label::createWithSystemFont(arg0,arg1,arg2,arg3,arg4,arg5);},[](const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return cocos2d::Label::createWithSystemFont(arg0,arg1,arg2,arg3,arg4);},[](const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return cocos2d::Label::createWithSystemFont(arg0,arg1,arg2,arg3);},[](const std::string& arg0,const std::string& arg1,float arg2){return cocos2d::Label::createWithSystemFont(arg0,arg1,arg2);});
mt["static"]["CreateWithTTF"]=sol::overload([](const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4,cocos2d::TextVAlignment arg5){return cocos2d::Label::createWithTTF(arg0,arg1,arg2,arg3,arg4,arg5);},[](const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3,cocos2d::TextHAlignment arg4){return cocos2d::Label::createWithTTF(arg0,arg1,arg2,arg3,arg4);},[](const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2,int arg3){return cocos2d::Label::createWithTTF(arg0,arg1,arg2,arg3);},[](const std::string& arg0,const std::string& arg1,float arg2,const cocos2d::Size& arg3){return cocos2d::Label::createWithTTF(arg0,arg1,arg2,arg3);},[](const cocos2d::TTFConfig& arg0,const std::string& arg1,cocos2d::TextHAlignment arg2){return cocos2d::Label::createWithTTF(arg0,arg1,arg2);},[](const std::string& arg0,const std::string& arg1,float arg2){return cocos2d::Label::createWithTTF(arg0,arg1,arg2);},[](const cocos2d::TTFConfig& arg0,const std::string& arg1){return cocos2d::Label::createWithTTF(arg0,arg1);});
mt["static"]["CreateWithBMFont"]=sol::overload(static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const cocos2d::Rect&,bool)>(&cocos2d::Label::createWithBMFont),static_cast<cocos2d::Label*(*)(const std::string&,const std::string&,const cocos2d::TextHAlignment&,int,const std::string&)>(&cocos2d::Label::createWithBMFont),[](const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2,int arg3){return cocos2d::Label::createWithBMFont(arg0,arg1,arg2,arg3);},[](const std::string& arg0,const std::string& arg1,const cocos2d::TextHAlignment& arg2){return cocos2d::Label::createWithBMFont(arg0,arg1,arg2);},[](const std::string& arg0,const std::string& arg1){return cocos2d::Label::createWithBMFont(arg0,arg1);});
mt["static"]["CreateWithCharMap"]=sol::overload(static_cast<cocos2d::Label*(*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&,int,int,int)>(&cocos2d::Label::createWithCharMap),static_cast<cocos2d::Label*(*)(const std::string&)>(&cocos2d::Label::createWithCharMap));
mt["SetTTFConfig"]=static_cast<bool(cocos2d::Label::*)(const cocos2d::TTFConfig&)>(&cocos2d::Label::setTTFConfig);
mt["set"]["TTFConfig"]=mt["SetTTFConfig"];
mt["GetTTFConfig"]=static_cast<const cocos2d::TTFConfig&(cocos2d::Label::*)()const>(&cocos2d::Label::getTTFConfig);
mt["get"]["TTFConfig"]=mt["GetTTFConfig"];
mt["SetBMFontFilePath"]=sol::overload([](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2,float arg3){return obj->setBMFontFilePath(arg0,arg1,arg2,arg3);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1,float arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const cocos2d::Rect& arg1,bool arg2){return obj->setBMFontFilePath(arg0,arg1,arg2);},[](cocos2d::Label* obj,const std::string& arg0,const std::string& arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0,float arg1){return obj->setBMFontFilePath(arg0,arg1);},[](cocos2d::Label* obj,const std::string& arg0){return obj->setBMFontFilePath(arg0);});
mt["set"]["BMFontFilePath"]=mt["SetBMFontFilePath"];
mt["GetBMFontFilePath"]=static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontFilePath);
mt["get"]["BMFontFilePath"]=mt["GetBMFontFilePath"];
mt["SetCharMap"]=sol::overload(static_cast<bool(cocos2d::Label::*)(cocos2d::Texture2D*,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&,int,int,int)>(&cocos2d::Label::setCharMap),static_cast<bool(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setCharMap));
mt["set"]["CharMap"]=mt["SetCharMap"];
mt["SetSystemFontName"]=static_cast<void(cocos2d::Label::*)(const std::string&)>(&cocos2d::Label::setSystemFontName);
mt["set"]["SystemFontName"]=mt["SetSystemFontName"];
mt["GetSystemFontName"]=static_cast<const std::string&(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontName);
mt["get"]["SystemFontName"]=mt["GetSystemFontName"];
mt["SetSystemFontSize"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setSystemFontSize);
mt["set"]["SystemFontSize"]=mt["SetSystemFontSize"];
mt["GetSystemFontSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getSystemFontSize);
mt["get"]["SystemFontSize"]=mt["GetSystemFontSize"];
mt["RequestSystemFontRefresh"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::requestSystemFontRefresh);
mt["GetStringNumLines"]=static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringNumLines);
mt["get"]["StringNumLines"]=mt["GetStringNumLines"];
mt["GetStringLength"]=static_cast<int(cocos2d::Label::*)()>(&cocos2d::Label::getStringLength);
mt["get"]["StringLength"]=mt["GetStringLength"];
mt["SetTextColor"]=static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::setTextColor);
mt["set"]["TextColor"]=mt["SetTextColor"];
mt["GetTextColor"]=static_cast<const cocos2d::Color4B&(cocos2d::Label::*)()const>(&cocos2d::Label::getTextColor);
mt["get"]["TextColor"]=mt["GetTextColor"];
mt["EnableShadow"]=sol::overload([](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1,int arg2){return obj->enableShadow(arg0,arg1,arg2);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){return obj->enableShadow(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableShadow(arg0);},[](cocos2d::Label* obj){return obj->enableShadow();});
mt["EnableOutline"]=sol::overload([](cocos2d::Label* obj,const cocos2d::Color4B& arg0,int arg1){return obj->enableOutline(arg0,arg1);},[](cocos2d::Label* obj,const cocos2d::Color4B& arg0){return obj->enableOutline(arg0);});
mt["EnableGlow"]=static_cast<void(cocos2d::Label::*)(const cocos2d::Color4B&)>(&cocos2d::Label::enableGlow);
mt["EnableItalics"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableItalics);
mt["EnableBold"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableBold);
mt["EnableUnderline"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableUnderline);
mt["EnableStrikethrough"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::enableStrikethrough);
mt["DisableEffect"]=sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::LabelEffect)>(&cocos2d::Label::disableEffect),static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::disableEffect));
mt["IsShadowEnabled"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isShadowEnabled);
mt["get"]["ShadowEnabled"]=mt["IsShadowEnabled"];
mt["GetShadowOffset"]=static_cast<cocos2d::Size(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowOffset);
mt["get"]["ShadowOffset"]=mt["GetShadowOffset"];
mt["GetShadowBlurRadius"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowBlurRadius);
mt["get"]["ShadowBlurRadius"]=mt["GetShadowBlurRadius"];
mt["GetShadowColor"]=static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getShadowColor);
mt["get"]["ShadowColor"]=mt["GetShadowColor"];
mt["GetOutlineSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getOutlineSize);
mt["get"]["OutlineSize"]=mt["GetOutlineSize"];
mt["GetLabelEffectType"]=static_cast<cocos2d::LabelEffect(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelEffectType);
mt["get"]["LabelEffectType"]=mt["GetLabelEffectType"];
mt["GetEffectColor"]=static_cast<cocos2d::Color4F(cocos2d::Label::*)()const>(&cocos2d::Label::getEffectColor);
mt["get"]["EffectColor"]=mt["GetEffectColor"];
mt["SetAlignment"]=sol::overload(static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment,cocos2d::TextVAlignment)>(&cocos2d::Label::setAlignment),static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setAlignment));
mt["set"]["Alignment"]=mt["SetAlignment"];
mt["GetTextAlignment"]=static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getTextAlignment);
mt["get"]["TextAlignment"]=mt["GetTextAlignment"];
mt["SetHorizontalAlignment"]=static_cast<void(cocos2d::Label::*)(cocos2d::TextHAlignment)>(&cocos2d::Label::setHorizontalAlignment);
mt["set"]["HorizontalAlignment"]=mt["SetHorizontalAlignment"];
mt["GetHorizontalAlignment"]=static_cast<cocos2d::TextHAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getHorizontalAlignment);
mt["get"]["HorizontalAlignment"]=mt["GetHorizontalAlignment"];
mt["SetVerticalAlignment"]=static_cast<void(cocos2d::Label::*)(cocos2d::TextVAlignment)>(&cocos2d::Label::setVerticalAlignment);
mt["set"]["VerticalAlignment"]=mt["SetVerticalAlignment"];
mt["GetVerticalAlignment"]=static_cast<cocos2d::TextVAlignment(cocos2d::Label::*)()const>(&cocos2d::Label::getVerticalAlignment);
mt["get"]["VerticalAlignment"]=mt["GetVerticalAlignment"];
mt["SetLineBreakWithoutSpace"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setLineBreakWithoutSpace);
mt["set"]["LineBreakWithoutSpace"]=mt["SetLineBreakWithoutSpace"];
mt["SetMaxLineWidth"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setMaxLineWidth);
mt["set"]["MaxLineWidth"]=mt["SetMaxLineWidth"];
mt["GetMaxLineWidth"]=static_cast<float(cocos2d::Label::*)()>(&cocos2d::Label::getMaxLineWidth);
mt["get"]["MaxLineWidth"]=mt["GetMaxLineWidth"];
mt["SetBMFontSize"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setBMFontSize);
mt["set"]["BMFontSize"]=mt["SetBMFontSize"];
mt["GetBMFontSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getBMFontSize);
mt["get"]["BMFontSize"]=mt["GetBMFontSize"];
mt["EnableWrap"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::enableWrap);
mt["IsWrapEnabled"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isWrapEnabled);
mt["get"]["WrapEnabled"]=mt["IsWrapEnabled"];
mt["SetOverflow"]=static_cast<void(cocos2d::Label::*)(cocos2d::Label::Overflow)>(&cocos2d::Label::setOverflow);
mt["set"]["Overflow"]=mt["SetOverflow"];
mt["GetOverflow"]=static_cast<cocos2d::Label::Overflow(cocos2d::Label::*)()const>(&cocos2d::Label::getOverflow);
mt["get"]["Overflow"]=mt["GetOverflow"];
mt["SetWidth"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setWidth);
mt["set"]["Width"]=mt["SetWidth"];
mt["GetWidth"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getWidth);
mt["get"]["Width"]=mt["GetWidth"];
mt["SetHeight"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setHeight);
mt["set"]["Height"]=mt["SetHeight"];
mt["GetHeight"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getHeight);
mt["get"]["Height"]=mt["GetHeight"];
mt["SetDimensions"]=static_cast<void(cocos2d::Label::*)(float,float)>(&cocos2d::Label::setDimensions);
mt["GetDimensions"]=static_cast<const cocos2d::Size&(cocos2d::Label::*)()const>(&cocos2d::Label::getDimensions);
mt["get"]["Dimensions"]=mt["GetDimensions"];
mt["UpdateContent"]=static_cast<void(cocos2d::Label::*)()>(&cocos2d::Label::updateContent);
mt["GetLetter"]=static_cast<cocos2d::Sprite*(cocos2d::Label::*)(int)>(&cocos2d::Label::getLetter);
mt["SetClipMarginEnabled"]=static_cast<void(cocos2d::Label::*)(bool)>(&cocos2d::Label::setClipMarginEnabled);
mt["set"]["ClipMarginEnabled"]=mt["SetClipMarginEnabled"];
mt["IsClipMarginEnabled"]=static_cast<bool(cocos2d::Label::*)()const>(&cocos2d::Label::isClipMarginEnabled);
mt["get"]["ClipMarginEnabled"]=mt["IsClipMarginEnabled"];
mt["SetLineHeight"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineHeight);
mt["set"]["LineHeight"]=mt["SetLineHeight"];
mt["GetLineHeight"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineHeight);
mt["get"]["LineHeight"]=mt["GetLineHeight"];
mt["SetLineSpacing"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setLineSpacing);
mt["set"]["LineSpacing"]=mt["SetLineSpacing"];
mt["GetLineSpacing"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getLineSpacing);
mt["get"]["LineSpacing"]=mt["GetLineSpacing"];
mt["GetLabelType"]=static_cast<cocos2d::Label::LabelType(cocos2d::Label::*)()const>(&cocos2d::Label::getLabelType);
mt["get"]["LabelType"]=mt["GetLabelType"];
mt["GetRenderingFontSize"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getRenderingFontSize);
mt["get"]["RenderingFontSize"]=mt["GetRenderingFontSize"];
mt["SetAdditionalKerning"]=static_cast<void(cocos2d::Label::*)(float)>(&cocos2d::Label::setAdditionalKerning);
mt["set"]["AdditionalKerning"]=mt["SetAdditionalKerning"];
mt["GetAdditionalKerning"]=static_cast<float(cocos2d::Label::*)()const>(&cocos2d::Label::getAdditionalKerning);
mt["get"]["AdditionalKerning"]=mt["GetAdditionalKerning"];
mt["GetFontAtlas"]=static_cast<cocos2d::FontAtlas*(cocos2d::Label::*)()>(&cocos2d::Label::getFontAtlas);
mt["get"]["FontAtlas"]=mt["GetFontAtlas"];
RegisterLuaCoreLabelOverflowAuto(lua);
RegisterLuaCoreLabelLabelTypeAuto(lua);
}
void RegisterLuaCoreLabelAtlasAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::LabelAtlas).name()] = sol::usertype_traits<cocos2d::LabelAtlas*>::metatable();
auto dep=lua.new_usertype<cocos2d::LabelAtlas>("deprecated.cocos2d::LabelAtlas");
dep[sol::base_classes]=sol::bases<cocos2d::AtlasNode,cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject,cocos2d::TextureProtocol,cocos2d::BlendProtocol,cocos2d::LabelProtocol>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::LabelAtlas*>::metatable(),sol::usertype_traits<cocos2d::AtlasNode*>::metatable(),sol::usertype_traits<cocos2d::LabelProtocol*>::metatable());
lua["cc"]["LabelAtlas"]=mt;
mt["__new__"]=sol::overload(static_cast<cocos2d::LabelAtlas*(*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::create),static_cast<cocos2d::LabelAtlas*(*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::create));
mt["InitWithString"]=sol::overload(static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,cocos2d::Texture2D*,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&,int,int,int)>(&cocos2d::LabelAtlas::initWithString),static_cast<bool(cocos2d::LabelAtlas::*)(const std::string&,const std::string&)>(&cocos2d::LabelAtlas::initWithString));
}
void RegisterLuaCoreTouchDispatchModeAuto(cocos2d::extension::Lua& lua) {
sol::table enumTable = lua.create_table_with(0,2);
enumTable["ALL_AT_ONCE"]=cocos2d::Touch::DispatchMode::ALL_AT_ONCE;
enumTable["ONE_BY_ONE"]=cocos2d::Touch::DispatchMode::ONE_BY_ONE;
lua["cc"]["Touch"]["static"]["DispatchMode"]=lua.NewEnum(enumTable);
}
void RegisterLuaCoreTouchAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Touch).name()] = sol::usertype_traits<cocos2d::Touch*>::metatable();
auto dep=lua.new_usertype<cocos2d::Touch>("deprecated.cocos2d::Touch");
dep[sol::base_classes]=sol::bases<cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Touch*>::metatable(),sol::usertype_traits<cocos2d::Ref*>::metatable());
lua["cc"]["Touch"]=mt;
mt["__new__"]=[](){return new cocos2d::Touch();};
mt["GetLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocation);
mt["get"]["Location"]=mt["GetLocation"];
mt["GetPreviousLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocation);
mt["get"]["PreviousLocation"]=mt["GetPreviousLocation"];
mt["GetStartLocation"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocation);
mt["get"]["StartLocation"]=mt["GetStartLocation"];
mt["GetDelta"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getDelta);
mt["get"]["Delta"]=mt["GetDelta"];
mt["GetLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getLocationInView);
mt["get"]["LocationInView"]=mt["GetLocationInView"];
mt["GetPreviousLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getPreviousLocationInView);
mt["get"]["PreviousLocationInView"]=mt["GetPreviousLocationInView"];
mt["GetStartLocationInView"]=static_cast<cocos2d::Vec2(cocos2d::Touch::*)()const>(&cocos2d::Touch::getStartLocationInView);
mt["get"]["StartLocationInView"]=mt["GetStartLocationInView"];
mt["SetTouchInfo"]=sol::overload(static_cast<void(cocos2d::Touch::*)(int,float,float,float,float)>(&cocos2d::Touch::setTouchInfo),static_cast<void(cocos2d::Touch::*)(int,float,float)>(&cocos2d::Touch::setTouchInfo));
mt["GetId"]=static_cast<int(cocos2d::Touch::*)()const>(&cocos2d::Touch::getID);
mt["get"]["ID"]=mt["GetId"];
mt["GetCurrentForce"]=static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getCurrentForce);
mt["get"]["CurrentForce"]=mt["GetCurrentForce"];
mt["GetMaxForce"]=static_cast<float(cocos2d::Touch::*)()const>(&cocos2d::Touch::getMaxForce);
mt["get"]["MaxForce"]=mt["GetMaxForce"];
RegisterLuaCoreTouchDispatchModeAuto(lua);
}
void RegisterLuaCoreLayerAuto(cocos2d::extension::Lua& lua){
cocos2d::extension::Lua::Id2Meta[typeid(cocos2d::Layer).name()] = sol::usertype_traits<cocos2d::Layer*>::metatable();
auto dep=lua.new_usertype<cocos2d::Layer>("deprecated.cocos2d::Layer");
dep[sol::base_classes]=sol::bases<cocos2d::Node,cocos2d::Ref,cocos2d::extension::LuaObject>();
sol::table mt=lua.NewClass(sol::usertype_traits<cocos2d::Layer*>::metatable(),sol::usertype_traits<cocos2d::Node*>::metatable());
lua["cc"]["Layer"]=mt;
mt["__new__"]=static_cast<cocos2d::Layer*(*)()>(&cocos2d::Layer::create);
mt["OnTouchBegan"]=static_cast<bool(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchBegan);
mt["OnTouchMoved"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchMoved);
mt["OnTouchEnded"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchEnded);
mt["OnTouchCancelled"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Touch*,cocos2d::Event*)>(&cocos2d::Layer::onTouchCancelled);
mt["OnTouchesBegan"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesBegan);
mt["OnTouchesMoved"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesMoved);
mt["OnTouchesEnded"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesEnded);
mt["OnTouchesCancelled"]=static_cast<void(cocos2d::Layer::*)(const std::vector<cocos2d::Touch *, std::allocator<cocos2d::Touch *> >&,cocos2d::Event*)>(&cocos2d::Layer::onTouchesCancelled);
mt["OnAcceleration"]=static_cast<void(cocos2d::Layer::*)(cocos2d::Acceleration*,cocos2d::Event*)>(&cocos2d::Layer::onAcceleration);
mt["OnKeyPressed"]=static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyPressed);
mt["OnKeyReleased"]=static_cast<void(cocos2d::Layer::*)(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*)>(&cocos2d::Layer::onKeyReleased);
}
}
