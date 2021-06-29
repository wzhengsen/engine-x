cmake_minimum_required(VERSION 3.6)

set(lib_name vlc)

project(${lib_name})

include(../cmake/CocosExternalConfig.cmake)

# -----macro: set vlc sub target-----
macro(set_vlc_sub_target sub_lib_name)

  set(sub_target_name ext_${sub_lib_name})
  add_library(${sub_target_name} SHARED IMPORTED GLOBAL)

  set_target_properties(${sub_target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )
  if(WINDOWS)
    set_target_properties(${sub_target_name} PROPERTIES
      IMPORTED_LOCATION "${platform_spec_path}/${sub_lib_name}.dll"
      IMPORTED_IMPLIB "${platform_spec_path}/${sub_lib_name}.lib"
    )
  elseif(LINUX)
    set_target_properties(${sub_target_name} PROPERTIES
      IMPORTED_LOCATION "${platform_spec_path}/${sub_lib_name}.so"
    )
  elseif(MACOSX)
    set_target_properties(${sub_target_name} PROPERTIES
      IMPORTED_LOCATION "${platform_spec_path}/${sub_lib_name}.dylib"
    )
  endif()
endmacro()

# -----sub target 1: libvlc-----
set(target_name libvlc)
set_vlc_sub_target(${target_name})

# -----sub target 2: libvlccore-----
set(target_name libvlccore)
set_vlc_sub_target(${target_name})
