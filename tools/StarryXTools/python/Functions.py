#!/usr/bin/env python3

import os
import stat
from enum import Enum, auto
import shutil
import getopt
import random
import json
import platform
import hashlib
import zipfile
from ftplib import FTP, error_perm
import sys
from tempfile import NamedTemporaryFile
try:
    import requests
except:
    import os
    if 0 != os.system('pip3 install requests --user'):
        print("run pip3 failed.")
        exit(1)
    else:
        import requests
try:
    from Crypto.Cipher import AES
except:
    if 0 != os.system("pip3 install pycryptodome --user"):
        print("run pip3 failed.")
        exit(1)
    else:
        from Crypto.Cipher import AES
try:
    from colorama import Fore, Back, Style
except:
    if 0 != os.system("pip3 install colorama --user"):
        print("run pip3 failed.")
        exit(1)
    else:
        from colorama import Fore, Back, Style


class ListType(Enum):
    '''遍历路径方式枚举。
    '''

    # 遍历文件。
    File = auto(),
    # 遍历目录。
    Dir = auto(),
    # 遍历文件和目录。
    All = auto(),
    # 不遍历。
    Nil = auto()


def ListPath(path=os.curdir, l=None, absName=False, lt=ListType.Nil):
    '''遍历指定路径下的所有文件/目录。

    Param:

        path        指定的路径。
        l           可提供一个追加列表。
        absName     是否返回绝对路径名，而非当前路径名。
        lt          遍历类型。

    Return:

        list
    '''

    if l == None:
        l = []
    if lt == ListType.Nil or os.path.isfile(path):
        return l

    listPath = os.path.abspath(path) if absName else path

    for v in os.listdir(listPath):
        fullPath = os.path.join(
            "" if path == "." else path, v).replace(os.sep, "/")

        if lt == ListType.All:
            l.append(fullPath)
        elif lt == ListType.File and os.path.isfile(fullPath):
            l.append(fullPath)

        if os.path.isdir(fullPath):
            if lt == ListType.Dir:
                l.append(fullPath)
            ListPath(fullPath, l, absName, lt)
    return l


def ListDirsFiles(path=os.curdir, l=None, absName=False):
    return ListPath(path, l, absName, ListType.All)


def ListFiles(path=os.curdir, l=None, absName=False):
    return ListPath(path, l, absName, ListType.File)


def ListDirs(path=os.curdir, l=None, absName=False):
    return ListPath(path, l, absName, ListType.Dir)


def newLine(func):
    def wr(*arg, **kwarg):
        ret = func(*arg, **kwarg)
        sys.stdout.write("\r\n")
        return ret
    return wr


class CopyType(Enum):
    '''复制目录方式枚举。
    '''

    # 目标存在，则跳过。
    Skip = auto(),
    # 目标存在，则覆盖。
    Override = auto(),
    # 目标存在，则停止。
    Stop = auto(),
    # 目标存在，且（最后修改时间不同，或大小不同时），则覆盖。
    # 为保证效率，不以计算目标哈希判断。
    Diff = auto()


def CopyDir(src, dst, ct=CopyType.Override):
    '''复制src目录到dst目录。

    Param:

        src     源目录。
        dst     目标目录。
        ct      复制方式。

    Return:

        bool    发生错误，返回False；否则返回True。
    '''

    if (os.path.exists(src) and os.path.exists(dst) and os.path.samefile(src, dst)) and os.path.isfile(src) or os.path.isfile(dst):
        return False

    if (not os.path.isdir(dst)):
        os.makedirs(dst)

    fdList = ListDirsFiles(src)
    for sItem in fdList:
        dItem = os.path.join(dst, os.path.relpath(sItem, src))
        sIsFile = os.path.isfile(sItem)
        dIsFile = os.path.isfile(dItem)

        if os.path.exists(dItem):
            # 目标存在，不同的处理方式。
            if ct == CopyType.Skip:
                continue
            elif ct == CopyType.Stop:
                return False
            elif ct == CopyType.Diff:
                if sIsFile:
                    dCTime = os.path.getmtime(dItem)
                    sCTime = os.path.getmtime(sItem)
                    dSize = os.path.getsize(dItem)
                    sSize = os.path.getsize(sItem)
                    if dCTime == sCTime and dSize == sSize:
                        continue
        try:
            if not sIsFile:
                if dIsFile:
                    os.remove(dItem)
                if not os.path.isdir(dItem):
                    os.makedirs(dItem)
                continue
            else:
                if os.path.isdir(dItem):
                    shutil.rmtree(dItem)
            dDir = os.path.dirname(dItem)
            if not os.path.isdir(dDir):
                os.makedirs(dDir)
            shutil.copy2(sItem, dItem)
        except:
            return False
    return True


def SyncDir(src, dst, eList=None):
    '''同步两个目录。
    将src同步到dst。
    首先向src复制到dst，再将dst多余的文件/目录删除。

    Param:

        src     源目录。
        dst     目标目录。
        eList   排除文件或目录。

    Return:
        bool    发生错误，返回False；否则返回True。
    '''
    ret = CopyDir(src, dst, CopyType.Diff)
    if ret:
        dList = ListDirsFiles(dst)
        for item in dList:
            relPath = os.path.relpath(item, dst)
            if not os.path.exists(os.path.join(src, relPath)):
                bItem = os.path.basename(item)
                if eList and (bItem in eList):
                    continue
                try:
                    if os.path.exists(item):
                        if os.path.isdir(item):
                            shutil.rmtree(item)
                        else:
                            os.remove(item)
                except:
                    return False
    return ret


@newLine
def CompileLua(src, luac=None, remove=True):
    '''编译指定路径下的lua文件。

    Param:

        src     指定路径。
        luac    指定一个编译luac程序。
        remove  完成后是否删除原文件。

    Return:

        bool    发生错误，返回False；否则返回True。
    '''

    if not luac:
        egxRoot = os.environ["ENGINEX_ROOT"]
        luac =  "tools/StarryXTools/trd/Mac/luac54"
        if platform.system() == 'Windows':
            luac = "tools/StarryXTools/trd/Windows/luac54.exe"
        elif platform.system() == 'Linux':
            luac = "tools/StarryXTools/trd/Linux/luac54"
        luac = os.path.join(egxRoot,luac)

    if platform.system() != 'Windows':
        os.chmod(luac, stat.S_IRWXO + stat.S_IRWXG + stat.S_IRWXU)

    luac = os.path.abspath(luac)
    oldCWD = os.getcwd()
    if not os.path.isdir(src):
        os.makedirs(src)
    os.chdir(src)
    luaList = [f for f in ListFiles() if f[-4:] == ".lua"]
    count = len(luaList)
    num = 0
    bName = os.path.basename(src)
    for lua in luaList:
        num += 1
        cmd = "%s -o \"%s\" \"%s\"" % (luac, lua + "c", lua)
        if os.system(cmd):
            os.chdir(oldCWD)
            return False
        elif remove:
            os.remove(lua)

        sys.stdout.write("\r编译%s [%d%%]->%s" %
                         (bName, int(num / count * 100), lua))
        sys.stdout.flush()

    os.chdir(oldCWD)
    return True


@newLine
def CompressPng(src, pngquant=None, qMin=50, qMax=85):
    '''压缩指定路径下的png图像。

    Param:

        src     指定路径。
        deal    指定一个压缩png图像的程序，一般，这个程序是pngquant。
        q       压缩质量。
        remove  完成后是否删除原文件。

    Return:

        bool    发生错误，返回False；否则返回True。
    '''

    if not pngquant:
        egxRoot = os.environ["ENGINEX_ROOT"]
        pngquant = "tools/StarryXTools/trd/Mac/pngquant-openmp"
        if(platform.system() == 'Windows'):
            pngquant = "tools/StarryXTools/trd/Windows/pngquant.exe"
        elif(platform.system() == 'Linux'):
            pngquant = "tools/StarryXTools/trd/Linux/pngquant"
        pngquant = os.path.join(egxRoot,pngquant)

    if platform.system() != 'Windows':
        os.chmod(pngquant, stat.S_IRWXO + stat.S_IRWXG + stat.S_IRWXU)

    pngList = [f for f in ListFiles(src, absName=True) if f[-4:] == ".png"]
    pngquant = os.path.abspath(pngquant)

    qMin = int(qMin)
    qMax = int(qMax)
    if qMin < 0:
        qMin = 0
    elif qMin > 100:
        qMin = 100

    if qMax < 1:
        qMax = 1
    elif qMax > 100:
        qMax = 100

    if qMin > qMax:
        qMin = qMax

    count = len(pngList)
    num = 0
    bName = os.path.basename(src)
    for png in pngList:
        num += 1
        newName = ""
        for s in png:
            if ord(s) > 255:
                newName = os.path.join(os.path.dirname(
                    png), "pngquant..rename.." + str(random.randrange(1000)) + ".png")
                os.rename(png, newName)
                break

        cmd = ""
        if newName:
            cmd = "%s --quality=%d-%d --ext=.png --force %s" % (
                pngquant, qMin, qMax, newName)
        else:
            cmd = "%s --quality=%d-%d --ext=.png --force %s" % (
                pngquant, qMin, qMax, png)
        ret = os.system(cmd)
        if newName:
            os.rename(newName, png)
        sys.stdout.write("\r压缩%s [%d%%]->%s" %
                         (bName, int(num / count * 100), png))
        sys.stdout.flush()
        if ret:
            return False
    return True


@newLine
def EncryptRes(src, pwd):
    r'''加密（aes-cfb）指定路径下的png/luac文件。
    iv将全部使用\0填充。

    Param:

        src     指定路径。
        pwd     加密密码，将被转换为字节，超过16字节将截断，不足将补\0。

    Return:

        bool    发生错误，返回False；否则返回True。
    '''
    resList = [f for f in ListFiles(
        src) if f[-4:] == ".png" or f[-5:] == ".luac" or f[-4:] == ".lua"]

    encryptSign = br')(@%%AES_Sign_@_'
    pwd = pwd.encode()
    pwdLen = len(pwd)
    if pwdLen > 16:
        pwd = pwd[:16]
    elif pwdLen < 16:
        pwd += (b'\0' * (16 - pwdLen))

    count = len(resList)
    num = 0
    bName = os.path.basename(src)
    for res in resList:
        num += 1
        try:
            with open(res, "r+b") as r:
                b16 = r.read(16)
                if b16 == encryptSign:
                    continue
                r.seek(0, 0)

                aes = AES.new(pwd, AES.MODE_CFB, iv=b'\0' *
                              16, segment_size=128)
                b = encryptSign + aes.encrypt(r.read())
                r.seek(0, 0)
                r.truncate(0)
                r.flush()
                r.write(b)
        except:
            return False
        sys.stdout.write("\r加密%s [%d%%]->%s" %
                         (bName, int(num / count * 100), res))
        sys.stdout.flush()
    return True


class HashType(Enum):
    MD5 = "md5",
    SHA1 = "sha1"


def CalcFileHash(filePath, hashType=HashType.MD5):
    '''计算文件哈希值。
    '''
    with open(filePath, 'rb') as f:
        h = None
        if hashType == HashType.MD5:
            h = hashlib.md5()
        elif hashType == HashType.SHA1:
            h = hashlib.sha1()
        h.update(f.read())
        return h.hexdigest()


@newLine
def CalcDirHash(path, hashType=HashType.MD5, withSize=True, compressed=False):
    '''计算文件夹下所有文件的哈希值，并以一个map返回。

    Param:

        hashType        计算hash的类型。
        withSize        是否一并返回文件的大小信息。
        compressed      对zip文件是否标记为需要解压。

    Return:

        dict
    '''

    ret = {}
    lF = ListFiles(path)
    count = len(lF)
    num = 0
    bName = os.path.basename(path)
    for f in lF:
        num += 1
        m = {
            hashType.value[0]: CalcFileHash(f, hashType)
        }
        if withSize:
            m["size"] = os.path.getsize(f)
        if compressed and f[-4:] == ".zip":
            m["compressed"] = True
        ret[os.path.relpath(f, path).replace("\\", "/")] = m
        sys.stdout.write("\r哈希%s [%d%%]->%s" %
                         (bName, int(num / count * 100), f))
        sys.stdout.flush()

    return ret


@newLine
def FtpUpload(addr, account, pwd, fList):
    '''上传文件列表到ftp。

    Param:
        addr        ftp地址。
        account     ftp账户。
        pwd         ftp密码。
        fList       文件列表。

    Return:

        bool        发生任何错误，均返回False；否则返回True。
    '''
    def _ftpMakeDirs(ftp, dirs):
        if not dirs:
            return
        try:
            ftp.mkd(dirs)
        except:
            return

    try:
        if addr[:6].lower() == "ftp://":
            addr = addr[6:]
        subDir = None
        idx = addr.find("/")
        if idx != -1:
            subDir = addr[idx + 1:]
            addr = addr[:idx]
        with FTP(addr, account, pwd, timeout=5) as ftp:
            _ftpMakeDirs(ftp, subDir)
            ftp.cwd(subDir)

            count = len(fList)
            num = 0
            for file in fList:
                num += 1
                with open(file, "rb") as fp:
                    _ftpMakeDirs(ftp, os.path.dirname(file))
                    ftp.storbinary("STOR " + file, fp)
                sys.stdout.write("\r上传 [%d%%]->%s" %
                                 (int(num / count * 100), file))
                sys.stdout.flush()
    except:
        return False
    return True


def GetOpt(argv, sStr, lList=None, usage=None):
    '''对getopt简单封装。
    当传入usage时，会自动添加-h和--help命令。
    usage可以为string和function。

    Param:

        argv        命令字符串。
        sStr        短命令。
        lList       长命令列表。
        usage       用法。

    Return:

        list|None    发生错误，返回None；否则返回List。
    '''
    opts = None
    try:
        if lList == None:
            lList = []
        lList.append("help")
        opts, _ = getopt.getopt(argv, sStr + "h", lList)
    except:
        if callable(usage):
            usage()
        elif isinstance(usage, str):
            print(usage)
        return opts

    for opt, _ in opts:
        if opt in ("-h", "--help"):
            if callable(usage):
                usage()
            elif isinstance(usage, str):
                print(usage)
            opts = []

    return opts


def LoadJson(path):
    '''加载json文件，失败返回None。
    '''
    try:
        with open(path, "rb") as f:
            return json.load(f)
    except:
        return None


def SaveJson(path, obj, indent=4):
    '''将一个对象保存为json文件。
    '''
    dn = os.path.dirname(path)
    if dn and not os.path.exists(dn):
        os.makedirs(dn)
    if os.path.exists(path):
        os.chmod(path, stat.S_IRWXO + stat.S_IRWXG + stat.S_IRWXU)
    with open(path, "w") as f:
        f.write(json.dumps(obj, ensure_ascii=False, indent=indent))


def LoadNetJson(url):
    '''从网络上获取一个json对象。
    '''
    try:
        res = requests.get(url=url, timeout=5)
        return res.json()
    except:
        return None


def ZipFiles(zipName, fList):
    '''将文件列表中的文件压缩至zip文件中。

    Param:
        zipName         zip文件名。
        fList           文件列表。

    Return:

        bool            发生任何错误，都将返回False，否则返回True。
    '''
    try:
        with zipfile.ZipFile(zipName, "w", zipfile.ZIP_DEFLATED) as f:
            for file in fList:
                f.write(file)
    except:
        return False
    return True


def __GetchUnix():
    import sys
    import tty
    import termios
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        ch = sys.stdin.read(1)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch


def __GetchWindows():
    import msvcrt
    return msvcrt.getch().decode()


def GetChar(pStr=None):
    if pStr:
        print(pStr)
    try:
        return __GetchWindows()
    except ImportError:
        return __GetchUnix()


def GetChars(chars, pStr=None):
    print(pStr)
    while(True):
        c = GetChar().lower()
        if c in chars:
            return c


def YesOrNo(pStr=None, acceptNone=True):
    '''接受一个Y键或N键。

    Param:

        pStr            打印信息。
        acceptNone      是否接受单独的回车，此时返回None。

    Return:

        bool | None
    '''
    print(pStr)
    while(True):
        c = GetChar().lower()
        if acceptNone and c == "\r":
            return None
        if c == "y":
            return True
        elif c == "n":
            return False
