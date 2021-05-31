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
    File:   Sound
    Auth:   wzhengsen
    Data:   2019.07.06
    Desc:   对cc.SimpleAudioEngine简单封装

    Chg By:     wzhengsen
    Date:       2019.09.26
    Content:    采用继承的方式使用cc.SimpleAudioEngine

    Chg By:     wzhengsen
    Date:       2019.10.14
    Content:    使用ccexp.AudioEngine实现；并重命名为Sound
]]

local AudioEngine = cc.AudioEngine;
local UserFile = require("Utils.UserFile");
local Sound = class();

Sound.StateCode = {
    Error  = -1,
    Initialzing = 0,
    Playing = 1,
    Paused = 2
};

-- 指示获取的持续时间是否是未知的。
Sound.UnkownTime = AudioEngine.TIME_UNKNOWN;

--[[
    构造一个声音对象
    Param:  string                          路径
            boolean[false]                  循环
            number[Sound.DefaultVolume]     音量0-1
]]
function Sound:__init__(filePath,loop,vol)
    self._sInst = AudioEngine.INVALID_AUDIO_ID;
    loop = loop or false;
    vol = vol or Sound.DefaultVolume;
    self._sFilePath = filePath;
    self._sLoop = loop;
    self._sVol = math.Limit(vol,0,1);
end

--[[
    Param:      boolean{false}      是否强制结束当前的播放，而重新开始。
]]
function Sound:Play(force)
    if Sound.Silence then
        return false;
    end

    if self._sInst ~= AudioEngine.INVALID_AUDIO_ID then
        local state = self:GetState();
        if state == Sound.StateCode.Playing
        or state == Sound.StateCode.Paused then
            if force then
                self:Stop();
            else
                -- 播放状态和暂停状态下不能再次播放
                return false;
            end
        end
    end

    self._sInst = AudioEngine.play2d(self._sFilePath,self._sLoop,self._sVol);
    if self._sInst == AudioEngine.INVALID_AUDIO_ID then
        return false;
    end

    if self._cfb then
        -- 再次Play时将回调绑定至新的声音句柄
        AudioEngine.SetFinishCallback(self._sInst,self._cfb);
    end
    return true;
end

function Sound:SetLoop(loop)
    self._sLoop = loop;
    AudioEngine.SetLoop(self._sInst,loop);
end

function Sound:IsLoop()
    return AudioEngine.IsLoop(self._sInst);
end

function Sound:SetVolume(vol)
    self._sVol = math.Limit(vol,0,1);
    AudioEngine.SetVolume(self._sInst,vol);
end

function Sound:GetVolume()
    return AudioEngine.GetVolume(self._sInst);
end

function Sound:Pause()
    AudioEngine.Pause(self._sInst);
end

function Sound:Resume()
    AudioEngine.Resume(self._sInst);
end

function Sound:Stop()
    AudioEngine.Stop(self._sInst);
    --停止后，当前句柄将不可用
    self._sInst = AudioEngine.INVALID_AUDIO_ID;
end

function Sound.PauseAll()
    AudioEngine.PauseAll();
end

function Sound.ResumeAll()
    AudioEngine.ResumeAll();
end

function Sound.StopAll()
    AudioEngine.StopAll();
end

--[[
    Func:   设置音效当前时间
    Param:  number
    Return: boolean
]]
function Sound:SetCurrentTime(dt)
    return AudioEngine.SetCurrentTime(self._sInst,dt);
end

function Sound:GetCurrentTime()
    return AudioEngine.GetCurrentTime(self._sInst);
end

function Sound:GetDuration()
    return AudioEngine.GetDuration(self._sInst);
end

--[[
    Func:   获取当前音效状态
    Return: number  Sound.State{}
]]
function Sound:GetState()
    return AudioEngine.GetState(self._sInst);
end

function Sound:SetFinishHandler(fcb)
    self._cfb = function(_,str)
        if fcb then
            fcb(self,str)
        end
    end;
    AudioEngine.SetFinishCallback(self._sInst,self._cfb);
end

function Sound.GetMaxAudioInstance()
    return AudioEngine.GetMaxAudioInstance();
end

function Sound.SetMaxAudioInstance(max)
    AudioEngine.setMaxAudioInstance(max);
end

function Sound.Uncache(filePath)
    AudioEngine.Uncache(filePath);
end

function Sound.UncacheAll()
    AudioEngine.UncacheAll();
end

--[[
    Func:   预载入声音
    Param:  table           声音资源表
            function{nil}   完成回调
]]
function Sound.Preload(sounds,callBack)
    if not callBack then
        for _,v in ipairs(sounds) do
            AudioEngine.Preload(v);
        end
    else
        local count = #sounds;
        for i,sound in ipairs(sounds) do
            AudioEngine.Preload(sound,function(suc)
                callBack(sound,suc,i,count);
            end)
        end
    end
end

function Sound.SetDefaultVolume(vol)
    vol = math.Limit(vol,0,1);
    UserFile.SoundDefaultVolume = vol;
    Sound._DefaultVolume = vol;
end

function Sound.GetDefaultVolume()
    if nil == Sound._DefaultVolume then
        Sound._DefaultVolume = math.Limit(UserFile.SoundDefaultVolume or 0.8,0,1);
    end
    return Sound._DefaultVolume;
end

--[[
    Func:   设置是否静音
    Param:  boolean
]]
function Sound.SetSilence(b)
    b = cc.ToBoolean(b);
    if cc.ToBoolean(Sound._Silence) == b then
        return;
    end
    UserFile.SoundSilence = b;
    Sound._Silence = b;
    if b then
        Sound.StopAll()
    end
end

function Sound.GetSilence()
    if nil == Sound._Silence then
        Sound._Silence = UserFile.SoundSilence or false;
    end
    return Sound._Silence;
end

function Sound:__del__()
    self:Stop();
end

function Sound.__properties__()
    return {
        r = {
            State = Sound.GetState,
            Duration = Sound.GetDuration,
            CurrentTime = Sound.GetCurrentTime,
            Volume = Sound.GetVolume,
            Loop = Sound.IsLoop,
            MaxAudioInstance = Sound.GetMaxAudioInstance,
            DefaultVolume = Sound.GetDefaultVolume,
            Silence = Sound.GetSilence
        },
        w = {
            FinishHandler = Sound.SetFinishHandler,
            CurrentTime = Sound.SetCurrentTime,
            Volume = Sound.SetVolume,
            Loop = Sound.SetLoop,
            MaxAudioInstance = Sound.SetMaxAudioInstance,
            DefaultVolume = Sound.SetDefaultVolume,
            Silence = Sound.SetSilence
        }
    }
end

cc.Sound = Sound;

return Sound;