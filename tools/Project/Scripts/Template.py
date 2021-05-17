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

from typing import Dict, List


class Asset:
    def __init__(self, size=None, md5=None, sha=None, compress=None) -> None:
        if md5:
            self.md5 = md5
        if sha:
            self.sha = sha
        if size:
            self.size = size
        if compress:
            self.compress = compress


class VersionManifestTemplate:
    def __init__(self) -> None:
        self.remoteVersionUrl = ""
        self.remoteManifestUrl = ""
        self.version = "0.0.0.0"
        self.engineVersion = "Cocos2dx-Lua 4.0"

    @staticmethod
    def FromJson(data):
        ret = None
        if isinstance(data, dict):
            keys = data.keys()
            if "remoteVersionUrl" in keys:
                ret = VersionManifestTemplate()
                ret.__dict__ = data

        return ret

    @staticmethod
    def ToJson(data):
        ret = {}
        if isinstance(data, VersionManifestTemplate):
            ret = data.__dict__.copy()

        return ret


class ProjectManifestTemplate(VersionManifestTemplate):
    def __init__(self) -> None:
        super().__init__()
        self.filterType = 0
        self.openFilterNum = False
        self.filterNum = 0
        self.openFilterSize = False
        self.filterSize = 0
        self.downloadUrl = ""
        self.assets: Dict[str, Asset] = {}

    @staticmethod
    def FromJson(data):
        ret = None
        if isinstance(data, dict):
            keys = data.keys()
            if "filterType" in keys:
                ret = ProjectManifestTemplate()
                ret.__dict__ = data
            elif "size" in keys or ("md5" in keys or "sha" in keys):
                ret = Asset()
                ret.__dict__ = data
            else:
                ret = data

        return ret

    @staticmethod
    def ToJson(data):
        ret = {}
        if isinstance(data, ProjectManifestTemplate):
            ret = data.__dict__.copy()
            assets = {k: v.__dict__.copy() for k, v in data.assets.items()}
            ret["assets"] = assets

        return ret


class Module:
    def __init__(self) -> None:
        # 更新目录根Url
        self.downloadUrl = ""
        # 远程版本文件Url
        self.remoteVersionUrl = ""
        # 远程清单文件Url
        self.remoteManifestUrl = ""
        # 上传目录根Url
        self.uploadUrl = ""
        # 模块包含目录
        self.dirs: List[str] = ["res", "src"]
        # 模块包含文件
        self.files: List[str] = ["config.json"]
        # 上传ftp账号
        self.ftpAccount = ""
        # 上传ftp密码
        self.ftpPassword = ""
        # 不上传文件
        self.noUpload = False
        # 仅上传hash值不同的文件
        self.onlyHashDiff = True
        # 生成的文件压缩为一个文件后再上传
        self.compressUpload = False
        # 筛选整包zip下载
        # 0-使用||逻辑
        # 1-使用&&逻辑
        self.filterType = 0
        # 打开筛选数量
        self.openFilterNum = False
        # 筛选数量
        self.filterNum = 0
        # 打开筛选容量
        self.openFilterSize = False
        # 筛选容量，此处以字节数表示
        self.filterSize = 0
        # 标识zip文件是需要解压的
        self.zipUncompress = False
        # 加密资源文件
        self.encryptRes = False
        # 加密密码
        self.encryptPassword = "testpassword"
        # 压缩图像
        self.compressPic = True
        # 压缩最低质量
        self.compressQualityMin = 50
        # 压缩最高接近质量
        self.compressQualityMax = 85
        # 编译lua
        self.compileLua = True
        # 使用何种版本
        # 0-远程版本+1
        # 1-本地版本+1
        # 2-版本不变
        # 3-指定版本
        self.versionType = 2
        # 指定的版本
        self.useVersion = "0.0.0.0"


class ConfigTemplate:
    def __init__(self) -> None:
        self.engineVersion = "Cocos2dx-Lua 4.0"
        # 是否使用通用配置。
        self.useUniConfig = True
        # 退出时保存设置。
        self.exitSave = False
        # 配置文件根目录。
        self.configRoot = "Resources"
        self.uniModule = Module()
        self.uniModule.dirs = []
        self.uniModule.files = []
        self.modules: Dict[str, Module] = {
            "Default": Module()
        }

    @staticmethod
    def FromJson(data):
        ret = None
        if isinstance(data, dict):
            keys = data.keys()
            if "configRoot" in keys:
                ret = ConfigTemplate()
                ret.__dict__ = data
            elif "ftpAccount" in keys:
                ret = Module()
                ret.__dict__ = data
            else:
                ret = data

        return ret

    @staticmethod
    def ToJson(data):
        ret = {}
        if isinstance(data, ConfigTemplate):
            ret = data.__dict__.copy()
            ret["uniModule"] = data.uniModule.__dict__.copy()
            modules = {k: v.__dict__.copy() for k, v in data.modules.items()}
            ret["modules"] = modules

        return ret
