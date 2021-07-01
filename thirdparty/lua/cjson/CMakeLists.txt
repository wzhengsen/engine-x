cmake_minimum_required(VERSION 3.6)

set(lib_name cjson)
set(target_name ${lib_name})

project(${lib_name})

set(${target_name}_src
fpconv.h
lua_cjson.h
strbuf.h
fpconv.c
lua_cjson.c
strbuf.c
)

add_library(${target_name} STATIC
  ${${target_name}_src}
)

target_include_directories(${target_name}
  PUBLIC .
)
target_link_libraries(${target_name} plainlua)

if(MSVC)
target_compile_definitions(${target_name} PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()