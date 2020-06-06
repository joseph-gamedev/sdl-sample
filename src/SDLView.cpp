#include "SDLView.h"
#include <SDL.h>

SDLView::SDLView(const std::string& title, int width, int height)
	: m_Data({ title,width,height })
	, m_Window(nullptr)
	, m_ShouldQuit(false)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}

}

SDLView::~SDLView()
{

}

void SDLView::Init()
{
	m_Window = SDL_CreateWindow(
		m_Data.title.c_str(),              // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		m_Data.width,                      // width, in pixels
		m_Data.height,                     // height, in pixels
		SDL_WINDOW_OPENGL                  // flags 
		);

	if (!m_Window)
	{
		SDL_Log("Unable to create SDL window: %s", SDL_GetError());
	}

}

void SDLView::ReInitialize()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
	Init();
}

void SDLView::Update(ApplicationBase& appBase)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/* handle your event here */
		switch (event.type)
		{
		case SDL_QUIT:
			m_ShouldQuit = true;
			break;
		default:
			break;
		}
	}
}

void SDLView::Terminate()
{
	if (m_Window)
	{
		// Close and destroy the window
		SDL_DestroyWindow(m_Window);
	}
	// Clean up
	SDL_Quit();

}

void SDLView::GetViewportSize() const
{

}

void SDLView::GetViewSize() const
{

}

void* SDLView::GetWindow() const
{
	return m_Window;
}

void SDLView::SetViewSize(int width, int height)
{
	m_Data.width = width;
	m_Data.height = height;
}

bool SDLView::ShouldClose() const
{
	return m_ShouldQuit;
}

const std::string& SDLView::GetTitle() const
{
	return m_Data.title;
}

void SDLView::SetTitle(const std::string& title)
{
	m_Data.title = title;
}

void SDLView::Display(IScene* scene, IRenderer* renderer)
{
}
