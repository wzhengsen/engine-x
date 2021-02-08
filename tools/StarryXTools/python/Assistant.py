#!/usr/bin/env python3

import os
import sys
import getopt
import shutil
from ftplib import FTP,error_perm
import Functions
from Template import ConfigTemplate,ProjectManifestTemplate,VersionManifestTemplate
from colorama import Fore,Back,Style
import platform

class Assistant():
    '''助理类，能帮助处理Lua编译/文件夹同步/加密/热更/上传/版本管理等。
    '''
    _tempDir = "../.tempDir"
    _versionManifest = "version.manifest.json"
    _projectManifest = "project.manifest.json"
    _versionDir = "Version"

    def __init__(self,configFileName):
        '''
        Param:

        configFileName      配置文件名。该json文件提供了大多数初始配置。
                            若该文件不存在，则将依照模板创建一个新的。
        '''
        self._config = Functions.LoadJson(configFileName)
        if self._config == None:
            self._config = ConfigTemplate.copy()
            Functions.SaveJson(configFileName,self._config)
        self._configFileName = os.path.realpath(configFileName)

    def __del__(self):
        if self._config.get("exitSave"):
            Functions.SaveJson(self._configFileName,self._config)

    @staticmethod
    def __SyncGet(m1,m2,key):
        '''获取m1[key]，若该值存在，则将值覆盖到m2[key]；
        若该值不存在，则使用m2[key]的值。
        '''
        val = m1.get(key)
        if None != val:
            m2[key] = val
        else:
            val = m2.get(key)
        return val

    @staticmethod
    def __VersionGrew(verList,grew,idx):
        if idx >= len(verList) or idx < 0:
            return verList

        verList[idx] += grew
        val = verList[idx]
        if val > 100 and idx != 0:
            verList[idx] = val % 100
            verList = Assistant.__VersionGrew(verList,val // 100,idx - 1)
        return verList


    @staticmethod
    def __VersionStrGrew(ver,grew = 0):
        '''形如"1.2.3.4"格式的版本号，按照grew参数增长，在100时进位。
        '''
        verNList = [0,0,0,0]
        verList = ver.split(".")
        try:
            for i in range(0,min(len(verNList),len(verList))):
                verNList[i] = int(verList[i])
        except:
            verNList = [0,0,0,0]
        verNList = Assistant.__VersionGrew(verNList,grew,idx = 3)

        for i in range(0,min(len(verNList),len(verList))):
            verList[i] = str(verNList[i])
        return ".".join(verList)

    def GetModules(self):
        l = []
        for m in self._config["modules"]:
            l.append(m["name"])
        return l

    def GetProjectManifest(self,pManifestPath,template):
        '''获取指定路径的projectManifest文件内容。
        若不存在，将以Template.ProjectManifestTemplate创建一个新的，并以template参数初始化。
        '''

        if os.path.isfile(pManifestPath):
            return Functions.LoadJson(pManifestPath)

        pManifest = ProjectManifestTemplate.copy()
        for k in pManifest.keys():
            if k in template.keys():
                pManifest[k] = template[k]
        Functions.SaveJson(pManifestPath,pManifest,0)
        return pManifest

    def __GetModule(self,moduleName):
        '''由模块名获得模块，moduleName == None时，将获取所有模块。

        Param:

            moduleName      模块名。

        Return:

            tuple
        '''
        if moduleName != None:
            return (x for x in self._config["modules"] if x["name"] == moduleName)
        else:
            return (x for x in self._config["modules"])

        return ()

    def SyncModule(self,moduleName = None):
        '''同步给定的模块名的文件到_tempDir/module["name"]中。
        若不提供模块名，将同步全部模块。

        Param:

            moduleName          模块名。
        '''
        for m in self._config["modules"]:
            if moduleName == None or m["name"] == moduleName:
                for d in m["dirs"]:
                    if not Functions.SyncDir(os.path.join(m["localRoot"],d),os.path.join(Assistant._tempDir,m["name"],d)):
                        return False
                for f in m["files"]:
                    dstFileDir = os.path.dirname(os.path.join(Assistant._tempDir,m["name"],f))
                    if not os.path.exists(dstFileDir):
                        os.makedirs(dstFileDir)
                    shutil.copy(os.path.join(m["localRoot"],f),os.path.join(Assistant._tempDir,m["name"],f))
                if m["name"] == moduleName:
                    break
        return True

    def CompileLua(self,moduleName = None,uniConfig = None,sync = False,**kw):
        '''编译给定的模块名的lua文件到_tempDir/module["name"]中。
        若不提供模块名，将编译全部模块。

        Param:

            moduleName          模块名。
            uniConfig           是否使用统一配置。
            sync                操作前是否先同步文件夹。
            compileLua          编译lua的功能是否开启。
        '''
        if sync:
            self.SyncModule(moduleName)
        if None == uniConfig:
            uniConfig = self._config.get("useUniConfig")
        for module in self.__GetModule(moduleName):
            opDir = os.path.join(Assistant._tempDir,module["name"])
            mConfig = module if not uniConfig else self._config["uniModule"]
            compileLua = Assistant.__SyncGet(kw,mConfig,"compileLua")
            if compileLua and not Functions.CompileLua(opDir):
                return False
        return True

    def CompressPng(self,moduleName = None,uniConfig = None,sync = False,**kw):
        '''压缩给定的模块名的png文件到_tempDir/module["name"]中。
        若不提供模块名，将压缩全部模块。

        Param:

            moduleName          模块名。
            uniConfig           是否使用统一配置。
            sync                操作前是否先同步文件夹。
            compressPic         压缩png的功能是否开启。
            compressQualityMin  最低质量。
            compressQualityMax  最高接近质量。
        '''
        if sync:
            self.SyncModule(moduleName)
        if None == uniConfig:
            uniConfig = self._config.get("useUniConfig")
        for module in self.__GetModule(moduleName):
            opDir = os.path.join(Assistant._tempDir,module["name"])
            mConfig = module if not uniConfig else self._config["uniModule"]
            compressQualityMin = Assistant.__SyncGet(kw,mConfig,"compressQualityMin")
            compressQualityMax = Assistant.__SyncGet(kw,mConfig,"compressQualityMax")
            compressPic = Assistant.__SyncGet(kw,mConfig,"compressPic")
            if compressPic and not Functions.CompressPng(opDir,qMin = compressQualityMin,qMax = compressQualityMax):
                return False
        return True

    def EncryptRes(self,moduleName = None,uniConfig = None,sync = False,**kw):
        '''加密给定的模块名的png/lua/luac文件到_tempDir/module["name"]中。
        若不提供模块名，将加密全部模块。

        Param:

            moduleName          模块名。
            uniConfig           是否使用统一配置。
            sync                操作前是否先同步文件夹。
            encryptRes          加密功能是否开启。
            encryptPassword     加密密码。
        '''
        if sync:
            self.SyncModule(moduleName)
        if None == uniConfig:
            uniConfig = self._config.get("useUniConfig")
        for module in self.__GetModule(moduleName):
            opDir = os.path.join(Assistant._tempDir,module["name"])
            mConfig = module if not uniConfig else self._config["uniModule"]
            encryptPassword = Assistant.__SyncGet(kw,mConfig,"encryptPassword")
            encryptRes = Assistant.__SyncGet(kw,mConfig,"encryptRes")

            if encryptRes and not Functions.EncryptRes(opDir,encryptPassword):
                return False
        return True

    def HashModule(self,moduleName,uniConfig = None,sync = False,**kw):
        '''生成并返回给定的模块名的哈希描述。

        Param:

            moduleName          模块名。
            uniConfig           是否使用统一配置。
            sync                操作前是否先同步文件夹。
            zipUncompress       是否将zip文件标识为需要解压。
        '''
        if None == moduleName:
            return {}
        if sync:
            self.SyncModule(moduleName)
        if None == uniConfig:
                uniConfig = self._config.get("useUniConfig")
        for module in self.__GetModule(moduleName):
            opDir = os.path.join(Assistant._tempDir,module["name"])
            mConfig = module if not uniConfig else self._config["uniModule"]

            zipUncompress = Assistant.__SyncGet(kw,mConfig,"zipUncompress")
            return Functions.CalcDirHash(opDir,compressed = zipUncompress)
        return {}

    def __Upload(
        self,
        moduleName = None,
        uniConfig = False,
        **kw
    ):
        '''见Upload
        '''
        if None == uniConfig:
            uniConfig = self._config.get("useUniConfig")
        for module in self.__GetModule(moduleName):
            opDir = os.path.join(Assistant._tempDir,module["name"])
            mConfig = module if not uniConfig else self._config["uniModule"]

            versionType = kw.get("versionType")
            if None != versionType:
                if isinstance(versionType,str):
                    mConfig["versionType"] = 3
                    mConfig["useVersion"] = versionType
                else:
                    mConfig["versionType"] = versionType
            else:
                if mConfig["versionType"] == 3:
                    versionType = mConfig["useVersion"]
                else:
                    versionType = mConfig["versionType"]

            noUpload = Assistant.__SyncGet(kw,mConfig,"noUpload")
            onlyHashDiff = Assistant.__SyncGet(kw,mConfig,"onlyHashDiff")
            compressUpload = Assistant.__SyncGet(kw,mConfig,"compressUpload")
            ftpAccount = Assistant.__SyncGet(kw,mConfig,"ftpAccount")
            ftpPassword = Assistant.__SyncGet(kw,mConfig,"ftpPassword")
            Assistant.__SyncGet(kw,mConfig,"filterType")
            Assistant.__SyncGet(kw,mConfig,"openFilterNum")
            Assistant.__SyncGet(kw,mConfig,"filterNum")
            Assistant.__SyncGet(kw,mConfig,"openFilterSize")
            Assistant.__SyncGet(kw,mConfig,"filterSize")

            pManifestPath = os.path.join(module["localRoot"],Assistant._versionDir,module["name"],Assistant._projectManifest)
            mpManifestPath = os.path.join(Assistant._tempDir,module["name"],Assistant._projectManifest)
            mvManifestPath = os.path.join(Assistant._tempDir,module["name"],Assistant._versionManifest)
            moduleZip = os.path.join(Assistant._tempDir,module["name"],module["name"] + ".zip")

            pManifest = self.GetProjectManifest(pManifestPath,module)

            # 先删除version.manifest.json/project.manifest.json/module["name"].zip
            if os.path.isfile(mvManifestPath):
                os.remove(mvManifestPath)
            if os.path.isfile(mpManifestPath):
                os.remove(mpManifestPath)
            if os.path.isfile(moduleZip):
                os.remove(moduleZip)
            # 生成文件哈希描述。
            pManifest["assets"] = self.HashModule(module["name"],uniConfig,False,**kw)

            if versionType == 0:
                # 远程版本+1操作。
                remoteVM = Functions.LoadNetJson(module["remoteVersionUrl"])
                if remoteVM:
                    pManifest["version"] = Assistant.__VersionStrGrew(remoteVM["version"],1)
                else:
                    print(Fore.LIGHTRED_EX + "获取远程版本失败！" + Style.RESET_ALL)
                    return False
            elif versionType == 1:
                # 本地版本+1操作。
                pManifest["version"] = Assistant.__VersionStrGrew(pManifest["version"],1)
            elif isinstance(versionType,str):
                # 指定版本。
                pManifest["version"] = Assistant.__VersionStrGrew(versionType)

            # ProjectManifest写回文件。
            Functions.SaveJson(pManifestPath,pManifest,0)
            Functions.SaveJson(mpManifestPath,pManifest,0)
            # VersionManifest写入。
            vManifest = VersionManifestTemplate.copy()
            vManifest["version"] = pManifest["version"]
            vManifest["remoteManifestUrl"] = pManifest["remoteManifestUrl"]
            vManifest["remoteVersionUrl"] = pManifest["remoteVersionUrl"]
            Functions.SaveJson(mvManifestPath,vManifest,0)

            if not noUpload:
                # 待上传文件。
                uploadFiles = pManifest["assets"]
                if onlyHashDiff:
                    # 比对不同哈希文件。
                    rpManifest = Functions.LoadNetJson(module["remoteManifestUrl"])
                    if None == rpManifest:
                        print(Fore.LIGHTRED_EX + "获取远程文件列表失败！" + Style.RESET_ALL)
                        return False
                    remoteFiles = rpManifest.get("assets",{})
                    uploadFiles = [
                        k\
                        for k,v in uploadFiles.items()\
                        if k not in remoteFiles.keys() or (remoteFiles[k].get("md5","").lower() != v.get("md5","").lower())
                    ]
                else:
                    uploadFiles = [k for k in uploadFiles.keys()]

                oCWD = os.getcwd()
                os.chdir(opDir)
                if compressUpload:
                    # 需要压缩再上传。
                    ret = Functions.ZipFiles(module["name"] + ".zip",uploadFiles)
                    if not ret:
                        return False
                    uploadFiles = [module["name"] + ".zip"]

                # 追加version.manifest.json和project.manifest.json
                uploadFiles.append(Assistant._versionManifest)
                uploadFiles.append(Assistant._projectManifest)
                # ftp上传
                ret = Functions.FtpUpload(module["uploadUrl"],ftpAccount,ftpPassword,uploadFiles)
                os.chdir(oCWD)
                if not ret:
                    print(Fore.LIGHTRED_EX + "文件上传失败！" + Style.RESET_ALL)
                    return False

        return True

    def Upload(
        self,
        moduleName = None,
        uniConfig = None,
        **kw
    ):
        '''在本地完成部署后上传。
        若不提供模块名，将部署和上传全部模块。
        project.manifest.json文件将生成于模块根目录的Version下；
        version.manifest.json文件将生成于_tempDir的模块目录下。
        如果不提供参数，则参数将使用模块文件中的默认值。

        Param:

            moduleName          模块名。

            uniConfig           是否使用统一配置。

            versionType         版本配置类型，可以为整数或字符串。
                                整数0表示使用远程版本号+1；
                                整数1表示使用本地版本号+1；
                                整数2表示版本不变；
                                字符串表示为："1.2.3.4"的格式。

            zipUncompress       表示zip资源在project.manifest.json文件中是否标识为自动解压。

            encryptRes          表示是否加密资源.
                                若为True，则encryptPassword指示了加密密码；
                                若为False，则encryptPassword不生效。

            encryptPassword     加密密码。

            compressPic         表示是否压缩png图像。
                                若为True，qMin和qMax参数指示了压缩质量；
                                若为False，qMin和qMax不生效。

            compressQualityMin  压缩图像的最低质量。

            compressQualityMax  压缩图像的最高接近质量。

            compileLua          表示是否对lua编译。

            noUpload            表示是否不上传。
                                若为True，将不会有上传步骤，但仍然会进行本地部署，这对于应用编译和本地调试很有用；
                                若为True，uploadHashDiff和compressUpload将被强制认为是False。
                                若为False，将在本地部署后，将部署完成的文件上传。

            onlyHashDiff        表示是否仅上传哈希不同的文件。
                                当且仅当uploadHashDiff为False（或默认配置中为False），compressUpload为True（或默认配置中为True）时，
                                文件下载筛选才会生效。

            compressUpload      表示是否压缩文件后再上传（需要接收端解压）。
                                当且仅当uploadHashDiff为False（或默认配置中为False），compressUpload为True（或默认配置中为True）时，
                                文件下载筛选才会生效。

            ftpAccount          ftp账号。

            ftpPassword         ftp密码。

            filterType          整数，整包下载筛选类型。
                                若为0，使用||逻辑；
                                若为1，使用&&逻辑。

            openFilterNum       是否开启文件数量筛选。

            filterNum           整数，文件筛选总数量。

            openFilterSize      是否开启文件容量筛选。

            filterSize          整数，文件筛选总容量（字节）。

        Return:

            bool                有任意一个步骤失败，均会中断剩余步骤，返回False；
                                否则返回True。
        '''

        # 依次进行文件同步/编译lua/压缩图像/加密资源/生成描述文件和上传的步骤。
        ret = self.SyncModule(moduleName) and\
        self.CompileLua(moduleName,uniConfig,False,**kw) and\
        self.CompressPng(moduleName,uniConfig,False,**kw) and\
        self.EncryptRes(moduleName,uniConfig,False,**kw) and\
        self.__Upload(moduleName,uniConfig,**kw)
        if not ret:
            print(Fore.LIGHTRED_EX + "操作失败！" + Style.RESET_ALL)
        else:
            print(Fore.LIGHTGREEN_EX + "操作成功。" + Style.RESET_ALL)
        return ret

    def LocalDeploy(self,
        deployDir,
        uniConfig = None,
        **kw
    ):
        '''仅在本地部署，不上传。
        将会部署全部模块。
        project.manifest.json文件将生成于模块根目录的Version下；
        如果不提供参数，则参数将使用模块文件中的默认值。

        Param:

            deployDir           部署文件夹。

            uniConfig           是否使用统一配置。

            versionType         版本配置类型，可以为整数或字符串。
                                整数0表示使用远程版本号+1；
                                整数1表示使用本地版本号+1；
                                整数2表示版本不变；
                                字符串表示为："1.2.3.4"的格式。

            zipUncompress       表示zip资源在project.manifest.json文件中是否标识为自动解压。

            encryptPassword     加密密码。

            compressQualityMin  压缩图像的最低质量。

            compressQualityMax  压缩图像的最高接近质量。

        Return:

            bool                有任意一个步骤失败，均会中断剩余步骤，返回False；
                                否则返回True。
        '''
        # 依次进行文件同步/编译lua/压缩图像/加密资源/生成描述文件的步骤。
        ret = self.SyncModule() and\
        self.CompileLua(None,uniConfig,False,compileLua = True,**kw) and\
        self.CompressPng(None,uniConfig,False,compressPic = True,**kw) and\
        self.EncryptRes(None,uniConfig,False,encryptRes = True,**kw) and\
        self.__Upload(None,uniConfig,noUpload = True,**kw)

        if not os.path.exists(os.path.join(deployDir,Assistant._versionDir)):
            os.makedirs(os.path.join(deployDir,Assistant._versionDir))
        if ret:
            for m in self._config["modules"]:
                for d in m["dirs"]:
                    if not Functions.SyncDir(os.path.join(Assistant._tempDir,m["name"],d),os.path.join(deployDir,d)):
                        ret = False
                        break
                for f in m["files"]:
                    dstFileDir = os.path.dirname(os.path.join(deployDir,f))
                    if not os.path.exists(dstFileDir):
                        os.makedirs(dstFileDir)
                    shutil.copy(os.path.join(Assistant._tempDir,m["name"],f),os.path.join(deployDir,f))
                vPath = os.path.join(Assistant._tempDir,m["name"],Assistant._versionManifest)
                pPath = os.path.join(Assistant._tempDir,m["name"],Assistant._projectManifest)
                dvPath = os.path.join(deployDir,Assistant._versionDir,m["name"],Assistant._versionManifest)
                dpPath = os.path.join(deployDir,Assistant._versionDir,m["name"],Assistant._projectManifest)
                dvPath = os.path.dirname(dvPath)
                dpPath = os.path.dirname(dpPath)
                if not os.path.exists(dvPath):
                    os.makedirs(dvPath)
                if not os.path.exists(dpPath):
                    os.makedirs(dpPath)

                if os.path.isfile(vPath):
                    shutil.copy(vPath,dvPath)
                if os.path.isfile(pPath):
                    shutil.copy(pPath,dpPath)
        if not ret:
            print(Fore.LIGHTRED_EX + "操作失败！" + Style.RESET_ALL)
        else:
            print(Fore.LIGHTGREEN_EX + "操作成功。" + Style.RESET_ALL)
        return ret