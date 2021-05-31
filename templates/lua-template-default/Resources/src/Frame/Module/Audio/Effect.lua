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
    File:   Effect
    Desc:   音效类型，继承至Sound，
            所有*All的方法都将重写，只会影响到Effect类型的声音，不会影响到音乐类型。
]]

local AudioEngine = cc.AudioEngine;
local UserFile = require("Utils.UserFile");
local Sound = require("Audio.Sound");
local Effect = class(Sound);

--[[
    禁止访问的方法
]]
local forbiddenMethod = function()
    error("Forbidden!");
end

Effect.Uncache               = forbiddenMethod;
Effect.UncacheAll            = forbiddenMethod;
Effect.Preload               = forbiddenMethod;
Effect.GetMaxAudioInstance   = forbiddenMethod;
Effect.SetMaxAudioInstance   = forbiddenMethod;

-- 音效静音选项
Effect.Silence = UserFile.EffectSilence or false;

-- 记录所有当前运行的声音句柄
Effect._AllInst = {};

function Effect:__init__(...)
    Sound.__init__(self,...)
    self._sVol = math.Limit(Effect.GetDefaultVolume(),0,1);

    self._cfb = function(_,str)
        if self._ecfb then
            self:_ecfb(str);
        end

        Effect._AllInst[self._sInst] = nil;
    end
end

function Effect:Play(...)
    if Effect.GetSilence() then
        return false;
    end
    local ret = Sound.Play(self,...);
    if ret then
        Effect._AllInst[self._sInst] = self;
    end
    return ret;
end

function Effect:Stop()
    Effect._AllInst[self._sInst] = nil;
    Sound.Stop(self);
end

function Effect.StopAll()
    for k,v in pairs(Effect._AllInst) do
        AudioEngine.Stop(k);
        v._sInst = AudioEngine.INVALID_AUDIO_ID;
        Effect._AllInst[k] = nil;
    end
end

function Sound.PauseAll()
    for k,_ in pairs(Effect._AllInst) do
        AudioEngine.Pause(k);
    end
end

function Sound.ResumeAll()
    for k,_ in pairs(Effect._AllInst) do
        AudioEngine.Resume(k);
    end
end

function Effect:SetFinishHandler(fcb)
    self._ecfb = fcb;
end

function Effect.SetDefaultVolume(vol)
    vol = math.Limit(vol,0,1);
    UserFile.EffectDefaultVolume = vol;
    Effect._DefaultVolume = vol;
end

function Effect.GetDefaultVolume()
    local dVol = rawget(Effect,"_DefaultVolume") or UserFile.EffectDefaultVolume or Sound.DefaultVolume or 0.8;
    Effect._DefaultVolume = dVol;
    return dVol;
end

--[[
    Func:   设置是否静音
    Param:  boolean
]]
function Effect.SetSilence(b)
    b = cc.ToBoolean(b);
    if cc.ToBoolean(Effect._Silence) == b then
        return;
    end
    UserFile.EffectSilence = b;
    Effect._Silence = b;
    if b then
        Effect.StopAll();
    end
end

function Effect.GetSilence()
    -- 主音量或音效音量任意一个静音，都为静音
    local sil = Sound.Silence;
    if sil then
        return sil;
    end
    if nil == Effect._Silence then
        Effect._Silence = UserFile.EffectSilence or false;
    end
    return Effect._Silence;
end

function Effect.__properties__()
    return {
        r = {
            DefaultVolume = Effect.GetDefaultVolume,
            Silence = Effect.GetSilence
        },
        w = {
            FinishHandler = Effect.SetFinishHandler,
            DefaultVolume = Effect.SetDefaultVolume,
            Silence = Effect.SetSilence
        }
    };
end

cc.Effect = Effect;

return Effect;