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
from .Functions import *


class EnvChecker:
    """用于检查环境可用性和必要支持的简单封装。
    """
    _System = ""
    _AndroidNDK = ""
    _GCC_IncludePath = ""
    _LLVM_IncludePath = ""
    _GCC_ToolChain = ""
    _LLVM_ToolChain = ""
    _DefautIncludePath = None

    @classmethod
    def Check_NDK_RootEnv(cls) -> str:
        """检查并返回 ANDROID_NDK 环境变量。"""
        if not cls._AndroidNDK:
            cls._AndroidNDK = os.environ.get("ANDROID_NDK")
        if not cls._AndroidNDK:
            print("未找到 ANDROID_NDK 环境变量！")
        return cls._AndroidNDK

    @classmethod
    def _Find_GCC_IncludePath(cls) -> str:
        """查找 gcc 的包含路径。
        见实例:"$ANDROID_NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64/lib/gcc/arm-linux-androideabi/4.9.x/include"
        """
        if not cls._GCC_IncludePath:
            _NDK_Root = cls.Check_NDK_RootEnv()
            if _NDK_Root:
                cls._GCC_IncludePath = FindAllFilesMatch(os.path.join(
                    _NDK_Root, "toolchains"), lambda x: os.path.basename(x) == "stdarg.h" and "arm-linux-androideabi" in x)
                if cls._GCC_IncludePath:
                    cls._GCC_IncludePath = "-I" + os.path.dirname(cls._GCC_IncludePath[0])

        return cls._GCC_IncludePath

    @classmethod
    def _Find_LLVM_IncludePath(cls) -> str:
        '''查找 llvm 的包含路径。
        见实例:"$ANDROID_NDK/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/6.0.2/include"
        '''
        if not cls._LLVM_IncludePath:
            _NDK_Root = cls.Check_NDK_RootEnv()
            if _NDK_Root:
                versionFile = FindFirstFileInDir(_NDK_Root, "AndroidVersion.txt")
                if versionFile:
                    versionDir = os.path.dirname(versionFile)
                    includeDir = FindFirstFileInDir(versionDir, "stdarg.h")
                    if includeDir:
                        cls._LLVM_IncludePath = "-I" + os.path.dirname(includeDir)
        return cls._LLVM_IncludePath

    @classmethod
    def CheckSystem(cls) -> str:
        """检查并返回当前系统的可用性。"""
        if not cls._System:
            for k, v in {"win32": "windows", "darwin": "darwin", "linux": "linux"}.items():
                if k in sys.platform:
                    cls._System = v
                    break
            else:
                print('你的系统不受支持！')
        return cls._System

    @classmethod
    def _FindToolChain(cls, toolChain: str) -> str:
        """查找符合系统的指定工具链。

        参数：

            toolChain           工具链前置路径。
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
        return ""

    @classmethod
    def Find_GCC_ToolChain(cls) -> str:
        if not cls._GCC_ToolChain:
            cls._GCC_ToolChain = cls._FindToolChain("toolchains/arm-linux-androideabi-4.9/prebuilt")
        return cls._GCC_ToolChain

    @classmethod
    def Find_LLVM_ToolChain(cls) -> str:
        if not cls._LLVM_ToolChain:
            cls._LLVM_ToolChain = cls._FindToolChain("toolchains/llvm/prebuilt")
        return cls._LLVM_ToolChain

    @classmethod
    def DefaultIncludePath(cls) -> list:
        '''libclang, llvm & gcc 的默认包含路径。
        '''
        if not cls._DefautIncludePath:
            cls._DefautIncludePath = []
            llvmInclude = cls._Find_LLVM_IncludePath()
            if llvmInclude:
                cls._DefautIncludePath.append(llvmInclude)
            toolchainInclude = cls._Find_GCC_IncludePath()
            if toolchainInclude:
                cls._DefautIncludePath.append(toolchainInclude)
        return cls._DefautIncludePath
