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

import os
import sys


class EnvChecker:
    _System = None
    _AndroidNDK = None
    _GCC_IncludePath = None
    _LLVM_IncludePath = None
    _GCC_ToolChain = None
    _LLVM_ToolChain = None

    """用于检查环境可用性和必要支持的简单封装。
    """
    @classmethod
    def Check_NDK_RootEnv(cls):
        """检查并返回 ANDROID_NDK 环境变量。

        返回：
            str|None        未指定ANDROID_NDK时，返回None。
        """
        if not cls._AndroidNDK:
            cls._AndroidNDK = os.environ.get("ANDROID_NDK")
        if not cls._AndroidNDK:
            print("未找到 ANDROID_NDK 环境变量！")
        return cls._AndroidNDK

    @staticmethod
    def FindFirstFileInDir(dir, fn):
        """查找并返回目录下第一个匹配的指定文件。

        参数：
            dir             <str>目录路径。
            fn              <str>指定文件。
        返回：
            str|None        未找到文件返回None，否则返回文件路径。
        """
        if os.path.isfile(dir):
            if os.path.basename(dir) == fn:
                return os.path.join(os.path.dirname(dir), fn)
            else:
                return None
        elif os.path.isdir(dir):
            for subdir in os.listdir(dir):
                searchPath = EnvChecker.FindFirstFileInDir(
                    os.path.join(dir, subdir), fn)
                if searchPath is not None:
                    return searchPath
            else:
                return None

    @staticmethod
    def FindAllFilesMatch(dir, cond, all=None):
        """查找并返回目录下所有符合条件的文件。

        参数：
            dir             <str>目录路径。
            cond            <funtion|lambda>指定条件。
            all             <list|None>可指定一个用于返回值的列表。
        返回：
            list            返回列表。
        """
        if all is None:
            all = []
        if cond(dir):
            all.append(dir)
        elif os.path.isdir(dir):
            for subdir in os.listdir(dir):
                EnvChecker.FindAllFilesMatch(
                    os.path.join(dir, subdir), cond, all)

        return all

    @classmethod
    def _Find_GCC_IncludePath(cls):
        """查找 gcc 的包含路径。
        见实例:"$ANDROID_NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64/lib/gcc/arm-linux-androideabi/4.9.x/include"

        返回：
            str|None             返回None表示未找到路径。
        """
        if not cls._GCC_IncludePath:
            _NDK_Root = cls.Check_NDK_RootEnv()
            if _NDK_Root is None:
                return None
            cls._GCC_IncludePath = cls.FindAllFilesMatch(os.path.join(
                _NDK_Root, "toolchains"), lambda x: os.path.basename(x) == "stdarg.h" and "arm-linux-androideabi" in x)
            if cls._GCC_IncludePath:
                cls._GCC_IncludePath = "-I" + os.path.dirname(cls._GCC_IncludePath[0])

        return cls._GCC_IncludePath

    @classmethod
    def _Find_LLVM_IncludePath(cls):
        '''查找 llvm 的包含路径。
        见实例:"$ANDROID_NDK/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/6.0.2/include"

        返回：
            str|None             返回None表示未找到路径。
        '''
        if not cls._LLVM_IncludePath:
            _NDK_Root = cls.Check_NDK_RootEnv()
            if _NDK_Root is None:
                return None
            versionFile = cls.FindFirstFileInDir(
                _NDK_Root, "AndroidVersion.txt")
            if versionFile is None:
                return None
            versionDir = os.path.dirname(versionFile)
            includeDir = cls.FindFirstFileInDir(versionDir, "stdarg.h")
            if includeDir is None:
                return None
            cls._LLVM_IncludePath = "-I" + os.path.dirname(includeDir)
        return cls._LLVM_IncludePath

    @classmethod
    def CheckSystem(cls):
        """检查并返回当前系统的可用性。

        返回：
            str|None            受支持的系统返回系统名，否则返回None。
        """
        if not cls._System:
            for k, v in {"win32": "windows", "darwin": "darwin", "linux": "linux"}.items():
                if k in sys.platform:
                    cls._System = v
                    break
            else:
                print('你的系统不受支持！')
        return cls._System

    @classmethod
    def _FindToolChain(cls, toolChain):
        """查找符合系统的指定工具链。

        参数：
            toolChain           工具链前置路径。
        返回：
            str|None            找到时返回路径，否则返回None。
        """
        ndkRoot = cls.Check_NDK_RootEnv()
        sysName = cls.CheckSystem()
        if ndkRoot and sysName:
            invalidPath = []
            for p in ["{}-{}".format(sysName, "x86_64"), sysName, "{}-{}".format(sysName, "x86")]:
                findPath = os.path.abspath(os.path.join(ndkRoot, toolChain, p))
                if os.path.isdir(findPath):
                    return findPath
                invalidPath.append(findPath)
            else:
                print("工具链未找到！\n路径不可用：{}".format("\n".join(invalidPath)))
        return None

    @classmethod
    def Find_GCC_ToolChain(cls):
        if cls._GCC_ToolChain:
            cls._GCC_ToolChain = cls._FindToolChain("toolchains/arm-linux-androideabi-4.9/prebuilt")
        return cls._GCC_ToolChain

    @classmethod
    def Find_LLVM_ToolChain(cls):
        if cls._LLVM_ToolChain:
            cls._LLVM_ToolChain = cls._FindToolChain("toolchains/llvm/prebuilt")
        return cls._LLVM_ToolChain

    @classmethod
    def DefaultIncludePath(cls):
        '''libclang, llvm & gcc 的默认包含路径。

        返回：
            str|None             返回None表示未找到路径。
        '''
        llvmInclude = cls._Find_LLVM_IncludePath()
        if llvmInclude is None:
            return None
        toolchainInclude = cls._Find_GCC_IncludePath()
        if toolchainInclude is None:
            return None
        exactIncludes = llvmInclude + " " + toolchainInclude
        return exactIncludes
