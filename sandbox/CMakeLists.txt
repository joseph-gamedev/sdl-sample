set(SANDBOX_SOURCE_FILES 
	SandBox.h
	SandBox.cpp
	)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/third-party)

set(SDL_LIBPATH ${EXTERNAL}/libsdl2/lib/x64)
set(TINYXML_LIBPATH ${EXTERNAL}/tinyxml2/lib/x64)
set(SPDLOG_LIBPATH ${EXTERNAL}/spdlog/lib/x64)
set(GLM_LIBPATH ${EXTERNAL}/glm/lib/x64)
set(GLEW_LIBPATH ${EXTERNAL}/glew/lib/Release/x64)

include_directories(${EXTERNAL}/spdlog/include)
include_directories(${EXTERNAL}/libsdl2/include)
include_directories(${EXTERNAL}/tinyxml2/include)
include_directories(${EXTERNAL}/glm/include)
include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${TINYXML_LIBPATH})
link_directories(${SDL_LIBPATH})

include_directories($ENV{UniversalCRTSdkDir}/Include/ucrt)
include_directories($ENV{UniversalCRTSdkDir}/Include/10.0.10056.0/ucrt)

add_executable(sandbox WIN32 ${SANDBOX_SOURCE_FILES} )

target_link_libraries(sandbox PUBLIC imgui glad ${SDL_LIBPATH}/SDL2.lib 
										   ${TINYXML_LIBPATH}/tinyxml2d.lib 
										   ${GLEW_LIBPATH}/glew32.lib 
										   ${SPDLOG_LIBPATH}/spdlogd.lib 
										   ${GLM_LIBPATH}/glm_static.lib 
										   sdl-sample										
										   )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SANDBOX_SOURCE_FILES})

#configure_file(${SDL_LIBPATH}/SDL2.dll ${CMAKE_BINARY_DIR}/sandbox/debug COPYONLY)