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
    print("压缩给定的源目录中的png文件。\n原文件会被压缩后的文件覆盖。")
    print("-h | --help          查看帮助。")
    print("-s | --src           需要被压缩的源目录。")
    print("-q | --quality       压缩质量，0-100，默认50-85。")


def main(argv):
    src = None
    qMin = 50
    qMax = 85

    opts = Functions.GetOpt(argv, "s:q:", ["src=", "quality="], usage)
    if None == opts:
        sys.exit(1)

    for opt, arg in opts:
        if opt in ("-s", "--src"):
            src = arg
        elif opt in ("-q", "--quality"):
            qL = arg.split("-")
            qMin, qMax = int(qL[0]), int(qL[1])

    if not src:
        usage()
        sys.exit(1)

    if not Functions.CompressPng(src, qMin=qMin, qMax=qMax):
        print("\n压缩 \"{}\"失败！".format(src))
        return False

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
