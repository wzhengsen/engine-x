--[[
    File:   UserFile
    Func:   本地文件，该文件即是cc.UserDefault，使用单例
    Auth:   wzhengsen
    Data:   2019.04.04

    Chg By:     wzhengsen
    Date:       2019.07.06
    Content:    cc.UserDefault.getInstance()现在被作为成员；
                增加了Get的自动判断；
                增加了Flush()。

    Chg By:     wzhengsen
    Date:       2019.09.26
    Content:    采用继承的方式使用cc.UserDefault

    Chg By:     wzhengsen
    Date:       2019.12.05
    Content:    采用.和=操作符取值与赋值了，且不再继承自cc.UserDefault。

    Chg By:     wzhengsen
    Date:       2019.12.10
    Content:    新增了Clear()方法以清除所有数据；XmlFile重命名为UserFile。
]]
local UserFile = class(class.Singleton)

--[[
    类型前缀，每种类型均以字符串保存，并添加对应前缀
]]
UserFile.TypePrefix = {
    string  = "_@_TS",
    boolean = "_@_TB",
    number  = "_@_TN",

    -- 反向查询映射
    ["_@_TS"] = "S",
    ["_@_TB"] = "B",
    ["_@_TN"] = "N",
}

function UserFile:ctor()
    UserFile.UpdateUD(self);
    local newmt = {
        binData = {}
    }
    self.newmt = newmt
    newmt.__newindex = function(_,k,v)
        if UserFile.TypePrefix[type(k)] then
            -- 前缀查询
            UserFile.UpdateUD(self);
            local prefix = UserFile.TypePrefix[type(v)]
            if prefix then
                self.ud:setStringForKey(tostring(k),prefix .. tostring(v))
                -- 此处保存一个缓存在内存中
                rawset(newmt.binData,k,v)
            elseif v == nil then
                self.ud:deleteValueForKey(k)
                rawset(newmt.binData,k,v)
            else
                print("UserFile can't set the value.")
            end
        else
            print("UserFile can't set the value.")
        end
    end
    newmt.__index = function(_,k)
        local ret = rawget(newmt.binData,k)
        -- 先判断缓存值
        if nil ~= ret then
            return ret
        end

        -- 再查找文件
        UserFile.UpdateUD(self);
        ret = self.ud:getStringForKey(k,"")
        if "" ~= ret then
            local vType = UserFile.TypePrefix[ret:sub(1,5)]
            -- 查询前缀
            if vType == "N" then
                ret = tonumber(ret:sub(6))
            elseif vType == "S" then
                ret = ret:sub(6)
            elseif vType == "B" then
                local retV = ret:sub(6)
                if retV == "true" then
                    ret = true
                elseif retV == "false" then
                    ret = false
                else
                    ret = nil
                end
            end
            -- 缓存
            rawset(newmt.binData,k,ret)
            return ret
        end

        -- 最后查找原类型
        ret = UserFile[k]
        if nil ~= ret then
            return ret
        end
        return nil
    end
    setmetatable(self,newmt)
end

function UserFile:UpdateUD()
    if class.IsNull(rawget(self,"ud")) then
        rawset(self,"ud",cc.UserDefault.getInstance());
    end
end

function UserFile:Flush()
    UserFile.UpdateUD(self);
    self.ud:flush()
end

--[[
    Func:   清空xml文件
]]
function UserFile:Clear()
    UserFile.UpdateUD(self);
    self.ud:Clear()
    self.newmt.binData = {}
end

return UserFile