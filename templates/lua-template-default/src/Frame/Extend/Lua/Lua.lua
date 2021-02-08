--[[
    Auth:   wzhengsen
    Date:   2020.08.15
    Desc:   重写一些lua库函数。
]]

if os.IsWindows() then
    local _dofile = dofile;
    function dofile(filename)
        if filename then
            filename = filename:Convert("gb2312//TRANSLIT","utf-8");
        end
        return _dofile(filename);
    end;

    local _loadfile = loadfile;
    function loadfile(filename,...)
        if filename then
            filename = filename:Convert("gb2312//TRANSLIT","utf-8");
        end
        return _loadfile(filename,...);
    end;
end