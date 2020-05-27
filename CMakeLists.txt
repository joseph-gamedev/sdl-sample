cmake_minimum_required(VERSION 3.8)

project(sdl-sample VERSION 1.0.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SDLSAMPLE ${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(sandbox)
add_subdirectory(third-party/imgui)
#add_subdirectory(third-party/libpng)

if (MSVC)
		 set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT sandbox) 
endif()

