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
    print("以aes-cfb-128的方式加密给定的源目录中的png/lua文件。")
    print("-h | --help          查看帮助。")
    print("-s | --src           需要被加密的源目录。")
    print("-p | --pwd           加密密码，小于等于16字节，不足部分补\\0。")


def main(argv):
    src = None
    pwd = None

    opts = Functions.GetOpt(argv, "s:p:", ["src=", "pwd="], usage)
    if None == opts:
        sys.exit(1)

    for opt, arg in opts:
        if opt in ("-s", "--src"):
            src = arg
        elif opt in ("-p", "--pwd"):
            pwd = arg

    if not src or not pwd:
        usage()
        sys.exit(1)

    if not Functions.EncryptRes(src, pwd):
        print("\n加密\"{}\"失败！".format(src))
        return False

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
