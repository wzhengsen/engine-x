cmake_minimum_required(VERSION 3.6)

project(cef)
include(../cmake/CocosExternalConfig.cmake)

add_library(ext_libcef SHARED IMPORTED GLOBAL)

set_target_properties(ext_libcef PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include/${platform_name}
)

if(WINDOWS)
    set_target_properties(ext_libcef PROPERTIES
       IMPORTED_LOCATION "${platform_spec_path}/libcef.dll"
       IMPORTED_IMPLIB "${platform_spec_path}/libcef.lib"
    )
elseif(LINUX)
    execute_process(
      COMMAND
      ${PYTHON_COMMAND} ${CMAKE_CURRENT_SOURCE_DIR}/CefPreprocess.py
    )

    set_target_properties(ext_libcef PROPERTIES
       IMPORTED_LOCATION "${platform_spec_path}/libcef.so"
    )
endif()

add_library(ext_libcef_dll_wrapper STATIC IMPORTED GLOBAL)
if(WINDOWS)
    set_target_properties(ext_libcef_dll_wrapper PROPERTIES
      IMPORTED_LOCATION "${platform_spec_path}/libcef_dll_wrapper.lib"
      IMPORTED_LOCATION_RELEASE "${platform_spec_path}/libcef_dll_wrapper.lib"
      IMPORTED_LOCATION_DEBUG "${platform_spec_path}/libcef_dll_wrapper_d.lib"
    )
elseif(LINUX)
    set_target_properties(ext_libcef_dll_wrapper PROPERTIES
       IMPORTED_LOCATION "${platform_spec_path}/libcef_dll_wrapper.a"
    )
endif()
