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
#include "platform/CCPlatformMacros.h"

NS_CC_BEGIN
class Crypto final {
public:
    enum class EncodeMode {
        BASE64,
        HEX,
        URL
    };
    typedef EncodeMode DecodeMode;

    /**
    * @brief    Encodes or decodes data from a section of memory in a specified mode.
    * @param    src         The string you want to codec.
    * @param    mode        The mode of the wanted codec.
    * @note     Perform base64 codec without line feeds.
    */
    inline static std::string Encode(const std::string& src, EncodeMode mode) {
        return Crypto::Codec(src, mode, true);
    }
    inline static std::string Decode(const std::string& src, DecodeMode mode) {
        return Crypto::Codec(src, mode, false);
    }


    enum class HashMode {
        SHA1,
        SHA224,
        SHA256,
        SHA384,
        SHA512,
        MD5
    };

    /**
    * @brief   Gets the hash of the data in a section of memory areas.
    * @param   src         The data source for the memory area.
    * @param   mode        The mode of the desired output hash value.
    * @param   encode      Whether to convert the hash result to hexadecimal encoding,it is true as default.
    * @return  Even if you do not choose to encode it in hexadecimal, it still returns the hash as a string.
    *          And if src is empty,returns empty.
    * @note    Different hash modes and whether or not hex encoding is performed will use different lengths of
    *          output memory area.
    *          For example, for md5 mode, the length is 32 bytes when the output result is encoded in
    *          hexadecimal, and 16 bytes when the output result is not encoded.
    */
    static std::string Hash(const std::string& src, HashMode mode, bool encode = true);
    inline static std::string SHA1(const std::string& src) {
        return Crypto::Hash(src, HashMode::SHA1);
    };
    inline static std::string SHA224(const std::string& src) {
        return Crypto::Hash(src, HashMode::SHA224);
    };
    inline static std::string SHA256(const std::string& src) {
        return Crypto::Hash(src, HashMode::SHA256);
    };
    inline static std::string SHA384(const std::string& src) {
        return Crypto::Hash(src, HashMode::SHA384);
    };
    inline static std::string SHA512(const std::string& src) {
        return Crypto::Hash(src, HashMode::SHA512);
    };
    inline static std::string MD5(const std::string& src) {
        return Crypto::Hash(src, HashMode::MD5);
    };

    static std::string Encrypt(const std::string& src, const std::string& key, const std::string& iv = "");
    static std::string Decrypt(const std::string& src, const std::string& key, const std::string& iv = "");

    /**
    * @brief        Encryption and decryption with CFB128.
    * @param[in]    src         The data source for the memory area.
    * @param        srcLen      The lenght of the memory area.
    * @param[out]   dst         The memory area of the outputing.
    * @param        dstLen      The length of the memory area of the outputing.
    * @param[in]    key         The key.
    * @param        keyLen      The length of key,if less than 16,then fill \0 to 16 bytes,
    *                           if greater than 16, only the first 16 bytes are intercepted.
    * @param[in]    iv          The iv.
    * @param        ivLen       The length of iv,like keyLen parameter.
    */
    static void CFB128(
        const void* src, size_t srcLen,
        void* dst, size_t dstLen,
        const char* key, uint8_t keyLen,
        const char* iv, uint8_t ivLen,
        bool encrypt
    );
private:
    static void EncodeBase64(const void* src, size_t srcLen, void* dst, size_t& dstLen);
    static void DecodeBase64(const void* src, size_t srcLen, void* dst, size_t& dstLen);
    inline static void EncodeHex(const void* src, size_t srcLen, void* dst, size_t& dummy) {
        Crypto::EncodeHex(src, srcLen, dst);
    };
    static void EncodeHex(const void* src, size_t srcLen, void* dst);
    static void DecodeHex(const void* src, size_t srcLen, void* dst, size_t& dstLen);
    static void EncodeUrl(const void* src, size_t srcLen, void* dst, size_t& dstLen);
    static void DecodeUrl(const void* src, size_t srcLen, void* dst, size_t& dstLen);
    static std::string Codec(const std::string& src, EncodeMode mode, bool encode);

    Crypto() = delete;
};
NS_CC_END