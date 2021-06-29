cmake_minimum_required(VERSION 3.6)

set(lib_name cjson)
set(target_name ${lib_name})

project(${lib_name})

set(${target_name}_src
fpconv.c
lua_cjson.c
strbuf.c
)

add_library(${target_name} STATIC
  ${${target_name}_src}
)

target_include_directories(${target_name}
  PUBLIC .
  PRIVATE ../plainlua/src
)
target_link_libraries(${target_name} plainlua)

if(MSVC)
target_compile_definitions(${target_name} PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

set_target_properties(${target_name}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "External"
)