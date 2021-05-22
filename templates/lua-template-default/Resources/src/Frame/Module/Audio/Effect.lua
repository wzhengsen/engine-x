--[[
    File:   Effect
    Desc:   音效类型，继承至Sound，
            所有*All的方法都将重写，只会影响到Effect类型的声音，不会影响到音乐类型。
]]

local AudioEngine = cc.AudioEngine
local UserFile = require("Utils.UserFile")
local Sound = require("Audio.Sound")
local Effect = class(Sound)

--[[
    禁止访问的方法
]]
local forbiddenMethod = function()
    error("Forbidden!")
end

Effect.Uncache               = forbiddenMethod
Effect.UncacheAll            = forbiddenMethod
Effect.Preload               = forbiddenMethod
Effect.GetMaxAudioInstance   = forbiddenMethod
Effect.SetMaxAudioInstance   = forbiddenMethod

-- 音效静音选项
Effect.Silence = UserFile().EffectSilence or false

-- 记录所有当前运行的声音句柄
Effect.AllInst = {}

function Effect:__init__(...)
    Sound.__init__(self,...)
    self.sVol = math.Limit(Effect.GetDefaultVolume(),0,1)

    self._cfb = function(_,str)
        if self._ecfb then
            self:_ecfb(str)
        end

        Effect.AllInst[self.sInst] = nil
    end
end

function Effect:Play(...)
    if Effect.GetSilence() then
        return false
    end
    local ret = Sound.Play(self,...)
    if ret then
        Effect.AllInst[self.sInst] = self
    end
    return ret
end

function Effect:Stop()
    Effect.AllInst[self.sInst] = nil

    Sound.Stop(self)
end

function Effect.StopAll()
    for k,v in pairs(Effect.AllInst) do
        AudioEngine.stop(k)
        v.sInst = AudioEngine.INVALID_AUDIO_ID
        Effect.AllInst[k] = nil
    end
end

function Sound.PauseAll()
    for k,_ in pairs(Effect.AllInst) do
        AudioEngine.pause(k)
    end
end

function Sound.ResumeAll()
    for k,_ in pairs(Effect.AllInst) do
        AudioEngine.resume(k)
    end
end

function Effect:SetFinishHandler(fcb)
    self._ecfb = fcb
end

function Effect.SetDefaultVolume(vol)
    vol = math.Limit(vol,0,1)
    UserFile().EffectDefaultVolume = vol
    Effect.DefaultVolume = vol
end

function Effect.GetDefaultVolume()
    local dVol = rawget(Effect,"DefaultVolume") or UserFile().EffectDefaultVolume or Sound.DefaultVolume or 0.8
    Effect.DefaultVolume = dVol
    return dVol
end

--[[
    Func:   设置是否静音
    Param:  boolean
]]
function Effect.SetSilence(b)
    b = syx.Boolean(b);
    if Effect.Silence == b then
        return
    end
    UserFile().MusicSilence = b
    Effect.Silence = b
    if b then
        Effect.StopAll()
    end
end

function Effect.GetSilence()
    -- 主音量或音效音量任意一个静音，都为静音
    return Sound.Silence or Effect.Silence
end

return Effect