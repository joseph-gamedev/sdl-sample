#pragma once

#include "IRenderer.h"

class SDLView;
struct SDL_Window;

class SDL_GLRenderer : public IRenderer
{
public:
    SDL_GLRenderer(SDLView& sdlView);
    virtual ~SDL_GLRenderer(){}

    virtual void Init() override;

    virtual void ClearColor(float, float, float, float) override;

    virtual void ReInitialize() override;

    virtual void SwapBuffers() override;

    virtual void Terminate() override;

private:
    void* m_GlContext;
    SDL_Window* m_Window;
};