#include "LuaRegister_crypto.h"
#include <algorithm>
#include <cstring>
#include "openssl/aes.h"
#include "openssl/md5.h"
#include "openssl/sha.h"
#include "openssl/bio.h"
#include "openssl/buffer.h"
#include "openssl/evp.h"
#include "OO_Lua/OO_Lua.hpp"


#define LuaHash(hashName) static int Lua##hashName(lua_State* L){\
    const auto lua = Lua(L);\
    size_t len = 0;\
    const char* str = lua.CheckLString(1,len);\
    const uint8_t* h = hashName(reinterpret_cast<const unsigned char*>(str),len,nullptr);\
    lua.Push(h,hashName##_DIGEST_LENGTH);\
    return 1;\
}

#define LuaDE(DC_EC) static int Lua##DC_EC(lua_State* L){\
    static const size_t keyLen = 16;\
    const Lua lua = Lua(L);\
    size_t strLen = 0;\
    const uint8_t* str = reinterpret_cast<const uint8_t*>(lua.CheckLString(1,strLen));\
    size_t pwdLen = 0;\
    const uint8_t* pwd = reinterpret_cast<const uint8_t*>(lua.CheckLString(2,pwdLen));\
    uint8_t pwdChar[keyLen] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};\
    uint8_t iv[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};\
    for (size_t i = 0; i < std::min(pwdLen,keyLen); i++){\
        pwdChar[i] = pwd[i];\
    }\
    AES_KEY aeskey = {};\
    AES_set_encrypt_key(pwdChar, keyLen * sizeof(uint8_t) * 8, &aeskey);\
    auto b = Lua::Buffer();\
    uint8_t* buffer = reinterpret_cast<uint8_t*>(lua.BufferInitSize(&b, strLen));\
    int num = 0;\
    AES_cfb128_encrypt(str,buffer,strLen,&aeskey,iv,&num,AES_##DC_EC);\
    Lua::PushResultSize(&b,strLen);\
    return 1;\
}

using namespace OO_Lua;

// ¶¨Òåºêº¯Êý¡£
#define SHA1_DIGEST_LENGTH SHA_DIGEST_LENGTH
LuaHash(MD5)
LuaHash(SHA1)
LuaHash(SHA224)
LuaHash(SHA256)
LuaHash(SHA384)
LuaHash(SHA512)
#define __temp_min__ min
#undef min
LuaDE(ENCRYPT)
LuaDE(DECRYPT)
#define min __temp_min__
#undef __temp_min__
#undef SHA1_DIGEST_LENGTH
#undef LuaHash
#undef LuaDE

static int LuaBase64(lua_State* L) {
    const Lua lua = Lua(L);
    size_t strLen = 0;
    const uint8_t* str = reinterpret_cast<const uint8_t*>(lua.CheckLString(1, strLen));

    BIO* b64 = BIO_new(BIO_f_base64());
    BIO* bmem = BIO_new(BIO_s_mem());
    BUF_MEM* b_ptr = nullptr;

    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    b64 = BIO_push(b64, bmem);
    BIO_write(b64, str, static_cast<int>(strLen));
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &b_ptr);
    BIO_set_close(b64, BIO_NOCLOSE);

    auto b = Lua::Buffer();
    const size_t len = b_ptr->length;
    uint8_t* buffer = reinterpret_cast<uint8_t*>(lua.BufferInitSize(&b, len));
    ::memcpy(buffer, b_ptr->data, len);

    BIO_free_all(b64);

    Lua::PushResultSize(&b, len);
    return 1;
}

static int LuaUnbase64(lua_State* L) {
    const Lua lua = Lua(L);
    size_t strLen = 0;
    const uint8_t* str = reinterpret_cast<const uint8_t*>(lua.CheckLString(1, strLen));

    auto b = Lua::Buffer();
    uint8_t* buffer = reinterpret_cast<uint8_t*>(lua.BufferInitSize(&b, strLen));

    BIO* b64 = BIO_new(BIO_f_base64());
    BIO* bmem = BIO_new_mem_buf(str, static_cast<int>(strLen));

    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bmem = BIO_push(b64, bmem);

    const size_t len = BIO_read(bmem, buffer, static_cast<int>(strLen));

    Lua::PushResultSize(&b, len);

    BIO_free_all(bmem);
    return 1;
}

static int LuaHex(lua_State* L) {
    static char HexMap[] = "0123456789abcdef";
    const Lua lua = Lua(L);
    size_t strLen = 0;
    const uint8_t* str = reinterpret_cast<const uint8_t*>(lua.CheckLString(1, strLen));

    auto b = Lua::Buffer();
    char* buffer = lua.BufferInitSize(&b, strLen * 2);
    for (size_t i = 0; i < strLen; i++) {
        buffer[i * 2] = HexMap[str[i] >> 4];
        buffer[i * 2 + 1] = HexMap[str[i] & 0xf];
    }
    Lua::PushResultSize(&b, strLen * 2);
    return 1;
}

static int LuaUnhex(lua_State* L) {
    static uint8_t HexMap[] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,        0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,

        0,0xa,0xb,0xc,0xd,0xe,0xf,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0xa,0xb,0xc,0xd,0xe,0xf,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };
    const Lua lua = Lua(L);
    size_t strLen = 0;
    const uint8_t* str = reinterpret_cast<const uint8_t*>(lua.CheckLString(1, strLen));

    if (strLen <= 1) {
        lua.Push("");
        return 1;
    }

    auto b = Lua::Buffer();
    char* buffer = lua.BufferInitSize(&b, strLen / 2);
    for (size_t i = 0; i < strLen / 2; i++) {
        buffer[i] = (HexMap[str[i * 2]] << 4) + HexMap[str[i * 2 + 1]];
    }
    Lua::PushResultSize(&b, strLen / 2);
    return 1;
}

static int luaopen_crypto(lua_State* L) noexcept {
    const static Lua::KVPair<const char*, Lua::CFunction> reg[] = {
        {"SHA1",LuaSHA1},
        {"SHA224",LuaSHA224},
        {"SHA256",LuaSHA256},
        {"SHA384",LuaSHA384},
        {"SHA512",LuaSHA512},
        {"MD5",LuaMD5},

        {"EncodeBASE64",LuaBase64},
        {"DecodeBASE64",LuaUnbase64},
        {"EncodeHEX",LuaHex},
        {"DecodeHEX",LuaUnhex},

        {"Encrypt",LuaENCRYPT},
        {"Decrypt",LuaDECRYPT},
    };
    const auto lua = Lua(L);
    lua.NewTable(0, sizeof(reg) / sizeof(reg[0]));
    lua.SetPairs(-1, reg);
    return 1;
}

void LuaRegister_crypto(lua_State* L) noexcept {
    const static Lua::KVPair<const char*, Lua::CFunction> reg[] = {
        {"crypto", luaopen_crypto}
    };
    const auto lua = Lua(L);
    lua.GetGlobal("package");
    lua.GetField(-1, "preload");
    lua.SetPairs(-1, reg);
    lua.Pop(2);
}