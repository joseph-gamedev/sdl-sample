file (GLOB SDL2_HEADER_FILES
include/*.h
)

#target_include_directories(libsdl2 PUBLIC ..)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SDL2_HEADER_FILES})

include_directories(${SDL2_HEADER_FILES})

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_include_directories(libsdl2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)