set(cocos_root ${ADXE_ROOT_PATH})

set(lua_bindings_manual_headers
    manual/CCLuaBridge.h
    manual/CCRegisterLuaManual.h
    manual/CCLuaConvertSol.hpp
    manual/network/CCLuaWebSocket.h
    manual/network/CCLuaHttpRequest.h
    )

set(lua_bindings_manual_files
    manual/CCRegisterLuaManual.cpp
    manual/CCLuaConvertSol.cpp
    manual/network/CCLuaWebSocket.cpp
    manual/network/CCLuaHttpRequest.cpp
    )

if (NOT WINDOWS AND NOT LINUX)
    set(lua_bindings_manual_headers
        ${lua_bindings_manual_headers}
        manual/CCLuaBridge.h
        )
    set(lua_bindings_manual_files
        ${lua_bindings_manual_files}
        manual/CCLuaBridge.cpp
        )
endif()

if(APPLE)
    # CCLuaObjcBridge.mm needed by ios and mac
    set(lua_bindings_manual_headers
        ${lua_bindings_manual_headers}
        manual/platform/ios/CCLuaObjcBridge.h
        )
    set(lua_bindings_manual_files
        ${lua_bindings_manual_files}
        manual/platform/ios/CCLuaObjcBridge.mm
        )
elseif(ANDROID)
    # set(lua_bindings_manual_headers
    #     ${lua_bindings_manual_headers}
    #     manual/ui/lua_cocos2dx_webview_manual.hpp
    #     auto/lua_cocos2dx_webview_auto.hpp
    #     auto/lua_cocos2dx_video_auto.hpp
    #     manual/ui/lua_cocos2dx_video_manual.hpp
    #     )
    # set(lua_bindings_manual_files
    #     ${lua_bindings_manual_files}
    #     manual/ui/lua_cocos2dx_webview_manual.cpp
    #     auto/lua_cocos2dx_webview_auto.cpp
    #     manual/ui/lua_cocos2dx_video_manual.cpp
    #     auto/lua_cocos2dx_video_auto.cpp
    #     )
endif()

set(lua_bindings_files
    ${lua_bindings_manual_files}
    ${lua_bindings_auto_files}
    ${COCOS_DEPRECATED_SRC}
    CCLua.cpp
    CCLuaObject.cpp
    )
set(lua_bindings_headers
    ${lua_bindings_manual_headers}
    ${lua_bindings_auto_headers}
    ${COCOS_DEPRECATED_HEADER}
    CCLua.h
    CCLuaObject.h
    )

set(lua_bindings_files
    ${lua_bindings_files}
    "${cocos_root}/thirdparty/yasio/bindings/lyasio.cpp"
    "${cocos_root}/thirdparty/yasio/bindings/yasio_cclua.cpp")

list(APPEND lua_bindings_files ${lua_bindings_headers})
aux_source_directory(auto lua_bindings_files)

set(ADXE_LUA_LIB adxelua CACHE INTERNAL "The ADXE lua bindings lib name" )

add_library(${ADXE_LUA_LIB} STATIC ${lua_bindings_files})
target_link_libraries(${ADXE_LUA_LIB} ${ADXE_CORE_LIB})
add_dependencies(${ADXE_LUA_LIB} ${ADXE_CORE_LIB})
if(WINDOWS)
    target_compile_options(${ADXE_LUA_LIB} PRIVATE "/bigobj")
endif()


target_include_directories(${ADXE_LUA_LIB}
    PUBLIC ${cocos_root}/thirdparty/lua
    PRIVATE manual/platform/android
    PRIVATE manual/platform/android/jni
    PRIVATE ${cocos_root}/extensions/spine/runtime/include
    PRIVATE ${cocos_root}/extensions/cocostudio
    INTERFACE ${cocos_root}/extensions/scripting/lua-bindings/manual
    PRIVATE ${cocos_root}/extensions/spine/runtime/include
)

if(WINDOWS)
    target_compile_definitions(${ADXE_LUA_LIB} PUBLIC _USRLUASTATIC)
endif()

set_target_properties(${ADXE_LUA_LIB}
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      FOLDER "Extensions"
                      )

if(XCODE OR VS)
    cocos_mark_code_files("${ADXE_LUA_LIB}")
endif()
