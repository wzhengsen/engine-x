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


local type = type;
local table = table;
local insert = table.insert;
local remove = table.remove;
local next = next;

-- 重写一些lua库函数和增加一些库函数。

---遍历表，且可遍历嵌套表，返回3个值：当前表，当前键，当前值。
---不会触发__pairs元方法。
---@param t table
---@return function
function _G.apairs(t)
    local curTable = t;
    -- 记录即将被遍历的表。
    local tabList = {};
    local key,val = nil,nil;
    return function ()
        ::begin::
        key,val = next(curTable,key);
        if "table" == type(val) then
            insert(tabList,val);
        end
        if nil == key then
            if #tabList > 0 then
                curTable = remove(tabList);
                goto begin;
            else
                curTable = nil;
            end
        end
        return curTable,key,val;
    end
end

---以不会触发__pairs元方法的方式遍历表。
---@param t table
---@return function
function _G.rpairs(t)
    local key,value = nil,nil;
    return function ()
        key,value = next(t,key);
        return key,value;
    end
end

if os.windows then
    local _dofile = dofile;
    function dofile(filename)
        if filename then
            filename = filename:convert("utf-8","gbk//TRANSLIT");
        end
        return _dofile(filename);
    end

    local _loadfile = loadfile;
    function loadfile(filename,...)
        if filename then
            filename = filename:convert("utf-8","gbk//TRANSLIT");
        end
        return _loadfile(filename,...);
    end
end