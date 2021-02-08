--[[
    File:   LocalFile
    Func:   用于存储数据到指定文件，可以指定密码，默认使用AES加密。
    Date:   2019.12.11
    Auth:   wzhengsen
]]
local LocalFile = class()

--[[
    Param:  string          存储文件的路径。
            string{nil}     如果必要，该文件的密码。
    Desc:   __pd,__path,__FILE,__fileData字段将被保留，不要将其赋值。
]]
function LocalFile:ctor(path,password)
    assert(type(path) == "string" and path ~= "", "Path is invaild.")
    assert(cc.FileUtils.getInstance():isAbsolutePath(path),"Relative Path was forbidden!")

    self.__pd = password
    self.__path = path
    self.__fileData = {}

    -- 避免同时操作文件，此处保持文件独占打开，需要Close
    self:Open()

    -- 重定向存取数据到fileData
    setmetatable(self,{
        __newindex = function(t,k,v)
            t.__fileData[k] = v
        end,
        __index = function(t,k)
            return t.__fileData[k] or LocalFile[k]
        end,
        -- 若在使用完成后未关闭，将在__gc时自动关闭。
        __gc = self.dtor,
        __close = function(self)
            self:Close();
        end
    })
end


--[[
    Func:   打开一个文件以操作
    Return: boolean
    Desc:   构造时会自动调用，一般用于Close后重新打开文件；
            文件关闭后，对文件的操作都不会保存，重新打开后，在文件关闭期间的修改都会丢失。
]]
function LocalFile:Open()
    local path = self.__path
    local file = io.open(path, "rb")
    if not file then
        file = io.open(path, "w+b")
        if not file then
            return false
        end
    end

    rawset(self,"__FILE",file)

    file = file:read("a")
    if self.__pd then
        -- 存在密码先解密
        file = file:Decrypt(self.__pd)
    end
    -- 尝试json解码
    file = cjson.decode(file)
    self.__fileData = file or {}
    return true
end

--[[
    Func:   将数据Flush
]]
function LocalFile:Flush()
    local fileData = self.__fileData
    local file = rawget(self,"__FILE")
    if file and fileData then
        local tabStr = cjson.encode(fileData)
        if tabStr then
            if self.__pd then
                tabStr = tabStr:Encrypt(self.__pd)
            end
            -- 关闭原句柄
            file:close()

            -- 清空文件
            file = io.open(self.__path, "w+b")
            -- 写入数据
            file:write(tabStr)
            file:flush()
            rawset(self,"__FILE",file)
        end
    end
end

--[[
    Func:   关闭文件
    Param:  boolean{true}     指示调用Flush
    Desc:   内部会调用Flush，且清空__FILE
]]
function LocalFile:Close(b)
    local file = rawget(self,"__FILE")
    if not file then
        return;
    end
    b = b == nil or b
    if b then
        self:Flush()
        file = rawget(self,"__FILE")
    end
    file:close()
    rawset(self,"__FILE",nil)
end


--[[
    Func:   清除文件
]]
function LocalFile:Clear()
    local file = rawget(self,"__FILE")
    if file then
        file:close()
        file = io.open(self.__path, "w+b")
        rawset(self,"__FILE",file)
        self.__fileData = {}
    end
end

--[[
    Desc:       获得内部数据。
    Return:     table
]]

function LocalFile:GetData()
    return self.__fileData;
end

--[[
    析构时自动关闭
]]
function LocalFile:dtor()
    self:Close()
end


return LocalFile