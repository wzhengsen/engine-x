xpcall(
function()
    require("src.LuaPanda").start();
end,
function(msg)
    print(msg);
end);

local function main()
    package.path = package.path .. ";src/?.lua";
    require("Frame.Init");
    syx.Application():Start();
end
xpcall(main,
function(msg)
    print(msg);
end);