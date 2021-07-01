cmake_minimum_required(VERSION 3.6)

set(lib_name lua-protobuf)
set(target_name ${lib_name})

project(${lib_name})

set(${target_name}_src
  pb.c
)

add_library(${target_name} STATIC
  ${${target_name}_src}
)

target_include_directories(${target_name} PUBLIC .)
target_link_libraries(${target_name} plainlua)