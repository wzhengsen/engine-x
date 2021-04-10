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
from Scripts import Functions
from Scripts.Assistant import Assistant


def usage():
    print(""""""
          """对源目录下的给定模块进行lua编译/图像压缩/资源加密/上传/版本变更等操作。
默认模块位于源目录下Module.json，各域值参照Template.py。
操作结果将放置于目标目录。
""")

    print("""
--gui <string>              Gui工具，并指定根目录。
-i                          交互式命令行。
""")

    print(
        """
-h | --help                 查看帮助。

-s <string>                 源目录。
                            若不使用此命令，则默认当前目录为源目录。

-d string                   目标目录。

-m <module1 module2 ...>    需要处理的模块名。
                            若不使用此命令，将默认处理所有模块。

-u <bool>                   使用此命令以启用通用配置（所有模块使用同一配置）。
                            若不使用此命令，每个模块的配置将以配置文件为准。

--debug                     使用本地部署，部署到指定目录，只同步，不编译，不压缩，不加密，不上传。

--release|minsizerel|relwithdebinfo     使用本地部署，部署到指定目录，不上传。

-c                          若源目录下没有Module.json，则将创建一个默认的Module.json。

-=通用配置=-
以下配置若为空，并不意味则该选项不启用；而是使用配置文件中的默认值。
若提供了参数，将使用参数值修改配置文件中的值。

--versionType <ver>         版本配置类型，可以为整数或字符串。
                            整数0表示使用远程版本号+1；
                            整数1表示使用本地版本号+1；
                            整数2表示版本不变；
                            字符串表示为："1.2.3.4"的格式。

--zipUncompress <bool>      表示zip资源在project.manifest.json文件中是否标识为自动解压。

--encryptRes <bool>         表示是否加密资源.
                            若为true，则encryptPassword指示了加密密码；
                            若为false，则encryptPassword不生效。

--encryptPassword <string>  加密密码。

--compressPic <bool>        表示是否压缩png图像。
                            若为true，qMin和qMax参数指示了压缩质量；
                            若为false，qMin和qMax不生效。

--compressQualityMin <int>  压缩图像的最低质量。

--compressQualityMax <int>  压缩图像的最高接近质量。

--compileLua <bool>         表示是否对lua编译。

--noUpload <bool>           表示是否不上传。
                            若为true，将不会有上传步骤，但仍然会进行本地部署，这对于应用编译和本地调试很有用；
                            若为true，uploadHashDiff和compressUpload将被强制认为是false。
                            若为false，将在本地部署后，将部署完成的文件上传。

--onlyHashDiff <bool>       表示是否仅上传哈希不同的文件。
                            当且仅当uploadHashDiff为false（或默认配置中为false），compressUpload为true（或默认配置中为true）时，
                            文件下载筛选才会生效。

--compressUpload <bool>     表示是否压缩文件后再上传（需要接收端解压）。
                            当且仅当uploadHashDiff为false（或默认配置中为false），compressUpload为true（或默认配置中为true）时，
                            文件下载筛选才会生效。

--ftpAccount <str>          ftp账号。

--ftpPassword <str>         ftp密码。

--filterType <int>          整数，整包下载筛选类型。
                            若为0，使用||逻辑；
                            若为1，使用&&逻辑。

--openFilterNum <bool>      是否开启文件数量筛选。

--filterNum <int>           整数，文件筛选总数量。

--openFilterSize <bool>     是否开启文件容量筛选。

--filterSize <int>          整数，文件筛选总容量（字节）。
""")


def ConvertArgs(opts):
    dArgs = {}
    for item in opts:
        k = item[0]
        v = item[1]
        k = k.replace("-", "")
        dArgs[k] = v
        if k == "versionType":
            if v == "0" or v == "1" or v == "2":
                dArgs[k] = int(v)
        elif k == "zipUncompress":
            dArgs[k] = v.lower() == "true"
        elif k == "encryptRes":
            dArgs[k] = v.lower() == "true"
        elif k == "compressPic":
            dArgs[k] = v.lower() == "true"
        elif k == "compressQualityMin":
            dArgs[k] = int(v) if v.isdecimal() else None
        elif k == "compressQualityMax":
            dArgs[k] = int(v) if v.isdecimal() else None
        elif k == "compileLua":
            dArgs[k] = v.lower() == "true"
        elif k == "noUpload":
            dArgs[k] = v.lower() == "true"
        elif k == "onlyHashDiff":
            dArgs[k] = v.lower() == "true"
        elif k == "compressUpload":
            dArgs[k] = v.lower() == "true"
        elif k == "filterType":
            dArgs[k] = int(v) if v.isdecimal() else None
        elif k == "openFilterNum":
            dArgs[k] = v.lower() == "true"
        elif k == "filterNum":
            dArgs[k] = int(v) if v.isdecimal() else None
        elif k == "openFilterSize":
            dArgs[k] = v.lower() == "true"
        elif k == "filterSize":
            dArgs[k] = int(v) if v.isdecimal() else None
        elif k == "u":
            dArgs[k] = v.lower() == "true"

    return dArgs


def ConfigByInteractive(ast: Assistant):
    modules = ast.GetModules()
    if len(modules) == 0:
        print("没有任何模块可以操作。")
        return True
    print("当前可操作的模块：")
    for m in modules.keys():
        print(m)

    modules = input("输入操作的模块，以空格间隔（输入回车跳过，以操作所有模块）：")
    modules = modules.split(" ")
    if len(modules) == 0 or (len(modules) == 1 and modules[0] == ""):
        modules = None
    uniConfig = Functions.YesOrNo("使用通用配置吗？(y/n)", False)

    print("\n以下选项都可使用回车跳过以使用配置文件中的默认值。\n")
    kwArg = {}
    if uniConfig:
        kwArg["versionType"] = input(
            "输入版本：\n0-远程版本+1\n1-本地版本+1\n2-版本不变\n其它值-直接指定为版本号\n")
        kwArg["compileLua"] = Functions.YesOrNo("是否编译lua代码？(y/n)")
        kwArg["compressPic"] = Functions.YesOrNo("是否压缩图像？(y/n)")
        if kwArg.get("compressPic") != False:
            try:
                kwArg["compressQualityMin"] = int(input("最低图像质量："))
            except:
                kwArg["compressQualityMin"] = None
            try:
                kwArg["compressQualityMax"] = int(input("最高图像质量："))
            except:
                kwArg["compressQualityMax"] = None
        kwArg["encryptRes"] = Functions.YesOrNo("是否加密资源？(y/n)")
        if kwArg.get("encryptRes") != False:
            kwArg["encryptPassword"] = input("加密密码：")
        kwArg["zipUncompress"] = Functions.YesOrNo("是否标识zip资源为自动解压？(y/n)")

        kwArg["noUpload"] = Functions.YesOrNo("是否仅在本地操作（即不上传任何资源）？(y/n)")
        if kwArg.get("noUpload") != False:
            kwArg["onlyHashDiff"] = Functions.YesOrNo("是否仅上传哈希值不同的文件？(y/n)")
            kwArg["compressUpload"] = Functions.YesOrNo(
                "是否压缩资源后再上传（需要接收端解压）？(y/n)")
            kwArg["ftpAccount"] = input("ftp账号：")
            kwArg["ftpPassword"] = input("ftp密码：")
            if kwArg.get("onlyHashDiff") == False and kwArg.get("compressUpload") == True:
                kwArg["openFilterNum"] = Functions.YesOrNo("是否开启文件数量筛选？(y/n)")
                try:
                    kwArg["filterNum"] = int(input("文件筛选总数量："))
                except:
                    kwArg["filterNum"] = None

                kwArg["openFilterSize"] = Functions.YesOrNo("是否开启文件容量筛选？(y/n)")
                try:
                    kwArg["filterSize"] = int(input("文件筛选总容量（字节）："))
                except:
                    kwArg["filterSize"] = None

                if not (kwArg.get("openFilterNum") == False and kwArg.get("openFilterSize") == False):
                    kwArg["filterType"] = Functions.GetChars(
                        "01\r", "整包下载筛选类型：\n0-使用||逻辑\n1-使用&&逻辑")

    if modules != None:
        for m in modules:
            ret = ast.Upload(m, uniConfig, **kwArg)
            if not ret:
                return False
        return True
    else:
        return ast.Upload(modules, uniConfig, **kwArg)


def UniOpt(opts, tp):
    for p1 in tp:
        if p1 in opts:
            for p2 in tp:
                if p2 != p1 and p2 in opts:
                    print(p1 + "不能和" +
                          p2 + "同时使用。")
                    return False
    return True


def main(argv):
    opts = Functions.GetOpt(
        argv,
        "im:u:d:s:",
        [
            "gui=",
            "versionType=",
            "zipUncompress=",
            "encryptRes=",
            "encryptPassword=",
            "compressPic=",
            "compressQualityMin=",
            "compressQualityMax=",
            "compileLua=",
            "noUpload=",
            "onlyHashDiff=",
            "uploadCompress=",
            "ftpAccount=",
            "ftpPassword=",
            "filterType=",
            "openFilterNum=",
            "filterNum=",
            "openFilterSize=",
            "filterSize=",
            "debug",
            "Debug",
            "release",
            "Release",
            "minsizerel",
            "MinSizeRel",
            "relwithdebinfo",
            "RelWithDebInfo"
        ],
        usage
    )
    if not opts or len(opts) == 0:
        usage()
        return False
    opts = ConvertArgs(opts)
    oKeys = opts.keys()
    lowCaseOpt = [x.lower() for x in oKeys]

    if not UniOpt(lowCaseOpt, ("debug", "release", "relwithdebinfo", "minsizerel")):
        return False

    if "gui" in oKeys:
        from ToolForm import ToolForm
        from PyQt5.QtWidgets import QApplication
        _ = QApplication(sys.argv)
        ToolForm(opts["gui"])
        ret = QApplication.exec()
        return True
    elif "i" in oKeys:
        srcPath = input("请输入源目录（按回车使用当前目录）：")
        srcPath = "." if srcPath == "" else srcPath
    else:
        srcPath = opts.get("s", ".")

    if os.path.isdir(srcPath):
        ast = Assistant(srcPath)
    else:
        print("源目录不存在。")
        return False

    oCwd = os.getcwd()
    os.chdir(os.path.realpath(srcPath))

    if "c" in oKeys:
        ast.CreateDefaultConfig()
    if "i" in oKeys:
        ret = ConfigByInteractive(ast)
    elif "debug" in lowCaseOpt:
        ret = ast.Sync(opts["d"])
    elif "release" in lowCaseOpt\
            or "relwithdebinfo" in lowCaseOpt\
            or "minsizerel" in lowCaseOpt:
        ret = ast.Deploy(opts["d"], opts.get("u"), **opts)
    else:
        modules = opts.get("m")
        uniConfig = opts.get("u")
        if isinstance(modules, str):
            modules = modules.split(" ")
            for m in modules:
                ret = ast.Upload(m, uniConfig, **opts)
                if not ret:
                    break
        else:
            modules = None
            ret = ast.Upload(modules, uniConfig, **opts)

    os.chdir(oCwd)
    return ret


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
