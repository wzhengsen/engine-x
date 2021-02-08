#include "Zip/ZipFile.h"

#include <utility>

using namespace StarryX;
using namespace cocos2d;

bool StarryX::ZipFile::ZipItem::Read(void* buff, size_t len, const std::string& password) {
	return Read(buff, len, password.c_str());
}
bool StarryX::ZipFile::ZipItem::Read(void* buff, size_t len, const char* password) {
	if (!unzf) {
		return false;
	}
	unz_file_pos oldFilePos = {};
	const auto hasOldPos = unzGetFilePos(unzf, &oldFilePos) == UNZ_OK;

	const auto ret = unzGoToFilePos(unzf, &info.pos) == UNZ_OK
		&& unzOpenCurrentFile3(unzf, nullptr, nullptr, 0, password) == UNZ_OK
		&& unzReadCurrentFile(unzf, buff, static_cast<uint32_t>(len)) >= 0
		&& unzCloseCurrentFile(unzf) == UNZ_OK;

	if (hasOldPos) {
		unzGoToFilePos(unzf, &oldFilePos);
	}

	return ret;
}

const StarryX::ZipFile::ZipInfo& StarryX::ZipFile::ZipItem::GetInfo() const noexcept {
	return info;
}

StarryX::ZipFile::ZipFile(const std::string& filePath, ZipMode mode) :
    mode(mode) {
    fopenFilePath = utils::UTF8ToGB2312(FileUtils::getInstance()->fullPathForFilename(filePath));
    if (mode == ZipMode::W) {
        // 检查文件是否存在。
        FILE* file = ::fopen(fopenFilePath.c_str(), "rb");
        if (file) {
            ::fclose(file);
        }
        zipf = zipOpen(fopenFilePath.c_str(), file ? APPEND_STATUS_ADDINZIP : APPEND_STATUS_CREATE);
    }
    if (mode == ZipMode::R) {
        unzf = unzOpen(fopenFilePath.c_str());
    }
}

StarryX::ZipFile::~ZipFile() {
	Close();
}

bool StarryX::ZipFile::Availed() const noexcept{
    return zipf || unzf;
}

void StarryX::ZipFile::Close() {
	if (unzf) {
		unzClose(unzf);
		unzf = nullptr;
	}
    if (zipf) {
        zipClose(zipf, nullptr);
        zipf = nullptr;
    }
	mapZipItem.clear();
}

const StarryX::ZipFile::ZipItem* StarryX::ZipFile::Current() {
	if (!unzf) {
		curZipItem = nullptr;
		return nullptr;
	}

	unz_file_pos filePos = { 0,0 };
	if (unzGetFilePos(unzf, &filePos) != UNZ_OK) {
		// 不合法文件。
		curZipItem = nullptr;
		return nullptr;
	}

	// 查询是否有缓存的Item数据
	auto isNew = false;
	curZipItem = &GetZipItem(filePos.pos_in_zip_directory, isNew);
	if (isNew) {
		unz_file_info fileInfo = {};
		char fileName[ZipFile::ZipInfo::MaxFileNameInZip] = {};

		// 新增Item，设置item参数。
		if (unzGetCurrentFileInfo(unzf, &fileInfo, fileName, sizeof(fileName), nullptr, 0, nullptr, 0) == UNZ_OK) {
			curZipItem->unzf = unzf;
			auto& info = curZipItem->info;
			info.name = utils::GB2312ToUTF8(fileName, ::strlen(fileName));
			info.encrypt = fileInfo.flag;
            info.date = utils::DosDate2Time(fileInfo.dos_date);
			info.size = fileInfo.uncompressed_size;
			info.pos.pos_in_zip_directory = filePos.pos_in_zip_directory;
			info.pos.num_of_file = filePos.num_of_file;
		}
	}
	return curZipItem;
}

const std::unordered_map<uint32_t, StarryX::ZipFile::ZipItem>& StarryX::ZipFile::GetInternalZipItems() const noexcept {
	return mapZipItem;
}

const StarryX::ZipFile::ZipItem* StarryX::ZipFile::First() {
	if (!unzf || unzGoToFirstFile(unzf) != UNZ_OK) {
		// 无效的首文件。
		curZipItem = nullptr;
		return nullptr;
	}

	return Current();
}


const StarryX::ZipFile::ZipItem* StarryX::ZipFile::Next() {
	if (!unzf
		|| !curZipItem
		|| unzGoToNextFile(unzf) != UNZ_OK) {
		// 无效的下一个文件。
		curZipItem = nullptr;
		return nullptr;
	}

	return Current();
}

const StarryX::ZipFile::ZipItem* StarryX::ZipFile::Seek(const char* fileName) {
    if (!unzf) {
        return nullptr;
    }
    std::string fileNameFix = utils::UTF8ToGB2312(fileName, ::strlen(fileName));
    if(unzLocateFile(unzf, fileNameFix.c_str(), nullptr) != UNZ_OK) {
		// 未查找到文件。
		curZipItem = nullptr;
		return nullptr;
	}

	return Current();
}

const StarryX::ZipFile::ZipItem* StarryX::ZipFile::Seek(const std::string& fileName) {
	return Seek(fileName.c_str());
}


StarryX::ZipFile::ZipItem& StarryX::ZipFile::GetZipItem(uint32_t pos, bool& isNew)
{
	if (mapZipItem.find(pos) != mapZipItem.cend()) {
		isNew = false;
		return mapZipItem.at(pos);
	}
	isNew = true;
	mapZipItem.emplace(pos, std::move(ZipItem{}));
	auto& item = mapZipItem.at(pos);
	return item;
}

static std::string basename(const std::string& path) {
    size_t found = path.find_last_of("/\\");

    if (std::string::npos != found) {
        return path.substr(0, found);
    }
    else {
        return path;
    }
}

bool StarryX::ZipFile::Uncompress(const char* path, const char* password, std::string* errorStr) {
    if (!unzf) {
        return false;
    }

    // Get info about the zip file
    unz_global_info globalInfo = {};
    if (unzGetGlobalInfo(unzf, &globalInfo) != UNZ_OK
        || unzGoToFirstFile(unzf) != UNZ_OK) {
        return false;
    }

    const FileUtils* const fileUtils = FileUtils::getInstance();

    std::string pathStr = path;
    if (pathStr.find_last_of("/\\") == std::string::npos) {
        pathStr += "/";
    }

    if (!fileUtils->createDirectory(pathStr)) {
        // Failed to create directory
        return false;
    }

    // Buffer to hold data read from the zip file
    std::unique_ptr<char[]>readBuffer(new char[8192 *4]);
    // Loop to extract all files.
    for (uint32_t i = 0; i < globalInfo.number_entry; ++i)
    {
        // Get info about current file.
        unz_file_info fileInfo = {};
        char fileName[ZipInfo::MaxFileNameInZip] = {};
        if (unzGetCurrentFileInfo(unzf,
            &fileInfo,
            fileName,
            sizeof(fileName),
            nullptr,
            0,
            nullptr,
            0) != UNZ_OK) {
            return false;
        }

        // 获取多字节编码的路径。
        const std::string mbPath = utils::UTF8ToGB2312(pathStr);
        const std::string fullPath = mbPath + fileName;

        // 获取UTF8编码的路径。
        std::string utf8FileName = utils::GB2312ToUTF8(fileName, ::strlen(fileName));
        const std::string utf8FullPath = pathStr + utf8FileName;

        // Check if this entry is a directory or a file.
        const size_t filenameLength = ::strlen(fileName);
        if (fileName[filenameLength - 1] == '/') {
            //There are not directory entry in some case.
            //So we need to create directory when decompressing file entry
            if (!fileUtils->createDirectory(utf8FullPath)) {
                // Failed to create directory
                if (errorStr) {
                    *errorStr = utf8FileName;
                }
                return false;
            }
        }
        else {
            // Create all directories in advance to avoid issue
            std::string dir = basename(utf8FullPath);
            if (!fileUtils->createDirectory(dir)) {
                // Failed to create directory
                if (errorStr) {
                    *errorStr = utf8FileName;
                }
                return false;
            }

            // Entry is a file, so extract it.
            // Open current file.
            if (unzOpenCurrentFile3(unzf, nullptr, nullptr, 0, password) != UNZ_OK) {
                if (errorStr) {
                    *errorStr = utf8FileName;
                }
                return false;
            }

            // Create a file to store current file.
            FILE* out = ::fopen(fullPath.c_str(), "wb");
            if (!out) {
                unzCloseCurrentFile(unzf);
                if (errorStr) {
                    *errorStr = utf8FileName;
                }
                return false;
            }

            // Write current file content to destinate file.
            int error = UNZ_OK;
            do {
                error = unzReadCurrentFile(unzf, readBuffer.get(), 8192 * 4);
                if (error < 0) {
                    ::fclose(out);
                    unzCloseCurrentFile(unzf);
                    if (errorStr) {
                        *errorStr = utf8FileName;
                    }
                    return false;
                }

                if (error > 0) {
                    ::fwrite(readBuffer.get(), error, 1, out);
                }
            } while (error > 0);

            ::fclose(out);
        }

        unzCloseCurrentFile(unzf);

        // Goto next entry listed in the zip file.
        if ((i + 1) < globalInfo.number_entry) {
            if (unzGoToNextFile(unzf) != UNZ_OK) {
                if (errorStr) {
                    *errorStr = utf8FileName;
                }
                return false;
            }
        }
    }

    return true;
}

void StarryX::ZipFile::UncompressAsync(const char* path, const char* password, const std::function<void(AsyncData&)>& callBack) {

    auto* const asyncData = new AsyncData();

    std::string passwordStr = password ? password : "";
    std::string _path = path;
    AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_OTHER,
        [callBack](void* param) {
            auto* const asyncData = static_cast<AsyncData*>(param);

            if (asyncData) {
                callBack(*asyncData);
                delete asyncData;
            }
        },
        asyncData,
        [this, asyncData, passwordStr, _path, password]() {
            asyncData->suc = this->Uncompress(_path.c_str(), password ? passwordStr.c_str() : password, &asyncData->error);
        });
}

void StarryX::ZipFile::UncompressAsync(const char* path, const std::function<void(AsyncData&)>& callBack) {
    UncompressAsync(path, nullptr, callBack);
}

bool StarryX::ZipFile::Compress(const std::string& fileNameInZip, const std::string& fileName, const char* password, int level) {
    if (!zipf) {
        return false;
    }
    const FileUtils* fileUtils = FileUtils::getInstance();
    std::string fullName = fileUtils->fullPathForFilename(fileName);
    if (fullName.empty()) {
        return false;
    }

    std::string nameInZip = utils::UTF8ToGB2312(fileNameInZip.c_str(), fileNameInZip.length());
    fullName = utils::UTF8ToGB2312(fullName);

    // 查找重复。
    unzFile f = unzOpen(fopenFilePath.c_str());
    if (f && unzLocateFile(f, nameInZip.c_str(), nullptr) == UNZ_OK) {
        // 查找到文件。
        unzClose(f);
        return true;
    }
    if (f) {
        unzClose(f);
    }

    const bool ret = PushItem(nameInZip, fullName, password, level);
    // 重新打开一次，以便下次查找重复。
    zipClose(zipf, nullptr);
    zipf = zipOpen(fopenFilePath.c_str(), APPEND_STATUS_ADDINZIP);
    return ret;
}

void StarryX::ZipFile::CompressAsync(const std::string& fileNameInZip, const std::string& fileName, const char* password, const std::function<void(AsyncData&)>& callBack) {
    auto* const asyncData = new AsyncData();

    std::string passwordStr = password ? password : "";
    AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_OTHER,
        [callBack](void* param) {
            auto* const asyncData = static_cast<AsyncData*>(param);

            if (asyncData) {
                callBack(*asyncData);
                delete asyncData;
            }
        },
        asyncData,
            [this, asyncData, passwordStr, password, fileNameInZip, fileName]() {
            asyncData->suc = this->Compress(fileNameInZip, fileName,password ? passwordStr.c_str() : password, Z_DEFAULT_COMPRESSION);
            if (!asyncData->suc) {
                asyncData->error = fileName;
            }
        });
}

void StarryX::ZipFile::CompressAsync(const std::string& fileNameInZip, const std::string& fileName, const std::function<void(AsyncData&)>& callBack) {
    CompressAsync(fileNameInZip, fileName, nullptr, callBack);
}

void StarryX::ZipFile::CompressAsync(const std::vector<std::string>& fileNameInZipVec, const std::vector<std::string>& fileNameVec, const char* password, const std::function<void(AsyncData&)>& callBack) {
    auto* const asyncData = new AsyncData();

    std::string passwordStr = password ? password : "";
    AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_OTHER,
        [callBack](void* param) {
            auto* const asyncData = static_cast<AsyncData*>(param);

            if (asyncData) {
                callBack(*asyncData);
                delete asyncData;
            }
        },
        asyncData,
            [this, asyncData, passwordStr, password, fileNameInZipVec, fileNameVec]() {
            asyncData->suc = this->Compress(fileNameInZipVec, fileNameVec, password ? passwordStr.c_str() : password, Z_DEFAULT_COMPRESSION, &asyncData->error);
        });
}

void StarryX::ZipFile::CompressAsync(const std::vector<std::string>& fileNameInZipVec, const std::vector<std::string>& fileNameVec, const std::function<void(AsyncData&)>& callBack) {
    CompressAsync(fileNameInZipVec, fileNameVec, nullptr, callBack);
}

void StarryX::ZipFile::CompressAsync(const std::string& dirName, const std::function<void(AsyncData&)>& callBack) {
    auto* const asyncData = new AsyncData();

    AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_OTHER,
        [callBack](void* param) {
            auto* const asyncData = static_cast<AsyncData*>(param);

            if (asyncData) {
                callBack(*asyncData);
                delete asyncData;
            }
        },
        asyncData,
            [this, asyncData, dirName]() {
            asyncData->suc = this->Compress(dirName);
            if (!asyncData->suc) {
                asyncData->error = dirName;
            }
        });
}

void StarryX::ZipFile::CompressAsync(const std::vector<std::string>& dirVec, const std::function<void(AsyncData&)>& callBack) {
    auto* const asyncData = new AsyncData();

    AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_OTHER,
        [callBack](void* param) {
            auto* const asyncData = static_cast<AsyncData*>(param);

            if (asyncData) {
                callBack(*asyncData);
                delete asyncData;
            }
        },
        asyncData,
            [this, asyncData, dirVec]() {
            asyncData->suc = this->Compress(dirVec, &asyncData->error);
        });
}

bool StarryX::ZipFile::Compress(std::vector<std::string> fileNameInZipVec, std::vector<std::string> fileNameVec, const char* password, int level, std::string* errorStr) {
    if (!zipf || fileNameInZipVec.size() != fileNameVec.size()) {
        return false;
    }

    // 验证是否有无效文件。
    const FileUtils* fileUtils = FileUtils::getInstance();
    for (auto& fileName : fileNameVec) {
        fileName = fileUtils->fullPathForFilename(fileName);
        if (fileName.empty()) {
            return false;
        }
    }

    unzFile f = unzOpen(fopenFilePath.c_str());

    bool ret = true;
    for (size_t idx = 0; idx < fileNameInZipVec.size(); idx++) {
        std::string& nameInZip = fileNameInZipVec[idx];
        nameInZip = utils::UTF8ToGB2312(nameInZip);

        // 查找重复。
        if (f && unzLocateFile(f, nameInZip.c_str(), nullptr) == UNZ_OK) {
            // 查找到文件。
            continue;
        }

        std::string& fullName = fileNameVec[idx];
        fullName = utils::UTF8ToGB2312(fullName);

        ret = PushItem(nameInZip, fullName, password, level);
        if (!ret) {
            if (errorStr) {
                fullName = utils::GB2312ToUTF8(fullName);
                *errorStr = fullName;
            }
            break;
        }
    }

    // 重新打开一次，以便下次查找重复。
    zipClose(zipf, nullptr);
    zipf = zipOpen(fopenFilePath.c_str(), APPEND_STATUS_ADDINZIP);
    if (f) {
        unzClose(f);
    }

    return ret;
}

bool StarryX::ZipFile::Compress(const std::string& dirName) {
    if (!zipf || dirName.empty()) {
        return false;
    }
    // 尾字符确保为'/'
    std::string dir = dirName;
    const char tailChar = dir[dir.length() - 1];
    if (tailChar != '/') {
        dir += "/";
    }

    dir = utils::UTF8ToGB2312(dir);

    // 查找重复。
    unzFile f = unzOpen(fopenFilePath.c_str());
    if (f && unzLocateFile(f, dir.c_str(), nullptr) == UNZ_OK) {
        // 查找到文件。
        unzClose(f);
        return true;
    }
    if (f) {
        unzClose(f);
    }

    const bool ret = PushItem(dir);
    // 重新打开一次，以便下次查找重复。
    zipClose(zipf, nullptr);
    zipf = zipOpen(fopenFilePath.c_str(), APPEND_STATUS_ADDINZIP);
    return ret;
}

bool StarryX::ZipFile::Compress(std::vector<std::string> dirVec, std::string* errorStr) {
    if (!zipf) {
        return false;
    }
    unzFile f = unzOpen(fopenFilePath.c_str());

    for (auto dir = dirVec.begin(); dir != dirVec.end();) {
        if (dir->empty()) {
            dir = dirVec.erase(dir);
            continue;
        }
        // 尾字符确保为'/'
        if (dir->at(dir->length() - 1) != '/') {
            *dir += "/";
        }

        *dir = utils::UTF8ToGB2312(*dir);

        // 查找重复。
        if (f && unzLocateFile(f, dir->c_str(), nullptr) == UNZ_OK) {
            // 查找到文件。
            dir = dirVec.erase(dir);
            continue;
        }
        dir++;
    }
    if (f) {
        unzClose(f);
    }

    bool ret = true;
    for (auto& dir : dirVec) {
        ret = PushItem(dir);
        if (!ret) {
            if (errorStr) {
                dir = utils::GB2312ToUTF8(dir);
                *errorStr = dir;
            }
            break;
        }
    }
    // 重新打开一次，以便下次查找重复。
    zipClose(zipf, nullptr);
    zipf = zipOpen(fopenFilePath.c_str(), APPEND_STATUS_ADDINZIP);
    return ret;
}

bool StarryX::ZipFile::PushItem(const std::string& fileNameInZip, const std::string& fileName, const char* password, int level) {

    FILE* file = ::fopen(fileName.c_str(), "rb");
    if (!file) {
        return false;
    }

    // Crc32
    const uLong crc = MakeItemCrc32(file);
    zip_fileinfo zi = {
        MakeItemDosDate(fileName.c_str()),
        0,0
    };

    // open internal file.
    bool err = zipOpenNewFileInZip4_64(zipf, fileNameInZip.c_str(), &zi,
        nullptr, 0,
        nullptr, 0,
        nullptr,
        Z_DEFLATED,
        level,
        0,
        -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY,
        password, crc,
        0, 0, 0) == ZIP_OK;
    if (!err) {
        return false;
    }

    std::unique_ptr<char[]>readBuff(new char[8192 * 4]);
    size_t readSize = 0;
    do {
        readSize = ::fread(readBuff.get(), sizeof(char), 8192 * 4, file);
        err = zipWriteInFileInZip(zipf, readBuff.get(), static_cast<uint32_t>(readSize)) == ZIP_OK;
    } while (readSize == 8192 * 4 && err);

    ::fclose(file);
    // close internal file.
    err = zipCloseFileInZip(zipf) == ZIP_OK && err;
    return err;
}

bool StarryX::ZipFile::PushItem(const std::string& dirName) {
    // 取当前时间。

    zip_fileinfo zi = {};
    zi.dos_date = utils::Time2DosDate();

    // open internal file.
    const bool ret = zipOpenNewFileInZip4_64(zipf, dirName.c_str(), &zi,
        nullptr, 0,
        nullptr, 0,
        nullptr,
        Z_DEFLATED,
        Z_DEFAULT_COMPRESSION,
        0,
        -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY,
        nullptr, 0,
        0, 0, 0) == ZIP_OK
        && zipCloseFileInZip(zipf) == ZIP_OK;
    return ret != 0;
}

uint32_t StarryX::ZipFile::MakeItemDosDate(const char* path) noexcept {
    uint32_t dos_date = 0;
#ifdef _WIN32
    FILETIME ftm_local = {};
    HANDLE find = nullptr;
    WIN32_FIND_DATAA ff32 = {};

    find = FindFirstFileA(path, &ff32);
    if (find != INVALID_HANDLE_VALUE)
    {
        FileTimeToLocalFileTime(&(ff32.ftLastWriteTime), &ftm_local);
        FileTimeToDosDateTime(&ftm_local, ((LPWORD)&dos_date) + 1, ((LPWORD)&dos_date) + 0);
        FindClose(find);
    }
#else
    struct stat s{};
    time_t tm_t = 0;

    memset(&s, 0, sizeof(s));

    if (strcmp(path, "-") != 0)
    {
        size_t len = strlen(path);
        char* name = (char*)malloc(len + 1);
        strncpy(name, path, len + 1);
        name[len] = 0;
        if (name[len - 1] == '/')
            name[len - 1] = 0;

        /* Not all systems allow stat'ing a file with / appended */
        if (stat(name, &s) == 0)
        {
            tm_t = s.st_mtime;
        }
        free(name);
    }

    dos_date = utils::Time2DosDate(tm_t);
#endif
    return dos_date;
}

uLong StarryX::ZipFile::MakeItemCrc32(FILE* inf) {
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