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

local Sound = require("Audio.Sound");
local UserFile = require("Utils.UserFile");
---继承自Sound，由于背景音乐的特性，该类使用单例；
---某些Sound方法在继承后将不可被Music访问。
local Music = class(Sound);

--[[
    禁止访问的方法
]]
local forbiddenMethod = function()
    error("Forbidden!");
end
Music.static.private.PauseAll              = forbiddenMethod;
Music.static.private.ResumeAll             = forbiddenMethod;
Music.static.private.StopAll               = forbiddenMethod;
Music.static.private.Uncache               = forbiddenMethod;
Music.static.private.UncacheAll            = forbiddenMethod;
Music.static.private.Preload               = forbiddenMethod;
Music.static.private.GetMaxAudioInstance   = forbiddenMethod;
Music.static.private.SetMaxAudioInstance   = forbiddenMethod;
Music.private.set.Loop                     = forbiddenMethod;
Music.private.get.Loop                     = forbiddenMethod;

Music.static.protected._DefaultVolume = UserFile.MusicDefaultVolume and math.limit(cc.ToInteger(UserFile.MusicDefaultVolume),0,1) or Sound.DefaultVolume or 0.8;
Music.static._Silence = UserFile.MusicSilence or false;

-- 音乐播放模式
Music.static.PlayMode = enum {
    -- 单曲单次
    SingleOnce = {},
    -- 单曲循环
    SingleLoop = {},
    -- 列表随机
    ListRandom = {},
    -- 列表循环
    ListLoop = {}
};

Music.protected.sVol = math.limit(Music.DefaultVolume,0,1);
Music.protected.sFilePath = "";
Music.protected.playList = {};
Music.protected.playMode = Music.PlayMode.ListLoop;
-- 当前播放序列
Music.protected.curPlayIndex = nil;
Music.private.mcfb = nil;
function Music:ctor()
    Sound.ctor(self)
    self.sVol = math.limit(Music.DefaultVolume,0,1);
    self.cfb = function(_,str)
        if self.mcfb then
            self:mcfb(str);
        end

        if self.playMode == Music.PlayMode.ListRandom
        or self.playMode == Music.PlayMode.ListLoop then
            self:Next();
        end
    end
end

function Music.__singleton__()
    return Music.new();
end

---设置播放列表。
---@param pList table 背景音乐只会播放列表中的文件。
---@param bPreload? boolean {false} 是否预载。
function Music:SetList(pList,bPreload)
    self.playList = pList;
    if bPreload then
        Sound.Preload(pList);
    end
end

Music.set.List = Music.SetList;

function Music.get:List()
    return self.playList;
end

---@alias Music.PlayMode integer
---设置播放模式
---@param mode Music.PlayMode
function Music.set:Mode(mode)
    self.playMode = mode;
end

function Music.get:Mode()
    return self.playMode;
end

---播放下一首。
---@return boolean 是否成功切换至下一首。
function Music:Next()
    self:Stop();
    local listLen = self.playList and #self.playList or 0;
    if listLen == 0 then return false; end

    self.sLoop = self.playMode == Music.PlayMode.SingleLoop;
    if not self.curPlayIndex or self.curPlayIndex >= listLen then
        self.curPlayIndex = 1;
    else
        if self.playMode == Music.PlayMode.ListRandom then
            -- 列表随机采用随机模式
            self.curPlayIndex = math.random(1,listLen);
        else
            self.curPlayIndex = self.curPlayIndex + 1;
        end
    end

    self.sFilePath = self.playList[self.curPlayIndex];
    return self:Play();
end

function Music:Play(...)
    if Music.Silence then
        return false;
    end
    if not self.curPlayIndex then
        return self:Next();
    end
    return Sound.Play(self,...);
end

function Music.set:FinishHandler(fcb)
    self.mcfb = fcb;
end

function Music.static.set.DefaultVolume(vol)
    vol = math.limit(vol,0,1);
    UserFile.MusicDefaultVolume = vol;
    Music._DefaultVolume = vol;
end

function Music.get.DefaultVolume()
    return Music._DefaultVolume;
end

function Music.static.set.Silence(b)
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

function Music.static.get.Silence()
    -- 主音量或音乐音量任意一个静音，都为静音
    return Sound.Silence or Music._Silence;
end

cc.Music = Music;
return Music;