#include "SDL_GLRenderer.h"
#include "SDLView.h"
#include <SDL.h>
#include <glad/glad.h>

#pragma comment(lib, "glew32.lib")

SDL_GLRenderer::SDL_GLRenderer(SDLView& sdlView)
	: m_GlContext(nullptr)
	, m_Window(static_cast<SDL_Window*>(sdlView.GetWindow()))
{

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Create an OpenGL context associated with the window.
	m_GlContext = SDL_GL_CreateContext(m_Window);


	// Load GL extensions using glad
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		
		exit(1);
	}
}

void SDL_GLRenderer::Init()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Create an OpenGL context associated with the window.
	m_GlContext = SDL_GL_CreateContext(m_Window);


	// Load GL extensions using glad
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {

		exit(1);
	}
	glViewport(0, 0, 800, 600);
}

void SDL_GLRenderer::ClearColor(float r , float g , float b , float a )
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void SDL_GLRenderer::ReInitialize()
{
	if (m_GlContext)
		Terminate();

	Init();

}

void SDL_GLRenderer::SwapBuffers()
{
	SDL_GL_SwapWindow(m_Window);
}

void SDL_GLRenderer::Terminate()
{
	// Once finished with OpenGL functions, the SDL_GLContext can be deleted.
	SDL_GL_DeleteContext(m_GlContext);
}
