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
    Date:   2020.08.15
    Desc:   重写一些lua库函数。
]]

if os.Windows then
    local _print = print;
    function print(...)
        local convert = {};
        for _,arg in pairs({...}) do
            table.insert(convert,tostring(arg):Convert("gbk//TRANSLIT","utf-8") or arg);
        end
        _print(table.unpack(convert));
    end

    local _dofile = dofile;
    function dofile(filename)
        if filename then
            filename = filename:Convert("gbk//TRANSLIT","utf-8");
        end
        return _dofile(filename);
    end;

    local _loadfile = loadfile;
    function loadfile(filename,...)
        if filename then
            filename = filename:Convert("gbk//TRANSLIT","utf-8");
        end
        return _loadfile(filename,...);
    end;
end