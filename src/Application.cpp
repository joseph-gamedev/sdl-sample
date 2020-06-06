#include "Application.h"
#include "SDLView.h"
#include "SDL_GLRenderer.h"
#include <memory>

const std::string title = "sdl-sample";
const int DefaultWidth = 800;
const int DefaultHeight = 600;

Application::Application()
{	
	m_View = new SDLView(title, DefaultWidth, DefaultHeight);
	m_View->Init();

	m_Renderer = new SDL_GLRenderer(*(static_cast<SDLView*>(m_View)));
	m_Renderer->Init();

}

Application::~Application()
{
	if (m_View)
	{
		m_View->Terminate();
		delete m_View;
	}

	if (m_Renderer)
	{
		m_Renderer->Terminate();
		delete m_Renderer;
	}

}

int Application::Run()
{
	Start();
	while (!m_View->ShouldClose())
	{
		m_Time.Update();
		m_View->Update(*this);
		m_Renderer->ClearColor(0,0,0,0);
		//Draw code
		Update();
		m_Renderer->SwapBuffers();
	}
	Stop();
	return 0;
}

void Application::SetAppData(const AppData& data)
{
	m_View->SetTitle(data.title);
	m_View->SetViewSize(data.width, data.height);
	m_View->ReInitialize();
	m_Renderer->ReInitialize();
}

const Time& Application::GetTime() const
{
	return m_Time;
}

