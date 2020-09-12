#include "scripting/lua-bindings/auto/lua_cocos2dx_video_auto.hpp"
#include "ui/UIVideoPlayer/UIVideoPlayer.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_cocos2dx_video_VideoPlayer_SetFileName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetFileName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ccui.VideoPlayer:SetFileName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetFileName'", nullptr);
            return 0;
        }
        cobj->SetFileName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetFileName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetFileName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_GetFileName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_GetFileName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_GetFileName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->GetFileName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:GetFileName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_GetFileName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SetURL(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ccui.VideoPlayer:SetURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetURL'", nullptr);
            return 0;
        }
        cobj->SetURL(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetURL",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetURL'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_GetURL(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_GetURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_GetURL'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->GetURL();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:GetURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_GetURL'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SetLooping(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetLooping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ccui.VideoPlayer:SetLooping");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetLooping'", nullptr);
            return 0;
        }
        cobj->SetLooping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetLooping",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetLooping'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SetUserInputEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetUserInputEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ccui.VideoPlayer:SetUserInputEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetUserInputEnabled'", nullptr);
            return 0;
        }
        cobj->SetUserInputEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetUserInputEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetUserInputEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SetStyle(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetStyle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ui::VideoPlayer::StyleType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ccui.VideoPlayer:SetStyle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetStyle'", nullptr);
            return 0;
        }
        cobj->SetStyle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetStyle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetStyle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_Play(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_Play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_Play'", nullptr);
            return 0;
        }
        cobj->Play();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:Play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_Play'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_Pause(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_Pause'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_Pause'", nullptr);
            return 0;
        }
        cobj->Pause();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:Pause",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_Pause'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_Resume(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_Resume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_Resume'", nullptr);
            return 0;
        }
        cobj->Resume();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:Resume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_Resume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_Stop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_Stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_Stop'", nullptr);
            return 0;
        }
        cobj->Stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:Stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_Stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SeekTo(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SeekTo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ccui.VideoPlayer:SeekTo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SeekTo'", nullptr);
            return 0;
        }
        cobj->SeekTo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SeekTo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SeekTo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_IsPlaying(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_IsPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_IsPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->IsPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:IsPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_IsPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_IsLooping(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_IsLooping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_IsLooping'", nullptr);
            return 0;
        }
        bool ret = cobj->IsLooping();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:IsLooping",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_IsLooping'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_IsUserInputEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_IsUserInputEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_IsUserInputEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->IsUserInputEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:IsUserInputEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_IsUserInputEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SetKeepAspectRatioEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetKeepAspectRatioEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ccui.VideoPlayer:SetKeepAspectRatioEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetKeepAspectRatioEnabled'", nullptr);
            return 0;
        }
        cobj->SetKeepAspectRatioEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetKeepAspectRatioEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetKeepAspectRatioEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_IsKeepAspectRatioEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_IsKeepAspectRatioEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_IsKeepAspectRatioEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->IsKeepAspectRatioEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:IsKeepAspectRatioEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_IsKeepAspectRatioEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_SetFullScreenEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_SetFullScreenEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ccui.VideoPlayer:SetFullScreenEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_SetFullScreenEnabled'", nullptr);
            return 0;
        }
        cobj->SetFullScreenEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:SetFullScreenEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_SetFullScreenEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_IsFullScreenEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_IsFullScreenEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_IsFullScreenEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->IsFullScreenEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:IsFullScreenEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_IsFullScreenEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_OnPlayEvent(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ui::VideoPlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccui.VideoPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ui::VideoPlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_video_VideoPlayer_OnPlayEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ccui.VideoPlayer:OnPlayEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_OnPlayEvent'", nullptr);
            return 0;
        }
        cobj->OnPlayEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ccui.VideoPlayer:OnPlayEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_OnPlayEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_video_VideoPlayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S);

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_video_VideoPlayer_create'", nullptr);
            return 0;
        }
        cocos2d::ui::VideoPlayer* ret = cocos2d::ui::VideoPlayer::create();
        object_to_luaval<cocos2d::ui::VideoPlayer>(tolua_S, "ccui.VideoPlayer",(cocos2d::ui::VideoPlayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ccui.VideoPlayer:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_video_VideoPlayer_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_video_VideoPlayer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (VideoPlayer)");
    return 0;
}

int lua_register_cocos2dx_video_VideoPlayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccui.VideoPlayer");
    tolua_cclass(tolua_S,"VideoPlayer","ccui.VideoPlayer","ccui.Widget",nullptr);

    tolua_beginmodule(tolua_S,"VideoPlayer");
        tolua_function(tolua_S,"SetFileName",lua_cocos2dx_video_VideoPlayer_SetFileName);
        tolua_function(tolua_S,"GetFileName",lua_cocos2dx_video_VideoPlayer_GetFileName);
        tolua_function(tolua_S,"SetURL",lua_cocos2dx_video_VideoPlayer_SetURL);
        tolua_function(tolua_S,"GetURL",lua_cocos2dx_video_VideoPlayer_GetURL);
        tolua_function(tolua_S,"SetLooping",lua_cocos2dx_video_VideoPlayer_SetLooping);
        tolua_function(tolua_S,"SetUserInputEnabled",lua_cocos2dx_video_VideoPlayer_SetUserInputEnabled);
        tolua_function(tolua_S,"SetStyle",lua_cocos2dx_video_VideoPlayer_SetStyle);
        tolua_function(tolua_S,"Play",lua_cocos2dx_video_VideoPlayer_Play);
        tolua_function(tolua_S,"Pause",lua_cocos2dx_video_VideoPlayer_Pause);
        tolua_function(tolua_S,"Resume",lua_cocos2dx_video_VideoPlayer_Resume);
        tolua_function(tolua_S,"Stop",lua_cocos2dx_video_VideoPlayer_Stop);
        tolua_function(tolua_S,"SeekTo",lua_cocos2dx_video_VideoPlayer_SeekTo);
        tolua_function(tolua_S,"IsPlaying",lua_cocos2dx_video_VideoPlayer_IsPlaying);
        tolua_function(tolua_S,"IsLooping",lua_cocos2dx_video_VideoPlayer_IsLooping);
        tolua_function(tolua_S,"IsUserInputEnabled",lua_cocos2dx_video_VideoPlayer_IsUserInputEnabled);
        tolua_function(tolua_S,"SetKeepAspectRatioEnabled",lua_cocos2dx_video_VideoPlayer_SetKeepAspectRatioEnabled);
        tolua_function(tolua_S,"IsKeepAspectRatioEnabled",lua_cocos2dx_video_VideoPlayer_IsKeepAspectRatioEnabled);
        tolua_function(tolua_S,"SetFullScreenEnabled",lua_cocos2dx_video_VideoPlayer_SetFullScreenEnabled);
        tolua_function(tolua_S,"IsFullScreenEnabled",lua_cocos2dx_video_VideoPlayer_IsFullScreenEnabled);
        tolua_function(tolua_S,"OnPlayEvent",lua_cocos2dx_video_VideoPlayer_OnPlayEvent);
        tolua_function(tolua_S,"new", lua_cocos2dx_video_VideoPlayer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::ui::VideoPlayer).name();
    g_luaType[typeName] = "ccui.VideoPlayer";
    g_typeCast["VideoPlayer"] = "ccui.VideoPlayer";
    return 1;
}
TOLUA_API int register_all_cocos2dx_video(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccui",0);
	tolua_beginmodule(tolua_S,"ccui");

	lua_register_cocos2dx_video_VideoPlayer(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

