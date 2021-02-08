#!/usr/bin/env python3

import os
import sys
import getopt
import Functions


def usage():
    print("构建Apple CMake工程。")
    print("--type           可选类型：\n    Mac应用\n    Ios应用")


def main(argv):
    sType = "Mac应用"

    opts = Functions.GetOpt(argv, "", ["type="], usage)
    if None == opts:
        sys.exit(1)

    for opt, arg in opts:
        if opt == "--type":
            sType = arg

    platform = ""
    cmd = ""

    if sType == "Mac应用":
        platform = "mac"
        cmd = "cmake ../.. -GXcode"
    elif sType == "Ios应用":
        platform = "ios"
        cmd = "cmake ../.. -GXcode -DCMAKE_SYSTEM_NAME=iOS -DCMAKE_OSX_SYSROOT=iphoneos"

    platformDir = "build/" + platform
    Functions.SyncDir("Resources", "build/Resources")
    if not os.path.exists("build/Resources/Version"):
        os.makedirs("build/Resources/Version")
    if not os.path.exists(platformDir):
        os.makedirs(platformDir)
    os.chdir(platformDir)

    os.system(cmd)

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
