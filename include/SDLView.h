#pragma once

#include "IView.h"

class ApplicationBase;
struct SDL_Window;

struct SDLViewData
{
    std::string title;
    int width;
    int height;
};

class SDLView : public IView
{
public:
	SDLView(const std::string& title, int width, int height);
	virtual ~SDLView();

    virtual void Init() override;

    virtual void ReInitialize() override;

    virtual void Update(ApplicationBase& appBase) override;

    virtual void Terminate() override;

    virtual void GetViewportSize() const override;

    virtual void GetViewSize() const override;

    virtual void* GetWindow() const override;

    virtual void SetViewSize(int width, int height) override;

    virtual bool ShouldClose() const override;

    virtual const std::string& GetTitle() const override;

    virtual void SetTitle(const std::string& title) override;

    virtual void Display(IScene* scene, IRenderer* renderer) override;

private:
    SDLViewData m_Data;
    SDL_Window* m_Window;
    bool m_ShouldQuit;
};
