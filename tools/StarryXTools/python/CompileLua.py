#!/usr/bin/env python3

import os
import sys
import getopt
import Functions
from colorama import Fore,Back,Style

def usage():
    print("将给定的源目录中的lua文件编译为luac。\n原lua文件会被删除。")
    print("-h | --help          查看帮助。")
    print("-s | --src           编译的源目录。")


def main(argv):
    src = None

    opts = Functions.GetOpt(argv,"s:",["src="],usage)
    if None == opts:
        sys.exit(1)

    for opt,arg in opts:
        if opt in ("-s","--src"):
            src = arg

    if not src:
        usage()
        sys.exit(1)

    if not Functions.CompileLua(src):
        print(Fore.LIGHTRED_EX + "\n编译Lua %s失败！" % (src) + Style.RESET_ALL)
        return False

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)