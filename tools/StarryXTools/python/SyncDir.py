#!/usr/bin/env python3

import os
import sys
import getopt
import Functions
from colorama import Fore, Back, Style


def usage():
    print("将源目录同步到目标目录。\n最后修改时间或大小不同的文件，才会被覆盖。")
    print("-h | --help          查看帮助。")
    print("-s | --src           同步的源目录。")
    print("-d | --dst           同步的目标目录。")
    print("-e | --exclude       排除的文件或目录。")


def main(argv):
    src = None
    dst = None

    opts = Functions.GetOpt(
        
        
        
        argv, "s:d:e:", ["src=", "dst=", "exclude="], usage)
    if None == opts:
        sys.exit(1)

    eList = []
    for opt, arg in opts:
        if opt in ("-s", "--src"):
            src = arg
        elif opt in ("-d", "--dst"):
            dst = arg
        elif opt in ("-e", "--exclude"):
            eList.append(arg)

    if not src or not dst:
        usage()
        sys.exit(1)

    if not Functions.SyncDir(src, dst, eList):
        print(Fore.LIGHTRED_EX + "\n同步文件夹%s到%s失败！" %
              (src, dst) + Style.RESET_ALL)
        return False
    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
