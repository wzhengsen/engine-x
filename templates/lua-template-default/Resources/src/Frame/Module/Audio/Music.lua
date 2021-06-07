--[[

Copyright (c) 2014-2017 Chukong Technologies Inc.
Copyright (c) 2021 wzhengsen.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]
--[[
    File:   Music
    Desc:   继承自Sound，由于背景音乐的特性，该类使用单例；
            某些Sound方法在继承后将不可被Music访问
]]

local Sound = require("Audio.Sound");
local UserFile = require("Utils.UserFile");
local Music = class(Sound,class.Singleton);

--[[
    禁止访问的方法
]]
local forbiddenMethod = function()
    error("Forbidden!");
end
Music.PauseAll              = forbiddenMethod;
Music.ResumeAll             = forbiddenMethod;
Music.StopAll               = forbiddenMethod;
Music.Uncache               = forbiddenMethod;
Music.UncacheAll            = forbiddenMethod;
Music.Preload               = forbiddenMethod;
Music.GetMaxAudioInstance   = forbiddenMethod;
Music.SetMaxAudioInstance   = forbiddenMethod;
Music.SetLoop               = forbiddenMethod;
Music.IsLoop                = forbiddenMethod;

-- 音乐播放模式
Music.PlayMode = {
    -- 单曲单次
    SingleOnce = {},
    -- 单曲循环
    SingleLoop = {},
    -- 列表随机
    ListRandom = {},
    -- 列表循环
    ListLoop = {}
}

function Music:__init__()
    Sound.__init__(self)
    self._sVol = math.Limit(Music.GetDefaultVolume(),0,1);
    self._sFilePath = "";
    self._playList = {};
    self._playMode = Music.PlayMode.ListLoop;

    -- 当前播放序列
    self._curPlayIndex = nil;
    self._cfb = function(_,str)
        if self._mcfb then
            self:_mcfb(str);
        end

        if self._playMode == Music.PlayMode.ListRandom
        or self._playMode == Music.PlayMode.ListLoop then
            self:Next();
        end
    end
end

--[[
    Func:   设置播放列表
    Param:  table               背景音乐只会播放列表中的文件
            boolean{false}      是否预载
]]
function Music:SetList(pList,bPreload)
    self._playList = pList;
    if bPreload then
        Sound.Preload(pList);
    end
end

function Music:GetList()
    return self._playList;
end

--[[
    Func:   设置播放模式
    Param:  table{Music.PlayMode}
]]
function Music:SetMode(mode)
    self._playMode = mode;
end

function Music:GetMode()
    return self._playMode;
end

--[[
    Func:   播放下一首
    Return: boolean     是否成功切换至下一首
]]
function Music:Next()
    self:Stop();
    local listLen = self._playList and #self._playList or 0;
    if listLen == 0 then return false; end

    self._sLoop = self._playMode == Music.PlayMode.SingleLoop;
    if not self._curPlayIndex or self._curPlayIndex >= listLen then
        self._curPlayIndex = 1;
    else
        if self._playMode == Music.PlayMode.ListRandom then
            -- 列表随机采用随机模式
            self._curPlayIndex = math.random(1,listLen);
        else
            self._curPlayIndex = self._curPlayIndex + 1;
        end
    end

    self._sFilePath = self._playList[self._curPlayIndex];
    return self:Play();
end

function Music:Play(...)
    if Music.GetSilence() then
        return false;
    end
    if not self._curPlayIndex then
        return self:Next();
    end
    return Sound.Play(self,...);
end

function Music:SetFinishHandler(fcb)
    self._mcfb = fcb;
end

function Music.SetDefaultVolume(vol)
    vol = math.Limit(vol,0,1);
    UserFile.MusicDefaultVolume = vol;
    Music._DefaultVolume = vol;
end

function Music.GetDefaultVolume()
    local dVol = rawget(Music,"_DefaultVolume") or UserFile.MusicDefaultVolume or Sound.DefaultVolume or 0.8;
    Music._DefaultVolume = dVol;
    return dVol;
end

--[[
    Func:   设置是否静音
    Param:  boolean
]]
function Music.SetSilence(b)
    b = cc.ToBoolean(b);
    if cc.ToBoolean(Music._Silence) == b then
        return;
    end
    UserFile.MusicSilence = b;
    Music._Silence = b;
    if b then
        Music.Instance:Stop();
    end
end

function Music.GetSilence()
    -- 主音量或音乐音量任意一个静音，都为静音
    local sil = Sound.Silence;
    if sil then
        return sil;
    end
    if nil == Music._Silence then
        Music._Silence = UserFile.MusicSilence or false;
    end
    return Music._Silence;
end

function Music.__properties__()
    return {
        r = {
            DefaultVolume = Music.GetDefaultVolume,
            Silence = Music.GetSilence,
            List = Music.GetList,
            Mode = Music.GetMode
        },
        w = {
            FinishHandler = Music.SetFinishHandler,
            DefaultVolume = Music.SetDefaultVolume,
            Silence = Music.SetSilence,
            List = Music.SetList,
            Mode = Music.SetMode
        }
    };
end

cc.Music = Music;

return Music;