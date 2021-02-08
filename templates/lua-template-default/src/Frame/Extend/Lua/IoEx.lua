--[[
    Auth:   wzhengsen
    Date:   2020.08.15
    Desc:   重写一些lua io库函数。
]]

if os.IsWindows() then
    local _open = io.open;
    function io.open(filename,...)
        filename = filename:Convert("gb2312//TRANSLIT","utf-8");
        return _open(filename,...);
    end

    local _popen = io.popen;
    function io.popen(prog,...)
        prog = prog:Convert("gb2312//TRANSLIT","utf-8");
        return _popen(prog,...);
    end
end