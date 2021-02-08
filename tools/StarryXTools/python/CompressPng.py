#!/usr/bin/env python3

import os
import sys
import getopt
import Functions
from colorama import Fore,Back,Style

def usage():
    print("压缩给定的源目录中的png文件。\n原文件会被压缩后的文件覆盖。")
    print("-h | --help          查看帮助。")
    print("-s | --src           需要被压缩的源目录。")
    print("-q | --quality       压缩质量，0-100，默认50-85。")

def main(argv):
    src = None
    qMin = 50
    qMax = 85

    opts = Functions.GetOpt(argv,"s:q:",["src=","quality="],usage)
    if None == opts:
        sys.exit(1)

    for opt,arg in opts:
        if opt in ("-s","--src"):
            src = arg
        elif opt in ("-q","--quality"):
            qL = arg.split("-")
            qMin,qMax = int(qL[0]),int(qL[1])

    if not src:
        usage()
        sys.exit(1)

    if not Functions.CompressPng(src,qMin=qMin,qMax=qMax):
        print(Fore.LIGHTRED_EX + "\n压缩 %s失败！" % (src) + Style.RESET_ALL)
        return False

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)