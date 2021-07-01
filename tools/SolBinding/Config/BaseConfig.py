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
from typing import Dict
from Util.EnvChecker import EnvChecker
from Util.Functions import ExceptImport
try:
    import lupa
except:
    lupa = ExceptImport("lupa")


class NotFoundFileException(Exception):
    def __str__(self) -> str:
        return "未找到某些关键文件或环境变量。"


class BaseConfig(object):
    class AnonymousType():
        # 不允许匿名枚举。
        Ban = 0
        # 允许所有的匿名枚举。
        All = 1
        # 仅允许类中的匿名枚举。
        Class = 2
        # 仅允许全局的匿名枚举。
        Global = 3

    def __init__(self):
        ndkRoot = EnvChecker.Check_NDK_RootEnv()
        defaultInclude = EnvChecker.DefaultIncludePath()
        gccToolChain = EnvChecker.Find_GCC_ToolChain()
        llvmToolChain = EnvChecker.Find_LLVM_ToolChain()
        egx = os.environ.get("ADXE_ROOT")
        if not ndkRoot or not defaultInclude or not gccToolChain or not llvmToolChain or not egx:
            raise NotFoundFileException()

        lua = lupa.LuaRuntime(unpack_returned_tuples=True)
        lua.execute('package.path = package.path .. ";{}/?.lua"'.format(os.path.join(egx,
                                                                                     "templates/lua-template-default/Resources/src").replace("\\", '/')))
        self.LuaConfig = lua.require("OOP.Config")

        # Tag用于生成的注册函数中，作为和其它生成文件的区分。
        self.Tag = None
        # TargetNamespace用于将所有CppNamespace简化成一个lua表名便于访问。
        self.TargetNamespace = None
        # 指定一组c++命名空间，所有c++类将在符合的命名空间中查找，且可以和相同的类名区分开来。
        # 比如："cocos2d::Label" <-> "cocos2d::ui::Label"
        self.CppNameSpace = []
        # 允许生成匿名枚举（属于全局或仅属于命名空间的匿名枚举可能在被include时多次生成，谨慎开启）。
        self.AllowAnonymous = BaseConfig.AnonymousType.Class
        # 允许生成结构体类型（结构体普遍被转换为一个table，没有必要为每个结构体转换为用户类）。
        self.AllowStruct = False
        # 宏判断，用于某些情况下的条件编译。
        self.MacroJudgement = None
        # 使用大驼峰命名法（在最后阶段生效，不会影响命名空间）。
        self.UpperCamelCase = True
        # 是否自动生成属性。
        # 当一个方法能够接受一个参数，且前缀符合SetPrefix时，生成set属性；
        # 当一个方法能够返回一个非void值，且接受0个参数，前缀也还符合GetPrefix时，生成get属性。
        self.AutoProperties = True
        # 对于那些没有明确指示有new函数的类型，指定一个基类名，
        # 凡是继承此基类的，如果没有new函数，但有构造函数，也会为其生成构造代码。
        # 使用类型全名，包含命名空间名。
        self.ConstructBase = ""

        self.AndroidHeaders = []
        self.AndroidFlags = [
            "-target", "armv7-none-linux-androideabi",
            "-D_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS",
            "-DANDROID",
            "-D__ANDROID_API__=14",
            "-gcc-toolchain", gccToolChain,
            "--sysroot={}/platforms/android-14/arch-arm".format(ndkRoot),
            "-idirafter", "{}/sources/android/support/include".format(ndkRoot),
            "-idirafter", "{}/sysroot/usr/include".format(llvmToolChain),
            "-idirafter", "{}/sysroot/usr/include/arm-linux-androideabi".format(llvmToolChain),
            "-I{}/sources/cxx-stl/llvm-libc++/include".format(ndkRoot)
        ]
        dl = os.listdir("{}/lib64/clang".format(llvmToolChain))
        if dl:
            self.AndroidFlags.append("-idirafter")
            self.AndroidFlags.append("{}/lib64/clang/{}/include".format(llvmToolChain, dl[0]))

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
        #   ".*Test.*" : ("getInstance","destroyInstance"),
        #   ".*NoDestroyTest.*" : ("getInstance",None)
        # }
        # 类名和方法名均可使用正则表达式。
        # 只有静态方法才生效。
        # 变换后，可直接使用单例属性访问单例（原单例方法仍然可以使用），如：
        # local inst = MyTest.getInstance();
        # local inst = MyTest.Instance;
        # MyTest.Instance = nil;--相当于调用MyTest.destroyInstance();
        self.InstanceMethods: Dict[str, tuple] = {}

        # 当一个类在作为父类时，希望被跳过的类型列表。
        self.ParentsClassesSkip = []

        # 生成get属性的前缀。
        self.GetPrefix = []
        # 生成set属性的前缀。
        self.SetPrefix = []
