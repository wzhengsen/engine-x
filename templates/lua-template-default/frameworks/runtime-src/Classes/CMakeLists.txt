cmake_minimum_required(VERSION 3.6)

set(lib_name derivative)
set(target_name ${lib_name})

project(${lib_name})

set(${target_name}_src
    OO_Lua/OO_Lua.hpp
    Device/Device.h
    LuaModule/cjson/LuaRegister_cjson.h
    LuaModule/cjson/LuaRegister_cjson.cpp
    LuaModule/crypto/LuaRegister_crypto.h
    LuaModule/crypto/LuaRegister_crypto.cpp
    LuaModule/Device/LuaRegisterDevice.h
    LuaModule/Device/LuaRegisterDevice.cpp
    LuaModule/ExtLib/LuaRegisterExtLib.h
    LuaModule/ExtLib/LuaRegisterExtLib.cpp
    LuaModule/lua-protobuf/LuaRegister_lua-protobuf.h
    LuaModule/lua-protobuf/LuaRegister_lua-protobuf.cpp
    LuaModule/Cocos2dx/LuaRegisterCocos2dx.h
    LuaModule/Cocos2dx/LuaRegisterCocos2dx.cpp
)

if(WINDOWS)
    list(APPEND ${target_name}_src
    Device/Device-windows.cpp
    )
elseif(ANDROID)
    list(APPEND ${target_name}_src
    Device/Device-android.cpp
    )
elseif(LINUX)
    list(APPEND ${target_name}_src
    Device/Device-linux.cpp
    )
else()
    list(APPEND ${target_name}_src
    Device/Device-apple.mm
    )
    if(IOS)
        list(APPEND ${target_name}_src
        LuaModule/ExtLib/LuaRegisterExtLib.mm
        )
    endif()
endif()

add_library(${target_name} STATIC ${${target_name}_src})
target_include_directories(${target_name}
    PRIVATE Zip
    PRIVATE OO_Lua
    PRIVATE Network
    PUBLIC LuaModule
    PRIVATE ${ADXE_ROOT_PATH}/cocos
    PRIVATE ${ADXE_ROOT_PATH}/external
    PRIVATE ${ADXE_ROOT_PATH}/external/windows-specific/zlib/include
    PUBLIC .
    )

if(WINDOWS)
    target_include_directories(${target_name}
        PRIVATE ${RUNTIME_SRC_ROOT}/proj.windows
    )
endif()

target_link_libraries(${target_name}
    cocos2d
    plainlua
    cjson
)

if(NOT LINUX AND NOT IOS)
target_link_libraries(${target_name}
    ext_zlib
)
endif()

if(XCODE OR VS)
    cocos_mark_code_files(${target_name})
endif()

set_target_properties(${target_name}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)