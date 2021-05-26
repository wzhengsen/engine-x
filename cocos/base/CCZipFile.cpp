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
#include "CCZipFile.h"
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

/****************ZipFile begin****************/
ZipFile::ZipFile(const std::string& filePath,ZipFile::Encoding code) {
    _code = code;
    _fOpenFilePath = TryU2G(FileUtils::getInstance()->fullPathForFilename(filePath));
    if (_fOpenFilePath.empty()) {
        _fOpenFilePath = TryU2G(filePath);
    }
}

bool ZipFile::IsValid() const noexcept {
    return _zip != nullptr;
}

void ZipFile::SetProcessHandler(const ProcessHandler& handler) {
    _processHandler = handler;
}

void ZipFile::SetErrorHandler(const ErrorHandler& handler) {
    _errorHandler = handler;
}

void ZipFile::OnProcess(const std::string& fileName, uint32_t idx, uint32_t count) {
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

void ZipFile::OnError(ErrorCode code, const std::string& reason) {
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

void ZipFile::WorkAsync(const std::string& path, const char* password) {
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

uint32_t ZipFile::MakeItemDosDate(const char* path) noexcept {
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

uLong ZipFile::MakeItemCrc32(FILE* inf) {
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
/****************ZipFile end****************/

/****************RZipFile begin****************/
const RZipFile::ZipInfo& RZipFile::ZipItem::GetInfo() const noexcept {
    return _info;
}

bool RZipFile::ZipItem::Read(void* buff, size_t len, const char* password) const {
    if (!_rZip->_zip) {
        return false;
    }

    const std::string& name = _info.name;
    const size_t length = name.length();
    if (length > 0 && (name[length - 1] == '/' || name[length - 1] == '\\')) {
        // The ZipItem is a directory.
        return false;
    }

    // If RZipFile has old file pos,record it.
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

bool RZipFile::ZipItem::Read(std::vector<const ZipItem*>& vecItem) const {
    if (!_rZip->_zip) {
        return false;
    }

    const std::string& name = _info.name;
    const size_t length = name.length();
    if (length > 0 && name[length - 1] != '/' && name[length - 1] != '\\') {
        // The ZipItem is a file.
        return false;
    }

    // If RZipFile has old file pos,record it.
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

RZipFile::ZipItemIterator& RZipFile::ZipItemIterator::operator=(const RZipFile::ZipItemIterator& iter) {
    _item = iter._item;
    return *this;
}
bool RZipFile::ZipItemIterator::operator!=(const RZipFile::ZipItemIterator& iter) const {
    return _item != iter._item;
}
bool RZipFile::ZipItemIterator::operator==(const RZipFile::ZipItemIterator& iter) const {
    return _item == iter._item;
}
RZipFile::ZipItemIterator& RZipFile::ZipItemIterator::operator++() {
    _item->_rZip->GoTo(_item);
    _item = _item->_rZip->Next();
    return *this;
}
RZipFile::ZipItemIterator RZipFile::ZipItemIterator::operator++(int) {
    ZipItemIterator tmp = *this;
    _item->_rZip->GoTo(_item);
    _item = _item->_rZip->Next();
    return tmp;
}
const RZipFile::ZipItem& RZipFile::ZipItemIterator::operator* () const {
    return *_item;
}

RZipFile* RZipFile::Create(const std::string& filePath,ZipFile::Encoding code) {
    auto rZip = new RZipFile(filePath,code);
    if (!rZip->Open()) {
        delete rZip;
        return nullptr;
    }
    return rZip;
}

RZipFile::~RZipFile() {
    Close();
}

bool RZipFile::Open() {
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

void RZipFile::Close() {
    if (_zip) {
        unzClose(_zip);
        _zip = nullptr;
    }
    _mapZipItem.clear();
}

const RZipFile::ZipItem* RZipFile::Current() {
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
        char fileName[RZipFile::ZipInfo::MaxFileNameInZip] = { 0 };

        // Set info for new item.
        if (unzGetCurrentFileInfo(_zip, &fileInfo, fileName, sizeof(fileName), nullptr, 0, nullptr, 0) == UNZ_OK) {
            ZipInfo info = {
                _code == Encoding::Gbk ? utils::GbkToUtf8(fileName) : fileName,
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

bool RZipFile::CheckZipItem(uint32_t pos) const noexcept {
    return _mapZipItem.find(pos) == _mapZipItem.cend();
}

const RZipFile::ZipItem* RZipFile::First() {
    if (!_zip || unzGoToFirstFile(_zip) != UNZ_OK) {
        // No first file.
        _curZipItem = nullptr;
        return nullptr;
    }

    return Current();
}

const RZipFile::ZipItem* RZipFile::Next() {
    if (!_zip || !_curZipItem || unzGoToNextFile(_zip) != UNZ_OK) {
        // No next file.
        _curZipItem = nullptr;
        return nullptr;
    }

    return Current();
}

void RZipFile::GoTo(const RZipFile::ZipItem* item) {
    if (!_zip || !item) {
        return;
    }
    unz_file_pos pos = item->_info.pos;
    if (UNZ_OK == unzGoToFilePos(_zip, &pos)) {
        _curZipItem = item;
    }
}

const RZipFile::ZipItem* RZipFile::Locate(const std::string& fileName) {
    if (!_zip) {
        return nullptr;
    }
    auto cur = Current();
    if (unzLocateFile(_zip, (_code == Encoding::Gbk ? utils::Utf8ToGbk(fileName) : fileName).c_str(), nullptr) != UNZ_OK) {
        // No file found.
        GoTo(cur);
        _curZipItem = nullptr;
        return nullptr;
    }

    auto ret = Current();
    GoTo(cur);
    return ret;
}

std::vector<const RZipFile::ZipItem*> RZipFile::Match(const std::string& fileName) {
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

void RZipFile::Work(const std::string& path, const char* password) {
    if (!_zip) {
        return OnError(ErrorCode::ZipError, "Can't read ZipFile,maybe closed?");
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
        const std::string utf8File = _code == Encoding::Utf8 ? fileName : utils::GbkToUtf8(fileName);

        // Output path.
        const std::string outPath = TryU2G(root + utf8File);

        // utf8 path.
        const std::string utf8Path = root + utf8File;

        // Check if this entry is a directory or a file.
        const size_t filenameLength = std::strlen(fileName);
        if (filenameLength > 0 && (fileName[filenameLength - 1] == '/' || fileName[filenameLength - 1] == '\\')) {
            //There are not directory entry in some case.
            //So we need to create directory when decompressing file entry
            if (!fileUtils->createDirectory(utf8Path.substr(0, filenameLength - 1))) {
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
            error = UNZ_OK;
            do {
                error = unzReadCurrentFile(_zip, readBuffer.get(), 8192 * 4);
                if (error < 0) {
                    std::fclose(out);
                    unzCloseCurrentFile(_zip);
                    return OnError(ErrorCode::ReadItemError, std::string("Can't read item - ") + utf8File);
                }

                if (error > 0) {
                    if (1 != std::fwrite(readBuffer.get(), error, 1, out)) {
                        return OnError(ErrorCode::WriteFileError, "Can't write file - " + utf8Path);
                    }
                }
            } while (error > 0);
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

RZipFile::ZipItemIterator RZipFile::begin() {
    return ZipItemIterator(First());
}

const RZipFile::ZipItemIterator& RZipFile::end() {
    static auto zi = ZipItemIterator(nullptr);
    return zi;
}

/****************RZipFile end****************/

/****************WZipFile begin****************/
WZipFile* WZipFile::Create(const std::string& filePath,ZipFile::Encoding code) {
    auto wZip = new WZipFile(filePath,code);
    if (!wZip->Open()) {
        delete wZip;
        return nullptr;
    }
    return wZip;
}

WZipFile::~WZipFile() {
    Close();
}

bool WZipFile::Open() {
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

void WZipFile::Close() {
    if (_zip) {
        zipClose(_zip, nullptr);
        _zip = nullptr;
    }
}

void WZipFile::Work(const std::string& path, const char* password) {
    if (!_zip) {
        return OnError(ErrorCode::ZipError, "Can't write ZipFile,maybe closed?");
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

void WZipFile::PushDir(const std::string& dir, const char* password) {
    std::string newDir = dir;
    if (dir[dir.length() - 1] != '/') {
        newDir += '/';
    }
    std::vector<std::string> list = {};
    FileUtils::getInstance()->listFilesRecursively(dir, &list);

    unzFile f = unzOpen(_fOpenFilePath.c_str());
    if (!f) {
        return OnError(ErrorCode::OpenZipError, "Open zip error - " + TryG2U(_fOpenFilePath));
    }
    for (const auto& file : list) {
        // Relative path in zip file.
        auto relName = file.substr(newDir.length());
        const bool found = unzLocateFile(f, relName.c_str(), nullptr) == UNZ_OK;
        if (found) {
            // Already exist?
            unzClose(f);
            return OnError(ErrorCode::DuplicateFileError, "Duplicate file - " + relName);
        }
    }
    unzClose(f);

    // for (const auto& file : list) {
    //     // Relative path in zip file.
    //     auto relNameU = file.substr(newDir.length());
    //     auto relNameG = TryU2G(relNameU);
    //     const bool found = unzLocateFile(f, relNameG.c_str(), nullptr) == UNZ_OK;
    //     if (found) {
    //         // Already exist?
    //         unzClose(f);
    //         return OnError(ErrorCode::DuplicateFileError, "Duplicate file - " + relNameU);
    //     }
    // }
}

void WZipFile::PushFile(const std::string& file, const char* password) {
    const auto fullPath = FileUtils::getInstance()->fullPathForFilename(file);
    const std::string gbk = TryU2G(fullPath);
    const auto idx = gbk.find_last_of("/");
    std::string baseName = TryG2U(idx != std::string::npos ? gbk.substr(idx + 1) : gbk);

    unzFile f = unzOpen(_fOpenFilePath.c_str());
    if (!f) {
        return OnError(ErrorCode::OpenZipError, "Open zip error - " + TryG2U(_fOpenFilePath));
    }
    const bool found = unzLocateFile(f, baseName.c_str(), nullptr) == UNZ_OK;
    unzClose(f);
    if (found) {
        // Already exist?
        return OnError(ErrorCode::DuplicateFileError, "Duplicate file - " + baseName);
    }

    FILE* rf = std::fopen(gbk.c_str(), "rb");
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
    bool err = zipOpenNewFileInZip4_64(_zip, baseName.c_str(), &zi,
        nullptr, 0,
        nullptr, 0,
        nullptr,
        Z_DEFLATED, Z_DEFAULT_COMPRESSION,
        0,
        -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY,
        password, crc,
        0, 0, 0) == ZIP_OK;
    if (!err) {
        return OnError(ErrorCode::InternalFileError, "Can't open internal file - " + baseName);;
    }

    std::unique_ptr<char[]> readBuff(new char[8192 * 4]);
    size_t readSize = 0;
    do {
        readSize = std::fread(readBuff.get(), sizeof(char), 8192 * 4, rf);
        err = zipWriteInFileInZip(_zip, readBuff.get(), static_cast<uint32_t>(readSize)) == ZIP_OK;
    } while (readSize == 8192 * 4 && err);

    std::fclose(rf);

    // close internal file.
    err = zipCloseFileInZip(_zip) == ZIP_OK && err;

    // Reopen it for find duplicate file.
    zipClose(_zip, nullptr);
    _zip = zipOpen(_fOpenFilePath.c_str(), APPEND_STATUS_ADDINZIP);
    if (!_zip) {
        return OnError(ErrorCode::ReopenError, "Can't reopen zip file - " + TryG2U(_fOpenFilePath));
    }

    return OnProcess(baseName, 1, 1);
}

/****************WZipFile end****************/