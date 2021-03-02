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
from Util.EnvChecker import EnvChecker


class BaseConfig(object):
    def __init__(self):
        ndkRoot = EnvChecker.Check_NDK_RootEnv()
        defaultInclude = EnvChecker.DefaultIncludePath()
        gccToolChain = EnvChecker.Find_GCC_ToolChain()
        llvmToolChain = EnvChecker.Find_LLVM_ToolChain()
        if not ndkRoot or not defaultInclude or not gccToolChain or not llvmToolChain:
            sys.exit(1)

        # Tag用于生成的注册函数中，作为和其它生成文件的区分。
        self.Tag = None
        # TargetNamespace用于将所有CppNamespace简化成一个lua表名便于访问。
        self.TargetNamespace = None
        # 指定一组c++命名空间，所有c++类将在符合的命名空间中查找，且可以和相同的类名区分开来。
        # 比如："cocos2d::Label" <-> "cocos2d::ui::Label"
        self.CppNameSpace = []
        # 允许生成匿名枚举。
        self.AllowAnonymous = True
        # 允许生成结构体类型。
        self.AllowStruct = False
        # 宏判断，用于某些情况下的条件编译。
        self.MacroJudgement = None

        self.AndroidHeaders = []
        self.AndroidFlags = [
            "-target", "armv7-none-linux-androideabi",
            "-D_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS",
            "-DANDROID",
            "-D__ANDROID_API__=14",
            "-gcc-toolchain", gccToolChain,
            "--sysroot={}/platforms/android-14/arch-arm".format(ndkRoot),
            "-idirafter", "{}/sources/android/support/include".format(ndkRoot),
            "-idirafter", "{}/sysroot/usr/include".format(ndkRoot),
            "-idirafter", "{}/sysroot/usr/include/arm-linux-androideabi".format(ndkRoot),
            "-idirafter", "{}/lib64/clang/5.0/include".format(llvmToolChain),
            "-I{}/sources/cxx-stl/llvm-libc++/include".format(ndkRoot)
        ]

        self.ClangHeaders = []
        self.ClangFlags = ["-nostdinc", "-x", "c++", "-std=c++11", "-fsigned-char", "-U__SSE__"]
        self.Win32ClangFlags = []

        # 额外参数，用于用户扩展。
        self.ExtraArgs = []

        # clang 参数。
        self.ClangArgs = [
            *self.AndroidHeaders,
            *self.ClangHeaders,
            *self.AndroidFlags,
            *self.ClangFlags,
            *defaultInclude
        ]

        # 欲解析的头文件。
        self.Headers = []

        # 头文件的查找路径。
        self.SearchPaths = []

        # 欲生成代码的类（也适用于结构体和枚举类型），可以使用正则表达式。
        # 会使用"^$"括起来再进行正则匹配，如："^Menu*$"。
        self.Classes = []

        # 欲跳过的类方法（也适用于成员变量）。
        # 格式：
        # self.Skip = {
        #   "SkipName" : ["method1","method2"],
        #   "Skip.*" : ["method.*"]
        # }
        # 类名和方法名均可使用正则表达式。
        self.Skip = {}

        # 欲重命名的方法（也适用于成员变量）。
        # 格式：
        # self.RenameMembers = {
        #   "renameClass.*" : {"renameMethod" : "newMethod"},
        # }
        # 类名可以使用正则表达式。
        self.RenameMembers = {}

        # 欲重命名的类。
        # 格式：
        # self.RenameClasses = {
        #   "renameClass" : "newClass",
        #   "rename.*" : "newClass1"
        # }
        # 类名可使用正则表达式。
        self.RenameClasses = {}

        # 欲将单例方法变更为单例属性的对应关系。
        # 格式：
        # self.InstanceMethods = {
        #   ".*Test.*" : "getInstance"
        # }
        # 类名和方法名均可使用正则表达式。
        # 只有静态方法才生效。
        # 变换后，可直接使用单例属性访问单例（原单例方法仍然可以使用），如：
        # local inst = MyTest.getInstance();
        # local inst = MyTest.Instance;
        self.InstanceMethods = {}

        # 那些希望不再生成父类继承关系的类型列表。
        self.ClassesNoParents = []

        # 当一个类在作为父类时，希望被跳过的类型列表。
        self.ParentsClassesSkip = []
