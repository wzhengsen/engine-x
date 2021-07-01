set(cocos_root ${ADXE_ROOT_PATH})

set(lua_bindings_manual_headers
    # manual/3d/lua_cocos2dx_3d_manual.h
    # manual/lua_module_register.h
    manual/CCLuaBridge.h
    manual/CCRegisterLuaManual.h
    manual/CCLuaConvertSol.hpp
    manual/network/CCLuaWebSocket.h
    manual/network/CCLuaHttpRequest.h
    # manual/extension/lua_cocos2dx_extension_manual.h
    # manual/spine/LuaSkeletonAnimation.h
    # manual/platform/ios/CCLuaObjcBridge.h
    # manual/network/lua_cocos2dx_network_manual.h
    # manual/network/lua_xml_http_request.h
    # manual/network/lua_extensions.h
    # manual/network/Lua_web_socket.h
    # manual/audioengine/lua_cocos2dx_audioengine_manual.h
    # manual/navmesh/lua_cocos2dx_navmesh_manual.h
    # manual/navmesh/lua_cocos2dx_navmesh_conversions.h
    # manual/cocos2d/lua_cocos2dx_manual.hpp
    # manual/physics3d/lua_cocos2dx_physics3d_manual.h
    # manual/cocostudio/lua-cocos-studio-conversions.h
    # manual/cocostudio/CustomGUIReader.h
    # manual/ui/lua_cocos2dx_ui_manual.hpp
    # manual/controller/lua_cocos2dx_controller_manual.hpp
    # manual/ui/lua_cocos2dx_webview_manual.hpp
    # manual/ui/lua_cocos2dx_video_manual.hpp
    )

set(lua_bindings_manual_files
    manual/CCRegisterLuaManual.cpp
    manual/CCLuaConvertSol.cpp
    manual/network/CCLuaWebSocket.cpp
    manual/network/CCLuaHttpRequest.cpp
    # manual/lua_module_register.cpp
    # manual/cocos2d/lua_cocos2dx_manual.cpp
    # manual/cocos2d/lua_cocos2dx_physics_manual.cpp
    # manual/3d/lua_cocos2dx_3d_manual.cpp
    # manual/cocostudio/CustomGUIReader.cpp
    # manual/cocostudio/lua_cocos2dx_coco_studio_manual.cpp
    # manual/cocostudio/lua-cocos-studio-conversions.cpp
    # manual/cocostudio/lua_cocos2dx_csloader_manual.cpp
    # manual/controller/lua_cocos2dx_controller_manual.cpp
    # manual/extension/lua_cocos2dx_extension_manual.cpp
    # manual/network/lua_cocos2dx_network_manual.cpp
    # manual/network/lua_extensions.c
    # manual/network/Lua_web_socket.cpp
    # manual/network/lua_xml_http_request.cpp
    # manual/spine/lua_cocos2dx_spine_manual.cpp
    # manual/spine/LuaSkeletonAnimation.cpp
    # manual/ui/lua_cocos2dx_ui_manual.cpp
    # manual/audioengine/lua_cocos2dx_audioengine_manual.cpp
    # manual/physics3d/lua_cocos2dx_physics3d_manual.cpp
    # manual/navmesh/lua_cocos2dx_navmesh_conversions.cpp
    # manual/navmesh/lua_cocos2dx_navmesh_manual.cpp
    # manual/ui/lua_cocos2dx_webview_manual.cpp
    # manual/ui/lua_cocos2dx_video_manual.cpp
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

# set(lua_bindings_auto_headers
#     auto/CCRegisterLua3DAuto.hpp
#     #auto/CCRegisterLuaCoreAuto.hpp
#     auto/CCRegisterLuaControllerAuto.hpp
#     auto/CCRegisterLuaExtensionAuto.hpp
#     auto/CCRegisterLuaPhysicsAuto.hpp
#     auto/CCRegisterLuaSpineAuto.hpp
#     auto/CCRegisterLuaStudioAuto.hpp
#     auto/CCRegisterLuaCSLoaderAuto.hpp
#     #auto/CCRegisterLuaUIAuto.hpp
#     auto/CCRegisterLuaAudioEngineAuto.hpp
#     auto/CCRegisterLuaPhysics3DAuto.hpp
#     auto/CCRegisterLuaNavMeshAuto.hpp
#     auto/CCRegisterLuaBackendAuto.hpp
#     auto/CCRegisterLuaWebViewAuto.hpp
#     auto/CCRegisterLuaVideoPlayerAuto.hpp
#     )

# set(lua_bindings_auto_files
#     auto/CCRegisterLua3DAuto.cpp
#     #auto/CCRegisterLuaCoreAuto.cpp
#     auto/CCRegisterLuaControllerAuto.cpp
#     auto/CCRegisterLuaExtensionAuto.cpp
#     auto/CCRegisterLuaPhysicsAuto.cpp
#     auto/CCRegisterLuaSpineAuto.cpp
#     auto/CCRegisterLuaStudioAuto.cpp
#     auto/CCRegisterLuaCSLoaderAuto.cpp
#     #auto/CCRegisterLuaUIAuto.cpp
#     auto/CCRegisterLuaAudioEngineAuto.cpp
#     auto/CCRegisterLuaPhysics3DAuto.cpp
#     auto/CCRegisterLuaNavMeshAuto.cpp
#     auto/CCRegisterLuaBackendAuto.cpp
#     auto/CCRegisterLuaWebViewAuto.cpp
#     auto/CCRegisterLuaVideoPlayerAuto.cpp
#     )

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
    # if(IOS)
    #     set(lua_bindings_manual_headers
    #         ${lua_bindings_manual_headers}
    #         manual/ui/lua_cocos2dx_webview_manual.hpp
    #         auto/lua_cocos2dx_webview_auto.hpp
    #         auto/lua_cocos2dx_video_auto.hpp
    #         manual/ui/lua_cocos2dx_video_manual.hpp
    #         )
    #     set(lua_bindings_manual_files
    #         ${lua_bindings_manual_files}
    #         manual/ui/lua_cocos2dx_webview_manual.cpp
    #         auto/lua_cocos2dx_webview_auto.cpp
    #         manual/ui/lua_cocos2dx_video_manual.cpp
    #         auto/lua_cocos2dx_video_auto.cpp
    #         )
    # endif()
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
