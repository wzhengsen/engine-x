#!/usr/bin/env python3
# Copyright (c) 2021 - wzhengsen

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

import sys
import Functions


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
        print("\n同步文件夹{}到{}失败！".format(src, dst))
        return False
    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
