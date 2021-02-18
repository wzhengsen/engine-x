\#include "base/ccConfig.h"
\#include "scripting/lua-bindings/CCLua.h"
#if $macro_judgement
$macro_judgement
#end if 
\#ifndef __lua_${prefix}_auto_h__
\#define __lua_${prefix}_auto_h__
#if $hpp_headers
#for header in $hpp_headers
\#include "${header}"
#end for
#end if
void RegisterLua${prefix}Auto(cocos2d::Lua&);