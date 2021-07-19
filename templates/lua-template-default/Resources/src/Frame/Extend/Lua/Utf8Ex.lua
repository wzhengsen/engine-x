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

local ulen = utf8.len;
local ucodepoint = utf8.codepoint;
local uchar = utf8.char;
local uoffset = utf8.offset;

---迭代utf8字符串。
---@param str string
---@return function
function utf8.ipairs(str)
    local len,idx = ulen(str);
    if not len then
        -- 当找到任意不合法的utf8码点时，截取前段合法部分。
        len = ulen(str:sub(1,idx - 1));
    end

    idx = 0;
    return function ()
        idx = idx + 1
        if idx > len then
            return nil,nil;
        end
        return idx,uchar(ucodepoint(str,uoffset(str,idx)));
    end
end