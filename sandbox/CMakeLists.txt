set(SANDBOX_SOURCE_FILES main.cpp)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/third-party)

set(SDL_LIBPATH ${EXTERNAL}/libsdl2/lib/x64)
set(TINYXML_LIBPATH ${EXTERNAL}/tinyxml2/lib/x64)
set(SPDLOG_LIBPATH ${EXTERNAL}/spdlog/lib/x64)

include_directories(${EXTERNAL}/spdlog/include)
include_directories(${EXTERNAL}/libsdl2/include)
include_directories(${EXTERNAL}/tinyxml2/include)

link_directories(${TINYXML_LIBPATH})
link_directories(${SDL_LIBPATH})

add_executable(sandbox ${SANDBOX_SOURCE_FILES})

target_link_libraries(sandbox PUBLIC imgui ${SDL_LIBPATH}/SDL2.lib 
										   ${TINYXML_LIBPATH}/tinyxml2d.lib 
										   ${SPDLOG_LIBPATH}/spdlogd.lib)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SANDBOX_SOURCE_FILES})

#configure_file(${SDL_LIBPATH}/SDL2.dll ${CMAKE_BINARY_DIR}/sandbox/debug COPYONLY)