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

#include "crypto/CCCrypto.h"
#include "openssl/aes.h"
#include "openssl/md5.h"
#include "openssl/sha.h"
#include "openssl/bio.h"
#include "openssl/buffer.h"
#include "openssl/evp.h"

using namespace cocos2d;

/****************Codec Begin****************/
void Crypto::EncodeBase64(const void* src, size_t srcLen, void* dst, size_t& dstLen) {
    BIO* b64 = BIO_new(BIO_f_base64());
    BUF_MEM* b_ptr = nullptr;

    // Base64 encoding without line feeds.
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    b64 = BIO_push(b64, BIO_new(BIO_s_mem()));
    BIO_write(b64, src, static_cast<int>(srcLen));
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &b_ptr);
    BIO_set_close(b64, BIO_NOCLOSE);

    dstLen = std::min(dstLen, b_ptr->length);
    std::memcpy(dst, b_ptr->data, dstLen);

    BIO_free_all(b64);
}

void Crypto::DecodeBase64(const void* src, size_t srcLen, void* dst, size_t& dstLen) {
    BIO* b64 = BIO_new(BIO_f_base64());

    // Base64 decoding without line feeds.
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    b64 = BIO_push(b64, BIO_new_mem_buf(src, static_cast<int>(srcLen)));

    dstLen = BIO_read(b64, dst, static_cast<int>(dstLen));

    BIO_free_all(b64);
}

void Crypto::EncodeHex(const void* src, size_t srcLen, void* dst) {
    static char HexMap[] = "0123456789ABCDEF";
    const uint8_t* u8Src = reinterpret_cast<const uint8_t*>(src);
    uint8_t* u8Dst = reinterpret_cast<uint8_t*>(dst);

    for (size_t i = 0; i < srcLen; i++) {
        u8Dst[i * 2] = HexMap[u8Src[i] >> 4];
        u8Dst[i * 2 + 1] = HexMap[u8Src[i] & 0xf];
    }
}

void Crypto::DecodeHex(const void* src, size_t srcLen, void* dst, size_t& dstLen) {
    static uint8_t HexMap[] = {
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0xff,0xff,0xff,0xff,0xff,0xff,

        0xff,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,

        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,

        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
        0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    };
    dstLen = 0;
    if (srcLen % 2) { return; }
    const uint8_t* u8Src = reinterpret_cast<const uint8_t*>(src);
    uint8_t* u8Dst = reinterpret_cast<uint8_t*>(dst);

    for (size_t i = 0; i < srcLen / 2; i++) {
        const uint8_t high = HexMap[u8Src[i * 2]];
        if (0xff == high) {
            dstLen = 0;
            return;
        }
        const uint8_t low = HexMap[u8Src[i * 2 + 1]];
        if (0xff == low) {
            dstLen = 0;
            return;
        }
        u8Dst[i] = (high << 4) + low;
        dstLen++;
    }
}

void Crypto::EncodeUrl(const void* src, size_t srcLen, void* dst, size_t& dstLen) {
    const uint8_t* u8Src = reinterpret_cast<const uint8_t*>(src);
    uint8_t* u8Dst = reinterpret_cast<uint8_t*>(dst);

    dstLen = 0;
    for (size_t i = 0; i < srcLen; i++) {
        uint8_t ch = u8Src[i];
        auto hex = false;
        if (ch == ' ') {
            ch = '+';
        }
        else if (!std::isalnum(ch) && ch != '-' && ch != '_' && ch != '.' && ch != '~') {
            ch = '%';
            hex = true;
        }
        *u8Dst++ = ch;
        dstLen++;
        if (hex) {
            EncodeHex(u8Src + i, 1, u8Dst);
            u8Dst += 2;
            dstLen += 2;
        }
    }
}

void Crypto::DecodeUrl(const void* src, size_t srcLen, void* dst, size_t& dstLen) {
    const uint8_t* u8Src = reinterpret_cast<const uint8_t*>(src);
    uint8_t* u8Dst = reinterpret_cast<uint8_t*>(dst);

    dstLen = 0;
    for (size_t i = 0; i < srcLen; i++) {
        uint8_t ch = u8Src[i];
        if (ch == '+')
            ch = ' ';
        else if (ch == '%') {
            size_t len = 1;
            DecodeHex(u8Src + i + 1, std::min(2ull, srcLen - i - 1), &ch, len);
            if (len != 1) {
                dstLen = 0;
                return;
            }
            i += 2;
        }
        *u8Dst++ = ch;
        dstLen++;
    }
}

std::string Crypto::Codec(const std::string& src, EncodeMode mode, bool encode) {
    if (src.empty()) {
        return "";
    }
    const auto srcLen = src.length();
    size_t dstLen = 0;
    void (*func)(const void*, size_t, void*, size_t&) = nullptr;

    switch (mode) {
    case EncodeMode::BASE64:
        if (encode) {
            // The result is always a multiple of 4 when encoded in Base64.
            const auto mod3 = srcLen % 3;
            dstLen = (srcLen - mod3) * 4 / 3 + (mod3 ? 4 : 0);
        }
        else {
            dstLen = srcLen;
        }
        func = encode ? EncodeBase64 : DecodeBase64;
        break;
    case EncodeMode::HEX:
        dstLen = encode ? srcLen * 2 : srcLen / 2;
        func = encode ? static_cast<void (*)(const void*, size_t, void*, size_t&)>(EncodeHex) : DecodeHex;
        break;
    case EncodeMode::URL:
        dstLen = encode ? srcLen * 3 : srcLen;
        func = encode ? EncodeUrl : DecodeUrl;
        break;
    default:
        return "";
    }
    auto decodeRet = std::string(dstLen, 0);
    func(src.data(), srcLen, decodeRet.data(), dstLen);
    decodeRet.resize(dstLen);
    return decodeRet;
}
/****************Codec End****************/

/****************Hash Begin****************/
std::string Crypto::Hash(const std::string& src, HashMode mode, bool encode) {
    if (src.empty()) {
        return "";
    }
    auto outLen = 0;
    uint8_t* (*func)(const uint8_t*, size_t, uint8_t*) = nullptr;
    switch (mode) {
    case cocos2d::Crypto::HashMode::SHA1:
        func = ::SHA1;
        outLen = SHA_DIGEST_LENGTH;
        break;
    case cocos2d::Crypto::HashMode::SHA224:
        func = ::SHA224;
        outLen = SHA224_DIGEST_LENGTH;
        break;
    case cocos2d::Crypto::HashMode::SHA256:
        func = ::SHA256;
        outLen = SHA256_DIGEST_LENGTH;
        break;
    case cocos2d::Crypto::HashMode::SHA384:
        func = ::SHA384;
        outLen = SHA384_DIGEST_LENGTH;
        break;
    case cocos2d::Crypto::HashMode::SHA512:
        func = ::SHA512;
        outLen = SHA512_DIGEST_LENGTH;
        break;
    case cocos2d::Crypto::HashMode::MD5:
        func = ::MD5;
        outLen = MD5_DIGEST_LENGTH;
        break;
    default:
        return "";
    }

    auto hashRet = std::string(encode ? outLen * 2 : outLen, 0);
    if (encode) {
        std::unique_ptr<uint8_t[]> out = std::make_unique<uint8_t[]>(outLen);
        func(reinterpret_cast<const uint8_t*>(src.data()), src.length(), out.get());
        EncodeHex(out.get(), outLen, hashRet.data());
    }
    else {
        func(reinterpret_cast<const uint8_t*>(src.data()), src.length(), reinterpret_cast<uint8_t*>(hashRet.data()));
    }
    return hashRet;
}
/****************Hash End****************/

/****************Crypto Begin****************/
void Crypto::Encrypt(
    const void* src, size_t srcLen,
    void* dst, size_t dstLen,
    const char* key, uint8_t keyLen,
    const char* iv, uint8_t ivLen,
    EncryptMode mode
) {
    switch (mode) {
    case EncryptMode::CFB128:
        CFB128(src, srcLen, dst, dstLen, key, keyLen, iv, ivLen, true);
        break;
    default:
        break;
    }
}

void Crypto::Decrypt(
    const void* src, size_t srcLen,
    void* dst, size_t dstLen,
    const char* key, uint8_t keyLen,
    const char* iv, uint8_t ivLen,
    DecryptMode mode
) {
    switch (mode) {
    case EncryptMode::CFB128:
        CFB128(src, srcLen, dst, dstLen, key, keyLen, iv, ivLen, false);
        break;
    default:
        break;
    }
}

void Crypto::CFB128(
    const void* src, size_t srcLen,
    void* dst, size_t dstLen,
    const char* key, uint8_t keyLen,
    const char* iv, uint8_t ivLen,
    bool encrypt) {
    static constexpr uint8_t DefaultKeyLen = 16;
    static constexpr uint8_t DefaultIVLen = 16;

    uint8_t keyChar[DefaultKeyLen] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    uint8_t IV[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::memcpy(keyChar, key, std::min(DefaultKeyLen, keyLen));
    std::memcpy(IV, iv, std::min(DefaultIVLen, ivLen));

    AES_KEY aeskey = {};
    AES_set_encrypt_key(keyChar, DefaultKeyLen * sizeof(uint8_t) * 8, &aeskey);

    int num = 0;
    AES_cfb128_encrypt(
        reinterpret_cast<const uint8_t*>(src), reinterpret_cast<uint8_t*>(dst), srcLen, &aeskey,
        IV, &num, encrypt ? AES_ENCRYPT : AES_DECRYPT);
}
/****************Crypto End****************/