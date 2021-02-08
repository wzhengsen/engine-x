#pragma once
#ifdef MINIZIP_FROM_SYSTEM
#include <minizip/unzip.h>
#include <minizip/zip.h>
#else // from our embedded sources
#include "minizip/unzip.h"
#include "minizip/zip.h"
#endif

#include "zlib.h"
#include <string>
#include "cocos2d.h"

// from unzip.cpp
#define UNZ_MAXFILENAMEINZIP 256

namespace StarryX {

	class ZipFile {
	public:
		struct ZipItem;
		struct ZipInfo {
			static constexpr uint32_t MaxFileNameInZip = UNZ_MAXFILENAMEINZIP + 1;
			std::string name = std::string();
			int64_t date = 0;
			size_t size = 0;
			unz_file_pos pos = { 0,0 };
			bool encrypt = false;
		private:
			ZipInfo() noexcept {};
			friend struct ZipItem;
		};

		struct ZipItem {
		public:
			bool Read(void* buff, size_t len, const std::string& password);
			bool Read(void* buff, size_t len, const char* password = nullptr);
			const ZipInfo& GetInfo() const noexcept;
		private:
			ZipItem() noexcept {};
			ZipInfo info = {};
			unzFile unzf = nullptr;
			friend class ZipFile;
		};

        // 异步操作数据类。
        struct AsyncData {
            // 失败信息。
            std::string error = std::string();
            bool suc = false;
        };

		// ZipFile操作模式，可读，可写。
		enum class ZipMode {
			R ,
			W
		};

		ZipFile(const std::string& filePath,ZipMode mode = ZipMode::R);
        ZipFile(const ZipFile&) = delete;
        ZipFile(ZipFile&& zf) = delete;
        ZipFile& operator=(const ZipFile&) = delete;
        ZipFile& operator=(ZipFile&&) = delete;


		virtual ~ZipFile();

        // 判断当前Zip文件是可用的。
        bool Availed() const noexcept;

		// 返回下一个内部文件/目录。
		// 当查找到最后一个文件时的下一个时，会返回nullptr。
		const ZipItem* Next();

		// 返回第一个内部文件/目录。
		const ZipItem* First();

		// 查找内部文件/目录。
		const ZipItem* Seek(const char* fileName);
		const ZipItem* Seek(const std::string& fileName);

        // 将当前Zip文件解压缩至指定目录。
        bool Uncompress(const char* path, const char* password = nullptr, std::string* errorStr = nullptr);

        // 异步解压缩Zip文件。
        void UncompressAsync(const char* path, const char* password, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});
        void UncompressAsync(const char* path, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});


		// 创建一个新的Zip内部项目，该项目可以是目录或文件。
		/*
			fileNameInZip   创建压缩文件的名字。
            fileName        被写入压缩文件的文件名字。
            password        若不为nullptr，则使用该密码。
            level           压缩率，使用0-9，默认使用Z_DEFAULT_COMPRESSION宏。
		*/
		bool Compress(const std::string& fileNameInZip, const std::string& fileName, const char* password = nullptr, int level = Z_DEFAULT_COMPRESSION);
        bool Compress(std::vector<std::string> fileNameInZipVec, std::vector<std::string> fileNameVec, const char* password = nullptr, int level = Z_DEFAULT_COMPRESSION, std::string* errorStr = nullptr);
        bool Compress(const std::string& dirName);
        bool Compress(std::vector<std::string> dirVec, std::string* errorStr = nullptr);

        // 异步压缩zip文件。
        void CompressAsync(const std::string& fileNameInZip, const std::string& fileName, const char* password, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});
        void CompressAsync(const std::string& fileNameInZip, const std::string& fileName, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});
        void CompressAsync(const std::vector<std::string>& fileNameInZipVec, const std::vector<std::string>& fileNameVec, const char* password, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});
        void CompressAsync(const std::vector<std::string>& fileNameInZipVec, const std::vector<std::string>& fileNameVec, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});
        void CompressAsync(const std::string& dirName, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});
        void CompressAsync(const std::vector<std::string>& dirVec, const std::function<void(AsyncData&)>& callBack = [](AsyncData&) noexcept {});

		// 返回内部缓存的全部文件。
		const std::unordered_map<uint32_t, ZipItem>& GetInternalZipItems() const noexcept;
	private:
        std::string fopenFilePath = std::string();
		ZipMode mode = ZipMode::R;
		unzFile unzf = nullptr;
        zipFile zipf = nullptr;
		// 当前指示的ZipItem
		ZipItem* curZipItem = nullptr;

		// 按照给定的pos返回一个内部ZipItem
		ZipItem& GetZipItem(uint32_t pos,bool& isNew);

		std::unordered_map<uint32_t, ZipItem> mapZipItem = std::unordered_map<uint32_t, ZipItem>();

		// 返回当前内部文件/目录。
		const ZipItem* Current();

        bool PushItem(const std::string& fileNameInZip, const std::string& fileName, const char* password = nullptr, int level = Z_DEFAULT_COMPRESSION);
        bool PushItem(const std::string& dirName);

        static uint32_t MakeItemDosDate(const char* path) noexcept;
        static uLong MakeItemCrc32(FILE* inf);

		void Close();
	};
}