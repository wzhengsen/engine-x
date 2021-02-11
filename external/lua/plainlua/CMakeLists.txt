cmake_minimum_required(VERSION 3.6)

set(LUA_SRC_PATH ${CMAKE_CURRENT_LIST_DIR}/src)

set(lib_name plainlua)
set(target_name ${lib_name})

project(${lib_name})

include(../../cmake/CocosExternalConfig.cmake)

aux_source_directory(${LUA_SRC_PATH} LUA_CORE)
list(REMOVE_ITEM LUA_CORE ${LUA_SRC_PATH}/lua.c ${LUA_SRC_PATH}/luac.c)

add_library(${target_name} ${LUA_CORE})

target_compile_definitions(${target_name} 
    PRIVATE _CRT_SECURE_NO_WARNINGS 
    PRIVATE _WINSOCK_DEPRECATED_NO_WARNINGS
    )

#LUA_FLOORN2I=1
#The 1 means F2Ifloor,default is 0,which means F2Ieq.
target_compile_definitions(${target_name} PUBLIC LUA_FLOORN2I=1)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(${target_name} PUBLIC LUA_BUILD_AS_DLL=1)
endif()

set_target_properties(${target_name} PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${LUA_SRC_PATH}"
  #for sol path
  PUBLIC    ..
)

set_target_properties(${target_name}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "External"
)