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
local UserFile = require("Utils.UserFile")
local Sound = class()

Sound.State = {
    Error  = -1,
    Initialzing = 0,
    Playing = 1,
    Paused = 2
}

--默认音量大小
Sound.DefaultVolume = math.Limit(UserFile().SoundDefaultVolume or 0.8,0,1)

--静音选项
Sound.Silence = UserFile().SoundSilence or false

-- 指示获取的持续时间是否是未知的。
Sound.UnkownTime = AudioEngine.TIME_UNKNOWN;

--[[
    构造一个声音对象
    Param:  string                          路径
            boolean[false]                  循环
            number[Sound.DefaultVolume]     音量0-1
]]
function Sound:__init__(filePath,loop,vol)
    self.sInst = AudioEngine.INVALID_AUDIO_ID
    loop = loop or false
    vol = vol or Sound.DefaultVolume
    self.sFilePath = filePath
    self.sLoop = loop
    self.sVol = math.Limit(vol,0,1)
end

--[[
    Param:      boolean{false}      是否强制结束当前的播放，而重新开始。
]]
function Sound:Play(force)
    if Sound.Silence then
        return false
    end

    if self.sInst ~= AudioEngine.INVALID_AUDIO_ID then
        local state = self:GetState()
        if state == Sound.State.Playing
        or state == Sound.State.Paused then
            if force then
                self:Stop();
            else
                -- 播放状态和暂停状态下不能再次播放
                return false
            end
        end
    end

    self.sInst = AudioEngine.play2d(self.sFilePath,self.sLoop,self.sVol)
    if self.sInst == AudioEngine.INVALID_AUDIO_ID then
        return false
    end

    if self._cfb then
        -- 再次Play时将回调绑定至新的声音句柄
        AudioEngine.setFinishCallback(self.sInst,self._cfb)
    end
    return true
end

function Sound:SetLoop(loop)
    self.sLoop = loop
    AudioEngine.setLoop(self.sInst,loop)
end

function Sound:IsLoop()
    return AudioEngine.isLoop(self.sInst)
end

function Sound:SetVolume(vol)
    self.sVol = math.Limit(vol,0,1)
    AudioEngine.setVolume(self.sInst,vol)
end

function Sound:GetVolume()
    return AudioEngine.getVolume(self.sInst)
end

function Sound:Pause()
    AudioEngine.pause(self.sInst)
end

function Sound.PauseAll()
    AudioEngine.pauseAll()
end

function Sound:Resume()
    AudioEngine.resume(self.sInst)
end

function Sound.ResumeAll()
    AudioEngine.resumeAll()
end

function Sound:Stop()
    AudioEngine.stop(self.sInst)
    --停止后，当前句柄将不可用
    self.sInst = AudioEngine.INVALID_AUDIO_ID
end

function Sound.StopAll()
    AudioEngine.stopAll()
end

--[[
    Func:   设置音效当前时间
    Param:  number
    Return: boolean
]]
function Sound:SetCurrentTime(dt)
    return AudioEngine.setCurrentTime(self.sInst,dt)
end

function Sound:GetCurrentTime()
    return AudioEngine.getCurrentTime(self.sInst)
end

function Sound:GetDuration()
    return AudioEngine.getDuration(self.sInst);
end

--[[
    Func:   获取当前音效状态
    Return: number  Sound.State{}
]]
function Sound:GetState()
    return AudioEngine.getState(self.sInst)
end

function Sound:SetFinishHandler(fcb)
    self._cfb = function(_,str)
        if fcb then
            fcb(self,str)
        end
    end
    AudioEngine.setFinishCallback(self.sInst,self._cfb)
end

Sound.gtor({
    State = Sound.GetState,
    Duration = Sound.GetDuration,
    CurrentTime = Sound.GetCurrentTime,
    Volume = Sound.GetVolume,
    Loop = Sound.IsLoop
});

Sound.stor({
    FinishHandler = Sound.SetFinishHandler,
    CurrentTime = Sound.SetCurrentTime,
    Volume = Sound.SetVolume,
    Loop = Sound.SetLoop
});

function Sound.GetMaxAudioInstance()
    return AudioEngine.getMaxAudioInstance()
end

function Sound.SetMaxAudioInstance(max)
    AudioEngine.setMaxAudioInstance(max)
end

function Sound.Uncache(filePath)
    AudioEngine.uncache(filePath)
end

function Sound.UncacheAll()
    AudioEngine.uncacheAll()
end

--[[
    Func:   预载入声音
    Param:  string|table    声音资源|声音资源表
            function{nil}   完成回调|全部完成回调
    Desc:   若str参数为字符串，则只会预载这一个资源；
            若str参数为表，则会同时预载入所有的资源；
            若function不为nil且str为表时，回调参数第三个为当前已预载数量。
]]
function Sound.Preload(str,callBack)
    if "string" == type(str) then
        if callBack then
            AudioEngine.preload(str,function(suc)
                callBack(str,suc)
            end)
        else
            AudioEngine.preload(str)
        end
    else
        if not callBack then
            for _,v in ipairs(str) do
                AudioEngine.preload(v)
            end
        else
            local count = 0
            for _,v in ipairs(str) do
                AudioEngine.preload(v,function(suc)
                    count = count + 1
                    callBack(v,suc,count)
                end)
            end
        end
    end
end

function Sound.SetDefaultVolume(vol)
    vol = math.Limit(vol,0,1)
    UserFile().SoundDefaultVolume = vol
    Sound.DefaultVolume = vol
end

function Sound.GetDefaultVolume()
    return Sound.DefaultVolume
end

--[[
    Func:   设置是否静音
    Param:  boolean
]]
function Sound.SetSilence(b)
    b = syx.Boolean(b);
    if Sound.Silence == b then
        return
    end
    UserFile().SoundSilence = b
    Sound.Silence = b
    if b then
        Sound.StopAll()
    end
end

function Sound.GetSilence()
    return Sound.Silence
end

return Sound