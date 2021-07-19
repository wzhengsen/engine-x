-- Copyright (c) 2021 wzhengsen

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:

-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.

---用于存储数据到指定文件，可以指定密码，默认使用AES加密。
local LocalFile = class();

LocalFile.private.key = nil;
LocalFile.private.path = nil;
LocalFile.private.FILE = nil;
LocalFile.private.fileData = {};

---@param path string 存储文件的路径。
---@param key? string 如果必要，该文件的密码。
function LocalFile:ctor(path,key)
    self.key = key;
    self.path = path;

    -- 避免同时操作文件，此处保持文件独占打开，需要Close
    self:Open();
end

---打开或重新打开文件。
---构造时会自动调用，一般用于Close后重新打开文件；
---文件关闭后，对文件的操作都不会保存，重新打开后，在文件关闭期间的修改都会丢失。
---@return boolean
function LocalFile:Open()
    if self.FILE then
        return false;
    end
    local path = self.path;
    local file = io.open(path, "rb") or io.open(path, "w+b");
    if not file then
        return false;
    end
    self.FILE = file;

    local fileContent = file:read("a");
    if self.key then
        -- 存在密码先解密。
        fileContent = fileContent:decrypt(self.key);
    end
    -- 尝试json解码。
    fileContent = cjson.decode(fileContent);
    if fileContent then
        for tab,key,val in apairs(fileContent) do
            -- 对可能是函数的类型反序列化。
            if "string" == type(val) and "_@_TF" == val:sub(1,5) then
                local func = load(val:sub(6));
                if func then
                    tab[key] = func;
                end
            end
        end
    end
    self.fileData = fileContent or {};
    return true;
end

---将数据Flush到文件。
---
function LocalFile:Flush()
    local file = self.FILE;
    if not file then
        return;
    end
    local fileData = self.fileData;
    for tab,key,val in apairs(fileData) do
        -- 对函数序列化，并加入前缀。
        if "function" == type(val) then
            tab[key] = "_@_TF" .. string.dump(val);
        end
    end
    local tabStr = cjson.encode(fileData);
    if tabStr then
        if self.key then
            tabStr = tabStr:encrypt(self.key);
        end
        -- 关闭原句柄。
        file:close();

        -- 清空文件。
        file = io.open(self.path, "w+b")
        -- 写入数据。
        file:write(tabStr)
        file:flush();
        self.FILE = file;
    end
end

---关闭文件。
---@param b? boolean {true}指示调用Flush。
function LocalFile:Close(b)
    local file = self.FILE;
    if not file then
        return;
    end
    if b == nil or b then
        self:Flush();
    end
    self.FILE:close();
    self.FILE = nil;
end

---清除文件内容。
---
function LocalFile:Clear()
    local file = self.FILE;
    if file then
        file:close();
        file = io.open(self.path, "w+b");
        self.FILE = file;
        self.fileData = {};
    end
end

function LocalFile.get:Data()
    return self.FILE and self.fileData or {};
end

function LocalFile.get:Valid()
    return nil ~= self.FILE;
end

---析构时自动关闭。
function LocalFile:dtor()
    self:Close()
end

---垃圾回收时自动关闭。
function LocalFile:__gc__()
    self:Close();
end

---离开作用域时自动关闭。
function LocalFile:__close__()
    self:Close();
end

cc.LocalFile = LocalFile;
return LocalFile;