#!/usr/bin/env python3

import os
import sys
import getopt
import Functions
from colorama import Fore,Back,Style
import platform

def usage():
    print("以aes-cfb-128的方式加密给定的源目录中的png/lua文件。")
    print("-h | --help          查看帮助。")
    print("-s | --src           需要被加密的源目录。")
    print("-p | --pwd           加密密码，小于等于16字节，不足部分补\\0。")

def main(argv):
    src = None
    pwd = None

    opts = Functions.GetOpt(argv,"s:p:",["src=","pwd="],usage)
    if None == opts:
        sys.exit(1)

    for opt,arg in opts:
        if opt in ("-s","--src"):
            src = arg
        elif opt in ("-p","--pwd"):
            pwd = arg

    if not src or not pwd:
        usage()
        sys.exit(1)

    if not Functions.EncryptRes(src,pwd):
        print(Fore.LIGHTRED_EX + "\n加密 %s失败！" % (src) + Style.RESET_ALL)
        return False

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)