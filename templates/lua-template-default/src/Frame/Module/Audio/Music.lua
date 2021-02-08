--[[
    File:   Music
    Desc:   继承自Sound，由于背景音乐的特性，该类使用单例；
            某些Sound方法在继承后将不可被Music访问
]]

local UserFile = require("Utils.UserFile")
local Sound = require("Audio.Sound")
local Music = class(Sound,class.Singleton)

--[[
    禁止访问的方法
]]
local forbiddenMethod = function()
    error("Forbidden!")
end
Music.PauseAll              = forbiddenMethod
Music.ResumeAll             = forbiddenMethod
Music.StopAll               = forbiddenMethod
Music.Uncache               = forbiddenMethod
Music.UncacheAll            = forbiddenMethod
Music.Preload               = forbiddenMethod
Music.GetMaxAudioInstance   = forbiddenMethod
Music.SetMaxAudioInstance   = forbiddenMethod
Music.SetLoop               = forbiddenMethod
Music.IsLoop                = forbiddenMethod

-- 音乐静音选项
Music.Silence = UserFile().MusicSilence or false

-- 音乐播放模式
Music.Mode = {
    -- 单曲单次
    SingleOnce = {},
    -- 单曲循环
    SingLoop = {},
    -- 列表随机
    ListRandom = {},
    -- 列表循环
    ListLoop = {}
}

function Music:ctor()
    Sound.ctor(self)
    self.sVol = math.Limit(Music.GetDefaultVolume(),0,1)
    self.sFilePath = ""
    self.playList = {}
    self.playMode = Music.Mode.ListLoop

    -- 当前播放序列
    self.curPlayIndex = nil
    self._cfb = function(_,str)
        if self._mcfb then
            self:_mcfb(str)
        end

        if self.playMode == Music.Mode.ListRandom
        or self.playMode == Music.Mode.ListLoop then
            self:Next()
        end
    end
end

--[[
    Func:   设置播放列表
    Param:  table               背景音乐只会播放列表中的文件
            boolean{false}      是否预载
]]
function Music:SetList(pList,bPreload)
    self.playList = pList
    if bPreload then
        Sound.Preload(pList)
    end
end

function Music:GetList()
    return self.playList
end

--[[
    Func:   设置播放模式
    Param:  table{Music.Mode}
]]
function Music:SetMode(mode)
    self.playMode = mode
end

function Music:GetMode()
    return self.playMode
end

--[[
    Func:   播放下一首
    Return: boolean     是否成功切换至下一首
]]
function Music:Next()
    self:Stop()
    local listLen = self.playList and #self.playList or 0
    if listLen == 0 then return false end

    self.sLoop = self.playMode == Music.Mode.SingleLoop
    if not self.curPlayIndex or self.curPlayIndex >= listLen then
        self.curPlayIndex = 1
    else
        if self.playMode == Music.Mode.ListRandom then
            -- 列表随机采用随机模式
            self.curPlayIndex = math.random(1,listLen)
        else
            self.curPlayIndex = self.curPlayIndex + 1
        end
    end

    self.sFilePath = self.playList[self.curPlayIndex]
    return self:Play()
end

function Music:Play(...)
    if Music.GetSilence() then
        return false
    end
    if not self.curPlayIndex then
        return self:Next()
    end
    return Sound.Play(self,...)
end

function Music:SetFinishHandler(fcb)
    self._mcfb = fcb
end

function Music.SetDefaultVolume(vol)
    vol = math.Limit(vol,0,1)
    UserFile().MusicDefaultVolume = vol
    Music.DefaultVolume = vol
end

function Music.GetDefaultVolume()
    local dVol = rawget(Music,"DefaultVolume") or UserFile().MusicDefaultVolume or Sound.DefaultVolume or 0.8
    Music.DefaultVolume = dVol
    return dVol
end

--[[
    Func:   设置是否静音
    Param:  boolean
]]
function Music.SetSilence(b)
    b = syx.Boolean(b);
    if Music.Silence == b then
        return
    end
    UserFile().MusicSilence = b
    Music.Silence = b
    if b then
        Music():Stop()
    end
end

function Music.GetSilence()
    -- 主音量或音乐音量任意一个静音，都为静音
    return Sound.Silence or Music.Silence
end


return Music