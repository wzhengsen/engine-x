#!/usr/bin/env python3

ProjectManifestTemplate = {
    "remoteVersionUrl": "",
    "remoteManifestUrl": "",
    "version": "0.0.0.0",
    "engineVersion": "Cocos2dx-Lua 4.0",
    "filterType": 0,
    "openFilterNum": False,
    "filterNum": 0,
    "openFilterSize": False,
    "filterSize": 0,
    "downloadUrl": "",
    "allZipFileName": "",
    "assets": {}
}

VersionManifestTemplate = {
    "remoteVersionUrl": "",
    "remoteManifestUrl": "",
    "version": "0.0.0.0",
    "engineVersion": "Cocos2dx-Lua 4.0"
}

ConfigTemplate = {
    "engineVersion" : "Cocos2dx-Lua 4.0",
    # 是否使用通用配置。
    "useUniConfig" : True,
    # 退出时保存设置。
    "exitSave" : False,
    "uniModule" : {
            "ftpAccount" : "",
            "ftpPassword" : "",
            "noUpload" : False,
            "onlyHashDiff" : True,
            "compressUpload" : False,
            "filterType": 0,
            "openFilterNum": False,
            "filterNum": 0,
            "openFilterSize": False,
            "filterSize": 0,
            "zipUncompress" : False,
            "encryptRes" : False,
            "encryptPassword" : "testpassword",
            "compressPic" : True,
            "compressQualityMin" : 50,
            "compressQualityMax" : 85,
            "compileLua" : True,
            "versionType" : 2,
            "useVersion" : "0.0.0.0",
    },
    "modules" : {
        "Default": {
            # 更新目录根Url
            "downloadUrl" : "",
            # 远程版本文件Url
            "remoteVersionUrl" : "",
            # 远程清单文件Url
            "remoteManifestUrl" : "",
            # 上传目录根Url
            "uploadUrl" : "",
            # 整包zip文件名
            "allZipFileName": "",
            # 模块包含目录
            "dirs" : ["."],
            # 模块包含文件
            "files" : [],
            # 上传ftp账号
            "ftpAccount" : "",
            # 上传ftp密码
            "ftpPassword" : "",
            # 不上传文件
            "noUpload" : False,
            # 仅上传hash值不同的文件
            "onlyHashDiff" : True,
            # 生成的文件压缩为一个文件后再上传
            "compressUpload" : False,
            # 筛选整包zip下载
            # 0-使用||逻辑
            # 1-使用&&逻辑
            "filterType": 0,
            # 打开筛选数量
            "openFilterNum": False,
            # 筛选数量
            "filterNum": 0,
            # 打开筛选容量
            "openFilterSize": False,
            # 筛选容量，此处以字节数表示
            "filterSize": 0,
            # 标识zip文件是需要解压的
            "zipUncompress" : False,
            # 加密资源文件
            "encryptRes" : False,
            # 加密密码
            "encryptPassword" : "testpassword",
            # 压缩图像
            "compressPic" : True,
            # 压缩最低质量
            "compressQualityMin" : 50,
            # 压缩最高接近质量
            "compressQualityMax" : 85,
            # 编译lua
            "compileLua" : True,
            # 使用何种版本
            # 0-远程版本+1
            # 1-本地版本+1
            # 2-版本不变
            # 3-指定版本
            "versionType" : 2,
            # 指定的版本
            "useVersion" : "0.0.0.0"
        }
    }
}