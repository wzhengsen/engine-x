local function main()
    package.path = package.path .. ";src/?.lua";
    require("LuaPanda").start();
    require("Frame.Init");
    syx.Application():Start();
end

xpcall(main,function (msg)
    print(msg);
end);