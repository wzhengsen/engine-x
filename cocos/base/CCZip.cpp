/****************************************************************************
 Copyright (c) 2021 wzhengsen

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "CCZip.h"
#include <regex>
using namespace cocos2d;

#if _WIN32
static std::string TryG2U(const std::string& gbk) {
    return utils::GbkToUtf8(gbk);
}

static std::string TryU2G(const std::string& utf8) {
    return utils::Utf8ToGbk(utf8);
}
#else
static std::string TryG2U(const std::string& gbk) {
    return gbk;
}

static std::string TryU2G(const std::string& utf8) {
    return utf8;
}
#endif

static int LocateFileByUtf8(unzFile zip, const std::string_view& fileName) {
    return unzLocateFile(zip, fileName.data(), [](unzFile file, const char* f1, const char* f2) {
        unz_file_info fileInfo = {};
        if (unzGetCurrentFileInfo(file, &fileInfo, nullptr, 0, nullptr, 0, nullptr, 0) == UNZ_OK) {
            // 0x0800 means that the filename is encoded by utf8.
            // From https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT
            std::string name = fileInfo.flag & 0x0800 ? f1 : utils::GbkToUtf8(f1);
            if (name == f2) {
                return 0;
            }
        }
        return 1;
    });
}

/****************Zip begin****************/
Zip::Zip(const std::string& filePath) {
    _fOpenFilePath = TryU2G(FileUtils::getInstance()->fullPathForFilename(filePath));
    if (_fOpenFilePath.empty()) {
        _fOpenFilePath = TryU2G(filePath);
    }
}

bool Zip::IsValid() const noexcept {
    return _zip != nullptr;
}

void Zip::SetProcessHandler(const ProcessHandler& handler) {
    _processHandler = handler;
}

void Zip::SetErrorHandler(const ErrorHandler& handler) {
    _errorHandler = handler;
}

void Zip::OnProcess(const std::string& fileName, uint32_t idx, uint32_t count) {
    if (!_processHandler) {
        return;
    }
    if (_inAsync) {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread(
            std::bind(_processHandler, this, fileName, idx, count)
        );
    }
    else {
        _processHandler(this, fileName, idx, count);
    }
}

void Zip::OnError(ErrorCode code, const std::string& reason) {
    if (!_errorHandler) {
        return;
    }
    if (_inAsync) {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread(
            std::bind(_errorHandler, this, code, reason)
        );
    }
    else {
        _errorHandler(this, code, reason);
    }
}

void Zip::WorkAsync(const std::string& path, const char* password) {
    std::string passwordStr = password ? password : "";
    std::string _path = path;
    AsyncTaskPool::getInstance()->enqueue(
        AsyncTaskPool::TaskType::TASK_OTHER,
        [this, passwordStr, _path, password]() {
        this->_inAsync = true;
        try {
            this->Work(_path, password ? passwordStr.c_str() : password);
        }
        catch (...) {
            this->_inAsync = false;
        }
        this->_inAsync = false;
    });
}

uint32_t Zip::MakeItemDosDate(const char* path) noexcept {
    uint32_t dos_date = 0;
#ifdef _WIN32
    const auto gbk = TryU2G(path);
    FILETIME ftm_local = {};
    HANDLE find = nullptr;
    WIN32_FIND_DATAA ff32 = {};

    find = FindFirstFileA(gbk.c_str(), &ff32);
    if (find != INVALID_HANDLE_VALUE) {
        FileTimeToLocalFileTime(&(ff32.ftLastWriteTime), &ftm_local);
        FileTimeToDosDateTime(&ftm_local, ((LPWORD)&dos_date) + 1, ((LPWORD)&dos_date) + 0);
        FindClose(find);
    }
#else
    struct stat s {};
    time_t tm_t = 0;

    memset(&s, 0, sizeof(s));

    if (strcmp(path, "-") != 0) {
        size_t len = strlen(path);
        char* name = (char*)malloc(len + 1);
        strncpy(name, path, len + 1);
        name[len] = 0;
        if (name[len - 1] == '/')
            name[len - 1] = 0;

        /* Not all systems allow stat'ing a file with / appended */
        if (stat(name, &s) == 0) {
            tm_t = s.st_mtime;
        }
        free(name);
    }

    dos_date = utils::Time2DosDate(tm_t);
#endif
    return dos_date;
}

uLong Zip::MakeItemCrc32(FILE* inf) {
    if (!inf) {
        return 0;
    }
    std::unique_ptr<char[]>readBuff(new char[8192 * 4]);
    const auto cur = ::ftell(inf);
    ::fseek(inf, 0, SEEK_SET);
    size_t readSize = 0;
    uLong calculate_crc = crc32(0L, Z_NULL, 0);
    do {
        readSize = ::fread(readBuff.get(), sizeof(char), 8192 * 4, inf);
        if (readSize > 0) {
            calculate_crc = crc32(calculate_crc, reinterpret_cast<const Bytef*>(readBuff.get()), static_cast<uInt>(readSize));
        }
    } while (readSize == 8192 * 4);

    ::fseek(inf, cur, SEEK_SET);

    return calculate_crc;
}
/****************Zip end****************/

/****************RZip begin****************/
const RZip::ZipInfo& RZip::ZipItem::GetInfo() const noexcept {
    return _info;
}

bool RZip::ZipItem::Read(void* buff, size_t len, const char* password) const {
    if (!_rZip->_zip) {
        return false;
    }

    const std::string& name = _info.name;
    const size_t length = name.length();
    if (length > 0 && (name[length - 1] == '/' || name[length - 1] == '\\')) {
        // The ZipItem is a directory.
        return false;
    }

    // If RZip has old file pos,record it.
    unz_file_pos oldFilePos = {};
    const bool hasOldPos = unzGetFilePos(_rZip->_zip, &oldFilePos) == UNZ_OK;

    unz_file_pos pos = _info.pos;
    const bool ret = unzGoToFilePos(_rZip->_zip, &pos) == UNZ_OK
        && unzOpenCurrentFile3(_rZip->_zip, nullptr, nullptr, 0, password) == UNZ_OK
        && unzReadCurrentFile(_rZip->_zip, buff, static_cast<uint32_t>(len)) >= 0
        && unzCloseCurrentFile(_rZip->_zip) == UNZ_OK;

    if (hasOldPos) {
        // Recover old file pos.
        unzGoToFilePos(_rZip->_zip, &oldFilePos);
    }

    return ret;
}

bool RZip::ZipItem::Read(std::vector<const ZipItem*>& vecItem) const {
    if (!_rZip->_zip) {
        return false;
    }

    const std::string& name = _info.name;
    const size_t length = name.length();
    if (length > 0 && name[length - 1] != '/' && name[length - 1] != '\\') {
        // The ZipItem is a file.
        return false;
    }

    // If RZip has old file pos,record it.
    unz_file_pos oldFilePos = {};
    const bool hasOldPos = unzGetFilePos(_rZip->_zip, &oldFilePos) == UNZ_OK;

    vecItem.clear();
    const auto& selfName = _info.name;
    const auto selfNameLen = selfName.length();
    for (const auto& item : *_rZip) {
        if (&item == this) {
            continue;
        }
        const auto& name = item.GetInfo().name;
        if (name.length() > selfNameLen && name.substr(0, selfNameLen) == selfName) {
            vecItem.push_back(&item);
        }
    }

    if (hasOldPos) {
        // Recover old file pos.
        unzGoToFilePos(_rZip->_zip, &oldFilePos);
    }

    return true;
}

RZip::ZipItemIterator& RZip::ZipItemIterator::operator=(const RZip::ZipItemIterator& iter) {
    _item = iter._item;
    return *this;
}
bool RZip::ZipItemIterator::operator!=(const RZip::ZipItemIterator& iter) const {
    return _item != iter._item;
}
bool RZip::ZipItemIterator::operator==(const RZip::ZipItemIterator& iter) const {
    return _item == iter._item;
}
RZip::ZipItemIterator& RZip::ZipItemIterator::operator++() {
    _item->_rZip->GoTo(_item);
    _item = _item->_rZip->Next();
    return *this;
}
RZip::ZipItemIterator RZip::ZipItemIterator::operator++(int) {
    ZipItemIterator tmp = *this;
    _item->_rZip->GoTo(_item);
    _item = _item->_rZip->Next();
    return tmp;
}
const RZip::ZipItem& RZip::ZipItemIterator::operator* () const {
    return *_item;
}

RZip* RZip::Create(const std::string& filePath, Encoding code) {
    auto rZip = new RZip(filePath, code);
    if (!rZip->Open()) {
        delete rZip;
        return nullptr;
    }
    return rZip;
}


RZip::~RZip() {
    Close();
}

bool RZip::Open() {
    if (_zip) {
        return true;
    }
    _zip = unzOpen(_fOpenFilePath.c_str());
    if (_zip) {
        unz_global_info globalInfo = {};
        if (unzGetGlobalInfo(_zip, &globalInfo) != UNZ_OK) {
            // If can't get global info,close the zip file.
            unzClose(_zip);
            _zip = nullptr;
        }
        else {
            _itemCount = globalInfo.number_entry;
        }
    }
    return IsValid();
}

void RZip::Close() {
    if (_zip) {
        unzClose(_zip);
        _zip = nullptr;
    }
    _mapZipItem.clear();
}

const RZip::ZipItem* RZip::Current() {
    if (!_zip) {
        _curZipItem = nullptr;
        return _curZipItem;
    }

    unz_file_pos filePos = { 0,0 };
    // Get current item pos into filePos.
    if (unzGetFilePos(_zip, &filePos) != UNZ_OK) {
        // Invalid file.
        _curZipItem = nullptr;
        return _curZipItem;
    }

    // Find in cache or create new one?
    const uint32_t pos = filePos.pos_in_zip_directory;
    const bool isNew = CheckZipItem(pos);
    if (isNew) {
        unz_file_info fileInfo = {};
        char fileName[RZip::ZipInfo::MaxFileNameInZip] = { 0 };

        // Set info for new item.
        if (unzGetCurrentFileInfo(_zip, &fileInfo, fileName, sizeof(fileName), nullptr, 0, nullptr, 0) == UNZ_OK) {
            bool utf8 = true;
            if (_code == Encoding::Gbk) {
                utf8 = false;
            }
            else if (_code == Encoding::Auto) {
                // 0x0800 means that the filename is encoded by utf8.
                // From https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT
                utf8 = fileInfo.flag & 0x0800;
            }
            ZipInfo info = {
                !utf8 ? utils::GbkToUtf8(fileName) : fileName,
                utils::DosDate2Time(fileInfo.dos_date),
                fileInfo.uncompressed_size,
                static_cast<bool>(fileInfo.flag & 1),
                filePos
            };
            _mapZipItem.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(pos),
                std::forward_as_tuple(this, info)
            );
        }
    }
    _curZipItem = &_mapZipItem.at(pos);;
    return _curZipItem;
}

bool RZip::CheckZipItem(uint32_t pos) const noexcept {
    return _mapZipItem.find(pos) == _mapZipItem.cend();
}

const RZip::ZipItem* RZip::First() {
    if (!_zip || unzGoToFirstFile(_zip) != UNZ_OK) {
        // No first file.
        _curZipItem = nullptr;
        return nullptr;
    }

    return Current();
}

const RZip::ZipItem* RZip::Next() {
    if (!_zip || !_curZipItem || unzGoToNextFile(_zip) != UNZ_OK) {
        // No next file.
        _curZipItem = nullptr;
        return nullptr;
    }

    return Current();
}

void RZip::GoTo(const RZip::ZipItem* item) {
    if (!_zip || !item) {
        return;
    }
    unz_file_pos pos = item->_info.pos;
    if (UNZ_OK == unzGoToFilePos(_zip, &pos)) {
        _curZipItem = item;
    }
}

const RZip::ZipItem* RZip::Locate(const std::string& fileName) {
    if (!_zip) {
        return nullptr;
    }
    auto cur = Current();
    if (LocateFileByUtf8(_zip,fileName) != UNZ_OK) {
        // No file found.
        GoTo(cur);
        _curZipItem = nullptr;
        return nullptr;
    }

    auto ret = Current();
    GoTo(cur);
    return ret;
}

std::vector<const RZip::ZipItem*> RZip::Match(const std::string& fileName) {
    std::vector<const ZipItem*> items = {};

    auto cur = Current();
    for (auto& item : *this) {
        if (std::regex_match(item._info.name, std::regex(fileName))) {
            items.push_back(&item);
        }
    }
    GoTo(cur);
    return items;
}

void RZip::Work(const std::string& path, const char* password) {
    if (!_zip) {
        return OnError(ErrorCode::ZipError, "Can't read Zip,maybe closed?");
    }
    if (path.empty()) {
        return OnError(ErrorCode::PathEmptyError, "You passed a empty path param.");
    }

    // Get info about the zip file.
    unz_global_info globalInfo = {};
    if (unzGetGlobalInfo(_zip, &globalInfo) != UNZ_OK) {
        return OnError(ErrorCode::GlobalInfoError, "Can't get info about the zip file.");
    }

    const FileUtils* const fileUtils = FileUtils::getInstance();
    std::string root = path;
    if (root.find_last_of("/\\") != root.length() - 1) {
        root += "/";
    }

    if (!fileUtils->createDirectory(root)) {
        // Failed to create directory.
        return OnError(ErrorCode::CreateDirError, "Failed to create directory - " + root);
    }

    if (!globalInfo.number_entry) {
        return OnProcess(root, 0, 0);
    }

    // Buffer to hold data read from the zip file
    std::unique_ptr<char[]>readBuffer(new char[8192 * 4]);
    // Loop to extract all files.
    for (uint32_t i = 0; i < globalInfo.number_entry; ++i) {
        // Get info about current file.
        unz_file_info fileInfo = {};
        char fileName[ZipInfo::MaxFileNameInZip] = {};
        if (unzGetCurrentFileInfo(_zip, &fileInfo, fileName, sizeof(fileName),
            nullptr, 0,
            nullptr, 0) != UNZ_OK) {
            return OnError(ErrorCode::ItemInfoError, "Can't get info about the zip item.");
        }
        bool utf8 = true;
        if (_code == Encoding::Gbk) {
            utf8 = false;
        }
        else if (_code == Encoding::Auto) {
            // 0x0800 means that the filename is encoded by utf8.
            // From https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT
            utf8 = fileInfo.flag & 0x0800;
        }
        const std::string utf8File = utf8 ? fileName : utils::GbkToUtf8(fileName);

        // Output path.
        const std::string outPath = TryU2G(root + utf8File);

        // utf8 path.
        const std::string utf8Path = root + utf8File;

        // Check if this entry is a directory or a file.
        const size_t fileNameLength = utf8Path.length();
        if (fileNameLength > 0 && (utf8Path[fileNameLength - 1] == '/' || utf8Path[fileNameLength - 1] == '\\')) {
            //There are not directory entry in some case.
            //So we need to create directory when decompressing file entry
            if (!fileUtils->createDirectory(utf8Path.substr(0, fileNameLength - 1))) {
                // Failed to create directory
                return OnError(ErrorCode::CreateDirError, "Failed to create directory - " + utf8Path);
            }
        }
        else {
            // Create all directories in advance to avoid issue
            const size_t found = utf8Path.find_last_of("/\\");
            std::string dir = found == std::string::npos ? utf8Path : utf8Path.substr(0, found);
            if (!fileUtils->createDirectory(dir)) {
                // Failed to create directory
                return OnError(ErrorCode::CreateDirError, "Failed to create directory - " + dir);
            }

            // Entry is a file, so extract it.
            // Open current file.
            size_t error = unzOpenCurrentFile3(_zip, nullptr, nullptr, 0, password);
            if (error != UNZ_OK) {
                if (error == UNZ_BADPASSWORD) {
                    return OnError(ErrorCode::PasswordError, std::string("Bad password - ") + utf8File);
                }
                return OnError(ErrorCode::OpenItemError, std::string("Can't open item - ") + utf8File);
            }

            // Create a file to store current file.
            FILE* out = std::fopen(outPath.c_str(), "wb");
            if (!out) {
                unzCloseCurrentFile(_zip);
                return OnError(ErrorCode::CreateFileError, "Can't create new file - " + utf8Path);
            }

            // Write current file content to destinate file.
            int ret = UNZ_OK;
            do {
                ret = unzReadCurrentFile(_zip, readBuffer.get(), 8192 * 4);
                if (ret < 0) {
                    std::fclose(out);
                    unzCloseCurrentFile(_zip);
                    if (Z_DATA_ERROR == ret) {
                        return OnError(ErrorCode::PasswordError, std::string("Maybe password is wrong. - ") + utf8File);
                    }
                    return OnError(ErrorCode::ReadItemError, std::string("Can't read item - ") + utf8File);
                }

                if (ret > 0) {
                    if (1 != std::fwrite(readBuffer.get(), ret, 1, out)) {
                        return OnError(ErrorCode::WriteFileError, "Can't write file - " + utf8Path);
                    }
                }
            } while (ret > 0);
            std::fclose(out);
        }

        unzCloseCurrentFile(_zip);

        // Goto next entry listed in the zip file.
        if ((i + 1) < globalInfo.number_entry) {
            if (unzGoToNextFile(_zip) != UNZ_OK) {
                return OnError(ErrorCode::Unknown, "Unkown error.");
            }
        }

        OnProcess(utf8File, i + 1, globalInfo.number_entry);
    }
}

RZip::ZipItemIterator RZip::begin() {
    return ZipItemIterator(First());
}

const RZip::ZipItemIterator& RZip::end() {
    static auto zi = ZipItemIterator(nullptr);
    return zi;
}

/****************RZip end****************/

/****************WZip begin****************/
WZip* WZip::Create(const std::string& filePath) {
    auto wZip = new WZip(filePath);
    if (!wZip->Open()) {
        delete wZip;
        return nullptr;
    }
    return wZip;
}

WZip::~WZip() {
    Close();
}

bool WZip::Open() {
    if (_zip) {
        return true;
    }

    // Check file exist?
    FILE* file = std::fopen(_fOpenFilePath.c_str(), "rb");
    if (file) {
        std::fclose(file);
    }
    _zip = zipOpen(_fOpenFilePath.c_str(), file ? APPEND_STATUS_ADDINZIP : APPEND_STATUS_CREATE);
    return IsValid();
}

void WZip::Close() {
    if (_zip) {
        zipClose(_zip, nullptr);
        _zip = nullptr;
    }
}

void WZip::Work(const std::string& path, const char* password) {
    if (!_zip) {
        return OnError(ErrorCode::ZipError, "Can't write Zip,maybe closed?");
    }
    if (path.empty()) {
        return OnError(ErrorCode::PathEmptyError, "You passed a empty path param.");
    }
    const auto fu = FileUtils::getInstance();
    bool isDir = path[path.length() - 1] == '/';
    if (isDir) {
        // path is directory really?
        if (!fu->isDirectoryExist(path)) {
            return OnError(ErrorCode::DirNotExistError, "Directory does not exist - " + path);
        }
        return PushDir(path, password);
    }
    else {
        // path is file really?
        if (!fu->isFileExist(path)) {
            // Not a file,guess it is a directory?
            if (!fu->isDirectoryExist(path)) {
                return OnError(ErrorCode::FileNotExistError, "File does not exist - " + path);
            }
            else {
                return PushDir(path, password);
            }
        }
        return PushFile(path, password);
    }
}

bool WZip::CloseUnzipAndReopenZip(unzFile unz) {
    if (unz) {
        unzClose(unz);
    }
    _zip = zipOpen(_fOpenFilePath.c_str(), APPEND_STATUS_ADDINZIP);
    if (!_zip) {
        OnError(ErrorCode::ReopenError, "Can't reopen zip file - " + TryG2U(_fOpenFilePath));
        return false;
    }
    return true;
}

void WZip::PushDir(const std::string& dir, const char* password) {
    std::string newDir = dir;
    if (dir[dir.length() - 1] != '/') {
        newDir += '/';
    }
    std::vector<std::string> list = {};
    std::vector<std::string> relList = {};
    FileUtils::getInstance()->listFilesRecursively(dir, &list);

    // Close zip file first for find duplicative file.
    Close();
    unzFile f = unzOpen(_fOpenFilePath.c_str());
    if (!f) {
        if (!CloseUnzipAndReopenZip(f)) {
            return;
        }
        return OnError(ErrorCode::OpenZipError, "Open zip error - " + TryG2U(_fOpenFilePath));
    }
    for (const auto& item: list) {
        // Relative path in zip item.
        auto relName = item.substr(newDir.length());
        relList.push_back(relName);
        const bool found = LocateFileByUtf8(f, relName) == UNZ_OK;
        if (found) {
            // Already exist?
            if (!CloseUnzipAndReopenZip(f)) {
                return;
            }
            return OnError(ErrorCode::DuplicateFileError, "Duplicate file - " + relName);
        }
    }
    if (!CloseUnzipAndReopenZip(f)) {
        return;
    }

    // Create directory first.
    const auto size = relList.size();
    for (size_t idx = 0; idx < size; idx++) {
        const std::string& relItem = relList[idx];
        const std::string& item = list[idx];

        const bool isDir = relItem[relItem.length() - 1] == '/';
        // crc32
        uLong crc = 0;
        FILE* rf = nullptr;
        zip_fileinfo zi = {MakeItemDosDate(item.c_str()),0,0};
        const char* pwd = nullptr;
        if (!isDir) {
            rf = std::fopen(TryU2G(item).c_str(), "rb");
            if (!rf) {
                return OnError(ErrorCode::ReadFileError, "Can't open file - " + item);
            }
            crc = MakeItemCrc32(rf);
            pwd = password;
        }

        // open internal file.
        bool ok = zipOpenNewFileInZip4_64(_zip, relItem.c_str(), &zi,
            nullptr, 0,
            nullptr, 0,
            nullptr,
            Z_DEFLATED, Z_DEFAULT_COMPRESSION,
            0,
            -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY,
            pwd, crc,
            // 0x0800 means that the filename is encoded by utf8.
            // From https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT
            MadeBy, 0x0800, 0) == ZIP_OK;
        if (!ok) {
            return OnError(ErrorCode::InternalFileError, "Can't open internal file - " + relItem);;
        }

        if (!isDir) {
            std::unique_ptr<char[]> readBuff(new char[8192 * 4]);
            size_t readSize = 0;
            do {
                readSize = std::fread(readBuff.get(), sizeof(char), 8192 * 4, rf);
                ok = zipWriteInFileInZip(_zip, readBuff.get(), static_cast<uint32_t>(readSize)) == ZIP_OK;
            } while (readSize == 8192 * 4 && ok);

            std::fclose(rf);
        }
        // close internal file.
        zipCloseFileInZip(_zip);

        if (!ok) {
            return OnError(ErrorCode::InternalFileError, "Can't write zip file - " + relItem);
        }
        OnProcess(relItem, static_cast<uint32_t>(idx + 1), static_cast<uint32_t>(size));
    }
}

void WZip::PushFile(const std::string& file, const char* password) {
    const auto fullPath = FileUtils::getInstance()->fullPathForFilename(file);
    const std::string inFile = TryU2G(fullPath);
    const auto idx = fullPath.find_last_of("/");
    std::string baseName = idx != std::string::npos ? fullPath.substr(idx + 1) : fullPath;
    // Close zip file first for find duplicative file.
    Close();
    unzFile f = unzOpen(_fOpenFilePath.c_str());
    if (!f) {
        if (!CloseUnzipAndReopenZip(f)) {
            return;
        }
        return OnError(ErrorCode::OpenZipError, "Open zip error - " + TryG2U(_fOpenFilePath));
    }
    const bool found = LocateFileByUtf8(f, baseName) == UNZ_OK;
    if (!CloseUnzipAndReopenZip(f)) {
        return;
    }

    if (found) {
        // Already exist?
        return OnError(ErrorCode::DuplicateFileError, "Duplicate file - " + baseName);
    }

    FILE* rf = std::fopen(inFile.c_str(), "rb");
    if (!rf) {
        return OnError(ErrorCode::ReadFileError, "Can't read file - " + file);
    }

    // Crc32
    const uLong crc = MakeItemCrc32(rf);
    zip_fileinfo zi = {
        MakeItemDosDate(fullPath.c_str()),
        0,0
    };

    // open internal file.
    bool ok = zipOpenNewFileInZip4_64(_zip, baseName.c_str(), &zi,
        nullptr, 0,
        nullptr, 0,
        nullptr,
        Z_DEFLATED, Z_DEFAULT_COMPRESSION,
        0,
        -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY,
        password, crc,
        // 0x0800 means that the filename is encoded by utf8.
        // From https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT
        MadeBy, 0x0800, 0) == ZIP_OK;
    if (!ok) {
        return OnError(ErrorCode::InternalFileError, "Can't open internal file - " + baseName);;
    }

    std::unique_ptr<char[]> readBuff(new char[8192 * 4]);
    size_t readSize = 0;
    do {
        readSize = std::fread(readBuff.get(), sizeof(char), 8192 * 4, rf);
        ok = zipWriteInFileInZip(_zip, readBuff.get(), static_cast<uint32_t>(readSize)) == ZIP_OK;
    } while (readSize == 8192 * 4 && ok);

    std::fclose(rf);
    // close internal file.
    zipCloseFileInZip(_zip);

    if (!ok) {
        return OnError(ErrorCode::InternalFileError, "Can't write zip file - " + baseName);
    }
    return OnProcess(baseName, 1, 1);
}

/****************WZip end****************/