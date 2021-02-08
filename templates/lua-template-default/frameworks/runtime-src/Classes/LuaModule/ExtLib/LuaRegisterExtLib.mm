#include "ExtLib/LuaRegisterExtLib.h"
#include "OO_Lua/OO_Lua.hpp"
#import <UIKit/UIPasteboard.h>

using namespace OO_Lua;

int Lua_os_GetClipboard(lua_State* L) {
    const auto lua = Lua(L);
    UIPasteboard* pBoard = [UIPasteboard generalPasteboard];
    if(pBoard != NULL) {
        NSString* pNsStr = pBoard.string;
        if(pNsStr != NULL) {
            lua.Push([pNsStr cStringUsingEncoding:(NSUTF8StringEncoding)]);
            return 1;
        }
    }

    lua.Push("");
    return 1;
}
int Lua_os_SetClipboard(lua_State* L) {
    const auto lua = Lua(L);
    UIPasteboard* pBoard = [UIPasteboard generalPasteboard];
    const char* str = lua.CheckString(1);
    pBoard.string = [[NSString alloc] initWithCString:(const char*)str encoding:NSUTF8StringEncoding];
    return 0;
}
