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
#pragma once
#ifdef MINIZIP_FROM_SYSTEM
#include <minizip/zip.h>
#include <minizip/unzip.h>
#else // from our embedded sources
#include "minizip/zip.h"
#include "minizip/unzip.h"
#endif
#include "zlib.h"
#include "cocos2d.h"

 // from unzip.cpp
#define UNZ_MAXFILENAMEINZIP 256

namespace cocos2d {
    /****************ZipFile begin****************/
    /**
     * @brief The base of RZipFile and WZipFile.
    */
#if CC_ENABLE_LUA_BINDING
    class CC_DLL ZipFile : public cocos2d::extension::LuaObject {
#else
    class CC_DLL ZipFile {
#endif
    public:

        enum class ErrorCode {
            Unknown,
            ZipError,
            PathEmptyError,

            // Read error.
            CreateDirError,
            CreateFileError,
            GlobalInfoError,
            ItemInfoError,
            OpenItemError,
            PasswordError,
            ReadItemError,
            WriteFileError,

            // Write error.
            DirNotExistError,
            FileNotExistError,
            DuplicateFileError,
            ReadFileError,
            InternalFileError,
            ReopenError,
            OpenZipError
        };

        /**
         * @param sender It is self.
         * @param path The internal path in ZipFile.
         * @param idx Current index.
         * @param count The count of items.
        */
        typedef std::function<void(ZipFile* sender, const std::string& path, uint32_t idx, uint32_t count)> ProcessHandler;

        /**
         * @param sender It is self.
         * @param code Error type.
         * @param reason Why failed?
        */
        typedef std::function<void(ZipFile* sender, ErrorCode code, const std::string& reason)> ErrorHandler;

        /**
         * @brief       Set the handler function that indicates the process.
        */
        void SetProcessHandler(const ProcessHandler& handler);

        /**
         * @brief       Set the handler function that for failure.
        */
        void SetErrorHandler(const ErrorHandler& handler);

        /**
         * @brief       Start working immediately.
         * @param       path The work path.
         * @param       password? The password of ZipFile.Specifically, the empty string is also a password.
        */
        virtual void Work(const std::string& path, const char* password = nullptr) = 0;

        /**
         * @brief       Start asynchronous work.
         * @param       path The work path.
         * @param       password? The password of ZipFile.Specifically, the empty string is also a password.
        */
        void WorkAsync(const std::string& path, const char* password = nullptr);
    protected:
        ZipFile(const std::string& filePath);
        ZipFile(const ZipFile&) = delete;
        ZipFile& operator=(const ZipFile&) = delete;

        ProcessHandler _processHandler = nullptr;
        ErrorHandler _errorHandler = nullptr;
        bool _inAsync = false;

        bool IsValid() const noexcept;
        virtual bool Open() = 0;
        virtual void Close() = 0;

        void OnError(ErrorCode code, const std::string& reason);
        void OnProcess(const std::string& path, uint32_t idx, uint32_t count);

        std::string _fOpenFilePath = {};
        void* _zip = nullptr;

        static uint32_t MakeItemDosDate(const char* path) noexcept;
        static uLong MakeItemCrc32(FILE* inf);
    };
    /****************ZipFile end****************/

    /****************RZipFile begin****************/
    /**
     * @brief This class provides the ability to read zip files.
    */
    class CC_DLL RZipFile : public cocos2d::ZipFile {
    public:
        class ZipItemIterator;
        struct ZipInfo {
        public:
            static constexpr uint32_t MaxFileNameInZip = UNZ_MAXFILENAMEINZIP + 1;
            std::string name = {};
            int64_t date = 0;
            size_t size = 0;
            bool encrypt = false;
        private:
            unz_file_pos pos = { 0,0 };
            ZipInfo() = default;
            ZipInfo(const std::string& name, int64_t date, size_t size, bool encrypt, const unz_file_pos& pos)
                :name(name), date(date), size(size), encrypt(encrypt), pos(pos) {}
            friend class RZipFile;
        };

        /**
         * @brief This class indicates each item in ZipFile, including files and directories.
        */
#if CC_ENABLE_LUA_BINDING
        class ZipItem : public cocos2d::extension::LuaObject {
#else
        class ZipItem {
#endif
        public:
            /**
             * @brief   Retrieve the contents or subitems of the item.
             *          1.If the item is a file, writes the contents of the file to the buffer.
             *          It is also possible to provide a password to read the contents,
             *          specifically, the empty string is also a password.
             *          2.If the item is a directory, writes the subitems of the directory to vecItem.
            */
            /**
             * @param   buff     The buffer of contents.
             * @param   len      You can get length of contents by GetInfo().
             * @param   password default = nullptr
             * @return  Return true on success and false on failure.
            */
            bool Read(void* buff, size_t len, const char* password = nullptr) const;

            /**
             * @param   vecItem All direct children of the current item.
             * @return  Return true on success and false on failure.
            */
            bool Read(std::vector<const ZipItem*>& vecItem) const;
            const ZipInfo& GetInfo() const noexcept;
        private:
            ZipItem(RZipFile* rZip, const ZipInfo& info) noexcept :_rZip(rZip), _info(info) {};
            ZipInfo _info = {};
            RZipFile* _rZip = nullptr;
            friend class RZipFile;
            friend class ZipItemIterator;
        };

        /**
         * @brief Used to access the elements in a ZipFile.
        */
        class CC_DLL ZipItemIterator {
        public:
            // For warning STL4015.
            typedef std::forward_iterator_tag iterator_category;
            typedef RZipFile::ZipItem value_type;
            typedef ptrdiff_t difference_type;
            typedef RZipFile::ZipItem* pointer;
            typedef RZipFile::ZipItem& reference;

            ZipItemIterator(const RZipFile::ZipItem* item) :_item(item) {}

            ZipItemIterator& operator=(const ZipItemIterator& iter);
            bool operator!=(const ZipItemIterator& iter) const;
            bool operator==(const ZipItemIterator& iter) const;
            ZipItemIterator& operator++();
            ZipItemIterator operator++(int);
            const RZipFile::ZipItem& operator*() const;
        private:
            const RZipFile::ZipItem* _item = nullptr;
        };

        /**
         * @brief       Create a RZipFile instance,if filePath isn't valid,returns nullptr.
         * @param       filePath The path of the zip file you want to read.
         * @return      RZipFile instance or nullptr.
        */
        static RZipFile* Create(const std::string& filePath);
        virtual ~RZipFile();

        /**
         * @brief       Seek a Item.
         * @return      When not found, nullptr is returned.
        */
        const ZipItem* Seek(const std::string& fileName);

        void Work(const std::string& path, const char* password = nullptr) override;

        ZipItemIterator begin();
        const static ZipItemIterator& end();
        uint32_t size() const noexcept;
    protected:
        using ZipFile::ZipFile;

        const ZipItem* _curZipItem = nullptr;
        uint32_t _itemCount = 0;

        /**
         * @brief Returns true if the item should be created.
         * @param pos The offest in zip file.
        */
        bool CheckZipItem(uint32_t pos) const noexcept;

        std::unordered_map<uint32_t, ZipItem> _mapZipItem = {};

        /**
         * @brief       Return current ZipItem.
         * @return      Returns nullptr when no current file.
        */
        const ZipItem* Current();

        /**
         * @brief       Return next ZipItem.
         * @return      Returns nullptr when no next file.
        */
        const ZipItem* Next();

        /**
         * @brief       Return first ZipItem.
         * @return      Returns nullptr when no first file.
        */
        const ZipItem* First();

        /**
         * @brief       Go to a item.
         * @param       item The item you want to go.
        */
        void GoTo(const ZipItem* item);

        bool Open() override;
        void Close() override;

        friend class ZipItem;
        friend class ZipItemIterator;
    };
    /****************RZipFile end****************/

    /****************WZipFile begin****************/
    /**
     * @brief This class provides the ability to write zip files.
    */
    class CC_DLL WZipFile : public cocos2d::ZipFile {
    public:
        /**
         * @brief       Create a WZipFile instance,if filePath isn't valid,returns nullptr.
         * @param       filePath The path of the zip file you want to write to.
         * @return      WZipFile instance or nullptr.
        */
        static WZipFile* Create(const std::string& filePath);
        virtual ~WZipFile();

        void Work(const std::string& path, const char* password = nullptr) override;
    protected:
        using ZipFile::ZipFile;

        bool Open() override;
        void Close();

        void PushDir(const std::string& dir, const char* password = nullptr);
        void PushFile(const std::string& file, const char* password = nullptr);
    };
    /****************WZipFile end****************/
}