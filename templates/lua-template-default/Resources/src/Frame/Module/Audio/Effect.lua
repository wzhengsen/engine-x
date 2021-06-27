--[[
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

local AudioEngine = cc.AudioEngine;
local UserFile = require("Utils.UserFile");
local Sound = require("Audio.Sound");

---音效类型，继承至Sound，
---所有*All的方法都将重写，只会影响到Effect类型的声音，不会影响到音乐类型。
local Effect = class(Sound);

---禁止访问的方法
local forbiddenMethod = function()
    error("Forbidden!");
end

Effect.static.private.Uncache               = forbiddenMethod;
Effect.static.private.UncacheAll            = forbiddenMethod;
Effect.static.private.Preload               = forbiddenMethod;
Effect.static.private.GetMaxAudioInstance   = forbiddenMethod;
Effect.static.private.SetMaxAudioInstance   = forbiddenMethod;

Effect.static.protected._DefaultVolume = UserFile.EffectDefaultVolume and math.Limit(cc.ToInteger(UserFile.EffectDefaultVolume),0,1) or Sound.DefaultVolume or 0.8;
Effect.static.protected._Silence = UserFile.EffectSilence or false;

-- 记录所有当前运行的声音句柄
Effect.static.private.AllInst = {};
Effect.private.ecfb = nil;
function Effect:ctor(filePath,loop,vol)
    Sound.ctor(self,filePath,loop,vol)
    self.sVol = vol and math.Limit(vol,0,1) or Effect.DefaultVolume;

    self.cfb = function(_,str)
        if self.ecfb then
            self:ecfb(str);
        end

        Effect.AllInst[self.sInst] = nil;
    end
end

function Effect:Play(...)
    if Effect.Silence then
        return false;
    end
    local ret = Sound.Play(self,...);
    if ret then
        Effect.AllInst[self.sInst] = self;
    end
    return ret;
end

function Effect:Stop()
    Effect.AllInst[self.sInst] = nil;
    Sound.Stop(self);
end

function Effect.StopAll()
    for k,v in pairs(Effect.AllInst) do
        AudioEngine.Stop(k);
        v.sInst = AudioEngine.INVALID_AUDIO_ID;
        Effect.AllInst[k] = nil;
    end
end

function Sound.PauseAll()
    for k,_ in pairs(Effect.AllInst) do
        AudioEngine.Pause(k);
    end
end

function Sound.ResumeAll()
    for k,_ in pairs(Effect.AllInst) do
        AudioEngine.Resume(k);
    end
end

function Effect.set:FinishHandler(fcb)
    self.ecfb = fcb;
end

function Effect.static.set.DefaultVolume(vol)
    vol = math.Limit(vol,0,1);
    UserFile.EffectDefaultVolume = vol;
    Effect._DefaultVolume = vol;
end

function Effect.static.get.DefaultVolume()
    return Effect._DefaultVolume;
end

function Effect.static.set.Silence(b)
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

function Effect.static.get.Silence()
    -- 主音量或音效音量任意一个静音，都为静音
    return Sound.Silence or Effect._Silence;
end

cc.Effect = Effect;
return Effect;