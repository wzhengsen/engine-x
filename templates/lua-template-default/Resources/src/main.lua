xpcall(
function()
    require("src.LuaPanda").startServer();
end,
function(msg)
    print(msg);
end);

package.path = package.path .. ";src/?.lua";
require("Frame.Init");

local function main()
    syx.Application():Start();
end
main();