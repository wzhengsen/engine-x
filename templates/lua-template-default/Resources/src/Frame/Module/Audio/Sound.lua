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
local Sound = class();

Sound.static.State = enum {
    Error  = -1,
    Initialzing = 0,
    Playing = 1,
    Paused = 2
};
-- 指示获取的持续时间是否是未知的。
Sound.static.UnkownTime = AudioEngine.TIME_UNKNOWN;
Sound.static.protected._DefaultVolume = math.Limit(UserFile.SoundDefaultVolume or 0.8,0,1);
Sound.static.protected._Silence = UserFile.SoundSilence or false;

Sound.protected.sInst = AudioEngine.INVALID_AUDIO_ID;
Sound.protected.sFilePath = nil;
Sound.protected.sLoop = false;
Sound.protected.sVol = Sound.DefaultVolume;

---构造一个声音对象。
---@param filePath string 声音路径。
---@param loop? boolean {false}循环。
---@param vol? number {Sound.DefaultVolume} 音量0-1。
function Sound:ctor(filePath,loop,vol)
    self.sFilePath = filePath;
    if loop then
        self.sLoop = loop;
    end
    self.sVol = vol and math.Limit(vol,0,1) or Sound.DefaultVolume;
end


---@param force boolean 是否强制结束当前的播放，而重新开始。
---@return boolean
function Sound:Play(force)
    if Sound.Silence then
        return false;
    end

    if self.sInst ~= AudioEngine.INVALID_AUDIO_ID then
        local state = self:GetState();
        if state == Sound.State.Playing
        or state == Sound.State.Paused then
            if force then
                self:Stop();
            else
                -- 播放状态和暂停状态下不能再次播放
                return false;
            end
        end
    end

    self.sInst = AudioEngine.Play2d(self.sFilePath,self.sLoop,self.sVol);
    if self.sInst == AudioEngine.INVALID_AUDIO_ID then
        return false;
    end

    if self._cfb then
        -- 再次Play时将回调绑定至新的声音句柄
        AudioEngine.SetFinishCallback(self.sInst,self._cfb);
    end
    return true;
end

function Sound.set:Loop(loop)
    self._sLoop = loop;
    AudioEngine.SetLoop(self._sInst,loop);
end

function Sound.get:Loop()
    return AudioEngine.IsLoop(self._sInst);
end

function Sound.set:Volume(vol)
    self._sVol = math.Limit(vol,0,1);
    AudioEngine.SetVolume(self._sInst,vol);
end

function Sound.get:Volume()
    return AudioEngine.GetVolume(self._sInst);
end

function Sound:Pause()
    AudioEngine.Pause(self.sInst);
end

function Sound:Resume()
    AudioEngine.Resume(self.sInst);
end

function Sound:Stop()
    AudioEngine.Stop(self.sInst);
    --停止后，当前句柄将不可用
    self.sInst = AudioEngine.INVALID_AUDIO_ID;
end

Sound.static.PauseAll = AudioEngine.PauseAll;
Sound.static.ResumeAll = AudioEngine.ResumeAll;
Sound.static.StopAll = AudioEngine.StopAll;
Sound.static.get.MaxAudioInstance = AudioEngine.GetMaxAudioInstance;
Sound.static.set.MaxAudioInstance = AudioEngine.SetMaxAudioInstance;
Sound.static.Uncache = AudioEngine.Uncache;
Sound.static.UncacheAll = AudioEngine.UncacheAll;

---设置音效的当前时间。
---@param dt number
---@return boolean
function Sound.set:CurrentTime(dt)
    return AudioEngine.SetCurrentTime(self._sInst,dt);
end

function Sound.get:CurrentTime()
    return AudioEngine.GetCurrentTime(self._sInst);
end

function Sound.get:Duration()
    return AudioEngine.GetDuration(self._sInst);
end

---@alias Sound.State integer
---获取当前音效状态。
---@return Sound.State
function Sound.get:State()
    return AudioEngine.GetState(self._sInst);
end

function Sound.set:FinishHandler(fcb)
    self.cfb = function(_,str)
        if fcb then
            fcb(self,str)
        end
    end;
    AudioEngine.SetFinishCallback(self._sInst,self.cfb);
end

---预载入声音。
---@param sounds table
---@param callBack? function
function Sound.static.Preload(sounds,callBack)
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

function Sound.static.set.DefaultVolume(vol)
    vol = math.Limit(vol,0,1);
    UserFile.SoundDefaultVolume = vol;
    Sound._DefaultVolume = vol;
end

function Sound.static.get.DefaultVolume()
    return Sound._DefaultVolume;
end

function Sound.static.set.Silence(b)
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

function Sound.static.get.Silence()
    return Sound._Silence;
end

function Sound:dtor()
    self:Stop();
end

cc.Sound = Sound;
return Sound;