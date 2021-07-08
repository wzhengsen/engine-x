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
    /****************Zip begin****************/
    /**
     * @brief The base of RZip and WZip.
    */
#if CC_ENABLE_LUA_BINDING
    class CC_DLL Zip : public cocos2d::extension::LuaObject {
#else
    class CC_DLL Zip {
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
         * @param path The internal path in Zip.
         * @param idx Current index.
         * @param count The count of items.
        */
        typedef std::function<void(Zip* sender, const std::string& path, uint32_t idx, uint32_t count)> ProcessHandler;

        /**
         * @param sender It is self.
         * @param code Error type.
         * @param reason Why failed?
        */
        typedef std::function<void(Zip* sender, ErrorCode code, const std::string& reason)> ErrorHandler;

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
         * @param       password? The password of Zip.Specifically, the empty string is also a password.
        */
        virtual void Work(const std::string& path, const char* password = nullptr) = 0;

        /**
         * @brief       Start asynchronous work.
         * @param       path The work path.
         * @param       password? The password of Zip.Specifically, the empty string is also a password.
        */
        void WorkAsync(const std::string& path, const char* password = nullptr);
    protected:
        Zip(const std::string& filePath);
        Zip(const Zip&) = delete;

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
    /****************Zip end****************/

    /****************RZip begin****************/
    /**
     * @brief This class provides the ability to read zip files.
    */
    class CC_DLL RZip : public cocos2d::Zip {
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
            friend class RZip;
        };

        /**
         * @brief This class indicates each item in Zip, including files and directories.
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
            ZipItem(RZip* rZip, const ZipInfo& info) noexcept :_rZip(rZip), _info(info) {};
        private:
            ZipInfo _info = {};
            RZip* _rZip = nullptr;
            friend class RZip;
            friend class ZipItemIterator;
        };

        /**
         * @brief Used to access the elements in a Zip.
        */
        class CC_DLL ZipItemIterator {
        public:
            // For warning STL4015.
            typedef std::forward_iterator_tag iterator_category;
            typedef RZip::ZipItem value_type;
            typedef ptrdiff_t difference_type;
            typedef RZip::ZipItem* pointer;
            typedef RZip::ZipItem& reference;

            ZipItemIterator(const RZip::ZipItem* item) :_item(item) {}

            ZipItemIterator& operator=(const ZipItemIterator& iter);
            bool operator!=(const ZipItemIterator& iter) const;
            bool operator==(const ZipItemIterator& iter) const;
            ZipItemIterator& operator++();
            ZipItemIterator operator++(int);
            const RZip::ZipItem& operator*() const;
        private:
            const RZip::ZipItem* _item = nullptr;
        };

        enum class Encoding {
            Auto,
            Utf8,
            Gbk
        };

        /**
         * @brief       Create a RZip instance,if filePath isn't valid,returns nullptr.
         * @param       filePath The path of the zip file you want to read.
         * @param       code Possible encoding methods for zip file internal filenames.
         * @return      RZip instance or nullptr.
        */
        static RZip* Create(const std::string& filePath,Encoding code = Encoding::Auto);
        virtual ~RZip();

        /**
         * @brief       Locate a Item.
         * @param       fileName The file name you want to locate.
         * @return      When not found, nullptr is returned.
        */
        const ZipItem* Locate(const std::string& fileName);

        /**
        * @brief        Get all item which match the pattern.
        * @param        fileName The file name you want to get,can be a regex pattern.
        * @return       vector,but returns an empty vector when not found.
        */
        std::vector<const ZipItem*> Match(const std::string& fileName);

        void Work(const std::string& path, const char* password = nullptr) override;

        /**
         * @brief       Use for iterator.
        */
        ZipItemIterator begin();
        const static ZipItemIterator& end();
    protected:
        using Zip::Zip;
        RZip(const std::string& filePath,Encoding code = Encoding::Auto) :Zip(filePath), _code(code) {};

        const ZipItem* _curZipItem = nullptr;
        uint32_t _itemCount = 0;

        Encoding _code = Encoding::Auto;

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
    /****************RZip end****************/

    /****************WZip begin****************/
    /**
     * @brief This class provides the ability to write zip files.
    */
    class CC_DLL WZip : public cocos2d::Zip {
    public:
        /**
         * @brief       Create a WZip instance,if filePath isn't valid,returns nullptr.
         * @param       filePath The path of the zip file you want to write to.
         * @return      WZip instance or nullptr.
        */
        static WZip* Create(const std::string& filePath);
        virtual ~WZip();

        void Work(const std::string& path, const char* password = nullptr) override;
    protected:
        using Zip::Zip;

        bool Open() override;
        void Close() override;

        void PushDir(const std::string& dir, const char* password = nullptr);
        void PushFile(const std::string& file, const char* password = nullptr);
        bool CloseUnzipAndReopenZip(unzFile unz);

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
        static constexpr uint16_t MadeBy = 0x1014;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
        static constexpr uint16_t MadeBy = 0x1914;
#else
        static constexpr uint16_t MadeBy = 0x0314;
#endif
    };
    /****************WZip end****************/
}