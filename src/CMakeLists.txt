set(SAMPLE_HEADER_FILES
	../include/Application.h
	../include/ApplicationBase.h
	../include/Camera.h
	../include/Debug.h
	../include/Drawable.h
	../include/Grid.h
	../include/FileUtility.h
	../include/GameFramework.h
	../include/IndexBuffer.h
	../include/IRenderer.h
	../include/IView.h
	../include/LifeCycle.h
	../include/Light.h
	../include/Material.h
	../include/Mesh.h
	../include/Model.h
	../include/pch.h
	../include/SDL_GLRenderer.h
	../include/SDLView.h
	../include/SpriteBatch.h
	../include/Shader.h
	../include/Skybox.h
	../include/TransformNode.h
	../include/Time.h
	../include/Util.h
	../include/VertexArray.h
	../include/VertexBuffer.h
	../include/WindowsEntry.h
	)

set(SAMPLE_SOURCE_FILES
	Application.cpp
	Camera.cpp
	Debug.cpp
	Drawable.cpp	
	FileUtility.cpp
	Grid.cpp
	IndexBuffer.cpp
	Light.cpp
	Material.cpp
	Mesh.cpp
	Model.cpp
	SDL_GLRenderer.cpp
	SDLView.cpp	
	SpriteBatch.cpp
	Shader.cpp
	Skybox.cpp
	TransformNode.cpp
	Time.cpp
	Util.cpp
	VertexArray.cpp
	VertexBuffer.cpp
	WindowsEntry.cpp
	)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/third-party)

include_directories(${EXTERNAL}/spdlog/include)
include_directories(${EXTERNAL}/libsdl2/include)
include_directories(${EXTERNAL}/tinyxml2/include)
include_directories(${EXTERNAL}/glew/include)
include_directories(${EXTERNAL}/glad/include)
include_directories(${EXTERNAL}/glm/include)
include_directories(${CMAKE_SOURCE_DIR}/include)


add_library(sdl-sample STATIC ${SAMPLE_SOURCE_FILES} ${SAMPLE_HEADER_FILES})
target_precompile_headers(sdl-sample PUBLIC ../include/pch.h)

target_include_directories(sdl-sample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(sdl-sample PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "src" FILES ${SAMPLE_SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../include" PREFIX "include" FILES ${SAMPLE_HEADER_FILES})