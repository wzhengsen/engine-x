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


# 一些基本功能性函数，没有具体业务逻辑。
import os


def FindFirstFileInDir(dir: str, fn: str) -> str:
    """查找并返回目录下第一个匹配的指定文件。

    参数：

        dir             目录路径。

        fn              指定文件。
    """
    if os.path.isfile(dir):
        if os.path.basename(dir) == fn:
            return os.path.join(os.path.dirname(dir), fn)
        else:
            return ""
    elif os.path.isdir(dir):
        for subdir in os.listdir(dir):
            searchPath = FindFirstFileInDir(os.path.join(dir, subdir), fn)
            if searchPath:
                return searchPath
        else:
            return ""


def FindAllFilesMatch(dir: str, cond, all: list = None) -> list:
    """查找并返回目录下所有符合条件的文件。

    参数：

        dir             目录路径。

        cond            指定条件。

        all             可指定一个用于返回值的列表。
    """
    if all is None:
        all = []
    if cond(dir):
        all.append(dir)
    elif os.path.isdir(dir):
        for subdir in os.listdir(dir):
            FindAllFilesMatch(os.path.join(dir, subdir), cond, all)

    return all
