set(SAMPLE_HEADER_FILES
    ../include/Debug.h)

set(SAMPLE_SOURCE_FILES
    Debug.cpp)

add_library(sdl-sample STATIC ${SAMPLE_SOURCE_FILES} ${SAMPLE_HEADER_FILES})

target_include_directories(sdl-sample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(sdl-sample PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "src" FILES ${SAMPLE_SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../include" PREFIX "include" FILES ${SAMPLE_HEADER_FILES})