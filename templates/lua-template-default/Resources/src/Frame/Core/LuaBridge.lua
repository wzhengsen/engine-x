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

--[[
    Auth:   wzhengsen
    Date:   2020.10.02
    Desc:   重新实现luaj/luaoc，统一为LuaBridge实现。

    Chg By:     wzhengsen
    Date:       2020.10.16
    Content:    LuaBridge不再需要显式指明返回类型了，且支持java静态方法重载。

    Chg By:     wzhengsen
    Date:       2020.11.10
    Content:    LuaBridge支持oc静态方法重载；
                LuaBridge可以直接传递多个参数了（仍然可以使用表传递）。

    Chg By:     wzhengsen
    Date:       2020.11.11
    Content:    LuaBridge在Android下不再将参数包装为表，现在使用变长参数直接传递。

    用例：
        调用空返回值方法：
        前提：
            ClassName中存在ATestVoidRetMethod静态方法。
        使用：
            LuaBridge.ATestVoidRetMethod();

        调用布尔返回值方法，且接受2个参数：
        前提：
            ClassName中存在ATestBoolRetMethod(long,double)静态方法。
            或存在+(BOOL)ATestBoolRetMethod:(long)l :(double)d
        使用：
            local i = 10;
            local d = 200;
            return LuaBridge.ATestBoolRetMethod(i,d);

    参数及返回值：
        Lua->Java参数：
            number(integer)->long
            number(float)->double/float
            string->String
            boolean->boolean
            function->int

        Lua->Objc参数：
            number(integer)->long
            number(float)->double
            string->NSString*
            boolean->BOOL
            function->int
            table->NSDictionary*    该表的键将使用string类型，
                                    键类型被转换为NSString*；
                                    值类型中的number/boolean/function类型被转换为NSNumber*。

        Java->lua返回值：
            long->number(integer)
            int->number(integer)
            short->number(integer)
            byte->number(integer)
            double->number(float)
            float->number(float)
            String->string
            boolean->boolean

        Objc->lua返回值：
            long->number(integer)
            int->number(integer)
            short->number(integer)
            char->number(integer)
            double->number(float)
            float->number(float)
            NSString*->string
            BOOL->boolean
            NSDictionary*->table

]]
local LuaBridge = {
    Error = enum {
        OK = 0,
        InvalidParameters = -1,
        ClassNotFound = -2,
        MethodNotFound = -3,
        ExceptionOccurred = -4,
        InvalidSignature = -5
    }
};

rawset(_G,"LuaBridge",LuaBridge);

if not os.android and not os.apple then
    return LuaBridge;
end


local type = type;
local math = math;
local table = table;
local ipairs = ipairs;
local print = print;
local setmetatable = setmetatable;

local ClassName = os.android and "org.cocos2dx.lib.Cocos2dxHelper" or "Cocos2dxHelper";
local CallStaticMethod = (os.android and LuaJavaBridge or LuaObjcBridge).callStaticMethod;
local CheckMethodSign = nil;

if os.android then
    local JavaReturnSignMap = {
        double = "D",
        long = "J",
        boolean = "Z",
        void = "V",
        byte = "C",
        short = "S",
        int = "I",
        float = "F",
        ["java.lang.String"] = "Ljava/lang/String;"
    };
    local JavaParamSignMap = {
        double = "D",
        float = "F",
        long = "J",
        boolean = "Z",
        int = "I",
        ["java.lang.String"] = "Ljava/lang/String;"
    };
    local JavaMethods = {};


    CheckMethodSign = function (methodName, ...)
        local method = JavaMethods[methodName];
        if not method then
            return LuaBridge.Error.MethodNotFound,nil;
        end
        local args = {...};
        local fitIndex = nil;
        for idx,sign in ipairs(method) do
            local paramFit = true;
            -- 数值类型转换后可匹配签名。
            local numberConvertFit = false;
            local l = #args;
            if l ~= #sign - 1 then
                goto continue;
            end

            for i = 1,l do
                local ps = sign[i];
                local v = args[i];
                if (ps == "Ljava/lang/String;" and type(v) ~= "string") or
                (ps == "Z" and type(v) ~= "boolean") or
                (ps == "I" and type(v) ~= "function") then
                    paramFit = false;
                    break;
                elseif (ps == "J" or ps == "D" or ps == "F") then
                    if type(v) == "number" then
                        -- 匹配数值类型。
                        numberConvertFit = true;
                        local numberType = math.type(v);
                        if (ps == "J" and numberType ~= "integer") or
                        ((ps == "D" or ps == "F") and numberType ~= "float") then
                            paramFit = false;
                            break;
                        end
                    else
                        paramFit = false;
                        break;
                    end
                end
            end
            if paramFit or numberConvertFit then
                fitIndex = idx;
                if paramFit then
                    break;
                end
            end
            ::continue::;
        end

        if fitIndex then
            return nil,method[fitIndex].sign;
        end
        return LuaBridge.Error.InvalidSignature,nil;
    end;


    local ok,ret = CallStaticMethod(ClassName,"GetStaticMethodsSignature","()Ljava/lang/String;");
    if not ok then
        error("GetStaticMethodsSignature failed!");
    end
    local signatures = ret:split("\n");
    for _,s in ipairs(signatures) do
        local paramTypes = s:split(";");
        local methodName = table.remove(paramTypes);
        local returnType = table.remove(paramTypes);
        local sign = {"("};
        local signTable = {};

        -- 签名类型检查，不合法签名的方法都不记录。
        for _,pt in ipairs(paramTypes) do
            local ps = JavaParamSignMap[pt];
            if not ps then
                goto continue;
            end
            table.insert(sign,ps);
            table.insert(signTable,ps);
        end
        table.insert(sign,")");

        local rs = JavaReturnSignMap[returnType];
        if not rs then
            goto continue;
        end
        table.insert(sign,rs);
        table.insert(signTable,rs);
        signTable.sign = table.concat(sign);

        local methodTable = JavaMethods[methodName] or {};
        JavaMethods[methodName] = methodTable;
        table.insert(methodTable,signTable);
        ::continue::;
    end
end

local methodMeta = {};

methodMeta.__call = function(t,...)
    local methodName = t._methodName;
    local ok,ret,sign = nil,nil,nil;
    if os.android then
        ret,sign = CheckMethodSign(methodName,...);
        if not ret then
            ok,ret = CallStaticMethod(ClassName,methodName,sign,...);
        end
    else
        ok,ret = CallStaticMethod(ClassName,methodName,...);
    end
    if not ok then
        print(("CallStaticMethod(\"%s\", \"%s\") - error: [%d]"):format(
            ClassName,methodName,ret
        ));
    end
    -- 交换返回顺序。
    return ret,ok;
end;

setmetatable(LuaBridge,{
    __index = function(t,k)
        if "string" == type(k) then
            local method = {
                _methodName = k
            };
            t[k] = method;
            setmetatable(method,methodMeta);
            return method;
        end
    end
});

return LuaBridge;