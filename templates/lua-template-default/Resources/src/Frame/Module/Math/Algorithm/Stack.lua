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

local insert = table.insert;
local ipairs = ipairs;
local min = math.min;
local remove = table.remove;
local Stack = class();
Stack.protected.stackTable = {};

function Stack:Push(...)
    local st = self.stackTable;
    for _,v in ipairs({...}) do
        insert(st,v);
    end
end

---从栈顶开始弹出，可以弹出多个。
---@param n integer 弹出的数量。
---@return nil
---@return any
function Stack:Pop(n)
    local st = self.stackTable;
    local len = #st;
    if len == 0 then
        return nil;
    end
    n = n and min(n,len) or 1;
    if n == 1 then
        return remove(st);
    elseif n > 1 then
        return Stack.Pop(self,1),Stack.Pop(self,n - 1);
    end
end

---查看栈中指定索引处的值。
---@param i integer
---@return any
function Stack:Peek(i)
    local len = #self.stackTable
    i = i or len;
    if i < 0 then
        i = len + i + 1;
    end
    return self.stackTable[i];
end

---从栈顶开始移除。
---@param n integer 移除的数量。
function Stack:Remove(n)
    local len = #self.stackTable;
    for _ = 1,min(n,len) do
        remove(self.stackTable);
    end
end

function Stack:Clear()
    self.stackTable = {};
end

function Stack:__len__()
    return #self.stackTable;
end

cc.Algorithm = cc.Algorithm or {};
cc.Algorithm.Stack = Stack;
return Stack;